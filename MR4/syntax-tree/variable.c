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
  String* name;
  Int access;
  TypeInstance* type_instance;
  TypeData* parent_type;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_parse_new(SyntaxTreeVariable* self, Int access, TypeData* parent_type, Char* end, SyntaxTreeVariableInit** new_init_node, SyntaxTreeVariable** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_parse_new = "SyntaxTreeVariable.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_parse_new
Returncode SyntaxTreeVariable_parse_new(SyntaxTreeVariable* self, Int access, TypeData* parent_type, Char* end, SyntaxTreeVariableInit** new_init_node, SyntaxTreeVariable** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeVariable));
  if ((*new_node) == NULL) RAISE(14)
  *(*new_node) = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeVariable__dtl;
  CHECK(15, SyntaxTreeVariable_parse((*new_node), access, parent_type, &((*new_init_node)), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_parse(SyntaxTreeVariable* self, Int access, TypeData* parent_type, SyntaxTreeVariableInit** new_init_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_parse = "SyntaxTreeVariable.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_parse
Returncode SyntaxTreeVariable_parse(SyntaxTreeVariable* self, Int access, TypeData* parent_type, SyntaxTreeVariableInit** new_init_node, Char* end) {
  self->parent_type = parent_type;
  self->access = access;
  self->type_instance = malloc(sizeof(TypeInstance));
  if (self->type_instance == NULL) RAISE(22)
  *self->type_instance = (TypeInstance){NULL, NULL, NULL};
  CHECK(23, TypeInstance_parse(self->type_instance, &(String){2, 1, " "}, &((*end))) )
  if ((*end) != ' ') {
    CHECK(25, f_syntax_error_c(&(String){31, 30, "expected space after type, got"}, (*end)) )
  }
  CHECK(26, read_new(&(String){2, 1, "("}, &(self->name), &((*end))) )
  if ((*end) == '(') {
    CHECK(28, SyntaxTreeVariableInit_parse_new(NULL, self, &((*end)), &((*new_init_node))) )
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
  CHECK(33, TypeInstance_write(self->type_instance) )
  if (self->access != ACCESS_VAR) {
    CHECK(35, write(&(String){2, 1, "*"}) )
  }
  CHECK(36, write(&(String){2, 1, " "}) )
  CHECK(37, write_cname(self->name) )
  CHECK(38, write(&(String){2, 1, ";"}) )
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
  SyntaxTreeVariable* variable;
  Expression* value;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariableInit_parse_new(SyntaxTreeVariableInit* self, SyntaxTreeVariable* variable, Char* end, SyntaxTreeVariableInit** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariableInit_parse_new = "SyntaxTreeVariableInit.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariableInit_parse_new
Returncode SyntaxTreeVariableInit_parse_new(SyntaxTreeVariableInit* self, SyntaxTreeVariable* variable, Char* end, SyntaxTreeVariableInit** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeVariableInit));
  if ((*new_node) == NULL) RAISE(48)
  *(*new_node) = (SyntaxTreeVariableInit){SyntaxTreeVariableInit__dtl, NULL, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeVariableInit__dtl;
  CHECK(49, SyntaxTreeVariableInit_parse((*new_node), variable, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariableInit_parse(SyntaxTreeVariableInit* self, SyntaxTreeVariable* variable, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariableInit_parse = "SyntaxTreeVariableInit.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariableInit_parse
Returncode SyntaxTreeVariableInit_parse(SyntaxTreeVariableInit* self, SyntaxTreeVariable* variable, Char* end) {
  self->variable = variable;
  CHECK(53, parse_new_expression(&(String){2, 1, ")"}, &(self->value), &((*end))) )
  if ((*end) != ')') {
    CHECK(55, f_syntax_error_c(&(String){39, 38, "expected \")\" after initialization, got"}, (*end)) )
  }
  CHECK(58, read_c(&((*end))) )
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
  CHECK(62, write_cname(self->variable->name) )
  CHECK(63, write(&(String){4, 3, " = "}) )
  CHECK(64, (self->value)->_dtl[1](self->value) )
  CHECK(65, write(&(String){2, 1, ";"}) )
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
#include "expression/symbol.c"
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
