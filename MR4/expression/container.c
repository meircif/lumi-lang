#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/container.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file8_name = "expression/container.3.mr";
#endif
#define MR_FILE_NAME _mr_file8_name

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
Returncode BlockExpression_parse_new(BlockExpression* self, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BlockExpression_parse_new = "BlockExpression.parse-new";
#define MR_FUNC_NAME _func_name_BlockExpression_parse_new
Returncode BlockExpression_parse_new(BlockExpression* self, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  BlockExpression* block_expression = malloc(sizeof(BlockExpression));
  if (block_expression == NULL) RAISE(9)
  *block_expression = (BlockExpression){BlockExpression__dtl, NULL, NULL, false, false, NULL};
  block_expression->_base._dtl = BlockExpression__dtl;
  CHECK(10, BlockExpression_parse(block_expression, code_node, &((*end))) )
  (*expression) = &(block_expression->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `(expression)` */
#if MR_STAGE == MR_DECLARATIONS
Returncode BlockExpression_parse(BlockExpression* self, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BlockExpression_parse = "BlockExpression.parse";
#define MR_FUNC_NAME _func_name_BlockExpression_parse
Returncode BlockExpression_parse(BlockExpression* self, SyntaxTreeCode* code_node, Char* end) {
  Char _Char22;
  CHECK(15, parse_new_expression(&(String){2, 1, ")"}, code_node, &(self->expression), &(_Char22)) )
  CHECK(16, read_c(&((*end))) )
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
  CHECK(19, write(&(String){2, 1, "("}) )
  CHECK(20, (self->expression)->_dtl[2](self->expression) )
  CHECK(21, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BlockExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BlockExpression__dtl[] = {(void*)Expression_analyze, (void*)Expression_analyze_call, (void*)BlockExpression_write};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct Operator Operator;
#elif MR_STAGE == MR_TYPES(0)
struct Operator {
  String* name;
  String* c_name;
  Int order;
  Int group_index;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Operator_init(Operator* self, String* name, String* c_name, Int order, Int group_index);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Operator_init = "Operator.init";
#define MR_FUNC_NAME _func_name_Operator_init
Returncode Operator_init(Operator* self, String* name, String* c_name, Int order, Int group_index) {
  CHECK(35, string_new_copy(name, &(self->name)) )
  CHECK(36, string_new_copy(c_name, &(self->c_name)) )
  self->order = order;
  self->group_index = group_index;
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* An expression with an unary operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct UnaryExpression UnaryExpression;
#elif MR_STAGE == MR_TYPES(1)
struct UnaryExpression {
  Expression _base;
  Operator* operator;
  Expression* right_expression;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UnaryExpression_parse_new(UnaryExpression* self, String* ends, Operator* operator, SyntaxTreeCode* code_node, Expression** expression, Char* end, Operator** next_operator);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UnaryExpression_parse_new = "UnaryExpression.parse-new";
#define MR_FUNC_NAME _func_name_UnaryExpression_parse_new
Returncode UnaryExpression_parse_new(UnaryExpression* self, String* ends, Operator* operator, SyntaxTreeCode* code_node, Expression** expression, Char* end, Operator** next_operator) {
  UnaryExpression* unary_expression = malloc(sizeof(UnaryExpression));
  if (unary_expression == NULL) RAISE(49)
  *unary_expression = (UnaryExpression){UnaryExpression__dtl, NULL, NULL, false, false, NULL, NULL};
  unary_expression->_base._dtl = UnaryExpression__dtl;
  CHECK(50, UnaryExpression_parse(unary_expression, operator, ends, code_node, &((*end)), &((*next_operator))) )
  (*expression) = &(unary_expression->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UnaryExpression_parse(UnaryExpression* self, Operator* operator, String* ends, SyntaxTreeCode* code_node, Char* end, Operator** next_operator);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UnaryExpression_parse = "UnaryExpression.parse";
#define MR_FUNC_NAME _func_name_UnaryExpression_parse
Returncode UnaryExpression_parse(UnaryExpression* self, Operator* operator, String* ends, SyntaxTreeCode* code_node, Char* end, Operator** next_operator) {
  self->operator = operator;
  if ((*end) == '\n') {
    CHECK(61, read_line_break_spaces() )
  }
  else {
    if ((*end) != ' ') {
      CHECK(63, f_syntax_error_c(&(String){11, 10, "unexpected"}, (*end)) )
    }
  }
  CHECK(64, Expression_parse_new(NULL, ends, code_node, operator, &(self->right_expression), &((*end)), &((*next_operator))) )
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
  CHECK(68, UnaryExpression_write_start(self) )
  CHECK(69, UnaryExpression_write_end(self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UnaryExpression_write_start(UnaryExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UnaryExpression_write_start = "UnaryExpression.write-start";
#define MR_FUNC_NAME _func_name_UnaryExpression_write_start
Returncode UnaryExpression_write_start(UnaryExpression* self) {
  if (!self->_base.top) {
    CHECK(73, write(&(String){2, 1, "("}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UnaryExpression_write_end(UnaryExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UnaryExpression_write_end = "UnaryExpression.write-end";
#define MR_FUNC_NAME _func_name_UnaryExpression_write_end
Returncode UnaryExpression_write_end(UnaryExpression* self) {
  CHECK(76, write(self->operator->c_name) )
  CHECK(77, write(&(String){2, 1, " "}) )
  CHECK(78, (self->right_expression)->_dtl[2](self->right_expression) )
  if (!self->_base.top) {
    CHECK(80, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func UnaryExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func UnaryExpression__dtl[] = {(void*)Expression_analyze, (void*)Expression_analyze_call, (void*)UnaryExpression_write};
#endif


/* An expression with a binary operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct BinaryExpression BinaryExpression;
#elif MR_STAGE == MR_TYPES(2)
struct BinaryExpression {
  UnaryExpression _base;
  Expression* left_expression;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BinaryExpression_parse_new(BinaryExpression* self, String* ends, Operator* operator, SyntaxTreeCode* code_node, Expression** expression, Char* end, Operator** next_operator);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BinaryExpression_parse_new = "BinaryExpression.parse-new";
#define MR_FUNC_NAME _func_name_BinaryExpression_parse_new
Returncode BinaryExpression_parse_new(BinaryExpression* self, String* ends, Operator* operator, SyntaxTreeCode* code_node, Expression** expression, Char* end, Operator** next_operator) {
  BinaryExpression* binary_expression = malloc(sizeof(BinaryExpression));
  if (binary_expression == NULL) RAISE(90)
  *binary_expression = (BinaryExpression){BinaryExpression__dtl, NULL, NULL, false, false, NULL, NULL, NULL};
  binary_expression->_base._base._dtl = BinaryExpression__dtl;
  binary_expression->left_expression = (*expression);
  CHECK(92, UnaryExpression_parse(&(binary_expression->_base), operator, ends, code_node, &((*end)), &((*next_operator))) )
  (*expression) = &(binary_expression->_base._base);
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
  CHECK(97, UnaryExpression_write_start(&(self->_base)) )
  CHECK(98, (self->left_expression)->_dtl[2](self->left_expression) )
  CHECK(99, write(&(String){2, 1, " "}) )
  CHECK(100, UnaryExpression_write_end(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BinaryExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BinaryExpression__dtl[] = {(void*)Expression_analyze, (void*)Expression_analyze_call, (void*)BinaryExpression_write};
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
  if (question_expression == NULL) RAISE(108)
  *question_expression = (QuestionExpression){QuestionExpression__dtl, NULL, NULL, false, false, NULL};
  question_expression->_base._dtl = QuestionExpression__dtl;
  CHECK(109, QuestionExpression_parse(question_expression, (*expression), &((*end))) )
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
  CHECK(115, read_c(&((*end))) )
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
  if (!self->_base.top) {
    CHECK(119, write(&(String){2, 1, "("}) )
  }
  CHECK(120, (self->tested)->_dtl[2](self->tested) )
  CHECK(121, write(&(String){9, 8, " != NULL"}) )
  if (!self->_base.top) {
    CHECK(123, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func QuestionExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func QuestionExpression__dtl[] = {(void*)Expression_analyze, (void*)Expression_analyze_call, (void*)QuestionExpression_write};
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
