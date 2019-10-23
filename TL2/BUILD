load("//:lumi.bzl", "lumi_binary")

cc_library(
    name = "lumi",
    srcs = ["lumi.2.c"],
    hdrs = ["lumi.2.h"],
    # This is a workaround for https://github.com/bazelbuild/bazel/issues/6337.
    includes = ["."],
    # strip_include_prefix allows dependending rules to include headers without
    # the prefix.
    strip_include_prefix = "",
    visibility = [
        "//TL3:__pkg__",
        "//lumi-command:__pkg__",
    ],
)

lumi_binary(
    name = "compiler",
    srcs = ["tl2-compiler.1.lm"],
    compiler = "//TL1:compiler",
    lumi_version = 1,
    visibility = ["//visibility:public"],
)
