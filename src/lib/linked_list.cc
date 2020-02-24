#include "linked_list.h"
#include <iostream>

bool SinglyLinkedList::empty() { return head_ == nullptr; }

int SinglyLinkedList::size() {
  int s = 0;
  if (empty()) {
    return s;
  }
  ListNode *p = head_;
  ListNode *p_prev;
  while (p != nullptr) {
    s++;
    p_prev = p;
    p = p->next;
  }

  return s;
}

ListNode *SinglyLinkedList::GetBackPointer2() {
  if (empty()) {
    return head_;
  }
  ListNode *p = head_;
  ListNode *p_prev;
  while (p != nullptr) {
    p_prev = p;
    p = p->next;
  }
  return p_prev;
}

ListNode *SinglyLinkedList::GetBackPointer() {
  if (empty()) {
    return head_;
  }
  ListNode *p = head_;
  while (p->next != nullptr) {
    p = p->next;
  }
  return p;
}

ListNode *SinglyLinkedList::GetIthPointer(int i) {
  if (empty()) {
    return head_;
  }

  ListNode *p = head_;
  ListNode *p_prev = head_;
  int max_size = size();
  int count = 0;
  while (p != nullptr && count < max_size && count <= i) {
    p_prev = p;
    p = p->next;
    count++;
  }

  if (i < max_size) {
    return p_prev;
  } else {
    return nullptr;
  }
}

void SinglyLinkedList::push_back(int i) {
  // If list empty, create a new node and point head_ to it
  if (empty()) {
    head_ = new ListNode(i);
    return;
  }
  // If not empty, go to the end, create a new node and point the last item to
  // it
  auto back_ptr = GetBackPointer();
  auto newNode = new ListNode(i);
  back_ptr->next = newNode;
  my_size++;
}

void SinglyLinkedList::pop_back() {}
int SinglyLinkedList::back() { return 0; }
void SinglyLinkedList::print() {
  std::cout << "{";
  if (!empty()) {

    ListNode *p = head_;
    ListNode *p_prev;
    while (p != nullptr) {
      p_prev = p;
      std::cout << p->val;
      p = p->next;
      if (p) {
        std::cout << ", ";
      }
    }
    std::cout << "}" << std::endl;
  }
}

// Dangerous!
int &SinglyLinkedList::operator[](int i) {
  ListNode *ith_pointer = GetIthPointer(i);
  // Dangerous!
  return ith_pointer->val;
}
