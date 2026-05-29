#include <iostream>

class Test {
 public:
  // Test() { std::cout << "Constructor!" << std::endl; }
  Test() {
    std::cout << "Constructor throws!" << std::endl;
    throw std::runtime_error("");
  }

  ~Test() { std::cout << "Destructor!" << std::endl; }
  // Override operator "new" to allocate with malloc
  static void* operator new(size_t size) {
    std::cout << "Custom new, size: " << size << std::endl;

    return malloc(size);
  }
  // Override operator "delete" to free with free
  static void operator delete(void* ptr) {
    std::cout << "Custom delete!" << std::endl;
    free(ptr);
  }
  // NOTE: Should also overload new[] and delete[]

  int i_;
};
//-----------------------------------------------------------------------------
class Base {
 public:
  static void* operator new(std::size_t size,         // this new hides
                            std::ostream& logStream)  // the normal
      ;                                               // global forms
};

class Derived : public Base {  // inherits from Base above
 public:
  static void* operator new(std::size_t size)  // redeclares the normal
      ;                                        // form of new
};
//-----------------------------------------------------------------------------
class StandardNewDeleteForms {
 public:
  // normal new/delete
  static void* operator new(std::size_t size) { return ::operator new(size); }
  static void operator delete(void* pMemory) { ::operator delete(pMemory); }
  // placement new/delete
  static void* operator new(std::size_t size, void* ptr) {
    return ::operator new(size, ptr);
  }
  static void operator delete(void* pMemory, void* ptr) {
    return ::operator delete(pMemory, ptr);
  }
  // nothrow new/delete
  static void* operator new(std::size_t size, const std::nothrow_t& nt) {
    return ::operator new(size, nt);
  }
  static void operator delete(void* pMemory, const std::nothrow_t&) {
    ::operator delete(pMemory);
  }
};

class Widget : public StandardNewDeleteForms {  // inherit std forms
 public:
  using StandardNewDeleteForms::operator new;         // make those
  using StandardNewDeleteForms::operator delete;      // forms visible
  static void* operator new(std::size_t size,         // add a custom
                            std::ostream& logStream)  // placement new
      ;
  static void operator delete(
      void* pMemory,             // add the corresstd::
      std::ostream& logStream);  // ponding placethrow();
                                 // ment delete
};
//-----------------------------------------------------------------------------
int main(int argc, char const* argv[]) {
  try {
    Test* myTest = new Test();
    delete myTest;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  {
    // Base* pb = new Base;  // error! the normal form of
    // operator new is hidden
  }
  {
    Base* pb = new (std::cerr) Base;  // fine, calls Base's
    // placement new
  }
  {
    // Derived* pd = new (std::clog) Derived;  // error! Base's placement
    // new is hidden}
    {
      Derived* pd = new Derived;  // fine, calls Derived's
      // operator new
    }
    return 0;
  }
}
