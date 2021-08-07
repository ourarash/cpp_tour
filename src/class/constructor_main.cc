#include <iostream>
#include <string>
#include <vector>

class Point {
 public:
  Point() {
    i_ = 0;
    j_ = 0;

    z_ = new int;
    std::cout << "***NO PARAMETERIZED constructor." << std::endl;
  }

  // PARAMETERIZED Constructor
  Point(int i, int j) {
    std::cout << "**PARAMETERIZED constructor." << std::endl;
    i_ = i;
    j_ = j;
    z_ = new int;
  }

  // PARAMETERIZED Constructor
  Point(int i) {
    std::cout << "**PARAMETERIZED constructor 2." << std::endl;
    i_ = i;
    j_ = 0;
    z_ = new int;
  }

  // Copy constructor
  Point(const Point &p2) {
    std::cout << "COPY constructor." << std::endl;

    i_ = p2.GetI();
    j_ = p2.GetJ();
    z_ = new int;
    // *z_ = p2.GetZ();
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
  Point p1;
  std::cout << "p1: " << p1 << std::endl;

  Point p2(1, 2);

  Point p3 = p2;  // Copy constructor

  p2.SetI(10);
  p2.SetJ(50);

  std::cout << "p3: " << p3 << std::endl;

  MyFunction(p3);

  Point p4;  // Default constructor
  p4 = p2;   // Assignments (Copy assignment)

  Point *ptr;
  ptr = new Point;

  delete ptr;

  {
    Point a;
    Point b(a);
    Point c{a};
  }
}