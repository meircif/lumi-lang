#include "lumi.5.h"

/*traceback*/
#define CRAISE(message) { \
  LUMI_C_trace_print(__LINE__, LUMI_FUNC_NAME, message); \
  return ERR; }
#define CCHECK(err) { \
  Returncode LUMI_cerr = err; \
  if (LUMI_cerr != OK) return LUMI_cerr; }
#define CHECK_NOT_NULL(ref) \
  if (ref == NULL) { CRAISE(LUMI_error_messages.empty_object.str); }

char* LUMI_raise_format = "Error raised in %s:%d %s()\n";
char* LUMI_assert_format = "Assert failed in %s:%d %s()\n";
char* LUMI_traceline_format = "  called from %s:%d %s()\n";
FILE* LUMI_trace_stream = NULL;
int LUMI_trace_ignore_count = 0;
char* LUMI_expected_error = NULL;
int LUMI_expected_error_trace_ignore_count = 0;
Generic_Type_Dynamic* dynamic_Void = NULL;

Sys* sys = NULL;
Ref_Manager* sys_Refman = NULL;
int Lumi_empty_int = 0;

#define ERROR_MESAGE(field, message) {message, sizeof(message) - 1}

Error_Messages LUMI_error_messages = {
  ERROR_MESAGE(empty_object, "empty object used"),
  ERROR_MESAGE(outdated_weak_reference, "outdated weak reference used"),
  ERROR_MESAGE(
      object_memory, "insufficient memory for object dynamic allocation"),
  ERROR_MESAGE(managed_object_memory, "insufficient memory for managed object"),
  ERROR_MESAGE(
      empty_base_output, "non empty base class given as output argument"),
  ERROR_MESAGE(slice_index, "slice index out of bounds"),
  ERROR_MESAGE(string_too_long, "string too long"),
  ERROR_MESAGE(file_not_opened, "file not opened"),
  ERROR_MESAGE(file_write_failed, "file write failed")
};

enum {
  LUMI_DEBUG_NOTHING = 0,
  LUMI_DEBUG_FAIL,
  LUMI_DEBUG_SUCCESS
};
int lumi_debug_value = LUMI_DEBUG_NOTHING;

void LUMI_trace_print(
    char const* format,
    char const* filename,
    int line,
    char const* funcname,
    char const* message,
    int message_length) {
  if (LUMI_trace_ignore_count == 0) {
    if (message != NULL) {
      fprintf(
          LUMI_trace_stream,
          "Error: %.*s\n  ",
          message_length,
          message);
    }
    fprintf(LUMI_trace_stream, format, filename, line, funcname);
  }
  else if (LUMI_expected_error != NULL &&
      LUMI_expected_error_trace_ignore_count == LUMI_trace_ignore_count &&
      format != LUMI_traceline_format) {
    int n;
    if (message == NULL) {
      LUMI_expected_error = NULL;
      if (LUMI_trace_ignore_count == 1) {
        fprintf(
            LUMI_trace_stream,
            "Assert failed: error with no message raised\n  ");
      }
      return;
    }
    for (n = 0; n <= message_length; ++n) {
      if (((n == message_length)? '\0': message[n]) !=
          LUMI_expected_error[n]) {
        LUMI_expected_error = NULL;
        if (LUMI_trace_ignore_count == 1) {
          fprintf(
              LUMI_trace_stream,
              "Assert failed: unexpected error message \"%.*s\"\n  ",
              message_length,
              message);
        }
        return;
      }
    }
  }
}

/*like strnlen*/
int cstring_length(char* cstring, int max_length) {
  int length = 0;
  while (cstring[length] != '\0' && length < max_length) {
    ++length;
  }
  return length;
}

void LUMI_C_trace_print(int line, char const* funcname, char* message) {
  LUMI_trace_print(
      LUMI_raise_format,
      "builtin",
      line,
      funcname,
      message,
      cstring_length(message, 255));
}

/*main*/
Returncode LUMI_user_main(void);
int set_sys(int argc, char* argv[]);
#define SET_SYS err = set_sys(argc, argv); if (err != OK) return err;

