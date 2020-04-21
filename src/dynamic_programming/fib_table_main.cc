#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "src/lib/utility.h"

// Fibonacci with memoization
int Fibonacci(int n) {
  // Allocate for 0 to n included
  std::vector<int> d(n + 1);

  for (int i = 0; i <= n; i++) {
    if (i == 0 || i == 1) {
      d[i] = 1;
    } else {
      d[i] = d[i - 1] + d[i - 2];
    }
  }

  return d[n];
}

// Driver function
int main() {
  int n = Fibonacci(42);
  std::cout << "n: " << n << std::endl;
  return 0;
}