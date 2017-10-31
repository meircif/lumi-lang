#include "mr.4.h"


/* types declaration */

typedef struct TestStruct TestStruct;


/* types struct */

struct TestStruct {
  Int num;
  String* text;
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
  TEST_ASSERT(47, x == 0)
  TEST_ASSERT(48, s != NULL)
  TEST_ASSERT(49, a != NULL)
  TEST_ASSERT(50, t != NULL)
  TEST_ASSERT(51, tv != NULL)
  TEST_ASSERT(52, sv != NULL)
  TEST_ASSERT(53, ia != NULL)
  TEST_ASSERT(54, ta != NULL)
  TEST_ASSERT(55, sa != NULL)
  TEST_ASSERT(56, tn != NULL)
  TEST_ASSERT(57, sn != NULL)
  TEST_ASSERT(58, ian != NULL)
  TEST_ASSERT(59, tan != NULL)
  TEST_ASSERT(60, san != NULL)
  TEST_ASSERT(61, ix == 0)
  TEST_ASSERT(62, is != NULL)
  TEST_ASSERT(63, isv != NULL)
  TEST_ASSERT(64, isn != NULL)
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
