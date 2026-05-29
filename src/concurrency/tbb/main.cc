// #include <tbb/parallel_for.h>
// #include <tbb/parallel_for_each.h>

#include <iostream>
#include <vector>

bool isPrime(unsigned long n) {
  if (n <= 3) {
    return n > 1;
  } else if (n % 2 == 0 || n % 3 == 0) {
    return false;
  } else {
    for (unsigned long i = 5; i * i <= n; i += 6) {
      if (n % i == 0 || n % (i + 2) == 0) {
        return false;
      }
    }
    return true;
  }
}

struct Number {
  unsigned value;
  bool isPrime;
  Number(unsigned v) {
    value = v;
    isPrime = false;
  }
};

int main() {
  std::vector<Number> numbers;
  const unsigned long NUMBER_COUNT = 500000000;
  // Populate vector with numbers from file
  // ...

  for (unsigned long i = 0; i < NUMBER_COUNT; ++i) {
    numbers.push_back(rand() % 100 + 1);
  }

  {  // Start high frequency timer (custom class I created)
    auto start_time = std::chrono::high_resolution_clock::now();

    // Test each number (serial)
    for (auto& n : numbers) {
      n.isPrime = isPrime(n.value);
    }

    // Get time elapsed
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);

    std::cout << "Took " << elapsed.count() << " seconds" << std::endl;
  }

  // {
  //   tbb::parallel_for_each(numbers.begin(), numbers.end(),
  //                          [](Number& n) { n.isPrime = isPrime(n.value); });
  // }
  // // Test each number (parallel)
  // tbb::parallel_for_each(numbers.begin(), numbers.end(),
  //                        [](Number& n) { n.isPrime = isPrime(n.value); });

  return 0;  // End of a line
}