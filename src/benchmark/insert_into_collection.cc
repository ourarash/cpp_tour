/**
 * Benchmark code for comparison of inserting inside a vector vs list
 * Run:
         bazel run src/benchmark/insert_into_collection -c opt -- --benchmark_format=csv | \
         tee src/benchmark/output/insert_into_collection.csv
         python3 src/benchmark/plot.py src/benchmark/output/insert_into_collection.csv
 */
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "benchmark/benchmark.h"
#include "src/lib/utility.h"

void InsertIntoVector(int count) {
  srand(123456);  // Use a set seed

  std::vector<int> v;

  for (size_t i = 0; i < count; i++) {
    int number = rand() % 10000;
    auto iter = v.begin();
    auto end = v.end();
    while (iter != end) {
      if (*iter > number) {
        break;
      }
      ++iter;
    }
    v.insert(iter, number);
  }
}
//-----------------------------------------------------
void InsertIntoList(int count) {
  srand(123456);  // Use a set seed

  std::list<int> v;

  for (size_t i = 0; i < count; i++) {
    int number = rand() % 10000;
    auto iter = v.begin();
    auto end = v.end();
    while (iter != end) {
      if (*iter > number) {
        break;
      }
      ++iter;
    }
    v.insert(iter, number);
  }
}
//-----------------------------------------------------
static void BM_InsertIntoVector(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    InsertIntoVector(state.range(0));
  }
}
//-----------------------------------------------------
static void BM_InsertIntoList(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    // This code gets timed
    InsertIntoList(state.range(0));
  }
}
// Register the function as a benchmark
BENCHMARK(BM_InsertIntoVector)->RangeMultiplier(2)->Range(1 << 10, 1 << 16);
BENCHMARK(BM_InsertIntoList)->RangeMultiplier(2)->Range(1 << 10, 1 << 16);

// Run the benchmark
BENCHMARK_MAIN();
