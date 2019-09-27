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
    void (*fun)(void);
};
struct ut_M_Ta {
    ut_M_Test _base;
    Int numa;
};
struct ut_M_Ta_Dynamic {
    Dynamic_Del _del;
    void (*dyn)(ut_M_Ta* self, ut_M_Ta_Dynamic* self_Dynamic);
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
};
void ut_M_Test_meth(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_Ta_metha(ut_M_Ta* self, ut_M_Ta_Dynamic* self_Dynamic);
void ut_M_Ta_dyn(ut_M_Ta* self, ut_M_Ta_Dynamic* self_Dynamic);
void ut_M_Ta_Del(ut_M_Ta* self);
Returncode ut_M_Tb_new(ut_M_Tb* self, ut_M_Tb_Dynamic* self_Dynamic, Int num);
void ut_M_Tb_methb(ut_M_Tb* self, ut_M_Tb_Dynamic* self_Dynamic);
void ut_M_Tb_dyn(ut_M_Tb* self, ut_M_Tb_Dynamic* self_Dynamic);
void ut_M_Tb_Del(ut_M_Tb* self);
void ut_M_Tc_methc(ut_M_Tc* self, ut_M_Tc_Dynamic* self_Dynamic);
void ut_M_Tc_dyn(ut_M_Tc* self, ut_M_Tc_Dynamic* self_Dynamic);
void ut_M_Tc_Del(ut_M_Tc* self);
void ut_M_Data_set(ut_M_Data* self, Generic_Type* item, Generic_Type_Dynamic* item_Dynamic);
void ut_M_Data_get(ut_M_Data* self, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Data_Del(ut_M_Data* self);
void ut_M_fun0(void);
void ut_M_fun1(Int x, char* s, int s_Max_length, int* s_Length, char* o, int o_Max_length, int* o_Length);
void ut_M_fun2(char** s, int* s_Max_length, int** s_Length, Ref_Manager** s_Refman, Int* x);
void ut_M_fun3(Int x, char** s, int* s_Max_length, int** s_Length, Ref_Manager** s_Refman);
void ut_M_fun4(Int x);
void ut_M_fun5(Int x, Int* y);
void ut_M_fun6(Int x, Int y, Int* n, Int* m);
void ut_M_fun7(ut_M_Tb* tb, Ref_Manager* tb_Refman, ut_M_Tb_Dynamic* tb_Dynamic, ut_M_Tb** tbo, Ref_Manager** tbo_Refman, ut_M_Tb_Dynamic** tbo_Dynamic);
void ut_M_fun8(char* s, int s_Max_length, int* s_Length, Ref_Manager* s_Refman);
Returncode ut_M_fune(void);
Returncode ut_M_mock(char** so, int* so_Max_length, int** so_Length, Ref_Manager** so_Refman, Int* io, ut_M_Test** to, Ref_Manager** to_Refman, ut_M_Tc** tco, Ref_Manager** tco_Refman, ut_M_Tc_Dynamic** tco_Dynamic);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
ut_M_Ta_Dynamic ut_M_Ta_dynamic = {(Dynamic_Del)ut_M_Ta_Del, ut_M_Ta_dyn};
ut_M_Tb_Dynamic ut_M_Tb_dynamic = {{(Dynamic_Del)ut_M_Tb_Del, (void (*)(ut_M_Ta* self, ut_M_Ta_Dynamic* self_Dynamic))ut_M_Tb_dyn}};
ut_M_Tc_Dynamic ut_M_Tc_dynamic = {{{(Dynamic_Del)ut_M_Tc_Del, (void (*)(ut_M_Ta* self, ut_M_Ta_Dynamic* self_Dynamic))ut_M_Tc_dyn}}};
Generic_Type_Dynamic ut_M_Data_dynamic = {(Dynamic_Del)ut_M_Data_Del};
Int ut_M_i = 0;
Char ut_M_c = 0;
Bool ut_M_b = 0;
char* ut_M_str = NULL;
int ut_M_str_Max_length = 0;
int* ut_M_str_Length = &Lumi_empty_int;
char* ut_M_ostr = NULL;
int ut_M_ostr_Max_length = 0;
int* ut_M_ostr_Length = &Lumi_empty_int;
Int* ut_M_arr = NULL;
int ut_M_arr_Length = 0;
Ref_Manager* ut_M_arr_Refman = NULL;
File* ut_M_fobj = NULL;
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
char* ut_M_sarr = NULL;
int ut_M_sarr_Length = 0;
int ut_M_sarr_Value_length = 0;
int* ut_M_sarr_String_length = NULL;
Ref_Manager* ut_M_sarr_Refman = NULL;
void ut_M_Test_meth(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->t_Refman);
}
void ut_M_Ta_metha(ut_M_Ta* self, ut_M_Ta_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Ta_dyn(ut_M_Ta* self, ut_M_Ta_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Ta_Del(ut_M_Ta* self) {
    if (self == NULL) return;
    ut_M_Test_Del(&(self->_base));
}
Returncode ut_M_Tb_new(ut_M_Tb* self, ut_M_Tb_Dynamic* self_Dynamic, Int num) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_Tb_methb(ut_M_Tb* self, ut_M_Tb_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Tb_dyn(ut_M_Tb* self, ut_M_Tb_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Tb_Del(ut_M_Tb* self) {
    if (self == NULL) return;
    ut_M_Ta_Del(&(self->_base));
}
void ut_M_Tc_methc(ut_M_Tc* self, ut_M_Tc_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Tc_dyn(ut_M_Tc* self, ut_M_Tc_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Tc_Del(ut_M_Tc* self) {
    if (self == NULL) return;
    ut_M_Tb_Del(&(self->_base));
}
void ut_M_Data_set(ut_M_Data* self, Generic_Type* item, Generic_Type_Dynamic* item_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    if (item_Dynamic != NULL) item_Dynamic->_del(item);
    free(item);
}
void ut_M_Data_get(ut_M_Data* self, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Data_Del(ut_M_Data* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
void ut_M_fun0(void) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun1(Int x, char* s, int s_Max_length, int* s_Length, char* o, int o_Max_length, int* o_Length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    String_Del(o);
    free(o);
}
void ut_M_fun2(char** s, int* s_Max_length, int** s_Length, Ref_Manager** s_Refman, Int* x) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun3(Int x, char** s, int* s_Max_length, int** s_Length, Ref_Manager** s_Refman) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun4(Int x) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun5(Int x, Int* y) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun6(Int x, Int y, Int* n, Int* m) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun7(ut_M_Tb* tb, Ref_Manager* tb_Refman, ut_M_Tb_Dynamic* tb_Dynamic, ut_M_Tb** tbo, Ref_Manager** tbo_Refman, ut_M_Tb_Dynamic** tbo_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(tb_Refman);
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(tb_Refman);
}
void ut_M_fun8(char* s, int s_Max_length, int* s_Length, Ref_Manager* s_Refman) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    String_Del(s);
    LUMI_owner_dec_ref(s_Refman);
}
Returncode ut_M_fune(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
Returncode ut_M_mock(char** so, int* so_Max_length, int** so_Length, Ref_Manager** so_Refman, Int* io, ut_M_Test** to, Ref_Manager** to_Refman, ut_M_Tc** tco, Ref_Manager** tco_Refman, ut_M_Tc_Dynamic** tco_Dynamic) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @@ test-int-expression
/// @ t0
ut_M_i = 0;
/// @ t1
ut_M_i = 9630;
/// @ t2
ut_M_i = -9630;
/// @ t3
ut_M_i = 3920;
/// @ t4
ut_M_i = -3920;
/// @ t5
ut_M_i = 16623936;
/// @ t6
ut_M_i = -16623936;
/// @ t7
ut_M_i = 16623936;
/// @ t8
ut_M_i = -16623936;
/// @ t9
ut_M_i = 37;
/// @ t10
ut_M_i = -37;
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
char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int aux_String_0_Length[1] = {0};
    INIT_STRING_CONST(1, LUMI_block0_cleanup, aux_String_0, "some string");
    ut_M_str_Max_length = aux_String_0_Max_length;
    ut_M_str_Length = aux_String_0_Length;
    ut_M_str = aux_String_0;
/// @ t1
char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int aux_String_0_Length[1] = {0};
    INIT_STRING_CONST(1, LUMI_block0_cleanup, aux_String_0, "\nstring\t\"with\\formatting\n");
    ut_M_str_Max_length = aux_String_0_Max_length;
    ut_M_str_Length = aux_String_0_Length;
    ut_M_str = aux_String_0;
/// @ t2
char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int aux_String_0_Length[1] = {0};
    INIT_STRING_CONST(4, LUMI_block0_cleanup, aux_String_0, "linesplitstring");
    ut_M_str_Max_length = aux_String_0_Max_length;
    ut_M_str_Length = aux_String_0_Length;
    ut_M_str = aux_String_0;
/// @ t3
char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int aux_String_0_Length[1] = {0};
    INIT_STRING_CONST(4, LUMI_block0_cleanup, aux_String_0, "multi\nline\nstring\n");
    ut_M_str_Max_length = aux_String_0_Max_length;
    ut_M_str_Length = aux_String_0_Length;
    ut_M_str = aux_String_0;
/// @ t4
char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int aux_String_0_Length[1] = {0};
    INIT_STRING_CONST(2, LUMI_block0_cleanup, aux_String_0, "line split");
    ut_M_str_Max_length = aux_String_0_Max_length;
    ut_M_str_Length = aux_String_0_Length;
    ut_M_str = aux_String_0;
/// @ te0
no '"' around string constant ""aaa"
/// @ te1
too short string constant """
/// @ te2
'"' inside string constant ""error"+"string""
/// @ te3
indentation too short, expected 12 got 8
/// @ te4
indentation too short, expected 12 got 8
/// @@ test-empty-expression
/// @ t0
ut_M_str_Max_length = 0;
    ut_M_str_Length = &Lumi_empty_int;
    ut_M_str = NULL;
/// @ t1
LUMI_inc_ref(NULL);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = NULL;
    ut_M_t = NULL;
/// @ t2
String_Del(*so);
    LUMI_owner_dec_ref(*so_Refman);
    *so_Refman = NULL;
    *so_Max_length = 0;
    *so_Length = &Lumi_empty_int;
    *so = NULL;
/// @ t3
ut_M_b = ((void*)ut_M_t == NULL) || ((void*)ut_M_ta != NULL);
/// @ te0
cannot assign "Empty Symbol" into "Int"
/// @@ test-member-expression
/// @ t0
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    ut_M_i = ut_M_t->num;
/// @ t1
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_tc, ut_M_tc_Refman)
    ut_M_i = ut_M_tc->_base.numb;
/// @ t2
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_tc, ut_M_tc_Refman)
    ut_M_i = ut_M_tc->_base._base._base.num;
/// @ t3
CHECK_REF(1, LUMI_block0_cleanup, *to)
    ut_M_i = (*to)->num;
/// @ t4
LUMI_inc_ref(ut_M_tc_Refman);
    LUMI_dec_ref(*tco_Refman);
    *tco_Refman = ut_M_tc_Refman;
    *tco_Dynamic = ut_M_tc_Dynamic;
    *tco = ut_M_tc;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, *tco, *tco_Refman)
    ut_M_i = (*tco)->_base._base._base.num;
/// @ t5
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t->t, ut_M_t->t_Refman)
    ut_M_i = ut_M_t->t->num;
/// @ t6
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t->t, ut_M_t->t_Refman)
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t->t->t, ut_M_t->t->t_Refman)
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
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    if (13 >= *(ut_M_ostr_Length)) RAISE(1, LUMI_block0_cleanup, slice_index)
    ut_M_c = ut_M_ostr[13];
/// @ t1
Char* x = NULL;
    int x_Length = 0;
    Char* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_ostr)
    if (2 + 6 > *(ut_M_ostr_Length)) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = ut_M_ostr + 2;
    aux_Array_0_Length = 6;
    x_Length = aux_Array_0_Length;
    x = aux_Array_0;
/// @ t2
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (13 >= ut_M_arr_Length) RAISE(1, LUMI_block0_cleanup, slice_index)
    ut_M_i = ut_M_arr[13];
/// @ t3
Int* x = NULL;
    int x_Length = 0;
    Int* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_i <= 0 || 2 + ut_M_i > ut_M_arr_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = ut_M_arr + 2;
    aux_Array_0_Length = ut_M_i;
    x_Length = aux_Array_0_Length;
    x = aux_Array_0;
/// @ t4
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    if (4 >= *(ut_M_ostr_Length)) RAISE(1, LUMI_block0_cleanup, slice_index)
    ut_M_ostr[4] = ut_M_c;
/// @ t5
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (4 >= ut_M_arr_Length) RAISE(1, LUMI_block0_cleanup, slice_index)
    ut_M_arr[4] = ut_M_i;
/// @ t6
ut_M_Test* tarr = NULL;
    int tarr_Length = 0;
    Ref_Manager* tarr_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, tarr)
    if (3 >= tarr_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(tarr_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = tarr_Refman;
    ut_M_t = tarr + 3;
/// @ t7
char vsa[8 * 5] = {0};
    int vsa_String_length[8] = {0};
    char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    char* sa = NULL;
    int sa_Length = 0;
    int sa_Value_length = 0;
    int* sa_String_length = NULL;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    char* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    int aux_Array_0_Value_length = 0;
    int* aux_Array_0_String_length = NULL;
    /* initializing vsa */
    aux_String_0 = vsa + 3 * 5;
    aux_String_0_Max_length = 5;
    aux_String_0_Length = vsa_String_length + 3;
    s_Max_length = 5;
    s_Length = aux_String_0_Length;
    s = aux_String_0;
    aux_Array_0 = vsa + 2 * 5;
    aux_Array_0_Length = 4;
    aux_Array_0_Value_length = 5;
    aux_Array_0_String_length = vsa_String_length + 2;
    sa_Length = aux_Array_0_Length;
    sa_Value_length = 5;
    sa_String_length = aux_Array_0_String_length;
    sa = aux_Array_0;
/// @ t8
Returncode ut_M_fun(char* s, int s_Max_length, int* s_Length, Ref_Manager* s_Refman, char* sa, int sa_Length, int sa_Value_length, int* sa_String_length, Ref_Manager* sa_Refman);
Returncode ut_M_fun(char* s, int s_Max_length, int* s_Length, Ref_Manager* s_Refman, char* sa, int sa_Length, int sa_Value_length, int* sa_String_length, Ref_Manager* sa_Refman) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Char c = 0;
    Char* part = NULL;
    int part_Length = 0;
    char* si = NULL;
    int si_Max_length = 0;
    int* si_Length = &Lumi_empty_int;
    Char* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    Ref_Manager* aux_Array_0_Refman = NULL;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    Ref_Manager* aux_String_0_Refman = NULL;
    if (5 >= *(s_Length)) RAISE(2, LUMI_block0_cleanup, slice_index)
    c = s[5];
    if (4 + 2 > *(s_Length)) RAISE(3, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = s + 4;
    aux_Array_0_Length = 2;
    aux_Array_0_Refman = s_Refman;
    LUMI_inc_ref(aux_Array_0_Refman);
    CHECK_REFMAN(3, LUMI_block0_cleanup, aux_Array_0_Refman)
    part_Length = aux_Array_0_Length;
    part = aux_Array_0;
    if (3 >= sa_Length) RAISE(4, LUMI_block0_cleanup, slice_index)
    aux_String_0 = sa + 3 * sa_Value_length;
    aux_String_0_Max_length = sa_Value_length;
    aux_String_0_Length = sa_String_length + 3;
    aux_String_0_Refman = sa_Refman;
    LUMI_inc_ref(aux_String_0_Refman);
    CHECK_REFMAN(4, LUMI_block0_cleanup, aux_String_0_Refman)
    si_Max_length = aux_String_0_Max_length;
    si_Length = aux_String_0_Length;
    si = aux_String_0;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(aux_String_0_Refman);
    LUMI_dec_ref(aux_Array_0_Refman);
    free(sa_String_length);
    LUMI_owner_dec_ref(sa_Refman);
    return LUMI_err;
}
/// @ t9
char* sa = NULL;
    int sa_Length = 0;
    int sa_Value_length = 0;
    int* sa_String_length = NULL;
    Ref_Manager* sa_Refman = NULL;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int aux_String_0_Length[1] = {0};
    char* aux_String_1 = NULL;
    int aux_String_1_Max_length = 0;
    int* aux_String_1_Length = &Lumi_empty_int;
    Ref_Manager* aux_String_1_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, sa)
    if (3 >= sa_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_String_1 = sa + 3 * sa_Value_length;
    aux_String_1_Max_length = sa_Value_length;
    aux_String_1_Length = sa_String_length + 3;
    aux_String_1_Refman = sa_Refman;
    LUMI_inc_ref(aux_String_1_Refman);
    CHECK_REFMAN(2, LUMI_block0_cleanup, aux_String_1_Refman)
    INIT_STRING_CONST(2, LUMI_block0_cleanup, aux_String_0, "text");
    LUMI_err = String_copy(aux_String_1, aux_String_1_Max_length, aux_String_1_Length, aux_String_0, *aux_String_0_Length);
    CHECK(2, LUMI_block0_cleanup)
    free(sa_String_length);
    LUMI_owner_dec_ref(sa_Refman);
    sa_Refman = NULL;
    sa_Length = 0;
    sa_Value_length = 0;
    sa_String_length = NULL;
    sa = NULL;
/// @ t10
Int* aai = NULL;
    int aai_Length = 0;
    int aai_Value_length = 0;
    Ref_Manager* aai_Refman = NULL;
    Int* ua = NULL;
    int ua_Length = 0;
    int ua_Value_length = 0;
    Ref_Manager* ua_Refman = NULL;
    Int* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    Ref_Manager* aux_Array_0_Refman = NULL;
    Int* aux_Array_1 = NULL;
    int aux_Array_1_Length = 0;
    int aux_Array_1_Value_length = 0;
    Ref_Manager* aux_Array_1_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, aai)
    if (3 >= aai_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = aai + 3 * aai_Value_length;
    aux_Array_0_Length = aai_Value_length;
    aux_Array_0_Refman = aai_Refman;
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_dec_ref(ut_M_arr_Refman);
    ut_M_arr_Refman = aux_Array_0_Refman;
    ut_M_arr_Length = aux_Array_0_Length;
    ut_M_arr = aux_Array_0;
    CHECK_REF(3, LUMI_block0_cleanup, aai)
    if (2 + 4 > aai_Length) RAISE(3, LUMI_block0_cleanup, slice_index)
    aux_Array_1 = aai + 2 * aai_Value_length;
    aux_Array_1_Length = 4;
    aux_Array_1_Value_length = aai_Value_length;
    aux_Array_1_Refman = aai_Refman;
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_dec_ref(ua_Refman);
    ua_Refman = aux_Array_1_Refman;
    ua_Length = aux_Array_1_Length;
    ua_Value_length = aux_Array_1_Value_length;
    ua = aux_Array_1;
/// @ t11
Int* aai = NULL;
    int aai_Length = 0;
    int aai_Value_length = 0;
    int aai_Value_value_length = 0;
    int aai_Value_value_value_length = 0;
    Ref_Manager* aai_Refman = NULL;
    Int* ua = NULL;
    int ua_Length = 0;
    int ua_Value_length = 0;
    int ua_Value_value_length = 0;
    Ref_Manager* ua_Refman = NULL;
    Int* uaa = NULL;
    int uaa_Length = 0;
    int uaa_Value_length = 0;
    int uaa_Value_value_length = 0;
    int uaa_Value_value_value_length = 0;
    Ref_Manager* uaa_Refman = NULL;
    Int* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    int aux_Array_0_Value_length = 0;
    int aux_Array_0_Value_value_length = 0;
    Ref_Manager* aux_Array_0_Refman = NULL;
    Int* aux_Array_1 = NULL;
    int aux_Array_1_Length = 0;
    int aux_Array_1_Value_length = 0;
    int aux_Array_1_Value_value_length = 0;
    int aux_Array_1_Value_value_value_length = 0;
    Ref_Manager* aux_Array_1_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, aai)
    if (3 >= aai_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = aai + 3 * aai_Value_length * aai_Value_value_length * aai_Value_value_value_length;
    aux_Array_0_Length = aai_Value_length;
    aux_Array_0_Value_length = aai_Value_value_length;
    aux_Array_0_Value_value_length = aai_Value_value_value_length;
    aux_Array_0_Refman = aai_Refman;
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_dec_ref(ua_Refman);
    ua_Refman = aux_Array_0_Refman;
    ua_Length = aux_Array_0_Length;
    ua_Value_length = aux_Array_0_Value_length;
    ua_Value_value_length = aux_Array_0_Value_value_length;
    ua = aux_Array_0;
    CHECK_REF(3, LUMI_block0_cleanup, aai)
    if (2 + 4 > aai_Length) RAISE(3, LUMI_block0_cleanup, slice_index)
    aux_Array_1 = aai + 2 * aai_Value_length * aai_Value_value_length * aai_Value_value_value_length;
    aux_Array_1_Length = 4;
    aux_Array_1_Value_length = aai_Value_length;
    aux_Array_1_Value_value_length = aai_Value_value_length;
    aux_Array_1_Value_value_value_length = aai_Value_value_value_length;
    aux_Array_1_Refman = aai_Refman;
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_dec_ref(uaa_Refman);
    uaa_Refman = aux_Array_1_Refman;
    uaa_Length = aux_Array_1_Length;
    uaa_Value_length = aux_Array_1_Value_length;
    uaa_Value_value_length = aux_Array_1_Value_value_length;
    uaa_Value_value_value_length = aux_Array_1_Value_value_value_length;
    uaa = aux_Array_1;
/// @ t12
char* aas = NULL;
    int aas_Length = 0;
    int aas_Value_length = 0;
    int aas_Value_value_length = 0;
    int aas_Value_value_value_length = 0;
    int* aas_String_length = NULL;
    Ref_Manager* aas_Refman = NULL;
    char* ua = NULL;
    int ua_Length = 0;
    int ua_Value_length = 0;
    int ua_Value_value_length = 0;
    int* ua_String_length = NULL;
    Ref_Manager* ua_Refman = NULL;
    char* uaa = NULL;
    int uaa_Length = 0;
    int uaa_Value_length = 0;
    int uaa_Value_value_length = 0;
    int uaa_Value_value_value_length = 0;
    int* uaa_String_length = NULL;
    Ref_Manager* uaa_Refman = NULL;
    char* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    int aux_Array_0_Value_length = 0;
    int aux_Array_0_Value_value_length = 0;
    int* aux_Array_0_String_length = NULL;
    Ref_Manager* aux_Array_0_Refman = NULL;
    char* aux_Array_1 = NULL;
    int aux_Array_1_Length = 0;
    int aux_Array_1_Value_length = 0;
    int aux_Array_1_Value_value_length = 0;
    int aux_Array_1_Value_value_value_length = 0;
    int* aux_Array_1_String_length = NULL;
    Ref_Manager* aux_Array_1_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, aas)
    if (3 >= aas_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = aas + 3 * aas_Value_length * aas_Value_value_length * aas_Value_value_value_length;
    aux_Array_0_Length = aas_Value_length;
    aux_Array_0_Value_length = aas_Value_value_length;
    aux_Array_0_Value_value_length = aas_Value_value_value_length;
    aux_Array_0_String_length = aas_String_length + 3 * aas_Value_length * aas_Value_value_length;
    aux_Array_0_Refman = aas_Refman;
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_dec_ref(ua_Refman);
    ua_Refman = aux_Array_0_Refman;
    ua_Length = aux_Array_0_Length;
    ua_Value_length = aux_Array_0_Value_length;
    ua_Value_value_length = aux_Array_0_Value_value_length;
    ua_String_length = aux_Array_0_String_length;
    ua = aux_Array_0;
    CHECK_REF(3, LUMI_block0_cleanup, aas)
    if (2 + 4 > aas_Length) RAISE(3, LUMI_block0_cleanup, slice_index)
    aux_Array_1 = aas + 2 * aas_Value_length * aas_Value_value_length * aas_Value_value_value_length;
    aux_Array_1_Length = 4;
    aux_Array_1_Value_length = aas_Value_length;
    aux_Array_1_Value_value_length = aas_Value_value_length;
    aux_Array_1_Value_value_value_length = aas_Value_value_value_length;
    aux_Array_1_String_length = aas_String_length + 2 * aas_Value_length * aas_Value_value_length;
    aux_Array_1_Refman = aas_Refman;
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_dec_ref(uaa_Refman);
    uaa_Refman = aux_Array_1_Refman;
    uaa_Length = aux_Array_1_Length;
    uaa_Value_length = aux_Array_1_Value_length;
    uaa_Value_value_length = aux_Array_1_Value_value_length;
    uaa_Value_value_value_length = aux_Array_1_Value_value_value_length;
    uaa_String_length = aux_Array_1_String_length;
    uaa = aux_Array_1;
    free(aas_String_length);
    LUMI_owner_dec_ref(aas_Refman);
    aas_Refman = NULL;
    aas_Length = 0;
    aas_Value_length = 0;
    aas_Value_value_length = 0;
    aas_Value_value_value_length = 0;
    aas_String_length = NULL;
    aas = NULL;
/// @ t13
Int aai[8 * 7 * 6 * 5] = {0};
    Int* ua = NULL;
    int ua_Length = 0;
    int ua_Value_length = 0;
    int ua_Value_value_length = 0;
    Int* uaa = NULL;
    int uaa_Length = 0;
    int uaa_Value_length = 0;
    int uaa_Value_value_length = 0;
    int uaa_Value_value_value_length = 0;
    Int* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    int aux_Array_0_Value_length = 0;
    int aux_Array_0_Value_value_length = 0;
    Int* aux_Array_1 = NULL;
    int aux_Array_1_Length = 0;
    int aux_Array_1_Value_length = 0;
    int aux_Array_1_Value_value_length = 0;
    int aux_Array_1_Value_value_value_length = 0;
    /* initializing aai */
    aux_Array_0 = aai + 3 * 7 * 6 * 5;
    aux_Array_0_Length = 7;
    aux_Array_0_Value_length = 6;
    aux_Array_0_Value_value_length = 5;
    ua_Length = 7;
    ua_Value_length = 6;
    ua_Value_value_length = 5;
    ua = aux_Array_0;
    aux_Array_1 = aai + 2 * 7 * 6 * 5;
    aux_Array_1_Length = 4;
    aux_Array_1_Value_length = 7;
    aux_Array_1_Value_value_length = 6;
    aux_Array_1_Value_value_value_length = 5;
    uaa_Length = aux_Array_1_Length;
    uaa_Value_length = 7;
    uaa_Value_value_length = 6;
    uaa_Value_value_value_length = 5;
    uaa = aux_Array_1;
/// @ t14
char aas[8 * 7 * 6 * 5] = {0};
    int aas_String_length[8 * 7 * 6] = {0};
    char* ua = NULL;
    int ua_Length = 0;
    int ua_Value_length = 0;
    int ua_Value_value_length = 0;
    int* ua_String_length = NULL;
    char* uaa = NULL;
    int uaa_Length = 0;
    int uaa_Value_length = 0;
    int uaa_Value_value_length = 0;
    int uaa_Value_value_value_length = 0;
    int* uaa_String_length = NULL;
    char* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    int aux_Array_0_Value_length = 0;
    int aux_Array_0_Value_value_length = 0;
    int* aux_Array_0_String_length = NULL;
    char* aux_Array_1 = NULL;
    int aux_Array_1_Length = 0;
    int aux_Array_1_Value_length = 0;
    int aux_Array_1_Value_value_length = 0;
    int aux_Array_1_Value_value_value_length = 0;
    int* aux_Array_1_String_length = NULL;
    /* initializing aas */
    if (ut_M_i < 0 || ut_M_i >= 8) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = aas + ut_M_i * 7 * 6 * 5;
    aux_Array_0_Length = 7;
    aux_Array_0_Value_length = 6;
    aux_Array_0_Value_value_length = 5;
    aux_Array_0_String_length = aas_String_length + ut_M_i * 7 * 6;
    ua_Length = 7;
    ua_Value_length = 6;
    ua_Value_value_length = 5;
    ua_String_length = aux_Array_0_String_length;
    ua = aux_Array_0;
    aux_Array_1 = aas + 2 * 7 * 6 * 5;
    aux_Array_1_Length = 4;
    aux_Array_1_Value_length = 7;
    aux_Array_1_Value_value_length = 6;
    aux_Array_1_Value_value_value_length = 5;
    aux_Array_1_String_length = aas_String_length + 2 * 7 * 6;
    uaa_Length = aux_Array_1_Length;
    uaa_Value_length = 7;
    uaa_Value_value_length = 6;
    uaa_Value_value_value_length = 5;
    uaa_String_length = aux_Array_1_String_length;
    uaa = aux_Array_1;
/// @ t15
void ut_M_fun(void);
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    char aas[8 * 7 * 6 * 5] = {0};
    int aas_String_length[8 * 7 * 6] = {0};
    char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    char* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    int aux_Array_0_Value_length = 0;
    int aux_Array_0_Value_value_length = 0;
    int* aux_Array_0_String_length = NULL;
    char* aux_Array_1 = NULL;
    int aux_Array_1_Length = 0;
    int aux_Array_1_Value_length = 0;
    int* aux_Array_1_String_length = NULL;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    /* initializing aas */
    aux_Array_0 = aas + 4 * 7 * 6 * 5;
    aux_Array_0_Length = 7;
    aux_Array_0_Value_length = 6;
    aux_Array_0_Value_value_length = 5;
    aux_Array_0_String_length = aas_String_length + 4 * 7 * 6;
    aux_Array_1 = (aux_Array_0) + 3 * 6 * 5;
    aux_Array_1_Length = 6;
    aux_Array_1_Value_length = 5;
    aux_Array_1_String_length = aux_Array_0_String_length + 3 * 6;
    aux_String_0 = (aux_Array_1) + 2 * 5;
    aux_String_0_Max_length = 5;
    aux_String_0_Length = aux_Array_1_String_length + 2;
    s_Max_length = 5;
    s_Length = aux_String_0_Length;
    s = aux_String_0;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t16
Char* x = NULL;
    int x_Length = 0;
    x_Length = *(ut_M_ostr_Length);
    x = ut_M_ostr;
/// @ t17
char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    INIT_NEW_STRING(1, LUMI_block0_cleanup, s, 12);
    LUMI_err = Sys_print(sys, s, *s_Length);
    CHECK(2, LUMI_block0_cleanup)
/// @ t18
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    int s_Max_length;
    int* s_Length;
};
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    String_Del(self->s);
    free(self->s);
}
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {0};
    ut_M_Test* t = NULL;
    ut_M_Test a[6] = {0};
    t = &t_Var;
    /* initializing a */
LUMI_block0_cleanup:
    (void)0;
    ARRAY_DEL(ut_M_Test, a, 6)
    ut_M_Test_Del(t);
}
/// @ te0
expected "]", got "new-line"
/// @ te1
expected "]", got "new-line"
/// @ te2
cannot slice a void expression
/// @ te3
cannot slice type "Int"
/// @ te4
expected integer index for slice, got "String"
/// @ te5
expected integer index for slice, got "String"
/// @ te6
expected integer index for slice, got void expression
/// @ te7
assigning into non assignable expression
/// @ te8
assigning into non assignable expression
/// @ te9
assigning into non assignable expression
/// @ te10
assigning into an owner a non-owner access "user"
/// @ te11
array of type with constructor "Tc"
/// @ te12
array of type with constructor "Test"
/// @ te13
ignoring slice bounds check
/// @ te14
sequence length is not positive
/// @ te15
negative slice index [-1]
/// @ te16
non positive slice length [0]
/// @ te17
slice last index [3] is larger than sequence size [3]
/// @@ test-call-expression
/// @ t0
ut_M_fun0();
/// @ t1
ut_M_fun1(3, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, NULL, 0, &Lumi_empty_int);
/// @ t2
ut_M_fun2(&(*so), &(*so_Max_length), &(*so_Length), &(*so_Refman), &(*io));
/// @ t3
Int x = 0;
    char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    Ref_Manager* s_Refman = NULL;
    ut_M_fun2(&(s), &(s_Max_length), &(s_Length), &(s_Refman), &(x));
/// @ t4
ut_M_fun3(0, &(*so), &(*so_Max_length), &(*so_Length), &(*so_Refman));
/// @ t5
Int x = 0;
    ut_M_fun5(3, &(x));
    ut_M_fun4(x);
/// @ t6
ut_M_fun6(2, 3, &(*io), &(*io));
/// @ t7
Int aux_Int_0 = 0;
    ut_M_fun5(4, &(aux_Int_0));
/// @ t8
Int aux_Int_0 = 0;
    ut_M_fun5(4, &(aux_Int_0));
    *io = aux_Int_0;
/// @ t9
char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    Ref_Manager* aux_String_0_Refman = NULL;
    ut_M_fun3(7, &(aux_String_0), &(aux_String_0_Max_length), &(aux_String_0_Length), &(aux_String_0_Refman));
    String_Del(*so);
    LUMI_owner_dec_ref(*so_Refman);
    *so_Refman = aux_String_0_Refman;
    *so_Max_length = aux_String_0_Max_length;
    *so_Length = aux_String_0_Length;
    *so = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Refman = NULL;
    aux_String_0_Length = &Lumi_empty_int;
/// @ t10
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_t_Refman)
    ut_M_Test_meth(ut_M_t);
/// @ t11
ut_M_Test_meth(*to);
/// @ t12
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    ut_M_Tc_methc(ut_M_tc, ut_M_tc_Dynamic);
/// @ t13
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    ut_M_Tb_methb(&(ut_M_tc->_base), &(ut_M_tc_Dynamic->_base));
/// @ t14
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    ut_M_Test_meth(&(ut_M_tc->_base._base._base));
/// @ t15
LUMI_inc_ref(ut_M_tc_Refman);
    LUMI_dec_ref(*tco_Refman);
    *tco_Refman = ut_M_tc_Refman;
    *tco_Dynamic = ut_M_tc_Dynamic;
    *tco = ut_M_tc;
    CHECK_REFMAN(2, LUMI_block0_cleanup, *tco_Refman)
    ut_M_Test_meth(&((*tco)->_base._base._base));
/// @ t16
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_t->t_Refman)
    ut_M_Test_meth(ut_M_t->t);
/// @ t17
LUMI_var_dec_ref(*so_Refman);
    ut_M_fun1(3, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, *so, *so_Max_length, *so_Length);
    *so = NULL;
    *so_Refman = NULL;
    *so_Length = &Lumi_empty_int;
/// @ t18
char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    Ref_Manager* aux_String_0_Refman = NULL;
    Int aux_Int_0 = 0;
    ut_M_fun3(1, &(aux_String_0), &(aux_String_0_Max_length), &(aux_String_0_Length), &(aux_String_0_Refman));
    ut_M_fun5(2, &(aux_Int_0));
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
    Returncode (*meth)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, ut_M_Base* b, ut_M_Base_Dynamic* b_Dynamic);
};
struct ut_M_Test {
    ut_M_Base _base;
};
struct ut_M_Test_Dynamic {
    ut_M_Base_Dynamic _base;
};
Returncode ut_M_Base_meth(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, ut_M_Base* b, ut_M_Base_Dynamic* b_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, ut_M_Base* b, ut_M_Base_Dynamic* b_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_meth};
ut_M_Test_Dynamic ut_M_Test_dynamic = {{(Dynamic_Del)ut_M_Test_Del, (Returncode (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, ut_M_Base* b, ut_M_Base_Dynamic* b_Dynamic))ut_M_Test_meth}};
Returncode ut_M_Base_meth(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, ut_M_Base* b, ut_M_Base_Dynamic* b_Dynamic) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    if (b_Dynamic != NULL) b_Dynamic->_del(b);
    free(b);
    return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
}
Returncode ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, ut_M_Base* b, ut_M_Base_Dynamic* b_Dynamic) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Test* t = NULL;
    ut_M_Test_Dynamic* t_Dynamic = &ut_M_Test_dynamic;
    INIT_NEW(6, LUMI_block0_cleanup, t, ut_M_Test, 1);
    LUMI_err = ut_M_Base_meth(&(self->_base), &(self_Dynamic->_base), &(t->_base), &(t_Dynamic->_base));
    t = NULL;
    t_Dynamic = NULL;
    CHECK(7, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    if (t_Dynamic != NULL) t_Dynamic->_base._del(t);
    free(t);
    if (b_Dynamic != NULL) b_Dynamic->_del(b);
    free(b);
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
    void (*meth)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_mock(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
Returncode ut_M_mock(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    LUMI_err = ut_M_mock(&(*t), &(*t_Refman), &(*t_Dynamic));
    CHECK(5, LUMI_block0_cleanup)
    CHECK_REF_REFMAN(5, LUMI_block0_cleanup, *t, *t_Refman)
    if (*t_Dynamic == NULL) RAISE(5, LUMI_block0_cleanup, empty_object)
    (*t_Dynamic)->meth(*t, *t_Dynamic);
LUMI_block0_cleanup:
    (void)0;
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
    Returncode (*meth)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic);
};
Returncode ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
Returncode ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Test* aux_Test_0 = NULL;
    Ref_Manager* aux_Test_0_Refman = NULL;
    ut_M_Test_Dynamic* aux_Test_0_Dynamic = NULL;
    ut_M_Test* aux_Test_1 = NULL;
    Ref_Manager* aux_Test_1_Refman = NULL;
    ut_M_Test_Dynamic* aux_Test_1_Dynamic = NULL;
    LUMI_err = self_Dynamic->meth(self, self_Dynamic, &(aux_Test_0), &(aux_Test_0_Refman), &(aux_Test_0_Dynamic));
    CHECK(4, LUMI_block0_cleanup)
    CHECK_REF_REFMAN(4, LUMI_block0_cleanup, aux_Test_0, aux_Test_0_Refman)
    if (aux_Test_0_Dynamic == NULL) RAISE(4, LUMI_block0_cleanup, empty_object)
    LUMI_err = aux_Test_0_Dynamic->meth(aux_Test_0, aux_Test_0_Dynamic, &(aux_Test_1), &(aux_Test_1_Refman), &(aux_Test_1_Dynamic));
    CHECK(4, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(aux_Test_1_Refman);
    LUMI_dec_ref(aux_Test_0_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ t22
void ut_M_fun(char** astr, int* astr_Length, int* astr_Value_length, int** astr_String_length);
void ut_M_fun(char** astr, int* astr_Length, int* astr_Value_length, int** astr_String_length) {
    unsigned LUMI_loop_depth = 1;
    ut_M_fun(&(*astr), &(*astr_Length), &(*astr_Value_length), &(*astr_String_length));
LUMI_block0_cleanup:
    (void)0;
}
/// @ t23
Returncode ut_M_fun(char* s, int s_Max_length, int* s_Length);
Returncode ut_M_fun(char* s, int s_Max_length, int* s_Length) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char vars[12] = {0};
    int vars_Length[1] = {0};
    char s_vars[12] = {0};
    int s_vars_Length[1] = {0};
    Ref_Manager* s_vars_Refman = NULL;
    char* owners = NULL;
    int owners_Max_length = 0;
    int* owners_Length = &Lumi_empty_int;
    char* strongs = NULL;
    int strongs_Max_length = 0;
    int* strongs_Length = &Lumi_empty_int;
    Ref_Manager* strongs_Refman = NULL;
    char* users = NULL;
    int users_Max_length = 0;
    int* users_Length = &Lumi_empty_int;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    char* aux_String_1 = NULL;
    int aux_String_1_Max_length = 0;
    int* aux_String_1_Length = &Lumi_empty_int;
    /* initializing vars */
    INIT_VAR_REFMAN(3, LUMI_block0_cleanup, s_vars)
    INIT_NEW_STRING(4, LUMI_block0_cleanup, aux_String_0, 12);
    owners_Max_length = 12;
    owners_Length = aux_String_0_Length;
    owners = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_int;
    INIT_NEW_STRING(5, LUMI_block0_cleanup, aux_String_1, 12);
    strongs_Max_length = 12;
    strongs_Length = aux_String_1_Length;
    strongs = aux_String_1;
    aux_String_1 = NULL;
    aux_String_1_Length = &Lumi_empty_int;
    INIT_NEW_REFMAN(5, LUMI_block0_cleanup, strongs)
    users_Max_length = s_Max_length;
    users_Length = s_Length;
    users = s;
    LUMI_err = ut_M_fun(s, s_Max_length, s_Length);
    CHECK(7, LUMI_block0_cleanup)
    LUMI_err = ut_M_fun(vars, 12, vars_Length);
    CHECK(8, LUMI_block0_cleanup)
    LUMI_err = ut_M_fun(s_vars, 12, s_vars_Length);
    CHECK(9, LUMI_block0_cleanup)
    LUMI_err = ut_M_fun(owners, owners_Max_length, owners_Length);
    CHECK(10, LUMI_block0_cleanup)
    LUMI_err = ut_M_fun(strongs, strongs_Max_length, strongs_Length);
    CHECK(11, LUMI_block0_cleanup)
    String_clear(s, s_Max_length, s_Length);
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_1);
    free(aux_String_1);
    String_Del(aux_String_0);
    free(aux_String_0);
    String_Del(strongs);
    LUMI_owner_dec_ref(strongs_Refman);
    String_Del(owners);
    free(owners);
    LUMI_var_dec_ref(s_vars_Refman);
    return LUMI_err;
}
/// @ t24
char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    Ref_Manager* s_Refman = NULL;
    char* sw = NULL;
    int sw_Max_length = 0;
    int* sw_Length = &Lumi_empty_int;
    Ref_Manager* sw_Refman = NULL;
    CHECK_REFMAN(3, LUMI_block0_cleanup, sw_Refman)
    LUMI_var_dec_ref(s_Refman);
    ut_M_fun1(0, sw, sw_Max_length, sw_Length, s, s_Max_length, s_Length);
    s = NULL;
    s_Refman = NULL;
    s_Length = &Lumi_empty_int;
/// @ t25
char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    Ref_Manager* aux_String_0_Refman = NULL;
    aux_String_0 = ut_M_ostr;
    ut_M_ostr = NULL;
    ut_M_ostr_Length = &Lumi_empty_int;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, aux_String_0)
    ut_M_fun8(aux_String_0, aux_String_0_Max_length, aux_String_0_Length, aux_String_0_Refman);
    aux_String_0 = NULL;
    aux_String_0_Refman = NULL;
    aux_String_0_Length = &Lumi_empty_int;
/// @ t26
LUMI_err = ut_M_fune();
    CHECK(1, LUMI_block0_cleanup)
/// @ te0
expected access, got " "
/// @ te1
expected space after "user", got ")"
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
assigning into access "weak" invalid access "strong"
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
/// @ te20
assigning into a weak reference an illegal access "owner"
/// @ te21
ignoring error result check on function call
/// @ te22
error raised inside function not declared as error raising "fun"
/// @@ test-type-expression
/// @ t0
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_t_Refman)
    ut_M_Test_meth(ut_M_t);
/// @ t1
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    ut_M_Tb_methb(&(ut_M_tc->_base), &(ut_M_tc_Dynamic->_base));
/// @ t2
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    ut_M_Test_meth(&(ut_M_tc->_base._base._base));
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
void ut_M_Base_methb(ut_M_Base* self);
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Mid_methm(ut_M_Mid* self);
void ut_M_Mid_Del(ut_M_Mid* self);
void ut_M_Top_methb(ut_M_Top* self);
void ut_M_Top_methm(ut_M_Top* self);
void ut_M_Top_Del(ut_M_Top* self);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Top_dynamic = {(Dynamic_Del)ut_M_Top_Del};
void ut_M_Base_methb(ut_M_Base* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
}
void ut_M_Mid_methm(ut_M_Mid* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Mid_Del(ut_M_Mid* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
void ut_M_Top_methb(ut_M_Top* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Top_methm(ut_M_Top* self) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Mid_methm(&(self->_base));
LUMI_block0_cleanup:
    (void)0;
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
void ut_M_Base_methb(ut_M_Base* self);
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Mid_methm(ut_M_Mid* self);
void ut_M_Mid_Del(ut_M_Mid* self);
void ut_M_Top_methb(ut_M_Top* self);
void ut_M_Top_methm(ut_M_Top* self);
void ut_M_Top_Del(ut_M_Top* self);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Top_dynamic = {(Dynamic_Del)ut_M_Top_Del};
void ut_M_Base_methb(ut_M_Base* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
}
void ut_M_Mid_methm(ut_M_Mid* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Mid_Del(ut_M_Mid* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
void ut_M_Top_methb(ut_M_Top* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Top_methm(ut_M_Top* self) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Base_methb(&(self->_base._base));
LUMI_block0_cleanup:
    (void)0;
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
assigning into non assignable expression
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
expected expression, got "{"
/// @ t6
expected space after "-", got "["
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
ut_M_i += (100 * 2) - 37;
    ut_M_i *= 3;
/// @ t2
ut_M_i -= 12 * 13;
/// @ t3
ut_M_b = (3 < 5) || (23 > 37);
/// @ t4
ut_M_b = (3 <= 5) && (23 >= 37);
/// @ t5
ut_M_b = (ut_M_i == 5) || (ut_M_i != 37);
/// @ t6
ut_M_b = ((2 < ut_M_i) && (ut_M_i < 12)) && (12 == (2 * ut_M_i));
/// @ t7
LUMI_inc_ref(ut_M_tc_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = ut_M_tc_Refman;
    ut_M_t = &(ut_M_tc->_base._base._base);
/// @ t8
char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    String_Del(s);
    free(s);
    LUMI_var_dec_ref(*so_Refman);
    s_Max_length = *so_Max_length;
    s_Length = *so_Length;
    s = *so;
    *so = NULL;
    *so_Refman = NULL;
    *so_Length = &Lumi_empty_int;
/// @ t9
ut_M_str_Max_length = *so_Max_length;
    ut_M_str_Length = *so_Length;
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
    ut_M_Tc_Dynamic* otc_Dynamic = NULL;
    if (ut_M_tb_Dynamic != NULL) ut_M_tb_Dynamic->_base._del(ut_M_tb);
    LUMI_owner_dec_ref(ut_M_tb_Refman);
    ut_M_tb_Dynamic = &(otc_Dynamic->_base);
    ut_M_tb = &(otc->_base);
    otc = NULL;
    otc_Dynamic = NULL;
    INIT_NEW_REFMAN(2, LUMI_block0_cleanup, ut_M_tb)
/// @ t15
ut_M_Test* otarr = NULL;
    int otarr_Length = 0;
    ARRAY_DEL(ut_M_Test, otarr, otarr_Length)
    free(otarr);
    otarr_Length = 0;
    otarr = NULL;
/// @ t16
if (ut_M_i == 0) RAISE(1, LUMI_block0_cleanup, zero_division)
    if (ut_M_i == 0) RAISE(1, LUMI_block0_cleanup, zero_division)
    *io = (60 / ut_M_i) + (60 % ut_M_i);
/// @ te0
unknown operator "@"
/// @ te1
expected space after "+", got "("
/// @ te2
ambiguous precedence between operators "+" and "*"
/// @ te3
ambiguous precedence between operators "or" and "and"
/// @ te4
used non-binary operator "not"
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
/// @ te19
operator "<" expected "Int" operand, got "Bool"
/// @ te20
assigning into a weak reference an illegal access "user"
/// @ te21
ignoring empty reference check
/// @ te22
ignoring zero division check
/// @ te23
ignoring zero division check
/// @ te24
dividing by zero
/// @ te25
dividing by zero
/// @@ test-swap-expression
/// @ t0
ut_M_Test* t1 = NULL;
    ut_M_Test* t2 = NULL;
    ut_M_Test* aux_Test_0 = NULL;
    INIT_NEW(1, LUMI_block0_cleanup, t1, ut_M_Test, 1);
    INIT_NEW(2, LUMI_block0_cleanup, t2, ut_M_Test, 1);
    aux_Test_0 = t1;
    t1 = t2;
    t2 = aux_Test_0;
    aux_Test_0 = NULL;
/// @ t1
ut_M_Test* t1 = NULL;
    Ref_Manager* t1_Refman = NULL;
    ut_M_Test* t2 = NULL;
    Ref_Manager* t2_Refman = NULL;
    ut_M_Test* aux_Test_0 = NULL;
    Ref_Manager* aux_Test_0_Refman = NULL;
    CHECK_REF(1, LUMI_block0_cleanup, *to)
    t1_Refman = *to_Refman;
    t1 = *to;
    *to = NULL;
    *to_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, *to)
    t2_Refman = *to_Refman;
    t2 = *to;
    *to = NULL;
    *to_Refman = NULL;
    aux_Test_0_Refman = t1_Refman;
    aux_Test_0 = t1;
    t1_Refman = t2_Refman;
    t1 = t2;
    t2_Refman = aux_Test_0_Refman;
    t2 = aux_Test_0;
    aux_Test_0 = NULL;
    aux_Test_0_Refman = NULL;
/// @ t2
ut_M_Tc* t1 = NULL;
    ut_M_Tc_Dynamic* t1_Dynamic = &ut_M_Tc_dynamic;
    ut_M_Tc* t2 = NULL;
    ut_M_Tc_Dynamic* t2_Dynamic = &ut_M_Tc_dynamic;
    ut_M_Tc* aux_Tc_0 = NULL;
    ut_M_Tc_Dynamic* aux_Tc_0_Dynamic = NULL;
    INIT_NEW(1, LUMI_block0_cleanup, t1, ut_M_Tc, 1);
    LUMI_err = ut_M_Tb_new(&(t1->_base), &(t1_Dynamic->_base), 1);
    INIT_NEW(2, LUMI_block0_cleanup, t2, ut_M_Tc, 1);
    LUMI_err = ut_M_Tb_new(&(t2->_base), &(t2_Dynamic->_base), 2);
    aux_Tc_0_Dynamic = t1_Dynamic;
    aux_Tc_0 = t1;
    t1_Dynamic = t2_Dynamic;
    t1 = t2;
    t2_Dynamic = aux_Tc_0_Dynamic;
    t2 = aux_Tc_0;
    aux_Tc_0 = NULL;
    aux_Tc_0_Dynamic = NULL;
/// @ t3
ut_M_Tc* t1 = NULL;
    Ref_Manager* t1_Refman = NULL;
    ut_M_Tc_Dynamic* t1_Dynamic = NULL;
    ut_M_Tc* t2 = NULL;
    Ref_Manager* t2_Refman = NULL;
    ut_M_Tc_Dynamic* t2_Dynamic = NULL;
    ut_M_Tc* aux_Tc_0 = NULL;
    ut_M_Tc_Dynamic* aux_Tc_0_Dynamic = &ut_M_Tc_dynamic;
    ut_M_Tc* aux_Tc_1 = NULL;
    ut_M_Tc_Dynamic* aux_Tc_1_Dynamic = &ut_M_Tc_dynamic;
    ut_M_Tc* aux_Tc_2 = NULL;
    Ref_Manager* aux_Tc_2_Refman = NULL;
    ut_M_Tc_Dynamic* aux_Tc_2_Dynamic = NULL;
    INIT_NEW(1, LUMI_block0_cleanup, aux_Tc_0, ut_M_Tc, 1);
    LUMI_err = ut_M_Tb_new(&(aux_Tc_0->_base), &(aux_Tc_0_Dynamic->_base), 1);
    t1_Dynamic = aux_Tc_0_Dynamic;
    t1 = aux_Tc_0;
    aux_Tc_0 = NULL;
    aux_Tc_0_Dynamic = NULL;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, t1)
    INIT_NEW(2, LUMI_block0_cleanup, aux_Tc_1, ut_M_Tc, 1);
    LUMI_err = ut_M_Tb_new(&(aux_Tc_1->_base), &(aux_Tc_1_Dynamic->_base), 2);
    t2_Dynamic = aux_Tc_1_Dynamic;
    t2 = aux_Tc_1;
    aux_Tc_1 = NULL;
    aux_Tc_1_Dynamic = NULL;
    INIT_NEW_REFMAN(2, LUMI_block0_cleanup, t2)
    aux_Tc_2_Refman = t1_Refman;
    aux_Tc_2_Dynamic = t1_Dynamic;
    aux_Tc_2 = t1;
    t1_Refman = t2_Refman;
    t1_Dynamic = t2_Dynamic;
    t1 = t2;
    t2_Refman = aux_Tc_2_Refman;
    t2_Dynamic = aux_Tc_2_Dynamic;
    t2 = aux_Tc_2;
    aux_Tc_2 = NULL;
    aux_Tc_2_Refman = NULL;
    aux_Tc_2_Dynamic = NULL;
/// @ t4
Int* a1 = NULL;
    int a1_Length = 0;
    Int* a2 = NULL;
    int a2_Length = 0;
    Int* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, a1, Int, 4, 1);
    INIT_NEW_ARRAY(2, LUMI_block0_cleanup, a2, Int, 6, 1);
    aux_Array_0_Length = 4;
    aux_Array_0 = a1;
    a1_Length = 6;
    a1 = a2;
    a2_Length = 4;
    a2 = aux_Array_0;
    aux_Array_0 = NULL;
/// @ t5
Int* a1 = NULL;
    int a1_Length = 0;
    Ref_Manager* a1_Refman = NULL;
    Int* a2 = NULL;
    int a2_Length = 0;
    Ref_Manager* a2_Refman = NULL;
    Int* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    Int* aux_Array_1 = NULL;
    int aux_Array_1_Length = 0;
    Int* aux_Array_2 = NULL;
    int aux_Array_2_Length = 0;
    Ref_Manager* aux_Array_2_Refman = NULL;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, aux_Array_0, Int, 4, 1);
    a1_Length = 4;
    a1 = aux_Array_0;
    aux_Array_0 = NULL;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, a1)
    INIT_NEW_ARRAY(2, LUMI_block0_cleanup, aux_Array_1, Int, 6, 1);
    a2_Length = 6;
    a2 = aux_Array_1;
    aux_Array_1 = NULL;
    INIT_NEW_REFMAN(2, LUMI_block0_cleanup, a2)
    aux_Array_2_Refman = a1_Refman;
    aux_Array_2_Length = a1_Length;
    aux_Array_2 = a1;
    a1_Refman = a2_Refman;
    a1_Length = a2_Length;
    a1 = a2;
    a2_Refman = aux_Array_2_Refman;
    a2_Length = aux_Array_2_Length;
    a2 = aux_Array_2;
    aux_Array_2 = NULL;
    aux_Array_2_Refman = NULL;
/// @ t6
char* s1 = NULL;
    int s1_Max_length = 0;
    int* s1_Length = &Lumi_empty_int;
    char* s2 = NULL;
    int s2_Max_length = 0;
    int* s2_Length = &Lumi_empty_int;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    INIT_NEW_STRING(1, LUMI_block0_cleanup, s1, 4);
    INIT_NEW_STRING(2, LUMI_block0_cleanup, s2, 6);
    aux_String_0_Max_length = 4;
    aux_String_0_Length = s1_Length;
    aux_String_0 = s1;
    s1_Max_length = 6;
    s1_Length = s2_Length;
    s1 = s2;
    s2_Max_length = 4;
    s2_Length = aux_String_0_Length;
    s2 = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_int;
/// @ t7
char* s1 = NULL;
    int s1_Max_length = 0;
    int* s1_Length = &Lumi_empty_int;
    Ref_Manager* s1_Refman = NULL;
    char* s2 = NULL;
    int s2_Max_length = 0;
    int* s2_Length = &Lumi_empty_int;
    Ref_Manager* s2_Refman = NULL;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    char* aux_String_1 = NULL;
    int aux_String_1_Max_length = 0;
    int* aux_String_1_Length = &Lumi_empty_int;
    char* aux_String_2 = NULL;
    int aux_String_2_Max_length = 0;
    int* aux_String_2_Length = &Lumi_empty_int;
    Ref_Manager* aux_String_2_Refman = NULL;
    INIT_NEW_STRING(1, LUMI_block0_cleanup, aux_String_0, 4);
    s1_Max_length = 4;
    s1_Length = aux_String_0_Length;
    s1 = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_int;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, s1)
    INIT_NEW_STRING(2, LUMI_block0_cleanup, aux_String_1, 6);
    s2_Max_length = 6;
    s2_Length = aux_String_1_Length;
    s2 = aux_String_1;
    aux_String_1 = NULL;
    aux_String_1_Length = &Lumi_empty_int;
    INIT_NEW_REFMAN(2, LUMI_block0_cleanup, s2)
    aux_String_2_Refman = s1_Refman;
    aux_String_2_Max_length = s1_Max_length;
    aux_String_2_Length = s1_Length;
    aux_String_2 = s1;
    s1_Refman = s2_Refman;
    s1_Max_length = s2_Max_length;
    s1_Length = s2_Length;
    s1 = s2;
    s2_Refman = aux_String_2_Refman;
    s2_Max_length = aux_String_2_Max_length;
    s2_Length = aux_String_2_Length;
    s2 = aux_String_2;
    aux_String_2 = NULL;
    aux_String_2_Refman = NULL;
    aux_String_2_Length = &Lumi_empty_int;
/// @ t8
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    File* f;
};
void ut_M_Test_new(ut_M_Test* self, File* f);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(ut_M_Test* t1, ut_M_Test* t2);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_new(ut_M_Test* self, File* f) {
    unsigned LUMI_loop_depth = 1;
    File_Del(self->f);
    free(self->f);
    self->f = f;
    f = NULL;
LUMI_block0_cleanup:
    (void)0;
    File_Del(f);
    free(f);
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    File_Del(self->f);
    free(self->f);
}
void ut_M_fun(ut_M_Test* t1, ut_M_Test* t2) {
    unsigned LUMI_loop_depth = 1;
    File* aux_File_0 = NULL;
    aux_File_0 = t1->f;
    t1->f = t2->f;
    t2->f = aux_File_0;
    aux_File_0 = NULL;
LUMI_block0_cleanup:
    (void)0;
    File_Del(aux_File_0);
    free(aux_File_0);
    ut_M_Test_Del(t2);
    free(t2);
    ut_M_Test_Del(t1);
    free(t1);
}
/// @ t9
ut_M_Test* t1 = NULL;
    ut_M_Test* t2 = NULL;
    ut_M_Test* aux_Test_0 = NULL;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    t1 = ut_M_t;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    t2 = ut_M_t;
    aux_Test_0 = t1;
    t1 = t2;
    t2 = aux_Test_0;
    aux_Test_0 = NULL;
/// @ t10
ut_M_Test* t1 = NULL;
    Ref_Manager* t1_Refman = NULL;
    ut_M_Test* t2 = NULL;
    Ref_Manager* t2_Refman = NULL;
    ut_M_Test* aux_Test_0 = NULL;
    Ref_Manager* aux_Test_0_Refman = NULL;
    CHECK_REF(1, LUMI_block0_cleanup, *to)
    LUMI_inc_ref(*to_Refman);
    LUMI_dec_ref(t1_Refman);
    t1_Refman = *to_Refman;
    t1 = *to;
    CHECK_REF(2, LUMI_block0_cleanup, *to)
    LUMI_inc_ref(*to_Refman);
    LUMI_dec_ref(t2_Refman);
    t2_Refman = *to_Refman;
    t2 = *to;
    aux_Test_0_Refman = t1_Refman;
    aux_Test_0 = t1;
    t1_Refman = t2_Refman;
    t1 = t2;
    t2_Refman = aux_Test_0_Refman;
    t2 = aux_Test_0;
    aux_Test_0 = NULL;
    aux_Test_0_Refman = NULL;
/// @ t11
Int aux_Int_0 = 0;
    aux_Int_0 = ut_M_i;
    ut_M_i = *io;
    *io = aux_Int_0;
/// @ t12
ut_M_Test* aux_Test_0 = NULL;
    Ref_Manager* aux_Test_0_Refman = NULL;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_d, ut_M_d_Refman)
    aux_Test_0_Refman = ut_M_d->item_Refman;
    aux_Test_0 = ut_M_d->item;
    ut_M_d->item_Refman = ut_M_t_Refman;
    ut_M_d->item_Dynamic = &ut_M_Test_dynamic;
    ut_M_d->item = ut_M_t;
    ut_M_t_Refman = aux_Test_0_Refman;
    ut_M_t = aux_Test_0;
    aux_Test_0 = NULL;
    aux_Test_0_Refman = NULL;
/// @ te0
cannot swap access "weak" with other access "strong"
/// @ te1
swapping reference with itself
/// @ te2
conditionals not matching in type "String"
/// @ te3
swapping non assignable expression
/// @ te4
non matching types "Ta" and "Tc"
/// @ te5
cannot swap access "owner" with other access "strong"
/// @@ test-question-expression
/// @ t0
ut_M_b = ut_M_ostr != NULL;
/// @ t1
ut_M_b = ! (ut_M_arr != NULL && (ut_M_arr_Refman)->value != NULL);
/// @ t2
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    ut_M_b = ut_M_t->fun != NULL;
/// @ t3
ut_M_b = (*to) != NULL;
/// @ t4
ut_M_t = NULL;
    ut_M_t_Refman = NULL;
    ut_M_fun7(NULL, NULL, NULL, (void*)&(ut_M_t), &(ut_M_t_Refman), (void*)&(ut_M_t_Dynamic));
    ut_M_b = ut_M_t != NULL && (ut_M_t_Refman)->value != NULL;
/// @ t5
ut_M_Test* tt = NULL;
    Ref_Manager* tt_Refman = NULL;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_t)
    LUMI_inc_ref(ut_M_t_Refman);
    LUMI_dec_ref(tt_Refman);
    tt_Refman = ut_M_t_Refman;
    tt = ut_M_t;
    ut_M_b = (tt_Refman)->value != NULL;
/// @ t6
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    int s_Max_length;
    int* s_Length;
    Ref_Manager* s_Refman;
};
void ut_M_Test_meth(ut_M_Test* self, Bool* res);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_meth(ut_M_Test* self, Bool* res) {
    unsigned LUMI_loop_depth = 1;
    *res = self->s != NULL && (self->s_Refman)->value != NULL;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->s_Refman);
}
/// @ te0
cannot use "?" on void expression
/// @ te1
cannot use "?" on non conditional or weak reference of type "Int"
/// @ te2
cannot use "?" on non conditional or weak reference of type "Test"
/// @@ test-exclamation-expression
/// @ t0
char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    s_Max_length = ut_M_ostr_Max_length;
    s_Length = ut_M_ostr_Length;
    s = ut_M_ostr;
/// @ t1
ut_M_Test* tt = NULL;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t->t, ut_M_t->t_Refman)
    tt = ut_M_t->t;
/// @ t2
ut_M_Test* tu = NULL;
    ut_M_t = NULL;
    ut_M_t_Refman = NULL;
    ut_M_fun7(NULL, NULL, NULL, (void*)&(ut_M_t), &(ut_M_t_Refman), (void*)&(ut_M_t_Dynamic));
    CHECK_REFMAN(2, LUMI_block0_cleanup, ut_M_t_Refman)
    tu = &(ut_M_t->_base._base);
/// @ t3
CHECK_REF(1, LUMI_block0_cleanup, ut_M_tb)
    ut_M_i = ut_M_tb->_base._base.num;
/// @ t4
ut_M_Test* tt = NULL;
    Ref_Manager* tt_Refman = NULL;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_t)
    LUMI_inc_ref(ut_M_t_Refman);
    LUMI_dec_ref(tt_Refman);
    tt_Refman = ut_M_t_Refman;
    tt = ut_M_t;
/// @ t5
char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    Int aux_Int_0 = 0;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_str)
    String_length(ut_M_str, ut_M_str_Max_length, ut_M_str_Length, &(aux_Int_0));
    INIT_NEW_STRING(1, LUMI_block0_cleanup, s, aux_Int_0);
/// @ te0
ignoring empty reference check
/// @ te1
ignoring weak reference check
/// @ te2
ignoring empty reference check
/// @ te3
ignoring weak reference check
/// @ te4
ignoring empty reference check
/// @ te5
ignoring weak reference check
/// @ te6
ignoring empty reference check
/// @ te7
ignoring empty reference check
/// @ te8
ignoring empty reference check
/// @ te9
ignoring weak reference check
/// @ te10
ignoring empty reference check
/// @ te11
ignoring initialization error check
/// @ teo0
only one "!" needed
/// @ ten0
using "!" where there is no error
/// @ ten1
using "!" where there is no error
/// @ ten2
using "!" where there is no error
/// @ ten3
using "!" where there is no error
/// @ ten4
using "!" where there is no error
/// @ ten5
using "!" where there is no error
/// @ ten6
using "!" where there is no error
/// @ ten7
using "!" where there is no error
/// @ ten8
using "!" where there is no error
/// @ ten9
using "!" where there is no error
/// @ ten10
using "!" where there is no error
/// @ ten11
using "!" where there is no error
/// @ ten12
using "!" where there is no error
/// @ ten13
using "!" where there is no error
/// @ ten14
using "!" where there is no error
/// @ ten15
using "!" where there is no error
/// @ ten16
using "!" where there is no error
/// @ ten17
using "!" where there is no error
/// @ ten18
using "!" where there is no error
/// @ ten19
using "!" where there is no error
/// @ ten20
using "!" where there is no error
/// @ ten21
using "!" where there is no error
/// @ ten22
using "!" where there is no error
/// @ ten23
using "!" where there is no error
/// @ ten24
using "!" where there is no error
/// @ ten26
using "!" where there is no error
/// @ ten27
using "!" where there is no error
/// @ ten28
using "!" where there is no error
/// @ ten29
using "!" where there is no error
/// @ ten30
using "!" where there is no error
/// @ ten31
using "!" where there is no error
/// @ ten32
using "!" where there is no error
/// @@ test-dynamic
/// @ t0
ut_M_Ta a_Var = {{0}};
    ut_M_Ta* a = NULL;
    ut_M_Ta_Dynamic* a_Dynamic = &ut_M_Ta_dynamic;
    a = &a_Var;
/// @ t1
ut_M_Ta* a = NULL;
    ut_M_Ta_Dynamic* a_Dynamic = NULL;
/// @ t2
ut_M_Ta* nta = NULL;
    ut_M_Ta_Dynamic* nta_Dynamic = NULL;
    ut_M_Ta* aux_Ta_0 = NULL;
    ut_M_Ta_Dynamic* aux_Ta_0_Dynamic = &ut_M_Ta_dynamic;
    INIT_NEW(1, LUMI_block0_cleanup, aux_Ta_0, ut_M_Ta, 1);
    nta_Dynamic = aux_Ta_0_Dynamic;
    nta = aux_Ta_0;
    aux_Ta_0 = NULL;
    aux_Ta_0_Dynamic = NULL;
/// @ t3
ut_M_Ta* a = NULL;
    ut_M_Ta_Dynamic* a_Dynamic = &ut_M_Ta_dynamic;
    INIT_NEW(1, LUMI_block0_cleanup, a, ut_M_Ta, 1);
/// @ t4
ut_M_Ta* a = NULL;
    ut_M_Ta_Dynamic* a_Dynamic = NULL;
    CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_ta_Refman)
    a_Dynamic = ut_M_ta_Dynamic;
    a = ut_M_ta;
/// @ t5
ut_M_Ta* x = NULL;
    ut_M_Ta_Dynamic* x_Dynamic = NULL;
    CHECK_REFMAN(2, LUMI_block0_cleanup, ut_M_ta_Refman)
    x_Dynamic = ut_M_ta_Dynamic;
    x = ut_M_ta;
/// @ t6
LUMI_inc_ref(ut_M_tb_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = ut_M_tb_Refman;
    ut_M_ta_Dynamic = &(ut_M_tb_Dynamic->_base);
    ut_M_ta = &(ut_M_tb->_base);
/// @ t7
LUMI_inc_ref(ut_M_tc_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = ut_M_tc_Refman;
    ut_M_ta_Dynamic = &(ut_M_tc_Dynamic->_base._base);
    ut_M_ta = &(ut_M_tc->_base._base);
/// @ t8
LUMI_inc_ref(NULL);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = NULL;
    ut_M_ta_Dynamic = NULL;
    ut_M_ta = NULL;
/// @ t9
ut_M_Ta* aa = NULL;
    int aa_Length = 0;
    Ref_Manager* aa_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, aa)
    if (4 >= aa_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aa_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = aa_Refman;
    ut_M_ta_Dynamic = &ut_M_Ta_dynamic;
    ut_M_ta = aa + 4;
/// @ t10
ut_M_Tc* ca = NULL;
    int ca_Length = 0;
    Ref_Manager* ca_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, ca)
    if (4 >= ca_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(ca_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = ca_Refman;
    ut_M_ta_Dynamic = &(&ut_M_Tc_dynamic->_base._base);
    ut_M_ta = &((ca + 4)->_base._base);
/// @ t11
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_ta_Refman)
    if (ut_M_ta_Dynamic == NULL) RAISE(1, LUMI_block0_cleanup, empty_object)
    ut_M_ta_Dynamic->dyn(ut_M_ta, ut_M_ta_Dynamic);
/// @ t12
if (ut_M_tb_Dynamic == NULL) RAISE(1, LUMI_block0_cleanup, empty_object)
    ut_M_tb_Dynamic->_base.dyn(&(ut_M_tb->_base), &(ut_M_tb_Dynamic->_base));
/// @ t13
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    if (ut_M_tc_Dynamic == NULL) RAISE(1, LUMI_block0_cleanup, empty_object)
    ut_M_tc_Dynamic->_base._base.dyn(&(ut_M_tc->_base._base), &(ut_M_tc_Dynamic->_base._base));
/// @ t14
LUMI_inc_ref(ut_M_tc_Refman);
    LUMI_dec_ref(*tco_Refman);
    *tco_Refman = ut_M_tc_Refman;
    *tco_Dynamic = ut_M_tc_Dynamic;
    *tco = ut_M_tc;
    CHECK_REFMAN(2, LUMI_block0_cleanup, *tco_Refman)
    if (*tco_Dynamic == NULL) RAISE(2, LUMI_block0_cleanup, empty_object)
    (*tco_Dynamic)->_base._base.dyn(&((*tco)->_base._base), &((*tco_Dynamic)->_base._base));
/// @ t15
ut_M_ta = NULL;
    ut_M_ta_Refman = NULL;
    ut_M_ta_Dynamic = NULL;
    ut_M_fun7(&(ut_M_tc->_base), ut_M_tc_Refman, &(ut_M_tc_Dynamic->_base), (void*)&(ut_M_ta), &(ut_M_ta_Refman), (void*)&(ut_M_ta_Dynamic));
/// @ t16
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    Int x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_mock(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
Returncode ut_M_mock(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    CHECK_REF_REFMAN(5, LUMI_block0_cleanup, *t, *t_Refman)
    if (*t_Dynamic == NULL) RAISE(5, LUMI_block0_cleanup, empty_object)
    (*t_Dynamic)->meth(*t, *t_Dynamic);
LUMI_block0_cleanup:
    (void)0;
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
    void (*meth)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
};
struct ut_M_Test {
    ut_M_Base _base;
};
struct ut_M_Test_Dynamic {
    ut_M_Base_Dynamic _base;
};
void ut_M_Base_meth(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Test_fun(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_meth};
ut_M_Test_Dynamic ut_M_Test_dynamic = {{(Dynamic_Del)ut_M_Test_Del, ut_M_Base_meth}};
void ut_M_Base_meth(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
}
void ut_M_Test_fun(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    self_Dynamic->_base.meth(&(self->_base), &(self_Dynamic->_base));
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
/// @ t18
ut_M_Tb* aux_Tb_0 = NULL;
    Ref_Manager* aux_Tb_0_Refman = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = NULL;
    ut_M_fun7(NULL, NULL, NULL, &(aux_Tb_0), &(aux_Tb_0_Refman), &(aux_Tb_0_Dynamic));
/// @ te0
ignoring empty reference check
/// @@ test-function-object
/// @ t0
void (*fun)(void) = NULL;
    fun = ut_M_fun0;
    fun();
/// @ t1
void (*fun)(Int x, Int* y) = NULL;
    Int x = 0;
    fun = ut_M_fun5;
    fun(9, &(x));
/// @ t2
void (*fun)(ut_M_Test* self) = NULL;
    fun = ut_M_Test_meth;
    CHECK_REFMAN(2, LUMI_block0_cleanup, ut_M_t_Refman)
    fun(ut_M_t);
/// @ t3
void (*fun)(void) = NULL;
    fun = NULL;
    ut_M_b = fun != NULL;
    CHECK_REF(4, LUMI_block0_cleanup, fun)
    fun();
/// @ t4
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    ut_M_t->fun = ut_M_fun0;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_t->fun)
    ut_M_t->fun();
/// @ t5
void (*farr[38])(void) = {0};
    void (**farr1)(Int x, Int* y) = NULL;
    int farr1_Length = 0;
    Returncode (**farr2)(void) = NULL;
    int farr2_Length = 0;
    Returncode (**ufarr)(void) = NULL;
    int ufarr_Length = 0;
    /* initializing farr */
    INIT_NEW_ARRAY(2, LUMI_block0_cleanup, farr1, void (*)(Int x, Int* y), 12, 1);
    INIT_NEW_ARRAY(3, LUMI_block0_cleanup, farr2, Returncode (*)(void), 12, 1);
    farr[3] = ut_M_fun0;
    (farr[3])();
/// @ t6
void (*fun)(Int x, Int y) = NULL;
/// @ t7
void ut_M_mock(void (**f)(void));
void ut_M_mock(void (**f)(void)) {
    unsigned LUMI_loop_depth = 1;
    (*f)();
LUMI_block0_cleanup:
    (void)0;
}
/// @ t8
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    void (*fun)(Int x, Int y);
    Returncode (*afun[4])(Int x, Int* y);
};
void ut_M_Test_meth(ut_M_Test* self, Returncode (*fi)(Int x, Int y), void (**fo)(Int x, Int y));
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(void (*fi)(Int x, Int y), Returncode (**fo)(Int x, Int y));
void ut_M_afun(void (** in)(Int x, Int* y), int in_Length, Returncode (*** out)(void), int* out_Length);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_meth(ut_M_Test* self, Returncode (*fi)(Int x, Int y), void (**fo)(Int x, Int y)) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_fun(void (*fi)(Int x, Int y), Returncode (**fo)(Int x, Int y)) {
    unsigned LUMI_loop_depth = 1;
    Returncode (*aux_Func_0)(Int x, Int y) = NULL;
    ut_M_fun(NULL, &(aux_Func_0));
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_afun(void (** in)(Int x, Int* y), int in_Length, Returncode (*** out)(void), int* out_Length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t9
Returncode (*fun)(void) = NULL;
    fun = ut_M_fune;
    LUMI_err = fun();
    CHECK(3, LUMI_block0_cleanup)
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
/// @ te6
using invalid reference "fun"
/// @ te7
assigning empty into non-conditional type "Func"
/// @ te8
cannot use "?" on non conditional or weak reference of type "Func"
/// @ te9
non matching error result
/// @ te10
non matching error result
/// @@ test-builtin
/// @ ti0
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = Int_str(ut_M_i, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length);
    CHECK(1, LUMI_block0_cleanup)
/// @ tb0
ut_M_b = true;
/// @ tb1
ut_M_b = false;
/// @ c0
unknown symbol "EOF"
/// @ ta0
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    Array_length(ut_M_arr, ut_M_arr_Length, &(ut_M_i));
/// @ ts0
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_length(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(ut_M_i));
/// @ ts1
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_clear(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length);
/// @ ts2
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_equal(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_ostr, *ut_M_ostr_Length, &(ut_M_b));
/// @ ts3
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_get(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_i, &(ut_M_c));
    CHECK(1, LUMI_block0_cleanup)
/// @ ts4
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_set(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_i, ut_M_c);
    CHECK(1, LUMI_block0_cleanup)
/// @ ts5
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_append(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_c);
    CHECK(1, LUMI_block0_cleanup)
/// @ ts6
char sv[12] = {0};
    int sv_Length[1] = {0};
    /* initializing sv */
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_copy(sv, 12, sv_Length, ut_M_ostr, *ut_M_ostr_Length);
    CHECK(2, LUMI_block0_cleanup)
/// @ ts7
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_concat(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_ostr, *ut_M_ostr_Length);
    CHECK(1, LUMI_block0_cleanup)
/// @ ts8
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_concat_int(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_i);
    CHECK(1, LUMI_block0_cleanup)
/// @ ts9
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_find(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_ostr, *ut_M_ostr_Length, &(ut_M_i));
/// @ ts10
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_has(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_c, &(ut_M_b));
/// @ ts11
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_set(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, 0, 'a');
    CHECK(1, LUMI_block0_cleanup)
/// @ ts12
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_max_length(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(ut_M_i));
/// @ tf0
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = file_open_read(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(ut_M_fobj));
    CHECK(1, LUMI_block0_cleanup)
/// @ tf1
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = file_open_write(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(ut_M_fobj));
    CHECK(1, LUMI_block0_cleanup)
/// @ tf2
CHECK_REF(1, LUMI_block0_cleanup, ut_M_fobj)
    LUMI_err = file_close(ut_M_fobj);
    ut_M_fobj = NULL;
    CHECK(1, LUMI_block0_cleanup)
/// @ tf3
CHECK_REF(1, LUMI_block0_cleanup, ut_M_fobj)
    LUMI_err = File_getc(ut_M_fobj, &(ut_M_c), &(ut_M_b));
    CHECK(1, LUMI_block0_cleanup)
/// @ tf4
CHECK_REF(1, LUMI_block0_cleanup, ut_M_fobj)
    LUMI_err = File_putc(ut_M_fobj, ut_M_c);
    CHECK(1, LUMI_block0_cleanup)
/// @ tf5
CHECK_REF(1, LUMI_block0_cleanup, ut_M_fobj)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = File_write(ut_M_fobj, ut_M_ostr, *ut_M_ostr_Length);
    CHECK(1, LUMI_block0_cleanup)
/// @ ty0
char* argv = NULL;
    int argv_Length = 0;
    int argv_Value_length = 0;
    int* argv_String_length = NULL;
    argv_Length = sys->argv_Length;
    argv_Value_length = sys->argv_Value_length;
    argv_String_length = sys->argv_String_length;
    argv = sys->argv;
/// @ ty1
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = Sys_print(sys, ut_M_ostr, *ut_M_ostr_Length);
    CHECK(1, LUMI_block0_cleanup)
/// @ ty2
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = Sys_println(sys, ut_M_ostr, *ut_M_ostr_Length);
    CHECK(1, LUMI_block0_cleanup)
/// @ ty3
Sys_getchar(sys, &(ut_M_c), &(ut_M_b));
/// @ ty4
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = Sys_getline(sys, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length);
    CHECK(1, LUMI_block0_cleanup)
/// @ ty5
LUMI_err = Sys_exit(sys, ut_M_i);
    CHECK(1, LUMI_block0_cleanup)
/// @ ty6
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = Sys_system(sys, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(ut_M_i));
    CHECK(1, LUMI_block0_cleanup)
/// @ ty7
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = Sys_getenv(sys, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(ut_M_b));
    CHECK(1, LUMI_block0_cleanup)
/// @ ty8
LUMI_err = File_putc(sys->stdout_Cname, ut_M_c);
    CHECK(1, LUMI_block0_cleanup)
/// @ ty9
LUMI_err = File_getc(sys->stdin_Cname, &(ut_M_c), &(ut_M_b));
    CHECK(1, LUMI_block0_cleanup)
/// @ ty10
LUMI_err = File_putc(sys->stderr_Cname, ut_M_c);
    CHECK(1, LUMI_block0_cleanup)
/// @ tef0
cannot create objects with type "File"
/// @ tef1
cannot create objects with type "File"
/// @ tef2
cannot create objects with type "File"
/// @ tef3
using potentially illegal user reference "f"
/// @ tef4
using potentially illegal user reference "f"
/// @ tef5
using potentially illegal user reference "f"
/// @ tef6
assigning conditional into non-conditional type "File"
/// @ tey0
cannot create objects with type "Sys"
/// @ tey1
cannot create objects with type "Sys"
/// @ tey2
cannot create objects with type "Sys"
/// @@ test-general
/// @ t0
char* ut_M_str = NULL;
int ut_M_str_Max_length = 0;
int* ut_M_str_Length = &Lumi_empty_int;
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
char ut_M_s[12] = {0};
int ut_M_s_Length[1] = {0};
char* ut_M_us = NULL;
int ut_M_us_Max_length = 0;
int* ut_M_us_Length = &Lumi_empty_int;
char* ut_M_gs = NULL;
int ut_M_gs_Max_length = 0;
int* ut_M_gs_Length = &Lumi_empty_int;
void new_Mock(Bool* allocate_success) { }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Int x = 0;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int aux_String_0_Length[1] = {0};
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "mock.5.lm"
    /* initializing ut_M_s */
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.5.lm"
    ut_M_us_Max_length = 12;
    ut_M_us_Length = ut_M_s_Length;
    ut_M_us = ut_M_s;
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.5.lm"
    INIT_STRING_CONST(3, LUMI_block0_cleanup, aux_String_0, "global text");
    ut_M_gs_Max_length = aux_String_0_Max_length;
    ut_M_gs_Length = aux_String_0_Length;
    ut_M_gs = aux_String_0;
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
    x = 6;
    x = 7;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
MAIN_FUNC
/// @ t7
void ut_M_fun(void);
Returncode second_M_dummy(void);
char ut_M_s[12] = {0};
int ut_M_s_Length[1] = {0};
char* ut_M_us = NULL;
int ut_M_us_Max_length = 0;
int* ut_M_us_Length = &Lumi_empty_int;
int LUMI_file0_line_count[6] = {
    -1,-1,-1,-1, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.5.lm", 6, LUMI_file0_line_count}
};
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    ++LUMI_file_coverage[0].line_count[4];
    String_clear(ut_M_s, 12, ut_M_s_Length);
LUMI_block0_cleanup:
    (void)0;
}
Returncode second_M_dummy(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void new_Mock(Bool* allocate_success) { }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Bool LUMI_success = true;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "mock.5.lm"
    /* initializing ut_M_s */
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.5.lm"
    ut_M_us_Max_length = 12;
    ut_M_us_Length = ut_M_s_Length;
    ut_M_us = ut_M_s;
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
    LUMI_success &= LUMI_run_test("dummy", second_M_dummy);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
LUMI_block0_cleanup:
    return LUMI_err;
}
TEST_MAIN_FUNC
/// @ t8
void ut_M_fun(void);
Returncode test_M_test_fun(void);
int LUMI_file0_line_count[5] = {
    -1,-1,-1, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.5.lm", 5, LUMI_file0_line_count}
};
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
Returncode test_M_test_fun(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void new_Mock(Bool* allocate_success) { }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Bool LUMI_success = true;
    LUMI_success &= LUMI_run_test("test-fun", test_M_test_fun);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
LUMI_block0_cleanup:
    return LUMI_err;
}
TEST_MAIN_FUNC
/// @ te0
unknown keyword "error"
/// @ te1
statement has no effect
/// @ te2
unreachable code
/// @ te3
unreachable code
/// @ te4
expected new-line in line end, got "?"
/// @ te5
expected new-line after "main", got "("
/// @ te6
indentation too long, expected 0 got 4
/// @ te7
indentation too short, expected 12 got 8
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
/// @ t4
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    ut_M_Test* to;
    ut_M_Test* ts;
    Ref_Manager* ts_Refman;
    ut_M_Test* tw;
    Ref_Manager* tw_Refman;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->tw_Refman);
    SELF_REF_DEL_STR(ut_M_Test, ts);
    LUMI_owner_dec_ref(self->ts_Refman);
    SELF_REF_DEL(ut_M_Test, to);
    free(self->to);
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
expected block in a new line, got "end-of-file"
/// @ te10
type with no fields "Error"
/// @ te11
expected "(" after "new", got " "
/// @ te12
constructor already defined for type "Error"
/// @ te13
constructor with outputs
/// @ te14
recursive declaration of type "Error", extended by type "Error"
/// @ te15
recursive declaration of type "Aerror", extended by type "Berror", extended by type "Aerror"
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
    ut_M_Base_Dynamic* b_Dynamic;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
    void (*dyn0)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
    Returncode (*dyn1)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
    void (*dyn2)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
};
struct ut_M_Mid {
    ut_M_Base _base;
    Int y;
    ut_M_Mid* m;
    ut_M_Mid_Dynamic* m_Dynamic;
};
struct ut_M_Mid_Dynamic {
    ut_M_Base_Dynamic _base;
    void (*dyn3)(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
    Returncode (*dyn4)(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
};
struct ut_M_Top {
    ut_M_Mid _base;
    Int z;
    ut_M_Top* t;
    ut_M_Top_Dynamic* t_Dynamic;
};
struct ut_M_Top_Dynamic {
    ut_M_Mid_Dynamic _base;
    void (*dyn5)(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
};
void ut_M_Base_stat(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_dyn0(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
Returncode ut_M_Base_dyn1(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_dyn2(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Mid_dyn0(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Mid_dyn3(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
Returncode ut_M_Mid_dyn4(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self);
void ut_M_Top_dyn0(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
Returncode ut_M_Top_dyn1(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
void ut_M_Top_dyn3(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
void ut_M_Top_dyn5(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
void ut_M_Top_Del(ut_M_Top* self);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_dyn0, ut_M_Base_dyn1, ut_M_Base_dyn2};
ut_M_Mid_Dynamic ut_M_Mid_dynamic = {{(Dynamic_Del)ut_M_Mid_Del, (void (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic))ut_M_Mid_dyn0, ut_M_Base_dyn1, ut_M_Base_dyn2}, ut_M_Mid_dyn3, ut_M_Mid_dyn4};
ut_M_Top_Dynamic ut_M_Top_dynamic = {{{(Dynamic_Del)ut_M_Top_Del, (void (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic))ut_M_Top_dyn0, (Returncode (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic))ut_M_Top_dyn1, ut_M_Base_dyn2}, (void (*)(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic))ut_M_Top_dyn3, ut_M_Mid_dyn4}, ut_M_Top_dyn5};
void ut_M_Base_stat(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_dyn0(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
Returncode ut_M_Base_dyn1(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_Base_dyn2(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    SELF_REF_DEL_DYN(ut_M_Base, _, b);
    free(self->b);
}
void ut_M_Mid_dyn0(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Mid_dyn3(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
Returncode ut_M_Mid_dyn4(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_Mid_Del(ut_M_Mid* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
    SELF_REF_DEL_DYN(ut_M_Mid, _base._, m);
    free(self->m);
}
void ut_M_Top_dyn0(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Mid_dyn0(&(self->_base), &(self_Dynamic->_base));
LUMI_block0_cleanup:
    (void)0;
}
Returncode ut_M_Top_dyn1(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    LUMI_err = ut_M_Base_dyn1(&(self->_base._base), &(self_Dynamic->_base._base));
    CHECK(20, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_Top_dyn3(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Mid_dyn3(&(self->_base), &(self_Dynamic->_base));
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Top_dyn5(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Mid_dyn0(&(self->_base), &(self_Dynamic->_base));
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Top_Del(ut_M_Top* self) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base));
    SELF_REF_DEL_DYN(ut_M_Top, _base._base._, t);
    free(self->t);
}
/// @ t1
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    ut_M_Test* to;
    ut_M_Test_Dynamic* to_Dynamic;
    ut_M_Test* ts;
    Ref_Manager* ts_Refman;
    ut_M_Test_Dynamic* ts_Dynamic;
    ut_M_Test* tw;
    Ref_Manager* tw_Refman;
    ut_M_Test_Dynamic* tw_Dynamic;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*fun)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
};
void ut_M_Test_fun(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_fun};
void ut_M_Test_fun(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->tw_Refman);
    SELF_REF_DEL_STR_DYN(ut_M_Test, _, ts);
    LUMI_owner_dec_ref(self->ts_Refman);
    SELF_REF_DEL_DYN(ut_M_Test, _, to);
    free(self->to);
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
/// @ te5
too many parameters
/// @ te6
non matching error result
/// @@ test-function
/// @ t0
void ut_M_name(void);
void ut_M_name(void) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t1
void ut_M_name(char* self, int self_Max_length, int* self_Length, char* text, int text_Max_length, int* text_Length, Int num);
void ut_M_name(char* self, int self_Max_length, int* self_Length, char* text, int text_Max_length, int* text_Length, Int num) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t2
void ut_M_name(char** text, int* text_Max_length, int** text_Length, Int* num);
void ut_M_name(char** text, int* text_Max_length, int** text_Length, Int* num) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t3
void ut_M_name(Char param, char** out, int* out_Max_length, int** out_Length);
void ut_M_name(Char param, char** out, int* out_Max_length, int** out_Length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t4
void ut_M_name(Int* array, int array_Length);
void ut_M_name(Int* array, int array_Length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t5
void ut_M_name(void (*fun)(Int x, Int* y), void (**joy)(void));
void ut_M_name(void (*fun)(Int x, Int* y), void (**joy)(void)) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t6
void ut_M_name(void);
void ut_M_name(void) {
    unsigned LUMI_loop_depth = 1;
    Int x = 0;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t7
Returncode ut_M_name(char* self, int self_Max_length, int* self_Length, Int px, Char* pu, int pu_Length, char* po, int po_Max_length, int* po_Length, char** oself, int* oself_Max_length, int** oself_Length, Ref_Manager** oself_Refman, Int* ox, char** ou, int* ou_Max_length, int** ou_Length, Ref_Manager** ou_Refman, char** oo, int* oo_Max_length, int** oo_Length);
Returncode ut_M_name(char* self, int self_Max_length, int* self_Length, Int px, Char* pu, int pu_Length, char* po, int po_Max_length, int* po_Length, char** oself, int* oself_Max_length, int** oself_Length, Ref_Manager** oself_Refman, Int* ox, char** ou, int* ou_Max_length, int** ou_Length, Ref_Manager** ou_Refman, char** oo, int* oo_Max_length, int** oo_Length) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Int x = 0;
    char* u = NULL;
    int u_Max_length = 0;
    int* u_Length = &Lumi_empty_int;
    char* o = NULL;
    int o_Max_length = 0;
    int* o_Length = &Lumi_empty_int;
    char v[12] = {0};
    int v_Length[1] = {0};
    char* n = NULL;
    int n_Max_length = 0;
    int* n_Length = &Lumi_empty_int;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    char* aux_String_1 = NULL;
    int aux_String_1_Max_length = 0;
    int aux_String_1_Length[1] = {0};
    Char* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    /* initializing v */
    INIT_NEW_STRING(7, LUMI_block0_cleanup, n, 12);
    INIT_NEW_STRING(8, LUMI_block0_cleanup, aux_String_0, 12);
    String_Del(o);
    free(o);
    o_Max_length = 12;
    o_Length = aux_String_0_Length;
    o = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_int;
    INIT_STRING_CONST(9, LUMI_block0_cleanup, aux_String_1, "constant string");
    u_Max_length = aux_String_1_Max_length;
    u_Length = aux_String_1_Length;
    u = aux_String_1;
    if (2 + 6 > *(po_Length)) RAISE(10, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = po + 2;
    aux_Array_0_Length = 6;
    pu_Length = aux_Array_0_Length;
    pu = aux_Array_0;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0);
    free(aux_String_0);
    String_Del(n);
    free(n);
    String_Del(o);
    free(o);
    String_Del(po);
    free(po);
    return LUMI_err;
}
/// @ t8
typedef struct ut_M_Struct ut_M_Struct;
typedef struct ut_M_Class ut_M_Class;
typedef struct ut_M_Class_Dynamic ut_M_Class_Dynamic;
struct ut_M_Struct {
    ut_M_Struct* s;
    ut_M_Struct* as;
    int as_Length;
    char* astr;
    int astr_Length;
    int astr_Value_length;
    int* astr_String_length;
};
struct ut_M_Class {
    ut_M_Class* c;
    ut_M_Class_Dynamic* c_Dynamic;
    ut_M_Class* ac;
    int ac_Length;
};
struct ut_M_Class_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Class* self, ut_M_Class_Dynamic* self_Dynamic);
};
void ut_M_Struct_Del(ut_M_Struct* self);
void ut_M_Class_meth(ut_M_Class* self, ut_M_Class_Dynamic* self_Dynamic);
void ut_M_Class_Del(ut_M_Class* self);
void ut_M_name(ut_M_Struct* ps, ut_M_Class* pc, ut_M_Class_Dynamic* pc_Dynamic, ut_M_Struct* pas, int pas_Length, ut_M_Class* pac, int pac_Length);
Generic_Type_Dynamic ut_M_Struct_dynamic = {(Dynamic_Del)ut_M_Struct_Del};
ut_M_Class_Dynamic ut_M_Class_dynamic = {(Dynamic_Del)ut_M_Class_Del, ut_M_Class_meth};
void ut_M_Struct_Del(ut_M_Struct* self) {
    if (self == NULL) return;
    free(self->astr_String_length);
    free(self->astr);
    ARRAY_DEL(ut_M_Struct, self->as, self->as_Length)
    free(self->as);
    SELF_REF_DEL(ut_M_Struct, s);
    free(self->s);
}
void ut_M_Class_meth(ut_M_Class* self, ut_M_Class_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Class_Del(ut_M_Class* self) {
    if (self == NULL) return;
    ARRAY_DEL(ut_M_Class, self->ac, self->ac_Length)
    free(self->ac);
    SELF_REF_DEL_DYN(ut_M_Class, _, c);
    free(self->c);
}
void ut_M_name(ut_M_Struct* ps, ut_M_Class* pc, ut_M_Class_Dynamic* pc_Dynamic, ut_M_Struct* pas, int pas_Length, ut_M_Class* pac, int pac_Length) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Struct* s = NULL;
    ut_M_Class* c = NULL;
    ut_M_Class_Dynamic* c_Dynamic = NULL;
    ut_M_Struct* as = NULL;
    int as_Length = 0;
    ut_M_Class* ac = NULL;
    int ac_Length = 0;
    Int* ai = NULL;
    int ai_Length = 0;
    File* af = NULL;
    int af_Length = 0;
    char* astr = NULL;
    int astr_Length = 0;
    int astr_Value_length = 0;
    int* astr_String_length = NULL;
LUMI_block0_cleanup:
    (void)0;
    free(astr_String_length);
    free(astr);
    ARRAY_DEL(File, af, af_Length)
    free(af);
    free(ai);
    ARRAY_DEL(ut_M_Class, ac, ac_Length)
    free(ac);
    ARRAY_DEL(ut_M_Struct, as, as_Length)
    free(as);
    if (c_Dynamic != NULL) c_Dynamic->_del(c);
    free(c);
    ut_M_Struct_Del(s);
    free(s);
    ARRAY_DEL(ut_M_Class, pac, pac_Length)
    free(pac);
    ARRAY_DEL(ut_M_Struct, pas, pas_Length)
    free(pas);
    if (pc_Dynamic != NULL) pc_Dynamic->_del(pc);
    free(pc);
    ut_M_Struct_Del(ps);
    free(ps);
}
/// @ t9
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    Int x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_name(ut_M_Test** t, ut_M_Test_Dynamic** t_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_name(ut_M_Test** t, ut_M_Test_Dynamic** t_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    if (*t_Dynamic != NULL) (*t_Dynamic)->_del(*t);
    free(*t);
    *t_Dynamic = NULL;
    *t = NULL;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t10
void ut_M_name(char* ai, int ai_Length, int ai_Value_length, int ai_Value_value_length, int* ai_String_length, Int** ao, int* ao_Length, int* ao_Value_length);
void ut_M_name(char* ai, int ai_Length, int ai_Value_length, int ai_Value_value_length, int* ai_String_length, Int** ao, int* ao_Length, int* ao_Value_length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ tm0
void new_Mock(Bool* allocate_success) { }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Int x = 0;
LUMI_block0_cleanup:
    (void)0;
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
expected space after "user", got ")"
/// @ te8
expected space after "type", got "new-line"
/// @ te9
illegal access "error"
/// @ te10
expected space or new-line after ",", got "u"
/// @ te11
expected ">(" got "()"
/// @ te12
expected block in a new line, got "end-of-file"
/// @ te13
indentation too long, expected 4 got 8
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
/// @ te20
indentation too short, expected 8 got 4
/// @ te21
misplaced item "Error"
/// @ te22
misplaced item "error"
/// @ te23
redefinition of variable "error"
/// @ te24
redefinition of variable "error"
/// @ te25
redefinition of global variable "error"
/// @ te26
variable name overrides function "error"
/// @ te27
variable name overrides function "error"
/// @ te28
illegal variable name "Error"
/// @ te29
not yet supporting non-conditional and non-primitive output "s"
/// @ te30
error raised inside function not declared as error raising "fun"
/// @ te31
error raised inside function not declared as error raising "fun"
/// @ te32
error raised inside function not declared as error raising "fun"
/// @ te33
error raised inside function not declared as error raising "fun"
/// @@ test-members
/// @ t0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
    char* str;
    int str_Max_length;
    int* str_Length;
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
void ut_M_Test_name(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_name(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    self->x = 2;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ t2
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
void ut_M_Test_name(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_name(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    Int x = 0;
    x = self->x;
LUMI_block0_cleanup:
    (void)0;
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
void ut_M_Test1_fun(ut_M_Test1* self);
void ut_M_Test1_Del(ut_M_Test1* self);
void ut_M_Test2_name(ut_M_Test2* self);
void ut_M_Test2_Del(ut_M_Test2* self);
void ut_M_fun(void);
Generic_Type_Dynamic ut_M_Test1_dynamic = {(Dynamic_Del)ut_M_Test1_Del};
Generic_Type_Dynamic ut_M_Test2_dynamic = {(Dynamic_Del)ut_M_Test2_Del};
Int ut_M_name = 0;
void ut_M_Test1_fun(ut_M_Test1* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test1_Del(ut_M_Test1* self) {
    if (self == NULL) return;
}
void ut_M_Test2_name(ut_M_Test2* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test2_Del(ut_M_Test2* self) {
    if (self == NULL) return;
}
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t8
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
void ut_M_Test_fun(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_fun(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    if (self->x > 3) {
        self->x = 3;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    do {
        Int aux_Int_0 = 0;
        LUMI_loop_depth = 3;
        do {
            Int n = 0;
            LUMI_loop_depth = 5;
            if (!(aux_Int_0 < 4)) { LUMI_loop_depth = 3; goto LUMI_block3_cleanup; }
            n = aux_Int_0;
            aux_Int_0 += 1;
            self->x += n;
        LUMI_block3_cleanup:
            (void)0;
        } while (LUMI_loop_depth >= 4);
        if (LUMI_loop_depth < 3) goto LUMI_block2_cleanup;
        if (!(self->x < 30)) { LUMI_loop_depth = 1; goto LUMI_block2_cleanup; }
    LUMI_block2_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ t9
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
void ut_M_Test_fun(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_Test_fun(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    self->x = 3;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t10
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
void ut_M_Test_fun(ut_M_Test* self, char* s, int s_Max_length, int* s_Length, Int* x);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_Test_fun(ut_M_Test* self, char* s, int s_Max_length, int* s_Length, Int* x) {
    unsigned LUMI_loop_depth = 1;
    String_length(s, s_Max_length, s_Length, &(*x));
LUMI_block0_cleanup:
    (void)0;
}
/// @ t11
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
void ut_M_Test_new(ut_M_Test* self, Int x);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_Test_new(ut_M_Test* self, Int x) {
    unsigned LUMI_loop_depth = 1;
    self->x = x;
LUMI_block0_cleanup:
    (void)0;
}
/// @ te0
redefinition of field "name"
/// @ te1
field name overrides method "name"
/// @ te2
redefinition of method "name"
/// @ te3
method name overrides field "name"
/// @ te4
assigning into an owner a non-owner access "user"
/// @ te5
expected block in a new line, got " "
/// @ te6
misplaced item "error"
/// @ te7
type "Test" already implemented method "fun"
/// @ te8
type "Test" already implemented method "fun"
/// @ te9
expected name after ".", got "."
/// @ te10
field "num" is not a global member of type "Test"
/// @ te11
missing access before method name
/// @ te12
missing access before method name
/// @ te13
too few outputs
/// @ te14
non matching error result
/// @@ test-return
/// @ t0
void ut_M_name(void);
void ut_M_name(void) {
    unsigned LUMI_loop_depth = 1;
    LUMI_loop_depth = 0; goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t1
Returncode ut_M_name(void);
Returncode ut_M_name(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    USER_RAISE(2, LUMI_block0_cleanup, NULL, 0)
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ t2
Returncode ut_M_name(void);
Returncode ut_M_name(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int aux_String_0_Length[1] = {0};
    INIT_STRING_CONST(2, LUMI_block0_cleanup, aux_String_0, "some error");
    USER_RAISE(2, LUMI_block0_cleanup, aux_String_0, *(aux_String_0_Length))
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ t3
Returncode ut_M_name(char* arr, int arr_Length, int arr_Value_length, int* arr_String_length);
Returncode ut_M_name(char* arr, int arr_Length, int arr_Value_length, int* arr_String_length) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    if (3 >= arr_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_String_0 = arr + 3 * arr_Value_length;
    aux_String_0_Max_length = arr_Value_length;
    aux_String_0_Length = arr_String_length + 3;
    USER_RAISE(2, LUMI_block0_cleanup, aux_String_0, *(aux_String_0_Length))
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ t4
char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    Ref_Manager* s_Refman = NULL;
    CHECK_REFMAN(2, LUMI_block0_cleanup, s_Refman)
    USER_RAISE(2, LUMI_block0_cleanup, s, *(s_Length))
/// @ te0
expected new-line after "return", got "("
/// @ te1
expected space or new-line after "raise!", got "("
/// @ te2
got "Int" expression, expected "String"
/// @ te3
got "Empty Symbol" expression, expected "String"
/// @ te4
expected ! after "raise", got "new-line"
/// @@ test-code-variables
/// @ t0
Int x = 0;
/// @ t1
char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
/// @ t2
Int* a = NULL;
    int a_Length = 0;
/// @ t3
ut_M_Test* tt = NULL;
/// @ t4
char s[12] = {0};
    int s_Length[1] = {0};
    /* initializing s */
/// @ t5
Int a[12] = {0};
    /* initializing a */
/// @ t6
ut_M_Test a[12] = {0};
    /* initializing a */
/// @ t7
char sa[12 * 7] = {0};
    int sa_String_length[12] = {0};
    /* initializing sa */
/// @ t8
char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    INIT_NEW_STRING(1, LUMI_block0_cleanup, s, 12);
    String_Del(*so);
    LUMI_owner_dec_ref(*so_Refman);
    *so_Max_length = 12;
    *so_Length = s_Length;
    *so = s;
    s = NULL;
    s_Length = &Lumi_empty_int;
    INIT_NEW_REFMAN(2, LUMI_block0_cleanup, *so)
/// @ t9
ut_M_Ta a[12] = {0};
    /* initializing a */
/// @ t10
Int* a = NULL;
    int a_Length = 0;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, a, Int, 12, 1);
/// @ t11
char* sa = NULL;
    int sa_Length = 0;
    int sa_Value_length = 0;
    int* sa_String_length = NULL;
    sa_Value_length = 7;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, sa, char, 12, sa_Value_length);
    sa_String_length = LUMI_alloc(sizeof(int) * sa_Length);
/// @ t12
char aa[3 * 4 * 5] = {0};
    int aa_String_length[3 * 4] = {0};
    /* initializing aa */
/// @ t13
char* aa = NULL;
    int aa_Length = 0;
    int aa_Value_length = 0;
    int aa_Value_value_length = 0;
    int* aa_String_length = NULL;
    aa_Value_length = 4;
    aa_Value_value_length = 5;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, aa, char, 3, aa_Value_length * aa_Value_value_length);
    aa_String_length = LUMI_alloc(sizeof(int) * aa_Length * aa_Value_length);
/// @ t14
Returncode ut_M_fun(void);
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char sv[4] = {0};
    int sv_Length[1] = {0};
    /* initializing sv */
    if (1 > 2) {
        Char* su = NULL;
        int su_Length = 0;
        Char* aux_Array_0 = NULL;
        int aux_Array_0_Length = 0;
        if (1 + 2 > *(sv_Length)) RAISE(4, LUMI_block1_cleanup, slice_index)
        aux_Array_0 = sv + 1;
        aux_Array_0_Length = 2;
        su_Length = aux_Array_0_Length;
        su = aux_Array_0;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ te0
expected space after "type", got "new-line"
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
sequence length is not constant
/// @ te10
illegal variable name "error--name"
/// @@ test-initialize
/// @ t0
ut_M_Tb* aux_Tb_0 = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = &ut_M_Tb_dynamic;
    INIT_NEW(1, LUMI_block0_cleanup, aux_Tb_0, ut_M_Tb, 1);
    LUMI_err = ut_M_Tb_new(aux_Tb_0, aux_Tb_0_Dynamic, ut_M_i);
    if (ut_M_tb_Dynamic != NULL) ut_M_tb_Dynamic->_base._del(ut_M_tb);
    LUMI_owner_dec_ref(ut_M_tb_Refman);
    ut_M_tb_Dynamic = aux_Tb_0_Dynamic;
    ut_M_tb = aux_Tb_0;
    aux_Tb_0 = NULL;
    aux_Tb_0_Dynamic = NULL;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, ut_M_tb)
/// @ t1
char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    INIT_NEW_STRING(1, LUMI_block0_cleanup, aux_String_0, ut_M_arr[0]);
    ut_M_str_Max_length = aux_String_0_Max_length;
    ut_M_str_Length = aux_String_0_Length;
    ut_M_str = aux_String_0;
/// @ t2
Int* a = NULL;
    int a_Length = 0;
    Int* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, aux_Array_0, Int, ut_M_arr[0], 1);
    a_Length = aux_Array_0_Length;
    a = aux_Array_0;
    aux_Array_0 = NULL;
/// @ t3
ut_M_Test* a = NULL;
    int a_Length = 0;
    ut_M_Test* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, aux_Array_0, ut_M_Test, ut_M_arr[0], 1);
    a_Length = aux_Array_0_Length;
    a = aux_Array_0;
    aux_Array_0 = NULL;
/// @ t4
char* sa = NULL;
    int sa_Length = 0;
    int sa_Value_length = 0;
    int* sa_String_length = NULL;
    char* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    int aux_Array_0_Value_length = 0;
    int* aux_Array_0_String_length = NULL;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (1 >= ut_M_arr_Length) RAISE(1, LUMI_block0_cleanup, slice_index)
    aux_Array_0_Value_length = ut_M_arr[1];
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, aux_Array_0, char, ut_M_arr[0], aux_Array_0_Value_length);
    aux_Array_0_String_length = LUMI_alloc(sizeof(int) * aux_Array_0_Length);
    sa_Length = aux_Array_0_Length;
    sa_Value_length = aux_Array_0_Value_length;
    sa_String_length = aux_Array_0_String_length;
    sa = aux_Array_0;
    aux_Array_0 = NULL;
/// @ t5
Int x = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    x = ut_M_arr[0];
/// @ t6
char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    s_Max_length = ut_M_ostr_Max_length;
    s_Length = ut_M_ostr_Length;
    s = ut_M_ostr;
/// @ t7
char s[12] = {0};
    int s_Length[1] = {0};
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int aux_String_0_Length[1] = {0};
    INIT_STRING_CONST(1, LUMI_block0_cleanup, aux_String_0, "some string");
    /* initializing s */
    LUMI_err = String_copy(s, 12, s_Length, aux_String_0, *aux_String_0_Length);
/// @ t8
char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    INIT_NEW_STRING(1, LUMI_block0_cleanup, s, ut_M_i);
    LUMI_err = String_copy(s, s_Max_length, s_Length, ut_M_ostr, *ut_M_ostr_Length);
/// @ t9
ut_M_Test* tt = NULL;
    CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    tt = &(ut_M_tc->_base._base._base);
/// @ t10
ut_M_Tc tt_Var = {{{{0}}}};
    ut_M_Tc* tt = NULL;
    ut_M_Tc_Dynamic* tt_Dynamic = &ut_M_Tc_dynamic;
    tt = &tt_Var;
    LUMI_err = ut_M_Tb_new(&(tt->_base), &(tt_Dynamic->_base), 3);
/// @ t11
ut_M_Tc* tt = NULL;
    ut_M_Tc_Dynamic* tt_Dynamic = &ut_M_Tc_dynamic;
    INIT_NEW(1, LUMI_block0_cleanup, tt, ut_M_Tc, 1);
    LUMI_err = ut_M_Tb_new(&(tt->_base), &(tt_Dynamic->_base), 3);
/// @ t12
ut_M_Tc* aux_Tc_0 = NULL;
    ut_M_Tc_Dynamic* aux_Tc_0_Dynamic = &ut_M_Tc_dynamic;
    INIT_NEW(1, LUMI_block0_cleanup, aux_Tc_0, ut_M_Tc, 1);
    LUMI_err = ut_M_Tb_new(&(aux_Tc_0->_base), &(aux_Tc_0_Dynamic->_base), 3);
    if (ut_M_tb_Dynamic != NULL) ut_M_tb_Dynamic->_base._del(ut_M_tb);
    LUMI_owner_dec_ref(ut_M_tb_Refman);
    ut_M_tb_Dynamic = &(aux_Tc_0_Dynamic->_base);
    ut_M_tb = &(aux_Tc_0->_base);
    aux_Tc_0 = NULL;
    aux_Tc_0_Dynamic = NULL;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, ut_M_tb)
/// @ t13
ut_M_Tb* tt = NULL;
    ut_M_Tb_Dynamic* tt_Dynamic = NULL;
    tt_Dynamic = ut_M_tb_Dynamic;
    tt = ut_M_tb;
/// @ t14
ut_M_Ta* ota = NULL;
    ut_M_Ta_Dynamic* ota_Dynamic = NULL;
    LUMI_var_dec_ref(ut_M_tb_Refman);
    ota_Dynamic = &(ut_M_tb_Dynamic->_base);
    ota = &(ut_M_tb->_base);
    ut_M_tb = NULL;
    ut_M_tb_Refman = NULL;
    ut_M_tb_Dynamic = NULL;
/// @ t15
char* sa = NULL;
    int sa_Length = 0;
    int sa_Value_length = 0;
    int sa_Value_value_length = 0;
    int* sa_String_length = NULL;
    char* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    int aux_Array_0_Value_length = 0;
    int aux_Array_0_Value_value_length = 0;
    int* aux_Array_0_String_length = NULL;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    aux_Array_0_Value_length = ut_M_arr[1];
    aux_Array_0_Value_value_length = ut_M_arr[2];
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, aux_Array_0, char, ut_M_arr[0], aux_Array_0_Value_length * aux_Array_0_Value_value_length);
    aux_Array_0_String_length = LUMI_alloc(sizeof(int) * aux_Array_0_Length * aux_Array_0_Value_length);
    sa_Length = aux_Array_0_Length;
    sa_Value_length = aux_Array_0_Value_length;
    sa_Value_value_length = aux_Array_0_Value_value_length;
    sa_String_length = aux_Array_0_String_length;
    sa = aux_Array_0;
    aux_Array_0 = NULL;
/// @ t16
void ut_M_get(File** a);
void ut_M_get(File** a) {
    unsigned LUMI_loop_depth = 1;
    File* b = NULL;
    File* aux_File_0 = NULL;
    ut_M_get(&(aux_File_0));
    b = aux_File_0;
    aux_File_0 = NULL;
LUMI_block0_cleanup:
    (void)0;
    File_Del(aux_File_0);
    free(aux_File_0);
    File_Del(b);
    free(b);
}
/// @ t17
ut_M_Test* ot = NULL;
    ut_M_Test* st = NULL;
    Ref_Manager* st_Refman = NULL;
    LUMI_var_dec_ref(*to_Refman);
    ot = *to;
    *to = NULL;
    *to_Refman = NULL;
    st = ot;
    ot = NULL;
    INIT_NEW_REFMAN(2, LUMI_block0_cleanup, st)
/// @ t18
ut_M_Tc tt_Var = {{{{0}}}};
    ut_M_Tc* tt = NULL;
    Ref_Manager* tt_Refman = NULL;
    ut_M_Tc_Dynamic* tt_Dynamic = &ut_M_Tc_dynamic;
    tt = &tt_Var;
    INIT_VAR_REFMAN(1, LUMI_block0_cleanup, tt)
    LUMI_err = ut_M_Tb_new(&(tt->_base), &(tt_Dynamic->_base), 3);
/// @ t19
ut_M_Test* t1 = NULL;
    ut_M_Test t2_Var = {0};
    ut_M_Test* t2 = NULL;
    Ref_Manager* t2_Refman = NULL;
    INIT_NEW(1, LUMI_block0_cleanup, t1, ut_M_Test, 1);
    t2 = &t2_Var;
    INIT_VAR_REFMAN(2, LUMI_block0_cleanup, t2)
/// @ t20
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
void ut_M_Test_new(ut_M_Test* self, Int x);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_new(ut_M_Test* self, Int x) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {0};
    ut_M_Test* t = NULL;
    t = &t_Var;
    ut_M_Test_new(t, 3);
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
}
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
generic arrays not supported
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
no constructor for type "Array"
/// @ te17
cannot assign "Int" into "Bool"
/// @ te18
only one initialization parameter expected
/// @ te19
no constructor for type "Test"
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
/// @ te25
using invalid reference "s"
/// @ te26
assigning empty into non-conditional type "String"
/// @ te27
ignoring empty reference check
/// @ te28
using before declaration variable "error"
/// @ te29
using before declaration variable "error"
/// @ te30
using before declaration variable "error"
/// @ te31
unknown symbol "error"
/// @ te32
unexpected ? initializing type "Test"
/// @ te33
cannot use "?" on non conditional or weak reference of type "Type Name"
/// @ te34
ignoring initialization error check
/// @ te35
ignoring initialization error check
/// @ te36
using "!" where there is no error
/// @ te37
using "!" where there is no error
/// @ te38
unexpected "!" after "s"
/// @@ test-comment
/// @ t0
Int x = 0;
/// @ t1
Int x = 0;
/// @ t2
Int x = 0;
/// @ t3
Int x = 0;
/// @@ test-block
/// @ t0
{
        ut_M_Test* tt = NULL;
        INIT_NEW(2, LUMI_block1_cleanup, tt, ut_M_Test, 1);
        ut_M_i += 1;
    LUMI_block1_cleanup:
        (void)0;
    ut_M_Test_Del(tt);
        free(tt);
    }
/// @ t1
{
        LUMI_loop_depth = 0; goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    }
/// @ t2
{
        Int n = 0;
    LUMI_block1_cleanup:
        (void)0;
    }
    {
        Int n = 0;
    LUMI_block2_cleanup:
        (void)0;
    }
/// @ te0
expected new-line after "block", got " "
/// @ te1
"break" used not inside loop
/// @ te2
"while" used not inside loop
/// @ te3
unknown symbol "tt"
/// @ te4
using invalid reference "tt"
/// @@ test-if-else
/// @ t0
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    if (ut_M_t->num > 3) {
        ut_M_i -= 2;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t1
if (ut_M_i > 3) {
        ut_M_i -= 2;
    LUMI_block1_cleanup:
        (void)0;
    }
    else {
        ut_M_i += 1;
    LUMI_block3_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t2
if (ut_M_i > 3) {
        ut_M_i -= 3;
    LUMI_block1_cleanup:
        (void)0;
    }
    else {
        CHECK_REF_REFMAN(3, LUMI_block3_cleanup, ut_M_t, ut_M_t_Refman)
        if (ut_M_t->num > 2) {
            ut_M_i -= 2;
        LUMI_block4_cleanup:
            (void)0;
        }
        else {
            CHECK_REF_REFMAN(5, LUMI_block6_cleanup, ut_M_t, ut_M_t_Refman)
            if (ut_M_t->num > 1) {
                ut_M_i -= 1;
            LUMI_block7_cleanup:
                (void)0;
            }
            else {
                ut_M_i += 1;
            LUMI_block9_cleanup:
                (void)0;
            }
            if (LUMI_loop_depth < 1) goto LUMI_block6_cleanup;
        LUMI_block6_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 1) goto LUMI_block3_cleanup;
    LUMI_block3_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t3
if (ut_M_b) {
        LUMI_loop_depth = 0; goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    ut_M_i = 3;
/// @ t4
if (ut_M_b && ut_M_b) {
        ut_M_i += 1;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t5
if (ut_M_b) {
        char sa[4] = {0};
        int sa_Length[1] = {0};
        /* initializing sa */
        if (ut_M_b) {
            char sb[4] = {0};
            int sb_Length[1] = {0};
            /* initializing sb */
        LUMI_block2_cleanup:
            (void)0;
        }
        else {
            if (ut_M_b) {
                char sc[4] = {0};
                int sc_Length[1] = {0};
                /* initializing sc */
            LUMI_block5_cleanup:
                (void)0;
            }
            else {
                char sd[4] = {0};
                int sd_Length[1] = {0};
                /* initializing sd */
            LUMI_block7_cleanup:
                (void)0;
            }
            if (LUMI_loop_depth < 1) goto LUMI_block4_cleanup;
        LUMI_block4_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 1) goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    }
    else {
        if (ut_M_b) {
            char se[4] = {0};
            int se_Length[1] = {0};
            /* initializing se */
        LUMI_block10_cleanup:
            (void)0;
        }
        else {
            char sf[4] = {0};
            int sf_Length[1] = {0};
            /* initializing sf */
        LUMI_block12_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 1) goto LUMI_block9_cleanup;
    LUMI_block9_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
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
expected block in a new line, got "end-of-file"
/// @@ test-loop
/// @ t0
do {
        Int x = 0;
        LUMI_loop_depth = 3;
        if (!(ut_M_b)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t1
do {
        LUMI_loop_depth = 3;
        LUMI_loop_depth = 1; goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t2
do {
        LUMI_loop_depth = 3;
        CHECK_REF_REFMAN(2, LUMI_block1_cleanup, ut_M_t, ut_M_t_Refman)
        if (!(ut_M_t->num > 3)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t3
do {
        LUMI_loop_depth = 3;
        LUMI_loop_depth = 2; goto LUMI_block1_cleanup;
        if (!(ut_M_b)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t4
do {
        LUMI_loop_depth = 3;
        if (true) {
            if (!(false)) { LUMI_loop_depth = 1; goto LUMI_block2_cleanup; }
        LUMI_block2_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 3) goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t5
do {
        char sa[4] = {0};
        int sa_Length[1] = {0};
        LUMI_loop_depth = 3;
        /* initializing sa */
        if (!(ut_M_b)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        LUMI_loop_depth = 1; goto LUMI_block1_cleanup;
        LUMI_loop_depth = 2; goto LUMI_block1_cleanup;
        if (ut_M_b) {
            LUMI_loop_depth = 0; goto LUMI_block2_cleanup;
        LUMI_block2_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 3) goto LUMI_block1_cleanup;
        do {
            char sb[4] = {0};
            int sb_Length[1] = {0};
            LUMI_loop_depth = 5;
            /* initializing sb */
            if (!(ut_M_b)) { LUMI_loop_depth = 3; goto LUMI_block3_cleanup; }
            LUMI_loop_depth = 3; goto LUMI_block3_cleanup;
            LUMI_loop_depth = 4; goto LUMI_block3_cleanup;
            if (ut_M_b) {
                LUMI_loop_depth = 0; goto LUMI_block4_cleanup;
            LUMI_block4_cleanup:
                (void)0;
            }
            if (LUMI_loop_depth < 5) goto LUMI_block3_cleanup;
            do {
                char sc[4] = {0};
                int sc_Length[1] = {0};
                LUMI_loop_depth = 7;
                /* initializing sc */
                if (!(ut_M_b)) { LUMI_loop_depth = 5; goto LUMI_block5_cleanup; }
                LUMI_loop_depth = 5; goto LUMI_block5_cleanup;
                LUMI_loop_depth = 6; goto LUMI_block5_cleanup;
                if (ut_M_b) {
                    LUMI_loop_depth = 0; goto LUMI_block6_cleanup;
                LUMI_block6_cleanup:
                    (void)0;
                }
                if (LUMI_loop_depth < 7) goto LUMI_block5_cleanup;
            LUMI_block5_cleanup:
                (void)0;
            } while (LUMI_loop_depth >= 6);
            if (LUMI_loop_depth < 5) goto LUMI_block3_cleanup;
        LUMI_block3_cleanup:
            (void)0;
        } while (LUMI_loop_depth >= 4);
        if (LUMI_loop_depth < 3) goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t6
Int aux_Int_0 = 0;
    do {
        LUMI_loop_depth = 3;
        if (aux_Int_0 >= 1024) RAISE(1, LUMI_block1_cleanup, loop_limit)
        ++aux_Int_0;
        if (!(ut_M_b)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t7
{
        Int aux_Int_0 = 0;
        Int aux_Int_1 = 0;
        Int aux_Int_2 = 0;
        ++LUMI_trace_ignore_count;
        CHECK_REF(2, LUMI_block1_cleanup, ut_M_ostr)
        String_length(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(aux_Int_0));
        aux_Int_2 = aux_Int_0 + 2;
        do {
            LUMI_loop_depth = 3;
            if (aux_Int_1 >= aux_Int_2) RAISE(2, LUMI_block2_cleanup, loop_limit)
            ++aux_Int_1;
            if (!(ut_M_b)) { LUMI_loop_depth = 1; goto LUMI_block2_cleanup; }
        LUMI_block2_cleanup:
            (void)0;
        } while (LUMI_loop_depth >= 2);
        if (LUMI_loop_depth < 1) goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    }
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
    LUMI_block3_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t8
do {
        LUMI_loop_depth = 3;
        ut_M_i += 1;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t9
do {
        LUMI_loop_depth = 3;
        do {
            LUMI_loop_depth = 5;
            do {
                LUMI_loop_depth = 7;
                LUMI_loop_depth = 0; goto LUMI_block3_cleanup;
            LUMI_block3_cleanup:
                (void)0;
            } while (LUMI_loop_depth >= 6);
            if (LUMI_loop_depth < 5) goto LUMI_block2_cleanup;
        LUMI_block2_cleanup:
            (void)0;
        } while (LUMI_loop_depth >= 4);
        if (LUMI_loop_depth < 3) goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ te0
expected space after "loop", got "("
/// @ te1
"while" used not inside loop
/// @ te2
"continue" used not inside loop
/// @ te3
got "Int" expression, expected "Bool"
/// @ te4
unknown symbol "error"
/// @ te6
got void expression, expected "Bool"
/// @ te7
expected space after "while", got "new-line"
/// @ te8
expected new-line after "continue", got " "
/// @ te9
"break" used not inside loop
/// @ te10
expected new-line after "break", got " "
/// @ te11
loop is infinite
/// @ te12
loop is infinite
/// @ te13
using "!" where error is not propagated
/// @@ test-for-loop
/// @ t0
Int aux_Int_0 = 0;
    do {
        Int n = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < 5)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Int_0;
        aux_Int_0 += 1;
        ut_M_i += n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t1
Int aux_Int_0 = 0;
    Int aux_Int_1 = 0;
    Int aux_Int_2 = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    aux_Int_2 = ut_M_t->num;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_length(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(aux_Int_0));
    aux_Int_1 = aux_Int_0 + 2;
    do {
        Int n = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_2 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Int_2;
        aux_Int_2 += 1;
        ut_M_i += n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t2
char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    Int aux_Int_0 = 0;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    aux_String_0_Max_length = ut_M_ostr_Max_length;
    aux_String_0_Length = ut_M_ostr_Length;
    aux_String_0 = ut_M_ostr;
    do {
        Char ch = 0;
        Int aux_Int_1 = 0;
        LUMI_loop_depth = 3;
        String_length(aux_String_0, aux_String_0_Max_length, aux_String_0_Length, &(aux_Int_1));
        if (!(aux_Int_0 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        ch = aux_String_0[aux_Int_0];
        aux_Int_0 += 1;
        ut_M_c = ch;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t3
Int* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    Int aux_Int_0 = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    aux_Array_0_Length = ut_M_arr_Length;
    aux_Array_0 = ut_M_arr;
    do {
        Int n = 0;
        Int aux_Int_1 = 0;
        LUMI_loop_depth = 3;
        Array_length(aux_Array_0, aux_Array_0_Length, &(aux_Int_1));
        if (!(aux_Int_0 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Array_0[aux_Int_0];
        aux_Int_0 += 1;
        ut_M_i += n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t4
char* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    int aux_Array_0_Value_length = 0;
    int* aux_Array_0_String_length = NULL;
    Int aux_Int_0 = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_sarr, ut_M_sarr_Refman)
    aux_Array_0_Length = ut_M_sarr_Length;
    aux_Array_0_Value_length = ut_M_sarr_Value_length;
    aux_Array_0_String_length = ut_M_sarr_String_length;
    aux_Array_0 = ut_M_sarr;
    do {
        char* s = NULL;
        int s_Max_length = 0;
        int* s_Length = &Lumi_empty_int;
        Int aux_Int_1 = 0;
        char* aux_String_0 = NULL;
        int aux_String_0_Max_length = 0;
        int* aux_String_0_Length = &Lumi_empty_int;
        LUMI_loop_depth = 3;
        Array_length(aux_Array_0, aux_Array_0_Length, &(aux_Int_1));
        if (!(aux_Int_0 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        aux_String_0 = aux_Array_0 + aux_Int_0 * aux_Array_0_Value_length;
        aux_String_0_Max_length = aux_Array_0_Value_length;
        aux_String_0_Length = aux_Array_0_String_length + aux_Int_0;
        s_Max_length = aux_String_0_Max_length;
        s_Length = aux_String_0_Length;
        s = aux_String_0;
        aux_Int_0 += 1;
        String_clear(s, s_Max_length, s_Length);
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t5
Int n = 0;
    Int aux_Int_0 = 0;
    do {
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < 5)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Int_0;
        aux_Int_0 += 1;
        ut_M_i += n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t6
Int aux_Int_0 = 0;
    Int aux_Int_1 = 0;
    do {
        Int n = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < 5)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Int_0;
        aux_Int_0 += 1;
        ut_M_i += n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    do {
        Int n = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_1 < 7)) { LUMI_loop_depth = 1; goto LUMI_block2_cleanup; }
        n = aux_Int_1;
        aux_Int_1 += 1;
        ut_M_i += n;
    LUMI_block2_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t7
Int aux_Int_0 = 0;
    do {
        Int n = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < (1 + 2))) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Int_0;
        aux_Int_0 += 1;
        ut_M_i += n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t8
Int aux_Int_0 = 0;
    do {
        char sa[4] = {0};
        int sa_Length[1] = {0};
        Int n = 0;
        char* aux_String_0 = NULL;
        int aux_String_0_Max_length = 0;
        int* aux_String_0_Length = &Lumi_empty_int;
        Int aux_Int_1 = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < 6)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Int_0;
        aux_Int_0 += 1;
        /* initializing sa */
        LUMI_loop_depth = 1; goto LUMI_block1_cleanup;
        LUMI_loop_depth = 2; goto LUMI_block1_cleanup;
        if (ut_M_b) {
            LUMI_loop_depth = 0; goto LUMI_block2_cleanup;
        LUMI_block2_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 3) goto LUMI_block1_cleanup;
        CHECK_REF(7, LUMI_block1_cleanup, ut_M_ostr)
        aux_String_0_Max_length = ut_M_ostr_Max_length;
        aux_String_0_Length = ut_M_ostr_Length;
        aux_String_0 = ut_M_ostr;
        do {
            char sb[4] = {0};
            int sb_Length[1] = {0};
            Char ch = 0;
            Int aux_Int_2 = 0;
            LUMI_loop_depth = 5;
            String_length(aux_String_0, aux_String_0_Max_length, aux_String_0_Length, &(aux_Int_2));
            if (!(aux_Int_1 < aux_Int_2)) { LUMI_loop_depth = 3; goto LUMI_block3_cleanup; }
            ch = aux_String_0[aux_Int_1];
            aux_Int_1 += 1;
            /* initializing sb */
            LUMI_loop_depth = 3; goto LUMI_block3_cleanup;
            LUMI_loop_depth = 4; goto LUMI_block3_cleanup;
            if (ut_M_b) {
                LUMI_loop_depth = 0; goto LUMI_block4_cleanup;
            LUMI_block4_cleanup:
                (void)0;
            }
            if (LUMI_loop_depth < 5) goto LUMI_block3_cleanup;
        LUMI_block3_cleanup:
            (void)0;
        } while (LUMI_loop_depth >= 4);
        if (LUMI_loop_depth < 3) goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t9
char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int aux_String_0_Length[1] = {0};
    char* aux_String_1 = NULL;
    int aux_String_1_Max_length = 0;
    int* aux_String_1_Length = &Lumi_empty_int;
    Int aux_Int_0 = 0;
    INIT_STRING_CONST(1, LUMI_block0_cleanup, aux_String_0, "text");
    s_Max_length = aux_String_0_Max_length;
    s_Length = aux_String_0_Length;
    s = aux_String_0;
    aux_String_1_Max_length = s_Max_length;
    aux_String_1_Length = s_Length;
    aux_String_1 = s;
    do {
        Char ch = 0;
        Int aux_Int_1 = 0;
        LUMI_loop_depth = 3;
        String_length(aux_String_1, aux_String_1_Max_length, aux_String_1_Length, &(aux_Int_1));
        if (!(aux_Int_0 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        ch = aux_String_1[aux_Int_0];
        aux_Int_0 += 1;
        ut_M_c = ch;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t10
char sa[3 * 4] = {0};
    int sa_String_length[3] = {0};
    char* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    int aux_Array_0_Value_length = 0;
    int* aux_Array_0_String_length = NULL;
    Int aux_Int_0 = 0;
    /* initializing sa */
    aux_Array_0_Length = 3;
    aux_Array_0_Value_length = 4;
    aux_Array_0_String_length = sa_String_length;
    aux_Array_0 = sa;
    do {
        char* s = NULL;
        int s_Max_length = 0;
        int* s_Length = &Lumi_empty_int;
        Int aux_Int_1 = 0;
        char* aux_String_0 = NULL;
        int aux_String_0_Max_length = 0;
        int* aux_String_0_Length = &Lumi_empty_int;
        LUMI_loop_depth = 3;
        Array_length(aux_Array_0, 3, &(aux_Int_1));
        if (!(aux_Int_0 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        aux_String_0 = aux_Array_0 + aux_Int_0 * 4;
        aux_String_0_Max_length = 4;
        aux_String_0_Length = aux_Array_0_String_length + aux_Int_0;
        s_Max_length = 4;
        s_Length = aux_String_0_Length;
        s = aux_String_0;
        aux_Int_0 += 1;
        String_clear(s, 4, s_Length);
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t11
Int aux_Int_0 = 0;
    aux_Int_0 = 2;
    do {
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < 6)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        aux_Int_0 += 1;
        ut_M_i += 1;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t12
char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    Int aux_Int_0 = 0;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    aux_String_0_Max_length = ut_M_ostr_Max_length;
    aux_String_0_Length = ut_M_ostr_Length;
    aux_String_0 = ut_M_ostr;
    do {
        Int aux_Int_1 = 0;
        LUMI_loop_depth = 3;
        String_length(aux_String_0, aux_String_0_Max_length, aux_String_0_Length, &(aux_Int_1));
        if (!(aux_Int_0 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        aux_Int_0 += 1;
        ut_M_i += 1;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t13
Int aux_Int_0 = 0;
    Int aux_Int_1 = 0;
    aux_Int_0 = ut_M_i + 4;
    do {
        LUMI_loop_depth = 3;
        if (!(aux_Int_1 < aux_Int_0)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        aux_Int_1 += 1;
        ut_M_i += 1;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ te0
expected space after "for", got "("
/// @ te1
expected space after "n", got "new-line"
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
/// @ te7
using before declaration variable "n"
/// @@ test-testing
/// @ ta0
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    TEST_ASSERT(1, LUMI_block0_cleanup, ut_M_t->num == 2)
/// @ ta1
++LUMI_trace_ignore_count;
    CHECK_REF_REFMAN(1, LUMI_block1_cleanup, ut_M_t, ut_M_t_Refman)
    --LUMI_trace_ignore_count;
    TEST_FAIL(1, LUMI_block0_cleanup, 16, "error not raised")
    LUMI_block1_cleanup:
    (void)0;
    --LUMI_trace_ignore_count;
    LUMI_err = OK;
    LUMI_loop_depth = 1;
/// @ ta2
++LUMI_trace_ignore_count;
    LUMI_err = ut_M_fune();
    CHECK(1, LUMI_block1_cleanup)
    --LUMI_trace_ignore_count;
    TEST_FAIL(1, LUMI_block0_cleanup, 16, "error not raised")
    LUMI_block1_cleanup:
    (void)0;
    --LUMI_trace_ignore_count;
    LUMI_err = OK;
    LUMI_loop_depth = 1;
/// @ ta3
{char* LUMI_expected_error_prev;
    int LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error_prev = LUMI_expected_error;
    LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
    LUMI_expected_error = "expected error";
    LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
    ++LUMI_trace_ignore_count;
    CHECK_REF_REFMAN(1, LUMI_block1_cleanup, ut_M_t, ut_M_t_Refman)
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(1, LUMI_block0_cleanup, 16, "error not raised")
    LUMI_block1_cleanup:
    (void)0;
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    if (LUMI_expected_error == NULL) {
        LUMI_expected_error = LUMI_expected_error_prev;
        TEST_FAIL_NULL(1, LUMI_block0_cleanup)
    }
    LUMI_expected_error = LUMI_expected_error_prev;}
    LUMI_err = OK;
    LUMI_loop_depth = 1;
/// @ ta4
{char* LUMI_expected_error_prev;
    int LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error_prev = LUMI_expected_error;
    LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
    LUMI_expected_error = "expected error in the function";
    LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
    ++LUMI_trace_ignore_count;
    LUMI_err = ut_M_fune();
    CHECK(1, LUMI_block1_cleanup)
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(1, LUMI_block0_cleanup, 16, "error not raised")
    LUMI_block1_cleanup:
    (void)0;
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    if (LUMI_expected_error == NULL) {
        LUMI_expected_error = LUMI_expected_error_prev;
        TEST_FAIL_NULL(1, LUMI_block0_cleanup)
    }
    LUMI_expected_error = LUMI_expected_error_prev;}
    LUMI_err = OK;
    LUMI_loop_depth = 1;
/// @ ta5
{char* LUMI_expected_error_prev;
    int LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error_prev = LUMI_expected_error;
    LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
    LUMI_expected_error = "expected error in new line";
    LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
    ++LUMI_trace_ignore_count;
    CHECK_REF_REFMAN(1, LUMI_block1_cleanup, ut_M_t, ut_M_t_Refman)
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error = LUMI_expected_error_prev;
    TEST_FAIL(1, LUMI_block0_cleanup, 16, "error not raised")
    LUMI_block1_cleanup:
    (void)0;
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    if (LUMI_expected_error == NULL) {
        LUMI_expected_error = LUMI_expected_error_prev;
        TEST_FAIL_NULL(1, LUMI_block0_cleanup)
    }
    LUMI_expected_error = LUMI_expected_error_prev;}
    LUMI_err = OK;
    LUMI_loop_depth = 1;
/// @ ta6
if (ut_M_b) {
        char s[4] = {0};
        int s_Length[1] = {0};
        Char* aux_Array_0 = NULL;
        int aux_Array_0_Length = 0;
        Int aux_Int_0 = 0;
        /* initializing s */
        TEST_ASSERT(3, LUMI_block1_cleanup, ut_M_b)
        ++LUMI_trace_ignore_count;
        if (ut_M_i < 0 || ut_M_i + 2 > *(s_Length)) RAISE(4, LUMI_block2_cleanup, slice_index)
        aux_Array_0 = s + ut_M_i;
        aux_Array_0_Length = 2;
        --LUMI_trace_ignore_count;
        TEST_FAIL(4, LUMI_block1_cleanup, 16, "error not raised")
        LUMI_block2_cleanup:
        (void)0;
        --LUMI_trace_ignore_count;
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        do {
            Char* aux_Array_1 = NULL;
            int aux_Array_1_Length = 0;
            LUMI_loop_depth = 3;
            if (!(aux_Int_0 < 3)) { LUMI_loop_depth = 1; goto LUMI_block3_cleanup; }
            aux_Int_0 += 1;
            ++LUMI_trace_ignore_count;
            if (ut_M_i < 0 || ut_M_i + 2 > *(s_Length)) RAISE(6, LUMI_block4_cleanup, slice_index)
            aux_Array_1 = s + ut_M_i;
            aux_Array_1_Length = 2;
            --LUMI_trace_ignore_count;
            TEST_FAIL(6, LUMI_block3_cleanup, 16, "error not raised")
            LUMI_block4_cleanup:
            (void)0;
            --LUMI_trace_ignore_count;
            LUMI_err = OK;
            LUMI_loop_depth = 3;
        LUMI_block3_cleanup:
            (void)0;
        } while (LUMI_loop_depth >= 2);
        if (LUMI_loop_depth < 1) goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ tm0
Returncode ut_M_fun(void);
Returncode ut_M_fun_Mock(void);
Bool ut_M_fun_Mock_active = true;
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    LUMI_err = ut_M_fun_Mock();
    CHECK(2, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
Returncode ut_M_fun_Mock(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_fun_Mock_active) { return ut_M_fun(); }
    USER_RAISE(4, LUMI_block0_cleanup, NULL, 0)
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ tm1
void ut_M_fun_Mock(void);
Bool ut_M_fun_Mock_active = true;
void ut_M_fun(void);
void ut_M_fun_Mock(void) {
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_fun_Mock_active) { ut_M_fun(); return; }
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    ut_M_fun_Mock();
LUMI_block0_cleanup:
    (void)0;
}
/// @ tm2
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
void ut_M_Test_meth(ut_M_Test* self, Int x);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_Test_meth_Mock(ut_M_Test* self, Int x);
Bool ut_M_Test_meth_Mock_active = true;
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_meth(ut_M_Test* self, Int x) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test_meth_Mock(self, x);
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_Test_meth_Mock(ut_M_Test* self, Int x) {
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_Test_meth_Mock_active) { ut_M_Test_meth(self, x); return; }
LUMI_block0_cleanup:
    (void)0;
}
/// @ tm3
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    Int x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Int x);
};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Int x);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_Test_meth_Mock(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Int x);
Bool ut_M_Test_meth_Mock_active = true;
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth_Mock};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Int x) {
    unsigned LUMI_loop_depth = 1;
    self_Dynamic->meth(self, self_Dynamic, x);
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_Test_meth_Mock(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Int x) {
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_Test_meth_Mock_active) { ut_M_Test_meth(self, self_Dynamic, x); return; }
LUMI_block0_cleanup:
    (void)0;
}
/// @ tm4
void ut_M_fun(Int x, Int* y);
void ut_M_fun_Mock(Int x, Int* y);
Bool ut_M_fun_Mock_active = true;
void ut_M_fun(Int x, Int* y) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun_Mock(Int x, Int* y) {
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_fun_Mock_active) { ut_M_fun(x, &(*y)); return; }
    ut_M_fun(x, &(*y));
    ut_M_fun_Mock_active = false;
    ut_M_fun_Mock(x, &(*y));
    ut_M_fun_Mock_active = true;
LUMI_block0_cleanup:
    (void)0;
}
/// @ tm5
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
void ut_M_Test_meth(ut_M_Test* self, Int x, Int* y);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_Test_meth_Mock(ut_M_Test* self, Int x, Int* y);
Bool ut_M_Test_meth_Mock_active = true;
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_meth(ut_M_Test* self, Int x, Int* y) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test_meth_Mock(self, x, &(*y));
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_Test_meth_Mock(ut_M_Test* self, Int x, Int* y) {
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_Test_meth_Mock_active) { ut_M_Test_meth(self, x, &(*y)); return; }
    ut_M_Test_meth(self, x, &(*y));
    ut_M_Test_meth(self, x, &(*y));
    ut_M_Test_meth_Mock_active = false;
    ut_M_Test_meth_Mock(self, x, &(*y));
    ut_M_Test_meth_Mock_active = true;
LUMI_block0_cleanup:
    (void)0;
}
/// @ tm6
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    Int x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y);
};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_Test_meth_Mock(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y);
Bool ut_M_Test_meth_Mock_active = true;
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth_Mock};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y) {
    unsigned LUMI_loop_depth = 1;
    self_Dynamic->meth(self, self_Dynamic, x, &(*y));
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_Test_meth_Mock(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y) {
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_Test_meth_Mock_active) { ut_M_Test_meth(self, self_Dynamic, x, &(*y)); return; }
    ut_M_Test_meth(self, self_Dynamic, x, &(*y));
    ut_M_Test_meth_Mock_active = false;
    ut_M_Test_meth_Mock(self, self_Dynamic, x, &(*y));
    ut_M_Test_meth_Mock_active = true;
LUMI_block0_cleanup:
    (void)0;
}
/// @ tm7
Returncode ut_M_fun(void);
Returncode Sys_print_Mock(Sys* self, Char* text, int text_Length);
Bool Sys_print_Mock_active = true;
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int aux_String_0_Length[1] = {0};
    char* aux_String_1 = NULL;
    int aux_String_1_Max_length = 0;
    int aux_String_1_Length[1] = {0};
    INIT_STRING_CONST(2, LUMI_block0_cleanup, aux_String_0, "mock print");
    LUMI_err = Sys_print_Mock(sys, aux_String_0, *aux_String_0_Length);
    CHECK(2, LUMI_block0_cleanup)
    INIT_STRING_CONST(3, LUMI_block0_cleanup, aux_String_1, "really print");
    LUMI_err = Sys_print(sys, aux_String_1, *aux_String_1_Length);
    CHECK(3, LUMI_block0_cleanup)
    Sys_print_Mock_active = false;
    Sys_print_Mock_active = true;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
Returncode Sys_print_Mock(Sys* self, Char* text, int text_Length) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    if (!Sys_print_Mock_active) { return Sys_print(self, text, text_Length); }
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ tm8
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
void ut_M_Test_new(ut_M_Test* self, Int x);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_Test_new_Mock(ut_M_Test* self, Int x);
Bool ut_M_Test_new_Mock_active = true;
void ut_M_fun(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_new(ut_M_Test* self, Int x) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_Test_new_Mock(ut_M_Test* self, Int x) {
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_Test_new_Mock_active) { ut_M_Test_new(self, x); return; }
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {0};
    ut_M_Test* t = NULL;
    t = &t_Var;
    ut_M_Test_new_Mock(t, 2);
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
}
/// @ tt0
void ut_M_fun0(void);
void ut_M_fun1(void);
Returncode ut_M_fun2(void);
int LUMI_file0_line_count[30] = {
    -1,-1, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0,
     0, 0, 0, 0,-1
};
int LUMI_file1_line_count[7] = {
    -1,-1,-1, 0,-1, 0,-1
};
File_Coverage LUMI_file_coverage[2] = {
    {"mock.5.lm", 30, LUMI_file0_line_count},
    {"second.5.lm", 7, LUMI_file1_line_count}
};
void ut_M_fun0(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Int x = 0;
    Int y = 0;
    Int aux_Int_0 = 0;
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
    LUMI_block1_cleanup:
        (void)0;
    }
    else {
        ++LUMI_file_coverage[0].line_count[8];
        if (y < 0) {
            ++LUMI_file_coverage[0].line_count[9];
            y = 0;
        LUMI_block4_cleanup:
            (void)0;
        }
        else {
            ++LUMI_file_coverage[0].line_count[11];
            y += 1;
        LUMI_block6_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 1) goto LUMI_block3_cleanup;
    LUMI_block3_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    ++LUMI_file_coverage[0].line_count[12];
    {
        char* aux_String_0 = NULL;
        int aux_String_0_Max_length = 0;
        int aux_String_0_Length[1] = {0};
        ++LUMI_trace_ignore_count;
        ++LUMI_file_coverage[0].line_count[13];
        x = 0;
        ++LUMI_file_coverage[0].line_count[14];
        INIT_STRING_CONST(14, LUMI_block7_cleanup, aux_String_0, "text");
        LUMI_err = Sys_print(sys, aux_String_0, *aux_String_0_Length);
        CHECK(14, LUMI_block7_cleanup)
        ++LUMI_file_coverage[0].line_count[15];
        y = 0;
    LUMI_block7_cleanup:
        (void)0;
    }
    --LUMI_trace_ignore_count;
    ++LUMI_file_coverage[0].line_count[16];
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        ++LUMI_file_coverage[0].line_count[17];
        x = 1;
        ++LUMI_file_coverage[0].line_count[18];
        x = 2;
    LUMI_block8_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    ++LUMI_file_coverage[0].line_count[19];
    if (x > 3) {
        ++LUMI_file_coverage[0].line_count[20];
        LUMI_loop_depth = 0; goto LUMI_block9_cleanup;
    LUMI_block9_cleanup:
        (void)0;
    }
    else {
        ++LUMI_file_coverage[0].line_count[22];
        x = 3;
    LUMI_block11_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    ++LUMI_file_coverage[0].line_count[23];
    do {
        LUMI_loop_depth = 3;
        ++LUMI_file_coverage[0].line_count[24];
        if (!(x > 1)) { LUMI_loop_depth = 1; goto LUMI_block12_cleanup; }
        ++LUMI_file_coverage[0].line_count[25];
        if (x == 5) {
            ++LUMI_file_coverage[0].line_count[26];
            LUMI_loop_depth = 2; goto LUMI_block13_cleanup;
        LUMI_block13_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 3) goto LUMI_block12_cleanup;
    LUMI_block12_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    ++LUMI_file_coverage[0].line_count[27];
    do {
        Int n = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < 3)) { LUMI_loop_depth = 1; goto LUMI_block14_cleanup; }
        n = aux_Int_0;
        aux_Int_0 += 1;
        ++LUMI_file_coverage[0].line_count[28];
        x += y;
    LUMI_block14_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun1(void) {
    unsigned LUMI_loop_depth = 1;
    ++LUMI_file_coverage[1].line_count[3];
    ut_M_fun0();
LUMI_block0_cleanup:
    (void)0;
}
Returncode ut_M_fun2(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ++LUMI_file_coverage[1].line_count[5];
    ut_M_fun1();
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void new_Mock(Bool* allocate_success) { }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Bool LUMI_success = true;
    LUMI_success &= LUMI_run_test("fun2", ut_M_fun2);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 2);
    return LUMI_success? LUMI_err : FAIL;
LUMI_block0_cleanup:
    return LUMI_err;
}
TEST_MAIN_FUNC
/// @ tt1
void ut_M_fun(void);
Returncode second_M_fun0(void);
Returncode second_M_fun1(void);
int LUMI_file0_line_count[5] = {
    -1,-1, 0,-1,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.5.lm", 5, LUMI_file0_line_count}
};
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    Int x = 0;
    ++LUMI_file_coverage[0].line_count[2];
LUMI_block0_cleanup:
    (void)0;
}
Returncode second_M_fun0(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
Returncode second_M_fun1(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void new_Mock(Bool* allocate_success) { }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Bool LUMI_success = true;
    LUMI_success &= LUMI_run_test("fun0", second_M_fun0);
    LUMI_success &= LUMI_run_test("fun1", second_M_fun1);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
LUMI_block0_cleanup:
    return LUMI_err;
}
TEST_MAIN_FUNC
/// @ tmg0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    int s_Max_length;
    int* s_Length;
    Ref_Manager* s_Refman;
};
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_Test_MockDel(Ref self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    IGNORE_ERRORS( ut_M_Test_MockDel(self) )
    LUMI_dec_ref(self->s_Refman);
}
void ut_M_Test_MockDel(Ref self) {
    unsigned LUMI_loop_depth = 1;
    Ref r = NULL;
    r = self;
LUMI_block0_cleanup:
    (void)0;
}
/// @ tmg1
void delete_Mock(Ref self);
void delete_Mock(Ref self) {
    unsigned LUMI_loop_depth = 1;
    Ref r = NULL;
    r = self;
LUMI_block0_cleanup:
    (void)0;
}
void new_Mock(Bool* allocate_success) { }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
MAIN_FUNC
/// @ tmg2
void new_Mock(Bool* allocate_success);
void new_Mock(Bool* allocate_success) {
    unsigned LUMI_loop_depth = 1;
    *allocate_success = false;
LUMI_block0_cleanup:
    (void)0;
}
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
MAIN_FUNC
/// @ tr0
Ref r = NULL;
/// @ tr1
Ref r = NULL;
    r = ut_M_ostr;
/// @ tr2
Ref r = NULL;
    r = NULL;
/// @ tr3
Ref r = NULL;
    r = ut_M_ostr;
/// @ tr4
Ref r = NULL;
    TEST_ASSERT(2, LUMI_block0_cleanup, (void*)r == r)
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
unknown method "error" of type "Test"
/// @ te8
expected access "user" , got "owner"
/// @ te9
non matching types "Int" and "String"
/// @ te10
non matching subtypes "Char" and "Int"
/// @ te11
expected ! after "assert", got " "
/// @ te12
expected ! after "assert-error", got " "
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
type "Func" has no member "error"
/// @ te30
accessing mock function field in dynamic call to "meth"
/// @ te31
expected space after "test", got "new-line"
/// @ te32
constructor did not initialize field "s"
/// @ te33
no need to mark test functions with "!"
/// @ te34
no error raised in expression
/// @ te35
using "!" where error is not propagated
/// @ te36
using "!" where error is not propagated
/// @@ test-native
/// @ ti0
#include <native.h>
/// @ ti1
#include <first.h>
#include <second.h>
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ tf0
void ut_M_call(void);
void ut_M_call(void) {
    unsigned LUMI_loop_depth = 1;
    external();
LUMI_block0_cleanup:
    (void)0;
}
/// @ tf1
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    Int x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_call(void);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_call(void) {
    unsigned LUMI_loop_depth = 1;
    Int i = 0;
    char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    Int* a = NULL;
    int a_Length = 0;
    ut_M_Test* t = NULL;
    ut_M_Test_Dynamic* t_Dynamic = NULL;
    i = external(5, s, a, t);
    i = (2 * external(5, s, a, t)) + 3;
LUMI_block0_cleanup:
    (void)0;
}
/// @ tv0
void ut_M_use(void);
void ut_M_use(void) {
    unsigned LUMI_loop_depth = 1;
    x = 2;
LUMI_block0_cleanup:
    (void)0;
}
/// @ tc0
void ut_M_get(Int* x);
void ut_M_get(Int* x) {
    unsigned LUMI_loop_depth = 1;
    *x = VALUE;
LUMI_block0_cleanup:
    (void)0;
}
/// @ tt0
void ut_M_call(void);
void ut_M_call(void) {
    unsigned LUMI_loop_depth = 1;
    Native n = 0;
    n = external(n);
LUMI_block0_cleanup:
    (void)0;
}
/// @ te0
expected space after "native", got "("
/// @ te1
expected space after "native", got "new-line"
/// @ te2
unknown "native" keyword "error"
/// @ tei0
no '"' around string constant "native.h"
/// @ tef0
redefinition of function "error"
/// @ tef1
more than one output to native function
/// @ tef2
user output to native function
/// @ tef3
owner argument to native function
/// @ tef4
var output to native function
/// @ tef5
output "s" access should not be "var" for non-primitive type "String"
/// @ tef6
managed argument to native function
/// @ tef7
owner argument to native function
/// @ tef8
owner argument to native function
/// @ tef9
managed argument to native function
/// @ tef10
owner argument to native function
/// @ tef11
managed argument to native function
/// @ tef12
error raising native function
/// @ tef13
output argument in native function call
/// @ tev0
only primitive types supported for native variable, got "String"
/// @ tec0
expected new-line after "VALUE", got " "
/// @ tec1
sequence length is not constant
/// @@ test-parameter-type
/// @ t0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
Returncode ut_M_Test_set(ut_M_Test* self, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_set(ut_M_Test* self, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Generic_Type* x = NULL;
    Ref_Manager* x_Refman = NULL;
    Generic_Type_Dynamic* x_Dynamic = NULL;
    ut_M_Test* t = NULL;
    LUMI_inc_ref(item_Refman);
    LUMI_inc_ref(item_Refman);
    LUMI_dec_ref(x_Refman);
    x_Refman = item_Refman;
    x_Dynamic = item_Dynamic;
    x = item;
    LUMI_inc_ref(x_Refman);
    LUMI_dec_ref(self->item_Refman);
    self->item_Refman = x_Refman;
    self->item_Dynamic = x_Dynamic;
    self->item = x;
    INIT_NEW(6, LUMI_block0_cleanup, t, ut_M_Test, 1);
    LUMI_inc_ref(self->item_Refman);
    LUMI_dec_ref(t->item_Refman);
    t->item_Refman = self->item_Refman;
    t->item_Dynamic = self->item_Dynamic;
    t->item = self->item;
    LUMI_inc_ref(t->item_Refman);
    LUMI_dec_ref(self->item_Refman);
    self->item_Refman = t->item_Refman;
    self->item_Dynamic = t->item_Dynamic;
    self->item = t->item;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    free(t);
    LUMI_dec_ref(x_Refman);
    LUMI_dec_ref(item_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
/// @ t1
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Generic_Type* item;
    Generic_Type_Dynamic* item_Dynamic;
};
void ut_M_Test_get(ut_M_Test* self, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_get(ut_M_Test* self, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    *item_Dynamic = self->item_Dynamic;
    *item = self->item;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    if (self->item_Dynamic != NULL) self->item_Dynamic->_del(self->item);
    free(self->item);
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
void ut_M_Test_set(ut_M_Test* self, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Generic_Type* second, Ref_Manager* second_Refman, Generic_Type_Dynamic* second_Dynamic, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_use(File* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_set(ut_M_Test* self, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Generic_Type* second, Ref_Manager* second_Refman, Generic_Type_Dynamic* second_Dynamic, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(first_Refman);
    LUMI_inc_ref(second_Refman);
    LUMI_inc_ref(third_Refman);
    LUMI_inc_ref(first_Refman);
    LUMI_dec_ref(self->first_Refman);
    self->first_Refman = first_Refman;
    self->first_Dynamic = first_Dynamic;
    self->first = first;
    LUMI_inc_ref(second_Refman);
    LUMI_dec_ref(self->second_Refman);
    self->second_Refman = second_Refman;
    self->second_Dynamic = second_Dynamic;
    self->second = second;
    LUMI_inc_ref(third_Refman);
    LUMI_dec_ref(self->third_Refman);
    self->third_Refman = third_Refman;
    self->third_Dynamic = third_Dynamic;
    self->third = third;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->third_Refman);
    LUMI_dec_ref(self->second_Refman);
    LUMI_dec_ref(self->first_Refman);
}
void ut_M_use(File* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {0};
    ut_M_Test* t = NULL;
    LUMI_inc_ref(first_Refman);
    LUMI_inc_ref(second_Refman);
    LUMI_inc_ref(third_Refman);
    t = &t_Var;
    LUMI_inc_ref(first_Refman);
    LUMI_dec_ref(t->first_Refman);
    t->first_Refman = first_Refman;
    t->first_Dynamic = &File_dynamic;
    t->first = first;
    LUMI_inc_ref(second_Refman);
    LUMI_dec_ref(t->second_Refman);
    t->second_Refman = second_Refman;
    t->second_Dynamic = &Sys_dynamic;
    t->second = second;
    LUMI_inc_ref(third_Refman);
    LUMI_dec_ref(t->third_Refman);
    t->third_Refman = third_Refman;
    t->third_Dynamic = &File_dynamic;
    t->third = third;
    ut_M_Test_set(t, first, first_Refman, &File_dynamic, second, second_Refman, &Sys_dynamic, third, third_Refman, &File_dynamic);
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
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
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_d, ut_M_d_Refman)
    LUMI_inc_ref(ut_M_t_Refman);
    LUMI_dec_ref(ut_M_d->item_Refman);
    ut_M_d->item_Refman = ut_M_t_Refman;
    ut_M_d->item_Dynamic = &ut_M_Test_dynamic;
    ut_M_d->item = ut_M_t;
/// @ t5
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_d, ut_M_d_Refman)
    LUMI_inc_ref(ut_M_d->item_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = ut_M_d->item_Refman;
    ut_M_t = ut_M_d->item;
/// @ t8
ut_M_Data ad[5] = {0};
    /* initializing ad */
    LUMI_inc_ref((ad + 2)->item_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = (ad + 2)->item_Refman;
    ut_M_t = (ad + 2)->item;
/// @ t10
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_d_Refman)
    ut_M_Data_set(ut_M_d, NULL, NULL);
/// @ t11
ut_M_Data dr_Var = {0};
    ut_M_Data* dr = NULL;
    dr = &dr_Var;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, dr->item, dr->item_Refman)
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ((ut_M_Data*)(dr->item))->item, ((ut_M_Data*)(dr->item))->item_Refman)
    LUMI_inc_ref(((ut_M_Data*)(((ut_M_Data*)(dr->item))->item))->item_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = ((ut_M_Data*)(((ut_M_Data*)(dr->item))->item))->item_Refman;
    ut_M_t = ((ut_M_Data*)(((ut_M_Data*)(dr->item))->item))->item;
/// @ t12
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_d_Refman)
    LUMI_var_dec_ref(*to_Refman);
    ut_M_Data_set(ut_M_d, *to, &ut_M_Test_dynamic);
    *to = NULL;
    *to_Refman = NULL;
/// @ t13
ut_M_Test* aux_Test_0 = NULL;
    Ref_Manager* aux_Test_0_Refman = NULL;
    CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_d_Refman)
    ut_M_Data_get(ut_M_d, (void*)&(ut_M_t), &(ut_M_t_Refman), &dynamic_Void);
    CHECK_REFMAN(2, LUMI_block0_cleanup, ut_M_d_Refman)
    ut_M_Data_get(ut_M_d, (void*)&(aux_Test_0), &(aux_Test_0_Refman), &dynamic_Void);
    CHECK_REFMAN(2, LUMI_block0_cleanup, aux_Test_0_Refman)
    ut_M_Test_meth(aux_Test_0);
/// @ t14
ut_M_Data dg_Var = {0};
    ut_M_Data* dg = NULL;
    dg = &dg_Var;
/// @ t15
ut_M_Data* dg = NULL;
    CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_d_Refman)
    dg = ut_M_d;
/// @ t16
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_d_Refman)
    LUMI_var_dec_ref(*to_Refman);
    ut_M_Data_set(ut_M_d, *to, &ut_M_Test_dynamic);
    *to = NULL;
    *to_Refman = NULL;
/// @ t17
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    ut_M_Test* next;
    Ref_Manager* next_Refman;
};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test* next, Ref_Manager* next_Refman, ut_M_Test** out);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test* next, Ref_Manager* next_Refman, ut_M_Test** out) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(next_Refman);
    LUMI_inc_ref(next_Refman);
    LUMI_dec_ref(self->next_Refman);
    self->next_Refman = next_Refman;
    self->next = next;
    *out = self;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(next_Refman);
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->next_Refman);
}
/// @ t18
ut_M_Data dt_Var = {0};
    ut_M_Data* dt = NULL;
    ut_M_Tc* otc = NULL;
    ut_M_Tc_Dynamic* otc_Dynamic = NULL;
    ut_M_Tb* tb2 = NULL;
    ut_M_Tb_Dynamic* tb2_Dynamic = NULL;
    ut_M_Tb* aux_Tb_0 = NULL;
    Ref_Manager* aux_Tb_0_Refman = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = NULL;
    dt = &dt_Var;
    LUMI_inc_ref(ut_M_tc_Refman);
    LUMI_dec_ref(dt->item_Refman);
    dt->item_Refman = ut_M_tc_Refman;
    dt->item_Dynamic = (Generic_Type_Dynamic*)&(ut_M_tc_Dynamic->_base);
    dt->item = &(ut_M_tc->_base);
    LUMI_inc_ref(dt->item_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = dt->item_Refman;
    ut_M_ta_Dynamic = &(((ut_M_Tb_Dynamic*)(dt->item_Dynamic))->_base);
    ut_M_ta = &(((ut_M_Tb*)(dt->item))->_base);
    ut_M_Data_set(dt, &(otc->_base), (void*)&(otc_Dynamic->_base));
    otc = NULL;
    otc_Dynamic = NULL;
    ut_M_ta = NULL;
    ut_M_ta_Refman = NULL;
    ut_M_ta_Dynamic = NULL;
    ut_M_Data_get(dt, (void*)&(ut_M_ta), &(ut_M_ta_Refman), (void*)&(ut_M_ta_Dynamic));
    ut_M_Data_get(dt, (void*)&(aux_Tb_0), &(aux_Tb_0_Refman), (void*)&(aux_Tb_0_Dynamic));
    CHECK_REF_REFMAN(7, LUMI_block0_cleanup, aux_Tb_0, aux_Tb_0_Refman)
    ut_M_i = aux_Tb_0->_base.numa;
    ut_M_fun7(dt->item, dt->item_Refman, ((ut_M_Tb_Dynamic*)(dt->item_Dynamic)), &(dt->item), &(dt->item_Refman), &(((ut_M_Tb_Dynamic*)(dt->item_Dynamic))));
    CHECK_REFMAN(9, LUMI_block0_cleanup, dt->item_Refman)
    tb2_Dynamic = ((ut_M_Tb_Dynamic*)(dt->item_Dynamic));
    tb2 = dt->item;
    CHECK_REFMAN(10, LUMI_block0_cleanup, dt->item_Refman)
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
void ut_M_Base_get(ut_M_Base* self, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Test_set(ut_M_Test* self, File* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_fun(ut_M_Test* test, File* f, Ref_Manager* f_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_get(ut_M_Base* self, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
void ut_M_Test_set(ut_M_Test* self, File* f, Ref_Manager* f_Refman) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(f_Refman);
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(self->_base.item_Refman);
    self->_base.item_Refman = f_Refman;
    self->_base.item_Dynamic = &File_dynamic;
    self->_base.item = f;
    ut_M_Base_get(&(self->_base), (void*)&(f), &(f_Refman), &dynamic_Void);
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(f_Refman);
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_fun(ut_M_Test* test, File* f, Ref_Manager* f_Refman) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    File* aux_File_0 = NULL;
    Ref_Manager* aux_File_0_Refman = NULL;
    LUMI_inc_ref(f_Refman);
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(test->_base.item_Refman);
    test->_base.item_Refman = f_Refman;
    test->_base.item_Dynamic = &File_dynamic;
    test->_base.item = f;
    ut_M_Test_set(test, f, f_Refman);
    LUMI_inc_ref(test->_base.item_Refman);
    LUMI_dec_ref(f_Refman);
    f_Refman = test->_base.item_Refman;
    f = test->_base.item;
    ut_M_Base_get(&(test->_base), (void*)&(f), &(f_Refman), &dynamic_Void);
    ut_M_Base_get(&(test->_base), (void*)&(aux_File_0), &(aux_File_0_Refman), &dynamic_Void);
    CHECK_REF_REFMAN(13, LUMI_block0_cleanup, aux_File_0, aux_File_0_Refman)
    LUMI_err = File_putc(aux_File_0, 'a');
    CHECK(13, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(aux_File_0_Refman);
    LUMI_dec_ref(f_Refman);
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
    void (*set)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
    void (*get)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
};
struct ut_M_Test {
    ut_M_Base _base;
};
struct ut_M_Test_Dynamic {
    ut_M_Base_Dynamic _base;
};
void ut_M_Base_set(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
void ut_M_Base_get(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Test_set(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
void ut_M_Test_get(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_mock(ut_M_Test* test, Ref_Manager* test_Refman, ut_M_Test_Dynamic* test_Dynamic, File* f, Ref_Manager* f_Refman);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_set, ut_M_Base_get};
ut_M_Test_Dynamic ut_M_Test_dynamic = {{(Dynamic_Del)ut_M_Test_Del, (void (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic))ut_M_Test_set, (void (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic))ut_M_Test_get}};
void ut_M_Base_set(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(item_Refman);
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(item_Refman);
}
void ut_M_Base_get(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
void ut_M_Test_set(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(item_Refman);
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(item_Refman);
}
void ut_M_Test_get(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_mock(ut_M_Test* test, Ref_Manager* test_Refman, ut_M_Test_Dynamic* test_Dynamic, File* f, Ref_Manager* f_Refman) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    File* aux_File_0 = NULL;
    Ref_Manager* aux_File_0_Refman = NULL;
    LUMI_inc_ref(test_Refman);
    LUMI_inc_ref(f_Refman);
    CHECK_REFMAN(9, LUMI_block0_cleanup, test_Refman)
    test_Dynamic->_base.set(&(test->_base), &(test_Dynamic->_base), f, f_Refman, &File_dynamic);
    CHECK_REFMAN(10, LUMI_block0_cleanup, test_Refman)
    test_Dynamic->_base.get(&(test->_base), &(test_Dynamic->_base), (void*)&(f), &(f_Refman), &dynamic_Void);
    CHECK_REFMAN(11, LUMI_block0_cleanup, test_Refman)
    test_Dynamic->_base.get(&(test->_base), &(test_Dynamic->_base), (void*)&(aux_File_0), &(aux_File_0_Refman), &dynamic_Void);
    CHECK_REF_REFMAN(11, LUMI_block0_cleanup, aux_File_0, aux_File_0_Refman)
    LUMI_err = File_putc(aux_File_0, 'a');
    CHECK(11, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(aux_File_0_Refman);
    LUMI_dec_ref(f_Refman);
    LUMI_dec_ref(test_Refman);
    return LUMI_err;
}
/// @ t21
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
void ut_M_Test_meth(ut_M_Test* self, Generic_Type* in, Ref_Manager* in_Refman, Generic_Type_Dynamic* in_Dynamic, Generic_Type** out, Ref_Manager** out_Refman, Generic_Type_Dynamic** out_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
void ut_M_Test_meth(ut_M_Test* self, Generic_Type* in, Ref_Manager* in_Refman, Generic_Type_Dynamic* in_Dynamic, Generic_Type** out, Ref_Manager** out_Refman, Generic_Type_Dynamic** out_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    Generic_Type* p = NULL;
    Ref_Manager* p_Refman = NULL;
    Generic_Type_Dynamic* p_Dynamic = NULL;
    LUMI_inc_ref(in_Refman);
    LUMI_inc_ref(in_Refman);
    LUMI_dec_ref(p_Refman);
    p_Refman = in_Refman;
    p_Dynamic = in_Dynamic;
    p = in;
    LUMI_inc_ref(p_Refman);
    LUMI_dec_ref(*out_Refman);
    *out_Refman = p_Refman;
    *out_Dynamic = p_Dynamic;
    *out = p;
    LUMI_inc_ref(p_Refman);
    LUMI_dec_ref(self->item_Refman);
    self->item_Refman = p_Refman;
    self->item_Dynamic = p_Dynamic;
    self->item = p;
    ut_M_Test_meth(self, p, p_Refman, (void*)p_Dynamic, (void*)&(p), &(p_Refman), (void*)&(p_Dynamic));
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(p_Refman);
    LUMI_dec_ref(in_Refman);
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
cannot assign type "Data" with no parameter into same type with parameter "Test"
/// @ tec6
cannot assign "Test" into "String"
/// @ tec7
array as parameter type is unsupported
/// @ tec8
string as parameter type is unsupported
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
Returncode ut_M_Test_set(ut_M_Test* self, File* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_use(File* f, Ref_Manager* f_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_set(ut_M_Test* self, File* f, Ref_Manager* f_Refman) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Test* aux_Test_0 = NULL;
    LUMI_inc_ref(f_Refman);
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(self->_base.item_Refman);
    self->_base.item_Refman = f_Refman;
    self->_base.item_Dynamic = &File_dynamic;
    self->_base.item = f;
    INIT_NEW(6, LUMI_block0_cleanup, aux_Test_0, ut_M_Test, 1);
    LUMI_err = ut_M_Test_set(aux_Test_0, f, f_Refman);
    CHECK(6, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(aux_Test_0);
    free(aux_Test_0);
    LUMI_dec_ref(f_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
void ut_M_use(File* f, Ref_Manager* f_Refman) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {{0}};
    ut_M_Test* t = NULL;
    LUMI_inc_ref(f_Refman);
    t = &t_Var;
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(t->_base.item_Refman);
    t->_base.item_Refman = f_Refman;
    t->_base.item_Dynamic = &File_dynamic;
    t->_base.item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_dec_ref(f_Refman);
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
Returncode ut_M_Test_set(ut_M_Test* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, File* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_use(File* f, Ref_Manager* f_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_set(ut_M_Test* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, File* f, Ref_Manager* f_Refman) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Test* aux_Test_0 = NULL;
    LUMI_inc_ref(i_Refman);
    LUMI_inc_ref(f_Refman);
    LUMI_inc_ref(i_Refman);
    LUMI_dec_ref(self->_base.item_Refman);
    self->_base.item_Refman = i_Refman;
    self->_base.item_Dynamic = i_Dynamic;
    self->_base.item = i;
    INIT_NEW(6, LUMI_block0_cleanup, aux_Test_0, ut_M_Test, 1);
    LUMI_err = ut_M_Test_set(aux_Test_0, f, f_Refman, &File_dynamic, f, f_Refman);
    CHECK(6, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(aux_Test_0);
    free(aux_Test_0);
    LUMI_dec_ref(f_Refman);
    LUMI_dec_ref(i_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
void ut_M_use(File* f, Ref_Manager* f_Refman) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {{0}};
    ut_M_Test* t = NULL;
    LUMI_inc_ref(f_Refman);
    t = &t_Var;
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(t->_base.item_Refman);
    t->_base.item_Refman = f_Refman;
    t->_base.item_Dynamic = &File_dynamic;
    t->_base.item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_dec_ref(f_Refman);
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
void ut_M_Base_set(ut_M_Base* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Mid_set(ut_M_Mid* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self);
void ut_M_Top_set(ut_M_Top* self, File* f, Ref_Manager* f_Refman);
void ut_M_Top_Del(ut_M_Top* self);
Returncode ut_M_Test_set(ut_M_Test* self, File* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_use(File* f, Ref_Manager* f_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Top_dynamic = {(Dynamic_Del)ut_M_Top_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_set(ut_M_Base* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(i_Refman);
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(i_Refman);
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
void ut_M_Mid_set(ut_M_Mid* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(i_Refman);
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(i_Refman);
}
void ut_M_Mid_Del(ut_M_Mid* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
void ut_M_Top_set(ut_M_Top* self, File* f, Ref_Manager* f_Refman) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(f_Refman);
    ut_M_Mid_set(&(self->_base), f, f_Refman, &File_dynamic);
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(self->_base._base.item_Refman);
    self->_base._base.item_Refman = f_Refman;
    self->_base._base.item_Dynamic = &File_dynamic;
    self->_base._base.item = f;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(f_Refman);
}
void ut_M_Top_Del(ut_M_Top* self) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base));
}
Returncode ut_M_Test_set(ut_M_Test* self, File* f, Ref_Manager* f_Refman) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Top* aux_Top_0 = NULL;
    ut_M_Test* aux_Test_0 = NULL;
    ut_M_Top* aux_Top_1 = NULL;
    LUMI_inc_ref(f_Refman);
    ut_M_Top_set(&(self->_base), f, f_Refman);
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(self->_base._base._base.item_Refman);
    self->_base._base._base.item_Refman = f_Refman;
    self->_base._base._base.item_Dynamic = &File_dynamic;
    self->_base._base._base.item = f;
    INIT_NEW(14, LUMI_block0_cleanup, aux_Top_0, ut_M_Top, 1);
    ut_M_Top_set(aux_Top_0, f, f_Refman);
    INIT_NEW(15, LUMI_block0_cleanup, aux_Test_0, ut_M_Test, 1);
    LUMI_err = ut_M_Test_set(aux_Test_0, f, f_Refman);
    CHECK(15, LUMI_block0_cleanup)
    INIT_NEW(16, LUMI_block0_cleanup, aux_Top_1, ut_M_Top, 1);
    ut_M_Mid_set(&(aux_Top_1->_base), f, f_Refman, &File_dynamic);
LUMI_block0_cleanup:
    (void)0;
    ut_M_Top_Del(aux_Top_1);
    free(aux_Top_1);
    ut_M_Test_Del(aux_Test_0);
    free(aux_Test_0);
    ut_M_Top_Del(aux_Top_0);
    free(aux_Top_0);
    LUMI_dec_ref(f_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Top_Del(&(self->_base));
}
void ut_M_use(File* f, Ref_Manager* f_Refman) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {{{{0}}}};
    ut_M_Test* t = NULL;
    LUMI_inc_ref(f_Refman);
    t = &t_Var;
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(t->_base._base._base.item_Refman);
    t->_base._base._base.item_Refman = f_Refman;
    t->_base._base._base.item_Dynamic = &File_dynamic;
    t->_base._base._base.item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_dec_ref(f_Refman);
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
Returncode ut_M_Test_set(ut_M_Test* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, File* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_use(File* f, Ref_Manager* f_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_set(ut_M_Test* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, File* f, Ref_Manager* f_Refman) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Test* aux_Test_0 = NULL;
    LUMI_inc_ref(i_Refman);
    LUMI_inc_ref(f_Refman);
    LUMI_inc_ref(i_Refman);
    LUMI_dec_ref(self->_base.item_Refman);
    self->_base.item_Refman = i_Refman;
    self->_base.item_Dynamic = i_Dynamic;
    self->_base.item = i;
    INIT_NEW(6, LUMI_block0_cleanup, aux_Test_0, ut_M_Test, 1);
    LUMI_err = ut_M_Test_set(aux_Test_0, f, f_Refman, &File_dynamic, f, f_Refman);
    CHECK(6, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(aux_Test_0);
    free(aux_Test_0);
    LUMI_dec_ref(f_Refman);
    LUMI_dec_ref(i_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
void ut_M_use(File* f, Ref_Manager* f_Refman) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {{0}};
    ut_M_Test* t = NULL;
    LUMI_inc_ref(f_Refman);
    t = &t_Var;
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(t->_base.item_Refman);
    t->_base.item_Refman = f_Refman;
    t->_base.item_Dynamic = &File_dynamic;
    t->_base.item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_dec_ref(f_Refman);
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
void ut_M_Mid_set(ut_M_Mid* self, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self);
void ut_M_Top_set(ut_M_Top* self, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
void ut_M_Top_Del(ut_M_Top* self);
void ut_M_Test_set(ut_M_Test* self, File* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_use(File* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Top_dynamic = {(Dynamic_Del)ut_M_Top_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->second_Refman);
    LUMI_dec_ref(self->first_Refman);
}
void ut_M_Mid_set(ut_M_Mid* self, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(first_Refman);
    LUMI_inc_ref(second_Refman);
    LUMI_inc_ref(third_Refman);
    LUMI_inc_ref(first_Refman);
    LUMI_dec_ref(self->_base.first_Refman);
    self->_base.first_Refman = first_Refman;
    self->_base.first_Dynamic = first_Dynamic;
    self->_base.first = first;
    LUMI_inc_ref(second_Refman);
    LUMI_dec_ref(self->_base.second_Refman);
    self->_base.second_Refman = second_Refman;
    self->_base.second_Dynamic = &Sys_dynamic;
    self->_base.second = second;
    LUMI_inc_ref(third_Refman);
    LUMI_dec_ref(self->third_Refman);
    self->third_Refman = third_Refman;
    self->third_Dynamic = third_Dynamic;
    self->third = third;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
}
void ut_M_Mid_Del(ut_M_Mid* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
    LUMI_dec_ref(self->third_Refman);
}
void ut_M_Top_set(ut_M_Top* self, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(first_Refman);
    LUMI_inc_ref(second_Refman);
    LUMI_inc_ref(third_Refman);
    LUMI_inc_ref(first_Refman);
    LUMI_dec_ref(self->_base._base.first_Refman);
    self->_base._base.first_Refman = first_Refman;
    self->_base._base.first_Dynamic = first_Dynamic;
    self->_base._base.first = first;
    LUMI_inc_ref(second_Refman);
    LUMI_dec_ref(self->_base._base.second_Refman);
    self->_base._base.second_Refman = second_Refman;
    self->_base._base.second_Dynamic = &Sys_dynamic;
    self->_base._base.second = second;
    LUMI_inc_ref(third_Refman);
    LUMI_dec_ref(self->_base.third_Refman);
    self->_base.third_Refman = third_Refman;
    self->_base.third_Dynamic = &File_dynamic;
    self->_base.third = third;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
}
void ut_M_Top_Del(ut_M_Top* self) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base));
}
void ut_M_Test_set(ut_M_Test* self, File* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(first_Refman);
    LUMI_inc_ref(second_Refman);
    LUMI_inc_ref(third_Refman);
    LUMI_inc_ref(first_Refman);
    LUMI_dec_ref(self->_base._base._base.first_Refman);
    self->_base._base._base.first_Refman = first_Refman;
    self->_base._base._base.first_Dynamic = &File_dynamic;
    self->_base._base._base.first = first;
    LUMI_inc_ref(second_Refman);
    LUMI_dec_ref(self->_base._base._base.second_Refman);
    self->_base._base._base.second_Refman = second_Refman;
    self->_base._base._base.second_Dynamic = &Sys_dynamic;
    self->_base._base._base.second = second;
    LUMI_inc_ref(third_Refman);
    LUMI_dec_ref(self->_base._base.third_Refman);
    self->_base._base.third_Refman = third_Refman;
    self->_base._base.third_Dynamic = &File_dynamic;
    self->_base._base.third = third;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Top_Del(&(self->_base));
}
void ut_M_use(File* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {{{{0}}}};
    ut_M_Test* t = NULL;
    LUMI_inc_ref(first_Refman);
    LUMI_inc_ref(second_Refman);
    LUMI_inc_ref(third_Refman);
    t = &t_Var;
    LUMI_inc_ref(first_Refman);
    LUMI_dec_ref(t->_base._base._base.first_Refman);
    t->_base._base._base.first_Refman = first_Refman;
    t->_base._base._base.first_Dynamic = &File_dynamic;
    t->_base._base._base.first = first;
    LUMI_inc_ref(second_Refman);
    LUMI_dec_ref(t->_base._base._base.second_Refman);
    t->_base._base._base.second_Refman = second_Refman;
    t->_base._base._base.second_Dynamic = &Sys_dynamic;
    t->_base._base._base.second = second;
    LUMI_inc_ref(third_Refman);
    LUMI_dec_ref(t->_base._base.third_Refman);
    t->_base._base.third_Refman = third_Refman;
    t->_base._base.third_Dynamic = &File_dynamic;
    t->_base._base.third = third;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
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
Returncode ut_M_Test_set(ut_M_Test* self, Generic_Type* g, Ref_Manager* g_Refman, Generic_Type_Dynamic* g_Dynamic, ut_M_Second* sg, Ref_Manager* sg_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(File* f, Ref_Manager* f_Refman, ut_M_Second* ff, Ref_Manager* ff_Refman);
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
Returncode ut_M_Test_set(ut_M_Test* self, Generic_Type* g, Ref_Manager* g_Refman, Generic_Type_Dynamic* g_Dynamic, ut_M_Second* sg, Ref_Manager* sg_Refman) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(g_Refman);
    LUMI_inc_ref(sg_Refman);
    LUMI_inc_ref(sg_Refman);
    LUMI_dec_ref(self->_base.item_Refman);
    self->_base.item_Refman = sg_Refman;
    self->_base.item_Dynamic = &ut_M_Second_dynamic;
    self->_base.item = sg;
    CHECK_REF_REFMAN(8, LUMI_block0_cleanup, self->_base.item, self->_base.item_Refman)
    LUMI_inc_ref(g_Refman);
    LUMI_dec_ref(((ut_M_Second*)(self->_base.item))->item_Refman);
    ((ut_M_Second*)(self->_base.item))->item_Refman = g_Refman;
    ((ut_M_Second*)(self->_base.item))->item_Dynamic = g_Dynamic;
    ((ut_M_Second*)(self->_base.item))->item = g;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(sg_Refman);
    LUMI_dec_ref(g_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_First_Del(&(self->_base));
}
Returncode ut_M_use(File* f, Ref_Manager* f_Refman, ut_M_Second* ff, Ref_Manager* ff_Refman) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {{0}};
    ut_M_Test* t = NULL;
    LUMI_inc_ref(f_Refman);
    LUMI_inc_ref(ff_Refman);
    t = &t_Var;
    LUMI_inc_ref(ff_Refman);
    LUMI_dec_ref(t->_base.item_Refman);
    t->_base.item_Refman = ff_Refman;
    t->_base.item_Dynamic = &ut_M_Second_dynamic;
    t->_base.item = ff;
    CHECK_REF_REFMAN(12, LUMI_block0_cleanup, t->_base.item, t->_base.item_Refman)
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(((ut_M_Second*)(t->_base.item))->item_Refman);
    ((ut_M_Second*)(t->_base.item))->item_Refman = f_Refman;
    ((ut_M_Second*)(t->_base.item))->item_Dynamic = &File_dynamic;
    ((ut_M_Second*)(t->_base.item))->item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_dec_ref(ff_Refman);
    LUMI_dec_ref(f_Refman);
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
void ut_M_test(void);
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
void ut_M_test(void) {
    unsigned LUMI_loop_depth = 1;
    ut_M_BaseGen* bb = NULL;
    ut_M_BaseGen* bt = NULL;
    ut_M_TestGen* tb = NULL;
    ut_M_TestGen* tt = NULL;
    bb = &(tb->_base);
    bt = &(tt->_base);
    bb = bt;
    tb = tt;
    bb = &(tt->_base);
LUMI_block0_cleanup:
    (void)0;
}
/// @ t7
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Top ut_M_Top;
struct ut_M_Base {
    Generic_Type* first;
    Ref_Manager* first_Refman;
    Generic_Type_Dynamic* first_Dynamic;
};
struct ut_M_Mid {
    ut_M_Base _base;
    Generic_Type* second;
    Ref_Manager* second_Refman;
    Generic_Type_Dynamic* second_Dynamic;
};
struct ut_M_Top {
    ut_M_Mid _base;
};
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Mid_Del(ut_M_Mid* self);
void ut_M_Top_Del(ut_M_Top* self);
void ut_M_fun(ut_M_Top* t);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Top_dynamic = {(Dynamic_Del)ut_M_Top_Del};
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->first_Refman);
}
void ut_M_Mid_Del(ut_M_Mid* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
    LUMI_dec_ref(self->second_Refman);
}
void ut_M_Top_Del(ut_M_Top* self) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base));
}
void ut_M_fun(ut_M_Top* t) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Mid* m = NULL;
    m = &(t->_base);
LUMI_block0_cleanup:
    (void)0;
}
/// @ te0
unknown type "Generic"
/// @ te1
cannot assign "String" into "File"
/// @ te2
cannot assign "String" into "Generic Type"
/// @ te3
cannot assign "String" into "File"
/// @@ test-error-handling
/// @ t0
++LUMI_trace_ignore_count;
    CHECK_REF_REFMAN(1, LUMI_block2_cleanup, ut_M_t, ut_M_t_Refman)
    ut_M_i = ut_M_t->num;
LUMI_block2_cleanup:
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        ut_M_i = 0;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t1
++LUMI_trace_ignore_count;
    LUMI_err = ut_M_fune();
    CHECK(1, LUMI_block2_cleanup)
LUMI_block2_cleanup:
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        ut_M_i = 0;
    LUMI_block1_cleanup:
        (void)0;
    }
    else {
        *io = ut_M_i;
    LUMI_block4_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t2
++LUMI_trace_ignore_count;
    CHECK_REF_REFMAN(1, LUMI_block2_cleanup, ut_M_t, ut_M_t_Refman)
    ut_M_i = ut_M_t->num;
LUMI_block2_cleanup:
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        ut_M_i = 0;
    LUMI_block4_cleanup:
        (void)0;
    }
    else {
        *io = ut_M_i;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t3
if (ut_M_b) {
        *io = 0;
    LUMI_block1_cleanup:
        (void)0;
    }
    else {
        ++LUMI_trace_ignore_count;
        LUMI_err = ut_M_fune();
        CHECK(3, LUMI_block3_cleanup)
    LUMI_block3_cleanup:
        --LUMI_trace_ignore_count;
        if (LUMI_err != OK) {
            LUMI_err = OK;
            LUMI_loop_depth = 1;
            ut_M_i = 0;
        LUMI_block5_cleanup:
            (void)0;
        }
        else {
            *io = ut_M_i;
        LUMI_block7_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 1) goto LUMI_block4_cleanup;
    LUMI_block4_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t4
if (ut_M_b) {
        *io = 0;
    LUMI_block1_cleanup:
        (void)0;
    }
    else {
        ++LUMI_trace_ignore_count;
        CHECK_REF_REFMAN(3, LUMI_block3_cleanup, ut_M_t, ut_M_t_Refman)
        ut_M_i = ut_M_t->num;
    LUMI_block3_cleanup:
        --LUMI_trace_ignore_count;
        if (LUMI_err != OK) {
            LUMI_err = OK;
            LUMI_loop_depth = 1;
            ut_M_i = 0;
        LUMI_block7_cleanup:
            (void)0;
        }
        else {
            *io = ut_M_i;
        LUMI_block5_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 1) goto LUMI_block4_cleanup;
    LUMI_block4_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t5
void ut_M_fun(char* s, int s_Max_length, int* s_Length, Ref_Manager* s_Refman, Bool* fail);
void ut_M_fun(char* s, int s_Max_length, int* s_Length, Ref_Manager* s_Refman, Bool* fail) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(s_Refman);
    ++LUMI_trace_ignore_count;
    CHECK_REFMAN(2, LUMI_block2_cleanup, s_Refman)
    String_clear(s, s_Max_length, s_Length);
LUMI_block2_cleanup:
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        *fail = true;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(s_Refman);
}
/// @ te0
statement has no effect
/// @ te1
statement has no effect
/// @ te2
no error raised in expression
/// @ te3
"if-ok" without "else"
/// @ te4
error handling with no code
/// @ te5
error handling with no code
/// @ te6
using "!" where error is not propagated
/// @@ test-try-catch
/// @ t0
{
        ++LUMI_trace_ignore_count;
        CHECK_REF_REFMAN(2, LUMI_block1_cleanup, ut_M_t, ut_M_t_Refman)
        ut_M_t->num = 1;
        ut_M_fun0();
    LUMI_block1_cleanup:
        (void)0;
    }
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        CHECK_REF_REFMAN(5, LUMI_block2_cleanup, ut_M_t, ut_M_t_Refman)
        ut_M_i = ut_M_t->num;
        ut_M_fun4(2);
    LUMI_block2_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t1
{
        ++LUMI_trace_ignore_count;
        CHECK_REF_REFMAN(2, LUMI_block1_cleanup, ut_M_t, ut_M_t_Refman)
        ut_M_t->num = 1;
        ut_M_fun0();
    LUMI_block1_cleanup:
        (void)0;
    }
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
    LUMI_block2_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t2
{
        ++LUMI_trace_ignore_count;
        CHECK_REF_REFMAN(2, LUMI_block1_cleanup, ut_M_t, ut_M_t_Refman)
        ut_M_t->num = 1;
        {
            ++LUMI_trace_ignore_count;
            LUMI_err = ut_M_fune();
            CHECK(4, LUMI_block2_cleanup)
        LUMI_block2_cleanup:
            (void)0;
        }
        --LUMI_trace_ignore_count;
        if (LUMI_err != OK) {
            LUMI_err = OK;
            LUMI_loop_depth = 1;
            ut_M_fun4(2);
        LUMI_block3_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 1) goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    }
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        {
            ++LUMI_trace_ignore_count;
            CHECK_REF_REFMAN(9, LUMI_block5_cleanup, ut_M_arr, ut_M_arr_Refman)
            if (3 >= ut_M_arr_Length) RAISE(9, LUMI_block5_cleanup, slice_index)
            ut_M_i = ut_M_arr[3];
        LUMI_block5_cleanup:
            (void)0;
        }
        --LUMI_trace_ignore_count;
        if (LUMI_err != OK) {
            LUMI_err = OK;
            LUMI_loop_depth = 1;
            CHECK_REF_REFMAN(11, LUMI_block6_cleanup, ut_M_t, ut_M_t_Refman)
            ut_M_i = ut_M_t->num;
        LUMI_block6_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 1) goto LUMI_block4_cleanup;
    LUMI_block4_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t3
{
        char sa[4] = {0};
        int sa_Length[1] = {0};
        ++LUMI_trace_ignore_count;
        /* initializing sa */
        {
            char sb[4] = {0};
            int sb_Length[1] = {0};
            Ref_Manager* sb_Refman = NULL;
            ++LUMI_trace_ignore_count;
            INIT_VAR_REFMAN(4, LUMI_block2_cleanup, sb)
        LUMI_block2_cleanup:
            (void)0;
            LUMI_var_dec_ref(sb_Refman);
        }
        --LUMI_trace_ignore_count;
        if (LUMI_err != OK) {
            char sc[4] = {0};
            int sc_Length[1] = {0};
            Ref_Manager* sc_Refman = NULL;
            LUMI_err = OK;
            LUMI_loop_depth = 1;
            INIT_VAR_REFMAN(6, LUMI_block3_cleanup, sc)
        LUMI_block3_cleanup:
            (void)0;
            LUMI_var_dec_ref(sc_Refman);
        }
        if (LUMI_loop_depth < 1) goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    }
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        char sd[4] = {0};
        int sd_Length[1] = {0};
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        /* initializing sd */
        {
            char se[4] = {0};
            int se_Length[1] = {0};
            Ref_Manager* se_Refman = NULL;
            ++LUMI_trace_ignore_count;
            INIT_VAR_REFMAN(10, LUMI_block5_cleanup, se)
        LUMI_block5_cleanup:
            (void)0;
            LUMI_var_dec_ref(se_Refman);
        }
        --LUMI_trace_ignore_count;
        if (LUMI_err != OK) {
            char sf[4] = {0};
            int sf_Length[1] = {0};
            LUMI_err = OK;
            LUMI_loop_depth = 1;
            /* initializing sf */
        LUMI_block6_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 1) goto LUMI_block4_cleanup;
    LUMI_block4_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ t4
void ut_M_fun(char* s, int s_Max_length, int* s_Length, Ref_Manager* s_Refman);
void ut_M_fun(char* s, int s_Max_length, int* s_Length, Ref_Manager* s_Refman) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(s_Refman);
    {
        ++LUMI_trace_ignore_count;
        CHECK_REFMAN(3, LUMI_block1_cleanup, s_Refman)
        String_clear(s, s_Max_length, s_Length);
        TEST_ASSERT(4, LUMI_block1_cleanup, true)
        ++LUMI_trace_ignore_count;
        CHECK_REFMAN(5, LUMI_block2_cleanup, s_Refman)
        String_clear(s, s_Max_length, s_Length);
        --LUMI_trace_ignore_count;
        TEST_FAIL(5, LUMI_block1_cleanup, 16, "error not raised")
        LUMI_block2_cleanup:
        (void)0;
        --LUMI_trace_ignore_count;
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        USER_RAISE(6, LUMI_block1_cleanup, NULL, 0)
    LUMI_block1_cleanup:
        (void)0;
    }
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
    LUMI_block3_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(s_Refman);
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
/// @ te6
no error raised in block
/// @ te7
using "!" where error is not propagated
/// @ te8
using "!" where error is not propagated
/// @@ test-for-each
/// @ t0
typedef struct ut_M_TestIterator ut_M_TestIterator;
struct ut_M_TestIterator {
    Int counter;
};
void ut_M_TestIterator_new(ut_M_TestIterator* self, Int count);
void ut_M_TestIterator_step(ut_M_TestIterator* self, Int* num, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
Returncode ut_M_fun(Int* i);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
void ut_M_TestIterator_new(ut_M_TestIterator* self, Int count) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_TestIterator_step(ut_M_TestIterator* self, Int* num, Bool* has_data) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
    if (self == NULL) return;
}
Returncode ut_M_fun(Int* i) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    ut_M_TestIterator* aux_TestIterator_1 = NULL;
    INIT_NEW(6, LUMI_block0_cleanup, aux_TestIterator_0, ut_M_TestIterator, 1);
    ut_M_TestIterator_new(aux_TestIterator_0, 6);
    aux_TestIterator_1 = aux_TestIterator_0;
    do {
        char s[4] = {0};
        int s_Length[1] = {0};
        Int n = 0;
        Bool aux_Bool_0 = 0;
        LUMI_loop_depth = 3;
        ut_M_TestIterator_step(aux_TestIterator_1, &(n), &(aux_Bool_0));
        if (!(aux_Bool_0)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        /* initializing s */
        *i = n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    ut_M_TestIterator_Del(aux_TestIterator_0);
    free(aux_TestIterator_0);
    return LUMI_err;
}
/// @ t1
typedef struct ut_M_TestIterator ut_M_TestIterator;
struct ut_M_TestIterator {
    char* value;
    int value_Max_length;
    int* value_Length;
};
void ut_M_TestIterator_step(ut_M_TestIterator* self, char** text, int* text_Max_length, int** text_Length, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
void ut_M_fun(ut_M_TestIterator* iter);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
void ut_M_TestIterator_step(ut_M_TestIterator* self, char** text, int* text_Max_length, int** text_Length, Bool* has_data) {
    unsigned LUMI_loop_depth = 1;
    *text_Max_length = self->value_Max_length;
    *text_Length = self->value_Length;
    *text = self->value;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
    if (self == NULL) return;
    String_Del(self->value);
    free(self->value);
}
void ut_M_fun(ut_M_TestIterator* iter) {
    unsigned LUMI_loop_depth = 1;
    char* t = NULL;
    int t_Max_length = 0;
    int* t_Length = &Lumi_empty_int;
    char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    aux_TestIterator_0 = iter;
    do {
        Bool aux_Bool_0 = 0;
        LUMI_loop_depth = 3;
        ut_M_TestIterator_step(aux_TestIterator_0, &(t), &(t_Max_length), &(t_Length), &(aux_Bool_0));
        if (!(aux_Bool_0)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        s_Max_length = t_Max_length;
        s_Length = t_Length;
        s = t;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t2
typedef struct ut_M_TestIterator ut_M_TestIterator;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_TestIterator {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Test {
    Int x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*fun)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
};
Returncode ut_M_TestIterator_step(ut_M_TestIterator* self, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
void ut_M_Test_fun(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_fun(ut_M_TestIterator* fiter, ut_M_TestIterator* titer);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_fun};
Returncode ut_M_TestIterator_step(ut_M_TestIterator* self, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_data) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    CHECK_REFMAN(4, LUMI_block0_cleanup, self->item_Refman)
    *item_Dynamic = self->item_Dynamic;
    *item = self->item;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
void ut_M_Test_fun(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
Returncode ut_M_fun(ut_M_TestIterator* fiter, ut_M_TestIterator* titer) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    File* of = NULL;
    ut_M_Test* ot = NULL;
    ut_M_Test_Dynamic* ot_Dynamic = NULL;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    ut_M_TestIterator* aux_TestIterator_1 = NULL;
    aux_TestIterator_0 = fiter;
    do {
        File* f = NULL;
        Bool aux_Bool_0 = 0;
        LUMI_loop_depth = 3;
        LUMI_err = ut_M_TestIterator_step(aux_TestIterator_0, (void*)&(f), &dynamic_Void, &(aux_Bool_0));
        CHECK(11, LUMI_block1_cleanup)
        if (!(aux_Bool_0)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        of = f;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    aux_TestIterator_1 = titer;
    do {
        ut_M_Test* t = NULL;
        ut_M_Test_Dynamic* t_Dynamic = NULL;
        Bool aux_Bool_1 = 0;
        LUMI_loop_depth = 3;
        LUMI_err = ut_M_TestIterator_step(aux_TestIterator_1, (void*)&(t), (void*)&(t_Dynamic), &(aux_Bool_1));
        CHECK(13, LUMI_block2_cleanup)
        if (!(aux_Bool_1)) { LUMI_loop_depth = 1; goto LUMI_block2_cleanup; }
        ot_Dynamic = t_Dynamic;
        ot = t;
    LUMI_block2_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
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
    Returncode (*step)(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_data);
};
Returncode ut_M_TestIterator_step(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
Returncode ut_M_f_mock(ut_M_TestIterator* iter, ut_M_TestIterator_Dynamic* iter_Dynamic);
ut_M_TestIterator_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del, ut_M_TestIterator_step};
Returncode ut_M_TestIterator_step(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_data) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    CHECK_REFMAN(4, LUMI_block0_cleanup, self->item_Refman)
    *item_Dynamic = self->item_Dynamic;
    *item = self->item;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_f_mock(ut_M_TestIterator* iter, ut_M_TestIterator_Dynamic* iter_Dynamic) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    File* f = NULL;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    ut_M_TestIterator_Dynamic* aux_TestIterator_0_Dynamic = NULL;
    aux_TestIterator_0_Dynamic = iter_Dynamic;
    aux_TestIterator_0 = iter;
    do {
        File* t = NULL;
        Bool aux_Bool_0 = 0;
        LUMI_loop_depth = 3;
        LUMI_err = aux_TestIterator_0_Dynamic->step(aux_TestIterator_0, aux_TestIterator_0_Dynamic, (void*)&(t), &dynamic_Void, &(aux_Bool_0));
        CHECK(7, LUMI_block1_cleanup)
        if (!(aux_Bool_0)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        f = t;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ t4
typedef struct ut_M_TestIterator ut_M_TestIterator;
struct ut_M_TestIterator {
    char* value;
    int value_Max_length;
    int* value_Length;
};
void ut_M_TestIterator_step(ut_M_TestIterator* self, char** text, int* text_Max_length, int** text_Length, Ref_Manager** text_Refman, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
void ut_M_fun(ut_M_TestIterator* iter);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
void ut_M_TestIterator_step(ut_M_TestIterator* self, char** text, int* text_Max_length, int** text_Length, Ref_Manager** text_Refman, Bool* has_data) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    ++LUMI_trace_ignore_count;
    CHECK_REF(4, LUMI_block2_cleanup, self->value)
    INIT_NEW_STRING(4, LUMI_block2_cleanup, aux_String_0, 12);
    LUMI_err = String_copy(aux_String_0, 12, aux_String_0_Length, self->value, *self->value_Length);
    String_Del(*text);
    LUMI_owner_dec_ref(*text_Refman);
    *text_Max_length = 12;
    *text_Length = aux_String_0_Length;
    *text = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_int;
    INIT_NEW_REFMAN(4, LUMI_block2_cleanup, *text)
LUMI_block2_cleanup:
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        String_Del(*text);
        LUMI_owner_dec_ref(*text_Refman);
        *text_Refman = NULL;
        *text_Max_length = 0;
        *text_Length = &Lumi_empty_int;
        *text = NULL;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0);
    free(aux_String_0);
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
    if (self == NULL) return;
    String_Del(self->value);
    free(self->value);
}
void ut_M_fun(ut_M_TestIterator* iter) {
    unsigned LUMI_loop_depth = 1;
    char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    aux_TestIterator_0 = iter;
    do {
        char* t = NULL;
        int t_Max_length = 0;
        int* t_Length = &Lumi_empty_int;
        Ref_Manager* t_Refman = NULL;
        Bool aux_Bool_0 = 0;
        LUMI_loop_depth = 3;
        ut_M_TestIterator_step(aux_TestIterator_0, &(t), &(t_Max_length), &(t_Length), &(t_Refman), &(aux_Bool_0));
        if (!(aux_Bool_0)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        String_Del(s);
        free(s);
        LUMI_var_dec_ref(t_Refman);
        s_Max_length = t_Max_length;
        s_Length = t_Length;
        s = t;
        t = NULL;
        t_Refman = NULL;
        t_Length = &Lumi_empty_int;
    LUMI_block1_cleanup:
        (void)0;
    String_Del(t);
        LUMI_owner_dec_ref(t_Refman);
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    String_Del(s);
    free(s);
}
/// @ t5
typedef struct ut_M_TestIterator ut_M_TestIterator;
struct ut_M_TestIterator {
    char* value;
    int value_Max_length;
    int* value_Length;
};
void ut_M_TestIterator_step(ut_M_TestIterator* self, char** text, int* text_Max_length, int** text_Length, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
void ut_M_fun(ut_M_TestIterator* iter);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
void ut_M_TestIterator_step(ut_M_TestIterator* self, char** text, int* text_Max_length, int** text_Length, Bool* has_data) {
    unsigned LUMI_loop_depth = 1;
    *text_Max_length = self->value_Max_length;
    *text_Length = self->value_Length;
    *text = self->value;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
    if (self == NULL) return;
    String_Del(self->value);
    free(self->value);
}
void ut_M_fun(ut_M_TestIterator* iter) {
    unsigned LUMI_loop_depth = 1;
    Int x = 0;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    aux_TestIterator_0 = iter;
    do {
        char* aux_String_0 = NULL;
        int aux_String_0_Max_length = 0;
        int* aux_String_0_Length = &Lumi_empty_int;
        Bool aux_Bool_0 = 0;
        LUMI_loop_depth = 3;
        ut_M_TestIterator_step(aux_TestIterator_0, &(aux_String_0), &(aux_String_0_Max_length), &(aux_String_0_Length), &(aux_Bool_0));
        if (!(aux_Bool_0)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        x += 1;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
}
/// @ te0
cannot iterate type with no "step" named method - "TestIterator"
/// @ te1
iterator "step" method has parameters in type "TestIterator"
/// @ te2
iterator "step" method has no outputs in type "TestIterator"
/// @ te3
iterator "step" method has only one output in type "TestIterator"
/// @ te4
iterator "step" method has more than two outputs in type "TestIterator"
/// @ te5
iterator "step" method second output is not "Bool" in type "TestIterator"
/// @ te6
iterator "step" method self access is not "user" in type "TestIterator"
/// @ te7
ignoring iterator step function error check
/// @@ test-complex-fields
/// @ t0
typedef struct ut_M_Astruct ut_M_Astruct;
typedef struct ut_M_Astruct_Dynamic ut_M_Astruct_Dynamic;
typedef struct ut_M_Bstruct ut_M_Bstruct;
typedef struct ut_M_Bstruct_Dynamic ut_M_Bstruct_Dynamic;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Astruct {
    Int x;
};
struct ut_M_Astruct_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Astruct* self, ut_M_Astruct_Dynamic* self_Dynamic);
};
struct ut_M_Bstruct {
    ut_M_Astruct _base;
    ut_M_Bstruct* b;
    Ref_Manager* b_Refman;
    ut_M_Bstruct_Dynamic* b_Dynamic;
};
struct ut_M_Bstruct_Dynamic {
    ut_M_Astruct_Dynamic _base;
};
struct ut_M_Test {
    ut_M_Bstruct b;
    ut_M_Bstruct sb;
    Ref_Manager* sb_Refman;
};
void ut_M_Astruct_meth(ut_M_Astruct* self, ut_M_Astruct_Dynamic* self_Dynamic);
void ut_M_Astruct_Del(ut_M_Astruct* self);
void ut_M_Bstruct_meth(ut_M_Bstruct* self, ut_M_Bstruct_Dynamic* self_Dynamic);
void ut_M_Bstruct_Del(ut_M_Bstruct* self);
Returncode ut_M_Test_test(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
ut_M_Astruct_Dynamic ut_M_Astruct_dynamic = {(Dynamic_Del)ut_M_Astruct_Del, ut_M_Astruct_meth};
ut_M_Bstruct_Dynamic ut_M_Bstruct_dynamic = {{(Dynamic_Del)ut_M_Bstruct_Del, (void (*)(ut_M_Astruct* self, ut_M_Astruct_Dynamic* self_Dynamic))ut_M_Bstruct_meth}};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Astruct_meth(ut_M_Astruct* self, ut_M_Astruct_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Astruct_Del(ut_M_Astruct* self) {
    if (self == NULL) return;
}
void ut_M_Bstruct_meth(ut_M_Bstruct* self, ut_M_Bstruct_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Bstruct_Del(ut_M_Bstruct* self) {
    if (self == NULL) return;
    ut_M_Astruct_Del(&(self->_base));
    LUMI_dec_ref(self->b_Refman);
}
Returncode ut_M_Test_test(ut_M_Test* self) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Bstruct* b = NULL;
    Ref_Manager* b_Refman = NULL;
    ut_M_Bstruct_Dynamic* b_Dynamic = NULL;
    ut_M_Bstruct* b2 = NULL;
    ut_M_Bstruct_Dynamic* b2_Dynamic = NULL;
    ut_M_Test t_Var = {{{0}}};
    ut_M_Test* t = NULL;
    Ref_Manager* t_Refman = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_dec_ref(b_Refman);
    b_Refman = self_Refman;
    b_Dynamic = &ut_M_Bstruct_dynamic;
    b = &(self->sb);
    LUMI_inc_ref(self_Refman);
    LUMI_dec_ref(b_Refman);
    b_Refman = self_Refman;
    b_Dynamic = &ut_M_Bstruct_dynamic;
    b = &(self->sb);
    ut_M_Bstruct_meth(&(self->b), &ut_M_Bstruct_dynamic);
    ut_M_Bstruct_meth(&(self->b), &ut_M_Bstruct_dynamic);
    CHECK_REFMAN(9, LUMI_block0_cleanup, self->b.b_Refman)
    b2_Dynamic = self->b.b_Dynamic;
    b2 = self->b.b;
    CHECK_REFMAN(10, LUMI_block0_cleanup, self->b.b_Refman)
    b2_Dynamic = self->b.b_Dynamic;
    b2 = self->b.b;
    CHECK_REFMAN(11, LUMI_block0_cleanup, self->b.b_Refman)
    if (self->b.b_Dynamic == NULL) RAISE(11, LUMI_block0_cleanup, empty_object)
    self->b.b_Dynamic->_base.meth(&(self->b.b->_base), &(self->b.b_Dynamic->_base));
    LUMI_inc_ref(b_Refman);
    LUMI_dec_ref(self->b.b_Refman);
    self->b.b_Refman = b_Refman;
    self->b.b_Dynamic = b_Dynamic;
    self->b.b = b;
    CHECK_REFMAN(13, LUMI_block0_cleanup, self->b.b_Refman)
    ut_M_Bstruct_meth(self->b.b, self->b.b_Dynamic);
    t = &t_Var;
    INIT_VAR_REFMAN(14, LUMI_block0_cleanup, t)
    self->b._base.x = 5;
    ut_M_Astruct_meth(&(self->b._base), &(ut_M_Bstruct_dynamic._base));
    if (((void*)&(self->b) == b) || ((void*)b2 != &(self->b))) {
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    LUMI_inc_ref(t_Refman);
    LUMI_dec_ref(b_Refman);
    b_Refman = t_Refman;
    b_Dynamic = &ut_M_Bstruct_dynamic;
    b = &(t->b);
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_var_dec_ref(t_Refman);
    LUMI_dec_ref(b_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Bstruct_Del(&(self->sb));
    LUMI_var_dec_ref(self->sb_Refman);
    ut_M_Bstruct_Del(&(self->b));
}
/// @ t1
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Base {
    Int x;
};
struct ut_M_Test {
    char s[10];
    int s_Length[1];
    Int ai[11];
    ut_M_Base ab[12];
    char as[7 * 8];
    int as_String_length[7];
    Int aai[4 * 5 * 6];
    ut_M_Base aab[4 * 5 * 6];
    char aas[4 * 5 * 6];
    int aas_String_length[4 * 5];
};
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Test_test(ut_M_Test* self, Char* c, Int* i, ut_M_Base** b);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
}
Returncode ut_M_Test_test(ut_M_Test* self, Char* c, Int* i, ut_M_Base** b) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    Int* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    int aux_Array_0_Value_length = 0;
    Int* aux_Array_1 = NULL;
    int aux_Array_1_Length = 0;
    ut_M_Base* aux_Array_2 = NULL;
    int aux_Array_2_Length = 0;
    int aux_Array_2_Value_length = 0;
    ut_M_Base* aux_Array_3 = NULL;
    int aux_Array_3_Length = 0;
    char* aux_Array_4 = NULL;
    int aux_Array_4_Length = 0;
    int aux_Array_4_Value_length = 0;
    int* aux_Array_4_String_length = NULL;
    char* aux_String_1 = NULL;
    int aux_String_1_Max_length = 0;
    int* aux_String_1_Length = &Lumi_empty_int;
    if (3 >= *(self->s_Length)) RAISE(12, LUMI_block0_cleanup, slice_index)
    *c = self->s[3];
    *i = self->ai[4];
    *b = self->ab + 5;
    aux_String_0 = self->as + 4 * 8;
    aux_String_0_Max_length = 8;
    aux_String_0_Length = self->as_String_length + 4;
    if (5 >= *(aux_String_0_Length)) RAISE(15, LUMI_block0_cleanup, slice_index)
    *c = (aux_String_0)[5];
    aux_Array_0 = self->aai + 1 * 5 * 6;
    aux_Array_0_Length = 5;
    aux_Array_0_Value_length = 6;
    aux_Array_1 = (aux_Array_0) + 2 * 6;
    aux_Array_1_Length = 6;
    *i = (aux_Array_1)[3];
    aux_Array_2 = self->aab + 1 * 5 * 6;
    aux_Array_2_Length = 5;
    aux_Array_2_Value_length = 6;
    aux_Array_3 = (aux_Array_2) + 2 * 6;
    aux_Array_3_Length = 6;
    *b = (aux_Array_3) + 3;
    aux_Array_4 = self->aas + 1 * 5 * 6;
    aux_Array_4_Length = 5;
    aux_Array_4_Value_length = 6;
    aux_Array_4_String_length = self->aas_String_length + 1 * 5;
    aux_String_1 = (aux_Array_4) + 2 * 6;
    aux_String_1_Max_length = 6;
    aux_String_1_Length = aux_Array_4_String_length + 2;
    if (3 >= *(aux_String_1_Length)) RAISE(18, LUMI_block0_cleanup, slice_index)
    *c = (aux_String_1)[3];
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ARRAY_DEL(ut_M_Base, self->aab, 4 * 5 * 6)
    ARRAY_DEL(ut_M_Base, self->ab, 12)
}
/// @ te0
sequence length is not constant
/// @ te1
sequence length is not constant
/// @ te2
recursive declaration of type "Test", variable of type "Test"
/// @ te3
recursive declaration of type "Test", variable of type "Base", variable of type "Test"
/// @ te4
recursive declaration of type "Abase", extended by type "Aerror", variable of type "Bbase", extended by type "Berror", variable of type "Abase"
/// @ te5
assigning into non assignable expression
/// @ te6
cannot use "?" on non conditional or weak reference of type "Base"
/// @@ test-enum
/// @ t0
enum {
    ut_M_MyEnum_VALUE = 0,
    ut_M_MyEnum_ANOTHER_VALUE,
    ut_M_MyEnum_LAST_VALUE,
    ut_M_MyEnum_length
};
void ut_M_dummy(void);
void ut_M_dummy(void) {
    unsigned LUMI_loop_depth = 1;
    Int x = 0;
    x = ut_M_MyEnum_VALUE;
    x += ut_M_MyEnum_ANOTHER_VALUE;
    x -= ut_M_MyEnum_length;
LUMI_block0_cleanup:
    (void)0;
}
/// @ t1
enum {
    ut_M_MyEnum_VALUE = 0,
    ut_M_MyEnum_ANOTHER_VALUE,
    ut_M_MyEnum_LAST_VALUE,
    ut_M_MyEnum_length
};
Int ut_M_arr[ut_M_MyEnum_length] = {0};
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
expected new-line after "VALUE", got "("
/// @ te8
Enum with no values
/// @ te9
indentation too long, expected 4 got 8
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
void ut_M_fun(Int* a, int a_Length);
Int ut_M_arr[ut_M_SIZE + 3] = {0};
void ut_M_fun(Int* a, int a_Length) {
    unsigned LUMI_loop_depth = 1;
    ut_M_fun(ut_M_arr, 15);
LUMI_block0_cleanup:
    (void)0;
}
/// @ t2
enum { ut_M_SMALL = 7 };
enum { ut_M_LARGE = 15 };
/// @ t3
enum {
    ut_M_MyEnum_VALUE = 0,
    ut_M_MyEnum_length
};
enum { ut_M_NUMBER = 0 };
/// @ t4
enum { ut_M_NUMBER = 2 };
enum { ut_M_D_CHAR = 100 };
/// @ te0
expected space after "const", got "new-line"
/// @ te1
Only "Int" typed constant supported, got "Bool"
/// @ te2
expected space after "Int", got "new-line"
/// @ te3
illegal constant name "Error"
/// @ te4
expected space after "ERROR", got "new-line"
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
void ut_M_Test_meth(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
void second_M_Test_meth(second_M_Test* self);
void second_M_Test_Del(second_M_Test* self);
Returncode ut_M_fun(void);
Returncode second_M_fun(void);
Returncode second_M_dummy(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Generic_Type_Dynamic second_M_Test_dynamic = {(Dynamic_Del)second_M_Test_Del};
ut_M_Test ut_M_t_Var = {0};
ut_M_Test* ut_M_t = NULL;
second_M_Test second_M_t_Var = {{0}};
second_M_Test* second_M_t = NULL;
int LUMI_file0_line_count[17] = {
    -1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.5.lm", 17, LUMI_file0_line_count}
};
void ut_M_Test_meth(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void second_M_Test_meth(second_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void second_M_Test_Del(second_M_Test* self) {
    if (self == NULL) return;
    ut_M_Test_Del(&(self->_base));
}
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    second_M_Test* nt = NULL;
    ++LUMI_file_coverage[0].line_count[9];
    ut_M_t->x = ut_M_Enum_VALUE + ut_M_SIZE;
    ++LUMI_file_coverage[0].line_count[10];
    LUMI_err = ut_M_fun();
    CHECK(10, LUMI_block0_cleanup)
    ++LUMI_file_coverage[0].line_count[11];
    ut_M_Test_meth(ut_M_t);
    ++LUMI_file_coverage[0].line_count[12];
    second_M_t->_base.x = second_M_Enum_VALUE + second_M_SIZE;
    ++LUMI_file_coverage[0].line_count[13];
    LUMI_err = second_M_fun();
    CHECK(13, LUMI_block0_cleanup)
    ++LUMI_file_coverage[0].line_count[14];
    second_M_Test_meth(second_M_t);
    ++LUMI_file_coverage[0].line_count[15];
    INIT_NEW(15, LUMI_block0_cleanup, nt, second_M_Test, 1);
LUMI_block0_cleanup:
    (void)0;
    second_M_Test_Del(nt);
    free(nt);
    return LUMI_err;
}
Returncode second_M_fun(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Test* nt = NULL;
    second_M_t->_base.x = second_M_Enum_VALUE + second_M_SIZE;
    LUMI_err = second_M_fun();
    CHECK(10, LUMI_block0_cleanup)
    second_M_Test_meth(second_M_t);
    ut_M_t->x = ut_M_Enum_VALUE + ut_M_SIZE;
    LUMI_err = ut_M_fun();
    CHECK(13, LUMI_block0_cleanup)
    ut_M_Test_meth(ut_M_t);
    INIT_NEW(15, LUMI_block0_cleanup, nt, ut_M_Test, 1);
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(nt);
    free(nt);
    return LUMI_err;
}
Returncode second_M_dummy(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void new_Mock(Bool* allocate_success) { }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Bool LUMI_success = true;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "mock.5.lm"
    ut_M_t = &ut_M_t_Var;
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "second.5.lm"
    second_M_t = &second_M_t_Var;
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
    LUMI_success &= LUMI_run_test("dummy", second_M_dummy);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
LUMI_block0_cleanup:
    return LUMI_err;
}
TEST_MAIN_FUNC
/// @ t1
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
void ut_M_Test_meth(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(void);
void ut_M_fun_Mock(void);
Bool ut_M_fun_Mock_active = true;
void ut_M_Test_meth_Mock(ut_M_Test* self);
Bool ut_M_Test_meth_Mock_active = true;
Returncode second_M_dummy(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
int LUMI_file0_line_count[8] = {
    -1,-1,-1,-1,-1, 0, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.5.lm", 8, LUMI_file0_line_count}
};
void ut_M_Test_meth(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    ++LUMI_file_coverage[0].line_count[5];
    ut_M_fun_Mock();
    ++LUMI_file_coverage[0].line_count[6];
    ut_M_Test_meth_Mock(self);
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun_Mock(void) {
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_fun_Mock_active) { ut_M_fun(); return; }
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_meth_Mock(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_Test_meth_Mock_active) { ut_M_Test_meth(self); return; }
LUMI_block0_cleanup:
    (void)0;
}
Returncode second_M_dummy(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void new_Mock(Bool* allocate_success) { }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Bool LUMI_success = true;
    LUMI_success &= LUMI_run_test("dummy", second_M_dummy);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
LUMI_block0_cleanup:
    return LUMI_err;
}
TEST_MAIN_FUNC
/// @ t2
void ut_M_fun(void);
Returncode second_M_use(void);
int LUMI_file0_line_count[7] = {
    -1,-1,-1,-1,-1, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.5.lm", 7, LUMI_file0_line_count}
};
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    ++LUMI_file_coverage[0].line_count[5];
    x = 0;
LUMI_block0_cleanup:
    (void)0;
}
Returncode second_M_use(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Native n = 0;
    x = 2;
    external();
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void new_Mock(Bool* allocate_success) { }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Bool LUMI_success = true;
    LUMI_success &= LUMI_run_test("use", second_M_use);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
LUMI_block0_cleanup:
    return LUMI_err;
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
/// @@ test-memory
/// @ to0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    int s_Max_length;
    int* s_Length;
    char* str;
    int str_Max_length;
    int* str_Length;
};
Returncode ut_M_Test_new(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_use(char* s, int s_Max_length, int* s_Length);
void ut_M_take(char* s, int s_Max_length, int* s_Length);
void ut_M_give(char** s, int* s_Max_length, int** s_Length);
Returncode ut_M_fun(char* s, int s_Max_length, int* s_Length, ut_M_Test* tu, ut_M_Test* to);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_new(ut_M_Test* self) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    INIT_NEW_STRING(5, LUMI_block0_cleanup, aux_String_0, 12);
    String_Del(self->str);
    free(self->str);
    self->str_Max_length = 12;
    self->str_Length = aux_String_0_Length;
    self->str = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_int;
    String_clear(self->str, self->str_Max_length, self->str_Length);
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0);
    free(aux_String_0);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    String_Del(self->str);
    free(self->str);
    String_Del(self->s);
    free(self->s);
}
void ut_M_use(char* s, int s_Max_length, int* s_Length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_take(char* s, int s_Max_length, int* s_Length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    String_Del(s);
    free(s);
}
void ut_M_give(char** s, int* s_Max_length, int** s_Length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
Returncode ut_M_fun(char* s, int s_Max_length, int* s_Length, ut_M_Test* tu, ut_M_Test* to) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* su = NULL;
    int su_Max_length = 0;
    int* su_Length = &Lumi_empty_int;
    Int arr[12] = {0};
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    char* aux_String_1 = NULL;
    int aux_String_1_Max_length = 0;
    int* aux_String_1_Length = &Lumi_empty_int;
    String_Del(s);
    free(s);
    s_Max_length = 0;
    s_Length = &Lumi_empty_int;
    s = NULL;
    INIT_NEW_STRING(12, LUMI_block0_cleanup, aux_String_0, 12);
    String_Del(s);
    free(s);
    s_Max_length = 12;
    s_Length = aux_String_0_Length;
    s = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_int;
    CHECK_REF(13, LUMI_block0_cleanup, s)
    String_clear(s, s_Max_length, s_Length);
    INIT_NEW_STRING(14, LUMI_block0_cleanup, aux_String_1, 12);
    String_Del(to->s);
    free(to->s);
    to->s_Max_length = 12;
    to->s_Length = aux_String_1_Length;
    to->s = aux_String_1;
    aux_String_1 = NULL;
    aux_String_1_Length = &Lumi_empty_int;
    su_Max_length = tu->s_Max_length;
    su_Length = tu->s_Length;
    su = tu->s;
    ut_M_use(tu->s, tu->s_Max_length, tu->s_Length);
    ut_M_take(to->s, to->s_Max_length, to->s_Length);
    to->s = NULL;
    to->s_Length = &Lumi_empty_int;
    /* initializing arr */
    arr[4] = arr[8];
    do {
        LUMI_loop_depth = 3;
        ut_M_give(&(s), &(s_Max_length), &(s_Length));
        if (!(s != NULL)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_1);
    free(aux_String_1);
    String_Del(aux_String_0);
    free(aux_String_0);
    ut_M_Test_Del(to);
    free(to);
    String_Del(s);
    free(s);
    return LUMI_err;
}
/// @ tu0
void ut_M_deleting(char** s, int* s_Max_length, int** s_Length);
void ut_M_fun(char* s, int s_Max_length, int* s_Length, char** so, int* so_Max_length, int** so_Length);
void ut_M_deleting(char** s, int* s_Max_length, int** s_Length) {
    unsigned LUMI_loop_depth = 1;
    String_Del(*s);
    free(*s);
    *s_Max_length = 0;
    *s_Length = &Lumi_empty_int;
    *s = NULL;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun(char* s, int s_Max_length, int* s_Length, char** so, int* so_Max_length, int** so_Length) {
    unsigned LUMI_loop_depth = 1;
    String_clear(s, s_Max_length, s_Length);
    ut_M_deleting(&(*so), &(*so_Max_length), &(*so_Length));
LUMI_block0_cleanup:
    (void)0;
}
/// @ tu1
void ut_M_deleting(char** s, int* s_Max_length, int** s_Length, Ref_Manager** s_Refman);
Returncode ut_M_fun(void);
void ut_M_deleting(char** s, int* s_Max_length, int** s_Length, Ref_Manager** s_Refman) {
    unsigned LUMI_loop_depth = 1;
    String_Del(*s);
    LUMI_owner_dec_ref(*s_Refman);
    *s_Refman = NULL;
    *s_Max_length = 0;
    *s_Length = &Lumi_empty_int;
    *s = NULL;
LUMI_block0_cleanup:
    (void)0;
}
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* so = NULL;
    int so_Max_length = 0;
    int* so_Length = &Lumi_empty_int;
    Ref_Manager* so_Refman = NULL;
    char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    INIT_NEW_STRING(4, LUMI_block0_cleanup, aux_String_0, 12);
    so_Max_length = 12;
    so_Length = aux_String_0_Length;
    so = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_int;
    INIT_NEW_REFMAN(4, LUMI_block0_cleanup, so)
    s_Max_length = so_Max_length;
    s_Length = so_Length;
    s = so;
    CHECK_REF(6, LUMI_block0_cleanup, s)
    String_clear(s, s_Max_length, s_Length);
    ut_M_deleting(&(so), &(so_Max_length), &(so_Length), &(so_Refman));
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0);
    free(aux_String_0);
    String_Del(so);
    LUMI_owner_dec_ref(so_Refman);
    return LUMI_err;
}
/// @ tu2
void ut_M_deleting(char** s, int* s_Max_length, int** s_Length, Ref_Manager** s_Refman);
Returncode ut_M_fun(void);
void ut_M_deleting(char** s, int* s_Max_length, int** s_Length, Ref_Manager** s_Refman) {
    unsigned LUMI_loop_depth = 1;
    String_Del(*s);
    LUMI_owner_dec_ref(*s_Refman);
    *s_Refman = NULL;
    *s_Max_length = 0;
    *s_Length = &Lumi_empty_int;
    *s = NULL;
LUMI_block0_cleanup:
    (void)0;
}
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* so = NULL;
    int so_Max_length = 0;
    int* so_Length = &Lumi_empty_int;
    Ref_Manager* so_Refman = NULL;
    char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    Ref_Manager* s_Refman = NULL;
    char* aux_String_0 = NULL;
    int aux_String_0_Max_length = 0;
    int* aux_String_0_Length = &Lumi_empty_int;
    INIT_NEW_STRING(4, LUMI_block0_cleanup, aux_String_0, 12);
    so_Max_length = 12;
    so_Length = aux_String_0_Length;
    so = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_int;
    INIT_NEW_REFMAN(4, LUMI_block0_cleanup, so)
    LUMI_inc_ref(so_Refman);
    LUMI_dec_ref(s_Refman);
    s_Refman = so_Refman;
    s_Max_length = so_Max_length;
    s_Length = so_Length;
    s = so;
    ut_M_deleting(&(so), &(so_Max_length), &(so_Length), &(so_Refman));
    CHECK_REF_REFMAN(7, LUMI_block0_cleanup, s, s_Refman)
    String_clear(s, s_Max_length, s_Length);
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0);
    free(aux_String_0);
    LUMI_dec_ref(s_Refman);
    String_Del(so);
    LUMI_owner_dec_ref(so_Refman);
    return LUMI_err;
}
/// @ tu3
char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    String_Del(*so);
    LUMI_owner_dec_ref(*so_Refman);
    *so_Refman = NULL;
    *so_Max_length = 0;
    *so_Length = &Lumi_empty_int;
    *so = NULL;
    s_Max_length = *so_Max_length;
    s_Length = *so_Length;
    s = *so;
    CHECK_REF(4, LUMI_block0_cleanup, s)
    String_clear(s, s_Max_length, s_Length);
/// @ tu4
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    int s_Max_length;
    int* s_Length;
    Ref_Manager* s_Refman;
};
Returncode ut_M_Test_get(ut_M_Test* self, char** s, int* s_Max_length, int** s_Length);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_fun(ut_M_Test* t, char** s, int* s_Max_length, int** s_Length);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->s_Refman);
}
Returncode ut_M_Test_get(ut_M_Test* self, char** s, int* s_Max_length, int** s_Length) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    CHECK_REFMAN(5, LUMI_block0_cleanup, self->s_Refman)
    *s_Max_length = self->s_Max_length;
    *s_Length = self->s_Length;
    *s = self->s;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
Returncode ut_M_fun(ut_M_Test* t, char** s, int* s_Max_length, int** s_Length) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    LUMI_err = ut_M_Test_get(t, &(*s), &(*s_Max_length), &(*s_Length));
    CHECK(7, LUMI_block0_cleanup)
    CHECK_REF(8, LUMI_block0_cleanup, *s)
    String_clear(*s, *s_Max_length, *s_Length);
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ tu5
char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    char* aux_Array_0 = NULL;
    int aux_Array_0_Length = 0;
    int aux_Array_0_Value_length = 0;
    int* aux_Array_0_String_length = NULL;
    Int aux_Int_0 = 0;
    s_Max_length = ut_M_ostr_Max_length;
    s_Length = ut_M_ostr_Length;
    s = ut_M_ostr;
    String_Del(ut_M_ostr);
    free(ut_M_ostr);
    ut_M_ostr_Max_length = 0;
    ut_M_ostr_Length = &Lumi_empty_int;
    ut_M_ostr = NULL;
    CHECK_REF_REFMAN(3, LUMI_block0_cleanup, ut_M_sarr, ut_M_sarr_Refman)
    aux_Array_0_Length = ut_M_sarr_Length;
    aux_Array_0_Value_length = ut_M_sarr_Value_length;
    aux_Array_0_String_length = ut_M_sarr_String_length;
    aux_Array_0 = ut_M_sarr;
    do {
        Int aux_Int_1 = 0;
        char* aux_String_0 = NULL;
        int aux_String_0_Max_length = 0;
        int* aux_String_0_Length = &Lumi_empty_int;
        LUMI_loop_depth = 3;
        Array_length(aux_Array_0, aux_Array_0_Length, &(aux_Int_1));
        if (!(aux_Int_0 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        aux_String_0 = aux_Array_0 + aux_Int_0 * aux_Array_0_Value_length;
        aux_String_0_Max_length = aux_Array_0_Value_length;
        aux_String_0_Length = aux_Array_0_String_length + aux_Int_0;
        s_Max_length = aux_String_0_Max_length;
        s_Length = aux_String_0_Length;
        s = aux_String_0;
        aux_Int_0 += 1;
        CHECK_REF(4, LUMI_block1_cleanup, s)
        String_clear(s, s_Max_length, s_Length);
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ tu6
void ut_M_get(char** s, int* s_Max_length, int** s_Length);
Returncode ut_M_fun(void);
void ut_M_get(char** s, int* s_Max_length, int** s_Length) {
    unsigned LUMI_loop_depth = 1;
    *s_Max_length = 0;
    *s_Length = &Lumi_empty_int;
    *s = NULL;
LUMI_block0_cleanup:
    (void)0;
}
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    do {
        char* s = NULL;
        int s_Max_length = 0;
        int* s_Length = &Lumi_empty_int;
        LUMI_loop_depth = 3;
        ut_M_get(&(s), &(s_Max_length), &(s_Length));
        if (!(s != NULL)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        CHECK_REF(7, LUMI_block1_cleanup, s)
        String_clear(s, s_Max_length, s_Length);
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ tb0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    int s_Max_length;
    int* s_Length;
};
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(ut_M_Test* t);
void ut_M_use(ut_M_Test* to);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    String_Del(self->s);
    free(self->s);
}
void ut_M_fun(ut_M_Test* t) {
    unsigned LUMI_loop_depth = 1;
    String_Del(t->s);
    free(t->s);
    t->s_Max_length = 0;
    t->s_Length = &Lumi_empty_int;
    t->s = NULL;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_use(ut_M_Test* to) {
    unsigned LUMI_loop_depth = 1;
    ut_M_fun(to);
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(to);
    free(to);
}
/// @ tb1
char* s = NULL;
    int s_Max_length = 0;
    int* s_Length = &Lumi_empty_int;
    Ref_Manager* s_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, *so)
    LUMI_inc_ref(*so_Refman);
    LUMI_dec_ref(s_Refman);
    s_Refman = *so_Refman;
    s_Max_length = *so_Max_length;
    s_Length = *so_Length;
    s = *so;
    CHECK_REFMAN(3, LUMI_block0_cleanup, s_Refman)
    String_clear(s, s_Max_length, s_Length);
/// @ teo0
cannot modify owner field "s" in non-owner reference "t.s"
/// @ teo1
cannot modify owner field "a" in non-owner reference "b.a"
/// @ teo2
cannot modify owner field "a" in non-owner reference "b.a"
/// @ teo3
cannot modify owner field "s" in non-owner reference "b.a.s"
/// @ teo4
cannot modify owner field "s" in non-owner reference "t.s"
/// @ teo5
cannot modify owner field "s" in non-owner reference "{anonymous}.s"
/// @ teo6
cannot move non-conditional owner field "t.s"
/// @ teo7
cannot move non-conditional owner field "t.s"
/// @ teo8
cannot move non-conditional owner field "t.s"
/// @ teo9
using invalid reference "s"
/// @ teo10
using modified reference "t"
/// @ teo11
using modified reference "t"
/// @ teo12
using invalid reference "t"
/// @ teo13
using invalid reference "t.t"
/// @ teo14
cannot modify owner field "s" in non-owner reference "tu.s"
/// @ teo15
using invalid reference "s"
/// @ teo16
using invalid reference "tbad"
/// @ teo17
using invalid reference "s"
/// @ teo18
using modified reference "s"
/// @ teo19
using modified reference "s"
/// @ teo20
using modified reference "s"
/// @ teo21
using invalid reference "t"
/// @ teo22
using modified reference "t"
/// @ teo23
using invalid reference "s"
/// @ teo24
using potentially illegal user reference "{anonymous}"
/// @ teo25
using invalid reference "s"
/// @ teu0
using potentially illegal user reference "s"
/// @ teu1
using potentially illegal user reference "s"
/// @ teu2
using potentially illegal user reference "s"
/// @ teu3
using potentially illegal user reference "s"
/// @ teu4
using potentially illegal user reference "s"
/// @ teu5
using potentially illegal user reference "s"
/// @ teu6
using potentially illegal user reference "s"
/// @ teu7
using potentially illegal user reference "s"
/// @ teu8
using potentially illegal user reference "s"
/// @ teu9
using potentially illegal user reference "s"
/// @ teu10
using potentially illegal user reference "s"
/// @ teu11
using potentially illegal user reference "s"
/// @ teu12
using potentially illegal user reference "s"
/// @ teu13
using potentially illegal user reference "a"
/// @ teu14
using potentially illegal user reference "s"
/// @ teu15
using potentially illegal user reference "s"
/// @ teu16
using potentially illegal user reference "tt"
/// @ teu17
using potentially illegal user reference "f"
/// @ teu18
using potentially illegal user reference "t"
/// @ teu19
using potentially illegal user reference "b"
/// @ teu20
using potentially illegal user reference "s"
/// @ teu21
using potentially illegal user reference "s"
/// @ teu22
using potentially illegal user reference "s"
/// @ teu23
using potentially illegal user reference "s"
/// @ teu24
using potentially illegal user reference "s"
/// @ teu25
returning potentially illegal user output "s"
/// @ teu26
returning potentially illegal user output "s"
/// @ teu27
returning potentially illegal user output "s"
/// @ teu28
returning potentially illegal user output "s"
/// @ teu29
using potentially illegal user reference "s"
/// @ teu30
using potentially illegal user reference "s"
/// @ teu31
using potentially illegal user reference "s"
/// @ teu32
using potentially illegal user reference "s"
/// @ teu33
using potentially illegal user reference "f"
/// @ teu34
using potentially illegal user reference "f"
/// @ teu35
using potentially illegal user reference "su"
/// @ teu36
using potentially illegal user reference "str"
/// @ teu37
using potentially illegal user reference "str"
/// @ teu38
using potentially illegal user reference "str"
/// @ teu39
using potentially illegal user reference "str"
/// @ teu40
using potentially illegal user reference "str"
/// @ teu41
using potentially illegal user reference "str"
/// @ teu42
using potentially illegal user reference "str"
/// @ teu43
using potentially illegal user reference "str"
/// @ teu44
using potentially illegal user reference "str"
/// @ teu45
using potentially illegal user reference "str"
/// @ teu46
returning potentially illegal user output "sout"
/// @ teu47
returning potentially illegal user output "sout"
/// @ tev0
cannot assign value with access "user" into value with access "var"
/// @ tev1
assigning into an owner a non-owner access "var"
/// @ tev2
assigning into non assignable expression
/// @ tev3
output "s" access should not be "var" for non-primitive type "String"
/// @ tee0
non-conditional reference in type without constructor "Error"
/// @ tee1
constructor did not initialize field "s"
/// @ tee2
using invalid reference "self.s"
/// @ tee3
using invalid reference "self"
/// @ tee4
using invalid reference "self"
/// @ tee5
constructor did not initialize field "s"
/// @ tee6
constructor did not initialize field "s"
/// @ tec0
assigning reference into itself
/// @ tec1
fields cannot have "user" access
/// @@ test-c-objects
/// @ t0
cdef_M_Char c_char = 0;
    cdef_M_Uchar c_uchar = 0;
    cdef_M_Short c_short = 0;
    cdef_M_Ushort c_ushort = 0;
    cdef_M_Int c_int = 0;
    cdef_M_Uint c_uint = 0;
    cdef_M_Long c_long = 0;
    cdef_M_Ulong c_ulong = 0;
    cdef_M_Size c_size = 0;
    cdef_M_Float c_float = 0;
    cdef_M_Double c_double = 0;
    cdef_M_LongDouble c_long_double = 0;
    c_char = ut_M_i;
    ut_M_i = c_char;
    c_uchar = ut_M_i;
    ut_M_i = c_uchar;
    c_short = ut_M_i;
    ut_M_i = c_short;
    c_ushort = ut_M_i;
    ut_M_i = c_ushort;
    c_int = ut_M_i;
    ut_M_i = c_int;
    c_uint = ut_M_i;
    ut_M_i = c_uint;
    c_long = ut_M_i;
    ut_M_i = c_long;
    c_ulong = ut_M_i;
    ut_M_i = c_ulong;
    c_size = ut_M_i;
    ut_M_i = c_size;
    c_float = ut_M_i;
    ut_M_i = c_float;
    c_double = ut_M_i;
    ut_M_i = c_double;
    c_long_double = ut_M_i;
    ut_M_i = c_long_double;
/// @
