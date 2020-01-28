#include "src/lib/utility.h"

#include <iostream>
#include <numeric>
#include <vector>
int main() {
  // lambda expression to print vector
  std::vector<int> my_vector = {5, 12, -1, 45, 1, 34, 22, 11, 5, 11, 22, -1};

  std::sort(my_vector.begin(), my_vector.end(),
            [](const int &a, const int &b) -> bool { return a > b; });

  PrintVector(my_vector);

  std::sort(my_vector.begin(), my_vector.end(),
            [](const int &a, const int &b) -> bool { return a < b; });

  PrintVector(my_vector);

  int f = std::accumulate(my_vector.begin(), my_vector.end(), /*init=*/1,
                           [](int i, int j) { return i + j; });
  std::cout << "f: " << f << std::endl;

  f = std::accumulate(my_vector.begin(), my_vector.end(), /*init=*/1,
                           [](int i, int j) { return i * j; });
  std::cout << "f: " << f << std::endl;

  return 0;
}