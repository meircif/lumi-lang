/// @@ test-general
/// @ t0
String* str = NULL;
Ref_Manager* str_Refman = NULL;
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
char s_Values[12] = {0};
String s_Var = {12, 0, NULL};
String* s = NULL;
Ref_Manager* s_Refman = NULL;
String* us = NULL;
Ref_Manager* us_Refman = NULL;
String* gs = NULL;
Ref_Manager* gs_Refman = NULL;
void Mock_delete(Ref self) {}
USER_MAIN_HEADER {
  Returncode MR_err = OK;
  Int x = 0;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value;
#define MR_FUNC_NAME "global variable initialization"
#define MR_FILE_NAME "mock.3.mr"
  s = &s_Var;
  s_Var.values = s_Values;
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
#undef MR_FILE_NAME
#define MR_FILE_NAME "mock.3.mr"
  us = s;
  us_Refman = s_Refman;
  MR_inc_ref(us_Refman);
#undef MR_FILE_NAME
#define MR_FILE_NAME "mock.3.mr"
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(3, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "global text";
  gs = aux_String_0;
  gs_Refman = aux_String_0_Refman;
  MR_inc_ref(gs_Refman);
#undef MR_FILE_NAME
#undef MR_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  x = 6;
  x = 7;
MR_cleanup:
  return MR_err;
}
MAIN_FUNC
/// @ t7
char s_Values[12] = {0};
String s_Var = {12, 0, NULL};
String* s = NULL;
Ref_Manager* s_Refman = NULL;
Returncode dummy(void);
Returncode dummy(void) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Mock_delete(Ref self) {}
USER_MAIN_HEADER {
  Bool MR_success = true;
#undef RETURN_ERROR
#define RETURN_ERROR(value) return value;
#define MR_FUNC_NAME "global variable initialization"
#define MR_FILE_NAME "mock.3.mr"
  s = &s_Var;
  s_Var.values = s_Values;
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
#undef MR_FILE_NAME
#undef MR_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  RUN_TEST(dummy);
  return MR_success? OK : FAIL;
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
indentation too big, expected "0" got "2"
/// @ te7
too short indentation, expected "6" got "4"
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
typedef struct Test Test;
struct Test {
  Int x;
};
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
void Test_Del(Test* self) {
  if (self == NULL) return;
}
/// @ t1
typedef struct Test Test;
struct Test {
  Int x;
};
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
void Test_Del(Test* self) {
  if (self == NULL) return;
}
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
void Test1_Del(Test1* self);
void Test2_Del(Test2* self);
void Test3_Del(Test3* self);
Generic_Type_Dynamic Test1_dynamic = {(Dynamic_Del)Test1_Del};
Generic_Type_Dynamic Test2_dynamic = {(Dynamic_Del)Test2_Del};
Generic_Type_Dynamic Test3_dynamic = {(Dynamic_Del)Test3_Del};
void Test1_Del(Test1* self) {
  if (self == NULL) return;
}
void Test2_Del(Test2* self) {
  if (self == NULL) return;
}
void Test3_Del(Test3* self) {
  if (self == NULL) return;
}
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
void Test1_Del(Test1* self);
void Test2_Del(Test2* self);
Generic_Type_Dynamic Test1_dynamic = {(Dynamic_Del)Test1_Del};
Generic_Type_Dynamic Test2_dynamic = {(Dynamic_Del)Test2_Del};
void Test1_Del(Test1* self) {
  if (self == NULL) return;
}
void Test2_Del(Test2* self) {
  if (self == NULL) return;
  Test1_Del(&(self->_base));
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
  Base* b;
  Ref_Manager* b_Refman;
  Base_Dynamic* b_Dynamic;
};
struct Base_Dynamic {
  Dynamic_Del _del;
  Returncode (*dyn0)(Base* self, Ref_Manager* self_Refman, Base_Dynamic* self_Dynamic);
  Returncode (*dyn1)(Base* self, Ref_Manager* self_Refman, Base_Dynamic* self_Dynamic);
};
struct Mid {
  Base _base;
  Int y;
  Mid* m;
  Ref_Manager* m_Refman;
  Mid_Dynamic* m_Dynamic;
};
struct Mid_Dynamic {
  Base_Dynamic _base;
  Returncode (*dyn2)(Mid* self, Ref_Manager* self_Refman, Mid_Dynamic* self_Dynamic);
};
struct Top {
  Mid _base;
  Int z;
  Top* t;
  Ref_Manager* t_Refman;
  Top_Dynamic* t_Dynamic;
};
struct Top_Dynamic {
  Mid_Dynamic _base;
  Returncode (*dyn3)(Top* self, Ref_Manager* self_Refman, Top_Dynamic* self_Dynamic);
};
Returncode Base_stat(Base* self, Ref_Manager* self_Refman, Base_Dynamic* self_Dynamic);
Returncode Base_dyn0(Base* self, Ref_Manager* self_Refman, Base_Dynamic* self_Dynamic);
Returncode Base_dyn1(Base* self, Ref_Manager* self_Refman, Base_Dynamic* self_Dynamic);
void Base_Del(Base* self);
Returncode Mid_dyn0(Mid* self, Ref_Manager* self_Refman, Mid_Dynamic* self_Dynamic);
Returncode Mid_dyn2(Mid* self, Ref_Manager* self_Refman, Mid_Dynamic* self_Dynamic);
void Mid_Del(Mid* self);
Returncode Top_dyn0(Top* self, Ref_Manager* self_Refman, Top_Dynamic* self_Dynamic);
Returncode Top_dyn3(Top* self, Ref_Manager* self_Refman, Top_Dynamic* self_Dynamic);
void Top_Del(Top* self);
Base_Dynamic Base_dynamic = {(Dynamic_Del)Base_Del, Base_dyn0, Base_dyn1};
Mid_Dynamic Mid_dynamic = {{(Dynamic_Del)Mid_Del, (Func)Mid_dyn0, Base_dyn1}, Mid_dyn2};
Top_Dynamic Top_dynamic = {{{(Dynamic_Del)Top_Del, (Func)Top_dyn0, Base_dyn1}, Mid_dyn2}, Top_dyn3};
Returncode Base_stat(Base* self, Ref_Manager* self_Refman, Base_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Base_dyn0(Base* self, Ref_Manager* self_Refman, Base_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Base_dyn1(Base* self, Ref_Manager* self_Refman, Base_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Base_Del(Base* self) {
  if (self == NULL) return;
  DYN_SELF_REF_DEL(Base, _, b);
  MR_owner_dec_ref(self->b_Refman);
}
Returncode Mid_dyn0(Mid* self, Ref_Manager* self_Refman, Mid_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Mid_dyn2(Mid* self, Ref_Manager* self_Refman, Mid_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Mid_Del(Mid* self) {
  if (self == NULL) return;
  Base_Del(&(self->_base));
  DYN_SELF_REF_DEL(Mid, _base._, m);
  MR_owner_dec_ref(self->m_Refman);
}
Returncode Top_dyn0(Top* self, Ref_Manager* self_Refman, Top_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  CHECK(16, Mid_dyn0(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
MR_cleanup:
  return MR_err;
}
Returncode Top_dyn3(Top* self, Ref_Manager* self_Refman, Top_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
  CHECK(18, Mid_dyn0(&(self->_base), self_Refman, &(self_Dynamic->_base)) )
MR_cleanup:
  return MR_err;
}
void Top_Del(Top* self) {
  if (self == NULL) return;
  Mid_Del(&(self->_base));
  DYN_SELF_REF_DEL(Top, _base._base._, t);
  MR_owner_dec_ref(self->t_Refman);
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
Returncode name(String* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman, Int num);
Returncode name(String* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman, Int num) {
  Returncode MR_err = OK;
  MR_inc_ref(text_Refman);
MR_cleanup:
  MR_dec_ref(text_Refman);
  return MR_err;
}
/// @ t2
Returncode name(String** text, Ref_Manager** text_Refman, Int* num);
Returncode name(String** text, Ref_Manager** text_Refman, Int* num) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
/// @ t3
Returncode name(Char param, String** out, Ref_Manager** out_Refman);
Returncode name(Char param, String** out, Ref_Manager** out_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
/// @ t4
Returncode name(Array* array, Ref_Manager* array_Refman);
Returncode name(Array* array, Ref_Manager* array_Refman) {
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
Returncode name(String* self, Ref_Manager* self_Refman, Int px, String* pu, Ref_Manager* pu_Refman, String* po, Ref_Manager* po_Refman, String** oself, Ref_Manager** oself_Refman, Int* ox, String** ou, Ref_Manager** ou_Refman, String** oo, Ref_Manager** oo_Refman);
Returncode name(String* self, Ref_Manager* self_Refman, Int px, String* pu, Ref_Manager* pu_Refman, String* po, Ref_Manager* po_Refman, String** oself, Ref_Manager** oself_Refman, Int* ox, String** ou, Ref_Manager** ou_Refman, String** oo, Ref_Manager** oo_Refman) {
  Returncode MR_err = OK;
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
  MR_inc_ref(pu_Refman);
  v = &v_Var;
  v_Var.values = v_Values;
  v_Refman = MR_new_ref(v);
  if (v_Refman == NULL) RAISE(6, 38, "insufficient memory for managed object")
  n = MR_new_string(12);
  if (n == NULL) RAISE(7, 49, "insufficient memory for object dynamic allocation")
  n_Refman = MR_new_ref(n);
  if (n_Refman == NULL) RAISE(7, 38, "insufficient memory for managed object")
  aux_String_0 = MR_new_string(12);
  if (aux_String_0 == NULL) RAISE(8, 49, "insufficient memory for object dynamic allocation")
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(8, 38, "insufficient memory for managed object")
  String_Del(o);
  MR_owner_dec_ref(o_Refman);
  o_Refman = aux_String_0_Refman;
  o = aux_String_0;
  aux_String_0 = NULL;
  aux_String_0_Refman = NULL;
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = MR_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(9, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 16;
  aux_String_1_Var.length = 15;
  aux_String_1_Var.values = "constant string";
  MR_dec_ref(u_Refman);
  u_Refman = aux_String_1_Refman;
  MR_inc_ref(u_Refman);
  u = aux_String_1;
  aux_String_2 = &aux_String_2_Var;
  aux_String_2_Refman = MR_new_ref(aux_String_2);
  if (aux_String_2_Refman == NULL) RAISE(10, 38, "insufficient memory for managed object")
  aux_String_2_Var.length = 6;
  aux_String_2_Var.max_length = aux_String_2_Var.length + 1;
  aux_String_2_Var.values = (po)->values + (2);
  if (po == NULL) RAISE(10, 29, "empty object used as sequence")
  if (po_Refman->value == NULL) RAISE(10, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (6) < 0 || (2) + (6) > (po)->length) RAISE(10, 25, "slice index out of bounds")
  MR_dec_ref(pu_Refman);
  pu_Refman = po_Refman;
  MR_inc_ref(pu_Refman);
  pu = aux_String_2;
MR_cleanup:
  MR_dec_ref(aux_String_2_Refman);
  MR_dec_ref(aux_String_1_Refman);
  String_Del(aux_String_0);
  MR_owner_dec_ref(aux_String_0_Refman);
  String_Del(n);
  MR_owner_dec_ref(n_Refman);
  MR_dec_ref(v_Refman);
  String_Del(o);
  MR_owner_dec_ref(o_Refman);
  MR_dec_ref(u_Refman);
  String_Del(po);
  MR_owner_dec_ref(po_Refman);
  MR_dec_ref(pu_Refman);
  return MR_err;
}
/// @ t8
typedef struct Struct Struct;
typedef struct Class Class;
typedef struct Class_Dynamic Class_Dynamic;
struct Struct {
  Struct* s;
  Ref_Manager* s_Refman;
  Array* as;
  Ref_Manager* as_Refman;
};
struct Class {
  Class* c;
  Ref_Manager* c_Refman;
  Class_Dynamic* c_Dynamic;
  Array* ac;
  Ref_Manager* ac_Refman;
};
struct Class_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth)(Class* self, Ref_Manager* self_Refman, Class_Dynamic* self_Dynamic);
};
void Struct_Del(Struct* self);
Returncode Class_meth(Class* self, Ref_Manager* self_Refman, Class_Dynamic* self_Dynamic);
void Class_Del(Class* self);
Generic_Type_Dynamic Struct_dynamic = {(Dynamic_Del)Struct_Del};
Class_Dynamic Class_dynamic = {(Dynamic_Del)Class_Del, Class_meth};
Returncode name(Struct* ps, Ref_Manager* ps_Refman, Class* pc, Ref_Manager* pc_Refman, Class_Dynamic* pc_Dynamic, Array* pas, Ref_Manager* pas_Refman, Array* pac, Ref_Manager* pac_Refman);
void Struct_Del(Struct* self) {
  if (self == NULL) return;
  ARRAY_DEL(Struct, self->as)
  MR_owner_dec_ref(self->as_Refman);
  SELF_REF_DEL(Struct, s);
  MR_owner_dec_ref(self->s_Refman);
}
Returncode Class_meth(Class* self, Ref_Manager* self_Refman, Class_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Class_Del(Class* self) {
  if (self == NULL) return;
  ARRAY_DEL(Class, self->ac)
  MR_owner_dec_ref(self->ac_Refman);
  DYN_SELF_REF_DEL(Class, _, c);
  MR_owner_dec_ref(self->c_Refman);
}
Returncode name(Struct* ps, Ref_Manager* ps_Refman, Class* pc, Ref_Manager* pc_Refman, Class_Dynamic* pc_Dynamic, Array* pas, Ref_Manager* pas_Refman, Array* pac, Ref_Manager* pac_Refman) {
  Returncode MR_err = OK;
  Struct* s = NULL;
  Ref_Manager* s_Refman = NULL;
  Class* c = NULL;
  Ref_Manager* c_Refman = NULL;
  Class_Dynamic* c_Dynamic = NULL;
  Array* as = NULL;
  Ref_Manager* as_Refman = NULL;
  Array* ac = NULL;
  Ref_Manager* ac_Refman = NULL;
  Array* ai = NULL;
  Ref_Manager* ai_Refman = NULL;
  Array* af = NULL;
  Ref_Manager* af_Refman = NULL;
MR_cleanup:
  ARRAY_DEL(File, af)
  MR_owner_dec_ref(af_Refman);
  MR_owner_dec_ref(ai_Refman);
  ARRAY_DEL(Class, ac)
  MR_owner_dec_ref(ac_Refman);
  ARRAY_DEL(Struct, as)
  MR_owner_dec_ref(as_Refman);
  if (c_Dynamic != NULL) c_Dynamic->_del(c);
  MR_owner_dec_ref(c_Refman);
  Struct_Del(s);
  MR_owner_dec_ref(s_Refman);
  ARRAY_DEL(Class, pac)
  MR_owner_dec_ref(pac_Refman);
  ARRAY_DEL(Struct, pas)
  MR_owner_dec_ref(pas_Refman);
  if (pc_Dynamic != NULL) pc_Dynamic->_del(pc);
  MR_owner_dec_ref(pc_Refman);
  Struct_Del(ps);
  MR_owner_dec_ref(ps_Refman);
  return MR_err;
}
/// @ tm0
void Mock_delete(Ref self) {}
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
  Ref_Manager* str_Refman;
};
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
void Test_Del(Test* self) {
  if (self == NULL) return;
  MR_dec_ref(self->str_Refman);
}
/// @ t1
typedef struct Test Test;
struct Test {
  Int x;
};
Returncode Test_name(Test* self, Ref_Manager* self_Refman);
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode Test_name(Test* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
}
/// @ t2
typedef struct Test Test;
struct Test {
  Int x;
};
Returncode Test_name(Test* self, Ref_Manager* self_Refman);
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode Test_name(Test* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
  Int x = 0;
MR_cleanup:
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
}
/// @ t3
typedef struct Test Test;
struct Test {
  Int x;
};
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
void Test_Del(Test* self) {
  if (self == NULL) return;
}
/// @ t4
typedef struct Test Test;
struct Test {
  Int x;
};
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
void Test_Del(Test* self) {
  if (self == NULL) return;
}
/// @ t5
typedef struct Test Test;
struct Test {
  Int x;
};
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
void Test_Del(Test* self) {
  if (self == NULL) return;
}
/// @ t6
typedef struct Test Test;
struct Test {
  Int x;
};
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
void Test_Del(Test* self) {
  if (self == NULL) return;
}
/// @ t7
typedef struct Test1 Test1;
typedef struct Test2 Test2;
struct Test1 {
  Int name;
};
struct Test2 {
  Int fun;
};
Returncode Test1_fun(Test1* self, Ref_Manager* self_Refman);
void Test1_Del(Test1* self);
Returncode Test2_name(Test2* self, Ref_Manager* self_Refman);
void Test2_Del(Test2* self);
Generic_Type_Dynamic Test1_dynamic = {(Dynamic_Del)Test1_Del};
Generic_Type_Dynamic Test2_dynamic = {(Dynamic_Del)Test2_Del};
Int name = 0;
Returncode fun(void);
Returncode Test1_fun(Test1* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Test1_Del(Test1* self) {
  if (self == NULL) return;
}
Returncode Test2_name(Test2* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Test2_Del(Test2* self) {
  if (self == NULL) return;
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
  USER_RAISE(2, NULL, NULL)
MR_cleanup:
  return MR_err;
}
/// @ t2
Returncode name(void);
Returncode name(void) {
  Returncode MR_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(2, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 11;
  aux_String_0_Var.length = 10;
  aux_String_0_Var.values = "some error";
  USER_RAISE(2, aux_String_0, aux_String_0_Refman)
MR_cleanup:
  MR_dec_ref(aux_String_0_Refman);
  return MR_err;
}
/// @ t3
Returncode name(Array* arr, Ref_Manager* arr_Refman);
Returncode name(Array* arr, Ref_Manager* arr_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(arr_Refman);
  if (arr == NULL) RAISE(2, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(2, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) >= (arr)->length) RAISE(2, 25, "slice index out of bounds")
  USER_RAISE(2, ((String*)((arr)->values)) + 3, arr_Refman)
MR_cleanup:
  MR_dec_ref(arr_Refman);
  return MR_err;
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
Test* tt = NULL;
  Ref_Manager* tt_Refman = NULL;
/// @ t4
char s_Values[12] = {0};
  String s_Var = {12, 0, NULL};
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  s = &s_Var;
  s_Var.values = s_Values;
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
/// @ t5
Int a_Values[12] = {0};
  Array a_Var = {12, NULL};
  Array* a = NULL;
  Ref_Manager* a_Refman = NULL;
  a = &a_Var;
  a_Var.values = a_Values;
  a_Refman = MR_new_ref(a);
  if (a_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
/// @ t6
Test a_Values[12] = {{0}};
  Array a_Var = {12, NULL};
  Array* a = NULL;
  Ref_Manager* a_Refman = NULL;
  a = &a_Var;
  a_Var.values = a_Values;
  a_Refman = MR_new_ref(a);
  if (a_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
/// @ t7
char sa_Chars[12 * 7];
  String sa_Values[12] = {{0}};
  Array sa_Var = {12, NULL};
  Array* sa = NULL;
  Ref_Manager* sa_Refman = NULL;
  sa = &sa_Var;
  sa_Var.values = sa_Values;
  MR_set_var_string_array(12, 7, sa, sa_Chars);
  sa_Refman = MR_new_ref(sa);
  if (sa_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
/// @ t8
String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  s = MR_new_string(12);
  if (s == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  String_Del(*so);
  MR_owner_dec_ref(*so_Refman);
  *so_Refman = s_Refman;
  *so = s;
  s = NULL;
  s_Refman = NULL;
/// @ t9
Tc a_Values[12] = {{{{{0}}}}};
  Array a_Var = {12, NULL};
  Array* a = NULL;
  Ref_Manager* a_Refman = NULL;
  a = &a_Var;
  a_Var.values = a_Values;
  a_Refman = MR_new_ref(a);
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
/// @@ test-initialize
/// @ t0
Test* aux_Test_0 = NULL;
  Ref_Manager* aux_Test_0_Refman = NULL;
  aux_Test_0 = calloc(1, sizeof(Test));
  if (aux_Test_0 == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  aux_Test_0_Refman = MR_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, Test_new(aux_Test_0, aux_Test_0_Refman, i) )
  MR_dec_ref(t_Refman);
  t_Refman = aux_Test_0_Refman;
  MR_inc_ref(t_Refman);
  t = aux_Test_0;
/// @ t1
String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  if (arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(1, 25, "slice index out of bounds")
  aux_String_0 = MR_new_string(((Int*)((arr)->values))[0]);
  if (aux_String_0 == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  MR_dec_ref(str_Refman);
  str_Refman = aux_String_0_Refman;
  MR_inc_ref(str_Refman);
  str = aux_String_0;
/// @ t2
Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  if (arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(1, 25, "slice index out of bounds")
  aux_Array_0 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Int));
  if (aux_Array_0 == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  aux_Array_0_Refman = MR_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  MR_dec_ref(arr_Refman);
  arr_Refman = aux_Array_0_Refman;
  MR_inc_ref(arr_Refman);
  arr = aux_Array_0;
/// @ t3
Array* a = NULL;
  Ref_Manager* a_Refman = NULL;
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  if (arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(1, 25, "slice index out of bounds")
  aux_Array_0 = MR_new_array(((Int*)((arr)->values))[0], sizeof(Test));
  if (aux_Array_0 == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  aux_Array_0_Refman = MR_new_ref(aux_Array_0);
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
  if (arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(1, 25, "slice index out of bounds")
  if (arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((1) < 0 || (1) >= (arr)->length) RAISE(1, 25, "slice index out of bounds")
  aux_Array_0 = MR_new_string_array(((Int*)((arr)->values))[0], ((Int*)((arr)->values))[1]);
  if (aux_Array_0 == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  aux_Array_0_Refman = MR_new_ref(aux_Array_0);
  if (aux_Array_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  sa = aux_Array_0;
  sa_Refman = aux_Array_0_Refman;
  aux_Array_0 = NULL;
  aux_Array_0_Refman = NULL;
/// @ t5
Int x = 0;
  if (arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= (arr)->length) RAISE(1, 25, "slice index out of bounds")
  x = ((Int*)((arr)->values))[0];
/// @ t6
String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  s = str;
  s_Refman = str_Refman;
  MR_inc_ref(s_Refman);
/// @ t7
char s_Values[12] = {0};
  String s_Var = {12, 0, NULL};
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = MR_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 12;
  aux_String_0_Var.length = 11;
  aux_String_0_Var.values = "some string";
  s = &s_Var;
  s_Var.values = s_Values;
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, String_new(s, s_Refman, aux_String_0, aux_String_0_Refman) )
/// @ t8
String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  s = MR_new_string(i);
  if (s == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  s_Refman = MR_new_ref(s);
  if (s_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, String_new(s, s_Refman, str, str_Refman) )
/// @ t9
Test* tt = NULL;
  Ref_Manager* tt_Refman = NULL;
  tt = &(tc->_base._base._base);
  tt_Refman = tc_Refman;
  MR_inc_ref(tt_Refman);
/// @ t10
Test tt_Var = {0};
  Test* tt = NULL;
  Ref_Manager* tt_Refman = NULL;
  tt = &tt_Var;
  tt_Refman = MR_new_ref(tt);
  if (tt_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, Test_new(tt, tt_Refman, 3) )
/// @ t11
Test* tt = NULL;
  Ref_Manager* tt_Refman = NULL;
  tt = calloc(1, sizeof(Test));
  if (tt == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  tt_Refman = MR_new_ref(tt);
  if (tt_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, Test_new(tt, tt_Refman, 3) )
/// @ t12
Test* aux_Test_0 = NULL;
  Ref_Manager* aux_Test_0_Refman = NULL;
  aux_Test_0 = calloc(1, sizeof(Test));
  if (aux_Test_0 == NULL) RAISE(1, 49, "insufficient memory for object dynamic allocation")
  aux_Test_0_Refman = MR_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  CHECK(1, Test_new(aux_Test_0, aux_Test_0_Refman, 3) )
  MR_dec_ref(t_Refman);
  t_Refman = aux_Test_0_Refman;
  MR_inc_ref(t_Refman);
  t = aux_Test_0;
/// @ t13
Tb* tt = NULL;
  Ref_Manager* tt_Refman = NULL;
  Tb_Dynamic* tt_Dynamic = NULL;
  tt = tb;
  tt_Refman = tb_Refman;
  MR_inc_ref(tt_Refman);
  tt_Dynamic = tb_Dynamic;
/// @ t14
Ta* ota = NULL;
  Ref_Manager* ota_Refman = NULL;
  Ta_Dynamic* ota_Dynamic = NULL;
  ota = &(tb->_base);
  ota_Refman = tb_Refman;
  ota_Dynamic = &(tb_Dynamic->_base);
  tb = NULL;
  tb_Refman = NULL;
  tb_Dynamic = NULL;
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
if (t == NULL) RAISE(1, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
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
    if (t == NULL) RAISE(3, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(3, 38, "used member of outdated weak reference")
    if (t->num > 2) {
      i -= 2;
    }
    else {
      if (t == NULL) RAISE(5, 27, "used member of empty object")
      if (t_Refman->value == NULL) RAISE(5, 38, "used member of outdated weak reference")
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
    if (t == NULL) RAISE(2, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
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
Int n = 0;
  for (n = 0; n < 5; ++n) {
    i += n;
  }
/// @ t1
Int n = 0;
  if (t == NULL) RAISE(1, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  for (n = t->num; n < t->num + 2; ++n) {
    i += n;
  }
/// @ t2
Char ch = 0;
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  MR_dec_ref(aux_String_0_Refman);
  aux_String_0_Refman = str_Refman;
  MR_inc_ref(aux_String_0_Refman);
  aux_String_0 = str;
  {int ch_Index; for (ch_Index = 0; ch_Index < aux_String_0->length; ++ch_Index) {
    if (aux_String_0 == NULL) RAISE(1, 29, "empty object used as sequence")
    if (aux_String_0_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
    if ((ch_Index) < 0 || (ch_Index) >= (aux_String_0)->length) RAISE(1, 25, "slice index out of bounds")
    ch = ((aux_String_0)->values)[ch_Index];
    c = ch;
  }}
  MR_dec_ref(aux_String_0_Refman);
  aux_String_0_Refman = NULL;
  MR_inc_ref(aux_String_0_Refman);
  aux_String_0 = NULL;
/// @ t3
Int n = 0;
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  MR_dec_ref(aux_Array_0_Refman);
  aux_Array_0_Refman = arr_Refman;
  MR_inc_ref(aux_Array_0_Refman);
  aux_Array_0 = arr;
  {int n_Index; for (n_Index = 0; n_Index < aux_Array_0->length; ++n_Index) {
    if (aux_Array_0 == NULL) RAISE(1, 29, "empty object used as sequence")
    if (aux_Array_0_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
    if ((n_Index) < 0 || (n_Index) >= (aux_Array_0)->length) RAISE(1, 25, "slice index out of bounds")
    n = ((Int*)((aux_Array_0)->values))[n_Index];
    i += n;
  }}
  MR_dec_ref(aux_Array_0_Refman);
  aux_Array_0_Refman = NULL;
  MR_inc_ref(aux_Array_0_Refman);
  aux_Array_0 = NULL;
/// @ t4
String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  Array* aux_Array_0 = NULL;
  Ref_Manager* aux_Array_0_Refman = NULL;
  MR_dec_ref(aux_Array_0_Refman);
  aux_Array_0_Refman = sarr_Refman;
  MR_inc_ref(aux_Array_0_Refman);
  aux_Array_0 = sarr;
  {int s_Index; for (s_Index = 0; s_Index < aux_Array_0->length; ++s_Index) {
    if (aux_Array_0 == NULL) RAISE(1, 29, "empty object used as sequence")
    if (aux_Array_0_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
    if ((s_Index) < 0 || (s_Index) >= (aux_Array_0)->length) RAISE(1, 25, "slice index out of bounds")
    MR_dec_ref(s_Refman);
    s_Refman = aux_Array_0_Refman;
    MR_inc_ref(s_Refman);
    s = ((String*)((aux_Array_0)->values)) + s_Index;
    MR_dec_ref(str_Refman);
    str_Refman = s_Refman;
    MR_inc_ref(str_Refman);
    str = s;
  }}
  MR_dec_ref(aux_Array_0_Refman);
  aux_Array_0_Refman = NULL;
  MR_inc_ref(aux_Array_0_Refman);
  aux_Array_0 = NULL;
/// @ t5
Int n = 0;
  for (n = 0; n < 5; ++n) {
    i += n;
  }
/// @ t6
Int n = 0;
  for (n = 0; n < 5; ++n) {
    i += n;
  }
  for (n = 0; n < 7; ++n) {
    i += n;
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
/// @ t0
if (t == NULL) RAISE(1, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  TEST_ASSERT(1, t->num == 2)
/// @ t1
do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (t == NULL) RAISE(1, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
    #undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(1, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
/// @ t2
do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(1, fun0() )
    #undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    TEST_FAIL(1, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
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
  USER_RAISE(4, NULL, NULL)
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
Returncode Test_meth(Test* self, Ref_Manager* self_Refman, Int x);
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode Test_Mock_meth(Test* self, Ref_Manager* self_Refman, Int x);
Returncode Test_meth(Test* self, Ref_Manager* self_Refman, Int x) {
  Returncode MR_err = OK;
  CHECK(5, Test_Mock_meth(self, self_Refman, x) )
MR_cleanup:
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
}
Returncode Test_Mock_meth(Test* self, Ref_Manager* self_Refman, Int x) {
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
void Mock_delete(Ref self) {}
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
void Mock_delete(Ref self) {}
USER_MAIN_HEADER {
  Bool MR_success = true;
  RUN_TEST(fun0);
  RUN_TEST(fun1);
  return MR_success? OK : FAIL;
}
TEST_MAIN_FUNC
/// @ t8
typedef struct Test Test;
struct Test {
  String* s;
  Ref_Manager* s_Refman;
};
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode Test_MockDel(Ref self);
void Test_Del(Test* self) {
  if (self == NULL) return;
  IGNORE_ERRORS( Test_MockDel(self) )
  MR_dec_ref(self->s_Refman);
}
Returncode Test_MockDel(Ref self) {
  Returncode MR_err = OK;
  Ref r = NULL;
  r = self;
MR_cleanup:
  return MR_err;
}
/// @ t9
Returncode Mock_delete(Ref self);
Returncode Mock_delete(Ref self) {
  Returncode MR_err = OK;
  Ref r = NULL;
  r = self;
MR_cleanup:
  return MR_err;
}
USER_MAIN_HEADER {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
MAIN_FUNC
/// @ t10
{char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "expected error";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (t == NULL) RAISE(1, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
    #undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(1, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(1)
  }
  MR_expected_error = MR_expected_error_prev;}
/// @ t11
{char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "expected error in the function";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    CHECK(1, fun0() )
    #undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(1, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(1)
  }
  MR_expected_error = MR_expected_error_prev;}
/// @ t12
{char* MR_expected_error_prev;
  int MR_expected_error_trace_ignore_count_prev;
  MR_expected_error_prev = MR_expected_error;
  MR_expected_error_trace_ignore_count_prev = MR_expected_error_trace_ignore_count;
  MR_expected_error = "expected error in new line";
  MR_expected_error_trace_ignore_count = MR_trace_ignore_count + 1;
  do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) break
    if (t == NULL) RAISE(1, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
    #undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    --MR_trace_ignore_count;
    MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL(1, 16, "error not raised")
  } while (false);
  --MR_trace_ignore_count;
  MR_expected_error_trace_ignore_count = MR_expected_error_trace_ignore_count_prev;
  if (MR_expected_error == NULL) {
    MR_expected_error = MR_expected_error_prev;
    TEST_FAIL_NULL(1)
  }
  MR_expected_error = MR_expected_error_prev;}
/// @ tr0
Ref r = NULL;
/// @ tr1
Ref r = NULL;
  r = str;
/// @ tr2
Ref r = NULL;
  r = NULL;
/// @ tr3
Ref r = NULL;
  r = str;
/// @ tr4
Ref r = NULL;
  TEST_ASSERT(2, r == r)
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
/// @ te20
no '"' around string constant " "error""
/// @ te21
no '"' around string constant "error"
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
  Dynamic_Del _del;
  Returncode (*meth)(Test* self, Ref_Manager* self_Refman, Test_Dynamic* self_Dynamic);
};
Returncode Test_meth(Test* self, Ref_Manager* self_Refman, Test_Dynamic* self_Dynamic);
void Test_Del(Test* self);
Test_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del, Test_meth};
Returncode external(Int i, String* s, Test* ta, Int* io);
Returncode call(void);
Returncode Test_meth(Test* self, Ref_Manager* self_Refman, Test_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
}
Returncode call(void) {
  Returncode MR_err = OK;
  Int i = 0;
  String* s = NULL;
  Ref_Manager* s_Refman = NULL;
  Test* ta = NULL;
  Ref_Manager* ta_Refman = NULL;
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
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
  Array* arr;
  Ref_Manager* arr_Refman;
};
Returncode Test_set(Test* self, Ref_Manager* self_Refman, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic, Array* arr, Ref_Manager* arr_Refman);
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode Test_set(Test* self, Ref_Manager* self_Refman, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic, Array* arr, Ref_Manager* arr_Refman) {
  Returncode MR_err = OK;
  Generic_Type* x = NULL;
  Ref_Manager* x_Refman = NULL;
  Generic_Type_Dynamic* x_Dynamic = NULL;
  Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  MR_inc_ref(arr_Refman);
  x = item;
  x_Refman = item_Refman;
  x_Dynamic = item_Dynamic;
  item = NULL;
  item_Refman = NULL;
  item_Dynamic = NULL;
  if (self == NULL) RAISE(6, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(6, 38, "used member of outdated weak reference")
  if (self->item_Dynamic != NULL) self->item_Dynamic->_del(self->item);
  MR_owner_dec_ref(self->item_Refman);
  self->item_Refman = x_Refman;
  self->item_Dynamic = x_Dynamic;
  self->item = x;
  x = NULL;
  x_Refman = NULL;
  x_Dynamic = NULL;
  if (self == NULL) RAISE(7, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(7, 38, "used member of outdated weak reference")
  MR_dec_ref(self->arr_Refman);
  self->arr_Refman = arr_Refman;
  MR_inc_ref(self->arr_Refman);
  self->arr = arr;
  t = calloc(1, sizeof(Test));
  if (t == NULL) RAISE(8, 49, "insufficient memory for object dynamic allocation")
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(8, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(9, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  if (t == NULL) RAISE(9, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  if (t->item_Dynamic != NULL) t->item_Dynamic->_del(t->item);
  MR_owner_dec_ref(t->item_Refman);
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
  if (self->item_Dynamic != NULL) self->item_Dynamic->_del(self->item);
  MR_owner_dec_ref(self->item_Refman);
  self->item_Refman = t->item_Refman;
  self->item_Dynamic = t->item_Dynamic;
  self->item = t->item;
  t->item = NULL;
  t->item_Refman = NULL;
  t->item_Dynamic = NULL;
MR_cleanup:
  Test_Del(t);
  MR_owner_dec_ref(t_Refman);
  if (x_Dynamic != NULL) x_Dynamic->_del(x);
  MR_owner_dec_ref(x_Refman);
  MR_dec_ref(arr_Refman);
  if (item_Dynamic != NULL) item_Dynamic->_del(item);
  MR_owner_dec_ref(item_Refman);
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
  MR_dec_ref(self->arr_Refman);
  if (self->item_Dynamic != NULL) self->item_Dynamic->_del(self->item);
  MR_owner_dec_ref(self->item_Refman);
}
/// @ t1
typedef struct Test Test;
struct Test {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
Returncode Test_get(Test* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode Test_get(Test* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
  Returncode MR_err = OK;
  if (self == NULL) RAISE(4, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(4, 38, "used member of outdated weak reference")
  MR_dec_ref(*item_Refman);
  *item_Refman = self->item_Refman;
  MR_inc_ref(*item_Refman);
  *item_Dynamic = self->item_Dynamic;
  *item = self->item;
MR_cleanup:
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
  if (self->item_Dynamic != NULL) self->item_Dynamic->_del(self->item);
  MR_owner_dec_ref(self->item_Refman);
}
/// @ t2
typedef struct Test Test;
struct Test {
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
Returncode Test_set(Test* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Generic_Type* second, Ref_Manager* second_Refman, Generic_Type_Dynamic* second_Dynamic, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic);
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode use(String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
Returncode Test_set(Test* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Generic_Type* second, Ref_Manager* second_Refman, Generic_Type_Dynamic* second_Dynamic, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic) {
  Returncode MR_err = OK;
  MR_inc_ref(first_Refman);
  MR_inc_ref(second_Refman);
  MR_inc_ref(third_Refman);
  if (self == NULL) RAISE(6, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(6, 38, "used member of outdated weak reference")
  MR_dec_ref(self->first_Refman);
  self->first_Refman = first_Refman;
  MR_inc_ref(self->first_Refman);
  self->first_Dynamic = first_Dynamic;
  self->first = first;
  if (self == NULL) RAISE(7, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(7, 38, "used member of outdated weak reference")
  MR_dec_ref(self->second_Refman);
  self->second_Refman = second_Refman;
  MR_inc_ref(self->second_Refman);
  self->second_Dynamic = second_Dynamic;
  self->second = second;
  if (self == NULL) RAISE(8, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(8, 38, "used member of outdated weak reference")
  MR_dec_ref(self->third_Refman);
  self->third_Refman = third_Refman;
  MR_inc_ref(self->third_Refman);
  self->third_Dynamic = third_Dynamic;
  self->third = third;
MR_cleanup:
  MR_dec_ref(third_Refman);
  MR_dec_ref(second_Refman);
  MR_dec_ref(first_Refman);
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
  MR_dec_ref(self->third_Refman);
  MR_dec_ref(self->second_Refman);
  MR_dec_ref(self->first_Refman);
}
Returncode use(String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
  Returncode MR_err = OK;
  Test t_Var = {0};
  Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  MR_inc_ref(first_Refman);
  MR_inc_ref(second_Refman);
  MR_inc_ref(third_Refman);
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(10, 38, "insufficient memory for managed object")
  if (t == NULL) RAISE(11, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(11, 38, "used member of outdated weak reference")
  MR_dec_ref(t->first_Refman);
  t->first_Refman = first_Refman;
  MR_inc_ref(t->first_Refman);
  t->first_Dynamic = &String_dynamic;
  t->first = first;
  if (t == NULL) RAISE(12, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(12, 38, "used member of outdated weak reference")
  MR_dec_ref(t->second_Refman);
  t->second_Refman = second_Refman;
  MR_inc_ref(t->second_Refman);
  t->second_Dynamic = &Sys_dynamic;
  t->second = second;
  if (t == NULL) RAISE(13, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(13, 38, "used member of outdated weak reference")
  MR_dec_ref(t->third_Refman);
  t->third_Refman = third_Refman;
  MR_inc_ref(t->third_Refman);
  t->third_Dynamic = &File_dynamic;
  t->third = third;
  CHECK(14, Test_set(t, t_Refman, first, first_Refman, &String_dynamic, second, second_Refman, &Sys_dynamic, third, third_Refman, &File_dynamic) )
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
void Base_Del(Base* self);
void Test_Del(Test* self);
Generic_Type_Dynamic Base_dynamic = {(Dynamic_Del)Base_Del};
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
void Base_Del(Base* self) {
  if (self == NULL) return;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
  Base_Del(&(self->_base));
}
/// @ t4
if (d == NULL) RAISE(1, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  MR_dec_ref(d->item_Refman);
  d->item_Refman = str_Refman;
  MR_inc_ref(d->item_Refman);
  d->item_Dynamic = &String_dynamic;
  d->item = str;
/// @ t5
if (d == NULL) RAISE(1, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  MR_dec_ref(str_Refman);
  str_Refman = d->item_Refman;
  MR_inc_ref(str_Refman);
  str = d->item;
/// @ t6
if (d == NULL) RAISE(1, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  MR_dec_ref(d->arr_Refman);
  d->arr_Refman = sarr_Refman;
  MR_inc_ref(d->arr_Refman);
  d->arr = sarr;
/// @ t7
if (d == NULL) RAISE(1, 27, "used member of empty object")
  if (d_Refman->value == NULL) RAISE(1, 38, "used member of outdated weak reference")
  if (d->arr == NULL) RAISE(1, 29, "empty object used as sequence")
  if (d->arr_Refman->value == NULL) RAISE(1, 40, "outdated weak reference used as sequence")
  if ((4) < 0 || (4) >= (d->arr)->length) RAISE(1, 25, "slice index out of bounds")
  MR_dec_ref(str_Refman);
  str_Refman = d->arr_Refman;
  MR_inc_ref(str_Refman);
  str = ((String*)((d->arr)->values)) + 4;
/// @ t8
Data ad_Values[5] = {{0}};
  Array ad_Var = {5, NULL};
  Array* ad = NULL;
  Ref_Manager* ad_Refman = NULL;
  ad = &ad_Var;
  ad_Var.values = ad_Values;
  ad_Refman = MR_new_ref(ad);
  if (ad_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  if (ad == NULL) RAISE(2, 29, "empty object used as sequence")
  if (ad_Refman->value == NULL) RAISE(2, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (ad)->length) RAISE(2, 25, "slice index out of bounds")
  if (((Data*)((ad)->values)) + 2 == NULL) RAISE(2, 27, "used member of empty object")
  if (ad_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
  MR_dec_ref(str_Refman);
  str_Refman = (((Data*)((ad)->values)) + 2)->item_Refman;
  MR_inc_ref(str_Refman);
  str = (((Data*)((ad)->values)) + 2)->item;
/// @ t9
Data ad_Values[5] = {{0}};
  Array ad_Var = {5, NULL};
  Array* ad = NULL;
  Ref_Manager* ad_Refman = NULL;
  ad = &ad_Var;
  ad_Var.values = ad_Values;
  ad_Refman = MR_new_ref(ad);
  if (ad_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  if (ad == NULL) RAISE(2, 29, "empty object used as sequence")
  if (ad_Refman->value == NULL) RAISE(2, 40, "outdated weak reference used as sequence")
  if ((2) < 0 || (2) >= (ad)->length) RAISE(2, 25, "slice index out of bounds")
  if (((Data*)((ad)->values)) + 2 == NULL) RAISE(2, 27, "used member of empty object")
  if (ad_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
  if ((((Data*)((ad)->values)) + 2)->arr == NULL) RAISE(2, 29, "empty object used as sequence")
  if ((((Data*)((ad)->values)) + 2)->arr_Refman->value == NULL) RAISE(2, 40, "outdated weak reference used as sequence")
  if ((3) < 0 || (3) >= ((((Data*)((ad)->values)) + 2)->arr)->length) RAISE(2, 25, "slice index out of bounds")
  MR_dec_ref(str_Refman);
  str_Refman = (((Data*)((ad)->values)) + 2)->arr_Refman;
  MR_inc_ref(str_Refman);
  str = ((String*)(((((Data*)((ad)->values)) + 2)->arr)->values)) + 3;
/// @ t10
CHECK(1, Data_set(d, d_Refman, NULL, NULL, NULL, NULL, NULL) )
/// @ t11
Data dr_Var = {0};
  Data* dr = NULL;
  Ref_Manager* dr_Refman = NULL;
  dr = &dr_Var;
  dr_Refman = MR_new_ref(dr);
  if (dr_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  if (dr == NULL) RAISE(2, 27, "used member of empty object")
  if (dr_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
  if (dr->item == NULL) RAISE(2, 27, "used member of empty object")
  if (dr->item_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
  if (((Data*)(dr->item))->item == NULL) RAISE(2, 27, "used member of empty object")
  if (((Data*)(dr->item))->item_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
  MR_dec_ref(str_Refman);
  str_Refman = ((Data*)(((Data*)(dr->item))->item))->item_Refman;
  MR_inc_ref(str_Refman);
  str = ((Data*)(((Data*)(dr->item))->item))->item;
/// @ t12
CHECK(1, Data_set(d, d_Refman, *so, *so_Refman, &String_dynamic, sarr, sarr_Refman) )
  *so = NULL;
  *so_Refman = NULL;
/// @ t13
CHECK(1, Data_get(d, d_Refman, (void*)&(str), &(str_Refman), &dynamic_Void) )
/// @ t14
Data dg_Var = {0};
  Data* dg = NULL;
  Ref_Manager* dg_Refman = NULL;
  dg = &dg_Var;
  dg_Refman = MR_new_ref(dg);
  if (dg_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
/// @ t15
Data* dg = NULL;
  Ref_Manager* dg_Refman = NULL;
  dg = d;
  dg_Refman = d_Refman;
  MR_inc_ref(dg_Refman);
/// @ t16
CHECK(1, Data_set(d, d_Refman, *so, *so_Refman, &String_dynamic, sarr, sarr_Refman) )
  *so = NULL;
  *so_Refman = NULL;
/// @ t17
typedef struct Test Test;
struct Test {
  Test* next;
  Ref_Manager* next_Refman;
};
Returncode Test_meth(Test* self, Ref_Manager* self_Refman);
void Test_Del(Test* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode Test_meth(Test* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
  if (self == NULL) RAISE(4, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(4, 38, "used member of outdated weak reference")
  MR_dec_ref(self->next_Refman);
  self->next_Refman = self_Refman;
  MR_inc_ref(self->next_Refman);
  self->next = self;
MR_cleanup:
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
  MR_dec_ref(self->next_Refman);
}
/// @ t18
Data dt_Var = {0};
  Data* dt = NULL;
  Ref_Manager* dt_Refman = NULL;
  Tc* otc = NULL;
  Ref_Manager* otc_Refman = NULL;
  Tc_Dynamic* otc_Dynamic = NULL;
  dt = &dt_Var;
  dt_Refman = MR_new_ref(dt);
  if (dt_Refman == NULL) RAISE(1, 38, "insufficient memory for managed object")
  if (dt == NULL) RAISE(2, 27, "used member of empty object")
  if (dt_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
  MR_dec_ref(dt->item_Refman);
  dt->item_Refman = tc_Refman;
  MR_inc_ref(dt->item_Refman);
  dt->item_Dynamic = (Generic_Type_Dynamic*)&(tc_Dynamic->_base);
  dt->item = &(tc->_base);
  if (dt == NULL) RAISE(3, 27, "used member of empty object")
  if (dt_Refman->value == NULL) RAISE(3, 38, "used member of outdated weak reference")
  MR_dec_ref(ta_Refman);
  ta_Refman = dt->item_Refman;
  MR_inc_ref(ta_Refman);
  ta_Dynamic = &(((Tb_Dynamic*)(dt->item_Dynamic))->_base);
  ta = &(((Tb*)(dt->item))->_base);
  CHECK(5, Data_set(dt, dt_Refman, &(otc->_base), otc_Refman, (void*)&(otc_Dynamic->_base), NULL, NULL) )
  otc = NULL;
  otc_Refman = NULL;
  otc_Dynamic = NULL;
  if (ta != NULL) RAISE(6, 45, "non empty base class given as output argument")
  CHECK(6, Data_get(dt, dt_Refman, (void*)&(ta), &(ta_Refman), (void*)&(ta_Dynamic)) )
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
/// @ teg8
cannot slice generic array
/// @ teg9
cannot create generic array
/// @ teg10
cannot create generic array
/// @ teg11
cannot assign type "Test" with parameters into same type with more parameters "String"
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
array as parameter type is unsupported
/// @@ test-parameter-inheritance
/// @ t0
typedef struct Base Base;
typedef struct Test Test;
struct Base {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct Test {
  Base _base;
};
void Base_Del(Base* self);
Returncode Test_set(Test* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman);
void Test_Del(Test* self);
Generic_Type_Dynamic Base_dynamic = {(Dynamic_Del)Base_Del};
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode use(String* s, Ref_Manager* s_Refman);
void Base_Del(Base* self) {
  if (self == NULL) return;
  MR_dec_ref(self->item_Refman);
}
Returncode Test_set(Test* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  Test* aux_Test_0 = NULL;
  Ref_Manager* aux_Test_0_Refman = NULL;
  MR_inc_ref(s_Refman);
  if (self == NULL) RAISE(5, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(5, 38, "used member of outdated weak reference")
  MR_dec_ref(self->_base.item_Refman);
  self->_base.item_Refman = s_Refman;
  MR_inc_ref(self->_base.item_Refman);
  self->_base.item_Dynamic = &String_dynamic;
  self->_base.item = s;
  aux_Test_0 = calloc(1, sizeof(Test));
  if (aux_Test_0 == NULL) RAISE(6, 49, "insufficient memory for object dynamic allocation")
  aux_Test_0_Refman = MR_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(6, 38, "insufficient memory for managed object")
  CHECK(6, Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman) )
MR_cleanup:
  Test_Del(aux_Test_0);
  MR_owner_dec_ref(aux_Test_0_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
  Base_Del(&(self->_base));
}
Returncode use(String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  Test t_Var = {{0}};
  Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  MR_inc_ref(s_Refman);
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(8, 38, "insufficient memory for managed object")
  if (t == NULL) RAISE(9, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base.item_Refman);
  t->_base.item_Refman = s_Refman;
  MR_inc_ref(t->_base.item_Refman);
  t->_base.item_Dynamic = &String_dynamic;
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
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct Test {
  Base _base;
};
void Base_Del(Base* self);
Returncode Test_set(Test* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, String* s, Ref_Manager* s_Refman);
void Test_Del(Test* self);
Generic_Type_Dynamic Base_dynamic = {(Dynamic_Del)Base_Del};
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode use(String* s, Ref_Manager* s_Refman);
void Base_Del(Base* self) {
  if (self == NULL) return;
  MR_dec_ref(self->item_Refman);
}
Returncode Test_set(Test* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  Test* aux_Test_0 = NULL;
  Ref_Manager* aux_Test_0_Refman = NULL;
  MR_inc_ref(i_Refman);
  MR_inc_ref(s_Refman);
  if (self == NULL) RAISE(5, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(5, 38, "used member of outdated weak reference")
  MR_dec_ref(self->_base.item_Refman);
  self->_base.item_Refman = i_Refman;
  MR_inc_ref(self->_base.item_Refman);
  self->_base.item_Dynamic = i_Dynamic;
  self->_base.item = i;
  aux_Test_0 = calloc(1, sizeof(Test));
  if (aux_Test_0 == NULL) RAISE(6, 49, "insufficient memory for object dynamic allocation")
  aux_Test_0_Refman = MR_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(6, 38, "insufficient memory for managed object")
  CHECK(6, Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman, &String_dynamic, s, s_Refman) )
MR_cleanup:
  Test_Del(aux_Test_0);
  MR_owner_dec_ref(aux_Test_0_Refman);
  MR_dec_ref(s_Refman);
  MR_dec_ref(i_Refman);
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
  Base_Del(&(self->_base));
}
Returncode use(String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  Test t_Var = {{0}};
  Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  MR_inc_ref(s_Refman);
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(8, 38, "insufficient memory for managed object")
  if (t == NULL) RAISE(9, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base.item_Refman);
  t->_base.item_Refman = s_Refman;
  MR_inc_ref(t->_base.item_Refman);
  t->_base.item_Dynamic = &String_dynamic;
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
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
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
Returncode Base_set(Base* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic);
void Base_Del(Base* self);
Returncode Mid_set(Mid* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic);
void Mid_Del(Mid* self);
Returncode Top_set(Top* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman);
void Top_Del(Top* self);
Returncode Test_set(Test* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman);
void Test_Del(Test* self);
Generic_Type_Dynamic Base_dynamic = {(Dynamic_Del)Base_Del};
Generic_Type_Dynamic Mid_dynamic = {(Dynamic_Del)Mid_Del};
Generic_Type_Dynamic Top_dynamic = {(Dynamic_Del)Top_Del};
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode use(String* s, Ref_Manager* s_Refman);
Returncode Base_set(Base* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic) {
  Returncode MR_err = OK;
  MR_inc_ref(i_Refman);
MR_cleanup:
  MR_dec_ref(i_Refman);
  return MR_err;
}
void Base_Del(Base* self) {
  if (self == NULL) return;
  MR_dec_ref(self->item_Refman);
}
Returncode Mid_set(Mid* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic) {
  Returncode MR_err = OK;
  MR_inc_ref(i_Refman);
MR_cleanup:
  MR_dec_ref(i_Refman);
  return MR_err;
}
void Mid_Del(Mid* self) {
  if (self == NULL) return;
  Base_Del(&(self->_base));
}
Returncode Top_set(Top* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(s_Refman);
  CHECK(8, Mid_set(&(self->_base), self_Refman, s, s_Refman, &String_dynamic) )
  if (self == NULL) RAISE(9, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  MR_dec_ref(self->_base._base.item_Refman);
  self->_base._base.item_Refman = s_Refman;
  MR_inc_ref(self->_base._base.item_Refman);
  self->_base._base.item_Dynamic = &String_dynamic;
  self->_base._base.item = s;
MR_cleanup:
  MR_dec_ref(s_Refman);
  return MR_err;
}
void Top_Del(Top* self) {
  if (self == NULL) return;
  Mid_Del(&(self->_base));
}
Returncode Test_set(Test* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  Top* aux_Top_0 = NULL;
  Ref_Manager* aux_Top_0_Refman = NULL;
  Test* aux_Test_0 = NULL;
  Ref_Manager* aux_Test_0_Refman = NULL;
  Top* aux_Top_1 = NULL;
  Ref_Manager* aux_Top_1_Refman = NULL;
  MR_inc_ref(s_Refman);
  CHECK(12, Top_set(&(self->_base), self_Refman, s, s_Refman) )
  if (self == NULL) RAISE(13, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(13, 38, "used member of outdated weak reference")
  MR_dec_ref(self->_base._base._base.item_Refman);
  self->_base._base._base.item_Refman = s_Refman;
  MR_inc_ref(self->_base._base._base.item_Refman);
  self->_base._base._base.item_Dynamic = &String_dynamic;
  self->_base._base._base.item = s;
  aux_Top_0 = calloc(1, sizeof(Top));
  if (aux_Top_0 == NULL) RAISE(14, 49, "insufficient memory for object dynamic allocation")
  aux_Top_0_Refman = MR_new_ref(aux_Top_0);
  if (aux_Top_0_Refman == NULL) RAISE(14, 38, "insufficient memory for managed object")
  CHECK(14, Top_set(aux_Top_0, aux_Top_0_Refman, s, s_Refman) )
  aux_Test_0 = calloc(1, sizeof(Test));
  if (aux_Test_0 == NULL) RAISE(15, 49, "insufficient memory for object dynamic allocation")
  aux_Test_0_Refman = MR_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(15, 38, "insufficient memory for managed object")
  CHECK(15, Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman) )
  aux_Top_1 = calloc(1, sizeof(Top));
  if (aux_Top_1 == NULL) RAISE(16, 49, "insufficient memory for object dynamic allocation")
  aux_Top_1_Refman = MR_new_ref(aux_Top_1);
  if (aux_Top_1_Refman == NULL) RAISE(16, 38, "insufficient memory for managed object")
  CHECK(16, Mid_set(&(aux_Top_1->_base), aux_Top_1_Refman, s, s_Refman, &String_dynamic) )
MR_cleanup:
  Top_Del(aux_Top_1);
  MR_owner_dec_ref(aux_Top_1_Refman);
  Test_Del(aux_Test_0);
  MR_owner_dec_ref(aux_Test_0_Refman);
  Top_Del(aux_Top_0);
  MR_owner_dec_ref(aux_Top_0_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
  Top_Del(&(self->_base));
}
Returncode use(String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  Test t_Var = {{{{0}}}};
  Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  MR_inc_ref(s_Refman);
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(18, 38, "insufficient memory for managed object")
  if (t == NULL) RAISE(19, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(19, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base._base._base.item_Refman);
  t->_base._base._base.item_Refman = s_Refman;
  MR_inc_ref(t->_base._base._base.item_Refman);
  t->_base._base._base.item_Dynamic = &String_dynamic;
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
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct Test {
  Base _base;
};
void Base_Del(Base* self);
Returncode Test_set(Test* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, String* s, Ref_Manager* s_Refman);
void Test_Del(Test* self);
Generic_Type_Dynamic Base_dynamic = {(Dynamic_Del)Base_Del};
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode use(String* s, Ref_Manager* s_Refman);
void Base_Del(Base* self) {
  if (self == NULL) return;
  MR_dec_ref(self->item_Refman);
}
Returncode Test_set(Test* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  Test* aux_Test_0 = NULL;
  Ref_Manager* aux_Test_0_Refman = NULL;
  MR_inc_ref(i_Refman);
  MR_inc_ref(s_Refman);
  if (self == NULL) RAISE(5, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(5, 38, "used member of outdated weak reference")
  MR_dec_ref(self->_base.item_Refman);
  self->_base.item_Refman = i_Refman;
  MR_inc_ref(self->_base.item_Refman);
  self->_base.item_Dynamic = i_Dynamic;
  self->_base.item = i;
  aux_Test_0 = calloc(1, sizeof(Test));
  if (aux_Test_0 == NULL) RAISE(6, 49, "insufficient memory for object dynamic allocation")
  aux_Test_0_Refman = MR_new_ref(aux_Test_0);
  if (aux_Test_0_Refman == NULL) RAISE(6, 38, "insufficient memory for managed object")
  CHECK(6, Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman, &String_dynamic, s, s_Refman) )
MR_cleanup:
  Test_Del(aux_Test_0);
  MR_owner_dec_ref(aux_Test_0_Refman);
  MR_dec_ref(s_Refman);
  MR_dec_ref(i_Refman);
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
  Base_Del(&(self->_base));
}
Returncode use(String* s, Ref_Manager* s_Refman) {
  Returncode MR_err = OK;
  Test t_Var = {{0}};
  Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  MR_inc_ref(s_Refman);
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(8, 38, "insufficient memory for managed object")
  if (t == NULL) RAISE(9, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base.item_Refman);
  t->_base.item_Refman = s_Refman;
  MR_inc_ref(t->_base.item_Refman);
  t->_base.item_Dynamic = &String_dynamic;
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
  Ref_Manager* first_Refman;
  Generic_Type_Dynamic* first_Dynamic;
  Generic_Type* second;
  Ref_Manager* second_Refman;
  Generic_Type_Dynamic* second_Dynamic;
};
struct Mid {
  Base _base;
  Generic_Type* third;
  Ref_Manager* third_Refman;
  Generic_Type_Dynamic* third_Dynamic;
};
struct Top {
  Mid _base;
};
struct Test {
  Top _base;
};
void Base_Del(Base* self);
Returncode Mid_set(Mid* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic);
void Mid_Del(Mid* self);
Returncode Top_set(Top* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
void Top_Del(Top* self);
Returncode Test_set(Test* self, Ref_Manager* self_Refman, String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
void Test_Del(Test* self);
Generic_Type_Dynamic Base_dynamic = {(Dynamic_Del)Base_Del};
Generic_Type_Dynamic Mid_dynamic = {(Dynamic_Del)Mid_Del};
Generic_Type_Dynamic Top_dynamic = {(Dynamic_Del)Top_Del};
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode use(String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
void Base_Del(Base* self) {
  if (self == NULL) return;
  MR_dec_ref(self->second_Refman);
  MR_dec_ref(self->first_Refman);
}
Returncode Mid_set(Mid* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic) {
  Returncode MR_err = OK;
  MR_inc_ref(first_Refman);
  MR_inc_ref(second_Refman);
  MR_inc_ref(third_Refman);
  if (self == NULL) RAISE(7, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(7, 38, "used member of outdated weak reference")
  MR_dec_ref(self->_base.first_Refman);
  self->_base.first_Refman = first_Refman;
  MR_inc_ref(self->_base.first_Refman);
  self->_base.first_Dynamic = first_Dynamic;
  self->_base.first = first;
  if (self == NULL) RAISE(8, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(8, 38, "used member of outdated weak reference")
  MR_dec_ref(self->_base.second_Refman);
  self->_base.second_Refman = second_Refman;
  MR_inc_ref(self->_base.second_Refman);
  self->_base.second_Dynamic = &Sys_dynamic;
  self->_base.second = second;
  if (self == NULL) RAISE(9, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  MR_dec_ref(self->third_Refman);
  self->third_Refman = third_Refman;
  MR_inc_ref(self->third_Refman);
  self->third_Dynamic = third_Dynamic;
  self->third = third;
MR_cleanup:
  MR_dec_ref(third_Refman);
  MR_dec_ref(second_Refman);
  MR_dec_ref(first_Refman);
  return MR_err;
}
void Mid_Del(Mid* self) {
  if (self == NULL) return;
  Base_Del(&(self->_base));
  MR_dec_ref(self->third_Refman);
}
Returncode Top_set(Top* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(first_Refman);
  MR_inc_ref(second_Refman);
  MR_inc_ref(third_Refman);
  if (self == NULL) RAISE(12, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(12, 38, "used member of outdated weak reference")
  MR_dec_ref(self->_base._base.first_Refman);
  self->_base._base.first_Refman = first_Refman;
  MR_inc_ref(self->_base._base.first_Refman);
  self->_base._base.first_Dynamic = first_Dynamic;
  self->_base._base.first = first;
  if (self == NULL) RAISE(13, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(13, 38, "used member of outdated weak reference")
  MR_dec_ref(self->_base._base.second_Refman);
  self->_base._base.second_Refman = second_Refman;
  MR_inc_ref(self->_base._base.second_Refman);
  self->_base._base.second_Dynamic = &Sys_dynamic;
  self->_base._base.second = second;
  if (self == NULL) RAISE(14, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(14, 38, "used member of outdated weak reference")
  MR_dec_ref(self->_base.third_Refman);
  self->_base.third_Refman = third_Refman;
  MR_inc_ref(self->_base.third_Refman);
  self->_base.third_Dynamic = &File_dynamic;
  self->_base.third = third;
MR_cleanup:
  MR_dec_ref(third_Refman);
  MR_dec_ref(second_Refman);
  MR_dec_ref(first_Refman);
  return MR_err;
}
void Top_Del(Top* self) {
  if (self == NULL) return;
  Mid_Del(&(self->_base));
}
Returncode Test_set(Test* self, Ref_Manager* self_Refman, String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(first_Refman);
  MR_inc_ref(second_Refman);
  MR_inc_ref(third_Refman);
  if (self == NULL) RAISE(17, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(17, 38, "used member of outdated weak reference")
  MR_dec_ref(self->_base._base._base.first_Refman);
  self->_base._base._base.first_Refman = first_Refman;
  MR_inc_ref(self->_base._base._base.first_Refman);
  self->_base._base._base.first_Dynamic = &String_dynamic;
  self->_base._base._base.first = first;
  if (self == NULL) RAISE(18, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(18, 38, "used member of outdated weak reference")
  MR_dec_ref(self->_base._base._base.second_Refman);
  self->_base._base._base.second_Refman = second_Refman;
  MR_inc_ref(self->_base._base._base.second_Refman);
  self->_base._base._base.second_Dynamic = &Sys_dynamic;
  self->_base._base._base.second = second;
  if (self == NULL) RAISE(19, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(19, 38, "used member of outdated weak reference")
  MR_dec_ref(self->_base._base.third_Refman);
  self->_base._base.third_Refman = third_Refman;
  MR_inc_ref(self->_base._base.third_Refman);
  self->_base._base.third_Dynamic = &File_dynamic;
  self->_base._base.third = third;
MR_cleanup:
  MR_dec_ref(third_Refman);
  MR_dec_ref(second_Refman);
  MR_dec_ref(first_Refman);
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
  Top_Del(&(self->_base));
}
Returncode use(String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
  Returncode MR_err = OK;
  Test t_Var = {{{{0}}}};
  Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  MR_inc_ref(first_Refman);
  MR_inc_ref(second_Refman);
  MR_inc_ref(third_Refman);
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(21, 38, "insufficient memory for managed object")
  if (t == NULL) RAISE(22, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(22, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base._base._base.first_Refman);
  t->_base._base._base.first_Refman = first_Refman;
  MR_inc_ref(t->_base._base._base.first_Refman);
  t->_base._base._base.first_Dynamic = &String_dynamic;
  t->_base._base._base.first = first;
  if (t == NULL) RAISE(23, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(23, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base._base._base.second_Refman);
  t->_base._base._base.second_Refman = second_Refman;
  MR_inc_ref(t->_base._base._base.second_Refman);
  t->_base._base._base.second_Dynamic = &Sys_dynamic;
  t->_base._base._base.second = second;
  if (t == NULL) RAISE(24, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(24, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base._base.third_Refman);
  t->_base._base.third_Refman = third_Refman;
  MR_inc_ref(t->_base._base.third_Refman);
  t->_base._base.third_Dynamic = &File_dynamic;
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
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct Second {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
struct Test {
  First _base;
};
void First_Del(First* self);
void Second_Del(Second* self);
Returncode Test_set(Test* self, Ref_Manager* self_Refman, Generic_Type* g, Ref_Manager* g_Refman, Generic_Type_Dynamic* g_Dynamic, Second* sg, Ref_Manager* sg_Refman);
void Test_Del(Test* self);
Generic_Type_Dynamic First_dynamic = {(Dynamic_Del)First_Del};
Generic_Type_Dynamic Second_dynamic = {(Dynamic_Del)Second_Del};
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode use(String* s, Ref_Manager* s_Refman, Second* ss, Ref_Manager* ss_Refman);
void First_Del(First* self) {
  if (self == NULL) return;
  MR_dec_ref(self->item_Refman);
}
void Second_Del(Second* self) {
  if (self == NULL) return;
  MR_dec_ref(self->item_Refman);
}
Returncode Test_set(Test* self, Ref_Manager* self_Refman, Generic_Type* g, Ref_Manager* g_Refman, Generic_Type_Dynamic* g_Dynamic, Second* sg, Ref_Manager* sg_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(g_Refman);
  MR_inc_ref(sg_Refman);
  if (self == NULL) RAISE(7, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(7, 38, "used member of outdated weak reference")
  MR_dec_ref(self->_base.item_Refman);
  self->_base.item_Refman = sg_Refman;
  MR_inc_ref(self->_base.item_Refman);
  self->_base.item_Dynamic = &Second_dynamic;
  self->_base.item = sg;
  if (self == NULL) RAISE(8, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(8, 38, "used member of outdated weak reference")
  if (self->_base.item == NULL) RAISE(8, 27, "used member of empty object")
  if (self->_base.item_Refman->value == NULL) RAISE(8, 38, "used member of outdated weak reference")
  MR_dec_ref(((Second*)(self->_base.item))->item_Refman);
  ((Second*)(self->_base.item))->item_Refman = g_Refman;
  MR_inc_ref(((Second*)(self->_base.item))->item_Refman);
  ((Second*)(self->_base.item))->item_Dynamic = g_Dynamic;
  ((Second*)(self->_base.item))->item = g;
MR_cleanup:
  MR_dec_ref(sg_Refman);
  MR_dec_ref(g_Refman);
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
  First_Del(&(self->_base));
}
Returncode use(String* s, Ref_Manager* s_Refman, Second* ss, Ref_Manager* ss_Refman) {
  Returncode MR_err = OK;
  Test t_Var = {{0}};
  Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  MR_inc_ref(s_Refman);
  MR_inc_ref(ss_Refman);
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(10, 38, "insufficient memory for managed object")
  if (t == NULL) RAISE(11, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(11, 38, "used member of outdated weak reference")
  MR_dec_ref(t->_base.item_Refman);
  t->_base.item_Refman = ss_Refman;
  MR_inc_ref(t->_base.item_Refman);
  t->_base.item_Dynamic = &Second_dynamic;
  t->_base.item = ss;
  if (t == NULL) RAISE(12, 27, "used member of empty object")
  if (t_Refman->value == NULL) RAISE(12, 38, "used member of outdated weak reference")
  if (t->_base.item == NULL) RAISE(12, 27, "used member of empty object")
  if (t->_base.item_Refman->value == NULL) RAISE(12, 38, "used member of outdated weak reference")
  MR_dec_ref(((Second*)(t->_base.item))->item_Refman);
  ((Second*)(t->_base.item))->item_Refman = s_Refman;
  MR_inc_ref(((Second*)(t->_base.item))->item_Refman);
  ((Second*)(t->_base.item))->item_Dynamic = &String_dynamic;
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
/// @@ test-error-handling
/// @ t0
do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; break
    if (t == NULL) RAISE(2, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
    t->num = 1;
    CHECK(3, fun0() )
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  } while (false);
  --MR_trace_ignore_count;
  if (MR_err != OK) {
    MR_err = OK;
    if (t == NULL) RAISE(5, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(5, 38, "used member of outdated weak reference")
    i = t->num;
    CHECK(6, fun4(2) )
  }
/// @ t1
do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; break
    if (t == NULL) RAISE(2, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
    t->num = 1;
    CHECK(3, fun0() )
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  } while (false);
  --MR_trace_ignore_count;
  MR_err = OK;
/// @ t2
do {
    ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; break
    if (t == NULL) RAISE(2, 27, "used member of empty object")
    if (t_Refman->value == NULL) RAISE(2, 38, "used member of outdated weak reference")
    t->num = 1;
    do {
      ++MR_trace_ignore_count;
      CHECK(4, fun0() )
    } while (false);
    --MR_trace_ignore_count;
    if (MR_err != OK) {
      MR_err = OK;
      CHECK(6, fun4(2) )
    }
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
  } while (false);
  --MR_trace_ignore_count;
  if (MR_err != OK) {
    MR_err = OK;
    do {
      ++MR_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; break
      if (arr == NULL) RAISE(9, 29, "empty object used as sequence")
      if (arr_Refman->value == NULL) RAISE(9, 40, "outdated weak reference used as sequence")
      if ((3) < 0 || (3) >= (arr)->length) RAISE(9, 25, "slice index out of bounds")
      i = ((Int*)((arr)->values))[3];
#undef RETURN_ERROR
#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup
    } while (false);
    --MR_trace_ignore_count;
    if (MR_err != OK) {
      MR_err = OK;
      if (t == NULL) RAISE(11, 27, "used member of empty object")
      if (t_Refman->value == NULL) RAISE(11, 38, "used member of outdated weak reference")
      i = t->num;
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
typedef struct TestIterator TestIterator;
struct TestIterator {
  Int counter;
};
Returncode TestIterator_new(TestIterator* self, Ref_Manager* self_Refman, Int count);
Returncode TestIterator_has(TestIterator* self, Ref_Manager* self_Refman, Bool* has_data);
Returncode TestIterator_get(TestIterator* self, Ref_Manager* self_Refman, Int* num);
Returncode TestIterator_next(TestIterator* self, Ref_Manager* self_Refman);
void TestIterator_Del(TestIterator* self);
Generic_Type_Dynamic TestIterator_dynamic = {(Dynamic_Del)TestIterator_Del};
Returncode f_mock(Int* i);
Returncode TestIterator_new(TestIterator* self, Ref_Manager* self_Refman, Int count) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode TestIterator_has(TestIterator* self, Ref_Manager* self_Refman, Bool* has_data) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode TestIterator_get(TestIterator* self, Ref_Manager* self_Refman, Int* num) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode TestIterator_next(TestIterator* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void TestIterator_Del(TestIterator* self) {
  if (self == NULL) return;
}
Returncode f_mock(Int* i) {
  Returncode MR_err = OK;
  TestIterator* aux_TestIterator_0 = NULL;
  Ref_Manager* aux_TestIterator_0_Refman = NULL;
  Int n = 0;
  TestIterator* aux_TestIterator_1 = NULL;
  Ref_Manager* aux_TestIterator_1_Refman = NULL;
  aux_TestIterator_0 = calloc(1, sizeof(TestIterator));
  if (aux_TestIterator_0 == NULL) RAISE(8, 49, "insufficient memory for object dynamic allocation")
  aux_TestIterator_0_Refman = MR_new_ref(aux_TestIterator_0);
  if (aux_TestIterator_0_Refman == NULL) RAISE(8, 38, "insufficient memory for managed object")
  CHECK(8, TestIterator_new(aux_TestIterator_0, aux_TestIterator_0_Refman, 6) )
  MR_dec_ref(aux_TestIterator_1_Refman);
  aux_TestIterator_1_Refman = aux_TestIterator_0_Refman;
  MR_inc_ref(aux_TestIterator_1_Refman);
  aux_TestIterator_1 = aux_TestIterator_0;
  while (true) {
    Bool n_Has = false;
    CHECK(8, TestIterator_has(aux_TestIterator_1, aux_TestIterator_1_Refman, &(n_Has)) )
    if (!n_Has) break;
    CHECK(8, TestIterator_get(aux_TestIterator_1, aux_TestIterator_1_Refman, &(n)) )
    *i = n;
    CHECK(8, TestIterator_next(aux_TestIterator_1, aux_TestIterator_1_Refman) )
  }
  MR_dec_ref(aux_TestIterator_1_Refman);
  aux_TestIterator_1_Refman = NULL;
  MR_inc_ref(aux_TestIterator_1_Refman);
  aux_TestIterator_1 = NULL;
MR_cleanup:
  MR_dec_ref(aux_TestIterator_1_Refman);
  TestIterator_Del(aux_TestIterator_0);
  MR_owner_dec_ref(aux_TestIterator_0_Refman);
  return MR_err;
}
/// @ t1
typedef struct TestIterator TestIterator;
struct TestIterator {
  String* value;
  Ref_Manager* value_Refman;
};
Returncode TestIterator_has(TestIterator* self, Ref_Manager* self_Refman, Bool* has_data);
Returncode TestIterator_get(TestIterator* self, Ref_Manager* self_Refman, String** text, Ref_Manager** text_Refman);
Returncode TestIterator_next(TestIterator* self, Ref_Manager* self_Refman);
void TestIterator_Del(TestIterator* self);
Generic_Type_Dynamic TestIterator_dynamic = {(Dynamic_Del)TestIterator_Del};
Returncode f_mock(TestIterator* iter, Ref_Manager* iter_Refman, String** s, Ref_Manager** s_Refman);
Returncode TestIterator_has(TestIterator* self, Ref_Manager* self_Refman, Bool* has_data) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode TestIterator_get(TestIterator* self, Ref_Manager* self_Refman, String** text, Ref_Manager** text_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode TestIterator_next(TestIterator* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void TestIterator_Del(TestIterator* self) {
  if (self == NULL) return;
  MR_dec_ref(self->value_Refman);
}
Returncode f_mock(TestIterator* iter, Ref_Manager* iter_Refman, String** s, Ref_Manager** s_Refman) {
  Returncode MR_err = OK;
  String* t = NULL;
  Ref_Manager* t_Refman = NULL;
  TestIterator* aux_TestIterator_0 = NULL;
  Ref_Manager* aux_TestIterator_0_Refman = NULL;
  MR_inc_ref(iter_Refman);
  MR_dec_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0_Refman = iter_Refman;
  MR_inc_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0 = iter;
  while (true) {
    Bool t_Has = false;
    CHECK(7, TestIterator_has(aux_TestIterator_0, aux_TestIterator_0_Refman, &(t_Has)) )
    if (!t_Has) break;
    CHECK(7, TestIterator_get(aux_TestIterator_0, aux_TestIterator_0_Refman, &(t), &(t_Refman)) )
    MR_dec_ref(*s_Refman);
    *s_Refman = t_Refman;
    MR_inc_ref(*s_Refman);
    *s = t;
    CHECK(7, TestIterator_next(aux_TestIterator_0, aux_TestIterator_0_Refman) )
  }
  MR_dec_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0_Refman = NULL;
  MR_inc_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0 = NULL;
MR_cleanup:
  MR_dec_ref(aux_TestIterator_0_Refman);
  MR_dec_ref(t_Refman);
  MR_dec_ref(iter_Refman);
  return MR_err;
}
/// @ t2
typedef struct TestIterator TestIterator;
struct TestIterator {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
};
Returncode TestIterator_has(TestIterator* self, Ref_Manager* self_Refman, Bool* has_data);
Returncode TestIterator_get(TestIterator* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
Returncode TestIterator_next(TestIterator* self, Ref_Manager* self_Refman);
void TestIterator_Del(TestIterator* self);
Generic_Type_Dynamic TestIterator_dynamic = {(Dynamic_Del)TestIterator_Del};
Returncode f_mock(TestIterator* iter, Ref_Manager* iter_Refman, String** s, Ref_Manager** s_Refman);
Returncode TestIterator_has(TestIterator* self, Ref_Manager* self_Refman, Bool* has_data) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode TestIterator_get(TestIterator* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode TestIterator_next(TestIterator* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void TestIterator_Del(TestIterator* self) {
  if (self == NULL) return;
  MR_dec_ref(self->item_Refman);
}
Returncode f_mock(TestIterator* iter, Ref_Manager* iter_Refman, String** s, Ref_Manager** s_Refman) {
  Returncode MR_err = OK;
  String* t = NULL;
  Ref_Manager* t_Refman = NULL;
  TestIterator* aux_TestIterator_0 = NULL;
  Ref_Manager* aux_TestIterator_0_Refman = NULL;
  MR_inc_ref(iter_Refman);
  MR_dec_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0_Refman = iter_Refman;
  MR_inc_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0 = iter;
  while (true) {
    Bool t_Has = false;
    CHECK(7, TestIterator_has(aux_TestIterator_0, aux_TestIterator_0_Refman, &(t_Has)) )
    if (!t_Has) break;
    CHECK(7, TestIterator_get(aux_TestIterator_0, aux_TestIterator_0_Refman, (void*)&(t), &(t_Refman), &dynamic_Void) )
    MR_dec_ref(*s_Refman);
    *s_Refman = t_Refman;
    MR_inc_ref(*s_Refman);
    *s = t;
    CHECK(7, TestIterator_next(aux_TestIterator_0, aux_TestIterator_0_Refman) )
  }
  MR_dec_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0_Refman = NULL;
  MR_inc_ref(aux_TestIterator_0_Refman);
  aux_TestIterator_0 = NULL;
MR_cleanup:
  MR_dec_ref(aux_TestIterator_0_Refman);
  MR_dec_ref(t_Refman);
  MR_dec_ref(iter_Refman);
  return MR_err;
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
typedef struct Base Base;
typedef struct Base_Dynamic Base_Dynamic;
typedef struct Test Test;
struct Base {
  Base* b;
  Ref_Manager* b_Refman;
  Base_Dynamic* b_Dynamic;
};
struct Base_Dynamic {
  Dynamic_Del _del;
  Returncode (*meth)(Base* self, Ref_Manager* self_Refman, Base_Dynamic* self_Dynamic);
};
struct Test {
  Base b;
};
Returncode Base_meth(Base* self, Ref_Manager* self_Refman, Base_Dynamic* self_Dynamic);
void Base_Del(Base* self);
Returncode Test_test(Test* self, Ref_Manager* self_Refman);
void Test_Del(Test* self);
Base_Dynamic Base_dynamic = {(Dynamic_Del)Base_Del, Base_meth};
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Returncode Base_meth(Base* self, Ref_Manager* self_Refman, Base_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Base_Del(Base* self) {
  if (self == NULL) return;
  MR_dec_ref(self->b_Refman);
}
Returncode Test_test(Test* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
  Base* b = NULL;
  Ref_Manager* b_Refman = NULL;
  Base_Dynamic* b_Dynamic = NULL;
  Base* b2 = NULL;
  Ref_Manager* b2_Refman = NULL;
  Base_Dynamic* b2_Dynamic = NULL;
  Test t_Var = {{0}};
  Test* t = NULL;
  Ref_Manager* t_Refman = NULL;
  if (self == NULL) RAISE(7, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(7, 38, "used member of outdated weak reference")
  b = &(self->b);
  b_Refman = self_Refman;
  MR_inc_ref(b_Refman);
  b_Dynamic = &Base_dynamic;
  if (self == NULL) RAISE(8, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(8, 38, "used member of outdated weak reference")
  MR_dec_ref(b_Refman);
  b_Refman = self_Refman;
  MR_inc_ref(b_Refman);
  b_Dynamic = &Base_dynamic;
  b = &(self->b);
  if (self == NULL) RAISE(9, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(9, 38, "used member of outdated weak reference")
  CHECK(9, Base_meth(&(self->b), self_Refman, &Base_dynamic) )
  if (self == NULL) RAISE(10, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(10, 38, "used member of outdated weak reference")
  CHECK(10, Base_meth(&(self->b), self_Refman, &Base_dynamic) )
  if (self == NULL) RAISE(11, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(11, 38, "used member of outdated weak reference")
  b2 = self->b.b;
  b2_Refman = self->b.b_Refman;
  MR_inc_ref(b2_Refman);
  b2_Dynamic = self->b.b_Dynamic;
  if (self == NULL) RAISE(12, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(12, 38, "used member of outdated weak reference")
  MR_dec_ref(b2_Refman);
  b2_Refman = self->b.b_Refman;
  MR_inc_ref(b2_Refman);
  b2_Dynamic = self->b.b_Dynamic;
  b2 = self->b.b;
  if (self->b.b_Dynamic == NULL) RAISE(13, 28, "dynamic call of empty object")
  if (self == NULL) RAISE(13, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(13, 38, "used member of outdated weak reference")
  CHECK(13, self->b.b_Dynamic->meth(self->b.b, self->b.b_Refman, self->b.b_Dynamic) )
  if (self == NULL) RAISE(14, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(14, 38, "used member of outdated weak reference")
  CHECK(14, Base_meth(self->b.b, self->b.b_Refman, self->b.b_Dynamic) )
  t = &t_Var;
  t_Refman = MR_new_ref(t);
  if (t_Refman == NULL) RAISE(15, 38, "insufficient memory for managed object")
MR_cleanup:
  MR_dec_ref(t_Refman);
  MR_dec_ref(b2_Refman);
  MR_dec_ref(b_Refman);
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
  Base_Del(&(self->b));
}
/// @ te0
cannot declared "var" field of sequence type "String"
/// @ te1
cannot declared "var" field of sequence type "Array"
/// @ te2
variable will cause recursive declaration of type "Test"
/// @ te3
variable will cause recursive declaration of type "Test"
/// @
