#ifndef MR_MAINFILE
#define MR_MAINFILE "tests/syntax-tree-tests.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file25_name = "tests/syntax-tree-tests.3.mr";
#endif
#define MR_FILE_NAME _mr_file25_name

/* MR4 compiler tests - Syntax tree */

#if MR_STAGE == MR_DECLARATIONS
Returncode write_syntax_tree();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_syntax_tree = "write-syntax-tree";
#define MR_FUNC_NAME _func_name_write_syntax_tree
Returncode write_syntax_tree() {
  Array* mock_argv = &(Array){3, (String[3]){0}};
  _set_var_string_array(3, 256, mock_argv, (char[256 * 3]){0});
  if ((2) < 0 || (2) >= (mock_argv)->length) RAISE(5)
  CHECK(5, String_copy((&(((String*)((mock_argv)->values))[2])), &(String){10, 9, "mock.3.mr"}) )
  SyntaxTreeRoot* root = &(SyntaxTreeRoot){SyntaxTreeRoot__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL};
  root->_base._base._base._dtl = SyntaxTreeRoot__dtl;
  CHECK(7, SyntaxTreeRoot_parse(glob->root, mock_argv) )
  CHECK(8, (glob->root)->_base._base._base._dtl[1](glob->root) )
  CHECK(9, (glob->root)->_base._base._base._dtl[2](glob->root) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_global_scope(String* input_text, String* expected_output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_global_scope = "test-global-scope";
#define MR_FUNC_NAME _func_name_test_global_scope
Returncode test_global_scope(String* input_text, String* expected_output) {
  CHECK(13, f_setup_test() )
  CHECK(14, set_mock_file_text(input_text) )
  CHECK(15, String_append(mock_input_file_text, '\n') )
  CHECK(16, write_syntax_tree() )
  if ((0) < 0 || (0) >= (mock_output_file_text)->length) RAISE(17)
  if (((mock_output_file_text)->values[0]) != '\n') {
    CHECK(18, print(mock_output_file_text) )
  }
  if ((0) < 0 || (0) >= (mock_output_file_text)->length) RAISE(19)
  TEST_ASSERT(19, ((mock_output_file_text)->values[0]) == '\n')
  CHECK(20, f_assert_string_slice(expected_output, mock_output_file_text, 1, mock_output_file_text->length - 2) )
  if ((mock_output_file_text->length - 1) < 0 || (mock_output_file_text->length - 1) >= (mock_output_file_text)->length) RAISE(25)
  TEST_ASSERT(25, ((mock_output_file_text)->values[mock_output_file_text->length - 1]) == '\n')
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_global_scope_error(String* input_text, String* expected_error);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_global_scope_error = "test-global-scope-error";
#define MR_FUNC_NAME _func_name_test_global_scope_error
Returncode test_global_scope_error(String* input_text, String* expected_error) {
  CHECK(29, f_setup_test() )
  CHECK(30, set_mock_file_text(input_text) )
  mock_print_active = true;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(32, write_syntax_tree() );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(32)
  } while (false);
  _trace_stream = stdout;
  mock_print_active = false;
  String* expected_header = &(String){25, 24, "Code error in mock.3.mr["};
  CHECK(35, f_assert_string_slice(expected_header, mock_print_text, 0, expected_header->length) )
  CHECK(40, f_assert_string_slice(expected_error, mock_print_text, expected_header->length + 3, mock_print_text->length - expected_header->length - 4) )
  if ((mock_print_text->length - 1) < 0 || (mock_print_text->length - 1) >= (mock_print_text)->length) RAISE(45)
  TEST_ASSERT(45, ((mock_print_text)->values[mock_print_text->length - 1]) == '\n')
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_general();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_general = "test-general";
#define MR_FUNC_NAME _func_name_test_general
Returncode test_general() {
  CHECK(49, test_global_scope(&(String){16, 15, "user String str"}, &(String){13, 12, "String* str;"}) )
  String* expected = &(String){7, 6, "Int x;"};
  CHECK(51, test_global_scope(&(String){15, 14, "\n  \n\nvar Int x"}, expected) )
  CHECK(52, test_global_scope(&(String){21, 20, "# comment\n\nvar Int x"}, expected) )
  CHECK(53, test_global_scope(&(String){28, 27, "## documemtation\n\nvar Int x"}, expected) )
  CHECK(54, test_global_scope(&(String){40, 39, "{# multi \n line \n comment #}\n\nvar Int x"}, expected) )
  CHECK(56, test_global_scope(&(String){47, 46, "{## multi \n line \n documemtation #}\n\nvar Int x"}, expected) )
  CHECK(58, test_global_scope_error(&(String){7, 6, "error "}, &(String){24, 23, "unknown keyword \"error\""}) )
  CHECK(59, test_code_error(&(String){6, 5, "1 + 2"}, &(String){25, 24, "statememnt has no effect"}) )
  CHECK(60, test_global_scope_error(&(String){15, 14, "{# comment #}?"}, &(String){39, 38, "expected new-line in line end, got \"?\""}) )
  CHECK(62, test_global_scope_error(&(String){7, 6, "main(\n"}, &(String){40, 39, "expected new-line after \"main\", got \"(\""}) )
  CHECK(64, test_global_scope_error(&(String){14, 13, "  struct Test"}, &(String){42, 41, "indentation too big, expected \"0\" got \"2\""}) )
  CHECK(67, test_global_scope_error(&(String){10, 9, "var Int x"}, &(String){28, 27, "no new-line before file end"}) )
  CHECK(70, test_global_scope_error(&(String){27, 26, "var Int name\nvar Int name\n"}, &(String){39, 38, "redefinition of global variable \"name\""}) )
  CHECK(73, test_global_scope_error(&(String){25, 24, "func name()\nvar Int name"}, &(String){40, 39, "variable name overrides function \"name\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_struct();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_struct = "test-struct";
#define MR_FUNC_NAME _func_name_test_struct
Returncode test_struct() {
  CHECK(79, test_global_scope(&(String){24, 23, "struct Test\n  var Int x"}, &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"}) )
  CHECK(82, test_global_scope(&(String){24, 23, "struct Test\n  var Int x"}, &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"}) )
  CHECK(85, test_global_scope(&(String){77, 76, "struct Test1\n  var Int x\nstruct Test2\n  var Int x\n\n\nstruct Test3\n  var Int x"}, &(String){165, 164, "typedef struct Test1 Test1;\ntypedef struct Test2 Test2;\ntypedef struct Test3 Test3;\nstruct Test1 {\n  Int x;\n};\nstruct Test2 {\n  Int x;\n};\nstruct Test3 {\n  Int x;\n};"}) )
  CHECK(88, test_global_scope(&(String){57, 56, "struct Test2(Test1)\n  var Int y\nstruct Test1\n  var Int x"}, &(String){125, 124, "typedef struct Test1 Test1;\ntypedef struct Test2 Test2;\nstruct Test1 {\n  Int x;\n};\nstruct Test2 {\n  Test1 _base;\n  Int y;\n};"}) )
  CHECK(91, test_global_scope_error(&(String){9, 8, "struct(\n"}, &(String){39, 38, "expected space after \"struct\", got \"(\""}) )
  CHECK(93, test_global_scope_error(&(String){14, 13, "struct error\n"}, &(String){26, 25, "illegal type name \"error\""}) )
  CHECK(95, test_global_scope_error(&(String){15, 14, "struct ERrror\n"}, &(String){27, 26, "illegal type name \"ERrror\""}) )
  CHECK(97, test_global_scope_error(&(String){19, 18, "struct Error-name\n"}, &(String){31, 30, "illegal type name \"Error-name\""}) )
  CHECK(99, test_global_scope_error(&(String){12, 11, "struct Int\n"}, &(String){27, 26, "redefinition of type \"Int\""}) )
  CHECK(101, test_global_scope_error(&(String){25, 24, "struct Test\nstruct Test\n"}, &(String){28, 27, "redefinition of type \"Test\""}) )
  CHECK(103, test_global_scope_error(&(String){18, 17, "struct Test(Base\n"}, &(String){45, 44, "expected \")\" after base type, got \"new-line\""}) )
  CHECK(106, test_global_scope_error(&(String){21, 20, "struct Test\n  error "}, &(String){24, 23, "unknown keyword \"error\""}) )
  CHECK(108, test_global_scope_error(&(String){12, 11, "struct Test"}, &(String){40, 39, "expected block in a new line, got \"EOF\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_class();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_class = "test-class";
#define MR_FUNC_NAME _func_name_test_class
Returncode test_class() {
  String* input = &(String){1024, 0, (char[1024]){0}};
  CHECK(114, String_copy(input, &(String){12, 11, "class Base\n"}) )
  CHECK(115, String_concat(input, &(String){13, 12, "  var Int x\n"}) )
  CHECK(116, String_concat(input, &(String){20, 19, "  func inst stat()\n"}) )
  CHECK(117, String_concat(input, &(String){23, 22, "  func dynamic dyn0()\n"}) )
  CHECK(118, String_concat(input, &(String){23, 22, "  func dynamic dyn1()\n"}) )
  CHECK(119, String_concat(input, &(String){17, 16, "class Mid(Base)\n"}) )
  CHECK(120, String_concat(input, &(String){13, 12, "  var Int y\n"}) )
  CHECK(121, String_concat(input, &(String){23, 22, "  func dynamic dyn0()\n"}) )
  CHECK(122, String_concat(input, &(String){23, 22, "  func dynamic dyn2()\n"}) )
  CHECK(123, String_concat(input, &(String){16, 15, "class Top(Mid)\n"}) )
  CHECK(124, String_concat(input, &(String){13, 12, "  var Int z\n"}) )
  CHECK(125, String_concat(input, &(String){23, 22, "  func dynamic dyn0()\n"}) )
  CHECK(126, String_concat(input, &(String){23, 22, "  func dynamic dyn3()\n"}) )
  CHECK(127, String_concat(input, &(String){17, 16, "    base.dyn0()\n"}) )
  
  String* expected = &(String){2048, 0, (char[2048]){0}};
  CHECK(130, String_copy(expected, &(String){27, 26, "typedef struct Base Base;\n"}) )
  CHECK(131, String_concat(expected, &(String){43, 42, "typedef struct Base_Dynamic Base_Dynamic;\n"}) )
  CHECK(132, String_concat(expected, &(String){25, 24, "typedef struct Mid Mid;\n"}) )
  CHECK(133, String_concat(expected, &(String){41, 40, "typedef struct Mid_Dynamic Mid_Dynamic;\n"}) )
  CHECK(134, String_concat(expected, &(String){25, 24, "typedef struct Top Top;\n"}) )
  CHECK(135, String_concat(expected, &(String){41, 40, "typedef struct Top_Dynamic Top_Dynamic;\n"}) )
  
  CHECK(137, String_concat(expected, &(String){15, 14, "struct Base {\n"}) )
  CHECK(138, String_concat(expected, &(String){10, 9, "  Int x;\n"}) )
  CHECK(139, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(140, String_concat(expected, &(String){23, 22, "struct Base_Dynamic {\n"}) )
  CHECK(141, String_concat(expected, &(String){32, 31, "  Returncode (*dyn0)(Base* self"}) )
  CHECK(142, String_concat(expected, &(String){32, 31, ", Base_Dynamic* self_Dynamic);\n"}) )
  CHECK(143, String_concat(expected, &(String){32, 31, "  Returncode (*dyn1)(Base* self"}) )
  CHECK(144, String_concat(expected, &(String){32, 31, ", Base_Dynamic* self_Dynamic);\n"}) )
  CHECK(145, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(146, String_concat(expected, &(String){14, 13, "struct Mid {\n"}) )
  CHECK(147, String_concat(expected, &(String){15, 14, "  Base _base;\n"}) )
  CHECK(148, String_concat(expected, &(String){10, 9, "  Int y;\n"}) )
  CHECK(149, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(150, String_concat(expected, &(String){22, 21, "struct Mid_Dynamic {\n"}) )
  CHECK(151, String_concat(expected, &(String){23, 22, "  Base_Dynamic _base;\n"}) )
  CHECK(152, String_concat(expected, &(String){31, 30, "  Returncode (*dyn2)(Mid* self"}) )
  CHECK(153, String_concat(expected, &(String){31, 30, ", Mid_Dynamic* self_Dynamic);\n"}) )
  CHECK(154, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(155, String_concat(expected, &(String){14, 13, "struct Top {\n"}) )
  CHECK(156, String_concat(expected, &(String){14, 13, "  Mid _base;\n"}) )
  CHECK(157, String_concat(expected, &(String){10, 9, "  Int z;\n"}) )
  CHECK(158, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(159, String_concat(expected, &(String){22, 21, "struct Top_Dynamic {\n"}) )
  CHECK(160, String_concat(expected, &(String){22, 21, "  Mid_Dynamic _base;\n"}) )
  CHECK(161, String_concat(expected, &(String){31, 30, "  Returncode (*dyn3)(Top* self"}) )
  CHECK(162, String_concat(expected, &(String){31, 30, ", Top_Dynamic* self_Dynamic);\n"}) )
  CHECK(163, String_concat(expected, &(String){4, 3, "};\n"}) )
  
  CHECK(165, String_concat(expected, &(String){32, 31, "Returncode Base_stat(Base* self"}) )
  CHECK(166, String_concat(expected, &(String){32, 31, ", Base_Dynamic* self_Dynamic);\n"}) )
  CHECK(167, String_concat(expected, &(String){32, 31, "Returncode Base_dyn0(Base* self"}) )
  CHECK(168, String_concat(expected, &(String){32, 31, ", Base_Dynamic* self_Dynamic);\n"}) )
  CHECK(169, String_concat(expected, &(String){32, 31, "Returncode Base_dyn1(Base* self"}) )
  CHECK(170, String_concat(expected, &(String){32, 31, ", Base_Dynamic* self_Dynamic);\n"}) )
  CHECK(171, String_concat(expected, &(String){30, 29, "Returncode Mid_dyn0(Mid* self"}) )
  CHECK(172, String_concat(expected, &(String){31, 30, ", Mid_Dynamic* self_Dynamic);\n"}) )
  CHECK(173, String_concat(expected, &(String){30, 29, "Returncode Mid_dyn2(Mid* self"}) )
  CHECK(174, String_concat(expected, &(String){31, 30, ", Mid_Dynamic* self_Dynamic);\n"}) )
  CHECK(175, String_concat(expected, &(String){30, 29, "Returncode Top_dyn0(Top* self"}) )
  CHECK(176, String_concat(expected, &(String){31, 30, ", Top_Dynamic* self_Dynamic);\n"}) )
  CHECK(177, String_concat(expected, &(String){30, 29, "Returncode Top_dyn3(Top* self"}) )
  CHECK(178, String_concat(expected, &(String){31, 30, ", Top_Dynamic* self_Dynamic);\n"}) )
  
  CHECK(180, String_concat(expected, &(String){53, 52, "Base_Dynamic Base_dynamic = {Base_dyn0, Base_dyn1};\n"}) )
  CHECK(181, String_concat(expected, &(String){55, 54, "Mid_Dynamic Mid_dynamic = {{(Func)Mid_dyn0, Base_dyn1}"}) )
  CHECK(182, String_concat(expected, &(String){14, 13, ", Mid_dyn2};\n"}) )
  CHECK(183, String_concat(expected, &(String){44, 43, "Top_Dynamic Top_dynamic = {{{(Func)Top_dyn0"}) )
  CHECK(184, String_concat(expected, &(String){37, 36, ", Base_dyn1}, Mid_dyn2}, Top_dyn3};\n"}) )
  
  CHECK(186, String_concat(expected, &(String){32, 31, "Returncode Base_stat(Base* self"}) )
  CHECK(187, String_concat(expected, &(String){33, 32, ", Base_Dynamic* self_Dynamic) {\n"}) )
  CHECK(188, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(189, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(190, String_concat(expected, &(String){32, 31, "Returncode Base_dyn0(Base* self"}) )
  CHECK(191, String_concat(expected, &(String){33, 32, ", Base_Dynamic* self_Dynamic) {\n"}) )
  CHECK(192, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(193, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(194, String_concat(expected, &(String){32, 31, "Returncode Base_dyn1(Base* self"}) )
  CHECK(195, String_concat(expected, &(String){33, 32, ", Base_Dynamic* self_Dynamic) {\n"}) )
  CHECK(196, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(197, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(198, String_concat(expected, &(String){30, 29, "Returncode Mid_dyn0(Mid* self"}) )
  CHECK(199, String_concat(expected, &(String){32, 31, ", Mid_Dynamic* self_Dynamic) {\n"}) )
  CHECK(200, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(201, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(202, String_concat(expected, &(String){30, 29, "Returncode Mid_dyn2(Mid* self"}) )
  CHECK(203, String_concat(expected, &(String){32, 31, ", Mid_Dynamic* self_Dynamic) {\n"}) )
  CHECK(204, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(205, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(206, String_concat(expected, &(String){30, 29, "Returncode Top_dyn0(Top* self"}) )
  CHECK(207, String_concat(expected, &(String){32, 31, ", Top_Dynamic* self_Dynamic) {\n"}) )
  CHECK(208, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(209, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(210, String_concat(expected, &(String){30, 29, "Returncode Top_dyn3(Top* self"}) )
  CHECK(211, String_concat(expected, &(String){32, 31, ", Top_Dynamic* self_Dynamic) {\n"}) )
  CHECK(212, String_concat(expected, &(String){36, 35, "  CHECK(14, Mid_dyn0(&(self->_base)"}) )
  CHECK(213, String_concat(expected, &(String){29, 28, ", &(self_Dynamic->_base)) )\n"}) )
  CHECK(214, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(215, String_concat(expected, &(String){2, 1, "}"}) )
  
  CHECK(217, test_global_scope(input, expected) )
  CHECK(218, test_global_scope_error(&(String){8, 7, "class(\n"}, &(String){38, 37, "expected space after \"class\", got \"(\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_function();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_function = "test-function";
#define MR_FUNC_NAME _func_name_test_function
Returncode test_function() {
  CHECK(223, test_global_scope(&(String){12, 11, "func name()"}, &(String){62, 61, "Returncode name(void);\nReturncode name(void) {\n  return OK;\n}"}) )
  CHECK(226, test_global_scope(&(String){59, 58, "func name(var String self, user String text, copy Int num)"}, &(String){124, 123, "Returncode name(String* self, String* text, Int num);\nReturncode name(String* self, String* text, Int num) {\n  return OK;\n}"}) )
  CHECK(229, test_global_scope(&(String){47, 46, "func name()->(owner String text, copy Int num)"}, &(String){100, 99, "Returncode name(String** text, Int* num);\nReturncode name(String** text, Int* num) {\n  return OK;\n}"}) )
  CHECK(232, test_global_scope(&(String){47, 46, "func name(copy Char param)->(owner String out)"}, &(String){102, 101, "Returncode name(Char param, String** out);\nReturncode name(Char param, String** out) {\n  return OK;\n}"}) )
  CHECK(235, test_global_scope(&(String){33, 32, "func name(user Array{Int} array)"}, &(String){78, 77, "Returncode name(Array* array);\nReturncode name(Array* array) {\n  return OK;\n}"}) )
  CHECK(238, test_global_scope(&(String){74, 73, "func name(copy Func{(copy Int x)->(copy Int y)} fun)->(copy Func{()} joy)"}, &(String){170, 169, "Returncode name(Returncode (*fun)(Int x, Int* y), Returncode (**joy)(void));\nReturncode name(Returncode (*fun)(Int x, Int* y), Returncode (**joy)(void)) {\n  return OK;\n}"}) )
  CHECK(241, test_global_scope(&(String){24, 23, "func name()\n  var Int x"}, &(String){75, 74, "Returncode name(void);\nReturncode name(void) {\n  Int x = 0;\n  return OK;\n}"}) )
  CHECK(244, test_global_scope(&(String){17, 16, "main\n  var Int x"}, &(String){57, 56, "USER_MAIN_HEADER {\n  Int x = 0;\n  return OK;\n}\nMAIN_FUNC"}) )
  CHECK(247, test_global_scope_error(&(String){7, 6, "func(\n"}, &(String){37, 36, "expected space after \"func\", got \"(\""}) )
  CHECK(249, test_global_scope_error(&(String){11, 10, "func name\n"}, &(String){49, 48, "expected \"(\" after function name, got \"new-line\""}) )
  CHECK(252, test_global_scope_error(&(String){14, 13, "func Error()\n"}, &(String){30, 29, "illegal function name \"Error\""}) )
  CHECK(254, test_global_scope_error(&(String){19, 18, "func error_name()\n"}, &(String){35, 34, "illegal function name \"error_name\""}) )
  CHECK(256, test_global_scope_error(&(String){25, 24, "func name()\nfunc name()\n"}, &(String){32, 31, "redefinition of function \"name\""}) )
  CHECK(259, test_global_scope_error(&(String){26, 25, "var Int name\nfunc name()\n"}, &(String){47, 46, "function name overrides global variable \"name\""}) )
  CHECK(262, test_global_scope_error(&(String){14, 13, "func name( )\n"}, &(String){25, 24, "expected access, got \" \""}) )
  CHECK(264, test_global_scope_error(&(String){17, 16, "func name(user)\n"}, &(String){37, 36, "expected space after access, got \")\""}) )
  CHECK(266, test_global_scope_error(&(String){22, 21, "func name(var String\n"}, &(String){42, 41, "expected space after type, got \"new-line\""}) )
  CHECK(269, test_global_scope_error(&(String){24, 23, "func name(error Int x)\n"}, &(String){23, 22, "illegal access \"error\""}) )
  CHECK(271, test_global_scope_error(&(String){38, 37, "func name(var String str,user Int x)\n"}, &(String){46, 45, "expected space or new-line after \",\", got \"u\""}) )
  CHECK(274, test_global_scope_error(&(String){16, 15, "func name()-()\n"}, &(String){23, 22, "expected \">(\" got \"()\""}) )
  CHECK(276, test_global_scope_error(&(String){12, 11, "func name()"}, &(String){40, 39, "expected block in a new line, got \"EOF\""}) )
  CHECK(278, test_global_scope_error(&(String){26, 25, "func name()\n    var Int x"}, &(String){42, 41, "indentation too big, expected \"2\" got \"4\""}) )
  CHECK(281, test_global_scope_error(&(String){23, 22, "func name(user Int x)\n"}, &(String){69, 68, "argument \"x\" access should be \"copy\" for primitive types, got \"user\""}) )
  CHECK(284, test_global_scope_error(&(String){26, 25, "func name(copy String s)\n"}, &(String){73, 72, "argument \"s\" access should not be \"copy\" for non-primitive type \"String\""}) )
  CHECK(287, test_global_scope_error(&(String){29, 28, "func name(user Array error)\n"}, &(String){26, 25, "missing subtype for array"}) )
  CHECK(289, test_global_scope_error(&(String){28, 27, "func name(copy Func error)\n"}, &(String){35, 34, "missing arguments in function type"}) )
  CHECK(292, test_global_scope_error(&(String){41, 40, "func name(user Array{Array{Int}} error)\n"}, &(String){44, 43, "multidimensional array not supported yet..."}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_members();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_members = "test-members";
#define MR_FUNC_NAME _func_name_test_members
Returncode test_members() {
  CHECK(298, test_global_scope(&(String){42, 41, "struct Test\n  var Int x\n  user String str"}, &(String){67, 66, "typedef struct Test Test;\nstruct Test {\n  Int x;\n  String* str;\n};"}) )
  CHECK(301, test_global_scope(&(String){38, 37, "struct Test\n  var Int x\n  func name()"}, &(String){136, 135, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};\nReturncode Test_name(Test* self);\nReturncode Test_name(Test* self) {\n  return OK;\n}"}) )
  CHECK(304, test_global_scope(&(String){52, 51, "struct Test\n  var Int x\n  func name()\n    var Int x"}, &(String){149, 148, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};\nReturncode Test_name(Test* self);\nReturncode Test_name(Test* self) {\n  Int x = 0;\n  return OK;\n}"}) )
  String* expected = &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"};
  CHECK(308, test_global_scope(&(String){36, 35, "struct Test\n  # comment\n  var Int x"}, expected) )
  CHECK(309, test_global_scope(&(String){43, 42, "struct Test\n  ## documemtation\n  var Int x"}, expected) )
  CHECK(311, test_global_scope(&(String){55, 54, "struct Test\n  {# multi \n line \n comment #}\n  var Int x"}, expected) )
  CHECK(314, test_global_scope(&(String){62, 61, "struct Test\n  {## multi \n line \n documemtation #}\n  var Int x"}, expected) )
  String* output = &(String){1024, 0, (char[1024]){0}};
  CHECK(318, String_copy(output, &(String){29, 28, "typedef struct Test1 Test1;\n"}) )
  CHECK(319, String_concat(output, &(String){29, 28, "typedef struct Test2 Test2;\n"}) )
  CHECK(320, String_concat(output, &(String){16, 15, "struct Test1 {\n"}) )
  CHECK(321, String_concat(output, &(String){13, 12, "  Int name;\n"}) )
  CHECK(322, String_concat(output, &(String){4, 3, "};\n"}) )
  CHECK(323, String_concat(output, &(String){16, 15, "struct Test2 {\n"}) )
  CHECK(324, String_concat(output, &(String){12, 11, "  Int fun;\n"}) )
  CHECK(325, String_concat(output, &(String){4, 3, "};\n"}) )
  CHECK(326, String_concat(output, &(String){36, 35, "Returncode Test1_fun(Test1* self);\n"}) )
  CHECK(327, String_concat(output, &(String){37, 36, "Returncode Test2_name(Test2* self);\n"}) )
  CHECK(328, String_concat(output, &(String){11, 10, "Int name;\n"}) )
  CHECK(329, String_concat(output, &(String){23, 22, "Returncode fun(void);\n"}) )
  CHECK(330, String_concat(output, &(String){37, 36, "Returncode Test1_fun(Test1* self) {\n"}) )
  CHECK(331, String_concat(output, &(String){14, 13, "  return OK;\n"}) )
  CHECK(332, String_concat(output, &(String){3, 2, "}\n"}) )
  CHECK(333, String_concat(output, &(String){38, 37, "Returncode Test2_name(Test2* self) {\n"}) )
  CHECK(334, String_concat(output, &(String){14, 13, "  return OK;\n"}) )
  CHECK(335, String_concat(output, &(String){3, 2, "}\n"}) )
  CHECK(336, String_concat(output, &(String){24, 23, "Returncode fun(void) {\n"}) )
  CHECK(337, String_concat(output, &(String){14, 13, "  return OK;\n"}) )
  CHECK(338, String_concat(output, &(String){2, 1, "}"}) )
  CHECK(339, test_global_scope(&(String){107, 106, "var Int name\nfunc fun()\nstruct Test1\n  var Int name\n  func fun()\nstruct Test2\n  var Int fun\n  func name()\n"}, output) )
  CHECK(342, test_global_scope_error(&(String){43, 42, "struct Test\n  var Int name\n  var Int name\n"}, &(String){29, 28, "redefinition of field \"name\""}) )
  CHECK(345, test_global_scope_error(&(String){42, 41, "struct Test\n  func name()\n  var Int name\n"}, &(String){35, 34, "field name overrides method \"name\""}) )
  CHECK(348, test_global_scope_error(&(String){41, 40, "struct Test\n  func name()\n  func name()\n"}, &(String){30, 29, "redefinition of method \"name\""}) )
  CHECK(351, test_global_scope_error(&(String){42, 41, "struct Test\n  var Int name\n  func name()\n"}, &(String){35, 34, "method name overrides field \"name\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_return();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_return = "test-return";
#define MR_FUNC_NAME _func_name_test_return
Returncode test_return() {
  CHECK(357, test_global_scope(&(String){21, 20, "func name()\n  return"}, &(String){62, 61, "Returncode name(void);\nReturncode name(void) {\n  return OK;\n}"}) )
  CHECK(360, test_global_scope(&(String){20, 19, "func name()\n  raise"}, &(String){60, 59, "Returncode name(void);\nReturncode name(void) {\n  RAISE(2)\n}"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_code_variables();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_code_variables = "test-code-variables";
#define MR_FUNC_NAME _func_name_test_code_variables
Returncode test_code_variables() {
  CHECK(366, test_code(&(String){10, 9, "var Int x"}, &(String){11, 10, "Int x = 0;"}) )
  CHECK(367, test_code(&(String){14, 13, "user String s"}, &(String){18, 17, "String* s = NULL;"}) )
  CHECK(368, test_code(&(String){19, 18, "owner Array{Int} a"}, &(String){17, 16, "Array* a = NULL;"}) )
  CHECK(369, test_code(&(String){13, 12, "user Test tt"}, &(String){17, 16, "Test* tt = NULL;"}) )
  CHECK(370, test_code(&(String){12, 11, "var Test tt"}, &(String){41, 40, "Test tt_Var = {0};\n  Test* tt = &tt_Var;"}) )
  CHECK(371, test_code(&(String){17, 16, "var String{12} s"}, &(String){100, 99, "char s_Values[12];\n  String s_Var = {12, 0, NULL};\n  String* s = &s_Var;\n  s_Var.values = s_Values;"}) )
  CHECK(374, test_code(&(String){20, 19, "var Array{12:Int} a"}, &(String){94, 93, "Int a_Values[12];\n  Array a_Var = {12, NULL};\n  Array* a = &a_Var;\n  a_Var.values = a_Values;"}) )
  CHECK(377, test_code(&(String){21, 20, "var Array{12:Test} a"}, &(String){95, 94, "Test a_Values[12];\n  Array a_Var = {12, NULL};\n  Array* a = &a_Var;\n  a_Var.values = a_Values;"}) )
  CHECK(380, test_code(&(String){27, 26, "var Array{12:String{7}} sa"}, &(String){176, 175, "char sa_Chars[12 * 7];\n  String sa_Values[12];\n  Array sa_Var = {12, NULL};\n  Array* sa = &sa_Var;\n  sa_Var.values = sa_Values;\n  MR_set_var_string_array(12, 7, sa, sa_Chars);"}) )
  CHECK(383, test_code(&(String){12, 11, "t := Test()"}, &(String){118, 117, "Test* aux_Test_0 = NULL;\n  aux_Test_0 = calloc(1, sizeof(Test));\n  if (aux_Test_0 == NULL) RAISE(1)\n  t = aux_Test_0;"}) )
  CHECK(386, test_code(&(String){24, 23, "str := String{arr[0]}()"}, &(String){196, 195, "String* aux_String_0 = NULL;\n  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)\n  aux_String_0 = MR_new_string(((Int*)((arr)->values))[0]);\n  if (aux_String_0 == NULL) RAISE(1)\n  str = aux_String_0;"}) )
  CHECK(389, test_code(&(String){27, 26, "arr := Array{arr[0]:Int}()"}, &(String){203, 202, "Array* aux_Array_0 = NULL;\n  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)\n  aux_Array_0 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));\n  if (aux_Array_0 == NULL) RAISE(1)\n  arr = aux_Array_0;"}) )
  CHECK(392, test_code(&(String){42, 41, "owner Array{Test} a(Array{arr[0]:Test}())"}, &(String){221, 220, "Array* a = NULL;\n  Array* aux_Array_0 = NULL;\n  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)\n  aux_Array_0 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Test));\n  if (aux_Array_0 == NULL) RAISE(1)\n  a = aux_Array_0;"}) )
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(396, String_copy(expected, &(String){19, 18, "Array* sa = NULL;\n"}) )
  CHECK(397, String_concat(expected, &(String){30, 29, "  Array* aux_Array_0 = NULL;\n"}) )
  CHECK(398, String_concat(expected, &(String){49, 48, "  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)\n"}) )
  CHECK(399, String_concat(expected, &(String){49, 48, "  if ((1) < 0 || (1) >= (arr)->length) RAISE(1)\n"}) )
  CHECK(400, String_concat(expected, &(String){14, 13, "  aux_Array_0"}) )
  CHECK(401, String_concat(expected, &(String){50, 49, " = MR_new_string_array(((Int*)((arr)->values))[0]"}) )
  CHECK(402, String_concat(expected, &(String){32, 31, ", ((Int*)((arr)->values))[1]);\n"}) )
  CHECK(403, String_concat(expected, &(String){37, 36, "  if (aux_Array_0 == NULL) RAISE(1)\n"}) )
  CHECK(404, String_concat(expected, &(String){20, 19, "  sa = aux_Array_0;"}) )
  CHECK(405, test_code(&(String){55, 54, "owner Array{String} sa(Array{arr[0]:String{arr[1]}}())"}, expected) )
  CHECK(408, test_code(&(String){18, 17, "var Int x(arr[0])"}, &(String){93, 92, "Int x = 0;\n  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)\n  x = ((Int*)((arr)->values))[0];"}) )
  CHECK(411, test_code(&(String){19, 18, "user String s(str)"}, &(String){29, 28, "String* s = NULL;\n  s = str;"}) )
  CHECK(412, String_copy(expected, &(String){20, 19, "char s_Values[12];\n"}) )
  CHECK(413, String_concat(expected, &(String){33, 32, "  String s_Var = {12, 0, NULL};\n"}) )
  CHECK(414, String_concat(expected, &(String){23, 22, "  String* s = &s_Var;\n"}) )
  CHECK(415, String_concat(expected, &(String){34, 33, "  String aux_String_0_Var = {0};\n"}) )
  CHECK(416, String_concat(expected, &(String){45, 44, "  String* aux_String_0 = &aux_String_0_Var;\n"}) )
  CHECK(417, String_concat(expected, &(String){28, 27, "  s_Var.values = s_Values;\n"}) )
  CHECK(418, String_concat(expected, &(String){34, 33, "  aux_String_0->max_length = 12;\n"}) )
  CHECK(419, String_concat(expected, &(String){30, 29, "  aux_String_0->length = 11;\n"}) )
  CHECK(420, String_concat(expected, &(String){41, 40, "  aux_String_0->values = \"some string\";\n"}) )
  CHECK(421, String_concat(expected, &(String){42, 41, "  CHECK(1, String_copy(s, aux_String_0) )"}) )
  CHECK(422, test_code(&(String){32, 31, "var String{12} s(\"some string\")"}, expected) )
  CHECK(423, test_code(&(String){21, 20, "new String{i} s(str)"}, &(String){101, 100, "String* s = NULL;\n  s = MR_new_string(i);\n  if (s == NULL) RAISE(1)\n  CHECK(1, String_copy(s, str) )"}) )
  CHECK(426, test_code(&(String){17, 16, "user Test tt(tc)"}, &(String){50, 49, "Test* tt = NULL;\n  tt = &(tc->_base._base._base);"}) )
  CHECK(429, test_code_error(&(String){8, 7, "var Int"}, &(String){42, 41, "expected space after type, got \"new-line\""}) )
  CHECK(431, test_code_error(&(String){14, 13, "var Int Error"}, &(String){30, 29, "illegal variable name \"Error\""}) )
  CHECK(433, test_code_error(&(String){18, 17, "var Int errorName"}, &(String){34, 33, "illegal variable name \"errorName\""}) )
  CHECK(435, test_code_error(&(String){29, 28, "var Int name\n  var Int name\n"}, &(String){32, 31, "redefinition of variable \"name\""}) )
  CHECK(438, test_code_error(&(String){59, 58, "var Int name\n  do\n    var Int x\n    do\n      var Int name\n"}, &(String){32, 31, "redefinition of variable \"name\""}) )
  CHECK(441, test_global_scope_error(&(String){40, 39, "var Int name\nfunc mock()\n  var Int name"}, &(String){39, 38, "redefinition of global variable \"name\""}) )
  CHECK(444, test_global_scope_error(&(String){39, 38, "func name()\nfunc mock()\n  var Int name"}, &(String){40, 39, "variable name overrides function \"name\""}) )
  CHECK(447, test_global_scope_error(&(String){27, 26, "struct Test\n  var Int x(1)"}, &(String){35, 34, "type members cannot be initialized"}) )
  CHECK(450, test_global_scope_error(&(String){13, 12, "var Int x(1)"}, &(String){39, 38, "global variables cannot be initialized"}) )
  CHECK(452, test_global_scope_error(&(String){26, 25, "struct Test\n  var Test t\n"}, &(String){52, 51, "non-primitives cannot be declared \"var\" here yet..."}) )
  CHECK(455, test_code_error(&(String){6, 5, "Int()"}, &(String){43, 42, "dynamic allocation of primitive type \"Int\""}) )
  CHECK(457, test_code_error(&(String){13, 12, "var String s"}, &(String){28, 27, "missing length for sequence"}) )
  CHECK(458, test_code_error(&(String){23, 22, "var Array{4:String} sa"}, &(String){28, 27, "missing length for sequence"}) )
  CHECK(460, test_code_error(&(String){13, 12, "new String s"}, &(String){28, 27, "missing length for sequence"}) )
  CHECK(461, test_code_error(&(String){9, 8, "String()"}, &(String){28, 27, "missing length for sequence"}) )
  CHECK(462, test_code_error(&(String){13, 12, "user Array a"}, &(String){26, 25, "missing subtype for array"}) )
  CHECK(463, test_code_error(&(String){12, 11, "new Array a"}, &(String){26, 25, "missing subtype for array"}) )
  CHECK(464, test_code_error(&(String){8, 7, "Array()"}, &(String){26, 25, "missing subtype for array"}) )
  CHECK(465, test_code_error(&(String){16, 15, "var Array{23} a"}, &(String){26, 25, "missing subtype for array"}) )
  CHECK(466, test_code_error(&(String){28, 27, "var Array{1:Array{2:Int}} a"}, &(String){44, 43, "multidimensional array not supported yet..."}) )
  CHECK(469, test_code_error(&(String){12, 11, "var Array{1"}, &(String){29, 28, "expected \":\", got \"new-line\""}) )
  CHECK(470, test_code_error(&(String){14, 13, "var String{12"}, &(String){29, 28, "expected \"}\", got \"new-line\""}) )
  CHECK(471, test_code_error(&(String){23, 22, "var Array{error:Int} a"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(473, test_code_error(&(String){22, 21, "var Array{\"12\":Int} a"}, &(String){40, 39, "got \"String\" expression, expected \"Int\""}) )
  CHECK(476, test_code_error(&(String){11, 10, "user Int x"}, &(String){63, 62, "only \"var\" access is supported for primitive types, got \"user\""}) )
  CHECK(479, test_code_error(&(String){10, 9, "new Int x"}, &(String){62, 61, "only \"var\" access is supported for primitive types, got \"new\""}) )
  CHECK(482, test_code_error(&(String){12, 11, "var Int x(1"}, &(String){50, 49, "expected \")\" after initialization, got \"new-line\""}) )
  CHECK(485, test_code_error(&(String){14, 13, "var File f(1)"}, &(String){44, 43, "cannot initialize non-primitive type \"File\""}) )
  CHECK(488, test_code_error(&(String){14, 13, "var Bool x(1)"}, &(String){32, 31, "cannot assign \"Int\" into \"Bool\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_comment();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_comment = "test-comment";
#define MR_FUNC_NAME _func_name_test_comment
Returncode test_comment() {
  String* expected = &(String){11, 10, "Int x = 0;"};
  CHECK(494, test_code(&(String){23, 22, "# comment\n\n  var Int x"}, expected) )
  CHECK(495, test_code(&(String){30, 29, "## documemtation\n\n  var Int x"}, expected) )
  CHECK(496, test_code(&(String){42, 41, "{# multi \n line \n comment #}\n\n  var Int x"}, expected) )
  CHECK(497, test_code(&(String){49, 48, "{## multi \n line \n documemtation #}\n\n  var Int x"}, expected) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_if_else();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_if_else = "test-if-else";
#define MR_FUNC_NAME _func_name_test_if_else
Returncode test_if_else() {
  CHECK(503, test_code(&(String){24, 23, "if t.num > 3\n    i -= 2"}, &(String){60, 59, "if (t == NULL) RAISE(1)\n  if (t->num > 3) {\n    i -= 2;\n  }"}) )
  CHECK(506, test_code(&(String){38, 37, "if i > 3\n    i -= 2\n  else\n    i += 1"}, &(String){54, 53, "if (i > 3) {\n    i -= 2;\n  }\n  else {\n    i += 1;\n  }"}) )
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(510, String_copy(expected, &(String){14, 13, "if (i > 3) {\n"}) )
  CHECK(511, String_concat(expected, &(String){13, 12, "    i -= 3;\n"}) )
  CHECK(512, String_concat(expected, &(String){5, 4, "  }\n"}) )
  CHECK(513, String_concat(expected, &(String){10, 9, "  else {\n"}) )
  CHECK(514, String_concat(expected, &(String){29, 28, "    if (t == NULL) RAISE(3)\n"}) )
  CHECK(515, String_concat(expected, &(String){23, 22, "    if (t->num > 2) {\n"}) )
  CHECK(516, String_concat(expected, &(String){15, 14, "      i -= 2;\n"}) )
  CHECK(517, String_concat(expected, &(String){7, 6, "    }\n"}) )
  CHECK(518, String_concat(expected, &(String){12, 11, "    else {\n"}) )
  CHECK(519, String_concat(expected, &(String){31, 30, "      if (t == NULL) RAISE(5)\n"}) )
  CHECK(520, String_concat(expected, &(String){25, 24, "      if (t->num > 1) {\n"}) )
  CHECK(521, String_concat(expected, &(String){17, 16, "        i -= 1;\n"}) )
  CHECK(522, String_concat(expected, &(String){9, 8, "      }\n"}) )
  CHECK(523, String_concat(expected, &(String){14, 13, "      else {\n"}) )
  CHECK(524, String_concat(expected, &(String){17, 16, "        i += 1;\n"}) )
  CHECK(525, String_concat(expected, &(String){9, 8, "      }\n"}) )
  CHECK(526, String_concat(expected, &(String){7, 6, "    }\n"}) )
  CHECK(527, String_concat(expected, &(String){4, 3, "  }"}) )
  CHECK(528, test_code(&(String){100, 99, "if i > 3\n    i -= 3\n  else-if t.num > 2\n    i -= 2\n  else-if t.num > 1\n    i -= 1\n  else\n    i += 1"}, expected) )
  CHECK(531, test_code_error(&(String){5, 4, "if 3"}, &(String){38, 37, "got \"Int\" expression, expected \"Bool\""}) )
  CHECK(533, test_code_error(&(String){15, 14, "if b\n    error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(534, test_code_error(&(String){33, 32, "if b\n    i := 0\n  else\n    error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(537, test_code_error(&(String){38, 37, "if b\n    i := 0\n  else-if b\n    error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_do_loop();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_do_loop = "test-do-loop";
#define MR_FUNC_NAME _func_name_test_do_loop
Returncode test_do_loop() {
  CHECK(543, test_code(&(String){17, 16, "do\n    var Int x"}, &(String){34, 33, "while (true) {\n    Int x = 0;\n  }"}) )
  CHECK(544, test_code(&(String){22, 21, "\n  \n    \n\n  var Int x"}, &(String){11, 10, "Int x = 0;"}) )
  CHECK(545, test_code(&(String){23, 22, "do\n    while t.num > 3"}, &(String){77, 76, "while (true) {\n    if (t == NULL) RAISE(2)\n    if (!(t->num > 3)) break;\n  }"}) )
  CHECK(548, test_code(&(String){16, 15, "do\n    continue"}, &(String){33, 32, "while (true) {\n    continue;\n  }"}) )
  CHECK(549, test_code_error(&(String){4, 3, "do("}, &(String){38, 37, "expected new-line after \"do\", got \"(\""}) )
  CHECK(550, test_code_error(&(String){11, 10, "while true"}, &(String){29, 28, "\"while\" used not inside loop"}) )
  CHECK(551, test_code_error(&(String){9, 8, "continue"}, &(String){32, 31, "\"continue\" used not inside loop"}) )
  CHECK(552, test_code_error(&(String){15, 14, "do\n    while 2"}, &(String){38, 37, "got \"Int\" expression, expected \"Bool\""}) )
  CHECK(554, test_code_error(&(String){13, 12, "do\n    error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_for_loop();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_for_loop = "test-for-loop";
#define MR_FUNC_NAME _func_name_test_for_loop
Returncode test_for_loop() {
  CHECK(558, test_code(&(String){22, 21, "for n in 5\n    i += n"}, &(String){49, 48, "{int n; for(n=0; n<5; ++n) {\n    i += n;\n  }\n  }"}) )
  CHECK(561, test_code(&(String){36, 35, "for n in t.num:t.num + 2\n    i += n"}, &(String){115, 114, "if (t == NULL) RAISE(1)\n  if (t == NULL) RAISE(1)\n  {int n; for(n=t->num; n<t->num + 2; ++n) {\n    i += n;\n  }\n  }"}) )
  CHECK(564, test_code_error(&(String){5, 4, "for("}, &(String){36, 35, "expected space after \"for\", got \"(\""}) )
  CHECK(565, test_code_error(&(String){6, 5, "for n"}, &(String){48, 47, "expected space after index name, got \"new-line\""}) )
  CHECK(567, test_code_error(&(String){12, 11, "for n error"}, &(String){25, 24, "expected \"in \" got \"err\""}) )
  CHECK(569, test_code_error(&(String){13, 12, "for n in str"}, &(String){40, 39, "got \"String\" expression, expected \"Int\""}) )
  CHECK(571, test_code_error(&(String){15, 14, "for n in str:8"}, &(String){40, 39, "got \"String\" expression, expected \"Int\""}) )
  CHECK(573, test_code_error(&(String){21, 20, "for n in 5\n    error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_testing();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_testing = "test-testing";
#define MR_FUNC_NAME _func_name_test_testing
Returncode test_testing() {
  CHECK(577, test_code(&(String){17, 16, "assert t.num = 2"}, &(String){54, 53, "if (t == NULL) RAISE(1)\n  TEST_ASSERT(1, t->num == 2)"}) )
  CHECK(580, test_code(&(String){19, 18, "assert-error t.num"}, &(String){246, 245, "do {\n    MR_trace_stream = NULL;\n#undef RETURN_ERROR\n#define RETURN_ERROR(value) break\n    if (t == NULL) RAISE(1)\n    #undef RETURN_ERROR\n#define RETURN_ERROR(value) return value\n    MR_trace_stream = stdout;\n    TEST_FAIL(1)\n  } while (false);"}) )
  CHECK(583, test_code(&(String){20, 19, "assert-error fun0()"}, &(String){240, 239, "do {\n    MR_trace_stream = NULL;\n#undef RETURN_ERROR\n#define RETURN_ERROR(value) break\n    CHECK(1, fun0() )\n    #undef RETURN_ERROR\n#define RETURN_ERROR(value) return value\n    MR_trace_stream = stdout;\n    TEST_FAIL(1)\n  } while (false);"}) )
  CHECK(586, test_global_scope(&(String){38, 37, "func fun()\n  fun()\nmock fun()\n  raise"}, &(String){152, 151, "Returncode fun(void);\nReturncode Mock_fun(void);\nReturncode fun(void) {\n  CHECK(2, Mock_fun() )\n  return OK;\n}\nReturncode Mock_fun(void) {\n  RAISE(4)\n}"}) )
  CHECK(589, test_global_scope(&(String){31, 30, "mock fun()\nfunc fun()\n  fun()\n"}, &(String){154, 153, "Returncode Mock_fun(void);\nReturncode fun(void);\nReturncode Mock_fun(void) {\n  return OK;\n}\nReturncode fun(void) {\n  CHECK(3, Mock_fun() )\n  return OK;\n}"}) )
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(593, String_copy(expected, &(String){27, 26, "typedef struct Test Test;\n"}) )
  CHECK(594, String_concat(expected, &(String){15, 14, "struct Test {\n"}) )
  CHECK(595, String_concat(expected, &(String){10, 9, "  Int x;\n"}) )
  CHECK(596, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(597, String_concat(expected, &(String){42, 41, "Returncode Test_meth(Test* self, Int x);\n"}) )
  CHECK(598, String_concat(expected, &(String){47, 46, "Returncode Test_Mock_meth(Test* self, Int x);\n"}) )
  CHECK(599, String_concat(expected, &(String){43, 42, "Returncode Test_meth(Test* self, Int x) {\n"}) )
  CHECK(600, String_concat(expected, &(String){38, 37, "  CHECK(5, Test_Mock_meth(self, x) )\n"}) )
  CHECK(601, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(602, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(603, String_concat(expected, &(String){48, 47, "Returncode Test_Mock_meth(Test* self, Int x) {\n"}) )
  CHECK(604, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(605, String_concat(expected, &(String){2, 1, "}"}) )
  CHECK(606, test_global_scope(&(String){97, 96, "mock Test.meth(copy Int x)\nstruct Test\n  var Int x\n  func meth(copy Int x)\n    self.meth(copy x)"}, expected) )
  CHECK(609, String_copy(expected, &(String){24, 23, "Returncode fun0(void);\n"}) )
  CHECK(610, String_concat(expected, &(String){24, 23, "Returncode fun1(void);\n"}) )
  CHECK(611, String_concat(expected, &(String){25, 24, "Returncode fun0(void) {\n"}) )
  CHECK(612, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(613, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(614, String_concat(expected, &(String){25, 24, "Returncode fun1(void) {\n"}) )
  CHECK(615, String_concat(expected, &(String){14, 13, "  return OK;\n"}) )
  CHECK(616, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(617, String_concat(expected, &(String){20, 19, "USER_MAIN_HEADER {\n"}) )
  CHECK(618, String_concat(expected, &(String){24, 23, "  Bool success = true;\n"}) )
  CHECK(619, String_concat(expected, &(String){19, 18, "  RUN_TEST(fun0);\n"}) )
  CHECK(620, String_concat(expected, &(String){19, 18, "  RUN_TEST(fun1);\n"}) )
  CHECK(621, String_concat(expected, &(String){30, 29, "  return success? OK : FAIL;\n"}) )
  CHECK(622, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(623, String_concat(expected, &(String){15, 14, "TEST_MAIN_FUNC"}) )
  CHECK(624, String_concat(expected, &(String){1, 0, ""}) )
  CHECK(625, String_concat(expected, &(String){1, 0, ""}) )
  CHECK(626, String_concat(expected, &(String){1, 0, ""}) )
  CHECK(627, test_global_scope(&(String){25, 24, "test fun0()\ntest fun1()\n"}, expected) )
  CHECK(628, test_global_scope(&(String){30, 29, "test fun0()\ntest fun1()\nmain\n"}, expected) )
  CHECK(629, test_code_error(&(String){9, 8, "assert 3"}, &(String){38, 37, "got \"Int\" expression, expected \"Bool\""}) )
  CHECK(631, test_code_error(&(String){13, 12, "assert error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(632, test_code_error(&(String){19, 18, "assert-error error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(633, test_global_scope_error(&(String){22, 21, "test fun(copy Int x)\n"}, &(String){36, 35, "test function cannot have arguments"}) )
  CHECK(635, test_global_scope_error(&(String){26, 25, "test fun()->(copy Int x)\n"}, &(String){36, 35, "test function cannot have arguments"}) )
  CHECK(638, test_global_scope_error(&(String){14, 13, "mock error()\n"}, &(String){33, 32, "mocking unknown function \"error\""}) )
  CHECK(640, test_global_scope_error(&(String){18, 17, "mock Error.fun()\n"}, &(String){21, 20, "unknown type \"Error\""}) )
  CHECK(642, test_global_scope_error(&(String){43, 42, "struct Test\n  var Int x\nmock Test.error()\n"}, &(String){46, 45, "mocking unknown method \"error\" of type \"Test\""}) )
  CHECK(645, test_global_scope_error(&(String){50, 49, "mock fun(owner String s)\nfunc fun(user String s)\n"}, &(String){37, 36, "expected access \"user\" , got \"owner\""}) )
  CHECK(648, test_global_scope_error(&(String){46, 45, "mock fun(user Int s)\nfunc fun(user String s)\n"}, &(String){38, 37, "non matching types \"Int\" and \"String\""}) )
  CHECK(651, test_global_scope_error(&(String){58, 57, "mock fun(user Array{Char} a)\nfunc fun(user Array{Int} a)\n"}, &(String){39, 38, "non matching subtypes \"Char\" and \"Int\""}) )
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
#include "tests/expression-tests.c"
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
#elif MR_STAGE == MR_TYPES(4)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(5)
#endif
#undef MR_INCLUDES
#endif

#endif
