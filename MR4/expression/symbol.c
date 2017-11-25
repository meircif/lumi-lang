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
extern Func SymbolExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SymbolExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)SymbolExpression_analyze, (void*)SymbolExpression_write, (void*)Expression_write_dynamic, (void*)SymbolExpression_analyze_call, (void*)Expression_write_preactions};
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
  if (member_expression == NULL) RAISE(62)
  *member_expression = (MemberExpression){MemberExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL, NULL, NULL, NULL, NULL, 0, false};
  member_expression->_base._base._base._dtl = MemberExpression__dtl;
  CHECK(63, MemberExpression_parse(member_expression, (*expression), ends, code_node, &((*end))) )
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
  CHECK(75, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(76, Expression_read_new_value(&(self->_base._base), ends, &(self->_base.name), &((*end))) )
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
  CHECK(79, (self->instance)->_base._dtl[1](self->instance) )
  self->_base._base.assignable = self->instance->assignable;
  if (!(NULL != self->instance->result_type) ||  ! (NULL != self->instance->result_type->type_data)) {
    CHECK(83, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){30, 29, "void expression has no member"}, self->_base.name) )
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
  
  CHECK(90, TypeData_find_field(type_data, self->_base.name, &(self->_base.variable), &(self->bases)) )
  if (NULL != self->_base.variable) {
    CHECK(92, TypeInstance_copy_new(self->_base.variable->type_instance, &(self->_base._base.result_type)) )
    self->_base._base.assignable = true;
  }
  else {
    CHECK(95, TypeData_find_meth(type_data, self->_base.name, &(self->_base.function), &(self->bases)) )
    if (!(NULL != self->_base.function)) {
      CHECK(98, SyntaxTreeNode_m_syntax_error2(&(self->_base._base._base), &(String){5, 4, "type"}, type_data->name, &(String){14, 13, "has no member"}, self->_base.name) )
    }
    if (self->_base.function->is_dynamic && self->instance->result_type->type_data != &(glob->type_type->_base) && self->instance->result_type->type_data != &(glob->type_base->_base)) {
      self->bases = self->_base.function->dynamic_base_count;
      self->_base.function = self->_base.function->dynamic_base_method;
      self->is_dynamic_call = true;
    }
    CHECK(109, Expression_set_simple_type(&(self->_base._base), &(glob->type_func->_base)) )
    CHECK(110, FunctionArguments_copy_new(self->_base.function->arguments, &(self->_base._base.result_type->arguments)) )
  }
  if (self->instance->result_type->type_data == &(glob->type_base->_base)) {
    if (!(NULL != self->_base.function)) {
      CHECK(113, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){31, 30, "calling \"base\" with non-method"}, self->_base.name) )
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
  CHECK(121, SymbolExpression_analyze_call(&(self->_base), arguments, &((*is_function_object))) )
  if ((*is_function_object)) {
    return OK;
  }
  if (self->instance->result_type->type_data == &(glob->type_type->_base)) {
    free(self->instance);
  }
  else {
    CallArgument* self_param = malloc(sizeof(CallArgument));
    if (self_param == NULL) RAISE(126)
    *self_param = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, NULL, NULL, false, false};
    self_param->_base._base._dtl = CallArgument__dtl;
    self_param->_base.access = ((Argument*)(self->_base.function->arguments->parameters->first->item))->access;
    self_param->value = self->instance;
    self_param->value->top = true;
    CHECK(130, List_prepend(arguments->parameters, &(self_param->_base)) )
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
  if (!(NULL != self->dynamic_call_self_instance || (NULL != self->instance &&  ! (NULL != self->_base.function) && self->instance->result_type->type_data != &(glob->type_type->_base)))) {
    return OK;
  }
  if (NULL != self->instance) {
    CHECK(141, (self->instance)->_base._dtl[5](self->instance) )
  }
  /* if (`instance` == NULL[ || *`instance` == NULL]) RAISE(`line-num`) */
  CHECK(143, write(&(String){5, 4, "if ("}) )
  if (NULL != self->instance) {
    CHECK(145, (self->instance)->_base._dtl[2](self->instance) )
    if (!self->instance->result_type->type_data->is_primitive) {
      CHECK(147, write(&(String){14, 13, " == NULL || *"}) )
      CHECK(148, (self->instance)->_base._dtl[2](self->instance) )
    }
  }
  else {
    if (NULL != self->dynamic_call_self_instance) {
      CHECK(150, (self->dynamic_call_self_instance)->_base._dtl[3](self->dynamic_call_self_instance) )
    }
  }
  CHECK(151, write(&(String){11, 10, " == NULL) "}) )
  CHECK(152, SyntaxTreeNode_write_raise(&(self->_base._base._base)) )
  CHECK(153, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
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
    CHECK(157, (self->dynamic_call_self_instance)->_base._dtl[3](self->dynamic_call_self_instance) )
    CHECK(158, MemberExpression_write_bases(self) )
    CHECK(159, write_cname(self->_base.function->name) )
    return OK;
  }
  if (NULL != self->instance &&  ! (NULL != self->_base.function) && self->instance->result_type->type_data != &(glob->type_type->_base)) {
    if (!self->instance->result_type->type_data->is_primitive) {
      CHECK(164, write(&(String){3, 2, "(*"}) )
      self->instance->top = true;
    }
    CHECK(166, (self->instance)->_base._dtl[2](self->instance) )
    if (!self->instance->result_type->type_data->is_primitive) {
      CHECK(168, write(&(String){2, 1, ")"}) )
    }
    CHECK(169, MemberExpression_write_bases(self) )
  }
  CHECK(170, SymbolExpression_write(&(self->_base)) )
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
  CHECK(173, write(&(String){3, 2, "->"}) )
  {int n; for (n = (0); n < (self->bases); ++n) {
    CHECK(175, write(&(String){7, 6, "_base."}) )
  }}
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func MemberExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func MemberExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)MemberExpression_analyze, (void*)MemberExpression_write, (void*)Expression_write_dynamic, (void*)MemberExpression_analyze_call, (void*)MemberExpression_write_preactions};
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
  if (base_expression == NULL) RAISE(188)
  *base_expression = (BaseMethExpression){BaseMethExpression__dtl, NULL, 0, NULL, NULL, false, false, false, false, NULL, NULL};
  base_expression->_base._base._dtl = BaseMethExpression__dtl;
  CHECK(189, BaseMethExpression_init(base_expression, code_node, end == '(') )
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
  CHECK(195, SyntaxTreeNode_set_location(&(self->_base._base)) )
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
  CHECK(199, SyntaxTreeCode_get_function(self->_base.code_node, &(function)) )
  self->parent_type = function->parent_type;
  if (!(NULL != self->parent_type)) {
    CHECK(202, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){26, 25, "\"base\" used not in method"}) )
  }
  if (!(NULL != self->parent_type->base_type)) {
    CHECK(204, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){22, 21, "no base type for type"}, function->parent_type->name) )
  }
  if (self->is_call) {
    Int _Int33;
    CHECK(207, TypeData_find_meth(self->parent_type->base_type, function->name, &(self->function), &(_Int33)) )
    if (!(NULL != function)) {
      CHECK(210, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){26, 25, "no base method for method"}, function->name) )
    }
    CHECK(212, Expression_set_simple_type(&(self->_base), &(glob->type_func->_base)) )
    self->_base.result_type->arguments = self->function->arguments;
  }
  else {
    CHECK(215, Expression_set_simple_type(&(self->_base), &(glob->type_base->_base)) )
    CHECK(216, TypeData_m_new_type_instance(self->parent_type, &(self->_base.result_type->sub_type)) )
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
  if (self_param == NULL) RAISE(221)
  *self_param = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, NULL, NULL, false, false};
  self_param->_base._base._dtl = CallArgument__dtl;
  self_param->_base.access = ((Argument*)(self->function->arguments->parameters->first->item))->access;
  BaseMethExpression* _BaseMethExpression34 = malloc(sizeof(BaseMethExpression));
  if (_BaseMethExpression34 == NULL) RAISE(223)
  *_BaseMethExpression34 = (BaseMethExpression){BaseMethExpression__dtl, NULL, 0, NULL, NULL, false, false, false, false, NULL, NULL};
  _BaseMethExpression34->_base._base._dtl = BaseMethExpression__dtl;
  self_param->value = &(_BaseMethExpression34->_base);
  CHECK(224, TypeData_m_new_type_instance(self->parent_type, &(self_param->value->result_type)) )
  CHECK(225, List_prepend(arguments->parameters, &(self_param->_base)) )
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
    CHECK(229, SyntaxTreeFunction_write_cname(self->function) )
  }
  else {
    CHECK(231, write(&(String){5, 4, "self"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BaseMethExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BaseMethExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)BaseMethExpression_analyze, (void*)BaseMethExpression_write, (void*)Expression_write_dynamic, (void*)BaseMethExpression_analyze_call, (void*)Expression_write_preactions};
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
  if (up_cast == NULL) RAISE(240)
  *up_cast = (UpCastExpression){UpCastExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL, 0};
  up_cast->_base._base._dtl = UpCastExpression__dtl;
  CHECK(241, UpCastExpression_init(up_cast, bases, (*expression)) )
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
  self->bases = bases;
  CHECK(247, TypeInstance_copy_new(self->expression->result_type, &(self->_base.result_type)) )
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
  CHECK(250, (self->expression)->_base._dtl[5](self->expression) )
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
  /* self.write-pre() */
  CHECK(255, write(&(String){8, 7, "(void*)"}) )
  CHECK(256, (self->expression)->_base._dtl[2](self->expression) )
  /* self.write-post() */
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
  CHECK(260, UpCastExpression_write_pre(self) )
  CHECK(261, (self->expression)->_base._dtl[3](self->expression) )
  CHECK(262, UpCastExpression_write_post(self) )
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
  CHECK(265, write(&(String){3, 2, "&("}) )
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
  CHECK(268, write(&(String){8, 7, "->_base"}) )
  {int n; for (n = (1); n < (self->bases); ++n) {
    CHECK(270, write(&(String){7, 6, "._base"}) )
  }}
  CHECK(271, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func UpCastExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func UpCastExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)UpCastExpression_write, (void*)UpCastExpression_write_dynamic, (void*)Expression_analyze_call, (void*)UpCastExpression_write_preactions};
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
  if (type_instance == NULL) RAISE(278)
  *type_instance = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL};
  CHECK(279, TypeInstance_parse_name(type_instance, text, &(code_node->_base), code_node, &((*end))) )
  if ((*end) == '(') {
    InitExpression* expression_init = malloc(sizeof(InitExpression));
    if (expression_init == NULL) RAISE(282)
    *expression_init = (InitExpression){InitExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL, NULL, NULL, NULL};
    expression_init->_base._base._dtl = InitExpression__dtl;
    CHECK(283, InitExpression_parse(expression_init, type_instance, code_node, &((*end))) )
    (*expression) = &(expression_init->_base);
  }
  else {
    TypeExpression* type_expression = malloc(sizeof(TypeExpression));
    if (type_expression == NULL) RAISE(286)
    *type_expression = (TypeExpression){TypeExpression__dtl, NULL, 0, NULL, NULL, false, false, false};
    type_expression->_base._base._dtl = TypeExpression__dtl;
    CHECK(287, TypeExpression_parse(type_expression, type_instance) )
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
  CHECK(291, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(292, Expression_set_simple_type(&(self->_base), &(glob->type_type->_base)) )
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
  CHECK(296, TypeInstance_analyze(self->_base.result_type->sub_type, &(self->_base._base)) )
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
  CHECK(299, write_cname(self->_base.result_type->sub_type->type_data->name) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func TypeExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func TypeExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)TypeExpression_analyze, (void*)TypeExpression_write, (void*)Expression_write_dynamic, (void*)Expression_analyze_call, (void*)Expression_write_preactions};
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
  CHECK(314, SyntaxTreeNode_set_location(&(self->_base._base)) )
  self->arguments = malloc(sizeof(FunctionArguments));
  if (self->arguments == NULL) RAISE(315)
  *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->arguments->_base._dtl = FunctionArguments__dtl;
  if ((*end) == '(') {
    CallArgumentFactory* argument_factory = &(CallArgumentFactory){CallArgumentFactory__dtl};
    argument_factory->_base._dtl = CallArgumentFactory__dtl;
    CHECK(318, FunctionArguments_parse(self->arguments, &(argument_factory->_base), code_node, &((*end))) )
  }
  else {
    CHECK(320, FunctionArguments_init(self->arguments) )
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
  CHECK(323, TypeInstance_analyze(self->_base.result_type, &(self->_base._base)) )
  
  CHECK(325, (self->arguments)->_base._dtl[1](self->arguments) )
  if (NULL != self->symbol) {
    CHECK(327, TypeInstance_analyze(self->symbol->_base.result_type, &(self->_base._base)) )
  }
  else {
    CHECK(329, Expression_add_aux_variable(&(self->_base), ACCESS_NEW, self->_base.result_type, &(self->symbol)) )
  }
  
  if (self->symbol->variable->access == ACCESS_NEW && self->_base.result_type->type_data->is_primitive) {
    CHECK(334, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){37, 36, "dynamic allocation of primitive type"}, self->_base.result_type->type_data->name) )
  }
  
  if (!self->_base.result_type->type_data->is_primitive && (self->symbol->variable->access == ACCESS_VAR || self->symbol->variable->access == ACCESS_NEW)) {
    CHECK(341, TypeInstance_check_sequence(self->_base.result_type, &(self->_base._base)) )
    Int _Int35;
    CHECK(342, TypeData_find_meth(self->_base.result_type->type_data, &(String){4, 3, "new"}, &(self->constructor), &(_Int35)) )
    if (!(NULL != self->arguments->parameters->first) &&  ! (NULL != self->arguments->outputs->first) && (!(NULL != self->constructor) || self->_base.result_type->type_data == &(glob->type_string->_base))) {
      self->constructor = NULL;
    }
    else {
      if (!(NULL != self->constructor)) {
        CHECK(348, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){23, 22, "no contructor for type"}, self->_base.result_type->type_data->name) )
      }
      else {
        CallArgument* self_param = malloc(sizeof(CallArgument));
        if (self_param == NULL) RAISE(351)
        *self_param = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, NULL, NULL, false, false};
        self_param->_base._base._dtl = CallArgument__dtl;
        self_param->_base.access = ((Argument*)(self->constructor->arguments->parameters->first->item))->access;
        self_param->code_node = self->_base.code_node;
        self_param->value = &(self->symbol->_base);
        CHECK(356, List_prepend(self->arguments->parameters, &(self_param->_base)) )
        Bool _Bool36;
        CHECK(357, FunctionArguments_check_same_as(self->arguments, self->constructor->arguments, &(_Bool36)) )
      }
    }
    
  }
  else {
    if (NULL != self->arguments->parameters->first) {
      if (NULL != self->arguments->parameters->first->next ||  NULL !=  self->arguments->outputs->first) {
        CHECK(362, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){43, 42, "only one initialization parameter expected"}) )
      }
      Argument* param = self->arguments->parameters->first->item;
      CHECK(365, (param)->_base._dtl[6](param, self->_base.result_type) )
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
  CHECK(368, FunctionArguments_write_preactions(self->arguments) )
  if (self->_base.result_type->type_data == &(glob->type_array->_base) || self->_base.result_type->type_data == &(glob->type_string->_base)) {
    CHECK(371, (self->_base.result_type->length)->_base._dtl[5](self->_base.result_type->length) )
  }
  if (self->_base.result_type->type_data == &(glob->type_array->_base) && self->_base.result_type->sub_type->type_data == &(glob->type_string->_base)) {
    CHECK(374, (self->_base.result_type->sub_type->length)->_base._dtl[5](self->_base.result_type->sub_type->length) )
  }
  
  CHECK(376, Expression_write_ref_init(&(self->_base), self->symbol) )
  
  if (self->symbol->variable->access == ACCESS_VAR) {
    CHECK(379, InitExpression_write_var_init(self) )
  }
  else {
    CHECK(381, InitExpression_write_new_init(self) )
  }
  
  if (NULL != self->constructor) {
    CHECK(384, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(385, SyntaxTreeNode_write_call(&(self->_base._base)) )
    CHECK(386, SyntaxTreeFunction_write_cname(self->constructor) )
    CHECK(387, (self->arguments)->_base._dtl[3](self->arguments) )
    CHECK(388, write(&(String){4, 3, " )\n"}) )
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
  CHECK(391, Expression_write_init_var_ref(&(self->_base), self->symbol) )
  
  if (self->_base.result_type->type_data == &(glob->type_array->_base) || self->_base.result_type->type_data == &(glob->type_string->_base)) {
    /* `symbol`_Var.values = `symbol`_Values; */
    CHECK(396, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(397, (self->symbol)->_base._base._dtl[2](self->symbol) )
    CHECK(398, write(&(String){15, 14, "_Var.values = "}) )
    CHECK(399, (self->symbol)->_base._base._dtl[2](self->symbol) )
    CHECK(400, write(&(String){10, 9, "_Values;\n"}) )
    if (self->_base.result_type->type_data == &(glob->type_array->_base) && self->_base.result_type->sub_type->type_data == &(glob->type_string->_base)) {
      /* MR_set_var_string_array( */
      /*    `array-length`, `string-length`, `name`, `name`_Chars); */
      CHECK(405, SyntaxTreeCode_write_spaces(self->_base.code_node) )
      CHECK(406, write(&(String){25, 24, "MR_set_var_string_array("}) )
      CHECK(407, (self->_base.result_type->length)->_base._dtl[2](self->_base.result_type->length) )
      CHECK(408, write(&(String){3, 2, ", "}) )
      CHECK(409, (self->_base.result_type->sub_type->length)->_base._dtl[2](self->_base.result_type->sub_type->length) )
      CHECK(410, write(&(String){3, 2, ", "}) )
      CHECK(411, (self->symbol)->_base._base._dtl[2](self->symbol) )
      CHECK(412, write(&(String){3, 2, ", "}) )
      CHECK(413, (self->symbol)->_base._base._dtl[2](self->symbol) )
      CHECK(414, write(&(String){10, 9, "_Chars);\n"}) )
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
  CHECK(417, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  CHECK(418, write(&(String){2, 1, "*"}) )
  CHECK(419, (self->symbol)->_base._base._dtl[2](self->symbol) )
  CHECK(420, write(&(String){4, 3, " = "}) )
  
  if (self->_base.result_type->type_data == &(glob->type_array->_base)) {
    if (self->_base.result_type->sub_type->type_data == &(glob->type_string->_base)) {
      /* MR_new_string_array(`length`, `string-length`); */
      CHECK(425, write(&(String){21, 20, "MR_new_string_array("}) )
      CHECK(426, (self->_base.result_type->length)->_base._dtl[2](self->_base.result_type->length) )
      CHECK(427, write(&(String){3, 2, ", "}) )
      CHECK(428, (self->_base.result_type->sub_type->length)->_base._dtl[2](self->_base.result_type->sub_type->length) )
      
    }
    else {
      /* MR_new_array(`length`, sizeof(`SubType`)); */
      CHECK(432, write(&(String){14, 13, "MR_new_array("}) )
      CHECK(433, (self->_base.result_type->length)->_base._dtl[2](self->_base.result_type->length) )
      CHECK(434, write(&(String){10, 9, ", sizeof("}) )
      CHECK(435, write_cname(self->_base.result_type->sub_type->type_data->name) )
      CHECK(436, write(&(String){2, 1, ")"}) )
      
    }
  }
  else {
    if (self->_base.result_type->type_data == &(glob->type_string->_base)) {
      /* MR_new_string(`length`); */
      CHECK(440, write(&(String){15, 14, "MR_new_string("}) )
      CHECK(441, (self->_base.result_type->length)->_base._dtl[2](self->_base.result_type->length) )
      
    }
    else {
      /* calloc(1, sizeof(`type`)); */
      CHECK(445, write(&(String){18, 17, "calloc(1, sizeof("}) )
      CHECK(446, write_cname(self->_base.result_type->type_data->name) )
      CHECK(447, write(&(String){2, 1, ")"}) )
    }
  }
  
  CHECK(449, write(&(String){4, 3, ");\n"}) )
  
  /* if (*`symbol` == NULL) raise(`line-num`) */
  CHECK(452, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  CHECK(453, write(&(String){6, 5, "if (*"}) )
  CHECK(454, (self->symbol)->_base._base._dtl[2](self->symbol) )
  CHECK(455, write(&(String){11, 10, " == NULL) "}) )
  CHECK(456, SyntaxTreeNode_write_raise(&(self->_base._base)) )
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
  CHECK(461, (((Argument*)(self->arguments->parameters->first->item)))->_base._dtl[8](((Argument*)(self->arguments->parameters->first->item)), &(value)) )
  CHECK(462, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  CHECK(463, (value)->_base._dtl[5](value) )
  CHECK(464, (self->symbol)->_base._base._dtl[2](self->symbol) )
  CHECK(465, write(&(String){4, 3, " = "}) )
  CHECK(466, (value)->_base._dtl[2](value) )
  CHECK(467, write(&(String){3, 2, ";\n"}) )
  if (self->_base.result_type->type_data->is_dynamic) {
    /* `name`_Dynamic = `Type`_Dynamic; */
    CHECK(470, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(471, (self->symbol)->_base._base._dtl[2](self->symbol) )
    CHECK(472, write(&(String){12, 11, "_Dynamic = "}) )
    CHECK(473, (value)->_base._dtl[3](value) )
    CHECK(474, write(&(String){3, 2, ";\n"}) )
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
  CHECK(477, InitExpression_write_allocation(self) )
  CHECK(478, SyntaxTreeCode_write_spaces(self->_base.code_node) )
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
      CHECK(485, SyntaxTreeCode_write_spaces(self->_base.code_node) )
      CHECK(486, InitExpression_write_allocation(self) )
    }
    else {
      if (NULL != self->arguments->parameters->first) {
        CHECK(488, InitExpression_write_assign(self) )
      }
    }
  }
  else {
    CHECK(490, (self->symbol)->_base._base._dtl[2](self->symbol) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func InitExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func InitExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)InitExpression_analyze, (void*)InitExpression_write, (void*)Expression_write_dynamic, (void*)Expression_analyze_call, (void*)InitExpression_write_preactions};
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
