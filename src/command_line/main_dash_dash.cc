#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "src/lib/utility.h"

void PrintErrorMessage() {
  std::cout << "Error: command line arguments were not correct." << std::endl;
  std::cout << "Example usage: translate my_file.txt japanese 2 true"
            << std::endl;
}

int main(int argc, char** argv) {s
  if (argc < 5) {
    PrintErrorMessage();
    return -1;
  }

  std::string input;
  std::string from;
  int accuracy;
  bool overwrite;

  // Regular expression matching --parameter=value.
  // Example: --input=my_file.txt
  std::regex pattern("--(.*)=(.*)");

  // Iterate each element of argc
  for (size_t i = 1; i < argc; i++) {
    std::string p = argv[i];
    std::smatch sm;
    if (std::regex_match(p, sm, pattern)) {
      auto it = sm.begin();
      it++;

      if ((*it) == "input") {
        it++;
        input = *it;
        continue;
      }

      if ((*it) == "from") {
        it++;
        from = *it;
        continue;
      }

      if ((*it) == "accuracy") {
        it++;
        accuracy = std::stoi(*it);
        continue;
      }

      if ((*it) == "overwrite") {
        it++;
        std::istringstream((*it)) >> std::boolalpha >> overwrite;
        continue;
      }
      PrintErrorMessage();

    } else {
      PrintErrorMessage();
    }
  }

  std::cout << "input: " << input << std::endl;
  std::cout << "from: " << from << std::endl;
  std::cout << "accuracy: " << accuracy << std::endl;
  std::cout << "overwrite: " << std::boolalpha << overwrite << std::endl;

  return 0;
}
