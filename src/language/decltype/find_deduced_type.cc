#include <iostream>
#include <string>
#include <vector>

// Attempts to instantiate this template will elicit an error message, because
// there’s no
// template definition to instantiate.
template <typename T>  // declaration only for TD;
class TD;              // TD == "Type Displayer"

int main(int argc, char const* argv[]) {
  // TD<double> td;
  // {
  //   int x;
  //   float y;
  //   const int& cir = x;
  //   auto xr = cir;

  //   // To see the types for x and y, just try to instantiate
  //   // TD with their types:
  //   TD<decltype(x)> xType;      // elicit errors containing
  //   TD<decltype(y)> yType;      // x's and y's types
  //   TD<decltype(cir)> cirType;  // cir type
  //   TD<decltype(xr)> xrType;    // xr type
  // }

  {
    int x;
    float y;
    std::cout << typeid(x).name() << '\n';  // display types for
    std::cout << typeid(y).name() << '\n';  // x and y
  }
  return 0;
}
