#include <iostream>
#include <string>

int main() {
  int i = 8;
  int *q;
  int *p = nullptr;  // Doesn't point to anything.
  // *p = 5; // Crash your program!

  
q = &i;
  p = new int;  // Give me a valid location in memory and have p point to it.
  *p = 5;       // Ok!
  (*p)++;       // Ok! Derefrencing a pointer.

  
  int* &j = p;

  std::cout << "*p: " << *p << std::endl;
  std::cout << "*j: " << *j << std::endl;

  delete p;  // I'm returning that valid location back!
  // (*p)++; // Not ok! Can crash!

  // We conditionally use more memory
  if (4 > 2) {
    p = new int;
    *p = 5;
    std::cout << "*p: " << *p << std::endl;
  }

  if (p != nullptr) {
    delete p;

    *p = 20;
  }

  p = new int(10);

  std::cout << "*p: " << *p << std::endl;

  delete p;
  return 0;
}