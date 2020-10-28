#include <iostream>
class Foo {
 public:
  // single parameter constructor, can be used as an implicit conversion
  Foo(int foo) : m_foo(foo) {}

  int GetFoo() { return m_foo; }

 private:
  int m_foo;
};

int DoBar(Foo foo) {
  int i = foo.GetFoo();
  return i;
}

//-----------------------------------------------------
int main() {
  auto i = DoBar(42);
  std::cout << "i: " << i << std::endl;
}