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

typedef struct {
  Array* argv;
} Sys;

#define MANAGER_TYPEDEF(type) \
typedef struct { int ref_count; type* ref; } type##_Manager;

#define STATIC_REF_TYPEDEF(type) \
MANAGER_TYPEDEF(type) \
typedef struct { type##_Manager* manager; } type##_ManagerRef; \
typedef struct { type##_Manager* manager; type* ref; } type##_WeakRef;

#define DYNAMIC_REF_TYPEDEF(type) \
MANAGER_TYPEDEF(type) \
typedef struct { type##_Manager* manager; type##_Dtl* dtl; } \
type##_ManagerRef; \
typedef struct { type##_Manager* manager; type* ref; type##_Dtl* dtl; } \
type##_WeakRef;


extern char* MR_raise_format;
extern char* MR_assert_format;
extern char* MR_traceline_format;
extern FILE* MR_trace_stream;
void MR_trace_print(
  char const* format,
  char const* filename,
  int line,
  char const* funcname);

#define RETURN_ERROR(value) return value

#define START_TRACE(line, value, format) { \
  MR_trace_print(format, MR_FILE_NAME, line, MR_FUNC_NAME); \
  RETURN_ERROR(value); }

#define RAISE(line) START_TRACE(line, ERR, MR_raise_format)

#define CHECK(line, err) { Returncode _err = err; if (_err != OK) { \
  MR_trace_print(MR_traceline_format, MR_FILE_NAME, line, MR_FUNC_NAME); \
  RETURN_ERROR(_err); } }

#define TEST_FAIL(line) START_TRACE(line, FAIL, MR_assert_format)

#define TEST_ASSERT(line, condition) if (!(condition)) TEST_FAIL(line)

#define RUN_TEST(test_func) success &= MR_run_test(#test_func, test_func)

int MR_main(int argc, char* argv[]);
int MR_test_main(int argc, char* argv[]);

#define MAIN_PROXY(func) int main(int argc, char* argv[]) { \
  return func(argc, argv); \
}

#define MAIN_FUNC MAIN_PROXY(MR_main)
#define TEST_MAIN_FUNC MAIN_PROXY(MR_test_main)
#define USER_MAIN_HEADER Returncode MR_user_main()

String* MR_new_string(int length);
Array* MR_new_array(int length, int value_size);
Array* MR_new_string_array(int array_length, int string_length);
void MR_set_var_string_array(
  int array_length, int string_length, Array* array, char* chars);
Bool MR_run_test(char* test_name, Func test_func);

Returncode String_clear(String* this);
Returncode String_length(String* this, Int* length);
Returncode String_equal(String* this, String* other, Bool* equal);
Returncode String_get(String* this, Int index, Char* ch);
Returncode String_append(String* this, Char ch);
Returncode String_new(String* this, String* source);
Returncode String_concat(String* this, String* ext);
Returncode String_concat_int(String* this, Int num);
Returncode String_find(String* this, String* pattern, Int* index);
Returncode String_has(String* this, Char ch, Bool* found);

Returncode Int_str(Int value, String* str);

Returncode file_open_read(String* name, File** file);
Returncode file_open_write(String* name, File** file);
Returncode File_close(File* this);
Returncode File_getc(File* this, Char* ch);
Returncode File_putc(File* this, Char ch);
Returncode File_write(File* this, String* line);

extern Sys* sys;
Returncode Sys_print(Sys*, String* text);
Returncode Sys_println(Sys*, String* text);
Returncode Sys_exit(Sys*, Int status);
Returncode Sys_system(Sys*, String* command, Int* status);
Returncode Sys_getenv(Sys*, String* name, String* value, Bool* exists);


#endif  /*MR_MR4_MR_4_H_INCLUDED_*/
