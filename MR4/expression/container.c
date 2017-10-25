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
#elif MR_STAGE == MR_TYPES(2)
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
  *block_expression = (BlockExpression){BlockExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL};
  block_expression->_base._base._dtl = BlockExpression__dtl;
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
  CHECK(15, SyntaxTreeNode_set_location(&(self->_base._base)) )
  Char _Char25;
  CHECK(16, parse_new_expression(&(String){2, 1, ")"}, code_node, &(self->expression), &(_Char25)) )
  CHECK(17, read_c(&((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BlockExpression_analyze(BlockExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BlockExpression_analyze = "BlockExpression.analyze";
#define MR_FUNC_NAME _func_name_BlockExpression_analyze
Returncode BlockExpression_analyze(BlockExpression* self) {
  CHECK(20, (self->expression)->_base._dtl[0](self->expression) )
  CHECK(21, TypeInstance_m_copy_new(self->expression->result_type, &(self->_base.result_type)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BlockExpression_write_preactions(BlockExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BlockExpression_write_preactions = "BlockExpression.write-preactions";
#define MR_FUNC_NAME _func_name_BlockExpression_write_preactions
Returncode BlockExpression_write_preactions(BlockExpression* self) {
  CHECK(24, (self->expression)->_base._dtl[3](self->expression) )
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
  CHECK(27, write(&(String){2, 1, "("}) )
  CHECK(28, (self->expression)->_base._dtl[1](self->expression) )
  CHECK(29, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BlockExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BlockExpression__dtl[] = {(void*)BlockExpression_analyze, (void*)BlockExpression_write, (void*)Expression_analyze_call, (void*)BlockExpression_write_preactions};
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
  CHECK(43, string_new_copy(name, &(self->name)) )
  CHECK(44, string_new_copy(c_name, &(self->c_name)) )
  self->order = order;
  self->group_index = group_index;
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* An expression with an unary operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct UnaryExpression UnaryExpression;
#elif MR_STAGE == MR_TYPES(2)
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
  if (unary_expression == NULL) RAISE(57)
  *unary_expression = (UnaryExpression){UnaryExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL, NULL};
  unary_expression->_base._base._dtl = UnaryExpression__dtl;
  CHECK(58, UnaryExpression_parse(unary_expression, operator, ends, code_node, &((*end)), &((*next_operator))) )
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
  CHECK(68, SyntaxTreeNode_set_location(&(self->_base._base)) )
  if ((*end) == '\n') {
    CHECK(70, SyntaxTreeNode_read_line_break_spaces(&(self->_base._base)) )
  }
  else {
    if ((*end) != ' ') {
      CHECK(72, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){11, 10, "unexpected"}, (*end)) )
    }
  }
  CHECK(73, Expression_parse_new(NULL, ends, code_node, operator, &(self->right_expression), &((*end)), &((*next_operator))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UnaryExpression_analyze(UnaryExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UnaryExpression_analyze = "UnaryExpression.analyze";
#define MR_FUNC_NAME _func_name_UnaryExpression_analyze
Returncode UnaryExpression_analyze(UnaryExpression* self) {
  CHECK(77, UnaryExpression_analyze_operand(self, self->right_expression) )
  if (self->operator->order == 2) {
    /* `not` operator */
    CHECK(80, UnaryExpression_test_operand_type(self, self->right_expression, glob->type_bool) )
    CHECK(81, Expression_set_simple_type(&(self->_base), glob->type_bool) )
  }
  else {
    Bool _Bool26;
    CHECK(82, String_equal(self->operator->name, &(String){2, 1, "-"}, &(_Bool26)) )
    if (_Bool26) {
      CHECK(83, UnaryExpression_test_operand_type(self, self->right_expression, glob->type_int) )
      CHECK(84, Expression_set_simple_type(&(self->_base), glob->type_int) )
    }
    else {
      CHECK(86, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){19, 18, "not unary operator"}, self->operator->name) )
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UnaryExpression_analyze_operand(UnaryExpression* self, Expression* operand);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UnaryExpression_analyze_operand = "UnaryExpression.analyze-operand";
#define MR_FUNC_NAME _func_name_UnaryExpression_analyze_operand
Returncode UnaryExpression_analyze_operand(UnaryExpression* self, Expression* operand) {
  CHECK(89, (operand)->_base._dtl[0](operand) )
  if (!(NULL != operand->result_type)) {
    CHECK(91, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){45, 44, "void expression given as operand to operator"}, self->operator->name) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UnaryExpression_test_operand_type(UnaryExpression* self, Expression* operand, TypeData* expected_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UnaryExpression_test_operand_type = "UnaryExpression.test-operand-type";
#define MR_FUNC_NAME _func_name_UnaryExpression_test_operand_type
Returncode UnaryExpression_test_operand_type(UnaryExpression* self, Expression* operand, TypeData* expected_type) {
  if (operand->result_type->type_data != expected_type) {
    CHECK(99, SyntaxTreeNode_m_syntax_error3(&(self->_base._base), &(String){9, 8, "operator"}, self->operator->name, &(String){9, 8, "expected"}, expected_type->name, &(String){13, 12, "operand, got"}, operand->result_type->type_data->name) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode UnaryExpression_write_preactions(UnaryExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_UnaryExpression_write_preactions = "UnaryExpression.write-preactions";
#define MR_FUNC_NAME _func_name_UnaryExpression_write_preactions
Returncode UnaryExpression_write_preactions(UnaryExpression* self) {
  CHECK(108, (self->right_expression)->_base._dtl[3](self->right_expression) )
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
  CHECK(111, UnaryExpression_write_start(self) )
  CHECK(112, UnaryExpression_write_end(self) )
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
    CHECK(116, write(&(String){2, 1, "("}) )
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
  CHECK(119, write(self->operator->c_name) )
  CHECK(120, write(&(String){2, 1, " "}) )
  CHECK(121, (self->right_expression)->_base._dtl[1](self->right_expression) )
  if (!self->_base.top) {
    CHECK(123, write(&(String){2, 1, ")"}) )
  }
  if (self->_base.is_statement) {
    CHECK(125, write(&(String){2, 1, ";"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func UnaryExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func UnaryExpression__dtl[] = {(void*)UnaryExpression_analyze, (void*)UnaryExpression_write, (void*)Expression_analyze_call, (void*)UnaryExpression_write_preactions};
#endif


/* An expression with a binary operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct BinaryExpression BinaryExpression;
#elif MR_STAGE == MR_TYPES(3)
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
  if (binary_expression == NULL) RAISE(135)
  *binary_expression = (BinaryExpression){BinaryExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL, NULL, NULL};
  binary_expression->_base._base._base._dtl = BinaryExpression__dtl;
  binary_expression->left_expression = (*expression);
  CHECK(137, UnaryExpression_parse(&(binary_expression->_base), operator, ends, code_node, &((*end)), &((*next_operator))) )
  (*expression) = &(binary_expression->_base._base);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BinaryExpression_analyze(BinaryExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BinaryExpression_analyze = "BinaryExpression.analyze";
#define MR_FUNC_NAME _func_name_BinaryExpression_analyze
Returncode BinaryExpression_analyze(BinaryExpression* self) {
  CHECK(142, UnaryExpression_analyze_operand(&(self->_base), self->_base.right_expression) )
  CHECK(143, UnaryExpression_analyze_operand(&(self->_base), self->left_expression) )
  if (self->_base.operator->order == 2) {
    /* `not` operator */
    CHECK(146, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){35, 34, "cannot use \"not\" as binary operand"}) )
  }
  if (self->_base.operator->order == 3) {
    /* `or`\`and` operator */
    CHECK(149, BinaryExpression_test_operands_type(self, glob->type_bool) )
    CHECK(150, Expression_set_simple_type(&(self->_base._base), glob->type_bool) )
  }
  else {
    Bool _Bool27;
    CHECK(151, String_equal(self->_base.operator->name, &(String){3, 2, ":="}, &(_Bool27)) )
    if (_Bool27) {
      CHECK(152, TypeInstance_m_check_assign_to(self->_base.right_expression->result_type, self->left_expression->result_type, &(self->_base._base._base)) )
      if (!self->left_expression->assignable) {
        CHECK(155, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){41, 40, "assigning into non assignable expression"}) )
      }
      self->left_expression->top = true;
      self->_base.right_expression->top = true;
    }
    else {
      /* any other Int operator */
      CHECK(160, BinaryExpression_test_operands_type(self, glob->type_int) )
      if (self->_base.operator->order == 0) {
        /* aritmetic operator */
        CHECK(163, Expression_set_simple_type(&(self->_base._base), glob->type_int) )
      }
      else {
        if (self->_base.operator->order == 1) {
          /* compare operator */
          CHECK(166, Expression_set_simple_type(&(self->_base._base), glob->type_bool) )
        }
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BinaryExpression_test_operands_type(BinaryExpression* self, TypeData* expected_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BinaryExpression_test_operands_type = "BinaryExpression.test-operands-type";
#define MR_FUNC_NAME _func_name_BinaryExpression_test_operands_type
Returncode BinaryExpression_test_operands_type(BinaryExpression* self, TypeData* expected_type) {
  CHECK(169, UnaryExpression_test_operand_type(&(self->_base), self->_base.right_expression, expected_type) )
  CHECK(170, UnaryExpression_test_operand_type(&(self->_base), self->left_expression, expected_type) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BinaryExpression_write_preactions(BinaryExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BinaryExpression_write_preactions = "BinaryExpression.write-preactions";
#define MR_FUNC_NAME _func_name_BinaryExpression_write_preactions
Returncode BinaryExpression_write_preactions(BinaryExpression* self) {
  CHECK(173, UnaryExpression_write_preactions(&(self->_base)) )
  CHECK(174, (self->left_expression)->_base._dtl[3](self->left_expression) )
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
  CHECK(177, UnaryExpression_write_start(&(self->_base)) )
  CHECK(178, (self->left_expression)->_base._dtl[1](self->left_expression) )
  CHECK(179, write(&(String){2, 1, " "}) )
  CHECK(180, UnaryExpression_write_end(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BinaryExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BinaryExpression__dtl[] = {(void*)BinaryExpression_analyze, (void*)BinaryExpression_write, (void*)Expression_analyze_call, (void*)BinaryExpression_write_preactions};
#endif


/* An expression with the "?" operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct QuestionExpression QuestionExpression;
#elif MR_STAGE == MR_TYPES(2)
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
  if (question_expression == NULL) RAISE(188)
  *question_expression = (QuestionExpression){QuestionExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL};
  question_expression->_base._base._dtl = QuestionExpression__dtl;
  CHECK(189, QuestionExpression_parse(question_expression, (*expression), &((*end))) )
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
  CHECK(195, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(196, read_c(&((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode QuestionExpression_analyze(QuestionExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_QuestionExpression_analyze = "QuestionExpression.analyze";
#define MR_FUNC_NAME _func_name_QuestionExpression_analyze
Returncode QuestionExpression_analyze(QuestionExpression* self) {
  CHECK(199, (self->tested)->_base._dtl[0](self->tested) )
  if (!(NULL != self->tested->result_type)) {
    CHECK(201, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){34, 33, "cannot use \"?\" on void expression"}) )
  }
  if (self->tested->result_type->type_data->is_primitive) {
    CHECK(203, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){23, 22, "cannot use \"?\" on type"}, self->tested->result_type->type_data->name) )
  }
  CHECK(206, Expression_set_simple_type(&(self->_base), glob->type_bool) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode QuestionExpression_write_preactions(QuestionExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_QuestionExpression_write_preactions = "QuestionExpression.write-preactions";
#define MR_FUNC_NAME _func_name_QuestionExpression_write_preactions
Returncode QuestionExpression_write_preactions(QuestionExpression* self) {
  CHECK(209, (self->tested)->_base._dtl[3](self->tested) )
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
    CHECK(213, write(&(String){2, 1, "("}) )
  }
  CHECK(214, (self->tested)->_base._dtl[1](self->tested) )
  CHECK(215, write(&(String){9, 8, " != NULL"}) )
  if (!self->_base.top) {
    CHECK(217, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func QuestionExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func QuestionExpression__dtl[] = {(void*)QuestionExpression_analyze, (void*)QuestionExpression_write, (void*)Expression_analyze_call, (void*)QuestionExpression_write_preactions};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/argument.c"
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
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
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
