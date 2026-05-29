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
    name = "references_in_loops_main",
    srcs = ["references_in_loops_main.cc"],
    deps = [
        "//src/lib:SolutionLib",
        "//src/lib:utility",
    ],
)

cc_binary(
    name = "pointer_vs_reference_main",
    srcs = ["pointer_vs_reference_main.cc"],
    deps = [
        "//src/lib:SolutionLib",
        "//src/lib:utility",
    ],
)


cc_binary(
name = "returning_handles",
srcs = ["returning_handles.cc"],
)