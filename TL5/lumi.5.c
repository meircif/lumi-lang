#include "lumi.5.h"

/*traceback*/
#define CRAISE(message) { \
  LUMI_C_trace_print(__LINE__, LUMI_FUNC_NAME, message); \
  return ERR; }
#define CCHECK(err) if (err != OK) return err;
#define CHECK_NOT_NULL(ref) \
  if (ref == NULL) CRAISE("empty object used"); \
  if (ref##_Refman->value == NULL) CRAISE("outdated weak reference used")

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
static Array* sys_argv = NULL;
static Ref_Manager* sys_argv_Refman = NULL;

#define ERROR_MESAGE(field, message) \
  {{sizeof(message), sizeof(message) - 1, message}, \
   {1, &(LUMI_error_messages.field.str), &(LUMI_error_messages.field.str)}}

Error_Messages LUMI_error_messages = {
  ERROR_MESAGE(empty_object, "empty object used"),
  ERROR_MESAGE(outdated_weak_reference, "outdated weak reference used"),
  ERROR_MESAGE(
      object_memory, "insufficient memory for object dynamic allocation"),
  ERROR_MESAGE(managed_object_memory, "insufficient memory for managed object"),
  ERROR_MESAGE(
      empty_base_output, "non empty base class given as output argument"),
  ERROR_MESAGE(slice_index, "slice index out of bounds")
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
    String* message,
    Ref_Manager* message_refman) {
  if (LUMI_trace_ignore_count == 0) {
    if (message != NULL && message_refman->value != NULL) {
      fprintf(
          LUMI_trace_stream,
          "Error: %.*s\n  ",
          message->length,
          message->values);
    }
    fprintf(LUMI_trace_stream, format, filename, line, funcname);
  }
  else if (LUMI_expected_error != NULL &&
      LUMI_expected_error_trace_ignore_count == LUMI_trace_ignore_count &&
      format != LUMI_traceline_format) {
    int n;
    if (message == NULL || message_refman->value == NULL) {
      LUMI_expected_error = NULL;
      if (LUMI_trace_ignore_count == 1) {
        fprintf(
            LUMI_trace_stream,
            "Assert failed: error with no message raised\n  ");
      }
      return;
    }
    for (n = 0; n <= message->length; ++n) {
      if (((n == message->length)? '\0': message->values[n]) !=
          LUMI_expected_error[n]) {
        LUMI_expected_error = NULL;
        if (LUMI_trace_ignore_count == 1) {
          fprintf(
              LUMI_trace_stream,
              "Assert failed: unexpected error message \"%.*s\"\n  ",
              message->length,
              message->values);
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
  String LUMI_msg;
  Ref_Manager LUMI_msg_refman = { 1 };
  LUMI_msg.length = cstring_length(message, 255);
  LUMI_msg.max_length = LUMI_msg.length + 1;
  LUMI_msg.values = message;
  LUMI_msg_refman.value = &LUMI_msg;
  LUMI_msg_refman.ref = &LUMI_msg;
  LUMI_trace_print(
      LUMI_raise_format,
      "builtin",
      line,
      funcname,
      &LUMI_msg,
      &LUMI_msg_refman);
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
  if (sys_argv != NULL && sys_argv_Refman->value != NULL) {
    String* args_strings;
    args_strings = sys_argv->values;
    generate_xml = sys_argv->length > 1 && args_strings[1].length > 1 &&
      args_strings[1].values[0] == '-' && args_strings[1].values[1] == 'x';
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

/*helpers*/
#define LUMI_FUNC_NAME "set_cstring"
Returncode set_cstring(String* str, Ref_Manager* str_Refman) {
  CHECK_NOT_NULL(str)
  if (str->length >= str->max_length) {
    if (cstring_length(str->values, str->max_length) >= str->max_length) {
      CRAISE("string too long")
    }
  }
  else if (cstring_length(str->values, str->length + 1) > str->length) {
    str->values[str->length] = '\0';
  }
  return OK;
}
#undef LUMI_FUNC_NAME

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

Ref_Manager* LUMI_new_ref(void** value, Bool is_new) {
  Ref_Manager* ref = NULL;
  Bool allocate_success = true;
  IGNORE_ERRORS( new_Mock(&allocate_success); )
  if (allocate_success) {
    ref = malloc(sizeof(Ref_Manager));
    if (ref == NULL) {
      if (is_new) free(*value);
      *value = NULL;
    }
    else {
      ref->count = 1;
      ref->value = *value;
      ref->ref = *value;
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

/*allocations*/
String* LUMI_new_string(int length) {
  void* buff;
  String* str;
  buff = LUMI_alloc(sizeof(String) + length);
  if (buff == NULL) {
    return NULL;
  }
  str = buff;
  str->max_length = length;
  str->length = 0;
  str->values = ((char*)buff) + sizeof(String);
  return str;
}

Array* LUMI_new_array(int length, int value_size) {
  void* buff;
  Array* array;
  buff = LUMI_alloc(sizeof(Array) + length * value_size);
  if (buff == NULL) {
    return NULL;
  }
  array = buff;
  array->length = length;
  array->values = ((Byte*)buff) + sizeof(Array);
  return array;
}

Array* LUMI_new_string_array(int array_length, int string_length) {
  void* buff;
  Array* array;
  int n;
  buff = LUMI_new_array(array_length, sizeof(String) + (string_length));
  if (buff == NULL) {
    return NULL;
  }
  array = buff;
  for (n = 0; n < array_length; ++n) {
    String* str;
    str = ((String*)(array->values)) + n;
    str->max_length = string_length;
    str->length = 0;
    str->values = ((char*)(array->values)) + array_length * sizeof(String) +
      string_length * n;
  }
  return array;
}

void LUMI_set_var_string_array(
    int array_length,
    int string_length,
    Array* array,
    char* chars) {
  int n;
  for (n = 0; n < array_length; ++n) {
    String* str;
    str = ((String*)(array->values)) + n;
    str->max_length = string_length;
    str->length = 0;
    str->values = chars + n * string_length;
  }
}

/*Files*/
#define LUMI_FUNC_NAME "open-file"
Returncode open_file(
    File** file, Ref_Manager** file_Refman,
    String* name, Ref_Manager* name_Refman,
    char* mode) {
  FILE* new_fobj = NULL;
  File* new_file = NULL;
  if (lumi_debug_value == LUMI_DEBUG_NOTHING) {
    CCHECK(file_close(*file, *file_Refman));
  }
  *file = NULL;
  *file_Refman = NULL;
  CCHECK(set_cstring(name, name_Refman));
  if (lumi_debug_value != LUMI_DEBUG_SUCCESS) {
    if (lumi_debug_value != LUMI_DEBUG_FAIL) {
      new_fobj = fopen(name->values, mode);
    }
    if (new_fobj == NULL) {
      CRAISE("open file failed")
    }
  }
  if (lumi_debug_value == LUMI_DEBUG_FAIL) printf("open_file fail BUG!\n");
  new_file = LUMI_alloc(sizeof(File));
  if (new_file == NULL) {
    if (lumi_debug_value != LUMI_DEBUG_SUCCESS) {
      fclose(new_fobj);
    }
    CRAISE("insufficient memory for object dynamic allocation")
  }
  *file_Refman = LUMI_new_ref((void**)&new_file, true);
  if (*file_Refman == NULL) {
    if (lumi_debug_value != LUMI_DEBUG_SUCCESS) {
      fclose(new_fobj);
    }
    CRAISE("insufficient memory for managed object")
  }
  *file = new_file;
  (*file)->fobj = new_fobj;
  return OK;
}
#undef LUMI_FUNC_NAME

Returncode file_open_read(
    String* name, Ref_Manager* name_Refman,
    File** file, Ref_Manager** file_Refman) {
  return open_file(file, file_Refman, name, name_Refman, "r");
}

Returncode file_open_write(
    String* name, Ref_Manager* name_Refman,
    File** file, Ref_Manager** file_Refman) {
  return open_file(file, file_Refman, name, name_Refman, "w");
}

#define LUMI_FUNC_NAME "file-close"
Returncode file_close(File* file, Ref_Manager* file_Refman) {
  if (lumi_debug_value == LUMI_DEBUG_FAIL ||
      (file != NULL && file_Refman->value != NULL && file->fobj != NULL)) {
    if (lumi_debug_value == LUMI_DEBUG_FAIL ||
        fclose(file->fobj) != 0) {
      CRAISE("close file failed")
    }
    file->fobj = NULL;
  }
  LUMI_owner_dec_ref(file_Refman);
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
Returncode File_getc(
    File* file, Ref_Manager* file_Refman, Char* out_char, Bool* is_eof) {
  CHECK_NOT_NULL(file)
  if (file->fobj == NULL) CRAISE("file not opened")
  *is_eof = getc_is_eof(getc(file->fobj), out_char);
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "File.putc"
Returncode File_putc(File* file, Ref_Manager* file_Refman, Char in_char) {
  int res = '\0';
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    CHECK_NOT_NULL(file)
    if (file->fobj == NULL) CRAISE("file not opened")
    res = putc(in_char, file->fobj);
  }
  if (res != in_char) {
    CRAISE("file write failed")
  }
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "File.write"
Returncode File_write(
    File* file, Ref_Manager* file_Refman,
    String* data, Ref_Manager* data_Refman) {
  int n, ch, res=0;
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    CHECK_NOT_NULL(file)
    if (file->fobj == NULL) CRAISE("file not opened")
  }
  CHECK_NOT_NULL(data)
  for (n = 0; n < data->length; ++n) {
    ch = data->values[n];
    if (lumi_debug_value != LUMI_DEBUG_FAIL) {
      res = putc(ch, file->fobj);
    }
    if (ch != res) {
      CRAISE("file write failed")
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME

/*Strings*/
void String_Del(String* self) {}
Generic_Type_Dynamic String_dynamic = { (Dynamic_Del)String_Del };

#define LUMI_FUNC_NAME "String.clear"
Returncode String_clear(String* self, Ref_Manager* self_Refman) {
  CHECK_NOT_NULL(self)
  self->length = 0;
  return OK;
}
#undef LUMI_FUNC_NAME

Returncode String_equal(
    String* self, Ref_Manager* self_Refman,
    String* other, Ref_Manager* other_Refman,
    Bool* out_equal) {
  if ((self_Refman != NULL && self_Refman->value == NULL) ||
      (self_Refman != NULL && self_Refman->value == NULL)) {
    *out_equal = false;
    return OK;
  }
  if (self == other) {
    *out_equal = true;
    return OK;
  }
  if (self == NULL || other == NULL) {
    *out_equal = false;
    return OK;
  }
  if (self->length != other->length) {
    *out_equal = false;
    return OK;
  }
  if (strncmp(self->values, other->values, self->length) == 0) {
    *out_equal = true;
    return OK;
  }
  *out_equal = false;
  return OK;
}

#define LUMI_FUNC_NAME "String.get"
Returncode String_get(
    String* self, Ref_Manager* self_Refman,
    Int index,
    Char* out_char) {
  CHECK_NOT_NULL(self)
  if (index < 0 || index >= self->length) {
    CRAISE("slice index out of bounds")
  }
  *out_char = self->values[index];
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.append"
Returncode String_append(String* self, Ref_Manager* self_Refman, Char in_char) {
  CHECK_NOT_NULL(self)
  if (self->length == self->max_length) {
    CRAISE("string too long")
  }
  self->values[self->length] = in_char;
  ++self->length;
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "Int.str"
Returncode Int_str(Int value, String* out_str, Ref_Manager* out_str_Refman) {
  Bool is_neg;
  int abs;
  int swap;
  char* next;
  char* last;
  CHECK_NOT_NULL(out_str)
  is_neg = value < 0;
  abs = value;
  if (is_neg) {
    abs = -value;
  }
  swap = 0;
  out_str->length = is_neg;
  do {
    swap *= 10;
    swap += abs % 10;
    abs /= 10;
    if (out_str->max_length <= out_str->length) {
      out_str->length = 0;
      CRAISE("string too long")
    }
    ++out_str->length;
  } while (abs > 0);
  next = out_str->values;
  if (is_neg) {
    *next = '-';
    ++next;
  }
  last = out_str->values + out_str->length;
  while (next < last) {
    *next = '0' + swap % 10;
    ++next;
    swap /= 10;
  }
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.new"
Returncode String_new(
    String* self, Ref_Manager* self_Refman,
    String* source, Ref_Manager* source_Refman) {
  CHECK_NOT_NULL(self)
  if (source == NULL || source_Refman->value == NULL || self == source) {
    return OK;
  }
  if (source->length > self->max_length) {
    CRAISE("string too long")
  }
  self->length = source->length;
  memcpy(self->values, source->values, self->length);
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.concat"
Returncode String_concat(
    String* self, Ref_Manager* self_Refman,
    String* ext, Ref_Manager* ext_Refman) {
  CHECK_NOT_NULL(self)
  if (ext == NULL || ext_Refman->value == NULL) {
    return OK;
  }
  if (self->length + ext->length > self->max_length) {
    CRAISE("string too long")
  }
  memcpy(self->values + self->length, ext->values, ext->length);
  self->length += ext->length;
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.concat-int"
Returncode String_concat_int(String* self, Ref_Manager* self_Refman, Int num) {
  String remain;
  String* remain_ref = &remain;
  Ref_Manager remain_Refman = { 1 , NULL };
  remain_Refman.value = remain_ref;
  remain.max_length = self->max_length - self->length;
  remain.length = 0;
  remain.values = self->values + self->length;
  CCHECK(Int_str(num, remain_ref, &remain_Refman));
  self->length += remain.length;
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.find"
Returncode String_find(
    String* self, Ref_Manager* self_Refman,
    String* pattern, Ref_Manager* pattern_Refman,
    Int* out_index) {
  int n;
  CHECK_NOT_NULL(self)
  if (pattern == NULL || pattern_Refman->value == NULL) {
    *out_index = 0;
    return OK;
  }
  for (n = 0; n <= self->length - pattern->length; ++n) {
    if (strncmp(self->values + n, pattern->values, pattern->length)
        == 0) {
      *out_index = n;
      return OK;
    }
  }
  *out_index = self->length;
  return OK;
}
#undef LUMI_FUNC_NAME

Returncode String_has(
    String* self, Ref_Manager* self_Refman, Char ch, Bool* found) {
  int n;
  if (self == NULL || self_Refman->value == NULL) {
    *found = false;
    return OK;
  }
  for (n = 0; n < self->length; ++n) {
    if (self->values[n] == ch) {
      *found = true;
      return OK;
    }
  }
  *found = false;
  return OK;
}

/*system*/
int set_sys(int argc, char* argv[]) {
  String* args_strings;
  int arg;
  sys = LUMI_alloc(sizeof(Sys));
  sys_Refman = LUMI_new_ref((void**)&sys, true);
  sys_argv = LUMI_new_array(argc, sizeof(String));
  sys_argv_Refman = LUMI_new_ref((void**)&sys_argv, true);
  if (sys != NULL) {
    sys->stdout_Cname = LUMI_alloc(sizeof(File));
    sys->stdout_Cname_Refman = LUMI_new_ref((void**)&(sys->stdout_Cname), true);
    sys->stdin_Cname = LUMI_alloc(sizeof(File));
    sys->stdin_Cname_Refman = LUMI_new_ref((void**)&(sys->stdin_Cname), true);
    sys->stderr_Cname = LUMI_alloc(sizeof(File));
    sys->stderr_Cname_Refman = LUMI_new_ref((void**)&(sys->stderr_Cname), true);
  }
  if (sys == NULL || sys_Refman == NULL ||
    sys_argv == NULL || sys_argv_Refman == NULL ||
    sys->stdout_Cname == NULL || sys->stdout_Cname_Refman == NULL ||
    sys->stdin_Cname == NULL || sys->stdin_Cname_Refman == NULL ||
    sys->stderr_Cname == NULL || sys->stderr_Cname_Refman == NULL) {
    fprintf(stderr, "insufficient memory\n");
    return ERR;
  }
  ++sys_Refman->count;
  ++sys_argv_Refman->count;
  ++sys->stdout_Cname_Refman->count;
  ++sys->stdin_Cname_Refman->count;
  ++sys->stderr_Cname_Refman->count;
  sys->stdout_Cname->fobj = stdout;
  sys->stdin_Cname->fobj = stdin;
  sys->stderr_Cname->fobj = stderr;
  sys->argv = sys_argv;
  sys->argv_Refman = sys_argv_Refman;
  args_strings = sys_argv->values;
  for (arg = 0; arg < argc; ++arg) {
    args_strings[arg].values = argv[arg];
    args_strings[arg].length = cstring_length(argv[arg], 1024);
    args_strings[arg].max_length = args_strings[arg].length + 1;
    args_strings[arg].values[args_strings[arg].length] = '\0';
  }
  return OK;
}

void Sys_Del(Sys* self) {}
Generic_Type_Dynamic Sys_dynamic = { (Dynamic_Del)Sys_Del };

Returncode Sys_print(
    Sys* _, Ref_Manager* __, String* text, Ref_Manager* text_Refman) {
  if (text != NULL && text_Refman->value != NULL) {
    int n, ch, res;
    for (n = 0; n < text->length; ++n) {
      ch = text->values[n];
      res = putchar(ch);
      if (ch != res) {
        return OK;
      }
    }
  }
  return OK;
}

Returncode Sys_println(
    Sys* _, Ref_Manager* __, String* text, Ref_Manager* text_Refman) {
  Sys_print(NULL, NULL, text, text_Refman);
  putchar('\n');
  return OK;
}

Returncode Sys_getchar(Sys* _, Ref_Manager* __, char* out_char, Bool* is_eof) {
  *is_eof = getc_is_eof(getchar(), out_char);
  return OK;
}

#define LUMI_FUNC_NAME "Sys.getline"
Returncode Sys_getline(
    Sys* _, Ref_Manager* __, String* line, Ref_Manager* line_Refman) {
  int ch = 0;
  CHECK_NOT_NULL(line);
  line->length = 0;
  if (lumi_debug_value != LUMI_DEBUG_SUCCESS) {
    ch = getchar();
  }
  while (ch != EOF && ch != '\n') {
    if (line->length >= line->max_length) {
      CRAISE("string too long")
    }
    line->values[line->length] = ch;
    ++line->length;
    if (lumi_debug_value != LUMI_DEBUG_SUCCESS) {
      ch = getchar();
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "Sys.exit"
Returncode Sys_exit(Sys* _, Ref_Manager* __, Int status) {
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    exit(status);
  }
  CRAISE("exit failed")
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "Sys.system"
Returncode Sys_system(
    Sys* _, Ref_Manager* __,
    String* command, Ref_Manager* command_Refman,
    Int* status) {
  int res = -1;
  CCHECK(set_cstring(command, command_Refman));
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    res = system(command->values);
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
    Sys* _, Ref_Manager* __,
    String* name, Ref_Manager* name_Refman,
    String* value, Ref_Manager* value_Refman,
    Bool* exists) {
  char* ret;
  CCHECK(set_cstring(name, name_Refman));
  CHECK_NOT_NULL(value)
  ret = getenv(name->values);
  if (ret == NULL) {
    *exists = false;
    return OK;
  }
  value->length = cstring_length(ret, value->max_length);
  strncpy(value->values, ret, value->length);
  *exists = true;
  return OK;
}
#undef LUMI_FUNC_NAME
