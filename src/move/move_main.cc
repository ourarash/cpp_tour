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

  // Non-Default constructor
  MyString(const char *data, size_t size) {
    std::cout << "Non-Default constructor was called." << std::endl;
    data_ = new char[size];
    size_ = size;
    for (size_t i = 0; i < size; i++) {
      this->data_[i] = data[i];
    }
  }

  // Copy constructor
  MyString(const MyString &obj) {
    std::cout << "Copy constructor was called." << std::endl;

    this->data_ = new char[obj.size_];
    this->size_ = obj.size_;
    for (size_t i = 0; i < obj.size_; i++) {
      this->data_[i] = obj.data_[i];
    }
  }

  // Move constructor
  // MyString(MyString &&obj) {
  //   std::cout << "Move constructor was called." << std::endl;
  //   this->data_ = obj.data_;
  //   this->size_ = obj.size_;
  //   obj.data_ = nullptr;
  //   obj.size_ = 0;
  // }

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
  // Using std::move with built-in variables.
  {
    int a = 10;
    auto b = a;
    auto c = std::move(a);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << std::endl;
  }

  // Using std::move with non-built-in variables.
  {
    std::cout << "------------------------------------------" << std::endl;
    std::string a = "string_a";
    auto b = a;
    auto c = std::move(a);
    auto d = a + a;
    auto e = std::move(a + a);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << std::endl;
  }

  // Using std::move with non-built-in variables.
  {
    std::cout << "------------------------------------------" << std::endl;
    MyString a("MyString_a", strlen("MyString_a"));

    MyString b = a;
    MyString c(a);
    MyString d = std::move(a);

    std::cout << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << std::endl;
  }

  // Using std::move with non-built-in variables.
  {
    std::cout << "------------------------------------------" << std::endl;
    std::string a = "string_a";
    auto b = a;
    auto c = a + a;
    auto d = std::move(a + a);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << std::endl;
  }

  // Using std::move with non-built-in variables.
  {
    std::cout << "------------------------------------------" << std::endl;
    MyString a("MyString_a", strlen("MyString_a"));

    MyString b = a;

    MyString c(a);

    MyString d = std::move(a);
    std::cout << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    std::cout << std::endl;
  }

  // Using std::move with non-built-in variables.
  {
    std::cout << "------------------------------------------" << std::endl;
    MyString a("MyString_a", strlen("MyString_a"));
    MyString b("MyString_b", strlen("MyString_b"));

    MyString c = a + b;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl;
  }
  return 0;
}