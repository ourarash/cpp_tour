#include<iostream>
#include <cstddef>
#include <iterator>

class Integers {
 public:
  struct Iterator {
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = int;
    using pointer = int*;
    using reference = int&;

    Iterator(pointer ptr) : m_ptr(ptr) {}

    reference operator*() const { return *m_ptr; }
    pointer operator->() { return m_ptr; }
    Iterator& operator++() {
      m_ptr++;
      return *this;
    }
    Iterator operator++(int) {
      Iterator tmp = *this;
      ++(*this);
      return tmp;
    }
    friend bool operator==(const Iterator& a, const Iterator& b) {
      return a.m_ptr == b.m_ptr;
    };
    friend bool operator!=(const Iterator& a, const Iterator& b) {
      return a.m_ptr != b.m_ptr;
    };

   private:
    pointer m_ptr;
  };

  Iterator begin() { return Iterator(&m_data[0]); }
  Iterator end() { return Iterator(&m_data[5]); }

 private:
  int m_data[5];
};

int main(int argc, char const* argv[]) {
  Integers integers;

  for (auto it = integers.begin(), end = integers.end(); it != end; ++it) {
    const auto i = *it;
    std::cout << i << "\n";
  }
  /* code */
  return 0;
}
