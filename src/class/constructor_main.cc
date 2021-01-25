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

  // If you don't define constructor (any type of it), the compiler create a
  // default one for you The default one my not do what you want!

  // Copy constructor
  Point(const Point &p2) {
    std::cout << "COPY constructor." << std::endl;

    i_ = p2.GetI() * 2;
    j_ = p2.GetJ() * 2;

    std::cout << "Thanks for calling me!" << std::endl;
  }

  ~Point() { std::cout << "DESTRUCTOR." << std::endl; }

  // Getter or Accessor
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

void MyFunction(Point &param) { std::cout << "param: " << param << std::endl; }

int main() {
  Point p1;
  std::cout << "p1: " << p1 << std::endl;

  Point p2(1, 2);

  Point p3 = p2;

  MyFunction(p3);
  Point* ptr;
  ptr = new Point;

  { Point local_p1; }
}