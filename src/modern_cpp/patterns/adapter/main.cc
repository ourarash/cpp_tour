#include <iostream>
class Point {
 public:
  Point() {
    x = 0;
    y = 0;
  }

  // PARAMETERIZED Constructor
  Point(int x1, int y1) {
    x = x1;
    y = y1;
  }

  // Copy constructor
  Point(const Point& p2) {
    std::cout << "COPY constructor." << std::endl;
    x = p2.x;
    y = p2.y;
  }

  int x;
  int y;
};

struct Shape {
  // Shape class we want to use
  virtual void BoundingBox(Point& topLeft, Point& bottomRight) const;
};

struct TextView {
  // Text view class for external lib
  void GetOrigin(int& x, int& y) const;
  void GetExtent(int& width, int& height) const;
};

struct TextShape : public Shape, private TextView {
  void BoundingBox(Point& topLeft, Point& bottomRight) const {
    int x, y, w, h;
    GetOrigin(x, y);
    GetExtent(w, h);

    topLeft.x = x;
    topLeft.y = y;
    bottomRight.x = x + w;
    bottomRight.y = y + h;
  }
};

int main(int argc, char const* argv[]) {
  Shape s;
  TextView tv;

  // Later ...
  // Get the bounding box.
  Point topLeft;
  Point bottomRight;
  s.BoundingBox(topLeft, bottomRight);
  // tv.BoundingBox(); // Doesn't compile.

  TextShape ts;
  ts.BoundingBox(topLeft, bottomRight);

  return 0;
}
