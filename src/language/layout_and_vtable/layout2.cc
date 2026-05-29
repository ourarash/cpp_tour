#include <cstddef>
#include <cstring>
#include <iomanip>
#include <iostream>

struct Inner {
  char a;    // 1 byte
  double b;  // 8 bytes
  char c;    // 1 byte
};

struct Outer {
  char d;
  Inner inner;
  char f;
};

template <typename T>
void dump_bytes(const T& obj) {
  const std::byte* ptr = reinterpret_cast<const std::byte*>(&obj);
  std::cout << "Raw memory of object (" << sizeof(T) << " bytes):\n";
  for (size_t i = 0; i < sizeof(T); ++i) {
    if (i % 8 == 0) std::cout << std::setw(2) << i << ": ";
    std::cout << std::hex << std::setw(2) << std::setfill('0')
              << static_cast<int>(ptr[i]) << " ";
    if (i % 8 == 7) std::cout << "\n";
  }
  std::cout << std::dec << std::setfill(' ') << "\n";
}

int main() {
  std::cout << "sizeof(Inner): " << sizeof(Inner) << "\n";
  std::cout << "offsetof(Inner, a): " << offsetof(Inner, a) << "\n";
  std::cout << "offsetof(Inner, b): " << offsetof(Inner, b) << "\n";
  std::cout << "offsetof(Inner, c): " << offsetof(Inner, c) << "\n";

  std::cout << "\nsizeof(Outer): " << sizeof(Outer) << "\n";
  std::cout << "offsetof(Outer, d): " << offsetof(Outer, d) << "\n";
  std::cout << "offsetof(Outer, inner): " << offsetof(Outer, inner) << "\n";
  std::cout << "offsetof(Outer, f): " << offsetof(Outer, f) << "\n";

  Outer obj{};
  obj.d = 'D';
  obj.inner.a = 'A';
  obj.inner.b = 123456;
  obj.inner.c = 'C';
  obj.f = 'F';

  dump_bytes(obj);
}
