#ifndef MR_MAINFILE
#define MR_MAINFILE "tests/global-tests.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file31_name = "tests/global-tests.3.mr";
#endif
#define MR_FILE_NAME _mr_file31_name

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
String* mock_input_file_text = &(String){2048, 0, (char[2048]){0}};
#endif
#if MR_STAGE == MR_DECLARATIONS
extern String* mock_output_file_text;
#elif MR_STAGE == MR_FUNCTIONS
String* mock_output_file_text = &(String){16384, 0, (char[16384]){0}};
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
extern File* input_file;
#elif MR_STAGE == MR_FUNCTIONS
File* input_file = NULL;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern File* actual_output_file;
#elif MR_STAGE == MR_FUNCTIONS
File* actual_output_file = NULL;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern File* expected_output_file;
#elif MR_STAGE == MR_FUNCTIONS
File* expected_output_file = NULL;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Bool tests_passed;
#elif MR_STAGE == MR_FUNCTIONS
Bool tests_passed = false;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Bool had_test_error;
#elif MR_STAGE == MR_FUNCTIONS
Bool had_test_error = false;
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode print(String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_print = "print";
#define MR_FUNC_NAME _func_name_print
Returncode print(String* text) {
  TEST_ASSERT(20, NULL != text)
  if (mock_print_active) {
    CHECK(22, String_concat(mock_print_text, text) )
  }
  else {
    CHECK(24, Sys_print_raw(sys, text) )
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
  CHECK(27, String_copy(mock_input_file_text, text) )
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
  TEST_ASSERT(37, file == glob->input_file)
  if (mock_input_file_index >= mock_input_file_text->length) {
    (*ch) = EOF;
    return OK;
  }
  if ((mock_input_file_index) < 0 || (mock_input_file_index) >= (mock_input_file_text)->length) RAISE(41)
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
  TEST_ASSERT(47, file == glob->output_file)
  CHECK(48, String_append(mock_output_file_text, ch) )
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
  TEST_ASSERT(51, file == glob->output_file)
  {int n; for (n = (0); n < (text->length); ++n) {
    if ((n) < 0 || (n) >= (text)->length) RAISE(53)
    Char ch = ((text)->values[n]);
    if (ch != '\n' || ch != mock_output_file_last) {
      CHECK(55, String_append(mock_output_file_text, ch) )
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
  CHECK(73, Global_init(glob) )
  glob->input_file_name = mock_input_file_name;
  CHECK(75, String_copy(glob->input_file_name, &(String){10, 9, "mock.4.mr"}) )
  glob->line_number = 0;
  glob->save_input = false;
  CHECK(78, String_clear(mock_print_text) )
  CHECK(79, String_clear(mock_input_file_text) )
  CHECK(80, String_clear(mock_output_file_text) )
  mock_output_file_last = '\0';
  mock_input_file_index = 0;
  mock_print_active = false;
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* string assertion */

#if MR_STAGE == MR_DECLARATIONS
Returncode f_assert_string_slice(String* expected, String* actual, Int start, Int slice_length, Bool is_main);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_f_assert_string_slice = "f-assert-string-slice";
#define MR_FUNC_NAME _func_name_f_assert_string_slice
Returncode f_assert_string_slice(String* expected, String* actual, Int start, Int slice_length, Bool is_main) {
  String* actual_slice = &(String){1, 0, ""};
  if (actual->length >= start + slice_length) {
    if ((start) < 0 || (slice_length) < 0 || (start) + (slice_length) > (actual)->length) RAISE(96)
    actual_slice = (&(String){slice_length, slice_length, (actual)->values + (start)});
  }
  else {
    if (actual->length > start) {
      if ((start) < 0 || (actual->length - start) < 0 || (start) + (actual->length - start) > (actual)->length) RAISE(98)
      actual_slice = (&(String){actual->length - start, actual->length - start, (actual)->values + (start)});
    }
  }
  if (is_main) {
    CHECK(100, File_write(actual_output_file, actual_slice) )
    CHECK(101, File_write(actual_output_file, &(String){2, 1, "\n"}) )
  }
  Bool _Bool176;
  CHECK(102, String_equal(actual_slice, expected, &(_Bool176)) )
  if (_Bool176) {
    return OK;
  }
  CHECK(104, Sys_print_raw(sys, &(String){15, 14, "\n  [expected `"}) )
  CHECK(105, Sys_print_raw(sys, expected) )
  CHECK(106, Sys_print_raw(sys, &(String){9, 8, "`, got `"}) )
  CHECK(107, Sys_print_raw(sys, actual_slice) )
  CHECK(108, Sys_print_raw(sys, &(String){4, 3, "`] "}) )
  CHECK(109, write_new_file(&(String){13, 12, "expected.txt"}, expected) )
  CHECK(110, write_new_file(&(String){11, 10, "actual.txt"}, actual_slice) )
  tests_passed = false;
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
  CHECK(115, file_open_write(filename, &(file)) )
  CHECK(116, File_write(file, data) )
  CHECK(117, File_close(file) )
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
  TEST_ASSERT(120, NULL != actual)
  CHECK(121, f_assert_string_slice(expected, actual, 0, actual->length, false) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode set_test_file_name(String* filename, String* base_name, String* suffix);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_set_test_file_name = "set-test-file-name";
#define MR_FUNC_NAME _func_name_set_test_file_name
Returncode set_test_file_name(String* filename, String* base_name, String* suffix) {
  String* base_dir = &(String){1024, 0, (char[1024]){0}};
  Bool _Bool177;
  CHECK(128, Sys_getenv(sys, &(String){9, 8, "TEST_DIR"}, base_dir, &(_Bool177)) )
  if (_Bool177) {
    CHECK(129, String_copy(filename, base_dir) )
  }
  CHECK(130, String_concat(filename, base_name) )
  CHECK(131, String_concat(filename, suffix) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_new_file(String* base_name, String* name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_new_file = "test-new-file";
#define MR_FUNC_NAME _func_name_test_new_file
Returncode test_new_file(String* base_name, String* name) {
  String* filename = &(String){256, 0, (char[256]){0}};
  CHECK(136, set_test_file_name(filename, base_name, &(String){6, 5, ".4.mr"}) )
  CHECK(137, file_open_read(filename, &(input_file)) )
  CHECK(138, set_test_file_name(filename, base_name, &(String){12, 11, ".expected.c"}) )
  CHECK(139, file_open_read(filename, &(expected_output_file)) )
  CHECK(140, set_test_file_name(filename, base_name, &(String){10, 9, ".actual.c"}) )
  CHECK(141, file_open_write(filename, &(actual_output_file)) )
  
  had_test_error = false;
  String* line = &(String){1024, 0, (char[1024]){0}};
  Bool _Bool178;
  CHECK(145, read_line(input_file, line, &(String){7, 6, "## @@ "}, &(_Bool178)) )
  if (!_Bool178) {
    CHECK(146, file_error(name, line) )
  }
  Bool _Bool179;
  CHECK(147, read_line(expected_output_file, line, &(String){8, 7, "/// @@ "}, &(_Bool179)) )
  if (!_Bool179) {
    CHECK(148, file_error(name, line) )
  }
  CHECK(149, test_from_file(name) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode test_from_file(String* name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_from_file = "test-from-file";
#define MR_FUNC_NAME _func_name_test_from_file
Returncode test_from_file(String* name) {
  String* line = &(String){1024, 0, (char[1024]){0}};
  String* subname = &(String){1024, 0, (char[1024]){0}};
  CHECK(154, String_copy(subname, &(String){6, 5, "start"}))
  if (had_test_error) {
    while (true) {
      Bool _Bool180;
      CHECK(157, read_line(input_file, line, &(String){7, 6, "## @@ "}, &(_Bool180)) )
      if (!(!_Bool180)) break;
    }
    while (true) {
      Bool _Bool181;
      CHECK(159, read_line(expected_output_file, line, &(String){8, 7, "/// @@ "}, &(_Bool181)) )
      if (!(!_Bool181)) break;
    }
  }
  had_test_error = true;
  Bool _Bool182;
  CHECK(161, read_line(input_file, line, NULL, &(_Bool182)) )
  Bool _Bool183;
  CHECK(162, String_equal(line, name, &(_Bool183)) )
  if (!_Bool183) {
    CHECK(163, file_error(name, line) )
  }
  Bool _Bool184;
  CHECK(164, read_line(expected_output_file, line, NULL, &(_Bool184)) )
  Bool _Bool185;
  CHECK(165, String_equal(line, name, &(_Bool185)) )
  if (!_Bool185) {
    CHECK(166, file_error(name, line) )
  }
  CHECK(167, File_write(actual_output_file, &(String){8, 7, "/// @@ "}) )
  CHECK(168, File_write(actual_output_file, name) )
  CHECK(169, File_write(actual_output_file, &(String){2, 1, "\n"}) )
  
  String* input = &(String){4096, 0, (char[4096]){0}};
  String* expected = &(String){16384, 0, (char[16384]){0}};
  Bool _Bool186;
  CHECK(173, read_line(input_file, line, &(String){6, 5, "## @ "}, &(_Bool186)) )
  if (!_Bool186) {
    CHECK(174, file_error(name, line) )
  }
  Bool _Bool187;
  CHECK(175, read_line(expected_output_file, line, &(String){7, 6, "/// @ "}, &(_Bool187)) )
  if (!_Bool187) {
    CHECK(176, file_error(name, line) )
  }
  
  Char type_char = '\0';
  Bool is_error_test = false;
  Bool append_newline = false;
  Bool is_test = false;
  tests_passed = true;
  while (true) {
    CHECK(184, File_getc(input_file, &(type_char)) )
    append_newline = type_char != 'f';
    if (!append_newline) {
      CHECK(187, File_getc(input_file, &(type_char)) )
    }
    is_error_test = type_char == 'e';
    if (is_error_test) {
      CHECK(190, File_getc(input_file, &(type_char)) )
    }
    is_test = type_char == 't';
    if (is_test) {
      CHECK(193, File_getc(input_file, &(type_char)) )
    }
    if (type_char != 'g' && type_char != 'c') {
      CHECK(195, file_error(name, subname) )
    }
    Char _Char188;
    CHECK(196, File_getc(input_file, &(_Char188)) )
    if (_Char188 != ' ') {
      CHECK(197, file_error(name, subname) )
    }
    Bool _Bool189;
    CHECK(198, read_line(input_file, subname, NULL, &(_Bool189)) )
    Bool _Bool190;
    CHECK(199, read_line(expected_output_file, line, NULL, &(_Bool190)) )
    Bool _Bool191;
    CHECK(200, String_equal(line, subname, &(_Bool191)) )
    if (!_Bool191) {
      CHECK(201, file_error(name, subname) )
    }
    CHECK(202, File_write(actual_output_file, &(String){7, 6, "/// @ "}) )
    CHECK(203, File_write(actual_output_file, subname) )
    CHECK(204, File_write(actual_output_file, &(String){2, 1, "\n"}) )
    
    CHECK(206, read_data(input_file, input, &(String){5, 4, "## @"}) )
    CHECK(207, read_data(expected_output_file, expected, &(String){6, 5, "/// @"}) )
    if (append_newline) {
      CHECK(209, String_append(input, '\n') )
    }
    if (type_char == 'c') {
      if (is_error_test) {
        CHECK(212, test_code_error(input, expected) )
      }
      else {
        CHECK(214, test_code(input, expected) )
      }
    }
    else {
      if (is_error_test) {
        CHECK(217, test_global_scope_error(input, expected) )
      }
      else {
        CHECK(219, test_global_scope(input, expected, is_test) )
      }
    }
    
    Char _Char192;
    CHECK(221, File_getc(expected_output_file, &(_Char192)) )
    Char _Char193;
    CHECK(222, File_getc(input_file, &(_Char193)) )
    if (!(_Char193 == ' ')) break;
  }
  
  Char _Char194;
  CHECK(224, File_getc(expected_output_file, &(_Char194)) )
  Char _Char195;
  CHECK(225, File_getc(input_file, &(_Char195)) )
  if (_Char195 == EOF) {
    Char _Char196;
    CHECK(226, File_getc(expected_output_file, &(_Char196)) )
    if (_Char196 != EOF) {
      CHECK(227, file_error(name, subname) )
    }
    CHECK(228, File_write(actual_output_file, &(String){7, 6, "/// @\n"}) )
    CHECK(229, File_close(input_file) )
    CHECK(230, File_close(expected_output_file) )
    CHECK(231, File_close(actual_output_file) )
  }
  
  had_test_error = false;
  TEST_ASSERT(234, tests_passed)
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode read_line(File* file, String* line, String* prefix, Bool* found_prefix);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_read_line = "read-line";
#define MR_FUNC_NAME _func_name_read_line
Returncode read_line(File* file, String* line, String* prefix, Bool* found_prefix) {
  CHECK(238, String_clear(line) )
  (*found_prefix) = false;
  Char ch = '\0';
  while (true) {
    CHECK(242, File_getc(file, &(ch)) )
    if (!(ch != EOF && ch != '\n')) break;
    CHECK(244, String_append(line, ch) )
    if (NULL != prefix &&  ! (*found_prefix)) {
      Bool _Bool197;
      CHECK(246, String_equal(line, prefix, &(_Bool197)) )
      if (_Bool197) {
        (*found_prefix) = true;
        return OK;
      }
    }
  }
  if (ch == EOF && line->length == 0) {
    RAISE(250)
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode read_data(File* file, String* data, String* prefix);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_read_data = "read-data";
#define MR_FUNC_NAME _func_name_read_data
Returncode read_data(File* file, String* data, String* prefix) {
  CHECK(254, String_clear(data) )
  String* line = &(String){1024, 0, (char[1024]){0}};
  while (true) {
    Bool _Bool198;
    CHECK(257, read_line(file, line, prefix, &(_Bool198)) )
    if (!(!_Bool198)) break;
    if (data->length > 0) {
      CHECK(259, String_append(data, '\n') )
    }
    CHECK(260, String_concat(data, line) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode file_error(String* name, String* subname);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_file_error = "file-error";
#define MR_FUNC_NAME _func_name_file_error
Returncode file_error(String* name, String* subname) {
  CHECK(264, Sys_print_raw(sys, &(String){23, 22, "file format error in ["}) )
  CHECK(265, Sys_print_raw(sys, name) )
  if (NULL != subname) {
    CHECK(267, Sys_print_raw(sys, &(String){6, 5, "] / ["}) )
    CHECK(268, Sys_print_raw(sys, subname) )
  }
  CHECK(269, Sys_print(sys, &(String){2, 1, "]"}) )
  RAISE(270)
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
  String* _String199;
  CHECK(276, List_pop(list, (void**)&(_String199)) )
  TEST_ASSERT(276, !(NULL != _String199))
  String* _String200;
  CHECK(277, string_new_copy(&(String){7, 6, "value1"}, &(_String200)) )
  CHECK(277, List_add(list, _String200) )
  String* _String201;
  CHECK(278, string_new_copy(&(String){7, 6, "value2"}, &(_String201)) )
  CHECK(278, List_add(list, _String201) )
  String* _String202;
  CHECK(279, string_new_copy(&(String){7, 6, "value3"}, &(_String202)) )
  CHECK(279, List_add(list, _String202) )
  String* _String203;
  CHECK(280, List_pop(list, (void**)&(_String203)) )
  CHECK(280, f_assert_string(&(String){7, 6, "value1"}, _String203) )
  String* _String204;
  CHECK(281, List_pop(list, (void**)&(_String204)) )
  CHECK(281, f_assert_string(&(String){7, 6, "value2"}, _String204) )
  String* _String205;
  CHECK(282, List_pop(list, (void**)&(_String205)) )
  CHECK(282, f_assert_string(&(String){7, 6, "value3"}, _String205) )
  String* _String206;
  CHECK(283, List_pop(list, (void**)&(_String206)) )
  TEST_ASSERT(283, !(NULL != _String206))
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
  String* _String207;
  CHECK(289, NameMap_find(map, &(String){6, 5, "name1"}, (void**)&(_String207)) )
  TEST_ASSERT(289, !(NULL != _String207))
  CHECK(290, NameMap_add(map, &(String){6, 5, "name1"}, &(String){7, 6, "value1"}) )
  String* _String208;
  CHECK(291, NameMap_find(map, &(String){6, 5, "name1"}, (void**)&(_String208)) )
  CHECK(291, f_assert_string(&(String){7, 6, "value1"}, _String208) )
  String* _String209;
  CHECK(292, NameMap_find(map, &(String){6, 5, "name2"}, (void**)&(_String209)) )
  TEST_ASSERT(292, !(NULL != _String209))
  CHECK(293, NameMap_add(map, &(String){6, 5, "name2"}, &(String){7, 6, "value2"}) )
  String* _String210;
  CHECK(294, NameMap_find(map, &(String){6, 5, "name1"}, (void**)&(_String210)) )
  CHECK(294, f_assert_string(&(String){7, 6, "value1"}, _String210) )
  String* _String211;
  CHECK(295, NameMap_find(map, &(String){6, 5, "name2"}, (void**)&(_String211)) )
  CHECK(295, f_assert_string(&(String){7, 6, "value2"}, _String211) )
  CHECK(296, NameMap_update_or_add(map, &(String){6, 5, "name3"}, &(String){7, 6, "value3"}) )
  String* _String212;
  CHECK(297, NameMap_find(map, &(String){6, 5, "name3"}, (void**)&(_String212)) )
  CHECK(297, f_assert_string(&(String){7, 6, "value3"}, _String212) )
  CHECK(298, NameMap_update_or_add(map, &(String){6, 5, "name2"}, &(String){8, 7, "value2x"}) )
  String* _String213;
  CHECK(299, NameMap_find(map, &(String){6, 5, "name2"}, (void**)&(_String213)) )
  CHECK(299, f_assert_string(&(String){8, 7, "value2x"}, _String213) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Illegal call tests */
#if MR_STAGE == MR_DECLARATIONS
Returncode test_illegal_call();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_test_illegal_call = "test-illegal-call";
#define MR_FUNC_NAME _func_name_test_illegal_call
Returncode test_illegal_call() {
  Argument* arg = &(Argument){Argument__dtl, NULL, 0, 0, false, false};
  arg->_base._dtl = Argument__dtl;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    DeclarationArgument* _DeclarationArgument214;
    CHECK(305, (arg)->_base._dtl[5](arg, &(_DeclarationArgument214)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(305)
  } while (false);
  _trace_stream = stdout;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    Char _Char215;
    CHECK(306, (arg)->_base._dtl[6](arg, NULL, &(_Char215)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(306)
  } while (false);
  _trace_stream = stdout;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    TypeInstance* _TypeInstance216;
    CHECK(307, (arg)->_base._dtl[7](arg, &(_TypeInstance216)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(307)
  } while (false);
  _trace_stream = stdout;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    SyntaxTreeVariable* _SyntaxTreeVariable217;
    CHECK(308, (arg)->_base._dtl[9](arg, &(_SyntaxTreeVariable217)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(308)
  } while (false);
  _trace_stream = stdout;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    Expression* _Expression218;
    CHECK(309, (arg)->_base._dtl[10](arg, &(_Expression218)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(309)
  } while (false);
  _trace_stream = stdout;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(310, (arg)->_base._dtl[11](arg) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(310)
  } while (false);
  _trace_stream = stdout;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(311, (arg)->_base._dtl[12](arg) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(311)
  } while (false);
  _trace_stream = stdout;
  ArgumentFactory* factory = &(ArgumentFactory){ArgumentFactory__dtl};
  factory->_dtl = ArgumentFactory__dtl;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    Argument* _Argument219;
    CHECK(313, (factory)->_dtl[0](factory, &(_Argument219)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(313)
  } while (false);
  _trace_stream = stdout;
  SyntaxTreeBranch* branch = &(SyntaxTreeBranch){SyntaxTreeBranch__dtl, NULL, 0, 0, NULL};
  branch->_base._dtl = SyntaxTreeBranch__dtl;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    Char _Char220;
    CHECK(315, (branch)->_base._dtl[5](branch, NULL, &(_Char220)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(315)
  } while (false);
  _trace_stream = stdout;
  SyntaxTreeNode* node = &(SyntaxTreeNode){SyntaxTreeNode__dtl, NULL, 0};
  node->_dtl = SyntaxTreeNode__dtl;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(317, (node)->_dtl[4](node) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(317)
  } while (false);
  _trace_stream = stdout;
  NodeAction* action = &(NodeAction){NodeAction__dtl};
  action->_dtl = NodeAction__dtl;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(319, (action)->_dtl[0](action, NULL) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(319)
  } while (false);
  _trace_stream = stdout;
  SyntaxTreeRoot* root = &(SyntaxTreeRoot){SyntaxTreeRoot__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, false, false};
  root->_base._base._base._dtl = SyntaxTreeRoot__dtl;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(321, (root)->_base._base._base._dtl[1](root) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(321)
  } while (false);
  _trace_stream = stdout;
  TypeWriter* tw = &(TypeWriter){TypeWriter__dtl};
  tw->_dtl = TypeWriter__dtl;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(323, (tw)->_dtl[0](tw, NULL) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(323)
  } while (false);
  _trace_stream = stdout;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(324, write_cname(NULL) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(324)
  } while (false);
  _trace_stream = stdout;
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
