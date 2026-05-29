#include <iostream>

class BasicStackAlloc {
 public:
  // Constructs the stack allocator to requested size
  BasicStackAlloc(size_t size);
  // Destructor
  ~BasicStackAlloc();
  // Gets how many bytes are left in the stack
  size_t GetBytesRemaining() const;
  // Allocates the specified number of bytes, if available,
  // and returns a pointer to this allocation
  // Returns nullptr if not enough bytes are left
  void* Allocate(size_t size);
  // Disallow copy construction, assignment, and moves
  BasicStackAlloc(const BasicStackAlloc&) = delete;
  BasicStackAlloc& operator=(const BasicStackAlloc&) = delete;
  BasicStackAlloc(BasicStackAlloc&&) = delete;
  BasicStackAlloc& operator=(BasicStackAlloc&&) = delete;

 private:
  // Pointer to the beginning of the usable memory area of the stack
  char* mMemoryBuffer;
  // Pointer to top of stack
  char* mTop;
};

BasicStackAlloc::BasicStackAlloc(size_t size)
    : mMemoryBuffer(nullptr), mTop(nullptr) {
  std::cout << "Arena constructor size: " << size << std::endl;
  // Allocate specified bytes
  mMemoryBuffer = new char[size];
  // The "top" should be at the end of the buffer
  // (pointer arithmetic)
  mTop = mMemoryBuffer + size;
}

BasicStackAlloc::~BasicStackAlloc() {
  std::cout << "Arena destructor is called" << std::endl;

  delete[] mMemoryBuffer;
  mMemoryBuffer = nullptr;
  mTop = nullptr;
}
size_t BasicStackAlloc::GetBytesRemaining() const {
  return (mTop - mMemoryBuffer);
}

void* BasicStackAlloc::Allocate(size_t size) {
  // If we have enough space, move the top by the size
  // and return this address
  if (GetBytesRemaining() >= size) {
    mTop -= size;
    return mTop;
  } else {
    // Not enough space, so return null
    return nullptr;
  }
}

//-----------------------------------------------------

BasicStackAlloc arena(1000);
class Test {
 public:
  Test() { std::cout << "Constructor!" << std::endl; }
  ~Test() { std::cout << "Destructor!" << std::endl; }

  void Talk() { std::cout << "My name is Test!" << std::endl; }

  // Override operator "new" to allocate with malloc
  static void* operator new(size_t size) {
    std::cout << "Custom new!" << std::endl;
    std::cout << "size: " << size << std::endl;
    // return malloc(size);
    return arena.Allocate(size);
  }

  // Override operator "delete" to free with free
  static void operator delete(void* ptr) {
    std::cout << "Custom delete. No Free!" << std::endl;
    // free(ptr);
  }

  // NOTE: Should also overload new[] and delete[]
  int data_[10];
};

int main(int argc, char const* argv[]) {
  std::cout << "arena.GetBytesRemaining(): " << arena.GetBytesRemaining()
            << std::endl;
  {
    Test* myTest = new Test();
    myTest->Talk();
    // delete myTest;
  }
  std::cout << "arena.GetBytesRemaining(): " << arena.GetBytesRemaining()
            << std::endl;
  return 0;
}