
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Ta ut_M_Ta;
typedef struct ut_M_Ta_Dynamic ut_M_Ta_Dynamic;
typedef struct ut_M_Tb ut_M_Tb;
typedef struct ut_M_Tb_Dynamic ut_M_Tb_Dynamic;
typedef struct ut_M_Tc ut_M_Tc;
typedef struct ut_M_Tc_Dynamic ut_M_Tc_Dynamic;
typedef struct ut_M_Data ut_M_Data;
struct ut_M_Test {
  Int num;
  ut_M_Test* t;
  Ref_Manager* t_Refman;
  Returncode (*fun)(void);
};
struct ut_M_Ta {
  ut_M_Test _base;
  Int numa;
};
struct ut_M_Ta_Dynamic {
  Dynamic_Del _del;
  Returncode (*dyn)(ut_M_Ta* self, Ref_Manager* self_Refman, ut_M_Ta_Dynamic* self_Dynamic);
};
struct ut_M_Tb {
  ut_M_Ta _base;
  Int numb;
};
struct ut_M_Tb_Dynamic {
  ut_M_Ta_Dynamic _base;
};
struct ut_M_Tc {
  ut_M_Tb _base;
  Int numc;
};
struct ut_M_Tc_Dynamic {
  ut_M_Tb_Dynamic _base;
};
struct ut_M_Data {
  Generic_Type* item;
  Ref_Manager* item_Refman;
  Generic_Type_Dynamic* item_Dynamic;
  Array* arr;
  Ref_Manager* arr_Refman;
};
Returncode ut_M_Test_new(ut_M_Test* self, Ref_Manager* self_Refman, Int num);
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_Ta_metha(ut_M_Ta* self, Ref_Manager* self_Refman, ut_M_Ta_Dynamic* self_Dynamic);
Returncode ut_M_Ta_dyn(ut_M_Ta* self, Ref_Manager* self_Refman, ut_M_Ta_Dynamic* self_Dynamic);
void ut_M_Ta_Del(ut_M_Ta* self);
Returncode ut_M_Tb_methb(ut_M_Tb* self, Ref_Manager* self_Refman, ut_M_Tb_Dynamic* self_Dynamic);
Returncode ut_M_Tb_dyn(ut_M_Tb* self, Ref_Manager* self_Refman, ut_M_Tb_Dynamic* self_Dynamic);
void ut_M_Tb_Del(ut_M_Tb* self);
Returncode ut_M_Tc_methc(ut_M_Tc* self, Ref_Manager* self_Refman, ut_M_Tc_Dynamic* self_Dynamic);
Returncode ut_M_Tc_dyn(ut_M_Tc* self, Ref_Manager* self_Refman, ut_M_Tc_Dynamic* self_Dynamic);
void ut_M_Tc_Del(ut_M_Tc* self);
Returncode ut_M_Data_set(ut_M_Data* self, Ref_Manager* self_Refman, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic, Array* arr, Ref_Manager* arr_Refman);
Returncode ut_M_Data_get(ut_M_Data* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Data_Del(ut_M_Data* self);
Returncode ut_M_fun0(void);
Returncode ut_M_fun1(Int x, String* s, Ref_Manager* s_Refman, String* o, Ref_Manager* o_Refman);
Returncode ut_M_fun2(String** s, Ref_Manager** s_Refman, Int* x);
Returncode ut_M_fun3(Int x, String** s, Ref_Manager** s_Refman);
Returncode ut_M_fun4(Int x);
Returncode ut_M_fun5(Int x, Int* y);
Returncode ut_M_fun6(Int x, Int y, Int* n, Int* m);
Returncode ut_M_fun7(ut_M_Tb* tb, Ref_Manager* tb_Refman, ut_M_Tb_Dynamic* tb_Dynamic, ut_M_Tb** tbo, Ref_Manager** tbo_Refman, ut_M_Tb_Dynamic** tbo_Dynamic);
Returncode ut_M_mock(String** so, Ref_Manager** so_Refman, Int* io, ut_M_Test** to, Ref_Manager** to_Refman, ut_M_Tc** tco, Ref_Manager** tco_Refman, ut_M_Tc_Dynamic** tco_Dynamic);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
ut_M_Ta_Dynamic ut_M_Ta_dynamic = {(Dynamic_Del)ut_M_Ta_Del, ut_M_Ta_dyn};
ut_M_Tb_Dynamic ut_M_Tb_dynamic = {{(Dynamic_Del)ut_M_Tb_Del, (Func)ut_M_Tb_dyn}};
ut_M_Tc_Dynamic ut_M_Tc_dynamic = {{{(Dynamic_Del)ut_M_Tc_Del, (Func)ut_M_Tc_dyn}}};
Generic_Type_Dynamic ut_M_Data_dynamic = {(Dynamic_Del)ut_M_Data_Del};
Int ut_M_i = 0;
Char ut_M_c = 0;
Bool ut_M_b = 0;
String* ut_M_str = NULL;
Ref_Manager* ut_M_str_Refman = NULL;
Array* ut_M_arr = NULL;
Ref_Manager* ut_M_arr_Refman = NULL;
File* ut_M_fobj = NULL;
Ref_Manager* ut_M_fobj_Refman = NULL;
ut_M_Test* ut_M_t = NULL;
Ref_Manager* ut_M_t_Refman = NULL;
ut_M_Ta* ut_M_ta = NULL;
Ref_Manager* ut_M_ta_Refman = NULL;
ut_M_Ta_Dynamic* ut_M_ta_Dynamic = NULL;
ut_M_Tb* ut_M_tb = NULL;
Ref_Manager* ut_M_tb_Refman = NULL;
ut_M_Tb_Dynamic* ut_M_tb_Dynamic = NULL;
ut_M_Tc* ut_M_tc = NULL;
Ref_Manager* ut_M_tc_Refman = NULL;
ut_M_Tc_Dynamic* ut_M_tc_Dynamic = NULL;
ut_M_Data* ut_M_d = NULL;
Ref_Manager* ut_M_d_Refman = NULL;
Array* ut_M_sarr = NULL;
Ref_Manager* ut_M_sarr_Refman = NULL;
Returncode ut_M_Test_new(ut_M_Test* self, Ref_Manager* self_Refman, Int num) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->t_Refman);
}
Returncode ut_M_Ta_metha(ut_M_Ta* self, Ref_Manager* self_Refman, ut_M_Ta_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_Ta_dyn(ut_M_Ta* self, Ref_Manager* self_Refman, ut_M_Ta_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Ta_Del(ut_M_Ta* self) {
  if (self == NULL) return;
  ut_M_Test_Del(&(self->_base));
}
Returncode ut_M_Tb_methb(ut_M_Tb* self, Ref_Manager* self_Refman, ut_M_Tb_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_Tb_dyn(ut_M_Tb* self, Ref_Manager* self_Refman, ut_M_Tb_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Tb_Del(ut_M_Tb* self) {
  if (self == NULL) return;
  ut_M_Ta_Del(&(self->_base));
}
Returncode ut_M_Tc_methc(ut_M_Tc* self, Ref_Manager* self_Refman, ut_M_Tc_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_Tc_dyn(ut_M_Tc* self, Ref_Manager* self_Refman, ut_M_Tc_Dynamic* self_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Tc_Del(ut_M_Tc* self) {
  if (self == NULL) return;
  ut_M_Tb_Del(&(self->_base));
}
Returncode ut_M_Data_set(ut_M_Data* self, Ref_Manager* self_Refman, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic, Array* arr, Ref_Manager* arr_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(arr_Refman);
LUMI_cleanup:
  LUMI_dec_ref(arr_Refman);
  if (item_Dynamic != NULL) item_Dynamic->_del(item);
  LUMI_owner_dec_ref(item_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
Returncode ut_M_Data_get(ut_M_Data* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
void ut_M_Data_Del(ut_M_Data* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->arr_Refman);
  LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_fun0(void) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
Returncode ut_M_fun1(Int x, String* s, Ref_Manager* s_Refman, String* o, Ref_Manager* o_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(s_Refman);
LUMI_cleanup:
  String_Del(o);
  LUMI_owner_dec_ref(o_Refman);
  LUMI_dec_ref(s_Refman);
  return LUMI_err;
}
Returncode ut_M_fun2(String** s, Ref_Manager** s_Refman, Int* x) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
Returncode ut_M_fun3(Int x, String** s, Ref_Manager** s_Refman) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
Returncode ut_M_fun4(Int x) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
Returncode ut_M_fun5(Int x, Int* y) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
Returncode ut_M_fun6(Int x, Int y, Int* n, Int* m) {
  Returncode LUMI_err = OK;
LUMI_cleanup:
  return LUMI_err;
}
Returncode ut_M_fun7(ut_M_Tb* tb, Ref_Manager* tb_Refman, ut_M_Tb_Dynamic* tb_Dynamic, ut_M_Tb** tbo, Ref_Manager** tbo_Refman, ut_M_Tb_Dynamic** tbo_Dynamic) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(tb_Refman);
LUMI_cleanup:
  LUMI_dec_ref(tb_Refman);
  return LUMI_err;
}
Returncode ut_M_mock(String** so, Ref_Manager** so_Refman, Int* io, ut_M_Test** to, Ref_Manager** to_Refman, ut_M_Tc** tco, Ref_Manager** tco_Refman, ut_M_Tc_Dynamic** tco_Dynamic) {
  Returncode LUMI_err = OK;
  