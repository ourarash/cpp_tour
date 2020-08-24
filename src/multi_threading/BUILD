load("@rules_cc//cc:defs.bzl", "cc_binary")
cc_binary(
    name = "main",
    srcs = ["main.cc"],
    linkopts = ["-pthread"],
    deps = ["//src/lib:SolutionLib"],
)

cc_binary(
    name = "vector_of_threads_main",
    srcs = ["vector_of_threads_main.cc"],
    linkopts = ["-pthread"],
    deps = ["//src/lib:SolutionLib"],
)

cc_binary(
    name = "vector_of_threads_main_measure_time",
    srcs = ["vector_of_threads_main_measure_time.cc"],
    linkopts = ["-pthread"],
    deps = ["//src/lib:SolutionLib"],
)

cc_binary(
    name = "thread_functor",
    srcs = ["thread_functor.cc"],
    linkopts = ["-pthread"],
    deps = ["//src/lib:SolutionLib"],
)

cc_binary(
    name = "vector_of_threads_lambda_main",
    srcs = ["vector_of_threads_lambda_main.cc"],
    linkopts = ["-pthread"],
    deps = ["//src/lib:SolutionLib"],
)

cc_binary(
    name = "vector_of_threads_async_main",
    srcs = ["vector_of_threads_async_main.cc"],
    linkopts = ["-pthread"],
    deps = ["//src/lib:SolutionLib"],
)
