#include <iostream>
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

  // Move constructor
  // Test(Test&& rhs) {
  //   mName = std::move(rhs.mName);
  //   mValue = std::move(rhs.mValue);
  //   std::cout << "Move" << std::endl;
  // }
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

Test doStuff() {
  Test temp;
  temp.mName = "Hello World!";
  return temp;
}

int main() {
  Test b;
  b.mName = "Goodbye!";
  b = doStuff();
  // Test b = doStuff();
  std::cout << b.mName << std::endl;
  return 0;
}
