/// @@ test-int-expression
/// @ t0
ut_M_i = 0;
/// @ t1
ut_M_i = 9630;
/// @ t2
ut_M_i = -9630;
/// @ t3
ut_M_i = 07520;
/// @ t4
ut_M_i = -07520;
/// @ t5
ut_M_i = 0xfda940;
/// @ t6
ut_M_i = -0xfda940;
/// @ t7
ut_M_i = 0xFDA940;
/// @ t8
ut_M_i = -0xFDA940;
/// @ te0
illegal number "2a"
/// @ te1
illegal number "0a"
/// @ te2
illegal octal number "038"
/// @ te3
illegal binary number "0b021"
/// @ te4
illegal hexadecimal number "0xadg"
/// @ te5
binary numbers not supported yet... "0b1001"
/// @@ test-char-expression
/// @ t0
ut_M_c = 'a';
/// @ t1
ut_M_c = '\'';
/// @ t2
ut_M_c = '\n';
/// @ t3
ut_M_c = '\x0f';
/// @ t4
ut_M_c = '\xA9';
/// @ t5
ut_M_c = '\270';
/// @ te0
illegal character constant "'''"
/// @ te1
illegal character constant "'\'"
/// @ te2
illegal character constant "'aa"
/// @ te3
illegal character constant "'\c'"
/// @ te4
illegal character constant "'aaaa'"
/// @ te5
illegal character constant "'\x6g'"
/// @ te6
illegal character constant "'\058'"
/// @ te7
illegal character constant "''"
/// @ te8
illegal character constant "'aa'"
/// @ te9
illegal character constant "'aaa'"
/// @ te10
illegal character constant "'aaaaa'"
/// @@ test-string-expression
/// @ t0
String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  INIT_STRING_CONST(1, aux_String_0, "some string");
  aux_Ref_Manager = ut_M_str_Refman;
  ut_M_str_Refman = aux_String_0_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_str = aux_String_0;
/// @ t1
String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  INIT_STRING_CONST(1, aux_String_0, "\nstring\t\"with\\formatting\n");
  aux_Ref_Manager = ut_M_str_Refman;
  ut_M_str_Refman = aux_String_0_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_str = aux_String_0;
/// @ t2
String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  INIT_STRING_CONST(4, aux_String_0, "linesplitstring");
  aux_Ref_Manager = ut_M_str_Refman;
  ut_M_str_Refman = aux_String_0_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_str = aux_String_0;
/// @ t3
String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  INIT_STRING_CONST(4, aux_String_0, "multi\nline\nstring\n");
  aux_Ref_Manager = ut_M_str_Refman;
  ut_M_str_Refman = aux_String_0_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_str = aux_String_0;
/// @ t4
String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  INIT_STRING_CONST(2, aux_String_0, "line split");
  aux_Ref_Manager = ut_M_str_Refman;
  ut_M_str_Refman = aux_String_0_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_str = aux_String_0;
