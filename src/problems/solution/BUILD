load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "solution_lib",
    srcs = ["solution.cc"],
    hdrs = ["solution.h"],
    visibility = ["//visibility:public"],
    # Many of the demos that depend on SolutionLib also include "src/lib/utility.h".
    # Re-exporting utility here keeps the demo BUILDs simple (one dep) without
    # forcing every demo to redeclare the utility dep explicitly.
    deps = ["//src/lib:utility"],
)

cc_test(
    name = "solution_test",
    srcs = ["solution_test.cc"],
    deps = [
        ":solution_lib",
        "//src/lib:utility",
        "@com_google_googletest//:gtest_main",
    ],
)
