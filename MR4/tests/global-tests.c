#ifndef MR_MAINFILE
#define MR_MAINFILE "tests/global-tests.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file24_name = "tests/global-tests.3.mr";
#endif
#define MR_FILE_NAME _mr_file24_name

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
String* mock_output_file_text = &(String){4096, 0, (char[4096]){0}};
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Int mock_input_file_index;
#elif MR_STAGE == MR_FUNCTIONS
Int mock_input_file_index = 0;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Int mock_input_line_reset_index;
#elif MR_STAGE == MR_FUNCTIONS
Int mock_input_line_reset_index = 0;
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
    CHECK(15, String_concat(mock_print_text, text) )
  }
  else {
    CHECK(17, Sys_print_raw(sys, text) )
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
  CHECK(20, String_copy(mock_input_file_text, text) )
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
  TEST_ASSERT(30, file == glob->input_file)
  if (mock_input_file_index >= mock_input_file_text->length) {
    (*ch) = EOF;
    return OK;
  }
  if ((mock_input_file_index) < 0 || (mock_input_file_index) >= (mock_input_file_text)->length) RAISE(34)
  (*ch) = ((mock_input_file_text)->values[mock_input_file_index]);
  if (mock_input_file_index == mock_input_line_reset_index) {
    glob->line_number = 1;
  }
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
  TEST_ASSERT(40, file == glob->output_file)
  if (mock_output_file_text->length == 4096) {
    CHECK(42, Sys_print_raw(sys, &(String){14, 13, "full output ["}) )
    CHECK(43, Sys_print_raw(sys, mock_output_file_text) )
    CHECK(44, Sys_print(sys, &(String){2, 1, "]"}) )
  }
  CHECK(45, String_append(mock_output_file_text, ch) )
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
  TEST_ASSERT(48, file == glob->output_file)
  {int n; for (n = (0); n < (text->length); ++n) {
    if ((n) < 0 || (n) >= (text)->length) RAISE(50)
    Char ch = ((text)->values[n]);
    if (ch != '\n' || ch != mock_output_file_last) {
      CHECK(52, String_append(mock_output_file_text, ch) )
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
Returncode write_pre_func(SyntaxTreeFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_pre_func = "write-pre-func";
#define MR_FUNC_NAME _func_name_write_pre_func
Returncode write_pre_func(SyntaxTreeFunction* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode write_post_func();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_post_func = "write-post-func";
#define MR_FUNC_NAME _func_name_write_post_func
Returncode write_post_func() {
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
  CHECK(70, Global_init(glob) )
  glob->input_file_name = mock_input_file_name;
  CHECK(72, String_copy(glob->input_file_name, &(String){10, 9, "mock.3.mr"}) )
  glob->line_number = 0;
  glob->save_input = false;
  CHECK(75, String_clear(mock_print_text) )
  CHECK(76, String_clear(mock_input_file_text) )
  CHECK(77, String_clear(mock_output_file_text) )
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
    if ((start) < 0 || (length) < 0 || (start) + (length) > (actual)->length) RAISE(89)
    actual_slice = (&(String){length, length, (actual)->values + (start)});
    Bool _Bool133;
    CHECK(90, String_equal(actual_slice, expected, &(_Bool133)) )
    if (_Bool133) {
      return OK;
    }
  }
  else {
    if (actual->length > start) {
      if ((start) < 0 || (actual->length - start) < 0 || (start) + (actual->length - start) > (actual)->length) RAISE(93)
      actual_slice = (&(String){actual->length - start, actual->length - start, (actual)->values + (start)});
    }
  }
  CHECK(94, Sys_print_raw(sys, &(String){12, 11, "[expected `"}) )
  CHECK(95, Sys_print_raw(sys, expected) )
  CHECK(96, Sys_print_raw(sys, &(String){9, 8, "`, got `"}) )
  CHECK(97, Sys_print_raw(sys, actual_slice) )
  CHECK(98, Sys_print_raw(sys, &(String){4, 3, "`] "}) )
  CHECK(99, write_new_file(&(String){13, 12, "expected.txt"}, expected) )
  CHECK(100, write_new_file(&(String){11, 10, "actual.txt"}, actual_slice) )
  TEST_ASSERT(101, false)
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode write_new_file(String* filename, String* data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_new_file = "write-new-file";
#define MR_FUNC_NAME _func_name_write_new_file
Returncode write_new_file(String* filename, String* data) {
  File* file = NULL;
  CHECK(105, file_open_write(filename, &(file)) )
  CHECK(106, File_write(file, data) )
  CHECK(107, File_close(file) )
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
  TEST_ASSERT(110, NULL != actual)
  CHECK(111, f_assert_string_slice(expected, actual, 0, actual->length) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* List tests */
#if MR_STAGE == MR_DECLARATIONS
Returncode test_list();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_list = "test-list";
#define MR_FUNC_NAME _func_name_test_list
Returncode test_list() {
  List* list = &(List){NULL, NULL};
  String* _String134;
  CHECK(117, List_pop(list, (void**)&(_String134)) )
  TEST_ASSERT(117, !(NULL != _String134))
  String* _String135;
  CHECK(118, string_new_copy(&(String){7, 6, "value1"}, &(_String135)) )
  CHECK(118, List_add(list, _String135) )
  String* _String136;
  CHECK(119, string_new_copy(&(String){7, 6, "value2"}, &(_String136)) )
  CHECK(119, List_add(list, _String136) )
  String* _String137;
  CHECK(120, string_new_copy(&(String){7, 6, "value3"}, &(_String137)) )
  CHECK(120, List_add(list, _String137) )
  String* _String138;
  CHECK(121, List_pop(list, (void**)&(_String138)) )
  CHECK(121, f_assert_string(&(String){7, 6, "value1"}, _String138) )
  String* _String139;
  CHECK(122, List_pop(list, (void**)&(_String139)) )
  CHECK(122, f_assert_string(&(String){7, 6, "value2"}, _String139) )
  String* _String140;
  CHECK(123, List_pop(list, (void**)&(_String140)) )
  CHECK(123, f_assert_string(&(String){7, 6, "value3"}, _String140) )
  String* _String141;
  CHECK(124, List_pop(list, (void**)&(_String141)) )
  TEST_ASSERT(124, !(NULL != _String141))
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
  String* _String142;
  CHECK(131, NameMap_find(map, &(String){6, 5, "name1"}, (void**)&(_String142)) )
  TEST_ASSERT(131, !(NULL != _String142))
  CHECK(132, NameMap_add(map, &(String){6, 5, "name1"}, &(String){7, 6, "value1"}) )
  String* _String143;
  CHECK(133, NameMap_find(map, &(String){6, 5, "name1"}, (void**)&(_String143)) )
  CHECK(133, f_assert_string(&(String){7, 6, "value1"}, _String143) )
  String* _String144;
  CHECK(134, NameMap_find(map, &(String){6, 5, "name2"}, (void**)&(_String144)) )
  TEST_ASSERT(134, !(NULL != _String144))
  CHECK(135, NameMap_add(map, &(String){6, 5, "name2"}, &(String){7, 6, "value2"}) )
  String* _String145;
  CHECK(136, NameMap_find(map, &(String){6, 5, "name1"}, (void**)&(_String145)) )
  CHECK(136, f_assert_string(&(String){7, 6, "value1"}, _String145) )
  String* _String146;
  CHECK(137, NameMap_find(map, &(String){6, 5, "name2"}, (void**)&(_String146)) )
  CHECK(137, f_assert_string(&(String){7, 6, "value2"}, _String146) )
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
