#include <iostream>
#include <memory>

struct B;
struct A {
  std::shared_ptr<B> b;
  ~A() { std::cout << "~A()\n"; }
};

struct B {
  std::shared_ptr<A> a;
  ~B() { std::cout << "~B()\n"; }
};

// At the end of this the destructors won't be called!
void useAnB() {
  auto a = std::make_shared<A>();
  auto b = std::make_shared<B>();
  a->b = b;
  b->a = a;
}

int main() {
  {
    useAnB();
    std::cout << "Finished using A and B\n";
  }
  std::cout << "------------------------------------------" << std::endl;
  {
    struct A {
      A() { std::cout << "A constructor" << std::endl; }
      ~A() { std::cout << "A destructor" << std::endl; }
    };
    struct B {
      B(std::shared_ptr<A> ptr) : mPtr(ptr) {
        std::cout << "B constructor" << std::endl;
      }

      ~B() { std::cout << "B destructor" << std::endl; }

     private:
      std::shared_ptr<A> mPtr;
    };

    // Then...
    std::shared_ptr<B> ptrB;
    {
      std::shared_ptr<A> ptrA = std::make_shared<A>();
      ptrB = std::make_shared<B>(ptrA);
    }
  }
}