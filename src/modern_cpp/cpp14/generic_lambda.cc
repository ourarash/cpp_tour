#include <iostream>
#include <numeric>
#include <string>
#include <vector>
int adder(int a, int b) { return a + b; }
int main() {
  {
    std::vector<int> ivec = {1, 2, 3, 4};
    std::vector<std::string> svec = {"red", "green", "blue"};

    // auto adder = [](auto op1, auto op2) { return op1 + op2; };

    std::cout << "int result : "
              << std::accumulate(ivec.begin(), ivec.end(), 0, adder)
              << std::endl;

    std::cout << "string result : "
              << std::accumulate(
                     svec.begin(), svec.end(), std::string(""),
                     [](auto op1, auto op2) { return op1 + op2; } )
              << std::endl;
  }
}