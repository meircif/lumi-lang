#include "mr.4.h"


/* types declaration */

typedef struct TestStruct TestStruct;

typedef struct BaseType BaseType;

typedef struct BaseType_Dynamic BaseType_Dynamic;

typedef struct MiddleType MiddleType;

typedef struct MiddleType_Dynamic MiddleType_Dynamic;

typedef struct TopType TopType;

typedef struct TopType_Dynamic TopType_Dynamic;


/* types struct */

struct TestStruct {
  Int num;
  String* text;
};

struct BaseType {
  MiddleType* base_mid_ref;
  TopType* base_top_ref;
};

struct BaseType_Dynamic {
  Returncode (*meth0)(BaseType* self);
  Returncode (*meth1)(BaseType* self, Int n, String* s);
  Returncode (*meth2)(BaseType* self);
  Returncode (*meth3)(BaseType* self, Int n, String* s);
};

struct MiddleType {
  BaseType _base;
  BaseType* mid_base_ref;
  TopType* mid_top_ref;
};

struct MiddleType_Dynamic {
  BaseType_Dynamic _base;
  Returncode (*meth4)(MiddleType* self);
  Returncode (*meth5)(MiddleType* self, Int n, String* s);
};

struct TopType {
  MiddleType _base;
  BaseType* top_base_ref;
  MiddleType* top_mid_ref;
};

struct TopType_Dynamic {
  MiddleType_Dynamic _base;
  Returncode (*meth6)(TopType* self);
};


/* types methods declaration */

Returncode TestStruct_set(TestStruct* self, Int x, String* s);

Returncode TestStruct_get(TestStruct* self, Int* x, String** s);

Returncode BaseType_meth0(BaseType* self);

Returncode BaseType_meth1(BaseType* self, Int n, String* s);

Returncode BaseType_meth2(BaseType* self);

Returncode BaseType_meth3(BaseType* self, Int n, String* s);

Returncode MiddleType_meth1(MiddleType* self, Int n, String* s);

Returncode MiddleType_meth2(MiddleType* self);

Returncode MiddleType_meth4(MiddleType* self);

Returncode MiddleType_meth5(MiddleType* self, Int n, String* s);

Returncode TopType_meth2(TopType* self);

Returncode TopType_meth3(TopType* self, Int n, String* s);

Returncode TopType_meth5(TopType* self, Int n, String* s);

Returncode TopType_meth6(TopType* self);


/* types global variables */

BaseType_Dynamic BaseType_dynamic = {BaseType_meth0, BaseType_meth1, BaseType_meth2, BaseType_meth3};

MiddleType_Dynamic MiddleType_dynamic = {{BaseType_meth0, (Func)MiddleType_meth1, (Func)MiddleType_meth2, BaseType_meth3}, MiddleType_meth4, MiddleType_meth5};

TopType_Dynamic TopType_dynamic = {{{BaseType_meth0, (Func)MiddleType_meth1, (Func)TopType_meth2, (Func)TopType_meth3}, MiddleType_meth4, (Func)TopType_meth5}, TopType_meth6};


/* global variables */

Int global_int;

Int CONSTANT_INT;

String* global_string;

String* CONSTANT_STRING;


/* global functions declaration */

Returncode test_simple_function(void);

Returncode test_complex_function(Int num, String* text, Int* out_num, String** out_text);


/* types methods body */

Returncode TestStruct_set(TestStruct* self, Int x, String* s) {
  self.num = x;
  self.text = s;
}

Returncode TestStruct_get(TestStruct* self, Int* x, String** s) {
  x = self.num;
  s = self.text;
}

Returncode BaseType_meth0(BaseType* self) {
  sys.print("BaseType.meth0");
}

Returncode BaseType_meth1(BaseType* self, Int n, String* s) {
  sys.print("BaseType.meth1");
}

Returncode BaseType_meth2(BaseType* self) {
  sys.print("BaseType.meth2");
}

Returncode BaseType_meth3(BaseType* self, Int n, String* s) {
  sys.print("BaseType.meth3");
}

Returncode MiddleType_meth1(MiddleType* self, Int n, String* s) {
  sys.print("MiddleType.meth1");
}

Returncode MiddleType_meth2(MiddleType* self) {
  sys.print("MiddleType.meth2");
}

Returncode MiddleType_meth4(MiddleType* self) {
  sys.print("MiddleType.meth4");
}

Returncode MiddleType_meth5(MiddleType* self, Int n, String* s) {
  sys.print("MiddleType.meth5");
}

Returncode TopType_meth2(TopType* self) {
  sys.print("TopType.meth2");
}

Returncode TopType_meth3(TopType* self, Int n, String* s) {
  sys.print("TopType.meth3");
}

Returncode TopType_meth5(TopType* self, Int n, String* s) {
  sys.print("TopType.meth5");
}

Returncode TopType_meth6(TopType* self) {
  sys.print("TopType.meth6");
}


/* global functions body */

Returncode test_simple_function(void) {
  sys.print("I am test func");
}

Returncode test_complex_function(Int num, String* text, Int* out_num, String** out_text) {
  out_num = num;
  out_text = text;
}


/* main function */

USER_MAIN_HEADER {
  test_simple_function();
}
MAIN_FUNC
