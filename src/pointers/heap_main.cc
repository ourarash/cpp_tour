#include <iostream>
#include <string>

int main() {

  int *p = nullptr;

  // We conditionally use more memory
  if (4 > 2) {
    p = new int;
    *p = 5;
    std::cout << "*p: " << *p << std::endl;
  }

  if (p != nullptr) {
    delete p;
  }

  p = new int(10);

  std::cout << "*p: " << *p << std::endl;

  delete p;
  return 0;
}