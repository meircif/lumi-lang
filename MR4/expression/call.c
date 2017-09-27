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
#elif MR_STAGE == MR_TYPES(1)
struct CallExpression {
  Expression _base;
  Expression* function;
  FunctionArguments* arguments;
  Expression* output;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallExpression_parse_new(CallExpression* self, String* ends, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallExpression_parse_new = "CallExpression.parse-new";
#define MR_FUNC_NAME _func_name_CallExpression_parse_new
Returncode CallExpression_parse_new(CallExpression* self, String* ends, Expression** expression, Char* end) {
  CallExpression* call_expression = malloc(sizeof(CallExpression));
  if (call_expression == NULL) RAISE(11)
  *call_expression = (CallExpression){CallExpression__dtl, NULL, NULL, false, NULL, NULL, NULL};
  call_expression->_base._dtl = CallExpression__dtl;
  CHECK(12, CallExpression_parse(call_expression, (*expression), &((*end))) )
  (*expression) = &(call_expression->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallExpression_parse(CallExpression* self, Expression* function, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallExpression_parse = "CallExpression.parse";
#define MR_FUNC_NAME _func_name_CallExpression_parse
Returncode CallExpression_parse(CallExpression* self, Expression* function, Char* end) {
  self->function = function;
  self->arguments = malloc(sizeof(FunctionArguments));
  if (self->arguments == NULL) RAISE(17)
  *self->arguments = (FunctionArguments){NULL, NULL};
  CallArgumentFactory* argument_factory = &(CallArgumentFactory){CallArgumentFactory__dtl};
  argument_factory->_base._dtl = CallArgumentFactory__dtl;
  CHECK(19, FunctionArguments_parse(self->arguments, &(argument_factory->_base), self->_base.code_node, NULL, &((*end))) )
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
  CHECK(23, (self->function)->_dtl[0](self->function) )
  CHECK(24, FunctionArguments_analyze(self->arguments) )
  /* TODO add self... */
  FunctionArguments* declaration = self->function->result_type->arguments;
  if (!(NULL != self->function->result_type->type_data)) {
    CHECK(28, f_syntax_error_msg(&(String){32, 31, "void expression is not callable"}) )
  }
  if (self->function->result_type->type_data != glob->type_func ||  ! (NULL != declaration)) {
    CHECK(31, f_syntax_error(&(String){18, 17, "non callable type"}, self->function->result_type->type_data->name) )
  }
  TypeInstance* _TypeInstance11;
  CHECK(34, FunctionArguments_get_result_type(declaration, &(_TypeInstance11)) )
  CHECK(34, TypeInstance_m_copy_new(_TypeInstance11, &(self->_base.result_type)) )
  Bool _Bool12;
  CHECK(35, FunctionArguments_m_check_calling(self->arguments, declaration, &(_Bool12)) )
  if (_Bool12) {
    /* add omitted output */
    SymbolExpression* symbol = malloc(sizeof(SymbolExpression));
    if (symbol == NULL) RAISE(37)
    *symbol = (SymbolExpression){SymbolExpression__dtl, NULL, NULL, false, NULL, NULL, NULL};
    symbol->_base._base._dtl = SymbolExpression__dtl;
    symbol->_base._base.code_node = self->_base.code_node;
    CHECK(39, TypeInstance_m_copy_new(self->_base.result_type, &(symbol->_base._base.result_type)) )
    symbol->_base._base.assignable = true;
    CHECK(41, SyntaxTreeBlock_add_aux_variable(self->_base.code_node->parent, ((Argument*)(declaration->outputs->last->item))->access, self->_base.result_type, &(symbol->variable)) )
    CHECK(45, string_new_copy(symbol->variable->name, &(symbol->_base.text)) )
    self->output = &(symbol->_base._base);
    CallArgument* output = malloc(sizeof(CallArgument));
    if (output == NULL) RAISE(47)
    *output = (CallArgument){CallArgument__dtl, 0, NULL};
    output->_base._dtl = CallArgument__dtl;
    output->_base.access = ((Argument*)(declaration->outputs->last->item))->access;
    output->value = &(symbol->_base._base);
    CHECK(50, List_add(self->arguments->outputs, &(output->_base)) )
  }
  else {
    if (NULL != self->_base.result_type->type_data) {
      CHECK(52, FunctionArguments_get_output(declaration, &(self->output)) )
    }
  }
  self->_base.assignable =  NULL !=  self->_base.result_type->type_data;
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
  CHECK(56, (self->function)->_dtl[1](self->function) )
  CHECK(57, FunctionArguments_write(self->arguments, false) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func CallExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func CallExpression__dtl[] = {(void*)CallExpression_analyze, (void*)CallExpression_write};
#endif


/* Function argument call */
#if MR_STAGE == MR_TYPEDEFS
typedef struct CallArgument CallArgument;
#elif MR_STAGE == MR_TYPES(1)
struct CallArgument {
  Argument _base;
  Expression* value;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgument_parse_value(CallArgument* self, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_parse_value = "CallArgument.parse-value";
#define MR_FUNC_NAME _func_name_CallArgument_parse_value
Returncode CallArgument_parse_value(CallArgument* self, SyntaxTreeCode* code_node, Char* end) {
  CHECK(65, parse_new_expression(&(String){3, 2, ",)"}, code_node, &(self->value), &((*end))) )
  if ((*end) != ',' && (*end) != ')') {
    CHECK(68, f_syntax_error_c(&(String){25, 24, "expected \",\" or \")\", got"}, (*end)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgument_analyze(CallArgument* self, Bool is_output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_analyze = "CallArgument.analyze";
#define MR_FUNC_NAME _func_name_CallArgument_analyze
Returncode CallArgument_analyze(CallArgument* self, Bool is_output) {
  CHECK(71, (self->value)->_dtl[0](self->value) )
  if (is_output &&  ! self->value->assignable) {
    CHECK(73, f_syntax_error_msg(&(String){27, 26, "non assignable call output"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgument_get_type_instance(CallArgument* self, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_get_type_instance = "CallArgument.get-type-instance";
#define MR_FUNC_NAME _func_name_CallArgument_get_type_instance
Returncode CallArgument_get_type_instance(CallArgument* self, TypeInstance** type_instance) {
  (*type_instance) = self->value->result_type;
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
Returncode CallArgument_write(CallArgument* self, Bool is_output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_write = "CallArgument.write";
#define MR_FUNC_NAME _func_name_CallArgument_write
Returncode CallArgument_write(CallArgument* self, Bool is_output) {
  /* &(`value`) */
  if (is_output) {
    CHECK(84, write(&(String){3, 2, "&("}) )
  }
  CHECK(85, (self->value)->_dtl[1](self->value) )
  if (is_output) {
    CHECK(87, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func CallArgument__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func CallArgument__dtl[] = {(void*)Argument_m_copy_new, (void*)CallArgument_parse_value, (void*)CallArgument_analyze, (void*)CallArgument_get_type_instance, (void*)CallArgument_get_output, (void*)CallArgument_write};
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
  CallArgument* _CallArgument13 = malloc(sizeof(CallArgument));
  if (_CallArgument13 == NULL) RAISE(92)
  *_CallArgument13 = (CallArgument){CallArgument__dtl, 0, NULL};
  _CallArgument13->_base._dtl = CallArgument__dtl;
  (*new_argument) = &(_CallArgument13->_base);
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
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "global/type.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/symbol.c"
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
