/**
 * Benchmark code for comparison of copmarison of passing c style string to
 * string_view
 * Run:
 *        bazel run string_view_remove_prefix_benchmark -c opt -- --benchmark_format=csv | tee output/string_view_remove_prefix_benchmark.csv
 *        python3 plot.py output/string_view_remove_prefix_benchmark.csv
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
std::string GenerateRandomString(std::size_t n) {
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
std::string remove_prefix(const std::string& str) { return str.substr(1); }
std::string_view remove_prefix_string_view(std::string_view str) {
  str.remove_prefix(1);
  return str;
}
//-----------------------------------------------------
static void BM_remove_prefix(benchmark::State& state) {
  auto s = GenerateRandomString(state.range(0));

  for (auto _ : state) {
    benchmark::DoNotOptimize(remove_prefix(s));
  }
}
//-----------------------------------------------------
static void BM_remove_prefix_string_view(benchmark::State& state) {
  auto s = GenerateRandomString(state.range(0));

  for (auto _ : state) {
    benchmark::DoNotOptimize(remove_prefix_string_view(s));
  }
}

// BENCHMARK(BM_remove_prefix)->Arg(1 << 20);
// BENCHMARK(BM_remove_prefix_string_view)->Arg(1 << 20);
BENCHMARK(BM_remove_prefix)->RangeMultiplier(2)->Range(1 << 10, 1 << 30);
BENCHMARK(BM_remove_prefix_string_view)
    ->RangeMultiplier(2)
    ->Range(1 << 10, 1 << 30);

// Run the benchmark
BENCHMARK_MAIN();
