#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/call.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file6_name = "expression/call.3.mr";
#endif
#define MR_FILE_NAME _mr_file6_name

/* MR4 compiler - Call expression */

/* Function call expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Call_expression Call_expression;
#elif MR_STAGE == MR_TYPES(1)
struct Call_expression {
  Expression _base;
  Expression* function;
  Function_arguments* arguments;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Call_expression_parse_new(Call_expression* self, String* ends, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Call_expression_parse_new = "Call-expression.parse-new";
#define MR_FUNC_NAME _func_name_Call_expression_parse_new
Returncode Call_expression_parse_new(Call_expression* self, String* ends, Expression** expression, Char* end) {
  Call_expression* call_expression = malloc(sizeof(Call_expression));
  if (call_expression == NULL) RAISE(10)
  *call_expression = (Call_expression){Call_expression__dtl, NULL, NULL, NULL};
  call_expression->_base._dtl = Call_expression__dtl;
  CHECK(11, Call_expression_parse(call_expression, (*expression), &((*end))) )
  (*expression) = &(call_expression->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Call_expression_parse(Call_expression* self, Expression* function, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Call_expression_parse = "Call-expression.parse";
#define MR_FUNC_NAME _func_name_Call_expression_parse
Returncode Call_expression_parse(Call_expression* self, Expression* function, Char* end) {
  self->function = function;
  self->arguments = malloc(sizeof(Function_arguments));
  if (self->arguments == NULL) RAISE(16)
  *self->arguments = (Function_arguments){NULL, NULL};
  CHECK(17, Function_arguments_parse(self->arguments, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Call_expression_write(Call_expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Call_expression_write = "Call-expression.write";
#define MR_FUNC_NAME _func_name_Call_expression_write
Returncode Call_expression_write(Call_expression* self) {
  CHECK(20, (self->function)->_dtl[0](self->function) )
  CHECK(21, Function_arguments_write(self->arguments) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Call_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Call_expression__dtl[] = {Call_expression_write};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct Function_arguments Function_arguments;
#elif MR_STAGE == MR_TYPES(0)
struct Function_arguments {
  String* parameters;
  String* outputs;
/* parsing `(parameters):(outputs)` */};
#endif/* parsing `(parameters):(outputs)` */
#if MR_STAGE == MR_DECLARATIONS
Returncode Function_arguments_parse(Function_arguments* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Function_arguments_parse = "Function-arguments.parse";
#define MR_FUNC_NAME _func_name_Function_arguments_parse
Returncode Function_arguments_parse(Function_arguments* self, Char* end) {
  Char _Char7;
  CHECK(30, read_new(&(String){2, 1, ")"}, &(self->parameters), &(_Char7)) )
  CHECK(31, read_c(&((*end))) )
  if ((*end) == ':') {
    CHECK(33, read_expect(&(String){2, 1, "("}) )
    Char _Char8;
    CHECK(34, read_new(&(String){2, 1, ")"}, &(self->outputs), &(_Char8)) )
    CHECK(35, read_c(&((*end))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Function_arguments_write(Function_arguments* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Function_arguments_write = "Function-arguments.write";
#define MR_FUNC_NAME _func_name_Function_arguments_write
Returncode Function_arguments_write(Function_arguments* self) {
  CHECK(38, write(&(String){2, 1, "("}) )
  CHECK(39, write(self->parameters) )
  CHECK(40, write(&(String){2, 1, ")"}) )
  if (NULL != self->outputs) {
    CHECK(42, write(&(String){3, 2, ":("}) )
    CHECK(43, write(self->outputs) )
    CHECK(44, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/map.c"
#include "global/type.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/variable.c"
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
#endif
#undef MR_INCLUDES
#endif

#endif
