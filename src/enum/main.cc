#include <iostream>
#include <string>
#include <vector>

// #include "src/lib/utility.h"

int main() {
  // Red =0, green=1, blue = 2
  int color = 0;   // Red
  int color2 = 1;  // Green

  // A: 0, B:1, C: 2, ...
  int x = 1;

  // Enum type in C:
  enum ColorPallet1 { Red, Green, Blue };
  enum ColorPallet2 { Yellow, Orange, Red };

  ColorPallet1 myColor1 = Red;

  // Red // Ambiguous !!

  // Enum Class in C++
  // Declaration
  enum class ColorPalletClass1 { Red, Green, Blue };
  enum class ColorPalletClass2 { Yellow, Orange, Red };
  enum class Grade { A, B, C, D, E, F };

  // Assignment
  ColorPalletClass1 col1 = ColorPalletClass1::Red;
  ColorPalletClass2 col2 = ColorPalletClass2::Red;

  Grade myGrade = Grade::A;
  myGrade = ColorPalletClass1::Red;

  // col2 = ColorPalletClass1::Red;

  if (col1 == ColorPalletClass1::Red) {
    std::cout << "RED" << std::endl;
  } else if (col1 == ColorPalletClass1::Green) {
    std::cout << "Green" << std::endl;
  }

  // std::cout << "color3: " << color3 << std::endl;

  return 0;

  // ColorPalletClass1 option;
  // if (option == Red) {
  // } else if (option == Brown) {
  // }

  // 1. Readability
  // 2. Type checking

  // if (trafficLight = Red)
  //   else if (trafficLight = Green) else if (trafficLight = Yellow)
}