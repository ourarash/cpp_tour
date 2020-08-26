#include <iostream>
#include <string>
#include <vector>

#include "src/lib/utility.h"

int main() {
  // c style casting and increments
  {
    char c = 10;               // 1 byte
    char *char_p = &c;         // 4 bytes

    int *int_p = (int *)(&c);  // 4 bytes

    *int_p = 12;               //⚡☠️ Dangerous!

    char_p++;
    int_p++;
    std::cout << "char_p: " << (long)char_p << std::endl;
    std::cout << "int_p: " << (long)int_p << std::endl;

    // int *int_p_sc = static_cast<int *>(&c);  // compile-time error

    int *int_p_rp = reinterpret_cast<int *>(&c);
  }
}