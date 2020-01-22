#include <iostream>
#include <string>

// Swaps values of i and j
void SwapUsingReference(int &i, int &j) {
  int temp = i;
  i = j;
  j = temp;
}

bool MultiplyByTwoAndThree(int i, int &mult_2, int &mult_3) {
  if (i >= INT32_MAX / 2) {
    return false;
  }
  mult_2 = i * 2;
  mult_3 = i * 3;
  return true;
}

int main() {

  int i = 1;
  int j = 2;
  std::cout << "i: " << i << ", j: " << j << std::endl;

  SwapUsingReference(i, j);

  std::cout << "i: " << i << ", j: " << j << std::endl;

  int x = 2;
  int x_mult_2, x_mult_3;
  MultiplyByTwoAndThree(x, x_mult_2, x_mult_3);
  std::cout << "x: " << x << ", x_mult_2: " << x_mult_2
            << ", x_mult_3: " << x_mult_3 << std::endl;

  return 0;
}