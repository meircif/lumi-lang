#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "tests/expression-tests.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file31_name = "tests/expression-tests.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file31_name

/* TL4 compiler tests - Expression */

#if LUMI_STAGE == LUMI_DECLARATIONS
extern Bool not_first_code_test;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Bool not_first_code_test = false;
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Bool code_header_valid;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Bool code_header_valid = false;
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_code_setup(String* input_text);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_code_setup = "test-code-setup";
#define LUMI_FUNC_NAME _func_name_test_code_setup
Returncode test_code_setup(String* input_text) {
  CHECK(8, f_setup_test() )
  CHECK(9, set_mock_file_text(&(String){1, 0, ""}, NULL) )
  File* code_header = NULL;
  String* filename = &(String){256, 0, (char[256]){0}};
  CHECK(12, set_test_file_name(filename, &(String){12, 11, "code-header"}, &(String){6, 5, ".4.lm"}) )
  CHECK(13, file_open_read(filename, &(code_header)) )
  while (true) {
    Char ch = '\0';
    CHECK(16, File_getc(code_header, &(ch)) )
    if (!(ch != EOF)) break;
    CHECK(18, String_append(mock_input_file_text, ch) )
  }
  mock_input_line_reset_index = mock_input_file_text->length;
  CHECK(20, String_concat(mock_input_file_text, input_text) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_code(String* input_text, String* expected_output);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_code = "test-code";
#define LUMI_FUNC_NAME _func_name_test_code
Returncode test_code(String* input_text, String* expected_output) {
  if (not_first_code_test &&  ! code_header_valid) {
    return OK;
  }
  Bool was_first = !not_first_code_test;
  not_first_code_test = true;
  CHECK(28, test_code_setup(input_text) )
  CHECK(29, write_syntax_tree(false) )
  String* expected_header = &(String){16384, 0, (char[16384]){0}};
  File* code_header = NULL;
  String* filename = &(String){256, 0, (char[256]){0}};
  CHECK(33, set_test_file_name(filename, &(String){12, 11, "code-header"}, &(String){12, 11, ".expected.c"}) )
  CHECK(34, file_open_read(filename, &(code_header)) )
  while (true) {
    Char ch = '\0';
    CHECK(37, File_getc(code_header, &(ch)) )
    if (!(ch != EOF)) break;
    CHECK(39, String_append(expected_header, ch) )
  }
  
  CHECK(41, f_assert_string_slice(expected_header, mock_output_file_text, 0, expected_header->length, false) )
  if (was_first) {
    CHECK(48, set_test_file_name(filename, &(String){12, 11, "code-header"}, &(String){10, 9, ".actual.c"}) )
    CHECK(49, file_open_write(filename, &(code_header)) )
    if (tests_passed) {
      {int n; for (n = (0); n < (expected_header->length); ++n) {
        if ((n) < 0 || (n) >= (mock_output_file_text)->length) RAISE(52)
        CHECK(52, File_putc(code_header, ((mock_output_file_text)->values[n])) )
      }}
    }
    else {
      {int n; for (n = (0); n < (mock_output_file_text->length); ++n) {
        if ((n) < 0 || (n) >= (mock_output_file_text)->length) RAISE(55)
        CHECK(55, File_putc(code_header, ((mock_output_file_text)->values[n])) )
      }}
    }
    CHECK(56, File_close(code_header) )
    code_header_valid = tests_passed;
    if (!tests_passed) {
      return OK;
    }
  }
  
  Int footer_start = 0;
  if ((expected_header->length) < 0 || (mock_output_file_text->length - expected_header->length) < 0 || (expected_header->length) + (mock_output_file_text->length - expected_header->length) > (mock_output_file_text)->length) RAISE(62)
  String* mock_output_no_header = (&(String){mock_output_file_text->length - expected_header->length, mock_output_file_text->length - expected_header->length, (mock_output_file_text)->values + (expected_header->length)});
  CHECK(63, String_find(mock_output_no_header, &(String){18, 17, "\nLUMI_cleanup:\n  "}, &(footer_start)) )
  if (footer_start >= mock_output_no_header->length) {
    CHECK(65, Sys_print(sys, mock_output_no_header) )
    code_header_valid = false;
    RAISE(67)
  }
  CHECK(68, f_assert_string_slice(expected_output, mock_output_no_header, 0, footer_start, true) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_code_error(String* input_text, String* expected_error);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_code_error = "test-code-error";
#define LUMI_FUNC_NAME _func_name_test_code_error
Returncode test_code_error(String* input_text, String* expected_error) {
  if (not_first_code_test &&  ! code_header_valid) {
    return OK;
  }
  CHECK(79, test_code_setup(input_text) )
  mock_print_active = true;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(81, write_syntax_tree(false) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(81)
  } while (false);
  _trace_stream = stdout;
  mock_print_active = false;
  String* expected_header = &(String){25, 24, "Code error in mock.4.lm["};
  CHECK(84, f_assert_string_slice(expected_header, mock_print_text, 0, expected_header->length, false) )
  if ((mock_print_text->length - 1) < 0 || (mock_print_text->length - 1) >= (mock_print_text)->length) RAISE(90)
  TEST_ASSERT(90, ((mock_print_text)->values[mock_print_text->length - 1]) == '\n')
  CHECK(91, f_assert_string_slice(expected_error, mock_print_text, expected_header->length + 3, mock_print_text->length - expected_header->length - 4, true) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_int_expression();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_int_expression = "test-int-expression";
#define LUMI_FUNC_NAME _func_name_test_int_expression
Returncode test_int_expression() {
  CHECK(100, test_new_file(&(String){17, 16, "expression-tests"}, &(String){20, 19, "test-int-expression"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_char_expression();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_char_expression = "test-char-expression";
#define LUMI_FUNC_NAME _func_name_test_char_expression
Returncode test_char_expression() {
  CHECK(104, test_from_file(&(String){21, 20, "test-char-expression"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_string_expression();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_string_expression = "test-string-expression";
#define LUMI_FUNC_NAME _func_name_test_string_expression
Returncode test_string_expression() {
  CHECK(108, test_from_file(&(String){23, 22, "test-string-expression"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_empty_expression();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_empty_expression = "test-empty-expression";
#define LUMI_FUNC_NAME _func_name_test_empty_expression
Returncode test_empty_expression() {
  CHECK(112, test_from_file(&(String){22, 21, "test-empty-expression"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_member_expression();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_member_expression = "test-member-expression";
#define LUMI_FUNC_NAME _func_name_test_member_expression
Returncode test_member_expression() {
  CHECK(116, test_from_file(&(String){23, 22, "test-member-expression"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_slice_expression();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_slice_expression = "test-slice-expression";
#define LUMI_FUNC_NAME _func_name_test_slice_expression
Returncode test_slice_expression() {
  CHECK(120, test_from_file(&(String){22, 21, "test-slice-expression"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_call_expression();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_call_expression = "test-call-expression";
#define LUMI_FUNC_NAME _func_name_test_call_expression
Returncode test_call_expression() {
  CHECK(124, test_from_file(&(String){21, 20, "test-call-expression"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_type_expression();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_type_expression = "test-type-expression";
#define LUMI_FUNC_NAME _func_name_test_type_expression
Returncode test_type_expression() {
  CHECK(128, test_from_file(&(String){21, 20, "test-type-expression"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_base_expression();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_base_expression = "test-base-expression";
#define LUMI_FUNC_NAME _func_name_test_base_expression
Returncode test_base_expression() {
  CHECK(132, test_from_file(&(String){21, 20, "test-base-expression"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_block_expression();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_block_expression = "test-block-expression";
#define LUMI_FUNC_NAME _func_name_test_block_expression
Returncode test_block_expression() {
  CHECK(136, test_from_file(&(String){22, 21, "test-block-expression"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_unary_expression();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_unary_expression = "test-unary-expression";
#define LUMI_FUNC_NAME _func_name_test_unary_expression
Returncode test_unary_expression() {
  CHECK(140, test_from_file(&(String){22, 21, "test-unary-expression"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_binary_expression();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_binary_expression = "test-binary-expression";
#define LUMI_FUNC_NAME _func_name_test_binary_expression
Returncode test_binary_expression() {
  CHECK(144, test_from_file(&(String){23, 22, "test-binary-expression"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_question_expression();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_question_expression = "test-question-expression";
#define LUMI_FUNC_NAME _func_name_test_question_expression
Returncode test_question_expression() {
  CHECK(148, test_from_file(&(String){25, 24, "test-question-expression"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_dynamic();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_dynamic = "test-dynamic";
#define LUMI_FUNC_NAME _func_name_test_dynamic
Returncode test_dynamic() {
  CHECK(152, test_from_file(&(String){13, 12, "test-dynamic"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_function_object();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_function_object = "test-function-object";
#define LUMI_FUNC_NAME _func_name_test_function_object
Returncode test_function_object() {
  CHECK(156, test_from_file(&(String){21, 20, "test-function-object"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_builtin();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_builtin = "test-builtin";
#define LUMI_FUNC_NAME _func_name_test_builtin
Returncode test_builtin() {
  CHECK(160, test_from_file(&(String){13, 12, "test-builtin"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#undef LUMI_FILE_NAME

#ifndef LUMI_INCLUDES
#define LUMI_INCLUDES
#include "tl4-compiler.c"
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
#include "tests/global-tests.c"
#include "tests/syntax-tree-tests.c"
#if LUMI_STAGE == LUMI_TYPES(1)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(2)
#elif LUMI_STAGE == LUMI_TYPES(2)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(3)
#elif LUMI_STAGE == LUMI_TYPES(3)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(4)
#elif LUMI_STAGE == LUMI_TYPES(4)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(5)
#endif
#undef LUMI_INCLUDES
#endif

#endif
