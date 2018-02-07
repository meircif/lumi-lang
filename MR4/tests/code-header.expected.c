
typedef struct Test Test;
typedef struct Ta Ta;
typedef struct Ta_Dynamic Ta_Dynamic;
typedef struct Tb Tb;
typedef struct Tb_Dynamic Tb_Dynamic;
typedef struct Tc Tc;
typedef struct Tc_Dynamic Tc_Dynamic;
typedef struct Data Data;
struct Test {
  Int num;
  Test* t;
  Ref_Manager* t_Refman;
  Returncode (*fun)(void);
};
struct Ta {
  Test _base;
  Int numa;
};
struct Ta_Dynamic {
  Dynamic_Del _del;
  Returncode (*dyn)(Ta* self, Ref_Manager* self_Refman, Ta_Dynamic* self_Dynamic);
};
struct Tb {
  Ta _base;
  Int numb;
};
struct Tb_Dynamic {
  Ta_Dynamic _base;
};
struct Tc {
  Tb _base;
  Int numc;
};
struct Tc_Dynamic {
  Tb_Dynamic _base;
};
struct Data {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
  Array* arr;
  Ref_Manager* arr_Refman;
};
Returncode Test_new(Test* self, Ref_Manager* self_Refman, Int num);
Returncode Test_meth(Test* self, Ref_Manager* self_Refman);
void Test_Del(Test* self);
Returncode Ta_metha(Ta* self, Ref_Manager* self_Refman, Ta_Dynamic* self_Dynamic);
Returncode Ta_dyn(Ta* self, Ref_Manager* self_Refman, Ta_Dynamic* self_Dynamic);
void Ta_Del(Ta* self);
Returncode Tb_methb(Tb* self, Ref_Manager* self_Refman, Tb_Dynamic* self_Dynamic);
Returncode Tb_dyn(Tb* self, Ref_Manager* self_Refman, Tb_Dynamic* self_Dynamic);
void Tb_Del(Tb* self);
Returncode Tc_methc(Tc* self, Ref_Manager* self_Refman, Tc_Dynamic* self_Dynamic);
Returncode Tc_dyn(Tc* self, Ref_Manager* self_Refman, Tc_Dynamic* self_Dynamic);
void Tc_Del(Tc* self);
Returncode Data_set(Data* self, Ref_Manager* self_Refman, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic, Array* arr, Ref_Manager* arr_Refman);
Returncode Data_get(Data* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void Data_Del(Data* self);
Generic_Type_Dynamic Test_dynamic = {(Dynamic_Del)Test_Del};
Ta_Dynamic Ta_dynamic = {(Dynamic_Del)Ta_Del, Ta_dyn};
Tb_Dynamic Tb_dynamic = {{(Dynamic_Del)Tb_Del, (Func)Tb_dyn}};
Tc_Dynamic Tc_dynamic = {{{(Dynamic_Del)Tc_Del, (Func)Tc_dyn}}};
Generic_Type_Dynamic Data_dynamic = {(Dynamic_Del)Data_Del};
Int i = 0;
Char c = 0;
Bool b = 0;
String* str = NULL;
Ref_Manager* str_Refman = NULL;
Array* arr = NULL;
Ref_Manager* arr_Refman = NULL;
File* fobj = NULL;
Ref_Manager* fobj_Refman = NULL;
Test* t = NULL;
Ref_Manager* t_Refman = NULL;
Ta* ta = NULL;
Ref_Manager* ta_Refman = NULL;
Ta_Dynamic* ta_Dynamic = NULL;
Tb* tb = NULL;
Ref_Manager* tb_Refman = NULL;
Tb_Dynamic* tb_Dynamic = NULL;
Tc* tc = NULL;
Ref_Manager* tc_Refman = NULL;
Tc_Dynamic* tc_Dynamic = NULL;
Data* d = NULL;
Ref_Manager* d_Refman = NULL;
Array* sarr = NULL;
Ref_Manager* sarr_Refman = NULL;
Returncode fun0(void);
Returncode fun1(Int x, String* s, Ref_Manager* s_Refman, String* o, Ref_Manager* o_Refman);
Returncode fun2(String** s, Ref_Manager** s_Refman, Int* x);
Returncode fun3(Int x, String** s, Ref_Manager** s_Refman);
Returncode fun4(Int x);
Returncode fun5(Int x, Int* y);
Returncode fun6(Int x, Int y, Int* n, Int* m);
Returncode fun7(Tb** tb, Ref_Manager** tb_Refman, Tb_Dynamic** tb_Dynamic);
Returncode mock(String** so, Ref_Manager** so_Refman, Int* io, Test** to, Ref_Manager** to_Refman, Tc** tco, Ref_Manager** tco_Refman, Tc_Dynamic** tco_Dynamic);
Returncode Test_new(Test* self, Ref_Manager* self_Refman, Int num) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Test_meth(Test* self, Ref_Manager* self_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Test_Del(Test* self) {
  if (self == NULL) return;
  MR_dec_ref(self->t_Refman);
}
Returncode Ta_metha(Ta* self, Ref_Manager* self_Refman, Ta_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Ta_dyn(Ta* self, Ref_Manager* self_Refman, Ta_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Ta_Del(Ta* self) {
  if (self == NULL) return;
  Test_Del(&(self->_base));
}
Returncode Tb_methb(Tb* self, Ref_Manager* self_Refman, Tb_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Tb_dyn(Tb* self, Ref_Manager* self_Refman, Tb_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Tb_Del(Tb* self) {
  if (self == NULL) return;
  Ta_Del(&(self->_base));
}
Returncode Tc_methc(Tc* self, Ref_Manager* self_Refman, Tc_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode Tc_dyn(Tc* self, Ref_Manager* self_Refman, Tc_Dynamic* self_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Tc_Del(Tc* self) {
  if (self == NULL) return;
  Tb_Del(&(self->_base));
}
Returncode Data_set(Data* self, Ref_Manager* self_Refman, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic, Array* arr, Ref_Manager* arr_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(arr_Refman);
MR_cleanup:
  MR_dec_ref(arr_Refman);
  if (item_Dynamic != NULL) item_Dynamic->_del(item);
  MR_owner_dec_ref(item_Refman);
  return MR_err;
}
Returncode Data_get(Data* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
void Data_Del(Data* self) {
  if (self == NULL) return;
  MR_dec_ref(self->arr_Refman);
  MR_dec_ref(self->item_Refman);
}
Returncode fun0(void) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun1(Int x, String* s, Ref_Manager* s_Refman, String* o, Ref_Manager* o_Refman) {
  Returncode MR_err = OK;
  MR_inc_ref(s_Refman);
MR_cleanup:
  String_Del(o);
  MR_owner_dec_ref(o_Refman);
  MR_dec_ref(s_Refman);
  return MR_err;
}
Returncode fun2(String** s, Ref_Manager** s_Refman, Int* x) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun3(Int x, String** s, Ref_Manager** s_Refman) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun4(Int x) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun5(Int x, Int* y) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun6(Int x, Int y, Int* n, Int* m) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode fun7(Tb** tb, Ref_Manager** tb_Refman, Tb_Dynamic** tb_Dynamic) {
  Returncode MR_err = OK;
MR_cleanup:
  return MR_err;
}
Returncode mock(String** so, Ref_Manager** so_Refman, Int* io, Test** to, Ref_Manager** to_Refman, Tc** tco, Ref_Manager** tco_Refman, Tc_Dynamic** tco_Dynamic) {
  Returncode MR_err = OK;
  