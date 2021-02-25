// The output is different if you run this code with C++17 vs C++11 and
// -fno-elide-constructors
#include <iostream>
using namespace std;

class B {
 public:
  B(const char* str = "\0")  // default constructor
  {
    cout << "Constructor called" << endl;
  }

  B(const B& b)  // copy constructor
  {
    cout << "Copy constructor called" << endl;
  }
};

int main() {
  {
    // This should convert to:
    // B ob("copy me");
    B ob = "copy me";
  }

  {
    // This should convert to:
    // B ob("copy me");
    B ob = B("copy me");
  }
  return 0;
}