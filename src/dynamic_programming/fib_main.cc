#include <iostream>
#include <string>

#include "src/lib/utility.h"

// Recursive Fibonacci Implementation
int Fibonacci(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
  int n = Fibonacci(50);
  std::cout << "n: " << n << std::endl;
  return 0;
}