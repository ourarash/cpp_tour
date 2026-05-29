#include <iostream>
#include <string>
#include <vector>
class Rational {
 public:
  Rational(int n = 0, int d = 1) : numerator(n), denominator(d) {}

  int numerator;
  int denominator;

  void Print() {
    std::cout << "numerator: " << numerator << std::endl;
    std::cout << "denominator: " << denominator << std::endl;
  }

 private:
};

const Rational operator*(const Rational &lhs, const Rational &rhs) {
  Rational result;
  result.numerator = lhs.numerator * rhs.numerator;
  result.denominator = lhs.denominator * rhs.denominator;

  return result;
}

int Add(int a, int b) {
  int result;
  result = a + b;
  return result;
}
int main() {
  {
    Rational a{1, 3}, b{2, 4};
    Rational c = a * b;
    // a * b = c; // This compiles if operator* is not returning const!
    c.Print();
  }
  // { Add(1, 2) = 4; } // ---> Doesn't compile!
}