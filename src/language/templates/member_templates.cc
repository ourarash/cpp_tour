// Effective C++, Item 45
#include <iostream>
template <class T>
class shared_ptr {
 public:
  shared_ptr(shared_ptr const& r);                // copy constructor
  template <class Y>                              // generalized
  shared_ptr(shared_ptr<Y> const& r);             // copy constructor
  shared_ptr& operator=(shared_ptr const& r);     // copy assignment
  template <class Y>                              // generalized
  shared_ptr& operator=(shared_ptr<Y> const& r);  // copy assignment
};