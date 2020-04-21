#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <thread>
#include <vector>

#include "src/lib/utility.h"

int main() {
  const int number_of_threads = 10;
  uint64_t number_of_elements =
      1000 * 1000 * 1000;
  uint64_t step = number_of_elements / number_of_threads;
  std::vector<std::thread> threads;
  std::vector<uint64_t> partial_sums(number_of_threads);

  auto start_time = std::chrono::high_resolution_clock::now();

  for (int i = 0; i < number_of_threads; i++) {
    threads.push_back(std::thread(AccumulateRange,
                                  std::ref(partial_sums[i]), i * step,
                                  (i + 1) * step));
  }

  for (std::thread &th : threads) {
    if (th.joinable()) {
      th.join();
    }
  }

  auto end_time = std::chrono::high_resolution_clock::now();
  auto duration =
      std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);

  auto total = std::accumulate(partial_sums.begin(), partial_sums.end(), uint64_t(0));
  Print(partial_sums);
  std::cout << "total: " << total << std::endl;
  std::cout << "duration: " << duration.count() << std::endl;

  return 0;
}