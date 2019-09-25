#define EXTERNAL_CONST 12

typedef struct Native {
  int x;
  int y;
} *Native;

extern int external_int;

int external(
    int i, char* s, int s_max_length, int* s_length, int* io, Native* n);

void external2(Native n, int* b);
