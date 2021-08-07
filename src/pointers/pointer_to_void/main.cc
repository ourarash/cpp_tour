// including c++ input and output libraries
#include <iostream>
using namespace std;
// main method for run c++ application
int main() {
  // declaring void pointer
  void* pointer;
  // declaring and initializing float variable
  float money = 55.50;
  // initializing void pointer variable
  pointer = &money;  // converting float to void pointer
  // displaying output
  cout << &money
       << endl;  // displayed money address, it may varied from system to system
  // displaying output
  cout << pointer << endl;  // displayed pointer address, it may varied from
                            // system to system
  return 0;
}