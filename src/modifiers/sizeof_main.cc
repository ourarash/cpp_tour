#include <iostream>

int main() {
  // Pointer size
  {
    int* ptr;

    std::cout << "Size of ptr : " << sizeof(ptr) << " byte" << std::endl;
  }
  {
    int* ptr;
    ptr = new int[10];

    std::cout << "Size of ptr : " << sizeof(ptr) << " byte" << std::endl;
  }

  // Array size
  {
    int array[10];

    std::cout << "Size of array : " << sizeof(array) << " byte" << std::endl;
  }

  // Struct size padding
  {
    class Test1 {
      char c;
      int i;
    };

    std::cout << "Size of Test1 : " << sizeof(Test1) << " byte" << std::endl;
  }

  // Struct size padding
  {
    class Test2 {
      char c;
      uint64_t i;
    };

    std::cout << "Size of Test2 : " << sizeof(Test2) << " byte" << std::endl;
  }

  // Struct size padding
  {
    class Test3 {
      char c;
      uint64_t i;
      char d;
    };

    std::cout << "Size of Test3 : " << sizeof(Test3) << " byte" << std::endl;
  }

  {
    class Test4 {
      char d;
      char c;
      uint64_t i;
    };

    std::cout << "Size of Test4 : " << sizeof(Test4) << " byte" << std::endl;
  }

  // EmptyClass
  {
    class EmptyClass {};

    std::cout << "Size of EmptyClass : " << sizeof(EmptyClass) << " byte"
              << std::endl;
  }

  // EmptyClass
  {
    class EmptyClass {};
    class Derived : public EmptyClass {
      int i;
    };

    std::cout << "Size of EmptyClass : " << sizeof(EmptyClass) << " byte"
              << std::endl;

    std::cout << "Size of Derived : " << sizeof(Derived) << " byte"
              << std::endl;
  }

  // VirtualClass
  {
    class VirtualClass {
      virtual void F();
      int i;
    };

    std::cout << "Size of VirtualClass : " << sizeof(VirtualClass) << " byte"
              << std::endl;
  }

  // VirtualClass
  {
    class A {
     public:
      virtual void a();
      virtual void b();
      virtual ~A();
    };

    class B : public A {
     public:
      virtual void a();
      virtual void c();
      virtual ~B();
    };

    std::cout << "Size of A : " << sizeof(A) << " byte" << std::endl;
    std::cout << "Size of B : " << sizeof(B) << " byte" << std::endl;
  }

  // VirtualClass
  {
    class X {
      int a;

     public:
      virtual void x();
      void y();
      virtual void z();
      virtual ~X();
    };

    class Y : public X {
      char b;

     public:
      virtual void z() override;
    };

    std::cout << "Size of X : " << sizeof(X) << " byte" << std::endl;
    std::cout << "Size of Y : " << sizeof(Y) << " byte" << std::endl;
  }

  {
    class A {
     public:
      virtual void f();

     private:
      char c;
      double d;
    };

    std::cout << "Size of A : " << sizeof(A) << " byte" << std::endl;
  }

  {
    std::cout << "sizeof(double): " << sizeof(double) << std::endl;
  }
  return 0;
}