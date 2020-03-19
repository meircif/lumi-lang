#ifndef LUMI_TL4_LUMI_4_H_INCLUDED_
#define LUMI_TL4_LUMI_4_H_INCLUDED_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int Int;
typedef char Char;
typedef unsigned char Byte;

typedef struct {
  int max_length;
  int length;
  char* values;
} String;

typedef enum {
  false = 0,
  true = 1
} Bool;

typedef enum {
  OK = EXIT_SUCCESS,
  ERR = EXIT_FAILURE,
  FAIL = EXIT_FAILURE > EXIT_SUCCESS? EXIT_FAILURE + 1 : EXIT_SUCCESS + 1
} Returncode;

typedef struct {
  int length;
  void* values;
} Array;

typedef Returncode (*Func)();

typedef struct {
  FILE* fobj;
} File;

typedef struct {
  Byte* number;
  int length;
  int sign;
} Long;

typedef void* Ref;

typedef struct {
  int count;
  void* value;
  void* ref;
} Ref_Manager;

typedef struct {
  char const* filename;
  int lines_number;
  int* line_count;
} File_Coverage;

typedef void (*Dynamic_Del)(void*);

typedef void Generic_Type;
typedef struct { Dynamic_Del _del; } Generic_Type_Dynamic;
extern Generic_Type_Dynamic* dynamic_Void;


typedef struct {
  String str;
  Ref_Manager refman;
} Error_Message;

typedef struct {
  Error_Message empty_object;
  Error_Message outdated_weak_reference;
  Error_Message object_memory;
  Error_Message managed_object_memory;
  Error_Message empty_base_output;
  Error_Message slice_index;
} Error_Messages;

extern Error_Messages LUMI_error_messages;


extern char* LUMI_raise_format;
extern char* LUMI_assert_format;
extern char* LUMI_traceline_format;
extern int LUMI_trace_ignore_count;
extern char* LUMI_expected_error;
extern int LUMI_expected_error_trace_ignore_count;
void LUMI_trace_print(
  char const* format,
  char const* filename,
  int line,
  char const* funcname,
  String* message,
  Ref_Manager* message_refman);

#define RETURN_ERROR goto LUMI_cleanup

#define START_TRACE(line, value, format, message, message_refman) \
  LUMI_trace_print( \
      format, LUMI_FILE_NAME, line, LUMI_FUNC_NAME, message, message_refman); \
  LUMI_err = value; \
  RETURN_ERROR;

#define START_TRACE_STATIC(line, err_value, format, message_length, message) { \
  String LUMI_msg = { message_length + 1, message_length, message }; \
  Ref_Manager LUMI_msg_refman = { 1, NULL, NULL }; \
  LUMI_msg_refman.value = &LUMI_msg; \
  START_TRACE(line, err_value, format, &LUMI_msg, &LUMI_msg_refman) }

#define RAISE(line, message) { \
  START_TRACE( \
      line, ERR, LUMI_raise_format, \
      &(LUMI_error_messages.message.str), \
      &(LUMI_error_messages.message.refman)) }

#define USER_RAISE(line, message, message_refman) \
  { START_TRACE(line, ERR, LUMI_raise_format, message, message_refman) }

#define TEST_FAIL(line, message_length, message) \
  START_TRACE_STATIC(line, FAIL, LUMI_assert_format, message_length, message)

#define TEST_ASSERT(line, condition) if (!(condition)) \
  TEST_FAIL(line, 21, "condition is not true")

#define TEST_FAIL_NULL(line) \
  { START_TRACE(line, FAIL, LUMI_assert_format, NULL, NULL) }

#define CHECK(line) if (LUMI_err != OK) { \
  LUMI_trace_print( \
      LUMI_traceline_format, LUMI_FILE_NAME, line, LUMI_FUNC_NAME, \
      NULL, NULL); \
  RETURN_ERROR; }

#define IGNORE_ERRORS(call) \
  ++LUMI_trace_ignore_count; (void)call; --LUMI_trace_ignore_count;

#define CHECK_REF(line, ref, refman) \
  if (ref == NULL) RAISE(line, empty_object) \
  if ((refman)->value == NULL) RAISE(line, outdated_weak_reference)

int LUMI_main(int argc, char* argv[]);
int LUMI_test_main(int argc, char* argv[]);

#define MAIN_PROXY(func) int main(int argc, char* argv[]) { \
  return func(argc, argv); \
}

#define MAIN_FUNC MAIN_PROXY(LUMI_main)
#define TEST_MAIN_FUNC MAIN_PROXY(LUMI_test_main)
#define USER_MAIN_HEADER Returncode LUMI_user_main(void)

#define ARRAY_DEL(Type, array) if (array != NULL) { \
  int LUMI_n = 0; \
  for (; LUMI_n < array->length; ++LUMI_n) \
    Type##_Del(((Type*)(array->values))+LUMI_n); \
}

#define SELF_REF_DEL(Type, field) \
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

#define DYN_SELF_REF_DEL(Type, bases, field) \
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

