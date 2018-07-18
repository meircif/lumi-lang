#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "tests/global-tests.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file32_name = "tests/global-tests.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file32_name

/* TL4 compiler tests - Global */

/* IO mocks */

#if LUMI_STAGE == LUMI_DECLARATIONS
extern String* mock_print_text;
#elif LUMI_STAGE == LUMI_FUNCTIONS
String* mock_print_text = &(String){1024, 0, (char[1024]){0}};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern String* mock_input_file_text;
#elif LUMI_STAGE == LUMI_FUNCTIONS
String* mock_input_file_text = &(String){2048, 0, (char[2048]){0}};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern String* mock_output_file_text;
#elif LUMI_STAGE == LUMI_FUNCTIONS
String* mock_output_file_text = &(String){16384, 0, (char[16384]){0}};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Int mock_input_file_index;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Int mock_input_file_index = 0;
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Int mock_input_line_eof_index;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Int mock_input_line_eof_index = 0;
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Int mock_input_line_reset_index;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Int mock_input_line_reset_index = 0;
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Bool mock_print_active;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Bool mock_print_active = false;
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Char mock_output_file_last;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Char mock_output_file_last = '\0';
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
extern File* input_file;
#elif LUMI_STAGE == LUMI_FUNCTIONS
File* input_file = NULL;
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern File* actual_output_file;
#elif LUMI_STAGE == LUMI_FUNCTIONS
File* actual_output_file = NULL;
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern File* expected_output_file;
#elif LUMI_STAGE == LUMI_FUNCTIONS
File* expected_output_file = NULL;
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Bool tests_passed;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Bool tests_passed = false;
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Bool had_test_error;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Bool had_test_error = false;
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode print(String* text);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_print = "print";
#define LUMI_FUNC_NAME _func_name_print
Returncode print(String* text) {
  TEST_ASSERT(21, NULL != text)
  if (mock_print_active) {
    CHECK(23, String_concat(mock_print_text, text) )
  }
  else {
    CHECK(25, Sys_print_raw(sys, text) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode set_mock_file_text(String* text, String* second_file_text);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_set_mock_file_text = "set-mock-file-text";
#define LUMI_FUNC_NAME _func_name_set_mock_file_text
Returncode set_mock_file_text(String* text, String* second_file_text) {
  CHECK(28, String_copy(mock_input_file_text, &(String){11, 10, "module ut\n"}) )
  mock_input_line_reset_index = mock_input_file_text->length;
  CHECK(30, String_concat(mock_input_file_text, text) )
  if (NULL != second_file_text) {
    mock_input_line_eof_index = mock_input_file_text->length;
    CHECK(33, String_concat(mock_input_file_text, second_file_text) )
  }
  else {
    mock_input_line_eof_index =  - 1;
  }
  mock_input_file_index = 0;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode file_open(String* name, Bool is_read, File** file);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_file_open = "file-open";
#define LUMI_FUNC_NAME _func_name_file_open
Returncode file_open(String* name, Bool is_read, File** file) {
  /* do nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode file_close(File* file);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_file_close = "file-close";
#define LUMI_FUNC_NAME _func_name_file_close
Returncode file_close(File* file) {
  mock_input_line_eof_index =  - 1;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode file_getc(File* file, Char* ch);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_file_getc = "file-getc";
#define LUMI_FUNC_NAME _func_name_file_getc
Returncode file_getc(File* file, Char* ch) {
  TEST_ASSERT(45, file == glob->input_file)
  if (mock_input_file_index == mock_input_line_eof_index || mock_input_file_index >= mock_input_file_text->length) {
    (*ch) = EOF;
    return OK;
  }
  if ((mock_input_file_index) < 0 || (mock_input_file_index) >= (mock_input_file_text)->length) RAISE(50)
  (*ch) = ((mock_input_file_text)->values[mock_input_file_index]);
  if (mock_input_file_index == mock_input_line_reset_index) {
    glob->line_number = 1;
  }
  mock_input_file_index += 1;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode file_putc(File* file, Char ch);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_file_putc = "file-putc";
#define LUMI_FUNC_NAME _func_name_file_putc
Returncode file_putc(File* file, Char ch) {
  TEST_ASSERT(56, file == glob->output_file)
  CHECK(57, String_append(mock_output_file_text, ch) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode file_write(File* file, String* text);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_file_write = "file-write";
#define LUMI_FUNC_NAME _func_name_file_write
Returncode file_write(File* file, String* text) {
  TEST_ASSERT(60, file == glob->output_file)
  {int n; for (n = (0); n < (text->length); ++n) {
    if ((n) < 0 || (n) >= (text)->length) RAISE(62)
    Char ch = ((text)->values[n]);
    if (ch != '\n' || ch != mock_output_file_last) {
      CHECK(64, String_append(mock_output_file_text, ch) )
    }
    mock_output_file_last = ch;
  }}
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode write_global(String* text);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_write_global = "write-global";
#define LUMI_FUNC_NAME _func_name_write_global
Returncode write_global(String* text) {
  /* do nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode write_pre_func(SyntaxTreeFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_write_pre_func = "write-pre-func";
#define LUMI_FUNC_NAME _func_name_write_pre_func
Returncode write_pre_func(SyntaxTreeFunction* self) {
  /* do nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode write_post_func();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_write_post_func = "write-post-func";
#define LUMI_FUNC_NAME _func_name_write_post_func
Returncode write_post_func() {
  /* do nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
extern String* mock_input_file_name;
#elif LUMI_STAGE == LUMI_FUNCTIONS
String* mock_input_file_name = &(String){16, 0, (char[16]){0}};
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode f_setup_test();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_f_setup_test = "f-setup-test";
#define LUMI_FUNC_NAME _func_name_f_setup_test
Returncode f_setup_test() {
  free(glob->operator_map);
  free(glob->module_map);
  CHECK(82, Global_init(glob) )
  glob->input_file_name = mock_input_file_name;
  CHECK(84, String_copy(glob->input_file_name, &(String){10, 9, "mock.4.lm"}) )
  glob->line_number = 0;
  glob->save_input = false;
  CHECK(87, String_clear(mock_print_text) )
  CHECK(88, String_clear(mock_input_file_text) )
  CHECK(89, String_clear(mock_output_file_text) )
  mock_output_file_last = '\0';
  mock_input_file_index = 0;
  mock_print_active = false;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* string assertion */

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode f_assert_string_slice(String* expected, String* actual, Int start, Int slice_length, Bool is_main);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_f_assert_string_slice = "f-assert-string-slice";
#define LUMI_FUNC_NAME _func_name_f_assert_string_slice
Returncode f_assert_string_slice(String* expected, String* actual, Int start, Int slice_length, Bool is_main) {
  String* actual_slice = &(String){1, 0, ""};
  if (actual->length >= start + slice_length) {
    if ((start) < 0 || (slice_length) < 0 || (start) + (slice_length) > (actual)->length) RAISE(105)
    actual_slice = (&(String){slice_length, slice_length, (actual)->values + (start)});
  }
  else {
    if (actual->length > start) {
      if ((start) < 0 || (actual->length - start) < 0 || (start) + (actual->length - start) > (actual)->length) RAISE(107)
      actual_slice = (&(String){actual->length - start, actual->length - start, (actual)->values + (start)});
    }
  }
  if (is_main) {
    CHECK(109, File_write(actual_output_file, actual_slice) )
    CHECK(110, File_write(actual_output_file, &(String){2, 1, "\n"}) )
  }
  Bool _Bool208;
  CHECK(111, String_equal(actual_slice, expected, &(_Bool208)) )
  if (_Bool208) {
    return OK;
  }
  CHECK(113, Sys_print_raw(sys, &(String){15, 14, "\n  [expected `"}) )
  CHECK(114, Sys_print_raw(sys, expected) )
  CHECK(115, Sys_print_raw(sys, &(String){9, 8, "`, got `"}) )
  CHECK(116, Sys_print_raw(sys, actual_slice) )
  CHECK(117, Sys_print_raw(sys, &(String){4, 3, "`] "}) )
  CHECK(118, write_new_file(&(String){13, 12, "expected.txt"}, expected) )
  CHECK(119, write_new_file(&(String){11, 10, "actual.txt"}, actual_slice) )
  tests_passed = false;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode write_new_file(String* filename, String* data);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_write_new_file = "write-new-file";
#define LUMI_FUNC_NAME _func_name_write_new_file
Returncode write_new_file(String* filename, String* data) {
  File* file = NULL;
  CHECK(124, file_open_write(filename, &(file)) )
  CHECK(125, File_write(file, data) )
  CHECK(126, File_close(file) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode f_assert_string(String* expected, String* actual);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_f_assert_string = "f-assert-string";
#define LUMI_FUNC_NAME _func_name_f_assert_string
Returncode f_assert_string(String* expected, String* actual) {
  TEST_ASSERT(129, NULL != actual)
  CHECK(130, f_assert_string_slice(expected, actual, 0, actual->length, false) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode set_test_file_name(String* filename, String* base_name, String* suffix);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_set_test_file_name = "set-test-file-name";
#define LUMI_FUNC_NAME _func_name_set_test_file_name
Returncode set_test_file_name(String* filename, String* base_name, String* suffix) {
  String* base_dir = &(String){1024, 0, (char[1024]){0}};
  Bool _Bool209;
  CHECK(137, Sys_getenv(sys, &(String){9, 8, "TEST_DIR"}, base_dir, &(_Bool209)) )
  if (_Bool209) {
    CHECK(138, String_copy(filename, base_dir) )
  }
  CHECK(139, String_concat(filename, base_name) )
  CHECK(140, String_concat(filename, suffix) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_new_file(String* base_name, String* name);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_new_file = "test-new-file";
#define LUMI_FUNC_NAME _func_name_test_new_file
Returncode test_new_file(String* base_name, String* name) {
  String* filename = &(String){256, 0, (char[256]){0}};
  CHECK(145, set_test_file_name(filename, base_name, &(String){6, 5, ".4.lm"}) )
  CHECK(146, file_open_read(filename, &(input_file)) )
  CHECK(147, set_test_file_name(filename, base_name, &(String){12, 11, ".expected.c"}) )
  CHECK(148, file_open_read(filename, &(expected_output_file)) )
  CHECK(149, set_test_file_name(filename, base_name, &(String){10, 9, ".actual.c"}) )
  CHECK(150, file_open_write(filename, &(actual_output_file)) )
  
  had_test_error = false;
  String* line = &(String){1024, 0, (char[1024]){0}};
  Bool _Bool210;
  CHECK(154, read_line(input_file, line, &(String){7, 6, "## @@ "}, &(_Bool210)) )
  if (!_Bool210) {
    CHECK(155, file_error(name, line) )
  }
  Bool _Bool211;
  CHECK(156, read_line(expected_output_file, line, &(String){8, 7, "/// @@ "}, &(_Bool211)) )
  if (!_Bool211) {
    CHECK(157, file_error(name, line) )
  }
  CHECK(158, test_from_file(name) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_from_file(String* name);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_from_file = "test-from-file";
#define LUMI_FUNC_NAME _func_name_test_from_file
Returncode test_from_file(String* name) {
  String* line = &(String){1024, 0, (char[1024]){0}};
  String* subname = &(String){1024, 0, (char[1024]){0}};
  CHECK(163, String_copy(subname, &(String){6, 5, "start"}))
  if (had_test_error) {
    while (true) {
      Bool _Bool212;
      CHECK(166, read_line(input_file, line, &(String){7, 6, "## @@ "}, &(_Bool212)) )
      if (!(!_Bool212)) break;
    }
    while (true) {
      Bool _Bool213;
      CHECK(168, read_line(expected_output_file, line, &(String){8, 7, "/// @@ "}, &(_Bool213)) )
      if (!(!_Bool213)) break;
    }
  }
  had_test_error = true;
  Bool _Bool214;
  CHECK(170, read_line(input_file, line, NULL, &(_Bool214)) )
  Bool _Bool215;
  CHECK(171, String_equal(line, name, &(_Bool215)) )
  if (!_Bool215) {
    CHECK(172, file_error(name, line) )
  }
  Bool _Bool216;
  CHECK(173, read_line(expected_output_file, line, NULL, &(_Bool216)) )
  Bool _Bool217;
  CHECK(174, String_equal(line, name, &(_Bool217)) )
  if (!_Bool217) {
    CHECK(175, file_error(name, line) )
  }
  CHECK(176, File_write(actual_output_file, &(String){8, 7, "/// @@ "}) )
  CHECK(177, File_write(actual_output_file, name) )
  CHECK(178, File_write(actual_output_file, &(String){2, 1, "\n"}) )
  
  String* input = &(String){4096, 0, (char[4096]){0}};
  String* second_file_input = &(String){1024, 0, (char[1024]){0}};
  String* expected = &(String){16384, 0, (char[16384]){0}};
  Bool _Bool218;
  CHECK(183, read_line(input_file, line, &(String){6, 5, "## @ "}, &(_Bool218)) )
  if (!_Bool218) {
    CHECK(184, file_error(name, line) )
  }
  Bool _Bool219;
  CHECK(185, read_line(expected_output_file, line, &(String){7, 6, "/// @ "}, &(_Bool219)) )
  if (!_Bool219) {
    CHECK(186, file_error(name, line) )
  }
  
  Char type_char = '\0';
  Bool is_error_test = false;
  Bool append_newline = false;
  Bool is_test = false;
  tests_passed = true;
  while (true) {
    String* second_input = NULL;
    CHECK(195, File_getc(input_file, &(type_char)) )
    append_newline = type_char != 'f';
    if (!append_newline) {
      CHECK(198, File_getc(input_file, &(type_char)) )
    }
    is_error_test = type_char == 'e';
    if (is_error_test) {
      CHECK(201, File_getc(input_file, &(type_char)) )
    }
    is_test = type_char == 't';
    if (is_test) {
      CHECK(204, File_getc(input_file, &(type_char)) )
      second_input = second_file_input;
    }
    if (type_char != 'g' && type_char != 'c') {
      CHECK(207, file_error(name, subname) )
    }
    Char _Char220;
    CHECK(208, File_getc(input_file, &(_Char220)) )
    if (_Char220 != ' ') {
      CHECK(209, file_error(name, subname) )
    }
    Bool _Bool221;
    CHECK(210, read_line(input_file, subname, NULL, &(_Bool221)) )
    Bool _Bool222;
    CHECK(211, read_line(expected_output_file, line, NULL, &(_Bool222)) )
    Bool _Bool223;
    CHECK(212, String_equal(line, subname, &(_Bool223)) )
    if (!_Bool223) {
      CHECK(213, file_error(name, subname) )
    }
    CHECK(214, File_write(actual_output_file, &(String){7, 6, "/// @ "}) )
    CHECK(215, File_write(actual_output_file, subname) )
    CHECK(216, File_write(actual_output_file, &(String){2, 1, "\n"}) )
    
    CHECK(218, read_data(input_file, input, &(String){5, 4, "## @"}) )
    if (is_test) {
      Char _Char224;
      CHECK(220, File_getc(input_file, &(_Char224)) )
      if (_Char224 != '-') {
        CHECK(221, file_error(name, subname) )
      }
      Char _Char225;
      CHECK(222, File_getc(input_file, &(_Char225)) )
      CHECK(223, read_data(input_file, second_file_input, &(String){5, 4, "## @"}) )
    }
    CHECK(224, read_data(expected_output_file, expected, &(String){6, 5, "/// @"}) )
    if (append_newline) {
      CHECK(226, String_append(input, '\n') )
      if (is_test) {
        CHECK(228, String_append(second_file_input, '\n') )
      }
    }
    if (type_char == 'c') {
      if (is_error_test) {
        CHECK(231, test_code_error(input, expected) )
      }
      else {
        CHECK(233, test_code(input, expected) )
      }
    }
    else {
      if (is_error_test) {
        CHECK(236, test_global_scope_error(input, second_input, expected, is_test) )
      }
      else {
        CHECK(239, test_global_scope(input, second_input, expected, is_test) )
      }
    }
    
    Char _Char226;
    CHECK(242, File_getc(expected_output_file, &(_Char226)) )
    Char _Char227;
    CHECK(243, File_getc(input_file, &(_Char227)) )
    if (!(_Char227 == ' ')) break;
  }
  
  Char _Char228;
  CHECK(245, File_getc(expected_output_file, &(_Char228)) )
  Char _Char229;
  CHECK(246, File_getc(input_file, &(_Char229)) )
  if (_Char229 == EOF) {
    Char _Char230;
    CHECK(247, File_getc(expected_output_file, &(_Char230)) )
    if (_Char230 != EOF) {
      CHECK(248, file_error(name, subname) )
    }
    CHECK(249, File_write(actual_output_file, &(String){7, 6, "/// @\n"}) )
    CHECK(250, File_close(input_file) )
    CHECK(251, File_close(expected_output_file) )
    CHECK(252, File_close(actual_output_file) )
  }
  
  had_test_error = false;
  TEST_ASSERT(255, tests_passed)
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode read_line(File* file, String* line, String* prefix, Bool* found_prefix);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_read_line = "read-line";
#define LUMI_FUNC_NAME _func_name_read_line
Returncode read_line(File* file, String* line, String* prefix, Bool* found_prefix) {
  CHECK(259, String_clear(line) )
  (*found_prefix) = false;
  Char ch = '\0';
  while (true) {
    CHECK(263, File_getc(file, &(ch)) )
    if (!(ch != EOF && ch != '\n')) break;
    CHECK(265, String_append(line, ch) )
    if (NULL != prefix &&  ! (*found_prefix)) {
      Bool _Bool231;
      CHECK(267, String_equal(line, prefix, &(_Bool231)) )
      if (_Bool231) {
        (*found_prefix) = true;
        return OK;
      }
    }
  }
  if (ch == EOF && line->length == 0) {
    RAISE(271)
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode read_data(File* file, String* data, String* prefix);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_read_data = "read-data";
#define LUMI_FUNC_NAME _func_name_read_data
Returncode read_data(File* file, String* data, String* prefix) {
  CHECK(275, String_clear(data) )
  String* line = &(String){1024, 0, (char[1024]){0}};
  while (true) {
    Bool _Bool232;
    CHECK(278, read_line(file, line, prefix, &(_Bool232)) )
    if (!(!_Bool232)) break;
    if (data->length > 0) {
      CHECK(280, String_append(data, '\n') )
    }
    CHECK(281, String_concat(data, line) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode file_error(String* name, String* subname);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_file_error = "file-error";
#define LUMI_FUNC_NAME _func_name_file_error
Returncode file_error(String* name, String* subname) {
  CHECK(285, Sys_print_raw(sys, &(String){23, 22, "file format error in ["}) )
  CHECK(286, Sys_print_raw(sys, name) )
  if (NULL != subname) {
    CHECK(288, Sys_print_raw(sys, &(String){6, 5, "] / ["}) )
    CHECK(289, Sys_print_raw(sys, subname) )
  }
  CHECK(290, Sys_print(sys, &(String){2, 1, "]"}) )
  RAISE(291)
}
#undef LUMI_FUNC_NAME
#endif


/* List tests */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_list();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_list = "test-list";
#define LUMI_FUNC_NAME _func_name_test_list
Returncode test_list() {
  List* list = &(List){NULL, NULL};
  String* _String233;
  CHECK(297, List_pop(list, (void**)&(_String233)) )
  TEST_ASSERT(297, !(NULL != _String233))
  String* _String234;
  CHECK(298, string_new_copy(&(String){7, 6, "value1"}, &(_String234)) )
  CHECK(298, List_add(list, _String234) )
  String* _String235;
  CHECK(299, string_new_copy(&(String){7, 6, "value2"}, &(_String235)) )
  CHECK(299, List_add(list, _String235) )
  String* _String236;
  CHECK(300, string_new_copy(&(String){7, 6, "value3"}, &(_String236)) )
  CHECK(300, List_add(list, _String236) )
  String* _String237;
  CHECK(301, List_pop(list, (void**)&(_String237)) )
  CHECK(301, f_assert_string(&(String){7, 6, "value1"}, _String237) )
  String* _String238;
  CHECK(302, List_pop(list, (void**)&(_String238)) )
  CHECK(302, f_assert_string(&(String){7, 6, "value2"}, _String238) )
  String* _String239;
  CHECK(303, List_pop(list, (void**)&(_String239)) )
  CHECK(303, f_assert_string(&(String){7, 6, "value3"}, _String239) )
  String* _String240;
  CHECK(304, List_pop(list, (void**)&(_String240)) )
  TEST_ASSERT(304, !(NULL != _String240))
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* NameMap tests */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_name_map();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_name_map = "test-name-map";
#define LUMI_FUNC_NAME _func_name_test_name_map
Returncode test_name_map() {
  NameMap* map = &(NameMap){NULL, NULL};
  String* _String241;
  CHECK(310, NameMap_find(map, &(String){6, 5, "name1"}, (void**)&(_String241)) )
  TEST_ASSERT(310, !(NULL != _String241))
  CHECK(311, NameMap_add(map, &(String){6, 5, "name1"}, &(String){7, 6, "value1"}) )
  String* _String242;
  CHECK(312, NameMap_find(map, &(String){6, 5, "name1"}, (void**)&(_String242)) )
  CHECK(312, f_assert_string(&(String){7, 6, "value1"}, _String242) )
  String* _String243;
  CHECK(313, NameMap_find(map, &(String){6, 5, "name2"}, (void**)&(_String243)) )
  TEST_ASSERT(313, !(NULL != _String243))
  CHECK(314, NameMap_add(map, &(String){6, 5, "name2"}, &(String){7, 6, "value2"}) )
  String* _String244;
  CHECK(315, NameMap_find(map, &(String){6, 5, "name1"}, (void**)&(_String244)) )
  CHECK(315, f_assert_string(&(String){7, 6, "value1"}, _String244) )
  String* _String245;
  CHECK(316, NameMap_find(map, &(String){6, 5, "name2"}, (void**)&(_String245)) )
  CHECK(316, f_assert_string(&(String){7, 6, "value2"}, _String245) )
  CHECK(317, NameMap_update_or_add(map, &(String){6, 5, "name3"}, &(String){7, 6, "value3"}) )
  String* _String246;
  CHECK(318, NameMap_find(map, &(String){6, 5, "name3"}, (void**)&(_String246)) )
  CHECK(318, f_assert_string(&(String){7, 6, "value3"}, _String246) )
  CHECK(319, NameMap_update_or_add(map, &(String){6, 5, "name2"}, &(String){8, 7, "value2x"}) )
  String* _String247;
  CHECK(320, NameMap_find(map, &(String){6, 5, "name2"}, (void**)&(_String247)) )
  CHECK(320, f_assert_string(&(String){8, 7, "value2x"}, _String247) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* Illegal call tests */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode test_illegal_call();
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_test_illegal_call = "test-illegal-call";
#define LUMI_FUNC_NAME _func_name_test_illegal_call
Returncode test_illegal_call() {
  Argument* arg = &(Argument){Argument__dtl, NULL, 0, 0, false, false};
  arg->_base._dtl = Argument__dtl;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    DeclarationArgument* _DeclarationArgument248;
    CHECK(326, (arg)->_base._dtl[5](arg, &(_DeclarationArgument248)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(326)
  } while (false);
  _trace_stream = stdout;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    Char _Char249;
    CHECK(327, (arg)->_base._dtl[6](arg, NULL, &(_Char249)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(327)
  } while (false);
  _trace_stream = stdout;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    TypeInstance* _TypeInstance250;
    CHECK(328, (arg)->_base._dtl[7](arg, &(_TypeInstance250)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(328)
  } while (false);
  _trace_stream = stdout;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    SyntaxTreeVariable* _SyntaxTreeVariable251;
    CHECK(329, (arg)->_base._dtl[9](arg, &(_SyntaxTreeVariable251)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(329)
  } while (false);
  _trace_stream = stdout;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    Expression* _Expression252;
    CHECK(330, (arg)->_base._dtl[10](arg, &(_Expression252)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(330)
  } while (false);
  _trace_stream = stdout;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(331, (arg)->_base._dtl[11](arg) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(331)
  } while (false);
  _trace_stream = stdout;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(332, (arg)->_base._dtl[12](arg) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(332)
  } while (false);
  _trace_stream = stdout;
  ArgumentFactory* factory = &(ArgumentFactory){ArgumentFactory__dtl};
  factory->_dtl = ArgumentFactory__dtl;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    Argument* _Argument253;
    CHECK(334, (factory)->_dtl[0](factory, &(_Argument253)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(334)
  } while (false);
  _trace_stream = stdout;
  SyntaxTreeBranch* branch = &(SyntaxTreeBranch){SyntaxTreeBranch__dtl, NULL, 0, 0, NULL};
  branch->_base._dtl = SyntaxTreeBranch__dtl;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    Char _Char254;
    CHECK(336, (branch)->_base._dtl[6](branch, NULL, &(_Char254)) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(336)
  } while (false);
  _trace_stream = stdout;
  SyntaxTreeNode* node = &(SyntaxTreeNode){SyntaxTreeNode__dtl, NULL, 0};
  node->_dtl = SyntaxTreeNode__dtl;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(338, (node)->_dtl[4](node) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(338)
  } while (false);
  _trace_stream = stdout;
  TypeData* _TypeData255;
  CHECK(339, (node)->_dtl[0](node, &(_TypeData255)) )
  TEST_ASSERT(339, !(NULL != _TypeData255))
  NodeAction* action = &(NodeAction){NodeAction__dtl};
  action->_dtl = NodeAction__dtl;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(341, (action)->_dtl[0](action, NULL) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(341)
  } while (false);
  _trace_stream = stdout;
  SyntaxTreeRoot* root = &(SyntaxTreeRoot){SyntaxTreeRoot__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  root->_base._base._base._base._dtl = SyntaxTreeRoot__dtl;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(343, (root)->_base._base._base._base._dtl[1](root) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(343)
  } while (false);
  _trace_stream = stdout;
  TypeWriter* tw = &(TypeWriter){TypeWriter__dtl};
  tw->_dtl = TypeWriter__dtl;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(345, (tw)->_dtl[0](tw, NULL) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(345)
  } while (false);
  _trace_stream = stdout;
  _trace_stream = NULL;
  do {
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(346, write_cname(NULL) );
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    _trace_stream = stdout;
    TEST_FAIL(346)
  } while (false);
  _trace_stream = stdout;
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
#include "tests/expression-tests.c"
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
