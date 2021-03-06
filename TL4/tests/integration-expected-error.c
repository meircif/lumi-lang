#include "lumi.4.h"


/* types declaration */

typedef struct error_M_BaseType error_M_BaseType;

typedef struct error_M_BaseType_Dynamic error_M_BaseType_Dynamic;

typedef struct error_M_TopType error_M_TopType;

typedef struct error_M_TopType_Dynamic error_M_TopType_Dynamic;

typedef struct error_M_Test error_M_Test;


/* Enums */


/* constants */


/* types struct */

struct error_M_BaseType {
    Int x;
};

struct error_M_BaseType_Dynamic {
    Dynamic_Del _del;
    Returncode (*meth)(error_M_BaseType* self, Ref_Manager* self_Refman, error_M_BaseType_Dynamic* self_Dynamic);
};

struct error_M_TopType {
    error_M_BaseType _base;
};

struct error_M_TopType_Dynamic {
    error_M_BaseType_Dynamic _base;
};

struct error_M_Test {
    error_M_Test* t;
    Ref_Manager* t_Refman;
};


/* types methods declaration */

Returncode error_M_BaseType_meth(error_M_BaseType* self, Ref_Manager* self_Refman, error_M_BaseType_Dynamic* self_Dynamic);

void error_M_BaseType_Del(error_M_BaseType* self);

Returncode error_M_TopType_meth(error_M_TopType* self, Ref_Manager* self_Refman, error_M_TopType_Dynamic* self_Dynamic);

void error_M_TopType_Del(error_M_TopType* self);

void error_M_Test_Del(error_M_Test* self);


/* global functions declaration */

Returncode error_M_f_get_top(error_M_TopType** top, Ref_Manager** top_Refman, error_M_TopType_Dynamic** top_Dynamic);

Returncode error_M_f_good_function(void);

Returncode error_M_f_raise_message(String* msg, Ref_Manager* msg_Refman);

Returncode new_Mock(Bool* alloc_success);

Returncode error_M_fail_call_empty(void);

Returncode error_M_fail_base_class_output(void);

Returncode error_M_fail_slice_index(void);

Returncode error_M_fail_member_empty(void);

Returncode error_M_fail_member_outdated(void);

Returncode error_M_fail_sequence_empty(void);

Returncode error_M_fail_sequence_outdated(void);

Returncode error_M_fail_dynamic_empty(void);

Returncode error_M_fail_object_no_memory(void);

Returncode error_M_fail_managed_no_memory(void);

Returncode error_M_fail_raise(void);

Returncode error_M_fail_raise_message(void);

Returncode error_M_fail_assert(void);

Returncode error_M_fail_assert_error(void);

Returncode error_M_fail_assert_error_message(void);

Returncode error_M_fail_assert_error_message_prefix(void);

Returncode error_M_fail_owner_cycle(void);


/* types global variables */

error_M_BaseType_Dynamic error_M_BaseType_dynamic = {(Dynamic_Del)error_M_BaseType_Del, error_M_BaseType_meth};

error_M_TopType_Dynamic error_M_TopType_dynamic = {{(Dynamic_Del)error_M_TopType_Del, (Func)error_M_TopType_meth}};

Generic_Type_Dynamic error_M_Test_dynamic = {(Dynamic_Del)error_M_Test_Del};


/* global variables */

Int error_M_new_fail_countdown = 0;

int LUMI_file0_line_count[101] = {
    -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1, 0, 0, 0,
     0, 0,-1,-1,-1, 0, 0,-1,-1, 0, 0, 0,-1,-1, 0, 0,-1,-1, 0, 0, 0,-1,-1, 0, 0,
     0, 0, 0,-1,-1, 0, 0,-1,-1, 0, 0, 0, 0,-1,-1, 0, 0,-1,-1, 0, 0,-1,-1, 0, 0,
    -1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1,-1, 0, 0,
    -1
};
File_Coverage LUMI_file_coverage[1] = {
    {"tests/integration-error-test.4.lm", 101, LUMI_file0_line_count}
};


