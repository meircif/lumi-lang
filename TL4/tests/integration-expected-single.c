#include "lumi.4.h"


/* types declaration */

typedef struct integration_M_TestStruct integration_M_TestStruct;

typedef struct integration_M_TestClass integration_M_TestClass;

typedef struct integration_M_TestClass_Dynamic integration_M_TestClass_Dynamic;

typedef struct integration_M_Data integration_M_Data;

typedef struct integration_M_Dataset integration_M_Dataset;

typedef struct integration_M_MidData integration_M_MidData;

typedef struct integration_M_TopData integration_M_TopData;

typedef struct integration_M_Container integration_M_Container;

typedef struct integration_M_ContainerIterator integration_M_ContainerIterator;

typedef struct integration_M_ComplexField integration_M_ComplexField;

typedef struct integration_M_ComplexField_Dynamic integration_M_ComplexField_Dynamic;

typedef struct integration_M_HasComplexField integration_M_HasComplexField;


/* Enums */

enum {
  integration_M_TestEnum_FIRST_VALUE = 0,
  integration_M_TestEnum_ANOTHER_VALUE,
  integration_M_TestEnum_VALUE2,
  integration_M_TestEnum_length
};


/* constants */

enum { integration_M_SIZE = 12 };

enum { integration_M_LENGTH = integration_M_SIZE * 5 };


/* types struct */

struct integration_M_TestStruct {
  Int num;
  String* text;
  Ref_Manager* text_Refman;
  integration_M_TestStruct* ts;
  Ref_Manager* ts_Refman;
  Returncode (*fun)(void);
};

struct integration_M_TestClass {
  Int num;
  String* text;
  Ref_Manager* text_Refman;
  integration_M_TestClass* tc;
  Ref_Manager* tc_Refman;
  integration_M_TestClass_Dynamic* tc_Dynamic;
};

struct integration_M_TestClass_Dynamic {
  Dynamic_Del _del;
  Returncode (*dynamic_meth)(integration_M_TestClass* self, Ref_Manager* self_Refman, integration_M_TestClass_Dynamic* self_Dynamic);
};

struct integration_M_Data {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
  Array* arr;
  Ref_Manager* arr_Refman;
};

struct integration_M_Dataset {
  integration_M_Data _base;
  Generic_Type* second;
  Ref_Manager* second_Refman;
  Generic_Type_Dynamic* second_Dynamic;
  Generic_Type* third;
  Ref_Manager* third_Refman;
  Generic_Type_Dynamic* third_Dynamic;
};

struct integration_M_MidData {
  integration_M_Dataset _base;
};

struct integration_M_TopData {
  integration_M_MidData _base;
};

struct integration_M_Container {
  Generic_Type* value;
  Ref_Manager* value_Refman;
  Generic_Type_Dynamic* value_Dynamic;
  integration_M_Container* next;
  Ref_Manager* next_Refman;
};

struct integration_M_ContainerIterator {
  integration_M_Container* curr;
  Ref_Manager* curr_Refman;
};

struct integration_M_ComplexField {
  integration_M_ComplexField* x;
  Ref_Manager* x_Refman;
  integration_M_ComplexField_Dynamic* x_Dynamic;
};

struct integration_M_ComplexField_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth)(integration_M_ComplexField* self, Ref_Manager* self_Refman, integration_M_ComplexField_Dynamic* self_Dynamic);
};

struct integration_M_HasComplexField {
  integration_M_ComplexField x;
};


/* types methods declaration */

Returncode integration_M_TestStruct_new(integration_M_TestStruct* self, Ref_Manager* self_Refman, Int x, String* s, Ref_Manager* s_Refman);

Returncode integration_M_TestStruct_get(integration_M_TestStruct* self, Ref_Manager* self_Refman, Int* x, String** s, Ref_Manager** s_Refman);

Returncode integration_M_TestStruct_print(integration_M_TestStruct* self, Ref_Manager* self_Refman);

void integration_M_TestStruct_Del(integration_M_TestStruct* self);

Returncode integration_M_TestClass_new(integration_M_TestClass* self, Ref_Manager* self_Refman, integration_M_TestClass_Dynamic* self_Dynamic);

Returncode integration_M_TestClass_static_meth(integration_M_TestClass* self, Ref_Manager* self_Refman, integration_M_TestClass_Dynamic* self_Dynamic);

Returncode integration_M_TestClass_dynamic_meth(integration_M_TestClass* self, Ref_Manager* self_Refman, integration_M_TestClass_Dynamic* self_Dynamic);

Returncode integration_M_TestClass_print(integration_M_TestClass* self, Ref_Manager* self_Refman, integration_M_TestClass_Dynamic* self_Dynamic);

void integration_M_TestClass_Del(integration_M_TestClass* self);

Returncode integration_M_Data_set(integration_M_Data* self, Ref_Manager* self_Refman, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic, Array* arr, Ref_Manager* arr_Refman);

Returncode integration_M_Data_get(integration_M_Data* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);

void integration_M_Data_Del(integration_M_Data* self);

void integration_M_Dataset_Del(integration_M_Dataset* self);

void integration_M_MidData_Del(integration_M_MidData* self);

void integration_M_TopData_Del(integration_M_TopData* self);

Returncode integration_M_Container_new(integration_M_Container* self, Ref_Manager* self_Refman, Generic_Type* value, Ref_Manager* value_Refman, Generic_Type_Dynamic* value_Dynamic, integration_M_Container* next, Ref_Manager* next_Refman);

Returncode integration_M_Container_iter(integration_M_Container* self, Ref_Manager* self_Refman, integration_M_ContainerIterator** iter, Ref_Manager** iter_Refman);

void integration_M_Container_Del(integration_M_Container* self);

Returncode integration_M_ContainerIterator_new(integration_M_ContainerIterator* self, Ref_Manager* self_Refman, integration_M_Container* first, Ref_Manager* first_Refman);

Returncode integration_M_ContainerIterator_has(integration_M_ContainerIterator* self, Ref_Manager* self_Refman, Bool* has_data);

Returncode integration_M_ContainerIterator_get(integration_M_ContainerIterator* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);

Returncode integration_M_ContainerIterator_next(integration_M_ContainerIterator* self, Ref_Manager* self_Refman);

void integration_M_ContainerIterator_Del(integration_M_ContainerIterator* self);

Returncode integration_M_ComplexField_meth(integration_M_ComplexField* self, Ref_Manager* self_Refman, integration_M_ComplexField_Dynamic* self_Dynamic);

void integration_M_ComplexField_Del(integration_M_ComplexField* self);

Returncode integration_M_HasComplexField_run(integration_M_HasComplexField* self, Ref_Manager* self_Refman);

void integration_M_HasComplexField_Del(integration_M_HasComplexField* self);


/* global functions declaration */

Returncode integration_M_test_simple_function(void);

Returncode integration_M_test_const_expression(Int* i, Char* c, String** s, Ref_Manager** s_Refman, integration_M_TestStruct** t, Ref_Manager** t_Refman, integration_M_TestClass** d, Ref_Manager** d_Refman, integration_M_TestClass_Dynamic** d_Dynamic, Returncode (**f)(void));

Returncode integration_M_test_member_expression(integration_M_TestStruct* t, Ref_Manager* t_Refman, integration_M_TestStruct** to, Ref_Manager** to_Refman, Int* i);

Returncode integration_M_test_slice_expression(String* s, Ref_Manager* s_Refman, Array* arri, Ref_Manager* arri_Refman, Array* arrs, Ref_Manager* arrs_Refman, Array* arrt, Ref_Manager* arrt_Refman, Array* arrd, Ref_Manager* arrd_Refman, Array* arrf, Ref_Manager* arrf_Refman, Char* c, Int* i, integration_M_TestStruct** t, Ref_Manager** t_Refman, integration_M_TestClass** d, Ref_Manager** d_Refman, integration_M_TestClass_Dynamic** d_Dynamic, Returncode (**f)(void), Array** arrio, Ref_Manager** arrio_Refman, Array** arrso, Ref_Manager** arrso_Refman, Array** arrto, Ref_Manager** arrto_Refman, Array** arrdo, Ref_Manager** arrdo_Refman, Array** arrfo, Ref_Manager** arrfo_Refman);

Returncode integration_M_test_container_expression(Int x, Int y, String* s, Ref_Manager* s_Refman, Int* i, Bool* b);

Returncode integration_M_test_variable(Int i, String* text, Ref_Manager* text_Refman, Array* arr, Ref_Manager* arr_Refman);

Returncode integration_M_test_complex_function(Int num, String* text, Ref_Manager* text_Refman, Int* out_num, String** out_text, Ref_Manager** out_text_Refman);

Returncode integration_M_f_test_void(void);

Returncode integration_M_f_test_params(Int x, String* s, Ref_Manager* s_Refman, String* o, Ref_Manager* o_Refman);

Returncode integration_M_f_test_outs(String** s, Ref_Manager** s_Refman, Int* x);

Returncode integration_M_f_test_int2str(Int x, String** s, Ref_Manager** s_Refman);

Returncode integration_M_f_test_int(Int x);

Returncode integration_M_f_test_int2int(Int x, Int* r);

Returncode integration_M_f_test_many(Int x, Int y, Int* n, Int* m);

Returncode integration_M_test_call_expression(void);

Returncode integration_M_test_code_flow(Array* arr, Ref_Manager* arr_Refman, Int* res);

Returncode integration_M_test_builtins(Int i, Char c, Bool b, String* s, Ref_Manager* s_Refman, Array* a, Ref_Manager* a_Refman);

Returncode integration_M_test_ref_count(void);

Returncode integration_M_f_remove(String* s, Ref_Manager* s_Refman);

Returncode integration_M_test_type_parameters(String* s, Ref_Manager* s_Refman);

Returncode integration_M_f_try_catch_raise(integration_M_TestStruct* t, Ref_Manager* t_Refman);

Returncode integration_M_test_error_handling(integration_M_TestStruct* t, Ref_Manager* t_Refman);

Returncode integration_M_test_for_each(void);

Returncode integration_M_test_complex_field(void);


/* types global variables */

Generic_Type_Dynamic integration_M_TestStruct_dynamic = {(Dynamic_Del)integration_M_TestStruct_Del};

integration_M_TestClass_Dynamic integration_M_TestClass_dynamic = {(Dynamic_Del)integration_M_TestClass_Del, integration_M_TestClass_dynamic_meth};

Generic_Type_Dynamic integration_M_Data_dynamic = {(Dynamic_Del)integration_M_Data_Del};

Generic_Type_Dynamic integration_M_Dataset_dynamic = {(Dynamic_Del)integration_M_Dataset_Del};

Generic_Type_Dynamic integration_M_MidData_dynamic = {(Dynamic_Del)integration_M_MidData_Del};

Generic_Type_Dynamic integration_M_TopData_dynamic = {(Dynamic_Del)integration_M_TopData_Del};

Generic_Type_Dynamic integration_M_Container_dynamic = {(Dynamic_Del)integration_M_Container_Del};

Generic_Type_Dynamic integration_M_ContainerIterator_dynamic = {(Dynamic_Del)integration_M_ContainerIterator_Del};

integration_M_ComplexField_Dynamic integration_M_ComplexField_dynamic = {(Dynamic_Del)integration_M_ComplexField_Del, integration_M_ComplexField_meth};

Generic_Type_Dynamic integration_M_HasComplexField_dynamic = {(Dynamic_Del)integration_M_HasComplexField_Del};


/* global variables */

Int integration_M_global_int = 0;

String* integration_M_global_string = NULL;
Ref_Manager* integration_M_global_string_Refman = NULL;

Int integration_M_int_arr_Values[integration_M_TestEnum_length + integration_M_LENGTH] = {0};
Array integration_M_int_arr_Var = {integration_M_TestEnum_length + integration_M_LENGTH, NULL};
Array* integration_M_int_arr = NULL;
Ref_Manager* integration_M_int_arr_Refman = NULL;


