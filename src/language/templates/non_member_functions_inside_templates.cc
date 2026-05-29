// Effective C++, Item 46

#include <iostream>
template <typename T>
class Rational {
 public:
  Rational(const T& numerator = 0,       // see Item 20 for why params
           const T& denominator = 1) {}  // are now passed by reference
  const T numerator() const;             // see Item 28 for why return
  const T denominator() const;           // values are still passed by value,
  // Item 3 for why they're const

  friend const Rational<T> operator*(const Rational<T>& lhs,
                                     const Rational<T>& rhs);
};
template <typename T>
const Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs) {}

int main(int argc, char const* argv[]) {
  Rational<int> oneHalf(1, 2);  // this example is from Item 24,
  // except Rational is now a template
  Rational<int> result = oneHalf * 2;  // error! won't compile
  return 0;
}
