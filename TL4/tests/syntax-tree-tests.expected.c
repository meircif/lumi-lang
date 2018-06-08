/// @@ test-general
/// @ t0
String* ut_M_str = NULL;
Ref_Manager* ut_M_str_Refman = NULL;
/// @ t1
Int ut_M_x = 0;
/// @ t2
Int ut_M_x = 0;
/// @ t3
Int ut_M_x = 0;
/// @ t4
Int ut_M_x = 0;
/// @ t5
Int ut_M_x = 0;
/// @ t6
char ut_M_s_Values[12] = {0};
String ut_M_s_Var = {12, 0, NULL};
String* ut_M_s = NULL;
Ref_Manager* ut_M_s_Refman = NULL;
String* ut_M_us = NULL;
Ref_Manager* ut_M_us_Refman = NULL;
String* ut_M_gs = NULL;
Ref_Manager* ut_M_gs_Refman = NULL;
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
  Returncode LUMI_err = OK;
  Int x = 0;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "mock.4.lm"
  ut_M_s = &ut_M_s_Var;
  ut_M_s_Var.values = ut_M_s_Values;
  ut_M_s_Refman = LUMI_new_ref(ut_M_s);
  if (ut_M_s_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.4.lm"
  ut_M_us = ut_M_s;
  ut_M_us_Refman = ut_M_s_Refman;
  LUMI_inc_ref(ut_M_us_Refman);
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.4.lm"
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(3, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "global text";
  ut_M_gs = aux_String_0;
  ut_M_gs_Refman = aux_String_0_Refman;
  LUMI_inc_ref(ut_M_gs_Refman);
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
  x = 6;
  x = 7;
LUMI_cleanup:
  return LUMI_err;
}
MAIN_FUNC
/// @ t7
Returncode ut_M_fun(void);
Returncode second_M_dummy(void);
char ut_M_s_Values[12] = {0};
String ut_M_s_Var = {12, 0, NULL};
String* ut_M_s = NULL;
Ref_Manager* ut_M_s_Refman = NULL;
int LUMI_file0_line_count[5] = {
  -1,-1,-1, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
  {"mock.4.lm", 5, LUMI_file0_line_count}
};
Returncode ut_M_fun(void) {
  Returncode LUMI_err = OK;
  ++LUMI_file_coverage[0].line_count[3];
  LUMI_dec_ref(ut_M_s_Refman);
  ut_M_s_Refman = NULL;
  LUMI_inc_ref(ut_M_s_Refman);
  ut_M_s = NULL;
LUMI_cleanup:
  return LUMI_err;
}
Returncode second_M_dummy(void) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
  Bool LUMI_success = true;
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "mock.4.lm"
  ut_M_s = &ut_M_s_Var;
  ut_M_s_Var.values = ut_M_s_Values;
  ut_M_s_Refman = LUMI_new_ref(ut_M_s);
  if (ut_M_s_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
  LUMI_success &= LUMI_run_test("dummy", second_M_dummy);
  LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
  return LUMI_success? OK : FAIL;
}
TEST_MAIN_FUNC
/// @ te0
unknown keyword "error"
/// @ te1
statememnt has no effect
/// @ te2
unreachable code
/// @ te3
unreachable code
/// @ te4
expected new-line in line end, got "?"
/// @ te5
expected new-line after "main", got "("
/// @ te6
indentation too long, expected 0 got 2
/// @ te7
indentation too short, expected 6 got 4
/// @ te8
no new-line before file end
/// @ te9
redefinition of global variable "name"
/// @ te10
variable name overrides function "name"
/// @ te11
unknown type "Error"
/// @ te12
unknown symbol "error"
/// @ te13
unexpected "["
/// @@ test-struct
/// @ t0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Int x;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
/// @ t1
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Int x;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
/// @ t2
typedef struct ut_M_Test1 ut_M_Test1;
typedef struct ut_M_Test2 ut_M_Test2;
typedef struct ut_M_Test3 ut_M_Test3;
struct ut_M_Test1 {
  Int x;
};
struct ut_M_Test2 {
  Int x;
};
struct ut_M_Test3 {
  Int x;
};
void ut_M_Test1_Del(ut_M_Test1* self);
void ut_M_Test2_Del(ut_M_Test2* self);
void ut_M_Test3_Del(ut_M_Test3* self);
Generic_Type_Dynamic ut_M_Test1_dynamic = {(Dynamic_Del)ut_M_Test1_Del};
Generic_Type_Dynamic ut_M_Test2_dynamic = {(Dynamic_Del)ut_M_Test2_Del};
Generic_Type_Dynamic ut_M_Test3_dynamic = {(Dynamic_Del)ut_M_Test3_Del};
void ut_M_Test1_Del(ut_M_Test1* self) {
  if (self == NULL) return;
}
void ut_M_Test2_Del(ut_M_Test2* self) {
  if (self == NULL) return;
}
void ut_M_Test3_Del(ut_M_Test3* self) {
  if (self == NULL) return;
}
/// @ t3
typedef struct ut_M_Test1 ut_M_Test1;
typedef struct ut_M_Test2 ut_M_Test2;
struct ut_M_Test1 {
  Int x;
};
struct ut_M_Test2 {
  ut_M_Test1 _base;
  Int y;
};
void ut_M_Test1_Del(ut_M_Test1* self);
void ut_M_Test2_Del(ut_M_Test2* self);
Generic_Type_Dynamic ut_M_Test1_dynamic = {(Dynamic_Del)ut_M_Test1_Del};
Generic_Type_Dynamic ut_M_Test2_dynamic = {(Dynamic_Del)ut_M_Test2_Del};
void ut_M_Test1_Del(ut_M_Test1* self) {
  if (self == NULL) return;
}
void ut_M_Test2_Del(ut_M_Test2* self) {
  if (self == NULL) return;
  ut_M_Test1_Del(&(self->_base));
}
/// @ te0
expected space after "struct", got "("
/// @ te1
illegal type name "error"
/// @ te2
illegal type name "ERror"
/// @ te3
illegal type name "Error-name"
/// @ te4
illegal type name "E"
/// @ te5
redefinition of type "Int"
/// @ te6
redefinition of type "Test"
/// @ te7
expected ")" after base type, got "new-line"
/// @ te8
unknown keyword "error"
/// @ te9
expected block in a new line, got "EOF"
/// @ te10
type with no fields "Error"
/// @ te11
expected "(" after "new", got " "
/// @ te12
constructor already defined for type "Error"
/// @ te13
constructor with outputs
/// @ te14
recursive inheritance in type "Error"
/// @ te15
recursive inheritance in type "Aerror"
/// @@ test-class
/// @ t0
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Mid_Dynamic ut_M_Mid_Dynamic;
typedef struct ut_M_Top ut_M_Top;
typedef struct ut_M_Top_Dynamic ut_M_Top_Dynamic;
struct ut_M_Base {
  Int x;
  ut_M_Base* b;
  Ref_Manager* b_Refman;
  ut_M_Base_Dynamic* b_Dynamic;
};
struct ut_M_Base_Dynamic {
  Dynamic_Del _del;
  Returncode (*dyn0)(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic);
  Returncode (*dyn1)(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic);
};
struct ut_M_Mid {
  ut_M_Base _base;
  Int y;
  ut_M_Mid* m;
  Ref_Manager* m_Refman;
  ut_M_Mid_Dynamic* m_Dynamic;
};
struct ut_M_Mid_Dynamic {
  ut_M_Base_Dynamic _base;
  Returncode (*dyn2)(ut_M_Mid* self, Ref_Manager* self_Refman, ut_M_Mid_Dynamic* self_Dynamic);
};
struct ut_M_Top {
  ut_M_Mid _base;
  Int z;
  ut_M_Top* t;
  Ref_Manager* t_Refman;
  ut_M_Top_Dynamic* t_Dynamic;
};
struct ut_M_Top_Dynamic {
  ut_M_Mid_Dynamic _base;
  Returncode (*dyn3)(ut_M_Top* self, Ref_Manager* self_Refman, ut_M_Top_Dynamic* self_Dynamic);
};
Returncode ut_M_Base_stat(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic);
Returncode ut_M_Base_dyn0(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic);
Returncode ut_M_Base_dyn1(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Mid_dyn0(ut_M_Mid* self, Ref_Manager* self_Refman, ut_M_Mid_Dynamic* self_Dynamic);
Returncode ut_M_Mid_dyn2(ut_M_Mid* self, Ref_Manager* self_Refman, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self);
Returncode ut_M_Top_dyn0(ut_M_Top* self, Ref_Manager* self_Refman, ut_M_Top_Dynamic* self_Dynamic);
Returncode ut_M_Top_dyn3(ut_M_Top* self, Ref_Manager* self_Refman, ut_M_Top_Dynamic* self_Dynamic);
void ut_M_Top_Del(ut_M_Top* self);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_dyn0, ut_M_Base_dyn1};
ut_M_Mid_Dynamic ut_M_Mid_dynamic = {{(Dynamic_Del)ut_M_Mid_Del, (Func)ut_M_Mid_dyn0, ut_M_Base_dyn1}, ut_M_Mid_dyn2};
ut_M_Top_Dynamic ut_M_Top_dynamic = {{{(Dynamic_Del)ut_M_Top_Del, (Func)ut_M_Top_dyn0, ut_M_Base_dyn1}, ut_M_Mid_dyn2}, ut_M_Top_dyn3};
Returncode ut_M_Base_stat(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_Base_dyn0(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_Base_dyn1(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
  DYN_SELF_REF_DEL(ut_M_Base, _, b);
  LUMI_owner_dec_ref(self->b_Refman);
}
Returncode ut_M_Mid_dyn0(ut_M_Mid* self, Ref_Manager* self_Refman, ut_M_Mid_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_Mid_dyn2(ut_M_Mid* self, Ref_Manager* self_Refman, ut_M_Mid_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Mid_Del(ut_M_Mid* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->_base));
  DYN_SELF_REF_DEL(ut_M_Mid, _base._, m);
  LUMI_owner_dec_ref(self->m_Refman);
}
Returncode ut_M_Top_dyn0(ut_M_Top* self, Ref_Manager* self_Refman, ut_M_Top_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  CHECK(16, ut_M_Mid_dyn0(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_Top_dyn3(ut_M_Top* self, Ref_Manager* self_Refman, ut_M_Top_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  CHECK(18, ut_M_Mid_dyn0(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Top_Del(ut_M_Top* self) {
  if (self == NULL) return;
  ut_M_Mid_Del(&(self->_base));
  DYN_SELF_REF_DEL(ut_M_Top, _base._base._, t);
  LUMI_owner_dec_ref(self->t_Refman);
}
/// @ te0
expected space after "class", got "("
/// @ te1
class with no dynamic methods "Error"
/// @ te2
expected "dynamic" or "inst" method type, got "error"
/// @ te3
illegal dynamic in function "meth"
/// @ te4
illegal dynamic in function "meth"
/// @@ test-function
/// @ t0
Returncode ut_M_name(void);
Returncode ut_M_name(void) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
/// @ t1
Returncode ut_M_name(String* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman, Int num);
Returncode ut_M_name(String* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman, Int num) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(text_Refman);
LUMI_cleanup:
  LUMI_dec_ref(text_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
/// @ t2
Returncode ut_M_name(String** text, Ref_Manager** text_Refman, Int* num);
Returncode ut_M_name(String** text, Ref_Manager** text_Refman, Int* num) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
/// @ t3
Returncode ut_M_name(Char param, String** out, Ref_Manager** out_Refman);
Returncode ut_M_name(Char param, String** out, Ref_Manager** out_Refman) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
/// @ t4
Returncode ut_M_name(Array* array, Ref_Manager* array_Refman);
Returncode ut_M_name(Array* array, Ref_Manager* array_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(array_Refman);
LUMI_cleanup:
  LUMI_dec_ref(array_Refman);
  return LUMI_err;
}
/// @ t5
Returncode ut_M_name(Returncode (*fun)(Int x, Int* y), Returncode (**joy)(void));
Returncode ut_M_name(Returncode (*fun)(Int x, Int* y), Returncode (**joy)(void)) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
/// @ t6
Returncode ut_M_name(void);
Returncode ut_M_name(void) {
  Returncode LUMI_err = OK;
  Int x = 0;
LUMI_cleanup:
  return LUMI_err;
}
/// @ t7
Returncode ut_M_name(String* self, Ref_Manager* self_Refman, Int px, String* pu, Ref_Manager* pu_Refman, String* po, Ref_Manager* po_Refman, String** oself, Ref_Manager** oself_Refman, Int* ox, String** ou, Ref_Manager** ou_Refman, String** oo, Ref_Manager** oo_Refman);
Returncode ut_M_name(String* self, Ref_Manager* self_Refman, Int px, String* pu, Ref_Manager* pu_Refman, String* po, Ref_Manager* po_Refman, String** oself, Ref_Manager** oself_Refman, Int* ox, String** ou, Ref_Manager** ou_Refman, String** oo, Ref_Manager** oo_Refman) {
  Returncode LUMI_err = OK;
  Int x = 0;
  String* u = NULL;
  Ref_Manager* u_Refman = NULL;
  String* o = NULL;
  Ref_Manager* o_Refman = NULL;
  char v_Values[12] = {0};
  String v_Var = {12, 0, NULL};
  String* v = NULL;
  Ref_Manager* v_Refman = NULL;
  String* n = NULL;
  Ref_Manager* n_Refman = NULL;
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  String aux_String_2_Var = {0};
  String* aux_String_2 = NULL;
  Ref_Manager* aux_String_2_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(pu_Refman);
  v = &v_Var;
  v_Var.values = v_Values;
  v_Refman = LUMI_new_ref(v);
  if (v_Refman == NULL) RAISE(6, 38, "insufficient memory for managed object")
  n = LUMI_new_string(12);
  if (n == NULL) RAISE(7, 49, "insufficient memory for object dynamic allocation")
  n_Refman = LUMI_new_ref(n);
  if (n_Refman == NULL) RAISE(7, 38, "insufficient memory for managed object")
  aux_String_0 = LUMI_new_string(12);
  if (aux_String_0 == NULL) RAISE(8, 49, "insufficient memory for object dynamic allocation")
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(8, 38, "insufficient memory for managed object")
  String_Del(o);
  LUMI_owner_dec_ref(o_Refman);
  o_Refman = aux_String_0_Refman;
  o = aux_String_0;
  aux_String_0 = NULL;
  aux_String_0_Refman = NULL;
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(9, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 16;
  aux_String_1_Var.length = 15;
  aux_String_1_Var.values = "constant string";
  LUMI_dec_ref(u_Refman);
  u_Refman = aux_String_1_Refman;
  LUMI_inc_ref(u_Refman);
  u = aux_String_1;
  aux_String_2 = &aux_String_2_Var;
  aux_String_2_Refman = LUMI_new_ref(aux_String_2);
  if (aux_String_2_Refman == NULL) RAISE(10, 38, "insufficient memory for managed object")
  aux_String_2_Var.length = 6;
  aux_String_2_Var.max_length = aux_String_2_Var.length + 1;
  aux_String_2_Var.values = (po)->values + (2);
  if (po == NULL) RAISE(10, 29, "empty object used as sequence")
  if (po_Refman->value == NULL) RAISE(10, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (6) < 0 || (2) + (6) > (po)->length) RAISE(10, 25, "slice index out of bounds")
  LUMI_dec_ref(pu_Refman);
  pu_Refman = po_Refman;
  LUMI_inc_ref(pu_Refman);
  pu = aux_String_2;
LUMI_cleanup:
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  String_Del(aux_String_0);
  LUMI_owner_dec_ref(aux_String_0_Refman);
  String_Del(n);
  LUMI_owner_dec_ref(n_Refman);
  LUMI_dec_ref(v_Refman);
  String_Del(o);
  LUMI_owner_dec_ref(o_Refman);
  LUMI_dec_ref(u_Refman);
  String_Del(po);
  LUMI_owner_dec_ref(po_Refman);
  LUMI_dec_ref(pu_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
/// @ t8
typedef struct ut_M_Struct ut_M_Struct;
typedef struct ut_M_Class ut_M_Class;
typedef struct ut_M_Class_Dynamic ut_M_Class_Dynamic;
struct ut_M_Struct {
  ut_M_Struct* s;
  Ref_Manager* s_Refman;
  Array* as;
  Ref_Manager* as_Refman;
};
struct ut_M_Class {
  ut_M_Class* c;
  Ref_Manager* c_Refman;
  ut_M_Class_Dynamic* c_Dynamic;
  Array* ac;
  Ref_Manager* ac_Refman;
};
struct ut_M_Class_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth)(ut_M_Class* self, Ref_Manager* self_Refman, ut_M_Class_Dynamic* self_Dynamic);
};
void ut_M_Struct_Del(ut_M_Struct* self);
Returncode ut_M_Class_meth(ut_M_Class* self, Ref_Manager* self_Refman, ut_M_Class_Dynamic* self_Dynamic);
void ut_M_Class_Del(ut_M_Class* self);
Returncode ut_M_name(ut_M_Struct* ps, Ref_Manager* ps_Refman, ut_M_Class* pc, Ref_Manager* pc_Refman, ut_M_Class_Dynamic* pc_Dynamic, Array* pas, Ref_Manager* pas_Refman, Array* pac, Ref_Manager* pac_Refman);
Generic_Type_Dynamic ut_M_Struct_dynamic = {(Dynamic_Del)ut_M_Struct_Del};
ut_M_Class_Dynamic ut_M_Class_dynamic = {(Dynamic_Del)ut_M_Class_Del, ut_M_Class_meth};
void ut_M_Struct_Del(ut_M_Struct* self) {
  if (self == NULL) return;
  ARRAY_DEL(ut_M_Struct, self->as)
  LUMI_owner_dec_ref(self->as_Refman);
  SELF_REF_DEL(ut_M_Struct, s);
  LUMI_owner_dec_ref(self->s_Refman);
}
Returncode ut_M_Class_meth(ut_M_Class* self, Ref_Manager* self_Refman, ut_M_Class_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Class_Del(ut_M_Class* self) {
  if (self == NULL) return;
  ARRAY_DEL(ut_M_Class, self->ac)
  LUMI_owner_dec_ref(self->ac_Refman);
  DYN_SELF_REF_DEL(ut_M_Class, _, c);
  LUMI_owner_dec_ref(self->c_Refman);
}
Returncode ut_M_name(ut_M_Struct* ps, Ref_Manager* ps_Refman, ut_M_Class* pc, Ref_Manager* pc_Refman, ut_M_Class_Dynamic* pc_Dynamic, Array* pas, Ref_Manager* pas_Refman, Array* pac, Ref_Manager* pac_Refman) {
  Returncode LUMI_err = OK;
  ut_M_Struct* s = NULL;
  Ref_Manager* s_Refman = NULL;
  ut_M_Class* c = NULL;
  Ref_Manager* c_Refman = NULL;
  ut_M_Class_Dynamic* c_Dynamic = NULL;
  Array* as = NULL;
  Ref_Manager* as_Refman = NULL;
  Array* ac = NULL;
  Ref_Manager* ac_Refman = NULL;
  Array* ai = NULL;
  Ref_Manager* ai_Refman = NULL;
  Array* af = NULL;
  Ref_Manager* af_Refman = NULL;
LUMI_cleanup:
  ARRAY_DEL(File, af)
  LUMI_owner_dec_ref(af_Refman);
  LUMI_owner_dec_ref(ai_Refman);
  ARRAY_DEL(ut_M_Class, ac)
  LUMI_owner_dec_ref(ac_Refman);
  ARRAY_DEL(ut_M_Struct, as)
  LUMI_owner_dec_ref(as_Refman);
  if (c_Dynamic != NULL) c_Dynamic->_del(c);
  LUMI_owner_dec_ref(c_Refman);
  ut_M_Struct_Del(s);
  LUMI_owner_dec_ref(s_Refman);
  ARRAY_DEL(ut_M_Class, pac)
  LUMI_owner_dec_ref(pac_Refman);
  ARRAY_DEL(ut_M_Struct, pas)
  LUMI_owner_dec_ref(pas_Refman);
  if (pc_Dynamic != NULL) pc_Dynamic->_del(pc);
  LUMI_owner_dec_ref(pc_Refman);
  ut_M_Struct_Del(ps);
  LUMI_owner_dec_ref(ps_Refman);
  return LUMI_err;
}
/// @ t9
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
  Int x;
};
struct ut_M_Test_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth)(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic);
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_name(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
Returncode ut_M_name(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic) {
  Returncode LUMI_err = OK;
  if (*t_Dynamic != NULL) (*t_Dynamic)->_del(*t);
  LUMI_owner_dec_ref(*t_Refman);
  *t_Refman = NULL;
  *t_Dynamic = NULL;
  *t = NULL;
LUMI_cleanup:
  return LUMI_err;
}
/// @ tm0
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
  Returncode LUMI_err = OK;
  Int x = 0;
LUMI_cleanup:
  return LUMI_err;
}
MAIN_FUNC
/// @ te0
expected space after "func", got "("
/// @ te1
expected "(" after function name, got "new-line"
/// @ te2
illegal function name "Error"
/// @ te3
illegal function name "error_name"
/// @ te4
redefinition of function "name"
/// @ te5
function name overrides global variable "name"
/// @ te6
expected access, got " "
/// @ te7
expected space after access, got ")"
/// @ te8
expected space after type, got "new-line"
/// @ te9
illegal access "error"
/// @ te10
expected space or new-line after ",", got "u"
/// @ te11
expected ">(" got "()"
/// @ te12
expected block in a new line, got "EOF"
/// @ te13
indentation too long, expected 2 got 4
/// @ te14
parameter "x" access should be "copy" for primitive types, got "user"
/// @ te15
output "x" access should be "var" for primitive types, got "copy"
/// @ te16
argument "s" access should not be "copy" for non-primitive type "String"
/// @ te17
missing subtype for array
/// @ te18
missing arguments in function type
/// @ te19
multidimensional array not supported yet...
/// @ te20
indentation too short, expected 4 got 2
/// @@ test-members
/// @ t0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Int x;
  String* str;
  Ref_Manager* str_Refman;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->str_Refman);
}
/// @ t1
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Int x;
};
Returncode ut_M_Test_name(ut_M_Test* self, Ref_Manager* self_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_name(ut_M_Test* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(4, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(4, 38, "used member of outdated weak reference")
  self->x = 2;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
/// @ t2
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Int x;
};
Returncode ut_M_Test_name(ut_M_Test* self, Ref_Manager* self_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_name(ut_M_Test* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  Int x = 0;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(5, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(5, 38, "used member of outdated weak reference")
  x = self->x;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
/// @ t3
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Int x;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
/// @ t4
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Int x;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
/// @ t5
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Int x;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
/// @ t6
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Int x;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
/// @ t7
typedef struct ut_M_Test1 ut_M_Test1;
typedef struct ut_M_Test2 ut_M_Test2;
struct ut_M_Test1 {
  Int name;
};
struct ut_M_Test2 {
  Int fun;
};
Returncode ut_M_Test1_fun(ut_M_Test1* self, Ref_Manager* self_Refman);
void ut_M_Test1_Del(ut_M_Test1* self);
Returncode ut_M_Test2_name(ut_M_Test2* self, Ref_Manager* self_Refman);
void ut_M_Test2_Del(ut_M_Test2* self);
Returncode ut_M_fun(void);
Generic_Type_Dynamic ut_M_Test1_dynamic = {(Dynamic_Del)ut_M_Test1_Del};
Generic_Type_Dynamic ut_M_Test2_dynamic = {(Dynamic_Del)ut_M_Test2_Del};
Int ut_M_name = 0;
Returncode ut_M_Test1_fun(ut_M_Test1* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test1_Del(ut_M_Test1* self) {
  if (self == NULL) return;
}
Returncode ut_M_Test2_name(ut_M_Test2* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test2_Del(ut_M_Test2* self) {
  if (self == NULL) return;
}
Returncode ut_M_fun(void) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
/// @ t8
redefinition of field "name"
/// @ t9
field name overrides method "name"
/// @ t10
redefinition of method "name"
/// @ t11
method name overrides field "name"
/// @ t12
assigning into an owner a non-owner access "user"
/// @@ test-return
/// @ t0
Returncode ut_M_name(void);
Returncode ut_M_name(void) {
  Returncode LUMI_err = OK;
  goto LUMI_cleanup;
LUMI_cleanup:
  return LUMI_err;
}
/// @ t1
Returncode ut_M_name(void);
Returncode ut_M_name(void) {
  Returncode LUMI_err = OK;
  USER_RAISE(2, NULL, NULL)
LUMI_cleanup:
  return LUMI_err;
}
/// @ t2
Returncode ut_M_name(void);
Returncode ut_M_name(void) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(2, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 11;
  aux_String_0_Var.length = 10;
  aux_String_0_Var.values = "some error";
  USER_RAISE(2, aux_String_0, aux_String_0_Refman)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  return LUMI_err;
}
/// @ t3
Returncode ut_M_name(Array* arr, Ref_Manager* arr_Refman);
Returncode ut_M_name(Array* arr, Ref_Manager* arr_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(arr_Refman);
  if (arr == NULL) RAISE(2, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(2, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) >= (arr)->length) RAISE(2, 25, "slice index out of bounds")
  USER_RAISE(2, ((String*)((arr)->values)) + 3, arr_Refman)
LUMI_cleanup:
  LUMI_dec_ref(arr_Refman);
  return LUMI_err;
}
/// @ te0
expected new-line after "return", got "("
/// @ te1
expected space or new-line after "raise", got "("
/// @ te2
got "Int" expression, expected "String"
/// @@ test-code-variables
/// @ t0
Int x = 0;
/// @ t1
String* s = NULL;
  Ref_Manager* s_Refman = NULL;
/// @ t2
Array* a = NULL;
  Ref_Manager* a_Refman = NULL;
/// @ t3
ut_M_Test* tt = NULL;
  Ref_Manager* tt_Refman = NULL;
/// @ t4
char s_Values[12] = {0};
  String s_Var = {12, 0, NULL};
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  s = &s_Var;
  s_Var.values = s_Values;
  s_Refman = LUMI_new_ref(s);
  if (s_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
/// @ t5
Int a_Values[12] = {0};
  Array a_Var = {12, NULL};
  Array* a = NULL;
  Ref_Manager* a_Refman = NULL;
  a = &a_Var;
  a_Var.values = a_Values;
  a_Refman = LUMI_new_ref(a);
  if (a_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
/// @ t6
ut_M_Test a_Values[12] = {{0}};
  Array a_Var = {12, NULL};
  Array* a = NULL;
  Ref_Manager* a_Refman = NULL;
  a = &a_Var;
  a_Var.values = a_Values;
  a_Refman = LUMI_new_ref(a);
  if (a_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
/// @ t7
char sa_Chars[12 * 7];
  String sa_Values[12] = {{0}};
  Array sa_Var = {12, NULL};
  Array* sa = NULL;
  Ref_Manager* sa_Refman = NULL;
  sa = &sa_Var;
  sa_Var.values = sa_Values;
  LUMI_set_var_string_array(12, 7, sa, sa_Chars);
  sa_Refman = LUMI_new_ref(sa);
  if (sa_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
/// @ t8
String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  s = LUMI_new_string(12);
  if (s == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  s_Refman = LUMI_new_ref(s);
  if (s_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  String_Del(*so);
  LUMI_owner_dec_ref(*so_Refman);
  *so_Refman = s_Refman;
  *so = s;
  s = NULL;
  s_Refman = NULL;
/// @ t9
ut_M_Tc a_Values[12] = {{{{{0}}}}};
  Array a_Var = {12, NULL};
  Array* a = NULL;
  Ref_Manager* a_Refman = NULL;
  a = &a_Var;
  a_Var.values = a_Values;
  a_Refman = LUMI_new_ref(a);
  if (a_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
/// @ te0
expected space after type, got "new-line"
/// @ te1
illegal variable name "Error"
/// @ te2
illegal variable name "errorName"
/// @ te3
redefinition of variable "name"
/// @ te4
redefinition of variable "name"
/// @ te5
redefinition of global variable "name"
/// @ te6
variable name overrides function "name"
/// @ te7
type members cannot be initialized
/// @ te8
expected space after "new", got "new-line"
/// @ te9
array length is not constant
/// @ te10
illegal variable name "error--name"
/// @@ test-initialize
/// @ t0
ut_M_Test* aux_Test_0 = NULL;
  Ref_Manager* aux_Test_0_Refman = NULL;
  aux_Test_0 = LUMI_alloc(sizeof(ut_M_Test));
  if (aux_Test_0 == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  aux_Test_0_Refman = LUMI_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, ut_M_Test_new(aux_Test_0, aux_Test_0_Refman, ut_M_i) )
  LUMI_dec_ref(ut_M_t_Refman);
  ut_M_t_Refman = aux_Test_0_Refman;
  LUMI_inc_ref(ut_M_t_Refman);
  ut_M_t = aux_Test_0;
/// @ t1
String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  if (ut_M_arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (ut_M_arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (ut_M_arr)->length) RAISE(1, 25, "slice index out of bounds")
  aux_String_0 = LUMI_new_string(((Int*)((ut_M_arr)->values))[0]);
  if (aux_String_0 == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  LUMI_dec_ref(ut_M_str_Refman);
  ut_M_str_Refman = aux_String_0_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  ut_M_str = aux_String_0;
/// @ t2
Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  if (ut_M_arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (ut_M_arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (ut_M_arr)->length) RAISE(1, 25, "slice index out of bounds")
  aux_Array_0 = LUMI_new_array(((Int*)((ut_M_arr)->values))[0], sizeof(Int));
  if (aux_Array_0 == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  aux_Array_0_Refman = LUMI_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  LUMI_dec_ref(ut_M_arr_Refman);
  ut_M_arr_Refman = aux_Array_0_Refman;
  LUMI_inc_ref(ut_M_arr_Refman);
  ut_M_arr = aux_Array_0;
/// @ t3
Array* a = NULL;
  Ref_Manager* a_Refman = NULL;
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  if (ut_M_arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (ut_M_arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (ut_M_arr)->length) RAISE(1, 25, "slice index out of bounds")
  aux_Array_0 = LUMI_new_array(((Int*)((ut_M_arr)->values))[0], sizeof(ut_M_Test));
  if (aux_Array_0 == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  aux_Array_0_Refman = LUMI_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  a = aux_Array_0;
  a_Refman = aux_Array_0_Refman;
  aux_Array_0 = NULL;
  aux_Array_0_Refman = NULL;
/// @ t4
Array* sa = NULL;
  Ref_Manager* sa_Refman = NULL;
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  if (ut_M_arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (ut_M_arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (ut_M_arr)->length) RAISE(1, 25, "slice index out of bounds")
  if (ut_M_arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (ut_M_arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (ut_M_arr)->length) RAISE(1, 25, "slice index out of bounds")
  aux_Array_0 = LUMI_new_string_array(((Int*)((ut_M_arr)->values))[0], ((Int*)((ut_M_arr)->values))[1]);
  if (aux_Array_0 == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  aux_Array_0_Refman = LUMI_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  sa = aux_Array_0;
  sa_Refman = aux_Array_0_Refman;
  aux_Array_0 = NULL;
  aux_Array_0_Refman = NULL;
/// @ t5
Int x = 0;
  if (ut_M_arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (ut_M_arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (ut_M_arr)->length) RAISE(1, 25, "slice index out of bounds")
  x = ((Int*)((ut_M_arr)->values))[0];
/// @ t6
String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  s = ut_M_str;
  s_Refman = ut_M_str_Refman;
  LUMI_inc_ref(s_Refman);
/// @ t7
char s_Values[12] = {0};
  String s_Var = {12, 0, NULL};
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  s = &s_Var;
  s_Var.values = s_Values;
  s_Refman = LUMI_new_ref(s);
  if (s_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, String_new(s, s_Refman, aux_String_0, aux_String_0_Refman) )
/// @ t8
String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  s = LUMI_new_string(ut_M_i);
  if (s == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  s_Refman = LUMI_new_ref(s);
  if (s_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, String_new(s, s_Refman, ut_M_str, ut_M_str_Refman) )
/// @ t9
ut_M_Test* tt = NULL;
  Ref_Manager* tt_Refman = NULL;
  tt = &(ut_M_tc->_base._base._base);
  tt_Refman = ut_M_tc_Refman;
  LUMI_inc_ref(tt_Refman);
/// @ t10
ut_M_Test tt_Var = {0};
  ut_M_Test* tt = NULL;
  Ref_Manager* tt_Refman = NULL;
  tt = &tt_Var;
  tt_Refman = LUMI_new_ref(tt);
  if (tt_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, ut_M_Test_new(tt, tt_Refman, 3) )
/// @ t11
ut_M_Test* tt = NULL;
  Ref_Manager* tt_Refman = NULL;
  tt = LUMI_alloc(sizeof(ut_M_Test));
  if (tt == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  tt_Refman = LUMI_new_ref(tt);
  if (tt_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, ut_M_Test_new(tt, tt_Refman, 3) )
/// @ t12
ut_M_Test* aux_Test_0 = NULL;
  Ref_Manager* aux_Test_0_Refman = NULL;
  aux_Test_0 = LUMI_alloc(sizeof(ut_M_Test));
  if (aux_Test_0 == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  aux_Test_0_Refman = LUMI_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, ut_M_Test_new(aux_Test_0, aux_Test_0_Refman, 3) )
  LUMI_dec_ref(ut_M_t_Refman);
  ut_M_t_Refman = aux_Test_0_Refman;
  LUMI_inc_ref(ut_M_t_Refman);
  ut_M_t = aux_Test_0;
/// @ t13
ut_M_Tb* tt = NULL;
  Ref_Manager* tt_Refman = NULL;
  ut_M_Tb_Dynamic* tt_Dynamic = NULL;
  tt = ut_M_tb;
  tt_Refman = ut_M_tb_Refman;
  LUMI_inc_ref(tt_Refman);
  tt_Dynamic = ut_M_tb_Dynamic;
/// @ t14
ut_M_Ta* ota = NULL;
  Ref_Manager* ota_Refman = NULL;
  ut_M_Ta_Dynamic* ota_Dynamic = NULL;
  ota = &(ut_M_tb->_base);
  ota_Refman = ut_M_tb_Refman;
  ota_Dynamic = &(ut_M_tb_Dynamic->_base);
  ut_M_tb = NULL;
  ut_M_tb_Refman = NULL;
  ut_M_tb_Dynamic = NULL;
/// @ te0
dynamic allocation of primitive type "Int"
/// @ te1
missing length for sequence
/// @ te2
missing length for sequence
/// @ te3
missing length for sequence
/// @ te4
missing length for sequence
/// @ te5
missing subtype for array
/// @ te6
missing subtype for array
/// @ te7
missing subtype for array
/// @ te8
missing subtype for array
/// @ te9
multidimensional array not supported yet...
/// @ te10
expected ":" or "} after array length", got "new-line"
/// @ te11
expected "}" after sub-types, got "new-line"
/// @ te12
unknown symbol "error"
/// @ te13
got "String" expression, expected "Int"
/// @ te14
only "var" access is supported for primitive types, got "user"
/// @ te15
only "var" access is supported for primitive types, got "owner"
/// @ te16
no contructor for type "File"
/// @ te17
cannot assign "Int" into "Bool"
/// @ te18
only one initialization parameter expected
/// @ te19
no contructor for type "Test"
/// @ te20
access should be "copy" for primitive types, got "user"
/// @ te21
assigning into access "owner" invalid access "user"
/// @ te22
assigning into an owner a non-owner access "user"
/// @ te23
more than one subtype for array
/// @ te24
passing ownership of type "Tb" into static type "Test"
/// @@ test-comment
/// @ t0
Int x = 0;
/// @ t1
Int x = 0;
/// @ t2
Int x = 0;
/// @ t3
Int x = 0;
/// @@ test-if-else
/// @ t0
if (ut_M_t == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  if (ut_M_t->num > 3) {
    ut_M_i -= 2;
  }
/// @ t1
if (ut_M_i > 3) {
    ut_M_i -= 2;
  }
  else {
    ut_M_i += 1;
  }
/// @ t2
if (ut_M_i > 3) {
    ut_M_i -= 3;
  }
  else {
    if (ut_M_t == NULL) RAISE(3, 27, "used member of empty object")
    if (ut_M_t_Refman->value == NULL) RAISE(3, 38, "used member of outdated weak reference")
    if (ut_M_t->num > 2) {
      ut_M_i -= 2;
    }
    else {
      if (ut_M_t == NULL) RAISE(5, 27, "used member of empty object")
      if (ut_M_t_Refman->value == NULL) RAISE(5, 38, "used member of outdated weak reference")
      if (ut_M_t->num > 1) {
        ut_M_i -= 1;
      }
      else {
        ut_M_i += 1;
      }
    }
  }
/// @ t3
if (ut_M_b) {
    goto LUMI_cleanup;
  }
  ut_M_i = 3;
/// @ t4
if (ut_M_b && ut_M_b) {
    ut_M_i += 1;
  }
/// @ te0
got "Int" expression, expected "Bool"
/// @ te1
unknown symbol "error"
/// @ te2
unknown symbol "error"
/// @ te3
unknown symbol "error"
/// @ te4
unreachable code
/// @ te5
expected space after "if", got "("
/// @ te6
"else" without a previous "if"
/// @ te7
expected new-line after "else", got " "
/// @ te8
"else-if" without a previous "if"
/// @ te9
expected space after "else-if", got "("
/// @ te10
expected block in a new line, got "EOF"
/// @@ test-do-loop
/// @ t0
Int x = 0;
  while (true) {
  }
/// @ t1
Int x = 0;
/// @ t2
while (true) {
    if (ut_M_t == NULL) RAISE(2, 27, "used member of empty object")
    if (ut_M_t_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
    if (!(ut_M_t->num > 3)) break;
  }
/// @ t3
while (true) {
    continue;
  }
/// @ te0
expected new-line after "do", got "("
/// @ te1
"while" used not inside loop
/// @ te2
"continue" used not inside loop
/// @ te3
got "Int" expression, expected "Bool"
/// @ te4
unknown symbol "error"
/// @ te5
redefinition of variable "error"
/// @ te6
got void expression, expected "Bool"
/// @@ test-for-loop
/// @ t0
Int n = 0;
  for (n = 0; n < 5; ++n) {
    ut_M_i += n;
  }
/// @ t1
Int n = 0;
  if (ut_M_t == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  for (n = ut_M_t->num; n < ut_M_t->num + 2; ++n) {
    ut_M_i += n;
  }
/// @ t2
Char ch = 0;
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_dec_ref(aux_String_0_Refman);
  aux_String_0_Refman = ut_M_str_Refman;
  LUMI_inc_ref(aux_String_0_Refman);
  aux_String_0 = ut_M_str;
  {int ch_Index; for (ch_Index = 0; ch_Index < aux_String_0->length; ++ch_Index) {
    if (aux_String_0 == NULL) RAISE(1, 29, "empty object used as sequence")
    if (aux_String_0_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
    if ((ch_Index) < 0 || (ch_Index) >= (aux_String_0)->length) RAISE(1, 25, "slice index out of bounds")
    ch = ((aux_String_0)->values)[ch_Index];
    ut_M_c = ch;
  }}
  LUMI_dec_ref(aux_String_0_Refman);
  aux_String_0_Refman = NULL;
  LUMI_inc_ref(aux_String_0_Refman);
  aux_String_0 = NULL;
/// @ t3
Int n = 0;
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  LUMI_dec_ref(aux_Array_0_Refman);
  aux_Array_0_Refman = ut_M_arr_Refman;
  LUMI_inc_ref(aux_Array_0_Refman);
  aux_Array_0 = ut_M_arr;
  {int n_Index; for (n_Index = 0; n_Index < aux_Array_0->length; ++n_Index) {
    if (aux_Array_0 == NULL) RAISE(1, 29, "empty object used as sequence")
    if (aux_Array_0_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
    if ((n_Index) < 0 || (n_Index) >= (aux_Array_0)->length) RAISE(1, 25, "slice index out of bounds")
    n = ((Int*)((aux_Array_0)->values))[n_Index];
    ut_M_i += n;
  }}
  LUMI_dec_ref(aux_Array_0_Refman);
  aux_Array_0_Refman = NULL;
  LUMI_inc_ref(aux_Array_0_Refman);
  aux_Array_0 = NULL;
/// @ t4
String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  LUMI_dec_ref(aux_Array_0_Refman);
  aux_Array_0_Refman = ut_M_sarr_Refman;
  LUMI_inc_ref(aux_Array_0_Refman);
  aux_Array_0 = ut_M_sarr;
  {int s_Index; for (s_Index = 0; s_Index < aux_Array_0->length; ++s_Index) {
    if (aux_Array_0 == NULL) RAISE(1, 29, "empty object used as sequence")
    if (aux_Array_0_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
    if ((s_Index) < 0 || (s_Index) >= (aux_Array_0)->length) RAISE(1, 25, "slice index out of bounds")
    LUMI_dec_ref(s_Refman);
    s_Refman = aux_Array_0_Refman;
    LUMI_inc_ref(s_Refman);
    s = ((String*)((aux_Array_0)->values)) + s_Index;
    LUMI_dec_ref(ut_M_str_Refman);
    ut_M_str_Refman = s_Refman;
    LUMI_inc_ref(ut_M_str_Refman);
    ut_M_str = s;
  }}
  LUMI_dec_ref(aux_Array_0_Refman);
  aux_Array_0_Refman = NULL;
  LUMI_inc_ref(aux_Array_0_Refman);
  aux_Array_0 = NULL;
/// @ t5
Int n = 0;
  for (n = 0; n < 5; ++n) {
    ut_M_i += n;
  }
/// @ t6
Int n = 0;
  for (n = 0; n < 5; ++n) {
    ut_M_i += n;
  }
  for (n = 0; n < 7; ++n) {
    ut_M_i += n;
  }
/// @ t7
Int n = 0;
  for (n = 0; n < 1 + 2; ++n) {
    ut_M_i += n;
  }
/// @ te0
expected space after "for", got "("
/// @ te1
expected space after index name, got "new-line"
/// @ te2
expected "in " got "err"
/// @ te3
cannot iterate void expression
/// @ te4
got "String" expression, expected "Int"
/// @ te5
unknown symbol "error"
/// @ te6
cannot assign "String" into "Int"
/// @@ test-testing
/// @ ta0
if (ut_M_t == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  TEST_ASSERT(1, ut_M_t->num == 2)
/// @ ta1
do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (ut_M_t == NULL) RAISE(1, 27, "used member of empty object")
    if (ut_M_t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
    #undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    TEST_FAIL(1, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
/// @ ta2
do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(1, ut_M_fun0() )
    #undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    TEST_FAIL(1, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
/// @ ta3
{char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "expected error";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (ut_M_t == NULL) RAISE(1, 27, "used member of empty object")
    if (ut_M_t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
    #undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(1, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(1)
  }
  LUMI_expected_error = LUMI_expected_error_prev;}
/// @ ta4
{char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "expected error in the function";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(1, ut_M_fun0() )
    #undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(1, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(1)
  }
  LUMI_expected_error = LUMI_expected_error_prev;}
/// @ ta5
{char* LUMI_expected_error_prev;
  int LUMI_expected_error_trace_ignore_count_prev;
  LUMI_expected_error_prev = LUMI_expected_error;
  LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
  LUMI_expected_error = "expected error in new line";
  LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (ut_M_t == NULL) RAISE(1, 27, "used member of empty object")
    if (ut_M_t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
    #undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(1, 16, "error not raised")
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
  if (LUMI_expected_error == NULL) {
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL_NULL(1)
  }
  LUMI_expected_error = LUMI_expected_error_prev;}
/// @ tm0
Returncode ut_M_fun(void);
Returncode ut_M_fun_Mock(void);
Returncode ut_M_fun(void) {
  Returncode LUMI_err = OK;
  CHECK(2, ut_M_fun_Mock() )
LUMI_cleanup:
  return LUMI_err;
}
Bool ut_M_fun_Mock_active = true;
Returncode ut_M_fun_Mock(void) {
  Returncode LUMI_err = OK;
  if (!ut_M_fun_Mock_active) return ut_M_fun();
  USER_RAISE(4, NULL, NULL)
LUMI_cleanup:
  return LUMI_err;
}
/// @ tm1
Returncode ut_M_fun_Mock(void);
Returncode ut_M_fun(void);
Bool ut_M_fun_Mock_active = true;
Returncode ut_M_fun_Mock(void) {
  Returncode LUMI_err = OK;
  if (!ut_M_fun_Mock_active) return ut_M_fun();
LUMI_cleanup:
  return LUMI_err;
}
Returncode ut_M_fun(void) {
  Returncode LUMI_err = OK;
  CHECK(3, ut_M_fun_Mock() )
LUMI_cleanup:
  return LUMI_err;
}
/// @ tm2
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Int x;
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, Int x);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, Int x);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, Int x) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  CHECK(5, ut_M_Test_meth_Mock(self, self_Refman, x) )
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
Bool ut_M_Test_meth_Mock_active = true;
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, Int x) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (!ut_M_Test_meth_Mock_active) return ut_M_Test_meth(self, self_Refman, x);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
/// @ tm3
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
  Int x;
};
struct ut_M_Test_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth)(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x);
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth_Mock};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (self_Dynamic == NULL) RAISE(5, 28, "dynamic call of empty object")
  CHECK(5, self_Dynamic->meth(self, self_Refman, self_Dynamic, x) )
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
Bool ut_M_Test_meth_Mock_active = true;
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (!ut_M_Test_meth_Mock_active) return ut_M_Test_meth(self, self_Refman, self_Dynamic, x);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
/// @ tm4
Returncode ut_M_fun(Int x, Int* y);
Returncode ut_M_fun_Mock(Int x, Int* y);
Returncode ut_M_fun(Int x, Int* y) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
Bool ut_M_fun_Mock_active = true;
Returncode ut_M_fun_Mock(Int x, Int* y) {
  Returncode LUMI_err = OK;
  if (!ut_M_fun_Mock_active) return ut_M_fun(x, y);
  CHECK(3, ut_M_fun(x, &(*y)) )
  ut_M_fun_Mock_active = false;
  CHECK(5, ut_M_fun_Mock(x, &(*y)) )
  ut_M_fun_Mock_active = true;
LUMI_cleanup:
  return LUMI_err;
}
/// @ tm5
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Int x;
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, Int x, Int* y);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, Int x, Int* y);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, Int x, Int* y) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  CHECK(4, ut_M_Test_meth_Mock(self, self_Refman, x, &(*y)) )
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
Bool ut_M_Test_meth_Mock_active = true;
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, Int x, Int* y) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (!ut_M_Test_meth_Mock_active) return ut_M_Test_meth(self, self_Refman, x, y);
  CHECK(6, ut_M_Test_meth(self, self_Refman, x, &(*y)) )
  CHECK(7, ut_M_Test_meth(self, self_Refman, x, &(*y)) )
  ut_M_Test_meth_Mock_active = false;
  CHECK(9, ut_M_Test_meth_Mock(self, self_Refman, x, &(*y)) )
  ut_M_Test_meth_Mock_active = true;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
/// @ tm6
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
  Int x;
};
struct ut_M_Test_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth)(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y);
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth_Mock};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (self_Dynamic == NULL) RAISE(4, 28, "dynamic call of empty object")
  CHECK(4, self_Dynamic->meth(self, self_Refman, self_Dynamic, x, &(*y)) )
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
Bool ut_M_Test_meth_Mock_active = true;
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (!ut_M_Test_meth_Mock_active) return ut_M_Test_meth(self, self_Refman, self_Dynamic, x, y);
  CHECK(6, ut_M_Test_meth(self, self_Refman, self_Dynamic, x, &(*y)) )
  ut_M_Test_meth_Mock_active = false;
  CHECK(8, ut_M_Test_meth_Mock(self, self_Refman, self_Dynamic, x, &(*y)) )
  ut_M_Test_meth_Mock_active = true;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
/// @ tt0
Returncode ut_M_fun0(void);
Returncode ut_M_fun1(void);
Returncode ut_M_fun2(void);
int LUMI_file0_line_count[30] = {
  -1,-1, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0,
   0, 0, 0, 0,-1
};
int LUMI_file1_line_count[7] = {
  -1,-1,-1, 0,-1, 0,-1
};
File_Coverage LUMI_file_coverage[2] = {
  {"mock.4.lm", 30, LUMI_file0_line_count},
  {"second.4.lm", 7, LUMI_file1_line_count}
};
Returncode ut_M_fun0(void) {
  Returncode LUMI_err = OK;
  Int x = 0;
  Int y = 0;
  Int n = 0;
  ++LUMI_file_coverage[0].line_count[2];
  x = 4;
  ++LUMI_file_coverage[0].line_count[3];
  x += 1;
  ++LUMI_file_coverage[0].line_count[4];
  y = 5;
  ++LUMI_file_coverage[0].line_count[5];
  y = x;
  ++LUMI_file_coverage[0].line_count[6];
  if (y > 3) {
    ++LUMI_file_coverage[0].line_count[7];
    y = 3;
  }
  else {
    ++LUMI_file_coverage[0].line_count[8];
    if (y < 0) {
      ++LUMI_file_coverage[0].line_count[9];
      y = 0;
    }
    else {
      ++LUMI_file_coverage[0].line_count[11];
      y += 1;
    }
  }
  ++LUMI_file_coverage[0].line_count[12];
  do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; break
    ++LUMI_file_coverage[0].line_count[13];
    x = 0;
    ++LUMI_file_coverage[0].line_count[14];
    CHECK(14, Sys_print(sys, sys_Refman, NULL, NULL) )
    ++LUMI_file_coverage[0].line_count[15];
    y = 0;
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
  } while (false);
  --LUMI_trace_ignore_count;
  ++LUMI_file_coverage[0].line_count[16];
  if (LUMI_err != OK) {
    LUMI_err = OK;
    ++LUMI_file_coverage[0].line_count[17];
    x = 1;
    ++LUMI_file_coverage[0].line_count[18];
    x = 2;
  }
  ++LUMI_file_coverage[0].line_count[19];
  if (x > 3) {
    ++LUMI_file_coverage[0].line_count[20];
    goto LUMI_cleanup;
  }
  else {
    ++LUMI_file_coverage[0].line_count[22];
    USER_RAISE(22, NULL, NULL)
  }
  ++LUMI_file_coverage[0].line_count[23];
  while (true) {
    ++LUMI_file_coverage[0].line_count[24];
    if (!(x > 1)) break;
    ++LUMI_file_coverage[0].line_count[25];
    if (x == 5) {
      ++LUMI_file_coverage[0].line_count[26];
      continue;
    }
  }
  ++LUMI_file_coverage[0].line_count[27];
  for (n = 0; n < 3; ++n) {
    ++LUMI_file_coverage[0].line_count[28];
    x += y;
  }
LUMI_cleanup:
  return LUMI_err;
}
Returncode ut_M_fun1(void) {
  Returncode LUMI_err = OK;
  ++LUMI_file_coverage[1].line_count[3];
  CHECK(3, ut_M_fun0() )
LUMI_cleanup:
  return LUMI_err;
}
Returncode ut_M_fun2(void) {
  Returncode LUMI_err = OK;
  ++LUMI_file_coverage[1].line_count[5];
  CHECK(5, ut_M_fun1() )
LUMI_cleanup:
  return LUMI_err;
}
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
  Bool LUMI_success = true;
  LUMI_success &= LUMI_run_test("fun2", ut_M_fun2);
  LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 2);
  return LUMI_success? OK : FAIL;
}
TEST_MAIN_FUNC
/// @ tt1
Returncode ut_M_fun(void);
Returncode second_M_fun0(void);
Returncode second_M_fun1(void);
int LUMI_file0_line_count[5] = {
  -1,-1, 0,-1,-1
};
File_Coverage LUMI_file_coverage[1] = {
  {"mock.4.lm", 5, LUMI_file0_line_count}
};
Returncode ut_M_fun(void) {
  Returncode LUMI_err = OK;
  Int x = 0;
  ++LUMI_file_coverage[0].line_count[2];
LUMI_cleanup:
  return LUMI_err;
}
Returncode second_M_fun0(void) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
Returncode second_M_fun1(void) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
  Bool LUMI_success = true;
  LUMI_success &= LUMI_run_test("fun0", second_M_fun0);
  LUMI_success &= LUMI_run_test("fun1", second_M_fun1);
  LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
  return LUMI_success? OK : FAIL;
}
TEST_MAIN_FUNC
/// @ tmg0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  String* s;
  Ref_Manager* s_Refman;
};
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_Test_MockDel(Ref self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  IGNORE_ERRORS( ut_M_Test_MockDel(self) )
  LUMI_dec_ref(self->s_Refman);
}
Returncode ut_M_Test_MockDel(Ref self) {
  Returncode LUMI_err = OK;
  Ref r = NULL;
  r = self;
LUMI_cleanup:
  return LUMI_err;
}
/// @ tmg1
Returncode delete_Mock(Ref self);
Returncode delete_Mock(Ref self) {
  Returncode LUMI_err = OK;
  Ref r = NULL;
  r = self;
LUMI_cleanup:
  return LUMI_err;
}
Returncode new_Mock(Bool* allocate_success) { return OK; }
USER_MAIN_HEADER {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
MAIN_FUNC
/// @ tmg2
Returncode new_Mock(Bool* allocate_success);
Returncode new_Mock(Bool* allocate_success) {
  Returncode LUMI_err = OK;
  *allocate_success = false;
LUMI_cleanup:
  return LUMI_err;
}
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
MAIN_FUNC
/// @ tr0
Ref r = NULL;
/// @ tr1
Ref r = NULL;
  r = ut_M_str;
/// @ tr2
Ref r = NULL;
  r = NULL;
/// @ tr3
Ref r = NULL;
  r = ut_M_str;
/// @ tr4
Ref r = NULL;
  TEST_ASSERT(2, (void*)r == r)
/// @ te0
got "Int" expression, expected "Bool"
/// @ te1
unknown symbol "error"
/// @ te2
unknown symbol "error"
/// @ te3
test function cannot have arguments
/// @ te4
test function cannot have arguments
/// @ te5
mocking unknown function "error"
/// @ te6
unknown type "Error"
/// @ te7
mocking unknown method "error" of type "Test"
/// @ te8
expected access "user" , got "owner"
/// @ te9
non matching types "Int" and "String"
/// @ te10
non matching subtypes "Char" and "Int"
/// @ te11
expected space after "assert", got "new-line"
/// @ te12
expected space after "assert-error", got "new-line"
/// @ te13
expected space after "mock", got "("
/// @ te14
already mocking function "fun"
/// @ te15
already mocking function "fun"
/// @ te16
already mocking global delete
/// @ te17
already mocking delete of type "Test"
/// @ te18
unknown operator ""
/// @ te19
expected space after ",", got """
/// @ te19-copy
expected space after ",", got """
/// @ te20
no '"' around string constant " "error""
/// @ te21
no '"' around string constant "error"
/// @ te22
already mocking global new
/// @ te23
mock new should have only single Bool output
/// @ te24
mock new should have only single Bool output
/// @ te25
mock new should have only single Bool output
/// @ te26
mock new should have only single Bool output
/// @ te27
mock delete should have no arguments
/// @ te28
mock delete should have no arguments
/// @ te29
mock function has no member "error"
/// @ te30
accessing mock function field in dynamic call to "meth"
/// @@ test-native
/// @ tf0
Returncode external(void);
Returncode ut_M_call(void);
Returncode ut_M_call(void) {
  Returncode LUMI_err = OK;
  CHECK(3, external() )
LUMI_cleanup:
  return LUMI_err;
}
/// @ tf1
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
  Int x;
};
struct ut_M_Test_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth)(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic);
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Returncode external(Int i, String* s, ut_M_Test* ta, Int* io);
Returncode ut_M_call(void);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
Returncode ut_M_call(void) {
  Returncode LUMI_err = OK;
  Int i = 0;
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  ut_M_Test* ta = NULL;
  Ref_Manager* ta_Refman = NULL;
  ut_M_Test_Dynamic* ta_Dynamic = NULL;
  CHECK(9, external(5, s, ta, &(i)) )
LUMI_cleanup:
  LUMI_dec_ref(ta_Refman);
  LUMI_dec_ref(s_Refman);
  return LUMI_err;
}
/// @ tv0
Returncode ut_M_use(void);
extern Int x;
Returncode ut_M_use(void) {
  Returncode LUMI_err = OK;
  x = 2;
LUMI_cleanup:
  return LUMI_err;
}
/// @ tt0
typedef void* Native;
Returncode external(Native n, Native* no);
/// @ te0
expected space after "native", got "("
/// @ te1
expected space after "native" keyword, got "new-line"
/// @ te2
unknown "native" keyword "error"
/// @ tef1
owner argument to native function
/// @ tef2
user output to native function
/// @ tef3
owner argument to native function
/// @ tef4
redefinition of function "error"
/// @ tev3
only primitive types supported for native variable, got "String"
/// @@ test-parameter-type
/// @ t0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
  Array* arr;
  Ref_Manager* arr_Refman;
};
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic, Array* arr, Ref_Manager* arr_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic, Array* arr, Ref_Manager* arr_Refman) {
  Returncode LUMI_err = OK;
  Generic_Type* x = NULL;
  Ref_Manager* x_Refman = NULL;
  Generic_Type_Dynamic* x_Dynamic = NULL;
  ut_M_Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(arr_Refman);
  x = item;
  x_Refman = item_Refman;
  x_Dynamic = item_Dynamic;
  item = NULL;
  item_Refman = NULL;
  item_Dynamic = NULL;
  if (self == NULL) RAISE(6, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(6, 38, "used member of outdated weak reference")
  if (self->item_Dynamic != NULL) ((Generic_Type_Dynamic*)(self->item_Dynamic))->_del(self->item);
  LUMI_owner_dec_ref(self->item_Refman);
  self->item_Refman = x_Refman;
  self->item_Dynamic = x_Dynamic;
  self->item = x;
  x = NULL;
  x_Refman = NULL;
  x_Dynamic = NULL;
  if (self == NULL) RAISE(7, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(7, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->arr_Refman);
  self->arr_Refman = arr_Refman;
  LUMI_inc_ref(self->arr_Refman);
  self->arr = arr;
  t = LUMI_alloc(sizeof(ut_M_Test));
  if (t == NULL) RAISE(8, 49, "insufficient memory for object dynamic allocation")
  t_Refman = LUMI_new_ref(t);
  if (t_Refman == NULL) RAISE(8, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(9, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  if (t == NULL) RAISE(9, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  if (t->item_Dynamic != NULL) ((Generic_Type_Dynamic*)(t->item_Dynamic))->_del(t->item);
  LUMI_owner_dec_ref(t->item_Refman);
  t->item_Refman = self->item_Refman;
  t->item_Dynamic = self->item_Dynamic;
  t->item = self->item;
  self->item = NULL;
  self->item_Refman = NULL;
  self->item_Dynamic = NULL;
  if (t == NULL) RAISE(10, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(10, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(10, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(10, 38, "used member of outdated weak reference")
  if (self->item_Dynamic != NULL) ((Generic_Type_Dynamic*)(self->item_Dynamic))->_del(self->item);
  LUMI_owner_dec_ref(self->item_Refman);
  self->item_Refman = t->item_Refman;
  self->item_Dynamic = t->item_Dynamic;
  self->item = t->item;
  t->item = NULL;
  t->item_Refman = NULL;
  t->item_Dynamic = NULL;
LUMI_cleanup:
  ut_M_Test_Del(t);
  LUMI_owner_dec_ref(t_Refman);
  if (x_Dynamic != NULL) x_Dynamic->_del(x);
  LUMI_owner_dec_ref(x_Refman);
  LUMI_dec_ref(arr_Refman);
  if (item_Dynamic != NULL) item_Dynamic->_del(item);
  LUMI_owner_dec_ref(item_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->arr_Refman);
  if (self->item_Dynamic != NULL) self->item_Dynamic->_del(self->item);
  LUMI_owner_dec_ref(self->item_Refman);
}
/// @ t1
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
Returncode ut_M_Test_get(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_get(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(4, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(4, 38, "used member of outdated weak reference")
  LUMI_dec_ref(*item_Refman);
  *item_Refman = self->item_Refman;
  LUMI_inc_ref(*item_Refman);
  *item_Dynamic = self->item_Dynamic;
  *item = self->item;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  if (self->item_Dynamic != NULL) self->item_Dynamic->_del(self->item);
  LUMI_owner_dec_ref(self->item_Refman);
}
/// @ t2
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Generic_Type* first;
  Ref_Manager* first_Refman;
  Generic_Type_Dynamic* first_Dynamic;
  Generic_Type* second;
  Ref_Manager* second_Refman;
  Generic_Type_Dynamic* second_Dynamic;
  Generic_Type* third;
  Ref_Manager* third_Refman;
  Generic_Type_Dynamic* third_Dynamic;
};
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Generic_Type* second, Ref_Manager* second_Refman, Generic_Type_Dynamic* second_Dynamic, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Generic_Type* second, Ref_Manager* second_Refman, Generic_Type_Dynamic* second_Dynamic, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(first_Refman);
  LUMI_inc_ref(second_Refman);
  LUMI_inc_ref(third_Refman);
  if (self == NULL) RAISE(6, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(6, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->first_Refman);
  self->first_Refman = first_Refman;
  LUMI_inc_ref(self->first_Refman);
  self->first_Dynamic = first_Dynamic;
  self->first = first;
  if (self == NULL) RAISE(7, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(7, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->second_Refman);
  self->second_Refman = second_Refman;
  LUMI_inc_ref(self->second_Refman);
  self->second_Dynamic = second_Dynamic;
  self->second = second;
  if (self == NULL) RAISE(8, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(8, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->third_Refman);
  self->third_Refman = third_Refman;
  LUMI_inc_ref(self->third_Refman);
  self->third_Dynamic = third_Dynamic;
  self->third = third;
LUMI_cleanup:
  LUMI_dec_ref(third_Refman);
  LUMI_dec_ref(second_Refman);
  LUMI_dec_ref(first_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->third_Refman);
  LUMI_dec_ref(self->second_Refman);
  LUMI_dec_ref(self->first_Refman);
}
Returncode ut_M_use(String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
  Returncode LUMI_err = OK;
  ut_M_Test t_Var = {0};
  ut_M_Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  LUMI_inc_ref(first_Refman);
  LUMI_inc_ref(second_Refman);
  LUMI_inc_ref(third_Refman);
  t = &t_Var;
  t_Refman = LUMI_new_ref(t);
  if (t_Refman == NULL) RAISE(10, 38, "insufficient memory for managed object")
  if (t == NULL) RAISE(11, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(11, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->first_Refman);
  t->first_Refman = first_Refman;
  LUMI_inc_ref(t->first_Refman);
  t->first_Dynamic = &String_dynamic;
  t->first = first;
  if (t == NULL) RAISE(12, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(12, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->second_Refman);
  t->second_Refman = second_Refman;
  LUMI_inc_ref(t->second_Refman);
  t->second_Dynamic = &Sys_dynamic;
  t->second = second;
  if (t == NULL) RAISE(13, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(13, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->third_Refman);
  t->third_Refman = third_Refman;
  LUMI_inc_ref(t->third_Refman);
  t->third_Dynamic = &File_dynamic;
  t->third = third;
  CHECK(14, ut_M_Test_set(t, t_Refman, first, first_Refman, &String_dynamic, second, second_Refman, &Sys_dynamic, third, third_Refman, &File_dynamic) )
LUMI_cleanup:
  LUMI_dec_ref(t_Refman);
  LUMI_dec_ref(third_Refman);
  LUMI_dec_ref(second_Refman);
  LUMI_dec_ref(first_Refman);
  return LUMI_err;
}
/// @ t3
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Base {
  Int x;
};
struct ut_M_Test {
  ut_M_Base _base;
};
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->_base));
}
/// @ t4
if (ut_M_d == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_d_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  LUMI_dec_ref(ut_M_d->item_Refman);
  ut_M_d->item_Refman = ut_M_str_Refman;
  LUMI_inc_ref(ut_M_d->item_Refman);
  ut_M_d->item_Dynamic = &String_dynamic;
  ut_M_d->item = ut_M_str;
/// @ t5
if (ut_M_d == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_d_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  LUMI_dec_ref(ut_M_str_Refman);
  ut_M_str_Refman = ut_M_d->item_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  ut_M_str = ut_M_d->item;
/// @ t6
if (ut_M_d == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_d_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  LUMI_dec_ref(ut_M_d->arr_Refman);
  ut_M_d->arr_Refman = ut_M_sarr_Refman;
  LUMI_inc_ref(ut_M_d->arr_Refman);
  ut_M_d->arr = ut_M_sarr;
/// @ t7
if (ut_M_d == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_d_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  if (ut_M_d->arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (ut_M_d->arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (ut_M_d->arr)->length) RAISE(1, 25, "slice index out of bounds")
  LUMI_dec_ref(ut_M_str_Refman);
  ut_M_str_Refman = ut_M_d->arr_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  ut_M_str = ((String*)((ut_M_d->arr)->values)) + 4;
/// @ t8
ut_M_Data ad_Values[5] = {{0}};
  Array ad_Var = {5, NULL};
  Array* ad = NULL;
  Ref_Manager* ad_Refman = NULL;
  ad = &ad_Var;
  ad_Var.values = ad_Values;
  ad_Refman = LUMI_new_ref(ad);
  if (ad_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  if (ad == NULL) RAISE(2, 29, "empty object used as sequence")
  if (ad_Refman->value == NULL) RAISE(2, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (ad)->length) RAISE(2, 25, "slice index out of bounds")
  if (((ut_M_Data*)((ad)->values)) + 2 == NULL) RAISE(2, 27, "used member of empty object")
  if (ad_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
  LUMI_dec_ref(ut_M_str_Refman);
  ut_M_str_Refman = (((ut_M_Data*)((ad)->values)) + 2)->item_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  ut_M_str = (((ut_M_Data*)((ad)->values)) + 2)->item;
/// @ t9
ut_M_Data ad_Values[5] = {{0}};
  Array ad_Var = {5, NULL};
  Array* ad = NULL;
  Ref_Manager* ad_Refman = NULL;
  ad = &ad_Var;
  ad_Var.values = ad_Values;
  ad_Refman = LUMI_new_ref(ad);
  if (ad_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  if (ad == NULL) RAISE(2, 29, "empty object used as sequence")
  if (ad_Refman->value == NULL) RAISE(2, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (ad)->length) RAISE(2, 25, "slice index out of bounds")
  if (((ut_M_Data*)((ad)->values)) + 2 == NULL) RAISE(2, 27, "used member of empty object")
  if (ad_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
  if ((((ut_M_Data*)((ad)->values)) + 2)->arr == NULL) RAISE(2, 29, "empty object used as sequence")
  if ((((ut_M_Data*)((ad)->values)) + 2)->arr_Refman->value == NULL) RAISE(2, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) >= ((((ut_M_Data*)((ad)->values)) + 2)->arr)->length) RAISE(2, 25, "slice index out of bounds")
  LUMI_dec_ref(ut_M_str_Refman);
  ut_M_str_Refman = (((ut_M_Data*)((ad)->values)) + 2)->arr_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  ut_M_str = ((String*)(((((ut_M_Data*)((ad)->values)) + 2)->arr)->values)) + 3;
/// @ t10
CHECK(1, ut_M_Data_set(ut_M_d, ut_M_d_Refman, NULL, NULL, NULL, NULL, NULL) )
/// @ t11
ut_M_Data dr_Var = {0};
  ut_M_Data* dr = NULL;
  Ref_Manager* dr_Refman = NULL;
  dr = &dr_Var;
  dr_Refman = LUMI_new_ref(dr);
  if (dr_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  if (dr == NULL) RAISE(2, 27, "used member of empty object")
  if (dr_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
  if (dr->item == NULL) RAISE(2, 27, "used member of empty object")
  if (dr->item_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
  if (((ut_M_Data*)(dr->item))->item == NULL) RAISE(2, 27, "used member of empty object")
  if (((ut_M_Data*)(dr->item))->item_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
  LUMI_dec_ref(ut_M_str_Refman);
  ut_M_str_Refman = ((ut_M_Data*)(((ut_M_Data*)(dr->item))->item))->item_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  ut_M_str = ((ut_M_Data*)(((ut_M_Data*)(dr->item))->item))->item;
/// @ t12
CHECK(1, ut_M_Data_set(ut_M_d, ut_M_d_Refman, *so, *so_Refman, &String_dynamic, ut_M_sarr, ut_M_sarr_Refman) )
  *so = NULL;
  *so_Refman = NULL;
/// @ t13
String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  CHECK(1, ut_M_Data_get(ut_M_d, ut_M_d_Refman, (void*)&(ut_M_str), &(ut_M_str_Refman), &dynamic_Void) )
  CHECK(2, ut_M_Data_get(ut_M_d, ut_M_d_Refman, (void*)&(aux_String_0), &(aux_String_0_Refman), &dynamic_Void) )
  CHECK(2, String_clear(aux_String_0, aux_String_0_Refman) )
/// @ t14
ut_M_Data dg_Var = {0};
  ut_M_Data* dg = NULL;
  Ref_Manager* dg_Refman = NULL;
  dg = &dg_Var;
  dg_Refman = LUMI_new_ref(dg);
  if (dg_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
/// @ t15
ut_M_Data* dg = NULL;
  Ref_Manager* dg_Refman = NULL;
  dg = ut_M_d;
  dg_Refman = ut_M_d_Refman;
  LUMI_inc_ref(dg_Refman);
/// @ t16
CHECK(1, ut_M_Data_set(ut_M_d, ut_M_d_Refman, *so, *so_Refman, &String_dynamic, ut_M_sarr, ut_M_sarr_Refman) )
  *so = NULL;
  *so_Refman = NULL;
/// @ t17
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  ut_M_Test* next;
  Ref_Manager* next_Refman;
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(4, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(4, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->next_Refman);
  self->next_Refman = self_Refman;
  LUMI_inc_ref(self->next_Refman);
  self->next = self;
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->next_Refman);
}
/// @ t18
ut_M_Data dt_Var = {0};
  ut_M_Data* dt = NULL;
  Ref_Manager* dt_Refman = NULL;
  ut_M_Tc* otc = NULL;
  Ref_Manager* otc_Refman = NULL;
  ut_M_Tc_Dynamic* otc_Dynamic = NULL;
  ut_M_Tb* tb2 = NULL;
  Ref_Manager* tb2_Refman = NULL;
  ut_M_Tb_Dynamic* tb2_Dynamic = NULL;
  ut_M_Tb* aux_Tb_0 = NULL;
  Ref_Manager* aux_Tb_0_Refman = NULL;
  ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = NULL;
  dt = &dt_Var;
  dt_Refman = LUMI_new_ref(dt);
  if (dt_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  if (dt == NULL) RAISE(2, 27, "used member of empty object")
  if (dt_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
  LUMI_dec_ref(dt->item_Refman);
  dt->item_Refman = ut_M_tc_Refman;
  LUMI_inc_ref(dt->item_Refman);
  dt->item_Dynamic = (Generic_Type_Dynamic*)&(ut_M_tc_Dynamic->_base);
  dt->item = &(ut_M_tc->_base);
  if (dt == NULL) RAISE(3, 27, "used member of empty object")
  if (dt_Refman->value == NULL) RAISE(3, 38, "used member of outdated weak reference")
  LUMI_dec_ref(ut_M_ta_Refman);
  ut_M_ta_Refman = dt->item_Refman;
  LUMI_inc_ref(ut_M_ta_Refman);
  ut_M_ta_Dynamic = &(((ut_M_Tb_Dynamic*)(dt->item_Dynamic))->_base);
  ut_M_ta = &(((ut_M_Tb*)(dt->item))->_base);
  CHECK(5, ut_M_Data_set(dt, dt_Refman, &(otc->_base), otc_Refman, (void*)&(otc_Dynamic->_base), NULL, NULL) )
  otc = NULL;
  otc_Refman = NULL;
  otc_Dynamic = NULL;
  if (ut_M_ta != NULL) RAISE(6, 45, "non empty base class given as output argument")
  CHECK(6, ut_M_Data_get(dt, dt_Refman, (void*)&(ut_M_ta), &(ut_M_ta_Refman), (void*)&(ut_M_ta_Dynamic)) )
  CHECK(7, ut_M_Data_get(dt, dt_Refman, (void*)&(aux_Tb_0), &(aux_Tb_0_Refman), (void*)&(aux_Tb_0_Dynamic)) )
  if (aux_Tb_0 == NULL) RAISE(7, 27, "used member of empty object")
  if (aux_Tb_0_Refman->value == NULL) RAISE(7, 38, "used member of outdated weak reference")
  ut_M_i = aux_Tb_0->_base.numa;
  if (dt == NULL) RAISE(8, 27, "used member of empty object")
  if (dt_Refman->value == NULL) RAISE(8, 38, "used member of outdated weak reference")
  if (dt == NULL) RAISE(8, 27, "used member of empty object")
  if (dt_Refman->value == NULL) RAISE(8, 38, "used member of outdated weak reference")
  CHECK(8, ut_M_fun7(dt->item, dt->item_Refman, ((ut_M_Tb_Dynamic*)(dt->item_Dynamic)), &(dt->item), &(dt->item_Refman), &(((ut_M_Tb_Dynamic*)(dt->item_Dynamic)))) )
  if (dt == NULL) RAISE(9, 27, "used member of empty object")
  if (dt_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  tb2 = dt->item;
  tb2_Refman = dt->item_Refman;
  LUMI_inc_ref(tb2_Refman);
  tb2_Dynamic = ((ut_M_Tb_Dynamic*)(dt->item_Dynamic));
  if (dt == NULL) RAISE(10, 27, "used member of empty object")
  if (dt_Refman->value == NULL) RAISE(10, 38, "used member of outdated weak reference")
  LUMI_dec_ref(tb2_Refman);
  tb2_Refman = dt->item_Refman;
  LUMI_inc_ref(tb2_Refman);
  tb2_Dynamic = ((ut_M_Tb_Dynamic*)(dt->item_Dynamic));
  tb2 = dt->item;
/// @ t19
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Base {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Test {
  ut_M_Base _base;
};
Returncode ut_M_Base_get(ut_M_Base* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_mock(ut_M_Test* test, Ref_Manager* test_Refman, String* text, Ref_Manager* text_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Base_get(ut_M_Base* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(text_Refman);
  if (self == NULL) RAISE(6, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(6, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base.item_Refman);
  self->_base.item_Refman = text_Refman;
  LUMI_inc_ref(self->_base.item_Refman);
  self->_base.item_Dynamic = &String_dynamic;
  self->_base.item = text;
  CHECK(7, ut_M_Base_get(&(self->_base), self_Refman, (void*)&(text), &(text_Refman), &dynamic_Void) )
LUMI_cleanup:
  LUMI_dec_ref(text_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_mock(ut_M_Test* test, Ref_Manager* test_Refman, String* text, Ref_Manager* text_Refman) {
  Returncode LUMI_err = OK;
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(test_Refman);
  LUMI_inc_ref(text_Refman);
  if (test == NULL) RAISE(9, 27, "used member of empty object")
  if (test_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  LUMI_dec_ref(test->_base.item_Refman);
  test->_base.item_Refman = text_Refman;
  LUMI_inc_ref(test->_base.item_Refman);
  test->_base.item_Dynamic = &String_dynamic;
  test->_base.item = text;
  CHECK(10, ut_M_Test_set(test, test_Refman, text, text_Refman) )
  if (test == NULL) RAISE(11, 27, "used member of empty object")
  if (test_Refman->value == NULL) RAISE(11, 38, "used member of outdated weak reference")
  LUMI_dec_ref(text_Refman);
  text_Refman = test->_base.item_Refman;
  LUMI_inc_ref(text_Refman);
  text = test->_base.item;
  CHECK(12, ut_M_Base_get(&(test->_base), test_Refman, (void*)&(text), &(text_Refman), &dynamic_Void) )
  CHECK(13, ut_M_Base_get(&(test->_base), test_Refman, (void*)&(aux_String_0), &(aux_String_0_Refman), &dynamic_Void) )
  CHECK(13, String_clear(aux_String_0, aux_String_0_Refman) )
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(text_Refman);
  LUMI_dec_ref(test_Refman);
  return LUMI_err;
}
/// @ t20
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Base {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Base_Dynamic {
  Dynamic_Del _del;
  Returncode (*set)(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
  Returncode (*get)(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
};
struct ut_M_Test {
  ut_M_Base _base;
};
struct ut_M_Test_Dynamic {
  ut_M_Base_Dynamic _base;
};
Returncode ut_M_Base_set(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
Returncode ut_M_Base_get(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
Returncode ut_M_Test_get(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_mock(ut_M_Test* test, Ref_Manager* test_Refman, ut_M_Test_Dynamic* test_Dynamic, String* text, Ref_Manager* text_Refman);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_set, ut_M_Base_get};
ut_M_Test_Dynamic ut_M_Test_dynamic = {{(Dynamic_Del)ut_M_Test_Del, (Func)ut_M_Test_set, (Func)ut_M_Test_get}};
Returncode ut_M_Base_set(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(item_Refman);
LUMI_cleanup:
  LUMI_dec_ref(item_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_Base_get(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(item_Refman);
LUMI_cleanup:
  LUMI_dec_ref(item_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_Test_get(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_mock(ut_M_Test* test, Ref_Manager* test_Refman, ut_M_Test_Dynamic* test_Dynamic, String* text, Ref_Manager* text_Refman) {
  Returncode LUMI_err = OK;
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(test_Refman);
  LUMI_inc_ref(text_Refman);
  if (test_Dynamic == NULL) RAISE(9, 28, "dynamic call of empty object")
  CHECK(9, test_Dynamic->_base.set(&(test->_base), test_Refman, &(test_Dynamic->_base), text, text_Refman, &String_dynamic) )
  if (test_Dynamic == NULL) RAISE(10, 28, "dynamic call of empty object")
  CHECK(10, test_Dynamic->_base.get(&(test->_base), test_Refman, &(test_Dynamic->_base), (void*)&(text), &(text_Refman), &dynamic_Void) )
  if (test_Dynamic == NULL) RAISE(11, 28, "dynamic call of empty object")
  CHECK(11, test_Dynamic->_base.get(&(test->_base), test_Refman, &(test_Dynamic->_base), (void*)&(aux_String_0), &(aux_String_0_Refman), &dynamic_Void) )
  CHECK(11, String_clear(aux_String_0, aux_String_0_Refman) )
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(text_Refman);
  LUMI_dec_ref(test_Refman);
  return LUMI_err;
}
/// @ teg0
expected "}" after type parameters, got "new-line"
/// @ teg1
declared variable with generic subtype "Generic"
/// @ teg2
argument "error" access should not be "copy" for non-primitive type "Generic Type"
/// @ teg3
cannot assign "String" into "Generic Type"
/// @ teg4
cannot assign "Generic Type" into "String"
/// @ teg5
declared variable with generic subtype "Generic"
/// @ teg6
cannot assign generic subtype "Second" into different generic subtype "First"
/// @ teg7
illegal type parameter name "error"
/// @ teg8
cannot slice generic array
/// @ teg9
cannot create generic array
/// @ teg10
cannot create generic array
/// @ teg11
too few parameter given for type "Test"
/// @ teg12
no parameter given for type with parameters "Base"
/// @ teg13
parameter given for type with no parameters "Base"
/// @ teg14
too many parameters given for type "Base"
/// @ teg15
too few parameter given for type "Base"
/// @ tec0
unsupported primitive parameter type "Int"
/// @ tec1
too many parameters given for type "Data"
/// @ tec2
unknown type "Error"
/// @ tec3
parameter given for type with no parameters "Char"
/// @ tec4
cannot assign "Generic Type" into "String"
/// @ tec5
cannot assign type "Data" with no parameter into same type with parameter "String"
/// @ tec6
cannot assign "String" into "Test"
/// @ tec7
array as parameter type is unsupported
/// @@ test-parameter-inheritance
/// @ t0
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Base {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Test {
  ut_M_Base _base;
};
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(String* s, Ref_Manager* s_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  ut_M_Test* aux_Test_0 = NULL;
  Ref_Manager* aux_Test_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(s_Refman);
  if (self == NULL) RAISE(5, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(5, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base.item_Refman);
  self->_base.item_Refman = s_Refman;
  LUMI_inc_ref(self->_base.item_Refman);
  self->_base.item_Dynamic = &String_dynamic;
  self->_base.item = s;
  aux_Test_0 = LUMI_alloc(sizeof(ut_M_Test));
  if (aux_Test_0 == NULL) RAISE(6, 49, "insufficient memory for object dynamic allocation")
  aux_Test_0_Refman = LUMI_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(6, 38, "insufficient memory for managed object")
  CHECK(6, ut_M_Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman) )
LUMI_cleanup:
  ut_M_Test_Del(aux_Test_0);
  LUMI_owner_dec_ref(aux_Test_0_Refman);
  LUMI_dec_ref(s_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_use(String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  ut_M_Test t_Var = {{0}};
  ut_M_Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  LUMI_inc_ref(s_Refman);
  t = &t_Var;
  t_Refman = LUMI_new_ref(t);
  if (t_Refman == NULL) RAISE(8, 38, "insufficient memory for managed object")
  if (t == NULL) RAISE(9, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->_base.item_Refman);
  t->_base.item_Refman = s_Refman;
  LUMI_inc_ref(t->_base.item_Refman);
  t->_base.item_Dynamic = &String_dynamic;
  t->_base.item = s;
LUMI_cleanup:
  LUMI_dec_ref(t_Refman);
  LUMI_dec_ref(s_Refman);
  return LUMI_err;
}
/// @ t1
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Base {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Test {
  ut_M_Base _base;
};
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, String* s, Ref_Manager* s_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(String* s, Ref_Manager* s_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  ut_M_Test* aux_Test_0 = NULL;
  Ref_Manager* aux_Test_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(i_Refman);
  LUMI_inc_ref(s_Refman);
  if (self == NULL) RAISE(5, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(5, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base.item_Refman);
  self->_base.item_Refman = i_Refman;
  LUMI_inc_ref(self->_base.item_Refman);
  self->_base.item_Dynamic = i_Dynamic;
  self->_base.item = i;
  aux_Test_0 = LUMI_alloc(sizeof(ut_M_Test));
  if (aux_Test_0 == NULL) RAISE(6, 49, "insufficient memory for object dynamic allocation")
  aux_Test_0_Refman = LUMI_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(6, 38, "insufficient memory for managed object")
  CHECK(6, ut_M_Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman, &String_dynamic, s, s_Refman) )
LUMI_cleanup:
  ut_M_Test_Del(aux_Test_0);
  LUMI_owner_dec_ref(aux_Test_0_Refman);
  LUMI_dec_ref(s_Refman);
  LUMI_dec_ref(i_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_use(String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  ut_M_Test t_Var = {{0}};
  ut_M_Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  LUMI_inc_ref(s_Refman);
  t = &t_Var;
  t_Refman = LUMI_new_ref(t);
  if (t_Refman == NULL) RAISE(8, 38, "insufficient memory for managed object")
  if (t == NULL) RAISE(9, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->_base.item_Refman);
  t->_base.item_Refman = s_Refman;
  LUMI_inc_ref(t->_base.item_Refman);
  t->_base.item_Dynamic = &String_dynamic;
  t->_base.item = s;
LUMI_cleanup:
  LUMI_dec_ref(t_Refman);
  LUMI_dec_ref(s_Refman);
  return LUMI_err;
}
/// @ t2
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Top ut_M_Top;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Base {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Mid {
  ut_M_Base _base;
};
struct ut_M_Top {
  ut_M_Mid _base;
};
struct ut_M_Test {
  ut_M_Top _base;
};
Returncode ut_M_Base_set(ut_M_Base* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Mid_set(ut_M_Mid* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self);
Returncode ut_M_Top_set(ut_M_Top* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman);
void ut_M_Top_Del(ut_M_Top* self);
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(String* s, Ref_Manager* s_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Top_dynamic = {(Dynamic_Del)ut_M_Top_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Base_set(ut_M_Base* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(i_Refman);
LUMI_cleanup:
  LUMI_dec_ref(i_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Mid_set(ut_M_Mid* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(i_Refman);
LUMI_cleanup:
  LUMI_dec_ref(i_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Mid_Del(ut_M_Mid* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_Top_set(ut_M_Top* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(s_Refman);
  CHECK(8, ut_M_Mid_set(&(self->_base), self_Refman, s, s_Refman, &String_dynamic) )
  if (self == NULL) RAISE(9, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base._base.item_Refman);
  self->_base._base.item_Refman = s_Refman;
  LUMI_inc_ref(self->_base._base.item_Refman);
  self->_base._base.item_Dynamic = &String_dynamic;
  self->_base._base.item = s;
LUMI_cleanup:
  LUMI_dec_ref(s_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Top_Del(ut_M_Top* self) {
  if (self == NULL) return;
  ut_M_Mid_Del(&(self->_base));
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  ut_M_Top* aux_Top_0 = NULL;
  Ref_Manager* aux_Top_0_Refman = NULL;
  ut_M_Test* aux_Test_0 = NULL;
  Ref_Manager* aux_Test_0_Refman = NULL;
  ut_M_Top* aux_Top_1 = NULL;
  Ref_Manager* aux_Top_1_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(s_Refman);
  CHECK(12, ut_M_Top_set(&(self->_base), self_Refman, s, s_Refman) )
  if (self == NULL) RAISE(13, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(13, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base._base._base.item_Refman);
  self->_base._base._base.item_Refman = s_Refman;
  LUMI_inc_ref(self->_base._base._base.item_Refman);
  self->_base._base._base.item_Dynamic = &String_dynamic;
  self->_base._base._base.item = s;
  aux_Top_0 = LUMI_alloc(sizeof(ut_M_Top));
  if (aux_Top_0 == NULL) RAISE(14, 49, "insufficient memory for object dynamic allocation")
  aux_Top_0_Refman = LUMI_new_ref(aux_Top_0);
  if (aux_Top_0_Refman == NULL) RAISE(14, 38, "insufficient memory for managed object")
  CHECK(14, ut_M_Top_set(aux_Top_0, aux_Top_0_Refman, s, s_Refman) )
  aux_Test_0 = LUMI_alloc(sizeof(ut_M_Test));
  if (aux_Test_0 == NULL) RAISE(15, 49, "insufficient memory for object dynamic allocation")
  aux_Test_0_Refman = LUMI_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(15, 38, "insufficient memory for managed object")
  CHECK(15, ut_M_Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman) )
  aux_Top_1 = LUMI_alloc(sizeof(ut_M_Top));
  if (aux_Top_1 == NULL) RAISE(16, 49, "insufficient memory for object dynamic allocation")
  aux_Top_1_Refman = LUMI_new_ref(aux_Top_1);
  if (aux_Top_1_Refman == NULL) RAISE(16, 38, "insufficient memory for managed object")
  CHECK(16, ut_M_Mid_set(&(aux_Top_1->_base), aux_Top_1_Refman, s, s_Refman, &String_dynamic) )
LUMI_cleanup:
  ut_M_Top_Del(aux_Top_1);
  LUMI_owner_dec_ref(aux_Top_1_Refman);
  ut_M_Test_Del(aux_Test_0);
  LUMI_owner_dec_ref(aux_Test_0_Refman);
  ut_M_Top_Del(aux_Top_0);
  LUMI_owner_dec_ref(aux_Top_0_Refman);
  LUMI_dec_ref(s_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  ut_M_Top_Del(&(self->_base));
}
Returncode ut_M_use(String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  ut_M_Test t_Var = {{{{0}}}};
  ut_M_Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  LUMI_inc_ref(s_Refman);
  t = &t_Var;
  t_Refman = LUMI_new_ref(t);
  if (t_Refman == NULL) RAISE(18, 38, "insufficient memory for managed object")
  if (t == NULL) RAISE(19, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(19, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->_base._base._base.item_Refman);
  t->_base._base._base.item_Refman = s_Refman;
  LUMI_inc_ref(t->_base._base._base.item_Refman);
  t->_base._base._base.item_Dynamic = &String_dynamic;
  t->_base._base._base.item = s;
LUMI_cleanup:
  LUMI_dec_ref(t_Refman);
  LUMI_dec_ref(s_Refman);
  return LUMI_err;
}
/// @ t3
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Base {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Test {
  ut_M_Base _base;
};
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, String* s, Ref_Manager* s_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(String* s, Ref_Manager* s_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  ut_M_Test* aux_Test_0 = NULL;
  Ref_Manager* aux_Test_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(i_Refman);
  LUMI_inc_ref(s_Refman);
  if (self == NULL) RAISE(5, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(5, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base.item_Refman);
  self->_base.item_Refman = i_Refman;
  LUMI_inc_ref(self->_base.item_Refman);
  self->_base.item_Dynamic = i_Dynamic;
  self->_base.item = i;
  aux_Test_0 = LUMI_alloc(sizeof(ut_M_Test));
  if (aux_Test_0 == NULL) RAISE(6, 49, "insufficient memory for object dynamic allocation")
  aux_Test_0_Refman = LUMI_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(6, 38, "insufficient memory for managed object")
  CHECK(6, ut_M_Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman, &String_dynamic, s, s_Refman) )
LUMI_cleanup:
  ut_M_Test_Del(aux_Test_0);
  LUMI_owner_dec_ref(aux_Test_0_Refman);
  LUMI_dec_ref(s_Refman);
  LUMI_dec_ref(i_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_use(String* s, Ref_Manager* s_Refman) {
  Returncode LUMI_err = OK;
  ut_M_Test t_Var = {{0}};
  ut_M_Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  LUMI_inc_ref(s_Refman);
  t = &t_Var;
  t_Refman = LUMI_new_ref(t);
  if (t_Refman == NULL) RAISE(8, 38, "insufficient memory for managed object")
  if (t == NULL) RAISE(9, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->_base.item_Refman);
  t->_base.item_Refman = s_Refman;
  LUMI_inc_ref(t->_base.item_Refman);
  t->_base.item_Dynamic = &String_dynamic;
  t->_base.item = s;
LUMI_cleanup:
  LUMI_dec_ref(t_Refman);
  LUMI_dec_ref(s_Refman);
  return LUMI_err;
}
/// @ t4
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Top ut_M_Top;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Base {
  Generic_Type* first;
  Ref_Manager* first_Refman;
  Generic_Type_Dynamic* first_Dynamic;
  Generic_Type* second;
  Ref_Manager* second_Refman;
  Generic_Type_Dynamic* second_Dynamic;
};
struct ut_M_Mid {
  ut_M_Base _base;
  Generic_Type* third;
  Ref_Manager* third_Refman;
  Generic_Type_Dynamic* third_Dynamic;
};
struct ut_M_Top {
  ut_M_Mid _base;
};
struct ut_M_Test {
  ut_M_Top _base;
};
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Mid_set(ut_M_Mid* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self);
Returncode ut_M_Top_set(ut_M_Top* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
void ut_M_Top_Del(ut_M_Top* self);
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Top_dynamic = {(Dynamic_Del)ut_M_Top_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->second_Refman);
  LUMI_dec_ref(self->first_Refman);
}
Returncode ut_M_Mid_set(ut_M_Mid* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(first_Refman);
  LUMI_inc_ref(second_Refman);
  LUMI_inc_ref(third_Refman);
  if (self == NULL) RAISE(7, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(7, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base.first_Refman);
  self->_base.first_Refman = first_Refman;
  LUMI_inc_ref(self->_base.first_Refman);
  self->_base.first_Dynamic = first_Dynamic;
  self->_base.first = first;
  if (self == NULL) RAISE(8, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(8, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base.second_Refman);
  self->_base.second_Refman = second_Refman;
  LUMI_inc_ref(self->_base.second_Refman);
  self->_base.second_Dynamic = &Sys_dynamic;
  self->_base.second = second;
  if (self == NULL) RAISE(9, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->third_Refman);
  self->third_Refman = third_Refman;
  LUMI_inc_ref(self->third_Refman);
  self->third_Dynamic = third_Dynamic;
  self->third = third;
LUMI_cleanup:
  LUMI_dec_ref(third_Refman);
  LUMI_dec_ref(second_Refman);
  LUMI_dec_ref(first_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Mid_Del(ut_M_Mid* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->_base));
  LUMI_dec_ref(self->third_Refman);
}
Returncode ut_M_Top_set(ut_M_Top* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(first_Refman);
  LUMI_inc_ref(second_Refman);
  LUMI_inc_ref(third_Refman);
  if (self == NULL) RAISE(12, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(12, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base._base.first_Refman);
  self->_base._base.first_Refman = first_Refman;
  LUMI_inc_ref(self->_base._base.first_Refman);
  self->_base._base.first_Dynamic = first_Dynamic;
  self->_base._base.first = first;
  if (self == NULL) RAISE(13, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(13, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base._base.second_Refman);
  self->_base._base.second_Refman = second_Refman;
  LUMI_inc_ref(self->_base._base.second_Refman);
  self->_base._base.second_Dynamic = &Sys_dynamic;
  self->_base._base.second = second;
  if (self == NULL) RAISE(14, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(14, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base.third_Refman);
  self->_base.third_Refman = third_Refman;
  LUMI_inc_ref(self->_base.third_Refman);
  self->_base.third_Dynamic = &File_dynamic;
  self->_base.third = third;
LUMI_cleanup:
  LUMI_dec_ref(third_Refman);
  LUMI_dec_ref(second_Refman);
  LUMI_dec_ref(first_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Top_Del(ut_M_Top* self) {
  if (self == NULL) return;
  ut_M_Mid_Del(&(self->_base));
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(first_Refman);
  LUMI_inc_ref(second_Refman);
  LUMI_inc_ref(third_Refman);
  if (self == NULL) RAISE(17, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(17, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base._base._base.first_Refman);
  self->_base._base._base.first_Refman = first_Refman;
  LUMI_inc_ref(self->_base._base._base.first_Refman);
  self->_base._base._base.first_Dynamic = &String_dynamic;
  self->_base._base._base.first = first;
  if (self == NULL) RAISE(18, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(18, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base._base._base.second_Refman);
  self->_base._base._base.second_Refman = second_Refman;
  LUMI_inc_ref(self->_base._base._base.second_Refman);
  self->_base._base._base.second_Dynamic = &Sys_dynamic;
  self->_base._base._base.second = second;
  if (self == NULL) RAISE(19, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(19, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base._base.third_Refman);
  self->_base._base.third_Refman = third_Refman;
  LUMI_inc_ref(self->_base._base.third_Refman);
  self->_base._base.third_Dynamic = &File_dynamic;
  self->_base._base.third = third;
LUMI_cleanup:
  LUMI_dec_ref(third_Refman);
  LUMI_dec_ref(second_Refman);
  LUMI_dec_ref(first_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  ut_M_Top_Del(&(self->_base));
}
Returncode ut_M_use(String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
  Returncode LUMI_err = OK;
  ut_M_Test t_Var = {{{{0}}}};
  ut_M_Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  LUMI_inc_ref(first_Refman);
  LUMI_inc_ref(second_Refman);
  LUMI_inc_ref(third_Refman);
  t = &t_Var;
  t_Refman = LUMI_new_ref(t);
  if (t_Refman == NULL) RAISE(21, 38, "insufficient memory for managed object")
  if (t == NULL) RAISE(22, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(22, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->_base._base._base.first_Refman);
  t->_base._base._base.first_Refman = first_Refman;
  LUMI_inc_ref(t->_base._base._base.first_Refman);
  t->_base._base._base.first_Dynamic = &String_dynamic;
  t->_base._base._base.first = first;
  if (t == NULL) RAISE(23, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(23, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->_base._base._base.second_Refman);
  t->_base._base._base.second_Refman = second_Refman;
  LUMI_inc_ref(t->_base._base._base.second_Refman);
  t->_base._base._base.second_Dynamic = &Sys_dynamic;
  t->_base._base._base.second = second;
  if (t == NULL) RAISE(24, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(24, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->_base._base.third_Refman);
  t->_base._base.third_Refman = third_Refman;
  LUMI_inc_ref(t->_base._base.third_Refman);
  t->_base._base.third_Dynamic = &File_dynamic;
  t->_base._base.third = third;
LUMI_cleanup:
  LUMI_dec_ref(t_Refman);
  LUMI_dec_ref(third_Refman);
  LUMI_dec_ref(second_Refman);
  LUMI_dec_ref(first_Refman);
  return LUMI_err;
}
/// @ t5
typedef struct ut_M_First ut_M_First;
typedef struct ut_M_Second ut_M_Second;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_First {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Second {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Test {
  ut_M_First _base;
};
void ut_M_First_Del(ut_M_First* self);
void ut_M_Second_Del(ut_M_Second* self);
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* g, Ref_Manager* g_Refman, Generic_Type_Dynamic* g_Dynamic, ut_M_Second* sg, Ref_Manager* sg_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(String* s, Ref_Manager* s_Refman, ut_M_Second* ss, Ref_Manager* ss_Refman);
Generic_Type_Dynamic ut_M_First_dynamic = {(Dynamic_Del)ut_M_First_Del};
Generic_Type_Dynamic ut_M_Second_dynamic = {(Dynamic_Del)ut_M_Second_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_First_Del(ut_M_First* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->item_Refman);
}
void ut_M_Second_Del(ut_M_Second* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* g, Ref_Manager* g_Refman, Generic_Type_Dynamic* g_Dynamic, ut_M_Second* sg, Ref_Manager* sg_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(g_Refman);
  LUMI_inc_ref(sg_Refman);
  if (self == NULL) RAISE(7, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(7, 38, "used member of outdated weak reference")
  LUMI_dec_ref(self->_base.item_Refman);
  self->_base.item_Refman = sg_Refman;
  LUMI_inc_ref(self->_base.item_Refman);
  self->_base.item_Dynamic = &ut_M_Second_dynamic;
  self->_base.item = sg;
  if (self == NULL) RAISE(8, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(8, 38, "used member of outdated weak reference")
  if (self->_base.item == NULL) RAISE(8, 27, "used member of empty object")
  if (self->_base.item_Refman->value == NULL) RAISE(8, 38, "used member of outdated weak reference")
  LUMI_dec_ref(((ut_M_Second*)(self->_base.item))->item_Refman);
  ((ut_M_Second*)(self->_base.item))->item_Refman = g_Refman;
  LUMI_inc_ref(((ut_M_Second*)(self->_base.item))->item_Refman);
  ((ut_M_Second*)(self->_base.item))->item_Dynamic = g_Dynamic;
  ((ut_M_Second*)(self->_base.item))->item = g;
LUMI_cleanup:
  LUMI_dec_ref(sg_Refman);
  LUMI_dec_ref(g_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  ut_M_First_Del(&(self->_base));
}
Returncode ut_M_use(String* s, Ref_Manager* s_Refman, ut_M_Second* ss, Ref_Manager* ss_Refman) {
  Returncode LUMI_err = OK;
  ut_M_Test t_Var = {{0}};
  ut_M_Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  LUMI_inc_ref(s_Refman);
  LUMI_inc_ref(ss_Refman);
  t = &t_Var;
  t_Refman = LUMI_new_ref(t);
  if (t_Refman == NULL) RAISE(10, 38, "insufficient memory for managed object")
  if (t == NULL) RAISE(11, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(11, 38, "used member of outdated weak reference")
  LUMI_dec_ref(t->_base.item_Refman);
  t->_base.item_Refman = ss_Refman;
  LUMI_inc_ref(t->_base.item_Refman);
  t->_base.item_Dynamic = &ut_M_Second_dynamic;
  t->_base.item = ss;
  if (t == NULL) RAISE(12, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(12, 38, "used member of outdated weak reference")
  if (t->_base.item == NULL) RAISE(12, 27, "used member of empty object")
  if (t->_base.item_Refman->value == NULL) RAISE(12, 38, "used member of outdated weak reference")
  LUMI_dec_ref(((ut_M_Second*)(t->_base.item))->item_Refman);
  ((ut_M_Second*)(t->_base.item))->item_Refman = s_Refman;
  LUMI_inc_ref(((ut_M_Second*)(t->_base.item))->item_Refman);
  ((ut_M_Second*)(t->_base.item))->item_Dynamic = &String_dynamic;
  ((ut_M_Second*)(t->_base.item))->item = s;
LUMI_cleanup:
  LUMI_dec_ref(t_Refman);
  LUMI_dec_ref(ss_Refman);
  LUMI_dec_ref(s_Refman);
  return LUMI_err;
}
/// @ t6
typedef struct ut_M_BaseGen ut_M_BaseGen;
typedef struct ut_M_TestGen ut_M_TestGen;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_BaseGen {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_TestGen {
  ut_M_BaseGen _base;
};
struct ut_M_Base {
  Int x;
};
struct ut_M_Test {
  ut_M_Base _base;
};
void ut_M_BaseGen_Del(ut_M_BaseGen* self);
void ut_M_TestGen_Del(ut_M_TestGen* self);
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_test(void);
Generic_Type_Dynamic ut_M_BaseGen_dynamic = {(Dynamic_Del)ut_M_BaseGen_Del};
Generic_Type_Dynamic ut_M_TestGen_dynamic = {(Dynamic_Del)ut_M_TestGen_Del};
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_BaseGen_Del(ut_M_BaseGen* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->item_Refman);
}
void ut_M_TestGen_Del(ut_M_TestGen* self) {
  if (self == NULL) return;
  ut_M_BaseGen_Del(&(self->_base));
}
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_test(void) {
  Returncode LUMI_err = OK;
  ut_M_BaseGen* bb = NULL;
  Ref_Manager* bb_Refman = NULL;
  ut_M_BaseGen* bt = NULL;
  Ref_Manager* bt_Refman = NULL;
  ut_M_TestGen* tb = NULL;
  Ref_Manager* tb_Refman = NULL;
  ut_M_TestGen* tt = NULL;
  Ref_Manager* tt_Refman = NULL;
  LUMI_dec_ref(bb_Refman);
  bb_Refman = tb_Refman;
  LUMI_inc_ref(bb_Refman);
  bb = &(tb->_base);
  LUMI_dec_ref(bt_Refman);
  bt_Refman = tt_Refman;
  LUMI_inc_ref(bt_Refman);
  bt = &(tt->_base);
  LUMI_dec_ref(bb_Refman);
  bb_Refman = bt_Refman;
  LUMI_inc_ref(bb_Refman);
  bb = bt;
  LUMI_dec_ref(tb_Refman);
  tb_Refman = tt_Refman;
  LUMI_inc_ref(tb_Refman);
  tb = tt;
  LUMI_dec_ref(bb_Refman);
  bb_Refman = tt_Refman;
  LUMI_inc_ref(bb_Refman);
  bb = &(tt->_base);
LUMI_cleanup:
  LUMI_dec_ref(tt_Refman);
  LUMI_dec_ref(tb_Refman);
  LUMI_dec_ref(bt_Refman);
  LUMI_dec_ref(bb_Refman);
  return LUMI_err;
}
/// @ te0
unknown type "Generic"
/// @ te1
cannot assign "File" into "String"
/// @ te2
cannot assign "String" into "Generic Type"
/// @ te3
cannot assign "File" into "String"
/// @@ test-error-handling
/// @ t0
do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; break
    if (ut_M_t == NULL) RAISE(2, 27, "used member of empty object")
    if (ut_M_t_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
    ut_M_t->num = 1;
    CHECK(3, ut_M_fun0() )
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
  } while (false);
  --LUMI_trace_ignore_count;
  if (LUMI_err != OK) {
    LUMI_err = OK;
    if (ut_M_t == NULL) RAISE(5, 27, "used member of empty object")
    if (ut_M_t_Refman->value == NULL) RAISE(5, 38, "used member of outdated weak reference")
    ut_M_i = ut_M_t->num;
    CHECK(6, ut_M_fun4(2) )
  }
/// @ t1
do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; break
    if (ut_M_t == NULL) RAISE(2, 27, "used member of empty object")
    if (ut_M_t_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
    ut_M_t->num = 1;
    CHECK(3, ut_M_fun0() )
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
  } while (false);
  --LUMI_trace_ignore_count;
  LUMI_err = OK;
/// @ t2
do {
    ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; break
    if (ut_M_t == NULL) RAISE(2, 27, "used member of empty object")
    if (ut_M_t_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
    ut_M_t->num = 1;
    do {
      ++LUMI_trace_ignore_count;
      CHECK(4, ut_M_fun0() )
    } while (false);
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
      LUMI_err = OK;
      CHECK(6, ut_M_fun4(2) )
    }
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
  } while (false);
  --LUMI_trace_ignore_count;
  if (LUMI_err != OK) {
    LUMI_err = OK;
    do {
      ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; break
      if (ut_M_arr == NULL) RAISE(9, 29, "empty object used as sequence")
      if (ut_M_arr_Refman->value == NULL) RAISE(9, 40, "outdated weak reference used as sequence")
      if ((3) < 0 || (3) >= (ut_M_arr)->length) RAISE(9, 25, "slice index out of bounds")
      ut_M_i = ((Int*)((ut_M_arr)->values))[3];
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
    } while (false);
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
      LUMI_err = OK;
      if (ut_M_t == NULL) RAISE(11, 27, "used member of empty object")
      if (ut_M_t_Refman->value == NULL) RAISE(11, 38, "used member of outdated weak reference")
      ut_M_i = ut_M_t->num;
    }
  }
/// @ te0
expected new-line after "try", got "("
/// @ te1
"catch" without a previous "try"
/// @ te2
expected new-line after "catch", got "("
/// @ te3
"try" statement with no code
/// @ te4
"catch" statement with no code
/// @ te5
"catch" without a previous "try"
/// @@ test-for-each
/// @ t0
typedef struct ut_M_TestIterator ut_M_TestIterator;
struct ut_M_TestIterator {
  Int counter;
};
Returncode ut_M_TestIterator_new(ut_M_TestIterator* self, Ref_Manager* self_Refman, Int count);
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, Bool* has_data);
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, Int* num);
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
Returncode ut_M_f_mock(Int* i);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
Returncode ut_M_TestIterator_new(ut_M_TestIterator* self, Ref_Manager* self_Refman, Int count) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, Bool* has_data) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, Int* num) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
  if (self == NULL) return;
}
Returncode ut_M_f_mock(Int* i) {
  Returncode LUMI_err = OK;
  ut_M_TestIterator* aux_TestIterator_0 = NULL;
  Ref_Manager* aux_TestIterator_0_Refman = NULL;
  Int n = 0;
  ut_M_TestIterator* aux_TestIterator_1 = NULL;
  Ref_Manager* aux_TestIterator_1_Refman = NULL;
  aux_TestIterator_0 = LUMI_alloc(sizeof(ut_M_TestIterator));
  if (aux_TestIterator_0 == NULL) RAISE(8, 49, "insufficient memory for object dynamic allocation")
  aux_TestIterator_0_Refman = LUMI_new_ref(aux_TestIterator_0);
  if (aux_TestIterator_0_Refman == NULL) RAISE(8, 38, "insufficient memory for managed object")
  CHECK(8, ut_M_TestIterator_new(aux_TestIterator_0, aux_TestIterator_0_Refman, 6) )
  LUMI_dec_ref(aux_TestIterator_1_Refman);
  aux_TestIterator_1_Refman = aux_TestIterator_0_Refman;
  LUMI_inc_ref(aux_TestIterator_1_Refman);
  aux_TestIterator_1 = aux_TestIterator_0;
  while (true) {
    Bool n_Has = false;
    CHECK(8, ut_M_TestIterator_has(aux_TestIterator_1, aux_TestIterator_1_Refman, &(n_Has)) )
    if (!n_Has) break;
    CHECK(8, ut_M_TestIterator_get(aux_TestIterator_1, aux_TestIterator_1_Refman, &(n)) )
    *i = n;
    CHECK(8, ut_M_TestIterator_next(aux_TestIterator_1, aux_TestIterator_1_Refman) )
  }
  LUMI_dec_ref(aux_TestIterator_1_Refman);
  aux_TestIterator_1_Refman = NULL;
  LUMI_inc_ref(aux_TestIterator_1_Refman);
  aux_TestIterator_1 = NULL;
LUMI_cleanup:
  LUMI_dec_ref(aux_TestIterator_1_Refman);
  ut_M_TestIterator_Del(aux_TestIterator_0);
  LUMI_owner_dec_ref(aux_TestIterator_0_Refman);
  return LUMI_err;
}
/// @ t1
typedef struct ut_M_TestIterator ut_M_TestIterator;
struct ut_M_TestIterator {
  String* value;
  Ref_Manager* value_Refman;
};
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, Bool* has_data);
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, String** text, Ref_Manager** text_Refman);
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
Returncode ut_M_f_mock(ut_M_TestIterator* iter, Ref_Manager* iter_Refman, String** s, Ref_Manager** s_Refman);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, Bool* has_data) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, String** text, Ref_Manager** text_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->value_Refman);
}
Returncode ut_M_f_mock(ut_M_TestIterator* iter, Ref_Manager* iter_Refman, String** s, Ref_Manager** s_Refman) {
  Returncode LUMI_err = OK;
  String* t = NULL;
  Ref_Manager* t_Refman = NULL;
  ut_M_TestIterator* aux_TestIterator_0 = NULL;
  Ref_Manager* aux_TestIterator_0_Refman = NULL;
  LUMI_inc_ref(iter_Refman);
  LUMI_dec_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0_Refman = iter_Refman;
  LUMI_inc_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0 = iter;
  while (true) {
    Bool t_Has = false;
    CHECK(7, ut_M_TestIterator_has(aux_TestIterator_0, aux_TestIterator_0_Refman, &(t_Has)) )
    if (!t_Has) break;
    CHECK(7, ut_M_TestIterator_get(aux_TestIterator_0, aux_TestIterator_0_Refman, &(t), &(t_Refman)) )
    LUMI_dec_ref(*s_Refman);
    *s_Refman = t_Refman;
    LUMI_inc_ref(*s_Refman);
    *s = t;
    CHECK(7, ut_M_TestIterator_next(aux_TestIterator_0, aux_TestIterator_0_Refman) )
  }
  LUMI_dec_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0_Refman = NULL;
  LUMI_inc_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0 = NULL;
LUMI_cleanup:
  LUMI_dec_ref(aux_TestIterator_0_Refman);
  LUMI_dec_ref(t_Refman);
  LUMI_dec_ref(iter_Refman);
  return LUMI_err;
}
/// @ t2
typedef struct ut_M_TestIterator ut_M_TestIterator;
struct ut_M_TestIterator {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, Bool* has_data);
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
Returncode ut_M_f_mock(ut_M_TestIterator* iter, Ref_Manager* iter_Refman, String** s, Ref_Manager** s_Refman);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, Bool* has_data) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_f_mock(ut_M_TestIterator* iter, Ref_Manager* iter_Refman, String** s, Ref_Manager** s_Refman) {
  Returncode LUMI_err = OK;
  String* t = NULL;
  Ref_Manager* t_Refman = NULL;
  ut_M_TestIterator* aux_TestIterator_0 = NULL;
  Ref_Manager* aux_TestIterator_0_Refman = NULL;
  LUMI_inc_ref(iter_Refman);
  LUMI_dec_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0_Refman = iter_Refman;
  LUMI_inc_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0 = iter;
  while (true) {
    Bool t_Has = false;
    CHECK(7, ut_M_TestIterator_has(aux_TestIterator_0, aux_TestIterator_0_Refman, &(t_Has)) )
    if (!t_Has) break;
    CHECK(7, ut_M_TestIterator_get(aux_TestIterator_0, aux_TestIterator_0_Refman, (void*)&(t), &(t_Refman), &dynamic_Void) )
    LUMI_dec_ref(*s_Refman);
    *s_Refman = t_Refman;
    LUMI_inc_ref(*s_Refman);
    *s = t;
    CHECK(7, ut_M_TestIterator_next(aux_TestIterator_0, aux_TestIterator_0_Refman) )
  }
  LUMI_dec_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0_Refman = NULL;
  LUMI_inc_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0 = NULL;
LUMI_cleanup:
  LUMI_dec_ref(aux_TestIterator_0_Refman);
  LUMI_dec_ref(t_Refman);
  LUMI_dec_ref(iter_Refman);
  return LUMI_err;
}
/// @ t3
typedef struct ut_M_TestIterator ut_M_TestIterator;
typedef struct ut_M_TestIterator_Dynamic ut_M_TestIterator_Dynamic;
struct ut_M_TestIterator {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_TestIterator_Dynamic {
  Dynamic_Del _del;
  Returncode (*has)(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic, Bool* has_data);
  Returncode (*get)(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
  Returncode (*next)(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic);
};
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic, Bool* has_data);
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
Returncode ut_M_f_mock(ut_M_TestIterator* iter, Ref_Manager* iter_Refman, ut_M_TestIterator_Dynamic* iter_Dynamic, String** s, Ref_Manager** s_Refman);
ut_M_TestIterator_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del, ut_M_TestIterator_has, ut_M_TestIterator_get, ut_M_TestIterator_next};
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic, Bool* has_data) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_f_mock(ut_M_TestIterator* iter, Ref_Manager* iter_Refman, ut_M_TestIterator_Dynamic* iter_Dynamic, String** s, Ref_Manager** s_Refman) {
  Returncode LUMI_err = OK;
  String* t = NULL;
  Ref_Manager* t_Refman = NULL;
  ut_M_TestIterator* aux_TestIterator_0 = NULL;
  Ref_Manager* aux_TestIterator_0_Refman = NULL;
  ut_M_TestIterator_Dynamic* aux_TestIterator_0_Dynamic = NULL;
  LUMI_inc_ref(iter_Refman);
  LUMI_dec_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0_Refman = iter_Refman;
  LUMI_inc_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0_Dynamic = iter_Dynamic;
  aux_TestIterator_0 = iter;
  while (true) {
    Bool t_Has = false;
    if (aux_TestIterator_0_Dynamic == NULL) RAISE(0, 28, "dynamic call of empty object")
    CHECK(7, aux_TestIterator_0_Dynamic->has(aux_TestIterator_0, aux_TestIterator_0_Refman, aux_TestIterator_0_Dynamic, &(t_Has)) )
    if (!t_Has) break;
    if (aux_TestIterator_0_Dynamic == NULL) RAISE(0, 28, "dynamic call of empty object")
    CHECK(7, aux_TestIterator_0_Dynamic->get(aux_TestIterator_0, aux_TestIterator_0_Refman, aux_TestIterator_0_Dynamic, (void*)&(t), &(t_Refman), &dynamic_Void) )
    LUMI_dec_ref(*s_Refman);
    *s_Refman = t_Refman;
    LUMI_inc_ref(*s_Refman);
    *s = t;
    if (aux_TestIterator_0_Dynamic == NULL) RAISE(0, 28, "dynamic call of empty object")
    CHECK(7, aux_TestIterator_0_Dynamic->next(aux_TestIterator_0, aux_TestIterator_0_Refman, aux_TestIterator_0_Dynamic) )
  }
  LUMI_dec_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0_Refman = NULL;
  LUMI_inc_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0_Dynamic = NULL;
  aux_TestIterator_0 = NULL;
LUMI_cleanup:
  LUMI_dec_ref(aux_TestIterator_0_Refman);
  LUMI_dec_ref(t_Refman);
  LUMI_dec_ref(iter_Refman);
  return LUMI_err;
}
/// @ te0
cannot iterate type with no "has" named method -  "TestIterator"
/// @ te1
iterator "has" method has parameters in type "TestIterator"
/// @ te2
iterator "has" method has no outputs in type "TestIterator"
/// @ te3
iterator "has" method has more than one output in type "TestIterator"
/// @ te4
iterator "has" method output is not "Bool" in type "TestIterator"
/// @ te5
cannot iterate type with no "get" named method -  "TestIterator"
/// @ te6
iterator "get" method has parameters in type "TestIterator"
/// @ te7
iterator "get" method has no outputs in type "TestIterator"
/// @ te8
iterator "get" method has more than one output in type "TestIterator"
/// @ te9
iterator "get" method output has "owner" access in type "TestIterator"
/// @ te10
cannot iterate type with no "next" named method -  "TestIterator"
/// @ te11
iterator "next" method has parameters in type "TestIterator"
/// @ te12
iterator "next" method has outputs in type "TestIterator"
/// @@ test-complex-fields
/// @ t0
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Base {
  ut_M_Base* b;
  Ref_Manager* b_Refman;
  ut_M_Base_Dynamic* b_Dynamic;
};
struct ut_M_Base_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth)(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic);
};
struct ut_M_Test {
  ut_M_Base b;
};
Returncode ut_M_Base_meth(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Test_test(ut_M_Test* self, Ref_Manager* self_Refman);
void ut_M_Test_Del(ut_M_Test* self);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_meth};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Base_meth(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->b_Refman);
}
Returncode ut_M_Test_test(ut_M_Test* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  ut_M_Base* b = NULL;
  Ref_Manager* b_Refman = NULL;
  ut_M_Base_Dynamic* b_Dynamic = NULL;
  ut_M_Base* b2 = NULL;
  Ref_Manager* b2_Refman = NULL;
  ut_M_Base_Dynamic* b2_Dynamic = NULL;
  ut_M_Test t_Var = {{0}};
  ut_M_Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(7, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(7, 38, "used member of outdated weak reference")
  b = &(self->b);
  b_Refman = self_Refman;
  LUMI_inc_ref(b_Refman);
  b_Dynamic = &ut_M_Base_dynamic;
  if (self == NULL) RAISE(8, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(8, 38, "used member of outdated weak reference")
  LUMI_dec_ref(b_Refman);
  b_Refman = self_Refman;
  LUMI_inc_ref(b_Refman);
  b_Dynamic = &ut_M_Base_dynamic;
  b = &(self->b);
  if (self == NULL) RAISE(9, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  CHECK(9, ut_M_Base_meth(&(self->b), self_Refman, &ut_M_Base_dynamic) )
  if (self == NULL) RAISE(10, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(10, 38, "used member of outdated weak reference")
  CHECK(10, ut_M_Base_meth(&(self->b), self_Refman, &ut_M_Base_dynamic) )
  if (self == NULL) RAISE(11, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(11, 38, "used member of outdated weak reference")
  b2 = self->b.b;
  b2_Refman = self->b.b_Refman;
  LUMI_inc_ref(b2_Refman);
  b2_Dynamic = self->b.b_Dynamic;
  if (self == NULL) RAISE(12, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(12, 38, "used member of outdated weak reference")
  LUMI_dec_ref(b2_Refman);
  b2_Refman = self->b.b_Refman;
  LUMI_inc_ref(b2_Refman);
  b2_Dynamic = self->b.b_Dynamic;
  b2 = self->b.b;
  if (self->b.b_Dynamic == NULL) RAISE(13, 28, "dynamic call of empty object")
  if (self == NULL) RAISE(13, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(13, 38, "used member of outdated weak reference")
  CHECK(13, self->b.b_Dynamic->meth(self->b.b, self->b.b_Refman, self->b.b_Dynamic) )
  if (self == NULL) RAISE(14, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(14, 38, "used member of outdated weak reference")
  CHECK(14, ut_M_Base_meth(self->b.b, self->b.b_Refman, self->b.b_Dynamic) )
  t = &t_Var;
  t_Refman = LUMI_new_ref(t);
  if (t_Refman == NULL) RAISE(15, 38, "insufficient memory for managed object")
LUMI_cleanup:
  LUMI_dec_ref(t_Refman);
  LUMI_dec_ref(b2_Refman);
  LUMI_dec_ref(b_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->b));
}
/// @ te0
cannot declared "var" field of sequence type "String"
/// @ te1
cannot declared "var" field of sequence type "Array"
/// @ te2
variable will cause recursive declaration of type "Test"
/// @ te3
variable will cause recursive declaration of type "Test"
/// @@ test-enum
/// @ t0
enum {
  ut_M_MyEnum_VALUE = 0,
  ut_M_MyEnum_ANOTHER_VALUE,
  ut_M_MyEnum_LAST_VALUE,
  ut_M_MyEnum_length
};
Returncode ut_M_dummy(void);
Returncode ut_M_dummy(void) {
  Returncode LUMI_err = OK;
  Int x = 0;
  x = ut_M_MyEnum_VALUE;
  x += ut_M_MyEnum_ANOTHER_VALUE;
  x -= ut_M_MyEnum_length;
LUMI_cleanup:
  return LUMI_err;
}
/// @ t1
enum {
  ut_M_MyEnum_VALUE = 0,
  ut_M_MyEnum_ANOTHER_VALUE,
  ut_M_MyEnum_LAST_VALUE,
  ut_M_MyEnum_length
};
Int ut_M_arr_Values[ut_M_MyEnum_length] = {0};
Array ut_M_arr_Var = {ut_M_MyEnum_length, NULL};
Array* ut_M_arr = NULL;
Ref_Manager* ut_M_arr_Refman = NULL;
/// @ te0
Enum "MyEnum" has no value "ERROR"
/// @ te1
unknown Enum "Error"
/// @ te2
unknown type "MyEnum"
/// @ te3
illegal Enum name "My-Enum"
/// @ te4
illegal constant name "Error"
/// @ te5
illegal constant name "ERRoR"
/// @ te6
expected space after "enum", got "new-line"
/// @ te7
expected new-line after Enum value, got "("
/// @ te8
Enum with no values
/// @ te9
indentation too long, expected 2 got 4
/// @ te10
redefinition of Enum "Error"
/// @ te11
Enum name overrides type "Error"
/// @ te12
type name overrides Enum "Error"
/// @@ test-constant
/// @ t0
enum { ut_M_NUMBER = 12 };
/// @ t1
enum { ut_M_SIZE = 12 };
Int ut_M_arr_Values[ut_M_SIZE + 3] = {0};
Array ut_M_arr_Var = {ut_M_SIZE + 3, NULL};
Array* ut_M_arr = NULL;
Ref_Manager* ut_M_arr_Refman = NULL;
/// @ t2
enum { ut_M_SMALL = 7 };
enum { ut_M_LARGE = (- (2 * ut_M_SMALL)) + 1 };
/// @ te0
expected space after "const", got "new-line"
/// @ te1
Only "Int" typed constant supported, got "Bool"
/// @ te2
expected space after "Int", got "new-line"
/// @ te3
illegal constant name "Error"
/// @ te4
expected space after constant name, got "new-line"
/// @ te5
got "Bool" expression, expected "Int"
/// @ te6
value is not constant
/// @ te7
recursive dependency in constant "ERROR"
/// @ te8
recursive dependency in constant "A-ERROR"
/// @ te9
assigning into non assignable expression
/// @ te10
non assignable call output
/// @@ test-module
/// @ t0
typedef struct ut_M_Test ut_M_Test;
typedef struct second_M_Test second_M_Test;
enum {
  ut_M_Enum_VALUE = 0,
  ut_M_Enum_length
};
enum {
  second_M_Enum_VALUE = 0,
  second_M_Enum_length
};
enum { ut_M_SIZE = 12 };
enum { second_M_SIZE = 12 };
struct ut_M_Test {
  Int x;
};
struct second_M_Test {
  ut_M_Test _base;
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode second_M_Test_meth(second_M_Test* self, Ref_Manager* self_Refman);
void second_M_Test_Del(second_M_Test* self);
Returncode ut_M_fun(void);
Returncode second_M_fun(void);
Returncode second_M_dummy(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Generic_Type_Dynamic second_M_Test_dynamic = {(Dynamic_Del)second_M_Test_Del};
ut_M_Test ut_M_t_Var = {0};
ut_M_Test* ut_M_t = NULL;
Ref_Manager* ut_M_t_Refman = NULL;
second_M_Test second_M_t_Var = {{0}};
second_M_Test* second_M_t = NULL;
Ref_Manager* second_M_t_Refman = NULL;
int LUMI_file0_line_count[17] = {
  -1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
  {"mock.4.lm", 17, LUMI_file0_line_count}
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
Returncode second_M_Test_meth(second_M_Test* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void second_M_Test_Del(second_M_Test* self) {
  if (self == NULL) return;
  ut_M_Test_Del(&(self->_base));
}
Returncode ut_M_fun(void) {
  Returncode LUMI_err = OK;
  second_M_Test* nt = NULL;
  Ref_Manager* nt_Refman = NULL;
  ++LUMI_file_coverage[0].line_count[9];
  if (ut_M_t == NULL) RAISE(9, 27, "used member of empty object")
  if (ut_M_t_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  ut_M_t->x = ut_M_Enum_VALUE + ut_M_SIZE;
  ++LUMI_file_coverage[0].line_count[10];
  CHECK(10, ut_M_fun() )
  ++LUMI_file_coverage[0].line_count[11];
  CHECK(11, ut_M_Test_meth(ut_M_t, ut_M_t_Refman) )
  ++LUMI_file_coverage[0].line_count[12];
  if (second_M_t == NULL) RAISE(12, 27, "used member of empty object")
  if (second_M_t_Refman->value == NULL) RAISE(12, 38, "used member of outdated weak reference")
  second_M_t->_base.x = second_M_Enum_VALUE + second_M_SIZE;
  ++LUMI_file_coverage[0].line_count[13];
  CHECK(13, second_M_fun() )
  ++LUMI_file_coverage[0].line_count[14];
  CHECK(14, second_M_Test_meth(second_M_t, second_M_t_Refman) )
  ++LUMI_file_coverage[0].line_count[15];
  nt = LUMI_alloc(sizeof(second_M_Test));
  if (nt == NULL) RAISE(15, 49, "insufficient memory for object dynamic allocation")
  nt_Refman = LUMI_new_ref(nt);
  if (nt_Refman == NULL) RAISE(15, 38, "insufficient memory for managed object")
LUMI_cleanup:
  second_M_Test_Del(nt);
  LUMI_owner_dec_ref(nt_Refman);
  return LUMI_err;
}
Returncode second_M_fun(void) {
  Returncode LUMI_err = OK;
  ut_M_Test* nt = NULL;
  Ref_Manager* nt_Refman = NULL;
  if (second_M_t == NULL) RAISE(9, 27, "used member of empty object")
  if (second_M_t_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  second_M_t->_base.x = second_M_Enum_VALUE + second_M_SIZE;
  CHECK(10, second_M_fun() )
  CHECK(11, second_M_Test_meth(second_M_t, second_M_t_Refman) )
  if (ut_M_t == NULL) RAISE(12, 27, "used member of empty object")
  if (ut_M_t_Refman->value == NULL) RAISE(12, 38, "used member of outdated weak reference")
  ut_M_t->x = ut_M_Enum_VALUE + ut_M_SIZE;
  CHECK(13, ut_M_fun() )
  CHECK(14, ut_M_Test_meth(ut_M_t, ut_M_t_Refman) )
  nt = LUMI_alloc(sizeof(ut_M_Test));
  if (nt == NULL) RAISE(15, 49, "insufficient memory for object dynamic allocation")
  nt_Refman = LUMI_new_ref(nt);
  if (nt_Refman == NULL) RAISE(15, 38, "insufficient memory for managed object")
LUMI_cleanup:
  ut_M_Test_Del(nt);
  LUMI_owner_dec_ref(nt_Refman);
  return LUMI_err;
}
Returncode second_M_dummy(void) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
  Bool LUMI_success = true;
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "mock.4.lm"
  ut_M_t = &ut_M_t_Var;
  ut_M_t_Refman = LUMI_new_ref(ut_M_t);
  if (ut_M_t_Refman == NULL) RAISE(7, 38, "insufficient memory for managed object")
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "second.4.lm"
  second_M_t = &second_M_t_Var;
  second_M_t_Refman = LUMI_new_ref(second_M_t);
  if (second_M_t_Refman == NULL) RAISE(7, 38, "insufficient memory for managed object")
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
  LUMI_success &= LUMI_run_test("dummy", second_M_dummy);
  LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
  return LUMI_success? OK : FAIL;
}
TEST_MAIN_FUNC
/// @ t1
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
  Int x;
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_fun(void);
Returncode ut_M_fun_Mock(void);
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman);
Returncode second_M_dummy(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
int LUMI_file0_line_count[8] = {
  -1,-1,-1,-1,-1, 0, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
  {"mock.4.lm", 8, LUMI_file0_line_count}
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  ++LUMI_file_coverage[0].line_count[5];
  CHECK(5, ut_M_fun_Mock() )
  ++LUMI_file_coverage[0].line_count[6];
  CHECK(6, ut_M_Test_meth_Mock(self, self_Refman) )
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
Returncode ut_M_fun(void) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
Bool ut_M_fun_Mock_active = true;
Returncode ut_M_fun_Mock(void) {
  Returncode LUMI_err = OK;
  if (!ut_M_fun_Mock_active) return ut_M_fun();
LUMI_cleanup:
  return LUMI_err;
}
Bool ut_M_Test_meth_Mock_active = true;
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (!ut_M_Test_meth_Mock_active) return ut_M_Test_meth(self, self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode second_M_dummy(void) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
  Bool LUMI_success = true;
  LUMI_success &= LUMI_run_test("dummy", second_M_dummy);
  LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
  return LUMI_success? OK : FAIL;
}
TEST_MAIN_FUNC
/// @ t2
typedef void* Native;
Returncode external(void);
Returncode ut_M_fun(void);
Returncode second_M_use(void);
extern Int x;
int LUMI_file0_line_count[7] = {
  -1,-1,-1,-1,-1, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
  {"mock.4.lm", 7, LUMI_file0_line_count}
};
Returncode ut_M_fun(void) {
  Returncode LUMI_err = OK;
  ++LUMI_file_coverage[0].line_count[5];
  x = 0;
LUMI_cleanup:
  return LUMI_err;
}
Returncode second_M_use(void) {
  Returncode LUMI_err = OK;
  Native n = 0;
  x = 2;
  CHECK(5, external() )
LUMI_cleanup:
  return LUMI_err;
}
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
  Bool LUMI_success = true;
  LUMI_success &= LUMI_run_test("use", second_M_use);
  LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
  return LUMI_success? OK : FAIL;
}
TEST_MAIN_FUNC
/// @ te0
unknown symbol "error" in module "ut"
/// @ te1
variable name overrides module "ut"
/// @ te2
function name overrides module "ut"
/// @ te3
unknown module "error"
/// @ te4
unknown type "Error" in module "ut"
/// @ te5
expected space after "module", got "("
/// @ te6
illegal module name "Error"
/// @ te7
module name overrides variable "true"
/// @ te8
module name overrides function "file-open-read"
/// @ te9
no "module" in file start
/// @ te10
expected module, got empty expression
/// @ te11
expected module, got "Int"
/// @ te12
unknown Enum "Error" in module "ut"
/// @
