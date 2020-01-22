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

  PassByValue(i);
  std::cout << "i: " << i << std::endl;

  PassByReferenceUsingPointer(&i);
  std::cout << "i: " << i << std::endl;

  PassByReferenceUsingReference(i);
  std::cout << "i: " << i << std::endl;

  return 0;
}