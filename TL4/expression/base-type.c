#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "expression/base-type.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file9_name = "expression/base-type.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file9_name

/* TL4 compiler - Base and Type expressions */

/* The `base` method expression */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct BaseMethExpression BaseMethExpression;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct BaseMethExpression {
  Expression _base;
  Bool is_call;
  SyntaxTreeFunction* function;
  TypeData* parent_type;
  Int bases;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BaseMethExpression_parse_new(BaseMethExpression* self, String* text, SyntaxTreeCode* code_node, Char end, Expression** expression);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BaseMethExpression_parse_new = "BaseMethExpression.parse-new";
#define LUMI_FUNC_NAME _func_name_BaseMethExpression_parse_new
Returncode BaseMethExpression_parse_new(BaseMethExpression* self, String* text, SyntaxTreeCode* code_node, Char end, Expression** expression) {
  free(text);
  BaseMethExpression* base_expression = malloc(sizeof(BaseMethExpression));
  if (base_expression == NULL) RAISE(14)
  *base_expression = (BaseMethExpression){BaseMethExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, false, NULL, NULL, 0};
  base_expression->_base._base._dtl = BaseMethExpression__dtl;
  CHECK(15, BaseMethExpression_init(base_expression, code_node, end == '(') )
  (*expression) = &(base_expression->_base);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BaseMethExpression_init(BaseMethExpression* self, SyntaxTreeCode* code_node, Bool is_call);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BaseMethExpression_init = "BaseMethExpression.init";
#define LUMI_FUNC_NAME _func_name_BaseMethExpression_init
Returncode BaseMethExpression_init(BaseMethExpression* self, SyntaxTreeCode* code_node, Bool is_call) {
  self->_base.code_node = code_node;
  self->is_call = is_call;
  self->_base.access = ACCESS_VAR;
  CHECK(22, SyntaxTreeNode_set_location(&(self->_base._base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BaseMethExpression_analyze(BaseMethExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BaseMethExpression_analyze = "BaseMethExpression.analyze";
#define LUMI_FUNC_NAME _func_name_BaseMethExpression_analyze
Returncode BaseMethExpression_analyze(BaseMethExpression* self) {
  SyntaxTreeFunction* function = NULL;
  CHECK(26, SyntaxTreeCode_get_function(self->_base.code_node, &(function)) )
  self->parent_type = function->parent_type;
  if (!(NULL != self->parent_type)) {
    CHECK(29, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){26, 25, "\"base\" used not in method"}) )
  }
  if (!(NULL != self->parent_type->base_type)) {
    CHECK(31, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){22, 21, "no base type for type"}, function->parent_type->name) )
  }
  if (self->is_call) {
    CHECK(34, TypeData_find_meth(self->parent_type->base_type->type_data, function->name, &(self->function), &(self->bases)) )
    if (!(NULL != self->function)) {
      CHECK(37, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){26, 25, "no base method for method"}, function->name) )
    }
    CHECK(39, Expression_set_simple_type(&(self->_base), glob->type_func) )
    self->_base.result_type->arguments = self->function->arguments;
  }
  else {
    CHECK(42, Expression_set_simple_type(&(self->_base), glob->type_base) )
    CHECK(43, TypeInstance_add_subtype_copy(self->_base.result_type, self->parent_type) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BaseMethExpression_analyze_call(BaseMethExpression* self, FunctionArguments* arguments, TypeInstance** instance_type, Int* bases, Bool* is_function_object);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BaseMethExpression_analyze_call = "BaseMethExpression.analyze-call";
#define LUMI_FUNC_NAME _func_name_BaseMethExpression_analyze_call
Returncode BaseMethExpression_analyze_call(BaseMethExpression* self, FunctionArguments* arguments, TypeInstance** instance_type, Int* bases, Bool* is_function_object) {
  (*is_function_object) = false;
  (*instance_type) = self->parent_type->base_type;
  (*bases) = self->bases;
  CallArgument* self_param = malloc(sizeof(CallArgument));
  if (self_param == NULL) RAISE(52)
  *self_param = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, NULL, false, false, false, false};
  self_param->_base._base._dtl = CallArgument__dtl;
  CHECK(53, SyntaxTreeNode_set_location(&(self_param->_base._base)) )
  self_param->_base.access = ((Argument*)(self->function->arguments->parameters->first->item))->access;
  BaseMethExpression* _BaseMethExpression29 = malloc(sizeof(BaseMethExpression));
  if (_BaseMethExpression29 == NULL) RAISE(55)
  *_BaseMethExpression29 = (BaseMethExpression){BaseMethExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, false, NULL, NULL, 0};
  _BaseMethExpression29->_base._base._dtl = BaseMethExpression__dtl;
  self_param->value = &(_BaseMethExpression29->_base);
  CHECK(56, TypeData_m_self_type_instance(self->parent_type, &(self_param->value->result_type)) )
  CHECK(57, List_prepend(arguments->parameters, &(self_param->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BaseMethExpression_write(BaseMethExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BaseMethExpression_write = "BaseMethExpression.write";
#define LUMI_FUNC_NAME _func_name_BaseMethExpression_write
Returncode BaseMethExpression_write(BaseMethExpression* self) {
  if (self->is_call) {
    CHECK(61, SyntaxTreeFunction_write_cname(self->function) )
  }
  else {
    CHECK(63, write(&(String){5, 4, "self"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func BaseMethExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func BaseMethExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)BaseMethExpression_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)BaseMethExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)BaseMethExpression_analyze_call, (void*)Expression_analyze_mock, (void*)Expression_write_preactions};
#endif


/* Up-cast expression */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct UpCastExpression UpCastExpression;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct UpCastExpression {
  Expression _base;
  Expression* expression;
  Int bases;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UpCastExpression_init_new(UpCastExpression* self, Int bases, Expression** expression);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UpCastExpression_init_new = "UpCastExpression.init-new";
#define LUMI_FUNC_NAME _func_name_UpCastExpression_init_new
Returncode UpCastExpression_init_new(UpCastExpression* self, Int bases, Expression** expression) {
  UpCastExpression* up_cast = malloc(sizeof(UpCastExpression));
  if (up_cast == NULL) RAISE(72)
  *up_cast = (UpCastExpression){UpCastExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, 0};
  up_cast->_base._base._dtl = UpCastExpression__dtl;
  CHECK(73, UpCastExpression_init(up_cast, bases, (*expression)) )
  (*expression) = &(up_cast->_base);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UpCastExpression_init(UpCastExpression* self, Int bases, Expression* expression);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UpCastExpression_init = "UpCastExpression.init";
#define LUMI_FUNC_NAME _func_name_UpCastExpression_init
Returncode UpCastExpression_init(UpCastExpression* self, Int bases, Expression* expression) {
  self->expression = expression;
  self->expression->top = false;
  self->bases = bases;
  CHECK(80, TypeInstance_copy_new(self->expression->result_type, &(self->_base.result_type)) )
  self->_base.access = self->expression->access;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UpCastExpression_write_preactions(UpCastExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UpCastExpression_write_preactions = "UpCastExpression.write-preactions";
#define LUMI_FUNC_NAME _func_name_UpCastExpression_write_preactions
Returncode UpCastExpression_write_preactions(UpCastExpression* self) {
  CHECK(84, (self->expression)->_base._dtl[9](self->expression) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UpCastExpression_write(UpCastExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UpCastExpression_write = "UpCastExpression.write";
#define LUMI_FUNC_NAME _func_name_UpCastExpression_write
Returncode UpCastExpression_write(UpCastExpression* self) {
  /* &(`expression`->_base[._base]...) */
  CHECK(88, UpCastExpression_write_pre(self) )
  CHECK(89, (self->expression)->_base._dtl[4](self->expression) )
  CHECK(90, UpCastExpression_write_post(self) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UpCastExpression_write_dynamic(UpCastExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UpCastExpression_write_dynamic = "UpCastExpression.write-dynamic";
#define LUMI_FUNC_NAME _func_name_UpCastExpression_write_dynamic
Returncode UpCastExpression_write_dynamic(UpCastExpression* self) {
  CHECK(93, UpCastExpression_write_pre(self) )
  CHECK(94, (self->expression)->_base._dtl[5](self->expression) )
  CHECK(95, UpCastExpression_write_post(self) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UpCastExpression_write_refman(UpCastExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UpCastExpression_write_refman = "UpCastExpression.write-refman";
#define LUMI_FUNC_NAME _func_name_UpCastExpression_write_refman
Returncode UpCastExpression_write_refman(UpCastExpression* self) {
  self->expression->top = true;
  CHECK(99, (self->expression)->_base._dtl[6](self->expression) )
  self->expression->top = false;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UpCastExpression_write_pre(UpCastExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UpCastExpression_write_pre = "UpCastExpression.write-pre";
#define LUMI_FUNC_NAME _func_name_UpCastExpression_write_pre
Returncode UpCastExpression_write_pre(UpCastExpression* self) {
  CHECK(103, write(&(String){3, 2, "&("}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UpCastExpression_write_post(UpCastExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UpCastExpression_write_post = "UpCastExpression.write-post";
#define LUMI_FUNC_NAME _func_name_UpCastExpression_write_post
Returncode UpCastExpression_write_post(UpCastExpression* self) {
  if (self->expression->is_complex_field) {
    CHECK(107, write(&(String){2, 1, "."}) )
  }
  else {
    CHECK(109, write(&(String){3, 2, "->"}) )
  }
  CHECK(110, write(&(String){6, 5, "_base"}) )
  {int n; for (n = (1); n < (self->bases); ++n) {
    CHECK(112, write(&(String){7, 6, "._base"}) )
  }}
  CHECK(113, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func UpCastExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func UpCastExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)UpCastExpression_write, (void*)UpCastExpression_write_dynamic, (void*)UpCastExpression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)UpCastExpression_write_preactions};
#endif


#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct ModuleTypeExpression ModuleTypeExpression;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct ModuleTypeExpression {
  Expression _base;
  Expression* module_expression;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode ModuleTypeExpression_analyze_module(ModuleTypeExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_ModuleTypeExpression_analyze_module = "ModuleTypeExpression.analyze-module";
#define LUMI_FUNC_NAME _func_name_ModuleTypeExpression_analyze_module
Returncode ModuleTypeExpression_analyze_module(ModuleTypeExpression* self) {
  CHECK(120, (self->module_expression)->_base._dtl[2](self->module_expression) )
  if (!(NULL != self->module_expression->result_type)) {
    CHECK(122, SyntaxTreeNode_m_syntax_error_msg(&(self->_base.code_node->_base), &(String){38, 37, "expected module, got empty expression"}) )
  }
  if (self->module_expression->result_type->type_data != glob->type_module) {
    CHECK(125, SyntaxTreeNode_m_syntax_error(&(self->_base.code_node->_base), &(String){21, 20, "expected module, got"}, self->module_expression->result_type->type_data->name) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode ModuleTypeExpression_analyze_type_instance(ModuleTypeExpression* self, TypeInstance* type_instance);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_ModuleTypeExpression_analyze_type_instance = "ModuleTypeExpression.analyze-type-instance";
#define LUMI_FUNC_NAME _func_name_ModuleTypeExpression_analyze_type_instance
Returncode ModuleTypeExpression_analyze_type_instance(ModuleTypeExpression* self, TypeInstance* type_instance) {
  if (NULL != self->module_expression) {
    CHECK(131, ModuleTypeExpression_analyze_module(self) )
    CHECK(132, string_new_copy(self->module_expression->result_type->name, &(type_instance->module_name)) )
  }
  CHECK(134, TypeInstance_analyze(type_instance, &(self->_base._base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func ModuleTypeExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func ModuleTypeExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeNode_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)Expression_write_preactions};
#endif


/* Type name expression */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct TypeExpression TypeExpression;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct TypeExpression {
  ModuleTypeExpression _base;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeExpression_parse_new(TypeExpression* self, String* text, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeExpression_parse_new = "TypeExpression.parse-new";
#define LUMI_FUNC_NAME _func_name_TypeExpression_parse_new
Returncode TypeExpression_parse_new(TypeExpression* self, String* text, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  String* value = NULL;
  Char next_end = '\0';
  if ((*end) == '.') {
    CHECK(145, Expression_read_new_value(&(self->_base._base), ends, &(value), &(next_end)) )
    if (value->length > 0) {
      Bool _Bool30;
      CHECK(147, String_equal(value, &(String){7, 6, "length"}, &(_Bool30)) )
      if ((0) < 0 || (0) >= (value)->length) RAISE(147)
      if ((0) < 0 || (0) >= (value)->length) RAISE(147)
      if (_Bool30 || (((value)->values[0]) >= 'A' && ((value)->values[0]) <= 'Z')) {
        EnumExpression* enum_expression = malloc(sizeof(EnumExpression));
        if (enum_expression == NULL) RAISE(148)
        *enum_expression = (EnumExpression){EnumExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL};
        enum_expression->_base._base._base._dtl = EnumExpression__dtl;
        CHECK(149, EnumExpression_parse(enum_expression, text, value, (*expression), code_node) )
        (*end) = next_end;
        (*expression) = &(enum_expression->_base._base);
        return OK;
      }
    }
    glob->save_input = true;
  }
  TypeInstance* type_instance = malloc(sizeof(TypeInstance));
  if (type_instance == NULL) RAISE(155)
  *type_instance = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL, NULL};
  CHECK(156, TypeInstance_parse_name(type_instance, text, &(code_node->_base), code_node, code_node->parent->_base.indentation_spaces, &((*end))) )
  if ((*end) == '(') {
    InitExpression* expression_init = malloc(sizeof(InitExpression));
    if (expression_init == NULL) RAISE(163)
    *expression_init = (InitExpression){InitExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL, NULL};
    expression_init->_base._base._base._dtl = InitExpression__dtl;
    CHECK(164, InitExpression_parse(expression_init, type_instance, (*expression), code_node, &((*end))) )
    (*expression) = &(expression_init->_base._base);
  }
  else {
    TypeExpression* type_expression = malloc(sizeof(TypeExpression));
    if (type_expression == NULL) RAISE(168)
    *type_expression = (TypeExpression){TypeExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL};
    type_expression->_base._base._base._dtl = TypeExpression__dtl;
    CHECK(169, TypeExpression_parse(type_expression, type_instance, (*expression), code_node) )
    (*expression) = &(type_expression->_base._base);
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeExpression_parse(TypeExpression* self, TypeInstance* type_instance, Expression* module_expression, SyntaxTreeCode* code_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeExpression_parse = "TypeExpression.parse";
#define LUMI_FUNC_NAME _func_name_TypeExpression_parse
Returncode TypeExpression_parse(TypeExpression* self, TypeInstance* type_instance, Expression* module_expression, SyntaxTreeCode* code_node) {
  CHECK(177, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  self->_base._base.code_node = code_node;
  CHECK(179, Expression_set_simple_type(&(self->_base._base), glob->type_type) )
  self->_base.module_expression = module_expression;
  self->_base._base.result_type->parameters = malloc(sizeof(List));
  if (self->_base._base.result_type->parameters == NULL) RAISE(181)
  *self->_base._base.result_type->parameters = (List){NULL, NULL};
  CHECK(182, List_add(self->_base._base.result_type->parameters, type_instance) )
  self->_base._base.access = ACCESS_VAR;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeExpression_analyze(TypeExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeExpression_analyze = "TypeExpression.analyze";
#define LUMI_FUNC_NAME _func_name_TypeExpression_analyze
Returncode TypeExpression_analyze(TypeExpression* self) {
  CHECK(186, ModuleTypeExpression_analyze_type_instance(&(self->_base), self->_base._base.result_type->parameters->first->item) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func TypeExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func TypeExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)TypeExpression_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeNode_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)Expression_write_preactions};
#endif


/* Enum name expression */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct EnumExpression EnumExpression;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct EnumExpression {
  ModuleTypeExpression _base;
  String* name;
  String* value;
  EnumData* enum_data;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode EnumExpression_parse(EnumExpression* self, String* name, String* value, Expression* module_expression, SyntaxTreeCode* code_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_EnumExpression_parse = "EnumExpression.parse";
#define LUMI_FUNC_NAME _func_name_EnumExpression_parse
Returncode EnumExpression_parse(EnumExpression* self, String* name, String* value, Expression* module_expression, SyntaxTreeCode* code_node) {
  CHECK(200, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  self->_base._base.code_node = code_node;
  self->name = name;
  self->value = value;
  CHECK(204, Expression_set_simple_type(&(self->_base._base), glob->type_int) )
  self->_base._base.access = ACCESS_VAR;
  self->_base._base.constant = true;
  self->_base.module_expression = module_expression;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode EnumExpression_analyze(EnumExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_EnumExpression_analyze = "EnumExpression.analyze";
#define LUMI_FUNC_NAME _func_name_EnumExpression_analyze
Returncode EnumExpression_analyze(EnumExpression* self) {
  if (NULL != self->_base.module_expression) {
    CHECK(211, ModuleTypeExpression_analyze_module(&(self->_base)) )
    String* module_name = self->_base.module_expression->result_type->name;
    ModuleMembers* _ModuleMembers31;
    CHECK(213, SyntaxTreeNode_find_module(&(self->_base._base.code_node->_base), module_name, &(_ModuleMembers31)) )
    CHECK(213, NameMap_find(_ModuleMembers31->enum_map, self->name, (void**)&(self->enum_data)) )
    if (!(NULL != self->enum_data)) {
      CHECK(215, SyntaxTreeNode_m_syntax_error2(&(self->_base._base._base), &(String){13, 12, "unknown Enum"}, self->name, &(String){10, 9, "in module"}, module_name) )
    }
  }
  else {
    CHECK(220, NameMap_find(glob->current_module->enum_map, self->name, (void**)&(self->enum_data)) )
    if (!(NULL != self->enum_data)) {
      CHECK(222, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){13, 12, "unknown Enum"}, self->name) )
    }
  }
  Bool _Bool32;
  CHECK(223, EnumData_m_has_value(self->enum_data, self->value, &(_Bool32)) )
  if (!_Bool32) {
    CHECK(224, SyntaxTreeNode_m_syntax_error2(&(self->_base._base._base), &(String){5, 4, "Enum"}, self->name, &(String){13, 12, "has no value"}, self->value) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode EnumExpression_write(EnumExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_EnumExpression_write = "EnumExpression.write";
#define LUMI_FUNC_NAME _func_name_EnumExpression_write
Returncode EnumExpression_write(EnumExpression* self) {
  CHECK(228, EnumData_write_cname(self->enum_data) )
  CHECK(229, write(&(String){2, 1, "_"}) )
  CHECK(230, write_cname(self->value) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func EnumExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func EnumExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)EnumExpression_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)EnumExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)Expression_write_preactions};
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
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/initialize.c"
#include "expression/slice.c"
#include "expression/symbol.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/code.c"
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
