load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "SolutionLib",
    srcs = ["solution.cc"],
    hdrs = ["solution.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "TreeLib",
    srcs = ["tree.cc"],
    hdrs = ["tree.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "BSTLib",
    srcs = ["bst.cc"],
    hdrs = ["bst.h"],
    visibility = ["//visibility:public"],
    deps = [":TreeLib"],
)

# cc_library(
#     name = "dynamic_programming_lpss_lib",
#     hdrs = ["dynamic_programming/lpss.h"],
#     visibility = ["//visibility:public"],
# )

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

cc_library(
    name = "graph_distance_matrix_lib",
    srcs = ["graph/distance_matrix.cc"],
    hdrs = ["graph/distance_matrix.h"],
    visibility = ["//visibility:public"],
    deps = ["utility"],
)

cc_library(
    name = "map_of_int_to_set_graph_lib",
    srcs = ["graph/map_of_int_to_set_graph.cc"],
    hdrs = ["graph/map_of_int_to_set_graph.h"],
    visibility = ["//visibility:public"],
    deps = ["utility"],
)

cc_library(
    name = "vector_union_lib",
    srcs = ["vector_union.cc"],
    hdrs = ["vector_union.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "heap_lib",
    srcs = ["heap.cc"],
    hdrs = ["heap.h"],
    visibility = ["//visibility:public"],
    deps = [":utility"],
)

cc_library(
    name = "utility",
    hdrs = ["utility.h"],
    visibility = ["//visibility:public"],
)
