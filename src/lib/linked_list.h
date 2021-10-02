#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <map>
#include <vector>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}

  // ListNode(int x) {
  //   val = x;
  //   next = nullptr;
  // }
};

class SinglyLinkedList {
 public:
  SinglyLinkedList() { head_ = nullptr; }
  bool empty();
  int size();
  void push_back(int i);
  void pop_back();
  int back();
  ListNode *GetBackPointer();
  ListNode *GetIthPointer(int i);
  int &operator[](int i);
  void print();

  ListNode *head_;
  int my_size;

  // Write a copy constructor for the list.

  // Write a new parameterized constructor that takes a vector as an input and
  // crates a linked list based on that. Note that your constructor should
  // assign a valid value for head_. Example:
  // Input:  v = {1, 4, 5, 6, 10}
  // The created list: 1->4->5->6->10, and head_ will point to the first node
  // with value 1.
  SinglyLinkedList(const std::vector<int> &v);

  // Write a function that converts the list into a vector. Example:
  // The list: 1->4->5->6->10
  // Output: a vector with value: {1, 4, 5, 6, 10}
  std::vector<int> convert_to_vector();

  // Erases element i from the list if it exists and returns a pointer to item
  // i-1. If item i doesn't exist, returns nullptr. The first item in the list
  // has index 0.

  // Example:
  // Input: 1 -> 5 -> 10 ->20, i= 2.
  // Output: 1 -> 5 -> 20, return value: a pointer to element 5.
  ListNode *erase(int i);

  // Returns a histogram of the items in the list.
  // Example:
  // Input: 1 -> 5 -> 1 -> 20 -> 4 -> 5 -> 32
  // Output: {{1,2}, {4,1}, {5,2}, {32,1}}
  std::map<int, int> histogram();

  // Removes duplicate elements and only keeps the first one.
  // Example:
  // Input: 1 -> 5 -> 1 -> 20 -> 4 -> 5 -> 32
  // Output: 1 -> 5 -> 20 -> 4 -> 32
  void remove_duplicates();

  // Assuming the following struct is defined:
  struct Statistics {
    int minimum;
    int maximum;
    int median;
    float average;
    float standard_deviation;
  };

  // Write the following function which iterates through the list and returns a
  // variable of type Statistics which has the correct values for the items in
  // the list.
  Statistics calculate_statistics() {
    Statistics s;
    return s;
  }
};

#endif