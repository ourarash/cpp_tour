cc_test(
    name = "tests",
    srcs = glob(["**/*.cc"]),
    deps = [
        "//src/lib:SolutionLib",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "vector_union",
    srcs = glob(["vector_union_test.cc"]),
    deps = [
        "//src/lib:SolutionLib",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "sort_test",
    srcs = glob(["sort_test.cc"]),
    deps = [
        "//src/lib/sort:SortLib",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "solution_test",
    srcs = glob(["solution_test.cc"]),
    deps = [
        "//src/lib:SolutionLib",
        "@googletest//:gtest_main",
    ],
)
