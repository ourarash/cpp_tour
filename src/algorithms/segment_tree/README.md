# Segment Tree

A **segment tree** is a binary-tree data structure for answering range queries
over an array (e.g. "sum of elements in [l, r]") and supporting point updates,
both in `O(log n)`. The tree stores aggregates over array segments at each
node — leaves hold individual elements, internal nodes hold the aggregate of
their two children's ranges.

## Complexity

| Operation     | Cost     |
|---------------|----------|
| Build         | O(n)     |
| Range query   | O(log n) |
| Point update  | O(log n) |
| Space         | O(n)     |

## Try it

```bash
bazel test //src/algorithms/segment_tree:segment_tree_test
```

## Files

- [segment_tree.h](segment_tree.h), [segment_tree.cc](segment_tree.cc) — the implementation.
- [segment_tree_test.cc](segment_tree_test.cc) — read the tests as the spec.
