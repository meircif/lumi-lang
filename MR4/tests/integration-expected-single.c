#include "mr.4.h"


/* types declaration */

typedef struct TestStruct TestStruct;

typedef struct TestClass TestClass;

typedef struct TestClass_Dynamic TestClass_Dynamic;

typedef struct Data Data;

typedef struct Dataset Dataset;

typedef struct MidData MidData;

typedef struct TopData TopData;

typedef struct Container Container;

typedef struct ContainerIterator ContainerIterator;

typedef struct ComplexField ComplexField;

typedef struct ComplexField_Dynamic ComplexField_Dynamic;

typedef struct HasComplexField HasComplexField;


/* types struct */

struct TestStruct {
  Int num;
  String* text;
  Ref_Manager* text_Refman;
  TestStruct* ts;
  Ref_Manager* ts_Refman;
  Returncode (*fun)(void);
};

struct TestClass {
  Int num;
  String* text;
  Ref_Manager* text_Refman;
  TestClass* tc;
  Ref_Manager* tc_Refman;
  TestClass_Dynamic* tc_Dynamic;
};

struct TestClass_Dynamic {
  Dynamic_Del _del;
  Returncode (*dynamic_meth)(TestClass* self, Ref_Manager* self_Refman, TestClass_Dynamic* self_Dynamic);
};

struct Data {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
  Array* arr;
  Ref_Manager* arr_Refman;
};

struct Dataset {
  Data _base;
  Generic_Type* second;
  Ref_Manager* second_Refman;
  Generic_Type_Dynamic* second_Dynamic;
  Generic_Type* third;
  Ref_Manager* third_Refman;
  Generic_Type_Dynamic* third_Dynamic;
};

struct MidData {
  Dataset _base;
};

struct TopData {
  MidData _base;
};

struct Container {
  Generic_Type* value;
  Ref_Manager* value_Refman;
  Generic_Type_Dynamic* value_Dynamic;
  Container* next;
  Ref_Manager* next_Refman;
};

struct ContainerIterator {
  Container* curr;
  Ref_Manager* curr_Refman;
};

struct ComplexField {
  ComplexField* x;
  Ref_Manager* x_Refman;
  ComplexField_Dynamic* x_Dynamic;
};

struct ComplexField_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth)(ComplexField* self, Ref_Manager* self_Refman, ComplexField_Dynamic* self_Dynamic);
};

struct HasComplexField {
  ComplexField x;
};


/* types methods declaration */

Returncode TestStruct_new(TestStruct* self, Ref_Manager* self_Refman, Int x, String* s, Ref_Manager* s_Refman);

Returncode TestStruct_get(TestStruct* self, Ref_Manager* self_Refman, Int* x, String** s, Ref_Manager** s_Refman);

Returncode TestStruct_print(TestStruct* self, Ref_Manager* self_Refman);

void TestStruct_Del(TestStruct* self);

Returncode TestClass_new(TestClass* self, Ref_Manager* self_Refman, TestClass_Dynamic* self_Dynamic);

Returncode TestClass_static_meth(TestClass* self, Ref_Manager* self_Refman, TestClass_Dynamic* self_Dynamic);

Returncode TestClass_dynamic_meth(TestClass* self, Ref_Manager* self_Refman, TestClass_Dynamic* self_Dynamic);

Returncode TestClass_print(TestClass* self, Ref_Manager* self_Refman, TestClass_Dynamic* self_Dynamic);

void TestClass_Del(TestClass* self);

Returncode Data_set(Data* self, Ref_Manager* self_Refman, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic, Array* arr, Ref_Manager* arr_Refman);

Returncode Data_get(Data* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);

void Data_Del(Data* self);

void Dataset_Del(Dataset* self);

void MidData_Del(MidData* self);

void TopData_Del(TopData* self);

Returncode Container_new(Container* self, Ref_Manager* self_Refman, Generic_Type* value, Ref_Manager* value_Refman, Generic_Type_Dynamic* value_Dynamic, Container* next, Ref_Manager* next_Refman);

Returncode Container_iter(Container* self, Ref_Manager* self_Refman, ContainerIterator** iter, Ref_Manager** iter_Refman);

void Container_Del(Container* self);

Returncode ContainerIterator_new(ContainerIterator* self, Ref_Manager* self_Refman, Container* first, Ref_Manager* first_Refman);

Returncode ContainerIterator_has(ContainerIterator* self, Ref_Manager* self_Refman, Bool* has_data);

Returncode ContainerIterator_get(ContainerIterator* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);

Returncode ContainerIterator_next(ContainerIterator* self, Ref_Manager* self_Refman);

void ContainerIterator_Del(ContainerIterator* self);

Returncode ComplexField_meth(ComplexField* self, Ref_Manager* self_Refman, ComplexField_Dynamic* self_Dynamic);

void ComplexField_Del(ComplexField* self);

Returncode HasComplexField_run(HasComplexField* self, Ref_Manager* self_Refman);

void HasComplexField_Del(HasComplexField* self);


/* types global variables */

Generic_Type_Dynamic TestStruct_dynamic = {(Dynamic_Del)TestStruct_Del};

TestClass_Dynamic TestClass_dynamic = {(Dynamic_Del)TestClass_Del, TestClass_dynamic_meth};

Generic_Type_Dynamic Data_dynamic = {(Dynamic_Del)Data_Del};

Generic_Type_Dynamic Dataset_dynamic = {(Dynamic_Del)Dataset_Del};

Generic_Type_Dynamic MidData_dynamic = {(Dynamic_Del)MidData_Del};

Generic_Type_Dynamic TopData_dynamic = {(Dynamic_Del)TopData_Del};

Generic_Type_Dynamic Container_dynamic = {(Dynamic_Del)Container_Del};

Generic_Type_Dynamic ContainerIterator_dynamic = {(Dynamic_Del)ContainerIterator_Del};

ComplexField_Dynamic ComplexField_dynamic = {(Dynamic_Del)ComplexField_Del, ComplexField_meth};

Generic_Type_Dynamic HasComplexField_dynamic = {(Dynamic_Del)HasComplexField_Del};


/* global variables */

Int global_int = 0;

String* global_string = NULL;
Ref_Manager* global_string_Refman = NULL;


/* global functions declaration */

Returncode test_simple_function(void);

Returncode test_const_expression(Int* i, Char* c, String** s, Ref_Manager** s_Refman, TestStruct** t, Ref_Manager** t_Refman, TestClass** d, Ref_Manager** d_Refman, TestClass_Dynamic** d_Dynamic, Returncode (**f)(void));

Returncode test_member_expression(TestStruct* t, Ref_Manager* t_Refman, TestStruct** to, Ref_Manager** to_Refman, Int* i);

Returncode test_slice_expression(String* s, Ref_Manager* s_Refman, Array* arri, Ref_Manager* arri_Refman, Array* arrs, Ref_Manager* arrs_Refman, Array* arrt, Ref_Manager* arrt_Refman, Array* arrd, Ref_Manager* arrd_Refman, Array* arrf, Ref_Manager* arrf_Refman, Char* c, Int* i, TestStruct** t, Ref_Manager** t_Refman, TestClass** d, Ref_Manager** d_Refman, TestClass_Dynamic** d_Dynamic, Returncode (**f)(void), Array** arrio, Ref_Manager** arrio_Refman, Array** arrso, Ref_Manager** arrso_Refman, Array** arrto, Ref_Manager** arrto_Refman, Array** arrdo, Ref_Manager** arrdo_Refman, Array** arrfo, Ref_Manager** arrfo_Refman);

Returncode test_container_expression(Int x, Int y, String* s, Ref_Manager* s_Refman, Int* i, Bool* b);

Returncode test_variable(Int i, String* text, Ref_Manager* text_Refman, Array* arr, Ref_Manager* arr_Refman);

Returncode test_complex_function(Int num, String* text, Ref_Manager* text_Refman, Int* out_num, String** out_text, Ref_Manager** out_text_Refman);

Returncode f_test_void(void);

Returncode f_test_params(Int x, String* s, Ref_Manager* s_Refman, String* o, Ref_Manager* o_Refman);

Returncode f_test_outs(String** s, Ref_Manager** s_Refman, Int* x);

Returncode f_test_int2str(Int x, String** s, Ref_Manager** s_Refman);

Returncode f_test_int(Int x);

Returncode f_test_int2int(Int x, Int* r);

Returncode f_test_many(Int x, Int y, Int* n, Int* m);

Returncode test_call_expression(void);

Returncode test_code_flow(Array* arr, Ref_Manager* arr_Refman, Int* res);

Returncode test_builtins(Int i, Char c, Bool b, String* s, Ref_Manager* s_Refman, Array* a, Ref_Manager* a_Refman);

Returncode test_ref_count(void);

Returncode f_remove(String* s, Ref_Manager* s_Refman);

Returncode test_type_parameters(String* s, Ref_Manager* s_Refman);

Returncode f_try_catch_raise(TestStruct* t, Ref_Manager* t_Refman);

Returncode test_error_handling(TestStruct* t, Ref_Manager* t_Refman);

Returncode test_for_each(void);

Returncode test_complex_field(void);


