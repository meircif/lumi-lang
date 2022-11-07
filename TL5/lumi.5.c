#ifdef _MSC_VER
  #define _CRT_SECURE_NO_WARNINGS
  #pragma section(".CRT$XCU",read)
  #define INITIALIZER2_(f,p) \
    static void f(void); \
    __declspec(allocate(".CRT$XCU")) void (*f##_)(void) = f; \
    __pragma(comment(linker,"/include:" p #f "_")) \
    static void f(void)
  #ifdef _WIN64
    #define INITIALIZER(f) INITIALIZER2_(f,"")
  #else
    #define INITIALIZER(f) INITIALIZER2_(f,"_")
  #endif
  #define MAIN_INIT(f)
#else
  #ifdef __GNUC__
    #define INITIALIZER(f) \
      static void f(void) __attribute__((constructor)); \
      static void f(void)
    #define MAIN_INIT(f)
  #else
    #define INITIALIZER(f) static void f(void)
    #define MAIN_INIT(f) f();
  #endif
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
  #ifndef WIN_IMPORT
    #ifdef __GNUC__
      #define EXPORTED __attribute__ ((dllexport))
    #else
      #define EXPORTED __declspec(dllexport)
    #endif
  #else
    #ifdef __GNUC__
      #define EXPORTED __attribute__ ((dllimport))
    #else
      #define EXPORTED __declspec(dllimport)
    #endif
  #endif
  #define NOT_EXPORTED
#else
  #if __GNUC__ >= 4
    #define EXPORTED __attribute__ ((visibility ("default")))
    #define NOT_EXPORTED  __attribute__ ((visibility ("hidden")))
  #else
    #define EXPORTED
    #define NOT_EXPORTED
  #endif
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifndef UINT8_MAX
  #define UINT8_MAX 0xff
#endif
#ifndef INT8_MAX
  #define INT8_MAX 0x7f
#endif
#ifndef UINT16_MAX
  #define UINT16_MAX 0xffff
#endif
#ifndef INT16_MAX
  #define INT16_MAX 0x7fff
#endif
#ifndef UINT32_MAX
  #define UINT32_MAX 0xffffffff
#endif
#ifndef INT32_MAX
  #define INT32_MAX 0x7fffffff
#endif
#ifndef UINT64_MAX
  #define UINT64_MAX 0xffffffffffffffff
#endif
#ifndef INT64_MAX
  #define INT64_MAX 0x7fffffffffffffff
#endif

/* builtin type defines */

typedef uint32_t Char;
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

typedef struct String {
  Byte* bytes;
  uint32_t length;
} String;

typedef struct File {
  FILE* fobj;
} File;

typedef File FileReadText;
typedef File FileReadBinary;
typedef File FileWriteText;
typedef File FileWriteBinary;
typedef File FileReadWriteText;
typedef File FileReadWriteBinary;

#define VAR_POINTER(type, name) \
  type name##_Var; \
  type* name = &name##_Var;
#define VAR_REFMAN(type, name) \
  VAR_POINTER(type, name) \
  VAR_POINTER(Ref_Manager, name##_Refman)

String* sys_M_argv = NULL;
uint32_t sys_M_argv_Length = 0;
VAR_POINTER(Ref_Manager, sys_M_argv_Refman)
VAR_REFMAN(File, sys_M_stdin)
VAR_REFMAN(File, sys_M_stdout)
VAR_REFMAN(File, sys_M_stderr)

typedef void* Ref;

typedef char cdef_M_Char;
typedef signed char cdef_M_Schar;
typedef unsigned char cdef_M_Uchar;
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
  Byte* str;
  unsigned length;
} Error_Message;

typedef struct Error_Messages {
  Error_Message empty_object;
  Error_Message outdated_weak_reference;
  Error_Message object_memory;
  Error_Message managed_object_memory;
  Error_Message integer_overflow;
  Error_Message slice_index;
  Error_Message array_too_short;
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
      line, cleanup, FAIL, LUMI_assert_format, (Byte*)message, message_length)

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

#define ARRAY_DEL(Type, array, length) if (array != NULL) { \
  uint32_t LUMI_n = 0; \
  for (; LUMI_n < length; ++LUMI_n) \
    Type##_Del(array + LUMI_n, NULL); \
  }

#define ARRAY_DEL_DYN(Type, array, length) if (array != NULL) { \
  uint32_t LUMI_n = 0; \
  for (; LUMI_n < length; ++LUMI_n) \
    Type##_Del(array + LUMI_n, &Type##_dynamic); \
  }

#define SELF_REF_DEL(Type, field, _) \
while (self->field != NULL) { \
  Type* value = self->field; \
  self->field = value->field; \
  value->field = NULL; \
  Type##_Del(value, NULL); \
  free(value); \
}

#define SELF_REF_DEL_STR(Type, field, _) \
while (self->field != NULL) { \
  Type* value = self->field; \
  Ref_Manager* value_Refman = self->field##_Refman; \
  self->field = value->field; \
  self->field##_Refman = value->field##_Refman; \
  value->field = NULL; \
  value->field##_Refman = NULL; \
  Type##_Del(value, NULL); \
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
  name##_Refman = LUMI_new_ref(&name); \
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

#define INIT_NEW_LEN_ARRAY(line, cleanup, name, type, length, value_size) \
  name##_Length = length; \
  INIT_NEW_ARRAY(line, cleanup, name, type, name##_Length, value_size)

#define INIT_NEW_ARRAY(line, cleanup, name, type, length, value_size) \
  INIT_NEW(line, cleanup, name, type, length * value_size)

#define SAFE_SUM_LARGER(a, b, c) a > c || b > c - a

#define NULL_OR_VALUE(base, value) base != NULL? value: NULL


/* traceback */

#define CRAISE(message) { \
  LUMI_C_trace_print(__LINE__, LUMI_FUNC_NAME, (Byte*)message); \
  return ERR; }
#define CCHECK(err) { \
  Return_Code LUMI_cerr = err; \
  if (LUMI_cerr != OK) return LUMI_cerr; }

char* LUMI_raise_format = "Error raised in %s:%lu %s()\n";
char* LUMI_assert_format = "Assert failed in %s:%lu %s()\n";
char* LUMI_traceline_format = "  called from %s:%lu %s()\n";
FILE* LUMI_trace_stream = NULL;
size_t LUMI_trace_ignore_count = 0;
Byte* LUMI_expected_error = NULL;
size_t LUMI_expected_error_trace_ignore_count = 0;
Generic_Type_Dynamic* dynamic_Void = NULL;
void LUMI_nop_Del(void* _, void* __) {}
Generic_Type_Dynamic LUMI_nop_dynamic = { LUMI_nop_Del };


#define ERROR_MESAGE(message) {(Byte*)message, sizeof(message) - 1}

Error_Messages LUMI_error_messages = {
  ERROR_MESAGE("empty object used"),
  ERROR_MESAGE("outdated weak reference used"),
  ERROR_MESAGE("insufficient memory for object dynamic allocation"),
  ERROR_MESAGE("insufficient memory for managed object"),
  ERROR_MESAGE("integer overflow"),
  ERROR_MESAGE("slice index out of bounds"),
  ERROR_MESAGE("array too short"),
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
    Byte const* message,
    uint32_t message_length) {
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
    uint32_t n;
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
uint32_t cstring_length(Byte* cstring) {
  uint32_t length = 0;
  while (cstring[length] != '\0' && length < UINT32_MAX - 1) {
    ++length;
  }
  return length;
}

void LUMI_C_trace_print(Line_Count line, char const* funcname, Byte* message) {
  LUMI_trace_print(
      LUMI_raise_format,
      "builtin",
      line,
      funcname,
      message,
      cstring_length(message));
}


/* initialize */

#define LUMI_INIT_FUNC(init_func) INITIALIZER(LUMI_initialization) { \
  Return_Code err; \
  LUMI_trace_stream = stderr; \
  err = init_func(); \
  if (err != OK) { \
    fprintf(stderr, "  called from lumi initialization\n"); \
    exit(err); \
  } \
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
      sys_M_argv_Length > 1 && sys_M_argv[1].length > 1) {
    String* arg = sys_M_argv + 1;
    generate_xml = arg->bytes[0] == '-' && arg->bytes[1] == 'x';
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
          printf(" %ld", first_uncovered);
          if (first_uncovered < line - 1) {
            printf("-%ld", line - 1);
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
#define cdef_M_Pointer_get_pointed_at(pointer, index) pointer[index]
#define cdef_M_Pointer_get_ref_at(pointer, index) (pointer + index)


/* Int */

void String_clear(String* self);

#define LUMI_FUNC_NAME "Int.str"
Return_Code Int_str(uint64_t abs, Bool is_neg, String* str, Bool is_append) {
  uint64_t tmp;
  uint64_t swaped = 0;
  uint32_t digits = 1;
  Byte* bytes = NULL;
  tmp = abs;
  while (tmp > 9) {
    ++digits;
    swaped = swaped * 10 + tmp % 10;
    tmp /= 10;
  }
  if (lumi_debug_value == LUMI_DEBUG_FAIL) {
    bytes = NULL;
  } else if (is_append) {
    bytes = realloc(str->bytes, str->length + digits + is_neg + 1);
  } else {
    bytes = malloc(digits + is_neg + 1);
  }
  if (bytes == NULL) CRAISE(LUMI_error_messages.object_memory.str)
  if (!is_append) {
    String_clear(str);
  }
  str->bytes = bytes;
  if (is_append) {
    bytes += str->length;
    str->length += digits + is_neg;
  }
  else {
    str->length = digits + is_neg;
  }
  if (is_neg) {
    *bytes = '-';
    ++bytes;
  }
  *bytes = '0' + tmp;
  while (digits > 1) {
    ++bytes;
    *bytes = '0' + swaped % 10;
    swaped /= 10;
    --digits;
  }
  bytes[1] = '\0';
  return OK;
}
#undef LUMI_FUNC_NAME

#define Int_strU(value, str) Int_str(value, false, str, false)
#define Int_strS(value, str) Int_strS_append(value, str, false)
#define Int_strS_append(value, str, is_append) \
    Int_str((value) < 0? -(value): (value), (value) < 0, str, is_append)

#define CHECK_MIN_ADD(a, b) ((a < 0) && (b < 0) && (-a > INT64_MAX + b))
#define CHECK_MAX_ADD(a, b, limit) ((a > 0) && (b > 0) && (a > limit - b))

#define CHECK_MIN_SUB(a, b) \
  ((b > 0) && ((int64_t)a < (int64_t)(-INT64_MAX + b)))
#define CHECK_MAX_SUB(a, b, limit) ((a > 0) && (b < 0) && (a > limit + b))

#define CHECK_MIN_MUL(a, b) \
  ((a < 0) && (b > INT64_MAX / (-a))) || ((b < 0) && (a > INT64_MAX / (-b)))
#define CHECK_MAX_MUL(a, b, limit) \
  ((a > 0) && (b > limit / a)) || ((b < 0) && (-a > limit / (-b)))
  
#define CLAMPED_ADD_UU_LIMIT(a, b, max, LIMIT) \
  ((a > LIMIT - b) || (a + b > max))? max: (a + b)
#define CLAMPED_ADD_UU(a, b, min, max) \
  CLAMPED_ADD_UU_LIMIT(a, b, max, UINT64_MAX)
#define CLAMPED_ADD_US(a, b, min, max) (b > 0)? \
  (CLAMPED_ADD_UU(a, b, min, max)): (((-b > a) || (a + b < min))? min: (a + b))
#define CLAMPED_ADD_SU(a, b, min, max) \
  (a > 0)? (CLAMPED_ADD_UU(a, b, min, max)): ((a + b > max)? max: (a + b))
#define CLAMPED_ADD_SS(a, b, min, max) (b > 0)? \
  (CLAMPED_ADD_UU_LIMIT(a, b, max, INT64_MAX)): \
  (((a < INT64_MIN - b) || (a + b < min))? min: (a + b))

#define CLAMPED_SUB_SN_LIMIT(a, b, max, LIMIT) \
  (((a > LIMIT + b) || (a - b > max))? max: (a - b))
#define CLAMPED_SUB_UU(a, b, min, max) ((a < b) || (a - b < min))? min: (a - b)
#define CLAMPED_SUB_US(a, b, min, max) (b > 0)? \
  (CLAMPED_SUB_UU(a, b, min, max)): CLAMPED_SUB_SN_LIMIT(a, b, max, UINT64_MAX)
#define CLAMPED_SUB_SU(a, b, min, max) \
  ((a < (int64_t)(INT64_MIN + b)) || (a - b < min))? min: (a - b)
#define CLAMPED_SUB_SS(a, b, min, max) (b > 0)? \
  (CLAMPED_SUB_SU(a, b, min, max)): CLAMPED_SUB_SN_LIMIT(a, b, max, INT64_MAX)

#define CLAMPED_MUL_UP_LIMIT(a, b, max, CMP_LIMIT) \
  (((a CMP_LIMIT / b) || (a * b > max))? max: (a * b))
#define CLAMPED_MUL_UP(a, b, max) CLAMPED_MUL_UP_LIMIT(a, b, max, > UINT64_MAX)
#define CLAMPED_MUL_UN(a, b, min, cmp) \
  (((a cmp INT64_MIN / b) || (a * b < min))? min: (a * b))
#define CLAMPED_MUL_UU(a, b, min, max) (a == 0 || b == 0)? min: \
  CLAMPED_MUL_UP(a, b, max)
#define CLAMPED_MUL_US(a, b, min, max) (a == 0 || b == 0)? min: \
  ((b > 0)? CLAMPED_MUL_UP(a, b, max): CLAMPED_MUL_UN(a, b, min, >=))
#define CLAMPED_MUL_SU(a, b, min, max) (a == 0 || b == 0)? (max < 0? max: 0): \
  (a > 0)? CLAMPED_MUL_UP(a, b, max): CLAMPED_MUL_UN(a, b, min, >=)
#define CLAMPED_MUL_SS(a, b, min, max) (a == 0 || b == 0)? (max < 0? max: 0): \
  ((a > 0)? \
    ((b > 0)? CLAMPED_MUL_UP_LIMIT(a, b, max, > INT64_MAX): \
      CLAMPED_MUL_UN(a, b, min, >=)): \
    ((b > 0)? CLAMPED_MUL_UN(a, b, min, <=): \
      CLAMPED_MUL_UP_LIMIT(a, b, max, < INT64_MAX)))


/* Buffer */

void cdef_M_copy_to_buffer(
    Byte* source, Byte* target, uint32_t target_length) {
  if (source != NULL) {
    memcpy(target, source, target_length);
  }
}


/* String */

Byte String_empty_string[1] = {'\0'};

void String_Del(String* self, void* _) {
  if (self == NULL) return;
  if (self->bytes != String_empty_string) {
    free(self->bytes);
  }
  self->bytes = NULL;
}

Generic_Type_Dynamic String_dynamic = { (Dynamic_Del)String_Del };

#define String_length(self, length_out) *(length_out) = (self)->length

void String_clear(String* self) {
  if (self->bytes != String_empty_string) {
    free(self->bytes);
  }
  self->bytes = String_empty_string;
  self->length = 0;
}

#define LUMI_FUNC_NAME "String.new"
Return_Code String_new(String* self, Byte* source, uint32_t source_length) {
  Byte* new_bytes = NULL;
  if (source_length == 0) {
    new_bytes = String_empty_string;
  } else {
    if (lumi_debug_value == LUMI_DEBUG_FAIL) {
      new_bytes = NULL;
    } else {
      new_bytes = malloc(source_length + 1);
    }
    if (new_bytes == NULL) CRAISE(LUMI_error_messages.object_memory.str)
    memcpy(new_bytes, source, source_length);
    new_bytes[source_length] = '\0';
  }
  String_clear(self);
  self->bytes = new_bytes;
  self->length = source_length;
  return OK;
}
#undef LUMI_FUNC_NAME

void String_bytes(String* self, Byte** bytes, uint32_t* bytes_length) {
  if (self->bytes == NULL) {
    self->bytes = String_empty_string;
  }
  *bytes = self->bytes;
  *bytes_length = self->length;
}

char* cdef_M_string_pointer(String* self) {
  if (self->bytes == NULL) {
    self->bytes = String_empty_string;
  }
  return (char*)(self->bytes);
}

#define LUMI_FUNC_NAME "cdef.copy-to-string"
Return_Code cdef_M_copy_to_string(char* source, String* self) {
  CCHECK(String_new(
      self, (Byte*)source, cstring_length((Byte*)source)))
  return OK;
}
#undef LUMI_FUNC_NAME

void String_equal(
    String* self, Byte* other, uint32_t other_length, Bool* out_equal) {
  if (self->bytes == NULL) {
    self->bytes = String_empty_string;
  }
  if (self->length != other_length) {
    *out_equal = false;
    return;
  }
  if (self->bytes == other) {
    *out_equal = true;
    return;
  }
  *out_equal = strncmp((char*)(self->bytes), (char*)other, other_length) == 0;
}

#define LUMI_FUNC_NAME "String.get"
Return_Code String_get(String* self, uint32_t index, Char* out_char) {
  /*CHECK_INDEX(index, length)
  *out_char = self[index];*/
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.set"
Return_Code String_set(String* self, uint32_t index, Char ch) {
  /*CHECK_INDEX(index, length)
  self[index] = ch;*/
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.concat"
Return_Code String_concat(String* self, Byte* ext, uint32_t ext_length) {
  Byte *new_bytes;
  if (lumi_debug_value == LUMI_DEBUG_FAIL) {
    new_bytes = NULL;
  } else if (self->length == 0) {
    new_bytes = malloc(ext_length + 1);
  } else {
    new_bytes = realloc(self->bytes, self->length + ext_length + 1);
  }
  if (new_bytes == NULL) CRAISE(LUMI_error_messages.object_memory.str)
  memcpy(new_bytes + self->length, ext, ext_length);
  self->length += ext_length;
  new_bytes[self->length] = '\0';
  self->bytes = new_bytes;
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "String.append"
Return_Code String_append(String* self, Char ch) {
  Byte tmp;
  if (ch > 255) CRAISE("appending character values over 255 not suppored yet")
  tmp = ch;
  CCHECK(String_concat(self, &tmp, 1))
  return OK;
}
#undef LUMI_FUNC_NAME

#define String_concat_int(self, value) \
  Int_strS_append(value, self, (self)->length > 0)

void String_find(
    String* self,
    Byte* pattern, uint32_t pattern_length,
    uint32_t* out_index) {
  /*uint32_t n;
  for (n = 0; n <= *length - pattern_length; ++n) {
    if (strncmp((char*)self + n, (char*)pattern, pattern_length) == 0) {
      *out_index = n;
      return;
    }
  }
  *out_index = *length;*/
}

void String_has(
    String* self, Char ch, Bool* found) {
  uint32_t n;
  for (n = 0; n < self->length; ++n) {
    if (self->bytes[n] == ch) {
      *found = true;
      return;
    }
  }
  *found = false;
}


/* File */

void File_Del(File* self, void* _) {
  if (self != NULL && self->fobj != NULL) {
    fclose(self->fobj);
    self->fobj = NULL;
  }
}
#define FileReadText_Del(self, _) File_Del(self, _)
#define FileReadBinary_Del(self, _) File_Del(self, _)
#define FileWriteText_Del(self, _) File_Del(self, _)
#define FileWriteBinary_Del(self, _) File_Del(self, _)
#define FileReadWriteText_Del(self, _) File_Del(self, _)
#define FileReadWriteBinary_Del(self, _) File_Del(self, _)

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
Return_Code File_new(File* self, String* name, char* mode) {
  if (lumi_debug_value == LUMI_DEBUG_NOTHING) {
    CCHECK(File_close(self))
  }
  if (lumi_debug_value != LUMI_DEBUG_SUCCESS) {
    if (lumi_debug_value != LUMI_DEBUG_FAIL) {
      self->fobj = fopen((char*)(name->bytes), mode);
    }
    if (self->fobj == NULL) CRAISE("open file failed")
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#define FileReadText_new(self, name) File_new(self, name, "r")
#define FileReadBinary_new(self, name) File_new(self, name, "rb")
#define FileWriteText_new(self, name, append) \
  File_new(self, name, append? "a": "w")
#define FileWriteBinary_new(self, name, append) \
  File_new(self, name, append? "ab": "wb")
#define FileReadWriteText_new(self, name, append, exist) \
  File_new(self, name, append? "a+": exist? "r+": "w+")
#define FileReadWriteBinary_new(self, name, append, exist) \
  File_new(self, name, append? "ab+": exist? "rb+": "wb+")

#define CHECK_OPEN(self) \
  if (lumi_debug_value != LUMI_DEBUG_FAIL && self->fobj == NULL) \
    CRAISE(LUMI_error_messages.file_not_opened.str)

#define LUMI_FUNC_NAME "File.tell"
Return_Code File_tell(File* self, int64_t* offset) {
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
Return_Code File_seek(File* self, int64_t offset, int whence) {
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

Bool getc_is_not_ok(int get, Byte* ch) {
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
Return_Code FileReadText_get(FileReadText* self, Byte* out_char, Bool* is_eof) {
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
    Byte* target, uint32_t target_length,
    Byte** line, uint32_t* line_length,
    Bool* is_eof,
    int (*char_getter)(FileReadText*)) {
  int ch = EOF;
  *line = target;
  *line_length = 0;
  if (lumi_debug_value == LUMI_DEBUG_NOTHING) {
    ch = char_getter(self);
  } else if (lumi_debug_value == LUMI_DEBUG_SUCCESS) {
    ch = 'a';
  }
  while (ch != EOF && ch != '\n') {
    if (*line_length >= target_length)
      CRAISE(LUMI_error_messages.array_too_short.str)
    target[*line_length] = ch;
    ++(*line_length);
    if (lumi_debug_value != LUMI_DEBUG_SUCCESS) {
      ch = getc(self->fobj);
    }
  }
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
    Byte* target, uint32_t target_length,
    Byte** line, uint32_t* line_length,
    Bool* is_eof) {
  CHECK_OPEN(self)
  CCHECK(FileReadText_getline_internal(
      self, target, target_length, line, line_length, is_eof, getc_char_getter))
  return OK;
}
#undef LUMI_FUNC_NAME
#define FileReadWriteText_getline(self, line, line_max_length, line_length, is_eof) \
  FileReadText_getline(self, line, line_max_length, line_length, is_eof)

#define LUMI_FUNC_NAME "FileReadBinary.read"
Return_Code FileReadBinary_read(
    FileReadBinary* self,
    Byte* data, uint32_t data_length,
    uint32_t* bytes_read) {
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
    FileWriteText* self, Byte* text, uint32_t text_length, uint32_t* written) {
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
    FileWriteBinary* self,
    Byte* data, uint32_t data_length,
    uint32_t* written) {
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

#define INIT_REFMAN(name) \
  name##_Refman->count = 2; \
  name##_Refman->value = name; \
  name##_Refman->ref = name;

Return_Code set_sys(int argc, char* argv[]) {
  int arg;
  sys_M_argv_Length = argc;
  sys_M_argv = LUMI_alloc(sizeof(String) * argc);
  if (sys_M_argv == NULL) {
    fprintf(stderr, "insufficient memory\n");
    return ERR;
  }
  INIT_REFMAN(sys_M_argv)
  INIT_REFMAN(sys_M_stdin)
  INIT_REFMAN(sys_M_stdout)
  INIT_REFMAN(sys_M_stderr)
  sys_M_stdin->fobj = stdin;
  sys_M_stdout->fobj = stdout;
  sys_M_stderr->fobj = stderr;
  for (arg = 0; arg < argc; ++arg) {
    sys_M_argv[arg].bytes = (Byte*)(argv[arg]);
    sys_M_argv[arg].length = cstring_length(sys_M_argv[arg].bytes);
  }
  return OK;
}

#define LUMI_FUNC_NAME "sys.print"
Return_Code sys_M_print(Byte* text, uint32_t text_length) {
  uint32_t n;
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
Return_Code sys_M_println(Byte* text, uint32_t text_length) {
  sys_M_print(text, text_length);
  if (lumi_debug_value == LUMI_DEBUG_FAIL || putchar('\n') != '\n')
    CRAISE(LUMI_error_messages.file_write_failed.str)
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "sys.getchar"
Return_Code sys_M_getchar(Char* out_char, Bool* is_eof) {
  Byte byte;
  CHECK_READ(sys_M_stdin, *is_eof, getc_is_not_ok(getchar(), &byte))
  *out_char = byte;
  return OK;
}
#undef LUMI_FUNC_NAME

int getchar_char_getter(FileReadText* self) {
  return getchar();
}

#define LUMI_FUNC_NAME "sys.getline"
Return_Code sys_M_getline(
    Byte* target, uint32_t target_length,
    Byte** line, uint32_t* line_length,
    Bool* is_eof) {
  CCHECK(FileReadText_getline_internal(
      sys_M_stdin,
      target, target_length,
      line, line_length,
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
Return_Code sys_M_system(String* command, int32_t* status) {
  int res = -1;
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    res = system((char*)(command->bytes));
  }
  if (res == -1) CRAISE("command execution failed")
  *status = res;
  return OK;
}
#undef LUMI_FUNC_NAME

#define LUMI_FUNC_NAME "sys.getenv"
Return_Code sys_M_getenv(String* name, String* value, Bool* exists) {
  char* ret;
  Byte* new_bytes = NULL;
  uint32_t length;
  if (lumi_debug_value != LUMI_DEBUG_FAIL) {
    ret = getenv((char*)(name->bytes));
    if (ret == NULL) {
      *exists = false;
      return OK;
    }
    length = cstring_length((Byte*)ret);
    new_bytes = malloc(length + 1);
  }
  if (new_bytes == NULL) CRAISE(LUMI_error_messages.object_memory.str)
  memcpy(new_bytes, ret, length + 1);
  String_clear(value);
  value->bytes = new_bytes;
  value->length = length;
  *exists = true;
  return OK;
}
#undef LUMI_FUNC_NAME
