#include <functional>
#include <future>
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
  std::vector<std::future<uint64_t>> tasks;

  for (uint64_t i = 0; i < number_of_threads; i++) {
    tasks.push_back(std::async(GetRangeSum, i * step, (i + 1) * step));
  }
  
  uint64_t total = 0;
  for (auto &t : tasks) {
    total += t.get();
  }

  std::cout << "total: " << total << std::endl;

  return 0;
}