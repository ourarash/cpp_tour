# Dynamic Programming

**Dynamic programming** turns exponential recursive problems into polynomial
ones by remembering subproblem answers. Two flavors:

- **Memoization (top-down):** start from the recursive solution, cache results.
- **Tabulation (bottom-up):** iterate, filling a table from base cases up.

Each problem in this folder has three demos showing the progression:
*naive recursion* → *memoization* → *tabulation*. Reading them side by side is
the point.

## Problems covered

| Problem               | Naive            | Memo               | Table              |
|-----------------------|------------------|--------------------|--------------------|
| Fibonacci             | `fib_main`       | `fib_memo_main`    | `fib_table_main`   |
| Coin change           | `coin_main`      | `coin_memo_main`   | `coin_tab_main`    |
| 0/1 Knapsack          | `knap_01_main`   | `knap_01_memo_main`| `knap_01_table_main`|
| Longest common subseq | `lscs_main`      | `lscs_memo_main`   | `lscs_table_main`  |
| Longest palindromic substring | — | — | `lpss_main` |

## Try it

```bash
bazel run  //src/algorithms/dynamic_programming:fib_main
bazel run  //src/algorithms/dynamic_programming:fib_memo_main
bazel run  //src/algorithms/dynamic_programming:fib_table_main
# ...

bazel test //src/algorithms/dynamic_programming:dynamic_programming_test
bazel test //src/algorithms/dynamic_programming:lpss_test
```

## Files

- [dynamic_programming.h](dynamic_programming.h) / [.cc](dynamic_programming.cc) — small reusable lib.
- [lpss.h](lpss.h) — three approaches to longest palindromic substring.
- `*_main.cc` — the self-contained demos.
- `*_test.cc` — GoogleTest cases.
