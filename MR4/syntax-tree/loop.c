#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/loop.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file15_name = "syntax-tree/loop.3.mr";
#endif
#define MR_FILE_NAME _mr_file15_name

/* MR4 compiler - Syntax tree loops */

/* Basic loop node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeLoop SyntaxTreeLoop;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeLoop {
  SyntaxTreeCode _base;
  SyntaxTreeBlock* block;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeLoop_parse_block(SyntaxTreeLoop* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeLoop_parse_block = "SyntaxTreeLoop.parse-block";
#define MR_FUNC_NAME _func_name_SyntaxTreeLoop_parse_block
Returncode SyntaxTreeLoop_parse_block(SyntaxTreeLoop* self, Char* end) {
  self->block = malloc(sizeof(SyntaxTreeBlock));
  if (self->block == NULL) RAISE(8)
  *self->block = (SyntaxTreeBlock){SyntaxTreeBlock__dtl, 0, NULL, NULL};
  self->block->_base._base._dtl = SyntaxTreeBlock__dtl;
  self->block->_base.indentation_spaces = self->_base.parent->_base.indentation_spaces + 2;
  CHECK(10, SyntaxTreeBlock_parse_block(self->block, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeLoop_write_block(SyntaxTreeLoop* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeLoop_write_block = "SyntaxTreeLoop.write-block";
#define MR_FUNC_NAME _func_name_SyntaxTreeLoop_write_block
Returncode SyntaxTreeLoop_write_block(SyntaxTreeLoop* self) {
  CHECK(13, SyntaxTreeBlock_write_block(self->block) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeLoop__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeLoop__dtl[] = {(void*)SyntaxTreeNode_write};
#endif


/* Do loop node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeDoLoop SyntaxTreeDoLoop;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeDoLoop {
  SyntaxTreeLoop _base;
  SyntaxTreeBlock* block;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeDoLoop_parse_new(SyntaxTreeDoLoop* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeDoLoop** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeDoLoop_parse_new = "SyntaxTreeDoLoop.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeDoLoop_parse_new
Returncode SyntaxTreeDoLoop_parse_new(SyntaxTreeDoLoop* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeDoLoop** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeDoLoop));
  if ((*new_node) == NULL) RAISE(22)
  *(*new_node) = (SyntaxTreeDoLoop){SyntaxTreeDoLoop__dtl, NULL, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeDoLoop__dtl;
  CHECK(23, SyntaxTreeDoLoop_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeDoLoop_parse(SyntaxTreeDoLoop* self, SyntaxTreeBlock* parent, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeDoLoop_parse = "SyntaxTreeDoLoop.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeDoLoop_parse
Returncode SyntaxTreeDoLoop_parse(SyntaxTreeDoLoop* self, SyntaxTreeBlock* parent, Char* end) {
  self->_base._base.parent = parent;
  CHECK(27, SyntaxTreeLoop_parse_block(&(self->_base), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeDoLoop_write(SyntaxTreeDoLoop* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeDoLoop_write = "SyntaxTreeDoLoop.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeDoLoop_write
Returncode SyntaxTreeDoLoop_write(SyntaxTreeDoLoop* self) {
  CHECK(30, write(&(String){3, 2, "do"}) )
  CHECK(31, SyntaxTreeLoop_write_block(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeDoLoop__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeDoLoop__dtl[] = {(void*)SyntaxTreeDoLoop_write};
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
#endif
#undef MR_INCLUDES
#endif

#endif