/* types methods body */

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "BaseType.meth"
Returncode error_M_BaseType_meth(error_M_BaseType* self, Ref_Manager* self_Refman, error_M_BaseType_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void error_M_BaseType_Del(error_M_BaseType* self) {
    if (self == NULL) return;
}

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "TopType.meth"
Returncode error_M_TopType_meth(error_M_TopType* self, Ref_Manager* self_Refman, error_M_TopType_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void error_M_TopType_Del(error_M_TopType* self) {
    if (self == NULL) return;
    error_M_BaseType_Del(&(self->_base));
}

void error_M_Test_Del(error_M_Test* self) {
    if (self == NULL) return;
    SELF_REF_DEL(error_M_Test, t);
    LUMI_owner_dec_ref(self->t_Refman);
}


/* global functions body */

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "f-get-top"
Returncode error_M_f_get_top(error_M_TopType** top, Ref_Manager** top_Refman, error_M_TopType_Dynamic** top_Dynamic) {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "f-good-function"
Returncode error_M_f_good_function(void) {
    Returncode LUMI_err = OK;
    ++LUMI_file_coverage[0].line_count[14];
    goto LUMI_cleanup;
LUMI_cleanup:
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "f-raise-message"
Returncode error_M_f_raise_message(String* msg, Ref_Manager* msg_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(msg_Refman);
    ++LUMI_file_coverage[0].line_count[17];
    USER_RAISE(17, msg, msg_Refman)
LUMI_cleanup:
    LUMI_dec_ref(msg_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "new Mock"
Returncode new_Mock(Bool* alloc_success) {
    Returncode LUMI_err = OK;
    ++LUMI_file_coverage[0].line_count[22];
    *alloc_success = true;
    ++LUMI_file_coverage[0].line_count[23];
    if (error_M_new_fail_countdown > 0) {
        ++LUMI_file_coverage[0].line_count[24];
        error_M_new_fail_countdown -= 1;
        ++LUMI_file_coverage[0].line_count[25];
        if (error_M_new_fail_countdown == 0) {
            ++LUMI_file_coverage[0].line_count[26];
            *alloc_success = false;
        }
    }
LUMI_cleanup:
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-call-empty"
Returncode error_M_fail_call_empty(void) {
    Returncode LUMI_err = OK;
    Returncode (*fun)(void) = NULL;
    ++LUMI_file_coverage[0].line_count[30];
    ++LUMI_file_coverage[0].line_count[31];
    if (fun == NULL) RAISE(31, empty_object)
    LUMI_err = fun();
    CHECK(31)
LUMI_cleanup:
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-base-class-output"
Returncode error_M_fail_base_class_output(void) {
    Returncode LUMI_err = OK;
    error_M_BaseType base_var_Var = {0};
    error_M_BaseType* base_var = NULL;
    Ref_Manager* base_var_Refman = NULL;
    error_M_BaseType_Dynamic* base_var_Dynamic = &error_M_BaseType_dynamic;
    error_M_BaseType* base_user = NULL;
    Ref_Manager* base_user_Refman = NULL;
    error_M_BaseType_Dynamic* base_user_Dynamic = NULL;
    ++LUMI_file_coverage[0].line_count[34];
    INIT_VAR(34, base_var)
    ++LUMI_file_coverage[0].line_count[35];
    base_user = base_var;
    base_user_Refman = base_var_Refman;
    LUMI_inc_ref(base_user_Refman);
    base_user_Dynamic = base_var_Dynamic;
    ++LUMI_file_coverage[0].line_count[36];
    if (base_user != NULL) RAISE(36, empty_base_output)
    LUMI_err = error_M_f_get_top((void*)&(base_user), &(base_user_Refman), (void*)&(base_user_Dynamic));
    CHECK(36)
LUMI_cleanup:
    LUMI_dec_ref(base_user_Refman);
    LUMI_var_dec_ref(base_var_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-slice-index"
Returncode error_M_fail_slice_index(void) {
    Returncode LUMI_err = OK;
    Int arr_Values[2] = {0};
    Array arr_Var = {2, NULL};
    Array* arr = NULL;
    Ref_Manager* arr_Refman = NULL;
    ++LUMI_file_coverage[0].line_count[39];
    INIT_VAR(39, arr)
    arr_Var.values = arr_Values;
    ++LUMI_file_coverage[0].line_count[40];
    CHECK_REF(40, arr, arr_Refman)
    if ((6) < 0 || (6) >= (arr)->length) RAISE(40, slice_index)
    TEST_ASSERT(40, (((Int*)((arr)->values))[6]) == 0)
LUMI_cleanup:
    LUMI_var_dec_ref(arr_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-member-empty"
Returncode error_M_fail_member_empty(void) {
    Returncode LUMI_err = OK;
    error_M_BaseType* obj = NULL;
    Ref_Manager* obj_Refman = NULL;
    error_M_BaseType_Dynamic* obj_Dynamic = NULL;
    ++LUMI_file_coverage[0].line_count[43];
    ++LUMI_file_coverage[0].line_count[44];
    CHECK_REF(44, obj, obj_Refman)
    TEST_ASSERT(44, obj->x == 0)
    ++LUMI_file_coverage[0].line_count[45];
    if (obj_Dynamic == NULL) RAISE(45, empty_object)
    LUMI_err = obj_Dynamic->meth(obj, obj_Refman, obj_Dynamic);
    CHECK(45)
LUMI_cleanup:
    LUMI_dec_ref(obj_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-member-outdated"
Returncode error_M_fail_member_outdated(void) {
    Returncode LUMI_err = OK;
    error_M_BaseType* obj_owner = NULL;
    Ref_Manager* obj_owner_Refman = NULL;
    error_M_BaseType_Dynamic* obj_owner_Dynamic = &error_M_BaseType_dynamic;
    error_M_BaseType* obj = NULL;
    Ref_Manager* obj_Refman = NULL;
    error_M_BaseType_Dynamic* obj_Dynamic = NULL;
    error_M_BaseType* aux_BaseType_0 = NULL;
    Ref_Manager* aux_BaseType_0_Refman = NULL;
    error_M_BaseType_Dynamic* aux_BaseType_0_Dynamic = NULL;
    ++LUMI_file_coverage[0].line_count[48];
    INIT_NEW(48, obj_owner, LUMI_alloc(sizeof(error_M_BaseType)));
    ++LUMI_file_coverage[0].line_count[49];
    obj = obj_owner;
    obj_Refman = obj_owner_Refman;
    LUMI_inc_ref(obj_Refman);
    obj_Dynamic = obj_owner_Dynamic;
    ++LUMI_file_coverage[0].line_count[50];
    aux_BaseType_0 = NULL;
    aux_BaseType_0_Refman = NULL;
    aux_BaseType_0_Dynamic = NULL;
    if (obj_owner_Dynamic != NULL) obj_owner_Dynamic->_del(obj_owner);
    LUMI_owner_dec_ref(obj_owner_Refman);
    obj_owner_Refman = aux_BaseType_0_Refman;
    obj_owner_Dynamic = aux_BaseType_0_Dynamic;
    obj_owner = aux_BaseType_0;
    aux_BaseType_0 = NULL;
    aux_BaseType_0_Refman = NULL;
    aux_BaseType_0_Dynamic = NULL;
    ++LUMI_file_coverage[0].line_count[51];
    CHECK_REF(51, obj, obj_Refman)
    TEST_ASSERT(51, obj->x == 0)
    ++LUMI_file_coverage[0].line_count[52];
    if (obj_Dynamic == NULL) RAISE(52, empty_object)
    LUMI_err = obj_Dynamic->meth(obj, obj_Refman, obj_Dynamic);
    CHECK(52)
LUMI_cleanup:
    if (aux_BaseType_0_Dynamic != NULL) aux_BaseType_0_Dynamic->_del(aux_BaseType_0);
    LUMI_owner_dec_ref(aux_BaseType_0_Refman);
    LUMI_dec_ref(obj_Refman);
    if (obj_owner_Dynamic != NULL) obj_owner_Dynamic->_del(obj_owner);
    LUMI_owner_dec_ref(obj_owner_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-sequence-empty"
Returncode error_M_fail_sequence_empty(void) {
    Returncode LUMI_err = OK;
    Array* arr = NULL;
    Ref_Manager* arr_Refman = NULL;
    ++LUMI_file_coverage[0].line_count[55];
    ++LUMI_file_coverage[0].line_count[56];
    CHECK_REF(56, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(56, slice_index)
    TEST_ASSERT(56, (((Int*)((arr)->values))[0]) == 0)
LUMI_cleanup:
    LUMI_dec_ref(arr_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-sequence-outdated"
Returncode error_M_fail_sequence_outdated(void) {
    Returncode LUMI_err = OK;
    Array* arr_owner = NULL;
    Ref_Manager* arr_owner_Refman = NULL;
    Array* arr = NULL;
    Ref_Manager* arr_Refman = NULL;
    Array* aux_Array_0 = NULL;
    Ref_Manager* aux_Array_0_Refman = NULL;
    ++LUMI_file_coverage[0].line_count[59];
    INIT_NEW(59, arr_owner, LUMI_new_array(2, sizeof(Int)));
    ++LUMI_file_coverage[0].line_count[60];
    arr = arr_owner;
    arr_Refman = arr_owner_Refman;
    LUMI_inc_ref(arr_Refman);
    ++LUMI_file_coverage[0].line_count[61];
    aux_Array_0 = NULL;
    aux_Array_0_Refman = NULL;
        LUMI_owner_dec_ref(arr_owner_Refman);
    arr_owner_Refman = aux_Array_0_Refman;
    arr_owner = aux_Array_0;
    aux_Array_0 = NULL;
    aux_Array_0_Refman = NULL;
    ++LUMI_file_coverage[0].line_count[62];
    CHECK_REF(62, arr, arr_Refman)
    if ((0) < 0 || (0) >= (arr)->length) RAISE(62, slice_index)
    TEST_ASSERT(62, (((Int*)((arr)->values))[0]) == 0)
LUMI_cleanup:
    LUMI_owner_dec_ref(aux_Array_0_Refman);
    LUMI_dec_ref(arr_Refman);
    LUMI_owner_dec_ref(arr_owner_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-dynamic-empty"
Returncode error_M_fail_dynamic_empty(void) {
    Returncode LUMI_err = OK;
    error_M_BaseType* obj = NULL;
    Ref_Manager* obj_Refman = NULL;
    error_M_BaseType_Dynamic* obj_Dynamic = NULL;
    ++LUMI_file_coverage[0].line_count[65];
    ++LUMI_file_coverage[0].line_count[66];
    if (obj_Dynamic == NULL) RAISE(66, empty_object)
    LUMI_err = obj_Dynamic->meth(obj, obj_Refman, obj_Dynamic);
    CHECK(66)
LUMI_cleanup:
    LUMI_dec_ref(obj_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-object-no-memory"
Returncode error_M_fail_object_no_memory(void) {
    Returncode LUMI_err = OK;
    error_M_BaseType* obj = NULL;
    Ref_Manager* obj_Refman = NULL;
    error_M_BaseType_Dynamic* obj_Dynamic = &error_M_BaseType_dynamic;
    ++LUMI_file_coverage[0].line_count[69];
    error_M_new_fail_countdown = 1;
    ++LUMI_file_coverage[0].line_count[70];
    INIT_NEW(70, obj, LUMI_alloc(sizeof(error_M_BaseType)));
LUMI_cleanup:
    if (obj_Dynamic != NULL) obj_Dynamic->_del(obj);
    LUMI_owner_dec_ref(obj_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-managed-no-memory"
Returncode error_M_fail_managed_no_memory(void) {
    Returncode LUMI_err = OK;
    error_M_BaseType* obj = NULL;
    Ref_Manager* obj_Refman = NULL;
    error_M_BaseType_Dynamic* obj_Dynamic = &error_M_BaseType_dynamic;
    ++LUMI_file_coverage[0].line_count[73];
    error_M_new_fail_countdown = 2;
    ++LUMI_file_coverage[0].line_count[74];
    INIT_NEW(74, obj, LUMI_alloc(sizeof(error_M_BaseType)));
LUMI_cleanup:
    if (obj_Dynamic != NULL) obj_Dynamic->_del(obj);
    LUMI_owner_dec_ref(obj_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-raise"
Returncode error_M_fail_raise(void) {
    Returncode LUMI_err = OK;
    ++LUMI_file_coverage[0].line_count[77];
    USER_RAISE(77, NULL, NULL)
LUMI_cleanup:
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-raise-message"
Returncode error_M_fail_raise_message(void) {
    Returncode LUMI_err = OK;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    ++LUMI_file_coverage[0].line_count[80];
    INIT_STRING_CONST(80, aux_String_0, "my error");
    LUMI_err = error_M_f_raise_message(aux_String_0, aux_String_0_Refman);
    CHECK(80)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_0_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-assert"
Returncode error_M_fail_assert(void) {
    Returncode LUMI_err = OK;
    ++LUMI_file_coverage[0].line_count[83];
    TEST_ASSERT(83, 1 == 2)
LUMI_cleanup:
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-assert-error"
Returncode error_M_fail_assert_error(void) {
    Returncode LUMI_err = OK;
    ++LUMI_file_coverage[0].line_count[86];
    do {
        ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
        LUMI_err = error_M_f_good_function();
        CHECK(86)
        
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
        --LUMI_trace_ignore_count;
        TEST_FAIL(86, 16, "error not raised")
    } while (false);
    --LUMI_trace_ignore_count;
    LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-assert-error-message"
Returncode error_M_fail_assert_error_message(void) {
    Returncode LUMI_err = OK;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    ++LUMI_file_coverage[0].line_count[89];
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
        INIT_STRING_CONST(89, aux_String_0, "tested other message");
        LUMI_err = error_M_f_raise_message(aux_String_0, aux_String_0_Refman);
        CHECK(89)
        
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
        --LUMI_trace_ignore_count;
        LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
        LUMI_expected_error = LUMI_expected_error_prev;
        TEST_FAIL(89, 16, "error not raised")
    } while (false);
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    if (LUMI_expected_error == NULL) {
        LUMI_expected_error = LUMI_expected_error_prev;
        TEST_FAIL_NULL(89)
    }
    LUMI_expected_error = LUMI_expected_error_prev;}
    LUMI_err = OK;
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_0_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-assert-error-message-prefix"
Returncode error_M_fail_assert_error_message_prefix(void) {
    Returncode LUMI_err = OK;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    ++LUMI_file_coverage[0].line_count[92];
    {char* LUMI_expected_error_prev;
    int LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error_prev = LUMI_expected_error;
    LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
    LUMI_expected_error = "tested message and more";
    LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
    do {
        ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
        INIT_STRING_CONST(92, aux_String_0, "tested message");
        LUMI_err = error_M_f_raise_message(aux_String_0, aux_String_0_Refman);
        CHECK(92)
        
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
        --LUMI_trace_ignore_count;
        LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
        LUMI_expected_error = LUMI_expected_error_prev;
        TEST_FAIL(92, 16, "error not raised")
    } while (false);
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    if (LUMI_expected_error == NULL) {
        LUMI_expected_error = LUMI_expected_error_prev;
        TEST_FAIL_NULL(92)
    }
    LUMI_expected_error = LUMI_expected_error_prev;}
    LUMI_err = OK;
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_0_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "tests/integration-error-test.4.lm"
#define LUMI_FUNC_NAME "fail-owner-cycle"
Returncode error_M_fail_owner_cycle(void) {
    Returncode LUMI_err = OK;
    error_M_Test* t = NULL;
    Ref_Manager* t_Refman = NULL;
    error_M_Test* aux_Test_0 = NULL;
    Ref_Manager* aux_Test_0_Refman = NULL;
    ++LUMI_file_coverage[0].line_count[98];
    INIT_NEW(98, t, LUMI_alloc(sizeof(error_M_Test)));
    ++LUMI_file_coverage[0].line_count[99];
    aux_Test_0 = t;
    aux_Test_0_Refman = t_Refman;
    t = NULL;
    t_Refman = NULL;
    CHECK_REF(99, t, t_Refman)
    error_M_Test_Del(t->t);
    LUMI_owner_dec_ref(t->t_Refman);
    t->t_Refman = aux_Test_0_Refman;
    t->t = aux_Test_0;
    aux_Test_0 = NULL;
    aux_Test_0_Refman = NULL;
LUMI_cleanup:
    error_M_Test_Del(aux_Test_0);
    LUMI_owner_dec_ref(aux_Test_0_Refman);
    error_M_Test_Del(t);
    LUMI_owner_dec_ref(t_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME


Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    Bool LUMI_success = true;
#undef RETURN_ERROR
#define RETURN_ERROR return LUMI_err;
#define LUMI_FUNC_NAME "global variable initialization"
#undef LUMI_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    LUMI_success &= LUMI_run_test("fail-call-empty", error_M_fail_call_empty);
    LUMI_success &= LUMI_run_test("fail-base-class-output", error_M_fail_base_class_output);
    LUMI_success &= LUMI_run_test("fail-slice-index", error_M_fail_slice_index);
    LUMI_success &= LUMI_run_test("fail-member-empty", error_M_fail_member_empty);
    LUMI_success &= LUMI_run_test("fail-member-outdated", error_M_fail_member_outdated);
    LUMI_success &= LUMI_run_test("fail-sequence-empty", error_M_fail_sequence_empty);
    LUMI_success &= LUMI_run_test("fail-sequence-outdated", error_M_fail_sequence_outdated);
    LUMI_success &= LUMI_run_test("fail-dynamic-empty", error_M_fail_dynamic_empty);
    LUMI_success &= LUMI_run_test("fail-object-no-memory", error_M_fail_object_no_memory);
    LUMI_success &= LUMI_run_test("fail-managed-no-memory", error_M_fail_managed_no_memory);
    LUMI_success &= LUMI_run_test("fail-raise", error_M_fail_raise);
    LUMI_success &= LUMI_run_test("fail-raise-message", error_M_fail_raise_message);
    LUMI_success &= LUMI_run_test("fail-assert", error_M_fail_assert);
    LUMI_success &= LUMI_run_test("fail-assert-error", error_M_fail_assert_error);
    LUMI_success &= LUMI_run_test("fail-assert-error-message", error_M_fail_assert_error_message);
    LUMI_success &= LUMI_run_test("fail-assert-error-message-prefix", error_M_fail_assert_error_message_prefix);
    LUMI_success &= LUMI_run_test("fail-owner-cycle", error_M_fail_owner_cycle);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
}

TEST_MAIN_FUNC
