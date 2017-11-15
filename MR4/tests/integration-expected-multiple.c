#include "mr.4.h"


/* types declaration */

typedef struct TestStruct TestStruct;

typedef struct TestClass TestClass;

typedef struct TestClass_Dynamic TestClass_Dynamic;

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
  TestStruct* ts;
  Returncode (*fun)(void);
};

struct TestClass {
  Int num;
  String* text;
};

struct TestClass_Dynamic {
  Returncode (*dynamic_meth)(TestClass* self, TestClass_Dynamic* self_Dynamic);
};

struct BaseType {
  Int num_base;
  MiddleType* base_mid_ref;
  MiddleType_Dynamic* base_mid_ref_Dynamic;
  TopType* base_top_ref;
  TopType_Dynamic* base_top_ref_Dynamic;
};

struct BaseType_Dynamic {
  Returncode (*meth0)(BaseType* self, BaseType_Dynamic* self_Dynamic);
  Returncode (*meth1)(BaseType* self, BaseType_Dynamic* self_Dynamic, Int n, String* s);
  Returncode (*meth2)(BaseType* self, BaseType_Dynamic* self_Dynamic);
  Returncode (*meth3)(BaseType* self, BaseType_Dynamic* self_Dynamic, Int n, String* s);
};

struct MiddleType {
  BaseType _base;
  Int num_mid;
  BaseType* mid_base_ref;
  BaseType_Dynamic* mid_base_ref_Dynamic;
  TopType* mid_top_ref;
  TopType_Dynamic* mid_top_ref_Dynamic;
};

struct MiddleType_Dynamic {
  BaseType_Dynamic _base;
  Returncode (*meth4)(MiddleType* self, MiddleType_Dynamic* self_Dynamic);
  Returncode (*meth5)(MiddleType* self, MiddleType_Dynamic* self_Dynamic, Int n, String* s);
};

struct TopType {
  MiddleType _base;
  Int num_top;
  BaseType* top_base_ref;
  BaseType_Dynamic* top_base_ref_Dynamic;
  MiddleType* top_mid_ref;
  MiddleType_Dynamic* top_mid_ref_Dynamic;
};

struct TopType_Dynamic {
  MiddleType_Dynamic _base;
  Returncode (*meth6)(TopType* self, TopType_Dynamic* self_Dynamic);
};


/* types methods declaration */

Returncode TestStruct_new(TestStruct* self, Int x, String* s);

Returncode TestStruct_get(TestStruct* self, Int* x, String** s);

Returncode TestStruct_print(TestStruct* self);

Returncode TestClass_new(TestClass* self, TestClass_Dynamic* self_Dynamic);

Returncode TestClass_static_meth(TestClass* self, TestClass_Dynamic* self_Dynamic);

Returncode TestClass_dynamic_meth(TestClass* self, TestClass_Dynamic* self_Dynamic);

Returncode TestClass_print(TestClass* self, TestClass_Dynamic* self_Dynamic);

Returncode BaseType_new(BaseType* self, BaseType_Dynamic* self_Dynamic);

Returncode BaseType_meth0(BaseType* self, BaseType_Dynamic* self_Dynamic);

Returncode BaseType_meth1(BaseType* self, BaseType_Dynamic* self_Dynamic, Int n, String* s);

Returncode BaseType_meth2(BaseType* self, BaseType_Dynamic* self_Dynamic);

Returncode BaseType_meth3(BaseType* self, BaseType_Dynamic* self_Dynamic, Int n, String* s);

Returncode MiddleType_new(MiddleType* self, MiddleType_Dynamic* self_Dynamic);

Returncode MiddleType_meth1(MiddleType* self, MiddleType_Dynamic* self_Dynamic, Int n, String* s);

Returncode MiddleType_meth2(MiddleType* self, MiddleType_Dynamic* self_Dynamic);

Returncode MiddleType_meth4(MiddleType* self, MiddleType_Dynamic* self_Dynamic);

Returncode MiddleType_meth5(MiddleType* self, MiddleType_Dynamic* self_Dynamic, Int n, String* s);

Returncode TopType_new(TopType* self, TopType_Dynamic* self_Dynamic);

Returncode TopType_meth2(TopType* self, TopType_Dynamic* self_Dynamic);

Returncode TopType_meth3(TopType* self, TopType_Dynamic* self_Dynamic, Int n, String* s);

Returncode TopType_meth5(TopType* self, TopType_Dynamic* self_Dynamic, Int n, String* s);

Returncode TopType_meth6(TopType* self, TopType_Dynamic* self_Dynamic);


/* types global variables */

TestClass_Dynamic TestClass_dynamic = {TestClass_dynamic_meth};

