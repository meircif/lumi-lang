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
  CHECK(16, parse_new_expression(&(String){2, 1, ")"}, code_node, &(self->expression), &((*end))) )
  if ((*end) != ')') {
    CHECK(19, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){18, 17, "expected \")\", got"}, (*end)) )
  }
  CHECK(20, read_c(&((*end))) )
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
  CHECK(23, (self->expression)->_base._dtl[1](self->expression) )
  CHECK(24, TypeInstance_copy_new(self->expression->result_type, &(self->_base.result_type)) )
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
  CHECK(27, (self->expression)->_base._dtl[6](self->expression) )
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
  if (!self->_base.top) {
    CHECK(31, write(&(String){2, 1, "("}) )
  }
  CHECK(32, (self->expression)->_base._dtl[2](self->expression) )
  if (!self->_base.top) {
    CHECK(34, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BlockExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BlockExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)BlockExpression_analyze, (void*)BlockExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)BlockExpression_write_preactions};
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
  CHECK(48, string_new_copy(name, &(self->name)) )
  CHECK(49, string_new_copy(c_name, &(self->c_name)) )
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
  if (unary_expression == NULL) RAISE(62)
  *unary_expression = (UnaryExpression){UnaryExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL, NULL};
  unary_expression->_base._base._dtl = UnaryExpression__dtl;
  CHECK(63, UnaryExpression_parse(unary_expression, operator, ends, code_node, &((*end)), &((*next_operator))) )
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
  self->_base.code_node = code_node;
  CHECK(74, SyntaxTreeNode_set_location(&(self->_base._base)) )
  if ((*end) == '\n') {
    CHECK(76, SyntaxTreeCode_read_line_break_spaces(code_node) )
  }
  else {
    if ((*end) != ' ') {
      CHECK(78, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){11, 10, "unexpected"}, (*end)) )
    }
  }
  CHECK(79, Expression_parse_new(NULL, ends, code_node, operator, &(self->right_expression), &((*end)), &((*next_operator))) )
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
  CHECK(83, UnaryExpression_analyze_operand(self, self->right_expression) )
  if (self->operator->order == 2) {
    /* `not` operator */
    CHECK(86, UnaryExpression_test_operand_type(self, self->right_expression, &(glob->type_bool->_base)) )
    CHECK(87, Expression_set_simple_type(&(self->_base), &(glob->type_bool->_base)) )
  }
  else {
    Bool _Bool26;
    CHECK(88, String_equal(self->operator->name, &(String){2, 1, "-"}, &(_Bool26)) )
    if (_Bool26) {
      CHECK(89, UnaryExpression_test_operand_type(self, self->right_expression, &(glob->type_int->_base)) )
      CHECK(90, Expression_set_simple_type(&(self->_base), &(glob->type_int->_base)) )
    }
    else {
      CHECK(92, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){19, 18, "not unary operator"}, self->operator->name) )
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
  CHECK(95, (operand)->_base._dtl[1](operand) )
  if (!(NULL != operand->result_type)) {
    CHECK(97, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){45, 44, "void expression given as operand to operator"}, self->operator->name) )
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
  Bool _Bool27;
  CHECK(104, TypeData_m_is_same(expected_type, operand->result_type->type_data, &(_Bool27)) )
  if (!_Bool27) {
    CHECK(105, SyntaxTreeNode_m_syntax_error3(&(self->_base._base), &(String){9, 8, "operator"}, self->operator->name, &(String){9, 8, "expected"}, expected_type->name, &(String){13, 12, "operand, got"}, operand->result_type->type_data->name) )
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
  CHECK(114, (self->right_expression)->_base._dtl[6](self->right_expression) )
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
  CHECK(117, UnaryExpression_write_start(self) )
  CHECK(118, UnaryExpression_write_end(self) )
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
    CHECK(122, write(&(String){2, 1, "("}) )
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
  CHECK(125, write(self->operator->c_name) )
  CHECK(126, write(&(String){2, 1, " "}) )
  CHECK(127, (self->right_expression)->_base._dtl[2](self->right_expression) )
  if (!self->_base.top) {
    CHECK(129, write(&(String){2, 1, ")"}) )
  }
  if (self->_base.is_statement) {
    CHECK(131, write(&(String){3, 2, ";\n"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func UnaryExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func UnaryExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)UnaryExpression_analyze, (void*)UnaryExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)UnaryExpression_write_preactions};
#endif


/* An expression with a binary operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct BinaryExpression BinaryExpression;
#elif MR_STAGE == MR_TYPES(3)
struct BinaryExpression {
  UnaryExpression _base;
  Expression* left_expression;
  BinaryExpression* binary_left_expression;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BinaryExpression_parse_new(BinaryExpression* self, String* ends, Operator* operator, SyntaxTreeCode* code_node, Expression* left_expression, BinaryExpression* binary_left_expression, BinaryExpression** expression, Char* end, Operator** next_operator);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BinaryExpression_parse_new = "BinaryExpression.parse-new";
#define MR_FUNC_NAME _func_name_BinaryExpression_parse_new
Returncode BinaryExpression_parse_new(BinaryExpression* self, String* ends, Operator* operator, SyntaxTreeCode* code_node, Expression* left_expression, BinaryExpression* binary_left_expression, BinaryExpression** expression, Char* end, Operator** next_operator) {
  BinaryExpression* binary_expression = malloc(sizeof(BinaryExpression));
  if (binary_expression == NULL) RAISE(148)
  *binary_expression = (BinaryExpression){BinaryExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL, NULL, NULL, NULL};
  binary_expression->_base._base._base._dtl = BinaryExpression__dtl;
  binary_expression->left_expression = left_expression;
  binary_expression->binary_left_expression = binary_left_expression;
  CHECK(151, UnaryExpression_parse(&(binary_expression->_base), operator, ends, code_node, &((*end)), &((*next_operator))) )
  (*expression) = binary_expression;
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
  CHECK(156, UnaryExpression_analyze_operand(&(self->_base), self->_base.right_expression) )
  CHECK(157, UnaryExpression_analyze_operand(&(self->_base), self->left_expression) )
  if (NULL != self->binary_left_expression && self->_base.operator->order == self->binary_left_expression->_base.operator->order && self->_base.operator->group_index != self->binary_left_expression->_base.operator->group_index) {
    CHECK(162, SyntaxTreeNode_m_syntax_error2(&(self->_base._base._base), &(String){39, 38, "ambiguous precedence between operators"}, self->binary_left_expression->_base.operator->name, &(String){4, 3, "and"}, self->_base.operator->name) )
  }
  if (self->_base.operator->order == 2) {
    /* `not` operator */
    CHECK(169, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){35, 34, "cannot use \"not\" as binary operand"}) )
  }
  if (self->_base.operator->order == 3) {
    /* `or`\`and` operator */
    CHECK(172, BinaryExpression_test_operands_type(self, &(glob->type_bool->_base)) )
    CHECK(173, Expression_set_simple_type(&(self->_base._base), &(glob->type_bool->_base)) )
  }
  else {
    if (self->_base.operator->order == 4 && self->_base.operator->group_index == 0) {
      /* := operator */
      CHECK(176, TypeInstance_check_assign_from(self->left_expression->result_type, &(self->_base._base._base), &(self->_base.right_expression)) )
    }
    else {
      /* any other Int operator */
      if (self->_base.operator->order == 1 &&  NULL !=  self->binary_left_expression && self->binary_left_expression->_base.operator->order == 1) {
        /* (a > b) > c */
        CHECK(183, UnaryExpression_test_operand_type(&(self->_base), self->_base.right_expression, &(glob->type_int->_base)) )
      }
      else {
        CHECK(185, BinaryExpression_test_operands_type(self, &(glob->type_int->_base)) )
      }
      if (self->_base.operator->order == 0) {
        /* aritmetic operator */
        CHECK(188, Expression_set_simple_type(&(self->_base._base), &(glob->type_int->_base)) )
      }
      else {
        if (self->_base.operator->order == 1) {
          /* compare operator */
          CHECK(191, Expression_set_simple_type(&(self->_base._base), &(glob->type_bool->_base)) )
        }
      }
      /* else, assign operator */
    }
  }
  if (self->_base.operator->order == 4) {
    /* assign operator */
    if (!self->left_expression->assignable) {
      CHECK(196, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){41, 40, "assigning into non assignable expression"}) )
    }
    self->left_expression->top = true;
    self->_base.right_expression->top = true;
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
  CHECK(201, UnaryExpression_test_operand_type(&(self->_base), self->_base.right_expression, expected_type) )
  CHECK(202, UnaryExpression_test_operand_type(&(self->_base), self->left_expression, expected_type) )
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
  CHECK(205, UnaryExpression_write_preactions(&(self->_base)) )
  CHECK(206, (self->left_expression)->_base._dtl[6](self->left_expression) )
  
  if (self->_base.operator->order == 4 && self->_base.operator->group_index == 0) {
    /* := operator */
    if (!self->left_expression->result_type->type_data->is_primitive) {
      /* also assign Refman */
      CHECK(212, (self->left_expression)->_base._dtl[4](self->left_expression) )
      CHECK(213, write(&(String){4, 3, " = "}) )
      CHECK(214, (self->_base.right_expression)->_base._dtl[4](self->_base.right_expression) )
      CHECK(215, write(&(String){3, 2, ";\n"}) )
      CHECK(216, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
    }
    if (self->left_expression->result_type->type_data->is_dynamic) {
      /* also assign Dynamic */
      CHECK(219, (self->left_expression)->_base._dtl[3](self->left_expression) )
      CHECK(220, write(&(String){4, 3, " = "}) )
      CHECK(221, (self->_base.right_expression)->_base._dtl[3](self->_base.right_expression) )
      CHECK(222, write(&(String){3, 2, ";\n"}) )
      CHECK(223, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
    }
  }
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
  CHECK(226, UnaryExpression_write_start(&(self->_base)) )
  CHECK(227, (self->left_expression)->_base._dtl[2](self->left_expression) )
  Bool expand_and = self->_base.operator->order == 1 &&  NULL !=  self->binary_left_expression && self->binary_left_expression->_base.operator->order == 1;
  if (expand_and) {
    /* (a > b) > c --> (a > b) && (b > c) */
    CHECK(233, write(&(String){6, 5, " && ("}) )
    CHECK(234, (self->binary_left_expression->_base.right_expression)->_base._dtl[2](self->binary_left_expression->_base.right_expression) )
  }
  CHECK(235, write(&(String){2, 1, " "}) )
  CHECK(236, UnaryExpression_write_end(&(self->_base)) )
  if (expand_and) {
    CHECK(238, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BinaryExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BinaryExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)BinaryExpression_analyze, (void*)BinaryExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)BinaryExpression_write_preactions};
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
  if (question_expression == NULL) RAISE(246)
  *question_expression = (QuestionExpression){QuestionExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL};
  question_expression->_base._base._dtl = QuestionExpression__dtl;
  CHECK(247, QuestionExpression_parse(question_expression, (*expression), &((*end))) )
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
  CHECK(253, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(254, read_c(&((*end))) )
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
  CHECK(257, (self->tested)->_base._dtl[1](self->tested) )
  if (!(NULL != self->tested->result_type)) {
    CHECK(259, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){34, 33, "cannot use \"?\" on void expression"}) )
  }
  if (self->tested->result_type->type_data->is_primitive &&  ! (self->tested->result_type->type_data == &(glob->type_func->_base))) {
    CHECK(262, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){23, 22, "cannot use \"?\" on type"}, self->tested->result_type->type_data->name) )
  }
  CHECK(265, Expression_set_simple_type(&(self->_base), &(glob->type_bool->_base)) )
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
  CHECK(268, (self->tested)->_base._dtl[6](self->tested) )
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
  /* `tested` != NULL && `tested`_Refman->value != NULL */
  if (!self->_base.top) {
    CHECK(273, write(&(String){2, 1, "("}) )
  }
  CHECK(274, write(&(String){3, 2, "!("}) )
  CHECK(275, Expression_write_validate_ref(self->tested) )
  CHECK(276, write(&(String){2, 1, ")"}) )
  if (!self->_base.top) {
    CHECK(278, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func QuestionExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func QuestionExpression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)QuestionExpression_analyze, (void*)QuestionExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)QuestionExpression_write_preactions};
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
