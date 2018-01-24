/// @@ test-int-expression
/// @ t0
i = 0;
/// @ t1
i = 9630;
/// @ t2
i = -9630;
/// @ t3
i = 07520;
/// @ t4
i = -07520;
/// @ t5
i = 0xfda940;
/// @ t6
i = -0xfda940;
/// @ t7
i = 0xFDA940;
/// @ t8
i = -0xFDA940;
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
c = 'a';
/// @ t1
c = '\'';
/// @ t2
c = '\n';
/// @ t3
c = '\x0f';
/// @ t4
c = '\xA9';
/// @ t5
c = '\270';
/// @ te0
illegal character constant "'''"
/// @ te1
illegal character constant "'\'"
/// @ te2
illegal character constant "'aa'"
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
illegal character constant "'aaa'"
/// @ te9
illegal character constant "'aaaaa'"
/// @ te10
illegal character constant "'aa"
/// @@ test-string-expression
/// @ t0
String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(1)
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  MR_dec_ref(str_Refman);
  str_Refman = aux_String_0_Refman;
  MR_inc_ref(str_Refman);
  str = aux_String_0;
/// @ t1
String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(1)
  aux_String_0_Var.max_length = 25;
  aux_String_0_Var.length = 24;
  aux_String_0_Var.values = "\nstring\twith\\formatting\n";
  MR_dec_ref(str_Refman);
  str_Refman = aux_String_0_Refman;
  MR_inc_ref(str_Refman);
  str = aux_String_0;
/// @ te0
illegal string constant ""aaa"
/// @ te1
statememnt has no effect
/// @@ test-empty-expression
/// @ t0
MR_dec_ref(str_Refman);
  str_Refman = NULL;
  MR_inc_ref(str_Refman);
  str = NULL;
/// @ t1
MR_dec_ref(t_Refman);
  t_Refman = NULL;
  MR_inc_ref(t_Refman);
  t = NULL;
/// @ t2
MR_owner_dec_ref(*so_Refman);
  *so_Refman = NULL;
  *so = NULL;
/// @ t3
b = (t == NULL) || (ta != NULL);
/// @ te0
cannot assign "Empty Symbol" into "Int"
/// @@ test-member-expression
/// @ t0
if (t == NULL || t_Refman->value == NULL) RAISE(1)
  i = t->num;
/// @ t1
if (tc == NULL || tc_Refman->value == NULL) RAISE(1)
  i = tc->_base.numb;
/// @ t2
if (tc == NULL || tc_Refman->value == NULL) RAISE(1)
  i = tc->_base._base._base.num;
/// @ t3
if (*to == NULL || (*to_Refman)->value == NULL) RAISE(1)
  i = (*to)->num;
/// @ t4
if (*tco == NULL || (*tco_Refman)->value == NULL) RAISE(1)
  i = (*tco)->_base._base._base.num;
/// @ t5
if (t == NULL || t_Refman->value == NULL) RAISE(1)
  if (t->t == NULL || t->t_Refman->value == NULL) RAISE(1)
  i = t->t->num;
/// @ t6
if (t == NULL || t_Refman->value == NULL) RAISE(1)
  if (t->t == NULL || t->t_Refman->value == NULL) RAISE(1)
  if (t->t->t == NULL || t->t->t_Refman->value == NULL) RAISE(1)
  i = t->t->t->num;
/// @ te0
unknown symbol "error"
/// @ te1
void expression has no member "error"
/// @ te2
type "Test" has no member "error"
/// @@ test-slice-expression
/// @ t0
if (str == NULL || str_Refman->value == NULL) RAISE(1)
  if ((13) < 0 || (13) >= (str)->length) RAISE(1)
  c = ((str)->values)[13];
/// @ t1
String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(1)
  aux_String_0_Var.length = 6;
  aux_String_0_Var.max_length = aux_String_0_Var.length + 1;
  aux_String_0_Var.values = (str)->values + (2);
  if (str == NULL || str_Refman->value == NULL) RAISE(1)
  if ((2) < 0 || (6) < 0 || (2) + (6) > (str)->length) RAISE(1)
  MR_dec_ref(str_Refman);
  str_Refman = str_Refman;
  MR_inc_ref(str_Refman);
  str = aux_String_0;
/// @ t2
if (arr == NULL || arr_Refman->value == NULL) RAISE(1)
  if ((13) < 0 || (13) >= (arr)->length) RAISE(1)
  i = ((Int*)((arr)->values))[13];
