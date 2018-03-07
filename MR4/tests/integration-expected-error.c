#include "mr.4.h"


/* types declaration */

typedef struct error_M_BaseType error_M_BaseType;

typedef struct error_M_BaseType_Dynamic error_M_BaseType_Dynamic;

typedef struct error_M_TopType error_M_TopType;

typedef struct error_M_TopType_Dynamic error_M_TopType_Dynamic;


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


/* types methods declaration */

Returncode error_M_BaseType_meth(error_M_BaseType* self, Ref_Manager* self_Refman, error_M_BaseType_Dynamic* self_Dynamic);

void error_M_BaseType_Del(error_M_BaseType* self);

Returncode error_M_TopType_meth(error_M_TopType* self, Ref_Manager* self_Refman, error_M_TopType_Dynamic* self_Dynamic);

void error_M_TopType_Del(error_M_TopType* self);


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


/* types global variables */

error_M_BaseType_Dynamic error_M_BaseType_dynamic = {(Dynamic_Del)error_M_BaseType_Del, error_M_BaseType_meth};

error_M_TopType_Dynamic error_M_TopType_dynamic = {{(Dynamic_Del)error_M_TopType_Del, (Func)error_M_TopType_meth}};


/* global variables */

Int error_M_new_fail_countdown = 0;

int MR_file0_line_count[94] = {
  -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 0,-1,-1, 0,-1,-1,-1,-1, 0, 0, 0,
   0, 0,-1,-1,-1, 0, 0,-1,-1, 0, 0, 0,-1,-1, 0, 0,-1,-1, 0, 0, 0,-1,-1, 0, 0,
   0, 0, 0,-1,-1, 0, 0,-1,-1, 0, 0, 0, 0,-1,-1, 0, 0,-1,-1, 0, 0,-1,-1, 0, 0,
  -1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1, 0,-1,-1, 0,-1
};
File_Coverage MR_file_coverage[1] = {
  {"tests/integration-error-test.4.mr", 94, MR_file0_line_count}
};


