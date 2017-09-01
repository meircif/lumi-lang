#ifndef MR_MAINFILE
#define MR_MAINFILE "tests/global-tests.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file22_name = "tests/global-tests.3.mr";
#endif
#define MR_FILE_NAME _mr_file22_name

/* MR4 compiler tests - Global */

/* IO mocks */

#if MR_STAGE == MR_DECLARATIONS
extern String* mock_print_text;
#elif MR_STAGE == MR_FUNCTIONS
String* mock_print_text = &(String){1024, 0, (char[1024]){0}};
#endif
#if MR_STAGE == MR_DECLARATIONS
extern String* mock_input_file_text;
#elif MR_STAGE == MR_FUNCTIONS
String* mock_input_file_text = &(String){1024, 0, (char[1024]){0}};
#endif
#if MR_STAGE == MR_DECLARATIONS
extern String* mock_output_file_text;
#elif MR_STAGE == MR_FUNCTIONS
String* mock_output_file_text = &(String){1024, 0, (char[1024]){0}};
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Int mock_input_file_index;
#elif MR_STAGE == MR_FUNCTIONS
Int mock_input_file_index = 0;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Bool mock_print_active;
#elif MR_STAGE == MR_FUNCTIONS
Bool mock_print_active = false;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Char mock_output_file_last;
#elif MR_STAGE == MR_FUNCTIONS
Char mock_output_file_last = '\0';
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode print(String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_print = "print";
#define MR_FUNC_NAME _func_name_print
Returncode print(String* text) {
  if (mock_print_active) {
    CHECK(14, String_concat(mock_print_text, text) )
  }
  else {
    CHECK(16, Sys_print_raw(sys, text) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode set_mock_file_text(String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_set_mock_file_text = "set-mock-file-text";
#define MR_FUNC_NAME _func_name_set_mock_file_text
Returncode set_mock_file_text(String* text) {
  CHECK(19, String_copy(mock_input_file_text, text) )
  mock_input_file_index = 0;
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode file_open(String* name, Bool is_read, File** file);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_file_open = "file-open";
#define MR_FUNC_NAME _func_name_file_open
Returncode file_open(String* name, Bool is_read, File** file) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode file_close(File* file);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_file_close = "file-close";
#define MR_FUNC_NAME _func_name_file_close
Returncode file_close(File* file) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode file_getc(File* file, Char* ch);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_file_getc = "file-getc";
#define MR_FUNC_NAME _func_name_file_getc
Returncode file_getc(File* file, Char* ch) {
  TEST_ASSERT(29, file == glob->input_file)
  if (mock_input_file_index >= mock_input_file_text->length) {
    (*ch) = EOF;
    return OK;
  }
  if ((mock_input_file_index) < 0 || (mock_input_file_index) >= (mock_input_file_text)->length) RAISE(33)
  (*ch) = ((mock_input_file_text)->values[mock_input_file_index]);
  mock_input_file_index += 1;
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode file_putc(File* file, Char ch);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_file_putc = "file-putc";
#define MR_FUNC_NAME _func_name_file_putc
Returncode file_putc(File* file, Char ch) {
  TEST_ASSERT(37, file == glob->output_file)
  CHECK(38, String_append(mock_output_file_text, ch) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode file_write(File* file, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_file_write = "file-write";
#define MR_FUNC_NAME _func_name_file_write
Returncode file_write(File* file, String* text) {
  TEST_ASSERT(41, file == glob->output_file)
  {int n; for (n = (0); n < (text->length); ++n) {
    if ((n) < 0 || (n) >= (text)->length) RAISE(43)
    Char ch = ((text)->values[n]);
    if (ch != '\n' || ch != mock_output_file_last) {
      CHECK(45, String_append(mock_output_file_text, ch) )
    }
    mock_output_file_last = ch;
  }}
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode write_global(String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_global = "write-global";
#define MR_FUNC_NAME _func_name_write_global
Returncode write_global(String* text) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
extern String* mock_input_file_name;
#elif MR_STAGE == MR_FUNCTIONS
String* mock_input_file_name = &(String){16, 0, (char[16]){0}};
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode f_setup_test();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_f_setup_test = "f-setup-test";
#define MR_FUNC_NAME _func_name_f_setup_test
Returncode f_setup_test() {
  free(glob->operator_map);
  free(glob->type_map);
  CHECK(57, Global_init(glob) )
  glob->input_file_name = mock_input_file_name;
  CHECK(59, String_copy(glob->input_file_name, &(String){10, 9, "mock.3.mr"}) )
  glob->line_number = 0;
  glob->save_input = false;
  CHECK(62, String_clear(mock_print_text) )
  CHECK(63, String_clear(mock_input_file_text) )
  CHECK(64, String_clear(mock_output_file_text) )
  mock_output_file_last = '\0';
  mock_input_file_index = 0;
  mock_print_active = false;
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* string assertion */

#if MR_STAGE == MR_DECLARATIONS
Returncode f_assert_string_slice(String* expected, String* actual, Int start, Int length);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_f_assert_string_slice = "f-assert-string-slice";
#define MR_FUNC_NAME _func_name_f_assert_string_slice
Returncode f_assert_string_slice(String* expected, String* actual, Int start, Int length) {
  String* actual_slice = &(String){1, 0, ""};
  if (actual->length >= start + length) {
    if ((start) < 0 || (length) < 0 || (start) + (length) > (actual)->length) RAISE(76)
    actual_slice = (&(String){length, length, (actual)->values + (start)});
    Bool _Bool76;
    CHECK(77, String_equal(actual_slice, expected, &(_Bool76)) )
    if (_Bool76) {
      return OK;
    }
  }
  else {
    if (actual->length > start) {
      if ((start) < 0 || (actual->length - start) < 0 || (start) + (actual->length - start) > (actual)->length) RAISE(80)
      actual_slice = (&(String){actual->length - start, actual->length - start, (actual)->values + (start)});
    }
  }
  CHECK(81, Sys_print_raw(sys, &(String){12, 11, "[expected `"}) )
  CHECK(82, Sys_print_raw(sys, expected) )
  CHECK(83, Sys_print_raw(sys, &(String){9, 8, "`, got `"}) )
  CHECK(84, Sys_print_raw(sys, actual_slice) )
  CHECK(85, Sys_print_raw(sys, &(String){4, 3, "`] "}) )
  TEST_ASSERT(86, false)
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode f_assert_string(String* expected, String* actual);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_f_assert_string = "f-assert-string";
#define MR_FUNC_NAME _func_name_f_assert_string
Returncode f_assert_string(String* expected, String* actual) {
  CHECK(89, f_assert_string_slice(expected, actual, 0, actual->length) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* NameMap tests */

#if MR_STAGE == MR_DECLARATIONS
Returncode test_name_map();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_name_map = "test-name-map";
#define MR_FUNC_NAME _func_name_test_name_map
Returncode test_name_map() {
  NameMap* map = &(NameMap){NULL, NULL};
  String* _String77;
  CHECK(96, NameMap_find(map, &(String){6, 5, "name1"}, (void**)&(_String77)) )
  TEST_ASSERT(96, !(NULL != _String77))
  String* _String78;
  CHECK(97, string_new_copy(&(String){7, 6, "value1"}, &(_String78)) )
  CHECK(97, NameMap_add(map, &(String){6, 5, "name1"}, _String78) )
  String* _String79;
  CHECK(98, NameMap_find(map, &(String){6, 5, "name1"}, (void**)&(_String79)) )
  CHECK(98, f_assert_string(_String79, &(String){7, 6, "value1"}) )
  String* _String80;
  CHECK(99, NameMap_find(map, &(String){6, 5, "name2"}, (void**)&(_String80)) )
  TEST_ASSERT(99, !(NULL != _String80))
  String* _String81;
  CHECK(100, string_new_copy(&(String){7, 6, "value2"}, &(_String81)) )
  CHECK(100, NameMap_add(map, &(String){6, 5, "name2"}, _String81) )
  String* _String82;
  CHECK(101, NameMap_find(map, &(String){6, 5, "name1"}, (void**)&(_String82)) )
  CHECK(101, f_assert_string(_String82, &(String){7, 6, "value1"}) )
  String* _String83;
  CHECK(102, NameMap_find(map, &(String){6, 5, "name2"}, (void**)&(_String83)) )
  CHECK(102, f_assert_string(_String83, &(String){7, 6, "value2"}) )
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
#include "tests/syntax-tree-tests.c"
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
