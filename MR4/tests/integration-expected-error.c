#include "mr.4.h"


/* types declaration */

typedef struct BaseType BaseType;

typedef struct BaseType_Dynamic BaseType_Dynamic;

typedef struct TopType TopType;

typedef struct TopType_Dynamic TopType_Dynamic;


/* types struct */

struct BaseType {
  Int x;
};

struct BaseType_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth)(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic);
};

struct TopType {
  BaseType _base;
};

struct TopType_Dynamic {
  BaseType_Dynamic _base;
};


/* types methods declaration */

Returncode BaseType_meth(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic);

void BaseType_Del(BaseType* self);

Returncode TopType_meth(TopType* self, Ref_Manager* self_Refman, TopType_Dynamic* self_Dynamic);

void TopType_Del(TopType* self);


/* types global variables */

BaseType_Dynamic BaseType_dynamic = {(Dynamic_Del)BaseType_Del, BaseType_meth};

TopType_Dynamic TopType_dynamic = {{(Dynamic_Del)TopType_Del, (Func)TopType_meth}};


/* global variables */


/* global functions declaration */

Returncode f_get_top(TopType** top, Ref_Manager** top_Refman, TopType_Dynamic** top_Dynamic);

Returncode f_good_function(void);

Returncode f_raise_message(String* msg, Ref_Manager* msg_Refman);

Returncode fail_call_empty(void);

Returncode fail_base_class_output(void);

Returncode fail_slice_index(void);

Returncode fail_member_empty(void);

Returncode fail_member_outdated(void);

Returncode fail_sequence_empty(void);

Returncode fail_sequence_outdated(void);

Returncode fail_dynamic_empty(void);

Returncode fail_raise(void);

Returncode fail_raise_message(void);

Returncode fail_assert(void);

Returncode fail_assert_error(void);

Returncode fail_assert_error_message(void);

Returncode fail_assert_error_message_prefix(void);


