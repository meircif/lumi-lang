#include "mr.4.h"


/* types declaration */

typedef struct TestStruct TestStruct;


/* types struct */

struct TestStruct {
  Int num;
  String* text;
  TestStruct* ts;
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

Returncode test_slice_expression(String* s, Array* arri, Array* arrs, Array* arrt, Char* c, Int* i, TestStruct** t);

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


/* types methods body */

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestStruct.set"
Returncode TestStruct_set(TestStruct* self, Int x, String* s) {
  self->num = x;
  self->text = s;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestStruct.get"
Returncode TestStruct_get(TestStruct* self, Int* x, String** s) {
  *x = self->num;
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
  t->num = ((*to)->num + t->ts->num) + t->ts->ts->num;
  (*to)->num = t->num;
  t->ts->ts->num = 4;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-slice-expression"
Returncode test_slice_expression(String* s, Array* arri, Array* arrs, Array* arrt, Char* c, Int* i, TestStruct** t) {
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
  aux_Array_0_Var.length = 2;
  aux_Array_0_Var.values = (Byte*)((arrs)->values) + (4);
  if ((4) < 0 || (2) < 0 || (4) + (2) > (arrs)->length) RAISE(50)
  if ((4) < 0 || (4) >= (aux_Array_0)->length) RAISE(50)
  aux_String_0_Var.length = 3;
  aux_String_0_Var.max_length = aux_String_0_Var.length + 1;
  aux_String_0_Var.values = ((((String**)((aux_Array_0)->values))[4]))->values + (1);
  if ((1) < 0 || (3) < 0 || (1) + (3) > ((((String**)((aux_Array_0)->values))[4]))->length) RAISE(50)
  if ((0) < 0 || (0) >= (aux_String_0)->length) RAISE(50)
  if ((3) < 0 || (3) >= (arrs)->length) RAISE(50)
  if ((2) < 0 || (2) >= ((((String**)((arrs)->values))[3]))->length) RAISE(50)
  aux_String_1_Var.length = 7;
  aux_String_1_Var.max_length = aux_String_1_Var.length + 1;
  aux_String_1_Var.values = (s)->values + (4);
  if ((4) < 0 || (7) < 0 || (4) + (7) > (s)->length) RAISE(50)
  if ((2) < 0 || (2) >= (aux_String_1)->length) RAISE(50)
  if ((2) < 0 || (2) >= (s)->length) RAISE(50)
  *c = (((((s)->values)[2]) + (((aux_String_1)->values)[2])) + ((((((String**)((arrs)->values))[3]))->values)[2])) + (((aux_String_0)->values)[0]);
  aux_Array_1_Var.length = 4;
  aux_Array_1_Var.values = (Byte*)((arri)->values) + (2);
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arri)->length) RAISE(52)
  aux_Array_2_Var.length = 2;
  aux_Array_2_Var.values = (Byte*)((aux_Array_1)->values) + (1);
  if ((1) < 0 || (2) < 0 || (1) + (2) > (aux_Array_1)->length) RAISE(52)
  if ((1) < 0 || (1) >= (aux_Array_2)->length) RAISE(52)
  aux_Array_3_Var.length = 4;
  aux_Array_3_Var.values = (Byte*)((arrt)->values) + (2);
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arrt)->length) RAISE(51)
  if ((1) < 0 || (1) >= (aux_Array_3)->length) RAISE(51)
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(51)
  if ((2) < 0 || (2) >= (arri)->length) RAISE(51)
  if ((((*i) + 3) - (((Int*)((arri)->values))[2])) < 0 || (((*i) + 3) - (((Int*)((arri)->values))[2])) >= (arri)->length) RAISE(51)
  *i = (((((Int*)((arri)->values))[((*i) + 3) - (((Int*)((arri)->values))[2])]) + (((TestStruct**)((arrt)->values))[4])->num) + (((TestStruct**)((aux_Array_3)->values))[1])->num) + (((Int*)((aux_Array_2)->values))[1]);
  aux_Array_4_Var.length = 4;
  aux_Array_4_Var.values = (Byte*)((arri)->values) + (2);
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arri)->length) RAISE(53)
  if ((1) < 0 || (1) >= (aux_Array_4)->length) RAISE(53)
  aux_Array_5_Var.length = 5 * ((*i) - 1);
  aux_Array_5_Var.values = (Byte*)((arri)->values) + ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1]));
  if (((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1])) < 0 || (5 * ((*i) - 1)) < 0 || ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1])) + (5 * ((*i) - 1)) > (arri)->length) RAISE(53)
  arri = aux_Array_5;
  if ((4) < 0 || (4) >= (arrs)->length) RAISE(54)
  s = ((String**)((arrs)->values))[4];
  aux_Array_6_Var.length = 7;
  aux_Array_6_Var.values = (Byte*)((arrs)->values) + (2);
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrs)->length) RAISE(55)
  arrs = aux_Array_6;
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(56)
  *t = ((TestStruct**)((arrt)->values))[4];
  aux_Array_7_Var.length = 7;
  aux_Array_7_Var.values = (Byte*)((arrt)->values) + (2);
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrt)->length) RAISE(57)
  arrt = aux_Array_7;
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
  if ((0) < 0 || (0) >= (arr)->length) RAISE(79)
  sn = MR_new_string(((Int*)((arr)->values))[0]);
  if ((0) < 0 || (0) >= (arr)->length) RAISE(80)
  ian = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if ((0) < 0 || (0) >= (arr)->length) RAISE(81)
  tan = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestStruct));
  if ((0) < 0 || (0) >= (arr)->length) RAISE(82)
  if ((1) < 0 || (1) >= (arr)->length) RAISE(82)
  san = MR_new_array(((Int*)((arr)->values))[0], sizeof(String) + (((Int*)((arr)->values))[1]));
  MR_set_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1], san);
  if ((0) < 0 || (0) >= (arr)->length) RAISE(83)
  ix = ((Int*)((arr)->values))[0];
  is = text;
  isv_Var.values = isv_Values;
  aux_String_0->max_length = 12;
  aux_String_0->length = 11;
  aux_String_0->values = "some string";
  CHECK(85, String_copy(isv, aux_String_0) )
  isn = MR_new_string(i);
  CHECK(86, String_copy(isn, text) )
  TEST_ASSERT(87, x == 0)
  TEST_ASSERT(88, s != NULL)
  TEST_ASSERT(89, a != NULL)
  TEST_ASSERT(90, t != NULL)
  TEST_ASSERT(91, tv != NULL)
  TEST_ASSERT(92, sv != NULL)
  TEST_ASSERT(93, ia != NULL)
  TEST_ASSERT(94, ta != NULL)
  TEST_ASSERT(95, sa != NULL)
  TEST_ASSERT(96, tn != NULL)
  TEST_ASSERT(97, sn != NULL)
  TEST_ASSERT(98, ian != NULL)
  TEST_ASSERT(99, tan != NULL)
  TEST_ASSERT(100, san != NULL)
  TEST_ASSERT(101, ix == 0)
  TEST_ASSERT(102, is != NULL)
  TEST_ASSERT(103, isv != NULL)
  TEST_ASSERT(104, isn != NULL)
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
  return OK;
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
  CHECK(163, f_test_void() )
  aux_String_0->max_length = 5;
  aux_String_0->length = 4;
  aux_String_0->values = "text";
  CHECK(164, f_test_params(3, aux_String_0, NULL) )
  CHECK(165, f_test_outs(&(s), &(x)) )
  CHECK(166, f_test_int2str(4, &(s)) )
  CHECK(167, f_test_int(5) )
  CHECK(168, f_test_int2int(6, &(x)) )
  CHECK(169, f_test_many(7, 8, &(x), &(x)) )
  CHECK(175, f_test_int2int(9, &(tmp)) )
  CHECK(175, f_test_int(tmp) )
  CHECK(176, f_test_many(11, 12, &(x), &(aux_Int_0)) )
  CHECK(176, f_test_int2int(10, &(aux_Int_1)) )
  x = aux_Int_1 + aux_Int_0;
  CHECK(177, f_test_int2str(13, &(aux_String_1)) )
  s = aux_String_1;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME


/* main function */

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "main"
USER_MAIN_HEADER {
  CHECK(181, test_simple_function() )
  CHECK(182, test_call_expression() )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

MAIN_FUNC
