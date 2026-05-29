#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
//-----------------------------------------------------
// Related to PA5
// Forward declaraion

// template <typename T>
// std::tuple<T> ParseStr(std::vector<std::string>& paramV);

// template <typename T1, typename T2>
// std::tuple<T1, T2> ParseStr(std::vector<std::string>& paramV);

// {"r1", "r2", "r3"}  -> std::tuple<std::string, std::string, std::string>
// {"r1", "10"}       -> std::tuple<std::string, int>
// { }                 -> std::tuple<>
template <typename... Args>
std::tuple<Args...> ParseStr(std::vector<std::string>& paramV);

// Later on:
// ParseStr<std::string, std::string, std::string> ({"r1", "r2", "r3"});

std::vector<std::string> Split(const std::string& str) {
  std::stringstream ss(str);
  std::vector<std::string> result;
  while (ss.good()) {
    std::string substr;
    std::getline(ss, substr, ',');
    result.push_back(substr);
  }
  return result;
}

struct Op {
  virtual const char* GetName() const = 0;
  virtual void Parse(const std::string& params) = 0;
  virtual void Execute(class Machine& machine) = 0;
};

struct MovI_old : Op {
  const char* GetName() const override { return "movi"; }
  void Parse(const std::string& params) override {
    // Split comma-separated list
    std::vector<std::string> paramV = Split(params);
    opReg1 = paramV[0];            // This is a string
    opInt = std::stoi(paramV[1]);  // Gotta convert this to int!
  }
  void Execute(class Machine& machine) override { /* Do whatever */
  }
  // Member data for this op!
  std::string opReg1;
  int opInt;
};

template <typename... Args>
struct OpBase : Op {
  void Parse(const std::string& params) override {
    // Split comma-separated list
    std::vector<std::string> paramV = Split(params);
    std::reverse(paramV.begin(), paramV.end());
    mParameters = ParseStr<Args...>(paramV);
    // empty tuple -> tuple<Args[0]> -> tuple<Args[0], Args[1]> -> tuple<Args[0], ..., Args[N]>
  }

  std::tuple<Args...> mParameters;
};

//-----------------------------------------------------
// ParseElem
template <typename T>
std::tuple<T> ParseElem(const std::string& elem) {}

// Specialized template
template <>
inline std::tuple<int> ParseElem(const std::string& elem) {
  return std::make_tuple(std::stoi(elem));
}

// Specialized template
template <>
inline std::tuple<std::string> ParseElem(const std::string& elem) {
  return std::make_tuple(elem);
}

//-----------------------------------------------------
// Forward declaration
template <typename T, typename... Args>
std::tuple<T, Args...> ParseStrHelper(std::vector<std::string>& paramV);
//-----------------------------------------------------

template <typename... Args>
std::tuple<Args...> ParseStr(std::vector<std::string>& paramV) {
  return ParseStrHelper<Args...>(paramV);
}

// Base case
template <>
std::tuple<> ParseStr(std::vector<std::string>& paramV) {
  return std::make_tuple();
}

//  Arg... = <int, float, std::string>
//  T = int, Arg... = <float, std::string>
//                   T = float, Arg... = std::string
//                                     T = std::string, Arg... = {}

//-----------------------------------------------------
// <int, std::string, std::string>
template <typename T, typename... Args>
std::tuple<T, Args...> ParseStrHelper(std::vector<std::string>& paramV) {
  std::string elem = paramV.back();
  paramV.pop_back();

  return std::tuple_cat(ParseElem<T>(elem), ParseStr<Args...>(paramV));
}
//-----------------------------------------------------
struct MovI : OpBase<std::string, int> {
  const char* GetName() const override { return "movi"; }
  void Execute(class Machine& machine) override {
    // Still have to implement this
  }
};

//-----------------------------------------------------
//  map for shared pointer
template <typename T>
std::shared_ptr<Op> CreateOp() {
  return std::make_shared<T>();
}

std::map<std::string, std::function<std::shared_ptr<Op>()>> opMap;
//-----------------------------------------------------
int main() {
  {
    auto parsed = ParseElem<int>("10");
    // std::tuple<int> parsed

    std::cout << "parsed: " << std::get<0>(parsed) << std::endl;
  }

  {
    auto parsed = ParseElem<std::string>("r1");
    // std::tuple<std::string> parsed
    std::cout << "parsed: " << std::get<0>(parsed) << std::endl;
  }

  std::vector<std::string> paramV = {"5", "r1"};
  auto t = ParseStr<std::string, int>(paramV);

  std::cout << "std::get<0>(t): " << std::get<0>(t) << std::endl;
  std::cout << "std::get<1>(t): " << std::get<1>(t) << std::endl;

  {
    MovI m;
    m.Parse("r1,5");

    std::cout << "std::get<0>(m.mParameters): " << std::get<0>(m.mParameters)
              << std::endl;
  }

  {
    opMap.emplace("mov", &CreateOp<MovI>);

    // Get the string for op name and params
    std::string opName = "mov";
    std::string params = "r1,10";

    // Look up the opName in our map, and call the
    // correct CreateOp function! (note the extra
    // parenthesis at the end, that's the function call)
    std::shared_ptr<Op> ptr = opMap.at(opName)();
    ptr->Parse(params);
  }
  return 0;
}

// mov r1,r2,r3

// params = "r1,r2,r3" ----split----> { "r1", "r2", "r3" }

// std::vector<int>

// intput File:
// "Add r1, r2, r3"  ====> opName = "Add", params = "r1, r2, r3"
// "And r1, r2, r3"
// "Mov r1, 100"

// Split : "r1, r2, r3"  ====> {"r1", "r2", "r3" }
// ParseElem: "r1" ====> ("r1")
//          : "11" ====> (11)

// ParseString: {"r1", "r2", "r3" } ===> ParseHelper:
//                                                std::tup_cat (ParseElem("r1"),
//                                                ParseString({"r2", "r3" }) =
//                                                ("r1", "r2", "r3")
