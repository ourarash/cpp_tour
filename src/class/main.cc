#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

class Point {
public:
  // Constructor
  Point(int i, int j) {
    i_ = i;
    j_ = j;
  }
  // Copy constructor
  Point(const Point &p2) {
    i_ = p2.GetI();
    j_ = p2.GetJ();
  }

  int GetI() const { return i_; };
  int GetJ() const { return j_; };
  void SetI(int i) { i_ = i; };
  void SetJ(int j) { j_ = j; };

private:
  int i_;
  int j_;
};

int main() {
  Point p1(1, 2); // Constructor is called
  Point p2 = p1;  // Copy constructor is called
}