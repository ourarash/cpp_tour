#include <iostream>
#include <string>
#include <vector>
struct Test {
  // Default constructor
  Test() {
    std::cout << "Constructor is called." << std::endl;
    mValue = 0;
  }
  // Copy constructor
  Test(const Test& rhs) {
    std::cout << "Copy Constructor is called." << std::endl;
    mName = rhs.mName;
    mValue = rhs.mValue;
  }

  // Move constructor
  // Test(Test&& rhs) {
  //   std::cout << "Move" << std::endl;
  //   mName = rhs.mName;
  //   mValue = rhs.mValue;
  // }

  std::string mName;
  int mValue;
};

Test doStuff() {
  Test temp;
  temp.mName = "Hello World!";
  return temp;
}

int main() {
  Test a(doStuff());
  std::cout << a.mName << std::endl;
  return 0;
}
