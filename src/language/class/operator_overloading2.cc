#include <iostream>
using namespace std;

class Complex {
 private:
  int real, imag;

 public:
  Complex(int r = 0, int i = 0) {
    real = r;
    imag = i;
  }
  void print() { cout << real << " + i" << imag << endl; }

  bool operator<(const Complex &rhs) { return (real < rhs.real); }
  friend bool operator<(const Complex &lhs, const Complex &rhs) {
    return (lhs.real < rhs.real);
  }

  // The global operator function is made friend of this class so
  // that it can access private members
  friend Complex operator+(Complex const &, Complex const &);
  friend Complex operator+(Complex const &lhs, int const &rhs) {
    return lhs.real + rhs;
  }

  // This is automatically called when '+' is used with
  // between two Complex objects
  // Complex operator+(Complex const &obj) {
  //   Complex res;
  //   res.real = real + obj.real;
  //   res.imag = imag + obj.imag;
  //   return res;
  // }
};

Complex operator+(Complex const &c1, Complex const &c2) {
  return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

struct Record {
  std::string name;
  unsigned int floor;
  double weight;
  friend bool operator<(const Record &l, const Record &r) {
    return std::tie(l.name, l.floor, l.weight) <
           std::tie(r.name, r.floor, r.weight);  // keep the same order
  }
};

int main() {
  Complex c1(10, 5), c2(2, 4);
  Complex c3 = c1 + c2;  // An example call to "operator+"
  c3.print();
  return 0;
}