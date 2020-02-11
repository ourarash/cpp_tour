#include "src/lib/bst.h"
#include "src/lib/utility.h"

#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {

  BST t;

  t.insert(t.root_, 8);
  t.insert(t.root_, 3);
  t.insert(t.root_, 10);
  t.insert(t.root_, 2);
  t.insert(t.root_, 5);
  t.insert(t.root_, 4);
  t.insert(t.root_, 7);
  t.insert(t.root_, 14);
  t.insert(t.root_, 12);

  t.InOrder(t.root_);

  auto r1 = t.search(t.root_, 14);
  std::cout << "r1: " << r1 << std::endl;
  auto r2 = t.search(t.root_, 100);
  std::cout << "r2: " << r2 << std::endl;
  return 0;
}