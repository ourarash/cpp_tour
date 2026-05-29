#include <iostream>
#include <string>
#include <vector>

class MyClass {
 public:
  MyClass(int a) : a_(a), b_(0) {}
  MyClass(int a, int b) : a_(a), b_(b) {}
  void Print() { std::cout << "a: " << a_ << ", b: " << b_ << std::endl; }
  int a_;
  int b_;
};
int add(int a, int b) {
  int c = a + b;
  return c;
}
int main() {
  MyClass my_class1(3);
  my_class1.Print();
  MyClass my_class2({1, 2});  //--> Passing two parameters to a constructor
                              //(uniform initialization)
  my_class2.Print();

  //  auto x = add({1, 2}); //---> won't compile!
}