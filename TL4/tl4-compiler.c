#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "tl4-compiler.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file30_name = "tl4-compiler.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file30_name

/* TL4 compiler main - written in TL3 */

/* compiler main function! */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode func(Array* argv);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_func = "func";
#define LUMI_FUNC_NAME _func_name_func
Returncode func(Array* argv) {
  CHECK(5, Global_init(glob) )
  CHECK(6, SyntaxTreeRoot_parse(glob->root, argv) )
  CHECK(7, (glob->root)->_base._base._base._base._dtl[2](glob->root) )
  CHECK(8, (glob->root)->_base._base._base._base._dtl[4](glob->root) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_FUNCTIONS
MAIN_FUNC
#endif

#undef LUMI_FILE_NAME

#ifndef LUMI_INCLUDES
#define LUMI_INCLUDES
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
#if LUMI_STAGE == LUMI_TYPES(1)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(2)
#elif LUMI_STAGE == LUMI_TYPES(2)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(3)
#elif LUMI_STAGE == LUMI_TYPES(3)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(4)
#elif LUMI_STAGE == LUMI_TYPES(4)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(5)
#endif
#undef LUMI_INCLUDES
#endif

#endif
