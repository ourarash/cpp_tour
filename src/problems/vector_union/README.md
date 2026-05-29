# Vector Union

Given two `std::vector<int>`s, return their set union (unique values). Classic
warm-up — compare the naive `O(n²)` approach to using `std::set` or hashing.

## Try it

```bash
bazel test //src/problems/vector_union:vector_union_test
```

## Files

- [vector_union.h](vector_union.h), [vector_union.cc](vector_union.cc) — `VectorUnionSolution::Calculate`.
- [vector_union_test.cc](vector_union_test.cc) — GoogleTest cases.
