#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#include "src/lib/utility.h"

int IncrementByTen(int a) { return a + 10; }
int MathFunction(int a) { return a ^ 2 + 10; }

std::vector<int> DivEachBy(const std::vector<int>& v, int denominator) {
  std::vector<int> ret;
  // std::transform can be used to map
  std::transform(v.begin(),                // Start of range
                 v.end(),                  // End of range
                 std::back_inserter(ret),  // Collection to insert into
                 // Unary Function that returns transform value
                 [denominator](const int& a) { return a / denominator; });
  return ret;
}
//-----------------------------------------------------
template <typename T, typename U>
T map(const T& v, U f) {
  T ret;
  std::transform(v.begin(), v.end(), std::back_inserter(ret), f);
  return ret;
}
//-----------------------------------------------------
std::vector<int> DivEachByMap(const std::vector<int>& v,
                                int denominator) {
  return map(v, 
  
  [denominator](const int& a) { return a / denominator; });
}

//-----------------------------------------------------

int main() {
  std::vector<int> inputs = {0, 10, 20, 30, 40, 50, 60, 70, 80};
  std::vector<int> outputs1 = DivEachBy(inputs, 10);
  std::vector<int> outputs2 = DivEachByMap(inputs, 10);

  Print(outputs1);
  Print(outputs2);

  return 0;
}