# Consonant–Vowel Imbalance

A solution to a string-processing problem: given a string, compute a per-prefix
score where vowels and consonants offset each other, and find the maximum
imbalance over any substring.

## Try it

```bash
bazel test //src/algorithms/consonant_vowel_imbalance:consonant_vowel_imbalance_test
```

## Files

- [consonant_vowel_imbalance.h](consonant_vowel_imbalance.h), [consonant_vowel_imbalance.cc](consonant_vowel_imbalance.cc) — the algorithm.
- [consonant_vowel_imbalance_test.cc](consonant_vowel_imbalance_test.cc) — GoogleTest cases.
