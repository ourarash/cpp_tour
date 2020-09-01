#include <iostream>
#include <list>
#include <set>
#include <vector>

int main() {
  std::cout << "Size of int8_t: " << sizeof(int8_t) << " byte" << std::endl;

  std::cout << "Size of size_t: " << sizeof(size_t) << " byte" << std::endl;

  std::cout << "Size of int16_t: " << sizeof(int16_t) << " byte" << std::endl;
  std::cout << "Size of int32_t: " << sizeof(int32_t) << " byte" << std::endl;
  std::cout << "Size of int64_t: " << sizeof(int64_t) << "byte" << std::endl;
  std::cout << "Size of uint8_t: " << sizeof(uint8_t) << " byte" << std::endl;
  std::cout << "Size of uint16_t: " << sizeof(uint16_t) << " byte" << std::endl;
  std::cout << "Size of uint32_t: " << sizeof(uint32_t) << " byte" << std::endl;
  std::cout << "Size of uint64_t: " << sizeof(uint64_t) << " byte" << std::endl;

  std::vector<int> v;
  std::cout << "Size of v: " << sizeof(v) << " byte" << std::endl;
  std::cout << "v.size(): " << v.size() << std::endl;

  v.push_back(1);

  std::cout << "Size of v: " << sizeof(v) << " byte" << std::endl;
  std::cout << "v.size(): " << v.size() << std::endl;

  v.push_back(1);

  std::cout << "Size of v: " << sizeof(v) << " byte" << std::endl;
  std::cout << "v.size(): " << v.size() << std::endl;

  std::list<int> l;
  std::cout << "Size of l: " << sizeof(l) << " byte" << std::endl;
  std::cout << "l.size(): " << l.size() << std::endl;

  l.push_back(100);
  std::cout << "Size of l: " << sizeof(l) << " byte" << std::endl;
  std::cout << "l.size(): " << l.size() << std::endl;

  std::set<int> s;
  std::cout << "Size of s: " << sizeof(s) << " byte" << std::endl;
  std::cout << "s.size(): " << s.size() << std::endl;
  s.insert(100);
  std::cout << "Size of s: " << sizeof(s) << " byte" << std::endl;
  std::cout << "s.size(): " << s.size() << std::endl;

  return 0;
}