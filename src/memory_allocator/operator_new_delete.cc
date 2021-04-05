#include <iostream>
#include <stdexcept>
struct X {
  // X() { throw std::runtime_error(""); }
  X() { std::cout << "Constructor!" << std::endl; }
  ~X() { std::cout << "Destructor!" << std::endl; }
  // custom placement new
  static void* operator new(std::size_t sz, bool b) {
    std::cout << "custom placement new called, b = " << b << '\n';
    return ::operator new(sz);
  }
  // custom placement delete
  void operator delete(void* ptr, bool b) {
    std::cout << "custom placement delete called, b = " << b << '\n';
    ::operator delete(ptr);
  }
};
int main() {
  try {
    X* p1 = new (true) X;
  } catch (const std::exception& e) {
    std::cout << "e.what(): " << e.what() << std::endl;
  }
}