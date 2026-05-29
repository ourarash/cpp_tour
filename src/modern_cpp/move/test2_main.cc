/**
 * Shows the use of move constructor vs copy constructor;
 * Run with:
 *  g++ src/move/test2_main.cc  -std=c++17 -fno-elide-constructors
 *  g++ src/move/test2_main.cc  -std=c++17
 */
#include <iostream>
#include <vector>

class MyClass {
 public:
  int *ptr;

 public:
  MyClass() {
    // Default constructor
    std::cout << "Calling Default constructor" << std::endl;
    ptr = new int;
  }

  MyClass(const MyClass &obj) {
    // Copy Constructor
    // copy of object is created
    this->ptr = new int;
    // Deep copying
    std::cout << "Calling Copy constructor" << std::endl;
  }

  // MyClass(MyClass &&obj) {
  //   // Move constructor
  //   // It will simply shift the resources,
  //   // without creating a copy.
  //   std::cout << "Calling Move constructor" << std::endl;
  //   this->ptr = obj.ptr;
  //   obj.ptr = nullptr;
  // }

  ~MyClass() {
    // Destructor
    std::cout << "Calling Destructor" << std::endl;
    delete ptr;
  }
};

MyClass ReturnMyClass() {
  MyClass temp;
  temp.ptr = nullptr;
  return temp;
}

int main() {
  MyClass a;
  MyClass b = a;
  MyClass c = ReturnMyClass();
  return 0;
}