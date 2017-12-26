#include "mr.4.h"


/* types declaration */

typedef struct TestStruct TestStruct;

typedef struct TestClass TestClass;

typedef struct TestClass_Dynamic TestClass_Dynamic;

typedef struct Data Data;


/* types struct */

struct TestStruct {
  Int num;
  String* text;
  RefManager* text_Refman;
  TestStruct* ts;
  RefManager* ts_Refman;
  Returncode (*fun)(void);
};

struct TestClass {
  Int num;
  String* text;
  RefManager* text_Refman;
};

struct TestClass_Dynamic {
  Returncode (*dynamic_meth)(TestClass* self, RefManager* self_Refman, TestClass_Dynamic* self_Dynamic);
};

struct Data {
  Generic_Subtype* item;
  RefManager* item_Refman;
  Array* arr;
  RefManager* arr_Refman;
};


/* types methods declaration */

Returncode TestStruct_new(TestStruct* self, RefManager* self_Refman, Int x, String* s, RefManager* s_Refman);

Returncode TestStruct_get(TestStruct* self, RefManager* self_Refman, Int* x, String** s, RefManager** s_Refman);

Returncode TestStruct_print(TestStruct* self, RefManager* self_Refman);

Returncode TestClass_new(TestClass* self, RefManager* self_Refman, TestClass_Dynamic* self_Dynamic);

Returncode TestClass_static_meth(TestClass* self, RefManager* self_Refman, TestClass_Dynamic* self_Dynamic);

Returncode TestClass_dynamic_meth(TestClass* self, RefManager* self_Refman, TestClass_Dynamic* self_Dynamic);

Returncode TestClass_print(TestClass* self, RefManager* self_Refman, TestClass_Dynamic* self_Dynamic);

Returncode Data_set(Data* self, RefManager* self_Refman, Generic_Subtype* item, RefManager* item_Refman, Array* arr, RefManager* arr_Refman);

Returncode Data_get(Data* self, RefManager* self_Refman, Generic_Subtype** item, RefManager** item_Refman);


/* types global variables */

TestClass_Dynamic TestClass_dynamic = {TestClass_dynamic_meth};


/* global variables */

Int global_int = 0;

String* global_string = NULL;
RefManager* global_string_Refman = NULL;


/* global functions declaration */

Returncode test_simple_function(void);

Returncode test_const_expression(Int* i, Char* c, String** s, RefManager** s_Refman, TestStruct** t, RefManager** t_Refman, TestClass** d, RefManager** d_Refman, TestClass_Dynamic** d_Dynamic, Returncode (**f)(void));

Returncode test_member_expression(TestStruct* t, RefManager* t_Refman, TestStruct** to, RefManager** to_Refman, Int* i);

Returncode test_slice_expression(String* s, RefManager* s_Refman, Array* arri, RefManager* arri_Refman, Array* arrs, RefManager* arrs_Refman, Array* arrt, RefManager* arrt_Refman, Array* arrd, RefManager* arrd_Refman, Array* arrf, RefManager* arrf_Refman, Char* c, Int* i, TestStruct** t, RefManager** t_Refman, TestClass** d, RefManager** d_Refman, TestClass_Dynamic** d_Dynamic, Returncode (**f)(void), Array** arrio, RefManager** arrio_Refman, Array** arrso, RefManager** arrso_Refman, Array** arrto, RefManager** arrto_Refman, Array** arrdo, RefManager** arrdo_Refman, Array** arrfo, RefManager** arrfo_Refman);

Returncode test_container_expression(Int x, Int y, String* s, RefManager* s_Refman, Int* i, Bool* b);

Returncode test_variable(Int i, String* text, RefManager* text_Refman, Array* arr, RefManager* arr_Refman);

Returncode test_complex_function(Int num, String* text, RefManager* text_Refman, Int* out_num, String** out_text, RefManager** out_text_Refman);

Returncode f_test_void(void);

Returncode f_test_params(Int x, String* s, RefManager* s_Refman, String* o, RefManager* o_Refman);

Returncode f_test_outs(String** s, RefManager** s_Refman, Int* x);

Returncode f_test_int2str(Int x, String** s, RefManager** s_Refman);

Returncode f_test_int(Int x);

Returncode f_test_int2int(Int x, Int* r);

Returncode f_test_many(Int x, Int y, Int* n, Int* m);

Returncode test_call_expression(void);

Returncode test_code_flow(Array* arr, RefManager* arr_Refman, Int* res);

Returncode test_builtins(Int i, Char c, Bool b, String* s, RefManager* s_Refman, Array* a, RefManager* a_Refman);

Returncode test_ref_count(void);

Returncode f_remove(String* s, RefManager* s_Refman);

Returncode test_type_parameters(String* s, RefManager* s_Refman);


