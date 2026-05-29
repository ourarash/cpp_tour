#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
class MyClass {
 public:
  //<< conversion constructor
  MyClass() { std::cout << "Constructor!" << std::endl; }
  ~MyClass() { std::cout << "Destructor!" << std::endl; }

  // bool operator<(const Complex &rhs) { return (real < rhs.real); }
  friend bool operator<(const MyClass &lhs, const MyClass &rhs) {
    return (true);
  }
};

int main(int argc, char const *argv[]) {
  // auto derefLess =        // C++14 comparison
  //     [](const auto& p1,  // function for

  //        const auto& p2)  // values pointed
  // { return *p1 < *p2; };  // to by anything
  //                         // pointer-like

  // int a = 4, b = 5;

  // auto x = derefLess(&a, &b);

  {
    std::map<MyClass, int> m;

    MyClass mc1, mc2;
    m[mc1] = 1;
    m[mc2] = 2;

    // This will genreate a warning, because in map members the first item is
    // const. missing const will cause the copy constructor and the destructor
    // to be called!
    for (const std::pair<MyClass, int> &p : m) {
      std::cout << "p.second: " << p.second << std::endl;
    }
  }

  return 0;
}
