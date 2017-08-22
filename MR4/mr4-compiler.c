#ifndef MR_MAINFILE
#define MR_MAINFILE "mr4-compiler.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file21_name = "mr4-compiler.3.mr";
#endif
#define MR_FILE_NAME _mr_file21_name

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
  /* work in progres... */
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
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "global/type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/variable.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/function.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "syntax-tree/test.c"
#include "syntax-tree/type.c"
#include "syntax-tree/variable.c"
#if MR_STAGE == MR_TYPES(1)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(2)
#elif MR_STAGE == MR_TYPES(2)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(3)
#elif MR_STAGE == MR_TYPES(3)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(4)
#endif
#undef MR_INCLUDES
#endif

#endif
