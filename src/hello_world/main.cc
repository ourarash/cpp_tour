#include <iostream>

// My first C++ program

int f() {
  int a;
  return a = 10;
}
int main() {
  auto t = f();
  std::cout << "t: " << t << std::endl;

  return 0;  // End of a line
}