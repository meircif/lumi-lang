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
/// @ t9
illegal number "2a"
/// @ t10
illegal number "0a"
/// @ t11
illegal octal number "038"
/// @ t12
illegal binary number "0b021"
/// @ t13
illegal hexadecimal number "0xadg"
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
/// @ t6
illegal character constant "'''"
/// @ t7
illegal character constant "'\'"
/// @ t8
illegal character constant "'aa'"
/// @ t9
illegal character constant "'\c'"
/// @ t10
illegal character constant "'aaaa'"
/// @ t11
illegal character constant "'\x6fg'"
/// @ t12
illegal character constant "'\058'"
/// @ t13
illegal character constant "''"
/// @ t14
illegal character constant "'aaa'"
/// @ t15
illegal character constant "'aaaaa'"
/// @ t16
illegal character constant "'aa"
/// @@ test-string-expression
/// @ t0
String aux_String_0_Var = {0};
  String** aux_String_0 = NULL;
  aux_String_0 = MR_new_ref();
  if (aux_String_0 == NULL) RAISE(1)
  *aux_String_0 = &aux_String_0_Var;
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  str = aux_String_0;
/// @ t1
illegal string constant ""aaa"
/// @ t2
statememnt has no effect
/// @@ test-empty-expression
/// @ t0
str = NULL;
/// @ t1
t = NULL;
/// @ t2
cannot assign "Empty Symbol" into "Int"
/// @@ test-member-expression
/// @ t0
if (t == NULL || *t == NULL) RAISE(1)
  i = (*t)->num;
/// @ t1
if (tc == NULL || *tc == NULL) RAISE(1)
  i = (*tc)->_base.numb;
/// @ t2
if (tc == NULL || *tc == NULL) RAISE(1)
  i = (*tc)->_base._base._base.num;
/// @ t3
unknown symbol "error"
/// @ t4
void expression has no member "error"
/// @ t5
type "Test" has no member "error"
/// @@ test-slice-expression
/// @ t0
if ((13) < 0 || (13) >= (*str)->length) RAISE(1)
  c = ((*str)->values)[13];
/// @ t1
String aux_String_0_Var = {0};
  String** aux_String_0 = NULL;
  aux_String_0 = MR_new_ref();
  if (aux_String_0 == NULL) RAISE(1)
  *aux_String_0 = &aux_String_0_Var;
  aux_String_0_Var.length = 6;
  aux_String_0_Var.max_length = aux_String_0_Var.length + 1;
  aux_String_0_Var.values = (*str)->values + (2);
  if ((2) < 0 || (6) < 0 || (2) + (6) > (*str)->length) RAISE(1)
  str = aux_String_0;
/// @ t2
if ((13) < 0 || (13) >= (*arr)->length) RAISE(1)
  i = ((Int*)((*arr)->values))[13];
/// @ t3
Array aux_Array_0_Var = {0};
  Array** aux_Array_0 = NULL;
  aux_Array_0 = MR_new_ref();
  if (aux_Array_0 == NULL) RAISE(1)
  *aux_Array_0 = &aux_Array_0_Var;
  aux_Array_0_Var.length = 6;
  aux_Array_0_Var.values = (Byte*)((*arr)->values) + (2);
  if ((2) < 0 || (6) < 0 || (2) + (6) > (*arr)->length) RAISE(1)
  arr = aux_Array_0;
/// @ t4
if ((4) < 0 || (4) >= (*str)->length) RAISE(1)
  ((*str)->values)[4] = c;
/// @ t5
if ((4) < 0 || (4) >= (*arr)->length) RAISE(1)
  ((Int*)((*arr)->values))[4] = i;
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
CHECK(1, fun1(3, str, NULL) )
/// @ t2
CHECK(1, fun2(&(*so), &(*io)) )
/// @ t3
Int x = 0;
  String** s = NULL;
  CHECK(3, fun2(&(s), &(x)) )
/// @ t4
CHECK(1, fun3(0, &(*so)) )
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
String** aux_String_0 = NULL;
  CHECK(1, fun3(7, &(aux_String_0)) )
  *so = aux_String_0;
