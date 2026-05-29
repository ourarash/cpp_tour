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

  std::cout << absl::ProgramUsageMessage() << std::endl;
}

int main(int argc, char* argv[]) {
  absl::SetProgramUsageMessage(
      "Usage example: --input=my_file.txt --from=Japanese --accuracy=2 "
      "--overwrite=true");
  absl::ParseCommandLine(argc, argv);

  if (argc < 5) {
    PrintErrorMessage();
    return -1;
  }

  std::string input = absl::GetFlag(FLAGS_input);
  std::string from = absl::GetFlag(FLAGS_from);
  int accuracy = absl::GetFlag(FLAGS_accuracy);
  bool overwrite = absl::GetFlag(FLAGS_overwrite);

  Translate(input, from, accuracy, overwrite);

  return 0;
}