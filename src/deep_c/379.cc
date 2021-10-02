#include <stdio.h>

struct A {
  A() { puts("A()"); }
  A(int v) { puts("A(int)"); }
  ~A() { puts("~A()"); }
};
struct X {
  X(int v) { a = v; }
  X(long v) : a(v) {}
  A a;
};
int main() {
  puts("bad style");
  { X slow(int(2)); }
  puts("good style");
  { X fast(long(2)); }
}