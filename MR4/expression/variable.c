#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/variable.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file12_name = "expression/variable.3.mr";
#endif
#define MR_FILE_NAME _mr_file12_name

/* MR4 compiler - Variable expression */

/* A single variable expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct VariableExpression VariableExpression;
#elif MR_STAGE == MR_TYPES(2)
struct VariableExpression {
  TextExpression _base;
  Variable* variable;
/* parsing `variable` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode VariableExpression_parse_new(VariableExpression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_VariableExpression_parse_new = "VariableExpression.parse-new";
#define MR_FUNC_NAME _func_name_VariableExpression_parse_new
Returncode VariableExpression_parse_new(VariableExpression* self, String* text, Expression** expression) {
  VariableExpression* variable_expression = malloc(sizeof(VariableExpression));
  if (variable_expression == NULL) RAISE(8)
  *variable_expression = (VariableExpression){VariableExpression__dtl, NULL, NULL, NULL};
  variable_expression->_base._base._dtl = VariableExpression__dtl;
  CHECK(9, VariableExpression_parse(variable_expression, text) )
  (*expression) = &(variable_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `variable` */
#if MR_STAGE == MR_DECLARATIONS
Returncode VariableExpression_parse(VariableExpression* self, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_VariableExpression_parse = "VariableExpression.parse";
#define MR_FUNC_NAME _func_name_VariableExpression_parse
Returncode VariableExpression_parse(VariableExpression* self, String* text) {
  self->_base.text = text;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode VariableExpression_write(VariableExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_VariableExpression_write = "VariableExpression.write";
#define MR_FUNC_NAME _func_name_VariableExpression_write
Returncode VariableExpression_write(VariableExpression* self) {
  CHECK(17, TextExpression_write_text(&(self->_base), &(String){9, 8, "Variable"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func VariableExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func VariableExpression__dtl[] = {(void*)VariableExpression_write};
#endif

/* The `base` method expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct BaseMethExpression BaseMethExpression;
#elif MR_STAGE == MR_TYPES(1)
struct BaseMethExpression {
  Expression _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BaseMethExpression_parse_new(BaseMethExpression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BaseMethExpression_parse_new = "BaseMethExpression.parse-new";
#define MR_FUNC_NAME _func_name_BaseMethExpression_parse_new
Returncode BaseMethExpression_parse_new(BaseMethExpression* self, String* text, Expression** expression) {
  BaseMethExpression* _BaseMethExpression25 = malloc(sizeof(BaseMethExpression));
  if (_BaseMethExpression25 == NULL) RAISE(22)
  *_BaseMethExpression25 = (BaseMethExpression){BaseMethExpression__dtl, NULL};
  _BaseMethExpression25->_base._dtl = BaseMethExpression__dtl;
  (*expression) = &(_BaseMethExpression25->_base);
  free(text);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BaseMethExpression_write(BaseMethExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BaseMethExpression_write = "BaseMethExpression.write";
#define MR_FUNC_NAME _func_name_BaseMethExpression_write
Returncode BaseMethExpression_write(BaseMethExpression* self) {
  CHECK(26, write(&(String){5, 4, "Base"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BaseMethExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BaseMethExpression__dtl[] = {(void*)BaseMethExpression_write};
#endif


/* Type name expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeExpression TypeExpression;
#elif MR_STAGE == MR_TYPES(2)
struct TypeExpression {
  TextExpression _base;
  TypeInstance* type_value;
/* parsing `Type-name` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeExpression_parse_new(TypeExpression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeExpression_parse_new = "TypeExpression.parse-new";
#define MR_FUNC_NAME _func_name_TypeExpression_parse_new
Returncode TypeExpression_parse_new(TypeExpression* self, String* text, Expression** expression) {
  TypeExpression* type_expression = malloc(sizeof(TypeExpression));
  if (type_expression == NULL) RAISE(34)
  *type_expression = (TypeExpression){TypeExpression__dtl, NULL, NULL, NULL};
  type_expression->_base._base._dtl = TypeExpression__dtl;
  CHECK(35, TypeExpression_parse(type_expression, text) )
  (*expression) = &(type_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `Type-name` */
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeExpression_parse(TypeExpression* self, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeExpression_parse = "TypeExpression.parse";
#define MR_FUNC_NAME _func_name_TypeExpression_parse
Returncode TypeExpression_parse(TypeExpression* self, String* text) {
  self->_base.text = text;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeExpression_write(TypeExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeExpression_write = "TypeExpression.write";
#define MR_FUNC_NAME _func_name_TypeExpression_write
Returncode TypeExpression_write(TypeExpression* self) {
  CHECK(43, TextExpression_write_text(&(self->_base), &(String){5, 4, "Type"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func TypeExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func TypeExpression__dtl[] = {(void*)TypeExpression_write};
#endif


/* An instance member expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct MemberExpression MemberExpression;
#elif MR_STAGE == MR_TYPES(3)
struct MemberExpression {
  VariableExpression _base;
  Expression* instance;
/* parsing `instance.variable` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_parse_new(MemberExpression* self, String* ends, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_parse_new = "MemberExpression.parse-new";
#define MR_FUNC_NAME _func_name_MemberExpression_parse_new
Returncode MemberExpression_parse_new(MemberExpression* self, String* ends, Expression** expression, Char* end) {
  MemberExpression* member_expression = malloc(sizeof(MemberExpression));
  if (member_expression == NULL) RAISE(52)
  *member_expression = (MemberExpression){MemberExpression__dtl, NULL, NULL, NULL, NULL};
  member_expression->_base._base._base._dtl = MemberExpression__dtl;
  CHECK(53, MemberExpression_parse(member_expression, (*expression), ends, &((*end))) )
  (*expression) = &(member_expression->_base._base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `instance.variable` */
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_parse(MemberExpression* self, Expression* instance, String* ends, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_parse = "MemberExpression.parse";
#define MR_FUNC_NAME _func_name_MemberExpression_parse
Returncode MemberExpression_parse(MemberExpression* self, Expression* instance, String* ends, Char* end) {
  self->instance = instance;
  CHECK(59, Expression_read_new_value(&(self->_base._base._base), ends, &(self->_base._base.text), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_write(MemberExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_write = "MemberExpression.write";
#define MR_FUNC_NAME _func_name_MemberExpression_write
Returncode MemberExpression_write(MemberExpression* self) {
  CHECK(62, (self->instance)->_dtl[0](self->instance) )
  CHECK(63, TextExpression_write_text(&(self->_base._base), &(String){8, 7, ".Member"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func MemberExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func MemberExpression__dtl[] = {(void*)MemberExpression_write};
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
#endif
#undef MR_INCLUDES
#endif

#endif
