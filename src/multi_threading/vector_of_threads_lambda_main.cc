#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <thread>
#include <vector>

#include "src/lib/utility.h"

int main() {
  const int number_of_threads = 10;
  uint64_t number_of_elements = 1000 * 1000 * 1000;
  uint64_t step = number_of_elements / number_of_threads;
  std::vector<std::thread> threads;
  std::vector<uint64_t> partial_sums(number_of_threads);

  for (uint64_t i = 0; i < number_of_threads; i++) {
    threads.push_back(std::thread([i, &partial_sums, step] {
      for (uint64_t j = i * step; j < (i + 1) * step; j++) {
        partial_sums[i] += j;
      }
    }));
  }

  for (std::thread &t : threads) {
    if (t.joinable()) {
      t.join();
    }
  }

  uint64_t total =
      std::accumulate(partial_sums.begin(), partial_sums.end(), uint64_t(0));
  Print(partial_sums);
  std::cout << "total: " << total << std::endl;

  return 0;
}