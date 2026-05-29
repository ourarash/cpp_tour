#include <iostream>
#include <vector>

#include "src/lib/solution.h"

int main() {
  int x, y;

  std::cout << "Input x coordinate: ";
  std::cin >> x;

  std::cout << "Input y coordinate: ";
  std::cin >> y;

  int array[8][8];

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if ((i - x == j - y) || (i - x == -(j - y))) {
        array[i][j] = 1;
      } else {
        array[i][j] = 0;
      }
    }
  }

  array[x][y] = 2;

  for (int j = 7; j >= 0; j--) {
    for (int i = 0; i < 8; i++) {
      std::cout << array[i][j];
    }
    std::cout << std::endl;
  }
  return 0;
}
