#include <iostream>
class Base {
 public:
  Base() { std::cout << "Base!" << std::endl; }
  void Talk() { std::cout << "Base talking!" << std::endl; }
  virtual ~Base() { std::cout << "Base destructor!" << std::endl; }
};

class Derived : public Base {
 public:
  Derived() { std::cout << "Derived!" << std::endl; }
  void Talk() { std::cout << "Derived talking!" << std::endl; }
  ~Derived() { std::cout << "Derived destructor!" << std::endl; }
};

int main() {
  {
    Base *b = new Derived();
    b->Talk();
    delete b;
  }
  std::cout << "------------------------------------------" << std::endl;
  {
    Derived d;
    d.Talk();
    Base &b = d;
    b.Talk();
  }
  return 0;
}