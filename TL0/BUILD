cc_library(
    name = "lumi",
    srcs = [
        "tl0-file.c",
        "tl0-string.c",
    ],
    hdrs = ["tl0-c-api.h"],
    strip_include_prefix = "",
    visibility = ["//visibility:public"],
)

cc_binary(
    name = "compiler",
    srcs = [
        "tl0-compiler.c",
    ],
    copts = ["-std=c89"],
    visibility = ["//visibility:public"],
    deps = [":lumi"],
)