int LUMI_main(int argc, char* argv[]) {
  Returncode err;
  LUMI_trace_stream = stderr;
  SET_SYS
  err = LUMI_user_main();
  if (err != OK) {
    fprintf(stderr, "  called from executable start\n");
  }
  return err;
}

/*tests*/
int LUMI_test_main(int argc, char* argv[]) {
  Returncode err;
  LUMI_trace_stream = stdout;
  SET_SYS
  printf("Running tests:\n");
  err = LUMI_user_main();
  if (err == OK) {
    printf("Tests passed\n");
  }
  else {
    printf("Tests failed\n");
    return ERR;
  }
  return OK;
}

Bool LUMI_run_test(char* test_name, Func test_func) {
  Returncode err;
  printf("testing %s... ", test_name);
  fflush(stdout);
  err = test_func();
  if (err == OK) {
    printf("OK\n");
    return true;
  }
  return false;
}

int calc_coverage(File_Coverage* files_coverage, int files_number) {
  int n;
  int all_lines = 0;
  int covered_lines = 0;
  for (n = 0; n < files_number; ++n) {
    int line;
    for (line = 0; line < files_coverage[n].lines_number; ++line) {
      if (files_coverage[n].line_count[line] >= 0) {
        ++all_lines;
      }
      if (files_coverage[n].line_count[line] > 0) {
        ++covered_lines;
      }
    }
  }
  return covered_lines * 100 / all_lines;
}

void make_coverage_xml(File_Coverage* files_coverage, int files_number) {
  int n;
  FILE* xml = NULL;
  xml = fopen("cobertura.xml", "w");
  if (xml == NULL) {
    return;
  }
  fputs("<?xml version=\"1.0\" ?>\n", xml);
  fputs(
    "<!DOCTYPE coverage SYSTEM 'https://raw.githubusercontent.com/cobertura/"
    "cobertura/master/cobertura/src/site/htdocs/xml/coverage-loose.dtd'>\n",
    xml);
  fputs("<coverage timestamp=\"0\" version=\"lumi 0.0.5\">\n", xml);
  fputs(" <packages>\n", xml);

  for (n = 0; n < files_number; ++n) {
    int line;
    fputs("  <package name=\"\">\n", xml);
    fputs("   <classes>\n", xml);
    fprintf(
      xml,
      "    <class name=\"%s\" filename=\"%s\">\n",
      files_coverage[n].filename,
      files_coverage[n].filename);
    fputs("     <methods/>\n", xml);
    fputs("     <lines>\n", xml);

    for (line = 0; line < files_coverage[n].lines_number; ++line) {
      if (files_coverage[n].line_count[line] >= 0) {
        fprintf(
          xml,
          "      <line branch=\"false\" hits=\"%d\" number=\"%d\"/>\n",
          files_coverage[n].line_count[line],
          line);
      }
    }

    fputs("     </lines>\n", xml);
    fputs("    </class>\n", xml);
    fputs("   </classes>\n", xml);
    fputs("  </package>\n", xml);
  }

  fputs(" </packages>\n", xml);
  fputs("</coverage>\n", xml);
  fclose(xml);
}

Bool LUMI_test_coverage(File_Coverage* files_coverage, int files_number) {
  int n;
  int coverage;
  Bool generate_xml = false;
  if (sys->argv != NULL && sys->argv_Refman->value != NULL &&
      sys->argv_Length > 1 && sys->argv_String_length[1] > 1) {
    char* arg = sys->argv + sys->argv_Value_length;
    generate_xml = arg[0] == '-' && arg[1] == 'x';
  }
  printf("testing code coverage... ");
  coverage = calc_coverage(files_coverage, files_number);
  if (coverage == 100) {
    printf("100%%\n");
    if (generate_xml) {
      make_coverage_xml(files_coverage, files_number);
    }
    return true;
  }

  printf("%d%% - failed, lines not covered:\n", coverage);
  for (n = 0; n < files_number; ++n) {
    coverage = calc_coverage(files_coverage + n, 1);
    if (coverage < 100) {
      int line;
      int first_uncovered;
      Bool prev_uncovered = false;
      printf("  %s(%d%%):", files_coverage[n].filename, coverage);
      for (line = 0; line < files_coverage[n].lines_number; ++line) {
        if (files_coverage[n].line_count[line] == 0) {
          if (!prev_uncovered) {
            first_uncovered = line;
            prev_uncovered = true;
          }
        }
        else if (prev_uncovered) {
          printf(" %d", first_uncovered);
          if (first_uncovered < line - 1) {
            printf("-%d", line - 1);
          }
          prev_uncovered = false;
        }
      }
      printf("\n");
    }
  }
  if (generate_xml) {
    make_coverage_xml(files_coverage, files_number);
  }
  return false;
}

