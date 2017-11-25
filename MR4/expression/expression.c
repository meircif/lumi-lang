#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/expression.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file10_name = "expression/expression.3.mr";
#endif
#define MR_FILE_NAME _mr_file10_name

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
  Operator* _Operator28;
  CHECK(23, Expression_parse_new(NULL, ends, code_node, NULL, &((*expression)), &((*end)), &(_Operator28)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Meta type for an expression in the language. */
/* Currently only the parsing is fully implemented, `write` is implemented only */
/* for testing. */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Expression Expression;
#elif MR_STAGE == MR_TYPES(1)
struct Expression {
  SyntaxTreeNode _base;
  SyntaxTreeCode* code_node;
  TypeInstance* result_type;
  Bool assignable;
  Bool top;
  Bool is_statement;
/* Parse any expression *//* Read a single expression value as new string *//* Parse an expression that is an operand *//* Parse the initialize part of an operand expression *//* Parse one following part of an operand *//* Set type instance to be a type that has no sub-type */};
#endif/* Parse any expression */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_parse_new(Expression* self, String* ends, SyntaxTreeCode* code_node, Operator* curr_operator, Expression** expression, Char* end, Operator** operator);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_parse_new = "Expression.parse-new";
#define MR_FUNC_NAME _func_name_Expression_parse_new
Returncode Expression_parse_new(Expression* self, String* ends, SyntaxTreeCode* code_node, Operator* curr_operator, Expression** expression, Char* end, Operator** operator) {
  (*expression) = NULL;
  Bool _Bool29;
  CHECK(46, String_has(ends, ' ', &(_Bool29)) )
  Bool multi_operands = !_Bool29;
  String* text = NULL;
  CHECK(48, Expression_read_new_value(self, ends, &(text), &((*end))) )
  CHECK(49, NameMap_find(glob->operator_map, text, (void**)&((*operator))) )
  if (NULL != (*operator)) {
    if (!multi_operands) {
      CHECK(52, SyntaxTreeNode_m_syntax_error(&(code_node->_base), &(String){20, 19, "unexpected operator"}, (*operator)->name) )
    }
    CHECK(53, UnaryExpression_parse_new(NULL, ends, (*operator), code_node, &((*expression)), &((*end)), &((*operator))) )
  }
  else {
    CHECK(57, Expression_parse_new_operand(self, text, ends, code_node, &((*expression)), &((*end))) )
    if (multi_operands && (*end) == ' ') {
      CHECK(60, Expression_read_new_value(self, ends, &(text), &((*end))) )
      CHECK(61, NameMap_find(glob->operator_map, text, (void**)&((*operator))) )
      if (!(NULL != (*operator))) {
        CHECK(63, SyntaxTreeNode_m_syntax_error(&(code_node->_base), &(String){17, 16, "unknown operator"}, text) )
      }
    }
  }
  BinaryExpression* binary_left_expression = NULL;
  while (true) {
    if (!(NULL != (*operator) && (!(NULL != curr_operator) || (*operator)->order < curr_operator->order))) break;
    BinaryExpression* new_binary_expression = NULL;
    CHECK(69, BinaryExpression_parse_new(NULL, ends, (*operator), code_node, (*expression), binary_left_expression, &(new_binary_expression), &((*end)), &((*operator))) )
    binary_left_expression = new_binary_expression;
    (*expression) = &(new_binary_expression->_base._base);
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
  CHECK(87, string_new_concat(&(String){7, 6, " .[({?"}, ends, &(all_ends)) )
  CHECK(88, read_new(all_ends, &((*text)), &((*end))) )
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
      CHECK(97, BlockExpression_parse_new(NULL, code_node, &((*expression)), &((*end))) )
    }
    else {
      CHECK(100, SyntaxTreeNode_m_syntax_error_c(&(code_node->_base), &(String){11, 10, "unexpected"}, (*end)) )
    }
    free(text);
  }
  else {
    CHECK(103, Expression_parse_new_init_operand(self, text, code_node, &((*expression)), &((*end))) )
  }
  
  while (true) {
    if ((*end) == '?') {
      CHECK(108, QuestionExpression_parse_new(NULL, &((*expression)), &((*end))) )
    }
    Bool _Bool30;
    CHECK(109, Expression_parse_new_follow_operand(self, ends, code_node, &((*expression)), &((*end)), &(_Bool30)) )
    if (!(_Bool30)) break;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Parse the initialize part of an operand expression */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_parse_new_init_operand(Expression* self, String* text, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_parse_new_init_operand = "Expression.parse-new-init-operand";
#define MR_FUNC_NAME _func_name_Expression_parse_new_init_operand
Returncode Expression_parse_new_init_operand(Expression* self, String* text, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  if ((0) < 0 || (0) >= (text)->length) RAISE(116)
  Char first = ((text)->values[0]);
  Char second = '\0';
  if (text->length > 1) {
    if ((1) < 0 || (1) >= (text)->length) RAISE(119)
    second = ((text)->values[1]);
  }
  if (first == '\'') {
    CHECK(121, CharExpression_parse_new(NULL, text, &((*expression))) )
  }
  else {
    if (first == '"') {
      CHECK(123, StringExpression_parse_new(NULL, text, code_node, &((*expression))) )
    }
    else {
      if ((first >= '0' && first <= '9') || (first == '-' && second >= '0' && second <= '9')) {
        CHECK(127, IntExpression_parse_new(NULL, text, &((*expression))) )
      }
      else {
        if (first >= 'A' && first <= 'Z' && second >= 'a' && second <= 'z') {
          CHECK(129, TypeExpression_parse_new(NULL, text, code_node, &((*expression)), &((*end))) )
        }
        else {
          if (text->length == 1 && first == '_') {
            CHECK(132, EmptyExpression_parse_new(NULL, text, &((*expression))) )
          }
          else {
            Bool _Bool31;
            CHECK(133, String_equal(text, &(String){5, 4, "base"}, &(_Bool31)) )
            if (_Bool31) {
              CHECK(134, BaseMethExpression_parse_new(NULL, text, code_node, (*end), &((*expression))) )
            }
            else {
              CHECK(137, SymbolExpression_parse_new(NULL, text, code_node, &((*expression))) )
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
    CHECK(146, MemberExpression_parse_new(NULL, ends, code_node, &((*expression)), &((*end))) )
  }
  else {
    if ((*end) == '[') {
      CHECK(149, SliceExpression_parse_new(NULL, ends, code_node, &((*expression)), &((*end))) )
    }
    else {
      if ((*end) == '(') {
        CHECK(152, CallExpression_parse_new(NULL, ends, code_node, &((*expression)), &((*end))) )
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
  CHECK(159, TypeData_m_new_type_instance(type_data, &(self->result_type)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_add_aux_variable(Expression* self, Int access, TypeInstance* type_instance, SymbolExpression** symbol);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_add_aux_variable = "Expression.add-aux-variable";
#define MR_FUNC_NAME _func_name_Expression_add_aux_variable
Returncode Expression_add_aux_variable(Expression* self, Int access, TypeInstance* type_instance, SymbolExpression** symbol) {
  (*symbol) = malloc(sizeof(SymbolExpression));
  if ((*symbol) == NULL) RAISE(163)
  *(*symbol) = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL, NULL, NULL};
  (*symbol)->_base._base._dtl = SymbolExpression__dtl;
  (*symbol)->_base.code_node = self->code_node;
  CHECK(165, TypeInstance_copy_new(type_instance, &((*symbol)->_base.result_type)) )
  (*symbol)->_base.assignable = true;
  SyntaxTreeFunction* _SyntaxTreeFunction32;
  CHECK(167, SyntaxTreeCode_get_function(self->code_node, &(_SyntaxTreeFunction32)) )
  CHECK(167, SyntaxTreeFunction_add_aux_variable(_SyntaxTreeFunction32, access, type_instance, &((*symbol)->variable)) )
  CHECK(169, string_new_copy((*symbol)->variable->name, &((*symbol)->name)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_write_ref_init(Expression* self, SymbolExpression* symbol);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_write_ref_init = "Expression.write-ref-init";
#define MR_FUNC_NAME _func_name_Expression_write_ref_init
Returncode Expression_write_ref_init(Expression* self, SymbolExpression* symbol) {
  /* `symbol` = MR_new_ref(); */
  /* if (`symbol` == NULL) raise(`line-num`) */
  CHECK(174, (symbol)->_base._base._dtl[2](symbol) )
  CHECK(175, write(&(String){18, 17, " = MR_new_ref();\n"}) )
  CHECK(176, SyntaxTreeCode_write_spaces(self->code_node) )
  CHECK(177, write(&(String){5, 4, "if ("}) )
  CHECK(178, (symbol)->_base._base._dtl[2](symbol) )
  CHECK(179, write(&(String){11, 10, " == NULL) "}) )
  CHECK(180, SyntaxTreeNode_write_raise(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_write_init_var_ref(Expression* self, SymbolExpression* symbol);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_write_init_var_ref = "Expression.write-init-var-ref";
#define MR_FUNC_NAME _func_name_Expression_write_init_var_ref
Returncode Expression_write_init_var_ref(Expression* self, SymbolExpression* symbol) {
  /* &`symbol`_Var; */
  CHECK(184, SyntaxTreeCode_write_spaces(self->code_node) )
  CHECK(185, write(&(String){2, 1, "*"}) )
  CHECK(186, (symbol)->_base._base._dtl[2](symbol) )
  CHECK(187, write(&(String){5, 4, " = &"}) )
  CHECK(188, (symbol)->_base._base._dtl[2](symbol) )
  CHECK(189, write(&(String){7, 6, "_Var;\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_write_dynamic(Expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_write_dynamic = "Expression.write-dynamic";
#define MR_FUNC_NAME _func_name_Expression_write_dynamic
Returncode Expression_write_dynamic(Expression* self) {
  CHECK(192, (self)->_base._dtl[2](self) )
  CHECK(193, write(&(String){9, 8, "_Dynamic"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_analyze_call(Expression* self, FunctionArguments* arguments, Bool* is_function_object);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_analyze_call = "Expression.analyze-call";
#define MR_FUNC_NAME _func_name_Expression_analyze_call
Returncode Expression_analyze_call(Expression* self, FunctionArguments* arguments, Bool* is_function_object) {
  (*is_function_object) = true;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_write_preactions(Expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_write_preactions = "Expression.write-preactions";
#define MR_FUNC_NAME _func_name_Expression_write_preactions
Returncode Expression_write_preactions(Expression* self) {
  /* do noting */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Expression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write, (void*)Expression_write_dynamic, (void*)Expression_analyze_call, (void*)Expression_write_preactions};
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
#include "expression/container.c"
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
