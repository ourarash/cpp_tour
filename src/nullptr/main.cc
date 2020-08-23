#include <iostream>

void func(int) {}
void func(int *) {}
void func(bool) {}

int main() {
  func(nullptr);
  // func(NULL);

  return 0;  // End of a line
}