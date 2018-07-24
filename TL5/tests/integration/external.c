#include "lumi.5.h"

Int external_int = 6;

void* save_s;

Returncode external(Int i, String* s, Int* io, void** n) {
  *io = i;
  save_s = s;
  *n = save_s;
  s->values[0] = 'a';
  return ERR;
}

Returncode external2(void* n, Bool* b) {
  *b = n == save_s;
  return OK;
}
