/**
 * Benchmark code for comparison of inserting inside a vector vs list
 * Run:
 *        bazel run NAME_OF_TARGET -c opt -- --benchmark_format=csv | \
 *        tee output/NAME_OF_TARGET.csv
 *        python3 plot.py NAME_OF_TARGET.csv
 */
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <vector>

#include "benchmark/benchmark.h"
#include "src/lib/utility.h"

// std::string original, postfix;
// auto result = original + postfix;
std::string GrowByAppend(const std::string& original,
                         const std::string& postfix) {
  std::string result = original;
  return result.append(postfix);
}
//-----------------------------------------------------

std::string GrowByAppendReserve(const std::string& original,
                                const std::string& postfix) {
  std::string result;

  result.reserve(original.size() + postfix.size());
  result = original;
  return result.append(postfix);
}
//-----------------------------------------------------
std::string GrowByAdd(const std::string& original, const std::string& postfix) {
  std::string result = original;
  return result + postfix;
}
//-----------------------------------------------------
std::string GrowByPushBack(const std::string& original,
                           const std::string& postfix) {
  std::string result = original;
  for (const auto c : postfix) {
    result.push_back(c);
  }
  return result;
}
//-----------------------------------------------------
std::string GrowByStringStream(const std::string& original,
                               const std::string& postfix) {
  std::stringstream result;
  result << original << postfix;
  return result.str();
}

//-----------------------------------------------------
static void BM_GrowByAppend(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    state.PauseTiming();
    std::string original;
    std::string postfix;
    original.resize(state.range(0), 'a');
    postfix.resize(state.range(0), 'b');
    state.ResumeTiming();

    GrowByAppend(original, postfix);
  }
}
//-----------------------------------------------------
static void BM_GrowByAppendReserve(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    state.PauseTiming();
    std::string original;
    std::string postfix;
    original.resize(state.range(0), 'a');
    postfix.resize(state.range(0), 'b');
    state.ResumeTiming();
    GrowByAppendReserve(original, postfix);
  }
}
//-----------------------------------------------------
static void BM_GrowByAdd(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    state.PauseTiming();
    std::string original;
    std::string postfix;
    original.resize(state.range(0), 'a');
    postfix.resize(state.range(0), 'b');
    state.ResumeTiming();
    GrowByAdd(original, postfix);
  }
}
//-----------------------------------------------------
static void BM_GrowByPushBack(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {
    state.PauseTiming();
    std::string original;
    std::string postfix;
    original.resize(state.range(0), 'a');
    postfix.resize(state.range(0), 'b');
    state.ResumeTiming();
    GrowByPushBack(original, postfix);
  }
}
//-----------------------------------------------------
static void BM_GrowByStringStream(benchmark::State& state) {
  // Perform setup here
  for (auto _ : state) {

    state.PauseTiming();
    std::string original;
    std::string postfix;
    original.resize(state.range(0), 'a');
    postfix.resize(state.range(0), 'b');
    state.ResumeTiming();

    GrowByStringStream(original, postfix);
  }
}
//-----------------------------------------------------
// Register the function as a benchmark
BENCHMARK(BM_GrowByAppend)->RangeMultiplier(2)->Range(1 << 10, 1 << 16);
BENCHMARK(BM_GrowByAppendReserve)->RangeMultiplier(2)->Range(1 << 10, 1 << 16);
BENCHMARK(BM_GrowByAdd)->RangeMultiplier(2)->Range(1 << 10, 1 << 16);
// BENCHMARK(BM_GrowByPushBack)->RangeMultiplier(2)->Range(1 << 10, 1 << 16);
BENCHMARK(BM_GrowByStringStream)->RangeMultiplier(2)->Range(1 << 10, 1 << 16);

// Run the benchmark
BENCHMARK_MAIN();

