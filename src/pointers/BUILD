load("@rules_cc//cc:defs.bzl", "cc_binary")
cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = ["//src/lib:SolutionLib"],
)

cc_binary(
    name = "unsafe_pointers_main",
    srcs = ["unsafe_pointers_main.cc"],
    deps = ["//src/lib:SolutionLib"],
)

cc_binary(
    name = "heap_main",
    srcs = ["heap_main.cc"],
    deps = ["//src/lib:SolutionLib"],
)

cc_binary(
    name = "shallow_copy_main",
    srcs = ["shallow_copy_main.cc"],
)

cc_binary(
name = "set_new_handler",
srcs = ["set_new_handler.cc"],
)