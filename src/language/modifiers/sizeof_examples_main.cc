#include <iostream>

int main() {
  {
    std::cout << "sizeof(bool): " << sizeof(bool) << std::endl;
  }
  {
    struct {
      char mData[22];
      char mSize;
      bool mIsSmallString;
    } Small;

    std::cout << "sizeof(Small): " << sizeof(Small) << std::endl;
  }
  {
    struct X {
      // vtable* ptr;  --->   8 bytes
      int a;  //=============> 4 bytes, padding

      virtual void f();
      virtual void g();
      void h1();
      void h2();

      virtual ~X();
    };

    struct Y : X {
      double b;
      void f() override;
      virtual void i();
      ~Y();
    };

    struct Z : Y {
      char c;
      char d;
      int e;
      void g() override;
      ~Z();
    };

    std::cout << "sizeof(X): " << sizeof(X) << std::endl;
    std::cout << "sizeof(Y): " << sizeof(Y) << std::endl;
    std::cout << "sizeof(Z): " << sizeof(Z) << std::endl;
  }
}