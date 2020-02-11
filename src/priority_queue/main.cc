#include "src/lib/utility.h"
#include <iostream>
#include <queue>
#include <string>

int main() {

  {
    // max heap
    std::priority_queue<int> q;

    q.push(5);
    q.push(15);
    q.push(1);

    q.push(42);
    q.push(3);
    q.push(2);

    // One by one extract items from max heap
    while (q.empty() == false) {
      std::cout << q.top() << std::endl;
      q.pop();
    }
  }
  std::cout << "Output min heap" << std::endl;
  {
    // min heap
    std::priority_queue <int, std::vector<int>, std::greater<int> > q; 

    q.push(5);
    q.push(15);
    q.push(1);

    q.push(42);
    q.push(3);
    q.push(2);

    // One by one extract items from max heap
    while (q.empty() == false) {
      std::cout << q.top() << std::endl;
      q.pop();
    }
  }
  return 0;
}