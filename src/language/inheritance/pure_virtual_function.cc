#include <iostream>
class Shape {
 public:
  virtual void draw() const = 0;
};

// We can still define a definition for draw if we want to!
void Shape::draw() const { std::cout << "Shape::draw" << std::endl; }

class Rectangle : public Shape {
 public:
  void draw() const { std::cout << "Rectangle draw" << std::endl; }
};
class Ellipse : public Shape {
 public:
  void draw() const { std::cout << "Ellipses draw" << std::endl; }
};

int main(int argc, char const *argv[]) {
  // Shape *ps = new Shape;       // error! Shape is abstract
  Shape *ps1 = new Rectangle;  // fine
  ps1->draw();                 // calls Rectangle::draw

  Shape *ps2 = new Ellipse;  // fine
  ps2->draw();               // calls Ellipse::draw
  ps1->Shape::draw();        // calls Shape::draw
  return 0;
}
