// Item 37: Never redefine a function's inherited default parameter
// value
#include <iostream>
// a class for geometric shapes
class Shape {
 public:
  enum ShapeColor { Red, Green, Blue };
  // all shapes must offer a function to draw themselves
  virtual void draw(ShapeColor color = Red) const = 0;
};
class Rectangle : public Shape {
 public:
  // notice the different default parameter value 􀬛 bad!
  virtual void draw(ShapeColor color = Green) const {
    std::cout << "Rectangle Draw, color: " << color << std::endl;
  }
};
class Circle : public Shape {
 public:
  virtual void draw(ShapeColor color) const {
    std::cout << "Circle Draw, color: " << color << std::endl;
  }
};

int main(int argc, char const *argv[]) {
  Shape *pc = new Circle;     // static type = Shape*
  Shape *pr = new Rectangle;  // static type = Shape*

  pc->draw(Shape::Red);  // calls Circle::draw(Shape::Red)
  pr->draw(Shape::Red);  // calls Rectangle::draw(Shape::Red)
  pr->draw();            // calls Rectangle::draw(Shape::Red)!
  return 0;
}
