#ifndef MR_MAINFILE
#define MR_MAINFILE "tests/syntax-tree-tests.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file32_name = "tests/syntax-tree-tests.3.mr";
#endif
#define MR_FILE_NAME _mr_file32_name

/* MR4 compiler tests - Syntax tree */

#if MR_STAGE == MR_DECLARATIONS
Returncode write_syntax_tree(Bool is_test);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_syntax_tree = "write-syntax-tree";
#define MR_FUNC_NAME _func_name_write_syntax_tree
Returncode write_syntax_tree(Bool is_test) {
  Array* mock_argv = &(Array){6, (String[6]){0}};
  _set_var_string_array(6, 256, mock_argv, (char[256 * 6]){0});
  if ((0) < 0 || (0) >= (mock_argv)->length) RAISE(5)
  CHECK(5, String_copy((&(((String*)((mock_argv)->values))[0])), &(String){13, 12, "mr4-compiler"}) )
  if ((1) < 0 || (1) >= (mock_argv)->length) RAISE(6)
  CHECK(6, String_copy((&(((String*)((mock_argv)->values))[1])), &(String){7, 6, "mock.c"}) )
  if ((2) < 0 || (2) >= (mock_argv)->length) RAISE(7)
  CHECK(7, String_copy((&(((String*)((mock_argv)->values))[2])), &(String){10, 9, "mock.4.mr"}) )
  if (is_test) {
    if ((3) < 0 || (3) >= (mock_argv)->length) RAISE(9)
    CHECK(9, String_copy((&(((String*)((mock_argv)->values))[3])), &(String){3, 2, "-t"}) )
    if ((4) < 0 || (4) >= (mock_argv)->length) RAISE(10)
    CHECK(10, String_copy((&(((String*)((mock_argv)->values))[4])), &(String){3, 2, "ut"}) )
    if ((5) < 0 || (5) >= (mock_argv)->length) RAISE(11)
    CHECK(11, String_copy((&(((String*)((mock_argv)->values))[5])), &(String){12, 11, "second.4.mr"}) )
  }
  else {
    mock_argv->length = 3;
  }
  glob->root->is_library = true;
  CHECK(15, SyntaxTreeRoot_parse(glob->root, mock_argv) )
  CHECK(16, (glob->root)->_base._base._base._base._dtl[2](glob->root) )
  CHECK(17, (glob->root)->_base._base._base._base._dtl[4](glob->root) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_global_scope(String* input_text, String* second_file_input_text, String* expected_output, Bool is_test);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_global_scope = "test-global-scope";
#define MR_FUNC_NAME _func_name_test_global_scope
Returncode test_global_scope(String* input_text, String* second_file_input_text, String* expected_output, Bool is_test) {
  CHECK(25, f_setup_test() )
  CHECK(26, set_mock_file_text(input_text, second_file_input_text) )
  CHECK(27, write_syntax_tree(is_test) )
  if ((0) < 0 || (0) >= (mock_output_file_text)->length) RAISE(28)
  if (((mock_output_file_text)->values[0]) != '\n') {
    CHECK(29, print(mock_output_file_text) )
  }
  if ((0) < 0 || (0) >= (mock_output_file_text)->length) RAISE(30)
  TEST_ASSERT(30, ((mock_output_file_text)->values[0]) == '\n')
  if ((mock_output_file_text->length - 1) < 0 || (mock_output_file_text->length - 1) >= (mock_output_file_text)->length) RAISE(31)
  TEST_ASSERT(31, ((mock_output_file_text)->values[mock_output_file_text->length - 1]) == '\n')
  CHECK(32, f_assert_string_slice(expected_output, mock_output_file_text, 1, mock_output_file_text->length - 2, true) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_global_scope_error(String* input_text, String* second_file_input_text, String* expected_error, Bool is_test);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_global_scope_error = "test-global-scope-error";
#define MR_FUNC_NAME _func_name_test_global_scope_error
Returncode test_global_scope_error(String* input_text, String* second_file_input_text, String* expected_error, Bool is_test) {
  CHECK(45, f_setup_test() )
  CHECK(46, set_mock_file_text(input_text, second_file_input_text) )
  mock_print_active = true;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(48, write_syntax_tree(is_test) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(48)
  } while (false);
  _trace_stream = stdout;
  mock_print_active = false;
  String* expected_header = NULL;
  if (is_test) {
    expected_header = &(String){27, 26, "Code error in second.4.mr["};
  }
  else {
    expected_header = &(String){25, 24, "Code error in mock.4.mr["};
  }
  CHECK(55, f_assert_string_slice(expected_header, mock_print_text, 0, expected_header->length, false) )
  if ((mock_print_text->length - 1) < 0 || (mock_print_text->length - 1) >= (mock_print_text)->length) RAISE(61)
  TEST_ASSERT(61, ((mock_print_text)->values[mock_print_text->length - 1]) == '\n')
  CHECK(62, f_assert_string_slice(expected_error, mock_print_text, expected_header->length + 3, mock_print_text->length - expected_header->length - 4, true) )
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
  CHECK(71, f_setup_test() )
  Array* mock_argv = &(Array){2, (String[2]){0}};
  _set_var_string_array(2, 4, mock_argv, (char[4 * 2]){0});
  mock_print_active = true;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(74, SyntaxTreeRoot_parse(glob->root, mock_argv) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(74)
  } while (false);
  _trace_stream = stdout;
  mock_print_active = false;
  CHECK(76, f_assert_string_slice(&(String){78, 77, "usage: mr-4compiler [-t TESTED-MODULE] OUTPUT-C-FILE-NAME INPUT-MR4-FILES...\n"}, mock_print_text, 0, mock_print_text->length, false) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_analyze_error(String* expected_error);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_analyze_error = "test-analyze-error";
#define MR_FUNC_NAME _func_name_test_analyze_error
Returncode test_analyze_error(String* expected_error) {
  mock_print_active = true;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(86, (glob->root)->_base._base._base._base._dtl[2](glob->root) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(86)
  } while (false);
  _trace_stream = stdout;
  mock_print_active = false;
  CHECK(88, f_assert_string_slice(expected_error, mock_print_text, 0, mock_print_text->length, false) )
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
  CHECK(97, f_setup_test() )
  glob->root->is_library = false;
  if (testing) {
    CHECK(100, string_new_copy(&(String){3, 2, "ut"}, &(glob->tested_module)) )
  }
  CHECK(101, test_analyze_error(expected_error) )
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
  CHECK(104, test_no_run_func(false, &(String){38, 37, "General code error: no main function\n"}) )
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
  CHECK(108, test_no_run_func(true, &(String){39, 38, "General code error: no test functions\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_cover_error(Bool has_module, String* expected_error);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_cover_error = "test-cover-error";
#define MR_FUNC_NAME _func_name_test_cover_error
Returncode test_cover_error(Bool has_module, String* expected_error) {
  CHECK(113, f_setup_test() )
  glob->root->is_library = true;
  CHECK(115, string_new_copy(&(String){6, 5, "error"}, &(glob->tested_module)) )
  CHECK(116, NameMap_add(glob->test_functions, NULL, NULL) )
  ModuleMembers* dummy_module = &(ModuleMembers){NULL, NULL, NULL, NULL, NULL};
  if (has_module) {
    CHECK(119, NameMap_add(glob->module_map, glob->tested_module, dummy_module) )
  }
  glob->root->line_counts = _new_array(1, sizeof(LineCount));
  if (glob->root->line_counts == NULL) RAISE(120)
  CHECK(121, test_analyze_error(expected_error) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode test_unknown_test_module();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_unknown_test_module = "test-unknown-test-module";
#define MR_FUNC_NAME _func_name_test_unknown_test_module
Returncode test_unknown_test_module() {
  CHECK(124, test_cover_error(false, &(String){51, 50, "General code error: unknown tested module \"error\"\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode test_no_code_to_test();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_no_code_to_test = "test-no-code-to-test";
#define MR_FUNC_NAME _func_name_test_no_code_to_test
Returncode test_no_code_to_test() {
  CHECK(129, test_cover_error(true, &(String){58, 57, "General code error: no code to test under module \"error\"\n"}) )
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
  CHECK(135, test_new_file(&(String){18, 17, "syntax-tree-tests"}, &(String){13, 12, "test-general"}) )
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
  CHECK(139, test_from_file(&(String){12, 11, "test-struct"}) )
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
  CHECK(143, test_from_file(&(String){11, 10, "test-class"}) )
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
  CHECK(147, test_from_file(&(String){14, 13, "test-function"}) )
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
  CHECK(151, test_from_file(&(String){13, 12, "test-members"}) )
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
  CHECK(155, test_from_file(&(String){12, 11, "test-return"}) )
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
  CHECK(159, test_from_file(&(String){20, 19, "test-code-variables"}) )
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
  CHECK(163, test_from_file(&(String){16, 15, "test-initialize"}) )
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
  CHECK(167, test_from_file(&(String){13, 12, "test-comment"}) )
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
  CHECK(171, test_from_file(&(String){13, 12, "test-if-else"}) )
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
  CHECK(175, test_from_file(&(String){13, 12, "test-do-loop"}) )
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
  CHECK(179, test_from_file(&(String){14, 13, "test-for-loop"}) )
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
  CHECK(183, test_from_file(&(String){13, 12, "test-testing"}) )
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
  CHECK(187, test_from_file(&(String){12, 11, "test-native"}) )
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
  CHECK(191, test_from_file(&(String){20, 19, "test-parameter-type"}) )
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
  CHECK(195, test_from_file(&(String){27, 26, "test-parameter-inheritance"}) )
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
  CHECK(199, test_from_file(&(String){20, 19, "test-error-handling"}) )
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
  CHECK(203, test_from_file(&(String){14, 13, "test-for-each"}) )
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
  CHECK(207, test_from_file(&(String){20, 19, "test-complex-fields"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_enum();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_enum = "test-enum";
#define MR_FUNC_NAME _func_name_test_enum
Returncode test_enum() {
  CHECK(211, test_from_file(&(String){10, 9, "test-enum"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_constant();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_constant = "test-constant";
#define MR_FUNC_NAME _func_name_test_constant
Returncode test_constant() {
  CHECK(215, test_from_file(&(String){14, 13, "test-constant"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_module();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_module = "test-module";
#define MR_FUNC_NAME _func_name_test_module
Returncode test_module() {
  CHECK(219, test_from_file(&(String){12, 11, "test-module"}) )
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
#include "statement/enum.c"
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
