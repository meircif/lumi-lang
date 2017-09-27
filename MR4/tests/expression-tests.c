#ifndef MR_MAINFILE
#define MR_MAINFILE "tests/expression-tests.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file21_name = "tests/expression-tests.3.mr";
#endif
#define MR_FILE_NAME _mr_file21_name

/* MR4 compiler tests - Expression */

#if MR_STAGE == MR_DECLARATIONS
Returncode test_expression_ends(String* input_text, String* expected_output, String* ends, Char expected_end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_expression_ends = "test-expression-ends";
#define MR_FUNC_NAME _func_name_test_expression_ends
Returncode test_expression_ends(String* input_text, String* expected_output, String* ends, Char expected_end) {
  CHECK(8, f_setup_test() )
  CHECK(9, set_mock_file_text(input_text) )
  Expression* expression = NULL;
  Char end = '\0';
  CHECK(12, parse_new_expression(ends, NULL, &(expression), &(end)) )
  TEST_ASSERT(13, end == expected_end)
  CHECK(14, (expression)->_dtl[1](expression) )
  CHECK(15, f_assert_string(expected_output, mock_output_file_text) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode test_expression(String* input_text, String* expected_output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_expression = "test-expression";
#define MR_FUNC_NAME _func_name_test_expression
Returncode test_expression(String* input_text, String* expected_output) {
  CHECK(18, test_expression_ends(input_text, expected_output, &(String){1, 0, ""}, EOF) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_expression_error_ends(String* input_text, String* expected_error, String* ends);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_expression_error_ends = "test-expression-error-ends";
#define MR_FUNC_NAME _func_name_test_expression_error_ends
Returncode test_expression_error_ends(String* input_text, String* expected_error, String* ends) {
  CHECK(23, f_setup_test() )
  CHECK(24, set_mock_file_text(input_text) )
  Expression* expression = NULL;
  mock_print_active = true;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    Char _Char91;
    CHECK(27, parse_new_expression(ends, NULL, &(expression), &(_Char91)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(27)
  } while (false);
  _trace_stream = stdout;
  mock_print_active = false;
  String* expected_header = &(String){28, 27, "Code error in mock.3.mr[0] "};
  CHECK(30, f_assert_string_slice(expected_header, mock_print_text, 0, expected_header->length) )
  CHECK(35, f_assert_string_slice(expected_error, mock_print_text, expected_header->length, mock_print_text->length - expected_header->length - 1) )
  if ((mock_print_text->length - 1) < 0 || (mock_print_text->length - 1) >= (mock_print_text)->length) RAISE(40)
  TEST_ASSERT(40, ((mock_print_text)->values[mock_print_text->length - 1]) == '\n')
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_expression_error(String* input_text, String* expected_error);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_expression_error = "test-expression-error";
#define MR_FUNC_NAME _func_name_test_expression_error
Returncode test_expression_error(String* input_text, String* expected_error) {
  CHECK(44, test_expression_error_ends(input_text, expected_error, &(String){1, 0, ""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_int_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_int_expression = "test-int-expression";
#define MR_FUNC_NAME _func_name_test_int_expression
Returncode test_int_expression() {
  CHECK(48, test_expression(&(String){2, 1, "0"}, &(String){2, 1, "0"}) )
  CHECK(49, test_expression(&(String){5, 4, "9630"}, &(String){5, 4, "9630"}) )
  CHECK(50, test_expression(&(String){6, 5, "-9630"}, &(String){6, 5, "-9630"}) )
  CHECK(51, test_expression(&(String){6, 5, "07520"}, &(String){6, 5, "07520"}) )
  CHECK(52, test_expression(&(String){7, 6, "0b1011"}, &(String){7, 6, "0b1011"}) )
  CHECK(53, test_expression(&(String){9, 8, "0xfda940"}, &(String){9, 8, "0xfda940"}) )
  CHECK(54, test_expression(&(String){9, 8, "0xFDA940"}, &(String){9, 8, "0xFDA940"}) )
  CHECK(55, test_expression_error(&(String){3, 2, "2a"}, &(String){20, 19, "illegal number \"2a\""}) )
  CHECK(56, test_expression_error(&(String){3, 2, "0a"}, &(String){20, 19, "illegal number \"0a\""}) )
  CHECK(57, test_expression_error(&(String){4, 3, "038"}, &(String){27, 26, "illegal octal number \"038\""}) )
  CHECK(58, test_expression_error(&(String){6, 5, "0b021"}, &(String){30, 29, "illegal binary number \"0b021\""}) )
  CHECK(59, test_expression_error(&(String){6, 5, "0xadg"}, &(String){35, 34, "illegal hexadecimal number \"0xadg\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_char_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_char_expression = "test-char-expression";
#define MR_FUNC_NAME _func_name_test_char_expression
Returncode test_char_expression() {
  CHECK(64, test_expression(&(String){4, 3, "'a'"}, &(String){4, 3, "'a'"}) )
  CHECK(65, test_expression(&(String){5, 4, "'\\''"}, &(String){5, 4, "'\\''"}) )
  CHECK(66, test_expression(&(String){5, 4, "'\\n'"}, &(String){5, 4, "'\\n'"}) )
  CHECK(67, test_expression(&(String){7, 6, "'\\x0f'"}, &(String){7, 6, "'\\x0f'"}) )
  CHECK(68, test_expression(&(String){7, 6, "'\\xA9'"}, &(String){7, 6, "'\\xA9'"}) )
  CHECK(69, test_expression(&(String){7, 6, "'\\270'"}, &(String){7, 6, "'\\270'"}) )
  CHECK(70, test_expression_error(&(String){4, 3, "'''"}, &(String){33, 32, "illegal character constant \"'''\""}) )
  CHECK(71, test_expression_error(&(String){4, 3, "'\\'"}, &(String){33, 32, "illegal character constant \"'\\'\""}) )
  CHECK(73, test_expression_error(&(String){5, 4, "'aa'"}, &(String){34, 33, "illegal character constant \"'aa'\""}) )
  CHECK(74, test_expression_error(&(String){5, 4, "'\\c'"}, &(String){34, 33, "illegal character constant \"'\\c'\""}) )
  CHECK(76, test_expression_error(&(String){7, 6, "'aaaa'"}, &(String){36, 35, "illegal character constant \"'aaaa'\""}) )
  CHECK(78, test_expression_error(&(String){8, 7, "'\\x6fg'"}, &(String){37, 36, "illegal character constant \"'\\x6fg'\""}) )
  CHECK(80, test_expression_error(&(String){7, 6, "'\\058'"}, &(String){36, 35, "illegal character constant \"'\\058'\""}) )
  CHECK(82, test_expression_error(&(String){3, 2, "''"}, &(String){32, 31, "illegal character constant \"''\""}) )
  CHECK(83, test_expression_error(&(String){6, 5, "'aaa'"}, &(String){35, 34, "illegal character constant \"'aaa'\""}) )
  CHECK(85, test_expression_error(&(String){8, 7, "'aaaaa'"}, &(String){37, 36, "illegal character constant \"'aaaaa'\""}) )
  CHECK(87, test_expression_error(&(String){4, 3, "'aa"}, &(String){33, 32, "illegal character constant \"'aa\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_string_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_string_expression = "test-string-expression";
#define MR_FUNC_NAME _func_name_test_string_expression
Returncode test_string_expression() {
  CHECK(92, test_expression(&(String){14, 13, "\"some string\""}, &(String){14, 13, "\"some string\""}) )
  CHECK(93, test_expression_error(&(String){5, 4, "\"aaa"}, &(String){31, 30, "illegal string constant \"\"aaa\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_empty_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_empty_expression = "test-empty-expression";
#define MR_FUNC_NAME _func_name_test_empty_expression
Returncode test_empty_expression() {
  CHECK(97, test_expression(&(String){2, 1, "_"}, &(String){5, 4, "NULL"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_variable_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_variable_expression = "test-variable-expression";
#define MR_FUNC_NAME _func_name_test_variable_expression
Returncode test_variable_expression() {
  CHECK(101, test_expression(&(String){9, 8, "var-name"}, &(String){9, 8, "var_name"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_base_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_base_expression = "test-base-expression";
#define MR_FUNC_NAME _func_name_test_base_expression
Returncode test_base_expression() {
  CHECK(105, test_expression(&(String){5, 4, "base"}, &(String){5, 4, "Base"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_type_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_type_expression = "test-type-expression";
#define MR_FUNC_NAME _func_name_test_type_expression
Returncode test_type_expression() {
  CHECK(109, test_expression(&(String){9, 8, "TypeName"}, &(String){9, 8, "TypeName"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_member_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_member_expression = "test-member-expression";
#define MR_FUNC_NAME _func_name_test_member_expression
Returncode test_member_expression() {
  String* expected = &(String){256, 0, (char[256]){0}};
  CHECK(113, String_copy(expected, &(String){21, 20, "var_name.member_name"}))
  CHECK(114, test_expression(&(String){21, 20, "var-name.member-name"}, expected) )
  CHECK(115, String_concat(expected, &(String){16, 15, ".another.member"}) )
  CHECK(116, test_expression(&(String){36, 35, "var_name.member_name.another.member"}, expected) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_slice_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_slice_expression = "test-slice-expression";
#define MR_FUNC_NAME _func_name_test_slice_expression
Returncode test_slice_expression() {
  CHECK(120, test_expression(&(String){10, 9, "array[13]"}, &(String){10, 9, "array[13]"}) )
  CHECK(121, test_expression(&(String){11, 10, "array[2:6]"}, &(String){11, 10, "array[2:6]"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_call_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_call_expression = "test-call-expression";
#define MR_FUNC_NAME _func_name_test_call_expression
Returncode test_call_expression() {
  CHECK(125, test_expression(&(String){11, 10, "function()"}, &(String){11, 10, "function()"}) )
  CHECK(126, test_expression(&(String){34, 33, "function(copy 3, user arg, var _)"}, &(String){23, 22, "function(3, arg, NULL)"}) )
  CHECK(129, test_expression(&(String){34, 33, "function()->(owner arg, copy num)"}, &(String){25, 24, "function(&(arg), &(num))"}) )
  CHECK(132, test_expression(&(String){30, 29, "function(copy 0)->(owner arg)"}, &(String){20, 19, "function(0, &(arg))"}) )
  CHECK(135, test_expression(&(String){28, 27, "function(copy calc(copy 3))"}, &(String){18, 17, "function(calc(3))"}) )
  CHECK(138, test_expression(&(String){61, 60, "function(\n    copy 2,\n    copy 3)->(\n    copy x,\n    copy y)"}, &(String){27, 26, "function(2, 3, &(x), &(y))"}) )
  CHECK(141, test_expression_error(&(String){18, 17, "function( copy 1)"}, &(String){25, 24, "expected access, got \" \""}) )
  CHECK(143, test_expression_error(&(String){15, 14, "function(user)"}, &(String){37, 36, "expected space after access, got \")\""}) )
  CHECK(145, test_expression_error(&(String){24, 23, "function(copy 4,copy 3)"}, &(String){46, 45, "expected space or new-line after \",\", got \"c\""}) )
  CHECK(148, test_expression_error(&(String){16, 15, "function(copy 2"}, &(String){31, 30, "expected \",\" or \")\", got \"EOF\""}) )
  CHECK(150, test_expression_error(&(String){18, 17, "function(error 4)"}, &(String){23, 22, "illegal access \"error\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_block_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_block_expression = "test-block-expression";
#define MR_FUNC_NAME _func_name_test_block_expression
Returncode test_block_expression() {
  CHECK(155, test_expression(&(String){6, 5, "(123)"}, &(String){6, 5, "(123)"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_unary_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_unary_expression = "test-unary-expression";
#define MR_FUNC_NAME _func_name_test_unary_expression
Returncode test_unary_expression() {
  CHECK(159, test_expression(&(String){16, 15, "- variable-name"}, &(String){16, 15, "- variable_name"}) )
  CHECK(160, test_expression(&(String){20, 19, "-\n    variable-name"}, &(String){16, 15, "- variable_name"}) )
  CHECK(161, test_expression_error(&(String){18, 17, "- - variable-name"}, &(String){24, 23, "unexpected operator \"-\""}) )
  CHECK(163, test_expression_error(&(String){5, 4, "[45]"}, &(String){15, 14, "unexpected \"[\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_binary_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_binary_expression = "test-binary-expression";
#define MR_FUNC_NAME _func_name_test_binary_expression
Returncode test_binary_expression() {
  CHECK(167, test_expression(&(String){8, 7, "23 + 54"}, &(String){8, 7, "23 + 54"}) )
  CHECK(168, test_expression(&(String){13, 12, "100 * 2 - 37"}, &(String){13, 12, "100 * 2 - 37"}) )
  CHECK(169, test_expression(&(String){12, 11, "12 *\n    13"}, &(String){8, 7, "12 * 13"}) )
  CHECK(170, test_expression(&(String){18, 17, "3 < 5 and 23 < 37"}, &(String){17, 16, "3 < 5 && 23 < 37"}) )
  CHECK(171, test_expression_error(&(String){8, 7, "345 @ 2"}, &(String){21, 20, "unknown operator \"@\""}) )
  CHECK(172, test_expression_error(&(String){6, 5, "80 +("}, &(String){15, 14, "unexpected \"(\""}) )
  CHECK(173, test_expression_error_ends(&(String){16, 15, "- variable-name"}, &(String){24, 23, "unexpected operator \"-\""}, &(String){2, 1, " "}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_question_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_question_expression = "test-question-expression";
#define MR_FUNC_NAME _func_name_test_question_expression
Returncode test_question_expression() {
  CHECK(178, test_expression(&(String){15, 14, "variable-name?"}, &(String){22, 21, "variable_name != NULL"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_single_operand_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_single_operand_expression = "test-single-operand-expression";
#define MR_FUNC_NAME _func_name_test_single_operand_expression
Returncode test_single_operand_expression() {
  CHECK(182, test_expression_ends(&(String){20, 19, "23 after expression"}, &(String){3, 2, "23"}, &(String){2, 1, " "}, ' ') )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_complex_operand();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_complex_operand = "test-complex-operand";
#define MR_FUNC_NAME _func_name_test_complex_operand
Returncode test_complex_operand() {
  CHECK(187, test_expression(&(String){40, 39, "base.func().array[3].seq[4][70]()()[23]"}, &(String){40, 39, "Base.func().array[3].seq[4][70]()()[23]"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_complex_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_complex_expression = "test-complex-expression";
#define MR_FUNC_NAME _func_name_test_complex_expression
Returncode test_complex_expression() {
  CHECK(193, test_expression(&(String){100, 99, "4 + (array[5] - 23) > 2 + func(copy 2 + base.meth())->(owner item).val or (var.arr[1]? and num < 5)"}, &(String){96, 95, "4 + (array[5] - 23) > 2 + func(2 + Base.meth(), &(item)).val || (var.arr[1] != NULL && num < 5)"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_no_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_no_expression = "test-no-expression";
#define MR_FUNC_NAME _func_name_test_no_expression
Returncode test_no_expression() {
  CHECK(199, test_expression_error(&(String){1, 0, ""}, &(String){17, 16, "unexpected \"EOF\""}) )
  return OK;
}
#undef MR_FUNC_NAME
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
#include "expression/container.c"
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
#include "tests/global-tests.c"
#include "tests/syntax-tree-tests.c"
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
