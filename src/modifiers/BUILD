# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
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