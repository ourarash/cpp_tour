#include <iostream>
#include <unordered_map>
#include <string>

#include "src/lib/utility.h"

// memo map works like a cache
std::unordered_map<int, int> memo;

// Fibonacci with memoization
int Fibonacci(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  if (memo.count(n) > 0) {
    return memo[n];
  } else {
    memo[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
  }
  return memo[n];
}

// Driver function
int main() {
  int n = Fibonacci(42);
  std::cout << "n: " << n << std::endl;
  return 0;
}