/// @ t3
Array aux_Array_0_Var = {0};
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  aux_Array_0 = &aux_Array_0_Var;
  aux_Array_0_Refman = MR_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(1)
  aux_Array_0_Var.length = 6;
  aux_Array_0_Var.values = (Byte*)((arr)->values) + (2);
  if (arr == NULL || arr_Refman->value == NULL) RAISE(1)
  if ((2) < 0 || (6) < 0 || (2) + (6) > (arr)->length) RAISE(1)
  MR_dec_ref(arr_Refman);
  arr_Refman = arr_Refman;
  MR_inc_ref(arr_Refman);
  arr = aux_Array_0;
/// @ t4
if (str == NULL || str_Refman->value == NULL) RAISE(1)
  if ((4) < 0 || (4) >= (str)->length) RAISE(1)
  ((str)->values)[4] = c;
/// @ t5
if (arr == NULL || arr_Refman->value == NULL) RAISE(1)
  if ((4) < 0 || (4) >= (arr)->length) RAISE(1)
  ((Int*)((arr)->values))[4] = i;
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
CHECK(1, fun0() )
/// @ t1
CHECK(1, fun1(3, str, str_Refman, NULL, NULL) )
/// @ t2
CHECK(1, fun2(&(*so), &(*so_Refman), &(*io)) )
/// @ t3
Int x = 0;
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  CHECK(3, fun2(&(s), &(s_Refman), &(x)) )
/// @ t4
CHECK(1, fun3(0, &(*so), &(*so_Refman)) )
/// @ t5
Int x = 0;
  CHECK(2, fun5(3, &(x)) )
  CHECK(2, fun4(x) )
/// @ t6
CHECK(1, fun6(2, 3, &(*io), &(*io)) )
/// @ t7
Int aux_Int_0 = 0;
  CHECK(1, fun5(4, &(aux_Int_0)) )
/// @ t8
Int aux_Int_0 = 0;
  CHECK(1, fun5(4, &(aux_Int_0)) )
  *io = aux_Int_0;
/// @ t9
String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  CHECK(1, fun3(7, &(aux_String_0), &(aux_String_0_Refman)) )
  MR_owner_dec_ref(*so_Refman);
  *so_Refman = aux_String_0_Refman;
  aux_String_0_Refman = NULL;
  *so = aux_String_0;
  aux_String_0 = NULL;
/// @ t10
CHECK(1, Test_meth(t, t_Refman) )
/// @ t11
CHECK(1, Test_meth(*to, *to_Refman) )
/// @ t12
CHECK(1, Tc_methc(tc, tc_Refman, tc_Dynamic) )
/// @ t13
CHECK(1, Tb_methb(&(tc->_base), tc_Refman, &(tc_Dynamic->_base)) )
/// @ t14
CHECK(1, Test_meth(&(tc->_base._base._base), tc_Refman) )
/// @ t15
CHECK(1, Test_meth(&((*tco)->_base._base._base), *tco_Refman) )
/// @ t16
if (t == NULL || t_Refman->value == NULL) RAISE(1)
  CHECK(1, Test_meth(t->t, t->t_Refman) )
/// @ t17
CHECK(1, fun1(3, str, str_Refman, *so, *so_Refman) )
  *so = NULL;
  *so_Refman = NULL;
