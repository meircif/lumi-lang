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

String* global_string;


/* global functions declaration */

Returncode test_simple_function(void);

Returncode test_variable(Int i, String* text, Array* arr);

Returncode test_complex_function(Int num, String* text, Int* out_num, String** out_text);


/* types methods body */

Returncode TestStruct_set(TestStruct* self, Int x, String* s) {
  self->num = x;
  self->text = s;
  return OK;
}

Returncode TestStruct_get(TestStruct* self, Int* x, String** s) {
  (*x) = self->num;
  (*s) = self->text;
  return OK;
}

Returncode BaseType_meth0(BaseType* self) {
  return OK;
}

Returncode BaseType_meth1(BaseType* self, Int n, String* s) {
  return OK;
}

Returncode BaseType_meth2(BaseType* self) {
  return OK;
}

Returncode BaseType_meth3(BaseType* self, Int n, String* s) {
  return OK;
}

Returncode MiddleType_meth1(MiddleType* self, Int n, String* s) {
  return OK;
}

Returncode MiddleType_meth2(MiddleType* self) {
  return OK;
}

Returncode MiddleType_meth4(MiddleType* self) {
  return OK;
}

Returncode MiddleType_meth5(MiddleType* self, Int n, String* s) {
  return OK;
}

Returncode TopType_meth2(TopType* self) {
  return OK;
}

Returncode TopType_meth3(TopType* self, Int n, String* s) {
  return OK;
}

Returncode TopType_meth5(TopType* self, Int n, String* s) {
  return OK;
}

Returncode TopType_meth6(TopType* self) {
  return OK;
}


/* global functions body */

Returncode test_simple_function(void) {
  return OK;
}

Returncode test_variable(Int i, String* text, Array* arr) {
  Int x = 0;
  String* s = NULL;
  Array* a = NULL;
  TestStruct* t = NULL;
  TestStruct tv_Var = {0};
  TestStruct* tv = &tv_Var;
  char sv_Values[12];
  String sv_Var = {12, 0, NULL};
  String* sv = &sv_Var;
  Int ia_Values[12];
  Array ia_Var = {12, NULL};
  Array* ia = &ia_Var;
  TestStruct ta_Values[12];
  Array ta_Var = {12, NULL};
  Array* ta = &ta_Var;
  char sa_Chars[12 * 7];
  String sa_Values[12];
  Array sa_Var = {12, NULL};
  Array* sa = &sa_Var;
  TestStruct* tn = NULL;
  String* sn = NULL;
  Array* ian = NULL;
  Array* tan = NULL;
  Array* san = NULL;
  Int ix = 0;
  String* is = NULL;
  char isv_Values[12];
  String isv_Var = {12, 0, NULL};
  String* isv = &isv_Var;
  String* isn = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  sv_Var.values = sv_Values;
  ia_Var.values = ia_Values;
  ta_Var.values = ta_Values;
  sa_Var.values = sa_Values;
  MR_set_var_string_array(12, 7, sa, sa_Chars);
  tn = calloc(1, sizeof(TestStruct));
  if ((0) < 0 || (0) >= (arr)->length) RAISE(39)
  sn = MR_new_string((((Int*)((arr)->values))[0]));
  if ((0) < 0 || (0) >= (arr)->length) RAISE(40)
  ian = MR_new_array((((Int*)((arr)->values))[0]), sizeof(Int));
  if ((0) < 0 || (0) >= (arr)->length) RAISE(41)
  tan = MR_new_array((((Int*)((arr)->values))[0]), sizeof(TestStruct));
  if ((0) < 0 || (0) >= (arr)->length) RAISE(42)
  if ((1) < 0 || (1) >= (arr)->length) RAISE(42)
  san = MR_new_array((((Int*)((arr)->values))[0]), sizeof(String) + ((((Int*)((arr)->values))[1])));
  MR_set_new_string_array((((Int*)((arr)->values))[0]), (((Int*)((arr)->values))[1]), san);
  if ((0) < 0 || (0) >= (arr)->length) RAISE(43)
  ix = (((Int*)((arr)->values))[0]);
  is = text;
  isv_Var.values = isv_Values;
  aux_String_0->max_length = 12;
  aux_String_0->length = 11;
  aux_String_0->values = "some string";
  CHECK(45, String_copy(isv, aux_String_0) )
  isn = MR_new_string(i);
  CHECK(46, String_copy(isn, text) )
  return OK;
}

Returncode test_complex_function(Int num, String* text, Int* out_num, String** out_text) {
  (*out_num) = num;
  (*out_text) = text;
  return OK;
}


/* main function */

USER_MAIN_HEADER {
  return OK;
}
MAIN_FUNC
