#include <iostream>
#include <numeric>
#include <vector>

#include "src/lib/utility.h"

int main() {
  // lambda expression to print vector
  std::vector<int> my_vector = {5, 12, -1, 45, 1, 34, 22, 11, 5, 11, 22, -1};

  int c, d;

  auto my_lambda = [&c](const int &a, const int &b) -> bool { return a > b; };

  std::sort(my_vector.begin(), my_vector.end(), my_lambda);

  PrintVector(my_vector);

  std::sort(my_vector.begin(), my_vector.end(),
            [](const int &a, const int &b) -> bool { return a < b; });

  PrintVector(my_vector);

 std::sort(my_vector.begin(), my_vector.end(), my_lambda);
  // int f = std::accumulate(my_vector.begin(), my_vector.end(), /*init=*/1,
  //                          [](int i, int j) { return i + j; });
  // std::cout << "f: " << f << std::endl;

  // f = std::accumulate(my_vector.begin(), my_vector.end(), /*init=*/1,
  //                          [](int i, int j) { return i * j; });
  // std::cout << "f: " << f << std::endl;

  return 0;
}

// std::sort(v.begin(), v.end(), [](int a, int b) {
//    // Return a greater than b instead of less
//    return a > b;
// });

// std::sort(v.begin(), v.end());
