/**
 * Benchmark code for comparison of copmarison of passing c style string to
 * string_view
 * Run:
 *        bazel run string_view_last -c opt -- --benchmark_format=csv | tee
 * output/string_view_last.csv
 *
 *        python3 plot.py output/string_view_last.csv
 */
#include <iostream>
#include <map>
#include <string>
#include <string_view>
#include <vector>

#include "benchmark/benchmark.h"
#include "src/lib/utility.h"
//-----------------------------------------------------
/**
 * Generates a random string of size n
 */
std::string GenerateRandomString(size_t n) {
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
char last(const std::string& str) {
  if (!str.empty()) {
    return str[str.size() - 1];
  } else {
    return ' ';
  }
}
char last_string_view(std::string_view sv) {
  if (!sv.empty()) {
    return sv[sv.size() - 1];
  } else {
    return ' ';
  }
}
//-----------------------------------------------------
static void BM_last(benchmark::State& state) {
  auto s = GenerateRandomString(state.range(0));
  char r;
  for (auto _ : state) {
    benchmark::DoNotOptimize(r = last(s.c_str()));
  }
}
//-----------------------------------------------------
static void BM_last_string_view(benchmark::State& state) {
  auto s = GenerateRandomString(state.range(0));
  char r;
  for (auto _ : state) {
    benchmark::DoNotOptimize(r = last_string_view(s.c_str()));
  }
}

static void BM_last_string_view_size(benchmark::State& state) {
  auto s = GenerateRandomString(state.range(0));
  auto size = s.size();
  char r;
  for (auto _ : state) {
    benchmark::DoNotOptimize(r = last_string_view({s.c_str(), size}));
  }
}


BENCHMARK(BM_last)->RangeMultiplier(2)->Range(1 << 15, 1 << 25);
BENCHMARK(BM_last_string_view)->RangeMultiplier(2)->Range(1 << 15, 1 << 25);
BENCHMARK(BM_last_string_view_size)
    ->RangeMultiplier(2)
    ->Range(1 << 15, 1 << 25);

// Run the benchmark
BENCHMARK_MAIN();
