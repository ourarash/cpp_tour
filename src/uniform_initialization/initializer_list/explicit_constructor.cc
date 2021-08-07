#include <iostream>
#include <string>
#include <vector>
//-----------------------------------------------------
// The compiler is allowed to make one implicit conversion to resolve the
// parameters to a function. What this means is that the compiler can use
// constructors callable with a single parameter to convert from one type to
// another in order to get the right type for a parameter.

class Test {
 public:
  explicit Test(int i) : x(i) {}
  void DoSomething() {}

 private:
  int x;
};

void DoStuff(Test foo) { foo.DoSomething(); }

int main(int argc, char const *argv[]) {
  // Uniform Initialization - Works!
  Test t1{5};


  // = { } ignores explicit constructors - ERROR! :(
  // Test t2 = {5};

  Test t3(5);

  // DoStuff(5); // Doesn't work because of explicit.
  return 0;
}