/*reference counting*/
Returncode new_Mock(Bool*);
Returncode delete_Mock(Ref);

void* LUMI_alloc(size_t size) {
  Bool allocate_success = true;
  IGNORE_ERRORS( new_Mock(&allocate_success); )
  if (allocate_success) {
    return calloc(1, size);
  }
  return NULL;
}

Ref_Manager* LUMI_new_ref(void* value) {
  Ref_Manager* ref = NULL;
  Bool allocate_success = true;
  IGNORE_ERRORS( new_Mock(&allocate_success); )
  if (allocate_success) {
    ref = malloc(sizeof(Ref_Manager));
    if (ref != NULL) {
      ref->count = 1;
      ref->value = value;
      ref->ref = value;
    }
  }
  return ref;
}

void LUMI_inc_ref(Ref_Manager* ref) {
  if (ref != NULL) {
    ++ref->count;
  }
}

void dec_ref(Ref_Manager* ref) {
  --ref->count;
  if (ref->count == 0) {
    IGNORE_ERRORS( delete_Mock(ref->ref); )
    free(ref);
  }
}

void LUMI_dec_ref(Ref_Manager* ref) {
  if (ref != NULL) {
    dec_ref(ref);
  }
}

void LUMI_var_dec_ref(Ref_Manager* ref) {
  if (ref != NULL) {
    ref->value = NULL;
    dec_ref(ref);
  }
}

void LUMI_owner_dec_ref(Ref_Manager* ref) {
  if (ref != NULL) {
    free(ref->value);
    ref->value = NULL;
    dec_ref(ref);
  }
}


/*Files*/
#define LUMI_FUNC_NAME "open-file"
Returncode open_file(
    File** file,
    char* name, int name_max_length, int name_length,
    char* mode) {
  FILE* new_fobj = NULL;
  if (lumi_debug_value == LUMI_DEBUG_NOTHING) {
    CCHECK(file_close(*file));
  }
  *file = NULL;
  CHECK_NOT_NULL(name)
  if (lumi_debug_value != LUMI_DEBUG_SUCCESS) {
    if (lumi_debug_value != LUMI_DEBUG_FAIL) {
      new_fobj = fopen(name, mode);
    }
    if (new_fobj == NULL) {
      CRAISE("open file failed")
    }
  }
  if (lumi_debug_value == LUMI_DEBUG_FAIL) printf("open_file fail BUG!\n");
  *file = LUMI_alloc(sizeof(File));
  if (*file == NULL) {
    if (lumi_debug_value != LUMI_DEBUG_SUCCESS) {
      fclose(new_fobj);
    }
    CRAISE(LUMI_error_messages.object_memory.str)
  }
  (*file)->fobj = new_fobj;
  return OK;
}
#undef LUMI_FUNC_NAME

Returncode file_open_read(
    char* name, int name_max_length, int *name_length, File** file) {
  return open_file(file, name, name_max_length, *name_length, "r");
}

Returncode file_open_write(
    char* name, int name_max_length, int *name_length, File** file) {
  return open_file(
    file, name, name_max_length, *name_length, "w");
}

#define LUMI_FUNC_NAME "file-close"
Returncode file_close(File* file) {
  if (lumi_debug_value == LUMI_DEBUG_FAIL ||
      (file != NULL && file->fobj != NULL)) {
    if (lumi_debug_value == LUMI_DEBUG_FAIL || fclose(file->fobj) != 0) {
      CRAISE("close file failed")
    }
    file->fobj = NULL;
  }
  return OK;
}
#undef LUMI_FUNC_NAME

