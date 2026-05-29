#include <iostream>

// Works for T = any type but std::string, double
template <typename T>
T Max(T a, T b) {
  return ((a > b) ? a : b);
}

// Works for T =std::string
template <>
std::string Max<std::string>(std::string a, std::string b) {
  // Code specific for this case
  return ((a < b) ? a : b);
}

template <>
double Max<double>(double a, double b) {
  // Code specific for this case
  return 0.0;
}

int main() {
  // Type not specified, compiler attempts substitution
  {
    auto int_max = Max(1, 2);
    std::cout << "int_max: " << int_max << std::endl;
  }
  // Type not specified, compiler attempts substitution

  {
    auto char_max = Max('a', 'b');
    std::cout << "char_max: " << char_max << std::endl;
  }
  // Type specified (optional)
  {
    auto char_max = Max<char>('a', 'b');
    std::cout << "char_max: " << char_max << std::endl;
  }

  // With a string (specific template)
  {
    auto string_max = Max(std::string("a"), std::string("b"));
    std::cout << "string_max: " << string_max << std::endl;
  }

  return 0;
}



// movi tx,110  ====> ((string) "tx", (int) 110)  ---> std::get<0>(my_tuple)
// movi ty,105