/* types methods body */

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestStruct.new"
Returncode TestStruct_new(TestStruct* self, RefManager* self_Refman, Int x, String* s, RefManager* s_Refman) {
  Returncode MR_err = OK;
  TestStruct* aux_TestStruct_0 = NULL;
  RefManager* aux_TestStruct_0_Refman = NULL;
  MR_inc_ref(s_Refman);
  if (self == NULL || self_Refman->value == NULL) RAISE(195)
  self->num = x;
  if (self == NULL || self_Refman->value == NULL) RAISE(196)
  MR_dec_ref(self->text_Refman);
  self->text_Refman = s_Refman;
  MR_inc_ref(self->text_Refman);
  self->text = s;
  if (x < 0) {
      aux_TestStruct_0 = calloc(1, sizeof(TestStruct));
      if (aux_TestStruct_0 == NULL) RAISE(198)
      aux_TestStruct_0_Refman = MR_new_ref(aux_TestStruct_0);
      if (aux_TestStruct_0_Refman == NULL) RAISE(198)
      CHECK(198, TestStruct_new(aux_TestStruct_0, aux_TestStruct_0_Refman, x + 1, s, s_Refman) )
      if (self == NULL || self_Refman->value == NULL) RAISE(198)
      MR_dec_ref(self->ts_Refman);
      self->ts_Refman = aux_TestStruct_0_Refman;
      MR_inc_ref(self->ts_Refman);
      self->ts = aux_TestStruct_0;
    }
MR_cleanup:
  MR_owner_dec_ref(aux_TestStruct_0_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestStruct.get"
Returncode TestStruct_get(TestStruct* self, RefManager* self_Refman, Int* x, String** s, RefManager** s_Refman) {
  Returncode MR_err = OK;
  if (self == NULL || self_Refman->value == NULL) RAISE(205)
  *x = self->num;
  if (self == NULL || self_Refman->value == NULL) RAISE(206)
  MR_dec_ref(*s_Refman);
  *s_Refman = self->text_Refman;
  MR_inc_ref(*s_Refman);
  *s = self->text;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestStruct.print"
Returncode TestStruct_print(TestStruct* self, RefManager* self_Refman) {
  Returncode MR_err = OK;
  if (self == NULL || self_Refman->value == NULL) RAISE(209)
  CHECK(209, Sys_println(sys, sys_Refman, self->text, self->text_Refman) )
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestClass.new"
Returncode TestClass_new(TestClass* self, RefManager* self_Refman, TestClass_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  if (self == NULL || self_Refman->value == NULL) RAISE(217)
  self->num = 1;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestClass.static-meth"
Returncode TestClass_static_meth(TestClass* self, RefManager* self_Refman, TestClass_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  if (self == NULL || self_Refman->value == NULL) RAISE(220)
  self->num = 3;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestClass.dynamic-meth"
Returncode TestClass_dynamic_meth(TestClass* self, RefManager* self_Refman, TestClass_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  if (self == NULL || self_Refman->value == NULL) RAISE(223)
  self->num = 6;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestClass.print"
Returncode TestClass_print(TestClass* self, RefManager* self_Refman, TestClass_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  if (self == NULL || self_Refman->value == NULL) RAISE(226)
  CHECK(226, Sys_println(sys, sys_Refman, self->text, self->text_Refman) )
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "Data.set"
Returncode Data_set(Data* self, RefManager* self_Refman, Generic_Subtype* item, RefManager* item_Refman, Array* arr, RefManager* arr_Refman) {
  Returncode MR_err = OK;
  Generic_Subtype* x = NULL;
  RefManager* x_Refman = NULL;
  Data* d = NULL;
  RefManager* d_Refman = NULL;
  MR_inc_ref(item_Refman);
  MR_inc_ref(arr_Refman);
  x = item;
  x_Refman = item_Refman;
  MR_inc_ref(x_Refman);
  if (self == NULL || self_Refman->value == NULL) RAISE(353)
  MR_dec_ref(self->item_Refman);
  self->item_Refman = x_Refman;
  MR_inc_ref(self->item_Refman);
  self->item = x;
  if (self == NULL || self_Refman->value == NULL) RAISE(354)
  MR_dec_ref(self->arr_Refman);
  self->arr_Refman = arr_Refman;
  MR_inc_ref(self->arr_Refman);
  self->arr = arr;
  if (arr == NULL || arr_Refman->value == NULL) RAISE(355)
  if ((2) < 0 || (2) >= (arr)->length) RAISE(355)
  MR_dec_ref(x_Refman);
  x_Refman = arr_Refman;
  MR_inc_ref(x_Refman);
  x = ((Generic_Subtype**)((arr)->values))[2];
  d = calloc(1, sizeof(Data));
  if (d == NULL) RAISE(356)
  d_Refman = MR_new_ref(d);
  if (d_Refman == NULL) RAISE(356)
  if (self == NULL || self_Refman->value == NULL) RAISE(357)
  if (d == NULL || d_Refman->value == NULL) RAISE(357)
  MR_dec_ref(d->item_Refman);
  d->item_Refman = self->item_Refman;
  MR_inc_ref(d->item_Refman);
  d->item = self->item;
  if (d == NULL || d_Refman->value == NULL) RAISE(358)
  if (self == NULL || self_Refman->value == NULL) RAISE(358)
  MR_dec_ref(self->item_Refman);
  self->item_Refman = d->item_Refman;
  MR_inc_ref(self->item_Refman);
  self->item = d->item;
MR_cleanup:
  MR_owner_dec_ref(d_Refman);
  MR_dec_ref(x_Refman);
  MR_dec_ref(arr_Refman);
  MR_dec_ref(item_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "Data.get"
Returncode Data_get(Data* self, RefManager* self_Refman, Generic_Subtype** item, RefManager** item_Refman) {
  Returncode MR_err = OK;
  if (self == NULL || self_Refman->value == NULL) RAISE(361)
  MR_dec_ref(*item_Refman);
  *item_Refman = self->item_Refman;
  MR_inc_ref(*item_Refman);
  *item = self->item;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME


/* global functions body */

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-simple-function"
Returncode test_simple_function(void) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  RefManager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(26)
  aux_String_0_Var.max_length = 23;
  aux_String_0_Var.length = 22;
  aux_String_0_Var.values = "I am a simple function";
  CHECK(26, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-const-expression"
Returncode test_const_expression(Int* i, Char* c, String** s, RefManager** s_Refman, TestStruct** t, RefManager** t_Refman, TestClass** d, RefManager** d_Refman, TestClass_Dynamic** d_Dynamic, Returncode (**f)(void)) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  RefManager* aux_String_0_Refman = NULL;
  *i = (((((((0 + 9630) + -9630) + 07520) + -07520) + 0xfda940) + -0xfda940) + 0xFDA940) + -0xFDA940;
  *c = (((('a' + '\'') + '\n') + '\x0f') + '\xA9') + '\270';
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(39)
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  MR_dec_ref(*s_Refman);
  *s_Refman = aux_String_0_Refman;
  MR_inc_ref(*s_Refman);
  *s = aux_String_0;
  MR_dec_ref(*t_Refman);
  *t_Refman = NULL;
  MR_inc_ref(*t_Refman);
  *t = NULL;
  MR_dec_ref(*d_Refman);
  *d_Refman = NULL;
  MR_inc_ref(*d_Refman);
  *d_Dynamic = NULL;
  *d = NULL;
  *f = NULL;
  if (*f == NULL) RAISE(43)
  CHECK(43, (*f)() )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-member-expression"
Returncode test_member_expression(TestStruct* t, RefManager* t_Refman, TestStruct** to, RefManager** to_Refman, Int* i) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  RefManager* aux_String_0_Refman = NULL;
  MR_inc_ref(t_Refman);
  if (t == NULL || t_Refman->value == NULL) RAISE(47)
  if (t->ts == NULL || t->ts_Refman->value == NULL) RAISE(47)
  if (t->ts->ts == NULL || t->ts->ts_Refman->value == NULL) RAISE(47)
  if (t == NULL || t_Refman->value == NULL) RAISE(47)
  if (t->ts == NULL || t->ts_Refman->value == NULL) RAISE(47)
  if (*to == NULL || (*to_Refman)->value == NULL) RAISE(47)
  if (t == NULL || t_Refman->value == NULL) RAISE(47)
  t->num = ((*to)->num + t->ts->num) + t->ts->ts->num;
  if (t == NULL || t_Refman->value == NULL) RAISE(48)
  if (*to == NULL || (*to_Refman)->value == NULL) RAISE(48)
  (*to)->num = t->num;
  if (t == NULL || t_Refman->value == NULL) RAISE(49)
  if (t->ts == NULL || t->ts_Refman->value == NULL) RAISE(49)
  if (t->ts->ts == NULL || t->ts->ts_Refman->value == NULL) RAISE(49)
  t->ts->ts->num = 4;
  if (t == NULL || t_Refman->value == NULL) RAISE(50)
  t->fun = f_test_void;
  if (t == NULL || t_Refman->value == NULL) RAISE(51)
  if (t->fun == NULL) RAISE(51)
  CHECK(51, t->fun() )
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(52)
  aux_String_0_Var.max_length = 1;
  aux_String_0_Var.length = 0;
  aux_String_0_Var.values = "";
  CHECK(52, TestStruct_new(t, t_Refman, 0, aux_String_0, aux_String_0_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(t_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-slice-expression"
Returncode test_slice_expression(String* s, RefManager* s_Refman, Array* arri, RefManager* arri_Refman, Array* arrs, RefManager* arrs_Refman, Array* arrt, RefManager* arrt_Refman, Array* arrd, RefManager* arrd_Refman, Array* arrf, RefManager* arrf_Refman, Char* c, Int* i, TestStruct** t, RefManager** t_Refman, TestClass** d, RefManager** d_Refman, TestClass_Dynamic** d_Dynamic, Returncode (**f)(void), Array** arrio, RefManager** arrio_Refman, Array** arrso, RefManager** arrso_Refman, Array** arrto, RefManager** arrto_Refman, Array** arrdo, RefManager** arrdo_Refman, Array** arrfo, RefManager** arrfo_Refman) {
  Returncode MR_err = OK;
  Array aux_Array_0_Var = {0};
  Array* aux_Array_0 = NULL;
  RefManager* aux_Array_0_Refman = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  RefManager* aux_String_0_Refman = NULL;
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  RefManager* aux_String_1_Refman = NULL;
  Array aux_Array_1_Var = {0};
  Array* aux_Array_1 = NULL;
  RefManager* aux_Array_1_Refman = NULL;
  Array aux_Array_2_Var = {0};
  Array* aux_Array_2 = NULL;
  RefManager* aux_Array_2_Refman = NULL;
  Array aux_Array_3_Var = {0};
  Array* aux_Array_3 = NULL;
  RefManager* aux_Array_3_Refman = NULL;
  Array aux_Array_4_Var = {0};
  Array* aux_Array_4 = NULL;
  RefManager* aux_Array_4_Refman = NULL;
  Array aux_Array_5_Var = {0};
  Array* aux_Array_5 = NULL;
  RefManager* aux_Array_5_Refman = NULL;
  Array aux_Array_6_Var = {0};
  Array* aux_Array_6 = NULL;
  RefManager* aux_Array_6_Refman = NULL;
  Array aux_Array_7_Var = {0};
  Array* aux_Array_7 = NULL;
  RefManager* aux_Array_7_Refman = NULL;
  Array aux_Array_8_Var = {0};
  Array* aux_Array_8 = NULL;
  RefManager* aux_Array_8_Refman = NULL;
  Array aux_Array_9_Var = {0};
  Array* aux_Array_9 = NULL;
  RefManager* aux_Array_9_Refman = NULL;
  MR_inc_ref(s_Refman);
  MR_inc_ref(arri_Refman);
  MR_inc_ref(arrs_Refman);
  MR_inc_ref(arrt_Refman);
  MR_inc_ref(arrd_Refman);
  MR_inc_ref(arrf_Refman);
  aux_Array_0 = &aux_Array_0_Var;
  aux_Array_0_Refman = MR_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(72)
  aux_Array_0_Var.length = 2;
  aux_Array_0_Var.values = (Byte*)((arrs)->values) + (4);
  if (arrs == NULL || arrs_Refman->value == NULL) RAISE(72)
  if ((4) < 0 || (2) < 0 || (4) + (2) > (arrs)->length) RAISE(72)
  if (aux_Array_0 == NULL || arrs_Refman->value == NULL) RAISE(72)
  if ((4) < 0 || (4) >= (aux_Array_0)->length) RAISE(72)
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(72)
  aux_String_0_Var.length = 3;
  aux_String_0_Var.max_length = aux_String_0_Var.length + 1;
  aux_String_0_Var.values = ((((String**)((aux_Array_0)->values))[4]))->values + (1);
  if (((String**)((aux_Array_0)->values))[4] == NULL || arrs_Refman->value == NULL) RAISE(72)
  if ((1) < 0 || (3) < 0 || (1) + (3) > ((((String**)((aux_Array_0)->values))[4]))->length) RAISE(72)
  if (aux_String_0 == NULL || arrs_Refman->value == NULL) RAISE(72)
  if ((0) < 0 || (0) >= (aux_String_0)->length) RAISE(72)
  if (arrs == NULL || arrs_Refman->value == NULL) RAISE(72)
  if ((3) < 0 || (3) >= (arrs)->length) RAISE(72)
  if (((String**)((arrs)->values))[3] == NULL || arrs_Refman->value == NULL) RAISE(72)
  if ((2) < 0 || (2) >= ((((String**)((arrs)->values))[3]))->length) RAISE(72)
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = MR_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(72)
  aux_String_1_Var.length = 7;
  aux_String_1_Var.max_length = aux_String_1_Var.length + 1;
  aux_String_1_Var.values = (s)->values + (4);
  if (s == NULL || s_Refman->value == NULL) RAISE(72)
  if ((4) < 0 || (7) < 0 || (4) + (7) > (s)->length) RAISE(72)
  if (aux_String_1 == NULL || s_Refman->value == NULL) RAISE(72)
  if ((2) < 0 || (2) >= (aux_String_1)->length) RAISE(72)
  if (s == NULL || s_Refman->value == NULL) RAISE(72)
  if ((2) < 0 || (2) >= (s)->length) RAISE(72)
  *c = (((((s)->values)[2]) + (((aux_String_1)->values)[2])) + ((((((String**)((arrs)->values))[3]))->values)[2])) + (((aux_String_0)->values)[0]);
  aux_Array_1 = &aux_Array_1_Var;
  aux_Array_1_Refman = MR_new_ref(aux_Array_1);
  if (aux_Array_1_Refman == NULL) RAISE(74)
  aux_Array_1_Var.length = 3;
  aux_Array_1_Var.values = (Byte*)((arri)->values) + (3);
  if (arri == NULL || arri_Refman->value == NULL) RAISE(74)
  if ((3) < 0 || (3) < 0 || (3) + (3) > (arri)->length) RAISE(74)
  aux_Array_2 = &aux_Array_2_Var;
  aux_Array_2_Refman = MR_new_ref(aux_Array_2);
  if (aux_Array_2_Refman == NULL) RAISE(74)
  aux_Array_2_Var.length = 2;
  aux_Array_2_Var.values = (Byte*)((aux_Array_1)->values) + (1);
  if (aux_Array_1 == NULL || arri_Refman->value == NULL) RAISE(74)
  if ((1) < 0 || (2) < 0 || (1) + (2) > (aux_Array_1)->length) RAISE(74)
  if (aux_Array_2 == NULL || arri_Refman->value == NULL) RAISE(74)
  if ((1) < 0 || (1) >= (aux_Array_2)->length) RAISE(74)
  aux_Array_3 = &aux_Array_3_Var;
  aux_Array_3_Refman = MR_new_ref(aux_Array_3);
  if (aux_Array_3_Refman == NULL) RAISE(73)
  aux_Array_3_Var.length = 4;
  aux_Array_3_Var.values = (Byte*)((arrt)->values) + (2);
  if (arrt == NULL || arrt_Refman->value == NULL) RAISE(73)
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arrt)->length) RAISE(73)
  if (aux_Array_3 == NULL || arrt_Refman->value == NULL) RAISE(73)
  if ((1) < 0 || (1) >= (aux_Array_3)->length) RAISE(73)
  if (((TestStruct**)((aux_Array_3)->values))[1] == NULL || arrt_Refman->value == NULL) RAISE(73)
  if (arrt == NULL || arrt_Refman->value == NULL) RAISE(73)
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(73)
  if (((TestStruct**)((arrt)->values))[4] == NULL || arrt_Refman->value == NULL) RAISE(73)
  if (arri == NULL || arri_Refman->value == NULL) RAISE(73)
  if ((2) < 0 || (2) >= (arri)->length) RAISE(73)
  if (arri == NULL || arri_Refman->value == NULL) RAISE(73)
  if ((((*i) + 3) - (((Int*)((arri)->values))[2])) < 0 || (((*i) + 3) - (((Int*)((arri)->values))[2])) >= (arri)->length) RAISE(73)
  *i = (((((Int*)((arri)->values))[((*i) + 3) - (((Int*)((arri)->values))[2])]) + (((TestStruct**)((arrt)->values))[4])->num) + (((TestStruct**)((aux_Array_3)->values))[1])->num) + (((Int*)((aux_Array_2)->values))[1]);
  aux_Array_4 = &aux_Array_4_Var;
  aux_Array_4_Refman = MR_new_ref(aux_Array_4);
  if (aux_Array_4_Refman == NULL) RAISE(75)
  aux_Array_4_Var.length = 4;
  aux_Array_4_Var.values = (Byte*)((arri)->values) + (2);
  if (arri == NULL || arri_Refman->value == NULL) RAISE(75)
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arri)->length) RAISE(75)
  if (aux_Array_4 == NULL || arri_Refman->value == NULL) RAISE(75)
  if ((1) < 0 || (1) >= (aux_Array_4)->length) RAISE(75)
  aux_Array_5 = &aux_Array_5_Var;
  aux_Array_5_Refman = MR_new_ref(aux_Array_5);
  if (aux_Array_5_Refman == NULL) RAISE(75)
  aux_Array_5_Var.length = 5 * ((*i) - 1);
  aux_Array_5_Var.values = (Byte*)((arri)->values) + ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1]));
  if (arri == NULL || arri_Refman->value == NULL) RAISE(75)
  if (((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1])) < 0 || (5 * ((*i) - 1)) < 0 || ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1])) + (5 * ((*i) - 1)) > (arri)->length) RAISE(75)
  MR_dec_ref(*arrio_Refman);
  *arrio_Refman = arri_Refman;
  MR_inc_ref(*arrio_Refman);
  *arrio = aux_Array_5;
  if (arrs == NULL || arrs_Refman->value == NULL) RAISE(76)
  if ((4) < 0 || (4) >= (arrs)->length) RAISE(76)
  MR_dec_ref(s_Refman);
  s_Refman = arrs_Refman;
  MR_inc_ref(s_Refman);
  s = ((String**)((arrs)->values))[4];
  aux_Array_6 = &aux_Array_6_Var;
  aux_Array_6_Refman = MR_new_ref(aux_Array_6);
  if (aux_Array_6_Refman == NULL) RAISE(77)
  aux_Array_6_Var.length = 7;
  aux_Array_6_Var.values = (Byte*)((arrs)->values) + (2);
  if (arrs == NULL || arrs_Refman->value == NULL) RAISE(77)
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrs)->length) RAISE(77)
  MR_dec_ref(*arrso_Refman);
  *arrso_Refman = arrs_Refman;
  MR_inc_ref(*arrso_Refman);
  *arrso = aux_Array_6;
  if (arrt == NULL || arrt_Refman->value == NULL) RAISE(78)
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(78)
  MR_dec_ref(*t_Refman);
  *t_Refman = arrt_Refman;
  MR_inc_ref(*t_Refman);
  *t = ((TestStruct**)((arrt)->values))[4];
  aux_Array_7 = &aux_Array_7_Var;
  aux_Array_7_Refman = MR_new_ref(aux_Array_7);
  if (aux_Array_7_Refman == NULL) RAISE(79)
  aux_Array_7_Var.length = 7;
  aux_Array_7_Var.values = (Byte*)((arrt)->values) + (2);
  if (arrt == NULL || arrt_Refman->value == NULL) RAISE(79)
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrt)->length) RAISE(79)
  MR_dec_ref(*arrto_Refman);
  *arrto_Refman = arrt_Refman;
  MR_inc_ref(*arrto_Refman);
  *arrto = aux_Array_7;
  if (arrd == NULL || arrd_Refman->value == NULL) RAISE(80)
  if ((4) < 0 || (4) >= (arrd)->length) RAISE(80)
  MR_dec_ref(*d_Refman);
  *d_Refman = arrd_Refman;
  MR_inc_ref(*d_Refman);
  *d_Dynamic = &TestClass_dynamic;
  *d = ((TestClass**)((arrd)->values))[4];
  aux_Array_8 = &aux_Array_8_Var;
  aux_Array_8_Refman = MR_new_ref(aux_Array_8);
  if (aux_Array_8_Refman == NULL) RAISE(81)
  aux_Array_8_Var.length = 7;
  aux_Array_8_Var.values = (Byte*)((arrd)->values) + (2);
  if (arrd == NULL || arrd_Refman->value == NULL) RAISE(81)
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrd)->length) RAISE(81)
  MR_dec_ref(*arrdo_Refman);
  *arrdo_Refman = arrd_Refman;
  MR_inc_ref(*arrdo_Refman);
  *arrdo = aux_Array_8;
  if (arrf == NULL || arrf_Refman->value == NULL) RAISE(82)
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(82)
  *f = ((Returncode (**)(void))((arrf)->values))[4];
  aux_Array_9 = &aux_Array_9_Var;
  aux_Array_9_Refman = MR_new_ref(aux_Array_9);
  if (aux_Array_9_Refman == NULL) RAISE(83)
  aux_Array_9_Var.length = 7;
  aux_Array_9_Var.values = (Byte*)((arrf)->values) + (2);
  if (arrf == NULL || arrf_Refman->value == NULL) RAISE(83)
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrf)->length) RAISE(83)
  MR_dec_ref(*arrfo_Refman);
  *arrfo_Refman = arrf_Refman;
  MR_inc_ref(*arrfo_Refman);
  *arrfo = aux_Array_9;
  if (arrf == NULL || arrf_Refman->value == NULL) RAISE(84)
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(84)
  if (((Returncode (**)(void))((arrf)->values))[4] == NULL) RAISE(84)
  CHECK(84, (((Returncode (**)(void))((arrf)->values))[4])() )
  if (*arrfo == NULL || (*arrfo_Refman)->value == NULL) RAISE(85)
  if ((4) < 0 || (4) >= ((*arrfo))->length) RAISE(85)
  if (((Returncode (**)(void))(((*arrfo))->values))[4] == NULL) RAISE(85)
  CHECK(85, (((Returncode (**)(void))(((*arrfo))->values))[4])() )
