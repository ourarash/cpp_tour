#include <iostream>
#include <string>
#include <vector>
//-----------------------------------------------------
class Test {
 public:
  explicit Test(int i) : x(i) {}

 private:
  int x;
};
int main(int argc, char const *argv[]) {
  // Uniform Initialization - Works!
  Test t1{5};

  // = { } ignores explicit constructors - ERROR! :(
  Test t2 = {5};

  return 0;
}
