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

struct Vector2 {
  float X;
  float Y;
  float* Z;

  Vector2(float x, float y) : X(x), Y(y) {}

  Vector2(const Vector2& rhs) {
    X = rhs.X;
    Y = rhs.Y;
    // Z = new float[10];
  }
  // Vector2 a, b;
  // a += b;
  Vector2& operator+=(const Vector2& rhs) {
    X += rhs.X;
    Y += rhs.Y;
    return *this;
  }

  // Vector2 a, b;
  // a = a + b;
  Vector2 operator+(const Vector2& rhs) {
    Vector2 temp(*this);
    temp += rhs;
    return temp;
  }
};

//-----------------------------------------------------
static void BM_Plus(benchmark::State& state) {
  // Perform setup here
  Vector2 v1(1, 2);
  Vector2 v2(3, 4);
  for (auto _ : state) {
    benchmark::DoNotOptimize(v1 = v1 + v2);
    benchmark::ClobberMemory();
  }
}
//-----------------------------------------------------
static void BM_PlusEqual(benchmark::State& state) {
  // Perform setup here
  Vector2 v1(1, 2);
  Vector2 v2(3, 4);
  for (auto _ : state) {
    benchmark::DoNotOptimize(v1 += v2);
    benchmark::ClobberMemory();
  }
}
//-----------------------------------------------------
// Register the function as a benchmark
BENCHMARK(BM_Plus);
BENCHMARK(BM_PlusEqual);

// Run the benchmark
BENCHMARK_MAIN();


vector<char> 