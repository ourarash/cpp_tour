#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/flags/usage.h"

enum class Language { 
  kJapanese, kGerman, kFrench 
};

// AbslParseFlag converts from a string to Language.
// Must be in same namespace as Language.

// Parses an Language from the command line flag value `text`.
// Returns `true` and sets `*language` on success.
// Returns `false` and sets `*error` on failure.
bool AbslParseFlag(absl::string_view text, Language* language,
                   std::string* error) {
  if (text == "japanese") {
    *language = Language::kJapanese;
    return true;
  }
  if (text == "german") {
    *language = Language::kGerman;
    return true;
  }

  if (text == "french") {
    *language = Language::kFrench;
    return true;
  }
  *error = std::string("'" + std::string(text) + "'" +
                       " language is not supported.");
  return false;
}

// AbslUnparseFlag converts from an Language to a string.
// Must be in same namespace as Language.

// Returns a textual flag value corresponding to the Language `language`.
std::string AbslUnparseFlag(Language language) {
  switch (language) {
    case Language::kGerman:
      return "german";
    case Language::kJapanese:
      return "japanese";
    case Language::kFrench:
      return "french";
    default:
      return std::to_string(static_cast<int>(language));
  }
}

ABSL_FLAG(std::string, input, "input.txt", "input file name");
ABSL_FLAG(Language, from, Language::kGerman, "from language");
ABSL_FLAG(int, accuracy, 1, "accuracy of translation");
ABSL_FLAG(bool, overwrite, false, "whether to overwrite the output files");

void Translate(std::string_view input, Language from, int accuracy,
               bool overwrite) {
  // Perform translation...
  std::cout << "input: " << input << std::endl;
  std::cout << "from: " << static_cast<int>(from) << std::endl;
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
      "Usage example: --input=my_file.txt --from=<japanese|german|french> "
      "--accuracy=2 "
      "--overwrite=true");
  absl::ParseCommandLine(argc, argv);

  if (argc < 5) {
    PrintErrorMessage();
    return -1;
  }

  std::string input = absl::GetFlag(FLAGS_input);
  Language from = absl::GetFlag(FLAGS_from);
  int accuracy = absl::GetFlag(FLAGS_accuracy);
  bool overwrite = absl::GetFlag(FLAGS_overwrite);

  Translate(input, from, accuracy, overwrite);

  return 0;
}