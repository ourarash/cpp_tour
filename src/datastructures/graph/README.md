# Graph

A **graph** is a set of vertices connected by edges. There's no single "right"
way to represent one — every choice trades off memory, lookup speed, and ease
of update. This folder shows several representations side by side so you can
read the code and compare.

## Representations covered

| Representation                     | Lookup edge | Add edge | Space   | Best for                          |
|-----------------------------------|-------------|----------|---------|-----------------------------------|
| Adjacency matrix                   | O(1)        | O(1)     | O(V²)   | Dense graphs, fast edge lookup    |
| Adjacency list (vector of set)     | O(log V)    | O(log V) | O(V+E)  | Sparse graphs, fast iteration     |
| Vector of vertices + pair edges    | O(V)        | O(1)     | O(V+E)  | Static graphs, simple iteration   |
| Map of int → set                   | O(log V)    | O(log V) | O(V+E)  | Sparse graphs with arbitrary IDs  |
| Distance matrix (weighted)         | O(1)        | O(1)     | O(V²)   | Dijkstra, Floyd–Warshall          |
| Pointer-based                      | varies      | O(1)     | O(V+E)  | Mutating graphs in place          |

## Try it

```bash
# Tests
bazel test //src/datastructures/graph/...

# Demos for each representation
bazel run //src/datastructures/graph:adjacency_matrix_main
bazel run //src/datastructures/graph:adjacency_vector_of_set_main
bazel run //src/datastructures/graph:vector_v_vector_pair_e_main
bazel run //src/datastructures/graph:main_map_of_int_to_set_graph
bazel run //src/datastructures/graph:pointer_main
# ...and more demos in BUILD
```

## Files

Library headers (`*.h` / `*.cc`):
- `adjacency_matrix.{h,cc}`, `adjacency_vector_of_set.{h,cc}`,
  `distance_matrix.{h,cc}`, `map_of_int_to_set_graph.{h,cc}`,
  `pointer.{h,cc}`, `vector_v_vector_pair_e.{h,cc}`.

Tests (`*_test.cc`) — read these as the spec for each representation.

Demos (`*_main.cc`, `set_of_set.cc`, `vector_of_set.cc`, etc.) — runnable
explorations of each style. The `shortest_path_*.cc` demos focus on Dijkstra
and BFS-based shortest path on different underlying representations.

The standalone `set_v_set_pair_e_main.cc` file is a **student exercise** —
the `Graph` class is left commented out for you to implement.

## See also

- [src/algorithms/dynamic_programming/](../../algorithms/dynamic_programming/) — graph problems that benefit from DP.
