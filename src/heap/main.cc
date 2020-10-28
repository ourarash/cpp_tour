#include "src/lib/heap.h"

Heap ConvertToHeap(std::vector<int> &input) {
  Heap result_heap;

  for (int e : input) {
    result_heap.push(e);
  }
  return result_heap;
}