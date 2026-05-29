load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "coroutine",
    srcs = ["coroutine.cc"],
    # C++20 coroutines + std::generator: needs -std=c++23 plus a stdlib that
    # ships std::generator (libc++ on macOS does not yet). Kept as a reading
    # demo of the syntax.
    tags = ["manual"],
)