#define INIT_REFMAN(line, name, is_new) \
  name##_Refman = LUMI_new_ref((void**)&name, is_new); \
  if (name##_Refman == NULL) RAISE(line, managed_object_memory)

#define INIT_VAR(line, name) \
  name = &name##_Var; \
  INIT_REFMAN(line, name, false)

#define INIT_NEW(line, name, alloc) \
  name = alloc; \
  if (name == NULL) RAISE(line, object_memory) \
  INIT_REFMAN(line, name, true)

#define INIT_STRING_CONST(line, name, text) \
  INIT_VAR(line, name) \
  name##_Var.max_length = sizeof(text); \
  name##_Var.length = sizeof(text) - 1; \
  name##_Var.values = text;

void* LUMI_alloc(size_t size);
Ref_Manager* LUMI_new_ref(void** value, Bool is_new);
void LUMI_inc_ref(Ref_Manager* ref);
void LUMI_dec_ref(Ref_Manager* ref);
void LUMI_var_dec_ref(Ref_Manager* ref);
void LUMI_owner_dec_ref(Ref_Manager* ref);

String* LUMI_new_string(int length);
Array* LUMI_new_array(int length, int value_size);
Array* LUMI_new_string_array(int array_length, int string_length);
void LUMI_set_var_string_array(
  int array_length, int string_length, Array* array, char* chars);
Bool LUMI_run_test(char* test_name, Func test_func);
Bool LUMI_test_coverage(File_Coverage* file_coverage, int files_number);

void String_Del(String*);
extern Generic_Type_Dynamic String_dynamic;
Returncode String_clear(String*, Ref_Manager*);
Returncode String_length(String*, Ref_Manager*, Int* length);
Returncode String_equal(
  String*, Ref_Manager*, String* other, Ref_Manager*, Bool* equal);
Returncode String_get(String*, Ref_Manager*, Int index, Char* ch);
Returncode String_append(String*, Ref_Manager*, Char ch);
Returncode String_new(String*, Ref_Manager*, String* source, Ref_Manager*);
Returncode String_concat(String*, Ref_Manager*, String* ext, Ref_Manager*);
Returncode String_concat_int(String*, Ref_Manager*, Int num);
Returncode String_find(
  String*, Ref_Manager*, String* pattern, Ref_Manager*, Int* index);
Returncode String_has(String*, Ref_Manager*, Char ch, Bool* found);

Returncode Int_str(Int value, String* str, Ref_Manager*);

Returncode file_open_read(
  String* name, Ref_Manager*, File** file, Ref_Manager**);
Returncode file_open_write(
  String* name, Ref_Manager*, File** file, Ref_Manager**);
Returncode file_close(File* file, Ref_Manager* file_Refman);
void File_Del(File*);
extern Generic_Type_Dynamic File_dynamic;
Returncode File_getc(File*, Ref_Manager*, Char* ch, Bool* is_eof);
Returncode File_putc(File*, Ref_Manager*, Char ch);
Returncode File_write(File*, Ref_Manager*, String* line, Ref_Manager*);

typedef struct {
  Array* argv;
  Ref_Manager* argv_Refman;
  File* stdout_Cname;
  Ref_Manager* stdout_Cname_Refman;
  File* stdin_Cname;
  Ref_Manager* stdin_Cname_Refman;
  File* stderr_Cname;
  Ref_Manager* stderr_Cname_Refman;
} Sys;
extern Sys* sys;
extern Ref_Manager* sys_Refman;
void Sys_Del(Sys*);
extern Generic_Type_Dynamic Sys_dynamic;
Returncode Sys_print(Sys*, Ref_Manager*, String* text, Ref_Manager*);
Returncode Sys_println(Sys*, Ref_Manager*, String* text, Ref_Manager*);
Returncode Sys_getchar(Sys*, Ref_Manager*, char* ch, Bool* is_eof);
Returncode Sys_getline(Sys*, Ref_Manager*, String* line, Ref_Manager*);
Returncode Sys_exit(Sys*, Ref_Manager*, Int status);
Returncode Sys_system(
  Sys*, Ref_Manager*, String* command, Ref_Manager*, Int* status);
Returncode Sys_getenv(
  Sys*, Ref_Manager*,
  String* name, Ref_Manager*,
  String* value, Ref_Manager*,
  Bool* exists);

void Long_Del(Long*);
Returncode Long_new(Long*, Ref_Manager*);
Returncode Long_copy(Long*, Ref_Manager*, Long**, Ref_Manager**);
Returncode Long_sign(Long*, Ref_Manager*, int*);
Returncode Long_set(Long*, Ref_Manager*, int);
Returncode Long_int(Long*, Ref_Manager*, int*);
Returncode Long_add(Long*, Ref_Manager*, int);
Returncode Long_mul(Long*, Ref_Manager*, int);
Returncode Long_negate(Long*, Ref_Manager*);
Returncode Long_parse(Long*, Ref_Manager*, String*, Ref_Manager*);
Returncode Long_hex(Long*, Ref_Manager*, String*, Ref_Manager*);
Returncode long_combine(
  Long*, Ref_Manager*, Long*, Ref_Manager*, Long**, Ref_Manager**, Bool add);
#define long_add(a, a_Refman, b, b_Refman, res, res_Refman) \
  long_combine(a, a_Refman, b, b_Refman, res, res_Refman, true)
#define long_sub(a, a_Refman, b, b_Refman, res, res_Refman) \
  long_combine(a, a_Refman, b, b_Refman, res, res_Refman, false)
Returncode long_mul(
  Long*, Ref_Manager*, Long*, Ref_Manager*, Long**, Ref_Manager**);
Returncode long_div(
  Long*, Ref_Manager*, Long*, Ref_Manager*, Long**, Ref_Manager**);
Returncode long_mod(
  Long*, Ref_Manager*, Long*, Ref_Manager*, Long**, Ref_Manager**);
Returncode long_equal(Long*, Ref_Manager*, Long*, Ref_Manager*, Bool*);
Returncode long_larger(Long*, Ref_Manager*, Long*, Ref_Manager*, Bool*);

extern int lumi_debug_value;


#endif  /*LUMI_TL4_LUMI_4_H_INCLUDED_*/
