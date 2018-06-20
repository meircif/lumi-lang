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

typedef struct integration_M_BaseType integration_M_BaseType;

typedef struct integration_M_BaseType_Dynamic integration_M_BaseType_Dynamic;

typedef struct covered_M_MiddleType covered_M_MiddleType;

typedef struct covered_M_MiddleType_Dynamic covered_M_MiddleType_Dynamic;

typedef struct integration_M_TopType integration_M_TopType;

typedef struct integration_M_TopType_Dynamic integration_M_TopType_Dynamic;

typedef void* Native;

typedef struct integration_M_Link integration_M_Link;

typedef struct integration_M_BaseLink integration_M_BaseLink;

typedef struct integration_M_BaseLink_Dynamic integration_M_BaseLink_Dynamic;

typedef struct integration_M_TopLink integration_M_TopLink;

typedef struct integration_M_TopLink_Dynamic integration_M_TopLink_Dynamic;

typedef struct integration_M_RefNode integration_M_RefNode;


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

struct integration_M_BaseType {
  Int num_base;
  covered_M_MiddleType* base_mid_ref;
  Ref_Manager* base_mid_ref_Refman;
  covered_M_MiddleType_Dynamic* base_mid_ref_Dynamic;
  integration_M_TopType* base_top_ref;
  Ref_Manager* base_top_ref_Refman;
  integration_M_TopType_Dynamic* base_top_ref_Dynamic;
};

struct integration_M_BaseType_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth0)(integration_M_BaseType* self, Ref_Manager* self_Refman, integration_M_BaseType_Dynamic* self_Dynamic);
  Returncode (*meth1)(integration_M_BaseType* self, Ref_Manager* self_Refman, integration_M_BaseType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);
  Returncode (*meth2)(integration_M_BaseType* self, Ref_Manager* self_Refman, integration_M_BaseType_Dynamic* self_Dynamic);
  Returncode (*meth3)(integration_M_BaseType* self, Ref_Manager* self_Refman, integration_M_BaseType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);
};

struct covered_M_MiddleType {
  integration_M_BaseType _base;
  Int num_mid;
  integration_M_BaseType* mid_base_ref;
  Ref_Manager* mid_base_ref_Refman;
  integration_M_BaseType_Dynamic* mid_base_ref_Dynamic;
  integration_M_TopType* mid_top_ref;
  Ref_Manager* mid_top_ref_Refman;
  integration_M_TopType_Dynamic* mid_top_ref_Dynamic;
};

struct covered_M_MiddleType_Dynamic {
  integration_M_BaseType_Dynamic _base;
  Returncode (*meth4)(covered_M_MiddleType* self, Ref_Manager* self_Refman, covered_M_MiddleType_Dynamic* self_Dynamic);
  Returncode (*meth5)(covered_M_MiddleType* self, Ref_Manager* self_Refman, covered_M_MiddleType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);
};

struct integration_M_TopType {
  covered_M_MiddleType _base;
  Int num_top;
  integration_M_BaseType* top_base_ref;
  Ref_Manager* top_base_ref_Refman;
  integration_M_BaseType_Dynamic* top_base_ref_Dynamic;
  covered_M_MiddleType* top_mid_ref;
  Ref_Manager* top_mid_ref_Refman;
  covered_M_MiddleType_Dynamic* top_mid_ref_Dynamic;
};

struct integration_M_TopType_Dynamic {
  covered_M_MiddleType_Dynamic _base;
  Returncode (*meth6)(integration_M_TopType* self, Ref_Manager* self_Refman, integration_M_TopType_Dynamic* self_Dynamic);
};

struct integration_M_Link {
  integration_M_Link* next;
  Ref_Manager* next_Refman;
};

struct integration_M_BaseLink {
  integration_M_BaseLink* next;
  Ref_Manager* next_Refman;
  integration_M_BaseLink_Dynamic* next_Dynamic;
  integration_M_Link* link;
  Ref_Manager* link_Refman;
};

struct integration_M_BaseLink_Dynamic {
  Dynamic_Del _del;
  Returncode (*m_meth)(integration_M_BaseLink* self, Ref_Manager* self_Refman, integration_M_BaseLink_Dynamic* self_Dynamic);
};

struct integration_M_TopLink {
  integration_M_BaseLink _base;
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};

struct integration_M_TopLink_Dynamic {
  integration_M_BaseLink_Dynamic _base;
};