BaseType_Dynamic BaseType_dynamic = {BaseType_meth0, BaseType_meth1, BaseType_meth2, BaseType_meth3};

MiddleType_Dynamic MiddleType_dynamic = {{BaseType_meth0, (Func)MiddleType_meth1, (Func)MiddleType_meth2, BaseType_meth3}, MiddleType_meth4, MiddleType_meth5};

TopType_Dynamic TopType_dynamic = {{{BaseType_meth0, (Func)MiddleType_meth1, (Func)TopType_meth2, (Func)TopType_meth3}, MiddleType_meth4, (Func)TopType_meth5}, TopType_meth6};


/* global variables */

Int global_int;

String* global_string;


/* global functions declaration */

Returncode test_simple_function(void);

Returncode test_const_expression(Int* i, Char* c, String** s, TestStruct** t, TestClass** d, TestClass_Dynamic** d_Dynamic, Returncode (**f)(void));

Returncode test_member_expression(TestStruct* t, TestStruct** to, Int* i);

Returncode test_slice_expression(String* s, Array* arri, Array* arrs, Array* arrt, Array* arrd, Array* arrf, Char* c, Int* i, TestStruct** t, TestClass** d, TestClass_Dynamic** d_Dynamic, Returncode (**f)(void));

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

Returncode test_mid_out(MiddleType** mt, MiddleType_Dynamic** mt_Dynamic);

Returncode TestStruct_Mock_get(TestStruct* self, Int* x, String** s);

Returncode Mock_f_test_int2str(Int x, String** s);

Returncode test_func(void);

Returncode test_another(void);


