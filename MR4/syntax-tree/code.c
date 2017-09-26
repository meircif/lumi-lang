#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/code.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file13_name = "syntax-tree/code.3.mr";
#endif
#define MR_FILE_NAME _mr_file13_name

/* MR4 compiler - Syntax tree code nodes */

/* Expression node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeExpression SyntaxTreeExpression;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeExpression {
  SyntaxTreeCode _base;
  Expression* expression;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeExpression_parse_new(SyntaxTreeExpression* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeExpression** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeExpression_parse_new = "SyntaxTreeExpression.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeExpression_parse_new
Returncode SyntaxTreeExpression_parse_new(SyntaxTreeExpression* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeExpression** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeExpression));
  if ((*new_node) == NULL) RAISE(9)
  *(*new_node) = (SyntaxTreeExpression){SyntaxTreeExpression__dtl, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeExpression__dtl;
  CHECK(10, SyntaxTreeExpression_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeExpression_parse(SyntaxTreeExpression* self, SyntaxTreeBlock* parent, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeExpression_parse = "SyntaxTreeExpression.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeExpression_parse
Returncode SyntaxTreeExpression_parse(SyntaxTreeExpression* self, SyntaxTreeBlock* parent, Char* end) {
  self->_base.parent = parent;
  CHECK(14, parse_new_expression(&(String){1, 0, ""}, &(self->expression), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeExpression_write(SyntaxTreeExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeExpression_write = "SyntaxTreeExpression.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeExpression_write
Returncode SyntaxTreeExpression_write(SyntaxTreeExpression* self) {
  CHECK(17, (self->expression)->_dtl[1](self->expression) )
  CHECK(18, write(&(String){2, 1, ";"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeExpression__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeExpression_write};
#endif


/* Return statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeReturn SyntaxTreeReturn;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeReturn {
  SyntaxTreeCode _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeReturn_parse_new(SyntaxTreeReturn* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeReturn** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeReturn_parse_new = "SyntaxTreeReturn.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeReturn_parse_new
Returncode SyntaxTreeReturn_parse_new(SyntaxTreeReturn* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeReturn** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeReturn));
  if ((*new_node) == NULL) RAISE(26)
  *(*new_node) = (SyntaxTreeReturn){SyntaxTreeReturn__dtl, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeReturn__dtl;
  (*new_node)->_base.parent = parent;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeReturn_write(SyntaxTreeReturn* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeReturn_write = "SyntaxTreeReturn.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeReturn_write
Returncode SyntaxTreeReturn_write(SyntaxTreeReturn* self) {
  CHECK(30, write(&(String){11, 10, "return OK;"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeReturn__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeReturn__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeReturn_write};
#endif


/* Raise statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeRaise SyntaxTreeRaise;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeRaise {
  SyntaxTreeCode _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRaise_parse_new(SyntaxTreeRaise* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeRaise** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRaise_parse_new = "SyntaxTreeRaise.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeRaise_parse_new
Returncode SyntaxTreeRaise_parse_new(SyntaxTreeRaise* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeRaise** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeRaise));
  if ((*new_node) == NULL) RAISE(38)
  *(*new_node) = (SyntaxTreeRaise){SyntaxTreeRaise__dtl, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeRaise__dtl;
  (*new_node)->_base.parent = parent;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRaise_write(SyntaxTreeRaise* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRaise_write = "SyntaxTreeRaise.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeRaise_write
Returncode SyntaxTreeRaise_write(SyntaxTreeRaise* self) {
  CHECK(42, write(&(String){12, 11, "return ERR;"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeRaise__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeRaise__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeRaise_write};
#endif


/* While statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeWhile SyntaxTreeWhile;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeWhile {
  SyntaxTreeCode _base;
  Expression* condition;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeWhile_parse_new(SyntaxTreeWhile* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeWhile** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeWhile_parse_new = "SyntaxTreeWhile.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeWhile_parse_new
Returncode SyntaxTreeWhile_parse_new(SyntaxTreeWhile* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeWhile** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeWhile));
  if ((*new_node) == NULL) RAISE(51)
  *(*new_node) = (SyntaxTreeWhile){SyntaxTreeWhile__dtl, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeWhile__dtl;
  CHECK(52, SyntaxTreeWhile_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeWhile_parse(SyntaxTreeWhile* self, SyntaxTreeBlock* parent, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeWhile_parse = "SyntaxTreeWhile.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeWhile_parse
Returncode SyntaxTreeWhile_parse(SyntaxTreeWhile* self, SyntaxTreeBlock* parent, Char* end) {
  self->_base.parent = parent;
  CHECK(56, parse_new_expression(&(String){1, 0, ""}, &(self->condition), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeWhile_write(SyntaxTreeWhile* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeWhile_write = "SyntaxTreeWhile.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeWhile_write
Returncode SyntaxTreeWhile_write(SyntaxTreeWhile* self) {
  /* if (!(`condition`) break; */
  CHECK(60, write(&(String){7, 6, "if (!("}) )
  CHECK(61, (self->condition)->_dtl[1](self->condition) )
  CHECK(62, write(&(String){10, 9, ")) break;"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeWhile__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeWhile__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeWhile_write};
#endif


/* Continue statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeContinue SyntaxTreeContinue;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeContinue {
  SyntaxTreeCode _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeContinue_parse_new(SyntaxTreeContinue* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeContinue** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeContinue_parse_new = "SyntaxTreeContinue.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeContinue_parse_new
Returncode SyntaxTreeContinue_parse_new(SyntaxTreeContinue* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeContinue** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeContinue));
  if ((*new_node) == NULL) RAISE(70)
  *(*new_node) = (SyntaxTreeContinue){SyntaxTreeContinue__dtl, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeContinue__dtl;
  (*new_node)->_base.parent = parent;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeContinue_write(SyntaxTreeContinue* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeContinue_write = "SyntaxTreeContinue.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeContinue_write
Returncode SyntaxTreeContinue_write(SyntaxTreeContinue* self) {
  CHECK(74, write(&(String){10, 9, "continue;"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeContinue__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeContinue__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeContinue_write};
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
#include "expression/symbol.c"
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
