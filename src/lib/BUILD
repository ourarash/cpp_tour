# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "SolutionLib",
    srcs = glob(["**/*.cc"]),
    hdrs = glob(["**/*.h"]),
    visibility = ["//visibility:public"],
)

cc_library(
    name = "dynamic_programming_lpss_lib",
    hdrs = ["dynamic_programming/lpss.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "graph_vector_v_vector_pair_e_lib",
    hdrs = ["graph/vector_v_vector_pair_e.h"],
    srcs = ["graph/vector_v_vector_pair_e.cc"],
    visibility = ["//visibility:public"],
)