/* types methods body */

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "BaseType.meth"
Returncode BaseType_meth(BaseType* self, Ref_Manager* self_Refman, BaseType_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void BaseType_Del(BaseType* self) {
  if (self == NULL) return;
}

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "TopType.meth"
Returncode TopType_meth(TopType* self, Ref_Manager* self_Refman, TopType_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void TopType_Del(TopType* self) {
  if (self == NULL) return;
  BaseType_Del(&(self->_base));
}


/* global functions body */

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "f-get-top"
Returncode f_get_top(TopType** top, Ref_Manager** top_Refman, TopType_Dynamic** top_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "f-good-function"
Returncode f_good_function(void) {
  Returncode MR_err = OK;
  goto MR_cleanup;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "f-raise-message"
Returncode f_raise_message(String* msg, Ref_Manager* msg_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(msg_Refman);
  USER_RAISE(16, msg, msg_Refman)
MR_cleanup:
  MR_dec_ref(msg_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-call-empty"
Returncode fail_call_empty(void) {
  Returncode MR_err = OK;
  Returncode (*fun)(void) = NULL;
  if (fun == NULL) RAISE(21, 21, "empty function called")
  CHECK(21, fun() )
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-base-class-output"
Returncode fail_base_class_output(void) {
  Returncode MR_err = OK;
  BaseType base_var_Var = {0};
  BaseType* base_var = NULL;
  Ref_Manager* base_var_Refman = NULL;
  BaseType_Dynamic* base_var_Dynamic = &BaseType_dynamic;
  BaseType* base_user = NULL;
  Ref_Manager* base_user_Refman = NULL;
  BaseType_Dynamic* base_user_Dynamic = NULL;
  base_var = &base_var_Var;
  base_var_Refman = MR_new_ref(base_var);
  if (base_var_Refman == NULL) RAISE(24, 38, "insufficient memory for managed object")
  base_user = base_var;
  base_user_Refman = base_var_Refman;
  MR_inc_ref(base_user_Refman);
  base_user_Dynamic = base_var_Dynamic;
  if (base_user != NULL) RAISE(26, 45, "non empty base class given as output argument")
  CHECK(26, f_get_top((void*)&(base_user), &(base_user_Refman), (void*)&(base_user_Dynamic)) )
MR_cleanup:
  MR_dec_ref(base_user_Refman);
  MR_dec_ref(base_var_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-slice-index"
Returncode fail_slice_index(void) {
  Returncode MR_err = OK;
  Int arr_Values[2] = {0};
  Array arr_Var = {2, NULL};
  Array* arr = NULL;
  Ref_Manager* arr_Refman = NULL;
  arr = &arr_Var;
  arr_Var.values = arr_Values;
  arr_Refman = MR_new_ref(arr);
  if (arr_Refman == NULL) RAISE(29, 38, "insufficient memory for managed object")
  if (arr == NULL) RAISE(30, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(30, 40, "outdated weak reference used as sequence")
  if ((6) < 0 || (6) >= (arr)->length) RAISE(30, 25, "slice index out of bounds")
  TEST_ASSERT(30, (((Int*)((arr)->values))[6]) == 0)
MR_cleanup:
  MR_dec_ref(arr_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-member-empty"
Returncode fail_member_empty(void) {
  Returncode MR_err = OK;
  BaseType* obj = NULL;
  Ref_Manager* obj_Refman = NULL;
  BaseType_Dynamic* obj_Dynamic = NULL;
  if (obj == NULL) RAISE(34, 27, "used member of empty object")
  if (obj_Refman->value == NULL) RAISE(34, 38, "used member of outdated weak reference")
  TEST_ASSERT(34, obj->x == 0)
  if (obj_Dynamic == NULL) RAISE(35, 28, "dynamic call of empty object")
  CHECK(35, obj_Dynamic->meth(obj, obj_Refman, obj_Dynamic) )
MR_cleanup:
  MR_dec_ref(obj_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-member-outdated"
Returncode fail_member_outdated(void) {
  Returncode MR_err = OK;
  BaseType* obj_owner = NULL;
  Ref_Manager* obj_owner_Refman = NULL;
  BaseType_Dynamic* obj_owner_Dynamic = &BaseType_dynamic;
  BaseType* obj = NULL;
  Ref_Manager* obj_Refman = NULL;
  BaseType_Dynamic* obj_Dynamic = NULL;
  obj_owner = calloc(1, sizeof(BaseType));
  if (obj_owner == NULL) RAISE(38, 49, "insufficient memory for object dynamic allocation")
  obj_owner_Refman = MR_new_ref(obj_owner);
  if (obj_owner_Refman == NULL) RAISE(38, 38, "insufficient memory for managed object")
  obj = obj_owner;
  obj_Refman = obj_owner_Refman;
  MR_inc_ref(obj_Refman);
  obj_Dynamic = obj_owner_Dynamic;
  if (obj_owner_Dynamic != NULL) obj_owner_Dynamic->_del(obj_owner);
  MR_owner_dec_ref(obj_owner_Refman);
  obj_owner_Refman = NULL;
  obj_owner_Dynamic = NULL;
  obj_owner = NULL;
  if (obj == NULL) RAISE(41, 27, "used member of empty object")
  if (obj_Refman->value == NULL) RAISE(41, 38, "used member of outdated weak reference")
  TEST_ASSERT(41, obj->x == 0)
  if (obj_Dynamic == NULL) RAISE(42, 28, "dynamic call of empty object")
  CHECK(42, obj_Dynamic->meth(obj, obj_Refman, obj_Dynamic) )
MR_cleanup:
  MR_dec_ref(obj_Refman);
  if (obj_owner_Dynamic != NULL) obj_owner_Dynamic->_del(obj_owner);
  MR_owner_dec_ref(obj_owner_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-sequence-empty"
Returncode fail_sequence_empty(void) {
  Returncode MR_err = OK;
  Array* arr = NULL;
  Ref_Manager* arr_Refman = NULL;
  if (arr == NULL) RAISE(46, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(46, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(46, 25, "slice index out of bounds")
  TEST_ASSERT(46, (((Int*)((arr)->values))[0]) == 0)
MR_cleanup:
  MR_dec_ref(arr_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-sequence-outdated"
Returncode fail_sequence_outdated(void) {
  Returncode MR_err = OK;
  Array* arr_owner = NULL;
  Ref_Manager* arr_owner_Refman = NULL;
  Array* arr = NULL;
  Ref_Manager* arr_Refman = NULL;
  arr_owner = MR_new_array(2, sizeof(Int));
  if (arr_owner == NULL) RAISE(49, 49, "insufficient memory for object dynamic allocation")
  arr_owner_Refman = MR_new_ref(arr_owner);
  if (arr_owner_Refman == NULL) RAISE(49, 38, "insufficient memory for managed object")
  arr = arr_owner;
  arr_Refman = arr_owner_Refman;
  MR_inc_ref(arr_Refman);
  MR_owner_dec_ref(arr_owner_Refman);
  arr_owner_Refman = NULL;
  arr_owner = NULL;
  if (arr == NULL) RAISE(52, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(52, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(52, 25, "slice index out of bounds")
  TEST_ASSERT(52, (((Int*)((arr)->values))[0]) == 0)
MR_cleanup:
  MR_dec_ref(arr_Refman);
  MR_owner_dec_ref(arr_owner_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-dynamic-empty"
Returncode fail_dynamic_empty(void) {
  Returncode MR_err = OK;
  BaseType* obj = NULL;
  Ref_Manager* obj_Refman = NULL;
  BaseType_Dynamic* obj_Dynamic = NULL;
  if (obj_Dynamic == NULL) RAISE(56, 28, "dynamic call of empty object")
  CHECK(56, obj_Dynamic->meth(obj, obj_Refman, obj_Dynamic) )
MR_cleanup:
  MR_dec_ref(obj_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-raise"
Returncode fail_raise(void) {
  Returncode MR_err = OK;
  USER_RAISE(59, NULL, NULL)
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-raise-message"
Returncode fail_raise_message(void) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(62, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 9;
  aux_String_0_Var.length = 8;
  aux_String_0_Var.values = "my error";
  CHECK(62, f_raise_message(aux_String_0, aux_String_0_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-assert"
Returncode fail_assert(void) {
  Returncode MR_err = OK;
  TEST_ASSERT(65, 1 == 2)
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-assert-error"
Returncode fail_assert_error(void) {
  Returncode MR_err = OK;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(68, f_good_function() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(68, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-assert-error-message"
Returncode fail_assert_error_message(void) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
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
    aux_String_0 = &aux_String_0_Var;
    aux_String_0_Refman = MR_new_ref(aux_String_0);
    if (aux_String_0_Refman == NULL) RAISE(71, 38, "insufficient memory for managed object")
    aux_String_0_Var.max_length = 21;
    aux_String_0_Var.length = 20;
    aux_String_0_Var.values = "tested other message";
    CHECK(71, f_raise_message(aux_String_0, aux_String_0_Refman) )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(71, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(71)
  }
  MR_expected_error = MR_expected_error_prev;}
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-assert-error-message-prefix"
Returncode fail_assert_error_message_prefix(void) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  {char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "tested message and more";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    aux_String_0 = &aux_String_0_Var;
    aux_String_0_Refman = MR_new_ref(aux_String_0);
    if (aux_String_0_Refman == NULL) RAISE(74, 38, "insufficient memory for managed object")
    aux_String_0_Var.max_length = 15;
    aux_String_0_Var.length = 14;
    aux_String_0_Var.values = "tested message";
    CHECK(74, f_raise_message(aux_String_0, aux_String_0_Refman) )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(74, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(74)
  }
  MR_expected_error = MR_expected_error_prev;}
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME


void Mock_delete(Ref self) {}
USER_MAIN_HEADER {
  Bool MR_success = true;

  RUN_TEST(fail_call_empty);
  RUN_TEST(fail_base_class_output);
  RUN_TEST(fail_slice_index);
  RUN_TEST(fail_member_empty);
  RUN_TEST(fail_member_outdated);
  RUN_TEST(fail_sequence_empty);
  RUN_TEST(fail_sequence_outdated);
  RUN_TEST(fail_dynamic_empty);
  RUN_TEST(fail_raise);
  RUN_TEST(fail_raise_message);
  RUN_TEST(fail_assert);
  RUN_TEST(fail_assert_error);
  RUN_TEST(fail_assert_error_message);
  RUN_TEST(fail_assert_error_message_prefix);
  return MR_success? OK : FAIL;
}

TEST_MAIN_FUNC
