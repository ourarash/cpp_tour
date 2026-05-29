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

class MyType {
 public:
  MyType() { std::cout << "constructor!" << std::endl; }

  void Print() { std::cout << "Print!" << std::endl; }
};

void VariableInsideLoop() {
  for (int i = 0; i < 100; i++) {
    MyType m;
    m.Print();
  }
}

void VariableOutsideLoop() {
  MyType m;
  for (int i = 0; i < 100; i++) {
    m.Print();
  }
}

int main(int argc, char const *argv[]) {
  VariableInsideLoop();
  // VariableOutsideLoop();
  return 0;
}
