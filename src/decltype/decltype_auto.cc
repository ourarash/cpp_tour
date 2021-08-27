#include <iostream>
#include <string>
#include <vector>
class Widget {};
template <typename T>  // simplified version of std::vector
class vector {
 public:
  T& operator[](std::size_t index);
};
bool f(const Widget& w);  // decltype(w) is const Widget&

template <typename Container, typename Index>  // works, but
auto authAndAccess(Container& c, Index i)      // requires
    -> decltype(c[i])                          // refinement
{
  // authenticateUser();
  return c[i];
}

template <typename Container, typename Index>  // C++14;
auto authAndAccess(Container& c, Index i)      // not quite
{                                              // correct
  // authenticateUser();
  return c[i];  // return type deduced from c[i]
}

template <typename Container, typename Index>  // C++14; works,
decltype(auto)                                 // but still
authAndAccess(Container& c, Index i)           // requires
{                                              // refinement
  // authenticateUser();
  return c[i];
}

template <typename Container, typename Index>  // final
decltype(auto)                                 // C++14
authAndAccess(Container&& c, Index i)          // version
{
  // authenticateUser();
  return std::forward<Container>(c)[i];
}

template <typename Container, typename Index>  // final
auto                                           // C++11
authAndAccess(Container&& c, Index i)          // version
    -> decltype(std::forward<Container>(c)[i]) {
  // authenticateUser();
  return std::forward<Container>(c)[i];
}

int main() {
  const int i = 0;  // decltype(i) is const int
  // decltype(f) is bool(const Widget&)
  struct Point {
    int x, y;  // decltype(Point::x) is int
  };           // decltype(Point::y) is int
  Widget w;    // decltype(w) is Widget
  if (f(w)) {  // decltype(f(w)) is bool
  }

  vector<int> v;  // decltype(v) is vector<int>
  if (v[0] == 0)  // decltype(v[0]) is int&
    return 0;

  {
    Widget w;
    const Widget& cw = w;
    auto myWidget1 = cw;            // auto type deduction:
                                    // myWidget1's type is Widget
    decltype(auto) myWidget2 = cw;  // decltype type deduction:
                                    // myWidget2's type is
                                    // const Widget&
  }
}