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
  std::vector<int64_t> partial_sums(number_of_threads);
  std::vector<AccumulateFunctor *> functors;

  for (int i = 0; i < number_of_threads; i++) {
    AccumulateFunctor *functor = new AccumulateFunctor();
    threads.push_back(
        std::thread(std::ref(*functor), i * step, (i + 1) * step));
    functors.push_back(functor);
  }

  for (std::thread &t : threads) {
    if (t.joinable()) {
      t.join();
    }
  }

  int64_t total = 0;
  for (auto pf : functors) {
    total += pf->_sum;
  }
  std::cout << "total: " << total << std::endl;

  return 0;
}