MR_cleanup:
  MR_dec_ref(aux_Array_9_Refman);
  MR_dec_ref(aux_Array_8_Refman);
  MR_dec_ref(aux_Array_7_Refman);
  MR_dec_ref(aux_Array_6_Refman);
  MR_dec_ref(aux_Array_5_Refman);
  MR_dec_ref(aux_Array_4_Refman);
  MR_dec_ref(aux_Array_3_Refman);
  MR_dec_ref(aux_Array_2_Refman);
  MR_dec_ref(aux_Array_1_Refman);
  MR_dec_ref(aux_String_1_Refman);
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(aux_Array_0_Refman);
  MR_dec_ref(arrf_Refman);
  MR_dec_ref(arrd_Refman);
  MR_dec_ref(arrt_Refman);
  MR_dec_ref(arrs_Refman);
  MR_dec_ref(arri_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-container-expression"
Returncode test_container_expression(Int x, Int y, String* s, RefManager* s_Refman, Int* i, Bool* b) {
  Returncode MR_err = OK;
  MR_inc_ref(s_Refman);
  *i = (- x) + (- (- (- y)));
  *b = (! (((! ((((x * 3) - 5) > (6 * y)) && ((6 * y) == 234))) && (! ((5 - x) < y))) || (! ((x == (-2 - (-4 * y))) && (((-6 > y) && (y >= 12)) && (12 == x)))))) && ((((- (2 + x)) > y) || (!(s == NULL || s_Refman->value == NULL))) || (! (!(s == NULL || s_Refman->value == NULL))));
MR_cleanup:
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-variable"
Returncode test_variable(Int i, String* text, RefManager* text_Refman, Array* arr, RefManager* arr_Refman) {
  Returncode MR_err = OK;
  Int x = 0;
  String* s = NULL;
  RefManager* s_Refman = NULL;
  Array* a = NULL;
  RefManager* a_Refman = NULL;
  TestStruct* t = NULL;
  RefManager* t_Refman = NULL;
  TestClass* d = NULL;
  RefManager* d_Refman = NULL;
  TestClass_Dynamic* d_Dynamic = NULL;
  TestStruct tv_Var = {0};
  TestStruct* tv = NULL;
  RefManager* tv_Refman = NULL;
  TestClass dv_Var = {0};
  TestClass* dv = NULL;
  RefManager* dv_Refman = NULL;
  TestClass_Dynamic* dv_Dynamic = &TestClass_dynamic;
  char sv_Values[12];
  String sv_Var = {12, 0, NULL};
  String* sv = NULL;
  RefManager* sv_Refman = NULL;
  Returncode (*f)(Int xi, String* si, RefManager* si_Refman, Int* xo, String** so, RefManager** so_Refman) = NULL;
  Int ia_Values[12];
  Array ia_Var = {12, NULL};
  Array* ia = NULL;
  RefManager* ia_Refman = NULL;
  TestStruct ta_Values[12];
  Array ta_Var = {12, NULL};
  Array* ta = NULL;
  RefManager* ta_Refman = NULL;
  TestClass da_Values[12];
  Array da_Var = {12, NULL};
  Array* da = NULL;
  RefManager* da_Refman = NULL;
  char sa_Chars[12 * 7];
  String sa_Values[12];
  Array sa_Var = {12, NULL};
  Array* sa = NULL;
  RefManager* sa_Refman = NULL;
  Returncode (*fa_Values[12])(void);
  Array fa_Var = {12, NULL};
  Array* fa = NULL;
  RefManager* fa_Refman = NULL;
  TestStruct* tn = NULL;
  RefManager* tn_Refman = NULL;
  TestClass* dn = NULL;
  RefManager* dn_Refman = NULL;
  TestClass_Dynamic* dn_Dynamic = &TestClass_dynamic;
  String* sn = NULL;
  RefManager* sn_Refman = NULL;
  Array* ian = NULL;
  RefManager* ian_Refman = NULL;
  Array* tan = NULL;
  RefManager* tan_Refman = NULL;
  Array* dan = NULL;
  RefManager* dan_Refman = NULL;
  Array* san = NULL;
  RefManager* san_Refman = NULL;
  Array* sfn = NULL;
  RefManager* sfn_Refman = NULL;
  Int ix = 0;
  String* si = NULL;
  RefManager* si_Refman = NULL;
  char isv_Values[12];
  String isv_Var = {12, 0, NULL};
  String* isv = NULL;
  RefManager* isv_Refman = NULL;
  String* isn = NULL;
  RefManager* isn_Refman = NULL;
  Returncode (*fi)(Int x, String** s, RefManager** s_Refman) = NULL;
  TestStruct itv_Var = {0};
  TestStruct* itv = NULL;
  RefManager* itv_Refman = NULL;
  TestStruct* itn = NULL;
  RefManager* itn_Refman = NULL;
  TestClass idv_Var = {0};
  TestClass* idv = NULL;
  RefManager* idv_Refman = NULL;
  TestClass_Dynamic* idv_Dynamic = &TestClass_dynamic;
  TestClass* idn = NULL;
  RefManager* idn_Refman = NULL;
  TestClass_Dynamic* idn_Dynamic = &TestClass_dynamic;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  RefManager* aux_String_0_Refman = NULL;
  TestStruct* aux_TestStruct_0 = NULL;
  RefManager* aux_TestStruct_0_Refman = NULL;
  TestClass* aux_TestClass_0 = NULL;
  RefManager* aux_TestClass_0_Refman = NULL;
  TestClass_Dynamic* aux_TestClass_0_Dynamic = &TestClass_dynamic;
  String* aux_String_1 = NULL;
  RefManager* aux_String_1_Refman = NULL;
  Array* aux_Array_0 = NULL;
  RefManager* aux_Array_0_Refman = NULL;
  Array* aux_Array_1 = NULL;
  RefManager* aux_Array_1_Refman = NULL;
  Array* aux_Array_2 = NULL;
  RefManager* aux_Array_2_Refman = NULL;
  Array* aux_Array_3 = NULL;
  RefManager* aux_Array_3_Refman = NULL;
  Array* aux_Array_4 = NULL;
  RefManager* aux_Array_4_Refman = NULL;
  String* aux_String_2 = NULL;
  RefManager* aux_String_2_Refman = NULL;
  MR_inc_ref(text_Refman);
  MR_inc_ref(arr_Refman);
  tv = &tv_Var;
  tv_Refman = MR_new_ref(tv);
  if (tv_Refman == NULL) RAISE(102)
  CHECK(102, TestStruct_new(tv, tv_Refman, 0, NULL, NULL) )
  dv = &dv_Var;
  dv_Refman = MR_new_ref(dv);
  if (dv_Refman == NULL) RAISE(103)
  CHECK(103, TestClass_new(dv, dv_Refman, dv_Dynamic) )
  sv = &sv_Var;
  sv_Var.values = sv_Values;
  sv_Refman = MR_new_ref(sv);
  if (sv_Refman == NULL) RAISE(104)
  ia = &ia_Var;
  ia_Var.values = ia_Values;
  ia_Refman = MR_new_ref(ia);
  if (ia_Refman == NULL) RAISE(106)
  ta = &ta_Var;
  ta_Var.values = ta_Values;
  ta_Refman = MR_new_ref(ta);
  if (ta_Refman == NULL) RAISE(107)
  da = &da_Var;
  da_Var.values = da_Values;
  da_Refman = MR_new_ref(da);
  if (da_Refman == NULL) RAISE(108)
  sa = &sa_Var;
  sa_Var.values = sa_Values;
  MR_set_var_string_array(12, 7, sa, sa_Chars);
  sa_Refman = MR_new_ref(sa);
  if (sa_Refman == NULL) RAISE(109)
  fa = &fa_Var;
  fa_Var.values = fa_Values;
  fa_Refman = MR_new_ref(fa);
  if (fa_Refman == NULL) RAISE(110)
  tn = calloc(1, sizeof(TestStruct));
  if (tn == NULL) RAISE(111)
  tn_Refman = MR_new_ref(tn);
  if (tn_Refman == NULL) RAISE(111)
  CHECK(111, TestStruct_new(tn, tn_Refman, 0, NULL, NULL) )
  dn = calloc(1, sizeof(TestClass));
  if (dn == NULL) RAISE(112)
  dn_Refman = MR_new_ref(dn);
  if (dn_Refman == NULL) RAISE(112)
  CHECK(112, TestClass_new(dn, dn_Refman, dn_Dynamic) )
  if (arr == NULL || arr_Refman->value == NULL) RAISE(113)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(113)
  sn = MR_new_string(((Int*)((arr)->values))[0]);
  if (sn == NULL) RAISE(113)
  sn_Refman = MR_new_ref(sn);
  if (sn_Refman == NULL) RAISE(113)
  if (arr == NULL || arr_Refman->value == NULL) RAISE(114)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(114)
  ian = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if (ian == NULL) RAISE(114)
  ian_Refman = MR_new_ref(ian);
  if (ian_Refman == NULL) RAISE(114)
  if (arr == NULL || arr_Refman->value == NULL) RAISE(115)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(115)
  tan = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestStruct));
  if (tan == NULL) RAISE(115)
  tan_Refman = MR_new_ref(tan);
  if (tan_Refman == NULL) RAISE(115)
  if (arr == NULL || arr_Refman->value == NULL) RAISE(116)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(116)
  dan = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestClass));
  if (dan == NULL) RAISE(116)
  dan_Refman = MR_new_ref(dan);
  if (dan_Refman == NULL) RAISE(116)
  if (arr == NULL || arr_Refman->value == NULL) RAISE(117)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(117)
  if (arr == NULL || arr_Refman->value == NULL) RAISE(117)
  if ((1) < 0 || (1) >= (arr)->length) RAISE(117)
  san = MR_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]);
  if (san == NULL) RAISE(117)
  san_Refman = MR_new_ref(san);
  if (san_Refman == NULL) RAISE(117)
  if (arr == NULL || arr_Refman->value == NULL) RAISE(118)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(118)
  sfn = MR_new_array(((Int*)((arr)->values))[0], sizeof(Func));
  if (sfn == NULL) RAISE(118)
  sfn_Refman = MR_new_ref(sfn);
  if (sfn_Refman == NULL) RAISE(118)
  if (arr == NULL || arr_Refman->value == NULL) RAISE(119)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(119)
  ix = ((Int*)((arr)->values))[0];
  si = text;
  si_Refman = text_Refman;
  MR_inc_ref(si_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(121)
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  isv = &isv_Var;
  isv_Var.values = isv_Values;
  isv_Refman = MR_new_ref(isv);
  if (isv_Refman == NULL) RAISE(121)
  CHECK(121, String_new(isv, isv_Refman, aux_String_0, aux_String_0_Refman) )
  isn = MR_new_string(i);
  if (isn == NULL) RAISE(122)
  isn_Refman = MR_new_ref(isn);
  if (isn_Refman == NULL) RAISE(122)
  CHECK(122, String_new(isn, isn_Refman, text, text_Refman) )
  fi = f_test_int2str;
  itv = &itv_Var;
  itv_Refman = MR_new_ref(itv);
  if (itv_Refman == NULL) RAISE(124)
  CHECK(124, TestStruct_new(itv, itv_Refman, i, text, text_Refman) )
  itn = calloc(1, sizeof(TestStruct));
  if (itn == NULL) RAISE(125)
  itn_Refman = MR_new_ref(itn);
  if (itn_Refman == NULL) RAISE(125)
  CHECK(125, TestStruct_new(itn, itn_Refman, i, text, text_Refman) )
  idv = &idv_Var;
  idv_Refman = MR_new_ref(idv);
  if (idv_Refman == NULL) RAISE(126)
  CHECK(126, TestClass_new(idv, idv_Refman, idv_Dynamic) )
  idn = calloc(1, sizeof(TestClass));
  if (idn == NULL) RAISE(127)
  idn_Refman = MR_new_ref(idn);
  if (idn_Refman == NULL) RAISE(127)
  CHECK(127, TestClass_new(idn, idn_Refman, idn_Dynamic) )
  aux_TestStruct_0 = calloc(1, sizeof(TestStruct));
  if (aux_TestStruct_0 == NULL) RAISE(128)
  aux_TestStruct_0_Refman = MR_new_ref(aux_TestStruct_0);
  if (aux_TestStruct_0_Refman == NULL) RAISE(128)
  CHECK(128, TestStruct_new(aux_TestStruct_0, aux_TestStruct_0_Refman, i, text, text_Refman) )
  CHECK(128, TestStruct_print(aux_TestStruct_0, aux_TestStruct_0_Refman) )
  aux_TestClass_0 = calloc(1, sizeof(TestClass));
  if (aux_TestClass_0 == NULL) RAISE(129)
  aux_TestClass_0_Refman = MR_new_ref(aux_TestClass_0);
  if (aux_TestClass_0_Refman == NULL) RAISE(129)
  CHECK(129, TestClass_new(aux_TestClass_0, aux_TestClass_0_Refman, aux_TestClass_0_Dynamic) )
  CHECK(129, TestClass_print(aux_TestClass_0, aux_TestClass_0_Refman, aux_TestClass_0_Dynamic) )
  if (arr == NULL || arr_Refman->value == NULL) RAISE(130)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(130)
  aux_String_1 = MR_new_string(((Int*)((arr)->values))[0]);
  if (aux_String_1 == NULL) RAISE(130)
  aux_String_1_Refman = MR_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(130)
  TEST_ASSERT(130, !(aux_String_1 == NULL || aux_String_1_Refman->value == NULL))
  if (arr == NULL || arr_Refman->value == NULL) RAISE(131)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(131)
  aux_Array_0 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if (aux_Array_0 == NULL) RAISE(131)
  aux_Array_0_Refman = MR_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(131)
  TEST_ASSERT(131, !(aux_Array_0 == NULL || aux_Array_0_Refman->value == NULL))
  if (arr == NULL || arr_Refman->value == NULL) RAISE(132)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(132)
  aux_Array_1 = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestStruct));
  if (aux_Array_1 == NULL) RAISE(132)
  aux_Array_1_Refman = MR_new_ref(aux_Array_1);
  if (aux_Array_1_Refman == NULL) RAISE(132)
  TEST_ASSERT(132, !(aux_Array_1 == NULL || aux_Array_1_Refman->value == NULL))
  if (arr == NULL || arr_Refman->value == NULL) RAISE(133)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(133)
  aux_Array_2 = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestClass));
  if (aux_Array_2 == NULL) RAISE(133)
  aux_Array_2_Refman = MR_new_ref(aux_Array_2);
  if (aux_Array_2_Refman == NULL) RAISE(133)
  TEST_ASSERT(133, !(aux_Array_2 == NULL || aux_Array_2_Refman->value == NULL))
  if (arr == NULL || arr_Refman->value == NULL) RAISE(134)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(134)
  if (arr == NULL || arr_Refman->value == NULL) RAISE(134)
  if ((1) < 0 || (1) >= (arr)->length) RAISE(134)
  aux_Array_3 = MR_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]);
  if (aux_Array_3 == NULL) RAISE(134)
  aux_Array_3_Refman = MR_new_ref(aux_Array_3);
  if (aux_Array_3_Refman == NULL) RAISE(134)
  TEST_ASSERT(134, !(aux_Array_3 == NULL || aux_Array_3_Refman->value == NULL))
  if (arr == NULL || arr_Refman->value == NULL) RAISE(135)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(135)
  aux_Array_4 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Func));
  if (aux_Array_4 == NULL) RAISE(135)
  aux_Array_4_Refman = MR_new_ref(aux_Array_4);
  if (aux_Array_4_Refman == NULL) RAISE(135)
  TEST_ASSERT(135, !(aux_Array_4 == NULL || aux_Array_4_Refman->value == NULL))
  TEST_ASSERT(136, x == 0)
  TEST_ASSERT(137, !(s == NULL || s_Refman->value == NULL))
  TEST_ASSERT(138, !(a == NULL || a_Refman->value == NULL))
  CHECK(139, TestStruct_print(t, t_Refman) )
  CHECK(140, TestClass_print(d, d_Refman, d_Dynamic) )
  TEST_ASSERT(141, !(f == NULL))
  CHECK(142, TestStruct_print(tv, tv_Refman) )
  CHECK(143, TestClass_print(dv, dv_Refman, dv_Dynamic) )
  TEST_ASSERT(144, !(sv == NULL || sv_Refman->value == NULL))
  TEST_ASSERT(145, !(ia == NULL || ia_Refman->value == NULL))
  TEST_ASSERT(146, !(ta == NULL || ta_Refman->value == NULL))
  TEST_ASSERT(147, !(da == NULL || da_Refman->value == NULL))
  TEST_ASSERT(148, !(sa == NULL || sa_Refman->value == NULL))
  TEST_ASSERT(149, !(fa == NULL || fa_Refman->value == NULL))
  CHECK(150, TestStruct_print(tn, tn_Refman) )
  CHECK(151, TestClass_print(dn, dn_Refman, dn_Dynamic) )
  TEST_ASSERT(152, !(sn == NULL || sn_Refman->value == NULL))
  TEST_ASSERT(153, !(ian == NULL || ian_Refman->value == NULL))
  TEST_ASSERT(154, !(tan == NULL || tan_Refman->value == NULL))
  TEST_ASSERT(155, !(dan == NULL || dan_Refman->value == NULL))
  TEST_ASSERT(156, !(san == NULL || san_Refman->value == NULL))
  TEST_ASSERT(157, !(sfn == NULL || sfn_Refman->value == NULL))
  TEST_ASSERT(158, ix == 0)
  TEST_ASSERT(159, !(si == NULL || si_Refman->value == NULL))
  if (fi == NULL) RAISE(160)
  CHECK(160, fi(7, &(aux_String_2), &(aux_String_2_Refman)) )
  TEST_ASSERT(161, !(isv == NULL || isv_Refman->value == NULL))
  TEST_ASSERT(162, !(isn == NULL || isn_Refman->value == NULL))