/* types methods body */

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "TestStruct.new"
Returncode integration_M_TestStruct_new(integration_M_TestStruct* self, Ref_Manager* self_Refman, Int x, String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  integration_M_TestStruct* aux_TestStruct_0 = NULL;
  Ref_Manager* aux_TestStruct_0_Refman = NULL;
  integration_M_TestStruct* aux_TestStruct_1 = NULL;
  Ref_Manager* aux_TestStruct_1_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(s_Refman);
  if (self == NULL) RAISE(212, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(212, 28, "outdated weak reference used")
  self->num = x;
  if (self == NULL) RAISE(213, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(213, 28, "outdated weak reference used")
  aux_Ref_Manager = self->text_Refman;
  self->text_Refman = s_Refman;
  LUMI_inc_ref(self->text_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  self->text = s;
  if (x < 0) {
      aux_TestStruct_0 = LUMI_alloc(sizeof(integration_M_TestStruct));
      if (aux_TestStruct_0 == NULL) RAISE(215, 49, "insufficient memory for object dynamic allocation")
      aux_TestStruct_0_Refman = LUMI_new_ref((void**)&aux_TestStruct_0, true);
      if (aux_TestStruct_0_Refman == NULL) RAISE(215, 38, "insufficient memory for managed object")
      LUMI_err = integration_M_TestStruct_new(aux_TestStruct_0, aux_TestStruct_0_Refman, x + 1, s, s_Refman);
      CHECK(215)
      if (self == NULL) RAISE(215, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(215, 28, "outdated weak reference used")
      aux_TestStruct_1 = aux_TestStruct_0;
      aux_TestStruct_1_Refman = aux_TestStruct_0_Refman;
      aux_TestStruct_0 = NULL;
      aux_TestStruct_0_Refman = NULL;
      integration_M_TestStruct_Del(self->ts);
      LUMI_owner_dec_ref(self->ts_Refman);
      self->ts_Refman = aux_TestStruct_1_Refman;
      self->ts = aux_TestStruct_1;
      aux_TestStruct_1 = NULL;
      aux_TestStruct_1_Refman = NULL;
    }
LUMI_cleanup:
  integration_M_TestStruct_Del(aux_TestStruct_1);
  LUMI_owner_dec_ref(aux_TestStruct_1_Refman);
  integration_M_TestStruct_Del(aux_TestStruct_0);
  LUMI_owner_dec_ref(aux_TestStruct_0_Refman);
  LUMI_dec_ref(s_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "TestStruct.get"
Returncode integration_M_TestStruct_get(integration_M_TestStruct* self, Ref_Manager* self_Refman, Int* x, String** s, Ref_Manager** s_Refman) {
  Returncode LUMI_err = OK;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(222, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(222, 28, "outdated weak reference used")
  *x = self->num;
  if (self == NULL) RAISE(223, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(223, 28, "outdated weak reference used")
  aux_Ref_Manager = *s_Refman;
  *s_Refman = self->text_Refman;
  LUMI_inc_ref(*s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *s = self->text;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "TestStruct.print"
Returncode integration_M_TestStruct_print(integration_M_TestStruct* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(226, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(226, 28, "outdated weak reference used")
  LUMI_err = Sys_println(sys, sys_Refman, self->text, self->text_Refman);
  CHECK(226)
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void integration_M_TestStruct_Del(integration_M_TestStruct* self) {
  if (self == NULL) return;
  SELF_REF_DEL(integration_M_TestStruct, ts);
  LUMI_owner_dec_ref(self->ts_Refman);
  LUMI_dec_ref(self->text_Refman);
}

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "TestClass.new"
Returncode integration_M_TestClass_new(integration_M_TestClass* self, Ref_Manager* self_Refman, integration_M_TestClass_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(235, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(235, 28, "outdated weak reference used")
  self->num = 1;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "TestClass.static-meth"
Returncode integration_M_TestClass_static_meth(integration_M_TestClass* self, Ref_Manager* self_Refman, integration_M_TestClass_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(238, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(238, 28, "outdated weak reference used")
  self->num = 3;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "TestClass.dynamic-meth"
Returncode integration_M_TestClass_dynamic_meth(integration_M_TestClass* self, Ref_Manager* self_Refman, integration_M_TestClass_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(241, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(241, 28, "outdated weak reference used")
  self->num = 6;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "TestClass.print"
Returncode integration_M_TestClass_print(integration_M_TestClass* self, Ref_Manager* self_Refman, integration_M_TestClass_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(244, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(244, 28, "outdated weak reference used")
  LUMI_err = Sys_println(sys, sys_Refman, self->text, self->text_Refman);
  CHECK(244)
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void integration_M_TestClass_Del(integration_M_TestClass* self) {
  if (self == NULL) return;
  DYN_SELF_REF_DEL(integration_M_TestClass, _, tc);
  LUMI_owner_dec_ref(self->tc_Refman);
  LUMI_dec_ref(self->text_Refman);
}

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "Data.set"
Returncode integration_M_Data_set(integration_M_Data* self, Ref_Manager* self_Refman, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic, Array* arr, Ref_Manager* arr_Refman) {
  Returncode LUMI_err = OK;
  Generic_Type* x = NULL;
  Ref_Manager* x_Refman = NULL;
  Generic_Type_Dynamic* x_Dynamic = NULL;
  integration_M_Data* d = NULL;
  Ref_Manager* d_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(item_Refman);
  LUMI_inc_ref(arr_Refman);
  x = item;
  x_Refman = item_Refman;
  LUMI_inc_ref(x_Refman);
  x_Dynamic = item_Dynamic;
  if (self == NULL) RAISE(377, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(377, 28, "outdated weak reference used")
  aux_Ref_Manager = self->item_Refman;
  self->item_Refman = x_Refman;
  self->item_Dynamic = x_Dynamic;
  LUMI_inc_ref(self->item_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  self->item = x;
  if (self == NULL) RAISE(378, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(378, 28, "outdated weak reference used")
  aux_Ref_Manager = self->arr_Refman;
  self->arr_Refman = arr_Refman;
  LUMI_inc_ref(self->arr_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  self->arr = arr;
  d = LUMI_alloc(sizeof(integration_M_Data));
  if (d == NULL) RAISE(379, 49, "insufficient memory for object dynamic allocation")
  d_Refman = LUMI_new_ref((void**)&d, true);
  if (d_Refman == NULL) RAISE(379, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(380, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(380, 28, "outdated weak reference used")
  if (d == NULL) RAISE(380, 17, "empty object used")
  if (d_Refman->value == NULL) RAISE(380, 28, "outdated weak reference used")
  aux_Ref_Manager = d->item_Refman;
  d->item_Refman = self->item_Refman;
  d->item_Dynamic = self->item_Dynamic;
  LUMI_inc_ref(d->item_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  d->item = self->item;
  if (d == NULL) RAISE(381, 17, "empty object used")
  if (d_Refman->value == NULL) RAISE(381, 28, "outdated weak reference used")
  if (self == NULL) RAISE(381, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(381, 28, "outdated weak reference used")
  aux_Ref_Manager = self->item_Refman;
  self->item_Refman = d->item_Refman;
  self->item_Dynamic = d->item_Dynamic;
  LUMI_inc_ref(self->item_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  self->item = d->item;
LUMI_cleanup:
  integration_M_Data_Del(d);
  LUMI_owner_dec_ref(d_Refman);
  LUMI_dec_ref(x_Refman);
  LUMI_dec_ref(arr_Refman);
  LUMI_dec_ref(item_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "Data.get"
Returncode integration_M_Data_get(integration_M_Data* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
  Returncode LUMI_err = OK;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(384, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(384, 28, "outdated weak reference used")
  aux_Ref_Manager = *item_Refman;
  *item_Refman = self->item_Refman;
  *item_Dynamic = self->item_Dynamic;
  LUMI_inc_ref(*item_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *item = self->item;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void integration_M_Data_Del(integration_M_Data* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->arr_Refman);
  LUMI_dec_ref(self->item_Refman);
}

void integration_M_Dataset_Del(integration_M_Dataset* self) {
  if (self == NULL) return;
  integration_M_Data_Del(&(self->_base));
  LUMI_dec_ref(self->third_Refman);
  LUMI_dec_ref(self->second_Refman);
}

void integration_M_MidData_Del(integration_M_MidData* self) {
  if (self == NULL) return;
  integration_M_Dataset_Del(&(self->_base));
}

void integration_M_TopData_Del(integration_M_TopData* self) {
  if (self == NULL) return;
  integration_M_MidData_Del(&(self->_base));
}

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "Container.new"
Returncode integration_M_Container_new(integration_M_Container* self, Ref_Manager* self_Refman, Generic_Type* value, Ref_Manager* value_Refman, Generic_Type_Dynamic* value_Dynamic, integration_M_Container* next, Ref_Manager* next_Refman) {
  Returncode LUMI_err = OK;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(value_Refman);
  LUMI_inc_ref(next_Refman);
  if (self == NULL) RAISE(459, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(459, 28, "outdated weak reference used")
  aux_Ref_Manager = self->value_Refman;
  self->value_Refman = value_Refman;
  self->value_Dynamic = value_Dynamic;
  LUMI_inc_ref(self->value_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  self->value = value;
  if (self == NULL) RAISE(460, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(460, 28, "outdated weak reference used")
  aux_Ref_Manager = self->next_Refman;
  self->next_Refman = next_Refman;
  LUMI_inc_ref(self->next_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  self->next = next;
LUMI_cleanup:
  LUMI_dec_ref(next_Refman);
  LUMI_dec_ref(value_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "Container.iter"
Returncode integration_M_Container_iter(integration_M_Container* self, Ref_Manager* self_Refman, integration_M_ContainerIterator** iter, Ref_Manager** iter_Refman) {
  Returncode LUMI_err = OK;
  integration_M_ContainerIterator* aux_ContainerIterator_0 = NULL;
  Ref_Manager* aux_ContainerIterator_0_Refman = NULL;
  integration_M_ContainerIterator* aux_ContainerIterator_1 = NULL;
  Ref_Manager* aux_ContainerIterator_1_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(463, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(463, 28, "outdated weak reference used")
  aux_ContainerIterator_0 = LUMI_alloc(sizeof(integration_M_ContainerIterator));
  if (aux_ContainerIterator_0 == NULL) RAISE(463, 49, "insufficient memory for object dynamic allocation")
  aux_ContainerIterator_0_Refman = LUMI_new_ref((void**)&aux_ContainerIterator_0, true);
  if (aux_ContainerIterator_0_Refman == NULL) RAISE(463, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_ContainerIterator_new(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman, self->next, self->next_Refman);
  CHECK(463)
  aux_ContainerIterator_1 = aux_ContainerIterator_0;
  aux_ContainerIterator_1_Refman = aux_ContainerIterator_0_Refman;
  aux_ContainerIterator_0 = NULL;
  aux_ContainerIterator_0_Refman = NULL;
  integration_M_ContainerIterator_Del(*iter);
  LUMI_owner_dec_ref(*iter_Refman);
  *iter_Refman = aux_ContainerIterator_1_Refman;
  *iter = aux_ContainerIterator_1;
  aux_ContainerIterator_1 = NULL;
  aux_ContainerIterator_1_Refman = NULL;
LUMI_cleanup:
  integration_M_ContainerIterator_Del(aux_ContainerIterator_1);
  LUMI_owner_dec_ref(aux_ContainerIterator_1_Refman);
  integration_M_ContainerIterator_Del(aux_ContainerIterator_0);
  LUMI_owner_dec_ref(aux_ContainerIterator_0_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void integration_M_Container_Del(integration_M_Container* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->next_Refman);
  LUMI_dec_ref(self->value_Refman);
}

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "ContainerIterator.new"
Returncode integration_M_ContainerIterator_new(integration_M_ContainerIterator* self, Ref_Manager* self_Refman, integration_M_Container* first, Ref_Manager* first_Refman) {
  Returncode LUMI_err = OK;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(first_Refman);
  if (self == NULL) RAISE(469, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(469, 28, "outdated weak reference used")
  aux_Ref_Manager = self->curr_Refman;
  self->curr_Refman = first_Refman;
  LUMI_inc_ref(self->curr_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  self->curr = first;
LUMI_cleanup:
  LUMI_dec_ref(first_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "ContainerIterator.has"
Returncode integration_M_ContainerIterator_has(integration_M_ContainerIterator* self, Ref_Manager* self_Refman, Bool* has_data) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(472, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(472, 28, "outdated weak reference used")
  *has_data = self->curr != NULL && self->curr_Refman->value != NULL;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "ContainerIterator.get"
Returncode integration_M_ContainerIterator_get(integration_M_ContainerIterator* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
  Returncode LUMI_err = OK;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(475, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(475, 28, "outdated weak reference used")
  if (self->curr == NULL) RAISE(475, 17, "empty object used")
  if (self->curr_Refman->value == NULL) RAISE(475, 28, "outdated weak reference used")
  aux_Ref_Manager = *item_Refman;
  *item_Refman = self->curr->value_Refman;
  *item_Dynamic = self->curr->value_Dynamic;
  LUMI_inc_ref(*item_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *item = self->curr->value;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "ContainerIterator.next"
Returncode integration_M_ContainerIterator_next(integration_M_ContainerIterator* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(478, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(478, 28, "outdated weak reference used")
  if (self->curr == NULL) RAISE(478, 17, "empty object used")
  if (self->curr_Refman->value == NULL) RAISE(478, 28, "outdated weak reference used")
  if (self == NULL) RAISE(478, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(478, 28, "outdated weak reference used")
  aux_Ref_Manager = self->curr_Refman;
  self->curr_Refman = self->curr->next_Refman;
  LUMI_inc_ref(self->curr_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  self->curr = self->curr->next;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void integration_M_ContainerIterator_Del(integration_M_ContainerIterator* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->curr_Refman);
}

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "ComplexField.meth"
Returncode integration_M_ComplexField_meth(integration_M_ComplexField* self, Ref_Manager* self_Refman, integration_M_ComplexField_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref((void**)&aux_String_0, false);
  if (aux_String_0_Refman == NULL) RAISE(538, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 2;
  aux_String_0_Var.length = 1;
  aux_String_0_Var.values = "$";
  LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(538)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void integration_M_ComplexField_Del(integration_M_ComplexField* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->x_Refman);
}

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "HasComplexField.run"
Returncode integration_M_HasComplexField_run(integration_M_HasComplexField* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  integration_M_ComplexField* x = NULL;
  Ref_Manager* x_Refman = NULL;
  integration_M_ComplexField_Dynamic* x_Dynamic = NULL;
  integration_M_ComplexField* x2 = NULL;
  Ref_Manager* x2_Refman = NULL;
  integration_M_ComplexField_Dynamic* x2_Dynamic = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(543, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(543, 28, "outdated weak reference used")
  x = &(self->x);
  x_Refman = self_Refman;
  LUMI_inc_ref(x_Refman);
  x_Dynamic = &integration_M_ComplexField_dynamic;
  if (self == NULL) RAISE(544, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(544, 28, "outdated weak reference used")
  aux_Ref_Manager = x_Refman;
  x_Refman = self_Refman;
  x_Dynamic = &integration_M_ComplexField_dynamic;
  LUMI_inc_ref(x_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  x = &(self->x);
  if (x_Dynamic == NULL) RAISE(545, 28, "dynamic call of empty object")
  LUMI_err = x_Dynamic->meth(x, x_Refman, x_Dynamic);
  CHECK(545)
  if (self == NULL) RAISE(546, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(546, 28, "outdated weak reference used")
  LUMI_err = integration_M_ComplexField_meth(&(self->x), self_Refman, &integration_M_ComplexField_dynamic);
  CHECK(546)
  if (self == NULL) RAISE(547, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(547, 28, "outdated weak reference used")
  LUMI_err = integration_M_ComplexField_meth(&(self->x), self_Refman, &integration_M_ComplexField_dynamic);
  CHECK(547)
  if (self == NULL) RAISE(548, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(548, 28, "outdated weak reference used")
  x2 = self->x.x;
  x2_Refman = self->x.x_Refman;
  LUMI_inc_ref(x2_Refman);
  x2_Dynamic = self->x.x_Dynamic;
  if (self == NULL) RAISE(549, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(549, 28, "outdated weak reference used")
  aux_Ref_Manager = x2_Refman;
  x2_Refman = self->x.x_Refman;
  x2_Dynamic = self->x.x_Dynamic;
  LUMI_inc_ref(x2_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  x2 = self->x.x;
  if (x2_Dynamic == NULL) RAISE(550, 28, "dynamic call of empty object")
  LUMI_err = x2_Dynamic->meth(x2, x2_Refman, x2_Dynamic);
  CHECK(550)
  if (self == NULL) RAISE(551, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(551, 28, "outdated weak reference used")
  if (self->x.x_Dynamic == NULL) RAISE(551, 28, "dynamic call of empty object")
  LUMI_err = self->x.x_Dynamic->meth(self->x.x, self->x.x_Refman, self->x.x_Dynamic);
  CHECK(551)
  if (self == NULL) RAISE(552, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(552, 28, "outdated weak reference used")
  LUMI_err = integration_M_ComplexField_meth(self->x.x, self->x.x_Refman, self->x.x_Dynamic);
  CHECK(552)
LUMI_cleanup:
  LUMI_dec_ref(x2_Refman);
  LUMI_dec_ref(x_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void integration_M_HasComplexField_Del(integration_M_HasComplexField* self) {
  if (self == NULL) return;
  integration_M_ComplexField_Del(&(self->x));
}


/* global functions body */

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-simple-function"
Returncode integration_M_test_simple_function(void) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref((void**)&aux_String_0, false);
  if (aux_String_0_Refman == NULL) RAISE(36, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 23;
  aux_String_0_Var.length = 22;
  aux_String_0_Var.values = "I am a simple function";
  LUMI_err = Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(36)
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref((void**)&aux_String_1, false);
  if (aux_String_1_Refman == NULL) RAISE(40, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 25;
  aux_String_1_Var.length = 24;
  aux_String_1_Var.values = "I am a multiline\nstring\n";
  LUMI_err = Sys_print(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
  CHECK(37)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-const-expression"
Returncode integration_M_test_const_expression(Int* i, Char* c, String** s, Ref_Manager** s_Refman, integration_M_TestStruct** t, Ref_Manager** t_Refman, integration_M_TestClass** d, Ref_Manager** d_Refman, integration_M_TestClass_Dynamic** d_Dynamic, Returncode (**f)(void)) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  *i = (((((((0 + 9630) + -9630) + 07520) + -07520) + 0xfda940) + -0xfda940) + 0xFDA940) + -0xFDA940;
  *c = (((('a' + '\'') + '\n') + '\x0f') + '\xA9') + '\270';
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref((void**)&aux_String_0, false);
  if (aux_String_0_Refman == NULL) RAISE(53, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  aux_Ref_Manager = *s_Refman;
  *s_Refman = aux_String_0_Refman;
  LUMI_inc_ref(*s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *s = aux_String_0;
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref((void**)&aux_String_1, false);
  if (aux_String_1_Refman == NULL) RAISE(56, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 12;
  aux_String_1_Var.length = 11;
  aux_String_1_Var.values = "some\nstring";
  aux_Ref_Manager = *s_Refman;
  *s_Refman = aux_String_1_Refman;
  LUMI_inc_ref(*s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *s = aux_String_1;
  aux_Ref_Manager = *t_Refman;
  *t_Refman = NULL;
  LUMI_inc_ref(*t_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *t = NULL;
  aux_Ref_Manager = *d_Refman;
  *d_Refman = NULL;
  *d_Dynamic = NULL;
  LUMI_inc_ref(*d_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *d = NULL;
  *f = NULL;
  if (*f == NULL) RAISE(60, 21, "empty function called")
  LUMI_err = (*f)();
  CHECK(60)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-member-expression"
Returncode integration_M_test_member_expression(integration_M_TestStruct* t, Ref_Manager* t_Refman, integration_M_TestStruct** to, Ref_Manager** to_Refman, Int* i) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(t_Refman);
  if (t == NULL) RAISE(64, 17, "empty object used")
  if (t_Refman->value == NULL) RAISE(64, 28, "outdated weak reference used")
  if (t->ts == NULL) RAISE(64, 17, "empty object used")
  if (t->ts_Refman->value == NULL) RAISE(64, 28, "outdated weak reference used")
  if (t->ts->ts == NULL) RAISE(64, 17, "empty object used")
  if (t->ts->ts_Refman->value == NULL) RAISE(64, 28, "outdated weak reference used")
  if (t == NULL) RAISE(64, 17, "empty object used")
  if (t_Refman->value == NULL) RAISE(64, 28, "outdated weak reference used")
  if (t->ts == NULL) RAISE(64, 17, "empty object used")
  if (t->ts_Refman->value == NULL) RAISE(64, 28, "outdated weak reference used")
  if (*to == NULL) RAISE(64, 17, "empty object used")
  if ((*to_Refman)->value == NULL) RAISE(64, 28, "outdated weak reference used")
  if (t == NULL) RAISE(64, 17, "empty object used")
  if (t_Refman->value == NULL) RAISE(64, 28, "outdated weak reference used")
  t->num = ((*to)->num + t->ts->num) + t->ts->ts->num;
  if (t == NULL) RAISE(65, 17, "empty object used")
  if (t_Refman->value == NULL) RAISE(65, 28, "outdated weak reference used")
  if (*to == NULL) RAISE(65, 17, "empty object used")
  if ((*to_Refman)->value == NULL) RAISE(65, 28, "outdated weak reference used")
  (*to)->num = t->num;
  if (t == NULL) RAISE(66, 17, "empty object used")
  if (t_Refman->value == NULL) RAISE(66, 28, "outdated weak reference used")
  if (t->ts == NULL) RAISE(66, 17, "empty object used")
  if (t->ts_Refman->value == NULL) RAISE(66, 28, "outdated weak reference used")
  if (t->ts->ts == NULL) RAISE(66, 17, "empty object used")
  if (t->ts->ts_Refman->value == NULL) RAISE(66, 28, "outdated weak reference used")
  t->ts->ts->num = 4;
  if (t == NULL) RAISE(67, 17, "empty object used")
  if (t_Refman->value == NULL) RAISE(67, 28, "outdated weak reference used")
  t->fun = integration_M_f_test_void;
  if (t == NULL) RAISE(68, 17, "empty object used")
  if (t_Refman->value == NULL) RAISE(68, 28, "outdated weak reference used")
  if (t->fun == NULL) RAISE(68, 21, "empty function called")
  LUMI_err = t->fun();
  CHECK(68)
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref((void**)&aux_String_0, false);
  if (aux_String_0_Refman == NULL) RAISE(69, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 1;
  aux_String_0_Var.length = 0;
  aux_String_0_Var.values = "";
  LUMI_err = integration_M_TestStruct_new(t, t_Refman, 0, aux_String_0, aux_String_0_Refman);
  CHECK(69)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(t_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-slice-expression"
Returncode integration_M_test_slice_expression(String* s, Ref_Manager* s_Refman, Array* arri, Ref_Manager* arri_Refman, Array* arrs, Ref_Manager* arrs_Refman, Array* arrt, Ref_Manager* arrt_Refman, Array* arrd, Ref_Manager* arrd_Refman, Array* arrf, Ref_Manager* arrf_Refman, Char* c, Int* i, integration_M_TestStruct** t, Ref_Manager** t_Refman, integration_M_TestClass** d, Ref_Manager** d_Refman, integration_M_TestClass_Dynamic** d_Dynamic, Returncode (**f)(void), Array** arrio, Ref_Manager** arrio_Refman, Array** arrso, Ref_Manager** arrso_Refman, Array** arrto, Ref_Manager** arrto_Refman, Array** arrdo, Ref_Manager** arrdo_Refman, Array** arrfo, Ref_Manager** arrfo_Refman) {
  Returncode LUMI_err = OK;
  Array aux_Array_0_Var = {0};
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  Array aux_Array_1_Var = {0};
  Array* aux_Array_1 = NULL;
  Ref_Manager* aux_Array_1_Refman = NULL;
  Array aux_Array_2_Var = {0};
  Array* aux_Array_2 = NULL;
  Ref_Manager* aux_Array_2_Refman = NULL;
  Array aux_Array_3_Var = {0};
  Array* aux_Array_3 = NULL;
  Ref_Manager* aux_Array_3_Refman = NULL;
  Array aux_Array_4_Var = {0};
  Array* aux_Array_4 = NULL;
  Ref_Manager* aux_Array_4_Refman = NULL;
  Array aux_Array_5_Var = {0};
  Array* aux_Array_5 = NULL;
  Ref_Manager* aux_Array_5_Refman = NULL;
  Array aux_Array_6_Var = {0};
  Array* aux_Array_6 = NULL;
  Ref_Manager* aux_Array_6_Refman = NULL;
  Array aux_Array_7_Var = {0};
  Array* aux_Array_7 = NULL;
  Ref_Manager* aux_Array_7_Refman = NULL;
  Array aux_Array_8_Var = {0};
  Array* aux_Array_8 = NULL;
  Ref_Manager* aux_Array_8_Refman = NULL;
  Array aux_Array_9_Var = {0};
  Array* aux_Array_9 = NULL;
  Ref_Manager* aux_Array_9_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(s_Refman);
  LUMI_inc_ref(arri_Refman);
  LUMI_inc_ref(arrs_Refman);
  LUMI_inc_ref(arrt_Refman);
  LUMI_inc_ref(arrd_Refman);
  LUMI_inc_ref(arrf_Refman);
  aux_Array_0 = &aux_Array_0_Var;
  aux_Array_0_Refman = LUMI_new_ref((void**)&aux_Array_0, false);
  if (aux_Array_0_Refman == NULL) RAISE(89, 38, "insufficient memory for managed object")
  aux_Array_0_Var.length = 2;
  aux_Array_0_Var.values = (Byte*)((arrs)->values) + (4);
  if (arrs == NULL) RAISE(89, 17, "empty object used")
  if (arrs_Refman->value == NULL) RAISE(89, 28, "outdated weak reference used")
  if ((4) < 0 || (2) < 0 || (4) + (2) > (arrs)->length) RAISE(89, 25, "slice index out of bounds")
  if (aux_Array_0 == NULL) RAISE(89, 17, "empty object used")
  if (arrs_Refman->value == NULL) RAISE(89, 28, "outdated weak reference used")
  if ((4) < 0 || (4) >= (aux_Array_0)->length) RAISE(89, 25, "slice index out of bounds")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref((void**)&aux_String_0, false);
  if (aux_String_0_Refman == NULL) RAISE(89, 38, "insufficient memory for managed object")
  aux_String_0_Var.length = 3;
  aux_String_0_Var.max_length = aux_String_0_Var.length + 1;
  aux_String_0_Var.values = ((((String*)((aux_Array_0)->values)) + 4))->values + (1);
  if (((String*)((aux_Array_0)->values)) + 4 == NULL) RAISE(89, 17, "empty object used")
  if (arrs_Refman->value == NULL) RAISE(89, 28, "outdated weak reference used")
  if ((1) < 0 || (3) < 0 || (1) + (3) > ((((String*)((aux_Array_0)->values)) + 4))->length) RAISE(89, 25, "slice index out of bounds")
  if (aux_String_0 == NULL) RAISE(89, 17, "empty object used")
  if (arrs_Refman->value == NULL) RAISE(89, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (aux_String_0)->length) RAISE(89, 25, "slice index out of bounds")
  if (arrs == NULL) RAISE(89, 17, "empty object used")
  if (arrs_Refman->value == NULL) RAISE(89, 28, "outdated weak reference used")
  if ((3) < 0 || (3) >= (arrs)->length) RAISE(89, 25, "slice index out of bounds")
  if (((String*)((arrs)->values)) + 3 == NULL) RAISE(89, 17, "empty object used")
  if (arrs_Refman->value == NULL) RAISE(89, 28, "outdated weak reference used")
  if ((2) < 0 || (2) >= ((((String*)((arrs)->values)) + 3))->length) RAISE(89, 25, "slice index out of bounds")
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref((void**)&aux_String_1, false);
  if (aux_String_1_Refman == NULL) RAISE(89, 38, "insufficient memory for managed object")
  aux_String_1_Var.length = 7;
  aux_String_1_Var.max_length = aux_String_1_Var.length + 1;
  aux_String_1_Var.values = (s)->values + (4);
  if (s == NULL) RAISE(89, 17, "empty object used")
  if (s_Refman->value == NULL) RAISE(89, 28, "outdated weak reference used")
  if ((4) < 0 || (7) < 0 || (4) + (7) > (s)->length) RAISE(89, 25, "slice index out of bounds")
  if (aux_String_1 == NULL) RAISE(89, 17, "empty object used")
  if (s_Refman->value == NULL) RAISE(89, 28, "outdated weak reference used")
  if ((2) < 0 || (2) >= (aux_String_1)->length) RAISE(89, 25, "slice index out of bounds")
  if (s == NULL) RAISE(89, 17, "empty object used")
  if (s_Refman->value == NULL) RAISE(89, 28, "outdated weak reference used")
  if ((2) < 0 || (2) >= (s)->length) RAISE(89, 25, "slice index out of bounds")
  *c = (((((s)->values)[2]) + (((aux_String_1)->values)[2])) + ((((((String*)((arrs)->values)) + 3))->values)[2])) + (((aux_String_0)->values)[0]);
  aux_Array_1 = &aux_Array_1_Var;
  aux_Array_1_Refman = LUMI_new_ref((void**)&aux_Array_1, false);
  if (aux_Array_1_Refman == NULL) RAISE(91, 38, "insufficient memory for managed object")
  aux_Array_1_Var.length = 3;
  aux_Array_1_Var.values = (Byte*)((arri)->values) + (3);
  if (arri == NULL) RAISE(91, 17, "empty object used")
  if (arri_Refman->value == NULL) RAISE(91, 28, "outdated weak reference used")
  if ((3) < 0 || (3) < 0 || (3) + (3) > (arri)->length) RAISE(91, 25, "slice index out of bounds")
  aux_Array_2 = &aux_Array_2_Var;
  aux_Array_2_Refman = LUMI_new_ref((void**)&aux_Array_2, false);
  if (aux_Array_2_Refman == NULL) RAISE(91, 38, "insufficient memory for managed object")
  aux_Array_2_Var.length = 2;
  aux_Array_2_Var.values = (Byte*)((aux_Array_1)->values) + (1);
  if (aux_Array_1 == NULL) RAISE(91, 17, "empty object used")
  if (arri_Refman->value == NULL) RAISE(91, 28, "outdated weak reference used")
  if ((1) < 0 || (2) < 0 || (1) + (2) > (aux_Array_1)->length) RAISE(91, 25, "slice index out of bounds")
  if (aux_Array_2 == NULL) RAISE(91, 17, "empty object used")
  if (arri_Refman->value == NULL) RAISE(91, 28, "outdated weak reference used")
  if ((1) < 0 || (1) >= (aux_Array_2)->length) RAISE(91, 25, "slice index out of bounds")
  aux_Array_3 = &aux_Array_3_Var;
  aux_Array_3_Refman = LUMI_new_ref((void**)&aux_Array_3, false);
  if (aux_Array_3_Refman == NULL) RAISE(90, 38, "insufficient memory for managed object")
  aux_Array_3_Var.length = 4;
  aux_Array_3_Var.values = (Byte*)((arrt)->values) + (2);
  if (arrt == NULL) RAISE(90, 17, "empty object used")
  if (arrt_Refman->value == NULL) RAISE(90, 28, "outdated weak reference used")
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arrt)->length) RAISE(90, 25, "slice index out of bounds")
  if (aux_Array_3 == NULL) RAISE(90, 17, "empty object used")
  if (arrt_Refman->value == NULL) RAISE(90, 28, "outdated weak reference used")
  if ((1) < 0 || (1) >= (aux_Array_3)->length) RAISE(90, 25, "slice index out of bounds")
  if (((integration_M_TestStruct*)((aux_Array_3)->values)) + 1 == NULL) RAISE(90, 17, "empty object used")
  if (arrt_Refman->value == NULL) RAISE(90, 28, "outdated weak reference used")
  if (arrt == NULL) RAISE(90, 17, "empty object used")
  if (arrt_Refman->value == NULL) RAISE(90, 28, "outdated weak reference used")
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(90, 25, "slice index out of bounds")
  if (((integration_M_TestStruct*)((arrt)->values)) + 4 == NULL) RAISE(90, 17, "empty object used")
  if (arrt_Refman->value == NULL) RAISE(90, 28, "outdated weak reference used")
  if (arri == NULL) RAISE(90, 17, "empty object used")
  if (arri_Refman->value == NULL) RAISE(90, 28, "outdated weak reference used")
  if ((2) < 0 || (2) >= (arri)->length) RAISE(90, 25, "slice index out of bounds")
  if (arri == NULL) RAISE(90, 17, "empty object used")
  if (arri_Refman->value == NULL) RAISE(90, 28, "outdated weak reference used")
  if ((((*i) + 3) - (((Int*)((arri)->values))[2])) < 0 || (*i + 3 - (((Int*)((arri)->values))[2])) >= (arri)->length) RAISE(90, 25, "slice index out of bounds")
  *i = (((((Int*)((arri)->values))[*i + 3 - (((Int*)((arri)->values))[2])]) + (((integration_M_TestStruct*)((arrt)->values)) + 4)->num) + (((integration_M_TestStruct*)((aux_Array_3)->values)) + 1)->num) + (((Int*)((aux_Array_2)->values))[1]);
  aux_Array_4 = &aux_Array_4_Var;
  aux_Array_4_Refman = LUMI_new_ref((void**)&aux_Array_4, false);
  if (aux_Array_4_Refman == NULL) RAISE(92, 38, "insufficient memory for managed object")
  aux_Array_4_Var.length = 4;
  aux_Array_4_Var.values = (Byte*)((arri)->values) + (2);
  if (arri == NULL) RAISE(92, 17, "empty object used")
  if (arri_Refman->value == NULL) RAISE(92, 28, "outdated weak reference used")
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arri)->length) RAISE(92, 25, "slice index out of bounds")
  if (aux_Array_4 == NULL) RAISE(92, 17, "empty object used")
  if (arri_Refman->value == NULL) RAISE(92, 28, "outdated weak reference used")
  if ((1) < 0 || (1) >= (aux_Array_4)->length) RAISE(92, 25, "slice index out of bounds")
  aux_Array_5 = &aux_Array_5_Var;
  aux_Array_5_Refman = LUMI_new_ref((void**)&aux_Array_5, false);
  if (aux_Array_5_Refman == NULL) RAISE(92, 38, "insufficient memory for managed object")
  aux_Array_5_Var.length = 5 * ((*i) - 1);
  aux_Array_5_Var.values = (Byte*)((arri)->values) + ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1]));
  if (arri == NULL) RAISE(92, 17, "empty object used")
  if (arri_Refman->value == NULL) RAISE(92, 28, "outdated weak reference used")
  if ((2 - (*i) + (((Int*)((aux_Array_4)->values))[1])) < 0 || (5 * (*i - 1)) < 0 || (2 - (*i) + (((Int*)((aux_Array_4)->values))[1])) + (5 * (*i - 1)) > (arri)->length) RAISE(92, 25, "slice index out of bounds")
  aux_Ref_Manager = *arrio_Refman;
  *arrio_Refman = arri_Refman;
  LUMI_inc_ref(*arrio_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *arrio = aux_Array_5;
  if (arrs == NULL) RAISE(93, 17, "empty object used")
  if (arrs_Refman->value == NULL) RAISE(93, 28, "outdated weak reference used")
  if ((4) < 0 || (4) >= (arrs)->length) RAISE(93, 25, "slice index out of bounds")
  aux_Ref_Manager = s_Refman;
  s_Refman = arrs_Refman;
  LUMI_inc_ref(s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  s = ((String*)((arrs)->values)) + 4;
  aux_Array_6 = &aux_Array_6_Var;
  aux_Array_6_Refman = LUMI_new_ref((void**)&aux_Array_6, false);
  if (aux_Array_6_Refman == NULL) RAISE(94, 38, "insufficient memory for managed object")
  aux_Array_6_Var.length = 7;
  aux_Array_6_Var.values = (Byte*)((arrs)->values) + (2);
  if (arrs == NULL) RAISE(94, 17, "empty object used")
  if (arrs_Refman->value == NULL) RAISE(94, 28, "outdated weak reference used")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrs)->length) RAISE(94, 25, "slice index out of bounds")
  aux_Ref_Manager = *arrso_Refman;
  *arrso_Refman = arrs_Refman;
  LUMI_inc_ref(*arrso_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *arrso = aux_Array_6;
  if (arrt == NULL) RAISE(95, 17, "empty object used")
  if (arrt_Refman->value == NULL) RAISE(95, 28, "outdated weak reference used")
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(95, 25, "slice index out of bounds")
  aux_Ref_Manager = *t_Refman;
  *t_Refman = arrt_Refman;
  LUMI_inc_ref(*t_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *t = ((integration_M_TestStruct*)((arrt)->values)) + 4;
  aux_Array_7 = &aux_Array_7_Var;
  aux_Array_7_Refman = LUMI_new_ref((void**)&aux_Array_7, false);
  if (aux_Array_7_Refman == NULL) RAISE(96, 38, "insufficient memory for managed object")
  aux_Array_7_Var.length = 7;
  aux_Array_7_Var.values = (Byte*)((arrt)->values) + (2);
  if (arrt == NULL) RAISE(96, 17, "empty object used")
  if (arrt_Refman->value == NULL) RAISE(96, 28, "outdated weak reference used")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrt)->length) RAISE(96, 25, "slice index out of bounds")
  aux_Ref_Manager = *arrto_Refman;
  *arrto_Refman = arrt_Refman;
  LUMI_inc_ref(*arrto_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *arrto = aux_Array_7;
  if (arrd == NULL) RAISE(97, 17, "empty object used")
  if (arrd_Refman->value == NULL) RAISE(97, 28, "outdated weak reference used")
  if ((4) < 0 || (4) >= (arrd)->length) RAISE(97, 25, "slice index out of bounds")
  aux_Ref_Manager = *d_Refman;
  *d_Refman = arrd_Refman;
  *d_Dynamic = &integration_M_TestClass_dynamic;
  LUMI_inc_ref(*d_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *d = ((integration_M_TestClass*)((arrd)->values)) + 4;
  aux_Array_8 = &aux_Array_8_Var;
  aux_Array_8_Refman = LUMI_new_ref((void**)&aux_Array_8, false);
  if (aux_Array_8_Refman == NULL) RAISE(98, 38, "insufficient memory for managed object")
  aux_Array_8_Var.length = 7;
  aux_Array_8_Var.values = (Byte*)((arrd)->values) + (2);
  if (arrd == NULL) RAISE(98, 17, "empty object used")
  if (arrd_Refman->value == NULL) RAISE(98, 28, "outdated weak reference used")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrd)->length) RAISE(98, 25, "slice index out of bounds")
  aux_Ref_Manager = *arrdo_Refman;
  *arrdo_Refman = arrd_Refman;
  LUMI_inc_ref(*arrdo_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *arrdo = aux_Array_8;
  if (arrf == NULL) RAISE(99, 17, "empty object used")
  if (arrf_Refman->value == NULL) RAISE(99, 28, "outdated weak reference used")
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(99, 25, "slice index out of bounds")
  *f = ((Returncode (**)(void))((arrf)->values))[4];
  aux_Array_9 = &aux_Array_9_Var;
  aux_Array_9_Refman = LUMI_new_ref((void**)&aux_Array_9, false);
  if (aux_Array_9_Refman == NULL) RAISE(100, 38, "insufficient memory for managed object")
  aux_Array_9_Var.length = 7;
  aux_Array_9_Var.values = (Byte*)((arrf)->values) + (2);
  if (arrf == NULL) RAISE(100, 17, "empty object used")
  if (arrf_Refman->value == NULL) RAISE(100, 28, "outdated weak reference used")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrf)->length) RAISE(100, 25, "slice index out of bounds")
  aux_Ref_Manager = *arrfo_Refman;
  *arrfo_Refman = arrf_Refman;
  LUMI_inc_ref(*arrfo_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *arrfo = aux_Array_9;
  if (arrf == NULL) RAISE(101, 17, "empty object used")
  if (arrf_Refman->value == NULL) RAISE(101, 28, "outdated weak reference used")
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(101, 25, "slice index out of bounds")
  if (((Returncode (**)(void))((arrf)->values))[4] == NULL) RAISE(101, 21, "empty function called")
  LUMI_err = (((Returncode (**)(void))((arrf)->values))[4])();
  CHECK(101)
  if (*arrfo == NULL) RAISE(102, 17, "empty object used")
  if ((*arrfo_Refman)->value == NULL) RAISE(102, 28, "outdated weak reference used")
  if ((4) < 0 || (4) >= ((*arrfo))->length) RAISE(102, 25, "slice index out of bounds")
  if (((Returncode (**)(void))(((*arrfo))->values))[4] == NULL) RAISE(102, 21, "empty function called")
  LUMI_err = (((Returncode (**)(void))(((*arrfo))->values))[4])();
  CHECK(102)
LUMI_cleanup:
  LUMI_dec_ref(aux_Array_9_Refman);
  LUMI_dec_ref(aux_Array_8_Refman);
  LUMI_dec_ref(aux_Array_7_Refman);
  LUMI_dec_ref(aux_Array_6_Refman);
  LUMI_dec_ref(aux_Array_5_Refman);
  LUMI_dec_ref(aux_Array_4_Refman);
  LUMI_dec_ref(aux_Array_3_Refman);
  LUMI_dec_ref(aux_Array_2_Refman);
  LUMI_dec_ref(aux_Array_1_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(aux_Array_0_Refman);
  LUMI_dec_ref(arrf_Refman);
  LUMI_dec_ref(arrd_Refman);
  LUMI_dec_ref(arrt_Refman);
  LUMI_dec_ref(arrs_Refman);
  LUMI_dec_ref(arri_Refman);
  LUMI_dec_ref(s_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-container-expression"
Returncode integration_M_test_container_expression(Int x, Int y, String* s, Ref_Manager* s_Refman, Int* i, Bool* b) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(s_Refman);
  *i = (- x) + (- (- (- y)));
  *b = (! (((! ((((x * 3) - 5) > (6 * y)) && ((6 * y) == 234))) && (! ((5 - x) < y))) || (! ((x == (-2 - (-4 * y))) && (((-6 > y) && (y >= 12)) && (12 == x)))))) && ((((- (2 + x)) > y) || (s != NULL && s_Refman->value != NULL)) || (! (s != NULL && s_Refman->value != NULL)));
LUMI_cleanup:
  LUMI_dec_ref(s_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-variable"
Returncode integration_M_test_variable(Int i, String* text, Ref_Manager* text_Refman, Array* arr, Ref_Manager* arr_Refman) {
  Returncode LUMI_err = OK;
  Int x = 0;
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  Array* a = NULL;
  Ref_Manager* a_Refman = NULL;
  integration_M_TestStruct* t = NULL;
  Ref_Manager* t_Refman = NULL;
  integration_M_TestClass* d = NULL;
  Ref_Manager* d_Refman = NULL;
  integration_M_TestClass_Dynamic* d_Dynamic = NULL;
  integration_M_TestStruct tv_Var = {0};
  integration_M_TestStruct* tv = NULL;
  Ref_Manager* tv_Refman = NULL;
  integration_M_TestClass dv_Var = {0};
  integration_M_TestClass* dv = NULL;
  Ref_Manager* dv_Refman = NULL;
  integration_M_TestClass_Dynamic* dv_Dynamic = &integration_M_TestClass_dynamic;
  char sv_Values[12] = {0};
  String sv_Var = {12, 0, NULL};
  String* sv = NULL;
  Ref_Manager* sv_Refman = NULL;
  Returncode (*f)(Int xi, String* si, Ref_Manager* si_Refman, Int* xo, String** so, Ref_Manager** so_Refman) = NULL;
  Int ia_Values[12] = {0};
  Array ia_Var = {12, NULL};
  Array* ia = NULL;
  Ref_Manager* ia_Refman = NULL;
  integration_M_TestStruct ta_Values[12] = {{0}};
  Array ta_Var = {12, NULL};
  Array* ta = NULL;
  Ref_Manager* ta_Refman = NULL;
  integration_M_TestClass da_Values[12] = {{0}};
  Array da_Var = {12, NULL};
  Array* da = NULL;
  Ref_Manager* da_Refman = NULL;
  char sa_Chars[12 * 7];
  String sa_Values[12] = {{0}};
  Array sa_Var = {12, NULL};
  Array* sa = NULL;
  Ref_Manager* sa_Refman = NULL;
  Returncode (*fa_Values[12])(void) = {0};
  Array fa_Var = {12, NULL};
  Array* fa = NULL;
  Ref_Manager* fa_Refman = NULL;
  integration_M_TestStruct* tn = NULL;
  Ref_Manager* tn_Refman = NULL;
  integration_M_TestClass* dn = NULL;
  Ref_Manager* dn_Refman = NULL;
  integration_M_TestClass_Dynamic* dn_Dynamic = &integration_M_TestClass_dynamic;
  String* sn = NULL;
  Ref_Manager* sn_Refman = NULL;
  Array* ian = NULL;
  Ref_Manager* ian_Refman = NULL;
  Array* tan = NULL;
  Ref_Manager* tan_Refman = NULL;
  Array* dan = NULL;
  Ref_Manager* dan_Refman = NULL;
  Array* san = NULL;
  Ref_Manager* san_Refman = NULL;
  Array* sfn = NULL;
  Ref_Manager* sfn_Refman = NULL;
  Int ix = 0;
  String* si = NULL;
  Ref_Manager* si_Refman = NULL;
  char isv_Values[12] = {0};
  String isv_Var = {12, 0, NULL};
  String* isv = NULL;
  Ref_Manager* isv_Refman = NULL;
  String* isn = NULL;
  Ref_Manager* isn_Refman = NULL;
  Returncode (*fi)(Int x, String** s, Ref_Manager** s_Refman) = NULL;
  integration_M_TestStruct itv_Var = {0};
  integration_M_TestStruct* itv = NULL;
  Ref_Manager* itv_Refman = NULL;
  integration_M_TestStruct* itn = NULL;
  Ref_Manager* itn_Refman = NULL;
  integration_M_TestClass idv_Var = {0};
  integration_M_TestClass* idv = NULL;
  Ref_Manager* idv_Refman = NULL;
  integration_M_TestClass_Dynamic* idv_Dynamic = &integration_M_TestClass_dynamic;
  integration_M_TestClass* idn = NULL;
  Ref_Manager* idn_Refman = NULL;
  integration_M_TestClass_Dynamic* idn_Dynamic = &integration_M_TestClass_dynamic;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  integration_M_TestStruct* aux_TestStruct_0 = NULL;
  Ref_Manager* aux_TestStruct_0_Refman = NULL;
  integration_M_TestClass* aux_TestClass_0 = NULL;
  Ref_Manager* aux_TestClass_0_Refman = NULL;
  integration_M_TestClass_Dynamic* aux_TestClass_0_Dynamic = &integration_M_TestClass_dynamic;
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  Array* aux_Array_1 = NULL;
  Ref_Manager* aux_Array_1_Refman = NULL;
  Array* aux_Array_2 = NULL;
  Ref_Manager* aux_Array_2_Refman = NULL;
  Array* aux_Array_3 = NULL;
  Ref_Manager* aux_Array_3_Refman = NULL;
  Array* aux_Array_4 = NULL;
  Ref_Manager* aux_Array_4_Refman = NULL;
  String* aux_String_2 = NULL;
  Ref_Manager* aux_String_2_Refman = NULL;
  LUMI_inc_ref(text_Refman);
  LUMI_inc_ref(arr_Refman);
  tv = &tv_Var;
  tv_Refman = LUMI_new_ref((void**)&tv, false);
  if (tv_Refman == NULL) RAISE(119, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(tv, tv_Refman, 0, NULL, NULL);
  CHECK(119)
  dv = &dv_Var;
  dv_Refman = LUMI_new_ref((void**)&dv, false);
  if (dv_Refman == NULL) RAISE(120, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestClass_new(dv, dv_Refman, dv_Dynamic);
  CHECK(120)
  sv = &sv_Var;
  sv_Var.values = sv_Values;
  sv_Refman = LUMI_new_ref((void**)&sv, false);
  if (sv_Refman == NULL) RAISE(121, 38, "insufficient memory for managed object")
  ia = &ia_Var;
  ia_Var.values = ia_Values;
  ia_Refman = LUMI_new_ref((void**)&ia, false);
  if (ia_Refman == NULL) RAISE(123, 38, "insufficient memory for managed object")
  ta = &ta_Var;
  ta_Var.values = ta_Values;
  ta_Refman = LUMI_new_ref((void**)&ta, false);
  if (ta_Refman == NULL) RAISE(124, 38, "insufficient memory for managed object")
  da = &da_Var;
  da_Var.values = da_Values;
  da_Refman = LUMI_new_ref((void**)&da, false);
  if (da_Refman == NULL) RAISE(125, 38, "insufficient memory for managed object")
  sa = &sa_Var;
  sa_Var.values = sa_Values;
  LUMI_set_var_string_array(12, 7, sa, sa_Chars);
  sa_Refman = LUMI_new_ref((void**)&sa, false);
  if (sa_Refman == NULL) RAISE(126, 38, "insufficient memory for managed object")
  fa = &fa_Var;
  fa_Var.values = fa_Values;
  fa_Refman = LUMI_new_ref((void**)&fa, false);
  if (fa_Refman == NULL) RAISE(127, 38, "insufficient memory for managed object")
  tn = LUMI_alloc(sizeof(integration_M_TestStruct));
  if (tn == NULL) RAISE(128, 49, "insufficient memory for object dynamic allocation")
  tn_Refman = LUMI_new_ref((void**)&tn, true);
  if (tn_Refman == NULL) RAISE(128, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(tn, tn_Refman, 0, NULL, NULL);
  CHECK(128)
  dn = LUMI_alloc(sizeof(integration_M_TestClass));
  if (dn == NULL) RAISE(129, 49, "insufficient memory for object dynamic allocation")
  dn_Refman = LUMI_new_ref((void**)&dn, true);
  if (dn_Refman == NULL) RAISE(129, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestClass_new(dn, dn_Refman, dn_Dynamic);
  CHECK(129)
  if (arr == NULL) RAISE(130, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(130, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(130, 25, "slice index out of bounds")
  sn = LUMI_new_string(((Int*)((arr)->values))[0]);
  if (sn == NULL) RAISE(130, 49, "insufficient memory for object dynamic allocation")
  sn_Refman = LUMI_new_ref((void**)&sn, true);
  if (sn_Refman == NULL) RAISE(130, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(131, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(131, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(131, 25, "slice index out of bounds")
  ian = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if (ian == NULL) RAISE(131, 49, "insufficient memory for object dynamic allocation")
  ian_Refman = LUMI_new_ref((void**)&ian, true);
  if (ian_Refman == NULL) RAISE(131, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(132, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(132, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(132, 25, "slice index out of bounds")
  tan = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(integration_M_TestStruct));
  if (tan == NULL) RAISE(132, 49, "insufficient memory for object dynamic allocation")
  tan_Refman = LUMI_new_ref((void**)&tan, true);
  if (tan_Refman == NULL) RAISE(132, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(133, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(133, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(133, 25, "slice index out of bounds")
  dan = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(integration_M_TestClass));
  if (dan == NULL) RAISE(133, 49, "insufficient memory for object dynamic allocation")
  dan_Refman = LUMI_new_ref((void**)&dan, true);
  if (dan_Refman == NULL) RAISE(133, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(134, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(134, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(134, 25, "slice index out of bounds")
  if (arr == NULL) RAISE(134, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(134, 28, "outdated weak reference used")
  if ((1) < 0 || (1) >= (arr)->length) RAISE(134, 25, "slice index out of bounds")
  san = LUMI_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]);
  if (san == NULL) RAISE(134, 49, "insufficient memory for object dynamic allocation")
  san_Refman = LUMI_new_ref((void**)&san, true);
  if (san_Refman == NULL) RAISE(134, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(135, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(135, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(135, 25, "slice index out of bounds")
  sfn = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(Func));
  if (sfn == NULL) RAISE(135, 49, "insufficient memory for object dynamic allocation")
  sfn_Refman = LUMI_new_ref((void**)&sfn, true);
  if (sfn_Refman == NULL) RAISE(135, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(136, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(136, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(136, 25, "slice index out of bounds")
  ix = ((Int*)((arr)->values))[0];
  si = text;
  si_Refman = text_Refman;
  LUMI_inc_ref(si_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref((void**)&aux_String_0, false);
  if (aux_String_0_Refman == NULL) RAISE(138, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  isv = &isv_Var;
  isv_Var.values = isv_Values;
  isv_Refman = LUMI_new_ref((void**)&isv, false);
  if (isv_Refman == NULL) RAISE(138, 38, "insufficient memory for managed object")
  LUMI_err = String_new(isv, isv_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(138)
  isn = LUMI_new_string(i);
  if (isn == NULL) RAISE(139, 49, "insufficient memory for object dynamic allocation")
  isn_Refman = LUMI_new_ref((void**)&isn, true);
  if (isn_Refman == NULL) RAISE(139, 38, "insufficient memory for managed object")
  LUMI_err = String_new(isn, isn_Refman, text, text_Refman);
  CHECK(139)
  fi = integration_M_f_test_int2str;
  itv = &itv_Var;
  itv_Refman = LUMI_new_ref((void**)&itv, false);
  if (itv_Refman == NULL) RAISE(141, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(itv, itv_Refman, i, text, text_Refman);
  CHECK(141)
  itn = LUMI_alloc(sizeof(integration_M_TestStruct));
  if (itn == NULL) RAISE(142, 49, "insufficient memory for object dynamic allocation")
  itn_Refman = LUMI_new_ref((void**)&itn, true);
  if (itn_Refman == NULL) RAISE(142, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(itn, itn_Refman, i, text, text_Refman);
  CHECK(142)
  idv = &idv_Var;
  idv_Refman = LUMI_new_ref((void**)&idv, false);
  if (idv_Refman == NULL) RAISE(143, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestClass_new(idv, idv_Refman, idv_Dynamic);
  CHECK(143)
  idn = LUMI_alloc(sizeof(integration_M_TestClass));
  if (idn == NULL) RAISE(144, 49, "insufficient memory for object dynamic allocation")
  idn_Refman = LUMI_new_ref((void**)&idn, true);
  if (idn_Refman == NULL) RAISE(144, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestClass_new(idn, idn_Refman, idn_Dynamic);
  CHECK(144)
  aux_TestStruct_0 = LUMI_alloc(sizeof(integration_M_TestStruct));
  if (aux_TestStruct_0 == NULL) RAISE(145, 49, "insufficient memory for object dynamic allocation")
  aux_TestStruct_0_Refman = LUMI_new_ref((void**)&aux_TestStruct_0, true);
  if (aux_TestStruct_0_Refman == NULL) RAISE(145, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(aux_TestStruct_0, aux_TestStruct_0_Refman, i, text, text_Refman);
  CHECK(145)
  LUMI_err = integration_M_TestStruct_print(aux_TestStruct_0, aux_TestStruct_0_Refman);
  CHECK(145)
  aux_TestClass_0 = LUMI_alloc(sizeof(integration_M_TestClass));
  if (aux_TestClass_0 == NULL) RAISE(146, 49, "insufficient memory for object dynamic allocation")
  aux_TestClass_0_Refman = LUMI_new_ref((void**)&aux_TestClass_0, true);
  if (aux_TestClass_0_Refman == NULL) RAISE(146, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestClass_new(aux_TestClass_0, aux_TestClass_0_Refman, aux_TestClass_0_Dynamic);
  CHECK(146)
  LUMI_err = integration_M_TestClass_print(aux_TestClass_0, aux_TestClass_0_Refman, aux_TestClass_0_Dynamic);
  CHECK(146)
  if (arr == NULL) RAISE(147, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(147, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(147, 25, "slice index out of bounds")
  aux_String_1 = LUMI_new_string(((Int*)((arr)->values))[0]);
  if (aux_String_1 == NULL) RAISE(147, 49, "insufficient memory for object dynamic allocation")
  aux_String_1_Refman = LUMI_new_ref((void**)&aux_String_1, true);
  if (aux_String_1_Refman == NULL) RAISE(147, 38, "insufficient memory for managed object")
  TEST_ASSERT(147, aux_String_1 != NULL && aux_String_1_Refman->value != NULL)
  if (arr == NULL) RAISE(148, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(148, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(148, 25, "slice index out of bounds")
  aux_Array_0 = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if (aux_Array_0 == NULL) RAISE(148, 49, "insufficient memory for object dynamic allocation")
  aux_Array_0_Refman = LUMI_new_ref((void**)&aux_Array_0, true);
  if (aux_Array_0_Refman == NULL) RAISE(148, 38, "insufficient memory for managed object")
  TEST_ASSERT(148, aux_Array_0 != NULL && aux_Array_0_Refman->value != NULL)
  if (arr == NULL) RAISE(149, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(149, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(149, 25, "slice index out of bounds")
  aux_Array_1 = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(integration_M_TestStruct));
  if (aux_Array_1 == NULL) RAISE(149, 49, "insufficient memory for object dynamic allocation")
  aux_Array_1_Refman = LUMI_new_ref((void**)&aux_Array_1, true);
  if (aux_Array_1_Refman == NULL) RAISE(149, 38, "insufficient memory for managed object")
  TEST_ASSERT(149, aux_Array_1 != NULL && aux_Array_1_Refman->value != NULL)
  if (arr == NULL) RAISE(150, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(150, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(150, 25, "slice index out of bounds")
  aux_Array_2 = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(integration_M_TestClass));
  if (aux_Array_2 == NULL) RAISE(150, 49, "insufficient memory for object dynamic allocation")
  aux_Array_2_Refman = LUMI_new_ref((void**)&aux_Array_2, true);
  if (aux_Array_2_Refman == NULL) RAISE(150, 38, "insufficient memory for managed object")
  TEST_ASSERT(150, aux_Array_2 != NULL && aux_Array_2_Refman->value != NULL)
  if (arr == NULL) RAISE(151, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(151, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(151, 25, "slice index out of bounds")
  if (arr == NULL) RAISE(151, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(151, 28, "outdated weak reference used")
  if ((1) < 0 || (1) >= (arr)->length) RAISE(151, 25, "slice index out of bounds")
  aux_Array_3 = LUMI_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]);
  if (aux_Array_3 == NULL) RAISE(151, 49, "insufficient memory for object dynamic allocation")
  aux_Array_3_Refman = LUMI_new_ref((void**)&aux_Array_3, true);
  if (aux_Array_3_Refman == NULL) RAISE(151, 38, "insufficient memory for managed object")
  TEST_ASSERT(151, aux_Array_3 != NULL && aux_Array_3_Refman->value != NULL)
  if (arr == NULL) RAISE(152, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(152, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(152, 25, "slice index out of bounds")
  aux_Array_4 = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(Func));
  if (aux_Array_4 == NULL) RAISE(152, 49, "insufficient memory for object dynamic allocation")
  aux_Array_4_Refman = LUMI_new_ref((void**)&aux_Array_4, true);
  if (aux_Array_4_Refman == NULL) RAISE(152, 38, "insufficient memory for managed object")
  TEST_ASSERT(152, aux_Array_4 != NULL && aux_Array_4_Refman->value != NULL)
  TEST_ASSERT(153, x == 0)
  TEST_ASSERT(154, s != NULL && s_Refman->value != NULL)
  TEST_ASSERT(155, a != NULL && a_Refman->value != NULL)
  LUMI_err = integration_M_TestStruct_print(t, t_Refman);
  CHECK(156)
  LUMI_err = integration_M_TestClass_print(d, d_Refman, d_Dynamic);
  CHECK(157)
  TEST_ASSERT(158, f != NULL)
  LUMI_err = integration_M_TestStruct_print(tv, tv_Refman);
  CHECK(159)
  LUMI_err = integration_M_TestClass_print(dv, dv_Refman, dv_Dynamic);
  CHECK(160)
  TEST_ASSERT(161, sv != NULL && sv_Refman->value != NULL)
  TEST_ASSERT(162, ia != NULL && ia_Refman->value != NULL)
  TEST_ASSERT(163, ta != NULL && ta_Refman->value != NULL)
  TEST_ASSERT(164, da != NULL && da_Refman->value != NULL)
  TEST_ASSERT(165, sa != NULL && sa_Refman->value != NULL)
  TEST_ASSERT(166, fa != NULL && fa_Refman->value != NULL)
  LUMI_err = integration_M_TestStruct_print(tn, tn_Refman);
  CHECK(167)
  LUMI_err = integration_M_TestClass_print(dn, dn_Refman, dn_Dynamic);
  CHECK(168)
  TEST_ASSERT(169, sn != NULL && sn_Refman->value != NULL)
  TEST_ASSERT(170, ian != NULL && ian_Refman->value != NULL)
  TEST_ASSERT(171, tan != NULL && tan_Refman->value != NULL)
  TEST_ASSERT(172, dan != NULL && dan_Refman->value != NULL)
  TEST_ASSERT(173, san != NULL && san_Refman->value != NULL)
  TEST_ASSERT(174, sfn != NULL && sfn_Refman->value != NULL)
  TEST_ASSERT(175, ix == 0)
  TEST_ASSERT(176, si != NULL && si_Refman->value != NULL)
  if (fi == NULL) RAISE(177, 21, "empty function called")
  LUMI_err = fi(7, &(aux_String_2), &(aux_String_2_Refman));
  CHECK(177)
  TEST_ASSERT(178, isv != NULL && isv_Refman->value != NULL)
  TEST_ASSERT(179, isn != NULL && isn_Refman->value != NULL)
LUMI_cleanup:
  String_Del(aux_String_2);
  LUMI_owner_dec_ref(aux_String_2_Refman);
  LUMI_owner_dec_ref(aux_Array_4_Refman);
  ARRAY_DEL(String, aux_Array_3)
  LUMI_owner_dec_ref(aux_Array_3_Refman);
  ARRAY_DEL(integration_M_TestClass, aux_Array_2)
  LUMI_owner_dec_ref(aux_Array_2_Refman);
  ARRAY_DEL(integration_M_TestStruct, aux_Array_1)
  LUMI_owner_dec_ref(aux_Array_1_Refman);
  LUMI_owner_dec_ref(aux_Array_0_Refman);
  String_Del(aux_String_1);
  LUMI_owner_dec_ref(aux_String_1_Refman);
  if (aux_TestClass_0_Dynamic != NULL) aux_TestClass_0_Dynamic->_del(aux_TestClass_0);
  LUMI_owner_dec_ref(aux_TestClass_0_Refman);
  integration_M_TestStruct_Del(aux_TestStruct_0);
  LUMI_owner_dec_ref(aux_TestStruct_0_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  if (idn_Dynamic != NULL) idn_Dynamic->_del(idn);
  LUMI_owner_dec_ref(idn_Refman);
  LUMI_dec_ref(idv_Refman);
  integration_M_TestStruct_Del(itn);
  LUMI_owner_dec_ref(itn_Refman);
  LUMI_dec_ref(itv_Refman);
  String_Del(isn);
  LUMI_owner_dec_ref(isn_Refman);
  LUMI_dec_ref(isv_Refman);
  LUMI_dec_ref(si_Refman);
  LUMI_owner_dec_ref(sfn_Refman);
  ARRAY_DEL(String, san)
  LUMI_owner_dec_ref(san_Refman);
  ARRAY_DEL(integration_M_TestClass, dan)
  LUMI_owner_dec_ref(dan_Refman);
  ARRAY_DEL(integration_M_TestStruct, tan)
  LUMI_owner_dec_ref(tan_Refman);
  LUMI_owner_dec_ref(ian_Refman);
  String_Del(sn);
  LUMI_owner_dec_ref(sn_Refman);
  if (dn_Dynamic != NULL) dn_Dynamic->_del(dn);
  LUMI_owner_dec_ref(dn_Refman);
  integration_M_TestStruct_Del(tn);
  LUMI_owner_dec_ref(tn_Refman);
  LUMI_dec_ref(fa_Refman);
  LUMI_dec_ref(sa_Refman);
  LUMI_dec_ref(da_Refman);
  LUMI_dec_ref(ta_Refman);
  LUMI_dec_ref(ia_Refman);
  LUMI_dec_ref(sv_Refman);
  LUMI_dec_ref(dv_Refman);
  LUMI_dec_ref(tv_Refman);
  LUMI_dec_ref(d_Refman);
  LUMI_dec_ref(t_Refman);
  LUMI_owner_dec_ref(a_Refman);
  LUMI_dec_ref(s_Refman);
  LUMI_dec_ref(arr_Refman);
  LUMI_dec_ref(text_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-complex-function"
Returncode integration_M_test_complex_function(Int num, String* text, Ref_Manager* text_Refman, Int* out_num, String** out_text, Ref_Manager** out_text_Refman) {
  Returncode LUMI_err = OK;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(text_Refman);
  *out_num = num;
  aux_Ref_Manager = *out_text_Refman;
  *out_text_Refman = text_Refman;
  LUMI_inc_ref(*out_text_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *out_text = text;
LUMI_cleanup:
  LUMI_dec_ref(text_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "f-test-void"
Returncode integration_M_f_test_void(void) {
  Returncode LUMI_err = OK;
  goto LUMI_cleanup;
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "f-test-params"
Returncode integration_M_f_test_params(Int x, String* s, Ref_Manager* s_Refman, String* o, Ref_Manager* o_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(s_Refman);
  USER_RAISE(250, NULL, NULL)
LUMI_cleanup:
  String_Del(o);
  LUMI_owner_dec_ref(o_Refman);
  LUMI_dec_ref(s_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "f-test-outs"
Returncode integration_M_f_test_outs(String** s, Ref_Manager** s_Refman, Int* x) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "f-test-int2str"
Returncode integration_M_f_test_int2str(Int x, String** s, Ref_Manager** s_Refman) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "f-test-int"
Returncode integration_M_f_test_int(Int x) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "f-test-int2int"
Returncode integration_M_f_test_int2int(Int x, Int* r) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "f-test-many"
Returncode integration_M_f_test_many(Int x, Int y, Int* n, Int* m) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-call-expression"
Returncode integration_M_test_call_expression(void) {
  Returncode LUMI_err = OK;
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  Int x = 0;
  Int tmp = 0;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  Int aux_Int_0 = 0;
  Int aux_Int_1 = 0;
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  String* aux_String_2 = NULL;
  Ref_Manager* aux_String_2_Refman = NULL;
  LUMI_err = integration_M_f_test_void();
  CHECK(265)
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref((void**)&aux_String_0, false);
  if (aux_String_0_Refman == NULL) RAISE(266, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 5;
  aux_String_0_Var.length = 4;
  aux_String_0_Var.values = "text";
  LUMI_err = integration_M_f_test_params(3, aux_String_0, aux_String_0_Refman, NULL, NULL);
  CHECK(266)
  LUMI_err = integration_M_f_test_outs(&(s), &(s_Refman), &(x));
  CHECK(267)
  LUMI_err = integration_M_f_test_int2str(4, &(s), &(s_Refman));
  CHECK(268)
  LUMI_err = integration_M_f_test_int(5);
  CHECK(269)
  LUMI_err = integration_M_f_test_int2int(6, &(x));
  CHECK(270)
  LUMI_err = integration_M_f_test_many(7, 8, &(x), &(x));
  CHECK(271)
  LUMI_err = integration_M_f_test_int2int(9, &(tmp));
  CHECK(277)
  LUMI_err = integration_M_f_test_int(tmp);
  CHECK(277)
  LUMI_err = integration_M_f_test_many(11, 12, &(x), &(aux_Int_0));
  CHECK(278)
  LUMI_err = integration_M_f_test_int2int(10, &(aux_Int_1));
  CHECK(278)
  x = aux_Int_1 + aux_Int_0;
  LUMI_err = integration_M_f_test_int2str(13, &(aux_String_1), &(aux_String_1_Refman));
  CHECK(279)
  aux_String_2 = aux_String_1;
  aux_String_2_Refman = aux_String_1_Refman;
  aux_String_1 = NULL;
  aux_String_1_Refman = NULL;
  String_Del(s);
  LUMI_owner_dec_ref(s_Refman);
  s_Refman = aux_String_2_Refman;
  s = aux_String_2;
  aux_String_2 = NULL;
  aux_String_2_Refman = NULL;
LUMI_cleanup:
  String_Del(aux_String_2);
  LUMI_owner_dec_ref(aux_String_2_Refman);
  String_Del(aux_String_1);
  LUMI_owner_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  String_Del(s);
  LUMI_owner_dec_ref(s_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-code-flow"
Returncode integration_M_test_code_flow(Array* arr, Ref_Manager* arr_Refman, Int* res) {
  Returncode LUMI_err = OK;
  Int x = 0;
  Int y = 0;
  Int z = 0;
  Int w = 0;
  Int n = 0;
  Array aux_Array_0_Var = {0};
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  LUMI_inc_ref(arr_Refman);
  if (arr == NULL) RAISE(283, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(283, 28, "outdated weak reference used")
  if ((4) < 0 || (4) >= (arr)->length) RAISE(283, 25, "slice index out of bounds")
  if ((((Int*)((arr)->values))[4]) > 6) {
    *res = 6;
  }
  else {
    if (arr != NULL && arr_Refman->value != NULL) {
      *res = 6;
    }
    else {
      if (arr == NULL) RAISE(287, 17, "empty object used")
      if (arr_Refman->value == NULL) RAISE(287, 28, "outdated weak reference used")
      if ((5) < 0 || (5) >= (arr)->length) RAISE(287, 25, "slice index out of bounds")
      if (arr == NULL) RAISE(287, 17, "empty object used")
      if (arr_Refman->value == NULL) RAISE(287, 28, "outdated weak reference used")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(287, 25, "slice index out of bounds")
      if ((((Int*)((arr)->values))[4]) != (((Int*)((arr)->values))[5])) {
        *res = 6;
      }
      else {
        if (arr == NULL) RAISE(289, 17, "empty object used")
        if (arr_Refman->value == NULL) RAISE(289, 28, "outdated weak reference used")
        if ((0) < 0 || (0) >= (arr)->length) RAISE(289, 25, "slice index out of bounds")
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
    if (arr == NULL) RAISE(294, 17, "empty object used")
    if (arr_Refman->value == NULL) RAISE(294, 28, "outdated weak reference used")
    if ((6) < 0 || (6) >= (arr)->length) RAISE(294, 25, "slice index out of bounds")
    ((Int*)((arr)->values))[6] = 6;
    if (arr == NULL) RAISE(295, 17, "empty object used")
    if (arr_Refman->value == NULL) RAISE(295, 28, "outdated weak reference used")
    if ((2) < 0 || (2) >= (arr)->length) RAISE(295, 25, "slice index out of bounds")
    x = ((Int*)((arr)->values))[2];
    if (!((x > 3) && ((void*)arr == NULL))) break;
    y = x - 1;
    while (true) {
      if (arr == NULL) RAISE(299, 17, "empty object used")
      if (arr_Refman->value == NULL) RAISE(299, 28, "outdated weak reference used")
      if ((8) < 0 || (8) >= (arr)->length) RAISE(299, 25, "slice index out of bounds")
      if (arr == NULL) RAISE(299, 17, "empty object used")
      if (arr_Refman->value == NULL) RAISE(299, 28, "outdated weak reference used")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(299, 25, "slice index out of bounds")
      ((Int*)((arr)->values))[4] = ((Int*)((arr)->values))[8];
      if (arr == NULL) RAISE(300, 17, "empty object used")
      if (arr_Refman->value == NULL) RAISE(300, 28, "outdated weak reference used")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(300, 25, "slice index out of bounds")
      if (y > (((Int*)((arr)->values))[4])) {
        continue;
      }
      z = 7;
      if (arr == NULL) RAISE(303, 17, "empty object used")
      if (arr_Refman->value == NULL) RAISE(303, 28, "outdated weak reference used")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(303, 25, "slice index out of bounds")
      if (z <= (((Int*)((arr)->values))[4])) {
        if (!(z > 0)) break;
      }
    }
  }
  if (arr == NULL) RAISE(305, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(305, 28, "outdated weak reference used")
  if ((2) < 0 || (2) >= (arr)->length) RAISE(305, 25, "slice index out of bounds")
  if (arr == NULL) RAISE(305, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(305, 28, "outdated weak reference used")
  if ((2) < 0 || (2) >= (arr)->length) RAISE(305, 25, "slice index out of bounds")
  for (n = ((Int*)((arr)->values))[2]; n < 2 - (3 * (((Int*)((arr)->values))[2])); ++n) {
    if (arr == NULL) RAISE(306, 17, "empty object used")
    if (arr_Refman->value == NULL) RAISE(306, 28, "outdated weak reference used")
    if ((2) < 0 || (2) >= (arr)->length) RAISE(306, 25, "slice index out of bounds")
    if (arr == NULL) RAISE(306, 17, "empty object used")
    if (arr_Refman->value == NULL) RAISE(306, 28, "outdated weak reference used")
    if ((0) < 0 || (0) >= (arr)->length) RAISE(306, 25, "slice index out of bounds")
    ((Int*)((arr)->values))[0] = ((Int*)((arr)->values))[2];
    if (arr == NULL) RAISE(307, 17, "empty object used")
    if (arr_Refman->value == NULL) RAISE(307, 28, "outdated weak reference used")
    if ((0) < 0 || (0) >= (arr)->length) RAISE(307, 25, "slice index out of bounds")
    w = ((Int*)((arr)->values))[0];
    aux_Array_0 = &aux_Array_0_Var;
    aux_Array_0_Refman = LUMI_new_ref((void**)&aux_Array_0, false);
    if (aux_Array_0_Refman == NULL) RAISE(308, 38, "insufficient memory for managed object")
    aux_Array_0_Var.length = 2;
    aux_Array_0_Var.values = (Byte*)((arr)->values) + (3);
    if (arr == NULL) RAISE(308, 17, "empty object used")
    if (arr_Refman->value == NULL) RAISE(308, 28, "outdated weak reference used")
    if ((3) < 0 || (2) < 0 || (3) + (2) > (arr)->length) RAISE(308, 25, "slice index out of bounds")
    if ((w > 4) && ((void*)arr != aux_Array_0)) {
      if (arr == NULL) RAISE(309, 17, "empty object used")
      if (arr_Refman->value == NULL) RAISE(309, 28, "outdated weak reference used")
      if ((1) < 0 || (1) >= (arr)->length) RAISE(309, 25, "slice index out of bounds")
      ((Int*)((arr)->values))[1] = w;
    }
  }
LUMI_cleanup:
  LUMI_dec_ref(aux_Array_0_Refman);
  LUMI_dec_ref(arr_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-builtins"
Returncode integration_M_test_builtins(Int i, Char c, Bool b, String* s, Ref_Manager* s_Refman, Array* a, Ref_Manager* a_Refman) {
  Returncode LUMI_err = OK;
  Int iv = 0;
  Char cv = 0;
  Bool bv = 0;
  File* f = NULL;
  Ref_Manager* f_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(s_Refman);
  LUMI_inc_ref(a_Refman);
  LUMI_err = Int_str(i, s, s_Refman);
  CHECK(317)
  bv = true || false;
  if (a == NULL) RAISE(319, 17, "empty object used")
  if (a_Refman->value == NULL) RAISE(319, 28, "outdated weak reference used")
  i = a->length;
  if (s == NULL) RAISE(320, 17, "empty object used")
  if (s_Refman->value == NULL) RAISE(320, 28, "outdated weak reference used")
  i = s->length;
  LUMI_err = String_clear(s, s_Refman);
  CHECK(321)
  LUMI_err = String_equal(s, s_Refman, s, s_Refman, &(bv));
  CHECK(322)
  LUMI_err = String_get(s, s_Refman, i, &(cv));
  CHECK(323)
  LUMI_err = String_append(s, s_Refman, c);
  CHECK(324)
  LUMI_err = String_new(s, s_Refman, s, s_Refman);
  CHECK(325)
  LUMI_err = String_concat(s, s_Refman, s, s_Refman);
  CHECK(326)
  LUMI_err = String_concat_int(s, s_Refman, i);
  CHECK(327)
  LUMI_err = String_find(s, s_Refman, s, s_Refman, &(iv));
  CHECK(328)
  LUMI_err = String_has(s, s_Refman, c, &(bv));
  CHECK(329)
  LUMI_err = file_open_read(s, s_Refman, &(f), &(f_Refman));
  CHECK(331)
  LUMI_err = file_open_write(s, s_Refman, &(f), &(f_Refman));
  CHECK(332)
  LUMI_err = File_getc(f, f_Refman, &(cv), &(bv));
  CHECK(333)
  LUMI_err = File_putc(f, f_Refman, c);
  CHECK(334)
  LUMI_err = File_write(f, f_Refman, s, s_Refman);
  CHECK(335)
  LUMI_err = file_close(f, f_Refman);
  f = NULL;
  f_Refman = NULL;
  CHECK(336)
  if (sys == NULL) RAISE(337, 17, "empty object used")
  if (sys_Refman->value == NULL) RAISE(337, 28, "outdated weak reference used")
  if (sys->argv == NULL) RAISE(337, 17, "empty object used")
  if (sys->argv_Refman->value == NULL) RAISE(337, 28, "outdated weak reference used")
  if ((1) < 0 || (1) >= (sys->argv)->length) RAISE(337, 25, "slice index out of bounds")
  aux_Ref_Manager = s_Refman;
  s_Refman = sys->argv_Refman;
  LUMI_inc_ref(s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  s = ((String*)((sys->argv)->values)) + 1;
  LUMI_err = Sys_print(sys, sys_Refman, s, s_Refman);
  CHECK(338)
  LUMI_err = Sys_println(sys, sys_Refman, s, s_Refman);
  CHECK(339)
  LUMI_err = Sys_getchar(sys, sys_Refman, &(cv), &(bv));
  CHECK(340)
  LUMI_err = Sys_getline(sys, sys_Refman, s, s_Refman);
  CHECK(341)
  LUMI_err = Sys_getenv(sys, sys_Refman, s, s_Refman, s, s_Refman, &(bv));
  CHECK(342)
  LUMI_err = Sys_system(sys, sys_Refman, s, s_Refman, &(iv));
  CHECK(343)
  LUMI_err = Sys_exit(sys, sys_Refman, i);
  CHECK(344)
  if (sys == NULL) RAISE(345, 17, "empty object used")
  if (sys_Refman->value == NULL) RAISE(345, 28, "outdated weak reference used")
  LUMI_err = File_putc(sys->stdout_Cname, sys->stdout_Cname_Refman, c);
  CHECK(345)
  if (sys == NULL) RAISE(346, 17, "empty object used")
  if (sys_Refman->value == NULL) RAISE(346, 28, "outdated weak reference used")
  LUMI_err = File_getc(sys->stdin_Cname, sys->stdin_Cname_Refman, &(cv), &(bv));
  CHECK(346)
  if (sys == NULL) RAISE(347, 17, "empty object used")
  if (sys_Refman->value == NULL) RAISE(347, 28, "outdated weak reference used")
  LUMI_err = File_putc(sys->stderr_Cname, sys->stderr_Cname_Refman, c);
  CHECK(347)
LUMI_cleanup:
  File_Del(f);
  LUMI_owner_dec_ref(f_Refman);
  LUMI_dec_ref(a_Refman);
  LUMI_dec_ref(s_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-ref-count"
Returncode integration_M_test_ref_count(void) {
  Returncode LUMI_err = OK;
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  String* s_user = NULL;
  Ref_Manager* s_user_Refman = NULL;
  integration_M_TestStruct* ts = NULL;
  Ref_Manager* ts_Refman = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  String aux_String_2_Var = {0};
  String* aux_String_2 = NULL;
  Ref_Manager* aux_String_2_Refman = NULL;
  String aux_String_3_Var = {0};
  String* aux_String_3 = NULL;
  Ref_Manager* aux_String_3_Refman = NULL;
  integration_M_TestStruct* aux_TestStruct_0 = NULL;
  Ref_Manager* aux_TestStruct_0_Refman = NULL;
  String aux_String_4_Var = {0};
  String* aux_String_4 = NULL;
  Ref_Manager* aux_String_4_Refman = NULL;
  integration_M_TestStruct* aux_TestStruct_1 = NULL;
  Ref_Manager* aux_TestStruct_1_Refman = NULL;
  integration_M_TestStruct* aux_TestStruct_2 = NULL;
  Ref_Manager* aux_TestStruct_2_Refman = NULL;
  integration_M_TestStruct* aux_TestStruct_3 = NULL;
  Ref_Manager* aux_TestStruct_3_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref((void**)&aux_String_0, false);
  if (aux_String_0_Refman == NULL) RAISE(351, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "test string";
  s = LUMI_new_string(32);
  if (s == NULL) RAISE(351, 49, "insufficient memory for object dynamic allocation")
  s_Refman = LUMI_new_ref((void**)&s, true);
  if (s_Refman == NULL) RAISE(351, 38, "insufficient memory for managed object")
  LUMI_err = String_new(s, s_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(351)
  s_user = s;
  s_user_Refman = s_Refman;
  LUMI_inc_ref(s_user_Refman);
  LUMI_err = Sys_println(sys, sys_Refman, s, s_Refman);
  CHECK(353)
  LUMI_err = Sys_println(sys, sys_Refman, s_user, s_user_Refman);
  CHECK(354)
  LUMI_err = integration_M_f_remove(s, s_Refman);
  s = NULL;
  s_Refman = NULL;
  CHECK(355)
  if (! (s != NULL && s_Refman->value != NULL)) {
    aux_String_1 = &aux_String_1_Var;
    aux_String_1_Refman = LUMI_new_ref((void**)&aux_String_1, false);
    if (aux_String_1_Refman == NULL) RAISE(357, 38, "insufficient memory for managed object")
    aux_String_1_Var.max_length = 17;
    aux_String_1_Var.length = 16;
    aux_String_1_Var.values = "ownership passed";
    LUMI_err = Sys_println(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
    CHECK(357)
  }
  if (! (s_user != NULL && s_user_Refman->value != NULL)) {
    aux_String_2 = &aux_String_2_Var;
    aux_String_2_Refman = LUMI_new_ref((void**)&aux_String_2, false);
    if (aux_String_2_Refman == NULL) RAISE(359, 38, "insufficient memory for managed object")
    aux_String_2_Var.max_length = 15;
    aux_String_2_Var.length = 14;
    aux_String_2_Var.values = "string deleted";
    LUMI_err = Sys_println(sys, sys_Refman, aux_String_2, aux_String_2_Refman);
    CHECK(359)
  }
  aux_String_3 = &aux_String_3_Var;
  aux_String_3_Refman = LUMI_new_ref((void**)&aux_String_3, false);
  if (aux_String_3_Refman == NULL) RAISE(360, 38, "insufficient memory for managed object")
  aux_String_3_Var.max_length = 13;
  aux_String_3_Var.length = 12;
  aux_String_3_Var.values = "first struct";
  ts = LUMI_alloc(sizeof(integration_M_TestStruct));
  if (ts == NULL) RAISE(360, 49, "insufficient memory for object dynamic allocation")
  ts_Refman = LUMI_new_ref((void**)&ts, true);
  if (ts_Refman == NULL) RAISE(360, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(ts, ts_Refman, 0, aux_String_3, aux_String_3_Refman);
  CHECK(360)
  aux_TestStruct_0 = ts;
  aux_TestStruct_0_Refman = ts_Refman;
  ts = NULL;
  ts_Refman = NULL;
  integration_M_TestStruct_Del(ts);
  LUMI_owner_dec_ref(ts_Refman);
  ts_Refman = aux_TestStruct_0_Refman;
  ts = aux_TestStruct_0;
  aux_TestStruct_0 = NULL;
  aux_TestStruct_0_Refman = NULL;
  if (ts == NULL) RAISE(362, 17, "empty object used")
  if (ts_Refman->value == NULL) RAISE(362, 28, "outdated weak reference used")
  LUMI_err = Sys_println(sys, sys_Refman, ts->text, ts->text_Refman);
  CHECK(362)
  aux_String_4 = &aux_String_4_Var;
  aux_String_4_Refman = LUMI_new_ref((void**)&aux_String_4, false);
  if (aux_String_4_Refman == NULL) RAISE(363, 38, "insufficient memory for managed object")
  aux_String_4_Var.max_length = 14;
  aux_String_4_Var.length = 13;
  aux_String_4_Var.values = "second struct";
  aux_TestStruct_1 = LUMI_alloc(sizeof(integration_M_TestStruct));
  if (aux_TestStruct_1 == NULL) RAISE(363, 49, "insufficient memory for object dynamic allocation")
  aux_TestStruct_1_Refman = LUMI_new_ref((void**)&aux_TestStruct_1, true);
  if (aux_TestStruct_1_Refman == NULL) RAISE(363, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(aux_TestStruct_1, aux_TestStruct_1_Refman, 1, aux_String_4, aux_String_4_Refman);
  CHECK(363)
  if (ts == NULL) RAISE(363, 17, "empty object used")
  if (ts_Refman->value == NULL) RAISE(363, 28, "outdated weak reference used")
  aux_TestStruct_2 = aux_TestStruct_1;
  aux_TestStruct_2_Refman = aux_TestStruct_1_Refman;
  aux_TestStruct_1 = NULL;
  aux_TestStruct_1_Refman = NULL;
  integration_M_TestStruct_Del(ts->ts);
  LUMI_owner_dec_ref(ts->ts_Refman);
  ts->ts_Refman = aux_TestStruct_2_Refman;
  ts->ts = aux_TestStruct_2;
  aux_TestStruct_2 = NULL;
  aux_TestStruct_2_Refman = NULL;
  if (ts == NULL) RAISE(364, 17, "empty object used")
  if (ts_Refman->value == NULL) RAISE(364, 28, "outdated weak reference used")
  aux_TestStruct_3 = ts->ts;
  aux_TestStruct_3_Refman = ts->ts_Refman;
  ts->ts = NULL;
  ts->ts_Refman = NULL;
  integration_M_TestStruct_Del(ts);
  LUMI_owner_dec_ref(ts_Refman);
  ts_Refman = aux_TestStruct_3_Refman;
  ts = aux_TestStruct_3;
  aux_TestStruct_3 = NULL;
  aux_TestStruct_3_Refman = NULL;
  if (ts == NULL) RAISE(365, 17, "empty object used")
  if (ts_Refman->value == NULL) RAISE(365, 28, "outdated weak reference used")
  LUMI_err = Sys_println(sys, sys_Refman, ts->text, ts->text_Refman);
  CHECK(365)
LUMI_cleanup:
  integration_M_TestStruct_Del(aux_TestStruct_3);
  LUMI_owner_dec_ref(aux_TestStruct_3_Refman);
  integration_M_TestStruct_Del(aux_TestStruct_2);
  LUMI_owner_dec_ref(aux_TestStruct_2_Refman);
  integration_M_TestStruct_Del(aux_TestStruct_1);
  LUMI_owner_dec_ref(aux_TestStruct_1_Refman);
  LUMI_dec_ref(aux_String_4_Refman);
  integration_M_TestStruct_Del(aux_TestStruct_0);
  LUMI_owner_dec_ref(aux_TestStruct_0_Refman);
  LUMI_dec_ref(aux_String_3_Refman);
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  integration_M_TestStruct_Del(ts);
  LUMI_owner_dec_ref(ts_Refman);
  LUMI_dec_ref(s_user_Refman);
  String_Del(s);
  LUMI_owner_dec_ref(s_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "f-remove"
Returncode integration_M_f_remove(String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  String_Del(s);
  LUMI_owner_dec_ref(s_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-type-parameters"
Returncode integration_M_test_type_parameters(String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  integration_M_Data d_Var = {0};
  integration_M_Data* d = NULL;
  Ref_Manager* d_Refman = NULL;
  char sarr_Chars[6 * 16];
  String sarr_Values[6] = {{0}};
  Array sarr_Var = {6, NULL};
  Array* sarr = NULL;
  Ref_Manager* sarr_Refman = NULL;
  integration_M_Data ad_Values[5] = {{0}};
  Array ad_Var = {5, NULL};
  Array* ad = NULL;
  Ref_Manager* ad_Refman = NULL;
  integration_M_Data dr_Var = {0};
  integration_M_Data* dr = NULL;
  Ref_Manager* dr_Refman = NULL;
  integration_M_Data* dg = NULL;
  Ref_Manager* dg_Refman = NULL;
  integration_M_TopData t_Var = {{{{0}}}};
  integration_M_TopData* t = NULL;
  Ref_Manager* t_Refman = NULL;
  integration_M_Data dt_Var = {0};
  integration_M_Data* dt = NULL;
  Ref_Manager* dt_Refman = NULL;
  integration_M_TestStruct ts_Var = {0};
  integration_M_TestStruct* ts = NULL;
  Ref_Manager* ts_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(s_Refman);
  d = &d_Var;
  d_Refman = LUMI_new_ref((void**)&d, false);
  if (d_Refman == NULL) RAISE(395, 38, "insufficient memory for managed object")
  sarr = &sarr_Var;
  sarr_Var.values = sarr_Values;
  LUMI_set_var_string_array(6, 16, sarr, sarr_Chars);
  sarr_Refman = LUMI_new_ref((void**)&sarr, false);
  if (sarr_Refman == NULL) RAISE(396, 38, "insufficient memory for managed object")
  if (d == NULL) RAISE(397, 17, "empty object used")
  if (d_Refman->value == NULL) RAISE(397, 28, "outdated weak reference used")
  aux_Ref_Manager = d->item_Refman;
  d->item_Refman = s_Refman;
  d->item_Dynamic = &String_dynamic;
  LUMI_inc_ref(d->item_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  d->item = s;
  if (d == NULL) RAISE(398, 17, "empty object used")
  if (d_Refman->value == NULL) RAISE(398, 28, "outdated weak reference used")
  aux_Ref_Manager = s_Refman;
  s_Refman = d->item_Refman;
  LUMI_inc_ref(s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  s = d->item;
  if (d == NULL) RAISE(399, 17, "empty object used")
  if (d_Refman->value == NULL) RAISE(399, 28, "outdated weak reference used")
  aux_Ref_Manager = d->arr_Refman;
  d->arr_Refman = sarr_Refman;
  LUMI_inc_ref(d->arr_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  d->arr = sarr;
  if (d == NULL) RAISE(400, 17, "empty object used")
  if (d_Refman->value == NULL) RAISE(400, 28, "outdated weak reference used")
  if (d->arr == NULL) RAISE(400, 17, "empty object used")
  if (d->arr_Refman->value == NULL) RAISE(400, 28, "outdated weak reference used")
  if ((4) < 0 || (4) >= (d->arr)->length) RAISE(400, 25, "slice index out of bounds")
  aux_Ref_Manager = s_Refman;
  s_Refman = d->arr_Refman;
  LUMI_inc_ref(s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  s = ((String*)((d->arr)->values)) + 4;
  ad = &ad_Var;
  ad_Var.values = ad_Values;
  ad_Refman = LUMI_new_ref((void**)&ad, false);
  if (ad_Refman == NULL) RAISE(401, 38, "insufficient memory for managed object")
  if (ad == NULL) RAISE(402, 17, "empty object used")
  if (ad_Refman->value == NULL) RAISE(402, 28, "outdated weak reference used")
  if ((2) < 0 || (2) >= (ad)->length) RAISE(402, 25, "slice index out of bounds")
  if (((integration_M_Data*)((ad)->values)) + 2 == NULL) RAISE(402, 17, "empty object used")
  if (ad_Refman->value == NULL) RAISE(402, 28, "outdated weak reference used")
  aux_Ref_Manager = s_Refman;
  s_Refman = (((integration_M_Data*)((ad)->values)) + 2)->item_Refman;
  LUMI_inc_ref(s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  s = (((integration_M_Data*)((ad)->values)) + 2)->item;
  if (ad == NULL) RAISE(403, 17, "empty object used")
  if (ad_Refman->value == NULL) RAISE(403, 28, "outdated weak reference used")
  if ((2) < 0 || (2) >= (ad)->length) RAISE(403, 25, "slice index out of bounds")
  if (((integration_M_Data*)((ad)->values)) + 2 == NULL) RAISE(403, 17, "empty object used")
  if (ad_Refman->value == NULL) RAISE(403, 28, "outdated weak reference used")
  if ((((integration_M_Data*)((ad)->values)) + 2)->arr == NULL) RAISE(403, 17, "empty object used")
  if ((((integration_M_Data*)((ad)->values)) + 2)->arr_Refman->value == NULL) RAISE(403, 28, "outdated weak reference used")
  if ((3) < 0 || (3) >= ((((integration_M_Data*)((ad)->values)) + 2)->arr)->length) RAISE(403, 25, "slice index out of bounds")
  aux_Ref_Manager = s_Refman;
  s_Refman = (((integration_M_Data*)((ad)->values)) + 2)->arr_Refman;
  LUMI_inc_ref(s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  s = ((String*)(((((integration_M_Data*)((ad)->values)) + 2)->arr)->values)) + 3;
  dr = &dr_Var;
  dr_Refman = LUMI_new_ref((void**)&dr, false);
  if (dr_Refman == NULL) RAISE(404, 38, "insufficient memory for managed object")
  if (dr == NULL) RAISE(405, 17, "empty object used")
  if (dr_Refman->value == NULL) RAISE(405, 28, "outdated weak reference used")
  if (dr->item == NULL) RAISE(405, 17, "empty object used")
  if (dr->item_Refman->value == NULL) RAISE(405, 28, "outdated weak reference used")
  if (((integration_M_Data*)(dr->item))->item == NULL) RAISE(405, 17, "empty object used")
  if (((integration_M_Data*)(dr->item))->item_Refman->value == NULL) RAISE(405, 28, "outdated weak reference used")
  aux_Ref_Manager = s_Refman;
  s_Refman = ((integration_M_Data*)(((integration_M_Data*)(dr->item))->item))->item_Refman;
  LUMI_inc_ref(s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  s = ((integration_M_Data*)(((integration_M_Data*)(dr->item))->item))->item;
  LUMI_err = integration_M_Data_set(d, d_Refman, s, s_Refman, &String_dynamic, sarr, sarr_Refman);
  CHECK(406)
  LUMI_err = integration_M_Data_get(d, d_Refman, (void*)&(s), &(s_Refman), &dynamic_Void);
  CHECK(407)
  dg = d;
  dg_Refman = d_Refman;
  LUMI_inc_ref(dg_Refman);
  TEST_ASSERT(409, dg != NULL && dg_Refman->value != NULL)
  t = &t_Var;
  t_Refman = LUMI_new_ref((void**)&t, false);
  if (t_Refman == NULL) RAISE(411, 38, "insufficient memory for managed object")
  dt = &dt_Var;
  dt_Refman = LUMI_new_ref((void**)&dt, false);
  if (dt_Refman == NULL) RAISE(412, 38, "insufficient memory for managed object")
  ts = &ts_Var;
  ts_Refman = LUMI_new_ref((void**)&ts, false);
  if (ts_Refman == NULL) RAISE(413, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(ts, ts_Refman, 0, NULL, NULL);
  CHECK(413)
  if (t == NULL) RAISE(414, 17, "empty object used")
  if (t_Refman->value == NULL) RAISE(414, 28, "outdated weak reference used")
  aux_Ref_Manager = t->_base._base._base.item_Refman;
  t->_base._base._base.item_Refman = s_Refman;
  t->_base._base._base.item_Dynamic = &String_dynamic;
  LUMI_inc_ref(t->_base._base._base.item_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  t->_base._base._base.item = s;
  if (t == NULL) RAISE(415, 17, "empty object used")
  if (t_Refman->value == NULL) RAISE(415, 28, "outdated weak reference used")
  aux_Ref_Manager = t->_base._base._base.arr_Refman;
  t->_base._base._base.arr_Refman = sarr_Refman;
  LUMI_inc_ref(t->_base._base._base.arr_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  t->_base._base._base.arr = sarr;
  if (t == NULL) RAISE(416, 17, "empty object used")
  if (t_Refman->value == NULL) RAISE(416, 28, "outdated weak reference used")
  aux_Ref_Manager = t->_base._base.second_Refman;
  t->_base._base.second_Refman = dt_Refman;
  t->_base._base.second_Dynamic = &integration_M_Data_dynamic;
  LUMI_inc_ref(t->_base._base.second_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  t->_base._base.second = dt;
  if (t == NULL) RAISE(417, 17, "empty object used")
  if (t_Refman->value == NULL) RAISE(417, 28, "outdated weak reference used")
  aux_Ref_Manager = t->_base._base.third_Refman;
  t->_base._base.third_Refman = ts_Refman;
  t->_base._base.third_Dynamic = &integration_M_TestStruct_dynamic;
  LUMI_inc_ref(t->_base._base.third_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  t->_base._base.third = ts;
LUMI_cleanup:
  LUMI_dec_ref(ts_Refman);
  LUMI_dec_ref(dt_Refman);
  LUMI_dec_ref(t_Refman);
  LUMI_dec_ref(dg_Refman);
  LUMI_dec_ref(dr_Refman);
  LUMI_dec_ref(ad_Refman);
  LUMI_dec_ref(sarr_Refman);
  LUMI_dec_ref(d_Refman);
  LUMI_dec_ref(s_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "f-try-catch-raise"
Returncode integration_M_f_try_catch_raise(integration_M_TestStruct* t, Ref_Manager* t_Refman) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(t_Refman);
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    if (t == NULL) RAISE(422, 17, "empty object used")
    if (t_Refman->value == NULL) RAISE(422, 28, "outdated weak reference used")
    t->num = 1;

#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
  } while (false);
  --LUMI_trace_ignore_count;
  if (LUMI_err != OK) {
    LUMI_err = OK;
    aux_String_0 = &aux_String_0_Var;
    aux_String_0_Refman = LUMI_new_ref((void**)&aux_String_0, false);
    if (aux_String_0_Refman == NULL) RAISE(424, 38, "insufficient memory for managed object")
    aux_String_0_Var.max_length = 16;
    aux_String_0_Var.length = 15;
    aux_String_0_Var.values = "ignored message";
    USER_RAISE(424, aux_String_0, aux_String_0_Refman)
  }
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(t_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-error-handling"
Returncode integration_M_test_error_handling(integration_M_TestStruct* t, Ref_Manager* t_Refman) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  String aux_String_2_Var = {0};
  String* aux_String_2 = NULL;
  Ref_Manager* aux_String_2_Refman = NULL;
  String aux_String_3_Var = {0};
  String* aux_String_3 = NULL;
  Ref_Manager* aux_String_3_Refman = NULL;
  String aux_String_4_Var = {0};
  String* aux_String_4 = NULL;
  Ref_Manager* aux_String_4_Refman = NULL;
  String aux_String_5_Var = {0};
  String* aux_String_5 = NULL;
  Ref_Manager* aux_String_5_Refman = NULL;
  String aux_String_6_Var = {0};
  String* aux_String_6 = NULL;
  Ref_Manager* aux_String_6_Refman = NULL;
  String aux_String_7_Var = {0};
  String* aux_String_7 = NULL;
  Ref_Manager* aux_String_7_Refman = NULL;
  String aux_String_8_Var = {0};
  String* aux_String_8 = NULL;
  Ref_Manager* aux_String_8_Refman = NULL;
  String aux_String_9_Var = {0};
  String* aux_String_9 = NULL;
  Ref_Manager* aux_String_9_Refman = NULL;
  String aux_String_10_Var = {0};
  String* aux_String_10 = NULL;
  Ref_Manager* aux_String_10_Refman = NULL;
  String aux_String_11_Var = {0};
  String* aux_String_11 = NULL;
  Ref_Manager* aux_String_11_Refman = NULL;
  String aux_String_12_Var = {0};
  String* aux_String_12 = NULL;
  Ref_Manager* aux_String_12_Refman = NULL;
  LUMI_inc_ref(t_Refman);
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    aux_String_0 = &aux_String_0_Var;
    aux_String_0_Refman = LUMI_new_ref((void**)&aux_String_0, false);
    if (aux_String_0_Refman == NULL) RAISE(428, 38, "insufficient memory for managed object")
    aux_String_0_Var.max_length = 20;
    aux_String_0_Var.length = 19;
    aux_String_0_Var.values = "error handling { 1 ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(428)
    if (t == NULL) RAISE(429, 17, "empty object used")
    if (t_Refman->value == NULL) RAISE(429, 28, "outdated weak reference used")
    t->num = 1;
    aux_String_1 = &aux_String_1_Var;
    aux_String_1_Refman = LUMI_new_ref((void**)&aux_String_1, false);
    if (aux_String_1_Refman == NULL) RAISE(430, 38, "insufficient memory for managed object")
    aux_String_1_Var.max_length = 4;
    aux_String_1_Var.length = 3;
    aux_String_1_Var.values = " X ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
    CHECK(430)
    do {
      ++LUMI_trace_ignore_count;
      LUMI_err = integration_M_f_test_void();
      CHECK(432)
    } while (false);
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
      LUMI_err = OK;
      LUMI_err = integration_M_f_test_int(2);
      CHECK(434)
    }

#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
  } while (false);
  --LUMI_trace_ignore_count;
  if (LUMI_err != OK) {
    LUMI_err = OK;
    aux_String_2 = &aux_String_2_Var;
    aux_String_2_Refman = LUMI_new_ref((void**)&aux_String_2, false);
    if (aux_String_2_Refman == NULL) RAISE(436, 38, "insufficient memory for managed object")
    aux_String_2_Var.max_length = 3;
    aux_String_2_Var.length = 2;
    aux_String_2_Var.values = "2 ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_2, aux_String_2_Refman);
    CHECK(436)
    do {
      ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
      aux_String_3 = &aux_String_3_Var;
      aux_String_3_Refman = LUMI_new_ref((void**)&aux_String_3, false);
      if (aux_String_3_Refman == NULL) RAISE(438, 38, "insufficient memory for managed object")
      aux_String_3_Var.max_length = 3;
      aux_String_3_Var.length = 2;
      aux_String_3_Var.values = "3 ";
      LUMI_err = Sys_print(sys, sys_Refman, aux_String_3, aux_String_3_Refman);
      CHECK(438)
      if (t == NULL) RAISE(439, 17, "empty object used")
      if (t_Refman->value == NULL) RAISE(439, 28, "outdated weak reference used")
      t->num = 2;
      aux_String_4 = &aux_String_4_Var;
      aux_String_4_Refman = LUMI_new_ref((void**)&aux_String_4, false);
      if (aux_String_4_Refman == NULL) RAISE(440, 38, "insufficient memory for managed object")
      aux_String_4_Var.max_length = 4;
      aux_String_4_Var.length = 3;
      aux_String_4_Var.values = " X ";
      LUMI_err = Sys_print(sys, sys_Refman, aux_String_4, aux_String_4_Refman);
      CHECK(440)

#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    } while (false);
    --LUMI_trace_ignore_count;
    LUMI_err = OK;
    aux_String_5 = &aux_String_5_Var;
    aux_String_5_Refman = LUMI_new_ref((void**)&aux_String_5, false);
    if (aux_String_5_Refman == NULL) RAISE(441, 38, "insufficient memory for managed object")
    aux_String_5_Var.max_length = 3;
    aux_String_5_Var.length = 2;
    aux_String_5_Var.values = "4 ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_5, aux_String_5_Refman);
    CHECK(441)
  }
  aux_String_6 = &aux_String_6_Var;
  aux_String_6_Refman = LUMI_new_ref((void**)&aux_String_6, false);
  if (aux_String_6_Refman == NULL) RAISE(442, 38, "insufficient memory for managed object")
  aux_String_6_Var.max_length = 3;
  aux_String_6_Var.length = 2;
  aux_String_6_Var.values = "5 ";
  LUMI_err = Sys_print(sys, sys_Refman, aux_String_6, aux_String_6_Refman);
  CHECK(442)
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    aux_String_7 = &aux_String_7_Var;
    aux_String_7_Refman = LUMI_new_ref((void**)&aux_String_7, false);
    if (aux_String_7_Refman == NULL) RAISE(444, 38, "insufficient memory for managed object")
    aux_String_7_Var.max_length = 3;
    aux_String_7_Var.length = 2;
    aux_String_7_Var.values = "6 ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_7, aux_String_7_Refman);
    CHECK(444)
    do {
      ++LUMI_trace_ignore_count;
      aux_String_8 = &aux_String_8_Var;
      aux_String_8_Refman = LUMI_new_ref((void**)&aux_String_8, false);
      if (aux_String_8_Refman == NULL) RAISE(446, 38, "insufficient memory for managed object")
      aux_String_8_Var.max_length = 3;
      aux_String_8_Var.length = 2;
      aux_String_8_Var.values = "7 ";
      LUMI_err = Sys_print(sys, sys_Refman, aux_String_8, aux_String_8_Refman);
      CHECK(446)
      LUMI_err = integration_M_f_try_catch_raise(t, t_Refman);
      CHECK(447)
      aux_String_9 = &aux_String_9_Var;
      aux_String_9_Refman = LUMI_new_ref((void**)&aux_String_9, false);
      if (aux_String_9_Refman == NULL) RAISE(448, 38, "insufficient memory for managed object")
      aux_String_9_Var.max_length = 4;
      aux_String_9_Var.length = 3;
      aux_String_9_Var.values = " X ";
      LUMI_err = Sys_print(sys, sys_Refman, aux_String_9, aux_String_9_Refman);
      CHECK(448)
    } while (false);
    --LUMI_trace_ignore_count;
    LUMI_err = OK;
    aux_String_10 = &aux_String_10_Var;
    aux_String_10_Refman = LUMI_new_ref((void**)&aux_String_10, false);
    if (aux_String_10_Refman == NULL) RAISE(449, 38, "insufficient memory for managed object")
    aux_String_10_Var.max_length = 3;
    aux_String_10_Var.length = 2;
    aux_String_10_Var.values = "8 ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_10, aux_String_10_Refman);
    CHECK(449)
    aux_String_11 = &aux_String_11_Var;
    aux_String_11_Refman = LUMI_new_ref((void**)&aux_String_11, false);
    if (aux_String_11_Refman == NULL) RAISE(450, 38, "insufficient memory for managed object")
    aux_String_11_Var.max_length = 24;
    aux_String_11_Var.length = 23;
    aux_String_11_Var.values = "another ignored message";
    USER_RAISE(450, aux_String_11, aux_String_11_Refman)

#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_err = OK;
  aux_String_12 = &aux_String_12_Var;
  aux_String_12_Refman = LUMI_new_ref((void**)&aux_String_12, false);
  if (aux_String_12_Refman == NULL) RAISE(451, 38, "insufficient memory for managed object")
  aux_String_12_Var.max_length = 2;
  aux_String_12_Var.length = 1;
  aux_String_12_Var.values = "}";
  LUMI_err = Sys_println(sys, sys_Refman, aux_String_12, aux_String_12_Refman);
  CHECK(451)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_12_Refman);
  LUMI_dec_ref(aux_String_11_Refman);
  LUMI_dec_ref(aux_String_10_Refman);
  LUMI_dec_ref(aux_String_9_Refman);
  LUMI_dec_ref(aux_String_8_Refman);
  LUMI_dec_ref(aux_String_7_Refman);
  LUMI_dec_ref(aux_String_6_Refman);
  LUMI_dec_ref(aux_String_5_Refman);
  LUMI_dec_ref(aux_String_4_Refman);
  LUMI_dec_ref(aux_String_3_Refman);
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(t_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-for-each"
Returncode integration_M_test_for_each(void) {
  Returncode LUMI_err = OK;
  char text_Values[16] = {0};
  String text_Var = {16, 0, NULL};
  String* text = NULL;
  Ref_Manager* text_Refman = NULL;
  Int arr_Values[3] = {0};
  Array arr_Var = {3, NULL};
  Array* arr = NULL;
  Ref_Manager* arr_Refman = NULL;
  integration_M_TestStruct tsarr_Values[3] = {{0}};
  Array tsarr_Var = {3, NULL};
  Array* tsarr = NULL;
  Ref_Manager* tsarr_Refman = NULL;
  char sarr_Chars[3 * 16];
  String sarr_Values[3] = {{0}};
  Array sarr_Var = {3, NULL};
  Array* sarr = NULL;
  Ref_Manager* sarr_Refman = NULL;
  integration_M_Container container_last_Var = {0};
  integration_M_Container* container_last = NULL;
  Ref_Manager* container_last_Refman = NULL;
  integration_M_Container container_mid_Var = {0};
  integration_M_Container* container_mid = NULL;
  Ref_Manager* container_mid_Refman = NULL;
  integration_M_Container container_first_Var = {0};
  integration_M_Container* container_first = NULL;
  Ref_Manager* container_first_Refman = NULL;
  integration_M_Container container_Var = {0};
  integration_M_Container* container = NULL;
  Ref_Manager* container_Refman = NULL;
  integration_M_ContainerIterator* iter = NULL;
  Ref_Manager* iter_Refman = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  Char c = 0;
  String* aux_String_2 = NULL;
  Ref_Manager* aux_String_2_Refman = NULL;
  String aux_String_3_Var = {0};
  String* aux_String_3 = NULL;
  Ref_Manager* aux_String_3_Refman = NULL;
  String aux_String_4_Var = {0};
  String* aux_String_4 = NULL;
  Ref_Manager* aux_String_4_Refman = NULL;
  String aux_String_5_Var = {0};
  String* aux_String_5 = NULL;
  Ref_Manager* aux_String_5_Refman = NULL;
  Int n = 0;
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  String aux_String_6_Var = {0};
  String* aux_String_6 = NULL;
  Ref_Manager* aux_String_6_Refman = NULL;
  String aux_String_7_Var = {0};
  String* aux_String_7 = NULL;
  Ref_Manager* aux_String_7_Refman = NULL;
  String aux_String_8_Var = {0};
  String* aux_String_8 = NULL;
  Ref_Manager* aux_String_8_Refman = NULL;
  String aux_String_9_Var = {0};
  String* aux_String_9 = NULL;
  Ref_Manager* aux_String_9_Refman = NULL;
  String aux_String_10_Var = {0};
  String* aux_String_10 = NULL;
  Ref_Manager* aux_String_10_Refman = NULL;
  String aux_String_11_Var = {0};
  String* aux_String_11 = NULL;
  Ref_Manager* aux_String_11_Refman = NULL;
  integration_M_TestStruct* ts = NULL;
  Ref_Manager* ts_Refman = NULL;
  Array* aux_Array_1 = NULL;
  Ref_Manager* aux_Array_1_Refman = NULL;
  String aux_String_12_Var = {0};
  String* aux_String_12 = NULL;
  Ref_Manager* aux_String_12_Refman = NULL;
  String aux_String_13_Var = {0};
  String* aux_String_13 = NULL;
  Ref_Manager* aux_String_13_Refman = NULL;
  String aux_String_14_Var = {0};
  String* aux_String_14 = NULL;
  Ref_Manager* aux_String_14_Refman = NULL;
  String aux_String_15_Var = {0};
  String* aux_String_15 = NULL;
  Ref_Manager* aux_String_15_Refman = NULL;
  String aux_String_16_Var = {0};
  String* aux_String_16 = NULL;
  Ref_Manager* aux_String_16_Refman = NULL;
  String aux_String_17_Var = {0};
  String* aux_String_17 = NULL;
  Ref_Manager* aux_String_17_Refman = NULL;
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  Array* aux_Array_2 = NULL;
  Ref_Manager* aux_Array_2_Refman = NULL;
  String aux_String_18_Var = {0};
  String* aux_String_18 = NULL;
  Ref_Manager* aux_String_18_Refman = NULL;
  String aux_String_19_Var = {0};
  String* aux_String_19 = NULL;
  Ref_Manager* aux_String_19_Refman = NULL;
  String aux_String_20_Var = {0};
  String* aux_String_20 = NULL;
  Ref_Manager* aux_String_20_Refman = NULL;
  String aux_String_21_Var = {0};
  String* aux_String_21 = NULL;
  Ref_Manager* aux_String_21_Refman = NULL;
  String aux_String_22_Var = {0};
  String* aux_String_22 = NULL;
  Ref_Manager* aux_String_22_Refman = NULL;
  String aux_String_23_Var = {0};
  String* aux_String_23 = NULL;
  Ref_Manager* aux_String_23_Refman = NULL;
  integration_M_ContainerIterator* aux_ContainerIterator_0 = NULL;
  Ref_Manager* aux_ContainerIterator_0_Refman = NULL;
  String aux_String_24_Var = {0};
  String* aux_String_24 = NULL;
  Ref_Manager* aux_String_24_Refman = NULL;
  String aux_String_25_Var = {0};
  String* aux_String_25 = NULL;
  Ref_Manager* aux_String_25_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  text = &text_Var;
  text_Var.values = text_Values;
  text_Refman = LUMI_new_ref((void**)&text, false);
  if (text_Refman == NULL) RAISE(481, 38, "insufficient memory for managed object")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref((void**)&aux_String_0, false);
  if (aux_String_0_Refman == NULL) RAISE(482, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 8;
  aux_String_0_Var.length = 7;
  aux_String_0_Var.values = "chars[ ";
  LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(482)
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref((void**)&aux_String_1, false);
  if (aux_String_1_Refman == NULL) RAISE(483, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 7;
  aux_String_1_Var.length = 6;
  aux_String_1_Var.values = "abcdef";
  aux_Ref_Manager = aux_String_2_Refman;
  aux_String_2_Refman = aux_String_1_Refman;
  LUMI_inc_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  aux_String_2 = aux_String_1;
  if (aux_String_2 == NULL) RAISE(483, 17, "empty object used")
  if (aux_String_2_Refman->value == NULL) RAISE(483, 28, "outdated weak reference used")
  {int c_Index; for (c_Index = 0; c_Index < aux_String_2->length; ++c_Index) {
    if (aux_String_2 == NULL) RAISE(483, 17, "empty object used")
    if (aux_String_2_Refman->value == NULL) RAISE(483, 28, "outdated weak reference used")
    if ((c_Index) < 0 || (c_Index) >= (aux_String_2)->length) RAISE(483, 25, "slice index out of bounds")
    c = ((aux_String_2)->values)[c_Index];
    LUMI_err = String_clear(text, text_Refman);
    CHECK(484)
    LUMI_err = String_append(text, text_Refman, c);
    CHECK(485)
    LUMI_err = Sys_print(sys, sys_Refman, text, text_Refman);
    CHECK(486)
    aux_String_3 = &aux_String_3_Var;
    aux_String_3_Refman = LUMI_new_ref((void**)&aux_String_3, false);
    if (aux_String_3_Refman == NULL) RAISE(487, 38, "insufficient memory for managed object")
    aux_String_3_Var.max_length = 2;
    aux_String_3_Var.length = 1;
    aux_String_3_Var.values = " ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_3, aux_String_3_Refman);
    CHECK(487)
  }}
  aux_Ref_Manager = aux_String_2_Refman;
  aux_String_2_Refman = NULL;
  LUMI_inc_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  aux_String_2 = NULL;
  aux_String_4 = &aux_String_4_Var;
  aux_String_4_Refman = LUMI_new_ref((void**)&aux_String_4, false);
  if (aux_String_4_Refman == NULL) RAISE(488, 38, "insufficient memory for managed object")
  aux_String_4_Var.max_length = 2;
  aux_String_4_Var.length = 1;
  aux_String_4_Var.values = "]";
  LUMI_err = Sys_println(sys, sys_Refman, aux_String_4, aux_String_4_Refman);
  CHECK(488)
  arr = &arr_Var;
  arr_Var.values = arr_Values;
  arr_Refman = LUMI_new_ref((void**)&arr, false);
  if (arr_Refman == NULL) RAISE(490, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(491, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(491, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(491, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[0] = 14;
  if (arr == NULL) RAISE(492, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(492, 28, "outdated weak reference used")
  if ((1) < 0 || (1) >= (arr)->length) RAISE(492, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[1] = 15;
  if (arr == NULL) RAISE(493, 17, "empty object used")
  if (arr_Refman->value == NULL) RAISE(493, 28, "outdated weak reference used")
  if ((2) < 0 || (2) >= (arr)->length) RAISE(493, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[2] = 16;
  aux_String_5 = &aux_String_5_Var;
  aux_String_5_Refman = LUMI_new_ref((void**)&aux_String_5, false);
  if (aux_String_5_Refman == NULL) RAISE(494, 38, "insufficient memory for managed object")
  aux_String_5_Var.max_length = 10;
  aux_String_5_Var.length = 9;
  aux_String_5_Var.values = "numbers[ ";
  LUMI_err = Sys_print(sys, sys_Refman, aux_String_5, aux_String_5_Refman);
  CHECK(494)
  aux_Ref_Manager = aux_Array_0_Refman;
  aux_Array_0_Refman = arr_Refman;
  LUMI_inc_ref(aux_Array_0_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  aux_Array_0 = arr;
  if (aux_Array_0 == NULL) RAISE(495, 17, "empty object used")
  if (aux_Array_0_Refman->value == NULL) RAISE(495, 28, "outdated weak reference used")
  {int n_Index; for (n_Index = 0; n_Index < aux_Array_0->length; ++n_Index) {
    if (aux_Array_0 == NULL) RAISE(495, 17, "empty object used")
    if (aux_Array_0_Refman->value == NULL) RAISE(495, 28, "outdated weak reference used")
    if ((n_Index) < 0 || (n_Index) >= (aux_Array_0)->length) RAISE(495, 25, "slice index out of bounds")
    n = ((Int*)((aux_Array_0)->values))[n_Index];
    LUMI_err = String_clear(text, text_Refman);
    CHECK(496)
    LUMI_err = Int_str(n, text, text_Refman);
    CHECK(497)
    LUMI_err = Sys_print(sys, sys_Refman, text, text_Refman);
    CHECK(498)
    aux_String_6 = &aux_String_6_Var;
    aux_String_6_Refman = LUMI_new_ref((void**)&aux_String_6, false);
    if (aux_String_6_Refman == NULL) RAISE(499, 38, "insufficient memory for managed object")
    aux_String_6_Var.max_length = 2;
    aux_String_6_Var.length = 1;
    aux_String_6_Var.values = " ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_6, aux_String_6_Refman);
    CHECK(499)
  }}
  aux_Ref_Manager = aux_Array_0_Refman;
  aux_Array_0_Refman = NULL;
  LUMI_inc_ref(aux_Array_0_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  aux_Array_0 = NULL;
  aux_String_7 = &aux_String_7_Var;
  aux_String_7_Refman = LUMI_new_ref((void**)&aux_String_7, false);
  if (aux_String_7_Refman == NULL) RAISE(500, 38, "insufficient memory for managed object")
  aux_String_7_Var.max_length = 2;
  aux_String_7_Var.length = 1;
  aux_String_7_Var.values = "]";
  LUMI_err = Sys_println(sys, sys_Refman, aux_String_7, aux_String_7_Refman);
  CHECK(500)
  tsarr = &tsarr_Var;
  tsarr_Var.values = tsarr_Values;
  tsarr_Refman = LUMI_new_ref((void**)&tsarr, false);
  if (tsarr_Refman == NULL) RAISE(502, 38, "insufficient memory for managed object")
  aux_String_8 = &aux_String_8_Var;
  aux_String_8_Refman = LUMI_new_ref((void**)&aux_String_8, false);
  if (aux_String_8_Refman == NULL) RAISE(503, 38, "insufficient memory for managed object")
  aux_String_8_Var.max_length = 4;
  aux_String_8_Var.length = 3;
  aux_String_8_Var.values = "aaa";
  if (tsarr == NULL) RAISE(503, 17, "empty object used")
  if (tsarr_Refman->value == NULL) RAISE(503, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (tsarr)->length) RAISE(503, 25, "slice index out of bounds")
  if (((integration_M_TestStruct*)((tsarr)->values)) + 0 == NULL) RAISE(503, 17, "empty object used")
  if (tsarr_Refman->value == NULL) RAISE(503, 28, "outdated weak reference used")
  aux_Ref_Manager = (((integration_M_TestStruct*)((tsarr)->values)) + 0)->text_Refman;
  (((integration_M_TestStruct*)((tsarr)->values)) + 0)->text_Refman = aux_String_8_Refman;
  LUMI_inc_ref((((integration_M_TestStruct*)((tsarr)->values)) + 0)->text_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  (((integration_M_TestStruct*)((tsarr)->values)) + 0)->text = aux_String_8;
  aux_String_9 = &aux_String_9_Var;
  aux_String_9_Refman = LUMI_new_ref((void**)&aux_String_9, false);
  if (aux_String_9_Refman == NULL) RAISE(504, 38, "insufficient memory for managed object")
  aux_String_9_Var.max_length = 4;
  aux_String_9_Var.length = 3;
  aux_String_9_Var.values = "bbb";
  if (tsarr == NULL) RAISE(504, 17, "empty object used")
  if (tsarr_Refman->value == NULL) RAISE(504, 28, "outdated weak reference used")
  if ((1) < 0 || (1) >= (tsarr)->length) RAISE(504, 25, "slice index out of bounds")
  if (((integration_M_TestStruct*)((tsarr)->values)) + 1 == NULL) RAISE(504, 17, "empty object used")
  if (tsarr_Refman->value == NULL) RAISE(504, 28, "outdated weak reference used")
  aux_Ref_Manager = (((integration_M_TestStruct*)((tsarr)->values)) + 1)->text_Refman;
  (((integration_M_TestStruct*)((tsarr)->values)) + 1)->text_Refman = aux_String_9_Refman;
  LUMI_inc_ref((((integration_M_TestStruct*)((tsarr)->values)) + 1)->text_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  (((integration_M_TestStruct*)((tsarr)->values)) + 1)->text = aux_String_9;
  aux_String_10 = &aux_String_10_Var;
  aux_String_10_Refman = LUMI_new_ref((void**)&aux_String_10, false);
  if (aux_String_10_Refman == NULL) RAISE(505, 38, "insufficient memory for managed object")
  aux_String_10_Var.max_length = 4;
  aux_String_10_Var.length = 3;
  aux_String_10_Var.values = "ccc";
  if (tsarr == NULL) RAISE(505, 17, "empty object used")
  if (tsarr_Refman->value == NULL) RAISE(505, 28, "outdated weak reference used")
  if ((2) < 0 || (2) >= (tsarr)->length) RAISE(505, 25, "slice index out of bounds")
  if (((integration_M_TestStruct*)((tsarr)->values)) + 2 == NULL) RAISE(505, 17, "empty object used")
  if (tsarr_Refman->value == NULL) RAISE(505, 28, "outdated weak reference used")
  aux_Ref_Manager = (((integration_M_TestStruct*)((tsarr)->values)) + 2)->text_Refman;
  (((integration_M_TestStruct*)((tsarr)->values)) + 2)->text_Refman = aux_String_10_Refman;
  LUMI_inc_ref((((integration_M_TestStruct*)((tsarr)->values)) + 2)->text_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  (((integration_M_TestStruct*)((tsarr)->values)) + 2)->text = aux_String_10;
  aux_String_11 = &aux_String_11_Var;
  aux_String_11_Refman = LUMI_new_ref((void**)&aux_String_11, false);
  if (aux_String_11_Refman == NULL) RAISE(506, 38, "insufficient memory for managed object")
  aux_String_11_Var.max_length = 10;
  aux_String_11_Var.length = 9;
  aux_String_11_Var.values = "structs[ ";
  LUMI_err = Sys_print(sys, sys_Refman, aux_String_11, aux_String_11_Refman);
  CHECK(506)
  aux_Ref_Manager = aux_Array_1_Refman;
  aux_Array_1_Refman = tsarr_Refman;
  LUMI_inc_ref(aux_Array_1_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  aux_Array_1 = tsarr;
  if (aux_Array_1 == NULL) RAISE(507, 17, "empty object used")
  if (aux_Array_1_Refman->value == NULL) RAISE(507, 28, "outdated weak reference used")
  {int ts_Index; for (ts_Index = 0; ts_Index < aux_Array_1->length; ++ts_Index) {
    if (aux_Array_1 == NULL) RAISE(507, 17, "empty object used")
    if (aux_Array_1_Refman->value == NULL) RAISE(507, 28, "outdated weak reference used")
    if ((ts_Index) < 0 || (ts_Index) >= (aux_Array_1)->length) RAISE(507, 25, "slice index out of bounds")
    aux_Ref_Manager = ts_Refman;
    ts_Refman = aux_Array_1_Refman;
    LUMI_inc_ref(ts_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ts = ((integration_M_TestStruct*)((aux_Array_1)->values)) + ts_Index;
    if (ts == NULL) RAISE(508, 17, "empty object used")
    if (ts_Refman->value == NULL) RAISE(508, 28, "outdated weak reference used")
    LUMI_err = Sys_print(sys, sys_Refman, ts->text, ts->text_Refman);
    CHECK(508)
    aux_String_12 = &aux_String_12_Var;
    aux_String_12_Refman = LUMI_new_ref((void**)&aux_String_12, false);
    if (aux_String_12_Refman == NULL) RAISE(509, 38, "insufficient memory for managed object")
    aux_String_12_Var.max_length = 2;
    aux_String_12_Var.length = 1;
    aux_String_12_Var.values = " ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_12, aux_String_12_Refman);
    CHECK(509)
  }}
  aux_Ref_Manager = aux_Array_1_Refman;
  aux_Array_1_Refman = NULL;
  LUMI_inc_ref(aux_Array_1_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  aux_Array_1 = NULL;
  aux_String_13 = &aux_String_13_Var;
  aux_String_13_Refman = LUMI_new_ref((void**)&aux_String_13, false);
  if (aux_String_13_Refman == NULL) RAISE(510, 38, "insufficient memory for managed object")
  aux_String_13_Var.max_length = 2;
  aux_String_13_Var.length = 1;
  aux_String_13_Var.values = "]";
  LUMI_err = Sys_println(sys, sys_Refman, aux_String_13, aux_String_13_Refman);
  CHECK(510)
  sarr = &sarr_Var;
  sarr_Var.values = sarr_Values;
  LUMI_set_var_string_array(3, 16, sarr, sarr_Chars);
  sarr_Refman = LUMI_new_ref((void**)&sarr, false);
  if (sarr_Refman == NULL) RAISE(512, 38, "insufficient memory for managed object")
  if (sarr == NULL) RAISE(513, 17, "empty object used")
  if (sarr_Refman->value == NULL) RAISE(513, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= (sarr)->length) RAISE(513, 25, "slice index out of bounds")
  aux_String_14 = &aux_String_14_Var;
  aux_String_14_Refman = LUMI_new_ref((void**)&aux_String_14, false);
  if (aux_String_14_Refman == NULL) RAISE(513, 38, "insufficient memory for managed object")
  aux_String_14_Var.max_length = 4;
  aux_String_14_Var.length = 3;
  aux_String_14_Var.values = "ddd";
  LUMI_err = String_new(((String*)((sarr)->values)) + 0, sarr_Refman, aux_String_14, aux_String_14_Refman);
  CHECK(513)
  if (sarr == NULL) RAISE(514, 17, "empty object used")
  if (sarr_Refman->value == NULL) RAISE(514, 28, "outdated weak reference used")
  if ((1) < 0 || (1) >= (sarr)->length) RAISE(514, 25, "slice index out of bounds")
  aux_String_15 = &aux_String_15_Var;
  aux_String_15_Refman = LUMI_new_ref((void**)&aux_String_15, false);
  if (aux_String_15_Refman == NULL) RAISE(514, 38, "insufficient memory for managed object")
  aux_String_15_Var.max_length = 4;
  aux_String_15_Var.length = 3;
  aux_String_15_Var.values = "eee";
  LUMI_err = String_new(((String*)((sarr)->values)) + 1, sarr_Refman, aux_String_15, aux_String_15_Refman);
  CHECK(514)
  if (sarr == NULL) RAISE(515, 17, "empty object used")
  if (sarr_Refman->value == NULL) RAISE(515, 28, "outdated weak reference used")
  if ((2) < 0 || (2) >= (sarr)->length) RAISE(515, 25, "slice index out of bounds")
  aux_String_16 = &aux_String_16_Var;
  aux_String_16_Refman = LUMI_new_ref((void**)&aux_String_16, false);
  if (aux_String_16_Refman == NULL) RAISE(515, 38, "insufficient memory for managed object")
  aux_String_16_Var.max_length = 4;
  aux_String_16_Var.length = 3;
  aux_String_16_Var.values = "fff";
  LUMI_err = String_new(((String*)((sarr)->values)) + 2, sarr_Refman, aux_String_16, aux_String_16_Refman);
  CHECK(515)
  aux_String_17 = &aux_String_17_Var;
  aux_String_17_Refman = LUMI_new_ref((void**)&aux_String_17, false);
  if (aux_String_17_Refman == NULL) RAISE(516, 38, "insufficient memory for managed object")
  aux_String_17_Var.max_length = 10;
  aux_String_17_Var.length = 9;
  aux_String_17_Var.values = "strings[ ";
  LUMI_err = Sys_print(sys, sys_Refman, aux_String_17, aux_String_17_Refman);
  CHECK(516)
  aux_Ref_Manager = aux_Array_2_Refman;
  aux_Array_2_Refman = sarr_Refman;
  LUMI_inc_ref(aux_Array_2_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  aux_Array_2 = sarr;
  if (aux_Array_2 == NULL) RAISE(517, 17, "empty object used")
  if (aux_Array_2_Refman->value == NULL) RAISE(517, 28, "outdated weak reference used")
  {int s_Index; for (s_Index = 0; s_Index < aux_Array_2->length; ++s_Index) {
    if (aux_Array_2 == NULL) RAISE(517, 17, "empty object used")
    if (aux_Array_2_Refman->value == NULL) RAISE(517, 28, "outdated weak reference used")
    if ((s_Index) < 0 || (s_Index) >= (aux_Array_2)->length) RAISE(517, 25, "slice index out of bounds")
    aux_Ref_Manager = s_Refman;
    s_Refman = aux_Array_2_Refman;
    LUMI_inc_ref(s_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    s = ((String*)((aux_Array_2)->values)) + s_Index;
    LUMI_err = Sys_print(sys, sys_Refman, s, s_Refman);
    CHECK(518)
    aux_String_18 = &aux_String_18_Var;
    aux_String_18_Refman = LUMI_new_ref((void**)&aux_String_18, false);
    if (aux_String_18_Refman == NULL) RAISE(519, 38, "insufficient memory for managed object")
    aux_String_18_Var.max_length = 2;
    aux_String_18_Var.length = 1;
    aux_String_18_Var.values = " ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_18, aux_String_18_Refman);
    CHECK(519)
  }}
  aux_Ref_Manager = aux_Array_2_Refman;
  aux_Array_2_Refman = NULL;
  LUMI_inc_ref(aux_Array_2_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  aux_Array_2 = NULL;
  aux_String_19 = &aux_String_19_Var;
  aux_String_19_Refman = LUMI_new_ref((void**)&aux_String_19, false);
  if (aux_String_19_Refman == NULL) RAISE(520, 38, "insufficient memory for managed object")
  aux_String_19_Var.max_length = 2;
  aux_String_19_Var.length = 1;
  aux_String_19_Var.values = "]";
  LUMI_err = Sys_println(sys, sys_Refman, aux_String_19, aux_String_19_Refman);
  CHECK(520)
  aux_String_20 = &aux_String_20_Var;
  aux_String_20_Refman = LUMI_new_ref((void**)&aux_String_20, false);
  if (aux_String_20_Refman == NULL) RAISE(522, 38, "insufficient memory for managed object")
  aux_String_20_Var.max_length = 4;
  aux_String_20_Var.length = 3;
  aux_String_20_Var.values = "iii";
  container_last = &container_last_Var;
  container_last_Refman = LUMI_new_ref((void**)&container_last, false);
  if (container_last_Refman == NULL) RAISE(522, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_Container_new(container_last, container_last_Refman, aux_String_20, aux_String_20_Refman, &String_dynamic, NULL, NULL);
  CHECK(522)
  aux_String_21 = &aux_String_21_Var;
  aux_String_21_Refman = LUMI_new_ref((void**)&aux_String_21, false);
  if (aux_String_21_Refman == NULL) RAISE(523, 38, "insufficient memory for managed object")
  aux_String_21_Var.max_length = 4;
  aux_String_21_Var.length = 3;
  aux_String_21_Var.values = "hhh";
  container_mid = &container_mid_Var;
  container_mid_Refman = LUMI_new_ref((void**)&container_mid, false);
  if (container_mid_Refman == NULL) RAISE(523, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_Container_new(container_mid, container_mid_Refman, aux_String_21, aux_String_21_Refman, &String_dynamic, container_last, container_last_Refman);
  CHECK(523)
  aux_String_22 = &aux_String_22_Var;
  aux_String_22_Refman = LUMI_new_ref((void**)&aux_String_22, false);
  if (aux_String_22_Refman == NULL) RAISE(524, 38, "insufficient memory for managed object")
  aux_String_22_Var.max_length = 4;
  aux_String_22_Var.length = 3;
  aux_String_22_Var.values = "ggg";
  container_first = &container_first_Var;
  container_first_Refman = LUMI_new_ref((void**)&container_first, false);
  if (container_first_Refman == NULL) RAISE(524, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_Container_new(container_first, container_first_Refman, aux_String_22, aux_String_22_Refman, &String_dynamic, container_mid, container_mid_Refman);
  CHECK(524)
  container = &container_Var;
  container_Refman = LUMI_new_ref((void**)&container, false);
  if (container_Refman == NULL) RAISE(525, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_Container_new(container, container_Refman, NULL, NULL, NULL, container_first, container_first_Refman);
  CHECK(525)
  LUMI_err = integration_M_Container_iter(container, container_Refman, &(iter), &(iter_Refman));
  CHECK(527)
  aux_String_23 = &aux_String_23_Var;
  aux_String_23_Refman = LUMI_new_ref((void**)&aux_String_23, false);
  if (aux_String_23_Refman == NULL) RAISE(528, 38, "insufficient memory for managed object")
  aux_String_23_Var.max_length = 9;
  aux_String_23_Var.length = 8;
  aux_String_23_Var.values = "values[ ";
  LUMI_err = Sys_print(sys, sys_Refman, aux_String_23, aux_String_23_Refman);
  CHECK(528)
  aux_Ref_Manager = aux_ContainerIterator_0_Refman;
  aux_ContainerIterator_0_Refman = iter_Refman;
  LUMI_inc_ref(aux_ContainerIterator_0_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  aux_ContainerIterator_0 = iter;
  while (true) {
    Bool s_Has = false;
    LUMI_err = integration_M_ContainerIterator_has(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman, &(s_Has));
    CHECK(529)
    if (!s_Has) break;
    LUMI_err = integration_M_ContainerIterator_get(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman, (void*)&(s), &(s_Refman), &dynamic_Void);
    CHECK(529)
    LUMI_err = Sys_print(sys, sys_Refman, s, s_Refman);
    CHECK(530)
    aux_String_24 = &aux_String_24_Var;
    aux_String_24_Refman = LUMI_new_ref((void**)&aux_String_24, false);
    if (aux_String_24_Refman == NULL) RAISE(531, 38, "insufficient memory for managed object")
    aux_String_24_Var.max_length = 2;
    aux_String_24_Var.length = 1;
    aux_String_24_Var.values = " ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_24, aux_String_24_Refman);
    CHECK(531)
    LUMI_err = integration_M_ContainerIterator_next(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman);
    CHECK(529)
  }
  aux_Ref_Manager = aux_ContainerIterator_0_Refman;
  aux_ContainerIterator_0_Refman = NULL;
  LUMI_inc_ref(aux_ContainerIterator_0_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  aux_ContainerIterator_0 = NULL;
  aux_String_25 = &aux_String_25_Var;
  aux_String_25_Refman = LUMI_new_ref((void**)&aux_String_25, false);
  if (aux_String_25_Refman == NULL) RAISE(532, 38, "insufficient memory for managed object")
  aux_String_25_Var.max_length = 2;
  aux_String_25_Var.length = 1;
  aux_String_25_Var.values = "]";
  LUMI_err = Sys_println(sys, sys_Refman, aux_String_25, aux_String_25_Refman);
  CHECK(532)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_25_Refman);
  LUMI_dec_ref(aux_String_24_Refman);
  LUMI_dec_ref(aux_ContainerIterator_0_Refman);
  LUMI_dec_ref(aux_String_23_Refman);
  LUMI_dec_ref(aux_String_22_Refman);
  LUMI_dec_ref(aux_String_21_Refman);
  LUMI_dec_ref(aux_String_20_Refman);
  LUMI_dec_ref(aux_String_19_Refman);
  LUMI_dec_ref(aux_String_18_Refman);
  LUMI_dec_ref(aux_Array_2_Refman);
  LUMI_dec_ref(s_Refman);
  LUMI_dec_ref(aux_String_17_Refman);
  LUMI_dec_ref(aux_String_16_Refman);
  LUMI_dec_ref(aux_String_15_Refman);
  LUMI_dec_ref(aux_String_14_Refman);
  LUMI_dec_ref(aux_String_13_Refman);
  LUMI_dec_ref(aux_String_12_Refman);
  LUMI_dec_ref(aux_Array_1_Refman);
  LUMI_dec_ref(ts_Refman);
  LUMI_dec_ref(aux_String_11_Refman);
  LUMI_dec_ref(aux_String_10_Refman);
  LUMI_dec_ref(aux_String_9_Refman);
  LUMI_dec_ref(aux_String_8_Refman);
  LUMI_dec_ref(aux_String_7_Refman);
  LUMI_dec_ref(aux_String_6_Refman);
  LUMI_dec_ref(aux_Array_0_Refman);
  LUMI_dec_ref(aux_String_5_Refman);
  LUMI_dec_ref(aux_String_4_Refman);
  LUMI_dec_ref(aux_String_3_Refman);
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  integration_M_ContainerIterator_Del(iter);
  LUMI_owner_dec_ref(iter_Refman);
  LUMI_dec_ref(container_Refman);
  LUMI_dec_ref(container_first_Refman);
  LUMI_dec_ref(container_mid_Refman);
  LUMI_dec_ref(container_last_Refman);
  LUMI_dec_ref(sarr_Refman);
  LUMI_dec_ref(tsarr_Refman);
  LUMI_dec_ref(arr_Refman);
  LUMI_dec_ref(text_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "test-complex-field"
Returncode integration_M_test_complex_field(void) {
  Returncode LUMI_err = OK;
  integration_M_HasComplexField y_Var = {{0}};
  integration_M_HasComplexField* y = NULL;
  Ref_Manager* y_Refman = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  y = &y_Var;
  y_Refman = LUMI_new_ref((void**)&y, false);
  if (y_Refman == NULL) RAISE(555, 38, "insufficient memory for managed object")
  if (y == NULL) RAISE(556, 17, "empty object used")
  if (y_Refman->value == NULL) RAISE(556, 28, "outdated weak reference used")
  if (y == NULL) RAISE(556, 17, "empty object used")
  if (y_Refman->value == NULL) RAISE(556, 28, "outdated weak reference used")
  aux_Ref_Manager = y->x.x_Refman;
  y->x.x_Refman = y_Refman;
  y->x.x_Dynamic = &integration_M_ComplexField_dynamic;
  LUMI_inc_ref(y->x.x_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  y->x.x = &(y->x);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref((void**)&aux_String_0, false);
  if (aux_String_0_Refman == NULL) RAISE(557, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "complex fields: ";
  LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(557)
  LUMI_err = integration_M_HasComplexField_run(y, y_Refman);
  CHECK(558)
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref((void**)&aux_String_1, false);
  if (aux_String_1_Refman == NULL) RAISE(559, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 1;
  aux_String_1_Var.length = 0;
  aux_String_1_Var.values = "";
  LUMI_err = Sys_println(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
  CHECK(559)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(y_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME


Returncode new_Mock(Bool* allocate_success) { return OK; }

Returncode delete_Mock(Ref self) { return OK; }

/* main function */

USER_MAIN_HEADER {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
#undef RETURN_ERROR
#define RETURN_ERROR return LUMI_err;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
  integration_M_global_int = 23;
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref((void**)&aux_String_0, false);
  if (aux_String_0_Refman == NULL) RAISE(20, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 18;
  aux_String_0_Var.length = 17;
  aux_String_0_Var.values = "a constant string";
  integration_M_global_string = aux_String_0;
  integration_M_global_string_Refman = aux_String_0_Refman;
  LUMI_inc_ref(integration_M_global_string_Refman);
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
  integration_M_int_arr = &integration_M_int_arr_Var;
  integration_M_int_arr_Var.values = integration_M_int_arr_Values;
  integration_M_int_arr_Refman = LUMI_new_ref((void**)&integration_M_int_arr, false);
  if (integration_M_int_arr_Refman == NULL) RAISE(22, 38, "insufficient memory for managed object")
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "main"
  LUMI_err = integration_M_test_simple_function();
  CHECK(563)
  LUMI_err = integration_M_test_ref_count();
  CHECK(564)
  LUMI_err = integration_M_test_error_handling(NULL, NULL);
  CHECK(565)
  LUMI_err = integration_M_test_for_each();
  CHECK(566)
  LUMI_err = integration_M_test_complex_field();
  CHECK(567)
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

MAIN_FUNC
