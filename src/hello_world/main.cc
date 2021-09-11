#include <cstring>
#include <iostream>
#include <vector>
// My first C++ program

int main() {
  std::cout << "**** Hello world!" << std::endl;
  int a = 6;
  int b = 4;
  int c = a & b;
  std::cout << "c: " << c << std::endl;

  bool x = true;
  bool y = false;

  bool z = x && y;

  int d = (x == y) ? (100 + 2) : (100 - 2);

  if (x == y) {
    d = 100 + 2;
  } else {
    d = 100 - 2;
  }

  return 1;  // End of a line
}
