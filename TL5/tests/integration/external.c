#include "external.h"

int external_int = 6;

void* save_s;

int external(
    int i, char* s, int s_max_length, int* s_length, int* io, Native* n) {
  *io = i;
  save_s = s;
  *n = save_s;
  s[0] = 'a';
  return 1;
}

void external2(Native n, int* b) {
  *b = n == save_s;
}
