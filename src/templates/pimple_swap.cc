#include <iostream>
#include <vector>

class WidgetImpl {  // class for Widget data;
 public:            // details are unimportant
 private:
  int a, b, c;            // possibly lots of data 􀬛
  std::vector<double> v;  // expensive to copy!
};
class Widget {  // class using the pimpl idiom
 public:
  Widget(const Widget& rhs);
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
  WidgetImpl* pImpl;  // ptr to object with this
};

namespace std {
template <>                   // revised specialization of
void swap<Widget>(Widget& a,  // std::swap
                  Widget& b) {
  a.swap(b);  // to swap Widgets, call their
}  // swap member function
}  // namespace std