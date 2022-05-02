load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "tests",
    srcs = glob(["**/*.cc"]),
    deps = [
        "//src/lib:SolutionLib",
        "//src/lib:vector_union_lib",
        "//src/lib/sort:SortLib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "vector_union_test",
    deps = [
        "//src/lib:SolutionLib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "sort_test",
    srcs = ["sort_test.cc"],
    deps = [
        "//src/lib:utility",
        "//src/lib/sort:SortLib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "solution_test",
    srcs = ["solution_test.cc"],

    deps = [
        "//src/lib:SolutionLib",
        "//src/lib:utility",
        "@com_google_googletest//:gtest_main",
    ],
)


cc_test(
    name = "backtracking_test",
    srcs = ["backtracking_test.cc"],
    deps = [
        "//src/lib/backtracking:BacktrackingLib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "search_test",
    srcs = ["search_test.cc"],
    deps = [
        "//src/lib/search:SearchLib",
        "@com_google_googletest//:gtest_main",
    ],
)
