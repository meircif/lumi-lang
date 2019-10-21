def _generated_c_impl(ctx):
    args = [ctx.outputs.out.path]
    args += [f.path for f in ctx.files.srcs]
    args += [f.path for f in ctx.files.deps]

    ctx.actions.run(
        inputs = ctx.files.srcs + ctx.files.deps,
        outputs = [ctx.outputs.out],
        executable = ctx.file.compiler,
        arguments = args,
        progress_message = "Generating {} from Lumi.".format(ctx.outputs.out.path),
    )

lumi_generated_c = rule(
    attrs = {
        "compiler": attr.label(
            default = Label("//TL5:compiler"),
            allow_single_file = True,
            executable = True,
            cfg = "host",
            doc = "Lumi compiler binary",
        ),
        "srcs": attr.label_list(
            mandatory = True,
            allow_empty = False,
            allow_files = True,
            doc = "Lumi files to compile",
        ),
        "deps": attr.label_list(),
    },
    implementation = _generated_c_impl,
    outputs = {"out": "%{name}.c"},
    output_to_genfiles = True,
)

def lumi_binary(name, srcs, deps, **kwargs):
    generated_name = "{}.gen".format(name)

    lumi_generated_c(
        name = generated_name,
        srcs = srcs,
        deps = deps,
    )

    native.cc_binary(
        name = name,
        srcs = [":" + generated_name],
        deps = [],
        **kwargs
    )
