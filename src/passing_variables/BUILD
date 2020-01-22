# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
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


