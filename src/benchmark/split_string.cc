/**
 * Benchmark code for comparison of inserting inside a vector vs list
 * Run:
 *        bazel run NAME_OF_TARGET -c opt -- --benchmark_format=csv | \
 *        tee output/NAME_OF_TARGET.csv
 *        python3 plot.py NAME_OF_TARGET.csv
 */
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

#include "benchmark/benchmark.h"
#include "src/lib/utility.h"

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
  std::string str(
      "James,Mary,John,Patricia,Robert,Linda,Michael,Barbara,"
      "William,Elizabeth,David,Jennifer,Richard,Maria,Charles,Susan,"
      "Joseph,Margaret,Thomas,Dorothy");

  for (auto _ : state) {
    auto v = SplitStackOverflow(str);
  }
}

//-----------------------------------------------------
// Benchmark function
static void BM_SplitSanjay(benchmark::State& state) {
  // Perform setup here
  std::string str(
      "James,Mary,John,Patricia,Robert,Linda,Michael,Barbara,"
      "William,Elizabeth,David,Jennifer,Richard,Maria,Charles,Susan,"
      "Joseph,Margaret,Thomas,Dorothy");

  for (auto _ : state) {
    auto v = SplitSanjay(str);
  }
}
//-----------------------------------------------------
// Register the function as a benchmark
BENCHMARK(BM_SplitStackOverflow)->RangeMultiplier(2)->Range(1 << 10, 1 << 16);;
BENCHMARK(BM_SplitSanjay)->RangeMultiplier(2)->Range(1 << 10, 1 << 16);;

// Run the benchmark
BENCHMARK_MAIN();
