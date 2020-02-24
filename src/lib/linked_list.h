#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
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
  ListNode *GetBackPointer2();

  ListNode *GetIthPointer(int i);
  int &operator[](int i);
  void print();

  ListNode *head_;
  int my_size;
};

#endif