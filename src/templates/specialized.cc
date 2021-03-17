#include <iostream>
#include <string>

template <typename T>
std::tuple<T> ParseElem(const std::string& elem) {}

template <>
inline std::tuple<int> ParseElem(const std::string& elem) {
  return std::make_tuple(std::stoi(elem));
}

template <>
inline std::tuple<std::string> ParseElem(const std::string& elem) {
  return std::make_tuple(elem);
}

int main() {
  auto my_int = ParseElem<int>("11");
  auto my_string = ParseElem<std::string>("r1");

  std::cout << "std::get<0>(my_int): " << std::get<0>(my_int) << std::endl;
  std::cout << "std::get<0>(my_string): " << std::get<0>(my_string)
            << std::endl;

  return 0;
}


// "movei tx, 110"  ======> "tx,110" ===>vector {"tx", "110"} ======================> tuple: ("tx", 110)

// "add r1, r2, r3" ======> "r1, r2, r3" ==> vector {"r1", "r2", "r3"} ==============> tuple: ("r1", "r2", "r3") 

//                                                                     ====ParseStr=>