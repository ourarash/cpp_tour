#include <iostream>
#include <string>
#include <vector>

int main() {
  char greeting[] = "Hello";
  char greeting2[] = "Hello";

  {
    int a[10];
    int b[10];

    // b = a; -----> Compile error!
  }

  // const before asterisk: What is pointed to is constant
  // const after asterisk: the pointer is constant
  {
    char *p = greeting;  // non-const pointer, non-const data
    p = (char *)&greeting2;
    strcpy(p, "asdf");
  }
  {
    const char *p = greeting;  // non-const pointer, const data
    p = greeting2;
    // strcpy(p, "asdf");  // -----> Compile error!
  }
  {
    char *const p = greeting;  // const pointer, non-const data
    // p = greeting2; ----> Compile error!
  }
  {
    const char *const p = greeting;  // const pointer,
                                     // const data
  }

  //-----------------------------------------------------------------------------
  // Const with iterators
  {
    std::vector<int> vec;
    // iter acts like a T* const
    const std::vector<int>::iterator iter = vec.begin();
    *iter = 10;  // OK, changes what iter points to
    // ++iter;      // error! iter is const

    // cIter acts like a const T*
    std::vector<int>::const_iterator cIter = vec.begin();
    // *cIter = 10;  // errsor! *cIter is const
    ++cIter;  // fine, changes cIter
  }
  return 0;
}