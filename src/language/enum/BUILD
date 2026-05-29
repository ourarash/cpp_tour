load("@rules_cc//cc:defs.bzl", "cc_binary")
cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = ["//src/lib:SolutionLib"],
    # Intentionally fails to compile: demonstrates name pollution in C-style
    # `enum` (two enums both define `Red`) and the type-safety of `enum class`.
    tags = ["manual"],
)