/// @ te0
no '"' around string constant ""aaa"
/// @ te1
too short string constant """
/// @ te2
'"' inside string constant ""error"+"string""
/// @ te3
indentation too short, expected 6 got 4
/// @ te4
indentation too short, expected 6 got 4
/// @@ test-empty-expression
/// @ t0
Ref_Manager* aux_Ref_Manager = NULL;
  aux_Ref_Manager = ut_M_str_Refman;
  ut_M_str_Refman = NULL;
  LUMI_inc_ref(ut_M_str_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_str = NULL;
/// @ t1
Ref_Manager* aux_Ref_Manager = NULL;
  aux_Ref_Manager = ut_M_t_Refman;
  ut_M_t_Refman = NULL;
  LUMI_inc_ref(ut_M_t_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_t = NULL;
/// @ t2
String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = NULL;
  aux_String_0_Refman = NULL;
  String_Del(*so);
  LUMI_owner_dec_ref(*so_Refman);
  *so_Refman = aux_String_0_Refman;
  *so = aux_String_0;
  aux_String_0 = NULL;
  aux_String_0_Refman = NULL;
/// @ t3
ut_M_b = ((void*)ut_M_t == NULL) || ((void*)ut_M_ta != NULL);
/// @ te0
cannot assign "Empty Symbol" into "Int"
/// @@ test-member-expression
/// @ t0
CHECK_REF(1, ut_M_t, ut_M_t_Refman)
  ut_M_i = ut_M_t->num;
/// @ t1
CHECK_REF(1, ut_M_tc, ut_M_tc_Refman)
  ut_M_i = ut_M_tc->_base.numb;
/// @ t2
CHECK_REF(1, ut_M_tc, ut_M_tc_Refman)
  ut_M_i = ut_M_tc->_base._base._base.num;
/// @ t3
CHECK_REF(1, *to, (*to_Refman))
  ut_M_i = (*to)->num;
/// @ t4
CHECK_REF(1, *tco, (*tco_Refman))
  ut_M_i = (*tco)->_base._base._base.num;
/// @ t5
CHECK_REF(1, ut_M_t, ut_M_t_Refman)
  CHECK_REF(1, ut_M_t->t, ut_M_t->t_Refman)
  ut_M_i = ut_M_t->t->num;
/// @ t6
CHECK_REF(1, ut_M_t, ut_M_t_Refman)
  CHECK_REF(1, ut_M_t->t, ut_M_t->t_Refman)
  CHECK_REF(1, ut_M_t->t->t, ut_M_t->t->t_Refman)
  ut_M_i = ut_M_t->t->t->num;
/// @ te0
unknown symbol "error"
/// @ te1
void expression has no member "error"
/// @ te2
type "Test" has no member "error"
/// @ te3
type "Int" has no member "error"
/// @@ test-slice-expression
/// @ t0
CHECK_REF(1, ut_M_str, ut_M_str_Refman)
  if ((13) < 0 || (13) >= (ut_M_str)->length) RAISE(1, slice_index)
  ut_M_c = ((ut_M_str)->values)[13];
/// @ t1
String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  INIT_VAR(1, aux_String_0)
  aux_String_0_Var.length = 6;
  aux_String_0_Var.max_length = aux_String_0_Var.length + 1;
  aux_String_0_Var.values = (ut_M_str)->values + (2);
  CHECK_REF(1, ut_M_str, ut_M_str_Refman)
  if ((2) < 0 || (6) < 0 || (2) + (6) > (ut_M_str)->length) RAISE(1, slice_index)
  aux_Ref_Manager = ut_M_str_Refman;
  ut_M_str_Refman = ut_M_str_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_str = aux_String_0;
/// @ t2
CHECK_REF(1, ut_M_arr, ut_M_arr_Refman)
  if ((13) < 0 || (13) >= (ut_M_arr)->length) RAISE(1, slice_index)
  ut_M_i = ((Int*)((ut_M_arr)->values))[13];
/// @ t3
Array aux_Array_0_Var = {0};
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  INIT_VAR(1, aux_Array_0)
  aux_Array_0_Var.length = 6;
  aux_Array_0_Var.values = (Byte*)((ut_M_arr)->values) + (2);
  CHECK_REF(1, ut_M_arr, ut_M_arr_Refman)
  if ((2) < 0 || (6) < 0 || (2) + (6) > (ut_M_arr)->length) RAISE(1, slice_index)
  aux_Ref_Manager = ut_M_arr_Refman;
  ut_M_arr_Refman = ut_M_arr_Refman;
  LUMI_inc_ref(ut_M_arr_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_arr = aux_Array_0;
/// @ t4
CHECK_REF(1, ut_M_str, ut_M_str_Refman)
  if ((4) < 0 || (4) >= (ut_M_str)->length) RAISE(1, slice_index)
  ((ut_M_str)->values)[4] = ut_M_c;
/// @ t5
CHECK_REF(1, ut_M_arr, ut_M_arr_Refman)
  if ((4) < 0 || (4) >= (ut_M_arr)->length) RAISE(1, slice_index)
  ((Int*)((ut_M_arr)->values))[4] = ut_M_i;
/// @ t6
expected "]", got "new-line"
/// @ t7
expected "]", got "new-line"
/// @ t8
cannot slice a void expression
/// @ t9
cannot slice type "Int"
/// @ t10
expected integer index for slice, got "String"
/// @ t11
expected integer index for slice, got "String"
/// @ t12
expected integer index for slice, got void expression
/// @ t13
assigning into non assignable expression
/// @ t14
assigning into non assignable expression
/// @ t15
assigning into non assignable expression
/// @@ test-call-expression
/// @ t0
LUMI_err = ut_M_fun0();
  CHECK(1)
/// @ t1
LUMI_err = ut_M_fun1(3, ut_M_str, ut_M_str_Refman, NULL, NULL);
  CHECK(1)
/// @ t2
LUMI_err = ut_M_fun2(&(*so), &(*so_Refman), &(*io));
  CHECK(1)
/// @ t3
Int x = 0;
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  LUMI_err = ut_M_fun2(&(s), &(s_Refman), &(x));
  CHECK(3)
/// @ t4
LUMI_err = ut_M_fun3(0, &(*so), &(*so_Refman));
  CHECK(1)
/// @ t5
Int x = 0;
  LUMI_err = ut_M_fun5(3, &(x));
  CHECK(2)
  LUMI_err = ut_M_fun4(x);
  CHECK(2)
/// @ t6
LUMI_err = ut_M_fun6(2, 3, &(*io), &(*io));
  CHECK(1)
/// @ t7
Int aux_Int_0 = 0;
  LUMI_err = ut_M_fun5(4, &(aux_Int_0));
  CHECK(1)
/// @ t8
Int aux_Int_0 = 0;
  LUMI_err = ut_M_fun5(4, &(aux_Int_0));
  CHECK(1)
  *io = aux_Int_0;
/// @ t9
String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  LUMI_err = ut_M_fun3(7, &(aux_String_0), &(aux_String_0_Refman));
  CHECK(1)
  aux_String_1 = aux_String_0;
  aux_String_1_Refman = aux_String_0_Refman;
  aux_String_0 = NULL;
  aux_String_0_Refman = NULL;
  String_Del(*so);
  LUMI_owner_dec_ref(*so_Refman);
  *so_Refman = aux_String_1_Refman;
  *so = aux_String_1;
  aux_String_1 = NULL;
  aux_String_1_Refman = NULL;
/// @ t10
LUMI_err = ut_M_Test_meth(ut_M_t, ut_M_t_Refman);
  CHECK(1)
/// @ t11
LUMI_err = ut_M_Test_meth(*to, *to_Refman);
  CHECK(1)
/// @ t12
LUMI_err = ut_M_Tc_methc(ut_M_tc, ut_M_tc_Refman, ut_M_tc_Dynamic);
  CHECK(1)
/// @ t13
LUMI_err = ut_M_Tb_methb(&(ut_M_tc->_base), ut_M_tc_Refman, &(ut_M_tc_Dynamic->_base));
  CHECK(1)
/// @ t14
LUMI_err = ut_M_Test_meth(&(ut_M_tc->_base._base._base), ut_M_tc_Refman);
  CHECK(1)
/// @ t15
LUMI_err = ut_M_Test_meth(&((*tco)->_base._base._base), *tco_Refman);
  CHECK(1)
/// @ t16
CHECK_REF(1, ut_M_t, ut_M_t_Refman)
  LUMI_err = ut_M_Test_meth(ut_M_t->t, ut_M_t->t_Refman);
  CHECK(1)
/// @ t17
LUMI_err = ut_M_fun1(3, ut_M_str, ut_M_str_Refman, *so, *so_Refman);
  *so = NULL;
  *so_Refman = NULL;
  CHECK(1)
/// @ t18
String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  Int aux_Int_0 = 0;
  LUMI_err = ut_M_fun3(1, &(aux_String_0), &(aux_String_0_Refman));
  CHECK(1)
  LUMI_err = ut_M_fun5(2, &(aux_Int_0));
  CHECK(2)
/// @ t19
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Base {
  Int x;
};
struct ut_M_Base_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth)(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, ut_M_Base* b, Ref_Manager* b_Refman, ut_M_Base_Dynamic* b_Dynamic);
};
struct ut_M_Test {
  ut_M_Base _base;
};
struct ut_M_Test_Dynamic {
  ut_M_Base_Dynamic _base;
};
Returncode ut_M_Base_meth(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, ut_M_Base* b, Ref_Manager* b_Refman, ut_M_Base_Dynamic* b_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, ut_M_Test* t, Ref_Manager* t_Refman, ut_M_Test_Dynamic* t_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_meth};
ut_M_Test_Dynamic ut_M_Test_dynamic = {{(Dynamic_Del)ut_M_Test_Del, (Func)ut_M_Test_meth}};
Returncode ut_M_Base_meth(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, ut_M_Base* b, Ref_Manager* b_Refman, ut_M_Base_Dynamic* b_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  if (b_Dynamic != NULL) b_Dynamic->_del(b);
  LUMI_owner_dec_ref(b_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
}
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, ut_M_Test* t, Ref_Manager* t_Refman, ut_M_Test_Dynamic* t_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_err = ut_M_Base_meth(&(self->_base), self_Refman, &(self_Dynamic->_base), &(t->_base), t_Refman, &(t_Dynamic->_base));
  t = NULL;
  t_Refman = NULL;
  t_Dynamic = NULL;
  CHECK(6)
LUMI_cleanup:
  if (t_Dynamic != NULL) t_Dynamic->_base._del(t);
  LUMI_owner_dec_ref(t_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->_base));
}
/// @ t20
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
Returncode ut_M_mock(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic);
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
Returncode ut_M_mock(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_err = ut_M_mock(&(*t), &(*t_Refman), &(*t_Dynamic));
  CHECK(5)
  if (*t_Dynamic == NULL) RAISE(5, empty_object)
  LUMI_err = (*t_Dynamic)->meth(*t, *t_Refman, *t_Dynamic);
  CHECK(5)
LUMI_cleanup:
  return LUMI_err;
}
/// @ t21
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
  Int x;
};
struct ut_M_Test_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth)(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic);
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic) {
  Returncode LUMI_err = OK;
  ut_M_Test* aux_Test_0 = NULL;
  Ref_Manager* aux_Test_0_Refman = NULL;
  ut_M_Test_Dynamic* aux_Test_0_Dynamic = NULL;
  ut_M_Test* aux_Test_1 = NULL;
  Ref_Manager* aux_Test_1_Refman = NULL;
  ut_M_Test_Dynamic* aux_Test_1_Dynamic = NULL;
  LUMI_inc_ref(self_Refman);
  if (self_Dynamic == NULL) RAISE(4, empty_object)
  LUMI_err = self_Dynamic->meth(self, self_Refman, self_Dynamic, &(aux_Test_0), &(aux_Test_0_Refman), &(aux_Test_0_Dynamic));
  CHECK(4)
  if (aux_Test_0_Dynamic == NULL) RAISE(4, empty_object)
  LUMI_err = aux_Test_0_Dynamic->meth(aux_Test_0, aux_Test_0_Refman, aux_Test_0_Dynamic, &(aux_Test_1), &(aux_Test_1_Refman), &(aux_Test_1_Dynamic));
  CHECK(4)
LUMI_cleanup:
  LUMI_dec_ref(aux_Test_1_Refman);
  LUMI_dec_ref(aux_Test_0_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
}
/// @ te0
expected access, got " "
/// @ te1
expected space after access, got ")"
/// @ te2
expected space or new-line after ",", got "c"
/// @ te3
expected "," or ")", got "new-line"
/// @ te4
illegal access "error"
/// @ te5
void expression is not callable
/// @ te6
non callable type "Int"
/// @ te7
non assignable call output
/// @ te8
cannot assign "Tb" into "Tc"
/// @ te9
cannot assign void expression
/// @ te10
expected access "copy" , got "user"
/// @ te11
assigning into an owner a non-owner access "user"
/// @ te12
assigning into an owner a non-owner access "user"
/// @ te13
assigning into access "user" invalid access "owner"
/// @ te14
too many parameters
/// @ te15
too few parameters
/// @ te16
too many outputs
/// @ te17
too few outputs
/// @ te18
passing ownership of type "Test" into static type "Base"
/// @ te19
assigning into an owner a non-owner access "var"
/// @@ test-type-expression
/// @ t0
LUMI_err = ut_M_Test_meth(ut_M_t, ut_M_t_Refman);
  CHECK(1)
/// @ t1
LUMI_err = ut_M_Tb_methb(&(ut_M_tc->_base), ut_M_tc_Refman, &(ut_M_tc_Dynamic->_base));
  CHECK(1)
/// @ t2
LUMI_err = ut_M_Test_meth(&(ut_M_tc->_base._base._base), ut_M_tc_Refman);
  CHECK(1)
/// @ t3
unknown type "Error"
/// @@ test-base-expression
/// @ t0
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Top ut_M_Top;
struct ut_M_Base {
  Int x;
};
struct ut_M_Mid {
  ut_M_Base _base;
};
struct ut_M_Top {
  ut_M_Mid _base;
};
Returncode ut_M_Base_methb(ut_M_Base* self, Ref_Manager* self_Refman);
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Mid_methm(ut_M_Mid* self, Ref_Manager* self_Refman);
void ut_M_Mid_Del(ut_M_Mid* self);
Returncode ut_M_Top_methb(ut_M_Top* self, Ref_Manager* self_Refman);
Returncode ut_M_Top_methm(ut_M_Top* self, Ref_Manager* self_Refman);
void ut_M_Top_Del(ut_M_Top* self);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Top_dynamic = {(Dynamic_Del)ut_M_Top_Del};
Returncode ut_M_Base_methb(ut_M_Base* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
}
Returncode ut_M_Mid_methm(ut_M_Mid* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Mid_Del(ut_M_Mid* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_Top_methb(ut_M_Top* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_Top_methm(ut_M_Top* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_err = ut_M_Mid_methm(&(self->_base), self_Refman);
  CHECK(9)
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Top_Del(ut_M_Top* self) {
  if (self == NULL) return;
  ut_M_Mid_Del(&(self->_base));
}
/// @ t1
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Top ut_M_Top;
struct ut_M_Base {
  Int x;
};
struct ut_M_Mid {
  ut_M_Base _base;
};
struct ut_M_Top {
  ut_M_Mid _base;
};
Returncode ut_M_Base_methb(ut_M_Base* self, Ref_Manager* self_Refman);
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Mid_methm(ut_M_Mid* self, Ref_Manager* self_Refman);
void ut_M_Mid_Del(ut_M_Mid* self);
Returncode ut_M_Top_methb(ut_M_Top* self, Ref_Manager* self_Refman);
Returncode ut_M_Top_methm(ut_M_Top* self, Ref_Manager* self_Refman);
void ut_M_Top_Del(ut_M_Top* self);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Top_dynamic = {(Dynamic_Del)ut_M_Top_Del};
Returncode ut_M_Base_methb(ut_M_Base* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
}
Returncode ut_M_Mid_methm(ut_M_Mid* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Mid_Del(ut_M_Mid* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_Top_methb(ut_M_Top* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_Top_methm(ut_M_Top* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_err = ut_M_Base_methb(&(self->_base._base), self_Refman);
  CHECK(9)
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Top_Del(ut_M_Top* self) {
  if (self == NULL) return;
  ut_M_Mid_Del(&(self->_base));
}
/// @ te0
"base" used not in method
/// @ te1
no base type for type "Test"
/// @ te2
no base method for method "mock"
/// @ te3
cannot assign "Test" into "Base Symbol"
/// @ te4
calling "base" with non-method "x"
/// @@ test-block-expression
/// @ t0
ut_M_i = 2 + (123);
/// @ t1
ut_M_i = 123;
/// @ t2
ut_M_i = (123 * (ut_M_i - 4)) + 2;
/// @ t3
expected ")", got "new-line"
/// @@ test-unary-expression
/// @ t0
ut_M_i = - ut_M_i;
/// @ t1
ut_M_i = - ut_M_i;
/// @ t2
ut_M_i = - (- ut_M_i);
/// @ t3
ut_M_b = ! ut_M_b;
/// @ t4
ut_M_b = ! (ut_M_i > 3);
/// @ t5
unexpected "{"
/// @ t6
expected space after operator, got "["
/// @ t7
not unary operator "+"
/// @ t8
void expression given as operand to operator "-"
/// @ t9
operator "-" expected "Int" operand, got "Bool"
/// @ t10
operator "not" expected "Bool" operand, got "Int"
/// @@ test-binary-expression
/// @ t0
ut_M_i = 23 + 54;
/// @ t1
ut_M_i += (100 * 2) - ((37 / 5) % 2);
/// @ t2
ut_M_i -= 12 * 13;
/// @ t3
ut_M_b = (3 < 5) || (23 > 37);
/// @ t4
ut_M_b = (3 <= 5) && (23 >= 37);
/// @ t5
ut_M_b = (ut_M_i == 5) || (ut_M_i != 37);
/// @ t6
ut_M_b = ((2 < ut_M_i) && (ut_M_i < 12)) && (12 < (2 * ut_M_i));
/// @ t7
Ref_Manager* aux_Ref_Manager = NULL;
  aux_Ref_Manager = ut_M_t_Refman;
  ut_M_t_Refman = ut_M_tc_Refman;
  LUMI_inc_ref(ut_M_t_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_t = &(ut_M_tc->_base._base._base);
/// @ t8
String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = *so;
  aux_String_0_Refman = *so_Refman;
  *so = NULL;
  *so_Refman = NULL;
  String_Del(s);
  LUMI_owner_dec_ref(s_Refman);
  s_Refman = aux_String_0_Refman;
  s = aux_String_0;
  aux_String_0 = NULL;
  aux_String_0_Refman = NULL;
/// @ t9
Ref_Manager* aux_Ref_Manager = NULL;
  aux_Ref_Manager = ut_M_str_Refman;
  ut_M_str_Refman = *so_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_str = *so;
/// @ t10
ut_M_b = ((void*)ut_M_t == ut_M_ta) || ((void*)ut_M_tc != ut_M_tb);
/// @ t11
ut_M_c = '0' + 4;
/// @ t12
ut_M_b = (void*)ut_M_fun0 != ut_M_fun1;
/// @ t13
ut_M_b = ut_M_b == ut_M_b;
/// @ t14
ut_M_Tc* otc = NULL;
  Ref_Manager* otc_Refman = NULL;
  ut_M_Tc_Dynamic* otc_Dynamic = NULL;
  ut_M_Tb* aux_Tb_0 = NULL;
  Ref_Manager* aux_Tb_0_Refman = NULL;
  ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = NULL;
  aux_Tb_0 = &(otc->_base);
  aux_Tb_0_Refman = otc_Refman;
  aux_Tb_0_Dynamic = &(otc_Dynamic->_base);
  otc = NULL;
  otc_Refman = NULL;
  otc_Dynamic = NULL;
  if (ut_M_tb_Dynamic != NULL) ut_M_tb_Dynamic->_base._del(ut_M_tb);
  LUMI_owner_dec_ref(ut_M_tb_Refman);
  ut_M_tb_Refman = aux_Tb_0_Refman;
  ut_M_tb_Dynamic = aux_Tb_0_Dynamic;
  ut_M_tb = aux_Tb_0;
  aux_Tb_0 = NULL;
  aux_Tb_0_Refman = NULL;
  aux_Tb_0_Dynamic = NULL;
/// @ t15
Array* tarr = NULL;
  Ref_Manager* tarr_Refman = NULL;
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  aux_Array_0 = NULL;
  aux_Array_0_Refman = NULL;
  ARRAY_DEL(ut_M_Test, tarr)
  LUMI_owner_dec_ref(tarr_Refman);
  tarr_Refman = aux_Array_0_Refman;
  tarr = aux_Array_0;
  aux_Array_0 = NULL;
  aux_Array_0_Refman = NULL;
/// @ te0
unknown operator "@"
/// @ te1
expected space after operator, got "("
/// @ te2
ambiguous precedence between operators "+" and "*"
/// @ te3
ambiguous precedence between operators "or" and "and"
/// @ te4
cannot use "not" as binary operand
/// @ te5
assigning into non assignable expression
/// @ te6
assigning into non assignable expression
/// @ te7
assigning into non assignable expression
/// @ te8
assigning into an owner a non-owner access "user"
/// @ te9
operator "or" expected "Bool" operand, got "Int"
/// @ te10
operator ">" expected "Int" operand, got "Test"
/// @ te11
operator ">" expected "Int" operand, got "Test"
/// @ te12
operator "+" expected "Int" operand, got "Test"
/// @ te13
operator "+=" expected "Int" operand, got "Test"
/// @ te14
operator "-=" expected "Int" operand, got "Bool"
/// @ te15
operator "is" is not supported for type "Int"
/// @ te16
non matching subtypes "Int" and "Char"
/// @ te17
passing ownership of type "Tb" into static type "Test"
/// @ te18
operator "is" is not supported for type "Bool"
/// @@ test-question-expression
/// @ t0
ut_M_b = ut_M_str != NULL && ut_M_str_Refman->value != NULL;
/// @ t1
ut_M_b = ! (ut_M_str != NULL && ut_M_str_Refman->value != NULL);
/// @ t2
CHECK_REF(1, ut_M_t, ut_M_t_Refman)
  ut_M_b = ut_M_t->fun != NULL;
/// @ t3
ut_M_b = (*to) != NULL && (*to_Refman)->value != NULL;
/// @ t4
if (*to != NULL) RAISE(1, empty_base_output)
  LUMI_err = ut_M_fun7(NULL, NULL, NULL, (void*)&(*to), &(*to_Refman), (void*)&(*to_Dynamic));
  CHECK(1)
  ut_M_b = (*to) != NULL && (*to_Refman)->value != NULL;
/// @ te0
cannot use "?" on void expression
/// @ te1
cannot use "?" on type "Int"
/// @@ test-dynamic
/// @ t0
ut_M_Ta a_Var = {{0}};
  ut_M_Ta* a = NULL;
  Ref_Manager* a_Refman = NULL;
  ut_M_Ta_Dynamic* a_Dynamic = &ut_M_Ta_dynamic;
  INIT_VAR(1, a)
  LUMI_err = ut_M_Test_new(&(a->_base), a_Refman, 1);
  CHECK(1)
/// @ t1
ut_M_Ta* a = NULL;
  Ref_Manager* a_Refman = NULL;
  ut_M_Ta_Dynamic* a_Dynamic = NULL;
/// @ t2
ut_M_Ta* aux_Ta_0 = NULL;
  Ref_Manager* aux_Ta_0_Refman = NULL;
  ut_M_Ta_Dynamic* aux_Ta_0_Dynamic = &ut_M_Ta_dynamic;
  Ref_Manager* aux_Ref_Manager = NULL;
  INIT_NEW(1, aux_Ta_0, LUMI_alloc(sizeof(ut_M_Ta)));
  LUMI_err = ut_M_Test_new(&(aux_Ta_0->_base), aux_Ta_0_Refman, 7);
  CHECK(1)
  aux_Ref_Manager = ut_M_ta_Refman;
  ut_M_ta_Refman = aux_Ta_0_Refman;
  ut_M_ta_Dynamic = aux_Ta_0_Dynamic;
  LUMI_inc_ref(ut_M_ta_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_ta = aux_Ta_0;
/// @ t3
ut_M_Ta* a = NULL;
  Ref_Manager* a_Refman = NULL;
  ut_M_Ta_Dynamic* a_Dynamic = &ut_M_Ta_dynamic;
  INIT_NEW(1, a, LUMI_alloc(sizeof(ut_M_Ta)));
  LUMI_err = ut_M_Test_new(&(a->_base), a_Refman, 1);
  CHECK(1)
/// @ t4
ut_M_Ta* a = NULL;
  Ref_Manager* a_Refman = NULL;
  ut_M_Ta_Dynamic* a_Dynamic = NULL;
  a = ut_M_ta;
  a_Refman = ut_M_ta_Refman;
  LUMI_inc_ref(a_Refman);
  a_Dynamic = ut_M_ta_Dynamic;
/// @ t5
Ref_Manager* aux_Ref_Manager = NULL;
  aux_Ref_Manager = ut_M_ta_Refman;
  ut_M_ta_Refman = ut_M_ta_Refman;
  ut_M_ta_Dynamic = ut_M_ta_Dynamic;
  LUMI_inc_ref(ut_M_ta_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_ta = ut_M_ta;
/// @ t6
Ref_Manager* aux_Ref_Manager = NULL;
  aux_Ref_Manager = ut_M_ta_Refman;
  ut_M_ta_Refman = ut_M_tb_Refman;
  ut_M_ta_Dynamic = &(ut_M_tb_Dynamic->_base);
  LUMI_inc_ref(ut_M_ta_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_ta = &(ut_M_tb->_base);
/// @ t7
Ref_Manager* aux_Ref_Manager = NULL;
  aux_Ref_Manager = ut_M_ta_Refman;
  ut_M_ta_Refman = ut_M_tc_Refman;
  ut_M_ta_Dynamic = &(ut_M_tc_Dynamic->_base._base);
  LUMI_inc_ref(ut_M_ta_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_ta = &(ut_M_tc->_base._base);
/// @ t8
Ref_Manager* aux_Ref_Manager = NULL;
  aux_Ref_Manager = ut_M_ta_Refman;
  ut_M_ta_Refman = NULL;
  ut_M_ta_Dynamic = NULL;
  LUMI_inc_ref(ut_M_ta_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_ta = NULL;
/// @ t9
Array* aa = NULL;
  Ref_Manager* aa_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  CHECK_REF(2, aa, aa_Refman)
  if ((4) < 0 || (4) >= (aa)->length) RAISE(2, slice_index)
  aux_Ref_Manager = ut_M_ta_Refman;
  ut_M_ta_Refman = aa_Refman;
  ut_M_ta_Dynamic = &ut_M_Ta_dynamic;
  LUMI_inc_ref(ut_M_ta_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_ta = ((ut_M_Ta*)((aa)->values)) + 4;
/// @ t10
Array* ca = NULL;
  Ref_Manager* ca_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  CHECK_REF(2, ca, ca_Refman)
  if ((4) < 0 || (4) >= (ca)->length) RAISE(2, slice_index)
  aux_Ref_Manager = ut_M_ta_Refman;
  ut_M_ta_Refman = ca_Refman;
  ut_M_ta_Dynamic = &(&ut_M_Tc_dynamic->_base._base);
  LUMI_inc_ref(ut_M_ta_Refman);
  LUMI_dec_ref(aux_Ref_Manager);
  aux_Ref_Manager = NULL;
  ut_M_ta = &((((ut_M_Tc*)((ca)->values)) + 4)->_base._base);
/// @ t11
if (ut_M_ta_Dynamic == NULL) RAISE(1, empty_object)
  LUMI_err = ut_M_ta_Dynamic->dyn(ut_M_ta, ut_M_ta_Refman, ut_M_ta_Dynamic);
  CHECK(1)
/// @ t12
if (ut_M_tb_Dynamic == NULL) RAISE(1, empty_object)
  LUMI_err = ut_M_tb_Dynamic->_base.dyn(&(ut_M_tb->_base), ut_M_tb_Refman, &(ut_M_tb_Dynamic->_base));
  CHECK(1)
/// @ t13
if (ut_M_tc_Dynamic == NULL) RAISE(1, empty_object)
  LUMI_err = ut_M_tc_Dynamic->_base._base.dyn(&(ut_M_tc->_base._base), ut_M_tc_Refman, &(ut_M_tc_Dynamic->_base._base));
  CHECK(1)
/// @ t14
if (*tco_Dynamic == NULL) RAISE(1, empty_object)
  LUMI_err = (*tco_Dynamic)->_base._base.dyn(&((*tco)->_base._base), *tco_Refman, &((*tco_Dynamic)->_base._base));
  CHECK(1)
/// @ t15
if (ut_M_ta != NULL) RAISE(1, empty_base_output)
  LUMI_err = ut_M_fun7(&(ut_M_tc->_base), ut_M_tc_Refman, &(ut_M_tc_Dynamic->_base), (void*)&(ut_M_ta), &(ut_M_ta_Refman), (void*)&(ut_M_ta_Dynamic));
  CHECK(1)
/// @ t16
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
Returncode ut_M_mock(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic);
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
Returncode ut_M_mock(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic) {
  Returncode LUMI_err = OK;
  if (*t_Dynamic == NULL) RAISE(5, empty_object)
  LUMI_err = (*t_Dynamic)->meth(*t, *t_Refman, *t_Dynamic);
  CHECK(5)
LUMI_cleanup:
  return LUMI_err;
}
/// @ t17
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Base {
  Int x;
};
struct ut_M_Base_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth)(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic);
};
struct ut_M_Test {
  ut_M_Base _base;
};
struct ut_M_Test_Dynamic {
  ut_M_Base_Dynamic _base;
};
Returncode ut_M_Base_meth(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Test_fun(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_meth};
ut_M_Test_Dynamic ut_M_Test_dynamic = {{(Dynamic_Del)ut_M_Test_Del, ut_M_Base_meth}};
Returncode ut_M_Base_meth(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
  if (self == NULL) return;
}
Returncode ut_M_Test_fun(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  if (self_Dynamic == NULL) RAISE(6, empty_object)
  LUMI_err = self_Dynamic->_base.meth(&(self->_base), self_Refman, &(self_Dynamic->_base));
  CHECK(6)
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  ut_M_Base_Del(&(self->_base));
}
/// @ t18
ut_M_Tb* aux_Tb_0 = NULL;
  Ref_Manager* aux_Tb_0_Refman = NULL;
  ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = NULL;
  LUMI_err = ut_M_fun7(NULL, NULL, NULL, &(aux_Tb_0), &(aux_Tb_0_Refman), &(aux_Tb_0_Dynamic));
  CHECK(1)
/// @@ test-function-object
/// @ t0
Returncode (*fun)(void) = NULL;
  fun = ut_M_fun0;
  if (fun == NULL) RAISE(3, empty_object)
  LUMI_err = fun();
  CHECK(3)
/// @ t1
Returncode (*fun)(Int x, Int* y) = NULL;
  Int x = 0;
  fun = ut_M_fun5;
  if (fun == NULL) RAISE(3, empty_object)
  LUMI_err = fun(9, &(x));
  CHECK(3)
/// @ t2
Returncode (*fun)(ut_M_Test* self, Ref_Manager* self_Refman) = NULL;
  fun = ut_M_Test_meth;
  if (fun == NULL) RAISE(2, empty_object)
  LUMI_err = fun(ut_M_t, ut_M_t_Refman);
  CHECK(2)
/// @ t3
Returncode (*fun)(void) = NULL;
  fun = NULL;
  ut_M_b = fun != NULL;
/// @ t4
CHECK_REF(1, ut_M_t, ut_M_t_Refman)
  ut_M_t->fun = ut_M_fun0;
  CHECK_REF(2, ut_M_t, ut_M_t_Refman)
  if (ut_M_t->fun == NULL) RAISE(2, empty_object)
  LUMI_err = ut_M_t->fun();
  CHECK(2)
/// @ t5
Returncode (*farr_Values[38])(void) = {0};
  Array farr_Var = {38, NULL};
  Array* farr = NULL;
  Ref_Manager* farr_Refman = NULL;
  INIT_VAR(1, farr)
  farr_Var.values = farr_Values;
  CHECK_REF(2, farr, farr_Refman)
  if ((3) < 0 || (3) >= (farr)->length) RAISE(2, slice_index)
  ((Returncode (**)(void))((farr)->values))[3] = ut_M_fun0;
  CHECK_REF(3, farr, farr_Refman)
  if ((3) < 0 || (3) >= (farr)->length) RAISE(3, slice_index)
  if (((Returncode (**)(void))((farr)->values))[3] == NULL) RAISE(3, empty_object)
  LUMI_err = (((Returncode (**)(void))((farr)->values))[3])();
  CHECK(3)
/// @ t6
Returncode (*fun)(Int x, Int y) = NULL;
/// @ te0
missing arguments in function type
/// @ te1
missing arguments in function type
/// @ te2
expected "(" inside Function type, got "}"
/// @ te3
expected "}" after sub-types, got " "
/// @ te4
too many parameters
/// @ te5
too few outputs
/// @@ test-builtin
/// @ t0
LUMI_err = Int_str(ut_M_i, ut_M_str, ut_M_str_Refman);
  CHECK(1)
/// @ t1
ut_M_b = true;
/// @ t2
ut_M_b = false;
/// @ t3
unknown symbol "EOF"
/// @ t4
CHECK_REF(1, ut_M_arr, ut_M_arr_Refman)
  ut_M_i = ut_M_arr->length;
/// @ t5
CHECK_REF(1, ut_M_str, ut_M_str_Refman)
  ut_M_i = ut_M_str->length;
/// @ t6
LUMI_err = String_clear(ut_M_str, ut_M_str_Refman);
  CHECK(1)
/// @ t7
LUMI_err = String_equal(ut_M_str, ut_M_str_Refman, ut_M_str, ut_M_str_Refman, &(ut_M_b));
  CHECK(1)
/// @ t8
LUMI_err = String_get(ut_M_str, ut_M_str_Refman, ut_M_i, &(ut_M_c));
  CHECK(1)
/// @ t9
LUMI_err = String_append(ut_M_str, ut_M_str_Refman, ut_M_c);
  CHECK(1)
/// @ t10
LUMI_err = String_new(ut_M_str, ut_M_str_Refman, ut_M_str, ut_M_str_Refman);
  CHECK(1)
/// @ t11
LUMI_err = String_concat(ut_M_str, ut_M_str_Refman, ut_M_str, ut_M_str_Refman);
  CHECK(1)
/// @ t12
LUMI_err = String_concat_int(ut_M_str, ut_M_str_Refman, ut_M_i);
  CHECK(1)
/// @ t13
LUMI_err = String_find(ut_M_str, ut_M_str_Refman, ut_M_str, ut_M_str_Refman, &(ut_M_i));
  CHECK(1)
/// @ t14
LUMI_err = String_has(ut_M_str, ut_M_str_Refman, ut_M_c, &(ut_M_b));
  CHECK(1)
/// @ t15
LUMI_err = file_open_read(ut_M_str, ut_M_str_Refman, &(ut_M_fobj), &(ut_M_fobj_Refman));
  CHECK(1)
/// @ t16
LUMI_err = file_open_write(ut_M_str, ut_M_str_Refman, &(ut_M_fobj), &(ut_M_fobj_Refman));
  CHECK(1)
/// @ t17
LUMI_err = file_close(ut_M_fobj, ut_M_fobj_Refman);
  ut_M_fobj = NULL;
  ut_M_fobj_Refman = NULL;
  CHECK(1)
/// @ t18
LUMI_err = File_getc(ut_M_fobj, ut_M_fobj_Refman, &(ut_M_c), &(ut_M_b));
  CHECK(1)
/// @ t19
LUMI_err = File_putc(ut_M_fobj, ut_M_fobj_Refman, ut_M_c);
  CHECK(1)
/// @ t20
LUMI_err = File_write(ut_M_fobj, ut_M_fobj_Refman, ut_M_str, ut_M_str_Refman);
  CHECK(1)
/// @ t21
Array* argv = NULL;
  Ref_Manager* argv_Refman = NULL;
  CHECK_REF(1, sys, sys_Refman)
  argv = sys->argv;
  argv_Refman = sys->argv_Refman;
  LUMI_inc_ref(argv_Refman);
/// @ t22
LUMI_err = Sys_print(sys, sys_Refman, ut_M_str, ut_M_str_Refman);
  CHECK(1)
/// @ t23
LUMI_err = Sys_println(sys, sys_Refman, ut_M_str, ut_M_str_Refman);
  CHECK(1)
/// @ t24
LUMI_err = Sys_getchar(sys, sys_Refman, &(ut_M_c), &(ut_M_b));
  CHECK(1)
/// @ t25
LUMI_err = Sys_getline(sys, sys_Refman, ut_M_str, ut_M_str_Refman);
  CHECK(1)
/// @ t26
LUMI_err = Sys_exit(sys, sys_Refman, ut_M_i);
  CHECK(1)
/// @ t27
LUMI_err = Sys_system(sys, sys_Refman, ut_M_str, ut_M_str_Refman, &(ut_M_i));
  CHECK(1)
/// @ t28
LUMI_err = Sys_getenv(sys, sys_Refman, ut_M_str, ut_M_str_Refman, ut_M_str, ut_M_str_Refman, &(ut_M_b));
  CHECK(1)
/// @ t29
CHECK_REF(1, sys, sys_Refman)
  LUMI_err = File_putc(sys->stdout_Cname, sys->stdout_Cname_Refman, ut_M_c);
  CHECK(1)
/// @ t30
CHECK_REF(1, sys, sys_Refman)
  LUMI_err = File_getc(sys->stdin_Cname, sys->stdin_Cname_Refman, &(ut_M_c), &(ut_M_b));
  CHECK(1)
/// @ t31
CHECK_REF(1, sys, sys_Refman)
  LUMI_err = File_putc(sys->stderr_Cname, sys->stderr_Cname_Refman, ut_M_c);
  CHECK(1)
/// @ t32
LUMI_err = String_clear(ut_M_str, ut_M_str_Refman);
  CHECK(1)
/// @ te0
cannot create objects with type "File"
/// @ te1
cannot create objects with type "File"
/// @ te2
cannot create objects with type "File"
/// @ te3
cannot create objects with type "Sys"
/// @ te4
cannot create objects with type "Sys"
/// @ te5
cannot create objects with type "Sys"
/// @
