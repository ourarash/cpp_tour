# Binary Search Tree (BST)

A **BST** orders every node so that all keys in the left subtree are smaller
than the node, and all keys in the right subtree are larger. That ordering
makes lookup, insert, and delete `O(log n)` on average — and `O(n)` worst-case
if the tree degenerates into a list (no rebalancing here).

This `BST` inherits from [Tree](../tree/) and adds the ordering invariant.

## Complexity

| Operation | Average  | Worst case |
|-----------|----------|------------|
| Insert    | O(log n) | O(n)       |
| Lookup    | O(log n) | O(n)       |
| In-order traversal | O(n) | O(n)  |

## Try it

```bash
bazel run //src/datastructures/bst:main
```

## Files

- [bst.h](bst.h), [bst.cc](bst.cc) — `BST` inherits from `Tree`.
- [main.cc](main.cc) — builds a BST and demonstrates traversal.

## See also

- `std::set` and `std::map` — STL associative containers, typically
  implemented as red-black trees (a self-balancing BST).
