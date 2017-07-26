#ifndef MR_MAINFILE
#define MR_MAINFILE "tests/global-tests.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file13_name = "tests/global-tests.3.mr";
#endif
#define MR_FILE_NAME _mr_file13_name

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
Returncode print(String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_print = "print";
#define MR_FUNC_NAME _func_name_print
Returncode print(String* text) {
  if (mock_print_active) {
    CHECK(13, String_concat(mock_print_text, text) )
  }
  else {
    CHECK(15, Sys_print_raw(sys, text) )
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
  CHECK(18, String_copy(mock_input_file_text, text) )
  mock_input_file_index = 0;
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
  TEST_ASSERT(22, file == glob->input_file)
  TEST_ASSERT(23, NULL != mock_input_file_text)
  if (mock_input_file_index >= mock_input_file_text->length) {
    (*ch) = EOF;
    return OK;
  }
  if ((mock_input_file_index) < 0 || (mock_input_file_index) >= (mock_input_file_text)->length) RAISE(27)
  (*ch) = ((mock_input_file_text)->values[mock_input_file_index]);
  mock_input_file_index += 1;
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
  TEST_ASSERT(31, file == glob->output_file)
  CHECK(32, String_concat(mock_output_file_text, text) )
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
  CHECK(40, Global_init(glob) )
  glob->input_file_name = mock_input_file_name;
  CHECK(42, String_copy(glob->input_file_name, &(String){10, 9, "mock.3.mr"}) )
  glob->line_number = 0;
  CHECK(44, String_clear(mock_print_text) )
  CHECK(45, String_clear(mock_input_file_text) )
  CHECK(46, String_clear(mock_output_file_text) )
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
    if ((start) < 0 || (length) < 0 || (start) + (length) > (actual)->length) RAISE(57)
    actual_slice = (&(String){length, length, (actual)->values + (start)});
    Bool _Bool28;
    CHECK(58, String_equal(actual_slice, expected, &(_Bool28)) )
    if (_Bool28) {
      return OK;
    }
  }
  else {
    if (actual->length > start) {
      if ((start) < 0 || (actual->length - start) < 0 || (start) + (actual->length - start) > (actual)->length) RAISE(61)
      actual_slice = (&(String){actual->length - start, actual->length - start, (actual)->values + (start)});
    }
  }
  CHECK(62, Sys_print_raw(sys, &(String){12, 11, "[expected `"}) )
  CHECK(63, Sys_print_raw(sys, expected) )
  CHECK(64, Sys_print_raw(sys, &(String){9, 8, "`, got `"}) )
  CHECK(65, Sys_print_raw(sys, actual_slice) )
  CHECK(66, Sys_print_raw(sys, &(String){4, 3, "`] "}) )
  TEST_ASSERT(67, false)
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
  CHECK(70, f_assert_string_slice(expected, actual, 0, actual->length) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Name-map tests */

#if MR_STAGE == MR_DECLARATIONS
Returncode test_name_map();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_name_map = "test-name-map";
#define MR_FUNC_NAME _func_name_test_name_map
Returncode test_name_map() {
  Name_map* map = &(Name_map){NULL, NULL};
  String* _String29;
  CHECK(77, Name_map_find(map, &(String){6, 5, "name1"}, (void**)&(_String29)) )
  TEST_ASSERT(77, !(NULL != _String29))
  String* _String30;
  CHECK(78, string_new_copy(&(String){7, 6, "value1"}, &(_String30)) )
  CHECK(78, Name_map_add(map, &(String){6, 5, "name1"}, _String30) )
  String* _String31;
  CHECK(79, Name_map_find(map, &(String){6, 5, "name1"}, (void**)&(_String31)) )
  CHECK(79, f_assert_string(_String31, &(String){7, 6, "value1"}) )
  String* _String32;
  CHECK(80, Name_map_find(map, &(String){6, 5, "name2"}, (void**)&(_String32)) )
  TEST_ASSERT(80, !(NULL != _String32))
  String* _String33;
  CHECK(81, string_new_copy(&(String){7, 6, "value2"}, &(_String33)) )
  CHECK(81, Name_map_add(map, &(String){6, 5, "name2"}, _String33) )
  String* _String34;
  CHECK(82, Name_map_find(map, &(String){6, 5, "name1"}, (void**)&(_String34)) )
  CHECK(82, f_assert_string(_String34, &(String){7, 6, "value1"}) )
  String* _String35;
  CHECK(83, Name_map_find(map, &(String){6, 5, "name2"}, (void**)&(_String35)) )
  CHECK(83, f_assert_string(_String35, &(String){7, 6, "value2"}) )
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
#include "global/map.c"
#include "global/type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/variable.c"
#include "tests/expression-tests.c"
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
