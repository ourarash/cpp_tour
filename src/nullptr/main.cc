#include <iostream>

void func(int) { std::cout << "int" << std::endl; }
void func(int *) { std::cout << "pointer" << std::endl; }
void func(bool) { std::cout << "bool" << std::endl; }
// void func(long *) { std::cout << "pointer" << std::endl; }

int main() {
  func(nullptr);
  // func(NULL);

  return 0;  // End of a line
}