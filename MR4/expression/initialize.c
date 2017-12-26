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
  
  CHECK(26, (self->arguments)->_base._dtl[2](self->arguments) )
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
      if (NULL != self->constructor) {
        CallArgument* self_param = malloc(sizeof(CallArgument));
        if (self_param == NULL) RAISE(51)
        *self_param = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, false, false};
        self_param->_base._base._dtl = CallArgument__dtl;
        self_param->_base.access = ((Argument*)(self->constructor->arguments->parameters->first->item))->access;
        self_param->code_node = self->_base.code_node;
        self_param->value = &(self->symbol->_base);
        CHECK(56, List_prepend(self->arguments->parameters, &(self_param->_base)) )
        Bool _Bool33;
        CHECK(57, FunctionArguments_check_same_as(self->arguments, self->constructor->arguments, self->_base.result_type, &(_Bool33)) )
      }
      else {
        CHECK(60, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){23, 22, "no contructor for type"}, self->_base.result_type->type_data->name) )
      }
    }
    
  }
  else {
    if (NULL != self->arguments->parameters->first) {
      if (NULL != self->arguments->parameters->first->next ||  NULL !=  self->arguments->outputs->first) {
        CHECK(66, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){43, 42, "only one initialization parameter expected"}) )
      }
      Argument* param = self->arguments->parameters->first->item;
      CHECK(69, (param)->_base._dtl[7](param, self->_base.result_type, NULL) )
      if (self->_base.result_type->type_data->is_primitive && param->access != ACCESS_COPY) {
        if ((param->access) < 0 || (param->access) >= (glob->access_names)->length) RAISE(71)
        CHECK(71, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){49, 48, "access should be \"copy\" for primitive types, got"}, (&(((String*)((glob->access_names)->values))[param->access]))) )
      }
      else {
        if (!self->_base.result_type->type_data->is_primitive && self->_base.access != param->access) {
          if ((self->_base.access) < 0 || (self->_base.access) >= (glob->access_names)->length) RAISE(76)
          if ((param->access) < 0 || (param->access) >= (glob->access_names)->length) RAISE(76)
          CHECK(76, SyntaxTreeNode_m_syntax_error2(&(self->_base._base), &(String){22, 21, "assigning into access"}, (&(((String*)((glob->access_names)->values))[self->_base.access])), &(String){15, 14, "invalid access"}, (&(((String*)((glob->access_names)->values))[param->access]))) )
          
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
  CHECK(84, FunctionArguments_write_preactions(self->arguments) )
  if (self->_base.result_type->type_data == &(glob->type_array->_base) || self->_base.result_type->type_data == &(glob->type_string->_base)) {
    CHECK(87, (self->_base.result_type->length)->_base._dtl[7](self->_base.result_type->length) )
  }
  if (self->_base.result_type->type_data == &(glob->type_array->_base) && ((TypeInstance*)(self->_base.result_type->sub_types->first->item))->type_data == &(glob->type_string->_base)) {
    CHECK(90, (((TypeInstance*)(self->_base.result_type->sub_types->first->item))->length)->_base._dtl[7](((TypeInstance*)(self->_base.result_type->sub_types->first->item))->length) )
  }
  
  if (self->symbol->variable->access == ACCESS_VAR) {
    CHECK(93, InitExpression_write_var_init(self) )
  }
  else {
    CHECK(95, InitExpression_write_new_init(self) )
  }
  
  CHECK(97, Expression_write_refman_init(&(self->_base), self->symbol) )
  
  if (NULL != self->constructor) {
    CHECK(100, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(101, SyntaxTreeNode_write_call(&(self->_base._base)) )
    CHECK(102, SyntaxTreeFunction_write_cname(self->constructor) )
    CHECK(103, (self->arguments)->_base._dtl[4](self->arguments) )
    CHECK(104, write(&(String){4, 3, " )\n"}) )
    CHECK(105, FunctionArguments_write_postactions(self->arguments) )
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
  CHECK(108, Expression_write_init_var_ref(&(self->_base), self->symbol) )
  
  if (self->_base.result_type->type_data == &(glob->type_array->_base) || self->_base.result_type->type_data == &(glob->type_string->_base)) {
    /* `symbol`_Var.values = `symbol`_Values; */
    CHECK(113, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(114, (self->symbol)->_base._base._dtl[3](self->symbol) )
    CHECK(115, write(&(String){15, 14, "_Var.values = "}) )
    CHECK(116, (self->symbol)->_base._base._dtl[3](self->symbol) )
    CHECK(117, write(&(String){10, 9, "_Values;\n"}) )
    if (self->_base.result_type->type_data == &(glob->type_array->_base) && ((TypeInstance*)(self->_base.result_type->sub_types->first->item))->type_data == &(glob->type_string->_base)) {
      /* MR_set_var_string_array( */
      /*    `array-length`, `string-length`, `name`, `name`_Chars); */
      CHECK(122, SyntaxTreeCode_write_spaces(self->_base.code_node) )
      CHECK(123, write(&(String){25, 24, "MR_set_var_string_array("}) )
      CHECK(124, (self->_base.result_type->length)->_base._dtl[3](self->_base.result_type->length) )
      CHECK(125, write(&(String){3, 2, ", "}) )
      CHECK(126, (((TypeInstance*)(self->_base.result_type->sub_types->first->item))->length)->_base._dtl[3](((TypeInstance*)(self->_base.result_type->sub_types->first->item))->length) )
      CHECK(127, write(&(String){3, 2, ", "}) )
      CHECK(128, (self->symbol)->_base._base._dtl[3](self->symbol) )
      CHECK(129, write(&(String){3, 2, ", "}) )
      CHECK(130, (self->symbol)->_base._base._dtl[3](self->symbol) )
      CHECK(131, write(&(String){10, 9, "_Chars);\n"}) )
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
  CHECK(135, (self->symbol)->_base._base._dtl[3](self->symbol) )
  CHECK(136, write(&(String){4, 3, " = "}) )
  
  if (self->_base.result_type->type_data == &(glob->type_array->_base)) {
    if (((TypeInstance*)(self->_base.result_type->sub_types->first->item))->type_data == &(glob->type_string->_base)) {
      /* MR_new_string_array(`length`, `string-length`); */
      CHECK(141, write(&(String){21, 20, "MR_new_string_array("}) )
      CHECK(142, (self->_base.result_type->length)->_base._dtl[3](self->_base.result_type->length) )
      CHECK(143, write(&(String){3, 2, ", "}) )
      CHECK(144, (((TypeInstance*)(self->_base.result_type->sub_types->first->item))->length)->_base._dtl[3](((TypeInstance*)(self->_base.result_type->sub_types->first->item))->length) )
      
    }
    else {
      /* MR_new_array(`length`, sizeof(`SubType`)); */
      CHECK(148, write(&(String){14, 13, "MR_new_array("}) )
      CHECK(149, (self->_base.result_type->length)->_base._dtl[3](self->_base.result_type->length) )
      CHECK(150, write(&(String){10, 9, ", sizeof("}) )
      CHECK(151, write_cname(((TypeInstance*)(self->_base.result_type->sub_types->first->item))->type_data->name) )
      CHECK(152, write(&(String){2, 1, ")"}) )
      
    }
  }
  else {
    if (self->_base.result_type->type_data == &(glob->type_string->_base)) {
      /* MR_new_string(`length`); */
      CHECK(156, write(&(String){15, 14, "MR_new_string("}) )
      CHECK(157, (self->_base.result_type->length)->_base._dtl[3](self->_base.result_type->length) )
      
    }
    else {
      /* calloc(1, sizeof(`type`)); */
      CHECK(161, write(&(String){18, 17, "calloc(1, sizeof("}) )
      CHECK(162, write_cname(self->_base.result_type->type_data->name) )
      CHECK(163, write(&(String){2, 1, ")"}) )
    }
  }
  
  CHECK(165, write(&(String){4, 3, ");\n"}) )
  
  /* if (`symbol` == NULL) raise(`line-num`) */
  CHECK(168, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  CHECK(169, write(&(String){5, 4, "if ("}) )
  CHECK(170, (self->symbol)->_base._base._dtl[3](self->symbol) )
  CHECK(171, write(&(String){11, 10, " == NULL) "}) )
  CHECK(172, SyntaxTreeNode_write_raise(&(self->_base._base)) )
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
  CHECK(177, (((Argument*)(self->arguments->parameters->first->item)))->_base._dtl[9](((Argument*)(self->arguments->parameters->first->item)), &(value)) )
  CHECK(178, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  CHECK(179, (value)->_base._dtl[7](value) )
  CHECK(180, (self->symbol)->_base._base._dtl[3](self->symbol) )
  CHECK(181, write(&(String){4, 3, " = "}) )
  CHECK(182, (value)->_base._dtl[3](value) )
  CHECK(183, write(&(String){3, 2, ";\n"}) )
  
  if (!self->_base.result_type->type_data->is_primitive) {
    /* `name`_Refman = `value`_Refman; */
    /* MR_inc_ref(`name`_Refman); */
    CHECK(188, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(189, (self->symbol)->_base._base._dtl[3](self->symbol) )
    CHECK(190, write(&(String){11, 10, "_Refman = "}) )
    CHECK(191, (value)->_base._dtl[5](value) )
    CHECK(192, write(&(String){3, 2, ";\n"}) )
    if (self->_base.access != ACCESS_OWNER) {
      CHECK(194, SyntaxTreeCode_write_spaces(self->_base.code_node) )
      CHECK(195, write(&(String){12, 11, "MR_inc_ref("}) )
      CHECK(196, (self->symbol)->_base._base._dtl[3](self->symbol) )
      CHECK(197, write(&(String){11, 10, "_Refman);\n"}) )
    }
  }
  
  if (self->_base.result_type->type_data->is_dynamic) {
    /* `name`_Dynamic = `Type`_Dynamic; */
    CHECK(201, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(202, (self->symbol)->_base._base._dtl[3](self->symbol) )
    CHECK(203, write(&(String){12, 11, "_Dynamic = "}) )
    CHECK(204, (value)->_base._dtl[4](value) )
    CHECK(205, write(&(String){3, 2, ";\n"}) )
  }
  
  CHECK(207, FunctionArguments_write_postactions(self->arguments) )
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
  CHECK(210, InitExpression_write_allocation(self) )
  CHECK(211, SyntaxTreeCode_write_spaces(self->_base.code_node) )
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
      CHECK(217, SyntaxTreeCode_write_spaces(self->_base.code_node) )
      CHECK(218, InitExpression_write_allocation(self) )
    }
    else {
      if (NULL != self->arguments->parameters->first) {
        CHECK(220, InitExpression_write_assign(self) )
      }
    }
  }
  else {
    CHECK(222, (self->symbol)->_base._base._dtl[3](self->symbol) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func InitExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func InitExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)InitExpression_analyze, (void*)InitExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)InitExpression_write_preactions};
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
