#include <iostream>
class Test {
 public:
  Test() { std::cout << "Constructor!" << std::endl; }
};

class MyClass {};

int main(int argc, char const* argv[]) {
  Test* test_p = new Test;

  Test* myTest = static_cast<Test*>(malloc(sizeof(Test)));
  new (myTest) Test();  // Placement new
  delete myTest;

  char buffer[1024];
  MyClass* p = new (buffer) MyClass();
  
  p->~MyClass();
  free(p);

  MyClass* q = new MyClass;
  free(q);
  return 0;
}

// What's the difference between free and delete???