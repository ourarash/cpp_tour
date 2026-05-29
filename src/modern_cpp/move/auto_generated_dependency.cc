#include <iostream>
#include <string>

// move operations are generated for classes (when needed) only if these three
// things are true:

// • No copy operations are declared in the class.
// • No move operations are declared in the class.
// • No destructor is declared in the class.

// Move operations won’t be generated for any class that explicitly
// declares a copy operation (and vice versa)
struct C {
  C(std::string val) {
    value = val;
    std::cout << "Default " << value << "\n";
  }
  ~C() { std::cout << "Destructor " << value << "\n"; }

  C(const C& rhs) {
    value = rhs.value + "_copy";
    std::cout << "Copy Constructor " << value << "\n";
  }

  std::string value;
};

// Declaring a move operation (construction or
// assignment) in a class causes compilers to disable the copy operations (and
// vice versa)

// The two move operations are not independent. If you declare either, that
// prevents compilers from generating the other.
struct D {
  D(std::string val) {
    value = val;
    std::cout << "Default " << value << "\n";
  }
  ~D() { std::cout << "Destructor " << value << "\n"; }

  D(D&& rhs) {
    value = rhs.value;
    value += "_move";
    std::cout << "Move Constructor " << value << "\n";
  }

  std::string value;
};

// C++11 does not generate
// move operations for a class with a user-declared destructor.
struct E {
  E(std::string val) {
    value = val;
    std::cout << "Default " << value << "\n";
  }
  ~E() { std::cout << "Destructor " << value << "\n"; }

  std::string value;
};

// We can make compiler generate the default move using default.
struct F {
  F(std::string val) {
    value = val;
    std::cout << "Default " << value << "\n";
  }
  ~F() { std::cout << "Destructor " << value << "\n"; }
  F(F&& rhs) = default;
  std::string value;
};

class Widget {
 public:
  ~Widget() {}                         // user-declared dtor
                                       // default copy ctor
  Widget(const Widget&) = default;     // behavior is OK
  Widget&                              // default copy assign
  operator=(const Widget&) = default;  // behavior is OK
};

int main() {
  {
    C x("x");
    C y = x;
    C z =
        std::move(x);  // Move constructor will not be generated automatically.
    std::cout << "z.value: " << z.value << std::endl;
  }

  {
    D x("x");
    // D y = x;  // Copy constructor is not generated automatically.
    D z = std::move(x);
    // z = std::move(x);  // Move assignment will not be generated
    // automatically.
    std::cout << "z.value: " << z.value << std::endl;
  }

  {
    E x("x");

    E z = std::move(x);

    // C++11 does not generate
    // move operations for a class with a user-declared destructor.
    // x is still valid!
    std::cout << "x.value: " << x.value << std::endl;
  }

  {
    F x("x");

    F z = std::move(x);

    // C++11 does not generate
    // move operations for a class with a user-declared destructor.
    // But we bring it back using the keyword `default`.
    // x is now moved.
    std::cout << "x.value: " << x.value << std::endl;
  }
  return 0;
}