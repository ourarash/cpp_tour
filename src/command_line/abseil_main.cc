#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/flags/usage.h"

ABSL_FLAG(std::string, input, "input.txt", "input file name");
ABSL_FLAG(std::string, from, "german", "from language");
ABSL_FLAG(int, accuracy, 1, "accuracy of translation");
ABSL_FLAG(bool, overwrite, false, "whether to overwrite the output files");

int main(int argc, char** argv) {
  absl::SetProgramUsageMessage("This program translates an input file.");
  absl::ParseCommandLine(argc, argv);

  if (argc < 5) {
    std::cout << "Error: not enough input parameters provided." << std::endl;
    std::cout << absl::ProgramUsageMessage() << std::endl;
    return -1;
  }

  std::string input = absl::GetFlag(FLAGS_input);
  std::string from = absl::GetFlag(FLAGS_from);
  int accuracy = absl::GetFlag(FLAGS_accuracy);
  bool overwrite = absl::GetFlag(FLAGS_overwrite);

  std::cout << "input: " << input << std::endl;
  std::cout << "from: " << from << std::endl;
  std::cout << "accuracy: " << accuracy << std::endl;
  std::cout << "overwrite: " << std::boolalpha << overwrite << std::endl;

  return 0;
}