#include <iostream>
#include <string>
#include <vector>
class Point {  // class for representing points
 public:
  Point() : Point(0, 0) {
    std::cout << "Point constructor: "
              << ", x: " << x << ", y: " << y << std::endl;
  }
  Point(int x, int y) {
    std::cout << "Point constructor: "
              << ", x: " << x << ", y: " << y << std::endl;
  }
  void setX(int newVal) { x = newVal; }
  void setY(int newVal) { y = newVal; }

 private:
  int x;
  int y;
};

struct RectData {  // Point data for a Rectangle
  Point ulhc;      // ulhc = " upper left-hand corner"
  Point lrhc;      // lrhc = " lower right-hand corner"
  int z;
};

class Rectangle {
 public:
  Rectangle(Point& ulhc, Point& lrhc) {
    pData = new RectData;
    pData->ulhc = ulhc;
    pData->lrhc = lrhc;
  }

  // Although member function is const, we can still modify the object.

  Point& upperLeft() const { return pData->ulhc; }
  Point& lowerRight() const { return pData->lrhc; }
  int& getZ() const { return pData->z; }
  // int& getT() const { return t; } // This doesn't compile

 private:
  RectData* pData;  // see Item 13 for info on
  int t;
};

void doSomething() throw() {}

int main(int argc, char const* argv[]) {
  Point coord1(0, 0);
  Point coord2(100, 100);
  const Rectangle rec(coord1, coord2);  // rec is a const rectangle from
  // (0, 0) to (100, 100)
  rec.upperLeft().setX(50);  // now rec goes from
  // (50, 0) to (100, 100)!

  rec.getZ() = 10;
  return 0;
}
