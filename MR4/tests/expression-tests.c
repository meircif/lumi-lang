#ifndef MR_MAINFILE
#define MR_MAINFILE "tests/expression-tests.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file23_name = "tests/expression-tests.3.mr";
#endif
#define MR_FILE_NAME _mr_file23_name

/* MR4 compiler tests - Expression */

#if MR_STAGE == MR_DECLARATIONS
Returncode test_code(String* input_text, String* expected_output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_code = "test-code";
#define MR_FUNC_NAME _func_name_test_code
Returncode test_code(String* input_text, String* expected_output) {
  CHECK(4, f_setup_test() )
  CHECK(5, set_mock_file_text(&(String){115, 114, "struct Test\n  var Int num\nfunc mock(copy Int i, copy Char c, copy Bool b, user String str, user Array{Int} arr)\n  "}) )
  CHECK(7, String_concat(mock_input_file_text, input_text) )
  CHECK(8, String_append(mock_input_file_text, '\n') )
  CHECK(9, write_syntax_tree() )
  String* expected_header = &(String){189, 188, "\ntypedef struct Test Test;\nstruct Test {\n  Int num;\n};\nReturncode mock(Int i, Char c, Bool b, String* str, Array* arr);\nReturncode mock(Int i, Char c, Bool b, String* str, Array* arr) {\n  "};
  String* expected_footer = &(String){17, 16, "\n  return OK;\n}\n"};
  CHECK(12, f_assert_string_slice(expected_header, mock_output_file_text, 0, expected_header->length) )
  CHECK(17, f_assert_string_slice(expected_output, mock_output_file_text, expected_header->length, mock_output_file_text->length - expected_header->length - expected_footer->length) )
  CHECK(23, f_assert_string_slice(expected_footer, mock_output_file_text, mock_output_file_text->length - expected_footer->length, expected_footer->length) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_code_error(String* input_text, String* expected_error);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_code_error = "test-code-error";
#define MR_FUNC_NAME _func_name_test_code_error
Returncode test_code_error(String* input_text, String* expected_error) {
  CHECK(31, f_setup_test() )
  CHECK(32, set_mock_file_text(&(String){15, 14, "func mock()\n  "}) )
  CHECK(33, String_concat(mock_input_file_text, input_text) )
  CHECK(34, String_append(mock_input_file_text, '\n') )
  mock_print_active = true;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(36, write_syntax_tree() );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(36)
  } while (false);
  _trace_stream = stdout;
  mock_print_active = false;
  String* expected_header = &(String){25, 24, "Code error in mock.3.mr["};
  CHECK(39, f_assert_string_slice(expected_header, mock_print_text, 0, expected_header->length) )
  CHECK(44, f_assert_string_slice(expected_error, mock_print_text, expected_header->length + 3, mock_print_text->length - expected_header->length - 4) )
  if ((mock_print_text->length - 1) < 0 || (mock_print_text->length - 1) >= (mock_print_text)->length) RAISE(49)
  TEST_ASSERT(49, ((mock_print_text)->values[mock_print_text->length - 1]) == '\n')
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
  CHECK(53, test_code(&(String){7, 6, "i := 0"}, &(String){7, 6, "i = 0;"}) )
  CHECK(54, test_code(&(String){10, 9, "i := 9630"}, &(String){10, 9, "i = 9630;"}) )
  CHECK(55, test_code(&(String){11, 10, "i := -9630"}, &(String){11, 10, "i = -9630;"}) )
  CHECK(56, test_code(&(String){11, 10, "i := 07520"}, &(String){11, 10, "i = 07520;"}) )
  CHECK(57, test_code(&(String){12, 11, "i := 0b1011"}, &(String){12, 11, "i = 0b1011;"}) )
  CHECK(58, test_code(&(String){14, 13, "i := 0xfda940"}, &(String){14, 13, "i = 0xfda940;"}) )
  CHECK(59, test_code(&(String){14, 13, "i := 0xFDA940"}, &(String){14, 13, "i = 0xFDA940;"}) )
  CHECK(60, test_code_error(&(String){3, 2, "2a"}, &(String){20, 19, "illegal number \"2a\""}) )
  CHECK(61, test_code_error(&(String){3, 2, "0a"}, &(String){20, 19, "illegal number \"0a\""}) )
  CHECK(62, test_code_error(&(String){4, 3, "038"}, &(String){27, 26, "illegal octal number \"038\""}) )
  CHECK(63, test_code_error(&(String){6, 5, "0b021"}, &(String){30, 29, "illegal binary number \"0b021\""}) )
  CHECK(64, test_code_error(&(String){6, 5, "0xadg"}, &(String){35, 34, "illegal hexadecimal number \"0xadg\""}) )
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
  CHECK(68, test_code(&(String){9, 8, "c := 'a'"}, &(String){9, 8, "c = 'a';"}) )
  CHECK(69, test_code(&(String){10, 9, "c := '\\''"}, &(String){10, 9, "c = '\\'';"}) )
  CHECK(70, test_code(&(String){10, 9, "c := '\\n'"}, &(String){10, 9, "c = '\\n';"}) )
  CHECK(71, test_code(&(String){12, 11, "c := '\\x0f'"}, &(String){12, 11, "c = '\\x0f';"}) )
  CHECK(72, test_code(&(String){12, 11, "c := '\\xA9'"}, &(String){12, 11, "c = '\\xA9';"}) )
  CHECK(73, test_code(&(String){12, 11, "c := '\\270'"}, &(String){12, 11, "c = '\\270';"}) )
  CHECK(74, test_code_error(&(String){4, 3, "'''"}, &(String){33, 32, "illegal character constant \"'''\""}) )
  CHECK(75, test_code_error(&(String){4, 3, "'\\'"}, &(String){33, 32, "illegal character constant \"'\\'\""}) )
  CHECK(77, test_code_error(&(String){5, 4, "'aa'"}, &(String){34, 33, "illegal character constant \"'aa'\""}) )
  CHECK(78, test_code_error(&(String){5, 4, "'\\c'"}, &(String){34, 33, "illegal character constant \"'\\c'\""}) )
  CHECK(80, test_code_error(&(String){7, 6, "'aaaa'"}, &(String){36, 35, "illegal character constant \"'aaaa'\""}) )
  CHECK(82, test_code_error(&(String){8, 7, "'\\x6fg'"}, &(String){37, 36, "illegal character constant \"'\\x6fg'\""}) )
  CHECK(84, test_code_error(&(String){7, 6, "'\\058'"}, &(String){36, 35, "illegal character constant \"'\\058'\""}) )
  CHECK(86, test_code_error(&(String){3, 2, "''"}, &(String){32, 31, "illegal character constant \"''\""}) )
  CHECK(87, test_code_error(&(String){6, 5, "'aaa'"}, &(String){35, 34, "illegal character constant \"'aaa'\""}) )
  CHECK(89, test_code_error(&(String){8, 7, "'aaaaa'"}, &(String){37, 36, "illegal character constant \"'aaaaa'\""}) )
  CHECK(91, test_code_error(&(String){4, 3, "'aa"}, &(String){33, 32, "illegal character constant \"'aa\""}) )
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
  CHECK(96, test_code(&(String){21, 20, "str := \"some string\""}, &(String){199, 198, "String aux_String_0_Var = {0};\n  String* aux_String_0 = &aux_String_0_Var;\n  aux_String_0->max_length = 12;\n  aux_String_0->length = 11;\n  aux_String_0->values = \"some string\";\n  str = aux_String_0;"}) )
  CHECK(99, test_code_error(&(String){5, 4, "\"aaa"}, &(String){31, 30, "illegal string constant \"\"aaa\""}) )
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
  CHECK(103, test_code(&(String){9, 8, "str := _"}, &(String){12, 11, "str = NULL;"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* test test-base-expression() */
/* test-code(user "base", user "Base") */


/* test test-type-expression() */
/* test-code(user "TypeName", user "TypeName") */


/* test test-member-expression() */
/* test-code(user "str.length", user "str->length;") */
/* test-code(user "str.length.str", user "str->length->str;") */


#if MR_STAGE == MR_DECLARATIONS
Returncode test_slice_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_slice_expression = "test-slice-expression";
#define MR_FUNC_NAME _func_name_test_slice_expression
Returncode test_slice_expression() {
  CHECK(120, test_code(&(String){13, 12, "i := arr[13]"}, &(String){85, 84, "if ((13) < 0 || (13) >= (arr)->length) RAISE(3)\n  i = (((Int*)((arr)->values))[13]);"}) )
  CHECK(123, test_code(&(String){16, 15, "arr := arr[2:6]"}, &(String){225, 224, "Array aux_Array_0_Var = {0};\n  Array* aux_Array_0 = &aux_Array_0_Var;\n  aux_Array_0.length = 6;\n  aux_Array_0.values = (arr)->values + (2);\n  if ((2) < 0 || (6) < 0 || (2) + (6) > (arr)->length) RAISE(3)\n  arr = aux_Array_0;"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* test test-call-expression() */
/* test-code(user "function()", user "function()") */
/* test-code( */
/* user "function(copy 3, user arg, var _)", */
/* user "function(3, arg, NULL)") */
/* test-code( */
/* user "function()->(owner arg, copy num)", */
/* user "function(&(arg), &(num))") */
/* test-code( */
/* user "function(copy 0)->(owner arg)", */
/* user "function(0, &(arg))") */
/* test-code( */
/* user "function(copy calc(copy 3))", */
/* user "function(calc(3))") */
/* test-code( */
/* user "function(\n    copy 2,\n    copy 3)->(\n    copy x,\n    copy y)", */
/* user "function(2, 3, &(x), &(y))") */
/* test-code-error( */
/* user "function( copy 1)", user "expected access, got \" \"") */
/* test-code-error( */
/* user "function(user)", user "expected space after access, got \")\"") */
/* test-code-error( */
/* user "function(copy 4,copy 3)", */
/* user "expected space or new-line after \",\", got \"c\"") */
/* test-code-error( */
/* user "function(copy 2", user "expected \",\" or \")\", got \"EOF\"") */
/* test-code-error( */
/* user "function(error 4)", user "illegal access \"error\"") */


#if MR_STAGE == MR_DECLARATIONS
Returncode test_block_expression();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_block_expression = "test-block-expression";
#define MR_FUNC_NAME _func_name_test_block_expression
Returncode test_block_expression() {
  CHECK(159, test_code(&(String){11, 10, "i := (123)"}, &(String){11, 10, "i = (123);"}) )
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
  CHECK(163, test_code(&(String){9, 8, "i := - i"}, &(String){9, 8, "i = - i;"}) )
  CHECK(164, test_code(&(String){13, 12, "i := -\n    i"}, &(String){9, 8, "i = - i;"}) )
  CHECK(165, test_code(&(String){11, 10, "i := - - i"}, &(String){13, 12, "i = - (- i);"}) )
  CHECK(166, test_code_error(&(String){5, 4, "[45]"}, &(String){15, 14, "unexpected \"[\""}) )
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
  CHECK(170, test_code(&(String){13, 12, "i := 23 + 54"}, &(String){13, 12, "i = 23 + 54;"}) )
  CHECK(171, test_code(&(String){18, 17, "i := 100 * 2 - 37"}, &(String){20, 19, "i = (100 * 2) - 37;"}) )
  CHECK(172, test_code(&(String){17, 16, "i := 12 *\n    13"}, &(String){13, 12, "i = 12 * 13;"}) )
  CHECK(173, test_code(&(String){23, 22, "b := 3 < 5 and 23 < 37"}, &(String){26, 25, "b = (3 < 5) && (23 < 37);"}) )
  CHECK(174, test_code_error(&(String){8, 7, "345 @ 2"}, &(String){21, 20, "unknown operator \"@\""}) )
  CHECK(175, test_code_error(&(String){6, 5, "80 +("}, &(String){15, 14, "unexpected \"(\""}) )
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
  CHECK(179, test_code(&(String){10, 9, "b := str?"}, &(String){17, 16, "b = str != NULL;"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* test test-complex-operand() */
/* test-code( */
/* user "base.func().array[3].seq[4][70]()()[23]", */
/* user "Base.func().array[3].seq[4][70]()()[23]") */


/* test test-complex-expression() */
/* test-code( */
/* user "4 + (array[5] - 23) > 2 + func(copy 2 + base.meth())->(owner item).val or (var.arr[1]? and num < 5)", */
/* user "((4 + (array[5] - 23)) > (2 + func(2 + Base.meth(), &(item)).val)) || ((var.arr[1] != NULL) && (num < 5))") */

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
