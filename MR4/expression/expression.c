#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/expression.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file9_name = "expression/expression.3.mr";
#endif
#define MR_FILE_NAME _mr_file9_name

/*  MR4 compiler - Expression

Expression is a basic class for all expression types.
For each part of an expression (variable, constant, function call, etc..) there
is a class that expends the basic expression type and handles its unique logic.
From a complex expression an expression tree is generated, with types such
operators and slices that contain sub-expression inside.

For example, `array[4] + 3` expression is parsed as:
Binary-expression:
  operator: +
  left: Slice-expression:
    sequence: Variable-expression(array)
    index: Int-expression(4)
  right: Int-expression(3)
 */

/* Return in `expression` a new allocated expression parsed from the input */
/* file until one of the characters in `ends` is reached. */
/* Return the end character in `end` */
#if MR_STAGE == MR_DECLARATIONS
Returncode parse_new_expression(String* ends, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_parse_new_expression = "parse-new-expression";
#define MR_FUNC_NAME _func_name_parse_new_expression
Returncode parse_new_expression(String* ends, Expression** expression, Char* end) {
  CHECK(23, Expression_parse_new(NULL, ends, &((*expression)), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Meta type for an expression in the language. */
/* Currently only the parsing is fully implemented, `write` is implemented only */
/* for testing. */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Expression Expression;
#elif MR_STAGE == MR_TYPES(0)
struct Expression {
  Func* _dtl;
  Type_instance* result_type;
/* Parse any expression *//* Read a single expression value as new string *//* Parse an expression with an operator *//* Parse an expression that is an operand *//* Parse the initialize part of an operand expression *//* Parse one following part of an operand *//* Set type instance to be a type that has no sub-type *//* write to C - currently inly used in testing */};
#endif/* Parse any expression */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_parse_new(Expression* self, String* ends, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_parse_new = "Expression.parse-new";
#define MR_FUNC_NAME _func_name_Expression_parse_new
Returncode Expression_parse_new(Expression* self, String* ends, Expression** expression, Char* end) {
  (*expression) = NULL;
  Bool _Bool18;
  CHECK(36, String_has(ends, ' ', &(_Bool18)) )
  Bool multi_operands = !_Bool18;
  while (true) {
    String* text = NULL;
    CHECK(39, Expression_read_new_value(self, ends, &(text), &((*end))) )
    
    Operator* operator = NULL;
    CHECK(42, Name_map_find(glob->operator_map, text, (void**)&(operator)) )
    if (NULL != operator) {
      if (!multi_operands) {
        CHECK(45, f_syntax_error(&(String){20, 19, "unexpected operator"}, operator->name) )
      }
      CHECK(46, Expression_parse_new_operator(self, operator, multi_operands, ends, &((*expression)), &((*end))) )
    }
    else {
      if (NULL != (*expression)) {
        CHECK(50, f_syntax_error(&(String){17, 16, "unknown operator"}, text) )
      }
      CHECK(51, Expression_parse_new_operand(self, text, ends, &((*expression)), &((*end))) )
    }
    
    if (!(multi_operands && (*end) == ' ')) break;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Read a single expression value as new string */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_read_new_value(Expression* self, String* ends, String** text, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_read_new_value = "Expression.read-new-value";
#define MR_FUNC_NAME _func_name_Expression_read_new_value
Returncode Expression_read_new_value(Expression* self, String* ends, String** text, Char* end) {
  String* all_ends = NULL;
  CHECK(59, f_new_concat(&(String){6, 5, " .[(?"}, ends, &(all_ends)) )
  CHECK(60, read_new(all_ends, &((*text)), &((*end))) )
  free(all_ends);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Parse an expression with an operator */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_parse_new_operator(Expression* self, Operator* operator, Bool multi_operands, String* ends, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_parse_new_operator = "Expression.parse-new-operator";
#define MR_FUNC_NAME _func_name_Expression_parse_new_operator
Returncode Expression_parse_new_operator(Expression* self, Operator* operator, Bool multi_operands, String* ends, Expression** expression, Char* end) {
  if (((*end) != ' ' && (*end) != '\n')) {
    CHECK(68, f_syntax_error_c(&(String){11, 10, "unexpected"}, (*end)) )
  }
  if (NULL != (*expression)) {
    CHECK(70, Binary_expression_parse_new(NULL, ends, operator, &((*expression)), &((*end))) )
  }
  else {
    CHECK(73, Unary_expression_parse_new(NULL, ends, operator, &((*expression)), &((*end))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Parse an expression that is an operand */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_parse_new_operand(Expression* self, String* text, String* ends, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_parse_new_operand = "Expression.parse-new-operand";
#define MR_FUNC_NAME _func_name_Expression_parse_new_operand
Returncode Expression_parse_new_operand(Expression* self, String* text, String* ends, Expression** expression, Char* end) {
  if (text->length == 0) {
    if ((*end) == '(') {
      CHECK(81, Block_expression_parse_new(NULL, &((*expression)), &((*end))) )
    }
    else {
      CHECK(83, f_syntax_error_c(&(String){11, 10, "unexpected"}, (*end)) )
    }
    free(text);
  }
  else {
    CHECK(86, Expression_parse_new_init_operand(self, text, &((*expression))) )
  }
  
  while (true) {
    if ((*end) == '?') {
      CHECK(90, Question_expression_parse_new(NULL, &((*expression)), &((*end))) )
    }
    Bool _Bool19;
    CHECK(91, Expression_parse_new_follow_operand(self, ends, &((*expression)), &((*end)), &(_Bool19)) )
    if (!(_Bool19)) break;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Parse the initialize part of an operand expression */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_parse_new_init_operand(Expression* self, String* text, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_parse_new_init_operand = "Expression.parse-new-init-operand";
#define MR_FUNC_NAME _func_name_Expression_parse_new_init_operand
Returncode Expression_parse_new_init_operand(Expression* self, String* text, Expression** expression) {
  if ((0) < 0 || (0) >= (text)->length) RAISE(97)
  Char first = ((text)->values[0]);
  Char second = '\0';
  if (text->length > 1) {
    if ((1) < 0 || (1) >= (text)->length) RAISE(100)
    second = ((text)->values[1]);
  }
  if (first == '\'') {
    CHECK(102, Char_expression_parse_new(NULL, text, &((*expression))) )
  }
  else {
    if (first == '"') {
      CHECK(104, String_expression_parse_new(NULL, text, &((*expression))) )
    }
    else {
      if ((first >= '0' && first <= '9') || (first == '-' && second >= '0' && second <= '9')) {
        CHECK(107, Int_expression_parse_new(NULL, text, &((*expression))) )
      }
      else {
        if (first >= 'A' && first <= 'Z' && second >= 'a' && second <= 'z') {
          CHECK(109, Type_expression_parse_new(NULL, text, &((*expression))) )
        }
        else {
          if (text->length == 1 && first == '_') {
            CHECK(111, Empty_expression_parse_new(NULL, text, &((*expression))) )
          }
          else {
            Bool _Bool20;
            CHECK(112, String_equal(text, &(String){5, 4, "base"}, &(_Bool20)) )
            if (_Bool20) {
              CHECK(113, Base_meth_expression_parse_new(NULL, text, &((*expression))) )
            }
            else {
              CHECK(115, Variable_expression_parse_new(NULL, text, &((*expression))) )
            }
          }
        }
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Parse one following part of an operand */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_parse_new_follow_operand(Expression* self, String* ends, Expression** expression, Char* end, Bool* has_more);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_parse_new_follow_operand = "Expression.parse-new-follow-operand";
#define MR_FUNC_NAME _func_name_Expression_parse_new_follow_operand
Returncode Expression_parse_new_follow_operand(Expression* self, String* ends, Expression** expression, Char* end, Bool* has_more) {
  (*has_more) = true;
  if ((*end) == '.') {
    CHECK(122, Member_expression_parse_new(NULL, ends, &((*expression)), &((*end))) )
  }
  else {
    if ((*end) == '[') {
      CHECK(124, Slice_expression_parse_new(NULL, ends, &((*expression)), &((*end))) )
    }
    else {
      if ((*end) == '(') {
        CHECK(126, Call_expression_parse_new(NULL, ends, &((*expression)), &((*end))) )
      }
      else {
        (*has_more) = false;
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Set type instance to be a type that has no sub-type */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_set_simple_type(Expression* self, Type_data* type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_set_simple_type = "Expression.set-simple-type";
#define MR_FUNC_NAME _func_name_Expression_set_simple_type
Returncode Expression_set_simple_type(Expression* self, Type_data* type_data) {
  self->result_type = malloc(sizeof(Type_instance));
  if (self->result_type == NULL) RAISE(132)
  *self->result_type = (Type_instance){NULL, NULL};
  self->result_type->type_data = type_data;
  return OK;
}
#undef MR_FUNC_NAME
#endif/* write to C - currently inly used in testing */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_write(Expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_write = "Expression.write";
#define MR_FUNC_NAME _func_name_Expression_write
Returncode Expression_write(Expression* self) {
  /* should be implemented by each specific expression type */
  RAISE(138)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Expression__dtl[] = {Expression_write};
#endif


/* A basic expression that has a single textual value */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Text_expression Text_expression;
#elif MR_STAGE == MR_TYPES(1)
struct Text_expression {
  Expression _base;
  String* text;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Text_expression_write(Text_expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Text_expression_write = "Text-expression.write";
#define MR_FUNC_NAME _func_name_Text_expression_write
Returncode Text_expression_write(Text_expression* self) {
  CHECK(146, Text_expression_write_text(self, self->_base.result_type->type_data->name) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Text_expression_write_text(Text_expression* self, String* type_name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Text_expression_write_text = "Text-expression.write-text";
#define MR_FUNC_NAME _func_name_Text_expression_write_text
Returncode Text_expression_write_text(Text_expression* self, String* type_name) {
  CHECK(149, write(type_name) )
  CHECK(150, write(&(String){2, 1, "("}) )
  CHECK(151, write(self->text) )
  CHECK(152, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Text_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Text_expression__dtl[] = {Text_expression_write};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/map.c"
#include "global/type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
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
