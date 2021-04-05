#include <iostream>

int MyFunction(int i) {
  if (i < 0) {
    std::cout << "Error, i has to be non-negative" << std::endl;
    return -1;
  }
  return i + 1;
}

template <int size = 20>
class A {
  static_assert(size >= 20, "size has to be greater than or equal 20");

 public:
  int get_size() { return size; }
};

template <typename T>
class B {
  // Assert T is a character only
  static_assert(is_char<T>::value,
                "Don't use this template with char.");
};

int main() {
  A<21> a1;
  // A<19> a2;

  std::cout << "a1.get_size(): " << a1.get_size() << std::endl;
  // std::cout << "a2.get_size(): " << a2.get_size() << std::endl;

  return 0;
}