#include <iostream>

template <int size = 20>
class A {
  static_assert(size >= 20, "size has to be greater than or equal 20");

 public:
  int get_size() { return size; }
};

int main() {

  A<21> a1;
  // A<19> a2;



  std::cout << "a1.get_size(): " << a1.get_size() << std::endl;
  // std::cout << "a2.get_size(): " << a2.get_size() << std::endl;

  return 0;
}