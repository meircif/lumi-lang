#ifndef __MR_C_API__
#define __MR_C_API__

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

typedef void Sys;

typedef struct {
  int size;
  Func* dtl;
} Type;

extern char* _mr_raise_format;
extern char* _mr_assert_format;
extern char* _mr_traceline_format;
extern FILE* _trace_stream;

#define START_TRACE(line, value, format) { \
  fprintf(_trace_stream, format, MR_FILE_NAME, line, MR_FUNC_NAME); \
  return value; }

#define RAISE(line) START_TRACE(line, ERR, _mr_raise_format)

#define CHECK(line, err) { Returncode _err = err; if (_err != OK) { \
  fprintf(_trace_stream, _mr_traceline_format, MR_FILE_NAME, line, MR_FUNC_NAME); \
  return _err; } }

#define TEST_ASSERT(line, condition) if (!(condition)) { \
  START_TRACE(line, FAIL, _mr_assert_format) }

#define RUN_TEST(test_func) success &= _run_test(#test_func, test_func)

int _mr_main(int argc, char* argv[]);
int _mr_test_main(int argc, char* argv[]);

#define MAIN_PROXY(func) int main(int argc, char* argv[]) { \
  return func(argc, argv); \
}

#define MAIN_FUNC MAIN_PROXY(_mr_main)
#define MAIN_TEST_FUNC MAIN_PROXY(_mr_test_main)

#define sys NULL

String* _new_string(int length);
Array* _new_array(int length, int value_size);
void _set_var_string_array(
  int array_length,
  int string_length,
  Array* array,
  char* chars);
void _set_new_string_array(int array_length, int string_length, Array* array);
Bool _run_test(char* test_name, Func test_func);

Returncode String_clear(String* this);
Returncode String_length(String* this, Int* length);
Returncode String_equal(String* this, String* other, Bool* equal);
Returncode String_get(String* this, Int index, Char* ch);
Returncode String_append(String* this, Char ch);
Returncode String_copy(String* this, String* source);
Returncode String_concat(String* this, String* ext);
Returncode String_concat_int(String* this, Int num);
Returncode String_find(String* this, String* pattern, Int* index);
Returncode String_has(String* this, Char ch, Bool* found);
Returncode String_replace(String* this, Char old_ch, Char new_ch);

Returncode Int_str(Int value, String* str);

Returncode file_open_read(String* name, File** file);
Returncode file_open_write(String* name, File** file);
Returncode File_close(File* this);
Returncode File_getc(File* this, Char* ch);
Returncode File_putc(File* this, Char ch);
Returncode File_write(File* this, String* line);

Returncode Sys_print(void*, String* text);
Returncode Sys_exit(void*, Int status);
Returncode Sys_system(void*, String* command, Int* status);
Returncode Sys_getenv(void*, String* name, String* value, Bool* exists);


#define MR_TYPEDEFS 0
#define MR_TYPES(depth) 1 + depth
#define MR_DECLARATIONS 2 + DEPTH
#define MR_FUNCTIONS 3 + DEPTH
#define MR_END 4 + DEPTH

#define MR_STAGE MR_TYPEDEFS


#endif  /*__MR_C_API__*/


#if defined(MR_MAINFILE) && MR_STAGE < MR_END

#include MR_MAINFILE

#if MR_STAGE == MR_TYPEDEFS
#undef MR_STAGE
#define MR_STAGE MR_TYPES(0)
#elif MR_STAGE == MR_TYPES(0)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(1)
#elif MR_STAGE == MR_TYPES(DEPTH)
#undef MR_STAGE
#define MR_STAGE MR_DECLARATIONS
#elif MR_STAGE == MR_DECLARATIONS
#undef MR_STAGE
#define MR_STAGE MR_FUNCTIONS
#elif MR_STAGE == MR_FUNCTIONS
#undef MR_STAGE
#define MR_STAGE MR_END
#endif

#include __FILE__

#endif
