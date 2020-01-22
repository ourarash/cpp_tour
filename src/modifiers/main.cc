#include "src/lib/utility.h"
#include <iostream>

int main() {
  std::cout << "Size of char : " << sizeof(char) << " byte" << std::endl;
  std::cout << "Size of int : " << sizeof(int) << " bytes" << std::endl;
  std::cout << "Size of short int : " << sizeof(short int) << " bytes"
            << std::endl;
  std::cout << "Size of long int : " << sizeof(long int) << " bytes"
            << std::endl;
  std::cout << "Size of signed long int : " << sizeof(signed long int)
            << " bytes" << std::endl;
  std::cout << "Size of unsigned long int : " << sizeof(unsigned long int)
            << " bytes" << std::endl;
  std::cout << "Size of float : " << sizeof(float) << " bytes" << std::endl;
  std::cout << "Size of double : " << sizeof(double) << " bytes" << std::endl;
  std::cout << "Size of wchar_t : " << sizeof(wchar_t) << " bytes" << std::endl;
  return 0;
}