/* types methods body */

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestStruct.new"
Returncode TestStruct_new(TestStruct* self, Ref_Manager* self_Refman, Int x, String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  TestStruct* aux_TestStruct_0 = NULL;
  Ref_Manager* aux_TestStruct_0_Refman = NULL;
  MR_inc_ref(s_Refman);
  if (self == NULL) RAISE(193, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(193, 38, "used member of outdated weak reference")
  self->num = x;
  if (self == NULL) RAISE(194, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(194, 38, "used member of outdated weak reference")
  MR_dec_ref(self->text_Refman);
  self->text_Refman = s_Refman;
  MR_inc_ref(self->text_Refman);
  self->text = s;
  if (x < 0) {
      aux_TestStruct_0 = calloc(1, sizeof(TestStruct));
      if (aux_TestStruct_0 == NULL) RAISE(196, 49, "insufficient memory for object dynamic allocation")
      aux_TestStruct_0_Refman = MR_new_ref(aux_TestStruct_0);
      if (aux_TestStruct_0_Refman == NULL) RAISE(196, 38, "insufficient memory for managed object")
      CHECK(196, TestStruct_new(aux_TestStruct_0, aux_TestStruct_0_Refman, x + 1, s, s_Refman) )
      if (self == NULL) RAISE(196, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(196, 38, "used member of outdated weak reference")
      TestStruct_Del(self->ts);
      MR_owner_dec_ref(self->ts_Refman);
      self->ts_Refman = aux_TestStruct_0_Refman;
      self->ts = aux_TestStruct_0;
      aux_TestStruct_0 = NULL;
      aux_TestStruct_0_Refman = NULL;
    }
MR_cleanup:
  TestStruct_Del(aux_TestStruct_0);
  MR_owner_dec_ref(aux_TestStruct_0_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestStruct.get"
Returncode TestStruct_get(TestStruct* self, Ref_Manager* self_Refman, Int* x, String** s, Ref_Manager** s_Refman) {
  Returncode MR_err = OK;
  if (self == NULL) RAISE(203, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(203, 38, "used member of outdated weak reference")
  *x = self->num;
  if (self == NULL) RAISE(204, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(204, 38, "used member of outdated weak reference")
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
Returncode TestStruct_print(TestStruct* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
  if (self == NULL) RAISE(207, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(207, 38, "used member of outdated weak reference")
  CHECK(207, Sys_println(sys, sys_Refman, self->text, self->text_Refman) )
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void TestStruct_Del(TestStruct* self) {
  if (self == NULL) return;
  SELF_REF_DEL(TestStruct, ts);
  MR_owner_dec_ref(self->ts_Refman);
  MR_dec_ref(self->text_Refman);
}

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestClass.new"
Returncode TestClass_new(TestClass* self, Ref_Manager* self_Refman, TestClass_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  if (self == NULL) RAISE(216, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(216, 38, "used member of outdated weak reference")
  self->num = 1;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestClass.static-meth"
Returncode TestClass_static_meth(TestClass* self, Ref_Manager* self_Refman, TestClass_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  if (self == NULL) RAISE(219, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(219, 38, "used member of outdated weak reference")
  self->num = 3;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestClass.dynamic-meth"
Returncode TestClass_dynamic_meth(TestClass* self, Ref_Manager* self_Refman, TestClass_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  if (self == NULL) RAISE(222, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(222, 38, "used member of outdated weak reference")
  self->num = 6;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestClass.print"
Returncode TestClass_print(TestClass* self, Ref_Manager* self_Refman, TestClass_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  if (self == NULL) RAISE(225, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(225, 38, "used member of outdated weak reference")
  CHECK(225, Sys_println(sys, sys_Refman, self->text, self->text_Refman) )
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void TestClass_Del(TestClass* self) {
  if (self == NULL) return;
  DYN_SELF_REF_DEL(TestClass, _, tc);
  MR_owner_dec_ref(self->tc_Refman);
  MR_dec_ref(self->text_Refman);
}

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "Data.set"
Returncode Data_set(Data* self, Ref_Manager* self_Refman, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic, Array* arr, Ref_Manager* arr_Refman) {
  Returncode MR_err = OK;
  Generic_Type* x = NULL;
  Ref_Manager* x_Refman = NULL;
  Generic_Type_Dynamic* x_Dynamic = NULL;
  Data* d = NULL;
  Ref_Manager* d_Refman = NULL;
  MR_inc_ref(item_Refman);
  MR_inc_ref(arr_Refman);
  x = item;
  x_Refman = item_Refman;
  MR_inc_ref(x_Refman);
  x_Dynamic = item_Dynamic;
  if (self == NULL) RAISE(352, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(352, 38, "used member of outdated weak reference")
  MR_dec_ref(self->item_Refman);
  self->item_Refman = x_Refman;
  MR_inc_ref(self->item_Refman);
  self->item_Dynamic = x_Dynamic;
  self->item = x;
  if (self == NULL) RAISE(353, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(353, 38, "used member of outdated weak reference")
  MR_dec_ref(self->arr_Refman);
  self->arr_Refman = arr_Refman;
  MR_inc_ref(self->arr_Refman);
  self->arr = arr;
  d = calloc(1, sizeof(Data));
  if (d == NULL) RAISE(354, 49, "insufficient memory for object dynamic allocation")
  d_Refman = MR_new_ref(d);
  if (d_Refman == NULL) RAISE(354, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(355, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(355, 38, "used member of outdated weak reference")
  if (d == NULL) RAISE(355, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(355, 38, "used member of outdated weak reference")
  MR_dec_ref(d->item_Refman);
  d->item_Refman = self->item_Refman;
  MR_inc_ref(d->item_Refman);
  d->item_Dynamic = self->item_Dynamic;
  d->item = self->item;
  if (d == NULL) RAISE(356, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(356, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(356, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(356, 38, "used member of outdated weak reference")
  MR_dec_ref(self->item_Refman);
  self->item_Refman = d->item_Refman;
  MR_inc_ref(self->item_Refman);
  self->item_Dynamic = d->item_Dynamic;
  self->item = d->item;
MR_cleanup:
  Data_Del(d);
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
Returncode Data_get(Data* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
  Returncode MR_err = OK;
  if (self == NULL) RAISE(359, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(359, 38, "used member of outdated weak reference")
  MR_dec_ref(*item_Refman);
  *item_Refman = self->item_Refman;
  MR_inc_ref(*item_Refman);
  *item_Dynamic = self->item_Dynamic;
  *item = self->item;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void Data_Del(Data* self) {
  if (self == NULL) return;
  MR_dec_ref(self->arr_Refman);
  MR_dec_ref(self->item_Refman);
}

void Dataset_Del(Dataset* self) {
  if (self == NULL) return;
  Data_Del(&(self->_base));
  MR_dec_ref(self->third_Refman);
  MR_dec_ref(self->second_Refman);
}

void MidData_Del(MidData* self) {
  if (self == NULL) return;
  Dataset_Del(&(self->_base));
}

void TopData_Del(TopData* self) {
  if (self == NULL) return;
  MidData_Del(&(self->_base));
}

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "Container.new"
Returncode Container_new(Container* self, Ref_Manager* self_Refman, Generic_Type* value, Ref_Manager* value_Refman, Generic_Type_Dynamic* value_Dynamic, Container* next, Ref_Manager* next_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(value_Refman);
  MR_inc_ref(next_Refman);
  if (self == NULL) RAISE(434, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(434, 38, "used member of outdated weak reference")
  MR_dec_ref(self->value_Refman);
  self->value_Refman = value_Refman;
  MR_inc_ref(self->value_Refman);
  self->value_Dynamic = value_Dynamic;
  self->value = value;
  if (self == NULL) RAISE(435, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(435, 38, "used member of outdated weak reference")
  MR_dec_ref(self->next_Refman);
  self->next_Refman = next_Refman;
  MR_inc_ref(self->next_Refman);
  self->next = next;
MR_cleanup:
  MR_dec_ref(next_Refman);
  MR_dec_ref(value_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "Container.iter"
Returncode Container_iter(Container* self, Ref_Manager* self_Refman, ContainerIterator** iter, Ref_Manager** iter_Refman) {
  Returncode MR_err = OK;
  ContainerIterator* aux_ContainerIterator_0 = NULL;
  Ref_Manager* aux_ContainerIterator_0_Refman = NULL;
  if (self == NULL) RAISE(438, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(438, 38, "used member of outdated weak reference")
  aux_ContainerIterator_0 = calloc(1, sizeof(ContainerIterator));
  if (aux_ContainerIterator_0 == NULL) RAISE(438, 49, "insufficient memory for object dynamic allocation")
  aux_ContainerIterator_0_Refman = MR_new_ref(aux_ContainerIterator_0);
  if (aux_ContainerIterator_0_Refman == NULL) RAISE(438, 38, "insufficient memory for managed object")
  CHECK(438, ContainerIterator_new(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman, self->next, self->next_Refman) )
  ContainerIterator_Del(*iter);
  MR_owner_dec_ref(*iter_Refman);
  *iter_Refman = aux_ContainerIterator_0_Refman;
  *iter = aux_ContainerIterator_0;
  aux_ContainerIterator_0 = NULL;
  aux_ContainerIterator_0_Refman = NULL;
MR_cleanup:
  ContainerIterator_Del(aux_ContainerIterator_0);
  MR_owner_dec_ref(aux_ContainerIterator_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void Container_Del(Container* self) {
  if (self == NULL) return;
  MR_dec_ref(self->next_Refman);
  MR_dec_ref(self->value_Refman);
}

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "ContainerIterator.new"
Returncode ContainerIterator_new(ContainerIterator* self, Ref_Manager* self_Refman, Container* first, Ref_Manager* first_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(first_Refman);
  if (self == NULL) RAISE(444, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(444, 38, "used member of outdated weak reference")
  MR_dec_ref(self->curr_Refman);
  self->curr_Refman = first_Refman;
  MR_inc_ref(self->curr_Refman);
  self->curr = first;
MR_cleanup:
  MR_dec_ref(first_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "ContainerIterator.has"
Returncode ContainerIterator_has(ContainerIterator* self, Ref_Manager* self_Refman, Bool* has_data) {
  Returncode MR_err = OK;
  if (self == NULL) RAISE(447, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(447, 38, "used member of outdated weak reference")
  *has_data = self->curr != NULL && self->curr_Refman->value != NULL;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "ContainerIterator.get"
Returncode ContainerIterator_get(ContainerIterator* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
  Returncode MR_err = OK;
  if (self == NULL) RAISE(450, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(450, 38, "used member of outdated weak reference")
  if (self->curr == NULL) RAISE(450, 27, "used member of empty object")
  if (self->curr_Refman->value == NULL) RAISE(450, 38, "used member of outdated weak reference")
  MR_dec_ref(*item_Refman);
  *item_Refman = self->curr->value_Refman;
  MR_inc_ref(*item_Refman);
  *item_Dynamic = self->curr->value_Dynamic;
  *item = self->curr->value;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "ContainerIterator.next"
Returncode ContainerIterator_next(ContainerIterator* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
  if (self == NULL) RAISE(453, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(453, 38, "used member of outdated weak reference")
  if (self->curr == NULL) RAISE(453, 27, "used member of empty object")
  if (self->curr_Refman->value == NULL) RAISE(453, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(453, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(453, 38, "used member of outdated weak reference")
  MR_dec_ref(self->curr_Refman);
  self->curr_Refman = self->curr->next_Refman;
  MR_inc_ref(self->curr_Refman);
  self->curr = self->curr->next;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void ContainerIterator_Del(ContainerIterator* self) {
  if (self == NULL) return;
  MR_dec_ref(self->curr_Refman);
}

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "ComplexField.meth"
Returncode ComplexField_meth(ComplexField* self, Ref_Manager* self_Refman, ComplexField_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(513, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 2;
  aux_String_0_Var.length = 1;
  aux_String_0_Var.values = "$";
  CHECK(513, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void ComplexField_Del(ComplexField* self) {
  if (self == NULL) return;
  MR_dec_ref(self->x_Refman);
}

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "HasComplexField.run"
Returncode HasComplexField_run(HasComplexField* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
  ComplexField* x = NULL;
  Ref_Manager* x_Refman = NULL;
  ComplexField_Dynamic* x_Dynamic = NULL;
  ComplexField* x2 = NULL;
  Ref_Manager* x2_Refman = NULL;
  ComplexField_Dynamic* x2_Dynamic = NULL;
  if (self == NULL) RAISE(518, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(518, 38, "used member of outdated weak reference")
  x = &(self->x);
  x_Refman = self_Refman;
  MR_inc_ref(x_Refman);
  x_Dynamic = &ComplexField_dynamic;
  if (self == NULL) RAISE(519, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(519, 38, "used member of outdated weak reference")
  MR_dec_ref(x_Refman);
  x_Refman = self_Refman;
  MR_inc_ref(x_Refman);
  x_Dynamic = &ComplexField_dynamic;
  x = &(self->x);
  if (x_Dynamic == NULL) RAISE(520, 28, "dynamic call of empty object")
  CHECK(520, x_Dynamic->meth(x, x_Refman, x_Dynamic) )
  if (self == NULL) RAISE(521, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(521, 38, "used member of outdated weak reference")
  CHECK(521, ComplexField_meth(&(self->x), self_Refman, &ComplexField_dynamic) )
  if (self == NULL) RAISE(522, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(522, 38, "used member of outdated weak reference")
  CHECK(522, ComplexField_meth(&(self->x), self_Refman, &ComplexField_dynamic) )
  if (self == NULL) RAISE(523, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(523, 38, "used member of outdated weak reference")
  x2 = self->x.x;
  x2_Refman = self->x.x_Refman;
  MR_inc_ref(x2_Refman);
  x2_Dynamic = self->x.x_Dynamic;
  if (self == NULL) RAISE(524, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(524, 38, "used member of outdated weak reference")
  MR_dec_ref(x2_Refman);
  x2_Refman = self->x.x_Refman;
  MR_inc_ref(x2_Refman);
  x2_Dynamic = self->x.x_Dynamic;
  x2 = self->x.x;
  if (x2_Dynamic == NULL) RAISE(525, 28, "dynamic call of empty object")
  CHECK(525, x2_Dynamic->meth(x2, x2_Refman, x2_Dynamic) )
  if (self->x.x_Dynamic == NULL) RAISE(526, 28, "dynamic call of empty object")
  if (self == NULL) RAISE(526, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(526, 38, "used member of outdated weak reference")
  CHECK(526, self->x.x_Dynamic->meth(self->x.x, self->x.x_Refman, self->x.x_Dynamic) )
  if (self == NULL) RAISE(527, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(527, 38, "used member of outdated weak reference")
  CHECK(527, ComplexField_meth(self->x.x, self->x.x_Refman, self->x.x_Dynamic) )
MR_cleanup:
  MR_dec_ref(x2_Refman);
  MR_dec_ref(x_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void HasComplexField_Del(HasComplexField* self) {
  if (self == NULL) return;
  ComplexField_Del(&(self->x));
}


/* global functions body */

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-simple-function"
Returncode test_simple_function(void) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(24, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 23;
  aux_String_0_Var.length = 22;
  aux_String_0_Var.values = "I am a simple function";
  CHECK(24, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-const-expression"
Returncode test_const_expression(Int* i, Char* c, String** s, Ref_Manager** s_Refman, TestStruct** t, Ref_Manager** t_Refman, TestClass** d, Ref_Manager** d_Refman, TestClass_Dynamic** d_Dynamic, Returncode (**f)(void)) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  *i = (((((((0 + 9630) + -9630) + 07520) + -07520) + 0xfda940) + -0xfda940) + 0xFDA940) + -0xFDA940;
  *c = (((('a' + '\'') + '\n') + '\x0f') + '\xA9') + '\270';
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(37, 38, "insufficient memory for managed object")
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
  if (*f == NULL) RAISE(41, 21, "empty function called")
  CHECK(41, (*f)() )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-member-expression"
Returncode test_member_expression(TestStruct* t, Ref_Manager* t_Refman, TestStruct** to, Ref_Manager** to_Refman, Int* i) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  MR_inc_ref(t_Refman);
  if (t == NULL) RAISE(45, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(45, 38, "used member of outdated weak reference")
  if (t->ts == NULL) RAISE(45, 27, "used member of empty object")
  if (t->ts_Refman->value == NULL) RAISE(45, 38, "used member of outdated weak reference")
  if (t->ts->ts == NULL) RAISE(45, 27, "used member of empty object")
  if (t->ts->ts_Refman->value == NULL) RAISE(45, 38, "used member of outdated weak reference")
  if (t == NULL) RAISE(45, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(45, 38, "used member of outdated weak reference")
  if (t->ts == NULL) RAISE(45, 27, "used member of empty object")
  if (t->ts_Refman->value == NULL) RAISE(45, 38, "used member of outdated weak reference")
  if (*to == NULL) RAISE(45, 27, "used member of empty object")
  if ((*to_Refman)->value == NULL) RAISE(45, 38, "used member of outdated weak reference")
  if (t == NULL) RAISE(45, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(45, 38, "used member of outdated weak reference")
  t->num = ((*to)->num + t->ts->num) + t->ts->ts->num;
  if (t == NULL) RAISE(46, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(46, 38, "used member of outdated weak reference")
  if (*to == NULL) RAISE(46, 27, "used member of empty object")
  if ((*to_Refman)->value == NULL) RAISE(46, 38, "used member of outdated weak reference")
  (*to)->num = t->num;
  if (t == NULL) RAISE(47, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(47, 38, "used member of outdated weak reference")
  if (t->ts == NULL) RAISE(47, 27, "used member of empty object")
  if (t->ts_Refman->value == NULL) RAISE(47, 38, "used member of outdated weak reference")
  if (t->ts->ts == NULL) RAISE(47, 27, "used member of empty object")
  if (t->ts->ts_Refman->value == NULL) RAISE(47, 38, "used member of outdated weak reference")
  t->ts->ts->num = 4;
  if (t == NULL) RAISE(48, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(48, 38, "used member of outdated weak reference")
  t->fun = f_test_void;
  if (t == NULL) RAISE(49, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(49, 38, "used member of outdated weak reference")
  if (t->fun == NULL) RAISE(49, 21, "empty function called")
  CHECK(49, t->fun() )
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(50, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 1;
  aux_String_0_Var.length = 0;
  aux_String_0_Var.values = "";
  CHECK(50, TestStruct_new(t, t_Refman, 0, aux_String_0, aux_String_0_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(t_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-slice-expression"
Returncode test_slice_expression(String* s, Ref_Manager* s_Refman, Array* arri, Ref_Manager* arri_Refman, Array* arrs, Ref_Manager* arrs_Refman, Array* arrt, Ref_Manager* arrt_Refman, Array* arrd, Ref_Manager* arrd_Refman, Array* arrf, Ref_Manager* arrf_Refman, Char* c, Int* i, TestStruct** t, Ref_Manager** t_Refman, TestClass** d, Ref_Manager** d_Refman, TestClass_Dynamic** d_Dynamic, Returncode (**f)(void), Array** arrio, Ref_Manager** arrio_Refman, Array** arrso, Ref_Manager** arrso_Refman, Array** arrto, Ref_Manager** arrto_Refman, Array** arrdo, Ref_Manager** arrdo_Refman, Array** arrfo, Ref_Manager** arrfo_Refman) {
  Returncode MR_err = OK;
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
  MR_inc_ref(s_Refman);
  MR_inc_ref(arri_Refman);
  MR_inc_ref(arrs_Refman);
  MR_inc_ref(arrt_Refman);
  MR_inc_ref(arrd_Refman);
  MR_inc_ref(arrf_Refman);
  aux_Array_0 = &aux_Array_0_Var;
  aux_Array_0_Refman = MR_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(70, 38, "insufficient memory for managed object")
  aux_Array_0_Var.length = 2;
  aux_Array_0_Var.values = (Byte*)((arrs)->values) + (4);
  if (arrs == NULL) RAISE(70, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(70, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (2) < 0 || (4) + (2) > (arrs)->length) RAISE(70, 25, "slice index out of bounds")
  if (aux_Array_0 == NULL) RAISE(70, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(70, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (aux_Array_0)->length) RAISE(70, 25, "slice index out of bounds")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(70, 38, "insufficient memory for managed object")
  aux_String_0_Var.length = 3;
  aux_String_0_Var.max_length = aux_String_0_Var.length + 1;
  aux_String_0_Var.values = ((((String*)((aux_Array_0)->values)) + 4))->values + (1);
  if (((String*)((aux_Array_0)->values)) + 4 == NULL) RAISE(70, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(70, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (3) < 0 || (1) + (3) > ((((String*)((aux_Array_0)->values)) + 4))->length) RAISE(70, 25, "slice index out of bounds")
  if (aux_String_0 == NULL) RAISE(70, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(70, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (aux_String_0)->length) RAISE(70, 25, "slice index out of bounds")
  if (arrs == NULL) RAISE(70, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(70, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) >= (arrs)->length) RAISE(70, 25, "slice index out of bounds")
  if (((String*)((arrs)->values)) + 3 == NULL) RAISE(70, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(70, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= ((((String*)((arrs)->values)) + 3))->length) RAISE(70, 25, "slice index out of bounds")
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = MR_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(70, 38, "insufficient memory for managed object")
  aux_String_1_Var.length = 7;
  aux_String_1_Var.max_length = aux_String_1_Var.length + 1;
  aux_String_1_Var.values = (s)->values + (4);
  if (s == NULL) RAISE(70, 29, "empty object used as sequence")
  if (s_Refman->value == NULL) RAISE(70, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (7) < 0 || (4) + (7) > (s)->length) RAISE(70, 25, "slice index out of bounds")
  if (aux_String_1 == NULL) RAISE(70, 29, "empty object used as sequence")
  if (s_Refman->value == NULL) RAISE(70, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (aux_String_1)->length) RAISE(70, 25, "slice index out of bounds")
  if (s == NULL) RAISE(70, 29, "empty object used as sequence")
  if (s_Refman->value == NULL) RAISE(70, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (s)->length) RAISE(70, 25, "slice index out of bounds")
  *c = (((((s)->values)[2]) + (((aux_String_1)->values)[2])) + ((((((String*)((arrs)->values)) + 3))->values)[2])) + (((aux_String_0)->values)[0]);
  aux_Array_1 = &aux_Array_1_Var;
  aux_Array_1_Refman = MR_new_ref(aux_Array_1);
  if (aux_Array_1_Refman == NULL) RAISE(72, 38, "insufficient memory for managed object")
  aux_Array_1_Var.length = 3;
  aux_Array_1_Var.values = (Byte*)((arri)->values) + (3);
  if (arri == NULL) RAISE(72, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(72, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) < 0 || (3) + (3) > (arri)->length) RAISE(72, 25, "slice index out of bounds")
  aux_Array_2 = &aux_Array_2_Var;
  aux_Array_2_Refman = MR_new_ref(aux_Array_2);
  if (aux_Array_2_Refman == NULL) RAISE(72, 38, "insufficient memory for managed object")
  aux_Array_2_Var.length = 2;
  aux_Array_2_Var.values = (Byte*)((aux_Array_1)->values) + (1);
  if (aux_Array_1 == NULL) RAISE(72, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(72, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (2) < 0 || (1) + (2) > (aux_Array_1)->length) RAISE(72, 25, "slice index out of bounds")
  if (aux_Array_2 == NULL) RAISE(72, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(72, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (aux_Array_2)->length) RAISE(72, 25, "slice index out of bounds")
  aux_Array_3 = &aux_Array_3_Var;
  aux_Array_3_Refman = MR_new_ref(aux_Array_3);
  if (aux_Array_3_Refman == NULL) RAISE(71, 38, "insufficient memory for managed object")
  aux_Array_3_Var.length = 4;
  aux_Array_3_Var.values = (Byte*)((arrt)->values) + (2);
  if (arrt == NULL) RAISE(71, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(71, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arrt)->length) RAISE(71, 25, "slice index out of bounds")
  if (aux_Array_3 == NULL) RAISE(71, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(71, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (aux_Array_3)->length) RAISE(71, 25, "slice index out of bounds")
  if (((TestStruct*)((aux_Array_3)->values)) + 1 == NULL) RAISE(71, 27, "used member of empty object")
  if (arrt_Refman->value == NULL) RAISE(71, 38, "used member of outdated weak reference")
  if (arrt == NULL) RAISE(71, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(71, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(71, 25, "slice index out of bounds")
  if (((TestStruct*)((arrt)->values)) + 4 == NULL) RAISE(71, 27, "used member of empty object")
  if (arrt_Refman->value == NULL) RAISE(71, 38, "used member of outdated weak reference")
  if (arri == NULL) RAISE(71, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(71, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (arri)->length) RAISE(71, 25, "slice index out of bounds")
  if (arri == NULL) RAISE(71, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(71, 40, "outdated weak reference used as sequence")
  if ((((*i) + 3) - (((Int*)((arri)->values))[2])) < 0 || (((*i) + 3) - (((Int*)((arri)->values))[2])) >= (arri)->length) RAISE(71, 25, "slice index out of bounds")
  *i = (((((Int*)((arri)->values))[((*i) + 3) - (((Int*)((arri)->values))[2])]) + (((TestStruct*)((arrt)->values)) + 4)->num) + (((TestStruct*)((aux_Array_3)->values)) + 1)->num) + (((Int*)((aux_Array_2)->values))[1]);
  aux_Array_4 = &aux_Array_4_Var;
  aux_Array_4_Refman = MR_new_ref(aux_Array_4);
  if (aux_Array_4_Refman == NULL) RAISE(73, 38, "insufficient memory for managed object")
  aux_Array_4_Var.length = 4;
  aux_Array_4_Var.values = (Byte*)((arri)->values) + (2);
  if (arri == NULL) RAISE(73, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(73, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arri)->length) RAISE(73, 25, "slice index out of bounds")
  if (aux_Array_4 == NULL) RAISE(73, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(73, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (aux_Array_4)->length) RAISE(73, 25, "slice index out of bounds")
  aux_Array_5 = &aux_Array_5_Var;
  aux_Array_5_Refman = MR_new_ref(aux_Array_5);
  if (aux_Array_5_Refman == NULL) RAISE(73, 38, "insufficient memory for managed object")
  aux_Array_5_Var.length = 5 * ((*i) - 1);
  aux_Array_5_Var.values = (Byte*)((arri)->values) + ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1]));
  if (arri == NULL) RAISE(73, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(73, 40, "outdated weak reference used as sequence")
  if (((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1])) < 0 || (5 * ((*i) - 1)) < 0 || ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1])) + (5 * ((*i) - 1)) > (arri)->length) RAISE(73, 25, "slice index out of bounds")
  MR_dec_ref(*arrio_Refman);
  *arrio_Refman = arri_Refman;
  MR_inc_ref(*arrio_Refman);
  *arrio = aux_Array_5;
  if (arrs == NULL) RAISE(74, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(74, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrs)->length) RAISE(74, 25, "slice index out of bounds")
  MR_dec_ref(s_Refman);
  s_Refman = arrs_Refman;
  MR_inc_ref(s_Refman);
  s = ((String*)((arrs)->values)) + 4;
  aux_Array_6 = &aux_Array_6_Var;
  aux_Array_6_Refman = MR_new_ref(aux_Array_6);
  if (aux_Array_6_Refman == NULL) RAISE(75, 38, "insufficient memory for managed object")
  aux_Array_6_Var.length = 7;
  aux_Array_6_Var.values = (Byte*)((arrs)->values) + (2);
  if (arrs == NULL) RAISE(75, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(75, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrs)->length) RAISE(75, 25, "slice index out of bounds")
  MR_dec_ref(*arrso_Refman);
  *arrso_Refman = arrs_Refman;
  MR_inc_ref(*arrso_Refman);
  *arrso = aux_Array_6;
  if (arrt == NULL) RAISE(76, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(76, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(76, 25, "slice index out of bounds")
  MR_dec_ref(*t_Refman);
  *t_Refman = arrt_Refman;
  MR_inc_ref(*t_Refman);
  *t = ((TestStruct*)((arrt)->values)) + 4;
  aux_Array_7 = &aux_Array_7_Var;
  aux_Array_7_Refman = MR_new_ref(aux_Array_7);
  if (aux_Array_7_Refman == NULL) RAISE(77, 38, "insufficient memory for managed object")
  aux_Array_7_Var.length = 7;
  aux_Array_7_Var.values = (Byte*)((arrt)->values) + (2);
  if (arrt == NULL) RAISE(77, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(77, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrt)->length) RAISE(77, 25, "slice index out of bounds")
  MR_dec_ref(*arrto_Refman);
  *arrto_Refman = arrt_Refman;
  MR_inc_ref(*arrto_Refman);
  *arrto = aux_Array_7;
  if (arrd == NULL) RAISE(78, 29, "empty object used as sequence")
  if (arrd_Refman->value == NULL) RAISE(78, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrd)->length) RAISE(78, 25, "slice index out of bounds")
  MR_dec_ref(*d_Refman);
  *d_Refman = arrd_Refman;
  MR_inc_ref(*d_Refman);
  *d_Dynamic = &TestClass_dynamic;
  *d = ((TestClass*)((arrd)->values)) + 4;
  aux_Array_8 = &aux_Array_8_Var;
  aux_Array_8_Refman = MR_new_ref(aux_Array_8);
  if (aux_Array_8_Refman == NULL) RAISE(79, 38, "insufficient memory for managed object")
  aux_Array_8_Var.length = 7;
  aux_Array_8_Var.values = (Byte*)((arrd)->values) + (2);
  if (arrd == NULL) RAISE(79, 29, "empty object used as sequence")
  if (arrd_Refman->value == NULL) RAISE(79, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrd)->length) RAISE(79, 25, "slice index out of bounds")
  MR_dec_ref(*arrdo_Refman);
  *arrdo_Refman = arrd_Refman;
  MR_inc_ref(*arrdo_Refman);
  *arrdo = aux_Array_8;
  if (arrf == NULL) RAISE(80, 29, "empty object used as sequence")
  if (arrf_Refman->value == NULL) RAISE(80, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(80, 25, "slice index out of bounds")
  *f = ((Returncode (**)(void))((arrf)->values))[4];
  aux_Array_9 = &aux_Array_9_Var;
  aux_Array_9_Refman = MR_new_ref(aux_Array_9);
  if (aux_Array_9_Refman == NULL) RAISE(81, 38, "insufficient memory for managed object")
  aux_Array_9_Var.length = 7;
  aux_Array_9_Var.values = (Byte*)((arrf)->values) + (2);
  if (arrf == NULL) RAISE(81, 29, "empty object used as sequence")
  if (arrf_Refman->value == NULL) RAISE(81, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrf)->length) RAISE(81, 25, "slice index out of bounds")
  MR_dec_ref(*arrfo_Refman);
  *arrfo_Refman = arrf_Refman;
  MR_inc_ref(*arrfo_Refman);
  *arrfo = aux_Array_9;
  if (arrf == NULL) RAISE(82, 29, "empty object used as sequence")
  if (arrf_Refman->value == NULL) RAISE(82, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(82, 25, "slice index out of bounds")
  if (((Returncode (**)(void))((arrf)->values))[4] == NULL) RAISE(82, 21, "empty function called")
  CHECK(82, (((Returncode (**)(void))((arrf)->values))[4])() )
  if (*arrfo == NULL) RAISE(83, 29, "empty object used as sequence")
  if ((*arrfo_Refman)->value == NULL) RAISE(83, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= ((*arrfo))->length) RAISE(83, 25, "slice index out of bounds")
  if (((Returncode (**)(void))(((*arrfo))->values))[4] == NULL) RAISE(83, 21, "empty function called")
  CHECK(83, (((Returncode (**)(void))(((*arrfo))->values))[4])() )
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
Returncode test_container_expression(Int x, Int y, String* s, Ref_Manager* s_Refman, Int* i, Bool* b) {
  Returncode MR_err = OK;
  MR_inc_ref(s_Refman);
  *i = (- x) + (- (- (- y)));
  *b = (! (((! ((((x * 3) - 5) > (6 * y)) && ((6 * y) == 234))) && (! ((5 - x) < y))) || (! ((x == (-2 - (-4 * y))) && (((-6 > y) && (y >= 12)) && (12 == x)))))) && ((((- (2 + x)) > y) || (s != NULL && s_Refman->value != NULL)) || (! (s != NULL && s_Refman->value != NULL)));
MR_cleanup:
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-variable"
Returncode test_variable(Int i, String* text, Ref_Manager* text_Refman, Array* arr, Ref_Manager* arr_Refman) {
  Returncode MR_err = OK;
  Int x = 0;
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  Array* a = NULL;
  Ref_Manager* a_Refman = NULL;
  TestStruct* t = NULL;
  Ref_Manager* t_Refman = NULL;
  TestClass* d = NULL;
  Ref_Manager* d_Refman = NULL;
  TestClass_Dynamic* d_Dynamic = NULL;
  TestStruct tv_Var = {0};
  TestStruct* tv = NULL;
  Ref_Manager* tv_Refman = NULL;
  TestClass dv_Var = {0};
  TestClass* dv = NULL;
  Ref_Manager* dv_Refman = NULL;
  TestClass_Dynamic* dv_Dynamic = &TestClass_dynamic;
  char sv_Values[12] = {0};
  String sv_Var = {12, 0, NULL};
  String* sv = NULL;
  Ref_Manager* sv_Refman = NULL;
  Returncode (*f)(Int xi, String* si, Ref_Manager* si_Refman, Int* xo, String** so, Ref_Manager** so_Refman) = NULL;
  Int ia_Values[12] = {0};
  Array ia_Var = {12, NULL};
  Array* ia = NULL;
  Ref_Manager* ia_Refman = NULL;
  TestStruct ta_Values[12] = {{0}};
  Array ta_Var = {12, NULL};
  Array* ta = NULL;
  Ref_Manager* ta_Refman = NULL;
  TestClass da_Values[12] = {{0}};
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
  TestStruct* tn = NULL;
  Ref_Manager* tn_Refman = NULL;
  TestClass* dn = NULL;
  Ref_Manager* dn_Refman = NULL;
  TestClass_Dynamic* dn_Dynamic = &TestClass_dynamic;
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
  TestStruct itv_Var = {0};
  TestStruct* itv = NULL;
  Ref_Manager* itv_Refman = NULL;
  TestStruct* itn = NULL;
  Ref_Manager* itn_Refman = NULL;
  TestClass idv_Var = {0};
  TestClass* idv = NULL;
  Ref_Manager* idv_Refman = NULL;
  TestClass_Dynamic* idv_Dynamic = &TestClass_dynamic;
  TestClass* idn = NULL;
  Ref_Manager* idn_Refman = NULL;
  TestClass_Dynamic* idn_Dynamic = &TestClass_dynamic;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  TestStruct* aux_TestStruct_0 = NULL;
  Ref_Manager* aux_TestStruct_0_Refman = NULL;
  TestClass* aux_TestClass_0 = NULL;
  Ref_Manager* aux_TestClass_0_Refman = NULL;
  TestClass_Dynamic* aux_TestClass_0_Dynamic = &TestClass_dynamic;
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
  MR_inc_ref(text_Refman);
  MR_inc_ref(arr_Refman);
  tv = &tv_Var;
  tv_Refman = MR_new_ref(tv);
  if (tv_Refman == NULL) RAISE(100, 38, "insufficient memory for managed object")
  CHECK(100, TestStruct_new(tv, tv_Refman, 0, NULL, NULL) )
  dv = &dv_Var;
  dv_Refman = MR_new_ref(dv);
  if (dv_Refman == NULL) RAISE(101, 38, "insufficient memory for managed object")
  CHECK(101, TestClass_new(dv, dv_Refman, dv_Dynamic) )
  sv = &sv_Var;
  sv_Var.values = sv_Values;
  sv_Refman = MR_new_ref(sv);
  if (sv_Refman == NULL) RAISE(102, 38, "insufficient memory for managed object")
  ia = &ia_Var;
  ia_Var.values = ia_Values;
  ia_Refman = MR_new_ref(ia);
  if (ia_Refman == NULL) RAISE(104, 38, "insufficient memory for managed object")
  ta = &ta_Var;
  ta_Var.values = ta_Values;
  ta_Refman = MR_new_ref(ta);
  if (ta_Refman == NULL) RAISE(105, 38, "insufficient memory for managed object")
  da = &da_Var;
  da_Var.values = da_Values;
  da_Refman = MR_new_ref(da);
  if (da_Refman == NULL) RAISE(106, 38, "insufficient memory for managed object")
  sa = &sa_Var;
  sa_Var.values = sa_Values;
  MR_set_var_string_array(12, 7, sa, sa_Chars);
  sa_Refman = MR_new_ref(sa);
  if (sa_Refman == NULL) RAISE(107, 38, "insufficient memory for managed object")
  fa = &fa_Var;
  fa_Var.values = fa_Values;
  fa_Refman = MR_new_ref(fa);
  if (fa_Refman == NULL) RAISE(108, 38, "insufficient memory for managed object")
  tn = calloc(1, sizeof(TestStruct));
  if (tn == NULL) RAISE(109, 49, "insufficient memory for object dynamic allocation")
  tn_Refman = MR_new_ref(tn);
  if (tn_Refman == NULL) RAISE(109, 38, "insufficient memory for managed object")
  CHECK(109, TestStruct_new(tn, tn_Refman, 0, NULL, NULL) )
  dn = calloc(1, sizeof(TestClass));
  if (dn == NULL) RAISE(110, 49, "insufficient memory for object dynamic allocation")
  dn_Refman = MR_new_ref(dn);
  if (dn_Refman == NULL) RAISE(110, 38, "insufficient memory for managed object")
  CHECK(110, TestClass_new(dn, dn_Refman, dn_Dynamic) )
  if (arr == NULL) RAISE(111, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(111, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(111, 25, "slice index out of bounds")
  sn = MR_new_string(((Int*)((arr)->values))[0]);
  if (sn == NULL) RAISE(111, 49, "insufficient memory for object dynamic allocation")
  sn_Refman = MR_new_ref(sn);
  if (sn_Refman == NULL) RAISE(111, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(112, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(112, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(112, 25, "slice index out of bounds")
  ian = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if (ian == NULL) RAISE(112, 49, "insufficient memory for object dynamic allocation")
  ian_Refman = MR_new_ref(ian);
  if (ian_Refman == NULL) RAISE(112, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(113, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(113, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(113, 25, "slice index out of bounds")
  tan = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestStruct));
  if (tan == NULL) RAISE(113, 49, "insufficient memory for object dynamic allocation")
  tan_Refman = MR_new_ref(tan);
  if (tan_Refman == NULL) RAISE(113, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(114, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(114, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(114, 25, "slice index out of bounds")
  dan = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestClass));
  if (dan == NULL) RAISE(114, 49, "insufficient memory for object dynamic allocation")
  dan_Refman = MR_new_ref(dan);
  if (dan_Refman == NULL) RAISE(114, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(115, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(115, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(115, 25, "slice index out of bounds")
  if (arr == NULL) RAISE(115, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(115, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (arr)->length) RAISE(115, 25, "slice index out of bounds")
  san = MR_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]);
  if (san == NULL) RAISE(115, 49, "insufficient memory for object dynamic allocation")
  san_Refman = MR_new_ref(san);
  if (san_Refman == NULL) RAISE(115, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(116, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(116, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(116, 25, "slice index out of bounds")
  sfn = MR_new_array(((Int*)((arr)->values))[0], sizeof(Func));
  if (sfn == NULL) RAISE(116, 49, "insufficient memory for object dynamic allocation")
  sfn_Refman = MR_new_ref(sfn);
  if (sfn_Refman == NULL) RAISE(116, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(117, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(117, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(117, 25, "slice index out of bounds")
  ix = ((Int*)((arr)->values))[0];
  si = text;
  si_Refman = text_Refman;
  MR_inc_ref(si_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(119, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  isv = &isv_Var;
  isv_Var.values = isv_Values;
  isv_Refman = MR_new_ref(isv);
  if (isv_Refman == NULL) RAISE(119, 38, "insufficient memory for managed object")
  CHECK(119, String_new(isv, isv_Refman, aux_String_0, aux_String_0_Refman) )
  isn = MR_new_string(i);
  if (isn == NULL) RAISE(120, 49, "insufficient memory for object dynamic allocation")
  isn_Refman = MR_new_ref(isn);
  if (isn_Refman == NULL) RAISE(120, 38, "insufficient memory for managed object")
  CHECK(120, String_new(isn, isn_Refman, text, text_Refman) )
  fi = f_test_int2str;
  itv = &itv_Var;
  itv_Refman = MR_new_ref(itv);
  if (itv_Refman == NULL) RAISE(122, 38, "insufficient memory for managed object")
  CHECK(122, TestStruct_new(itv, itv_Refman, i, text, text_Refman) )
  itn = calloc(1, sizeof(TestStruct));
  if (itn == NULL) RAISE(123, 49, "insufficient memory for object dynamic allocation")
  itn_Refman = MR_new_ref(itn);
  if (itn_Refman == NULL) RAISE(123, 38, "insufficient memory for managed object")
  CHECK(123, TestStruct_new(itn, itn_Refman, i, text, text_Refman) )
  idv = &idv_Var;
  idv_Refman = MR_new_ref(idv);
  if (idv_Refman == NULL) RAISE(124, 38, "insufficient memory for managed object")
  CHECK(124, TestClass_new(idv, idv_Refman, idv_Dynamic) )
  idn = calloc(1, sizeof(TestClass));
  if (idn == NULL) RAISE(125, 49, "insufficient memory for object dynamic allocation")
  idn_Refman = MR_new_ref(idn);
  if (idn_Refman == NULL) RAISE(125, 38, "insufficient memory for managed object")
  CHECK(125, TestClass_new(idn, idn_Refman, idn_Dynamic) )
  aux_TestStruct_0 = calloc(1, sizeof(TestStruct));
  if (aux_TestStruct_0 == NULL) RAISE(126, 49, "insufficient memory for object dynamic allocation")
  aux_TestStruct_0_Refman = MR_new_ref(aux_TestStruct_0);
  if (aux_TestStruct_0_Refman == NULL) RAISE(126, 38, "insufficient memory for managed object")
  CHECK(126, TestStruct_new(aux_TestStruct_0, aux_TestStruct_0_Refman, i, text, text_Refman) )
  CHECK(126, TestStruct_print(aux_TestStruct_0, aux_TestStruct_0_Refman) )
  aux_TestClass_0 = calloc(1, sizeof(TestClass));
  if (aux_TestClass_0 == NULL) RAISE(127, 49, "insufficient memory for object dynamic allocation")
  aux_TestClass_0_Refman = MR_new_ref(aux_TestClass_0);
  if (aux_TestClass_0_Refman == NULL) RAISE(127, 38, "insufficient memory for managed object")
  CHECK(127, TestClass_new(aux_TestClass_0, aux_TestClass_0_Refman, aux_TestClass_0_Dynamic) )
  CHECK(127, TestClass_print(aux_TestClass_0, aux_TestClass_0_Refman, aux_TestClass_0_Dynamic) )
  if (arr == NULL) RAISE(128, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(128, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(128, 25, "slice index out of bounds")
  aux_String_1 = MR_new_string(((Int*)((arr)->values))[0]);
  if (aux_String_1 == NULL) RAISE(128, 49, "insufficient memory for object dynamic allocation")
  aux_String_1_Refman = MR_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(128, 38, "insufficient memory for managed object")
  TEST_ASSERT(128, aux_String_1 != NULL && aux_String_1_Refman->value != NULL)
  if (arr == NULL) RAISE(129, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(129, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(129, 25, "slice index out of bounds")
  aux_Array_0 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if (aux_Array_0 == NULL) RAISE(129, 49, "insufficient memory for object dynamic allocation")
  aux_Array_0_Refman = MR_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(129, 38, "insufficient memory for managed object")
  TEST_ASSERT(129, aux_Array_0 != NULL && aux_Array_0_Refman->value != NULL)
  if (arr == NULL) RAISE(130, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(130, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(130, 25, "slice index out of bounds")
  aux_Array_1 = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestStruct));
  if (aux_Array_1 == NULL) RAISE(130, 49, "insufficient memory for object dynamic allocation")
  aux_Array_1_Refman = MR_new_ref(aux_Array_1);
  if (aux_Array_1_Refman == NULL) RAISE(130, 38, "insufficient memory for managed object")
  TEST_ASSERT(130, aux_Array_1 != NULL && aux_Array_1_Refman->value != NULL)
  if (arr == NULL) RAISE(131, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(131, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(131, 25, "slice index out of bounds")
  aux_Array_2 = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestClass));
  if (aux_Array_2 == NULL) RAISE(131, 49, "insufficient memory for object dynamic allocation")
  aux_Array_2_Refman = MR_new_ref(aux_Array_2);
  if (aux_Array_2_Refman == NULL) RAISE(131, 38, "insufficient memory for managed object")
  TEST_ASSERT(131, aux_Array_2 != NULL && aux_Array_2_Refman->value != NULL)
  if (arr == NULL) RAISE(132, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(132, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(132, 25, "slice index out of bounds")
  if (arr == NULL) RAISE(132, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(132, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (arr)->length) RAISE(132, 25, "slice index out of bounds")
  aux_Array_3 = MR_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]);
  if (aux_Array_3 == NULL) RAISE(132, 49, "insufficient memory for object dynamic allocation")
  aux_Array_3_Refman = MR_new_ref(aux_Array_3);
  if (aux_Array_3_Refman == NULL) RAISE(132, 38, "insufficient memory for managed object")
  TEST_ASSERT(132, aux_Array_3 != NULL && aux_Array_3_Refman->value != NULL)
  if (arr == NULL) RAISE(133, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(133, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(133, 25, "slice index out of bounds")
  aux_Array_4 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Func));
  if (aux_Array_4 == NULL) RAISE(133, 49, "insufficient memory for object dynamic allocation")
  aux_Array_4_Refman = MR_new_ref(aux_Array_4);
  if (aux_Array_4_Refman == NULL) RAISE(133, 38, "insufficient memory for managed object")
  TEST_ASSERT(133, aux_Array_4 != NULL && aux_Array_4_Refman->value != NULL)
  TEST_ASSERT(134, x == 0)
  TEST_ASSERT(135, s != NULL && s_Refman->value != NULL)
  TEST_ASSERT(136, a != NULL && a_Refman->value != NULL)
  CHECK(137, TestStruct_print(t, t_Refman) )
  CHECK(138, TestClass_print(d, d_Refman, d_Dynamic) )
  TEST_ASSERT(139, f != NULL)
  CHECK(140, TestStruct_print(tv, tv_Refman) )
  CHECK(141, TestClass_print(dv, dv_Refman, dv_Dynamic) )
  TEST_ASSERT(142, sv != NULL && sv_Refman->value != NULL)
  TEST_ASSERT(143, ia != NULL && ia_Refman->value != NULL)
  TEST_ASSERT(144, ta != NULL && ta_Refman->value != NULL)
  TEST_ASSERT(145, da != NULL && da_Refman->value != NULL)
  TEST_ASSERT(146, sa != NULL && sa_Refman->value != NULL)
  TEST_ASSERT(147, fa != NULL && fa_Refman->value != NULL)
  CHECK(148, TestStruct_print(tn, tn_Refman) )
  CHECK(149, TestClass_print(dn, dn_Refman, dn_Dynamic) )
  TEST_ASSERT(150, sn != NULL && sn_Refman->value != NULL)
  TEST_ASSERT(151, ian != NULL && ian_Refman->value != NULL)
  TEST_ASSERT(152, tan != NULL && tan_Refman->value != NULL)
  TEST_ASSERT(153, dan != NULL && dan_Refman->value != NULL)
  TEST_ASSERT(154, san != NULL && san_Refman->value != NULL)
  TEST_ASSERT(155, sfn != NULL && sfn_Refman->value != NULL)
  TEST_ASSERT(156, ix == 0)
  TEST_ASSERT(157, si != NULL && si_Refman->value != NULL)
  if (fi == NULL) RAISE(158, 21, "empty function called")
  CHECK(158, fi(7, &(aux_String_2), &(aux_String_2_Refman)) )
  TEST_ASSERT(159, isv != NULL && isv_Refman->value != NULL)
  TEST_ASSERT(160, isn != NULL && isn_Refman->value != NULL)
MR_cleanup:
  String_Del(aux_String_2);
  MR_owner_dec_ref(aux_String_2_Refman);
  MR_owner_dec_ref(aux_Array_4_Refman);
  ARRAY_DEL(String, aux_Array_3)
  MR_owner_dec_ref(aux_Array_3_Refman);
  ARRAY_DEL(TestClass, aux_Array_2)
  MR_owner_dec_ref(aux_Array_2_Refman);
  ARRAY_DEL(TestStruct, aux_Array_1)
  MR_owner_dec_ref(aux_Array_1_Refman);
  MR_owner_dec_ref(aux_Array_0_Refman);
  String_Del(aux_String_1);
  MR_owner_dec_ref(aux_String_1_Refman);
  if (aux_TestClass_0_Dynamic != NULL) aux_TestClass_0_Dynamic->_del(aux_TestClass_0);
  MR_owner_dec_ref(aux_TestClass_0_Refman);
  TestStruct_Del(aux_TestStruct_0);
  MR_owner_dec_ref(aux_TestStruct_0_Refman);
  MR_dec_ref(aux_String_0_Refman);
  if (idn_Dynamic != NULL) idn_Dynamic->_del(idn);
  MR_owner_dec_ref(idn_Refman);
  MR_dec_ref(idv_Refman);
  TestStruct_Del(itn);
  MR_owner_dec_ref(itn_Refman);
  MR_dec_ref(itv_Refman);
  String_Del(isn);
  MR_owner_dec_ref(isn_Refman);
  MR_dec_ref(isv_Refman);
  MR_dec_ref(si_Refman);
  MR_owner_dec_ref(sfn_Refman);
  ARRAY_DEL(String, san)
  MR_owner_dec_ref(san_Refman);
  ARRAY_DEL(TestClass, dan)
  MR_owner_dec_ref(dan_Refman);
  ARRAY_DEL(TestStruct, tan)
  MR_owner_dec_ref(tan_Refman);
  MR_owner_dec_ref(ian_Refman);
  String_Del(sn);
  MR_owner_dec_ref(sn_Refman);
  if (dn_Dynamic != NULL) dn_Dynamic->_del(dn);
  MR_owner_dec_ref(dn_Refman);
  TestStruct_Del(tn);
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
Returncode test_complex_function(Int num, String* text, Ref_Manager* text_Refman, Int* out_num, String** out_text, Ref_Manager** out_text_Refman) {
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
Returncode f_test_params(Int x, String* s, Ref_Manager* s_Refman, String* o, Ref_Manager* o_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(s_Refman);
  USER_RAISE(231, NULL, NULL)
MR_cleanup:
  String_Del(o);
  MR_owner_dec_ref(o_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-outs"
Returncode f_test_outs(String** s, Ref_Manager** s_Refman, Int* x) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-test-int2str"
Returncode f_test_int2str(Int x, String** s, Ref_Manager** s_Refman) {
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
  CHECK(246, f_test_void() )
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(247, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 5;
  aux_String_0_Var.length = 4;
  aux_String_0_Var.values = "text";
  CHECK(247, f_test_params(3, aux_String_0, aux_String_0_Refman, NULL, NULL) )
  CHECK(248, f_test_outs(&(s), &(s_Refman), &(x)) )
  CHECK(249, f_test_int2str(4, &(s), &(s_Refman)) )
  CHECK(250, f_test_int(5) )
  CHECK(251, f_test_int2int(6, &(x)) )
  CHECK(252, f_test_many(7, 8, &(x), &(x)) )
  CHECK(258, f_test_int2int(9, &(tmp)) )
  CHECK(258, f_test_int(tmp) )
  CHECK(259, f_test_many(11, 12, &(x), &(aux_Int_0)) )
  CHECK(259, f_test_int2int(10, &(aux_Int_1)) )
  x = aux_Int_1 + aux_Int_0;
  CHECK(260, f_test_int2str(13, &(aux_String_1), &(aux_String_1_Refman)) )
  String_Del(s);
  MR_owner_dec_ref(s_Refman);
  s_Refman = aux_String_1_Refman;
  s = aux_String_1;
  aux_String_1 = NULL;
  aux_String_1_Refman = NULL;
MR_cleanup:
  String_Del(aux_String_1);
  MR_owner_dec_ref(aux_String_1_Refman);
  MR_dec_ref(aux_String_0_Refman);
  String_Del(s);
  MR_owner_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-code-flow"
Returncode test_code_flow(Array* arr, Ref_Manager* arr_Refman, Int* res) {
  Returncode MR_err = OK;
  Int x = 0;
  Int y = 0;
  Int z = 0;
  Int w = 0;
  Int n = 0;
  Array aux_Array_0_Var = {0};
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  MR_inc_ref(arr_Refman);
  if (arr == NULL) RAISE(264, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(264, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arr)->length) RAISE(264, 25, "slice index out of bounds")
  if ((((Int*)((arr)->values))[4]) > 6) {
    *res = 6;
  }
  else {
    if (arr != NULL && arr_Refman->value != NULL) {
      *res = 6;
    }
    else {
      if (arr == NULL) RAISE(268, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(268, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(268, 25, "slice index out of bounds")
      if (arr == NULL) RAISE(268, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(268, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(268, 25, "slice index out of bounds")
      if ((((Int*)((arr)->values))[4]) != (((Int*)((arr)->values))[4])) {
        *res = 6;
      }
      else {
        if (arr == NULL) RAISE(270, 29, "empty object used as sequence")
        if (arr_Refman->value == NULL) RAISE(270, 40, "outdated weak reference used as sequence")
        if ((0) < 0 || (0) >= (arr)->length) RAISE(270, 25, "slice index out of bounds")
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
    if (arr == NULL) RAISE(275, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(275, 40, "outdated weak reference used as sequence")
    if ((6) < 0 || (6) >= (arr)->length) RAISE(275, 25, "slice index out of bounds")
    ((Int*)((arr)->values))[6] = 6;
    if (arr == NULL) RAISE(276, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(276, 40, "outdated weak reference used as sequence")
    if ((2) < 0 || (2) >= (arr)->length) RAISE(276, 25, "slice index out of bounds")
    x = ((Int*)((arr)->values))[2];
    if (!((x > 3) && (arr == NULL))) break;
    y = x - 1;
    while (true) {
      if (arr == NULL) RAISE(280, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(280, 40, "outdated weak reference used as sequence")
      if ((8) < 0 || (8) >= (arr)->length) RAISE(280, 25, "slice index out of bounds")
      if (arr == NULL) RAISE(280, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(280, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(280, 25, "slice index out of bounds")
      ((Int*)((arr)->values))[4] = ((Int*)((arr)->values))[8];
      if (arr == NULL) RAISE(281, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(281, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(281, 25, "slice index out of bounds")
      if (y > (((Int*)((arr)->values))[4])) {
        continue;
      }
      z = 7;
      if (arr == NULL) RAISE(284, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(284, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(284, 25, "slice index out of bounds")
      if (z <= (((Int*)((arr)->values))[4])) {
        if (!(z > 0)) break;
      }
    }
  }
  if (arr == NULL) RAISE(286, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(286, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (arr)->length) RAISE(286, 25, "slice index out of bounds")
  for (n = ((Int*)((arr)->values))[2]; n < 2 - (3 * (((Int*)((arr)->values))[2])); ++n) {
    if (arr == NULL) RAISE(287, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(287, 40, "outdated weak reference used as sequence")
    if ((2) < 0 || (2) >= (arr)->length) RAISE(287, 25, "slice index out of bounds")
    if (arr == NULL) RAISE(287, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(287, 40, "outdated weak reference used as sequence")
    if ((0) < 0 || (0) >= (arr)->length) RAISE(287, 25, "slice index out of bounds")
    ((Int*)((arr)->values))[0] = ((Int*)((arr)->values))[2];
    if (arr == NULL) RAISE(288, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(288, 40, "outdated weak reference used as sequence")
    if ((0) < 0 || (0) >= (arr)->length) RAISE(288, 25, "slice index out of bounds")
    w = ((Int*)((arr)->values))[0];
    aux_Array_0 = &aux_Array_0_Var;
    aux_Array_0_Refman = MR_new_ref(aux_Array_0);
    if (aux_Array_0_Refman == NULL) RAISE(289, 38, "insufficient memory for managed object")
    aux_Array_0_Var.length = 2;
    aux_Array_0_Var.values = (Byte*)((arr)->values) + (3);
    if (arr == NULL) RAISE(289, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(289, 40, "outdated weak reference used as sequence")
    if ((3) < 0 || (2) < 0 || (3) + (2) > (arr)->length) RAISE(289, 25, "slice index out of bounds")
    if ((w > 4) && (arr != aux_Array_0)) {
      if (arr == NULL) RAISE(290, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(290, 40, "outdated weak reference used as sequence")
      if ((1) < 0 || (1) >= (arr)->length) RAISE(290, 25, "slice index out of bounds")
      ((Int*)((arr)->values))[1] = w;
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
Returncode test_builtins(Int i, Char c, Bool b, String* s, Ref_Manager* s_Refman, Array* a, Ref_Manager* a_Refman) {
  Returncode MR_err = OK;
  Int iv = 0;
  Char cv = 0;
  Bool bv = 0;
  File* f = NULL;
  Ref_Manager* f_Refman = NULL;
  MR_inc_ref(s_Refman);
  MR_inc_ref(a_Refman);
  CHECK(298, Int_str(i, s, s_Refman) )
  bv = true || false;
  if (a == NULL) RAISE(300, 27, "used member of empty object")
  if (a_Refman->value == NULL) RAISE(300, 38, "used member of outdated weak reference")
  i = a->length;
  if (s == NULL) RAISE(301, 27, "used member of empty object")
  if (s_Refman->value == NULL) RAISE(301, 38, "used member of outdated weak reference")
  i = s->length;
  CHECK(302, String_clear(s, s_Refman) )
  CHECK(303, String_equal(s, s_Refman, s, s_Refman, &(bv)) )
  CHECK(304, String_get(s, s_Refman, i, &(cv)) )
  CHECK(305, String_append(s, s_Refman, c) )
  CHECK(306, String_new(s, s_Refman, s, s_Refman) )
  CHECK(307, String_concat(s, s_Refman, s, s_Refman) )
  CHECK(308, String_concat_int(s, s_Refman, i) )
  CHECK(309, String_find(s, s_Refman, s, s_Refman, &(iv)) )
  CHECK(310, String_has(s, s_Refman, c, &(bv)) )
  CHECK(312, file_open_read(s, s_Refman, &(f), &(f_Refman)) )
  CHECK(313, file_open_write(s, s_Refman, &(f), &(f_Refman)) )
  CHECK(314, File_getc(f, f_Refman, &(cv), &(bv)) )
  CHECK(315, File_putc(f, f_Refman, c) )
  CHECK(316, File_write(f, f_Refman, s, s_Refman) )
  CHECK(317, File_close(f, f_Refman) )
  if (sys == NULL) RAISE(318, 27, "used member of empty object")
  if (sys_Refman->value == NULL) RAISE(318, 38, "used member of outdated weak reference")
  if (sys->argv == NULL) RAISE(318, 29, "empty object used as sequence")
  if (sys->argv_Refman->value == NULL) RAISE(318, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (sys->argv)->length) RAISE(318, 25, "slice index out of bounds")
  MR_dec_ref(s_Refman);
  s_Refman = sys->argv_Refman;
  MR_inc_ref(s_Refman);
  s = ((String*)((sys->argv)->values)) + 1;
  CHECK(319, Sys_print(sys, sys_Refman, s, s_Refman) )
  CHECK(320, Sys_println(sys, sys_Refman, s, s_Refman) )
  CHECK(321, Sys_getchar(sys, sys_Refman, &(cv), &(bv)) )
  CHECK(322, Sys_getline(sys, sys_Refman, s, s_Refman) )
  CHECK(323, Sys_getenv(sys, sys_Refman, s, s_Refman, s, s_Refman, &(bv)) )
  CHECK(324, Sys_system(sys, sys_Refman, s, s_Refman, &(iv)) )
  CHECK(325, Sys_exit(sys, sys_Refman, i) )
  CHECK(326, File_putc(stdout, stdout_Refman, c) )
  CHECK(327, File_getc(stdin, stdin_Refman, &(cv), &(bv)) )
  CHECK(328, File_putc(stderr, stderr_Refman, c) )
MR_cleanup:
  File_Del(f);
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
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(332, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "test string";
  s = MR_new_string(32);
  if (s == NULL) RAISE(332, 49, "insufficient memory for object dynamic allocation")
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(332, 38, "insufficient memory for managed object")
  CHECK(332, String_new(s, s_Refman, aux_String_0, aux_String_0_Refman) )
  s_user = s;
  s_user_Refman = s_Refman;
  MR_inc_ref(s_user_Refman);
  CHECK(334, Sys_println(sys, sys_Refman, s, s_Refman) )
  CHECK(335, Sys_println(sys, sys_Refman, s_user, s_user_Refman) )
  CHECK(336, f_remove(s, s_Refman) )
  s = NULL;
  s_Refman = NULL;
  if (! (s != NULL && s_Refman->value != NULL)) {
    aux_String_1 = &aux_String_1_Var;
    aux_String_1_Refman = MR_new_ref(aux_String_1);
    if (aux_String_1_Refman == NULL) RAISE(338, 38, "insufficient memory for managed object")
    aux_String_1_Var.max_length = 17;
    aux_String_1_Var.length = 16;
    aux_String_1_Var.values = "ownership passed";
    CHECK(338, Sys_println(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
  }
  if (! (s_user != NULL && s_user_Refman->value != NULL)) {
    aux_String_2 = &aux_String_2_Var;
    aux_String_2_Refman = MR_new_ref(aux_String_2);
    if (aux_String_2_Refman == NULL) RAISE(340, 38, "insufficient memory for managed object")
    aux_String_2_Var.max_length = 15;
    aux_String_2_Var.length = 14;
    aux_String_2_Var.values = "string deleted";
    CHECK(340, Sys_println(sys, sys_Refman, aux_String_2, aux_String_2_Refman) )
  }
MR_cleanup:
  MR_dec_ref(aux_String_2_Refman);
  MR_dec_ref(aux_String_1_Refman);
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(s_user_Refman);
  String_Del(s);
  MR_owner_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-remove"
Returncode f_remove(String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  String_Del(s);
  MR_owner_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-type-parameters"
Returncode test_type_parameters(String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  Data d_Var = {0};
  Data* d = NULL;
  Ref_Manager* d_Refman = NULL;
  char sarr_Chars[6 * 16];
  String sarr_Values[6] = {{0}};
  Array sarr_Var = {6, NULL};
  Array* sarr = NULL;
  Ref_Manager* sarr_Refman = NULL;
  Data ad_Values[5] = {{0}};
  Array ad_Var = {5, NULL};
  Array* ad = NULL;
  Ref_Manager* ad_Refman = NULL;
  Data dr_Var = {0};
  Data* dr = NULL;
  Ref_Manager* dr_Refman = NULL;
  Data* dg = NULL;
  Ref_Manager* dg_Refman = NULL;
  TopData t_Var = {{{{0}}}};
  TopData* t = NULL;
  Ref_Manager* t_Refman = NULL;
  Data dt_Var = {0};
  Data* dt = NULL;
  Ref_Manager* dt_Refman = NULL;
  TestStruct ts_Var = {0};
  TestStruct* ts = NULL;
  Ref_Manager* ts_Refman = NULL;
  MR_inc_ref(s_Refman);
  d = &d_Var;
  d_Refman = MR_new_ref(d);
  if (d_Refman == NULL) RAISE(370, 38, "insufficient memory for managed object")
  sarr = &sarr_Var;
  sarr_Var.values = sarr_Values;
  MR_set_var_string_array(6, 16, sarr, sarr_Chars);
  sarr_Refman = MR_new_ref(sarr);
  if (sarr_Refman == NULL) RAISE(371, 38, "insufficient memory for managed object")
  if (d == NULL) RAISE(372, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(372, 38, "used member of outdated weak reference")
  MR_dec_ref(d->item_Refman);
  d->item_Refman = s_Refman;
  MR_inc_ref(d->item_Refman);
  d->item_Dynamic = &String_dynamic;
  d->item = s;
  if (d == NULL) RAISE(373, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(373, 38, "used member of outdated weak reference")
  MR_dec_ref(s_Refman);
  s_Refman = d->item_Refman;
  MR_inc_ref(s_Refman);
  s = d->item;
  if (d == NULL) RAISE(374, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(374, 38, "used member of outdated weak reference")
  MR_dec_ref(d->arr_Refman);
  d->arr_Refman = sarr_Refman;
  MR_inc_ref(d->arr_Refman);
  d->arr = sarr;
  if (d == NULL) RAISE(375, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(375, 38, "used member of outdated weak reference")
  if (d->arr == NULL) RAISE(375, 29, "empty object used as sequence")
  if (d->arr_Refman->value == NULL) RAISE(375, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (d->arr)->length) RAISE(375, 25, "slice index out of bounds")
  MR_dec_ref(s_Refman);
  s_Refman = d->arr_Refman;
  MR_inc_ref(s_Refman);
  s = ((String*)((d->arr)->values)) + 4;
  ad = &ad_Var;
  ad_Var.values = ad_Values;
  ad_Refman = MR_new_ref(ad);
  if (ad_Refman == NULL) RAISE(376, 38, "insufficient memory for managed object")
  if (ad == NULL) RAISE(377, 29, "empty object used as sequence")
  if (ad_Refman->value == NULL) RAISE(377, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (ad)->length) RAISE(377, 25, "slice index out of bounds")
  if (((Data*)((ad)->values)) + 2 == NULL) RAISE(377, 27, "used member of empty object")
  if (ad_Refman->value == NULL) RAISE(377, 38, "used member of outdated weak reference")
  MR_dec_ref(s_Refman);
  s_Refman = (((Data*)((ad)->values)) + 2)->item_Refman;
  MR_inc_ref(s_Refman);
  s = (((Data*)((ad)->values)) + 2)->item;
  if (ad == NULL) RAISE(378, 29, "empty object used as sequence")
  if (ad_Refman->value == NULL) RAISE(378, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (ad)->length) RAISE(378, 25, "slice index out of bounds")
  if (((Data*)((ad)->values)) + 2 == NULL) RAISE(378, 27, "used member of empty object")
  if (ad_Refman->value == NULL) RAISE(378, 38, "used member of outdated weak reference")
  if ((((Data*)((ad)->values)) + 2)->arr == NULL) RAISE(378, 29, "empty object used as sequence")
  if ((((Data*)((ad)->values)) + 2)->arr_Refman->value == NULL) RAISE(378, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) >= ((((Data*)((ad)->values)) + 2)->arr)->length) RAISE(378, 25, "slice index out of bounds")
  MR_dec_ref(s_Refman);
  s_Refman = (((Data*)((ad)->values)) + 2)->arr_Refman;
  MR_inc_ref(s_Refman);
  s = ((String*)(((((Data*)((ad)->values)) + 2)->arr)->values)) + 3;
  dr = &dr_Var;
  dr_Refman = MR_new_ref(dr);
  if (dr_Refman == NULL) RAISE(379, 38, "insufficient memory for managed object")
  if (dr == NULL) RAISE(380, 27, "used member of empty object")
  if (dr_Refman->value == NULL) RAISE(380, 38, "used member of outdated weak reference")
  if (dr->item == NULL) RAISE(380, 27, "used member of empty object")
  if (dr->item_Refman->value == NULL) RAISE(380, 38, "used member of outdated weak reference")
  if (((Data*)(dr->item))->item == NULL) RAISE(380, 27, "used member of empty object")
  if (((Data*)(dr->item))->item_Refman->value == NULL) RAISE(380, 38, "used member of outdated weak reference")
  MR_dec_ref(s_Refman);
  s_Refman = ((Data*)(((Data*)(dr->item))->item))->item_Refman;
  MR_inc_ref(s_Refman);
  s = ((Data*)(((Data*)(dr->item))->item))->item;
  CHECK(381, Data_set(d, d_Refman, s, s_Refman, &String_dynamic, sarr, sarr_Refman) )
  CHECK(382, Data_get(d, d_Refman, (void*)&(s), &(s_Refman), &dynamic_Void) )
  dg = d;
  dg_Refman = d_Refman;
  MR_inc_ref(dg_Refman);
  TEST_ASSERT(384, dg != NULL && dg_Refman->value != NULL)
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(386, 38, "insufficient memory for managed object")
  dt = &dt_Var;
  dt_Refman = MR_new_ref(dt);
  if (dt_Refman == NULL) RAISE(387, 38, "insufficient memory for managed object")
  ts = &ts_Var;
  ts_Refman = MR_new_ref(ts);
  if (ts_Refman == NULL) RAISE(388, 38, "insufficient memory for managed object")
  CHECK(388, TestStruct_new(ts, ts_Refman, 0, NULL, NULL) )
  if (t == NULL) RAISE(389, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(389, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base._base._base.item_Refman);
  t->_base._base._base.item_Refman = s_Refman;
  MR_inc_ref(t->_base._base._base.item_Refman);
  t->_base._base._base.item_Dynamic = &String_dynamic;
  t->_base._base._base.item = s;
  if (t == NULL) RAISE(390, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(390, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base._base._base.arr_Refman);
  t->_base._base._base.arr_Refman = sarr_Refman;
  MR_inc_ref(t->_base._base._base.arr_Refman);
  t->_base._base._base.arr = sarr;
  if (t == NULL) RAISE(391, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(391, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base._base.second_Refman);
  t->_base._base.second_Refman = dt_Refman;
  MR_inc_ref(t->_base._base.second_Refman);
  t->_base._base.second_Dynamic = &Data_dynamic;
  t->_base._base.second = dt;
  if (t == NULL) RAISE(392, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(392, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base._base.third_Refman);
  t->_base._base.third_Refman = ts_Refman;
  MR_inc_ref(t->_base._base.third_Refman);
  t->_base._base.third_Dynamic = &TestStruct_dynamic;
  t->_base._base.third = ts;
MR_cleanup:
  MR_dec_ref(ts_Refman);
  MR_dec_ref(dt_Refman);
  MR_dec_ref(t_Refman);
  MR_dec_ref(dg_Refman);
  MR_dec_ref(dr_Refman);
  MR_dec_ref(ad_Refman);
  MR_dec_ref(sarr_Refman);
  MR_dec_ref(d_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "f-try-catch-raise"
Returncode f_try_catch_raise(TestStruct* t, Ref_Manager* t_Refman) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  MR_inc_ref(t_Refman);
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; break
    if (t == NULL) RAISE(397, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(397, 38, "used member of outdated weak reference")
    t->num = 1;

#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  } while (false);
  --MR_trace_ignore_count;
  if (MR_err != OK) {
    MR_err = OK;
    aux_String_0 = &aux_String_0_Var;
    aux_String_0_Refman = MR_new_ref(aux_String_0);
    if (aux_String_0_Refman == NULL) RAISE(399, 38, "insufficient memory for managed object")
    aux_String_0_Var.max_length = 16;
    aux_String_0_Var.length = 15;
    aux_String_0_Var.values = "ignored message";
    USER_RAISE(399, aux_String_0, aux_String_0_Refman)
  }
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(t_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-error-handling"
Returncode test_error_handling(TestStruct* t, Ref_Manager* t_Refman) {
  Returncode MR_err = OK;
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
  MR_inc_ref(t_Refman);
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; break
    aux_String_0 = &aux_String_0_Var;
    aux_String_0_Refman = MR_new_ref(aux_String_0);
    if (aux_String_0_Refman == NULL) RAISE(403, 38, "insufficient memory for managed object")
    aux_String_0_Var.max_length = 20;
    aux_String_0_Var.length = 19;
    aux_String_0_Var.values = "error handling { 1 ";
    CHECK(403, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
    if (t == NULL) RAISE(404, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(404, 38, "used member of outdated weak reference")
    t->num = 1;
    aux_String_1 = &aux_String_1_Var;
    aux_String_1_Refman = MR_new_ref(aux_String_1);
    if (aux_String_1_Refman == NULL) RAISE(405, 38, "insufficient memory for managed object")
    aux_String_1_Var.max_length = 4;
    aux_String_1_Var.length = 3;
    aux_String_1_Var.values = " X ";
    CHECK(405, Sys_print(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
    do {
      ++MR_trace_ignore_count;
      CHECK(407, f_test_void() )
    } while (false);
    --MR_trace_ignore_count;
    if (MR_err != OK) {
      MR_err = OK;
      CHECK(409, f_test_int(2) )
    }

#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  } while (false);
  --MR_trace_ignore_count;
  if (MR_err != OK) {
    MR_err = OK;
    aux_String_2 = &aux_String_2_Var;
    aux_String_2_Refman = MR_new_ref(aux_String_2);
    if (aux_String_2_Refman == NULL) RAISE(411, 38, "insufficient memory for managed object")
    aux_String_2_Var.max_length = 3;
    aux_String_2_Var.length = 2;
    aux_String_2_Var.values = "2 ";
    CHECK(411, Sys_print(sys, sys_Refman, aux_String_2, aux_String_2_Refman) )
    do {
      ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; break
      aux_String_3 = &aux_String_3_Var;
      aux_String_3_Refman = MR_new_ref(aux_String_3);
      if (aux_String_3_Refman == NULL) RAISE(413, 38, "insufficient memory for managed object")
      aux_String_3_Var.max_length = 3;
      aux_String_3_Var.length = 2;
      aux_String_3_Var.values = "3 ";
      CHECK(413, Sys_print(sys, sys_Refman, aux_String_3, aux_String_3_Refman) )
      if (t == NULL) RAISE(414, 27, "used member of empty object")
      if (t_Refman->value == NULL) RAISE(414, 38, "used member of outdated weak reference")
      t->num = 2;
      aux_String_4 = &aux_String_4_Var;
      aux_String_4_Refman = MR_new_ref(aux_String_4);
      if (aux_String_4_Refman == NULL) RAISE(415, 38, "insufficient memory for managed object")
      aux_String_4_Var.max_length = 4;
      aux_String_4_Var.length = 3;
      aux_String_4_Var.values = " X ";
      CHECK(415, Sys_print(sys, sys_Refman, aux_String_4, aux_String_4_Refman) )

#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    } while (false);
    --MR_trace_ignore_count;
    MR_err = OK;
    aux_String_5 = &aux_String_5_Var;
    aux_String_5_Refman = MR_new_ref(aux_String_5);
    if (aux_String_5_Refman == NULL) RAISE(416, 38, "insufficient memory for managed object")
    aux_String_5_Var.max_length = 3;
    aux_String_5_Var.length = 2;
    aux_String_5_Var.values = "4 ";
    CHECK(416, Sys_print(sys, sys_Refman, aux_String_5, aux_String_5_Refman) )
  }
  aux_String_6 = &aux_String_6_Var;
  aux_String_6_Refman = MR_new_ref(aux_String_6);
  if (aux_String_6_Refman == NULL) RAISE(417, 38, "insufficient memory for managed object")
  aux_String_6_Var.max_length = 3;
  aux_String_6_Var.length = 2;
  aux_String_6_Var.values = "5 ";
  CHECK(417, Sys_print(sys, sys_Refman, aux_String_6, aux_String_6_Refman) )
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; break
    aux_String_7 = &aux_String_7_Var;
    aux_String_7_Refman = MR_new_ref(aux_String_7);
    if (aux_String_7_Refman == NULL) RAISE(419, 38, "insufficient memory for managed object")
    aux_String_7_Var.max_length = 3;
    aux_String_7_Var.length = 2;
    aux_String_7_Var.values = "6 ";
    CHECK(419, Sys_print(sys, sys_Refman, aux_String_7, aux_String_7_Refman) )
    do {
      ++MR_trace_ignore_count;
      aux_String_8 = &aux_String_8_Var;
      aux_String_8_Refman = MR_new_ref(aux_String_8);
      if (aux_String_8_Refman == NULL) RAISE(421, 38, "insufficient memory for managed object")
      aux_String_8_Var.max_length = 3;
      aux_String_8_Var.length = 2;
      aux_String_8_Var.values = "7 ";
      CHECK(421, Sys_print(sys, sys_Refman, aux_String_8, aux_String_8_Refman) )
      CHECK(422, f_try_catch_raise(t, t_Refman) )
      aux_String_9 = &aux_String_9_Var;
      aux_String_9_Refman = MR_new_ref(aux_String_9);
      if (aux_String_9_Refman == NULL) RAISE(423, 38, "insufficient memory for managed object")
      aux_String_9_Var.max_length = 4;
      aux_String_9_Var.length = 3;
      aux_String_9_Var.values = " X ";
      CHECK(423, Sys_print(sys, sys_Refman, aux_String_9, aux_String_9_Refman) )
    } while (false);
    --MR_trace_ignore_count;
    MR_err = OK;
    aux_String_10 = &aux_String_10_Var;
    aux_String_10_Refman = MR_new_ref(aux_String_10);
    if (aux_String_10_Refman == NULL) RAISE(424, 38, "insufficient memory for managed object")
    aux_String_10_Var.max_length = 3;
    aux_String_10_Var.length = 2;
    aux_String_10_Var.values = "8 ";
    CHECK(424, Sys_print(sys, sys_Refman, aux_String_10, aux_String_10_Refman) )
    aux_String_11 = &aux_String_11_Var;
    aux_String_11_Refman = MR_new_ref(aux_String_11);
    if (aux_String_11_Refman == NULL) RAISE(425, 38, "insufficient memory for managed object")
    aux_String_11_Var.max_length = 24;
    aux_String_11_Var.length = 23;
    aux_String_11_Var.values = "another ignored message";
    USER_RAISE(425, aux_String_11, aux_String_11_Refman)

#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  } while (false);
  --MR_trace_ignore_count;
  MR_err = OK;
  aux_String_12 = &aux_String_12_Var;
  aux_String_12_Refman = MR_new_ref(aux_String_12);
  if (aux_String_12_Refman == NULL) RAISE(426, 38, "insufficient memory for managed object")
  aux_String_12_Var.max_length = 2;
  aux_String_12_Var.length = 1;
  aux_String_12_Var.values = "}";
  CHECK(426, Sys_println(sys, sys_Refman, aux_String_12, aux_String_12_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_12_Refman);
  MR_dec_ref(aux_String_11_Refman);
  MR_dec_ref(aux_String_10_Refman);
  MR_dec_ref(aux_String_9_Refman);
  MR_dec_ref(aux_String_8_Refman);
  MR_dec_ref(aux_String_7_Refman);
  MR_dec_ref(aux_String_6_Refman);
  MR_dec_ref(aux_String_5_Refman);
  MR_dec_ref(aux_String_4_Refman);
  MR_dec_ref(aux_String_3_Refman);
  MR_dec_ref(aux_String_2_Refman);
  MR_dec_ref(aux_String_1_Refman);
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(t_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-for-each"
Returncode test_for_each(void) {
  Returncode MR_err = OK;
  char text_Values[16] = {0};
  String text_Var = {16, 0, NULL};
  String* text = NULL;
  Ref_Manager* text_Refman = NULL;
  Int arr_Values[3] = {0};
  Array arr_Var = {3, NULL};
  Array* arr = NULL;
  Ref_Manager* arr_Refman = NULL;
  TestStruct tsarr_Values[3] = {{0}};
  Array tsarr_Var = {3, NULL};
  Array* tsarr = NULL;
  Ref_Manager* tsarr_Refman = NULL;
  char sarr_Chars[3 * 16];
  String sarr_Values[3] = {{0}};
  Array sarr_Var = {3, NULL};
  Array* sarr = NULL;
  Ref_Manager* sarr_Refman = NULL;
  Container container_last_Var = {0};
  Container* container_last = NULL;
  Ref_Manager* container_last_Refman = NULL;
  Container container_mid_Var = {0};
  Container* container_mid = NULL;
  Ref_Manager* container_mid_Refman = NULL;
  Container container_first_Var = {0};
  Container* container_first = NULL;
  Ref_Manager* container_first_Refman = NULL;
  Container container_Var = {0};
  Container* container = NULL;
  Ref_Manager* container_Refman = NULL;
  ContainerIterator* iter = NULL;
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
  TestStruct* ts = NULL;
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
  ContainerIterator* aux_ContainerIterator_0 = NULL;
  Ref_Manager* aux_ContainerIterator_0_Refman = NULL;
  String aux_String_24_Var = {0};
  String* aux_String_24 = NULL;
  Ref_Manager* aux_String_24_Refman = NULL;
  String aux_String_25_Var = {0};
  String* aux_String_25 = NULL;
  Ref_Manager* aux_String_25_Refman = NULL;
  text = &text_Var;
  text_Var.values = text_Values;
  text_Refman = MR_new_ref(text);
  if (text_Refman == NULL) RAISE(456, 38, "insufficient memory for managed object")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(457, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 8;
  aux_String_0_Var.length = 7;
  aux_String_0_Var.values = "chars[ ";
  CHECK(457, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = MR_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(458, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 7;
  aux_String_1_Var.length = 6;
  aux_String_1_Var.values = "abcdef";
  MR_dec_ref(aux_String_2_Refman);
  aux_String_2_Refman = aux_String_1_Refman;
  MR_inc_ref(aux_String_2_Refman);
  aux_String_2 = aux_String_1;
  {int c_Index; for (c_Index = 0; c_Index < aux_String_2->length; ++c_Index) {
    if (aux_String_2 == NULL) RAISE(458, 29, "empty object used as sequence")
    if (aux_String_2_Refman->value == NULL) RAISE(458, 40, "outdated weak reference used as sequence")
    if ((c_Index) < 0 || (c_Index) >= (aux_String_2)->length) RAISE(458, 25, "slice index out of bounds")
    c = ((aux_String_2)->values)[c_Index];
    CHECK(459, String_clear(text, text_Refman) )
    CHECK(460, String_append(text, text_Refman, c) )
    CHECK(461, Sys_print(sys, sys_Refman, text, text_Refman) )
    aux_String_3 = &aux_String_3_Var;
    aux_String_3_Refman = MR_new_ref(aux_String_3);
    if (aux_String_3_Refman == NULL) RAISE(462, 38, "insufficient memory for managed object")
    aux_String_3_Var.max_length = 2;
    aux_String_3_Var.length = 1;
    aux_String_3_Var.values = " ";
    CHECK(462, Sys_print(sys, sys_Refman, aux_String_3, aux_String_3_Refman) )
  }}
  MR_dec_ref(aux_String_2_Refman);
  aux_String_2_Refman = NULL;
  MR_inc_ref(aux_String_2_Refman);
  aux_String_2 = NULL;
  aux_String_4 = &aux_String_4_Var;
  aux_String_4_Refman = MR_new_ref(aux_String_4);
  if (aux_String_4_Refman == NULL) RAISE(463, 38, "insufficient memory for managed object")
  aux_String_4_Var.max_length = 2;
  aux_String_4_Var.length = 1;
  aux_String_4_Var.values = "]";
  CHECK(463, Sys_println(sys, sys_Refman, aux_String_4, aux_String_4_Refman) )
  arr = &arr_Var;
  arr_Var.values = arr_Values;
  arr_Refman = MR_new_ref(arr);
  if (arr_Refman == NULL) RAISE(465, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(466, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(466, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(466, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[0] = 14;
  if (arr == NULL) RAISE(467, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(467, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (arr)->length) RAISE(467, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[1] = 15;
  if (arr == NULL) RAISE(468, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(468, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (arr)->length) RAISE(468, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[2] = 16;
  aux_String_5 = &aux_String_5_Var;
  aux_String_5_Refman = MR_new_ref(aux_String_5);
  if (aux_String_5_Refman == NULL) RAISE(469, 38, "insufficient memory for managed object")
  aux_String_5_Var.max_length = 10;
  aux_String_5_Var.length = 9;
  aux_String_5_Var.values = "numbers[ ";
  CHECK(469, Sys_print(sys, sys_Refman, aux_String_5, aux_String_5_Refman) )
  MR_dec_ref(aux_Array_0_Refman);
  aux_Array_0_Refman = arr_Refman;
  MR_inc_ref(aux_Array_0_Refman);
  aux_Array_0 = arr;
  {int n_Index; for (n_Index = 0; n_Index < aux_Array_0->length; ++n_Index) {
    if (aux_Array_0 == NULL) RAISE(470, 29, "empty object used as sequence")
    if (aux_Array_0_Refman->value == NULL) RAISE(470, 40, "outdated weak reference used as sequence")
    if ((n_Index) < 0 || (n_Index) >= (aux_Array_0)->length) RAISE(470, 25, "slice index out of bounds")
    n = ((Int*)((aux_Array_0)->values))[n_Index];
    CHECK(471, String_clear(text, text_Refman) )
    CHECK(472, Int_str(n, text, text_Refman) )
    CHECK(473, Sys_print(sys, sys_Refman, text, text_Refman) )
    aux_String_6 = &aux_String_6_Var;
    aux_String_6_Refman = MR_new_ref(aux_String_6);
    if (aux_String_6_Refman == NULL) RAISE(474, 38, "insufficient memory for managed object")
    aux_String_6_Var.max_length = 2;
    aux_String_6_Var.length = 1;
    aux_String_6_Var.values = " ";
    CHECK(474, Sys_print(sys, sys_Refman, aux_String_6, aux_String_6_Refman) )
  }}
  MR_dec_ref(aux_Array_0_Refman);
  aux_Array_0_Refman = NULL;
  MR_inc_ref(aux_Array_0_Refman);
  aux_Array_0 = NULL;
  aux_String_7 = &aux_String_7_Var;
  aux_String_7_Refman = MR_new_ref(aux_String_7);
  if (aux_String_7_Refman == NULL) RAISE(475, 38, "insufficient memory for managed object")
  aux_String_7_Var.max_length = 2;
  aux_String_7_Var.length = 1;
  aux_String_7_Var.values = "]";
  CHECK(475, Sys_println(sys, sys_Refman, aux_String_7, aux_String_7_Refman) )
  tsarr = &tsarr_Var;
  tsarr_Var.values = tsarr_Values;
  tsarr_Refman = MR_new_ref(tsarr);
  if (tsarr_Refman == NULL) RAISE(477, 38, "insufficient memory for managed object")
  aux_String_8 = &aux_String_8_Var;
  aux_String_8_Refman = MR_new_ref(aux_String_8);
  if (aux_String_8_Refman == NULL) RAISE(478, 38, "insufficient memory for managed object")
  aux_String_8_Var.max_length = 4;
  aux_String_8_Var.length = 3;
  aux_String_8_Var.values = "aaa";
  if (tsarr == NULL) RAISE(478, 29, "empty object used as sequence")
  if (tsarr_Refman->value == NULL) RAISE(478, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (tsarr)->length) RAISE(478, 25, "slice index out of bounds")
  if (((TestStruct*)((tsarr)->values)) + 0 == NULL) RAISE(478, 27, "used member of empty object")
  if (tsarr_Refman->value == NULL) RAISE(478, 38, "used member of outdated weak reference")
  MR_dec_ref((((TestStruct*)((tsarr)->values)) + 0)->text_Refman);
  (((TestStruct*)((tsarr)->values)) + 0)->text_Refman = aux_String_8_Refman;
  MR_inc_ref((((TestStruct*)((tsarr)->values)) + 0)->text_Refman);
  (((TestStruct*)((tsarr)->values)) + 0)->text = aux_String_8;
  aux_String_9 = &aux_String_9_Var;
  aux_String_9_Refman = MR_new_ref(aux_String_9);
  if (aux_String_9_Refman == NULL) RAISE(479, 38, "insufficient memory for managed object")
  aux_String_9_Var.max_length = 4;
  aux_String_9_Var.length = 3;
  aux_String_9_Var.values = "bbb";
  if (tsarr == NULL) RAISE(479, 29, "empty object used as sequence")
  if (tsarr_Refman->value == NULL) RAISE(479, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (tsarr)->length) RAISE(479, 25, "slice index out of bounds")
  if (((TestStruct*)((tsarr)->values)) + 1 == NULL) RAISE(479, 27, "used member of empty object")
  if (tsarr_Refman->value == NULL) RAISE(479, 38, "used member of outdated weak reference")
  MR_dec_ref((((TestStruct*)((tsarr)->values)) + 1)->text_Refman);
  (((TestStruct*)((tsarr)->values)) + 1)->text_Refman = aux_String_9_Refman;
  MR_inc_ref((((TestStruct*)((tsarr)->values)) + 1)->text_Refman);
  (((TestStruct*)((tsarr)->values)) + 1)->text = aux_String_9;
  aux_String_10 = &aux_String_10_Var;
  aux_String_10_Refman = MR_new_ref(aux_String_10);
  if (aux_String_10_Refman == NULL) RAISE(480, 38, "insufficient memory for managed object")
  aux_String_10_Var.max_length = 4;
  aux_String_10_Var.length = 3;
  aux_String_10_Var.values = "ccc";
  if (tsarr == NULL) RAISE(480, 29, "empty object used as sequence")
  if (tsarr_Refman->value == NULL) RAISE(480, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (tsarr)->length) RAISE(480, 25, "slice index out of bounds")
  if (((TestStruct*)((tsarr)->values)) + 2 == NULL) RAISE(480, 27, "used member of empty object")
  if (tsarr_Refman->value == NULL) RAISE(480, 38, "used member of outdated weak reference")
  MR_dec_ref((((TestStruct*)((tsarr)->values)) + 2)->text_Refman);
  (((TestStruct*)((tsarr)->values)) + 2)->text_Refman = aux_String_10_Refman;
  MR_inc_ref((((TestStruct*)((tsarr)->values)) + 2)->text_Refman);
  (((TestStruct*)((tsarr)->values)) + 2)->text = aux_String_10;
  aux_String_11 = &aux_String_11_Var;
  aux_String_11_Refman = MR_new_ref(aux_String_11);
  if (aux_String_11_Refman == NULL) RAISE(481, 38, "insufficient memory for managed object")
  aux_String_11_Var.max_length = 10;
  aux_String_11_Var.length = 9;
  aux_String_11_Var.values = "structs[ ";
  CHECK(481, Sys_print(sys, sys_Refman, aux_String_11, aux_String_11_Refman) )
  MR_dec_ref(aux_Array_1_Refman);
  aux_Array_1_Refman = tsarr_Refman;
  MR_inc_ref(aux_Array_1_Refman);
  aux_Array_1 = tsarr;
  {int ts_Index; for (ts_Index = 0; ts_Index < aux_Array_1->length; ++ts_Index) {
    if (aux_Array_1 == NULL) RAISE(482, 29, "empty object used as sequence")
    if (aux_Array_1_Refman->value == NULL) RAISE(482, 40, "outdated weak reference used as sequence")
    if ((ts_Index) < 0 || (ts_Index) >= (aux_Array_1)->length) RAISE(482, 25, "slice index out of bounds")
    MR_dec_ref(ts_Refman);
    ts_Refman = aux_Array_1_Refman;
    MR_inc_ref(ts_Refman);
    ts = ((TestStruct*)((aux_Array_1)->values)) + ts_Index;
    if (ts == NULL) RAISE(483, 27, "used member of empty object")
    if (ts_Refman->value == NULL) RAISE(483, 38, "used member of outdated weak reference")
    CHECK(483, Sys_print(sys, sys_Refman, ts->text, ts->text_Refman) )
    aux_String_12 = &aux_String_12_Var;
    aux_String_12_Refman = MR_new_ref(aux_String_12);
    if (aux_String_12_Refman == NULL) RAISE(484, 38, "insufficient memory for managed object")
    aux_String_12_Var.max_length = 2;
    aux_String_12_Var.length = 1;
    aux_String_12_Var.values = " ";
    CHECK(484, Sys_print(sys, sys_Refman, aux_String_12, aux_String_12_Refman) )
  }}
  MR_dec_ref(aux_Array_1_Refman);
  aux_Array_1_Refman = NULL;
  MR_inc_ref(aux_Array_1_Refman);
  aux_Array_1 = NULL;
  aux_String_13 = &aux_String_13_Var;
  aux_String_13_Refman = MR_new_ref(aux_String_13);
  if (aux_String_13_Refman == NULL) RAISE(485, 38, "insufficient memory for managed object")
  aux_String_13_Var.max_length = 2;
  aux_String_13_Var.length = 1;
  aux_String_13_Var.values = "]";
  CHECK(485, Sys_println(sys, sys_Refman, aux_String_13, aux_String_13_Refman) )
  sarr = &sarr_Var;
  sarr_Var.values = sarr_Values;
  MR_set_var_string_array(3, 16, sarr, sarr_Chars);
  sarr_Refman = MR_new_ref(sarr);
  if (sarr_Refman == NULL) RAISE(487, 38, "insufficient memory for managed object")
  if (sarr == NULL) RAISE(488, 29, "empty object used as sequence")
  if (sarr_Refman->value == NULL) RAISE(488, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (sarr)->length) RAISE(488, 25, "slice index out of bounds")
  aux_String_14 = &aux_String_14_Var;
  aux_String_14_Refman = MR_new_ref(aux_String_14);
  if (aux_String_14_Refman == NULL) RAISE(488, 38, "insufficient memory for managed object")
  aux_String_14_Var.max_length = 4;
  aux_String_14_Var.length = 3;
  aux_String_14_Var.values = "ddd";
  CHECK(488, String_new(((String*)((sarr)->values)) + 0, sarr_Refman, aux_String_14, aux_String_14_Refman) )
  if (sarr == NULL) RAISE(489, 29, "empty object used as sequence")
  if (sarr_Refman->value == NULL) RAISE(489, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (sarr)->length) RAISE(489, 25, "slice index out of bounds")
  aux_String_15 = &aux_String_15_Var;
  aux_String_15_Refman = MR_new_ref(aux_String_15);
  if (aux_String_15_Refman == NULL) RAISE(489, 38, "insufficient memory for managed object")
  aux_String_15_Var.max_length = 4;
  aux_String_15_Var.length = 3;
  aux_String_15_Var.values = "eee";
  CHECK(489, String_new(((String*)((sarr)->values)) + 1, sarr_Refman, aux_String_15, aux_String_15_Refman) )
  if (sarr == NULL) RAISE(490, 29, "empty object used as sequence")
  if (sarr_Refman->value == NULL) RAISE(490, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (sarr)->length) RAISE(490, 25, "slice index out of bounds")
  aux_String_16 = &aux_String_16_Var;
  aux_String_16_Refman = MR_new_ref(aux_String_16);
  if (aux_String_16_Refman == NULL) RAISE(490, 38, "insufficient memory for managed object")
  aux_String_16_Var.max_length = 4;
  aux_String_16_Var.length = 3;
  aux_String_16_Var.values = "fff";
  CHECK(490, String_new(((String*)((sarr)->values)) + 2, sarr_Refman, aux_String_16, aux_String_16_Refman) )
  aux_String_17 = &aux_String_17_Var;
  aux_String_17_Refman = MR_new_ref(aux_String_17);
  if (aux_String_17_Refman == NULL) RAISE(491, 38, "insufficient memory for managed object")
  aux_String_17_Var.max_length = 10;
  aux_String_17_Var.length = 9;
  aux_String_17_Var.values = "strings[ ";
  CHECK(491, Sys_print(sys, sys_Refman, aux_String_17, aux_String_17_Refman) )
  MR_dec_ref(aux_Array_2_Refman);
  aux_Array_2_Refman = sarr_Refman;
  MR_inc_ref(aux_Array_2_Refman);
  aux_Array_2 = sarr;
  {int s_Index; for (s_Index = 0; s_Index < aux_Array_2->length; ++s_Index) {
    if (aux_Array_2 == NULL) RAISE(492, 29, "empty object used as sequence")
    if (aux_Array_2_Refman->value == NULL) RAISE(492, 40, "outdated weak reference used as sequence")
    if ((s_Index) < 0 || (s_Index) >= (aux_Array_2)->length) RAISE(492, 25, "slice index out of bounds")
    MR_dec_ref(s_Refman);
    s_Refman = aux_Array_2_Refman;
    MR_inc_ref(s_Refman);
    s = ((String*)((aux_Array_2)->values)) + s_Index;
    CHECK(493, Sys_print(sys, sys_Refman, s, s_Refman) )
    aux_String_18 = &aux_String_18_Var;
    aux_String_18_Refman = MR_new_ref(aux_String_18);
    if (aux_String_18_Refman == NULL) RAISE(494, 38, "insufficient memory for managed object")
    aux_String_18_Var.max_length = 2;
    aux_String_18_Var.length = 1;
    aux_String_18_Var.values = " ";
    CHECK(494, Sys_print(sys, sys_Refman, aux_String_18, aux_String_18_Refman) )
  }}
  MR_dec_ref(aux_Array_2_Refman);
  aux_Array_2_Refman = NULL;
  MR_inc_ref(aux_Array_2_Refman);
  aux_Array_2 = NULL;
  aux_String_19 = &aux_String_19_Var;
  aux_String_19_Refman = MR_new_ref(aux_String_19);
  if (aux_String_19_Refman == NULL) RAISE(495, 38, "insufficient memory for managed object")
  aux_String_19_Var.max_length = 2;
  aux_String_19_Var.length = 1;
  aux_String_19_Var.values = "]";
  CHECK(495, Sys_println(sys, sys_Refman, aux_String_19, aux_String_19_Refman) )
  aux_String_20 = &aux_String_20_Var;
  aux_String_20_Refman = MR_new_ref(aux_String_20);
  if (aux_String_20_Refman == NULL) RAISE(497, 38, "insufficient memory for managed object")
  aux_String_20_Var.max_length = 4;
  aux_String_20_Var.length = 3;
  aux_String_20_Var.values = "iii";
  container_last = &container_last_Var;
  container_last_Refman = MR_new_ref(container_last);
  if (container_last_Refman == NULL) RAISE(497, 38, "insufficient memory for managed object")
  CHECK(497, Container_new(container_last, container_last_Refman, aux_String_20, aux_String_20_Refman, &String_dynamic, NULL, NULL) )
  aux_String_21 = &aux_String_21_Var;
  aux_String_21_Refman = MR_new_ref(aux_String_21);
  if (aux_String_21_Refman == NULL) RAISE(498, 38, "insufficient memory for managed object")
  aux_String_21_Var.max_length = 4;
  aux_String_21_Var.length = 3;
  aux_String_21_Var.values = "hhh";
  container_mid = &container_mid_Var;
  container_mid_Refman = MR_new_ref(container_mid);
  if (container_mid_Refman == NULL) RAISE(498, 38, "insufficient memory for managed object")
  CHECK(498, Container_new(container_mid, container_mid_Refman, aux_String_21, aux_String_21_Refman, &String_dynamic, container_last, container_last_Refman) )
  aux_String_22 = &aux_String_22_Var;
  aux_String_22_Refman = MR_new_ref(aux_String_22);
  if (aux_String_22_Refman == NULL) RAISE(499, 38, "insufficient memory for managed object")
  aux_String_22_Var.max_length = 4;
  aux_String_22_Var.length = 3;
  aux_String_22_Var.values = "ggg";
  container_first = &container_first_Var;
  container_first_Refman = MR_new_ref(container_first);
  if (container_first_Refman == NULL) RAISE(499, 38, "insufficient memory for managed object")
  CHECK(499, Container_new(container_first, container_first_Refman, aux_String_22, aux_String_22_Refman, &String_dynamic, container_mid, container_mid_Refman) )
  container = &container_Var;
  container_Refman = MR_new_ref(container);
  if (container_Refman == NULL) RAISE(500, 38, "insufficient memory for managed object")
  CHECK(500, Container_new(container, container_Refman, NULL, NULL, NULL, container_first, container_first_Refman) )
  CHECK(502, Container_iter(container, container_Refman, &(iter), &(iter_Refman)) )
  aux_String_23 = &aux_String_23_Var;
  aux_String_23_Refman = MR_new_ref(aux_String_23);
  if (aux_String_23_Refman == NULL) RAISE(503, 38, "insufficient memory for managed object")
  aux_String_23_Var.max_length = 9;
  aux_String_23_Var.length = 8;
  aux_String_23_Var.values = "values[ ";
  CHECK(503, Sys_print(sys, sys_Refman, aux_String_23, aux_String_23_Refman) )
  MR_dec_ref(aux_ContainerIterator_0_Refman);
  aux_ContainerIterator_0_Refman = iter_Refman;
  MR_inc_ref(aux_ContainerIterator_0_Refman);
  aux_ContainerIterator_0 = iter;
  while (true) {
    Bool s_Has = false;
    CHECK(504, ContainerIterator_has(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman, &(s_Has)) )
    if (!s_Has) break;
    CHECK(504, ContainerIterator_get(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman, (void*)&(s), &(s_Refman), &dynamic_Void) )
    CHECK(505, Sys_print(sys, sys_Refman, s, s_Refman) )
    aux_String_24 = &aux_String_24_Var;
    aux_String_24_Refman = MR_new_ref(aux_String_24);
    if (aux_String_24_Refman == NULL) RAISE(506, 38, "insufficient memory for managed object")
    aux_String_24_Var.max_length = 2;
    aux_String_24_Var.length = 1;
    aux_String_24_Var.values = " ";
    CHECK(506, Sys_print(sys, sys_Refman, aux_String_24, aux_String_24_Refman) )
    CHECK(504, ContainerIterator_next(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman) )
  }
  MR_dec_ref(aux_ContainerIterator_0_Refman);
  aux_ContainerIterator_0_Refman = NULL;
  MR_inc_ref(aux_ContainerIterator_0_Refman);
  aux_ContainerIterator_0 = NULL;
  aux_String_25 = &aux_String_25_Var;
  aux_String_25_Refman = MR_new_ref(aux_String_25);
  if (aux_String_25_Refman == NULL) RAISE(507, 38, "insufficient memory for managed object")
  aux_String_25_Var.max_length = 2;
  aux_String_25_Var.length = 1;
  aux_String_25_Var.values = "]";
  CHECK(507, Sys_println(sys, sys_Refman, aux_String_25, aux_String_25_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_25_Refman);
  MR_dec_ref(aux_String_24_Refman);
  MR_dec_ref(aux_ContainerIterator_0_Refman);
  MR_dec_ref(aux_String_23_Refman);
  MR_dec_ref(aux_String_22_Refman);
  MR_dec_ref(aux_String_21_Refman);
  MR_dec_ref(aux_String_20_Refman);
  MR_dec_ref(aux_String_19_Refman);
  MR_dec_ref(aux_String_18_Refman);
  MR_dec_ref(aux_Array_2_Refman);
  MR_dec_ref(s_Refman);
  MR_dec_ref(aux_String_17_Refman);
  MR_dec_ref(aux_String_16_Refman);
  MR_dec_ref(aux_String_15_Refman);
  MR_dec_ref(aux_String_14_Refman);
  MR_dec_ref(aux_String_13_Refman);
  MR_dec_ref(aux_String_12_Refman);
  MR_dec_ref(aux_Array_1_Refman);
  MR_dec_ref(ts_Refman);
  MR_dec_ref(aux_String_11_Refman);
  MR_dec_ref(aux_String_10_Refman);
  MR_dec_ref(aux_String_9_Refman);
  MR_dec_ref(aux_String_8_Refman);
  MR_dec_ref(aux_String_7_Refman);
  MR_dec_ref(aux_String_6_Refman);
  MR_dec_ref(aux_Array_0_Refman);
  MR_dec_ref(aux_String_5_Refman);
  MR_dec_ref(aux_String_4_Refman);
  MR_dec_ref(aux_String_3_Refman);
  MR_dec_ref(aux_String_2_Refman);
  MR_dec_ref(aux_String_1_Refman);
  MR_dec_ref(aux_String_0_Refman);
  ContainerIterator_Del(iter);
  MR_owner_dec_ref(iter_Refman);
  MR_dec_ref(container_Refman);
  MR_dec_ref(container_first_Refman);
  MR_dec_ref(container_mid_Refman);
  MR_dec_ref(container_last_Refman);
  MR_dec_ref(sarr_Refman);
  MR_dec_ref(tsarr_Refman);
  MR_dec_ref(arr_Refman);
  MR_dec_ref(text_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "test-complex-field"
Returncode test_complex_field(void) {
  Returncode MR_err = OK;
  HasComplexField y_Var = {{0}};
  HasComplexField* y = NULL;
  Ref_Manager* y_Refman = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  y = &y_Var;
  y_Refman = MR_new_ref(y);
  if (y_Refman == NULL) RAISE(530, 38, "insufficient memory for managed object")
  if (y == NULL) RAISE(531, 27, "used member of empty object")
  if (y_Refman->value == NULL) RAISE(531, 38, "used member of outdated weak reference")
  if (y == NULL) RAISE(531, 27, "used member of empty object")
  if (y_Refman->value == NULL) RAISE(531, 38, "used member of outdated weak reference")
  MR_dec_ref(y->x.x_Refman);
  y->x.x_Refman = y_Refman;
  MR_inc_ref(y->x.x_Refman);
  y->x.x_Dynamic = &ComplexField_dynamic;
  y->x.x = &(y->x);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(532, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "complex fields: ";
  CHECK(532, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  CHECK(533, HasComplexField_run(y, y_Refman) )
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = MR_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(534, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 1;
  aux_String_1_Var.length = 0;
  aux_String_1_Var.values = "";
  CHECK(534, Sys_println(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_1_Refman);
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(y_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME


void Mock_delete(Ref self) {}

/* main function */

USER_MAIN_HEADER {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value;
#define MR_FUNC_NAME "global variable initialization"
#define MR_FILE_NAME "tests/integration-test0.4.mr"
  global_int = 23;
#undef MR_FILE_NAME
#define MR_FILE_NAME "tests/integration-test0.4.mr"
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(19, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 18;
  aux_String_0_Var.length = 17;
  aux_String_0_Var.values = "a constant string";
  global_string = aux_String_0;
  global_string_Refman = aux_String_0_Refman;
  MR_inc_ref(global_string_Refman);
#undef MR_FILE_NAME
#undef MR_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "main"
  CHECK(538, test_simple_function() )
  CHECK(539, test_ref_count() )
  CHECK(540, test_error_handling(NULL, NULL) )
  CHECK(541, test_for_each() )
  CHECK(542, test_complex_field() )
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

MAIN_FUNC
