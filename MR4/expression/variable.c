#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/variable.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file11_name = "expression/variable.3.mr";
#endif
#define MR_FILE_NAME _mr_file11_name

/* MR4 compiler - Variable expression */

/* A single variable expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Variable_expression Variable_expression;
#elif MR_STAGE == MR_TYPES(2)
struct Variable_expression {
  Text_expression _base;
  Variable* variable;
/* parsing `variable` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Variable_expression_parse_new(Variable_expression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Variable_expression_parse_new = "Variable-expression.parse-new";
#define MR_FUNC_NAME _func_name_Variable_expression_parse_new
Returncode Variable_expression_parse_new(Variable_expression* self, String* text, Expression** expression) {
  Variable_expression* variable_expression = malloc(sizeof(Variable_expression));
  if (variable_expression == NULL) RAISE(8)
  *variable_expression = (Variable_expression){Variable_expression__dtl, NULL, NULL, NULL};
  variable_expression->_base._base._dtl = Variable_expression__dtl;
  CHECK(9, Variable_expression_parse(variable_expression, text) )
  (*expression) = &(variable_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `variable` */
#if MR_STAGE == MR_DECLARATIONS
Returncode Variable_expression_parse(Variable_expression* self, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Variable_expression_parse = "Variable-expression.parse";
#define MR_FUNC_NAME _func_name_Variable_expression_parse
Returncode Variable_expression_parse(Variable_expression* self, String* text) {
  self->_base.text = text;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Variable_expression_write(Variable_expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Variable_expression_write = "Variable-expression.write";
#define MR_FUNC_NAME _func_name_Variable_expression_write
Returncode Variable_expression_write(Variable_expression* self) {
  CHECK(17, Text_expression_write_text(&(self->_base), &(String){9, 8, "Variable"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Variable_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Variable_expression__dtl[] = {Variable_expression_write};
#endif

/* The `base` method expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Base_meth_expression Base_meth_expression;
#elif MR_STAGE == MR_TYPES(1)
struct Base_meth_expression {
  Expression _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Base_meth_expression_parse_new(Base_meth_expression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Base_meth_expression_parse_new = "Base-meth-expression.parse-new";
#define MR_FUNC_NAME _func_name_Base_meth_expression_parse_new
Returncode Base_meth_expression_parse_new(Base_meth_expression* self, String* text, Expression** expression) {
  Base_meth_expression* _Base_meth_expression26 = malloc(sizeof(Base_meth_expression));
  if (_Base_meth_expression26 == NULL) RAISE(22)
  *_Base_meth_expression26 = (Base_meth_expression){Base_meth_expression__dtl, NULL};
  _Base_meth_expression26->_base._dtl = Base_meth_expression__dtl;
  (*expression) = &(_Base_meth_expression26->_base);
  free(text);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Base_meth_expression_write(Base_meth_expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Base_meth_expression_write = "Base-meth-expression.write";
#define MR_FUNC_NAME _func_name_Base_meth_expression_write
Returncode Base_meth_expression_write(Base_meth_expression* self) {
  CHECK(26, write(&(String){5, 4, "Base"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Base_meth_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Base_meth_expression__dtl[] = {Base_meth_expression_write};
#endif


/* Type name expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Type_expression Type_expression;
#elif MR_STAGE == MR_TYPES(2)
struct Type_expression {
  Text_expression _base;
  Type_instance* type_value;
/* parsing `Type-name` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Type_expression_parse_new(Type_expression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Type_expression_parse_new = "Type-expression.parse-new";
#define MR_FUNC_NAME _func_name_Type_expression_parse_new
Returncode Type_expression_parse_new(Type_expression* self, String* text, Expression** expression) {
  Type_expression* type_expression = malloc(sizeof(Type_expression));
  if (type_expression == NULL) RAISE(34)
  *type_expression = (Type_expression){Type_expression__dtl, NULL, NULL, NULL};
  type_expression->_base._base._dtl = Type_expression__dtl;
  CHECK(35, Type_expression_parse(type_expression, text) )
  (*expression) = &(type_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `Type-name` */
#if MR_STAGE == MR_DECLARATIONS
Returncode Type_expression_parse(Type_expression* self, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Type_expression_parse = "Type-expression.parse";
#define MR_FUNC_NAME _func_name_Type_expression_parse
Returncode Type_expression_parse(Type_expression* self, String* text) {
  self->_base.text = text;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Type_expression_write(Type_expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Type_expression_write = "Type-expression.write";
#define MR_FUNC_NAME _func_name_Type_expression_write
Returncode Type_expression_write(Type_expression* self) {
  CHECK(43, Text_expression_write_text(&(self->_base), &(String){5, 4, "Type"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Type_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Type_expression__dtl[] = {Type_expression_write};
#endif


/* An instance member expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Member_expression Member_expression;
#elif MR_STAGE == MR_TYPES(3)
struct Member_expression {
  Variable_expression _base;
  Expression* instance;
/* parsing `instance.variable` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Member_expression_parse_new(Member_expression* self, String* ends, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Member_expression_parse_new = "Member-expression.parse-new";
#define MR_FUNC_NAME _func_name_Member_expression_parse_new
Returncode Member_expression_parse_new(Member_expression* self, String* ends, Expression** expression, Char* end) {
  Member_expression* member_expression = malloc(sizeof(Member_expression));
  if (member_expression == NULL) RAISE(52)
  *member_expression = (Member_expression){Member_expression__dtl, NULL, NULL, NULL, NULL};
  member_expression->_base._base._base._dtl = Member_expression__dtl;
  CHECK(53, Member_expression_parse(member_expression, (*expression), ends, &((*end))) )
  (*expression) = &(member_expression->_base._base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `instance.variable` */
#if MR_STAGE == MR_DECLARATIONS
Returncode Member_expression_parse(Member_expression* self, Expression* instance, String* ends, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Member_expression_parse = "Member-expression.parse";
#define MR_FUNC_NAME _func_name_Member_expression_parse
Returncode Member_expression_parse(Member_expression* self, Expression* instance, String* ends, Char* end) {
  self->instance = instance;
  CHECK(59, Expression_read_new_value(&(self->_base._base._base), ends, &(self->_base._base.text), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Member_expression_write(Member_expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Member_expression_write = "Member-expression.write";
#define MR_FUNC_NAME _func_name_Member_expression_write
Returncode Member_expression_write(Member_expression* self) {
  CHECK(62, (self->instance)->_dtl[0](self->instance) )
  CHECK(63, Text_expression_write_text(&(self->_base._base), &(String){8, 7, ".Member"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Member_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Member_expression__dtl[] = {Member_expression_write};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/map.c"
#include "global/type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
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
