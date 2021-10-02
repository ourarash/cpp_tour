#include <iostream>
#include <stack>
#include <string>

int main() {

  // std::vector v;
  // std::cout << "v[10]: " << v[10] << std::endl;

  // Empty stack
  std::stack<int> s;

  int r;
  // r = s.top();  // Seriously?
  // s.pop();      // Don't do this!

  if (!s.empty()) {
    r = s.top();
    s.pop();  // Don't do this!
  }

  // // Do this:
  // if (!s.empty()) {
  //   s.pop();
  // }
  {
    std::stack<int> s;

    std::cout << "s.size(): " << s.size() << std::endl;
    // int r = s.top();
    // std::cout << "r: " << r << std::endl;

    s.push(1);
    std::cout << "s.top(): " << s.top() << std::endl;

    s.push(2);
    std::cout << "s.top(): " << s.top() << std::endl;

    s.pop();
    std::cout << "s.top(): " << s.top() << std::endl;
  }

  // OMG! There is not begin and end!
  // Can't do this:
  // for(auto it=s.begin(); it!=s.end(); ++it){

  // }

  return 0;
}