/// @ t10
CHECK(1, Tc_methc(tc, tc_Dynamic) )
/// @ t11
CHECK(1, Tb_methb((void*)tc, &(tc_Dynamic->_base)) )
/// @ t12
CHECK(1, Test_meth((void*)tc) )
/// @ t13
expected access, got " "
/// @ t14
expected space after access, got ")"
/// @ t15
expected space or new-line after ",", got "c"
/// @ t16
expected "," or ")", got "new-line"
/// @ t17
illegal access "error"
/// @ t18
void expression is not callable
/// @ t19
non callable type "Int"
/// @ t20
non assignable call output
/// @ t21
cannot assign "Tb" into "Tc"
/// @ t22
cannot assign void expression
/// @ t23
expected access "copy" , got "user"
/// @@ test-type-expression
/// @ t0
CHECK(1, Test_meth(t) )
/// @ t1
CHECK(1, Tb_methb((void*)tc, &(tc_Dynamic->_base)) )
/// @ t2
CHECK(1, Test_meth((void*)tc) )
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
Returncode Base_methb(Base** self);
Returncode Mid_methm(Mid** self);
Returncode Top_methb(Top** self);
Returncode Top_methm(Top** self);
Returncode Base_methb(Base** self) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Mid_methm(Mid** self) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Top_methb(Top** self) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Top_methm(Top** self) {
  Returncode MR_err = OK;
  CHECK(9, Mid_methm((void*)self) )
MR_cleanup:
  return MR_err;
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
Returncode Base_methb(Base** self);
Returncode Mid_methm(Mid** self);
Returncode Top_methb(Top** self);
Returncode Top_methm(Top** self);
Returncode Base_methb(Base** self) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Mid_methm(Mid** self) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Top_methb(Top** self) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Top_methm(Top** self) {
  Returncode MR_err = OK;
  CHECK(9, Base_methb((void*)self) )
MR_cleanup:
  return MR_err;
}
/// @ t2
"base" used not in method
/// @ t3
no base type for type "Test"
/// @ t4
cannot assign "Test" into "Base Symbol"
/// @ t5
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
t = (void*)tc;
/// @ t8
unknown operator "@"
/// @ t9
unexpected "("
/// @ t10
ambiguous precedence between operators "+" and "*"
/// @ t11
ambiguous precedence between operators "or" and "and"
/// @ t12
cannot use "not" as binary operand
/// @ t13
assigning into non assignable expression
/// @ t14
assigning into non assignable expression
/// @ t15
assigning into non assignable expression
/// @@ test-question-expression
/// @ t0
b = str != NULL;
/// @ t1
b = ! (str != NULL);
/// @ t2
cannot use "?" on void expression
/// @ t3
cannot use "?" on type "Int"
/// @@ test-dynamic
/// @ t0
Ta a_Var = {{0}};
  Ta** a = NULL;
  Ta_Dynamic* a_Dynamic = &Ta_dynamic;
  a = MR_new_ref();
  if (a == NULL) RAISE(1)
  *a = &a_Var;
  CHECK(1, Test_new((void*)a, 1) )
/// @ t1
Ta** a = NULL;
  Ta_Dynamic* a_Dynamic = NULL;
/// @ t2
Ta** aux_Ta_0 = NULL;
  Ta_Dynamic* aux_Ta_0_Dynamic = &Ta_dynamic;
  aux_Ta_0 = MR_new_ref();
  if (aux_Ta_0 == NULL) RAISE(1)
  *aux_Ta_0 = calloc(1, sizeof(Ta));
  if (*aux_Ta_0 == NULL) RAISE(1)
  CHECK(1, Test_new((void*)aux_Ta_0, 7) )
  ta_Dynamic = aux_Ta_0_Dynamic;
  ta = aux_Ta_0;
/// @ t3
Ta** a = NULL;
  Ta_Dynamic* a_Dynamic = &Ta_dynamic;
  a = MR_new_ref();
  if (a == NULL) RAISE(1)
  *a = calloc(1, sizeof(Ta));
  if (*a == NULL) RAISE(1)
  CHECK(1, Test_new((void*)a, 1) )
/// @ t4
Ta** a = NULL;
  Ta_Dynamic* a_Dynamic = NULL;
  a = ta;
  a_Dynamic = ta_Dynamic;
/// @ t5
ta_Dynamic = ta_Dynamic;
  ta = ta;
/// @ t6
ta_Dynamic = &(tb_Dynamic->_base);
  ta = (void*)tb;
/// @ t7
ta_Dynamic = &(tc_Dynamic->_base._base);
  ta = (void*)tc;
/// @ t8
ta_Dynamic = NULL;
  ta = NULL;
/// @ t9
Array** aa = NULL;
  if ((4) < 0 || (4) >= (*aa)->length) RAISE(2)
  ta_Dynamic = &Ta_dynamic;
  ta = ((Ta***)((*aa)->values))[4];
/// @ t10
Array** ca = NULL;
  if ((4) < 0 || (4) >= (*ca)->length) RAISE(2)
  ta_Dynamic = &(&Tc_dynamic->_base._base);
  ta = (void*)(((Tc***)((*ca)->values))[4]);
/// @ t11
if (ta_Dynamic == NULL) RAISE(1)
  CHECK(1, ta_Dynamic->dyn(ta, ta_Dynamic) )
/// @ t12
if (tb_Dynamic == NULL) RAISE(1)
  CHECK(1, tb_Dynamic->_base.dyn((void*)tb, &(tb_Dynamic->_base)) )
/// @ t13
if (tc_Dynamic == NULL) RAISE(1)
  CHECK(1, tc_Dynamic->_base._base.dyn((void*)tc, &(tc_Dynamic->_base._base)) )
/// @ t14
if (ta != NULL) RAISE(1)
  CHECK(1, fun7((void*)&(ta), (void*)&(ta_Dynamic)) )
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
Returncode (*fun)(Test** self) = NULL;
  fun = Test_meth;
  if (fun == NULL) RAISE(2)
  CHECK(2, fun(t) )
/// @ t3
Returncode (*fun)(void) = NULL;
  fun = NULL;
  b = fun != NULL;
/// @ t4
if (t == NULL || *t == NULL) RAISE(1)
  (*t)->fun = fun0;
  if (t == NULL || *t == NULL) RAISE(2)
  if ((*t)->fun == NULL) RAISE(2)
  CHECK(2, (*t)->fun() )
/// @ t5
Returncode (*farr_Values[38])(void);
  Array farr_Var = {38, NULL};
  Array** farr = NULL;
  farr = MR_new_ref();
  if (farr == NULL) RAISE(1)
  *farr = &farr_Var;
  farr_Var.values = farr_Values;
  if ((3) < 0 || (3) >= (*farr)->length) RAISE(2)
  ((Returncode (**)(void))((*farr)->values))[3] = fun0;
  if ((3) < 0 || (3) >= (*farr)->length) RAISE(3)
  if (((Returncode (**)(void))((*farr)->values))[3] == NULL) RAISE(3)
  CHECK(3, (((Returncode (**)(void))((*farr)->values))[3])() )
/// @ t6
missing arguments in function type
/// @ t7
missing arguments in function type
/// @ t8
expected "(" inside Function type, got "}"
/// @ t9
expected "}", got " "
/// @ t10
too many parameters
/// @ t11
too few outputs
/// @@ test-builtin
/// @ t0
CHECK(1, Int_str(i, str) )
/// @ t1
b = true;
/// @ t2
b = false;
/// @ t3
c = EOF;
/// @ t4
if (arr == NULL || *arr == NULL) RAISE(1)
  i = (*arr)->length;
/// @ t5
if (str == NULL || *str == NULL) RAISE(1)
  i = (*str)->length;
/// @ t6
CHECK(1, String_clear(str) )
/// @ t7
CHECK(1, String_equal(str, str, &(b)) )
/// @ t8
CHECK(1, String_get(str, i, &(c)) )
/// @ t9
CHECK(1, String_append(str, c) )
/// @ t10
CHECK(1, String_new(str, str) )
/// @ t11
CHECK(1, String_concat(str, str) )
/// @ t12
CHECK(1, String_concat_int(str, i) )
/// @ t13
CHECK(1, String_find(str, str, &(i)) )
/// @ t14
CHECK(1, String_has(str, c, &(b)) )
/// @ t15
CHECK(1, file_open_read(str, &(fobj)) )
/// @ t16
CHECK(1, file_open_write(str, &(fobj)) )
/// @ t17
CHECK(1, File_close(fobj) )
/// @ t18
CHECK(1, File_getc(fobj, &(c)) )
/// @ t19
CHECK(1, File_putc(fobj, c) )
/// @ t20
CHECK(1, File_write(fobj, str) )
/// @ t21
Array** argv = NULL;
  if (sys == NULL || *sys == NULL) RAISE(1)
  argv = (*sys)->argv;
/// @ t22
CHECK(1, Sys_print(sys, str) )
/// @ t23
CHECK(1, Sys_println(sys, str) )
/// @ t24
CHECK(1, Sys_exit(sys, i) )
/// @ t25
CHECK(1, Sys_system(sys, str, &(i)) )
/// @ t26
CHECK(1, Sys_getenv(sys, str, str, &(b)) )
/// @
