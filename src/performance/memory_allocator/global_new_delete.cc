#include <cstdio>
#include <cstdlib>
#include <new>
// replacement of a minimal set of functions:
void* operator new(
    std::size_t sz)  // no inline, required by [replacement.functions]/3
{
  std::printf("global op new called, size = %zu\n", sz);
  if (sz == 0)
    ++sz;  // avoid std::malloc(0) which may return nullptr on success

  if (void* ptr = std::malloc(sz)) return ptr;

  throw std::bad_alloc{};  // required by [new.delete.single]/3
}
void operator delete(void* ptr) noexcept {
  std::puts("global op delete called");
  std::free(ptr);
}
int main() {
  int* p1 = new int;
  delete p1;

  int* p2 = new int[10];  // guaranteed to call the replacement in C++11
  delete[] p2;
}