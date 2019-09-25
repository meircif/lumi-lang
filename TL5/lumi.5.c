#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* builtin type defines */

typedef int Int;
typedef char Char;
typedef unsigned char Byte;

typedef enum Bool {
  false = 0,
  true = 1
} Bool;

typedef enum Returncode {
  OK = EXIT_SUCCESS,
  ERR = EXIT_FAILURE,
  FAIL = EXIT_FAILURE > EXIT_SUCCESS? EXIT_FAILURE + 1 : EXIT_SUCCESS + 1
} Returncode;

typedef struct Ref_Manager {
  int count;
  void* value;
  void* ref;
} Ref_Manager;

typedef struct File {
  FILE* fobj;
} File;

typedef struct Sys {
  char* argv;
  int argv_Length;
  int argv_Value_length;
  int* argv_String_length;
  Ref_Manager* argv_Refman;
  File* stdout_Cname;
  Ref_Manager* stdout_Cname_Refman;
  File* stdin_Cname;
  Ref_Manager* stdin_Cname_Refman;
  File* stderr_Cname;
  Ref_Manager* stderr_Cname_Refman;
} Sys;

typedef void* Ref;

typedef char cdef_M_Char;
typedef unsigned char cdef_M_Uchar;
typedef wchar_t cdef_M_Wchar;
typedef short cdef_M_Short;
typedef unsigned short cdef_M_Ushort;
typedef int cdef_M_Int;
typedef unsigned int cdef_M_Uint;
typedef long cdef_M_Long;
typedef unsigned long cdef_M_Ulong;
typedef size_t cdef_M_Size;
typedef float cdef_M_Float;
typedef double cdef_M_Double;
typedef long double cdef_M_LongDouble;

typedef void (*Dynamic_Del)(void*);

typedef void Generic_Type;
typedef struct Generic_Type_Dynamic { Dynamic_Del _del; } Generic_Type_Dynamic;

typedef struct File_Coverage {
  char const* filename;
  int lines_number;
  int* line_count;
} File_Coverage;

typedef struct Error_Message {
  char* str;
  int length;
} Error_Message;

typedef struct Error_Messages {
  Error_Message empty_object;
  Error_Message outdated_weak_reference;
  Error_Message object_memory;
  Error_Message managed_object_memory;
  Error_Message slice_index;
  Error_Message string_too_long;
  Error_Message file_not_opened;
  Error_Message file_write_failed;
  Error_Message zero_division;
  Error_Message loop_limit;
} Error_Messages;


/* macros */

#define START_TRACE(line, cleanup, value, format, message, message_length) { \
  LUMI_trace_print( \
      format, \
      LUMI_FILE_NAME, \
      line, \
      LUMI_FUNC_NAME, \
      message, \
      message_length); \
  LUMI_err = value; \
  LUMI_loop_depth = 0; \
  goto cleanup; }

#define RAISE(line, cleanup, message) { \
  START_TRACE( \
      line, \
      cleanup, \
      ERR, \
      LUMI_raise_format, \
      LUMI_error_messages.message.str, \
      LUMI_error_messages.message.length) }

#define USER_RAISE(line, cleanup, message, message_length) \
  START_TRACE( \
      line, \
      cleanup, \
      ERR, \
      LUMI_raise_format, \
      message, \
      message_length)

#define TEST_FAIL(line, cleanup, message_length, message) \
  START_TRACE( \
      line, cleanup, FAIL, LUMI_assert_format, message, message_length)

#define TEST_ASSERT(line, cleanup, condition) if (!(condition)) \
  TEST_FAIL(line, cleanup, 21, "condition is not true")

#define TEST_FAIL_NULL(line, cleanup) \
  START_TRACE(line, cleanup, FAIL, LUMI_assert_format, NULL, 0)

#define CHECK(line, cleanup) if (LUMI_err != OK) { \
  LUMI_trace_print( \
      LUMI_traceline_format, LUMI_FILE_NAME, line, LUMI_FUNC_NAME, \
      NULL, 0); \
  LUMI_loop_depth = 0; \
  goto cleanup; }

#define IGNORE_ERRORS(call) \
  ++LUMI_trace_ignore_count; (void)call; --LUMI_trace_ignore_count;

#define CHECK_REF(line, cleanup, ref) \
  if (ref == NULL) RAISE(line, cleanup, empty_object)

#define CHECK_REFMAN(line, cleanup, refman) \
  if (refman != NULL && (refman)->value == NULL) \
    RAISE(line, cleanup, outdated_weak_reference)

#define CHECK_REF_REFMAN(line, cleanup, ref, refman) \
  CHECK_REF(line, cleanup, ref) \
  if ((refman)->value == NULL) RAISE(line, cleanup, outdated_weak_reference)

#define MAIN_PROXY(func) int main(int argc, char* argv[]) { \
  return func(argc, argv); \
}