void File_Del(File* self) {
  if (self != NULL && self->fobj != NULL) {
    fclose(self->fobj);
  }
}
Generic_Type_Dynamic File_dynamic = { (Dynamic_Del)File_Del };

Bool getc_is_eof(int get, char* ch) {
  if (get == EOF) {
    return true;
  }
  else {
    *ch = get;
    return false;
  }
}

#define LUMI_FUNC_NAME "File.getc"
Returncode File_getc(File* file, Char* out_char, Bool* is_eof) {
  CHECK_NOT_NULL(file)
  if (file->fobj == NULL) CRAISE(LUMI_error_messages.file_not_opened.str)
  *is_eof = getc_is_eof(getc(file->fobj), out_char);
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "File.putc"
Returncode File_putc(File* file, Char ch) {
  int res = '\0';
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    CHECK_NOT_NULL(file)
    if (file->fobj == NULL) CRAISE(LUMI_error_messages.file_not_opened.str)
    res = putc(ch, file->fobj);
  }
  if (res != ch) {
    CRAISE(LUMI_error_messages.file_write_failed.str)
  }
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "File.write"
Returncode File_write(File* file, char* text, int text_length) {
  int n, ch, res=0;
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    CHECK_NOT_NULL(file)
    if (file->fobj == NULL) CRAISE(LUMI_error_messages.file_not_opened.str)
  }
  CHECK_NOT_NULL(text)
  for (n = 0; n < text_length; ++n) {
    ch = text[n];
    if (lumi_debug_value != LUMI_DEBUG_FAIL) {
      res = putc(ch, file->fobj);
    }
    if (ch != res) {
      CRAISE(LUMI_error_messages.file_write_failed.str)
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME

/*Arrays*/
#define LUMI_FUNC_NAME "Array.length"
Returncode Array_length(void* self, int length, Int* length_out) {
  CHECK_NOT_NULL(self)
  *length_out = length;
  return OK;
}
#undef LUMI_FUNC_NAME

/*Strings*/
#define LUMI_FUNC_NAME "String.length"
Returncode String_length(
    char* self, int max_length, int *length, Int* length_out) {
  CHECK_NOT_NULL(self)
  *length_out = *length;
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.max-length"
Returncode String_max_length(
    char* self, int max_length, int *length, Int* max_length_out) {
  CHECK_NOT_NULL(self)
  *max_length_out = max_length;
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.clear"
Returncode String_clear(char* self, int max_length, int* length) {
  CHECK_NOT_NULL(self)
  *length = 0;
  return OK;
}
#undef LUMI_FUNC_NAME

Returncode String_equal(
    char* self, int max_length, int *length,
    char* other, int other_length,
    Bool* out_equal) {
  if (self == other) {
    *out_equal = self == NULL || *length == other_length;
    return OK;
  }
  if (self == NULL || other == NULL) {
    *out_equal = false;
    return OK;
  }
  if (*length != other_length) {
    *out_equal = false;
    return OK;
  }
  *out_equal = strncmp(self, other, *length) == 0;
  return OK;
}

#define LUMI_FUNC_NAME "String.get"
Returncode String_get(
    char* self, int max_length, int *length, Int index, Char* out_char) {
  CHECK_NOT_NULL(self)
  if (index < 0 || index >= *length) {
    CRAISE(LUMI_error_messages.slice_index.str)
  }
  *out_char = self[index];
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.set"
Returncode String_set(
    char* self, int max_length, int *length, Int index, Char ch) {
  CHECK_NOT_NULL(self)
  if (index < 0 || index >= *length) {
    CRAISE(LUMI_error_messages.slice_index.str)
  }
  self[index] = ch;
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.append"
Returncode String_append(char* self, int max_length, int* length, Char ch) {
  CHECK_NOT_NULL(self)
  if (*length + 1 >= max_length) {
    CRAISE(LUMI_error_messages.string_too_long.str)
  }
  self[*length] = ch;
  ++(*length);
  self[*length] = '\0';
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "Int.str"
Returncode Int_str(Int value, char* str, int str_max_length, int* str_length) {
  Bool is_neg;
  int abs;
  int swap;
  char* next;
  char* last;
  CHECK_NOT_NULL(str)
  is_neg = value < 0;
  abs = value;
  if (is_neg) {
    abs = -value;
  }
  swap = 0;
  *str_length = is_neg;
  do {
    swap *= 10;
    swap += abs % 10;
    abs /= 10;
    if (str_max_length <= *str_length + 1) {
      *str_length = 0;
      CRAISE(LUMI_error_messages.string_too_long.str)
    }
    ++*str_length;
  } while (abs > 0);
  next = str;
  if (is_neg) {
    *next = '-';
    ++next;
  }
  last = str + *str_length;
  while (next < last) {
    *next = '0' + swap % 10;
    ++next;
    swap /= 10;
  }
  *last = '\0';
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.copy"
Returncode String_copy(
    char* self, int max_length, int* length, char* source, int source_length) {
  CHECK_NOT_NULL(self)
  if (source == NULL || self == source) {
    return OK;
  }
  if (source_length >= max_length) {
    CRAISE(LUMI_error_messages.string_too_long.str)
  }
  *length = source_length;
  memcpy(self, source, source_length);
  self[source_length] = '\0';
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.concat"
Returncode String_concat(
    char* self, int max_length, int* length, char* ext, int ext_length) {
  CHECK_NOT_NULL(self)
  if (ext == NULL) {
    return OK;
  }
  if (*length + ext_length >= max_length) {
    CRAISE(LUMI_error_messages.string_too_long.str)
  }
  memcpy(self + *length, ext, ext_length);
  *length += ext_length;
  self[*length] = '\0';
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.concat-int"
Returncode String_concat_int(
    char* self, int max_length, int* length, Int num) {
  int added_length = 0;
  CHECK_NOT_NULL(self)
  CCHECK(Int_str(num, self + *length, max_length - *length, &added_length));
  *length += added_length;
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.find"
Returncode String_find(
    char* self, int max_length, int *length,
    char* pattern, int pattern_length,
    Int* out_index) {
  int n;
  CHECK_NOT_NULL(self)
  if (pattern == NULL) {
    *out_index = 0;
    return OK;
  }
  for (n = 0; n <= *length - pattern_length; ++n) {
    if (strncmp(self + n, pattern, pattern_length) == 0) {
      *out_index = n;
      return OK;
    }
  }
  *out_index = *length;
  return OK;
}
#undef LUMI_FUNC_NAME

Returncode String_has(
    char* self, int max_length, int *length, Char ch, Bool* found) {
  int n;
  if (self == NULL) {
    *found = false;
    return OK;
  }
  for (n = 0; n < *length; ++n) {
    if (self[n] == ch) {
      *found = true;
      return OK;
    }
  }
  *found = false;
  return OK;
}

/*system*/
int set_sys(int argc, char* argv[]) {
  int arg;
  sys = LUMI_alloc(sizeof(Sys));
  sys_Refman = LUMI_new_ref(sys);
  if (sys != NULL) {
    int max_length = 0;
    sys->stdout_Cname = LUMI_alloc(sizeof(File));
    sys->stdout_Cname_Refman = LUMI_new_ref(sys->stdout_Cname);
    sys->stdin_Cname = LUMI_alloc(sizeof(File));
    sys->stdin_Cname_Refman = LUMI_new_ref(sys->stdin_Cname);
    sys->stderr_Cname = LUMI_alloc(sizeof(File));
    sys->stderr_Cname_Refman = LUMI_new_ref(sys->stderr_Cname);
    sys->argv_Length = argc;
    sys->argv_Value_length = 0;
    sys->argv_String_length = LUMI_alloc(sizeof(int) * argc);
    for (arg = 0; arg < argc; ++arg) {
      int length = cstring_length(argv[arg], 1024);
      if (sys->argv_String_length != NULL) {
        sys->argv_String_length[arg] = length;
      }
      if (length > sys->argv_Value_length) {
        sys->argv_Value_length = length;
      }
    }
    ++sys->argv_Value_length;
    sys->argv = LUMI_alloc(sys->argv_Value_length * sys->argv_Length);
    sys->argv_Refman = LUMI_new_ref(sys->argv);
  }
  if (sys == NULL || sys_Refman == NULL || sys->argv == NULL ||
    sys->argv_Refman == NULL || sys->argv_String_length == NULL ||
    sys->stdout_Cname == NULL || sys->stdout_Cname_Refman == NULL ||
    sys->stdin_Cname == NULL || sys->stdin_Cname_Refman == NULL ||
    sys->stderr_Cname == NULL || sys->stderr_Cname_Refman == NULL) {
    fprintf(stderr, "insufficient memory\n");
    return ERR;
  }
  ++sys_Refman->count;
  ++sys->argv_Refman->count;
  ++sys->stdout_Cname_Refman->count;
  ++sys->stdin_Cname_Refman->count;
  ++sys->stderr_Cname_Refman->count;
  sys->stdout_Cname->fobj = stdout;
  sys->stdin_Cname->fobj = stdin;
  sys->stderr_Cname->fobj = stderr;
  for (arg = 0; arg < argc; ++arg) {
    strncpy(sys->argv + sys->argv_Value_length * arg, argv[arg], sys->argv_Length);
  }
  return OK;
}

void Sys_Del(Sys* self) {}
Generic_Type_Dynamic Sys_dynamic = { (Dynamic_Del)Sys_Del };

#define LUMI_FUNC_NAME "Sys.print"
Returncode Sys_print(Sys* _, char* text, int text_length) {
  int n, ch, res;
  if (text == NULL) {
    return OK;
  }
  for (n = 0; n < text_length; ++n) {
    ch = text[n];
    res = putchar(ch);
    if (ch != res) {
      CRAISE(LUMI_error_messages.file_write_failed.str)
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "Sys.println"
Returncode Sys_println(Sys* _, char* text, int text_length) {
  Sys_print(NULL, text, text_length);
  if (putchar('\n') != '\n') {
    CRAISE(LUMI_error_messages.file_write_failed.str)
  }
  return OK;
}
#undef LUMI_FUNC_NAME

Returncode Sys_getchar(Sys* _, char* out_char, Bool* is_eof) {
  *is_eof = getc_is_eof(getchar(), out_char);
  return OK;
}

#define LUMI_FUNC_NAME "Sys.getline"
Returncode Sys_getline(
    Sys* _, char* line, int line_max_length, int* line_length) {
  int ch = 0;
  CHECK_NOT_NULL(line)
  *line_length = 0;
  if (lumi_debug_value != LUMI_DEBUG_SUCCESS) {
    ch = getchar();
  }
  while (ch != EOF && ch != '\n') {
    if (*line_length + 1 >= line_max_length) {
      CRAISE(LUMI_error_messages.string_too_long.str)
    }
    line[*line_length] = ch;
    ++(*line_length);
    if (lumi_debug_value != LUMI_DEBUG_SUCCESS) {
      ch = getchar();
    }
  }
  line[*line_length] = '\0';
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "Sys.exit"
Returncode Sys_exit(Sys* _, Int status) {
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    exit(status);
  }
  CRAISE("exit failed")
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "Sys.system"
Returncode Sys_system(
    Sys* _,
    char* command, int command_max_length, int *command_length,
    Int* status) {
  int res = -1;
  CHECK_NOT_NULL(command)
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    res = system(command);
  }
  if (res == -1) {
    CRAISE("command execution failed")
  }
  *status = res;
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "Sys.getenv"
Returncode Sys_getenv(
    Sys* _,
    char* name, int name_max_length, int *name_length,
    char* value, int value_max_length, int* value_length,
    Bool* exists) {
  char* ret;
  CHECK_NOT_NULL(name)
  CHECK_NOT_NULL(value)
  ret = getenv(name);
  if (ret == NULL) {
    *exists = false;
    return OK;
  }
  *value_length = cstring_length(ret, value_max_length);
  strncpy(value, ret, *value_length);
  *exists = true;
  return OK;
}
#undef LUMI_FUNC_NAME
