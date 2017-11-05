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
Returncode test_global();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_global = "test-global";
#define MR_FUNC_NAME _func_name_test_global
Returncode test_global() {
  CHECK(49, test_global_scope(&(String){16, 15, "user String str"}, &(String){13, 12, "String* str;"}) )
  String* expected = &(String){7, 6, "Int x;"};
  CHECK(51, test_global_scope(&(String){15, 14, "\n  \n\nvar Int x"}, expected) )
  CHECK(52, test_global_scope(&(String){21, 20, "# comment\n\nvar Int x"}, expected) )
  CHECK(53, test_global_scope(&(String){28, 27, "## documemtation\n\nvar Int x"}, expected) )
  CHECK(54, test_global_scope(&(String){40, 39, "{# multi \n line \n comment #}\n\nvar Int x"}, expected) )
  CHECK(56, test_global_scope(&(String){47, 46, "{## multi \n line \n documemtation #}\n\nvar Int x"}, expected) )
  CHECK(58, test_global_scope_error(&(String){7, 6, "error "}, &(String){24, 23, "unknown keyword \"error\""}) )
  CHECK(59, test_global_scope_error(&(String){15, 14, "{# comment #}?"}, &(String){39, 38, "expected new-line in line end, got \"?\""}) )
  CHECK(61, test_global_scope_error(&(String){7, 6, "main(\n"}, &(String){40, 39, "expected new-line after \"main\", got \"(\""}) )
  CHECK(63, test_global_scope_error(&(String){14, 13, "  struct Test"}, &(String){42, 41, "indentation too big, expected \"0\" got \"2\""}) )
  CHECK(66, test_global_scope_error(&(String){10, 9, "var Int x"}, &(String){28, 27, "no new-line before file end"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_type();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_type = "test-type";
#define MR_FUNC_NAME _func_name_test_type
Returncode test_type() {
  CHECK(72, test_global_scope(&(String){24, 23, "struct Test\n  var Int x"}, &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"}) )
  CHECK(75, test_global_scope(&(String){24, 23, "struct Test\n  var Int x"}, &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"}) )
  CHECK(78, test_global_scope(&(String){77, 76, "struct Test1\n  var Int x\nstruct Test2\n  var Int x\n\n\nstruct Test3\n  var Int x"}, &(String){165, 164, "typedef struct Test1 Test1;\ntypedef struct Test2 Test2;\ntypedef struct Test3 Test3;\nstruct Test1 {\n  Int x;\n};\nstruct Test2 {\n  Int x;\n};\nstruct Test3 {\n  Int x;\n};"}) )
  CHECK(81, test_global_scope(&(String){57, 56, "struct Test2(Test1)\n  var Int y\nstruct Test1\n  var Int x"}, &(String){125, 124, "typedef struct Test1 Test1;\ntypedef struct Test2 Test2;\nstruct Test1 {\n  Int x;\n};\nstruct Test2 {\n  Test1 _base;\n  Int y;\n};"}) )
  CHECK(84, test_global_scope_error(&(String){9, 8, "struct(\n"}, &(String){39, 38, "expected space after \"struct\", got \"(\""}) )
  CHECK(86, test_global_scope_error(&(String){8, 7, "class(\n"}, &(String){38, 37, "expected space after \"class\", got \"(\""}) )
  CHECK(88, test_global_scope_error(&(String){21, 20, "struct Test\n  error "}, &(String){24, 23, "unknown keyword \"error\""}) )
  CHECK(91, test_global_scope_error(&(String){12, 11, "struct Test"}, &(String){40, 39, "expected block in a new line, got \"EOF\""}) )
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
  CHECK(97, test_global_scope(&(String){12, 11, "func name()"}, &(String){62, 61, "Returncode name(void);\nReturncode name(void) {\n  return OK;\n}"}) )
  CHECK(100, test_global_scope(&(String){59, 58, "func name(var String self, user String text, copy Int num)"}, &(String){124, 123, "Returncode name(String* self, String* text, Int num);\nReturncode name(String* self, String* text, Int num) {\n  return OK;\n}"}) )
  CHECK(103, test_global_scope(&(String){47, 46, "func name()->(owner String text, copy Int num)"}, &(String){100, 99, "Returncode name(String** text, Int* num);\nReturncode name(String** text, Int* num) {\n  return OK;\n}"}) )
  CHECK(106, test_global_scope(&(String){47, 46, "func name(copy Char param)->(owner String out)"}, &(String){102, 101, "Returncode name(Char param, String** out);\nReturncode name(Char param, String** out) {\n  return OK;\n}"}) )
  CHECK(109, test_global_scope(&(String){33, 32, "func name(user Array{Int} array)"}, &(String){78, 77, "Returncode name(Array* array);\nReturncode name(Array* array) {\n  return OK;\n}"}) )
  CHECK(112, test_global_scope(&(String){47, 46, "func name(user Array{Array{Array{Int}}} array)"}, &(String){78, 77, "Returncode name(Array* array);\nReturncode name(Array* array) {\n  return OK;\n}"}) )
  CHECK(115, test_global_scope(&(String){24, 23, "func name()\n  var Int x"}, &(String){75, 74, "Returncode name(void);\nReturncode name(void) {\n  Int x = 0;\n  return OK;\n}"}) )
  CHECK(118, test_global_scope(&(String){17, 16, "main\n  var Int x"}, &(String){57, 56, "USER_MAIN_HEADER {\n  Int x = 0;\n  return OK;\n}\nMAIN_FUNC"}) )
  CHECK(121, test_global_scope_error(&(String){7, 6, "func(\n"}, &(String){37, 36, "expected space after \"func\", got \"(\""}) )
  CHECK(123, test_global_scope_error(&(String){11, 10, "func name\n"}, &(String){49, 48, "expected \"(\" after function name, got \"new-line\""}) )
  CHECK(126, test_global_scope_error(&(String){14, 13, "func name( )\n"}, &(String){25, 24, "expected access, got \" \""}) )
  CHECK(129, test_global_scope_error(&(String){17, 16, "func name(user)\n"}, &(String){37, 36, "expected space after access, got \")\""}) )
  CHECK(132, test_global_scope_error(&(String){22, 21, "func name(var String\n"}, &(String){42, 41, "expected space after type, got \"new-line\""}) )
  CHECK(135, test_global_scope_error(&(String){24, 23, "func name(error Int x)\n"}, &(String){23, 22, "illegal access \"error\""}) )
  CHECK(138, test_global_scope_error(&(String){38, 37, "func name(var String str,user Int x)\n"}, &(String){46, 45, "expected space or new-line after \",\", got \"u\""}) )
  CHECK(141, test_global_scope_error(&(String){16, 15, "func name()-()\n"}, &(String){23, 22, "expected \">(\" got \"()\""}) )
  CHECK(144, test_global_scope_error(&(String){12, 11, "func name()"}, &(String){40, 39, "expected block in a new line, got \"EOF\""}) )
  CHECK(147, test_global_scope_error(&(String){26, 25, "func name()\n    var Int x"}, &(String){42, 41, "indentation too big, expected \"2\" got \"4\""}) )
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
  CHECK(153, test_global_scope(&(String){42, 41, "struct Test\n  var Int x\n  user String str"}, &(String){67, 66, "typedef struct Test Test;\nstruct Test {\n  Int x;\n  String* str;\n};"}) )
  CHECK(156, test_global_scope(&(String){38, 37, "struct Test\n  var Int x\n  func name()"}, &(String){136, 135, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};\nReturncode Test_name(Test* self);\nReturncode Test_name(Test* self) {\n  return OK;\n}"}) )
  CHECK(159, test_global_scope(&(String){52, 51, "struct Test\n  var Int x\n  func name()\n    var Int x"}, &(String){149, 148, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};\nReturncode Test_name(Test* self);\nReturncode Test_name(Test* self) {\n  Int x = 0;\n  return OK;\n}"}) )
  String* expected = &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"};
  CHECK(163, test_global_scope(&(String){36, 35, "struct Test\n  # comment\n  var Int x"}, expected) )
  CHECK(164, test_global_scope(&(String){43, 42, "struct Test\n  ## documemtation\n  var Int x"}, expected) )
  CHECK(166, test_global_scope(&(String){55, 54, "struct Test\n  {# multi \n line \n comment #}\n  var Int x"}, expected) )
  CHECK(169, test_global_scope(&(String){62, 61, "struct Test\n  {## multi \n line \n documemtation #}\n  var Int x"}, expected) )
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
  CHECK(175, test_global_scope(&(String){21, 20, "func name()\n  return"}, &(String){62, 61, "Returncode name(void);\nReturncode name(void) {\n  return OK;\n}"}) )
  CHECK(178, test_global_scope(&(String){20, 19, "func name()\n  raise"}, &(String){60, 59, "Returncode name(void);\nReturncode name(void) {\n  RAISE(2)\n}"}) )
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
  CHECK(184, test_code(&(String){10, 9, "var Int x"}, &(String){11, 10, "Int x = 0;"}) )
  CHECK(185, test_code(&(String){14, 13, "user String s"}, &(String){18, 17, "String* s = NULL;"}) )
  CHECK(186, test_code(&(String){19, 18, "owner Array{Int} a"}, &(String){17, 16, "Array* a = NULL;"}) )
  CHECK(187, test_code(&(String){12, 11, "user Test t"}, &(String){16, 15, "Test* t = NULL;"}) )
  CHECK(188, test_code(&(String){11, 10, "var Test t"}, &(String){38, 37, "Test t_Var = {0};\n  Test* t = &t_Var;"}) )
  CHECK(189, test_code(&(String){17, 16, "var String{12} s"}, &(String){100, 99, "char s_Values[12];\n  String s_Var = {12, 0, NULL};\n  String* s = &s_Var;\n  s_Var.values = s_Values;"}) )
  CHECK(192, test_code(&(String){20, 19, "var Array{12:Int} a"}, &(String){94, 93, "Int a_Values[12];\n  Array a_Var = {12, NULL};\n  Array* a = &a_Var;\n  a_Var.values = a_Values;"}) )
  CHECK(195, test_code(&(String){21, 20, "var Array{12:Test} a"}, &(String){95, 94, "Test a_Values[12];\n  Array a_Var = {12, NULL};\n  Array* a = &a_Var;\n  a_Var.values = a_Values;"}) )
  CHECK(198, test_code(&(String){27, 26, "var Array{12:String{7}} sa"}, &(String){176, 175, "char sa_Chars[12 * 7];\n  String sa_Values[12];\n  Array sa_Var = {12, NULL};\n  Array* sa = &sa_Var;\n  sa_Var.values = sa_Values;\n  MR_set_var_string_array(12, 7, sa, sa_Chars);"}) )
  CHECK(201, test_code(&(String){11, 10, "new Test t"}, &(String){47, 46, "Test* t = NULL;\n  t = calloc(1, sizeof(Test));"}) )
  CHECK(203, test_code(&(String){21, 20, "new String{arr[0]} s"}, &(String){115, 114, "String* s = NULL;\n  if ((0) < 0 || (0) >= (arr)->length) RAISE(4)\n  s = MR_new_string(((Int*)((arr)->values))[0]);"}) )
  CHECK(206, test_code(&(String){24, 23, "new Array{arr[0]:Int} a"}, &(String){126, 125, "Array* a = NULL;\n  if ((0) < 0 || (0) >= (arr)->length) RAISE(4)\n  a = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));"}) )
  CHECK(209, test_code(&(String){25, 24, "new Array{arr[0]:Test} a"}, &(String){127, 126, "Array* a = NULL;\n  if ((0) < 0 || (0) >= (arr)->length) RAISE(4)\n  a = MR_new_array(((Int*)((arr)->values))[0], sizeof(Test));"}) )
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(213, String_copy(expected, &(String){19, 18, "Array* sa = NULL;\n"}) )
  CHECK(214, String_concat(expected, &(String){49, 48, "  if ((0) < 0 || (0) >= (arr)->length) RAISE(4)\n"}) )
  CHECK(215, String_concat(expected, &(String){49, 48, "  if ((1) < 0 || (1) >= (arr)->length) RAISE(4)\n"}) )
  CHECK(216, String_concat(expected, &(String){49, 48, "  sa = MR_new_array(((Int*)((arr)->values))[0], "}) )
  CHECK(217, String_concat(expected, &(String){49, 48, "sizeof(String) + (((Int*)((arr)->values))[1]));\n"}) )
  CHECK(218, String_concat(expected, &(String){27, 26, "  MR_set_new_string_array("}) )
  CHECK(219, String_concat(expected, &(String){29, 28, "((Int*)((arr)->values))[0], "}) )
  CHECK(220, String_concat(expected, &(String){33, 32, "((Int*)((arr)->values))[1], sa);"}) )
  CHECK(221, test_code(&(String){36, 35, "new Array{arr[0]:String{arr[1]}} sa"}, expected) )
  CHECK(222, test_code(&(String){18, 17, "var Int x(arr[0])"}, &(String){93, 92, "Int x = 0;\n  if ((0) < 0 || (0) >= (arr)->length) RAISE(4)\n  x = ((Int*)((arr)->values))[0];"}) )
  CHECK(225, test_code(&(String){19, 18, "user String s(str)"}, &(String){29, 28, "String* s = NULL;\n  s = str;"}) )
  CHECK(226, String_copy(expected, &(String){20, 19, "char s_Values[12];\n"}) )
  CHECK(227, String_concat(expected, &(String){33, 32, "  String s_Var = {12, 0, NULL};\n"}) )
  CHECK(228, String_concat(expected, &(String){23, 22, "  String* s = &s_Var;\n"}) )
  CHECK(229, String_concat(expected, &(String){34, 33, "  String aux_String_0_Var = {0};\n"}) )
  CHECK(230, String_concat(expected, &(String){45, 44, "  String* aux_String_0 = &aux_String_0_Var;\n"}) )
  CHECK(231, String_concat(expected, &(String){28, 27, "  s_Var.values = s_Values;\n"}) )
  CHECK(232, String_concat(expected, &(String){34, 33, "  aux_String_0->max_length = 12;\n"}) )
  CHECK(233, String_concat(expected, &(String){30, 29, "  aux_String_0->length = 11;\n"}) )
  CHECK(234, String_concat(expected, &(String){41, 40, "  aux_String_0->values = \"some string\";\n"}) )
  CHECK(235, String_concat(expected, &(String){42, 41, "  CHECK(4, String_copy(s, aux_String_0) )"}) )
  CHECK(236, test_code(&(String){32, 31, "var String{12} s(\"some string\")"}, expected) )
  CHECK(237, test_code(&(String){21, 20, "new String{i} s(str)"}, &(String){75, 74, "String* s = NULL;\n  s = MR_new_string(i);\n  CHECK(4, String_copy(s, str) )"}) )
  CHECK(240, test_code_error(&(String){8, 7, "var Int"}, &(String){42, 41, "expected space after type, got \"new-line\""}) )
  CHECK(242, test_global_scope_error(&(String){27, 26, "struct Test\n  var Int x(1)"}, &(String){35, 34, "type members cannot be initialized"}) )
  CHECK(245, test_global_scope_error(&(String){13, 12, "var Int x(1)"}, &(String){39, 38, "global variables cannot be initialized"}) )
  CHECK(247, test_global_scope_error(&(String){26, 25, "struct Test\n  var Test t\n"}, &(String){52, 51, "non-primitives cannot be declared \"var\" here yet..."}) )
  CHECK(250, test_code_error(&(String){13, 12, "var String s"}, &(String){28, 27, "missing length for sequence"}) )
  CHECK(251, test_code_error(&(String){23, 22, "var Array{4:String} sa"}, &(String){28, 27, "missing length for sequence"}) )
  CHECK(253, test_code_error(&(String){13, 12, "user Array a"}, &(String){26, 25, "missing subtype for array"}) )
  CHECK(254, test_code_error(&(String){16, 15, "var Array{23} a"}, &(String){26, 25, "missing subtype for array"}) )
  CHECK(255, test_code_error(&(String){28, 27, "var Array{1:Array{2:Int}} a"}, &(String){44, 43, "multidimensional array not supported yet..."}) )
  CHECK(258, test_code_error(&(String){12, 11, "var Array{1"}, &(String){29, 28, "expected \":\", got \"new-line\""}) )
  CHECK(259, test_code_error(&(String){14, 13, "var String{12"}, &(String){29, 28, "expected \"}\", got \"new-line\""}) )
  CHECK(260, test_code_error(&(String){23, 22, "var Array{error:Int} a"}, &(String){23, 22, "unknown symbol \"error\""}) )
  CHECK(262, test_code_error(&(String){22, 21, "var Array{\"12\":Int} a"}, &(String){40, 39, "got \"String\" expression, expected \"Int\""}) )
  CHECK(265, test_code_error(&(String){10, 9, "new Int x"}, &(String){43, 42, "cannot use \"new\" with primitive type \"Int\""}) )
  CHECK(267, test_code_error(&(String){12, 11, "var Int x(1"}, &(String){50, 49, "expected \")\" after initialization, got \"new-line\""}) )
  CHECK(270, test_code_error(&(String){14, 13, "var File f(1)"}, &(String){44, 43, "cannot initialize non-primitive type \"File\""}) )
  CHECK(273, test_code_error(&(String){14, 13, "var Bool x(1)"}, &(String){32, 31, "cannot assign \"Int\" into \"Bool\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_simple_code();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_simple_code = "test-simple-code";
#define MR_FUNC_NAME _func_name_test_simple_code
Returncode test_simple_code() {
  String* expected = &(String){11, 10, "Int x = 0;"};
  CHECK(279, test_code(&(String){23, 22, "# comment\n\n  var Int x"}, expected) )
  CHECK(280, test_code(&(String){30, 29, "## documemtation\n\n  var Int x"}, expected) )
  CHECK(281, test_code(&(String){42, 41, "{# multi \n line \n comment #}\n\n  var Int x"}, expected) )
  CHECK(282, test_code(&(String){49, 48, "{## multi \n line \n documemtation #}\n\n  var Int x"}, expected) )
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
  CHECK(288, test_code(&(String){20, 19, "if i > 3\n    i -= 2"}, &(String){29, 28, "if (i > 3) {\n    i -= 2;\n  }"}) )
  CHECK(289, test_code(&(String){38, 37, "if i > 3\n    i -= 2\n  else\n    i += 1"}, &(String){54, 53, "if (i > 3) {\n    i -= 2;\n  }\n  else {\n    i += 1;\n  }"}) )
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(293, String_copy(expected, &(String){14, 13, "if (i > 3) {\n"}) )
  CHECK(294, String_concat(expected, &(String){13, 12, "    i -= 3;\n"}) )
  CHECK(295, String_concat(expected, &(String){5, 4, "  }\n"}) )
  CHECK(296, String_concat(expected, &(String){10, 9, "  else {\n"}) )
  CHECK(297, String_concat(expected, &(String){18, 17, "    if (i > 2) {\n"}) )
  CHECK(298, String_concat(expected, &(String){15, 14, "      i -= 2;\n"}) )
  CHECK(299, String_concat(expected, &(String){7, 6, "    }\n"}) )
  CHECK(300, String_concat(expected, &(String){12, 11, "    else {\n"}) )
  CHECK(301, String_concat(expected, &(String){20, 19, "      if (i > 1) {\n"}) )
  CHECK(302, String_concat(expected, &(String){17, 16, "        i -= 1;\n"}) )
  CHECK(303, String_concat(expected, &(String){9, 8, "      }\n"}) )
  CHECK(304, String_concat(expected, &(String){14, 13, "      else {\n"}) )
  CHECK(305, String_concat(expected, &(String){17, 16, "        i += 1;\n"}) )
  CHECK(306, String_concat(expected, &(String){9, 8, "      }\n"}) )
  CHECK(307, String_concat(expected, &(String){7, 6, "    }\n"}) )
  CHECK(308, String_concat(expected, &(String){4, 3, "  }"}) )
  CHECK(309, test_code(&(String){92, 91, "if i > 3\n    i -= 3\n  else-if i > 2\n    i -= 2\n  else-if i > 1\n    i -= 1\n  else\n    i += 1"}, expected) )
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
  CHECK(315, test_code(&(String){17, 16, "do\n    var Int x"}, &(String){34, 33, "while (true) {\n    Int x = 0;\n  }"}) )
  CHECK(316, test_code(&(String){22, 21, "\n  \n    \n\n  var Int x"}, &(String){11, 10, "Int x = 0;"}) )
  CHECK(317, test_code(&(String){19, 18, "do\n    while i > 3"}, &(String){44, 43, "while (true) {\n    if (!(i > 3)) break;\n  }"}) )
  CHECK(320, test_code(&(String){16, 15, "do\n    continue"}, &(String){33, 32, "while (true) {\n    continue;\n  }"}) )
  CHECK(321, test_code_error(&(String){4, 3, "do("}, &(String){38, 37, "expected new-line after \"do\", got \"(\""}) )
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
  CHECK(325, test_code(&(String){22, 21, "for n in 5\n    i += n"}, &(String){46, 45, "{int n; for(n=0; n<5; ++n) {\n    i += n;\n  }}"}) )
  CHECK(328, test_code(&(String){28, 27, "for n in i:i + 2\n    i += n"}, &(String){50, 49, "{int n; for(n=i; n<i + 2; ++n) {\n    i += n;\n  }}"}) )
  CHECK(331, test_code_error(&(String){5, 4, "for("}, &(String){36, 35, "expected space after \"for\", got \"(\""}) )
  CHECK(332, test_code_error(&(String){6, 5, "for n"}, &(String){48, 47, "expected space after index name, got \"new-line\""}) )
  CHECK(334, test_code_error(&(String){12, 11, "for n error"}, &(String){25, 24, "expected \"in \" got \"err\""}) )
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
