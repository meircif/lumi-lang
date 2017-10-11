#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/symbol.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file11_name = "expression/symbol.3.mr";
#endif
#define MR_FILE_NAME _mr_file11_name

/* MR4 compiler - Symbol expression */

/* A single symbol expression (variable or global-function) */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SymbolExpression SymbolExpression;
#elif MR_STAGE == MR_TYPES(2)
struct SymbolExpression {
  TextExpression _base;
  SyntaxTreeVariable* variable;
  SyntaxTreeFunction* function;
/* parsing `symbol` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SymbolExpression_parse_new(SymbolExpression* self, String* text, SyntaxTreeCode* code_node, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SymbolExpression_parse_new = "SymbolExpression.parse-new";
#define MR_FUNC_NAME _func_name_SymbolExpression_parse_new
Returncode SymbolExpression_parse_new(SymbolExpression* self, String* text, SyntaxTreeCode* code_node, Expression** expression) {
  SymbolExpression* symbol_expression = malloc(sizeof(SymbolExpression));
  if (symbol_expression == NULL) RAISE(10)
  *symbol_expression = (SymbolExpression){SymbolExpression__dtl, NULL, NULL, false, false, NULL, NULL, NULL};
  symbol_expression->_base._base._dtl = SymbolExpression__dtl;
  CHECK(11, SymbolExpression_parse(symbol_expression, text, code_node) )
  (*expression) = &(symbol_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `symbol` */
#if MR_STAGE == MR_DECLARATIONS
Returncode SymbolExpression_parse(SymbolExpression* self, String* text, SyntaxTreeCode* code_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SymbolExpression_parse = "SymbolExpression.parse";
#define MR_FUNC_NAME _func_name_SymbolExpression_parse
Returncode SymbolExpression_parse(SymbolExpression* self, String* text, SyntaxTreeCode* code_node) {
  self->_base._base.code_node = code_node;
  self->_base.text = text;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SymbolExpression_analyze(SymbolExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SymbolExpression_analyze = "SymbolExpression.analyze";
#define MR_FUNC_NAME _func_name_SymbolExpression_analyze
Returncode SymbolExpression_analyze(SymbolExpression* self) {
  CHECK(20, SyntaxTreeCode_m_find_variable(self->_base._base.code_node, self->_base.text, &(self->variable)) )
  if (NULL != self->variable) {
    CHECK(22, TypeInstance_m_copy_new(self->variable->type_instance, &(self->_base._base.result_type)) )
    self->_base._base.assignable = true;
  }
  else {
    CHECK(25, SyntaxTreeNamespace_m_find_function(&(glob->root->_base), self->_base.text, &(self->function)) )
    if (!(NULL != self->function)) {
      CHECK(27, f_syntax_error(&(String){15, 14, "unknown symbol"}, self->_base.text) )
    }
    CHECK(28, Expression_set_simple_type(&(self->_base._base), glob->type_func) )
    FunctionArguments* _FunctionArguments27;
    CHECK(29, FunctionArguments_m_copy_new(self->function->arguments, &(_FunctionArguments27)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SymbolExpression_write(SymbolExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SymbolExpression_write = "SymbolExpression.write";
#define MR_FUNC_NAME _func_name_SymbolExpression_write
Returncode SymbolExpression_write(SymbolExpression* self) {
  CHECK(32, write_cname(self->_base.text) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SymbolExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SymbolExpression__dtl[] = {(void*)SymbolExpression_analyze, (void*)Expression_analyze_call, (void*)SymbolExpression_write};
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
Returncode BaseMethExpression_parse_new(BaseMethExpression* self, String* text, SyntaxTreeCode* code_node, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BaseMethExpression_parse_new = "BaseMethExpression.parse-new";
#define MR_FUNC_NAME _func_name_BaseMethExpression_parse_new
Returncode BaseMethExpression_parse_new(BaseMethExpression* self, String* text, SyntaxTreeCode* code_node, Expression** expression) {
  BaseMethExpression* _BaseMethExpression28 = malloc(sizeof(BaseMethExpression));
  if (_BaseMethExpression28 == NULL) RAISE(39)
  *_BaseMethExpression28 = (BaseMethExpression){BaseMethExpression__dtl, NULL, NULL, false, false};
  _BaseMethExpression28->_base._dtl = BaseMethExpression__dtl;
  (*expression) = &(_BaseMethExpression28->_base);
  (*expression)->code_node = code_node;
  free(text);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BaseMethExpression_analyze(BaseMethExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BaseMethExpression_analyze = "BaseMethExpression.analyze";
#define MR_FUNC_NAME _func_name_BaseMethExpression_analyze
Returncode BaseMethExpression_analyze(BaseMethExpression* self) {
  TypeData* parent_type = NULL;
  CHECK(45, SyntaxTreeCode_m_get_parent_type(self->_base.code_node, &(parent_type)) )
  if (!(NULL != parent_type)) {
    CHECK(47, f_syntax_error_msg(&(String){26, 25, "\"base\" used not in method"}) )
  }
  if (!(NULL != parent_type->base_type)) {
    CHECK(49, f_syntax_error(&(String){22, 21, "no base type for type"}, parent_type->name) )
  }
  CHECK(50, Expression_set_simple_type(&(self->_base), parent_type->base_type) )
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
  CHECK(53, write(&(String){5, 4, "Base"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BaseMethExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BaseMethExpression__dtl[] = {(void*)BaseMethExpression_analyze, (void*)Expression_analyze_call, (void*)BaseMethExpression_write};
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
  if (type_expression == NULL) RAISE(61)
  *type_expression = (TypeExpression){TypeExpression__dtl, NULL, NULL, false, false, NULL, NULL};
  type_expression->_base._base._dtl = TypeExpression__dtl;
  CHECK(62, TypeExpression_parse(type_expression, text) )
  (*expression) = &(type_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeExpression_analyze(TypeExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeExpression_analyze = "TypeExpression.analyze";
#define MR_FUNC_NAME _func_name_TypeExpression_analyze
Returncode TypeExpression_analyze(TypeExpression* self) {
  CHECK(66, TypeInstance_analyze(self->type_value) )
  CHECK(67, TypeData_m_new_type_instance(glob->type_type, &(self->_base._base.result_type)) )
  CHECK(68, TypeInstance_m_copy_new(self->type_value, &(self->_base._base.result_type->sub_type)) )
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
extern Func TypeExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func TypeExpression__dtl[] = {(void*)TypeExpression_analyze, (void*)Expression_analyze_call, (void*)TextExpression_write};
#endif


/* An instance member expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct MemberExpression MemberExpression;
#elif MR_STAGE == MR_TYPES(3)
struct MemberExpression {
  SymbolExpression _base;
  Expression* instance;
/* parsing `instance.symbol` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_parse_new(MemberExpression* self, String* ends, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_parse_new = "MemberExpression.parse-new";
#define MR_FUNC_NAME _func_name_MemberExpression_parse_new
Returncode MemberExpression_parse_new(MemberExpression* self, String* ends, Expression** expression, Char* end) {
  MemberExpression* member_expression = malloc(sizeof(MemberExpression));
  if (member_expression == NULL) RAISE(81)
  *member_expression = (MemberExpression){MemberExpression__dtl, NULL, NULL, false, false, NULL, NULL, NULL, NULL};
  member_expression->_base._base._base._dtl = MemberExpression__dtl;
  CHECK(82, MemberExpression_parse(member_expression, (*expression), ends, &((*end))) )
  (*expression) = &(member_expression->_base._base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `instance.symbol` */
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_parse(MemberExpression* self, Expression* instance, String* ends, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_parse = "MemberExpression.parse";
#define MR_FUNC_NAME _func_name_MemberExpression_parse
Returncode MemberExpression_parse(MemberExpression* self, Expression* instance, String* ends, Char* end) {
  self->instance = instance;
  CHECK(88, Expression_read_new_value(&(self->_base._base._base), ends, &(self->_base._base.text), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_analyze(MemberExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_analyze = "MemberExpression.analyze";
#define MR_FUNC_NAME _func_name_MemberExpression_analyze
Returncode MemberExpression_analyze(MemberExpression* self) {
  CHECK(91, (self->instance)->_dtl[0](self->instance) )
  self->_base._base._base.assignable = self->instance->assignable;
  if (!(NULL != self->instance->result_type) ||  ! (NULL != self->instance->result_type->type_data)) {
    CHECK(95, f_syntax_error(&(String){30, 29, "void expression has no member"}, self->_base._base.text) )
  }
  TypeData* type_data = self->instance->result_type->type_data;
  if (self->instance->result_type->type_data == glob->type_type) {
    if (!(NULL != self->instance->result_type->sub_type) ||  ! (NULL != self->instance->result_type->sub_type->type_data)) {
      CHECK(100, f_syntax_error(&(String){31, 30, "unspecified type has no member"}, self->_base._base.text) )
    }
    type_data = self->instance->result_type->sub_type->type_data;
  }
  
  CHECK(104, TypeData_m_find_field(type_data, self->_base._base.text, &(self->_base.variable)) )
  if (NULL != self->_base.variable) {
    CHECK(106, TypeInstance_m_copy_new(self->_base.variable->type_instance, &(self->_base._base._base.result_type)) )
    self->_base._base._base.assignable = true;
  }
  else {
    CHECK(109, TypeData_m_find_meth(type_data, self->_base._base.text, &(self->_base.function)) )
    if (!(NULL != self->_base.function)) {
      CHECK(111, f_syntax_error2(&(String){5, 4, "type"}, type_data->name, &(String){14, 13, "has no member"}, self->_base._base.text) )
    }
    CHECK(116, Expression_set_simple_type(&(self->_base._base._base), glob->type_func) )
    FunctionArguments* _FunctionArguments29;
    CHECK(117, FunctionArguments_m_copy_new(self->_base.function->arguments, &(_FunctionArguments29)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_analyze_call(MemberExpression* self, FunctionArguments* arguments);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_analyze_call = "MemberExpression.analyze-call";
#define MR_FUNC_NAME _func_name_MemberExpression_analyze_call
Returncode MemberExpression_analyze_call(MemberExpression* self, FunctionArguments* arguments) {
  if (self->instance->result_type->type_data == glob->type_type) {
    return OK;
  }
  CallArgument* self_param = malloc(sizeof(CallArgument));
  if (self_param == NULL) RAISE(122)
  *self_param = (CallArgument){CallArgument__dtl, 0, NULL};
  self_param->_base._dtl = CallArgument__dtl;
  self_param->_base.access = ((Argument*)(self->_base.function->arguments->parameters->first->item))->access;
  self_param->value = self->instance;
  self->instance = NULL;
  CHECK(126, List_m_prepend(arguments->parameters, &(self_param->_base)) )
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
  CHECK(129, (self->instance)->_dtl[2](self->instance) )
  CHECK(130, write(&(String){2, 1, "."}) )
  CHECK(131, SymbolExpression_write(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func MemberExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func MemberExpression__dtl[] = {(void*)MemberExpression_analyze, (void*)MemberExpression_analyze_call, (void*)MemberExpression_write};
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
