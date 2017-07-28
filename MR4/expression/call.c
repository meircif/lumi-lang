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
typedef struct CallExpression CallExpression;
#elif MR_STAGE == MR_TYPES(1)
struct CallExpression {
  Expression _base;
  Expression* function;
  CallArguments* arguments;
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
  self->arguments = malloc(sizeof(CallArguments));
  if (self->arguments == NULL) RAISE(16)
  *self->arguments = (CallArguments){NULL, NULL};
  CHECK(17, CallArguments_parse(self->arguments, &((*end))) )
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
  CHECK(20, (self->function)->_dtl[0](self->function) )
  CHECK(21, CallArguments_write(self->arguments) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func CallExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func CallExpression__dtl[] = {CallExpression_write};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct CallArguments CallArguments;
#elif MR_STAGE == MR_TYPES(0)
struct CallArguments {
  CallArgument* parameters;
  CallArgument* outputs;
/* parsing `(access value, ...):(access value, ...)` *//* parsing single argument list `(access value, ...)` *//* write arguments starting from `first` */};
#endif/* parsing `(access value, ...):(access value, ...)` */
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArguments_parse(CallArguments* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArguments_parse = "CallArguments.parse";
#define MR_FUNC_NAME _func_name_CallArguments_parse
Returncode CallArguments_parse(CallArguments* self, Char* end) {
  CHECK(30, CallArguments_parse_args(self, &(self->parameters), &((*end))) )
  if ((*end) == '-') {
    CHECK(32, read_expect(&(String){3, 2, ">("}) )
    CHECK(33, CallArguments_parse_args(self, &(self->outputs), &((*end))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing single argument list `(access value, ...)` */
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArguments_parse_args(CallArguments* self, CallArgument** first, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArguments_parse_args = "CallArguments.parse-args";
#define MR_FUNC_NAME _func_name_CallArguments_parse_args
Returncode CallArguments_parse_args(CallArguments* self, CallArgument** first, Char* end) {
  CallArgument* arg = NULL;
  String* access_str = &(String){16, 0, (char[16]){0}};
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
        arg->next = malloc(sizeof(CallArgument));
        if (arg->next == NULL) RAISE(50)
        *arg->next = (CallArgument){0, NULL, NULL};
        arg = arg->next;
      }
      else {
        (*first) = malloc(sizeof(CallArgument));
        if ((*first) == NULL) RAISE(53)
        *(*first) = (CallArgument){0, NULL, NULL};
        arg = (*first);
      }
      CHECK(55, CallArgument_parse(arg, access_str, &((*end))) )
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
Returncode CallArguments_write(CallArguments* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArguments_write = "CallArguments.write";
#define MR_FUNC_NAME _func_name_CallArguments_write
Returncode CallArguments_write(CallArguments* self) {
  CHECK(66, write(&(String){2, 1, "("}) )
  if (NULL != self->parameters) {
    CHECK(68, CallArguments_write_args(self, self->parameters) )
  }
  if (NULL != self->outputs) {
    CHECK(70, write(&(String){5, 4, ")->("}) )
    CHECK(71, CallArguments_write_args(self, self->outputs) )
  }
  CHECK(72, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif/* write arguments starting from `first` */
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArguments_write_args(CallArguments* self, CallArgument* first);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArguments_write_args = "CallArguments.write-args";
#define MR_FUNC_NAME _func_name_CallArguments_write_args
Returncode CallArguments_write_args(CallArguments* self, CallArgument* first) {
  CallArgument* arg = first;
  while (true) {
    CHECK(78, CallArgument_write(arg) )
    arg = arg->next;
    if (!(NULL != arg)) break;
    CHECK(81, write(&(String){3, 2, ", "}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct CallArgument CallArgument;
#elif MR_STAGE == MR_TYPES(0)
struct CallArgument {
  Int access;
  Expression* value;
  CallArgument* next;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode CallArgument_parse(CallArgument* self, String* access_str, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_parse = "CallArgument.parse";
#define MR_FUNC_NAME _func_name_CallArgument_parse
Returncode CallArgument_parse(CallArgument* self, String* access_str, Char* end) {
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
Returncode CallArgument_write(CallArgument* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_CallArgument_write = "CallArgument.write";
#define MR_FUNC_NAME _func_name_CallArgument_write
Returncode CallArgument_write(CallArgument* self) {
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
