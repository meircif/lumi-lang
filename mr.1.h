#ifndef __MR_C_API__
#define __MR_C_API__

#include <stdio.h>
#include <string.h>


#define not !
#define or ||
#define and &&

typedef int Int;
typedef char Char;

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

#define CHECK(err) { Returncode _err = err; if (_err != OK) return _err; }


#endif  /*__MR_C_API__*/
