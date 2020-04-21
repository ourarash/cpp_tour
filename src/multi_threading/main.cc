#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <thread>
#include <vector>
#include "src/lib/utility.h"

int main() {
  const int number_of_threads = 2;
  const int step = 1000 * 1000 * 1000 / number_of_threads;
  std::vector<int64_t> partial_sums(number_of_threads);

  std::thread t1(GetRangeSum, 0, step);
  std::thread t2(GetRangeSum, step, 2 * step + 1);

  t1.join();
  t2.join();

  uint64_t total =
      std::accumulate(partial_sums.begin(), partial_sums.end(), uint64_t(0));
  Print(partial_sums);
  std::cout << "total: " << total << std::endl;

  return 0;
}