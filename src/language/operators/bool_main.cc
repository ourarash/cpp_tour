#include "src/lib/utility.h"
#include <iostream>
#include <string>

int main() {

  bool t = true;
  bool f = false;
  bool c = (1 == 5);

  std::cout << "t: " << t << std::endl;
  std::cout << "f: " << f << std::endl;
  std::cout << "c: " << c << std::endl;

  return 0;
}