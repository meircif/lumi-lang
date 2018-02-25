#ifndef MR_MAINFILE
#define MR_MAINFILE "tests/syntax-tree-tests.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file31_name = "tests/syntax-tree-tests.3.mr";
#endif
#define MR_FILE_NAME _mr_file31_name

/* MR4 compiler tests - Syntax tree */

#if MR_STAGE == MR_DECLARATIONS
Returncode write_syntax_tree(Bool is_test);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_syntax_tree = "write-syntax-tree";
#define MR_FUNC_NAME _func_name_write_syntax_tree
Returncode write_syntax_tree(Bool is_test) {
  Array* mock_argv = &(Array){5, (String[5]){0}};
  _set_var_string_array(5, 256, mock_argv, (char[256 * 5]){0});
  if ((2) < 0 || (2) >= (mock_argv)->length) RAISE(5)
  CHECK(5, String_copy((&(((String*)((mock_argv)->values))[2])), &(String){10, 9, "mock.4.mr"}) )
  if (is_test) {
    if ((3) < 0 || (3) >= (mock_argv)->length) RAISE(7)
    CHECK(7, String_copy((&(((String*)((mock_argv)->values))[3])), &(String){11, 10, "empty.4.mr"}) )
    if ((4) < 0 || (4) >= (mock_argv)->length) RAISE(8)
    CHECK(8, String_copy((&(((String*)((mock_argv)->values))[4])), &(String){6, 5, "-test"}) )
  }
  else {
    mock_argv->length = 3;
  }
  glob->root->is_library = true;
  CHECK(12, SyntaxTreeRoot_parse(glob->root, mock_argv) )
  CHECK(13, (glob->root)->_base._base._base._dtl[2](glob->root) )
  CHECK(14, (glob->root)->_base._base._base._dtl[3](glob->root) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_global_scope(String* input_text, String* expected_output, Bool is_test);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_global_scope = "test-global-scope";
#define MR_FUNC_NAME _func_name_test_global_scope
Returncode test_global_scope(String* input_text, String* expected_output, Bool is_test) {
  CHECK(19, f_setup_test() )
  CHECK(20, set_mock_file_text(input_text) )
  CHECK(21, write_syntax_tree(is_test) )
  if ((0) < 0 || (0) >= (mock_output_file_text)->length) RAISE(22)
  if (((mock_output_file_text)->values[0]) != '\n') {
    CHECK(23, print(mock_output_file_text) )
  }
  if ((0) < 0 || (0) >= (mock_output_file_text)->length) RAISE(24)
  TEST_ASSERT(24, ((mock_output_file_text)->values[0]) == '\n')
  if ((mock_output_file_text->length - 1) < 0 || (mock_output_file_text->length - 1) >= (mock_output_file_text)->length) RAISE(25)
  TEST_ASSERT(25, ((mock_output_file_text)->values[mock_output_file_text->length - 1]) == '\n')
  CHECK(26, f_assert_string_slice(expected_output, mock_output_file_text, 1, mock_output_file_text->length - 2, true) )
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
  CHECK(35, f_setup_test() )
  CHECK(36, set_mock_file_text(input_text) )
  mock_print_active = true;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(38, write_syntax_tree(false) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(38)
  } while (false);
  _trace_stream = stdout;
  mock_print_active = false;
  String* expected_header = &(String){25, 24, "Code error in mock.4.mr["};
  CHECK(41, f_assert_string_slice(expected_header, mock_print_text, 0, expected_header->length, false) )
  if ((mock_print_text->length - 1) < 0 || (mock_print_text->length - 1) >= (mock_print_text)->length) RAISE(47)
  TEST_ASSERT(47, ((mock_print_text)->values[mock_print_text->length - 1]) == '\n')
  CHECK(48, f_assert_string_slice(expected_error, mock_print_text, expected_header->length + 3, mock_print_text->length - expected_header->length - 4, true) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_illegal_usage();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_illegal_usage = "test-illegal-usage";
#define MR_FUNC_NAME _func_name_test_illegal_usage
Returncode test_illegal_usage() {
  CHECK(57, f_setup_test() )
  Array* mock_argv = &(Array){2, (String[2]){0}};
  _set_var_string_array(2, 4, mock_argv, (char[4 * 2]){0});
  mock_print_active = true;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(60, SyntaxTreeRoot_parse(glob->root, mock_argv) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(60)
  } while (false);
  _trace_stream = stdout;
  mock_print_active = false;
  CHECK(62, f_assert_string_slice(&(String){58, 57, "usage: mr-4compiler OUTPUT-C-FILE-NAME INPUT-MR3-FILES..."}, mock_print_text, 0, mock_print_text->length, false) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_no_run_func(Bool testing, String* expected_error);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_no_run_func = "test-no-run-func";
#define MR_FUNC_NAME _func_name_test_no_run_func
Returncode test_no_run_func(Bool testing, String* expected_error) {
  CHECK(71, f_setup_test() )
  glob->root->is_library = false;
  glob->root->testing = testing;
  mock_print_active = true;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(75, (glob->root)->_base._base._base._dtl[2](glob->root) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(75)
  } while (false);
  _trace_stream = stdout;
  mock_print_active = false;
  CHECK(77, f_assert_string_slice(expected_error, mock_print_text, 0, mock_print_text->length, false) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode test_no_main();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_no_main = "test-no-main";
#define MR_FUNC_NAME _func_name_test_no_main
Returncode test_no_main() {
  CHECK(85, test_no_run_func(false, &(String){37, 36, "General code error: no main function"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode test_no_test_func();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_no_test_func = "test-no-test-func";
#define MR_FUNC_NAME _func_name_test_no_test_func
Returncode test_no_test_func() {
  CHECK(89, test_no_run_func(true, &(String){38, 37, "General code error: no test functions"}) )
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
  CHECK(94, test_new_file(&(String){18, 17, "syntax-tree-tests"}, &(String){13, 12, "test-general"}) )
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
  CHECK(98, test_from_file(&(String){12, 11, "test-struct"}) )
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
  CHECK(102, test_from_file(&(String){11, 10, "test-class"}) )
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
  CHECK(106, test_from_file(&(String){14, 13, "test-function"}) )
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
  CHECK(110, test_from_file(&(String){13, 12, "test-members"}) )
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
  CHECK(114, test_from_file(&(String){12, 11, "test-return"}) )
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
  CHECK(118, test_from_file(&(String){20, 19, "test-code-variables"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_initialize();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_initialize = "test-initialize";
#define MR_FUNC_NAME _func_name_test_initialize
Returncode test_initialize() {
  CHECK(122, test_from_file(&(String){16, 15, "test-initialize"}) )
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
  CHECK(126, test_from_file(&(String){13, 12, "test-comment"}) )
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
  CHECK(130, test_from_file(&(String){13, 12, "test-if-else"}) )
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
  CHECK(134, test_from_file(&(String){13, 12, "test-do-loop"}) )
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
  CHECK(138, test_from_file(&(String){14, 13, "test-for-loop"}) )
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
  CHECK(142, test_from_file(&(String){13, 12, "test-testing"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_native();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_native = "test-native";
#define MR_FUNC_NAME _func_name_test_native
Returncode test_native() {
  CHECK(146, test_from_file(&(String){12, 11, "test-native"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_parameter_type();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_parameter_type = "test-parameter-type";
#define MR_FUNC_NAME _func_name_test_parameter_type
Returncode test_parameter_type() {
  CHECK(150, test_from_file(&(String){20, 19, "test-parameter-type"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_parameter_inheritance();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_parameter_inheritance = "test-parameter-inheritance";
#define MR_FUNC_NAME _func_name_test_parameter_inheritance
Returncode test_parameter_inheritance() {
  CHECK(154, test_from_file(&(String){27, 26, "test-parameter-inheritance"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_error_handling();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_error_handling = "test-error-handling";
#define MR_FUNC_NAME _func_name_test_error_handling
Returncode test_error_handling() {
  CHECK(158, test_from_file(&(String){20, 19, "test-error-handling"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_for_each();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_for_each = "test-for-each";
#define MR_FUNC_NAME _func_name_test_for_each
Returncode test_for_each() {
  CHECK(162, test_from_file(&(String){14, 13, "test-for-each"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_complex_fields();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_complex_fields = "test-complex-fields";
#define MR_FUNC_NAME _func_name_test_complex_fields
Returncode test_complex_fields() {
  CHECK(166, test_from_file(&(String){20, 19, "test-complex-fields"}) )
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
#include "global/type-instance.c"
#include "expression/base-type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/initialize.c"
#include "expression/slice.c"
#include "expression/symbol.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "statement/error.c"
#include "statement/for.c"
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
#include "statement/type.c"
#include "statement/variable.c"
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
