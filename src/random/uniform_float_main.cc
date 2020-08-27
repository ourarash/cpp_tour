#include <iostream>
#include <random>
#include <vector>

#include "src/lib/solution.h"

#include "absl/flags/flag.h"
#include "absl/time/time.h"

ABSL_FLAG(std::string, filename, "foo/bar/baz/", "output file dir");


int main(int argc, char** argv) {

  auto my_filename = absl::GetFlag(FLAGS_filename);


  // Pick a random value from [0, 10]
  auto seed = 1;

  std::mt19937 randGen(seed);
  std::uniform_real_distribution<> myDist(0, 10);

  for (size_t i = 0; i < 10; i++) {
    auto index1 = myDist(randGen);

    std::cout << "index1: " << index1 << std::endl;
  }

  return 0;  // End of a line
}