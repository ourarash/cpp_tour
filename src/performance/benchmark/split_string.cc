/**
 * Benchmark code for comparison of inserting inside a vector vs list
 * Run:
  NAME_OF_TARGET=split_string
  bazel run src/benchmark/$NAME_OF_TARGET -c opt -- --benchmark_format=csv | \
  tee run src/benchmark/output/$NAME_OF_TARGET.csv
  python3  src/benchmark/plot.py src/benchmark/output/$NAME_OF_TARGET.csv
 */
#include <iostream>
#include <list>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "benchmark/benchmark.h"
#include "src/lib/utility.h"

/**
 * Generates a random string of size len
 */
auto GenerateRandomString(std::size_t n) -> std::string {
  static constexpr auto chars =
      "0123456789"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      "abcdefghijklmnopqrstuvwxyz";

  auto result = std::string(n, '\0');
  std::generate_n(std::begin(result), n,
                  [&]() { return chars[rand() % std::strlen(chars)]; });
  return result;
}
//-----------------------------------------------------
/**
 * Generates a string that is the result of merging [n]
 * random string concatenated by ','
 */
std::string GenerateRandomMergedString(std::size_t n) {
  const int max_length = 10;
  const int min_length = 2;
  srand(123456);  // Use a set seed

  std::string result;
  for (std::size_t i = 0; i < n; i++) {
    result +=
        GenerateRandomString((rand() % (max_length - min_length)) + min_length);
    if (i < n - 1) {
      result += ",";
    }
  }
  return result;
}
//-----------------------------------------------------
std::vector<std::string> SplitStackOverflow(std::string input) {
  std::stringstream ss(input);
  std::vector<std::string> result;
  while (ss.good()) {
    std::string substr;
    std::getline(ss, substr, ',');
    result.push_back(substr);
  }
  return result;
}
//-----------------------------------------------------
std::vector<std::string> SplitSanjay(const std::string& str) {
  const char delim = ',';
  std::vector<std::string> retVal;

  size_t start = 0;
  size_t delimLoc = str.find_first_of(delim, start);
  while (delimLoc != std::string::npos) {
    retVal.emplace_back(str.substr(start, delimLoc - start));
    start = delimLoc + 1;
    delimLoc = str.find_first_of(delim, start);
  }

  retVal.emplace_back(str.substr(start));
  return retVal;
}

//-----------------------------------------------------
// Benchmark function
static void BM_SplitStackOverflow(benchmark::State& state) {
  // Perform setup here
  // Pass state.range(0) to GenerateRandomMergedString as n
  std::string str = GenerateRandomMergedString(state.range(0));

  for (auto _ : state) {
    auto v = SplitStackOverflow(str);
  }
}

//-----------------------------------------------------
// Benchmark function
static void BM_SplitSanjay(benchmark::State& state) {
  // Perform setup here
  // Pass state.range(0) to GenerateRandomMergedString as n
  std::string str = GenerateRandomMergedString(state.range(0));

  for (auto _ : state) {
    auto v = SplitSanjay(str);
  }
}
//-----------------------------------------------------
// Register the function as a benchmark
BENCHMARK(BM_SplitStackOverflow)->RangeMultiplier(2)->Range(1 << 10, 1 << 16);
;
BENCHMARK(BM_SplitSanjay)->RangeMultiplier(2)->Range(1 << 10, 1 << 16);
;

// Run the benchmark
BENCHMARK_MAIN();
