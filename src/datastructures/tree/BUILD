load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "tree_lib",
    srcs = ["tree.cc"],
    hdrs = ["tree.h"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":tree_lib",
        "//src/lib:utility",
    ],
)

cc_binary(
    name = "std_any_main",
    srcs = ["std_any_main.cc"],
    deps = ["//src/lib:utility"],
)

cc_binary(
    name = "tree_map_main",
    srcs = ["tree_map_main.cc"],
)
