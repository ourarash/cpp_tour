#include "src/lib/linked_list.h"
#include "src/lib/utility.h"

#include <iostream>
#include <list>
#include <string>
#include <vector>

int main() {
  SinglyLinkedList l;
  l.push_back(1);
  l.push_back(2);
  std::cout << "l.size(): " << l.size() << std::endl;

  l.push_back(3);
  l.print();
  std::cout << "l.size(): " << l.size() << std::endl;

  SinglyLinkedList l2 = l;
  
  // Test [] operator
  l.print();
  int item = l[0];
  std::cout << "l[0]: " << l[0] << ", l[1]: " << l[1] << ", l[2]: " << l[2]
            << std::endl;
  l[0] += 2;
  l.print();

  return 0;
}