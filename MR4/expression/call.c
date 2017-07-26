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
  Call_arguments* arguments;
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
  self->arguments = malloc(sizeof(Call_arguments));
  if (self->arguments == NULL) RAISE(16)
  *self->arguments = (Call_arguments){NULL, NULL};
  CHECK(17, Call_arguments_parse(self->arguments, &((*end))) )
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
  CHECK(21, Call_arguments_write(self->arguments) )
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
typedef struct Call_arguments Call_arguments;
#elif MR_STAGE == MR_TYPES(0)
struct Call_arguments {
  Call_argument* parameters;
  Call_argument* outputs;
/* parsing `(access value, ...):(access value, ...)` *//* parsing single argument list `(access value, ...)` *//* write arguments starting from `first` */};
#endif/* parsing `(access value, ...):(access value, ...)` */
#if MR_STAGE == MR_DECLARATIONS
Returncode Call_arguments_parse(Call_arguments* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Call_arguments_parse = "Call-arguments.parse";
#define MR_FUNC_NAME _func_name_Call_arguments_parse
Returncode Call_arguments_parse(Call_arguments* self, Char* end) {
  CHECK(30, Call_arguments_parse_args(self, &(self->parameters), &((*end))) )
  if ((*end) == ':') {
    CHECK(32, read_expect(&(String){2, 1, "("}) )
    CHECK(33, Call_arguments_parse_args(self, &(self->outputs), &((*end))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing single argument list `(access value, ...)` */
#if MR_STAGE == MR_DECLARATIONS
Returncode Call_arguments_parse_args(Call_arguments* self, Call_argument** first, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Call_arguments_parse_args = "Call-arguments.parse-args";
#define MR_FUNC_NAME _func_name_Call_arguments_parse_args
Returncode Call_arguments_parse_args(Call_arguments* self, Call_argument** first, Char* end) {
  Call_argument* arg = NULL;
  String* access_str = &(String){128, 0, (char[128]){0}};
  Int _Int11;
  CHECK(39, read_until(access_str, &(String){3, 2, " )"}, false, &((*end)), &(_Int11)) )
  if ((*end) == '\n' && access_str->length == 0) {
    CHECK(41, read_line_break_spaces() )
    Int _Int12;
    CHECK(42, read_until(access_str, &(String){2, 1, " "}, false, &((*end)), &(_Int12)) )
  }
  if ((*end) != ')' || access_str->length > 0) {
    while (true) {
      if (access_str->length == 0) {
        CHECK(46, f_syntax_error_c(&(String){21, 20, "expected access, got"}, (*end)) )
      }
      if ((*end) != ' ') {
        CHECK(48, f_syntax_error_c(&(String){20, 19, "expected space, got"}, (*end)) )
      }
      if (NULL != arg) {
        arg->next = malloc(sizeof(Call_argument));
        if (arg->next == NULL) RAISE(50)
        *arg->next = (Call_argument){0, NULL, NULL};
        arg = arg->next;
      }
      else {
        (*first) = malloc(sizeof(Call_argument));
        if ((*first) == NULL) RAISE(53)
        *(*first) = (Call_argument){0, NULL, NULL};
        arg = (*first);
      }
      CHECK(55, Call_argument_parse(arg, access_str, &((*end))) )
      if (!((*end) == ',')) break;
      CHECK(57, read_c(&((*end))) )
      if ((*end) == '\n') {
        CHECK(59, read_line_break_spaces() )
      }
      else {
        if ((*end) != ' ') {
          CHECK(61, f_syntax_error_c(&(String){32, 31, "expected space or new-line, got"}, (*end)) )
        }
      }
      Int _Int13;
      CHECK(62, read_until(access_str, &(String){2, 1, " "}, false, &((*end)), &(_Int13)) )
    }
  }
  CHECK(63, read_c(&((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Call_arguments_write(Call_arguments* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Call_arguments_write = "Call-arguments.write";
#define MR_FUNC_NAME _func_name_Call_arguments_write
Returncode Call_arguments_write(Call_arguments* self) {
  CHECK(66, write(&(String){2, 1, "("}) )
  if (NULL != self->parameters) {
    CHECK(68, Call_arguments_write_args(self, self->parameters) )
  }
  if (NULL != self->outputs) {
    CHECK(70, write(&(String){4, 3, "):("}) )
    CHECK(71, Call_arguments_write_args(self, self->outputs) )
  }
  CHECK(72, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif/* write arguments starting from `first` */
#if MR_STAGE == MR_DECLARATIONS
Returncode Call_arguments_write_args(Call_arguments* self, Call_argument* first);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Call_arguments_write_args = "Call-arguments.write-args";
#define MR_FUNC_NAME _func_name_Call_arguments_write_args
Returncode Call_arguments_write_args(Call_arguments* self, Call_argument* first) {
  Call_argument* arg = first;
  while (true) {
    CHECK(78, Call_argument_write(arg) )
    arg = arg->next;
    if (!(NULL != arg)) break;
    CHECK(81, write(&(String){3, 2, ", "}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct Call_argument Call_argument;
#elif MR_STAGE == MR_TYPES(0)
struct Call_argument {
  Int access;
  Expression* value;
  Call_argument* next;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Call_argument_parse(Call_argument* self, String* access_str, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Call_argument_parse = "Call-argument.parse";
#define MR_FUNC_NAME _func_name_Call_argument_parse
Returncode Call_argument_parse(Call_argument* self, String* access_str, Char* end) {
  CHECK(90, get_access(access_str, &(self->access)) )
  CHECK(91, parse_new_expression(&(String){3, 2, ",)"}, &(self->value), &((*end))) )
  if ((*end) != ',' && (*end) != ')') {
    CHECK(93, f_syntax_error_c(&(String){25, 24, "expected \",\" or \")\", got"}, (*end)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Call_argument_write(Call_argument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Call_argument_write = "Call-argument.write";
#define MR_FUNC_NAME _func_name_Call_argument_write
Returncode Call_argument_write(Call_argument* self) {
  CHECK(96, write(&(String){8, 7, "Access("}) )
  CHECK(97, write_int(self->access) )
  CHECK(98, write(&(String){3, 2, ") "}) )
  CHECK(99, (self->value)->_dtl[0](self->value) )
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
