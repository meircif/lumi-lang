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
Returncode test_code_setup(String* input_text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_code_setup = "test-code-setup";
#define MR_FUNC_NAME _func_name_test_code_setup
Returncode test_code_setup(String* input_text) {
  CHECK(4, f_setup_test() )
  CHECK(5, set_mock_file_text(&(String){1, 0, ""}) )
  CHECK(6, String_concat(mock_input_file_text, &(String){13, 12, "struct Test\n"}) )
  CHECK(7, String_concat(mock_input_file_text, &(String){15, 14, "  var Int num\n"}) )
  CHECK(8, String_concat(mock_input_file_text, &(String){15, 14, "  func meth()\n"}) )
  CHECK(9, String_concat(mock_input_file_text, &(String){17, 16, "struct Ta(Test)\n"}) )
  CHECK(10, String_concat(mock_input_file_text, &(String){16, 15, "  var Int numa\n"}) )
  CHECK(11, String_concat(mock_input_file_text, &(String){16, 15, "  func metha()\n"}) )
  CHECK(12, String_concat(mock_input_file_text, &(String){15, 14, "struct Tb(Ta)\n"}) )
  CHECK(13, String_concat(mock_input_file_text, &(String){16, 15, "  var Int numb\n"}) )
  CHECK(14, String_concat(mock_input_file_text, &(String){16, 15, "  func methb()\n"}) )
  CHECK(15, String_concat(mock_input_file_text, &(String){15, 14, "struct Tc(Tb)\n"}) )
  CHECK(16, String_concat(mock_input_file_text, &(String){16, 15, "  var Int numc\n"}) )
  CHECK(17, String_concat(mock_input_file_text, &(String){16, 15, "  func methc()\n"}) )
  CHECK(18, String_concat(mock_input_file_text, &(String){1, 0, ""}) )
  CHECK(19, String_concat(mock_input_file_text, &(String){13, 12, "func fun0()\n"}) )
  CHECK(20, String_concat(mock_input_file_text, &(String){54, 53, "func fun1(copy Int x, user String s, owner String o)\n"}) )
  CHECK(22, String_concat(mock_input_file_text, &(String){43, 42, "func fun2()->(owner String s, copy Int x)\n"}) )
  CHECK(24, String_concat(mock_input_file_text, &(String){41, 40, "func fun3(copy Int x)->(owner String s)\n"}) )
  CHECK(25, String_concat(mock_input_file_text, &(String){23, 22, "func fun4(copy Int x)\n"}) )
  CHECK(26, String_concat(mock_input_file_text, &(String){37, 36, "func fun5(copy Int x)->(copy Int y)\n"}) )
  CHECK(27, String_concat(mock_input_file_text, &(String){61, 60, "func fun6(copy Int x, copy Int y)->(copy Int n, copy Int m)\n"}) )
  CHECK(29, String_concat(mock_input_file_text, &(String){27, 26, "func fun7()->(user Tb tb)\n"}) )
  CHECK(30, String_concat(mock_input_file_text, &(String){21, 20, "func mock(copy Int i"}) )
  CHECK(31, String_concat(mock_input_file_text, &(String){14, 13, ", copy Char c"}) )
  CHECK(32, String_concat(mock_input_file_text, &(String){14, 13, ", copy Bool b"}) )
  CHECK(33, String_concat(mock_input_file_text, &(String){18, 17, ", user String str"}) )
  CHECK(34, String_concat(mock_input_file_text, &(String){22, 21, ", user Array{Int} arr"}) )
  CHECK(35, String_concat(mock_input_file_text, &(String){14, 13, ", user Test t"}) )
  CHECK(36, String_concat(mock_input_file_text, &(String){13, 12, ", user Tc tc"}) )
  CHECK(37, String_concat(mock_input_file_text, &(String){20, 19, ")->(owner String so"}) )
  CHECK(38, String_concat(mock_input_file_text, &(String){14, 13, ", copy Int io"}) )
  CHECK(39, String_concat(mock_input_file_text, &(String){5, 4, ")\n  "}) )
  mock_input_line_reset_index = mock_input_file_text->length;
  CHECK(41, String_concat(mock_input_file_text, input_text) )
  CHECK(42, String_append(mock_input_file_text, '\n') )
  
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode test_code(String* input_text, String* expected_output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_code = "test-code";
#define MR_FUNC_NAME _func_name_test_code
Returncode test_code(String* input_text, String* expected_output) {
  CHECK(46, test_code_setup(input_text) )
  CHECK(47, write_syntax_tree() )
  String* mock_func_header = &(String){1024, 0, (char[1024]){0}};
  CHECK(49, String_copy(mock_func_header, &(String){17, 16, "Returncode mock("}) )
  CHECK(50, String_concat(mock_func_header, &(String){6, 5, "Int i"}) )
  CHECK(51, String_concat(mock_func_header, &(String){9, 8, ", Char c"}) )
  CHECK(52, String_concat(mock_func_header, &(String){9, 8, ", Bool b"}) )
  CHECK(53, String_concat(mock_func_header, &(String){14, 13, ", String* str"}) )
  CHECK(54, String_concat(mock_func_header, &(String){13, 12, ", Array* arr"}) )
  CHECK(55, String_concat(mock_func_header, &(String){10, 9, ", Test* t"}) )
  CHECK(56, String_concat(mock_func_header, &(String){9, 8, ", Tc* tc"}) )
  CHECK(57, String_concat(mock_func_header, &(String){14, 13, ", String** so"}) )
  CHECK(58, String_concat(mock_func_header, &(String){10, 9, ", Int* io"}) )
  CHECK(59, String_concat(mock_func_header, &(String){2, 1, ")"}) )
  String* empty_func_body = &(String){19, 18, " {\n  return OK;\n}\n"};
  String* expected_header = &(String){2048, 0, (char[2048]){0}};
  CHECK(62, String_copy(expected_header, &(String){28, 27, "\ntypedef struct Test Test;\n"}) )
  CHECK(63, String_concat(expected_header, &(String){23, 22, "typedef struct Ta Ta;\n"}) )
  CHECK(64, String_concat(expected_header, &(String){23, 22, "typedef struct Tb Tb;\n"}) )
  CHECK(65, String_concat(expected_header, &(String){23, 22, "typedef struct Tc Tc;\n"}) )
  CHECK(66, String_concat(expected_header, &(String){15, 14, "struct Test {\n"}) )
  CHECK(67, String_concat(expected_header, &(String){12, 11, "  Int num;\n"}) )
  CHECK(68, String_concat(expected_header, &(String){4, 3, "};\n"}) )
  CHECK(69, String_concat(expected_header, &(String){13, 12, "struct Ta {\n"}) )
  CHECK(70, String_concat(expected_header, &(String){15, 14, "  Test _base;\n"}) )
  CHECK(71, String_concat(expected_header, &(String){13, 12, "  Int numa;\n"}) )
  CHECK(72, String_concat(expected_header, &(String){4, 3, "};\n"}) )
  CHECK(73, String_concat(expected_header, &(String){13, 12, "struct Tb {\n"}) )
  CHECK(74, String_concat(expected_header, &(String){13, 12, "  Ta _base;\n"}) )
  CHECK(75, String_concat(expected_header, &(String){13, 12, "  Int numb;\n"}) )
  CHECK(76, String_concat(expected_header, &(String){4, 3, "};\n"}) )
  CHECK(77, String_concat(expected_header, &(String){13, 12, "struct Tc {\n"}) )
  CHECK(78, String_concat(expected_header, &(String){13, 12, "  Tb _base;\n"}) )
  CHECK(79, String_concat(expected_header, &(String){13, 12, "  Int numc;\n"}) )
  CHECK(80, String_concat(expected_header, &(String){4, 3, "};\n"}) )
  CHECK(81, String_concat(expected_header, &(String){35, 34, "Returncode Test_meth(Test* self);\n"}) )
  CHECK(82, String_concat(expected_header, &(String){32, 31, "Returncode Ta_metha(Ta* self);\n"}) )
  CHECK(83, String_concat(expected_header, &(String){32, 31, "Returncode Tb_methb(Tb* self);\n"}) )
  CHECK(84, String_concat(expected_header, &(String){32, 31, "Returncode Tc_methc(Tc* self);\n"}) )
  CHECK(85, String_concat(expected_header, &(String){1, 0, ""}) )
  CHECK(86, String_concat(expected_header, &(String){24, 23, "Returncode fun0(void);\n"}) )
  CHECK(87, String_concat(expected_header, &(String){47, 46, "Returncode fun1(Int x, String* s, String* o);\n"}) )
  CHECK(88, String_concat(expected_header, &(String){38, 37, "Returncode fun2(String** s, Int* x);\n"}) )
  CHECK(89, String_concat(expected_header, &(String){37, 36, "Returncode fun3(Int x, String** s);\n"}) )
  CHECK(90, String_concat(expected_header, &(String){25, 24, "Returncode fun4(Int x);\n"}) )
  CHECK(91, String_concat(expected_header, &(String){33, 32, "Returncode fun5(Int x, Int* y);\n"}) )
  CHECK(92, String_concat(expected_header, &(String){48, 47, "Returncode fun6(Int x, Int y, Int* n, Int* m);\n"}) )
  CHECK(94, String_concat(expected_header, &(String){27, 26, "Returncode fun7(Tb** tb);\n"}) )
  CHECK(95, String_concat(expected_header, mock_func_header) )
  CHECK(96, String_concat(expected_header, &(String){3, 2, ";\n"}) )
  CHECK(97, String_concat(expected_header, &(String){33, 32, "Returncode Test_meth(Test* self)"}) )
  CHECK(98, String_concat(expected_header, empty_func_body) )
  CHECK(99, String_concat(expected_header, &(String){30, 29, "Returncode Ta_metha(Ta* self)"}) )
  CHECK(100, String_concat(expected_header, empty_func_body) )
  CHECK(101, String_concat(expected_header, &(String){30, 29, "Returncode Tb_methb(Tb* self)"}) )
  CHECK(102, String_concat(expected_header, empty_func_body) )
  CHECK(103, String_concat(expected_header, &(String){30, 29, "Returncode Tc_methc(Tc* self)"}) )
  CHECK(104, String_concat(expected_header, empty_func_body) )
  CHECK(105, String_concat(expected_header, &(String){1, 0, ""}) )
  CHECK(106, String_concat(expected_header, &(String){22, 21, "Returncode fun0(void)"}) )
  CHECK(107, String_concat(expected_header, empty_func_body) )
  CHECK(108, String_concat(expected_header, &(String){45, 44, "Returncode fun1(Int x, String* s, String* o)"}) )
  CHECK(109, String_concat(expected_header, empty_func_body) )
  CHECK(110, String_concat(expected_header, &(String){36, 35, "Returncode fun2(String** s, Int* x)"}) )
  CHECK(111, String_concat(expected_header, empty_func_body) )
  CHECK(112, String_concat(expected_header, &(String){35, 34, "Returncode fun3(Int x, String** s)"}) )
  CHECK(113, String_concat(expected_header, empty_func_body) )
  CHECK(114, String_concat(expected_header, &(String){23, 22, "Returncode fun4(Int x)"}) )
  CHECK(115, String_concat(expected_header, empty_func_body) )
  CHECK(116, String_concat(expected_header, &(String){31, 30, "Returncode fun5(Int x, Int* y)"}) )
  CHECK(117, String_concat(expected_header, empty_func_body) )
  CHECK(118, String_concat(expected_header, &(String){46, 45, "Returncode fun6(Int x, Int y, Int* n, Int* m)"}) )
  CHECK(119, String_concat(expected_header, empty_func_body) )
  CHECK(120, String_concat(expected_header, &(String){25, 24, "Returncode fun7(Tb** tb)"}) )
  CHECK(121, String_concat(expected_header, empty_func_body) )
  CHECK(122, String_concat(expected_header, mock_func_header) )
  CHECK(123, String_concat(expected_header, &(String){6, 5, " {\n  "}) )
  String* expected_footer = &(String){17, 16, "\n  return OK;\n}\n"};
  CHECK(125, f_assert_string_slice(expected_header, mock_output_file_text, 0, expected_header->length) )
  CHECK(130, f_assert_string_slice(expected_output, mock_output_file_text, expected_header->length, mock_output_file_text->length - expected_header->length - expected_footer->length) )
  CHECK(136, f_assert_string_slice(expected_footer, mock_output_file_text, mock_output_file_text->length - expected_footer->length, expected_footer->length) )
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
  CHECK(144, test_code_setup(input_text) )
  mock_print_active = true;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(146, write_syntax_tree() );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(146)
  } while (false);
  _trace_stream = stdout;
  mock_print_active = false;
  String* expected_header = &(String){25, 24, "Code error in mock.3.mr["};
  CHECK(149, f_assert_string_slice(expected_header, mock_print_text, 0, expected_header->length) )
  CHECK(154, f_assert_string_slice(expected_error, mock_print_text, expected_header->length + 3, mock_print_text->length - expected_header->length - 4) )
  if ((mock_print_text->length - 1) < 0 || (mock_print_text->length - 1) >= (mock_print_text)->length) RAISE(159)
  TEST_ASSERT(159, ((mock_print_text)->values[mock_print_text->length - 1]) == '\n')
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
  CHECK(163, test_code(&(String){7, 6, "i := 0"}, &(String){7, 6, "i = 0;"}) )
  CHECK(164, test_code(&(String){10, 9, "i := 9630"}, &(String){10, 9, "i = 9630;"}) )
  CHECK(165, test_code(&(String){11, 10, "i := -9630"}, &(String){11, 10, "i = -9630;"}) )
  CHECK(166, test_code(&(String){11, 10, "i := 07520"}, &(String){11, 10, "i = 07520;"}) )
  CHECK(167, test_code(&(String){12, 11, "i := -07520"}, &(String){12, 11, "i = -07520;"}) )
  CHECK(168, test_code(&(String){14, 13, "i := 0xfda940"}, &(String){14, 13, "i = 0xfda940;"}) )
  CHECK(169, test_code(&(String){15, 14, "i := -0xfda940"}, &(String){15, 14, "i = -0xfda940;"}) )
  CHECK(170, test_code(&(String){14, 13, "i := 0xFDA940"}, &(String){14, 13, "i = 0xFDA940;"}) )
  CHECK(171, test_code(&(String){15, 14, "i := -0xFDA940"}, &(String){15, 14, "i = -0xFDA940;"}) )
  CHECK(172, test_code_error(&(String){3, 2, "2a"}, &(String){20, 19, "illegal number \"2a\""}) )
  CHECK(173, test_code_error(&(String){3, 2, "0a"}, &(String){20, 19, "illegal number \"0a\""}) )
  CHECK(174, test_code_error(&(String){4, 3, "038"}, &(String){27, 26, "illegal octal number \"038\""}) )
  CHECK(175, test_code_error(&(String){6, 5, "0b021"}, &(String){30, 29, "illegal binary number \"0b021\""}) )
  CHECK(176, test_code_error(&(String){6, 5, "0xadg"}, &(String){35, 34, "illegal hexadecimal number \"0xadg\""}) )
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
  CHECK(180, test_code(&(String){9, 8, "c := 'a'"}, &(String){9, 8, "c = 'a';"}) )
  CHECK(181, test_code(&(String){10, 9, "c := '\\''"}, &(String){10, 9, "c = '\\'';"}) )
  CHECK(182, test_code(&(String){10, 9, "c := '\\n'"}, &(String){10, 9, "c = '\\n';"}) )
  CHECK(183, test_code(&(String){12, 11, "c := '\\x0f'"}, &(String){12, 11, "c = '\\x0f';"}) )
  CHECK(184, test_code(&(String){12, 11, "c := '\\xA9'"}, &(String){12, 11, "c = '\\xA9';"}) )
  CHECK(185, test_code(&(String){12, 11, "c := '\\270'"}, &(String){12, 11, "c = '\\270';"}) )
  CHECK(186, test_code_error(&(String){4, 3, "'''"}, &(String){33, 32, "illegal character constant \"'''\""}) )
  CHECK(187, test_code_error(&(String){4, 3, "'\\'"}, &(String){33, 32, "illegal character constant \"'\\'\""}) )
  CHECK(189, test_code_error(&(String){5, 4, "'aa'"}, &(String){34, 33, "illegal character constant \"'aa'\""}) )
  CHECK(190, test_code_error(&(String){5, 4, "'\\c'"}, &(String){34, 33, "illegal character constant \"'\\c'\""}) )
  CHECK(192, test_code_error(&(String){7, 6, "'aaaa'"}, &(String){36, 35, "illegal character constant \"'aaaa'\""}) )
  CHECK(194, test_code_error(&(String){8, 7, "'\\x6fg'"}, &(String){37, 36, "illegal character constant \"'\\x6fg'\""}) )
  CHECK(196, test_code_error(&(String){7, 6, "'\\058'"}, &(String){36, 35, "illegal character constant \"'\\058'\""}) )
  CHECK(198, test_code_error(&(String){3, 2, "''"}, &(String){32, 31, "illegal character constant \"''\""}) )
  CHECK(199, test_code_error(&(String){6, 5, "'aaa'"}, &(String){35, 34, "illegal character constant \"'aaa'\""}) )
  CHECK(201, test_code_error(&(String){8, 7, "'aaaaa'"}, &(String){37, 36, "illegal character constant \"'aaaaa'\""}) )
  CHECK(203, test_code_error(&(String){4, 3, "'aa"}, &(String){33, 32, "illegal character constant \"'aa\""}) )
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
  CHECK(208, test_code(&(String){21, 20, "str := \"some string\""}, &(String){199, 198, "String aux_String_0_Var = {0};\n  String* aux_String_0 = &aux_String_0_Var;\n  aux_String_0->max_length = 12;\n  aux_String_0->length = 11;\n  aux_String_0->values = \"some string\";\n  str = aux_String_0;"}) )
  CHECK(211, test_code_error(&(String){5, 4, "\"aaa"}, &(String){31, 30, "illegal string constant \"\"aaa\""}) )
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
  CHECK(215, test_code(&(String){9, 8, "str := _"}, &(String){12, 11, "str = NULL;"}) )
  CHECK(216, test_code(&(String){7, 6, "t := _"}, &(String){10, 9, "t = NULL;"}) )
  CHECK(217, test_code_error(&(String){7, 6, "i := _"}, &(String){40, 39, "cannot assign \"Empty Symbol\" into \"Int\""}) )
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
  CHECK(222, test_code(&(String){11, 10, "i := t.num"}, &(String){38, 37, "if (t == NULL) RAISE(1)\n  i = t->num;"}) )
  CHECK(223, test_code(&(String){13, 12, "i := tc.numb"}, &(String){47, 46, "if (tc == NULL) RAISE(1)\n  i = tc->_base.numb;"}) )
  CHECK(226, test_code(&(String){12, 11, "i := tc.num"}, &(String){58, 57, "if (tc == NULL) RAISE(1)\n  i = tc->_base._base._base.num;"}) )
  CHECK(229, test_code_error(&(String){6, 5, "error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(230, test_code_error(&(String){15, 14, "(i := 1).error"}, &(String){38, 37, "void expression has no member \"error\""}) )
  CHECK(232, test_code_error(&(String){8, 7, "t.error"}, &(String){34, 33, "type \"Test\" has no member \"error\""}) )
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
  CHECK(236, test_code(&(String){13, 12, "c := str[13]"}, &(String){75, 74, "if ((13) < 0 || (13) >= (str)->length) RAISE(1)\n  c = ((str)->values)[13];"}) )
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(240, String_copy(expected, &(String){32, 31, "String aux_String_0_Var = {0};\n"}) )
  CHECK(241, String_concat(expected, &(String){45, 44, "  String* aux_String_0 = &aux_String_0_Var;\n"}) )
  CHECK(242, String_concat(expected, &(String){32, 31, "  aux_String_0_Var.length = 6;\n"}) )
  CHECK(243, String_concat(expected, &(String){62, 61, "  aux_String_0_Var.max_length = aux_String_0_Var.length + 1;\n"}) )
  CHECK(245, String_concat(expected, &(String){50, 49, "  aux_String_0_Var.values = (str)->values + (2);\n"}) )
  CHECK(246, String_concat(expected, &(String){65, 64, "  if ((2) < 0 || (6) < 0 || (2) + (6) > (str)->length) RAISE(1)\n"}) )
  CHECK(248, String_concat(expected, &(String){22, 21, "  str = aux_String_0;"}) )
  CHECK(249, test_code(&(String){16, 15, "str := str[2:6]"}, expected) )
  CHECK(250, test_code(&(String){13, 12, "i := arr[13]"}, &(String){83, 82, "if ((13) < 0 || (13) >= (arr)->length) RAISE(1)\n  i = ((Int*)((arr)->values))[13];"}) )
  CHECK(253, test_code(&(String){16, 15, "arr := arr[2:6]"}, &(String){242, 241, "Array aux_Array_0_Var = {0};\n  Array* aux_Array_0 = &aux_Array_0_Var;\n  aux_Array_0_Var.length = 6;\n  aux_Array_0_Var.values = (Byte*)((arr)->values) + (2);\n  if ((2) < 0 || (6) < 0 || (2) + (6) > (arr)->length) RAISE(1)\n  arr = aux_Array_0;"}) )
  CHECK(256, test_code(&(String){12, 11, "str[4] := c"}, &(String){72, 71, "if ((4) < 0 || (4) >= (str)->length) RAISE(1)\n  ((str)->values)[4] = c;"}) )
  CHECK(259, test_code(&(String){12, 11, "arr[4] := i"}, &(String){80, 79, "if ((4) < 0 || (4) >= (arr)->length) RAISE(1)\n  ((Int*)((arr)->values))[4] = i;"}) )
  CHECK(262, test_code_error(&(String){6, 5, "arr[2"}, &(String){29, 28, "expected \"]\", got \"new-line\""}) )
  CHECK(263, test_code_error(&(String){8, 7, "arr[2:3"}, &(String){29, 28, "expected \"]\", got \"new-line\""}) )
  CHECK(264, test_code_error(&(String){12, 11, "(i := 3)[2]"}, &(String){31, 30, "cannot slice a void expression"}) )
  CHECK(265, test_code_error(&(String){5, 4, "i[2]"}, &(String){24, 23, "cannot slice type \"Int\""}) )
  CHECK(266, test_code_error(&(String){9, 8, "arr[str]"}, &(String){47, 46, "expected integer index for slice, got \"String\""}) )
  CHECK(268, test_code_error(&(String){11, 10, "arr[3:str]"}, &(String){47, 46, "expected integer index for slice, got \"String\""}) )
  CHECK(271, test_code_error(&(String){12, 11, "arr[i += 3]"}, &(String){54, 53, "expected integer index for slice, got void expression"}) )
  CHECK(274, test_code_error(&(String){16, 15, "str[2:5] := str"}, &(String){41, 40, "assigning into non assignable expression"}) )
  CHECK(276, test_code_error(&(String){16, 15, "arr[7:2] := arr"}, &(String){41, 40, "assigning into non assignable expression"}) )
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
  CHECK(281, test_code(&(String){7, 6, "fun0()"}, &(String){18, 17, "CHECK(1, fun0() )"}) )
  CHECK(282, test_code(&(String){32, 31, "fun1(copy 3, user str, owner _)"}, &(String){30, 29, "CHECK(1, fun1(3, str, NULL) )"}) )
  CHECK(285, test_code(&(String){28, 27, "fun2()->(owner so, copy io)"}, &(String){32, 31, "CHECK(1, fun2(&(*so), &(*io)) )"}) )
  CHECK(288, test_code(&(String){55, 54, "var Int x\n  owner String s\n  fun2()->(owner s, copy x)"}, &(String){61, 60, "Int x = 0;\n  String* s = NULL;\n  CHECK(3, fun2(&(s), &(x)) )"}) )
  CHECK(291, test_code(&(String){25, 24, "fun3(copy 0)->(owner so)"}, &(String){27, 26, "CHECK(1, fun3(0, &(*so)) )"}) )
  CHECK(292, test_code(&(String){46, 45, "var Int x\n  fun4(copy fun5(copy 3)->(copy x))"}, &(String){59, 58, "Int x = 0;\n  CHECK(2, fun5(3, &(x)) )\n  CHECK(2, fun4(x) )"}) )
  CHECK(295, test_code(&(String){67, 66, "fun6(\n      copy 2,\n      copy 3)->(\n      copy io,\n      copy io)"}, &(String){38, 37, "CHECK(1, fun6(2, 3, &(*io), &(*io)) )"}) )
  CHECK(298, test_code(&(String){19, 18, "io := fun5(copy 4)"}, &(String){73, 72, "Int aux_Int_0 = 0;\n  CHECK(1, fun5(4, &(aux_Int_0)) )\n  *io = aux_Int_0;"}) )
  CHECK(301, test_code(&(String){19, 18, "so := fun3(copy 7)"}, &(String){89, 88, "String* aux_String_0 = NULL;\n  CHECK(1, fun3(7, &(aux_String_0)) )\n  *so = aux_String_0;"}) )
  CHECK(304, test_code(&(String){11, 10, "tc.methc()"}, &(String){24, 23, "CHECK(1, Tc_methc(tc) )"}) )
  CHECK(305, test_code(&(String){11, 10, "tc.methb()"}, &(String){34, 33, "CHECK(1, Tb_methb(&(tc->_base)) )"}) )
  CHECK(306, test_code(&(String){10, 9, "tc.meth()"}, &(String){47, 46, "CHECK(1, Test_meth(&(tc->_base._base._base)) )"}) )
  CHECK(308, test_code(&(String){17, 16, "fun7()->(user t)"}, &(String){55, 54, "if (t != NULL) RAISE(1)\n  CHECK(1, fun7((void*)&(t)) )"}) )
  CHECK(311, test_code_error(&(String){18, 17, "function( copy 1)"}, &(String){25, 24, "expected access, got \" \""}) )
  CHECK(313, test_code_error(&(String){15, 14, "function(user)"}, &(String){37, 36, "expected space after access, got \")\""}) )
  CHECK(315, test_code_error(&(String){24, 23, "function(copy 4,copy 3)"}, &(String){46, 45, "expected space or new-line after \",\", got \"c\""}) )
  CHECK(318, test_code_error(&(String){16, 15, "function(copy 2"}, &(String){36, 35, "expected \",\" or \")\", got \"new-line\""}) )
  CHECK(320, test_code_error(&(String){18, 17, "function(error 4)"}, &(String){23, 22, "illegal access \"error\""}) )
  CHECK(322, test_code_error(&(String){11, 10, "(i := 0)()"}, &(String){32, 31, "void expression is not callable"}) )
  CHECK(324, test_code_error(&(String){4, 3, "i()"}, &(String){24, 23, "non callable type \"Int\""}) )
  CHECK(326, test_code_error(&(String){23, 22, "fun5(copy 0)->(copy 4)"}, &(String){27, 26, "non assignable call output"}) )
  CHECK(328, test_code_error(&(String){18, 17, "fun7()->(user tc)"}, &(String){29, 28, "cannot assign \"Tb\" into \"Tc\""}) )
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
  CHECK(333, test_code(&(String){17, 16, "Test.meth(var t)"}, &(String){24, 23, "CHECK(1, Test_meth(t) )"}) )
  CHECK(334, test_code(&(String){17, 16, "Tb.methb(var tc)"}, &(String){34, 33, "CHECK(1, Tb_methb(&(tc->_base)) )"}) )
  CHECK(335, test_code(&(String){16, 15, "Tc.meth(var tc)"}, &(String){47, 46, "CHECK(1, Test_meth(&(tc->_base._base._base)) )"}) )
  CHECK(338, test_code_error(&(String){6, 5, "Error"}, &(String){21, 20, "unknown type \"Error\""}) )
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
  CHECK(342, test_meth_code(&(String){13, 12, "base.methm()"}, &(String){37, 36, "CHECK(9, Mid_methm(&(self->_base)) )"}) )
  CHECK(344, test_meth_code(&(String){13, 12, "base.methb()"}, &(String){44, 43, "CHECK(9, Base_methb(&(self->_base._base)) )"}) )
  CHECK(346, test_code_error(&(String){5, 4, "base"}, &(String){26, 25, "\"base\" used not in method"}) )
  CHECK(347, test_global_scope_error(&(String){48, 47, "struct Test\n  var Int x\n  func mock()\n    base\n"}, &(String){29, 28, "no base type for type \"Test\""}) )
  CHECK(350, test_global_scope_error(&(String){74, 73, "struct Base\n  var Int x\nstruct Test(Base)\n  func mock()\n    base := self\n"}, &(String){40, 39, "cannot assign \"Test\" into \"Base Symbol\""}) )
  CHECK(353, test_global_scope_error(&(String){87, 86, "struct Base\n  var Int x\nstruct Test(Base)\n  func mock()->(copy Int x)\n    x := base.x\n"}, &(String){35, 34, "calling \"base\" with non-method \"x\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode test_meth_code(String* input_text, String* expected_output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_meth_code = "test-meth-code";
#define MR_FUNC_NAME _func_name_test_meth_code
Returncode test_meth_code(String* input_text, String* expected_output) {
  String* input = &(String){1024, 0, (char[1024]){0}};
  CHECK(359, String_copy(input, &(String){13, 12, "struct Base\n"}) )
  CHECK(360, String_concat(input, &(String){13, 12, "  var Int x\n"}) )
  CHECK(361, String_concat(input, &(String){16, 15, "  func methb()\n"}) )
  CHECK(362, String_concat(input, &(String){18, 17, "struct Mid(Base)\n"}) )
  CHECK(363, String_concat(input, &(String){16, 15, "  func methm()\n"}) )
  CHECK(364, String_concat(input, &(String){17, 16, "struct Top(Mid)\n"}) )
  CHECK(365, String_concat(input, &(String){16, 15, "  func methb()\n"}) )
  CHECK(366, String_concat(input, &(String){20, 19, "  func methm()\n    "}) )
  CHECK(367, String_concat(input, input_text) )
  CHECK(368, String_concat(input, &(String){2, 1, "\n"}) )
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(370, String_copy(expected, &(String){27, 26, "typedef struct Base Base;\n"}) )
  CHECK(371, String_concat(expected, &(String){25, 24, "typedef struct Mid Mid;\n"}) )
  CHECK(372, String_concat(expected, &(String){25, 24, "typedef struct Top Top;\n"}) )
  CHECK(373, String_concat(expected, &(String){15, 14, "struct Base {\n"}) )
  CHECK(374, String_concat(expected, &(String){10, 9, "  Int x;\n"}) )
  CHECK(375, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(376, String_concat(expected, &(String){14, 13, "struct Mid {\n"}) )
  CHECK(377, String_concat(expected, &(String){15, 14, "  Base _base;\n"}) )
  CHECK(378, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(379, String_concat(expected, &(String){14, 13, "struct Top {\n"}) )
  CHECK(380, String_concat(expected, &(String){14, 13, "  Mid _base;\n"}) )
  CHECK(381, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(382, String_concat(expected, &(String){36, 35, "Returncode Base_methb(Base* self);\n"}) )
  CHECK(383, String_concat(expected, &(String){34, 33, "Returncode Mid_methm(Mid* self);\n"}) )
  CHECK(384, String_concat(expected, &(String){34, 33, "Returncode Top_methb(Top* self);\n"}) )
  CHECK(385, String_concat(expected, &(String){34, 33, "Returncode Top_methm(Top* self);\n"}) )
  CHECK(386, String_concat(expected, &(String){37, 36, "Returncode Base_methb(Base* self) {\n"}) )
  CHECK(387, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(388, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(389, String_concat(expected, &(String){35, 34, "Returncode Mid_methm(Mid* self) {\n"}) )
  CHECK(390, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(391, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(392, String_concat(expected, &(String){35, 34, "Returncode Top_methb(Top* self) {\n"}) )
  CHECK(393, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(394, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(395, String_concat(expected, &(String){37, 36, "Returncode Top_methm(Top* self) {\n  "}) )
  CHECK(396, String_concat(expected, expected_output) )
  CHECK(397, String_concat(expected, &(String){15, 14, "\n  return OK;\n"}) )
  CHECK(398, String_concat(expected, &(String){2, 1, "}"}) )
  CHECK(399, test_global_scope(input, expected) )
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
  CHECK(403, test_code(&(String){15, 14, "i := 2 + (123)"}, &(String){15, 14, "i = 2 + (123);"}) )
  CHECK(404, test_code(&(String){11, 10, "i := (123)"}, &(String){9, 8, "i = 123;"}) )
  CHECK(405, test_code(&(String){25, 24, "i := (123 * (i - 4)) + 2"}, &(String){25, 24, "i = (123 * (i - 4)) + 2;"}) )
  CHECK(406, test_code_error(&(String){7, 6, "(error"}, &(String){29, 28, "expected \")\", got \"new-line\""}) )
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
  CHECK(410, test_code(&(String){9, 8, "i := - i"}, &(String){9, 8, "i = - i;"}) )
  CHECK(411, test_code(&(String){15, 14, "i := -\n      i"}, &(String){9, 8, "i = - i;"}) )
  CHECK(412, test_code(&(String){11, 10, "i := - - i"}, &(String){13, 12, "i = - (- i);"}) )
  CHECK(413, test_code(&(String){11, 10, "b := not b"}, &(String){9, 8, "b = ! b;"}) )
  CHECK(414, test_code(&(String){15, 14, "b := not i > 3"}, &(String){15, 14, "b = ! (i > 3);"}) )
  CHECK(415, test_code_error(&(String){5, 4, "[45]"}, &(String){15, 14, "unexpected \"[\""}) )
  CHECK(416, test_code_error(&(String){3, 2, "-["}, &(String){15, 14, "unexpected \"[\""}) )
  CHECK(417, test_code_error(&(String){4, 3, "+ 2"}, &(String){23, 22, "not unary operator \"+\""}) )
  CHECK(418, test_code_error(&(String){11, 10, "- (i := 2)"}, &(String){49, 48, "void expression given as operand to operator \"-\""}) )
  CHECK(421, test_code_error(&(String){10, 9, "- (i > 4)"}, &(String){48, 47, "operator \"-\" expected \"Int\" operand, got \"Bool\""}) )
  CHECK(424, test_code_error(&(String){6, 5, "not i"}, &(String){50, 49, "operator \"not\" expected \"Bool\" operand, got \"Int\""}) )
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
  CHECK(430, test_code(&(String){13, 12, "i := 23 + 54"}, &(String){13, 12, "i = 23 + 54;"}) )
  CHECK(431, test_code(&(String){34, 33, "i += (100 * 2) - (37 div 5 mod 2)"}, &(String){33, 32, "i += (100 * 2) - ((37 / 5) % 2);"}) )
  CHECK(434, test_code(&(String){19, 18, "i -= 12 *\n      13"}, &(String){14, 13, "i -= 12 * 13;"}) )
  CHECK(435, test_code(&(String){22, 21, "b := 3 < 5 or 23 > 37"}, &(String){26, 25, "b = (3 < 5) || (23 > 37);"}) )
  CHECK(436, test_code(&(String){25, 24, "b := 3 <= 5 and 23 >= 37"}, &(String){28, 27, "b = (3 <= 5) && (23 >= 37);"}) )
  CHECK(437, test_code(&(String){22, 21, "b := i = 5 or i != 37"}, &(String){27, 26, "b = (i == 5) || (i != 37);"}) )
  CHECK(438, test_code(&(String){24, 23, "b := 2 < i < 12 < 2 * i"}, &(String){45, 44, "b = ((2 < i) && (i < 12)) && (12 < (2 * i));"}) )
  CHECK(441, test_code(&(String){22, 21, "user Tb tb\n  tb := tc"}, &(String){36, 35, "Tb* tb = NULL;\n  tb = &(tc->_base);"}) )
  CHECK(444, test_code(&(String){8, 7, "t := tc"}, &(String){30, 29, "t = &(tc->_base._base._base);"}) )
  CHECK(445, test_code_error(&(String){8, 7, "345 @ 2"}, &(String){21, 20, "unknown operator \"@\""}) )
  CHECK(446, test_code_error(&(String){6, 5, "80 +("}, &(String){15, 14, "unexpected \"(\""}) )
  CHECK(447, test_code_error(&(String){10, 9, "1 + 2 * 3"}, &(String){51, 50, "ambiguous precedence between operators \"+\" and \"*\""}) )
  CHECK(450, test_code_error(&(String){25, 24, "1 < i or 2 < i and 3 < i"}, &(String){54, 53, "ambiguous precedence between operators \"or\" and \"and\""}) )
  CHECK(453, test_code_error(&(String){8, 7, "1 not 2"}, &(String){35, 34, "cannot use \"not\" as binary operand"}) )
  CHECK(455, test_code_error(&(String){7, 6, "1 := 2"}, &(String){41, 40, "assigning into non assignable expression"}) )
  CHECK(457, test_code_error(&(String){7, 6, "1 += 2"}, &(String){41, 40, "assigning into non assignable expression"}) )
  CHECK(459, test_code_error(&(String){7, 6, "1 -= 2"}, &(String){41, 40, "assigning into non assignable expression"}) )
  CHECK(461, test_int_operator_error(&(String){2, 1, "+"}) )
  CHECK(462, test_int_operator_error(&(String){2, 1, "-"}) )
  CHECK(463, test_int_operator_error(&(String){2, 1, "*"}) )
  CHECK(464, test_int_operator_error(&(String){4, 3, "div"}) )
  CHECK(465, test_int_operator_error(&(String){4, 3, "mod"}) )
  CHECK(466, test_int_operator_error(&(String){2, 1, "="}) )
  CHECK(467, test_int_operator_error(&(String){3, 2, "!="}) )
  CHECK(468, test_int_operator_error(&(String){2, 1, ">"}) )
  CHECK(469, test_int_operator_error(&(String){2, 1, "<"}) )
  CHECK(470, test_int_operator_error(&(String){3, 2, ">="}) )
  CHECK(471, test_int_operator_error(&(String){3, 2, "<="}) )
  CHECK(472, test_int_operator_error(&(String){3, 2, "+="}) )
  CHECK(473, test_int_operator_error(&(String){3, 2, "-="}) )
  CHECK(474, test_bool_operator_error(&(String){3, 2, "or"}) )
  CHECK(475, test_bool_operator_error(&(String){4, 3, "and"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode test_int_operator_error(String* operator);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_int_operator_error = "test-int-operator-error";
#define MR_FUNC_NAME _func_name_test_int_operator_error
Returncode test_int_operator_error(String* operator) {
  CHECK(478, test_operator_error(operator, &(String){4, 3, "Int"}, &(String){5, 4, "Bool"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode test_bool_operator_error(String* operator);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_bool_operator_error = "test-bool-operator-error";
#define MR_FUNC_NAME _func_name_test_bool_operator_error
Returncode test_bool_operator_error(String* operator) {
  CHECK(481, test_operator_error(operator, &(String){5, 4, "Bool"}, &(String){4, 3, "Int"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode test_operator_error(String* operator, String* expected_type, String* actual_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_operator_error = "test-operator-error";
#define MR_FUNC_NAME _func_name_test_operator_error
Returncode test_operator_error(String* operator, String* expected_type, String* actual_type) {
  String* input_text = &(String){128, 0, (char[128]){0}};
  CHECK(486, String_copy(input_text, &(String){3, 2, "2 "}) )
  CHECK(487, String_concat(input_text, operator) )
  CHECK(488, String_concat(input_text, &(String){9, 8, " (i > 4)"}) )
  String* expected_error = &(String){128, 0, (char[128]){0}};
  CHECK(490, String_copy(expected_error, &(String){11, 10, "operator \""}) )
  CHECK(491, String_concat(expected_error, operator) )
  CHECK(492, String_concat(expected_error, &(String){13, 12, "\" expected \""}) )
  CHECK(493, String_concat(expected_error, expected_type) )
  CHECK(494, String_concat(expected_error, &(String){17, 16, "\" operand, got \""}) )
  CHECK(495, String_concat(expected_error, actual_type) )
  CHECK(496, String_concat(expected_error, &(String){2, 1, "\""}) )
  CHECK(497, test_code_error(input_text, expected_error) )
  CHECK(498, String_copy(input_text, &(String){9, 8, "(i > 4) "}) )
  CHECK(499, String_concat(input_text, operator) )
  CHECK(500, String_concat(input_text, &(String){3, 2, " 2"}) )
  CHECK(501, test_code_error(input_text, expected_error) )
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
  CHECK(505, test_code(&(String){10, 9, "b := str?"}, &(String){17, 16, "b = str != NULL;"}) )
  CHECK(506, test_code(&(String){14, 13, "b := not str?"}, &(String){21, 20, "b = ! (str != NULL);"}) )
  CHECK(507, test_code_error(&(String){10, 9, "(i := 2)?"}, &(String){34, 33, "cannot use \"?\" on void expression"}) )
  CHECK(508, test_code_error(&(String){3, 2, "i?"}, &(String){29, 28, "cannot use \"?\" on type \"Int\""}) )
  return OK;
}
#undef MR_FUNC_NAME
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