struct integration_M_RefNode {
  integration_M_RefNode* next;
  Ref_Manager* next_Refman;
  Ref ref;
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

Returncode integration_M_BaseType_new(integration_M_BaseType* self, Ref_Manager* self_Refman, integration_M_BaseType_Dynamic* self_Dynamic);

Returncode integration_M_BaseType_meth0(integration_M_BaseType* self, Ref_Manager* self_Refman, integration_M_BaseType_Dynamic* self_Dynamic);

Returncode integration_M_BaseType_meth1(integration_M_BaseType* self, Ref_Manager* self_Refman, integration_M_BaseType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);

Returncode integration_M_BaseType_meth2(integration_M_BaseType* self, Ref_Manager* self_Refman, integration_M_BaseType_Dynamic* self_Dynamic);

Returncode integration_M_BaseType_meth3(integration_M_BaseType* self, Ref_Manager* self_Refman, integration_M_BaseType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);

void integration_M_BaseType_Del(integration_M_BaseType* self);

Returncode covered_M_MiddleType_new(covered_M_MiddleType* self, Ref_Manager* self_Refman, covered_M_MiddleType_Dynamic* self_Dynamic);

Returncode covered_M_MiddleType_meth1(covered_M_MiddleType* self, Ref_Manager* self_Refman, covered_M_MiddleType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);

Returncode covered_M_MiddleType_meth2(covered_M_MiddleType* self, Ref_Manager* self_Refman, covered_M_MiddleType_Dynamic* self_Dynamic);

Returncode covered_M_MiddleType_meth4(covered_M_MiddleType* self, Ref_Manager* self_Refman, covered_M_MiddleType_Dynamic* self_Dynamic);

Returncode covered_M_MiddleType_meth5(covered_M_MiddleType* self, Ref_Manager* self_Refman, covered_M_MiddleType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);

void covered_M_MiddleType_Del(covered_M_MiddleType* self);

Returncode integration_M_TopType_new(integration_M_TopType* self, Ref_Manager* self_Refman, integration_M_TopType_Dynamic* self_Dynamic);

Returncode integration_M_TopType_meth2(integration_M_TopType* self, Ref_Manager* self_Refman, integration_M_TopType_Dynamic* self_Dynamic);

Returncode integration_M_TopType_meth3(integration_M_TopType* self, Ref_Manager* self_Refman, integration_M_TopType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);

Returncode integration_M_TopType_meth5(integration_M_TopType* self, Ref_Manager* self_Refman, integration_M_TopType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman);

Returncode integration_M_TopType_meth6(integration_M_TopType* self, Ref_Manager* self_Refman, integration_M_TopType_Dynamic* self_Dynamic);

void integration_M_TopType_Del(integration_M_TopType* self);

void integration_M_Link_Del(integration_M_Link* self);

Returncode integration_M_BaseLink_m_meth(integration_M_BaseLink* self, Ref_Manager* self_Refman, integration_M_BaseLink_Dynamic* self_Dynamic);

void integration_M_BaseLink_Del(integration_M_BaseLink* self);

void integration_M_TopLink_Del(integration_M_TopLink* self);

Returncode integration_M_RefNode_new(integration_M_RefNode* self, Ref_Manager* self_Refman, Ref ref, integration_M_RefNode* next, Ref_Manager* next_Refman);

void integration_M_RefNode_Del(integration_M_RefNode* self);


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

Returncode integration_M_test_mid_out(covered_M_MiddleType** mt, Ref_Manager** mt_Refman, covered_M_MiddleType_Dynamic** mt_Dynamic);

Returncode integration_M_TestStruct_get_Mock(integration_M_TestStruct* self, Ref_Manager* self_Refman, Int* x, String** s, Ref_Manager** s_Refman);

Returncode integration_M_f_test_int2str_Mock(Int x, String** s, Ref_Manager** s_Refman);

Returncode integration_M_TestClass_dynamic_meth_Mock(integration_M_TestClass* self, Ref_Manager* self_Refman, integration_M_TestClass_Dynamic* self_Dynamic);

Returncode integration_M_test_func(void);

Returncode integration_M_test_another(void);

Returncode external(Int i, String* s, Int* io, Native* n);

Returncode external2(Native n, Bool* b);

Returncode integration_M_test_native(void);

Returncode integration_M_test_dynamic_type_parameters(void);

Returncode delete_Mock(Ref self);

Returncode integration_M_Link_MockDel(Ref self);

Returncode integration_M_BaseLink_MockDel(Ref self);

Returncode integration_M_TopLink_MockDel(Ref self);

Returncode integration_M_f_remove_obj(integration_M_Link* b, Ref_Manager* b_Refman);

Returncode integration_M_test_simple_delete(void);

Returncode integration_M_f_has_ref(Ref ref, integration_M_RefNode** node, Ref_Manager** node_Refman);

Returncode integration_M_f_has_ref_rec(Ref ref, integration_M_RefNode** node, Ref_Manager** node_Refman);

Returncode integration_M_test_complex_delete(void);

Returncode integration_M_f_raise_message(void);

Returncode integration_M_f_ignore_and_raise(void);

Returncode integration_M_f_failed_assert(void);

Returncode integration_M_f_good_assert_error(void);

Returncode integration_M_f_failed_assert_error(void);

Returncode integration_M_f_wrong_message_assert_error(void);

Returncode new_Mock(Bool* alloc_success);

Returncode integration_M_f_alloc(void);

Returncode integration_M_test_assert_error_message(void);

Returncode Sys_println_Mock(Sys* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman);

Returncode integration_M_test_cover_all(void);

Returncode integration_M_test_constants(void);


/* types global variables */

Generic_Type_Dynamic integration_M_TestStruct_dynamic = {(Dynamic_Del)integration_M_TestStruct_Del};

integration_M_TestClass_Dynamic integration_M_TestClass_dynamic = {(Dynamic_Del)integration_M_TestClass_Del, integration_M_TestClass_dynamic_meth_Mock};

Generic_Type_Dynamic integration_M_Data_dynamic = {(Dynamic_Del)integration_M_Data_Del};

Generic_Type_Dynamic integration_M_Dataset_dynamic = {(Dynamic_Del)integration_M_Dataset_Del};

Generic_Type_Dynamic integration_M_MidData_dynamic = {(Dynamic_Del)integration_M_MidData_Del};

Generic_Type_Dynamic integration_M_TopData_dynamic = {(Dynamic_Del)integration_M_TopData_Del};

Generic_Type_Dynamic integration_M_Container_dynamic = {(Dynamic_Del)integration_M_Container_Del};

Generic_Type_Dynamic integration_M_ContainerIterator_dynamic = {(Dynamic_Del)integration_M_ContainerIterator_Del};

integration_M_ComplexField_Dynamic integration_M_ComplexField_dynamic = {(Dynamic_Del)integration_M_ComplexField_Del, integration_M_ComplexField_meth};

Generic_Type_Dynamic integration_M_HasComplexField_dynamic = {(Dynamic_Del)integration_M_HasComplexField_Del};

integration_M_BaseType_Dynamic integration_M_BaseType_dynamic = {(Dynamic_Del)integration_M_BaseType_Del, integration_M_BaseType_meth0, integration_M_BaseType_meth1, integration_M_BaseType_meth2, integration_M_BaseType_meth3};

covered_M_MiddleType_Dynamic covered_M_MiddleType_dynamic = {{(Dynamic_Del)covered_M_MiddleType_Del, integration_M_BaseType_meth0, (Func)covered_M_MiddleType_meth1, (Func)covered_M_MiddleType_meth2, integration_M_BaseType_meth3}, covered_M_MiddleType_meth4, covered_M_MiddleType_meth5};

integration_M_TopType_Dynamic integration_M_TopType_dynamic = {{{(Dynamic_Del)integration_M_TopType_Del, integration_M_BaseType_meth0, (Func)covered_M_MiddleType_meth1, (Func)integration_M_TopType_meth2, (Func)integration_M_TopType_meth3}, covered_M_MiddleType_meth4, (Func)integration_M_TopType_meth5}, integration_M_TopType_meth6};

Generic_Type_Dynamic integration_M_Link_dynamic = {(Dynamic_Del)integration_M_Link_Del};

integration_M_BaseLink_Dynamic integration_M_BaseLink_dynamic = {(Dynamic_Del)integration_M_BaseLink_Del, integration_M_BaseLink_m_meth};

integration_M_TopLink_Dynamic integration_M_TopLink_dynamic = {{(Dynamic_Del)integration_M_TopLink_Del, integration_M_BaseLink_m_meth}};

Generic_Type_Dynamic integration_M_RefNode_dynamic = {(Dynamic_Del)integration_M_RefNode_Del};


/* global variables */

Int integration_M_global_int = 0;

String* integration_M_global_string = NULL;
Ref_Manager* integration_M_global_string_Refman = NULL;

Int integration_M_int_arr_Values[integration_M_TestEnum_length + integration_M_LENGTH] = {0};
Array integration_M_int_arr_Var = {integration_M_TestEnum_length + integration_M_LENGTH, NULL};
Array* integration_M_int_arr = NULL;
Ref_Manager* integration_M_int_arr_Refman = NULL;

extern Int external_int;

Bool integration_M_record_delete = 0;

integration_M_RefNode* integration_M_deleted_links = NULL;
Ref_Manager* integration_M_deleted_links_Refman = NULL;

integration_M_RefNode* integration_M_deleted_base_links = NULL;
Ref_Manager* integration_M_deleted_base_links_Refman = NULL;

integration_M_RefNode* integration_M_deleted_top_links = NULL;
Ref_Manager* integration_M_deleted_top_links_Refman = NULL;

integration_M_RefNode* integration_M_deleted_refmans = NULL;
Ref_Manager* integration_M_deleted_refmans_Refman = NULL;

Int integration_M_new_fail_countdown = 0;

int LUMI_file0_line_count[31] = {
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0,-1,-1, 0, 0,-1,-1, 0, 0,-1,
  -1, 0,-1,-1, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
  {"tests/integration-test2.4.lm", 31, LUMI_file0_line_count}
};


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
  if (self == NULL) RAISE(212, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(212, 38, "used member of outdated weak reference")
  self->num = x;
  if (self == NULL) RAISE(213, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(213, 38, "used member of outdated weak reference")
  aux_Ref_Manager = self->text_Refman;
  self->text_Refman = s_Refman;
  LUMI_inc_ref(self->text_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  self->text = s;
  if (x < 0) {
      aux_TestStruct_0 = LUMI_alloc(sizeof(integration_M_TestStruct));
      if (aux_TestStruct_0 == NULL) RAISE(215, 49, "insufficient memory for object dynamic allocation")
      aux_TestStruct_0_Refman = LUMI_new_ref(aux_TestStruct_0);
      if (aux_TestStruct_0_Refman == NULL) RAISE(215, 38, "insufficient memory for managed object")
      LUMI_err = integration_M_TestStruct_new(aux_TestStruct_0, aux_TestStruct_0_Refman, x + 1, s, s_Refman);
      CHECK(215)
      if (self == NULL) RAISE(215, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(215, 38, "used member of outdated weak reference")
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
  if (self == NULL) RAISE(222, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(222, 38, "used member of outdated weak reference")
  *x = self->num;
  if (self == NULL) RAISE(223, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(223, 38, "used member of outdated weak reference")
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
  if (self == NULL) RAISE(226, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(226, 38, "used member of outdated weak reference")
  LUMI_err = Sys_println_Mock(sys, sys_Refman, self->text, self->text_Refman);
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
  LUMI_err = Sys_println_Mock(sys, sys_Refman, self->text, self->text_Refman);
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
  if (self == NULL) RAISE(377, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(377, 38, "used member of outdated weak reference")
  aux_Ref_Manager = self->item_Refman;
  self->item_Refman = x_Refman;
  self->item_Dynamic = x_Dynamic;
  LUMI_inc_ref(self->item_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  self->item = x;
  if (self == NULL) RAISE(378, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(378, 38, "used member of outdated weak reference")
  aux_Ref_Manager = self->arr_Refman;
  self->arr_Refman = arr_Refman;
  LUMI_inc_ref(self->arr_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  self->arr = arr;
  d = LUMI_alloc(sizeof(integration_M_Data));
  if (d == NULL) RAISE(379, 49, "insufficient memory for object dynamic allocation")
  d_Refman = LUMI_new_ref(d);
  if (d_Refman == NULL) RAISE(379, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(380, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(380, 38, "used member of outdated weak reference")
  if (d == NULL) RAISE(380, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(380, 38, "used member of outdated weak reference")
  aux_Ref_Manager = d->item_Refman;
  d->item_Refman = self->item_Refman;
  d->item_Dynamic = self->item_Dynamic;
  LUMI_inc_ref(d->item_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  d->item = self->item;
  if (d == NULL) RAISE(381, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(381, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(381, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(381, 38, "used member of outdated weak reference")
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
  if (self == NULL) RAISE(384, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(384, 38, "used member of outdated weak reference")
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
  if (self == NULL) RAISE(459, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(459, 38, "used member of outdated weak reference")
  aux_Ref_Manager = self->value_Refman;
  self->value_Refman = value_Refman;
  self->value_Dynamic = value_Dynamic;
  LUMI_inc_ref(self->value_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  self->value = value;
  if (self == NULL) RAISE(460, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(460, 38, "used member of outdated weak reference")
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
  if (self == NULL) RAISE(463, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(463, 38, "used member of outdated weak reference")
  aux_ContainerIterator_0 = LUMI_alloc(sizeof(integration_M_ContainerIterator));
  if (aux_ContainerIterator_0 == NULL) RAISE(463, 49, "insufficient memory for object dynamic allocation")
  aux_ContainerIterator_0_Refman = LUMI_new_ref(aux_ContainerIterator_0);
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
  if (self == NULL) RAISE(469, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(469, 38, "used member of outdated weak reference")
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
  if (self == NULL) RAISE(472, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(472, 38, "used member of outdated weak reference")
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
  if (self == NULL) RAISE(475, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(475, 38, "used member of outdated weak reference")
  if (self->curr == NULL) RAISE(475, 27, "used member of empty object")
  if (self->curr_Refman->value == NULL) RAISE(475, 38, "used member of outdated weak reference")
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
  if (self == NULL) RAISE(478, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(478, 38, "used member of outdated weak reference")
  if (self->curr == NULL) RAISE(478, 27, "used member of empty object")
  if (self->curr_Refman->value == NULL) RAISE(478, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(478, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(478, 38, "used member of outdated weak reference")
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
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
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
  if (self == NULL) RAISE(543, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(543, 38, "used member of outdated weak reference")
  x = &(self->x);
  x_Refman = self_Refman;
  LUMI_inc_ref(x_Refman);
  x_Dynamic = &integration_M_ComplexField_dynamic;
  if (self == NULL) RAISE(544, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(544, 38, "used member of outdated weak reference")
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
  if (self == NULL) RAISE(546, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(546, 38, "used member of outdated weak reference")
  LUMI_err = integration_M_ComplexField_meth(&(self->x), self_Refman, &integration_M_ComplexField_dynamic);
  CHECK(546)
  if (self == NULL) RAISE(547, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(547, 38, "used member of outdated weak reference")
  LUMI_err = integration_M_ComplexField_meth(&(self->x), self_Refman, &integration_M_ComplexField_dynamic);
  CHECK(547)
  if (self == NULL) RAISE(548, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(548, 38, "used member of outdated weak reference")
  x2 = self->x.x;
  x2_Refman = self->x.x_Refman;
  LUMI_inc_ref(x2_Refman);
  x2_Dynamic = self->x.x_Dynamic;
  if (self == NULL) RAISE(549, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(549, 38, "used member of outdated weak reference")
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
  if (self == NULL) RAISE(551, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(551, 38, "used member of outdated weak reference")
  if (self->x.x_Dynamic == NULL) RAISE(551, 28, "dynamic call of empty object")
  LUMI_err = self->x.x_Dynamic->meth(self->x.x, self->x.x_Refman, self->x.x_Dynamic);
  CHECK(551)
  if (self == NULL) RAISE(552, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(552, 38, "used member of outdated weak reference")
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

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "BaseType.new"
Returncode integration_M_BaseType_new(integration_M_BaseType* self, Ref_Manager* self_Refman, integration_M_BaseType_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(50, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(50, 38, "used member of outdated weak reference")
  self->num_base = 1;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "BaseType.meth0"
Returncode integration_M_BaseType_meth0(integration_M_BaseType* self, Ref_Manager* self_Refman, integration_M_BaseType_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(53, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "BaseType.meth0";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(53)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "BaseType.meth1"
Returncode integration_M_BaseType_meth1(integration_M_BaseType* self, Ref_Manager* self_Refman, integration_M_BaseType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(s_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(56, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "BaseType.meth1";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(56)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(s_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "BaseType.meth2"
Returncode integration_M_BaseType_meth2(integration_M_BaseType* self, Ref_Manager* self_Refman, integration_M_BaseType_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(59, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "BaseType.meth2";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(59)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "BaseType.meth3"
Returncode integration_M_BaseType_meth3(integration_M_BaseType* self, Ref_Manager* self_Refman, integration_M_BaseType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(s_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(62, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "BaseType.meth3";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(62)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(s_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void integration_M_BaseType_Del(integration_M_BaseType* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->base_top_ref_Refman);
  LUMI_dec_ref(self->base_mid_ref_Refman);
}

#define LUMI_FILE_NAME "tests/integration-test2.4.lm"
#define LUMI_FUNC_NAME "MiddleType.new"
Returncode covered_M_MiddleType_new(covered_M_MiddleType* self, Ref_Manager* self_Refman, covered_M_MiddleType_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  ++LUMI_file_coverage[0].line_count[14];
  LUMI_err = integration_M_BaseType_new(&(self->_base), self_Refman, &(self_Dynamic->_base));
  CHECK(14)
  ++LUMI_file_coverage[0].line_count[15];
  if (self == NULL) RAISE(15, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(15, 38, "used member of outdated weak reference")
  self->num_mid = 2;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test2.4.lm"
#define LUMI_FUNC_NAME "MiddleType.meth1"
Returncode covered_M_MiddleType_meth1(covered_M_MiddleType* self, Ref_Manager* self_Refman, covered_M_MiddleType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(s_Refman);
  ++LUMI_file_coverage[0].line_count[18];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(18, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "MiddleType.meth1";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(18)
  ++LUMI_file_coverage[0].line_count[19];
  LUMI_err = integration_M_BaseType_meth1(&(self->_base), self_Refman, &(self_Dynamic->_base), n, s, s_Refman);
  CHECK(19)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(s_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test2.4.lm"
#define LUMI_FUNC_NAME "MiddleType.meth2"
Returncode covered_M_MiddleType_meth2(covered_M_MiddleType* self, Ref_Manager* self_Refman, covered_M_MiddleType_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  ++LUMI_file_coverage[0].line_count[22];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(22, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "MiddleType.meth2";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(22)
  ++LUMI_file_coverage[0].line_count[23];
  LUMI_err = integration_M_BaseType_meth2(&(self->_base), self_Refman, &(self_Dynamic->_base));
  CHECK(23)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test2.4.lm"
#define LUMI_FUNC_NAME "MiddleType.meth4"
Returncode covered_M_MiddleType_meth4(covered_M_MiddleType* self, Ref_Manager* self_Refman, covered_M_MiddleType_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  ++LUMI_file_coverage[0].line_count[26];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(26, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "MiddleType.meth4";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(26)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test2.4.lm"
#define LUMI_FUNC_NAME "MiddleType.meth5"
Returncode covered_M_MiddleType_meth5(covered_M_MiddleType* self, Ref_Manager* self_Refman, covered_M_MiddleType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(s_Refman);
  ++LUMI_file_coverage[0].line_count[29];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(29, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "MiddleType.meth5";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(29)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(s_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void covered_M_MiddleType_Del(covered_M_MiddleType* self) {
  if (self == NULL) return;
  integration_M_BaseType_Del(&(self->_base));
  LUMI_dec_ref(self->mid_top_ref_Refman);
  LUMI_dec_ref(self->mid_base_ref_Refman);
}

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "TopType.new"
Returncode integration_M_TopType_new(integration_M_TopType* self, Ref_Manager* self_Refman, integration_M_TopType_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_err = covered_M_MiddleType_new(&(self->_base), self_Refman, &(self_Dynamic->_base));
  CHECK(14)
  if (self == NULL) RAISE(15, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(15, 38, "used member of outdated weak reference")
  self->num_top = 3;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "TopType.meth2"
Returncode integration_M_TopType_meth2(integration_M_TopType* self, Ref_Manager* self_Refman, integration_M_TopType_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(19, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 14;
  aux_String_0_Var.length = 13;
  aux_String_0_Var.values = "TopType.meth2";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(19)
  LUMI_err = covered_M_MiddleType_meth2(&(self->_base), self_Refman, &(self_Dynamic->_base));
  CHECK(20)
  LUMI_err = covered_M_MiddleType_meth2(&(self->_base), self_Refman, &(self_Dynamic->_base));
  CHECK(21)
  LUMI_err = integration_M_BaseType_meth2(&(self->_base._base), self_Refman, &(self_Dynamic->_base._base));
  CHECK(22)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "TopType.meth3"
Returncode integration_M_TopType_meth3(integration_M_TopType* self, Ref_Manager* self_Refman, integration_M_TopType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(s_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(25, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 14;
  aux_String_0_Var.length = 13;
  aux_String_0_Var.values = "TopType.meth3";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(25)
  LUMI_err = integration_M_BaseType_meth3(&(self->_base._base), self_Refman, &(self_Dynamic->_base._base), n, s, s_Refman);
  CHECK(26)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(s_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "TopType.meth5"
Returncode integration_M_TopType_meth5(integration_M_TopType* self, Ref_Manager* self_Refman, integration_M_TopType_Dynamic* self_Dynamic, Int n, String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(s_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(29, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 14;
  aux_String_0_Var.length = 13;
  aux_String_0_Var.values = "TopType.meth5";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(29)
  LUMI_err = covered_M_MiddleType_meth5(&(self->_base), self_Refman, &(self_Dynamic->_base), n, s, s_Refman);
  CHECK(30)
  LUMI_err = covered_M_MiddleType_meth1(NULL, NULL, NULL, n, s, s_Refman);
  CHECK(31)
  LUMI_err = integration_M_BaseType_meth1(NULL, NULL, NULL, n, s, s_Refman);
  CHECK(32)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(s_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "TopType.meth6"
Returncode integration_M_TopType_meth6(integration_M_TopType* self, Ref_Manager* self_Refman, integration_M_TopType_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  covered_M_MiddleType* mt = NULL;
  Ref_Manager* mt_Refman = NULL;
  covered_M_MiddleType_Dynamic* mt_Dynamic = NULL;
  integration_M_BaseType* bt = NULL;
  Ref_Manager* bt_Refman = NULL;
  integration_M_BaseType_Dynamic* bt_Dynamic = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(self_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(35, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 14;
  aux_String_0_Var.length = 13;
  aux_String_0_Var.values = "TopType.meth6";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(35)
  if (self == NULL) RAISE(36, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(36, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(36, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(36, 38, "used member of outdated weak reference")
  self->_base.num_mid = self->_base._base.num_base;
  if (self == NULL) RAISE(37, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(37, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(37, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(37, 38, "used member of outdated weak reference")
  aux_Ref_Manager = self->top_base_ref_Refman;
  self->top_base_ref_Refman = self->top_mid_ref_Refman;
  self->top_base_ref_Dynamic = &(self->top_mid_ref_Dynamic->_base);
  LUMI_inc_ref(self->top_base_ref_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  self->top_base_ref = &(self->top_mid_ref->_base);
  if (self == NULL) RAISE(38, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(38, 38, "used member of outdated weak reference")
  aux_Ref_Manager = self->top_base_ref_Refman;
  self->top_base_ref_Refman = self_Refman;
  self->top_base_ref_Dynamic = &(self_Dynamic->_base._base);
  LUMI_inc_ref(self->top_base_ref_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  self->top_base_ref = &(self->_base._base);
  mt = &(self->_base);
  mt_Refman = self_Refman;
  LUMI_inc_ref(mt_Refman);
  mt_Dynamic = &(self_Dynamic->_base);
  bt = &(mt->_base);
  bt_Refman = mt_Refman;
  LUMI_inc_ref(bt_Refman);
  bt_Dynamic = &(mt_Dynamic->_base);
  if (bt != NULL) RAISE(41, 45, "non empty base class given as output argument")
  LUMI_err = integration_M_test_mid_out((void*)&(bt), &(bt_Refman), (void*)&(bt_Dynamic));
  CHECK(41)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(bt_Refman);
  LUMI_dec_ref(mt_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void integration_M_TopType_Del(integration_M_TopType* self) {
  if (self == NULL) return;
  covered_M_MiddleType_Del(&(self->_base));
  LUMI_dec_ref(self->top_mid_ref_Refman);
  LUMI_dec_ref(self->top_base_ref_Refman);
}

void integration_M_Link_Del(integration_M_Link* self) {
  if (self == NULL) return;
  IGNORE_ERRORS( integration_M_Link_MockDel(self) )
  SELF_REF_DEL(integration_M_Link, next);
  LUMI_owner_dec_ref(self->next_Refman);
}

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "BaseLink.m-meth"
Returncode integration_M_BaseLink_m_meth(integration_M_BaseLink* self, Ref_Manager* self_Refman, integration_M_BaseLink_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void integration_M_BaseLink_Del(integration_M_BaseLink* self) {
  if (self == NULL) return;
  IGNORE_ERRORS( integration_M_BaseLink_MockDel(self) )
  LUMI_dec_ref(self->link_Refman);
  DYN_SELF_REF_DEL(integration_M_BaseLink, _, next);
  LUMI_owner_dec_ref(self->next_Refman);
}

void integration_M_TopLink_Del(integration_M_TopLink* self) {
  if (self == NULL) return;
  integration_M_BaseLink_Del(&(self->_base));
  IGNORE_ERRORS( integration_M_TopLink_MockDel(self) )
  if (self->item_Dynamic != NULL) self->item_Dynamic->_del(self->item);
  LUMI_owner_dec_ref(self->item_Refman);
}

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "RefNode.new"
Returncode integration_M_RefNode_new(integration_M_RefNode* self, Ref_Manager* self_Refman, Ref ref, integration_M_RefNode* next, Ref_Manager* next_Refman) {
  Returncode LUMI_err = OK;
  integration_M_RefNode* aux_RefNode_0 = NULL;
  Ref_Manager* aux_RefNode_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(173, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(173, 38, "used member of outdated weak reference")
  self->ref = ref;
  if (self == NULL) RAISE(174, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(174, 38, "used member of outdated weak reference")
  aux_RefNode_0 = next;
  aux_RefNode_0_Refman = next_Refman;
  next = NULL;
  next_Refman = NULL;
  integration_M_RefNode_Del(self->next);
  LUMI_owner_dec_ref(self->next_Refman);
  self->next_Refman = aux_RefNode_0_Refman;
  self->next = aux_RefNode_0;
  aux_RefNode_0 = NULL;
  aux_RefNode_0_Refman = NULL;
LUMI_cleanup:
  integration_M_RefNode_Del(aux_RefNode_0);
  LUMI_owner_dec_ref(aux_RefNode_0_Refman);
  integration_M_RefNode_Del(next);
  LUMI_owner_dec_ref(next_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void integration_M_RefNode_Del(integration_M_RefNode* self) {
  if (self == NULL) return;
  SELF_REF_DEL(integration_M_RefNode, next);
  LUMI_owner_dec_ref(self->next_Refman);
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
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(36)
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
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
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
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
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
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
  LUMI_err = t->fun();
  CHECK(68)
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
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
  aux_Ref_Manager = *arrio_Refman;
  *arrio_Refman = arri_Refman;
  LUMI_inc_ref(*arrio_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *arrio = aux_Array_5;
  if (arrs == NULL) RAISE(93, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(93, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrs)->length) RAISE(93, 25, "slice index out of bounds")
  aux_Ref_Manager = s_Refman;
  s_Refman = arrs_Refman;
  LUMI_inc_ref(s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  s = ((String*)((arrs)->values)) + 4;
  aux_Array_6 = &aux_Array_6_Var;
  aux_Array_6_Refman = LUMI_new_ref(aux_Array_6);
  if (aux_Array_6_Refman == NULL) RAISE(94, 38, "insufficient memory for managed object")
  aux_Array_6_Var.length = 7;
  aux_Array_6_Var.values = (Byte*)((arrs)->values) + (2);
  if (arrs == NULL) RAISE(94, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(94, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrs)->length) RAISE(94, 25, "slice index out of bounds")
  aux_Ref_Manager = *arrso_Refman;
  *arrso_Refman = arrs_Refman;
  LUMI_inc_ref(*arrso_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *arrso = aux_Array_6;
  if (arrt == NULL) RAISE(95, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(95, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(95, 25, "slice index out of bounds")
  aux_Ref_Manager = *t_Refman;
  *t_Refman = arrt_Refman;
  LUMI_inc_ref(*t_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *t = ((integration_M_TestStruct*)((arrt)->values)) + 4;
  aux_Array_7 = &aux_Array_7_Var;
  aux_Array_7_Refman = LUMI_new_ref(aux_Array_7);
  if (aux_Array_7_Refman == NULL) RAISE(96, 38, "insufficient memory for managed object")
  aux_Array_7_Var.length = 7;
  aux_Array_7_Var.values = (Byte*)((arrt)->values) + (2);
  if (arrt == NULL) RAISE(96, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(96, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrt)->length) RAISE(96, 25, "slice index out of bounds")
  aux_Ref_Manager = *arrto_Refman;
  *arrto_Refman = arrt_Refman;
  LUMI_inc_ref(*arrto_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *arrto = aux_Array_7;
  if (arrd == NULL) RAISE(97, 29, "empty object used as sequence")
  if (arrd_Refman->value == NULL) RAISE(97, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrd)->length) RAISE(97, 25, "slice index out of bounds")
  aux_Ref_Manager = *d_Refman;
  *d_Refman = arrd_Refman;
  *d_Dynamic = &integration_M_TestClass_dynamic;
  LUMI_inc_ref(*d_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *d = ((integration_M_TestClass*)((arrd)->values)) + 4;
  aux_Array_8 = &aux_Array_8_Var;
  aux_Array_8_Refman = LUMI_new_ref(aux_Array_8);
  if (aux_Array_8_Refman == NULL) RAISE(98, 38, "insufficient memory for managed object")
  aux_Array_8_Var.length = 7;
  aux_Array_8_Var.values = (Byte*)((arrd)->values) + (2);
  if (arrd == NULL) RAISE(98, 29, "empty object used as sequence")
  if (arrd_Refman->value == NULL) RAISE(98, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrd)->length) RAISE(98, 25, "slice index out of bounds")
  aux_Ref_Manager = *arrdo_Refman;
  *arrdo_Refman = arrd_Refman;
  LUMI_inc_ref(*arrdo_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
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
  aux_Ref_Manager = *arrfo_Refman;
  *arrfo_Refman = arrf_Refman;
  LUMI_inc_ref(*arrfo_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *arrfo = aux_Array_9;
  if (arrf == NULL) RAISE(101, 29, "empty object used as sequence")
  if (arrf_Refman->value == NULL) RAISE(101, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(101, 25, "slice index out of bounds")
  if (((Returncode (**)(void))((arrf)->values))[4] == NULL) RAISE(101, 21, "empty function called")
  LUMI_err = (((Returncode (**)(void))((arrf)->values))[4])();
  CHECK(101)
  if (*arrfo == NULL) RAISE(102, 29, "empty object used as sequence")
  if ((*arrfo_Refman)->value == NULL) RAISE(102, 40, "outdated weak reference used as sequence")
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
  tv_Refman = LUMI_new_ref(tv);
  if (tv_Refman == NULL) RAISE(119, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(tv, tv_Refman, 0, NULL, NULL);
  CHECK(119)
  dv = &dv_Var;
  dv_Refman = LUMI_new_ref(dv);
  if (dv_Refman == NULL) RAISE(120, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestClass_new(dv, dv_Refman, dv_Dynamic);
  CHECK(120)
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
  LUMI_err = integration_M_TestStruct_new(tn, tn_Refman, 0, NULL, NULL);
  CHECK(128)
  dn = LUMI_alloc(sizeof(integration_M_TestClass));
  if (dn == NULL) RAISE(129, 49, "insufficient memory for object dynamic allocation")
  dn_Refman = LUMI_new_ref(dn);
  if (dn_Refman == NULL) RAISE(129, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestClass_new(dn, dn_Refman, dn_Dynamic);
  CHECK(129)
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
  LUMI_err = String_new(isv, isv_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(138)
  isn = LUMI_new_string(i);
  if (isn == NULL) RAISE(139, 49, "insufficient memory for object dynamic allocation")
  isn_Refman = LUMI_new_ref(isn);
  if (isn_Refman == NULL) RAISE(139, 38, "insufficient memory for managed object")
  LUMI_err = String_new(isn, isn_Refman, text, text_Refman);
  CHECK(139)
  fi = integration_M_f_test_int2str_Mock;
  itv = &itv_Var;
  itv_Refman = LUMI_new_ref(itv);
  if (itv_Refman == NULL) RAISE(141, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(itv, itv_Refman, i, text, text_Refman);
  CHECK(141)
  itn = LUMI_alloc(sizeof(integration_M_TestStruct));
  if (itn == NULL) RAISE(142, 49, "insufficient memory for object dynamic allocation")
  itn_Refman = LUMI_new_ref(itn);
  if (itn_Refman == NULL) RAISE(142, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(itn, itn_Refman, i, text, text_Refman);
  CHECK(142)
  idv = &idv_Var;
  idv_Refman = LUMI_new_ref(idv);
  if (idv_Refman == NULL) RAISE(143, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestClass_new(idv, idv_Refman, idv_Dynamic);
  CHECK(143)
  idn = LUMI_alloc(sizeof(integration_M_TestClass));
  if (idn == NULL) RAISE(144, 49, "insufficient memory for object dynamic allocation")
  idn_Refman = LUMI_new_ref(idn);
  if (idn_Refman == NULL) RAISE(144, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestClass_new(idn, idn_Refman, idn_Dynamic);
  CHECK(144)
  aux_TestStruct_0 = LUMI_alloc(sizeof(integration_M_TestStruct));
  if (aux_TestStruct_0 == NULL) RAISE(145, 49, "insufficient memory for object dynamic allocation")
  aux_TestStruct_0_Refman = LUMI_new_ref(aux_TestStruct_0);
  if (aux_TestStruct_0_Refman == NULL) RAISE(145, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(aux_TestStruct_0, aux_TestStruct_0_Refman, i, text, text_Refman);
  CHECK(145)
  LUMI_err = integration_M_TestStruct_print(aux_TestStruct_0, aux_TestStruct_0_Refman);
  CHECK(145)
  aux_TestClass_0 = LUMI_alloc(sizeof(integration_M_TestClass));
  if (aux_TestClass_0 == NULL) RAISE(146, 49, "insufficient memory for object dynamic allocation")
  aux_TestClass_0_Refman = LUMI_new_ref(aux_TestClass_0);
  if (aux_TestClass_0_Refman == NULL) RAISE(146, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestClass_new(aux_TestClass_0, aux_TestClass_0_Refman, aux_TestClass_0_Dynamic);
  CHECK(146)
  LUMI_err = integration_M_TestClass_print(aux_TestClass_0, aux_TestClass_0_Refman, aux_TestClass_0_Dynamic);
  CHECK(146)
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
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(266, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 5;
  aux_String_0_Var.length = 4;
  aux_String_0_Var.values = "text";
  LUMI_err = integration_M_f_test_params(3, aux_String_0, aux_String_0_Refman, NULL, NULL);
  CHECK(266)
  LUMI_err = integration_M_f_test_outs(&(s), &(s_Refman), &(x));
  CHECK(267)
  LUMI_err = integration_M_f_test_int2str_Mock(4, &(s), &(s_Refman));
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
  LUMI_err = integration_M_f_test_int2str_Mock(13, &(aux_String_1), &(aux_String_1_Refman));
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
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(s_Refman);
  LUMI_inc_ref(a_Refman);
  LUMI_err = Int_str(i, s, s_Refman);
  CHECK(317)
  bv = true || false;
  if (a == NULL) RAISE(319, 27, "used member of empty object")
  if (a_Refman->value == NULL) RAISE(319, 38, "used member of outdated weak reference")
  i = a->length;
  if (s == NULL) RAISE(320, 27, "used member of empty object")
  if (s_Refman->value == NULL) RAISE(320, 38, "used member of outdated weak reference")
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
  LUMI_err = File_close(f, f_Refman);
  CHECK(336)
  if (sys == NULL) RAISE(337, 27, "used member of empty object")
  if (sys_Refman->value == NULL) RAISE(337, 38, "used member of outdated weak reference")
  if (sys->argv == NULL) RAISE(337, 29, "empty object used as sequence")
  if (sys->argv_Refman->value == NULL) RAISE(337, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (sys->argv)->length) RAISE(337, 25, "slice index out of bounds")
  aux_Ref_Manager = s_Refman;
  s_Refman = sys->argv_Refman;
  LUMI_inc_ref(s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  s = ((String*)((sys->argv)->values)) + 1;
  LUMI_err = Sys_print(sys, sys_Refman, s, s_Refman);
  CHECK(338)
  LUMI_err = Sys_println_Mock(sys, sys_Refman, s, s_Refman);
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
  LUMI_err = File_putc(stdout, stdout_Refman, c);
  CHECK(345)
  LUMI_err = File_getc(stdin, stdin_Refman, &(cv), &(bv));
  CHECK(346)
  LUMI_err = File_putc(stderr, stderr_Refman, c);
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
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(351, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "test string";
  s = LUMI_new_string(32);
  if (s == NULL) RAISE(351, 49, "insufficient memory for object dynamic allocation")
  s_Refman = LUMI_new_ref(s);
  if (s_Refman == NULL) RAISE(351, 38, "insufficient memory for managed object")
  LUMI_err = String_new(s, s_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(351)
  s_user = s;
  s_user_Refman = s_Refman;
  LUMI_inc_ref(s_user_Refman);
  LUMI_err = Sys_println_Mock(sys, sys_Refman, s, s_Refman);
  CHECK(353)
  LUMI_err = Sys_println_Mock(sys, sys_Refman, s_user, s_user_Refman);
  CHECK(354)
  LUMI_err = integration_M_f_remove(s, s_Refman);
  s = NULL;
  s_Refman = NULL;
  CHECK(355)
  if (! (s != NULL && s_Refman->value != NULL)) {
    aux_String_1 = &aux_String_1_Var;
    aux_String_1_Refman = LUMI_new_ref(aux_String_1);
    if (aux_String_1_Refman == NULL) RAISE(357, 38, "insufficient memory for managed object")
    aux_String_1_Var.max_length = 17;
    aux_String_1_Var.length = 16;
    aux_String_1_Var.values = "ownership passed";
    LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
    CHECK(357)
  }
  if (! (s_user != NULL && s_user_Refman->value != NULL)) {
    aux_String_2 = &aux_String_2_Var;
    aux_String_2_Refman = LUMI_new_ref(aux_String_2);
    if (aux_String_2_Refman == NULL) RAISE(359, 38, "insufficient memory for managed object")
    aux_String_2_Var.max_length = 15;
    aux_String_2_Var.length = 14;
    aux_String_2_Var.values = "string deleted";
    LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_2, aux_String_2_Refman);
    CHECK(359)
  }
  aux_String_3 = &aux_String_3_Var;
  aux_String_3_Refman = LUMI_new_ref(aux_String_3);
  if (aux_String_3_Refman == NULL) RAISE(360, 38, "insufficient memory for managed object")
  aux_String_3_Var.max_length = 13;
  aux_String_3_Var.length = 12;
  aux_String_3_Var.values = "first struct";
  ts = LUMI_alloc(sizeof(integration_M_TestStruct));
  if (ts == NULL) RAISE(360, 49, "insufficient memory for object dynamic allocation")
  ts_Refman = LUMI_new_ref(ts);
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
  if (ts == NULL) RAISE(362, 27, "used member of empty object")
  if (ts_Refman->value == NULL) RAISE(362, 38, "used member of outdated weak reference")
  LUMI_err = Sys_println_Mock(sys, sys_Refman, ts->text, ts->text_Refman);
  CHECK(362)
  aux_String_4 = &aux_String_4_Var;
  aux_String_4_Refman = LUMI_new_ref(aux_String_4);
  if (aux_String_4_Refman == NULL) RAISE(363, 38, "insufficient memory for managed object")
  aux_String_4_Var.max_length = 14;
  aux_String_4_Var.length = 13;
  aux_String_4_Var.values = "second struct";
  aux_TestStruct_1 = LUMI_alloc(sizeof(integration_M_TestStruct));
  if (aux_TestStruct_1 == NULL) RAISE(363, 49, "insufficient memory for object dynamic allocation")
  aux_TestStruct_1_Refman = LUMI_new_ref(aux_TestStruct_1);
  if (aux_TestStruct_1_Refman == NULL) RAISE(363, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(aux_TestStruct_1, aux_TestStruct_1_Refman, 1, aux_String_4, aux_String_4_Refman);
  CHECK(363)
  if (ts == NULL) RAISE(363, 27, "used member of empty object")
  if (ts_Refman->value == NULL) RAISE(363, 38, "used member of outdated weak reference")
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
  if (ts == NULL) RAISE(364, 27, "used member of empty object")
  if (ts_Refman->value == NULL) RAISE(364, 38, "used member of outdated weak reference")
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
  if (ts == NULL) RAISE(365, 27, "used member of empty object")
  if (ts_Refman->value == NULL) RAISE(365, 38, "used member of outdated weak reference")
  LUMI_err = Sys_println_Mock(sys, sys_Refman, ts->text, ts->text_Refman);
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
  d_Refman = LUMI_new_ref(d);
  if (d_Refman == NULL) RAISE(395, 38, "insufficient memory for managed object")
  sarr = &sarr_Var;
  sarr_Var.values = sarr_Values;
  LUMI_set_var_string_array(6, 16, sarr, sarr_Chars);
  sarr_Refman = LUMI_new_ref(sarr);
  if (sarr_Refman == NULL) RAISE(396, 38, "insufficient memory for managed object")
  if (d == NULL) RAISE(397, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(397, 38, "used member of outdated weak reference")
  aux_Ref_Manager = d->item_Refman;
  d->item_Refman = s_Refman;
  d->item_Dynamic = &String_dynamic;
  LUMI_inc_ref(d->item_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  d->item = s;
  if (d == NULL) RAISE(398, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(398, 38, "used member of outdated weak reference")
  aux_Ref_Manager = s_Refman;
  s_Refman = d->item_Refman;
  LUMI_inc_ref(s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  s = d->item;
  if (d == NULL) RAISE(399, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(399, 38, "used member of outdated weak reference")
  aux_Ref_Manager = d->arr_Refman;
  d->arr_Refman = sarr_Refman;
  LUMI_inc_ref(d->arr_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  d->arr = sarr;
  if (d == NULL) RAISE(400, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(400, 38, "used member of outdated weak reference")
  if (d->arr == NULL) RAISE(400, 29, "empty object used as sequence")
  if (d->arr_Refman->value == NULL) RAISE(400, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (d->arr)->length) RAISE(400, 25, "slice index out of bounds")
  aux_Ref_Manager = s_Refman;
  s_Refman = d->arr_Refman;
  LUMI_inc_ref(s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  s = ((String*)((d->arr)->values)) + 4;
  ad = &ad_Var;
  ad_Var.values = ad_Values;
  ad_Refman = LUMI_new_ref(ad);
  if (ad_Refman == NULL) RAISE(401, 38, "insufficient memory for managed object")
  if (ad == NULL) RAISE(402, 29, "empty object used as sequence")
  if (ad_Refman->value == NULL) RAISE(402, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (ad)->length) RAISE(402, 25, "slice index out of bounds")
  if (((integration_M_Data*)((ad)->values)) + 2 == NULL) RAISE(402, 27, "used member of empty object")
  if (ad_Refman->value == NULL) RAISE(402, 38, "used member of outdated weak reference")
  aux_Ref_Manager = s_Refman;
  s_Refman = (((integration_M_Data*)((ad)->values)) + 2)->item_Refman;
  LUMI_inc_ref(s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  s = (((integration_M_Data*)((ad)->values)) + 2)->item;
  if (ad == NULL) RAISE(403, 29, "empty object used as sequence")
  if (ad_Refman->value == NULL) RAISE(403, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (ad)->length) RAISE(403, 25, "slice index out of bounds")
  if (((integration_M_Data*)((ad)->values)) + 2 == NULL) RAISE(403, 27, "used member of empty object")
  if (ad_Refman->value == NULL) RAISE(403, 38, "used member of outdated weak reference")
  if ((((integration_M_Data*)((ad)->values)) + 2)->arr == NULL) RAISE(403, 29, "empty object used as sequence")
  if ((((integration_M_Data*)((ad)->values)) + 2)->arr_Refman->value == NULL) RAISE(403, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) >= ((((integration_M_Data*)((ad)->values)) + 2)->arr)->length) RAISE(403, 25, "slice index out of bounds")
  aux_Ref_Manager = s_Refman;
  s_Refman = (((integration_M_Data*)((ad)->values)) + 2)->arr_Refman;
  LUMI_inc_ref(s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  s = ((String*)(((((integration_M_Data*)((ad)->values)) + 2)->arr)->values)) + 3;
  dr = &dr_Var;
  dr_Refman = LUMI_new_ref(dr);
  if (dr_Refman == NULL) RAISE(404, 38, "insufficient memory for managed object")
  if (dr == NULL) RAISE(405, 27, "used member of empty object")
  if (dr_Refman->value == NULL) RAISE(405, 38, "used member of outdated weak reference")
  if (dr->item == NULL) RAISE(405, 27, "used member of empty object")
  if (dr->item_Refman->value == NULL) RAISE(405, 38, "used member of outdated weak reference")
  if (((integration_M_Data*)(dr->item))->item == NULL) RAISE(405, 27, "used member of empty object")
  if (((integration_M_Data*)(dr->item))->item_Refman->value == NULL) RAISE(405, 38, "used member of outdated weak reference")
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
  t_Refman = LUMI_new_ref(t);
  if (t_Refman == NULL) RAISE(411, 38, "insufficient memory for managed object")
  dt = &dt_Var;
  dt_Refman = LUMI_new_ref(dt);
  if (dt_Refman == NULL) RAISE(412, 38, "insufficient memory for managed object")
  ts = &ts_Var;
  ts_Refman = LUMI_new_ref(ts);
  if (ts_Refman == NULL) RAISE(413, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(ts, ts_Refman, 0, NULL, NULL);
  CHECK(413)
  if (t == NULL) RAISE(414, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(414, 38, "used member of outdated weak reference")
  aux_Ref_Manager = t->_base._base._base.item_Refman;
  t->_base._base._base.item_Refman = s_Refman;
  t->_base._base._base.item_Dynamic = &String_dynamic;
  LUMI_inc_ref(t->_base._base._base.item_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  t->_base._base._base.item = s;
  if (t == NULL) RAISE(415, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(415, 38, "used member of outdated weak reference")
  aux_Ref_Manager = t->_base._base._base.arr_Refman;
  t->_base._base._base.arr_Refman = sarr_Refman;
  LUMI_inc_ref(t->_base._base._base.arr_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  t->_base._base._base.arr = sarr;
  if (t == NULL) RAISE(416, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(416, 38, "used member of outdated weak reference")
  aux_Ref_Manager = t->_base._base.second_Refman;
  t->_base._base.second_Refman = dt_Refman;
  t->_base._base.second_Dynamic = &integration_M_Data_dynamic;
  LUMI_inc_ref(t->_base._base.second_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  t->_base._base.second = dt;
  if (t == NULL) RAISE(417, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(417, 38, "used member of outdated weak reference")
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
    if (t == NULL) RAISE(422, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(422, 38, "used member of outdated weak reference")
    t->num = 1;

#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
  } while (false);
  --LUMI_trace_ignore_count;
  if (LUMI_err != OK) {
    LUMI_err = OK;
    aux_String_0 = &aux_String_0_Var;
    aux_String_0_Refman = LUMI_new_ref(aux_String_0);
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
    aux_String_0_Refman = LUMI_new_ref(aux_String_0);
    if (aux_String_0_Refman == NULL) RAISE(428, 38, "insufficient memory for managed object")
    aux_String_0_Var.max_length = 20;
    aux_String_0_Var.length = 19;
    aux_String_0_Var.values = "error handling { 1 ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(428)
    if (t == NULL) RAISE(429, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(429, 38, "used member of outdated weak reference")
    t->num = 1;
    aux_String_1 = &aux_String_1_Var;
    aux_String_1_Refman = LUMI_new_ref(aux_String_1);
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
    aux_String_2_Refman = LUMI_new_ref(aux_String_2);
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
      aux_String_3_Refman = LUMI_new_ref(aux_String_3);
      if (aux_String_3_Refman == NULL) RAISE(438, 38, "insufficient memory for managed object")
      aux_String_3_Var.max_length = 3;
      aux_String_3_Var.length = 2;
      aux_String_3_Var.values = "3 ";
      LUMI_err = Sys_print(sys, sys_Refman, aux_String_3, aux_String_3_Refman);
      CHECK(438)
      if (t == NULL) RAISE(439, 27, "used member of empty object")
      if (t_Refman->value == NULL) RAISE(439, 38, "used member of outdated weak reference")
      t->num = 2;
      aux_String_4 = &aux_String_4_Var;
      aux_String_4_Refman = LUMI_new_ref(aux_String_4);
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
    aux_String_5_Refman = LUMI_new_ref(aux_String_5);
    if (aux_String_5_Refman == NULL) RAISE(441, 38, "insufficient memory for managed object")
    aux_String_5_Var.max_length = 3;
    aux_String_5_Var.length = 2;
    aux_String_5_Var.values = "4 ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_5, aux_String_5_Refman);
    CHECK(441)
  }
  aux_String_6 = &aux_String_6_Var;
  aux_String_6_Refman = LUMI_new_ref(aux_String_6);
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
    aux_String_7_Refman = LUMI_new_ref(aux_String_7);
    if (aux_String_7_Refman == NULL) RAISE(444, 38, "insufficient memory for managed object")
    aux_String_7_Var.max_length = 3;
    aux_String_7_Var.length = 2;
    aux_String_7_Var.values = "6 ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_7, aux_String_7_Refman);
    CHECK(444)
    do {
      ++LUMI_trace_ignore_count;
      aux_String_8 = &aux_String_8_Var;
      aux_String_8_Refman = LUMI_new_ref(aux_String_8);
      if (aux_String_8_Refman == NULL) RAISE(446, 38, "insufficient memory for managed object")
      aux_String_8_Var.max_length = 3;
      aux_String_8_Var.length = 2;
      aux_String_8_Var.values = "7 ";
      LUMI_err = Sys_print(sys, sys_Refman, aux_String_8, aux_String_8_Refman);
      CHECK(446)
      LUMI_err = integration_M_f_try_catch_raise(t, t_Refman);
      CHECK(447)
      aux_String_9 = &aux_String_9_Var;
      aux_String_9_Refman = LUMI_new_ref(aux_String_9);
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
    aux_String_10_Refman = LUMI_new_ref(aux_String_10);
    if (aux_String_10_Refman == NULL) RAISE(449, 38, "insufficient memory for managed object")
    aux_String_10_Var.max_length = 3;
    aux_String_10_Var.length = 2;
    aux_String_10_Var.values = "8 ";
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_10, aux_String_10_Refman);
    CHECK(449)
    aux_String_11 = &aux_String_11_Var;
    aux_String_11_Refman = LUMI_new_ref(aux_String_11);
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
  aux_String_12_Refman = LUMI_new_ref(aux_String_12);
  if (aux_String_12_Refman == NULL) RAISE(451, 38, "insufficient memory for managed object")
  aux_String_12_Var.max_length = 2;
  aux_String_12_Var.length = 1;
  aux_String_12_Var.values = "}";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_12, aux_String_12_Refman);
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
  text_Refman = LUMI_new_ref(text);
  if (text_Refman == NULL) RAISE(481, 38, "insufficient memory for managed object")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(482, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 8;
  aux_String_0_Var.length = 7;
  aux_String_0_Var.values = "chars[ ";
  LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(482)
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
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
  {int c_Index; for (c_Index = 0; c_Index < aux_String_2->length; ++c_Index) {
    if (aux_String_2 == NULL) RAISE(483, 29, "empty object used as sequence")
    if (aux_String_2_Refman->value == NULL) RAISE(483, 40, "outdated weak reference used as sequence")
    if ((c_Index) < 0 || (c_Index) >= (aux_String_2)->length) RAISE(483, 25, "slice index out of bounds")
    c = ((aux_String_2)->values)[c_Index];
    LUMI_err = String_clear(text, text_Refman);
    CHECK(484)
    LUMI_err = String_append(text, text_Refman, c);
    CHECK(485)
    LUMI_err = Sys_print(sys, sys_Refman, text, text_Refman);
    CHECK(486)
    aux_String_3 = &aux_String_3_Var;
    aux_String_3_Refman = LUMI_new_ref(aux_String_3);
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
  aux_String_4_Refman = LUMI_new_ref(aux_String_4);
  if (aux_String_4_Refman == NULL) RAISE(488, 38, "insufficient memory for managed object")
  aux_String_4_Var.max_length = 2;
  aux_String_4_Var.length = 1;
  aux_String_4_Var.values = "]";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_4, aux_String_4_Refman);
  CHECK(488)
  arr = &arr_Var;
  arr_Var.values = arr_Values;
  arr_Refman = LUMI_new_ref(arr);
  if (arr_Refman == NULL) RAISE(490, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(491, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(491, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(491, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[0] = 14;
  if (arr == NULL) RAISE(492, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(492, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (arr)->length) RAISE(492, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[1] = 15;
  if (arr == NULL) RAISE(493, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(493, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (arr)->length) RAISE(493, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[2] = 16;
  aux_String_5 = &aux_String_5_Var;
  aux_String_5_Refman = LUMI_new_ref(aux_String_5);
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
  {int n_Index; for (n_Index = 0; n_Index < aux_Array_0->length; ++n_Index) {
    if (aux_Array_0 == NULL) RAISE(495, 29, "empty object used as sequence")
    if (aux_Array_0_Refman->value == NULL) RAISE(495, 40, "outdated weak reference used as sequence")
    if ((n_Index) < 0 || (n_Index) >= (aux_Array_0)->length) RAISE(495, 25, "slice index out of bounds")
    n = ((Int*)((aux_Array_0)->values))[n_Index];
    LUMI_err = String_clear(text, text_Refman);
    CHECK(496)
    LUMI_err = Int_str(n, text, text_Refman);
    CHECK(497)
    LUMI_err = Sys_print(sys, sys_Refman, text, text_Refman);
    CHECK(498)
    aux_String_6 = &aux_String_6_Var;
    aux_String_6_Refman = LUMI_new_ref(aux_String_6);
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
  aux_String_7_Refman = LUMI_new_ref(aux_String_7);
  if (aux_String_7_Refman == NULL) RAISE(500, 38, "insufficient memory for managed object")
  aux_String_7_Var.max_length = 2;
  aux_String_7_Var.length = 1;
  aux_String_7_Var.values = "]";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_7, aux_String_7_Refman);
  CHECK(500)
  tsarr = &tsarr_Var;
  tsarr_Var.values = tsarr_Values;
  tsarr_Refman = LUMI_new_ref(tsarr);
  if (tsarr_Refman == NULL) RAISE(502, 38, "insufficient memory for managed object")
  aux_String_8 = &aux_String_8_Var;
  aux_String_8_Refman = LUMI_new_ref(aux_String_8);
  if (aux_String_8_Refman == NULL) RAISE(503, 38, "insufficient memory for managed object")
  aux_String_8_Var.max_length = 4;
  aux_String_8_Var.length = 3;
  aux_String_8_Var.values = "aaa";
  if (tsarr == NULL) RAISE(503, 29, "empty object used as sequence")
  if (tsarr_Refman->value == NULL) RAISE(503, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (tsarr)->length) RAISE(503, 25, "slice index out of bounds")
  if (((integration_M_TestStruct*)((tsarr)->values)) + 0 == NULL) RAISE(503, 27, "used member of empty object")
  if (tsarr_Refman->value == NULL) RAISE(503, 38, "used member of outdated weak reference")
  aux_Ref_Manager = (((integration_M_TestStruct*)((tsarr)->values)) + 0)->text_Refman;
  (((integration_M_TestStruct*)((tsarr)->values)) + 0)->text_Refman = aux_String_8_Refman;
  LUMI_inc_ref((((integration_M_TestStruct*)((tsarr)->values)) + 0)->text_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  (((integration_M_TestStruct*)((tsarr)->values)) + 0)->text = aux_String_8;
  aux_String_9 = &aux_String_9_Var;
  aux_String_9_Refman = LUMI_new_ref(aux_String_9);
  if (aux_String_9_Refman == NULL) RAISE(504, 38, "insufficient memory for managed object")
  aux_String_9_Var.max_length = 4;
  aux_String_9_Var.length = 3;
  aux_String_9_Var.values = "bbb";
  if (tsarr == NULL) RAISE(504, 29, "empty object used as sequence")
  if (tsarr_Refman->value == NULL) RAISE(504, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (tsarr)->length) RAISE(504, 25, "slice index out of bounds")
  if (((integration_M_TestStruct*)((tsarr)->values)) + 1 == NULL) RAISE(504, 27, "used member of empty object")
  if (tsarr_Refman->value == NULL) RAISE(504, 38, "used member of outdated weak reference")
  aux_Ref_Manager = (((integration_M_TestStruct*)((tsarr)->values)) + 1)->text_Refman;
  (((integration_M_TestStruct*)((tsarr)->values)) + 1)->text_Refman = aux_String_9_Refman;
  LUMI_inc_ref((((integration_M_TestStruct*)((tsarr)->values)) + 1)->text_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  (((integration_M_TestStruct*)((tsarr)->values)) + 1)->text = aux_String_9;
  aux_String_10 = &aux_String_10_Var;
  aux_String_10_Refman = LUMI_new_ref(aux_String_10);
  if (aux_String_10_Refman == NULL) RAISE(505, 38, "insufficient memory for managed object")
  aux_String_10_Var.max_length = 4;
  aux_String_10_Var.length = 3;
  aux_String_10_Var.values = "ccc";
  if (tsarr == NULL) RAISE(505, 29, "empty object used as sequence")
  if (tsarr_Refman->value == NULL) RAISE(505, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (tsarr)->length) RAISE(505, 25, "slice index out of bounds")
  if (((integration_M_TestStruct*)((tsarr)->values)) + 2 == NULL) RAISE(505, 27, "used member of empty object")
  if (tsarr_Refman->value == NULL) RAISE(505, 38, "used member of outdated weak reference")
  aux_Ref_Manager = (((integration_M_TestStruct*)((tsarr)->values)) + 2)->text_Refman;
  (((integration_M_TestStruct*)((tsarr)->values)) + 2)->text_Refman = aux_String_10_Refman;
  LUMI_inc_ref((((integration_M_TestStruct*)((tsarr)->values)) + 2)->text_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  (((integration_M_TestStruct*)((tsarr)->values)) + 2)->text = aux_String_10;
  aux_String_11 = &aux_String_11_Var;
  aux_String_11_Refman = LUMI_new_ref(aux_String_11);
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
  {int ts_Index; for (ts_Index = 0; ts_Index < aux_Array_1->length; ++ts_Index) {
    if (aux_Array_1 == NULL) RAISE(507, 29, "empty object used as sequence")
    if (aux_Array_1_Refman->value == NULL) RAISE(507, 40, "outdated weak reference used as sequence")
    if ((ts_Index) < 0 || (ts_Index) >= (aux_Array_1)->length) RAISE(507, 25, "slice index out of bounds")
    aux_Ref_Manager = ts_Refman;
    ts_Refman = aux_Array_1_Refman;
    LUMI_inc_ref(ts_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ts = ((integration_M_TestStruct*)((aux_Array_1)->values)) + ts_Index;
    if (ts == NULL) RAISE(508, 27, "used member of empty object")
    if (ts_Refman->value == NULL) RAISE(508, 38, "used member of outdated weak reference")
    LUMI_err = Sys_print(sys, sys_Refman, ts->text, ts->text_Refman);
    CHECK(508)
    aux_String_12 = &aux_String_12_Var;
    aux_String_12_Refman = LUMI_new_ref(aux_String_12);
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
  aux_String_13_Refman = LUMI_new_ref(aux_String_13);
  if (aux_String_13_Refman == NULL) RAISE(510, 38, "insufficient memory for managed object")
  aux_String_13_Var.max_length = 2;
  aux_String_13_Var.length = 1;
  aux_String_13_Var.values = "]";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_13, aux_String_13_Refman);
  CHECK(510)
  sarr = &sarr_Var;
  sarr_Var.values = sarr_Values;
  LUMI_set_var_string_array(3, 16, sarr, sarr_Chars);
  sarr_Refman = LUMI_new_ref(sarr);
  if (sarr_Refman == NULL) RAISE(512, 38, "insufficient memory for managed object")
  if (sarr == NULL) RAISE(513, 29, "empty object used as sequence")
  if (sarr_Refman->value == NULL) RAISE(513, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (sarr)->length) RAISE(513, 25, "slice index out of bounds")
  aux_String_14 = &aux_String_14_Var;
  aux_String_14_Refman = LUMI_new_ref(aux_String_14);
  if (aux_String_14_Refman == NULL) RAISE(513, 38, "insufficient memory for managed object")
  aux_String_14_Var.max_length = 4;
  aux_String_14_Var.length = 3;
  aux_String_14_Var.values = "ddd";
  LUMI_err = String_new(((String*)((sarr)->values)) + 0, sarr_Refman, aux_String_14, aux_String_14_Refman);
  CHECK(513)
  if (sarr == NULL) RAISE(514, 29, "empty object used as sequence")
  if (sarr_Refman->value == NULL) RAISE(514, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (sarr)->length) RAISE(514, 25, "slice index out of bounds")
  aux_String_15 = &aux_String_15_Var;
  aux_String_15_Refman = LUMI_new_ref(aux_String_15);
  if (aux_String_15_Refman == NULL) RAISE(514, 38, "insufficient memory for managed object")
  aux_String_15_Var.max_length = 4;
  aux_String_15_Var.length = 3;
  aux_String_15_Var.values = "eee";
  LUMI_err = String_new(((String*)((sarr)->values)) + 1, sarr_Refman, aux_String_15, aux_String_15_Refman);
  CHECK(514)
  if (sarr == NULL) RAISE(515, 29, "empty object used as sequence")
  if (sarr_Refman->value == NULL) RAISE(515, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (sarr)->length) RAISE(515, 25, "slice index out of bounds")
  aux_String_16 = &aux_String_16_Var;
  aux_String_16_Refman = LUMI_new_ref(aux_String_16);
  if (aux_String_16_Refman == NULL) RAISE(515, 38, "insufficient memory for managed object")
  aux_String_16_Var.max_length = 4;
  aux_String_16_Var.length = 3;
  aux_String_16_Var.values = "fff";
  LUMI_err = String_new(((String*)((sarr)->values)) + 2, sarr_Refman, aux_String_16, aux_String_16_Refman);
  CHECK(515)
  aux_String_17 = &aux_String_17_Var;
  aux_String_17_Refman = LUMI_new_ref(aux_String_17);
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
  {int s_Index; for (s_Index = 0; s_Index < aux_Array_2->length; ++s_Index) {
    if (aux_Array_2 == NULL) RAISE(517, 29, "empty object used as sequence")
    if (aux_Array_2_Refman->value == NULL) RAISE(517, 40, "outdated weak reference used as sequence")
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
    aux_String_18_Refman = LUMI_new_ref(aux_String_18);
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
  aux_String_19_Refman = LUMI_new_ref(aux_String_19);
  if (aux_String_19_Refman == NULL) RAISE(520, 38, "insufficient memory for managed object")
  aux_String_19_Var.max_length = 2;
  aux_String_19_Var.length = 1;
  aux_String_19_Var.values = "]";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_19, aux_String_19_Refman);
  CHECK(520)
  aux_String_20 = &aux_String_20_Var;
  aux_String_20_Refman = LUMI_new_ref(aux_String_20);
  if (aux_String_20_Refman == NULL) RAISE(522, 38, "insufficient memory for managed object")
  aux_String_20_Var.max_length = 4;
  aux_String_20_Var.length = 3;
  aux_String_20_Var.values = "iii";
  container_last = &container_last_Var;
  container_last_Refman = LUMI_new_ref(container_last);
  if (container_last_Refman == NULL) RAISE(522, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_Container_new(container_last, container_last_Refman, aux_String_20, aux_String_20_Refman, &String_dynamic, NULL, NULL);
  CHECK(522)
  aux_String_21 = &aux_String_21_Var;
  aux_String_21_Refman = LUMI_new_ref(aux_String_21);
  if (aux_String_21_Refman == NULL) RAISE(523, 38, "insufficient memory for managed object")
  aux_String_21_Var.max_length = 4;
  aux_String_21_Var.length = 3;
  aux_String_21_Var.values = "hhh";
  container_mid = &container_mid_Var;
  container_mid_Refman = LUMI_new_ref(container_mid);
  if (container_mid_Refman == NULL) RAISE(523, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_Container_new(container_mid, container_mid_Refman, aux_String_21, aux_String_21_Refman, &String_dynamic, container_last, container_last_Refman);
  CHECK(523)
  aux_String_22 = &aux_String_22_Var;
  aux_String_22_Refman = LUMI_new_ref(aux_String_22);
  if (aux_String_22_Refman == NULL) RAISE(524, 38, "insufficient memory for managed object")
  aux_String_22_Var.max_length = 4;
  aux_String_22_Var.length = 3;
  aux_String_22_Var.values = "ggg";
  container_first = &container_first_Var;
  container_first_Refman = LUMI_new_ref(container_first);
  if (container_first_Refman == NULL) RAISE(524, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_Container_new(container_first, container_first_Refman, aux_String_22, aux_String_22_Refman, &String_dynamic, container_mid, container_mid_Refman);
  CHECK(524)
  container = &container_Var;
  container_Refman = LUMI_new_ref(container);
  if (container_Refman == NULL) RAISE(525, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_Container_new(container, container_Refman, NULL, NULL, NULL, container_first, container_first_Refman);
  CHECK(525)
  LUMI_err = integration_M_Container_iter(container, container_Refman, &(iter), &(iter_Refman));
  CHECK(527)
  aux_String_23 = &aux_String_23_Var;
  aux_String_23_Refman = LUMI_new_ref(aux_String_23);
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
    aux_String_24_Refman = LUMI_new_ref(aux_String_24);
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
  aux_String_25_Refman = LUMI_new_ref(aux_String_25);
  if (aux_String_25_Refman == NULL) RAISE(532, 38, "insufficient memory for managed object")
  aux_String_25_Var.max_length = 2;
  aux_String_25_Var.length = 1;
  aux_String_25_Var.values = "]";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_25, aux_String_25_Refman);
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
  y_Refman = LUMI_new_ref(y);
  if (y_Refman == NULL) RAISE(555, 38, "insufficient memory for managed object")
  if (y == NULL) RAISE(556, 27, "used member of empty object")
  if (y_Refman->value == NULL) RAISE(556, 38, "used member of outdated weak reference")
  if (y == NULL) RAISE(556, 27, "used member of empty object")
  if (y_Refman->value == NULL) RAISE(556, 38, "used member of outdated weak reference")
  aux_Ref_Manager = y->x.x_Refman;
  y->x.x_Refman = y_Refman;
  y->x.x_Dynamic = &integration_M_ComplexField_dynamic;
  LUMI_inc_ref(y->x.x_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  y->x.x = &(y->x);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(557, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "complex fields: ";
  LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(557)
  LUMI_err = integration_M_HasComplexField_run(y, y_Refman);
  CHECK(558)
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(559, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 1;
  aux_String_1_Var.length = 0;
  aux_String_1_Var.values = "";
  LUMI_err = Sys_println_Mock(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
  CHECK(559)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(y_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "test-mid-out"
Returncode integration_M_test_mid_out(covered_M_MiddleType** mt, Ref_Manager** mt_Refman, covered_M_MiddleType_Dynamic** mt_Dynamic) {
  Returncode LUMI_err = OK;
  covered_M_MiddleType* new_mt = NULL;
  Ref_Manager* new_mt_Refman = NULL;
  covered_M_MiddleType_Dynamic* new_mt_Dynamic = &covered_M_MiddleType_dynamic;
  Ref_Manager* aux_Ref_Manager = NULL;
  new_mt = LUMI_alloc(sizeof(covered_M_MiddleType));
  if (new_mt == NULL) RAISE(66, 49, "insufficient memory for object dynamic allocation")
  new_mt_Refman = LUMI_new_ref(new_mt);
  if (new_mt_Refman == NULL) RAISE(66, 38, "insufficient memory for managed object")
  LUMI_err = covered_M_MiddleType_new(new_mt, new_mt_Refman, new_mt_Dynamic);
  CHECK(66)
  aux_Ref_Manager = *mt_Refman;
  *mt_Refman = new_mt_Refman;
  *mt_Dynamic = new_mt_Dynamic;
  LUMI_inc_ref(*mt_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *mt = new_mt;
LUMI_cleanup:
  if (new_mt_Dynamic != NULL) new_mt_Dynamic->_base._del(new_mt);
  LUMI_owner_dec_ref(new_mt_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

Bool integration_M_TestStruct_get_Mock_active = true;
#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "TestStruct.get Mock"
Returncode integration_M_TestStruct_get_Mock(integration_M_TestStruct* self, Ref_Manager* self_Refman, Int* x, String** s, Ref_Manager** s_Refman) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(self_Refman);
  if (!integration_M_TestStruct_get_Mock_active) return integration_M_TestStruct_get(self, self_Refman, x, s, s_Refman);
  *x = 12;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(72, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 1;
  aux_String_0_Var.length = 0;
  aux_String_0_Var.values = "";
  aux_Ref_Manager = *s_Refman;
  *s_Refman = aux_String_0_Refman;
  LUMI_inc_ref(*s_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  *s = aux_String_0;
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

Bool integration_M_f_test_int2str_Mock_active = true;
#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "f-test-int2str Mock"
Returncode integration_M_f_test_int2str_Mock(Int x, String** s, Ref_Manager** s_Refman) {
  Returncode LUMI_err = OK;
  if (!integration_M_f_test_int2str_Mock_active) return integration_M_f_test_int2str(x, s, s_Refman);
  USER_RAISE(75, NULL, NULL)
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

Bool integration_M_TestClass_dynamic_meth_Mock_active = true;
#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "TestClass.dynamic-meth Mock"
Returncode integration_M_TestClass_dynamic_meth_Mock(integration_M_TestClass* self, Ref_Manager* self_Refman, integration_M_TestClass_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (!integration_M_TestClass_dynamic_meth_Mock_active) return integration_M_TestClass_dynamic_meth(self, self_Refman, self_Dynamic);
  if (self == NULL) RAISE(78, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(78, 38, "used member of outdated weak reference")
  self->num = 7;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "test-func"
Returncode integration_M_test_func(void) {
  Returncode LUMI_err = OK;
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  integration_M_TestStruct t_Var = {0};
  integration_M_TestStruct* t = NULL;
  Ref_Manager* t_Refman = NULL;
  Int x = 0;
  integration_M_TestClass c_Var = {0};
  integration_M_TestClass* c = NULL;
  Ref_Manager* c_Refman = NULL;
  integration_M_TestClass_Dynamic* c_Dynamic = &integration_M_TestClass_dynamic;
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  String* aux_String_2 = NULL;
  Ref_Manager* aux_String_2_Refman = NULL;
  String* aux_String_3 = NULL;
  Ref_Manager* aux_String_3_Refman = NULL;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = integration_M_f_test_int2str_Mock(3, &(s), &(s_Refman));
    CHECK(82)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    TEST_FAIL(82, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_err = integration_M_f_test_int2str(4, &(s), &(s_Refman));
  CHECK(83)
  integration_M_f_test_int2str_Mock_active = false;
  LUMI_err = integration_M_f_test_int2str_Mock(5, &(s), &(s_Refman));
  CHECK(85)
  integration_M_f_test_int2str_Mock_active = true;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = integration_M_f_test_int2str_Mock(6, &(s), &(s_Refman));
    CHECK(87)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    TEST_FAIL(87, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  t = &t_Var;
  t_Refman = LUMI_new_ref(t);
  if (t_Refman == NULL) RAISE(89, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestStruct_new(t, t_Refman, 0, NULL, NULL);
  CHECK(89)
  LUMI_err = integration_M_TestStruct_get_Mock(t, t_Refman, &(x), &(aux_String_0), &(aux_String_0_Refman));
  CHECK(91)
  TEST_ASSERT(92, x == 12)
  LUMI_err = integration_M_TestStruct_get(t, t_Refman, &(x), &(aux_String_1), &(aux_String_1_Refman));
  CHECK(93)
  TEST_ASSERT(94, x == 0)
  integration_M_TestStruct_get_Mock_active = false;
  x = 1;
  LUMI_err = integration_M_TestStruct_get_Mock(t, t_Refman, &(x), &(aux_String_2), &(aux_String_2_Refman));
  CHECK(97)
  TEST_ASSERT(98, x == 0)
  integration_M_TestStruct_get_Mock_active = true;
  LUMI_err = integration_M_TestStruct_get_Mock(t, t_Refman, &(x), &(aux_String_3), &(aux_String_3_Refman));
  CHECK(100)
  TEST_ASSERT(101, x == 12)
  c = &c_Var;
  c_Refman = LUMI_new_ref(c);
  if (c_Refman == NULL) RAISE(103, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TestClass_new(c, c_Refman, c_Dynamic);
  CHECK(103)
  if (c == NULL) RAISE(104, 27, "used member of empty object")
  if (c_Refman->value == NULL) RAISE(104, 38, "used member of outdated weak reference")
  TEST_ASSERT(104, c->num == 1)
  if (c_Dynamic == NULL) RAISE(105, 28, "dynamic call of empty object")
  LUMI_err = c_Dynamic->dynamic_meth(c, c_Refman, c_Dynamic);
  CHECK(105)
  if (c == NULL) RAISE(106, 27, "used member of empty object")
  if (c_Refman->value == NULL) RAISE(106, 38, "used member of outdated weak reference")
  TEST_ASSERT(106, c->num == 7)
  LUMI_err = integration_M_TestClass_dynamic_meth(c, c_Refman, c_Dynamic);
  CHECK(107)
  if (c == NULL) RAISE(108, 27, "used member of empty object")
  if (c_Refman->value == NULL) RAISE(108, 38, "used member of outdated weak reference")
  TEST_ASSERT(108, c->num == 6)
  integration_M_TestClass_dynamic_meth_Mock_active = false;
  if (c == NULL) RAISE(110, 27, "used member of empty object")
  if (c_Refman->value == NULL) RAISE(110, 38, "used member of outdated weak reference")
  c->num = 0;
  if (c_Dynamic == NULL) RAISE(111, 28, "dynamic call of empty object")
  LUMI_err = c_Dynamic->dynamic_meth(c, c_Refman, c_Dynamic);
  CHECK(111)
  if (c == NULL) RAISE(112, 27, "used member of empty object")
  if (c_Refman->value == NULL) RAISE(112, 38, "used member of outdated weak reference")
  TEST_ASSERT(112, c->num == 6)
  integration_M_TestClass_dynamic_meth_Mock_active = true;
  LUMI_err = integration_M_TestClass_dynamic_meth_Mock(c, c_Refman, c_Dynamic);
  CHECK(114)
  if (c == NULL) RAISE(115, 27, "used member of empty object")
  if (c_Refman->value == NULL) RAISE(115, 38, "used member of outdated weak reference")
  TEST_ASSERT(115, c->num == 7)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_3_Refman);
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(c_Refman);
  LUMI_dec_ref(t_Refman);
  String_Del(s);
  LUMI_owner_dec_ref(s_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "test-another"
Returncode integration_M_test_another(void) {
  Returncode LUMI_err = OK;
  Int x = 0;
  TEST_ASSERT(120, x == 0)
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "test-native"
Returncode integration_M_test_native(void) {
  Returncode LUMI_err = OK;
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
  TEST_ASSERT(130, external_int == 6)
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(133, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = "bb";
  s = &s_Var;
  s_Var.values = s_Values;
  s_Refman = LUMI_new_ref(s);
  if (s_Refman == NULL) RAISE(133, 38, "insufficient memory for managed object")
  LUMI_err = String_new(s, s_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(133)
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = external(3, s, &(i), &(n));
    CHECK(134)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    TEST_FAIL(134, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  TEST_ASSERT(135, i == 3)
  if (s == NULL) RAISE(136, 29, "empty object used as sequence")
  if (s_Refman->value == NULL) RAISE(136, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (s)->length) RAISE(136, 25, "slice index out of bounds")
  TEST_ASSERT(136, (((s)->values)[0]) == 'a')
  LUMI_err = external2(n, &(aux_Bool_0));
  CHECK(137)
  TEST_ASSERT(137, aux_Bool_0)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(s_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "test-dynamic-type-parameters"
Returncode integration_M_test_dynamic_type_parameters(void) {
  Returncode LUMI_err = OK;
  integration_M_Data dmid_Var = {0};
  integration_M_Data* dmid = NULL;
  Ref_Manager* dmid_Refman = NULL;
  integration_M_TopType ttop_Var = {{{0}}};
  integration_M_TopType* ttop = NULL;
  Ref_Manager* ttop_Refman = NULL;
  integration_M_TopType_Dynamic* ttop_Dynamic = &integration_M_TopType_dynamic;
  integration_M_BaseType* tbase = NULL;
  Ref_Manager* tbase_Refman = NULL;
  integration_M_BaseType_Dynamic* tbase_Dynamic = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  dmid = &dmid_Var;
  dmid_Refman = LUMI_new_ref(dmid);
  if (dmid_Refman == NULL) RAISE(141, 38, "insufficient memory for managed object")
  ttop = &ttop_Var;
  ttop_Refman = LUMI_new_ref(ttop);
  if (ttop_Refman == NULL) RAISE(142, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_TopType_new(ttop, ttop_Refman, ttop_Dynamic);
  CHECK(142)
  if (ttop == NULL) RAISE(143, 27, "used member of empty object")
  if (ttop_Refman->value == NULL) RAISE(143, 38, "used member of outdated weak reference")
  ttop->_base._base.num_base = 12;
  if (dmid == NULL) RAISE(144, 27, "used member of empty object")
  if (dmid_Refman->value == NULL) RAISE(144, 38, "used member of outdated weak reference")
  aux_Ref_Manager = dmid->item_Refman;
  dmid->item_Refman = ttop_Refman;
  dmid->item_Dynamic = (Generic_Type_Dynamic*)&(ttop_Dynamic->_base);
  LUMI_inc_ref(dmid->item_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  dmid->item = &(ttop->_base);
  if (dmid == NULL) RAISE(146, 27, "used member of empty object")
  if (dmid_Refman->value == NULL) RAISE(146, 38, "used member of outdated weak reference")
  aux_Ref_Manager = tbase_Refman;
  tbase_Refman = dmid->item_Refman;
  tbase_Dynamic = &(((covered_M_MiddleType_Dynamic*)(dmid->item_Dynamic))->_base);
  LUMI_inc_ref(tbase_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  tbase = &(((covered_M_MiddleType*)(dmid->item))->_base);
  if (tbase == NULL) RAISE(147, 27, "used member of empty object")
  if (tbase_Refman->value == NULL) RAISE(147, 38, "used member of outdated weak reference")
  TEST_ASSERT(147, tbase->num_base == 12)
  if (ttop == NULL) RAISE(148, 27, "used member of empty object")
  if (ttop_Refman->value == NULL) RAISE(148, 38, "used member of outdated weak reference")
  ttop->_base._base.num_base = 13;
  LUMI_err = integration_M_Data_set(dmid, dmid_Refman, &(ttop->_base), ttop_Refman, (void*)&(ttop_Dynamic->_base), NULL, NULL);
  CHECK(149)
  aux_Ref_Manager = tbase_Refman;
  tbase_Refman = NULL;
  tbase_Dynamic = NULL;
  LUMI_inc_ref(tbase_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  tbase = NULL;
  if (tbase != NULL) RAISE(151, 45, "non empty base class given as output argument")
  LUMI_err = integration_M_Data_get(dmid, dmid_Refman, (void*)&(tbase), &(tbase_Refman), (void*)&(tbase_Dynamic));
  CHECK(151)
  if (tbase == NULL) RAISE(152, 27, "used member of empty object")
  if (tbase_Refman->value == NULL) RAISE(152, 38, "used member of outdated weak reference")
  TEST_ASSERT(152, tbase->num_base == 13)
LUMI_cleanup:
  LUMI_dec_ref(tbase_Refman);
  LUMI_dec_ref(ttop_Refman);
  LUMI_dec_ref(dmid_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "delete Mock"
Returncode delete_Mock(Ref self) {
  Returncode LUMI_err = OK;
  integration_M_RefNode* aux_RefNode_0 = NULL;
  Ref_Manager* aux_RefNode_0_Refman = NULL;
  integration_M_RefNode* aux_RefNode_1 = NULL;
  Ref_Manager* aux_RefNode_1_Refman = NULL;
  if (integration_M_record_delete) {
    aux_RefNode_0 = LUMI_alloc(sizeof(integration_M_RefNode));
    if (aux_RefNode_0 == NULL) RAISE(184, 49, "insufficient memory for object dynamic allocation")
    aux_RefNode_0_Refman = LUMI_new_ref(aux_RefNode_0);
    if (aux_RefNode_0_Refman == NULL) RAISE(184, 38, "insufficient memory for managed object")
    LUMI_err = integration_M_RefNode_new(aux_RefNode_0, aux_RefNode_0_Refman, self, integration_M_deleted_refmans, integration_M_deleted_refmans_Refman);
    integration_M_deleted_refmans = NULL;
    integration_M_deleted_refmans_Refman = NULL;
    CHECK(184)
    aux_RefNode_1 = aux_RefNode_0;
    aux_RefNode_1_Refman = aux_RefNode_0_Refman;
    aux_RefNode_0 = NULL;
    aux_RefNode_0_Refman = NULL;
    integration_M_RefNode_Del(integration_M_deleted_refmans);
    LUMI_owner_dec_ref(integration_M_deleted_refmans_Refman);
    integration_M_deleted_refmans_Refman = aux_RefNode_1_Refman;
    integration_M_deleted_refmans = aux_RefNode_1;
    aux_RefNode_1 = NULL;
    aux_RefNode_1_Refman = NULL;
  }
LUMI_cleanup:
  integration_M_RefNode_Del(aux_RefNode_1);
  LUMI_owner_dec_ref(aux_RefNode_1_Refman);
  integration_M_RefNode_Del(aux_RefNode_0);
  LUMI_owner_dec_ref(aux_RefNode_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "Link.MockDel"
Returncode integration_M_Link_MockDel(Ref self) {
  Returncode LUMI_err = OK;
  integration_M_RefNode* aux_RefNode_0 = NULL;
  Ref_Manager* aux_RefNode_0_Refman = NULL;
  integration_M_RefNode* aux_RefNode_1 = NULL;
  Ref_Manager* aux_RefNode_1_Refman = NULL;
  if (integration_M_record_delete) {
    aux_RefNode_0 = LUMI_alloc(sizeof(integration_M_RefNode));
    if (aux_RefNode_0 == NULL) RAISE(188, 49, "insufficient memory for object dynamic allocation")
    aux_RefNode_0_Refman = LUMI_new_ref(aux_RefNode_0);
    if (aux_RefNode_0_Refman == NULL) RAISE(188, 38, "insufficient memory for managed object")
    LUMI_err = integration_M_RefNode_new(aux_RefNode_0, aux_RefNode_0_Refman, self, integration_M_deleted_links, integration_M_deleted_links_Refman);
    integration_M_deleted_links = NULL;
    integration_M_deleted_links_Refman = NULL;
    CHECK(188)
    aux_RefNode_1 = aux_RefNode_0;
    aux_RefNode_1_Refman = aux_RefNode_0_Refman;
    aux_RefNode_0 = NULL;
    aux_RefNode_0_Refman = NULL;
    integration_M_RefNode_Del(integration_M_deleted_links);
    LUMI_owner_dec_ref(integration_M_deleted_links_Refman);
    integration_M_deleted_links_Refman = aux_RefNode_1_Refman;
    integration_M_deleted_links = aux_RefNode_1;
    aux_RefNode_1 = NULL;
    aux_RefNode_1_Refman = NULL;
  }
LUMI_cleanup:
  integration_M_RefNode_Del(aux_RefNode_1);
  LUMI_owner_dec_ref(aux_RefNode_1_Refman);
  integration_M_RefNode_Del(aux_RefNode_0);
  LUMI_owner_dec_ref(aux_RefNode_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "BaseLink.MockDel"
Returncode integration_M_BaseLink_MockDel(Ref self) {
  Returncode LUMI_err = OK;
  integration_M_RefNode* aux_RefNode_0 = NULL;
  Ref_Manager* aux_RefNode_0_Refman = NULL;
  integration_M_RefNode* aux_RefNode_1 = NULL;
  Ref_Manager* aux_RefNode_1_Refman = NULL;
  if (integration_M_record_delete) {
    aux_RefNode_0 = LUMI_alloc(sizeof(integration_M_RefNode));
    if (aux_RefNode_0 == NULL) RAISE(192, 49, "insufficient memory for object dynamic allocation")
    aux_RefNode_0_Refman = LUMI_new_ref(aux_RefNode_0);
    if (aux_RefNode_0_Refman == NULL) RAISE(192, 38, "insufficient memory for managed object")
    LUMI_err = integration_M_RefNode_new(aux_RefNode_0, aux_RefNode_0_Refman, self, integration_M_deleted_base_links, integration_M_deleted_base_links_Refman);
    integration_M_deleted_base_links = NULL;
    integration_M_deleted_base_links_Refman = NULL;
    CHECK(192)
    aux_RefNode_1 = aux_RefNode_0;
    aux_RefNode_1_Refman = aux_RefNode_0_Refman;
    aux_RefNode_0 = NULL;
    aux_RefNode_0_Refman = NULL;
    integration_M_RefNode_Del(integration_M_deleted_base_links);
    LUMI_owner_dec_ref(integration_M_deleted_base_links_Refman);
    integration_M_deleted_base_links_Refman = aux_RefNode_1_Refman;
    integration_M_deleted_base_links = aux_RefNode_1;
    aux_RefNode_1 = NULL;
    aux_RefNode_1_Refman = NULL;
  }
LUMI_cleanup:
  integration_M_RefNode_Del(aux_RefNode_1);
  LUMI_owner_dec_ref(aux_RefNode_1_Refman);
  integration_M_RefNode_Del(aux_RefNode_0);
  LUMI_owner_dec_ref(aux_RefNode_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "TopLink.MockDel"
Returncode integration_M_TopLink_MockDel(Ref self) {
  Returncode LUMI_err = OK;
  integration_M_RefNode* aux_RefNode_0 = NULL;
  Ref_Manager* aux_RefNode_0_Refman = NULL;
  integration_M_RefNode* aux_RefNode_1 = NULL;
  Ref_Manager* aux_RefNode_1_Refman = NULL;
  if (integration_M_record_delete) {
    aux_RefNode_0 = LUMI_alloc(sizeof(integration_M_RefNode));
    if (aux_RefNode_0 == NULL) RAISE(196, 49, "insufficient memory for object dynamic allocation")
    aux_RefNode_0_Refman = LUMI_new_ref(aux_RefNode_0);
    if (aux_RefNode_0_Refman == NULL) RAISE(196, 38, "insufficient memory for managed object")
    LUMI_err = integration_M_RefNode_new(aux_RefNode_0, aux_RefNode_0_Refman, self, integration_M_deleted_top_links, integration_M_deleted_top_links_Refman);
    integration_M_deleted_top_links = NULL;
    integration_M_deleted_top_links_Refman = NULL;
    CHECK(196)
    aux_RefNode_1 = aux_RefNode_0;
    aux_RefNode_1_Refman = aux_RefNode_0_Refman;
    aux_RefNode_0 = NULL;
    aux_RefNode_0_Refman = NULL;
    integration_M_RefNode_Del(integration_M_deleted_top_links);
    LUMI_owner_dec_ref(integration_M_deleted_top_links_Refman);
    integration_M_deleted_top_links_Refman = aux_RefNode_1_Refman;
    integration_M_deleted_top_links = aux_RefNode_1;
    aux_RefNode_1 = NULL;
    aux_RefNode_1_Refman = NULL;
  }
LUMI_cleanup:
  integration_M_RefNode_Del(aux_RefNode_1);
  LUMI_owner_dec_ref(aux_RefNode_1_Refman);
  integration_M_RefNode_Del(aux_RefNode_0);
  LUMI_owner_dec_ref(aux_RefNode_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "f-remove-obj"
Returncode integration_M_f_remove_obj(integration_M_Link* b, Ref_Manager* b_Refman) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  integration_M_Link_Del(b);
  LUMI_owner_dec_ref(b_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "test-simple-delete"
Returncode integration_M_test_simple_delete(void) {
  Returncode LUMI_err = OK;
  integration_M_Link* l = NULL;
  Ref_Manager* l_Refman = NULL;
  integration_M_Link* l_user = NULL;
  Ref_Manager* l_user_Refman = NULL;
  Ref l_ref = NULL;
  integration_M_RefNode* aux_RefNode_0 = NULL;
  Ref_Manager* aux_RefNode_0_Refman = NULL;
  integration_M_RefNode* aux_RefNode_1 = NULL;
  Ref_Manager* aux_RefNode_1_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  TEST_ASSERT(202, ! (integration_M_deleted_refmans != NULL && integration_M_deleted_refmans_Refman->value != NULL))
  TEST_ASSERT(203, ! (integration_M_deleted_links != NULL && integration_M_deleted_links_Refman->value != NULL))
  integration_M_record_delete = true;
  l = LUMI_alloc(sizeof(integration_M_Link));
  if (l == NULL) RAISE(206, 49, "insufficient memory for object dynamic allocation")
  l_Refman = LUMI_new_ref(l);
  if (l_Refman == NULL) RAISE(206, 38, "insufficient memory for managed object")
  l_user = l;
  l_user_Refman = l_Refman;
  LUMI_inc_ref(l_user_Refman);
  TEST_ASSERT(208, l != NULL && l_Refman->value != NULL)
  TEST_ASSERT(209, l_user != NULL && l_user_Refman->value != NULL)
  l_ref = l;
  LUMI_err = integration_M_f_remove_obj(l, l_Refman);
  l = NULL;
  l_Refman = NULL;
  CHECK(211)
  TEST_ASSERT(212, ! (l != NULL && l_Refman->value != NULL))
  TEST_ASSERT(213, ! (l_user != NULL && l_user_Refman->value != NULL))
  TEST_ASSERT(214, ! (integration_M_deleted_refmans != NULL && integration_M_deleted_refmans_Refman->value != NULL))
  TEST_ASSERT(215, integration_M_deleted_links != NULL && integration_M_deleted_links_Refman->value != NULL)
  if (integration_M_deleted_links == NULL) RAISE(216, 27, "used member of empty object")
  if (integration_M_deleted_links_Refman->value == NULL) RAISE(216, 38, "used member of outdated weak reference")
  TEST_ASSERT(216, (void*)integration_M_deleted_links->ref == l_ref)
  if (integration_M_deleted_links == NULL) RAISE(217, 27, "used member of empty object")
  if (integration_M_deleted_links_Refman->value == NULL) RAISE(217, 38, "used member of outdated weak reference")
  TEST_ASSERT(217, ! (integration_M_deleted_links->next != NULL && integration_M_deleted_links->next_Refman->value != NULL))
  aux_Ref_Manager = l_user_Refman;
  l_user_Refman = NULL;
  LUMI_inc_ref(l_user_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  l_user = NULL;
  TEST_ASSERT(219, integration_M_deleted_refmans != NULL && integration_M_deleted_refmans_Refman->value != NULL)
  if (integration_M_deleted_refmans == NULL) RAISE(220, 27, "used member of empty object")
  if (integration_M_deleted_refmans_Refman->value == NULL) RAISE(220, 38, "used member of outdated weak reference")
  TEST_ASSERT(220, (void*)integration_M_deleted_refmans->ref == l_ref)
  if (integration_M_deleted_refmans == NULL) RAISE(221, 27, "used member of empty object")
  if (integration_M_deleted_refmans_Refman->value == NULL) RAISE(221, 38, "used member of outdated weak reference")
  TEST_ASSERT(221, ! (integration_M_deleted_refmans->next != NULL && integration_M_deleted_refmans->next_Refman->value != NULL))
  integration_M_record_delete = false;
  aux_RefNode_0 = NULL;
  aux_RefNode_0_Refman = NULL;
  integration_M_RefNode_Del(integration_M_deleted_refmans);
  LUMI_owner_dec_ref(integration_M_deleted_refmans_Refman);
  integration_M_deleted_refmans_Refman = aux_RefNode_0_Refman;
  integration_M_deleted_refmans = aux_RefNode_0;
  aux_RefNode_0 = NULL;
  aux_RefNode_0_Refman = NULL;
  aux_RefNode_1 = NULL;
  aux_RefNode_1_Refman = NULL;
  integration_M_RefNode_Del(integration_M_deleted_links);
  LUMI_owner_dec_ref(integration_M_deleted_links_Refman);
  integration_M_deleted_links_Refman = aux_RefNode_1_Refman;
  integration_M_deleted_links = aux_RefNode_1;
  aux_RefNode_1 = NULL;
  aux_RefNode_1_Refman = NULL;
LUMI_cleanup:
  integration_M_RefNode_Del(aux_RefNode_1);
  LUMI_owner_dec_ref(aux_RefNode_1_Refman);
  integration_M_RefNode_Del(aux_RefNode_0);
  LUMI_owner_dec_ref(aux_RefNode_0_Refman);
  LUMI_dec_ref(l_user_Refman);
  integration_M_Link_Del(l);
  LUMI_owner_dec_ref(l_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "f-has-ref"
Returncode integration_M_f_has_ref(Ref ref, integration_M_RefNode** node, Ref_Manager** node_Refman) {
  Returncode LUMI_err = OK;
  LUMI_err = integration_M_f_has_ref_rec(ref, &(*node), &(*node_Refman));
  CHECK(228)
  LUMI_err = integration_M_f_has_ref_rec(ref, &(integration_M_deleted_refmans), &(integration_M_deleted_refmans_Refman));
  CHECK(229)
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "f-has-ref-rec"
Returncode integration_M_f_has_ref_rec(Ref ref, integration_M_RefNode** node, Ref_Manager** node_Refman) {
  Returncode LUMI_err = OK;
  integration_M_RefNode* next = NULL;
  Ref_Manager* next_Refman = NULL;
  integration_M_RefNode* aux_RefNode_0 = NULL;
  Ref_Manager* aux_RefNode_0_Refman = NULL;
  TEST_ASSERT(232, (*node) != NULL && (*node_Refman)->value != NULL)
  if (*node == NULL) RAISE(233, 27, "used member of empty object")
  if ((*node_Refman)->value == NULL) RAISE(233, 38, "used member of outdated weak reference")
  if ((void*)(*node)->ref == ref) {
    if (*node == NULL) RAISE(234, 27, "used member of empty object")
    if ((*node_Refman)->value == NULL) RAISE(234, 38, "used member of outdated weak reference")
    next = (*node)->next;
    next_Refman = (*node)->next_Refman;
    (*node)->next = NULL;
    (*node)->next_Refman = NULL;
    aux_RefNode_0 = next;
    aux_RefNode_0_Refman = next_Refman;
    next = NULL;
    next_Refman = NULL;
    integration_M_RefNode_Del(*node);
    LUMI_owner_dec_ref(*node_Refman);
    *node_Refman = aux_RefNode_0_Refman;
    *node = aux_RefNode_0;
    aux_RefNode_0 = NULL;
    aux_RefNode_0_Refman = NULL;
  }
  else {
    if (*node == NULL) RAISE(237, 27, "used member of empty object")
    if ((*node_Refman)->value == NULL) RAISE(237, 38, "used member of outdated weak reference")
    LUMI_err = integration_M_f_has_ref_rec(ref, &((*node)->next), &((*node)->next_Refman));
    CHECK(237)
  }
LUMI_cleanup:
  integration_M_RefNode_Del(aux_RefNode_0);
  LUMI_owner_dec_ref(aux_RefNode_0_Refman);
  integration_M_RefNode_Del(next);
  LUMI_owner_dec_ref(next_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "test-complex-delete"
Returncode integration_M_test_complex_delete(void) {
  Returncode LUMI_err = OK;
  integration_M_BaseLink* b1 = NULL;
  Ref_Manager* b1_Refman = NULL;
  integration_M_BaseLink_Dynamic* b1_Dynamic = &integration_M_BaseLink_dynamic;
  Ref b1_ref = NULL;
  integration_M_BaseLink* b2 = NULL;
  Ref_Manager* b2_Refman = NULL;
  integration_M_BaseLink_Dynamic* b2_Dynamic = &integration_M_BaseLink_dynamic;
  Ref b2_ref = NULL;
  integration_M_TopLink* t1 = NULL;
  Ref_Manager* t1_Refman = NULL;
  integration_M_TopLink_Dynamic* t1_Dynamic = &integration_M_TopLink_dynamic;
  Ref t1_ref = NULL;
  integration_M_TopLink* t2 = NULL;
  Ref_Manager* t2_Refman = NULL;
  integration_M_TopLink_Dynamic* t2_Dynamic = &integration_M_TopLink_dynamic;
  Ref t2_ref = NULL;
  integration_M_TopLink* t3 = NULL;
  Ref_Manager* t3_Refman = NULL;
  integration_M_TopLink_Dynamic* t3_Dynamic = &integration_M_TopLink_dynamic;
  Ref t3_ref = NULL;
  integration_M_Link* l1 = NULL;
  Ref_Manager* l1_Refman = NULL;
  Ref l1_ref = NULL;
  integration_M_Link* l2 = NULL;
  Ref_Manager* l2_Refman = NULL;
  Ref l2_ref = NULL;
  integration_M_Link* l3 = NULL;
  Ref_Manager* l3_Refman = NULL;
  Ref l3_ref = NULL;
  integration_M_Link* aux_Link_0 = NULL;
  Ref_Manager* aux_Link_0_Refman = NULL;
  integration_M_Link* aux_Link_1 = NULL;
  Ref_Manager* aux_Link_1_Refman = NULL;
  integration_M_BaseLink* aux_BaseLink_0 = NULL;
  Ref_Manager* aux_BaseLink_0_Refman = NULL;
  integration_M_BaseLink_Dynamic* aux_BaseLink_0_Dynamic = NULL;
  integration_M_BaseLink* aux_BaseLink_1 = NULL;
  Ref_Manager* aux_BaseLink_1_Refman = NULL;
  integration_M_BaseLink_Dynamic* aux_BaseLink_1_Dynamic = NULL;
  integration_M_BaseLink* aux_BaseLink_2 = NULL;
  Ref_Manager* aux_BaseLink_2_Refman = NULL;
  integration_M_BaseLink_Dynamic* aux_BaseLink_2_Dynamic = NULL;
  integration_M_Link* aux_Link_2 = NULL;
  Ref_Manager* aux_Link_2_Refman = NULL;
  integration_M_BaseLink* aux_BaseLink_3 = NULL;
  Ref_Manager* aux_BaseLink_3_Refman = NULL;
  integration_M_BaseLink_Dynamic* aux_BaseLink_3_Dynamic = NULL;
  integration_M_BaseLink* aux_BaseLink_4 = NULL;
  Ref_Manager* aux_BaseLink_4_Refman = NULL;
  integration_M_BaseLink_Dynamic* aux_BaseLink_4_Dynamic = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  TEST_ASSERT(240, ! (integration_M_deleted_refmans != NULL && integration_M_deleted_refmans_Refman->value != NULL))
  TEST_ASSERT(241, ! (integration_M_deleted_links != NULL && integration_M_deleted_links_Refman->value != NULL))
  TEST_ASSERT(242, ! (integration_M_deleted_base_links != NULL && integration_M_deleted_base_links_Refman->value != NULL))
  TEST_ASSERT(243, ! (integration_M_deleted_top_links != NULL && integration_M_deleted_top_links_Refman->value != NULL))
  integration_M_record_delete = true;
  b1 = LUMI_alloc(sizeof(integration_M_BaseLink));
  if (b1 == NULL) RAISE(246, 49, "insufficient memory for object dynamic allocation")
  b1_Refman = LUMI_new_ref(b1);
  if (b1_Refman == NULL) RAISE(246, 38, "insufficient memory for managed object")
  b1_ref = b1;
  b2 = LUMI_alloc(sizeof(integration_M_BaseLink));
  if (b2 == NULL) RAISE(248, 49, "insufficient memory for object dynamic allocation")
  b2_Refman = LUMI_new_ref(b2);
  if (b2_Refman == NULL) RAISE(248, 38, "insufficient memory for managed object")
  b2_ref = b2;
  t1 = LUMI_alloc(sizeof(integration_M_TopLink));
  if (t1 == NULL) RAISE(250, 49, "insufficient memory for object dynamic allocation")
  t1_Refman = LUMI_new_ref(t1);
  if (t1_Refman == NULL) RAISE(250, 38, "insufficient memory for managed object")
  t1_ref = t1;
  t2 = LUMI_alloc(sizeof(integration_M_TopLink));
  if (t2 == NULL) RAISE(252, 49, "insufficient memory for object dynamic allocation")
  t2_Refman = LUMI_new_ref(t2);
  if (t2_Refman == NULL) RAISE(252, 38, "insufficient memory for managed object")
  t2_ref = t2;
  t3 = LUMI_alloc(sizeof(integration_M_TopLink));
  if (t3 == NULL) RAISE(254, 49, "insufficient memory for object dynamic allocation")
  t3_Refman = LUMI_new_ref(t3);
  if (t3_Refman == NULL) RAISE(254, 38, "insufficient memory for managed object")
  t3_ref = t3;
  l1 = LUMI_alloc(sizeof(integration_M_Link));
  if (l1 == NULL) RAISE(256, 49, "insufficient memory for object dynamic allocation")
  l1_Refman = LUMI_new_ref(l1);
  if (l1_Refman == NULL) RAISE(256, 38, "insufficient memory for managed object")
  l1_ref = l1;
  l2 = LUMI_alloc(sizeof(integration_M_Link));
  if (l2 == NULL) RAISE(258, 49, "insufficient memory for object dynamic allocation")
  l2_Refman = LUMI_new_ref(l2);
  if (l2_Refman == NULL) RAISE(258, 38, "insufficient memory for managed object")
  l2_ref = l2;
  l3 = LUMI_alloc(sizeof(integration_M_Link));
  if (l3 == NULL) RAISE(260, 49, "insufficient memory for object dynamic allocation")
  l3_Refman = LUMI_new_ref(l3);
  if (l3_Refman == NULL) RAISE(260, 38, "insufficient memory for managed object")
  l3_ref = l3;
  if (b1 == NULL) RAISE(263, 27, "used member of empty object")
  if (b1_Refman->value == NULL) RAISE(263, 38, "used member of outdated weak reference")
  aux_Ref_Manager = b1->link_Refman;
  b1->link_Refman = l1_Refman;
  LUMI_inc_ref(b1->link_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  b1->link = l1;
  if (b2 == NULL) RAISE(264, 27, "used member of empty object")
  if (b2_Refman->value == NULL) RAISE(264, 38, "used member of outdated weak reference")
  aux_Ref_Manager = b2->link_Refman;
  b2->link_Refman = l2_Refman;
  LUMI_inc_ref(b2->link_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  b2->link = l2;
  if (t1 == NULL) RAISE(265, 27, "used member of empty object")
  if (t1_Refman->value == NULL) RAISE(265, 38, "used member of outdated weak reference")
  aux_Ref_Manager = t1->_base.link_Refman;
  t1->_base.link_Refman = l1_Refman;
  LUMI_inc_ref(t1->_base.link_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  t1->_base.link = l1;
  if (t2 == NULL) RAISE(266, 27, "used member of empty object")
  if (t2_Refman->value == NULL) RAISE(266, 38, "used member of outdated weak reference")
  aux_Ref_Manager = t2->_base.link_Refman;
  t2->_base.link_Refman = l2_Refman;
  LUMI_inc_ref(t2->_base.link_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  t2->_base.link = l2;
  if (t3 == NULL) RAISE(267, 27, "used member of empty object")
  if (t3_Refman->value == NULL) RAISE(267, 38, "used member of outdated weak reference")
  aux_Ref_Manager = t3->_base.link_Refman;
  t3->_base.link_Refman = l3_Refman;
  LUMI_inc_ref(t3->_base.link_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  t3->_base.link = l3;
  if (l2 == NULL) RAISE(269, 27, "used member of empty object")
  if (l2_Refman->value == NULL) RAISE(269, 38, "used member of outdated weak reference")
  aux_Link_0 = l3;
  aux_Link_0_Refman = l3_Refman;
  l3 = NULL;
  l3_Refman = NULL;
  integration_M_Link_Del(l2->next);
  LUMI_owner_dec_ref(l2->next_Refman);
  l2->next_Refman = aux_Link_0_Refman;
  l2->next = aux_Link_0;
  aux_Link_0 = NULL;
  aux_Link_0_Refman = NULL;
  TEST_ASSERT(270, ! (l3 != NULL && l3_Refman->value != NULL))
  if (l1 == NULL) RAISE(271, 27, "used member of empty object")
  if (l1_Refman->value == NULL) RAISE(271, 38, "used member of outdated weak reference")
  aux_Link_1 = l2;
  aux_Link_1_Refman = l2_Refman;
  l2 = NULL;
  l2_Refman = NULL;
  integration_M_Link_Del(l1->next);
  LUMI_owner_dec_ref(l1->next_Refman);
  l1->next_Refman = aux_Link_1_Refman;
  l1->next = aux_Link_1;
  aux_Link_1 = NULL;
  aux_Link_1_Refman = NULL;
  TEST_ASSERT(272, ! (l2 != NULL && l2_Refman->value != NULL))
  if (t3 == NULL) RAISE(273, 27, "used member of empty object")
  if (t3_Refman->value == NULL) RAISE(273, 38, "used member of outdated weak reference")
  aux_BaseLink_0 = b2;
  aux_BaseLink_0_Refman = b2_Refman;
  aux_BaseLink_0_Dynamic = b2_Dynamic;
  b2 = NULL;
  b2_Refman = NULL;
  b2_Dynamic = NULL;
  if (t3->item_Dynamic != NULL) ((integration_M_BaseLink_Dynamic*)(t3->item_Dynamic))->_del(t3->item);
  LUMI_owner_dec_ref(t3->item_Refman);
  t3->item_Refman = aux_BaseLink_0_Refman;
  t3->item_Dynamic = (Generic_Type_Dynamic*)aux_BaseLink_0_Dynamic;
  t3->item = aux_BaseLink_0;
  aux_BaseLink_0 = NULL;
  aux_BaseLink_0_Refman = NULL;
  aux_BaseLink_0_Dynamic = NULL;
  TEST_ASSERT(274, ! (b2 != NULL && b2_Refman->value != NULL))
  if (t2 == NULL) RAISE(275, 27, "used member of empty object")
  if (t2_Refman->value == NULL) RAISE(275, 38, "used member of outdated weak reference")
  aux_BaseLink_1 = &(t3->_base);
  aux_BaseLink_1_Refman = t3_Refman;
  aux_BaseLink_1_Dynamic = &(t3_Dynamic->_base);
  t3 = NULL;
  t3_Refman = NULL;
  t3_Dynamic = NULL;
  if (t2->item_Dynamic != NULL) ((integration_M_BaseLink_Dynamic*)(t2->item_Dynamic))->_del(t2->item);
  LUMI_owner_dec_ref(t2->item_Refman);
  t2->item_Refman = aux_BaseLink_1_Refman;
  t2->item_Dynamic = (Generic_Type_Dynamic*)aux_BaseLink_1_Dynamic;
  t2->item = aux_BaseLink_1;
  aux_BaseLink_1 = NULL;
  aux_BaseLink_1_Refman = NULL;
  aux_BaseLink_1_Dynamic = NULL;
  TEST_ASSERT(276, ! (t3 != NULL && t3_Refman->value != NULL))
  if (t1 == NULL) RAISE(277, 27, "used member of empty object")
  if (t1_Refman->value == NULL) RAISE(277, 38, "used member of outdated weak reference")
  aux_BaseLink_2 = &(t2->_base);
  aux_BaseLink_2_Refman = t2_Refman;
  aux_BaseLink_2_Dynamic = &(t2_Dynamic->_base);
  t2 = NULL;
  t2_Refman = NULL;
  t2_Dynamic = NULL;
  if (t1->_base.next_Dynamic != NULL) t1->_base.next_Dynamic->_del(t1->_base.next);
  LUMI_owner_dec_ref(t1->_base.next_Refman);
  t1->_base.next_Refman = aux_BaseLink_2_Refman;
  t1->_base.next_Dynamic = aux_BaseLink_2_Dynamic;
  t1->_base.next = aux_BaseLink_2;
  aux_BaseLink_2 = NULL;
  aux_BaseLink_2_Refman = NULL;
  aux_BaseLink_2_Dynamic = NULL;
  TEST_ASSERT(278, ! (t2 != NULL && t2_Refman->value != NULL))
  if (t1 == NULL) RAISE(279, 27, "used member of empty object")
  if (t1_Refman->value == NULL) RAISE(279, 38, "used member of outdated weak reference")
  aux_Link_2 = l1;
  aux_Link_2_Refman = l1_Refman;
  l1 = NULL;
  l1_Refman = NULL;
  integration_M_Link_Del(t1->item);
  LUMI_owner_dec_ref(t1->item_Refman);
  t1->item_Refman = aux_Link_2_Refman;
  t1->item_Dynamic = &integration_M_Link_dynamic;
  t1->item = aux_Link_2;
  aux_Link_2 = NULL;
  aux_Link_2_Refman = NULL;
  TEST_ASSERT(280, ! (l1 != NULL && l1_Refman->value != NULL))
  if (b1 == NULL) RAISE(281, 27, "used member of empty object")
  if (b1_Refman->value == NULL) RAISE(281, 38, "used member of outdated weak reference")
  aux_BaseLink_3 = &(t1->_base);
  aux_BaseLink_3_Refman = t1_Refman;
  aux_BaseLink_3_Dynamic = &(t1_Dynamic->_base);
  t1 = NULL;
  t1_Refman = NULL;
  t1_Dynamic = NULL;
  if (b1->next_Dynamic != NULL) b1->next_Dynamic->_del(b1->next);
  LUMI_owner_dec_ref(b1->next_Refman);
  b1->next_Refman = aux_BaseLink_3_Refman;
  b1->next_Dynamic = aux_BaseLink_3_Dynamic;
  b1->next = aux_BaseLink_3;
  aux_BaseLink_3 = NULL;
  aux_BaseLink_3_Refman = NULL;
  aux_BaseLink_3_Dynamic = NULL;
  TEST_ASSERT(282, ! (t1 != NULL && t1_Refman->value != NULL))
  TEST_ASSERT(284, ! (integration_M_deleted_refmans != NULL && integration_M_deleted_refmans_Refman->value != NULL))
  TEST_ASSERT(285, ! (integration_M_deleted_links != NULL && integration_M_deleted_links_Refman->value != NULL))
  TEST_ASSERT(286, ! (integration_M_deleted_base_links != NULL && integration_M_deleted_base_links_Refman->value != NULL))
  TEST_ASSERT(287, ! (integration_M_deleted_top_links != NULL && integration_M_deleted_top_links_Refman->value != NULL))
  aux_BaseLink_4 = NULL;
  aux_BaseLink_4_Refman = NULL;
  aux_BaseLink_4_Dynamic = NULL;
  if (b1_Dynamic != NULL) b1_Dynamic->_del(b1);
  LUMI_owner_dec_ref(b1_Refman);
  b1_Refman = aux_BaseLink_4_Refman;
  b1_Dynamic = aux_BaseLink_4_Dynamic;
  b1 = aux_BaseLink_4;
  aux_BaseLink_4 = NULL;
  aux_BaseLink_4_Refman = NULL;
  aux_BaseLink_4_Dynamic = NULL;
  TEST_ASSERT(289, ! (b1 != NULL && b1_Refman->value != NULL))
  integration_M_record_delete = false;
  LUMI_err = integration_M_f_has_ref(b1_ref, &(integration_M_deleted_base_links), &(integration_M_deleted_base_links_Refman));
  CHECK(292)
  LUMI_err = integration_M_f_has_ref(t1_ref, &(integration_M_deleted_top_links), &(integration_M_deleted_top_links_Refman));
  CHECK(293)
  LUMI_err = integration_M_f_has_ref_rec(t1_ref, &(integration_M_deleted_base_links), &(integration_M_deleted_base_links_Refman));
  CHECK(294)
  LUMI_err = integration_M_f_has_ref(t2_ref, &(integration_M_deleted_top_links), &(integration_M_deleted_top_links_Refman));
  CHECK(295)
  LUMI_err = integration_M_f_has_ref_rec(t2_ref, &(integration_M_deleted_base_links), &(integration_M_deleted_base_links_Refman));
  CHECK(296)
  LUMI_err = integration_M_f_has_ref(t3_ref, &(integration_M_deleted_top_links), &(integration_M_deleted_top_links_Refman));
  CHECK(297)
  LUMI_err = integration_M_f_has_ref_rec(t3_ref, &(integration_M_deleted_base_links), &(integration_M_deleted_base_links_Refman));
  CHECK(298)
  LUMI_err = integration_M_f_has_ref(b2_ref, &(integration_M_deleted_base_links), &(integration_M_deleted_base_links_Refman));
  CHECK(299)
  LUMI_err = integration_M_f_has_ref(l1_ref, &(integration_M_deleted_links), &(integration_M_deleted_links_Refman));
  CHECK(300)
  LUMI_err = integration_M_f_has_ref(l2_ref, &(integration_M_deleted_links), &(integration_M_deleted_links_Refman));
  CHECK(301)
  LUMI_err = integration_M_f_has_ref(l3_ref, &(integration_M_deleted_links), &(integration_M_deleted_links_Refman));
  CHECK(302)
  TEST_ASSERT(304, ! (integration_M_deleted_refmans != NULL && integration_M_deleted_refmans_Refman->value != NULL))
  TEST_ASSERT(305, ! (integration_M_deleted_links != NULL && integration_M_deleted_links_Refman->value != NULL))
  TEST_ASSERT(306, ! (integration_M_deleted_base_links != NULL && integration_M_deleted_base_links_Refman->value != NULL))
  TEST_ASSERT(307, ! (integration_M_deleted_top_links != NULL && integration_M_deleted_top_links_Refman->value != NULL))
LUMI_cleanup:
  if (aux_BaseLink_4_Dynamic != NULL) aux_BaseLink_4_Dynamic->_del(aux_BaseLink_4);
  LUMI_owner_dec_ref(aux_BaseLink_4_Refman);
  if (aux_BaseLink_3_Dynamic != NULL) aux_BaseLink_3_Dynamic->_del(aux_BaseLink_3);
  LUMI_owner_dec_ref(aux_BaseLink_3_Refman);
  integration_M_Link_Del(aux_Link_2);
  LUMI_owner_dec_ref(aux_Link_2_Refman);
  if (aux_BaseLink_2_Dynamic != NULL) aux_BaseLink_2_Dynamic->_del(aux_BaseLink_2);
  LUMI_owner_dec_ref(aux_BaseLink_2_Refman);
  if (aux_BaseLink_1_Dynamic != NULL) aux_BaseLink_1_Dynamic->_del(aux_BaseLink_1);
  LUMI_owner_dec_ref(aux_BaseLink_1_Refman);
  if (aux_BaseLink_0_Dynamic != NULL) aux_BaseLink_0_Dynamic->_del(aux_BaseLink_0);
  LUMI_owner_dec_ref(aux_BaseLink_0_Refman);
  integration_M_Link_Del(aux_Link_1);
  LUMI_owner_dec_ref(aux_Link_1_Refman);
  integration_M_Link_Del(aux_Link_0);
  LUMI_owner_dec_ref(aux_Link_0_Refman);
  integration_M_Link_Del(l3);
  LUMI_owner_dec_ref(l3_Refman);
  integration_M_Link_Del(l2);
  LUMI_owner_dec_ref(l2_Refman);
  integration_M_Link_Del(l1);
  LUMI_owner_dec_ref(l1_Refman);
  if (t3_Dynamic != NULL) t3_Dynamic->_base._del(t3);
  LUMI_owner_dec_ref(t3_Refman);
  if (t2_Dynamic != NULL) t2_Dynamic->_base._del(t2);
  LUMI_owner_dec_ref(t2_Refman);
  if (t1_Dynamic != NULL) t1_Dynamic->_base._del(t1);
  LUMI_owner_dec_ref(t1_Refman);
  if (b2_Dynamic != NULL) b2_Dynamic->_del(b2);
  LUMI_owner_dec_ref(b2_Refman);
  if (b1_Dynamic != NULL) b1_Dynamic->_del(b1);
  LUMI_owner_dec_ref(b1_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "f-raise-message"
Returncode integration_M_f_raise_message(void) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(311, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "tested message";
  USER_RAISE(311, aux_String_0, aux_String_0_Refman)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "f-ignore-and-raise"
Returncode integration_M_f_ignore_and_raise(void) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = integration_M_f_raise_message();
    CHECK(315)

#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_err = OK;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(316, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "ignore and raise";
  USER_RAISE(316, aux_String_0, aux_String_0_Refman)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "f-failed-assert"
Returncode integration_M_f_failed_assert(void) {
  Returncode LUMI_err = OK;
  TEST_ASSERT(319, 1 == 2)
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "f-good-assert-error"
Returncode integration_M_f_good_assert_error(void) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = integration_M_f_raise_message();
    CHECK(322)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    TEST_FAIL(322, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(323, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 18;
  aux_String_0_Var.length = 17;
  aux_String_0_Var.values = "good assert error";
  USER_RAISE(323, aux_String_0, aux_String_0_Refman)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "f-failed-assert-error"
Returncode integration_M_f_failed_assert_error(void) {
  Returncode LUMI_err = OK;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = integration_M_f_test_void();
    CHECK(326)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    TEST_FAIL(326, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "f-wrong-message-assert-error"
Returncode integration_M_f_wrong_message_assert_error(void) {
  Returncode LUMI_err = OK;
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "wrong message";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = integration_M_f_raise_message();
    CHECK(329)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(329, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(329)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "new Mock"
Returncode new_Mock(Bool* alloc_success) {
  Returncode LUMI_err = OK;
  *alloc_success = true;
  if (integration_M_new_fail_countdown > 0) {
    integration_M_new_fail_countdown -= 1;
    if (integration_M_new_fail_countdown == 0) {
      *alloc_success = false;
    }
  }
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "f-alloc"
Returncode integration_M_f_alloc(void) {
  Returncode LUMI_err = OK;
  String* string = NULL;
  Ref_Manager* string_Refman = NULL;
  string = LUMI_new_string(16);
  if (string == NULL) RAISE(341, 49, "insufficient memory for object dynamic allocation")
  string_Refman = LUMI_new_ref(string);
  if (string_Refman == NULL) RAISE(341, 38, "insufficient memory for managed object")
  TEST_ASSERT(342, string != NULL && string_Refman->value != NULL)
LUMI_cleanup:
  String_Del(string);
  LUMI_owner_dec_ref(string_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "test-assert-error-message"
Returncode integration_M_test_assert_error_message(void) {
  Returncode LUMI_err = OK;
  Returncode (*fun)(void) = NULL;
  integration_M_BaseType base_var_Var = {0};
  integration_M_BaseType* base_var = NULL;
  Ref_Manager* base_var_Refman = NULL;
  integration_M_BaseType_Dynamic* base_var_Dynamic = &integration_M_BaseType_dynamic;
  integration_M_BaseType* base_user = NULL;
  Ref_Manager* base_user_Refman = NULL;
  integration_M_BaseType_Dynamic* base_user_Dynamic = NULL;
  Array* arr = NULL;
  Ref_Manager* arr_Refman = NULL;
  Array* arr2 = NULL;
  Ref_Manager* arr2_Refman = NULL;
  integration_M_TopType* top = NULL;
  Ref_Manager* top_Refman = NULL;
  integration_M_TopType_Dynamic* top_Dynamic = NULL;
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "tested message";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = integration_M_f_raise_message();
    CHECK(345)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(345, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(345)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "ignore and raise";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = integration_M_f_ignore_and_raise();
    CHECK(346)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(346, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(346)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "condition is not true";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = integration_M_f_failed_assert();
    CHECK(347)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(347, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(347)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "good assert error";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = integration_M_f_good_assert_error();
    CHECK(348)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(348, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(348)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "error not raised";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = integration_M_f_failed_assert_error();
    CHECK(349)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(349, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(349)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = integration_M_f_wrong_message_assert_error();
    CHECK(350)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    TEST_FAIL(350, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "empty function called";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    if (fun == NULL) RAISE(352, 21, "empty function called")
    LUMI_err = fun();
    CHECK(352)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(352, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(352)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
  base_var = &base_var_Var;
  base_var_Refman = LUMI_new_ref(base_var);
  if (base_var_Refman == NULL) RAISE(353, 38, "insufficient memory for managed object")
  LUMI_err = integration_M_BaseType_new(base_var, base_var_Refman, base_var_Dynamic);
  CHECK(353)
  base_user = base_var;
  base_user_Refman = base_var_Refman;
  LUMI_inc_ref(base_user_Refman);
  base_user_Dynamic = base_var_Dynamic;
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "non empty base class given as output argument";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    if (base_user != NULL) RAISE(355, 45, "non empty base class given as output argument")
    LUMI_err = integration_M_test_mid_out((void*)&(base_user), &(base_user_Refman), (void*)&(base_user_Dynamic));
    CHECK(355)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(355, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(355)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
  arr = LUMI_new_array(2, sizeof(Int));
  if (arr == NULL) RAISE(357, 49, "insufficient memory for object dynamic allocation")
  arr_Refman = LUMI_new_ref(arr);
  if (arr_Refman == NULL) RAISE(357, 38, "insufficient memory for managed object")
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "slice index out of bounds";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    if (arr == NULL) RAISE(358, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(358, 40, "outdated weak reference used as sequence")
    if ((6) < 0 || (6) >= (arr)->length) RAISE(358, 25, "slice index out of bounds")
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(358, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(358)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
  arr2 = arr;
  arr2_Refman = arr_Refman;
  LUMI_inc_ref(arr2_Refman);
  aux_Array_0 = NULL;
  aux_Array_0_Refman = NULL;
    LUMI_owner_dec_ref(arr_Refman);
  arr_Refman = aux_Array_0_Refman;
  arr = aux_Array_0;
  aux_Array_0 = NULL;
  aux_Array_0_Refman = NULL;
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "used member of empty object";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    if (arr == NULL) RAISE(361, 27, "used member of empty object")
    if (arr_Refman->value == NULL) RAISE(361, 38, "used member of outdated weak reference")
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(361, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(361)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "used member of outdated weak reference";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    if (arr2 == NULL) RAISE(362, 27, "used member of empty object")
    if (arr2_Refman->value == NULL) RAISE(362, 38, "used member of outdated weak reference")
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(362, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(362)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "empty object used as sequence";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    if (arr == NULL) RAISE(363, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(363, 40, "outdated weak reference used as sequence")
    if ((0) < 0 || (0) >= (arr)->length) RAISE(363, 25, "slice index out of bounds")
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(363, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(363)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "outdated weak reference used as sequence";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    if (arr2 == NULL) RAISE(364, 29, "empty object used as sequence")
    if (arr2_Refman->value == NULL) RAISE(364, 40, "outdated weak reference used as sequence")
    if ((0) < 0 || (0) >= (arr2)->length) RAISE(364, 25, "slice index out of bounds")
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(364, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(364)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "dynamic call of empty object";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    if (top_Dynamic == NULL) RAISE(366, 28, "dynamic call of empty object")
    LUMI_err = top_Dynamic->_base._base.meth2(&(top->_base._base), top_Refman, &(top_Dynamic->_base._base));
    CHECK(366)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(366, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(366)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
  integration_M_new_fail_countdown = 1;
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "insufficient memory for object dynamic allocation";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = integration_M_f_alloc();
    CHECK(368)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(368, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(368)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
  integration_M_new_fail_countdown = 2;
  {char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "insufficient memory for managed object";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
    LUMI_err = integration_M_f_alloc();
    CHECK(370)
    
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(370, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(370)
  }
  LUMI_expected_error = LUMI_expected_error_prev;
  LUMI_err = OK;}
LUMI_cleanup:
  LUMI_owner_dec_ref(aux_Array_0_Refman);
  LUMI_dec_ref(top_Refman);
  LUMI_dec_ref(arr2_Refman);
  LUMI_owner_dec_ref(arr_Refman);
  LUMI_dec_ref(base_user_Refman);
  LUMI_dec_ref(base_var_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

Bool Sys_println_Mock_active = true;
#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "Sys.println Mock"
Returncode Sys_println_Mock(Sys* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(text_Refman);
  if (!Sys_println_Mock_active) return Sys_println(self, self_Refman, text, text_Refman);
  TEST_ASSERT(373, text != NULL && text_Refman->value != NULL)
LUMI_cleanup:
  LUMI_dec_ref(text_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "test-cover-all"
Returncode integration_M_test_cover_all(void) {
  Returncode LUMI_err = OK;
  covered_M_MiddleType mid_Var = {{0}};
  covered_M_MiddleType* mid = NULL;
  Ref_Manager* mid_Refman = NULL;
  covered_M_MiddleType_Dynamic* mid_Dynamic = &covered_M_MiddleType_dynamic;
  mid = &mid_Var;
  mid_Refman = LUMI_new_ref(mid);
  if (mid_Refman == NULL) RAISE(376, 38, "insufficient memory for managed object")
  LUMI_err = covered_M_MiddleType_new(mid, mid_Refman, mid_Dynamic);
  CHECK(376)
  if (mid_Dynamic == NULL) RAISE(377, 28, "dynamic call of empty object")
  LUMI_err = mid_Dynamic->_base.meth1(&(mid->_base), mid_Refman, &(mid_Dynamic->_base), 0, NULL, NULL);
  CHECK(377)
  if (mid_Dynamic == NULL) RAISE(378, 28, "dynamic call of empty object")
  LUMI_err = mid_Dynamic->_base.meth2(&(mid->_base), mid_Refman, &(mid_Dynamic->_base));
  CHECK(378)
  if (mid_Dynamic == NULL) RAISE(379, 28, "dynamic call of empty object")
  LUMI_err = mid_Dynamic->meth4(mid, mid_Refman, mid_Dynamic);
  CHECK(379)
  if (mid_Dynamic == NULL) RAISE(380, 28, "dynamic call of empty object")
  LUMI_err = mid_Dynamic->meth5(mid, mid_Refman, mid_Dynamic, 0, NULL, NULL);
  CHECK(380)
LUMI_cleanup:
  LUMI_dec_ref(mid_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
#define LUMI_FUNC_NAME "test-constants"
Returncode integration_M_test_constants(void) {
  Returncode LUMI_err = OK;
  TEST_ASSERT(384, integration_M_SIZE == 12)
  TEST_ASSERT(385, integration_M_LENGTH == 60)
  TEST_ASSERT(386, integration_M_TestEnum_FIRST_VALUE == 0)
  TEST_ASSERT(387, integration_M_TestEnum_ANOTHER_VALUE == 1)
  TEST_ASSERT(388, integration_M_TestEnum_VALUE2 == 2)
  TEST_ASSERT(389, integration_M_TestEnum_length == 3)
  if (integration_M_int_arr == NULL) RAISE(390, 27, "used member of empty object")
  if (integration_M_int_arr_Refman->value == NULL) RAISE(390, 38, "used member of outdated weak reference")
  TEST_ASSERT(390, integration_M_int_arr->length == 63)
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

USER_MAIN_HEADER {
  Returncode LUMI_err = OK;
  Bool LUMI_success = true;
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
#define LUMI_FILE_NAME "tests/integration-test1.4.lm"
  integration_M_deleted_refmans = NULL;
  integration_M_deleted_refmans_Refman = NULL;
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
  LUMI_success &= LUMI_run_test("test-func", integration_M_test_func);
  LUMI_success &= LUMI_run_test("test-another", integration_M_test_another);
  LUMI_success &= LUMI_run_test("test-native", integration_M_test_native);
  LUMI_success &= LUMI_run_test("test-dynamic-type-parameters", integration_M_test_dynamic_type_parameters);
  LUMI_success &= LUMI_run_test("test-simple-delete", integration_M_test_simple_delete);
  LUMI_success &= LUMI_run_test("test-complex-delete", integration_M_test_complex_delete);
  LUMI_success &= LUMI_run_test("test-assert-error-message", integration_M_test_assert_error_message);
  LUMI_success &= LUMI_run_test("test-cover-all", integration_M_test_cover_all);
  LUMI_success &= LUMI_run_test("test-constants", integration_M_test_constants);
  LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
  return LUMI_success? LUMI_err : FAIL;
}

TEST_MAIN_FUNC
