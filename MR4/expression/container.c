#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/container.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file9_name = "expression/container.3.mr";
#endif
#define MR_FILE_NAME _mr_file9_name

/* MR4 compiler - Container expressions */

/* An expression surrounded by brackets */
#if MR_STAGE == MR_TYPEDEFS
typedef struct BlockExpression BlockExpression;
#elif MR_STAGE == MR_TYPES(1)
struct BlockExpression {
  Expression _base;
  Expression* expression;
/* parsing `(expression)` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BlockExpression_parse_new(BlockExpression* self, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BlockExpression_parse_new = "BlockExpression.parse-new";
#define MR_FUNC_NAME _func_name_BlockExpression_parse_new
Returncode BlockExpression_parse_new(BlockExpression* self, Expression** expression, Char* end) {
  BlockExpression* block_expression = malloc(sizeof(BlockExpression));
  if (block_expression == NULL) RAISE(8)
  *block_expression = (BlockExpression){BlockExpression__dtl, NULL, NULL};
  block_expression->_base._dtl = BlockExpression__dtl;
  CHECK(9, BlockExpression_parse(block_expression, &((*end))) )
  (*expression) = &(block_expression->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `(expression)` */
#if MR_STAGE == MR_DECLARATIONS
Returncode BlockExpression_parse(BlockExpression* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BlockExpression_parse = "BlockExpression.parse";
#define MR_FUNC_NAME _func_name_BlockExpression_parse
Returncode BlockExpression_parse(BlockExpression* self, Char* end) {
  Char _Char21;
  CHECK(14, parse_new_expression(&(String){2, 1, ")"}, &(self->expression), &(_Char21)) )
  CHECK(15, read_c(&((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BlockExpression_write(BlockExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BlockExpression_write = "BlockExpression.write";
#define MR_FUNC_NAME _func_name_BlockExpression_write
Returncode BlockExpression_write(BlockExpression* self) {
  CHECK(18, write(&(String){7, 6, "Block("}) )
  CHECK(19, (self->expression)->_dtl[0](self->expression) )
  CHECK(20, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BlockExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BlockExpression__dtl[] = {(void*)BlockExpression_write};
#endif


/* A basic expression with an operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct OperatorExpression OperatorExpression;
#elif MR_STAGE == MR_TYPES(1)
struct OperatorExpression {
  Expression _base;
  Operator* operator;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode OperatorExpression_parse_sub_expression(OperatorExpression* self, Operator* operator, String* ends, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_OperatorExpression_parse_sub_expression = "OperatorExpression.parse-sub-expression";
#define MR_FUNC_NAME _func_name_OperatorExpression_parse_sub_expression
Returncode OperatorExpression_parse_sub_expression(OperatorExpression* self, Operator* operator, String* ends, Expression** expression, Char* end) {
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
Returncode OperatorExpression_write_operator_and_expresssion(OperatorExpression* self, Expression* expression);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_OperatorExpression_write_operator_and_expresssion = "OperatorExpression.write-operator-and-expresssion";
#define MR_FUNC_NAME _func_name_OperatorExpression_write_operator_and_expresssion
Returncode OperatorExpression_write_operator_and_expresssion(OperatorExpression* self, Expression* expression) {
  CHECK(38, write(self->operator->c_name) )
  CHECK(39, write(&(String){2, 1, " "}) )
  CHECK(40, (expression)->_dtl[0](expression) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func OperatorExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func OperatorExpression__dtl[] = {(void*)Expression_write};
#endif


/* An expression with an unary operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct UnaryExpression UnaryExpression;
#elif MR_STAGE == MR_TYPES(2)
struct UnaryExpression {
  OperatorExpression _base;
  Expression* expression;
/* parsing `operator expression` or `operator\n    expression` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UnaryExpression_parse_new(UnaryExpression* self, String* ends, Operator* operator, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UnaryExpression_parse_new = "UnaryExpression.parse-new";
#define MR_FUNC_NAME _func_name_UnaryExpression_parse_new
Returncode UnaryExpression_parse_new(UnaryExpression* self, String* ends, Operator* operator, Expression** expression, Char* end) {
  UnaryExpression* unary_expression = malloc(sizeof(UnaryExpression));
  if (unary_expression == NULL) RAISE(49)
  *unary_expression = (UnaryExpression){UnaryExpression__dtl, NULL, NULL, NULL};
  unary_expression->_base._base._dtl = UnaryExpression__dtl;
  CHECK(50, UnaryExpression_parse(unary_expression, operator, ends, &((*end))) )
  (*expression) = &(unary_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `operator expression` or `operator\n    expression` */
#if MR_STAGE == MR_DECLARATIONS
Returncode UnaryExpression_parse(UnaryExpression* self, Operator* operator, String* ends, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UnaryExpression_parse = "UnaryExpression.parse";
#define MR_FUNC_NAME _func_name_UnaryExpression_parse
Returncode UnaryExpression_parse(UnaryExpression* self, Operator* operator, String* ends, Char* end) {
  CHECK(55, OperatorExpression_parse_sub_expression(&(self->_base), operator, ends, &(self->expression), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UnaryExpression_write(UnaryExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UnaryExpression_write = "UnaryExpression.write";
#define MR_FUNC_NAME _func_name_UnaryExpression_write
Returncode UnaryExpression_write(UnaryExpression* self) {
  CHECK(59, OperatorExpression_write_operator_and_expresssion(&(self->_base), self->expression) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func UnaryExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func UnaryExpression__dtl[] = {(void*)UnaryExpression_write};
#endif


/* An expression with a binary operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct BinaryExpression BinaryExpression;
#elif MR_STAGE == MR_TYPES(2)
struct BinaryExpression {
  OperatorExpression _base;
  Expression* left_expression;
  Operator* operator;
  Expression* right_expression;
/* parsing `left-expression operator right-expression` *//* or `left-expression operator\n    right-expression` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BinaryExpression_parse_new(BinaryExpression* self, String* ends, Operator* operator, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BinaryExpression_parse_new = "BinaryExpression.parse-new";
#define MR_FUNC_NAME _func_name_BinaryExpression_parse_new
Returncode BinaryExpression_parse_new(BinaryExpression* self, String* ends, Operator* operator, Expression** expression, Char* end) {
  BinaryExpression* binary_expression = malloc(sizeof(BinaryExpression));
  if (binary_expression == NULL) RAISE(70)
  *binary_expression = (BinaryExpression){BinaryExpression__dtl, NULL, NULL, NULL, NULL, NULL};
  binary_expression->_base._base._dtl = BinaryExpression__dtl;
  CHECK(71, BinaryExpression_parse(binary_expression, (*expression), operator, ends, &((*end))) )
  (*expression) = &(binary_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `left-expression operator right-expression` *//* or `left-expression operator\n    right-expression` */
#if MR_STAGE == MR_DECLARATIONS
Returncode BinaryExpression_parse(BinaryExpression* self, Expression* left_expression, Operator* operator, String* ends, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BinaryExpression_parse = "BinaryExpression.parse";
#define MR_FUNC_NAME _func_name_BinaryExpression_parse
Returncode BinaryExpression_parse(BinaryExpression* self, Expression* left_expression, Operator* operator, String* ends, Char* end) {
  self->left_expression = left_expression;
  CHECK(83, OperatorExpression_parse_sub_expression(&(self->_base), operator, ends, &(self->right_expression), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BinaryExpression_write(BinaryExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BinaryExpression_write = "BinaryExpression.write";
#define MR_FUNC_NAME _func_name_BinaryExpression_write
Returncode BinaryExpression_write(BinaryExpression* self) {
  CHECK(87, (self->left_expression)->_dtl[0](self->left_expression) )
  CHECK(88, write(&(String){2, 1, " "}) )
  CHECK(89, OperatorExpression_write_operator_and_expresssion(&(self->_base), self->right_expression) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BinaryExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BinaryExpression__dtl[] = {(void*)BinaryExpression_write};
#endif


/* An expression with the "?" operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct QuestionExpression QuestionExpression;
#elif MR_STAGE == MR_TYPES(1)
struct QuestionExpression {
  Expression _base;
  Expression* tested;
/* parsing `tested?` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode QuestionExpression_parse_new(QuestionExpression* self, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_QuestionExpression_parse_new = "QuestionExpression.parse-new";
#define MR_FUNC_NAME _func_name_QuestionExpression_parse_new
Returncode QuestionExpression_parse_new(QuestionExpression* self, Expression** expression, Char* end) {
  QuestionExpression* question_expression = malloc(sizeof(QuestionExpression));
  if (question_expression == NULL) RAISE(97)
  *question_expression = (QuestionExpression){QuestionExpression__dtl, NULL, NULL};
  question_expression->_base._dtl = QuestionExpression__dtl;
  CHECK(98, QuestionExpression_parse(question_expression, (*expression), &((*end))) )
  (*expression) = &(question_expression->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `tested?` */
#if MR_STAGE == MR_DECLARATIONS
Returncode QuestionExpression_parse(QuestionExpression* self, Expression* tested, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_QuestionExpression_parse = "QuestionExpression.parse";
#define MR_FUNC_NAME _func_name_QuestionExpression_parse
Returncode QuestionExpression_parse(QuestionExpression* self, Expression* tested, Char* end) {
  self->tested = tested;
  CHECK(104, read_c(&((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode QuestionExpression_write(QuestionExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_QuestionExpression_write = "QuestionExpression.write";
#define MR_FUNC_NAME _func_name_QuestionExpression_write
Returncode QuestionExpression_write(QuestionExpression* self) {
  CHECK(107, write(&(String){10, 9, "Question("}) )
  CHECK(108, (self->tested)->_dtl[0](self->tested) )
  CHECK(109, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func QuestionExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func QuestionExpression__dtl[] = {(void*)QuestionExpression_write};
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
#include "expression/call.c"
#include "expression/constant.c"
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
