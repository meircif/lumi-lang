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
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallExpression_parse_new(CallExpression* self, String* ends, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallExpression_parse_new = "CallExpression.parse-new";
#define MR_FUNC_NAME _func_name_CallExpression_parse_new
Returncode CallExpression_parse_new(CallExpression* self, String* ends, Expression** expression, Char* end) {
  CallExpression* call_expression = malloc(sizeof(CallExpression));
  if (call_expression == NULL) RAISE(10)
  *call_expression = (CallExpression){CallExpression__dtl, NULL, NULL, NULL};
  call_expression->_base._dtl = CallExpression__dtl;
  CHECK(11, CallExpression_parse(call_expression, (*expression), &((*end))) )
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
  if (self->arguments == NULL) RAISE(16)
  *self->arguments = (FunctionArguments){NULL, NULL};
  CallArgumentFactory* argument_factory = &(CallArgumentFactory){CallArgumentFactory__dtl};
  argument_factory->_base._dtl = CallArgumentFactory__dtl;
  CHECK(18, FunctionArguments_parse(self->arguments, &(argument_factory->_base), &((*end))) )
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
  CHECK(21, (self->function)->_dtl[0](self->function) )
  CHECK(22, FunctionArguments_write(self->arguments) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func CallExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func CallExpression__dtl[] = {(void*)CallExpression_write};
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
Returncode CallArgument_parse_value(CallArgument* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_parse_value = "CallArgument.parse-value";
#define MR_FUNC_NAME _func_name_CallArgument_parse_value
Returncode CallArgument_parse_value(CallArgument* self, Char* end) {
  CHECK(30, parse_new_expression(&(String){3, 2, ",)"}, &(self->value), &((*end))) )
  if ((*end) != ',' && (*end) != ')') {
    CHECK(32, f_syntax_error_c(&(String){25, 24, "expected \",\" or \")\", got"}, (*end)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgument_write_value(CallArgument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_write_value = "CallArgument.write-value";
#define MR_FUNC_NAME _func_name_CallArgument_write_value
Returncode CallArgument_write_value(CallArgument* self) {
  CHECK(35, (self->value)->_dtl[0](self->value) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func CallArgument__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func CallArgument__dtl[] = {(void*)CallArgument_parse_value, (void*)CallArgument_write_value};
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
  CallArgument* _CallArgument12 = malloc(sizeof(CallArgument));
  if (_CallArgument12 == NULL) RAISE(40)
  *_CallArgument12 = (CallArgument){CallArgument__dtl, 0, NULL};
  _CallArgument12->_base._dtl = CallArgument__dtl;
  (*new_argument) = &(_CallArgument12->_base);
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
#include "expression/variable.c"
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
