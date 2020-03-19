#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


/* builtin type defines */

typedef uint32_t Int;
typedef char Char;
typedef uint8_t Byte;
typedef uint8_t Bool;

enum Bool {
  false = 0,
  true = 1
};

typedef enum Return_Code {
  OK = EXIT_SUCCESS,
  ERR = EXIT_FAILURE,
  FAIL = EXIT_FAILURE > EXIT_SUCCESS? EXIT_FAILURE + 1 : EXIT_SUCCESS + 1
} Return_Code;

typedef struct Ref_Manager {
  size_t count;
  void* value;
  void* ref;
} Ref_Manager;

typedef struct File {
  FILE* fobj;
} File;

typedef File FileReadText;
typedef File FileReadBinary;
typedef File FileWriteText;
typedef File FileWriteBinary;
typedef File FileReadWriteText;
typedef File FileReadWriteBinary;

typedef uint32_t Seq_Length;

char* sys_M_argv = NULL;
Seq_Length sys_M_argv_Length = 0;
Seq_Length sys_M_argv_Value_length;
Seq_Length* sys_M_argv_Seq_length = NULL;
Ref_Manager* sys_M_argv_Refman = NULL;
File* sys_M_stdin = NULL;
Ref_Manager* sys_M_stdin_Refman = NULL;
File* sys_M_stdout = NULL;
Ref_Manager* sys_M_stdout_Refman = NULL;
File* sys_M_stderr = NULL;
Ref_Manager* sys_M_stderr_Refman = NULL;

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

typedef void (*Dynamic_Del)(void*, void*);

typedef void Generic_Type;
typedef struct Generic_Type_Dynamic { Dynamic_Del _del; } Generic_Type_Dynamic;

typedef long Line_Count;

typedef struct File_Coverage {
  char const* filename;
  Line_Count lines_number;
  Line_Count* line_count;
} File_Coverage;

typedef struct Error_Message {
  char* str;
  unsigned length;
} Error_Message;

typedef struct Error_Messages {
  Error_Message empty_object;
  Error_Message outdated_weak_reference;
  Error_Message object_memory;
  Error_Message managed_object_memory;
  Error_Message slice_index;
  Error_Message sequence_too_short;
  Error_Message file_not_opened;
  Error_Message file_read_failed;
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
#define USER_MAIN_HEADER Return_Code LUMI_user_main(void)

#define ARRAY_DEL(Type, array, length) if (array != NULL) { \
  Seq_Length LUMI_n = 0; \
  for (; LUMI_n < length; ++LUMI_n) \
    Type##_Del(array + LUMI_n); \
  }

#define ARRAY_DEL_DYN(Type, array, length) if (array != NULL) { \
  Seq_Length LUMI_n = 0; \
  for (; LUMI_n < length; ++LUMI_n) \
    Type##_Del(array + LUMI_n, &Type##_dynamic); \
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

#define SELF_REF_DEL_DYN(Type, bases, field, field_Dynamic) \
while (self->field != NULL) { \
  Type* value = self->field; \
  Type##_Dynamic* value_Dynamic = self->field_Dynamic; \
  self->field = value->field; \
  self->field_Dynamic = value->field_Dynamic; \
  value->field = NULL; \
  value->field_Dynamic = NULL; \
  value_Dynamic->bases##del(value, value_Dynamic); \
  free(value); \
}

