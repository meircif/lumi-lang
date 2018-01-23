#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/call.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file9_name = "expression/call.3.mr";
#endif
#define MR_FILE_NAME _mr_file9_name

/* MR4 compiler - Call expression */

/* Function call expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct CallExpression CallExpression;
#elif MR_STAGE == MR_TYPES(2)
struct CallExpression {
  Expression _base;
  Expression* function;
  FunctionArguments* arguments;
  Expression* output;
  Bool is_function_object;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallExpression_parse_new(CallExpression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallExpression_parse_new = "CallExpression.parse-new";
#define MR_FUNC_NAME _func_name_CallExpression_parse_new
Returncode CallExpression_parse_new(CallExpression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  CallExpression* call_expression = malloc(sizeof(CallExpression));
  if (call_expression == NULL) RAISE(12)
  *call_expression = (CallExpression){CallExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL, false};
  call_expression->_base._base._dtl = CallExpression__dtl;
  CHECK(13, CallExpression_parse(call_expression, (*expression), code_node, &((*end))) )
  (*expression) = &(call_expression->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallExpression_parse(CallExpression* self, Expression* function, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallExpression_parse = "CallExpression.parse";
#define MR_FUNC_NAME _func_name_CallExpression_parse
Returncode CallExpression_parse(CallExpression* self, Expression* function, SyntaxTreeCode* code_node, Char* end) {
  self->function = function;
  self->_base.code_node = code_node;
  CHECK(20, SyntaxTreeNode_set_location(&(self->_base._base)) )
  self->arguments = malloc(sizeof(FunctionArguments));
  if (self->arguments == NULL) RAISE(21)
  *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->arguments->_base._dtl = FunctionArguments__dtl;
  CallArgumentFactory* argument_factory = &(CallArgumentFactory){CallArgumentFactory__dtl};
  argument_factory->_base._dtl = CallArgumentFactory__dtl;
  CHECK(23, FunctionArguments_parse(self->arguments, &(argument_factory->_base), false, code_node, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallExpression_analyze(CallExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallExpression_analyze = "CallExpression.analyze";
#define MR_FUNC_NAME _func_name_CallExpression_analyze
Returncode CallExpression_analyze(CallExpression* self) {
  CHECK(27, (self->function)->_base._dtl[2](self->function) )
  CHECK(28, (self->arguments)->_base._dtl[2](self->arguments) )
  if (!(NULL != self->function->result_type)) {
    CHECK(30, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){32, 31, "void expression is not callable"}) )
  }
  if (self->function->result_type->type_data != &(glob->type_func->_base)) {
    CHECK(32, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){18, 17, "non callable type"}, self->function->result_type->type_data->name) )
  }
  FunctionArguments* declaration = self->function->result_type->arguments;
  TypeInstance* result_type = NULL;
  CHECK(37, FunctionArguments_get_result_type(declaration, &(self->_base.access), &(result_type)) )
  if (!self->_base.is_statement) {
    CHECK(39, TypeInstance_copy_new(result_type, &(self->_base.result_type)) )
  }
  TypeInstance* instance_type = NULL;
  Int bases = 0;
  CHECK(42, (self->function)->_base._dtl[6](self->function, self->arguments, &(instance_type), &(bases), &(self->is_function_object)) )
  Bool _Bool24;
  CHECK(44, FunctionArguments_check_same_as(self->arguments, declaration, instance_type, bases, &(_Bool24)) )
  if (_Bool24) {
    /* add omitted output */
    CallArgument* output = malloc(sizeof(CallArgument));
    if (output == NULL) RAISE(47)
    *output = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, false, false, false};
    output->_base._base._dtl = CallArgument__dtl;
    output->_base.is_output = true;
    output->_base.is_native = ((Argument*)(declaration->outputs->last->item))->is_native;
    output->_base.access = ((Argument*)(declaration->outputs->last->item))->access;
    SymbolExpression* _SymbolExpression25;
    CHECK(51, Expression_add_aux_variable(&(self->_base), ((Argument*)(declaration->outputs->last->item))->access, false, result_type, &(_SymbolExpression25)) )
    output->value = &(_SymbolExpression25->_base);
    self->output = output->value;
    CHECK(56, List_add(self->arguments->outputs, &(output->_base)) )
  }
  else {
    if (NULL != self->_base.result_type) {
      CHECK(58, FunctionArguments_get_output(self->arguments, &(self->output)) )
    }
  }
  self->_base.assignable =  NULL !=  self->_base.result_type;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallExpression_write_preactions(CallExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallExpression_write_preactions = "CallExpression.write-preactions";
#define MR_FUNC_NAME _func_name_CallExpression_write_preactions
Returncode CallExpression_write_preactions(CallExpression* self) {
  CHECK(62, (self->function)->_base._dtl[7](self->function) )
  if (self->is_function_object) {
    CHECK(64, write(&(String){5, 4, "if ("}) )
    CHECK(65, Expression_write_as_top(self->function) )
    CHECK(66, write(&(String){11, 10, " == NULL) "}) )
    CHECK(67, SyntaxTreeNode_write_raise(&(self->_base._base)) )
    CHECK(68, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  }
  CHECK(69, FunctionArguments_write_preactions(self->arguments) )
  if (!self->_base.is_statement) {
    CHECK(71, CallExpression_write_func_call(self) )
    CHECK(72, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallExpression_write(CallExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallExpression_write = "CallExpression.write";
#define MR_FUNC_NAME _func_name_CallExpression_write
Returncode CallExpression_write(CallExpression* self) {
  if (self->_base.is_statement) {
    CHECK(76, CallExpression_write_func_call(self) )
  }
  else {
    if (NULL != self->output) {
      CHECK(78, (self->output)->_base._dtl[3](self->output) )
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallExpression_write_func_call(CallExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallExpression_write_func_call = "CallExpression.write-func-call";
#define MR_FUNC_NAME _func_name_CallExpression_write_func_call
Returncode CallExpression_write_func_call(CallExpression* self) {
  CHECK(81, SyntaxTreeNode_write_call(&(self->_base._base)) )
  CHECK(82, (self->function)->_base._dtl[3](self->function) )
  CHECK(83, (self->arguments)->_base._dtl[4](self->arguments) )
  CHECK(84, write(&(String){4, 3, " )\n"}) )
  CHECK(85, FunctionArguments_write_postactions(self->arguments) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func CallExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func CallExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)CallExpression_analyze, (void*)CallExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)CallExpression_write_preactions};
#endif


/* Function argument call */
#if MR_STAGE == MR_TYPEDEFS
typedef struct CallArgument CallArgument;
#elif MR_STAGE == MR_TYPES(2)
struct CallArgument {
  Argument _base;
  Expression* value;
  SyntaxTreeCode* code_node;
  Bool is_down_cast;
  Bool is_dynamic;
  Bool is_generic;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgument_parse_value(CallArgument* self, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_parse_value = "CallArgument.parse-value";
#define MR_FUNC_NAME _func_name_CallArgument_parse_value
Returncode CallArgument_parse_value(CallArgument* self, SyntaxTreeCode* code_node, Char* end) {
  self->code_node = code_node;
  CHECK(98, parse_new_expression(&(String){3, 2, ",)"}, code_node, &(self->value), &((*end))) )
  if ((*end) != ',' && (*end) != ')') {
    CHECK(101, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){25, 24, "expected \",\" or \")\", got"}, (*end)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgument_analyze(CallArgument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_analyze = "CallArgument.analyze";
#define MR_FUNC_NAME _func_name_CallArgument_analyze
Returncode CallArgument_analyze(CallArgument* self) {
  CHECK(104, (self->value)->_base._dtl[2](self->value) )
  if (self->_base.is_output &&  ! self->value->assignable) {
    CHECK(106, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){27, 26, "non assignable call output"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgument_check_same_type_as(CallArgument* self, TypeInstance* type_instance, TypeInstance* instance_type, Int bases);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_check_same_type_as = "CallArgument.check-same-type-as";
#define MR_FUNC_NAME _func_name_CallArgument_check_same_type_as
Returncode CallArgument_check_same_type_as(CallArgument* self, TypeInstance* type_instance, TypeInstance* instance_type, Int bases) {
  if (self->_base.access == ACCESS_OWNER && self->value->access != ACCESS_OWNER) {
    if ((self->value->access) < 0 || (self->value->access) >= (glob->access_names)->length) RAISE(113)
    CHECK(113, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){43, 42, "assigning into an owner a non-owner access"}, (&(((String*)((glob->access_names)->values))[self->value->access]))) )
  }
  if (self->_base.is_output && self->_base.access != self->value->access) {
    if ((self->_base.access) < 0 || (self->_base.access) >= (glob->access_names)->length) RAISE(117)
    if ((self->value->access) < 0 || (self->value->access) >= (glob->access_names)->length) RAISE(117)
    CHECK(117, SyntaxTreeNode_m_syntax_error2(&(self->_base._base), &(String){22, 21, "assigning into access"}, (&(((String*)((glob->access_names)->values))[self->_base.access])), &(String){15, 14, "invalid access"}, (&(((String*)((glob->access_names)->values))[self->value->access]))) )
  }
  
  TypeInstance* real_type = NULL;
  CHECK(124, TypeInstance_f_new_replace_params(type_instance, instance_type, bases, &(real_type)) )
  if (self->_base.is_output) {
    Int _Int26;
    CHECK(127, TypeInstance_check_assign_to(real_type, self->value->result_type, &(self->_base._base), &(_Int26)) )
    self->is_down_cast = _Int26 > 0;
    self->is_generic = type_instance->type_data == &(glob->type_generic->_base);
  }
  else {
    CHECK(131, TypeInstance_check_assign_from(real_type, &(self->_base._base), &(self->value)) )
  }
  self->is_dynamic = real_type->type_data->is_dynamic;
  free(real_type);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgument_get_output(CallArgument* self, Expression** output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_get_output = "CallArgument.get-output";
#define MR_FUNC_NAME _func_name_CallArgument_get_output
Returncode CallArgument_get_output(CallArgument* self, Expression** output) {
  (*output) = self->value;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgument_write_preactions(CallArgument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_write_preactions = "CallArgument.write-preactions";
#define MR_FUNC_NAME _func_name_CallArgument_write_preactions
Returncode CallArgument_write_preactions(CallArgument* self) {
  CHECK(139, (self->value)->_base._dtl[7](self->value) )
  if (self->is_down_cast) {
    /* if (`value` != NULL) RAISE(`line-num`) */
    CHECK(142, write(&(String){5, 4, "if ("}) )
    CHECK(143, (self->value)->_base._dtl[3](self->value) )
    CHECK(144, write(&(String){11, 10, " != NULL) "}) )
    CHECK(145, SyntaxTreeNode_write_raise(&(self->_base._base)) )
    CHECK(146, SyntaxTreeCode_write_spaces(self->code_node) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgument_write(CallArgument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_write = "CallArgument.write";
#define MR_FUNC_NAME _func_name_CallArgument_write
Returncode CallArgument_write(CallArgument* self) {
  /* [&(]`value`[)][, [&(]`value`_Refman[)]][, [&(]`value`_Dynamic[)]] */
  if (self->_base.is_output) {
    if (self->is_down_cast || self->is_generic) {
      CHECK(152, write(&(String){8, 7, "(void*)"}) )
    }
    CHECK(153, write(&(String){3, 2, "&("}) )
  }
  CHECK(154, (self->value)->_base._dtl[3](self->value) )
  if (self->_base.is_output) {
    CHECK(156, write(&(String){2, 1, ")"}) )
  }
  
  if (!self->value->result_type->type_data->is_primitive &&  ! self->_base.is_native) {
    CHECK(159, write(&(String){3, 2, ", "}) )
    if (self->_base.is_output) {
      CHECK(161, write(&(String){3, 2, "&("}) )
    }
    CHECK(162, (self->value)->_base._dtl[5](self->value) )
    if (self->_base.is_output) {
      CHECK(164, write(&(String){2, 1, ")"}) )
    }
  }
  
  if (self->is_dynamic &&  ! self->_base.is_native) {
    CHECK(167, write(&(String){3, 2, ", "}) )
    if (self->_base.is_output) {
      if (self->is_down_cast) {
        CHECK(170, write(&(String){8, 7, "(void*)"}) )
      }
      CHECK(171, write(&(String){3, 2, "&("}) )
    }
    CHECK(172, (self->value)->_base._dtl[4](self->value) )
    if (self->_base.is_output) {
      CHECK(174, write(&(String){2, 1, ")"}) )
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgument_write_postactions(CallArgument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_write_postactions = "CallArgument.write-postactions";
#define MR_FUNC_NAME _func_name_CallArgument_write_postactions
Returncode CallArgument_write_postactions(CallArgument* self) {
  if (self->_base.access == ACCESS_OWNER &&  ! self->_base.is_output && self->value->result_type->type_data != &(glob->type_empty->_base)) {
    CHECK(179, SyntaxTreeCode_write_spaces(self->code_node) )
    CHECK(180, (self->value)->_base._dtl[3](self->value) )
    CHECK(181, write(&(String){10, 9, " = NULL;\n"}) )
    CHECK(182, SyntaxTreeCode_write_spaces(self->code_node) )
    CHECK(183, (self->value)->_base._dtl[5](self->value) )
    CHECK(184, write(&(String){10, 9, " = NULL;\n"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func CallArgument__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func CallArgument__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)CallArgument_analyze, (void*)CallArgument_write, (void*)Argument_copy_new, (void*)CallArgument_parse_value, (void*)Argument_get_type_instance, (void*)CallArgument_check_same_type_as, (void*)Argument_get_variable, (void*)CallArgument_get_output, (void*)CallArgument_write_preactions, (void*)CallArgument_write_postactions};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct CallArgumentFactory CallArgumentFactory;
#elif MR_STAGE == MR_TYPES(1)
struct CallArgumentFactory {
  ArgumentFactory _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgumentFactory_m_new_argument(CallArgumentFactory* self, Argument** new_argument);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgumentFactory_m_new_argument = "CallArgumentFactory.m-new-argument";
#define MR_FUNC_NAME _func_name_CallArgumentFactory_m_new_argument
Returncode CallArgumentFactory_m_new_argument(CallArgumentFactory* self, Argument** new_argument) {
  CallArgument* _CallArgument27 = malloc(sizeof(CallArgument));
  if (_CallArgument27 == NULL) RAISE(189)
  *_CallArgument27 = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, false, false, false};
  _CallArgument27->_base._base._dtl = CallArgument__dtl;
  (*new_argument) = &(_CallArgument27->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func CallArgumentFactory__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func CallArgumentFactory__dtl[] = {(void*)CallArgumentFactory_m_new_argument};
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
