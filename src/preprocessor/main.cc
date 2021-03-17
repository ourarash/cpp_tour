#include <iostream>
#include <iostream>
#include <iostream>

#define DEBUG

#ifdef DEBUG
const bool debug = true;
#endif

// 1. From compiler -d
// 2. Define DEBUG

#undef DEBUG
#ifdef DEBUG
const bool debug2 = true;
#endif



#define TO_STRING(str) #str


// a -> int a_s = 5;
#define DECLARE_VAR(var) int var##_s = 5;

// DECLARE_SPECIAL_VAR(a) => 
        // int a;
        // bool a_ctrl;
        // float a_float;
#define DECLARE_SPECIAL_VAR(var) \
  int var;                       \
  bool var##_ctrl;               \
  float var##_float;

constexpr long factorial(long x) {
  if (x > 0) {
    return x * factorial(x - 1);
  } else {
    return 1;
  }
}

#define _WINDOWS 1
#define SIZE 100

#include "hazf.h"  // cop7y paste everything form hazf.h here
#include "hazf.h"


#define TO_STRING(str) #str

int main() {
  int a[SIZE];

  std::cout << "TO_STRING(int): " << TO_STRING(int) << std::endl;

  // std::cout << TO_STRING(10 + 5) << std::endl;

  // #define DECLARE_VAR(var) int var##_s = 5;
  DECLARE_VAR(hello);

  std::cout << "hello_s: " << hello_s << std::endl;

  // std::cout << "factorial(10): " << factorial(100) << std::endl;

  // std::cout << "hello_s: " << hello_s << std::endl;
  return 0;
}
