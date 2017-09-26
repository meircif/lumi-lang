#ifndef MR_MAINFILE
#define MR_MAINFILE "global/type.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file6_name = "global/type.3.mr";
#endif
#define MR_FILE_NAME _mr_file6_name

/* MR4 compiler - Meta types - should be moved from here... */


/* Meta type of an operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Operator Operator;
#elif MR_STAGE == MR_TYPES(0)
struct Operator {
  String* name;
  String* c_name;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Operator_init(Operator* self, String* name, String* c_name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Operator_init = "Operator.init";
#define MR_FUNC_NAME _func_name_Operator_init
Returncode Operator_init(Operator* self, String* name, String* c_name) {
  CHECK(10, string_new_copy(name, &(self->name)) )
  CHECK(11, string_new_copy(c_name, &(self->c_name)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/symbol.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/function.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "syntax-tree/test.c"
#include "syntax-tree/type.c"
#include "syntax-tree/variable.c"
#include "mr4-compiler.c"
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