#define MAIN_FUNC MAIN_PROXY(LUMI_main)
#define TEST_MAIN_FUNC MAIN_PROXY(LUMI_test_main)
#define USER_MAIN_HEADER Returncode LUMI_user_main(void)

#define ARRAY_DEL(Type, array, length) if (array != NULL) { \
  int LUMI_n = 0; \
  for (; LUMI_n < length; ++LUMI_n) \
    Type##_Del(array + LUMI_n); \
  }

#define SELF_REF_DEL(Type, field) \
while (self->field != NULL) { \
  Type* value = self->field; \
  self->field = value->field; \
  value->field = NULL; \
  Type##_Del(value); \
  free(value); \
}

#define SELF_REF_DEL_STR(Type, field) \
while (self->field != NULL) { \
  Type* value = self->field; \
  Ref_Manager* value_Refman = self->field##_Refman; \
  self->field = value->field; \
  self->field##_Refman = value->field##_Refman; \
  value->field = NULL; \
  value->field##_Refman = NULL; \
  Type##_Del(value); \
  LUMI_owner_dec_ref(value_Refman); \
}

#define SELF_REF_DEL_DYN(Type, bases, field) \
while (self->field != NULL) { \
  Type* value = self->field; \
  Type##_Dynamic* value_Dynamic = self->field##_Dynamic; \
  self->field = value->field; \
  self->field##_Dynamic = value->field##_Dynamic; \
  value->field = NULL; \
  value->field##_Dynamic = NULL; \
  value_Dynamic->bases##del(value); \
  free(value); \
}

#define SELF_REF_DEL_STR_DYN(Type, bases, field) \
while (self->field != NULL) { \
  Type* value = self->field; \
  Ref_Manager* value_Refman = self->field##_Refman; \
  Type##_Dynamic* value_Dynamic = self->field##_Dynamic; \
  self->field = value->field; \
  self->field##_Refman = value->field##_Refman; \
  self->field##_Dynamic = value->field##_Dynamic; \
  value->field = NULL; \
  value->field##_Refman = NULL; \
  value->field##_Dynamic = NULL; \
  value_Dynamic->bases##del(value); \
  LUMI_owner_dec_ref(value_Refman); \
}

