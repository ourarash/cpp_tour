load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "bst_lib",
    srcs = ["bst.cc"],
    hdrs = ["bst.h"],
    visibility = ["//visibility:public"],
    deps = ["//src/datastructures/tree:tree_lib"],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":bst_lib",
        "//src/lib:utility",
    ],
)
