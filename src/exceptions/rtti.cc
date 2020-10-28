#include <exception>
#include <iostream>
class Shape {
  virtual int size() { return 1; };
};
class Triangle : public Shape {
  int size() override { return 0; }
};

int main() {
  Shape* myShape = new Triangle;  // Derrived
  Shape* shape = new Shape;       // Base

  Triangle* myTriangle = dynamic_cast<Triangle*>(myShape);
  // dynamic_cast returns 0 if not a triangle
  if (myTriangle) {
    std::cout << "Yes, it's a triangle!" << std::endl;
  }

  Triangle* not_triangle = dynamic_cast<Triangle*>(shape);

  if (not_triangle) {
    std::cout << "Yes, it's a triangle!" << std::endl;
  }

  if(typeid(*myShape) == typeid(*shape)){
    std::cout << "The types are the same." << std::endl;
  } else {
    std::cout << "The types are the different." << std::endl;
  }

  std::cout << "typeid(*myShape): " << typeid(*myShape).name() << std::endl;
  std::cout << "typeid(*shape): " << typeid(*shape).name() << std::endl;

  return 0;
}