#define SELF_REF_DEL_STR_DYN(Type, bases, field, field_Dynamic) \
while (self->field != NULL) { \
  Type* value = self->field; \
  Ref_Manager* value_Refman = self->field##_Refman; \
  Type##_Dynamic* value_Dynamic = self->field_Dynamic; \
  self->field = value->field; \
  self->field##_Refman = value->field##_Refman; \
  self->field_Dynamic = value->field_Dynamic; \
  value->field = NULL; \
  value->field##_Refman = NULL; \
  value->field_Dynamic = NULL; \
  value_Dynamic->bases##del(value, value_Dynamic); \
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
  name = LUMI_alloc(sizeof(type) * size); \
  if (name == NULL) RAISE(line, cleanup, object_memory)

#define INIT_NEW_ARRAY(line, cleanup, name, type, length, value_size) \
  name##_Length = length; \
  INIT_NEW(line, cleanup, name, type, name##_Length * value_size)

#define INIT_NEW_SEQUENCE(line, cleanup, name, type, size) \
  name##_Max_length = size; \
  INIT_NEW(line, cleanup, name, type, name##_Max_length) \
  name##_Length = LUMI_alloc(sizeof(Seq_Length)); \
  if (name##_Length == NULL) { \
    name##_Length = &Lumi_empty_length; \
    free(name); name = NULL; \
    RAISE(line, cleanup, object_memory) }


#define Buffer_Del(name) do { if (name##_Length != &Lumi_empty_length) { \
  free(name##_Length); \
  name##_Length = &Lumi_empty_length; } } while (false)
#define String_Del(name) Buffer_Del(name)


/* traceback */

#define CRAISE(message) { \
  LUMI_C_trace_print(__LINE__, LUMI_FUNC_NAME, message); \
  return ERR; }
#define CCHECK(err) { \
  Return_Code LUMI_cerr = err; \
  if (LUMI_cerr != OK) return LUMI_cerr; }

char* LUMI_raise_format = "Error raised in %s:%lu %s()\n";
char* LUMI_assert_format = "Assert failed in %s:%lu %s()\n";
char* LUMI_traceline_format = "  called from %s:%lu %s()\n";
FILE* LUMI_trace_stream = NULL;
size_t LUMI_trace_ignore_count = 0;
char* LUMI_expected_error = NULL;
size_t LUMI_expected_error_trace_ignore_count = 0;
Generic_Type_Dynamic* dynamic_Void = NULL;

Seq_Length Lumi_empty_length = 0;

#define ERROR_MESAGE(message) {message, sizeof(message) - 1}

Error_Messages LUMI_error_messages = {
  ERROR_MESAGE("empty object used"),
  ERROR_MESAGE("outdated weak reference used"),
  ERROR_MESAGE("insufficient memory for object dynamic allocation"),
  ERROR_MESAGE("insufficient memory for managed object"),
  ERROR_MESAGE("slice index out of bounds"),
  ERROR_MESAGE("sequence too short"),
  ERROR_MESAGE("file not opened"),
  ERROR_MESAGE("file read failed"),
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
    Line_Count line,
    char const* funcname,
    char const* message,
    unsigned message_length) {
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
    unsigned n;
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
size_t cstring_length(char* cstring, size_t max_length) {
  size_t length = 0;
  while (cstring[length] != '\0' && length < max_length) {
    ++length;
  }
  return length;
}

void LUMI_C_trace_print(Line_Count line, char const* funcname, char* message) {
  LUMI_trace_print(
      LUMI_raise_format,
      "builtin",
      line,
      funcname,
      message,
      cstring_length(message, 255));
}


/* main */

Return_Code LUMI_user_main(void);
Return_Code set_sys(int argc, char* argv[]);
#define SET_SYS err = set_sys(argc, argv); if (err != OK) return err;

int LUMI_main(int argc, char* argv[]) {
  Return_Code err;
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
  Return_Code err;
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

Bool LUMI_run_test(char* test_name, Return_Code (*test_func)(void)) {
  Return_Code err;
  printf("testing %s... ", test_name);
  fflush(stdout);
  err = test_func();
  if (err == OK) {
    printf("OK\n");
    return true;
  }
  return false;
}

unsigned calc_coverage(File_Coverage* files_coverage, size_t files_number) {
  size_t n;
  size_t all_lines = 0;
  size_t covered_lines = 0;
  for (n = 0; n < files_number; ++n) {
    Line_Count line;
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

void make_coverage_xml(File_Coverage* files_coverage, size_t files_number) {
  size_t n;
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
    Line_Count line;
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
          "      <line branch=\"false\" hits=\"%ld\" number=\"%ld\"/>\n",
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

Bool LUMI_test_coverage(File_Coverage* files_coverage, size_t files_number) {
  size_t n;
  unsigned coverage;
  Bool generate_xml = false;
  if (sys_M_argv != NULL && sys_M_argv_Refman->value != NULL &&
      sys_M_argv_Length > 1 && sys_M_argv_Seq_length[1] > 1) {
    char* arg = sys_M_argv + sys_M_argv_Value_length;
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

  printf("%u%% - failed, lines not covered:\n", coverage);
  for (n = 0; n < files_number; ++n) {
    coverage = calc_coverage(files_coverage + n, 1);
    if (coverage < 100) {
      Line_Count line;
      Line_Count first_uncovered;
      Bool prev_uncovered = false;
      printf("  %s(%u%%):", files_coverage[n].filename, coverage);
      for (line = 0; line < files_coverage[n].lines_number; ++line) {
        if (files_coverage[n].line_count[line] == 0) {
          if (!prev_uncovered) {
            first_uncovered = line;
            prev_uncovered = true;
          }
        }
        else if (prev_uncovered) {
          printf(" %lu", first_uncovered);
          if (first_uncovered < line - 1) {
            printf("-%lu", line - 1);
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
Return_Code delete_Mock(Ref);

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
Return_Code Int_str(
    int64_t value, char* str, Seq_Length str_max_length, Seq_Length* str_length) {
  Bool is_neg;
  uint64_t abs;
  uint64_t swap;
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
      CRAISE(LUMI_error_messages.sequence_too_short.str)
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

#define Array_length(self, length, length_out) *(length_out) = length


/* Buffer */

#define Buffer_length(self, max_length, length, length_out) \
  *(length_out) = *(length)
  
#define Buffer_max_length(self, max_length, length, max_length_out) \
  *(max_length_out) = max_length

#define LUMI_FUNC_NAME "Buffer.copy"
Return_Code Buffer_copy(
    void* self, Seq_Length max_length, Seq_Length* length, void* source, Seq_Length source_length) {
  if (self == source) {
    return OK;
  }
  if (source_length > max_length)
    CRAISE(LUMI_error_messages.sequence_too_short.str)
  *length = source_length;
  memcpy(self, source, source_length);
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "cdef.copy-to-buffer"
Return_Code cdef_M_copy_to_buffer(
    void* source, Seq_Length source_length, void* self, Seq_Length max_length, Seq_Length* length) {
  if (source == NULL) {
    *length = 0;
    return OK;
  }
  CCHECK(Buffer_copy(self, max_length, length, source, source_length))
  return OK;
}
#undef LUMI_FUNC_NAME

void Buffer_clear(void* self, Seq_Length max_length, Seq_Length* length) {
  *length = 0;
}

void Buffer_equal(
    void* self, Seq_Length max_length, Seq_Length *length,
    void* other, Seq_Length other_length,
    Bool* out_equal) {
  if (*length != other_length) {
    *out_equal = false;
    return;
  }
  if (self == other) {
    *out_equal = true;
    return;
  }
  *out_equal = memcmp(self, other, *length) == 0;
}

#define CHECK_INDEX(index, length) if (index < 0 || index >= *length) \
    CRAISE(LUMI_error_messages.slice_index.str)

#define LUMI_FUNC_NAME "Buffer.get"
Return_Code Buffer_get(
    Byte* self, Seq_Length max_length, Seq_Length *length, Seq_Length index, Byte* out_value) {
  CHECK_INDEX(index, length)
  *out_value = self[index];
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "Buffer.set"
Return_Code Buffer_set(
    Byte* self, Seq_Length max_length, Seq_Length *length, Seq_Length index, Byte value) {
  CHECK_INDEX(index, length)
  self[index] = value;
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "Buffer.append"
Return_Code Buffer_append(Byte* self, Seq_Length max_length, Seq_Length* length, Byte value) {
  if (*length >= max_length)
    CRAISE(LUMI_error_messages.sequence_too_short.str)
  self[*length] = value;
  ++(*length);
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "Buffer.concat"
Return_Code Buffer_concat_internal(
    void* self, Seq_Length max_length, Seq_Length* length, void* ext, Seq_Length ext_length) {
  if (*length + ext_length > max_length)
    CRAISE(LUMI_error_messages.sequence_too_short.str)
  memcpy(self, ext, ext_length);
  *length += ext_length;
  return OK;
}
#undef LUMI_FUNC_NAME

Return_Code Buffer_concat(
    Byte* self, Seq_Length max_length, Seq_Length* length, Byte* ext, Seq_Length ext_length) {
  return Buffer_concat_internal(
      self + (*length), max_length, length, ext, ext_length);
}

void Buffer_find(
    Byte* self, Seq_Length max_length, Seq_Length *length,
    Byte* pattern, Seq_Length pattern_length,
    Seq_Length* out_index) {
  Seq_Length n;
  for (n = 0; n <= *length - pattern_length; ++n) {
    if (memcmp(self + n, pattern, pattern_length) == 0) {
      *out_index = n;
      return;
    }
  }
  *out_index = *length;
}

void Buffer_has(
    Byte* self, Seq_Length max_length, Seq_Length *length, Byte value, Bool* found) {
  Seq_Length n;
  for (n = 0; n < *length; ++n) {
    if (self[n] == value) {
      *found = true;
      return;
    }
  }
  *found = false;
}


/* String */

#define String_length(self, max_length, length, length_out) \
  Buffer_length(self, max_length, length, length_out)
#define String_max_length(self, max_length, length, length_out) \
  Buffer_max_length(self, max_length, length, length_out)
#define String_clear(self, max_length, length) \
  Buffer_clear(self, max_length, length)

#define LUMI_FUNC_NAME "String.copy"
Return_Code String_copy(
    char* self, Seq_Length max_length, Seq_Length* length, char* source, Seq_Length source_length) {
  CCHECK(Buffer_copy(self, max_length - 1, length, source, source_length))
  self[source_length] = '\0';
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "cdef.copy-to-string"
Return_Code cdef_M_copy_to_string(
    char* source, char* self, Seq_Length max_length, Seq_Length* length) {
  CCHECK(cdef_M_copy_to_buffer(
      source, cstring_length(source, max_length), self, max_length - 1, length))
  self[*length] = '\0';
  return OK;
}
#undef LUMI_FUNC_NAME

void cdef_M_set_null_term_length(char* self, Seq_Length max_length, Seq_Length* length) {
  *length = cstring_length(self, max_length);
}

void String_equal(
    char* self, Seq_Length max_length, Seq_Length *length,
    char* other, Seq_Length other_length,
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
Return_Code String_get(
    char* self, Seq_Length max_length, Seq_Length *length, Seq_Length index, Char* out_char) {
  CHECK_INDEX(index, length)
  *out_char = self[index];
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.set"
Return_Code String_set(
    char* self, Seq_Length max_length, Seq_Length *length, Seq_Length index, Char ch) {
  CHECK_INDEX(index, length)
  self[index] = ch;
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.append"
Return_Code String_append(char* self, Seq_Length max_length, Seq_Length* length, Char ch) {
  if (*length + 1 >= max_length)
    CRAISE(LUMI_error_messages.sequence_too_short.str)
  self[*length] = ch;
  ++(*length);
  self[*length] = '\0';
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.concat"
Return_Code String_concat(
    char* self, Seq_Length max_length, Seq_Length* length, char* ext, Seq_Length ext_length) {
  CCHECK(Buffer_concat_internal(
      self + (*length), max_length - 1, length, ext, ext_length))
  self[*length] = '\0';
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.concat-int"
Return_Code String_concat_int(
    char* self, Seq_Length max_length, Seq_Length* length, int64_t num) {
  Seq_Length added_length = 0;
  CCHECK(Int_str(num, self + *length, max_length - *length, &added_length))
  *length += added_length;
  return OK;
}
#undef LUMI_FUNC_NAME

void String_find(
    char* self, Seq_Length max_length, Seq_Length *length,
    char* pattern, Seq_Length pattern_length,
    Seq_Length* out_index) {
  Seq_Length n;
  for (n = 0; n <= *length - pattern_length; ++n) {
    if (strncmp(self + n, pattern, pattern_length) == 0) {
      *out_index = n;
      return;
    }
  }
  *out_index = *length;
}

void String_has(
    char* self, Seq_Length max_length, Seq_Length *length, Char ch, Bool* found) {
  Seq_Length n;
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
    self->fobj = NULL;
  }
}
#define FileReadText_Del(self) File_Del(self)
#define FileReadBinary_Del(self) File_Del(self)
#define FileWriteText_Del(self) File_Del(self)
#define FileWriteBinary_Del(self) File_Del(self)
#define FileReadWriteText_Del(self) File_Del(self)
#define FileReadWriteBinary_Del(self) File_Del(self)

Generic_Type_Dynamic File_dynamic = { (Dynamic_Del)File_Del };
#define FileReadText_dynamic File_dynamic
#define FileReadBinary_dynamic File_dynamic
#define FileWriteText_dynamic File_dynamic
#define FileWriteBinary_dynamic File_dynamic
#define FileReadWriteText_dynamic File_dynamic
#define FileReadWriteBinary_dynamic File_dynamic

#define LUMI_FUNC_NAME "File.close"
Return_Code File_close(File* self) {
  if (lumi_debug_value == LUMI_DEBUG_FAIL || self->fobj != NULL) {
    if (lumi_debug_value == LUMI_DEBUG_FAIL || fclose(self->fobj) != 0)
      CRAISE("close file failed")
    self->fobj = NULL;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#define FileReadText_close(self) File_close(self)
#define FileReadBinary_close(self) File_close(self)
#define FileWriteText_close(self) File_close(self)
#define FileWriteBinary_close(self) File_close(self)
#define FileReadWriteText_close(self) File_close(self)
#define FileReadWriteBinary_close(self) File_close(self)

#define LUMI_FUNC_NAME "File.new"
Return_Code File_new(File* self, char* name, char* mode) {
  if (lumi_debug_value == LUMI_DEBUG_NOTHING) {
    CCHECK(File_close(self))
  }
  if (lumi_debug_value != LUMI_DEBUG_SUCCESS) {
    if (lumi_debug_value != LUMI_DEBUG_FAIL) {
      self->fobj = fopen(name, mode);
    }
    if (self->fobj == NULL) CRAISE("open file failed")
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#define FileReadText_new(self, name, name_max_length, name_length) \
  File_new(self, name, "r")
#define FileReadBinary_new(self, name, name_max_length, name_length) \
  File_new(self, name, "rb")
#define FileWriteText_new(self, name, name_max_length, name_length, append) \
  File_new(self, name, append? "a": "w")
#define FileWriteBinary_new(self, name, name_max_length, name_length, append) \
  File_new(self, name, append? "ab": "wb")
#define FileReadWriteText_new(self, name, name_max_length, name_length, append, exist) \
  File_new(self, name, append? "a+": exist? "r+": "w+")
#define FileReadWriteBinary_new(self, name, name_max_length, name_length, append, exist) \
  File_new(self, name, append? "ab+": exist? "rb+": "wb+")

#define CHECK_OPEN(self) \
  if (lumi_debug_value != LUMI_DEBUG_FAIL && self->fobj == NULL) \
    CRAISE(LUMI_error_messages.file_not_opened.str)

#define LUMI_FUNC_NAME "File.tell"
Return_Code File_tell(File* self, uint64_t* offset) {
  long ret = -1;
  CHECK_OPEN(self)
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    ret = ftell(self->fobj);
  }
  if (ret < 0) CRAISE("getting file offset failed")
  *offset = ret;
  return OK;
}
#undef LUMI_FUNC_NAME
#define FileReadText_tell(self, offset) File_tell(self, offset)
#define FileReadBinary_tell(self, offset) File_tell(self, offset)
#define FileWriteText_tell(self, offset) File_tell(self, offset)
#define FileWriteBinary_tell(self, offset) File_tell(self, offset)
#define FileReadWriteText_tell(self, offset) File_tell(self, offset)
#define FileReadWriteBinary_tell(self, offset) File_tell(self, offset)

#define LUMI_FUNC_NAME "File.seek"
Return_Code File_seek(File* self, uint64_t offset, int whence) {
  int ret = -1;
  CHECK_OPEN(self)
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    ret = fseek(self->fobj, offset, whence);
  }
  if (ret != 0) CRAISE("setting file offset failed")
  return OK;
}
#undef LUMI_FUNC_NAME
#define File_seek_set(self, offset) File_seek(self, offset, SEEK_SET)
#define File_seek_cur(self, offset) File_seek(self, offset, SEEK_CUR)
#define File_seek_end(self, offset) File_seek(self, offset, SEEK_END)
#define FileReadText_seek_set(self, offset) File_seek_set(self, offset)
#define FileReadBinary_seek_set(self, offset) File_seek_set(self, offset)
#define FileWriteText_seek_set(self, offset) File_seek_set(self, offset)
#define FileWriteBinary_seek_set(self, offset) File_seek_set(self, offset)
#define FileReadWriteText_seek_set(self, offset) File_seek_set(self, offset)
#define FileReadWriteBinary_seek_set(self, offset) File_seek_set(self, offset)
#define FileReadText_seek_cur(self, offset) File_seek_cur(self, offset)
#define FileReadBinary_seek_cur(self, offset) File_seek_cur(self, offset)
#define FileWriteText_seek_cur(self, offset) File_seek_cur(self, offset)
#define FileWriteBinary_seek_cur(self, offset) File_seek_cur(self, offset)
#define FileReadWriteText_seek_cur(self, offset) File_seek_cur(self, offset)
#define FileReadWriteBinary_seek_cur(self, offset) File_seek_cur(self, offset)
#define FileReadText_seek_end(self, offset) File_seek_end(self, offset)
#define FileReadBinary_seek_end(self, offset) File_seek_end(self, offset)
#define FileWriteText_seek_end(self, offset) File_seek_end(self, offset)
#define FileWriteBinary_seek_end(self, offset) File_seek_end(self, offset)
#define FileReadWriteText_seek_end(self, offset) File_seek_end(self, offset)
#define FileReadWriteBinary_seek_end(self, offset) File_seek_end(self, offset)

#define LUMI_FUNC_NAME "File.flush"
Return_Code File_flush(File* self) {
  int ret = EOF;
  CHECK_OPEN(self)
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    ret = fflush(self->fobj);
  }
  if (ret != 0) CRAISE("flush file failed")
  return OK;
}
#undef LUMI_FUNC_NAME
#define FileReadText_flush(self) File_flush(self)
#define FileReadBinary_flush(self) File_flush(self)
#define FileWriteText_flush(self) File_flush(self)
#define FileWriteBinary_flush(self) File_flush(self)
#define FileReadWriteText_flush(self) File_flush(self)
#define FileReadWriteBinary_flush(self) File_flush(self)

Bool getc_is_not_ok(int get, char* ch) {
  if (get == EOF) {
    return true;
  }
  else {
    *ch = get;
    return false;
  }
}

#define CHECK_READ(self, is_eof, read_fail) \
  if (lumi_debug_value == LUMI_DEBUG_FAIL || read_fail) { \
    if (lumi_debug_value == LUMI_DEBUG_FAIL || feof(self->fobj) != 0) \
      CRAISE(LUMI_error_messages.file_read_failed.str); \
    is_eof = true; }

#define LUMI_FUNC_NAME "FileReadText.get"
Return_Code FileReadText_get(FileReadText* self, Char* out_char, Bool* is_eof) {
  CHECK_OPEN(self)
  CHECK_READ(self, *is_eof, getc_is_not_ok(getc(self->fobj), out_char))
  return OK;
}
#undef LUMI_FUNC_NAME
#define FileReadWriteText_get(self, out_char, is_eof) \
  FileReadText_get(self, out_char, is_eof)

#define LUMI_FUNC_NAME "FileReadBinary.get"
Return_Code FileReadBinary_get(
    FileReadBinary* self, Byte* out_byte, Bool* is_eof) {
  CHECK_OPEN(self)
  CHECK_READ(self, *is_eof, fread(out_byte, sizeof(Byte), 1, self->fobj) < 1)
  return OK;
}
#undef LUMI_FUNC_NAME
#define FileReadWriteBinary_get(self, out_byte, is_eof) \
  FileReadBinary_get(self, out_byte, is_eof)

#define LUMI_FUNC_NAME "FileReadText.getline-internal"
Return_Code FileReadText_getline_internal(
    FileReadText* self,
    char* line, Seq_Length line_max_length, Seq_Length* line_length,
    Bool* is_eof,
    int (*char_getter)(FileReadText*)) {
  int ch = EOF;
  *line_length = 0;
  line[0] = '\0';
  if (lumi_debug_value == LUMI_DEBUG_NOTHING) {
    ch = char_getter(self);
  } else if (lumi_debug_value == LUMI_DEBUG_SUCCESS) {
    ch = 'a';
  }
  while (ch != EOF && ch != '\n') {
    if (*line_length + 1 >= line_max_length)
      CRAISE(LUMI_error_messages.sequence_too_short.str)
    line[*line_length] = ch;
    ++(*line_length);
    if (lumi_debug_value != LUMI_DEBUG_SUCCESS) {
      ch = getc(self->fobj);
    }
  }
  line[*line_length] = '\0';
  CHECK_READ(self, *is_eof, ch == EOF)
  return OK;
}
#undef LUMI_FUNC_NAME

int getc_char_getter(FileReadText* self) {
  return getc(self->fobj);
}

#define LUMI_FUNC_NAME "FileReadText.getline"
Return_Code FileReadText_getline(
    FileReadText* self,
    char* line, Seq_Length line_max_length, Seq_Length* line_length,
    Bool* is_eof) {
  CHECK_OPEN(self)
  CCHECK(FileReadText_getline_internal(
      self, line, line_max_length, line_length, is_eof, getc_char_getter))
  return OK;
}
#undef LUMI_FUNC_NAME
#define FileReadWriteText_getline(self, line, line_max_length, line_length, is_eof) \
  FileReadText_getline(self, line, line_max_length, line_length, is_eof)

#define LUMI_FUNC_NAME "FileReadBinary.read"
Return_Code FileReadBinary_read(
    FileReadBinary* self, Byte* data, Seq_Length data_length, Seq_Length* bytes_read) {
  Bool is_eof;
  *bytes_read = 0;
  CHECK_OPEN(self)
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    *bytes_read = fread(data, sizeof(Byte), data_length, self->fobj);
  }
  CHECK_READ(self, is_eof, *bytes_read < data_length)
  return OK;
}
#undef LUMI_FUNC_NAME
#define FileReadWriteBinary_read(self, data, data_length, bytes_read) \
  FileReadBinary_read(self, data, data_length, bytes_read)

#define LUMI_FUNC_NAME "FileWriteText.put"
Return_Code FileWriteText_put(FileWriteText* self, Char ch) {
  CHECK_OPEN(self)
  if (lumi_debug_value == LUMI_DEBUG_FAIL || putc(ch, self->fobj) != ch)
    CRAISE(LUMI_error_messages.file_write_failed.str)
  return OK;
}
#undef LUMI_FUNC_NAME
#define FileReadWriteText_put(self, ch) FileWriteText_put(self, ch)

#define LUMI_FUNC_NAME "FileWriteBinary.put"
Return_Code FileWriteBinary_put(FileWriteBinary* self, Byte value) {
  CHECK_OPEN(self)
  if (lumi_debug_value == LUMI_DEBUG_FAIL ||
      fwrite(&value, sizeof(value), 1, self->fobj) < 1)
    CRAISE(LUMI_error_messages.file_write_failed.str)
  return OK;
}
#undef LUMI_FUNC_NAME
#define FileReadWriteBinary_put(self, value) FileWriteBinary_put(self, value)

#define LUMI_FUNC_NAME "FileWriteText.write"
Return_Code FileWriteText_write(
    FileWriteText* self, char* text, Seq_Length text_length, Seq_Length* written) {
  *written = 0;
  CHECK_OPEN(self)
  while (*written < text_length) {
    int ch;
    ch = text[*written];
    if (lumi_debug_value == LUMI_DEBUG_FAIL || putc(ch, self->fobj) != ch)
      CRAISE(LUMI_error_messages.file_write_failed.str)
    ++(*written);
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#define FileReadWriteText_write(self, text, text_length, written) \
  FileWriteText_write(self, text, text_length, written)

#define LUMI_FUNC_NAME "FileWriteBinary.write"
Return_Code FileWriteBinary_write(
    FileWriteBinary* self, Byte* data, Seq_Length data_length, Seq_Length* written) {
  *written = 0;
  CHECK_OPEN(self)
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    *written = fwrite(data, sizeof(Byte), data_length, self->fobj);
  }
  if (*written < data_length) CRAISE(LUMI_error_messages.file_write_failed.str)
  return OK;
}
#undef LUMI_FUNC_NAME
#define FileReadWriteBinary_write(self, data, data_length, written) \
  FileWriteBinary_write(self, data, data_length, written)


/* system */

Return_Code set_sys(int argc, char* argv[]) {
  int arg;
  sys_M_stdin = LUMI_alloc(sizeof(File));
  sys_M_stdin_Refman = LUMI_new_ref(sys_M_stdin);
  sys_M_stdout = LUMI_alloc(sizeof(File));
  sys_M_stdout_Refman = LUMI_new_ref(sys_M_stdout);
  sys_M_stderr = LUMI_alloc(sizeof(File));
  sys_M_stderr_Refman = LUMI_new_ref(sys_M_stderr);
  sys_M_argv_Length = argc;
  sys_M_argv_Value_length = 0;
  sys_M_argv_Seq_length = LUMI_alloc(sizeof(Seq_Length) * argc);
  for (arg = 0; arg < argc; ++arg) {
    Seq_Length length = cstring_length(argv[arg], 1024);
    if (sys_M_argv_Seq_length != NULL) {
      sys_M_argv_Seq_length[arg] = length;
    }
    if (length > sys_M_argv_Value_length) {
      sys_M_argv_Value_length = length;
    }
  }
  ++sys_M_argv_Value_length;
  sys_M_argv = LUMI_alloc(sys_M_argv_Value_length * sys_M_argv_Length);
  sys_M_argv_Refman = LUMI_new_ref(sys_M_argv);
  if (sys_M_argv == NULL || sys_M_argv_Refman == NULL ||
    sys_M_argv_Seq_length == NULL ||
    sys_M_stdin == NULL || sys_M_stdin_Refman == NULL ||
    sys_M_stdout == NULL || sys_M_stdout_Refman == NULL ||
    sys_M_stderr == NULL || sys_M_stderr_Refman == NULL) {
    fprintf(stderr, "insufficient memory\n");
    return ERR;
  }
  ++sys_M_argv_Refman->count;
  ++sys_M_stdin_Refman->count;
  ++sys_M_stdout_Refman->count;
  ++sys_M_stderr_Refman->count;
  sys_M_stdin->fobj = stdin;
  sys_M_stdout->fobj = stdout;
  sys_M_stderr->fobj = stderr;
  for (arg = 0; arg < argc; ++arg) {
    strncpy(sys_M_argv + sys_M_argv_Value_length * arg, argv[arg], sys_M_argv_Length);
  }
  return OK;
}

#define LUMI_FUNC_NAME "sys.print"
Return_Code sys_M_print(char* text, Seq_Length text_length) {
  Seq_Length n;
  int ch;
  for (n = 0; n < text_length; ++n) {
    ch = text[n];
    if (lumi_debug_value == LUMI_DEBUG_FAIL || ch != putchar(ch))
      CRAISE(LUMI_error_messages.file_write_failed.str)
  }
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "sys.println"
Return_Code sys_M_println(char* text, Seq_Length text_length) {
  sys_M_print(text, text_length);
  if (lumi_debug_value == LUMI_DEBUG_FAIL || putchar('\n') != '\n')
    CRAISE(LUMI_error_messages.file_write_failed.str)
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "sys.getchar"
Return_Code sys_M_getchar(char* out_char, Bool* is_eof) {
  CHECK_READ(sys_M_stdin, *is_eof, getc_is_not_ok(getchar(), out_char))
  return OK;
}
#undef LUMI_FUNC_NAME

int getchar_char_getter(FileReadText* self) {
  return getchar();
}

#define LUMI_FUNC_NAME "sys.getline"
Return_Code sys_M_getline(
    char* line, Seq_Length line_max_length, Seq_Length* line_length, Bool* is_eof) {
  CCHECK(FileReadText_getline_internal(
      sys_M_stdin,
      line, line_max_length, line_length,
      is_eof,
      getchar_char_getter))
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "sys.exit"
Return_Code sys_M_exit(int32_t status) {
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    exit(status);
  }
  CRAISE("exit failed")
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "sys.system"
Return_Code sys_M_system(
    char* command, Seq_Length command_max_length, Seq_Length *command_length,
    int32_t* status) {
  int res = -1;
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    res = system(command);
  }
  if (res == -1) CRAISE("command execution failed")
  *status = res;
  return OK;
}
#undef LUMI_FUNC_NAME

Return_Code sys_M_getenv(
    char* name, Seq_Length name_max_length, Seq_Length *name_length,
    char* value, Seq_Length value_max_length, Seq_Length* value_length,
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
