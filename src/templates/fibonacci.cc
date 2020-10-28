#include <iostream>
// Calculate a Fibonacci number at COMPILE TIME
template <unsigned int i>
struct Fibonacci {
  static const int value = Fibonacci<i - 2>::value + Fibonacci<i - 1>::value;
  static_assert(i != 0, "Fibonacci of 0 is undefined.");
};
// The "base cases" are i == 1 or i == 2
// So use specialization...
template <>
struct Fibonacci<1> {
  static const int value = 1;
};
template <>
struct Fibonacci<2> {
  static const int value = 1;
};

int main() {
  // This would be 610 (at COMPILE TIME)
  int fib = Fibonacci<15>::value;
  std::cout << "fib: " << fib << std::endl;
}
