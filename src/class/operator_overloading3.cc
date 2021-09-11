#include <iostream>

// Returning reference to object vs the object
struct X {
  // prefix increment
  X& operator++() {
    value++;
    return *this;  // return new value by reference
  }

  // postfix increment
  X operator++(int) {
    X old = *this;  // copy old value
    ++(*this);      // prefix increment
    return old;     // return old value
  }

  // prefix decrement
  X& operator--() {
    value--;
    return *this;  // return new value by reference
  }

  // postfix decrement
  X operator--(int) {
    X old = *this;  // copy old value
    --(*this);      // prefix decrement
    return old;     // return old value
  }

  X& operator+=(
      const X& rhs)  // compound assignment (does not need to be value member,
  {                  // but often is, to modify the private members)
    value += rhs.value;
    return *this;  // return the result by reference
  }

  X operator+(const X& rhs) {
    (*this) += rhs;  // reuse compound assignment
    return *this;    // return the result by value (uses move constructor)
  }

  void Print() { std::cout << "value: " << value << std::endl; }

 public:
  int value;
};

int main(int argc, char const* argv[]) {
  X x1, x2;

  x1.value = 0;
  x2.value = 1;

  ++x1;
  x1.Print();
  x1++;
  x1.Print();

  x2 += x1;
  x2.Print();

  auto x3 = x1 + x2;

  x3.Print();
  return 0;
}
