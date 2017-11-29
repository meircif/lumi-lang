#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/symbol.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file12_name = "expression/symbol.3.mr";
#endif
#define MR_FILE_NAME _mr_file12_name

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
  *symbol_expression = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL, NULL, NULL};
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
    self->_base.assignable = true;
  }
  else {
    CHECK(27, SyntaxTreeNamespace_find_function(&(glob->root->_base), self->name, &(self->function)) )
    if (!(NULL != self->function)) {
      CHECK(29, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){15, 14, "unknown symbol"}, self->name) )
    }
    CHECK(30, Expression_set_simple_type(&(self->_base), &(glob->type_func->_base)) )
    CHECK(31, FunctionArguments_copy_new(self->function->arguments, &(self->_base.result_type->arguments)) )
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
      CHECK(40, SyntaxTreeFunction_write_cname(&(self->function->mocker_function->_base)) )
    }
    else {
      CHECK(42, SyntaxTreeFunction_write_cname(self->function) )
    }
    return OK;
  }
  if (NULL != self->variable && self->variable->is_output) {
    if (!self->_base.top) {
      CHECK(46, write(&(String){2, 1, "("}) )
    }
    CHECK(47, write(&(String){2, 1, "*"}) )
  }
  CHECK(48, write_cname(self->name) )
  if (NULL != self->variable && self->variable->is_output &&  ! self->_base.top) {
    CHECK(50, write(&(String){2, 1, ")"}) )
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
    CHECK(54, write(&(String){3, 2, "(*"}) )
    CHECK(55, write_cname(self->name) )
    CHECK(56, write(&(String){10, 9, "_Dynamic)"}) )
  }
  else {
    CHECK(58, Expression_write_dynamic(&(self->_base)) )
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
    CHECK(62, write(&(String){3, 2, "(*"}) )
    CHECK(63, write_cname(self->name) )
    CHECK(64, write(&(String){9, 8, "_Refman)"}) )
  }
  else {
    CHECK(66, Expression_write_refman(&(self->_base)) )
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
  if (member_expression == NULL) RAISE(77)
  *member_expression = (MemberExpression){MemberExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL, NULL, NULL, NULL, NULL, 0, false};
  member_expression->_base._base._base._dtl = MemberExpression__dtl;
  CHECK(78, MemberExpression_parse(member_expression, (*expression), ends, code_node, &((*end))) )
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
  CHECK(90, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(91, Expression_read_new_value(&(self->_base._base), ends, &(self->_base.name), &((*end))) )
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
  CHECK(94, (self->instance)->_base._dtl[1](self->instance) )
  self->_base._base.assignable = self->instance->assignable;
  if (!(NULL != self->instance->result_type) ||  ! (NULL != self->instance->result_type->type_data)) {
    CHECK(98, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){30, 29, "void expression has no member"}, self->_base.name) )
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
  
  CHECK(105, TypeData_find_field(type_data, self->_base.name, &(self->_base.variable), &(self->bases)) )
  if (NULL != self->_base.variable) {
    CHECK(107, TypeInstance_copy_new(self->_base.variable->type_instance, &(self->_base._base.result_type)) )
    self->_base._base.assignable = true;
  }
  else {
    CHECK(110, TypeData_find_meth(type_data, self->_base.name, &(self->_base.function), &(self->bases)) )
    if (!(NULL != self->_base.function)) {
      CHECK(113, SyntaxTreeNode_m_syntax_error2(&(self->_base._base._base), &(String){5, 4, "type"}, type_data->name, &(String){14, 13, "has no member"}, self->_base.name) )
    }
    if (self->_base.function->is_dynamic && self->instance->result_type->type_data != &(glob->type_type->_base) && self->instance->result_type->type_data != &(glob->type_base->_base)) {
      self->bases = self->_base.function->dynamic_base_count;
      self->_base.function = self->_base.function->dynamic_base_method;
      self->is_dynamic_call = true;
    }
    CHECK(124, Expression_set_simple_type(&(self->_base._base), &(glob->type_func->_base)) )
    CHECK(125, FunctionArguments_copy_new(self->_base.function->arguments, &(self->_base._base.result_type->arguments)) )
  }
  if (self->instance->result_type->type_data == &(glob->type_base->_base)) {
    if (!(NULL != self->_base.function)) {
      CHECK(128, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){31, 30, "calling \"base\" with non-method"}, self->_base.name) )
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
  CHECK(136, SymbolExpression_analyze_call(&(self->_base), arguments, &((*is_function_object))) )
  if ((*is_function_object)) {
    return OK;
  }
  if (self->instance->result_type->type_data == &(glob->type_type->_base)) {
    free(self->instance);
  }
  else {
    CallArgument* self_param = malloc(sizeof(CallArgument));
    if (self_param == NULL) RAISE(141)
    *self_param = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, NULL, NULL, false, false};
    self_param->_base._base._dtl = CallArgument__dtl;
    self_param->_base.access = ((Argument*)(self->_base.function->arguments->parameters->first->item))->access;
    self_param->value = self->instance;
    self_param->value->top = true;
    CHECK(145, List_prepend(arguments->parameters, &(self_param->_base)) )
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
    CHECK(152, (self->instance)->_base._dtl[6](self->instance) )
  }
  if (!(NULL != self->dynamic_call_self_instance || (NULL != self->instance &&  ! (NULL != self->_base.function) && self->instance->result_type->type_data != &(glob->type_type->_base)))) {
    return OK;
  }
  /* if (...) RAISE(`line-num`) */
  CHECK(158, write(&(String){5, 4, "if ("}) )
  if (NULL != self->instance) {
    /* `instance` == NULL[ || `instance`_Refman->value == NULL] */
    CHECK(161, Expression_write_validate_ref(self->instance) )
  }
  else {
    if (NULL != self->dynamic_call_self_instance) {
      /* `instance`_Dynamic == NULL */
      self->dynamic_call_self_instance->top = true;
      CHECK(165, (self->dynamic_call_self_instance)->_base._dtl[3](self->dynamic_call_self_instance) )
      self->dynamic_call_self_instance->top = false;
      CHECK(167, write(&(String){9, 8, " == NULL"}) )
    }
  }
  CHECK(168, write(&(String){3, 2, ") "}) )
  CHECK(169, SyntaxTreeNode_write_raise(&(self->_base._base._base)) )
  CHECK(170, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
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
    CHECK(174, (self->dynamic_call_self_instance)->_base._dtl[3](self->dynamic_call_self_instance) )
    CHECK(175, MemberExpression_write_bases(self) )
    CHECK(176, write_cname(self->_base.function->name) )
    return OK;
  }
  if (NULL != self->instance &&  ! (NULL != self->_base.function) && self->instance->result_type->type_data != &(glob->type_type->_base)) {
    CHECK(180, (self->instance)->_base._dtl[2](self->instance) )
    CHECK(181, MemberExpression_write_bases(self) )
  }
  CHECK(182, SymbolExpression_write(&(self->_base)) )
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
  CHECK(185, write(&(String){3, 2, "->"}) )
  {int n; for (n = (0); n < (self->bases); ++n) {
    CHECK(187, write(&(String){7, 6, "_base."}) )
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


/* The `base` method expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct BaseMethExpression BaseMethExpression;
#elif MR_STAGE == MR_TYPES(2)
struct BaseMethExpression {
  Expression _base;
  Bool is_call;
  SyntaxTreeFunction* function;
  TypeData* parent_type;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BaseMethExpression_parse_new(BaseMethExpression* self, String* text, SyntaxTreeCode* code_node, Char end, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BaseMethExpression_parse_new = "BaseMethExpression.parse-new";
#define MR_FUNC_NAME _func_name_BaseMethExpression_parse_new
Returncode BaseMethExpression_parse_new(BaseMethExpression* self, String* text, SyntaxTreeCode* code_node, Char end, Expression** expression) {
  free(text);
  BaseMethExpression* base_expression = malloc(sizeof(BaseMethExpression));
  if (base_expression == NULL) RAISE(200)
  *base_expression = (BaseMethExpression){BaseMethExpression__dtl, NULL, 0, NULL, NULL, false, false, false, false, NULL, NULL};
  base_expression->_base._base._dtl = BaseMethExpression__dtl;
  CHECK(201, BaseMethExpression_init(base_expression, code_node, end == '(') )
  (*expression) = &(base_expression->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BaseMethExpression_init(BaseMethExpression* self, SyntaxTreeCode* code_node, Bool is_call);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BaseMethExpression_init = "BaseMethExpression.init";
#define MR_FUNC_NAME _func_name_BaseMethExpression_init
Returncode BaseMethExpression_init(BaseMethExpression* self, SyntaxTreeCode* code_node, Bool is_call) {
  self->_base.code_node = code_node;
  self->is_call = is_call;
  CHECK(207, SyntaxTreeNode_set_location(&(self->_base._base)) )
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
  SyntaxTreeFunction* function = NULL;
  CHECK(211, SyntaxTreeCode_get_function(self->_base.code_node, &(function)) )
  self->parent_type = function->parent_type;
  if (!(NULL != self->parent_type)) {
    CHECK(214, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){26, 25, "\"base\" used not in method"}) )
  }
  if (!(NULL != self->parent_type->base_type)) {
    CHECK(216, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){22, 21, "no base type for type"}, function->parent_type->name) )
  }
  if (self->is_call) {
    Int _Int33;
    CHECK(219, TypeData_find_meth(self->parent_type->base_type, function->name, &(self->function), &(_Int33)) )
    if (!(NULL != function)) {
      CHECK(222, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){26, 25, "no base method for method"}, function->name) )
    }
    CHECK(224, Expression_set_simple_type(&(self->_base), &(glob->type_func->_base)) )
    self->_base.result_type->arguments = self->function->arguments;
  }
  else {
    CHECK(227, Expression_set_simple_type(&(self->_base), &(glob->type_base->_base)) )
    CHECK(228, TypeData_m_new_type_instance(self->parent_type, &(self->_base.result_type->sub_type)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BaseMethExpression_analyze_call(BaseMethExpression* self, FunctionArguments* arguments, Bool* is_function_object);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BaseMethExpression_analyze_call = "BaseMethExpression.analyze-call";
#define MR_FUNC_NAME _func_name_BaseMethExpression_analyze_call
Returncode BaseMethExpression_analyze_call(BaseMethExpression* self, FunctionArguments* arguments, Bool* is_function_object) {
  (*is_function_object) = false;
  CallArgument* self_param = malloc(sizeof(CallArgument));
  if (self_param == NULL) RAISE(233)
  *self_param = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, NULL, NULL, false, false};
  self_param->_base._base._dtl = CallArgument__dtl;
  self_param->_base.access = ((Argument*)(self->function->arguments->parameters->first->item))->access;
  BaseMethExpression* _BaseMethExpression34 = malloc(sizeof(BaseMethExpression));
  if (_BaseMethExpression34 == NULL) RAISE(235)
  *_BaseMethExpression34 = (BaseMethExpression){BaseMethExpression__dtl, NULL, 0, NULL, NULL, false, false, false, false, NULL, NULL};
  _BaseMethExpression34->_base._base._dtl = BaseMethExpression__dtl;
  self_param->value = &(_BaseMethExpression34->_base);
  CHECK(236, TypeData_m_new_type_instance(self->parent_type, &(self_param->value->result_type)) )
  CHECK(237, List_prepend(arguments->parameters, &(self_param->_base)) )
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
  if (self->is_call) {
    CHECK(241, SyntaxTreeFunction_write_cname(self->function) )
  }
  else {
    CHECK(243, write(&(String){5, 4, "self"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BaseMethExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BaseMethExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)BaseMethExpression_analyze, (void*)BaseMethExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)BaseMethExpression_analyze_call, (void*)Expression_write_preactions};
#endif


/* An instance member expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct UpCastExpression UpCastExpression;
#elif MR_STAGE == MR_TYPES(2)
struct UpCastExpression {
  Expression _base;
  Expression* expression;
  Int bases;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UpCastExpression_init_new(UpCastExpression* self, Int bases, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UpCastExpression_init_new = "UpCastExpression.init-new";
#define MR_FUNC_NAME _func_name_UpCastExpression_init_new
Returncode UpCastExpression_init_new(UpCastExpression* self, Int bases, Expression** expression) {
  UpCastExpression* up_cast = malloc(sizeof(UpCastExpression));
  if (up_cast == NULL) RAISE(252)
  *up_cast = (UpCastExpression){UpCastExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL, 0};
  up_cast->_base._base._dtl = UpCastExpression__dtl;
  CHECK(253, UpCastExpression_init(up_cast, bases, (*expression)) )
  (*expression) = &(up_cast->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UpCastExpression_init(UpCastExpression* self, Int bases, Expression* expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UpCastExpression_init = "UpCastExpression.init";
#define MR_FUNC_NAME _func_name_UpCastExpression_init
Returncode UpCastExpression_init(UpCastExpression* self, Int bases, Expression* expression) {
  self->expression = expression;
  self->expression->top = false;
  self->bases = bases;
  CHECK(260, TypeInstance_copy_new(self->expression->result_type, &(self->_base.result_type)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UpCastExpression_write_preactions(UpCastExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UpCastExpression_write_preactions = "UpCastExpression.write-preactions";
#define MR_FUNC_NAME _func_name_UpCastExpression_write_preactions
Returncode UpCastExpression_write_preactions(UpCastExpression* self) {
  CHECK(263, (self->expression)->_base._dtl[6](self->expression) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UpCastExpression_write(UpCastExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UpCastExpression_write = "UpCastExpression.write";
#define MR_FUNC_NAME _func_name_UpCastExpression_write
Returncode UpCastExpression_write(UpCastExpression* self) {
  /* &(`expression`->_base[._base]...) */
  CHECK(267, UpCastExpression_write_pre(self) )
  CHECK(268, (self->expression)->_base._dtl[2](self->expression) )
  CHECK(269, UpCastExpression_write_post(self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UpCastExpression_write_dynamic(UpCastExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UpCastExpression_write_dynamic = "UpCastExpression.write-dynamic";
#define MR_FUNC_NAME _func_name_UpCastExpression_write_dynamic
Returncode UpCastExpression_write_dynamic(UpCastExpression* self) {
  CHECK(272, UpCastExpression_write_pre(self) )
  CHECK(273, (self->expression)->_base._dtl[3](self->expression) )
  CHECK(274, UpCastExpression_write_post(self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UpCastExpression_write_refman(UpCastExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UpCastExpression_write_refman = "UpCastExpression.write-refman";
#define MR_FUNC_NAME _func_name_UpCastExpression_write_refman
Returncode UpCastExpression_write_refman(UpCastExpression* self) {
  self->expression->top = true;
  CHECK(278, (self->expression)->_base._dtl[4](self->expression) )
  self->expression->top = false;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UpCastExpression_write_pre(UpCastExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UpCastExpression_write_pre = "UpCastExpression.write-pre";
#define MR_FUNC_NAME _func_name_UpCastExpression_write_pre
Returncode UpCastExpression_write_pre(UpCastExpression* self) {
  CHECK(282, write(&(String){3, 2, "&("}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UpCastExpression_write_post(UpCastExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UpCastExpression_write_post = "UpCastExpression.write-post";
#define MR_FUNC_NAME _func_name_UpCastExpression_write_post
Returncode UpCastExpression_write_post(UpCastExpression* self) {
  CHECK(285, write(&(String){8, 7, "->_base"}) )
  {int n; for (n = (1); n < (self->bases); ++n) {
    CHECK(287, write(&(String){7, 6, "._base"}) )
  }}
  CHECK(288, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func UpCastExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func UpCastExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)UpCastExpression_write, (void*)UpCastExpression_write_dynamic, (void*)UpCastExpression_write_refman, (void*)Expression_analyze_call, (void*)UpCastExpression_write_preactions};
#endif


/* Type name expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeExpression TypeExpression;
#elif MR_STAGE == MR_TYPES(2)
struct TypeExpression {
  Expression _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeExpression_parse_new(TypeExpression* self, String* text, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeExpression_parse_new = "TypeExpression.parse-new";
#define MR_FUNC_NAME _func_name_TypeExpression_parse_new
Returncode TypeExpression_parse_new(TypeExpression* self, String* text, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  TypeInstance* type_instance = malloc(sizeof(TypeInstance));
  if (type_instance == NULL) RAISE(295)
  *type_instance = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL};
  CHECK(296, TypeInstance_parse_name(type_instance, text, &(code_node->_base), code_node, &((*end))) )
  if ((*end) == '(') {
    InitExpression* expression_init = malloc(sizeof(InitExpression));
    if (expression_init == NULL) RAISE(299)
    *expression_init = (InitExpression){InitExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL, NULL, NULL, NULL};
    expression_init->_base._base._dtl = InitExpression__dtl;
    CHECK(300, InitExpression_parse(expression_init, type_instance, code_node, &((*end))) )
    (*expression) = &(expression_init->_base);
  }
  else {
    TypeExpression* type_expression = malloc(sizeof(TypeExpression));
    if (type_expression == NULL) RAISE(303)
    *type_expression = (TypeExpression){TypeExpression__dtl, NULL, 0, NULL, NULL, false, false, false};
    type_expression->_base._base._dtl = TypeExpression__dtl;
    CHECK(304, TypeExpression_parse(type_expression, type_instance) )
    (*expression) = &(type_expression->_base);
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeExpression_parse(TypeExpression* self, TypeInstance* type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeExpression_parse = "TypeExpression.parse";
#define MR_FUNC_NAME _func_name_TypeExpression_parse
Returncode TypeExpression_parse(TypeExpression* self, TypeInstance* type_instance) {
  CHECK(308, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(309, Expression_set_simple_type(&(self->_base), &(glob->type_type->_base)) )
  self->_base.result_type->sub_type = type_instance;
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
  CHECK(313, TypeInstance_analyze(self->_base.result_type->sub_type, &(self->_base._base)) )
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
  CHECK(316, write_cname(self->_base.result_type->sub_type->type_data->name) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func TypeExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func TypeExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)TypeExpression_analyze, (void*)TypeExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_write_preactions};
#endif


/* Initialization expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct InitExpression InitExpression;
#elif MR_STAGE == MR_TYPES(2)
struct InitExpression {
  Expression _base;
  FunctionArguments* arguments;
  SymbolExpression* symbol;
  SyntaxTreeFunction* constructor;
  Expression* value;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode InitExpression_parse(InitExpression* self, TypeInstance* result_type, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_InitExpression_parse = "InitExpression.parse";
#define MR_FUNC_NAME _func_name_InitExpression_parse
Returncode InitExpression_parse(InitExpression* self, TypeInstance* result_type, SyntaxTreeCode* code_node, Char* end) {
  self->_base.code_node = code_node;
  self->_base.result_type = result_type;
  CHECK(331, SyntaxTreeNode_set_location(&(self->_base._base)) )
  self->arguments = malloc(sizeof(FunctionArguments));
  if (self->arguments == NULL) RAISE(332)
  *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->arguments->_base._dtl = FunctionArguments__dtl;
  if ((*end) == '(') {
    CallArgumentFactory* argument_factory = &(CallArgumentFactory){CallArgumentFactory__dtl};
    argument_factory->_base._dtl = CallArgumentFactory__dtl;
    CHECK(335, FunctionArguments_parse(self->arguments, &(argument_factory->_base), code_node, &((*end))) )
  }
  else {
    CHECK(337, FunctionArguments_init(self->arguments) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode InitExpression_analyze(InitExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_InitExpression_analyze = "InitExpression.analyze";
#define MR_FUNC_NAME _func_name_InitExpression_analyze
Returncode InitExpression_analyze(InitExpression* self) {
  CHECK(340, TypeInstance_analyze(self->_base.result_type, &(self->_base._base)) )
  
  CHECK(342, (self->arguments)->_base._dtl[1](self->arguments) )
  if (NULL != self->symbol) {
    CHECK(344, TypeInstance_analyze(self->symbol->_base.result_type, &(self->_base._base)) )
  }
  else {
    CHECK(346, Expression_add_aux_variable(&(self->_base), ACCESS_NEW, self->_base.result_type, &(self->symbol)) )
  }
  
  if (self->symbol->variable->access == ACCESS_NEW && self->_base.result_type->type_data->is_primitive) {
    CHECK(351, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){37, 36, "dynamic allocation of primitive type"}, self->_base.result_type->type_data->name) )
  }
  
  if (!self->_base.result_type->type_data->is_primitive && (self->symbol->variable->access == ACCESS_VAR || self->symbol->variable->access == ACCESS_NEW)) {
    CHECK(358, TypeInstance_check_sequence(self->_base.result_type, &(self->_base._base)) )
    Int _Int35;
    CHECK(359, TypeData_find_meth(self->_base.result_type->type_data, &(String){4, 3, "new"}, &(self->constructor), &(_Int35)) )
    if (!(NULL != self->arguments->parameters->first) &&  ! (NULL != self->arguments->outputs->first) && (!(NULL != self->constructor) || self->_base.result_type->type_data == &(glob->type_string->_base))) {
      self->constructor = NULL;
    }
    else {
      if (!(NULL != self->constructor)) {
        CHECK(365, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){23, 22, "no contructor for type"}, self->_base.result_type->type_data->name) )
      }
      else {
        CallArgument* self_param = malloc(sizeof(CallArgument));
        if (self_param == NULL) RAISE(368)
        *self_param = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, NULL, NULL, false, false};
        self_param->_base._base._dtl = CallArgument__dtl;
        self_param->_base.access = ((Argument*)(self->constructor->arguments->parameters->first->item))->access;
        self_param->code_node = self->_base.code_node;
        self_param->value = &(self->symbol->_base);
        CHECK(373, List_prepend(self->arguments->parameters, &(self_param->_base)) )
        Bool _Bool36;
        CHECK(374, FunctionArguments_check_same_as(self->arguments, self->constructor->arguments, &(_Bool36)) )
      }
    }
    
  }
  else {
    if (NULL != self->arguments->parameters->first) {
      if (NULL != self->arguments->parameters->first->next ||  NULL !=  self->arguments->outputs->first) {
        CHECK(379, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){43, 42, "only one initialization parameter expected"}) )
      }
      Argument* param = self->arguments->parameters->first->item;
      CHECK(382, (param)->_base._dtl[6](param, self->_base.result_type) )
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode InitExpression_write_allocation(InitExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_InitExpression_write_allocation = "InitExpression.write-allocation";
#define MR_FUNC_NAME _func_name_InitExpression_write_allocation
Returncode InitExpression_write_allocation(InitExpression* self) {
  CHECK(385, FunctionArguments_write_preactions(self->arguments) )
  if (self->_base.result_type->type_data == &(glob->type_array->_base) || self->_base.result_type->type_data == &(glob->type_string->_base)) {
    CHECK(388, (self->_base.result_type->length)->_base._dtl[6](self->_base.result_type->length) )
  }
  if (self->_base.result_type->type_data == &(glob->type_array->_base) && self->_base.result_type->sub_type->type_data == &(glob->type_string->_base)) {
    CHECK(391, (self->_base.result_type->sub_type->length)->_base._dtl[6](self->_base.result_type->sub_type->length) )
  }
  
  if (self->symbol->variable->access == ACCESS_VAR) {
    CHECK(394, InitExpression_write_var_init(self) )
  }
  else {
    CHECK(396, InitExpression_write_new_init(self) )
  }
  
  CHECK(398, Expression_write_refman_init(&(self->_base), self->symbol) )
  
  if (NULL != self->constructor) {
    CHECK(401, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(402, SyntaxTreeNode_write_call(&(self->_base._base)) )
    CHECK(403, SyntaxTreeFunction_write_cname(self->constructor) )
    CHECK(404, (self->arguments)->_base._dtl[3](self->arguments) )
    CHECK(405, write(&(String){4, 3, " )\n"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode InitExpression_write_var_init(InitExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_InitExpression_write_var_init = "InitExpression.write-var-init";
#define MR_FUNC_NAME _func_name_InitExpression_write_var_init
Returncode InitExpression_write_var_init(InitExpression* self) {
  CHECK(408, Expression_write_init_var_ref(&(self->_base), self->symbol) )
  
  if (self->_base.result_type->type_data == &(glob->type_array->_base) || self->_base.result_type->type_data == &(glob->type_string->_base)) {
    /* `symbol`_Var.values = `symbol`_Values; */
    CHECK(413, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(414, (self->symbol)->_base._base._dtl[2](self->symbol) )
    CHECK(415, write(&(String){15, 14, "_Var.values = "}) )
    CHECK(416, (self->symbol)->_base._base._dtl[2](self->symbol) )
    CHECK(417, write(&(String){10, 9, "_Values;\n"}) )
    if (self->_base.result_type->type_data == &(glob->type_array->_base) && self->_base.result_type->sub_type->type_data == &(glob->type_string->_base)) {
      /* MR_set_var_string_array( */
      /*    `array-length`, `string-length`, `name`, `name`_Chars); */
      CHECK(422, SyntaxTreeCode_write_spaces(self->_base.code_node) )
      CHECK(423, write(&(String){25, 24, "MR_set_var_string_array("}) )
      CHECK(424, (self->_base.result_type->length)->_base._dtl[2](self->_base.result_type->length) )
      CHECK(425, write(&(String){3, 2, ", "}) )
      CHECK(426, (self->_base.result_type->sub_type->length)->_base._dtl[2](self->_base.result_type->sub_type->length) )
      CHECK(427, write(&(String){3, 2, ", "}) )
      CHECK(428, (self->symbol)->_base._base._dtl[2](self->symbol) )
      CHECK(429, write(&(String){3, 2, ", "}) )
      CHECK(430, (self->symbol)->_base._base._dtl[2](self->symbol) )
      CHECK(431, write(&(String){10, 9, "_Chars);\n"}) )
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode InitExpression_write_new_init(InitExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_InitExpression_write_new_init = "InitExpression.write-new-init";
#define MR_FUNC_NAME _func_name_InitExpression_write_new_init
Returncode InitExpression_write_new_init(InitExpression* self) {
  /* `symbol` = ... */
  CHECK(435, (self->symbol)->_base._base._dtl[2](self->symbol) )
  CHECK(436, write(&(String){4, 3, " = "}) )
  
  if (self->_base.result_type->type_data == &(glob->type_array->_base)) {
    if (self->_base.result_type->sub_type->type_data == &(glob->type_string->_base)) {
      /* MR_new_string_array(`length`, `string-length`); */
      CHECK(441, write(&(String){21, 20, "MR_new_string_array("}) )
      CHECK(442, (self->_base.result_type->length)->_base._dtl[2](self->_base.result_type->length) )
      CHECK(443, write(&(String){3, 2, ", "}) )
      CHECK(444, (self->_base.result_type->sub_type->length)->_base._dtl[2](self->_base.result_type->sub_type->length) )
      
    }
    else {
      /* MR_new_array(`length`, sizeof(`SubType`)); */
      CHECK(448, write(&(String){14, 13, "MR_new_array("}) )
      CHECK(449, (self->_base.result_type->length)->_base._dtl[2](self->_base.result_type->length) )
      CHECK(450, write(&(String){10, 9, ", sizeof("}) )
      CHECK(451, write_cname(self->_base.result_type->sub_type->type_data->name) )
      CHECK(452, write(&(String){2, 1, ")"}) )
      
    }
  }
  else {
    if (self->_base.result_type->type_data == &(glob->type_string->_base)) {
      /* MR_new_string(`length`); */
      CHECK(456, write(&(String){15, 14, "MR_new_string("}) )
      CHECK(457, (self->_base.result_type->length)->_base._dtl[2](self->_base.result_type->length) )
      
    }
    else {
      /* calloc(1, sizeof(`type`)); */
      CHECK(461, write(&(String){18, 17, "calloc(1, sizeof("}) )
      CHECK(462, write_cname(self->_base.result_type->type_data->name) )
      CHECK(463, write(&(String){2, 1, ")"}) )
    }
  }
  
  CHECK(465, write(&(String){4, 3, ");\n"}) )
  
  /* if (`symbol` == NULL) raise(`line-num`) */
  CHECK(468, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  CHECK(469, write(&(String){5, 4, "if ("}) )
  CHECK(470, (self->symbol)->_base._base._dtl[2](self->symbol) )
  CHECK(471, write(&(String){11, 10, " == NULL) "}) )
  CHECK(472, SyntaxTreeNode_write_raise(&(self->_base._base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode InitExpression_write_assign(InitExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_InitExpression_write_assign = "InitExpression.write-assign";
#define MR_FUNC_NAME _func_name_InitExpression_write_assign
Returncode InitExpression_write_assign(InitExpression* self) {
  /* `name` = `value`; */
  Expression* value = NULL;
  CHECK(477, (((Argument*)(self->arguments->parameters->first->item)))->_base._dtl[8](((Argument*)(self->arguments->parameters->first->item)), &(value)) )
  CHECK(478, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  CHECK(479, (value)->_base._dtl[6](value) )
  CHECK(480, (self->symbol)->_base._base._dtl[2](self->symbol) )
  CHECK(481, write(&(String){4, 3, " = "}) )
  CHECK(482, (value)->_base._dtl[2](value) )
  CHECK(483, write(&(String){3, 2, ";\n"}) )
  
  if (!self->_base.result_type->type_data->is_primitive) {
    /* `name`_Refman = `value`_Refman; */
    CHECK(487, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(488, (self->symbol)->_base._base._dtl[2](self->symbol) )
    CHECK(489, write(&(String){11, 10, "_Refman = "}) )
    CHECK(490, (value)->_base._dtl[4](value) )
    CHECK(491, write(&(String){3, 2, ";\n"}) )
  }
  
  if (self->_base.result_type->type_data->is_dynamic) {
    /* `name`_Dynamic = `Type`_Dynamic; */
    CHECK(495, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(496, (self->symbol)->_base._base._dtl[2](self->symbol) )
    CHECK(497, write(&(String){12, 11, "_Dynamic = "}) )
    CHECK(498, (value)->_base._dtl[3](value) )
    CHECK(499, write(&(String){3, 2, ";\n"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode InitExpression_write_preactions(InitExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_InitExpression_write_preactions = "InitExpression.write-preactions";
#define MR_FUNC_NAME _func_name_InitExpression_write_preactions
Returncode InitExpression_write_preactions(InitExpression* self) {
  CHECK(502, InitExpression_write_allocation(self) )
  CHECK(503, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode InitExpression_write(InitExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_InitExpression_write = "InitExpression.write";
#define MR_FUNC_NAME _func_name_InitExpression_write
Returncode InitExpression_write(InitExpression* self) {
  if (self->_base.is_statement) {
    if (!self->_base.result_type->type_data->is_primitive && (self->symbol->variable->access == ACCESS_VAR || self->symbol->variable->access == ACCESS_NEW)) {
      CHECK(510, SyntaxTreeCode_write_spaces(self->_base.code_node) )
      CHECK(511, InitExpression_write_allocation(self) )
    }
    else {
      if (NULL != self->arguments->parameters->first) {
        CHECK(513, InitExpression_write_assign(self) )
      }
    }
  }
  else {
    CHECK(515, (self->symbol)->_base._base._dtl[2](self->symbol) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func InitExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func InitExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)InitExpression_analyze, (void*)InitExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)InitExpression_write_preactions};
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
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
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
