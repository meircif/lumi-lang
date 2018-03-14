#ifndef __LUMI_C_API__
#define __LUMI_C_API__


#define not !
#define or ||
#define and &&
#define minus -

typedef char Char;
typedef int Int;

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

int cstring_length(char* cstring, int max_length);


#endif  /*__LUMI_C_API__*/
