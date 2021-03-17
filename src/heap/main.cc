#include <iostream>
#include <vector>

#include "src/lib/heap.h"
#include "src/lib/utility.h"  // Necessary for PrintVector
Heap ConvertToHeap(const std::vector<int> &input) {
  Heap result_heap;

  for (int e : input) {
    result_heap.push(e);
  }
  return result_heap;
}

// We remove N-k items from the heap. What remains are k largest items.
std::vector<int> ReturnLargestItems(const std::vector<int> &input, int k) {
  std::vector<int> result;
  auto heap = ConvertToHeap(input);

  // Remove N - k items
  for (int i = 0; i < input.size() - k; i++) {
    heap.pop();
  }

  // Return the remaining k items.
  while (!heap.empty()) {
    result.push_back(heap.top());
    heap.pop();
  }

  return result;
}

int main(int argc, char const *argv[]) {
  std::vector<int> input = {1, 20, 5, 8, -7};
  auto res1 = ReturnLargestItems(input, 3);
  Print(res1);

  {
    std::vector<int> input = {1, 2, 3, 5, 4};
    auto res1 = ReturnLargestItems(input, 3);
    Print(res1);
  }

  {
    std::vector<int> input = {5, 6, 1, 2, 3};
    auto res1 = ReturnLargestItems(input, 3);
    Print(res1);
  }
  // Heap heap = ConvertToHeap(input);

  // while (!heap.empty()) {
  //   auto top = heap.top();
  //   std::cout << "top: " << top << std::endl;
  //   heap.pop();
  // }

  return 0;
}
