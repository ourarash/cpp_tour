# Start here

This directory is the entry point for the tour. Begin with `hello_world` to
verify your build, then browse to the topic you want to explore.

## Verify your build

```bash
bazel run //src/_start_here/hello_world:main
```

If that printed a greeting, your toolchain is set up correctly.

## Repository map

| Theme                                 | What's in there                                  |
|---------------------------------------|--------------------------------------------------|
| [`language/`](../language/)           | C++ language fundamentals (types, scope, classes, templates, …) |
| [`modern_cpp/`](../modern_cpp/)       | C++11+ features (smart pointers, move, lambdas, C++17/20)        |
| [`datastructures/`](../datastructures/) | DS implementations + demos + tests (heap, bst, graph, …)         |
| [`algorithms/`](../algorithms/)       | Algorithm implementations (sort, search, DP, backtracking, …)   |
| [`concurrency/`](../concurrency/)     | Threading and parallel demos                                     |
| [`performance/`](../performance/)     | Benchmarks, allocators, amortization                             |
| [`problems/`](../problems/)           | Leetcode-style problem solutions                                 |
| [`shared/`](../lib/)                  | Cross-cutting helpers (`utility.h`)                              |

Every concept folder follows the same shape: `BUILD` + `README.md` +
`main.cc` (demo) + optionally `<name>.{h,cc}` (library) + `<name>_test.cc`
(tests). Open any folder for that concept's deep dive.

## Conventions

- **`bazel run //<path>:main`** runs a demo; **`bazel test //<path>:...`** runs the tests.
- Some demos are intentionally not built — they illustrate compiler errors or
  are teaching skeletons. Look for `tags = ["manual"]` in the BUILD with a
  one-line note explaining why.
