# Backtracking

A general algorithm strategy: explore candidate solutions recursively, and
**undo** the last choice (backtrack) when a path can't lead to a valid answer.
Used for permutations, combinations, subsets, n-queens, sudoku, word search,
and many combinatorial problems.

## Pattern

```
backtrack(state, choices):
    if state is a solution:
        record it
        return
    for choice in choices:
        apply(choice)            # try it
        backtrack(state, ...)    # recurse
        undo(choice)             # backtrack
```

## Try it

```bash
bazel test //src/algorithms/backtracking:backtracking_test
```

## Files

- [backtracking.h](backtracking.h), [backtracking.cc](backtracking.cc) — `Backtracking` class with `Subsets`, `Permute`, `SubsetsWithDup`, etc.
- [backtracking_test.cc](backtracking_test.cc) — exhaustive tests per algorithm.
- [hazf.cc](hazf.cc) — an additional Word Break solution kept for reference (not built by default).
