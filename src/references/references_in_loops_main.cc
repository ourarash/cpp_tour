#include <iostream>
#include <string>
#include <vector>

#include "src/lib/utility.h"

int main() {
  std::vector<int> my_vector = {1, 2, 3, 4, 5, 6, 7, 8};

  PrintVector(my_vector);

  for (int n : my_vector) {
    n++;
    std::cout << "n: " << n << std::endl;
  }

  PrintVector(my_vector);

  for (auto &n : my_vector) {
    n++;
    std::cout << "n: " << n << std::endl;
  }
  PrintVector(my_vector);

  {
    int a = 10;
    int b = 10;
    std::cout << "a: " << a << ", b: " << b << std::endl;
  }

  {
    int a = 20;
    int b = 30;
    {
      // int a = 50;
      std::cout << "a: " << a << std::endl;
    }
    std::cout << "a: " << a << ", b: " << b << std::endl;
  }

  return 0;
}