#define INIT_VAR_REFMAN(line, cleanup, name) \
  name##_Refman = LUMI_new_ref(name); \
  if (name##_Refman == NULL) { RAISE(line, cleanup, managed_object_memory) }

#define INIT_NEW_REFMAN(line, cleanup, name) \
  name##_Refman = LUMI_new_ref(name); \
  if (name##_Refman == NULL) { \
    free(name); \
    name = NULL; \
    RAISE(line, cleanup, managed_object_memory) }

#define INIT_NEW(line, cleanup, name, type, size) \
  if (size <= 0) RAISE(line, cleanup, slice_index) \
  name = LUMI_alloc(sizeof(type) * size); \
  if (name == NULL) RAISE(line, cleanup, object_memory)

#define INIT_NEW_ARRAY(line, cleanup, name, type, length, value_size) \
  name##_Length = length; \
  INIT_NEW(line, cleanup, name, type, name##_Length * value_size)

#define INIT_NEW_STRING(line, cleanup, name, size) \
  name##_Max_length = size; \
  INIT_NEW(line, cleanup, name, char, name##_Max_length) \
  name##_Length = LUMI_alloc(sizeof(int)); \
  if (name##_Length == NULL) { \
    name##_Length = &Lumi_empty_int; \
    free(name); name = NULL; \
    RAISE(line, cleanup, object_memory) }

#define INIT_STRING_CONST(line, cleanup, name, text) \
  name = text; \
  name##_Max_length = sizeof(text); \
  *name##_Length = sizeof(text) - 1;


#define String_Del(name) do { if (name##_Length != &Lumi_empty_int) { \
  free(name##_Length); \
  name##_Length = &Lumi_empty_int; } } while (false)


/* traceback */

#define CRAISE(message) { \
  LUMI_C_trace_print(__LINE__, LUMI_FUNC_NAME, message); \
  return ERR; }
#define CCHECK(err) { \
  Returncode LUMI_cerr = err; \
  if (LUMI_cerr != OK) return LUMI_cerr; }

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

#define ERROR_MESAGE(message) {message, sizeof(message) - 1}

Error_Messages LUMI_error_messages = {
  ERROR_MESAGE("empty object used"),
  ERROR_MESAGE("outdated weak reference used"),
  ERROR_MESAGE("insufficient memory for object dynamic allocation"),
  ERROR_MESAGE("insufficient memory for managed object"),
  ERROR_MESAGE("slice index out of bounds"),
  ERROR_MESAGE("string too long"),
  ERROR_MESAGE("file not opened"),
  ERROR_MESAGE("file write failed"),
  ERROR_MESAGE("zero division"),
  ERROR_MESAGE("loop limit reached")
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

/* like strnlen */
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


/* main */

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


/* tests */

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

Bool LUMI_run_test(char* test_name, Returncode (*test_func)(void)) {
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


/* reference counting */

void new_Mock(Bool*);
Returncode delete_Mock(Ref);

void* LUMI_alloc(size_t size) {
  Bool allocate_success = true;
  new_Mock(&allocate_success);
  if (allocate_success) {
    return calloc(1, size);
  }
  return NULL;
}

Ref_Manager* LUMI_new_ref(void* value) {
  Ref_Manager* ref = NULL;
  Bool allocate_success = true;
  new_Mock(&allocate_success);
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


/* Int */

#define LUMI_FUNC_NAME "Int.str"
Returncode Int_str(Int value, char* str, int str_max_length, int* str_length) {
  Bool is_neg;
  int abs;
  int swap;
  char* next;
  char* last;
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


/* Array */

void Array_length(void* self, int length, Int* length_out) {
  *length_out = length;
}


/* String */

void String_length(
    char* self, int max_length, int *length, Int* length_out) {
  *length_out = *length;
}

void String_max_length(
    char* self, int max_length, int *length, Int* max_length_out) {
  *max_length_out = max_length;
}

#define LUMI_FUNC_NAME "String.copy"
Returncode String_copy(
    char* self, int max_length, int* length, char* source, int source_length) {
  if (self == source) {
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

void String_clear(char* self, int max_length, int* length) {
  *length = 0;
}

void String_equal(
    char* self, int max_length, int *length,
    char* other, int other_length,
    Bool* out_equal) {
  if (self == other) {
    *out_equal = *length == other_length;
    return;
  }
  if (*length != other_length) {
    *out_equal = false;
    return;
  }
  *out_equal = strncmp(self, other, *length) == 0;
}

#define LUMI_FUNC_NAME "String.get"
Returncode String_get(
    char* self, int max_length, int *length, Int index, Char* out_char) {
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
  if (index < 0 || index >= *length) {
    CRAISE(LUMI_error_messages.slice_index.str)
  }
  self[index] = ch;
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.append"
Returncode String_append(char* self, int max_length, int* length, Char ch) {
  if (*length + 1 >= max_length) {
    CRAISE(LUMI_error_messages.string_too_long.str)
  }
  self[*length] = ch;
  ++(*length);
  self[*length] = '\0';
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.concat"
Returncode String_concat(
    char* self, int max_length, int* length, char* ext, int ext_length) {
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
  CCHECK(Int_str(num, self + *length, max_length - *length, &added_length));
  *length += added_length;
  return OK;
}
#undef LUMI_FUNC_NAME

void String_find(
    char* self, int max_length, int *length,
    char* pattern, int pattern_length,
    Int* out_index) {
  int n;
  for (n = 0; n <= *length - pattern_length; ++n) {
    if (strncmp(self + n, pattern, pattern_length) == 0) {
      *out_index = n;
      return;
    }
  }
  *out_index = *length;
}

void String_has(
    char* self, int max_length, int *length, Char ch, Bool* found) {
  int n;
  for (n = 0; n < *length; ++n) {
    if (self[n] == ch) {
      *found = true;
      return;
    }
  }
  *found = false;
}


/* File */

void File_Del(File* self) {
  if (self != NULL && self->fobj != NULL) {
    fclose(self->fobj);
  }
}

Generic_Type_Dynamic File_dynamic = { (Dynamic_Del)File_Del };

#define LUMI_FUNC_NAME "file-close"
Returncode file_close(File* file) {
  if (lumi_debug_value == LUMI_DEBUG_FAIL || file->fobj != NULL) {
    if (lumi_debug_value == LUMI_DEBUG_FAIL || fclose(file->fobj) != 0) {
      free(file);
      CRAISE("close file failed")
    }
    file->fobj = NULL;
  }
  free(file);
  return OK;
}
#undef LUMI_FUNC_NAME

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
  if (lumi_debug_value != LUMI_DEBUG_SUCCESS) {
    if (lumi_debug_value != LUMI_DEBUG_FAIL) {
      new_fobj = fopen(name, mode);
    }
    if (new_fobj == NULL) {
      CRAISE("open file failed")
    }
  }
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
  if (file->fobj == NULL) CRAISE(LUMI_error_messages.file_not_opened.str)
  *is_eof = getc_is_eof(getc(file->fobj), out_char);
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "File.putc"
Returncode File_putc(File* file, Char ch) {
  int res = '\0';
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
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
    if (file->fobj == NULL) CRAISE(LUMI_error_messages.file_not_opened.str)
  }
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


/* system */

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

void Sys_getchar(Sys* _, char* out_char, Bool* is_eof) {
  *is_eof = getc_is_eof(getchar(), out_char);
}

#define LUMI_FUNC_NAME "Sys.getline"
Returncode Sys_getline(
    Sys* _, char* line, int line_max_length, int* line_length) {
  int ch = 0;
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

Returncode Sys_getenv(
    Sys* _,
    char* name, int name_max_length, int *name_length,
    char* value, int value_max_length, int* value_length,
    Bool* exists) {
  char* ret;
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
