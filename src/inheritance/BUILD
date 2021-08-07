load("@rules_cc//cc:defs.bzl", "cc_binary")
cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = ["//src/lib:SolutionLib"],
)

cc_binary(
    name = "virtual",
    srcs = ["virtual.cc"],
    deps = ["//src/lib:SolutionLib"],
)

cc_binary(
name = "final",
srcs = ["final.cc"],
)

cc_binary(
name = "call_virtual_during_ctr",
srcs = ["call_virtual_during_ctr.cc"],
)

cc_binary(
name = "base_pointer",
srcs = ["base_pointer.cc"],
)

cc_binary(
name = "pure_virtual_function",
srcs = ["pure_virtual_function.cc"],
)

cc_binary(
name = "virtual_default_value",
srcs = ["virtual_default_value.cc"],
)

cc_binary(
name = "override",
srcs = ["override.cc"],
)