load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = [":pimple"]
)

cc_library(
    name = "pimple",
    srcs = [
        "widget.cc",
    ],
    hdrs = [
        "widget.h",
    ],
    # includes = ["/Users/ari/github/cpp_tour/src/smart_pointer/pimple/widget.h"],
)
