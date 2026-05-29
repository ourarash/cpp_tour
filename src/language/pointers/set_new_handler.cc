#include <iostream>
#include <string>
// function to call if operator new can't allocate enough memory
void outOfMem() {
  std::cout << "Unable to satisfy request for memory\n";
  std::abort();
}
int main() {
  std::set_new_handler(outOfMem);
  int *pBigDataArray = new int[100000000000000L];
  pBigDataArray[5]=2;
  std::cout << "sizeof: " << sizeof(pBigDataArray) << std::endl;
}