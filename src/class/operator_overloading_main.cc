
#include <iostream>
#include <string>
#include <vector>

#include "src/lib/utility.h"

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

  Point operator+(const Point &rhs) const {
    Point res;
    res.i_ = i_ + rhs.i_;
    res.j_ = j_ + rhs.j_;
    return res;
  }

  // Prefix overload
  // ++p;
  // Point p2 = ++p1;
  Point& operator++() {
    i_++;
    j_++;
    return *this;
  }

  // Postfix overload
  // p++;
  // Point p2 = p1++;
  // 1. Return the previous value
  // 2. Increment p1
  Point operator++(int) {
    Point temp = *this;  // 1.
    i_++;                // 2.
    j_++;                // 2.
    return temp;         // 1.
  }

  int GetI() const { return i_; };
  int GetJ() const { return j_; };
  void SetI(int i) { i_ = i; };
  void SetJ(int j) { j_ = j; };
  friend std::istream &operator>>(std::istream &is, Point &p);
  friend Point operator-(const Point &lhs, const Point &rhs);

  friend int MyFunction(const Point &p);

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

int MyFunction(const Point &p) { std::cout << "p.i_: " << p.i_ << std::endl; }

// p1 - p2
Point operator-(const Point &lhs, const Point &rhs) {
  Point res;
  res.SetI(lhs.i_ - rhs.GetI());
  res.SetJ(lhs.j_ - rhs.GetJ());
  return res;
}

int main() {
  // OPerator overloading
  Point p1(1, 2);
  Point p2(10, 20);
  Point p3 = p1 + p2;
  Point p4 = p1 - p2;
  std::cout << "p3: " << p3 << std::endl;

  ++p1;
  std::cout << "p1: " << p1 << std::endl;

  p1++;
  std::cout << "p1: " << p1 << std::endl;

  // istream
  std::cin >> p1;
  std::cout << "p1: " << p1 << std::endl;
}
