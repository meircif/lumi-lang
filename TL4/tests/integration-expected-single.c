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
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(s_Refman);
  if (self == NULL) RAISE(212, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(212, 38, "used member of outdated weak reference")
  self->num = x;
  if (self == NULL) RAISE(213, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(213, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->text_Refman);
  self->text_Refman = s_Refman;
  LUMI_inc_ref(self->text_Refman);
  self->text = s;
  if (x < 0) {
      aux_TestStruct_0 = LUMI_alloc(sizeof(integration_M_TestStruct));
      if (aux_TestStruct_0 == NULL) RAISE(215, 49, "insufficient memory for object dynamic allocation")
      aux_TestStruct_0_Refman = LUMI_new_ref(aux_TestStruct_0);
      if (aux_TestStruct_0_Refman == NULL) RAISE(215, 38, "insufficient memory for managed object")
      CHECK(215, integration_M_TestStruct_new(aux_TestStruct_0, aux_TestStruct_0_Refman, x + 1, s, s_Refman) )
      if (self == NULL) RAISE(215, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(215, 38, "used member of outdated weak reference")
      integration_M_TestStruct_Del(self->ts);
      LUMI_owner_dec_ref(self->ts_Refman);
      self->ts_Refman = aux_TestStruct_0_Refman;
      self->ts = aux_TestStruct_0;
      aux_TestStruct_0 = NULL;
      aux_TestStruct_0_Refman = NULL;
    }
LUMI_cleanup:
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
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(222, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(222, 38, "used member of outdated weak reference")
  *x = self->num;
  if (self == NULL) RAISE(223, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(223, 38, "used member of outdated weak reference")
  LUMI_dec_ref(*s_Refman);
  *s_Refman = self->text_Refman;
  LUMI_inc_ref(*s_Refman);
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
  if (self == NULL) RAISE(226, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(226, 38, "used member of outdated weak reference")
  CHECK(226, Sys_println(sys, sys_Refman, self->text, self->text_Refman) )
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
  if (self == NULL) RAISE(235, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(235, 38, "used member of outdated weak reference")
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
  if (self == NULL) RAISE(238, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(238, 38, "used member of outdated weak reference")
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
  if (self == NULL) RAISE(241, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(241, 38, "used member of outdated weak reference")
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
  if (self == NULL) RAISE(244, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(244, 38, "used member of outdated weak reference")
  CHECK(244, Sys_println(sys, sys_Refman, self->text, self->text_Refman) )
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
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(item_Refman);
  LUMI_inc_ref(arr_Refman);
  x = item;
  x_Refman = item_Refman;
  LUMI_inc_ref(x_Refman);
  x_Dynamic = item_Dynamic;
  if (self == NULL) RAISE(371, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(371, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->item_Refman);
  self->item_Refman = x_Refman;
  LUMI_inc_ref(self->item_Refman);
  self->item_Dynamic = x_Dynamic;
  self->item = x;
  if (self == NULL) RAISE(372, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(372, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->arr_Refman);
  self->arr_Refman = arr_Refman;
  LUMI_inc_ref(self->arr_Refman);
  self->arr = arr;
  d = LUMI_alloc(sizeof(integration_M_Data));
  if (d == NULL) RAISE(373, 49, "insufficient memory for object dynamic allocation")
  d_Refman = LUMI_new_ref(d);
  if (d_Refman == NULL) RAISE(373, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(374, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(374, 38, "used member of outdated weak reference")
  if (d == NULL) RAISE(374, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(374, 38, "used member of outdated weak reference")
  LUMI_dec_ref(d->item_Refman);
  d->item_Refman = self->item_Refman;
  LUMI_inc_ref(d->item_Refman);
  d->item_Dynamic = self->item_Dynamic;
  d->item = self->item;
  if (d == NULL) RAISE(375, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(375, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(375, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(375, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->item_Refman);
  self->item_Refman = d->item_Refman;
  LUMI_inc_ref(self->item_Refman);
  self->item_Dynamic = d->item_Dynamic;
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
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(378, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(378, 38, "used member of outdated weak reference")
  LUMI_dec_ref(*item_Refman);
  *item_Refman = self->item_Refman;
  LUMI_inc_ref(*item_Refman);
  *item_Dynamic = self->item_Dynamic;
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
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(value_Refman);
  LUMI_inc_ref(next_Refman);
  if (self == NULL) RAISE(453, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(453, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->value_Refman);
  self->value_Refman = value_Refman;
  LUMI_inc_ref(self->value_Refman);
  self->value_Dynamic = value_Dynamic;
  self->value = value;
  if (self == NULL) RAISE(454, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(454, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->next_Refman);
  self->next_Refman = next_Refman;
  LUMI_inc_ref(self->next_Refman);
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
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(457, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(457, 38, "used member of outdated weak reference")
  aux_ContainerIterator_0 = LUMI_alloc(sizeof(integration_M_ContainerIterator));
  if (aux_ContainerIterator_0 == NULL) RAISE(457, 49, "insufficient memory for object dynamic allocation")
  aux_ContainerIterator_0_Refman = LUMI_new_ref(aux_ContainerIterator_0);
  if (aux_ContainerIterator_0_Refman == NULL) RAISE(457, 38, "insufficient memory for managed object")
  CHECK(457, integration_M_ContainerIterator_new(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman, self->next, self->next_Refman) )
  integration_M_ContainerIterator_Del(*iter);
  LUMI_owner_dec_ref(*iter_Refman);
  *iter_Refman = aux_ContainerIterator_0_Refman;
  *iter = aux_ContainerIterator_0;
  aux_ContainerIterator_0 = NULL;
  aux_ContainerIterator_0_Refman = NULL;
LUMI_cleanup:
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
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(first_Refman);
  if (self == NULL) RAISE(463, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(463, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->curr_Refman);
  self->curr_Refman = first_Refman;
  LUMI_inc_ref(self->curr_Refman);
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
  if (self == NULL) RAISE(466, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(466, 38, "used member of outdated weak reference")
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
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(469, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(469, 38, "used member of outdated weak reference")
  if (self->curr == NULL) RAISE(469, 27, "used member of empty object")
  if (self->curr_Refman->value == NULL) RAISE(469, 38, "used member of outdated weak reference")
  LUMI_dec_ref(*item_Refman);
  *item_Refman = self->curr->value_Refman;
  LUMI_inc_ref(*item_Refman);
  *item_Dynamic = self->curr->value_Dynamic;
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
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(472, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(472, 38, "used member of outdated weak reference")
  if (self->curr == NULL) RAISE(472, 27, "used member of empty object")
  if (self->curr_Refman->value == NULL) RAISE(472, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(472, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(472, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->curr_Refman);
  self->curr_Refman = self->curr->next_Refman;
  LUMI_inc_ref(self->curr_Refman);
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
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(532, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 2;
  aux_String_0_Var.length = 1;
  aux_String_0_Var.values = "$";
  CHECK(532, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
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
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(537, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(537, 38, "used member of outdated weak reference")
  x = &(self->x);
  x_Refman = self_Refman;
  LUMI_inc_ref(x_Refman);
  x_Dynamic = &integration_M_ComplexField_dynamic;
  if (self == NULL) RAISE(538, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(538, 38, "used member of outdated weak reference")
  LUMI_dec_ref(x_Refman);
  x_Refman = self_Refman;
  LUMI_inc_ref(x_Refman);
  x_Dynamic = &integration_M_ComplexField_dynamic;
  x = &(self->x);
  if (x_Dynamic == NULL) RAISE(539, 28, "dynamic call of empty object")
  CHECK(539, x_Dynamic->meth(x, x_Refman, x_Dynamic) )
  if (self == NULL) RAISE(540, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(540, 38, "used member of outdated weak reference")
  CHECK(540, integration_M_ComplexField_meth(&(self->x), self_Refman, &integration_M_ComplexField_dynamic) )
  if (self == NULL) RAISE(541, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(541, 38, "used member of outdated weak reference")
  CHECK(541, integration_M_ComplexField_meth(&(self->x), self_Refman, &integration_M_ComplexField_dynamic) )
  if (self == NULL) RAISE(542, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(542, 38, "used member of outdated weak reference")
  x2 = self->x.x;
  x2_Refman = self->x.x_Refman;
  LUMI_inc_ref(x2_Refman);
  x2_Dynamic = self->x.x_Dynamic;
  if (self == NULL) RAISE(543, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(543, 38, "used member of outdated weak reference")
  LUMI_dec_ref(x2_Refman);
  x2_Refman = self->x.x_Refman;
  LUMI_inc_ref(x2_Refman);
  x2_Dynamic = self->x.x_Dynamic;
  x2 = self->x.x;
  if (x2_Dynamic == NULL) RAISE(544, 28, "dynamic call of empty object")
  CHECK(544, x2_Dynamic->meth(x2, x2_Refman, x2_Dynamic) )
  if (self->x.x_Dynamic == NULL) RAISE(545, 28, "dynamic call of empty object")
  if (self == NULL) RAISE(545, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(545, 38, "used member of outdated weak reference")
  CHECK(545, self->x.x_Dynamic->meth(self->x.x, self->x.x_Refman, self->x.x_Dynamic) )
  if (self == NULL) RAISE(546, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(546, 38, "used member of outdated weak reference")
  CHECK(546, integration_M_ComplexField_meth(self->x.x, self->x.x_Refman, self->x.x_Dynamic) )
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
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(36, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 23;
  aux_String_0_Var.length = 22;
  aux_String_0_Var.values = "I am a simple function";
  CHECK(36, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(40, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 25;
  aux_String_1_Var.length = 24;
  aux_String_1_Var.values = "I am a multiline\nstring\n";
  CHECK(37, Sys_print(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
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
  *i = (((((((0 + 9630) + -9630) + 07520) + -07520) + 0xfda940) + -0xfda940) + 0xFDA940) + -0xFDA940;
  *c = (((('a' + '\'') + '\n') + '\x0f') + '\xA9') + '\270';
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(53, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  LUMI_dec_ref(*s_Refman);
  *s_Refman = aux_String_0_Refman;
  LUMI_inc_ref(*s_Refman);
  *s = aux_String_0;
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(56, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 12;
  aux_String_1_Var.length = 11;
  aux_String_1_Var.values = "some\nstring";
  LUMI_dec_ref(*s_Refman);
  *s_Refman = aux_String_1_Refman;
  LUMI_inc_ref(*s_Refman);
  *s = aux_String_1;
  LUMI_dec_ref(*t_Refman);
  *t_Refman = NULL;
  LUMI_inc_ref(*t_Refman);
  *t = NULL;
  LUMI_dec_ref(*d_Refman);
  *d_Refman = NULL;
  LUMI_inc_ref(*d_Refman);
  *d_Dynamic = NULL;
  *d = NULL;
  *f = NULL;
  if (*f == NULL) RAISE(60, 21, "empty function called")
  CHECK(60, (*f)() )
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
  if (t == NULL) RAISE(64, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(64, 38, "used member of outdated weak reference")
  if (t->ts == NULL) RAISE(64, 27, "used member of empty object")
  if (t->ts_Refman->value == NULL) RAISE(64, 38, "used member of outdated weak reference")
  if (t->ts->ts == NULL) RAISE(64, 27, "used member of empty object")
  if (t->ts->ts_Refman->value == NULL) RAISE(64, 38, "used member of outdated weak reference")
  if (t == NULL) RAISE(64, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(64, 38, "used member of outdated weak reference")
  if (t->ts == NULL) RAISE(64, 27, "used member of empty object")
  if (t->ts_Refman->value == NULL) RAISE(64, 38, "used member of outdated weak reference")
  if (*to == NULL) RAISE(64, 27, "used member of empty object")
  if ((*to_Refman)->value == NULL) RAISE(64, 38, "used member of outdated weak reference")
  if (t == NULL) RAISE(64, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(64, 38, "used member of outdated weak reference")
  t->num = ((*to)->num + t->ts->num) + t->ts->ts->num;
  if (t == NULL) RAISE(65, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(65, 38, "used member of outdated weak reference")
  if (*to == NULL) RAISE(65, 27, "used member of empty object")
  if ((*to_Refman)->value == NULL) RAISE(65, 38, "used member of outdated weak reference")
  (*to)->num = t->num;
  if (t == NULL) RAISE(66, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(66, 38, "used member of outdated weak reference")
  if (t->ts == NULL) RAISE(66, 27, "used member of empty object")
  if (t->ts_Refman->value == NULL) RAISE(66, 38, "used member of outdated weak reference")
  if (t->ts->ts == NULL) RAISE(66, 27, "used member of empty object")
  if (t->ts->ts_Refman->value == NULL) RAISE(66, 38, "used member of outdated weak reference")
  t->ts->ts->num = 4;
  if (t == NULL) RAISE(67, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(67, 38, "used member of outdated weak reference")
  t->fun = integration_M_f_test_void;
  if (t == NULL) RAISE(68, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(68, 38, "used member of outdated weak reference")
  if (t->fun == NULL) RAISE(68, 21, "empty function called")
  CHECK(68, t->fun() )
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(69, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 1;
  aux_String_0_Var.length = 0;
  aux_String_0_Var.values = "";
  CHECK(69, integration_M_TestStruct_new(t, t_Refman, 0, aux_String_0, aux_String_0_Refman) )
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
  LUMI_inc_ref(s_Refman);
  LUMI_inc_ref(arri_Refman);
  LUMI_inc_ref(arrs_Refman);
  LUMI_inc_ref(arrt_Refman);
  LUMI_inc_ref(arrd_Refman);
  LUMI_inc_ref(arrf_Refman);
  aux_Array_0 = &aux_Array_0_Var;
  aux_Array_0_Refman = LUMI_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(89, 38, "insufficient memory for managed object")
  aux_Array_0_Var.length = 2;
  aux_Array_0_Var.values = (Byte*)((arrs)->values) + (4);
  if (arrs == NULL) RAISE(89, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(89, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (2) < 0 || (4) + (2) > (arrs)->length) RAISE(89, 25, "slice index out of bounds")
  if (aux_Array_0 == NULL) RAISE(89, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(89, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (aux_Array_0)->length) RAISE(89, 25, "slice index out of bounds")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(89, 38, "insufficient memory for managed object")
  aux_String_0_Var.length = 3;
  aux_String_0_Var.max_length = aux_String_0_Var.length + 1;
  aux_String_0_Var.values = ((((String*)((aux_Array_0)->values)) + 4))->values + (1);
  if (((String*)((aux_Array_0)->values)) + 4 == NULL) RAISE(89, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(89, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (3) < 0 || (1) + (3) > ((((String*)((aux_Array_0)->values)) + 4))->length) RAISE(89, 25, "slice index out of bounds")
  if (aux_String_0 == NULL) RAISE(89, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(89, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (aux_String_0)->length) RAISE(89, 25, "slice index out of bounds")
  if (arrs == NULL) RAISE(89, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(89, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) >= (arrs)->length) RAISE(89, 25, "slice index out of bounds")
  if (((String*)((arrs)->values)) + 3 == NULL) RAISE(89, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(89, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= ((((String*)((arrs)->values)) + 3))->length) RAISE(89, 25, "slice index out of bounds")
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(89, 38, "insufficient memory for managed object")
  aux_String_1_Var.length = 7;
  aux_String_1_Var.max_length = aux_String_1_Var.length + 1;
  aux_String_1_Var.values = (s)->values + (4);
  if (s == NULL) RAISE(89, 29, "empty object used as sequence")
  if (s_Refman->value == NULL) RAISE(89, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (7) < 0 || (4) + (7) > (s)->length) RAISE(89, 25, "slice index out of bounds")
  if (aux_String_1 == NULL) RAISE(89, 29, "empty object used as sequence")
  if (s_Refman->value == NULL) RAISE(89, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (aux_String_1)->length) RAISE(89, 25, "slice index out of bounds")
  if (s == NULL) RAISE(89, 29, "empty object used as sequence")
  if (s_Refman->value == NULL) RAISE(89, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (s)->length) RAISE(89, 25, "slice index out of bounds")
  *c = (((((s)->values)[2]) + (((aux_String_1)->values)[2])) + ((((((String*)((arrs)->values)) + 3))->values)[2])) + (((aux_String_0)->values)[0]);
  aux_Array_1 = &aux_Array_1_Var;
  aux_Array_1_Refman = LUMI_new_ref(aux_Array_1);
  if (aux_Array_1_Refman == NULL) RAISE(91, 38, "insufficient memory for managed object")
  aux_Array_1_Var.length = 3;
  aux_Array_1_Var.values = (Byte*)((arri)->values) + (3);
  if (arri == NULL) RAISE(91, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(91, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) < 0 || (3) + (3) > (arri)->length) RAISE(91, 25, "slice index out of bounds")
  aux_Array_2 = &aux_Array_2_Var;
  aux_Array_2_Refman = LUMI_new_ref(aux_Array_2);
  if (aux_Array_2_Refman == NULL) RAISE(91, 38, "insufficient memory for managed object")
  aux_Array_2_Var.length = 2;
  aux_Array_2_Var.values = (Byte*)((aux_Array_1)->values) + (1);
  if (aux_Array_1 == NULL) RAISE(91, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(91, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (2) < 0 || (1) + (2) > (aux_Array_1)->length) RAISE(91, 25, "slice index out of bounds")
  if (aux_Array_2 == NULL) RAISE(91, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(91, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (aux_Array_2)->length) RAISE(91, 25, "slice index out of bounds")
  aux_Array_3 = &aux_Array_3_Var;
  aux_Array_3_Refman = LUMI_new_ref(aux_Array_3);
  if (aux_Array_3_Refman == NULL) RAISE(90, 38, "insufficient memory for managed object")
  aux_Array_3_Var.length = 4;
  aux_Array_3_Var.values = (Byte*)((arrt)->values) + (2);
  if (arrt == NULL) RAISE(90, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(90, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arrt)->length) RAISE(90, 25, "slice index out of bounds")
  if (aux_Array_3 == NULL) RAISE(90, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(90, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (aux_Array_3)->length) RAISE(90, 25, "slice index out of bounds")
  if (((integration_M_TestStruct*)((aux_Array_3)->values)) + 1 == NULL) RAISE(90, 27, "used member of empty object")
  if (arrt_Refman->value == NULL) RAISE(90, 38, "used member of outdated weak reference")
  if (arrt == NULL) RAISE(90, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(90, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(90, 25, "slice index out of bounds")
  if (((integration_M_TestStruct*)((arrt)->values)) + 4 == NULL) RAISE(90, 27, "used member of empty object")
  if (arrt_Refman->value == NULL) RAISE(90, 38, "used member of outdated weak reference")
  if (arri == NULL) RAISE(90, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(90, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (arri)->length) RAISE(90, 25, "slice index out of bounds")
  if (arri == NULL) RAISE(90, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(90, 40, "outdated weak reference used as sequence")
  if ((((*i) + 3) - (((Int*)((arri)->values))[2])) < 0 || (*i + 3 - (((Int*)((arri)->values))[2])) >= (arri)->length) RAISE(90, 25, "slice index out of bounds")
  *i = (((((Int*)((arri)->values))[*i + 3 - (((Int*)((arri)->values))[2])]) + (((integration_M_TestStruct*)((arrt)->values)) + 4)->num) + (((integration_M_TestStruct*)((aux_Array_3)->values)) + 1)->num) + (((Int*)((aux_Array_2)->values))[1]);
  aux_Array_4 = &aux_Array_4_Var;
  aux_Array_4_Refman = LUMI_new_ref(aux_Array_4);
  if (aux_Array_4_Refman == NULL) RAISE(92, 38, "insufficient memory for managed object")
  aux_Array_4_Var.length = 4;
  aux_Array_4_Var.values = (Byte*)((arri)->values) + (2);
  if (arri == NULL) RAISE(92, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(92, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arri)->length) RAISE(92, 25, "slice index out of bounds")
  if (aux_Array_4 == NULL) RAISE(92, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(92, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (aux_Array_4)->length) RAISE(92, 25, "slice index out of bounds")
  aux_Array_5 = &aux_Array_5_Var;
  aux_Array_5_Refman = LUMI_new_ref(aux_Array_5);
  if (aux_Array_5_Refman == NULL) RAISE(92, 38, "insufficient memory for managed object")
  aux_Array_5_Var.length = 5 * ((*i) - 1);
  aux_Array_5_Var.values = (Byte*)((arri)->values) + ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1]));
  if (arri == NULL) RAISE(92, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(92, 40, "outdated weak reference used as sequence")
  if ((2 - (*i) + (((Int*)((aux_Array_4)->values))[1])) < 0 || (5 * (*i - 1)) < 0 || (2 - (*i) + (((Int*)((aux_Array_4)->values))[1])) + (5 * (*i - 1)) > (arri)->length) RAISE(92, 25, "slice index out of bounds")
  LUMI_dec_ref(*arrio_Refman);
  *arrio_Refman = arri_Refman;
  LUMI_inc_ref(*arrio_Refman);
  *arrio = aux_Array_5;
  if (arrs == NULL) RAISE(93, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(93, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrs)->length) RAISE(93, 25, "slice index out of bounds")
  LUMI_dec_ref(s_Refman);
  s_Refman = arrs_Refman;
  LUMI_inc_ref(s_Refman);
  s = ((String*)((arrs)->values)) + 4;
  aux_Array_6 = &aux_Array_6_Var;
  aux_Array_6_Refman = LUMI_new_ref(aux_Array_6);
  if (aux_Array_6_Refman == NULL) RAISE(94, 38, "insufficient memory for managed object")
  aux_Array_6_Var.length = 7;
  aux_Array_6_Var.values = (Byte*)((arrs)->values) + (2);
  if (arrs == NULL) RAISE(94, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(94, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrs)->length) RAISE(94, 25, "slice index out of bounds")
  LUMI_dec_ref(*arrso_Refman);
  *arrso_Refman = arrs_Refman;
  LUMI_inc_ref(*arrso_Refman);
  *arrso = aux_Array_6;
  if (arrt == NULL) RAISE(95, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(95, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(95, 25, "slice index out of bounds")
  LUMI_dec_ref(*t_Refman);
  *t_Refman = arrt_Refman;
  LUMI_inc_ref(*t_Refman);
  *t = ((integration_M_TestStruct*)((arrt)->values)) + 4;
  aux_Array_7 = &aux_Array_7_Var;
  aux_Array_7_Refman = LUMI_new_ref(aux_Array_7);
  if (aux_Array_7_Refman == NULL) RAISE(96, 38, "insufficient memory for managed object")
  aux_Array_7_Var.length = 7;
  aux_Array_7_Var.values = (Byte*)((arrt)->values) + (2);
  if (arrt == NULL) RAISE(96, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(96, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrt)->length) RAISE(96, 25, "slice index out of bounds")
  LUMI_dec_ref(*arrto_Refman);
  *arrto_Refman = arrt_Refman;
  LUMI_inc_ref(*arrto_Refman);
  *arrto = aux_Array_7;
  if (arrd == NULL) RAISE(97, 29, "empty object used as sequence")
  if (arrd_Refman->value == NULL) RAISE(97, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrd)->length) RAISE(97, 25, "slice index out of bounds")
  LUMI_dec_ref(*d_Refman);
  *d_Refman = arrd_Refman;
  LUMI_inc_ref(*d_Refman);
  *d_Dynamic = &integration_M_TestClass_dynamic;
  *d = ((integration_M_TestClass*)((arrd)->values)) + 4;
  aux_Array_8 = &aux_Array_8_Var;
  aux_Array_8_Refman = LUMI_new_ref(aux_Array_8);
  if (aux_Array_8_Refman == NULL) RAISE(98, 38, "insufficient memory for managed object")
  aux_Array_8_Var.length = 7;
  aux_Array_8_Var.values = (Byte*)((arrd)->values) + (2);
  if (arrd == NULL) RAISE(98, 29, "empty object used as sequence")
  if (arrd_Refman->value == NULL) RAISE(98, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrd)->length) RAISE(98, 25, "slice index out of bounds")
  LUMI_dec_ref(*arrdo_Refman);
  *arrdo_Refman = arrd_Refman;
  LUMI_inc_ref(*arrdo_Refman);
  *arrdo = aux_Array_8;
  if (arrf == NULL) RAISE(99, 29, "empty object used as sequence")
  if (arrf_Refman->value == NULL) RAISE(99, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(99, 25, "slice index out of bounds")
  *f = ((Returncode (**)(void))((arrf)->values))[4];
  aux_Array_9 = &aux_Array_9_Var;
  aux_Array_9_Refman = LUMI_new_ref(aux_Array_9);
  if (aux_Array_9_Refman == NULL) RAISE(100, 38, "insufficient memory for managed object")
  aux_Array_9_Var.length = 7;
  aux_Array_9_Var.values = (Byte*)((arrf)->values) + (2);
  if (arrf == NULL) RAISE(100, 29, "empty object used as sequence")
  if (arrf_Refman->value == NULL) RAISE(100, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrf)->length) RAISE(100, 25, "slice index out of bounds")
  LUMI_dec_ref(*arrfo_Refman);
  *arrfo_Refman = arrf_Refman;
  LUMI_inc_ref(*arrfo_Refman);
  *arrfo = aux_Array_9;
  if (arrf == NULL) RAISE(101, 29, "empty object used as sequence")
  if (arrf_Refman->value == NULL) RAISE(101, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(101, 25, "slice index out of bounds")
  if (((Returncode (**)(void))((arrf)->values))[4] == NULL) RAISE(101, 21, "empty function called")
  CHECK(101, (((Returncode (**)(void))((arrf)->values))[4])() )
  if (*arrfo == NULL) RAISE(102, 29, "empty object used as sequence")
  if ((*arrfo_Refman)->value == NULL) RAISE(102, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= ((*arrfo))->length) RAISE(102, 25, "slice index out of bounds")
  if (((Returncode (**)(void))(((*arrfo))->values))[4] == NULL) RAISE(102, 21, "empty function called")
  CHECK(102, (((Returncode (**)(void))(((*arrfo))->values))[4])() )
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
  tv_Refman = LUMI_new_ref(tv);
  if (tv_Refman == NULL) RAISE(119, 38, "insufficient memory for managed object")
  CHECK(119, integration_M_TestStruct_new(tv, tv_Refman, 0, NULL, NULL) )
  dv = &dv_Var;
  dv_Refman = LUMI_new_ref(dv);
  if (dv_Refman == NULL) RAISE(120, 38, "insufficient memory for managed object")
  CHECK(120, integration_M_TestClass_new(dv, dv_Refman, dv_Dynamic) )
  sv = &sv_Var;
  sv_Var.values = sv_Values;
  sv_Refman = LUMI_new_ref(sv);
  if (sv_Refman == NULL) RAISE(121, 38, "insufficient memory for managed object")
  ia = &ia_Var;
  ia_Var.values = ia_Values;
  ia_Refman = LUMI_new_ref(ia);
  if (ia_Refman == NULL) RAISE(123, 38, "insufficient memory for managed object")
  ta = &ta_Var;
  ta_Var.values = ta_Values;
  ta_Refman = LUMI_new_ref(ta);
  if (ta_Refman == NULL) RAISE(124, 38, "insufficient memory for managed object")
  da = &da_Var;
  da_Var.values = da_Values;
  da_Refman = LUMI_new_ref(da);
  if (da_Refman == NULL) RAISE(125, 38, "insufficient memory for managed object")
  sa = &sa_Var;
  sa_Var.values = sa_Values;
  LUMI_set_var_string_array(12, 7, sa, sa_Chars);
  sa_Refman = LUMI_new_ref(sa);
  if (sa_Refman == NULL) RAISE(126, 38, "insufficient memory for managed object")
  fa = &fa_Var;
  fa_Var.values = fa_Values;
  fa_Refman = LUMI_new_ref(fa);
  if (fa_Refman == NULL) RAISE(127, 38, "insufficient memory for managed object")
  tn = LUMI_alloc(sizeof(integration_M_TestStruct));
  if (tn == NULL) RAISE(128, 49, "insufficient memory for object dynamic allocation")
  tn_Refman = LUMI_new_ref(tn);
  if (tn_Refman == NULL) RAISE(128, 38, "insufficient memory for managed object")
  CHECK(128, integration_M_TestStruct_new(tn, tn_Refman, 0, NULL, NULL) )
  dn = LUMI_alloc(sizeof(integration_M_TestClass));
  if (dn == NULL) RAISE(129, 49, "insufficient memory for object dynamic allocation")
  dn_Refman = LUMI_new_ref(dn);
  if (dn_Refman == NULL) RAISE(129, 38, "insufficient memory for managed object")
  CHECK(129, integration_M_TestClass_new(dn, dn_Refman, dn_Dynamic) )
  if (arr == NULL) RAISE(130, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(130, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(130, 25, "slice index out of bounds")
  sn = LUMI_new_string(((Int*)((arr)->values))[0]);
  if (sn == NULL) RAISE(130, 49, "insufficient memory for object dynamic allocation")
  sn_Refman = LUMI_new_ref(sn);
  if (sn_Refman == NULL) RAISE(130, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(131, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(131, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(131, 25, "slice index out of bounds")
  ian = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if (ian == NULL) RAISE(131, 49, "insufficient memory for object dynamic allocation")
  ian_Refman = LUMI_new_ref(ian);
  if (ian_Refman == NULL) RAISE(131, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(132, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(132, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(132, 25, "slice index out of bounds")
  tan = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(integration_M_TestStruct));
  if (tan == NULL) RAISE(132, 49, "insufficient memory for object dynamic allocation")
  tan_Refman = LUMI_new_ref(tan);
  if (tan_Refman == NULL) RAISE(132, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(133, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(133, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(133, 25, "slice index out of bounds")
  dan = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(integration_M_TestClass));
  if (dan == NULL) RAISE(133, 49, "insufficient memory for object dynamic allocation")
  dan_Refman = LUMI_new_ref(dan);
  if (dan_Refman == NULL) RAISE(133, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(134, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(134, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(134, 25, "slice index out of bounds")
  if (arr == NULL) RAISE(134, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(134, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (arr)->length) RAISE(134, 25, "slice index out of bounds")
  san = LUMI_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]);
  if (san == NULL) RAISE(134, 49, "insufficient memory for object dynamic allocation")
  san_Refman = LUMI_new_ref(san);
  if (san_Refman == NULL) RAISE(134, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(135, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(135, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(135, 25, "slice index out of bounds")
  sfn = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(Func));
  if (sfn == NULL) RAISE(135, 49, "insufficient memory for object dynamic allocation")
  sfn_Refman = LUMI_new_ref(sfn);
  if (sfn_Refman == NULL) RAISE(135, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(136, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(136, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(136, 25, "slice index out of bounds")
  ix = ((Int*)((arr)->values))[0];
  si = text;
  si_Refman = text_Refman;
  LUMI_inc_ref(si_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(138, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  isv = &isv_Var;
  isv_Var.values = isv_Values;
  isv_Refman = LUMI_new_ref(isv);
  if (isv_Refman == NULL) RAISE(138, 38, "insufficient memory for managed object")
  CHECK(138, String_new(isv, isv_Refman, aux_String_0, aux_String_0_Refman) )
  isn = LUMI_new_string(i);
  if (isn == NULL) RAISE(139, 49, "insufficient memory for object dynamic allocation")
  isn_Refman = LUMI_new_ref(isn);
  if (isn_Refman == NULL) RAISE(139, 38, "insufficient memory for managed object")
  CHECK(139, String_new(isn, isn_Refman, text, text_Refman) )
  fi = integration_M_f_test_int2str;
  itv = &itv_Var;
  itv_Refman = LUMI_new_ref(itv);
  if (itv_Refman == NULL) RAISE(141, 38, "insufficient memory for managed object")
  CHECK(141, integration_M_TestStruct_new(itv, itv_Refman, i, text, text_Refman) )
  itn = LUMI_alloc(sizeof(integration_M_TestStruct));
  if (itn == NULL) RAISE(142, 49, "insufficient memory for object dynamic allocation")
  itn_Refman = LUMI_new_ref(itn);
  if (itn_Refman == NULL) RAISE(142, 38, "insufficient memory for managed object")
  CHECK(142, integration_M_TestStruct_new(itn, itn_Refman, i, text, text_Refman) )
  idv = &idv_Var;
  idv_Refman = LUMI_new_ref(idv);
  if (idv_Refman == NULL) RAISE(143, 38, "insufficient memory for managed object")
  CHECK(143, integration_M_TestClass_new(idv, idv_Refman, idv_Dynamic) )
  idn = LUMI_alloc(sizeof(integration_M_TestClass));
  if (idn == NULL) RAISE(144, 49, "insufficient memory for object dynamic allocation")
  idn_Refman = LUMI_new_ref(idn);
  if (idn_Refman == NULL) RAISE(144, 38, "insufficient memory for managed object")
  CHECK(144, integration_M_TestClass_new(idn, idn_Refman, idn_Dynamic) )
  aux_TestStruct_0 = LUMI_alloc(sizeof(integration_M_TestStruct));
  if (aux_TestStruct_0 == NULL) RAISE(145, 49, "insufficient memory for object dynamic allocation")
  aux_TestStruct_0_Refman = LUMI_new_ref(aux_TestStruct_0);
  if (aux_TestStruct_0_Refman == NULL) RAISE(145, 38, "insufficient memory for managed object")
  CHECK(145, integration_M_TestStruct_new(aux_TestStruct_0, aux_TestStruct_0_Refman, i, text, text_Refman) )
  CHECK(145, integration_M_TestStruct_print(aux_TestStruct_0, aux_TestStruct_0_Refman) )
  aux_TestClass_0 = LUMI_alloc(sizeof(integration_M_TestClass));
  if (aux_TestClass_0 == NULL) RAISE(146, 49, "insufficient memory for object dynamic allocation")
  aux_TestClass_0_Refman = LUMI_new_ref(aux_TestClass_0);
  if (aux_TestClass_0_Refman == NULL) RAISE(146, 38, "insufficient memory for managed object")
  CHECK(146, integration_M_TestClass_new(aux_TestClass_0, aux_TestClass_0_Refman, aux_TestClass_0_Dynamic) )
  CHECK(146, integration_M_TestClass_print(aux_TestClass_0, aux_TestClass_0_Refman, aux_TestClass_0_Dynamic) )
  if (arr == NULL) RAISE(147, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(147, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(147, 25, "slice index out of bounds")
  aux_String_1 = LUMI_new_string(((Int*)((arr)->values))[0]);
  if (aux_String_1 == NULL) RAISE(147, 49, "insufficient memory for object dynamic allocation")
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(147, 38, "insufficient memory for managed object")
  TEST_ASSERT(147, aux_String_1 != NULL && aux_String_1_Refman->value != NULL)
  if (arr == NULL) RAISE(148, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(148, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(148, 25, "slice index out of bounds")
  aux_Array_0 = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if (aux_Array_0 == NULL) RAISE(148, 49, "insufficient memory for object dynamic allocation")
  aux_Array_0_Refman = LUMI_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(148, 38, "insufficient memory for managed object")
  TEST_ASSERT(148, aux_Array_0 != NULL && aux_Array_0_Refman->value != NULL)
  if (arr == NULL) RAISE(149, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(149, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(149, 25, "slice index out of bounds")
  aux_Array_1 = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(integration_M_TestStruct));
  if (aux_Array_1 == NULL) RAISE(149, 49, "insufficient memory for object dynamic allocation")
  aux_Array_1_Refman = LUMI_new_ref(aux_Array_1);
  if (aux_Array_1_Refman == NULL) RAISE(149, 38, "insufficient memory for managed object")
  TEST_ASSERT(149, aux_Array_1 != NULL && aux_Array_1_Refman->value != NULL)
  if (arr == NULL) RAISE(150, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(150, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(150, 25, "slice index out of bounds")
  aux_Array_2 = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(integration_M_TestClass));
  if (aux_Array_2 == NULL) RAISE(150, 49, "insufficient memory for object dynamic allocation")
  aux_Array_2_Refman = LUMI_new_ref(aux_Array_2);
  if (aux_Array_2_Refman == NULL) RAISE(150, 38, "insufficient memory for managed object")
  TEST_ASSERT(150, aux_Array_2 != NULL && aux_Array_2_Refman->value != NULL)
  if (arr == NULL) RAISE(151, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(151, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(151, 25, "slice index out of bounds")
  if (arr == NULL) RAISE(151, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(151, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (arr)->length) RAISE(151, 25, "slice index out of bounds")
  aux_Array_3 = LUMI_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]);
  if (aux_Array_3 == NULL) RAISE(151, 49, "insufficient memory for object dynamic allocation")
  aux_Array_3_Refman = LUMI_new_ref(aux_Array_3);
  if (aux_Array_3_Refman == NULL) RAISE(151, 38, "insufficient memory for managed object")
  TEST_ASSERT(151, aux_Array_3 != NULL && aux_Array_3_Refman->value != NULL)
  if (arr == NULL) RAISE(152, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(152, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(152, 25, "slice index out of bounds")
  aux_Array_4 = LUMI_new_array(((Int*)((arr)->values))[0], sizeof(Func));
  if (aux_Array_4 == NULL) RAISE(152, 49, "insufficient memory for object dynamic allocation")
  aux_Array_4_Refman = LUMI_new_ref(aux_Array_4);
  if (aux_Array_4_Refman == NULL) RAISE(152, 38, "insufficient memory for managed object")
  TEST_ASSERT(152, aux_Array_4 != NULL && aux_Array_4_Refman->value != NULL)
  TEST_ASSERT(153, x == 0)
  TEST_ASSERT(154, s != NULL && s_Refman->value != NULL)
  TEST_ASSERT(155, a != NULL && a_Refman->value != NULL)
  CHECK(156, integration_M_TestStruct_print(t, t_Refman) )
  CHECK(157, integration_M_TestClass_print(d, d_Refman, d_Dynamic) )
  TEST_ASSERT(158, f != NULL)
  CHECK(159, integration_M_TestStruct_print(tv, tv_Refman) )
  CHECK(160, integration_M_TestClass_print(dv, dv_Refman, dv_Dynamic) )
  TEST_ASSERT(161, sv != NULL && sv_Refman->value != NULL)
  TEST_ASSERT(162, ia != NULL && ia_Refman->value != NULL)
  TEST_ASSERT(163, ta != NULL && ta_Refman->value != NULL)
  TEST_ASSERT(164, da != NULL && da_Refman->value != NULL)
  TEST_ASSERT(165, sa != NULL && sa_Refman->value != NULL)
  TEST_ASSERT(166, fa != NULL && fa_Refman->value != NULL)
  CHECK(167, integration_M_TestStruct_print(tn, tn_Refman) )
  CHECK(168, integration_M_TestClass_print(dn, dn_Refman, dn_Dynamic) )
  TEST_ASSERT(169, sn != NULL && sn_Refman->value != NULL)
  TEST_ASSERT(170, ian != NULL && ian_Refman->value != NULL)
  TEST_ASSERT(171, tan != NULL && tan_Refman->value != NULL)
  TEST_ASSERT(172, dan != NULL && dan_Refman->value != NULL)
  TEST_ASSERT(173, san != NULL && san_Refman->value != NULL)
  TEST_ASSERT(174, sfn != NULL && sfn_Refman->value != NULL)
  TEST_ASSERT(175, ix == 0)
  TEST_ASSERT(176, si != NULL && si_Refman->value != NULL)
  if (fi == NULL) RAISE(177, 21, "empty function called")
  CHECK(177, fi(7, &(aux_String_2), &(aux_String_2_Refman)) )
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
  LUMI_inc_ref(text_Refman);
  *out_num = num;
  LUMI_dec_ref(*out_text_Refman);
  *out_text_Refman = text_Refman;
  LUMI_inc_ref(*out_text_Refman);
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
  CHECK(265, integration_M_f_test_void() )
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(266, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 5;
  aux_String_0_Var.length = 4;
  aux_String_0_Var.values = "text";
  CHECK(266, integration_M_f_test_params(3, aux_String_0, aux_String_0_Refman, NULL, NULL) )
  CHECK(267, integration_M_f_test_outs(&(s), &(s_Refman), &(x)) )
  CHECK(268, integration_M_f_test_int2str(4, &(s), &(s_Refman)) )
  CHECK(269, integration_M_f_test_int(5) )
  CHECK(270, integration_M_f_test_int2int(6, &(x)) )
  CHECK(271, integration_M_f_test_many(7, 8, &(x), &(x)) )
  CHECK(277, integration_M_f_test_int2int(9, &(tmp)) )
  CHECK(277, integration_M_f_test_int(tmp) )
  CHECK(278, integration_M_f_test_many(11, 12, &(x), &(aux_Int_0)) )
  CHECK(278, integration_M_f_test_int2int(10, &(aux_Int_1)) )
  x = aux_Int_1 + aux_Int_0;
  CHECK(279, integration_M_f_test_int2str(13, &(aux_String_1), &(aux_String_1_Refman)) )
  String_Del(s);
  LUMI_owner_dec_ref(s_Refman);
  s_Refman = aux_String_1_Refman;
  s = aux_String_1;
  aux_String_1 = NULL;
  aux_String_1_Refman = NULL;
LUMI_cleanup:
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
  if (arr == NULL) RAISE(283, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(283, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arr)->length) RAISE(283, 25, "slice index out of bounds")
  if ((((Int*)((arr)->values))[4]) > 6) {
    *res = 6;
  }
  else {
    if (arr != NULL && arr_Refman->value != NULL) {
      *res = 6;
    }
    else {
      if (arr == NULL) RAISE(287, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(287, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(287, 25, "slice index out of bounds")
      if (arr == NULL) RAISE(287, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(287, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(287, 25, "slice index out of bounds")
      if ((((Int*)((arr)->values))[4]) != (((Int*)((arr)->values))[4])) {
        *res = 6;
      }
      else {
        if (arr == NULL) RAISE(289, 29, "empty object used as sequence")
        if (arr_Refman->value == NULL) RAISE(289, 40, "outdated weak reference used as sequence")
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
    if (arr == NULL) RAISE(294, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(294, 40, "outdated weak reference used as sequence")
    if ((6) < 0 || (6) >= (arr)->length) RAISE(294, 25, "slice index out of bounds")
    ((Int*)((arr)->values))[6] = 6;
    if (arr == NULL) RAISE(295, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(295, 40, "outdated weak reference used as sequence")
    if ((2) < 0 || (2) >= (arr)->length) RAISE(295, 25, "slice index out of bounds")
    x = ((Int*)((arr)->values))[2];
    if (!((x > 3) && ((void*)arr == NULL))) break;
    y = x - 1;
    while (true) {
      if (arr == NULL) RAISE(299, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(299, 40, "outdated weak reference used as sequence")
      if ((8) < 0 || (8) >= (arr)->length) RAISE(299, 25, "slice index out of bounds")
      if (arr == NULL) RAISE(299, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(299, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(299, 25, "slice index out of bounds")
      ((Int*)((arr)->values))[4] = ((Int*)((arr)->values))[8];
      if (arr == NULL) RAISE(300, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(300, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(300, 25, "slice index out of bounds")
      if (y > (((Int*)((arr)->values))[4])) {
        continue;
      }
      z = 7;
      if (arr == NULL) RAISE(303, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(303, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(303, 25, "slice index out of bounds")
      if (z <= (((Int*)((arr)->values))[4])) {
        if (!(z > 0)) break;
      }
    }
  }
  if (arr == NULL) RAISE(305, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(305, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (arr)->length) RAISE(305, 25, "slice index out of bounds")
  for (n = ((Int*)((arr)->values))[2]; n < 2 - (3 * (((Int*)((arr)->values))[2])); ++n) {
    if (arr == NULL) RAISE(306, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(306, 40, "outdated weak reference used as sequence")
    if ((2) < 0 || (2) >= (arr)->length) RAISE(306, 25, "slice index out of bounds")
    if (arr == NULL) RAISE(306, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(306, 40, "outdated weak reference used as sequence")
    if ((0) < 0 || (0) >= (arr)->length) RAISE(306, 25, "slice index out of bounds")
    ((Int*)((arr)->values))[0] = ((Int*)((arr)->values))[2];
    if (arr == NULL) RAISE(307, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(307, 40, "outdated weak reference used as sequence")
    if ((0) < 0 || (0) >= (arr)->length) RAISE(307, 25, "slice index out of bounds")
    w = ((Int*)((arr)->values))[0];
    aux_Array_0 = &aux_Array_0_Var;
    aux_Array_0_Refman = LUMI_new_ref(aux_Array_0);
    if (aux_Array_0_Refman == NULL) RAISE(308, 38, "insufficient memory for managed object")
    aux_Array_0_Var.length = 2;
    aux_Array_0_Var.values = (Byte*)((arr)->values) + (3);
    if (arr == NULL) RAISE(308, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(308, 40, "outdated weak reference used as sequence")
    if ((3) < 0 || (2) < 0 || (3) + (2) > (arr)->length) RAISE(308, 25, "slice index out of bounds")
    if ((w > 4) && ((void*)arr != aux_Array_0)) {
      if (arr == NULL) RAISE(309, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(309, 40, "outdated weak reference used as sequence")
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
  LUMI_inc_ref(s_Refman);
  LUMI_inc_ref(a_Refman);
  CHECK(317, Int_str(i, s, s_Refman) )
  bv = true || false;
  if (a == NULL) RAISE(319, 27, "used member of empty object")
  if (a_Refman->value == NULL) RAISE(319, 38, "used member of outdated weak reference")
  i = a->length;
  if (s == NULL) RAISE(320, 27, "used member of empty object")
  if (s_Refman->value == NULL) RAISE(320, 38, "used member of outdated weak reference")
  i = s->length;
  CHECK(321, String_clear(s, s_Refman) )
  CHECK(322, String_equal(s, s_Refman, s, s_Refman, &(bv)) )
  CHECK(323, String_get(s, s_Refman, i, &(cv)) )
  CHECK(324, String_append(s, s_Refman, c) )
  CHECK(325, String_new(s, s_Refman, s, s_Refman) )
  CHECK(326, String_concat(s, s_Refman, s, s_Refman) )
  CHECK(327, String_concat_int(s, s_Refman, i) )
  CHECK(328, String_find(s, s_Refman, s, s_Refman, &(iv)) )
  CHECK(329, String_has(s, s_Refman, c, &(bv)) )
  CHECK(331, file_open_read(s, s_Refman, &(f), &(f_Refman)) )
  CHECK(332, file_open_write(s, s_Refman, &(f), &(f_Refman)) )
  CHECK(333, File_getc(f, f_Refman, &(cv), &(bv)) )
  CHECK(334, File_putc(f, f_Refman, c) )
  CHECK(335, File_write(f, f_Refman, s, s_Refman) )
  CHECK(336, File_close(f, f_Refman) )
  if (sys == NULL) RAISE(337, 27, "used member of empty object")
  if (sys_Refman->value == NULL) RAISE(337, 38, "used member of outdated weak reference")
  if (sys->argv == NULL) RAISE(337, 29, "empty object used as sequence")
  if (sys->argv_Refman->value == NULL) RAISE(337, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (sys->argv)->length) RAISE(337, 25, "slice index out of bounds")
  LUMI_dec_ref(s_Refman);
  s_Refman = sys->argv_Refman;
  LUMI_inc_ref(s_Refman);
  s = ((String*)((sys->argv)->values)) + 1;
  CHECK(338, Sys_print(sys, sys_Refman, s, s_Refman) )
  CHECK(339, Sys_println(sys, sys_Refman, s, s_Refman) )
  CHECK(340, Sys_getchar(sys, sys_Refman, &(cv), &(bv)) )
  CHECK(341, Sys_getline(sys, sys_Refman, s, s_Refman) )
  CHECK(342, Sys_getenv(sys, sys_Refman, s, s_Refman, s, s_Refman, &(bv)) )
  CHECK(343, Sys_system(sys, sys_Refman, s, s_Refman, &(iv)) )
  CHECK(344, Sys_exit(sys, sys_Refman, i) )
  CHECK(345, File_putc(stdout, stdout_Refman, c) )
  CHECK(346, File_getc(stdin, stdin_Refman, &(cv), &(bv)) )
  CHECK(347, File_putc(stderr, stderr_Refman, c) )
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
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  String aux_String_2_Var = {0};
  String* aux_String_2 = NULL;
  Ref_Manager* aux_String_2_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(351, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "test string";
  s = LUMI_new_string(32);
  if (s == NULL) RAISE(351, 49, "insufficient memory for object dynamic allocation")
  s_Refman = LUMI_new_ref(s);
  if (s_Refman == NULL) RAISE(351, 38, "insufficient memory for managed object")
  CHECK(351, String_new(s, s_Refman, aux_String_0, aux_String_0_Refman) )
  s_user = s;
  s_user_Refman = s_Refman;
  LUMI_inc_ref(s_user_Refman);
  CHECK(353, Sys_println(sys, sys_Refman, s, s_Refman) )
  CHECK(354, Sys_println(sys, sys_Refman, s_user, s_user_Refman) )
  CHECK(355, integration_M_f_remove(s, s_Refman) )
  s = NULL;
  s_Refman = NULL;
  if (! (s != NULL && s_Refman->value != NULL)) {
    aux_String_1 = &aux_String_1_Var;
    aux_String_1_Refman = LUMI_new_ref(aux_String_1);
    if (aux_String_1_Refman == NULL) RAISE(357, 38, "insufficient memory for managed object")
    aux_String_1_Var.max_length = 17;
    aux_String_1_Var.length = 16;
    aux_String_1_Var.values = "ownership passed";
    CHECK(357, Sys_println(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
  }
  if (! (s_user != NULL && s_user_Refman->value != NULL)) {
    aux_String_2 = &aux_String_2_Var;
    aux_String_2_Refman = LUMI_new_ref(aux_String_2);
    if (aux_String_2_Refman == NULL) RAISE(359, 38, "insufficient memory for managed object")
    aux_String_2_Var.max_length = 15;
    aux_String_2_Var.length = 14;
    aux_String_2_Var.values = "string deleted";
    CHECK(359, Sys_println(sys, sys_Refman, aux_String_2, aux_String_2_Refman) )
  }
LUMI_cleanup:
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
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
  LUMI_inc_ref(s_Refman);
  d = &d_Var;
  d_Refman = LUMI_new_ref(d);
  if (d_Refman == NULL) RAISE(389, 38, "insufficient memory for managed object")
  sarr = &sarr_Var;
  sarr_Var.values = sarr_Values;
  LUMI_set_var_string_array(6, 16, sarr, sarr_Chars);
  sarr_Refman = LUMI_new_ref(sarr);
  if (sarr_Refman == NULL) RAISE(390, 38, "insufficient memory for managed object")
  if (d == NULL) RAISE(391, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(391, 38, "used member of outdated weak reference")
  LUMI_dec_ref(d->item_Refman);
  d->item_Refman = s_Refman;
  LUMI_inc_ref(d->item_Refman);
  d->item_Dynamic = &String_dynamic;
  d->item = s;
  if (d == NULL) RAISE(392, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(392, 38, "used member of outdated weak reference")
  LUMI_dec_ref(s_Refman);
  s_Refman = d->item_Refman;
  LUMI_inc_ref(s_Refman);
  s = d->item;
  if (d == NULL) RAISE(393, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(393, 38, "used member of outdated weak reference")
  LUMI_dec_ref(d->arr_Refman);
  d->arr_Refman = sarr_Refman;
  LUMI_inc_ref(d->arr_Refman);
  d->arr = sarr;
  if (d == NULL) RAISE(394, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(394, 38, "used member of outdated weak reference")
  if (d->arr == NULL) RAISE(394, 29, "empty object used as sequence")
  if (d->arr_Refman->value == NULL) RAISE(394, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (d->arr)->length) RAISE(394, 25, "slice index out of bounds")
  LUMI_dec_ref(s_Refman);
  s_Refman = d->arr_Refman;
  LUMI_inc_ref(s_Refman);
  s = ((String*)((d->arr)->values)) + 4;
  ad = &ad_Var;
  ad_Var.values = ad_Values;
  ad_Refman = LUMI_new_ref(ad);
  if (ad_Refman == NULL) RAISE(395, 38, "insufficient memory for managed object")
  if (ad == NULL) RAISE(396, 29, "empty object used as sequence")
  if (ad_Refman->value == NULL) RAISE(396, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (ad)->length) RAISE(396, 25, "slice index out of bounds")
  if (((integration_M_Data*)((ad)->values)) + 2 == NULL) RAISE(396, 27, "used member of empty object")
  if (ad_Refman->value == NULL) RAISE(396, 38, "used member of outdated weak reference")
  LUMI_dec_ref(s_Refman);
  s_Refman = (((integration_M_Data*)((ad)->values)) + 2)->item_Refman;
  LUMI_inc_ref(s_Refman);
  s = (((integration_M_Data*)((ad)->values)) + 2)->item;
  if (ad == NULL) RAISE(397, 29, "empty object used as sequence")
  if (ad_Refman->value == NULL) RAISE(397, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (ad)->length) RAISE(397, 25, "slice index out of bounds")
  if (((integration_M_Data*)((ad)->values)) + 2 == NULL) RAISE(397, 27, "used member of empty object")
  if (ad_Refman->value == NULL) RAISE(397, 38, "used member of outdated weak reference")
  if ((((integration_M_Data*)((ad)->values)) + 2)->arr == NULL) RAISE(397, 29, "empty object used as sequence")
  if ((((integration_M_Data*)((ad)->values)) + 2)->arr_Refman->value == NULL) RAISE(397, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) >= ((((integration_M_Data*)((ad)->values)) + 2)->arr)->length) RAISE(397, 25, "slice index out of bounds")
  LUMI_dec_ref(s_Refman);
  s_Refman = (((integration_M_Data*)((ad)->values)) + 2)->arr_Refman;
  LUMI_inc_ref(s_Refman);
  s = ((String*)(((((integration_M_Data*)((ad)->values)) + 2)->arr)->values)) + 3;
  dr = &dr_Var;
  dr_Refman = LUMI_new_ref(dr);
  if (dr_Refman == NULL) RAISE(398, 38, "insufficient memory for managed object")
  if (dr == NULL) RAISE(399, 27, "used member of empty object")
  if (dr_Refman->value == NULL) RAISE(399, 38, "used member of outdated weak reference")
  if (dr->item == NULL) RAISE(399, 27, "used member of empty object")
  if (dr->item_Refman->value == NULL) RAISE(399, 38, "used member of outdated weak reference")
  if (((integration_M_Data*)(dr->item))->item == NULL) RAISE(399, 27, "used member of empty object")
  if (((integration_M_Data*)(dr->item))->item_Refman->value == NULL) RAISE(399, 38, "used member of outdated weak reference")
  LUMI_dec_ref(s_Refman);
  s_Refman = ((integration_M_Data*)(((integration_M_Data*)(dr->item))->item))->item_Refman;
  LUMI_inc_ref(s_Refman);
  s = ((integration_M_Data*)(((integration_M_Data*)(dr->item))->item))->item;
  CHECK(400, integration_M_Data_set(d, d_Refman, s, s_Refman, &String_dynamic, sarr, sarr_Refman) )
  CHECK(401, integration_M_Data_get(d, d_Refman, (void*)&(s), &(s_Refman), &dynamic_Void) )
  dg = d;
  dg_Refman = d_Refman;
  LUMI_inc_ref(dg_Refman);
  TEST_ASSERT(403, dg != NULL && dg_Refman->value != NULL)
  t = &t_Var;
  t_Refman = LUMI_new_ref(t);
  if (t_Refman == NULL) RAISE(405, 38, "insufficient memory for managed object")
  dt = &dt_Var;
  dt_Refman = LUMI_new_ref(dt);
  if (dt_Refman == NULL) RAISE(406, 38, "insufficient memory for managed object")
  ts = &ts_Var;
  ts_Refman = LUMI_new_ref(ts);
  if (ts_Refman == NULL) RAISE(407, 38, "insufficient memory for managed object")
  CHECK(407, integration_M_TestStruct_new(ts, ts_Refman, 0, NULL, NULL) )
  if (t == NULL) RAISE(408, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(408, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->_base._base._base.item_Refman);
  t->_base._base._base.item_Refman = s_Refman;
  LUMI_inc_ref(t->_base._base._base.item_Refman);
  t->_base._base._base.item_Dynamic = &String_dynamic;
  t->_base._base._base.item = s;
  if (t == NULL) RAISE(409, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(409, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->_base._base._base.arr_Refman);
  t->_base._base._base.arr_Refman = sarr_Refman;
  LUMI_inc_ref(t->_base._base._base.arr_Refman);
  t->_base._base._base.arr = sarr;
  if (t == NULL) RAISE(410, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(410, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->_base._base.second_Refman);
  t->_base._base.second_Refman = dt_Refman;
  LUMI_inc_ref(t->_base._base.second_Refman);
  t->_base._base.second_Dynamic = &integration_M_Data_dynamic;
  t->_base._base.second = dt;
  if (t == NULL) RAISE(411, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(411, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->_base._base.third_Refman);
  t->_base._base.third_Refman = ts_Refman;
  LUMI_inc_ref(t->_base._base.third_Refman);
  t->_base._base.third_Dynamic = &integration_M_TestStruct_dynamic;
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
#define RETURN_ERROR(value) LUMI_err = value; break
    if (t == NULL) RAISE(416, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(416, 38, "used member of outdated weak reference")
    t->num = 1;

#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
  } while (false);
  --LUMI_trace_ignore_count;
  if (LUMI_err != OK) {
    LUMI_err = OK;
    aux_String_0 = &aux_String_0_Var;
    aux_String_0_Refman = LUMI_new_ref(aux_String_0);
    if (aux_String_0_Refman == NULL) RAISE(418, 38, "insufficient memory for managed object")
    aux_String_0_Var.max_length = 16;
    aux_String_0_Var.length = 15;
    aux_String_0_Var.values = "ignored message";
    USER_RAISE(418, aux_String_0, aux_String_0_Refman)
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
#define RETURN_ERROR(value) LUMI_err = value; break
    aux_String_0 = &aux_String_0_Var;
    aux_String_0_Refman = LUMI_new_ref(aux_String_0);
    if (aux_String_0_Refman == NULL) RAISE(422, 38, "insufficient memory for managed object")
    aux_String_0_Var.max_length = 20;
    aux_String_0_Var.length = 19;
    aux_String_0_Var.values = "error handling { 1 ";
    CHECK(422, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
    if (t == NULL) RAISE(423, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(423, 38, "used member of outdated weak reference")
    t->num = 1;
    aux_String_1 = &aux_String_1_Var;
    aux_String_1_Refman = LUMI_new_ref(aux_String_1);
    if (aux_String_1_Refman == NULL) RAISE(424, 38, "insufficient memory for managed object")
    aux_String_1_Var.max_length = 4;
    aux_String_1_Var.length = 3;
    aux_String_1_Var.values = " X ";
    CHECK(424, Sys_print(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
    do {
      ++LUMI_trace_ignore_count;
      CHECK(426, integration_M_f_test_void() )
    } while (false);
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
      LUMI_err = OK;
      CHECK(428, integration_M_f_test_int(2) )
    }

#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
  } while (false);
  --LUMI_trace_ignore_count;
  if (LUMI_err != OK) {
    LUMI_err = OK;
    aux_String_2 = &aux_String_2_Var;
    aux_String_2_Refman = LUMI_new_ref(aux_String_2);
    if (aux_String_2_Refman == NULL) RAISE(430, 38, "insufficient memory for managed object")
    aux_String_2_Var.max_length = 3;
    aux_String_2_Var.length = 2;
    aux_String_2_Var.values = "2 ";
    CHECK(430, Sys_print(sys, sys_Refman, aux_String_2, aux_String_2_Refman) )
    do {
      ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; break
      aux_String_3 = &aux_String_3_Var;
      aux_String_3_Refman = LUMI_new_ref(aux_String_3);
      if (aux_String_3_Refman == NULL) RAISE(432, 38, "insufficient memory for managed object")
      aux_String_3_Var.max_length = 3;
      aux_String_3_Var.length = 2;
      aux_String_3_Var.values = "3 ";
      CHECK(432, Sys_print(sys, sys_Refman, aux_String_3, aux_String_3_Refman) )
      if (t == NULL) RAISE(433, 27, "used member of empty object")
      if (t_Refman->value == NULL) RAISE(433, 38, "used member of outdated weak reference")
      t->num = 2;
      aux_String_4 = &aux_String_4_Var;
      aux_String_4_Refman = LUMI_new_ref(aux_String_4);
      if (aux_String_4_Refman == NULL) RAISE(434, 38, "insufficient memory for managed object")
      aux_String_4_Var.max_length = 4;
      aux_String_4_Var.length = 3;
      aux_String_4_Var.values = " X ";
      CHECK(434, Sys_print(sys, sys_Refman, aux_String_4, aux_String_4_Refman) )

#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
    } while (false);
    --LUMI_trace_ignore_count;
    LUMI_err = OK;
    aux_String_5 = &aux_String_5_Var;
    aux_String_5_Refman = LUMI_new_ref(aux_String_5);
    if (aux_String_5_Refman == NULL) RAISE(435, 38, "insufficient memory for managed object")
    aux_String_5_Var.max_length = 3;
    aux_String_5_Var.length = 2;
    aux_String_5_Var.values = "4 ";
    CHECK(435, Sys_print(sys, sys_Refman, aux_String_5, aux_String_5_Refman) )
  }
  aux_String_6 = &aux_String_6_Var;
  aux_String_6_Refman = LUMI_new_ref(aux_String_6);
  if (aux_String_6_Refman == NULL) RAISE(436, 38, "insufficient memory for managed object")
  aux_String_6_Var.max_length = 3;
  aux_String_6_Var.length = 2;
  aux_String_6_Var.values = "5 ";
  CHECK(436, Sys_print(sys, sys_Refman, aux_String_6, aux_String_6_Refman) )
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; break
    aux_String_7 = &aux_String_7_Var;
    aux_String_7_Refman = LUMI_new_ref(aux_String_7);
    if (aux_String_7_Refman == NULL) RAISE(438, 38, "insufficient memory for managed object")
    aux_String_7_Var.max_length = 3;
    aux_String_7_Var.length = 2;
    aux_String_7_Var.values = "6 ";
    CHECK(438, Sys_print(sys, sys_Refman, aux_String_7, aux_String_7_Refman) )
    do {
      ++LUMI_trace_ignore_count;
      aux_String_8 = &aux_String_8_Var;
      aux_String_8_Refman = LUMI_new_ref(aux_String_8);
      if (aux_String_8_Refman == NULL) RAISE(440, 38, "insufficient memory for managed object")
      aux_String_8_Var.max_length = 3;
      aux_String_8_Var.length = 2;
      aux_String_8_Var.values = "7 ";
      CHECK(440, Sys_print(sys, sys_Refman, aux_String_8, aux_String_8_Refman) )
      CHECK(441, integration_M_f_try_catch_raise(t, t_Refman) )
      aux_String_9 = &aux_String_9_Var;
      aux_String_9_Refman = LUMI_new_ref(aux_String_9);
      if (aux_String_9_Refman == NULL) RAISE(442, 38, "insufficient memory for managed object")
      aux_String_9_Var.max_length = 4;
      aux_String_9_Var.length = 3;
      aux_String_9_Var.values = " X ";
      CHECK(442, Sys_print(sys, sys_Refman, aux_String_9, aux_String_9_Refman) )
    } while (false);
    --LUMI_trace_ignore_count;
    LUMI_err = OK;
    aux_String_10 = &aux_String_10_Var;
    aux_String_10_Refman = LUMI_new_ref(aux_String_10);
    if (aux_String_10_Refman == NULL) RAISE(443, 38, "insufficient memory for managed object")
    aux_String_10_Var.max_length = 3;
    aux_String_10_Var.length = 2;
    aux_String_10_Var.values = "8 ";
    CHECK(443, Sys_print(sys, sys_Refman, aux_String_10, aux_String_10_Refman) )
    aux_String_11 = &aux_String_11_Var;
    aux_String_11_Refman = LUMI_new_ref(aux_String_11);
    if (aux_String_11_Refman == NULL) RAISE(444, 38, "insufficient memory for managed object")
    aux_String_11_Var.max_length = 24;
    aux_String_11_Var.length = 23;
    aux_String_11_Var.values = "another ignored message";
    USER_RAISE(444, aux_String_11, aux_String_11_Refman)

#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_err = OK;
  aux_String_12 = &aux_String_12_Var;
  aux_String_12_Refman = LUMI_new_ref(aux_String_12);
  if (aux_String_12_Refman == NULL) RAISE(445, 38, "insufficient memory for managed object")
  aux_String_12_Var.max_length = 2;
  aux_String_12_Var.length = 1;
  aux_String_12_Var.values = "}";
  CHECK(445, Sys_println(sys, sys_Refman, aux_String_12, aux_String_12_Refman) )
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
  text = &text_Var;
  text_Var.values = text_Values;
  text_Refman = LUMI_new_ref(text);
  if (text_Refman == NULL) RAISE(475, 38, "insufficient memory for managed object")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(476, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 8;
  aux_String_0_Var.length = 7;
  aux_String_0_Var.values = "chars[ ";
  CHECK(476, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(477, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 7;
  aux_String_1_Var.length = 6;
  aux_String_1_Var.values = "abcdef";
  LUMI_dec_ref(aux_String_2_Refman);
  aux_String_2_Refman = aux_String_1_Refman;
  LUMI_inc_ref(aux_String_2_Refman);
  aux_String_2 = aux_String_1;
  {int c_Index; for (c_Index = 0; c_Index < aux_String_2->length; ++c_Index) {
    if (aux_String_2 == NULL) RAISE(477, 29, "empty object used as sequence")
    if (aux_String_2_Refman->value == NULL) RAISE(477, 40, "outdated weak reference used as sequence")
    if ((c_Index) < 0 || (c_Index) >= (aux_String_2)->length) RAISE(477, 25, "slice index out of bounds")
    c = ((aux_String_2)->values)[c_Index];
    CHECK(478, String_clear(text, text_Refman) )
    CHECK(479, String_append(text, text_Refman, c) )
    CHECK(480, Sys_print(sys, sys_Refman, text, text_Refman) )
    aux_String_3 = &aux_String_3_Var;
    aux_String_3_Refman = LUMI_new_ref(aux_String_3);
    if (aux_String_3_Refman == NULL) RAISE(481, 38, "insufficient memory for managed object")
    aux_String_3_Var.max_length = 2;
    aux_String_3_Var.length = 1;
    aux_String_3_Var.values = " ";
    CHECK(481, Sys_print(sys, sys_Refman, aux_String_3, aux_String_3_Refman) )
  }}
  LUMI_dec_ref(aux_String_2_Refman);
  aux_String_2_Refman = NULL;
  LUMI_inc_ref(aux_String_2_Refman);
  aux_String_2 = NULL;
  aux_String_4 = &aux_String_4_Var;
  aux_String_4_Refman = LUMI_new_ref(aux_String_4);
  if (aux_String_4_Refman == NULL) RAISE(482, 38, "insufficient memory for managed object")
  aux_String_4_Var.max_length = 2;
  aux_String_4_Var.length = 1;
  aux_String_4_Var.values = "]";
  CHECK(482, Sys_println(sys, sys_Refman, aux_String_4, aux_String_4_Refman) )
  arr = &arr_Var;
  arr_Var.values = arr_Values;
  arr_Refman = LUMI_new_ref(arr);
  if (arr_Refman == NULL) RAISE(484, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(485, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(485, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(485, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[0] = 14;
  if (arr == NULL) RAISE(486, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(486, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (arr)->length) RAISE(486, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[1] = 15;
  if (arr == NULL) RAISE(487, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(487, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (arr)->length) RAISE(487, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[2] = 16;
  aux_String_5 = &aux_String_5_Var;
  aux_String_5_Refman = LUMI_new_ref(aux_String_5);
  if (aux_String_5_Refman == NULL) RAISE(488, 38, "insufficient memory for managed object")
  aux_String_5_Var.max_length = 10;
  aux_String_5_Var.length = 9;
  aux_String_5_Var.values = "numbers[ ";
  CHECK(488, Sys_print(sys, sys_Refman, aux_String_5, aux_String_5_Refman) )
  LUMI_dec_ref(aux_Array_0_Refman);
  aux_Array_0_Refman = arr_Refman;
  LUMI_inc_ref(aux_Array_0_Refman);
  aux_Array_0 = arr;
  {int n_Index; for (n_Index = 0; n_Index < aux_Array_0->length; ++n_Index) {
    if (aux_Array_0 == NULL) RAISE(489, 29, "empty object used as sequence")
    if (aux_Array_0_Refman->value == NULL) RAISE(489, 40, "outdated weak reference used as sequence")
    if ((n_Index) < 0 || (n_Index) >= (aux_Array_0)->length) RAISE(489, 25, "slice index out of bounds")
    n = ((Int*)((aux_Array_0)->values))[n_Index];
    CHECK(490, String_clear(text, text_Refman) )
    CHECK(491, Int_str(n, text, text_Refman) )
    CHECK(492, Sys_print(sys, sys_Refman, text, text_Refman) )
    aux_String_6 = &aux_String_6_Var;
    aux_String_6_Refman = LUMI_new_ref(aux_String_6);
    if (aux_String_6_Refman == NULL) RAISE(493, 38, "insufficient memory for managed object")
    aux_String_6_Var.max_length = 2;
    aux_String_6_Var.length = 1;
    aux_String_6_Var.values = " ";
    CHECK(493, Sys_print(sys, sys_Refman, aux_String_6, aux_String_6_Refman) )
  }}
  LUMI_dec_ref(aux_Array_0_Refman);
  aux_Array_0_Refman = NULL;
  LUMI_inc_ref(aux_Array_0_Refman);
  aux_Array_0 = NULL;
  aux_String_7 = &aux_String_7_Var;
  aux_String_7_Refman = LUMI_new_ref(aux_String_7);
  if (aux_String_7_Refman == NULL) RAISE(494, 38, "insufficient memory for managed object")
  aux_String_7_Var.max_length = 2;
  aux_String_7_Var.length = 1;
  aux_String_7_Var.values = "]";
  CHECK(494, Sys_println(sys, sys_Refman, aux_String_7, aux_String_7_Refman) )
  tsarr = &tsarr_Var;
  tsarr_Var.values = tsarr_Values;
  tsarr_Refman = LUMI_new_ref(tsarr);
  if (tsarr_Refman == NULL) RAISE(496, 38, "insufficient memory for managed object")
  aux_String_8 = &aux_String_8_Var;
  aux_String_8_Refman = LUMI_new_ref(aux_String_8);
  if (aux_String_8_Refman == NULL) RAISE(497, 38, "insufficient memory for managed object")
  aux_String_8_Var.max_length = 4;
  aux_String_8_Var.length = 3;
  aux_String_8_Var.values = "aaa";
  if (tsarr == NULL) RAISE(497, 29, "empty object used as sequence")
  if (tsarr_Refman->value == NULL) RAISE(497, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (tsarr)->length) RAISE(497, 25, "slice index out of bounds")
  if (((integration_M_TestStruct*)((tsarr)->values)) + 0 == NULL) RAISE(497, 27, "used member of empty object")
  if (tsarr_Refman->value == NULL) RAISE(497, 38, "used member of outdated weak reference")
  LUMI_dec_ref((((integration_M_TestStruct*)((tsarr)->values)) + 0)->text_Refman);
  (((integration_M_TestStruct*)((tsarr)->values)) + 0)->text_Refman = aux_String_8_Refman;
  LUMI_inc_ref((((integration_M_TestStruct*)((tsarr)->values)) + 0)->text_Refman);
  (((integration_M_TestStruct*)((tsarr)->values)) + 0)->text = aux_String_8;
  aux_String_9 = &aux_String_9_Var;
  aux_String_9_Refman = LUMI_new_ref(aux_String_9);
  if (aux_String_9_Refman == NULL) RAISE(498, 38, "insufficient memory for managed object")
  aux_String_9_Var.max_length = 4;
  aux_String_9_Var.length = 3;
  aux_String_9_Var.values = "bbb";
  if (tsarr == NULL) RAISE(498, 29, "empty object used as sequence")
  if (tsarr_Refman->value == NULL) RAISE(498, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (tsarr)->length) RAISE(498, 25, "slice index out of bounds")
  if (((integration_M_TestStruct*)((tsarr)->values)) + 1 == NULL) RAISE(498, 27, "used member of empty object")
  if (tsarr_Refman->value == NULL) RAISE(498, 38, "used member of outdated weak reference")
  LUMI_dec_ref((((integration_M_TestStruct*)((tsarr)->values)) + 1)->text_Refman);
  (((integration_M_TestStruct*)((tsarr)->values)) + 1)->text_Refman = aux_String_9_Refman;
  LUMI_inc_ref((((integration_M_TestStruct*)((tsarr)->values)) + 1)->text_Refman);
  (((integration_M_TestStruct*)((tsarr)->values)) + 1)->text = aux_String_9;
  aux_String_10 = &aux_String_10_Var;
  aux_String_10_Refman = LUMI_new_ref(aux_String_10);
  if (aux_String_10_Refman == NULL) RAISE(499, 38, "insufficient memory for managed object")
  aux_String_10_Var.max_length = 4;
  aux_String_10_Var.length = 3;
  aux_String_10_Var.values = "ccc";
  if (tsarr == NULL) RAISE(499, 29, "empty object used as sequence")
  if (tsarr_Refman->value == NULL) RAISE(499, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (tsarr)->length) RAISE(499, 25, "slice index out of bounds")
  if (((integration_M_TestStruct*)((tsarr)->values)) + 2 == NULL) RAISE(499, 27, "used member of empty object")
  if (tsarr_Refman->value == NULL) RAISE(499, 38, "used member of outdated weak reference")
  LUMI_dec_ref((((integration_M_TestStruct*)((tsarr)->values)) + 2)->text_Refman);
  (((integration_M_TestStruct*)((tsarr)->values)) + 2)->text_Refman = aux_String_10_Refman;
  LUMI_inc_ref((((integration_M_TestStruct*)((tsarr)->values)) + 2)->text_Refman);
  (((integration_M_TestStruct*)((tsarr)->values)) + 2)->text = aux_String_10;
  aux_String_11 = &aux_String_11_Var;
  aux_String_11_Refman = LUMI_new_ref(aux_String_11);
  if (aux_String_11_Refman == NULL) RAISE(500, 38, "insufficient memory for managed object")
  aux_String_11_Var.max_length = 10;
  aux_String_11_Var.length = 9;
  aux_String_11_Var.values = "structs[ ";
  CHECK(500, Sys_print(sys, sys_Refman, aux_String_11, aux_String_11_Refman) )
  LUMI_dec_ref(aux_Array_1_Refman);
  aux_Array_1_Refman = tsarr_Refman;
  LUMI_inc_ref(aux_Array_1_Refman);
  aux_Array_1 = tsarr;
  {int ts_Index; for (ts_Index = 0; ts_Index < aux_Array_1->length; ++ts_Index) {
    if (aux_Array_1 == NULL) RAISE(501, 29, "empty object used as sequence")
    if (aux_Array_1_Refman->value == NULL) RAISE(501, 40, "outdated weak reference used as sequence")
    if ((ts_Index) < 0 || (ts_Index) >= (aux_Array_1)->length) RAISE(501, 25, "slice index out of bounds")
    LUMI_dec_ref(ts_Refman);
    ts_Refman = aux_Array_1_Refman;
    LUMI_inc_ref(ts_Refman);
    ts = ((integration_M_TestStruct*)((aux_Array_1)->values)) + ts_Index;
    if (ts == NULL) RAISE(502, 27, "used member of empty object")
    if (ts_Refman->value == NULL) RAISE(502, 38, "used member of outdated weak reference")
    CHECK(502, Sys_print(sys, sys_Refman, ts->text, ts->text_Refman) )
    aux_String_12 = &aux_String_12_Var;
    aux_String_12_Refman = LUMI_new_ref(aux_String_12);
    if (aux_String_12_Refman == NULL) RAISE(503, 38, "insufficient memory for managed object")
    aux_String_12_Var.max_length = 2;
    aux_String_12_Var.length = 1;
    aux_String_12_Var.values = " ";
    CHECK(503, Sys_print(sys, sys_Refman, aux_String_12, aux_String_12_Refman) )
  }}
  LUMI_dec_ref(aux_Array_1_Refman);
  aux_Array_1_Refman = NULL;
  LUMI_inc_ref(aux_Array_1_Refman);
  aux_Array_1 = NULL;
  aux_String_13 = &aux_String_13_Var;
  aux_String_13_Refman = LUMI_new_ref(aux_String_13);
  if (aux_String_13_Refman == NULL) RAISE(504, 38, "insufficient memory for managed object")
  aux_String_13_Var.max_length = 2;
  aux_String_13_Var.length = 1;
  aux_String_13_Var.values = "]";
  CHECK(504, Sys_println(sys, sys_Refman, aux_String_13, aux_String_13_Refman) )
  sarr = &sarr_Var;
  sarr_Var.values = sarr_Values;
  LUMI_set_var_string_array(3, 16, sarr, sarr_Chars);
  sarr_Refman = LUMI_new_ref(sarr);
  if (sarr_Refman == NULL) RAISE(506, 38, "insufficient memory for managed object")
  if (sarr == NULL) RAISE(507, 29, "empty object used as sequence")
  if (sarr_Refman->value == NULL) RAISE(507, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (sarr)->length) RAISE(507, 25, "slice index out of bounds")
  aux_String_14 = &aux_String_14_Var;
  aux_String_14_Refman = LUMI_new_ref(aux_String_14);
  if (aux_String_14_Refman == NULL) RAISE(507, 38, "insufficient memory for managed object")
  aux_String_14_Var.max_length = 4;
  aux_String_14_Var.length = 3;
  aux_String_14_Var.values = "ddd";
  CHECK(507, String_new(((String*)((sarr)->values)) + 0, sarr_Refman, aux_String_14, aux_String_14_Refman) )
  if (sarr == NULL) RAISE(508, 29, "empty object used as sequence")
  if (sarr_Refman->value == NULL) RAISE(508, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (sarr)->length) RAISE(508, 25, "slice index out of bounds")
  aux_String_15 = &aux_String_15_Var;
  aux_String_15_Refman = LUMI_new_ref(aux_String_15);
  if (aux_String_15_Refman == NULL) RAISE(508, 38, "insufficient memory for managed object")
  aux_String_15_Var.max_length = 4;
  aux_String_15_Var.length = 3;
  aux_String_15_Var.values = "eee";
  CHECK(508, String_new(((String*)((sarr)->values)) + 1, sarr_Refman, aux_String_15, aux_String_15_Refman) )
  if (sarr == NULL) RAISE(509, 29, "empty object used as sequence")
  if (sarr_Refman->value == NULL) RAISE(509, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (sarr)->length) RAISE(509, 25, "slice index out of bounds")
  aux_String_16 = &aux_String_16_Var;
  aux_String_16_Refman = LUMI_new_ref(aux_String_16);
  if (aux_String_16_Refman == NULL) RAISE(509, 38, "insufficient memory for managed object")
  aux_String_16_Var.max_length = 4;
  aux_String_16_Var.length = 3;
  aux_String_16_Var.values = "fff";
  CHECK(509, String_new(((String*)((sarr)->values)) + 2, sarr_Refman, aux_String_16, aux_String_16_Refman) )
  aux_String_17 = &aux_String_17_Var;
  aux_String_17_Refman = LUMI_new_ref(aux_String_17);
  if (aux_String_17_Refman == NULL) RAISE(510, 38, "insufficient memory for managed object")
  aux_String_17_Var.max_length = 10;
  aux_String_17_Var.length = 9;
  aux_String_17_Var.values = "strings[ ";
  CHECK(510, Sys_print(sys, sys_Refman, aux_String_17, aux_String_17_Refman) )
  LUMI_dec_ref(aux_Array_2_Refman);
  aux_Array_2_Refman = sarr_Refman;
  LUMI_inc_ref(aux_Array_2_Refman);
  aux_Array_2 = sarr;
  {int s_Index; for (s_Index = 0; s_Index < aux_Array_2->length; ++s_Index) {
    if (aux_Array_2 == NULL) RAISE(511, 29, "empty object used as sequence")
    if (aux_Array_2_Refman->value == NULL) RAISE(511, 40, "outdated weak reference used as sequence")
    if ((s_Index) < 0 || (s_Index) >= (aux_Array_2)->length) RAISE(511, 25, "slice index out of bounds")
    LUMI_dec_ref(s_Refman);
    s_Refman = aux_Array_2_Refman;
    LUMI_inc_ref(s_Refman);
    s = ((String*)((aux_Array_2)->values)) + s_Index;
    CHECK(512, Sys_print(sys, sys_Refman, s, s_Refman) )
    aux_String_18 = &aux_String_18_Var;
    aux_String_18_Refman = LUMI_new_ref(aux_String_18);
    if (aux_String_18_Refman == NULL) RAISE(513, 38, "insufficient memory for managed object")
    aux_String_18_Var.max_length = 2;
    aux_String_18_Var.length = 1;
    aux_String_18_Var.values = " ";
    CHECK(513, Sys_print(sys, sys_Refman, aux_String_18, aux_String_18_Refman) )
  }}
  LUMI_dec_ref(aux_Array_2_Refman);
  aux_Array_2_Refman = NULL;
  LUMI_inc_ref(aux_Array_2_Refman);
  aux_Array_2 = NULL;
  aux_String_19 = &aux_String_19_Var;
  aux_String_19_Refman = LUMI_new_ref(aux_String_19);
  if (aux_String_19_Refman == NULL) RAISE(514, 38, "insufficient memory for managed object")
  aux_String_19_Var.max_length = 2;
  aux_String_19_Var.length = 1;
  aux_String_19_Var.values = "]";
  CHECK(514, Sys_println(sys, sys_Refman, aux_String_19, aux_String_19_Refman) )
  aux_String_20 = &aux_String_20_Var;
  aux_String_20_Refman = LUMI_new_ref(aux_String_20);
  if (aux_String_20_Refman == NULL) RAISE(516, 38, "insufficient memory for managed object")
  aux_String_20_Var.max_length = 4;
  aux_String_20_Var.length = 3;
  aux_String_20_Var.values = "iii";
  container_last = &container_last_Var;
  container_last_Refman = LUMI_new_ref(container_last);
  if (container_last_Refman == NULL) RAISE(516, 38, "insufficient memory for managed object")
  CHECK(516, integration_M_Container_new(container_last, container_last_Refman, aux_String_20, aux_String_20_Refman, &String_dynamic, NULL, NULL) )
  aux_String_21 = &aux_String_21_Var;
  aux_String_21_Refman = LUMI_new_ref(aux_String_21);
  if (aux_String_21_Refman == NULL) RAISE(517, 38, "insufficient memory for managed object")
  aux_String_21_Var.max_length = 4;
  aux_String_21_Var.length = 3;
  aux_String_21_Var.values = "hhh";
  container_mid = &container_mid_Var;
  container_mid_Refman = LUMI_new_ref(container_mid);
  if (container_mid_Refman == NULL) RAISE(517, 38, "insufficient memory for managed object")
  CHECK(517, integration_M_Container_new(container_mid, container_mid_Refman, aux_String_21, aux_String_21_Refman, &String_dynamic, container_last, container_last_Refman) )
  aux_String_22 = &aux_String_22_Var;
  aux_String_22_Refman = LUMI_new_ref(aux_String_22);
  if (aux_String_22_Refman == NULL) RAISE(518, 38, "insufficient memory for managed object")
  aux_String_22_Var.max_length = 4;
  aux_String_22_Var.length = 3;
  aux_String_22_Var.values = "ggg";
  container_first = &container_first_Var;
  container_first_Refman = LUMI_new_ref(container_first);
  if (container_first_Refman == NULL) RAISE(518, 38, "insufficient memory for managed object")
  CHECK(518, integration_M_Container_new(container_first, container_first_Refman, aux_String_22, aux_String_22_Refman, &String_dynamic, container_mid, container_mid_Refman) )
  container = &container_Var;
  container_Refman = LUMI_new_ref(container);
  if (container_Refman == NULL) RAISE(519, 38, "insufficient memory for managed object")
  CHECK(519, integration_M_Container_new(container, container_Refman, NULL, NULL, NULL, container_first, container_first_Refman) )
  CHECK(521, integration_M_Container_iter(container, container_Refman, &(iter), &(iter_Refman)) )
  aux_String_23 = &aux_String_23_Var;
  aux_String_23_Refman = LUMI_new_ref(aux_String_23);
  if (aux_String_23_Refman == NULL) RAISE(522, 38, "insufficient memory for managed object")
  aux_String_23_Var.max_length = 9;
  aux_String_23_Var.length = 8;
  aux_String_23_Var.values = "values[ ";
  CHECK(522, Sys_print(sys, sys_Refman, aux_String_23, aux_String_23_Refman) )
  LUMI_dec_ref(aux_ContainerIterator_0_Refman);
  aux_ContainerIterator_0_Refman = iter_Refman;
  LUMI_inc_ref(aux_ContainerIterator_0_Refman);
  aux_ContainerIterator_0 = iter;
  while (true) {
    Bool s_Has = false;
    CHECK(523, integration_M_ContainerIterator_has(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman, &(s_Has)) )
    if (!s_Has) break;
    CHECK(523, integration_M_ContainerIterator_get(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman, (void*)&(s), &(s_Refman), &dynamic_Void) )
    CHECK(524, Sys_print(sys, sys_Refman, s, s_Refman) )
    aux_String_24 = &aux_String_24_Var;
    aux_String_24_Refman = LUMI_new_ref(aux_String_24);
    if (aux_String_24_Refman == NULL) RAISE(525, 38, "insufficient memory for managed object")
    aux_String_24_Var.max_length = 2;
    aux_String_24_Var.length = 1;
    aux_String_24_Var.values = " ";
    CHECK(525, Sys_print(sys, sys_Refman, aux_String_24, aux_String_24_Refman) )
    CHECK(523, integration_M_ContainerIterator_next(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman) )
  }
  LUMI_dec_ref(aux_ContainerIterator_0_Refman);
  aux_ContainerIterator_0_Refman = NULL;
  LUMI_inc_ref(aux_ContainerIterator_0_Refman);
  aux_ContainerIterator_0 = NULL;
  aux_String_25 = &aux_String_25_Var;
  aux_String_25_Refman = LUMI_new_ref(aux_String_25);
  if (aux_String_25_Refman == NULL) RAISE(526, 38, "insufficient memory for managed object")
  aux_String_25_Var.max_length = 2;
  aux_String_25_Var.length = 1;
  aux_String_25_Var.values = "]";
  CHECK(526, Sys_println(sys, sys_Refman, aux_String_25, aux_String_25_Refman) )
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
  y = &y_Var;
  y_Refman = LUMI_new_ref(y);
  if (y_Refman == NULL) RAISE(549, 38, "insufficient memory for managed object")
  if (y == NULL) RAISE(550, 27, "used member of empty object")
  if (y_Refman->value == NULL) RAISE(550, 38, "used member of outdated weak reference")
  if (y == NULL) RAISE(550, 27, "used member of empty object")
  if (y_Refman->value == NULL) RAISE(550, 38, "used member of outdated weak reference")
  LUMI_dec_ref(y->x.x_Refman);
  y->x.x_Refman = y_Refman;
  LUMI_inc_ref(y->x.x_Refman);
  y->x.x_Dynamic = &integration_M_ComplexField_dynamic;
  y->x.x = &(y->x);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(551, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "complex fields: ";
  CHECK(551, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  CHECK(552, integration_M_HasComplexField_run(y, y_Refman) )
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(553, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 1;
  aux_String_1_Var.length = 0;
  aux_String_1_Var.values = "";
  CHECK(553, Sys_println(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
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
#define RETURN_ERROR(value) return value;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
  integration_M_global_int = 23;
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
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
  integration_M_int_arr_Refman = LUMI_new_ref(integration_M_int_arr);
  if (integration_M_int_arr_Refman == NULL) RAISE(22, 38, "insufficient memory for managed object")
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
#define LUMI_FUNC_NAME "main"
  CHECK(557, integration_M_test_simple_function() )
  CHECK(558, integration_M_test_ref_count() )
  CHECK(559, integration_M_test_error_handling(NULL, NULL) )
  CHECK(560, integration_M_test_for_each() )
  CHECK(561, integration_M_test_complex_field() )
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

MAIN_FUNC
