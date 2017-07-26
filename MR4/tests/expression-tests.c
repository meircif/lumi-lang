#ifndef MR_MAINFILE
#define MR_MAINFILE "tests/expression-tests.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file12_name = "tests/expression-tests.3.mr";
#endif
#define MR_FILE_NAME _mr_file12_name

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
  CHECK(12, parse_new_expression(ends, &(expression), &(end)) )
  TEST_ASSERT(13, end == expected_end)
  CHECK(14, (expression)->_dtl[0](expression) )
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
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    Char _Char22;
    CHECK(26, parse_new_expression(ends, &(expression), &(_Char22)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(26)
  } while (false);
  _trace_stream = stdout;
  String* expected_header = &(String){26, 25, "Code error in in.3.mr[0] "};
  CHECK(28, f_assert_string_slice(expected_header, mock_print_text, 0, expected_header->length) )
  CHECK(33, f_assert_string_slice(expected_error, mock_print_text, expected_header->length, mock_print_text->length - expected_header->length - 1) )
  if ((mock_print_text->length - 1) < 0 || (mock_print_text->length - 1) >= (mock_print_text)->length) RAISE(38)
  TEST_ASSERT(38, ((mock_print_text)->values[mock_print_text->length - 1]) == '\n')
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
  CHECK(42, test_expression_error_ends(input_text, expected_error, &(String){1, 0, ""}) )
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
  CHECK(46, test_expression(&(String){5, 4, "9630"}, &(String){10, 9, "Int(9630)"}) )
  CHECK(47, test_expression(&(String){6, 5, "-9630"}, &(String){11, 10, "Int(-9630)"}) )
  CHECK(48, test_expression(&(String){6, 5, "07520"}, &(String){11, 10, "Int(07520)"}) )
  CHECK(49, test_expression(&(String){7, 6, "0b1011"}, &(String){12, 11, "Int(0b1011)"}) )
  CHECK(50, test_expression(&(String){9, 8, "0xfda940"}, &(String){14, 13, "Int(0xfda940)"}) )
  CHECK(51, test_expression(&(String){9, 8, "0xFDA940"}, &(String){14, 13, "Int(0xFDA940)"}) )
  CHECK(52, test_expression_error(&(String){3, 2, "2a"}, &(String){20, 19, "illegal number \"2a\""}) )
  CHECK(53, test_expression_error(&(String){3, 2, "0a"}, &(String){20, 19, "illegal number \"0a\""}) )
  CHECK(54, test_expression_error(&(String){4, 3, "038"}, &(String){27, 26, "illegal octal number \"038\""}) )
  CHECK(55, test_expression_error(&(String){6, 5, "0b021"}, &(String){30, 29, "illegal binary number \"0b021\""}) )
  CHECK(56, test_expression_error(&(String){6, 5, "0xadg"}, &(String){35, 34, "illegal hexadecimal number \"0xadg\""}) )
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
  CHECK(61, test_expression(&(String){4, 3, "'a'"}, &(String){10, 9, "Char('a')"}) )
  CHECK(62, test_expression(&(String){5, 4, "'\\''"}, &(String){11, 10, "Char('\\'')"}) )
  CHECK(63, test_expression(&(String){5, 4, "'\\n'"}, &(String){11, 10, "Char('\\n')"}) )
  CHECK(64, test_expression(&(String){7, 6, "'\\x0f'"}, &(String){13, 12, "Char('\\x0f')"}) )
  CHECK(65, test_expression(&(String){7, 6, "'\\xA9'"}, &(String){13, 12, "Char('\\xA9')"}) )
  CHECK(66, test_expression(&(String){7, 6, "'\\070'"}, &(String){13, 12, "Char('\\070')"}) )
  CHECK(67, test_expression_error(&(String){4, 3, "'''"}, &(String){33, 32, "illegal character constant \"'''\""}) )
  CHECK(68, test_expression_error(&(String){4, 3, "'\\'"}, &(String){33, 32, "illegal character constant \"'\\'\""}) )
  CHECK(70, test_expression_error(&(String){5, 4, "'aa'"}, &(String){34, 33, "illegal character constant \"'aa'\""}) )
  CHECK(71, test_expression_error(&(String){5, 4, "'\\c'"}, &(String){34, 33, "illegal character constant \"'\\c'\""}) )
  CHECK(73, test_expression_error(&(String){7, 6, "'aaaa'"}, &(String){36, 35, "illegal character constant \"'aaaa'\""}) )
  CHECK(75, test_expression_error(&(String){8, 7, "'\\x6fg'"}, &(String){37, 36, "illegal character constant \"'\\x6fg'\""}) )
  CHECK(77, test_expression_error(&(String){7, 6, "'\\058'"}, &(String){36, 35, "illegal character constant \"'\\058'\""}) )
  CHECK(79, test_expression_error(&(String){3, 2, "''"}, &(String){32, 31, "illegal character constant \"''\""}) )
  CHECK(80, test_expression_error(&(String){6, 5, "'aaa'"}, &(String){35, 34, "illegal character constant \"'aaa'\""}) )
  CHECK(82, test_expression_error(&(String){8, 7, "'aaaaa'"}, &(String){37, 36, "illegal character constant \"'aaaaa'\""}) )
  CHECK(84, test_expression_error(&(String){4, 3, "'aa"}, &(String){33, 32, "illegal character constant \"'aa\""}) )
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
  CHECK(89, test_expression(&(String){14, 13, "\"some string\""}, &(String){22, 21, "String(\"some string\")"}) )
  CHECK(90, test_expression_error(&(String){5, 4, "\"aaa"}, &(String){31, 30, "illegal string constant \"\"aaa\""}) )
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
  CHECK(94, test_expression(&(String){2, 1, "_"}, &(String){6, 5, "Empty"}) )
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
  CHECK(98, test_expression(&(String){9, 8, "var-name"}, &(String){19, 18, "Variable(var-name)"}) )
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
  CHECK(102, test_expression(&(String){5, 4, "base"}, &(String){5, 4, "Base"}) )
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
  CHECK(106, test_expression(&(String){10, 9, "Type-name"}, &(String){16, 15, "Type(Type-name)"}) )
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
  CHECK(110, String_copy(expected, &(String){39, 38, "Variable(var-name).Member(member-name)"}))
  CHECK(111, test_expression(&(String){21, 20, "var-name.member-name"}, expected) )
  CHECK(112, String_concat(expected, &(String){32, 31, ".Member(another).Member(member)"}) )
  CHECK(113, test_expression(&(String){36, 35, "var-name.member-name.another.member"}, expected) )
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
  CHECK(117, test_expression(&(String){10, 9, "array[13]"}, &(String){25, 24, "Variable(array)[Int(13)]"}) )
  CHECK(118, test_expression(&(String){11, 10, "array[2:6]"}, &(String){31, 30, "Variable(array)[Int(2):Int(6)]"}) )
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
  CHECK(122, test_expression(&(String){11, 10, "function()"}, &(String){21, 20, "Variable(function)()"}) )
  CHECK(123, test_expression(&(String){17, 16, "function(params)"}, &(String){27, 26, "Variable(function)(params)"}) )
  CHECK(124, test_expression(&(String){21, 20, "function():(outputs)"}, &(String){31, 30, "Variable(function)():(outputs)"}) )
  CHECK(126, test_expression(&(String){27, 26, "function(params):(outputs)"}, &(String){37, 36, "Variable(function)(params):(outputs)"}) )
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
  CHECK(132, test_expression(&(String){6, 5, "(123)"}, &(String){16, 15, "Block(Int(123))"}) )
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
  CHECK(136, test_expression(&(String){16, 15, "- variable-name"}, &(String){26, 25, "- Variable(variable-name)"}) )
  CHECK(137, test_expression_error(&(String){18, 17, "- - variable-name"}, &(String){24, 23, "unexpected operator \"-\""}) )
  CHECK(139, test_expression_error(&(String){5, 4, "[45]"}, &(String){15, 14, "unexpected \"[\""}) )
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
  CHECK(143, test_expression(&(String){8, 7, "23 + 54"}, &(String){18, 17, "Int(23) + Int(54)"}) )
  CHECK(144, test_expression(&(String){12, 11, "12 *\n    13"}, &(String){18, 17, "Int(12) * Int(13)"}) )
  CHECK(145, test_expression(&(String){18, 17, "3 < 5 and 23 < 37"}, &(String){37, 36, "Int(3) < Int(5) && Int(23) < Int(37)"}) )
  CHECK(147, test_expression_error(&(String){8, 7, "345 @ 2"}, &(String){21, 20, "unknown operator \"@\""}) )
  CHECK(148, test_expression_error(&(String){6, 5, "80 +("}, &(String){15, 14, "unexpected \"(\""}) )
  CHECK(149, test_expression_error_ends(&(String){16, 15, "- variable-name"}, &(String){24, 23, "unexpected operator \"-\""}, &(String){2, 1, " "}) )
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
  CHECK(154, test_expression(&(String){15, 14, "variable-name?"}, &(String){34, 33, "Question(Variable(variable-name))"}) )
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
  CHECK(159, test_expression_ends(&(String){20, 19, "23 after expression"}, &(String){8, 7, "Int(23)"}, &(String){2, 1, " "}, ' ') )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_comlex_operand();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_comlex_operand = "test-comlex-operand";
#define MR_FUNC_NAME _func_name_test_comlex_operand
Returncode test_comlex_operand() {
  CHECK(164, test_expression(&(String){35, 34, "array[3].func().seq[4][70]()()[23]"}, &(String){81, 80, "Variable(array)[Int(3)].Member(func)().Member(seq)[Int(4)][Int(70)]()()[Int(23)]"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_comlex_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_comlex_expression = "test-comlex-expression";
#define MR_FUNC_NAME _func_name_test_comlex_expression
Returncode test_comlex_expression() {
  CHECK(170, test_expression(&(String){72, 71, "4 + (array[5] - 23) > 2 + func(params).val or (var.arr[1]? and num < 5)"}, &(String){176, 175, "Int(4) + Block(Variable(array)[Int(5)] - Int(23)) > Int(2) + Variable(func)(params).Member(val) || Block(Question(Variable(var).Member(arr)[Int(1)]) && Variable(num) < Int(5))"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/variable.c"
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/map.c"
#include "global/type.c"
#include "tests/global-tests.c"
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
