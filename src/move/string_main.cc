#include <string.h>

#include <iostream>
#include <vector>

class MyString {
 public:
  char* mData;
  size_t mSize;
  size_t mCapacity;

 public:
  MyString(const char* c) {
    mSize = strlen(c);
    mCapacity = mSize;
    mData = new char[mCapacity];
    memcpy(mData, c, mSize + 1);
  }

  MyString operator+(const MyString& rhs) {
    MyString tmp = *this;
    tmp.mSize += rhs.mSize;
    tmp.mCapacity += rhs.mCapacity;
    strcat(tmp.mData, rhs.mData);
    return (tmp);
  }

  MyString(const MyString& rhs) {
    mSize = rhs.mSize;
    mCapacity = rhs.mCapacity;
    mData = new char[mCapacity];
    memcpy(mData, rhs.mData, mSize + 1);
  }

  MyString(MyString&& rvalue) {
    mData = rvalue.mData;
    mSize = rvalue.mSize;
    mCapacity = rvalue.mCapacity;

    // Null so rvalue destructor won't delete the data
    rvalue.mData = nullptr;
  }
};

int main() {
  MyString a("123");
  MyString b("_456");

  MyString c = a + b;

  MyString d = std::move(a + b);

  std::cout << "c: " << c.mData << std::endl;
  std::cout << "d.mData: " << d.mData << std::endl;
  return 0;
}