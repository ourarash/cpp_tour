#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

struct Test {
  // Default Constructor
  Test() : mValue(0) { std::cout << "Default" << std::endl; }

  // Copy constructor
  Test(const Test& rhs) : mName(rhs.mName), mValue(rhs.mValue) {
    std::cout << "Copy" << std::endl;
  }

  // Move constructor
  Test(Test&& rhs)
      : mName(std::move(rhs.mName)), mValue(std::move(rhs.mValue)) {
    std::cout << "Move" << std::endl;
  }

  // Destructor
  ~Test() { std::cout << "Destructor" << std::endl; }
  // Assignment
  Test& operator=(const Test& rhs) {
    std::cout << "Assignment" << std::endl;
    if (&rhs != this) {
      mName = rhs.mName;
      mValue = rhs.mValue;
    }
    return *this;
  }
  // Move Assignment
  Test& operator=(Test&& rhs) {
    std::cout << "Move Assignment" << std::endl;
    if (&rhs != this) {
      mName = std::move(rhs.mName);
      mValue = std::move(rhs.mValue);
    }
    return *this;
  }

  std::string mName;
  int mValue;
};

template <typename T>
T f() {
  return T{};  // no copy here (C++17)
}

template <typename T>
T g() {
  T t;
  return t;  // one copy, can be elided but elision is not guaranteed
}

template <typename T>
T h(T& t) {
  return t;  // one guaranteed copy (by necessity)
}

int main(int argc, char const* argv[]) {
  // Test x = f<Test>();              // no copy here either (C++17)
  // auto y = g<Test>();              // no copy here (C++17)
  // auto z = h<Test>(x);             // no copy here (C++17)
  auto t = Test(Test(f<Test>()));  // only one call to default constructor
  // of T, to initialize x

  std::cout << "End" << std::endl;
  return 0;
}
