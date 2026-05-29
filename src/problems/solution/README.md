# Solution

A grab-bag class that accumulates solutions to interview / leetcode-style
problems as static methods. Rather than one class per problem, every solution
lives on `Solution` so the tests can quickly try many of them. Useful when
practicing — pick a problem, add a method, write tests.

## Try it

```bash
bazel test //src/problems/solution:solution_test
```

## Files

- [solution.h](solution.h), [solution.cc](solution.cc) — the `Solution` class.
- [solution_test.cc](solution_test.cc) — read tests for the menu of problems covered.
