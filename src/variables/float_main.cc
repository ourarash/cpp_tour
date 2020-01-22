#include "src/lib/utility.h"
#include <iostream>
#include <string>

int main() {

  float f = 0.25;  // A float literal
  double d = 0.24; // A double literal

  std::cout << "f: " << f << std::endl;
  std::cout << "d: " << d << std::endl;

  int i = 5;
  int j = 2;

  float fraction = i / j; // Right hand side is converted to int
  std::cout << "fraction: " << fraction << std::endl;

  fraction = (float)i / j; // Right hand side is float
  std::cout << "fraction: " << fraction << std::endl;

  std::cout << "Size of float: " << sizeof(float) << " byte" << std::endl;

  std::cout << "Size of double: " << sizeof(double) << " byte" << std::endl;
  std::cout << "Size of long double: " << sizeof(long double) << " byte"
            << std::endl;

  return 0;
}