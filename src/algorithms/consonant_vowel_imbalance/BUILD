load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "consonant_vowel_imbalance_lib",
    srcs = ["consonant_vowel_imbalance.cc"],
    hdrs = ["consonant_vowel_imbalance.h"],
    visibility = ["//visibility:public"],
    deps = ["//src/lib:utility"],
)

cc_test(
    name = "consonant_vowel_imbalance_test",
    srcs = ["consonant_vowel_imbalance_test.cc"],
    deps = [
        ":consonant_vowel_imbalance_lib",
        "//src/lib:utility",
        "@com_google_googletest//:gtest_main",
    ],
)
