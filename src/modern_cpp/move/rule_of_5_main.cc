#include <iostream>
#include <string>

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

  C(C&& rhs) {
    value = rhs.value;
    value += "_move";
    std::cout << "Move Constructor " << value << "\n";
  }

  C& operator=(const C& rhs) {
    std::cout << "Copy Assignment\n";
    return *this;
  }

  C& operator=(C&& rhs) {
    value = rhs.value;
    std::cout << "Move Assignment" << value << "\n";
    return *this;
  }

  std::string value;
};

C f() {
  C a("a");
  C b("b");
  b = a;

  // When we have move assignmet hidden annoying retval
  // 1. You have to move b to retval
  // 2. retval gets destructed

  // We we don't have move assignment hidden annoying retval
  // 1. You have to copy b to retval
  // 2. retval gets destructed
  return b;
}

// int main() {
//   C x;

//   C y = x;  // Copy constructor

//   C t;
//   t = x;  // Copy assignment

//   C z( f() );

//   return 0;
// }

C b(C v) {
  v.value = v.value + "_hi";
  return v;
}

int main() {
  C x("x");
  C y = b(x);

  return 0;
}