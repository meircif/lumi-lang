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
  CHECK(60, test_code_error(&(String){16, 15, "return\n  i := 3"}, &(String){17, 16, "unreachable code"}) )
  CHECK(61, test_code_error(&(String){15, 14, "raise\n  i := 3"}, &(String){17, 16, "unreachable code"}) )
  CHECK(62, test_global_scope_error(&(String){15, 14, "{# comment #}?"}, &(String){39, 38, "expected new-line in line end, got \"?\""}) )
  CHECK(64, test_global_scope_error(&(String){7, 6, "main(\n"}, &(String){40, 39, "expected new-line after \"main\", got \"(\""}) )
  CHECK(66, test_global_scope_error(&(String){14, 13, "  struct Test"}, &(String){42, 41, "indentation too big, expected \"0\" got \"2\""}) )
  CHECK(69, test_global_scope_error(&(String){10, 9, "var Int x"}, &(String){28, 27, "no new-line before file end"}) )
  CHECK(72, test_global_scope_error(&(String){27, 26, "var Int name\nvar Int name\n"}, &(String){39, 38, "redefinition of global variable \"name\""}) )
  CHECK(75, test_global_scope_error(&(String){25, 24, "func name()\nvar Int name"}, &(String){40, 39, "variable name overrides function \"name\""}) )
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
  CHECK(81, test_global_scope(&(String){24, 23, "struct Test\n  var Int x"}, &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"}) )
  CHECK(84, test_global_scope(&(String){24, 23, "struct Test\n  var Int x"}, &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"}) )
  CHECK(87, test_global_scope(&(String){77, 76, "struct Test1\n  var Int x\nstruct Test2\n  var Int x\n\n\nstruct Test3\n  var Int x"}, &(String){165, 164, "typedef struct Test1 Test1;\ntypedef struct Test2 Test2;\ntypedef struct Test3 Test3;\nstruct Test1 {\n  Int x;\n};\nstruct Test2 {\n  Int x;\n};\nstruct Test3 {\n  Int x;\n};"}) )
  CHECK(90, test_global_scope(&(String){57, 56, "struct Test2(Test1)\n  var Int y\nstruct Test1\n  var Int x"}, &(String){125, 124, "typedef struct Test1 Test1;\ntypedef struct Test2 Test2;\nstruct Test1 {\n  Int x;\n};\nstruct Test2 {\n  Test1 _base;\n  Int y;\n};"}) )
  CHECK(93, test_global_scope_error(&(String){9, 8, "struct(\n"}, &(String){39, 38, "expected space after \"struct\", got \"(\""}) )
  CHECK(95, test_global_scope_error(&(String){14, 13, "struct error\n"}, &(String){26, 25, "illegal type name \"error\""}) )
  CHECK(97, test_global_scope_error(&(String){15, 14, "struct ERrror\n"}, &(String){27, 26, "illegal type name \"ERrror\""}) )
  CHECK(99, test_global_scope_error(&(String){19, 18, "struct Error-name\n"}, &(String){31, 30, "illegal type name \"Error-name\""}) )
  CHECK(101, test_global_scope_error(&(String){12, 11, "struct Int\n"}, &(String){27, 26, "redefinition of type \"Int\""}) )
  CHECK(103, test_global_scope_error(&(String){25, 24, "struct Test\nstruct Test\n"}, &(String){28, 27, "redefinition of type \"Test\""}) )
  CHECK(105, test_global_scope_error(&(String){18, 17, "struct Test(Base\n"}, &(String){45, 44, "expected \")\" after base type, got \"new-line\""}) )
  CHECK(108, test_global_scope_error(&(String){21, 20, "struct Test\n  error "}, &(String){24, 23, "unknown keyword \"error\""}) )
  CHECK(110, test_global_scope_error(&(String){12, 11, "struct Test"}, &(String){40, 39, "expected block in a new line, got \"EOF\""}) )
  CHECK(112, test_global_scope_error(&(String){14, 13, "struct Error\n"}, &(String){28, 27, "type with no fields \"Error\""}) )
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
  CHECK(118, String_copy(input, &(String){12, 11, "class Base\n"}) )
  CHECK(119, String_concat(input, &(String){13, 12, "  var Int x\n"}) )
  CHECK(120, String_concat(input, &(String){20, 19, "  func inst stat()\n"}) )
  CHECK(121, String_concat(input, &(String){23, 22, "  func dynamic dyn0()\n"}) )
  CHECK(122, String_concat(input, &(String){23, 22, "  func dynamic dyn1()\n"}) )
  CHECK(123, String_concat(input, &(String){17, 16, "class Mid(Base)\n"}) )
  CHECK(124, String_concat(input, &(String){13, 12, "  var Int y\n"}) )
  CHECK(125, String_concat(input, &(String){23, 22, "  func dynamic dyn0()\n"}) )
  CHECK(126, String_concat(input, &(String){23, 22, "  func dynamic dyn2()\n"}) )
  CHECK(127, String_concat(input, &(String){16, 15, "class Top(Mid)\n"}) )
  CHECK(128, String_concat(input, &(String){13, 12, "  var Int z\n"}) )
  CHECK(129, String_concat(input, &(String){23, 22, "  func dynamic dyn0()\n"}) )
  CHECK(130, String_concat(input, &(String){12, 11, "    base()\n"}) )
  CHECK(131, String_concat(input, &(String){23, 22, "  func dynamic dyn3()\n"}) )
  CHECK(132, String_concat(input, &(String){17, 16, "    base.dyn0()\n"}) )
  
  String* expected = &(String){4096, 0, (char[4096]){0}};
  CHECK(135, String_copy(expected, &(String){27, 26, "typedef struct Base Base;\n"}) )
  CHECK(136, String_concat(expected, &(String){43, 42, "typedef struct Base_Dynamic Base_Dynamic;\n"}) )
  CHECK(137, String_concat(expected, &(String){25, 24, "typedef struct Mid Mid;\n"}) )
  CHECK(138, String_concat(expected, &(String){41, 40, "typedef struct Mid_Dynamic Mid_Dynamic;\n"}) )
  CHECK(139, String_concat(expected, &(String){25, 24, "typedef struct Top Top;\n"}) )
  CHECK(140, String_concat(expected, &(String){41, 40, "typedef struct Top_Dynamic Top_Dynamic;\n"}) )
  
  CHECK(142, String_concat(expected, &(String){15, 14, "struct Base {\n"}) )
  CHECK(143, String_concat(expected, &(String){10, 9, "  Int x;\n"}) )
  CHECK(144, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(145, String_concat(expected, &(String){23, 22, "struct Base_Dynamic {\n"}) )
  CHECK(146, String_concat(expected, &(String){32, 31, "  Returncode (*dyn0)(Base* self"}) )
  CHECK(147, String_concat(expected, &(String){32, 31, ", Base_Dynamic* self_Dynamic);\n"}) )
  CHECK(148, String_concat(expected, &(String){32, 31, "  Returncode (*dyn1)(Base* self"}) )
  CHECK(149, String_concat(expected, &(String){32, 31, ", Base_Dynamic* self_Dynamic);\n"}) )
  CHECK(150, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(151, String_concat(expected, &(String){14, 13, "struct Mid {\n"}) )
  CHECK(152, String_concat(expected, &(String){15, 14, "  Base _base;\n"}) )
  CHECK(153, String_concat(expected, &(String){10, 9, "  Int y;\n"}) )
  CHECK(154, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(155, String_concat(expected, &(String){22, 21, "struct Mid_Dynamic {\n"}) )
  CHECK(156, String_concat(expected, &(String){23, 22, "  Base_Dynamic _base;\n"}) )
  CHECK(157, String_concat(expected, &(String){31, 30, "  Returncode (*dyn2)(Mid* self"}) )
  CHECK(158, String_concat(expected, &(String){31, 30, ", Mid_Dynamic* self_Dynamic);\n"}) )
  CHECK(159, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(160, String_concat(expected, &(String){14, 13, "struct Top {\n"}) )
  CHECK(161, String_concat(expected, &(String){14, 13, "  Mid _base;\n"}) )
  CHECK(162, String_concat(expected, &(String){10, 9, "  Int z;\n"}) )
  CHECK(163, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(164, String_concat(expected, &(String){22, 21, "struct Top_Dynamic {\n"}) )
  CHECK(165, String_concat(expected, &(String){22, 21, "  Mid_Dynamic _base;\n"}) )
  CHECK(166, String_concat(expected, &(String){31, 30, "  Returncode (*dyn3)(Top* self"}) )
  CHECK(167, String_concat(expected, &(String){31, 30, ", Top_Dynamic* self_Dynamic);\n"}) )
  CHECK(168, String_concat(expected, &(String){4, 3, "};\n"}) )
  
  CHECK(170, String_concat(expected, &(String){32, 31, "Returncode Base_stat(Base* self"}) )
  CHECK(171, String_concat(expected, &(String){32, 31, ", Base_Dynamic* self_Dynamic);\n"}) )
  CHECK(172, String_concat(expected, &(String){32, 31, "Returncode Base_dyn0(Base* self"}) )
  CHECK(173, String_concat(expected, &(String){32, 31, ", Base_Dynamic* self_Dynamic);\n"}) )
  CHECK(174, String_concat(expected, &(String){32, 31, "Returncode Base_dyn1(Base* self"}) )
  CHECK(175, String_concat(expected, &(String){32, 31, ", Base_Dynamic* self_Dynamic);\n"}) )
  CHECK(176, String_concat(expected, &(String){30, 29, "Returncode Mid_dyn0(Mid* self"}) )
  CHECK(177, String_concat(expected, &(String){31, 30, ", Mid_Dynamic* self_Dynamic);\n"}) )
  CHECK(178, String_concat(expected, &(String){30, 29, "Returncode Mid_dyn2(Mid* self"}) )
  CHECK(179, String_concat(expected, &(String){31, 30, ", Mid_Dynamic* self_Dynamic);\n"}) )
  CHECK(180, String_concat(expected, &(String){30, 29, "Returncode Top_dyn0(Top* self"}) )
  CHECK(181, String_concat(expected, &(String){31, 30, ", Top_Dynamic* self_Dynamic);\n"}) )
  CHECK(182, String_concat(expected, &(String){30, 29, "Returncode Top_dyn3(Top* self"}) )
  CHECK(183, String_concat(expected, &(String){31, 30, ", Top_Dynamic* self_Dynamic);\n"}) )
  
  CHECK(185, String_concat(expected, &(String){53, 52, "Base_Dynamic Base_dynamic = {Base_dyn0, Base_dyn1};\n"}) )
  CHECK(186, String_concat(expected, &(String){55, 54, "Mid_Dynamic Mid_dynamic = {{(Func)Mid_dyn0, Base_dyn1}"}) )
  CHECK(187, String_concat(expected, &(String){14, 13, ", Mid_dyn2};\n"}) )
  CHECK(188, String_concat(expected, &(String){44, 43, "Top_Dynamic Top_dynamic = {{{(Func)Top_dyn0"}) )
  CHECK(189, String_concat(expected, &(String){37, 36, ", Base_dyn1}, Mid_dyn2}, Top_dyn3};\n"}) )
  
  CHECK(191, String_concat(expected, &(String){32, 31, "Returncode Base_stat(Base* self"}) )
  CHECK(192, String_concat(expected, &(String){30, 29, ", Base_Dynamic* self_Dynamic)"}) )
  CHECK(193, String_concat(expected, empty_func_body) )
  CHECK(194, String_concat(expected, &(String){32, 31, "Returncode Base_dyn0(Base* self"}) )
  CHECK(195, String_concat(expected, &(String){30, 29, ", Base_Dynamic* self_Dynamic)"}) )
  CHECK(196, String_concat(expected, empty_func_body) )
  CHECK(197, String_concat(expected, &(String){32, 31, "Returncode Base_dyn1(Base* self"}) )
  CHECK(198, String_concat(expected, &(String){30, 29, ", Base_Dynamic* self_Dynamic)"}) )
  CHECK(199, String_concat(expected, empty_func_body) )
  CHECK(200, String_concat(expected, &(String){30, 29, "Returncode Mid_dyn0(Mid* self"}) )
  CHECK(201, String_concat(expected, &(String){29, 28, ", Mid_Dynamic* self_Dynamic)"}) )
  CHECK(202, String_concat(expected, empty_func_body) )
  CHECK(203, String_concat(expected, &(String){30, 29, "Returncode Mid_dyn2(Mid* self"}) )
  CHECK(204, String_concat(expected, &(String){29, 28, ", Mid_Dynamic* self_Dynamic)"}) )
  CHECK(205, String_concat(expected, empty_func_body) )
  CHECK(206, String_concat(expected, &(String){30, 29, "Returncode Top_dyn0(Top* self"}) )
  CHECK(207, String_concat(expected, &(String){32, 31, ", Top_Dynamic* self_Dynamic) {\n"}) )
  CHECK(208, String_concat(expected, &(String){27, 26, "  Returncode MR_err = OK;\n"}) )
  CHECK(209, String_concat(expected, &(String){36, 35, "  CHECK(13, Mid_dyn0(&(self->_base)"}) )
  CHECK(210, String_concat(expected, &(String){29, 28, ", &(self_Dynamic->_base)) )\n"}) )
  CHECK(211, String_concat(expected, &(String){13, 12, "MR_cleanup:\n"}) )
  CHECK(212, String_concat(expected, &(String){18, 17, "  return MR_err;\n"}) )
  CHECK(213, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(214, String_concat(expected, &(String){30, 29, "Returncode Top_dyn3(Top* self"}) )
  CHECK(215, String_concat(expected, &(String){32, 31, ", Top_Dynamic* self_Dynamic) {\n"}) )
  CHECK(216, String_concat(expected, &(String){27, 26, "  Returncode MR_err = OK;\n"}) )
  CHECK(217, String_concat(expected, &(String){36, 35, "  CHECK(15, Mid_dyn0(&(self->_base)"}) )
  CHECK(218, String_concat(expected, &(String){29, 28, ", &(self_Dynamic->_base)) )\n"}) )
  CHECK(219, String_concat(expected, &(String){13, 12, "MR_cleanup:\n"}) )
  CHECK(220, String_concat(expected, &(String){18, 17, "  return MR_err;\n"}) )
  CHECK(221, String_concat(expected, &(String){2, 1, "}"}) )
  
  CHECK(223, test_global_scope(input, expected) )
  CHECK(224, test_global_scope_error(&(String){8, 7, "class(\n"}, &(String){38, 37, "expected space after \"class\", got \"(\""}) )
  CHECK(226, test_global_scope_error(&(String){25, 24, "class Error\n  var Int x\n"}, &(String){38, 37, "class with no dynamic methods \"Error\""}) )
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
  CHECK(232, test_global_scope(&(String){12, 11, "func name()"}, &(String){104, 103, "Returncode name(void);\nReturncode name(void) {\n  Returncode MR_err = OK;\nMR_cleanup:\n  return MR_err;\n}"}) )
  CHECK(235, test_global_scope(&(String){59, 58, "func name(var String self, user String text, copy Int num)"}, &(String){166, 165, "Returncode name(String* self, String* text, Int num);\nReturncode name(String* self, String* text, Int num) {\n  Returncode MR_err = OK;\nMR_cleanup:\n  return MR_err;\n}"}) )
  CHECK(238, test_global_scope(&(String){47, 46, "func name()->(owner String text, copy Int num)"}, &(String){142, 141, "Returncode name(String** text, Int* num);\nReturncode name(String** text, Int* num) {\n  Returncode MR_err = OK;\nMR_cleanup:\n  return MR_err;\n}"}) )
  CHECK(241, test_global_scope(&(String){47, 46, "func name(copy Char param)->(owner String out)"}, &(String){144, 143, "Returncode name(Char param, String** out);\nReturncode name(Char param, String** out) {\n  Returncode MR_err = OK;\nMR_cleanup:\n  return MR_err;\n}"}) )
  CHECK(244, test_global_scope(&(String){33, 32, "func name(user Array{Int} array)"}, &(String){120, 119, "Returncode name(Array* array);\nReturncode name(Array* array) {\n  Returncode MR_err = OK;\nMR_cleanup:\n  return MR_err;\n}"}) )
  CHECK(247, test_global_scope(&(String){74, 73, "func name(copy Func{(copy Int x)->(copy Int y)} fun)->(copy Func{()} joy)"}, &(String){212, 211, "Returncode name(Returncode (*fun)(Int x, Int* y), Returncode (**joy)(void));\nReturncode name(Returncode (*fun)(Int x, Int* y), Returncode (**joy)(void)) {\n  Returncode MR_err = OK;\nMR_cleanup:\n  return MR_err;\n}"}) )
  CHECK(250, test_global_scope(&(String){24, 23, "func name()\n  var Int x"}, &(String){117, 116, "Returncode name(void);\nReturncode name(void) {\n  Returncode MR_err = OK;\n  Int x = 0;\nMR_cleanup:\n  return MR_err;\n}"}) )
  CHECK(253, test_global_scope(&(String){17, 16, "main\n  var Int x"}, &(String){99, 98, "USER_MAIN_HEADER {\n  Returncode MR_err = OK;\n  Int x = 0;\nMR_cleanup:\n  return MR_err;\n}\nMAIN_FUNC"}) )
  CHECK(256, test_global_scope_error(&(String){7, 6, "func(\n"}, &(String){37, 36, "expected space after \"func\", got \"(\""}) )
  CHECK(258, test_global_scope_error(&(String){11, 10, "func name\n"}, &(String){49, 48, "expected \"(\" after function name, got \"new-line\""}) )
  CHECK(261, test_global_scope_error(&(String){14, 13, "func Error()\n"}, &(String){30, 29, "illegal function name \"Error\""}) )
  CHECK(263, test_global_scope_error(&(String){19, 18, "func error_name()\n"}, &(String){35, 34, "illegal function name \"error_name\""}) )
  CHECK(265, test_global_scope_error(&(String){25, 24, "func name()\nfunc name()\n"}, &(String){32, 31, "redefinition of function \"name\""}) )
  CHECK(268, test_global_scope_error(&(String){26, 25, "var Int name\nfunc name()\n"}, &(String){47, 46, "function name overrides global variable \"name\""}) )
  CHECK(271, test_global_scope_error(&(String){14, 13, "func name( )\n"}, &(String){25, 24, "expected access, got \" \""}) )
  CHECK(273, test_global_scope_error(&(String){17, 16, "func name(user)\n"}, &(String){37, 36, "expected space after access, got \")\""}) )
  CHECK(275, test_global_scope_error(&(String){22, 21, "func name(var String\n"}, &(String){42, 41, "expected space after type, got \"new-line\""}) )
  CHECK(278, test_global_scope_error(&(String){24, 23, "func name(error Int x)\n"}, &(String){23, 22, "illegal access \"error\""}) )
  CHECK(280, test_global_scope_error(&(String){38, 37, "func name(var String str,user Int x)\n"}, &(String){46, 45, "expected space or new-line after \",\", got \"u\""}) )
  CHECK(283, test_global_scope_error(&(String){16, 15, "func name()-()\n"}, &(String){23, 22, "expected \">(\" got \"()\""}) )
  CHECK(285, test_global_scope_error(&(String){12, 11, "func name()"}, &(String){40, 39, "expected block in a new line, got \"EOF\""}) )
  CHECK(287, test_global_scope_error(&(String){26, 25, "func name()\n    var Int x"}, &(String){42, 41, "indentation too big, expected \"2\" got \"4\""}) )
  CHECK(290, test_global_scope_error(&(String){23, 22, "func name(user Int x)\n"}, &(String){69, 68, "argument \"x\" access should be \"copy\" for primitive types, got \"user\""}) )
  CHECK(293, test_global_scope_error(&(String){26, 25, "func name(copy String s)\n"}, &(String){73, 72, "argument \"s\" access should not be \"copy\" for non-primitive type \"String\""}) )
  CHECK(296, test_global_scope_error(&(String){29, 28, "func name(user Array error)\n"}, &(String){26, 25, "missing subtype for array"}) )
  CHECK(298, test_global_scope_error(&(String){28, 27, "func name(copy Func error)\n"}, &(String){35, 34, "missing arguments in function type"}) )
  CHECK(301, test_global_scope_error(&(String){41, 40, "func name(user Array{Array{Int}} error)\n"}, &(String){44, 43, "multidimensional array not supported yet..."}) )
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
  CHECK(307, test_global_scope(&(String){42, 41, "struct Test\n  var Int x\n  user String str"}, &(String){67, 66, "typedef struct Test Test;\nstruct Test {\n  Int x;\n  String* str;\n};"}) )
  CHECK(310, test_global_scope(&(String){38, 37, "struct Test\n  var Int x\n  func name()"}, &(String){178, 177, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};\nReturncode Test_name(Test* self);\nReturncode Test_name(Test* self) {\n  Returncode MR_err = OK;\nMR_cleanup:\n  return MR_err;\n}"}) )
  CHECK(313, test_global_scope(&(String){52, 51, "struct Test\n  var Int x\n  func name()\n    var Int x"}, &(String){191, 190, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};\nReturncode Test_name(Test* self);\nReturncode Test_name(Test* self) {\n  Returncode MR_err = OK;\n  Int x = 0;\nMR_cleanup:\n  return MR_err;\n}"}) )
  String* expected = &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"};
  CHECK(317, test_global_scope(&(String){36, 35, "struct Test\n  # comment\n  var Int x"}, expected) )
  CHECK(318, test_global_scope(&(String){43, 42, "struct Test\n  ## documemtation\n  var Int x"}, expected) )
  CHECK(320, test_global_scope(&(String){55, 54, "struct Test\n  {# multi \n line \n comment #}\n  var Int x"}, expected) )
  CHECK(323, test_global_scope(&(String){62, 61, "struct Test\n  {## multi \n line \n documemtation #}\n  var Int x"}, expected) )
  String* output = &(String){1024, 0, (char[1024]){0}};
  CHECK(327, String_copy(output, &(String){29, 28, "typedef struct Test1 Test1;\n"}) )
  CHECK(328, String_concat(output, &(String){29, 28, "typedef struct Test2 Test2;\n"}) )
  CHECK(329, String_concat(output, &(String){16, 15, "struct Test1 {\n"}) )
  CHECK(330, String_concat(output, &(String){13, 12, "  Int name;\n"}) )
  CHECK(331, String_concat(output, &(String){4, 3, "};\n"}) )
  CHECK(332, String_concat(output, &(String){16, 15, "struct Test2 {\n"}) )
  CHECK(333, String_concat(output, &(String){12, 11, "  Int fun;\n"}) )
  CHECK(334, String_concat(output, &(String){4, 3, "};\n"}) )
  CHECK(335, String_concat(output, &(String){36, 35, "Returncode Test1_fun(Test1* self);\n"}) )
  CHECK(336, String_concat(output, &(String){37, 36, "Returncode Test2_name(Test2* self);\n"}) )
  CHECK(337, String_concat(output, &(String){11, 10, "Int name;\n"}) )
  CHECK(338, String_concat(output, &(String){23, 22, "Returncode fun(void);\n"}) )
  CHECK(339, String_concat(output, &(String){34, 33, "Returncode Test1_fun(Test1* self)"}) )
  CHECK(340, String_concat(output, empty_func_body) )
  CHECK(341, String_concat(output, &(String){35, 34, "Returncode Test2_name(Test2* self)"}) )
  CHECK(342, String_concat(output, empty_func_body) )
  CHECK(343, String_concat(output, &(String){21, 20, "Returncode fun(void)"}) )
  CHECK(344, String_concat(output, empty_func_body) )
  output->length -= 1;
  CHECK(346, test_global_scope(&(String){107, 106, "var Int name\nfunc fun()\nstruct Test1\n  var Int name\n  func fun()\nstruct Test2\n  var Int fun\n  func name()\n"}, output) )
  CHECK(349, test_global_scope_error(&(String){43, 42, "struct Test\n  var Int name\n  var Int name\n"}, &(String){29, 28, "redefinition of field \"name\""}) )
  CHECK(352, test_global_scope_error(&(String){42, 41, "struct Test\n  func name()\n  var Int name\n"}, &(String){35, 34, "field name overrides method \"name\""}) )
  CHECK(355, test_global_scope_error(&(String){41, 40, "struct Test\n  func name()\n  func name()\n"}, &(String){30, 29, "redefinition of method \"name\""}) )
  CHECK(358, test_global_scope_error(&(String){42, 41, "struct Test\n  var Int name\n  func name()\n"}, &(String){35, 34, "method name overrides field \"name\""}) )
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
  CHECK(364, test_global_scope(&(String){21, 20, "func name()\n  return"}, &(String){123, 122, "Returncode name(void);\nReturncode name(void) {\n  Returncode MR_err = OK;\n  goto MR_cleanup;\nMR_cleanup:\n  return MR_err;\n}"}) )
  CHECK(367, test_global_scope(&(String){20, 19, "func name()\n  raise"}, &(String){115, 114, "Returncode name(void);\nReturncode name(void) {\n  Returncode MR_err = OK;\n  RAISE(2)\nMR_cleanup:\n  return MR_err;\n}"}) )
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
  CHECK(373, test_code(&(String){10, 9, "var Int x"}, &(String){11, 10, "Int x = 0;"}) )
  CHECK(374, test_code(&(String){14, 13, "user String s"}, &(String){18, 17, "String* s = NULL;"}) )
  CHECK(375, test_code(&(String){19, 18, "owner Array{Int} a"}, &(String){17, 16, "Array* a = NULL;"}) )
  CHECK(376, test_code(&(String){13, 12, "user Test tt"}, &(String){17, 16, "Test* tt = NULL;"}) )
  CHECK(377, test_code(&(String){12, 11, "var Test tt"}, &(String){41, 40, "Test tt_Var = {0};\n  Test* tt = &tt_Var;"}) )
  CHECK(378, test_code(&(String){17, 16, "var String{12} s"}, &(String){100, 99, "char s_Values[12];\n  String s_Var = {12, 0, NULL};\n  String* s = &s_Var;\n  s_Var.values = s_Values;"}) )
  CHECK(381, test_code(&(String){20, 19, "var Array{12:Int} a"}, &(String){94, 93, "Int a_Values[12];\n  Array a_Var = {12, NULL};\n  Array* a = &a_Var;\n  a_Var.values = a_Values;"}) )
  CHECK(384, test_code(&(String){21, 20, "var Array{12:Test} a"}, &(String){95, 94, "Test a_Values[12];\n  Array a_Var = {12, NULL};\n  Array* a = &a_Var;\n  a_Var.values = a_Values;"}) )
  CHECK(387, test_code(&(String){27, 26, "var Array{12:String{7}} sa"}, &(String){176, 175, "char sa_Chars[12 * 7];\n  String sa_Values[12];\n  Array sa_Var = {12, NULL};\n  Array* sa = &sa_Var;\n  sa_Var.values = sa_Values;\n  MR_set_var_string_array(12, 7, sa, sa_Chars);"}) )
  CHECK(390, test_code(&(String){18, 17, "t := Test(copy i)"}, &(String){155, 154, "Test* aux_Test_0 = NULL;\n  aux_Test_0 = calloc(1, sizeof(Test));\n  if (aux_Test_0 == NULL) RAISE(1)\n  CHECK(1, Test_new(aux_Test_0, i) )\n  t = aux_Test_0;"}) )
  CHECK(393, test_code(&(String){24, 23, "str := String{arr[0]}()"}, &(String){196, 195, "String* aux_String_0 = NULL;\n  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)\n  aux_String_0 = MR_new_string(((Int*)((arr)->values))[0]);\n  if (aux_String_0 == NULL) RAISE(1)\n  str = aux_String_0;"}) )
  CHECK(396, test_code(&(String){27, 26, "arr := Array{arr[0]:Int}()"}, &(String){203, 202, "Array* aux_Array_0 = NULL;\n  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)\n  aux_Array_0 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));\n  if (aux_Array_0 == NULL) RAISE(1)\n  arr = aux_Array_0;"}) )
  CHECK(399, test_code(&(String){46, 45, "owner Array{Test} a(var Array{arr[0]:Test}())"}, &(String){221, 220, "Array* a = NULL;\n  Array* aux_Array_0 = NULL;\n  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)\n  aux_Array_0 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Test));\n  if (aux_Array_0 == NULL) RAISE(1)\n  a = aux_Array_0;"}) )
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(403, String_copy(expected, &(String){19, 18, "Array* sa = NULL;\n"}) )
  CHECK(404, String_concat(expected, &(String){30, 29, "  Array* aux_Array_0 = NULL;\n"}) )
  CHECK(405, String_concat(expected, &(String){49, 48, "  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)\n"}) )
  CHECK(406, String_concat(expected, &(String){49, 48, "  if ((1) < 0 || (1) >= (arr)->length) RAISE(1)\n"}) )
  CHECK(407, String_concat(expected, &(String){14, 13, "  aux_Array_0"}) )
  CHECK(408, String_concat(expected, &(String){50, 49, " = MR_new_string_array(((Int*)((arr)->values))[0]"}) )
  CHECK(409, String_concat(expected, &(String){32, 31, ", ((Int*)((arr)->values))[1]);\n"}) )
  CHECK(410, String_concat(expected, &(String){37, 36, "  if (aux_Array_0 == NULL) RAISE(1)\n"}) )
  CHECK(411, String_concat(expected, &(String){20, 19, "  sa = aux_Array_0;"}) )
  CHECK(412, test_code(&(String){59, 58, "owner Array{String} sa(var Array{arr[0]:String{arr[1]}}())"}, expected) )
  CHECK(415, test_code(&(String){22, 21, "var Int x(var arr[0])"}, &(String){93, 92, "Int x = 0;\n  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)\n  x = ((Int*)((arr)->values))[0];"}) )
  CHECK(418, test_code(&(String){23, 22, "user String s(var str)"}, &(String){29, 28, "String* s = NULL;\n  s = str;"}) )
  CHECK(419, String_copy(expected, &(String){20, 19, "char s_Values[12];\n"}) )
  CHECK(420, String_concat(expected, &(String){33, 32, "  String s_Var = {12, 0, NULL};\n"}) )
  CHECK(421, String_concat(expected, &(String){23, 22, "  String* s = &s_Var;\n"}) )
  CHECK(422, String_concat(expected, &(String){34, 33, "  String aux_String_0_Var = {0};\n"}) )
  CHECK(423, String_concat(expected, &(String){45, 44, "  String* aux_String_0 = &aux_String_0_Var;\n"}) )
  CHECK(424, String_concat(expected, &(String){28, 27, "  s_Var.values = s_Values;\n"}) )
  CHECK(425, String_concat(expected, &(String){34, 33, "  aux_String_0->max_length = 12;\n"}) )
  CHECK(426, String_concat(expected, &(String){30, 29, "  aux_String_0->length = 11;\n"}) )
  CHECK(427, String_concat(expected, &(String){41, 40, "  aux_String_0->values = \"some string\";\n"}) )
  CHECK(428, String_concat(expected, &(String){41, 40, "  CHECK(1, String_new(s, aux_String_0) )"}) )
  CHECK(429, test_code(&(String){37, 36, "var String{12} s(user \"some string\")"}, expected) )
  CHECK(430, test_code(&(String){26, 25, "new String{i} s(user str)"}, &(String){100, 99, "String* s = NULL;\n  s = MR_new_string(i);\n  if (s == NULL) RAISE(1)\n  CHECK(1, String_new(s, str) )"}) )
  CHECK(433, test_code(&(String){21, 20, "user Test tt(var tc)"}, &(String){50, 49, "Test* tt = NULL;\n  tt = &(tc->_base._base._base);"}) )
  CHECK(436, test_code(&(String){20, 19, "var Test tt(copy 3)"}, &(String){70, 69, "Test tt_Var = {0};\n  Test* tt = &tt_Var;\n  CHECK(1, Test_new(tt, 3) )"}) )
  CHECK(439, test_code(&(String){20, 19, "new Test tt(copy 3)"}, &(String){105, 104, "Test* tt = NULL;\n  tt = calloc(1, sizeof(Test));\n  if (tt == NULL) RAISE(1)\n  CHECK(1, Test_new(tt, 3) )"}) )
  CHECK(442, test_code(&(String){18, 17, "t := Test(copy 3)"}, &(String){155, 154, "Test* aux_Test_0 = NULL;\n  aux_Test_0 = calloc(1, sizeof(Test));\n  if (aux_Test_0 == NULL) RAISE(1)\n  CHECK(1, Test_new(aux_Test_0, 3) )\n  t = aux_Test_0;"}) )
  CHECK(445, test_code_error(&(String){8, 7, "var Int"}, &(String){42, 41, "expected space after type, got \"new-line\""}) )
  CHECK(447, test_code_error(&(String){14, 13, "var Int Error"}, &(String){30, 29, "illegal variable name \"Error\""}) )
  CHECK(449, test_code_error(&(String){18, 17, "var Int errorName"}, &(String){34, 33, "illegal variable name \"errorName\""}) )
  CHECK(451, test_code_error(&(String){29, 28, "var Int name\n  var Int name\n"}, &(String){32, 31, "redefinition of variable \"name\""}) )
  CHECK(454, test_code_error(&(String){59, 58, "var Int name\n  do\n    var Int x\n    do\n      var Int name\n"}, &(String){32, 31, "redefinition of variable \"name\""}) )
  CHECK(457, test_global_scope_error(&(String){40, 39, "var Int name\nfunc mock()\n  var Int name"}, &(String){39, 38, "redefinition of global variable \"name\""}) )
  CHECK(460, test_global_scope_error(&(String){39, 38, "func name()\nfunc mock()\n  var Int name"}, &(String){40, 39, "variable name overrides function \"name\""}) )
  CHECK(463, test_global_scope_error(&(String){27, 26, "struct Test\n  var Int x(1)"}, &(String){35, 34, "type members cannot be initialized"}) )
  CHECK(466, test_global_scope_error(&(String){13, 12, "var Int x(1)"}, &(String){39, 38, "global variables cannot be initialized"}) )
  CHECK(468, test_global_scope_error(&(String){26, 25, "struct Test\n  var Test t\n"}, &(String){52, 51, "non-primitives cannot be declared \"var\" here yet..."}) )
  CHECK(471, test_code_error(&(String){6, 5, "Int()"}, &(String){43, 42, "dynamic allocation of primitive type \"Int\""}) )
  CHECK(473, test_code_error(&(String){13, 12, "var String s"}, &(String){28, 27, "missing length for sequence"}) )
  CHECK(474, test_code_error(&(String){23, 22, "var Array{4:String} sa"}, &(String){28, 27, "missing length for sequence"}) )
  CHECK(476, test_code_error(&(String){13, 12, "new String s"}, &(String){28, 27, "missing length for sequence"}) )
  CHECK(477, test_code_error(&(String){9, 8, "String()"}, &(String){28, 27, "missing length for sequence"}) )
  CHECK(478, test_code_error(&(String){13, 12, "user Array a"}, &(String){26, 25, "missing subtype for array"}) )
  CHECK(479, test_code_error(&(String){12, 11, "new Array a"}, &(String){26, 25, "missing subtype for array"}) )
  CHECK(480, test_code_error(&(String){8, 7, "Array()"}, &(String){26, 25, "missing subtype for array"}) )
  CHECK(481, test_code_error(&(String){16, 15, "var Array{23} a"}, &(String){26, 25, "missing subtype for array"}) )
  CHECK(482, test_code_error(&(String){28, 27, "var Array{1:Array{2:Int}} a"}, &(String){44, 43, "multidimensional array not supported yet..."}) )
  CHECK(485, test_code_error(&(String){12, 11, "var Array{1"}, &(String){29, 28, "expected \":\", got \"new-line\""}) )
  CHECK(486, test_code_error(&(String){14, 13, "var String{12"}, &(String){29, 28, "expected \"}\", got \"new-line\""}) )
  CHECK(487, test_code_error(&(String){23, 22, "var Array{error:Int} a"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(489, test_code_error(&(String){22, 21, "var Array{\"12\":Int} a"}, &(String){40, 39, "got \"String\" expression, expected \"Int\""}) )
  CHECK(492, test_code_error(&(String){11, 10, "user Int x"}, &(String){63, 62, "only \"var\" access is supported for primitive types, got \"user\""}) )
  CHECK(495, test_code_error(&(String){10, 9, "new Int x"}, &(String){62, 61, "only \"var\" access is supported for primitive types, got \"new\""}) )
  CHECK(498, test_code_error(&(String){13, 12, "var File f()"}, &(String){30, 29, "no contructor for type \"File\""}) )
  CHECK(500, test_code_error(&(String){18, 17, "var Bool x(var 1)"}, &(String){32, 31, "cannot assign \"Int\" into \"Bool\""}) )
  CHECK(502, test_code_error(&(String){24, 23, "var Int x(var 1, var 2)"}, &(String){20, 19, "too many parameters"}) )
  CHECK(504, test_global_scope_error(&(String){52, 51, "struct Test\n  var Int x\nfunc mock()\n  Test(copy 1)\n"}, &(String){30, 29, "no contructor for type \"Test\""}) )
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
  CHECK(511, test_code(&(String){23, 22, "# comment\n\n  var Int x"}, expected) )
  CHECK(512, test_code(&(String){30, 29, "## documemtation\n\n  var Int x"}, expected) )
  CHECK(513, test_code(&(String){42, 41, "{# multi \n line \n comment #}\n\n  var Int x"}, expected) )
  CHECK(514, test_code(&(String){49, 48, "{## multi \n line \n documemtation #}\n\n  var Int x"}, expected) )
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
  CHECK(520, test_code(&(String){24, 23, "if t.num > 3\n    i -= 2"}, &(String){60, 59, "if (t == NULL) RAISE(1)\n  if (t->num > 3) {\n    i -= 2;\n  }"}) )
  CHECK(523, test_code(&(String){38, 37, "if i > 3\n    i -= 2\n  else\n    i += 1"}, &(String){54, 53, "if (i > 3) {\n    i -= 2;\n  }\n  else {\n    i += 1;\n  }"}) )
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(527, String_copy(expected, &(String){14, 13, "if (i > 3) {\n"}) )
  CHECK(528, String_concat(expected, &(String){13, 12, "    i -= 3;\n"}) )
  CHECK(529, String_concat(expected, &(String){5, 4, "  }\n"}) )
  CHECK(530, String_concat(expected, &(String){10, 9, "  else {\n"}) )
  CHECK(531, String_concat(expected, &(String){29, 28, "    if (t == NULL) RAISE(3)\n"}) )
  CHECK(532, String_concat(expected, &(String){23, 22, "    if (t->num > 2) {\n"}) )
  CHECK(533, String_concat(expected, &(String){15, 14, "      i -= 2;\n"}) )
  CHECK(534, String_concat(expected, &(String){7, 6, "    }\n"}) )
  CHECK(535, String_concat(expected, &(String){12, 11, "    else {\n"}) )
  CHECK(536, String_concat(expected, &(String){31, 30, "      if (t == NULL) RAISE(5)\n"}) )
  CHECK(537, String_concat(expected, &(String){25, 24, "      if (t->num > 1) {\n"}) )
  CHECK(538, String_concat(expected, &(String){17, 16, "        i -= 1;\n"}) )
  CHECK(539, String_concat(expected, &(String){9, 8, "      }\n"}) )
  CHECK(540, String_concat(expected, &(String){14, 13, "      else {\n"}) )
  CHECK(541, String_concat(expected, &(String){17, 16, "        i += 1;\n"}) )
  CHECK(542, String_concat(expected, &(String){9, 8, "      }\n"}) )
  CHECK(543, String_concat(expected, &(String){7, 6, "    }\n"}) )
  CHECK(544, String_concat(expected, &(String){4, 3, "  }"}) )
  CHECK(545, test_code(&(String){100, 99, "if i > 3\n    i -= 3\n  else-if t.num > 2\n    i -= 2\n  else-if t.num > 1\n    i -= 1\n  else\n    i += 1"}, expected) )
  CHECK(548, test_code(&(String){25, 24, "if b\n    return\n  i := 3"}, &(String){43, 42, "if (b) {\n    goto MR_cleanup;\n  }\n  i = 3;"}) )
  CHECK(551, test_code_error(&(String){5, 4, "if 3"}, &(String){38, 37, "got \"Int\" expression, expected \"Bool\""}) )
  CHECK(553, test_code_error(&(String){15, 14, "if b\n    error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(554, test_code_error(&(String){33, 32, "if b\n    i := 0\n  else\n    error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(557, test_code_error(&(String){38, 37, "if b\n    i := 0\n  else-if b\n    error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(560, test_code_error(&(String){27, 26, "if b\n    return\n    i := 3"}, &(String){17, 16, "unreachable code"}) )
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
  CHECK(565, test_code(&(String){17, 16, "do\n    var Int x"}, &(String){32, 31, "Int x = 0;\n  while (true) {\n  }"}) )
  CHECK(566, test_code(&(String){22, 21, "\n  \n    \n\n  var Int x"}, &(String){11, 10, "Int x = 0;"}) )
  CHECK(567, test_code(&(String){23, 22, "do\n    while t.num > 3"}, &(String){77, 76, "while (true) {\n    if (t == NULL) RAISE(2)\n    if (!(t->num > 3)) break;\n  }"}) )
  CHECK(570, test_code(&(String){16, 15, "do\n    continue"}, &(String){33, 32, "while (true) {\n    continue;\n  }"}) )
  CHECK(571, test_code_error(&(String){4, 3, "do("}, &(String){38, 37, "expected new-line after \"do\", got \"(\""}) )
  CHECK(572, test_code_error(&(String){11, 10, "while true"}, &(String){29, 28, "\"while\" used not inside loop"}) )
  CHECK(573, test_code_error(&(String){9, 8, "continue"}, &(String){32, 31, "\"continue\" used not inside loop"}) )
  CHECK(574, test_code_error(&(String){15, 14, "do\n    while 2"}, &(String){38, 37, "got \"Int\" expression, expected \"Bool\""}) )
  CHECK(576, test_code_error(&(String){13, 12, "do\n    error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(577, test_code_error(&(String){44, 43, "do\n    var Int error\n  do\n    var Int error"}, &(String){33, 32, "redefinition of variable \"error\""}) )
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
  CHECK(583, test_code(&(String){22, 21, "for n in 5\n    i += n"}, &(String){49, 48, "{int n; for(n=0; n<5; ++n) {\n    i += n;\n  }\n  }"}) )
  CHECK(586, test_code(&(String){36, 35, "for n in t.num:t.num + 2\n    i += n"}, &(String){115, 114, "if (t == NULL) RAISE(1)\n  if (t == NULL) RAISE(1)\n  {int n; for(n=t->num; n<t->num + 2; ++n) {\n    i += n;\n  }\n  }"}) )
  CHECK(589, test_code_error(&(String){5, 4, "for("}, &(String){36, 35, "expected space after \"for\", got \"(\""}) )
  CHECK(590, test_code_error(&(String){6, 5, "for n"}, &(String){48, 47, "expected space after index name, got \"new-line\""}) )
  CHECK(592, test_code_error(&(String){12, 11, "for n error"}, &(String){25, 24, "expected \"in \" got \"err\""}) )
  CHECK(594, test_code_error(&(String){13, 12, "for n in str"}, &(String){40, 39, "got \"String\" expression, expected \"Int\""}) )
  CHECK(596, test_code_error(&(String){15, 14, "for n in str:8"}, &(String){40, 39, "got \"String\" expression, expected \"Int\""}) )
  CHECK(598, test_code_error(&(String){21, 20, "for n in 5\n    error"}, &(String){23, 22, "unknown symbol \"error\""}) )
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
  CHECK(602, test_code(&(String){17, 16, "assert t.num = 2"}, &(String){54, 53, "if (t == NULL) RAISE(1)\n  TEST_ASSERT(1, t->num == 2)"}) )
  CHECK(605, test_code(&(String){19, 18, "assert-error t.num"}, &(String){246, 245, "do {\n    MR_trace_stream = NULL;\n#undef RETURN_ERROR\n#define RETURN_ERROR(value) break\n    if (t == NULL) RAISE(1)\n    #undef RETURN_ERROR\n#define RETURN_ERROR(value) return value\n    MR_trace_stream = stdout;\n    TEST_FAIL(1)\n  } while (false);"}) )
  CHECK(608, test_code(&(String){20, 19, "assert-error fun0()"}, &(String){240, 239, "do {\n    MR_trace_stream = NULL;\n#undef RETURN_ERROR\n#define RETURN_ERROR(value) break\n    CHECK(1, fun0() )\n    #undef RETURN_ERROR\n#define RETURN_ERROR(value) return value\n    MR_trace_stream = stdout;\n    TEST_FAIL(1)\n  } while (false);"}) )
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(612, String_copy(expected, &(String){23, 22, "Returncode fun(void);\n"}) )
  CHECK(613, String_concat(expected, &(String){28, 27, "Returncode Mock_fun(void);\n"}) )
  CHECK(614, String_concat(expected, &(String){24, 23, "Returncode fun(void) {\n"}) )
  CHECK(615, String_concat(expected, &(String){27, 26, "  Returncode MR_err = OK;\n"}) )
  CHECK(616, String_concat(expected, &(String){25, 24, "  CHECK(2, Mock_fun() )\n"}) )
  CHECK(617, String_concat(expected, &(String){13, 12, "MR_cleanup:\n"}) )
  CHECK(618, String_concat(expected, &(String){18, 17, "  return MR_err;\n"}) )
  CHECK(619, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(620, String_concat(expected, &(String){29, 28, "Returncode Mock_fun(void) {\n"}) )
  CHECK(621, String_concat(expected, &(String){27, 26, "  Returncode MR_err = OK;\n"}) )
  CHECK(622, String_concat(expected, &(String){12, 11, "  RAISE(4)\n"}) )
  CHECK(623, String_concat(expected, &(String){13, 12, "MR_cleanup:\n"}) )
  CHECK(624, String_concat(expected, &(String){18, 17, "  return MR_err;\n"}) )
  CHECK(625, String_concat(expected, &(String){2, 1, "}"}) )
  CHECK(626, test_global_scope(&(String){38, 37, "func fun()\n  fun()\nmock fun()\n  raise"}, expected) )
  CHECK(629, test_global_scope(&(String){31, 30, "mock fun()\nfunc fun()\n  fun()\n"}, &(String){238, 237, "Returncode Mock_fun(void);\nReturncode fun(void);\nReturncode Mock_fun(void) {\n  Returncode MR_err = OK;\nMR_cleanup:\n  return MR_err;\n}\nReturncode fun(void) {\n  Returncode MR_err = OK;\n  CHECK(3, Mock_fun() )\nMR_cleanup:\n  return MR_err;\n}"}) )
  CHECK(632, String_copy(expected, &(String){27, 26, "typedef struct Test Test;\n"}) )
  CHECK(633, String_concat(expected, &(String){15, 14, "struct Test {\n"}) )
  CHECK(634, String_concat(expected, &(String){10, 9, "  Int x;\n"}) )
  CHECK(635, String_concat(expected, &(String){4, 3, "};\n"}) )
  CHECK(636, String_concat(expected, &(String){42, 41, "Returncode Test_meth(Test* self, Int x);\n"}) )
  CHECK(637, String_concat(expected, &(String){47, 46, "Returncode Test_Mock_meth(Test* self, Int x);\n"}) )
  CHECK(638, String_concat(expected, &(String){43, 42, "Returncode Test_meth(Test* self, Int x) {\n"}) )
  CHECK(639, String_concat(expected, &(String){27, 26, "  Returncode MR_err = OK;\n"}) )
  CHECK(640, String_concat(expected, &(String){38, 37, "  CHECK(5, Test_Mock_meth(self, x) )\n"}) )
  CHECK(641, String_concat(expected, &(String){13, 12, "MR_cleanup:\n"}) )
  CHECK(642, String_concat(expected, &(String){18, 17, "  return MR_err;\n"}) )
  CHECK(643, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(644, String_concat(expected, &(String){45, 44, "Returncode Test_Mock_meth(Test* self, Int x)"}) )
  CHECK(645, String_concat(expected, empty_func_body) )
  expected->length -= 1;
  CHECK(647, test_global_scope(&(String){97, 96, "mock Test.meth(copy Int x)\nstruct Test\n  var Int x\n  func meth(copy Int x)\n    self.meth(copy x)"}, expected) )
  CHECK(650, String_copy(expected, &(String){24, 23, "Returncode fun0(void);\n"}) )
  CHECK(651, String_concat(expected, &(String){24, 23, "Returncode fun1(void);\n"}) )
  CHECK(652, String_concat(expected, &(String){22, 21, "Returncode fun0(void)"}) )
  CHECK(653, String_concat(expected, empty_func_body) )
  CHECK(654, String_concat(expected, &(String){22, 21, "Returncode fun1(void)"}) )
  CHECK(655, String_concat(expected, empty_func_body) )
  CHECK(656, String_concat(expected, &(String){20, 19, "USER_MAIN_HEADER {\n"}) )
  CHECK(657, String_concat(expected, &(String){27, 26, "  Bool MR_success = true;\n"}) )
  CHECK(658, String_concat(expected, &(String){19, 18, "  RUN_TEST(fun0);\n"}) )
  CHECK(659, String_concat(expected, &(String){19, 18, "  RUN_TEST(fun1);\n"}) )
  CHECK(660, String_concat(expected, &(String){33, 32, "  return MR_success? OK : FAIL;\n"}) )
  CHECK(661, String_concat(expected, &(String){3, 2, "}\n"}) )
  CHECK(662, String_concat(expected, &(String){15, 14, "TEST_MAIN_FUNC"}) )
  CHECK(663, test_global_scope(&(String){25, 24, "test fun0()\ntest fun1()\n"}, expected) )
  CHECK(664, test_global_scope(&(String){30, 29, "test fun0()\ntest fun1()\nmain\n"}, expected) )
  CHECK(665, test_code_error(&(String){9, 8, "assert 3"}, &(String){38, 37, "got \"Int\" expression, expected \"Bool\""}) )
  CHECK(667, test_code_error(&(String){13, 12, "assert error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(668, test_code_error(&(String){19, 18, "assert-error error"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(669, test_global_scope_error(&(String){22, 21, "test fun(copy Int x)\n"}, &(String){36, 35, "test function cannot have arguments"}) )
  CHECK(671, test_global_scope_error(&(String){26, 25, "test fun()->(copy Int x)\n"}, &(String){36, 35, "test function cannot have arguments"}) )
  CHECK(674, test_global_scope_error(&(String){14, 13, "mock error()\n"}, &(String){33, 32, "mocking unknown function \"error\""}) )
  CHECK(676, test_global_scope_error(&(String){18, 17, "mock Error.fun()\n"}, &(String){21, 20, "unknown type \"Error\""}) )
  CHECK(678, test_global_scope_error(&(String){43, 42, "struct Test\n  var Int x\nmock Test.error()\n"}, &(String){46, 45, "mocking unknown method \"error\" of type \"Test\""}) )
  CHECK(681, test_global_scope_error(&(String){50, 49, "mock fun(owner String s)\nfunc fun(user String s)\n"}, &(String){37, 36, "expected access \"user\" , got \"owner\""}) )
  CHECK(684, test_global_scope_error(&(String){46, 45, "mock fun(user Int s)\nfunc fun(user String s)\n"}, &(String){38, 37, "non matching types \"Int\" and \"String\""}) )
  CHECK(687, test_global_scope_error(&(String){58, 57, "mock fun(user Array{Char} a)\nfunc fun(user Array{Int} a)\n"}, &(String){39, 38, "non matching subtypes \"Char\" and \"Int\""}) )
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
