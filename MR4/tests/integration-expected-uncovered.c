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

Returncode TestStruct_get_Mock(TestStruct* self, Ref_Manager* self_Refman, Int* x, String** s, Ref_Manager** s_Refman);

Returncode f_test_int2str_Mock(Int x, String** s, Ref_Manager** s_Refman);

Returncode TestClass_dynamic_meth_Mock(TestClass* self, Ref_Manager* self_Refman, TestClass_Dynamic* self_Dynamic);

Returncode test_func(void);

Returncode test_another(void);

Returncode external(Int i, String* s, Int* io, Native* n);

Returncode external2(Native n, Bool* b);

Returncode test_native(void);

Returncode test_dynamic_type_parameters(void);

Returncode delete_Mock(Ref self);

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

Returncode new_Mock(Bool* alloc_success);

Returncode f_alloc(void);

Returncode test_assert_error_message(void);

Returncode Sys_println_Mock(Sys* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman);

Returncode test_cover_all(void);


/* types global variables */

Generic_Type_Dynamic TestStruct_dynamic = {(Dynamic_Del)TestStruct_Del};

TestClass_Dynamic TestClass_dynamic = {(Dynamic_Del)TestClass_Del, TestClass_dynamic_meth_Mock};

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

Int new_fail_countdown = 0;

int MR_file0_line_count[551] = {
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,
   0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1, 0, 0, 0,-1,-1, 0, 0, 0, 0,-1,
  -1,-1, 0, 0, 0, 0, 0, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  -1,-1, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1,-1, 0, 0,-1,-1,-1,
  -1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1,-1,-1,-1,-1,
  -1,-1,-1,-1,-1, 0, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   0, 0, 0, 0,-1,-1,-1,-1,-1,-1, 0, 0,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,
  -1, 0,-1,-1, 0,-1,-1, 0,-1,-1,-1, 0,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
  -1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1,-1, 0, 0, 0, 0,-1,-1,-1, 0, 0, 0, 0,
   0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,
  -1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,
  -1,-1,-1,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0,-1,-1, 0,-1,-1,-1,-1,-1,-1,-1,-1,
  -1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0,
  -1,-1,-1, 0, 0, 0, 0,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1,-1,-1,-1,-1, 0, 0,-1,-1, 0,-1,-1,-1,-1,
  -1, 0,-1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0,
   0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1,-1,-1, 0,-1,-1,-1,-1,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1, 0, 0, 0, 0, 0,-1,-1,-1,-1,-1,-1,-1,-1,
  -1
};
int MR_file1_line_count[381] = {
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0,-1,-1,-1, 0, 0, 0, 0,-1,-1, 0,
   0,-1,-1, 0, 0, 0, 0,-1,-1, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1,-1,-1,-1,-1,-1, 0,
  -1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1,-1, 0, 0,-1,-1,-1, 0, 0,-1,-1, 0,
  -1,-1, 0,-1,-1, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1, 0, 0,-1,-1,-1,-1,-1,
  -1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0,-1,
  -1,-1,-1,-1,-1,-1,-1, 0, 0,-1,-1, 0, 0,-1,-1, 0, 0,-1,-1, 0, 0,-1,-1,-1,-1,
  -1, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0,
  -1,-1, 0, 0,-1,-1, 0, 0, 0, 0,-1, 0,-1,-1, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0,-1, 0, 0, 0, 0,-1,-1,-1, 0,-1,-1, 0, 0, 0,-1,-1, 0,-1,-1, 0, 0,-1,-1,
   0,-1,-1, 0,-1,-1,-1,-1, 0, 0, 0, 0, 0,-1,-1, 0, 0,-1,-1, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1,-1, 0,-1,-1,
   0, 0, 0, 0, 0,-1
};
int MR_file2_line_count[30] = {
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0,-1,-1, 0, 0,-1,-1, 0, 0,-1,-1,
   0,-1,-1, 0,-1
};
File_Coverage MR_file_coverage[3] = {
  {"tests/integration-test0.4.mr", 551, MR_file0_line_count},
  {"tests/integration-test1.4.mr", 381, MR_file1_line_count},
  {"tests/integration-test2.4.mr", 30, MR_file2_line_count}
};


/* types methods body */

