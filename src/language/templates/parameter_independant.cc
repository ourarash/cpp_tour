// Effective C++, Item 44
#include <iostream>

template <typename T,     // template for n x n matrices of
          std::size_t n>  // objects of type T; see below for info
class SquareMatrix {      // on the size_t parameter
 public:
  void invert();  // invert the matrix in place
};

int main(int argc, char const *argv[]) {
  // Two copies of invert will be instantiated!
  SquareMatrix<double, 5> sm1;
  sm1.invert();  // call SquareMatrix<double, 5>::invert
  SquareMatrix<double, 10> sm2;
  sm2.invert();  // call SquareMatrix<double, 10>::invert
  return 0;
}
