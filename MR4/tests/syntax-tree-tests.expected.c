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
/// @ te20
too short indentation, expected "4" got "2"
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
/// @ tf0
Returncode external(void);
Returncode call(void);
Returncode call(void) {
  Returncode MR_err = OK;
  CHECK(3, external() )
MR_cleanup:
  return MR_err;
}
/// @ tf1
typedef struct Test Test;
typedef struct Test_Dynamic Test_Dynamic;
struct Test {
  Int x;
};
struct Test_Dynamic {
  Returncode (*meth)(Test* self, RefManager* self_Refman, Test_Dynamic* self_Dynamic);
};
Returncode Test_meth(Test* self, RefManager* self_Refman, Test_Dynamic* self_Dynamic);
Test_Dynamic Test_dynamic = {Test_meth};
Returncode external(Int i, String* s, Test* ta, Int* io);
Returncode call(void);
Returncode Test_meth(Test* self, RefManager* self_Refman, Test_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode call(void) {
  Returncode MR_err = OK;
  Int i = 0;
  String* s = NULL;
  RefManager* s_Refman = NULL;
  Test* ta = NULL;
  RefManager* ta_Refman = NULL;
  Test_Dynamic* ta_Dynamic = NULL;
  CHECK(9, external(5, s, ta, &(i)) )
MR_cleanup:
  MR_dec_ref(ta_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
/// @ tv0
extern Int x;
/// @ tt0
typedef void* Native;
Returncode external(Native n, Native* no);
/// @ te0
expected space after "native", got "("
/// @ te1
expected space after "native" keyword, got "EOF"
/// @ te2
unknown "native" keyword "error"
/// @ tef1
owner argument to native function
/// @ tef2
user output to native function
/// @ tef3
owner argument to native function
/// @ tev3
only primitive types supported for native variable, got "String"
/// @@ test-parameter-type
/// @ t0
typedef struct Test Test;
struct Test {
  Generic_Type* item;
  RefManager* item_Refman;
  Array* arr;
  RefManager* arr_Refman;
};
Returncode Test_set(Test* self, RefManager* self_Refman, Generic_Type* item, RefManager* item_Refman, Array* arr, RefManager* arr_Refman);
Returncode Test_set(Test* self, RefManager* self_Refman, Generic_Type* item, RefManager* item_Refman, Array* arr, RefManager* arr_Refman) {
  Returncode MR_err = OK;
  Generic_Type* x = NULL;
  RefManager* x_Refman = NULL;
  Generic_Type* y = NULL;
  RefManager* y_Refman = NULL;
  Test* t = NULL;
  RefManager* t_Refman = NULL;
  MR_inc_ref(item_Refman);
  MR_inc_ref(arr_Refman);
  x = item;
  x_Refman = item_Refman;
  item = NULL;
  item_Refman = NULL;
  if (self == NULL || self_Refman->value == NULL) RAISE(6)
  MR_owner_dec_ref(self->item_Refman);
  self->item_Refman = x_Refman;
  x_Refman = NULL;
  self->item = x;
  x = NULL;
  if (self == NULL || self_Refman->value == NULL) RAISE(7)
  MR_dec_ref(self->arr_Refman);
  self->arr_Refman = arr_Refman;
  MR_inc_ref(self->arr_Refman);
  self->arr = arr;
  if (arr == NULL || arr_Refman->value == NULL) RAISE(9)
  if ((2) < 0 || (2) >= (arr)->length) RAISE(9)
  MR_dec_ref(y_Refman);
  y_Refman = arr_Refman;
  MR_inc_ref(y_Refman);
  y = ((Generic_Type**)((arr)->values))[2];
  t = calloc(1, sizeof(Test));
  if (t == NULL) RAISE(10)
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(10)
  if (self == NULL || self_Refman->value == NULL) RAISE(11)
  if (t == NULL || t_Refman->value == NULL) RAISE(11)
  MR_owner_dec_ref(t->item_Refman);
  t->item_Refman = self->item_Refman;
  self->item_Refman = NULL;
  t->item = self->item;
  self->item = NULL;
  if (t == NULL || t_Refman->value == NULL) RAISE(12)
  if (self == NULL || self_Refman->value == NULL) RAISE(12)
  MR_owner_dec_ref(self->item_Refman);
  self->item_Refman = t->item_Refman;
  t->item_Refman = NULL;
  self->item = t->item;
  t->item = NULL;
MR_cleanup:
  MR_owner_dec_ref(t_Refman);
  MR_dec_ref(y_Refman);
  MR_owner_dec_ref(x_Refman);
  MR_dec_ref(arr_Refman);
  MR_owner_dec_ref(item_Refman);
  return MR_err;
}
/// @ t1
typedef struct Test Test;
struct Test {
  Generic_Type* item;
  RefManager* item_Refman;
};
Returncode Test_get(Test* self, RefManager* self_Refman, Generic_Type** item, RefManager** item_Refman);
Returncode Test_get(Test* self, RefManager* self_Refman, Generic_Type** item, RefManager** item_Refman) {
  Returncode MR_err = OK;
  if (self == NULL || self_Refman->value == NULL) RAISE(4)
  MR_dec_ref(*item_Refman);
  *item_Refman = self->item_Refman;
  MR_inc_ref(*item_Refman);
  *item = self->item;
MR_cleanup:
  return MR_err;
}
/// @ t2
typedef struct Test Test;
struct Test {
  Generic_Type* first;
  RefManager* first_Refman;
  Generic_Type* second;
  RefManager* second_Refman;
  Generic_Type* third;
  RefManager* third_Refman;
};
Returncode Test_set(Test* self, RefManager* self_Refman, Generic_Type* first, RefManager* first_Refman, Generic_Type* second, RefManager* second_Refman, Generic_Type* third, RefManager* third_Refman);
Returncode use(String* first, RefManager* first_Refman, Array* second, RefManager* second_Refman, File* third, RefManager* third_Refman);
Returncode Test_set(Test* self, RefManager* self_Refman, Generic_Type* first, RefManager* first_Refman, Generic_Type* second, RefManager* second_Refman, Generic_Type* third, RefManager* third_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(first_Refman);
  MR_inc_ref(second_Refman);
  MR_inc_ref(third_Refman);
  if (self == NULL || self_Refman->value == NULL) RAISE(6)
  MR_dec_ref(self->first_Refman);
  self->first_Refman = first_Refman;
  MR_inc_ref(self->first_Refman);
  self->first = first;
  if (self == NULL || self_Refman->value == NULL) RAISE(7)
  MR_dec_ref(self->second_Refman);
  self->second_Refman = second_Refman;
  MR_inc_ref(self->second_Refman);
  self->second = second;
  if (self == NULL || self_Refman->value == NULL) RAISE(8)
  MR_dec_ref(self->third_Refman);
  self->third_Refman = third_Refman;
  MR_inc_ref(self->third_Refman);
  self->third = third;
MR_cleanup:
  MR_dec_ref(third_Refman);
  MR_dec_ref(second_Refman);
  MR_dec_ref(first_Refman);
  return MR_err;
}
Returncode use(String* first, RefManager* first_Refman, Array* second, RefManager* second_Refman, File* third, RefManager* third_Refman) {
  Returncode MR_err = OK;
  Test t_Var = {0};
  Test* t = NULL;
  RefManager* t_Refman = NULL;
  MR_inc_ref(first_Refman);
  MR_inc_ref(second_Refman);
  MR_inc_ref(third_Refman);
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(10)
  if (t == NULL || t_Refman->value == NULL) RAISE(11)
  MR_dec_ref(t->first_Refman);
  t->first_Refman = first_Refman;
  MR_inc_ref(t->first_Refman);
  t->first = first;
  if (t == NULL || t_Refman->value == NULL) RAISE(12)
  MR_dec_ref(t->second_Refman);
  t->second_Refman = second_Refman;
  MR_inc_ref(t->second_Refman);
  t->second = second;
  if (t == NULL || t_Refman->value == NULL) RAISE(13)
  MR_dec_ref(t->third_Refman);
  t->third_Refman = third_Refman;
  MR_inc_ref(t->third_Refman);
  t->third = third;
  CHECK(14, Test_set(t, t_Refman, first, first_Refman, second, second_Refman, third, third_Refman) )
MR_cleanup:
  MR_dec_ref(t_Refman);
  MR_dec_ref(third_Refman);
  MR_dec_ref(second_Refman);
  MR_dec_ref(first_Refman);
  return MR_err;
}
/// @ t3
typedef struct Base Base;
typedef struct Test Test;
struct Base {
  Int x;
};
struct Test {
  Base _base;
};
/// @ t4
if (d == NULL || d_Refman->value == NULL) RAISE(1)
  MR_dec_ref(d->item_Refman);
  d->item_Refman = str_Refman;
  MR_inc_ref(d->item_Refman);
  d->item = str;
/// @ t5
if (d == NULL || d_Refman->value == NULL) RAISE(1)
  MR_dec_ref(str_Refman);
  str_Refman = d->item_Refman;
  MR_inc_ref(str_Refman);
  str = d->item;
/// @ t6
if (d == NULL || d_Refman->value == NULL) RAISE(1)
  MR_dec_ref(d->arr_Refman);
  d->arr_Refman = sarr_Refman;
  MR_inc_ref(d->arr_Refman);
  d->arr = sarr;
/// @ t7
if (d == NULL || d_Refman->value == NULL) RAISE(1)
  if (d->arr == NULL || d->arr_Refman->value == NULL) RAISE(1)
  if ((4) < 0 || (4) >= (d->arr)->length) RAISE(1)
  MR_dec_ref(str_Refman);
  str_Refman = d->arr_Refman;
  MR_inc_ref(str_Refman);
  str = ((String**)((d->arr)->values))[4];
/// @ t8
Data ad_Values[5];
  Array ad_Var = {5, NULL};
  Array* ad = NULL;
  RefManager* ad_Refman = NULL;
  ad = &ad_Var;
  ad_Var.values = ad_Values;
  ad_Refman = MR_new_ref(ad);
  if (ad_Refman == NULL) RAISE(1)
  if (ad == NULL || ad_Refman->value == NULL) RAISE(2)
  if ((2) < 0 || (2) >= (ad)->length) RAISE(2)
  if (((Data**)((ad)->values))[2] == NULL || ad_Refman->value == NULL) RAISE(2)
  MR_dec_ref(str_Refman);
  str_Refman = (((Data**)((ad)->values))[2])->item_Refman;
  MR_inc_ref(str_Refman);
  str = (((Data**)((ad)->values))[2])->item;
/// @ t9
Data ad_Values[5];
  Array ad_Var = {5, NULL};
  Array* ad = NULL;
  RefManager* ad_Refman = NULL;
  ad = &ad_Var;
  ad_Var.values = ad_Values;
  ad_Refman = MR_new_ref(ad);
  if (ad_Refman == NULL) RAISE(1)
  if (ad == NULL || ad_Refman->value == NULL) RAISE(2)
  if ((2) < 0 || (2) >= (ad)->length) RAISE(2)
  if (((Data**)((ad)->values))[2] == NULL || ad_Refman->value == NULL) RAISE(2)
  if ((((Data**)((ad)->values))[2])->arr == NULL || (((Data**)((ad)->values))[2])->arr_Refman->value == NULL) RAISE(2)
  if ((3) < 0 || (3) >= ((((Data**)((ad)->values))[2])->arr)->length) RAISE(2)
  MR_dec_ref(str_Refman);
  str_Refman = (((Data**)((ad)->values))[2])->arr_Refman;
  MR_inc_ref(str_Refman);
  str = ((String**)(((((Data**)((ad)->values))[2])->arr)->values))[3];
/// @ t10
Data da_Var = {0};
  Data* da = NULL;
  RefManager* da_Refman = NULL;
  da = &da_Var;
  da_Refman = MR_new_ref(da);
  if (da_Refman == NULL) RAISE(1)
  if (da == NULL || da_Refman->value == NULL) RAISE(2)
  if (da->item == NULL || da->item_Refman->value == NULL) RAISE(2)
  if ((1) < 0 || (1) >= (((Array*)(da->item)))->length) RAISE(2)
  MR_dec_ref(str_Refman);
  str_Refman = da->item_Refman;
  MR_inc_ref(str_Refman);
  str = ((String**)((((Array*)(da->item)))->values))[1];
/// @ t11
Data dr_Var = {0};
  Data* dr = NULL;
  RefManager* dr_Refman = NULL;
  dr = &dr_Var;
  dr_Refman = MR_new_ref(dr);
  if (dr_Refman == NULL) RAISE(1)
  if (dr == NULL || dr_Refman->value == NULL) RAISE(2)
  if (dr->item == NULL || dr->item_Refman->value == NULL) RAISE(2)
  if (((Data*)(dr->item))->item == NULL || ((Data*)(dr->item))->item_Refman->value == NULL) RAISE(2)
  MR_dec_ref(str_Refman);
  str_Refman = ((Data*)(((Data*)(dr->item))->item))->item_Refman;
  MR_inc_ref(str_Refman);
  str = ((Data*)(((Data*)(dr->item))->item))->item;
/// @ t12
CHECK(1, Data_set(d, d_Refman, *so, *so_Refman, sarr, sarr_Refman) )
  *so = NULL;
  *so_Refman = NULL;
/// @ t13
if (str != NULL) RAISE(1)
  CHECK(1, Data_get(d, d_Refman, (void*)&(str), &(str_Refman)) )
/// @ t14
Data dg_Var = {0};
  Data* dg = NULL;
  RefManager* dg_Refman = NULL;
  dg = &dg_Var;
  dg_Refman = MR_new_ref(dg);
  if (dg_Refman == NULL) RAISE(1)
/// @ t15
Data* dg = NULL;
  RefManager* dg_Refman = NULL;
  dg = d;
  dg_Refman = d_Refman;
  MR_inc_ref(dg_Refman);
/// @ t16
CHECK(1, Data_set(d, d_Refman, *so, *so_Refman, sarr, sarr_Refman) )
  *so = NULL;
  *so_Refman = NULL;
/// @ teg0
expected "}" after type parameters, got "EOF"
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
/// @ tec0
unsupported primitive parameter type "Int"
/// @ tec1
too many parameter for type "Data"
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
cannot assign type "Test" with parameters into same type with more parameters "String"
/// @@ test-parameter-inheritance
/// @ t0
typedef struct Base Base;
typedef struct Test Test;
struct Base {
  Generic_Type* item;
  RefManager* item_Refman;
};
struct Test {
  Base _base;
};
Returncode Test_set(Test* self, RefManager* self_Refman, String* s, RefManager* s_Refman);
Returncode use(String* s, RefManager* s_Refman);
Returncode Test_set(Test* self, RefManager* self_Refman, String* s, RefManager* s_Refman) {
  Returncode MR_err = OK;
  Test* aux_Test_0 = NULL;
  RefManager* aux_Test_0_Refman = NULL;
  MR_inc_ref(s_Refman);
  if (self == NULL || self_Refman->value == NULL) RAISE(5)
  MR_dec_ref(self->_base.item_Refman);
  self->_base.item_Refman = s_Refman;
  MR_inc_ref(self->_base.item_Refman);
  self->_base.item = s;
  aux_Test_0 = calloc(1, sizeof(Test));
  if (aux_Test_0 == NULL) RAISE(6)
  aux_Test_0_Refman = MR_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(6)
  CHECK(6, Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman) )
MR_cleanup:
  MR_owner_dec_ref(aux_Test_0_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
Returncode use(String* s, RefManager* s_Refman) {
  Returncode MR_err = OK;
  Test t_Var = {{0}};
  Test* t = NULL;
  RefManager* t_Refman = NULL;
  MR_inc_ref(s_Refman);
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(8)
  if (t == NULL || t_Refman->value == NULL) RAISE(9)
  MR_dec_ref(t->_base.item_Refman);
  t->_base.item_Refman = s_Refman;
  MR_inc_ref(t->_base.item_Refman);
  t->_base.item = s;
MR_cleanup:
  MR_dec_ref(t_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
/// @ t1
typedef struct Base Base;
typedef struct Test Test;
struct Base {
  Generic_Type* item;
  RefManager* item_Refman;
};
struct Test {
  Base _base;
};
Returncode Test_set(Test* self, RefManager* self_Refman, Generic_Type* i, RefManager* i_Refman, String* s, RefManager* s_Refman);
Returncode use(String* s, RefManager* s_Refman);
Returncode Test_set(Test* self, RefManager* self_Refman, Generic_Type* i, RefManager* i_Refman, String* s, RefManager* s_Refman) {
  Returncode MR_err = OK;
  Test* aux_Test_0 = NULL;
  RefManager* aux_Test_0_Refman = NULL;
  MR_inc_ref(i_Refman);
  MR_inc_ref(s_Refman);
  if (self == NULL || self_Refman->value == NULL) RAISE(5)
  MR_dec_ref(self->_base.item_Refman);
  self->_base.item_Refman = i_Refman;
  MR_inc_ref(self->_base.item_Refman);
  self->_base.item = i;
  aux_Test_0 = calloc(1, sizeof(Test));
  if (aux_Test_0 == NULL) RAISE(6)
  aux_Test_0_Refman = MR_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(6)
  CHECK(6, Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman, s, s_Refman) )
MR_cleanup:
  MR_owner_dec_ref(aux_Test_0_Refman);
  MR_dec_ref(s_Refman);
  MR_dec_ref(i_Refman);
  return MR_err;
}
Returncode use(String* s, RefManager* s_Refman) {
  Returncode MR_err = OK;
  Test t_Var = {{0}};
  Test* t = NULL;
  RefManager* t_Refman = NULL;
  MR_inc_ref(s_Refman);
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(8)
  if (t == NULL || t_Refman->value == NULL) RAISE(9)
  MR_dec_ref(t->_base.item_Refman);
  t->_base.item_Refman = s_Refman;
  MR_inc_ref(t->_base.item_Refman);
  t->_base.item = s;
MR_cleanup:
  MR_dec_ref(t_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
/// @ t2
typedef struct Base Base;
typedef struct Mid Mid;
typedef struct Top Top;
typedef struct Test Test;
struct Base {
  Generic_Type* item;
  RefManager* item_Refman;
};
struct Mid {
  Base _base;
};
struct Top {
  Mid _base;
};
struct Test {
  Top _base;
};
Returncode Base_set(Base* self, RefManager* self_Refman, Generic_Type* i, RefManager* i_Refman);
Returncode Mid_set(Mid* self, RefManager* self_Refman, Generic_Type* i, RefManager* i_Refman);
Returncode Top_set(Top* self, RefManager* self_Refman, String* s, RefManager* s_Refman);
Returncode Test_set(Test* self, RefManager* self_Refman, String* s, RefManager* s_Refman);
Returncode use(String* s, RefManager* s_Refman);
Returncode Base_set(Base* self, RefManager* self_Refman, Generic_Type* i, RefManager* i_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(i_Refman);
MR_cleanup:
  MR_dec_ref(i_Refman);
  return MR_err;
}
Returncode Mid_set(Mid* self, RefManager* self_Refman, Generic_Type* i, RefManager* i_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(i_Refman);
MR_cleanup:
  MR_dec_ref(i_Refman);
  return MR_err;
}
Returncode Top_set(Top* self, RefManager* self_Refman, String* s, RefManager* s_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(s_Refman);
  CHECK(8, Mid_set(&(self->_base), self_Refman, s, s_Refman) )
  if (self == NULL || self_Refman->value == NULL) RAISE(9)
  MR_dec_ref(self->_base._base.item_Refman);
  self->_base._base.item_Refman = s_Refman;
  MR_inc_ref(self->_base._base.item_Refman);
  self->_base._base.item = s;
MR_cleanup:
  MR_dec_ref(s_Refman);
  return MR_err;
}
Returncode Test_set(Test* self, RefManager* self_Refman, String* s, RefManager* s_Refman) {
  Returncode MR_err = OK;
  Top* aux_Top_0 = NULL;
  RefManager* aux_Top_0_Refman = NULL;
  Test* aux_Test_0 = NULL;
  RefManager* aux_Test_0_Refman = NULL;
  MR_inc_ref(s_Refman);
  CHECK(12, Top_set(&(self->_base), self_Refman, s, s_Refman) )
  if (self == NULL || self_Refman->value == NULL) RAISE(13)
  MR_dec_ref(self->_base._base._base.item_Refman);
  self->_base._base._base.item_Refman = s_Refman;
  MR_inc_ref(self->_base._base._base.item_Refman);
  self->_base._base._base.item = s;
  aux_Top_0 = calloc(1, sizeof(Top));
  if (aux_Top_0 == NULL) RAISE(14)
  aux_Top_0_Refman = MR_new_ref(aux_Top_0);
  if (aux_Top_0_Refman == NULL) RAISE(14)
  CHECK(14, Top_set(aux_Top_0, aux_Top_0_Refman, s, s_Refman) )
  aux_Test_0 = calloc(1, sizeof(Test));
  if (aux_Test_0 == NULL) RAISE(15)
  aux_Test_0_Refman = MR_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(15)
  CHECK(15, Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman) )
MR_cleanup:
  MR_owner_dec_ref(aux_Test_0_Refman);
  MR_owner_dec_ref(aux_Top_0_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
Returncode use(String* s, RefManager* s_Refman) {
  Returncode MR_err = OK;
  Test t_Var = {{{{0}}}};
  Test* t = NULL;
  RefManager* t_Refman = NULL;
  MR_inc_ref(s_Refman);
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(17)
  if (t == NULL || t_Refman->value == NULL) RAISE(18)
  MR_dec_ref(t->_base._base._base.item_Refman);
  t->_base._base._base.item_Refman = s_Refman;
  MR_inc_ref(t->_base._base._base.item_Refman);
  t->_base._base._base.item = s;
MR_cleanup:
  MR_dec_ref(t_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
/// @ t3
typedef struct Base Base;
typedef struct Test Test;
struct Base {
  Generic_Type* item;
  RefManager* item_Refman;
};
struct Test {
  Base _base;
};
Returncode Test_set(Test* self, RefManager* self_Refman, Generic_Type* i, RefManager* i_Refman, String* s, RefManager* s_Refman);
Returncode use(String* s, RefManager* s_Refman);
Returncode Test_set(Test* self, RefManager* self_Refman, Generic_Type* i, RefManager* i_Refman, String* s, RefManager* s_Refman) {
  Returncode MR_err = OK;
  Test* aux_Test_0 = NULL;
  RefManager* aux_Test_0_Refman = NULL;
  MR_inc_ref(i_Refman);
  MR_inc_ref(s_Refman);
  if (self == NULL || self_Refman->value == NULL) RAISE(5)
  MR_dec_ref(self->_base.item_Refman);
  self->_base.item_Refman = i_Refman;
  MR_inc_ref(self->_base.item_Refman);
  self->_base.item = i;
  aux_Test_0 = calloc(1, sizeof(Test));
  if (aux_Test_0 == NULL) RAISE(6)
  aux_Test_0_Refman = MR_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(6)
  CHECK(6, Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman, s, s_Refman) )
MR_cleanup:
  MR_owner_dec_ref(aux_Test_0_Refman);
  MR_dec_ref(s_Refman);
  MR_dec_ref(i_Refman);
  return MR_err;
}
Returncode use(String* s, RefManager* s_Refman) {
  Returncode MR_err = OK;
  Test t_Var = {{0}};
  Test* t = NULL;
  RefManager* t_Refman = NULL;
  MR_inc_ref(s_Refman);
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(8)
  if (t == NULL || t_Refman->value == NULL) RAISE(9)
  MR_dec_ref(t->_base.item_Refman);
  t->_base.item_Refman = s_Refman;
  MR_inc_ref(t->_base.item_Refman);
  t->_base.item = s;
MR_cleanup:
  MR_dec_ref(t_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
/// @ t4
typedef struct Base Base;
typedef struct Mid Mid;
typedef struct Top Top;
typedef struct Test Test;
struct Base {
  Generic_Type* first;
  RefManager* first_Refman;
  Generic_Type* second;
  RefManager* second_Refman;
};
struct Mid {
  Base _base;
  Generic_Type* third;
  RefManager* third_Refman;
};
struct Top {
  Mid _base;
};
struct Test {
  Top _base;
};
Returncode Mid_set(Mid* self, RefManager* self_Refman, Generic_Type* first, RefManager* first_Refman, Array* second, RefManager* second_Refman, Generic_Type* third, RefManager* third_Refman);
Returncode Top_set(Top* self, RefManager* self_Refman, Generic_Type* first, RefManager* first_Refman, Array* second, RefManager* second_Refman, File* third, RefManager* third_Refman);
Returncode Test_set(Test* self, RefManager* self_Refman, String* first, RefManager* first_Refman, Array* second, RefManager* second_Refman, File* third, RefManager* third_Refman);
Returncode use(String* first, RefManager* first_Refman, Array* second, RefManager* second_Refman, File* third, RefManager* third_Refman);
Returncode Mid_set(Mid* self, RefManager* self_Refman, Generic_Type* first, RefManager* first_Refman, Array* second, RefManager* second_Refman, Generic_Type* third, RefManager* third_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(first_Refman);
  MR_inc_ref(second_Refman);
  MR_inc_ref(third_Refman);
  if (self == NULL || self_Refman->value == NULL) RAISE(7)
  MR_dec_ref(self->_base.first_Refman);
  self->_base.first_Refman = first_Refman;
  MR_inc_ref(self->_base.first_Refman);
  self->_base.first = first;
  if (self == NULL || self_Refman->value == NULL) RAISE(8)
  MR_dec_ref(self->_base.second_Refman);
  self->_base.second_Refman = second_Refman;
  MR_inc_ref(self->_base.second_Refman);
  self->_base.second = second;
  if (self == NULL || self_Refman->value == NULL) RAISE(9)
  MR_dec_ref(self->third_Refman);
  self->third_Refman = third_Refman;
  MR_inc_ref(self->third_Refman);
  self->third = third;
MR_cleanup:
  MR_dec_ref(third_Refman);
  MR_dec_ref(second_Refman);
  MR_dec_ref(first_Refman);
  return MR_err;
}
Returncode Top_set(Top* self, RefManager* self_Refman, Generic_Type* first, RefManager* first_Refman, Array* second, RefManager* second_Refman, File* third, RefManager* third_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(first_Refman);
  MR_inc_ref(second_Refman);
  MR_inc_ref(third_Refman);
  if (self == NULL || self_Refman->value == NULL) RAISE(12)
  MR_dec_ref(self->_base._base.first_Refman);
  self->_base._base.first_Refman = first_Refman;
  MR_inc_ref(self->_base._base.first_Refman);
  self->_base._base.first = first;
  if (self == NULL || self_Refman->value == NULL) RAISE(13)
  MR_dec_ref(self->_base._base.second_Refman);
  self->_base._base.second_Refman = second_Refman;
  MR_inc_ref(self->_base._base.second_Refman);
  self->_base._base.second = second;
  if (self == NULL || self_Refman->value == NULL) RAISE(14)
  MR_dec_ref(self->_base.third_Refman);
  self->_base.third_Refman = third_Refman;
  MR_inc_ref(self->_base.third_Refman);
  self->_base.third = third;
MR_cleanup:
  MR_dec_ref(third_Refman);
  MR_dec_ref(second_Refman);
  MR_dec_ref(first_Refman);
  return MR_err;
}
Returncode Test_set(Test* self, RefManager* self_Refman, String* first, RefManager* first_Refman, Array* second, RefManager* second_Refman, File* third, RefManager* third_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(first_Refman);
  MR_inc_ref(second_Refman);
  MR_inc_ref(third_Refman);
  if (self == NULL || self_Refman->value == NULL) RAISE(17)
  MR_dec_ref(self->_base._base._base.first_Refman);
  self->_base._base._base.first_Refman = first_Refman;
  MR_inc_ref(self->_base._base._base.first_Refman);
  self->_base._base._base.first = first;
  if (self == NULL || self_Refman->value == NULL) RAISE(18)
  MR_dec_ref(self->_base._base._base.second_Refman);
  self->_base._base._base.second_Refman = second_Refman;
  MR_inc_ref(self->_base._base._base.second_Refman);
  self->_base._base._base.second = second;
  if (self == NULL || self_Refman->value == NULL) RAISE(19)
  MR_dec_ref(self->_base._base.third_Refman);
  self->_base._base.third_Refman = third_Refman;
  MR_inc_ref(self->_base._base.third_Refman);
  self->_base._base.third = third;
MR_cleanup:
  MR_dec_ref(third_Refman);
  MR_dec_ref(second_Refman);
  MR_dec_ref(first_Refman);
  return MR_err;
}
Returncode use(String* first, RefManager* first_Refman, Array* second, RefManager* second_Refman, File* third, RefManager* third_Refman) {
  Returncode MR_err = OK;
  Test t_Var = {{{{0}}}};
  Test* t = NULL;
  RefManager* t_Refman = NULL;
  MR_inc_ref(first_Refman);
  MR_inc_ref(second_Refman);
  MR_inc_ref(third_Refman);
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(21)
  if (t == NULL || t_Refman->value == NULL) RAISE(22)
  MR_dec_ref(t->_base._base._base.first_Refman);
  t->_base._base._base.first_Refman = first_Refman;
  MR_inc_ref(t->_base._base._base.first_Refman);
  t->_base._base._base.first = first;
  if (t == NULL || t_Refman->value == NULL) RAISE(23)
  MR_dec_ref(t->_base._base._base.second_Refman);
  t->_base._base._base.second_Refman = second_Refman;
  MR_inc_ref(t->_base._base._base.second_Refman);
  t->_base._base._base.second = second;
  if (t == NULL || t_Refman->value == NULL) RAISE(24)
  MR_dec_ref(t->_base._base.third_Refman);
  t->_base._base.third_Refman = third_Refman;
  MR_inc_ref(t->_base._base.third_Refman);
  t->_base._base.third = third;
MR_cleanup:
  MR_dec_ref(t_Refman);
  MR_dec_ref(third_Refman);
  MR_dec_ref(second_Refman);
  MR_dec_ref(first_Refman);
  return MR_err;
}
/// @ t5
typedef struct First First;
typedef struct Second Second;
typedef struct Test Test;
struct First {
  Generic_Type* item;
  RefManager* item_Refman;
};
struct Second {
  Generic_Type* item;
  RefManager* item_Refman;
};
struct Test {
  First _base;
};
Returncode Test_set(Test* self, RefManager* self_Refman, Generic_Type* g, RefManager* g_Refman, Second* sg, RefManager* sg_Refman);
Returncode use(String* s, RefManager* s_Refman, Second* ss, RefManager* ss_Refman);
Returncode Test_set(Test* self, RefManager* self_Refman, Generic_Type* g, RefManager* g_Refman, Second* sg, RefManager* sg_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(g_Refman);
  MR_inc_ref(sg_Refman);
  if (self == NULL || self_Refman->value == NULL) RAISE(7)
  MR_dec_ref(self->_base.item_Refman);
  self->_base.item_Refman = sg_Refman;
  MR_inc_ref(self->_base.item_Refman);
  self->_base.item = sg;
  if (self == NULL || self_Refman->value == NULL) RAISE(8)
  if (self->_base.item == NULL || self->_base.item_Refman->value == NULL) RAISE(8)
  MR_dec_ref(((Second*)(self->_base.item))->item_Refman);
  ((Second*)(self->_base.item))->item_Refman = g_Refman;
  MR_inc_ref(((Second*)(self->_base.item))->item_Refman);
  ((Second*)(self->_base.item))->item = g;
MR_cleanup:
  MR_dec_ref(sg_Refman);
  MR_dec_ref(g_Refman);
  return MR_err;
}
Returncode use(String* s, RefManager* s_Refman, Second* ss, RefManager* ss_Refman) {
  Returncode MR_err = OK;
  Test t_Var = {{0}};
  Test* t = NULL;
  RefManager* t_Refman = NULL;
  MR_inc_ref(s_Refman);
  MR_inc_ref(ss_Refman);
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(10)
  if (t == NULL || t_Refman->value == NULL) RAISE(11)
  MR_dec_ref(t->_base.item_Refman);
  t->_base.item_Refman = ss_Refman;
  MR_inc_ref(t->_base.item_Refman);
  t->_base.item = ss;
  if (t == NULL || t_Refman->value == NULL) RAISE(12)
  if (t->_base.item == NULL || t->_base.item_Refman->value == NULL) RAISE(12)
  MR_dec_ref(((Second*)(t->_base.item))->item_Refman);
  ((Second*)(t->_base.item))->item_Refman = s_Refman;
  MR_inc_ref(((Second*)(t->_base.item))->item_Refman);
  ((Second*)(t->_base.item))->item = s;
MR_cleanup:
  MR_dec_ref(t_Refman);
  MR_dec_ref(ss_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
/// @ te0
unknown type "Generic"
/// @ te1
cannot assign "File" into "String"
/// @ te2
cannot assign "String" into "Generic Type"
/// @ te3
cannot assign "File" into "String"
/// @
