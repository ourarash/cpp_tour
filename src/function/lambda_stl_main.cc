#include <iostream>
#include <numeric>
#include <vector>

#include "src/lib/utility.h"
bool MyOwnFunction(int a, int b) { return a > b; }

MyOwnDevider(const float &a){return a / ? }

std::vector<float> divEachBy(const std::vector<float> &v, float denominator) {
  std::vector<float> ret;
  // std::transform can be used to map
  std::transform(v.begin(),                // Start of range
                 v.end(),                  // End of range
                 std::back_inserter(ret),  // Collection to insert into
                 // Unary Function that returns transform value
                 [denominator](const float &a) { return a / denominator; });
  return ret;
}

int main() {
  // lambda expression to print vector
  std::vector<int> my_vector = {5, 12, -1, 45, 1, 34, 22, 11, 5, 11, 22, -1};
  std::vector<int> my_vector2 = {5, 12, -1, 45, 1, 34, 22, 11, 5, 11, 22, -1};

  std::sort(my_vector.begin(), my_vector.end(), MyOwnFunction);
  std::sort(my_vector.begin(), my_vector.end(), [&](int a, int b) -> bool {
    // Return a greater than b instead of less
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    return a > b;
  });

  int c = 0, d;
  c++;
  auto my_lambda2 = [&c]() -> void { c++ };
  my_lambda2();  // also does c++
  std::cout << "c: " << c << std::endl;

  auto my_lambda = [&c](const int &a, const int &b) -> bool { return a > b; };
  std::sort(my_vector.begin(), my_vector.end(), my_lambda);
  std::sort(my_vector2.begin(), my_vector2.end(), my_lambda);

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
