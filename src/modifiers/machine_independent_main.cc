#include "src/lib/utility.h"
#include <iostream>

int main() {
  std::cout << "Size of int8_t: " << sizeof(int8_t) << " byte" << std::endl;
  std::cout << "Size of int16_t: " << sizeof(int16_t) << " byte" << std::endl;
  std::cout << "Size of int32_t: " << sizeof(int32_t) << " byte" << std::endl;
  std::cout << "Size of int64_t: " << sizeof(int64_t) << " byte" << std::endl;
  std::cout << "Size of uint8_t: " << sizeof(uint8_t) << " byte" << std::endl;
  std::cout << "Size of uint16_t: " << sizeof(uint16_t) << " byte" << std::endl;
  std::cout << "Size of uint32_t: " << sizeof(uint32_t) << " byte" << std::endl;
  std::cout << "Size of uint64_t: " << sizeof(uint64_t) << " byte" << std::endl;

  return 0;
}