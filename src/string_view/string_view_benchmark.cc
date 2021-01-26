/**
 * Benchmark code for comparison of copmarison of passing c style string to
 * string_view
 * Run:
 *        bazel run string_view_benchmark -c opt -- --benchmark_format=csv | \
 *        tee output/string_view_benchmark.csv
 *        python3 plot.py output/string_view_benchmark.csv
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
int count_matches_string(const std::string& str, char ch) {
  int count = 0;
  for (auto c : str) {
    if (c == ch) {
      count++;
    }
  }
  return count;
}
//-----------------------------------------------------
int count_matches_string_view(std::string_view str, char ch) {
  int count = 0;
  for (auto c : str) {
    if (c == ch) {
      count++;
    }
  }
  return count;
}
//-----------------------------------------------------
static void BM_count_matches_string(benchmark::State& state) {
  auto s = GenerateRandomString(state.range(0));
  const char* c_str = s.c_str();
  for (auto _ : state) {
    benchmark::DoNotOptimize(count_matches_string(c_str, 'c'));
  }
}
//-----------------------------------------------------
static void BM_count_matches_string_view(benchmark::State& state) {
  auto s = GenerateRandomString(state.range(0));
  char c[] = "This is a test.";
  const char* c_str = s.c_str();
  for (auto _ : state) {
    benchmark::DoNotOptimize(count_matches_string_view(c_str, 'c'));
  }
}



BENCHMARK(BM_count_matches_string)->Arg(1 << 30);
BENCHMARK(BM_count_matches_string_view)->Arg(1 << 30);

// BENCHMARK(BM_count_matches_string)->RangeMultiplier(2)->Range(1 << 10, 1 <<
// 30); BENCHMARK(BM_count_matches_string_view)
//     ->RangeMultiplier(2)
//     ->Range(1 << 10, 1 << 30);

// Run the benchmark
BENCHMARK_MAIN();
