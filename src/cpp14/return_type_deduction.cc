#include <iostream>
#include <numeric>
#include <string>
#include <vector>

// This is fine in C++14
auto sq2(double d) { return d * d; }

// auto func1(bool b) {
//   if (b) {
//     return 1;
//   } else {
//     return 1.0;  // Error!
//   }
// }

auto factorial(unsigned n) {
  if (n == 0) {
    return (unsigned) 1;
  } else {
    return n * factorial(n - 1);  // OK
  }
}

int main() {
  {
    // This is fine in C++11
    auto sq1 = [](double d) { return d * d; };

    sq1(10);
  }
  return 1;
}