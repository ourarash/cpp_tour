#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#include "src/lib/utility.h"
//-----------------------------------------------------
int main() {
  // Make a vector w/ 10 elements
  std::vector<int> v(10);

  std::generate(v.begin(),  // start of range
                v.end(),    // end of range
                // Lambda that returns generated value
                []() { return rand(); });

  Print(v);
}