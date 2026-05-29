#include <iostream>
#include <string>
#include <vector>

class A {
 public:
  virtual void TakeDamage(int amount) { std::cout << "A" << std::endl; }
};

class B : public A {
 public:
  // void TakeDamage() { std::cout << "B" << std::endl; }

  // void TakeDamage() override { std::cout << "B" << std::endl; }
};

int main(int argc, char const *argv[]) {
  A a;
  B b;

  return 0;
}
