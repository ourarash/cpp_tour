#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

class Point {
public:
  Point() {
    i_ = 0;
    j_ = 0;
    std::cout << "***NO PARAMETERIZED constructor." << std::endl;
  }

  // Constructor
  Point(int i, int j) {
    std::cout << "**PARAMETERIZED constructor." << std::endl;
    i_ = i;
    j_ = j;
  }

  Point(int i) : Point(i, 0) {}

  // Copy constructor
  Point(const Point &p2) {
    std::cout << "COPY constructor." << std::endl;

    i_ = p2.GetI();
    j_ = p2.GetJ();
  }

  ~Point() { std::cout << "DESTRUCTOR." << std::endl; }

  int GetI() const { return i_; };
  int GetJ() const { return j_; };
  void SetI(int i) { i_ = i; };
  void SetJ(int j) { j_ = j; };

private:
  int i_;
  int j_;
};

std::ostream &operator<<(std::ostream &os, const Point &m) {
  return os << "( " << m.GetI() << ", " << m.GetJ() << " )";
}

int main() {
  Point p1; // No parameterized constructor
  std::cout << "p1: " << p1 << std::endl;

  Point p2(1, 2); // Parameterized constructor is called
  Point p3 = p2;  // Copy constructor is called

}