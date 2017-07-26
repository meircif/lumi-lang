#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/container.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file8_name = "expression/container.3.mr";
#endif
#define MR_FILE_NAME _mr_file8_name

/* MR4 compiler - Container expressions */

/* An expression surrounded by brackets */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Block_expression Block_expression;
#elif MR_STAGE == MR_TYPES(1)
struct Block_expression {
  Expression _base;
  Expression* expression;
/* parsing `(expression)` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Block_expression_parse_new(Block_expression* self, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Block_expression_parse_new = "Block-expression.parse-new";
#define MR_FUNC_NAME _func_name_Block_expression_parse_new
Returncode Block_expression_parse_new(Block_expression* self, Expression** expression, Char* end) {
  Block_expression* block_expression = malloc(sizeof(Block_expression));
  if (block_expression == NULL) RAISE(8)
  *block_expression = (Block_expression){Block_expression__dtl, NULL, NULL};
  block_expression->_base._dtl = Block_expression__dtl;
  CHECK(9, Block_expression_parse(block_expression, &((*end))) )
  (*expression) = &(block_expression->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `(expression)` */
#if MR_STAGE == MR_DECLARATIONS
Returncode Block_expression_parse(Block_expression* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Block_expression_parse = "Block-expression.parse";
#define MR_FUNC_NAME _func_name_Block_expression_parse
Returncode Block_expression_parse(Block_expression* self, Char* end) {
  Char _Char22;
  CHECK(14, parse_new_expression(&(String){2, 1, ")"}, &(self->expression), &(_Char22)) )
  CHECK(15, read_c(&((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Block_expression_write(Block_expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Block_expression_write = "Block-expression.write";
#define MR_FUNC_NAME _func_name_Block_expression_write
Returncode Block_expression_write(Block_expression* self) {
  CHECK(18, write(&(String){7, 6, "Block("}) )
  CHECK(19, (self->expression)->_dtl[0](self->expression) )
  CHECK(20, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Block_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Block_expression__dtl[] = {Block_expression_write};
#endif


/* A basic expression with an operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Operator_expression Operator_expression;
#elif MR_STAGE == MR_TYPES(1)
struct Operator_expression {
  Expression _base;
  Operator* operator;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Operator_expression_parse_sub_expression(Operator_expression* self, Operator* operator, String* ends, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Operator_expression_parse_sub_expression = "Operator-expression.parse-sub-expression";
#define MR_FUNC_NAME _func_name_Operator_expression_parse_sub_expression
Returncode Operator_expression_parse_sub_expression(Operator_expression* self, Operator* operator, String* ends, Expression** expression, Char* end) {
  self->operator = operator;
  if ((*end) == '\n') {
    CHECK(31, read_line_break_spaces() )
  }
  String* new_ends = NULL;
  CHECK(33, string_new_concat(&(String){2, 1, " "}, ends, &(new_ends)) )
  CHECK(34, parse_new_expression(new_ends, &((*expression)), &((*end))) )
  free(new_ends);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Operator_expression_write_operator_and_expresssion(Operator_expression* self, Expression* expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Operator_expression_write_operator_and_expresssion = "Operator-expression.write-operator-and-expresssion";
#define MR_FUNC_NAME _func_name_Operator_expression_write_operator_and_expresssion
Returncode Operator_expression_write_operator_and_expresssion(Operator_expression* self, Expression* expression) {
  CHECK(38, write(self->operator->c_name) )
  CHECK(39, write(&(String){2, 1, " "}) )
  CHECK(40, (expression)->_dtl[0](expression) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Operator_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Operator_expression__dtl[] = {Expression_write};
#endif


/* An expression with an unary operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Unary_expression Unary_expression;
#elif MR_STAGE == MR_TYPES(2)
struct Unary_expression {
  Operator_expression _base;
  Expression* expression;
/* parsing `operator expression` or `operator\n    expression` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Unary_expression_parse_new(Unary_expression* self, String* ends, Operator* operator, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Unary_expression_parse_new = "Unary-expression.parse-new";
#define MR_FUNC_NAME _func_name_Unary_expression_parse_new
Returncode Unary_expression_parse_new(Unary_expression* self, String* ends, Operator* operator, Expression** expression, Char* end) {
  Unary_expression* unary_expression = malloc(sizeof(Unary_expression));
  if (unary_expression == NULL) RAISE(49)
  *unary_expression = (Unary_expression){Unary_expression__dtl, NULL, NULL, NULL};
  unary_expression->_base._base._dtl = Unary_expression__dtl;
  CHECK(50, Unary_expression_parse(unary_expression, operator, ends, &((*end))) )
  (*expression) = &(unary_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `operator expression` or `operator\n    expression` */
#if MR_STAGE == MR_DECLARATIONS
Returncode Unary_expression_parse(Unary_expression* self, Operator* operator, String* ends, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Unary_expression_parse = "Unary-expression.parse";
#define MR_FUNC_NAME _func_name_Unary_expression_parse
Returncode Unary_expression_parse(Unary_expression* self, Operator* operator, String* ends, Char* end) {
  CHECK(55, Operator_expression_parse_sub_expression(&(self->_base), operator, ends, &(self->expression), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Unary_expression_write(Unary_expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Unary_expression_write = "Unary-expression.write";
#define MR_FUNC_NAME _func_name_Unary_expression_write
Returncode Unary_expression_write(Unary_expression* self) {
  CHECK(59, Operator_expression_write_operator_and_expresssion(&(self->_base), self->expression) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Unary_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Unary_expression__dtl[] = {Unary_expression_write};
#endif


/* An expression with a binary operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Binary_expression Binary_expression;
#elif MR_STAGE == MR_TYPES(2)
struct Binary_expression {
  Operator_expression _base;
  Expression* left_expression;
  Operator* operator;
  Expression* right_expression;
/* parsing `left-expression operator right-expression` *//* or `left-expression operator\n    right-expression` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Binary_expression_parse_new(Binary_expression* self, String* ends, Operator* operator, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Binary_expression_parse_new = "Binary-expression.parse-new";
#define MR_FUNC_NAME _func_name_Binary_expression_parse_new
Returncode Binary_expression_parse_new(Binary_expression* self, String* ends, Operator* operator, Expression** expression, Char* end) {
  Binary_expression* binary_expression = malloc(sizeof(Binary_expression));
  if (binary_expression == NULL) RAISE(70)
  *binary_expression = (Binary_expression){Binary_expression__dtl, NULL, NULL, NULL, NULL, NULL};
  binary_expression->_base._base._dtl = Binary_expression__dtl;
  CHECK(71, Binary_expression_parse(binary_expression, (*expression), operator, ends, &((*end))) )
  (*expression) = &(binary_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `left-expression operator right-expression` *//* or `left-expression operator\n    right-expression` */
#if MR_STAGE == MR_DECLARATIONS
Returncode Binary_expression_parse(Binary_expression* self, Expression* left_expression, Operator* operator, String* ends, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Binary_expression_parse = "Binary-expression.parse";
#define MR_FUNC_NAME _func_name_Binary_expression_parse
Returncode Binary_expression_parse(Binary_expression* self, Expression* left_expression, Operator* operator, String* ends, Char* end) {
  self->left_expression = left_expression;
  CHECK(83, Operator_expression_parse_sub_expression(&(self->_base), operator, ends, &(self->right_expression), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Binary_expression_write(Binary_expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Binary_expression_write = "Binary-expression.write";
#define MR_FUNC_NAME _func_name_Binary_expression_write
Returncode Binary_expression_write(Binary_expression* self) {
  CHECK(87, (self->left_expression)->_dtl[0](self->left_expression) )
  CHECK(88, write(&(String){2, 1, " "}) )
  CHECK(89, Operator_expression_write_operator_and_expresssion(&(self->_base), self->right_expression) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Binary_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Binary_expression__dtl[] = {Binary_expression_write};
#endif


/* An expression with the "?" operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Question_expression Question_expression;
#elif MR_STAGE == MR_TYPES(1)
struct Question_expression {
  Expression _base;
  Expression* tested;
/* parsing `tested?` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Question_expression_parse_new(Question_expression* self, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Question_expression_parse_new = "Question-expression.parse-new";
#define MR_FUNC_NAME _func_name_Question_expression_parse_new
Returncode Question_expression_parse_new(Question_expression* self, Expression** expression, Char* end) {
  Question_expression* question_expression = malloc(sizeof(Question_expression));
  if (question_expression == NULL) RAISE(97)
  *question_expression = (Question_expression){Question_expression__dtl, NULL, NULL};
  question_expression->_base._dtl = Question_expression__dtl;
  CHECK(98, Question_expression_parse(question_expression, (*expression), &((*end))) )
  (*expression) = &(question_expression->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `tested?` */
#if MR_STAGE == MR_DECLARATIONS
Returncode Question_expression_parse(Question_expression* self, Expression* tested, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Question_expression_parse = "Question-expression.parse";
#define MR_FUNC_NAME _func_name_Question_expression_parse
Returncode Question_expression_parse(Question_expression* self, Expression* tested, Char* end) {
  self->tested = tested;
  CHECK(104, read_c(&((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Question_expression_write(Question_expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Question_expression_write = "Question-expression.write";
#define MR_FUNC_NAME _func_name_Question_expression_write
Returncode Question_expression_write(Question_expression* self) {
  CHECK(107, write(&(String){10, 9, "Question("}) )
  CHECK(108, (self->tested)->_dtl[0](self->tested) )
  CHECK(109, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Question_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Question_expression__dtl[] = {Question_expression_write};
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
