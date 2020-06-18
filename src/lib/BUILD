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
    srcs = ["graph/vector_v_vector_pair_e.cc"],
    hdrs = ["graph/vector_v_vector_pair_e.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "graph_adjacency_vector_of_set_lib",
    srcs = ["graph/adjacency_vector_of_set.cc"],
    hdrs = ["graph/adjacency_vector_of_set.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "graph_adjacency_matrix_lib",
    srcs = ["graph/adjacency_matrix.cc"],
    hdrs = ["graph/adjacency_matrix.h"],
    visibility = ["//visibility:public"],
)


