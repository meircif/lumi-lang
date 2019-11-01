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

cc_library(
    name = "dirent-lib",
    hdrs = ["dirent.h"],
)

lumi_library(
    name = "os",
    srcs = ["os.5.lm"],
    deps = [":ds"],
    c_deps = [":dirent-lib"],
    visibility = ["__subpackages__"],
)

lumi_library(
    name = "time",
    srcs = ["time.5.lm"],
    visibility = ["__subpackages__"],
)

lumi_library(
    name = "stdlib",
    srcs = [],
    deps = [
        ":math",
        ":ds",
        ":os",
        ":time",
    ],
    visibility = ["//visibility:public"],
)
