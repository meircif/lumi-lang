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
  Array** argv;
} Sys;


extern char* MR_raise_format;
extern char* MR_assert_format;
extern char* MR_traceline_format;
extern FILE* MR_trace_stream;
void MR_trace_print(
  char const* format,
  char const* filename,
  int line,
  char const* funcname);

#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup

#define START_TRACE(line, value, format) { \
  MR_trace_print(format, MR_FILE_NAME, line, MR_FUNC_NAME); \
  RETURN_ERROR(value); }

#define RAISE(line) START_TRACE(line, ERR, MR_raise_format)

#define CHECK(line, err) { Returncode _err = err; if (_err != OK) { \
  MR_trace_print(MR_traceline_format, MR_FILE_NAME, line, MR_FUNC_NAME); \
  RETURN_ERROR(_err); } }

#define TEST_FAIL(line) START_TRACE(line, FAIL, MR_assert_format)

#define TEST_ASSERT(line, condition) if (!(condition)) TEST_FAIL(line)

#define RUN_TEST(test_func) MR_success &= MR_run_test(#test_func, test_func)

int MR_main(int argc, char* argv[]);
int MR_test_main(int argc, char* argv[]);

#define MAIN_PROXY(func) int main(int argc, char* argv[]) { \
  return func(argc, argv); \
}

#define MAIN_FUNC MAIN_PROXY(MR_main)
#define TEST_MAIN_FUNC MAIN_PROXY(MR_test_main)
#define USER_MAIN_HEADER Returncode MR_user_main()

typedef struct {
  void* value;
  int count;
} RefManager;

void* MR_new_ref(void);
void MR_inc_ref(void* ref);
void MR_dec_ref(void* ref);
void MR_clean_owner(void* ref);

String* MR_new_string(int length);
Array* MR_new_array(int length, int value_size);
Array* MR_new_string_array(int array_length, int string_length);
void MR_set_var_string_array(
  int array_length, int string_length, Array** array, char* chars);
Bool MR_run_test(char* test_name, Func test_func);

Returncode String_clear(String**);
Returncode String_length(String**, Int* length);
Returncode String_equal(String**, String** other, Bool* equal);
Returncode String_get(String**, Int index, Char* ch);
Returncode String_append(String**, Char ch);
Returncode String_new(String**, String** source);
Returncode String_concat(String**, String** ext);
Returncode String_concat_int(String**, Int num);
Returncode String_find(String**, String** pattern, Int* index);
Returncode String_has(String**, Char ch, Bool* found);

Returncode Int_str(Int value, String** str);

Returncode file_open_read(String** name, File*** file);
Returncode file_open_write(String** name, File*** file);
Returncode File_close(File**);
Returncode File_getc(File**, Char* ch);
Returncode File_putc(File**, Char ch);
Returncode File_write(File**, String** line);

extern Sys** sys;
Returncode Sys_print(Sys**, String** text);
Returncode Sys_println(Sys**, String** text);
Returncode Sys_exit(Sys**, Int status);
Returncode Sys_system(Sys**, String** command, Int* status);
Returncode Sys_getenv(Sys**, String** name, String** value, Bool* exists);


#endif  /*MR_MR4_MR_4_H_INCLUDED_*/
