#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class MyVector {
 public:
  MyVector() {
    //
    data_ = nullptr;
    size_ = 0;
  }

  ~MyVector() {
    //
    if (data_ != nullptr) {
      delete data_;
    }
  }

  void push_back(int i) {
    //
    int *new_data = new int[size_ + 1];
    //...

    delete data_;
    data_ = new_data;
  }

  int size() {
    //
    return size_;
  }

  int *data_;
  int size_;
};

class Point {
 public:
  // Non-parameterized constructor.
  Point() {
    i_ = 0;
    j_ = 0;
    ptr_ = new int;
    internal_ = 0;
    std::cout << "Default constructor!" << std::endl;
  }

  // Parameterized constructor.
  Point(int i) {
    i_ = i;
    j_ = 0;
    internal_ = 0;
    ptr_ = new int;
  }

  // Parameterized constructor.
  Point(int i, int j) {
    i_ = i;
    j_ = j;
    internal_ = 0;
    ptr_ = new int;
  }

  // Copy constructor
  Point(const Point &original) {
    i_ = original.i_;
    j_ = original.j_;
    ptr_ = new int;
    *ptr_ = *(original.ptr_);
    internal_ = original.internal_;
  }

  ~Point() {
    //
    std::cout << "Destructor!" << std::endl;
    // To avoid memory leak!
    delete ptr_;
  }

  int GetI() { return i_; };
  int GetJ() { return j_; };
  void SetI(int i) {
    if (i < 1000) {
      i_ = i;
    } else {
      std::cout << "Error!" << std::endl;
    }
  };
  void SetJ(int j) { j_ = j; };

  int Sum() { return i_ + j_; }
  float Length() { return Sqrt(i_ * i_ + j_ * j_); }

  int i_;
  int j_;
  int *ptr_;

 private:
  int internal_;
  float Sqrt(int x) { return std::sqrt(x); }
};

void F(Point local_p) {
  //
  std::cout << "Inside F. Pass by value" << std::endl;
  std::cout << "local_p.i_: " << local_p.i_ << ", local_p.j_: " << local_p.j_
            << std::endl;
}

void F_reference(Point &p) {
  std::cout << "Inside F. Pass by reference" << std::endl;
}

int DoSomething() {
  Point p1(1, 2);
  Point p2(3, 3);
  Point p3;
  return p1.Sum();
}

int main() {
  Point p;
  std::cout << "p.i_: " << p.i_ << ", p.j_: " << p.j_ << std::endl;

  p.SetI(100);
  F(p);
  F_reference(p);

  Point p1(1, 2);  // Constructor is called
  std::cout << "p1.i_: " << p1.i_ << ", p1.j_: " << p1.j_ << std::endl;

  std::cout << "p1.Sum(): " << p1.Sum() << std::endl;
  std::cout << "p1.Length(): " << p1.Length() << std::endl;

  Point p5(1);  // Constructor is called
  std::cout << "p5.i_: " << p5.i_ << ", p5.j_: " << p5.j_ << std::endl;

  Point p2(1, 2);  // Constructor is called

  // Initialization
  // Point p3 = p1;  // Copy constructor is called
  Point p3(p1);  // Copy constructor is called

  std::cout << "p3.i_: " << p3.i_ << ", p3.j_: " << p3.j_ << std::endl;

  Point p4;  // Constructor.
  p4 = p1;   // Copy assignment --> We will cover this later.
  std::cout << "p4.i_: " << p4.i_ << ", p4.j_: " << p4.j_ << std::endl;

  p4 = p2;
  p4 = p1;

  DoSomething();
  std::cout << "p4.Length(): " << p4.Length() << std::endl;

  {
    MyVector v;
    v.push_back(1);
  }
}
