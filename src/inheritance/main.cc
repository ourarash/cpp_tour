#include <iostream>
class Base {
 public:
  Base() { std::cout << "Base!" << std::endl; }
  virtual ~Base() { std::cout << "Base destructor!" << std::endl; }
};

class Derived : public Base {
 public:
  Derived() { std::cout << "Derived!" << std::endl; }
  ~Derived() { std::cout << "Derived destructor!" << std::endl; }
};

int main() {
  Base *b = new Derived();
  delete b;
  return 0;
}