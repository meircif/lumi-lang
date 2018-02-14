#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/symbol.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file15_name = "expression/symbol.3.mr";
#endif
#define MR_FILE_NAME _mr_file15_name

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
  *symbol_expression = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, NULL, NULL, NULL};
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
Returncode SymbolExpression_analyze_call(SymbolExpression* self, FunctionArguments* arguments, TypeInstance** instance_type, Int* bases, Bool* is_function_object);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SymbolExpression_analyze_call = "SymbolExpression.analyze-call";
#define MR_FUNC_NAME _func_name_SymbolExpression_analyze_call
Returncode SymbolExpression_analyze_call(SymbolExpression* self, FunctionArguments* arguments, TypeInstance** instance_type, Int* bases, Bool* is_function_object) {
  (*is_function_object) =  NULL !=  self->variable;
  (*bases) = 0;
  (*instance_type) = NULL;
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
      CHECK(46, SyntaxTreeFunction_write_cname(&(self->function->mocker_function->_base)) )
    }
    else {
      CHECK(48, SyntaxTreeFunction_write_cname(self->function) )
    }
    return OK;
  }
  if (NULL != self->variable && self->variable->is_output) {
    if (!self->_base.top) {
      CHECK(52, write(&(String){2, 1, "("}) )
    }
    CHECK(53, write(&(String){2, 1, "*"}) )
  }
  CHECK(54, write_cname(self->name) )
  if (NULL != self->variable && self->variable->is_output &&  ! self->_base.top) {
    CHECK(56, write(&(String){2, 1, ")"}) )
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
    CHECK(60, write(&(String){3, 2, "(*"}) )
    CHECK(61, write_cname(self->name) )
    CHECK(62, write(&(String){10, 9, "_Dynamic)"}) )
  }
  else {
    CHECK(64, Expression_write_dynamic(&(self->_base)) )
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
    CHECK(68, write(&(String){3, 2, "(*"}) )
    CHECK(69, write_cname(self->name) )
    CHECK(70, write(&(String){9, 8, "_Refman)"}) )
  }
  else {
    CHECK(72, Expression_write_refman(&(self->_base)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SymbolExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SymbolExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SymbolExpression_analyze, (void*)SymbolExpression_write, (void*)SymbolExpression_write_dynamic, (void*)SymbolExpression_write_refman, (void*)SymbolExpression_analyze_call, (void*)Expression_write_preactions};
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
/* parsing `instance.symbol` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_parse_new(MemberExpression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_parse_new = "MemberExpression.parse-new";
#define MR_FUNC_NAME _func_name_MemberExpression_parse_new
Returncode MemberExpression_parse_new(MemberExpression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  MemberExpression* member_expression = malloc(sizeof(MemberExpression));
  if (member_expression == NULL) RAISE(82)
  *member_expression = (MemberExpression){MemberExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, NULL, NULL, NULL, NULL, NULL, 0};
  member_expression->_base._base._base._dtl = MemberExpression__dtl;
  CHECK(83, MemberExpression_parse(member_expression, (*expression), ends, code_node, &((*end))) )
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
  CHECK(95, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(96, Expression_read_new_value(&(self->_base._base), ends, &(self->_base.name), &((*end))) )
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
  CHECK(99, (self->instance)->_base._dtl[2](self->instance) )
  self->_base._base.assignable = self->instance->assignable;
  TypeInstance* instance_type = self->instance->result_type;
  if (!(NULL != instance_type) ||  ! (NULL != instance_type->type_data)) {
    CHECK(103, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){30, 29, "void expression has no member"}, self->_base.name) )
  }
  if (instance_type->type_data == &(glob->type_type->_base)) {
    instance_type = ((TypeInstance*)(instance_type->parameters->first->item));
  }
  else {
    if (instance_type->type_data == &(glob->type_base->_base)) {
      instance_type = ((TypeInstance*)(instance_type->parameters->first->item))->type_data->base_type;
    }
  }
  
  CHECK(109, TypeData_find_field(instance_type->type_data, self->_base.name, &(self->_base.variable), &(self->bases)) )
  if (NULL != self->_base.variable) {
    self->_base._base.is_complex_field = self->_base.variable->access == ACCESS_VAR &&  ! self->_base.variable->type_instance->type_data->is_primitive;
    self->_base._base.is_generic_cast = self->_base.variable->type_instance->type_data == &(glob->type_generic->_base);
    CHECK(116, TypeInstance_f_new_replace_params(self->_base.variable->type_instance, instance_type, self->bases, &(self->_base._base.result_type)) )
    self->_base._base.access = self->_base.variable->access;
    self->_base._base.assignable = true;
  }
  else {
    CHECK(121, TypeData_find_meth(instance_type->type_data, self->_base.name, &(self->_base.function), &(self->bases)) )
    if (!(NULL != self->_base.function)) {
      CHECK(124, SyntaxTreeNode_m_syntax_error2(&(self->_base._base._base), &(String){5, 4, "type"}, instance_type->type_data->name, &(String){14, 13, "has no member"}, self->_base.name) )
    }
    if (self->_base.function->is_dynamic && self->instance->result_type->type_data != &(glob->type_type->_base) && self->instance->result_type->type_data != &(glob->type_base->_base)) {
      self->bases = self->_base.function->dynamic_base_count;
      self->_base.function = self->_base.function->dynamic_base_method;
      if (!self->instance->is_complex_field) {
        self->dynamic_call_self_instance = self->instance;
      }
    }
    CHECK(136, Expression_set_simple_type(&(self->_base._base), &(glob->type_func->_base)) )
    self->_base._base.access = ACCESS_VAR;
    CHECK(138, FunctionArguments_copy_new(self->_base.function->arguments, &(self->_base._base.result_type->arguments)) )
  }
  if (self->instance->result_type->type_data == &(glob->type_base->_base)) {
    if (!(NULL != self->_base.function)) {
      CHECK(141, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){31, 30, "calling \"base\" with non-method"}, self->_base.name) )
    }
    TypeInstance* base_result_type = self->instance->result_type;
    self->instance->result_type = ((TypeInstance*)(base_result_type->parameters->first->item));
    free(base_result_type);
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_analyze_call(MemberExpression* self, FunctionArguments* arguments, TypeInstance** instance_type, Int* bases, Bool* is_function_object);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_analyze_call = "MemberExpression.analyze-call";
#define MR_FUNC_NAME _func_name_MemberExpression_analyze_call
Returncode MemberExpression_analyze_call(MemberExpression* self, FunctionArguments* arguments, TypeInstance** instance_type, Int* bases, Bool* is_function_object) {
  CHECK(151, SymbolExpression_analyze_call(&(self->_base), arguments, &((*instance_type)), &((*bases)), &((*is_function_object))) )
  if ((*is_function_object)) {
    return OK;
  }
  (*bases) = self->bases;
  if (self->instance->result_type->type_data == &(glob->type_type->_base)) {
    (*instance_type) = ((TypeInstance*)(self->instance->result_type->parameters->first->item));
  }
  else {
    (*instance_type) = self->instance->result_type;
    CallArgument* self_param = malloc(sizeof(CallArgument));
    if (self_param == NULL) RAISE(159)
    *self_param = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, NULL, false, false, false};
    self_param->_base._base._dtl = CallArgument__dtl;
    CHECK(160, SyntaxTreeNode_set_location(&(self_param->_base._base)) )
    self_param->_base.access = ((Argument*)(self->_base.function->arguments->parameters->first->item))->access;
    self_param->value = self->instance;
    self_param->value->top = true;
    CHECK(164, List_prepend(arguments->parameters, &(self_param->_base)) )
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
    CHECK(169, (self->instance)->_base._dtl[7](self->instance) )
  }
  if (!(NULL != self->dynamic_call_self_instance || (NULL != self->instance &&  ! (NULL != self->_base.function) && self->instance->result_type->type_data != &(glob->type_type->_base))) || (NULL != self->instance && self->instance->is_complex_field)) {
    return OK;
  }
  /* if (...) RAISE(`line-num`, ...) */
  CHECK(176, write(&(String){5, 4, "if ("}) )
  if (NULL != self->instance) {
    /* if (`instance` == NULL) RAISE("used member of empty object") */
    /* if (`instance`_Refman->value == NULL) */
    /*   RAISE("used member of outdated weak reference") */
    CHECK(181, Expression_write_as_top(self->instance) )
    CHECK(182, write(&(String){11, 10, " == NULL) "}) )
    CHECK(183, SyntaxTreeNode_write_raise(&(self->_base._base._base), &(String){28, 27, "used member of empty object"}) )
    CHECK(184, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
    CHECK(185, write(&(String){5, 4, "if ("}) )
    CHECK(186, (self->instance)->_base._dtl[5](self->instance) )
    CHECK(187, write(&(String){18, 17, "->value == NULL) "}) )
    CHECK(188, SyntaxTreeNode_write_raise(&(self->_base._base._base), &(String){39, 38, "used member of outdated weak reference"}) )
  }
  else {
    if (NULL != self->dynamic_call_self_instance) {
      /* if (`instance`_Dynamic == NULL) RAISE("dynamic call of empty object") */
      Bool top = self->dynamic_call_self_instance->top;
      self->dynamic_call_self_instance->top = true;
      CHECK(193, (self->dynamic_call_self_instance)->_base._dtl[4](self->dynamic_call_self_instance) )
      CHECK(194, write(&(String){11, 10, " == NULL) "}) )
      CHECK(195, SyntaxTreeNode_write_raise(&(self->_base._base._base), &(String){29, 28, "dynamic call of empty object"}) )
      self->dynamic_call_self_instance->top = top;
    }
  }
  CHECK(197, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
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
    CHECK(201, (self->dynamic_call_self_instance)->_base._dtl[4](self->dynamic_call_self_instance) )
    CHECK(202, MemberExpression_write_bases(self) )
    CHECK(203, write_cname(self->_base.function->name) )
    return OK;
  }
  if (self->_base._base.is_generic_cast &&  ! self->_base._base.top) {
    CHECK(206, write(&(String){3, 2, "(("}) )
    CHECK(207, write_cname(self->_base._base.result_type->type_data->name) )
    CHECK(208, write(&(String){4, 3, "*)("}) )
  }
  if (NULL != self->instance &&  ! (NULL != self->_base.function) && self->instance->result_type->type_data != &(glob->type_type->_base)) {
    if (self->_base._base.is_complex_field && self->_base._base.top) {
      CHECK(212, write(&(String){3, 2, "&("}) )
    }
    CHECK(213, (self->instance)->_base._dtl[3](self->instance) )
    CHECK(214, MemberExpression_write_bases(self) )
  }
  CHECK(215, SymbolExpression_write(&(self->_base)) )
  if (NULL != self->instance &&  ! (NULL != self->_base.function) && self->_base._base.is_complex_field && self->instance->result_type->type_data != &(glob->type_type->_base) && self->_base._base.top) {
    CHECK(218, write(&(String){2, 1, ")"}) )
  }
  if (self->_base._base.is_generic_cast &&  ! self->_base._base.top) {
    CHECK(220, write(&(String){3, 2, "))"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_write_refman(MemberExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_write_refman = "MemberExpression.write-refman";
#define MR_FUNC_NAME _func_name_MemberExpression_write_refman
Returncode MemberExpression_write_refman(MemberExpression* self) {
  if (self->_base._base.is_complex_field) {
    CHECK(224, (self->instance)->_base._dtl[5](self->instance) )
    return OK;
  }
  Bool top = self->_base._base.top;
  if (self->_base._base.is_generic_cast &&  ! self->_base._base.top) {
    self->_base._base.top = true;
  }
  CHECK(229, SymbolExpression_write_refman(&(self->_base)) )
  self->_base._base.top = top;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode MemberExpression_write_dynamic(MemberExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_MemberExpression_write_dynamic = "MemberExpression.write-dynamic";
#define MR_FUNC_NAME _func_name_MemberExpression_write_dynamic
Returncode MemberExpression_write_dynamic(MemberExpression* self) {
  if (self->_base._base.is_complex_field) {
    CHECK(234, write(&(String){2, 1, "&"}) )
    CHECK(235, write_cname(self->_base._base.result_type->type_data->name) )
    CHECK(236, write(&(String){9, 8, "_dynamic"}) )
    return OK;
  }
  Bool top = self->_base._base.top;
  if (self->_base._base.is_generic_cast &&  ! self->_base._base.top) {
    CHECK(240, write(&(String){3, 2, "(("}) )
    CHECK(241, write_cname(self->_base._base.result_type->type_data->name) )
    CHECK(242, write(&(String){12, 11, "_Dynamic*)("}) )
    self->_base._base.top = true;
  }
  CHECK(244, SymbolExpression_write_dynamic(&(self->_base)) )
  self->_base._base.top = top;
  if (self->_base._base.is_generic_cast &&  ! self->_base._base.top) {
    CHECK(247, write(&(String){3, 2, "))"}) )
  }
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
  if (NULL != self->instance && self->instance->is_complex_field) {
    CHECK(251, write(&(String){2, 1, "."}) )
  }
  else {
    CHECK(253, write(&(String){3, 2, "->"}) )
  }
  {int n; for (n = (0); n < (self->bases); ++n) {
    CHECK(255, write(&(String){7, 6, "_base."}) )
  }}
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func MemberExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func MemberExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)MemberExpression_analyze, (void*)MemberExpression_write, (void*)MemberExpression_write_dynamic, (void*)MemberExpression_write_refman, (void*)MemberExpression_analyze_call, (void*)MemberExpression_write_preactions};
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
#include "global/type-instance.c"
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
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "statement/error.c"
#include "statement/for.c"
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
#include "statement/type.c"
#include "statement/variable.c"
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
