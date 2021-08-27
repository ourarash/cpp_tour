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

int main(int argc, char const *argv[]) {
  {
    std::vector<int> vec1;
    std::vector<std::vector<int>> vec2;
    std::vector<std::vector<int>> vec3;

    vec1.push_back(1 << 20);

    {
      vec2.push_back(1 << 20);  // Doesn't compile
      // constructs a vector of over a million elements!
      vec2.emplace_back(1 << 20);
    }
  }
  {
    std::vector<std::string> my_vec;
    my_vec.push_back("foo");     // This is OK, so...
    my_vec.emplace_back("foo");  // This is also OK, and has the same result
  }

  {
    // declaring priority queue
    std::vector<std::pair<char, int>> vect;

    // using emplace() to insert pair in-place
    vect.emplace_back('a', 24);

    // Below line would not compile
    // vect.push_back('b', 25);

    // using push_back() to insert
    vect.push_back(std::make_pair('b', 25));

    // printing the vector
    for (int i = 0; i < vect.size(); i++)
      std::cout << vect[i].first << " " << vect[i].second << std::endl;
  }

  return 0;
}
