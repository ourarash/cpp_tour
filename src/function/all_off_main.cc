#include <iostream>
#include <numeric>
#include <vector>

bool MyPredicate(const int& i) { return (i % 2) == 0; }

//-----------------------------------------------------
int main() {
  std::vector<int> v1{2, 4, 6, 8, 10};
  auto all_are_even = std::all_of(v1.begin(), v1.end(), MyPredicate);

  auto all_are_odd = std::all_of(v1.begin(), v1.end(),
                                 [](const int& i) { return (i % 2) == 1; });

  std::cout << "all_are_even: " << all_are_even
            << ", all_are_odd: " << all_are_odd << std::endl;
}