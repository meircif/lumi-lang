#include "lumi.5.h"

Int external_int = 6;

void* save_s;

Returncode external(
    Int i, char* s, Int s_max_length, Int s_length, Int* io, void** n) {
  *io = i;
  save_s = s;
  *n = save_s;
  s[0] = 'a';
  return ERR;
}

void external2(void* n, Bool* b) {
  *b = n == save_s;
}
