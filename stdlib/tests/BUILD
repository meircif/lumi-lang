load("//:lumi.bzl", "lumi_test")

lumi_test(
    name = "math-tests",
    srcs = ["math-tests.5.lm"],
    tested_module = "math",
    deps = ["//stdlibs:math"],
)

lumi_test(
    name = "ds-tests",
    srcs = ["ds-tests.5.lm"],
    tested_module = "ds",
    deps = ["//stdlibs:ds"],
)

cc_library(
    name = "mock-time-lib",
    hdrs = ["time.h"],
    strip_include_prefix = "",
)

cc_library(
    name = "mock-dirent-lib",
    hdrs = ["dirent.h"],
    strip_include_prefix = "",
)

lumi_test(
    name = "time-tests",
    srcs = ["time-tests.5.lm"],
    c_deps = [":mock-time-lib"],
    tested_module = "time",
    deps = ["//stdlibs:time"],
)

lumi_test(
    name = "os-tests",
    srcs = ["os-test.5.lm"],
    c_deps = [":mock-dirent-lib"],
    tested_module = "os",
    deps = ["//stdlibs:os"],
)