/// @ t18
String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  Int aux_Int_0 = 0;
  CHECK(1, fun3(1, &(aux_String_0), &(aux_String_0_Refman)) )
  CHECK(2, fun5(2, &(aux_Int_0)) )
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
/// @@ test-type-expression
/// @ t0
CHECK(1, Test_meth(t, t_Refman) )
/// @ t1
CHECK(1, Tb_methb(&(tc->_base), tc_Refman, &(tc_Dynamic->_base)) )
/// @ t2
CHECK(1, Test_meth(&(tc->_base._base._base), tc_Refman) )
/// @ t3
unknown type "Error"
/// @@ test-base-expression
/// @ t0
typedef struct Base Base;
typedef struct Mid Mid;
typedef struct Top Top;
struct Base {
  Int x;
};
struct Mid {
  Base _base;
};
struct Top {
  Mid _base;
};
Returncode Base_methb(Base* self, Ref_Manager* self_Refman);
void Base_Del(Base* self);
Returncode Mid_methm(Mid* self, Ref_Manager* self_Refman);
void Mid_Del(Mid* self);
Returncode Top_methb(Top* self, Ref_Manager* self_Refman);
Returncode Top_methm(Top* self, Ref_Manager* self_Refman);
void Top_Del(Top* self);
Returncode Base_methb(Base* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Base_Del(Base* self) {
  if (self == NULL) return;
}
Returncode Mid_methm(Mid* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Mid_Del(Mid* self) {
  if (self == NULL) return;
  Base_Del(&(self->_base));
}
Returncode Top_methb(Top* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Top_methm(Top* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
  CHECK(9, Mid_methm(&(self->_base), self_Refman) )
MR_cleanup:
  return MR_err;
}
void Top_Del(Top* self) {
  if (self == NULL) return;
  Mid_Del(&(self->_base));
}
/// @ t1
typedef struct Base Base;
typedef struct Mid Mid;
typedef struct Top Top;
struct Base {
  Int x;
};
struct Mid {
  Base _base;
};
struct Top {
  Mid _base;
};
Returncode Base_methb(Base* self, Ref_Manager* self_Refman);
void Base_Del(Base* self);
Returncode Mid_methm(Mid* self, Ref_Manager* self_Refman);
void Mid_Del(Mid* self);
Returncode Top_methb(Top* self, Ref_Manager* self_Refman);
Returncode Top_methm(Top* self, Ref_Manager* self_Refman);
void Top_Del(Top* self);
Returncode Base_methb(Base* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Base_Del(Base* self) {
  if (self == NULL) return;
}
Returncode Mid_methm(Mid* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Mid_Del(Mid* self) {
  if (self == NULL) return;
  Base_Del(&(self->_base));
}
Returncode Top_methb(Top* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Top_methm(Top* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
  CHECK(9, Base_methb(&(self->_base._base), self_Refman) )
MR_cleanup:
  return MR_err;
}
void Top_Del(Top* self) {
  if (self == NULL) return;
  Mid_Del(&(self->_base));
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
i = 2 + (123);
/// @ t1
i = 123;
/// @ t2
i = (123 * (i - 4)) + 2;
/// @ t3
expected ")", got "new-line"
/// @@ test-unary-expression
/// @ t0
i = - i;
/// @ t1
i = - i;
/// @ t2
i = - (- i);
/// @ t3
b = ! b;
/// @ t4
b = ! (i > 3);
/// @ t5
unexpected "["
/// @ t6
unexpected "["
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
i = 23 + 54;
/// @ t1
i += (100 * 2) - ((37 / 5) % 2);
/// @ t2
i -= 12 * 13;
/// @ t3
b = (3 < 5) || (23 > 37);
/// @ t4
b = (3 <= 5) && (23 >= 37);
/// @ t5
b = (i == 5) || (i != 37);
/// @ t6
b = ((2 < i) && (i < 12)) && (12 < (2 * i));
/// @ t7
MR_dec_ref(t_Refman);
  t_Refman = tc_Refman;
  MR_inc_ref(t_Refman);
  t = &(tc->_base._base._base);
/// @ t8
String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  MR_owner_dec_ref(s_Refman);
  s_Refman = *so_Refman;
  *so_Refman = NULL;
  s = *so;
  *so = NULL;
/// @ t9
MR_dec_ref(str_Refman);
  str_Refman = *so_Refman;
  MR_inc_ref(str_Refman);
  str = *so;
/// @ t10
b = (t == ta) || (tb != tc);
/// @ t11
c = '0' + 4;
/// @ t12
b = fun0 != fun1;
/// @ t13
b = b == b;
/// @ te0
unknown operator "@"
/// @ te1
unexpected "("
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
/// @@ test-question-expression
/// @ t0
b = !(str == NULL || str_Refman->value == NULL);
/// @ t1
b = ! (!(str == NULL || str_Refman->value == NULL));
/// @ t2
if (t == NULL || t_Refman->value == NULL) RAISE(1)
  b = !(t->fun == NULL);
/// @ t3
b = !(*to == NULL || (*to_Refman)->value == NULL);
/// @ te0
cannot use "?" on void expression
/// @ te1
cannot use "?" on type "Int"
/// @@ test-dynamic
/// @ t0
Ta a_Var = {{0}};
  Ta* a = NULL;
  Ref_Manager* a_Refman = NULL;
  Ta_Dynamic* a_Dynamic = &Ta_dynamic;
  a = &a_Var;
  a_Refman = MR_new_ref(a);
  if (a_Refman == NULL) RAISE(1)
  CHECK(1, Test_new(&(a->_base), a_Refman, 1) )
/// @ t1
Ta* a = NULL;
  Ref_Manager* a_Refman = NULL;
  Ta_Dynamic* a_Dynamic = NULL;
/// @ t2
Ta* aux_Ta_0 = NULL;
  Ref_Manager* aux_Ta_0_Refman = NULL;
  Ta_Dynamic* aux_Ta_0_Dynamic = &Ta_dynamic;
  aux_Ta_0 = calloc(1, sizeof(Ta));
  if (aux_Ta_0 == NULL) RAISE(1)
  aux_Ta_0_Refman = MR_new_ref(aux_Ta_0);
  if (aux_Ta_0_Refman == NULL) RAISE(1)
  CHECK(1, Test_new(&(aux_Ta_0->_base), aux_Ta_0_Refman, 7) )
  MR_dec_ref(ta_Refman);
  ta_Refman = aux_Ta_0_Refman;
  MR_inc_ref(ta_Refman);
  ta_Dynamic = aux_Ta_0_Dynamic;
  ta = aux_Ta_0;
/// @ t3
Ta* a = NULL;
  Ref_Manager* a_Refman = NULL;
  Ta_Dynamic* a_Dynamic = &Ta_dynamic;
  a = calloc(1, sizeof(Ta));
  if (a == NULL) RAISE(1)
  a_Refman = MR_new_ref(a);
  if (a_Refman == NULL) RAISE(1)
  CHECK(1, Test_new(&(a->_base), a_Refman, 1) )
/// @ t4
Ta* a = NULL;
  Ref_Manager* a_Refman = NULL;
  Ta_Dynamic* a_Dynamic = NULL;
  a = ta;
  a_Refman = ta_Refman;
  MR_inc_ref(a_Refman);
  a_Dynamic = ta_Dynamic;
/// @ t5
MR_dec_ref(ta_Refman);
  ta_Refman = ta_Refman;
  MR_inc_ref(ta_Refman);
  ta_Dynamic = ta_Dynamic;
  ta = ta;
/// @ t6
MR_dec_ref(ta_Refman);
  ta_Refman = tb_Refman;
  MR_inc_ref(ta_Refman);
  ta_Dynamic = &(tb_Dynamic->_base);
  ta = &(tb->_base);
/// @ t7
MR_dec_ref(ta_Refman);
  ta_Refman = tc_Refman;
  MR_inc_ref(ta_Refman);
  ta_Dynamic = &(tc_Dynamic->_base._base);
  ta = &(tc->_base._base);
/// @ t8
MR_dec_ref(ta_Refman);
  ta_Refman = NULL;
  MR_inc_ref(ta_Refman);
  ta_Dynamic = NULL;
  ta = NULL;
/// @ t9
Array* aa = NULL;
  Ref_Manager* aa_Refman = NULL;
  if (aa == NULL || aa_Refman->value == NULL) RAISE(2)
  if ((4) < 0 || (4) >= (aa)->length) RAISE(2)
  MR_dec_ref(ta_Refman);
  ta_Refman = aa_Refman;
  MR_inc_ref(ta_Refman);
  ta_Dynamic = &Ta_dynamic;
  ta = ((Ta*)((aa)->values)) + 4;
/// @ t10
Array* ca = NULL;
  Ref_Manager* ca_Refman = NULL;
  if (ca == NULL || ca_Refman->value == NULL) RAISE(2)
  if ((4) < 0 || (4) >= (ca)->length) RAISE(2)
  MR_dec_ref(ta_Refman);
  ta_Refman = ca_Refman;
  MR_inc_ref(ta_Refman);
  ta_Dynamic = &(&Tc_dynamic->_base._base);
  ta = &((((Tc*)((ca)->values)) + 4)->_base._base);
/// @ t11
if (ta_Dynamic == NULL) RAISE(1)
  CHECK(1, ta_Dynamic->dyn(ta, ta_Refman, ta_Dynamic) )
/// @ t12
if (tb_Dynamic == NULL) RAISE(1)
  CHECK(1, tb_Dynamic->_base.dyn(&(tb->_base), tb_Refman, &(tb_Dynamic->_base)) )
/// @ t13
if (tc_Dynamic == NULL) RAISE(1)
  CHECK(1, tc_Dynamic->_base._base.dyn(&(tc->_base._base), tc_Refman, &(tc_Dynamic->_base._base)) )
/// @ t14
if (*tco_Dynamic == NULL) RAISE(1)
  CHECK(1, (*tco_Dynamic)->_base._base.dyn(&((*tco)->_base._base), *tco_Refman, &((*tco_Dynamic)->_base._base)) )
/// @ t15
if (ta != NULL) RAISE(1)
  CHECK(1, fun7((void*)&(ta), &(ta_Refman), (void*)&(ta_Dynamic)) )
/// @@ test-function-object
/// @ t0
Returncode (*fun)(void) = NULL;
  fun = fun0;
  if (fun == NULL) RAISE(3)
  CHECK(3, fun() )
/// @ t1
Returncode (*fun)(Int x, Int* y) = NULL;
  Int x = 0;
  fun = fun5;
  if (fun == NULL) RAISE(3)
  CHECK(3, fun(9, &(x)) )
/// @ t2
Returncode (*fun)(Test* self, Ref_Manager* self_Refman) = NULL;
  fun = Test_meth;
  if (fun == NULL) RAISE(2)
  CHECK(2, fun(t, t_Refman) )
/// @ t3
Returncode (*fun)(void) = NULL;
  fun = NULL;
  b = !(fun == NULL);
/// @ t4
if (t == NULL || t_Refman->value == NULL) RAISE(1)
  t->fun = fun0;
  if (t == NULL || t_Refman->value == NULL) RAISE(2)
  if (t->fun == NULL) RAISE(2)
  CHECK(2, t->fun() )
/// @ t5
Returncode (*farr_Values[38])(void) = {0};
  Array farr_Var = {38, NULL};
  Array* farr = NULL;
  Ref_Manager* farr_Refman = NULL;
  farr = &farr_Var;
  farr_Var.values = farr_Values;
  farr_Refman = MR_new_ref(farr);
  if (farr_Refman == NULL) RAISE(1)
  if (farr == NULL || farr_Refman->value == NULL) RAISE(2)
  if ((3) < 0 || (3) >= (farr)->length) RAISE(2)
  ((Returncode (**)(void))((farr)->values))[3] = fun0;
  if (farr == NULL || farr_Refman->value == NULL) RAISE(3)
  if ((3) < 0 || (3) >= (farr)->length) RAISE(3)
  if (((Returncode (**)(void))((farr)->values))[3] == NULL) RAISE(3)
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
CHECK(1, Int_str(i, str, str_Refman) )
/// @ t1
b = true;
/// @ t2
b = false;
/// @ t3
unknown symbol "EOF"
/// @ t4
if (arr == NULL || arr_Refman->value == NULL) RAISE(1)
  i = arr->length;
/// @ t5
if (str == NULL || str_Refman->value == NULL) RAISE(1)
  i = str->length;
/// @ t6
CHECK(1, String_clear(str, str_Refman) )
/// @ t7
CHECK(1, String_equal(str, str_Refman, str, str_Refman, &(b)) )
/// @ t8
CHECK(1, String_get(str, str_Refman, i, &(c)) )
/// @ t9
CHECK(1, String_append(str, str_Refman, c) )
/// @ t10
CHECK(1, String_new(str, str_Refman, str, str_Refman) )
/// @ t11
CHECK(1, String_concat(str, str_Refman, str, str_Refman) )
/// @ t12
CHECK(1, String_concat_int(str, str_Refman, i) )
/// @ t13
CHECK(1, String_find(str, str_Refman, str, str_Refman, &(i)) )
/// @ t14
CHECK(1, String_has(str, str_Refman, c, &(b)) )
/// @ t15
CHECK(1, file_open_read(str, str_Refman, &(fobj), &(fobj_Refman)) )
/// @ t16
CHECK(1, file_open_write(str, str_Refman, &(fobj), &(fobj_Refman)) )
/// @ t17
CHECK(1, File_close(fobj, fobj_Refman) )
/// @ t18
CHECK(1, File_getc(fobj, fobj_Refman, &(c), &(b)) )
/// @ t19
CHECK(1, File_putc(fobj, fobj_Refman, c) )
/// @ t20
CHECK(1, File_write(fobj, fobj_Refman, str, str_Refman) )
/// @ t21
Array* argv = NULL;
  Ref_Manager* argv_Refman = NULL;
  if (sys == NULL || sys_Refman->value == NULL) RAISE(1)
  argv = sys->argv;
  argv_Refman = sys->argv_Refman;
  MR_inc_ref(argv_Refman);
/// @ t22
CHECK(1, Sys_print(sys, sys_Refman, str, str_Refman) )
/// @ t23
CHECK(1, Sys_println(sys, sys_Refman, str, str_Refman) )
/// @ t24
CHECK(1, Sys_getchar(sys, sys_Refman, &(c), &(b)) )
/// @ t25
CHECK(1, Sys_getline(sys, sys_Refman, str, str_Refman) )
/// @ t26
CHECK(1, Sys_exit(sys, sys_Refman, i) )
/// @ t27
CHECK(1, Sys_system(sys, sys_Refman, str, str_Refman, &(i)) )
/// @ t28
CHECK(1, Sys_getenv(sys, sys_Refman, str, str_Refman, str, str_Refman, &(b)) )
/// @ t29
CHECK(1, File_putc(stdout, stdout_Refman, c) )
/// @ t30
CHECK(1, File_getc(stdin, stdin_Refman, &(c), &(b)) )
/// @ t31
CHECK(1, File_putc(stderr, stderr_Refman, c) )
/// @
