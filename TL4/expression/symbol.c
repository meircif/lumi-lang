#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "expression/symbol.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file16_name = "expression/symbol.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file16_name

/* TL4 compiler - Symbol expression */

/* A single symbol expression (variable or global-function) */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SymbolExpression SymbolExpression;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct SymbolExpression {
  Expression _base;
  String* name;
  String* module_name;
  SyntaxTreeVariable* variable;
  SyntaxTreeFunction* function;
  Bool is_annotate;
/* parsing `symbol` */};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SymbolExpression_parse_new(SymbolExpression* self, String* text, SyntaxTreeCode* code_node, Expression** expression);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SymbolExpression_parse_new = "SymbolExpression.parse-new";
#define LUMI_FUNC_NAME _func_name_SymbolExpression_parse_new
Returncode SymbolExpression_parse_new(SymbolExpression* self, String* text, SyntaxTreeCode* code_node, Expression** expression) {
  SymbolExpression* symbol_expression = malloc(sizeof(SymbolExpression));
  if (symbol_expression == NULL) RAISE(13)
  *symbol_expression = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL, false};
  symbol_expression->_base._base._dtl = SymbolExpression__dtl;
  CHECK(14, SymbolExpression_parse(symbol_expression, text, code_node) )
  (*expression) = &(symbol_expression->_base);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* parsing `symbol` */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SymbolExpression_parse(SymbolExpression* self, String* text, SyntaxTreeCode* code_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SymbolExpression_parse = "SymbolExpression.parse";
#define LUMI_FUNC_NAME _func_name_SymbolExpression_parse
Returncode SymbolExpression_parse(SymbolExpression* self, String* text, SyntaxTreeCode* code_node) {
  self->_base.code_node = code_node;
  self->name = text;
  CHECK(21, SyntaxTreeNode_set_location(&(self->_base._base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SymbolExpression_analyze(SymbolExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SymbolExpression_analyze = "SymbolExpression.analyze";
#define LUMI_FUNC_NAME _func_name_SymbolExpression_analyze
Returncode SymbolExpression_analyze(SymbolExpression* self) {
  ModuleMembers* _ModuleMembers49;
  CHECK(24, NameMap_find(glob->module_map, self->name, (void**)&(_ModuleMembers49)) )
  if (NULL != _ModuleMembers49) {
    self->_base.result_type = malloc(sizeof(TypeInstance));
    if (self->_base.result_type == NULL) RAISE(25)
    *self->_base.result_type = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    CHECK(26, string_new_copy(self->name, &(self->_base.result_type->name)) )
    self->_base.result_type->type_data = glob->type_module;
  }
  else {
    CHECK(28, SyntaxTreeCode_find_variable(self->_base.code_node, self->name, self->module_name, &(self->variable)) )
    if (NULL != self->variable) {
      CHECK(30, TypeInstance_copy_new(self->variable->type_instance, &(self->_base.result_type)) )
      self->_base.access = self->variable->access;
      self->_base.constant = self->variable->constant;
      self->_base.assignable =  ! self->_base.constant;
    }
    else {
      CHECK(34, SyntaxTreeNode_find_function(&(self->_base.code_node->_base), self->name, self->module_name, &(self->function)) )
      if (NULL != self->function) {
        CHECK(36, Expression_set_simple_type(&(self->_base), glob->type_func) )
        self->_base.access = ACCESS_VAR;
        CHECK(38, FunctionArguments_copy_new(self->function->arguments, &(self->_base.result_type->arguments)) )
      }
      else {
        if (NULL != self->module_name) {
          CHECK(40, SyntaxTreeNode_m_syntax_error2(&(self->_base._base), &(String){15, 14, "unknown symbol"}, self->name, &(String){10, 9, "in module"}, self->module_name) )
        }
        else {
          CHECK(46, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){15, 14, "unknown symbol"}, self->name) )
        }
      }
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SymbolExpression_analyze_call(SymbolExpression* self, FunctionArguments* arguments, TypeInstance** instance_type, Int* bases, Bool* is_function_object);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SymbolExpression_analyze_call = "SymbolExpression.analyze-call";
#define LUMI_FUNC_NAME _func_name_SymbolExpression_analyze_call
Returncode SymbolExpression_analyze_call(SymbolExpression* self, FunctionArguments* arguments, TypeInstance** instance_type, Int* bases, Bool* is_function_object) {
  (*is_function_object) =  NULL !=  self->variable;
  (*bases) = 0;
  (*instance_type) = NULL;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SymbolExpression_analyze_mock(SymbolExpression* self, Bool is_annotate, Bool* is_mock);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SymbolExpression_analyze_mock = "SymbolExpression.analyze-mock";
#define LUMI_FUNC_NAME _func_name_SymbolExpression_analyze_mock
Returncode SymbolExpression_analyze_mock(SymbolExpression* self, Bool is_annotate, Bool* is_mock) {
  (*is_mock) =  NULL !=  self->function &&  NULL !=  self->function->mocker_function;
  if ((*is_mock)) {
    self->is_annotate = is_annotate;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SymbolExpression_m_order_constants(SymbolExpression* self, List* ordered_list);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SymbolExpression_m_order_constants = "SymbolExpression.m-order-constants";
#define LUMI_FUNC_NAME _func_name_SymbolExpression_m_order_constants
Returncode SymbolExpression_m_order_constants(SymbolExpression* self, List* ordered_list) {
  if (NULL != self->variable) {
    CHECK(63, (self->variable)->_base._base._dtl[3](self->variable, ordered_list) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SymbolExpression_write(SymbolExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SymbolExpression_write = "SymbolExpression.write";
#define LUMI_FUNC_NAME _func_name_SymbolExpression_write
Returncode SymbolExpression_write(SymbolExpression* self) {
  if (NULL != self->function) {
    if (NULL != self->function->mocker_function &&  ! self->is_annotate) {
      CHECK(68, SyntaxTreeFunction_write_cname(&(self->function->mocker_function->_base)) )
    }
    else {
      CHECK(70, SyntaxTreeFunction_write_cname(self->function) )
    }
    return OK;
  }
  if (NULL != self->variable && self->variable->is_output) {
    if (!self->_base.top) {
      CHECK(74, write(&(String){2, 1, "("}) )
    }
    CHECK(75, write(&(String){2, 1, "*"}) )
  }
  if (NULL != self->variable) {
    CHECK(77, SyntaxTreeVariable_write_cname(self->variable) )
  }
  else {
    CHECK(79, write_cname(self->name) )
  }
  if (NULL != self->variable && self->variable->is_output &&  ! self->_base.top) {
    CHECK(81, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SymbolExpression_write_dynamic(SymbolExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SymbolExpression_write_dynamic = "SymbolExpression.write-dynamic";
#define LUMI_FUNC_NAME _func_name_SymbolExpression_write_dynamic
Returncode SymbolExpression_write_dynamic(SymbolExpression* self) {
  if (NULL != self->variable && self->variable->is_output &&  ! self->_base.top) {
    CHECK(85, write(&(String){3, 2, "(*"}) )
    CHECK(86, write_cname(self->name) )
    CHECK(87, write(&(String){10, 9, "_Dynamic)"}) )
  }
  else {
    CHECK(89, Expression_write_dynamic(&(self->_base)) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SymbolExpression_write_refman(SymbolExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SymbolExpression_write_refman = "SymbolExpression.write-refman";
#define LUMI_FUNC_NAME _func_name_SymbolExpression_write_refman
Returncode SymbolExpression_write_refman(SymbolExpression* self) {
  if (NULL != self->variable && self->variable->is_output &&  ! self->_base.top) {
    CHECK(93, write(&(String){3, 2, "(*"}) )
    CHECK(94, write_cname(self->name) )
    CHECK(95, write(&(String){9, 8, "_Refman)"}) )
  }
  else {
    CHECK(97, Expression_write_refman(&(self->_base)) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SymbolExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SymbolExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SymbolExpression_analyze, (void*)SymbolExpression_m_order_constants, (void*)SymbolExpression_write, (void*)SymbolExpression_write_dynamic, (void*)SymbolExpression_write_refman, (void*)SymbolExpression_analyze_call, (void*)SymbolExpression_analyze_mock, (void*)Expression_write_preactions};
#endif

/* An instance member expression */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct MemberExpression MemberExpression;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct MemberExpression {
  SymbolExpression _base;
  Expression* instance;
  Expression* dynamic_call_self_instance;
  Int bases;
  Bool is_mock_field;
/* parsing `instance.symbol` */};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode MemberExpression_parse_new(MemberExpression* self, String* text, SyntaxTreeCode* code_node, Expression** expression);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_MemberExpression_parse_new = "MemberExpression.parse-new";
#define LUMI_FUNC_NAME _func_name_MemberExpression_parse_new
Returncode MemberExpression_parse_new(MemberExpression* self, String* text, SyntaxTreeCode* code_node, Expression** expression) {
  MemberExpression* member_expression = malloc(sizeof(MemberExpression));
  if (member_expression == NULL) RAISE(108)
  *member_expression = (MemberExpression){MemberExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL, false, NULL, NULL, 0, false};
  member_expression->_base._base._base._dtl = MemberExpression__dtl;
  CHECK(109, MemberExpression_parse(member_expression, (*expression), text, code_node) )
  (*expression) = &(member_expression->_base._base);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* parsing `instance.symbol` */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode MemberExpression_parse(MemberExpression* self, Expression* instance, String* text, SyntaxTreeCode* code_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_MemberExpression_parse = "MemberExpression.parse";
#define LUMI_FUNC_NAME _func_name_MemberExpression_parse
Returncode MemberExpression_parse(MemberExpression* self, Expression* instance, String* text, SyntaxTreeCode* code_node) {
  self->_base._base.code_node = code_node;
  self->instance = instance;
  CHECK(119, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  self->_base.name = text;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode MemberExpression_analyze(MemberExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_MemberExpression_analyze = "MemberExpression.analyze";
#define LUMI_FUNC_NAME _func_name_MemberExpression_analyze
Returncode MemberExpression_analyze(MemberExpression* self) {
  CHECK(123, (self->instance)->_base._dtl[2](self->instance) )
  self->_base._base.assignable = self->instance->assignable;
  TypeInstance* instance_type = self->instance->result_type;
  if (!(NULL != instance_type) ||  ! (NULL != instance_type->type_data)) {
    CHECK(127, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){30, 29, "void expression has no member"}, self->_base.name) )
  }
  if (instance_type->type_data == glob->type_type) {
    instance_type = ((TypeInstance*)(instance_type->parameters->first->item));
  }
  else {
    if (instance_type->type_data == glob->type_base) {
      instance_type = ((TypeInstance*)(instance_type->parameters->first->item))->type_data->base_type;
    }
  }
  
  if (instance_type->type_data == glob->type_module) {
    self->_base.module_name = instance_type->name;
    CHECK(135, SymbolExpression_analyze(&(self->_base)) )
    return OK;
  }
  
  CHECK(138, TypeData_find_field(instance_type->type_data, self->_base.name, &(self->_base.variable), &(self->bases)) )
  if (NULL != self->_base.variable) {
    self->_base._base.is_complex_field = self->_base.variable->access == ACCESS_VAR &&  ! self->_base.variable->type_instance->type_data->is_primitive;
    self->_base._base.is_generic_cast = self->_base.variable->type_instance->type_data == glob->type_generic;
    CHECK(145, TypeInstance_f_new_replace_params(self->_base.variable->type_instance, instance_type, self->bases, &(self->_base._base.result_type)) )
    self->_base._base.access = self->_base.variable->access;
    self->_base._base.assignable = true;
  }
  else {
    CHECK(150, TypeData_find_meth(instance_type->type_data, self->_base.name, &(self->_base.function), &(self->bases)) )
    if (!(NULL != self->_base.function)) {
      Bool _Bool50;
      CHECK(153, String_equal(self->_base.name, &(String){7, 6, "mocked"}, &(_Bool50)) )
      self->_base.is_annotate = _Bool50;
      CHECK(154, (self->instance)->_base._dtl[8](self->instance, self->_base.is_annotate, &(self->is_mock_field)) )
      if (self->is_mock_field) {
        if (self->_base.is_annotate) {
          CHECK(157, TypeInstance_copy_new(instance_type, &(self->_base._base.result_type)) )
        }
        else {
          Bool _Bool51;
          CHECK(158, String_equal(self->_base.name, &(String){7, 6, "active"}, &(_Bool51)) )
          if (!_Bool51) {
            CHECK(159, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){28, 27, "mock function has no member"}, self->_base.name) )
          }
          else {
            CHECK(162, Expression_set_simple_type(&(self->_base._base), glob->type_bool) )
            self->_base._base.assignable = true;
          }
        }
        return OK;
      }
      CHECK(165, SyntaxTreeNode_m_syntax_error2(&(self->_base._base._base), &(String){5, 4, "type"}, instance_type->type_data->name, &(String){14, 13, "has no member"}, self->_base.name) )
    }
    if (self->_base.function->is_dynamic && self->instance->result_type->type_data != glob->type_type && self->instance->result_type->type_data != glob->type_base) {
      self->bases = self->_base.function->dynamic_base_count;
      self->_base.function = self->_base.function->dynamic_base_method;
      if (!self->instance->is_complex_field) {
        self->dynamic_call_self_instance = self->instance;
      }
    }
    CHECK(177, Expression_set_simple_type(&(self->_base._base), glob->type_func) )
    self->_base._base.access = ACCESS_VAR;
    CHECK(179, FunctionArguments_copy_new(self->_base.function->arguments, &(self->_base._base.result_type->arguments)) )
  }
  if (self->instance->result_type->type_data == glob->type_base) {
    if (!(NULL != self->_base.function)) {
      CHECK(182, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){31, 30, "calling \"base\" with non-method"}, self->_base.name) )
    }
    TypeInstance* base_result_type = self->instance->result_type;
    self->instance->result_type = ((TypeInstance*)(base_result_type->parameters->first->item));
    free(base_result_type);
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode MemberExpression_analyze_call(MemberExpression* self, FunctionArguments* arguments, TypeInstance** instance_type, Int* bases, Bool* is_function_object);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_MemberExpression_analyze_call = "MemberExpression.analyze-call";
#define LUMI_FUNC_NAME _func_name_MemberExpression_analyze_call
Returncode MemberExpression_analyze_call(MemberExpression* self, FunctionArguments* arguments, TypeInstance** instance_type, Int* bases, Bool* is_function_object) {
  if (self->is_mock_field && self->_base.is_annotate) {
    CHECK(193, (self->instance)->_base._dtl[7](self->instance, arguments, &((*instance_type)), &((*bases)), &((*is_function_object))) )
    return OK;
  }
  CHECK(196, SymbolExpression_analyze_call(&(self->_base), arguments, &((*instance_type)), &((*bases)), &((*is_function_object))) )
  if ((*is_function_object) ||  NULL !=  self->_base.module_name) {
    return OK;
  }
  (*bases) = self->bases;
  if (self->instance->result_type->type_data == glob->type_type) {
    (*instance_type) = ((TypeInstance*)(self->instance->result_type->parameters->first->item));
  }
  else {
    (*instance_type) = self->instance->result_type;
    CallArgument* self_param = malloc(sizeof(CallArgument));
    if (self_param == NULL) RAISE(205)
    *self_param = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, NULL, false, false, false};
    self_param->_base._base._dtl = CallArgument__dtl;
    CHECK(206, SyntaxTreeNode_set_location(&(self_param->_base._base)) )
    self_param->_base.access = ((Argument*)(self->_base.function->arguments->parameters->first->item))->access;
    self_param->value = self->instance;
    self_param->value->top = true;
    CHECK(210, List_prepend(arguments->parameters, &(self_param->_base)) )
  }
  self->instance = NULL;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode MemberExpression_analyze_mock(MemberExpression* self, Bool is_annotate, Bool* is_mock);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_MemberExpression_analyze_mock = "MemberExpression.analyze-mock";
#define LUMI_FUNC_NAME _func_name_MemberExpression_analyze_mock
Returncode MemberExpression_analyze_mock(MemberExpression* self, Bool is_annotate, Bool* is_mock) {
  CHECK(214, SymbolExpression_analyze_mock(&(self->_base), is_annotate, &((*is_mock))) )
  if ((*is_mock)) {
    if (self->_base.function->is_dynamic && self->instance->result_type->type_data != glob->type_type && self->instance->result_type->type_data != glob->type_base) {
      CHECK(218, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){49, 48, "accessing mock function field in dynamic call to"}, self->_base.name) )
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode MemberExpression_write_preactions(MemberExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_MemberExpression_write_preactions = "MemberExpression.write-preactions";
#define LUMI_FUNC_NAME _func_name_MemberExpression_write_preactions
Returncode MemberExpression_write_preactions(MemberExpression* self) {
  if (NULL != self->_base.module_name) {
    return OK;
  }
  if (NULL != self->instance) {
    CHECK(226, (self->instance)->_base._dtl[9](self->instance) )
  }
  if (!(NULL != self->dynamic_call_self_instance || (NULL != self->instance &&  ! (NULL != self->_base.function) && self->instance->result_type->type_data != glob->type_type)) || (NULL != self->instance && self->instance->is_complex_field) || self->is_mock_field) {
    return OK;
  }
  /* if (...) RAISE(`line-num`, ...) */
  CHECK(234, write(&(String){5, 4, "if ("}) )
  if (NULL != self->instance) {
    /* if (`instance` == NULL) RAISE("used member of empty object") */
    /* if (`instance`_Refman->value == NULL) */
    /*   RAISE("used member of outdated weak reference") */
    CHECK(239, Expression_write_as_top(self->instance) )
    CHECK(240, write(&(String){11, 10, " == NULL) "}) )
    CHECK(241, SyntaxTreeNode_write_raise(&(self->_base._base._base), &(String){28, 27, "used member of empty object"}) )
    CHECK(242, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
    CHECK(243, write(&(String){5, 4, "if ("}) )
    CHECK(244, (self->instance)->_base._dtl[6](self->instance) )
    CHECK(245, write(&(String){18, 17, "->value == NULL) "}) )
    CHECK(246, SyntaxTreeNode_write_raise(&(self->_base._base._base), &(String){39, 38, "used member of outdated weak reference"}) )
  }
  else {
    if (NULL != self->dynamic_call_self_instance) {
      /* if (`instance`_Dynamic == NULL) RAISE("dynamic call of empty object") */
      Bool top = self->dynamic_call_self_instance->top;
      self->dynamic_call_self_instance->top = true;
      CHECK(251, (self->dynamic_call_self_instance)->_base._dtl[5](self->dynamic_call_self_instance) )
      CHECK(252, write(&(String){11, 10, " == NULL) "}) )
      CHECK(253, SyntaxTreeNode_write_raise(&(self->_base._base._base), &(String){29, 28, "dynamic call of empty object"}) )
      self->dynamic_call_self_instance->top = top;
    }
  }
  CHECK(255, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode MemberExpression_write(MemberExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_MemberExpression_write = "MemberExpression.write";
#define LUMI_FUNC_NAME _func_name_MemberExpression_write
Returncode MemberExpression_write(MemberExpression* self) {
  if (NULL != self->dynamic_call_self_instance) {
    CHECK(259, (self->dynamic_call_self_instance)->_base._dtl[5](self->dynamic_call_self_instance) )
    CHECK(260, MemberExpression_write_bases(self) )
    CHECK(261, write_cname(self->_base.function->name) )
    return OK;
  }
  if (self->is_mock_field) {
    CHECK(264, (self->instance)->_base._dtl[4](self->instance) )
    if (!self->_base.is_annotate) {
      CHECK(266, write(&(String){2, 1, "_"}) )
      CHECK(267, write_cname(self->_base.name) )
    }
    return OK;
  }
  
  if (self->_base._base.is_generic_cast &&  ! self->_base._base.top) {
    CHECK(271, write(&(String){3, 2, "(("}) )
    CHECK(272, TypeData_write_cname(self->_base._base.result_type->type_data) )
    CHECK(273, write(&(String){4, 3, "*)("}) )
  }
  if (NULL != self->instance &&  ! (NULL != self->_base.function) && self->instance->result_type->type_data != glob->type_type &&  ! (NULL != self->_base.module_name)) {
    if (self->_base._base.is_complex_field && self->_base._base.top) {
      CHECK(278, write(&(String){3, 2, "&("}) )
    }
    CHECK(279, (self->instance)->_base._dtl[4](self->instance) )
    CHECK(280, MemberExpression_write_bases(self) )
  }
  CHECK(281, SymbolExpression_write(&(self->_base)) )
  if (NULL != self->instance &&  ! (NULL != self->_base.function) && self->_base._base.is_complex_field && self->instance->result_type->type_data != glob->type_type && self->_base._base.top) {
    CHECK(284, write(&(String){2, 1, ")"}) )
  }
  if (self->_base._base.is_generic_cast &&  ! self->_base._base.top) {
    CHECK(286, write(&(String){3, 2, "))"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode MemberExpression_write_refman(MemberExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_MemberExpression_write_refman = "MemberExpression.write-refman";
#define LUMI_FUNC_NAME _func_name_MemberExpression_write_refman
Returncode MemberExpression_write_refman(MemberExpression* self) {
  if (self->_base._base.is_complex_field) {
    CHECK(290, (self->instance)->_base._dtl[6](self->instance) )
    return OK;
  }
  Bool top = self->_base._base.top;
  if (self->_base._base.is_generic_cast &&  ! self->_base._base.top) {
    self->_base._base.top = true;
  }
  CHECK(295, SymbolExpression_write_refman(&(self->_base)) )
  self->_base._base.top = top;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode MemberExpression_write_dynamic(MemberExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_MemberExpression_write_dynamic = "MemberExpression.write-dynamic";
#define LUMI_FUNC_NAME _func_name_MemberExpression_write_dynamic
Returncode MemberExpression_write_dynamic(MemberExpression* self) {
  if (self->_base._base.is_complex_field) {
    CHECK(300, write(&(String){2, 1, "&"}) )
    CHECK(301, TypeData_write_cname(self->_base._base.result_type->type_data) )
    CHECK(302, write(&(String){9, 8, "_dynamic"}) )
    return OK;
  }
  Bool top = self->_base._base.top;
  if (self->_base._base.is_generic_cast &&  ! self->_base._base.top) {
    CHECK(306, write(&(String){3, 2, "(("}) )
    CHECK(307, TypeData_write_cname(self->_base._base.result_type->type_data) )
    CHECK(308, write(&(String){12, 11, "_Dynamic*)("}) )
    self->_base._base.top = true;
  }
  CHECK(310, SymbolExpression_write_dynamic(&(self->_base)) )
  self->_base._base.top = top;
  if (self->_base._base.is_generic_cast &&  ! self->_base._base.top) {
    CHECK(313, write(&(String){3, 2, "))"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode MemberExpression_write_bases(MemberExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_MemberExpression_write_bases = "MemberExpression.write-bases";
#define LUMI_FUNC_NAME _func_name_MemberExpression_write_bases
Returncode MemberExpression_write_bases(MemberExpression* self) {
  if (NULL != self->instance && self->instance->is_complex_field) {
    CHECK(317, write(&(String){2, 1, "."}) )
  }
  else {
    CHECK(319, write(&(String){3, 2, "->"}) )
  }
  {int n; for (n = (0); n < (self->bases); ++n) {
    CHECK(321, write(&(String){7, 6, "_base."}) )
  }}
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func MemberExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func MemberExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)MemberExpression_analyze, (void*)SymbolExpression_m_order_constants, (void*)MemberExpression_write, (void*)MemberExpression_write_dynamic, (void*)MemberExpression_write_refman, (void*)MemberExpression_analyze_call, (void*)MemberExpression_analyze_mock, (void*)MemberExpression_write_preactions};
#endif

#undef LUMI_FILE_NAME

#ifndef LUMI_INCLUDES
#define LUMI_INCLUDES
#include "tl4-compiler.c"
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
#include "statement/enum.c"
#include "statement/error.c"
#include "statement/for.c"
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
#include "statement/type.c"
#include "statement/variable.c"
#if LUMI_STAGE == LUMI_TYPES(1)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(2)
#elif LUMI_STAGE == LUMI_TYPES(2)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(3)
#elif LUMI_STAGE == LUMI_TYPES(3)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(4)
#elif LUMI_STAGE == LUMI_TYPES(4)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(5)
#endif
#undef LUMI_INCLUDES
#endif

#endif
