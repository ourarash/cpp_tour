#include <iostream>

constexpr long factorial(long x) {
  if (x > 0) {
    return x * factorial(x - 1);
  } else {
    return 1;
  }
}

int main() {
  const int a = 5;
  const int f = factorial(a);
  std::cout << "f: " << f << std::endl;
  return 0;
}
