#include <iostream>
// sized class-specific deallocation functions
struct X {
  static void operator delete(void* ptr, std::size_t sz) {
    std::cout << "custom delete for size " << sz << '\n';
    ::operator delete(ptr);
  }
  static void operator delete[](void* ptr, std::size_t sz) {
    std::cout << "custom delete for size " << sz << '\n';
    ::operator delete(ptr);
  }
};
int main() {
  X* p1 = new X;
  delete p1;
  X* p2 = new X[10];
  delete[] p2;
}