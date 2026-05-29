#include <iostream>
#include <string>
#include <unordered_map>

// #include "src/lib/utility.h"

// memo map works like a cache
std::unordered_map<unsigned long, unsigned long> memo; // O(1) (on average), Amortize O(1)

// Fibonacci with memoization
unsigned long Fibonacci_memo(unsigned long n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  if (memo.count(n) > 0) {
    return memo[n];
  } else {
    memo[n] = Fibonacci_memo(n - 1) + Fibonacci_memo(n - 2);
  }
  return memo[n];
}

unsigned long Fibonacci(unsigned long n) {
  if (n == 0 || n == 1) {
    return 1;
  }

  return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// Driver function
int main() {
  unsigned long n = Fibonacci_memo(50);  // O(n)

  unsigned long m = Fibonacci_memo(50);  // O(1)
  std::cout << "n: " << n << std::endl;
  std::cout << "m: " << m << std::endl;
  return 0;
}

