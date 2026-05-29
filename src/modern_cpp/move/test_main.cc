#include <iostream>
#include <string>
#include <vector>
struct Test {
  // Default constructor
  Test() {
    std::cout << "Constructor is called." << std::endl;
    mValue = 0;
  }
  ~Test() {
    std::cout << "Destructor is called." << std::endl;
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
  // This one cause the default constructor for mName and mValue
  // Then, it calls move assignment for mName and mValue
  // Test(Test &&rhs) {
  //   std::cout << "Move" << std::endl;
  //   mName = std::move(rhs.mName);    // ----> We saved here :)
  //   mValue = std::move(rhs.mValue);  // std::move will get ignored.
  //   rhs.mValue = 0;                  // SOME_INVALID_VALUE
  // }

  // This one calls the move constructor for mName and mValue
  Test(Test &&rhs)
      : mName(std::move(rhs.mName)), mValue(std::move(rhs.mValue)) {
    std::cout << "Move Constructor" << std::endl;
  }

  // Move Assignment
  Test &operator=(Test &&rhs) {
    std::cout << "Move Assignment" << std::endl;
    if (&rhs != this) {
      mName = std::move(rhs.mName);  // move assignment of std::string.
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
  Test a(doStuff());
  std::cout << a.mName << std::endl;
  std::cout << "------------------------------------------" << std::endl;

  Test c;         // Default constructor?
  c = doStuff();  // Move assignment operator

  //-----------------------------------------------------
  {
    Test a(doStuff());  // Move constructor

    Test b;
    b = doStuff();      // Move assignment.
  }
}