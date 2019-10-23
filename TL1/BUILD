load("//:lumi.bzl", "lumi_binary")

cc_library(
    name = "lumi",
    srcs = ["lumi.1.c"],
    hdrs = ["lumi.1.h"],
    # This is a workaround for https://github.com/bazelbuild/bazel/issues/6337.
    includes = ["."],
    # strip_include_prefix allows dependending rules to include headers without
    # the prefix.
    strip_include_prefix = "",
    visibility = [
        "//TL2:__pkg__",
        "//lumi-command:__pkg__",
    ],
)

lumi_binary(
    name = "compiler",
    srcs = ["tl1-compiler.0.lm"],
    compiler = "//TL0:compiler",
    lumi_version = 0,
    visibility = ["//visibility:public"],
)
