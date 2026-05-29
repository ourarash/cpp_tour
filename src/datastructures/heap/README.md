# Heap (Binary Min-Heap)

A **heap** is a complete binary tree where every parent is ordered relative to
its children. In a **min-heap** the smallest element sits at the root; in a
**max-heap** the largest does. The implementation here is a min-heap stored in
a `std::vector<int>`, using index arithmetic to navigate parents and children:

```
parent(i) = (i - 1) / 2
left(i)   = 2 * i + 1
right(i)  = 2 * i + 2
```

This is the same backing structure that `std::priority_queue` uses under the
hood, and the same shape used by heapsort.

## When you'd reach for a heap

- **Top-k problems** — repeatedly pull the smallest (or largest) item.
- **Priority queues** — task scheduling, Dijkstra, A*, event simulation.
- **Heapsort** — `O(n log n)` in-place sort (see `HeapSort` in `heap.h`).

## Complexity

| Operation | Cost      |
|-----------|-----------|
| `push`    | O(log n)  |
| `pop`     | O(log n)  |
| `top`     | O(1)      |
| Build from n items | O(n) |

## Try it

```bash
bazel run  //src/datastructures/heap:main         # demo
bazel test //src/datastructures/heap:heap_test    # unit tests
```

## Files

- [heap.h](heap.h) — class declaration with the index helpers.
- [heap.cc](heap.cc) — `TrickleUp` / `TrickleDown` and `HeapSort`.
- [heap_test.cc](heap_test.cc) — GoogleTest cases; read these as the spec.
- [main.cc](main.cc) — a runnable demo of building a heap from a vector.

## See also

- `std::priority_queue` (in `<queue>`) — the STL equivalent.
- `std::make_heap` / `std::push_heap` / `std::pop_heap` — heap algorithms on
  any random-access container.
