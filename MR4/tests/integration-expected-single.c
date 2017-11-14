#include "mr.4.h"


/* types declaration */

typedef struct TestStruct TestStruct;


/* types struct */

struct TestStruct {
  Int num;
  String* text;
  TestStruct* ts;
  Returncode (*fun)(void);
};


/* types methods declaration */

Returncode TestStruct_set(TestStruct* self, Int x, String* s);

Returncode TestStruct_get(TestStruct* self, Int* x, String** s);


/* types global variables */


/* global variables */

Int global_int;

String* global_string;


/* global functions declaration */

Returncode test_simple_function(void);

Returncode test_const_expression(Int* i, Char* c, String** s, TestStruct** t);

Returncode test_member_expression(TestStruct* t, TestStruct** to, Int* i);

Returncode test_slice_expression(String* s, Array* arri, Array* arrs, Array* arrt, Array* arrf, Char* c, Int* i, TestStruct** t, Returncode (**f)(void));

Returncode test_container_expression(Int x, Int y, String* s, Int* i, Bool* b);

Returncode test_variable(Int i, String* text, Array* arr);

Returncode test_complex_function(Int num, String* text, Int* out_num, String** out_text);

Returncode f_test_void(void);

Returncode f_test_params(Int x, String* s, String* o);

Returncode f_test_outs(String** s, Int* x);

Returncode f_test_int2str(Int x, String** s);

Returncode f_test_int(Int x);

Returncode f_test_int2int(Int x, Int* r);

Returncode f_test_many(Int x, Int y, Int* n, Int* m);

Returncode test_call_expression(void);

Returncode test_code_flow(Array* arr, Int* res);

Returncode test_builtins(Int i, Char c, Bool b, String* s, Array* a);


