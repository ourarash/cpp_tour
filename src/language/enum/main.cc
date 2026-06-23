#include <iostream>
#include <string>
#include <vector>

// #include "src/lib/utility.h"
#define RED 0
#define GREEN 1

int main() {
  // Red =0, green=1, blue = 2
  int color = 0;   // Red
  int color2 = 1;  // Green

  // Letter grade: A: 4, B: 3, C: 2, D: 1 ...
  int x = 1; // --> color green or grade?

  // 100000 lines later...
  if (color == RED) {
   
  } else if (color == 10) {
   
  }

  // Enum type in C:
  enum ColorPallet1 { Red, Green, Blue };
  enum ColorPallet2 { Yellow, Orange, Red };

  ColorPallet1 myColor1 = Red;

  // Red // Ambiguous !!

  // Enum Class in C++
  // Declaration
  enum class TrafficLight { Red, Green, Blue };
  enum class WallColor { Yellow, Orange, Red };
  enum class Grade { A, B, C, D, E, F };

  // Assignment
  TrafficLight col1 = TrafficLight::Red;
  WallColor col2 = WallColor::Red;

  // col1 = col2;
  // col1 = 0 ; // Compile error

  Grade myGrade = Grade::A;
  myGrade = TrafficLight::Red;

  // col2 = TrafficLight::Red;

  if (col1 == TrafficLight::Red) {
    std::cout << "RED" << std::endl;
  } else if (col1 == TrafficLight::Green) {
    std::cout << "Green" << std::endl;
  }

  // std::cout << "color3: " << color3 << std::endl;

  return 0;

  // TrafficLight option;
  // if (option == Red) {
  // } else if (option == Brown) {
  // }

  // 1. Readability
  // 2. Type checking

  // if (trafficLight = Red)
  //   else if (trafficLight = Green) else if (trafficLight = Yellow)
}