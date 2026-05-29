#include <iostream>
#include <string>

int main() {

  int value;
  std::cout << "Please enter a value: " << std::endl;
  std::cin >> value;

  if (value > 10) {
    std::cout << "It was GREATER than 10! " << std::endl;
  } else {
    std::cout << "It was LESS than or EQUAL to 10! " << std::endl;
  }

  // Nested if
  std::cout << "Please enter a value: " << std::endl;
  std::cin >> value;

  if (value > 10) {
    std::cout << "It was GREATER than 10! " << std::endl;
  } else if (value == 10) {
    std::cout << "It was EQUAL to 10! " << std::endl;
  } else {
    std::cout << "It was LESS than 10! " << std::endl;
  }

  bool b = false;
  if (b = true) {
    std::cout << "b is true" << std::endl;
  }

  return 0;
}