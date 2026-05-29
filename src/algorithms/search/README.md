# Searching

Linear and binary search implementations (recursive and iterative). Binary
search is the canonical example of a divide-and-conquer algorithm.

## Complexity

| Algorithm        | Time     | Requires sorted? |
|------------------|----------|------------------|
| Linear search    | O(n)     | No               |
| Binary search    | O(log n) | Yes              |

## Try it

```bash
bazel test //src/algorithms/search:search_test
```

## Files

- [search.h](search.h), [search.cc](search.cc) — the `Search` class.
- [search_test.cc](search_test.cc) — exercises each variant.

## See also

- `std::binary_search`, `std::lower_bound`, `std::upper_bound`, `std::equal_range`.
- `std::find`, `std::find_if`.
