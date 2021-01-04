#include <iostream>
#include <string>
#include <vector>

int main() {
  {
    int x = 4;
    auto y = [& r = x, x = x + 1]() {
      r += 2;
      return x + 2;
    };

    y();  // Updates ::x to 6, and initializes y to 7.

    std::cout << "x: " << x << std::endl;
  }

  {
    int x = 4;
    auto y = [& r = x, x = x + 1]() -> int {
      r += 2;  // r=6
      std::cout << "r: " << r << std::endl;
      return x + 2;  // 5+2
    };
    std::cout << "y(): " << y() << std::endl;
  }

  // Move inside lambda
  {
    std::unique_ptr<int> p(new int);
    int x = 5;
    *p = 11;
    std::cout << "p: " << p << std::endl;
    auto y = [p = std::move(p)]() { std::cout << "inside: " << *p << "\n"; };

    y();
    std::cout << "p: " << p << std::endl;
    std::cout << "outside: " << *p << "\n";
  }
}