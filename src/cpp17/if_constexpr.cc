#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  constexpr int a = 1, b = 1;
  if constexpr (a == b) {
    std::cout << "a: " << a << ", b: " << b << std::endl;
  } else if constexpr (a != b) {
    std::cout << "a: " << a << ", b: " << b << std::endl;
  }

  return 0;
}
