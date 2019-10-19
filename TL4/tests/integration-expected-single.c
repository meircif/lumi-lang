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
    CHECK_REF(212, self, self_Refman)
    self->num = x;
    CHECK_REF(213, self, self_Refman)
    aux_Ref_Manager = self->text_Refman;
    self->text_Refman = s_Refman;
    LUMI_inc_ref(self->text_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->text = s;
    if (x < 0) {
        INIT_NEW(215, aux_TestStruct_0, LUMI_alloc(sizeof(integration_M_TestStruct)));
        LUMI_err = integration_M_TestStruct_new(aux_TestStruct_0, aux_TestStruct_0_Refman, x + 1, s, s_Refman);
        CHECK(215)
        aux_TestStruct_1 = aux_TestStruct_0;
        aux_TestStruct_1_Refman = aux_TestStruct_0_Refman;
        aux_TestStruct_0 = NULL;
        aux_TestStruct_0_Refman = NULL;
        CHECK_REF(215, self, self_Refman)
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
    CHECK_REF(222, self, self_Refman)
    *x = self->num;
    CHECK_REF(223, self, self_Refman)
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
    CHECK_REF(226, self, self_Refman)
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
    CHECK_REF(235, self, self_Refman)
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
    CHECK_REF(238, self, self_Refman)
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
    CHECK_REF(241, self, self_Refman)
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
    CHECK_REF(244, self, self_Refman)
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
    CHECK_REF(377, self, self_Refman)
    aux_Ref_Manager = self->item_Refman;
    self->item_Refman = x_Refman;
    self->item_Dynamic = x_Dynamic;
    LUMI_inc_ref(self->item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->item = x;
    CHECK_REF(378, self, self_Refman)
    aux_Ref_Manager = self->arr_Refman;
    self->arr_Refman = arr_Refman;
    LUMI_inc_ref(self->arr_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->arr = arr;
    INIT_NEW(379, d, LUMI_alloc(sizeof(integration_M_Data)));
    CHECK_REF(380, self, self_Refman)
    CHECK_REF(380, d, d_Refman)
    aux_Ref_Manager = d->item_Refman;
    d->item_Refman = self->item_Refman;
    d->item_Dynamic = self->item_Dynamic;
    LUMI_inc_ref(d->item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    d->item = self->item;
    CHECK_REF(381, d, d_Refman)
    CHECK_REF(381, self, self_Refman)
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
    CHECK_REF(384, self, self_Refman)
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
    CHECK_REF(459, self, self_Refman)
    aux_Ref_Manager = self->value_Refman;
    self->value_Refman = value_Refman;
    self->value_Dynamic = value_Dynamic;
    LUMI_inc_ref(self->value_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->value = value;
    CHECK_REF(460, self, self_Refman)
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
    CHECK_REF(463, self, self_Refman)
    INIT_NEW(463, aux_ContainerIterator_0, LUMI_alloc(sizeof(integration_M_ContainerIterator)));
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
    CHECK_REF(469, self, self_Refman)
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
    CHECK_REF(472, self, self_Refman)
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
    CHECK_REF(475, self, self_Refman)
    CHECK_REF(475, self->curr, self->curr_Refman)
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
    CHECK_REF(478, self, self_Refman)
    CHECK_REF(478, self->curr, self->curr_Refman)
    CHECK_REF(478, self, self_Refman)
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
    INIT_STRING_CONST(538, aux_String_0, "$");
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(538)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_0_Refman);
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
    CHECK_REF(543, self, self_Refman)
    x = &(self->x);
    x_Refman = self_Refman;
    LUMI_inc_ref(x_Refman);
    x_Dynamic = &integration_M_ComplexField_dynamic;
    CHECK_REF(544, self, self_Refman)
    aux_Ref_Manager = x_Refman;
    x_Refman = self_Refman;
    x_Dynamic = &integration_M_ComplexField_dynamic;
    LUMI_inc_ref(x_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    x = &(self->x);
    if (x_Dynamic == NULL) RAISE(545, empty_object)
    LUMI_err = x_Dynamic->meth(x, x_Refman, x_Dynamic);
    CHECK(545)
    CHECK_REF(546, self, self_Refman)
    LUMI_err = integration_M_ComplexField_meth(&(self->x), self_Refman, &integration_M_ComplexField_dynamic);
    CHECK(546)
    CHECK_REF(547, self, self_Refman)
    LUMI_err = integration_M_ComplexField_meth(&(self->x), self_Refman, &integration_M_ComplexField_dynamic);
    CHECK(547)
    CHECK_REF(548, self, self_Refman)
    x2 = self->x.x;
    x2_Refman = self->x.x_Refman;
    LUMI_inc_ref(x2_Refman);
    x2_Dynamic = self->x.x_Dynamic;
    CHECK_REF(549, self, self_Refman)
    aux_Ref_Manager = x2_Refman;
    x2_Refman = self->x.x_Refman;
    x2_Dynamic = self->x.x_Dynamic;
    LUMI_inc_ref(x2_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    x2 = self->x.x;
    if (x2_Dynamic == NULL) RAISE(550, empty_object)
    LUMI_err = x2_Dynamic->meth(x2, x2_Refman, x2_Dynamic);
    CHECK(550)
    CHECK_REF(551, self, self_Refman)
    if (self->x.x_Dynamic == NULL) RAISE(551, empty_object)
    LUMI_err = self->x.x_Dynamic->meth(self->x.x, self->x.x_Refman, self->x.x_Dynamic);
    CHECK(551)
    CHECK_REF(552, self, self_Refman)
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
    INIT_STRING_CONST(36, aux_String_0, "I am a simple function");
    LUMI_err = Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(36)
    INIT_STRING_CONST(40, aux_String_1, "I am a multiline\nstring\n");
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
    CHECK(37)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
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
    INIT_STRING_CONST(53, aux_String_0, "some string");
    aux_Ref_Manager = *s_Refman;
    *s_Refman = aux_String_0_Refman;
    LUMI_inc_ref(*s_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    *s = aux_String_0;
    INIT_STRING_CONST(56, aux_String_1, "some\nstring");
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
    if (*f == NULL) RAISE(60, empty_object)
    LUMI_err = (*f)();
    CHECK(60)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
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
    CHECK_REF(64, t, t_Refman)
    CHECK_REF(64, t->ts, t->ts_Refman)
    CHECK_REF(64, t->ts->ts, t->ts->ts_Refman)
    CHECK_REF(64, t, t_Refman)
    CHECK_REF(64, t->ts, t->ts_Refman)
    CHECK_REF(64, *to, (*to_Refman))
    CHECK_REF(64, t, t_Refman)
    t->num = ((*to)->num + t->ts->num) + t->ts->ts->num;
    CHECK_REF(65, t, t_Refman)
    CHECK_REF(65, *to, (*to_Refman))
    (*to)->num = t->num;
    CHECK_REF(66, t, t_Refman)
    CHECK_REF(66, t->ts, t->ts_Refman)
    CHECK_REF(66, t->ts->ts, t->ts->ts_Refman)
    t->ts->ts->num = 4;
    CHECK_REF(67, t, t_Refman)
    t->fun = integration_M_f_test_void;
    CHECK_REF(68, t, t_Refman)
    if (t->fun == NULL) RAISE(68, empty_object)
    LUMI_err = t->fun();
    CHECK(68)
    INIT_STRING_CONST(69, aux_String_0, "");
    LUMI_err = integration_M_TestStruct_new(t, t_Refman, 0, aux_String_0, aux_String_0_Refman);
    CHECK(69)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_0_Refman);
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
    INIT_VAR(89, aux_Array_0)
    aux_Array_0_Var.length = 2;
    aux_Array_0_Var.values = (Byte*)((arrs)->values) + (4);
    CHECK_REF(89, arrs, arrs_Refman)
    if ((4) < 0 || (2) < 0 || (4) + (2) > (arrs)->length) RAISE(89, slice_index)
    CHECK_REF(89, aux_Array_0, arrs_Refman)
    if ((4) < 0 || (4) >= (aux_Array_0)->length) RAISE(89, slice_index)
    INIT_VAR(89, aux_String_0)
    aux_String_0_Var.length = 3;
    aux_String_0_Var.max_length = aux_String_0_Var.length + 1;
    aux_String_0_Var.values = ((((String*)((aux_Array_0)->values)) + 4))->values + (1);
    CHECK_REF(89, ((String*)((aux_Array_0)->values)) + 4, arrs_Refman)
    if ((1) < 0 || (3) < 0 || (1) + (3) > ((((String*)((aux_Array_0)->values)) + 4))->length) RAISE(89, slice_index)
    CHECK_REF(89, aux_String_0, arrs_Refman)
    if ((0) < 0 || (0) >= (aux_String_0)->length) RAISE(89, slice_index)
    CHECK_REF(89, arrs, arrs_Refman)
    if ((3) < 0 || (3) >= (arrs)->length) RAISE(89, slice_index)
    CHECK_REF(89, ((String*)((arrs)->values)) + 3, arrs_Refman)
    if ((2) < 0 || (2) >= ((((String*)((arrs)->values)) + 3))->length) RAISE(89, slice_index)
    INIT_VAR(89, aux_String_1)
    aux_String_1_Var.length = 7;
    aux_String_1_Var.max_length = aux_String_1_Var.length + 1;
    aux_String_1_Var.values = (s)->values + (4);
    CHECK_REF(89, s, s_Refman)
    if ((4) < 0 || (7) < 0 || (4) + (7) > (s)->length) RAISE(89, slice_index)
    CHECK_REF(89, aux_String_1, s_Refman)
    if ((2) < 0 || (2) >= (aux_String_1)->length) RAISE(89, slice_index)
    CHECK_REF(89, s, s_Refman)
    if ((2) < 0 || (2) >= (s)->length) RAISE(89, slice_index)
    *c = (((((s)->values)[2]) + (((aux_String_1)->values)[2])) + ((((((String*)((arrs)->values)) + 3))->values)[2])) + (((aux_String_0)->values)[0]);
    INIT_VAR(91, aux_Array_1)
    aux_Array_1_Var.length = 3;
    aux_Array_1_Var.values = (Byte*)((arri)->values) + (3);
    CHECK_REF(91, arri, arri_Refman)
    if ((3) < 0 || (3) < 0 || (3) + (3) > (arri)->length) RAISE(91, slice_index)
    INIT_VAR(91, aux_Array_2)
    aux_Array_2_Var.length = 2;
    aux_Array_2_Var.values = (Byte*)((aux_Array_1)->values) + (1);
    CHECK_REF(91, aux_Array_1, arri_Refman)
    if ((1) < 0 || (2) < 0 || (1) + (2) > (aux_Array_1)->length) RAISE(91, slice_index)
    CHECK_REF(91, aux_Array_2, arri_Refman)
    if ((1) < 0 || (1) >= (aux_Array_2)->length) RAISE(91, slice_index)
    INIT_VAR(90, aux_Array_3)
    aux_Array_3_Var.length = 4;
    aux_Array_3_Var.values = (Byte*)((arrt)->values) + (2);
    CHECK_REF(90, arrt, arrt_Refman)
    if ((2) < 0 || (4) < 0 || (2) + (4) > (arrt)->length) RAISE(90, slice_index)
    CHECK_REF(90, aux_Array_3, arrt_Refman)
    if ((1) < 0 || (1) >= (aux_Array_3)->length) RAISE(90, slice_index)
    CHECK_REF(90, ((integration_M_TestStruct*)((aux_Array_3)->values)) + 1, arrt_Refman)
    CHECK_REF(90, arrt, arrt_Refman)
    if ((4) < 0 || (4) >= (arrt)->length) RAISE(90, slice_index)
    CHECK_REF(90, ((integration_M_TestStruct*)((arrt)->values)) + 4, arrt_Refman)
    CHECK_REF(90, arri, arri_Refman)
    if ((2) < 0 || (2) >= (arri)->length) RAISE(90, slice_index)
    CHECK_REF(90, arri, arri_Refman)
    if ((((*i) + 3) - (((Int*)((arri)->values))[2])) < 0 || (*i + 3 - (((Int*)((arri)->values))[2])) >= (arri)->length) RAISE(90, slice_index)
    *i = (((((Int*)((arri)->values))[*i + 3 - (((Int*)((arri)->values))[2])]) + (((integration_M_TestStruct*)((arrt)->values)) + 4)->num) + (((integration_M_TestStruct*)((aux_Array_3)->values)) + 1)->num) + (((Int*)((aux_Array_2)->values))[1]);
    INIT_VAR(92, aux_Array_4)
    aux_Array_4_Var.length = 4;
    aux_Array_4_Var.values = (Byte*)((arri)->values) + (2);
    CHECK_REF(92, arri, arri_Refman)
    if ((2) < 0 || (4) < 0 || (2) + (4) > (arri)->length) RAISE(92, slice_index)
    CHECK_REF(92, aux_Array_4, arri_Refman)
    if ((1) < 0 || (1) >= (aux_Array_4)->length) RAISE(92, slice_index)
    INIT_VAR(92, aux_Array_5)
    aux_Array_5_Var.length = 5 * ((*i) - 1);
    aux_Array_5_Var.values = (Byte*)((arri)->values) + ((2 - (*i)) + (((Int*)((aux_Array_4)->values))[1]));
    CHECK_REF(92, arri, arri_Refman)
    if ((2 - (*i) + (((Int*)((aux_Array_4)->values))[1])) < 0 || (5 * (*i - 1)) < 0 || (2 - (*i) + (((Int*)((aux_Array_4)->values))[1])) + (5 * (*i - 1)) > (arri)->length) RAISE(92, slice_index)
    aux_Ref_Manager = *arrio_Refman;
    *arrio_Refman = arri_Refman;
    LUMI_inc_ref(*arrio_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    *arrio = aux_Array_5;
    CHECK_REF(93, arrs, arrs_Refman)
    if ((4) < 0 || (4) >= (arrs)->length) RAISE(93, slice_index)
    aux_Ref_Manager = s_Refman;
    s_Refman = arrs_Refman;
    LUMI_inc_ref(s_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    s = ((String*)((arrs)->values)) + 4;
    INIT_VAR(94, aux_Array_6)
    aux_Array_6_Var.length = 7;
    aux_Array_6_Var.values = (Byte*)((arrs)->values) + (2);
    CHECK_REF(94, arrs, arrs_Refman)
    if ((2) < 0 || (7) < 0 || (2) + (7) > (arrs)->length) RAISE(94, slice_index)
    aux_Ref_Manager = *arrso_Refman;
    *arrso_Refman = arrs_Refman;
    LUMI_inc_ref(*arrso_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    *arrso = aux_Array_6;
    CHECK_REF(95, arrt, arrt_Refman)
    if ((4) < 0 || (4) >= (arrt)->length) RAISE(95, slice_index)
    aux_Ref_Manager = *t_Refman;
    *t_Refman = arrt_Refman;
    LUMI_inc_ref(*t_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    *t = ((integration_M_TestStruct*)((arrt)->values)) + 4;
    INIT_VAR(96, aux_Array_7)
    aux_Array_7_Var.length = 7;
    aux_Array_7_Var.values = (Byte*)((arrt)->values) + (2);
    CHECK_REF(96, arrt, arrt_Refman)
    if ((2) < 0 || (7) < 0 || (2) + (7) > (arrt)->length) RAISE(96, slice_index)
    aux_Ref_Manager = *arrto_Refman;
    *arrto_Refman = arrt_Refman;
    LUMI_inc_ref(*arrto_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    *arrto = aux_Array_7;
    CHECK_REF(97, arrd, arrd_Refman)
    if ((4) < 0 || (4) >= (arrd)->length) RAISE(97, slice_index)
    aux_Ref_Manager = *d_Refman;
    *d_Refman = arrd_Refman;
    *d_Dynamic = &integration_M_TestClass_dynamic;
    LUMI_inc_ref(*d_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    *d = ((integration_M_TestClass*)((arrd)->values)) + 4;
    INIT_VAR(98, aux_Array_8)
    aux_Array_8_Var.length = 7;
    aux_Array_8_Var.values = (Byte*)((arrd)->values) + (2);
    CHECK_REF(98, arrd, arrd_Refman)
    if ((2) < 0 || (7) < 0 || (2) + (7) > (arrd)->length) RAISE(98, slice_index)
    aux_Ref_Manager = *arrdo_Refman;
    *arrdo_Refman = arrd_Refman;
    LUMI_inc_ref(*arrdo_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    *arrdo = aux_Array_8;
    CHECK_REF(99, arrf, arrf_Refman)
    if ((4) < 0 || (4) >= (arrf)->length) RAISE(99, slice_index)
    *f = ((Returncode (**)(void))((arrf)->values))[4];
    INIT_VAR(100, aux_Array_9)
    aux_Array_9_Var.length = 7;
    aux_Array_9_Var.values = (Byte*)((arrf)->values) + (2);
    CHECK_REF(100, arrf, arrf_Refman)
    if ((2) < 0 || (7) < 0 || (2) + (7) > (arrf)->length) RAISE(100, slice_index)
    aux_Ref_Manager = *arrfo_Refman;
    *arrfo_Refman = arrf_Refman;
    LUMI_inc_ref(*arrfo_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    *arrfo = aux_Array_9;
    CHECK_REF(101, arrf, arrf_Refman)
    if ((4) < 0 || (4) >= (arrf)->length) RAISE(101, slice_index)
    if (((Returncode (**)(void))((arrf)->values))[4] == NULL) RAISE(101, empty_object)
    LUMI_err = (((Returncode (**)(void))((arrf)->values))[4])();
    CHECK(101)
    CHECK_REF(102, *arrfo, (*arrfo_Refman))
    if ((4) < 0 || (4) >= ((*arrfo))->length) RAISE(102, slice_index)
    if (((Returncode (**)(void))(((*arrfo))->values))[4] == NULL) RAISE(102, empty_object)
    LUMI_err = (((Returncode (**)(void))(((*arrfo))->values))[4])();
    CHECK(102)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_Array_9_Refman);
    LUMI_var_dec_ref(aux_Array_8_Refman);
    LUMI_var_dec_ref(aux_Array_7_Refman);
    LUMI_var_dec_ref(aux_Array_6_Refman);
    LUMI_var_dec_ref(aux_Array_5_Refman);
    LUMI_var_dec_ref(aux_Array_4_Refman);
    LUMI_var_dec_ref(aux_Array_3_Refman);
    LUMI_var_dec_ref(aux_Array_2_Refman);
    LUMI_var_dec_ref(aux_Array_1_Refman);
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
    LUMI_var_dec_ref(aux_Array_0_Refman);
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
    INIT_VAR(119, tv)
    LUMI_err = integration_M_TestStruct_new(tv, tv_Refman, 0, NULL, NULL);
    CHECK(119)
    INIT_VAR(120, dv)
    LUMI_err = integration_M_TestClass_new(dv, dv_Refman, dv_Dynamic);
    CHECK(120)
    INIT_VAR(121, sv)
    sv_Var.values = sv_Values;
    INIT_VAR(123, ia)
    ia_Var.values = ia_Values;
    INIT_VAR(124, ta)
    ta_Var.values = ta_Values;
    INIT_VAR(125, da)
    da_Var.values = da_Values;
    INIT_VAR(126, sa)
    sa_Var.values = sa_Values;
    LUMI_set_var_string_array(12, 7, sa, sa_Chars);
    INIT_VAR(127, fa)
    fa_Var.values = fa_Values;
    INIT_NEW(128, tn, LUMI_alloc(sizeof(integration_M_TestStruct)));
    LUMI_err = integration_M_TestStruct_new(tn, tn_Refman, 0, NULL, NULL);
    CHECK(128)
    INIT_NEW(129, dn, LUMI_alloc(sizeof(integration_M_TestClass)));
    LUMI_err = integration_M_TestClass_new(dn, dn_Refman, dn_Dynamic);
    CHECK(129)
    CHECK_REF(130, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(130, slice_index)
    INIT_NEW(130, sn, LUMI_new_string(((Int*)((arr)->values))[0]));
    CHECK_REF(131, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(131, slice_index)
    INIT_NEW(131, ian, LUMI_new_array(((Int*)((arr)->values))[0], sizeof(Int)));
    CHECK_REF(132, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(132, slice_index)
    INIT_NEW(132, tan, LUMI_new_array(((Int*)((arr)->values))[0], sizeof(integration_M_TestStruct)));
    CHECK_REF(133, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(133, slice_index)
    INIT_NEW(133, dan, LUMI_new_array(((Int*)((arr)->values))[0], sizeof(integration_M_TestClass)));
    CHECK_REF(134, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(134, slice_index)
    CHECK_REF(134, arr, arr_Refman)
    if ((1) < 0 || (1) >= (arr)->length) RAISE(134, slice_index)
    INIT_NEW(134, san, LUMI_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]));
    CHECK_REF(135, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(135, slice_index)
    INIT_NEW(135, sfn, LUMI_new_array(((Int*)((arr)->values))[0], sizeof(Func)));
    CHECK_REF(136, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(136, slice_index)
    ix = ((Int*)((arr)->values))[0];
    si = text;
    si_Refman = text_Refman;
    LUMI_inc_ref(si_Refman);
    INIT_STRING_CONST(138, aux_String_0, "some string");
    INIT_VAR(138, isv)
    isv_Var.values = isv_Values;
    LUMI_err = String_new(isv, isv_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(138)
    INIT_NEW(139, isn, LUMI_new_string(i));
    LUMI_err = String_new(isn, isn_Refman, text, text_Refman);
    CHECK(139)
    fi = integration_M_f_test_int2str;
    INIT_VAR(141, itv)
    LUMI_err = integration_M_TestStruct_new(itv, itv_Refman, i, text, text_Refman);
    CHECK(141)
    INIT_NEW(142, itn, LUMI_alloc(sizeof(integration_M_TestStruct)));
    LUMI_err = integration_M_TestStruct_new(itn, itn_Refman, i, text, text_Refman);
    CHECK(142)
    INIT_VAR(143, idv)
    LUMI_err = integration_M_TestClass_new(idv, idv_Refman, idv_Dynamic);
    CHECK(143)
    INIT_NEW(144, idn, LUMI_alloc(sizeof(integration_M_TestClass)));
    LUMI_err = integration_M_TestClass_new(idn, idn_Refman, idn_Dynamic);
    CHECK(144)
    INIT_NEW(145, aux_TestStruct_0, LUMI_alloc(sizeof(integration_M_TestStruct)));
    LUMI_err = integration_M_TestStruct_new(aux_TestStruct_0, aux_TestStruct_0_Refman, i, text, text_Refman);
    CHECK(145)
    LUMI_err = integration_M_TestStruct_print(aux_TestStruct_0, aux_TestStruct_0_Refman);
    CHECK(145)
    INIT_NEW(146, aux_TestClass_0, LUMI_alloc(sizeof(integration_M_TestClass)));
    LUMI_err = integration_M_TestClass_new(aux_TestClass_0, aux_TestClass_0_Refman, aux_TestClass_0_Dynamic);
    CHECK(146)
    LUMI_err = integration_M_TestClass_print(aux_TestClass_0, aux_TestClass_0_Refman, aux_TestClass_0_Dynamic);
    CHECK(146)
    CHECK_REF(147, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(147, slice_index)
    INIT_NEW(147, aux_String_1, LUMI_new_string(((Int*)((arr)->values))[0]));
    TEST_ASSERT(147, aux_String_1 != NULL && aux_String_1_Refman->value != NULL)
    CHECK_REF(148, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(148, slice_index)
    INIT_NEW(148, aux_Array_0, LUMI_new_array(((Int*)((arr)->values))[0], sizeof(Int)));
    TEST_ASSERT(148, aux_Array_0 != NULL && aux_Array_0_Refman->value != NULL)
    CHECK_REF(149, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(149, slice_index)
    INIT_NEW(149, aux_Array_1, LUMI_new_array(((Int*)((arr)->values))[0], sizeof(integration_M_TestStruct)));
    TEST_ASSERT(149, aux_Array_1 != NULL && aux_Array_1_Refman->value != NULL)
    CHECK_REF(150, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(150, slice_index)
    INIT_NEW(150, aux_Array_2, LUMI_new_array(((Int*)((arr)->values))[0], sizeof(integration_M_TestClass)));
    TEST_ASSERT(150, aux_Array_2 != NULL && aux_Array_2_Refman->value != NULL)
    CHECK_REF(151, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(151, slice_index)
    CHECK_REF(151, arr, arr_Refman)
    if ((1) < 0 || (1) >= (arr)->length) RAISE(151, slice_index)
    INIT_NEW(151, aux_Array_3, LUMI_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]));
    TEST_ASSERT(151, aux_Array_3 != NULL && aux_Array_3_Refman->value != NULL)
    CHECK_REF(152, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(152, slice_index)
    INIT_NEW(152, aux_Array_4, LUMI_new_array(((Int*)((arr)->values))[0], sizeof(Func)));
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
    if (fi == NULL) RAISE(177, empty_object)
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
    LUMI_var_dec_ref(aux_String_0_Refman);
    if (idn_Dynamic != NULL) idn_Dynamic->_del(idn);
    LUMI_owner_dec_ref(idn_Refman);
    LUMI_var_dec_ref(idv_Refman);
    integration_M_TestStruct_Del(itn);
    LUMI_owner_dec_ref(itn_Refman);
    LUMI_var_dec_ref(itv_Refman);
    String_Del(isn);
    LUMI_owner_dec_ref(isn_Refman);
    LUMI_var_dec_ref(isv_Refman);
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
    LUMI_var_dec_ref(fa_Refman);
    LUMI_var_dec_ref(sa_Refman);
    LUMI_var_dec_ref(da_Refman);
    LUMI_var_dec_ref(ta_Refman);
    LUMI_var_dec_ref(ia_Refman);
    LUMI_var_dec_ref(sv_Refman);
    LUMI_var_dec_ref(dv_Refman);
    LUMI_var_dec_ref(tv_Refman);
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
    INIT_STRING_CONST(266, aux_String_0, "text");
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
    LUMI_var_dec_ref(aux_String_0_Refman);
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
    CHECK_REF(283, arr, arr_Refman)
    if ((4) < 0 || (4) >= (arr)->length) RAISE(283, slice_index)
    if ((((Int*)((arr)->values))[4]) > 6) {
        *res = 6;
    }
    else {
        if (arr != NULL && arr_Refman->value != NULL) {
            *res = 6;
        }
        else {
            CHECK_REF(287, arr, arr_Refman)
            if ((5) < 0 || (5) >= (arr)->length) RAISE(287, slice_index)
            CHECK_REF(287, arr, arr_Refman)
            if ((4) < 0 || (4) >= (arr)->length) RAISE(287, slice_index)
            if ((((Int*)((arr)->values))[4]) != (((Int*)((arr)->values))[5])) {
                *res = 6;
            }
            else {
                CHECK_REF(289, arr, arr_Refman)
                if ((0) < 0 || (0) >= (arr)->length) RAISE(289, slice_index)
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
        CHECK_REF(294, arr, arr_Refman)
        if ((6) < 0 || (6) >= (arr)->length) RAISE(294, slice_index)
        ((Int*)((arr)->values))[6] = 6;
        CHECK_REF(295, arr, arr_Refman)
        if ((2) < 0 || (2) >= (arr)->length) RAISE(295, slice_index)
        x = ((Int*)((arr)->values))[2];
        if (!((x > 3) && ((void*)arr == NULL))) break;
        y = x - 1;
        while (true) {
            CHECK_REF(299, arr, arr_Refman)
            if ((8) < 0 || (8) >= (arr)->length) RAISE(299, slice_index)
            CHECK_REF(299, arr, arr_Refman)
            if ((4) < 0 || (4) >= (arr)->length) RAISE(299, slice_index)
            ((Int*)((arr)->values))[4] = ((Int*)((arr)->values))[8];
            CHECK_REF(300, arr, arr_Refman)
            if ((4) < 0 || (4) >= (arr)->length) RAISE(300, slice_index)
            if (y > (((Int*)((arr)->values))[4])) {
                continue;
            }
            z = 7;
            CHECK_REF(303, arr, arr_Refman)
            if ((4) < 0 || (4) >= (arr)->length) RAISE(303, slice_index)
            if (z <= (((Int*)((arr)->values))[4])) {
                if (!(z > 0)) break;
            }
        }
    }
    CHECK_REF(305, arr, arr_Refman)
    if ((2) < 0 || (2) >= (arr)->length) RAISE(305, slice_index)
    CHECK_REF(305, arr, arr_Refman)
    if ((2) < 0 || (2) >= (arr)->length) RAISE(305, slice_index)
    for (n = ((Int*)((arr)->values))[2]; n < 2 - (3 * (((Int*)((arr)->values))[2])); ++n) {
        CHECK_REF(306, arr, arr_Refman)
        if ((2) < 0 || (2) >= (arr)->length) RAISE(306, slice_index)
        CHECK_REF(306, arr, arr_Refman)
        if ((0) < 0 || (0) >= (arr)->length) RAISE(306, slice_index)
        ((Int*)((arr)->values))[0] = ((Int*)((arr)->values))[2];
        CHECK_REF(307, arr, arr_Refman)
        if ((0) < 0 || (0) >= (arr)->length) RAISE(307, slice_index)
        w = ((Int*)((arr)->values))[0];
        INIT_VAR(308, aux_Array_0)
        aux_Array_0_Var.length = 2;
        aux_Array_0_Var.values = (Byte*)((arr)->values) + (3);
        CHECK_REF(308, arr, arr_Refman)
        if ((3) < 0 || (2) < 0 || (3) + (2) > (arr)->length) RAISE(308, slice_index)
        if ((w > 4) && ((void*)arr != aux_Array_0)) {
            CHECK_REF(309, arr, arr_Refman)
            if ((1) < 0 || (1) >= (arr)->length) RAISE(309, slice_index)
            ((Int*)((arr)->values))[1] = w;
        }
    }
LUMI_cleanup:
    LUMI_var_dec_ref(aux_Array_0_Refman);
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
    CHECK_REF(319, a, a_Refman)
    i = a->length;
    CHECK_REF(320, s, s_Refman)
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
    CHECK_REF(337, sys, sys_Refman)
    CHECK_REF(337, sys->argv, sys->argv_Refman)
    if ((1) < 0 || (1) >= (sys->argv)->length) RAISE(337, slice_index)
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
    CHECK_REF(345, sys, sys_Refman)
    LUMI_err = File_putc(sys->stdout_Cname, sys->stdout_Cname_Refman, c);
    CHECK(345)
    CHECK_REF(346, sys, sys_Refman)
    LUMI_err = File_getc(sys->stdin_Cname, sys->stdin_Cname_Refman, &(cv), &(bv));
    CHECK(346)
    CHECK_REF(347, sys, sys_Refman)
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
    INIT_STRING_CONST(351, aux_String_0, "test string");
    INIT_NEW(351, s, LUMI_new_string(32));
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
        INIT_STRING_CONST(357, aux_String_1, "ownership passed");
        LUMI_err = Sys_println(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
        CHECK(357)
    }
    if (! (s_user != NULL && s_user_Refman->value != NULL)) {
        INIT_STRING_CONST(359, aux_String_2, "string deleted");
        LUMI_err = Sys_println(sys, sys_Refman, aux_String_2, aux_String_2_Refman);
        CHECK(359)
    }
    INIT_STRING_CONST(360, aux_String_3, "first struct");
    INIT_NEW(360, ts, LUMI_alloc(sizeof(integration_M_TestStruct)));
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
    CHECK_REF(362, ts, ts_Refman)
    LUMI_err = Sys_println(sys, sys_Refman, ts->text, ts->text_Refman);
    CHECK(362)
    INIT_STRING_CONST(363, aux_String_4, "second struct");
    INIT_NEW(363, aux_TestStruct_1, LUMI_alloc(sizeof(integration_M_TestStruct)));
    LUMI_err = integration_M_TestStruct_new(aux_TestStruct_1, aux_TestStruct_1_Refman, 1, aux_String_4, aux_String_4_Refman);
    CHECK(363)
    aux_TestStruct_2 = aux_TestStruct_1;
    aux_TestStruct_2_Refman = aux_TestStruct_1_Refman;
    aux_TestStruct_1 = NULL;
    aux_TestStruct_1_Refman = NULL;
    CHECK_REF(363, ts, ts_Refman)
    integration_M_TestStruct_Del(ts->ts);
    LUMI_owner_dec_ref(ts->ts_Refman);
    ts->ts_Refman = aux_TestStruct_2_Refman;
    ts->ts = aux_TestStruct_2;
    aux_TestStruct_2 = NULL;
    aux_TestStruct_2_Refman = NULL;
    CHECK_REF(364, ts, ts_Refman)
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
    CHECK_REF(365, ts, ts_Refman)
    LUMI_err = Sys_println(sys, sys_Refman, ts->text, ts->text_Refman);
    CHECK(365)
LUMI_cleanup:
    integration_M_TestStruct_Del(aux_TestStruct_3);
    LUMI_owner_dec_ref(aux_TestStruct_3_Refman);
    integration_M_TestStruct_Del(aux_TestStruct_2);
    LUMI_owner_dec_ref(aux_TestStruct_2_Refman);
    integration_M_TestStruct_Del(aux_TestStruct_1);
    LUMI_owner_dec_ref(aux_TestStruct_1_Refman);
    LUMI_var_dec_ref(aux_String_4_Refman);
    integration_M_TestStruct_Del(aux_TestStruct_0);
    LUMI_owner_dec_ref(aux_TestStruct_0_Refman);
    LUMI_var_dec_ref(aux_String_3_Refman);
    LUMI_var_dec_ref(aux_String_2_Refman);
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
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
    INIT_VAR(395, d)
    INIT_VAR(396, sarr)
    sarr_Var.values = sarr_Values;
    LUMI_set_var_string_array(6, 16, sarr, sarr_Chars);
    CHECK_REF(397, d, d_Refman)
    aux_Ref_Manager = d->item_Refman;
    d->item_Refman = s_Refman;
    d->item_Dynamic = &String_dynamic;
    LUMI_inc_ref(d->item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    d->item = s;
    CHECK_REF(398, d, d_Refman)
    aux_Ref_Manager = s_Refman;
    s_Refman = d->item_Refman;
    LUMI_inc_ref(s_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    s = d->item;
    CHECK_REF(399, d, d_Refman)
    aux_Ref_Manager = d->arr_Refman;
    d->arr_Refman = sarr_Refman;
    LUMI_inc_ref(d->arr_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    d->arr = sarr;
    CHECK_REF(400, d, d_Refman)
    CHECK_REF(400, d->arr, d->arr_Refman)
    if ((4) < 0 || (4) >= (d->arr)->length) RAISE(400, slice_index)
    aux_Ref_Manager = s_Refman;
    s_Refman = d->arr_Refman;
    LUMI_inc_ref(s_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    s = ((String*)((d->arr)->values)) + 4;
    INIT_VAR(401, ad)
    ad_Var.values = ad_Values;
    CHECK_REF(402, ad, ad_Refman)
    if ((2) < 0 || (2) >= (ad)->length) RAISE(402, slice_index)
    CHECK_REF(402, ((integration_M_Data*)((ad)->values)) + 2, ad_Refman)
    aux_Ref_Manager = s_Refman;
    s_Refman = (((integration_M_Data*)((ad)->values)) + 2)->item_Refman;
    LUMI_inc_ref(s_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    s = (((integration_M_Data*)((ad)->values)) + 2)->item;
    CHECK_REF(403, ad, ad_Refman)
    if ((2) < 0 || (2) >= (ad)->length) RAISE(403, slice_index)
    CHECK_REF(403, ((integration_M_Data*)((ad)->values)) + 2, ad_Refman)
    CHECK_REF(403, (((integration_M_Data*)((ad)->values)) + 2)->arr, (((integration_M_Data*)((ad)->values)) + 2)->arr_Refman)
    if ((3) < 0 || (3) >= ((((integration_M_Data*)((ad)->values)) + 2)->arr)->length) RAISE(403, slice_index)
    aux_Ref_Manager = s_Refman;
    s_Refman = (((integration_M_Data*)((ad)->values)) + 2)->arr_Refman;
    LUMI_inc_ref(s_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    s = ((String*)(((((integration_M_Data*)((ad)->values)) + 2)->arr)->values)) + 3;
    INIT_VAR(404, dr)
    CHECK_REF(405, dr, dr_Refman)
    CHECK_REF(405, dr->item, dr->item_Refman)
    CHECK_REF(405, ((integration_M_Data*)(dr->item))->item, ((integration_M_Data*)(dr->item))->item_Refman)
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
    INIT_VAR(411, t)
    INIT_VAR(412, dt)
    INIT_VAR(413, ts)
    LUMI_err = integration_M_TestStruct_new(ts, ts_Refman, 0, NULL, NULL);
    CHECK(413)
    CHECK_REF(414, t, t_Refman)
    aux_Ref_Manager = t->_base._base._base.item_Refman;
    t->_base._base._base.item_Refman = s_Refman;
    t->_base._base._base.item_Dynamic = &String_dynamic;
    LUMI_inc_ref(t->_base._base._base.item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->_base._base._base.item = s;
    CHECK_REF(415, t, t_Refman)
    aux_Ref_Manager = t->_base._base._base.arr_Refman;
    t->_base._base._base.arr_Refman = sarr_Refman;
    LUMI_inc_ref(t->_base._base._base.arr_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->_base._base._base.arr = sarr;
    CHECK_REF(416, t, t_Refman)
    aux_Ref_Manager = t->_base._base.second_Refman;
    t->_base._base.second_Refman = dt_Refman;
    t->_base._base.second_Dynamic = &integration_M_Data_dynamic;
    LUMI_inc_ref(t->_base._base.second_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->_base._base.second = dt;
    CHECK_REF(417, t, t_Refman)
    aux_Ref_Manager = t->_base._base.third_Refman;
    t->_base._base.third_Refman = ts_Refman;
    t->_base._base.third_Dynamic = &integration_M_TestStruct_dynamic;
    LUMI_inc_ref(t->_base._base.third_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->_base._base.third = ts;
LUMI_cleanup:
    LUMI_var_dec_ref(ts_Refman);
    LUMI_var_dec_ref(dt_Refman);
    LUMI_var_dec_ref(t_Refman);
    LUMI_dec_ref(dg_Refman);
    LUMI_var_dec_ref(dr_Refman);
    LUMI_var_dec_ref(ad_Refman);
    LUMI_var_dec_ref(sarr_Refman);
    LUMI_var_dec_ref(d_Refman);
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
        CHECK_REF(422, t, t_Refman)
        t->num = 1;

#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    } while (false);
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        INIT_STRING_CONST(424, aux_String_0, "ignored message");
        USER_RAISE(424, aux_String_0, aux_String_0_Refman)
    }
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_0_Refman);
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
        INIT_STRING_CONST(428, aux_String_0, "error handling { 1 ");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
        CHECK(428)
        CHECK_REF(429, t, t_Refman)
        t->num = 1;
        INIT_STRING_CONST(430, aux_String_1, " X ");
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
        INIT_STRING_CONST(436, aux_String_2, "2 ");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_2, aux_String_2_Refman);
        CHECK(436)
        do {
            ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
            INIT_STRING_CONST(438, aux_String_3, "3 ");
            LUMI_err = Sys_print(sys, sys_Refman, aux_String_3, aux_String_3_Refman);
            CHECK(438)
            CHECK_REF(439, t, t_Refman)
            t->num = 2;
            INIT_STRING_CONST(440, aux_String_4, " X ");
            LUMI_err = Sys_print(sys, sys_Refman, aux_String_4, aux_String_4_Refman);
            CHECK(440)

#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
        } while (false);
        --LUMI_trace_ignore_count;
        LUMI_err = OK;
        INIT_STRING_CONST(441, aux_String_5, "4 ");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_5, aux_String_5_Refman);
        CHECK(441)
    }
    INIT_STRING_CONST(442, aux_String_6, "5 ");
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_6, aux_String_6_Refman);
    CHECK(442)
    do {
        ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
        INIT_STRING_CONST(444, aux_String_7, "6 ");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_7, aux_String_7_Refman);
        CHECK(444)
        do {
            ++LUMI_trace_ignore_count;
            INIT_STRING_CONST(446, aux_String_8, "7 ");
            LUMI_err = Sys_print(sys, sys_Refman, aux_String_8, aux_String_8_Refman);
            CHECK(446)
            LUMI_err = integration_M_f_try_catch_raise(t, t_Refman);
            CHECK(447)
            INIT_STRING_CONST(448, aux_String_9, " X ");
            LUMI_err = Sys_print(sys, sys_Refman, aux_String_9, aux_String_9_Refman);
            CHECK(448)
        } while (false);
        --LUMI_trace_ignore_count;
        LUMI_err = OK;
        INIT_STRING_CONST(449, aux_String_10, "8 ");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_10, aux_String_10_Refman);
        CHECK(449)
        INIT_STRING_CONST(450, aux_String_11, "another ignored message");
        USER_RAISE(450, aux_String_11, aux_String_11_Refman)

#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    } while (false);
    --LUMI_trace_ignore_count;
    LUMI_err = OK;
    INIT_STRING_CONST(451, aux_String_12, "}");
    LUMI_err = Sys_println(sys, sys_Refman, aux_String_12, aux_String_12_Refman);
    CHECK(451)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_12_Refman);
    LUMI_var_dec_ref(aux_String_11_Refman);
    LUMI_var_dec_ref(aux_String_10_Refman);
    LUMI_var_dec_ref(aux_String_9_Refman);
    LUMI_var_dec_ref(aux_String_8_Refman);
    LUMI_var_dec_ref(aux_String_7_Refman);
    LUMI_var_dec_ref(aux_String_6_Refman);
    LUMI_var_dec_ref(aux_String_5_Refman);
    LUMI_var_dec_ref(aux_String_4_Refman);
    LUMI_var_dec_ref(aux_String_3_Refman);
    LUMI_var_dec_ref(aux_String_2_Refman);
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
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
    INIT_VAR(481, text)
    text_Var.values = text_Values;
    INIT_STRING_CONST(482, aux_String_0, "chars[ ");
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(482)
    INIT_STRING_CONST(483, aux_String_1, "abcdef");
    aux_Ref_Manager = aux_String_2_Refman;
    aux_String_2_Refman = aux_String_1_Refman;
    LUMI_inc_ref(aux_String_2_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_String_2 = aux_String_1;
    CHECK_REF(483, aux_String_2, aux_String_2_Refman)
    {int c_Index; for (c_Index = 0; c_Index < aux_String_2->length; ++c_Index) {
        CHECK_REF(483, aux_String_2, aux_String_2_Refman)
        if ((c_Index) < 0 || (c_Index) >= (aux_String_2)->length) RAISE(483, slice_index)
        c = ((aux_String_2)->values)[c_Index];
        LUMI_err = String_clear(text, text_Refman);
        CHECK(484)
        LUMI_err = String_append(text, text_Refman, c);
        CHECK(485)
        LUMI_err = Sys_print(sys, sys_Refman, text, text_Refman);
        CHECK(486)
        INIT_STRING_CONST(487, aux_String_3, " ");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_3, aux_String_3_Refman);
        CHECK(487)
    }}
    aux_Ref_Manager = aux_String_2_Refman;
    aux_String_2_Refman = NULL;
    LUMI_inc_ref(aux_String_2_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_String_2 = NULL;
    INIT_STRING_CONST(488, aux_String_4, "]");
    LUMI_err = Sys_println(sys, sys_Refman, aux_String_4, aux_String_4_Refman);
    CHECK(488)
    INIT_VAR(490, arr)
    arr_Var.values = arr_Values;
    CHECK_REF(491, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(491, slice_index)
    ((Int*)((arr)->values))[0] = 14;
    CHECK_REF(492, arr, arr_Refman)
    if ((1) < 0 || (1) >= (arr)->length) RAISE(492, slice_index)
    ((Int*)((arr)->values))[1] = 15;
    CHECK_REF(493, arr, arr_Refman)
    if ((2) < 0 || (2) >= (arr)->length) RAISE(493, slice_index)
    ((Int*)((arr)->values))[2] = 16;
    INIT_STRING_CONST(494, aux_String_5, "numbers[ ");
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_5, aux_String_5_Refman);
    CHECK(494)
    aux_Ref_Manager = aux_Array_0_Refman;
    aux_Array_0_Refman = arr_Refman;
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_Array_0 = arr;
    CHECK_REF(495, aux_Array_0, aux_Array_0_Refman)
    {int n_Index; for (n_Index = 0; n_Index < aux_Array_0->length; ++n_Index) {
        CHECK_REF(495, aux_Array_0, aux_Array_0_Refman)
        if ((n_Index) < 0 || (n_Index) >= (aux_Array_0)->length) RAISE(495, slice_index)
        n = ((Int*)((aux_Array_0)->values))[n_Index];
        LUMI_err = String_clear(text, text_Refman);
        CHECK(496)
        LUMI_err = Int_str(n, text, text_Refman);
        CHECK(497)
        LUMI_err = Sys_print(sys, sys_Refman, text, text_Refman);
        CHECK(498)
        INIT_STRING_CONST(499, aux_String_6, " ");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_6, aux_String_6_Refman);
        CHECK(499)
    }}
    aux_Ref_Manager = aux_Array_0_Refman;
    aux_Array_0_Refman = NULL;
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_Array_0 = NULL;
    INIT_STRING_CONST(500, aux_String_7, "]");
    LUMI_err = Sys_println(sys, sys_Refman, aux_String_7, aux_String_7_Refman);
    CHECK(500)
    INIT_VAR(502, tsarr)
    tsarr_Var.values = tsarr_Values;
    INIT_STRING_CONST(503, aux_String_8, "aaa");
    CHECK_REF(503, tsarr, tsarr_Refman)
    if ((0) < 0 || (0) >= (tsarr)->length) RAISE(503, slice_index)
    CHECK_REF(503, ((integration_M_TestStruct*)((tsarr)->values)) + 0, tsarr_Refman)
    aux_Ref_Manager = (((integration_M_TestStruct*)((tsarr)->values)) + 0)->text_Refman;
    (((integration_M_TestStruct*)((tsarr)->values)) + 0)->text_Refman = aux_String_8_Refman;
    LUMI_inc_ref((((integration_M_TestStruct*)((tsarr)->values)) + 0)->text_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    (((integration_M_TestStruct*)((tsarr)->values)) + 0)->text = aux_String_8;
    INIT_STRING_CONST(504, aux_String_9, "bbb");
    CHECK_REF(504, tsarr, tsarr_Refman)
    if ((1) < 0 || (1) >= (tsarr)->length) RAISE(504, slice_index)
    CHECK_REF(504, ((integration_M_TestStruct*)((tsarr)->values)) + 1, tsarr_Refman)
    aux_Ref_Manager = (((integration_M_TestStruct*)((tsarr)->values)) + 1)->text_Refman;
    (((integration_M_TestStruct*)((tsarr)->values)) + 1)->text_Refman = aux_String_9_Refman;
    LUMI_inc_ref((((integration_M_TestStruct*)((tsarr)->values)) + 1)->text_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    (((integration_M_TestStruct*)((tsarr)->values)) + 1)->text = aux_String_9;
    INIT_STRING_CONST(505, aux_String_10, "ccc");
    CHECK_REF(505, tsarr, tsarr_Refman)
    if ((2) < 0 || (2) >= (tsarr)->length) RAISE(505, slice_index)
    CHECK_REF(505, ((integration_M_TestStruct*)((tsarr)->values)) + 2, tsarr_Refman)
    aux_Ref_Manager = (((integration_M_TestStruct*)((tsarr)->values)) + 2)->text_Refman;
    (((integration_M_TestStruct*)((tsarr)->values)) + 2)->text_Refman = aux_String_10_Refman;
    LUMI_inc_ref((((integration_M_TestStruct*)((tsarr)->values)) + 2)->text_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    (((integration_M_TestStruct*)((tsarr)->values)) + 2)->text = aux_String_10;
    INIT_STRING_CONST(506, aux_String_11, "structs[ ");
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_11, aux_String_11_Refman);
    CHECK(506)
    aux_Ref_Manager = aux_Array_1_Refman;
    aux_Array_1_Refman = tsarr_Refman;
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_Array_1 = tsarr;
    CHECK_REF(507, aux_Array_1, aux_Array_1_Refman)
    {int ts_Index; for (ts_Index = 0; ts_Index < aux_Array_1->length; ++ts_Index) {
        CHECK_REF(507, aux_Array_1, aux_Array_1_Refman)
        if ((ts_Index) < 0 || (ts_Index) >= (aux_Array_1)->length) RAISE(507, slice_index)
        aux_Ref_Manager = ts_Refman;
        ts_Refman = aux_Array_1_Refman;
        LUMI_inc_ref(ts_Refman);
        LUMI_dec_ref(aux_Ref_Manager);
        aux_Ref_Manager = NULL;
        ts = ((integration_M_TestStruct*)((aux_Array_1)->values)) + ts_Index;
        CHECK_REF(508, ts, ts_Refman)
        LUMI_err = Sys_print(sys, sys_Refman, ts->text, ts->text_Refman);
        CHECK(508)
        INIT_STRING_CONST(509, aux_String_12, " ");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_12, aux_String_12_Refman);
        CHECK(509)
    }}
    aux_Ref_Manager = aux_Array_1_Refman;
    aux_Array_1_Refman = NULL;
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_Array_1 = NULL;
    INIT_STRING_CONST(510, aux_String_13, "]");
    LUMI_err = Sys_println(sys, sys_Refman, aux_String_13, aux_String_13_Refman);
    CHECK(510)
    INIT_VAR(512, sarr)
    sarr_Var.values = sarr_Values;
    LUMI_set_var_string_array(3, 16, sarr, sarr_Chars);
    CHECK_REF(513, sarr, sarr_Refman)
    if ((0) < 0 || (0) >= (sarr)->length) RAISE(513, slice_index)
    INIT_STRING_CONST(513, aux_String_14, "ddd");
    LUMI_err = String_new(((String*)((sarr)->values)) + 0, sarr_Refman, aux_String_14, aux_String_14_Refman);
    CHECK(513)
    CHECK_REF(514, sarr, sarr_Refman)
    if ((1) < 0 || (1) >= (sarr)->length) RAISE(514, slice_index)
    INIT_STRING_CONST(514, aux_String_15, "eee");
    LUMI_err = String_new(((String*)((sarr)->values)) + 1, sarr_Refman, aux_String_15, aux_String_15_Refman);
    CHECK(514)
    CHECK_REF(515, sarr, sarr_Refman)
    if ((2) < 0 || (2) >= (sarr)->length) RAISE(515, slice_index)
    INIT_STRING_CONST(515, aux_String_16, "fff");
    LUMI_err = String_new(((String*)((sarr)->values)) + 2, sarr_Refman, aux_String_16, aux_String_16_Refman);
    CHECK(515)
    INIT_STRING_CONST(516, aux_String_17, "strings[ ");
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_17, aux_String_17_Refman);
    CHECK(516)
    aux_Ref_Manager = aux_Array_2_Refman;
    aux_Array_2_Refman = sarr_Refman;
    LUMI_inc_ref(aux_Array_2_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_Array_2 = sarr;
    CHECK_REF(517, aux_Array_2, aux_Array_2_Refman)
    {int s_Index; for (s_Index = 0; s_Index < aux_Array_2->length; ++s_Index) {
        CHECK_REF(517, aux_Array_2, aux_Array_2_Refman)
        if ((s_Index) < 0 || (s_Index) >= (aux_Array_2)->length) RAISE(517, slice_index)
        aux_Ref_Manager = s_Refman;
        s_Refman = aux_Array_2_Refman;
        LUMI_inc_ref(s_Refman);
        LUMI_dec_ref(aux_Ref_Manager);
        aux_Ref_Manager = NULL;
        s = ((String*)((aux_Array_2)->values)) + s_Index;
        LUMI_err = Sys_print(sys, sys_Refman, s, s_Refman);
        CHECK(518)
        INIT_STRING_CONST(519, aux_String_18, " ");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_18, aux_String_18_Refman);
        CHECK(519)
    }}
    aux_Ref_Manager = aux_Array_2_Refman;
    aux_Array_2_Refman = NULL;
    LUMI_inc_ref(aux_Array_2_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_Array_2 = NULL;
    INIT_STRING_CONST(520, aux_String_19, "]");
    LUMI_err = Sys_println(sys, sys_Refman, aux_String_19, aux_String_19_Refman);
    CHECK(520)
    INIT_STRING_CONST(522, aux_String_20, "iii");
    INIT_VAR(522, container_last)
    LUMI_err = integration_M_Container_new(container_last, container_last_Refman, aux_String_20, aux_String_20_Refman, &String_dynamic, NULL, NULL);
    CHECK(522)
    INIT_STRING_CONST(523, aux_String_21, "hhh");
    INIT_VAR(523, container_mid)
    LUMI_err = integration_M_Container_new(container_mid, container_mid_Refman, aux_String_21, aux_String_21_Refman, &String_dynamic, container_last, container_last_Refman);
    CHECK(523)
    INIT_STRING_CONST(524, aux_String_22, "ggg");
    INIT_VAR(524, container_first)
    LUMI_err = integration_M_Container_new(container_first, container_first_Refman, aux_String_22, aux_String_22_Refman, &String_dynamic, container_mid, container_mid_Refman);
    CHECK(524)
    INIT_VAR(525, container)
    LUMI_err = integration_M_Container_new(container, container_Refman, NULL, NULL, NULL, container_first, container_first_Refman);
    CHECK(525)
    LUMI_err = integration_M_Container_iter(container, container_Refman, &(iter), &(iter_Refman));
    CHECK(527)
    INIT_STRING_CONST(528, aux_String_23, "values[ ");
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
        INIT_STRING_CONST(531, aux_String_24, " ");
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
    INIT_STRING_CONST(532, aux_String_25, "]");
    LUMI_err = Sys_println(sys, sys_Refman, aux_String_25, aux_String_25_Refman);
    CHECK(532)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_25_Refman);
    LUMI_var_dec_ref(aux_String_24_Refman);
    LUMI_dec_ref(aux_ContainerIterator_0_Refman);
    LUMI_var_dec_ref(aux_String_23_Refman);
    LUMI_var_dec_ref(aux_String_22_Refman);
    LUMI_var_dec_ref(aux_String_21_Refman);
    LUMI_var_dec_ref(aux_String_20_Refman);
    LUMI_var_dec_ref(aux_String_19_Refman);
    LUMI_var_dec_ref(aux_String_18_Refman);
    LUMI_dec_ref(aux_Array_2_Refman);
    LUMI_dec_ref(s_Refman);
    LUMI_var_dec_ref(aux_String_17_Refman);
    LUMI_var_dec_ref(aux_String_16_Refman);
    LUMI_var_dec_ref(aux_String_15_Refman);
    LUMI_var_dec_ref(aux_String_14_Refman);
    LUMI_var_dec_ref(aux_String_13_Refman);
    LUMI_var_dec_ref(aux_String_12_Refman);
    LUMI_dec_ref(aux_Array_1_Refman);
    LUMI_dec_ref(ts_Refman);
    LUMI_var_dec_ref(aux_String_11_Refman);
    LUMI_var_dec_ref(aux_String_10_Refman);
    LUMI_var_dec_ref(aux_String_9_Refman);
    LUMI_var_dec_ref(aux_String_8_Refman);
    LUMI_var_dec_ref(aux_String_7_Refman);
    LUMI_var_dec_ref(aux_String_6_Refman);
    LUMI_dec_ref(aux_Array_0_Refman);
    LUMI_var_dec_ref(aux_String_5_Refman);
    LUMI_var_dec_ref(aux_String_4_Refman);
    LUMI_var_dec_ref(aux_String_3_Refman);
    LUMI_dec_ref(aux_String_2_Refman);
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
    integration_M_ContainerIterator_Del(iter);
    LUMI_owner_dec_ref(iter_Refman);
    LUMI_var_dec_ref(container_Refman);
    LUMI_var_dec_ref(container_first_Refman);
    LUMI_var_dec_ref(container_mid_Refman);
    LUMI_var_dec_ref(container_last_Refman);
    LUMI_var_dec_ref(sarr_Refman);
    LUMI_var_dec_ref(tsarr_Refman);
    LUMI_var_dec_ref(arr_Refman);
    LUMI_var_dec_ref(text_Refman);
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
    INIT_VAR(555, y)
    CHECK_REF(556, y, y_Refman)
    CHECK_REF(556, y, y_Refman)
    aux_Ref_Manager = y->x.x_Refman;
    y->x.x_Refman = y_Refman;
    y->x.x_Dynamic = &integration_M_ComplexField_dynamic;
    LUMI_inc_ref(y->x.x_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    y->x.x = &(y->x);
    INIT_STRING_CONST(557, aux_String_0, "complex fields: ");
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(557)
    LUMI_err = integration_M_HasComplexField_run(y, y_Refman);
    CHECK(558)
    INIT_STRING_CONST(559, aux_String_1, "");
    LUMI_err = Sys_println(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
    CHECK(559)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
    LUMI_var_dec_ref(y_Refman);
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
    INIT_STRING_CONST(20, aux_String_0, "a constant string");
    integration_M_global_string = aux_String_0;
    integration_M_global_string_Refman = aux_String_0_Refman;
    LUMI_inc_ref(integration_M_global_string_Refman);
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "tests/integration-test0.4.lm"
    INIT_VAR(22, integration_M_int_arr)
    integration_M_int_arr_Var.values = integration_M_int_arr_Values;
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
