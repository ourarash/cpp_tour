/**
 * Benchmark code for comparison of inserting inside a vector vs list
 * Run:
 *        bazel run NAME_OF_TARGET -c opt -- --benchmark_format=csv | \
 *        tee output/NAME_OF_TARGET.csv
 *        python3 plot.py NAME_OF_TARGET.csv
 */
#include <iostream>
#include <list>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "benchmark/benchmark.h"
#include "src/lib/utility.h"

/**
 * Generates a random string of size len
 */
auto GenerateRandomString(std::size_t n) -> std::string {
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
/**
 * Generates a string that is the result of merging [n]
 * random string concatenated by ','
 */
std::string GenerateRandomMergedString(std::size_t n) {
  const int max_length = 10;
  const int min_length = 2;
  srand(123456);  // Use a set seed

  std::string result;
  for (std::size_t i = 0; i < n; i++) {
    result +=
        GenerateRandomString((rand() % (max_length - min_length)) + min_length);
    if (i < n - 1) {
      result += ",";
    }
  }
  return result;
}
//-----------------------------------------------------
std::vector<std::string> SplitStackOverflow(const std::string &str) {
  std::stringstream ss(str);
  std::vector<std::string> result;
  while (ss.good()) {
    std::string substr;
    std::getline(ss, substr, ',');
    result.push_back(substr);
  }
  return result;
}
//-----------------------------------------------------
std::vector<std::string> SplitSanjay(const std::string &str) {
  const char delim = ',';
  std::vector<std::string> retVal;

  size_t start = 0;
  size_t delimLoc = str.find_first_of(delim, start);
  while (delimLoc != std::string::npos) {
    retVal.emplace_back(str.substr(start, delimLoc - start));
    start = delimLoc + 1;
    delimLoc = str.find_first_of(delim, start);
  }

  retVal.emplace_back(str.substr(start));
  return retVal;
}



int main() {
  std::string str = GenerateRandomMergedString(100000);
  auto v1 = SplitSanjay(str);
  auto v2 = SplitStackOverflow(str);
  std::cout << "v1[0]: " << v1[0] << std::endl;
  std::cout << "v2[0]: " << v2[0] << std::endl;
  std::cout << "v1.size(): " << v1.size() << std::endl;
  std::cout << "v2.size(): " << v2.size() << std::endl;

  return 0;
}
