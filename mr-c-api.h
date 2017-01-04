#ifndef __MR_C_API__
#define __MR_C_API__


typedef struct {
  int max_length;
  int actual_length;
  char* chars;
} String;

typedef enum {
  OK = 0,
  ERR
} Returncode;


#endif  /*__MR_C_API__*/