#define MR_FILE_NAME "tests/integration-test0.4.mr"
#define MR_FUNC_NAME "TestStruct.new"
Returncode TestStruct_new(TestStruct* self, Ref_Manager* self_Refman, Int x, String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  TestStruct* aux_TestStruct_0 = NULL;
  Ref_Manager* aux_TestStruct_0_Refman = NULL;
  MR_inc_ref(s_Refman);
  ++MR_file_coverage[0].line_count[200];
  if (self == NULL) RAISE(200, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(200, 38, "used member of outdated weak reference")
  self->num = x;
  ++MR_file_coverage[0].line_count[201];
  if (self == NULL) RAISE(201, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(201, 38, "used member of outdated weak reference")
  MR_dec_ref(self->text_Refman);
  self->text_Refman = s_Refman;
  MR_inc_ref(self->text_Refman);
  self->text = s;
  ++MR_file_coverage[0].line_count[202];
  if (x < 0) {
      ++MR_file_coverage[0].line_count[203];
      aux_TestStruct_0 = MR_alloc(sizeof(TestStruct));
      if (aux_TestStruct_0 == NULL) RAISE(203, 49, "insufficient memory for object dynamic allocation")
      aux_TestStruct_0_Refman = MR_new_ref(aux_TestStruct_0);
      if (aux_TestStruct_0_Refman == NULL) RAISE(203, 38, "insufficient memory for managed object")
      CHECK(203, TestStruct_new(aux_TestStruct_0, aux_TestStruct_0_Refman, x + 1, s, s_Refman) )
      if (self == NULL) RAISE(203, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(203, 38, "used member of outdated weak reference")
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
  ++MR_file_coverage[0].line_count[210];
  if (self == NULL) RAISE(210, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(210, 38, "used member of outdated weak reference")
  *x = self->num;
  ++MR_file_coverage[0].line_count[211];
  if (self == NULL) RAISE(211, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(211, 38, "used member of outdated weak reference")
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
  ++MR_file_coverage[0].line_count[214];
  if (self == NULL) RAISE(214, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(214, 38, "used member of outdated weak reference")
  CHECK(214, Sys_println_Mock(sys, sys_Refman, self->text, self->text_Refman) )
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
  ++MR_file_coverage[0].line_count[223];
  if (self == NULL) RAISE(223, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(223, 38, "used member of outdated weak reference")
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
  ++MR_file_coverage[0].line_count[226];
  if (self == NULL) RAISE(226, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(226, 38, "used member of outdated weak reference")
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
  ++MR_file_coverage[0].line_count[229];
  if (self == NULL) RAISE(229, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(229, 38, "used member of outdated weak reference")
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
  ++MR_file_coverage[0].line_count[232];
  if (self == NULL) RAISE(232, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(232, 38, "used member of outdated weak reference")
  CHECK(232, Sys_println_Mock(sys, sys_Refman, self->text, self->text_Refman) )
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
  ++MR_file_coverage[0].line_count[358];
  x = item;
  x_Refman = item_Refman;
  MR_inc_ref(x_Refman);
  x_Dynamic = item_Dynamic;
  ++MR_file_coverage[0].line_count[359];
  if (self == NULL) RAISE(359, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(359, 38, "used member of outdated weak reference")
  MR_dec_ref(self->item_Refman);
  self->item_Refman = x_Refman;
  MR_inc_ref(self->item_Refman);
  self->item_Dynamic = x_Dynamic;
  self->item = x;
  ++MR_file_coverage[0].line_count[360];
  if (self == NULL) RAISE(360, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(360, 38, "used member of outdated weak reference")
  MR_dec_ref(self->arr_Refman);
  self->arr_Refman = arr_Refman;
  MR_inc_ref(self->arr_Refman);
  self->arr = arr;
  ++MR_file_coverage[0].line_count[361];
  d = MR_alloc(sizeof(Data));
  if (d == NULL) RAISE(361, 49, "insufficient memory for object dynamic allocation")
  d_Refman = MR_new_ref(d);
  if (d_Refman == NULL) RAISE(361, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[362];
  if (self == NULL) RAISE(362, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(362, 38, "used member of outdated weak reference")
  if (d == NULL) RAISE(362, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(362, 38, "used member of outdated weak reference")
  MR_dec_ref(d->item_Refman);
  d->item_Refman = self->item_Refman;
  MR_inc_ref(d->item_Refman);
  d->item_Dynamic = self->item_Dynamic;
  d->item = self->item;
  ++MR_file_coverage[0].line_count[363];
  if (d == NULL) RAISE(363, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(363, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(363, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(363, 38, "used member of outdated weak reference")
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
  ++MR_file_coverage[0].line_count[366];
  if (self == NULL) RAISE(366, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(366, 38, "used member of outdated weak reference")
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
  ++MR_file_coverage[0].line_count[441];
  if (self == NULL) RAISE(441, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(441, 38, "used member of outdated weak reference")
  MR_dec_ref(self->value_Refman);
  self->value_Refman = value_Refman;
  MR_inc_ref(self->value_Refman);
  self->value_Dynamic = value_Dynamic;
  self->value = value;
  ++MR_file_coverage[0].line_count[442];
  if (self == NULL) RAISE(442, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(442, 38, "used member of outdated weak reference")
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
  ++MR_file_coverage[0].line_count[445];
  if (self == NULL) RAISE(445, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(445, 38, "used member of outdated weak reference")
  aux_ContainerIterator_0 = MR_alloc(sizeof(ContainerIterator));
  if (aux_ContainerIterator_0 == NULL) RAISE(445, 49, "insufficient memory for object dynamic allocation")
  aux_ContainerIterator_0_Refman = MR_new_ref(aux_ContainerIterator_0);
  if (aux_ContainerIterator_0_Refman == NULL) RAISE(445, 38, "insufficient memory for managed object")
  CHECK(445, ContainerIterator_new(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman, self->next, self->next_Refman) )
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
  ++MR_file_coverage[0].line_count[451];
  if (self == NULL) RAISE(451, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(451, 38, "used member of outdated weak reference")
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
  ++MR_file_coverage[0].line_count[454];
  if (self == NULL) RAISE(454, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(454, 38, "used member of outdated weak reference")
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
  ++MR_file_coverage[0].line_count[457];
  if (self == NULL) RAISE(457, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(457, 38, "used member of outdated weak reference")
  if (self->curr == NULL) RAISE(457, 27, "used member of empty object")
  if (self->curr_Refman->value == NULL) RAISE(457, 38, "used member of outdated weak reference")
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
  ++MR_file_coverage[0].line_count[460];
  if (self == NULL) RAISE(460, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(460, 38, "used member of outdated weak reference")
  if (self->curr == NULL) RAISE(460, 27, "used member of empty object")
  if (self->curr_Refman->value == NULL) RAISE(460, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(460, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(460, 38, "used member of outdated weak reference")
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
  ++MR_file_coverage[0].line_count[520];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(520, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 2;
  aux_String_0_Var.length = 1;
  aux_String_0_Var.values = "$";
  CHECK(520, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
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
  ++MR_file_coverage[0].line_count[525];
  if (self == NULL) RAISE(525, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(525, 38, "used member of outdated weak reference")
  x = &(self->x);
  x_Refman = self_Refman;
  MR_inc_ref(x_Refman);
  x_Dynamic = &ComplexField_dynamic;
  ++MR_file_coverage[0].line_count[526];
  if (self == NULL) RAISE(526, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(526, 38, "used member of outdated weak reference")
  MR_dec_ref(x_Refman);
  x_Refman = self_Refman;
  MR_inc_ref(x_Refman);
  x_Dynamic = &ComplexField_dynamic;
  x = &(self->x);
  ++MR_file_coverage[0].line_count[527];
  if (x_Dynamic == NULL) RAISE(527, 28, "dynamic call of empty object")
  CHECK(527, x_Dynamic->meth(x, x_Refman, x_Dynamic) )
  ++MR_file_coverage[0].line_count[528];
  if (self == NULL) RAISE(528, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(528, 38, "used member of outdated weak reference")
  CHECK(528, ComplexField_meth(&(self->x), self_Refman, &ComplexField_dynamic) )
  ++MR_file_coverage[0].line_count[529];
  if (self == NULL) RAISE(529, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(529, 38, "used member of outdated weak reference")
  CHECK(529, ComplexField_meth(&(self->x), self_Refman, &ComplexField_dynamic) )
  ++MR_file_coverage[0].line_count[530];
  if (self == NULL) RAISE(530, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(530, 38, "used member of outdated weak reference")
  x2 = self->x.x;
  x2_Refman = self->x.x_Refman;
  MR_inc_ref(x2_Refman);
  x2_Dynamic = self->x.x_Dynamic;
  ++MR_file_coverage[0].line_count[531];
  if (self == NULL) RAISE(531, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(531, 38, "used member of outdated weak reference")
  MR_dec_ref(x2_Refman);
  x2_Refman = self->x.x_Refman;
  MR_inc_ref(x2_Refman);
  x2_Dynamic = self->x.x_Dynamic;
  x2 = self->x.x;
  ++MR_file_coverage[0].line_count[532];
  if (x2_Dynamic == NULL) RAISE(532, 28, "dynamic call of empty object")
  CHECK(532, x2_Dynamic->meth(x2, x2_Refman, x2_Dynamic) )
  ++MR_file_coverage[0].line_count[533];
  if (self->x.x_Dynamic == NULL) RAISE(533, 28, "dynamic call of empty object")
  if (self == NULL) RAISE(533, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(533, 38, "used member of outdated weak reference")
  CHECK(533, self->x.x_Dynamic->meth(self->x.x, self->x.x_Refman, self->x.x_Dynamic) )
  ++MR_file_coverage[0].line_count[534];
  if (self == NULL) RAISE(534, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(534, 38, "used member of outdated weak reference")
  CHECK(534, ComplexField_meth(self->x.x, self->x.x_Refman, self->x.x_Dynamic) )
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
  ++MR_file_coverage[1].line_count[49];
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
  ++MR_file_coverage[1].line_count[52];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(52, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "BaseType.meth0";
  CHECK(52, Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
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
  ++MR_file_coverage[1].line_count[55];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(55, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "BaseType.meth1";
  CHECK(55, Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
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
  ++MR_file_coverage[1].line_count[58];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(58, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "BaseType.meth2";
  CHECK(58, Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
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
  ++MR_file_coverage[1].line_count[61];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(61, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "BaseType.meth3";
  CHECK(61, Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
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
  ++MR_file_coverage[2].line_count[13];
  CHECK(13, BaseType_new(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
  ++MR_file_coverage[2].line_count[14];
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
  ++MR_file_coverage[2].line_count[17];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(17, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "MiddleType.meth1";
  CHECK(17, Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  ++MR_file_coverage[2].line_count[18];
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
  ++MR_file_coverage[2].line_count[21];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(21, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "MiddleType.meth2";
  CHECK(21, Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  ++MR_file_coverage[2].line_count[22];
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
  ++MR_file_coverage[2].line_count[25];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(25, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "MiddleType.meth4";
  CHECK(25, Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
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
  ++MR_file_coverage[2].line_count[28];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(28, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "MiddleType.meth5";
  CHECK(28, Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
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
  ++MR_file_coverage[1].line_count[13];
  CHECK(13, MiddleType_new(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
  ++MR_file_coverage[1].line_count[14];
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
  ++MR_file_coverage[1].line_count[18];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(18, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 14;
  aux_String_0_Var.length = 13;
  aux_String_0_Var.values = "TopType.meth2";
  CHECK(18, Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  ++MR_file_coverage[1].line_count[19];
  CHECK(19, MiddleType_meth2(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
  ++MR_file_coverage[1].line_count[20];
  CHECK(20, MiddleType_meth2(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
  ++MR_file_coverage[1].line_count[21];
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
  ++MR_file_coverage[1].line_count[24];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(24, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 14;
  aux_String_0_Var.length = 13;
  aux_String_0_Var.values = "TopType.meth3";
  CHECK(24, Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  ++MR_file_coverage[1].line_count[25];
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
  ++MR_file_coverage[1].line_count[28];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(28, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 14;
  aux_String_0_Var.length = 13;
  aux_String_0_Var.values = "TopType.meth5";
  CHECK(28, Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  ++MR_file_coverage[1].line_count[29];
  CHECK(29, MiddleType_meth5(&(self->_base), self_Refman, &(self_Dynamic->_base), n, s, s_Refman) )
  ++MR_file_coverage[1].line_count[30];
  CHECK(30, MiddleType_meth1(NULL, NULL, NULL, n, s, s_Refman) )
  ++MR_file_coverage[1].line_count[31];
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
  ++MR_file_coverage[1].line_count[34];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(34, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 14;
  aux_String_0_Var.length = 13;
  aux_String_0_Var.values = "TopType.meth6";
  CHECK(34, Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  ++MR_file_coverage[1].line_count[35];
  if (self == NULL) RAISE(35, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(35, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(35, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(35, 38, "used member of outdated weak reference")
  self->_base.num_mid = self->_base._base.num_base;
  ++MR_file_coverage[1].line_count[36];
  if (self == NULL) RAISE(36, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(36, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(36, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(36, 38, "used member of outdated weak reference")
  MR_dec_ref(self->top_base_ref_Refman);
  self->top_base_ref_Refman = self->top_mid_ref_Refman;
  MR_inc_ref(self->top_base_ref_Refman);
  self->top_base_ref_Dynamic = &(self->top_mid_ref_Dynamic->_base);
  self->top_base_ref = &(self->top_mid_ref->_base);
  ++MR_file_coverage[1].line_count[37];
  if (self == NULL) RAISE(37, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(37, 38, "used member of outdated weak reference")
  MR_dec_ref(self->top_base_ref_Refman);
  self->top_base_ref_Refman = self_Refman;
  MR_inc_ref(self->top_base_ref_Refman);
  self->top_base_ref_Dynamic = &(self_Dynamic->_base._base);
  self->top_base_ref = &(self->_base._base);
  ++MR_file_coverage[1].line_count[38];
  mt = &(self->_base);
  mt_Refman = self_Refman;
  MR_inc_ref(mt_Refman);
  mt_Dynamic = &(self_Dynamic->_base);
  ++MR_file_coverage[1].line_count[39];
  bt = &(mt->_base);
  bt_Refman = mt_Refman;
  MR_inc_ref(bt_Refman);
  bt_Dynamic = &(mt_Dynamic->_base);
  ++MR_file_coverage[1].line_count[40];
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
  ++MR_file_coverage[1].line_count[172];
  if (self == NULL) RAISE(172, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(172, 38, "used member of outdated weak reference")
  self->ref = ref;
  ++MR_file_coverage[1].line_count[173];
  if (self == NULL) RAISE(173, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(173, 38, "used member of outdated weak reference")
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
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  ++MR_file_coverage[0].line_count[24];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(24, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 23;
  aux_String_0_Var.length = 22;
  aux_String_0_Var.values = "I am a simple function";
  CHECK(24, Sys_println_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  ++MR_file_coverage[0].line_count[25];
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = MR_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(28, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 25;
  aux_String_1_Var.length = 24;
  aux_String_1_Var.values = "I am a multiline\nstring\n";
  CHECK(25, Sys_print(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_1_Refman);
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
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  ++MR_file_coverage[0].line_count[38];
  *i = (((((((0 + 9630) + -9630) + 07520) + -07520) + 0xfda940) + -0xfda940) + 0xFDA940) + -0xFDA940;
  ++MR_file_coverage[0].line_count[40];
  *c = (((('a' + '\'') + '\n') + '\x0f') + '\xA9') + '\270';
  ++MR_file_coverage[0].line_count[41];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(41, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  MR_dec_ref(*s_Refman);
  *s_Refman = aux_String_0_Refman;
  MR_inc_ref(*s_Refman);
  *s = aux_String_0;
  ++MR_file_coverage[0].line_count[42];
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = MR_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(44, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 12;
  aux_String_1_Var.length = 11;
  aux_String_1_Var.values = "some\nstring";
  MR_dec_ref(*s_Refman);
  *s_Refman = aux_String_1_Refman;
  MR_inc_ref(*s_Refman);
  *s = aux_String_1;
  ++MR_file_coverage[0].line_count[45];
  MR_dec_ref(*t_Refman);
  *t_Refman = NULL;
  MR_inc_ref(*t_Refman);
  *t = NULL;
  ++MR_file_coverage[0].line_count[46];
  MR_dec_ref(*d_Refman);
  *d_Refman = NULL;
  MR_inc_ref(*d_Refman);
  *d_Dynamic = NULL;
  *d = NULL;
  ++MR_file_coverage[0].line_count[47];
  *f = NULL;
  ++MR_file_coverage[0].line_count[48];
  if (*f == NULL) RAISE(48, 21, "empty function called")
  CHECK(48, (*f)() )
MR_cleanup:
  MR_dec_ref(aux_String_1_Refman);
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
  ++MR_file_coverage[0].line_count[52];
  if (t == NULL) RAISE(52, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(52, 38, "used member of outdated weak reference")
  if (t->ts == NULL) RAISE(52, 27, "used member of empty object")
  if (t->ts_Refman->value == NULL) RAISE(52, 38, "used member of outdated weak reference")
  if (t->ts->ts == NULL) RAISE(52, 27, "used member of empty object")
  if (t->ts->ts_Refman->value == NULL) RAISE(52, 38, "used member of outdated weak reference")
  if (t == NULL) RAISE(52, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(52, 38, "used member of outdated weak reference")
  if (t->ts == NULL) RAISE(52, 27, "used member of empty object")
  if (t->ts_Refman->value == NULL) RAISE(52, 38, "used member of outdated weak reference")
  if (*to == NULL) RAISE(52, 27, "used member of empty object")
  if ((*to_Refman)->value == NULL) RAISE(52, 38, "used member of outdated weak reference")
  if (t == NULL) RAISE(52, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(52, 38, "used member of outdated weak reference")
  t->num = ((*to)->num + t->ts->num) + t->ts->ts->num;
  ++MR_file_coverage[0].line_count[53];
  if (t == NULL) RAISE(53, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(53, 38, "used member of outdated weak reference")
  if (*to == NULL) RAISE(53, 27, "used member of empty object")
  if ((*to_Refman)->value == NULL) RAISE(53, 38, "used member of outdated weak reference")
  (*to)->num = t->num;
  ++MR_file_coverage[0].line_count[54];
  if (t == NULL) RAISE(54, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(54, 38, "used member of outdated weak reference")
  if (t->ts == NULL) RAISE(54, 27, "used member of empty object")
  if (t->ts_Refman->value == NULL) RAISE(54, 38, "used member of outdated weak reference")
  if (t->ts->ts == NULL) RAISE(54, 27, "used member of empty object")
  if (t->ts->ts_Refman->value == NULL) RAISE(54, 38, "used member of outdated weak reference")
  t->ts->ts->num = 4;
  ++MR_file_coverage[0].line_count[55];
  if (t == NULL) RAISE(55, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(55, 38, "used member of outdated weak reference")
  t->fun = f_test_void;
  ++MR_file_coverage[0].line_count[56];
  if (t == NULL) RAISE(56, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(56, 38, "used member of outdated weak reference")
  if (t->fun == NULL) RAISE(56, 21, "empty function called")
  CHECK(56, t->fun() )
  ++MR_file_coverage[0].line_count[57];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(57, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 1;
  aux_String_0_Var.length = 0;
  aux_String_0_Var.values = "";
  CHECK(57, TestStruct_new(t, t_Refman, 0, aux_String_0, aux_String_0_Refman) )
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
  ++MR_file_coverage[0].line_count[77];
  aux_Array_0 = &aux_Array_0_Var;
  aux_Array_0_Refman = MR_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(77, 38, "insufficient memory for managed object")
  aux_Array_0_Var.length = 2;
  aux_Array_0_Var.values = (Byte*)((arrs)->values) + (4);
  if (arrs == NULL) RAISE(77, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(77, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (2) < 0 || (4) + (2) > (arrs)->length) RAISE(77, 25, "slice index out of bounds")
  if (aux_Array_0 == NULL) RAISE(77, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(77, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (aux_Array_0)->length) RAISE(77, 25, "slice index out of bounds")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(77, 38, "insufficient memory for managed object")
  aux_String_0_Var.length = 3;
  aux_String_0_Var.max_length = aux_String_0_Var.length + 1;
  aux_String_0_Var.values = ((((String*)((aux_Array_0)->values)) + 4))->values + (1);
  if (((String*)((aux_Array_0)->values)) + 4 == NULL) RAISE(77, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(77, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (3) < 0 || (1) + (3) > ((((String*)((aux_Array_0)->values)) + 4))->length) RAISE(77, 25, "slice index out of bounds")
  if (aux_String_0 == NULL) RAISE(77, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(77, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (aux_String_0)->length) RAISE(77, 25, "slice index out of bounds")
  if (arrs == NULL) RAISE(77, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(77, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) >= (arrs)->length) RAISE(77, 25, "slice index out of bounds")
  if (((String*)((arrs)->values)) + 3 == NULL) RAISE(77, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(77, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= ((((String*)((arrs)->values)) + 3))->length) RAISE(77, 25, "slice index out of bounds")
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = MR_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(77, 38, "insufficient memory for managed object")
  aux_String_1_Var.length = 7;
  aux_String_1_Var.max_length = aux_String_1_Var.length + 1;
  aux_String_1_Var.values = (s)->values + (4);
  if (s == NULL) RAISE(77, 29, "empty object used as sequence")
  if (s_Refman->value == NULL) RAISE(77, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (7) < 0 || (4) + (7) > (s)->length) RAISE(77, 25, "slice index out of bounds")
  if (aux_String_1 == NULL) RAISE(77, 29, "empty object used as sequence")
  if (s_Refman->value == NULL) RAISE(77, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (aux_String_1)->length) RAISE(77, 25, "slice index out of bounds")
  if (s == NULL) RAISE(77, 29, "empty object used as sequence")
  if (s_Refman->value == NULL) RAISE(77, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (s)->length) RAISE(77, 25, "slice index out of bounds")
  *c = (((((s)->values)[2]) + (((aux_String_1)->values)[2])) + ((((((String*)((arrs)->values)) + 3))->values)[2])) + (((aux_String_0)->values)[0]);
  ++MR_file_coverage[0].line_count[78];
  aux_Array_1 = &aux_Array_1_Var;
  aux_Array_1_Refman = MR_new_ref(aux_Array_1);
  if (aux_Array_1_Refman == NULL) RAISE(79, 38, "insufficient memory for managed object")
  aux_Array_1_Var.length = 3;
  aux_Array_1_Var.values = (Byte*)((arri)->values) + (3);
  if (arri == NULL) RAISE(79, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(79, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) < 0 || (3) + (3) > (arri)->length) RAISE(79, 25, "slice index out of bounds")
  aux_Array_2 = &aux_Array_2_Var;
  aux_Array_2_Refman = MR_new_ref(aux_Array_2);
  if (aux_Array_2_Refman == NULL) RAISE(79, 38, "insufficient memory for managed object")
  aux_Array_2_Var.length = 2;
  aux_Array_2_Var.values = (Byte*)((aux_Array_1)->values) + (1);
  if (aux_Array_1 == NULL) RAISE(79, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(79, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (2) < 0 || (1) + (2) > (aux_Array_1)->length) RAISE(79, 25, "slice index out of bounds")
  if (aux_Array_2 == NULL) RAISE(79, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(79, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (aux_Array_2)->length) RAISE(79, 25, "slice index out of bounds")
  aux_Array_3 = &aux_Array_3_Var;
  aux_Array_3_Refman = MR_new_ref(aux_Array_3);
  if (aux_Array_3_Refman == NULL) RAISE(78, 38, "insufficient memory for managed object")
  aux_Array_3_Var.length = 4;
  aux_Array_3_Var.values = (Byte*)((arrt)->values) + (2);
  if (arrt == NULL) RAISE(78, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(78, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arrt)->length) RAISE(78, 25, "slice index out of bounds")
  if (aux_Array_3 == NULL) RAISE(78, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(78, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (aux_Array_3)->length) RAISE(78, 25, "slice index out of bounds")
  if (((TestStruct*)((aux_Array_3)->values)) + 1 == NULL) RAISE(78, 27, "used member of empty object")
  if (arrt_Refman->value == NULL) RAISE(78, 38, "used member of outdated weak reference")
  if (arrt == NULL) RAISE(78, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(78, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(78, 25, "slice index out of bounds")
  if (((TestStruct*)((arrt)->values)) + 4 == NULL) RAISE(78, 27, "used member of empty object")
  if (arrt_Refman->value == NULL) RAISE(78, 38, "used member of outdated weak reference")
  if (arri == NULL) RAISE(78, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(78, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (arri)->length) RAISE(78, 25, "slice index out of bounds")
  if (arri == NULL) RAISE(78, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(78, 40, "outdated weak reference used as sequence")
  if ((((*i) + 3) - (((Int*)((arri)->values))[2])) < 0 || (((*i) + 3) - (((Int*)((arri)->values))[2])) >= (arri)->length) RAISE(78, 25, "slice index out of bounds")
  *i = (((((Int*)((arri)->values))[((*i) + 3) - (((Int*)((arri)->values))[2])]) + (((TestStruct*)((arrt)->values)) + 4)->num) + (((TestStruct*)((aux_Array_3)->values)) + 1)->num) + (((Int*)((aux_Array_2)->values))[1]);
  ++MR_file_coverage[0].line_count[80];
  aux_Array_4 = &aux_Array_4_Var;
  aux_Array_4_Refman = MR_new_ref(aux_Array_4);
  if (aux_Array_4_Refman == NULL) RAISE(80, 38, "insufficient memory for managed object")
  aux_Array_4_Var.length = 4;
  aux_Array_4_Var.values = (Byte*)((arri)->values) + (2);
  if (arri == NULL) RAISE(80, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(80, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (4) < 0 || (2) + (4) > (arri)->length) RAISE(80, 25, "slice index out of bounds")
  if (aux_Array_4 == NULL) RAISE(80, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(80, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (aux_Array_4)->length) RAISE(80, 25, "slice index out of bounds")
  aux_Array_5 = &aux_Array_5_Var;
  aux_Array_5_Refman = MR_new_ref(aux_Array_5);
  if (aux_Array_5_Refman == NULL) RAISE(80, 38, "insufficient memory for managed object")
  aux_Array_5_Var.length = 5 * ((*i) - 1);
  aux_Array_5_Var.values = (Byte*)((arri)->values) + ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1]));
  if (arri == NULL) RAISE(80, 29, "empty object used as sequence")
  if (arri_Refman->value == NULL) RAISE(80, 40, "outdated weak reference used as sequence")
  if (((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1])) < 0 || (5 * ((*i) - 1)) < 0 || ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1])) + (5 * ((*i) - 1)) > (arri)->length) RAISE(80, 25, "slice index out of bounds")
  MR_dec_ref(*arrio_Refman);
  *arrio_Refman = arri_Refman;
  MR_inc_ref(*arrio_Refman);
  *arrio = aux_Array_5;
  ++MR_file_coverage[0].line_count[81];
  if (arrs == NULL) RAISE(81, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(81, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrs)->length) RAISE(81, 25, "slice index out of bounds")
  MR_dec_ref(s_Refman);
  s_Refman = arrs_Refman;
  MR_inc_ref(s_Refman);
  s = ((String*)((arrs)->values)) + 4;
  ++MR_file_coverage[0].line_count[82];
  aux_Array_6 = &aux_Array_6_Var;
  aux_Array_6_Refman = MR_new_ref(aux_Array_6);
  if (aux_Array_6_Refman == NULL) RAISE(82, 38, "insufficient memory for managed object")
  aux_Array_6_Var.length = 7;
  aux_Array_6_Var.values = (Byte*)((arrs)->values) + (2);
  if (arrs == NULL) RAISE(82, 29, "empty object used as sequence")
  if (arrs_Refman->value == NULL) RAISE(82, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrs)->length) RAISE(82, 25, "slice index out of bounds")
  MR_dec_ref(*arrso_Refman);
  *arrso_Refman = arrs_Refman;
  MR_inc_ref(*arrso_Refman);
  *arrso = aux_Array_6;
  ++MR_file_coverage[0].line_count[83];
  if (arrt == NULL) RAISE(83, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(83, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrt)->length) RAISE(83, 25, "slice index out of bounds")
  MR_dec_ref(*t_Refman);
  *t_Refman = arrt_Refman;
  MR_inc_ref(*t_Refman);
  *t = ((TestStruct*)((arrt)->values)) + 4;
  ++MR_file_coverage[0].line_count[84];
  aux_Array_7 = &aux_Array_7_Var;
  aux_Array_7_Refman = MR_new_ref(aux_Array_7);
  if (aux_Array_7_Refman == NULL) RAISE(84, 38, "insufficient memory for managed object")
  aux_Array_7_Var.length = 7;
  aux_Array_7_Var.values = (Byte*)((arrt)->values) + (2);
  if (arrt == NULL) RAISE(84, 29, "empty object used as sequence")
  if (arrt_Refman->value == NULL) RAISE(84, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrt)->length) RAISE(84, 25, "slice index out of bounds")
  MR_dec_ref(*arrto_Refman);
  *arrto_Refman = arrt_Refman;
  MR_inc_ref(*arrto_Refman);
  *arrto = aux_Array_7;
  ++MR_file_coverage[0].line_count[85];
  if (arrd == NULL) RAISE(85, 29, "empty object used as sequence")
  if (arrd_Refman->value == NULL) RAISE(85, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrd)->length) RAISE(85, 25, "slice index out of bounds")
  MR_dec_ref(*d_Refman);
  *d_Refman = arrd_Refman;
  MR_inc_ref(*d_Refman);
  *d_Dynamic = &TestClass_dynamic;
  *d = ((TestClass*)((arrd)->values)) + 4;
  ++MR_file_coverage[0].line_count[86];
  aux_Array_8 = &aux_Array_8_Var;
  aux_Array_8_Refman = MR_new_ref(aux_Array_8);
  if (aux_Array_8_Refman == NULL) RAISE(86, 38, "insufficient memory for managed object")
  aux_Array_8_Var.length = 7;
  aux_Array_8_Var.values = (Byte*)((arrd)->values) + (2);
  if (arrd == NULL) RAISE(86, 29, "empty object used as sequence")
  if (arrd_Refman->value == NULL) RAISE(86, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrd)->length) RAISE(86, 25, "slice index out of bounds")
  MR_dec_ref(*arrdo_Refman);
  *arrdo_Refman = arrd_Refman;
  MR_inc_ref(*arrdo_Refman);
  *arrdo = aux_Array_8;
  ++MR_file_coverage[0].line_count[87];
  if (arrf == NULL) RAISE(87, 29, "empty object used as sequence")
  if (arrf_Refman->value == NULL) RAISE(87, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(87, 25, "slice index out of bounds")
  *f = ((Returncode (**)(void))((arrf)->values))[4];
  ++MR_file_coverage[0].line_count[88];
  aux_Array_9 = &aux_Array_9_Var;
  aux_Array_9_Refman = MR_new_ref(aux_Array_9);
  if (aux_Array_9_Refman == NULL) RAISE(88, 38, "insufficient memory for managed object")
  aux_Array_9_Var.length = 7;
  aux_Array_9_Var.values = (Byte*)((arrf)->values) + (2);
  if (arrf == NULL) RAISE(88, 29, "empty object used as sequence")
  if (arrf_Refman->value == NULL) RAISE(88, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (7) < 0 || (2) + (7) > (arrf)->length) RAISE(88, 25, "slice index out of bounds")
  MR_dec_ref(*arrfo_Refman);
  *arrfo_Refman = arrf_Refman;
  MR_inc_ref(*arrfo_Refman);
  *arrfo = aux_Array_9;
  ++MR_file_coverage[0].line_count[89];
  if (arrf == NULL) RAISE(89, 29, "empty object used as sequence")
  if (arrf_Refman->value == NULL) RAISE(89, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arrf)->length) RAISE(89, 25, "slice index out of bounds")
  if (((Returncode (**)(void))((arrf)->values))[4] == NULL) RAISE(89, 21, "empty function called")
  CHECK(89, (((Returncode (**)(void))((arrf)->values))[4])() )
  ++MR_file_coverage[0].line_count[90];
  if (*arrfo == NULL) RAISE(90, 29, "empty object used as sequence")
  if ((*arrfo_Refman)->value == NULL) RAISE(90, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= ((*arrfo))->length) RAISE(90, 25, "slice index out of bounds")
  if (((Returncode (**)(void))(((*arrfo))->values))[4] == NULL) RAISE(90, 21, "empty function called")
  CHECK(90, (((Returncode (**)(void))(((*arrfo))->values))[4])() )
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
  ++MR_file_coverage[0].line_count[95];
  *i = (- x) + (- (- (- y)));
  ++MR_file_coverage[0].line_count[96];
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
  ++MR_file_coverage[0].line_count[102];
  ++MR_file_coverage[0].line_count[103];
  ++MR_file_coverage[0].line_count[104];
  ++MR_file_coverage[0].line_count[105];
  ++MR_file_coverage[0].line_count[106];
  ++MR_file_coverage[0].line_count[107];
  tv = &tv_Var;
  tv_Refman = MR_new_ref(tv);
  if (tv_Refman == NULL) RAISE(107, 38, "insufficient memory for managed object")
  CHECK(107, TestStruct_new(tv, tv_Refman, 0, NULL, NULL) )
  ++MR_file_coverage[0].line_count[108];
  dv = &dv_Var;
  dv_Refman = MR_new_ref(dv);
  if (dv_Refman == NULL) RAISE(108, 38, "insufficient memory for managed object")
  CHECK(108, TestClass_new(dv, dv_Refman, dv_Dynamic) )
  ++MR_file_coverage[0].line_count[109];
  sv = &sv_Var;
  sv_Var.values = sv_Values;
  sv_Refman = MR_new_ref(sv);
  if (sv_Refman == NULL) RAISE(109, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[110];
  ++MR_file_coverage[0].line_count[111];
  ia = &ia_Var;
  ia_Var.values = ia_Values;
  ia_Refman = MR_new_ref(ia);
  if (ia_Refman == NULL) RAISE(111, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[112];
  ta = &ta_Var;
  ta_Var.values = ta_Values;
  ta_Refman = MR_new_ref(ta);
  if (ta_Refman == NULL) RAISE(112, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[113];
  da = &da_Var;
  da_Var.values = da_Values;
  da_Refman = MR_new_ref(da);
  if (da_Refman == NULL) RAISE(113, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[114];
  sa = &sa_Var;
  sa_Var.values = sa_Values;
  MR_set_var_string_array(12, 7, sa, sa_Chars);
  sa_Refman = MR_new_ref(sa);
  if (sa_Refman == NULL) RAISE(114, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[115];
  fa = &fa_Var;
  fa_Var.values = fa_Values;
  fa_Refman = MR_new_ref(fa);
  if (fa_Refman == NULL) RAISE(115, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[116];
  tn = MR_alloc(sizeof(TestStruct));
  if (tn == NULL) RAISE(116, 49, "insufficient memory for object dynamic allocation")
  tn_Refman = MR_new_ref(tn);
  if (tn_Refman == NULL) RAISE(116, 38, "insufficient memory for managed object")
  CHECK(116, TestStruct_new(tn, tn_Refman, 0, NULL, NULL) )
  ++MR_file_coverage[0].line_count[117];
  dn = MR_alloc(sizeof(TestClass));
  if (dn == NULL) RAISE(117, 49, "insufficient memory for object dynamic allocation")
  dn_Refman = MR_new_ref(dn);
  if (dn_Refman == NULL) RAISE(117, 38, "insufficient memory for managed object")
  CHECK(117, TestClass_new(dn, dn_Refman, dn_Dynamic) )
  ++MR_file_coverage[0].line_count[118];
  if (arr == NULL) RAISE(118, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(118, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(118, 25, "slice index out of bounds")
  sn = MR_new_string(((Int*)((arr)->values))[0]);
  if (sn == NULL) RAISE(118, 49, "insufficient memory for object dynamic allocation")
  sn_Refman = MR_new_ref(sn);
  if (sn_Refman == NULL) RAISE(118, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[119];
  if (arr == NULL) RAISE(119, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(119, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(119, 25, "slice index out of bounds")
  ian = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if (ian == NULL) RAISE(119, 49, "insufficient memory for object dynamic allocation")
  ian_Refman = MR_new_ref(ian);
  if (ian_Refman == NULL) RAISE(119, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[120];
  if (arr == NULL) RAISE(120, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(120, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(120, 25, "slice index out of bounds")
  tan = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestStruct));
  if (tan == NULL) RAISE(120, 49, "insufficient memory for object dynamic allocation")
  tan_Refman = MR_new_ref(tan);
  if (tan_Refman == NULL) RAISE(120, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[121];
  if (arr == NULL) RAISE(121, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(121, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(121, 25, "slice index out of bounds")
  dan = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestClass));
  if (dan == NULL) RAISE(121, 49, "insufficient memory for object dynamic allocation")
  dan_Refman = MR_new_ref(dan);
  if (dan_Refman == NULL) RAISE(121, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[122];
  if (arr == NULL) RAISE(122, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(122, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(122, 25, "slice index out of bounds")
  if (arr == NULL) RAISE(122, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(122, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (arr)->length) RAISE(122, 25, "slice index out of bounds")
  san = MR_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]);
  if (san == NULL) RAISE(122, 49, "insufficient memory for object dynamic allocation")
  san_Refman = MR_new_ref(san);
  if (san_Refman == NULL) RAISE(122, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[123];
  if (arr == NULL) RAISE(123, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(123, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(123, 25, "slice index out of bounds")
  sfn = MR_new_array(((Int*)((arr)->values))[0], sizeof(Func));
  if (sfn == NULL) RAISE(123, 49, "insufficient memory for object dynamic allocation")
  sfn_Refman = MR_new_ref(sfn);
  if (sfn_Refman == NULL) RAISE(123, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[124];
  if (arr == NULL) RAISE(124, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(124, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(124, 25, "slice index out of bounds")
  ix = ((Int*)((arr)->values))[0];
  ++MR_file_coverage[0].line_count[125];
  si = text;
  si_Refman = text_Refman;
  MR_inc_ref(si_Refman);
  ++MR_file_coverage[0].line_count[126];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(126, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  isv = &isv_Var;
  isv_Var.values = isv_Values;
  isv_Refman = MR_new_ref(isv);
  if (isv_Refman == NULL) RAISE(126, 38, "insufficient memory for managed object")
  CHECK(126, String_new(isv, isv_Refman, aux_String_0, aux_String_0_Refman) )
  ++MR_file_coverage[0].line_count[127];
  isn = MR_new_string(i);
  if (isn == NULL) RAISE(127, 49, "insufficient memory for object dynamic allocation")
  isn_Refman = MR_new_ref(isn);
  if (isn_Refman == NULL) RAISE(127, 38, "insufficient memory for managed object")
  CHECK(127, String_new(isn, isn_Refman, text, text_Refman) )
  ++MR_file_coverage[0].line_count[128];
  fi = f_test_int2str_Mock;
  ++MR_file_coverage[0].line_count[129];
  itv = &itv_Var;
  itv_Refman = MR_new_ref(itv);
  if (itv_Refman == NULL) RAISE(129, 38, "insufficient memory for managed object")
  CHECK(129, TestStruct_new(itv, itv_Refman, i, text, text_Refman) )
  ++MR_file_coverage[0].line_count[130];
  itn = MR_alloc(sizeof(TestStruct));
  if (itn == NULL) RAISE(130, 49, "insufficient memory for object dynamic allocation")
  itn_Refman = MR_new_ref(itn);
  if (itn_Refman == NULL) RAISE(130, 38, "insufficient memory for managed object")
  CHECK(130, TestStruct_new(itn, itn_Refman, i, text, text_Refman) )
  ++MR_file_coverage[0].line_count[131];
  idv = &idv_Var;
  idv_Refman = MR_new_ref(idv);
  if (idv_Refman == NULL) RAISE(131, 38, "insufficient memory for managed object")
  CHECK(131, TestClass_new(idv, idv_Refman, idv_Dynamic) )
  ++MR_file_coverage[0].line_count[132];
  idn = MR_alloc(sizeof(TestClass));
  if (idn == NULL) RAISE(132, 49, "insufficient memory for object dynamic allocation")
  idn_Refman = MR_new_ref(idn);
  if (idn_Refman == NULL) RAISE(132, 38, "insufficient memory for managed object")
  CHECK(132, TestClass_new(idn, idn_Refman, idn_Dynamic) )
  ++MR_file_coverage[0].line_count[133];
  aux_TestStruct_0 = MR_alloc(sizeof(TestStruct));
  if (aux_TestStruct_0 == NULL) RAISE(133, 49, "insufficient memory for object dynamic allocation")
  aux_TestStruct_0_Refman = MR_new_ref(aux_TestStruct_0);
  if (aux_TestStruct_0_Refman == NULL) RAISE(133, 38, "insufficient memory for managed object")
  CHECK(133, TestStruct_new(aux_TestStruct_0, aux_TestStruct_0_Refman, i, text, text_Refman) )
  CHECK(133, TestStruct_print(aux_TestStruct_0, aux_TestStruct_0_Refman) )
  ++MR_file_coverage[0].line_count[134];
  aux_TestClass_0 = MR_alloc(sizeof(TestClass));
  if (aux_TestClass_0 == NULL) RAISE(134, 49, "insufficient memory for object dynamic allocation")
  aux_TestClass_0_Refman = MR_new_ref(aux_TestClass_0);
  if (aux_TestClass_0_Refman == NULL) RAISE(134, 38, "insufficient memory for managed object")
  CHECK(134, TestClass_new(aux_TestClass_0, aux_TestClass_0_Refman, aux_TestClass_0_Dynamic) )
  CHECK(134, TestClass_print(aux_TestClass_0, aux_TestClass_0_Refman, aux_TestClass_0_Dynamic) )
  ++MR_file_coverage[0].line_count[135];
  if (arr == NULL) RAISE(135, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(135, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(135, 25, "slice index out of bounds")
  aux_String_1 = MR_new_string(((Int*)((arr)->values))[0]);
  if (aux_String_1 == NULL) RAISE(135, 49, "insufficient memory for object dynamic allocation")
  aux_String_1_Refman = MR_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(135, 38, "insufficient memory for managed object")
  TEST_ASSERT(135, aux_String_1 != NULL && aux_String_1_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[136];
  if (arr == NULL) RAISE(136, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(136, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(136, 25, "slice index out of bounds")
  aux_Array_0 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if (aux_Array_0 == NULL) RAISE(136, 49, "insufficient memory for object dynamic allocation")
  aux_Array_0_Refman = MR_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(136, 38, "insufficient memory for managed object")
  TEST_ASSERT(136, aux_Array_0 != NULL && aux_Array_0_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[137];
  if (arr == NULL) RAISE(137, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(137, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(137, 25, "slice index out of bounds")
  aux_Array_1 = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestStruct));
  if (aux_Array_1 == NULL) RAISE(137, 49, "insufficient memory for object dynamic allocation")
  aux_Array_1_Refman = MR_new_ref(aux_Array_1);
  if (aux_Array_1_Refman == NULL) RAISE(137, 38, "insufficient memory for managed object")
  TEST_ASSERT(137, aux_Array_1 != NULL && aux_Array_1_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[138];
  if (arr == NULL) RAISE(138, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(138, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(138, 25, "slice index out of bounds")
  aux_Array_2 = MR_new_array(((Int*)((arr)->values))[0], sizeof(TestClass));
  if (aux_Array_2 == NULL) RAISE(138, 49, "insufficient memory for object dynamic allocation")
  aux_Array_2_Refman = MR_new_ref(aux_Array_2);
  if (aux_Array_2_Refman == NULL) RAISE(138, 38, "insufficient memory for managed object")
  TEST_ASSERT(138, aux_Array_2 != NULL && aux_Array_2_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[139];
  if (arr == NULL) RAISE(139, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(139, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(139, 25, "slice index out of bounds")
  if (arr == NULL) RAISE(139, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(139, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (arr)->length) RAISE(139, 25, "slice index out of bounds")
  aux_Array_3 = MR_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]);
  if (aux_Array_3 == NULL) RAISE(139, 49, "insufficient memory for object dynamic allocation")
  aux_Array_3_Refman = MR_new_ref(aux_Array_3);
  if (aux_Array_3_Refman == NULL) RAISE(139, 38, "insufficient memory for managed object")
  TEST_ASSERT(139, aux_Array_3 != NULL && aux_Array_3_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[140];
  if (arr == NULL) RAISE(140, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(140, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(140, 25, "slice index out of bounds")
  aux_Array_4 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Func));
  if (aux_Array_4 == NULL) RAISE(140, 49, "insufficient memory for object dynamic allocation")
  aux_Array_4_Refman = MR_new_ref(aux_Array_4);
  if (aux_Array_4_Refman == NULL) RAISE(140, 38, "insufficient memory for managed object")
  TEST_ASSERT(140, aux_Array_4 != NULL && aux_Array_4_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[141];
  TEST_ASSERT(141, x == 0)
  ++MR_file_coverage[0].line_count[142];
  TEST_ASSERT(142, s != NULL && s_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[143];
  TEST_ASSERT(143, a != NULL && a_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[144];
  CHECK(144, TestStruct_print(t, t_Refman) )
  ++MR_file_coverage[0].line_count[145];
  CHECK(145, TestClass_print(d, d_Refman, d_Dynamic) )
  ++MR_file_coverage[0].line_count[146];
  TEST_ASSERT(146, f != NULL)
  ++MR_file_coverage[0].line_count[147];
  CHECK(147, TestStruct_print(tv, tv_Refman) )
  ++MR_file_coverage[0].line_count[148];
  CHECK(148, TestClass_print(dv, dv_Refman, dv_Dynamic) )
  ++MR_file_coverage[0].line_count[149];
  TEST_ASSERT(149, sv != NULL && sv_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[150];
  TEST_ASSERT(150, ia != NULL && ia_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[151];
  TEST_ASSERT(151, ta != NULL && ta_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[152];
  TEST_ASSERT(152, da != NULL && da_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[153];
  TEST_ASSERT(153, sa != NULL && sa_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[154];
  TEST_ASSERT(154, fa != NULL && fa_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[155];
  CHECK(155, TestStruct_print(tn, tn_Refman) )
  ++MR_file_coverage[0].line_count[156];
  CHECK(156, TestClass_print(dn, dn_Refman, dn_Dynamic) )
  ++MR_file_coverage[0].line_count[157];
  TEST_ASSERT(157, sn != NULL && sn_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[158];
  TEST_ASSERT(158, ian != NULL && ian_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[159];
  TEST_ASSERT(159, tan != NULL && tan_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[160];
  TEST_ASSERT(160, dan != NULL && dan_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[161];
  TEST_ASSERT(161, san != NULL && san_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[162];
  TEST_ASSERT(162, sfn != NULL && sfn_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[163];
  TEST_ASSERT(163, ix == 0)
  ++MR_file_coverage[0].line_count[164];
  TEST_ASSERT(164, si != NULL && si_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[165];
  if (fi == NULL) RAISE(165, 21, "empty function called")
  CHECK(165, fi(7, &(aux_String_2), &(aux_String_2_Refman)) )
  ++MR_file_coverage[0].line_count[166];
  TEST_ASSERT(166, isv != NULL && isv_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[167];
  TEST_ASSERT(167, isn != NULL && isn_Refman->value != NULL)
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
  ++MR_file_coverage[0].line_count[180];
  *out_num = num;
  ++MR_file_coverage[0].line_count[181];
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
  ++MR_file_coverage[0].line_count[236];
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
  ++MR_file_coverage[0].line_count[238];
  USER_RAISE(238, NULL, NULL)
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
  ++MR_file_coverage[0].line_count[251];
  ++MR_file_coverage[0].line_count[252];
  ++MR_file_coverage[0].line_count[253];
  CHECK(253, f_test_void() )
  ++MR_file_coverage[0].line_count[254];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(254, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 5;
  aux_String_0_Var.length = 4;
  aux_String_0_Var.values = "text";
  CHECK(254, f_test_params(3, aux_String_0, aux_String_0_Refman, NULL, NULL) )
  ++MR_file_coverage[0].line_count[255];
  CHECK(255, f_test_outs(&(s), &(s_Refman), &(x)) )
  ++MR_file_coverage[0].line_count[256];
  CHECK(256, f_test_int2str_Mock(4, &(s), &(s_Refman)) )
  ++MR_file_coverage[0].line_count[257];
  CHECK(257, f_test_int(5) )
  ++MR_file_coverage[0].line_count[258];
  CHECK(258, f_test_int2int(6, &(x)) )
  ++MR_file_coverage[0].line_count[259];
  CHECK(259, f_test_many(7, 8, &(x), &(x)) )
  ++MR_file_coverage[0].line_count[264];
  ++MR_file_coverage[0].line_count[265];
  CHECK(265, f_test_int2int(9, &(tmp)) )
  CHECK(265, f_test_int(tmp) )
  ++MR_file_coverage[0].line_count[266];
  CHECK(266, f_test_many(11, 12, &(x), &(aux_Int_0)) )
  CHECK(266, f_test_int2int(10, &(aux_Int_1)) )
  x = aux_Int_1 + aux_Int_0;
  ++MR_file_coverage[0].line_count[267];
  CHECK(267, f_test_int2str_Mock(13, &(aux_String_1), &(aux_String_1_Refman)) )
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
  ++MR_file_coverage[0].line_count[271];
  if (arr == NULL) RAISE(271, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(271, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (arr)->length) RAISE(271, 25, "slice index out of bounds")
  if ((((Int*)((arr)->values))[4]) > 6) {
    ++MR_file_coverage[0].line_count[272];
    *res = 6;
  }
  else {
    ++MR_file_coverage[0].line_count[273];
    if (arr != NULL && arr_Refman->value != NULL) {
      ++MR_file_coverage[0].line_count[274];
      *res = 6;
    }
    else {
      ++MR_file_coverage[0].line_count[275];
      if (arr == NULL) RAISE(275, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(275, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(275, 25, "slice index out of bounds")
      if (arr == NULL) RAISE(275, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(275, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(275, 25, "slice index out of bounds")
      if ((((Int*)((arr)->values))[4]) != (((Int*)((arr)->values))[4])) {
        ++MR_file_coverage[0].line_count[276];
        *res = 6;
      }
      else {
        ++MR_file_coverage[0].line_count[277];
        if (arr == NULL) RAISE(277, 29, "empty object used as sequence")
        if (arr_Refman->value == NULL) RAISE(277, 40, "outdated weak reference used as sequence")
        if ((0) < 0 || (0) >= (arr)->length) RAISE(277, 25, "slice index out of bounds")
        if (0 == (((Int*)((arr)->values))[0])) {
          ++MR_file_coverage[0].line_count[278];
          *res = 6;
        }
        else {
          ++MR_file_coverage[0].line_count[280];
          *res = 0;
        }
      }
    }
  }
  ++MR_file_coverage[0].line_count[281];
  while (true) {
    ++MR_file_coverage[0].line_count[282];
    if (arr == NULL) RAISE(282, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(282, 40, "outdated weak reference used as sequence")
    if ((6) < 0 || (6) >= (arr)->length) RAISE(282, 25, "slice index out of bounds")
    ((Int*)((arr)->values))[6] = 6;
    ++MR_file_coverage[0].line_count[283];
    if (arr == NULL) RAISE(283, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(283, 40, "outdated weak reference used as sequence")
    if ((2) < 0 || (2) >= (arr)->length) RAISE(283, 25, "slice index out of bounds")
    x = ((Int*)((arr)->values))[2];
    ++MR_file_coverage[0].line_count[284];
    if (!((x > 3) && (arr == NULL))) break;
    ++MR_file_coverage[0].line_count[285];
    y = x - 1;
    ++MR_file_coverage[0].line_count[286];
    while (true) {
      ++MR_file_coverage[0].line_count[287];
      if (arr == NULL) RAISE(287, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(287, 40, "outdated weak reference used as sequence")
      if ((8) < 0 || (8) >= (arr)->length) RAISE(287, 25, "slice index out of bounds")
      if (arr == NULL) RAISE(287, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(287, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(287, 25, "slice index out of bounds")
      ((Int*)((arr)->values))[4] = ((Int*)((arr)->values))[8];
      ++MR_file_coverage[0].line_count[288];
      if (arr == NULL) RAISE(288, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(288, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(288, 25, "slice index out of bounds")
      if (y > (((Int*)((arr)->values))[4])) {
        ++MR_file_coverage[0].line_count[289];
        continue;
      }
      ++MR_file_coverage[0].line_count[290];
      z = 7;
      ++MR_file_coverage[0].line_count[291];
      if (arr == NULL) RAISE(291, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(291, 40, "outdated weak reference used as sequence")
      if ((4) < 0 || (4) >= (arr)->length) RAISE(291, 25, "slice index out of bounds")
      if (z <= (((Int*)((arr)->values))[4])) {
        ++MR_file_coverage[0].line_count[292];
        if (!(z > 0)) break;
      }
    }
  }
  ++MR_file_coverage[0].line_count[293];
  if (arr == NULL) RAISE(293, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(293, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (arr)->length) RAISE(293, 25, "slice index out of bounds")
  for (n = ((Int*)((arr)->values))[2]; n < 2 - (3 * (((Int*)((arr)->values))[2])); ++n) {
    ++MR_file_coverage[0].line_count[294];
    if (arr == NULL) RAISE(294, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(294, 40, "outdated weak reference used as sequence")
    if ((2) < 0 || (2) >= (arr)->length) RAISE(294, 25, "slice index out of bounds")
    if (arr == NULL) RAISE(294, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(294, 40, "outdated weak reference used as sequence")
    if ((0) < 0 || (0) >= (arr)->length) RAISE(294, 25, "slice index out of bounds")
    ((Int*)((arr)->values))[0] = ((Int*)((arr)->values))[2];
    ++MR_file_coverage[0].line_count[295];
    if (arr == NULL) RAISE(295, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(295, 40, "outdated weak reference used as sequence")
    if ((0) < 0 || (0) >= (arr)->length) RAISE(295, 25, "slice index out of bounds")
    w = ((Int*)((arr)->values))[0];
    ++MR_file_coverage[0].line_count[296];
    aux_Array_0 = &aux_Array_0_Var;
    aux_Array_0_Refman = MR_new_ref(aux_Array_0);
    if (aux_Array_0_Refman == NULL) RAISE(296, 38, "insufficient memory for managed object")
    aux_Array_0_Var.length = 2;
    aux_Array_0_Var.values = (Byte*)((arr)->values) + (3);
    if (arr == NULL) RAISE(296, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(296, 40, "outdated weak reference used as sequence")
    if ((3) < 0 || (2) < 0 || (3) + (2) > (arr)->length) RAISE(296, 25, "slice index out of bounds")
    if ((w > 4) && (arr != aux_Array_0)) {
      ++MR_file_coverage[0].line_count[297];
      if (arr == NULL) RAISE(297, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(297, 40, "outdated weak reference used as sequence")
      if ((1) < 0 || (1) >= (arr)->length) RAISE(297, 25, "slice index out of bounds")
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
  ++MR_file_coverage[0].line_count[302];
  ++MR_file_coverage[0].line_count[303];
  ++MR_file_coverage[0].line_count[304];
  ++MR_file_coverage[0].line_count[305];
  CHECK(305, Int_str(i, s, s_Refman) )
  ++MR_file_coverage[0].line_count[306];
  bv = true || false;
  ++MR_file_coverage[0].line_count[307];
  if (a == NULL) RAISE(307, 27, "used member of empty object")
  if (a_Refman->value == NULL) RAISE(307, 38, "used member of outdated weak reference")
  i = a->length;
  ++MR_file_coverage[0].line_count[308];
  if (s == NULL) RAISE(308, 27, "used member of empty object")
  if (s_Refman->value == NULL) RAISE(308, 38, "used member of outdated weak reference")
  i = s->length;
  ++MR_file_coverage[0].line_count[309];
  CHECK(309, String_clear(s, s_Refman) )
  ++MR_file_coverage[0].line_count[310];
  CHECK(310, String_equal(s, s_Refman, s, s_Refman, &(bv)) )
  ++MR_file_coverage[0].line_count[311];
  CHECK(311, String_get(s, s_Refman, i, &(cv)) )
  ++MR_file_coverage[0].line_count[312];
  CHECK(312, String_append(s, s_Refman, c) )
  ++MR_file_coverage[0].line_count[313];
  CHECK(313, String_new(s, s_Refman, s, s_Refman) )
  ++MR_file_coverage[0].line_count[314];
  CHECK(314, String_concat(s, s_Refman, s, s_Refman) )
  ++MR_file_coverage[0].line_count[315];
  CHECK(315, String_concat_int(s, s_Refman, i) )
  ++MR_file_coverage[0].line_count[316];
  CHECK(316, String_find(s, s_Refman, s, s_Refman, &(iv)) )
  ++MR_file_coverage[0].line_count[317];
  CHECK(317, String_has(s, s_Refman, c, &(bv)) )
  ++MR_file_coverage[0].line_count[318];
  ++MR_file_coverage[0].line_count[319];
  CHECK(319, file_open_read(s, s_Refman, &(f), &(f_Refman)) )
  ++MR_file_coverage[0].line_count[320];
  CHECK(320, file_open_write(s, s_Refman, &(f), &(f_Refman)) )
  ++MR_file_coverage[0].line_count[321];
  CHECK(321, File_getc(f, f_Refman, &(cv), &(bv)) )
  ++MR_file_coverage[0].line_count[322];
  CHECK(322, File_putc(f, f_Refman, c) )
  ++MR_file_coverage[0].line_count[323];
  CHECK(323, File_write(f, f_Refman, s, s_Refman) )
  ++MR_file_coverage[0].line_count[324];
  CHECK(324, File_close(f, f_Refman) )
  ++MR_file_coverage[0].line_count[325];
  if (sys == NULL) RAISE(325, 27, "used member of empty object")
  if (sys_Refman->value == NULL) RAISE(325, 38, "used member of outdated weak reference")
  if (sys->argv == NULL) RAISE(325, 29, "empty object used as sequence")
  if (sys->argv_Refman->value == NULL) RAISE(325, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (sys->argv)->length) RAISE(325, 25, "slice index out of bounds")
  MR_dec_ref(s_Refman);
  s_Refman = sys->argv_Refman;
  MR_inc_ref(s_Refman);
  s = ((String*)((sys->argv)->values)) + 1;
  ++MR_file_coverage[0].line_count[326];
  CHECK(326, Sys_print(sys, sys_Refman, s, s_Refman) )
  ++MR_file_coverage[0].line_count[327];
  CHECK(327, Sys_println_Mock(sys, sys_Refman, s, s_Refman) )
  ++MR_file_coverage[0].line_count[328];
  CHECK(328, Sys_getchar(sys, sys_Refman, &(cv), &(bv)) )
  ++MR_file_coverage[0].line_count[329];
  CHECK(329, Sys_getline(sys, sys_Refman, s, s_Refman) )
  ++MR_file_coverage[0].line_count[330];
  CHECK(330, Sys_getenv(sys, sys_Refman, s, s_Refman, s, s_Refman, &(bv)) )
  ++MR_file_coverage[0].line_count[331];
  CHECK(331, Sys_system(sys, sys_Refman, s, s_Refman, &(iv)) )
  ++MR_file_coverage[0].line_count[332];
  CHECK(332, Sys_exit(sys, sys_Refman, i) )
  ++MR_file_coverage[0].line_count[333];
  CHECK(333, File_putc(stdout, stdout_Refman, c) )
  ++MR_file_coverage[0].line_count[334];
  CHECK(334, File_getc(stdin, stdin_Refman, &(cv), &(bv)) )
  ++MR_file_coverage[0].line_count[335];
  CHECK(335, File_putc(stderr, stderr_Refman, c) )
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
  ++MR_file_coverage[0].line_count[339];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(339, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "test string";
  s = MR_new_string(32);
  if (s == NULL) RAISE(339, 49, "insufficient memory for object dynamic allocation")
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(339, 38, "insufficient memory for managed object")
  CHECK(339, String_new(s, s_Refman, aux_String_0, aux_String_0_Refman) )
  ++MR_file_coverage[0].line_count[340];
  s_user = s;
  s_user_Refman = s_Refman;
  MR_inc_ref(s_user_Refman);
  ++MR_file_coverage[0].line_count[341];
  CHECK(341, Sys_println_Mock(sys, sys_Refman, s, s_Refman) )
  ++MR_file_coverage[0].line_count[342];
  CHECK(342, Sys_println_Mock(sys, sys_Refman, s_user, s_user_Refman) )
  ++MR_file_coverage[0].line_count[343];
  CHECK(343, f_remove(s, s_Refman) )
  s = NULL;
  s_Refman = NULL;
  ++MR_file_coverage[0].line_count[344];
  if (! (s != NULL && s_Refman->value != NULL)) {
    ++MR_file_coverage[0].line_count[345];
    aux_String_1 = &aux_String_1_Var;
    aux_String_1_Refman = MR_new_ref(aux_String_1);
    if (aux_String_1_Refman == NULL) RAISE(345, 38, "insufficient memory for managed object")
    aux_String_1_Var.max_length = 17;
    aux_String_1_Var.length = 16;
    aux_String_1_Var.values = "ownership passed";
    CHECK(345, Sys_println_Mock(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
  }
  ++MR_file_coverage[0].line_count[346];
  if (! (s_user != NULL && s_user_Refman->value != NULL)) {
    ++MR_file_coverage[0].line_count[347];
    aux_String_2 = &aux_String_2_Var;
    aux_String_2_Refman = MR_new_ref(aux_String_2);
    if (aux_String_2_Refman == NULL) RAISE(347, 38, "insufficient memory for managed object")
    aux_String_2_Var.max_length = 15;
    aux_String_2_Var.length = 14;
    aux_String_2_Var.values = "string deleted";
    CHECK(347, Sys_println_Mock(sys, sys_Refman, aux_String_2, aux_String_2_Refman) )
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
  ++MR_file_coverage[0].line_count[377];
  d = &d_Var;
  d_Refman = MR_new_ref(d);
  if (d_Refman == NULL) RAISE(377, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[378];
  sarr = &sarr_Var;
  sarr_Var.values = sarr_Values;
  MR_set_var_string_array(6, 16, sarr, sarr_Chars);
  sarr_Refman = MR_new_ref(sarr);
  if (sarr_Refman == NULL) RAISE(378, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[379];
  if (d == NULL) RAISE(379, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(379, 38, "used member of outdated weak reference")
  MR_dec_ref(d->item_Refman);
  d->item_Refman = s_Refman;
  MR_inc_ref(d->item_Refman);
  d->item_Dynamic = &String_dynamic;
  d->item = s;
  ++MR_file_coverage[0].line_count[380];
  if (d == NULL) RAISE(380, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(380, 38, "used member of outdated weak reference")
  MR_dec_ref(s_Refman);
  s_Refman = d->item_Refman;
  MR_inc_ref(s_Refman);
  s = d->item;
  ++MR_file_coverage[0].line_count[381];
  if (d == NULL) RAISE(381, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(381, 38, "used member of outdated weak reference")
  MR_dec_ref(d->arr_Refman);
  d->arr_Refman = sarr_Refman;
  MR_inc_ref(d->arr_Refman);
  d->arr = sarr;
  ++MR_file_coverage[0].line_count[382];
  if (d == NULL) RAISE(382, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(382, 38, "used member of outdated weak reference")
  if (d->arr == NULL) RAISE(382, 29, "empty object used as sequence")
  if (d->arr_Refman->value == NULL) RAISE(382, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (d->arr)->length) RAISE(382, 25, "slice index out of bounds")
  MR_dec_ref(s_Refman);
  s_Refman = d->arr_Refman;
  MR_inc_ref(s_Refman);
  s = ((String*)((d->arr)->values)) + 4;
  ++MR_file_coverage[0].line_count[383];
  ad = &ad_Var;
  ad_Var.values = ad_Values;
  ad_Refman = MR_new_ref(ad);
  if (ad_Refman == NULL) RAISE(383, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[384];
  if (ad == NULL) RAISE(384, 29, "empty object used as sequence")
  if (ad_Refman->value == NULL) RAISE(384, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (ad)->length) RAISE(384, 25, "slice index out of bounds")
  if (((Data*)((ad)->values)) + 2 == NULL) RAISE(384, 27, "used member of empty object")
  if (ad_Refman->value == NULL) RAISE(384, 38, "used member of outdated weak reference")
  MR_dec_ref(s_Refman);
  s_Refman = (((Data*)((ad)->values)) + 2)->item_Refman;
  MR_inc_ref(s_Refman);
  s = (((Data*)((ad)->values)) + 2)->item;
  ++MR_file_coverage[0].line_count[385];
  if (ad == NULL) RAISE(385, 29, "empty object used as sequence")
  if (ad_Refman->value == NULL) RAISE(385, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (ad)->length) RAISE(385, 25, "slice index out of bounds")
  if (((Data*)((ad)->values)) + 2 == NULL) RAISE(385, 27, "used member of empty object")
  if (ad_Refman->value == NULL) RAISE(385, 38, "used member of outdated weak reference")
  if ((((Data*)((ad)->values)) + 2)->arr == NULL) RAISE(385, 29, "empty object used as sequence")
  if ((((Data*)((ad)->values)) + 2)->arr_Refman->value == NULL) RAISE(385, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) >= ((((Data*)((ad)->values)) + 2)->arr)->length) RAISE(385, 25, "slice index out of bounds")
  MR_dec_ref(s_Refman);
  s_Refman = (((Data*)((ad)->values)) + 2)->arr_Refman;
  MR_inc_ref(s_Refman);
  s = ((String*)(((((Data*)((ad)->values)) + 2)->arr)->values)) + 3;
  ++MR_file_coverage[0].line_count[386];
  dr = &dr_Var;
  dr_Refman = MR_new_ref(dr);
  if (dr_Refman == NULL) RAISE(386, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[387];
  if (dr == NULL) RAISE(387, 27, "used member of empty object")
  if (dr_Refman->value == NULL) RAISE(387, 38, "used member of outdated weak reference")
  if (dr->item == NULL) RAISE(387, 27, "used member of empty object")
  if (dr->item_Refman->value == NULL) RAISE(387, 38, "used member of outdated weak reference")
  if (((Data*)(dr->item))->item == NULL) RAISE(387, 27, "used member of empty object")
  if (((Data*)(dr->item))->item_Refman->value == NULL) RAISE(387, 38, "used member of outdated weak reference")
  MR_dec_ref(s_Refman);
  s_Refman = ((Data*)(((Data*)(dr->item))->item))->item_Refman;
  MR_inc_ref(s_Refman);
  s = ((Data*)(((Data*)(dr->item))->item))->item;
  ++MR_file_coverage[0].line_count[388];
  CHECK(388, Data_set(d, d_Refman, s, s_Refman, &String_dynamic, sarr, sarr_Refman) )
  ++MR_file_coverage[0].line_count[389];
  CHECK(389, Data_get(d, d_Refman, (void*)&(s), &(s_Refman), &dynamic_Void) )
  ++MR_file_coverage[0].line_count[390];
  dg = d;
  dg_Refman = d_Refman;
  MR_inc_ref(dg_Refman);
  ++MR_file_coverage[0].line_count[391];
  TEST_ASSERT(391, dg != NULL && dg_Refman->value != NULL)
  ++MR_file_coverage[0].line_count[393];
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(393, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[394];
  dt = &dt_Var;
  dt_Refman = MR_new_ref(dt);
  if (dt_Refman == NULL) RAISE(394, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[395];
  ts = &ts_Var;
  ts_Refman = MR_new_ref(ts);
  if (ts_Refman == NULL) RAISE(395, 38, "insufficient memory for managed object")
  CHECK(395, TestStruct_new(ts, ts_Refman, 0, NULL, NULL) )
  ++MR_file_coverage[0].line_count[396];
  if (t == NULL) RAISE(396, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(396, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base._base._base.item_Refman);
  t->_base._base._base.item_Refman = s_Refman;
  MR_inc_ref(t->_base._base._base.item_Refman);
  t->_base._base._base.item_Dynamic = &String_dynamic;
  t->_base._base._base.item = s;
  ++MR_file_coverage[0].line_count[397];
  if (t == NULL) RAISE(397, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(397, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base._base._base.arr_Refman);
  t->_base._base._base.arr_Refman = sarr_Refman;
  MR_inc_ref(t->_base._base._base.arr_Refman);
  t->_base._base._base.arr = sarr;
  ++MR_file_coverage[0].line_count[398];
  if (t == NULL) RAISE(398, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(398, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base._base.second_Refman);
  t->_base._base.second_Refman = dt_Refman;
  MR_inc_ref(t->_base._base.second_Refman);
  t->_base._base.second_Dynamic = &Data_dynamic;
  t->_base._base.second = dt;
  ++MR_file_coverage[0].line_count[399];
  if (t == NULL) RAISE(399, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(399, 38, "used member of outdated weak reference")
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
  ++MR_file_coverage[0].line_count[403];
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; break
    ++MR_file_coverage[0].line_count[404];
    if (t == NULL) RAISE(404, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(404, 38, "used member of outdated weak reference")
    t->num = 1;

#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  } while (false);
  --MR_trace_ignore_count;
  ++MR_file_coverage[0].line_count[405];
  if (MR_err != OK) {
    MR_err = OK;
    ++MR_file_coverage[0].line_count[406];
    aux_String_0 = &aux_String_0_Var;
    aux_String_0_Refman = MR_new_ref(aux_String_0);
    if (aux_String_0_Refman == NULL) RAISE(406, 38, "insufficient memory for managed object")
    aux_String_0_Var.max_length = 16;
    aux_String_0_Var.length = 15;
    aux_String_0_Var.values = "ignored message";
    USER_RAISE(406, aux_String_0, aux_String_0_Refman)
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
  ++MR_file_coverage[0].line_count[409];
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; break
    ++MR_file_coverage[0].line_count[410];
    aux_String_0 = &aux_String_0_Var;
    aux_String_0_Refman = MR_new_ref(aux_String_0);
    if (aux_String_0_Refman == NULL) RAISE(410, 38, "insufficient memory for managed object")
    aux_String_0_Var.max_length = 20;
    aux_String_0_Var.length = 19;
    aux_String_0_Var.values = "error handling { 1 ";
    CHECK(410, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
    ++MR_file_coverage[0].line_count[411];
    if (t == NULL) RAISE(411, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(411, 38, "used member of outdated weak reference")
    t->num = 1;
    ++MR_file_coverage[0].line_count[412];
    aux_String_1 = &aux_String_1_Var;
    aux_String_1_Refman = MR_new_ref(aux_String_1);
    if (aux_String_1_Refman == NULL) RAISE(412, 38, "insufficient memory for managed object")
    aux_String_1_Var.max_length = 4;
    aux_String_1_Var.length = 3;
    aux_String_1_Var.values = " X ";
    CHECK(412, Sys_print(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
    ++MR_file_coverage[0].line_count[413];
    do {
      ++MR_trace_ignore_count;
      ++MR_file_coverage[0].line_count[414];
      CHECK(414, f_test_void() )
    } while (false);
    --MR_trace_ignore_count;
    ++MR_file_coverage[0].line_count[415];
    if (MR_err != OK) {
      MR_err = OK;
      ++MR_file_coverage[0].line_count[416];
      CHECK(416, f_test_int(2) )
    }

#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  } while (false);
  --MR_trace_ignore_count;
  ++MR_file_coverage[0].line_count[417];
  if (MR_err != OK) {
    MR_err = OK;
    ++MR_file_coverage[0].line_count[418];
    aux_String_2 = &aux_String_2_Var;
    aux_String_2_Refman = MR_new_ref(aux_String_2);
    if (aux_String_2_Refman == NULL) RAISE(418, 38, "insufficient memory for managed object")
    aux_String_2_Var.max_length = 3;
    aux_String_2_Var.length = 2;
    aux_String_2_Var.values = "2 ";
    CHECK(418, Sys_print(sys, sys_Refman, aux_String_2, aux_String_2_Refman) )
    ++MR_file_coverage[0].line_count[419];
    do {
      ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; break
      ++MR_file_coverage[0].line_count[420];
      aux_String_3 = &aux_String_3_Var;
      aux_String_3_Refman = MR_new_ref(aux_String_3);
      if (aux_String_3_Refman == NULL) RAISE(420, 38, "insufficient memory for managed object")
      aux_String_3_Var.max_length = 3;
      aux_String_3_Var.length = 2;
      aux_String_3_Var.values = "3 ";
      CHECK(420, Sys_print(sys, sys_Refman, aux_String_3, aux_String_3_Refman) )
      ++MR_file_coverage[0].line_count[421];
      if (t == NULL) RAISE(421, 27, "used member of empty object")
      if (t_Refman->value == NULL) RAISE(421, 38, "used member of outdated weak reference")
      t->num = 2;
      ++MR_file_coverage[0].line_count[422];
      aux_String_4 = &aux_String_4_Var;
      aux_String_4_Refman = MR_new_ref(aux_String_4);
      if (aux_String_4_Refman == NULL) RAISE(422, 38, "insufficient memory for managed object")
      aux_String_4_Var.max_length = 4;
      aux_String_4_Var.length = 3;
      aux_String_4_Var.values = " X ";
      CHECK(422, Sys_print(sys, sys_Refman, aux_String_4, aux_String_4_Refman) )

#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    } while (false);
    --MR_trace_ignore_count;
    MR_err = OK;
    ++MR_file_coverage[0].line_count[423];
    aux_String_5 = &aux_String_5_Var;
    aux_String_5_Refman = MR_new_ref(aux_String_5);
    if (aux_String_5_Refman == NULL) RAISE(423, 38, "insufficient memory for managed object")
    aux_String_5_Var.max_length = 3;
    aux_String_5_Var.length = 2;
    aux_String_5_Var.values = "4 ";
    CHECK(423, Sys_print(sys, sys_Refman, aux_String_5, aux_String_5_Refman) )
  }
  ++MR_file_coverage[0].line_count[424];
  aux_String_6 = &aux_String_6_Var;
  aux_String_6_Refman = MR_new_ref(aux_String_6);
  if (aux_String_6_Refman == NULL) RAISE(424, 38, "insufficient memory for managed object")
  aux_String_6_Var.max_length = 3;
  aux_String_6_Var.length = 2;
  aux_String_6_Var.values = "5 ";
  CHECK(424, Sys_print(sys, sys_Refman, aux_String_6, aux_String_6_Refman) )
  ++MR_file_coverage[0].line_count[425];
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; break
    ++MR_file_coverage[0].line_count[426];
    aux_String_7 = &aux_String_7_Var;
    aux_String_7_Refman = MR_new_ref(aux_String_7);
    if (aux_String_7_Refman == NULL) RAISE(426, 38, "insufficient memory for managed object")
    aux_String_7_Var.max_length = 3;
    aux_String_7_Var.length = 2;
    aux_String_7_Var.values = "6 ";
    CHECK(426, Sys_print(sys, sys_Refman, aux_String_7, aux_String_7_Refman) )
    ++MR_file_coverage[0].line_count[427];
    do {
      ++MR_trace_ignore_count;
      ++MR_file_coverage[0].line_count[428];
      aux_String_8 = &aux_String_8_Var;
      aux_String_8_Refman = MR_new_ref(aux_String_8);
      if (aux_String_8_Refman == NULL) RAISE(428, 38, "insufficient memory for managed object")
      aux_String_8_Var.max_length = 3;
      aux_String_8_Var.length = 2;
      aux_String_8_Var.values = "7 ";
      CHECK(428, Sys_print(sys, sys_Refman, aux_String_8, aux_String_8_Refman) )
      ++MR_file_coverage[0].line_count[429];
      CHECK(429, f_try_catch_raise(t, t_Refman) )
      ++MR_file_coverage[0].line_count[430];
      aux_String_9 = &aux_String_9_Var;
      aux_String_9_Refman = MR_new_ref(aux_String_9);
      if (aux_String_9_Refman == NULL) RAISE(430, 38, "insufficient memory for managed object")
      aux_String_9_Var.max_length = 4;
      aux_String_9_Var.length = 3;
      aux_String_9_Var.values = " X ";
      CHECK(430, Sys_print(sys, sys_Refman, aux_String_9, aux_String_9_Refman) )
    } while (false);
    --MR_trace_ignore_count;
    MR_err = OK;
    ++MR_file_coverage[0].line_count[431];
    aux_String_10 = &aux_String_10_Var;
    aux_String_10_Refman = MR_new_ref(aux_String_10);
    if (aux_String_10_Refman == NULL) RAISE(431, 38, "insufficient memory for managed object")
    aux_String_10_Var.max_length = 3;
    aux_String_10_Var.length = 2;
    aux_String_10_Var.values = "8 ";
    CHECK(431, Sys_print(sys, sys_Refman, aux_String_10, aux_String_10_Refman) )
    ++MR_file_coverage[0].line_count[432];
    aux_String_11 = &aux_String_11_Var;
    aux_String_11_Refman = MR_new_ref(aux_String_11);
    if (aux_String_11_Refman == NULL) RAISE(432, 38, "insufficient memory for managed object")
    aux_String_11_Var.max_length = 24;
    aux_String_11_Var.length = 23;
    aux_String_11_Var.values = "another ignored message";
    USER_RAISE(432, aux_String_11, aux_String_11_Refman)

#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  } while (false);
  --MR_trace_ignore_count;
  MR_err = OK;
  ++MR_file_coverage[0].line_count[433];
  aux_String_12 = &aux_String_12_Var;
  aux_String_12_Refman = MR_new_ref(aux_String_12);
  if (aux_String_12_Refman == NULL) RAISE(433, 38, "insufficient memory for managed object")
  aux_String_12_Var.max_length = 2;
  aux_String_12_Var.length = 1;
  aux_String_12_Var.values = "}";
  CHECK(433, Sys_println_Mock(sys, sys_Refman, aux_String_12, aux_String_12_Refman) )
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
  ++MR_file_coverage[0].line_count[463];
  text = &text_Var;
  text_Var.values = text_Values;
  text_Refman = MR_new_ref(text);
  if (text_Refman == NULL) RAISE(463, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[464];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(464, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 8;
  aux_String_0_Var.length = 7;
  aux_String_0_Var.values = "chars[ ";
  CHECK(464, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  ++MR_file_coverage[0].line_count[465];
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = MR_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(465, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 7;
  aux_String_1_Var.length = 6;
  aux_String_1_Var.values = "abcdef";
  MR_dec_ref(aux_String_2_Refman);
  aux_String_2_Refman = aux_String_1_Refman;
  MR_inc_ref(aux_String_2_Refman);
  aux_String_2 = aux_String_1;
  {int c_Index; for (c_Index = 0; c_Index < aux_String_2->length; ++c_Index) {
    if (aux_String_2 == NULL) RAISE(465, 29, "empty object used as sequence")
    if (aux_String_2_Refman->value == NULL) RAISE(465, 40, "outdated weak reference used as sequence")
    if ((c_Index) < 0 || (c_Index) >= (aux_String_2)->length) RAISE(465, 25, "slice index out of bounds")
    c = ((aux_String_2)->values)[c_Index];
    ++MR_file_coverage[0].line_count[466];
    CHECK(466, String_clear(text, text_Refman) )
    ++MR_file_coverage[0].line_count[467];
    CHECK(467, String_append(text, text_Refman, c) )
    ++MR_file_coverage[0].line_count[468];
    CHECK(468, Sys_print(sys, sys_Refman, text, text_Refman) )
    ++MR_file_coverage[0].line_count[469];
    aux_String_3 = &aux_String_3_Var;
    aux_String_3_Refman = MR_new_ref(aux_String_3);
    if (aux_String_3_Refman == NULL) RAISE(469, 38, "insufficient memory for managed object")
    aux_String_3_Var.max_length = 2;
    aux_String_3_Var.length = 1;
    aux_String_3_Var.values = " ";
    CHECK(469, Sys_print(sys, sys_Refman, aux_String_3, aux_String_3_Refman) )
  }}
  MR_dec_ref(aux_String_2_Refman);
  aux_String_2_Refman = NULL;
  MR_inc_ref(aux_String_2_Refman);
  aux_String_2 = NULL;
  ++MR_file_coverage[0].line_count[470];
  aux_String_4 = &aux_String_4_Var;
  aux_String_4_Refman = MR_new_ref(aux_String_4);
  if (aux_String_4_Refman == NULL) RAISE(470, 38, "insufficient memory for managed object")
  aux_String_4_Var.max_length = 2;
  aux_String_4_Var.length = 1;
  aux_String_4_Var.values = "]";
  CHECK(470, Sys_println_Mock(sys, sys_Refman, aux_String_4, aux_String_4_Refman) )
  ++MR_file_coverage[0].line_count[472];
  arr = &arr_Var;
  arr_Var.values = arr_Values;
  arr_Refman = MR_new_ref(arr);
  if (arr_Refman == NULL) RAISE(472, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[473];
  if (arr == NULL) RAISE(473, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(473, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(473, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[0] = 14;
  ++MR_file_coverage[0].line_count[474];
  if (arr == NULL) RAISE(474, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(474, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (arr)->length) RAISE(474, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[1] = 15;
  ++MR_file_coverage[0].line_count[475];
  if (arr == NULL) RAISE(475, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(475, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (arr)->length) RAISE(475, 25, "slice index out of bounds")
  ((Int*)((arr)->values))[2] = 16;
  ++MR_file_coverage[0].line_count[476];
  aux_String_5 = &aux_String_5_Var;
  aux_String_5_Refman = MR_new_ref(aux_String_5);
  if (aux_String_5_Refman == NULL) RAISE(476, 38, "insufficient memory for managed object")
  aux_String_5_Var.max_length = 10;
  aux_String_5_Var.length = 9;
  aux_String_5_Var.values = "numbers[ ";
  CHECK(476, Sys_print(sys, sys_Refman, aux_String_5, aux_String_5_Refman) )
  ++MR_file_coverage[0].line_count[477];
  MR_dec_ref(aux_Array_0_Refman);
  aux_Array_0_Refman = arr_Refman;
  MR_inc_ref(aux_Array_0_Refman);
  aux_Array_0 = arr;
  {int n_Index; for (n_Index = 0; n_Index < aux_Array_0->length; ++n_Index) {
    if (aux_Array_0 == NULL) RAISE(477, 29, "empty object used as sequence")
    if (aux_Array_0_Refman->value == NULL) RAISE(477, 40, "outdated weak reference used as sequence")
    if ((n_Index) < 0 || (n_Index) >= (aux_Array_0)->length) RAISE(477, 25, "slice index out of bounds")
    n = ((Int*)((aux_Array_0)->values))[n_Index];
    ++MR_file_coverage[0].line_count[478];
    CHECK(478, String_clear(text, text_Refman) )
    ++MR_file_coverage[0].line_count[479];
    CHECK(479, Int_str(n, text, text_Refman) )
    ++MR_file_coverage[0].line_count[480];
    CHECK(480, Sys_print(sys, sys_Refman, text, text_Refman) )
    ++MR_file_coverage[0].line_count[481];
    aux_String_6 = &aux_String_6_Var;
    aux_String_6_Refman = MR_new_ref(aux_String_6);
    if (aux_String_6_Refman == NULL) RAISE(481, 38, "insufficient memory for managed object")
    aux_String_6_Var.max_length = 2;
    aux_String_6_Var.length = 1;
    aux_String_6_Var.values = " ";
    CHECK(481, Sys_print(sys, sys_Refman, aux_String_6, aux_String_6_Refman) )
  }}
  MR_dec_ref(aux_Array_0_Refman);
  aux_Array_0_Refman = NULL;
  MR_inc_ref(aux_Array_0_Refman);
  aux_Array_0 = NULL;
  ++MR_file_coverage[0].line_count[482];
  aux_String_7 = &aux_String_7_Var;
  aux_String_7_Refman = MR_new_ref(aux_String_7);
  if (aux_String_7_Refman == NULL) RAISE(482, 38, "insufficient memory for managed object")
  aux_String_7_Var.max_length = 2;
  aux_String_7_Var.length = 1;
  aux_String_7_Var.values = "]";
  CHECK(482, Sys_println_Mock(sys, sys_Refman, aux_String_7, aux_String_7_Refman) )
  ++MR_file_coverage[0].line_count[484];
  tsarr = &tsarr_Var;
  tsarr_Var.values = tsarr_Values;
  tsarr_Refman = MR_new_ref(tsarr);
  if (tsarr_Refman == NULL) RAISE(484, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[485];
  aux_String_8 = &aux_String_8_Var;
  aux_String_8_Refman = MR_new_ref(aux_String_8);
  if (aux_String_8_Refman == NULL) RAISE(485, 38, "insufficient memory for managed object")
  aux_String_8_Var.max_length = 4;
  aux_String_8_Var.length = 3;
  aux_String_8_Var.values = "aaa";
  if (tsarr == NULL) RAISE(485, 29, "empty object used as sequence")
  if (tsarr_Refman->value == NULL) RAISE(485, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (tsarr)->length) RAISE(485, 25, "slice index out of bounds")
  if (((TestStruct*)((tsarr)->values)) + 0 == NULL) RAISE(485, 27, "used member of empty object")
  if (tsarr_Refman->value == NULL) RAISE(485, 38, "used member of outdated weak reference")
  MR_dec_ref((((TestStruct*)((tsarr)->values)) + 0)->text_Refman);
  (((TestStruct*)((tsarr)->values)) + 0)->text_Refman = aux_String_8_Refman;
  MR_inc_ref((((TestStruct*)((tsarr)->values)) + 0)->text_Refman);
  (((TestStruct*)((tsarr)->values)) + 0)->text = aux_String_8;
  ++MR_file_coverage[0].line_count[486];
  aux_String_9 = &aux_String_9_Var;
  aux_String_9_Refman = MR_new_ref(aux_String_9);
  if (aux_String_9_Refman == NULL) RAISE(486, 38, "insufficient memory for managed object")
  aux_String_9_Var.max_length = 4;
  aux_String_9_Var.length = 3;
  aux_String_9_Var.values = "bbb";
  if (tsarr == NULL) RAISE(486, 29, "empty object used as sequence")
  if (tsarr_Refman->value == NULL) RAISE(486, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (tsarr)->length) RAISE(486, 25, "slice index out of bounds")
  if (((TestStruct*)((tsarr)->values)) + 1 == NULL) RAISE(486, 27, "used member of empty object")
  if (tsarr_Refman->value == NULL) RAISE(486, 38, "used member of outdated weak reference")
  MR_dec_ref((((TestStruct*)((tsarr)->values)) + 1)->text_Refman);
  (((TestStruct*)((tsarr)->values)) + 1)->text_Refman = aux_String_9_Refman;
  MR_inc_ref((((TestStruct*)((tsarr)->values)) + 1)->text_Refman);
  (((TestStruct*)((tsarr)->values)) + 1)->text = aux_String_9;
  ++MR_file_coverage[0].line_count[487];
  aux_String_10 = &aux_String_10_Var;
  aux_String_10_Refman = MR_new_ref(aux_String_10);
  if (aux_String_10_Refman == NULL) RAISE(487, 38, "insufficient memory for managed object")
  aux_String_10_Var.max_length = 4;
  aux_String_10_Var.length = 3;
  aux_String_10_Var.values = "ccc";
  if (tsarr == NULL) RAISE(487, 29, "empty object used as sequence")
  if (tsarr_Refman->value == NULL) RAISE(487, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (tsarr)->length) RAISE(487, 25, "slice index out of bounds")
  if (((TestStruct*)((tsarr)->values)) + 2 == NULL) RAISE(487, 27, "used member of empty object")
  if (tsarr_Refman->value == NULL) RAISE(487, 38, "used member of outdated weak reference")
  MR_dec_ref((((TestStruct*)((tsarr)->values)) + 2)->text_Refman);
  (((TestStruct*)((tsarr)->values)) + 2)->text_Refman = aux_String_10_Refman;
  MR_inc_ref((((TestStruct*)((tsarr)->values)) + 2)->text_Refman);
  (((TestStruct*)((tsarr)->values)) + 2)->text = aux_String_10;
  ++MR_file_coverage[0].line_count[488];
  aux_String_11 = &aux_String_11_Var;
  aux_String_11_Refman = MR_new_ref(aux_String_11);
  if (aux_String_11_Refman == NULL) RAISE(488, 38, "insufficient memory for managed object")
  aux_String_11_Var.max_length = 10;
  aux_String_11_Var.length = 9;
  aux_String_11_Var.values = "structs[ ";
  CHECK(488, Sys_print(sys, sys_Refman, aux_String_11, aux_String_11_Refman) )
  ++MR_file_coverage[0].line_count[489];
  MR_dec_ref(aux_Array_1_Refman);
  aux_Array_1_Refman = tsarr_Refman;
  MR_inc_ref(aux_Array_1_Refman);
  aux_Array_1 = tsarr;
  {int ts_Index; for (ts_Index = 0; ts_Index < aux_Array_1->length; ++ts_Index) {
    if (aux_Array_1 == NULL) RAISE(489, 29, "empty object used as sequence")
    if (aux_Array_1_Refman->value == NULL) RAISE(489, 40, "outdated weak reference used as sequence")
    if ((ts_Index) < 0 || (ts_Index) >= (aux_Array_1)->length) RAISE(489, 25, "slice index out of bounds")
    MR_dec_ref(ts_Refman);
    ts_Refman = aux_Array_1_Refman;
    MR_inc_ref(ts_Refman);
    ts = ((TestStruct*)((aux_Array_1)->values)) + ts_Index;
    ++MR_file_coverage[0].line_count[490];
    if (ts == NULL) RAISE(490, 27, "used member of empty object")
    if (ts_Refman->value == NULL) RAISE(490, 38, "used member of outdated weak reference")
    CHECK(490, Sys_print(sys, sys_Refman, ts->text, ts->text_Refman) )
    ++MR_file_coverage[0].line_count[491];
    aux_String_12 = &aux_String_12_Var;
    aux_String_12_Refman = MR_new_ref(aux_String_12);
    if (aux_String_12_Refman == NULL) RAISE(491, 38, "insufficient memory for managed object")
    aux_String_12_Var.max_length = 2;
    aux_String_12_Var.length = 1;
    aux_String_12_Var.values = " ";
    CHECK(491, Sys_print(sys, sys_Refman, aux_String_12, aux_String_12_Refman) )
  }}
  MR_dec_ref(aux_Array_1_Refman);
  aux_Array_1_Refman = NULL;
  MR_inc_ref(aux_Array_1_Refman);
  aux_Array_1 = NULL;
  ++MR_file_coverage[0].line_count[492];
  aux_String_13 = &aux_String_13_Var;
  aux_String_13_Refman = MR_new_ref(aux_String_13);
  if (aux_String_13_Refman == NULL) RAISE(492, 38, "insufficient memory for managed object")
  aux_String_13_Var.max_length = 2;
  aux_String_13_Var.length = 1;
  aux_String_13_Var.values = "]";
  CHECK(492, Sys_println_Mock(sys, sys_Refman, aux_String_13, aux_String_13_Refman) )
  ++MR_file_coverage[0].line_count[494];
  sarr = &sarr_Var;
  sarr_Var.values = sarr_Values;
  MR_set_var_string_array(3, 16, sarr, sarr_Chars);
  sarr_Refman = MR_new_ref(sarr);
  if (sarr_Refman == NULL) RAISE(494, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[495];
  if (sarr == NULL) RAISE(495, 29, "empty object used as sequence")
  if (sarr_Refman->value == NULL) RAISE(495, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (sarr)->length) RAISE(495, 25, "slice index out of bounds")
  aux_String_14 = &aux_String_14_Var;
  aux_String_14_Refman = MR_new_ref(aux_String_14);
  if (aux_String_14_Refman == NULL) RAISE(495, 38, "insufficient memory for managed object")
  aux_String_14_Var.max_length = 4;
  aux_String_14_Var.length = 3;
  aux_String_14_Var.values = "ddd";
  CHECK(495, String_new(((String*)((sarr)->values)) + 0, sarr_Refman, aux_String_14, aux_String_14_Refman) )
  ++MR_file_coverage[0].line_count[496];
  if (sarr == NULL) RAISE(496, 29, "empty object used as sequence")
  if (sarr_Refman->value == NULL) RAISE(496, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (sarr)->length) RAISE(496, 25, "slice index out of bounds")
  aux_String_15 = &aux_String_15_Var;
  aux_String_15_Refman = MR_new_ref(aux_String_15);
  if (aux_String_15_Refman == NULL) RAISE(496, 38, "insufficient memory for managed object")
  aux_String_15_Var.max_length = 4;
  aux_String_15_Var.length = 3;
  aux_String_15_Var.values = "eee";
  CHECK(496, String_new(((String*)((sarr)->values)) + 1, sarr_Refman, aux_String_15, aux_String_15_Refman) )
  ++MR_file_coverage[0].line_count[497];
  if (sarr == NULL) RAISE(497, 29, "empty object used as sequence")
  if (sarr_Refman->value == NULL) RAISE(497, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (sarr)->length) RAISE(497, 25, "slice index out of bounds")
  aux_String_16 = &aux_String_16_Var;
  aux_String_16_Refman = MR_new_ref(aux_String_16);
  if (aux_String_16_Refman == NULL) RAISE(497, 38, "insufficient memory for managed object")
  aux_String_16_Var.max_length = 4;
  aux_String_16_Var.length = 3;
  aux_String_16_Var.values = "fff";
  CHECK(497, String_new(((String*)((sarr)->values)) + 2, sarr_Refman, aux_String_16, aux_String_16_Refman) )
  ++MR_file_coverage[0].line_count[498];
  aux_String_17 = &aux_String_17_Var;
  aux_String_17_Refman = MR_new_ref(aux_String_17);
  if (aux_String_17_Refman == NULL) RAISE(498, 38, "insufficient memory for managed object")
  aux_String_17_Var.max_length = 10;
  aux_String_17_Var.length = 9;
  aux_String_17_Var.values = "strings[ ";
  CHECK(498, Sys_print(sys, sys_Refman, aux_String_17, aux_String_17_Refman) )
  ++MR_file_coverage[0].line_count[499];
  MR_dec_ref(aux_Array_2_Refman);
  aux_Array_2_Refman = sarr_Refman;
  MR_inc_ref(aux_Array_2_Refman);
  aux_Array_2 = sarr;
  {int s_Index; for (s_Index = 0; s_Index < aux_Array_2->length; ++s_Index) {
    if (aux_Array_2 == NULL) RAISE(499, 29, "empty object used as sequence")
    if (aux_Array_2_Refman->value == NULL) RAISE(499, 40, "outdated weak reference used as sequence")
    if ((s_Index) < 0 || (s_Index) >= (aux_Array_2)->length) RAISE(499, 25, "slice index out of bounds")
    MR_dec_ref(s_Refman);
    s_Refman = aux_Array_2_Refman;
    MR_inc_ref(s_Refman);
    s = ((String*)((aux_Array_2)->values)) + s_Index;
    ++MR_file_coverage[0].line_count[500];
    CHECK(500, Sys_print(sys, sys_Refman, s, s_Refman) )
    ++MR_file_coverage[0].line_count[501];
    aux_String_18 = &aux_String_18_Var;
    aux_String_18_Refman = MR_new_ref(aux_String_18);
    if (aux_String_18_Refman == NULL) RAISE(501, 38, "insufficient memory for managed object")
    aux_String_18_Var.max_length = 2;
    aux_String_18_Var.length = 1;
    aux_String_18_Var.values = " ";
    CHECK(501, Sys_print(sys, sys_Refman, aux_String_18, aux_String_18_Refman) )
  }}
  MR_dec_ref(aux_Array_2_Refman);
  aux_Array_2_Refman = NULL;
  MR_inc_ref(aux_Array_2_Refman);
  aux_Array_2 = NULL;
  ++MR_file_coverage[0].line_count[502];
  aux_String_19 = &aux_String_19_Var;
  aux_String_19_Refman = MR_new_ref(aux_String_19);
  if (aux_String_19_Refman == NULL) RAISE(502, 38, "insufficient memory for managed object")
  aux_String_19_Var.max_length = 2;
  aux_String_19_Var.length = 1;
  aux_String_19_Var.values = "]";
  CHECK(502, Sys_println_Mock(sys, sys_Refman, aux_String_19, aux_String_19_Refman) )
  ++MR_file_coverage[0].line_count[504];
  aux_String_20 = &aux_String_20_Var;
  aux_String_20_Refman = MR_new_ref(aux_String_20);
  if (aux_String_20_Refman == NULL) RAISE(504, 38, "insufficient memory for managed object")
  aux_String_20_Var.max_length = 4;
  aux_String_20_Var.length = 3;
  aux_String_20_Var.values = "iii";
  container_last = &container_last_Var;
  container_last_Refman = MR_new_ref(container_last);
  if (container_last_Refman == NULL) RAISE(504, 38, "insufficient memory for managed object")
  CHECK(504, Container_new(container_last, container_last_Refman, aux_String_20, aux_String_20_Refman, &String_dynamic, NULL, NULL) )
  ++MR_file_coverage[0].line_count[505];
  aux_String_21 = &aux_String_21_Var;
  aux_String_21_Refman = MR_new_ref(aux_String_21);
  if (aux_String_21_Refman == NULL) RAISE(505, 38, "insufficient memory for managed object")
  aux_String_21_Var.max_length = 4;
  aux_String_21_Var.length = 3;
  aux_String_21_Var.values = "hhh";
  container_mid = &container_mid_Var;
  container_mid_Refman = MR_new_ref(container_mid);
  if (container_mid_Refman == NULL) RAISE(505, 38, "insufficient memory for managed object")
  CHECK(505, Container_new(container_mid, container_mid_Refman, aux_String_21, aux_String_21_Refman, &String_dynamic, container_last, container_last_Refman) )
  ++MR_file_coverage[0].line_count[506];
  aux_String_22 = &aux_String_22_Var;
  aux_String_22_Refman = MR_new_ref(aux_String_22);
  if (aux_String_22_Refman == NULL) RAISE(506, 38, "insufficient memory for managed object")
  aux_String_22_Var.max_length = 4;
  aux_String_22_Var.length = 3;
  aux_String_22_Var.values = "ggg";
  container_first = &container_first_Var;
  container_first_Refman = MR_new_ref(container_first);
  if (container_first_Refman == NULL) RAISE(506, 38, "insufficient memory for managed object")
  CHECK(506, Container_new(container_first, container_first_Refman, aux_String_22, aux_String_22_Refman, &String_dynamic, container_mid, container_mid_Refman) )
  ++MR_file_coverage[0].line_count[507];
  container = &container_Var;
  container_Refman = MR_new_ref(container);
  if (container_Refman == NULL) RAISE(507, 38, "insufficient memory for managed object")
  CHECK(507, Container_new(container, container_Refman, NULL, NULL, NULL, container_first, container_first_Refman) )
  ++MR_file_coverage[0].line_count[508];
  ++MR_file_coverage[0].line_count[509];
  CHECK(509, Container_iter(container, container_Refman, &(iter), &(iter_Refman)) )
  ++MR_file_coverage[0].line_count[510];
  aux_String_23 = &aux_String_23_Var;
  aux_String_23_Refman = MR_new_ref(aux_String_23);
  if (aux_String_23_Refman == NULL) RAISE(510, 38, "insufficient memory for managed object")
  aux_String_23_Var.max_length = 9;
  aux_String_23_Var.length = 8;
  aux_String_23_Var.values = "values[ ";
  CHECK(510, Sys_print(sys, sys_Refman, aux_String_23, aux_String_23_Refman) )
  ++MR_file_coverage[0].line_count[511];
  MR_dec_ref(aux_ContainerIterator_0_Refman);
  aux_ContainerIterator_0_Refman = iter_Refman;
  MR_inc_ref(aux_ContainerIterator_0_Refman);
  aux_ContainerIterator_0 = iter;
  while (true) {
    Bool s_Has = false;
    CHECK(511, ContainerIterator_has(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman, &(s_Has)) )
    if (!s_Has) break;
    CHECK(511, ContainerIterator_get(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman, (void*)&(s), &(s_Refman), &dynamic_Void) )
    ++MR_file_coverage[0].line_count[512];
    CHECK(512, Sys_print(sys, sys_Refman, s, s_Refman) )
    ++MR_file_coverage[0].line_count[513];
    aux_String_24 = &aux_String_24_Var;
    aux_String_24_Refman = MR_new_ref(aux_String_24);
    if (aux_String_24_Refman == NULL) RAISE(513, 38, "insufficient memory for managed object")
    aux_String_24_Var.max_length = 2;
    aux_String_24_Var.length = 1;
    aux_String_24_Var.values = " ";
    CHECK(513, Sys_print(sys, sys_Refman, aux_String_24, aux_String_24_Refman) )
    CHECK(511, ContainerIterator_next(aux_ContainerIterator_0, aux_ContainerIterator_0_Refman) )
  }
  MR_dec_ref(aux_ContainerIterator_0_Refman);
  aux_ContainerIterator_0_Refman = NULL;
  MR_inc_ref(aux_ContainerIterator_0_Refman);
  aux_ContainerIterator_0 = NULL;
  ++MR_file_coverage[0].line_count[514];
  aux_String_25 = &aux_String_25_Var;
  aux_String_25_Refman = MR_new_ref(aux_String_25);
  if (aux_String_25_Refman == NULL) RAISE(514, 38, "insufficient memory for managed object")
  aux_String_25_Var.max_length = 2;
  aux_String_25_Var.length = 1;
  aux_String_25_Var.values = "]";
  CHECK(514, Sys_println_Mock(sys, sys_Refman, aux_String_25, aux_String_25_Refman) )
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
  ++MR_file_coverage[0].line_count[537];
  y = &y_Var;
  y_Refman = MR_new_ref(y);
  if (y_Refman == NULL) RAISE(537, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[538];
  if (y == NULL) RAISE(538, 27, "used member of empty object")
  if (y_Refman->value == NULL) RAISE(538, 38, "used member of outdated weak reference")
  if (y == NULL) RAISE(538, 27, "used member of empty object")
  if (y_Refman->value == NULL) RAISE(538, 38, "used member of outdated weak reference")
  MR_dec_ref(y->x.x_Refman);
  y->x.x_Refman = y_Refman;
  MR_inc_ref(y->x.x_Refman);
  y->x.x_Dynamic = &ComplexField_dynamic;
  y->x.x = &(y->x);
  ++MR_file_coverage[0].line_count[539];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(539, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "complex fields: ";
  CHECK(539, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  ++MR_file_coverage[0].line_count[540];
  CHECK(540, HasComplexField_run(y, y_Refman) )
  ++MR_file_coverage[0].line_count[541];
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = MR_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(541, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 1;
  aux_String_1_Var.length = 0;
  aux_String_1_Var.values = "";
  CHECK(541, Sys_println_Mock(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
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
  ++MR_file_coverage[1].line_count[65];
  new_mt = MR_alloc(sizeof(MiddleType));
  if (new_mt == NULL) RAISE(65, 49, "insufficient memory for object dynamic allocation")
  new_mt_Refman = MR_new_ref(new_mt);
  if (new_mt_Refman == NULL) RAISE(65, 38, "insufficient memory for managed object")
  CHECK(65, MiddleType_new(new_mt, new_mt_Refman, new_mt_Dynamic) )
  ++MR_file_coverage[1].line_count[66];
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

Bool TestStruct_get_Mock_active = true;
#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TestStruct.get Mock"
Returncode TestStruct_get_Mock(TestStruct* self, Ref_Manager* self_Refman, Int* x, String** s, Ref_Manager** s_Refman) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  if (!TestStruct_get_Mock_active) return TestStruct_get(self, self_Refman, x, s, s_Refman);
  ++MR_file_coverage[1].line_count[70];
  *x = 12;
  ++MR_file_coverage[1].line_count[71];
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

Bool f_test_int2str_Mock_active = true;
#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "f-test-int2str Mock"
Returncode f_test_int2str_Mock(Int x, String** s, Ref_Manager** s_Refman) {
  Returncode MR_err = OK;
  if (!f_test_int2str_Mock_active) return f_test_int2str(x, s, s_Refman);
  ++MR_file_coverage[1].line_count[74];
  USER_RAISE(74, NULL, NULL)
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

Bool TestClass_dynamic_meth_Mock_active = true;
#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "TestClass.dynamic-meth Mock"
Returncode TestClass_dynamic_meth_Mock(TestClass* self, Ref_Manager* self_Refman, TestClass_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  if (!TestClass_dynamic_meth_Mock_active) return TestClass_dynamic_meth(self, self_Refman, self_Dynamic);
  ++MR_file_coverage[1].line_count[77];
  if (self == NULL) RAISE(77, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(77, 38, "used member of outdated weak reference")
  self->num = 7;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "test-func"
Returncode test_func(void) {
  Returncode MR_err = OK;
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  TestStruct t_Var = {0};
  TestStruct* t = NULL;
  Ref_Manager* t_Refman = NULL;
  Int x = 0;
  TestClass c_Var = {0};
  TestClass* c = NULL;
  Ref_Manager* c_Refman = NULL;
  TestClass_Dynamic* c_Dynamic = &TestClass_dynamic;
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  String* aux_String_2 = NULL;
  Ref_Manager* aux_String_2_Refman = NULL;
  String* aux_String_3 = NULL;
  Ref_Manager* aux_String_3_Refman = NULL;
  ++MR_file_coverage[1].line_count[80];
  ++MR_file_coverage[1].line_count[81];
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(81, f_test_int2str_Mock(3, &(s), &(s_Refman)) )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(81, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  ++MR_file_coverage[1].line_count[82];
  CHECK(82, f_test_int2str(4, &(s), &(s_Refman)) )
  ++MR_file_coverage[1].line_count[83];
  f_test_int2str_Mock_active = false;
  ++MR_file_coverage[1].line_count[84];
  CHECK(84, f_test_int2str_Mock(5, &(s), &(s_Refman)) )
  ++MR_file_coverage[1].line_count[85];
  f_test_int2str_Mock_active = true;
  ++MR_file_coverage[1].line_count[86];
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(86, f_test_int2str_Mock(6, &(s), &(s_Refman)) )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(86, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  ++MR_file_coverage[1].line_count[88];
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(88, 38, "insufficient memory for managed object")
  CHECK(88, TestStruct_new(t, t_Refman, 0, NULL, NULL) )
  ++MR_file_coverage[1].line_count[89];
  ++MR_file_coverage[1].line_count[90];
  CHECK(90, TestStruct_get_Mock(t, t_Refman, &(x), &(aux_String_0), &(aux_String_0_Refman)) )
  ++MR_file_coverage[1].line_count[91];
  TEST_ASSERT(91, x == 12)
  ++MR_file_coverage[1].line_count[92];
  CHECK(92, TestStruct_get(t, t_Refman, &(x), &(aux_String_1), &(aux_String_1_Refman)) )
  ++MR_file_coverage[1].line_count[93];
  TEST_ASSERT(93, x == 0)
  ++MR_file_coverage[1].line_count[94];
  TestStruct_get_Mock_active = false;
  ++MR_file_coverage[1].line_count[95];
  x = 1;
  ++MR_file_coverage[1].line_count[96];
  CHECK(96, TestStruct_get_Mock(t, t_Refman, &(x), &(aux_String_2), &(aux_String_2_Refman)) )
  ++MR_file_coverage[1].line_count[97];
  TEST_ASSERT(97, x == 0)
  ++MR_file_coverage[1].line_count[98];
  TestStruct_get_Mock_active = true;
  ++MR_file_coverage[1].line_count[99];
  CHECK(99, TestStruct_get_Mock(t, t_Refman, &(x), &(aux_String_3), &(aux_String_3_Refman)) )
  ++MR_file_coverage[1].line_count[100];
  TEST_ASSERT(100, x == 12)
  ++MR_file_coverage[1].line_count[102];
  c = &c_Var;
  c_Refman = MR_new_ref(c);
  if (c_Refman == NULL) RAISE(102, 38, "insufficient memory for managed object")
  CHECK(102, TestClass_new(c, c_Refman, c_Dynamic) )
  ++MR_file_coverage[1].line_count[103];
  if (c == NULL) RAISE(103, 27, "used member of empty object")
  if (c_Refman->value == NULL) RAISE(103, 38, "used member of outdated weak reference")
  TEST_ASSERT(103, c->num == 1)
  ++MR_file_coverage[1].line_count[104];
  if (c_Dynamic == NULL) RAISE(104, 28, "dynamic call of empty object")
  CHECK(104, c_Dynamic->dynamic_meth(c, c_Refman, c_Dynamic) )
  ++MR_file_coverage[1].line_count[105];
  if (c == NULL) RAISE(105, 27, "used member of empty object")
  if (c_Refman->value == NULL) RAISE(105, 38, "used member of outdated weak reference")
  TEST_ASSERT(105, c->num == 7)
  ++MR_file_coverage[1].line_count[106];
  CHECK(106, TestClass_dynamic_meth(c, c_Refman, c_Dynamic) )
  ++MR_file_coverage[1].line_count[107];
  if (c == NULL) RAISE(107, 27, "used member of empty object")
  if (c_Refman->value == NULL) RAISE(107, 38, "used member of outdated weak reference")
  TEST_ASSERT(107, c->num == 6)
  ++MR_file_coverage[1].line_count[108];
  TestClass_dynamic_meth_Mock_active = false;
  ++MR_file_coverage[1].line_count[109];
  if (c == NULL) RAISE(109, 27, "used member of empty object")
  if (c_Refman->value == NULL) RAISE(109, 38, "used member of outdated weak reference")
  c->num = 0;
  ++MR_file_coverage[1].line_count[110];
  if (c_Dynamic == NULL) RAISE(110, 28, "dynamic call of empty object")
  CHECK(110, c_Dynamic->dynamic_meth(c, c_Refman, c_Dynamic) )
  ++MR_file_coverage[1].line_count[111];
  if (c == NULL) RAISE(111, 27, "used member of empty object")
  if (c_Refman->value == NULL) RAISE(111, 38, "used member of outdated weak reference")
  TEST_ASSERT(111, c->num == 6)
  ++MR_file_coverage[1].line_count[112];
  TestClass_dynamic_meth_Mock_active = true;
  ++MR_file_coverage[1].line_count[113];
  CHECK(113, TestClass_dynamic_meth_Mock(c, c_Refman, c_Dynamic) )
  ++MR_file_coverage[1].line_count[114];
  if (c == NULL) RAISE(114, 27, "used member of empty object")
  if (c_Refman->value == NULL) RAISE(114, 38, "used member of outdated weak reference")
  TEST_ASSERT(114, c->num == 7)
MR_cleanup:
  MR_dec_ref(aux_String_3_Refman);
  MR_dec_ref(aux_String_2_Refman);
  MR_dec_ref(aux_String_1_Refman);
  MR_dec_ref(aux_String_0_Refman);
  MR_dec_ref(c_Refman);
  MR_dec_ref(t_Refman);
  String_Del(s);
  MR_owner_dec_ref(s_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "test-another"
Returncode test_another(void) {
  Returncode MR_err = OK;
  Int x = 0;
  ++MR_file_coverage[1].line_count[118];
  ++MR_file_coverage[1].line_count[119];
  TEST_ASSERT(119, x == 0)
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
  ++MR_file_coverage[1].line_count[129];
  TEST_ASSERT(129, external_int == 6)
  ++MR_file_coverage[1].line_count[130];
  ++MR_file_coverage[1].line_count[131];
  ++MR_file_coverage[1].line_count[132];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(132, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = "bb";
  s = &s_Var;
  s_Var.values = s_Values;
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(132, 38, "insufficient memory for managed object")
  CHECK(132, String_new(s, s_Refman, aux_String_0, aux_String_0_Refman) )
  ++MR_file_coverage[1].line_count[133];
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(133, external(3, s, &(i), &(n)) )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(133, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  ++MR_file_coverage[1].line_count[134];
  TEST_ASSERT(134, i == 3)
  ++MR_file_coverage[1].line_count[135];
  if (s == NULL) RAISE(135, 29, "empty object used as sequence")
  if (s_Refman->value == NULL) RAISE(135, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (s)->length) RAISE(135, 25, "slice index out of bounds")
  TEST_ASSERT(135, (((s)->values)[0]) == 'a')
  ++MR_file_coverage[1].line_count[136];
  CHECK(136, external2(n, &(aux_Bool_0)) )
  TEST_ASSERT(136, aux_Bool_0)
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
  ++MR_file_coverage[1].line_count[140];
  dmid = &dmid_Var;
  dmid_Refman = MR_new_ref(dmid);
  if (dmid_Refman == NULL) RAISE(140, 38, "insufficient memory for managed object")
  ++MR_file_coverage[1].line_count[141];
  ttop = &ttop_Var;
  ttop_Refman = MR_new_ref(ttop);
  if (ttop_Refman == NULL) RAISE(141, 38, "insufficient memory for managed object")
  CHECK(141, TopType_new(ttop, ttop_Refman, ttop_Dynamic) )
  ++MR_file_coverage[1].line_count[142];
  if (ttop == NULL) RAISE(142, 27, "used member of empty object")
  if (ttop_Refman->value == NULL) RAISE(142, 38, "used member of outdated weak reference")
  ttop->_base._base.num_base = 12;
  ++MR_file_coverage[1].line_count[143];
  if (dmid == NULL) RAISE(143, 27, "used member of empty object")
  if (dmid_Refman->value == NULL) RAISE(143, 38, "used member of outdated weak reference")
  MR_dec_ref(dmid->item_Refman);
  dmid->item_Refman = ttop_Refman;
  MR_inc_ref(dmid->item_Refman);
  dmid->item_Dynamic = (Generic_Type_Dynamic*)&(ttop_Dynamic->_base);
  dmid->item = &(ttop->_base);
  ++MR_file_coverage[1].line_count[144];
  ++MR_file_coverage[1].line_count[145];
  if (dmid == NULL) RAISE(145, 27, "used member of empty object")
  if (dmid_Refman->value == NULL) RAISE(145, 38, "used member of outdated weak reference")
  MR_dec_ref(tbase_Refman);
  tbase_Refman = dmid->item_Refman;
  MR_inc_ref(tbase_Refman);
  tbase_Dynamic = &(((MiddleType_Dynamic*)(dmid->item_Dynamic))->_base);
  tbase = &(((MiddleType*)(dmid->item))->_base);
  ++MR_file_coverage[1].line_count[146];
  if (tbase == NULL) RAISE(146, 27, "used member of empty object")
  if (tbase_Refman->value == NULL) RAISE(146, 38, "used member of outdated weak reference")
  TEST_ASSERT(146, tbase->num_base == 12)
  ++MR_file_coverage[1].line_count[147];
  if (ttop == NULL) RAISE(147, 27, "used member of empty object")
  if (ttop_Refman->value == NULL) RAISE(147, 38, "used member of outdated weak reference")
  ttop->_base._base.num_base = 13;
  ++MR_file_coverage[1].line_count[148];
  CHECK(148, Data_set(dmid, dmid_Refman, &(ttop->_base), ttop_Refman, (void*)&(ttop_Dynamic->_base), NULL, NULL) )
  ++MR_file_coverage[1].line_count[149];
  MR_dec_ref(tbase_Refman);
  tbase_Refman = NULL;
  MR_inc_ref(tbase_Refman);
  tbase_Dynamic = NULL;
  tbase = NULL;
  ++MR_file_coverage[1].line_count[150];
  if (tbase != NULL) RAISE(150, 45, "non empty base class given as output argument")
  CHECK(150, Data_get(dmid, dmid_Refman, (void*)&(tbase), &(tbase_Refman), (void*)&(tbase_Dynamic)) )
  ++MR_file_coverage[1].line_count[151];
  if (tbase == NULL) RAISE(151, 27, "used member of empty object")
  if (tbase_Refman->value == NULL) RAISE(151, 38, "used member of outdated weak reference")
  TEST_ASSERT(151, tbase->num_base == 13)
MR_cleanup:
  MR_dec_ref(tbase_Refman);
  MR_dec_ref(ttop_Refman);
  MR_dec_ref(dmid_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "delete Mock"
Returncode delete_Mock(Ref self) {
  Returncode MR_err = OK;
  RefNode* aux_RefNode_0 = NULL;
  Ref_Manager* aux_RefNode_0_Refman = NULL;
  ++MR_file_coverage[1].line_count[182];
  if (record_delete) {
    ++MR_file_coverage[1].line_count[183];
    aux_RefNode_0 = MR_alloc(sizeof(RefNode));
    if (aux_RefNode_0 == NULL) RAISE(183, 49, "insufficient memory for object dynamic allocation")
    aux_RefNode_0_Refman = MR_new_ref(aux_RefNode_0);
    if (aux_RefNode_0_Refman == NULL) RAISE(183, 38, "insufficient memory for managed object")
    CHECK(183, RefNode_new(aux_RefNode_0, aux_RefNode_0_Refman, self, deleted_refmans, deleted_refmans_Refman) )
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
  ++MR_file_coverage[1].line_count[186];
  if (record_delete) {
    ++MR_file_coverage[1].line_count[187];
    aux_RefNode_0 = MR_alloc(sizeof(RefNode));
    if (aux_RefNode_0 == NULL) RAISE(187, 49, "insufficient memory for object dynamic allocation")
    aux_RefNode_0_Refman = MR_new_ref(aux_RefNode_0);
    if (aux_RefNode_0_Refman == NULL) RAISE(187, 38, "insufficient memory for managed object")
    CHECK(187, RefNode_new(aux_RefNode_0, aux_RefNode_0_Refman, self, deleted_links, deleted_links_Refman) )
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
  ++MR_file_coverage[1].line_count[190];
  if (record_delete) {
    ++MR_file_coverage[1].line_count[191];
    aux_RefNode_0 = MR_alloc(sizeof(RefNode));
    if (aux_RefNode_0 == NULL) RAISE(191, 49, "insufficient memory for object dynamic allocation")
    aux_RefNode_0_Refman = MR_new_ref(aux_RefNode_0);
    if (aux_RefNode_0_Refman == NULL) RAISE(191, 38, "insufficient memory for managed object")
    CHECK(191, RefNode_new(aux_RefNode_0, aux_RefNode_0_Refman, self, deleted_base_links, deleted_base_links_Refman) )
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
  ++MR_file_coverage[1].line_count[194];
  if (record_delete) {
    ++MR_file_coverage[1].line_count[195];
    aux_RefNode_0 = MR_alloc(sizeof(RefNode));
    if (aux_RefNode_0 == NULL) RAISE(195, 49, "insufficient memory for object dynamic allocation")
    aux_RefNode_0_Refman = MR_new_ref(aux_RefNode_0);
    if (aux_RefNode_0_Refman == NULL) RAISE(195, 38, "insufficient memory for managed object")
    CHECK(195, RefNode_new(aux_RefNode_0, aux_RefNode_0_Refman, self, deleted_top_links, deleted_top_links_Refman) )
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
  ++MR_file_coverage[1].line_count[201];
  TEST_ASSERT(201, ! (deleted_refmans != NULL && deleted_refmans_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[202];
  TEST_ASSERT(202, ! (deleted_links != NULL && deleted_links_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[203];
  record_delete = true;
  ++MR_file_coverage[1].line_count[205];
  l = MR_alloc(sizeof(Link));
  if (l == NULL) RAISE(205, 49, "insufficient memory for object dynamic allocation")
  l_Refman = MR_new_ref(l);
  if (l_Refman == NULL) RAISE(205, 38, "insufficient memory for managed object")
  ++MR_file_coverage[1].line_count[206];
  l_user = l;
  l_user_Refman = l_Refman;
  MR_inc_ref(l_user_Refman);
  ++MR_file_coverage[1].line_count[207];
  TEST_ASSERT(207, l != NULL && l_Refman->value != NULL)
  ++MR_file_coverage[1].line_count[208];
  TEST_ASSERT(208, l_user != NULL && l_user_Refman->value != NULL)
  ++MR_file_coverage[1].line_count[209];
  l_ref = l;
  ++MR_file_coverage[1].line_count[210];
  CHECK(210, f_remove_obj(l, l_Refman) )
  l = NULL;
  l_Refman = NULL;
  ++MR_file_coverage[1].line_count[211];
  TEST_ASSERT(211, ! (l != NULL && l_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[212];
  TEST_ASSERT(212, ! (l_user != NULL && l_user_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[213];
  TEST_ASSERT(213, ! (deleted_refmans != NULL && deleted_refmans_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[214];
  TEST_ASSERT(214, deleted_links != NULL && deleted_links_Refman->value != NULL)
  ++MR_file_coverage[1].line_count[215];
  if (deleted_links == NULL) RAISE(215, 27, "used member of empty object")
  if (deleted_links_Refman->value == NULL) RAISE(215, 38, "used member of outdated weak reference")
  TEST_ASSERT(215, deleted_links->ref == l_ref)
  ++MR_file_coverage[1].line_count[216];
  if (deleted_links == NULL) RAISE(216, 27, "used member of empty object")
  if (deleted_links_Refman->value == NULL) RAISE(216, 38, "used member of outdated weak reference")
  TEST_ASSERT(216, ! (deleted_links->next != NULL && deleted_links->next_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[217];
  MR_dec_ref(l_user_Refman);
  l_user_Refman = NULL;
  MR_inc_ref(l_user_Refman);
  l_user = NULL;
  ++MR_file_coverage[1].line_count[218];
  TEST_ASSERT(218, deleted_refmans != NULL && deleted_refmans_Refman->value != NULL)
  ++MR_file_coverage[1].line_count[219];
  if (deleted_refmans == NULL) RAISE(219, 27, "used member of empty object")
  if (deleted_refmans_Refman->value == NULL) RAISE(219, 38, "used member of outdated weak reference")
  TEST_ASSERT(219, deleted_refmans->ref == l_ref)
  ++MR_file_coverage[1].line_count[220];
  if (deleted_refmans == NULL) RAISE(220, 27, "used member of empty object")
  if (deleted_refmans_Refman->value == NULL) RAISE(220, 38, "used member of outdated weak reference")
  TEST_ASSERT(220, ! (deleted_refmans->next != NULL && deleted_refmans->next_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[222];
  record_delete = false;
  ++MR_file_coverage[1].line_count[223];
  RefNode_Del(deleted_refmans);
  MR_owner_dec_ref(deleted_refmans_Refman);
  deleted_refmans_Refman = NULL;
  deleted_refmans = NULL;
  ++MR_file_coverage[1].line_count[224];
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
  ++MR_file_coverage[1].line_count[227];
  CHECK(227, f_has_ref_rec(ref, &(*node), &(*node_Refman)) )
  ++MR_file_coverage[1].line_count[228];
  CHECK(228, f_has_ref_rec(ref, &(deleted_refmans), &(deleted_refmans_Refman)) )
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
  ++MR_file_coverage[1].line_count[231];
  TEST_ASSERT(231, (*node) != NULL && (*node_Refman)->value != NULL)
  ++MR_file_coverage[1].line_count[232];
  if (*node == NULL) RAISE(232, 27, "used member of empty object")
  if ((*node_Refman)->value == NULL) RAISE(232, 38, "used member of outdated weak reference")
  if ((*node)->ref == ref) {
    ++MR_file_coverage[1].line_count[233];
    if (*node == NULL) RAISE(233, 27, "used member of empty object")
    if ((*node_Refman)->value == NULL) RAISE(233, 38, "used member of outdated weak reference")
    next = (*node)->next;
    next_Refman = (*node)->next_Refman;
    (*node)->next = NULL;
    (*node)->next_Refman = NULL;
    ++MR_file_coverage[1].line_count[234];
    RefNode_Del(*node);
    MR_owner_dec_ref(*node_Refman);
    *node_Refman = next_Refman;
    *node = next;
    next = NULL;
    next_Refman = NULL;
  }
  else {
    ++MR_file_coverage[1].line_count[236];
    if (*node == NULL) RAISE(236, 27, "used member of empty object")
    if ((*node_Refman)->value == NULL) RAISE(236, 38, "used member of outdated weak reference")
    CHECK(236, f_has_ref_rec(ref, &((*node)->next), &((*node)->next_Refman)) )
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
  ++MR_file_coverage[1].line_count[239];
  TEST_ASSERT(239, ! (deleted_refmans != NULL && deleted_refmans_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[240];
  TEST_ASSERT(240, ! (deleted_links != NULL && deleted_links_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[241];
  TEST_ASSERT(241, ! (deleted_base_links != NULL && deleted_base_links_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[242];
  TEST_ASSERT(242, ! (deleted_top_links != NULL && deleted_top_links_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[243];
  record_delete = true;
  ++MR_file_coverage[1].line_count[245];
  b1 = MR_alloc(sizeof(BaseLink));
  if (b1 == NULL) RAISE(245, 49, "insufficient memory for object dynamic allocation")
  b1_Refman = MR_new_ref(b1);
  if (b1_Refman == NULL) RAISE(245, 38, "insufficient memory for managed object")
  ++MR_file_coverage[1].line_count[246];
  b1_ref = b1;
  ++MR_file_coverage[1].line_count[247];
  b2 = MR_alloc(sizeof(BaseLink));
  if (b2 == NULL) RAISE(247, 49, "insufficient memory for object dynamic allocation")
  b2_Refman = MR_new_ref(b2);
  if (b2_Refman == NULL) RAISE(247, 38, "insufficient memory for managed object")
  ++MR_file_coverage[1].line_count[248];
  b2_ref = b2;
  ++MR_file_coverage[1].line_count[249];
  t1 = MR_alloc(sizeof(TopLink));
  if (t1 == NULL) RAISE(249, 49, "insufficient memory for object dynamic allocation")
  t1_Refman = MR_new_ref(t1);
  if (t1_Refman == NULL) RAISE(249, 38, "insufficient memory for managed object")
  ++MR_file_coverage[1].line_count[250];
  t1_ref = t1;
  ++MR_file_coverage[1].line_count[251];
  t2 = MR_alloc(sizeof(TopLink));
  if (t2 == NULL) RAISE(251, 49, "insufficient memory for object dynamic allocation")
  t2_Refman = MR_new_ref(t2);
  if (t2_Refman == NULL) RAISE(251, 38, "insufficient memory for managed object")
  ++MR_file_coverage[1].line_count[252];
  t2_ref = t2;
  ++MR_file_coverage[1].line_count[253];
  t3 = MR_alloc(sizeof(TopLink));
  if (t3 == NULL) RAISE(253, 49, "insufficient memory for object dynamic allocation")
  t3_Refman = MR_new_ref(t3);
  if (t3_Refman == NULL) RAISE(253, 38, "insufficient memory for managed object")
  ++MR_file_coverage[1].line_count[254];
  t3_ref = t3;
  ++MR_file_coverage[1].line_count[255];
  l1 = MR_alloc(sizeof(Link));
  if (l1 == NULL) RAISE(255, 49, "insufficient memory for object dynamic allocation")
  l1_Refman = MR_new_ref(l1);
  if (l1_Refman == NULL) RAISE(255, 38, "insufficient memory for managed object")
  ++MR_file_coverage[1].line_count[256];
  l1_ref = l1;
  ++MR_file_coverage[1].line_count[257];
  l2 = MR_alloc(sizeof(Link));
  if (l2 == NULL) RAISE(257, 49, "insufficient memory for object dynamic allocation")
  l2_Refman = MR_new_ref(l2);
  if (l2_Refman == NULL) RAISE(257, 38, "insufficient memory for managed object")
  ++MR_file_coverage[1].line_count[258];
  l2_ref = l2;
  ++MR_file_coverage[1].line_count[259];
  l3 = MR_alloc(sizeof(Link));
  if (l3 == NULL) RAISE(259, 49, "insufficient memory for object dynamic allocation")
  l3_Refman = MR_new_ref(l3);
  if (l3_Refman == NULL) RAISE(259, 38, "insufficient memory for managed object")
  ++MR_file_coverage[1].line_count[260];
  l3_ref = l3;
  ++MR_file_coverage[1].line_count[262];
  if (b1 == NULL) RAISE(262, 27, "used member of empty object")
  if (b1_Refman->value == NULL) RAISE(262, 38, "used member of outdated weak reference")
  MR_dec_ref(b1->link_Refman);
  b1->link_Refman = l1_Refman;
  MR_inc_ref(b1->link_Refman);
  b1->link = l1;
  ++MR_file_coverage[1].line_count[263];
  if (b2 == NULL) RAISE(263, 27, "used member of empty object")
  if (b2_Refman->value == NULL) RAISE(263, 38, "used member of outdated weak reference")
  MR_dec_ref(b2->link_Refman);
  b2->link_Refman = l2_Refman;
  MR_inc_ref(b2->link_Refman);
  b2->link = l2;
  ++MR_file_coverage[1].line_count[264];
  if (t1 == NULL) RAISE(264, 27, "used member of empty object")
  if (t1_Refman->value == NULL) RAISE(264, 38, "used member of outdated weak reference")
  MR_dec_ref(t1->_base.link_Refman);
  t1->_base.link_Refman = l1_Refman;
  MR_inc_ref(t1->_base.link_Refman);
  t1->_base.link = l1;
  ++MR_file_coverage[1].line_count[265];
  if (t2 == NULL) RAISE(265, 27, "used member of empty object")
  if (t2_Refman->value == NULL) RAISE(265, 38, "used member of outdated weak reference")
  MR_dec_ref(t2->_base.link_Refman);
  t2->_base.link_Refman = l2_Refman;
  MR_inc_ref(t2->_base.link_Refman);
  t2->_base.link = l2;
  ++MR_file_coverage[1].line_count[266];
  if (t3 == NULL) RAISE(266, 27, "used member of empty object")
  if (t3_Refman->value == NULL) RAISE(266, 38, "used member of outdated weak reference")
  MR_dec_ref(t3->_base.link_Refman);
  t3->_base.link_Refman = l3_Refman;
  MR_inc_ref(t3->_base.link_Refman);
  t3->_base.link = l3;
  ++MR_file_coverage[1].line_count[268];
  if (l2 == NULL) RAISE(268, 27, "used member of empty object")
  if (l2_Refman->value == NULL) RAISE(268, 38, "used member of outdated weak reference")
  Link_Del(l2->next);
  MR_owner_dec_ref(l2->next_Refman);
  l2->next_Refman = l3_Refman;
  l2->next = l3;
  l3 = NULL;
  l3_Refman = NULL;
  ++MR_file_coverage[1].line_count[269];
  TEST_ASSERT(269, ! (l3 != NULL && l3_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[270];
  if (l1 == NULL) RAISE(270, 27, "used member of empty object")
  if (l1_Refman->value == NULL) RAISE(270, 38, "used member of outdated weak reference")
  Link_Del(l1->next);
  MR_owner_dec_ref(l1->next_Refman);
  l1->next_Refman = l2_Refman;
  l1->next = l2;
  l2 = NULL;
  l2_Refman = NULL;
  ++MR_file_coverage[1].line_count[271];
  TEST_ASSERT(271, ! (l2 != NULL && l2_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[272];
  if (t3 == NULL) RAISE(272, 27, "used member of empty object")
  if (t3_Refman->value == NULL) RAISE(272, 38, "used member of outdated weak reference")
  if (t3->item_Dynamic != NULL) t3->item_Dynamic->_del(t3->item);
  MR_owner_dec_ref(t3->item_Refman);
  t3->item_Refman = b2_Refman;
  t3->item_Dynamic = (Generic_Type_Dynamic*)b2_Dynamic;
  t3->item = b2;
  b2 = NULL;
  b2_Refman = NULL;
  b2_Dynamic = NULL;
  ++MR_file_coverage[1].line_count[273];
  TEST_ASSERT(273, ! (b2 != NULL && b2_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[274];
  if (t2 == NULL) RAISE(274, 27, "used member of empty object")
  if (t2_Refman->value == NULL) RAISE(274, 38, "used member of outdated weak reference")
  if (t2->item_Dynamic != NULL) t2->item_Dynamic->_del(t2->item);
  MR_owner_dec_ref(t2->item_Refman);
  t2->item_Refman = t3_Refman;
  t2->item_Dynamic = (Generic_Type_Dynamic*)&(t3_Dynamic->_base);
  t2->item = &(t3->_base);
  t3 = NULL;
  t3_Refman = NULL;
  t3_Dynamic = NULL;
  ++MR_file_coverage[1].line_count[275];
  TEST_ASSERT(275, ! (t3 != NULL && t3_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[276];
  if (t1 == NULL) RAISE(276, 27, "used member of empty object")
  if (t1_Refman->value == NULL) RAISE(276, 38, "used member of outdated weak reference")
  if (t1->_base.next_Dynamic != NULL) t1->_base.next_Dynamic->_del(t1->_base.next);
  MR_owner_dec_ref(t1->_base.next_Refman);
  t1->_base.next_Refman = t2_Refman;
  t1->_base.next_Dynamic = &(t2_Dynamic->_base);
  t1->_base.next = &(t2->_base);
  t2 = NULL;
  t2_Refman = NULL;
  t2_Dynamic = NULL;
  ++MR_file_coverage[1].line_count[277];
  TEST_ASSERT(277, ! (t2 != NULL && t2_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[278];
  if (t1 == NULL) RAISE(278, 27, "used member of empty object")
  if (t1_Refman->value == NULL) RAISE(278, 38, "used member of outdated weak reference")
  Link_Del(t1->item);
  MR_owner_dec_ref(t1->item_Refman);
  t1->item_Refman = l1_Refman;
  t1->item_Dynamic = &Link_dynamic;
  t1->item = l1;
  l1 = NULL;
  l1_Refman = NULL;
  ++MR_file_coverage[1].line_count[279];
  TEST_ASSERT(279, ! (l1 != NULL && l1_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[280];
  if (b1 == NULL) RAISE(280, 27, "used member of empty object")
  if (b1_Refman->value == NULL) RAISE(280, 38, "used member of outdated weak reference")
  if (b1->next_Dynamic != NULL) b1->next_Dynamic->_del(b1->next);
  MR_owner_dec_ref(b1->next_Refman);
  b1->next_Refman = t1_Refman;
  b1->next_Dynamic = &(t1_Dynamic->_base);
  b1->next = &(t1->_base);
  t1 = NULL;
  t1_Refman = NULL;
  t1_Dynamic = NULL;
  ++MR_file_coverage[1].line_count[281];
  TEST_ASSERT(281, ! (t1 != NULL && t1_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[283];
  TEST_ASSERT(283, ! (deleted_refmans != NULL && deleted_refmans_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[284];
  TEST_ASSERT(284, ! (deleted_links != NULL && deleted_links_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[285];
  TEST_ASSERT(285, ! (deleted_base_links != NULL && deleted_base_links_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[286];
  TEST_ASSERT(286, ! (deleted_top_links != NULL && deleted_top_links_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[287];
  if (b1_Dynamic != NULL) b1_Dynamic->_del(b1);
  MR_owner_dec_ref(b1_Refman);
  b1_Refman = NULL;
  b1_Dynamic = NULL;
  b1 = NULL;
  ++MR_file_coverage[1].line_count[288];
  TEST_ASSERT(288, ! (b1 != NULL && b1_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[290];
  record_delete = false;
  ++MR_file_coverage[1].line_count[291];
  CHECK(291, f_has_ref(b1_ref, &(deleted_base_links), &(deleted_base_links_Refman)) )
  ++MR_file_coverage[1].line_count[292];
  CHECK(292, f_has_ref(t1_ref, &(deleted_top_links), &(deleted_top_links_Refman)) )
  ++MR_file_coverage[1].line_count[293];
  CHECK(293, f_has_ref_rec(t1_ref, &(deleted_base_links), &(deleted_base_links_Refman)) )
  ++MR_file_coverage[1].line_count[294];
  CHECK(294, f_has_ref(t2_ref, &(deleted_top_links), &(deleted_top_links_Refman)) )
  ++MR_file_coverage[1].line_count[295];
  CHECK(295, f_has_ref_rec(t2_ref, &(deleted_base_links), &(deleted_base_links_Refman)) )
  ++MR_file_coverage[1].line_count[296];
  CHECK(296, f_has_ref(t3_ref, &(deleted_top_links), &(deleted_top_links_Refman)) )
  ++MR_file_coverage[1].line_count[297];
  CHECK(297, f_has_ref_rec(t3_ref, &(deleted_base_links), &(deleted_base_links_Refman)) )
  ++MR_file_coverage[1].line_count[298];
  CHECK(298, f_has_ref(b2_ref, &(deleted_base_links), &(deleted_base_links_Refman)) )
  ++MR_file_coverage[1].line_count[299];
  CHECK(299, f_has_ref(l1_ref, &(deleted_links), &(deleted_links_Refman)) )
  ++MR_file_coverage[1].line_count[300];
  CHECK(300, f_has_ref(l2_ref, &(deleted_links), &(deleted_links_Refman)) )
  ++MR_file_coverage[1].line_count[301];
  CHECK(301, f_has_ref(l3_ref, &(deleted_links), &(deleted_links_Refman)) )
  ++MR_file_coverage[1].line_count[303];
  TEST_ASSERT(303, ! (deleted_refmans != NULL && deleted_refmans_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[304];
  TEST_ASSERT(304, ! (deleted_links != NULL && deleted_links_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[305];
  TEST_ASSERT(305, ! (deleted_base_links != NULL && deleted_base_links_Refman->value != NULL))
  ++MR_file_coverage[1].line_count[306];
  TEST_ASSERT(306, ! (deleted_top_links != NULL && deleted_top_links_Refman->value != NULL))
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
  ++MR_file_coverage[1].line_count[310];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(310, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 15;
  aux_String_0_Var.length = 14;
  aux_String_0_Var.values = "tested message";
  USER_RAISE(310, aux_String_0, aux_String_0_Refman)
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
  ++MR_file_coverage[1].line_count[313];
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; break
    ++MR_file_coverage[1].line_count[314];
    CHECK(314, f_raise_message() )

#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  } while (false);
  --MR_trace_ignore_count;
  MR_err = OK;
  ++MR_file_coverage[1].line_count[315];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(315, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 17;
  aux_String_0_Var.length = 16;
  aux_String_0_Var.values = "ignore and raise";
  USER_RAISE(315, aux_String_0, aux_String_0_Refman)
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
  ++MR_file_coverage[1].line_count[318];
  TEST_ASSERT(318, 1 == 2)
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
  ++MR_file_coverage[1].line_count[321];
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(321, f_raise_message() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(321, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  ++MR_file_coverage[1].line_count[322];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(322, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 18;
  aux_String_0_Var.length = 17;
  aux_String_0_Var.values = "good assert error";
  USER_RAISE(322, aux_String_0, aux_String_0_Refman)
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
  ++MR_file_coverage[1].line_count[325];
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(325, f_test_void() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(325, 16, "error not raised")
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
  ++MR_file_coverage[1].line_count[328];
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
    CHECK(328, f_raise_message() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(328, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(328)
  }
  MR_expected_error = MR_expected_error_prev;}
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "new Mock"
Returncode new_Mock(Bool* alloc_success) {
  Returncode MR_err = OK;
  ++MR_file_coverage[1].line_count[333];
  *alloc_success = true;
  ++MR_file_coverage[1].line_count[334];
  if (new_fail_countdown > 0) {
    ++MR_file_coverage[1].line_count[335];
    new_fail_countdown -= 1;
    ++MR_file_coverage[1].line_count[336];
    if (new_fail_countdown == 0) {
      ++MR_file_coverage[1].line_count[337];
      *alloc_success = false;
    }
  }
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "f-alloc"
Returncode f_alloc(void) {
  Returncode MR_err = OK;
  String* string = NULL;
  Ref_Manager* string_Refman = NULL;
  ++MR_file_coverage[1].line_count[340];
  string = MR_new_string(16);
  if (string == NULL) RAISE(340, 49, "insufficient memory for object dynamic allocation")
  string_Refman = MR_new_ref(string);
  if (string_Refman == NULL) RAISE(340, 38, "insufficient memory for managed object")
  ++MR_file_coverage[1].line_count[341];
  TEST_ASSERT(341, string != NULL && string_Refman->value != NULL)
MR_cleanup:
  String_Del(string);
  MR_owner_dec_ref(string_Refman);
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
  ++MR_file_coverage[1].line_count[344];
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
    CHECK(344, f_raise_message() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(344, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(344)
  }
  MR_expected_error = MR_expected_error_prev;}
  ++MR_file_coverage[1].line_count[345];
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
    CHECK(345, f_ignore_and_raise() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(345, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(345)
  }
  MR_expected_error = MR_expected_error_prev;}
  ++MR_file_coverage[1].line_count[346];
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
    CHECK(346, f_failed_assert() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(346, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(346)
  }
  MR_expected_error = MR_expected_error_prev;}
  ++MR_file_coverage[1].line_count[347];
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
    CHECK(347, f_good_assert_error() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(347, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(347)
  }
  MR_expected_error = MR_expected_error_prev;}
  ++MR_file_coverage[1].line_count[348];
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
    CHECK(348, f_failed_assert_error() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(348, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(348)
  }
  MR_expected_error = MR_expected_error_prev;}
  ++MR_file_coverage[1].line_count[349];
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(349, f_wrong_message_assert_error() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(349, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  ++MR_file_coverage[1].line_count[350];
  ++MR_file_coverage[1].line_count[351];
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
    if (fun == NULL) RAISE(351, 21, "empty function called")
    CHECK(351, fun() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(351, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(351)
  }
  MR_expected_error = MR_expected_error_prev;}
  ++MR_file_coverage[1].line_count[352];
  base_var = &base_var_Var;
  base_var_Refman = MR_new_ref(base_var);
  if (base_var_Refman == NULL) RAISE(352, 38, "insufficient memory for managed object")
  CHECK(352, BaseType_new(base_var, base_var_Refman, base_var_Dynamic) )
  ++MR_file_coverage[1].line_count[353];
  base_user = base_var;
  base_user_Refman = base_var_Refman;
  MR_inc_ref(base_user_Refman);
  base_user_Dynamic = base_var_Dynamic;
  ++MR_file_coverage[1].line_count[354];
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
    if (base_user != NULL) RAISE(354, 45, "non empty base class given as output argument")
    CHECK(354, test_mid_out((void*)&(base_user), &(base_user_Refman), (void*)&(base_user_Dynamic)) )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(354, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(354)
  }
  MR_expected_error = MR_expected_error_prev;}
  ++MR_file_coverage[1].line_count[356];
  arr = MR_new_array(2, sizeof(Int));
  if (arr == NULL) RAISE(356, 49, "insufficient memory for object dynamic allocation")
  arr_Refman = MR_new_ref(arr);
  if (arr_Refman == NULL) RAISE(356, 38, "insufficient memory for managed object")
  ++MR_file_coverage[1].line_count[357];
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
    if (arr == NULL) RAISE(357, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(357, 40, "outdated weak reference used as sequence")
    if ((6) < 0 || (6) >= (arr)->length) RAISE(357, 25, "slice index out of bounds")
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(357, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(357)
  }
  MR_expected_error = MR_expected_error_prev;}
  ++MR_file_coverage[1].line_count[358];
  arr2 = arr;
  arr2_Refman = arr_Refman;
  MR_inc_ref(arr2_Refman);
  ++MR_file_coverage[1].line_count[359];
  MR_owner_dec_ref(arr_Refman);
  arr_Refman = NULL;
  arr = NULL;
  ++MR_file_coverage[1].line_count[360];
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
    if (arr == NULL) RAISE(360, 27, "used member of empty object")
    if (arr_Refman->value == NULL) RAISE(360, 38, "used member of outdated weak reference")
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(360, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(360)
  }
  MR_expected_error = MR_expected_error_prev;}
  ++MR_file_coverage[1].line_count[361];
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
    if (arr2 == NULL) RAISE(361, 27, "used member of empty object")
    if (arr2_Refman->value == NULL) RAISE(361, 38, "used member of outdated weak reference")
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(361, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(361)
  }
  MR_expected_error = MR_expected_error_prev;}
  ++MR_file_coverage[1].line_count[362];
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
    if (arr == NULL) RAISE(362, 29, "empty object used as sequence")
    if (arr_Refman->value == NULL) RAISE(362, 40, "outdated weak reference used as sequence")
    if ((0) < 0 || (0) >= (arr)->length) RAISE(362, 25, "slice index out of bounds")
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(362, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(362)
  }
  MR_expected_error = MR_expected_error_prev;}
  ++MR_file_coverage[1].line_count[363];
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
    if (arr2 == NULL) RAISE(363, 29, "empty object used as sequence")
    if (arr2_Refman->value == NULL) RAISE(363, 40, "outdated weak reference used as sequence")
    if ((0) < 0 || (0) >= (arr2)->length) RAISE(363, 25, "slice index out of bounds")
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(363, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(363)
  }
  MR_expected_error = MR_expected_error_prev;}
  ++MR_file_coverage[1].line_count[364];
  ++MR_file_coverage[1].line_count[365];
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
    if (top_Dynamic == NULL) RAISE(365, 28, "dynamic call of empty object")
    CHECK(365, top_Dynamic->_base._base.meth2(&(top->_base._base), top_Refman, &(top_Dynamic->_base._base)) )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(365, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(365)
  }
  MR_expected_error = MR_expected_error_prev;}
  ++MR_file_coverage[1].line_count[366];
  new_fail_countdown = 1;
  ++MR_file_coverage[1].line_count[367];
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "insufficient memory for object dynamic allocation";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(367, f_alloc() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(367, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(367)
  }
  MR_expected_error = MR_expected_error_prev;}
  ++MR_file_coverage[1].line_count[368];
  new_fail_countdown = 2;
  ++MR_file_coverage[1].line_count[369];
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "insufficient memory for managed object";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(369, f_alloc() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(369, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(369)
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

Bool Sys_println_Mock_active = true;
#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "Sys.println Mock"
Returncode Sys_println_Mock(Sys* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(text_Refman);
  if (!Sys_println_Mock_active) return Sys_println(self, self_Refman, text, text_Refman);
  ++MR_file_coverage[1].line_count[372];
  TEST_ASSERT(372, text != NULL && text_Refman->value != NULL)
MR_cleanup:
  MR_dec_ref(text_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-test1.4.mr"
#define MR_FUNC_NAME "test-cover-all"
Returncode test_cover_all(void) {
  Returncode MR_err = OK;
  MiddleType mid_Var = {{0}};
  MiddleType* mid = NULL;
  Ref_Manager* mid_Refman = NULL;
  MiddleType_Dynamic* mid_Dynamic = &MiddleType_dynamic;
  ++MR_file_coverage[1].line_count[375];
  mid = &mid_Var;
  mid_Refman = MR_new_ref(mid);
  if (mid_Refman == NULL) RAISE(375, 38, "insufficient memory for managed object")
  CHECK(375, MiddleType_new(mid, mid_Refman, mid_Dynamic) )
  ++MR_file_coverage[1].line_count[376];
  if (mid_Dynamic == NULL) RAISE(376, 28, "dynamic call of empty object")
  CHECK(376, mid_Dynamic->_base.meth1(&(mid->_base), mid_Refman, &(mid_Dynamic->_base), 0, NULL, NULL) )
  ++MR_file_coverage[1].line_count[377];
  if (mid_Dynamic == NULL) RAISE(377, 28, "dynamic call of empty object")
  CHECK(377, mid_Dynamic->_base.meth2(&(mid->_base), mid_Refman, &(mid_Dynamic->_base)) )
  ++MR_file_coverage[1].line_count[378];
  if (mid_Dynamic == NULL) RAISE(378, 28, "dynamic call of empty object")
  CHECK(378, mid_Dynamic->meth4(mid, mid_Refman, mid_Dynamic) )
  ++MR_file_coverage[1].line_count[379];
  if (mid_Dynamic == NULL) RAISE(379, 28, "dynamic call of empty object")
  CHECK(379, mid_Dynamic->meth5(mid, mid_Refman, mid_Dynamic, 0, NULL, NULL) )
MR_cleanup:
  MR_dec_ref(mid_Refman);
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
  RUN_TEST(test_cover_all);
  MR_success &= MR_test_coverage(MR_file_coverage, 3);
  return MR_success? OK : FAIL;
}

TEST_MAIN_FUNC
