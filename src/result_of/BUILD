load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [
        "//src/lib:SolutionLib",
        "//src/lib:utility",
    ],
)

cc_binary(
name = "invoke",
srcs = ["invoke.cc"],
)