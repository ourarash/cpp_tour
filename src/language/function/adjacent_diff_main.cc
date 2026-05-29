#include <functional>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#include "src/lib/utility.h"
//-----------------------------------------------------
int main() {
  std::vector<int> from({10, 15, 20, 25, 30, 35});
  std::vector<int> to;
  std::adjacent_difference(
      from.begin(),            // Start of range
      from.end(),              // End of range
      std::back_inserter(to),  // Collection to insert into
      // Lambda to compute difference (defaults to subtraction)
      [](int a, int b) { return a - b; });

  Print(from);
  Print(to);
}