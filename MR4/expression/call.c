#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/call.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file7_name = "expression/call.3.mr";
#endif
#define MR_FILE_NAME _mr_file7_name

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
  *call_expression = (CallExpression){CallExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL, NULL, NULL, false};
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
  CHECK(23, FunctionArguments_parse(self->arguments, &(argument_factory->_base), code_node, &((*end))) )
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
  CHECK(26, (self->function)->_base._dtl[1](self->function) )
  CHECK(27, (self->arguments)->_base._dtl[1](self->arguments) )
  if (!(NULL != self->function->result_type)) {
    CHECK(29, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){32, 31, "void expression is not callable"}) )
  }
  if (self->function->result_type->type_data != &(glob->type_func->_base)) {
    CHECK(31, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){18, 17, "non callable type"}, self->function->result_type->type_data->name) )
  }
  FunctionArguments* declaration = self->function->result_type->arguments;
  if (!self->_base.is_statement) {
    TypeInstance* _TypeInstance12;
    CHECK(36, FunctionArguments_get_result_type(declaration, &(_TypeInstance12)) )
    CHECK(36, TypeInstance_copy_new(_TypeInstance12, &(self->_base.result_type)) )
  }
  CHECK(37, (self->function)->_base._dtl[5](self->function, self->arguments, &(self->is_function_object)) )
  Bool _Bool13;
  CHECK(39, FunctionArguments_check_same_as(self->arguments, declaration, &(_Bool13)) )
  if (_Bool13) {
    /* add omitted output */
    CallArgument* output = malloc(sizeof(CallArgument));
    if (output == NULL) RAISE(41)
    *output = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, NULL, NULL, false, false};
    output->_base._base._dtl = CallArgument__dtl;
    output->_base.is_output = true;
    output->_base.access = ((Argument*)(declaration->outputs->last->item))->access;
    TypeInstance* _TypeInstance14;
    CHECK(44, FunctionArguments_get_result_type(declaration, &(_TypeInstance14)) )
    SymbolExpression* _SymbolExpression15;
    CHECK(44, Expression_add_aux_variable(&(self->_base), ((Argument*)(declaration->outputs->last->item))->access, _TypeInstance14, &(_SymbolExpression15)) )
    output->value = &(_SymbolExpression15->_base);
    self->output = output->value;
    CHECK(48, List_add(self->arguments->outputs, &(output->_base)) )
  }
  else {
    if (NULL != self->_base.result_type) {
      CHECK(50, FunctionArguments_get_output(self->arguments, &(self->output)) )
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
  CHECK(54, (self->function)->_base._dtl[6](self->function) )
  if (self->is_function_object) {
    CHECK(56, write(&(String){5, 4, "if ("}) )
    CHECK(57, Expression_write_as_top(self->function) )
    CHECK(58, write(&(String){11, 10, " == NULL) "}) )
    CHECK(59, SyntaxTreeNode_write_raise(&(self->_base._base)) )
    CHECK(60, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  }
  CHECK(61, FunctionArguments_write_preactions(self->arguments) )
  if (!self->_base.is_statement) {
    CHECK(63, CallExpression_write_func_call(self) )
    CHECK(64, SyntaxTreeCode_write_spaces(self->_base.code_node) )
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
    CHECK(68, CallExpression_write_func_call(self) )
  }
  else {
    if (NULL != self->output) {
      CHECK(70, (self->output)->_base._dtl[2](self->output) )
    }
    else {
      RAISE(72)
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
  CHECK(75, SyntaxTreeNode_write_call(&(self->_base._base)) )
  CHECK(76, (self->function)->_base._dtl[2](self->function) )
  CHECK(77, (self->arguments)->_base._dtl[3](self->arguments) )
  CHECK(78, write(&(String){4, 3, " )\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func CallExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func CallExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)CallExpression_analyze, (void*)CallExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)CallExpression_write_preactions};
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
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgument_parse_value(CallArgument* self, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_parse_value = "CallArgument.parse-value";
#define MR_FUNC_NAME _func_name_CallArgument_parse_value
Returncode CallArgument_parse_value(CallArgument* self, SyntaxTreeCode* code_node, Char* end) {
  self->code_node = code_node;
  CHECK(91, parse_new_expression(&(String){3, 2, ",)"}, code_node, &(self->value), &((*end))) )
  if ((*end) != ',' && (*end) != ')') {
    CHECK(94, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){25, 24, "expected \",\" or \")\", got"}, (*end)) )
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
  CHECK(97, (self->value)->_base._dtl[1](self->value) )
  if (self->_base.is_output &&  ! self->value->assignable) {
    CHECK(99, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){27, 26, "non assignable call output"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgument_check_same_type_as(CallArgument* self, TypeInstance* type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_check_same_type_as = "CallArgument.check-same-type-as";
#define MR_FUNC_NAME _func_name_CallArgument_check_same_type_as
Returncode CallArgument_check_same_type_as(CallArgument* self, TypeInstance* type_instance) {
  if (self->_base.is_output) {
    Int _Int16;
    CHECK(103, TypeInstance_check_assign_to(type_instance, self->value->result_type, &(self->_base._base), &(_Int16)) )
    self->is_down_cast = _Int16 > 0;
  }
  else {
    CHECK(106, TypeInstance_check_assign_from(type_instance, &(self->_base._base), &(self->value)) )
  }
  self->is_dynamic = type_instance->type_data->is_dynamic;
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
  CHECK(113, (self->value)->_base._dtl[6](self->value) )
  if (self->is_down_cast) {
    /* if (`value` != NULL) RAISE(`line-num`) */
    CHECK(116, write(&(String){5, 4, "if ("}) )
    CHECK(117, (self->value)->_base._dtl[2](self->value) )
    CHECK(118, write(&(String){11, 10, " != NULL) "}) )
    CHECK(119, SyntaxTreeNode_write_raise(&(self->_base._base)) )
    CHECK(120, SyntaxTreeCode_write_spaces(self->code_node) )
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
    if (self->is_down_cast) {
      CHECK(126, write(&(String){8, 7, "(void*)"}) )
    }
    CHECK(127, write(&(String){3, 2, "&("}) )
  }
  CHECK(128, (self->value)->_base._dtl[2](self->value) )
  if (self->_base.is_output) {
    CHECK(130, write(&(String){2, 1, ")"}) )
  }
  
  if (!self->value->result_type->type_data->is_primitive) {
    CHECK(133, write(&(String){3, 2, ", "}) )
    if (self->_base.is_output) {
      CHECK(135, write(&(String){3, 2, "&("}) )
    }
    CHECK(136, (self->value)->_base._dtl[4](self->value) )
    if (self->_base.is_output) {
      CHECK(138, write(&(String){2, 1, ")"}) )
    }
  }
  
  if (self->is_dynamic) {
    CHECK(141, write(&(String){3, 2, ", "}) )
    if (self->_base.is_output) {
      if (self->is_down_cast) {
        CHECK(144, write(&(String){8, 7, "(void*)"}) )
      }
      CHECK(145, write(&(String){3, 2, "&("}) )
    }
    CHECK(146, (self->value)->_base._dtl[3](self->value) )
    if (self->_base.is_output) {
      CHECK(148, write(&(String){2, 1, ")"}) )
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func CallArgument__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func CallArgument__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)CallArgument_analyze, (void*)CallArgument_write, (void*)Argument_copy_new, (void*)CallArgument_parse_value, (void*)Argument_get_type_instance, (void*)CallArgument_check_same_type_as, (void*)Argument_get_variable, (void*)CallArgument_get_output, (void*)CallArgument_write_preactions};
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
  CallArgument* _CallArgument17 = malloc(sizeof(CallArgument));
  if (_CallArgument17 == NULL) RAISE(153)
  *_CallArgument17 = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, NULL, NULL, false, false};
  _CallArgument17->_base._base._dtl = CallArgument__dtl;
  (*new_argument) = &(_CallArgument17->_base);
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
