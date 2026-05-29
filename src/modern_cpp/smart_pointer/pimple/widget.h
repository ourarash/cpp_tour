#include <memory>

class Widget {  // in "widget.h"
 public:
  Widget();
  ~Widget();  // declaration only

  Widget(Widget&& rhs);             // declarations
  Widget& operator=(Widget&& rhs);  // only
 private:
  struct Impl;
  std::unique_ptr<Impl> pImpl;  // use smart pointer
};
//-----------------------------------------------------------------------------
