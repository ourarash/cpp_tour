#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
  int i = 10;
  int j = 20;

  int &k = i;
  // &k= j;      // Error!
  std::cout << "k: " << k << std::endl;

  // Pointers can be reassigned
  int *p = &i;
  std::cout << "*p: " << *p << std::endl;

  p = &j;
  std::cout << "*p: " << *p << std::endl;

  
}