#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/test.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file18_name = "syntax-tree/test.3.mr";
#endif
#define MR_FILE_NAME _mr_file18_name

/* MR4 compiler - Syntax tree testing nodes */

/* Assert statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeAssert SyntaxTreeAssert;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeAssert {
  SyntaxTreeCode _base;
  Expression* tested;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssert_parse_new(SyntaxTreeAssert* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeAssert** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssert_parse_new = "SyntaxTreeAssert.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssert_parse_new
Returncode SyntaxTreeAssert_parse_new(SyntaxTreeAssert* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeAssert** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeAssert));
  if ((*new_node) == NULL) RAISE(9)
  *(*new_node) = (SyntaxTreeAssert){SyntaxTreeAssert__dtl, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeAssert__dtl;
  CHECK(10, SyntaxTreeAssert_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssert_parse(SyntaxTreeAssert* self, SyntaxTreeBlock* parent, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssert_parse = "SyntaxTreeAssert.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssert_parse
Returncode SyntaxTreeAssert_parse(SyntaxTreeAssert* self, SyntaxTreeBlock* parent, Char* end) {
  self->_base.parent = parent;
  CHECK(14, parse_new_expression(&(String){1, 0, ""}, &(self->tested), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssert_write(SyntaxTreeAssert* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssert_write = "SyntaxTreeAssert.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssert_write
Returncode SyntaxTreeAssert_write(SyntaxTreeAssert* self) {
  CHECK(17, write(&(String){8, 7, "Assert("}) )
  CHECK(18, (self->tested)->_dtl[0](self->tested) )
  CHECK(19, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeAssert__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeAssert__dtl[] = {(void*)SyntaxTreeAssert_write};
#endif


/* Assert-error statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeAssertError SyntaxTreeAssertError;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeAssertError {
  SyntaxTreeCode _base;
  Expression* tested;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssertError_parse_new(SyntaxTreeAssertError* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeAssertError** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssertError_parse_new = "SyntaxTreeAssertError.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssertError_parse_new
Returncode SyntaxTreeAssertError_parse_new(SyntaxTreeAssertError* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeAssertError** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeAssertError));
  if ((*new_node) == NULL) RAISE(28)
  *(*new_node) = (SyntaxTreeAssertError){SyntaxTreeAssertError__dtl, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeAssertError__dtl;
  CHECK(29, SyntaxTreeAssertError_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssertError_parse(SyntaxTreeAssertError* self, SyntaxTreeBlock* parent, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssertError_parse = "SyntaxTreeAssertError.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssertError_parse
Returncode SyntaxTreeAssertError_parse(SyntaxTreeAssertError* self, SyntaxTreeBlock* parent, Char* end) {
  self->_base.parent = parent;
  CHECK(33, parse_new_expression(&(String){1, 0, ""}, &(self->tested), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeAssertError_write(SyntaxTreeAssertError* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeAssertError_write = "SyntaxTreeAssertError.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeAssertError_write
Returncode SyntaxTreeAssertError_write(SyntaxTreeAssertError* self) {
  CHECK(36, write(&(String){13, 12, "AssertError("}) )
  CHECK(37, (self->tested)->_dtl[0](self->tested) )
  CHECK(38, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeAssertError__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeAssertError__dtl[] = {(void*)SyntaxTreeAssertError_write};
#endif


/* Test function in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeTestFunction SyntaxTreeTestFunction;
#elif MR_STAGE == MR_TYPES(4)
struct SyntaxTreeTestFunction {
  SyntaxTreeFunction _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeTestFunction_parse_new(SyntaxTreeTestFunction* self, Char* end, SyntaxTreeTestFunction** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeTestFunction_parse_new = "SyntaxTreeTestFunction.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeTestFunction_parse_new
Returncode SyntaxTreeTestFunction_parse_new(SyntaxTreeTestFunction* self, Char* end, SyntaxTreeTestFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeTestFunction));
  if ((*new_node) == NULL) RAISE(44)
  *(*new_node) = (SyntaxTreeTestFunction){SyntaxTreeTestFunction__dtl, 0, NULL, NULL, NULL, NULL, NULL, NULL};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeTestFunction__dtl;
  CHECK(45, SyntaxTreeFunction_parse(&((*new_node)->_base), NULL, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeTestFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeTestFunction__dtl[] = {(void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBlock_parse_child};
#endif


/* Mock function in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeMockFunction SyntaxTreeMockFunction;
#elif MR_STAGE == MR_TYPES(4)
struct SyntaxTreeMockFunction {
  SyntaxTreeFunction _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMockFunction_parse_new(SyntaxTreeMockFunction* self, Char* end, SyntaxTreeMockFunction** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMockFunction_parse_new = "SyntaxTreeMockFunction.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeMockFunction_parse_new
Returncode SyntaxTreeMockFunction_parse_new(SyntaxTreeMockFunction* self, Char* end, SyntaxTreeMockFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeMockFunction));
  if ((*new_node) == NULL) RAISE(51)
  *(*new_node) = (SyntaxTreeMockFunction){SyntaxTreeMockFunction__dtl, 0, NULL, NULL, NULL, NULL, NULL, NULL};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeMockFunction__dtl;
  CHECK(52, SyntaxTreeFunction_parse(&((*new_node)->_base), NULL, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeMockFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeMockFunction__dtl[] = {(void*)SyntaxTreeFunction_write, (void*)SyntaxTreeBlock_parse_child};
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
