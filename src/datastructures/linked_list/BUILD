load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "linked_list_lib",
    srcs = ["linked_list.cc"],
    hdrs = ["linked_list.h"],
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        ":linked_list_lib",
        "//src/lib:utility",
    ],
)
