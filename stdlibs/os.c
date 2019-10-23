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

/* Pointer */

#define cdef_M_Pointer_set_point_to(pointer, value, _) pointer = &value
#define cdef_M_Pointer_set_from_ref(pointer, ref, _) pointer = ref
#define cdef_M_Pointer_set_from_array cdef_M_Pointer_set_from_ref
#define cdef_M_Pointer_get_pointed_at(pointer, index) pointer[index]
#define cdef_M_Pointer_get_ref_at(pointer, index) (pointer + index)


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

#define LUMI_FUNC_NAME "String.copy-from-pointer"
Returncode String_copy_from_pointer(
    char* self, int max_length, int* length, char* source) {
  int source_length;
  if (source == NULL) {
    *length = 0;
    self[0] = '\0';
    return OK;
  }
  if (self == source) {
    return OK;
  }
  source_length = cstring_length(source, max_length);
  if (source_length >= max_length) {
    CRAISE(LUMI_error_messages.string_too_long.str)
  }
  *length = source_length;
  memcpy(self, source, source_length);
  self[source_length] = '\0';
  return OK;
}
#undef LUMI_FUNC_NAME

void String_set_null_term_length(char* self, int max_length, int* length) {
  *length = cstring_length(self, max_length);
}

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



/* global nodes */

#include <dirent.h>


char* get_dname(struct dirent* dir) {
  return dir->d_name;
}


/* types declaration */

typedef struct os_M_Path os_M_Path;

typedef struct ds_M_List ds_M_List;

typedef struct ds_M_ListIterator ds_M_ListIterator;

typedef struct ds_M_ListIterator_Dynamic ds_M_ListIterator_Dynamic;

typedef struct ds_M_ListNode ds_M_ListNode;


/* Enums */


/* constants */


/* types struct */

struct os_M_Path {
    char* path_r;
    int path_r_Max_length;
    int* path_r_Length;
};

struct ds_M_List {
    ds_M_ListNode* first;
    Ref_Manager* first_Refman;
};

struct ds_M_ListIterator {
    ds_M_ListNode* curr;
    Ref_Manager* curr_Refman;
};

struct ds_M_ListIterator_Dynamic {
    Dynamic_Del _del;
    Returncode (*step)(ds_M_ListIterator* self, ds_M_ListIterator_Dynamic* self_Dynamic, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_another_item);
};

struct ds_M_ListNode {
    ds_M_ListNode* next;
    Ref_Manager* next_Refman;
    Generic_Type* item;
    Generic_Type_Dynamic* item_Dynamic;
};


/* types methods declaration */

Returncode os_M_Path_new(os_M_Path* self, Int len);

void os_M_Path_Del(os_M_Path* self);

Returncode ds_M_List_append(ds_M_List* self, Generic_Type* item, Generic_Type_Dynamic* item_Dynamic);

Returncode ds_M_List_rotate_to(ds_M_List* self, ds_M_List* target);

Returncode ds_M_List_prepend(ds_M_List* self, Generic_Type* item, Generic_Type_Dynamic* item_Dynamic);

void ds_M_List_is_empty(ds_M_List* self, Bool* empty);

Returncode ds_M_List_pop(ds_M_List* self, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic);

void ds_M_List_Del(ds_M_List* self);

void ds_M_ListIterator_new(ds_M_ListIterator* self, ds_M_ListIterator_Dynamic* self_Dynamic, ds_M_List* list);

Returncode ds_M_ListIterator_step(ds_M_ListIterator* self, ds_M_ListIterator_Dynamic* self_Dynamic, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_another_item);

void ds_M_ListIterator_Del(ds_M_ListIterator* self);

void ds_M_ListNode_new(ds_M_ListNode* self, Generic_Type* item, Generic_Type_Dynamic* item_Dynamic, ds_M_ListNode* next, Ref_Manager* next_Refman);

void ds_M_ListNode_Del(ds_M_ListNode* self);


/* global functions declaration */

Returncode os_M_list_dir(char* dir_path, int dir_path_Max_length, int* dir_path_Length, ds_M_List** files);

Returncode os_tests_M_printing(void);


/* types global variables */

Generic_Type_Dynamic os_M_Path_dynamic = {(Dynamic_Del)os_M_Path_Del};

Generic_Type_Dynamic ds_M_List_dynamic = {(Dynamic_Del)ds_M_List_Del};