/* types methods body */

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestStruct.new"
Returncode TestStruct_new(TestStruct* self, Int x, String* s) {
  TestStruct* aux_TestStruct_0 = NULL;
  if (self == NULL) RAISE(189)
  self->num = x;
  if (self == NULL) RAISE(190)
  self->text = s;
  aux_TestStruct_0 = calloc(1, sizeof(TestStruct));
  if (aux_TestStruct_0 == NULL) RAISE(191)
  CHECK(191, TestStruct_new(aux_TestStruct_0, x + 1, s) )
  if (self == NULL) RAISE(191)
  self->ts = aux_TestStruct_0;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestStruct.get"
Returncode TestStruct_get(TestStruct* self, Int* x, String** s) {
  if (self == NULL) RAISE(198)
  *x = self->num;
  if (self == NULL) RAISE(199)
  *s = self->text;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestStruct.print"
Returncode TestStruct_print(TestStruct* self) {
  if (self == NULL) RAISE(202)
  CHECK(202, Sys_println(sys, self->text) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestClass.new"
Returncode TestClass_new(TestClass* self, TestClass_Dynamic* self_Dynamic) {
  if (self == NULL) RAISE(210)
  self->num = 1;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestClass.static-meth"
Returncode TestClass_static_meth(TestClass* self, TestClass_Dynamic* self_Dynamic) {
  if (self == NULL) RAISE(213)
  self->num = 3;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestClass.dynamic-meth"
Returncode TestClass_dynamic_meth(TestClass* self, TestClass_Dynamic* self_Dynamic) {
  if (self == NULL) RAISE(216)
  self->num = 6;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestClass.print"
Returncode TestClass_print(TestClass* self, TestClass_Dynamic* self_Dynamic) {
  if (self == NULL) RAISE(219)
  CHECK(219, Sys_println(sys, self->text) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "BaseType.new"
Returncode BaseType_new(BaseType* self, BaseType_Dynamic* self_Dynamic) {
  if (self == NULL) RAISE(49)
  self->num_base = 1;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "BaseType.meth0"
Returncode BaseType_meth0(BaseType* self, BaseType_Dynamic* self_Dynamic) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  aux_String_0->max_length = 15;
  aux_String_0->length = 14;
  aux_String_0->values = "BaseType.meth0";
  CHECK(52, Sys_println(sys, aux_String_0) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "BaseType.meth1"
Returncode BaseType_meth1(BaseType* self, BaseType_Dynamic* self_Dynamic, Int n, String* s) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  aux_String_0->max_length = 15;
  aux_String_0->length = 14;
  aux_String_0->values = "BaseType.meth1";
  CHECK(55, Sys_println(sys, aux_String_0) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "BaseType.meth2"
Returncode BaseType_meth2(BaseType* self, BaseType_Dynamic* self_Dynamic) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  aux_String_0->max_length = 15;
  aux_String_0->length = 14;
  aux_String_0->values = "BaseType.meth2";
  CHECK(58, Sys_println(sys, aux_String_0) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "BaseType.meth3"
Returncode BaseType_meth3(BaseType* self, BaseType_Dynamic* self_Dynamic, Int n, String* s) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  aux_String_0->max_length = 15;
  aux_String_0->length = 14;
  aux_String_0->values = "BaseType.meth3";
  CHECK(61, Sys_println(sys, aux_String_0) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test2.4.mr"
#define MR_FUNC_NAME "MiddleType.new"
Returncode MiddleType_new(MiddleType* self, MiddleType_Dynamic* self_Dynamic) {
  CHECK(13, BaseType_new(&(self->_base), &(self_Dynamic->_base)) )
  if (self == NULL) RAISE(14)
  self->num_mid = 2;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test2.4.mr"
#define MR_FUNC_NAME "MiddleType.meth1"
Returncode MiddleType_meth1(MiddleType* self, MiddleType_Dynamic* self_Dynamic, Int n, String* s) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  aux_String_0->max_length = 17;
  aux_String_0->length = 16;
  aux_String_0->values = "MiddleType.meth1";
  CHECK(17, Sys_println(sys, aux_String_0) )
  CHECK(18, BaseType_meth1(&(self->_base), &(self_Dynamic->_base), n, s) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test2.4.mr"
#define MR_FUNC_NAME "MiddleType.meth2"
Returncode MiddleType_meth2(MiddleType* self, MiddleType_Dynamic* self_Dynamic) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  aux_String_0->max_length = 17;
  aux_String_0->length = 16;
  aux_String_0->values = "MiddleType.meth2";
  CHECK(21, Sys_println(sys, aux_String_0) )
  CHECK(22, BaseType_meth2(&(self->_base), &(self_Dynamic->_base)) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test2.4.mr"
#define MR_FUNC_NAME "MiddleType.meth4"
Returncode MiddleType_meth4(MiddleType* self, MiddleType_Dynamic* self_Dynamic) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  aux_String_0->max_length = 17;
  aux_String_0->length = 16;
  aux_String_0->values = "MiddleType.meth4";
  CHECK(25, Sys_println(sys, aux_String_0) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test2.4.mr"
#define MR_FUNC_NAME "MiddleType.meth5"
Returncode MiddleType_meth5(MiddleType* self, MiddleType_Dynamic* self_Dynamic, Int n, String* s) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  aux_String_0->max_length = 17;
  aux_String_0->length = 16;
  aux_String_0->values = "MiddleType.meth5";
  CHECK(28, Sys_println(sys, aux_String_0) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TopType.new"
Returncode TopType_new(TopType* self, TopType_Dynamic* self_Dynamic) {
  CHECK(13, MiddleType_new(&(self->_base), &(self_Dynamic->_base)) )
  if (self == NULL) RAISE(14)
  self->num_top = 3;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TopType.meth2"
Returncode TopType_meth2(TopType* self, TopType_Dynamic* self_Dynamic) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  aux_String_0->max_length = 14;
  aux_String_0->length = 13;
  aux_String_0->values = "TopType.meth2";
  CHECK(18, Sys_println(sys, aux_String_0) )
  CHECK(19, MiddleType_meth2(&(self->_base), &(self_Dynamic->_base)) )
  CHECK(20, MiddleType_meth2(&(self->_base), &(self_Dynamic->_base)) )
  CHECK(21, BaseType_meth2(&(self->_base._base), &(self_Dynamic->_base._base)) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TopType.meth3"
Returncode TopType_meth3(TopType* self, TopType_Dynamic* self_Dynamic, Int n, String* s) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  aux_String_0->max_length = 14;
  aux_String_0->length = 13;
  aux_String_0->values = "TopType.meth3";
  CHECK(24, Sys_println(sys, aux_String_0) )
  CHECK(25, BaseType_meth3(&(self->_base._base), &(self_Dynamic->_base._base), n, s) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TopType.meth5"
Returncode TopType_meth5(TopType* self, TopType_Dynamic* self_Dynamic, Int n, String* s) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  aux_String_0->max_length = 14;
  aux_String_0->length = 13;
  aux_String_0->values = "TopType.meth5";
  CHECK(28, Sys_println(sys, aux_String_0) )
  CHECK(29, MiddleType_meth5(&(self->_base), &(self_Dynamic->_base), n, s) )
  CHECK(30, MiddleType_meth1(NULL, NULL, n, s) )
  CHECK(31, BaseType_meth1(NULL, NULL, n, s) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TopType.meth6"
Returncode TopType_meth6(TopType* self, TopType_Dynamic* self_Dynamic) {
  MiddleType* mt = NULL;
  MiddleType_Dynamic* mt_Dynamic = NULL;
  BaseType* bt = NULL;
  BaseType_Dynamic* bt_Dynamic = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  aux_String_0->max_length = 14;
  aux_String_0->length = 13;
  aux_String_0->values = "TopType.meth6";
  CHECK(34, Sys_println(sys, aux_String_0) )
  if (self == NULL) RAISE(35)
  if (self == NULL) RAISE(35)
  self->_base.num_mid = self->_base._base.num_base;
  if (self == NULL) RAISE(36)
  if (self == NULL) RAISE(36)
  self->top_base_ref_Dynamic = &(self->top_mid_ref_Dynamic->_base);
  self->top_base_ref = &(self->top_mid_ref->_base);
  if (self == NULL) RAISE(37)
  self->top_base_ref_Dynamic = &(self_Dynamic->_base._base);
  self->top_base_ref = &(self->_base._base);
  mt = &(self->_base);
  mt_Dynamic = &(self_Dynamic->_base);
  bt = &(mt->_base);
  bt_Dynamic = &(mt_Dynamic->_base);
  if (bt != NULL) RAISE(40)
  CHECK(40, test_mid_out((void*)&(bt), (void*)&(bt_Dynamic)) )
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
Returncode test_const_expression(Int* i, Char* c, String** s, TestStruct** t, TestClass** d, TestClass_Dynamic** d_Dynamic, Returncode (**f)(void)) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  *i = (((((((0 + 9630) + -9630) + 07520) + -07520) + 0xfda940) + -0xfda940) + 0xFDA940) + -0xFDA940;
  *c = (((('a' + '\'') + '\n') + '\x0f') + '\xA9') + '\270';
  aux_String_0->max_length = 12;
  aux_String_0->length = 11;
  aux_String_0->values = "some string";
  *s = aux_String_0;
  *t = NULL;
  *d_Dynamic = NULL;
  *d = NULL;
  *f = NULL;
  if (*f == NULL) RAISE(43)
  CHECK(43, (*f)() )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-member-expression"
Returncode test_member_expression(TestStruct* t, TestStruct** to, Int* i) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  if (t == NULL) RAISE(47)
  if (t->ts == NULL) RAISE(47)
  if (t->ts->ts == NULL) RAISE(47)
  if (t == NULL) RAISE(47)
  if (t->ts == NULL) RAISE(47)
  if ((*to) == NULL) RAISE(47)
  if (t == NULL) RAISE(47)
  t->num = ((*to)->num + t->ts->num) + t->ts->ts->num;
  if (t == NULL) RAISE(48)
  if ((*to) == NULL) RAISE(48)
  (*to)->num = t->num;
  if (t == NULL) RAISE(49)
  if (t->ts == NULL) RAISE(49)
  if (t->ts->ts == NULL) RAISE(49)
  t->ts->ts->num = 4;
  if (t == NULL) RAISE(50)
  t->fun = f_test_void;
  if (t == NULL) RAISE(51)
  if (t->fun == NULL) RAISE(51)
  CHECK(51, t->fun() )
  aux_String_0->max_length = 1;
  aux_String_0->length = 0;
  aux_String_0->values = "";
  CHECK(52, TestStruct_new(t, 0, aux_String_0) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-slice-expression"
Returncode test_slice_expression(String* s, Array* arri, Array* arrs, Array* arrt, Array* arrd, Array* arrf, Char* c, Int* i, TestStruct** t, TestClass** d, TestClass_Dynamic** d_Dynamic, Returncode (**f)(void)) {
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
  Array aux_Array_9_Var = {0};
  Array* aux_Array_9 = &aux_Array_9_Var;
  aux_Array_0_Var.length = 2;
  aux_Array_0_Var.values = (Byte*)((arrs)->values) + (4);
  if ((4) < 0 || (2) < 0 || (4) + (2) > (arrs)->length) RAISE(67)
  if ((4) < 0 || (4) >= (aux_Array_0)->length) RAISE(67)
  aux_String_0_Var.length = 3;
  aux_String_0_Var.max_length = aux_String_0_Var.length + 1;
  aux_String_0_Var.values = ((((String**)((aux_Array_0)->values))[4]))->values + (1);
  if ((1) < 0 || (3) < 0 || (1) + (3) > ((((String**)((aux_Array_0)->values))[4]))->length) RAISE(67)
  if ((0) < 0 || (0) >= (aux_String_0)->length) RAISE(67)
  if ((3) < 0 || (3) >= (arrs)->length) RAISE(67)
  if ((2) < 0 || (2) >= ((((String**)((arrs)->values))[3]))->length) RAISE(67)
  aux_String_1_Var.length = 7;
  aux_String_1_Var.max_length = aux_String_1_Var.length + 1;
  aux_String_1_Var.values = (s)->values + (4);
  if ((4) < 0 || (7) < 0 || (4) + (7) > (s)->length) RAISE(67)
  if ((2) < 0 || (2) >= (aux_String_1)->length) RAISE(67)
  if ((2) < 0 || (2) >= (s)->length) RAISE(67)
  *c = (((((s)->values)[2]) + (((aux_String_1)->values)[2])) + ((((((String**)((arrs)->values))[3]))->values)[2])) + (((aux_String_0)->values)[0]);
  aux_Array_1_Var.length = 4;
  aux_Array_1_Var.values = (Byte*)((arri)->values) + (2);
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arri)->length) RAISE(69)
  aux_Array_2_Var.length = 2;
  aux_Array_2_Var.values = (Byte*)((aux_Array_1)->values) + (1);
  if ((1) < 0 || (2) < 0 || (1) + (2) > (aux_Array_1)->length) RAISE(69)
  if ((1) < 0 || (1) >= (aux_Array_2)->length) RAISE(69)
  aux_Array_3_Var.length = 4;
  aux_Array_3_Var.values = (Byte*)((arrt)->values) + (2);
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arrt)->length) RAISE(68)
  if ((1) < 0 || (1) >= (aux_Array_3)->length) RAISE(68)
  if ((((TestStruct**)((aux_Array_3)->values))[1]) == NULL) RAISE(68)
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(68)
  if ((((TestStruct**)((arrt)->values))[4]) == NULL) RAISE(68)
  if ((2) < 0 || (2) >= (arri)->length) RAISE(68)
  if ((((*i) + 3) - (((Int*)((arri)->values))[2])) < 0 || (((*i) + 3) - (((Int*)((arri)->values))[2])) >= (arri)->length) RAISE(68)
  *i = (((((Int*)((arri)->values))[((*i) + 3) - (((Int*)((arri)->values))[2])]) + (((TestStruct**)((arrt)->values))[4])->num) + (((TestStruct**)((aux_Array_3)->values))[1])->num) + (((Int*)((aux_Array_2)->values))[1]);
  aux_Array_4_Var.length = 4;
  aux_Array_4_Var.values = (Byte*)((arri)->values) + (2);
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arri)->length) RAISE(70)
  if ((1) < 0 || (1) >= (aux_Array_4)->length) RAISE(70)
  aux_Array_5_Var.length = 5 * ((*i) - 1);
  aux_Array_5_Var.values = (Byte*)((arri)->values) + ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1]));
  if (((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1])) < 0 || (5 * ((*i) - 1)) < 0 || ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1])) + (5 * ((*i) - 1)) > (arri)->length) RAISE(70)
  arri = aux_Array_5;
  if ((4) < 0 || (4) >= (arrs)->length) RAISE(71)
  s = ((String**)((arrs)->values))[4];
  aux_Array_6_Var.length = 7;
  aux_Array_6_Var.values = (Byte*)((arrs)->values) + (2);
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrs)->length) RAISE(72)
  arrs = aux_Array_6;
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(73)
  *t = ((TestStruct**)((arrt)->values))[4];
  aux_Array_7_Var.length = 7;
  aux_Array_7_Var.values = (Byte*)((arrt)->values) + (2);
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrt)->length) RAISE(74)
  arrt = aux_Array_7;
  if ((4) < 0 || (4) >= (arrd)->length) RAISE(75)
  *d_Dynamic = &TestClass_dynamic;
  *d = ((TestClass**)((arrd)->values))[4];
  aux_Array_8_Var.length = 7;
  aux_Array_8_Var.values = (Byte*)((arrd)->values) + (2);
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrd)->length) RAISE(76)
  arrd = aux_Array_8;
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(77)
  *f = ((Returncode (**)(void))((arrf)->values))[4];
  aux_Array_9_Var.length = 7;
  aux_Array_9_Var.values = (Byte*)((arrf)->values) + (2);
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrf)->length) RAISE(78)
  arrf = aux_Array_9;
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(79)
  if (((Returncode (**)(void))((arrf)->values))[4] == NULL) RAISE(79)
  CHECK(79, (((Returncode (**)(void))((arrf)->values))[4])() )
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
  TestClass* d = NULL;
  TestClass_Dynamic* d_Dynamic = NULL;
  TestStruct tv_Var = {0};
  TestStruct* tv = &tv_Var;
  TestClass dv_Var = {0};
  TestClass* dv = &dv_Var;
  TestClass_Dynamic* dv_Dynamic = &TestClass_dynamic;
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
  TestClass da_Values[12];
  Array da_Var = {12, NULL};
  Array* da = &da_Var;
  char sa_Chars[12 * 7];
  String sa_Values[12];
  Array sa_Var = {12, NULL};
  Array* sa = &sa_Var;
  Returncode (*fa_Values[12])(void);
  Array fa_Var = {12, NULL};
  Array* fa = &fa_Var;
  TestStruct* tn = NULL;
  TestClass* dn = NULL;
  TestClass_Dynamic* dn_Dynamic = &TestClass_dynamic;
  String* sn = NULL;
  Array* ian = NULL;
  Array* tan = NULL;
  Array* dan = NULL;
  Array* san = NULL;
  Array* sfn = NULL;
  Int ix = 0;
  String* is = NULL;
  char isv_Values[12];
  String isv_Var = {12, 0, NULL};
  String* isv = &isv_Var;
  String* isn = NULL;
  Returncode (*fi)(Int x, String** s) = NULL;
  TestStruct itv_Var = {0};
  TestStruct* itv = &itv_Var;
  TestStruct* itn = NULL;
  TestClass idv_Var = {0};
  TestClass* idv = &idv_Var;
  TestClass_Dynamic* idv_Dynamic = &TestClass_dynamic;
  TestClass* idn = NULL;
  TestClass_Dynamic* idn_Dynamic = &TestClass_dynamic;
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  TestStruct* aux_TestStruct_0 = NULL;
  TestClass* aux_TestClass_0 = NULL;
  TestClass_Dynamic* aux_TestClass_0_Dynamic = &TestClass_dynamic;
  String* aux_String_1 = NULL;
  Array* aux_Array_0 = NULL;
  Array* aux_Array_1 = NULL;
  Array* aux_Array_2 = NULL;
  Array* aux_Array_3 = NULL;
  Array* aux_Array_4 = NULL;
  String* aux_String_2 = NULL;
  sv_Var.values = sv_Values;
  ia_Var.values = ia_Values;
  ta_Var.values = ta_Values;
  da_Var.values = da_Values;
  sa_Var.values = sa_Values;
  MR_set_var_string_array(12, 7, sa, sa_Chars);
  fa_Var.values = fa_Values;
  tn = calloc(1, sizeof(TestStruct));
  if (tn == NULL) RAISE(105)
  dn = calloc(1, sizeof(TestClass));
  if (dn == NULL) RAISE(106)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(107)
  sn = MR_new_string(((Int*)((arr)->values))[0]);
  if (sn == NULL) RAISE(107)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(108)
  ian = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if (ian == NULL) RAISE(108)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(109)
  tan = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestStruct));
  if (tan == NULL) RAISE(109)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(110)
  dan = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestClass));
  if (dan == NULL) RAISE(110)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(111)
  if ((1) < 0 || (1) >= (arr)->length) RAISE(111)
  san = MR_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]);
  if (san == NULL) RAISE(111)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(112)
  sfn = MR_new_array(((Int*)((arr)->values))[0], sizeof(Func));
  if (sfn == NULL) RAISE(112)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(113)
  ix = ((Int*)((arr)->values))[0];
  is = text;
  isv_Var.values = isv_Values;
  aux_String_0->max_length = 12;
  aux_String_0->length = 11;
  aux_String_0->values = "some string";
  CHECK(115, String_new(isv, aux_String_0) )
  isn = MR_new_string(i);
  if (isn == NULL) RAISE(116)
  CHECK(116, String_new(isn, text) )
  fi = Mock_f_test_int2str;
  CHECK(118, TestStruct_new(itv, i, text) )
  itn = calloc(1, sizeof(TestStruct));
  if (itn == NULL) RAISE(119)
  CHECK(119, TestStruct_new(itn, i, text) )
  CHECK(120, TestClass_new(idv, idv_Dynamic) )
  idn = calloc(1, sizeof(TestClass));
  if (idn == NULL) RAISE(121)
  CHECK(121, TestClass_new(idn, idn_Dynamic) )
  aux_TestStruct_0 = calloc(1, sizeof(TestStruct));
  if (aux_TestStruct_0 == NULL) RAISE(122)
  CHECK(122, TestStruct_new(aux_TestStruct_0, i, text) )
  CHECK(122, TestStruct_print(aux_TestStruct_0) )
  aux_TestClass_0 = calloc(1, sizeof(TestClass));
  if (aux_TestClass_0 == NULL) RAISE(123)
  CHECK(123, TestClass_new(aux_TestClass_0, aux_TestClass_0_Dynamic) )
  CHECK(123, TestClass_print(aux_TestClass_0, aux_TestClass_0_Dynamic) )
  if ((0) < 0 || (0) >= (arr)->length) RAISE(124)
  aux_String_1 = MR_new_string(((Int*)((arr)->values))[0]);
  if (aux_String_1 == NULL) RAISE(124)
  TEST_ASSERT(124, aux_String_1 != NULL)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(125)
  aux_Array_0 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if (aux_Array_0 == NULL) RAISE(125)
  TEST_ASSERT(125, aux_Array_0 != NULL)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(126)
  aux_Array_1 = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestStruct));
  if (aux_Array_1 == NULL) RAISE(126)
  TEST_ASSERT(126, aux_Array_1 != NULL)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(127)
  aux_Array_2 = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestClass));
  if (aux_Array_2 == NULL) RAISE(127)
  TEST_ASSERT(127, aux_Array_2 != NULL)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(128)
  if ((1) < 0 || (1) >= (arr)->length) RAISE(128)
  aux_Array_3 = MR_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]);
  if (aux_Array_3 == NULL) RAISE(128)
  TEST_ASSERT(128, aux_Array_3 != NULL)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(129)
  aux_Array_4 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Func));
  if (aux_Array_4 == NULL) RAISE(129)
  TEST_ASSERT(129, aux_Array_4 != NULL)
  TEST_ASSERT(130, x == 0)
  TEST_ASSERT(131, s != NULL)
  TEST_ASSERT(132, a != NULL)
  CHECK(133, TestStruct_print(t) )
  CHECK(134, TestClass_print(d, d_Dynamic) )
  TEST_ASSERT(135, f != NULL)
  CHECK(136, TestStruct_print(tv) )
  CHECK(137, TestClass_print(dv, dv_Dynamic) )
  TEST_ASSERT(138, sv != NULL)
  TEST_ASSERT(139, ia != NULL)
  TEST_ASSERT(140, ta != NULL)
  TEST_ASSERT(141, da != NULL)
  TEST_ASSERT(142, sa != NULL)
  TEST_ASSERT(143, fa != NULL)
  CHECK(144, TestStruct_print(tn) )
  CHECK(145, TestClass_print(dn, dn_Dynamic) )
  TEST_ASSERT(146, sn != NULL)
  TEST_ASSERT(147, ian != NULL)
  TEST_ASSERT(148, tan != NULL)
  TEST_ASSERT(149, dan != NULL)
  TEST_ASSERT(150, san != NULL)
  TEST_ASSERT(151, sfn != NULL)
  TEST_ASSERT(152, ix == 0)
  TEST_ASSERT(153, is != NULL)
  if (fi == NULL) RAISE(154)
  CHECK(154, fi(7, &(aux_String_2)) )
  TEST_ASSERT(155, isv != NULL)
  TEST_ASSERT(156, isn != NULL)
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
  RAISE(225)
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
  CHECK(240, f_test_void() )
  aux_String_0->max_length = 5;
  aux_String_0->length = 4;
  aux_String_0->values = "text";
  CHECK(241, f_test_params(3, aux_String_0, NULL) )
  CHECK(242, f_test_outs(&(s), &(x)) )
  CHECK(243, Mock_f_test_int2str(4, &(s)) )
  CHECK(244, f_test_int(5) )
  CHECK(245, f_test_int2int(6, &(x)) )
  CHECK(246, f_test_many(7, 8, &(x), &(x)) )
  CHECK(252, f_test_int2int(9, &(tmp)) )
  CHECK(252, f_test_int(tmp) )
  CHECK(253, f_test_many(11, 12, &(x), &(aux_Int_0)) )
  CHECK(253, f_test_int2int(10, &(aux_Int_1)) )
  x = aux_Int_1 + aux_Int_0;
  CHECK(254, Mock_f_test_int2str(13, &(aux_String_1)) )
  s = aux_String_1;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-code-flow"
