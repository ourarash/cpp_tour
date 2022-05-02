load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "com_google_googletest",
    #// Dec 27, 2021
    commit = "1b18723e874b256c1e39378c6774a90701d70f7a",
    remote = "https://github.com/google/googletest",
    # tag = "release-1.11.0",
)

git_repository(
    name = "com_google_benchmark",
    remote = "https://github.com/google/benchmark.git",
    tag = "v1.5.1",
)

git_repository(
    name = "com_google_absl",
    remote = "https://github.com/abseil/abseil-cpp.git",
    tag = "20200225.2",
)

new_local_repository(
    name = "usr_local",
    build_file = "third_party/usr_local.BUILD",
    path = "/usr/local",
)
