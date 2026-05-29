load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "utility",
    hdrs = ["utility.h"],
    visibility = ["//visibility:public"],
)

# Back-compat shim header so `#include "src/lib/solution.h"` keeps working.
cc_library(
    name = "solution_compat",
    hdrs = ["solution.h"],
    visibility = ["//visibility:public"],
    deps = ["//src/problems/solution:solution_lib"],
)

# Back-compat shim header for vector_union.
cc_library(
    name = "vector_union_compat",
    hdrs = ["vector_union.h"],
    visibility = ["//visibility:public"],
    deps = ["//src/problems/vector_union:vector_union_lib"],
)

# Back-compat aliases. The libraries themselves were moved to their new homes
# during the directory reorganization. These aliases let pre-reorg BUILD files
# keep working until they are rewritten in their new theme folders.
alias(
    name = "SolutionLib",
    actual = ":solution_compat",
    visibility = ["//visibility:public"],
)

alias(
    name = "vector_union_lib",
    actual = ":vector_union_compat",
    visibility = ["//visibility:public"],
)
