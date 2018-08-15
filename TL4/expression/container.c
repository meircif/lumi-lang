#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "expression/container.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file12_name = "expression/container.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file12_name

/* TL4 compiler - Container expressions */

/* An expression surrounded by brackets */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct BlockExpression BlockExpression;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct BlockExpression {
  Expression _base;
  Expression* expression;
/* parsing `(expression)` */};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BlockExpression_parse_new(BlockExpression* self, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BlockExpression_parse_new = "BlockExpression.parse-new";
#define LUMI_FUNC_NAME _func_name_BlockExpression_parse_new
Returncode BlockExpression_parse_new(BlockExpression* self, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  BlockExpression* block_expression = malloc(sizeof(BlockExpression));
  if (block_expression == NULL) RAISE(9)
  *block_expression = (BlockExpression){BlockExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL};
  block_expression->_base._base._dtl = BlockExpression__dtl;
  CHECK(10, BlockExpression_parse(block_expression, code_node, &((*end))) )
  (*expression) = &(block_expression->_base);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* parsing `(expression)` */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BlockExpression_parse(BlockExpression* self, SyntaxTreeCode* code_node, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BlockExpression_parse = "BlockExpression.parse";
#define LUMI_FUNC_NAME _func_name_BlockExpression_parse
Returncode BlockExpression_parse(BlockExpression* self, SyntaxTreeCode* code_node, Char* end) {
  CHECK(15, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(16, parse_new_expression(&(String){2, 1, ")"}, code_node, &(self->expression), &((*end))) )
  if ((*end) != ')') {
    CHECK(19, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){18, 17, "expected \")\", got"}, (*end)) )
  }
  CHECK(20, read_c(&((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BlockExpression_analyze(BlockExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BlockExpression_analyze = "BlockExpression.analyze";
#define LUMI_FUNC_NAME _func_name_BlockExpression_analyze
Returncode BlockExpression_analyze(BlockExpression* self) {
  CHECK(23, (self->expression)->_base._dtl[2](self->expression) )
  CHECK(24, TypeInstance_copy_new(self->expression->result_type, &(self->_base.result_type)) )
  self->_base.access = self->expression->access;
  self->_base.constant = self->expression->constant;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BlockExpression_m_order_constants(BlockExpression* self, List* ordered_list);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BlockExpression_m_order_constants = "BlockExpression.m-order-constants";
#define LUMI_FUNC_NAME _func_name_BlockExpression_m_order_constants
Returncode BlockExpression_m_order_constants(BlockExpression* self, List* ordered_list) {
  CHECK(29, (self->expression)->_base._dtl[3](self->expression, ordered_list) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BlockExpression_write_preactions(BlockExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BlockExpression_write_preactions = "BlockExpression.write-preactions";
#define LUMI_FUNC_NAME _func_name_BlockExpression_write_preactions
Returncode BlockExpression_write_preactions(BlockExpression* self) {
  CHECK(32, (self->expression)->_base._dtl[9](self->expression) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BlockExpression_write(BlockExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BlockExpression_write = "BlockExpression.write";
#define LUMI_FUNC_NAME _func_name_BlockExpression_write
Returncode BlockExpression_write(BlockExpression* self) {
  if (!self->_base.top) {
    CHECK(36, write(&(String){2, 1, "("}) )
  }
  CHECK(37, (self->expression)->_base._dtl[4](self->expression) )
  if (!self->_base.top) {
    CHECK(39, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func BlockExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func BlockExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)BlockExpression_analyze, (void*)BlockExpression_m_order_constants, (void*)BlockExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)BlockExpression_write_preactions};
#endif


#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct Operator Operator;
#elif LUMI_STAGE == LUMI_TYPES(0)
struct Operator {
  String* name;
  String* c_name;
  Int order;
  Int group_index;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Operator_init(Operator* self, String* name, String* c_name, Int order, Int group_index);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Operator_init = "Operator.init";
#define LUMI_FUNC_NAME _func_name_Operator_init
Returncode Operator_init(Operator* self, String* name, String* c_name, Int order, Int group_index) {
  CHECK(53, string_new_copy(name, &(self->name)) )
  CHECK(54, string_new_copy(c_name, &(self->c_name)) )
  self->order = order;
  self->group_index = group_index;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* An expression with an unary operator */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct UnaryExpression UnaryExpression;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct UnaryExpression {
  Expression _base;
  Operator* operator;
  Expression* right_expression;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UnaryExpression_parse_new(UnaryExpression* self, String* ends, Operator* operator, SyntaxTreeCode* code_node, Expression** expression, Char* end, Operator** next_operator);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UnaryExpression_parse_new = "UnaryExpression.parse-new";
#define LUMI_FUNC_NAME _func_name_UnaryExpression_parse_new
Returncode UnaryExpression_parse_new(UnaryExpression* self, String* ends, Operator* operator, SyntaxTreeCode* code_node, Expression** expression, Char* end, Operator** next_operator) {
  UnaryExpression* unary_expression = malloc(sizeof(UnaryExpression));
  if (unary_expression == NULL) RAISE(67)
  *unary_expression = (UnaryExpression){UnaryExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL};
  unary_expression->_base._base._dtl = UnaryExpression__dtl;
  CHECK(68, UnaryExpression_parse(unary_expression, operator, ends, code_node, &((*end)), &((*next_operator))) )
  (*expression) = &(unary_expression->_base);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UnaryExpression_parse(UnaryExpression* self, Operator* operator, String* ends, SyntaxTreeCode* code_node, Char* end, Operator** next_operator);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UnaryExpression_parse = "UnaryExpression.parse";
#define LUMI_FUNC_NAME _func_name_UnaryExpression_parse
Returncode UnaryExpression_parse(UnaryExpression* self, Operator* operator, String* ends, SyntaxTreeCode* code_node, Char* end, Operator** next_operator) {
  self->operator = operator;
  self->_base.code_node = code_node;
  self->_base.access = ACCESS_VAR;
  CHECK(80, SyntaxTreeNode_set_location(&(self->_base._base)) )
  if ((*end) == '\n') {
    CHECK(82, SyntaxTreeCode_read_parent_line_break_spaces(code_node) )
  }
  else {
    if ((*end) != ' ') {
      CHECK(84, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){35, 34, "expected space after operator, got"}, (*end)) )
    }
  }
  CHECK(85, Expression_parse_new(NULL, ends, code_node, operator, &(self->right_expression), &((*end)), &((*next_operator))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UnaryExpression_analyze(UnaryExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UnaryExpression_analyze = "UnaryExpression.analyze";
#define LUMI_FUNC_NAME _func_name_UnaryExpression_analyze
Returncode UnaryExpression_analyze(UnaryExpression* self) {
  CHECK(89, UnaryExpression_analyze_operand(self, self->right_expression) )
  self->_base.constant = self->right_expression->constant;
  if (self->operator->order == 2) {
    /* `not` operator */
    CHECK(93, UnaryExpression_test_operand_type(self, self->right_expression, glob->type_bool) )
    CHECK(94, Expression_set_simple_type(&(self->_base), glob->type_bool) )
  }
  else {
    Bool _Bool44;
    CHECK(95, String_equal(self->operator->name, &(String){2, 1, "-"}, &(_Bool44)) )
    if (_Bool44) {
      CHECK(96, UnaryExpression_test_operand_type(self, self->right_expression, glob->type_int) )
      CHECK(97, Expression_set_simple_type(&(self->_base), glob->type_int) )
    }
    else {
      CHECK(99, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){19, 18, "not unary operator"}, self->operator->name) )
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UnaryExpression_analyze_operand(UnaryExpression* self, Expression* operand);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UnaryExpression_analyze_operand = "UnaryExpression.analyze-operand";
#define LUMI_FUNC_NAME _func_name_UnaryExpression_analyze_operand
Returncode UnaryExpression_analyze_operand(UnaryExpression* self, Expression* operand) {
  CHECK(102, (operand)->_base._dtl[2](operand) )
  if (!(NULL != operand->result_type)) {
    CHECK(104, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){45, 44, "void expression given as operand to operator"}, self->operator->name) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UnaryExpression_test_operand_type(UnaryExpression* self, Expression* operand, TypeData* expected_type);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UnaryExpression_test_operand_type = "UnaryExpression.test-operand-type";
#define LUMI_FUNC_NAME _func_name_UnaryExpression_test_operand_type
Returncode UnaryExpression_test_operand_type(UnaryExpression* self, Expression* operand, TypeData* expected_type) {
  Bool _Bool45;
  CHECK(111, TypeData_m_is_same(expected_type, operand->result_type->type_data, &(_Bool45)) )
  if (!_Bool45) {
    CHECK(112, SyntaxTreeNode_m_syntax_error3(&(self->_base._base), &(String){9, 8, "operator"}, self->operator->name, &(String){9, 8, "expected"}, expected_type->name, &(String){13, 12, "operand, got"}, operand->result_type->type_data->name) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UnaryExpression_m_order_constants(UnaryExpression* self, List* ordered_list);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UnaryExpression_m_order_constants = "UnaryExpression.m-order-constants";
#define LUMI_FUNC_NAME _func_name_UnaryExpression_m_order_constants
Returncode UnaryExpression_m_order_constants(UnaryExpression* self, List* ordered_list) {
  CHECK(121, (self->right_expression)->_base._dtl[3](self->right_expression, ordered_list) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UnaryExpression_write_preactions(UnaryExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UnaryExpression_write_preactions = "UnaryExpression.write-preactions";
#define LUMI_FUNC_NAME _func_name_UnaryExpression_write_preactions
Returncode UnaryExpression_write_preactions(UnaryExpression* self) {
  CHECK(124, (self->right_expression)->_base._dtl[9](self->right_expression) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UnaryExpression_write(UnaryExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UnaryExpression_write = "UnaryExpression.write";
#define LUMI_FUNC_NAME _func_name_UnaryExpression_write
Returncode UnaryExpression_write(UnaryExpression* self) {
  CHECK(127, UnaryExpression_write_start(self) )
  CHECK(128, UnaryExpression_write_end(self) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UnaryExpression_write_start(UnaryExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UnaryExpression_write_start = "UnaryExpression.write-start";
#define LUMI_FUNC_NAME _func_name_UnaryExpression_write_start
Returncode UnaryExpression_write_start(UnaryExpression* self) {
  if (!self->_base.top) {
    CHECK(132, write(&(String){2, 1, "("}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UnaryExpression_write_end(UnaryExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UnaryExpression_write_end = "UnaryExpression.write-end";
#define LUMI_FUNC_NAME _func_name_UnaryExpression_write_end
Returncode UnaryExpression_write_end(UnaryExpression* self) {
  CHECK(135, UnaryExpression_write_end_expression(self, self->right_expression) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UnaryExpression_write_end_expression(UnaryExpression* self, Expression* right_expression);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UnaryExpression_write_end_expression = "UnaryExpression.write-end-expression";
#define LUMI_FUNC_NAME _func_name_UnaryExpression_write_end_expression
Returncode UnaryExpression_write_end_expression(UnaryExpression* self, Expression* right_expression) {
  CHECK(138, write(self->operator->c_name) )
  CHECK(139, write(&(String){2, 1, " "}) )
  CHECK(140, UnaryExpression_write_operand(self, right_expression) )
  if (!self->_base.top) {
    CHECK(142, write(&(String){2, 1, ")"}) )
  }
  if (self->_base.is_statement) {
    CHECK(144, write(&(String){3, 2, ";\n"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode UnaryExpression_write_operand(UnaryExpression* self, Expression* expression);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_UnaryExpression_write_operand = "UnaryExpression.write-operand";
#define LUMI_FUNC_NAME _func_name_UnaryExpression_write_operand
Returncode UnaryExpression_write_operand(UnaryExpression* self, Expression* expression) {
  if (expression->is_complex_field) {
    CHECK(148, Expression_write_as_top(expression) )
  }
  else {
    CHECK(150, (expression)->_base._dtl[4](expression) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func UnaryExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func UnaryExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)UnaryExpression_analyze, (void*)UnaryExpression_m_order_constants, (void*)UnaryExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)UnaryExpression_write_preactions};
#endif


/* An expression with a binary operator */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct BinaryExpression BinaryExpression;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct BinaryExpression {
  UnaryExpression _base;
  Expression* left_expression;
  BinaryExpression* binary_left_expression;
  Expression* assignee;
  SymbolExpression* assigned_value_symbol;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BinaryExpression_parse_new(BinaryExpression* self, String* ends, Operator* operator, SyntaxTreeCode* code_node, Expression* left_expression, BinaryExpression* binary_left_expression, BinaryExpression** expression, Char* end, Operator** next_operator);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BinaryExpression_parse_new = "BinaryExpression.parse-new";
#define LUMI_FUNC_NAME _func_name_BinaryExpression_parse_new
Returncode BinaryExpression_parse_new(BinaryExpression* self, String* ends, Operator* operator, SyntaxTreeCode* code_node, Expression* left_expression, BinaryExpression* binary_left_expression, BinaryExpression** expression, Char* end, Operator** next_operator) {
  BinaryExpression* binary_expression = malloc(sizeof(BinaryExpression));
  if (binary_expression == NULL) RAISE(169)
  *binary_expression = (BinaryExpression){BinaryExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL, NULL, NULL};
  binary_expression->_base._base._base._dtl = BinaryExpression__dtl;
  binary_expression->left_expression = left_expression;
  binary_expression->binary_left_expression = binary_left_expression;
  CHECK(172, UnaryExpression_parse(&(binary_expression->_base), operator, ends, code_node, &((*end)), &((*next_operator))) )
  (*expression) = binary_expression;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BinaryExpression_analyze(BinaryExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BinaryExpression_analyze = "BinaryExpression.analyze";
#define LUMI_FUNC_NAME _func_name_BinaryExpression_analyze
Returncode BinaryExpression_analyze(BinaryExpression* self) {
  CHECK(177, UnaryExpression_analyze_operand(&(self->_base), self->_base.right_expression) )
  CHECK(178, UnaryExpression_analyze_operand(&(self->_base), self->left_expression) )
  self->_base._base.constant = self->left_expression->constant && self->_base.right_expression->constant;
  if (NULL != self->binary_left_expression && self->_base.operator->order == self->binary_left_expression->_base.operator->order && self->_base.operator->group_index != self->binary_left_expression->_base.operator->group_index) {
    CHECK(185, SyntaxTreeNode_m_syntax_error2(&(self->_base._base._base), &(String){39, 38, "ambiguous precedence between operators"}, self->binary_left_expression->_base.operator->name, &(String){4, 3, "and"}, self->_base.operator->name) )
  }
  if (self->_base.operator->order == 2) {
    /* `not` operator */
    CHECK(192, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){35, 34, "cannot use \"not\" as binary operand"}) )
  }
  if (self->_base.operator->order == 3) {
    /* `or`/`and` operator */
    CHECK(195, BinaryExpression_test_operands_type(self, glob->type_bool) )
    CHECK(196, Expression_set_simple_type(&(self->_base._base), glob->type_bool) )
  }
  else {
    if (self->_base.operator->order == 4 && self->_base.operator->group_index == 0) {
      /* := operator */
      CHECK(199, TypeInstance_check_assign_from(self->left_expression->result_type, self->left_expression->access, &(self->_base._base._base), &(self->_base.right_expression), &(self->assignee)) )
      if (self->left_expression->access == ACCESS_USER) {
        SyntaxTreeFunction* _SyntaxTreeFunction46;
        CHECK(203, SyntaxTreeCode_get_function(self->_base._base.code_node, &(_SyntaxTreeFunction46)) )
        _SyntaxTreeFunction46->has_user_assign = true;
      }
      else {
        if (self->left_expression->access == ACCESS_OWNER) {
          /* ownership pass */
          CHECK(206, Expression_add_aux_variable(&(self->_base._base), ACCESS_OWNER, false, self->left_expression->result_type, &(self->assigned_value_symbol)) )
        }
      }
    }
    else {
      if ((0) < 0 || (0) >= (self->_base.operator->name)->length) RAISE(211)
      if (self->_base.operator->order == 1 && ((self->_base.operator->name)->values[0]) == 'i') {
        /* `is`/`is-not` operator */
        CHECK(213, BinaryExpression_analyze_equalizer(self, true) )
      }
      else {
        Bool _Bool47;
        CHECK(214, String_equal(self->_base.operator->name, &(String){2, 1, "="}, &(_Bool47)) )
        Bool _Bool48;
        CHECK(214, String_equal(self->_base.operator->name, &(String){3, 2, "!="}, &(_Bool48)) )
        if (_Bool47 || _Bool48) {
          CHECK(216, BinaryExpression_analyze_equalizer(self, false) )
        }
        else {
          /* any other Int operator */
          if (self->_base.operator->order == 1 &&  NULL !=  self->binary_left_expression && self->binary_left_expression->_base.operator->order == 1) {
            /* (a > b) > c */
            CHECK(222, UnaryExpression_test_operand_type(&(self->_base), self->_base.right_expression, glob->type_int) )
          }
          else {
            CHECK(224, BinaryExpression_test_operands_type(self, glob->type_int) )
          }
          if (self->_base.operator->order == 0) {
            /* aritmetic operator */
            CHECK(227, Expression_set_simple_type(&(self->_base._base), glob->type_int) )
          }
          else {
            if (self->_base.operator->order == 1) {
              /* compare operator */
              CHECK(230, Expression_set_simple_type(&(self->_base._base), glob->type_bool) )
            }
          }
          /* else, assign operator */
        }
      }
    }
  }
  if (self->_base.operator->order == 4) {
    /* assign operator */
    if (!self->left_expression->assignable) {
      CHECK(235, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){41, 40, "assigning into non assignable expression"}) )
    }
    self->left_expression->top = true;
    self->_base.right_expression->top = true;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BinaryExpression_test_operands_type(BinaryExpression* self, TypeData* expected_type);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BinaryExpression_test_operands_type = "BinaryExpression.test-operands-type";
#define LUMI_FUNC_NAME _func_name_BinaryExpression_test_operands_type
Returncode BinaryExpression_test_operands_type(BinaryExpression* self, TypeData* expected_type) {
  CHECK(240, UnaryExpression_test_operand_type(&(self->_base), self->_base.right_expression, expected_type) )
  CHECK(241, UnaryExpression_test_operand_type(&(self->_base), self->left_expression, expected_type) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BinaryExpression_analyze_equalizer(BinaryExpression* self, Bool is_reference);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BinaryExpression_analyze_equalizer = "BinaryExpression.analyze-equalizer";
#define LUMI_FUNC_NAME _func_name_BinaryExpression_analyze_equalizer
Returncode BinaryExpression_analyze_equalizer(BinaryExpression* self, Bool is_reference) {
  CHECK(244, BinaryExpression_test_is_reference(self, is_reference, self->_base.right_expression) )
  CHECK(245, BinaryExpression_test_is_reference(self, is_reference, self->left_expression) )
  CHECK(246, Expression_set_simple_type(&(self->_base._base), glob->type_bool) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BinaryExpression_test_is_reference(BinaryExpression* self, Bool is_reference, Expression* operand);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BinaryExpression_test_is_reference = "BinaryExpression.test-is-reference";
#define LUMI_FUNC_NAME _func_name_BinaryExpression_test_is_reference
Returncode BinaryExpression_test_is_reference(BinaryExpression* self, Bool is_reference, Expression* operand) {
  if ((!operand->result_type->type_data->is_primitive || operand->result_type->type_data == glob->type_func || operand->result_type->type_data == glob->type_ref) != is_reference) {
    CHECK(252, SyntaxTreeNode_m_syntax_error2(&(self->_base._base._base), &(String){9, 8, "operator"}, self->_base.operator->name, &(String){26, 25, "is not supported for type"}, operand->result_type->type_data->name) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BinaryExpression_m_order_constants(BinaryExpression* self, List* ordered_list);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BinaryExpression_m_order_constants = "BinaryExpression.m-order-constants";
#define LUMI_FUNC_NAME _func_name_BinaryExpression_m_order_constants
Returncode BinaryExpression_m_order_constants(BinaryExpression* self, List* ordered_list) {
  CHECK(259, (self->left_expression)->_base._dtl[3](self->left_expression, ordered_list) )
  CHECK(260, UnaryExpression_m_order_constants(&(self->_base), ordered_list) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BinaryExpression_write_preactions(BinaryExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BinaryExpression_write_preactions = "BinaryExpression.write-preactions";
#define LUMI_FUNC_NAME _func_name_BinaryExpression_write_preactions
Returncode BinaryExpression_write_preactions(BinaryExpression* self) {
  CHECK(263, UnaryExpression_write_preactions(&(self->_base)) )
  CHECK(264, (self->left_expression)->_base._dtl[9](self->left_expression) )
  if (self->_base.operator->order == 4 && self->_base.operator->group_index == 0) {
    /* := operator */
    CHECK(267, BinaryExpression_write_assign_preactions(self) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BinaryExpression_write_assign_preactions(BinaryExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BinaryExpression_write_assign_preactions = "BinaryExpression.write-assign-preactions";
#define LUMI_FUNC_NAME _func_name_BinaryExpression_write_assign_preactions
Returncode BinaryExpression_write_assign_preactions(BinaryExpression* self) {
  if (!self->left_expression->result_type->type_data->is_primitive) {
    if (self->left_expression->access == ACCESS_OWNER) {
      CHECK(272, BinaryExpression_write_owner_assign_preactions(self) )
    }
    else {
      CHECK(274, BinaryExpression_write_user_assign_preactions(self) )
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BinaryExpression_write_user_assign_preactions(BinaryExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BinaryExpression_write_user_assign_preactions = "BinaryExpression.write-user-assign-preactions";
#define LUMI_FUNC_NAME _func_name_BinaryExpression_write_user_assign_preactions
Returncode BinaryExpression_write_user_assign_preactions(BinaryExpression* self) {
  CHECK(277, write(&(String){19, 18, "aux_Ref_Manager = "}) )
  CHECK(278, (self->left_expression)->_base._dtl[6](self->left_expression) )
  CHECK(279, write(&(String){3, 2, ";\n"}) )
  CHECK(280, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  
  CHECK(282, (self->left_expression)->_base._dtl[6](self->left_expression) )
  CHECK(283, write(&(String){4, 3, " = "}) )
  CHECK(284, (self->_base.right_expression)->_base._dtl[6](self->_base.right_expression) )
  CHECK(285, write(&(String){3, 2, ";\n"}) )
  CHECK(286, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  
  CHECK(288, BinaryExpression_assign_dynamic(self, self->left_expression, self->_base.right_expression) )
  
  CHECK(290, write(&(String){14, 13, "LUMI_inc_ref("}) )
  CHECK(291, (self->left_expression)->_base._dtl[6](self->left_expression) )
  CHECK(292, write(&(String){4, 3, ");\n"}) )
  CHECK(293, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  
  CHECK(295, write(&(String){32, 31, "LUMI_dec_ref(aux_Ref_Manager);\n"}) )
  CHECK(296, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  CHECK(297, write(&(String){25, 24, "aux_Ref_Manager = NULL;\n"}) )
  CHECK(298, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BinaryExpression_write_owner_assign_preactions(BinaryExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BinaryExpression_write_owner_assign_preactions = "BinaryExpression.write-owner-assign-preactions";
#define LUMI_FUNC_NAME _func_name_BinaryExpression_write_owner_assign_preactions
Returncode BinaryExpression_write_owner_assign_preactions(BinaryExpression* self) {
  CHECK(301, (self->assigned_value_symbol)->_base._base._dtl[4](self->assigned_value_symbol) )
  CHECK(302, write(&(String){4, 3, " = "}) )
  CHECK(303, (self->_base.right_expression)->_base._dtl[4](self->_base.right_expression) )
  CHECK(304, write(&(String){3, 2, ";\n"}) )
  CHECK(305, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  CHECK(306, (self->assigned_value_symbol)->_base._base._dtl[6](self->assigned_value_symbol) )
  CHECK(307, write(&(String){4, 3, " = "}) )
  CHECK(308, (self->_base.right_expression)->_base._dtl[6](self->_base.right_expression) )
  CHECK(309, write(&(String){3, 2, ";\n"}) )
  CHECK(310, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  
  CHECK(312, BinaryExpression_assign_dynamic(self, &(self->assigned_value_symbol->_base), self->_base.right_expression) )
  
  if (self->_base.right_expression->result_type->type_data != glob->type_empty) {
    CHECK(316, Expression_write_assign_null(self->assignee) )
    CHECK(317, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  }
  CHECK(318, BinaryExpression_write_left_delete(self) )
  CHECK(319, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  
  CHECK(321, write(&(String){20, 19, "LUMI_owner_dec_ref("}) )
  CHECK(322, (self->left_expression)->_base._dtl[6](self->left_expression) )
  CHECK(323, write(&(String){4, 3, ");\n"}) )
  CHECK(324, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  
  CHECK(326, (self->left_expression)->_base._dtl[6](self->left_expression) )
  CHECK(327, write(&(String){4, 3, " = "}) )
  CHECK(328, (self->assigned_value_symbol)->_base._base._dtl[6](self->assigned_value_symbol) )
  CHECK(329, write(&(String){3, 2, ";\n"}) )
  CHECK(330, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  
  CHECK(332, BinaryExpression_assign_dynamic(self, self->left_expression, &(self->assigned_value_symbol->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BinaryExpression_assign_dynamic(BinaryExpression* self, Expression* target, Expression* source);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BinaryExpression_assign_dynamic = "BinaryExpression.assign-dynamic";
#define LUMI_FUNC_NAME _func_name_BinaryExpression_assign_dynamic
Returncode BinaryExpression_assign_dynamic(BinaryExpression* self, Expression* target, Expression* source) {
  if (!target->result_type->type_data->is_dynamic &&  ! target->is_generic_cast) {
    return OK;
  }
  CHECK(339, (target)->_base._dtl[5](target) )
  CHECK(340, write(&(String){4, 3, " = "}) )
  if (!source->result_type->type_data->is_dynamic &&  ! source->is_generic_cast && source->result_type->type_data != glob->type_empty) {
    CHECK(344, write(&(String){2, 1, "&"}) )
    CHECK(345, TypeData_write_cname(source->result_type->type_data) )
    CHECK(346, write(&(String){9, 8, "_dynamic"}) )
  }
  else {
    if ((target->result_type->type_data == glob->type_generic || target->is_generic_cast) && source->result_type->type_data != glob->type_generic &&  ! source->is_generic_cast) {
      CHECK(352, write(&(String){24, 23, "(Generic_Type_Dynamic*)"}) )
      source->top = false;
    }
    else {
      if (source->is_generic_cast &&  ! target->is_generic_cast &&  ! (target->result_type->type_data == glob->type_generic)) {
        source->top = false;
      }
    }
    CHECK(357, (source)->_base._dtl[5](source) )
    source->top = true;
  }
  CHECK(359, write(&(String){3, 2, ";\n"}) )
  CHECK(360, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BinaryExpression_write_left_delete(BinaryExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BinaryExpression_write_left_delete = "BinaryExpression.write-left-delete";
#define LUMI_FUNC_NAME _func_name_BinaryExpression_write_left_delete
Returncode BinaryExpression_write_left_delete(BinaryExpression* self) {
  TypeData* type_data = self->left_expression->result_type->type_data;
  if (type_data->is_dynamic) {
    CHECK(365, write(&(String){5, 4, "if ("}) )
    CHECK(366, (self->left_expression)->_base._dtl[5](self->left_expression) )
    CHECK(367, write(&(String){11, 10, " != NULL) "}) )
    self->left_expression->top = false;
    CHECK(369, (self->left_expression)->_base._dtl[5](self->left_expression) )
    self->left_expression->top = true;
    CHECK(371, write(&(String){3, 2, "->"}) )
    while (true) {
      if (!(NULL != type_data->base_type)) break;
      type_data = type_data->base_type->type_data;
      if (!(type_data->is_dynamic)) break;
      CHECK(376, write(&(String){7, 6, "_base."}) )
    }
    CHECK(377, write(&(String){6, 5, "_del("}) )
  }
  else {
    if (type_data != glob->type_array) {
      CHECK(379, TypeData_write_cname(type_data) )
      CHECK(380, write(&(String){6, 5, "_Del("}) )
    }
    else {
      type_data = ((TypeInstance*)(self->left_expression->result_type->parameters->first->item))->type_data;
      if (!type_data->is_primitive) {
        CHECK(385, write(&(String){11, 10, "ARRAY_DEL("}) )
        CHECK(386, TypeData_write_cname(type_data) )
        CHECK(387, write(&(String){3, 2, ", "}) )
        CHECK(388, (self->left_expression)->_base._dtl[4](self->left_expression) )
        CHECK(389, write(&(String){3, 2, ")\n"}) )
      }
      return OK;
    }
  }
  CHECK(391, (self->left_expression)->_base._dtl[4](self->left_expression) )
  CHECK(392, write(&(String){4, 3, ");\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode BinaryExpression_write(BinaryExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_BinaryExpression_write = "BinaryExpression.write";
#define LUMI_FUNC_NAME _func_name_BinaryExpression_write
Returncode BinaryExpression_write(BinaryExpression* self) {
  CHECK(395, UnaryExpression_write_start(&(self->_base)) )
  if ((0) < 0 || (0) >= (self->_base.operator->name)->length) RAISE(396)
  if (self->_base.operator->order == 1 && ((self->_base.operator->name)->values[0]) == 'i') {
    /* `is`/`is-not` operator */
    CHECK(398, write(&(String){8, 7, "(void*)"}) )
    self->left_expression->top = false;
  }
  CHECK(400, UnaryExpression_write_operand(&(self->_base), self->left_expression) )
  self->left_expression->top = true;
  Bool expand_and = self->_base.operator->order == 1 &&  NULL !=  self->binary_left_expression && self->binary_left_expression->_base.operator->order == 1;
  if (expand_and) {
    /* (a > b) > c --> (a > b) && (b > c) */
    CHECK(407, write(&(String){6, 5, " && ("}) )
    CHECK(408, (self->binary_left_expression->_base.right_expression)->_base._dtl[4](self->binary_left_expression->_base.right_expression) )
  }
  CHECK(409, write(&(String){2, 1, " "}) )
  if (self->_base.operator->order == 4 && self->_base.operator->group_index == 0 && self->left_expression->access == ACCESS_OWNER) {
    CHECK(412, UnaryExpression_write_end_expression(&(self->_base), &(self->assigned_value_symbol->_base)) )
    CHECK(413, SyntaxTreeCode_write_spaces(self->_base._base.code_node) )
    CHECK(414, Expression_write_assign_null(&(self->assigned_value_symbol->_base)) )
  }
  else {
    CHECK(416, UnaryExpression_write_end(&(self->_base)) )
  }
  if (expand_and) {
    CHECK(418, write(&(String){2, 1, ")"}) )
  }
  
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func BinaryExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func BinaryExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)BinaryExpression_analyze, (void*)BinaryExpression_m_order_constants, (void*)BinaryExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)BinaryExpression_write_preactions};
#endif

/* An expression with the "?" operator */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct QuestionExpression QuestionExpression;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct QuestionExpression {
  Expression _base;
  Expression* tested;
/* parsing `tested?` */};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode QuestionExpression_parse_new(QuestionExpression* self, Expression** expression, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_QuestionExpression_parse_new = "QuestionExpression.parse-new";
#define LUMI_FUNC_NAME _func_name_QuestionExpression_parse_new
Returncode QuestionExpression_parse_new(QuestionExpression* self, Expression** expression, Char* end) {
  QuestionExpression* question_expression = malloc(sizeof(QuestionExpression));
  if (question_expression == NULL) RAISE(426)
  *question_expression = (QuestionExpression){QuestionExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL};
  question_expression->_base._base._dtl = QuestionExpression__dtl;
  CHECK(427, QuestionExpression_parse(question_expression, (*expression), &((*end))) )
  (*expression) = &(question_expression->_base);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* parsing `tested?` */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode QuestionExpression_parse(QuestionExpression* self, Expression* tested, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_QuestionExpression_parse = "QuestionExpression.parse";
#define LUMI_FUNC_NAME _func_name_QuestionExpression_parse
Returncode QuestionExpression_parse(QuestionExpression* self, Expression* tested, Char* end) {
  self->tested = tested;
  CHECK(433, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(434, read_c(&((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode QuestionExpression_analyze(QuestionExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_QuestionExpression_analyze = "QuestionExpression.analyze";
#define LUMI_FUNC_NAME _func_name_QuestionExpression_analyze
Returncode QuestionExpression_analyze(QuestionExpression* self) {
  CHECK(437, (self->tested)->_base._dtl[2](self->tested) )
  if (!(NULL != self->tested->result_type)) {
    CHECK(439, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){34, 33, "cannot use \"?\" on void expression"}) )
  }
  if (self->tested->result_type->type_data->is_primitive &&  ! (self->tested->result_type->type_data == glob->type_func)) {
    CHECK(442, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){23, 22, "cannot use \"?\" on type"}, self->tested->result_type->type_data->name) )
  }
  if (self->tested->is_complex_field) {
    CHECK(446, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){32, 31, "cannot use \"?\" on complex field"}) )
  }
  CHECK(447, Expression_set_simple_type(&(self->_base), glob->type_bool) )
  self->_base.access = ACCESS_VAR;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode QuestionExpression_write_preactions(QuestionExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_QuestionExpression_write_preactions = "QuestionExpression.write-preactions";
#define LUMI_FUNC_NAME _func_name_QuestionExpression_write_preactions
Returncode QuestionExpression_write_preactions(QuestionExpression* self) {
  CHECK(451, (self->tested)->_base._dtl[9](self->tested) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode QuestionExpression_write(QuestionExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_QuestionExpression_write = "QuestionExpression.write";
#define LUMI_FUNC_NAME _func_name_QuestionExpression_write
Returncode QuestionExpression_write(QuestionExpression* self) {
  /* `tested` != NULL && `tested`_Refman->value != NULL */
  if (!self->_base.top) {
    CHECK(456, write(&(String){2, 1, "("}) )
  }
  CHECK(457, (self->tested)->_base._dtl[4](self->tested) )
  CHECK(458, write(&(String){9, 8, " != NULL"}) )
  if (!self->tested->result_type->type_data->is_primitive) {
    CHECK(460, write(&(String){5, 4, " && "}) )
    CHECK(461, (self->tested)->_base._dtl[6](self->tested) )
    CHECK(462, write(&(String){16, 15, "->value != NULL"}) )
  }
  if (!self->_base.top) {
    CHECK(464, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func QuestionExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func QuestionExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)QuestionExpression_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)QuestionExpression_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)QuestionExpression_write_preactions};
#endif

#undef LUMI_FILE_NAME

#ifndef LUMI_INCLUDES
#define LUMI_INCLUDES
#include "tl4-compiler.c"
#include "global/argument.c"
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "global/type-instance.c"
#include "expression/base-type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/expression.c"
#include "expression/initialize.c"
#include "expression/slice.c"
#include "expression/symbol.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "statement/enum.c"
#include "statement/error.c"
#include "statement/for.c"
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
#include "statement/type.c"
#include "statement/variable.c"
#if LUMI_STAGE == LUMI_TYPES(1)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(2)
#elif LUMI_STAGE == LUMI_TYPES(2)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(3)
#elif LUMI_STAGE == LUMI_TYPES(3)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(4)
#elif LUMI_STAGE == LUMI_TYPES(4)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(5)
#endif
#undef LUMI_INCLUDES
#endif

#endif
