#include <iostream>
#include <string>

int main() {

  int i = 10;
  int &j = i;
  int k = i;

  std::cout << "i: " << i << std::endl;
  std::cout << "j: " << j << std::endl;
  std::cout << "k: " << k << std::endl;

  j++;
  std::cout << "i: " << i << std::endl;
  std::cout << "j: " << j << std::endl;
  std::cout << "k: " << k << std::endl;

  return 0;
}