#include <exception>
#include <iostream>
class MyException : public virtual std::exception {
  // what is a virtual function which returns a description
  const char* what() const noexcept override {
    // throw std::exception();
    return "MY EXCEPTION!";
  }
};
// later on...

int main() {
  try {
    throw MyException();
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;  // "MY EXCEPTION!"
  }
  return 0;
}
