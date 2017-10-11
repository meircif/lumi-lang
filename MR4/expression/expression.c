#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/expression.c"
#define DEPTH 5
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
BinaryExpression:
  operator: +
  left: SliceExpression:
    sequence: SymbolExpression(array)
    index: IntExpression(4)
  right: IntExpression(3)
 */

/* Return in `expression` a new allocated expression parsed from the input */
/* file until one of the characters in `ends` is reached. */
/* Return the end character in `end` */
#if MR_STAGE == MR_DECLARATIONS
Returncode parse_new_expression(String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_parse_new_expression = "parse-new-expression";
#define MR_FUNC_NAME _func_name_parse_new_expression
Returncode parse_new_expression(String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  Operator* _Operator23;
  CHECK(23, Expression_parse_new(NULL, ends, code_node, NULL, &((*expression)), &((*end)), &(_Operator23)) )
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
  SyntaxTreeCode* code_node;
  TypeInstance* result_type;
  Bool assignable;
  Bool top;
/* Parse any expression *//* Read a single expression value as new string *//* Parse an expression that is an operand *//* Parse the initialize part of an operand expression *//* Parse one following part of an operand *//* Set type instance to be a type that has no sub-type *//* write to C */};
#endif/* Parse any expression */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_parse_new(Expression* self, String* ends, SyntaxTreeCode* code_node, Operator* curr_operator, Expression** expression, Char* end, Operator** operator);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_parse_new = "Expression.parse-new";
#define MR_FUNC_NAME _func_name_Expression_parse_new
Returncode Expression_parse_new(Expression* self, String* ends, SyntaxTreeCode* code_node, Operator* curr_operator, Expression** expression, Char* end, Operator** operator) {
  (*expression) = NULL;
  Bool _Bool24;
  CHECK(45, String_has(ends, ' ', &(_Bool24)) )
  Bool multi_operands = !_Bool24;
  String* text = NULL;
  CHECK(47, Expression_read_new_value(self, ends, &(text), &((*end))) )
  CHECK(48, NameMap_find(glob->operator_map, text, (void**)&((*operator))) )
  if (NULL != (*operator)) {
    if (!multi_operands) {
      CHECK(51, f_syntax_error(&(String){20, 19, "unexpected operator"}, (*operator)->name) )
    }
    CHECK(52, UnaryExpression_parse_new(NULL, ends, (*operator), code_node, &((*expression)), &((*end)), &((*operator))) )
  }
  else {
    CHECK(56, Expression_parse_new_operand(self, text, ends, code_node, &((*expression)), &((*end))) )
    if (multi_operands && (*end) == ' ') {
      CHECK(59, Expression_read_new_value(self, ends, &(text), &((*end))) )
      CHECK(60, NameMap_find(glob->operator_map, text, (void**)&((*operator))) )
      if (!(NULL != (*operator))) {
        CHECK(62, f_syntax_error(&(String){17, 16, "unknown operator"}, text) )
      }
    }
  }
  while (true) {
    if (!(NULL != (*operator) && (!(NULL != curr_operator) || (*operator)->order < curr_operator->order))) break;
    CHECK(66, BinaryExpression_parse_new(NULL, ends, (*operator), code_node, &((*expression)), &((*end)), &((*operator))) )
  }
  if (!(NULL != curr_operator)) {
    (*expression)->top = true;
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
  CHECK(75, string_new_concat(&(String){6, 5, " .[(?"}, ends, &(all_ends)) )
  CHECK(76, read_new(all_ends, &((*text)), &((*end))) )
  free(all_ends);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Parse an expression that is an operand */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_parse_new_operand(Expression* self, String* text, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_parse_new_operand = "Expression.parse-new-operand";
#define MR_FUNC_NAME _func_name_Expression_parse_new_operand
Returncode Expression_parse_new_operand(Expression* self, String* text, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  if (text->length == 0) {
    if ((*end) == '(') {
      CHECK(85, BlockExpression_parse_new(NULL, code_node, &((*expression)), &((*end))) )
    }
    else {
      CHECK(88, f_syntax_error_c(&(String){11, 10, "unexpected"}, (*end)) )
    }
    free(text);
  }
  else {
    CHECK(91, Expression_parse_new_init_operand(self, text, code_node, &((*expression))) )
  }
  
  while (true) {
    if ((*end) == '?') {
      CHECK(95, QuestionExpression_parse_new(NULL, &((*expression)), &((*end))) )
    }
    Bool _Bool25;
    CHECK(96, Expression_parse_new_follow_operand(self, ends, code_node, &((*expression)), &((*end)), &(_Bool25)) )
    if (!(_Bool25)) break;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Parse the initialize part of an operand expression */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_parse_new_init_operand(Expression* self, String* text, SyntaxTreeCode* code_node, Expression** expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_parse_new_init_operand = "Expression.parse-new-init-operand";
#define MR_FUNC_NAME _func_name_Expression_parse_new_init_operand
Returncode Expression_parse_new_init_operand(Expression* self, String* text, SyntaxTreeCode* code_node, Expression** expression) {
  if ((0) < 0 || (0) >= (text)->length) RAISE(103)
  Char first = ((text)->values[0]);
  Char second = '\0';
  if (text->length > 1) {
    if ((1) < 0 || (1) >= (text)->length) RAISE(106)
    second = ((text)->values[1]);
  }
  if (first == '\'') {
    CHECK(108, CharExpression_parse_new(NULL, text, &((*expression))) )
  }
  else {
    if (first == '"') {
      CHECK(110, StringExpression_parse_new(NULL, text, &((*expression))) )
    }
    else {
      if ((first >= '0' && first <= '9') || (first == '-' && second >= '0' && second <= '9')) {
        CHECK(113, IntExpression_parse_new(NULL, text, &((*expression))) )
      }
      else {
        if (first >= 'A' && first <= 'Z' && second >= 'a' && second <= 'z') {
          CHECK(115, TypeExpression_parse_new(NULL, text, &((*expression))) )
        }
        else {
          if (text->length == 1 && first == '_') {
            CHECK(117, EmptyExpression_parse_new(NULL, text, &((*expression))) )
          }
          else {
            Bool _Bool26;
            CHECK(118, String_equal(text, &(String){5, 4, "base"}, &(_Bool26)) )
            if (_Bool26) {
              CHECK(119, BaseMethExpression_parse_new(NULL, text, code_node, &((*expression))) )
            }
            else {
              CHECK(122, SymbolExpression_parse_new(NULL, text, code_node, &((*expression))) )
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
Returncode Expression_parse_new_follow_operand(Expression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end, Bool* has_more);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_parse_new_follow_operand = "Expression.parse-new-follow-operand";
#define MR_FUNC_NAME _func_name_Expression_parse_new_follow_operand
Returncode Expression_parse_new_follow_operand(Expression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end, Bool* has_more) {
  (*has_more) = true;
  if ((*end) == '.') {
    CHECK(131, MemberExpression_parse_new(NULL, ends, &((*expression)), &((*end))) )
  }
  else {
    if ((*end) == '[') {
      CHECK(133, SliceExpression_parse_new(NULL, ends, code_node, &((*expression)), &((*end))) )
    }
    else {
      if ((*end) == '(') {
        CHECK(136, CallExpression_parse_new(NULL, ends, code_node, &((*expression)), &((*end))) )
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
Returncode Expression_set_simple_type(Expression* self, TypeData* type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_set_simple_type = "Expression.set-simple-type";
#define MR_FUNC_NAME _func_name_Expression_set_simple_type
Returncode Expression_set_simple_type(Expression* self, TypeData* type_data) {
  self->result_type = malloc(sizeof(TypeInstance));
  if (self->result_type == NULL) RAISE(143)
  *self->result_type = (TypeInstance){NULL, NULL, NULL, NULL};
  self->result_type->type_data = type_data;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_analyze(Expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_analyze = "Expression.analyze";
#define MR_FUNC_NAME _func_name_Expression_analyze
Returncode Expression_analyze(Expression* self) {
  /* do noting */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_analyze_call(Expression* self, FunctionArguments* arguments);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_analyze_call = "Expression.analyze-call";
#define MR_FUNC_NAME _func_name_Expression_analyze_call
Returncode Expression_analyze_call(Expression* self, FunctionArguments* arguments) {
  /* do noting */
  return OK;
}
#undef MR_FUNC_NAME
#endif/* write to C */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_write(Expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_write = "Expression.write";
#define MR_FUNC_NAME _func_name_Expression_write
Returncode Expression_write(Expression* self) {
  /* should be implemented by each specific expression type */
  RAISE(155)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Expression__dtl[] = {(void*)Expression_analyze, (void*)Expression_analyze_call, (void*)Expression_write};
#endif


/* A basic expression that has a single textual value */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TextExpression TextExpression;
#elif MR_STAGE == MR_TYPES(1)
struct TextExpression {
  Expression _base;
  String* text;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TextExpression_write(TextExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TextExpression_write = "TextExpression.write";
#define MR_FUNC_NAME _func_name_TextExpression_write
Returncode TextExpression_write(TextExpression* self) {
  CHECK(163, write(self->text) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func TextExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func TextExpression__dtl[] = {(void*)Expression_analyze, (void*)Expression_analyze_call, (void*)TextExpression_write};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
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
