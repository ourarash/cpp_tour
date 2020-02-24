#include "src/lib/tree.h"
#include "src/lib/utility.h"

#include <iostream>
#include <set>
#include <string>
#include <vector>

int main() {

  Tree t;
  t.CreateSampleTree2();
  std::cout << "InOrder:" << std::endl;
  t.InOrder(t.root_);
  std::cout << "PreOrder:" << std::endl;
  t.PreOrder(t.root_);
  std::cout << "PostOrder:" << std::endl;
  t.PostOrder(t.root_);

  return 0;
}