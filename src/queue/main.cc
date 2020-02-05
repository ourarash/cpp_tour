#include "src/lib/utility.h"
#include <iostream>
#include <queue>
#include <stack>
#include <string>

int main() {

  // Empty stack
  std::queue<int> q;
  // int r = q.front();  // Seriously?
  // q.pop();          // Don't do this!

  // Do this:
  if (!q.empty()) {
    q.pop();
  }

  {
    // compare to stack
    std::queue<int> q;
    std::stack<int> s;
    q.push(1);
    q.push(2);
    q.push(3);
    
    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << "q.front(): " << q.front() << std::endl;
    std::cout << "s.top(): " << s.top() << std::endl;
  }

  // OMG! There is not begin and end!
  // for(auto it=s.begin(); it!=s.end(); ++it){

  // }

  return 0;
}