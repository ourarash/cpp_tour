load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "main",
    srcs = ["main.cc"],
    deps = ["//src/lib:utility"],
)

cc_binary(
    name = "main_dash_dash",
    srcs = ["main_dash_dash.cc"],
    deps = ["//src/lib:utility"],
)

cc_binary(
    name = "abseil_main",
    srcs = ["abseil_main.cc"],
    deps = [
        "@com_google_absl//absl/flags:flag",
        "@com_google_absl//absl/flags:parse",
        "@com_google_absl//absl/flags:usage",
    ],
)


cc_binary(
    name = "abseil_main_user",
    srcs = ["abseil_main_user.cc"],
    deps = [
        "@com_google_absl//absl/flags:flag",
        "@com_google_absl//absl/flags:parse",
        "@com_google_absl//absl/flags:usage",
    ],
)

