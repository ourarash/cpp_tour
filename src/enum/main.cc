#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
  int color = 0;  // Red
  int color2 = 1; // Green

  // Enum type in C:
  enum ColorPallet1 { Red, Green, Blue };
  enum ColorPallet2 { Yellow, Orange, Red };

  ColorPallet1 color3 = Red;

  // Enum Class in C++
  // Declaration
  enum class ColorPalletClass1 { Red, Green, Blue };
  enum class ColorPalletClass2 { Yellow, Orange, Red };

  // Assignment
  ColorPalletClass1 col1 = ColorPalletClass1::Red;
  ColorPalletClass2 col2 = ColorPalletClass2::Red;

  if (col1 == ColorPalletClass1::Red) {
    std::cout << "RED" << std::endl;
  } else if (col1 == ColorPalletClass1::Green) {
    std::cout << "Green" << std::endl;
  }

  std::cout << "color3: " << color3 << std::endl;

  return 0;
}