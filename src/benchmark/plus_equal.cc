/**
 * Benchmark code for comparison of inserting inside a vector vs list
 * Run:
        NAME_OF_TARGET=plus_equal
        bazel run src/benchmark/$NAME_OF_TARGET -c opt -- --benchmark_format=csv
 \ | tee run src/benchmark/output/$NAME_OF_TARGET.csv python3
 src/benchmark/plot.py src/benchmark/output/$NAME_OF_TARGET.csv
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
  float Z;

  Vector2(float x, float y) : X(x), Y(y) {}

  Vector2(const Vector2& rhs) {
    X = rhs.X;
    Y = rhs.Y;
    // Adding delay to copy constructor
    for (int i = 0; i < 10000; i++) {
      Y += rand() / 100;
    }
  }

  Vector2& operator+=(const Vector2& rhs) {
    X += rhs.X;
    Y += rhs.Y;
    return *this;
  }

  Vector2 operator+(const Vector2& rhs) {
    Vector2 temp(*this);
    temp += rhs;
    return temp;
  }

  // Define prefix increment operator.
  Vector2 operator++() {
    X++;
    Y++;
    return *this;
  }

  // Define postfix increment operator.
  Vector2 operator++(int) {
    Vector2 orig = *this;
    ++(*this);  // Call prefix operator
    return orig;
  }
};

int main(int argc, char const* argv[]) {
  {
    Vector2 a, b;
    a = a + b;
    a += b;
  }
  {
    Vector2 a, b;
    b = a++;
    b = ++a;
  }


  for(it=...; ... ; it++){
      
  }

  for(it=...; ... ; ++it){
      
  }
  return 0;
}
