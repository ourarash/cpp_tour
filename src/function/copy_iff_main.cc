#include <iostream>
#include <numeric>
#include <vector>

//-----------------------------------------------------
int main() {
  std::vector<int> from{1, 2, 3, 4, 5};
  std::vector<int> to;

  auto is_odd = [](const int& i) { return i % 2 == 1 };

  // Copy from the "from" container into the "to" container,
  // only if is_odd returns true for that element
  std::copy_if(from.begin(), from.end(), std::back_inserter(to), is_odd);
}