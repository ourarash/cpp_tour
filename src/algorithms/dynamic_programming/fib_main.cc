#include <iostream>
#include <string>

// Recursive Fibonacci Implementation
int Fibonacci(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return Fibonacci(n - 1) + Fibonacci(n - 2);
}

template <class T>
int ExpectEqual(T expected, T actual) {
  if (expected == actual) {
    std::cout << "PASS: " << expected << " == " << actual << std::endl;
    return 0;
  } else {
    std::cout << "PASS: " << expected << " != " << actual << std::endl;
    return 1;
  }
}
int main() {
  int result = 0;
  result += ExpectEqual(Fibonacci(0), 1);
  result += ExpectEqual(Fibonacci(1), 1);
  result += ExpectEqual(Fibonacci(2), 2);
  result += ExpectEqual(Fibonacci(3), 3);
  result += ExpectEqual(Fibonacci(4), 5);
  std::cout << "Number of failed tests: " << result << std::endl;
  return 0;
}