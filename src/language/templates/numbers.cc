#include <iostream>

// The size cannot be greater than 100
template <int size = 20>
class A {
 public:
  int get_size() { return size; }
};

// Not valid for float
// template <float size>
// class B {
//   int get_size() { return size; }
// };

int main() {
  A<3> a1;
  A<4> a2;
  A<101> a3;
  A<> a4;

  std::cout << "a1.get_size(): " << a1.get_size() << std::endl;
  std::cout << "a2.get_size(): " << a2.get_size() << std::endl;
  std::cout << "a3.get_size(): " << a3.get_size() << std::endl;

  return 0;
}