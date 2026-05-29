# cpp_tour — A tour of C++ constructs

A learning repository that catalogues C++ language features, data structures,
and algorithms as self-contained, runnable examples — each with a `BUILD`
file, a `README.md`, and (where applicable) a library, a demo, and tests.

> Works well from VS Code with the Bazel extension.

## Quick start

```bash
git clone https://github.com/ourarash/cpp_tour.git
cd cpp_tour
bazel run //src/_start_here/hello_world:main
```

That builds everything Bazel needs and runs the smallest example. Then browse
[`src/_start_here/`](src/_start_here/) for the repository map.

## Layout

```
src/
  _start_here/        ← orientation; start here
  language/           ← C++ language fundamentals
  modern_cpp/         ← C++11+ features and idioms
  datastructures/     ← heap, bst, tree, graph, STL containers
  algorithms/         ← sort, search, DP, backtracking, segment_tree
  concurrency/        ← threading, parallel demos
  performance/        ← benchmarks, allocators, amortization
  problems/           ← leetcode-style problem solutions
  lib/                ← shared utilities (utility.h, back-compat shims)
```

Every concept folder is self-contained: open it on GitHub and you see the
library, demo, tests, and a README in one view.

## Run things

```bash
# Build everything
bazel build //src/...

# Run all tests
bazel test //src/...

# Run a specific demo
bazel run //src/algorithms/sort:main
bazel run //src/datastructures/heap:main

# Run a specific test
bazel test //src/datastructures/heap:heap_test
```

A few examples are intentionally *not* compiled — they illustrate the
compiler error itself (e.g. `enum` name collisions, missing `override`
keywords, accessing a private member). Those are marked with `tags = ["manual"]`
in their BUILD with a one-line note explaining why.

## Installing Bazel

Install Bazel from the [official guide](https://bazel.build/install). Tested
with Bazel 9.x; older versions don't support the bzlmod-based dependency
declarations in [`MODULE.bazel`](MODULE.bazel).

## Working with Bazel and GoogleTest

A short video walking through using GoogleTest with Bazel in VS Code:

<table><tr><td>
<a href="https://www.youtube.com/watch?v=0wMNtl2xDT0/">
<img border="5" alt="Bazel & Google Test in Visual Studio Code" src="https://raw.githubusercontent.com/ourarash/cpp-template/master/bazel_yt.png" width="400">
</a>
</td></tr></table>
