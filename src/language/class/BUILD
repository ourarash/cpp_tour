load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name="main",
    srcs=["main.cc"],
    deps=["//src/lib:SolutionLib"],
)

cc_binary(
    name="constructor_main",
    srcs=["constructor_main.cc"],
)

cc_binary(
    name="destructor_main",
    srcs=["destructor_main.cc"],
    deps=["//src/lib:SolutionLib"],
)

cc_binary(
    name="operator_overloading_main",
    srcs=["operator_overloading_main.cc"],
    deps=[
        "//src/lib:SolutionLib",
        "//src/lib:utility",
    ],
)

cc_binary(
    name="operator_overloading2",
    srcs=["operator_overloading2.cc"],
    deps=[
        "//src/lib:SolutionLib",
        "//src/lib:utility",
    ],
)

cc_binary(
    name="brackets",
    srcs=["brackets.cc"],
)

cc_binary(
    name = "constructor_implicit_default_deleted",
    srcs = ["constructor_implicit_default_deleted.cc"],
    # Intentionally fails to compile: shows that a class with a user-provided
    # constructor has its implicit default constructor deleted. The line
    # `Point p1;` is the lesson.
    tags = ["manual"],
)

cc_binary(
    name="struct",
    srcs=["struct.cc"],
)

cc_binary(
    name = "operator_overloading3",
    srcs = ["operator_overloading3.cc"],
    # Intentionally fails to compile: demonstrates access control by trying
    # to use private operators from outside the class.
    tags = ["manual"],
)

cc_binary(
name = "simple_class",
srcs = ["simple_class.cc"],
)
