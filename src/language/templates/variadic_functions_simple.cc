#include <iostream>
#include <sstream>
#include <string>
#include <vector>
//-----------------------------------------------------
enum LogType { INFO, DEBUG, WARNING };
// With no arguments
void MYLOG() { std::cout << std::endl; }

// With a single argument so that we don't print ',' at the end.
template <typename T>
void MYLOG(T arg1) {
  std::cout << arg1 << std::endl;
}

// With variable arguments. Separate with ','.
template <typename T, typename... Args>
void MYLOG(T arg1, Args... args) {
  std::cout << arg1 << ", ";
  MYLOG(args...);
}

// Specialized case with the first argument being LogType.
template <typename... Args>
void MYLOG(LogType arg1, Args... args) {
  switch (arg1) {
    case LogType::DEBUG:
      std::cout << "DEBUG:( ";
      break;
    case LogType::INFO:
      std::cout << "INFO:( ";
      break;
    case LogType::WARNING:
      std::cout << "WARNING:( ";
      break;
  }
  std::cout << std::string(__FILE__) + std::string(":") +
                   std::to_string(__LINE__) + std::string(" ): ");
  MYLOG(args...);
}

//-----------------------------------------------------
int main(int argc, char const *argv[]) {
  int a = 1, b = 2, c = 3;
  std::string str("This is a test");
  MYLOG(a);
  MYLOG(LogType::WARNING, a);
  MYLOG(str);
  MYLOG(str, a, b, c);
  MYLOG(LogType::DEBUG, a, b, c);
  MYLOG(LogType::INFO, a, b, c);
  return 0;
}
