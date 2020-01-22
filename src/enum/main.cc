#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
  // Enum type in C:
  enum ColorPallet1 { Red, Green, Blue };
  enum ColorPallet2 { Yellow, Orange, Red2};

  // Enum Class in C++
  // Declaration
  enum class ColorPalletClass1 { Red, Green, Blue };
  enum class ColorPalletClass2 { Yellow, Orange, Red };

  // Assignment
  ColorPalletClass1 col1 = ColorPalletClass1::Red;
  ColorPalletClass2 col2 = ColorPalletClass2::Red;

  return 0;
}