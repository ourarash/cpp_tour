#include <iostream>
class Point {
 public:
  constexpr Point(int xVal = 0, int yVal = 0) noexcept : x(xVal), y(yVal) {}
  constexpr int xValue() const noexcept { return x; }
  constexpr int yValue() const noexcept { return y; }
  void setX(int newX) noexcept { x = newX; }
  void setY(int newY) noexcept { y = newY; }

  constexpr void setX14(double newX) noexcept  // C++14
  {
    x = newX;
  }
  constexpr void setY14(double newY) noexcept  // C++14
  {
    y = newY;
  }

 private:
  int x, y;
};
constexpr Point midpoint(const Point& p1, const Point& p2) noexcept {
  return {(p1.xValue() + p2.xValue()) / 2,   // call constexpr
          (p1.yValue() + p2.yValue()) / 2};  // member funcs
}

// return reflection of p with respect to the origin (C++14)
constexpr Point reflection(const Point& p) noexcept {
  Point result;              // create non-const Point
  result.setX14(-p.xValue());  // set its x and y values
  result.setY14(-p.yValue());
  return result;  // return copy of it
}

int main() {
  {
    constexpr Point p1(9, 27);  // fine, "runs" constexpr
    // ctor during compilation
    constexpr Point p2(28, 5);  // also fine

    int a[p1.xValue()];

    constexpr auto mid = midpoint(p1, p2);  // init constexpr
    // object w/result of
    // constexpr function
  }

  {
    constexpr Point p1(9, 27);  // as above
    constexpr Point p2(28, 5);
    constexpr auto mid = midpoint(p1, p2);
    constexpr auto reflectedMid =  // reflectedMid's value is
        reflection(mid);           // (-19.1 -16.5) and known
                                   // during compilation
  }
  return 0;
}