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
Returncode test_code(String* input_text, String* expected_output);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_code = "test-code";
#define MR_FUNC_NAME _func_name_test_code
Returncode test_code(String* input_text, String* expected_output) {
  CHECK(26, f_setup_test() )
  CHECK(27, set_mock_file_text(&(String){15, 14, "func mock()\n  "}) )
  CHECK(28, String_concat(mock_input_file_text, input_text) )
  CHECK(29, String_append(mock_input_file_text, '\n') )
  CHECK(30, write_syntax_tree() )
  String* expected_header = &(String){23, 22, "\nFunction(mock)() {\n  "};
  String* expected_futter = &(String){4, 3, "\n}\n"};
  CHECK(33, f_assert_string_slice(expected_header, mock_output_file_text, 0, expected_header->length) )
  CHECK(38, f_assert_string_slice(expected_output, mock_output_file_text, expected_header->length, mock_output_file_text->length - expected_header->length - expected_futter->length) )
  CHECK(44, f_assert_string_slice(expected_futter, mock_output_file_text, mock_output_file_text->length - expected_futter->length, expected_futter->length) )
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
  CHECK(52, test_global_scope(&(String){12, 11, "struct Test"}, &(String){11, 10, "Type(Test)"}) )
  CHECK(53, test_global_scope(&(String){11, 10, "class Test"}, &(String){11, 10, "Type(Test)"}) )
  CHECK(54, test_global_scope(&(String){40, 39, "struct Test1\nclass Test2\n\n\nstruct Test3"}, &(String){38, 37, "Type(Test1)\n\nType(Test2)\n\nType(Test3)"}) )
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
  CHECK(60, test_global_scope(&(String){12, 11, "func name()"}, &(String){21, 20, "Function(name)() {\n}"}) )
  CHECK(61, test_global_scope(&(String){59, 58, "func name(var String self, user String text, copy Int num)"}, &(String){84, 83, "Function(name)(Access(3) String self, Access(1) String text, Access(0) Int num) {\n}"}) )
  CHECK(64, test_global_scope(&(String){47, 46, "func name()->(owner String text, copy Int num)"}, &(String){65, 64, "Function(name)()->(Access(2) String text, Access(0) Int num) {\n}"}) )
  CHECK(67, test_global_scope(&(String){47, 46, "func name(copy Char param)->(owner String out)"}, &(String){65, 64, "Function(name)(Access(0) Char param)->(Access(2) String out) {\n}"}) )
  CHECK(70, test_global_scope(&(String){33, 32, "func name(user Array{Int} array)"}, &(String){47, 46, "Function(name)(Access(1) Array{Int} array) {\n}"}) )
  CHECK(73, test_global_scope(&(String){46, 45, "func name(user Array{List{Array{Int}}} array)"}, &(String){60, 59, "Function(name)(Access(1) Array{List{Array{Int}}} array) {\n}"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_expression_in_func();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_expression_in_func = "test-expression-in-func";
#define MR_FUNC_NAME _func_name_test_expression_in_func
Returncode test_expression_in_func() {
  CHECK(79, test_code(&(String){7, 6, "x := 3"}, &(String){21, 20, "Variable(x) = Int(3)"}) )
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