MR_cleanup:
  MR_owner_dec_ref(aux_String_2_Refman);
  MR_owner_dec_ref(aux_Array_4_Refman);
  MR_owner_dec_ref(aux_Array_3_Refman);
  MR_owner_dec_ref(aux_Array_2_Refman);
  MR_owner_dec_ref(aux_Array_1_Refman);
  MR_owner_dec_ref(aux_Array_0_Refman);
  MR_owner_dec_ref(aux_String_1_Refman);
  MR_owner_dec_ref(aux_TestClass_0_Refman);
  MR_owner_dec_ref(aux_TestStruct_0_Refman);
  MR_dec_ref(aux_String_0_Refman);
  MR_owner_dec_ref(idn_Refman);
  MR_dec_ref(idv_Refman);
  MR_owner_dec_ref(itn_Refman);
  MR_dec_ref(itv_Refman);
  MR_owner_dec_ref(isn_Refman);
  MR_dec_ref(isv_Refman);
  MR_dec_ref(si_Refman);
  MR_owner_dec_ref(sfn_Refman);
  MR_owner_dec_ref(san_Refman);
  MR_owner_dec_ref(dan_Refman);
  MR_owner_dec_ref(tan_Refman);
  MR_owner_dec_ref(ian_Refman);
  MR_owner_dec_ref(sn_Refman);
  MR_owner_dec_ref(dn_Refman);
  MR_owner_dec_ref(tn_Refman);
  MR_dec_ref(fa_Refman);
  MR_dec_ref(sa_Refman);
  MR_dec_ref(da_Refman);
  MR_dec_ref(ta_Refman);
  MR_dec_ref(ia_Refman);
  MR_dec_ref(sv_Refman);
  MR_dec_ref(dv_Refman);
  MR_dec_ref(tv_Refman);
  MR_dec_ref(d_Refman);
  MR_dec_ref(t_Refman);
  MR_owner_dec_ref(a_Refman);
  MR_dec_ref(s_Refman);
  MR_dec_ref(arr_Refman);
  MR_dec_ref(text_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-complex-function"
Returncode test_complex_function(Int num, String* text, RefManager* text_Refman, Int* out_num, String** out_text, RefManager** out_text_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(text_Refman);
  *out_num = num;
  MR_dec_ref(*out_text_Refman);
  *out_text_Refman = text_Refman;
  MR_inc_ref(*out_text_Refman);
  *out_text = text;
MR_cleanup:
  MR_dec_ref(text_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-void"
Returncode f_test_void(void) {
  Returncode MR_err = OK;
  goto MR_cleanup;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-params"
Returncode f_test_params(Int x, String* s, RefManager* s_Refman, String* o, RefManager* o_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(s_Refman);
  MR_inc_ref(o_Refman);
  RAISE(232)
MR_cleanup:
  MR_owner_dec_ref(o_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-outs"
Returncode f_test_outs(String** s, RefManager** s_Refman, Int* x) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-int2str"
Returncode f_test_int2str(Int x, String** s, RefManager** s_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-int"
Returncode f_test_int(Int x) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-int2int"
Returncode f_test_int2int(Int x, Int* r) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-many"
Returncode f_test_many(Int x, Int y, Int* n, Int* m) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-call-expression"
Returncode test_call_expression(void) {
  Returncode MR_err = OK;
  String* s = NULL;
  RefManager* s_Refman = NULL;
  Int x = 0;
  Int tmp = 0;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  RefManager* aux_String_0_Refman = NULL;
  Int aux_Int_0 = 0;
  Int aux_Int_1 = 0;
  String* aux_String_1 = NULL;
  RefManager* aux_String_1_Refman = NULL;
  CHECK(247, f_test_void() )
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(248)
  aux_String_0_Var.max_length = 5;
  aux_String_0_Var.length = 4;
  aux_String_0_Var.values = "text";
  CHECK(248, f_test_params(3, aux_String_0, aux_String_0_Refman, NULL, NULL) )
  CHECK(249, f_test_outs(&(s), &(s_Refman), &(x)) )
  CHECK(250, f_test_int2str(4, &(s), &(s_Refman)) )
  CHECK(251, f_test_int(5) )
  CHECK(252, f_test_int2int(6, &(x)) )
  CHECK(253, f_test_many(7, 8, &(x), &(x)) )
  CHECK(259, f_test_int2int(9, &(tmp)) )
  CHECK(259, f_test_int(tmp) )
  CHECK(260, f_test_many(11, 12, &(x), &(aux_Int_0)) )
  CHECK(260, f_test_int2int(10, &(aux_Int_1)) )
  x = aux_Int_1 + aux_Int_0;
  CHECK(261, f_test_int2str(13, &(aux_String_1), &(aux_String_1_Refman)) )
  MR_owner_dec_ref(s_Refman);
  s_Refman = aux_String_1_Refman;
  aux_String_1_Refman = NULL;
  s = aux_String_1;
  aux_String_1 = NULL;
MR_cleanup:
  MR_owner_dec_ref(aux_String_1_Refman);
  MR_dec_ref(aux_String_0_Refman);
  MR_owner_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-code-flow"
Returncode test_code_flow(Array* arr, RefManager* arr_Refman, Int* res) {
  Returncode MR_err = OK;
  Int x = 0;
  Int y = 0;
  Int z = 0;
  Int w = 0;
  Array aux_Array_0_Var = {0};
  Array* aux_Array_0 = NULL;
  RefManager* aux_Array_0_Refman = NULL;
  MR_inc_ref(arr_Refman);
  if (arr == NULL || arr_Refman->value == NULL) RAISE(265)
  if ((4) < 0 || (4) >= (arr)->length) RAISE(265)
  if ((((Int*)((arr)->values))[4]) > 6) {
    *res = 6;
  }
  else {
    if (!(arr == NULL || arr_Refman->value == NULL)) {
      *res = 6;
    }
    else {
      if (arr == NULL || arr_Refman->value == NULL) RAISE(269)
      if ((4) < 0 || (4) >= (arr)->length) RAISE(269)
      if (arr == NULL || arr_Refman->value == NULL) RAISE(269)
      if ((4) < 0 || (4) >= (arr)->length) RAISE(269)
      if ((((Int*)((arr)->values))[4]) != (((Int*)((arr)->values))[4])) {
        *res = 6;
      }
      else {
        if (arr == NULL || arr_Refman->value == NULL) RAISE(271)
        if ((0) < 0 || (0) >= (arr)->length) RAISE(271)
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
    if (arr == NULL || arr_Refman->value == NULL) RAISE(276)
    if ((6) < 0 || (6) >= (arr)->length) RAISE(276)
    ((Int*)((arr)->values))[6] = 6;
    if (arr == NULL || arr_Refman->value == NULL) RAISE(277)
    if ((2) < 0 || (2) >= (arr)->length) RAISE(277)
    x = ((Int*)((arr)->values))[2];
    if (!((x > 3) && (arr == NULL))) break;
    y = x - 1;
    while (true) {
      if (arr == NULL || arr_Refman->value == NULL) RAISE(281)
      if ((8) < 0 || (8) >= (arr)->length) RAISE(281)
      if (arr == NULL || arr_Refman->value == NULL) RAISE(281)
      if ((4) < 0 || (4) >= (arr)->length) RAISE(281)
      ((Int*)((arr)->values))[4] = ((Int*)((arr)->values))[8];
      if (arr == NULL || arr_Refman->value == NULL) RAISE(282)
      if ((4) < 0 || (4) >= (arr)->length) RAISE(282)
      if (y > (((Int*)((arr)->values))[4])) {
        continue;
      }
      z = 7;
      if (arr == NULL || arr_Refman->value == NULL) RAISE(285)
      if ((4) < 0 || (4) >= (arr)->length) RAISE(285)
      if (z <= (((Int*)((arr)->values))[4])) {
        if (!(z > 0)) break;
      }
    }
  }
  if (arr == NULL || arr_Refman->value == NULL) RAISE(287)
  if ((2) < 0 || (2) >= (arr)->length) RAISE(287)
  if (arr == NULL || arr_Refman->value == NULL) RAISE(287)
  if ((2) < 0 || (2) >= (arr)->length) RAISE(287)
  {int n; for(n=((Int*)((arr)->values))[2]; n<2 - (3 * (((Int*)((arr)->values))[2])); ++n) {
    if (arr == NULL || arr_Refman->value == NULL) RAISE(288)
    if ((2) < 0 || (2) >= (arr)->length) RAISE(288)
    if (arr == NULL || arr_Refman->value == NULL) RAISE(288)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(288)
    ((Int*)((arr)->values))[0] = ((Int*)((arr)->values))[2];
    if (arr == NULL || arr_Refman->value == NULL) RAISE(289)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(289)
    w = ((Int*)((arr)->values))[0];
    aux_Array_0 = &aux_Array_0_Var;
    aux_Array_0_Refman = MR_new_ref(aux_Array_0);
    if (aux_Array_0_Refman == NULL) RAISE(290)
    aux_Array_0_Var.length = 2;
    aux_Array_0_Var.values = (Byte*)((arr)->values) + (3);
    if (arr == NULL || arr_Refman->value == NULL) RAISE(290)
    if ((3) < 0 || (2) < 0 || (3) + (2) > (arr)->length) RAISE(290)
    if ((w > 4) && (arr != aux_Array_0)) {
      if (arr == NULL || arr_Refman->value == NULL) RAISE(291)
      if ((1) < 0 || (1) >= (arr)->length) RAISE(291)
      ((Int*)((arr)->values))[1] = w;
    }
  }
  }
MR_cleanup:
  MR_dec_ref(aux_Array_0_Refman);
  MR_dec_ref(arr_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-builtins"
Returncode test_builtins(Int i, Char c, Bool b, String* s, RefManager* s_Refman, Array* a, RefManager* a_Refman) {
  Returncode MR_err = OK;
  Int iv = 0;
  Char cv = 0;
  Bool bv = 0;
  File* f = NULL;
  RefManager* f_Refman = NULL;
  MR_inc_ref(s_Refman);
  MR_inc_ref(a_Refman);
  CHECK(299, Int_str(i, s, s_Refman) )
  bv = true || false;
  if (a == NULL || a_Refman->value == NULL) RAISE(301)
  i = a->length;
  if (s == NULL || s_Refman->value == NULL) RAISE(302)
  i = s->length;
  CHECK(303, String_clear(s, s_Refman) )
  CHECK(304, String_equal(s, s_Refman, s, s_Refman, &(bv)) )
  CHECK(305, String_get(s, s_Refman, i, &(cv)) )
  CHECK(306, String_append(s, s_Refman, c) )
  CHECK(307, String_new(s, s_Refman, s, s_Refman) )
  CHECK(308, String_concat(s, s_Refman, s, s_Refman) )
  CHECK(309, String_concat_int(s, s_Refman, i) )
  CHECK(310, String_find(s, s_Refman, s, s_Refman, &(iv)) )
  CHECK(311, String_has(s, s_Refman, c, &(bv)) )
  CHECK(313, file_open_read(s, s_Refman, &(f), &(f_Refman)) )
  CHECK(314, file_open_write(s, s_Refman, &(f), &(f_Refman)) )
  CHECK(315, File_getc(f, f_Refman, &(cv), &(bv)) )
  CHECK(316, File_putc(f, f_Refman, c) )
  CHECK(317, File_write(f, f_Refman, s, s_Refman) )
  CHECK(318, File_close(f, f_Refman) )
  if (sys == NULL || sys_Refman->value == NULL) RAISE(319)
  if (sys->argv == NULL || sys->argv_Refman->value == NULL) RAISE(319)
  if ((1) < 0 || (1) >= (sys->argv)->length) RAISE(319)
  MR_dec_ref(s_Refman);
  s_Refman = sys->argv_Refman;
  MR_inc_ref(s_Refman);
  s = ((String**)((sys->argv)->values))[1];
  CHECK(320, Sys_print(sys, sys_Refman, s, s_Refman) )
  CHECK(321, Sys_println(sys, sys_Refman, s, s_Refman) )
  CHECK(322, Sys_getchar(sys, sys_Refman, &(cv), &(bv)) )
  CHECK(323, Sys_getline(sys, sys_Refman, s, s_Refman) )
  CHECK(324, Sys_getenv(sys, sys_Refman, s, s_Refman, s, s_Refman, &(bv)) )
  CHECK(325, Sys_system(sys, sys_Refman, s, s_Refman, &(iv)) )
  CHECK(326, Sys_exit(sys, sys_Refman, i) )
  CHECK(327, File_putc(stdout, stdout_Refman, c) )
  CHECK(328, File_getc(stdin, stdin_Refman, &(cv), &(bv)) )
  CHECK(329, File_putc(stderr, stderr_Refman, c) )
MR_cleanup:
  MR_owner_dec_ref(f_Refman);
  MR_dec_ref(a_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-ref-count"
Returncode test_ref_count(void) {
  Returncode MR_err = OK;
  String* s = NULL;
  RefManager* s_Refman = NULL;
  String* s_user = NULL;
  RefManager* s_user_Refman = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  RefManager* aux_String_0_Refman = NULL;
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  RefManager* aux_String_1_Refman = NULL;
  String aux_String_2_Var = {0};
  String* aux_String_2 = NULL;
  RefManager* aux_String_2_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(333)
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "test string";
  s = MR_new_string(32);
  if (s == NULL) RAISE(333)
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(333)
  CHECK(333, String_new(s, s_Refman, aux_String_0, aux_String_0_Refman) )
  s_user = s;
  s_user_Refman = s_Refman;
  MR_inc_ref(s_user_Refman);
  CHECK(335, Sys_println(sys, sys_Refman, s, s_Refman) )
  CHECK(336, Sys_println(sys, sys_Refman, s_user, s_user_Refman) )
  CHECK(337, f_remove(s, s_Refman) )
  s = NULL;
  s_Refman = NULL;
  if (! (!(s == NULL || s_Refman->value == NULL))) {
    aux_String_1 = &aux_String_1_Var;
    aux_String_1_Refman = MR_new_ref(aux_String_1);
    if (aux_String_1_Refman == NULL) RAISE(339)
    aux_String_1_Var.max_length = 17;
    aux_String_1_Var.length = 16;
    aux_String_1_Var.values = "ownership passed";
    CHECK(339, Sys_println(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
  }
  if (! (!(s_user == NULL || s_user_Refman->value == NULL))) {
    aux_String_2 = &aux_String_2_Var;
    aux_String_2_Refman = MR_new_ref(aux_String_2);
    if (aux_String_2_Refman == NULL) RAISE(341)
    aux_String_2_Var.max_length = 15;
    aux_String_2_Var.length = 14;
    aux_String_2_Var.values = "string deleted";
    CHECK(341, Sys_println(sys, sys_Refman, aux_String_2, aux_String_2_Refman) )
  }
MR_cleanup:
  MR_dec_ref(aux_String_2_Refman);
  MR_dec_ref(aux_String_1_Refman);
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(s_user_Refman);
  MR_owner_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-remove"
Returncode f_remove(String* s, RefManager* s_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(s_Refman);
MR_cleanup:
  MR_owner_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-type-parameters"
Returncode test_type_parameters(String* s, RefManager* s_Refman) {
  Returncode MR_err = OK;
  Data d_Var = {0};
  Data* d = NULL;
  RefManager* d_Refman = NULL;
  char sarr_Chars[6 * 16];
  String sarr_Values[6];
  Array sarr_Var = {6, NULL};
  Array* sarr = NULL;
  RefManager* sarr_Refman = NULL;
  Data ad_Values[5];
  Array ad_Var = {5, NULL};
  Array* ad = NULL;
  RefManager* ad_Refman = NULL;
  Data da_Var = {0};
  Data* da = NULL;
  RefManager* da_Refman = NULL;
  Data dr_Var = {0};
  Data* dr = NULL;
  RefManager* dr_Refman = NULL;
  Data* dg = NULL;
  RefManager* dg_Refman = NULL;
  MR_inc_ref(s_Refman);
  d = &d_Var;
  d_Refman = MR_new_ref(d);
  if (d_Refman == NULL) RAISE(364)
  sarr = &sarr_Var;
  sarr_Var.values = sarr_Values;
  MR_set_var_string_array(6, 16, sarr, sarr_Chars);
  sarr_Refman = MR_new_ref(sarr);
  if (sarr_Refman == NULL) RAISE(365)
  if (d == NULL || d_Refman->value == NULL) RAISE(366)
  MR_dec_ref(d->item_Refman);
  d->item_Refman = s_Refman;
  MR_inc_ref(d->item_Refman);
  d->item = s;
  if (d == NULL || d_Refman->value == NULL) RAISE(367)
  MR_dec_ref(s_Refman);
  s_Refman = d->item_Refman;
  MR_inc_ref(s_Refman);
  s = d->item;
  if (d == NULL || d_Refman->value == NULL) RAISE(368)
  MR_dec_ref(d->arr_Refman);
  d->arr_Refman = sarr_Refman;
  MR_inc_ref(d->arr_Refman);
  d->arr = sarr;
  if (d == NULL || d_Refman->value == NULL) RAISE(369)
  if (d->arr == NULL || d->arr_Refman->value == NULL) RAISE(369)
  if ((4) < 0 || (4) >= (d->arr)->length) RAISE(369)
  MR_dec_ref(s_Refman);
  s_Refman = d->arr_Refman;
  MR_inc_ref(s_Refman);
  s = ((String**)((d->arr)->values))[4];
  ad = &ad_Var;
  ad_Var.values = ad_Values;
  ad_Refman = MR_new_ref(ad);
  if (ad_Refman == NULL) RAISE(370)
  if (ad == NULL || ad_Refman->value == NULL) RAISE(371)
  if ((2) < 0 || (2) >= (ad)->length) RAISE(371)
  if (((Data**)((ad)->values))[2] == NULL || ad_Refman->value == NULL) RAISE(371)
  MR_dec_ref(s_Refman);
  s_Refman = (((Data**)((ad)->values))[2])->item_Refman;
  MR_inc_ref(s_Refman);
  s = (((Data**)((ad)->values))[2])->item;
  if (ad == NULL || ad_Refman->value == NULL) RAISE(372)
  if ((2) < 0 || (2) >= (ad)->length) RAISE(372)
  if (((Data**)((ad)->values))[2] == NULL || ad_Refman->value == NULL) RAISE(372)
  if ((((Data**)((ad)->values))[2])->arr == NULL || (((Data**)((ad)->values))[2])->arr_Refman->value == NULL) RAISE(372)
  if ((3) < 0 || (3) >= ((((Data**)((ad)->values))[2])->arr)->length) RAISE(372)
  MR_dec_ref(s_Refman);
  s_Refman = (((Data**)((ad)->values))[2])->arr_Refman;
  MR_inc_ref(s_Refman);
  s = ((String**)(((((Data**)((ad)->values))[2])->arr)->values))[3];
  da = &da_Var;
  da_Refman = MR_new_ref(da);
  if (da_Refman == NULL) RAISE(373)
  if (da == NULL || da_Refman->value == NULL) RAISE(374)
  if (da->item == NULL || da->item_Refman->value == NULL) RAISE(374)
  if ((1) < 0 || (1) >= (((Array*)(da->item)))->length) RAISE(374)
  MR_dec_ref(s_Refman);
  s_Refman = da->item_Refman;
  MR_inc_ref(s_Refman);
  s = ((String**)((((Array*)(da->item)))->values))[1];
  dr = &dr_Var;
  dr_Refman = MR_new_ref(dr);
  if (dr_Refman == NULL) RAISE(375)
  if (dr == NULL || dr_Refman->value == NULL) RAISE(376)
  if (dr->item == NULL || dr->item_Refman->value == NULL) RAISE(376)
  if (((Data*)(dr->item))->item == NULL || ((Data*)(dr->item))->item_Refman->value == NULL) RAISE(376)
  MR_dec_ref(s_Refman);
  s_Refman = ((Data*)(((Data*)(dr->item))->item))->item_Refman;
  MR_inc_ref(s_Refman);
  s = ((Data*)(((Data*)(dr->item))->item))->item;
  CHECK(377, Data_set(d, d_Refman, s, s_Refman, sarr, sarr_Refman) )
  if (s != NULL) RAISE(378)
  CHECK(378, Data_get(d, d_Refman, (void*)&(s), &(s_Refman)) )
  dg = d;
  dg_Refman = d_Refman;
  MR_inc_ref(dg_Refman);
  TEST_ASSERT(380, !(dg == NULL || dg_Refman->value == NULL))
MR_cleanup:
  MR_dec_ref(dg_Refman);
  MR_dec_ref(dr_Refman);
  MR_dec_ref(da_Refman);
  MR_dec_ref(ad_Refman);
  MR_dec_ref(sarr_Refman);
  MR_dec_ref(d_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME


/* main function */

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "main"
USER_MAIN_HEADER {
  Returncode MR_err = OK;
  CHECK(384, test_simple_function() )
  CHECK(385, test_ref_count() )
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

MAIN_FUNC
