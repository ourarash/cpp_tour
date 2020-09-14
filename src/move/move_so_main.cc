#include <iostream>
#include <string>

struct Test {
  // Default constructor
  Test() {
    std::cout << "Constructor is called." << std::endl;
    mValue = 0;
  }
  
  // Copy constructor
  // Test(const Test& rhs) {
  //   std::cout << "Copy Constructor is called." << std::endl;
  //   mName = rhs.mName;
  //   mValue = rhs.mValue;
  // }
    
  std::string mName;
  int mValue;
};

int main() {
  Test a;
  Test b = std::move(a);
  return 0;
}