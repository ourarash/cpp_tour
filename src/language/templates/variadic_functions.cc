#include <iostream>
#include <sstream>
#include <string>
#include <vector>
//-----------------------------------------------------
// void debug() { std::cout << std::endl; }

// With a single argument.
template <typename T>
void debug(T arg1) {
  std::cout << arg1 << std::endl;
}

// With a single std::string argument.
void debug(std::string arg1) {
  std::cout << arg1 << std::endl;
}

// With variable arguments.
template <typename T, typename... Args>
void debug(T arg1, Args... args) {
  std::cout << arg1 << ", ";
  debug(args...);
}

// Specialized case with the first argument being std::string.
template <typename... Args>
void debug(std::string arg1, Args... args) {
  if (arg1.rfind("DEBUG", 0) == 0) {
    std::cout << arg1 << ": ";
  } else {
    std::cout << arg1 << ", ";
  }
  debug(args...);
}
//-----------------------------------------------------
// template <typename... Args>
// void my_debug(Args... args) {
//   debug(std::string("__start__"), args...);
// }
#define my_debug(...)                                                      \
  debug(std::string("DEBUG(") + std::string(__FILE__) + std::string(":") + \
            std::to_string(__LINE__) + std::string(")"),                   \
        __VA_ARGS__)

//-----------------------------------------------------
int main(int argc, char const *argv[]) {
  int a = 1, b = 2, c = 3;
  std::string str("This is a test");
  my_debug(a);
  my_debug(str);

  my_debug(str, a, b, c);
  my_debug(a, b, c);
  my_debug(c, b);

  return 0;
}
