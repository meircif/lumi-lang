#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "expression/initialize.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _mr_file13_name = "expression/initialize.3.lm";
#endif
#define LUMI_FILE_NAME _mr_file13_name

/* TL4 compiler - Initialization expression */

#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct InitExpression InitExpression;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct InitExpression {
  ModuleTypeExpression _base;
  FunctionArguments* arguments;
  SymbolExpression* symbol;
  SyntaxTreeFunction* constructor;
  Expression* value;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode InitExpression_parse(InitExpression* self, TypeInstance* result_type, Expression* module_expression, SyntaxTreeCode* code_node, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_InitExpression_parse = "InitExpression.parse";
#define LUMI_FUNC_NAME _func_name_InitExpression_parse
Returncode InitExpression_parse(InitExpression* self, TypeInstance* result_type, Expression* module_expression, SyntaxTreeCode* code_node, Char* end) {
  self->_base._base.code_node = code_node;
  self->_base._base.result_type = result_type;
  CHECK(16, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  self->_base.module_expression = module_expression;
  self->arguments = malloc(sizeof(FunctionArguments));
  if (self->arguments == NULL) RAISE(18)
  *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->arguments->_base._dtl = FunctionArguments__dtl;
  if ((*end) == '(') {
    CallArgumentFactory* argument_factory = &(CallArgumentFactory){CallArgumentFactory__dtl};
    argument_factory->_base._dtl = CallArgumentFactory__dtl;
    CHECK(21, FunctionArguments_parse(self->arguments, &(argument_factory->_base), false, code_node, &((*end))) )
  }
  else {
    CHECK(24, FunctionArguments_init(self->arguments) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode InitExpression_analyze(InitExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_InitExpression_analyze = "InitExpression.analyze";
#define LUMI_FUNC_NAME _func_name_InitExpression_analyze
Returncode InitExpression_analyze(InitExpression* self) {
  CHECK(27, ModuleTypeExpression_analyze_type_instance(&(self->_base), self->_base._base.result_type) )
  
  CHECK(29, (self->arguments)->_base._dtl[2](self->arguments) )
  if (NULL != self->symbol) {
    CHECK(31, TypeInstance_analyze(self->symbol->_base.result_type, &(self->_base._base._base)) )
  }
  else {
    CHECK(33, Expression_add_aux_variable(&(self->_base._base), ACCESS_OWNER, true, self->_base._base.result_type, &(self->symbol)) )
  }
  self->_base._base.access = self->symbol->_base.access;
  
  if (self->symbol->variable->access == ACCESS_OWNER && self->symbol->variable->is_create && self->_base._base.result_type->type_data->is_primitive) {
    CHECK(41, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){37, 36, "dynamic allocation of primitive type"}, self->_base._base.result_type->type_data->name) )
  }
  
  if (!self->_base._base.result_type->type_data->is_primitive && self->symbol->variable->is_create) {
    CHECK(47, TypeInstance_check_sequence(self->_base._base.result_type, &(self->_base._base._base)) )
    if (self->_base._base.result_type->type_data == glob->type_array && ((TypeInstance*)(self->_base._base.result_type->parameters->first->item))->type_data == glob->type_generic) {
      CHECK(50, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){28, 27, "cannot create generic array"}) )
    }
    Int _Int46;
    CHECK(51, TypeData_find_meth(self->_base._base.result_type->type_data, &(String){4, 3, "new"}, &(self->constructor), &(_Int46)) )
    if (!(NULL != self->arguments->parameters->first) &&  ! (NULL != self->arguments->outputs->first) && (!(NULL != self->constructor) || self->_base._base.result_type->type_data == glob->type_string)) {
      self->constructor = NULL;
    }
    else {
      if (NULL != self->constructor) {
        CallArgument* self_param = malloc(sizeof(CallArgument));
        if (self_param == NULL) RAISE(57)
        *self_param = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, NULL, false, false, false};
        self_param->_base._base._dtl = CallArgument__dtl;
        CHECK(58, SyntaxTreeNode_set_location(&(self_param->_base._base)) )
        self_param->_base.access = ((Argument*)(self->constructor->arguments->parameters->first->item))->access;
        self_param->code_node = self->_base._base.code_node;
        self_param->value = &(self->symbol->_base);
        CHECK(63, List_prepend(self->arguments->parameters, &(self_param->_base)) )
        Bool _Bool47;
        CHECK(64, FunctionArguments_check_same_as(self->arguments, self->constructor->arguments, self->_base._base.result_type, 0, &(_Bool47)) )
      }
      else {
        CHECK(67, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){23, 22, "no contructor for type"}, self->_base._base.result_type->type_data->name) )
      }
    }
    
  }
  else {
    if (NULL != self->arguments->parameters->first) {
      if (NULL != self->arguments->parameters->first->next ||  NULL !=  self->arguments->outputs->first) {
        CHECK(73, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){43, 42, "only one initialization parameter expected"}) )
      }
      Argument* param = self->arguments->parameters->first->item;
      CHECK(76, (param)->_base._dtl[8](param, self->_base._base.result_type, NULL, 0) )
      if (self->_base._base.result_type->type_data->is_primitive && param->access != ACCESS_COPY) {
        if ((param->access) < 0 || (param->access) >= (glob->access_names)->length) RAISE(78)
        CHECK(78, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){49, 48, "access should be \"copy\" for primitive types, got"}, (&(((String*)((glob->access_names)->values))[param->access]))) )
      }
      else {
        if (!self->_base._base.result_type->type_data->is_primitive && self->_base._base.access != param->access) {
          if ((self->_base._base.access) < 0 || (self->_base._base.access) >= (glob->access_names)->length) RAISE(83)
          if ((param->access) < 0 || (param->access) >= (glob->access_names)->length) RAISE(83)
          CHECK(83, SyntaxTreeNode_m_syntax_error2(&(self->_base._base._base), &(String){22, 21, "assigning into access"}, (&(((String*)((glob->access_names)->values))[self->_base._base.access])), &(String){15, 14, "invalid access"}, (&(((String*)((glob->access_names)->values))[param->access]))) )
          
        }
      }
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode InitExpression_write_allocation(InitExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_InitExpression_write_allocation = "InitExpression.write-allocation";
#define LUMI_FUNC_NAME _func_name_InitExpression_write_allocation
Returncode InitExpression_write_allocation(InitExpression* self) {
  CHECK(91, FunctionArguments_write_preactions(self->arguments) )
  if (self->_base._base.result_type->type_data == glob->type_array || self->_base._base.result_type->type_data == glob->type_string) {
    CHECK(94, (self->_base._base.result_type->length)->_base._dtl[9](self->_base._base.result_type->length) )
  }
  if (self->_base._base.result_type->type_data == glob->type_array && ((TypeInstance*)(self->_base._base.result_type->parameters->first->item))->type_data == glob->type_string) {
    CHECK(97, (((TypeInstance*)(self->_base._base.result_type->parameters->first->item))->length)->_base._dtl[9](((TypeInstance*)(self->_base._base.result_type->parameters->first->item))->length) )
  }
  
  if (self->symbol->variable->access == ACCESS_VAR) {
    CHECK(100, InitExpression_write_var_init(self) )
  }
  else {
    CHECK(102, InitExpression_write_new_init(self) )
  }
  
  CHECK(104, Expression_write_refman_init(&(self->_base._base), self->symbol) )
  
  if (NULL != self->constructor) {
    CHECK(107, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
    CHECK(108, SyntaxTreeNode_write_call(&(self->_base._base._base)) )
    CHECK(109, SyntaxTreeFunction_write_cname(self->constructor) )
    CHECK(110, (self->arguments)->_base._dtl[5](self->arguments) )
    CHECK(111, write(&(String){4, 3, " )\n"}) )
    CHECK(112, FunctionArguments_write_postactions(self->arguments) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode InitExpression_write_var_init(InitExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_InitExpression_write_var_init = "InitExpression.write-var-init";
#define LUMI_FUNC_NAME _func_name_InitExpression_write_var_init
Returncode InitExpression_write_var_init(InitExpression* self) {
  CHECK(115, Expression_write_init_var_ref(&(self->_base._base), self->symbol) )
  
  if (self->_base._base.result_type->type_data == glob->type_array || self->_base._base.result_type->type_data == glob->type_string) {
    /* `symbol`_Var.values = `symbol`_Values; */
    CHECK(120, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
    CHECK(121, (self->symbol)->_base._base._dtl[4](self->symbol) )
    CHECK(122, write(&(String){15, 14, "_Var.values = "}) )
    CHECK(123, (self->symbol)->_base._base._dtl[4](self->symbol) )
    CHECK(124, write(&(String){10, 9, "_Values;\n"}) )
    if (self->_base._base.result_type->type_data == glob->type_array && ((TypeInstance*)(self->_base._base.result_type->parameters->first->item))->type_data == glob->type_string) {
      /* LUMI_set_var_string_array( */
      /*    `array-length`, `string-length`, `name`, `name`_Chars); */
      CHECK(129, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
      CHECK(130, write(&(String){27, 26, "LUMI_set_var_string_array("}) )
      CHECK(131, (self->_base._base.result_type->length)->_base._dtl[4](self->_base._base.result_type->length) )
      CHECK(132, write(&(String){3, 2, ", "}) )
      CHECK(133, (((TypeInstance*)(self->_base._base.result_type->parameters->first->item))->length)->_base._dtl[4](((TypeInstance*)(self->_base._base.result_type->parameters->first->item))->length) )
      CHECK(134, write(&(String){3, 2, ", "}) )
      CHECK(135, (self->symbol)->_base._base._dtl[4](self->symbol) )
      CHECK(136, write(&(String){3, 2, ", "}) )
      CHECK(137, (self->symbol)->_base._base._dtl[4](self->symbol) )
      CHECK(138, write(&(String){10, 9, "_Chars);\n"}) )
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode InitExpression_write_new_init(InitExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_InitExpression_write_new_init = "InitExpression.write-new-init";
#define LUMI_FUNC_NAME _func_name_InitExpression_write_new_init
Returncode InitExpression_write_new_init(InitExpression* self) {
  /* `symbol` = ... */
  CHECK(142, (self->symbol)->_base._base._dtl[4](self->symbol) )
  CHECK(143, write(&(String){4, 3, " = "}) )
  
  if (self->_base._base.result_type->type_data == glob->type_array) {
    if (((TypeInstance*)(self->_base._base.result_type->parameters->first->item))->type_data == glob->type_string) {
      /* LUMI_new_string_array(`length`, `string-length`); */
      CHECK(148, write(&(String){23, 22, "LUMI_new_string_array("}) )
      CHECK(149, (self->_base._base.result_type->length)->_base._dtl[4](self->_base._base.result_type->length) )
      CHECK(150, write(&(String){3, 2, ", "}) )
      CHECK(151, (((TypeInstance*)(self->_base._base.result_type->parameters->first->item))->length)->_base._dtl[4](((TypeInstance*)(self->_base._base.result_type->parameters->first->item))->length) )
      
    }
    else {
      /* LUMI_new_array(`length`, sizeof(`SubType`)); */
      CHECK(155, write(&(String){16, 15, "LUMI_new_array("}) )
      CHECK(156, (self->_base._base.result_type->length)->_base._dtl[4](self->_base._base.result_type->length) )
      CHECK(157, write(&(String){10, 9, ", sizeof("}) )
      CHECK(158, TypeData_write_cname(((TypeInstance*)(self->_base._base.result_type->parameters->first->item))->type_data) )
      CHECK(159, write(&(String){2, 1, ")"}) )
      
    }
  }
  else {
    if (self->_base._base.result_type->type_data == glob->type_string) {
      /* LUMI_new_string(`length`); */
      CHECK(163, write(&(String){17, 16, "LUMI_new_string("}) )
      CHECK(164, (self->_base._base.result_type->length)->_base._dtl[4](self->_base._base.result_type->length) )
      
    }
    else {
      /* LUMI_alloc(sizeof(`type`)); */
      CHECK(168, write(&(String){19, 18, "LUMI_alloc(sizeof("}) )
      CHECK(169, TypeData_write_cname(self->_base._base.result_type->type_data) )
      CHECK(170, write(&(String){2, 1, ")"}) )
    }
  }
  
  CHECK(172, write(&(String){4, 3, ");\n"}) )
  
  /* if (`symbol` == NULL) raise(`line-num`) */
  CHECK(175, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  CHECK(176, write(&(String){5, 4, "if ("}) )
  CHECK(177, (self->symbol)->_base._base._dtl[4](self->symbol) )
  CHECK(178, write(&(String){11, 10, " == NULL) "}) )
  CHECK(179, SyntaxTreeNode_write_raise(&(self->_base._base._base), &(String){50, 49, "insufficient memory for object dynamic allocation"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode InitExpression_write_assign(InitExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_InitExpression_write_assign = "InitExpression.write-assign";
#define LUMI_FUNC_NAME _func_name_InitExpression_write_assign
Returncode InitExpression_write_assign(InitExpression* self) {
  /* `name` = `value`; */
  Expression* value = NULL;
  CHECK(184, (((Argument*)(self->arguments->parameters->first->item)))->_base._dtl[10](((Argument*)(self->arguments->parameters->first->item)), &(value)) )
  CHECK(185, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  CHECK(186, (value)->_base._dtl[9](value) )
  CHECK(187, (self->symbol)->_base._base._dtl[4](self->symbol) )
  CHECK(188, write(&(String){4, 3, " = "}) )
  CHECK(189, (value)->_base._dtl[4](value) )
  CHECK(190, write(&(String){3, 2, ";\n"}) )
  
  if (!self->_base._base.result_type->type_data->is_primitive) {
    /* `name`_Refman = `value`_Refman; */
    /* LUMI_inc_ref(`name`_Refman); */
    CHECK(195, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
    CHECK(196, (self->symbol)->_base._base._dtl[4](self->symbol) )
    CHECK(197, write(&(String){11, 10, "_Refman = "}) )
    CHECK(198, (value)->_base._dtl[6](value) )
    CHECK(199, write(&(String){3, 2, ";\n"}) )
    if (self->_base._base.access != ACCESS_OWNER) {
      CHECK(201, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
      CHECK(202, write(&(String){14, 13, "LUMI_inc_ref("}) )
      CHECK(203, (self->symbol)->_base._base._dtl[4](self->symbol) )
      CHECK(204, write(&(String){11, 10, "_Refman);\n"}) )
    }
  }
  
  if (self->_base._base.result_type->type_data->is_dynamic) {
    /* `name`_Dynamic = `Type`_Dynamic; */
    CHECK(208, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
    CHECK(209, (self->symbol)->_base._base._dtl[4](self->symbol) )
    CHECK(210, write(&(String){12, 11, "_Dynamic = "}) )
    CHECK(211, (value)->_base._dtl[5](value) )
    CHECK(212, write(&(String){3, 2, ";\n"}) )
  }
  
  CHECK(214, FunctionArguments_write_postactions(self->arguments) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode InitExpression_write_preactions(InitExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_InitExpression_write_preactions = "InitExpression.write-preactions";
#define LUMI_FUNC_NAME _func_name_InitExpression_write_preactions
Returncode InitExpression_write_preactions(InitExpression* self) {
  CHECK(217, InitExpression_write_allocation(self) )
  CHECK(218, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode InitExpression_write(InitExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_InitExpression_write = "InitExpression.write";
#define LUMI_FUNC_NAME _func_name_InitExpression_write
Returncode InitExpression_write(InitExpression* self) {
  if (self->_base._base.is_statement) {
    if (!self->_base._base.result_type->type_data->is_primitive && self->symbol->variable->is_create) {
      CHECK(224, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
      CHECK(225, InitExpression_write_allocation(self) )
    }
    else {
      if (NULL != self->arguments->parameters->first) {
        CHECK(227, InitExpression_write_assign(self) )
      }
    }
  }
  else {
    CHECK(229, (self->symbol)->_base._base._dtl[4](self->symbol) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func InitExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func InitExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)InitExpression_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)InitExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)InitExpression_write_preactions};
#endif

#undef LUMI_FILE_NAME

#ifndef LUMI_INCLUDES
#define LUMI_INCLUDES
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
#include "expression/slice.c"
#include "expression/symbol.c"
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
#include "tl4-compiler.c"
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
