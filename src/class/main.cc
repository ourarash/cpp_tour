#include <iostream>
#include <string>
#include <vector>

class Point {
 public:
  // Constructor
  // Point() {
  //   i_ = 0;
  //   j_ = 0;
  // }

  Point(int i, int j) {
    i_ = i;
    j_ = j;
  }

  // Copy constructor
  Point(const Point &original) {
    i_ = original.GetI();
    j_ = original.GetJ();
  }

  int GetI() const { return i_; };
  int GetJ() const { return j_; };
  void SetI(int i) { i_ = i; };
  void SetJ(int j) { j_ = j; };

 private:
  int i_;
  int j_;
};

void F(Point p) {
  std::cout << "Inside F. Pass by value" << std::endl;
}

void F_reference(Point &p) {
  std::cout << "Inside F. Pass by reference" << std::endl;
}

int main() {
  Point p1(1, 2);  // Constructor is called
  Point p2 = p1;   // Copy constructor is called

  Point p;
  F(p);
  F_reference(p);
  Point *ptr;
}