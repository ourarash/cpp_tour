load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "vector_union_lib",
    srcs = ["vector_union.cc"],
    hdrs = ["vector_union.h"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "vector_union_test",
    srcs = ["vector_union_test.cc"],
    deps = [
        ":vector_union_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
