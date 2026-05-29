#include <stdlib.h>

#include <iostream>
class Test {
 public:
  Test() { std::cout << "Constructor!" << std::endl; }
  ~Test() { std::cout << "Destructor!" << std::endl; }
};

int main(int argc, char const* argv[]) {
  {
    // Allocate an array of 10 integers
    int* array = static_cast<int*>(malloc(sizeof(int) * 10));  // malloc
  }

  {  // Allocate a struct
    struct Test {
      int a;
      int b;
    };
    Test* test = static_cast<Test*>(malloc(sizeof(Test)));
    // Use memset to set the memory of the struct to 0
    // aka "zero out" the memory
    // Parameters are (address, value, number of bytes)
    memset(test, 0, sizeof(Test));
  }

  {
    Test* test_p = new Test;  // new
  }
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
    Test* p = new (buffer) Test();

    p->~Test();
    free(p);

    Test* q = new Test;
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