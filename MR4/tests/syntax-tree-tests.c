#ifndef MR_MAINFILE
#define MR_MAINFILE "tests/syntax-tree-tests.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file22_name = "tests/syntax-tree-tests.3.mr";
#endif
#define MR_FILE_NAME _mr_file22_name

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
  CHECK(8, (glob->root)->_base._base._base._dtl[0](glob->root) )
  CHECK(9, (glob->root)->_base._base._base._dtl[1](glob->root) )
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
  CHECK(59, test_global_scope_error(&(String){7, 6, "main(\n"}, &(String){40, 39, "expected new-line after \"main\", got \"(\""}) )
  CHECK(61, test_global_scope_error(&(String){14, 13, "  struct Test"}, &(String){42, 41, "indentation too big, expected \"0\" got \"2\""}) )
  CHECK(64, test_global_scope_error(&(String){10, 9, "var Int x"}, &(String){28, 27, "no new-line before file end"}) )
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
  CHECK(70, test_global_scope(&(String){24, 23, "struct Test\n  var Int x"}, &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"}) )
  CHECK(73, test_global_scope(&(String){24, 23, "struct Test\n  var Int x"}, &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"}) )
  CHECK(76, test_global_scope(&(String){77, 76, "struct Test1\n  var Int x\nstruct Test2\n  var Int x\n\n\nstruct Test3\n  var Int x"}, &(String){165, 164, "typedef struct Test1 Test1;\ntypedef struct Test2 Test2;\ntypedef struct Test3 Test3;\nstruct Test1 {\n  Int x;\n};\nstruct Test2 {\n  Int x;\n};\nstruct Test3 {\n  Int x;\n};"}) )
  CHECK(79, test_global_scope(&(String){57, 56, "struct Test2(Test1)\n  var Int y\nstruct Test1\n  var Int x"}, &(String){125, 124, "typedef struct Test1 Test1;\ntypedef struct Test2 Test2;\nstruct Test1 {\n  Int x;\n};\nstruct Test2 {\n  Test1 _base;\n  Int y;\n};"}) )
  CHECK(82, test_global_scope_error(&(String){9, 8, "struct(\n"}, &(String){39, 38, "expected space after \"struct\", got \"(\""}) )
  CHECK(84, test_global_scope_error(&(String){8, 7, "class(\n"}, &(String){38, 37, "expected space after \"class\", got \"(\""}) )
  CHECK(86, test_global_scope_error(&(String){21, 20, "struct Test\n  error "}, &(String){24, 23, "unknown keyword \"error\""}) )
  CHECK(89, test_global_scope_error(&(String){12, 11, "struct Test"}, &(String){40, 39, "expected block in a new line, got \"EOF\""}) )
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
  CHECK(95, test_global_scope(&(String){12, 11, "func name()"}, &(String){62, 61, "Returncode name(void);\nReturncode name(void) {\n  return OK;\n}"}) )
  CHECK(98, test_global_scope(&(String){59, 58, "func name(var String self, user String text, copy Int num)"}, &(String){124, 123, "Returncode name(String* self, String* text, Int num);\nReturncode name(String* self, String* text, Int num) {\n  return OK;\n}"}) )
  CHECK(101, test_global_scope(&(String){47, 46, "func name()->(owner String text, copy Int num)"}, &(String){100, 99, "Returncode name(String** text, Int* num);\nReturncode name(String** text, Int* num) {\n  return OK;\n}"}) )
  CHECK(104, test_global_scope(&(String){47, 46, "func name(copy Char param)->(owner String out)"}, &(String){102, 101, "Returncode name(Char param, String** out);\nReturncode name(Char param, String** out) {\n  return OK;\n}"}) )
  CHECK(107, test_global_scope(&(String){33, 32, "func name(user Array{Int} array)"}, &(String){78, 77, "Returncode name(Array* array);\nReturncode name(Array* array) {\n  return OK;\n}"}) )
  CHECK(110, test_global_scope(&(String){47, 46, "func name(user Array{Array{Array{Int}}} array)"}, &(String){78, 77, "Returncode name(Array* array);\nReturncode name(Array* array) {\n  return OK;\n}"}) )
  CHECK(113, test_global_scope(&(String){24, 23, "func name()\n  var Int x"}, &(String){71, 70, "Returncode name(void);\nReturncode name(void) {\n  Int x;\n  return OK;\n}"}) )
  CHECK(116, test_global_scope(&(String){17, 16, "main\n  var Int x"}, &(String){53, 52, "USER_MAIN_HEADER {\n  Int x;\n  return OK;\n}\nMAIN_FUNC"}) )
  CHECK(119, test_global_scope_error(&(String){7, 6, "func(\n"}, &(String){37, 36, "expected space after \"func\", got \"(\""}) )
  CHECK(121, test_global_scope_error(&(String){11, 10, "func name\n"}, &(String){49, 48, "expected \"(\" after function name, got \"new-line\""}) )
  CHECK(124, test_global_scope_error(&(String){14, 13, "func name( )\n"}, &(String){25, 24, "expected access, got \" \""}) )
  CHECK(127, test_global_scope_error(&(String){17, 16, "func name(user)\n"}, &(String){37, 36, "expected space after access, got \")\""}) )
  CHECK(130, test_global_scope_error(&(String){22, 21, "func name(var String\n"}, &(String){42, 41, "expected space after type, got \"new-line\""}) )
  CHECK(133, test_global_scope_error(&(String){24, 23, "func name(error Int x)\n"}, &(String){23, 22, "illegal access \"error\""}) )
  CHECK(136, test_global_scope_error(&(String){38, 37, "func name(var String str,user Int x)\n"}, &(String){46, 45, "expected space or new-line after \",\", got \"u\""}) )
  CHECK(139, test_global_scope_error(&(String){16, 15, "func name()-()\n"}, &(String){23, 22, "expected \">(\" got \"()\""}) )
  CHECK(142, test_global_scope_error(&(String){12, 11, "func name()"}, &(String){40, 39, "expected block in a new line, got \"EOF\""}) )
  CHECK(145, test_global_scope_error(&(String){26, 25, "func name()\n    var Int x"}, &(String){42, 41, "indentation too big, expected \"2\" got \"4\""}) )
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
  CHECK(151, test_global_scope(&(String){42, 41, "struct Test\n  var Int x\n  user String str"}, &(String){67, 66, "typedef struct Test Test;\nstruct Test {\n  Int x;\n  String* str;\n};"}) )
  CHECK(154, test_global_scope(&(String){38, 37, "struct Test\n  var Int x\n  func name()"}, &(String){136, 135, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};\nReturncode Test_name(Test* self);\nReturncode Test_name(Test* self) {\n  return OK;\n}"}) )
  CHECK(157, test_global_scope(&(String){52, 51, "struct Test\n  var Int x\n  func name()\n    var Int x"}, &(String){145, 144, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};\nReturncode Test_name(Test* self);\nReturncode Test_name(Test* self) {\n  Int x;\n  return OK;\n}"}) )
  String* expected = &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"};
  CHECK(161, test_global_scope(&(String){36, 35, "struct Test\n  # comment\n  var Int x"}, expected) )
  CHECK(162, test_global_scope(&(String){43, 42, "struct Test\n  ## documemtation\n  var Int x"}, expected) )
  CHECK(164, test_global_scope(&(String){55, 54, "struct Test\n  {# multi \n line \n comment #}\n  var Int x"}, expected) )
  CHECK(167, test_global_scope(&(String){62, 61, "struct Test\n  {## multi \n line \n documemtation #}\n  var Int x"}, expected) )
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
  CHECK(173, test_global_scope(&(String){21, 20, "func name()\n  return"}, &(String){62, 61, "Returncode name(void);\nReturncode name(void) {\n  return OK;\n}"}) )
  CHECK(176, test_global_scope(&(String){20, 19, "func name()\n  raise"}, &(String){60, 59, "Returncode name(void);\nReturncode name(void) {\n  RAISE(1)\n}"}) )
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
  CHECK(182, test_code(&(String){16, 15, "user String str"}, &(String){13, 12, "String* str;"}) )
  /* test-code(user "var Int x(i + 5)", user "Int x;\n  x = i + 5;") */
  String* expected = &(String){7, 6, "Int x;"};
  CHECK(185, test_code(&(String){23, 22, "# comment\n\n  var Int x"}, expected) )
  CHECK(186, test_code(&(String){30, 29, "## documemtation\n\n  var Int x"}, expected) )
  CHECK(187, test_code(&(String){42, 41, "{# multi \n line \n comment #}\n\n  var Int x"}, expected) )
  CHECK(188, test_code(&(String){49, 48, "{## multi \n line \n documemtation #}\n\n  var Int x"}, expected) )
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
  CHECK(194, test_code(&(String){20, 19, "if i > 3\n    i -= 2"}, &(String){29, 28, "if (i > 3) {\n    i -= 2;\n  }"}) )
  CHECK(195, test_code(&(String){38, 37, "if i > 3\n    i -= 2\n  else\n    i += 1"}, &(String){54, 53, "if (i > 3) {\n    i -= 2;\n  }\n  else {\n    i += 1;\n  }"}) )
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(199, String_copy(expected, &(String){14, 13, "if (i > 3) {\n"}) )
  CHECK(200, String_concat(expected, &(String){13, 12, "    i -= 3;\n"}) )
  CHECK(201, String_concat(expected, &(String){5, 4, "  }\n"}) )
  CHECK(202, String_concat(expected, &(String){10, 9, "  else {\n"}) )
  CHECK(203, String_concat(expected, &(String){18, 17, "    if (i > 2) {\n"}) )
  CHECK(204, String_concat(expected, &(String){15, 14, "      i -= 2;\n"}) )
  CHECK(205, String_concat(expected, &(String){7, 6, "    }\n"}) )
  CHECK(206, String_concat(expected, &(String){12, 11, "    else {\n"}) )
  CHECK(207, String_concat(expected, &(String){20, 19, "      if (i > 1) {\n"}) )
  CHECK(208, String_concat(expected, &(String){17, 16, "        i -= 1;\n"}) )
  CHECK(209, String_concat(expected, &(String){9, 8, "      }\n"}) )
  CHECK(210, String_concat(expected, &(String){14, 13, "      else {\n"}) )
  CHECK(211, String_concat(expected, &(String){17, 16, "        i += 1;\n"}) )
  CHECK(212, String_concat(expected, &(String){9, 8, "      }\n"}) )
  CHECK(213, String_concat(expected, &(String){7, 6, "    }\n"}) )
  CHECK(214, String_concat(expected, &(String){4, 3, "  }"}) )
  CHECK(215, test_code(&(String){92, 91, "if i > 3\n    i -= 3\n  else-if i > 2\n    i -= 2\n  else-if i > 1\n    i -= 1\n  else\n    i += 1"}, expected) )
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
  CHECK(221, test_code(&(String){17, 16, "do\n    var Int x"}, &(String){30, 29, "while (true) {\n    Int x;\n  }"}) )
  CHECK(222, test_code(&(String){22, 21, "\n  \n    \n\n  var Int x"}, &(String){7, 6, "Int x;"}) )
  CHECK(223, test_code(&(String){19, 18, "do\n    while i > 3"}, &(String){44, 43, "while (true) {\n    if (!(i > 3)) break;\n  }"}) )
  CHECK(226, test_code(&(String){16, 15, "do\n    continue"}, &(String){33, 32, "while (true) {\n    continue;\n  }"}) )
  CHECK(227, test_code_error(&(String){4, 3, "do("}, &(String){38, 37, "expected new-line after \"do\", got \"(\""}) )
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
  CHECK(231, test_code(&(String){22, 21, "for n in 5\n    i += n"}, &(String){46, 45, "{int n; for(n=0; n<5; ++n) {\n    i += n;\n  }}"}) )
  CHECK(234, test_code(&(String){28, 27, "for n in i:i + 2\n    i += n"}, &(String){50, 49, "{int n; for(n=i; n<i + 2; ++n) {\n    i += n;\n  }}"}) )
  CHECK(237, test_code_error(&(String){5, 4, "for("}, &(String){36, 35, "expected space after \"for\", got \"(\""}) )
  CHECK(238, test_code_error(&(String){6, 5, "for n"}, &(String){48, 47, "expected space after index name, got \"new-line\""}) )
  CHECK(240, test_code_error(&(String){12, 11, "for n error"}, &(String){25, 24, "expected \"in \" got \"err\""}) )
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
