#ifndef MR_MAINFILE
#define MR_MAINFILE "tests/syntax-tree-tests.c"
#define DEPTH 4
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
  SyntaxTreeRoot* root = &(SyntaxTreeRoot){SyntaxTreeRoot__dtl, 0, NULL, NULL, NULL};
  root->_base._base._base._dtl = SyntaxTreeRoot__dtl;
  CHECK(7, SyntaxTreeRoot_parse(root, mock_argv) )
  CHECK(8, (root)->_base._base._base._dtl[0](root) )
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
  if ((0) < 0 || (0) >= (mock_output_file_text)->length) RAISE(16)
  TEST_ASSERT(16, ((mock_output_file_text)->values[0]) == '\n')
  CHECK(17, f_assert_string_slice(expected_output, mock_output_file_text, 1, mock_output_file_text->length - 2) )
  if ((mock_output_file_text->length - 1) < 0 || (mock_output_file_text->length - 1) >= (mock_output_file_text)->length) RAISE(22)
  TEST_ASSERT(22, ((mock_output_file_text)->values[mock_output_file_text->length - 1]) == '\n')
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
  CHECK(26, f_setup_test() )
  CHECK(27, set_mock_file_text(input_text) )
  mock_print_active = true;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(29, write_syntax_tree() );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(29)
  } while (false);
  _trace_stream = stdout;
  mock_print_active = false;
  String* expected_header = &(String){25, 24, "Code error in mock.3.mr["};
  CHECK(32, f_assert_string_slice(expected_header, mock_print_text, 0, expected_header->length) )
  CHECK(37, f_assert_string_slice(expected_error, mock_print_text, expected_header->length + 3, mock_print_text->length - expected_header->length - 4) )
  if ((mock_print_text->length - 1) < 0 || (mock_print_text->length - 1) >= (mock_print_text)->length) RAISE(42)
  TEST_ASSERT(42, ((mock_print_text)->values[mock_print_text->length - 1]) == '\n')
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
  CHECK(46, f_setup_test() )
  CHECK(47, set_mock_file_text(&(String){15, 14, "func mock()\n  "}) )
  CHECK(48, String_concat(mock_input_file_text, input_text) )
  CHECK(49, String_append(mock_input_file_text, '\n') )
  CHECK(50, write_syntax_tree() )
  String* expected_header = &(String){23, 22, "\nFunction(mock)() {\n  "};
  String* expected_footer = &(String){4, 3, "\n}\n"};
  CHECK(53, f_assert_string_slice(expected_header, mock_output_file_text, 0, expected_header->length) )
  CHECK(58, f_assert_string_slice(expected_output, mock_output_file_text, expected_header->length, mock_output_file_text->length - expected_header->length - expected_footer->length) )
  CHECK(64, f_assert_string_slice(expected_footer, mock_output_file_text, mock_output_file_text->length - expected_footer->length, expected_footer->length) )
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
  CHECK(72, test_global_scope(&(String){16, 15, "user String str"}, &(String){21, 20, "Access(1) String str"}) )
  CHECK(73, test_global_scope(&(String){15, 14, "\n  \n\nvar Int x"}, &(String){16, 15, "Access(3) Int x"}) )
  CHECK(74, test_global_scope_error(&(String){7, 6, "error "}, &(String){24, 23, "unknown keyword \"error\""}) )
  CHECK(75, test_global_scope_error(&(String){7, 6, "error\n"}, &(String){46, 45, "expected space after key-word, got \"new-line\""}) )
  CHECK(78, test_global_scope_error(&(String){14, 13, "  struct Test"}, &(String){42, 41, "indentation too big, expected \"0\" got \"2\""}) )
  CHECK(81, test_global_scope_error(&(String){10, 9, "var Int x"}, &(String){28, 27, "no new-line before file end"}) )
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
  CHECK(87, test_global_scope(&(String){12, 11, "struct Test"}, &(String){11, 10, "Type(Test)"}) )
  CHECK(88, test_global_scope(&(String){11, 10, "class Test"}, &(String){11, 10, "Type(Test)"}) )
  CHECK(89, test_global_scope(&(String){40, 39, "struct Test1\nclass Test2\n\n\nstruct Test3"}, &(String){38, 37, "Type(Test1)\n\nType(Test2)\n\nType(Test3)"}) )
  CHECK(92, test_global_scope_error(&(String){21, 20, "struct Test\n  error "}, &(String){24, 23, "unknown keyword \"error\""}) )
  CHECK(95, test_global_scope_error(&(String){21, 20, "struct Test\n  error\n"}, &(String){46, 45, "expected space after key-word, got \"new-line\""}) )
  CHECK(98, test_global_scope_error(&(String){12, 11, "struct Test"}, &(String){40, 39, "expected block in a new line, got \"EOF\""}) )
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
  CHECK(104, test_global_scope(&(String){12, 11, "func name()"}, &(String){21, 20, "Function(name)() {\n}"}) )
  CHECK(105, test_global_scope(&(String){59, 58, "func name(var String self, user String text, copy Int num)"}, &(String){84, 83, "Function(name)(Access(3) String self, Access(1) String text, Access(0) Int num) {\n}"}) )
  CHECK(108, test_global_scope(&(String){47, 46, "func name()->(owner String text, copy Int num)"}, &(String){65, 64, "Function(name)()->(Access(2) String text, Access(0) Int num) {\n}"}) )
  CHECK(111, test_global_scope(&(String){47, 46, "func name(copy Char param)->(owner String out)"}, &(String){65, 64, "Function(name)(Access(0) Char param)->(Access(2) String out) {\n}"}) )
  CHECK(114, test_global_scope(&(String){33, 32, "func name(user Array{Int} array)"}, &(String){47, 46, "Function(name)(Access(1) Array{Int} array) {\n}"}) )
  CHECK(117, test_global_scope(&(String){46, 45, "func name(user Array{List{Array{Int}}} array)"}, &(String){60, 59, "Function(name)(Access(1) Array{List{Array{Int}}} array) {\n}"}) )
  CHECK(120, test_global_scope_error(&(String){11, 10, "func name\n"}, &(String){49, 48, "expected \"(\" after function name, got \"new-line\""}) )
  CHECK(123, test_global_scope_error(&(String){14, 13, "func name( )\n"}, &(String){25, 24, "expected access, got \" \""}) )
  CHECK(126, test_global_scope_error(&(String){17, 16, "func name(user)\n"}, &(String){37, 36, "expected space after access, got \")\""}) )
  CHECK(129, test_global_scope_error(&(String){22, 21, "func name(var String\n"}, &(String){42, 41, "expected space after type, got \"new-line\""}) )
  CHECK(132, test_global_scope_error(&(String){24, 23, "func name(error Int x)\n"}, &(String){23, 22, "illegal access \"error\""}) )
  CHECK(135, test_global_scope_error(&(String){38, 37, "func name(var String str,user Int x)\n"}, &(String){46, 45, "expected space or new-line after \",\", got \"u\""}) )
  CHECK(138, test_global_scope_error(&(String){16, 15, "func name()-()\n"}, &(String){23, 22, "expected \">(\" got \"()\""}) )
  CHECK(141, test_global_scope_error(&(String){12, 11, "func name()"}, &(String){40, 39, "expected block in a new line, got \"EOF\""}) )
  CHECK(144, test_global_scope_error(&(String){26, 25, "func name()\n    var Int x"}, &(String){42, 41, "indentation too big, expected \"2\" got \"4\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* test test-members() */
/* test-global-scope( */
/* user "struct Test\n  func name()", */
/* user "Type(Test)\n  Function(name)() {\n}") */
/* test-global-scope( */
/* user "struct Test\n  var Int x\n  user String str", */
/* user "Type(Test)\n  Access(3) Int x\n  Access(1) String str") */


#if MR_STAGE == MR_DECLARATIONS
Returncode test_expression_in_func();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_expression_in_func = "test-expression-in-func";
#define MR_FUNC_NAME _func_name_test_expression_in_func
Returncode test_expression_in_func() {
  CHECK(159, test_code(&(String){7, 6, "x := 3"}, &(String){21, 20, "Variable(x) = Int(3)"}) )
  CHECK(160, test_code(&(String){16, 15, "user String str"}, &(String){21, 20, "Access(1) String str"}) )
  CHECK(161, test_code(&(String){17, 16, "var Int x(y + 5)"}, &(String){39, 38, "Access(3) Int x (Variable(y) + Int(5))"}) )
  CHECK(163, test_code(&(String){17, 16, "do\n    var Int x"}, &(String){29, 28, "do {\n    Access(3) Int x\n  }"}) )
  CHECK(164, test_code(&(String){22, 21, "\n  \n    \n\n  var Int x"}, &(String){16, 15, "Access(3) Int x"}) )
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
#include "syntax-tree/function.c"
#include "syntax-tree/loop.c"
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
#endif
#undef MR_INCLUDES
#endif

#endif
