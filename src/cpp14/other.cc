#include <iostream>
#include <numeric>
#include <string>
#include <vector>

class SizeDelete {
 public:
  SizeDelete() {}
  void operator delete(void* p, std::size_t size) noexcept {
    std::cout << "size: " << size << std::endl;
  };
  void operator delete[](void*, std::size_t) noexcept;

  int x;
  int y;
};
int main() {
  {
    {  // Declare this as a binary number
      int x = 0b1010;
      std::cout << "x: " << x << std::endl;

      // Add digit separators so numbers are easier to read
      int y = 300'000;
      std::cout << "y: " << y << std::endl;

      // Base 8
      int z = 01010;
      std::cout << "z: " << z << std::endl;
    }

    {
      long long decn = 1'000'000'000ll;
      long long hexn = 0xFFFF'FFFFll;
      long long octn = 00'23'00ll;
      long long binn = 0b1010'0011ll;

      std::cout << "octn: " << octn << std::endl;
    }

    {
      SizeDelete* p = new SizeDelete();
      delete p;
    }
  }

  return 0;
}