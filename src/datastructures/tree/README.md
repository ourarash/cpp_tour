# Tree

A generic n-ary tree where each node carries an `int` value and a list of
child pointers. This is the base class that [bst/](../bst/) specializes into a
binary search tree.

## Try it

```bash
bazel run //src/datastructures/tree:main             # walks a small tree
bazel run //src/datastructures/tree:std_any_main     # demos std::any
bazel run //src/datastructures/tree:tree_map_main    # demos using std::map as a tree
```

## Files

- [tree.h](tree.h), [tree.cc](tree.cc) — the `Tree` class.
- [main.cc](main.cc) — builds a tree and walks it.
- [std_any_main.cc](std_any_main.cc) — uses `std::any` to model heterogeneous tree nodes.
- [tree_map_main.cc](tree_map_main.cc) — represents a tree purely as nested `std::map`s.
