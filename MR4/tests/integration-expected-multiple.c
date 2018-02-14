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

typedef struct BaseType BaseType;

typedef struct BaseType_Dynamic BaseType_Dynamic;

typedef struct MiddleType MiddleType;

typedef struct MiddleType_Dynamic MiddleType_Dynamic;

typedef struct TopType TopType;

typedef struct TopType_Dynamic TopType_Dynamic;

typedef void* Native;

typedef struct Link Link;

typedef struct BaseLink BaseLink;

typedef struct BaseLink_Dynamic BaseLink_Dynamic;

typedef struct TopLink TopLink;

typedef struct TopLink_Dynamic TopLink_Dynamic;

typedef struct RefNode RefNode;


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

struct BaseType {
  Int num_base;
  MiddleType* base_mid_ref;
  Ref_Manager* base_mid_ref_Refman;
  MiddleType_Dynamic* base_mid_ref_Dynamic;
  TopType* base_top_ref;
  Ref_Manager* base_top_ref_Refman;
  TopType_Dynamic* base_top_ref_Dynamic;
};

struct BaseType_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth0)(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic);
  Returncode (*meth1)(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);
  Returncode (*meth2)(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic);
  Returncode (*meth3)(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);
};

struct MiddleType {
  BaseType _base;
  Int num_mid;
  BaseType* mid_base_ref;
  Ref_Manager* mid_base_ref_Refman;
  BaseType_Dynamic* mid_base_ref_Dynamic;
  TopType* mid_top_ref;
  Ref_Manager* mid_top_ref_Refman;
  TopType_Dynamic* mid_top_ref_Dynamic;
};

struct MiddleType_Dynamic {
  BaseType_Dynamic _base;
  Returncode (*meth4)(MiddleType* self, Ref_Manager* self_Refman, MiddleType_Dynamic* self_Dynamic);
  Returncode (*meth5)(MiddleType* self, Ref_Manager* self_Refman, MiddleType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);
};

struct TopType {
  MiddleType _base;
  Int num_top;
  BaseType* top_base_ref;
  Ref_Manager* top_base_ref_Refman;
  BaseType_Dynamic* top_base_ref_Dynamic;
  MiddleType* top_mid_ref;
  Ref_Manager* top_mid_ref_Refman;
  MiddleType_Dynamic* top_mid_ref_Dynamic;
};

struct TopType_Dynamic {
  MiddleType_Dynamic _base;
  Returncode (*meth6)(TopType* self, Ref_Manager* self_Refman, TopType_Dynamic* self_Dynamic);
};

struct Link {
  Link* next;
  Ref_Manager* next_Refman;
};

struct BaseLink {
  BaseLink* next;
  Ref_Manager* next_Refman;
  BaseLink_Dynamic* next_Dynamic;
  Link* link;
  Ref_Manager* link_Refman;
};

struct BaseLink_Dynamic {
  Dynamic_Del _del;
  Returncode (*m_meth)(BaseLink* self, Ref_Manager* self_Refman, BaseLink_Dynamic* self_Dynamic);
};

struct TopLink {
  BaseLink _base;
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};

struct TopLink_Dynamic {
  BaseLink_Dynamic _base;
};

