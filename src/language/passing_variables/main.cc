#include <iostream>
#include <string>

// Acts like int j = i
void PassByValue(int j) { j++; }

// Acts like int *j = &i;
void PassByReferenceUsingPointer(int *j) { (*j)++; }

// Acts like int &j = i;
void PassByReferenceUsingReference(int &j) { j++; }

int main() {
  int i = 10;

  int j[100];

  std::vector<int> v;

  for (int i = 0; i < 100000; i++) {
    v.push_back(10);
  }
  PassByValue(i);
  std::cout << "i: " << i << std::endl;

  PassByReferenceUsingPointer(&i);
  std::cout << "i: " << i << std::endl;

  PassByReferenceUsingReference(i);
  std::cout << "i: " << i << std::endl;

  return 0;
}
