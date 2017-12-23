#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/symbol.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file14_name = "expression/symbol.3.mr";
#endif
#define MR_FILE_NAME _mr_file14_name

/* MR4 compiler - Symbol expression */

/* A single symbol expression (variable or global-function) */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SymbolExpression SymbolExpression;
#elif MR_STAGE == MR_TYPES(2)
struct SymbolExpression {
  Expression _base;
  String* name;
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
  if (symbol_expression == NULL) RAISE(11)
  *symbol_expression = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL};
  symbol_expression->_base._base._dtl = SymbolExpression__dtl;
  CHECK(12, SymbolExpression_parse(symbol_expression, text, code_node) )
  (*expression) = &(symbol_expression->_base);
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
  self->_base.code_node = code_node;
  self->name = text;
  CHECK(19, SyntaxTreeNode_set_location(&(self->_base._base)) )
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
  CHECK(22, SyntaxTreeCode_find_variable(self->_base.code_node, self->name, &(self->variable)) )
  if (NULL != self->variable) {
    CHECK(24, TypeInstance_copy_new(self->variable->type_instance, &(self->_base.result_type)) )
    self->_base.access = self->variable->access;
    self->_base.assignable = true;
  }
  else {
    CHECK(28, SyntaxTreeNamespace_find_function(&(glob->root->_base), self->name, &(self->function)) )
    if (!(NULL != self->function)) {
      CHECK(30, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){15, 14, "unknown symbol"}, self->name) )
    }
    CHECK(31, Expression_set_simple_type(&(self->_base), &(glob->type_func->_base)) )
    self->_base.access = ACCESS_VAR;
    CHECK(33, FunctionArguments_copy_new(self->function->arguments, &(self->_base.result_type->arguments)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SymbolExpression_analyze_call(SymbolExpression* self, FunctionArguments* arguments, Bool* is_function_object);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SymbolExpression_analyze_call = "SymbolExpression.analyze-call";
#define MR_FUNC_NAME _func_name_SymbolExpression_analyze_call
Returncode SymbolExpression_analyze_call(SymbolExpression* self, FunctionArguments* arguments, Bool* is_function_object) {
  (*is_function_object) =  NULL !=  self->variable;
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
  if (NULL != self->function) {
    if (NULL != self->function->mocker_function) {
      CHECK(42, SyntaxTreeFunction_write_cname(&(self->function->mocker_function->_base)) )
    }
    else {
      CHECK(44, SyntaxTreeFunction_write_cname(self->function) )
    }
    return OK;
  }
  if (NULL != self->variable && self->variable->is_output) {
    if (!self->_base.top) {
      CHECK(48, write(&(String){2, 1, "("}) )
    }
    CHECK(49, write(&(String){2, 1, "*"}) )
  }
  CHECK(50, write_cname(self->name) )
  if (NULL != self->variable && self->variable->is_output &&  ! self->_base.top) {
    CHECK(52, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SymbolExpression_write_dynamic(SymbolExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SymbolExpression_write_dynamic = "SymbolExpression.write-dynamic";
#define MR_FUNC_NAME _func_name_SymbolExpression_write_dynamic
Returncode SymbolExpression_write_dynamic(SymbolExpression* self) {
  if (NULL != self->variable && self->variable->is_output &&  ! self->_base.top) {
    CHECK(56, write(&(String){3, 2, "(*"}) )
    CHECK(57, write_cname(self->name) )
    CHECK(58, write(&(String){10, 9, "_Dynamic)"}) )
  }
  else {
    CHECK(60, Expression_write_dynamic(&(self->_base)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SymbolExpression_write_refman(SymbolExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SymbolExpression_write_refman = "SymbolExpression.write-refman";
#define MR_FUNC_NAME _func_name_SymbolExpression_write_refman
Returncode SymbolExpression_write_refman(SymbolExpression* self) {
  if (NULL != self->variable && self->variable->is_output &&  ! self->_base.top) {
    CHECK(64, write(&(String){3, 2, "(*"}) )
    CHECK(65, write_cname(self->name) )
    CHECK(66, write(&(String){9, 8, "_Refman)"}) )
  }
  else {
    CHECK(68, Expression_write_refman(&(self->_base)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SymbolExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SymbolExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)SymbolExpression_analyze, (void*)SymbolExpression_write, (void*)SymbolExpression_write_dynamic, (void*)SymbolExpression_write_refman, (void*)SymbolExpression_analyze_call, (void*)Expression_write_preactions};
#endif

/* An instance member expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct MemberExpression MemberExpression;
#elif MR_STAGE == MR_TYPES(3)
struct MemberExpression {
  SymbolExpression _base;
  Expression* instance;
  Expression* dynamic_call_self_instance;
  Int bases;
  Bool is_dynamic_call;
/* parsing `instance.symbol` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_parse_new(MemberExpression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_parse_new = "MemberExpression.parse-new";
#define MR_FUNC_NAME _func_name_MemberExpression_parse_new
Returncode MemberExpression_parse_new(MemberExpression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  MemberExpression* member_expression = malloc(sizeof(MemberExpression));
  if (member_expression == NULL) RAISE(79)
  *member_expression = (MemberExpression){MemberExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL, NULL, NULL, 0, false};
  member_expression->_base._base._base._dtl = MemberExpression__dtl;
  CHECK(80, MemberExpression_parse(member_expression, (*expression), ends, code_node, &((*end))) )
  (*expression) = &(member_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `instance.symbol` */
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_parse(MemberExpression* self, Expression* instance, String* ends, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_parse = "MemberExpression.parse";
#define MR_FUNC_NAME _func_name_MemberExpression_parse
Returncode MemberExpression_parse(MemberExpression* self, Expression* instance, String* ends, SyntaxTreeCode* code_node, Char* end) {
  self->_base._base.code_node = code_node;
  self->instance = instance;
  CHECK(92, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(93, Expression_read_new_value(&(self->_base._base), ends, &(self->_base.name), &((*end))) )
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
  CHECK(96, (self->instance)->_base._dtl[1](self->instance) )
  self->_base._base.assignable = self->instance->assignable;
  if (!(NULL != self->instance->result_type) ||  ! (NULL != self->instance->result_type->type_data)) {
    CHECK(100, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){30, 29, "void expression has no member"}, self->_base.name) )
  }
  TypeData* type_data = self->instance->result_type->type_data;
  if (type_data == &(glob->type_type->_base)) {
    type_data = self->instance->result_type->sub_type->type_data;
  }
  else {
    if (type_data == &(glob->type_base->_base)) {
      type_data = self->instance->result_type->sub_type->type_data->base_type;
    }
  }
  
  CHECK(107, TypeData_find_field(type_data, self->_base.name, &(self->_base.variable), &(self->bases)) )
  if (NULL != self->_base.variable) {
    CHECK(109, TypeInstance_copy_new(self->_base.variable->type_instance, &(self->_base._base.result_type)) )
    self->_base._base.access = self->_base.variable->access;
    self->_base._base.assignable = true;
  }
  else {
    CHECK(113, TypeData_find_meth(type_data, self->_base.name, &(self->_base.function), &(self->bases)) )
    if (!(NULL != self->_base.function)) {
      CHECK(116, SyntaxTreeNode_m_syntax_error2(&(self->_base._base._base), &(String){5, 4, "type"}, type_data->name, &(String){14, 13, "has no member"}, self->_base.name) )
    }
    if (self->_base.function->is_dynamic && self->instance->result_type->type_data != &(glob->type_type->_base) && self->instance->result_type->type_data != &(glob->type_base->_base)) {
      self->bases = self->_base.function->dynamic_base_count;
      self->_base.function = self->_base.function->dynamic_base_method;
      self->is_dynamic_call = true;
    }
    CHECK(127, Expression_set_simple_type(&(self->_base._base), &(glob->type_func->_base)) )
    self->_base._base.access = ACCESS_VAR;
    CHECK(129, FunctionArguments_copy_new(self->_base.function->arguments, &(self->_base._base.result_type->arguments)) )
  }
  if (self->instance->result_type->type_data == &(glob->type_base->_base)) {
    if (!(NULL != self->_base.function)) {
      CHECK(132, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){31, 30, "calling \"base\" with non-method"}, self->_base.name) )
    }
    TypeInstance* base_result_type = self->instance->result_type;
    self->instance->result_type = base_result_type->sub_type;
    free(base_result_type);
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_analyze_call(MemberExpression* self, FunctionArguments* arguments, Bool* is_function_object);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_analyze_call = "MemberExpression.analyze-call";
#define MR_FUNC_NAME _func_name_MemberExpression_analyze_call
Returncode MemberExpression_analyze_call(MemberExpression* self, FunctionArguments* arguments, Bool* is_function_object) {
  CHECK(140, SymbolExpression_analyze_call(&(self->_base), arguments, &((*is_function_object))) )
  if ((*is_function_object)) {
    return OK;
  }
  if (self->instance->result_type->type_data == &(glob->type_type->_base)) {
    free(self->instance);
  }
  else {
    CallArgument* self_param = malloc(sizeof(CallArgument));
    if (self_param == NULL) RAISE(145)
    *self_param = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, false, false};
    self_param->_base._base._dtl = CallArgument__dtl;
    self_param->_base.access = ((Argument*)(self->_base.function->arguments->parameters->first->item))->access;
    self_param->value = self->instance;
    self_param->value->top = true;
    CHECK(149, List_prepend(arguments->parameters, &(self_param->_base)) )
    if (self->is_dynamic_call) {
      self->dynamic_call_self_instance = self->instance;
    }
  }
  self->instance = NULL;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_write_preactions(MemberExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_write_preactions = "MemberExpression.write-preactions";
#define MR_FUNC_NAME _func_name_MemberExpression_write_preactions
Returncode MemberExpression_write_preactions(MemberExpression* self) {
  if (NULL != self->instance) {
    CHECK(156, (self->instance)->_base._dtl[6](self->instance) )
  }
  if (!(NULL != self->dynamic_call_self_instance || (NULL != self->instance &&  ! (NULL != self->_base.function) && self->instance->result_type->type_data != &(glob->type_type->_base)))) {
    return OK;
  }
  /* if (...) RAISE(`line-num`) */
  CHECK(162, write(&(String){5, 4, "if ("}) )
  if (NULL != self->instance) {
    /* `instance` == NULL[ || `instance`_Refman->value == NULL] */
    CHECK(165, Expression_write_validate_ref(self->instance) )
  }
  else {
    if (NULL != self->dynamic_call_self_instance) {
      /* `instance`_Dynamic == NULL */
      self->dynamic_call_self_instance->top = true;
      CHECK(169, (self->dynamic_call_self_instance)->_base._dtl[3](self->dynamic_call_self_instance) )
      self->dynamic_call_self_instance->top = false;
      CHECK(171, write(&(String){9, 8, " == NULL"}) )
    }
  }
  CHECK(172, write(&(String){3, 2, ") "}) )
  CHECK(173, SyntaxTreeNode_write_raise(&(self->_base._base._base)) )
  CHECK(174, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
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
  if (NULL != self->dynamic_call_self_instance) {
    CHECK(178, (self->dynamic_call_self_instance)->_base._dtl[3](self->dynamic_call_self_instance) )
    CHECK(179, MemberExpression_write_bases(self) )
    CHECK(180, write_cname(self->_base.function->name) )
    return OK;
  }
  if (NULL != self->instance &&  ! (NULL != self->_base.function) && self->instance->result_type->type_data != &(glob->type_type->_base)) {
    CHECK(184, (self->instance)->_base._dtl[2](self->instance) )
    CHECK(185, MemberExpression_write_bases(self) )
  }
  CHECK(186, SymbolExpression_write(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_write_bases(MemberExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_write_bases = "MemberExpression.write-bases";
#define MR_FUNC_NAME _func_name_MemberExpression_write_bases
Returncode MemberExpression_write_bases(MemberExpression* self) {
  CHECK(189, write(&(String){3, 2, "->"}) )
  {int n; for (n = (0); n < (self->bases); ++n) {
    CHECK(191, write(&(String){7, 6, "_base."}) )
  }}
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func MemberExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func MemberExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)MemberExpression_analyze, (void*)MemberExpression_write, (void*)SymbolExpression_write_dynamic, (void*)SymbolExpression_write_refman, (void*)MemberExpression_analyze_call, (void*)MemberExpression_write_preactions};
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
#include "expression/base-type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/initialize.c"
#include "expression/slice.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/function.c"
#include "syntax-tree/native.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "syntax-tree/test.c"
#include "syntax-tree/type.c"
#include "syntax-tree/type-instance.c"
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
