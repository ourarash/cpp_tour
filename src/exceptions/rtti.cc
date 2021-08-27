#include <exception>
#include <iostream>
class Shape {
 public:
  virtual int size() { return 0; };
};
class Triangle : public Shape {
 public:
  int size() override { return 3; }
};

int main() {
  Shape* myShape = new Triangle;  // Derrived
  Shape* shape = new Shape;       // Base

  std::cout << "typeid(*myShape): " << typeid(*myShape).name() << std::endl;
  std::cout << "typeid(*shape): " << typeid(*shape).name() << std::endl;

  Triangle* myTriangle = dynamic_cast<Triangle*>(myShape);

  // dynamic_cast returns 0 if not a triangle
  if (myTriangle) {
    std::cout << "Yes, it's a triangle!" << std::endl;
    std::cout << "myTriangle->size(): " << myTriangle->size() << std::endl;
  }

  Triangle* not_triangle = dynamic_cast<Triangle*>(shape);

  if (not_triangle) {
    std::cout << "Yes, it's a triangle!" << std::endl;
    std::cout << "not_triangle->size(): " << not_triangle->size() << std::endl;
  } else {
    std::cout << "Not a triangle" << std::endl;
  }

  if (typeid(*myShape) == typeid(*shape)) {
    std::cout << "The types are the same." << std::endl;
  } else {
    std::cout << "The types are the different." << std::endl;
  }

  std::cout << "typeid(*myShape): " << typeid(*myShape).name() << std::endl;
  std::cout << "typeid(*shape): " << typeid(*shape).name() << std::endl;

  // Static cast compiles, but gives you incorrect resutls.
  {
    Shape* myShape = new Triangle;  // Derrived
    Shape* shape = new Shape;       // Base

    std::cout << "myShape->size(): " << myShape->size() << std::endl;

    Triangle* myTriangle = static_cast<Triangle*>(myShape);
    std::cout << "myTriangle->size(): " << myTriangle->size() << std::endl;

    Triangle* not_triangle = static_cast<Triangle*>(shape);
    std::cout << "not_triangle->size(): " << not_triangle->size() <<
    std::endl;
  }
  return 0;
}