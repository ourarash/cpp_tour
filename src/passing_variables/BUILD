load("@rules_cc//cc:defs.bzl", "cc_binary")
cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = ["//src/lib:SolutionLib"],
)
cc_binary(
    name = "pass_by_reference_main",
    srcs = ["pass_by_reference_main.cc"],
    deps = ["//src/lib:SolutionLib"],
)

cc_binary(
    name = "pass_by_reference_avoiding_copy_main",
    srcs = ["pass_by_reference_avoiding_copy_main.cc"],
    deps = ["//src/lib:SolutionLib"],
)


