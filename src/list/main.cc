#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "src/lib/utility.h"

int GetIndexValue(const std::list<int> &l, int index) {
  auto it = l.begin();

  std::advance(it, index);
  int data = *it;
  return data;
}

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

  for (auto it = l.begin(); i != l.end(); ++it) {
    std::cout << "*it: " << *it << std::endl;
  }

  // Printing item 4:
  auto it = l.begin();
  for (int i = 0; i < 4; i++) {
    ++it;
  }
  std::cout << "*it: " << *it << std::endl;

  // Print(l);

  auto it = l.begin();

  std::advance(it, 4);
  int data = *it;

  std::cout << "data: " << data << std::endl;

  l.insert(it, 100);
  Print(l);

  // int value = GetIndexValue(l, 5);

  // std::cout << "value: " << value << std::endl;
  // auto it = l.begin();
  // auto it_next = std::next(it, 1);

  return 0;
}