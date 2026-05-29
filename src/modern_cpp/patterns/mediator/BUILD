load("@rules_cc//cc:defs.bzl", "cc_binary")
cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = ["//src/lib:utility"],
    # Teaching skeleton — class declarations only, no main() body. Read it,
    # don't link it. Excluded from `bazel build //...`.
    tags = ["manual"],
)
