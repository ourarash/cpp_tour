# C++ Template for Bazel and Google Test

> Can be used in Visual Studio Code

You can use this template for most of your C++ projects without the need for changing the BUILD files.

## Installation

You can copy this using this command:

```bash
git clone https://github.com/ourarash/cpp-template.git
```

### Run main:

You can run this using `blaze`:

```bash
bazel run src/main:main
```

### Run Tests:

You can run unit tests using [`blaze`](installing-bazel):

```bash
bazel test tests:tests
```

## Directory Structure

<img alt="Directory Structure" src="https://github.com/ourarash/cpp-template/blob/master/tree.png?raw=true" width="200">

## Installing Bazel

This repo uses `Bazel` for building C++ files.
You can install Bazel using this [link](https://docs.bazel.build/versions/master/install.html).

### Credit

This repo was inspired by [this post](https://www.ratanparai.com/c++/writing-unit-tests-with-bazel/).
