#include "src/lib/utility.h"
#include <iostream>

int main() {
  std::cout << "INT8_MIN :" << INT8_MIN << std::endl;
  std::cout << "INT8_MAX :" << INT8_MAX << std::endl;
  
  std::cout << "INT16_MIN:" << INT16_MIN << std::endl;
  std::cout << "INT16_MAX:" << INT16_MAX << std::endl;
  
  std::cout << "INT32_MIN:" << INT32_MIN << std::endl;
  std::cout << "INT32_MAX:" << INT32_MAX << std::endl;
  
  std::cout << "INT64_MIN:" << INT64_MIN << std::endl;
  std::cout << "INT64_MAX:" << INT64_MAX << std::endl;
  
  std::cout << "UINT8_MAX:" << UINT8_MAX << std::endl;
  std::cout << "UINT16_MAX:" << UINT16_MAX << std::endl;
  std::cout << "UINT32_MAX:" << UINT32_MAX << std::endl;
  std::cout << "UINT64_MAX:" << UINT64_MAX << std::endl;

  return 0;
}