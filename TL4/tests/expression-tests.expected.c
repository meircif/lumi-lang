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
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  LUMI_dec_ref(ut_M_str_Refman);
  ut_M_str_Refman = aux_String_0_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  ut_M_str = aux_String_0;
/// @ t1
String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 26;
  aux_String_0_Var.length = 25;
  aux_String_0_Var.values = "\nstring\t\"with\\formatting\n";
  LUMI_dec_ref(ut_M_str_Refman);
  ut_M_str_Refman = aux_String_0_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  ut_M_str = aux_String_0;
/// @ t2
String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(4, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 16;
  aux_String_0_Var.length = 15;
  aux_String_0_Var.values = "linesplitstring";
  LUMI_dec_ref(ut_M_str_Refman);
  ut_M_str_Refman = aux_String_0_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  ut_M_str = aux_String_0;
/// @ t3
String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(4, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 19;
  aux_String_0_Var.length = 18;
  aux_String_0_Var.values = "multi\nline\nstring\n";
  LUMI_dec_ref(ut_M_str_Refman);
  ut_M_str_Refman = aux_String_0_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  ut_M_str = aux_String_0;
/// @ t4
String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(2, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 11;
  aux_String_0_Var.length = 10;
  aux_String_0_Var.values = "line split";
  LUMI_dec_ref(ut_M_str_Refman);
  ut_M_str_Refman = aux_String_0_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
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
LUMI_dec_ref(ut_M_str_Refman);
  ut_M_str_Refman = NULL;
  LUMI_inc_ref(ut_M_str_Refman);
  ut_M_str = NULL;
/// @ t1
LUMI_dec_ref(ut_M_t_Refman);
  ut_M_t_Refman = NULL;
  LUMI_inc_ref(ut_M_t_Refman);
  ut_M_t = NULL;
/// @ t2
String_Del(*so);
  LUMI_owner_dec_ref(*so_Refman);
  *so_Refman = NULL;
  *so = NULL;
/// @ t3
ut_M_b = ((void*)ut_M_t == NULL) || ((void*)ut_M_ta != NULL);
/// @ te0
cannot assign "Empty Symbol" into "Int"
/// @@ test-member-expression
/// @ t0
if (ut_M_t == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  ut_M_i = ut_M_t->num;
/// @ t1
if (ut_M_tc == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_tc_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  ut_M_i = ut_M_tc->_base.numb;
/// @ t2
if (ut_M_tc == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_tc_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  ut_M_i = ut_M_tc->_base._base._base.num;
/// @ t3
if (*to == NULL) RAISE(1, 27, "used member of empty object")
  if ((*to_Refman)->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  ut_M_i = (*to)->num;
/// @ t4
if (*tco == NULL) RAISE(1, 27, "used member of empty object")
  if ((*tco_Refman)->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  ut_M_i = (*tco)->_base._base._base.num;
/// @ t5
if (ut_M_t == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  if (ut_M_t->t == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_t->t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  ut_M_i = ut_M_t->t->num;
/// @ t6
if (ut_M_t == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  if (ut_M_t->t == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_t->t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  if (ut_M_t->t->t == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_t->t->t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
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
if (ut_M_str == NULL) RAISE(1, 29, "empty object used as sequence")
  if (ut_M_str_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((13) < 0 || (13) >= (ut_M_str)->length) RAISE(1, 25, "slice index out of bounds")
  ut_M_c = ((ut_M_str)->values)[13];
/// @ t1
String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  aux_String_0_Var.length = 6;
  aux_String_0_Var.max_length = aux_String_0_Var.length + 1;
  aux_String_0_Var.values = (ut_M_str)->values + (2);
  if (ut_M_str == NULL) RAISE(1, 29, "empty object used as sequence")
  if (ut_M_str_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (6) < 0 || (2) + (6) > (ut_M_str)->length) RAISE(1, 25, "slice index out of bounds")
  LUMI_dec_ref(ut_M_str_Refman);
  ut_M_str_Refman = ut_M_str_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
  ut_M_str = aux_String_0;
/// @ t2
if (ut_M_arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (ut_M_arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((13) < 0 || (13) >= (ut_M_arr)->length) RAISE(1, 25, "slice index out of bounds")
  ut_M_i = ((Int*)((ut_M_arr)->values))[13];
/// @ t3
Array aux_Array_0_Var = {0};
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  aux_Array_0 = &aux_Array_0_Var;
  aux_Array_0_Refman = LUMI_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  aux_Array_0_Var.length = 6;
  aux_Array_0_Var.values = (Byte*)((ut_M_arr)->values) + (2);
  if (ut_M_arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (ut_M_arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (6) < 0 || (2) + (6) > (ut_M_arr)->length) RAISE(1, 25, "slice index out of bounds")
  LUMI_dec_ref(ut_M_arr_Refman);
  ut_M_arr_Refman = ut_M_arr_Refman;
  LUMI_inc_ref(ut_M_arr_Refman);
  ut_M_arr = aux_Array_0;
/// @ t4
if (ut_M_str == NULL) RAISE(1, 29, "empty object used as sequence")
  if (ut_M_str_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (ut_M_str)->length) RAISE(1, 25, "slice index out of bounds")
  ((ut_M_str)->values)[4] = ut_M_c;
/// @ t5
if (ut_M_arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (ut_M_arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (ut_M_arr)->length) RAISE(1, 25, "slice index out of bounds")
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
CHECK(1, ut_M_fun0() )
/// @ t1
CHECK(1, ut_M_fun1(3, ut_M_str, ut_M_str_Refman, NULL, NULL) )
/// @ t2
CHECK(1, ut_M_fun2(&(*so), &(*so_Refman), &(*io)) )
/// @ t3
Int x = 0;
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  CHECK(3, ut_M_fun2(&(s), &(s_Refman), &(x)) )
/// @ t4
CHECK(1, ut_M_fun3(0, &(*so), &(*so_Refman)) )
/// @ t5
Int x = 0;
  CHECK(2, ut_M_fun5(3, &(x)) )
  CHECK(2, ut_M_fun4(x) )
/// @ t6
CHECK(1, ut_M_fun6(2, 3, &(*io), &(*io)) )
/// @ t7
Int aux_Int_0 = 0;
  CHECK(1, ut_M_fun5(4, &(aux_Int_0)) )
/// @ t8
Int aux_Int_0 = 0;
  CHECK(1, ut_M_fun5(4, &(aux_Int_0)) )
  *io = aux_Int_0;
/// @ t9
String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  CHECK(1, ut_M_fun3(7, &(aux_String_0), &(aux_String_0_Refman)) )
  String_Del(*so);
  LUMI_owner_dec_ref(*so_Refman);
  *so_Refman = aux_String_0_Refman;
  *so = aux_String_0;
  aux_String_0 = NULL;
  aux_String_0_Refman = NULL;
/// @ t10
CHECK(1, ut_M_Test_meth(ut_M_t, ut_M_t_Refman) )
/// @ t11
CHECK(1, ut_M_Test_meth(*to, *to_Refman) )
/// @ t12
CHECK(1, ut_M_Tc_methc(ut_M_tc, ut_M_tc_Refman, ut_M_tc_Dynamic) )
/// @ t13
CHECK(1, ut_M_Tb_methb(&(ut_M_tc->_base), ut_M_tc_Refman, &(ut_M_tc_Dynamic->_base)) )
/// @ t14
CHECK(1, ut_M_Test_meth(&(ut_M_tc->_base._base._base), ut_M_tc_Refman) )
/// @ t15
CHECK(1, ut_M_Test_meth(&((*tco)->_base._base._base), *tco_Refman) )
/// @ t16
if (ut_M_t == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  CHECK(1, ut_M_Test_meth(ut_M_t->t, ut_M_t->t_Refman) )
/// @ t17
CHECK(1, ut_M_fun1(3, ut_M_str, ut_M_str_Refman, *so, *so_Refman) )
  *so = NULL;
  *so_Refman = NULL;
/// @ t18
String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  Int aux_Int_0 = 0;
  CHECK(1, ut_M_fun3(1, &(aux_String_0), &(aux_String_0_Refman)) )
  CHECK(2, ut_M_fun5(2, &(aux_Int_0)) )
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
  CHECK(6, ut_M_Base_meth(&(self->_base), self_Refman, &(self_Dynamic->_base), &(t->_base), t_Refman, &(t_Dynamic->_base)) )
  t = NULL;
  t_Refman = NULL;
  t_Dynamic = NULL;
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
  if (*t_Dynamic == NULL) RAISE(5, 28, "dynamic call of empty object")
  CHECK(5, ut_M_mock(&(*t), &(*t_Refman), &(*t_Dynamic)) )
  CHECK(5, (*t_Dynamic)->meth(*t, *t_Refman, *t_Dynamic) )
LUMI_cleanup:
  return LUMI_err;
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
CHECK(1, ut_M_Test_meth(ut_M_t, ut_M_t_Refman) )
/// @ t1
CHECK(1, ut_M_Tb_methb(&(ut_M_tc->_base), ut_M_tc_Refman, &(ut_M_tc_Dynamic->_base)) )
/// @ t2
CHECK(1, ut_M_Test_meth(&(ut_M_tc->_base._base._base), ut_M_tc_Refman) )
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
  CHECK(9, ut_M_Mid_methm(&(self->_base), self_Refman) )
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
  CHECK(9, ut_M_Base_methb(&(self->_base._base), self_Refman) )
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
LUMI_dec_ref(ut_M_t_Refman);
  ut_M_t_Refman = ut_M_tc_Refman;
  LUMI_inc_ref(ut_M_t_Refman);
  ut_M_t = &(ut_M_tc->_base._base._base);
/// @ t8
String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  String_Del(s);
  LUMI_owner_dec_ref(s_Refman);
  s_Refman = *so_Refman;
  s = *so;
  *so = NULL;
  *so_Refman = NULL;
/// @ t9
LUMI_dec_ref(ut_M_str_Refman);
  ut_M_str_Refman = *so_Refman;
  LUMI_inc_ref(ut_M_str_Refman);
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
  if (ut_M_tb_Dynamic != NULL) ut_M_tb_Dynamic->_base._del(ut_M_tb);
  LUMI_owner_dec_ref(ut_M_tb_Refman);
  ut_M_tb_Refman = otc_Refman;
  ut_M_tb_Dynamic = &(otc_Dynamic->_base);
  ut_M_tb = &(otc->_base);
  otc = NULL;
  otc_Refman = NULL;
  otc_Dynamic = NULL;
/// @ t15
Array* tarr = NULL;
  Ref_Manager* tarr_Refman = NULL;
  ARRAY_DEL(ut_M_Test, tarr)
  LUMI_owner_dec_ref(tarr_Refman);
  tarr_Refman = NULL;
  tarr = NULL;
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
if (ut_M_t == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  ut_M_b = ut_M_t->fun != NULL;
/// @ t3
ut_M_b = (*to) != NULL && (*to_Refman)->value != NULL;
/// @ t4
if (*to != NULL) RAISE(1, 45, "non empty base class given as output argument")
  CHECK(1, ut_M_fun7(NULL, NULL, NULL, (void*)&(*to), &(*to_Refman), (void*)&(*to_Dynamic)) )
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
  a = &a_Var;
  a_Refman = LUMI_new_ref(a);
  if (a_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, ut_M_Test_new(&(a->_base), a_Refman, 1) )
/// @ t1
ut_M_Ta* a = NULL;
  Ref_Manager* a_Refman = NULL;
  ut_M_Ta_Dynamic* a_Dynamic = NULL;
/// @ t2
ut_M_Ta* aux_Ta_0 = NULL;
  Ref_Manager* aux_Ta_0_Refman = NULL;
  ut_M_Ta_Dynamic* aux_Ta_0_Dynamic = &ut_M_Ta_dynamic;
  aux_Ta_0 = LUMI_alloc(sizeof(ut_M_Ta));
  if (aux_Ta_0 == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  aux_Ta_0_Refman = LUMI_new_ref(aux_Ta_0);
  if (aux_Ta_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, ut_M_Test_new(&(aux_Ta_0->_base), aux_Ta_0_Refman, 7) )
  LUMI_dec_ref(ut_M_ta_Refman);
  ut_M_ta_Refman = aux_Ta_0_Refman;
  LUMI_inc_ref(ut_M_ta_Refman);
  ut_M_ta_Dynamic = aux_Ta_0_Dynamic;
  ut_M_ta = aux_Ta_0;
/// @ t3
ut_M_Ta* a = NULL;
  Ref_Manager* a_Refman = NULL;
  ut_M_Ta_Dynamic* a_Dynamic = &ut_M_Ta_dynamic;
  a = LUMI_alloc(sizeof(ut_M_Ta));
  if (a == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  a_Refman = LUMI_new_ref(a);
  if (a_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, ut_M_Test_new(&(a->_base), a_Refman, 1) )
/// @ t4
ut_M_Ta* a = NULL;
  Ref_Manager* a_Refman = NULL;
  ut_M_Ta_Dynamic* a_Dynamic = NULL;
  a = ut_M_ta;
  a_Refman = ut_M_ta_Refman;
  LUMI_inc_ref(a_Refman);
  a_Dynamic = ut_M_ta_Dynamic;
/// @ t5
LUMI_dec_ref(ut_M_ta_Refman);
  ut_M_ta_Refman = ut_M_ta_Refman;
  LUMI_inc_ref(ut_M_ta_Refman);
  ut_M_ta_Dynamic = ut_M_ta_Dynamic;
  ut_M_ta = ut_M_ta;
/// @ t6
LUMI_dec_ref(ut_M_ta_Refman);
  ut_M_ta_Refman = ut_M_tb_Refman;
  LUMI_inc_ref(ut_M_ta_Refman);
  ut_M_ta_Dynamic = &(ut_M_tb_Dynamic->_base);
  ut_M_ta = &(ut_M_tb->_base);
/// @ t7
LUMI_dec_ref(ut_M_ta_Refman);
  ut_M_ta_Refman = ut_M_tc_Refman;
  LUMI_inc_ref(ut_M_ta_Refman);
  ut_M_ta_Dynamic = &(ut_M_tc_Dynamic->_base._base);
  ut_M_ta = &(ut_M_tc->_base._base);
/// @ t8
LUMI_dec_ref(ut_M_ta_Refman);
  ut_M_ta_Refman = NULL;
  LUMI_inc_ref(ut_M_ta_Refman);
  ut_M_ta_Dynamic = NULL;
  ut_M_ta = NULL;
/// @ t9
Array* aa = NULL;
  Ref_Manager* aa_Refman = NULL;
  if (aa == NULL) RAISE(2, 29, "empty object used as sequence")
  if (aa_Refman->value == NULL) RAISE(2, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (aa)->length) RAISE(2, 25, "slice index out of bounds")
  LUMI_dec_ref(ut_M_ta_Refman);
  ut_M_ta_Refman = aa_Refman;
  LUMI_inc_ref(ut_M_ta_Refman);
  ut_M_ta_Dynamic = &ut_M_Ta_dynamic;
  ut_M_ta = ((ut_M_Ta*)((aa)->values)) + 4;
/// @ t10
Array* ca = NULL;
  Ref_Manager* ca_Refman = NULL;
  if (ca == NULL) RAISE(2, 29, "empty object used as sequence")
  if (ca_Refman->value == NULL) RAISE(2, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (ca)->length) RAISE(2, 25, "slice index out of bounds")
  LUMI_dec_ref(ut_M_ta_Refman);
  ut_M_ta_Refman = ca_Refman;
  LUMI_inc_ref(ut_M_ta_Refman);
  ut_M_ta_Dynamic = &(&ut_M_Tc_dynamic->_base._base);
  ut_M_ta = &((((ut_M_Tc*)((ca)->values)) + 4)->_base._base);
/// @ t11
if (ut_M_ta_Dynamic == NULL) RAISE(1, 28, "dynamic call of empty object")
  CHECK(1, ut_M_ta_Dynamic->dyn(ut_M_ta, ut_M_ta_Refman, ut_M_ta_Dynamic) )
/// @ t12
if (ut_M_tb_Dynamic == NULL) RAISE(1, 28, "dynamic call of empty object")
  CHECK(1, ut_M_tb_Dynamic->_base.dyn(&(ut_M_tb->_base), ut_M_tb_Refman, &(ut_M_tb_Dynamic->_base)) )
/// @ t13
if (ut_M_tc_Dynamic == NULL) RAISE(1, 28, "dynamic call of empty object")
  CHECK(1, ut_M_tc_Dynamic->_base._base.dyn(&(ut_M_tc->_base._base), ut_M_tc_Refman, &(ut_M_tc_Dynamic->_base._base)) )
/// @ t14
if (*tco_Dynamic == NULL) RAISE(1, 28, "dynamic call of empty object")
  CHECK(1, (*tco_Dynamic)->_base._base.dyn(&((*tco)->_base._base), *tco_Refman, &((*tco_Dynamic)->_base._base)) )
/// @ t15
if (ut_M_ta != NULL) RAISE(1, 45, "non empty base class given as output argument")
  CHECK(1, ut_M_fun7(&(ut_M_tc->_base), ut_M_tc_Refman, &(ut_M_tc_Dynamic->_base), (void*)&(ut_M_ta), &(ut_M_ta_Refman), (void*)&(ut_M_ta_Dynamic)) )
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
  if (*t_Dynamic == NULL) RAISE(5, 28, "dynamic call of empty object")
  CHECK(5, (*t_Dynamic)->meth(*t, *t_Refman, *t_Dynamic) )
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
  if (self_Dynamic == NULL) RAISE(6, 28, "dynamic call of empty object")
  CHECK(6, self_Dynamic->_base.meth(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
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
  CHECK(1, ut_M_fun7(NULL, NULL, NULL, &(aux_Tb_0), &(aux_Tb_0_Refman), &(aux_Tb_0_Dynamic)) )
/// @@ test-function-object
/// @ t0
Returncode (*fun)(void) = NULL;
  fun = ut_M_fun0;
  if (fun == NULL) RAISE(3, 21, "empty function called")
  CHECK(3, fun() )
/// @ t1
Returncode (*fun)(Int x, Int* y) = NULL;
  Int x = 0;
  fun = ut_M_fun5;
  if (fun == NULL) RAISE(3, 21, "empty function called")
  CHECK(3, fun(9, &(x)) )
/// @ t2
Returncode (*fun)(ut_M_Test* self, Ref_Manager* self_Refman) = NULL;
  fun = ut_M_Test_meth;
  if (fun == NULL) RAISE(2, 21, "empty function called")
  CHECK(2, fun(ut_M_t, ut_M_t_Refman) )
/// @ t3
Returncode (*fun)(void) = NULL;
  fun = NULL;
  ut_M_b = fun != NULL;
/// @ t4
if (ut_M_t == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  ut_M_t->fun = ut_M_fun0;
  if (ut_M_t == NULL) RAISE(2, 27, "used member of empty object")
  if (ut_M_t_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
  if (ut_M_t->fun == NULL) RAISE(2, 21, "empty function called")
  CHECK(2, ut_M_t->fun() )
/// @ t5
Returncode (*farr_Values[38])(void) = {0};
  Array farr_Var = {38, NULL};
  Array* farr = NULL;
  Ref_Manager* farr_Refman = NULL;
  farr = &farr_Var;
  farr_Var.values = farr_Values;
  farr_Refman = LUMI_new_ref(farr);
  if (farr_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  if (farr == NULL) RAISE(2, 29, "empty object used as sequence")
  if (farr_Refman->value == NULL) RAISE(2, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) >= (farr)->length) RAISE(2, 25, "slice index out of bounds")
  ((Returncode (**)(void))((farr)->values))[3] = ut_M_fun0;
  if (farr == NULL) RAISE(3, 29, "empty object used as sequence")
  if (farr_Refman->value == NULL) RAISE(3, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) >= (farr)->length) RAISE(3, 25, "slice index out of bounds")
  if (((Returncode (**)(void))((farr)->values))[3] == NULL) RAISE(3, 21, "empty function called")
  CHECK(3, (((Returncode (**)(void))((farr)->values))[3])() )
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
CHECK(1, Int_str(ut_M_i, ut_M_str, ut_M_str_Refman) )
/// @ t1
ut_M_b = true;
/// @ t2
ut_M_b = false;
/// @ t3
unknown symbol "EOF"
/// @ t4
if (ut_M_arr == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_arr_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  ut_M_i = ut_M_arr->length;
/// @ t5
if (ut_M_str == NULL) RAISE(1, 27, "used member of empty object")
  if (ut_M_str_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  ut_M_i = ut_M_str->length;
/// @ t6
CHECK(1, String_clear(ut_M_str, ut_M_str_Refman) )
/// @ t7
CHECK(1, String_equal(ut_M_str, ut_M_str_Refman, ut_M_str, ut_M_str_Refman, &(ut_M_b)) )
/// @ t8
CHECK(1, String_get(ut_M_str, ut_M_str_Refman, ut_M_i, &(ut_M_c)) )
/// @ t9
CHECK(1, String_append(ut_M_str, ut_M_str_Refman, ut_M_c) )
/// @ t10
CHECK(1, String_new(ut_M_str, ut_M_str_Refman, ut_M_str, ut_M_str_Refman) )
/// @ t11
CHECK(1, String_concat(ut_M_str, ut_M_str_Refman, ut_M_str, ut_M_str_Refman) )
/// @ t12
CHECK(1, String_concat_int(ut_M_str, ut_M_str_Refman, ut_M_i) )
/// @ t13
CHECK(1, String_find(ut_M_str, ut_M_str_Refman, ut_M_str, ut_M_str_Refman, &(ut_M_i)) )
/// @ t14
CHECK(1, String_has(ut_M_str, ut_M_str_Refman, ut_M_c, &(ut_M_b)) )
/// @ t15
CHECK(1, file_open_read(ut_M_str, ut_M_str_Refman, &(ut_M_fobj), &(ut_M_fobj_Refman)) )
/// @ t16
CHECK(1, file_open_write(ut_M_str, ut_M_str_Refman, &(ut_M_fobj), &(ut_M_fobj_Refman)) )
/// @ t17
CHECK(1, File_close(ut_M_fobj, ut_M_fobj_Refman) )
/// @ t18
CHECK(1, File_getc(ut_M_fobj, ut_M_fobj_Refman, &(ut_M_c), &(ut_M_b)) )
/// @ t19
CHECK(1, File_putc(ut_M_fobj, ut_M_fobj_Refman, ut_M_c) )
/// @ t20
CHECK(1, File_write(ut_M_fobj, ut_M_fobj_Refman, ut_M_str, ut_M_str_Refman) )
/// @ t21
Array* argv = NULL;
  Ref_Manager* argv_Refman = NULL;
  if (sys == NULL) RAISE(1, 27, "used member of empty object")
  if (sys_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  argv = sys->argv;
  argv_Refman = sys->argv_Refman;
  LUMI_inc_ref(argv_Refman);
/// @ t22
CHECK(1, Sys_print(sys, sys_Refman, ut_M_str, ut_M_str_Refman) )
/// @ t23
CHECK(1, Sys_println(sys, sys_Refman, ut_M_str, ut_M_str_Refman) )
/// @ t24
CHECK(1, Sys_getchar(sys, sys_Refman, &(ut_M_c), &(ut_M_b)) )
/// @ t25
CHECK(1, Sys_getline(sys, sys_Refman, ut_M_str, ut_M_str_Refman) )
/// @ t26
CHECK(1, Sys_exit(sys, sys_Refman, ut_M_i) )
/// @ t27
CHECK(1, Sys_system(sys, sys_Refman, ut_M_str, ut_M_str_Refman, &(ut_M_i)) )
/// @ t28
CHECK(1, Sys_getenv(sys, sys_Refman, ut_M_str, ut_M_str_Refman, ut_M_str, ut_M_str_Refman, &(ut_M_b)) )
/// @ t29
CHECK(1, File_putc(stdout, stdout_Refman, ut_M_c) )
/// @ t30
CHECK(1, File_getc(stdin, stdin_Refman, &(ut_M_c), &(ut_M_b)) )
/// @ t31
CHECK(1, File_putc(stderr, stderr_Refman, ut_M_c) )
/// @ t32
CHECK(1, String_clear(ut_M_str, ut_M_str_Refman) )
/// @
