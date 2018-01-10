#ifndef MR_MAINFILE
#define MR_MAINFILE "statement/error.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file22_name = "statement/error.3.mr";
#endif
#define MR_FILE_NAME _mr_file22_name

/* MR4 compiler - Syntax tree error handling nodes */

#if MR_STAGE == MR_DECLARATIONS
extern Int try_depth_count;
#elif MR_STAGE == MR_FUNCTIONS
Int try_depth_count = 0;
#endif

/* Try statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeTry SyntaxTreeTry;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeTry {
  SyntaxTreeFlowElement _base;
  SyntaxTreeCatch* catch_node;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeTry_parse_new(SyntaxTreeTry* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeTry** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeTry_parse_new = "SyntaxTreeTry.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeTry_parse_new
Returncode SyntaxTreeTry_parse_new(SyntaxTreeTry* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeTry** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeTry));
  if ((*new_node) == NULL) RAISE(11)
  *(*new_node) = (SyntaxTreeTry){SyntaxTreeTry__dtl, NULL, 0, NULL, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeTry__dtl;
  CHECK(12, SyntaxTreeNode_set_location(&((*new_node)->_base._base._base)) )
  CHECK(13, SyntaxTreeFlowElement_parse_block(&((*new_node)->_base), parent, false, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeTry_write(SyntaxTreeTry* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeTry_write = "SyntaxTreeTry.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeTry_write
Returncode SyntaxTreeTry_write(SyntaxTreeTry* self) {
  CHECK(16, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(17, write(&(String){6, 5, "do {\n"}) )
  self->_base._base.parent->_base.indentation_spaces += 2;
  CHECK(19, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(20, write(&(String){26, 25, "++MR_trace_ignore_count;\n"}) )
  if (try_depth_count == 0) {
    CHECK(22, write(&(String){21, 20, "#undef RETURN_ERROR\n"}) )
    CHECK(23, write(&(String){51, 50, "#define RETURN_ERROR(value) MR_err = value; break\n"}) )
  }
  try_depth_count += 1;
  
  CHECK(26, SyntaxTreeBlock_write_block_body(self->_base.block) )
  
  try_depth_count -= 1;
  if (try_depth_count == 0) {
    CHECK(30, write(&(String){22, 21, "\n#undef RETURN_ERROR\n"}) )
    CHECK(31, write(&(String){61, 60, "#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup\n"}) )
  }
  self->_base._base.parent->_base.indentation_spaces -= 2;
  CHECK(34, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(35, write(&(String){18, 17, "} while (false);\n"}) )
  CHECK(36, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(37, write(&(String){26, 25, "--MR_trace_ignore_count;\n"}) )
  if (!(NULL != self->catch_node)) {
    CHECK(39, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
    CHECK(40, write(&(String){14, 13, "MR_err = OK;\n"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeTry__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeTry__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeFlowElement_link_types, (void*)SyntaxTreeFlowElement_analyze, (void*)SyntaxTreeTry_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Catch statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeCatch SyntaxTreeCatch;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeCatch {
  SyntaxTreeFlowElement _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCatch_parse_new(SyntaxTreeCatch* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeCatch** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCatch_parse_new = "SyntaxTreeCatch.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeCatch_parse_new
Returncode SyntaxTreeCatch_parse_new(SyntaxTreeCatch* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeCatch** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeCatch));
  if ((*new_node) == NULL) RAISE(47)
  *(*new_node) = (SyntaxTreeCatch){SyntaxTreeCatch__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeCatch__dtl;
  CHECK(48, SyntaxTreeNode_set_location(&((*new_node)->_base._base._base)) )
  CHECK(49, SyntaxTreeFlowElement_parse_block(&((*new_node)->_base), parent, false, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCatch_write(SyntaxTreeCatch* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCatch_write = "SyntaxTreeCatch.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeCatch_write
Returncode SyntaxTreeCatch_write(SyntaxTreeCatch* self) {
  CHECK(52, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(53, write(&(String){21, 20, "if (MR_err != OK) {\n"}) )
  CHECK(54, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(55, write(&(String){16, 15, "  MR_err = OK;\n"}) )
  CHECK(56, SyntaxTreeBlock_write_block_body(self->_base.block) )
  CHECK(57, SyntaxTreeBlock_write_block_end(self->_base.block) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeCatch__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeCatch__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeFlowElement_link_types, (void*)SyntaxTreeFlowElement_analyze, (void*)SyntaxTreeCatch_write, (void*)SyntaxTreeCode_m_is_end_point};
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
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
#include "statement/type.c"
#include "statement/variable.c"
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