/* types methods body */

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestStruct.set"
Returncode TestStruct_set(TestStruct* self, Int x, String* s) {
  if (self == NULL) RAISE(153)
  self->num = x;
  if (self == NULL) RAISE(154)
  self->text = s;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestStruct.get"
Returncode TestStruct_get(TestStruct* self, Int* x, String** s) {
  if (self == NULL) RAISE(161)
  *x = self->num;
  if (self == NULL) RAISE(162)
  *s = self->text;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME


/* global functions body */

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-simple-function"
Returncode test_simple_function(void) {
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-const-expression"
Returncode test_const_expression(Int* i, Char* c, String** s, TestStruct** t) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  *i = (((((((0 + 9630) + -9630) + 07520) + -07520) + 0xfda940) + -0xfda940) + 0xFDA940) + -0xFDA940;
  *c = (((('a' + '\'') + '\n') + '\x0f') + '\xA9') + '\270';
  aux_String_0->max_length = 12;
  aux_String_0->length = 11;
  aux_String_0->values = "some string";
  *s = aux_String_0;
  *t = NULL;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-member-expression"
Returncode test_member_expression(TestStruct* t, TestStruct** to, Int* i) {
  if (t == NULL) RAISE(39)
  if (t->ts == NULL) RAISE(39)
  if (t->ts->ts == NULL) RAISE(39)
  if (t == NULL) RAISE(39)
  if (t->ts == NULL) RAISE(39)
  if ((*to) == NULL) RAISE(39)
  if (t == NULL) RAISE(39)
  t->num = ((*to)->num + t->ts->num) + t->ts->ts->num;
  if (t == NULL) RAISE(40)
  if ((*to) == NULL) RAISE(40)
  (*to)->num = t->num;
  if (t == NULL) RAISE(41)
  if (t->ts == NULL) RAISE(41)
  if (t->ts->ts == NULL) RAISE(41)
  t->ts->ts->num = 4;
  if (t == NULL) RAISE(42)
  t->fun = f_test_void;
  if (t == NULL) RAISE(43)
  if (t->fun == NULL) RAISE(43)
  CHECK(43, t->fun() )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-slice-expression"
Returncode test_slice_expression(String* s, Array* arri, Array* arrs, Array* arrt, Array* arrf, Char* c, Int* i, TestStruct** t, Returncode (**f)(void)) {
  Array aux_Array_0_Var = {0};
  Array* aux_Array_0 = &aux_Array_0_Var;
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  String aux_String_1_Var = {0};
  String* aux_String_1 = &aux_String_1_Var;
  Array aux_Array_1_Var = {0};
  Array* aux_Array_1 = &aux_Array_1_Var;
  Array aux_Array_2_Var = {0};
  Array* aux_Array_2 = &aux_Array_2_Var;
  Array aux_Array_3_Var = {0};
  Array* aux_Array_3 = &aux_Array_3_Var;
  Array aux_Array_4_Var = {0};
  Array* aux_Array_4 = &aux_Array_4_Var;
  Array aux_Array_5_Var = {0};
  Array* aux_Array_5 = &aux_Array_5_Var;
  Array aux_Array_6_Var = {0};
  Array* aux_Array_6 = &aux_Array_6_Var;
  Array aux_Array_7_Var = {0};
  Array* aux_Array_7 = &aux_Array_7_Var;
  Array aux_Array_8_Var = {0};
  Array* aux_Array_8 = &aux_Array_8_Var;
  aux_Array_0_Var.length = 2;
  aux_Array_0_Var.values = (Byte*)((arrs)->values) + (4);
  if ((4) < 0 || (2) < 0 || (4) + (2) > (arrs)->length) RAISE(53)
  if ((4) < 0 || (4) >= (aux_Array_0)->length) RAISE(53)
  aux_String_0_Var.length = 3;
  aux_String_0_Var.max_length = aux_String_0_Var.length + 1;
  aux_String_0_Var.values = ((((String**)((aux_Array_0)->values))[4]))->values + (1);
  if ((1) < 0 || (3) < 0 || (1) + (3) > ((((String**)((aux_Array_0)->values))[4]))->length) RAISE(53)
  if ((0) < 0 || (0) >= (aux_String_0)->length) RAISE(53)
  if ((3) < 0 || (3) >= (arrs)->length) RAISE(53)
  if ((2) < 0 || (2) >= ((((String**)((arrs)->values))[3]))->length) RAISE(53)
  aux_String_1_Var.length = 7;
  aux_String_1_Var.max_length = aux_String_1_Var.length + 1;
  aux_String_1_Var.values = (s)->values + (4);
  if ((4) < 0 || (7) < 0 || (4) + (7) > (s)->length) RAISE(53)
  if ((2) < 0 || (2) >= (aux_String_1)->length) RAISE(53)
  if ((2) < 0 || (2) >= (s)->length) RAISE(53)
  *c = (((((s)->values)[2]) + (((aux_String_1)->values)[2])) + ((((((String**)((arrs)->values))[3]))->values)[2])) + (((aux_String_0)->values)[0]);
  aux_Array_1_Var.length = 4;
  aux_Array_1_Var.values = (Byte*)((arri)->values) + (2);
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arri)->length) RAISE(55)
  aux_Array_2_Var.length = 2;
  aux_Array_2_Var.values = (Byte*)((aux_Array_1)->values) + (1);
  if ((1) < 0 || (2) < 0 || (1) + (2) > (aux_Array_1)->length) RAISE(55)
  if ((1) < 0 || (1) >= (aux_Array_2)->length) RAISE(55)
  aux_Array_3_Var.length = 4;
  aux_Array_3_Var.values = (Byte*)((arrt)->values) + (2);
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arrt)->length) RAISE(54)
  if ((1) < 0 || (1) >= (aux_Array_3)->length) RAISE(54)
  if ((((TestStruct**)((aux_Array_3)->values))[1]) == NULL) RAISE(54)
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(54)
  if ((((TestStruct**)((arrt)->values))[4]) == NULL) RAISE(54)
  if ((2) < 0 || (2) >= (arri)->length) RAISE(54)
  if ((((*i) + 3) - (((Int*)((arri)->values))[2])) < 0 || (((*i) + 3) - (((Int*)((arri)->values))[2])) >= (arri)->length) RAISE(54)
  *i = (((((Int*)((arri)->values))[((*i) + 3) - (((Int*)((arri)->values))[2])]) + (((TestStruct**)((arrt)->values))[4])->num) + (((TestStruct**)((aux_Array_3)->values))[1])->num) + (((Int*)((aux_Array_2)->values))[1]);
  aux_Array_4_Var.length = 4;
  aux_Array_4_Var.values = (Byte*)((arri)->values) + (2);
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arri)->length) RAISE(56)
  if ((1) < 0 || (1) >= (aux_Array_4)->length) RAISE(56)
  aux_Array_5_Var.length = 5 * ((*i) - 1);
  aux_Array_5_Var.values = (Byte*)((arri)->values) + ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1]));
  if (((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1])) < 0 || (5 * ((*i) - 1)) < 0 || ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1])) + (5 * ((*i) - 1)) > (arri)->length) RAISE(56)
  arri = aux_Array_5;
  if ((4) < 0 || (4) >= (arrs)->length) RAISE(57)
  s = ((String**)((arrs)->values))[4];
  aux_Array_6_Var.length = 7;
  aux_Array_6_Var.values = (Byte*)((arrs)->values) + (2);
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrs)->length) RAISE(58)
  arrs = aux_Array_6;
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(59)
  *t = ((TestStruct**)((arrt)->values))[4];
  aux_Array_7_Var.length = 7;
  aux_Array_7_Var.values = (Byte*)((arrt)->values) + (2);
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrt)->length) RAISE(60)
  arrt = aux_Array_7;
  *f = NULL;
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(62)
  *f = ((Returncode (**)(void))((arrf)->values))[4];
  if (*f == NULL) RAISE(63)
  CHECK(63, (*f)() )
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(64)
  if (((Returncode (**)(void))((arrf)->values))[4] == NULL) RAISE(64)
  CHECK(64, (((Returncode (**)(void))((arrf)->values))[4])() )
  aux_Array_8_Var.length = 7;
  aux_Array_8_Var.values = (Byte*)((arrf)->values) + (2);
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrf)->length) RAISE(65)
  arrf = aux_Array_8;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-container-expression"
