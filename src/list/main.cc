#include "src/lib/utility.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
  std::list<int> l;

  l.push_back(1);
  l.push_back(2);
  l.push_back(3);
  l.push_back(4);
  l.push_back(5);
  l.push_back(6);
  l.push_back(7);
  l.push_back(8);
  l.push_back(9);
  Print(l);

  auto it = l.begin();

  std::advance(it, 5);
  int data = *it;

  std::cout << "data: " << data << std::endl;

  auto it = l.begin();
  auto it_next = std::next(it, 1);

  return 0;
}