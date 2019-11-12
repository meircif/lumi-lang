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
    copts = [
        "-std=c89",
        "-Wno-unused-label",
        "-Wno-unused-variable",
        "-Wno-unused-but-set-variable",
        "-Wno-misleading-indentation",
    ],
    visibility = ["//visibility:public"],
    deps = [":lumi"],
)
