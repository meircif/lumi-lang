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
  CHECK(5, set_mock_file_text(&(String){128, 127, "struct Test\n  var Int num\nfunc mock(copy Int i, copy Char c, copy Bool b, user String str, user Array{Int} arr, user Test t)\n  "}) )
  CHECK(7, String_concat(mock_input_file_text, input_text) )
  CHECK(8, String_append(mock_input_file_text, '\n') )
  CHECK(9, write_syntax_tree() )
  String* expected_header = &(String){207, 206, "\ntypedef struct Test Test;\nstruct Test {\n  Int num;\n};\nReturncode mock(Int i, Char c, Bool b, String* str, Array* arr, Test* t);\nReturncode mock(Int i, Char c, Bool b, String* str, Array* arr, Test* t) {\n  "};
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
  CHECK(32, set_mock_file_text(&(String){25, 24, "func mock(copy Int i)\n  "}) )
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
  CHECK(57, test_code(&(String){12, 11, "i := -07520"}, &(String){12, 11, "i = -07520;"}) )
  CHECK(58, test_code(&(String){14, 13, "i := 0xfda940"}, &(String){14, 13, "i = 0xfda940;"}) )
  CHECK(59, test_code(&(String){15, 14, "i := -0xfda940"}, &(String){15, 14, "i = -0xfda940;"}) )
  CHECK(60, test_code(&(String){14, 13, "i := 0xFDA940"}, &(String){14, 13, "i = 0xFDA940;"}) )
  CHECK(61, test_code(&(String){15, 14, "i := -0xFDA940"}, &(String){15, 14, "i = -0xFDA940;"}) )
  CHECK(62, test_code_error(&(String){3, 2, "2a"}, &(String){20, 19, "illegal number \"2a\""}) )
  CHECK(63, test_code_error(&(String){3, 2, "0a"}, &(String){20, 19, "illegal number \"0a\""}) )
  CHECK(64, test_code_error(&(String){4, 3, "038"}, &(String){27, 26, "illegal octal number \"038\""}) )
  CHECK(65, test_code_error(&(String){6, 5, "0b021"}, &(String){30, 29, "illegal binary number \"0b021\""}) )
  CHECK(66, test_code_error(&(String){6, 5, "0xadg"}, &(String){35, 34, "illegal hexadecimal number \"0xadg\""}) )
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
  CHECK(70, test_code(&(String){9, 8, "c := 'a'"}, &(String){9, 8, "c = 'a';"}) )
  CHECK(71, test_code(&(String){10, 9, "c := '\\''"}, &(String){10, 9, "c = '\\'';"}) )
  CHECK(72, test_code(&(String){10, 9, "c := '\\n'"}, &(String){10, 9, "c = '\\n';"}) )
  CHECK(73, test_code(&(String){12, 11, "c := '\\x0f'"}, &(String){12, 11, "c = '\\x0f';"}) )
  CHECK(74, test_code(&(String){12, 11, "c := '\\xA9'"}, &(String){12, 11, "c = '\\xA9';"}) )
  CHECK(75, test_code(&(String){12, 11, "c := '\\270'"}, &(String){12, 11, "c = '\\270';"}) )
  CHECK(76, test_code_error(&(String){4, 3, "'''"}, &(String){33, 32, "illegal character constant \"'''\""}) )
  CHECK(77, test_code_error(&(String){4, 3, "'\\'"}, &(String){33, 32, "illegal character constant \"'\\'\""}) )
  CHECK(79, test_code_error(&(String){5, 4, "'aa'"}, &(String){34, 33, "illegal character constant \"'aa'\""}) )
  CHECK(80, test_code_error(&(String){5, 4, "'\\c'"}, &(String){34, 33, "illegal character constant \"'\\c'\""}) )
  CHECK(82, test_code_error(&(String){7, 6, "'aaaa'"}, &(String){36, 35, "illegal character constant \"'aaaa'\""}) )
  CHECK(84, test_code_error(&(String){8, 7, "'\\x6fg'"}, &(String){37, 36, "illegal character constant \"'\\x6fg'\""}) )
  CHECK(86, test_code_error(&(String){7, 6, "'\\058'"}, &(String){36, 35, "illegal character constant \"'\\058'\""}) )
  CHECK(88, test_code_error(&(String){3, 2, "''"}, &(String){32, 31, "illegal character constant \"''\""}) )
  CHECK(89, test_code_error(&(String){6, 5, "'aaa'"}, &(String){35, 34, "illegal character constant \"'aaa'\""}) )
  CHECK(91, test_code_error(&(String){8, 7, "'aaaaa'"}, &(String){37, 36, "illegal character constant \"'aaaaa'\""}) )
  CHECK(93, test_code_error(&(String){4, 3, "'aa"}, &(String){33, 32, "illegal character constant \"'aa\""}) )
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
  CHECK(98, test_code(&(String){21, 20, "str := \"some string\""}, &(String){199, 198, "String aux_String_0_Var = {0};\n  String* aux_String_0 = &aux_String_0_Var;\n  aux_String_0->max_length = 12;\n  aux_String_0->length = 11;\n  aux_String_0->values = \"some string\";\n  str = aux_String_0;"}) )
  CHECK(101, test_code_error(&(String){5, 4, "\"aaa"}, &(String){31, 30, "illegal string constant \"\"aaa\""}) )
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
  CHECK(105, test_code(&(String){9, 8, "str := _"}, &(String){12, 11, "str = NULL;"}) )
  CHECK(106, test_code(&(String){7, 6, "t := _"}, &(String){10, 9, "t = NULL;"}) )
  CHECK(107, test_code_error(&(String){7, 6, "i := _"}, &(String){33, 32, "cannot assign \"Empty\" into \"Int\""}) )
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
  CHECK(111, test_code(&(String){11, 10, "i := t.num"}, &(String){12, 11, "i = t->num;"}) )
  CHECK(112, test_code_error(&(String){6, 5, "error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(113, test_code_error(&(String){15, 14, "(i := 1).error"}, &(String){38, 37, "void expression has no member \"error\""}) )
  CHECK(115, test_global_scope_error(&(String){58, 57, "struct Test\n  var Int x\nfunc mock(user Test t)\n  t.error\n"}, &(String){34, 33, "type \"Test\" has no member \"error\""}) )
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
  CHECK(121, test_code(&(String){13, 12, "c := str[13]"}, &(String){75, 74, "if ((13) < 0 || (13) >= (str)->length) RAISE(4)\n  c = ((str)->values)[13];"}) )
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(125, String_copy(expected, &(String){32, 31, "String aux_String_0_Var = {0};\n"}) )
  CHECK(126, String_concat(expected, &(String){45, 44, "  String* aux_String_0 = &aux_String_0_Var;\n"}) )
  CHECK(127, String_concat(expected, &(String){32, 31, "  aux_String_0_Var.length = 6;\n"}) )
  CHECK(128, String_concat(expected, &(String){62, 61, "  aux_String_0_Var.max_length = aux_String_0_Var.length + 1;\n"}) )
  CHECK(130, String_concat(expected, &(String){50, 49, "  aux_String_0_Var.values = (str)->values + (2);\n"}) )
  CHECK(131, String_concat(expected, &(String){65, 64, "  if ((2) < 0 || (6) < 0 || (2) + (6) > (str)->length) RAISE(4)\n"}) )
  CHECK(133, String_concat(expected, &(String){22, 21, "  str = aux_String_0;"}) )
  CHECK(134, test_code(&(String){16, 15, "str := str[2:6]"}, expected) )
  CHECK(135, test_code(&(String){13, 12, "i := arr[13]"}, &(String){83, 82, "if ((13) < 0 || (13) >= (arr)->length) RAISE(4)\n  i = ((Int*)((arr)->values))[13];"}) )
  CHECK(138, test_code(&(String){16, 15, "arr := arr[2:6]"}, &(String){242, 241, "Array aux_Array_0_Var = {0};\n  Array* aux_Array_0 = &aux_Array_0_Var;\n  aux_Array_0_Var.length = 6;\n  aux_Array_0_Var.values = (Byte*)((arr)->values) + (2);\n  if ((2) < 0 || (6) < 0 || (2) + (6) > (arr)->length) RAISE(4)\n  arr = aux_Array_0;"}) )
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
  CHECK(143, test_global_scope(&(String){31, 30, "func fun()\nfunc mock()\n  fun()"}, &(String){141, 140, "Returncode fun(void);\nReturncode mock(void);\nReturncode fun(void) {\n  return OK;\n}\nReturncode mock(void) {\n  CHECK(3, fun() )\n  return OK;\n}"}) )
  CHECK(146, test_global_scope(&(String){108, 107, "func fun(copy Int x, user String s, owner String o)\nfunc mock(user String s)\n  fun(copy 3, user s, owner _)"}, &(String){207, 206, "Returncode fun(Int x, String* s, String* o);\nReturncode mock(String* s);\nReturncode fun(Int x, String* s, String* o) {\n  return OK;\n}\nReturncode mock(String* s) {\n  CHECK(3, fun(3, s, NULL) )\n  return OK;\n}"}) )
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(150, String_copy(expected, &(String){37, 36, "Returncode fun(String** s, Int* x);\n"}) )
  CHECK(151, String_concat(expected, &(String){38, 37, "Returncode mock(String** s, Int* x);\n"}) )
  CHECK(152, String_concat(expected, &(String){38, 37, "Returncode fun(String** s, Int* x) {\n"}) )
  CHECK(153, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(154, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(155, String_concat(expected, &(String){39, 38, "Returncode mock(String** s, Int* x) {\n"}) )
  CHECK(156, String_concat(expected, &(String){14, 13, "  Int n = 0;\n"}) )
  CHECK(157, String_concat(expected, &(String){21, 20, "  String* t = NULL;\n"}) )
  CHECK(158, String_concat(expected, &(String){32, 31, "  CHECK(3, fun(&(*s), &(*x)) )\n"}) )
  CHECK(159, String_concat(expected, &(String){30, 29, "  CHECK(6, fun(&(t), &(n)) )\n"}) )
  CHECK(160, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(161, String_concat(expected, &(String){2, 1, "}"}) )
  CHECK(162, test_global_scope(&(String){166, 165, "func fun()->(owner String s, copy Int x)\nfunc mock()->(owner String s, copy Int x)\n  fun()->(owner s, copy x)\n  var Int n\n  owner String t\n  fun()->(owner t, copy n)"}, expected) )
  CHECK(165, test_global_scope(&(String){94, 93, "func fun(copy Int x)->(owner String s)\nfunc mock()->(owner String s)\n  fun(copy 0)->(owner s)"}, &(String){187, 186, "Returncode fun(Int x, String** s);\nReturncode mock(String** s);\nReturncode fun(Int x, String** s) {\n  return OK;\n}\nReturncode mock(String** s) {\n  CHECK(3, fun(0, &(*s)) )\n  return OK;\n}"}) )
  CHECK(168, String_copy(expected, &(String){24, 23, "Returncode fun(Int x);\n"}) )
  CHECK(169, String_concat(expected, &(String){32, 31, "Returncode joy(Int x, Int* r);\n"}) )
  CHECK(170, String_concat(expected, &(String){24, 23, "Returncode mock(void);\n"}) )
  CHECK(171, String_concat(expected, &(String){25, 24, "Returncode fun(Int x) {\n"}) )
  CHECK(172, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(173, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(174, String_concat(expected, &(String){33, 32, "Returncode joy(Int x, Int* r) {\n"}) )
  CHECK(175, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(176, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(177, String_concat(expected, &(String){25, 24, "Returncode mock(void) {\n"}) )
  CHECK(178, String_concat(expected, &(String){14, 13, "  Int x = 0;\n"}) )
  CHECK(179, String_concat(expected, &(String){27, 26, "  CHECK(5, joy(3, &(x)) )\n"}) )
  CHECK(180, String_concat(expected, &(String){21, 20, "  CHECK(5, fun(x) )\n"}) )
  CHECK(181, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(182, String_concat(expected, &(String){2, 1, "}"}) )
  CHECK(183, test_global_scope(&(String){114, 113, "func fun(copy Int x)\nfunc joy(copy Int x)->(copy Int r)\nfunc mock()\n  var Int x\n  fun(copy joy(copy 3)->(copy x))"}, expected) )
  CHECK(186, test_global_scope(&(String){163, 162, "func fun(copy Int x, copy Int y)->(copy Int n, copy Int m)\nfunc mock()->(copy Int n, copy Int m)\n  fun(\n      copy 2,\n      copy 3)->(\n      copy n,\n      copy m)"}, &(String){227, 226, "Returncode fun(Int x, Int y, Int* n, Int* m);\nReturncode mock(Int* n, Int* m);\nReturncode fun(Int x, Int y, Int* n, Int* m) {\n  return OK;\n}\nReturncode mock(Int* n, Int* m) {\n  CHECK(3, fun(2, 3, &(*n), &(*m)) )\n  return OK;\n}"}) )
  CHECK(189, test_global_scope(&(String){64, 63, "func fun()->(copy Int x)\nfunc mock()->(copy Int x)\n  x := fun()"}, &(String){200, 199, "Returncode fun(Int* x);\nReturncode mock(Int* x);\nReturncode fun(Int* x) {\n  return OK;\n}\nReturncode mock(Int* x) {\n  Int aux_Int_0 = 0;\n  CHECK(3, fun(&(aux_Int_0)) )\n  *x = aux_Int_0;\n  return OK;\n}"}) )
  CHECK(192, test_global_scope(&(String){70, 69, "func fun()->(user String s)\nfunc mock()->(user String s)\n  s := fun()"}, &(String){232, 231, "Returncode fun(String** s);\nReturncode mock(String** s);\nReturncode fun(String** s) {\n  return OK;\n}\nReturncode mock(String** s) {\n  String* aux_String_0 = NULL;\n  CHECK(3, fun(&(aux_String_0)) )\n  *s = aux_String_0;\n  return OK;\n}"}) )
  CHECK(195, test_code_error(&(String){18, 17, "function( copy 1)"}, &(String){25, 24, "expected access, got \" \""}) )
  CHECK(197, test_code_error(&(String){15, 14, "function(user)"}, &(String){37, 36, "expected space after access, got \")\""}) )
  CHECK(199, test_code_error(&(String){24, 23, "function(copy 4,copy 3)"}, &(String){46, 45, "expected space or new-line after \",\", got \"c\""}) )
  CHECK(202, test_code_error(&(String){16, 15, "function(copy 2"}, &(String){36, 35, "expected \",\" or \")\", got \"new-line\""}) )
  CHECK(204, test_code_error(&(String){18, 17, "function(error 4)"}, &(String){23, 22, "illegal access \"error\""}) )
  CHECK(206, test_code_error(&(String){11, 10, "(i := 0)()"}, &(String){32, 31, "void expression is not callable"}) )
  CHECK(208, test_code_error(&(String){4, 3, "i()"}, &(String){24, 23, "non callable type \"Int\""}) )
  CHECK(210, test_global_scope_error(&(String){56, 55, "func fun()->(copy Int x)\nfunc mock()\n  fun()->(copy 4)\n"}, &(String){27, 26, "non assignable call output"}) )
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
  CHECK(216, test_global_scope(&(String){80, 79, "struct Test\n  var Int x\n  func meth()\nfunc mock(user Test t)\n  Test.meth(var t)"}, &(String){230, 229, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};\nReturncode Test_meth(Test* self);\nReturncode mock(Test* t);\nReturncode Test_meth(Test* self) {\n  return OK;\n}\nReturncode mock(Test* t) {\n  CHECK(5, Test_meth(t) )\n  return OK;\n}"}) )
  CHECK(219, test_code_error(&(String){6, 5, "Error"}, &(String){21, 20, "unknown type \"Error\""}) )
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
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(224, String_copy(expected, &(String){27, 26, "typedef struct Base Base;\n"}) )
  CHECK(225, String_concat(expected, &(String){27, 26, "typedef struct Test Test;\n"}) )
  CHECK(226, String_concat(expected, &(String){15, 14, "struct Base {\n"}) )
  CHECK(227, String_concat(expected, &(String){10, 9, "  Int x;\n"}) )
  CHECK(228, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(229, String_concat(expected, &(String){15, 14, "struct Test {\n"}) )
  CHECK(230, String_concat(expected, &(String){15, 14, "  Base _base;\n"}) )
  CHECK(231, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(232, String_concat(expected, &(String){35, 34, "Returncode Base_meth(Base* self);\n"}) )
  CHECK(233, String_concat(expected, &(String){35, 34, "Returncode Test_meth(Test* self);\n"}) )
  CHECK(234, String_concat(expected, &(String){36, 35, "Returncode Base_meth(Base* self) {\n"}) )
  CHECK(235, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(236, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(237, String_concat(expected, &(String){36, 35, "Returncode Test_meth(Test* self) {\n"}) )
  CHECK(238, String_concat(expected, &(String){40, 39, "  CHECK(6, Base_meth(&(self->_base)) )\n"}) )
  CHECK(239, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(240, String_concat(expected, &(String){2, 1, "}"}) )
  CHECK(241, test_global_scope(&(String){86, 85, "struct Base\n  var Int x\n  func meth()\nstruct Test(Base)\n  func meth()\n    base.meth()"}, expected) )
  CHECK(244, test_code_error(&(String){5, 4, "base"}, &(String){26, 25, "\"base\" used not in method"}) )
  CHECK(245, test_global_scope_error(&(String){48, 47, "struct Test\n  var Int x\n  func mock()\n    base\n"}, &(String){29, 28, "no base type for type \"Test\""}) )
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
  CHECK(251, test_code(&(String){15, 14, "i := 2 + (123)"}, &(String){15, 14, "i = 2 + (123);"}) )
  CHECK(252, test_code(&(String){11, 10, "i := (123)"}, &(String){9, 8, "i = 123;"}) )
  CHECK(253, test_code(&(String){25, 24, "i := (123 * (i - 4)) + 2"}, &(String){25, 24, "i = (123 * (i - 4)) + 2;"}) )
  CHECK(254, test_code_error(&(String){7, 6, "(error"}, &(String){29, 28, "expected \")\", got \"new-line\""}) )
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
  CHECK(258, test_code(&(String){9, 8, "i := - i"}, &(String){9, 8, "i = - i;"}) )
  CHECK(259, test_code(&(String){15, 14, "i := -\n      i"}, &(String){9, 8, "i = - i;"}) )
  CHECK(260, test_code(&(String){11, 10, "i := - - i"}, &(String){13, 12, "i = - (- i);"}) )
  CHECK(261, test_code(&(String){11, 10, "b := not b"}, &(String){9, 8, "b = ! b;"}) )
  CHECK(262, test_code(&(String){15, 14, "b := not i > 3"}, &(String){15, 14, "b = ! (i > 3);"}) )
  CHECK(263, test_code_error(&(String){5, 4, "[45]"}, &(String){15, 14, "unexpected \"[\""}) )
  CHECK(264, test_code_error(&(String){3, 2, "-["}, &(String){15, 14, "unexpected \"[\""}) )
  CHECK(265, test_code_error(&(String){4, 3, "+ 2"}, &(String){23, 22, "not unary operator \"+\""}) )
  CHECK(266, test_code_error(&(String){11, 10, "- (i := 2)"}, &(String){49, 48, "void expression given as operand to operator \"-\""}) )
  CHECK(269, test_code_error(&(String){10, 9, "- (i > 4)"}, &(String){48, 47, "operator \"-\" expected \"Int\" operand, got \"Bool\""}) )
  CHECK(272, test_code_error(&(String){6, 5, "not i"}, &(String){50, 49, "operator \"not\" expected \"Bool\" operand, got \"Int\""}) )
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
  CHECK(278, test_code(&(String){13, 12, "i := 23 + 54"}, &(String){13, 12, "i = 23 + 54;"}) )
  CHECK(279, test_code(&(String){34, 33, "i += (100 * 2) - (37 div 5 mod 2)"}, &(String){33, 32, "i += (100 * 2) - ((37 / 5) % 2);"}) )
  CHECK(282, test_code(&(String){19, 18, "i -= 12 *\n      13"}, &(String){14, 13, "i -= 12 * 13;"}) )
  CHECK(283, test_code(&(String){22, 21, "b := 3 < 5 or 23 > 37"}, &(String){26, 25, "b = (3 < 5) || (23 > 37);"}) )
  CHECK(284, test_code(&(String){25, 24, "b := 3 <= 5 and 23 >= 37"}, &(String){28, 27, "b = (3 <= 5) && (23 >= 37);"}) )
  CHECK(285, test_code(&(String){22, 21, "b := i = 5 or i != 37"}, &(String){27, 26, "b = (i == 5) || (i != 37);"}) )
  CHECK(286, test_code(&(String){24, 23, "b := 2 < i < 12 < 2 * i"}, &(String){45, 44, "b = ((2 < i) && (i < 12)) && (12 < (2 * i));"}) )
  CHECK(289, test_code_error(&(String){8, 7, "345 @ 2"}, &(String){21, 20, "unknown operator \"@\""}) )
  CHECK(290, test_code_error(&(String){6, 5, "80 +("}, &(String){15, 14, "unexpected \"(\""}) )
  CHECK(291, test_code_error(&(String){10, 9, "1 + 2 * 3"}, &(String){51, 50, "ambiguous precedence between operators \"+\" and \"*\""}) )
  CHECK(294, test_code_error(&(String){25, 24, "1 < i or 2 < i and 3 < i"}, &(String){54, 53, "ambiguous precedence between operators \"or\" and \"and\""}) )
  CHECK(297, test_code_error(&(String){8, 7, "1 not 2"}, &(String){35, 34, "cannot use \"not\" as binary operand"}) )
  CHECK(299, test_code_error(&(String){7, 6, "1 := 2"}, &(String){41, 40, "assigning into non assignable expression"}) )
  CHECK(301, test_code_error(&(String){7, 6, "1 += 2"}, &(String){41, 40, "assigning into non assignable expression"}) )
  CHECK(303, test_code_error(&(String){7, 6, "1 -= 2"}, &(String){41, 40, "assigning into non assignable expression"}) )
  CHECK(305, test_int_operator_error(&(String){2, 1, "+"}) )
  CHECK(306, test_int_operator_error(&(String){2, 1, "-"}) )
  CHECK(307, test_int_operator_error(&(String){2, 1, "*"}) )
  CHECK(308, test_int_operator_error(&(String){4, 3, "div"}) )
  CHECK(309, test_int_operator_error(&(String){4, 3, "mod"}) )
  CHECK(310, test_int_operator_error(&(String){2, 1, "="}) )
  CHECK(311, test_int_operator_error(&(String){3, 2, "!="}) )
  CHECK(312, test_int_operator_error(&(String){2, 1, ">"}) )
  CHECK(313, test_int_operator_error(&(String){2, 1, "<"}) )
  CHECK(314, test_int_operator_error(&(String){3, 2, ">="}) )
  CHECK(315, test_int_operator_error(&(String){3, 2, "<="}) )
  CHECK(316, test_int_operator_error(&(String){3, 2, "+="}) )
  CHECK(317, test_int_operator_error(&(String){3, 2, "-="}) )
  CHECK(318, test_bool_operator_error(&(String){3, 2, "or"}) )
  CHECK(319, test_bool_operator_error(&(String){4, 3, "and"}) )
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
  CHECK(322, test_operator_error(operator, &(String){4, 3, "Int"}, &(String){5, 4, "Bool"}) )
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
  CHECK(325, test_operator_error(operator, &(String){5, 4, "Bool"}, &(String){4, 3, "Int"}) )
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
  CHECK(330, String_copy(input_text, &(String){3, 2, "2 "}) )
  CHECK(331, String_concat(input_text, operator) )
  CHECK(332, String_concat(input_text, &(String){9, 8, " (i > 4)"}) )
  String* expected_error = &(String){128, 0, (char[128]){0}};
  CHECK(334, String_copy(expected_error, &(String){11, 10, "operator \""}) )
  CHECK(335, String_concat(expected_error, operator) )
  CHECK(336, String_concat(expected_error, &(String){13, 12, "\" expected \""}) )
  CHECK(337, String_concat(expected_error, expected_type) )
  CHECK(338, String_concat(expected_error, &(String){17, 16, "\" operand, got \""}) )
  CHECK(339, String_concat(expected_error, actual_type) )
  CHECK(340, String_concat(expected_error, &(String){2, 1, "\""}) )
  CHECK(341, test_code_error(input_text, expected_error) )
  CHECK(342, String_copy(input_text, &(String){9, 8, "(i > 4) "}) )
  CHECK(343, String_concat(input_text, operator) )
  CHECK(344, String_concat(input_text, &(String){3, 2, " 2"}) )
  CHECK(345, test_code_error(input_text, expected_error) )
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
  CHECK(349, test_code(&(String){10, 9, "b := str?"}, &(String){17, 16, "b = str != NULL;"}) )
  CHECK(350, test_code(&(String){14, 13, "b := not str?"}, &(String){21, 20, "b = ! (str != NULL);"}) )
  CHECK(351, test_code_error(&(String){10, 9, "(i := 2)?"}, &(String){34, 33, "cannot use \"?\" on void expression"}) )
  CHECK(352, test_code_error(&(String){3, 2, "i?"}, &(String){29, 28, "cannot use \"?\" on type \"Int\""}) )
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
