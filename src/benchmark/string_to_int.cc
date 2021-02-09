/**
 * Benchmark code for comparison of inserting inside a vector vs list
 * Run:
 
        NAME_OF_TARGET=string_to_int
        bazel run src/benchmark/$NAME_OF_TARGET -c opt -- --benchmark_format=csv \
        | tee run src/benchmark/output/$NAME_OF_TARGET.csv
        python3 src/benchmark/plot.py src/benchmark/output/$NAME_OF_TARGET.csv
 */
#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <vector>

#include "benchmark/benchmark.h"
#include "src/lib/utility.h"

std::string StringToIntByToString(const int n) { return std::to_string(n); }
//-----------------------------------------------------
std::string StringToIntByStringStream(const int n) {
  std::stringstream result;
  result << n;
  return result.str();
}
//-----------------------------------------------------
// Benchmark function for StringToIntByToString
static void BM_StringToIntByToString(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    StringToIntByToString(INT_MAX);
  }
}
//-----------------------------------------------------
// Benchmark function for StringToIntByStringStream
static void BM_StringToIntByStringStream(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    StringToIntByStringStream(INT_MAX);
  }
}
//-----------------------------------------------------
// Register the function as a benchmark
BENCHMARK(BM_StringToIntByToString);
BENCHMARK(BM_StringToIntByStringStream);

// Run the benchmark
BENCHMARK_MAIN();
