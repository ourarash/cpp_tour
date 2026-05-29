
#include <any>
#include <iostream>
#include <optional>
#include <string>
#include <variant>


// This function will try to convert a string to an integer and either --
// Return the integer if successful
// Return an unset optional if not successful
std::optional<int> TryGetInt(const std::string& s) {
  try {
    int result = std::stoi(s);
    return std::optional<int>(result);
  } catch (std::exception&) {
    // stoi failed so return an unset optional
    return std::optional<int>();
  }
}

void CoutOptional(const std::optional<int>& o) {
  if (o) {
    std::cout << o.value() << "\n";
  } else {
    std::cout << "Optional was unset!\n";
  }
}

int main() {
  // Try to convert two strings to int
  auto result1 = TryGetInt("10");
  CoutOptional(result1);
  auto result2 = TryGetInt("xyzw");
  CoutOptional(result2);

  {  // This variant can either contain an int or a string
    std::variant<int, std::string, float> var;

    // Set it to an int
    var = 20;
    // We can use get<type>(variant) to extract the type
    std::cout << "As int: " << std::get<int>(var) << "\n";

    // Set it to a string
    var = "Hello";
    std::cout << "As string: " << std::get<std::string>(var) << "\n";

    // If we try to access it as a string we have an exception
    try {
      int result = std::get<int>(var);
    } catch (std::bad_variant_access&) {
      std::cout << "Error, variant wasn't set to an int!\n";
    }
  }

  {
    std::variant<int, std::string> v = "abc";

    std::cout << "v.index = " << v.index() << '\n';

    v = 1;

    std::cout << "v.index = " << v.index() << '\n';
  }

  {  // Initialize an any to any type
    auto any1 = std::any(50);
    // To extract the value we have to use any_cast
    std::cout << "As int: " << std::any_cast<int>(any1) << '\n';

    // If it doesn't contain the type, any_cast throws an exception
    try {
      std::cout << "As string: " << std::any_cast<std::string>(any1) << '\n';
    } catch (std::bad_any_cast&) {
      std::cout << "Any cast failed :(" << std::endl;
    }
  }

  return 0;
}
