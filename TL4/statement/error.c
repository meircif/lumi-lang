#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "statement/error.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file24_name = "statement/error.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file24_name

/* TL4 compiler - Syntax tree error handling nodes */

#if LUMI_STAGE == LUMI_DECLARATIONS
extern Int try_depth_count;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Int try_depth_count = 0;
#endif

/* Try statement in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeTry SyntaxTreeTry;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct SyntaxTreeTry {
  SyntaxTreeFlowElement _base;
  SyntaxTreeCatch* catch_node;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeTry_parse_new(SyntaxTreeTry* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeTry** new_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeTry_parse_new = "SyntaxTreeTry.parse-new";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeTry_parse_new
Returncode SyntaxTreeTry_parse_new(SyntaxTreeTry* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeTry** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeTry));
  if ((*new_node) == NULL) RAISE(11)
  *(*new_node) = (SyntaxTreeTry){SyntaxTreeTry__dtl, NULL, 0, NULL, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeTry__dtl;
  CHECK(12, SyntaxTreeFlowElement_init(&((*new_node)->_base), parent) )
  CHECK(13, SyntaxTreeFlowElement_parse_block(&((*new_node)->_base), false, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeTry_analyze(SyntaxTreeTry* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeTry_analyze = "SyntaxTreeTry.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeTry_analyze
Returncode SyntaxTreeTry_analyze(SyntaxTreeTry* self) {
  if (!(NULL != self->_base.block->code_nodes->first)) {
    CHECK(17, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){29, 28, "\"try\" statement with no code"}) )
  }
  CHECK(18, SyntaxTreeFlowElement_analyze(&(self->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeTry_write(SyntaxTreeTry* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeTry_write = "SyntaxTreeTry.write";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeTry_write
Returncode SyntaxTreeTry_write(SyntaxTreeTry* self) {
  CHECK(21, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(22, write(&(String){6, 5, "do {\n"}) )
  self->_base._base.parent->_base.indentation_spaces += 2;
  CHECK(24, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(25, write(&(String){28, 27, "++LUMI_trace_ignore_count;\n"}) )
  if (try_depth_count == 0) {
    CHECK(27, write(&(String){21, 20, "#undef RETURN_ERROR\n"}) )
    CHECK(28, write(&(String){53, 52, "#define RETURN_ERROR(value) LUMI_err = value; break\n"}) )
  }
  try_depth_count += 1;
  
  CHECK(31, (self->_base.block)->_base._base._dtl[9](self->_base.block) )
  
  try_depth_count -= 1;
  if (try_depth_count == 0) {
    CHECK(35, write(&(String){22, 21, "\n#undef RETURN_ERROR\n"}) )
    CHECK(36, write(&(String){65, 64, "#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup\n"}) )
  }
  self->_base._base.parent->_base.indentation_spaces -= 2;
  CHECK(39, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(40, write(&(String){18, 17, "} while (false);\n"}) )
  CHECK(41, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(42, write(&(String){28, 27, "--LUMI_trace_ignore_count;\n"}) )
  if (!(NULL != self->catch_node)) {
    CHECK(44, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
    CHECK(45, write(&(String){16, 15, "LUMI_err = OK;\n"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeTry__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeTry__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeFlowElement_link_types, (void*)SyntaxTreeTry_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeTry_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Catch statement in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeCatch SyntaxTreeCatch;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct SyntaxTreeCatch {
  SyntaxTreeFlowElement _base;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeCatch_parse_new(SyntaxTreeCatch* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeCatch** new_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeCatch_parse_new = "SyntaxTreeCatch.parse-new";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeCatch_parse_new
Returncode SyntaxTreeCatch_parse_new(SyntaxTreeCatch* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeCatch** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeCatch));
  if ((*new_node) == NULL) RAISE(52)
  *(*new_node) = (SyntaxTreeCatch){SyntaxTreeCatch__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeCatch__dtl;
  CHECK(53, SyntaxTreeFlowElement_init(&((*new_node)->_base), parent) )
  CHECK(54, SyntaxTreeFlowElement_parse_block(&((*new_node)->_base), false, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeCatch_analyze(SyntaxTreeCatch* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeCatch_analyze = "SyntaxTreeCatch.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeCatch_analyze
Returncode SyntaxTreeCatch_analyze(SyntaxTreeCatch* self) {
  if (!(NULL != self->_base.block->code_nodes->first)) {
    CHECK(58, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){31, 30, "\"catch\" statement with no code"}) )
  }
  CHECK(59, SyntaxTreeFlowElement_analyze(&(self->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeCatch_write(SyntaxTreeCatch* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeCatch_write = "SyntaxTreeCatch.write";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeCatch_write
Returncode SyntaxTreeCatch_write(SyntaxTreeCatch* self) {
  CHECK(62, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(63, write(&(String){23, 22, "if (LUMI_err != OK) {\n"}) )
  CHECK(64, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(65, write(&(String){18, 17, "  LUMI_err = OK;\n"}) )
  CHECK(66, (self->_base.block)->_base._base._dtl[9](self->_base.block) )
  CHECK(67, SyntaxTreeBlock_write_block_end(self->_base.block) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeCatch__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeCatch__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeFlowElement_link_types, (void*)SyntaxTreeCatch_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeCatch_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif

#undef LUMI_FILE_NAME

#ifndef LUMI_INCLUDES
#define LUMI_INCLUDES
#include "tl4-compiler.c"
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
