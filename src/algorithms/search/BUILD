load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "search_lib",
    srcs = ["search.cc"],
    hdrs = ["search.h"],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "search_test",
    srcs = ["search_test.cc"],
    deps = [
        ":search_lib",
        "@com_google_googletest//:gtest_main",
    ],
)
