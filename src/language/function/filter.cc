#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#include "src/lib/utility.h"

//-----------------------------------------------------
bool IsOdd(int i) { return ((i % 2) == 1); }
//-----------------------------------------------------
template <typename T, typename U>
T filter(const T& v, U f) {
  T ret;
  std::copy_if(v.begin(),                // Start of range
               v.end(),                  // End of range
               std::back_inserter(ret),  // Where to insert
               f);                       // Boolean unary function
  return ret;
}
//-----------------------------------------------------
int main() {
  std::vector<int> inputs = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  std::vector<int> outputs1;

  std::copy_if(inputs.begin(), inputs.end(), std::back_inserter(outputs1),
               IsOdd);
  Print(outputs1);
  std::vector<int> outputs2 = filter(inputs, IsOdd);
  Print(outputs2);

  return 0;
}