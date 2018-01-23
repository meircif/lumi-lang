#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/base-type.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file8_name = "expression/base-type.3.mr";
#endif
#define MR_FILE_NAME _mr_file8_name

/* MR4 compiler - Base and Type expressions */

/* The `base` method expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct BaseMethExpression BaseMethExpression;
#elif MR_STAGE == MR_TYPES(2)
struct BaseMethExpression {
  Expression _base;
  Bool is_call;
  SyntaxTreeFunction* function;
  TypeData* parent_type;
  Int bases;
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
  if (base_expression == NULL) RAISE(14)
  *base_expression = (BaseMethExpression){BaseMethExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, NULL, NULL, 0};
  base_expression->_base._base._dtl = BaseMethExpression__dtl;
  CHECK(15, BaseMethExpression_init(base_expression, code_node, end == '(') )
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
  self->_base.access = ACCESS_VAR;
  CHECK(22, SyntaxTreeNode_set_location(&(self->_base._base)) )
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
    CHECK(39, Expression_set_simple_type(&(self->_base), &(glob->type_func->_base)) )
    self->_base.result_type->arguments = self->function->arguments;
  }
  else {
    CHECK(42, Expression_set_simple_type(&(self->_base), &(glob->type_base->_base)) )
    CHECK(43, TypeInstance_add_subtype_copy(self->_base.result_type, self->parent_type) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BaseMethExpression_analyze_call(BaseMethExpression* self, FunctionArguments* arguments, TypeInstance** instance_type, Int* bases, Bool* is_function_object);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BaseMethExpression_analyze_call = "BaseMethExpression.analyze-call";
#define MR_FUNC_NAME _func_name_BaseMethExpression_analyze_call
Returncode BaseMethExpression_analyze_call(BaseMethExpression* self, FunctionArguments* arguments, TypeInstance** instance_type, Int* bases, Bool* is_function_object) {
  (*is_function_object) = false;
  (*instance_type) = self->parent_type->base_type;
  (*bases) = self->bases;
  CallArgument* self_param = malloc(sizeof(CallArgument));
  if (self_param == NULL) RAISE(52)
  *self_param = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, false, false, false};
  self_param->_base._base._dtl = CallArgument__dtl;
  self_param->_base.access = ((Argument*)(self->function->arguments->parameters->first->item))->access;
  BaseMethExpression* _BaseMethExpression23 = malloc(sizeof(BaseMethExpression));
  if (_BaseMethExpression23 == NULL) RAISE(54)
  *_BaseMethExpression23 = (BaseMethExpression){BaseMethExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, NULL, NULL, 0};
  _BaseMethExpression23->_base._base._dtl = BaseMethExpression__dtl;
  self_param->value = &(_BaseMethExpression23->_base);
  CHECK(55, TypeData_m_new_type_instance(self->parent_type, &(self_param->value->result_type)) )
  CHECK(56, List_prepend(arguments->parameters, &(self_param->_base)) )
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
    CHECK(60, SyntaxTreeFunction_write_cname(self->function) )
  }
  else {
    CHECK(62, write(&(String){5, 4, "self"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BaseMethExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BaseMethExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)BaseMethExpression_analyze, (void*)BaseMethExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)BaseMethExpression_analyze_call, (void*)Expression_write_preactions};
#endif


/* Up-cast expression */
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
  if (up_cast == NULL) RAISE(71)
  *up_cast = (UpCastExpression){UpCastExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, 0};
  up_cast->_base._base._dtl = UpCastExpression__dtl;
  CHECK(72, UpCastExpression_init(up_cast, bases, (*expression)) )
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
  CHECK(79, TypeInstance_copy_new(self->expression->result_type, &(self->_base.result_type)) )
  self->_base.access = self->expression->access;
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
  CHECK(83, (self->expression)->_base._dtl[7](self->expression) )
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
  CHECK(87, UpCastExpression_write_pre(self) )
  CHECK(88, (self->expression)->_base._dtl[3](self->expression) )
  CHECK(89, UpCastExpression_write_post(self) )
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
  CHECK(92, UpCastExpression_write_pre(self) )
  CHECK(93, (self->expression)->_base._dtl[4](self->expression) )
  CHECK(94, UpCastExpression_write_post(self) )
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
  CHECK(98, (self->expression)->_base._dtl[5](self->expression) )
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
  CHECK(102, write(&(String){3, 2, "&("}) )
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
  CHECK(105, write(&(String){8, 7, "->_base"}) )
  {int n; for (n = (1); n < (self->bases); ++n) {
    CHECK(107, write(&(String){7, 6, "._base"}) )
  }}
  CHECK(108, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func UpCastExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func UpCastExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)UpCastExpression_write, (void*)UpCastExpression_write_dynamic, (void*)UpCastExpression_write_refman, (void*)Expression_analyze_call, (void*)UpCastExpression_write_preactions};
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
  if (type_instance == NULL) RAISE(115)
  *type_instance = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL};
  CHECK(116, TypeInstance_parse_name(type_instance, text, &(code_node->_base), code_node, &((*end))) )
  if ((*end) == '(') {
    InitExpression* expression_init = malloc(sizeof(InitExpression));
    if (expression_init == NULL) RAISE(119)
    *expression_init = (InitExpression){InitExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL, NULL};
    expression_init->_base._base._dtl = InitExpression__dtl;
    CHECK(120, InitExpression_parse(expression_init, type_instance, code_node, &((*end))) )
    (*expression) = &(expression_init->_base);
  }
  else {
    TypeExpression* type_expression = malloc(sizeof(TypeExpression));
    if (type_expression == NULL) RAISE(123)
    *type_expression = (TypeExpression){TypeExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false};
    type_expression->_base._base._dtl = TypeExpression__dtl;
    CHECK(124, TypeExpression_parse(type_expression, type_instance) )
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
  CHECK(128, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(129, Expression_set_simple_type(&(self->_base), &(glob->type_type->_base)) )
  self->_base.result_type->parameters = malloc(sizeof(List));
  if (self->_base.result_type->parameters == NULL) RAISE(130)
  *self->_base.result_type->parameters = (List){NULL, NULL};
  CHECK(131, List_add(self->_base.result_type->parameters, type_instance) )
  self->_base.access = ACCESS_VAR;
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
  CHECK(135, TypeInstance_analyze(((TypeInstance*)(self->_base.result_type->parameters->first->item)), &(self->_base._base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func TypeExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func TypeExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)TypeExpression_analyze, (void*)SyntaxTreeNode_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_write_preactions};
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
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/initialize.c"
#include "expression/slice.c"
#include "expression/symbol.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "statement/error.c"
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