ds_M_ListIterator_Dynamic ds_M_ListIterator_dynamic = {(Dynamic_Del)ds_M_ListIterator_Del, ds_M_ListIterator_step};

Generic_Type_Dynamic ds_M_ListNode_dynamic = {(Dynamic_Del)ds_M_ListNode_Del};


/* global variables */

int LUMI_file0_line_count[68] = {
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
    -1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1, 0, 0, 0, 0,-1, 0,-1, 0, 0, 0, 0, 0,
     0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"stdlibs/os.5.lm", 68, LUMI_file0_line_count}
};


/* types methods body */

#define LUMI_FILE_NAME "stdlibs/os.5.lm"
#define LUMI_FUNC_NAME "Path.new"
Returncode os_M_Path_new(os_M_Path* self, Int len) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    ++LUMI_file_coverage[0].line_count[33];
    INIT_NEW_STRING(33, LUMI_block0_cleanup, aux_String_0, len + 1);
    String_Del(self->path_r);
    free(self->path_r);
    self->path_r_Max_length = aux_String_0_Max_length;
    self->path_r_Length = aux_String_0_Length;
    self->path_r = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_int;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0);
    free(aux_String_0);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void os_M_Path_Del(os_M_Path* self) {
    if (self == NULL) return;
    String_Del(self->path_r);
    free(self->path_r);
}

