#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
//-----------------------------------------------------
class Test {
 public:
 private:
  int x = 5;     // Works
  int y = {25};  // Works
  int z{125};    // Works
  //  int a(125);     // ERROR!
};

template <typename T>
class DynArray {
 public:
  // Functions here ...
  // Default Constructor
  DynArray() : mSize(10) { mData = new T[mSize]; }
  // Destructor
  ~DynArray() { delete[] mData; }
  // Constructor to specify initial size
  DynArray(size_t size) : mSize(size) { mData = new T[mSize]; }

  // Initializer list constructor
  DynArray(const std::initializer_list<T>& list) {
    mSize = list.size();
    mData = new T[mSize];
    int i = 0;
    for (const T& val : list) {
      mData[i] = val;
      i++;
    }
  }

 private:
  size_t mSize;
  T* mData;
};

int main(int argc, char const* argv[]) {
  // Calls the initializer list constructor
  DynArray<int> test{5, 10, 15, 20, 25};

  // This STILL calls the initializer list constructor
  // (Creates a list of size 1 with the value 5)
  DynArray<int> test2{5};

  // To call the constructor that takes the initial size
  // only, you have to use the old syntax...
  // (Creates a list of size 5 with no data)
  DynArray<int> test3(5);

  std::vector<int> my_vector(10);   // vector of 10 items
  std::vector<int> my_vector2{10};  // A vector of one value which is 10

  return 0;
}
