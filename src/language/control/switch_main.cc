#include <iostream>
#include <string>

int main() {

  int value;
  std::cout << "Please enter a value: " << std::endl;
  std::cin >> value;

  switch (value) {
  case 1:
    std::cout << "You entered 1!" << std::endl;
    break;

  case 2:
  case 3:
    std::cout << "You entered 2 or 3!" << std::endl;
    break;

  default:
    std::cout << "You entered an invalid number!" << std::endl;
  }

  return 0;
}