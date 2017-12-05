#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/expression.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file11_name = "expression/expression.3.mr";
#endif
#define MR_FILE_NAME _mr_file11_name

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
  Operator* _Operator27;
  CHECK(23, Expression_parse_new(NULL, ends, code_node, NULL, &((*expression)), &((*end)), &(_Operator27)) )
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
  Int access;
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
  Bool _Bool28;
  CHECK(47, String_has(ends, ' ', &(_Bool28)) )
  Bool multi_operands = !_Bool28;
  String* text = NULL;
  CHECK(49, Expression_read_new_value(self, ends, &(text), &((*end))) )
  CHECK(50, NameMap_find(glob->operator_map, text, (void**)&((*operator))) )
  if (NULL != (*operator)) {
    if (!multi_operands) {
      CHECK(53, SyntaxTreeNode_m_syntax_error(&(code_node->_base), &(String){20, 19, "unexpected operator"}, (*operator)->name) )
    }
    CHECK(54, UnaryExpression_parse_new(NULL, ends, (*operator), code_node, &((*expression)), &((*end)), &((*operator))) )
  }
  else {
    CHECK(58, Expression_parse_new_operand(self, text, ends, code_node, &((*expression)), &((*end))) )
    if (multi_operands && (*end) == ' ') {
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
#undef MR_FUNC_NAME
#endif/* Read a single expression value as new string */
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_read_new_value(Expression* self, String* ends, String** text, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_read_new_value = "Expression.read-new-value";
#define MR_FUNC_NAME _func_name_Expression_read_new_value
Returncode Expression_read_new_value(Expression* self, String* ends, String** text, Char* end) {
  String* all_ends = NULL;
  CHECK(88, string_new_concat(&(String){7, 6, " .[({?"}, ends, &(all_ends)) )
  CHECK(89, read_new(all_ends, &((*text)), &((*end))) )
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
      CHECK(98, BlockExpression_parse_new(NULL, code_node, &((*expression)), &((*end))) )
    }
    else {
      CHECK(101, SyntaxTreeNode_m_syntax_error_c(&(code_node->_base), &(String){11, 10, "unexpected"}, (*end)) )
    }
    free(text);
  }
  else {
    CHECK(104, Expression_parse_new_init_operand(self, text, code_node, &((*expression)), &((*end))) )
  }
  
  while (true) {
    if ((*end) == '?') {
      CHECK(109, QuestionExpression_parse_new(NULL, &((*expression)), &((*end))) )
    }
    Bool _Bool29;
    CHECK(110, Expression_parse_new_follow_operand(self, ends, code_node, &((*expression)), &((*end)), &(_Bool29)) )
    if (!(_Bool29)) break;
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
          CHECK(130, TypeExpression_parse_new(NULL, text, code_node, &((*expression)), &((*end))) )
        }
        else {
          if (text->length == 1 && first == '_') {
            CHECK(133, EmptyExpression_parse_new(NULL, text, &((*expression))) )
          }
          else {
            Bool _Bool30;
            CHECK(134, String_equal(text, &(String){5, 4, "base"}, &(_Bool30)) )
            if (_Bool30) {
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
    CHECK(147, MemberExpression_parse_new(NULL, ends, code_node, &((*expression)), &((*end))) )
  }
  else {
    if ((*end) == '[') {
      CHECK(150, SliceExpression_parse_new(NULL, ends, code_node, &((*expression)), &((*end))) )
    }
    else {
      if ((*end) == '(') {
        CHECK(153, CallExpression_parse_new(NULL, ends, code_node, &((*expression)), &((*end))) )
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
  CHECK(160, TypeData_m_new_type_instance(type_data, &(self->result_type)) )
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
  if ((*symbol) == NULL) RAISE(164)
  *(*symbol) = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL};
  (*symbol)->_base._base._dtl = SymbolExpression__dtl;
  (*symbol)->_base.code_node = self->code_node;
  CHECK(166, TypeInstance_copy_new(type_instance, &((*symbol)->_base.result_type)) )
  (*symbol)->_base.assignable = true;
  SyntaxTreeFunction* _SyntaxTreeFunction31;
  CHECK(168, SyntaxTreeCode_get_function(self->code_node, &(_SyntaxTreeFunction31)) )
  CHECK(168, SyntaxTreeFunction_add_aux_variable(_SyntaxTreeFunction31, access, type_instance, &((*symbol)->variable)) )
  CHECK(170, string_new_copy((*symbol)->variable->name, &((*symbol)->name)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_write_refman_init(Expression* self, SymbolExpression* symbol);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_write_refman_init = "Expression.write-refman-init";
#define MR_FUNC_NAME _func_name_Expression_write_refman_init
Returncode Expression_write_refman_init(Expression* self, SymbolExpression* symbol) {
  /* `symbol`_Refman = MR_new_ref(`symbol`); */
  /* if (`symbol`_Refman == NULL) raise(`line-num`) */
  CHECK(175, SyntaxTreeCode_write_spaces(self->code_node) )
  CHECK(176, (symbol)->_base._base._dtl[2](symbol) )
  CHECK(177, write(&(String){22, 21, "_Refman = MR_new_ref("}) )
  CHECK(178, (symbol)->_base._base._dtl[2](symbol) )
  CHECK(179, write(&(String){4, 3, ");\n"}) )
  CHECK(180, SyntaxTreeCode_write_spaces(self->code_node) )
  CHECK(181, write(&(String){5, 4, "if ("}) )
  CHECK(182, (symbol)->_base._base._dtl[2](symbol) )
  CHECK(183, write(&(String){18, 17, "_Refman == NULL) "}) )
  CHECK(184, SyntaxTreeNode_write_raise(&(self->_base)) )
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
  /* `symbol` = &`symbol`_Var; */
  CHECK(188, (symbol)->_base._base._dtl[2](symbol) )
  CHECK(189, write(&(String){5, 4, " = &"}) )
  CHECK(190, (symbol)->_base._base._dtl[2](symbol) )
  CHECK(191, write(&(String){7, 6, "_Var;\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_write_validate_ref(Expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_write_validate_ref = "Expression.write-validate-ref";
#define MR_FUNC_NAME _func_name_Expression_write_validate_ref
Returncode Expression_write_validate_ref(Expression* self) {
  CHECK(194, Expression_write_as_top(self) )
  CHECK(195, write(&(String){9, 8, " == NULL"}) )
  if (!self->result_type->type_data->is_primitive) {
    CHECK(197, write(&(String){5, 4, " || "}) )
    Bool top = self->top;
    self->top = false;
    CHECK(200, (self)->_base._dtl[4](self) )
    self->top = top;
    CHECK(202, write(&(String){16, 15, "->value == NULL"}) )
  }
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
  CHECK(205, (self)->_base._dtl[2](self) )
  CHECK(206, write(&(String){9, 8, "_Dynamic"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_write_refman(Expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_write_refman = "Expression.write-refman";
#define MR_FUNC_NAME _func_name_Expression_write_refman
Returncode Expression_write_refman(Expression* self) {
  CHECK(209, (self)->_base._dtl[2](self) )
  CHECK(210, write(&(String){8, 7, "_Refman"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Expression_write_as_top(Expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Expression_write_as_top = "Expression.write-as-top";
#define MR_FUNC_NAME _func_name_Expression_write_as_top
Returncode Expression_write_as_top(Expression* self) {
  Bool top = self->top;
  self->top = true;
  CHECK(215, (self)->_base._dtl[2](self) )
  self->top = top;
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
Func Expression__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write, (void*)Expression_write_dynamic, (void*)Expression_write_refman, (void*)Expression_analyze_call, (void*)Expression_write_preactions};
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
#include "syntax-tree/function.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "syntax-tree/test.c"
#include "syntax-tree/type.c"
#include "syntax-tree/type-instance.c"
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
