#include <iostream>
#include <numeric>
#include <vector>
//-----------------------------------------------------
/**
 * Calculates average using a loop.
 */
float AverageVectorLoop(const std::vector<float>& v) {
  float sum = 0.0f;
  for (auto& i : v) {
    sum += i;
  }

  return sum / v.size();
}
//-----------------------------------------------------
/**
 * Calculates given {sum} and {quantity}.
 */
float Average(float sum, size_t quantity) { return sum / quantity; }
//-----------------------------------------------------
/**
 * Calculates average using functional programming.
 */
float AccumulateVector(const std::vector<float>& v) {
  // std::accumulate can work as a REDUCE
  return std::accumulate(v.begin(),  // Start of range
                         v.end(),    // End of range
                         0.0f,       // Initial value
                         // Binary lambda expression
                         [](const float& a, const float& b) { return a + b; });
}

//-----------------------------------------------------
float AverageVectorFP(const std::vector<float>& v) {
  return Average(AccumulateVector(v), v.size());
}

//-----------------------------------------------------
int main() {
  std::vector<float> my_vector = {1, 2, 3, 4, 5, 6};

  auto sum_1 = AverageVectorLoop(my_vector);
  auto sum_2 = AverageVectorFP(my_vector);
  std::cout << "sum_1: " << sum_1 << ", sum_2: " << sum_2 << std::endl;
  return 0;
}