/**
 * Benchmark code for comparison of inserting inside a vector vs list
 * Run:
        NAME_OF_TARGET=push_back_collection
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

template <class T>
std::vector<T> PushBackIntoVector(int count, T e) {
  std::vector<T> v;

  for (size_t i = 0; i < count; i++) {
    T new_object;
    v.push_back(new_object);
  }
  return v;
}
//-----------------------------------------------------
template <class T>
std::list<T> PushBackIntoList(int count, T e) {
  std::list<T> v;
  for (size_t i = 0; i < count; i++) {
    T new_object;
    v.push_back(new_object);
  }
  return v;
}
//-----------------------------------------------------
static void BM_PushBackIntoVectorInt(benchmark::State& state) {
  // Perform setup here
  int i = 0;

  for (auto _ : state) {
    // This code gets timed
    auto v = PushBackIntoVector(state.range(0), i);
  }
}
//-----------------------------------------------------
static void BM_PushBackIntoListInt(benchmark::State& state) {
  // Perform setup here
  int i = 0;

  for (auto _ : state) {
    // This code gets timed
    auto v = PushBackIntoList(state.range(0), i);
  }
}
//-----------------------------------------------------
static void BM_PushBackIntoVectorStruct(benchmark::State& state) {
  // Perform setup here
  struct {
    int a[1255];
  } i;

  for (auto _ : state) {
    // This code gets timed
    auto v = PushBackIntoVector(state.range(0), i);
  }
}
//-----------------------------------------------------
static void BM_PushBackIntoListStruct(benchmark::State& state) {
  // Perform setup here

  struct {
    int a[1255];
  } i;

  for (auto _ : state) {
    // This code gets timed
    auto v = PushBackIntoList(state.range(0), i);
  }
}
//-----------------------------------------------------
// Register the function as a benchmark
BENCHMARK(BM_PushBackIntoVectorInt)
    ->RangeMultiplier(2)
    ->Range(1 << 10, 1 << 16);
BENCHMARK(BM_PushBackIntoListInt)->RangeMultiplier(2)->Range(1 << 10, 1 << 16);

BENCHMARK(BM_PushBackIntoVectorStruct)
    ->RangeMultiplier(2)
    ->Range(1 << 10, 1 << 16);
BENCHMARK(BM_PushBackIntoListStruct)
    ->RangeMultiplier(2)
    ->Range(1 << 10, 1 << 16);

// Run the benchmark
BENCHMARK_MAIN();
