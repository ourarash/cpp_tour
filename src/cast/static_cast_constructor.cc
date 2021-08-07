#include <iostream>
#include <string>
#include <vector>
class Class {
 public:
  //<< conversion constructor
  Class(int) { std::cout << "Constructor!" << std::endl; }
};

int main(int argc, char const *argv[]) {
  // These all call the conversion constructor!
  {
    int what = 0;
    Class object = static_cast<Class>(what);
  }
  {
    int what = 0;
    Class object = (Class)what;
  }
  {
    int what = 0;
    Class object = Class(what);
  }
  return 0;
}
