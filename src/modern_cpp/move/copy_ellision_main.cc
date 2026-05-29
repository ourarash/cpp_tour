// Shows the omission of copy constructor call
// Run with bazel --copt="-fno-elide-constructors" to disable copy elision.

#include <iostream>

class B {
 public:
  B(const char* str = "\0")  // default constructor
  {
    std::cout << "Constructor called" << std::endl;
  }

  B(const B& b)  // copy constructor
  {
    std::cout << "Copy constructor called" << std::endl;
  }
};

int main() {
  B ob = "copy me";
  return 0;
}
