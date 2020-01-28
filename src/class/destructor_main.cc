#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

class Point {
public:
  Point() {
    i_ = 5;
    j_ = 5;
    std::cout << "NO PARAMETERIZED constructor." << std::endl;
  }

  // Constructor
  Point(int i, int j) {
    std::cout << "PARAMETERIZED constructor." << std::endl;
    std::cout << "i: " << i << ", j: " << j << std::endl;
    i_ = i;
    j_ = j;
  }
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
  {
    Point p1; // No parameterized constructor}
  }
  std::cout << "Destructor is already called!" << std::endl;

  // dynamic
  Point *p2 = new Point(5,4);
  Point *p4 = new Point(15,44);

  // Oh Oh! Don't forget to delete!
  delete p2;
  delete p4;
}