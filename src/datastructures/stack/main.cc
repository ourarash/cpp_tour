#include <iostream>
#include <stack>
#include <string>

int main() {
  // Empty stack
  std::stack<int> s;

  if (!s.empty()) {
    int r = s.top();
    s.pop();  // Don't do this!
  }

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
  // for (auto it = s.begin(); it != s.end(); ++it) {
  // }

  return 0;
}