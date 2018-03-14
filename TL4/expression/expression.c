#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "expression/expression.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file12_name = "expression/expression.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file12_name

/*  TL4 compiler - Expression

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
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode parse_new_expression(String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_parse_new_expression = "parse-new-expression";
#define LUMI_FUNC_NAME _func_name_parse_new_expression
Returncode parse_new_expression(String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  Operator* _Operator42;
  CHECK(23, Expression_parse_new(NULL, ends, code_node, NULL, &((*expression)), &((*end)), &(_Operator42)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* Meta type for an expression in the language. */
/* Currently only the parsing is fully implemented, `write` is implemented only */
/* for testing. */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct Expression Expression;
#elif LUMI_STAGE == LUMI_TYPES(1)
struct Expression {
  SyntaxTreeNode _base;
  SyntaxTreeCode* code_node;
  TypeInstance* result_type;
  Int access;
  Bool assignable;
  Bool top;
  Bool constant;
  Bool is_statement;
  Bool is_generic_cast;
  Bool is_complex_field;
/* Parse any expression *//* Read a single expression value as new string *//* Parse an expression that is an operand *//* Parse the initialize part of an operand expression *//* Parse one following part of an operand *//* Set type instance to be a type that has no sub-type */};
#endif/* Parse any expression */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_parse_new(Expression* self, String* ends, SyntaxTreeCode* code_node, Operator* curr_operator, Expression** expression, Char* end, Operator** operator);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_parse_new = "Expression.parse-new";
#define LUMI_FUNC_NAME _func_name_Expression_parse_new
Returncode Expression_parse_new(Expression* self, String* ends, SyntaxTreeCode* code_node, Operator* curr_operator, Expression** expression, Char* end, Operator** operator) {
  (*expression) = NULL;
  String* text = NULL;
  CHECK(51, Expression_read_new_value(self, ends, &(text), &((*end))) )
  CHECK(52, NameMap_find(glob->operator_map, text, (void**)&((*operator))) )
  if (NULL != (*operator)) {
    CHECK(54, UnaryExpression_parse_new(NULL, ends, (*operator), code_node, &((*expression)), &((*end)), &((*operator))) )
  }
  else {
    CHECK(58, Expression_parse_new_operand(self, text, ends, code_node, &((*expression)), &((*end))) )
    if ((*end) == ' ') {
      CHECK(61, Expression_read_new_value(self, ends, &(text), &((*end))) )
      CHECK(62, NameMap_find(glob->operator_map, text, (void**)&((*operator))) )
      if (!(NULL != (*operator))) {
        CHECK(64, SyntaxTreeNode_m_syntax_error(&(code_node->_base), &(String){17, 16, "unknown operator"}, text) )
      }
    }
  }
  BinaryExpression* binary_left_expression = NULL;
  while (true) {
    if (!(NULL != (*operator) && (!(NULL != curr_operator) || (*operator)->order < curr_operator->order))) break;
    BinaryExpression* new_binary_expression = NULL;
    CHECK(70, BinaryExpression_parse_new(NULL, ends, (*operator), code_node, (*expression), binary_left_expression, &(new_binary_expression), &((*end)), &((*operator))) )
    binary_left_expression = new_binary_expression;
    (*expression) = &(new_binary_expression->_base._base);
  }
  if (!(NULL != curr_operator)) {
    (*expression)->top = true;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* Read a single expression value as new string */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_read_new_value(Expression* self, String* ends, String** text, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_read_new_value = "Expression.read-new-value";
#define LUMI_FUNC_NAME _func_name_Expression_read_new_value
Returncode Expression_read_new_value(Expression* self, String* ends, String** text, Char* end) {
  String* all_ends = NULL;
  CHECK(88, string_new_concat(&(String){7, 6, " .[({?"}, ends, &(all_ends)) )
  CHECK(89, read_new(all_ends, &((*text)), &((*end))) )
  free(all_ends);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* Parse an expression that is an operand */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_parse_new_operand(Expression* self, String* text, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_parse_new_operand = "Expression.parse-new-operand";
#define LUMI_FUNC_NAME _func_name_Expression_parse_new_operand
Returncode Expression_parse_new_operand(Expression* self, String* text, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  if (text->length == 0) {
    if ((*end) == '(') {
      CHECK(98, BlockExpression_parse_new(NULL, code_node, &((*expression)), &((*end))) )
    }
    else {
      CHECK(101, SyntaxTreeNode_m_syntax_error_c(&(code_node->_base), &(String){11, 10, "unexpected"}, (*end)) )
    }
    free(text);
  }
  else {
    CHECK(104, Expression_parse_new_init_operand(self, text, ends, code_node, &((*expression)), &((*end))) )
  }
  
  while (true) {
    if ((*end) == '?') {
      CHECK(109, QuestionExpression_parse_new(NULL, &((*expression)), &((*end))) )
    }
    Bool _Bool43;
    CHECK(110, Expression_parse_new_follow_operand(self, ends, code_node, &((*expression)), &((*end)), &(_Bool43)) )
    if (!(_Bool43)) break;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* Parse the initialize part of an operand expression */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_parse_new_init_operand(Expression* self, String* text, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_parse_new_init_operand = "Expression.parse-new-init-operand";
#define LUMI_FUNC_NAME _func_name_Expression_parse_new_init_operand
Returncode Expression_parse_new_init_operand(Expression* self, String* text, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  if ((0) < 0 || (0) >= (text)->length) RAISE(117)
  Char first = ((text)->values[0]);
  Char second = '\0';
  if (text->length > 1) {
    if ((1) < 0 || (1) >= (text)->length) RAISE(120)
    second = ((text)->values[1]);
  }
  if (first == '\'') {
    CHECK(122, CharExpression_parse_new(NULL, text, &((*expression))) )
  }
  else {
    if (first == '"') {
      CHECK(124, StringExpression_parse_new(NULL, text, code_node, &((*expression))) )
    }
    else {
      if ((first >= '0' && first <= '9') || (first == '-' && second >= '0' && second <= '9')) {
        CHECK(128, IntExpression_parse_new(NULL, text, &((*expression))) )
      }
      else {
        if (first >= 'A' && first <= 'Z' && second >= 'a' && second <= 'z') {
          CHECK(130, TypeExpression_parse_new(NULL, text, ends, code_node, &((*expression)), &((*end))) )
        }
        else {
          if (text->length == 1 && first == '_') {
            CHECK(133, EmptyExpression_parse_new(NULL, text, &((*expression))) )
          }
          else {
            Bool _Bool44;
            CHECK(134, String_equal(text, &(String){5, 4, "base"}, &(_Bool44)) )
            if (_Bool44) {
              CHECK(135, BaseMethExpression_parse_new(NULL, text, code_node, (*end), &((*expression))) )
            }
            else {
              CHECK(138, SymbolExpression_parse_new(NULL, text, code_node, &((*expression))) )
            }
          }
        }
      }
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* Parse one following part of an operand */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_parse_new_follow_operand(Expression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end, Bool* has_more);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_parse_new_follow_operand = "Expression.parse-new-follow-operand";
#define LUMI_FUNC_NAME _func_name_Expression_parse_new_follow_operand
Returncode Expression_parse_new_follow_operand(Expression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end, Bool* has_more) {
  (*has_more) = true;
  if ((*end) == '.') {
    String* text = NULL;
    CHECK(148, Expression_read_new_value(self, ends, &(text), &((*end))) )
    if ((0) < 0 || (0) >= (text)->length) RAISE(149)
    Char first = ((text)->values[0]);
    Char second = '\0';
    if (text->length > 1) {
      if ((1) < 0 || (1) >= (text)->length) RAISE(152)
      second = ((text)->values[1]);
    }
    if (first >= 'A' && first <= 'Z' && second >= 'a' && second <= 'z') {
      CHECK(154, TypeExpression_parse_new(NULL, text, ends, code_node, &((*expression)), &((*end))) )
    }
    else {
      CHECK(157, MemberExpression_parse_new(NULL, text, code_node, &((*expression))) )
    }
  }
  else {
    if ((*end) == '[') {
      CHECK(160, SliceExpression_parse_new(NULL, ends, code_node, &((*expression)), &((*end))) )
    }
    else {
      if ((*end) == '(') {
        CHECK(163, CallExpression_parse_new(NULL, ends, code_node, &((*expression)), &((*end))) )
      }
      else {
        (*has_more) = false;
      }
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* Set type instance to be a type that has no sub-type */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_set_simple_type(Expression* self, TypeData* type_data);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_set_simple_type = "Expression.set-simple-type";
#define LUMI_FUNC_NAME _func_name_Expression_set_simple_type
Returncode Expression_set_simple_type(Expression* self, TypeData* type_data) {
  CHECK(170, TypeData_m_new_type_instance(type_data, &(self->result_type)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_add_aux_variable(Expression* self, Int access, Bool is_create, TypeInstance* type_instance, SymbolExpression** symbol);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_add_aux_variable = "Expression.add-aux-variable";
#define LUMI_FUNC_NAME _func_name_Expression_add_aux_variable
Returncode Expression_add_aux_variable(Expression* self, Int access, Bool is_create, TypeInstance* type_instance, SymbolExpression** symbol) {
  (*symbol) = malloc(sizeof(SymbolExpression));
  if ((*symbol) == NULL) RAISE(175)
  *(*symbol) = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL, false};
  (*symbol)->_base._base._dtl = SymbolExpression__dtl;
  (*symbol)->_base.code_node = self->code_node;
  CHECK(177, TypeInstance_copy_new(type_instance, &((*symbol)->_base.result_type)) )
  (*symbol)->_base.access = access;
  (*symbol)->_base.assignable = true;
  SyntaxTreeFunction* _SyntaxTreeFunction45;
  CHECK(180, SyntaxTreeCode_get_function(self->code_node, &(_SyntaxTreeFunction45)) )
  CHECK(180, SyntaxTreeFunction_add_aux_variable(_SyntaxTreeFunction45, access, is_create, type_instance, &((*symbol)->variable)) )
  CHECK(182, string_new_copy((*symbol)->variable->name, &((*symbol)->name)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_get_parent_type(Expression* self, TypeData** parent_type);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_get_parent_type = "Expression.get-parent-type";
#define LUMI_FUNC_NAME _func_name_Expression_get_parent_type
Returncode Expression_get_parent_type(Expression* self, TypeData** parent_type) {
  (*parent_type) = NULL;
  if (NULL != self->code_node) {
    CHECK(187, (self->code_node)->_base._dtl[0](self->code_node, &((*parent_type))) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_write_refman_init(Expression* self, SymbolExpression* symbol);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_write_refman_init = "Expression.write-refman-init";
#define LUMI_FUNC_NAME _func_name_Expression_write_refman_init
Returncode Expression_write_refman_init(Expression* self, SymbolExpression* symbol) {
  /* `symbol`_Refman = LUMI_new_ref(`symbol`); */
  /* if (`symbol`_Refman == NULL) raise(`line-num`) */
  CHECK(192, SyntaxTreeCode_write_spaces(self->code_node) )
  CHECK(193, (symbol)->_base._base._dtl[4](symbol) )
  CHECK(194, write(&(String){24, 23, "_Refman = LUMI_new_ref("}) )
  CHECK(195, (symbol)->_base._base._dtl[4](symbol) )
  CHECK(196, write(&(String){4, 3, ");\n"}) )
  CHECK(197, SyntaxTreeCode_write_spaces(self->code_node) )
  CHECK(198, write(&(String){5, 4, "if ("}) )
  CHECK(199, (symbol)->_base._base._dtl[4](symbol) )
  CHECK(200, write(&(String){18, 17, "_Refman == NULL) "}) )
  CHECK(201, SyntaxTreeNode_write_raise(&(self->_base), &(String){39, 38, "insufficient memory for managed object"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_write_init_var_ref(Expression* self, SymbolExpression* symbol);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_write_init_var_ref = "Expression.write-init-var-ref";
#define LUMI_FUNC_NAME _func_name_Expression_write_init_var_ref
Returncode Expression_write_init_var_ref(Expression* self, SymbolExpression* symbol) {
  /* `symbol` = &`symbol`_Var; */
  CHECK(205, (symbol)->_base._base._dtl[4](symbol) )
  CHECK(206, write(&(String){5, 4, " = &"}) )
  CHECK(207, (symbol)->_base._base._dtl[4](symbol) )
  CHECK(208, write(&(String){7, 6, "_Var;\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_write_assign_null(Expression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_write_assign_null = "Expression.write-assign-null";
#define LUMI_FUNC_NAME _func_name_Expression_write_assign_null
Returncode Expression_write_assign_null(Expression* self) {
  CHECK(211, SyntaxTreeCode_write_spaces(self->code_node) )
  CHECK(212, (self)->_base._dtl[4](self) )
  CHECK(213, write(&(String){10, 9, " = NULL;\n"}) )
  CHECK(214, SyntaxTreeCode_write_spaces(self->code_node) )
  CHECK(215, (self)->_base._dtl[6](self) )
  CHECK(216, write(&(String){10, 9, " = NULL;\n"}) )
  if (self->result_type->type_data->is_dynamic) {
    CHECK(218, SyntaxTreeCode_write_spaces(self->code_node) )
    CHECK(219, (self)->_base._dtl[5](self) )
    CHECK(220, write(&(String){10, 9, " = NULL;\n"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_write_dynamic(Expression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_write_dynamic = "Expression.write-dynamic";
#define LUMI_FUNC_NAME _func_name_Expression_write_dynamic
Returncode Expression_write_dynamic(Expression* self) {
  CHECK(223, (self)->_base._dtl[4](self) )
  CHECK(224, write(&(String){9, 8, "_Dynamic"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_write_refman(Expression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_write_refman = "Expression.write-refman";
#define LUMI_FUNC_NAME _func_name_Expression_write_refman
Returncode Expression_write_refman(Expression* self) {
  CHECK(227, (self)->_base._dtl[4](self) )
  CHECK(228, write(&(String){8, 7, "_Refman"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_write_as_top(Expression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_write_as_top = "Expression.write-as-top";
#define LUMI_FUNC_NAME _func_name_Expression_write_as_top
Returncode Expression_write_as_top(Expression* self) {
  Bool top = self->top;
  self->top = true;
  CHECK(233, (self)->_base._dtl[4](self) )
  self->top = top;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_analyze_call(Expression* self, FunctionArguments* arguments, TypeInstance** instance_type, Int* bases, Bool* is_function_object);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_analyze_call = "Expression.analyze-call";
#define LUMI_FUNC_NAME _func_name_Expression_analyze_call
Returncode Expression_analyze_call(Expression* self, FunctionArguments* arguments, TypeInstance** instance_type, Int* bases, Bool* is_function_object) {
  (*is_function_object) = true;
  (*bases) = 0;
  (*instance_type) = NULL;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_analyze_mock(Expression* self, Bool is_annotate, Bool* is_mock);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_analyze_mock = "Expression.analyze-mock";
#define LUMI_FUNC_NAME _func_name_Expression_analyze_mock
Returncode Expression_analyze_mock(Expression* self, Bool is_annotate, Bool* is_mock) {
  (*is_mock) = false;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Expression_write_preactions(Expression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Expression_write_preactions = "Expression.write-preactions";
#define LUMI_FUNC_NAME _func_name_Expression_write_preactions
Returncode Expression_write_preactions(Expression* self) {
  /* do noting */
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func Expression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func Expression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeNode_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)Expression_write_preactions};
#endif

#undef LUMI_FILE_NAME

#ifndef LUMI_INCLUDES
#define LUMI_INCLUDES
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
#include "expression/container.c"
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
#include "tl4-compiler.c"
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
