#include "external.h"

int external_int = 6;

struct Native nvar = {3, 4};

void MY_Some_external(void) {
  external_int = 7;
}

Native external1(int i, char* s, int* a) {
  s[0] = 'a';
  a[0] = i;
  return &nvar;
}

int external2(Native n) {
  return n->x + n->y;
}
