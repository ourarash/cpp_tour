// Demonstrates the slicing problem

#include <iostream>
#include <string>

class Window {
 public:
  virtual void display() const {
    std::cout << "base" << std::endl;
  }  // draw window and contents

  std::string name() const { return name_; }  // return name of window

  std::string name_;
};

class WindowWithScrollBars : public Window {
 public:
  virtual void display() const {
    std::cout << "derived" << std::endl;
  }  // draw window and contents
};

void printNameAndDisplay(Window w)  // incorrect! parameter
{                                   // may be sliced!
  std::cout << w.name() << std::endl;
  w.display();
}

void printNameAndDisplay2(const Window& w)  // fine, parameter won't
{                                           // be sliced
  std::cout << w.name();
  w.display();
}

int main(int argc, char const* argv[]) {
  {
    // Calling the base class
    Window win;
    printNameAndDisplay(win);
  }
  {
    // Calling the function on the derived class, still prints base!
    WindowWithScrollBars wwsb;
    printNameAndDisplay(wwsb);
  }

  {
    // Calling the function on the derived class, will  print derived if pass by
    // reference
    WindowWithScrollBars wwsb;
    printNameAndDisplay2(wwsb);
  }
  return 0;
}
