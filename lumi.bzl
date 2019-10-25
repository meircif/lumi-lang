def _generated_c_impl(ctx):
    lumi_version = ctx.attr.lumi_version

    if lumi_version in (0, 1):
        # Only accepts one input.
        if (ctx.files.deps) or len(ctx.files.srcs) > 1:
            fail("Lumi 0 compiler only support one input file")
        args = [ctx.files.srcs[0].path]
        args += [ctx.outputs.out.path]
        ctx.actions.run(
            inputs = ctx.files.srcs + ctx.files.deps,
            outputs = [ctx.outputs.out],
            executable = ctx.file.compiler,
            arguments = args,
            progress_message =
                "Generating {} from Lumi.".format(ctx.outputs.out.path),
        )

    elif lumi_version in (5,):
        args = [ctx.outputs.out.path]
        args += [f.path for f in ctx.files.deps]
        args += [f.path for f in ctx.files.srcs]

        ctx.actions.run(
            inputs = ctx.files.srcs + ctx.files.deps,
            outputs = [ctx.outputs.out],
            executable = ctx.file.compiler,
            arguments = args,
            progress_message =
                "Generating {} from Lumi.".format(ctx.outputs.out.path),
        )

lumi_generated_c = rule(
    attrs = {
        "compiler": attr.label(
            default = Label("//TL5:compiler"),
            allow_single_file = True,
            executable = True,
            # This should probably be "host", but it's makes the build much
            # slower, and we're not cross-compiling just yet.
            cfg = "target",
            doc = "Lumi compiler binary",
        ),
        "lumi_version": attr.int(default = 5),
        "srcs": attr.label_list(
            mandatory = True,
            allow_empty = False,
            allow_files = True,
            doc = "Lumi files to compile",
        ),
        "deps": attr.label_list(
            mandatory = False,
            allow_empty = True,
        ),
    },
    implementation = _generated_c_impl,
    outputs = {"out": "%{name}.c"},
    output_to_genfiles = True,
)

def lumi_binary(name, srcs, **kwargs):
    lumi_version = kwargs.pop("lumi_version", 5)
    generated_name = "{}.gen".format(name)

    lumi_generated_c(
        name = generated_name,
        srcs = srcs,
        deps = kwargs.pop("deps", []),
        compiler = kwargs.pop("compiler", None),
        lumi_version = lumi_version,
    )

    deps = []
    if lumi_version in (2, 3, 4):
        fail("lumi_binary does not support Lumi version {}"
            .format(lumi_version))

    if lumi_version == 0:
        deps += ["//TL0:lumi"]
    elif lumi_version == 1:
        deps += ["//TL1:lumi"]

    native.cc_binary(
        name = name,
        srcs = [":" + generated_name],
        deps = deps,
        copts = [
            "-Wno-unused-label",
            "-Wno-unused-variable",
            "-Wno-unused-but-set-variable",
            "-Wno-misleading-indentation",
            "-Wno-parentheses",
        ],
        **kwargs
    )
