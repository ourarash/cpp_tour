#include <iostream>
#include <vector>

namespace WidgetStuff {
template <typename T>
class WidgetImpl {  // class for Widget data;
 public:            // details are unimportant
 private:
  int a, b, c;            // possibly lots of data 􀬛
  std::vector<double> v;  // expensive to copy!
  T z;
};

template <typename T>
class Widget {  // class using the pimpl idiom
 public:
  Widget(const Widget& rhs) {}
  Widget() {}
  Widget& operator=(const Widget& rhs)  // to copy a Widget, copy its
  {                                     // WidgetImpl object. For
                                        // details on implementing
    *pImpl = *(rhs.pImpl);              // operator= in general,
    // see Items 10, 11, and 12.
    return *this;
  }

  void swap(Widget& other) {
    using std::swap;  // the need for this declaration
    // is explained later in this Item
    swap(pImpl, other.pImpl);  // to swap Widgets, swap their
  }                            // pImpl pointers

 private:
  WidgetImpl<T>* pImpl;  // ptr to object with this
};

template <typename T>    // non-member swap function;
void swap(Widget<T>& a,  // not part of the std namespace
          Widget<T>& b) {
  a.swap(b);
}

}  // namespace WidgetStuff

// The following compiles, but we should not really add a function to std...
// namespace std {
// template <typename T>    // an overloading of std::swap
// void swap(Widget<T>& a,  // (note the lack of "<...>" after
//           Widget<T>& b)  // "swap"), but see below for
// {
//   a.swap(b);
// }  // why this isn't valid code
// }  // namespace std

// The following doesn't compile.
// namespace std {
// template <typename T>               // revised specialization of
// void swap<Widget<T>>(Widget<T>& a,  // std::swap
//                      Widget<T>& b) {
//   a.swap(b);  // to swap Widgets, call their
// }  // swap member function
// }  // namespace std
using namespace WidgetStuff;
int main(int argc, char const* argv[]) {
  Widget<int> a, b;
  swap(a,b);

      return 0;
}
