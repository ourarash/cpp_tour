#include "src/lib/utility.h"
#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

int BinaryOperation(int a, int b, std::function<int(int, int)> func) {
  return func(a, b);
}

int Add(int a, int b) { return a + b; }
int Mult(int a, int b) { return a * b; }

int main() {
  std::vector<std::function<int(int, int)>> operators = {Add, Mult};

  int choice = 0;

  while (true) {
    std::cout << "Enter operation on 10, 20: 0: Add, 1:Mult" << std::endl;
    std::cin >> choice;
    if (choice >= operators.size()) {
      break;
    }
    int result = BinaryOperation(10, 20, operators[choice]);

    std::cout << "result: " << result << std::endl;
  }

  return 0;
}