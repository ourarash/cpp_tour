#include <iostream>
class Base {
 public:
  Base() { std::cout << "Base!" << std::endl; }

  // No virtual destructor defined
  virtual void Foo() = 0;  // abstract method
};
class Derived final : public Base {
 public:
  Derived() { std::cout << "Derived!" << std::endl; }
  ~Derived() { std::cout << "Derived destructor!" << std::endl; }
  void Foo(){};  // Will also be virtual
};

int main() {
  {
    Base *b = new Derived();
    // b->Talk();
    // b->Speak();

    delete b;
  }

  return 0;
}