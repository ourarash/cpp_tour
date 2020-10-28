#include <iostream>

BasicStackAlloc arena;
class Test {
 public:
  Test() { std::cout << "Constructor!" << std::endl; }
  ~Test() { std::cout << "Destructor!" << std::endl; }

  // Override operator "new" to allocate with malloc
  static void* operator new(size_t size) {
    std::cout << "Custom new!" << std::endl;
    std::cout << "size: " << size << std::endl;
    // return malloc(size);
    return arena.Allocate(size);
  }

  // Override operator "delete" to free with free
  static void operator delete(void* ptr) {
    std::cout << "Custom delete!" << std::endl;
    free(ptr);
  }

  // NOTE: Should also overload new[] and delete[]
  int data_[10];
};

int main(int argc, char const* argv[]) {
  Test* myTest = new Test();
  delete myTest;

  return 0;
}
