#include <iostream>
template <typename T, int size = 10>
class A {
 public:
  A() { std::cout << "size: " << size << std::endl; }
  void PrintSize() { std::cout << "size: " << size << std::endl; }
};

// Can't do this for floats
// template <float size>
// class B {
//   B() { std::cout << "size: " << size << std::endl; }
//   void PrintSize() { std::cout << "size: " << size << std::endl; }
// };

int main(int argc, char const *argv[]) {
  {
    A<int, 5> a;
    a.PrintSize();
  }
  return 0;
}