Returncode test_code_flow(Array* arr, Int* res) {
  if ((4) < 0 || (4) >= (arr)->length) RAISE(258)
  if ((((Int*)((arr)->values))[4]) > 6) {
    *res = 6;
  }
  else {
    if (arr != NULL) {
      *res = 6;
    }
    else {
      if ((4) < 0 || (4) >= (arr)->length) RAISE(262)
      if ((4) < 0 || (4) >= (arr)->length) RAISE(262)
      if ((((Int*)((arr)->values))[4]) != (((Int*)((arr)->values))[4])) {
        *res = 6;
      }
      else {
        if ((0) < 0 || (0) >= (arr)->length) RAISE(264)
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
    if ((6) < 0 || (6) >= (arr)->length) RAISE(269)
    ((Int*)((arr)->values))[6] = 6;
    if ((2) < 0 || (2) >= (arr)->length) RAISE(270)
    x = ((Int*)((arr)->values))[2];
    if (!(x > 3)) break;
    y = x - 1;
    while (true) {
      Int z = 0;
      if ((8) < 0 || (8) >= (arr)->length) RAISE(274)
      if ((4) < 0 || (4) >= (arr)->length) RAISE(274)
      ((Int*)((arr)->values))[4] = ((Int*)((arr)->values))[8];
      if ((4) < 0 || (4) >= (arr)->length) RAISE(275)
      if (y > (((Int*)((arr)->values))[4])) {
        continue;
      }
      z = 7;
      if ((4) < 0 || (4) >= (arr)->length) RAISE(278)
      if (z <= (((Int*)((arr)->values))[4])) {
        if (!(z > 0)) break;
      }
    }
  }
  if ((2) < 0 || (2) >= (arr)->length) RAISE(280)
  if ((2) < 0 || (2) >= (arr)->length) RAISE(280)
  {int n; for(n=((Int*)((arr)->values))[2]; n<2 - (3 * (((Int*)((arr)->values))[2])); ++n) {
    Int x = 0;
    if ((2) < 0 || (2) >= (arr)->length) RAISE(281)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(281)
    ((Int*)((arr)->values))[0] = ((Int*)((arr)->values))[2];
    if ((0) < 0 || (0) >= (arr)->length) RAISE(282)
    x = ((Int*)((arr)->values))[0];
    if (x > 4) {
      if ((1) < 0 || (1) >= (arr)->length) RAISE(284)
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
  CHECK(289, Int_str(i, s) )
  b = true || false;
  c = EOF;
  if (a == NULL) RAISE(292)
  i = a->length;
  if (s == NULL) RAISE(293)
  i = s->length;
  CHECK(294, String_clear(s) )
  CHECK(295, String_equal(s, s, &(b)) )
  CHECK(296, String_get(s, i, &(c)) )
  CHECK(297, String_append(s, c) )
  CHECK(298, String_new(s, s) )
  CHECK(299, String_concat(s, s) )
  CHECK(300, String_concat_int(s, i) )
  CHECK(301, String_find(s, s, &(i)) )
  CHECK(302, String_has(s, c, &(b)) )
  CHECK(304, file_open_read(s, &(f)) )
  CHECK(305, file_open_write(s, &(f)) )
  CHECK(306, File_getc(f, &(c)) )
  CHECK(307, File_putc(f, c) )
  CHECK(308, File_write(f, s) )
  CHECK(309, File_close(f) )
  if (sys == NULL) RAISE(310)
  if ((1) < 0 || (1) >= (sys->argv)->length) RAISE(310)
  s = ((String**)((sys->argv)->values))[1];
  CHECK(311, Sys_print(sys, s) )
  CHECK(312, Sys_println(sys, s) )
  CHECK(313, Sys_getenv(sys, s, s, &(b)) )
  CHECK(314, Sys_system(sys, s, &(i)) )
  CHECK(315, Sys_exit(sys, i) )
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "test-mid-out"
Returncode test_mid_out(MiddleType** mt, MiddleType_Dynamic** mt_Dynamic) {
  MiddleType* new_mt = NULL;
  MiddleType_Dynamic* new_mt_Dynamic = &MiddleType_dynamic;
  new_mt = calloc(1, sizeof(MiddleType));
  if (new_mt == NULL) RAISE(65)
  *mt_Dynamic = new_mt_Dynamic;
  *mt = new_mt;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TestStruct.Mock get"
Returncode TestStruct_Mock_get(TestStruct* self, Int* x, String** s) {
  String aux_String_0_Var = {0};
  String* aux_String_0 = &aux_String_0_Var;
  *x = 12;
  aux_String_0->max_length = 1;
  aux_String_0->length = 0;
  aux_String_0->values = "";
  *s = aux_String_0;
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "Mock f-test-int2str"
Returncode Mock_f_test_int2str(Int x, String** s) {
  RAISE(75)
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "test-func"
Returncode test_func(void) {
  TestStruct t_Var = {0};
  TestStruct* t = &t_Var;
  Int x = 0;
  String* aux_String_0 = NULL;
  String* aux_String_1 = NULL;
  CHECK(81, TestStruct_Mock_get(t, &(x), &(aux_String_0)) )
  TEST_ASSERT(82, x == 12)
  do {
    MR_trace_stream = NULL;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(83, Mock_f_test_int2str(3, &(aux_String_1)) )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value
    MR_trace_stream = stdout;
    TEST_FAIL(83)
  } while (false);
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "test-another"
Returncode test_another(void) {
  Int x = 0;
  TEST_ASSERT(88, x == 0)
  return OK;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

USER_MAIN_HEADER {
  Bool success = true;
  RUN_TEST(test_func);
  RUN_TEST(test_another);
  return success? OK : FAIL;
}

TEST_MAIN_FUNC
