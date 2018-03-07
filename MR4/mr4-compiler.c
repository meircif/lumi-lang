#ifndef MR_MAINFILE
#define MR_MAINFILE "mr4-compiler.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file30_name = "mr4-compiler.3.mr";
#endif
#define MR_FILE_NAME _mr_file30_name

/*  MR4 compiler main - written in MR3

A work in progres...

Currently only expression parsing is fully implemented, along with some global
functionality that supports it.

Expression design is documented in expression/expression.3.mr.

Global notes:
  * Because MR3 not supports constructors or class-methods, they are replaced
    by calling instance methods directly with `_` as the self instance.
 */

/* compiler main function! */
#if MR_STAGE == MR_DECLARATIONS
Returncode func(Array* argv);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_func = "func";
#define MR_FUNC_NAME _func_name_func
Returncode func(Array* argv) {
  CHECK(17, Global_init(glob) )
  CHECK(18, SyntaxTreeRoot_parse(glob->root, argv) )
  CHECK(19, (glob->root)->_base._base._base._base._dtl[2](glob->root) )
  CHECK(20, (glob->root)->_base._base._base._base._dtl[4](glob->root) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_FUNCTIONS
MAIN_FUNC
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/argument.c"
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "global/type-instance.c"
#include "expression/base-type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/initialize.c"
#include "expression/slice.c"
#include "expression/symbol.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "statement/enum.c"
#include "statement/error.c"
#include "statement/for.c"
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
#include "statement/type.c"
#include "statement/variable.c"
#if MR_STAGE == MR_TYPES(1)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(2)
#elif MR_STAGE == MR_TYPES(2)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(3)
#elif MR_STAGE == MR_TYPES(3)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(4)
#elif MR_STAGE == MR_TYPES(4)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(5)
#endif
#undef MR_INCLUDES
#endif

#endif
