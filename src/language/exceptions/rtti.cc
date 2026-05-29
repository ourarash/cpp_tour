#include <exception>
#include <iostream>
class Base {
 public:
  virtual int size() { return 0; };
};
class Derived : public Base {
 public:
  int size() override { return 3; }
};

int main() {
  Base* base = new Base;            // Base
  Base* as_base_ptr = new Derived;  // Derrived

  std::cout << "typeid(*base): " << typeid(*base).name() << std::endl;
  std::cout << "typeid(*as_base_ptr): " << typeid(*as_base_ptr).name()
            << std::endl;

  Derived* derived_ptr = dynamic_cast<Derived*>(as_base_ptr);

  // dynamic_cast returns 0 if not a derived
  if (derived_ptr) {
    std::cout << "Yes, it's a derived!" << std::endl;
    std::cout << "derived_ptr->size(): " << derived_ptr->size() << std::endl;
  }

  Derived* not_derived_ptr = dynamic_cast<Derived*>(base);

  if (not_derived_ptr) {
    std::cout << "Yes, it's a derived!" << std::endl;
    std::cout << "not_derived_ptr->size(): " << not_derived_ptr->size()
              << std::endl;
  } else {
    std::cout << "Not a derived" << std::endl;
  }

  if (typeid(*as_base_ptr) == typeid(*base)) {
    std::cout << "The types are the same." << std::endl;
  } else {
    std::cout << "The types are the different." << std::endl;
  }

  std::cout << "typeid(*as_base_ptr): " << typeid(*as_base_ptr).name()
            << std::endl;
  std::cout << "typeid(*base): " << typeid(*base).name() << std::endl;

  // Static cast compiles, but gives you incorrect resutls.
  {
    Base* as_base_ptr = new Derived;  // Derrived
    Base* base = new Base;            // Base

    std::cout << "as_base_ptr->size(): " << as_base_ptr->size() << std::endl;

    Derived* derived_ptr = static_cast<Derived*>(as_base_ptr);
    std::cout << "derived_ptr->size(): " << derived_ptr->size() << std::endl;

    Derived* not_derived_ptr = static_cast<Derived*>(base);
    std::cout << "not_derived_ptr->size(): " << not_derived_ptr->size()
              << std::endl;
  }
  return 0;
}