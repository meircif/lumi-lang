#ifndef __MR_C_API__
#define __MR_C_API__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define not !
#define or ||
#define and &&

typedef int Int;
typedef char Char;
typedef unsigned char Byte;

typedef struct {
  int max_length;
  int actual_length;
  char* chars;
} String;

typedef enum {
  false = 0,
  true = 1
} Bool;

typedef enum {
  OK = 0,
  ERR
} Returncode;

typedef struct {
  int length;
  void* values;
} Array;

#define RAISE { fprintf(stderr, "Error raised in %s:%d %s()\n", __FILE__, __LINE__, __FUNCTION__); \
  return ERR; }

#define CHECK(err) { Returncode _err = err; if (_err != OK) { \
  fprintf(stderr, "  called from %s:%d %s()\n", __FILE__, __LINE__, __FUNCTION__); \
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
    args_strings[arg].actual_length = args_strings[arg].max_length; \
  } \
  CHECK(func(args_array)) \
  return OK; \
}

String* new_string(int length);
Array* new_array(int length, int value_size);


#endif  /*__MR_C_API__*/
