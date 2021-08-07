#include <iostream>
#include <string>
#include <vector>
class Window {  // base class
 public:
  Window() { std::cout << "Window constructor" << std::endl; }

  Window(const Window &rhs) {
    std::cout << "Window copy constructor" << std::endl;
  }
  ~Window() { std::cout << "Window destructor." << std::endl; }

  virtual void onResize() {
    std::cout << "Window resize" << std::endl;

  }  // base onResize impl
};
class SpecialWindow : public Window {  // derived class
 public:
  SpecialWindow() { std::cout << "SpecialWindow constructor" << std::endl; }
  virtual void onResize() {
    // Surprisingly, this will call the copy constructor!
    // this doesn't work!
    std::cout << "-------------------------------------------------------------"
              << std::endl;
    static_cast<Window>(*this).onResize();  // cast *this to Window,
    std::cout << "-------------------------------------------------------------"
              << std::endl;
    // But this will work:
    Window::onResize();

    std::cout << "SpecialWindow resize" << std::endl;

  }  // specific stuff
};

int main(int argc, char const *argv[]) {
  SpecialWindow special_window;

  special_window.onResize();
  return 0;
}
