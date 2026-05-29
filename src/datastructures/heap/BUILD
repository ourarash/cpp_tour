load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

cc_library(
    name = "heap_lib",
    srcs = ["heap.cc"],
    hdrs = ["heap.h"],
    visibility = ["//visibility:public"],
    deps = ["//src/lib:utility"],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":heap_lib",
        "//src/lib:utility",
    ],
)

cc_test(
    name = "heap_test",
    srcs = ["heap_test.cc"],
    deps = [
        ":heap_lib",
        "//src/lib:utility",
        "@com_google_googletest//:gtest_main",
    ],
)
