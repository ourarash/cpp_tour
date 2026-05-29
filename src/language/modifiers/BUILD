load("@rules_cc//cc:defs.bzl", "cc_binary")
cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = ["//src/lib:SolutionLib"],
)

cc_binary(
    name = "machine_independent_main",
    srcs = ["machine_independent_main.cc"],
    deps = ["//src/lib:SolutionLib"],
)

cc_binary(
    name = "constants_main",
    srcs = ["constants_main.cc"],
    deps = ["//src/lib:SolutionLib"],
)


cc_binary(
    name = "sizeof_main",
    srcs = ["sizeof_main.cc"],
    deps = ["//src/lib:utility"],
)

cc_binary(
    name = "sizeof_examples_main",
    srcs = ["sizeof_examples_main.cc"],
    deps = ["//src/lib:utility"],
)