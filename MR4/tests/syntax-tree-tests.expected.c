/// @@ test-general
/// @ t0
String* str = NULL;
RefManager* str_Refman = NULL;
/// @ t1
Int x = 0;
/// @ t2
Int x = 0;
/// @ t3
Int x = 0;
/// @ t4
Int x = 0;
/// @ t5
Int x = 0;
/// @ t6
unknown keyword "error"
/// @ t7
statememnt has no effect
/// @ t8
unreachable code
/// @ t9
unreachable code
/// @ t10
expected new-line in line end, got "?"
/// @ t11
expected new-line after "main", got "("
/// @ t12
indentation too big, expected "0" got "2"
/// @ t13
too short indentation, expected "6" got "4"
/// @ t14
no new-line before file end
/// @ t15
redefinition of global variable "name"
/// @ t16
variable name overrides function "name"
/// @@ test-struct
/// @ t0
typedef struct Test Test;
struct Test {
  Int x;
};
/// @ t1
typedef struct Test Test;
struct Test {
  Int x;
};
/// @ t2
typedef struct Test1 Test1;
typedef struct Test2 Test2;
typedef struct Test3 Test3;
struct Test1 {
  Int x;
};
struct Test2 {
  Int x;
};
struct Test3 {
  Int x;
};
/// @ t3
typedef struct Test1 Test1;
typedef struct Test2 Test2;
struct Test1 {
  Int x;
};
struct Test2 {
  Test1 _base;
  Int y;
};
/// @ te0
expected space after "struct", got "("
/// @ te1
illegal type name "error"
/// @ te2
illegal type name "ERrror"
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
/// @@ test-class
/// @ t0
typedef struct Base Base;
typedef struct Base_Dynamic Base_Dynamic;
typedef struct Mid Mid;
typedef struct Mid_Dynamic Mid_Dynamic;
typedef struct Top Top;
typedef struct Top_Dynamic Top_Dynamic;
struct Base {
  Int x;
};
struct Base_Dynamic {
  Returncode (*dyn0)(Base* self, RefManager* self_Refman, Base_Dynamic* self_Dynamic);
  Returncode (*dyn1)(Base* self, RefManager* self_Refman, Base_Dynamic* self_Dynamic);
};
struct Mid {
  Base _base;
  Int y;
};
struct Mid_Dynamic {
  Base_Dynamic _base;
  Returncode (*dyn2)(Mid* self, RefManager* self_Refman, Mid_Dynamic* self_Dynamic);
};
struct Top {
  Mid _base;
  Int z;
};
struct Top_Dynamic {
  Mid_Dynamic _base;
  Returncode (*dyn3)(Top* self, RefManager* self_Refman, Top_Dynamic* self_Dynamic);
};
Returncode Base_stat(Base* self, RefManager* self_Refman, Base_Dynamic* self_Dynamic);
Returncode Base_dyn0(Base* self, RefManager* self_Refman, Base_Dynamic* self_Dynamic);
Returncode Base_dyn1(Base* self, RefManager* self_Refman, Base_Dynamic* self_Dynamic);
Returncode Mid_dyn0(Mid* self, RefManager* self_Refman, Mid_Dynamic* self_Dynamic);
Returncode Mid_dyn2(Mid* self, RefManager* self_Refman, Mid_Dynamic* self_Dynamic);
Returncode Top_dyn0(Top* self, RefManager* self_Refman, Top_Dynamic* self_Dynamic);
Returncode Top_dyn3(Top* self, RefManager* self_Refman, Top_Dynamic* self_Dynamic);
Base_Dynamic Base_dynamic = {Base_dyn0, Base_dyn1};
Mid_Dynamic Mid_dynamic = {{(Func)Mid_dyn0, Base_dyn1}, Mid_dyn2};
Top_Dynamic Top_dynamic = {{{(Func)Top_dyn0, Base_dyn1}, Mid_dyn2}, Top_dyn3};
Returncode Base_stat(Base* self, RefManager* self_Refman, Base_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Base_dyn0(Base* self, RefManager* self_Refman, Base_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Base_dyn1(Base* self, RefManager* self_Refman, Base_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Mid_dyn0(Mid* self, RefManager* self_Refman, Mid_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Mid_dyn2(Mid* self, RefManager* self_Refman, Mid_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Top_dyn0(Top* self, RefManager* self_Refman, Top_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  CHECK(13, Mid_dyn0(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
MR_cleanup:
  return MR_err;
}
Returncode Top_dyn3(Top* self, RefManager* self_Refman, Top_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  CHECK(15, Mid_dyn0(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
MR_cleanup:
  return MR_err;
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
Returncode name(void);
Returncode name(void) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
/// @ t1
Returncode name(String* self, RefManager* self_Refman, String* text, RefManager* text_Refman, Int num);
Returncode name(String* self, RefManager* self_Refman, String* text, RefManager* text_Refman, Int num) {
  Returncode MR_err = OK;
  MR_inc_ref(text_Refman);
MR_cleanup:
  MR_dec_ref(text_Refman);
  return MR_err;
}
/// @ t2
Returncode name(String** text, RefManager** text_Refman, Int* num);
Returncode name(String** text, RefManager** text_Refman, Int* num) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
/// @ t3
Returncode name(Char param, String** out, RefManager** out_Refman);
Returncode name(Char param, String** out, RefManager** out_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
/// @ t4
Returncode name(Array* array, RefManager* array_Refman);
Returncode name(Array* array, RefManager* array_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(array_Refman);
MR_cleanup:
  MR_dec_ref(array_Refman);
  return MR_err;
}
/// @ t5
Returncode name(Returncode (*fun)(Int x, Int* y), Returncode (**joy)(void));
Returncode name(Returncode (*fun)(Int x, Int* y), Returncode (**joy)(void)) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
/// @ t6
Returncode name(void);
Returncode name(void) {
  Returncode MR_err = OK;
  Int x = 0;
MR_cleanup:
  return MR_err;
}
/// @ t7
Returncode name(String* self, RefManager* self_Refman, Int px, String* pu, RefManager* pu_Refman, String* po, RefManager* po_Refman, String** oself, RefManager** oself_Refman, Int* ox, String** ou, RefManager** ou_Refman, String** oo, RefManager** oo_Refman);
Returncode name(String* self, RefManager* self_Refman, Int px, String* pu, RefManager* pu_Refman, String* po, RefManager* po_Refman, String** oself, RefManager** oself_Refman, Int* ox, String** ou, RefManager** ou_Refman, String** oo, RefManager** oo_Refman) {
  Returncode MR_err = OK;
  Int x = 0;
  String* u = NULL;
  RefManager* u_Refman = NULL;
  String* o = NULL;
  RefManager* o_Refman = NULL;
  char v_Values[12];
  String v_Var = {12, 0, NULL};
  String* v = NULL;
  RefManager* v_Refman = NULL;
  String* n = NULL;
  RefManager* n_Refman = NULL;
  String* aux_String_0 = NULL;
  RefManager* aux_String_0_Refman = NULL;
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  RefManager* aux_String_1_Refman = NULL;
  String aux_String_2_Var = {0};
  String* aux_String_2 = NULL;
  RefManager* aux_String_2_Refman = NULL;
  MR_inc_ref(pu_Refman);
  MR_inc_ref(po_Refman);
  v = &v_Var;
  v_Var.values = v_Values;
  v_Refman = MR_new_ref(v);
  if (v_Refman == NULL) RAISE(6)
  n = MR_new_string(12);
  if (n == NULL) RAISE(7)
  n_Refman = MR_new_ref(n);
  if (n_Refman == NULL) RAISE(7)
  aux_String_0 = MR_new_string(12);
  if (aux_String_0 == NULL) RAISE(8)
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(8)
  MR_owner_dec_ref(o_Refman);
  o_Refman = aux_String_0_Refman;
  aux_String_0_Refman = NULL;
  o = aux_String_0;
  aux_String_0 = NULL;
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = MR_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(9)
  aux_String_1_Var.max_length = 16;
  aux_String_1_Var.length = 15;
  aux_String_1_Var.values = "constant string";
  MR_dec_ref(u_Refman);
  u_Refman = aux_String_1_Refman;
  MR_inc_ref(u_Refman);
  u = aux_String_1;
  aux_String_2 = &aux_String_2_Var;
  aux_String_2_Refman = MR_new_ref(aux_String_2);
  if (aux_String_2_Refman == NULL) RAISE(10)
  aux_String_2_Var.length = 6;
  aux_String_2_Var.max_length = aux_String_2_Var.length + 1;
  aux_String_2_Var.values = (po)->values + (2);
  if (po == NULL || po_Refman->value == NULL) RAISE(10)
  if ((2) < 0 || (6) < 0 || (2) + (6) > (po)->length) RAISE(10)
  MR_dec_ref(pu_Refman);
  pu_Refman = po_Refman;
  MR_inc_ref(pu_Refman);
  pu = aux_String_2;
MR_cleanup:
  MR_dec_ref(aux_String_2_Refman);
  MR_dec_ref(aux_String_1_Refman);
  MR_owner_dec_ref(aux_String_0_Refman);
  MR_owner_dec_ref(n_Refman);
  MR_dec_ref(v_Refman);
  MR_owner_dec_ref(o_Refman);
  MR_dec_ref(u_Refman);
  MR_owner_dec_ref(po_Refman);
  MR_dec_ref(pu_Refman);
  return MR_err;
}
/// @ tm0
USER_MAIN_HEADER {
  Returncode MR_err = OK;
  Int x = 0;
MR_cleanup:
  return MR_err;
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
indentation too big, expected "2" got "4"
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
/// @@ test-members
/// @ t0
typedef struct Test Test;
struct Test {
  Int x;
  String* str;
  RefManager* str_Refman;
};
/// @ t1
typedef struct Test Test;
struct Test {
  Int x;
};
Returncode Test_name(Test* self, RefManager* self_Refman);
Returncode Test_name(Test* self, RefManager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
/// @ t2
typedef struct Test Test;
struct Test {
  Int x;
};
Returncode Test_name(Test* self, RefManager* self_Refman);
Returncode Test_name(Test* self, RefManager* self_Refman) {
  Returncode MR_err = OK;
  Int x = 0;
MR_cleanup:
  return MR_err;
}
/// @ t3
typedef struct Test Test;
struct Test {
  Int x;
};
/// @ t4
typedef struct Test Test;
struct Test {
  Int x;
};
/// @ t5
typedef struct Test Test;
struct Test {
  Int x;
};
/// @ t6
typedef struct Test Test;
struct Test {
  Int x;
};
/// @ t7
typedef struct Test1 Test1;
typedef struct Test2 Test2;
struct Test1 {
  Int name;
};
struct Test2 {
  Int fun;
};
Returncode Test1_fun(Test1* self, RefManager* self_Refman);
Returncode Test2_name(Test2* self, RefManager* self_Refman);
Int name = 0;
Returncode fun(void);
Returncode Test1_fun(Test1* self, RefManager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Test2_name(Test2* self, RefManager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun(void) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
/// @ t8
redefinition of field "name"
/// @ t9
field name overrides method "name"
/// @ t10
redefinition of method "name"
/// @ t11
method name overrides field "name"
/// @@ test-return
/// @ t0
Returncode name(void);
Returncode name(void) {
  Returncode MR_err = OK;
  goto MR_cleanup;
MR_cleanup:
  return MR_err;
}
/// @ t1
Returncode name(void);
Returncode name(void) {
  Returncode MR_err = OK;
  RAISE(2)
MR_cleanup:
  return MR_err;
}
/// @ te0
expected new-line after "return", got "("
/// @ te1
expected new-line after "raise", got "("
/// @@ test-code-variables
/// @ t0
Int x = 0;
/// @ t1
String* s = NULL;
  RefManager* s_Refman = NULL;
/// @ t2
Array* a = NULL;
  RefManager* a_Refman = NULL;
/// @ t3
Test* tt = NULL;
  RefManager* tt_Refman = NULL;
/// @ t4
char s_Values[12];
  String s_Var = {12, 0, NULL};
  String* s = NULL;
  RefManager* s_Refman = NULL;
  s = &s_Var;
  s_Var.values = s_Values;
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(1)
/// @ t5
Int a_Values[12];
  Array a_Var = {12, NULL};
  Array* a = NULL;
  RefManager* a_Refman = NULL;
  a = &a_Var;
  a_Var.values = a_Values;
  a_Refman = MR_new_ref(a);
  if (a_Refman == NULL) RAISE(1)
/// @ t6
Test a_Values[12];
  Array a_Var = {12, NULL};
  Array* a = NULL;
  RefManager* a_Refman = NULL;
  a = &a_Var;
  a_Var.values = a_Values;
  a_Refman = MR_new_ref(a);
  if (a_Refman == NULL) RAISE(1)
/// @ t7
char sa_Chars[12 * 7];
  String sa_Values[12];
  Array sa_Var = {12, NULL};
  Array* sa = NULL;
  RefManager* sa_Refman = NULL;
  sa = &sa_Var;
  sa_Var.values = sa_Values;
  MR_set_var_string_array(12, 7, sa, sa_Chars);
  sa_Refman = MR_new_ref(sa);
  if (sa_Refman == NULL) RAISE(1)
/// @ t8
String* s = NULL;
  RefManager* s_Refman = NULL;
  s = MR_new_string(12);
  if (s == NULL) RAISE(1)
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(1)
  MR_owner_dec_ref(*so_Refman);
  *so_Refman = s_Refman;
  s_Refman = NULL;
  *so = s;
  s = NULL;
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
global variables cannot be initialized
/// @ te9
non-primitives cannot be declared "var" here yet...
/// @ te10
expected space after "new", got "new-line"
/// @@ test-initialize
/// @ t0
Test* aux_Test_0 = NULL;
  RefManager* aux_Test_0_Refman = NULL;
  aux_Test_0 = calloc(1, sizeof(Test));
  if (aux_Test_0 == NULL) RAISE(1)
  aux_Test_0_Refman = MR_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(1)
  CHECK(1, Test_new(aux_Test_0, aux_Test_0_Refman, i) )
  MR_dec_ref(t_Refman);
  t_Refman = aux_Test_0_Refman;
  MR_inc_ref(t_Refman);
  t = aux_Test_0;
/// @ t1
String* aux_String_0 = NULL;
  RefManager* aux_String_0_Refman = NULL;
  if (arr == NULL || arr_Refman->value == NULL) RAISE(1)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)
  aux_String_0 = MR_new_string(((Int*)((arr)->values))[0]);
  if (aux_String_0 == NULL) RAISE(1)
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(1)
  MR_dec_ref(str_Refman);
  str_Refman = aux_String_0_Refman;
  MR_inc_ref(str_Refman);
  str = aux_String_0;
/// @ t2
Array* aux_Array_0 = NULL;
  RefManager* aux_Array_0_Refman = NULL;
  if (arr == NULL || arr_Refman->value == NULL) RAISE(1)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)
  aux_Array_0 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if (aux_Array_0 == NULL) RAISE(1)
  aux_Array_0_Refman = MR_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(1)
  MR_dec_ref(arr_Refman);
  arr_Refman = aux_Array_0_Refman;
  MR_inc_ref(arr_Refman);
  arr = aux_Array_0;
/// @ t3
Array* a = NULL;
  RefManager* a_Refman = NULL;
  Array* aux_Array_0 = NULL;
  RefManager* aux_Array_0_Refman = NULL;
  if (arr == NULL || arr_Refman->value == NULL) RAISE(1)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)
  aux_Array_0 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Test));
  if (aux_Array_0 == NULL) RAISE(1)
  aux_Array_0_Refman = MR_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(1)
  a = aux_Array_0;
  a_Refman = aux_Array_0_Refman;
  aux_Array_0 = NULL;
  aux_Array_0_Refman = NULL;
/// @ t4
Array* sa = NULL;
  RefManager* sa_Refman = NULL;
  Array* aux_Array_0 = NULL;
  RefManager* aux_Array_0_Refman = NULL;
  if (arr == NULL || arr_Refman->value == NULL) RAISE(1)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)
  if (arr == NULL || arr_Refman->value == NULL) RAISE(1)
  if ((1) < 0 || (1) >= (arr)->length) RAISE(1)
  aux_Array_0 = MR_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]);
  if (aux_Array_0 == NULL) RAISE(1)
  aux_Array_0_Refman = MR_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(1)
  sa = aux_Array_0;
  sa_Refman = aux_Array_0_Refman;
  aux_Array_0 = NULL;
  aux_Array_0_Refman = NULL;
/// @ t5
Int x = 0;
  if (arr == NULL || arr_Refman->value == NULL) RAISE(1)
  if ((0) < 0 || (0) >= (arr)->length) RAISE(1)
  x = ((Int*)((arr)->values))[0];
/// @ t6
String* s = NULL;
  RefManager* s_Refman = NULL;
  s = str;
  s_Refman = str_Refman;
  MR_inc_ref(s_Refman);
/// @ t7
char s_Values[12];
  String s_Var = {12, 0, NULL};
  String* s = NULL;
  RefManager* s_Refman = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  RefManager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(1)
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  s = &s_Var;
  s_Var.values = s_Values;
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(1)
  CHECK(1, String_new(s, s_Refman, aux_String_0, aux_String_0_Refman) )
/// @ t8
String* s = NULL;
  RefManager* s_Refman = NULL;
  s = MR_new_string(i);
  if (s == NULL) RAISE(1)
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(1)
  CHECK(1, String_new(s, s_Refman, str, str_Refman) )
/// @ t9
Test* tt = NULL;
  RefManager* tt_Refman = NULL;
  tt = &(tc->_base._base._base);
  tt_Refman = tc_Refman;
  MR_inc_ref(tt_Refman);
/// @ t10
Test tt_Var = {0};
  Test* tt = NULL;
  RefManager* tt_Refman = NULL;
  tt = &tt_Var;
  tt_Refman = MR_new_ref(tt);
  if (tt_Refman == NULL) RAISE(1)
  CHECK(1, Test_new(tt, tt_Refman, 3) )
/// @ t11
Test* tt = NULL;
  RefManager* tt_Refman = NULL;
  tt = calloc(1, sizeof(Test));
  if (tt == NULL) RAISE(1)
  tt_Refman = MR_new_ref(tt);
  if (tt_Refman == NULL) RAISE(1)
  CHECK(1, Test_new(tt, tt_Refman, 3) )
/// @ t12
Test* aux_Test_0 = NULL;
  RefManager* aux_Test_0_Refman = NULL;
  aux_Test_0 = calloc(1, sizeof(Test));
  if (aux_Test_0 == NULL) RAISE(1)
  aux_Test_0_Refman = MR_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(1)
  CHECK(1, Test_new(aux_Test_0, aux_Test_0_Refman, 3) )
  MR_dec_ref(t_Refman);
  t_Refman = aux_Test_0_Refman;
  MR_inc_ref(t_Refman);
  t = aux_Test_0;
/// @ t13
Tb* tt = NULL;
  RefManager* tt_Refman = NULL;
  Tb_Dynamic* tt_Dynamic = NULL;
  tt = tb;
  tt_Refman = tb_Refman;
  MR_inc_ref(tt_Refman);
  tt_Dynamic = tb_Dynamic;
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
expected ":", got "new-line"
/// @ te11
expected "}", got "new-line"
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
if (t == NULL || t_Refman->value == NULL) RAISE(1)
  if (t->num > 3) {
    i -= 2;
  }
/// @ t1
if (i > 3) {
    i -= 2;
  }
  else {
    i += 1;
  }
/// @ t2
if (i > 3) {
    i -= 3;
  }
  else {
    if (t == NULL || t_Refman->value == NULL) RAISE(3)
    if (t->num > 2) {
      i -= 2;
    }
    else {
      if (t == NULL || t_Refman->value == NULL) RAISE(5)
      if (t->num > 1) {
        i -= 1;
      }
      else {
        i += 1;
      }
    }
  }
/// @ t3
if (b) {
    goto MR_cleanup;
  }
  i = 3;
/// @ t4
got "Int" expression, expected "Bool"
/// @ t5
unknown symbol "error"
/// @ t6
unknown symbol "error"
/// @ t7
unknown symbol "error"
/// @ t8
unreachable code
/// @ t9
expected space after "if", got "("
/// @ t10
"else" without a previous "if"
/// @ t11
expected new-line after "else", got " "
/// @ t12
"else-if" without a previous "if"
/// @ t13
expected space after "else-if", got "("
/// @@ test-do-loop
/// @ t0
Int x = 0;
  while (true) {
  }
/// @ t1
Int x = 0;
/// @ t2
while (true) {
    if (t == NULL || t_Refman->value == NULL) RAISE(2)
    if (!(t->num > 3)) break;
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
{int n; for(n=0; n<5; ++n) {
    i += n;
  }
  }
/// @ t1
if (t == NULL || t_Refman->value == NULL) RAISE(1)
  if (t == NULL || t_Refman->value == NULL) RAISE(1)
  {int n; for(n=t->num; n<t->num + 2; ++n) {
    i += n;
  }
  }
/// @ t2
expected space after "for", got "("
/// @ t3
expected space after index name, got "new-line"
/// @ t4
expected "in " got "err"
/// @ t5
got "String" expression, expected "Int"
/// @ t6
got "String" expression, expected "Int"
/// @ t7
unknown symbol "error"
/// @@ test-testing
/// @ t0
if (t == NULL || t_Refman->value == NULL) RAISE(1)
  TEST_ASSERT(1, t->num == 2)
/// @ t1
do {
    MR_trace_stream = NULL;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (t == NULL || t_Refman->value == NULL) RAISE(1)
    #undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    MR_trace_stream = stdout;
    TEST_FAIL(1)
  } while (false);
  MR_trace_stream = stdout;
/// @ t2
do {
    MR_trace_stream = NULL;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(1, fun0() )
    #undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    MR_trace_stream = stdout;
    TEST_FAIL(1)
  } while (false);
  MR_trace_stream = stdout;
/// @ t3
Returncode fun(void);
Returncode Mock_fun(void);
Returncode fun(void) {
  Returncode MR_err = OK;
  CHECK(2, Mock_fun() )
MR_cleanup:
  return MR_err;
}
Returncode Mock_fun(void) {
  Returncode MR_err = OK;
  RAISE(4)
MR_cleanup:
  return MR_err;
}
/// @ t4
Returncode Mock_fun(void);
Returncode fun(void);
Returncode Mock_fun(void) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun(void) {
  Returncode MR_err = OK;
  CHECK(3, Mock_fun() )
MR_cleanup:
  return MR_err;
}
/// @ t5
typedef struct Test Test;
struct Test {
  Int x;
};
Returncode Test_meth(Test* self, RefManager* self_Refman, Int x);
Returncode Test_Mock_meth(Test* self, RefManager* self_Refman, Int x);
Returncode Test_meth(Test* self, RefManager* self_Refman, Int x) {
  Returncode MR_err = OK;
  CHECK(5, Test_Mock_meth(self, self_Refman, x) )
MR_cleanup:
  return MR_err;
}
Returncode Test_Mock_meth(Test* self, RefManager* self_Refman, Int x) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
/// @ t6
Returncode fun0(void);
Returncode fun1(void);
Returncode fun0(void) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun1(void) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
USER_MAIN_HEADER {
  Bool MR_success = true;
  RUN_TEST(fun0);
  RUN_TEST(fun1);
  return MR_success? OK : FAIL;
}
TEST_MAIN_FUNC
/// @ t7
Returncode fun0(void);
Returncode fun1(void);
Returncode fun0(void) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun1(void) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
USER_MAIN_HEADER {
  Bool MR_success = true;
  RUN_TEST(fun0);
  RUN_TEST(fun1);
  return MR_success? OK : FAIL;
}
TEST_MAIN_FUNC
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
/// @@ test-native
/// @ t0
Returncode external(void);
/// @ te0
expected space after "native", got "("
/// @
