#include <iostream>
#include <string>

int main() {
  int a = 1;
  a++;
  std::cout << "a: " << a << std::endl;
  a += 2;
  std::cout << "a: " << a << std::endl;
  std::cout << "------------------------------------------" << std::endl;
  // Mod
  int i = 12;
  int j = 5;
  int k = i % j;
  std::cout << "k: " << k << std::endl;
  std::cout << "------------------------------------------" << std::endl;
  // bitwise
  int b = 0b00000001;
  int c = 0b00000011;
  int o = b & c;
  std::cout << "b & c: " << o << std::endl;

  o = b | c;
  std::cout << "b | c: " << o << std::endl;

  int shift = a << 1;
  std::cout << "shift: " << shift << std::endl;

  shift <<= 2;
  std::cout << "shift: " << shift << std::endl;
  
  std::cout << "------------------------------------------" << std::endl;
  // Ternary
  int t = (3 * 54 > 100) ? 0 : 1;
  std::cout << "t: " << t << std::endl;

  std::cout << ((10 > 0) ? "Yes" : "No!") << std::endl;

  t = (5 > 3) ? (4 < 3) ? 1 : 2 : 4;
  std::cout << "t: " << t << std::endl;

  return 0;
}