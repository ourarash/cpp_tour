#include <iostream>
#include <string>
#include <vector>

class Point {
 public:
  // No default constructor is defined.

  // PARAMETERIZED Constructor
  Point(int i, int j) {
    std::cout << "**PARAMETERIZED constructor." << std::endl;
    i_ = i;
    j_ = j;
    z_ = new int;
  }

  ~Point() {
    delete z_;  // Deallocate z_
    std::cout << "DESTRUCTOR." << std::endl;
  }

  // Getter or Accessor
  int GetI() const { return i_; };
  int GetJ() const { return j_; };

  void SetI(int i) { i_ = i; };
  void SetJ(int j) { j_ = j; };

 private:
  int i_;
  int j_;

  int *z_;
};

std::ostream &operator<<(std::ostream &os, const Point &m) {
  return os << "( " << m.GetI() << ", " << m.GetJ() << " )";
}

void MyFunction(Point param) { std::cout << "param: " << param << std::endl; }

int main() {
  Point p1;  //------------> doesn't compile!
  std::cout << "p1: " << p1 << std::endl;
}