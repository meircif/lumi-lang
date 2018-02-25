#ifndef MR_MR4_MR_4_H_INCLUDED_
#define MR_MR4_MR_4_H_INCLUDED_

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

typedef FILE File;

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


extern char* MR_raise_format;
extern char* MR_assert_format;
extern char* MR_traceline_format;
extern int MR_trace_ignore_count;
extern char* MR_expected_error;
extern int MR_expected_error_trace_ignore_count;
void MR_trace_print(
  char const* format,
  char const* filename,
  int line,
  char const* funcname,
  String* message,
  Ref_Manager* message_refman);

#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup

#define START_TRACE(line, value, format, message, message_refman) \
  MR_trace_print( \
      format, MR_FILE_NAME, line, MR_FUNC_NAME, message, message_refman); \
  RETURN_ERROR(value);

#define START_TRACE_STATIC(line, err_value, format, message_length, message) { \
  String MR_msg = { message_length + 1, message_length, message }; \
  Ref_Manager MR_msg_refman = { 1, NULL, NULL }; \
  MR_msg_refman.value = &MR_msg; \
  START_TRACE(line, err_value, format, &MR_msg, &MR_msg_refman) }

#define RAISE(line, message_length, message) \
  START_TRACE_STATIC(line, ERR, MR_raise_format, message_length, message)

#define USER_RAISE(line, message, message_refman) \
  { START_TRACE(line, ERR, MR_raise_format, message, message_refman) }

#define TEST_FAIL(line, message_length, message) \
  START_TRACE_STATIC(line, FAIL, MR_assert_format, message_length, message)

#define TEST_ASSERT(line, condition) if (!(condition)) \
  TEST_FAIL(line, 21, "condition is not true")

#define TEST_FAIL_NULL(line) \
  { START_TRACE(line, FAIL, MR_assert_format, NULL, NULL) }

#define CHECK(line, err) { Returncode _err = err; if (_err != OK) { \
  MR_trace_print( \
      MR_traceline_format, MR_FILE_NAME, line, MR_FUNC_NAME, NULL, NULL); \
  RETURN_ERROR(_err); } }

#define IGNORE_ERRORS(call) \
  ++MR_trace_ignore_count; (void)call; --MR_trace_ignore_count;

#define RUN_TEST(test_func) MR_success &= MR_run_test(#test_func, test_func)

int MR_main(int argc, char* argv[]);
int MR_test_main(int argc, char* argv[]);

#define MAIN_PROXY(func) int main(int argc, char* argv[]) { \
  return func(argc, argv); \
}

#define MAIN_FUNC MAIN_PROXY(MR_main)
#define TEST_MAIN_FUNC MAIN_PROXY(MR_test_main)
#define USER_MAIN_HEADER Returncode MR_user_main(void)

#define ARRAY_DEL(Type, array) \
{int MR_n=0; for(;MR_n<array->length; ++MR_n) \
 Type##_Del(((Type*)(array->values))+MR_n);}

#define SELF_REF_DEL(Type, field) \
while (self->field != NULL) { \
  Type* value = self->field; \
  Ref_Manager* value_Refman = self->field##_Refman; \
  self->field = value->field; \
  self->field##_Refman = value->field##_Refman; \
  value->field = NULL; \
  value->field##_Refman = NULL; \
  Type##_Del(value); \
  MR_owner_dec_ref(value_Refman); \
}

#define DYN_SELF_REF_DEL(Type, bases, field) \
while (self->field != NULL) { \
  Type* value = self->field; \
  Ref_Manager* value_Refman = self->field##_Refman; \
  Type##_Dynamic* value_Dynamic = self->field##_Dynamic; \
  self->field = value->field; \
  self->field##_Refman = value->field##_Refman; \
  value->field = NULL; \
  value->field##_Refman = NULL; \
  value->field##_Dynamic = NULL; \
  value_Dynamic->bases##del(value); \
  MR_owner_dec_ref(value_Refman); \
}

void* MR_alloc(size_t size);
Ref_Manager* MR_new_ref(void* value);
void MR_inc_ref(Ref_Manager* ref);
void MR_dec_ref(Ref_Manager* ref);
void MR_owner_dec_ref(Ref_Manager* ref);

String* MR_new_string(int length);
Array* MR_new_array(int length, int value_size);
Array* MR_new_string_array(int array_length, int string_length);
void MR_set_var_string_array(
  int array_length, int string_length, Array* array, char* chars);
Bool MR_run_test(char* test_name, Func test_func);
Bool MR_test_coverage(File_Coverage* file_coverage, int files_number);

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
void File_Del(File*);
extern Generic_Type_Dynamic File_dynamic;
Returncode File_close(File*, Ref_Manager*);
Returncode File_getc(File*, Ref_Manager*, Char* ch, Bool* is_eof);
Returncode File_putc(File*, Ref_Manager*, Char ch);
Returncode File_write(File*, Ref_Manager*, String* line, Ref_Manager*);

typedef struct {
  Array* argv;
  Ref_Manager* argv_Refman;
} Sys;
extern Sys* sys;
extern Ref_Manager* sys_Refman;
extern Ref_Manager* stdout_Refman;
extern Ref_Manager* stdin_Refman;
extern Ref_Manager* stderr_Refman;
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


#endif  /*MR_MR4_MR_4_H_INCLUDED_*/
