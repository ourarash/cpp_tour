load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = ["main.cc"],
)

cc_binary(
    name = "string_view_benchmark",
    srcs = ["string_view_benchmark.cc"],
    deps = [
        "//src/lib:utility",
        "@com_google_benchmark//:benchmark",
    ],
)
cc_binary(
    name = "string_view_remove_prefix_benchmark",
    srcs = ["string_view_remove_prefix_benchmark.cc"],
    deps = [
        "//src/lib:utility",
        "@com_google_benchmark//:benchmark",
    ],
)

cc_binary(
    name = "string_view_first",
    srcs = ["string_view_first.cc"],
    deps = [
        "//src/lib:utility",
        "@com_google_benchmark//:benchmark",
    ],
)