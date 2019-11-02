cc_binary(
    name = "compiler",
    srcs = ["tl5-compiler.c"],
    copts = [
        "-Wno-unused-label",
        "-Wno-unused-variable",
        "-Wno-unused-but-set-variable",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//TL4:lumi",
    ],
)
