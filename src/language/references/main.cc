#include <iostream>
#include <string>

int main() {
  int i = 10;   // original
  int& j = i;   // reference
  int* p = &i;  // pointer
  int k = i;    // copy!

  std::cout << "i: " << i << std::endl;
  std::cout << "j: " << j << std::endl;
  std::cout << "k: " << k << std::endl;

  j++;     // i++
  (*p)++;  // i++
  std::cout << "i: " << i << std::endl;
  std::cout << "j: " << j << std::endl;
  std::cout << "k: " << k << std::endl;

  p++;
  (*p)++;  // What is incremented? Might crash your program!
  std::cout << "i: " << i << std::endl;
  std::cout << "j: " << j << std::endl;
  std::cout << "k: " << k << std::endl;

  return 0;
}