class Base {
 private:
  int x;

 public:
  virtual void mf1() = 0;
  virtual void mf1(int);
  virtual void mf2();
  void mf3();  //-->
  void mf3(double);
};
class Derived : public Base {
 public:
  // using Base::mf1; // make all things in Base named mf1 and mf3
  // using Base::mf3; // visible (and public) in Derived's scope

  virtual void mf1();
  void mf3();  //--> hides both mf3 in Base
  void mf4();
};
int main(int argc, char const *argv[]) {
  /* code */
  Derived d;
  // d.mf3(5.5);  // --> Doesn't compile unles we have "using" statements
  d.Base::mf3(5.5);  // -> Compiles
  return 0;
}
