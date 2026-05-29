// Effective modern C++, Item 9
#include <iostream>
#include <list>
template <typename T>
class MyAlloc {};
class Widget {};

template <typename T>                                 // MyAllocList<T>
using MyAllocList = std::list<T, std::allocator<T>>;  // is synonym for
// std::list<T, MyAlloc<T>>

// Same thing with typedef
template <typename T>                            // MyAllocList<T>::type
struct MyAllocList2 {                            // is synonym for
  typedef std::list<T, std::allocator<T>> type;  // std::list<T,
};                                               // MyAlloc<T>>

template <typename T>
class Widget2 {         // Widget<T> contains
 private:               // a MyAllocList<T>
  MyAllocList<T> list;  // as a data member
  // This one needs typename
  typename MyAllocList2<T>::type list2;  // as a data member
};

int main(int argc, char const *argv[]) {
  MyAllocList<Widget> lw;          // client code
  MyAllocList2<Widget>::type lw2;  // client code
  return 0;
}
