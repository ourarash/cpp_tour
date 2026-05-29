#include <iostream>

constexpr unsigned long long factorial(long x) {
  if (x > 0) {
    return x * factorial(x - 1);
  } else {
    return 1;
  }
}

constexpr int product(int x, int y) { return (x * y); }
constexpr auto InchToMm(double inch) { return inch * 25.4; }

int main() {
  {
    const double const_inch{6};
    const auto mm1{InchToMm(const_inch)};  // at compile time ✔

    double dynamic_inch{8};
    const auto mm2{InchToMm(dynamic_inch)};  // at run time ❌ (still compiles)
  }
  {
    const int x = product(1, 2);
    std::cout << "x: " << x << std::endl;
  }

  {
    int x[product(1, 2)];
    std::cout << "x: " << x << std::endl;
  }

  // Compile with
  // g++ src/preprocessor/constexpr.cc -std=c++17 -pedantic -Wall -Wextra
  // -Werror
  {
    // int a, b;
    // std::cin >> a >> b;
    // int x[product(a, b)];

    // std::cout << "sizeof(x): " << sizeof(x) << std::endl;
    // for (size_t i = 0; i < sizeof(x) / sizeof(int); i++) {
    //   std::cout << "x[i]: " << x[i] << std::endl;
    // }
    // std::cout << "x: " << x << std::endl;
  }
  // const long a = 5;
  // constexpr unsigned long long f = factorial(a + 10000);
  // std::cout << "f: " << f << std::endl;
  return 0;
}
