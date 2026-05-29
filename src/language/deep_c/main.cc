#include <stdio.h>
struct X {
  int a;
  char b;
  int c;
  char* d;
};
int main(void) {
  printf("%zu\n", sizeof(int));
  printf("%zu\n", sizeof(char));
  printf("%zu\n", sizeof(struct X));
}