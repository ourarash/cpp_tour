load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "backtracking_lib",
    srcs = ["backtracking.cc"],
    hdrs = ["backtracking.h"],
    visibility = ["//visibility:public"],
    deps = ["//src/lib:utility"],
)

cc_test(
    name = "backtracking_test",
    srcs = ["backtracking_test.cc"],
    deps = [
        ":backtracking_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