#define LUMI_FILE_NAME "stdlibs/list.5.lm"
#define LUMI_FUNC_NAME "List.append"
Returncode ds_M_List_append(ds_M_List* self, Generic_Type* item, Generic_Type_Dynamic* item_Dynamic) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ds_M_List list_Var = {0};
    ds_M_List* list = NULL;
    list = &list_Var;
    LUMI_err = ds_M_List_rotate_to(self, list);
    CHECK(12, LUMI_block0_cleanup)
    LUMI_err = ds_M_List_prepend(list, item, (void*)item_Dynamic);
    item = NULL;
    item_Dynamic = NULL;
    CHECK(13, LUMI_block0_cleanup)
    LUMI_err = ds_M_List_rotate_to(list, self);
    CHECK(14, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    ds_M_List_Del(list);
    if (item_Dynamic != NULL) item_Dynamic->_del(item);
    free(item);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "stdlibs/list.5.lm"
#define LUMI_FUNC_NAME "List.rotate-to"
Returncode ds_M_List_rotate_to(ds_M_List* self, ds_M_List* target) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    do {
        ds_M_ListNode* node = NULL;
        Ref_Manager* node_Refman = NULL;
        LUMI_loop_depth = 3;
        if (!(self->first != NULL)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        node_Refman = self->first_Refman;
        node = self->first;
        self->first = NULL;
        self->first_Refman = NULL;
        CHECK_REF(20, LUMI_block1_cleanup, node)
        ds_M_ListNode_Del(self->first);
        LUMI_owner_dec_ref(self->first_Refman);
        self->first_Refman = node->next_Refman;
        self->first = node->next;
        node->next = NULL;
        node->next_Refman = NULL;
        CHECK_REF(21, LUMI_block1_cleanup, node)
        ds_M_ListNode_Del(node->next);
        LUMI_owner_dec_ref(node->next_Refman);
        node->next_Refman = target->first_Refman;
        node->next = target->first;
        target->first = NULL;
        target->first_Refman = NULL;
        ds_M_ListNode_Del(target->first);
        LUMI_owner_dec_ref(target->first_Refman);
        target->first_Refman = node_Refman;
        target->first = node;
        node = NULL;
        node_Refman = NULL;
    LUMI_block1_cleanup:
        (void)0;
    ds_M_ListNode_Del(node);
        LUMI_owner_dec_ref(node_Refman);
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "stdlibs/list.5.lm"
#define LUMI_FUNC_NAME "List.prepend"
Returncode ds_M_List_prepend(ds_M_List* self, Generic_Type* item, Generic_Type_Dynamic* item_Dynamic) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ds_M_ListNode* node = NULL;
    INIT_NEW(26, LUMI_block0_cleanup, node, ds_M_ListNode, 1);
    ds_M_ListNode_new(node, item, (void*)item_Dynamic, self->first, self->first_Refman);
    item = NULL;
    item_Dynamic = NULL;
    self->first = NULL;
    self->first_Refman = NULL;
    ds_M_ListNode_Del(self->first);
    LUMI_owner_dec_ref(self->first_Refman);
    self->first = node;
    node = NULL;
    INIT_NEW_REFMAN(27, LUMI_block0_cleanup, self->first)
LUMI_block0_cleanup:
    (void)0;
    ds_M_ListNode_Del(node);
    free(node);
    if (item_Dynamic != NULL) item_Dynamic->_del(item);
    free(item);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "stdlibs/list.5.lm"
#define LUMI_FUNC_NAME "List.is-empty"
void ds_M_List_is_empty(ds_M_List* self, Bool* empty) {
    unsigned LUMI_loop_depth = 1;
    *empty = ! (self->first != NULL);
LUMI_block0_cleanup:
    (void)0;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "stdlibs/list.5.lm"
#define LUMI_FUNC_NAME "List.pop"
Returncode ds_M_List_pop(ds_M_List* self, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ds_M_ListNode* first = NULL;
    ++LUMI_trace_ignore_count;
    CHECK_REF(35, LUMI_block2_cleanup, self->first)
    ds_M_ListNode_Del(first);
    free(first);
    LUMI_var_dec_ref(self->first_Refman);
    first = self->first;
    self->first = NULL;
    self->first_Refman = NULL;
LUMI_block2_cleanup:
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        char* aux_String_0 = NULL;
        int aux_String_0_Max_length = 0;
        int aux_String_0_Length[1] = {0};
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        INIT_STRING_CONST(36, LUMI_block1_cleanup, aux_String_0, "list empty");
        USER_RAISE(36, LUMI_block1_cleanup, aux_String_0, *(aux_String_0_Length))
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    ds_M_ListNode_Del(self->first);
    LUMI_owner_dec_ref(self->first_Refman);
    self->first_Refman = first->next_Refman;
    self->first = first->next;
    first->next = NULL;
    first->next_Refman = NULL;
    if (*item_Dynamic != NULL) (*item_Dynamic)->_del(*item);
    free(*item);
    *item_Dynamic = first->item_Dynamic;
    *item = first->item;
    first->item = NULL;
    first->item_Dynamic = NULL;
LUMI_block0_cleanup:
    (void)0;
    ds_M_ListNode_Del(first);
    free(first);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void ds_M_List_Del(ds_M_List* self) {
    if (self == NULL) return;
    ds_M_ListNode_Del(self->first);
    LUMI_owner_dec_ref(self->first_Refman);
}

#define LUMI_FILE_NAME "stdlibs/list.5.lm"
#define LUMI_FUNC_NAME "ListIterator.new"
void ds_M_ListIterator_new(ds_M_ListIterator* self, ds_M_ListIterator_Dynamic* self_Dynamic, ds_M_List* list) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(list->first_Refman);
    LUMI_dec_ref(self->curr_Refman);
    self->curr_Refman = list->first_Refman;
    self->curr = list->first;
LUMI_block0_cleanup:
    (void)0;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "stdlibs/list.5.lm"
#define LUMI_FUNC_NAME "ListIterator.step"
Returncode ds_M_ListIterator_step(ds_M_ListIterator* self, ds_M_ListIterator_Dynamic* self_Dynamic, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_another_item) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    *has_another_item = self->curr != NULL && (self->curr_Refman)->value != NULL;
    *item_Dynamic = (Generic_Type_Dynamic*)NULL;
    *item = NULL;
    if (self->curr != NULL && (self->curr_Refman)->value != NULL) {
        CHECK_REF_REFMAN(52, LUMI_block1_cleanup, self->curr, self->curr_Refman)
        *item_Dynamic = self->curr->item_Dynamic;
        *item = self->curr->item;
        CHECK_REF_REFMAN(53, LUMI_block1_cleanup, self->curr, self->curr_Refman)
        LUMI_inc_ref(self->curr->next_Refman);
        LUMI_dec_ref(self->curr_Refman);
        self->curr_Refman = self->curr->next_Refman;
        self->curr = self->curr->next;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void ds_M_ListIterator_Del(ds_M_ListIterator* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->curr_Refman);
}

#define LUMI_FILE_NAME "stdlibs/list.5.lm"
#define LUMI_FUNC_NAME "ListNode.new"
void ds_M_ListNode_new(ds_M_ListNode* self, Generic_Type* item, Generic_Type_Dynamic* item_Dynamic, ds_M_ListNode* next, Ref_Manager* next_Refman) {
    unsigned LUMI_loop_depth = 1;
    ds_M_ListNode_Del(self->next);
    LUMI_owner_dec_ref(self->next_Refman);
    self->next_Refman = next_Refman;
    self->next = next;
    next = NULL;
    next_Refman = NULL;
    if (self->item_Dynamic != NULL) ((Generic_Type_Dynamic*)(self->item_Dynamic))->_del(self->item);
    free(self->item);
    self->item_Dynamic = item_Dynamic;
    self->item = item;
    item = NULL;
    item_Dynamic = NULL;
LUMI_block0_cleanup:
    (void)0;
    ds_M_ListNode_Del(next);
    LUMI_owner_dec_ref(next_Refman);
    if (item_Dynamic != NULL) item_Dynamic->_del(item);
    free(item);
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void ds_M_ListNode_Del(ds_M_ListNode* self) {
    if (self == NULL) return;
    if (self->item_Dynamic != NULL) self->item_Dynamic->_del(self->item);
    free(self->item);
    SELF_REF_DEL_STR(ds_M_ListNode, next);
    LUMI_owner_dec_ref(self->next_Refman);
}


/* global functions body */

#define LUMI_FILE_NAME "stdlibs/os.5.lm"
#define LUMI_FUNC_NAME "list-dir"
Returncode os_M_list_dir(char* dir_path, int dir_path_Max_length, int* dir_path_Length, ds_M_List** files) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    DIR* dir = 0;
    struct dirent* ent = 0;
    Char* string_pointer = 0;
    Char* bla = NULL;
    int bla_Length = 0;
    Int a = 0;
    ds_M_List* aux_List_0 = NULL;
    ++LUMI_file_coverage[0].line_count[38];
    ++LUMI_file_coverage[0].line_count[39];
    ++LUMI_file_coverage[0].line_count[40];
    ++LUMI_file_coverage[0].line_count[41];
    ++LUMI_file_coverage[0].line_count[43];
    INIT_NEW(43, LUMI_block0_cleanup, aux_List_0, ds_M_List, 1);
    ds_M_List_Del(*files);
    free(*files);
    *files = aux_List_0;
    aux_List_0 = NULL;
    ++LUMI_file_coverage[0].line_count[45];
    bla_Length = *(dir_path_Length);
    bla = dir_path;
    ++LUMI_file_coverage[0].line_count[46];
    cdef_M_Pointer_set_from_array(string_pointer, bla, bla_Length);
    ++LUMI_file_coverage[0].line_count[47];
    dir = opendir(string_pointer);
    ++LUMI_file_coverage[0].line_count[48];
    if (! (dir != NULL)) {
        char* aux_String_0 = NULL;
        int aux_String_0_Max_length = 0;
        int aux_String_0_Length[1] = {0};
        ++LUMI_file_coverage[0].line_count[49];
        INIT_STRING_CONST(49, LUMI_block1_cleanup, aux_String_0, "path is not dir");
        USER_RAISE(49, LUMI_block1_cleanup, aux_String_0, *(aux_String_0_Length))
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    ++LUMI_file_coverage[0].line_count[50];
    do {
        Char* c_string = 0;
        Int l = 0;
        os_M_Path* path = NULL;
        LUMI_loop_depth = 3;
        ++LUMI_file_coverage[0].line_count[51];
        ++LUMI_file_coverage[0].line_count[52];
        CHECK_REF(52, LUMI_block2_cleanup, dir)
        ent = readdir(dir);
        ++LUMI_file_coverage[0].line_count[54];
        if (! (ent != NULL)) {
            char* aux_String_1 = NULL;
            int aux_String_1_Max_length = 0;
            int aux_String_1_Length[1] = {0};
            char* aux_String_2 = NULL;
            int aux_String_2_Max_length = 0;
            int aux_String_2_Length[1] = {0};
            ++LUMI_file_coverage[0].line_count[55];
            INIT_STRING_CONST(55, LUMI_block3_cleanup, aux_String_1, "hello");
            LUMI_err = Sys_println(sys, aux_String_1, *aux_String_1_Length);
            CHECK(55, LUMI_block3_cleanup)
            ++LUMI_file_coverage[0].line_count[56];
            INIT_STRING_CONST(56, LUMI_block3_cleanup, aux_String_2, "empty");
            USER_RAISE(56, LUMI_block3_cleanup, aux_String_2, *(aux_String_2_Length))
            ++LUMI_file_coverage[0].line_count[57];
            LUMI_loop_depth = 1; goto LUMI_block3_cleanup;
        LUMI_block3_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 3) goto LUMI_block2_cleanup;
        ++LUMI_file_coverage[0].line_count[58];
        CHECK_REF(58, LUMI_block2_cleanup, ent)
        c_string = get_dname(ent);
        ++LUMI_file_coverage[0].line_count[59];
        ++LUMI_file_coverage[0].line_count[60];
        l = strlen(c_string);
        ++LUMI_file_coverage[0].line_count[61];
        INIT_NEW(61, LUMI_block2_cleanup, path, os_M_Path, 1);
        LUMI_err = os_M_Path_new(path, l);
        ++LUMI_file_coverage[0].line_count[62];
        CHECK_REF(62, LUMI_block2_cleanup, path->path_r)
        LUMI_err = String_copy_from_pointer(path->path_r, path->path_r_Max_length, path->path_r_Length, c_string);
        CHECK(62, LUMI_block2_cleanup)
        ++LUMI_file_coverage[0].line_count[63];
        CHECK_REF(63, LUMI_block2_cleanup, *files)
        LUMI_err = ds_M_List_append(*files, path, &os_M_Path_dynamic);
        path = NULL;
        CHECK(63, LUMI_block2_cleanup)
    LUMI_block2_cleanup:
        (void)0;
    os_M_Path_Del(path);
        free(path);
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    ++LUMI_file_coverage[0].line_count[65];
    ++LUMI_file_coverage[0].line_count[66];
    CHECK_REF(66, LUMI_block0_cleanup, dir)
    a = closedir(dir);
LUMI_block0_cleanup:
    (void)0;
    ds_M_List_Del(aux_List_0);
    free(aux_List_0);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "stdlibs/tests/os-test.5.lm"
#define LUMI_FUNC_NAME "printing"
Returncode os_tests_M_printing(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ds_M_List* files = NULL;
    ds_M_ListIterator iter_Var = {0};
    ds_M_ListIterator* iter = NULL;
    ds_M_ListIterator_Dynamic* iter_Dynamic = &ds_M_ListIterator_dynamic;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int aux_String_0_Length[1] = {0};
    ds_M_List* aux_List_0 = NULL;
    ds_M_ListIterator* aux_ListIterator_0 = NULL;
    ds_M_ListIterator_Dynamic* aux_ListIterator_0_Dynamic = NULL;
    INIT_STRING_CONST(5, LUMI_block0_cleanup, aux_String_0, "/");
    LUMI_err = os_M_list_dir(aux_String_0, aux_String_0_Max_length, aux_String_0_Length, &(aux_List_0));
    CHECK(5, LUMI_block0_cleanup)
    files = aux_List_0;
    CHECK_REF(7, LUMI_block0_cleanup, files)
    iter = &iter_Var;
    ds_M_ListIterator_new(iter, iter_Dynamic, files);
    aux_ListIterator_0_Dynamic = iter_Dynamic;
    aux_ListIterator_0 = iter;
    do {
        os_M_Path* item = NULL;
        Bool aux_Bool_0 = 0;
        LUMI_loop_depth = 3;
        LUMI_err = aux_ListIterator_0_Dynamic->step(aux_ListIterator_0, aux_ListIterator_0_Dynamic, (void*)&(item), &dynamic_Void, &(aux_Bool_0));
        CHECK(8, LUMI_block1_cleanup)
        if (!(aux_Bool_0)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        CHECK_REF(9, LUMI_block1_cleanup, item)
        CHECK_REF(9, LUMI_block1_cleanup, item->path_r)
        LUMI_err = Sys_println(sys, item->path_r, *item->path_r_Length);
        CHECK(9, LUMI_block1_cleanup)
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    ds_M_List_Del(aux_List_0);
    free(aux_List_0);
    ds_M_ListIterator_Del(iter);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME


void new_Mock(Bool* allocate_success) { }

Returncode delete_Mock(Ref self) { return OK; }

/* main test function */

USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Bool LUMI_success = true;

    LUMI_success &= LUMI_run_test("printing", os_tests_M_printing);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
LUMI_block0_cleanup:
    return LUMI_err;
}

TEST_MAIN_FUNC
