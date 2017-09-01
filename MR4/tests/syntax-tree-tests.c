#ifndef MR_MAINFILE
#define MR_MAINFILE "tests/syntax-tree-tests.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file23_name = "tests/syntax-tree-tests.3.mr";
#endif
#define MR_FILE_NAME _mr_file23_name

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
  SyntaxTreeRoot* root = &(SyntaxTreeRoot){SyntaxTreeRoot__dtl, 0, NULL, NULL, NULL, NULL, NULL};
  root->_base._base._base._dtl = SyntaxTreeRoot__dtl;
  CHECK(7, SyntaxTreeRoot_parse(root, mock_argv) )
  CHECK(8, (root)->_base._base._base._dtl[1](root) )
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
  CHECK(12, f_setup_test() )
  CHECK(13, set_mock_file_text(input_text) )
  CHECK(14, String_append(mock_input_file_text, '\n') )
  CHECK(15, write_syntax_tree() )
  /* if mock-output-file-text[0] != '\n' */
  /*  print(user mock-output-file-text) */
  if ((0) < 0 || (0) >= (mock_output_file_text)->length) RAISE(18)
  TEST_ASSERT(18, ((mock_output_file_text)->values[0]) == '\n')
  CHECK(19, f_assert_string_slice(expected_output, mock_output_file_text, 1, mock_output_file_text->length - 2) )
  if ((mock_output_file_text->length - 1) < 0 || (mock_output_file_text->length - 1) >= (mock_output_file_text)->length) RAISE(24)
  TEST_ASSERT(24, ((mock_output_file_text)->values[mock_output_file_text->length - 1]) == '\n')
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
  CHECK(28, f_setup_test() )
  CHECK(29, set_mock_file_text(input_text) )
  mock_print_active = true;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(31, write_syntax_tree() );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(31)
  } while (false);
  _trace_stream = stdout;
  mock_print_active = false;
  String* expected_header = &(String){25, 24, "Code error in mock.3.mr["};
  CHECK(34, f_assert_string_slice(expected_header, mock_print_text, 0, expected_header->length) )
  CHECK(39, f_assert_string_slice(expected_error, mock_print_text, expected_header->length + 3, mock_print_text->length - expected_header->length - 4) )
  if ((mock_print_text->length - 1) < 0 || (mock_print_text->length - 1) >= (mock_print_text)->length) RAISE(44)
  TEST_ASSERT(44, ((mock_print_text)->values[mock_print_text->length - 1]) == '\n')
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
  CHECK(48, f_setup_test() )
  CHECK(49, set_mock_file_text(&(String){15, 14, "func mock()\n  "}) )
  CHECK(50, String_concat(mock_input_file_text, input_text) )
  CHECK(51, String_append(mock_input_file_text, '\n') )
  CHECK(52, write_syntax_tree() )
  String* expected_header = &(String){43, 42, "\nReturncode mock();\nReturncode mock() {\n  "};
  String* expected_footer = &(String){4, 3, "\n}\n"};
  CHECK(55, f_assert_string_slice(expected_header, mock_output_file_text, 0, expected_header->length) )
  CHECK(60, f_assert_string_slice(expected_output, mock_output_file_text, expected_header->length, mock_output_file_text->length - expected_header->length - expected_footer->length) )
  CHECK(66, f_assert_string_slice(expected_footer, mock_output_file_text, mock_output_file_text->length - expected_footer->length, expected_footer->length) )
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
  CHECK(74, f_setup_test() )
  CHECK(75, set_mock_file_text(&(String){15, 14, "func mock()\n  "}) )
  CHECK(76, String_concat(mock_input_file_text, input_text) )
  CHECK(77, String_append(mock_input_file_text, '\n') )
  mock_print_active = true;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(79, write_syntax_tree() );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(79)
  } while (false);
  _trace_stream = stdout;
  mock_print_active = false;
  String* expected_header = &(String){25, 24, "Code error in mock.3.mr["};
  CHECK(82, f_assert_string_slice(expected_header, mock_print_text, 0, expected_header->length) )
  CHECK(87, f_assert_string_slice(expected_error, mock_print_text, expected_header->length + 3, mock_print_text->length - expected_header->length - 4) )
  if ((mock_print_text->length - 1) < 0 || (mock_print_text->length - 1) >= (mock_print_text)->length) RAISE(92)
  TEST_ASSERT(92, ((mock_print_text)->values[mock_print_text->length - 1]) == '\n')
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
  CHECK(96, test_global_scope(&(String){16, 15, "user String str"}, &(String){13, 12, "String* str;"}) )
  String* expected = &(String){7, 6, "Int x;"};
  CHECK(98, test_global_scope(&(String){15, 14, "\n  \n\nvar Int x"}, expected) )
  CHECK(99, test_global_scope(&(String){21, 20, "# comment\n\nvar Int x"}, expected) )
  CHECK(100, test_global_scope(&(String){28, 27, "## documemtation\n\nvar Int x"}, expected) )
  CHECK(101, test_global_scope(&(String){40, 39, "{# multi \n line \n comment #}\n\nvar Int x"}, expected) )
  CHECK(103, test_global_scope(&(String){47, 46, "{## multi \n line \n documemtation #}\n\nvar Int x"}, expected) )
  CHECK(105, test_global_scope_error(&(String){7, 6, "error "}, &(String){24, 23, "unknown keyword \"error\""}) )
  CHECK(106, test_global_scope_error(&(String){7, 6, "main(\n"}, &(String){40, 39, "expected new-line after \"main\", got \"(\""}) )
  CHECK(108, test_global_scope_error(&(String){14, 13, "  struct Test"}, &(String){42, 41, "indentation too big, expected \"0\" got \"2\""}) )
  CHECK(111, test_global_scope_error(&(String){10, 9, "var Int x"}, &(String){28, 27, "no new-line before file end"}) )
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
  CHECK(117, test_global_scope(&(String){24, 23, "struct Test\n  var Int x"}, &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"}) )
  CHECK(120, test_global_scope(&(String){23, 22, "class Test\n  var Int x"}, &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"}) )
  CHECK(123, test_global_scope(&(String){76, 75, "struct Test1\n  var Int x\nclass Test2\n  var Int x\n\n\nstruct Test3\n  var Int x"}, &(String){165, 164, "typedef struct Test1 Test1;\ntypedef struct Test2 Test2;\ntypedef struct Test3 Test3;\nstruct Test1 {\n  Int x;\n};\nstruct Test2 {\n  Int x;\n};\nstruct Test3 {\n  Int x;\n};"}) )
  CHECK(126, test_global_scope_error(&(String){9, 8, "struct(\n"}, &(String){39, 38, "expected space after \"struct\", got \"(\""}) )
  CHECK(128, test_global_scope_error(&(String){8, 7, "class(\n"}, &(String){38, 37, "expected space after \"class\", got \"(\""}) )
  CHECK(130, test_global_scope_error(&(String){21, 20, "struct Test\n  error "}, &(String){24, 23, "unknown keyword \"error\""}) )
  CHECK(133, test_global_scope_error(&(String){12, 11, "struct Test"}, &(String){40, 39, "expected block in a new line, got \"EOF\""}) )
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
  CHECK(139, test_global_scope(&(String){12, 11, "func name()"}, &(String){41, 40, "Returncode name();\nReturncode name() {\n}"}) )
  CHECK(141, test_global_scope(&(String){59, 58, "func name(var String self, user String text, copy Int num)"}, &(String){111, 110, "Returncode name(String* self, String* text, Int num);\nReturncode name(String* self, String* text, Int num) {\n}"}) )
  CHECK(144, test_global_scope(&(String){47, 46, "func name()->(owner String text, copy Int num)"}, &(String){87, 86, "Returncode name(String** text, Int* num);\nReturncode name(String** text, Int* num) {\n}"}) )
  CHECK(147, test_global_scope(&(String){47, 46, "func name(copy Char param)->(owner String out)"}, &(String){89, 88, "Returncode name(Char param, String** out);\nReturncode name(Char param, String** out) {\n}"}) )
  CHECK(150, test_global_scope(&(String){33, 32, "func name(user Array{Int} array)"}, &(String){65, 64, "Returncode name(Array* array);\nReturncode name(Array* array) {\n}"}) )
  CHECK(153, test_global_scope(&(String){46, 45, "func name(user Array{List{Array{Int}}} array)"}, &(String){65, 64, "Returncode name(Array* array);\nReturncode name(Array* array) {\n}"}) )
  CHECK(156, test_global_scope(&(String){24, 23, "func name()\n  var Int x"}, &(String){50, 49, "Returncode name();\nReturncode name() {\n  Int x;\n}"}) )
  CHECK(159, test_global_scope(&(String){17, 16, "main\n  var Int x"}, &(String){40, 39, "USER_MAIN_HEADER {\n  Int x;\n}\nMAIN_FUNC"}) )
  CHECK(162, test_global_scope_error(&(String){7, 6, "func(\n"}, &(String){37, 36, "expected space after \"func\", got \"(\""}) )
  CHECK(164, test_global_scope_error(&(String){11, 10, "func name\n"}, &(String){49, 48, "expected \"(\" after function name, got \"new-line\""}) )
  CHECK(167, test_global_scope_error(&(String){14, 13, "func name( )\n"}, &(String){25, 24, "expected access, got \" \""}) )
  CHECK(170, test_global_scope_error(&(String){17, 16, "func name(user)\n"}, &(String){37, 36, "expected space after access, got \")\""}) )
  CHECK(173, test_global_scope_error(&(String){22, 21, "func name(var String\n"}, &(String){42, 41, "expected space after type, got \"new-line\""}) )
  CHECK(176, test_global_scope_error(&(String){24, 23, "func name(error Int x)\n"}, &(String){23, 22, "illegal access \"error\""}) )
  CHECK(179, test_global_scope_error(&(String){38, 37, "func name(var String str,user Int x)\n"}, &(String){46, 45, "expected space or new-line after \",\", got \"u\""}) )
  CHECK(182, test_global_scope_error(&(String){16, 15, "func name()-()\n"}, &(String){23, 22, "expected \">(\" got \"()\""}) )
  CHECK(185, test_global_scope_error(&(String){12, 11, "func name()"}, &(String){40, 39, "expected block in a new line, got \"EOF\""}) )
  CHECK(188, test_global_scope_error(&(String){26, 25, "func name()\n    var Int x"}, &(String){42, 41, "indentation too big, expected \"2\" got \"4\""}) )
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
  CHECK(194, test_global_scope(&(String){42, 41, "struct Test\n  var Int x\n  user String str"}, &(String){67, 66, "typedef struct Test Test;\nstruct Test {\n  Int x;\n  String* str;\n};"}) )
  CHECK(197, test_global_scope(&(String){38, 37, "struct Test\n  var Int x\n  func name()"}, &(String){103, 102, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};\nReturncode Test_name();\nReturncode Test_name() {\n}"}) )
  CHECK(200, test_global_scope(&(String){52, 51, "struct Test\n  var Int x\n  func name()\n    var Int x"}, &(String){112, 111, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};\nReturncode Test_name();\nReturncode Test_name() {\n  Int x;\n}"}) )
  String* expected = &(String){52, 51, "typedef struct Test Test;\nstruct Test {\n  Int x;\n};"};
  CHECK(204, test_global_scope(&(String){36, 35, "struct Test\n  # comment\n  var Int x"}, expected) )
  CHECK(205, test_global_scope(&(String){43, 42, "struct Test\n  ## documemtation\n  var Int x"}, expected) )
  CHECK(207, test_global_scope(&(String){55, 54, "struct Test\n  {# multi \n line \n comment #}\n  var Int x"}, expected) )
  CHECK(210, test_global_scope(&(String){62, 61, "struct Test\n  {## multi \n line \n documemtation #}\n  var Int x"}, expected) )
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
  CHECK(216, test_code(&(String){7, 6, "return"}, &(String){11, 10, "return OK;"}) )
  CHECK(217, test_code(&(String){6, 5, "raise"}, &(String){12, 11, "return ERR;"}) )
  CHECK(218, test_code(&(String){7, 6, "x := 3"}, &(String){7, 6, "x = 3;"}) )
  CHECK(219, test_code(&(String){16, 15, "user String str"}, &(String){13, 12, "String* str;"}) )
  CHECK(220, test_code(&(String){17, 16, "var Int x(y + 5)"}, &(String){20, 19, "Int x;\n  x = y + 5;"}) )
  String* expected = &(String){7, 6, "Int x;"};
  CHECK(222, test_code(&(String){23, 22, "# comment\n\n  var Int x"}, expected) )
  CHECK(223, test_code(&(String){30, 29, "## documemtation\n\n  var Int x"}, expected) )
  CHECK(224, test_code(&(String){42, 41, "{# multi \n line \n comment #}\n\n  var Int x"}, expected) )
  CHECK(225, test_code(&(String){49, 48, "{## multi \n line \n documemtation #}\n\n  var Int x"}, expected) )
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
  CHECK(231, test_code(&(String){20, 19, "if x > 3\n    x -= 2"}, &(String){29, 28, "if (x > 3) {\n    x -= 2;\n  }"}) )
  CHECK(232, test_code(&(String){38, 37, "if x > 3\n    x -= 2\n  else\n    x += 1"}, &(String){54, 53, "if (x > 3) {\n    x -= 2;\n  }\n  else {\n    x += 1;\n  }"}) )
  String* expected = &(String){1024, 0, (char[1024]){0}};
  CHECK(236, String_copy(expected, &(String){14, 13, "if (x > 3) {\n"}) )
  CHECK(237, String_concat(expected, &(String){13, 12, "    x -= 3;\n"}) )
  CHECK(238, String_concat(expected, &(String){5, 4, "  }\n"}) )
  CHECK(239, String_concat(expected, &(String){10, 9, "  else {\n"}) )
  CHECK(240, String_concat(expected, &(String){18, 17, "    if (x > 2) {\n"}) )
  CHECK(241, String_concat(expected, &(String){15, 14, "      x -= 2;\n"}) )
  CHECK(242, String_concat(expected, &(String){7, 6, "    }\n"}) )
  CHECK(243, String_concat(expected, &(String){12, 11, "    else {\n"}) )
  CHECK(244, String_concat(expected, &(String){20, 19, "      if (x > 1) {\n"}) )
  CHECK(245, String_concat(expected, &(String){17, 16, "        x -= 1;\n"}) )
  CHECK(246, String_concat(expected, &(String){9, 8, "      }\n"}) )
  CHECK(247, String_concat(expected, &(String){14, 13, "      else {\n"}) )
  CHECK(248, String_concat(expected, &(String){17, 16, "        x += 1;\n"}) )
  CHECK(249, String_concat(expected, &(String){9, 8, "      }\n"}) )
  CHECK(250, String_concat(expected, &(String){7, 6, "    }\n"}) )
  CHECK(251, String_concat(expected, &(String){4, 3, "  }"}) )
  CHECK(252, test_code(&(String){92, 91, "if x > 3\n    x -= 3\n  else-if x > 2\n    x -= 2\n  else-if x > 1\n    x -= 1\n  else\n    x += 1"}, expected) )
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
  CHECK(258, test_code(&(String){17, 16, "do\n    var Int x"}, &(String){30, 29, "while (true) {\n    Int x;\n  }"}) )
  CHECK(259, test_code(&(String){22, 21, "\n  \n    \n\n  var Int x"}, &(String){7, 6, "Int x;"}) )
  CHECK(260, test_code(&(String){19, 18, "do\n    while x > 3"}, &(String){44, 43, "while (true) {\n    if (!(x > 3)) break;\n  }"}) )
  CHECK(263, test_code(&(String){16, 15, "do\n    continue"}, &(String){33, 32, "while (true) {\n    continue;\n  }"}) )
  CHECK(264, test_code_error(&(String){4, 3, "do("}, &(String){38, 37, "expected new-line after \"do\", got \"(\""}) )
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
  CHECK(268, test_code(&(String){22, 21, "for n in 5\n    x += n"}, &(String){46, 45, "{int n; for(n=0; n<5; ++n) {\n    x += n;\n  }}"}) )
  CHECK(271, test_code(&(String){28, 27, "for n in x:x + 2\n    x += n"}, &(String){50, 49, "{int n; for(n=x; n<x + 2; ++n) {\n    x += n;\n  }}"}) )
  CHECK(274, test_code_error(&(String){5, 4, "for("}, &(String){36, 35, "expected space after \"for\", got \"(\""}) )
  CHECK(275, test_code_error(&(String){6, 5, "for n"}, &(String){48, 47, "expected space after index name, got \"new-line\""}) )
  CHECK(277, test_code_error(&(String){12, 11, "for n error"}, &(String){25, 24, "expected \"in \" got \"err\""}) )
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
#include "expression/variable.c"
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
