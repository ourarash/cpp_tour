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
    name = "main2",
    srcs = ["main2.cc"],
    deps = [
        "//src/lib:SolutionLib",
        "//src/lib:utility",
    ],
    # Intentionally fails to compile: `std::set` iterators are const, so you
    # cannot mutate set elements through them. The lesson is the error.
    tags = ["manual"],
)

cc_binary(
    name = "istream_iterator",
    srcs = ["istream_iterator.cc"],
)

cc_binary(
    name = "iterator_implementation",
    srcs = ["iterator_implementation.cc"],
)
