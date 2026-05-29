#include <iostream>

class Base {
 public:
  void Talk() { std::cout << "Base talking" << std::endl; }
};
class Derived : public Base {
 public:
  void Talk() { std::cout << "Derived talking" << std::endl; }
};

int main(int argc, char const *argv[]) {
  Derived d;

  Base *pb = &d;  // implicitly convert Derived* Base*

  std::cout << "&d: " << &d << std::endl;
  std::cout << "pb: " << pb << std::endl;

  d.Talk();
  pb->Talk();
  return 0;
}
