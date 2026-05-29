load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "sort_lib",
    srcs = ["sort.cc"],
    hdrs = ["sort.h"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":sort_lib",
        "//src/lib:utility",
    ],
)

cc_test(
    name = "sort_test",
    srcs = ["sort_test.cc"],
    deps = [
        ":sort_lib",
        "//src/lib:utility",
        "@com_google_googletest//:gtest_main",
    ],
)
