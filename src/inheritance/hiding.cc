class Base {
 private:
  int x;

 public:
  virtual void mf1() = 0;
  virtual void mf1(int);
  virtual void mf2();
  void mf3();
  void mf3(double);
};
class Derived : public Base {
 public:
  // using Base::mf1;  // make all things in Base named mf1 and mf3
  // using Base::mf3;  // visible (and public) in Derived's scope
  virtual void mf1();
  void mf3();
  void mf4();
};

int main(int argc, char const *argv[]) {
  Derived d;
  int x;
  d.mf1();   // fine, calls Derived::mf1
  d.mf1(x);  // error! Derived::mf1 hides Base::mf1
  d.mf2();   // fine, calls Base::mf2
  d.mf3();   // fine, calls Derived::mf3
  d.mf3(x);  // error! Derived::mf3 hides Base::mf3
  return 0;
}
