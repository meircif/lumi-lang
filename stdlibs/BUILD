load("//:lumi.bzl", "lumi_library")

lumi_library(
    name = "math",
    srcs = ["math.5.lm"],
    visibility = ["__subpackages__"],
)

lumi_library(
    name = "ds",
    srcs = ["list.5.lm"],
    visibility = ["__subpackages__"],
)

lumi_library(
    name = "os",
    srcs = ["os.5.lm"],
    visibility = ["__subpackages__"],
    deps = [":ds"],
)

lumi_library(
    name = "time",
    srcs = ["time.5.lm"],
    visibility = ["__subpackages__"],
)

lumi_library(
    name = "stdlib",
    srcs = [],
    visibility = ["//visibility:public"],
    deps = [
        ":ds",
        ":math",
        ":os",
        ":time",
    ],
)
