#include <iostream>
#include <string>

int main() {
  int i = 10;
  int j = 20;

  // Uninitialized
  int *q;
  // std::cout << "*q: " << *q << std::endl; // <------- Unsafe!

  // Modifying the value of the pointer
  q = &i;
  q++;
  // std::cout << "*q: " << *q << std::endl; // <------- Unsafe!

  // Using a deleted pointer
  int *r = new int;
  *r = 5;
  std::cout << "*r: " << *r << std::endl;

  delete r;

  std::cout << "*r: " << *r << std::endl; // Unsafe!

  // Deleting a pointer twice has undefined behavior!
  delete r;


  // Memory leak
  {
    int *p;
    p = new int(5);
    std::cout << "p: " << p << std::endl;
  }
  // p does not have scope here!

  return 0;
}