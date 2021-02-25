#include <string.h>

#include <iostream>
#include <vector>

class MyString {
 public:
  // Default constructor
  MyString() {
    std::cout << "Default constructor was called." << std::endl;
    data_ = new char;
    size_ = 0;
  }

  MyString(const char *c) {
    std::cout << "Non-Default constructor 1 is called." << std::endl;

    size_ = strlen(c);
    data_ = new char[size_ + 1];
    memcpy(data_, c, size_ + 1);
  }

  // Non-Default constructor
  MyString(const char *data, size_t size) {
    std::cout << "Non-Default constructor 2 was called." << std::endl;
    data_ = new char[size];
    size_ = size;
    for (size_t i = 0; i < size; i++) {
      this->data_[i] = data[i];
    }
  }

  // Copy constructor
  MyString(const MyString &rhs) {
    std::cout << "Copy constructor was called." << std::endl;

    this->data_ = new char[rhs.size_];
    this->size_ = rhs.size_;
    for (size_t i = 0; i < rhs.size_; i++) {
      this->data_[i] = rhs.data_[i];
    }
  }

  // Move constructor
  // rhs can be an rvalue, e.g.: (a + 1)
  MyString(MyString &&rhs) {
    std::cout << "Move constructor was called." << std::endl;
    this->data_ = rhs.data_;
    this->size_ = rhs.size_;
    rhs.data_ = nullptr;
    rhs.size_ = 0;
  }

  // void Example() {
  //   MyString b;
  //   {
  //     MyString a;
  //     b = std::move(a);
  //   }
  //   // ->>>>> a is destructed ->> b to be invalid
  // }
  void IOnlyTakeLvalue(MyString &rhs) {
    std::cout << "IOnlyTakeLvalue" << std::endl;
  }

  ~MyString() {
    // std::cout << "Destructor was called." << std::endl;
    size_ = 0;
    delete data_;
  }

  // Adds two MyString objects.
  MyString operator+(const MyString &rhs) {
    MyString tmp;
    tmp.size_ = size_ + rhs.size_;
    tmp.data_ = new char[tmp.size_];

    for (size_t i = 0; i < size_; i++) {
      tmp.data_[i] = data_[i];
    }

    for (size_t i = size_; i < size_ + rhs.size_; i++) {
      tmp.data_[i] = rhs.data_[i - size_];
    }
    return tmp;
  }

  void Push(char c) {
    char *new_data = new char[size_ + 1];
    size_t new_size = size_ + 1;
    for (size_t i = 0; i < size_; i++) {
      new_data[i] = data_[i];
    }
    new_data[new_size - 1] = c;
  }

  friend std::ostream &operator<<(std::ostream &out, const MyString &c);

 public:
  char *data_;
  size_t size_;
};

std::ostream &operator<<(std::ostream &out, const MyString &c) {
  if (c.data_) {
    for (size_t i = 0; i < c.size_; i++) {
      out << c.data_[i];
    }
  }
  return out;
}

int main() {
  MyString a("123");
  MyString b("_456");

  MyString c = a + b;

  std::cout << "a: " << a << std::endl;
  std::cout << "b: " << b << std::endl;
  std::cout << "c: " << c << std::endl;

  MyString e = a;             // Calls copy constructor.
  MyString d = std::move(a);  // Casts a as an rvalue THEREFORE the move
                              // constructor should be called.

  std::cout << "a: " << a << ", e: " << e << ", d: " << d << std::endl;

  {
    MyString a("Hello!");
    MyString b = a;
  }

  {
    MyString a("Hello!");
    MyString b = std::move(a);
  }

  {
    MyString a("Hello!");
    MyString b = std::move(a);
    MyString &c = (a + b);
  }

  return 0;
}
