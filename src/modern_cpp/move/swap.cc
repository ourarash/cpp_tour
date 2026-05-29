#include <utility>
template <typename T>
void SwapMove(T& a, T& b) {
  T t(std::move(a));

  a = std::move(b);

  b = std::move(t);
}

template <typename T>
void Swap(T& a, T& b) {
  T t(a);
  a = b;
  b = t;
}