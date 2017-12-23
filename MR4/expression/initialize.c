#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/initialize.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file12_name = "expression/initialize.3.mr";
#endif
#define MR_FILE_NAME _mr_file12_name

/* MR4 compiler - Initialization expression */

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
  CHECK(14, SyntaxTreeNode_set_location(&(self->_base._base)) )
  self->arguments = malloc(sizeof(FunctionArguments));
  if (self->arguments == NULL) RAISE(15)
  *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->arguments->_base._dtl = FunctionArguments__dtl;
  if ((*end) == '(') {
    CallArgumentFactory* argument_factory = &(CallArgumentFactory){CallArgumentFactory__dtl};
    argument_factory->_base._dtl = CallArgumentFactory__dtl;
    CHECK(18, FunctionArguments_parse(self->arguments, &(argument_factory->_base), false, code_node, &((*end))) )
  }
  else {
    CHECK(21, FunctionArguments_init(self->arguments) )
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
  CHECK(24, TypeInstance_analyze(self->_base.result_type, &(self->_base._base)) )
  
  CHECK(26, (self->arguments)->_base._dtl[1](self->arguments) )
  if (NULL != self->symbol) {
    CHECK(28, TypeInstance_analyze(self->symbol->_base.result_type, &(self->_base._base)) )
  }
  else {
    CHECK(30, Expression_add_aux_variable(&(self->_base), ACCESS_OWNER, true, self->_base.result_type, &(self->symbol)) )
  }
  self->_base.access = self->symbol->_base.access;
  
  if (self->symbol->variable->access == ACCESS_OWNER && self->symbol->variable->is_create && self->_base.result_type->type_data->is_primitive) {
    CHECK(38, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){37, 36, "dynamic allocation of primitive type"}, self->_base.result_type->type_data->name) )
  }
  
  if (!self->_base.result_type->type_data->is_primitive && self->symbol->variable->is_create) {
    CHECK(44, TypeInstance_check_sequence(self->_base.result_type, &(self->_base._base)) )
    Int _Int32;
    CHECK(45, TypeData_find_meth(self->_base.result_type->type_data, &(String){4, 3, "new"}, &(self->constructor), &(_Int32)) )
    if (!(NULL != self->arguments->parameters->first) &&  ! (NULL != self->arguments->outputs->first) && (!(NULL != self->constructor) || self->_base.result_type->type_data == &(glob->type_string->_base))) {
      self->constructor = NULL;
    }
    else {
      if (!(NULL != self->constructor)) {
        CHECK(51, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){23, 22, "no contructor for type"}, self->_base.result_type->type_data->name) )
      }
      else {
        CallArgument* self_param = malloc(sizeof(CallArgument));
        if (self_param == NULL) RAISE(54)
        *self_param = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, false, false};
        self_param->_base._base._dtl = CallArgument__dtl;
        self_param->_base.access = ((Argument*)(self->constructor->arguments->parameters->first->item))->access;
        self_param->code_node = self->_base.code_node;
        self_param->value = &(self->symbol->_base);
        CHECK(59, List_prepend(self->arguments->parameters, &(self_param->_base)) )
        Bool _Bool33;
        CHECK(60, FunctionArguments_check_same_as(self->arguments, self->constructor->arguments, &(_Bool33)) )
      }
    }
    
  }
  else {
    if (NULL != self->arguments->parameters->first) {
      if (NULL != self->arguments->parameters->first->next ||  NULL !=  self->arguments->outputs->first) {
        CHECK(65, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){43, 42, "only one initialization parameter expected"}) )
      }
      Argument* param = self->arguments->parameters->first->item;
      CHECK(68, (param)->_base._dtl[6](param, self->_base.result_type) )
      if (self->_base.result_type->type_data->is_primitive && param->access != ACCESS_COPY) {
        if ((param->access) < 0 || (param->access) >= (glob->access_names)->length) RAISE(70)
        CHECK(70, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){49, 48, "access should be \"copy\" for primitive types, got"}, (&(((String*)((glob->access_names)->values))[param->access]))) )
      }
      else {
        if (!self->_base.result_type->type_data->is_primitive && self->_base.access != param->access) {
          if ((self->_base.access) < 0 || (self->_base.access) >= (glob->access_names)->length) RAISE(75)
          if ((param->access) < 0 || (param->access) >= (glob->access_names)->length) RAISE(75)
          CHECK(75, SyntaxTreeNode_m_syntax_error2(&(self->_base._base), &(String){22, 21, "assigning into access"}, (&(((String*)((glob->access_names)->values))[self->_base.access])), &(String){15, 14, "invalid access"}, (&(((String*)((glob->access_names)->values))[param->access]))) )
          
        }
      }
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
  CHECK(83, FunctionArguments_write_preactions(self->arguments) )
  if (self->_base.result_type->type_data == &(glob->type_array->_base) || self->_base.result_type->type_data == &(glob->type_string->_base)) {
    CHECK(86, (self->_base.result_type->length)->_base._dtl[6](self->_base.result_type->length) )
  }
  if (self->_base.result_type->type_data == &(glob->type_array->_base) && self->_base.result_type->sub_type->type_data == &(glob->type_string->_base)) {
    CHECK(89, (self->_base.result_type->sub_type->length)->_base._dtl[6](self->_base.result_type->sub_type->length) )
  }
  
  if (self->symbol->variable->access == ACCESS_VAR) {
    CHECK(92, InitExpression_write_var_init(self) )
  }
  else {
    CHECK(94, InitExpression_write_new_init(self) )
  }
  
  CHECK(96, Expression_write_refman_init(&(self->_base), self->symbol) )
  
  if (NULL != self->constructor) {
    CHECK(99, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(100, SyntaxTreeNode_write_call(&(self->_base._base)) )
    CHECK(101, SyntaxTreeFunction_write_cname(self->constructor) )
    CHECK(102, (self->arguments)->_base._dtl[3](self->arguments) )
    CHECK(103, write(&(String){4, 3, " )\n"}) )
    CHECK(104, FunctionArguments_write_postactions(self->arguments) )
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
  CHECK(107, Expression_write_init_var_ref(&(self->_base), self->symbol) )
  
  if (self->_base.result_type->type_data == &(glob->type_array->_base) || self->_base.result_type->type_data == &(glob->type_string->_base)) {
    /* `symbol`_Var.values = `symbol`_Values; */
    CHECK(112, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(113, (self->symbol)->_base._base._dtl[2](self->symbol) )
    CHECK(114, write(&(String){15, 14, "_Var.values = "}) )
    CHECK(115, (self->symbol)->_base._base._dtl[2](self->symbol) )
    CHECK(116, write(&(String){10, 9, "_Values;\n"}) )
    if (self->_base.result_type->type_data == &(glob->type_array->_base) && self->_base.result_type->sub_type->type_data == &(glob->type_string->_base)) {
      /* MR_set_var_string_array( */
      /*    `array-length`, `string-length`, `name`, `name`_Chars); */
      CHECK(121, SyntaxTreeCode_write_spaces(self->_base.code_node) )
      CHECK(122, write(&(String){25, 24, "MR_set_var_string_array("}) )
      CHECK(123, (self->_base.result_type->length)->_base._dtl[2](self->_base.result_type->length) )
      CHECK(124, write(&(String){3, 2, ", "}) )
      CHECK(125, (self->_base.result_type->sub_type->length)->_base._dtl[2](self->_base.result_type->sub_type->length) )
      CHECK(126, write(&(String){3, 2, ", "}) )
      CHECK(127, (self->symbol)->_base._base._dtl[2](self->symbol) )
      CHECK(128, write(&(String){3, 2, ", "}) )
      CHECK(129, (self->symbol)->_base._base._dtl[2](self->symbol) )
      CHECK(130, write(&(String){10, 9, "_Chars);\n"}) )
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
  CHECK(134, (self->symbol)->_base._base._dtl[2](self->symbol) )
  CHECK(135, write(&(String){4, 3, " = "}) )
  
  if (self->_base.result_type->type_data == &(glob->type_array->_base)) {
    if (self->_base.result_type->sub_type->type_data == &(glob->type_string->_base)) {
      /* MR_new_string_array(`length`, `string-length`); */
      CHECK(140, write(&(String){21, 20, "MR_new_string_array("}) )
      CHECK(141, (self->_base.result_type->length)->_base._dtl[2](self->_base.result_type->length) )
      CHECK(142, write(&(String){3, 2, ", "}) )
      CHECK(143, (self->_base.result_type->sub_type->length)->_base._dtl[2](self->_base.result_type->sub_type->length) )
      
    }
    else {
      /* MR_new_array(`length`, sizeof(`SubType`)); */
      CHECK(147, write(&(String){14, 13, "MR_new_array("}) )
      CHECK(148, (self->_base.result_type->length)->_base._dtl[2](self->_base.result_type->length) )
      CHECK(149, write(&(String){10, 9, ", sizeof("}) )
      CHECK(150, write_cname(self->_base.result_type->sub_type->type_data->name) )
      CHECK(151, write(&(String){2, 1, ")"}) )
      
    }
  }
  else {
    if (self->_base.result_type->type_data == &(glob->type_string->_base)) {
      /* MR_new_string(`length`); */
      CHECK(155, write(&(String){15, 14, "MR_new_string("}) )
      CHECK(156, (self->_base.result_type->length)->_base._dtl[2](self->_base.result_type->length) )
      
    }
    else {
      /* calloc(1, sizeof(`type`)); */
      CHECK(160, write(&(String){18, 17, "calloc(1, sizeof("}) )
      CHECK(161, write_cname(self->_base.result_type->type_data->name) )
      CHECK(162, write(&(String){2, 1, ")"}) )
    }
  }
  
  CHECK(164, write(&(String){4, 3, ");\n"}) )
  
  /* if (`symbol` == NULL) raise(`line-num`) */
  CHECK(167, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  CHECK(168, write(&(String){5, 4, "if ("}) )
  CHECK(169, (self->symbol)->_base._base._dtl[2](self->symbol) )
  CHECK(170, write(&(String){11, 10, " == NULL) "}) )
  CHECK(171, SyntaxTreeNode_write_raise(&(self->_base._base)) )
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
  CHECK(176, (((Argument*)(self->arguments->parameters->first->item)))->_base._dtl[8](((Argument*)(self->arguments->parameters->first->item)), &(value)) )
  CHECK(177, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  CHECK(178, (value)->_base._dtl[6](value) )
  CHECK(179, (self->symbol)->_base._base._dtl[2](self->symbol) )
  CHECK(180, write(&(String){4, 3, " = "}) )
  CHECK(181, (value)->_base._dtl[2](value) )
  CHECK(182, write(&(String){3, 2, ";\n"}) )
  
  if (!self->_base.result_type->type_data->is_primitive) {
    /* `name`_Refman = `value`_Refman; */
    /* MR_inc_ref(`name`_Refman); */
    CHECK(187, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(188, (self->symbol)->_base._base._dtl[2](self->symbol) )
    CHECK(189, write(&(String){11, 10, "_Refman = "}) )
    CHECK(190, (value)->_base._dtl[4](value) )
    CHECK(191, write(&(String){3, 2, ";\n"}) )
    if (self->_base.access != ACCESS_OWNER) {
      CHECK(193, SyntaxTreeCode_write_spaces(self->_base.code_node) )
      CHECK(194, write(&(String){12, 11, "MR_inc_ref("}) )
      CHECK(195, (self->symbol)->_base._base._dtl[2](self->symbol) )
      CHECK(196, write(&(String){11, 10, "_Refman);\n"}) )
    }
  }
  
  if (self->_base.result_type->type_data->is_dynamic) {
    /* `name`_Dynamic = `Type`_Dynamic; */
    CHECK(200, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(201, (self->symbol)->_base._base._dtl[2](self->symbol) )
    CHECK(202, write(&(String){12, 11, "_Dynamic = "}) )
    CHECK(203, (value)->_base._dtl[3](value) )
    CHECK(204, write(&(String){3, 2, ";\n"}) )
  }
  
  CHECK(206, FunctionArguments_write_postactions(self->arguments) )
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
  CHECK(209, InitExpression_write_allocation(self) )
  CHECK(210, SyntaxTreeCode_write_spaces(self->_base.code_node) )
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
    if (!self->_base.result_type->type_data->is_primitive && self->symbol->variable->is_create) {
      CHECK(216, SyntaxTreeCode_write_spaces(self->_base.code_node) )
      CHECK(217, InitExpression_write_allocation(self) )
    }
    else {
      if (NULL != self->arguments->parameters->first) {
        CHECK(219, InitExpression_write_assign(self) )
      }
    }
  }
  else {
    CHECK(221, (self->symbol)->_base._base._dtl[2](self->symbol) )
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
