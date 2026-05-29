load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library", "cc_test")

# A graph can be represented many ways. This package shows several
# side-by-side so you can compare the tradeoffs (memory, lookup cost,
# update cost) for the same problem.

cc_library(
    name = "adjacency_matrix_lib",
    srcs = ["adjacency_matrix.cc"],
    hdrs = ["adjacency_matrix.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "adjacency_vector_of_set_lib",
    srcs = ["adjacency_vector_of_set.cc"],
    hdrs = ["adjacency_vector_of_set.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "distance_matrix_lib",
    srcs = ["distance_matrix.cc"],
    hdrs = ["distance_matrix.h"],
    visibility = ["//visibility:public"],
    deps = ["//src/lib:utility"],
)

cc_library(
    name = "map_of_int_to_set_graph_lib",
    srcs = ["map_of_int_to_set_graph.cc"],
    hdrs = ["map_of_int_to_set_graph.h"],
    visibility = ["//visibility:public"],
    deps = ["//src/lib:utility"],
)

cc_library(
    name = "pointer_lib",
    srcs = ["pointer.cc"],
    hdrs = ["pointer.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "vector_v_vector_pair_e_lib",
    srcs = ["vector_v_vector_pair_e.cc"],
    hdrs = ["vector_v_vector_pair_e.h"],
    visibility = ["//visibility:public"],
)

# Tests
cc_test(
    name = "adjacency_matrix_test",
    srcs = ["adjacency_matrix_test.cc"],
    deps = [
        ":adjacency_matrix_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "adjacency_vector_of_set_test",
    srcs = ["adjacency_vector_of_set_test.cc"],
    deps = [
        ":adjacency_vector_of_set_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "distance_matrix_test",
    srcs = ["distance_matrix_test.cc"],
    deps = [
        ":distance_matrix_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "distance_matrix_dijkstra_test",
    srcs = ["distance_matrix_dijkstra_test.cc"],
    deps = [
        ":distance_matrix_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "vector_v_vector_pair_e_test",
    srcs = ["vector_v_vector_pair_e_test.cc"],
    deps = [
        ":vector_v_vector_pair_e_lib",
        "@com_google_googletest//:gtest_main",
    ],
)

# Demos exploring various representations.
[
    cc_binary(
        name = name,
        srcs = [name + ".cc"],
        deps = deps,
    )
    for name, deps in [
        ("adjacency_matrix_main", [":adjacency_matrix_lib", "//src/lib:utility"]),
        ("adjacency_vector_of_set_main", [":adjacency_vector_of_set_lib", "//src/lib:utility"]),
        ("map_main", ["//src/lib:utility"]),
        ("main_map_of_int_to_set_graph", [":map_of_int_to_set_graph_lib", "//src/lib:utility"]),
        ("pointer_main", [":pointer_lib"]),
        ("set_of_set", ["//src/lib:utility"]),
        ("unordered_set_of_unordered_set", ["//src/lib:utility"]),
        ("vector_of_set", ["//src/lib:utility"]),
        ("vector_v_vector_pair_e_main", [":vector_v_vector_pair_e_lib", "//src/lib:utility"]),
        ("shortest_path_distance_matrix_main", [":distance_matrix_lib", "//src/lib:utility"]),
        ("shortest_path_map_of_int_to_set_graph", [":map_of_int_to_set_graph_lib", "//src/lib:utility"]),
    ]
]
