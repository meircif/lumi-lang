cc_library(
    name = "lumi",
    srcs = ["lumi.4.c"],
    hdrs = ["lumi.4.h"],
    # strip_include_prefix allows dependending rules to include headers without
    # the TL4 prefix.
    strip_include_prefix = "",
    # This is a workaround for https://github.com/bazelbuild/bazel/issues/6337.
    includes = ["."],
    visibility = [
    	"//TL5:__pkg__",
    	"//lumi-command:__pkg__",
    ],
)
