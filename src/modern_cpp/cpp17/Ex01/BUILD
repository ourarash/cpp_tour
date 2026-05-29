load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    # std::execution::par / par_unseq (C++17 parallel STL) are not implemented
    # in libc++ on macOS. The demo still reads as a tour of the API; toggle on
    # libstdc++ or MSVC to actually run it.
    tags = ["manual"],
)
