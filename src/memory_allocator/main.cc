#include <iostream>
class Test {
 public:
  Test() { std::cout << "Constructor!" << std::endl; }
  ~Test() { std::cout << "Destructor!" << std::endl; }
};

class MyClass {};

int main(int argc, char const* argv[]) {
  { Test* test_p = new Test; }
  {
    Test* myTest = static_cast<Test*>(malloc(sizeof(Test)));
    new (myTest) Test();  // Placement new to construct.
    delete myTest;
  }

  {
    // “nothrow” placement new tells the program you don’t want it throwing an
    //     exception if it fails :
    // This will return nullptr if it fails
    char* c = new (std::nothrow) char[1024];
  }
  {
    char buffer[1024];
    MyClass* p = new (buffer) MyClass();

    p->~MyClass();
    free(p);

    MyClass* q = new MyClass;
    free(q);
  }

  {
    // Allocate memory for a Test instance
    Test* myTest = static_cast<Test*>(malloc(sizeof(Test)));
    // Construct the object using "placement" new
    new (myTest) Test();
    // Destruct the object
    myTest->~Test();
    // Free the memory
    free(myTest);
  }

  return 0;
}

// What's the difference between free and delete???