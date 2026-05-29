#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "src/lib/utility.h"

void Translate(std::string_view input, std::string_view from, int accuracy,
               bool overwrite) {
  // Perform translation...
  std::cout << "input: " << input << std::endl;
  std::cout << "from: " << from << std::endl;
  std::cout << "accuracy: " << accuracy << std::endl;
  std::cout << "overwrite: " << std::boolalpha << overwrite << std::endl;
}

void PrintErrorMessage() {
  std::cout << "translate:" << std::endl;
  std::cout << "\tError: command line arguments were not correct." << std::endl;
  std::cout << "\tExample usage: translate my_file.txt japanese 2 true"
            << std::endl;
}

int main(int argc, char* argv[]) {
  if (argc < 5) {
    PrintErrorMessage();
    return -1;
  }

  try {
    std::string_view input = argv[1];
    std::string_view from = argv[2];
    int accuracy = std::stoi(argv[3]);
    bool overwrite;
    std::istringstream(argv[4]) >> std::boolalpha >> overwrite;

    Translate(input, from, accuracy, overwrite);

  } catch (const std::exception& e) {
    std::cout << "e: " << e.what() << std::endl;
    PrintErrorMessage();
    return -1;
  }
  return 0;
}
