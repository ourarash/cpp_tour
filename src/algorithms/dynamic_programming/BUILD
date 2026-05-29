load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "dynamic_programming_lib",
    srcs = ["dynamic_programming.cc"],
    hdrs = ["dynamic_programming.h"],
    visibility = ["//visibility:public"],
    deps = ["//src/lib:utility"],
)

cc_library(
    name = "lpss_lib",
    hdrs = ["lpss.h"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "dynamic_programming_test",
    srcs = ["dynamic_programming_test.cc"],
    deps = [
        ":dynamic_programming_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "lpss_test",
    srcs = ["lpss_test.cc"],
    deps = [
        ":lpss_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "lpss_test_memo",
    srcs = ["lpss_test_memo.cc"],
    deps = [
        ":lpss_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "lpss_test_table",
    srcs = ["lpss_test_table.cc"],
    deps = [
        ":lpss_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

# Self-contained demos. Each shows one DP technique side-by-side: naive
# recursion, memoization (top-down), tabulation (bottom-up).
[
    cc_binary(
        name = name,
        srcs = [name + ".cc"],
        deps = ["//src/lib:utility"],
    )
    for name in [
        "fib_main",
        "fib_memo_main",
        "fib_table_main",
        "coin_main",
        "coin_memo_main",
        "coin_tab_main",
        "knap_01_main",
        "knap_01_memo_main",
        "knap_01_table_main",
        "lscs_main",
        "lscs_memo_main",
        "lscs_table_main",
    ]
]

cc_binary(
    name = "lpss_main",
    srcs = ["lpss_main.cc"],
    deps = [
        ":lpss_lib",
        "//src/lib:utility",
    ],
)
