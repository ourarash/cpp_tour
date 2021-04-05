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

using namespace std;
std::vector<int> ReturnLargestItems2(const std::vector<int> &input, int k) {
  int n = input.size();
  int j = n - k;
  // #convert to min heap, assume this function is min heap convert function.
  auto minheap = ConvertToHeap(input);
  std::vector<int> output;
  for (int i = 0; i < n; i++) {
    
    auto value = minheap.top();
    minheap.pop();
    if (i >= k) {
      output.push_back(value);
    }
  }
  return output;
}

int main(int argc, char const *argv[]) {
  std::vector<int> input = {1, 20, 5, 8, -7};
  auto res1 = ReturnLargestItems(input, 3);
  auto res2 = ReturnLargestItems2(input, 3);

  Print(res1);
  Print(res2);
  std::cout << "------------------------------------------" << std::endl;
  {
    std::vector<int> input = {1, 2, 3, 5, 4};
    auto res1 = ReturnLargestItems(input, 2);
    auto res2 = ReturnLargestItems2(input, 2);

    Print(res1);
    Print(res2);
  }
  std::cout << "------------------------------------------" << std::endl;
  {
    std::vector<int> input = {-1, -3, 0, 0, 0, 1, 2};
    auto res1 = ReturnLargestItems(input, 3);
    auto res2 = ReturnLargestItems2(input, 3);

    Print(res1);
    Print(res2);
  }
  std::cout << "------------------------------------------" << std::endl;
  {
    std::vector<int> input = {5, 6, 1, 2, 3};
    auto res1 = ReturnLargestItems(input, 3);
    auto res2 = ReturnLargestItems2(input, 3);

    Print(res1);
    Print(res2);
  }

  // Heap heap = ConvertToHeap(input);

  // while (!heap.empty()) {
  //   auto top = heap.top();
  //   std::cout << "top: " << top << std::endl;
  //   heap.pop();
  // }

  return 0;
}
