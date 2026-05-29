#include <iostream>

class String_1 {
 public:
  String_1(const char* str)
      : mSize(std::strlen(str)),
        mCapacity(mSize > 19 ? mSize + 1 : 20),
        mData(new char[mSize + 1]) {
    // Copy from string literal into data
    std::memcpy(mData, str, mSize + 1);
  }

 private:
  size_t mSize;
  size_t mCapacity;
  char* mData;
};

class String {
 public:
  String(const char* str) {
    size_t len = std::strlen(str);
    // If the str is short enough, we can use the "small" string
    if (len <= 21) {
      mStr.Small.mIsSmallString = true;
      mStr.Small.mSize = len;
      std::memcpy(mStr.Small.mData, str, len + 1);
    } else {
      // We have to use "large" string :(
      mStr.Large.mSize = len;
      mStr.Large.mCapacity = len + 1;
      mStr.Large.mData = new char[mStr.Large.mCapacity];
      std::memcpy(mStr.Large.mData, str, len + 1);
    }
  }

  size_t Capacity() const {
    if (mStr.Small.mIsSmallString) {
      return 22;
    } else {
      return mStr.Large.mCapacity;
    }
  }

 private:
  union {
    struct {
      char* mData;
      size_t mCapacity;
    } Large;
    struct {
      char mData[22];

    } Small;
  } mStr;

  size_t mSize;

  // bool mIsSmallString;
};

String f() {
  String a;
  return a;
}

#include "lib.h"

int main(int argc, char const* argv[]) {
  String small("Hello");
  String large("This string is so long omgggggggg");

  {
    String y;
    String x = f(y);
  }
  return 0;
}
