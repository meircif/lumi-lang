#define EXTERNAL_CONST 12

typedef struct Native {
  int x;
  int y;
} Native;

typedef Native* NativeRef;

extern int external_int;

extern Native external_nvar;

void MY_Some_external(void);

NativeRef external_get_ref(int i, char* s, int* a);

int external_set_ref(NativeRef n);

Native external_get_var(void);

int external_set_var(Native);
