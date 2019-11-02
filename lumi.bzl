"""Build rules and macros for the Lumi programming language."""


LumiFiles = provider(fields = ["transitive_sources"])


def get_transitive_srcs(srcs, deps):
  """Obtain the source files for a target and its transitive dependencies.

  Args:
    srcs: a list of source files
    deps: a list of targets that are direct dependencies
  Returns:
    a collection of the transitive sources
  """
  return depset(
        srcs,
        transitive = [dep[LumiFiles].transitive_sources for dep in deps])


def _lumi_library_impl(ctx):
    """Gather transitive srcs, don't actually compile."""
    trans_srcs = get_transitive_srcs(ctx.files.srcs, ctx.attr.deps)
    return [LumiFiles(transitive_sources=trans_srcs)]


lumi_library = rule(
    implementation = _lumi_library_impl,
    attrs = {
        "srcs": attr.label_list(allow_files=True),
        "deps": attr.label_list(),
        "c_deps": attr.label_list(),
    },
)


def _generated_c_impl(ctx):
    """Run Lumi compiler on input files to generate a C file."""
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
        args = []
        if ctx.attr.tested_module:
            args += ["-t", ctx.attr.tested_module]
        args += [ctx.outputs.out.path]

        trans_srcs = get_transitive_srcs(ctx.files.srcs, ctx.attr.deps)
        srcs_list = trans_srcs.to_list()
        args += [src.path for src in srcs_list]

        ctx.actions.run(
            inputs = srcs_list,
            outputs = [ctx.outputs.out],
            tools = [ctx.file.compiler],
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
            # This should probably be "host", but it makes the build much
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
        "deps": attr.label_list(allow_files = False),
        "c_deps": attr.label_list(allow_files = False),
        "tested_module": attr.string(mandatory = False),
    },
    implementation = _generated_c_impl,
    outputs = {"out": "%{name}.c"},
    output_to_genfiles = True,
)


def lumi_binary(name, srcs, **kwargs):
    """Create a binary from Lumi sources."""
    lumi_version = kwargs.pop("lumi_version", 5)
    generated_name = "{}.gen".format(name)
    deps = kwargs.pop("deps", [])
    c_deps = kwargs.pop("c_deps", [])
    tested_module = kwargs.pop("tested_module", None)

    lumi_generated_c(
        name = generated_name,
        srcs = srcs,
        deps = deps,
        compiler = kwargs.pop("compiler", None),
        lumi_version = lumi_version,
        tested_module = tested_module,
    )

    deps = []
    if lumi_version in (2, 3, 4):
        fail("lumi_binary does not support Lumi version {}"
            .format(lumi_version))

    if lumi_version == 0:
        deps += ["//TL0:lumi"]
    elif lumi_version == 1:
        deps += ["//TL1:lumi"]

    cc_rule = native.cc_test if tested_module else native.cc_binary

    cc_rule(
        name = name,
        srcs = [":" + generated_name],
        deps = c_deps,
        copts = [
            "-std=c89",
            "-Wno-unused-label",
            "-Wno-unused-variable",
            "-Wno-unused-but-set-variable",
            "-Wno-misleading-indentation",
            "-Wno-parentheses",
        ],
        **kwargs
    )


def lumi_test(name, srcs, tested_module, **kwargs):
    """Create a test binary from Lumi sources."""
    if not tested_module:
        fail("lumi_test must have a valid tested_module specified.")
    kwargs["tested_module"] = tested_module
    lumi_binary(name, srcs, **kwargs)