/* types methods body */

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "BaseType.meth"
Returncode error_M_BaseType_meth(error_M_BaseType* self, Ref_Manager* self_Refman, error_M_BaseType_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void error_M_BaseType_Del(error_M_BaseType* self) {
  if (self == NULL) return;
}

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "TopType.meth"
Returncode error_M_TopType_meth(error_M_TopType* self, Ref_Manager* self_Refman, error_M_TopType_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

void error_M_TopType_Del(error_M_TopType* self) {
  if (self == NULL) return;
  error_M_BaseType_Del(&(self->_base));
}


/* global functions body */

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "f-get-top"
Returncode error_M_f_get_top(error_M_TopType** top, Ref_Manager** top_Refman, error_M_TopType_Dynamic** top_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "f-good-function"
Returncode error_M_f_good_function(void) {
  Returncode MR_err = OK;
  ++MR_file_coverage[0].line_count[14];
  goto MR_cleanup;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "f-raise-message"
Returncode error_M_f_raise_message(String* msg, Ref_Manager* msg_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(msg_Refman);
  ++MR_file_coverage[0].line_count[17];
  USER_RAISE(17, msg, msg_Refman)
MR_cleanup:
  MR_dec_ref(msg_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "new Mock"
Returncode new_Mock(Bool* alloc_success) {
  Returncode MR_err = OK;
  ++MR_file_coverage[0].line_count[22];
  *alloc_success = true;
  ++MR_file_coverage[0].line_count[23];
  if (error_M_new_fail_countdown > 0) {
    ++MR_file_coverage[0].line_count[24];
    error_M_new_fail_countdown -= 1;
    ++MR_file_coverage[0].line_count[25];
    if (error_M_new_fail_countdown == 0) {
      ++MR_file_coverage[0].line_count[26];
      *alloc_success = false;
    }
  }
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-call-empty"
Returncode error_M_fail_call_empty(void) {
  Returncode MR_err = OK;
  Returncode (*fun)(void) = NULL;
  ++MR_file_coverage[0].line_count[30];
  ++MR_file_coverage[0].line_count[31];
  if (fun == NULL) RAISE(31, 21, "empty function called")
  CHECK(31, fun() )
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-base-class-output"
Returncode error_M_fail_base_class_output(void) {
  Returncode MR_err = OK;
  error_M_BaseType base_var_Var = {0};
  error_M_BaseType* base_var = NULL;
  Ref_Manager* base_var_Refman = NULL;
  error_M_BaseType_Dynamic* base_var_Dynamic = &error_M_BaseType_dynamic;
  error_M_BaseType* base_user = NULL;
  Ref_Manager* base_user_Refman = NULL;
  error_M_BaseType_Dynamic* base_user_Dynamic = NULL;
  ++MR_file_coverage[0].line_count[34];
  base_var = &base_var_Var;
  base_var_Refman = MR_new_ref(base_var);
  if (base_var_Refman == NULL) RAISE(34, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[35];
  base_user = base_var;
  base_user_Refman = base_var_Refman;
  MR_inc_ref(base_user_Refman);
  base_user_Dynamic = base_var_Dynamic;
  ++MR_file_coverage[0].line_count[36];
  if (base_user != NULL) RAISE(36, 45, "non empty base class given as output argument")
  CHECK(36, error_M_f_get_top((void*)&(base_user), &(base_user_Refman), (void*)&(base_user_Dynamic)) )
MR_cleanup:
  MR_dec_ref(base_user_Refman);
  MR_dec_ref(base_var_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-slice-index"
Returncode error_M_fail_slice_index(void) {
  Returncode MR_err = OK;
  Int arr_Values[2] = {0};
  Array arr_Var = {2, NULL};
  Array* arr = NULL;
  Ref_Manager* arr_Refman = NULL;
  ++MR_file_coverage[0].line_count[39];
  arr = &arr_Var;
  arr_Var.values = arr_Values;
  arr_Refman = MR_new_ref(arr);
  if (arr_Refman == NULL) RAISE(39, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[40];
  if (arr == NULL) RAISE(40, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(40, 40, "outdated weak reference used as sequence")
  if ((6) < 0 || (6) >= (arr)->length) RAISE(40, 25, "slice index out of bounds")
  TEST_ASSERT(40, (((Int*)((arr)->values))[6]) == 0)
MR_cleanup:
  MR_dec_ref(arr_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-member-empty"
Returncode error_M_fail_member_empty(void) {
  Returncode MR_err = OK;
  error_M_BaseType* obj = NULL;
  Ref_Manager* obj_Refman = NULL;
  error_M_BaseType_Dynamic* obj_Dynamic = NULL;
  ++MR_file_coverage[0].line_count[43];
  ++MR_file_coverage[0].line_count[44];
  if (obj == NULL) RAISE(44, 27, "used member of empty object")
  if (obj_Refman->value == NULL) RAISE(44, 38, "used member of outdated weak reference")
  TEST_ASSERT(44, obj->x == 0)
  ++MR_file_coverage[0].line_count[45];
  if (obj_Dynamic == NULL) RAISE(45, 28, "dynamic call of empty object")
  CHECK(45, obj_Dynamic->meth(obj, obj_Refman, obj_Dynamic) )
MR_cleanup:
  MR_dec_ref(obj_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-member-outdated"
Returncode error_M_fail_member_outdated(void) {
  Returncode MR_err = OK;
  error_M_BaseType* obj_owner = NULL;
  Ref_Manager* obj_owner_Refman = NULL;
  error_M_BaseType_Dynamic* obj_owner_Dynamic = &error_M_BaseType_dynamic;
  error_M_BaseType* obj = NULL;
  Ref_Manager* obj_Refman = NULL;
  error_M_BaseType_Dynamic* obj_Dynamic = NULL;
  ++MR_file_coverage[0].line_count[48];
  obj_owner = MR_alloc(sizeof(error_M_BaseType));
  if (obj_owner == NULL) RAISE(48, 49, "insufficient memory for object dynamic allocation")
  obj_owner_Refman = MR_new_ref(obj_owner);
  if (obj_owner_Refman == NULL) RAISE(48, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[49];
  obj = obj_owner;
  obj_Refman = obj_owner_Refman;
  MR_inc_ref(obj_Refman);
  obj_Dynamic = obj_owner_Dynamic;
  ++MR_file_coverage[0].line_count[50];
  if (obj_owner_Dynamic != NULL) obj_owner_Dynamic->_del(obj_owner);
  MR_owner_dec_ref(obj_owner_Refman);
  obj_owner_Refman = NULL;
  obj_owner_Dynamic = NULL;
  obj_owner = NULL;
  ++MR_file_coverage[0].line_count[51];
  if (obj == NULL) RAISE(51, 27, "used member of empty object")
  if (obj_Refman->value == NULL) RAISE(51, 38, "used member of outdated weak reference")
  TEST_ASSERT(51, obj->x == 0)
  ++MR_file_coverage[0].line_count[52];
  if (obj_Dynamic == NULL) RAISE(52, 28, "dynamic call of empty object")
  CHECK(52, obj_Dynamic->meth(obj, obj_Refman, obj_Dynamic) )
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
Returncode error_M_fail_sequence_empty(void) {
  Returncode MR_err = OK;
  Array* arr = NULL;
  Ref_Manager* arr_Refman = NULL;
  ++MR_file_coverage[0].line_count[55];
  ++MR_file_coverage[0].line_count[56];
  if (arr == NULL) RAISE(56, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(56, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(56, 25, "slice index out of bounds")
  TEST_ASSERT(56, (((Int*)((arr)->values))[0]) == 0)
MR_cleanup:
  MR_dec_ref(arr_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-sequence-outdated"
Returncode error_M_fail_sequence_outdated(void) {
  Returncode MR_err = OK;
  Array* arr_owner = NULL;
  Ref_Manager* arr_owner_Refman = NULL;
  Array* arr = NULL;
  Ref_Manager* arr_Refman = NULL;
  ++MR_file_coverage[0].line_count[59];
  arr_owner = MR_new_array(2, sizeof(Int));
  if (arr_owner == NULL) RAISE(59, 49, "insufficient memory for object dynamic allocation")
  arr_owner_Refman = MR_new_ref(arr_owner);
  if (arr_owner_Refman == NULL) RAISE(59, 38, "insufficient memory for managed object")
  ++MR_file_coverage[0].line_count[60];
  arr = arr_owner;
  arr_Refman = arr_owner_Refman;
  MR_inc_ref(arr_Refman);
  ++MR_file_coverage[0].line_count[61];
  MR_owner_dec_ref(arr_owner_Refman);
  arr_owner_Refman = NULL;
  arr_owner = NULL;
  ++MR_file_coverage[0].line_count[62];
  if (arr == NULL) RAISE(62, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(62, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(62, 25, "slice index out of bounds")
  TEST_ASSERT(62, (((Int*)((arr)->values))[0]) == 0)
MR_cleanup:
  MR_dec_ref(arr_Refman);
  MR_owner_dec_ref(arr_owner_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-dynamic-empty"
Returncode error_M_fail_dynamic_empty(void) {
  Returncode MR_err = OK;
  error_M_BaseType* obj = NULL;
  Ref_Manager* obj_Refman = NULL;
  error_M_BaseType_Dynamic* obj_Dynamic = NULL;
  ++MR_file_coverage[0].line_count[65];
  ++MR_file_coverage[0].line_count[66];
  if (obj_Dynamic == NULL) RAISE(66, 28, "dynamic call of empty object")
  CHECK(66, obj_Dynamic->meth(obj, obj_Refman, obj_Dynamic) )
MR_cleanup:
  MR_dec_ref(obj_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-object-no-memory"
Returncode error_M_fail_object_no_memory(void) {
  Returncode MR_err = OK;
  error_M_BaseType* obj = NULL;
  Ref_Manager* obj_Refman = NULL;
  error_M_BaseType_Dynamic* obj_Dynamic = &error_M_BaseType_dynamic;
  ++MR_file_coverage[0].line_count[69];
  error_M_new_fail_countdown = 1;
  ++MR_file_coverage[0].line_count[70];
  obj = MR_alloc(sizeof(error_M_BaseType));
  if (obj == NULL) RAISE(70, 49, "insufficient memory for object dynamic allocation")
  obj_Refman = MR_new_ref(obj);
  if (obj_Refman == NULL) RAISE(70, 38, "insufficient memory for managed object")
MR_cleanup:
  if (obj_Dynamic != NULL) obj_Dynamic->_del(obj);
  MR_owner_dec_ref(obj_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-managed-no-memory"
Returncode error_M_fail_managed_no_memory(void) {
  Returncode MR_err = OK;
  error_M_BaseType* obj = NULL;
  Ref_Manager* obj_Refman = NULL;
  error_M_BaseType_Dynamic* obj_Dynamic = &error_M_BaseType_dynamic;
  ++MR_file_coverage[0].line_count[73];
  error_M_new_fail_countdown = 2;
  ++MR_file_coverage[0].line_count[74];
  obj = MR_alloc(sizeof(error_M_BaseType));
  if (obj == NULL) RAISE(74, 49, "insufficient memory for object dynamic allocation")
  obj_Refman = MR_new_ref(obj);
  if (obj_Refman == NULL) RAISE(74, 38, "insufficient memory for managed object")
MR_cleanup:
  if (obj_Dynamic != NULL) obj_Dynamic->_del(obj);
  MR_owner_dec_ref(obj_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-raise"
Returncode error_M_fail_raise(void) {
  Returncode MR_err = OK;
  ++MR_file_coverage[0].line_count[77];
  USER_RAISE(77, NULL, NULL)
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-raise-message"
Returncode error_M_fail_raise_message(void) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  ++MR_file_coverage[0].line_count[80];
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(80, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 9;
  aux_String_0_Var.length = 8;
  aux_String_0_Var.values = "my error";
  CHECK(80, error_M_f_raise_message(aux_String_0, aux_String_0_Refman) )
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-assert"
Returncode error_M_fail_assert(void) {
  Returncode MR_err = OK;
  ++MR_file_coverage[0].line_count[83];
  TEST_ASSERT(83, 1 == 2)
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-assert-error"
Returncode error_M_fail_assert_error(void) {
  Returncode MR_err = OK;
  ++MR_file_coverage[0].line_count[86];
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(86, error_M_f_good_function() )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(86, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
MR_cleanup:
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME

#define MR_FILE_NAME "tests/integration-error-test.4.mr"
#define MR_FUNC_NAME "fail-assert-error-message"
Returncode error_M_fail_assert_error_message(void) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  ++MR_file_coverage[0].line_count[89];
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
    if (aux_String_0_Refman == NULL) RAISE(89, 38, "insufficient memory for managed object")
    aux_String_0_Var.max_length = 21;
    aux_String_0_Var.length = 20;
    aux_String_0_Var.values = "tested other message";
    CHECK(89, error_M_f_raise_message(aux_String_0, aux_String_0_Refman) )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(89, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(89)
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
Returncode error_M_fail_assert_error_message_prefix(void) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  ++MR_file_coverage[0].line_count[92];
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
    if (aux_String_0_Refman == NULL) RAISE(92, 38, "insufficient memory for managed object")
    aux_String_0_Var.max_length = 15;
    aux_String_0_Var.length = 14;
    aux_String_0_Var.values = "tested message";
    CHECK(92, error_M_f_raise_message(aux_String_0, aux_String_0_Refman) )
    
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(92, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(92)
  }
  MR_expected_error = MR_expected_error_prev;}
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
#undef MR_FILE_NAME
#undef MR_FUNC_NAME


Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
  Bool MR_success = true;
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value;
#define MR_FUNC_NAME "global variable initialization"
#undef MR_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  MR_success &= MR_run_test("fail-call-empty", error_M_fail_call_empty);
  MR_success &= MR_run_test("fail-base-class-output", error_M_fail_base_class_output);
  MR_success &= MR_run_test("fail-slice-index", error_M_fail_slice_index);
  MR_success &= MR_run_test("fail-member-empty", error_M_fail_member_empty);
  MR_success &= MR_run_test("fail-member-outdated", error_M_fail_member_outdated);
  MR_success &= MR_run_test("fail-sequence-empty", error_M_fail_sequence_empty);
  MR_success &= MR_run_test("fail-sequence-outdated", error_M_fail_sequence_outdated);
  MR_success &= MR_run_test("fail-dynamic-empty", error_M_fail_dynamic_empty);
  MR_success &= MR_run_test("fail-object-no-memory", error_M_fail_object_no_memory);
  MR_success &= MR_run_test("fail-managed-no-memory", error_M_fail_managed_no_memory);
  MR_success &= MR_run_test("fail-raise", error_M_fail_raise);
  MR_success &= MR_run_test("fail-raise-message", error_M_fail_raise_message);
  MR_success &= MR_run_test("fail-assert", error_M_fail_assert);
  MR_success &= MR_run_test("fail-assert-error", error_M_fail_assert_error);
  MR_success &= MR_run_test("fail-assert-error-message", error_M_fail_assert_error_message);
  MR_success &= MR_run_test("fail-assert-error-message-prefix", error_M_fail_assert_error_message_prefix);
  MR_success &= MR_test_coverage(MR_file_coverage, 1);
  return MR_success? OK : FAIL;
}

TEST_MAIN_FUNC
