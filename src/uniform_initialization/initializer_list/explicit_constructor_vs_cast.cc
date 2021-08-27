#include <iostream>
#include <string>
#include <vector>

class Widget {
 public:
  explicit Widget(int size);
};

void doSomeWork(const Widget& w);
int main(int argc, char const* argv[]) {
  // doSomeWork(15); ---> Doesn't compile due to explicit.
  doSomeWork(Widget(15));  // create Widget from int
  // with function-style cast
  doSomeWork(static_cast<Widget>(15));  // create Widget from int
  // with C++-style cast

  Widget z = static_cast<Widget>(15);
  return 0;
}
