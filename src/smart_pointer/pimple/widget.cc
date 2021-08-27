
//-----------------------------------------------------------------------------
#include "widget.h"

#include <memory>
#include <string>
#include <vector>

// #include "gadget.h"
// #include "widget.h"    // in "widget.cpp"
struct Widget::Impl {  // as before
  std::string name;
  std::vector<double> data;
  // Gadget g1, g2, g3;
};
Widget::Widget()                       // per Item 21, create
    : pImpl(std::make_unique<Impl>())  // std::unique_ptr
{}

Widget::~Widget() = default;                        // ~Widget definition
Widget::Widget(Widget&& rhs) = default;             // defini-
Widget& Widget::operator=(Widget&& rhs) = default;  // tions
