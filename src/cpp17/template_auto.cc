#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

template <auto value>
int f() {
  return value + 1;
}

int main(int argc, char const *argv[]) {
  {
    // C++14
    auto p1 = std::make_pair(5, 'a');
    // Also C++14
    std::pair<int, char> p2(10, 'b');

    // C++17!
    std::pair p3(15, 'c');
  }
  {
    auto x = f<10>();  // deduces int
    std::cout << "x: " << x << std::endl;
  }
  return 0;
}