struct RefNode {
  RefNode* next;
  Ref_Manager* next_Refman;
  Ref ref;
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

Returncode BaseType_new(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic);

Returncode BaseType_meth0(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic);

Returncode BaseType_meth1(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);

Returncode BaseType_meth2(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic);

Returncode BaseType_meth3(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);

void BaseType_Del(BaseType* self);

Returncode MiddleType_new(MiddleType* self, Ref_Manager* self_Refman, MiddleType_Dynamic* self_Dynamic);

Returncode MiddleType_meth1(MiddleType* self, Ref_Manager* self_Refman, MiddleType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);

Returncode MiddleType_meth2(MiddleType* self, Ref_Manager* self_Refman, MiddleType_Dynamic* self_Dynamic);

Returncode MiddleType_meth4(MiddleType* self, Ref_Manager* self_Refman, MiddleType_Dynamic* self_Dynamic);

Returncode MiddleType_meth5(MiddleType* self, Ref_Manager* self_Refman, MiddleType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);

void MiddleType_Del(MiddleType* self);

Returncode TopType_new(TopType* self, Ref_Manager* self_Refman, TopType_Dynamic* self_Dynamic);

Returncode TopType_meth2(TopType* self, Ref_Manager* self_Refman, TopType_Dynamic* self_Dynamic);

Returncode TopType_meth3(TopType* self, Ref_Manager* self_Refman, TopType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);

Returncode TopType_meth5(TopType* self, Ref_Manager* self_Refman, TopType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);

Returncode TopType_meth6(TopType* self, Ref_Manager* self_Refman, TopType_Dynamic* self_Dynamic);

void TopType_Del(TopType* self);

void Link_Del(Link* self);

Returncode BaseLink_m_meth(BaseLink* self, Ref_Manager* self_Refman, BaseLink_Dynamic* self_Dynamic);

void BaseLink_Del(BaseLink* self);

void TopLink_Del(TopLink* self);

Returncode RefNode_new(RefNode* self, Ref_Manager* self_Refman, Ref ref, RefNode* next, Ref_Manager* next_Refman);

void RefNode_Del(RefNode* self);


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

BaseType_Dynamic BaseType_dynamic = {(Dynamic_Del)BaseType_Del, BaseType_meth0, BaseType_meth1, BaseType_meth2, BaseType_meth3};

MiddleType_Dynamic MiddleType_dynamic = {{(Dynamic_Del)MiddleType_Del, BaseType_meth0, (Func)MiddleType_meth1, (Func)MiddleType_meth2, BaseType_meth3}, MiddleType_meth4, MiddleType_meth5};

TopType_Dynamic TopType_dynamic = {{{(Dynamic_Del)TopType_Del, BaseType_meth0, (Func)MiddleType_meth1, (Func)TopType_meth2, (Func)TopType_meth3}, MiddleType_meth4, (Func)TopType_meth5}, TopType_meth6};

Generic_Type_Dynamic Link_dynamic = {(Dynamic_Del)Link_Del};

BaseLink_Dynamic BaseLink_dynamic = {(Dynamic_Del)BaseLink_Del, BaseLink_m_meth};

TopLink_Dynamic TopLink_dynamic = {{(Dynamic_Del)TopLink_Del, BaseLink_m_meth}};

Generic_Type_Dynamic RefNode_dynamic = {(Dynamic_Del)RefNode_Del};


/* global variables */

Int global_int = 0;

String* global_string = NULL;
Ref_Manager* global_string_Refman = NULL;

extern Int external_int;

Bool record_delete = 0;

RefNode* deleted_links = NULL;
Ref_Manager* deleted_links_Refman = NULL;

RefNode* deleted_base_links = NULL;
Ref_Manager* deleted_base_links_Refman = NULL;

RefNode* deleted_top_links = NULL;
Ref_Manager* deleted_top_links_Refman = NULL;

RefNode* deleted_refmans = NULL;
Ref_Manager* deleted_refmans_Refman = NULL;


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

Returncode test_mid_out(MiddleType** mt, Ref_Manager** mt_Refman, MiddleType_Dynamic** mt_Dynamic);

Returncode TestStruct_Mock_get(TestStruct* self, Ref_Manager* self_Refman, Int* x, String** s, Ref_Manager** s_Refman);

Returncode Mock_f_test_int2str(Int x, String** s, Ref_Manager** s_Refman);

Returncode test_func(void);

Returncode test_another(void);

Returncode external(Int i, String* s, Int* io, Native* n);

Returncode external2(Native n, Bool* b);

Returncode test_native(void);

Returncode test_dynamic_type_parameters(void);

Returncode Mock_delete(Ref self);

Returncode Link_MockDel(Ref self);

Returncode BaseLink_MockDel(Ref self);

Returncode TopLink_MockDel(Ref self);

Returncode f_remove_obj(Link* b, Ref_Manager* b_Refman);

Returncode test_simple_delete(void);

Returncode f_has_ref(Ref ref, RefNode** node, Ref_Manager** node_Refman);

Returncode f_has_ref_rec(Ref ref, RefNode** node, Ref_Manager** node_Refman);

Returncode test_complex_delete(void);

Returncode f_raise_message(void);

Returncode f_ignore_and_raise(void);

Returncode f_failed_assert(void);

Returncode f_good_assert_error(void);

Returncode f_failed_assert_error(void);

Returncode f_wrong_message_assert_error(void);

Returncode test_assert_error_message(void);


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

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "BaseType.new"
Returncode BaseType_new(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  if (self == NULL) RAISE(49, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(49, 38, "used member of outdated weak reference")
  self->num_base = 1;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "BaseType.meth0"
Returncode BaseType_meth0(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(52, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "BaseType.meth0";
  CHECK(52, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "BaseType.meth1"
Returncode BaseType_meth1(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  MR_inc_ref(s_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(55, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "BaseType.meth1";
  CHECK(55, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "BaseType.meth2"
Returncode BaseType_meth2(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(58, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "BaseType.meth2";
  CHECK(58, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "BaseType.meth3"
Returncode BaseType_meth3(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  MR_inc_ref(s_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(61, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "BaseType.meth3";
  CHECK(61, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void BaseType_Del(BaseType* self) {
  if (self == NULL) return;
  MR_dec_ref(self->base_top_ref_Refman);
  MR_dec_ref(self->base_mid_ref_Refman);
}

#define MR_FILE_NAME "tests/integration-test2.4.mr"
#define MR_FUNC_NAME "MiddleType.new"
Returncode MiddleType_new(MiddleType* self, Ref_Manager* self_Refman, MiddleType_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  CHECK(13, BaseType_new(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
  if (self == NULL) RAISE(14, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(14, 38, "used member of outdated weak reference")
  self->num_mid = 2;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test2.4.mr"
#define MR_FUNC_NAME "MiddleType.meth1"
Returncode MiddleType_meth1(MiddleType* self, Ref_Manager* self_Refman, MiddleType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  MR_inc_ref(s_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(17, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "MiddleType.meth1";
  CHECK(17, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  CHECK(18, BaseType_meth1(&(self->_base), self_Refman, &(self_Dynamic->_base), n, s, s_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test2.4.mr"
#define MR_FUNC_NAME "MiddleType.meth2"
Returncode MiddleType_meth2(MiddleType* self, Ref_Manager* self_Refman, MiddleType_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(21, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "MiddleType.meth2";
  CHECK(21, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  CHECK(22, BaseType_meth2(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test2.4.mr"
#define MR_FUNC_NAME "MiddleType.meth4"
Returncode MiddleType_meth4(MiddleType* self, Ref_Manager* self_Refman, MiddleType_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(25, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "MiddleType.meth4";
  CHECK(25, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test2.4.mr"
#define MR_FUNC_NAME "MiddleType.meth5"
Returncode MiddleType_meth5(MiddleType* self, Ref_Manager* self_Refman, MiddleType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  MR_inc_ref(s_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(28, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "MiddleType.meth5";
  CHECK(28, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void MiddleType_Del(MiddleType* self) {
  if (self == NULL) return;
  BaseType_Del(&(self->_base));
  MR_dec_ref(self->mid_top_ref_Refman);
  MR_dec_ref(self->mid_base_ref_Refman);
}

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TopType.new"
Returncode TopType_new(TopType* self, Ref_Manager* self_Refman, TopType_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  CHECK(13, MiddleType_new(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
  if (self == NULL) RAISE(14, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(14, 38, "used member of outdated weak reference")
  self->num_top = 3;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TopType.meth2"
Returncode TopType_meth2(TopType* self, Ref_Manager* self_Refman, TopType_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(18, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 14;
  aux_String_0_Var.length = 13;
  aux_String_0_Var.values = "TopType.meth2";
  CHECK(18, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  CHECK(19, MiddleType_meth2(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
  CHECK(20, MiddleType_meth2(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
  CHECK(21, BaseType_meth2(&(self->_base._base), self_Refman, &(self_Dynamic->_base._base)) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TopType.meth3"
Returncode TopType_meth3(TopType* self, Ref_Manager* self_Refman, TopType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  MR_inc_ref(s_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(24, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 14;
  aux_String_0_Var.length = 13;
  aux_String_0_Var.values = "TopType.meth3";
  CHECK(24, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  CHECK(25, BaseType_meth3(&(self->_base._base), self_Refman, &(self_Dynamic->_base._base), n, s, s_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TopType.meth5"
Returncode TopType_meth5(TopType* self, Ref_Manager* self_Refman, TopType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  MR_inc_ref(s_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(28, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 14;
  aux_String_0_Var.length = 13;
  aux_String_0_Var.values = "TopType.meth5";
  CHECK(28, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  CHECK(29, MiddleType_meth5(&(self->_base), self_Refman, &(self_Dynamic->_base), n, s, s_Refman) )
  CHECK(30, MiddleType_meth1(NULL, NULL, NULL, n, s, s_Refman) )
  CHECK(31, BaseType_meth1(NULL, NULL, NULL, n, s, s_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TopType.meth6"
Returncode TopType_meth6(TopType* self, Ref_Manager* self_Refman, TopType_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  MiddleType* mt = NULL;
  Ref_Manager* mt_Refman = NULL;
  MiddleType_Dynamic* mt_Dynamic = NULL;
  BaseType* bt = NULL;
  Ref_Manager* bt_Refman = NULL;
  BaseType_Dynamic* bt_Dynamic = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(34, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 14;
  aux_String_0_Var.length = 13;
  aux_String_0_Var.values = "TopType.meth6";
  CHECK(34, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  if (self == NULL) RAISE(35, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(35, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(35, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(35, 38, "used member of outdated weak reference")
  self->_base.num_mid = self->_base._base.num_base;
  if (self == NULL) RAISE(36, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(36, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(36, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(36, 38, "used member of outdated weak reference")
  MR_dec_ref(self->top_base_ref_Refman);
  self->top_base_ref_Refman = self->top_mid_ref_Refman;
  MR_inc_ref(self->top_base_ref_Refman);
  self->top_base_ref_Dynamic = &(self->top_mid_ref_Dynamic->_base);
  self->top_base_ref = &(self->top_mid_ref->_base);
  if (self == NULL) RAISE(37, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(37, 38, "used member of outdated weak reference")
  MR_dec_ref(self->top_base_ref_Refman);
  self->top_base_ref_Refman = self_Refman;
  MR_inc_ref(self->top_base_ref_Refman);
  self->top_base_ref_Dynamic = &(self_Dynamic->_base._base);
  self->top_base_ref = &(self->_base._base);
  mt = &(self->_base);
  mt_Refman = self_Refman;
  MR_inc_ref(mt_Refman);
  mt_Dynamic = &(self_Dynamic->_base);
  bt = &(mt->_base);
  bt_Refman = mt_Refman;
  MR_inc_ref(bt_Refman);
  bt_Dynamic = &(mt_Dynamic->_base);
  if (bt != NULL) RAISE(40, 45, "non empty base class given as output argument")
  CHECK(40, test_mid_out((void*)&(bt), &(bt_Refman), (void*)&(bt_Dynamic)) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(bt_Refman);
  MR_dec_ref(mt_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void TopType_Del(TopType* self) {
  if (self == NULL) return;
  MiddleType_Del(&(self->_base));
  MR_dec_ref(self->top_mid_ref_Refman);
  MR_dec_ref(self->top_base_ref_Refman);
}

void Link_Del(Link* self) {
  if (self == NULL) return;
  IGNORE_ERRORS( Link_MockDel(self) )
  SELF_REF_DEL(Link, next);
  MR_owner_dec_ref(self->next_Refman);
}

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "BaseLink.m-meth"
Returncode BaseLink_m_meth(BaseLink* self, Ref_Manager* self_Refman, BaseLink_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void BaseLink_Del(BaseLink* self) {
  if (self == NULL) return;
  IGNORE_ERRORS( BaseLink_MockDel(self) )
  MR_dec_ref(self->link_Refman);
  DYN_SELF_REF_DEL(BaseLink, _, next);
  MR_owner_dec_ref(self->next_Refman);
}

void TopLink_Del(TopLink* self) {
  if (self == NULL) return;
  BaseLink_Del(&(self->_base));
  IGNORE_ERRORS( TopLink_MockDel(self) )
  if (self->item_Dynamic != NULL) self->item_Dynamic->_del(self->item);
  MR_owner_dec_ref(self->item_Refman);
}

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "RefNode.new"
Returncode RefNode_new(RefNode* self, Ref_Manager* self_Refman, Ref ref, RefNode* next, Ref_Manager* next_Refman) {
  Returncode MR_err = OK;
  if (self == NULL) RAISE(141, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(141, 38, "used member of outdated weak reference")
  self->ref = ref;
  if (self == NULL) RAISE(142, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(142, 38, "used member of outdated weak reference")
  RefNode_Del(self->next);
  MR_owner_dec_ref(self->next_Refman);
  self->next_Refman = next_Refman;
  self->next = next;
  next = NULL;
  next_Refman = NULL;
MR_cleanup:
  RefNode_Del(next);
  MR_owner_dec_ref(next_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void RefNode_Del(RefNode* self) {
  if (self == NULL) return;
  SELF_REF_DEL(RefNode, next);
  MR_owner_dec_ref(self->next_Refman);
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
  fi = Mock_f_test_int2str;
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
  CHECK(249, Mock_f_test_int2str(4, &(s), &(s_Refman)) )
  CHECK(250, f_test_int(5) )
  CHECK(251, f_test_int2int(6, &(x)) )
  CHECK(252, f_test_many(7, 8, &(x), &(x)) )
  CHECK(258, f_test_int2int(9, &(tmp)) )
  CHECK(258, f_test_int(tmp) )
  CHECK(259, f_test_many(11, 12, &(x), &(aux_Int_0)) )
  CHECK(259, f_test_int2int(10, &(aux_Int_1)) )
  x = aux_Int_1 + aux_Int_0;
  CHECK(260, Mock_f_test_int2str(13, &(aux_String_1), &(aux_String_1_Refman)) )
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

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "test-mid-out"
Returncode test_mid_out(MiddleType** mt, Ref_Manager** mt_Refman, MiddleType_Dynamic** mt_Dynamic) {
  Returncode MR_err = OK;
  MiddleType* new_mt = NULL;
  Ref_Manager* new_mt_Refman = NULL;
  MiddleType_Dynamic* new_mt_Dynamic = &MiddleType_dynamic;
  new_mt = calloc(1, sizeof(MiddleType));
  if (new_mt == NULL) RAISE(65, 49, "insufficient memory for object dynamic allocation")
  new_mt_Refman = MR_new_ref(new_mt);
  if (new_mt_Refman == NULL) RAISE(65, 38, "insufficient memory for managed object")
  CHECK(65, MiddleType_new(new_mt, new_mt_Refman, new_mt_Dynamic) )
  MR_dec_ref(*mt_Refman);
  *mt_Refman = new_mt_Refman;
  MR_inc_ref(*mt_Refman);
  *mt_Dynamic = new_mt_Dynamic;
  *mt = new_mt;
MR_cleanup:
  if (new_mt_Dynamic != NULL) new_mt_Dynamic->_base._del(new_mt);
  MR_owner_dec_ref(new_mt_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TestStruct.Mock get"
Returncode TestStruct_Mock_get(TestStruct* self, Ref_Manager* self_Refman, Int* x, String** s, Ref_Manager** s_Refman) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  *x = 12;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(71, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 1;
  aux_String_0_Var.length = 0;
  aux_String_0_Var.values = "";
  MR_dec_ref(*s_Refman);
  *s_Refman = aux_String_0_Refman;
  MR_inc_ref(*s_Refman);
  *s = aux_String_0;
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "Mock f-test-int2str"
Returncode Mock_f_test_int2str(Int x, String** s, Ref_Manager** s_Refman) {
  Returncode MR_err = OK;
  USER_RAISE(75, NULL, NULL)
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "test-func"
Returncode test_func(void) {
  Returncode MR_err = OK;
  TestStruct t_Var = {0};
  TestStruct* t = NULL;
  Ref_Manager* t_Refman = NULL;
  Int x = 0;
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(79, 38, "insufficient memory for managed object")
  CHECK(79, TestStruct_new(t, t_Refman, 0, NULL, NULL) )
  CHECK(81, TestStruct_Mock_get(t, t_Refman, &(x), &(aux_String_0), &(aux_String_0_Refman)) )
  TEST_ASSERT(82, x == 12)
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(83, Mock_f_test_int2str(3, &(aux_String_1), &(aux_String_1_Refman)) )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(83, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
MR_cleanup:
  String_Del(aux_String_1);
  MR_owner_dec_ref(aux_String_1_Refman);
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(t_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "test-another"
Returncode test_another(void) {
  Returncode MR_err = OK;
  Int x = 0;
  TEST_ASSERT(88, x == 0)
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "test-native"
Returncode test_native(void) {
  Returncode MR_err = OK;
  Int i = 0;
  Native n = 0;
  char s_Values[4] = {0};
  String s_Var = {4, 0, NULL};
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  Bool aux_Bool_0 = 0;
  TEST_ASSERT(98, external_int == 6)
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(101, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = "bb";
  s = &s_Var;
  s_Var.values = s_Values;
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(101, 38, "insufficient memory for managed object")
  CHECK(101, String_new(s, s_Refman, aux_String_0, aux_String_0_Refman) )
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(102, external(3, s, &(i), &(n)) )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(102, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  TEST_ASSERT(103, i == 3)
  if (s == NULL) RAISE(104, 29, "empty object used as sequence")
  if (s_Refman->value == NULL) RAISE(104, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (s)->length) RAISE(104, 25, "slice index out of bounds")
  TEST_ASSERT(104, (((s)->values)[0]) == 'a')
  CHECK(105, external2(n, &(aux_Bool_0)) )
  TEST_ASSERT(105, aux_Bool_0)
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "test-dynamic-type-parameters"
Returncode test_dynamic_type_parameters(void) {
  Returncode MR_err = OK;
  Data dmid_Var = {0};
  Data* dmid = NULL;
  Ref_Manager* dmid_Refman = NULL;
  TopType ttop_Var = {{{0}}};
  TopType* ttop = NULL;
  Ref_Manager* ttop_Refman = NULL;
  TopType_Dynamic* ttop_Dynamic = &TopType_dynamic;
  BaseType* tbase = NULL;
  Ref_Manager* tbase_Refman = NULL;
  BaseType_Dynamic* tbase_Dynamic = NULL;
  dmid = &dmid_Var;
  dmid_Refman = MR_new_ref(dmid);
  if (dmid_Refman == NULL) RAISE(109, 38, "insufficient memory for managed object")
  ttop = &ttop_Var;
  ttop_Refman = MR_new_ref(ttop);
  if (ttop_Refman == NULL) RAISE(110, 38, "insufficient memory for managed object")
  CHECK(110, TopType_new(ttop, ttop_Refman, ttop_Dynamic) )
  if (ttop == NULL) RAISE(111, 27, "used member of empty object")
  if (ttop_Refman->value == NULL) RAISE(111, 38, "used member of outdated weak reference")
  ttop->_base._base.num_base = 12;
  if (dmid == NULL) RAISE(112, 27, "used member of empty object")
  if (dmid_Refman->value == NULL) RAISE(112, 38, "used member of outdated weak reference")
  MR_dec_ref(dmid->item_Refman);
  dmid->item_Refman = ttop_Refman;
  MR_inc_ref(dmid->item_Refman);
  dmid->item_Dynamic = (Generic_Type_Dynamic*)&(ttop_Dynamic->_base);
  dmid->item = &(ttop->_base);
  if (dmid == NULL) RAISE(114, 27, "used member of empty object")
  if (dmid_Refman->value == NULL) RAISE(114, 38, "used member of outdated weak reference")
  MR_dec_ref(tbase_Refman);
  tbase_Refman = dmid->item_Refman;
  MR_inc_ref(tbase_Refman);
  tbase_Dynamic = &(((MiddleType_Dynamic*)(dmid->item_Dynamic))->_base);
  tbase = &(((MiddleType*)(dmid->item))->_base);
  if (tbase == NULL) RAISE(115, 27, "used member of empty object")
  if (tbase_Refman->value == NULL) RAISE(115, 38, "used member of outdated weak reference")
  TEST_ASSERT(115, tbase->num_base == 12)
  if (ttop == NULL) RAISE(116, 27, "used member of empty object")
  if (ttop_Refman->value == NULL) RAISE(116, 38, "used member of outdated weak reference")
  ttop->_base._base.num_base = 13;
  CHECK(117, Data_set(dmid, dmid_Refman, &(ttop->_base), ttop_Refman, (void*)&(ttop_Dynamic->_base), NULL, NULL) )
  MR_dec_ref(tbase_Refman);
  tbase_Refman = NULL;
  MR_inc_ref(tbase_Refman);
  tbase_Dynamic = NULL;
  tbase = NULL;
  if (tbase != NULL) RAISE(119, 45, "non empty base class given as output argument")
  CHECK(119, Data_get(dmid, dmid_Refman, (void*)&(tbase), &(tbase_Refman), (void*)&(tbase_Dynamic)) )
  if (tbase == NULL) RAISE(120, 27, "used member of empty object")
  if (tbase_Refman->value == NULL) RAISE(120, 38, "used member of outdated weak reference")
  TEST_ASSERT(120, tbase->num_base == 13)
MR_cleanup:
  MR_dec_ref(tbase_Refman);
  MR_dec_ref(ttop_Refman);
  MR_dec_ref(dmid_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "Mock delete"
Returncode Mock_delete(Ref self) {
  Returncode MR_err = OK;
  RefNode* aux_RefNode_0 = NULL;
  Ref_Manager* aux_RefNode_0_Refman = NULL;
  if (record_delete) {
    aux_RefNode_0 = calloc(1, sizeof(RefNode));
    if (aux_RefNode_0 == NULL) RAISE(152, 49, "insufficient memory for object dynamic allocation")
    aux_RefNode_0_Refman = MR_new_ref(aux_RefNode_0);
    if (aux_RefNode_0_Refman == NULL) RAISE(152, 38, "insufficient memory for managed object")
    CHECK(152, RefNode_new(aux_RefNode_0, aux_RefNode_0_Refman, self, deleted_refmans, deleted_refmans_Refman) )
    deleted_refmans = NULL;
    deleted_refmans_Refman = NULL;
    RefNode_Del(deleted_refmans);
    MR_owner_dec_ref(deleted_refmans_Refman);
    deleted_refmans_Refman = aux_RefNode_0_Refman;
    deleted_refmans = aux_RefNode_0;
    aux_RefNode_0 = NULL;
    aux_RefNode_0_Refman = NULL;
  }
MR_cleanup:
  RefNode_Del(aux_RefNode_0);
  MR_owner_dec_ref(aux_RefNode_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "Link.MockDel"
Returncode Link_MockDel(Ref self) {
  Returncode MR_err = OK;
  RefNode* aux_RefNode_0 = NULL;
  Ref_Manager* aux_RefNode_0_Refman = NULL;
  if (record_delete) {
    aux_RefNode_0 = calloc(1, sizeof(RefNode));
    if (aux_RefNode_0 == NULL) RAISE(156, 49, "insufficient memory for object dynamic allocation")
    aux_RefNode_0_Refman = MR_new_ref(aux_RefNode_0);
    if (aux_RefNode_0_Refman == NULL) RAISE(156, 38, "insufficient memory for managed object")
    CHECK(156, RefNode_new(aux_RefNode_0, aux_RefNode_0_Refman, self, deleted_links, deleted_links_Refman) )
    deleted_links = NULL;
    deleted_links_Refman = NULL;
    RefNode_Del(deleted_links);
    MR_owner_dec_ref(deleted_links_Refman);
    deleted_links_Refman = aux_RefNode_0_Refman;
    deleted_links = aux_RefNode_0;
    aux_RefNode_0 = NULL;
    aux_RefNode_0_Refman = NULL;
  }
MR_cleanup:
  RefNode_Del(aux_RefNode_0);
  MR_owner_dec_ref(aux_RefNode_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "BaseLink.MockDel"
Returncode BaseLink_MockDel(Ref self) {
  Returncode MR_err = OK;
  RefNode* aux_RefNode_0 = NULL;
  Ref_Manager* aux_RefNode_0_Refman = NULL;
  if (record_delete) {
    aux_RefNode_0 = calloc(1, sizeof(RefNode));
    if (aux_RefNode_0 == NULL) RAISE(160, 49, "insufficient memory for object dynamic allocation")
    aux_RefNode_0_Refman = MR_new_ref(aux_RefNode_0);
    if (aux_RefNode_0_Refman == NULL) RAISE(160, 38, "insufficient memory for managed object")
    CHECK(160, RefNode_new(aux_RefNode_0, aux_RefNode_0_Refman, self, deleted_base_links, deleted_base_links_Refman) )
    deleted_base_links = NULL;
    deleted_base_links_Refman = NULL;
    RefNode_Del(deleted_base_links);
    MR_owner_dec_ref(deleted_base_links_Refman);
    deleted_base_links_Refman = aux_RefNode_0_Refman;
    deleted_base_links = aux_RefNode_0;
    aux_RefNode_0 = NULL;
    aux_RefNode_0_Refman = NULL;
  }
MR_cleanup:
  RefNode_Del(aux_RefNode_0);
  MR_owner_dec_ref(aux_RefNode_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TopLink.MockDel"
Returncode TopLink_MockDel(Ref self) {
  Returncode MR_err = OK;
  RefNode* aux_RefNode_0 = NULL;
  Ref_Manager* aux_RefNode_0_Refman = NULL;
  if (record_delete) {
    aux_RefNode_0 = calloc(1, sizeof(RefNode));
    if (aux_RefNode_0 == NULL) RAISE(164, 49, "insufficient memory for object dynamic allocation")
    aux_RefNode_0_Refman = MR_new_ref(aux_RefNode_0);
    if (aux_RefNode_0_Refman == NULL) RAISE(164, 38, "insufficient memory for managed object")
    CHECK(164, RefNode_new(aux_RefNode_0, aux_RefNode_0_Refman, self, deleted_top_links, deleted_top_links_Refman) )
    deleted_top_links = NULL;
    deleted_top_links_Refman = NULL;
    RefNode_Del(deleted_top_links);
    MR_owner_dec_ref(deleted_top_links_Refman);
    deleted_top_links_Refman = aux_RefNode_0_Refman;
    deleted_top_links = aux_RefNode_0;
    aux_RefNode_0 = NULL;
    aux_RefNode_0_Refman = NULL;
  }
MR_cleanup:
  RefNode_Del(aux_RefNode_0);
  MR_owner_dec_ref(aux_RefNode_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "f-remove-obj"
Returncode f_remove_obj(Link* b, Ref_Manager* b_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  Link_Del(b);
  MR_owner_dec_ref(b_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "test-simple-delete"
Returncode test_simple_delete(void) {
  Returncode MR_err = OK;
  Link* l = NULL;
  Ref_Manager* l_Refman = NULL;
  Link* l_user = NULL;
  Ref_Manager* l_user_Refman = NULL;
  Ref l_ref = NULL;
  TEST_ASSERT(170, ! (deleted_refmans != NULL && deleted_refmans_Refman->value != NULL))
  TEST_ASSERT(171, ! (deleted_links != NULL && deleted_links_Refman->value != NULL))
  record_delete = true;
  l = calloc(1, sizeof(Link));
  if (l == NULL) RAISE(174, 49, "insufficient memory for object dynamic allocation")
  l_Refman = MR_new_ref(l);
  if (l_Refman == NULL) RAISE(174, 38, "insufficient memory for managed object")
  l_user = l;
  l_user_Refman = l_Refman;
  MR_inc_ref(l_user_Refman);
  TEST_ASSERT(176, l != NULL && l_Refman->value != NULL)
  TEST_ASSERT(177, l_user != NULL && l_user_Refman->value != NULL)
  l_ref = l;
  CHECK(179, f_remove_obj(l, l_Refman) )
  l = NULL;
  l_Refman = NULL;
  TEST_ASSERT(180, ! (l != NULL && l_Refman->value != NULL))
  TEST_ASSERT(181, ! (l_user != NULL && l_user_Refman->value != NULL))
  TEST_ASSERT(182, ! (deleted_refmans != NULL && deleted_refmans_Refman->value != NULL))
  TEST_ASSERT(183, deleted_links != NULL && deleted_links_Refman->value != NULL)
  if (deleted_links == NULL) RAISE(184, 27, "used member of empty object")
  if (deleted_links_Refman->value == NULL) RAISE(184, 38, "used member of outdated weak reference")
  TEST_ASSERT(184, deleted_links->ref == l_ref)
  if (deleted_links == NULL) RAISE(185, 27, "used member of empty object")
  if (deleted_links_Refman->value == NULL) RAISE(185, 38, "used member of outdated weak reference")
  TEST_ASSERT(185, ! (deleted_links->next != NULL && deleted_links->next_Refman->value != NULL))
  MR_dec_ref(l_user_Refman);
  l_user_Refman = NULL;
  MR_inc_ref(l_user_Refman);
  l_user = NULL;
  TEST_ASSERT(187, deleted_refmans != NULL && deleted_refmans_Refman->value != NULL)
  if (deleted_refmans == NULL) RAISE(188, 27, "used member of empty object")
  if (deleted_refmans_Refman->value == NULL) RAISE(188, 38, "used member of outdated weak reference")
  TEST_ASSERT(188, deleted_refmans->ref == l_ref)
  if (deleted_refmans == NULL) RAISE(189, 27, "used member of empty object")
  if (deleted_refmans_Refman->value == NULL) RAISE(189, 38, "used member of outdated weak reference")
  TEST_ASSERT(189, ! (deleted_refmans->next != NULL && deleted_refmans->next_Refman->value != NULL))
  record_delete = false;
  RefNode_Del(deleted_refmans);
  MR_owner_dec_ref(deleted_refmans_Refman);
  deleted_refmans_Refman = NULL;
  deleted_refmans = NULL;
  RefNode_Del(deleted_links);
  MR_owner_dec_ref(deleted_links_Refman);
  deleted_links_Refman = NULL;
  deleted_links = NULL;
MR_cleanup:
  MR_dec_ref(l_user_Refman);
  Link_Del(l);
  MR_owner_dec_ref(l_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "f-has-ref"
Returncode f_has_ref(Ref ref, RefNode** node, Ref_Manager** node_Refman) {
  Returncode MR_err = OK;
  CHECK(196, f_has_ref_rec(ref, &(*node), &(*node_Refman)) )
  CHECK(197, f_has_ref_rec(ref, &(deleted_refmans), &(deleted_refmans_Refman)) )
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "f-has-ref-rec"
Returncode f_has_ref_rec(Ref ref, RefNode** node, Ref_Manager** node_Refman) {
  Returncode MR_err = OK;
  RefNode* next = NULL;
  Ref_Manager* next_Refman = NULL;
  TEST_ASSERT(200, (*node) != NULL && (*node_Refman)->value != NULL)
  if (*node == NULL) RAISE(201, 27, "used member of empty object")
  if ((*node_Refman)->value == NULL) RAISE(201, 38, "used member of outdated weak reference")
  if ((*node)->ref == ref) {
    if (*node == NULL) RAISE(202, 27, "used member of empty object")
    if ((*node_Refman)->value == NULL) RAISE(202, 38, "used member of outdated weak reference")
    next = (*node)->next;
    next_Refman = (*node)->next_Refman;
    (*node)->next = NULL;
    (*node)->next_Refman = NULL;
    RefNode_Del(*node);
    MR_owner_dec_ref(*node_Refman);
    *node_Refman = next_Refman;
    *node = next;
    next = NULL;
    next_Refman = NULL;
  }
  else {
    if (*node == NULL) RAISE(205, 27, "used member of empty object")
    if ((*node_Refman)->value == NULL) RAISE(205, 38, "used member of outdated weak reference")
    CHECK(205, f_has_ref_rec(ref, &((*node)->next), &((*node)->next_Refman)) )
  }
MR_cleanup:
  RefNode_Del(next);
  MR_owner_dec_ref(next_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "test-complex-delete"
Returncode test_complex_delete(void) {
  Returncode MR_err = OK;
  BaseLink* b1 = NULL;
  Ref_Manager* b1_Refman = NULL;
  BaseLink_Dynamic* b1_Dynamic = &BaseLink_dynamic;
  Ref b1_ref = NULL;
  BaseLink* b2 = NULL;
  Ref_Manager* b2_Refman = NULL;
  BaseLink_Dynamic* b2_Dynamic = &BaseLink_dynamic;
  Ref b2_ref = NULL;
  TopLink* t1 = NULL;
  Ref_Manager* t1_Refman = NULL;
  TopLink_Dynamic* t1_Dynamic = &TopLink_dynamic;
  Ref t1_ref = NULL;
  TopLink* t2 = NULL;
  Ref_Manager* t2_Refman = NULL;
  TopLink_Dynamic* t2_Dynamic = &TopLink_dynamic;
  Ref t2_ref = NULL;
  TopLink* t3 = NULL;
  Ref_Manager* t3_Refman = NULL;
  TopLink_Dynamic* t3_Dynamic = &TopLink_dynamic;
  Ref t3_ref = NULL;
  Link* l1 = NULL;
  Ref_Manager* l1_Refman = NULL;
  Ref l1_ref = NULL;
  Link* l2 = NULL;
  Ref_Manager* l2_Refman = NULL;
  Ref l2_ref = NULL;
  Link* l3 = NULL;
  Ref_Manager* l3_Refman = NULL;
  Ref l3_ref = NULL;
  TEST_ASSERT(208, ! (deleted_refmans != NULL && deleted_refmans_Refman->value != NULL))
  TEST_ASSERT(209, ! (deleted_links != NULL && deleted_links_Refman->value != NULL))
  TEST_ASSERT(210, ! (deleted_base_links != NULL && deleted_base_links_Refman->value != NULL))
  TEST_ASSERT(211, ! (deleted_top_links != NULL && deleted_top_links_Refman->value != NULL))
  record_delete = true;
  b1 = calloc(1, sizeof(BaseLink));
  if (b1 == NULL) RAISE(214, 49, "insufficient memory for object dynamic allocation")
  b1_Refman = MR_new_ref(b1);
  if (b1_Refman == NULL) RAISE(214, 38, "insufficient memory for managed object")
  b1_ref = b1;
  b2 = calloc(1, sizeof(BaseLink));
  if (b2 == NULL) RAISE(216, 49, "insufficient memory for object dynamic allocation")
  b2_Refman = MR_new_ref(b2);
  if (b2_Refman == NULL) RAISE(216, 38, "insufficient memory for managed object")
  b2_ref = b2;
  t1 = calloc(1, sizeof(TopLink));
  if (t1 == NULL) RAISE(218, 49, "insufficient memory for object dynamic allocation")
  t1_Refman = MR_new_ref(t1);
  if (t1_Refman == NULL) RAISE(218, 38, "insufficient memory for managed object")
  t1_ref = t1;
  t2 = calloc(1, sizeof(TopLink));
  if (t2 == NULL) RAISE(220, 49, "insufficient memory for object dynamic allocation")
  t2_Refman = MR_new_ref(t2);
  if (t2_Refman == NULL) RAISE(220, 38, "insufficient memory for managed object")
  t2_ref = t2;
  t3 = calloc(1, sizeof(TopLink));
  if (t3 == NULL) RAISE(222, 49, "insufficient memory for object dynamic allocation")
  t3_Refman = MR_new_ref(t3);
  if (t3_Refman == NULL) RAISE(222, 38, "insufficient memory for managed object")
  t3_ref = t3;
  l1 = calloc(1, sizeof(Link));
  if (l1 == NULL) RAISE(224, 49, "insufficient memory for object dynamic allocation")
  l1_Refman = MR_new_ref(l1);
  if (l1_Refman == NULL) RAISE(224, 38, "insufficient memory for managed object")
  l1_ref = l1;
  l2 = calloc(1, sizeof(Link));
  if (l2 == NULL) RAISE(226, 49, "insufficient memory for object dynamic allocation")
  l2_Refman = MR_new_ref(l2);
  if (l2_Refman == NULL) RAISE(226, 38, "insufficient memory for managed object")
  l2_ref = l2;
  l3 = calloc(1, sizeof(Link));
  if (l3 == NULL) RAISE(228, 49, "insufficient memory for object dynamic allocation")
  l3_Refman = MR_new_ref(l3);
  if (l3_Refman == NULL) RAISE(228, 38, "insufficient memory for managed object")
  l3_ref = l3;
  if (b1 == NULL) RAISE(231, 27, "used member of empty object")
  if (b1_Refman->value == NULL) RAISE(231, 38, "used member of outdated weak reference")
  MR_dec_ref(b1->link_Refman);
  b1->link_Refman = l1_Refman;
  MR_inc_ref(b1->link_Refman);
  b1->link = l1;
  if (b2 == NULL) RAISE(232, 27, "used member of empty object")
  if (b2_Refman->value == NULL) RAISE(232, 38, "used member of outdated weak reference")
  MR_dec_ref(b2->link_Refman);
  b2->link_Refman = l2_Refman;
  MR_inc_ref(b2->link_Refman);
  b2->link = l2;
  if (t1 == NULL) RAISE(233, 27, "used member of empty object")
  if (t1_Refman->value == NULL) RAISE(233, 38, "used member of outdated weak reference")
  MR_dec_ref(t1->_base.link_Refman);
  t1->_base.link_Refman = l1_Refman;
  MR_inc_ref(t1->_base.link_Refman);
  t1->_base.link = l1;
  if (t2 == NULL) RAISE(234, 27, "used member of empty object")
  if (t2_Refman->value == NULL) RAISE(234, 38, "used member of outdated weak reference")
  MR_dec_ref(t2->_base.link_Refman);
  t2->_base.link_Refman = l2_Refman;
  MR_inc_ref(t2->_base.link_Refman);
  t2->_base.link = l2;
  if (t3 == NULL) RAISE(235, 27, "used member of empty object")
  if (t3_Refman->value == NULL) RAISE(235, 38, "used member of outdated weak reference")
  MR_dec_ref(t3->_base.link_Refman);
  t3->_base.link_Refman = l3_Refman;
  MR_inc_ref(t3->_base.link_Refman);
  t3->_base.link = l3;
  if (l2 == NULL) RAISE(237, 27, "used member of empty object")
  if (l2_Refman->value == NULL) RAISE(237, 38, "used member of outdated weak reference")
  Link_Del(l2->next);
  MR_owner_dec_ref(l2->next_Refman);
  l2->next_Refman = l3_Refman;
  l2->next = l3;
  l3 = NULL;
  l3_Refman = NULL;
  TEST_ASSERT(238, ! (l3 != NULL && l3_Refman->value != NULL))
  if (l1 == NULL) RAISE(239, 27, "used member of empty object")
  if (l1_Refman->value == NULL) RAISE(239, 38, "used member of outdated weak reference")
  Link_Del(l1->next);
  MR_owner_dec_ref(l1->next_Refman);
  l1->next_Refman = l2_Refman;
  l1->next = l2;
  l2 = NULL;
  l2_Refman = NULL;
  TEST_ASSERT(240, ! (l2 != NULL && l2_Refman->value != NULL))
  if (t3 == NULL) RAISE(241, 27, "used member of empty object")
  if (t3_Refman->value == NULL) RAISE(241, 38, "used member of outdated weak reference")
  if (t3->item_Dynamic != NULL) t3->item_Dynamic->_del(t3->item);
  MR_owner_dec_ref(t3->item_Refman);
  t3->item_Refman = b2_Refman;
  t3->item_Dynamic = (Generic_Type_Dynamic*)b2_Dynamic;
  t3->item = b2;
  b2 = NULL;
  b2_Refman = NULL;
  b2_Dynamic = NULL;
  TEST_ASSERT(242, ! (b2 != NULL && b2_Refman->value != NULL))
  if (t2 == NULL) RAISE(243, 27, "used member of empty object")
  if (t2_Refman->value == NULL) RAISE(243, 38, "used member of outdated weak reference")
  if (t2->item_Dynamic != NULL) t2->item_Dynamic->_del(t2->item);
  MR_owner_dec_ref(t2->item_Refman);
  t2->item_Refman = t3_Refman;
  t2->item_Dynamic = (Generic_Type_Dynamic*)&(t3_Dynamic->_base);
  t2->item = &(t3->_base);
  t3 = NULL;
  t3_Refman = NULL;
  t3_Dynamic = NULL;
  TEST_ASSERT(244, ! (t3 != NULL && t3_Refman->value != NULL))
  if (t1 == NULL) RAISE(245, 27, "used member of empty object")
  if (t1_Refman->value == NULL) RAISE(245, 38, "used member of outdated weak reference")
  if (t1->_base.next_Dynamic != NULL) t1->_base.next_Dynamic->_del(t1->_base.next);
  MR_owner_dec_ref(t1->_base.next_Refman);
  t1->_base.next_Refman = t2_Refman;
  t1->_base.next_Dynamic = &(t2_Dynamic->_base);
  t1->_base.next = &(t2->_base);
  t2 = NULL;
  t2_Refman = NULL;
  t2_Dynamic = NULL;
  TEST_ASSERT(246, ! (t2 != NULL && t2_Refman->value != NULL))
  if (t1 == NULL) RAISE(247, 27, "used member of empty object")
  if (t1_Refman->value == NULL) RAISE(247, 38, "used member of outdated weak reference")
  Link_Del(t1->item);
  MR_owner_dec_ref(t1->item_Refman);
  t1->item_Refman = l1_Refman;
  t1->item_Dynamic = &Link_dynamic;
  t1->item = l1;
  l1 = NULL;
  l1_Refman = NULL;
  TEST_ASSERT(248, ! (l1 != NULL && l1_Refman->value != NULL))
  if (b1 == NULL) RAISE(249, 27, "used member of empty object")
  if (b1_Refman->value == NULL) RAISE(249, 38, "used member of outdated weak reference")
  if (b1->next_Dynamic != NULL) b1->next_Dynamic->_del(b1->next);
  MR_owner_dec_ref(b1->next_Refman);
  b1->next_Refman = t1_Refman;
  b1->next_Dynamic = &(t1_Dynamic->_base);
  b1->next = &(t1->_base);
  t1 = NULL;
  t1_Refman = NULL;
  t1_Dynamic = NULL;
  TEST_ASSERT(250, ! (t1 != NULL && t1_Refman->value != NULL))
  TEST_ASSERT(252, ! (deleted_refmans != NULL && deleted_refmans_Refman->value != NULL))
  TEST_ASSERT(253, ! (deleted_links != NULL && deleted_links_Refman->value != NULL))
  TEST_ASSERT(254, ! (deleted_base_links != NULL && deleted_base_links_Refman->value != NULL))
  TEST_ASSERT(255, ! (deleted_top_links != NULL && deleted_top_links_Refman->value != NULL))
  if (b1_Dynamic != NULL) b1_Dynamic->_del(b1);
  MR_owner_dec_ref(b1_Refman);
  b1_Refman = NULL;
  b1_Dynamic = NULL;
  b1 = NULL;
  TEST_ASSERT(257, ! (b1 != NULL && b1_Refman->value != NULL))
  record_delete = false;
  CHECK(260, f_has_ref(b1_ref, &(deleted_base_links), &(deleted_base_links_Refman)) )
  CHECK(261, f_has_ref(t1_ref, &(deleted_top_links), &(deleted_top_links_Refman)) )
  CHECK(262, f_has_ref_rec(t1_ref, &(deleted_base_links), &(deleted_base_links_Refman)) )
  CHECK(263, f_has_ref(t2_ref, &(deleted_top_links), &(deleted_top_links_Refman)) )
  CHECK(264, f_has_ref_rec(t2_ref, &(deleted_base_links), &(deleted_base_links_Refman)) )
  CHECK(265, f_has_ref(t3_ref, &(deleted_top_links), &(deleted_top_links_Refman)) )
  CHECK(266, f_has_ref_rec(t3_ref, &(deleted_base_links), &(deleted_base_links_Refman)) )
  CHECK(267, f_has_ref(b2_ref, &(deleted_base_links), &(deleted_base_links_Refman)) )
  CHECK(268, f_has_ref(l1_ref, &(deleted_links), &(deleted_links_Refman)) )
  CHECK(269, f_has_ref(l2_ref, &(deleted_links), &(deleted_links_Refman)) )
  CHECK(270, f_has_ref(l3_ref, &(deleted_links), &(deleted_links_Refman)) )
  TEST_ASSERT(272, ! (deleted_refmans != NULL && deleted_refmans_Refman->value != NULL))
  TEST_ASSERT(273, ! (deleted_links != NULL && deleted_links_Refman->value != NULL))
  TEST_ASSERT(274, ! (deleted_base_links != NULL && deleted_base_links_Refman->value != NULL))
  TEST_ASSERT(275, ! (deleted_top_links != NULL && deleted_top_links_Refman->value != NULL))
MR_cleanup:
  Link_Del(l3);
  MR_owner_dec_ref(l3_Refman);
  Link_Del(l2);
  MR_owner_dec_ref(l2_Refman);
  Link_Del(l1);
  MR_owner_dec_ref(l1_Refman);
  if (t3_Dynamic != NULL) t3_Dynamic->_base._del(t3);
  MR_owner_dec_ref(t3_Refman);
  if (t2_Dynamic != NULL) t2_Dynamic->_base._del(t2);
  MR_owner_dec_ref(t2_Refman);
  if (t1_Dynamic != NULL) t1_Dynamic->_base._del(t1);
  MR_owner_dec_ref(t1_Refman);
  if (b2_Dynamic != NULL) b2_Dynamic->_del(b2);
  MR_owner_dec_ref(b2_Refman);
  if (b1_Dynamic != NULL) b1_Dynamic->_del(b1);
  MR_owner_dec_ref(b1_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "f-raise-message"
Returncode f_raise_message(void) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(279, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "tested message";
  USER_RAISE(279, aux_String_0, aux_String_0_Refman)
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "f-ignore-and-raise"
Returncode f_ignore_and_raise(void) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; break
    CHECK(283, f_raise_message() )

#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  } while (false);
  --MR_trace_ignore_count;
  MR_err = OK;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(284, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "ignore and raise";
  USER_RAISE(284, aux_String_0, aux_String_0_Refman)
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "f-failed-assert"
Returncode f_failed_assert(void) {
  Returncode MR_err = OK;
  TEST_ASSERT(287, 1 == 2)
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "f-good-assert-error"
Returncode f_good_assert_error(void) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(290, f_raise_message() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(290, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(291, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 18;
  aux_String_0_Var.length = 17;
  aux_String_0_Var.values = "good assert error";
  USER_RAISE(291, aux_String_0, aux_String_0_Refman)
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "f-failed-assert-error"
Returncode f_failed_assert_error(void) {
  Returncode MR_err = OK;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(294, f_test_void() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(294, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "f-wrong-message-assert-error"
Returncode f_wrong_message_assert_error(void) {
  Returncode MR_err = OK;
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "wrong message";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(297, f_raise_message() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(297, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(297)
  }
  MR_expected_error = MR_expected_error_prev;}
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "test-assert-error-message"
Returncode test_assert_error_message(void) {
  Returncode MR_err = OK;
  Returncode (*fun)(void) = NULL;
  BaseType base_var_Var = {0};
  BaseType* base_var = NULL;
  Ref_Manager* base_var_Refman = NULL;
  BaseType_Dynamic* base_var_Dynamic = &BaseType_dynamic;
  BaseType* base_user = NULL;
  Ref_Manager* base_user_Refman = NULL;
  BaseType_Dynamic* base_user_Dynamic = NULL;
  Array* arr = NULL;
  Ref_Manager* arr_Refman = NULL;
  Array* arr2 = NULL;
  Ref_Manager* arr2_Refman = NULL;
  TopType* top = NULL;
  Ref_Manager* top_Refman = NULL;
  TopType_Dynamic* top_Dynamic = NULL;
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "tested message";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(300, f_raise_message() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(300, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(300)
  }
  MR_expected_error = MR_expected_error_prev;}
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "ignore and raise";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(301, f_ignore_and_raise() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(301, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(301)
  }
  MR_expected_error = MR_expected_error_prev;}
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "condition is not true";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(302, f_failed_assert() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(302, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(302)
  }
  MR_expected_error = MR_expected_error_prev;}
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "good assert error";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(303, f_good_assert_error() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(303, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(303)
  }
  MR_expected_error = MR_expected_error_prev;}
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "error not raised";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(304, f_failed_assert_error() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(304, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(304)
  }
  MR_expected_error = MR_expected_error_prev;}
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(305, f_wrong_message_assert_error() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(305, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "empty function called";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (fun == NULL) RAISE(307, 21, "empty function called")
    CHECK(307, fun() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(307, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(307)
  }
  MR_expected_error = MR_expected_error_prev;}
  base_var = &base_var_Var;
  base_var_Refman = MR_new_ref(base_var);
  if (base_var_Refman == NULL) RAISE(308, 38, "insufficient memory for managed object")
  CHECK(308, BaseType_new(base_var, base_var_Refman, base_var_Dynamic) )
  base_user = base_var;
  base_user_Refman = base_var_Refman;
  MR_inc_ref(base_user_Refman);
  base_user_Dynamic = base_var_Dynamic;
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "non empty base class given as output argument";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (base_user != NULL) RAISE(310, 45, "non empty base class given as output argument")
    CHECK(310, test_mid_out((void*)&(base_user), &(base_user_Refman), (void*)&(base_user_Dynamic)) )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(310, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(310)
  }
  MR_expected_error = MR_expected_error_prev;}
  arr = MR_new_array(2, sizeof(Int));
  if (arr == NULL) RAISE(312, 49, "insufficient memory for object dynamic allocation")
  arr_Refman = MR_new_ref(arr);
  if (arr_Refman == NULL) RAISE(312, 38, "insufficient memory for managed object")
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "slice index out of bounds";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (arr == NULL) RAISE(313, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(313, 40, "outdated weak reference used as sequence")
    if ((6) < 0 || (6) >= (arr)->length) RAISE(313, 25, "slice index out of bounds")
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(313, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(313)
  }
  MR_expected_error = MR_expected_error_prev;}
  arr2 = arr;
  arr2_Refman = arr_Refman;
  MR_inc_ref(arr2_Refman);
  MR_owner_dec_ref(arr_Refman);
  arr_Refman = NULL;
  arr = NULL;
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "used member of empty object";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (arr == NULL) RAISE(316, 27, "used member of empty object")
    if (arr_Refman->value == NULL) RAISE(316, 38, "used member of outdated weak reference")
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(316, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(316)
  }
  MR_expected_error = MR_expected_error_prev;}
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "used member of outdated weak reference";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (arr2 == NULL) RAISE(317, 27, "used member of empty object")
    if (arr2_Refman->value == NULL) RAISE(317, 38, "used member of outdated weak reference")
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(317, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(317)
  }
  MR_expected_error = MR_expected_error_prev;}
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "empty object used as sequence";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (arr == NULL) RAISE(318, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(318, 40, "outdated weak reference used as sequence")
    if ((0) < 0 || (0) >= (arr)->length) RAISE(318, 25, "slice index out of bounds")
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(318, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(318)
  }
  MR_expected_error = MR_expected_error_prev;}
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "outdated weak reference used as sequence";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (arr2 == NULL) RAISE(319, 29, "empty object used as sequence")
    if (arr2_Refman->value == NULL) RAISE(319, 40, "outdated weak reference used as sequence")
    if ((0) < 0 || (0) >= (arr2)->length) RAISE(319, 25, "slice index out of bounds")
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(319, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(319)
  }
  MR_expected_error = MR_expected_error_prev;}
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "dynamic call of empty object";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (top_Dynamic == NULL) RAISE(321, 28, "dynamic call of empty object")
    CHECK(321, top_Dynamic->_base._base.meth2(&(top->_base._base), top_Refman, &(top_Dynamic->_base._base)) )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(321, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(321)
  }
  MR_expected_error = MR_expected_error_prev;}
MR_cleanup:
  MR_dec_ref(top_Refman);
  MR_dec_ref(arr2_Refman);
  MR_owner_dec_ref(arr_Refman);
  MR_dec_ref(base_user_Refman);
  MR_dec_ref(base_var_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

USER_MAIN_HEADER {
  Bool MR_success = true;
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
#define MR_FILE_NAME "tests/integration-test1.4.mr"
  deleted_refmans = NULL;
  deleted_refmans_Refman = NULL;
#undef MR_FILE_NAME
#undef MR_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  RUN_TEST(test_func);
  RUN_TEST(test_another);
  RUN_TEST(test_native);
  RUN_TEST(test_dynamic_type_parameters);
  RUN_TEST(test_simple_delete);
  RUN_TEST(test_complex_delete);
  RUN_TEST(test_assert_error_message);
  return MR_success? OK : FAIL;
}

TEST_MAIN_FUNC
