# Singly Linked List

A **singly linked list** stores elements as nodes, where each node points to
the next. Unlike `std::vector`, there's no contiguous storage — insertions
and deletions don't require shifting, but random access is `O(n)`.

This file doubles as a **student exercise**: the header declares several
functions (`erase`, `histogram`, `remove_duplicates`, `convert_to_vector`,
the vector constructor, etc.) that are left unimplemented for the reader.

## Complexity

| Operation              | Cost |
|------------------------|------|
| `push_back` (with tail) | O(1) |
| `push_front`           | O(1) |
| Random access (`[i]`)  | O(n) |
| Find back without tail | O(n) |

## Try it

```bash
bazel run //src/datastructures/linked_list:main
```

## Files

- [linked_list.h](linked_list.h) — `ListNode` struct and `SinglyLinkedList` class.
  Read the comments — many functions are intentionally unimplemented exercises.
- [linked_list.cc](linked_list.cc) — implementations including two variants of
  `GetBackPointer` (read both and compare).
- [main.cc](main.cc) — runnable demo.

## See also

- `std::list` — STL doubly-linked list.
- `std::forward_list` — STL singly-linked list.
