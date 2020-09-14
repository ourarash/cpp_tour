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
  Test(const Test &rhs) {
    std::cout << "Copy Constructor is called." << std::endl;
    mName = rhs.mName;
    mValue = rhs.mValue;
  }

  // Copy Assignment
  Test &operator=(const Test &rhs) {
    std::cout << "Copy Assignment" << std::endl;
    if (&rhs != this) {
      mName = rhs.mName;
      mValue = rhs.mValue;
    }
    return *this;
  }

  // Move constructor
  Test(Test &&rhs) {
    std::cout << "Move" << std::endl;
    mName = std::move(rhs.mName);    // ----> We saved here :)
    mValue = std::move(rhs.mValue);  // ----> We saved here :)
  }

  // Move Assignment
  Test &operator=(Test &&rhs) {
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
  Test c;         // Default constructor?
  c = doStuff();  // Move assignment operator
}