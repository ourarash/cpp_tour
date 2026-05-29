/**
 * Benchmark code for comparison of inserting inside a vector vs list
 * Run:
        NAME_OF_TARGET=search_collection
        bazel run src/benchmark/$NAME_OF_TARGET -c opt -- --benchmark_format=csv | \
         tee run src/benchmark/output/$NAME_OF_TARGET.csv
         python3  src/benchmark/plot.py src/benchmark/output/$NAME_OF_TARGET.csv
 */
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "benchmark/benchmark.h"
#include "src/lib/utility.h"

bool SearchInVector(std::vector<int>& v, int item) {
  for (const auto& e : v) {
    if (e == item) {
      return true;
    }
  }
  return false;
}
//-----------------------------------------------------
bool SearchInList(std::list<int>& v, int item) {
  for (const auto& e : v) {
    if (e == item) {
      return true;
    }
  }
  return false;
}
//-----------------------------------------------------
static void BM_SearchInVector(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    state.PauseTiming();
    std::vector<int> v(state.range(0), 1);
    std::generate(v.begin(), v.end(), []() { return 1; });
    state.ResumeTiming();
    SearchInVector(v, 2);
  }
}
//-----------------------------------------------------
static void BM_SearchInList(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    state.PauseTiming();
    std::list<int> v(state.range(0), 1);
    state.ResumeTiming();
    SearchInList(v, 2);
  }
}
// Register the function as a benchmark
BENCHMARK(BM_SearchInVector)->RangeMultiplier(2)->Range(1 << 10, 1 << 16);
BENCHMARK(BM_SearchInList)->RangeMultiplier(2)->Range(1 << 10, 1 << 16);

// Run the benchmark
BENCHMARK_MAIN();
