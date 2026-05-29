load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "segment_tree_lib",
    srcs = ["segment_tree.cc"],
    hdrs = ["segment_tree.h"],
    visibility = ["//visibility:public"],
    deps = ["//src/lib:utility"],
)

cc_test(
    name = "segment_tree_test",
    srcs = ["segment_tree_test.cc"],
    deps = [
        ":segment_tree_lib",
        "//src/lib:utility",
        "@com_google_googletest//:gtest_main",
    ],
)
