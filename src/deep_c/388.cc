#include<iostream>
struct base {
  virtual void f(){std::cout << "base f" << std::endl;}
  virtual void g(){std::cout << "base g" << std::endl;}
  int a, b;
};

struct derived : base {
  virtual void g(){std::cout << "derrived g" << std::endl;}
  virtual void h(){std::cout << "derrived h" << std::endl;}
  int c;
};

void poly(base *ptr) {
  ptr->f();
  ptr->g();
}

int main() {
  base *b = new base();
  base *d = new derived();
  poly(b);
  poly(d);
}