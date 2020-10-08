#include "external.h"

int external_int = 6;

Native external_nvar = {3, 4};

void MY_Some_external(void) {
  external_int = 7;
}

NativeRef external_get_ref(int i, char* s, int* a) {
  s[0] = 'a';
  a[0] = i;
  return &external_nvar;
}

int external_set_ref(NativeRef n) {
  return n->x + n->y;
}

Native external_get_var(void) {
  return external_nvar;
}

int external_set_var(Native n) {
  return n.x + n.y;
}
