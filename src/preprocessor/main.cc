#include <iostream>
#define TO_STRING(str) #str

#define DECLARE_VAR(var) int var##_s = 5;


#define DECLARE_SPECIAL_VAR(var) int var; \
  bool var##_ctrl; \
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

int main() {

  int a[SIZE];

  // std::cout << TO_STRING(10 + 5) << std::endl;

  // #define DECLARE_VAR(var) int var##_s = 5;
  DECLARE_VAR(hello);
  
  std::cout << "hello_s: " << hello_s << std::endl;



  // std::cout << "factorial(10): " << factorial(100) << std::endl;

  // std::cout << "hello_s: " << hello_s << std::endl;
  return 0;
}
