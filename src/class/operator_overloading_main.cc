
#include "src/lib/utility.h"
#include <iostream>
#include <string>
#include <vector>

// Operator overloading
class Point {
public:
  // Constructor
  Point() {
    i_ = 0;
    j_ = 0;
  }

  Point(int i, int j) {
    i_ = i;
    j_ = j;
  }
  // Copy constructor
  Point(const Point &p2) {
    i_ = p2.GetI();
    j_ = p2.GetJ();
  }

  Point operator+(const Point &rhs) {
    Point res;
    res.SetI(i_ + rhs.GetI());
    res.SetJ(j_ + rhs.GetJ());
    return res;
  }

  // Prefix overload
  // ++p;
  Point operator++() {
    i_++;
    j_++;
    return *this;
  }

  // Postfix overload
  // p++;
  Point operator++(int) {
    Point temp = *this;
    i_++;
    j_++;
    return temp;
  }

  int GetI() const { return i_; };
  int GetJ() const { return j_; };
  void SetI(int i) { i_ = i; };
  void SetJ(int j) { j_ = j; };
  friend std::istream &operator>>(std::istream &is, Point &p);

private:
  int i_;
  int j_;
};

std::ostream &operator<<(std::ostream &os, const Point &p) {
  return os << "( " << p.GetI() << ", " << p.GetJ() << " )";
}

std::istream &operator>>(std::istream &is, Point &p) {
  std::cout << "Enter i ";
  is >> p.i_;
  std::cout << "Enter j ";
  is >> p.j_;
  return is;
}

int main() {
  // OPerator overloading
  Point p1(1, 2);
  Point p2(10, 20);
  Point p3 = p1 + p2;
  std::cout << "p3: " << p3 << std::endl;

  ++p1;
  std::cout << "p1: " << p1 << std::endl;

  p1++;
  std::cout << "p1: " << p1 << std::endl;

  // istream
  std::cin >> p1;
  std::cout << "p1: " << p1 << std::endl;
}