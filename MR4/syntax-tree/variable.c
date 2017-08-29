#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/variable.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file20_name = "syntax-tree/variable.3.mr";
#endif
#define MR_FILE_NAME _mr_file20_name

/* MR4 compiler - Syntax tree variable */

/* Variable node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeVariable SyntaxTreeVariable;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeVariable {
  SyntaxTreeCode _base;
  Variable* variable;
  SyntaxTreeType* parent_type;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_parse_new(SyntaxTreeVariable* self, Int access, SyntaxTreeType* parent_type, Char* end, SyntaxTreeVariableInit** new_init_node, SyntaxTreeVariable** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_parse_new = "SyntaxTreeVariable.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_parse_new
Returncode SyntaxTreeVariable_parse_new(SyntaxTreeVariable* self, Int access, SyntaxTreeType* parent_type, Char* end, SyntaxTreeVariableInit** new_init_node, SyntaxTreeVariable** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeVariable));
  if ((*new_node) == NULL) RAISE(12)
  *(*new_node) = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeVariable__dtl;
  CHECK(13, SyntaxTreeVariable_parse((*new_node), access, parent_type, &((*new_init_node)), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_parse(SyntaxTreeVariable* self, Int access, SyntaxTreeType* parent_type, SyntaxTreeVariableInit** new_init_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_parse = "SyntaxTreeVariable.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_parse
Returncode SyntaxTreeVariable_parse(SyntaxTreeVariable* self, Int access, SyntaxTreeType* parent_type, SyntaxTreeVariableInit** new_init_node, Char* end) {
  self->parent_type = parent_type;
  self->variable = malloc(sizeof(Variable));
  if (self->variable == NULL) RAISE(19)
  *self->variable = (Variable){NULL, 0, NULL};
  self->variable->access = access;
  self->variable->type_instance = malloc(sizeof(TypeInstance));
  if (self->variable->type_instance == NULL) RAISE(21)
  *self->variable->type_instance = (TypeInstance){NULL, NULL};
  CHECK(22, TypeInstance_parse(self->variable->type_instance, &(String){2, 1, " "}, &((*end))) )
  if ((*end) != ' ') {
    CHECK(24, f_syntax_error_c(&(String){31, 30, "expected space after type, got"}, (*end)) )
  }
  CHECK(25, read_new(&(String){2, 1, "("}, &(self->variable->name), &((*end))) )
  if ((*end) == '(') {
    CHECK(27, SyntaxTreeVariableInit_parse_new(NULL, self->variable, &((*end)), &((*new_init_node))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_write(SyntaxTreeVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_write = "SyntaxTreeVariable.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_write
Returncode SyntaxTreeVariable_write(SyntaxTreeVariable* self) {
  /* `type`* `name`; */
  CHECK(32, TypeInstance_write(self->variable->type_instance) )
  if (self->variable->access != ACCESS_VAR) {
    CHECK(34, write(&(String){2, 1, "*"}) )
  }
  CHECK(35, write(&(String){2, 1, " "}) )
  CHECK(36, write_cname(self->variable->name) )
  CHECK(37, write(&(String){2, 1, ";"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeVariable__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeVariable__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeVariable_write};
#endif


/* Variable initialization node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeVariableInit SyntaxTreeVariableInit;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeVariableInit {
  SyntaxTreeCode _base;
  Variable* variable;
  Expression* value;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariableInit_parse_new(SyntaxTreeVariableInit* self, Variable* variable, Char* end, SyntaxTreeVariableInit** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariableInit_parse_new = "SyntaxTreeVariableInit.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariableInit_parse_new
Returncode SyntaxTreeVariableInit_parse_new(SyntaxTreeVariableInit* self, Variable* variable, Char* end, SyntaxTreeVariableInit** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeVariableInit));
  if ((*new_node) == NULL) RAISE(47)
  *(*new_node) = (SyntaxTreeVariableInit){SyntaxTreeVariableInit__dtl, NULL, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeVariableInit__dtl;
  CHECK(48, SyntaxTreeVariableInit_parse((*new_node), variable, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariableInit_parse(SyntaxTreeVariableInit* self, Variable* variable, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariableInit_parse = "SyntaxTreeVariableInit.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariableInit_parse
Returncode SyntaxTreeVariableInit_parse(SyntaxTreeVariableInit* self, Variable* variable, Char* end) {
  self->variable = variable;
  CHECK(52, parse_new_expression(&(String){2, 1, ")"}, &(self->value), &((*end))) )
  if ((*end) != ')') {
    CHECK(54, f_syntax_error_c(&(String){39, 38, "expected \")\" after initialization, got"}, (*end)) )
  }
  CHECK(57, read_c(&((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariableInit_write(SyntaxTreeVariableInit* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariableInit_write = "SyntaxTreeVariableInit.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariableInit_write
Returncode SyntaxTreeVariableInit_write(SyntaxTreeVariableInit* self) {
  /* `name` = `value`; */
  CHECK(61, write_cname(self->variable->name) )
  CHECK(62, write(&(String){4, 3, " = "}) )
  CHECK(63, (self->value)->_dtl[0](self->value) )
  CHECK(64, write(&(String){2, 1, ";"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeVariableInit__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeVariableInit__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeVariableInit_write};
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
