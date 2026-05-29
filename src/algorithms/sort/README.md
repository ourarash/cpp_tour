# Sorting

Classic sorting algorithms implemented from scratch (not `std::sort`). The
`Sort` class collects multiple approaches side by side so you can compare
them — same input, different strategies, different complexity.

## Complexity

| Algorithm     | Average    | Worst      | Space  | Stable? |
|---------------|------------|------------|--------|---------|
| Bubble sort   | O(n²)      | O(n²)      | O(1)   | Yes     |
| Insertion sort| O(n²)      | O(n²)      | O(1)   | Yes     |
| Selection sort| O(n²)      | O(n²)      | O(1)   | No      |
| Merge sort    | O(n log n) | O(n log n) | O(n)   | Yes     |
| Quick sort    | O(n log n) | O(n²)      | O(log n)| No      |
| Heap sort     | O(n log n) | O(n log n) | O(1)   | No      |

## Try it

```bash
bazel run  //src/algorithms/sort:main        # demo
bazel test //src/algorithms/sort:sort_test   # tests
```

## Files

- [sort.h](sort.h), [sort.cc](sort.cc) — `Sort` class with static methods.
- [main.cc](main.cc) — runnable demo.
- [sort_test.cc](sort_test.cc) — tests covering all variants.

## See also

- `std::sort` (introsort: quicksort + heapsort + insertion).
- `std::stable_sort` (typically merge sort).
- `std::partial_sort`, `std::nth_element`.