Returncode test_container_expression(Int x, Int y, String* s, Int* i, Bool* b) {
  *i = (- x) + (- (- (- y)));
  *b = (! (((! ((((x * 3) - 5) > (6 * y)) && ((6 * y) == 234))) && (! ((5 - x) < y))) || (! ((x == (-2 - (-4 * y))) && (((-6 > y) && (y >= 12)) && (12 == x)))))) && ((((- (2 + x)) > y) || (s != NULL)) || (! (s != NULL)));
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-variable"
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
  Returncode (*f)(Int xi, String* si, Int* xo, String** so) = NULL;
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
  Returncode (*fa_Values[12])(void);
  Array fa_Var = {12, NULL};
  Array* fa = &fa_Var;
  TestStruct* tn = NULL;
  String* sn = NULL;
  Array* ian = NULL;
  Array* tan = NULL;
  Array* san = NULL;
  Array* sfn = NULL;
  Int ix = 0;
  String* is = NULL;
  char isv_Values[12];
  String isv_Var = {12, 0, NULL};
  String* isv = &isv_Var;
  String* isn = NULL;
  Returncode (*fi)(Int x, String** s) = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  sv_Var.values = sv_Values;
  ia_Var.values = ia_Values;
  ta_Var.values = ta_Values;
  sa_Var.values = sa_Values;
  MR_set_var_string_array(12, 7, sa, sa_Chars);
  fa_Var.values = fa_Values;
  tn = calloc(1, sizeof(TestStruct));
  if ((0) < 0 || (0) >= (arr)->length) RAISE(89)
  sn = MR_new_string(((Int*)((arr)->values))[0]);
  if ((0) < 0 || (0) >= (arr)->length) RAISE(90)
  ian = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if ((0) < 0 || (0) >= (arr)->length) RAISE(91)
  tan = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestStruct));
  if ((0) < 0 || (0) >= (arr)->length) RAISE(92)
  if ((1) < 0 || (1) >= (arr)->length) RAISE(92)
  san = MR_new_array(((Int*)((arr)->values))[0], sizeof(String) + (((Int*)((arr)->values))[1]));
  MR_set_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1], san);
  if ((0) < 0 || (0) >= (arr)->length) RAISE(93)
  sfn = MR_new_array(((Int*)((arr)->values))[0], sizeof(Func));
  if ((0) < 0 || (0) >= (arr)->length) RAISE(94)
  ix = ((Int*)((arr)->values))[0];
  is = text;
  isv_Var.values = isv_Values;
  aux_String_0->max_length = 12;
  aux_String_0->length = 11;
  aux_String_0->values = "some string";
  CHECK(96, String_copy(isv, aux_String_0) )
  isn = MR_new_string(i);
  CHECK(97, String_copy(isn, text) )
  fi = f_test_int2str;
  TEST_ASSERT(99, x == 0)
  TEST_ASSERT(100, s != NULL)
  TEST_ASSERT(101, a != NULL)
  TEST_ASSERT(102, t != NULL)
  TEST_ASSERT(103, f != NULL)
  TEST_ASSERT(104, tv != NULL)
  TEST_ASSERT(105, sv != NULL)
  TEST_ASSERT(106, ia != NULL)
  TEST_ASSERT(107, ta != NULL)
  TEST_ASSERT(108, sa != NULL)
  TEST_ASSERT(109, fa != NULL)
  TEST_ASSERT(110, tn != NULL)
  TEST_ASSERT(111, sn != NULL)
  TEST_ASSERT(112, ian != NULL)
  TEST_ASSERT(113, tan != NULL)
  TEST_ASSERT(114, san != NULL)
  TEST_ASSERT(115, sfn != NULL)
  TEST_ASSERT(116, ix == 0)
  TEST_ASSERT(117, is != NULL)
  TEST_ASSERT(118, fi != NULL)
  TEST_ASSERT(119, isv != NULL)
  TEST_ASSERT(120, isn != NULL)
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-complex-function"
Returncode test_complex_function(Int num, String* text, Int* out_num, String** out_text) {
  *out_num = num;
  *out_text = text;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-void"
Returncode f_test_void(void) {
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-params"
Returncode f_test_params(Int x, String* s, String* o) {
  RAISE(168)
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-outs"
Returncode f_test_outs(String** s, Int* x) {
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-int2str"
Returncode f_test_int2str(Int x, String** s) {
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-int"
Returncode f_test_int(Int x) {
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-int2int"
Returncode f_test_int2int(Int x, Int* r) {
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-many"
Returncode f_test_many(Int x, Int y, Int* n, Int* m) {
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-call-expression"
Returncode test_call_expression(void) {
  String* s = NULL;
  Int x = 0;
  Int tmp = 0;
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  Int aux_Int_0 = 0;
  Int aux_Int_1 = 0;
  String* aux_String_1 = NULL;
  CHECK(183, f_test_void() )
  aux_String_0->max_length = 5;
  aux_String_0->length = 4;
  aux_String_0->values = "text";
  CHECK(184, f_test_params(3, aux_String_0, NULL) )
  CHECK(185, f_test_outs(&(s), &(x)) )
  CHECK(186, f_test_int2str(4, &(s)) )
  CHECK(187, f_test_int(5) )
  CHECK(188, f_test_int2int(6, &(x)) )
  CHECK(189, f_test_many(7, 8, &(x), &(x)) )
  CHECK(195, f_test_int2int(9, &(tmp)) )
  CHECK(195, f_test_int(tmp) )
  CHECK(196, f_test_many(11, 12, &(x), &(aux_Int_0)) )
  CHECK(196, f_test_int2int(10, &(aux_Int_1)) )
  x = aux_Int_1 + aux_Int_0;
  CHECK(197, f_test_int2str(13, &(aux_String_1)) )
  s = aux_String_1;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-code-flow"
Returncode test_code_flow(Array* arr, Int* res) {
  if ((4) < 0 || (4) >= (arr)->length) RAISE(201)
  if ((((Int*)((arr)->values))[4]) > 6) {
    *res = 6;
  }
  else {
    if (arr != NULL) {
      *res = 6;
    }
    else {
      if ((4) < 0 || (4) >= (arr)->length) RAISE(205)
      if ((4) < 0 || (4) >= (arr)->length) RAISE(205)
      if ((((Int*)((arr)->values))[4]) != (((Int*)((arr)->values))[4])) {
        *res = 6;
      }
      else {
        if ((0) < 0 || (0) >= (arr)->length) RAISE(207)
        if (0 == (((Int*)((arr)->values))[0])) {
          *res = 6;
        }
        else {
          *res = 0;
        }
      }
    }
  }
  while (true) {
    Int x = 0;
    Int y = 0;
    if ((6) < 0 || (6) >= (arr)->length) RAISE(212)
    ((Int*)((arr)->values))[6] = 6;
    if ((2) < 0 || (2) >= (arr)->length) RAISE(213)
    x = ((Int*)((arr)->values))[2];
    if (!(x > 3)) break;
    y = x - 1;
    while (true) {
      Int z = 0;
      if ((8) < 0 || (8) >= (arr)->length) RAISE(217)
      if ((4) < 0 || (4) >= (arr)->length) RAISE(217)
      ((Int*)((arr)->values))[4] = ((Int*)((arr)->values))[8];
      if ((4) < 0 || (4) >= (arr)->length) RAISE(218)
      if (y > (((Int*)((arr)->values))[4])) {
        continue;
      }
      z = 0;
      if ((4) < 0 || (4) >= (arr)->length) RAISE(221)
      if (z <= (((Int*)((arr)->values))[4])) {
        if (!(z > 0)) break;
      }
    }
  }
  if ((2) < 0 || (2) >= (arr)->length) RAISE(223)
  if ((2) < 0 || (2) >= (arr)->length) RAISE(223)
  {int n; for(n=((Int*)((arr)->values))[2]; n<2 - (3 * (((Int*)((arr)->values))[2])); ++n) {
    Int x = 0;
    if ((2) < 0 || (2) >= (arr)->length) RAISE(224)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(224)
    ((Int*)((arr)->values))[0] = ((Int*)((arr)->values))[2];
    if ((0) < 0 || (0) >= (arr)->length) RAISE(225)
    x = ((Int*)((arr)->values))[0];
    if (x > 4) {
      if ((1) < 0 || (1) >= (arr)->length) RAISE(227)
      ((Int*)((arr)->values))[1] = x;
    }
  }
  }
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-builtins"
Returncode test_builtins(Int i, Char c, Bool b, String* s, Array* a) {
  File* f = NULL;
  CHECK(232, Int_str(i, s) )
  b = true || false;
  c = EOF;
  if (a == NULL) RAISE(235)
  i = a->length;
  if (s == NULL) RAISE(236)
  i = s->length;
  CHECK(237, String_clear(s) )
  CHECK(238, String_equal(s, s, &(b)) )
  CHECK(239, String_get(s, i, &(c)) )
  CHECK(240, String_append(s, c) )
  CHECK(241, String_copy(s, s) )
  CHECK(242, String_concat(s, s) )
  CHECK(243, String_concat_int(s, i) )
  CHECK(244, String_find(s, s, &(i)) )
  CHECK(245, String_has(s, c, &(b)) )
  CHECK(247, file_open_read(s, &(f)) )
  CHECK(248, file_open_write(s, &(f)) )
  CHECK(249, File_getc(f, &(c)) )
  CHECK(250, File_putc(f, c) )
  CHECK(251, File_write(f, s) )
  CHECK(252, File_close(f) )
  if (sys == NULL) RAISE(253)
  if ((1) < 0 || (1) >= (sys->argv)->length) RAISE(253)
  s = ((String**)((sys->argv)->values))[1];
  CHECK(254, Sys_print(sys, s) )
  CHECK(255, Sys_println(sys, s) )
  CHECK(256, Sys_getenv(sys, s, s, &(b)) )
  CHECK(257, Sys_system(sys, s, &(i)) )
  CHECK(258, Sys_exit(sys, i) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME


/* main function */

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "main"
USER_MAIN_HEADER {
  CHECK(262, test_simple_function() )
  CHECK(263, test_call_expression() )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

MAIN_FUNC
