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
  char* chars;
} String;

typedef enum {
  false = 0,
  true = 1
} Bool;

typedef enum {
  OK = EXIT_SUCCESS,
  ERR = EXIT_FAILURE
} Returncode;

typedef struct {
  int length;
  void* values;
} Array;

typedef Returncode (*Func)();

typedef FILE File;

typedef struct {} Sys;

typedef struct {
  int size;
  Func* dtl;
} Type;

#define RAISE(line) { \
  fprintf(stderr, "Error raised in %s:%d %s()\n",\
    MR_FILE_NAME, line, MR_FUNC_NAME); \
  return ERR; }

#define CHECK(line, err) { Returncode _err = err; if (_err != OK) { \
  fprintf(stderr, "  called from %s:%d %s()\n",\
    MR_FILE_NAME, line, MR_FUNC_NAME); \
  return _err; } }

#define MAIN_FUNC int main(int argc, char* argv[]) { \
  String* args_strings = malloc(argc * sizeof(String)); \
  if (args_strings == NULL) { \
    fprintf(stderr, "insufficient memory\n"); \
    return ERR; \
  } \
  Array* args_array = &(Array){argc, args_strings}; \
  int arg; \
  for (arg = 0; arg < argc; ++arg) { \
    args_strings[arg].chars = argv[arg]; \
    args_strings[arg].max_length = strnlen(args_strings[arg].chars, 1024); \
    args_strings[arg].length = args_strings[arg].max_length; \
  } \
  Returncode err =  func(args_array); \
  if (err != OK) {\
    fprintf(stderr, "  called from executable start"); \
  } \
  return err; \
}

String* new_string(int length);
Array* new_array(int length, int value_size);

Returncode String_clear(String* this);
Returncode String_length(String* this, Int* length);
Returncode String_equal(String* this, String* other, Bool* equal);
Returncode String_get(String* this, Int index, Char* ch);
Returncode String_append(String* this, Char ch);
Returncode String_copy(String* this, String* source);
Returncode String_concat(String* this, String* ext);
Returncode String_find(String* this, String* pattern, Int* index);
Returncode String_replace(String* this, Char old_ch, Char new_ch);

Returncode Int_str(Int value, String* str);

Returncode file_open_read(String* name, File** file);
Returncode file_open_write(String* name, File** file);
Returncode File_close(File* this);
Returncode File_getc(File* this, Char* ch);
Returncode File_putc(File* this, Char ch);
Returncode File_write(File* this, String* line);

Returncode Sys_print(Sys*, String* text);
Returncode Sys_exit(Sys*, Int status);
Returncode Sys_system(Sys*, String* command, Int* status);
Returncode Sys_getenv(Sys*, String* name, String* value, Bool* exists);

#endif  /*__MR_C_API__*/
