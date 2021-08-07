#include <iostream>
class Base {
 public:
  Base() : private_member_(0) { std::cout << "Base!" << std::endl; }
  void Talk() { std::cout << "Base talking!" << std::endl; }
  virtual void Speak() { std::cout << "Base speaking!" << std::endl; }
  ~Base() { std::cout << "Base destructor!" << std::endl; }

  int GetPrivateMember() { return private_member_; }

 protected:
  int protected_member_;
  int ProtectedMethod() { return 0; }

 private:
  int PrivateFunction() {
    std::cout << "PrivateFunction" << std::endl;
    return 0;
  }
  int private_member_;
};

class BaseWithVirtualDestructor {
 public:
  BaseWithVirtualDestructor() { std::cout << "Base!" << std::endl; }
  void Talk() { std::cout << "Base talking!" << std::endl; }
  virtual void Speak() { std::cout << "Base speaking!" << std::endl; }
  virtual ~BaseWithVirtualDestructor() {
    std::cout << "Base destructor!" << std::endl;
  }
};

class Derived : public Base {
 public:
  Derived() { std::cout << "Derived!" << std::endl; }

  void Talk() { std::cout << "Derived talking!" << std::endl; }

  // Virtual-ness propagates:
  // "If a class has a base class with a virtual destructor, its destructor
  // (whether user- or implicitly- declared) is virtual.
  // So Speak and ~Derived will be virtual no matter if we specify it here or
  // not.
  void Speak() { std::cout << "Derived speaking!" << std::endl; }
  ~Derived() { std::cout << "Derived destructor!" << std::endl; }

  void TestingAccessesToBase() {
    protected_member_++;
    // Doesn't compile, although it is part of this
    // object!
    // private_member_++;
  }
};

class DerivedWithVirtualDestructor : public BaseWithVirtualDestructor {
 public:
  DerivedWithVirtualDestructor() { std::cout << "Derived!" << std::endl; }

  void Talk() { std::cout << "Derived talking!" << std::endl; }

  // Virtual-ness propagates:
  // "If a class has a base class with a virtual destructor, its destructor
  // (whether user- or implicitly- declared) is virtual.
  // So Speak and ~Derived will be virtual no matter if we specify it here or
  // not.
  void Speak() { std::cout << "Derived speaking!" << std::endl; }
  ~DerivedWithVirtualDestructor() {
    std::cout << "Derived destructor!" << std::endl;
  }
};

class Derived2 : public Derived {
 public:
  Derived2() { std::cout << "Derived2!" << std::endl; }

  void Talk() { std::cout << "Derived2 talking!" << std::endl; }
  void Speak() { std::cout << "Derived2 speaking!" << std::endl; }
  ~Derived2() { std::cout << "Derived2 destructor!" << std::endl; }
};

int main() {
  {
    Derived d;
    std::cout << "d.GetPrivateMember(): " << d.GetPrivateMember() << std::endl;
    // d.PrivateFunction();  // Won't compile
    // d.private_member_++;  // Won't compile

    // However, the getters work (because they are public.)
    // A derived class doesn't inherit *access* to private data members.
    // However, it does inherit a full parent object, which contains any private
    // members which that class declares.
    std::cout << "d.GetPrivateMember(): " << d.GetPrivateMember() << std::endl;
  }
  {
    Base *b = new Derived();
    b->Talk();
    b->Speak();
    delete b;
  }
  std::cout << "------------------------------------------" << std::endl;

  {
    BaseWithVirtualDestructor *b = new DerivedWithVirtualDestructor();
    b->Talk();
    b->Speak();

    delete b;
  }
  std::cout << "------------------------------------------" << std::endl;
  {
    Base *b = new Derived2();
    b->Talk();
    b->Speak();

    delete b;
  }
  std::cout << "------------------------------------------" << std::endl;
  {
    Derived d;
    d.Talk();
    {
      Base &b = d;
      b.Talk();
      b.Speak();
    }
    std::cout << "------------------------------------------" << std::endl;
  }
  std::cout << "------------------------------------------" << std::endl;
  {
    Derived2 d;
    d.Talk();
    Base &b = d;
    b.Talk();
    b.Speak();
  }
  return 0;
}