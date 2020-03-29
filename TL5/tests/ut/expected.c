typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Ta ut_M_Ta;
typedef struct ut_M_Ta_Dynamic ut_M_Ta_Dynamic;
typedef struct ut_M_Tb ut_M_Tb;
typedef struct ut_M_Tb_Dynamic ut_M_Tb_Dynamic;
typedef struct ut_M_Tc ut_M_Tc;
typedef struct ut_M_Tc_Dynamic ut_M_Tc_Dynamic;
typedef struct ut_M_Data ut_M_Data;
struct ut_M_Test {
    uint32_t num;
    ut_M_Test* t;
    Ref_Manager* t_Refman;
    void (*fun)(void);
};
struct ut_M_Ta {
    ut_M_Test _base;
    uint32_t numa;
};
struct ut_M_Ta_Dynamic {
    Dynamic_Del _del;
    void (*dyn)(ut_M_Ta* self, ut_M_Ta_Dynamic* self_Dynamic);
};
struct ut_M_Tb {
    ut_M_Ta _base;
    uint32_t numb;
};
struct ut_M_Tb_Dynamic {
    ut_M_Ta_Dynamic _base;
};
struct ut_M_Tc {
    ut_M_Tb _base;
    uint32_t numc;
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
void ut_M_Ta_Del(ut_M_Ta* self, ut_M_Ta_Dynamic* self_Dynamic);
Return_Code ut_M_Tb_new(ut_M_Tb* self, ut_M_Tb_Dynamic* self_Dynamic, uint32_t num);
void ut_M_Tb_methb(ut_M_Tb* self, ut_M_Tb_Dynamic* self_Dynamic);
void ut_M_Tb_dyn(ut_M_Tb* self, ut_M_Tb_Dynamic* self_Dynamic);
void ut_M_Tb_Del(ut_M_Tb* self, ut_M_Tb_Dynamic* self_Dynamic);
void ut_M_Tc_methc(ut_M_Tc* self, ut_M_Tc_Dynamic* self_Dynamic);
void ut_M_Tc_dyn(ut_M_Tc* self, ut_M_Tc_Dynamic* self_Dynamic);
void ut_M_Tc_Del(ut_M_Tc* self, ut_M_Tc_Dynamic* self_Dynamic);
void ut_M_Data_set(ut_M_Data* self, Generic_Type* item, Generic_Type_Dynamic* item_Dynamic);
void ut_M_Data_get(ut_M_Data* self, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Data_Del(ut_M_Data* self);
void ut_M_fun0(void);
void ut_M_fun1(uint32_t x, char* s, Seq_Length s_Max_length, Seq_Length* s_Length, char* o, Seq_Length o_Max_length, Seq_Length* o_Length);
void ut_M_fun2(char** s, Seq_Length* s_Max_length, Seq_Length** s_Length, Ref_Manager** s_Refman, uint32_t* x);
void ut_M_fun3(uint32_t x, char** s, Seq_Length* s_Max_length, Seq_Length** s_Length, Ref_Manager** s_Refman);
void ut_M_fun4(uint32_t x);
void ut_M_fun5(uint32_t x, uint32_t* y);
void ut_M_fun6(uint32_t x, uint32_t y, uint32_t* n, uint32_t* m);
void ut_M_fun7(ut_M_Tb* tb, Ref_Manager* tb_Refman, ut_M_Tb_Dynamic* tb_Dynamic, ut_M_Tb** tbo, Ref_Manager** tbo_Refman, ut_M_Tb_Dynamic** tbo_Dynamic);
void ut_M_fun8(char* s, Seq_Length s_Max_length, Seq_Length* s_Length, Ref_Manager* s_Refman);
Return_Code ut_M_fune(void);
Return_Code ut_M_mock(char* str, Seq_Length str_Max_length, Seq_Length* str_Length, Byte* bfr, Seq_Length bfr_Max_length, Seq_Length* bfr_Length, char** so, Seq_Length* so_Max_length, Seq_Length** so_Length, Ref_Manager** so_Refman, uint32_t* io, ut_M_Test** to, Ref_Manager** to_Refman, ut_M_Tc** tco, Ref_Manager** tco_Refman, ut_M_Tc_Dynamic** tco_Dynamic);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
ut_M_Ta_Dynamic ut_M_Ta_dynamic = {(Dynamic_Del)ut_M_Ta_Del, ut_M_Ta_dyn};
ut_M_Tb_Dynamic ut_M_Tb_dynamic = {{(Dynamic_Del)ut_M_Tb_Del, (void (*)(ut_M_Ta* self, ut_M_Ta_Dynamic* self_Dynamic))ut_M_Tb_dyn}};
ut_M_Tc_Dynamic ut_M_Tc_dynamic = {{{(Dynamic_Del)ut_M_Tc_Del, (void (*)(ut_M_Ta* self, ut_M_Ta_Dynamic* self_Dynamic))ut_M_Tc_dyn}}};
Generic_Type_Dynamic ut_M_Data_dynamic = {(Dynamic_Del)ut_M_Data_Del};
uint32_t ut_M_i = 0;
int32_t ut_M_j = 0;
Byte ut_M_bt = 0;
Char ut_M_c = 0;
Bool ut_M_b = 0;
char* ut_M_ostr = NULL;
Seq_Length ut_M_ostr_Max_length = 0;
Seq_Length* ut_M_ostr_Length = &Lumi_empty_length;
Byte* ut_M_buff = NULL;
Seq_Length ut_M_buff_Max_length = 0;
Seq_Length* ut_M_buff_Length = &Lumi_empty_length;
uint32_t* ut_M_arr = NULL;
Seq_Length ut_M_arr_Length = 0;
Ref_Manager* ut_M_arr_Refman = NULL;
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
Seq_Length ut_M_sarr_Length = 0;
Seq_Length ut_M_sarr_Value_length = 0;
Seq_Length* ut_M_sarr_Seq_length = NULL;
Ref_Manager* ut_M_sarr_Refman = NULL;
Byte* ut_M_barr = NULL;
Seq_Length ut_M_barr_Length = 0;
Seq_Length ut_M_barr_Value_length = 0;
Seq_Length* ut_M_barr_Seq_length = NULL;
Ref_Manager* ut_M_barr_Refman = NULL;
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
void ut_M_Ta_Del(ut_M_Ta* self, ut_M_Ta_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Test_Del(&(self->_base), &(self_Dynamic->_base));
}
Return_Code ut_M_Tb_new(ut_M_Tb* self, ut_M_Tb_Dynamic* self_Dynamic, uint32_t num) {
    Return_Code LUMI_err = OK;
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
void ut_M_Tb_Del(ut_M_Tb* self, ut_M_Tb_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Ta_Del(&(self->_base), &(self_Dynamic->_base));
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
void ut_M_Tc_Del(ut_M_Tc* self, ut_M_Tc_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Tb_Del(&(self->_base), &(self_Dynamic->_base));
}
void ut_M_Data_set(ut_M_Data* self, Generic_Type* item, Generic_Type_Dynamic* item_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    if (item_Dynamic != NULL) item_Dynamic->_del(item, item_Dynamic);
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
void ut_M_fun1(uint32_t x, char* s, Seq_Length s_Max_length, Seq_Length* s_Length, char* o, Seq_Length o_Max_length, Seq_Length* o_Length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    String_Del(o);
    free(o);
}
void ut_M_fun2(char** s, Seq_Length* s_Max_length, Seq_Length** s_Length, Ref_Manager** s_Refman, uint32_t* x) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun3(uint32_t x, char** s, Seq_Length* s_Max_length, Seq_Length** s_Length, Ref_Manager** s_Refman) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun4(uint32_t x) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun5(uint32_t x, uint32_t* y) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun6(uint32_t x, uint32_t y, uint32_t* n, uint32_t* m) {
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
void ut_M_fun8(char* s, Seq_Length s_Max_length, Seq_Length* s_Length, Ref_Manager* s_Refman) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    String_Del(s);
    LUMI_owner_dec_ref(s_Refman);
}
Return_Code ut_M_fune(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
Return_Code ut_M_mock(char* str, Seq_Length str_Max_length, Seq_Length* str_Length, Byte* bfr, Seq_Length bfr_Max_length, Seq_Length* bfr_Length, char** so, Seq_Length* so_Max_length, Seq_Length** so_Length, Ref_Manager** so_Refman, uint32_t* io, ut_M_Test** to, Ref_Manager** to_Refman, ut_M_Tc** tco, Ref_Manager** tco_Refman, ut_M_Tc_Dynamic** tco_Dynamic) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @@ test-int-expression
/// @ test-int-expression-0
ut_M_i = 0;
/// @ test-int-expression-1
ut_M_i = 0x259e;
/// @ test-int-expression-2
ut_M_j = -0x259e;
/// @ test-int-expression-3
ut_M_i = 0x0f50;
/// @ test-int-expression-4
ut_M_j = -0x0f50;
/// @ test-int-expression-5
ut_M_i = 0xfda940;
/// @ test-int-expression-6
ut_M_j = -0xfda940;
/// @ test-int-expression-7
ut_M_i = 0xfda940;
/// @ test-int-expression-8
ut_M_j = -0xfda940;
/// @ test-int-expression-9
ut_M_i = 0x25;
/// @ test-int-expression-10
ut_M_j = -0x25;
/// @ test-int-expression-e0
illegal number "2a"
/// @ test-int-expression-e1
illegal number "0a"
/// @ test-int-expression-e2
illegal octal number "038"
/// @ test-int-expression-e3
illegal binary number "0b021"
/// @ test-int-expression-e4
illegal hexadecimal number "0xadg"
/// @@ test-byte-expression
/// @ test-byte-expression-0
ut_M_bt = 0;
/// @ test-byte-expression-1
ut_M_bt = 0x7f;
/// @ test-byte-expression-2
ut_M_bt = 0x3d;
/// @ test-byte-expression-3
ut_M_bt = 0xfd;
/// @ test-byte-expression-4
ut_M_bt = 0xfd;
/// @ test-byte-expression-5
ut_M_bt = 0x94;
/// @@ test-char-expression
/// @ test-char-expression-0
ut_M_c = 'a';
/// @ test-char-expression-1
ut_M_c = '\'';
/// @ test-char-expression-2
ut_M_c = '\n';
/// @ test-char-expression-3
ut_M_c = '\x0f';
/// @ test-char-expression-4
ut_M_c = '\x7A';
/// @ test-char-expression-5
ut_M_c = '\173';
/// @ test-char-expression-e0
illegal character constant "'''"
/// @ test-char-expression-e1
illegal character constant "'\'"
/// @ test-char-expression-e2
illegal character constant "'aa"
/// @ test-char-expression-e3
illegal character constant "'\c'"
/// @ test-char-expression-e4
illegal character constant "'aaaa'"
/// @ test-char-expression-e5
illegal character constant "'\x6g'"
/// @ test-char-expression-e6
illegal character constant "'\058'"
/// @ test-char-expression-e7
illegal character constant "''"
/// @ test-char-expression-e8
illegal character constant "'aa'"
/// @ test-char-expression-e9
illegal character constant "'aaa'"
/// @ test-char-expression-e10
illegal character constant "'aaaaa'"
/// @@ test-string-expression
/// @ test-string-expression-0
static char aux_String_0[] = {'s','o','m','e',' ','s','t','r','i','n','g','\0',};
    Seq_Length aux_String_0_Max_length = sizeof(aux_String_0);
    Seq_Length aux_String_0_Length[1] = {sizeof(aux_String_0) - 1};
    str_Max_length = aux_String_0_Max_length;
    str_Length = aux_String_0_Length;
    str = aux_String_0;
/// @ test-string-expression-1
static char aux_String_0[] = {'\n','s','t','r','i','n','g','\'','\t','\"','w','i','t','h','\\','\'','f','o','r','m',
        'a','t','t','i','n','g','\n','\0',};
    Seq_Length aux_String_0_Max_length = sizeof(aux_String_0);
    Seq_Length aux_String_0_Length[1] = {sizeof(aux_String_0) - 1};
    str_Max_length = aux_String_0_Max_length;
    str_Length = aux_String_0_Length;
    str = aux_String_0;
/// @ test-string-expression-2
static char aux_String_0[] = {'l','i','n','e','s','p','l','i','t','s','t','r','i','n','g','\0',};
    Seq_Length aux_String_0_Max_length = sizeof(aux_String_0);
    Seq_Length aux_String_0_Length[1] = {sizeof(aux_String_0) - 1};
    str_Max_length = aux_String_0_Max_length;
    str_Length = aux_String_0_Length;
    str = aux_String_0;
/// @ test-string-expression-3
static char aux_String_0[] = {'m','u','l','t','i','\n','l','i','n','e','\n','s','t','r','i','n','g','\n','\0',};
    Seq_Length aux_String_0_Max_length = sizeof(aux_String_0);
    Seq_Length aux_String_0_Length[1] = {sizeof(aux_String_0) - 1};
    str_Max_length = aux_String_0_Max_length;
    str_Length = aux_String_0_Length;
    str = aux_String_0;
/// @ test-string-expression-4
static char aux_String_0[] = {'l','i','n','e',' ','s','p','l','i','t','\0',};
    Seq_Length aux_String_0_Max_length = sizeof(aux_String_0);
    Seq_Length aux_String_0_Length[1] = {sizeof(aux_String_0) - 1};
    str_Max_length = aux_String_0_Max_length;
    str_Length = aux_String_0_Length;
    str = aux_String_0;
/// @ test-string-expression-e0
no '"' around string constant ""aaa"
/// @ test-string-expression-e1
too short string constant """
/// @ test-string-expression-e2
'"' inside string constant ""error"+"string""
/// @ test-string-expression-e3
indentation too short, expected 12 got 8
/// @ test-string-expression-e4
indentation too short, expected 12 got 8
/// @ test-string-expression-large
void ut_M_fun(void);
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    static char aux_String_0[] = {'0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
        '\0',};
    Seq_Length aux_String_0_Max_length = sizeof(aux_String_0);
    Seq_Length aux_String_0_Length[1] = {sizeof(aux_String_0) - 1};
    s_Max_length = aux_String_0_Max_length;
    s_Length = aux_String_0_Length;
    s = aux_String_0;
LUMI_block0_cleanup:
    (void)0;
}
/// @@ test-buffer-expression
/// @ test-buffer-expression-0
static Byte aux_Buffer_0[] = {0x4a,0x00,0xe2,0xff,0x59,};
    Seq_Length aux_Buffer_0_Max_length = sizeof(aux_Buffer_0);
    Seq_Length aux_Buffer_0_Length[1] = {sizeof(aux_Buffer_0)};
    bfr_Max_length = aux_Buffer_0_Max_length;
    bfr_Length = aux_Buffer_0_Length;
    bfr = aux_Buffer_0;
/// @ test-buffer-expression-1
static Byte aux_Buffer_0[] = {0x4a,0x00,0xe2,0xff,0x59,0xa8,};
    Seq_Length aux_Buffer_0_Max_length = sizeof(aux_Buffer_0);
    Seq_Length aux_Buffer_0_Length[1] = {sizeof(aux_Buffer_0)};
    bfr_Max_length = aux_Buffer_0_Max_length;
    bfr_Length = aux_Buffer_0_Length;
    bfr = aux_Buffer_0;
/// @ test-buffer-expression-2
static Byte aux_Buffer_0[] = {0x4a,0x00,0xe2,0xff,0x59,0xa8,};
    Seq_Length aux_Buffer_0_Max_length = sizeof(aux_Buffer_0);
    Seq_Length aux_Buffer_0_Length[1] = {sizeof(aux_Buffer_0)};
    bfr_Max_length = aux_Buffer_0_Max_length;
    bfr_Length = aux_Buffer_0_Length;
    bfr = aux_Buffer_0;
/// @ test-buffer-expression-e0
no '`' around buffer constant "`0000"
/// @ test-buffer-expression-e1
too short buffer constant "`"
/// @ test-buffer-expression-e2
indentation too short, expected 12 got 8
/// @ test-buffer-expression-e3
illegal buffer data "g"
/// @ test-buffer-expression-e4
odd buffer data length
/// @ test-buffer-expression-large
void ut_M_fun(void);
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    Byte* b = NULL;
    Seq_Length b_Max_length = 0;
    Seq_Length* b_Length = &Lumi_empty_length;
    static Byte aux_Buffer_0[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
        };
    Seq_Length aux_Buffer_0_Max_length = sizeof(aux_Buffer_0);
    Seq_Length aux_Buffer_0_Length[1] = {sizeof(aux_Buffer_0)};
    b_Max_length = aux_Buffer_0_Max_length;
    b_Length = aux_Buffer_0_Length;
    b = aux_Buffer_0;
LUMI_block0_cleanup:
    (void)0;
}
/// @@ test-empty-expression
/// @ test-empty-expression-0
str_Max_length = 0;
    str_Length = &Lumi_empty_length;
    str = NULL;
/// @ test-empty-expression-1
LUMI_inc_ref(NULL);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = NULL;
    ut_M_t = NULL;
/// @ test-empty-expression-2
String_Del(*so);
    LUMI_owner_dec_ref(*so_Refman);
    *so_Refman = NULL;
    *so_Max_length = 0;
    *so_Length = &Lumi_empty_length;
    *so = NULL;
/// @ test-empty-expression-3
ut_M_b = ((void*)ut_M_t == NULL) || ((void*)ut_M_ta != NULL);
/// @ test-empty-expression-e0
cannot assign "Empty Symbol" into "Int"
/// @@ test-member-expression
/// @ test-member-expression-0
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    ut_M_i = ut_M_t->num;
/// @ test-member-expression-1
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_tc, ut_M_tc_Refman)
    ut_M_i = ut_M_tc->_base.numb;
/// @ test-member-expression-2
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_tc, ut_M_tc_Refman)
    ut_M_i = ut_M_tc->_base._base._base.num;
/// @ test-member-expression-3
CHECK_REF(1, LUMI_block0_cleanup, *to)
    ut_M_i = (*to)->num;
/// @ test-member-expression-4
LUMI_inc_ref(ut_M_tc_Refman);
    LUMI_dec_ref(*tco_Refman);
    *tco_Refman = ut_M_tc_Refman;
    *tco_Dynamic = ut_M_tc_Dynamic;
    *tco = ut_M_tc;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, *tco, *tco_Refman)
    ut_M_i = (*tco)->_base._base._base.num;
/// @ test-member-expression-5
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t->t, ut_M_t->t_Refman)
    ut_M_i = ut_M_t->t->num;
/// @ test-member-expression-6
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t->t, ut_M_t->t_Refman)
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t->t->t, ut_M_t->t->t_Refman)
    ut_M_i = ut_M_t->t->t->num;
/// @ test-member-expression-e0
unknown symbol "error"
/// @ test-member-expression-e1
void expression has no member "error"
/// @ test-member-expression-e2
type "Test" has no member "error"
/// @ test-member-expression-e3
type "Int" has no member "error"
/// @@ test-slice-expression
/// @ test-slice-expression-0
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    if (0x0d >= *(ut_M_ostr_Length)) RAISE(1, LUMI_block0_cleanup, slice_index)
    ut_M_c = ut_M_ostr[0x0d];
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_buff)
    if (0x0d >= *(ut_M_buff_Length)) RAISE(2, LUMI_block0_cleanup, slice_index)
    ut_M_bt = ut_M_buff[0x0d];
/// @ test-slice-expression-1
Char* x = NULL;
    Seq_Length x_Length = 0;
    Byte* y = NULL;
    Seq_Length y_Length = 0;
    Char* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Byte* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_ostr)
    if (SAFE_SUM_LARGER(0x02, 0x06, *(ut_M_ostr_Length))) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = ut_M_ostr + 0x02;
    aux_Array_0_Length = 0x06;
    x_Length = 0x06;
    x = aux_Array_0;
    CHECK_REF(4, LUMI_block0_cleanup, ut_M_buff)
    if (SAFE_SUM_LARGER(0x02, 0x06, *(ut_M_buff_Length))) RAISE(4, LUMI_block0_cleanup, slice_index)
    aux_Array_1 = ut_M_buff + 0x02;
    aux_Array_1_Length = 0x06;
    y_Length = 0x06;
    y = aux_Array_1;
/// @ test-slice-expression-2
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (0x0d >= ut_M_arr_Length) RAISE(1, LUMI_block0_cleanup, slice_index)
    ut_M_i = ut_M_arr[0x0d];
/// @ test-slice-expression-3
uint32_t* x = NULL;
    Seq_Length x_Length = 0;
    uint32_t* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_i <= 0 || SAFE_SUM_LARGER(0x02, ut_M_i, ut_M_arr_Length)) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = ut_M_arr + 0x02;
    aux_Array_0_Length = ut_M_i;
    x_Length = aux_Array_0_Length;
    x = aux_Array_0;
/// @ test-slice-expression-4
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    if (0x04 >= *(ut_M_ostr_Length)) RAISE(1, LUMI_block0_cleanup, slice_index)
    ut_M_ostr[0x04] = ut_M_c;
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_buff)
    if (0x04 >= *(ut_M_buff_Length)) RAISE(2, LUMI_block0_cleanup, slice_index)
    ut_M_buff[0x04] = ut_M_bt;
/// @ test-slice-expression-5
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (0x04 >= ut_M_arr_Length) RAISE(1, LUMI_block0_cleanup, slice_index)
    ut_M_arr[0x04] = ut_M_i;
/// @ test-slice-expression-6
ut_M_Test* tarr = NULL;
    Seq_Length tarr_Length = 0;
    Ref_Manager* tarr_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, tarr)
    if (0x03 >= tarr_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(tarr_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = tarr_Refman;
    ut_M_t = tarr + 0x03;
/// @ test-slice-expression-7
char vsa[0x08 * 0x05] = {0};
    Seq_Length vsa_Seq_length[0x08] = {0};
    char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    char* sa = NULL;
    Seq_Length sa_Length = 0;
    Seq_Length sa_Value_length = 0;
    Seq_Length* sa_Seq_length = NULL;
    Byte vba[0x08 * 0x05] = {0};
    Seq_Length vba_Seq_length[0x08] = {0};
    Byte* bf = NULL;
    Seq_Length bf_Max_length = 0;
    Seq_Length* bf_Length = &Lumi_empty_length;
    Byte* ba = NULL;
    Seq_Length ba_Length = 0;
    Seq_Length ba_Value_length = 0;
    Seq_Length* ba_Seq_length = NULL;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    char* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Seq_Length aux_Array_0_Value_length = 0;
    Seq_Length* aux_Array_0_Seq_length = NULL;
    Byte* aux_Buffer_0 = NULL;
    Seq_Length aux_Buffer_0_Max_length = 0;
    Seq_Length* aux_Buffer_0_Length = &Lumi_empty_length;
    Byte* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    Seq_Length aux_Array_1_Value_length = 0;
    Seq_Length* aux_Array_1_Seq_length = NULL;
    /* initializing vsa */
    aux_String_0 = vsa + 0x03 * 0x05;
    aux_String_0_Max_length = 0x05;
    aux_String_0_Length = vsa_Seq_length + 0x03;
    s_Max_length = 0x05;
    s_Length = aux_String_0_Length;
    s = aux_String_0;
    aux_Array_0 = vsa + 0x02 * 0x05;
    aux_Array_0_Length = 0x04;
    aux_Array_0_Value_length = 0x05;
    aux_Array_0_Seq_length = vsa_Seq_length + 0x02;
    sa_Length = 0x04;
    sa_Value_length = 0x05;
    sa_Seq_length = aux_Array_0_Seq_length;
    sa = aux_Array_0;
    /* initializing vba */
    aux_Buffer_0 = vba + 0x03 * 0x05;
    aux_Buffer_0_Max_length = 0x05;
    aux_Buffer_0_Length = vba_Seq_length + 0x03;
    bf_Max_length = 0x05;
    bf_Length = aux_Buffer_0_Length;
    bf = aux_Buffer_0;
    aux_Array_1 = vba + 0x02 * 0x05;
    aux_Array_1_Length = 0x04;
    aux_Array_1_Value_length = 0x05;
    aux_Array_1_Seq_length = vba_Seq_length + 0x02;
    ba_Length = 0x04;
    ba_Value_length = 0x05;
    ba_Seq_length = aux_Array_1_Seq_length;
    ba = aux_Array_1;
/// @ test-slice-expression-8
Return_Code ut_M_fun(char* s, Seq_Length s_Max_length, Seq_Length* s_Length, char* sa, Seq_Length sa_Length, Seq_Length sa_Value_length, Seq_Length* sa_Seq_length, Ref_Manager* sa_Refman, Byte* b, Seq_Length b_Max_length, Seq_Length* b_Length, Byte* ba, Seq_Length ba_Length, Seq_Length ba_Value_length, Seq_Length* ba_Seq_length, Ref_Manager* ba_Refman);
Return_Code ut_M_fun(char* s, Seq_Length s_Max_length, Seq_Length* s_Length, char* sa, Seq_Length sa_Length, Seq_Length sa_Value_length, Seq_Length* sa_Seq_length, Ref_Manager* sa_Refman, Byte* b, Seq_Length b_Max_length, Seq_Length* b_Length, Byte* ba, Seq_Length ba_Length, Seq_Length ba_Value_length, Seq_Length* ba_Seq_length, Ref_Manager* ba_Refman) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Char c = 0;
    Char* spart = NULL;
    Seq_Length spart_Length = 0;
    char* si = NULL;
    Seq_Length si_Max_length = 0;
    Seq_Length* si_Length = &Lumi_empty_length;
    Byte y = 0;
    Byte* bpart = NULL;
    Seq_Length bpart_Length = 0;
    Byte* bi = NULL;
    Seq_Length bi_Max_length = 0;
    Seq_Length* bi_Length = &Lumi_empty_length;
    Char* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    Ref_Manager* aux_String_0_Refman = NULL;
    Byte* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    Byte* aux_Buffer_0 = NULL;
    Seq_Length aux_Buffer_0_Max_length = 0;
    Seq_Length* aux_Buffer_0_Length = &Lumi_empty_length;
    Ref_Manager* aux_Buffer_0_Refman = NULL;
    if (0x05 >= *(s_Length)) RAISE(6, LUMI_block0_cleanup, slice_index)
    c = s[0x05];
    if (SAFE_SUM_LARGER(0x04, 0x02, *(s_Length))) RAISE(7, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = s + 0x04;
    aux_Array_0_Length = 0x02;
    spart_Length = 0x02;
    spart = aux_Array_0;
    if (0x03 >= sa_Length) RAISE(8, LUMI_block0_cleanup, slice_index)
    aux_String_0 = sa + 0x03 * sa_Value_length;
    aux_String_0_Max_length = sa_Value_length;
    aux_String_0_Length = sa_Seq_length + 0x03;
    aux_String_0_Refman = sa_Refman;
    LUMI_inc_ref(aux_String_0_Refman);
    CHECK_REFMAN(8, LUMI_block0_cleanup, aux_String_0_Refman)
    si_Max_length = aux_String_0_Max_length;
    si_Length = aux_String_0_Length;
    si = aux_String_0;
    if (0x05 >= *(b_Length)) RAISE(9, LUMI_block0_cleanup, slice_index)
    y = b[0x05];
    if (SAFE_SUM_LARGER(0x04, 0x02, *(b_Length))) RAISE(10, LUMI_block0_cleanup, slice_index)
    aux_Array_1 = b + 0x04;
    aux_Array_1_Length = 0x02;
    bpart_Length = 0x02;
    bpart = aux_Array_1;
    if (0x03 >= ba_Length) RAISE(11, LUMI_block0_cleanup, slice_index)
    aux_Buffer_0 = ba + 0x03 * ba_Value_length;
    aux_Buffer_0_Max_length = ba_Value_length;
    aux_Buffer_0_Length = ba_Seq_length + 0x03;
    aux_Buffer_0_Refman = ba_Refman;
    LUMI_inc_ref(aux_Buffer_0_Refman);
    CHECK_REFMAN(11, LUMI_block0_cleanup, aux_Buffer_0_Refman)
    bi_Max_length = aux_Buffer_0_Max_length;
    bi_Length = aux_Buffer_0_Length;
    bi = aux_Buffer_0;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(aux_Buffer_0_Refman);
    LUMI_dec_ref(aux_String_0_Refman);
    free(ba_Seq_length);
    LUMI_owner_dec_ref(ba_Refman);
    free(sa_Seq_length);
    LUMI_owner_dec_ref(sa_Refman);
    return LUMI_err;
}
/// @ test-slice-expression-9
char* sa = NULL;
    Seq_Length sa_Length = 0;
    Seq_Length sa_Value_length = 0;
    Seq_Length* sa_Seq_length = NULL;
    Ref_Manager* sa_Refman = NULL;
    Byte* ba = NULL;
    Seq_Length ba_Length = 0;
    Seq_Length ba_Value_length = 0;
    Seq_Length* ba_Seq_length = NULL;
    Ref_Manager* ba_Refman = NULL;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    Ref_Manager* aux_String_0_Refman = NULL;
    static char aux_String_1[] = {'t','e','x','t','\0',};
    Seq_Length aux_String_1_Max_length = sizeof(aux_String_1);
    Seq_Length aux_String_1_Length[1] = {sizeof(aux_String_1) - 1};
    Byte* aux_Buffer_0 = NULL;
    Seq_Length aux_Buffer_0_Max_length = 0;
    Seq_Length* aux_Buffer_0_Length = &Lumi_empty_length;
    Ref_Manager* aux_Buffer_0_Refman = NULL;
    static Byte aux_Buffer_1[] = {0xbe,0xef,};
    Seq_Length aux_Buffer_1_Max_length = sizeof(aux_Buffer_1);
    Seq_Length aux_Buffer_1_Length[1] = {sizeof(aux_Buffer_1)};
    CHECK_REF(2, LUMI_block0_cleanup, sa)
    if (0x03 >= sa_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_String_0 = sa + 0x03 * sa_Value_length;
    aux_String_0_Max_length = sa_Value_length;
    aux_String_0_Length = sa_Seq_length + 0x03;
    aux_String_0_Refman = sa_Refman;
    LUMI_inc_ref(aux_String_0_Refman);
    CHECK_REFMAN(2, LUMI_block0_cleanup, aux_String_0_Refman)
    LUMI_err = String_copy(aux_String_0, aux_String_0_Max_length, aux_String_0_Length, aux_String_1, *aux_String_1_Length);
    CHECK(2, LUMI_block0_cleanup)
    free(sa_Seq_length);
    LUMI_owner_dec_ref(sa_Refman);
    sa_Refman = NULL;
    sa_Length = 0;
    sa_Value_length = 0;
    sa_Seq_length = NULL;
    sa = NULL;
    CHECK_REF(5, LUMI_block0_cleanup, ba)
    if (0x03 >= ba_Length) RAISE(5, LUMI_block0_cleanup, slice_index)
    aux_Buffer_0 = ba + 0x03 * ba_Value_length;
    aux_Buffer_0_Max_length = ba_Value_length;
    aux_Buffer_0_Length = ba_Seq_length + 0x03;
    aux_Buffer_0_Refman = ba_Refman;
    LUMI_inc_ref(aux_Buffer_0_Refman);
    CHECK_REFMAN(5, LUMI_block0_cleanup, aux_Buffer_0_Refman)
    LUMI_err = Buffer_copy(aux_Buffer_0, aux_Buffer_0_Max_length, aux_Buffer_0_Length, aux_Buffer_1, *aux_Buffer_1_Length);
    CHECK(5, LUMI_block0_cleanup)
    free(ba_Seq_length);
    LUMI_owner_dec_ref(ba_Refman);
    ba_Refman = NULL;
    ba_Length = 0;
    ba_Value_length = 0;
    ba_Seq_length = NULL;
    ba = NULL;
/// @ test-slice-expression-10
uint32_t* aai = NULL;
    Seq_Length aai_Length = 0;
    Seq_Length aai_Value_length = 0;
    Ref_Manager* aai_Refman = NULL;
    uint32_t* ua = NULL;
    Seq_Length ua_Length = 0;
    Seq_Length ua_Value_length = 0;
    Ref_Manager* ua_Refman = NULL;
    uint32_t* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Ref_Manager* aux_Array_0_Refman = NULL;
    uint32_t* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    Seq_Length aux_Array_1_Value_length = 0;
    Ref_Manager* aux_Array_1_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, aai)
    if (0x03 >= aai_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = aai + 0x03 * aai_Value_length;
    aux_Array_0_Length = aai_Value_length;
    aux_Array_0_Refman = aai_Refman;
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_dec_ref(ut_M_arr_Refman);
    ut_M_arr_Refman = aux_Array_0_Refman;
    ut_M_arr_Length = aux_Array_0_Length;
    ut_M_arr = aux_Array_0;
    CHECK_REF(3, LUMI_block0_cleanup, aai)
    if (SAFE_SUM_LARGER(0x02, 0x04, aai_Length)) RAISE(3, LUMI_block0_cleanup, slice_index)
    aux_Array_1 = aai + 0x02 * aai_Value_length;
    aux_Array_1_Length = 0x04;
    aux_Array_1_Value_length = aai_Value_length;
    aux_Array_1_Refman = aai_Refman;
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_dec_ref(ua_Refman);
    ua_Refman = aux_Array_1_Refman;
    ua_Length = 0x04;
    ua_Value_length = aux_Array_1_Value_length;
    ua = aux_Array_1;
/// @ test-slice-expression-11
uint32_t* aai = NULL;
    Seq_Length aai_Length = 0;
    Seq_Length aai_Value_length = 0;
    Seq_Length aai_Value_value_length = 0;
    Seq_Length aai_Value_value_value_length = 0;
    Ref_Manager* aai_Refman = NULL;
    uint32_t* ua = NULL;
    Seq_Length ua_Length = 0;
    Seq_Length ua_Value_length = 0;
    Seq_Length ua_Value_value_length = 0;
    Ref_Manager* ua_Refman = NULL;
    uint32_t* uaa = NULL;
    Seq_Length uaa_Length = 0;
    Seq_Length uaa_Value_length = 0;
    Seq_Length uaa_Value_value_length = 0;
    Seq_Length uaa_Value_value_value_length = 0;
    Ref_Manager* uaa_Refman = NULL;
    uint32_t* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Seq_Length aux_Array_0_Value_length = 0;
    Seq_Length aux_Array_0_Value_value_length = 0;
    Ref_Manager* aux_Array_0_Refman = NULL;
    uint32_t* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    Seq_Length aux_Array_1_Value_length = 0;
    Seq_Length aux_Array_1_Value_value_length = 0;
    Seq_Length aux_Array_1_Value_value_value_length = 0;
    Ref_Manager* aux_Array_1_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, aai)
    if (0x03 >= aai_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = aai + 0x03 * aai_Value_length * aai_Value_value_length * aai_Value_value_value_length;
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
    if (SAFE_SUM_LARGER(0x02, 0x04, aai_Length)) RAISE(3, LUMI_block0_cleanup, slice_index)
    aux_Array_1 = aai + 0x02 * aai_Value_length * aai_Value_value_length * aai_Value_value_value_length;
    aux_Array_1_Length = 0x04;
    aux_Array_1_Value_length = aai_Value_length;
    aux_Array_1_Value_value_length = aai_Value_value_length;
    aux_Array_1_Value_value_value_length = aai_Value_value_value_length;
    aux_Array_1_Refman = aai_Refman;
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_dec_ref(uaa_Refman);
    uaa_Refman = aux_Array_1_Refman;
    uaa_Length = 0x04;
    uaa_Value_length = aux_Array_1_Value_length;
    uaa_Value_value_length = aux_Array_1_Value_value_length;
    uaa_Value_value_value_length = aux_Array_1_Value_value_value_length;
    uaa = aux_Array_1;
/// @ test-slice-expression-12
char* aas = NULL;
    Seq_Length aas_Length = 0;
    Seq_Length aas_Value_length = 0;
    Seq_Length aas_Value_value_length = 0;
    Seq_Length aas_Value_value_value_length = 0;
    Seq_Length* aas_Seq_length = NULL;
    Ref_Manager* aas_Refman = NULL;
    char* wsa = NULL;
    Seq_Length wsa_Length = 0;
    Seq_Length wsa_Value_length = 0;
    Seq_Length wsa_Value_value_length = 0;
    Seq_Length* wsa_Seq_length = NULL;
    Ref_Manager* wsa_Refman = NULL;
    char* wsaa = NULL;
    Seq_Length wsaa_Length = 0;
    Seq_Length wsaa_Value_length = 0;
    Seq_Length wsaa_Value_value_length = 0;
    Seq_Length wsaa_Value_value_value_length = 0;
    Seq_Length* wsaa_Seq_length = NULL;
    Ref_Manager* wsaa_Refman = NULL;
    Byte* aab = NULL;
    Seq_Length aab_Length = 0;
    Seq_Length aab_Value_length = 0;
    Seq_Length aab_Value_value_length = 0;
    Seq_Length aab_Value_value_value_length = 0;
    Seq_Length* aab_Seq_length = NULL;
    Ref_Manager* aab_Refman = NULL;
    Byte* wba = NULL;
    Seq_Length wba_Length = 0;
    Seq_Length wba_Value_length = 0;
    Seq_Length wba_Value_value_length = 0;
    Seq_Length* wba_Seq_length = NULL;
    Ref_Manager* wba_Refman = NULL;
    Byte* wbaa = NULL;
    Seq_Length wbaa_Length = 0;
    Seq_Length wbaa_Value_length = 0;
    Seq_Length wbaa_Value_value_length = 0;
    Seq_Length wbaa_Value_value_value_length = 0;
    Seq_Length* wbaa_Seq_length = NULL;
    Ref_Manager* wbaa_Refman = NULL;
    char* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Seq_Length aux_Array_0_Value_length = 0;
    Seq_Length aux_Array_0_Value_value_length = 0;
    Seq_Length* aux_Array_0_Seq_length = NULL;
    Ref_Manager* aux_Array_0_Refman = NULL;
    char* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    Seq_Length aux_Array_1_Value_length = 0;
    Seq_Length aux_Array_1_Value_value_length = 0;
    Seq_Length aux_Array_1_Value_value_value_length = 0;
    Seq_Length* aux_Array_1_Seq_length = NULL;
    Ref_Manager* aux_Array_1_Refman = NULL;
    Byte* aux_Array_2 = NULL;
    Seq_Length aux_Array_2_Length = 0;
    Seq_Length aux_Array_2_Value_length = 0;
    Seq_Length aux_Array_2_Value_value_length = 0;
    Seq_Length* aux_Array_2_Seq_length = NULL;
    Ref_Manager* aux_Array_2_Refman = NULL;
    Byte* aux_Array_3 = NULL;
    Seq_Length aux_Array_3_Length = 0;
    Seq_Length aux_Array_3_Value_length = 0;
    Seq_Length aux_Array_3_Value_value_length = 0;
    Seq_Length aux_Array_3_Value_value_value_length = 0;
    Seq_Length* aux_Array_3_Seq_length = NULL;
    Ref_Manager* aux_Array_3_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, aas)
    if (0x03 >= aas_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = aas + 0x03 * aas_Value_length * aas_Value_value_length * aas_Value_value_value_length;
    aux_Array_0_Length = aas_Value_length;
    aux_Array_0_Value_length = aas_Value_value_length;
    aux_Array_0_Value_value_length = aas_Value_value_value_length;
    aux_Array_0_Seq_length = aas_Seq_length + 0x03 * aas_Value_length * aas_Value_value_length;
    aux_Array_0_Refman = aas_Refman;
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_dec_ref(wsa_Refman);
    wsa_Refman = aux_Array_0_Refman;
    wsa_Length = aux_Array_0_Length;
    wsa_Value_length = aux_Array_0_Value_length;
    wsa_Value_value_length = aux_Array_0_Value_value_length;
    wsa_Seq_length = aux_Array_0_Seq_length;
    wsa = aux_Array_0;
    CHECK_REF(3, LUMI_block0_cleanup, aas)
    if (SAFE_SUM_LARGER(0x02, 0x04, aas_Length)) RAISE(3, LUMI_block0_cleanup, slice_index)
    aux_Array_1 = aas + 0x02 * aas_Value_length * aas_Value_value_length * aas_Value_value_value_length;
    aux_Array_1_Length = 0x04;
    aux_Array_1_Value_length = aas_Value_length;
    aux_Array_1_Value_value_length = aas_Value_value_length;
    aux_Array_1_Value_value_value_length = aas_Value_value_value_length;
    aux_Array_1_Seq_length = aas_Seq_length + 0x02 * aas_Value_length * aas_Value_value_length;
    aux_Array_1_Refman = aas_Refman;
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_dec_ref(wsaa_Refman);
    wsaa_Refman = aux_Array_1_Refman;
    wsaa_Length = 0x04;
    wsaa_Value_length = aux_Array_1_Value_length;
    wsaa_Value_value_length = aux_Array_1_Value_value_length;
    wsaa_Value_value_value_length = aux_Array_1_Value_value_value_length;
    wsaa_Seq_length = aux_Array_1_Seq_length;
    wsaa = aux_Array_1;
    free(aas_Seq_length);
    LUMI_owner_dec_ref(aas_Refman);
    aas_Refman = NULL;
    aas_Length = 0;
    aas_Value_length = 0;
    aas_Value_value_length = 0;
    aas_Value_value_value_length = 0;
    aas_Seq_length = NULL;
    aas = NULL;
    CHECK_REF(6, LUMI_block0_cleanup, aab)
    if (0x03 >= aab_Length) RAISE(6, LUMI_block0_cleanup, slice_index)
    aux_Array_2 = aab + 0x03 * aab_Value_length * aab_Value_value_length * aab_Value_value_value_length;
    aux_Array_2_Length = aab_Value_length;
    aux_Array_2_Value_length = aab_Value_value_length;
    aux_Array_2_Value_value_length = aab_Value_value_value_length;
    aux_Array_2_Seq_length = aab_Seq_length + 0x03 * aab_Value_length * aab_Value_value_length;
    aux_Array_2_Refman = aab_Refman;
    LUMI_inc_ref(aux_Array_2_Refman);
    LUMI_inc_ref(aux_Array_2_Refman);
    LUMI_dec_ref(wba_Refman);
    wba_Refman = aux_Array_2_Refman;
    wba_Length = aux_Array_2_Length;
    wba_Value_length = aux_Array_2_Value_length;
    wba_Value_value_length = aux_Array_2_Value_value_length;
    wba_Seq_length = aux_Array_2_Seq_length;
    wba = aux_Array_2;
    CHECK_REF(7, LUMI_block0_cleanup, aab)
    if (SAFE_SUM_LARGER(0x02, 0x04, aab_Length)) RAISE(7, LUMI_block0_cleanup, slice_index)
    aux_Array_3 = aab + 0x02 * aab_Value_length * aab_Value_value_length * aab_Value_value_value_length;
    aux_Array_3_Length = 0x04;
    aux_Array_3_Value_length = aab_Value_length;
    aux_Array_3_Value_value_length = aab_Value_value_length;
    aux_Array_3_Value_value_value_length = aab_Value_value_value_length;
    aux_Array_3_Seq_length = aab_Seq_length + 0x02 * aab_Value_length * aab_Value_value_length;
    aux_Array_3_Refman = aab_Refman;
    LUMI_inc_ref(aux_Array_3_Refman);
    LUMI_inc_ref(aux_Array_3_Refman);
    LUMI_dec_ref(wbaa_Refman);
    wbaa_Refman = aux_Array_3_Refman;
    wbaa_Length = 0x04;
    wbaa_Value_length = aux_Array_3_Value_length;
    wbaa_Value_value_length = aux_Array_3_Value_value_length;
    wbaa_Value_value_value_length = aux_Array_3_Value_value_value_length;
    wbaa_Seq_length = aux_Array_3_Seq_length;
    wbaa = aux_Array_3;
    free(aas_Seq_length);
    LUMI_owner_dec_ref(aas_Refman);
    aas_Refman = NULL;
    aas_Length = 0;
    aas_Value_length = 0;
    aas_Value_value_length = 0;
    aas_Value_value_value_length = 0;
    aas_Seq_length = NULL;
    aas = NULL;
/// @ test-slice-expression-13
uint32_t aai[0x08 * 0x07 * 0x06 * 0x05] = {0};
    uint32_t* ua = NULL;
    Seq_Length ua_Length = 0;
    Seq_Length ua_Value_length = 0;
    Seq_Length ua_Value_value_length = 0;
    uint32_t* uaa = NULL;
    Seq_Length uaa_Length = 0;
    Seq_Length uaa_Value_length = 0;
    Seq_Length uaa_Value_value_length = 0;
    Seq_Length uaa_Value_value_value_length = 0;
    uint32_t* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Seq_Length aux_Array_0_Value_length = 0;
    Seq_Length aux_Array_0_Value_value_length = 0;
    uint32_t* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    Seq_Length aux_Array_1_Value_length = 0;
    Seq_Length aux_Array_1_Value_value_length = 0;
    Seq_Length aux_Array_1_Value_value_value_length = 0;
    /* initializing aai */
    aux_Array_0 = aai + 0x03 * 0x07 * 0x06 * 0x05;
    aux_Array_0_Length = 0x07;
    aux_Array_0_Value_length = 0x06;
    aux_Array_0_Value_value_length = 0x05;
    ua_Length = 0x07;
    ua_Value_length = 0x06;
    ua_Value_value_length = 0x05;
    ua = aux_Array_0;
    aux_Array_1 = aai + 0x02 * 0x07 * 0x06 * 0x05;
    aux_Array_1_Length = 0x04;
    aux_Array_1_Value_length = 0x07;
    aux_Array_1_Value_value_length = 0x06;
    aux_Array_1_Value_value_value_length = 0x05;
    uaa_Length = 0x04;
    uaa_Value_length = 0x07;
    uaa_Value_value_length = 0x06;
    uaa_Value_value_value_length = 0x05;
    uaa = aux_Array_1;
/// @ test-slice-expression-14
char aas[0x08 * 0x07 * 0x06 * 0x05] = {0};
    Seq_Length aas_Seq_length[0x08 * 0x07 * 0x06] = {0};
    char* usa = NULL;
    Seq_Length usa_Length = 0;
    Seq_Length usa_Value_length = 0;
    Seq_Length usa_Value_value_length = 0;
    Seq_Length* usa_Seq_length = NULL;
    char* usaa = NULL;
    Seq_Length usaa_Length = 0;
    Seq_Length usaa_Value_length = 0;
    Seq_Length usaa_Value_value_length = 0;
    Seq_Length usaa_Value_value_value_length = 0;
    Seq_Length* usaa_Seq_length = NULL;
    Byte aab[0x08 * 0x07 * 0x06 * 0x05] = {0};
    Seq_Length aab_Seq_length[0x08 * 0x07 * 0x06] = {0};
    Byte* uba = NULL;
    Seq_Length uba_Length = 0;
    Seq_Length uba_Value_length = 0;
    Seq_Length uba_Value_value_length = 0;
    Seq_Length* uba_Seq_length = NULL;
    Byte* ubaa = NULL;
    Seq_Length ubaa_Length = 0;
    Seq_Length ubaa_Value_length = 0;
    Seq_Length ubaa_Value_value_length = 0;
    Seq_Length ubaa_Value_value_value_length = 0;
    Seq_Length* ubaa_Seq_length = NULL;
    char* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Seq_Length aux_Array_0_Value_length = 0;
    Seq_Length aux_Array_0_Value_value_length = 0;
    Seq_Length* aux_Array_0_Seq_length = NULL;
    char* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    Seq_Length aux_Array_1_Value_length = 0;
    Seq_Length aux_Array_1_Value_value_length = 0;
    Seq_Length aux_Array_1_Value_value_value_length = 0;
    Seq_Length* aux_Array_1_Seq_length = NULL;
    Byte* aux_Array_2 = NULL;
    Seq_Length aux_Array_2_Length = 0;
    Seq_Length aux_Array_2_Value_length = 0;
    Seq_Length aux_Array_2_Value_value_length = 0;
    Seq_Length* aux_Array_2_Seq_length = NULL;
    Byte* aux_Array_3 = NULL;
    Seq_Length aux_Array_3_Length = 0;
    Seq_Length aux_Array_3_Value_length = 0;
    Seq_Length aux_Array_3_Value_value_length = 0;
    Seq_Length aux_Array_3_Value_value_value_length = 0;
    Seq_Length* aux_Array_3_Seq_length = NULL;
    /* initializing aas */
    if (ut_M_i >= 0x08) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = aas + ut_M_i * 0x07 * 0x06 * 0x05;
    aux_Array_0_Length = 0x07;
    aux_Array_0_Value_length = 0x06;
    aux_Array_0_Value_value_length = 0x05;
    aux_Array_0_Seq_length = aas_Seq_length + ut_M_i * 0x07 * 0x06;
    usa_Length = 0x07;
    usa_Value_length = 0x06;
    usa_Value_value_length = 0x05;
    usa_Seq_length = aux_Array_0_Seq_length;
    usa = aux_Array_0;
    aux_Array_1 = aas + 0x02 * 0x07 * 0x06 * 0x05;
    aux_Array_1_Length = 0x04;
    aux_Array_1_Value_length = 0x07;
    aux_Array_1_Value_value_length = 0x06;
    aux_Array_1_Value_value_value_length = 0x05;
    aux_Array_1_Seq_length = aas_Seq_length + 0x02 * 0x07 * 0x06;
    usaa_Length = 0x04;
    usaa_Value_length = 0x07;
    usaa_Value_value_length = 0x06;
    usaa_Value_value_value_length = 0x05;
    usaa_Seq_length = aux_Array_1_Seq_length;
    usaa = aux_Array_1;
    /* initializing aab */
    if (ut_M_i >= 0x08) RAISE(5, LUMI_block0_cleanup, slice_index)
    aux_Array_2 = aab + ut_M_i * 0x07 * 0x06 * 0x05;
    aux_Array_2_Length = 0x07;
    aux_Array_2_Value_length = 0x06;
    aux_Array_2_Value_value_length = 0x05;
    aux_Array_2_Seq_length = aab_Seq_length + ut_M_i * 0x07 * 0x06;
    uba_Length = 0x07;
    uba_Value_length = 0x06;
    uba_Value_value_length = 0x05;
    uba_Seq_length = aux_Array_2_Seq_length;
    uba = aux_Array_2;
    aux_Array_3 = aab + 0x02 * 0x07 * 0x06 * 0x05;
    aux_Array_3_Length = 0x04;
    aux_Array_3_Value_length = 0x07;
    aux_Array_3_Value_value_length = 0x06;
    aux_Array_3_Value_value_value_length = 0x05;
    aux_Array_3_Seq_length = aab_Seq_length + 0x02 * 0x07 * 0x06;
    ubaa_Length = 0x04;
    ubaa_Value_length = 0x07;
    ubaa_Value_value_length = 0x06;
    ubaa_Value_value_value_length = 0x05;
    ubaa_Seq_length = aux_Array_3_Seq_length;
    ubaa = aux_Array_3;
/// @ test-slice-expression-15
void ut_M_fun(void);
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    char aas[0x08 * 0x07 * 0x06 * 0x05] = {0};
    Seq_Length aas_Seq_length[0x08 * 0x07 * 0x06] = {0};
    char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    Byte aab[0x08 * 0x07 * 0x06 * 0x05] = {0};
    Seq_Length aab_Seq_length[0x08 * 0x07 * 0x06] = {0};
    Byte* b = NULL;
    Seq_Length b_Max_length = 0;
    Seq_Length* b_Length = &Lumi_empty_length;
    char* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Seq_Length aux_Array_0_Value_length = 0;
    Seq_Length aux_Array_0_Value_value_length = 0;
    Seq_Length* aux_Array_0_Seq_length = NULL;
    char* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    Seq_Length aux_Array_1_Value_length = 0;
    Seq_Length* aux_Array_1_Seq_length = NULL;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    Byte* aux_Array_2 = NULL;
    Seq_Length aux_Array_2_Length = 0;
    Seq_Length aux_Array_2_Value_length = 0;
    Seq_Length aux_Array_2_Value_value_length = 0;
    Seq_Length* aux_Array_2_Seq_length = NULL;
    Byte* aux_Array_3 = NULL;
    Seq_Length aux_Array_3_Length = 0;
    Seq_Length aux_Array_3_Value_length = 0;
    Seq_Length* aux_Array_3_Seq_length = NULL;
    Byte* aux_Buffer_0 = NULL;
    Seq_Length aux_Buffer_0_Max_length = 0;
    Seq_Length* aux_Buffer_0_Length = &Lumi_empty_length;
    /* initializing aas */
    aux_Array_0 = aas + 0x04 * 0x07 * 0x06 * 0x05;
    aux_Array_0_Length = 0x07;
    aux_Array_0_Value_length = 0x06;
    aux_Array_0_Value_value_length = 0x05;
    aux_Array_0_Seq_length = aas_Seq_length + 0x04 * 0x07 * 0x06;
    aux_Array_1 = (aux_Array_0) + 0x03 * 0x06 * 0x05;
    aux_Array_1_Length = 0x06;
    aux_Array_1_Value_length = 0x05;
    aux_Array_1_Seq_length = aux_Array_0_Seq_length + 0x03 * 0x06;
    aux_String_0 = (aux_Array_1) + 0x02 * 0x05;
    aux_String_0_Max_length = 0x05;
    aux_String_0_Length = aux_Array_1_Seq_length + 0x02;
    s_Max_length = 0x05;
    s_Length = aux_String_0_Length;
    s = aux_String_0;
    /* initializing aab */
    aux_Array_2 = aab + 0x04 * 0x07 * 0x06 * 0x05;
    aux_Array_2_Length = 0x07;
    aux_Array_2_Value_length = 0x06;
    aux_Array_2_Value_value_length = 0x05;
    aux_Array_2_Seq_length = aab_Seq_length + 0x04 * 0x07 * 0x06;
    aux_Array_3 = (aux_Array_2) + 0x03 * 0x06 * 0x05;
    aux_Array_3_Length = 0x06;
    aux_Array_3_Value_length = 0x05;
    aux_Array_3_Seq_length = aux_Array_2_Seq_length + 0x03 * 0x06;
    aux_Buffer_0 = (aux_Array_3) + 0x02 * 0x05;
    aux_Buffer_0_Max_length = 0x05;
    aux_Buffer_0_Length = aux_Array_3_Seq_length + 0x02;
    b_Max_length = 0x05;
    b_Length = aux_Buffer_0_Length;
    b = aux_Buffer_0;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-slice-expression-16
Char* x = NULL;
    Seq_Length x_Length = 0;
    Byte* y = NULL;
    Seq_Length y_Length = 0;
    x_Length = *(ut_M_ostr_Length);
    x = ut_M_ostr;
    y_Length = *(ut_M_buff_Length);
    y = ut_M_buff;
/// @ test-slice-expression-17
char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    Byte* bf = NULL;
    Seq_Length bf_Max_length = 0;
    Seq_Length* bf_Length = &Lumi_empty_length;
    INIT_NEW_SEQUENCE(1, LUMI_block0_cleanup, s, char, 0x0c);
    LUMI_err = sys_M_print(s, *s_Length);
    CHECK(2, LUMI_block0_cleanup)
    INIT_NEW_SEQUENCE(3, LUMI_block0_cleanup, bf, Byte, 0x0c);
/// @ test-slice-expression-18
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    Seq_Length s_Max_length;
    Seq_Length* s_Length;
    Byte* b;
    Seq_Length b_Max_length;
    Seq_Length* b_Length;
};
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    Buffer_Del(self->b);
    free(self->b);
    String_Del(self->s);
    free(self->s);
}
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {0};
    ut_M_Test* t = NULL;
    ut_M_Test a[0x06] = {0};
    t = &t_Var;
    /* initializing a */
LUMI_block0_cleanup:
    (void)0;
    ARRAY_DEL(ut_M_Test, a, 0x06)
    ut_M_Test_Del(t);
}
/// @ test-slice-expression-19
uint32_t* a = NULL;
    Seq_Length a_Length = 0;
    int8_t x = 0;
    int8_t y = 0;
    uint8_t length = 0;
    uint32_t* aa = NULL;
    Seq_Length aa_Length = 0;
    uint8_t xx = 0;
    uint8_t yy = 0;
    uint32_t ab[0x0c] = {0};
    uint32_t* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    uint32_t* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    uint32_t* aux_Array_2 = NULL;
    Seq_Length aux_Array_2_Length = 0;
    uint32_t* aux_Array_3 = NULL;
    Seq_Length aux_Array_3_Length = 0;
    uint32_t* aux_Array_4 = NULL;
    Seq_Length aux_Array_4_Length = 0;
    uint32_t* aux_Array_5 = NULL;
    Seq_Length aux_Array_5_Length = 0;
    uint32_t* aux_Array_6 = NULL;
    Seq_Length aux_Array_6_Length = 0;
    if (ut_M_i <= 0) RAISE(1, LUMI_block0_cleanup, sequence_too_short)
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, a, uint32_t, ut_M_i, 1);
    if (x < 0 || x <= 0 || SAFE_SUM_LARGER(x, x, ut_M_i)) RAISE(4, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = a + x;
    aux_Array_0_Length = x;
    if (y < 0 || (y + 0x01) <= 0) RAISE(4, LUMI_block0_cleanup, slice_index)
    aux_Array_1 = (aux_Array_0) + y;
    aux_Array_1_Length = y + 0x01;
    if (x < 0 || x >= y + 0x01) RAISE(4, LUMI_block0_cleanup, slice_index)
    if (SAFE_SUM_LARGER(ut_M_i, (ut_M_i + 0x01), ut_M_i)) RAISE(4, LUMI_block0_cleanup, slice_index)
    aux_Array_2 = a + ut_M_i;
    aux_Array_2_Length = ut_M_i + 0x01;
    if ((y + 0x01) <= 0) RAISE(4, LUMI_block0_cleanup, slice_index)
    aux_Array_3 = (aux_Array_2) + 0;
    aux_Array_3_Length = y + 0x01;
    if (y < 0) RAISE(4, LUMI_block0_cleanup, slice_index)
    aux_Array_4 = a + 0;
    aux_Array_4_Length = 0x01;
    if (ut_M_i >= 0x01) RAISE(4, LUMI_block0_cleanup, slice_index)
    ut_M_i = (((((aux_Array_1)[x]) + ((aux_Array_3)[y])) + ((aux_Array_4)[ut_M_i])) > UINT32_MAX)? UINT32_MAX: ((((aux_Array_1)[x]) + ((aux_Array_3)[y])) + ((aux_Array_4)[ut_M_i]));
    INIT_NEW_ARRAY(6, LUMI_block0_cleanup, aa, uint32_t, length, 1);
    xx = 0x0a;
    aux_Array_5 = aa + xx;
    aux_Array_5_Length = xx;
    ut_M_i = (aux_Array_5)[yy];
    /* initializing ab */
    aux_Array_6 = ab + 0x03;
    aux_Array_6_Length = 0x04;
    ut_M_i = (aux_Array_6)[0x03];
/// @ test-slice-expression-20
Char* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Byte* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    CHECK_REF(1, LUMI_block0_cleanup, str)
    if (0x02 >= *(str_Length)) RAISE(1, LUMI_block0_cleanup, slice_index)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    if (0x02 >= *(ut_M_buff_Length)) RAISE(1, LUMI_block0_cleanup, slice_index)
    CHECK_REF(1, LUMI_block0_cleanup, str)
    if (SAFE_SUM_LARGER(0x01, 0x03, *(str_Length))) RAISE(1, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = str + 0x01;
    aux_Array_0_Length = 0x03;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    if (SAFE_SUM_LARGER(0x01, 0x03, *(ut_M_buff_Length))) RAISE(1, LUMI_block0_cleanup, slice_index)
    aux_Array_1 = ut_M_buff + 0x01;
    aux_Array_1_Length = 0x03;
    ut_M_i = (((str[0x02]) + (ut_M_buff[0x02])) + ((aux_Array_0)[0x02])) + ((aux_Array_1)[0x02]);
/// @ test-slice-expression-e0
expected "]", got "new-line"
/// @ test-slice-expression-e1
expected "]", got "new-line"
/// @ test-slice-expression-e2
cannot slice a void expression
/// @ test-slice-expression-e3
cannot slice type "Int"
/// @ test-slice-expression-e4
expected integer index for slice, got "String"
/// @ test-slice-expression-e5
expected integer index for slice, got "String"
/// @ test-slice-expression-e6
expected integer index for slice, got void expression
/// @ test-slice-expression-e7
assigning into non assignable expression
/// @ test-slice-expression-e8
assigning into non assignable expression
/// @ test-slice-expression-e9
assigning into non assignable expression
/// @ test-slice-expression-e10
assigning into an owner a non-owner access "user"
/// @ test-slice-expression-e11
array of type with constructor "Tc"
/// @ test-slice-expression-e12
array of type with constructor "Test"
/// @ test-slice-expression-e13
ignoring slice bounds check
/// @ test-slice-expression-e14
sequence length is not positive
/// @ test-slice-expression-e15
slice index always negative with maximum value of "-0x01"
/// @ test-slice-expression-e16
slice index always negative with maximum value of "-0x02"
/// @ test-slice-expression-e17
slice length never positive with maximum value of "0x00"
/// @ test-slice-expression-e18
slice length never positive with maximum value of "0x00"
/// @ test-slice-expression-e19
slice minimal length "0x04" is larger than sequence maximal size "0x03"
/// @ test-slice-expression-e20
slice minimal length "0x10" is larger than sequence maximal size "0x0a"
/// @@ test-call-expression
/// @ test-call-expression-0
ut_M_fun0();
/// @ test-call-expression-1
ut_M_fun1(0x03, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, NULL, 0, &Lumi_empty_length);
/// @ test-call-expression-2
ut_M_fun2(&(*so), &(*so_Max_length), &(*so_Length), &(*so_Refman), &(*io));
/// @ test-call-expression-3
uint32_t x = 0;
    char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    Ref_Manager* s_Refman = NULL;
    ut_M_fun2(&(s), &(s_Max_length), &(s_Length), &(s_Refman), &(x));
/// @ test-call-expression-4
ut_M_fun3(0, &(*so), &(*so_Max_length), &(*so_Length), &(*so_Refman));
/// @ test-call-expression-5
uint32_t x = 0;
    ut_M_fun5(0x03, &(x));
    ut_M_fun4(x);
/// @ test-call-expression-6
ut_M_fun6(0x02, 0x03, &(*io), &(*io));
/// @ test-call-expression-7
uint32_t aux_Int_0 = 0;
    ut_M_fun5(0x04, &(aux_Int_0));
/// @ test-call-expression-8
uint32_t aux_Int_0 = 0;
    ut_M_fun5(0x04, &(aux_Int_0));
    *io = aux_Int_0;
/// @ test-call-expression-9
char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    Ref_Manager* aux_String_0_Refman = NULL;
    ut_M_fun3(0x07, &(aux_String_0), &(aux_String_0_Max_length), &(aux_String_0_Length), &(aux_String_0_Refman));
    String_Del(*so);
    LUMI_owner_dec_ref(*so_Refman);
    *so_Refman = aux_String_0_Refman;
    *so_Max_length = aux_String_0_Max_length;
    *so_Length = aux_String_0_Length;
    *so = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Refman = NULL;
    aux_String_0_Length = &Lumi_empty_length;
/// @ test-call-expression-10
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_t_Refman)
    ut_M_Test_meth(ut_M_t);
/// @ test-call-expression-11
ut_M_Test_meth(*to);
/// @ test-call-expression-12
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    ut_M_Tc_methc(ut_M_tc, ut_M_tc_Dynamic);
/// @ test-call-expression-13
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    ut_M_Tb_methb(&(ut_M_tc->_base), &(ut_M_tc_Dynamic->_base));
/// @ test-call-expression-14
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    ut_M_Test_meth(&(ut_M_tc->_base._base._base));
/// @ test-call-expression-15
LUMI_inc_ref(ut_M_tc_Refman);
    LUMI_dec_ref(*tco_Refman);
    *tco_Refman = ut_M_tc_Refman;
    *tco_Dynamic = ut_M_tc_Dynamic;
    *tco = ut_M_tc;
    CHECK_REFMAN(2, LUMI_block0_cleanup, *tco_Refman)
    ut_M_Test_meth(&((*tco)->_base._base._base));
/// @ test-call-expression-16
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_t->t_Refman)
    ut_M_Test_meth(ut_M_t->t);
/// @ test-call-expression-17
LUMI_var_dec_ref(*so_Refman);
    ut_M_fun1(0x03, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, *so, *so_Max_length, *so_Length);
    *so = NULL;
    *so_Refman = NULL;
    *so_Length = &Lumi_empty_length;
/// @ test-call-expression-18
char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    Ref_Manager* aux_String_0_Refman = NULL;
    uint32_t aux_Int_0 = 0;
    ut_M_fun3(0x01, &(aux_String_0), &(aux_String_0_Max_length), &(aux_String_0_Length), &(aux_String_0_Refman));
    ut_M_fun5(0x02, &(aux_Int_0));
/// @ test-call-expression-19
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Base {
    uint32_t x;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
    Return_Code (*meth)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, ut_M_Base* b, ut_M_Base_Dynamic* b_Dynamic);
};
struct ut_M_Test {
    ut_M_Base _base;
};
struct ut_M_Test_Dynamic {
    ut_M_Base_Dynamic _base;
};
Return_Code ut_M_Base_meth(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, ut_M_Base* b, ut_M_Base_Dynamic* b_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
Return_Code ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, ut_M_Base* b, ut_M_Base_Dynamic* b_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_meth};
ut_M_Test_Dynamic ut_M_Test_dynamic = {{(Dynamic_Del)ut_M_Test_Del, (Return_Code (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, ut_M_Base* b, ut_M_Base_Dynamic* b_Dynamic))ut_M_Test_meth}};
Return_Code ut_M_Base_meth(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, ut_M_Base* b, ut_M_Base_Dynamic* b_Dynamic) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    if (b_Dynamic != NULL) b_Dynamic->_del(b, b_Dynamic);
    free(b);
    return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
Return_Code ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, ut_M_Base* b, ut_M_Base_Dynamic* b_Dynamic) {
    Return_Code LUMI_err = OK;
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
    if (t_Dynamic != NULL) t_Dynamic->_base._del(t, t_Dynamic);
    free(t);
    if (b_Dynamic != NULL) b_Dynamic->_del(b, b_Dynamic);
    free(b);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), &(self_Dynamic->_base));
}
/// @ test-call-expression-20
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
Return_Code ut_M_mock(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
Return_Code ut_M_mock(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic) {
    Return_Code LUMI_err = OK;
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
/// @ test-call-expression-21
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    Return_Code (*meth)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic);
};
Return_Code ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
Return_Code ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic) {
    Return_Code LUMI_err = OK;
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
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
/// @ test-call-expression-22
void ut_M_fun(char** astr, Seq_Length* astr_Length, Seq_Length* astr_Value_length, Seq_Length** astr_Seq_length);
void ut_M_fun(char** astr, Seq_Length* astr_Length, Seq_Length* astr_Value_length, Seq_Length** astr_Seq_length) {
    unsigned LUMI_loop_depth = 1;
    ut_M_fun(&(*astr), &(*astr_Length), &(*astr_Value_length), &(*astr_Seq_length));
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-call-expression-23
Return_Code ut_M_fun(char* s, Seq_Length s_Max_length, Seq_Length* s_Length);
Return_Code ut_M_fun(char* s, Seq_Length s_Max_length, Seq_Length* s_Length) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char vars[0x0c] = {0};
    Seq_Length vars_Length[1] = {0};
    char s_vars[0x0c] = {0};
    Seq_Length s_vars_Length[1] = {0};
    Ref_Manager* s_vars_Refman = NULL;
    char* owners = NULL;
    Seq_Length owners_Max_length = 0;
    Seq_Length* owners_Length = &Lumi_empty_length;
    char* strongs = NULL;
    Seq_Length strongs_Max_length = 0;
    Seq_Length* strongs_Length = &Lumi_empty_length;
    Ref_Manager* strongs_Refman = NULL;
    char* users = NULL;
    Seq_Length users_Max_length = 0;
    Seq_Length* users_Length = &Lumi_empty_length;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    char* aux_String_1 = NULL;
    Seq_Length aux_String_1_Max_length = 0;
    Seq_Length* aux_String_1_Length = &Lumi_empty_length;
    /* initializing vars */
    INIT_VAR_REFMAN(3, LUMI_block0_cleanup, s_vars)
    INIT_NEW_SEQUENCE(4, LUMI_block0_cleanup, aux_String_0, char, 0x0c);
    owners_Max_length = 0x0c;
    owners_Length = aux_String_0_Length;
    owners = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
    INIT_NEW_SEQUENCE(5, LUMI_block0_cleanup, aux_String_1, char, 0x0c);
    strongs_Max_length = 0x0c;
    strongs_Length = aux_String_1_Length;
    strongs = aux_String_1;
    aux_String_1 = NULL;
    aux_String_1_Length = &Lumi_empty_length;
    INIT_NEW_REFMAN(5, LUMI_block0_cleanup, strongs)
    users_Max_length = s_Max_length;
    users_Length = s_Length;
    users = s;
    LUMI_err = ut_M_fun(s, s_Max_length, s_Length);
    CHECK(7, LUMI_block0_cleanup)
    LUMI_err = ut_M_fun(vars, 0x0c, vars_Length);
    CHECK(8, LUMI_block0_cleanup)
    LUMI_err = ut_M_fun(s_vars, 0x0c, s_vars_Length);
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
/// @ test-call-expression-24
char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    Ref_Manager* s_Refman = NULL;
    char* sw = NULL;
    Seq_Length sw_Max_length = 0;
    Seq_Length* sw_Length = &Lumi_empty_length;
    Ref_Manager* sw_Refman = NULL;
    CHECK_REFMAN(3, LUMI_block0_cleanup, sw_Refman)
    LUMI_var_dec_ref(s_Refman);
    ut_M_fun1(0, sw, sw_Max_length, sw_Length, s, s_Max_length, s_Length);
    s = NULL;
    s_Refman = NULL;
    s_Length = &Lumi_empty_length;
/// @ test-call-expression-25
char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    Ref_Manager* aux_String_0_Refman = NULL;
    aux_String_0 = ut_M_ostr;
    ut_M_ostr = NULL;
    ut_M_ostr_Length = &Lumi_empty_length;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, aux_String_0)
    ut_M_fun8(aux_String_0, aux_String_0_Max_length, aux_String_0_Length, aux_String_0_Refman);
    aux_String_0 = NULL;
    aux_String_0_Refman = NULL;
    aux_String_0_Length = &Lumi_empty_length;
/// @ test-call-expression-26
LUMI_err = ut_M_fune();
    CHECK(1, LUMI_block0_cleanup)
/// @ test-call-expression-27
uint8_t u8 = 0;
    int8_t s8 = 0;
    uint32_t u32 = 0;
    int32_t s32 = 0;
    uint64_t u64 = 0;
    int64_t s64 = 0;
    uint32_t aux_Int_0 = 0;
    uint32_t aux_Int_1 = 0;
    uint32_t aux_Int_2 = 0;
    uint32_t aux_Int_3 = 0;
    uint32_t aux_Int_4 = 0;
    ut_M_fun5(0, &(aux_Int_0));
    u8 = (aux_Int_0 > 0xff)? 0xff: aux_Int_0;
    ut_M_fun5(0x01, &(aux_Int_1));
    s8 = (aux_Int_1 > 0x7f)? 0x7f: aux_Int_1;
    ut_M_fun5(0x32, &(u32));
    ut_M_fun5(0x02, &(aux_Int_2));
    s32 = (aux_Int_2 > INT32_MAX)? INT32_MAX: aux_Int_2;
    ut_M_fun5(0x03, &(aux_Int_3));
    u64 = aux_Int_3;
    ut_M_fun5(0x04, &(aux_Int_4));
    s64 = aux_Int_4;
/// @ test-call-expression-e0
expected access, got " "
/// @ test-call-expression-e1
expected space after "user", got ")"
/// @ test-call-expression-e2
expected space or new-line after ",", got "c"
/// @ test-call-expression-e3
expected "," or ")", got "new-line"
/// @ test-call-expression-e4
illegal access "error"
/// @ test-call-expression-e5
void expression is not callable
/// @ test-call-expression-e6
non callable type "Int"
/// @ test-call-expression-e7
non assignable call output
/// @ test-call-expression-e8
cannot assign "Tb" into "Tc"
/// @ test-call-expression-e9
cannot assign void expression
/// @ test-call-expression-e10
expected access "copy" , got "user"
/// @ test-call-expression-e11
assigning into an owner a non-owner access "user"
/// @ test-call-expression-e12
assigning into an owner a non-owner access "user"
/// @ test-call-expression-e13
assigning into access "weak" invalid access "strong"
/// @ test-call-expression-e14
too many parameters
/// @ test-call-expression-e15
too few parameters
/// @ test-call-expression-e16
too many outputs
/// @ test-call-expression-e17
too few outputs
/// @ test-call-expression-e18
passing ownership of type "Test" into static type "Base"
/// @ test-call-expression-e19
assigning into an owner a non-owner access "var"
/// @ test-call-expression-e20
assigning into a weak reference an illegal access "owner"
/// @ test-call-expression-e21
ignoring error result check on function call
/// @ test-call-expression-e22
error raised inside function not declared as error raising "fun"
/// @ test-call-expression-e23
assigning conditional into non-conditional type "String"
/// @@ test-type-expression
/// @ test-type-expression-0
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_t_Refman)
    ut_M_Test_meth(ut_M_t);
/// @ test-type-expression-1
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    ut_M_Tb_methb(&(ut_M_tc->_base), &(ut_M_tc_Dynamic->_base));
/// @ test-type-expression-2
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    ut_M_Test_meth(&(ut_M_tc->_base._base._base));
/// @ test-type-expression-3
unknown type "Error"
/// @@ test-base-expression
/// @ test-base-expression-0
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Top ut_M_Top;
struct ut_M_Base {
    uint32_t x;
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
/// @ test-base-expression-1
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Top ut_M_Top;
struct ut_M_Base {
    uint32_t x;
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
/// @ test-base-expression-e0
"base" used not in method
/// @ test-base-expression-e1
no base type for type "Test"
/// @ test-base-expression-e2
no base method for method "mock"
/// @ test-base-expression-e3
assigning into non assignable expression
/// @ test-base-expression-e4
calling "base" with non-method "x"
/// @@ test-block-expression
/// @ test-block-expression-0
ut_M_i = 0x02 + (0x7b);
/// @ test-block-expression-1
ut_M_i = 0x7b;
/// @ test-block-expression-2
ut_M_i = (((0x7b * (ut_M_i - 0x04)) + 0x02) < 0)? 0: ((((0x7b * (ut_M_i - 0x04)) + 0x02) > UINT32_MAX)? UINT32_MAX: ((0x7b * (ut_M_i - 0x04)) + 0x02));
/// @ test-block-expression-3
expected ")", got "new-line"
/// @@ test-unary-expression
/// @ test-unary-expression-0
ut_M_j = - ut_M_j;
/// @ test-unary-expression-1
ut_M_j = - ut_M_j;
/// @ test-unary-expression-2
ut_M_i = - (- ut_M_i);
/// @ test-unary-expression-3
ut_M_b = ! ut_M_b;
/// @ test-unary-expression-4
ut_M_b = ! (ut_M_i > 0x03);
/// @ test-unary-expression-5
ut_M_i = ((ut_M_i + 0x01) > UINT32_MAX)? UINT32_MAX: (ut_M_i + 0x01);
/// @ test-unary-expression-6
ut_M_j = ((ut_M_j - 0x01) < -INT32_MAX)? -INT32_MAX: (ut_M_j - 0x01);
/// @ test-unary-expression-7
int8_t x = 0;
    x = (ut_M_j < -0x7f)? -0x7f: ((ut_M_j > 0x7f)? 0x7f: ut_M_j);
    x = (ut_M_j < -0x7f)? -0x7f: ((ut_M_j > 0x7f)? 0x7f: ut_M_j);
/// @ test-unary-expression-8
if ((ut_M_i + 0x01) > UINT32_MAX) RAISE(1, LUMI_block0_cleanup, integer_overflow)
    ut_M_i = ut_M_i + 0x01;
/// @ test-unary-expression-9
if ((ut_M_j - 0x01) < -INT32_MAX) RAISE(1, LUMI_block0_cleanup, integer_overflow)
    ut_M_j = ut_M_j - 0x01;
/// @ test-unary-expression-10
if ((ut_M_j * 0x02) < -INT32_MAX || (ut_M_j * 0x02) > INT32_MAX) RAISE(1, LUMI_block0_cleanup, integer_overflow)
    ut_M_j = ut_M_j * 0x02;
/// @ test-unary-expression-11
++LUMI_trace_ignore_count;
    if ((ut_M_i + 0x01) > UINT32_MAX) RAISE(1, LUMI_block2_cleanup, integer_overflow)
    ut_M_i = ut_M_i + 0x01;
LUMI_block2_cleanup:
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        ut_M_i = 0x0c;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-unary-expression-12
ut_M_Tb* ttb = NULL;
    ut_M_Tb_Dynamic* ttb_Dynamic = &ut_M_Tb_dynamic;
    ut_M_Tb* aux_Tb_0 = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = &ut_M_Tb_dynamic;
    ut_M_fun4(((ut_M_i + 0x01) > UINT32_MAX)? UINT32_MAX: (ut_M_i + 0x01));
    INIT_NEW(2, LUMI_block0_cleanup, ttb, ut_M_Tb, 1);
    LUMI_err = ut_M_Tb_new(ttb, ttb_Dynamic, ((ut_M_i + 0x01) > UINT32_MAX)? UINT32_MAX: (ut_M_i + 0x01));
    CHECK(2, LUMI_block0_cleanup)
    INIT_NEW(3, LUMI_block0_cleanup, aux_Tb_0, ut_M_Tb, 1);
    LUMI_err = ut_M_Tb_new(aux_Tb_0, aux_Tb_0_Dynamic, ((ut_M_i + 0x01) > UINT32_MAX)? UINT32_MAX: (ut_M_i + 0x01));
    CHECK(3, LUMI_block0_cleanup)
    if (ttb_Dynamic != NULL) ttb_Dynamic->_base._del(ttb, ttb_Dynamic);
    free(ttb);
    ttb_Dynamic = aux_Tb_0_Dynamic;
    ttb = aux_Tb_0;
    aux_Tb_0 = NULL;
    aux_Tb_0_Dynamic = NULL;
/// @ test-unary-expression-13
if ((ut_M_i + 0x01) > UINT32_MAX) RAISE(1, LUMI_block0_cleanup, integer_overflow)
    ut_M_fun4(ut_M_i + 0x01);
/// @ test-unary-expression-14
++LUMI_trace_ignore_count;
    if ((ut_M_i + 0x01) > UINT32_MAX) RAISE(1, LUMI_block2_cleanup, integer_overflow)
    ut_M_fun4(ut_M_i + 0x01);
LUMI_block2_cleanup:
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        ut_M_i = 0x0c;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-unary-expression-e0
expected expression, got "{"
/// @ test-unary-expression-e1
expected space after "-", got "["
/// @ test-unary-expression-e2
used non-unary operator "+"
/// @ test-unary-expression-e3
void expression given as operand to operator "-"
/// @ test-unary-expression-e4
operator "-" expected "Int" operand, got "Bool"
/// @ test-unary-expression-e5
operator "not" expected "Bool" operand, got "Int"
/// @ test-unary-expression-e6
misplaced use of "clamp"
/// @ test-unary-expression-e7
misplaced use of "clamp"
/// @ test-unary-expression-e8
unnecessary use of "clamp"
/// @ test-unary-expression-e9
unnecessary use of "clamp"
/// @ test-unary-expression-e10
using "?" where error is propagated
/// @ test-unary-expression-e11
error raised inside function not declared as error raising "error"
/// @ test-unary-expression-e12
using "?" where error is propagated
/// @ test-unary-expression-e13
misplaced use of "clamp"
/// @ test-unary-expression-e14
misplaced use of "clamp"
/// @@ test-binary-expression
/// @ test-binary-expression-0
ut_M_i = 0x17 + 0x36;
/// @ test-binary-expression-1
ut_M_i = CLAMPED_ADD_UU(ut_M_i, ((0x64 * 0x02) - 0x25), 0, UINT32_MAX);
    ut_M_i = CLAMPED_MUL_UU(ut_M_i, 0x03, 0, UINT32_MAX);
/// @ test-binary-expression-2
ut_M_i = CLAMPED_SUB_UU(ut_M_i, (0x0c * 0x0d), 0, UINT32_MAX);
/// @ test-binary-expression-3
ut_M_b = (0x03 < 0x05) || (0x17 > 0x25);
/// @ test-binary-expression-4
ut_M_b = (0x03 <= 0x05) && (0x17 >= 0x25);
/// @ test-binary-expression-5
ut_M_b = (ut_M_i == 0x05) || (ut_M_i != 0x25);
/// @ test-binary-expression-6
ut_M_b = ((0x02 < ut_M_i) && (ut_M_i < 0x0c)) && (0x0c == (-0x02 * ut_M_i));
/// @ test-binary-expression-7
LUMI_inc_ref(ut_M_tc_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = ut_M_tc_Refman;
    ut_M_t = &(ut_M_tc->_base._base._base);
/// @ test-binary-expression-8
char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    String_Del(s);
    free(s);
    LUMI_var_dec_ref(*so_Refman);
    s_Max_length = *so_Max_length;
    s_Length = *so_Length;
    s = *so;
    *so = NULL;
    *so_Refman = NULL;
    *so_Length = &Lumi_empty_length;
/// @ test-binary-expression-9
str_Max_length = *so_Max_length;
    str_Length = *so_Length;
    str = *so;
/// @ test-binary-expression-10
ut_M_b = ((void*)ut_M_t == ut_M_ta) || ((void*)ut_M_tc != ut_M_tb);
/// @ test-binary-expression-11
ut_M_c = '0' + 0x04;
/// @ test-binary-expression-12
ut_M_b = (void*)ut_M_fun0 != ut_M_fun1;
/// @ test-binary-expression-13
ut_M_b = ut_M_b == ut_M_b;
/// @ test-binary-expression-14
ut_M_Tc* otc = NULL;
    ut_M_Tc_Dynamic* otc_Dynamic = NULL;
    if (ut_M_tb_Dynamic != NULL) ut_M_tb_Dynamic->_base._del(ut_M_tb, ut_M_tb_Dynamic);
    LUMI_owner_dec_ref(ut_M_tb_Refman);
    ut_M_tb_Dynamic = &(otc_Dynamic->_base);
    ut_M_tb = &(otc->_base);
    otc = NULL;
    otc_Dynamic = NULL;
    INIT_NEW_REFMAN(2, LUMI_block0_cleanup, ut_M_tb)
/// @ test-binary-expression-15
ut_M_Test* otarr = NULL;
    Seq_Length otarr_Length = 0;
    ARRAY_DEL(ut_M_Test, otarr, otarr_Length)
    free(otarr);
    otarr_Length = 0;
    otarr = NULL;
/// @ test-binary-expression-16
if (ut_M_i == 0) RAISE(1, LUMI_block0_cleanup, zero_division)
    if (ut_M_i == 0) RAISE(1, LUMI_block0_cleanup, zero_division)
    *io = (0x3c / ut_M_i) + (0x3c % ut_M_i);
/// @ test-binary-expression-17
ut_M_i = ut_M_i | 0x08;
/// @ test-binary-expression-18
ut_M_i = 0x0a & ut_M_i;
/// @ test-binary-expression-19
uint8_t i8 = 0;
    uint64_t i64 = 0;
    i8 = 0x04;
    i64 = 0x174876e800;
    ut_M_i = CLAMPED_ADD_UU((CLAMPED_ADD_UU(((uint32_t)(~ ut_M_i)), ((uint8_t)(~ i8)), 0, UINT32_MAX)), ((uint64_t)(~ i64)), 0, UINT32_MAX);
/// @ test-binary-expression-20
ut_M_i = ut_M_i ^ 0x10;
/// @ test-binary-expression-21
ut_M_i = 0x02 >> ut_M_i;
/// @ test-binary-expression-22
ut_M_i = ut_M_i << 0x01;
/// @ test-binary-expression-23
ut_M_i = ((((uint32_t)(~ ut_M_i)) + (0x0a & ut_M_i)) > UINT32_MAX)? UINT32_MAX: (((uint32_t)(~ ut_M_i)) + (0x0a & ut_M_i));
/// @ test-binary-expression-24
uint8_t x = 0;
    x = 0x01;
    *io = (0x3c / x) + (0x0258 % x);
/// @ test-binary-expression-25
ut_M_i = CLAMPED_ADD_UU(ut_M_i, ut_M_i, 0, UINT32_MAX);
    ut_M_i = CLAMPED_ADD_US(ut_M_i, ut_M_j, 0, UINT32_MAX);
    ut_M_j = CLAMPED_ADD_SU(ut_M_j, ut_M_i, -INT32_MAX, INT32_MAX);
    ut_M_j = CLAMPED_ADD_SS(ut_M_j, ut_M_j, -INT32_MAX, INT32_MAX);
/// @ test-binary-expression-26
ut_M_i = CLAMPED_SUB_UU(ut_M_i, ut_M_i, 0, UINT32_MAX);
    ut_M_i = CLAMPED_SUB_US(ut_M_i, ut_M_j, 0, UINT32_MAX);
    ut_M_j = CLAMPED_SUB_SU(ut_M_j, ut_M_i, -INT32_MAX, INT32_MAX);
    ut_M_j = CLAMPED_SUB_SS(ut_M_j, ut_M_j, -INT32_MAX, INT32_MAX);
/// @ test-binary-expression-27
ut_M_i = CLAMPED_MUL_UU(ut_M_i, ut_M_i, 0, UINT32_MAX);
    ut_M_i = CLAMPED_MUL_US(ut_M_i, ut_M_j, 0, UINT32_MAX);
    ut_M_j = CLAMPED_MUL_SU(ut_M_j, ut_M_i, -INT32_MAX, INT32_MAX);
    ut_M_j = CLAMPED_MUL_SS(ut_M_j, ut_M_j, -INT32_MAX, INT32_MAX);
/// @ test-binary-expression-e0
unknown operator "@"
/// @ test-binary-expression-e1
expected space after "+", got "("
/// @ test-binary-expression-e2
ambiguous precedence between operators "+" and "*"
/// @ test-binary-expression-e3
ambiguous precedence between operators "or" and "and"
/// @ test-binary-expression-e4
used non-binary operator "not"
/// @ test-binary-expression-e5
assigning into non assignable expression
/// @ test-binary-expression-e6
assigning into non assignable expression
/// @ test-binary-expression-e7
assigning into non assignable expression
/// @ test-binary-expression-e8
assigning into an owner a non-owner access "user"
/// @ test-binary-expression-e9
operator "or" expected "Bool" operand, got "Int"
/// @ test-binary-expression-e10
operator ">" expected "Int" operand, got "Test"
/// @ test-binary-expression-e11
operator ">" expected "Int" operand, got "Test"
/// @ test-binary-expression-e12
operator "+" expected "Int" operand, got "Test"
/// @ test-binary-expression-e13
operator "clamp+=" expected "Int" operand, got "Test"
/// @ test-binary-expression-e14
operator "clamp-=" expected "Int" operand, got "Bool"
/// @ test-binary-expression-e15
operator "is" is not supported for type "Int"
/// @ test-binary-expression-e16
non matching subtypes "Int" and "Char"
/// @ test-binary-expression-e17
passing ownership of type "Tb" into static type "Test"
/// @ test-binary-expression-e18
operator "is" is not supported for type "Bool"
/// @ test-binary-expression-e19
operator "<" expected "Int" operand, got "Bool"
/// @ test-binary-expression-e20
assigning into a weak reference an illegal access "user"
/// @ test-binary-expression-e21
ignoring empty reference check
/// @ test-binary-expression-e22
ignoring zero division check
/// @ test-binary-expression-e23
ignoring zero division check
/// @ test-binary-expression-e24
dividing by zero
/// @ test-binary-expression-e25
dividing by zero
/// @ test-binary-expression-e26
bitwize operation on signed integer with minimum value of "-0x0a"
/// @ test-binary-expression-e27
bitwize operation on signed integer with minimum value of "-0x0a"
/// @ test-binary-expression-e28
bitwize operation on signed integer with minimum value of "-0x0a"
/// @ test-binary-expression-e29
bitwize operation on signed integer with minimum value of "-0x0a"
/// @ test-binary-expression-e30
bitwize operation on signed integer with minimum value of "-0x0a"
/// @ test-binary-expression-e31
bitwize operation on signed integer with minimum value of "-0x0a"
/// @ test-binary-expression-e32
division operation on signed integer with minimum value of "-0x0a"
/// @ test-binary-expression-e33
division operation on signed integer with minimum value of "-0x0a"
/// @@ test-swap-expression
/// @ test-swap-expression-0
ut_M_Test* t1 = NULL;
    ut_M_Test* t2 = NULL;
    ut_M_Test* aux_Test_0 = NULL;
    INIT_NEW(1, LUMI_block0_cleanup, t1, ut_M_Test, 1);
    INIT_NEW(2, LUMI_block0_cleanup, t2, ut_M_Test, 1);
    aux_Test_0 = t1;
    t1 = t2;
    t2 = aux_Test_0;
    aux_Test_0 = NULL;
/// @ test-swap-expression-1
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
/// @ test-swap-expression-2
ut_M_Tc* t1 = NULL;
    ut_M_Tc_Dynamic* t1_Dynamic = &ut_M_Tc_dynamic;
    ut_M_Tc* t2 = NULL;
    ut_M_Tc_Dynamic* t2_Dynamic = &ut_M_Tc_dynamic;
    ut_M_Tc* aux_Tc_0 = NULL;
    ut_M_Tc_Dynamic* aux_Tc_0_Dynamic = NULL;
    INIT_NEW(1, LUMI_block0_cleanup, t1, ut_M_Tc, 1);
    LUMI_err = ut_M_Tb_new(&(t1->_base), &(t1_Dynamic->_base), 0x01);
    CHECK(1, LUMI_block0_cleanup)
    INIT_NEW(2, LUMI_block0_cleanup, t2, ut_M_Tc, 1);
    LUMI_err = ut_M_Tb_new(&(t2->_base), &(t2_Dynamic->_base), 0x02);
    CHECK(2, LUMI_block0_cleanup)
    aux_Tc_0_Dynamic = t1_Dynamic;
    aux_Tc_0 = t1;
    t1_Dynamic = t2_Dynamic;
    t1 = t2;
    t2_Dynamic = aux_Tc_0_Dynamic;
    t2 = aux_Tc_0;
    aux_Tc_0 = NULL;
    aux_Tc_0_Dynamic = NULL;
/// @ test-swap-expression-3
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
    LUMI_err = ut_M_Tb_new(&(aux_Tc_0->_base), &(aux_Tc_0_Dynamic->_base), 0x01);
    CHECK(1, LUMI_block0_cleanup)
    t1_Dynamic = aux_Tc_0_Dynamic;
    t1 = aux_Tc_0;
    aux_Tc_0 = NULL;
    aux_Tc_0_Dynamic = NULL;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, t1)
    INIT_NEW(2, LUMI_block0_cleanup, aux_Tc_1, ut_M_Tc, 1);
    LUMI_err = ut_M_Tb_new(&(aux_Tc_1->_base), &(aux_Tc_1_Dynamic->_base), 0x02);
    CHECK(2, LUMI_block0_cleanup)
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
/// @ test-swap-expression-4
uint32_t* a1 = NULL;
    Seq_Length a1_Length = 0;
    uint32_t* a2 = NULL;
    Seq_Length a2_Length = 0;
    uint32_t* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, a1, uint32_t, 0x04, 1);
    INIT_NEW_ARRAY(2, LUMI_block0_cleanup, a2, uint32_t, 0x06, 1);
    aux_Array_0_Length = 0x04;
    aux_Array_0 = a1;
    a1_Length = 0x06;
    a1 = a2;
    a2_Length = 0x04;
    a2 = aux_Array_0;
    aux_Array_0 = NULL;
/// @ test-swap-expression-5
uint32_t* a1 = NULL;
    Seq_Length a1_Length = 0;
    Ref_Manager* a1_Refman = NULL;
    uint32_t* a2 = NULL;
    Seq_Length a2_Length = 0;
    Ref_Manager* a2_Refman = NULL;
    uint32_t* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    uint32_t* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    uint32_t* aux_Array_2 = NULL;
    Seq_Length aux_Array_2_Length = 0;
    Ref_Manager* aux_Array_2_Refman = NULL;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, aux_Array_0, uint32_t, 0x04, 1);
    a1_Length = 0x04;
    a1 = aux_Array_0;
    aux_Array_0 = NULL;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, a1)
    INIT_NEW_ARRAY(2, LUMI_block0_cleanup, aux_Array_1, uint32_t, 0x06, 1);
    a2_Length = 0x06;
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
/// @ test-swap-expression-6
char* s1 = NULL;
    Seq_Length s1_Max_length = 0;
    Seq_Length* s1_Length = &Lumi_empty_length;
    char* s2 = NULL;
    Seq_Length s2_Max_length = 0;
    Seq_Length* s2_Length = &Lumi_empty_length;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    INIT_NEW_SEQUENCE(1, LUMI_block0_cleanup, s1, char, 0x04);
    INIT_NEW_SEQUENCE(2, LUMI_block0_cleanup, s2, char, 0x06);
    aux_String_0_Max_length = 0x04;
    aux_String_0_Length = s1_Length;
    aux_String_0 = s1;
    s1_Max_length = 0x06;
    s1_Length = s2_Length;
    s1 = s2;
    s2_Max_length = 0x04;
    s2_Length = aux_String_0_Length;
    s2 = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
/// @ test-swap-expression-7
char* s1 = NULL;
    Seq_Length s1_Max_length = 0;
    Seq_Length* s1_Length = &Lumi_empty_length;
    Ref_Manager* s1_Refman = NULL;
    char* s2 = NULL;
    Seq_Length s2_Max_length = 0;
    Seq_Length* s2_Length = &Lumi_empty_length;
    Ref_Manager* s2_Refman = NULL;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    char* aux_String_1 = NULL;
    Seq_Length aux_String_1_Max_length = 0;
    Seq_Length* aux_String_1_Length = &Lumi_empty_length;
    char* aux_String_2 = NULL;
    Seq_Length aux_String_2_Max_length = 0;
    Seq_Length* aux_String_2_Length = &Lumi_empty_length;
    Ref_Manager* aux_String_2_Refman = NULL;
    INIT_NEW_SEQUENCE(1, LUMI_block0_cleanup, aux_String_0, char, 0x04);
    s1_Max_length = 0x04;
    s1_Length = aux_String_0_Length;
    s1 = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, s1)
    INIT_NEW_SEQUENCE(2, LUMI_block0_cleanup, aux_String_1, char, 0x06);
    s2_Max_length = 0x06;
    s2_Length = aux_String_1_Length;
    s2 = aux_String_1;
    aux_String_1 = NULL;
    aux_String_1_Length = &Lumi_empty_length;
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
    aux_String_2_Length = &Lumi_empty_length;
/// @ test-swap-expression-8
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_Test {
    ut_M_MyStruct* f;
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self);
void ut_M_Test_new(ut_M_Test* self, ut_M_MyStruct* f);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(ut_M_Test* t1, ut_M_Test* t2);
Generic_Type_Dynamic ut_M_MyStruct_dynamic = {(Dynamic_Del)ut_M_MyStruct_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_MyStruct_Del(ut_M_MyStruct* self) {
    if (self == NULL) return;
}
void ut_M_Test_new(ut_M_Test* self, ut_M_MyStruct* f) {
    unsigned LUMI_loop_depth = 1;
    ut_M_MyStruct_Del(self->f);
    free(self->f);
    self->f = f;
    f = NULL;
LUMI_block0_cleanup:
    (void)0;
    ut_M_MyStruct_Del(f);
    free(f);
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_MyStruct_Del(self->f);
    free(self->f);
}
void ut_M_fun(ut_M_Test* t1, ut_M_Test* t2) {
    unsigned LUMI_loop_depth = 1;
    ut_M_MyStruct* aux_MyStruct_0 = NULL;
    aux_MyStruct_0 = t1->f;
    t1->f = t2->f;
    t2->f = aux_MyStruct_0;
    aux_MyStruct_0 = NULL;
LUMI_block0_cleanup:
    (void)0;
    ut_M_MyStruct_Del(aux_MyStruct_0);
    free(aux_MyStruct_0);
    ut_M_Test_Del(t2);
    free(t2);
    ut_M_Test_Del(t1);
    free(t1);
}
/// @ test-swap-expression-9
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
/// @ test-swap-expression-10
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
/// @ test-swap-expression-11
uint32_t aux_Int_0 = 0;
    aux_Int_0 = ut_M_i;
    ut_M_i = *io;
    *io = aux_Int_0;
/// @ test-swap-expression-12
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
/// @ test-swap-expression-e0
cannot swap access "weak" with other access "strong"
/// @ test-swap-expression-e1
swapping reference with itself
/// @ test-swap-expression-e2
conditionals not matching in type "String"
/// @ test-swap-expression-e3
swapping non assignable expression
/// @ test-swap-expression-e4
non matching types "Ta" and "Tc"
/// @ test-swap-expression-e5
cannot swap access "owner" with other access "strong"
/// @ test-swap-expression-e6
using invalid reference "invalid"
/// @ test-swap-expression-e7
using invalid reference "invalid"
/// @@ test-question-expression
/// @ test-question-expression-0
ut_M_b = ut_M_ostr != NULL;
/// @ test-question-expression-1
ut_M_b = ! (ut_M_arr != NULL && (ut_M_arr_Refman)->value != NULL);
/// @ test-question-expression-2
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    ut_M_b = ut_M_t->fun != NULL;
/// @ test-question-expression-3
ut_M_b = (*to) != NULL;
/// @ test-question-expression-4
ut_M_t = NULL;
    ut_M_t_Refman = NULL;
    ut_M_fun7(NULL, NULL, NULL, (void*)&(ut_M_t), &(ut_M_t_Refman), (void*)&(ut_M_t_Dynamic));
    ut_M_b = ut_M_t != NULL && (ut_M_t_Refman)->value != NULL;
/// @ test-question-expression-5
ut_M_Test* tt = NULL;
    Ref_Manager* tt_Refman = NULL;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_t)
    LUMI_inc_ref(ut_M_t_Refman);
    LUMI_dec_ref(tt_Refman);
    tt_Refman = ut_M_t_Refman;
    tt = ut_M_t;
    ut_M_b = (tt_Refman)->value != NULL;
/// @ test-question-expression-6
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    Seq_Length s_Max_length;
    Seq_Length* s_Length;
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
/// @ test-question-expression-e0
cannot use "?" on void expression
/// @ test-question-expression-e1
cannot use "?" on non conditional or weak reference of type "Int"
/// @ test-question-expression-e2
cannot use "?" on non conditional or weak reference of type "Test"
/// @@ test-exclamation-expression
/// @ test-exclamation-expression-0
char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    s_Max_length = ut_M_ostr_Max_length;
    s_Length = ut_M_ostr_Length;
    s = ut_M_ostr;
/// @ test-exclamation-expression-1
ut_M_Test* tt = NULL;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t->t, ut_M_t->t_Refman)
    tt = ut_M_t->t;
/// @ test-exclamation-expression-2
ut_M_Test* tu = NULL;
    ut_M_t = NULL;
    ut_M_t_Refman = NULL;
    ut_M_fun7(NULL, NULL, NULL, (void*)&(ut_M_t), &(ut_M_t_Refman), (void*)&(ut_M_t_Dynamic));
    CHECK_REFMAN(2, LUMI_block0_cleanup, ut_M_t_Refman)
    tu = &(ut_M_t->_base._base);
/// @ test-exclamation-expression-3
CHECK_REF(1, LUMI_block0_cleanup, ut_M_tb)
    ut_M_i = ut_M_tb->_base._base.num;
/// @ test-exclamation-expression-4
ut_M_Test* tt = NULL;
    Ref_Manager* tt_Refman = NULL;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_t)
    LUMI_inc_ref(ut_M_t_Refman);
    LUMI_dec_ref(tt_Refman);
    tt_Refman = ut_M_t_Refman;
    tt = ut_M_t;
/// @ test-exclamation-expression-5
char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    uint32_t aux_Int_0 = 0;
    CHECK_REF(1, LUMI_block0_cleanup, str)
    String_length(str, str_Max_length, str_Length, &(aux_Int_0));
    if (aux_Int_0 <= 0) RAISE(1, LUMI_block0_cleanup, sequence_too_short)
    INIT_NEW_SEQUENCE(1, LUMI_block0_cleanup, s, char, aux_Int_0);
/// @ test-exclamation-expression-e0
ignoring empty reference check
/// @ test-exclamation-expression-e1
ignoring weak reference check
/// @ test-exclamation-expression-e2
ignoring empty reference check
/// @ test-exclamation-expression-e3
ignoring weak reference check
/// @ test-exclamation-expression-e4
ignoring empty reference check
/// @ test-exclamation-expression-e5
ignoring weak reference check
/// @ test-exclamation-expression-e6
ignoring empty reference check
/// @ test-exclamation-expression-e7
ignoring empty reference check
/// @ test-exclamation-expression-e8
ignoring empty reference check
/// @ test-exclamation-expression-e9
ignoring weak reference check
/// @ test-exclamation-expression-e10
ignoring empty reference check
/// @ test-exclamation-expression-e11
ignoring initialization error check
/// @ test-exclamation-expression-eo0
only one "!" needed
/// @ test-exclamation-expression-en0
using "!" where there is no error
/// @ test-exclamation-expression-en1
using "!" where there is no error
/// @ test-exclamation-expression-en2
using "!" where there is no error
/// @ test-exclamation-expression-en3
using "!" where there is no error
/// @ test-exclamation-expression-en4
using "!" where there is no error
/// @ test-exclamation-expression-en5
using "!" where there is no error
/// @ test-exclamation-expression-en6
using "!" where there is no error
/// @ test-exclamation-expression-en7
using "!" where there is no error
/// @ test-exclamation-expression-en8
using "!" where there is no error
/// @ test-exclamation-expression-en9
using "!" where there is no error
/// @ test-exclamation-expression-en10
using "!" where there is no error
/// @ test-exclamation-expression-en11
using "!" where there is no error
/// @ test-exclamation-expression-en12
using "!" where there is no error
/// @ test-exclamation-expression-en13
using "!" where there is no error
/// @ test-exclamation-expression-en14
using "!" where there is no error
/// @ test-exclamation-expression-en15
using "!" where there is no error
/// @ test-exclamation-expression-en16
using "!" where there is no error
/// @ test-exclamation-expression-en17
using "!" where there is no error
/// @ test-exclamation-expression-en18
using "!" where there is no error
/// @ test-exclamation-expression-en19
using "!" where there is no error
/// @ test-exclamation-expression-en20
using "!" where there is no error
/// @ test-exclamation-expression-en21
using "!" where there is no error
/// @ test-exclamation-expression-en22
using "!" where there is no error
/// @ test-exclamation-expression-en23
using "!" where there is no error
/// @ test-exclamation-expression-en24
using "!" where there is no error
/// @ test-exclamation-expression-en26
using "!" where there is no error
/// @ test-exclamation-expression-en27
using "!" where there is no error
/// @ test-exclamation-expression-en28
using "!" where there is no error
/// @ test-exclamation-expression-en29
using "!" where there is no error
/// @ test-exclamation-expression-en30
using "!" where there is no error
/// @ test-exclamation-expression-en31
using "!" where there is no error
/// @ test-exclamation-expression-en32
using "!" where there is no error
/// @ test-exclamation-expression-en33
using "!" where there is no error
/// @@ test-int-range
/// @ test-int-range-0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t int_def;
    uint8_t u8b;
    uint16_t u16b;
    uint32_t u32b;
    uint64_t u64b;
    int8_t s8b;
    int16_t s16b;
    int32_t s32b;
    int64_t s64b;
    uint8_t ru8;
    uint16_t ru16;
    uint32_t ru32;
    uint64_t ru64;
    int8_t rs8;
    int16_t rs16;
    int32_t rs32;
    int64_t rs64;
};
void ut_M_Test_new(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_new(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    self->ru16 = 0x05;
    self->ru32 = 0x0f4240;
    self->rs32 = -0x0f4240;
    self->ru64 = 0x174876e800;
    self->rs64 = -0x174876e800;
    self->u8b = 0xff;
    self->s8b = 0x7f;
    self->s8b = -0x7f;
    self->u16b = UINT16_MAX;
    self->s16b = INT16_MAX;
    self->s16b = -INT16_MAX;
    self->u32b = UINT32_MAX;
    self->s32b = INT32_MAX;
    self->s32b = -INT32_MAX;
    self->u64b = UINT64_MAX;
    self->s64b = INT64_MAX;
    self->s64b = -INT64_MAX;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ test-int-range-1
uint8_t u8 = 0;
    uint16_t u16 = 0;
    uint32_t u32 = 0;
    uint64_t u64 = 0;
    int8_t s8 = 0;
    int16_t s16 = 0;
    int32_t s32 = 0;
    int64_t s64 = 0;
/// @ test-int-range-2
typedef struct ut_M_Test ut_M_Test;
enum {
    ut_M_Nums_MIN = 0,
    ut_M_Nums_length
};
enum { ut_M_MAX = 0x2710 };
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(ut_M_Test* t, uint32_t* x);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
int16_t ut_M_s16 = 0;
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_fun(ut_M_Test* t, uint32_t* x) {
    unsigned LUMI_loop_depth = 1;
    uint32_t aux_Int_0 = 0;
    ut_M_fun(t, &(aux_Int_0));
    *x = ((aux_Int_0 + t->x) > UINT32_MAX)? UINT32_MAX: (aux_Int_0 + t->x);
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-int-range-3
uint8_t u8 = 0;
    int16_t s16 = 0;
    uint32_t u32 = 0;
    uint16_t u16 = 0;
    int32_t s32 = 0;
    s16 = -0x03e8;
    u32 = 0x0186a0;
    u16 = 0x03e8;
    s32 = 0x0186a0;
    s32 = -0x0186a0;
    ut_M_i = 0x14 + -0x14;
/// @ test-int-range-e0
integer range minimum "0x0c" larger than maximum "0x0b"
/// @ test-int-range-e1
too high unsigned integer maximum "0x010000000000000000"
/// @ test-int-range-e2
too high signed integer maximum "0x8000000000000000"
/// @ test-int-range-e3
too low signed integer minimum "-0x8000000000000001"
/// @ test-int-range-e4
got "String" expression, expected "Int"
/// @ test-int-range-e5
integer range is not constant
/// @ test-int-range-e6
integer range minimum "0x00" larger than maximum "-0x64"
/// @ test-int-range-e7
assigning integer with minimum of "-0x7fffffff" into integer with larger minimum of "0x00"
/// @ test-int-range-e8
assigning integer with maximum of "0xffffffff" into integer with smaller maximum of "0x7fffffff"
/// @ test-int-range-e9
too high unsigned integer maximum "0x010000000000000000"
/// @@ test-dynamic
/// @ test-dynamic-0
ut_M_Ta a_Var = {{0}};
    ut_M_Ta* a = NULL;
    ut_M_Ta_Dynamic* a_Dynamic = &ut_M_Ta_dynamic;
    a = &a_Var;
/// @ test-dynamic-1
ut_M_Ta* a = NULL;
    ut_M_Ta_Dynamic* a_Dynamic = NULL;
/// @ test-dynamic-2
ut_M_Ta* nta = NULL;
    ut_M_Ta_Dynamic* nta_Dynamic = NULL;
    ut_M_Ta* aux_Ta_0 = NULL;
    ut_M_Ta_Dynamic* aux_Ta_0_Dynamic = &ut_M_Ta_dynamic;
    INIT_NEW(1, LUMI_block0_cleanup, aux_Ta_0, ut_M_Ta, 1);
    nta_Dynamic = aux_Ta_0_Dynamic;
    nta = aux_Ta_0;
    aux_Ta_0 = NULL;
    aux_Ta_0_Dynamic = NULL;
/// @ test-dynamic-3
ut_M_Ta* a = NULL;
    ut_M_Ta_Dynamic* a_Dynamic = &ut_M_Ta_dynamic;
    INIT_NEW(1, LUMI_block0_cleanup, a, ut_M_Ta, 1);
/// @ test-dynamic-4
ut_M_Ta* a = NULL;
    ut_M_Ta_Dynamic* a_Dynamic = NULL;
    CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_ta_Refman)
    a_Dynamic = ut_M_ta_Dynamic;
    a = ut_M_ta;
/// @ test-dynamic-5
ut_M_Ta* x = NULL;
    ut_M_Ta_Dynamic* x_Dynamic = NULL;
    CHECK_REFMAN(2, LUMI_block0_cleanup, ut_M_ta_Refman)
    x_Dynamic = ut_M_ta_Dynamic;
    x = ut_M_ta;
/// @ test-dynamic-6
LUMI_inc_ref(ut_M_tb_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = ut_M_tb_Refman;
    ut_M_ta_Dynamic = &(ut_M_tb_Dynamic->_base);
    ut_M_ta = &(ut_M_tb->_base);
/// @ test-dynamic-7
LUMI_inc_ref(ut_M_tc_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = ut_M_tc_Refman;
    ut_M_ta_Dynamic = &(ut_M_tc_Dynamic->_base._base);
    ut_M_ta = &(ut_M_tc->_base._base);
/// @ test-dynamic-8
LUMI_inc_ref(NULL);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = NULL;
    ut_M_ta_Dynamic = NULL;
    ut_M_ta = NULL;
/// @ test-dynamic-9
ut_M_Ta* aa = NULL;
    Seq_Length aa_Length = 0;
    Ref_Manager* aa_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, aa)
    if (0x04 >= aa_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aa_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = aa_Refman;
    ut_M_ta_Dynamic = &ut_M_Ta_dynamic;
    ut_M_ta = aa + 0x04;
/// @ test-dynamic-10
ut_M_Tc* ca = NULL;
    Seq_Length ca_Length = 0;
    Ref_Manager* ca_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, ca)
    if (0x04 >= ca_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(ca_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = ca_Refman;
    ut_M_ta_Dynamic = &(&ut_M_Tc_dynamic->_base._base);
    ut_M_ta = &((ca + 0x04)->_base._base);
/// @ test-dynamic-11
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_ta_Refman)
    if (ut_M_ta_Dynamic == NULL) RAISE(1, LUMI_block0_cleanup, empty_object)
    ut_M_ta_Dynamic->dyn(ut_M_ta, ut_M_ta_Dynamic);
/// @ test-dynamic-12
if (ut_M_tb_Dynamic == NULL) RAISE(1, LUMI_block0_cleanup, empty_object)
    ut_M_tb_Dynamic->_base.dyn(&(ut_M_tb->_base), &(ut_M_tb_Dynamic->_base));
/// @ test-dynamic-13
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    if (ut_M_tc_Dynamic == NULL) RAISE(1, LUMI_block0_cleanup, empty_object)
    ut_M_tc_Dynamic->_base._base.dyn(&(ut_M_tc->_base._base), &(ut_M_tc_Dynamic->_base._base));
/// @ test-dynamic-14
LUMI_inc_ref(ut_M_tc_Refman);
    LUMI_dec_ref(*tco_Refman);
    *tco_Refman = ut_M_tc_Refman;
    *tco_Dynamic = ut_M_tc_Dynamic;
    *tco = ut_M_tc;
    CHECK_REFMAN(2, LUMI_block0_cleanup, *tco_Refman)
    if (*tco_Dynamic == NULL) RAISE(2, LUMI_block0_cleanup, empty_object)
    (*tco_Dynamic)->_base._base.dyn(&((*tco)->_base._base), &((*tco_Dynamic)->_base._base));
/// @ test-dynamic-15
ut_M_ta = NULL;
    ut_M_ta_Refman = NULL;
    ut_M_ta_Dynamic = NULL;
    ut_M_fun7(&(ut_M_tc->_base), ut_M_tc_Refman, &(ut_M_tc_Dynamic->_base), (void*)&(ut_M_ta), &(ut_M_ta_Refman), (void*)&(ut_M_ta_Dynamic));
/// @ test-dynamic-16
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
Return_Code ut_M_mock(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
Return_Code ut_M_mock(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    CHECK_REF_REFMAN(5, LUMI_block0_cleanup, *t, *t_Refman)
    if (*t_Dynamic == NULL) RAISE(5, LUMI_block0_cleanup, empty_object)
    (*t_Dynamic)->meth(*t, *t_Dynamic);
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ test-dynamic-17
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Base {
    uint32_t x;
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
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Test_fun(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_meth};
ut_M_Test_Dynamic ut_M_Test_dynamic = {{(Dynamic_Del)ut_M_Test_Del, ut_M_Base_meth}};
void ut_M_Base_meth(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Test_fun(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    self_Dynamic->_base.meth(&(self->_base), &(self_Dynamic->_base));
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), &(self_Dynamic->_base));
}
/// @ test-dynamic-18
ut_M_Tb* aux_Tb_0 = NULL;
    Ref_Manager* aux_Tb_0_Refman = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = NULL;
    ut_M_fun7(NULL, NULL, NULL, &(aux_Tb_0), &(aux_Tb_0_Refman), &(aux_Tb_0_Dynamic));
/// @ test-dynamic-e0
ignoring empty reference check
/// @@ test-function-object
/// @ test-function-object-0
void (*fun)(void) = NULL;
    fun = ut_M_fun0;
    fun();
/// @ test-function-object-1
void (*fun)(uint32_t x, uint32_t* y) = NULL;
    uint32_t x = 0;
    fun = ut_M_fun5;
    fun(0x09, &(x));
/// @ test-function-object-2
void (*fun)(ut_M_Test* self) = NULL;
    fun = ut_M_Test_meth;
    CHECK_REFMAN(2, LUMI_block0_cleanup, ut_M_t_Refman)
    fun(ut_M_t);
/// @ test-function-object-3
void (*fun)(void) = NULL;
    fun = NULL;
    ut_M_b = fun != NULL;
    CHECK_REF(4, LUMI_block0_cleanup, fun)
    fun();
/// @ test-function-object-4
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    ut_M_t->fun = ut_M_fun0;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_t->fun)
    ut_M_t->fun();
/// @ test-function-object-5
void (*farr[0x26])(void) = {0};
    void (**farr1)(uint32_t x, uint32_t* y) = NULL;
    Seq_Length farr1_Length = 0;
    Return_Code (**farr2)(void) = NULL;
    Seq_Length farr2_Length = 0;
    Return_Code (**ufarr)(void) = NULL;
    Seq_Length ufarr_Length = 0;
    /* initializing farr */
    INIT_NEW_ARRAY(2, LUMI_block0_cleanup, farr1, void (*)(uint32_t x, uint32_t* y), 0x0c, 1);
    INIT_NEW_ARRAY(3, LUMI_block0_cleanup, farr2, Return_Code (*)(void), 0x0c, 1);
    farr[0x03] = ut_M_fun0;
    (farr[0x03])();
/// @ test-function-object-6
void (*fun)(uint32_t x, uint32_t y) = NULL;
/// @ test-function-object-7
void ut_M_fun(void);
void ut_M_mock(void (**f)(void));
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_mock(void (**f)(void)) {
    unsigned LUMI_loop_depth = 1;
    *f = ut_M_fun;
    (*f)();
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-object-8
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    void (*fun)(uint32_t x, uint32_t y);
    Return_Code (*afun[0x04])(uint32_t x, uint32_t* y);
};
void ut_M_Test_meth(ut_M_Test* self, Return_Code (*fi)(uint32_t x, uint32_t y), Return_Code (**fo)(uint32_t x, uint32_t y));
void ut_M_Test_Del(ut_M_Test* self);
Return_Code ut_M_fun(uint32_t x, uint32_t y);
void ut_M_mock(void (*fi)(uint32_t x, uint32_t y), Return_Code (**fo)(uint32_t x, uint32_t y));
void ut_M_afun(void (** in)(uint32_t x, uint32_t* y), Seq_Length in_Length, Return_Code (*** out)(void), Seq_Length* out_Length);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_meth(ut_M_Test* self, Return_Code (*fi)(uint32_t x, uint32_t y), Return_Code (**fo)(uint32_t x, uint32_t y)) {
    unsigned LUMI_loop_depth = 1;
    *fo = ut_M_fun;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
Return_Code ut_M_fun(uint32_t x, uint32_t y) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_mock(void (*fi)(uint32_t x, uint32_t y), Return_Code (**fo)(uint32_t x, uint32_t y)) {
    unsigned LUMI_loop_depth = 1;
    Return_Code (*aux_Func_0)(uint32_t x, uint32_t y) = NULL;
    ut_M_mock(NULL, &(aux_Func_0));
    *fo = ut_M_fun;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_afun(void (** in)(uint32_t x, uint32_t* y), Seq_Length in_Length, Return_Code (*** out)(void), Seq_Length* out_Length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-object-9
Return_Code (*fun)(void) = NULL;
    fun = ut_M_fune;
    LUMI_err = fun();
    CHECK(3, LUMI_block0_cleanup)
/// @ test-function-object-e0
missing arguments in function type
/// @ test-function-object-e1
missing arguments in function type
/// @ test-function-object-e2
expected "(" inside Function type, got "}"
/// @ test-function-object-e3
expected "}" after sub-types, got " "
/// @ test-function-object-e4
too many parameters
/// @ test-function-object-e5
too few outputs
/// @ test-function-object-e6
using invalid reference "fun"
/// @ test-function-object-e7
assigning empty into non-conditional type "Func"
/// @ test-function-object-e8
cannot use "?" on non conditional or weak reference of type "Func"
/// @ test-function-object-e9
non matching error result
/// @ test-function-object-e10
non matching error result
/// @@ test-builtin
/// @ test-builtin-int0
uint64_t u64 = 0;
    int64_t s64 = 0;
    CHECK_REF(3, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = Int_strU(u64, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length);
    CHECK(3, LUMI_block0_cleanup)
    CHECK_REF(4, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = Int_strS(s64, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length);
    CHECK(4, LUMI_block0_cleanup)
/// @ test-builtin-bool0
ut_M_b = true;
/// @ test-builtin-bool1
ut_M_b = false;
/// @ test-builtin-char0
unknown symbol "EOF"
/// @ test-builtin-array0
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    Array_length(ut_M_arr, ut_M_arr_Length, &(ut_M_i));
/// @ test-builtin-string0
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_length(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(ut_M_i));
/// @ test-builtin-string1
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_clear(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length);
/// @ test-builtin-string2
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_equal(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_ostr, *ut_M_ostr_Length, &(ut_M_b));
/// @ test-builtin-string3
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_get(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_i, &(ut_M_c));
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-string4
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_set(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_i, ut_M_c);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-string5
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_append(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_c);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-string6
char sv[0x0c] = {0};
    Seq_Length sv_Length[1] = {0};
    /* initializing sv */
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_copy(sv, 0x0c, sv_Length, ut_M_ostr, *ut_M_ostr_Length);
    CHECK(2, LUMI_block0_cleanup)
/// @ test-builtin-string7
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_concat(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_ostr, *ut_M_ostr_Length);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-string8
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_concat_int(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_i);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-string9
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_find(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_ostr, *ut_M_ostr_Length, &(ut_M_i));
/// @ test-builtin-string10
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_has(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_c, &(ut_M_b));
/// @ test-builtin-string11
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_set(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, 0, 'a');
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-string12
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_max_length(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(ut_M_i));
/// @ test-builtin-buffer0
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    Buffer_length(ut_M_buff, ut_M_buff_Max_length, ut_M_buff_Length, &(ut_M_i));
/// @ test-builtin-buffer1
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    Buffer_clear(ut_M_buff, ut_M_buff_Max_length, ut_M_buff_Length);
/// @ test-builtin-buffer2
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    Buffer_equal(ut_M_buff, ut_M_buff_Max_length, ut_M_buff_Length, ut_M_buff, *ut_M_buff_Length, &(ut_M_b));
/// @ test-builtin-buffer3
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    LUMI_err = Buffer_get(ut_M_buff, ut_M_buff_Max_length, ut_M_buff_Length, ut_M_i, &(ut_M_bt));
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-buffer4
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    LUMI_err = Buffer_set(ut_M_buff, ut_M_buff_Max_length, ut_M_buff_Length, ut_M_i, ut_M_bt);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-buffer5
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    LUMI_err = Buffer_append(ut_M_buff, ut_M_buff_Max_length, ut_M_buff_Length, ut_M_bt);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-buffer6
Byte bv[0x0c] = {0};
    Seq_Length bv_Length[1] = {0};
    /* initializing bv */
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_buff)
    LUMI_err = Buffer_copy(bv, 0x0c, bv_Length, ut_M_buff, *ut_M_buff_Length);
    CHECK(2, LUMI_block0_cleanup)
/// @ test-builtin-buffer7
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    LUMI_err = Buffer_concat(ut_M_buff, ut_M_buff_Max_length, ut_M_buff_Length, ut_M_buff, *ut_M_buff_Length);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-buffer8
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    Buffer_find(ut_M_buff, ut_M_buff_Max_length, ut_M_buff_Length, ut_M_buff, *ut_M_buff_Length, &(ut_M_i));
/// @ test-builtin-buffer9
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    Buffer_has(ut_M_buff, ut_M_buff_Max_length, ut_M_buff_Length, ut_M_bt, &(ut_M_b));
/// @ test-builtin-buffer10
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    LUMI_err = Buffer_set(ut_M_buff, ut_M_buff_Max_length, ut_M_buff_Length, 0, ut_M_bt);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-buffer11
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    Buffer_max_length(ut_M_buff, ut_M_buff_Max_length, ut_M_buff_Length, &(ut_M_i));
/// @ test-builtin-file0
{
        FileReadText f_Var = {0};
        FileReadText* f = NULL;
        Ref_Manager* f_Refman = NULL;
        uint64_t x = 0;
        ut_M_Data df_Var = {0};
        ut_M_Data* df = NULL;
        ++LUMI_trace_ignore_count;
        CHECK_REF(2, LUMI_block1_cleanup, ut_M_ostr)
        f = &f_Var;
        INIT_VAR_REFMAN(2, LUMI_block1_cleanup, f)
        LUMI_err = FileReadText_new(f, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length);
        CHECK(2, LUMI_block1_cleanup)
        LUMI_err = FileReadText_get(f, &(ut_M_c), &(ut_M_b));
        CHECK(3, LUMI_block1_cleanup)
        CHECK_REF(4, LUMI_block1_cleanup, ut_M_ostr)
        LUMI_err = FileReadText_getline(f, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(ut_M_b));
        CHECK(4, LUMI_block1_cleanup)
        LUMI_err = FileReadText_tell(f, &(x));
        CHECK(6, LUMI_block1_cleanup)
        LUMI_err = FileReadText_seek_set(f, x);
        CHECK(7, LUMI_block1_cleanup)
        LUMI_err = FileReadText_seek_cur(f, x);
        CHECK(8, LUMI_block1_cleanup)
        LUMI_err = FileReadText_seek_end(f, x);
        CHECK(9, LUMI_block1_cleanup)
        LUMI_err = FileReadText_flush(f);
        CHECK(10, LUMI_block1_cleanup)
        LUMI_err = FileReadText_close(f);
        CHECK(11, LUMI_block1_cleanup)
        df = &df_Var;
        LUMI_inc_ref(f_Refman);
        LUMI_dec_ref(df->item_Refman);
        df->item_Refman = f_Refman;
        df->item_Dynamic = &FileReadText_dynamic;
        df->item = f;
    LUMI_block1_cleanup:
        (void)0;
    ut_M_Data_Del(df);
    FileReadText_Del(f);
        LUMI_var_dec_ref(f_Refman);
    }
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
    LUMI_block2_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-builtin-file1
{
        FileReadBinary* f = NULL;
        uint64_t x = 0;
        ut_M_Data df_Var = {0};
        ut_M_Data* df = NULL;
        ++LUMI_trace_ignore_count;
        CHECK_REF(2, LUMI_block1_cleanup, ut_M_ostr)
        INIT_NEW(2, LUMI_block1_cleanup, f, FileReadBinary, 1);
        LUMI_err = FileReadBinary_new(f, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length);
        CHECK(2, LUMI_block1_cleanup)
        LUMI_err = FileReadBinary_get(f, &(ut_M_bt), &(ut_M_b));
        CHECK(3, LUMI_block1_cleanup)
        CHECK_REF(4, LUMI_block1_cleanup, ut_M_buff)
        LUMI_err = FileReadBinary_read(f, ut_M_buff, *ut_M_buff_Length, &(ut_M_i));
        CHECK(4, LUMI_block1_cleanup)
        LUMI_err = FileReadBinary_tell(f, &(x));
        CHECK(6, LUMI_block1_cleanup)
        LUMI_err = FileReadBinary_seek_set(f, x);
        CHECK(7, LUMI_block1_cleanup)
        LUMI_err = FileReadBinary_seek_cur(f, x);
        CHECK(8, LUMI_block1_cleanup)
        LUMI_err = FileReadBinary_seek_end(f, x);
        CHECK(9, LUMI_block1_cleanup)
        LUMI_err = FileReadBinary_flush(f);
        CHECK(10, LUMI_block1_cleanup)
        LUMI_err = FileReadBinary_close(f);
        CHECK(11, LUMI_block1_cleanup)
        df = &df_Var;
        ut_M_Data_set(df, f, &FileReadBinary_dynamic);
        f = NULL;
    LUMI_block1_cleanup:
        (void)0;
    ut_M_Data_Del(df);
    FileReadBinary_Del(f);
        free(f);
    }
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
    LUMI_block2_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-builtin-file2
{
        FileWriteText* f = NULL;
        uint64_t x = 0;
        ut_M_Data df_Var = {0};
        ut_M_Data* df = NULL;
        FileWriteText* aux_FileWriteText_0 = NULL;
        ++LUMI_trace_ignore_count;
        CHECK_REF(2, LUMI_block1_cleanup, ut_M_ostr)
        INIT_NEW(2, LUMI_block1_cleanup, aux_FileWriteText_0, FileWriteText, 1);
        LUMI_err = FileWriteText_new(aux_FileWriteText_0, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, false);
        CHECK(2, LUMI_block1_cleanup)
        f = aux_FileWriteText_0;
        aux_FileWriteText_0 = NULL;
        LUMI_err = FileWriteText_put(f, ut_M_c);
        CHECK(3, LUMI_block1_cleanup)
        CHECK_REF(4, LUMI_block1_cleanup, ut_M_ostr)
        LUMI_err = FileWriteText_write(f, ut_M_ostr, *ut_M_ostr_Length, &(ut_M_i));
        CHECK(4, LUMI_block1_cleanup)
        LUMI_err = FileWriteText_tell(f, &(x));
        CHECK(6, LUMI_block1_cleanup)
        LUMI_err = FileWriteText_seek_set(f, x);
        CHECK(7, LUMI_block1_cleanup)
        LUMI_err = FileWriteText_seek_cur(f, x);
        CHECK(8, LUMI_block1_cleanup)
        LUMI_err = FileWriteText_seek_end(f, x);
        CHECK(9, LUMI_block1_cleanup)
        LUMI_err = FileWriteText_flush(f);
        CHECK(10, LUMI_block1_cleanup)
        LUMI_err = FileWriteText_close(f);
        CHECK(11, LUMI_block1_cleanup)
        df = &df_Var;
        ut_M_Data_set(df, f, &FileWriteText_dynamic);
        f = NULL;
    LUMI_block1_cleanup:
        (void)0;
    FileWriteText_Del(aux_FileWriteText_0);
        free(aux_FileWriteText_0);
    ut_M_Data_Del(df);
    FileWriteText_Del(f);
        free(f);
    }
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
    LUMI_block2_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-builtin-file3
{
        FileWriteBinary* f = NULL;
        Ref_Manager* f_Refman = NULL;
        uint64_t x = 0;
        ut_M_Data df_Var = {0};
        ut_M_Data* df = NULL;
        FileWriteBinary* aux_FileWriteBinary_0 = NULL;
        ++LUMI_trace_ignore_count;
        CHECK_REF(2, LUMI_block1_cleanup, ut_M_ostr)
        INIT_NEW(2, LUMI_block1_cleanup, aux_FileWriteBinary_0, FileWriteBinary, 1);
        LUMI_err = FileWriteBinary_new(aux_FileWriteBinary_0, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, true);
        CHECK(2, LUMI_block1_cleanup)
        f = aux_FileWriteBinary_0;
        aux_FileWriteBinary_0 = NULL;
        INIT_NEW_REFMAN(2, LUMI_block1_cleanup, f)
        LUMI_err = FileWriteBinary_put(f, ut_M_bt);
        CHECK(3, LUMI_block1_cleanup)
        CHECK_REF(4, LUMI_block1_cleanup, ut_M_buff)
        LUMI_err = FileWriteBinary_write(f, ut_M_buff, *ut_M_buff_Length, &(ut_M_i));
        CHECK(4, LUMI_block1_cleanup)
        LUMI_err = FileWriteBinary_tell(f, &(x));
        CHECK(6, LUMI_block1_cleanup)
        LUMI_err = FileWriteBinary_seek_set(f, x);
        CHECK(7, LUMI_block1_cleanup)
        LUMI_err = FileWriteBinary_seek_cur(f, x);
        CHECK(8, LUMI_block1_cleanup)
        LUMI_err = FileWriteBinary_seek_end(f, x);
        CHECK(9, LUMI_block1_cleanup)
        LUMI_err = FileWriteBinary_flush(f);
        CHECK(10, LUMI_block1_cleanup)
        LUMI_err = FileWriteBinary_close(f);
        CHECK(11, LUMI_block1_cleanup)
        df = &df_Var;
        LUMI_inc_ref(f_Refman);
        LUMI_dec_ref(df->item_Refman);
        df->item_Refman = f_Refman;
        df->item_Dynamic = &FileWriteBinary_dynamic;
        df->item = f;
    LUMI_block1_cleanup:
        (void)0;
    FileWriteBinary_Del(aux_FileWriteBinary_0);
        free(aux_FileWriteBinary_0);
    ut_M_Data_Del(df);
    FileWriteBinary_Del(f);
        LUMI_owner_dec_ref(f_Refman);
    }
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
    LUMI_block2_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-builtin-file4
{
        FileReadWriteText f_Var = {0};
        FileReadWriteText* f = NULL;
        Ref_Manager* f_Refman = NULL;
        uint64_t x = 0;
        ut_M_Data df_Var = {0};
        ut_M_Data* df = NULL;
        ++LUMI_trace_ignore_count;
        CHECK_REF(2, LUMI_block1_cleanup, ut_M_ostr)
        f = &f_Var;
        INIT_VAR_REFMAN(2, LUMI_block1_cleanup, f)
        LUMI_err = FileReadWriteText_new(f, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, true, true);
        CHECK(2, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteText_get(f, &(ut_M_c), &(ut_M_b));
        CHECK(3, LUMI_block1_cleanup)
        CHECK_REF(4, LUMI_block1_cleanup, ut_M_ostr)
        LUMI_err = FileReadWriteText_getline(f, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(ut_M_b));
        CHECK(4, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteText_put(f, ut_M_c);
        CHECK(5, LUMI_block1_cleanup)
        CHECK_REF(6, LUMI_block1_cleanup, ut_M_ostr)
        LUMI_err = FileReadWriteText_write(f, ut_M_ostr, *ut_M_ostr_Length, &(ut_M_i));
        CHECK(6, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteText_tell(f, &(x));
        CHECK(8, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteText_seek_set(f, x);
        CHECK(9, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteText_seek_cur(f, x);
        CHECK(10, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteText_seek_end(f, x);
        CHECK(11, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteText_flush(f);
        CHECK(12, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteText_close(f);
        CHECK(13, LUMI_block1_cleanup)
        df = &df_Var;
        LUMI_inc_ref(f_Refman);
        LUMI_dec_ref(df->item_Refman);
        df->item_Refman = f_Refman;
        df->item_Dynamic = &FileReadWriteText_dynamic;
        df->item = f;
    LUMI_block1_cleanup:
        (void)0;
    ut_M_Data_Del(df);
    FileReadWriteText_Del(f);
        LUMI_var_dec_ref(f_Refman);
    }
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
    LUMI_block2_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-builtin-file5
{
        FileReadWriteBinary* f = NULL;
        uint64_t x = 0;
        ut_M_Data df_Var = {0};
        ut_M_Data* df = NULL;
        ++LUMI_trace_ignore_count;
        CHECK_REF(2, LUMI_block1_cleanup, ut_M_ostr)
        INIT_NEW(2, LUMI_block1_cleanup, f, FileReadWriteBinary, 1);
        LUMI_err = FileReadWriteBinary_new(f, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, false, false);
        CHECK(2, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteBinary_get(f, &(ut_M_bt), &(ut_M_b));
        CHECK(3, LUMI_block1_cleanup)
        CHECK_REF(4, LUMI_block1_cleanup, ut_M_buff)
        LUMI_err = FileReadWriteBinary_read(f, ut_M_buff, *ut_M_buff_Length, &(ut_M_i));
        CHECK(4, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteBinary_put(f, ut_M_bt);
        CHECK(5, LUMI_block1_cleanup)
        CHECK_REF(6, LUMI_block1_cleanup, ut_M_buff)
        LUMI_err = FileReadWriteBinary_write(f, ut_M_buff, *ut_M_buff_Length, &(ut_M_i));
        CHECK(6, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteBinary_tell(f, &(x));
        CHECK(8, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteBinary_seek_set(f, x);
        CHECK(9, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteBinary_seek_cur(f, x);
        CHECK(10, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteBinary_seek_end(f, x);
        CHECK(11, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteBinary_flush(f);
        CHECK(12, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteBinary_close(f);
        CHECK(13, LUMI_block1_cleanup)
        df = &df_Var;
        ut_M_Data_set(df, f, &FileReadWriteBinary_dynamic);
        f = NULL;
    LUMI_block1_cleanup:
        (void)0;
    ut_M_Data_Del(df);
    FileReadWriteBinary_Del(f);
        free(f);
    }
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
    LUMI_block2_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-builtin-file6
typedef struct ut_M_Data ut_M_Data;
struct ut_M_Data {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
void ut_M_Data_set(ut_M_Data* self, Generic_Type* item, Generic_Type_Dynamic* item_Dynamic);
void ut_M_Data_Del(ut_M_Data* self);
Return_Code ut_M_fun(File* f, FileReadText* frt, FileReadBinary* frb, FileWriteText* fwt, FileWriteBinary* fwb, FileReadWriteText* frwt, FileReadWriteBinary* frwb);
Generic_Type_Dynamic ut_M_Data_dynamic = {(Dynamic_Del)ut_M_Data_Del};
void ut_M_Data_set(ut_M_Data* self, Generic_Type* item, Generic_Type_Dynamic* item_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    if (item_Dynamic != NULL) item_Dynamic->_del(item, item_Dynamic);
    free(item);
}
void ut_M_Data_Del(ut_M_Data* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Return_Code ut_M_fun(File* f, FileReadText* frt, FileReadBinary* frb, FileWriteText* fwt, FileWriteBinary* fwb, FileReadWriteText* frwt, FileReadWriteBinary* frwb) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Data df_Var = {0};
    ut_M_Data* df = NULL;
    File* fo = NULL;
    uint64_t i = 0;
    FileWriteBinary* aux_FileWriteBinary_0 = NULL;
    static char aux_String_0[] = {'n','a','m','e','\0',};
    Seq_Length aux_String_0_Max_length = sizeof(aux_String_0);
    Seq_Length aux_String_0_Length[1] = {sizeof(aux_String_0) - 1};
    f = frt;
    f = frb;
    f = fwt;
    f = fwb;
    f = frwt;
    f = frwb;
    frt = frwt;
    frb = frwb;
    fwt = frwt;
    fwb = frwb;
    LUMI_err = ut_M_fun(frt, frwt, frwb, frwt, frwb, frwt, frwb);
    CHECK(22, LUMI_block0_cleanup)
    df = &df_Var;
    INIT_NEW(31, LUMI_block0_cleanup, aux_FileWriteBinary_0, FileWriteBinary, 1);
    LUMI_err = FileWriteBinary_new(aux_FileWriteBinary_0, aux_String_0, aux_String_0_Max_length, aux_String_0_Length, false);
    CHECK(31, LUMI_block0_cleanup)
    fo = aux_FileWriteBinary_0;
    aux_FileWriteBinary_0 = NULL;
    LUMI_err = File_tell(fo, &(i));
    CHECK(33, LUMI_block0_cleanup)
    LUMI_err = File_seek_set(fo, i);
    CHECK(34, LUMI_block0_cleanup)
    LUMI_err = File_seek_cur(fo, i);
    CHECK(35, LUMI_block0_cleanup)
    LUMI_err = File_seek_end(fo, i);
    CHECK(36, LUMI_block0_cleanup)
    LUMI_err = File_flush(fo);
    CHECK(37, LUMI_block0_cleanup)
    LUMI_err = File_close(fo);
    CHECK(38, LUMI_block0_cleanup)
    ut_M_Data_set(df, fo, &File_dynamic);
    fo = NULL;
LUMI_block0_cleanup:
    (void)0;
    FileWriteBinary_Del(aux_FileWriteBinary_0);
    free(aux_FileWriteBinary_0);
    File_Del(fo);
    free(fo);
    ut_M_Data_Del(df);
    return LUMI_err;
}
/// @ test-builtin-sys0
char* argv = NULL;
    Seq_Length argv_Length = 0;
    Seq_Length argv_Value_length = 0;
    Seq_Length* argv_Seq_length = NULL;
    argv_Length = sys_M_argv_Length;
    argv_Value_length = sys_M_argv_Value_length;
    argv_Seq_length = sys_M_argv_Seq_length;
    argv = sys_M_argv;
/// @ test-builtin-sys1
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = sys_M_print(ut_M_ostr, *ut_M_ostr_Length);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys2
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = sys_M_println(ut_M_ostr, *ut_M_ostr_Length);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys3
LUMI_err = sys_M_getchar(&(ut_M_c), &(ut_M_b));
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys4
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = sys_M_getline(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(ut_M_b));
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys5
LUMI_err = sys_M_exit(ut_M_j);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys6
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = sys_M_system(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(ut_M_j));
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys7
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = sys_M_getenv(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(ut_M_b));
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys8
LUMI_err = FileReadText_get(sys_M_stdin, &(ut_M_c), &(ut_M_b));
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys9
LUMI_err = FileWriteText_put(sys_M_stdout, ut_M_c);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys10
LUMI_err = FileWriteText_put(sys_M_stderr, ut_M_c);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-file-e0
too few parameters
/// @ test-builtin-file-e1
too few parameters
/// @ test-builtin-file-e2
too few parameters
/// @@ test-general
/// @ test-general-0
char* ut_M_str = NULL;
Seq_Length ut_M_str_Max_length = 0;
Seq_Length* ut_M_str_Length = &Lumi_empty_length;
/// @ test-general-1
uint32_t ut_M_x = 0;
/// @ test-general-2
uint32_t ut_M_x = 0;
/// @ test-general-3
uint32_t ut_M_x = 0;
/// @ test-general-4
uint32_t ut_M_x = 0;
/// @ test-general-5
uint32_t ut_M_x = 0;
/// @ test-general-6
char ut_M_s[0x0c] = {0};
Seq_Length ut_M_s_Length[1] = {0};
char ut_M_svs[0x0c] = {0};
Seq_Length ut_M_svs_Length[1] = {0};
Ref_Manager* ut_M_svs_Refman = NULL;
char* ut_M_cs = NULL;
Seq_Length ut_M_cs_Max_length = 0;
Seq_Length* ut_M_cs_Length = &Lumi_empty_length;
Byte* ut_M_cb = NULL;
Seq_Length ut_M_cb_Max_length = 0;
Seq_Length* ut_M_cb_Length = &Lumi_empty_length;
char* ut_M_us = NULL;
Seq_Length ut_M_us_Max_length = 0;
Seq_Length* ut_M_us_Length = &Lumi_empty_length;
Ref_Manager* ut_M_us_Refman = NULL;
char* ut_M_gs = NULL;
Seq_Length ut_M_gs_Max_length = 0;
Seq_Length* ut_M_gs_Length = &Lumi_empty_length;
Ref_Manager* ut_M_gs_Refman = NULL;
void new_Mock(Bool* allocate_success) { }
Return_Code delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    uint32_t x = 0;
    char* ls = NULL;
    Seq_Length ls_Max_length = 0;
    Seq_Length* ls_Length = &Lumi_empty_length;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    static char aux_String_1[] = {'g','l','o','b','a','l',' ','t','e','x','t','\0',};
    Seq_Length aux_String_1_Max_length = sizeof(aux_String_1);
    Seq_Length aux_String_1_Length[1] = {sizeof(aux_String_1) - 1};
    Byte* aux_Buffer_0 = NULL;
    Seq_Length aux_Buffer_0_Max_length = 0;
    Seq_Length* aux_Buffer_0_Length = &Lumi_empty_length;
    static Byte aux_Buffer_1[] = {0xfa,0xde,0x00,0xbe,0xaf,};
    Seq_Length aux_Buffer_1_Max_length = sizeof(aux_Buffer_1);
    Seq_Length aux_Buffer_1_Length[1] = {sizeof(aux_Buffer_1)};
    char* aux_String_2 = NULL;
    Seq_Length aux_String_2_Max_length = 0;
    Seq_Length* aux_String_2_Length = &Lumi_empty_length;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "mock.5.lm"
    /* initializing ut_M_s */
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.5.lm"
    INIT_VAR_REFMAN(2, LUMI_block0_cleanup, ut_M_svs)
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.5.lm"
    INIT_NEW_SEQUENCE(3, LUMI_block0_cleanup, aux_String_0, char, 0x0c);
    LUMI_err = String_copy(aux_String_0, 0x0c, aux_String_0_Length, aux_String_1, *aux_String_1_Length);
    CHECK(3, LUMI_block0_cleanup)
    ut_M_cs_Max_length = 0x0c;
    ut_M_cs_Length = aux_String_0_Length;
    ut_M_cs = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.5.lm"
    INIT_NEW_SEQUENCE(4, LUMI_block0_cleanup, aux_Buffer_0, Byte, 0x0c);
    LUMI_err = Buffer_copy(aux_Buffer_0, 0x0c, aux_Buffer_0_Length, aux_Buffer_1, *aux_Buffer_1_Length);
    CHECK(4, LUMI_block0_cleanup)
    ut_M_cb_Max_length = 0x0c;
    ut_M_cb_Length = aux_Buffer_0_Length;
    ut_M_cb = aux_Buffer_0;
    aux_Buffer_0 = NULL;
    aux_Buffer_0_Length = &Lumi_empty_length;
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.5.lm"
    INIT_NEW_SEQUENCE(5, LUMI_block0_cleanup, aux_String_2, char, 0x0c);
    LUMI_err = String_copy(aux_String_2, 0x0c, aux_String_2_Length, ut_M_s, *ut_M_s_Length);
    CHECK(5, LUMI_block0_cleanup)
    ut_M_us_Max_length = 0x0c;
    ut_M_us_Length = aux_String_2_Length;
    ut_M_us = aux_String_2;
    aux_String_2 = NULL;
    aux_String_2_Length = &Lumi_empty_length;
    INIT_NEW_REFMAN(5, LUMI_block0_cleanup, ut_M_us)
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.5.lm"
    LUMI_inc_ref(ut_M_us_Refman);
    LUMI_dec_ref(ut_M_gs_Refman);
    ut_M_gs_Refman = ut_M_us_Refman;
    ut_M_gs_Max_length = ut_M_us_Max_length;
    ut_M_gs_Length = ut_M_us_Length;
    ut_M_gs = ut_M_us;
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
    x = 0x06;
    x = 0x07;
    INIT_NEW_SEQUENCE(10, LUMI_block0_cleanup, ls, char, 0x0c);
    aux_String_0_Max_length = 0x0c;
    aux_String_0_Length = ls_Length;
    aux_String_0 = ls;
    ls_Max_length = ut_M_cs_Max_length;
    ls_Length = ut_M_cs_Length;
    ls = ut_M_cs;
    ut_M_cs_Max_length = 0x0c;
    ut_M_cs_Length = aux_String_0_Length;
    ut_M_cs = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0);
    free(aux_String_0);
    String_Del(ls);
    free(ls);
    return LUMI_err;
}
MAIN_FUNC
/// @ test-general-7
void ut_M_fun(void);
Return_Code second_M_dummy(void);
char ut_M_s[0x0c] = {0};
Seq_Length ut_M_s_Length[1] = {0};
Line_Count LUMI_file0_line_count[5] = {
    -1,-1,-1, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.5.lm", 5, LUMI_file0_line_count}
};
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    ++LUMI_file_coverage[0].line_count[3];
    String_clear(ut_M_s, 0x0c, ut_M_s_Length);
LUMI_block0_cleanup:
    (void)0;
}
Return_Code second_M_dummy(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void new_Mock(Bool* allocate_success) { }
Return_Code delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Bool LUMI_success = true;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "mock.5.lm"
    /* initializing ut_M_s */
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
    LUMI_success &= LUMI_run_test("dummy", second_M_dummy);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
LUMI_block0_cleanup:
    return LUMI_err;
}
TEST_MAIN_FUNC
/// @ test-general-8
void ut_M_fun(void);
Return_Code test_M_test_fun(void);
Line_Count LUMI_file0_line_count[6] = {
    -1,-1, 0,-1,-1,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.5.lm", 6, LUMI_file0_line_count}
};
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    ++LUMI_file_coverage[0].line_count[2];
    ut_M_fun();
LUMI_block0_cleanup:
    (void)0;
}
Return_Code test_M_test_fun(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void new_Mock(Bool* allocate_success) { }
Return_Code delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Bool LUMI_success = true;
    LUMI_success &= LUMI_run_test("test-fun", test_M_test_fun);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
LUMI_block0_cleanup:
    return LUMI_err;
}
TEST_MAIN_FUNC
/// @ test-general-e0
unknown keyword "error"
/// @ test-general-e1
statement has no effect
/// @ test-general-e2
unreachable code
/// @ test-general-e3
unreachable code
/// @ test-general-e4
expected new-line in line end, got "?"
/// @ test-general-e5
expected new-line after "main", got "("
/// @ test-general-e6
indentation too long, expected 0 got 4
/// @ test-general-e7
indentation too short, expected 12 got 8
/// @ test-general-e8
no new-line before file end
/// @ test-general-e9
redefinition of variable "name"
/// @ test-general-e10
variable name overrides function "name"
/// @ test-general-e11
unknown type "Error"
/// @ test-general-e12
unknown symbol "error"
/// @ test-general-e13
unexpected "["
/// @ test-general-e14
global variables cannot have access "user"
/// @ test-general-e15
global variables cannot have access "temp"
/// @ test-general-e16
non-conditional global variable not initialized
/// @ test-general-e17
cannot move non-conditional global owner "error"
/// @ test-general-e18
cannot move non-conditional global owner "error"
/// @@ test-struct
/// @ test-struct-0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ test-struct-1
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ test-struct-2
typedef struct ut_M_Test1 ut_M_Test1;
typedef struct ut_M_Test2 ut_M_Test2;
typedef struct ut_M_Test3 ut_M_Test3;
struct ut_M_Test1 {
    uint32_t x;
};
struct ut_M_Test2 {
    uint32_t x;
};
struct ut_M_Test3 {
    uint32_t x;
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
/// @ test-struct-3
typedef struct ut_M_Test1 ut_M_Test1;
typedef struct ut_M_Test2 ut_M_Test2;
struct ut_M_Test1 {
    uint32_t x;
};
struct ut_M_Test2 {
    ut_M_Test1 _base;
    uint32_t y;
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
/// @ test-struct-4
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
/// @ test-struct-e0
expected space after "struct", got "("
/// @ test-struct-e1
illegal type name "error"
/// @ test-struct-e2
illegal type name "ERror"
/// @ test-struct-e3
illegal type name "Error-name"
/// @ test-struct-e4
illegal type name "E"
/// @ test-struct-e5
redefinition of type "Int"
/// @ test-struct-e6
redefinition of type "Test"
/// @ test-struct-e7
expected ")" after base type, got "new-line"
/// @ test-struct-e8
unknown keyword "error"
/// @ test-struct-e9
expected block in a new line, got "end-of-file"
/// @ test-struct-e10
type with no fields "Error"
/// @ test-struct-e11
expected "(" after "new", got " "
/// @ test-struct-e12
constructor already defined for type "Error"
/// @ test-struct-e13
constructor with outputs
/// @ test-struct-e14
using reserved method name "new"
/// @ test-struct-e15
recursive declaration of type "Error", extended by type "Error"
/// @ test-struct-e16
recursive declaration of type "Aerror", extended by type "Berror", extended by type "Aerror"
/// @@ test-class
/// @ test-class-0
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Mid_Dynamic ut_M_Mid_Dynamic;
typedef struct ut_M_Top ut_M_Top;
typedef struct ut_M_Top_Dynamic ut_M_Top_Dynamic;
struct ut_M_Base {
    uint32_t x;
    ut_M_Base* b;
    ut_M_Base_Dynamic* b_Dynamic;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
    void (*dyn0)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
    Return_Code (*dyn1)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
    void (*dyn2)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
};
struct ut_M_Mid {
    ut_M_Base _base;
    uint32_t y;
    ut_M_Mid* m;
    ut_M_Mid_Dynamic* m_Dynamic;
};
struct ut_M_Mid_Dynamic {
    ut_M_Base_Dynamic _base;
    void (*dyn3)(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
    Return_Code (*dyn4)(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
};
struct ut_M_Top {
    ut_M_Mid _base;
    uint32_t z;
    ut_M_Top* t;
    ut_M_Top_Dynamic* t_Dynamic;
};
struct ut_M_Top_Dynamic {
    ut_M_Mid_Dynamic _base;
    void (*dyn5)(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
};
void ut_M_Base_stat(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_dyn0(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
Return_Code ut_M_Base_dyn1(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_dyn2(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Mid_dyn0(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Mid_dyn3(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
Return_Code ut_M_Mid_dyn4(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Top_dyn0(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
Return_Code ut_M_Top_dyn1(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
void ut_M_Top_dyn3(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
void ut_M_Top_dyn5(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_dyn0, ut_M_Base_dyn1, ut_M_Base_dyn2};
ut_M_Mid_Dynamic ut_M_Mid_dynamic = {{(Dynamic_Del)ut_M_Mid_Del, (void (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic))ut_M_Mid_dyn0, ut_M_Base_dyn1, ut_M_Base_dyn2}, ut_M_Mid_dyn3, ut_M_Mid_dyn4};
ut_M_Top_Dynamic ut_M_Top_dynamic = {{{(Dynamic_Del)ut_M_Top_Del, (void (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic))ut_M_Top_dyn0, (Return_Code (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic))ut_M_Top_dyn1, ut_M_Base_dyn2}, (void (*)(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic))ut_M_Top_dyn3, ut_M_Mid_dyn4}, ut_M_Top_dyn5};
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
Return_Code ut_M_Base_dyn1(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    Return_Code LUMI_err = OK;
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
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    SELF_REF_DEL_DYN(ut_M_Base, _, b, b_Dynamic);
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
Return_Code ut_M_Mid_dyn4(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), &(self_Dynamic->_base));
    SELF_REF_DEL_DYN(ut_M_Mid, _base._, m, m_Dynamic);
    free(self->m);
}
void ut_M_Top_dyn0(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Mid_dyn0(&(self->_base), &(self_Dynamic->_base));
LUMI_block0_cleanup:
    (void)0;
}
Return_Code ut_M_Top_dyn1(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    Return_Code LUMI_err = OK;
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
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base), &(self_Dynamic->_base));
    SELF_REF_DEL_DYN(ut_M_Top, _base._base._, t, t_Dynamic);
    free(self->t);
}
/// @ test-class-1
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
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_fun};
void ut_M_Test_fun(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->tw_Refman);
    SELF_REF_DEL_STR_DYN(ut_M_Test, _, ts, ts_Dynamic);
    LUMI_owner_dec_ref(self->ts_Refman);
    SELF_REF_DEL_DYN(ut_M_Test, _, to, to_Dynamic);
    free(self->to);
}
/// @ test-class-e0
expected space after "class", got "("
/// @ test-class-e1
class with no dynamic methods "Error"
/// @ test-class-e2
expected "dynamic" or "inst" method type, got "error"
/// @ test-class-e3
illegal dynamic in function "meth"
/// @ test-class-e4
illegal dynamic in function "meth"
/// @ test-class-e5
too many parameters
/// @ test-class-e6
non matching error result
/// @@ test-function
/// @ test-function-0
void ut_M_name(void);
void ut_M_name(void) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-1
void ut_M_name(char* self, Seq_Length self_Max_length, Seq_Length* self_Length, char* text, Seq_Length text_Max_length, Seq_Length* text_Length, uint32_t num);
void ut_M_name(char* self, Seq_Length self_Max_length, Seq_Length* self_Length, char* text, Seq_Length text_Max_length, Seq_Length* text_Length, uint32_t num) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-2
void ut_M_name(char** text, Seq_Length* text_Max_length, Seq_Length** text_Length, uint32_t* num);
void ut_M_name(char** text, Seq_Length* text_Max_length, Seq_Length** text_Length, uint32_t* num) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-3
void ut_M_name(Char param, char** out, Seq_Length* out_Max_length, Seq_Length** out_Length);
void ut_M_name(Char param, char** out, Seq_Length* out_Max_length, Seq_Length** out_Length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-4
void ut_M_name(uint32_t* array, Seq_Length array_Length);
void ut_M_name(uint32_t* array, Seq_Length array_Length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-5
void ut_M_some(void);
void ut_M_name(void (*fun)(uint32_t x, uint32_t* y), void (**joy)(void));
void ut_M_some(void) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_name(void (*fun)(uint32_t x, uint32_t* y), void (**joy)(void)) {
    unsigned LUMI_loop_depth = 1;
    *joy = ut_M_some;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-6
void ut_M_name(void);
void ut_M_name(void) {
    unsigned LUMI_loop_depth = 1;
    uint32_t x = 0;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-7
Return_Code ut_M_name(char* self, Seq_Length self_Max_length, Seq_Length* self_Length, uint32_t px, Char* pu, Seq_Length pu_Length, char* po, Seq_Length po_Max_length, Seq_Length* po_Length, char** oself, Seq_Length* oself_Max_length, Seq_Length** oself_Length, Ref_Manager** oself_Refman, uint32_t* ox, char** ou, Seq_Length* ou_Max_length, Seq_Length** ou_Length, Ref_Manager** ou_Refman, char** oo, Seq_Length* oo_Max_length, Seq_Length** oo_Length);
Return_Code ut_M_name(char* self, Seq_Length self_Max_length, Seq_Length* self_Length, uint32_t px, Char* pu, Seq_Length pu_Length, char* po, Seq_Length po_Max_length, Seq_Length* po_Length, char** oself, Seq_Length* oself_Max_length, Seq_Length** oself_Length, Ref_Manager** oself_Refman, uint32_t* ox, char** ou, Seq_Length* ou_Max_length, Seq_Length** ou_Length, Ref_Manager** ou_Refman, char** oo, Seq_Length* oo_Max_length, Seq_Length** oo_Length) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    uint32_t x = 0;
    char* u = NULL;
    Seq_Length u_Max_length = 0;
    Seq_Length* u_Length = &Lumi_empty_length;
    Byte* b = NULL;
    Seq_Length b_Max_length = 0;
    Seq_Length* b_Length = &Lumi_empty_length;
    char* o = NULL;
    Seq_Length o_Max_length = 0;
    Seq_Length* o_Length = &Lumi_empty_length;
    char v[0x0c] = {0};
    Seq_Length v_Length[1] = {0};
    char* n = NULL;
    Seq_Length n_Max_length = 0;
    Seq_Length* n_Length = &Lumi_empty_length;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    static char aux_String_1[] = {'c','o','n','s','t','a','n','t',' ','s','t','r','i','n','g','\0',};
    Seq_Length aux_String_1_Max_length = sizeof(aux_String_1);
    Seq_Length aux_String_1_Length[1] = {sizeof(aux_String_1) - 1};
    static Byte aux_Buffer_0[] = {0xbe,0xef,};
    Seq_Length aux_Buffer_0_Max_length = sizeof(aux_Buffer_0);
    Seq_Length aux_Buffer_0_Length[1] = {sizeof(aux_Buffer_0)};
    Char* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    /* initializing v */
    INIT_NEW_SEQUENCE(8, LUMI_block0_cleanup, n, char, 0x0c);
    INIT_NEW_SEQUENCE(9, LUMI_block0_cleanup, aux_String_0, char, 0x0c);
    String_Del(o);
    free(o);
    o_Max_length = 0x0c;
    o_Length = aux_String_0_Length;
    o = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
    u_Max_length = aux_String_1_Max_length;
    u_Length = aux_String_1_Length;
    u = aux_String_1;
    b_Max_length = aux_Buffer_0_Max_length;
    b_Length = aux_Buffer_0_Length;
    b = aux_Buffer_0;
    if (SAFE_SUM_LARGER(0x02, 0x06, *(po_Length))) RAISE(12, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = po + 0x02;
    aux_Array_0_Length = 0x06;
    pu_Length = 0x06;
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
/// @ test-function-8
typedef struct ut_M_Struct ut_M_Struct;
typedef struct ut_M_Class ut_M_Class;
typedef struct ut_M_Class_Dynamic ut_M_Class_Dynamic;
struct ut_M_Struct {
    ut_M_Struct* s;
    ut_M_Struct* as;
    Seq_Length as_Length;
    char* astr;
    Seq_Length astr_Length;
    Seq_Length astr_Value_length;
    Seq_Length* astr_Seq_length;
};
struct ut_M_Class {
    ut_M_Class* c;
    ut_M_Class_Dynamic* c_Dynamic;
    ut_M_Class* ac;
    Seq_Length ac_Length;
};
struct ut_M_Class_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Class* self, ut_M_Class_Dynamic* self_Dynamic);
};
void ut_M_Struct_Del(ut_M_Struct* self);
void ut_M_Class_meth(ut_M_Class* self, ut_M_Class_Dynamic* self_Dynamic);
void ut_M_Class_Del(ut_M_Class* self, ut_M_Class_Dynamic* self_Dynamic);
void ut_M_name(ut_M_Struct* ps, ut_M_Class* pc, ut_M_Class_Dynamic* pc_Dynamic, ut_M_Struct* pas, Seq_Length pas_Length, ut_M_Class* pac, Seq_Length pac_Length);
Generic_Type_Dynamic ut_M_Struct_dynamic = {(Dynamic_Del)ut_M_Struct_Del};
ut_M_Class_Dynamic ut_M_Class_dynamic = {(Dynamic_Del)ut_M_Class_Del, ut_M_Class_meth};
void ut_M_Struct_Del(ut_M_Struct* self) {
    if (self == NULL) return;
    free(self->astr_Seq_length);
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
void ut_M_Class_Del(ut_M_Class* self, ut_M_Class_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ARRAY_DEL_DYN(ut_M_Class, self->ac, self->ac_Length)
    free(self->ac);
    SELF_REF_DEL_DYN(ut_M_Class, _, c, c_Dynamic);
    free(self->c);
}
void ut_M_name(ut_M_Struct* ps, ut_M_Class* pc, ut_M_Class_Dynamic* pc_Dynamic, ut_M_Struct* pas, Seq_Length pas_Length, ut_M_Class* pac, Seq_Length pac_Length) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Struct* s = NULL;
    ut_M_Class* c = NULL;
    ut_M_Class_Dynamic* c_Dynamic = NULL;
    ut_M_Struct* as = NULL;
    Seq_Length as_Length = 0;
    ut_M_Class* ac = NULL;
    Seq_Length ac_Length = 0;
    uint32_t* ai = NULL;
    Seq_Length ai_Length = 0;
    char* astr = NULL;
    Seq_Length astr_Length = 0;
    Seq_Length astr_Value_length = 0;
    Seq_Length* astr_Seq_length = NULL;
LUMI_block0_cleanup:
    (void)0;
    free(astr_Seq_length);
    free(astr);
    free(ai);
    ARRAY_DEL_DYN(ut_M_Class, ac, ac_Length)
    free(ac);
    ARRAY_DEL(ut_M_Struct, as, as_Length)
    free(as);
    if (c_Dynamic != NULL) c_Dynamic->_del(c, c_Dynamic);
    free(c);
    ut_M_Struct_Del(s);
    free(s);
    ARRAY_DEL_DYN(ut_M_Class, pac, pac_Length)
    free(pac);
    ARRAY_DEL(ut_M_Struct, pas, pas_Length)
    free(pas);
    if (pc_Dynamic != NULL) pc_Dynamic->_del(pc, pc_Dynamic);
    free(pc);
    ut_M_Struct_Del(ps);
    free(ps);
}
/// @ test-function-9
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_name(ut_M_Test** t, ut_M_Test_Dynamic** t_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_name(ut_M_Test** t, ut_M_Test_Dynamic** t_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    if (*t_Dynamic != NULL) (*t_Dynamic)->_del(*t, *t_Dynamic);
    free(*t);
    *t_Dynamic = NULL;
    *t = NULL;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-10
void ut_M_name(char* ai, Seq_Length ai_Length, Seq_Length ai_Value_length, Seq_Length ai_Value_value_length, Seq_Length* ai_Seq_length, uint32_t** ao, Seq_Length* ao_Length, Seq_Length* ao_Value_length);
void ut_M_name(char* ai, Seq_Length ai_Length, Seq_Length ai_Value_length, Seq_Length ai_Value_value_length, Seq_Length* ai_Seq_length, uint32_t** ao, Seq_Length* ao_Length, Seq_Length* ao_Value_length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-11
Return_Code ut_M_name(char** so, Seq_Length* so_Max_length, Seq_Length** so_Length);
Return_Code ut_M_name(char** so, Seq_Length* so_Max_length, Seq_Length** so_Length) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    INIT_NEW_SEQUENCE(2, LUMI_block0_cleanup, aux_String_0, char, 0x0c);
    String_Del(*so);
    free(*so);
    *so_Max_length = 0x0c;
    *so_Length = aux_String_0_Length;
    *so = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0);
    free(aux_String_0);
    return LUMI_err;
}
/// @ test-function-m0
void new_Mock(Bool* allocate_success) { }
Return_Code delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    uint32_t x = 0;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
MAIN_FUNC
/// @ test-function-m1
void new_Mock(Bool* allocate_success) { }
Return_Code delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    CHECK_REF(3, LUMI_block0_cleanup, s)
    String_clear(s, s_Max_length, s_Length);
LUMI_block0_cleanup:
    (void)0;
    String_Del(s);
    free(s);
    return LUMI_err;
}
MAIN_FUNC
/// @ test-function-me0
error raised inside function not declared as error raising "main"
/// @ test-function-e0
expected space after "func", got "("
/// @ test-function-e1
expected "(" after function name, got "new-line"
/// @ test-function-e2
illegal function name "Error"
/// @ test-function-e3
illegal function name "error_name"
/// @ test-function-e4
redefinition of function "name"
/// @ test-function-e5
function name overrides global variable "name"
/// @ test-function-e6
expected access, got " "
/// @ test-function-e7
expected space after "user", got ")"
/// @ test-function-e8
expected space after "type", got "new-line"
/// @ test-function-e9
illegal access "error"
/// @ test-function-e10
expected space or new-line after ",", got "u"
/// @ test-function-e11
expected ">(" got "()"
/// @ test-function-e12
expected block in a new line, got "end-of-file"
/// @ test-function-e13
indentation too long, expected 4 got 8
/// @ test-function-e14
parameter "x" access should be "copy" for primitive types, got "user"
/// @ test-function-e15
output "x" access should be "var" for primitive types, got "copy"
/// @ test-function-e16
argument "s" access should not be "copy" for non-primitive type "String"
/// @ test-function-e17
missing subtype for array
/// @ test-function-e18
missing arguments in function type
/// @ test-function-e20
indentation too short, expected 8 got 4
/// @ test-function-e21
misplaced item "Error"
/// @ test-function-e22
misplaced item "error"
/// @ test-function-e23
redefinition of variable "error"
/// @ test-function-e24
redefinition of variable "error"
/// @ test-function-e25
redefinition of variable "error"
/// @ test-function-e26
variable name overrides function "error"
/// @ test-function-e27
variable name overrides function "error"
/// @ test-function-e28
illegal variable name "Error"
/// @ test-function-e29
error raised inside function not declared as error raising "fun"
/// @ test-function-e30
error raised inside function not declared as error raising "fun"
/// @ test-function-e31
error raised inside function not declared as error raising "fun"
/// @ test-function-e32
error raised inside function not declared as error raising "fun"
/// @@ test-members
/// @ test-members-0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
    char* str;
    Seq_Length str_Max_length;
    Seq_Length* str_Length;
    Ref_Manager* str_Refman;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->str_Refman);
}
/// @ test-members-1
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_name(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_name(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    self->x = 0x02;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ test-members-2
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_name(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_name(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    uint32_t x = 0;
    x = self->x;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ test-members-3
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ test-members-4
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ test-members-5
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ test-members-6
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ test-members-7
typedef struct ut_M_Test1 ut_M_Test1;
typedef struct ut_M_Test2 ut_M_Test2;
struct ut_M_Test1 {
    uint32_t name;
};
struct ut_M_Test2 {
    uint32_t fun;
};
void ut_M_Test1_fun(ut_M_Test1* self);
void ut_M_Test1_Del(ut_M_Test1* self);
void ut_M_Test2_name(ut_M_Test2* self);
void ut_M_Test2_Del(ut_M_Test2* self);
void ut_M_fun(void);
Generic_Type_Dynamic ut_M_Test1_dynamic = {(Dynamic_Del)ut_M_Test1_Del};
Generic_Type_Dynamic ut_M_Test2_dynamic = {(Dynamic_Del)ut_M_Test2_Del};
uint32_t ut_M_name = 0;
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
/// @ test-members-8
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_fun(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_fun(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    if (self->x > 0x03) {
        self->x = 0x03;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    do {
        uint8_t aux_Int_0 = 0;
        LUMI_loop_depth = 3;
        do {
            uint8_t n = 0;
            LUMI_loop_depth = 5;
            if (!(aux_Int_0 < 0x04)) { LUMI_loop_depth = 3; goto LUMI_block3_cleanup; }
            n = aux_Int_0;
            aux_Int_0 += 0x01;
            self->x = n;
        LUMI_block3_cleanup:
            (void)0;
        } while (LUMI_loop_depth >= 4);
        if (LUMI_loop_depth < 3) goto LUMI_block2_cleanup;
        if (!(self->x < 0x1e)) { LUMI_loop_depth = 1; goto LUMI_block2_cleanup; }
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
/// @ test-members-9
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_fun(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_Test_fun(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    self->x = 0x03;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-members-10
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_fun(ut_M_Test* self, char* s, Seq_Length s_Max_length, Seq_Length* s_Length, uint32_t* x);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_Test_fun(ut_M_Test* self, char* s, Seq_Length s_Max_length, Seq_Length* s_Length, uint32_t* x) {
    unsigned LUMI_loop_depth = 1;
    String_length(s, s_Max_length, s_Length, &(*x));
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-members-11
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_new(ut_M_Test* self, uint32_t x);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_Test_new(ut_M_Test* self, uint32_t x) {
    unsigned LUMI_loop_depth = 1;
    self->x = x;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-members-e0
redefinition of field "name"
/// @ test-members-e1
field name overrides method "name"
/// @ test-members-e2
redefinition of method "name"
/// @ test-members-e3
method name overrides field "name"
/// @ test-members-e4
assigning into an owner a non-owner access "user"
/// @ test-members-e5
expected block in a new line, got " "
/// @ test-members-e6
misplaced item "error"
/// @ test-members-e7
type "Test" already implemented method "fun"
/// @ test-members-e8
type "Test" already implemented method "fun"
/// @ test-members-e9
expected name after ".", got "."
/// @ test-members-e10
field "num" is not a global member of type "Test"
/// @ test-members-e11
missing access before method name
/// @ test-members-e12
missing access before method name
/// @ test-members-e13
too few outputs
/// @ test-members-e14
non matching error result
/// @@ test-return
/// @ test-return-0
void ut_M_name(void);
void ut_M_name(void) {
    unsigned LUMI_loop_depth = 1;
    LUMI_loop_depth = 0; goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-return-1
Return_Code ut_M_name(void);
Return_Code ut_M_name(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    USER_RAISE(2, LUMI_block0_cleanup, NULL, 0)
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ test-return-2
Return_Code ut_M_name(void);
Return_Code ut_M_name(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    static char aux_String_0[] = {'s','o','m','e',' ','e','r','r','o','r','\0',};
    Seq_Length aux_String_0_Max_length = sizeof(aux_String_0);
    Seq_Length aux_String_0_Length[1] = {sizeof(aux_String_0) - 1};
    USER_RAISE(2, LUMI_block0_cleanup, aux_String_0, *(aux_String_0_Length))
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ test-return-3
Return_Code ut_M_name(char* arr, Seq_Length arr_Length, Seq_Length arr_Value_length, Seq_Length* arr_Seq_length);
Return_Code ut_M_name(char* arr, Seq_Length arr_Length, Seq_Length arr_Value_length, Seq_Length* arr_Seq_length) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    if (0x03 >= arr_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_String_0 = arr + 0x03 * arr_Value_length;
    aux_String_0_Max_length = arr_Value_length;
    aux_String_0_Length = arr_Seq_length + 0x03;
    USER_RAISE(2, LUMI_block0_cleanup, aux_String_0, *(aux_String_0_Length))
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ test-return-4
char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    Ref_Manager* s_Refman = NULL;
    CHECK_REFMAN(2, LUMI_block0_cleanup, s_Refman)
    USER_RAISE(2, LUMI_block0_cleanup, s, *(s_Length))
/// @ test-return-e0
expected new-line after "return", got "("
/// @ test-return-e1
expected space or new-line after "raise!", got "("
/// @ test-return-e2
got "Int" expression, expected "String"
/// @ test-return-e3
got "Empty Symbol" expression, expected "String"
/// @ test-return-e4
expected ! after "raise", got "new-line"
/// @@ test-code-variables
/// @ test-code-variables-0
uint32_t x = 0;
/// @ test-code-variables-1
char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
/// @ test-code-variables-2
uint32_t* a = NULL;
    Seq_Length a_Length = 0;
/// @ test-code-variables-3
ut_M_Test* tt = NULL;
/// @ test-code-variables-4
char s[0x0c] = {0};
    Seq_Length s_Length[1] = {0};
    /* initializing s */
/// @ test-code-variables-5
uint32_t a[0x0c] = {0};
    /* initializing a */
/// @ test-code-variables-6
ut_M_Test a[0x0c] = {0};
    /* initializing a */
/// @ test-code-variables-7
char sa[0x0c * 0x07] = {0};
    Seq_Length sa_Seq_length[0x0c] = {0};
    /* initializing sa */
/// @ test-code-variables-8
char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    INIT_NEW_SEQUENCE(1, LUMI_block0_cleanup, s, char, 0x0c);
    String_Del(*so);
    LUMI_owner_dec_ref(*so_Refman);
    *so_Max_length = 0x0c;
    *so_Length = s_Length;
    *so = s;
    s = NULL;
    s_Length = &Lumi_empty_length;
    INIT_NEW_REFMAN(2, LUMI_block0_cleanup, *so)
/// @ test-code-variables-9
ut_M_Ta a[0x0c] = {0};
    /* initializing a */
/// @ test-code-variables-10
uint32_t* a = NULL;
    Seq_Length a_Length = 0;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, a, uint32_t, 0x0c, 1);
/// @ test-code-variables-11
char* sa = NULL;
    Seq_Length sa_Length = 0;
    Seq_Length sa_Value_length = 0;
    Seq_Length* sa_Seq_length = NULL;
    sa_Value_length = 0x07;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, sa, char, 0x0c, sa_Value_length);
    sa_Seq_length = LUMI_alloc(sizeof(Seq_Length) * sa_Length);
/// @ test-code-variables-12
char aa[0x03 * 0x04 * 0x05] = {0};
    Seq_Length aa_Seq_length[0x03 * 0x04] = {0};
    /* initializing aa */
/// @ test-code-variables-13
char* aa = NULL;
    Seq_Length aa_Length = 0;
    Seq_Length aa_Value_length = 0;
    Seq_Length aa_Value_value_length = 0;
    Seq_Length* aa_Seq_length = NULL;
    aa_Value_length = 0x04;
    aa_Value_value_length = 0x05;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, aa, char, 0x03, aa_Value_length * aa_Value_value_length);
    aa_Seq_length = LUMI_alloc(sizeof(Seq_Length) * aa_Length * aa_Value_length);
/// @ test-code-variables-14
Return_Code ut_M_fun(void);
Return_Code ut_M_fun(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char sv[0x04] = {0};
    Seq_Length sv_Length[1] = {0};
    /* initializing sv */
    if (0x01 > 0x02) {
        Char* su = NULL;
        Seq_Length su_Length = 0;
        Char* aux_Array_0 = NULL;
        Seq_Length aux_Array_0_Length = 0;
        if (SAFE_SUM_LARGER(0x01, 0x02, *(sv_Length))) RAISE(4, LUMI_block1_cleanup, slice_index)
        aux_Array_0 = sv + 0x01;
        aux_Array_0_Length = 0x02;
        su_Length = 0x02;
        su = aux_Array_0;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ test-code-variables-e0
expected space after "type", got "new-line"
/// @ test-code-variables-e1
illegal variable name "Error"
/// @ test-code-variables-e2
illegal variable name "errorName"
/// @ test-code-variables-e3
redefinition of variable "name"
/// @ test-code-variables-e4
redefinition of variable "name"
/// @ test-code-variables-e5
redefinition of variable "name"
/// @ test-code-variables-e6
variable name overrides function "name"
/// @ test-code-variables-e7
type members cannot be initialized
/// @ test-code-variables-e8
expected space after "new", got "new-line"
/// @ test-code-variables-e9
sequence length is not constant
/// @ test-code-variables-e10
illegal variable name "error--name"
/// @ test-code-variables-e11
unexpected space after variable name
/// @ test-code-variables-e12
sequence length never positive with maximum value of "-0x02"
/// @@ test-initialize
/// @ test-initialize-0
ut_M_Tb* aux_Tb_0 = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = &ut_M_Tb_dynamic;
    INIT_NEW(1, LUMI_block0_cleanup, aux_Tb_0, ut_M_Tb, 1);
    LUMI_err = ut_M_Tb_new(aux_Tb_0, aux_Tb_0_Dynamic, ut_M_i);
    CHECK(1, LUMI_block0_cleanup)
    if (ut_M_tb_Dynamic != NULL) ut_M_tb_Dynamic->_base._del(ut_M_tb, ut_M_tb_Dynamic);
    LUMI_owner_dec_ref(ut_M_tb_Refman);
    ut_M_tb_Dynamic = aux_Tb_0_Dynamic;
    ut_M_tb = aux_Tb_0;
    aux_Tb_0 = NULL;
    aux_Tb_0_Dynamic = NULL;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, ut_M_tb)
/// @ test-initialize-1
char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    Byte* aux_Buffer_0 = NULL;
    Seq_Length aux_Buffer_0_Max_length = 0;
    Seq_Length* aux_Buffer_0_Length = &Lumi_empty_length;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_arr[0] <= 0) RAISE(1, LUMI_block0_cleanup, sequence_too_short)
    INIT_NEW_SEQUENCE(1, LUMI_block0_cleanup, aux_String_0, char, ut_M_arr[0]);
    str_Max_length = aux_String_0_Max_length;
    str_Length = aux_String_0_Length;
    str = aux_String_0;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_arr[0] <= 0) RAISE(2, LUMI_block0_cleanup, sequence_too_short)
    INIT_NEW_SEQUENCE(2, LUMI_block0_cleanup, aux_Buffer_0, Byte, ut_M_arr[0]);
    Buffer_Del(ut_M_buff);
    free(ut_M_buff);
    ut_M_buff_Max_length = aux_Buffer_0_Max_length;
    ut_M_buff_Length = aux_Buffer_0_Length;
    ut_M_buff = aux_Buffer_0;
    aux_Buffer_0 = NULL;
    aux_Buffer_0_Length = &Lumi_empty_length;
/// @ test-initialize-2
uint32_t* a = NULL;
    Seq_Length a_Length = 0;
    uint32_t* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_arr[0] <= 0) RAISE(1, LUMI_block0_cleanup, sequence_too_short)
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, aux_Array_0, uint32_t, ut_M_arr[0], 1);
    a_Length = aux_Array_0_Length;
    a = aux_Array_0;
    aux_Array_0 = NULL;
/// @ test-initialize-3
ut_M_Test* a = NULL;
    Seq_Length a_Length = 0;
    ut_M_Test* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_arr[0] <= 0) RAISE(1, LUMI_block0_cleanup, sequence_too_short)
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, aux_Array_0, ut_M_Test, ut_M_arr[0], 1);
    a_Length = aux_Array_0_Length;
    a = aux_Array_0;
    aux_Array_0 = NULL;
/// @ test-initialize-4
char* sa = NULL;
    Seq_Length sa_Length = 0;
    Seq_Length sa_Value_length = 0;
    Seq_Length* sa_Seq_length = NULL;
    Byte* ba = NULL;
    Seq_Length ba_Length = 0;
    Seq_Length ba_Value_length = 0;
    Seq_Length* ba_Seq_length = NULL;
    char* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Seq_Length aux_Array_0_Value_length = 0;
    Seq_Length* aux_Array_0_Seq_length = NULL;
    Byte* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    Seq_Length aux_Array_1_Value_length = 0;
    Seq_Length* aux_Array_1_Seq_length = NULL;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (0x01 >= ut_M_arr_Length) RAISE(1, LUMI_block0_cleanup, slice_index)
    if (ut_M_arr[0] <= 0) RAISE(1, LUMI_block0_cleanup, sequence_too_short)
    aux_Array_0_Value_length = ut_M_arr[0x01];
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, aux_Array_0, char, ut_M_arr[0], aux_Array_0_Value_length);
    aux_Array_0_Seq_length = LUMI_alloc(sizeof(Seq_Length) * aux_Array_0_Length);
    sa_Length = aux_Array_0_Length;
    sa_Value_length = aux_Array_0_Value_length;
    sa_Seq_length = aux_Array_0_Seq_length;
    sa = aux_Array_0;
    aux_Array_0 = NULL;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (0x01 >= ut_M_arr_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    if (ut_M_arr[0] <= 0) RAISE(2, LUMI_block0_cleanup, sequence_too_short)
    aux_Array_1_Value_length = ut_M_arr[0x01];
    INIT_NEW_ARRAY(2, LUMI_block0_cleanup, aux_Array_1, Byte, ut_M_arr[0], aux_Array_1_Value_length);
    aux_Array_1_Seq_length = LUMI_alloc(sizeof(Seq_Length) * aux_Array_1_Length);
    ba_Length = aux_Array_1_Length;
    ba_Value_length = aux_Array_1_Value_length;
    ba_Seq_length = aux_Array_1_Seq_length;
    ba = aux_Array_1;
    aux_Array_1 = NULL;
/// @ test-initialize-5
uint32_t x = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    x = ut_M_arr[0];
/// @ test-initialize-6
char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    Byte* bf = NULL;
    Seq_Length bf_Max_length = 0;
    Seq_Length* bf_Length = &Lumi_empty_length;
    s_Max_length = ut_M_ostr_Max_length;
    s_Length = ut_M_ostr_Length;
    s = ut_M_ostr;
    bf_Max_length = ut_M_buff_Max_length;
    bf_Length = ut_M_buff_Length;
    bf = ut_M_buff;
/// @ test-initialize-7
char s[0x0c] = {0};
    Seq_Length s_Length[1] = {0};
    Byte bf[0x0c] = {0};
    Seq_Length bf_Length[1] = {0};
    static char aux_String_0[] = {'s','o','m','e',' ','s','t','r','i','n','g','\0',};
    Seq_Length aux_String_0_Max_length = sizeof(aux_String_0);
    Seq_Length aux_String_0_Length[1] = {sizeof(aux_String_0) - 1};
    static Byte aux_Buffer_0[] = {0xfa,0xde,0x00,0xbe,0xaf,};
    Seq_Length aux_Buffer_0_Max_length = sizeof(aux_Buffer_0);
    Seq_Length aux_Buffer_0_Length[1] = {sizeof(aux_Buffer_0)};
    /* initializing s */
    LUMI_err = String_copy(s, 0x0c, s_Length, aux_String_0, *aux_String_0_Length);
    CHECK(1, LUMI_block0_cleanup)
    /* initializing bf */
    LUMI_err = Buffer_copy(bf, 0x0c, bf_Length, aux_Buffer_0, *aux_Buffer_0_Length);
    CHECK(2, LUMI_block0_cleanup)
/// @ test-initialize-8
char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    Byte* bf = NULL;
    Seq_Length bf_Max_length = 0;
    Seq_Length* bf_Length = &Lumi_empty_length;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    if (ut_M_i <= 0) RAISE(1, LUMI_block0_cleanup, sequence_too_short)
    INIT_NEW_SEQUENCE(1, LUMI_block0_cleanup, s, char, ut_M_i);
    LUMI_err = String_copy(s, s_Max_length, s_Length, ut_M_ostr, *ut_M_ostr_Length);
    CHECK(1, LUMI_block0_cleanup)
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_buff)
    if (ut_M_i <= 0) RAISE(2, LUMI_block0_cleanup, sequence_too_short)
    INIT_NEW_SEQUENCE(2, LUMI_block0_cleanup, bf, Byte, ut_M_i);
    LUMI_err = Buffer_copy(bf, bf_Max_length, bf_Length, ut_M_buff, *ut_M_buff_Length);
    CHECK(2, LUMI_block0_cleanup)
/// @ test-initialize-9
ut_M_Test* tt = NULL;
    CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    tt = &(ut_M_tc->_base._base._base);
/// @ test-initialize-10
ut_M_Tc tt_Var = {{{{0}}}};
    ut_M_Tc* tt = NULL;
    ut_M_Tc_Dynamic* tt_Dynamic = &ut_M_Tc_dynamic;
    tt = &tt_Var;
    LUMI_err = ut_M_Tb_new(&(tt->_base), &(tt_Dynamic->_base), 0x03);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-initialize-11
ut_M_Tc* tt = NULL;
    ut_M_Tc_Dynamic* tt_Dynamic = &ut_M_Tc_dynamic;
    INIT_NEW(1, LUMI_block0_cleanup, tt, ut_M_Tc, 1);
    LUMI_err = ut_M_Tb_new(&(tt->_base), &(tt_Dynamic->_base), 0x03);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-initialize-12
ut_M_Tc* aux_Tc_0 = NULL;
    ut_M_Tc_Dynamic* aux_Tc_0_Dynamic = &ut_M_Tc_dynamic;
    INIT_NEW(1, LUMI_block0_cleanup, aux_Tc_0, ut_M_Tc, 1);
    LUMI_err = ut_M_Tb_new(&(aux_Tc_0->_base), &(aux_Tc_0_Dynamic->_base), 0x03);
    CHECK(1, LUMI_block0_cleanup)
    if (ut_M_tb_Dynamic != NULL) ut_M_tb_Dynamic->_base._del(ut_M_tb, ut_M_tb_Dynamic);
    LUMI_owner_dec_ref(ut_M_tb_Refman);
    ut_M_tb_Dynamic = &(aux_Tc_0_Dynamic->_base);
    ut_M_tb = &(aux_Tc_0->_base);
    aux_Tc_0 = NULL;
    aux_Tc_0_Dynamic = NULL;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, ut_M_tb)
/// @ test-initialize-13
ut_M_Tb* tt = NULL;
    ut_M_Tb_Dynamic* tt_Dynamic = NULL;
    tt_Dynamic = ut_M_tb_Dynamic;
    tt = ut_M_tb;
/// @ test-initialize-14
ut_M_Ta* ota = NULL;
    ut_M_Ta_Dynamic* ota_Dynamic = NULL;
    LUMI_var_dec_ref(ut_M_tb_Refman);
    ota_Dynamic = &(ut_M_tb_Dynamic->_base);
    ota = &(ut_M_tb->_base);
    ut_M_tb = NULL;
    ut_M_tb_Refman = NULL;
    ut_M_tb_Dynamic = NULL;
/// @ test-initialize-15
char* sa = NULL;
    Seq_Length sa_Length = 0;
    Seq_Length sa_Value_length = 0;
    Seq_Length sa_Value_value_length = 0;
    Seq_Length* sa_Seq_length = NULL;
    Byte* ba = NULL;
    Seq_Length ba_Length = 0;
    Seq_Length ba_Value_length = 0;
    Seq_Length ba_Value_value_length = 0;
    Seq_Length* ba_Seq_length = NULL;
    char* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Seq_Length aux_Array_0_Value_length = 0;
    Seq_Length aux_Array_0_Value_value_length = 0;
    Seq_Length* aux_Array_0_Seq_length = NULL;
    Byte* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    Seq_Length aux_Array_1_Value_length = 0;
    Seq_Length aux_Array_1_Value_value_length = 0;
    Seq_Length* aux_Array_1_Seq_length = NULL;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_arr[0] <= 0) RAISE(1, LUMI_block0_cleanup, sequence_too_short)
    aux_Array_0_Value_length = ut_M_arr[0x01];
    aux_Array_0_Value_value_length = ut_M_arr[0x02];
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, aux_Array_0, char, ut_M_arr[0], aux_Array_0_Value_length * aux_Array_0_Value_value_length);
    aux_Array_0_Seq_length = LUMI_alloc(sizeof(Seq_Length) * aux_Array_0_Length * aux_Array_0_Value_length);
    sa_Length = aux_Array_0_Length;
    sa_Value_length = aux_Array_0_Value_length;
    sa_Value_value_length = aux_Array_0_Value_value_length;
    sa_Seq_length = aux_Array_0_Seq_length;
    sa = aux_Array_0;
    aux_Array_0 = NULL;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_arr[0] <= 0) RAISE(2, LUMI_block0_cleanup, sequence_too_short)
    aux_Array_1_Value_length = ut_M_arr[0x01];
    aux_Array_1_Value_value_length = ut_M_arr[0x02];
    INIT_NEW_ARRAY(2, LUMI_block0_cleanup, aux_Array_1, Byte, ut_M_arr[0], aux_Array_1_Value_length * aux_Array_1_Value_value_length);
    aux_Array_1_Seq_length = LUMI_alloc(sizeof(Seq_Length) * aux_Array_1_Length * aux_Array_1_Value_length);
    ba_Length = aux_Array_1_Length;
    ba_Value_length = aux_Array_1_Value_length;
    ba_Value_value_length = aux_Array_1_Value_value_length;
    ba_Seq_length = aux_Array_1_Seq_length;
    ba = aux_Array_1;
    aux_Array_1 = NULL;
/// @ test-initialize-16
typedef struct ut_M_MyStruct ut_M_MyStruct;
struct ut_M_MyStruct {
    uint32_t x;
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self);
void ut_M_get(ut_M_MyStruct** a);
Generic_Type_Dynamic ut_M_MyStruct_dynamic = {(Dynamic_Del)ut_M_MyStruct_Del};
void ut_M_MyStruct_Del(ut_M_MyStruct* self) {
    if (self == NULL) return;
}
void ut_M_get(ut_M_MyStruct** a) {
    unsigned LUMI_loop_depth = 1;
    ut_M_MyStruct* b = NULL;
    ut_M_MyStruct* aux_MyStruct_0 = NULL;
    ut_M_get(&(aux_MyStruct_0));
    b = aux_MyStruct_0;
    aux_MyStruct_0 = NULL;
LUMI_block0_cleanup:
    (void)0;
    ut_M_MyStruct_Del(aux_MyStruct_0);
    free(aux_MyStruct_0);
    ut_M_MyStruct_Del(b);
    free(b);
}
/// @ test-initialize-17
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
/// @ test-initialize-18
ut_M_Tc tt_Var = {{{{0}}}};
    ut_M_Tc* tt = NULL;
    Ref_Manager* tt_Refman = NULL;
    ut_M_Tc_Dynamic* tt_Dynamic = &ut_M_Tc_dynamic;
    tt = &tt_Var;
    INIT_VAR_REFMAN(1, LUMI_block0_cleanup, tt)
    LUMI_err = ut_M_Tb_new(&(tt->_base), &(tt_Dynamic->_base), 0x03);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-initialize-19
ut_M_Test* t1 = NULL;
    ut_M_Test t2_Var = {0};
    ut_M_Test* t2 = NULL;
    Ref_Manager* t2_Refman = NULL;
    INIT_NEW(1, LUMI_block0_cleanup, t1, ut_M_Test, 1);
    t2 = &t2_Var;
    INIT_VAR_REFMAN(2, LUMI_block0_cleanup, t2)
/// @ test-initialize-20
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_new(ut_M_Test* self, uint32_t x);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_new(ut_M_Test* self, uint32_t x) {
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
    ut_M_Test_new(t, 0x03);
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
}
/// @ test-initialize-21
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Base {
    uint32_t x;
};
struct ut_M_Test {
    ut_M_Base _base;
    uint32_t y;
};
void ut_M_Base_new(ut_M_Base* self);
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Test_new(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_new(ut_M_Base* self) {
    unsigned LUMI_loop_depth = 1;
    self->x = 0x02;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
}
void ut_M_Test_new(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Base_new(&(self->_base));
    self->y = 0x03;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
/// @ test-initialize-e0
dynamic allocation of primitive type "Int"
/// @ test-initialize-e1
missing length for sequence
/// @ test-initialize-e2
missing length for sequence
/// @ test-initialize-e3
missing length for sequence
/// @ test-initialize-e4
missing length for sequence
/// @ test-initialize-e5
missing subtype for array
/// @ test-initialize-e6
missing subtype for array
/// @ test-initialize-e7
missing subtype for array
/// @ test-initialize-e8
missing subtype for array
/// @ test-initialize-e9
generic arrays not supported
/// @ test-initialize-e10
expected ":" or "} after array length", got "new-line"
/// @ test-initialize-e11
expected "}" after sub-types, got "new-line"
/// @ test-initialize-e12
unknown symbol "error"
/// @ test-initialize-e13
got "String" expression, expected "Int"
/// @ test-initialize-e14
only "var" access is supported for primitive types, got "user"
/// @ test-initialize-e15
only "var" access is supported for primitive types, got "owner"
/// @ test-initialize-e16
no constructor for type "Array"
/// @ test-initialize-e17
cannot assign "Int" into "Bool"
/// @ test-initialize-e18
only one initialization parameter expected
/// @ test-initialize-e19
no constructor for type "Test"
/// @ test-initialize-e20
access should be "copy" for primitive types, got "user"
/// @ test-initialize-e21
assigning into access "owner" invalid access "user"
/// @ test-initialize-e22
assigning into an owner a non-owner access "user"
/// @ test-initialize-e23
more than one subtype for array
/// @ test-initialize-e24
passing ownership of type "Tb" into static type "Test"
/// @ test-initialize-e25
using invalid reference "s"
/// @ test-initialize-e26
assigning empty into non-conditional type "String"
/// @ test-initialize-e27
ignoring empty reference check
/// @ test-initialize-e28
using before declaration variable "error"
/// @ test-initialize-e29
assigning reference into itself
/// @ test-initialize-e30
using before declaration variable "error"
/// @ test-initialize-e31
unknown symbol "error"
/// @ test-initialize-e32
unexpected ? initializing type "Test"
/// @ test-initialize-e33
cannot use "?" on non conditional or weak reference of type "Type Name"
/// @ test-initialize-e34
ignoring initialization error check
/// @ test-initialize-e35
ignoring initialization error check
/// @ test-initialize-e36
using "!" where there is no error
/// @ test-initialize-e37
using "!" where there is no error
/// @ test-initialize-e38
unexpected "!" after "s"
/// @ test-initialize-e39
sequence length never positive with maximum value of "-0x02"
/// @ test-initialize-e40
using invalid reference "x"
/// @@ test-comment
/// @ test-comment-0
uint32_t x = 0;
/// @ test-comment-1
uint32_t x = 0;
/// @ test-comment-2
uint32_t x = 0;
/// @ test-comment-3
uint32_t x = 0;
/// @@ test-block
/// @ test-block-0
{
        ut_M_Test* tt = NULL;
        INIT_NEW(2, LUMI_block1_cleanup, tt, ut_M_Test, 1);
        ut_M_i = 0x01;
    LUMI_block1_cleanup:
        (void)0;
    ut_M_Test_Del(tt);
        free(tt);
    }
/// @ test-block-1
{
        LUMI_loop_depth = 0; goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    }
/// @ test-block-2
{
        uint32_t n = 0;
    LUMI_block1_cleanup:
        (void)0;
    }
    {
        uint32_t n = 0;
    LUMI_block2_cleanup:
        (void)0;
    }
/// @ test-block-e0
expected new-line after "block", got " "
/// @ test-block-e1
"break" used not inside loop
/// @ test-block-e2
"while" used not inside loop
/// @ test-block-e3
unknown symbol "tt"
/// @ test-block-e4
using invalid reference "tt"
/// @@ test-if-else
/// @ test-if-else-0
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    if (ut_M_t->num > 0x03) {
        ut_M_i = 0x02;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-if-else-1
if (ut_M_i > 0x03) {
        ut_M_i = 0x02;
    LUMI_block1_cleanup:
        (void)0;
    }
    else {
        ut_M_i = 0x01;
    LUMI_block3_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-if-else-2
if (ut_M_i > 0x03) {
        ut_M_i = 0x03;
    LUMI_block1_cleanup:
        (void)0;
    }
    else {
        CHECK_REF_REFMAN(3, LUMI_block3_cleanup, ut_M_t, ut_M_t_Refman)
        if (ut_M_t->num > 0x02) {
            ut_M_i = 0x02;
        LUMI_block4_cleanup:
            (void)0;
        }
        else {
            CHECK_REF_REFMAN(5, LUMI_block6_cleanup, ut_M_t, ut_M_t_Refman)
            if (ut_M_t->num > 0x01) {
                ut_M_i = 0x01;
            LUMI_block7_cleanup:
                (void)0;
            }
            else {
                ut_M_i = 0x01;
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
/// @ test-if-else-3
if (ut_M_b) {
        LUMI_loop_depth = 0; goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    ut_M_i = 0x03;
/// @ test-if-else-4
if (ut_M_b && ut_M_b) {
        ut_M_i = 0x01;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-if-else-5
if (ut_M_b) {
        char sa[0x04] = {0};
        Seq_Length sa_Length[1] = {0};
        /* initializing sa */
        if (ut_M_b) {
            char sb[0x04] = {0};
            Seq_Length sb_Length[1] = {0};
            /* initializing sb */
        LUMI_block2_cleanup:
            (void)0;
        }
        else {
            if (ut_M_b) {
                char sc[0x04] = {0};
                Seq_Length sc_Length[1] = {0};
                /* initializing sc */
            LUMI_block5_cleanup:
                (void)0;
            }
            else {
                char sd[0x04] = {0};
                Seq_Length sd_Length[1] = {0};
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
            char se[0x04] = {0};
            Seq_Length se_Length[1] = {0};
            /* initializing se */
        LUMI_block10_cleanup:
            (void)0;
        }
        else {
            char sf[0x04] = {0};
            Seq_Length sf_Length[1] = {0};
            /* initializing sf */
        LUMI_block12_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 1) goto LUMI_block9_cleanup;
    LUMI_block9_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-if-else-e0
got "Int" expression, expected "Bool"
/// @ test-if-else-e1
unknown symbol "error"
/// @ test-if-else-e2
unknown symbol "error"
/// @ test-if-else-e3
unknown symbol "error"
/// @ test-if-else-e4
unreachable code
/// @ test-if-else-e5
expected space after "if", got "("
/// @ test-if-else-e6
"else" without a previous "if"
/// @ test-if-else-e7
expected new-line after "else", got " "
/// @ test-if-else-e8
"else-if" without a previous "if"
/// @ test-if-else-e9
expected space after "else-if", got "("
/// @ test-if-else-e10
expected block in a new line, got "end-of-file"
/// @@ test-loop
/// @ test-loop-0
do {
        uint32_t x = 0;
        LUMI_loop_depth = 3;
        if (!(ut_M_b)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-loop-1
do {
        LUMI_loop_depth = 3;
        LUMI_loop_depth = 1; goto LUMI_block1_cleanup;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-loop-2
do {
        LUMI_loop_depth = 3;
        CHECK_REF_REFMAN(2, LUMI_block1_cleanup, ut_M_t, ut_M_t_Refman)
        if (!(ut_M_t->num > 0x03)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-loop-3
do {
        LUMI_loop_depth = 3;
        LUMI_loop_depth = 2; goto LUMI_block1_cleanup;
        if (!(ut_M_b)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-loop-4
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
/// @ test-loop-5
do {
        char sa[0x04] = {0};
        Seq_Length sa_Length[1] = {0};
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
            char sb[0x04] = {0};
            Seq_Length sb_Length[1] = {0};
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
                char sc[0x04] = {0};
                Seq_Length sc_Length[1] = {0};
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
/// @ test-loop-6
uint16_t aux_Int_0 = 0;
    do {
        LUMI_loop_depth = 3;
        if (aux_Int_0 >= 0x0400) RAISE(1, LUMI_block1_cleanup, loop_limit)
        ++aux_Int_0;
        if (!(ut_M_b)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-loop-7
{
        uint32_t aux_Int_0 = 0;
        uint64_t aux_Int_1 = 0;
        uint64_t aux_Int_2 = 0;
        ++LUMI_trace_ignore_count;
        CHECK_REF(2, LUMI_block1_cleanup, ut_M_ostr)
        String_length(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(aux_Int_0));
        aux_Int_2 = aux_Int_0 + 0x02;
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
/// @ test-loop-8
do {
        LUMI_loop_depth = 3;
        ut_M_i = 0x01;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-loop-9
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
/// @ test-loop-e0
expected space after "loop", got "("
/// @ test-loop-e1
"while" used not inside loop
/// @ test-loop-e2
"continue" used not inside loop
/// @ test-loop-e3
got "Int" expression, expected "Bool"
/// @ test-loop-e4
unknown symbol "error"
/// @ test-loop-e6
got void expression, expected "Bool"
/// @ test-loop-e7
expected space after "while", got "new-line"
/// @ test-loop-e8
expected new-line after "continue", got " "
/// @ test-loop-e9
"break" used not inside loop
/// @ test-loop-e10
expected new-line after "break", got " "
/// @ test-loop-e11
loop is infinite
/// @ test-loop-e12
loop is infinite
/// @ test-loop-e13
using "!" where error is not propagated
/// @@ test-for-loop
/// @ test-for-loop-0
uint8_t aux_Int_0 = 0;
    do {
        uint8_t n = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < 0x05)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Int_0;
        aux_Int_0 += 0x01;
        ut_M_i = n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-1
uint32_t aux_Int_0 = 0;
    uint64_t aux_Int_1 = 0;
    uint64_t aux_Int_2 = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    aux_Int_2 = ut_M_t->num;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_length(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(aux_Int_0));
    aux_Int_1 = aux_Int_0 + 0x02;
    do {
        uint64_t n = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_2 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Int_2;
        aux_Int_2 += 0x01;
        ut_M_i = (n > UINT32_MAX)? UINT32_MAX: n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-2
char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    uint32_t aux_Int_0 = 0;
    Byte* aux_Buffer_0 = NULL;
    Seq_Length aux_Buffer_0_Max_length = 0;
    Seq_Length* aux_Buffer_0_Length = &Lumi_empty_length;
    uint32_t aux_Int_2 = 0;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    aux_String_0_Max_length = ut_M_ostr_Max_length;
    aux_String_0_Length = ut_M_ostr_Length;
    aux_String_0 = ut_M_ostr;
    do {
        Char ch = 0;
        uint32_t aux_Int_1 = 0;
        LUMI_loop_depth = 3;
        String_length(aux_String_0, aux_String_0_Max_length, aux_String_0_Length, &(aux_Int_1));
        if (!(aux_Int_0 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        ch = aux_String_0[aux_Int_0];
        aux_Int_0 += 0x01;
        ut_M_c = ch;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    CHECK_REF(3, LUMI_block0_cleanup, ut_M_buff)
    aux_Buffer_0_Max_length = ut_M_buff_Max_length;
    aux_Buffer_0_Length = ut_M_buff_Length;
    aux_Buffer_0 = ut_M_buff;
    do {
        Byte y = 0;
        uint32_t aux_Int_3 = 0;
        LUMI_loop_depth = 3;
        Buffer_length(aux_Buffer_0, aux_Buffer_0_Max_length, aux_Buffer_0_Length, &(aux_Int_3));
        if (!(aux_Int_2 < aux_Int_3)) { LUMI_loop_depth = 1; goto LUMI_block2_cleanup; }
        y = aux_Buffer_0[aux_Int_2];
        aux_Int_2 += 0x01;
        ut_M_bt = y;
    LUMI_block2_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-3
uint32_t* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    uint32_t aux_Int_0 = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    aux_Array_0_Length = ut_M_arr_Length;
    aux_Array_0 = ut_M_arr;
    do {
        uint32_t n = 0;
        uint32_t aux_Int_1 = 0;
        LUMI_loop_depth = 3;
        Array_length(aux_Array_0, aux_Array_0_Length, &(aux_Int_1));
        if (!(aux_Int_0 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Array_0[aux_Int_0];
        aux_Int_0 += 0x01;
        ut_M_i = n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-4
char* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Seq_Length aux_Array_0_Value_length = 0;
    Seq_Length* aux_Array_0_Seq_length = NULL;
    uint32_t aux_Int_0 = 0;
    Byte* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    Seq_Length aux_Array_1_Value_length = 0;
    Seq_Length* aux_Array_1_Seq_length = NULL;
    uint32_t aux_Int_2 = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_sarr, ut_M_sarr_Refman)
    aux_Array_0_Length = ut_M_sarr_Length;
    aux_Array_0_Value_length = ut_M_sarr_Value_length;
    aux_Array_0_Seq_length = ut_M_sarr_Seq_length;
    aux_Array_0 = ut_M_sarr;
    do {
        char* s = NULL;
        Seq_Length s_Max_length = 0;
        Seq_Length* s_Length = &Lumi_empty_length;
        uint32_t aux_Int_1 = 0;
        char* aux_String_0 = NULL;
        Seq_Length aux_String_0_Max_length = 0;
        Seq_Length* aux_String_0_Length = &Lumi_empty_length;
        LUMI_loop_depth = 3;
        Array_length(aux_Array_0, aux_Array_0_Length, &(aux_Int_1));
        if (!(aux_Int_0 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        aux_String_0 = aux_Array_0 + aux_Int_0 * aux_Array_0_Value_length;
        aux_String_0_Max_length = aux_Array_0_Value_length;
        aux_String_0_Length = aux_Array_0_Seq_length + aux_Int_0;
        s_Max_length = aux_String_0_Max_length;
        s_Length = aux_String_0_Length;
        s = aux_String_0;
        aux_Int_0 += 0x01;
        String_clear(s, s_Max_length, s_Length);
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    CHECK_REF_REFMAN(3, LUMI_block0_cleanup, ut_M_barr, ut_M_barr_Refman)
    aux_Array_1_Length = ut_M_barr_Length;
    aux_Array_1_Value_length = ut_M_barr_Value_length;
    aux_Array_1_Seq_length = ut_M_barr_Seq_length;
    aux_Array_1 = ut_M_barr;
    do {
        Byte* bf = NULL;
        Seq_Length bf_Max_length = 0;
        Seq_Length* bf_Length = &Lumi_empty_length;
        uint32_t aux_Int_3 = 0;
        Byte* aux_Buffer_0 = NULL;
        Seq_Length aux_Buffer_0_Max_length = 0;
        Seq_Length* aux_Buffer_0_Length = &Lumi_empty_length;
        LUMI_loop_depth = 3;
        Array_length(aux_Array_1, aux_Array_1_Length, &(aux_Int_3));
        if (!(aux_Int_2 < aux_Int_3)) { LUMI_loop_depth = 1; goto LUMI_block2_cleanup; }
        aux_Buffer_0 = aux_Array_1 + aux_Int_2 * aux_Array_1_Value_length;
        aux_Buffer_0_Max_length = aux_Array_1_Value_length;
        aux_Buffer_0_Length = aux_Array_1_Seq_length + aux_Int_2;
        bf_Max_length = aux_Buffer_0_Max_length;
        bf_Length = aux_Buffer_0_Length;
        bf = aux_Buffer_0;
        aux_Int_2 += 0x01;
        Buffer_clear(bf, bf_Max_length, bf_Length);
    LUMI_block2_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-5
uint32_t n = 0;
    uint8_t aux_Int_0 = 0;
    do {
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < 0x05)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Int_0;
        aux_Int_0 += 0x01;
        ut_M_i = n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-6
uint8_t aux_Int_0 = 0;
    uint8_t aux_Int_1 = 0;
    do {
        uint8_t n = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < 0x05)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Int_0;
        aux_Int_0 += 0x01;
        ut_M_i = n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    do {
        uint8_t n = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_1 < 0x07)) { LUMI_loop_depth = 1; goto LUMI_block2_cleanup; }
        n = aux_Int_1;
        aux_Int_1 += 0x01;
        ut_M_i = n;
    LUMI_block2_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-7
uint8_t aux_Int_0 = 0;
    do {
        uint8_t n = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < (0x01 + 0x02))) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Int_0;
        aux_Int_0 += 0x01;
        ut_M_i = n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-8
uint8_t aux_Int_0 = 0;
    do {
        char sa[0x04] = {0};
        Seq_Length sa_Length[1] = {0};
        uint8_t n = 0;
        char* aux_String_0 = NULL;
        Seq_Length aux_String_0_Max_length = 0;
        Seq_Length* aux_String_0_Length = &Lumi_empty_length;
        uint32_t aux_Int_1 = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < 0x06)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Int_0;
        aux_Int_0 += 0x01;
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
            char sb[0x04] = {0};
            Seq_Length sb_Length[1] = {0};
            Char ch = 0;
            uint32_t aux_Int_2 = 0;
            LUMI_loop_depth = 5;
            String_length(aux_String_0, aux_String_0_Max_length, aux_String_0_Length, &(aux_Int_2));
            if (!(aux_Int_1 < aux_Int_2)) { LUMI_loop_depth = 3; goto LUMI_block3_cleanup; }
            ch = aux_String_0[aux_Int_1];
            aux_Int_1 += 0x01;
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
/// @ test-for-loop-9
char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    Byte* bf = NULL;
    Seq_Length bf_Max_length = 0;
    Seq_Length* bf_Length = &Lumi_empty_length;
    static char aux_String_0[] = {'t','e','x','t','\0',};
    Seq_Length aux_String_0_Max_length = sizeof(aux_String_0);
    Seq_Length aux_String_0_Length[1] = {sizeof(aux_String_0) - 1};
    char* aux_String_1 = NULL;
    Seq_Length aux_String_1_Max_length = 0;
    Seq_Length* aux_String_1_Length = &Lumi_empty_length;
    uint32_t aux_Int_0 = 0;
    static Byte aux_Buffer_0[] = {0xbe,0xaf,};
    Seq_Length aux_Buffer_0_Max_length = sizeof(aux_Buffer_0);
    Seq_Length aux_Buffer_0_Length[1] = {sizeof(aux_Buffer_0)};
    Byte* aux_Buffer_1 = NULL;
    Seq_Length aux_Buffer_1_Max_length = 0;
    Seq_Length* aux_Buffer_1_Length = &Lumi_empty_length;
    uint32_t aux_Int_2 = 0;
    s_Max_length = aux_String_0_Max_length;
    s_Length = aux_String_0_Length;
    s = aux_String_0;
    aux_String_1_Max_length = s_Max_length;
    aux_String_1_Length = s_Length;
    aux_String_1 = s;
    do {
        Char ch = 0;
        uint32_t aux_Int_1 = 0;
        LUMI_loop_depth = 3;
        String_length(aux_String_1, aux_String_1_Max_length, aux_String_1_Length, &(aux_Int_1));
        if (!(aux_Int_0 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        ch = aux_String_1[aux_Int_0];
        aux_Int_0 += 0x01;
        ut_M_c = ch;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    bf_Max_length = aux_Buffer_0_Max_length;
    bf_Length = aux_Buffer_0_Length;
    bf = aux_Buffer_0;
    aux_Buffer_1_Max_length = bf_Max_length;
    aux_Buffer_1_Length = bf_Length;
    aux_Buffer_1 = bf;
    do {
        Byte y = 0;
        uint32_t aux_Int_3 = 0;
        LUMI_loop_depth = 3;
        Buffer_length(aux_Buffer_1, aux_Buffer_1_Max_length, aux_Buffer_1_Length, &(aux_Int_3));
        if (!(aux_Int_2 < aux_Int_3)) { LUMI_loop_depth = 1; goto LUMI_block2_cleanup; }
        y = aux_Buffer_1[aux_Int_2];
        aux_Int_2 += 0x01;
        ut_M_bt = y;
    LUMI_block2_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-10
char sa[0x03 * 0x04] = {0};
    Seq_Length sa_Seq_length[0x03] = {0};
    Byte ba[0x03 * 0x04] = {0};
    Seq_Length ba_Seq_length[0x03] = {0};
    char* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Seq_Length aux_Array_0_Value_length = 0;
    Seq_Length* aux_Array_0_Seq_length = NULL;
    uint32_t aux_Int_0 = 0;
    Byte* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    Seq_Length aux_Array_1_Value_length = 0;
    Seq_Length* aux_Array_1_Seq_length = NULL;
    uint32_t aux_Int_2 = 0;
    /* initializing sa */
    aux_Array_0_Length = 0x03;
    aux_Array_0_Value_length = 0x04;
    aux_Array_0_Seq_length = sa_Seq_length;
    aux_Array_0 = sa;
    do {
        char* s = NULL;
        Seq_Length s_Max_length = 0;
        Seq_Length* s_Length = &Lumi_empty_length;
        uint32_t aux_Int_1 = 0;
        char* aux_String_0 = NULL;
        Seq_Length aux_String_0_Max_length = 0;
        Seq_Length* aux_String_0_Length = &Lumi_empty_length;
        LUMI_loop_depth = 3;
        Array_length(aux_Array_0, 0x03, &(aux_Int_1));
        if (!(aux_Int_0 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        aux_String_0 = aux_Array_0 + aux_Int_0 * 0x04;
        aux_String_0_Max_length = 0x04;
        aux_String_0_Length = aux_Array_0_Seq_length + aux_Int_0;
        s_Max_length = 0x04;
        s_Length = aux_String_0_Length;
        s = aux_String_0;
        aux_Int_0 += 0x01;
        String_clear(s, 0x04, s_Length);
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    /* initializing ba */
    aux_Array_1_Length = 0x03;
    aux_Array_1_Value_length = 0x04;
    aux_Array_1_Seq_length = ba_Seq_length;
    aux_Array_1 = ba;
    do {
        Byte* bf = NULL;
        Seq_Length bf_Max_length = 0;
        Seq_Length* bf_Length = &Lumi_empty_length;
        uint32_t aux_Int_3 = 0;
        Byte* aux_Buffer_0 = NULL;
        Seq_Length aux_Buffer_0_Max_length = 0;
        Seq_Length* aux_Buffer_0_Length = &Lumi_empty_length;
        LUMI_loop_depth = 3;
        Array_length(aux_Array_1, 0x03, &(aux_Int_3));
        if (!(aux_Int_2 < aux_Int_3)) { LUMI_loop_depth = 1; goto LUMI_block2_cleanup; }
        aux_Buffer_0 = aux_Array_1 + aux_Int_2 * 0x04;
        aux_Buffer_0_Max_length = 0x04;
        aux_Buffer_0_Length = aux_Array_1_Seq_length + aux_Int_2;
        bf_Max_length = 0x04;
        bf_Length = aux_Buffer_0_Length;
        bf = aux_Buffer_0;
        aux_Int_2 += 0x01;
        Buffer_clear(bf, 0x04, bf_Length);
    LUMI_block2_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-11
uint8_t aux_Int_0 = 0;
    aux_Int_0 = 0x02;
    do {
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < 0x06)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        aux_Int_0 += 0x01;
        ut_M_i = 0x01;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-12
char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    uint32_t aux_Int_0 = 0;
    Byte* aux_Buffer_0 = NULL;
    Seq_Length aux_Buffer_0_Max_length = 0;
    Seq_Length* aux_Buffer_0_Length = &Lumi_empty_length;
    uint32_t aux_Int_2 = 0;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    aux_String_0_Max_length = ut_M_ostr_Max_length;
    aux_String_0_Length = ut_M_ostr_Length;
    aux_String_0 = ut_M_ostr;
    do {
        uint32_t aux_Int_1 = 0;
        LUMI_loop_depth = 3;
        String_length(aux_String_0, aux_String_0_Max_length, aux_String_0_Length, &(aux_Int_1));
        if (!(aux_Int_0 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        aux_Int_0 += 0x01;
        ut_M_i = 0x01;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    CHECK_REF(3, LUMI_block0_cleanup, ut_M_buff)
    aux_Buffer_0_Max_length = ut_M_buff_Max_length;
    aux_Buffer_0_Length = ut_M_buff_Length;
    aux_Buffer_0 = ut_M_buff;
    do {
        uint32_t aux_Int_3 = 0;
        LUMI_loop_depth = 3;
        Buffer_length(aux_Buffer_0, aux_Buffer_0_Max_length, aux_Buffer_0_Length, &(aux_Int_3));
        if (!(aux_Int_2 < aux_Int_3)) { LUMI_loop_depth = 1; goto LUMI_block2_cleanup; }
        aux_Int_2 += 0x01;
        ut_M_i = 0x01;
    LUMI_block2_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-13
uint32_t aux_Int_0 = 0;
    uint32_t aux_Int_1 = 0;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_length(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length, &(aux_Int_0));
    aux_Int_1 = aux_Int_0;
    do {
        LUMI_loop_depth = 3;
        if (!(aux_Int_1 < 0x02)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        aux_Int_1 += 0x01;
        ut_M_i = 0x01;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-14
int64_t aux_Int_0 = 0;
    uint32_t aux_Int_1 = 0;
    aux_Int_0 = ut_M_i - 0x04;
    do {
        LUMI_loop_depth = 3;
        if (!(aux_Int_1 < aux_Int_0)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        aux_Int_1 += 0x01;
        ut_M_i = 0x01;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-e0
expected space after "for", got "("
/// @ test-for-loop-e1
expected space after "n", got "new-line"
/// @ test-for-loop-e2
expected "in " got "err"
/// @ test-for-loop-e3
cannot iterate void expression
/// @ test-for-loop-e4
got "String" expression, expected "Int"
/// @ test-for-loop-e5
unknown symbol "error"
/// @ test-for-loop-e6
cannot assign "String" into "Int"
/// @ test-for-loop-e7
using before declaration variable "n"
/// @@ test-testing
/// @ test-testing-a0
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    TEST_ASSERT(1, LUMI_block0_cleanup, ut_M_t->num == 0x02)
/// @ test-testing-a1
++LUMI_trace_ignore_count;
    CHECK_REF_REFMAN(1, LUMI_block1_cleanup, ut_M_t, ut_M_t_Refman)
    --LUMI_trace_ignore_count;
    TEST_FAIL(1, LUMI_block0_cleanup, 16, "error not raised")
    LUMI_block1_cleanup:
    (void)0;
    --LUMI_trace_ignore_count;
    LUMI_err = OK;
    LUMI_loop_depth = 1;
/// @ test-testing-a2
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
/// @ test-testing-a3
{char* LUMI_expected_error_prev;
    size_t LUMI_expected_error_trace_ignore_count_prev;
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
/// @ test-testing-a4
{char* LUMI_expected_error_prev;
    size_t LUMI_expected_error_trace_ignore_count_prev;
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
/// @ test-testing-a5
{char* LUMI_expected_error_prev;
    size_t LUMI_expected_error_trace_ignore_count_prev;
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
/// @ test-testing-a6
if (ut_M_b) {
        char s[0x04] = {0};
        Seq_Length s_Length[1] = {0};
        Char* aux_Array_0 = NULL;
        Seq_Length aux_Array_0_Length = 0;
        uint8_t aux_Int_0 = 0;
        /* initializing s */
        TEST_ASSERT(3, LUMI_block1_cleanup, ut_M_b)
        ++LUMI_trace_ignore_count;
        if (SAFE_SUM_LARGER(ut_M_i, 0x02, *(s_Length))) RAISE(4, LUMI_block2_cleanup, slice_index)
        aux_Array_0 = s + ut_M_i;
        aux_Array_0_Length = 0x02;
        --LUMI_trace_ignore_count;
        TEST_FAIL(4, LUMI_block1_cleanup, 16, "error not raised")
        LUMI_block2_cleanup:
        (void)0;
        --LUMI_trace_ignore_count;
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        do {
            Char* aux_Array_1 = NULL;
            Seq_Length aux_Array_1_Length = 0;
            LUMI_loop_depth = 3;
            if (!(aux_Int_0 < 0x03)) { LUMI_loop_depth = 1; goto LUMI_block3_cleanup; }
            aux_Int_0 += 0x01;
            ++LUMI_trace_ignore_count;
            if (SAFE_SUM_LARGER(ut_M_i, 0x02, *(s_Length))) RAISE(6, LUMI_block4_cleanup, slice_index)
            aux_Array_1 = s + ut_M_i;
            aux_Array_1_Length = 0x02;
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
/// @ test-testing-m0
Return_Code ut_M_fun(void);
Return_Code ut_M_fun_Mock(void);
Bool ut_M_fun_Mock_active = true;
Return_Code ut_M_fun(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    LUMI_err = ut_M_fun_Mock();
    CHECK(2, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
Return_Code ut_M_fun_Mock(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_fun_Mock_active) { return ut_M_fun(); }
    USER_RAISE(4, LUMI_block0_cleanup, NULL, 0)
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ test-testing-m1
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
/// @ test-testing-m2
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_meth(ut_M_Test* self, uint32_t x);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_Test_meth_Mock(ut_M_Test* self, uint32_t x);
Bool ut_M_Test_meth_Mock_active = true;
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_meth(ut_M_Test* self, uint32_t x) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test_meth_Mock(self, x);
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_Test_meth_Mock(ut_M_Test* self, uint32_t x) {
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_Test_meth_Mock_active) { ut_M_Test_meth(self, x); return; }
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-testing-m3
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, uint32_t x);
};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, uint32_t x);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_meth_Mock(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, uint32_t x);
Bool ut_M_Test_meth_Mock_active = true;
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth_Mock};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, uint32_t x) {
    unsigned LUMI_loop_depth = 1;
    self_Dynamic->meth(self, self_Dynamic, x);
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Test_meth_Mock(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, uint32_t x) {
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_Test_meth_Mock_active) { ut_M_Test_meth(self, self_Dynamic, x); return; }
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-testing-m4
void ut_M_fun(uint32_t x, uint32_t* y);
void ut_M_fun_Mock(uint32_t x, uint32_t* y);
Bool ut_M_fun_Mock_active = true;
void ut_M_fun(uint32_t x, uint32_t* y) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun_Mock(uint32_t x, uint32_t* y) {
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_fun_Mock_active) { ut_M_fun(x, &(*y)); return; }
    ut_M_fun(x, &(*y));
    ut_M_fun_Mock_active = false;
    ut_M_fun_Mock(x, &(*y));
    ut_M_fun_Mock_active = true;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-testing-m5
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_meth(ut_M_Test* self, uint32_t x, uint32_t* y);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_Test_meth_Mock(ut_M_Test* self, uint32_t x, uint32_t* y);
Bool ut_M_Test_meth_Mock_active = true;
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_meth(ut_M_Test* self, uint32_t x, uint32_t* y) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test_meth_Mock(self, x, &(*y));
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_Test_meth_Mock(ut_M_Test* self, uint32_t x, uint32_t* y) {
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
/// @ test-testing-m6
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, uint32_t x, uint32_t* y);
};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, uint32_t x, uint32_t* y);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_meth_Mock(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, uint32_t x, uint32_t* y);
Bool ut_M_Test_meth_Mock_active = true;
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth_Mock};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, uint32_t x, uint32_t* y) {
    unsigned LUMI_loop_depth = 1;
    self_Dynamic->meth(self, self_Dynamic, x, &(*y));
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Test_meth_Mock(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, uint32_t x, uint32_t* y) {
    unsigned LUMI_loop_depth = 1;
    if (!ut_M_Test_meth_Mock_active) { ut_M_Test_meth(self, self_Dynamic, x, &(*y)); return; }
    ut_M_Test_meth(self, self_Dynamic, x, &(*y));
    ut_M_Test_meth_Mock_active = false;
    ut_M_Test_meth_Mock(self, self_Dynamic, x, &(*y));
    ut_M_Test_meth_Mock_active = true;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-testing-m7
Return_Code ut_M_fun(void);
Return_Code sys_M_print_Mock(Char* text, Seq_Length text_Length);
Bool sys_M_print_Mock_active = true;
Return_Code ut_M_fun(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    static char aux_String_0[] = {'m','o','c','k',' ','p','r','i','n','t','\0',};
    Seq_Length aux_String_0_Max_length = sizeof(aux_String_0);
    Seq_Length aux_String_0_Length[1] = {sizeof(aux_String_0) - 1};
    static char aux_String_1[] = {'r','e','a','l','l','y',' ','p','r','i','n','t','\0',};
    Seq_Length aux_String_1_Max_length = sizeof(aux_String_1);
    Seq_Length aux_String_1_Length[1] = {sizeof(aux_String_1) - 1};
    LUMI_err = sys_M_print_Mock(aux_String_0, *aux_String_0_Length);
    CHECK(2, LUMI_block0_cleanup)
    LUMI_err = sys_M_print(aux_String_1, *aux_String_1_Length);
    CHECK(3, LUMI_block0_cleanup)
    sys_M_print_Mock_active = false;
    sys_M_print_Mock_active = true;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
Return_Code sys_M_print_Mock(Char* text, Seq_Length text_Length) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    if (!sys_M_print_Mock_active) { return sys_M_print(text, text_Length); }
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ test-testing-m8
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_new(ut_M_Test* self, uint32_t x);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_Test_new_Mock(ut_M_Test* self, uint32_t x);
Bool ut_M_Test_new_Mock_active = true;
void ut_M_fun(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_new(ut_M_Test* self, uint32_t x) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_Test_new_Mock(ut_M_Test* self, uint32_t x) {
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
    ut_M_Test_new_Mock(t, 0x02);
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
}
/// @ test-testing-t0
void ut_M_fun0(void);
void ut_M_fun1(void);
Return_Code ut_M_fun2(void);
Line_Count LUMI_file0_line_count[30] = {
    -1,-1, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0,
     0, 0, 0, 0,-1
};
Line_Count LUMI_file1_line_count[7] = {
    -1,-1,-1, 0,-1, 0,-1
};
File_Coverage LUMI_file_coverage[2] = {
    {"mock.5.lm", 30, LUMI_file0_line_count},
    {"path\\second.5.lm", 7, LUMI_file1_line_count}
};
void ut_M_fun0(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    uint32_t x = 0;
    uint32_t y = 0;
    uint8_t aux_Int_0 = 0;
    ++LUMI_file_coverage[0].line_count[2];
    x = 0x04;
    ++LUMI_file_coverage[0].line_count[3];
    x = 0x01;
    ++LUMI_file_coverage[0].line_count[4];
    y = 0x05;
    ++LUMI_file_coverage[0].line_count[5];
    y = x;
    ++LUMI_file_coverage[0].line_count[6];
    if (y > 0x03) {
        ++LUMI_file_coverage[0].line_count[7];
        y = 0x03;
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
            y = 0x01;
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
        static char aux_String_0[] = {'t','e','x','t','\0',};
        Seq_Length aux_String_0_Max_length = sizeof(aux_String_0);
        Seq_Length aux_String_0_Length[1] = {sizeof(aux_String_0) - 1};
        ++LUMI_trace_ignore_count;
        ++LUMI_file_coverage[0].line_count[13];
        x = 0;
        ++LUMI_file_coverage[0].line_count[14];
        LUMI_err = sys_M_print(aux_String_0, *aux_String_0_Length);
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
        x = 0x01;
        ++LUMI_file_coverage[0].line_count[18];
        x = 0x02;
    LUMI_block8_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    ++LUMI_file_coverage[0].line_count[19];
    if (x > 0x03) {
        ++LUMI_file_coverage[0].line_count[20];
        LUMI_loop_depth = 0; goto LUMI_block9_cleanup;
    LUMI_block9_cleanup:
        (void)0;
    }
    else {
        ++LUMI_file_coverage[0].line_count[22];
        x = 0x03;
    LUMI_block11_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    ++LUMI_file_coverage[0].line_count[23];
    do {
        LUMI_loop_depth = 3;
        ++LUMI_file_coverage[0].line_count[24];
        if (!(x > 0x01)) { LUMI_loop_depth = 1; goto LUMI_block12_cleanup; }
        ++LUMI_file_coverage[0].line_count[25];
        if (x == 0x05) {
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
        uint8_t n = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < 0x03)) { LUMI_loop_depth = 1; goto LUMI_block14_cleanup; }
        n = aux_Int_0;
        aux_Int_0 += 0x01;
        ++LUMI_file_coverage[0].line_count[28];
        x = y;
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
Return_Code ut_M_fun2(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ++LUMI_file_coverage[1].line_count[5];
    ut_M_fun1();
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void new_Mock(Bool* allocate_success) { }
Return_Code delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Bool LUMI_success = true;
    LUMI_success &= LUMI_run_test("fun2", ut_M_fun2);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 2);
    return LUMI_success? LUMI_err : FAIL;
LUMI_block0_cleanup:
    return LUMI_err;
}
TEST_MAIN_FUNC
/// @ test-testing-t1
void ut_M_fun(void);
Return_Code second_M_fun0(void);
Return_Code second_M_fun1(void);
Line_Count LUMI_file0_line_count[6] = {
    -1,-1, 0,-1,-1,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.5.lm", 6, LUMI_file0_line_count}
};
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    uint32_t x = 0;
    ++LUMI_file_coverage[0].line_count[2];
LUMI_block0_cleanup:
    (void)0;
}
Return_Code second_M_fun0(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
Return_Code second_M_fun1(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void new_Mock(Bool* allocate_success) { }
Return_Code delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Return_Code LUMI_err = OK;
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
/// @ test-testing-mg0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    Seq_Length s_Max_length;
    Seq_Length* s_Length;
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
/// @ test-testing-mg1
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
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
MAIN_FUNC
/// @ test-testing-mg2
void new_Mock(Bool* allocate_success);
void new_Mock(Bool* allocate_success) {
    unsigned LUMI_loop_depth = 1;
    *allocate_success = false;
LUMI_block0_cleanup:
    (void)0;
}
Return_Code delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
MAIN_FUNC
/// @ test-testing-r0
Ref r = NULL;
/// @ test-testing-r1
Ref r = NULL;
    r = ut_M_ostr;
/// @ test-testing-r2
Ref r = NULL;
    r = NULL;
/// @ test-testing-r3
Ref r = NULL;
    r = ut_M_ostr;
/// @ test-testing-r4
Ref r = NULL;
    TEST_ASSERT(2, LUMI_block0_cleanup, (void*)r == r)
/// @ test-testing-e0
got "Int" expression, expected "Bool"
/// @ test-testing-e1
unknown symbol "error"
/// @ test-testing-e2
unknown symbol "error"
/// @ test-testing-e3
test function cannot have arguments
/// @ test-testing-e4
test function cannot have arguments
/// @ test-testing-e5
mocking unknown function "error"
/// @ test-testing-e6
unknown type "Error"
/// @ test-testing-e7
unknown method "error" of type "Test"
/// @ test-testing-e8
expected access "user" , got "owner"
/// @ test-testing-e9
non matching types "Int" and "String"
/// @ test-testing-e10
non matching subtypes "Char" and "Int"
/// @ test-testing-e11
expected ! after "assert", got " "
/// @ test-testing-e12
expected ! after "assert-error", got " "
/// @ test-testing-e13
expected space after "mock", got "("
/// @ test-testing-e14
already mocking function "fun"
/// @ test-testing-e15
already mocking function "fun"
/// @ test-testing-e16
already mocking global delete
/// @ test-testing-e17
already mocking delete of type "Test"
/// @ test-testing-e18
unknown operator ""
/// @ test-testing-e19
expected space after ",", got """
/// @ test-testing-e20
no '"' around string constant " "error""
/// @ test-testing-e21
no '"' around string constant "error"
/// @ test-testing-e22
already mocking global new
/// @ test-testing-e23
mock new should have only single Bool output
/// @ test-testing-e24
mock new should have only single Bool output
/// @ test-testing-e25
mock new should have only single Bool output
/// @ test-testing-e26
mock new should have only single Bool output
/// @ test-testing-e27
mock delete should have no arguments
/// @ test-testing-e28
mock delete should have no arguments
/// @ test-testing-e29
type "Func" has no member "error"
/// @ test-testing-e30
accessing mock function field in dynamic call to "meth"
/// @ test-testing-e31
expected space after "test", got "new-line"
/// @ test-testing-e32
constructor did not initialize field "s"
/// @ test-testing-e33
no need to mark test functions with "!"
/// @ test-testing-e34
no error raised in expression
/// @ test-testing-e35
using "!" where error is not propagated
/// @ test-testing-e36
using "!" where error is not propagated
/// @@ test-native
/// @ test-native-i0
#include <native.h>
/// @ test-native-i1
#include <first.h>
#include <second.h>
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
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
/// @ test-native-f0
void ut_M_call(void);
void ut_M_call(void) {
    unsigned LUMI_loop_depth = 1;
    external();
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-native-f1
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_call(void);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_call(void) {
    unsigned LUMI_loop_depth = 1;
    uint32_t i = 0;
    char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    uint32_t* a = NULL;
    Seq_Length a_Length = 0;
    ut_M_Test* t = NULL;
    ut_M_Test_Dynamic* t_Dynamic = NULL;
    i = external(0x05, s, a, (void*)t);
    i = (((0x02 * external(0x05, s, a, (void*)t)) + 0x03) > UINT32_MAX)? UINT32_MAX: ((0x02 * external(0x05, s, a, (void*)t)) + 0x03);
    external(0x05, s, a, (void*)t);
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-native-f2
void ut_M_call(void);
void ut_M_call(void) {
    unsigned LUMI_loop_depth = 1;
    SOME_External_func();
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-native-f3
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_call(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
void ut_M_call(void) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test* t = NULL;
    t = ((ut_M_Test*)external());
    external();
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-native-v0
void ut_M_use(void);
void ut_M_use(void) {
    unsigned LUMI_loop_depth = 1;
    x = 0x02;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-native-v1
void ut_M_use(void);
void ut_M_use(void) {
    unsigned LUMI_loop_depth = 1;
    SOME_External_var = 0x02;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-native-c0
void ut_M_get(uint32_t* x);
void ut_M_get(uint32_t* x) {
    unsigned LUMI_loop_depth = 1;
    *x = ((VALUE + BYTE) > UINT32_MAX)? UINT32_MAX: (VALUE + BYTE);
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-native-c1
void ut_M_get(uint32_t* x);
void ut_M_get(uint32_t* x) {
    unsigned LUMI_loop_depth = 1;
    *x = SOME_External_const;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-native-t0
void ut_M_call(void);
void ut_M_call(void) {
    unsigned LUMI_loop_depth = 1;
    Native n = 0;
    n = external(n);
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-native-t1
void ut_M_call(void);
void ut_M_call(void) {
    unsigned LUMI_loop_depth = 1;
    SOME_External_type n = 0;
    n = SOME_External_func(n);
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-native-b0
#define HAS_SOME_DEFINE
uint32_t ut_M_x = 0;
uint32_t ut_M_y = 0;
/// @ test-native-b1
#ifdef __UNIX__
    *io = 0x03;
    #else
    *io = 0x04;
    #endif
/// @ test-native-e0
expected space after "native", got "("
/// @ test-native-e1
expected space after "native", got "new-line"
/// @ test-native-e2
unknown "native" keyword "error"
/// @ test-native-ei0
no '"' around string constant "native.h"
/// @ test-native-ef0
redefinition of function "error"
/// @ test-native-ef1
error raising native function
/// @ test-native-ef2
more than one output to native function
/// @ test-native-ef3
owner argument to native function
/// @ test-native-ef4
var output to native function
/// @ test-native-ef5
argument "s" access should not be "s-var" for non-primitive type "String"
/// @ test-native-ef6
managed argument to native function
/// @ test-native-ef7
owner argument to native function
/// @ test-native-ef8
owner argument to native function
/// @ test-native-ef9
managed argument to native function
/// @ test-native-ef10
owner argument to native function
/// @ test-native-ef11
argument "s" access should not be "s-var" for non-primitive type "String"
/// @ test-native-ef12
output argument in native function call
/// @ test-native-ef13
no '"' around string constant "error"
/// @ test-native-ef14
user output to native function with non struct type "String"
/// @ test-native-ef15
user output to native function with non struct type "Array"
/// @ test-native-ef16
user output to native function with non struct type "Error"
/// @ test-native-ev0
only primitive types supported for native variable, got "String"
/// @ test-native-ev1
no '"' around string constant "error"
/// @ test-native-ec0
no '"' around string constant "error"
/// @ test-native-ec1
Only numeric typed native constant supported, got "Bool"
/// @ test-native-ec2
sequence length is not constant
/// @ test-native-et0
no '"' around string constant "error"
/// @ test-native-eb0
no '"' around string constant "#define error"
/// @ test-native-eb1
no '"' around string constant "#ifdef error"
/// @@ test-parameter-type
/// @ test-parameter-type-0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
Return_Code ut_M_Test_set(ut_M_Test* self, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Return_Code ut_M_Test_set(ut_M_Test* self, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic) {
    Return_Code LUMI_err = OK;
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
/// @ test-parameter-type-1
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
    if (self->item_Dynamic != NULL) self->item_Dynamic->_del(self->item, self->item_Dynamic);
    free(self->item);
}
/// @ test-parameter-type-2
typedef struct ut_M_StructA ut_M_StructA;
typedef struct ut_M_StructB ut_M_StructB;
typedef struct ut_M_StructC ut_M_StructC;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_StructA {
    uint32_t x;
};
struct ut_M_StructB {
    uint32_t x;
};
struct ut_M_StructC {
    uint32_t x;
};
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
void ut_M_StructA_Del(ut_M_StructA* self);
void ut_M_StructB_Del(ut_M_StructB* self);
void ut_M_StructC_Del(ut_M_StructC* self);
void ut_M_Test_set(ut_M_Test* self, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Generic_Type* second, Ref_Manager* second_Refman, Generic_Type_Dynamic* second_Dynamic, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_use(ut_M_StructA* first, Ref_Manager* first_Refman, ut_M_StructB* second, Ref_Manager* second_Refman, ut_M_StructC* third, Ref_Manager* third_Refman);
Generic_Type_Dynamic ut_M_StructA_dynamic = {(Dynamic_Del)ut_M_StructA_Del};
Generic_Type_Dynamic ut_M_StructB_dynamic = {(Dynamic_Del)ut_M_StructB_Del};
Generic_Type_Dynamic ut_M_StructC_dynamic = {(Dynamic_Del)ut_M_StructC_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_StructA_Del(ut_M_StructA* self) {
    if (self == NULL) return;
}
void ut_M_StructB_Del(ut_M_StructB* self) {
    if (self == NULL) return;
}
void ut_M_StructC_Del(ut_M_StructC* self) {
    if (self == NULL) return;
}
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
void ut_M_use(ut_M_StructA* first, Ref_Manager* first_Refman, ut_M_StructB* second, Ref_Manager* second_Refman, ut_M_StructC* third, Ref_Manager* third_Refman) {
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
    t->first_Dynamic = &ut_M_StructA_dynamic;
    t->first = first;
    LUMI_inc_ref(second_Refman);
    LUMI_dec_ref(t->second_Refman);
    t->second_Refman = second_Refman;
    t->second_Dynamic = &ut_M_StructB_dynamic;
    t->second = second;
    LUMI_inc_ref(third_Refman);
    LUMI_dec_ref(t->third_Refman);
    t->third_Refman = third_Refman;
    t->third_Dynamic = &ut_M_StructC_dynamic;
    t->third = third;
    ut_M_Test_set(t, first, first_Refman, &ut_M_StructA_dynamic, second, second_Refman, &ut_M_StructB_dynamic, third, third_Refman, &ut_M_StructC_dynamic);
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
}
/// @ test-parameter-type-3
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Base {
    uint32_t x;
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
/// @ test-parameter-type-4
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_d, ut_M_d_Refman)
    LUMI_inc_ref(ut_M_t_Refman);
    LUMI_dec_ref(ut_M_d->item_Refman);
    ut_M_d->item_Refman = ut_M_t_Refman;
    ut_M_d->item_Dynamic = &ut_M_Test_dynamic;
    ut_M_d->item = ut_M_t;
/// @ test-parameter-type-5
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_d, ut_M_d_Refman)
    LUMI_inc_ref(ut_M_d->item_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = ut_M_d->item_Refman;
    ut_M_t = ut_M_d->item;
/// @ test-parameter-type-6
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
    void (*fun)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic, void (*fun)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic));
};
void ut_M_Test_meth(ut_M_Test* self, void (*fun)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic, void (*fun)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic)));
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_meth(ut_M_Test* self, void (*fun)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic, void (*fun)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic))) {
    unsigned LUMI_loop_depth = 1;
    void (*funv)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic, void (*funa)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic)) = NULL;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ test-parameter-type-8
ut_M_Data ad[0x05] = {0};
    /* initializing ad */
    LUMI_inc_ref((ad + 0x02)->item_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = (ad + 0x02)->item_Refman;
    ut_M_t = (ad + 0x02)->item;
/// @ test-parameter-type-10
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_d_Refman)
    ut_M_Data_set(ut_M_d, NULL, NULL);
/// @ test-parameter-type-11
ut_M_Data dr_Var = {0};
    ut_M_Data* dr = NULL;
    dr = &dr_Var;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, dr->item, dr->item_Refman)
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ((ut_M_Data*)(dr->item))->item, ((ut_M_Data*)(dr->item))->item_Refman)
    LUMI_inc_ref(((ut_M_Data*)(((ut_M_Data*)(dr->item))->item))->item_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = ((ut_M_Data*)(((ut_M_Data*)(dr->item))->item))->item_Refman;
    ut_M_t = ((ut_M_Data*)(((ut_M_Data*)(dr->item))->item))->item;
/// @ test-parameter-type-12
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_d_Refman)
    LUMI_var_dec_ref(*to_Refman);
    ut_M_Data_set(ut_M_d, *to, &ut_M_Test_dynamic);
    *to = NULL;
    *to_Refman = NULL;
/// @ test-parameter-type-13
ut_M_Test* aux_Test_0 = NULL;
    Ref_Manager* aux_Test_0_Refman = NULL;
    CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_d_Refman)
    ut_M_Data_get(ut_M_d, (void*)&(ut_M_t), &(ut_M_t_Refman), &dynamic_Void);
    CHECK_REFMAN(2, LUMI_block0_cleanup, ut_M_d_Refman)
    ut_M_Data_get(ut_M_d, (void*)&(aux_Test_0), &(aux_Test_0_Refman), &dynamic_Void);
    CHECK_REFMAN(2, LUMI_block0_cleanup, aux_Test_0_Refman)
    ut_M_Test_meth(aux_Test_0);
/// @ test-parameter-type-14
ut_M_Data dg_Var = {0};
    ut_M_Data* dg = NULL;
    dg = &dg_Var;
/// @ test-parameter-type-15
ut_M_Data* dg = NULL;
    CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_d_Refman)
    dg = ut_M_d;
/// @ test-parameter-type-16
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_d_Refman)
    LUMI_var_dec_ref(*to_Refman);
    ut_M_Data_set(ut_M_d, *to, &ut_M_Test_dynamic);
    *to = NULL;
    *to_Refman = NULL;
/// @ test-parameter-type-17
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
/// @ test-parameter-type-18
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
/// @ test-parameter-type-19
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_Base {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Test {
    ut_M_Base _base;
};
void ut_M_MyStruct_meth(ut_M_MyStruct* self);
void ut_M_MyStruct_Del(ut_M_MyStruct* self);
void ut_M_Base_get(ut_M_Base* self, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Test_set(ut_M_Test* self, ut_M_MyStruct* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Return_Code ut_M_fun(ut_M_Test* test, ut_M_MyStruct* f, Ref_Manager* f_Refman);
Generic_Type_Dynamic ut_M_MyStruct_dynamic = {(Dynamic_Del)ut_M_MyStruct_Del};
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_MyStruct_meth(ut_M_MyStruct* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_MyStruct_Del(ut_M_MyStruct* self) {
    if (self == NULL) return;
}
void ut_M_Base_get(ut_M_Base* self, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
void ut_M_Test_set(ut_M_Test* self, ut_M_MyStruct* f, Ref_Manager* f_Refman) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(f_Refman);
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(self->_base.item_Refman);
    self->_base.item_Refman = f_Refman;
    self->_base.item_Dynamic = &ut_M_MyStruct_dynamic;
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
Return_Code ut_M_fun(ut_M_Test* test, ut_M_MyStruct* f, Ref_Manager* f_Refman) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_MyStruct* aux_MyStruct_0 = NULL;
    Ref_Manager* aux_MyStruct_0_Refman = NULL;
    LUMI_inc_ref(f_Refman);
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(test->_base.item_Refman);
    test->_base.item_Refman = f_Refman;
    test->_base.item_Dynamic = &ut_M_MyStruct_dynamic;
    test->_base.item = f;
    ut_M_Test_set(test, f, f_Refman);
    LUMI_inc_ref(test->_base.item_Refman);
    LUMI_dec_ref(f_Refman);
    f_Refman = test->_base.item_Refman;
    f = test->_base.item;
    ut_M_Base_get(&(test->_base), (void*)&(f), &(f_Refman), &dynamic_Void);
    ut_M_Base_get(&(test->_base), (void*)&(aux_MyStruct_0), &(aux_MyStruct_0_Refman), &dynamic_Void);
    CHECK_REF_REFMAN(16, LUMI_block0_cleanup, aux_MyStruct_0, aux_MyStruct_0_Refman)
    ut_M_MyStruct_meth(aux_MyStruct_0);
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(aux_MyStruct_0_Refman);
    LUMI_dec_ref(f_Refman);
    return LUMI_err;
}
/// @ test-parameter-type-20
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
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
void ut_M_MyStruct_meth(ut_M_MyStruct* self);
void ut_M_MyStruct_Del(ut_M_MyStruct* self);
void ut_M_Base_set(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
void ut_M_Base_get(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Test_set(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
void ut_M_Test_get(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
Return_Code ut_M_mock(ut_M_Test* test, Ref_Manager* test_Refman, ut_M_Test_Dynamic* test_Dynamic, ut_M_MyStruct* f, Ref_Manager* f_Refman);
Generic_Type_Dynamic ut_M_MyStruct_dynamic = {(Dynamic_Del)ut_M_MyStruct_Del};
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_set, ut_M_Base_get};
ut_M_Test_Dynamic ut_M_Test_dynamic = {{(Dynamic_Del)ut_M_Test_Del, (void (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic))ut_M_Test_set, (void (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic))ut_M_Test_get}};
void ut_M_MyStruct_meth(ut_M_MyStruct* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_MyStruct_Del(ut_M_MyStruct* self) {
    if (self == NULL) return;
}
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
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
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
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), &(self_Dynamic->_base));
}
Return_Code ut_M_mock(ut_M_Test* test, Ref_Manager* test_Refman, ut_M_Test_Dynamic* test_Dynamic, ut_M_MyStruct* f, Ref_Manager* f_Refman) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_MyStruct* aux_MyStruct_0 = NULL;
    Ref_Manager* aux_MyStruct_0_Refman = NULL;
    LUMI_inc_ref(test_Refman);
    LUMI_inc_ref(f_Refman);
    CHECK_REFMAN(12, LUMI_block0_cleanup, test_Refman)
    test_Dynamic->_base.set(&(test->_base), &(test_Dynamic->_base), f, f_Refman, &ut_M_MyStruct_dynamic);
    CHECK_REFMAN(13, LUMI_block0_cleanup, test_Refman)
    test_Dynamic->_base.get(&(test->_base), &(test_Dynamic->_base), (void*)&(f), &(f_Refman), &dynamic_Void);
    CHECK_REFMAN(14, LUMI_block0_cleanup, test_Refman)
    test_Dynamic->_base.get(&(test->_base), &(test_Dynamic->_base), (void*)&(aux_MyStruct_0), &(aux_MyStruct_0_Refman), &dynamic_Void);
    CHECK_REF_REFMAN(14, LUMI_block0_cleanup, aux_MyStruct_0, aux_MyStruct_0_Refman)
    ut_M_MyStruct_meth(aux_MyStruct_0);
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(aux_MyStruct_0_Refman);
    LUMI_dec_ref(f_Refman);
    LUMI_dec_ref(test_Refman);
    return LUMI_err;
}
/// @ test-parameter-type-21
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
/// @ test-parameter-type-eg0
expected "}" after type parameters, got "new-line"
/// @ test-parameter-type-eg1
declared variable with generic subtype "Generic"
/// @ test-parameter-type-eg2
argument "error" access should not be "copy" for non-primitive type "Generic Type"
/// @ test-parameter-type-eg3
cannot assign "String" into "Generic Type"
/// @ test-parameter-type-eg4
cannot assign "Generic Type" into "String"
/// @ test-parameter-type-eg5
declared variable with generic subtype "Generic"
/// @ test-parameter-type-eg6
cannot assign generic subtype "Second" into different generic subtype "First"
/// @ test-parameter-type-eg7
illegal type parameter name "error"
/// @ test-parameter-type-eg11
too few parameter given for type "Test"
/// @ test-parameter-type-eg12
no parameter given for type with parameters "Base"
/// @ test-parameter-type-eg13
parameter given for type with no parameters "Base"
/// @ test-parameter-type-eg14
too many parameters given for type "Base"
/// @ test-parameter-type-eg15
too few parameter given for type "Base"
/// @ test-parameter-type-ec0
unsupported primitive parameter type "Int"
/// @ test-parameter-type-ec1
too many parameters given for type "Data"
/// @ test-parameter-type-ec2
unknown type "Error"
/// @ test-parameter-type-ec3
parameter given for type with no parameters "Char"
/// @ test-parameter-type-ec4
cannot assign "Generic Type" into "String"
/// @ test-parameter-type-ec5
cannot assign type "Data" with no parameter into same type with parameter "Test"
/// @ test-parameter-type-ec6
cannot assign "Test" into "String"
/// @ test-parameter-type-ec7
array as parameter type is unsupported
/// @ test-parameter-type-ec8
string as parameter type is unsupported
/// @ test-parameter-type-ec8
buffer as parameter type is unsupported
/// @@ test-parameter-inheritance
/// @ test-parameter-inheritance-0
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_Base {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Test {
    ut_M_Base _base;
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self);
void ut_M_Base_Del(ut_M_Base* self);
Return_Code ut_M_Test_set(ut_M_Test* self, ut_M_MyStruct* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman);
Generic_Type_Dynamic ut_M_MyStruct_dynamic = {(Dynamic_Del)ut_M_MyStruct_Del};
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_MyStruct_Del(ut_M_MyStruct* self) {
    if (self == NULL) return;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Return_Code ut_M_Test_set(ut_M_Test* self, ut_M_MyStruct* f, Ref_Manager* f_Refman) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Test* aux_Test_0 = NULL;
    LUMI_inc_ref(f_Refman);
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(self->_base.item_Refman);
    self->_base.item_Refman = f_Refman;
    self->_base.item_Dynamic = &ut_M_MyStruct_dynamic;
    self->_base.item = f;
    INIT_NEW(8, LUMI_block0_cleanup, aux_Test_0, ut_M_Test, 1);
    LUMI_err = ut_M_Test_set(aux_Test_0, f, f_Refman);
    CHECK(8, LUMI_block0_cleanup)
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
void ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {{0}};
    ut_M_Test* t = NULL;
    LUMI_inc_ref(f_Refman);
    t = &t_Var;
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(t->_base.item_Refman);
    t->_base.item_Refman = f_Refman;
    t->_base.item_Dynamic = &ut_M_MyStruct_dynamic;
    t->_base.item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_dec_ref(f_Refman);
}
/// @ test-parameter-inheritance-1
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_Base {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Test {
    ut_M_Base _base;
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self);
void ut_M_Base_Del(ut_M_Base* self);
Return_Code ut_M_Test_set(ut_M_Test* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, ut_M_MyStruct* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman);
Generic_Type_Dynamic ut_M_MyStruct_dynamic = {(Dynamic_Del)ut_M_MyStruct_Del};
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_MyStruct_Del(ut_M_MyStruct* self) {
    if (self == NULL) return;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Return_Code ut_M_Test_set(ut_M_Test* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, ut_M_MyStruct* f, Ref_Manager* f_Refman) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Test* aux_Test_0 = NULL;
    LUMI_inc_ref(i_Refman);
    LUMI_inc_ref(f_Refman);
    LUMI_inc_ref(i_Refman);
    LUMI_dec_ref(self->_base.item_Refman);
    self->_base.item_Refman = i_Refman;
    self->_base.item_Dynamic = i_Dynamic;
    self->_base.item = i;
    INIT_NEW(8, LUMI_block0_cleanup, aux_Test_0, ut_M_Test, 1);
    LUMI_err = ut_M_Test_set(aux_Test_0, f, f_Refman, &ut_M_MyStruct_dynamic, f, f_Refman);
    CHECK(8, LUMI_block0_cleanup)
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
void ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {{0}};
    ut_M_Test* t = NULL;
    LUMI_inc_ref(f_Refman);
    t = &t_Var;
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(t->_base.item_Refman);
    t->_base.item_Refman = f_Refman;
    t->_base.item_Dynamic = &ut_M_MyStruct_dynamic;
    t->_base.item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_dec_ref(f_Refman);
}
/// @ test-parameter-inheritance-2
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Top ut_M_Top;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_MyStruct {
    uint32_t x;
};
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
void ut_M_MyStruct_Del(ut_M_MyStruct* self);
void ut_M_Base_set(ut_M_Base* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Mid_set(ut_M_Mid* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self);
void ut_M_Top_set(ut_M_Top* self, ut_M_MyStruct* f, Ref_Manager* f_Refman);
void ut_M_Top_Del(ut_M_Top* self);
Return_Code ut_M_Test_set(ut_M_Test* self, ut_M_MyStruct* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman);
Generic_Type_Dynamic ut_M_MyStruct_dynamic = {(Dynamic_Del)ut_M_MyStruct_Del};
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Top_dynamic = {(Dynamic_Del)ut_M_Top_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_MyStruct_Del(ut_M_MyStruct* self) {
    if (self == NULL) return;
}
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
void ut_M_Top_set(ut_M_Top* self, ut_M_MyStruct* f, Ref_Manager* f_Refman) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(f_Refman);
    ut_M_Mid_set(&(self->_base), f, f_Refman, &ut_M_MyStruct_dynamic);
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(self->_base._base.item_Refman);
    self->_base._base.item_Refman = f_Refman;
    self->_base._base.item_Dynamic = &ut_M_MyStruct_dynamic;
    self->_base._base.item = f;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(f_Refman);
}
void ut_M_Top_Del(ut_M_Top* self) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base));
}
Return_Code ut_M_Test_set(ut_M_Test* self, ut_M_MyStruct* f, Ref_Manager* f_Refman) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Top* aux_Top_0 = NULL;
    ut_M_Test* aux_Test_0 = NULL;
    ut_M_Top* aux_Top_1 = NULL;
    LUMI_inc_ref(f_Refman);
    ut_M_Top_set(&(self->_base), f, f_Refman);
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(self->_base._base._base.item_Refman);
    self->_base._base._base.item_Refman = f_Refman;
    self->_base._base._base.item_Dynamic = &ut_M_MyStruct_dynamic;
    self->_base._base._base.item = f;
    INIT_NEW(16, LUMI_block0_cleanup, aux_Top_0, ut_M_Top, 1);
    ut_M_Top_set(aux_Top_0, f, f_Refman);
    INIT_NEW(17, LUMI_block0_cleanup, aux_Test_0, ut_M_Test, 1);
    LUMI_err = ut_M_Test_set(aux_Test_0, f, f_Refman);
    CHECK(17, LUMI_block0_cleanup)
    INIT_NEW(18, LUMI_block0_cleanup, aux_Top_1, ut_M_Top, 1);
    ut_M_Mid_set(&(aux_Top_1->_base), f, f_Refman, &ut_M_MyStruct_dynamic);
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
void ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {{{{0}}}};
    ut_M_Test* t = NULL;
    LUMI_inc_ref(f_Refman);
    t = &t_Var;
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(t->_base._base._base.item_Refman);
    t->_base._base._base.item_Refman = f_Refman;
    t->_base._base._base.item_Dynamic = &ut_M_MyStruct_dynamic;
    t->_base._base._base.item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_dec_ref(f_Refman);
}
/// @ test-parameter-inheritance-3
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_Base {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Test {
    ut_M_Base _base;
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self);
void ut_M_Base_Del(ut_M_Base* self);
Return_Code ut_M_Test_set(ut_M_Test* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, ut_M_MyStruct* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman);
Generic_Type_Dynamic ut_M_MyStruct_dynamic = {(Dynamic_Del)ut_M_MyStruct_Del};
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_MyStruct_Del(ut_M_MyStruct* self) {
    if (self == NULL) return;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Return_Code ut_M_Test_set(ut_M_Test* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, ut_M_MyStruct* f, Ref_Manager* f_Refman) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Test* aux_Test_0 = NULL;
    LUMI_inc_ref(i_Refman);
    LUMI_inc_ref(f_Refman);
    LUMI_inc_ref(i_Refman);
    LUMI_dec_ref(self->_base.item_Refman);
    self->_base.item_Refman = i_Refman;
    self->_base.item_Dynamic = i_Dynamic;
    self->_base.item = i;
    INIT_NEW(8, LUMI_block0_cleanup, aux_Test_0, ut_M_Test, 1);
    LUMI_err = ut_M_Test_set(aux_Test_0, f, f_Refman, &ut_M_MyStruct_dynamic, f, f_Refman);
    CHECK(8, LUMI_block0_cleanup)
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
void ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test t_Var = {{0}};
    ut_M_Test* t = NULL;
    LUMI_inc_ref(f_Refman);
    t = &t_Var;
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(t->_base.item_Refman);
    t->_base.item_Refman = f_Refman;
    t->_base.item_Dynamic = &ut_M_MyStruct_dynamic;
    t->_base.item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_dec_ref(f_Refman);
}
/// @ test-parameter-inheritance-4
typedef struct ut_M_StructA ut_M_StructA;
typedef struct ut_M_StructB ut_M_StructB;
typedef struct ut_M_StructC ut_M_StructC;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Top ut_M_Top;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_StructA {
    uint32_t x;
};
struct ut_M_StructB {
    uint32_t x;
};
struct ut_M_StructC {
    uint32_t x;
};
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
void ut_M_StructA_Del(ut_M_StructA* self);
void ut_M_StructB_Del(ut_M_StructB* self);
void ut_M_StructC_Del(ut_M_StructC* self);
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Mid_set(ut_M_Mid* self, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, ut_M_StructB* second, Ref_Manager* second_Refman, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self);
void ut_M_Top_set(ut_M_Top* self, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, ut_M_StructB* second, Ref_Manager* second_Refman, ut_M_StructC* third, Ref_Manager* third_Refman);
void ut_M_Top_Del(ut_M_Top* self);
void ut_M_Test_set(ut_M_Test* self, ut_M_StructA* first, Ref_Manager* first_Refman, ut_M_StructB* second, Ref_Manager* second_Refman, ut_M_StructC* third, Ref_Manager* third_Refman);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_use(ut_M_StructA* first, Ref_Manager* first_Refman, ut_M_StructB* second, Ref_Manager* second_Refman, ut_M_StructC* third, Ref_Manager* third_Refman);
Generic_Type_Dynamic ut_M_StructA_dynamic = {(Dynamic_Del)ut_M_StructA_Del};
Generic_Type_Dynamic ut_M_StructB_dynamic = {(Dynamic_Del)ut_M_StructB_Del};
Generic_Type_Dynamic ut_M_StructC_dynamic = {(Dynamic_Del)ut_M_StructC_Del};
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Top_dynamic = {(Dynamic_Del)ut_M_Top_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_StructA_Del(ut_M_StructA* self) {
    if (self == NULL) return;
}
void ut_M_StructB_Del(ut_M_StructB* self) {
    if (self == NULL) return;
}
void ut_M_StructC_Del(ut_M_StructC* self) {
    if (self == NULL) return;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->second_Refman);
    LUMI_dec_ref(self->first_Refman);
}
void ut_M_Mid_set(ut_M_Mid* self, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, ut_M_StructB* second, Ref_Manager* second_Refman, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic) {
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
    self->_base.second_Dynamic = &ut_M_StructB_dynamic;
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
void ut_M_Top_set(ut_M_Top* self, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, ut_M_StructB* second, Ref_Manager* second_Refman, ut_M_StructC* third, Ref_Manager* third_Refman) {
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
    self->_base._base.second_Dynamic = &ut_M_StructB_dynamic;
    self->_base._base.second = second;
    LUMI_inc_ref(third_Refman);
    LUMI_dec_ref(self->_base.third_Refman);
    self->_base.third_Refman = third_Refman;
    self->_base.third_Dynamic = &ut_M_StructC_dynamic;
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
void ut_M_Test_set(ut_M_Test* self, ut_M_StructA* first, Ref_Manager* first_Refman, ut_M_StructB* second, Ref_Manager* second_Refman, ut_M_StructC* third, Ref_Manager* third_Refman) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(first_Refman);
    LUMI_inc_ref(second_Refman);
    LUMI_inc_ref(third_Refman);
    LUMI_inc_ref(first_Refman);
    LUMI_dec_ref(self->_base._base._base.first_Refman);
    self->_base._base._base.first_Refman = first_Refman;
    self->_base._base._base.first_Dynamic = &ut_M_StructA_dynamic;
    self->_base._base._base.first = first;
    LUMI_inc_ref(second_Refman);
    LUMI_dec_ref(self->_base._base._base.second_Refman);
    self->_base._base._base.second_Refman = second_Refman;
    self->_base._base._base.second_Dynamic = &ut_M_StructB_dynamic;
    self->_base._base._base.second = second;
    LUMI_inc_ref(third_Refman);
    LUMI_dec_ref(self->_base._base.third_Refman);
    self->_base._base.third_Refman = third_Refman;
    self->_base._base.third_Dynamic = &ut_M_StructC_dynamic;
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
void ut_M_use(ut_M_StructA* first, Ref_Manager* first_Refman, ut_M_StructB* second, Ref_Manager* second_Refman, ut_M_StructC* third, Ref_Manager* third_Refman) {
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
    t->_base._base._base.first_Dynamic = &ut_M_StructA_dynamic;
    t->_base._base._base.first = first;
    LUMI_inc_ref(second_Refman);
    LUMI_dec_ref(t->_base._base._base.second_Refman);
    t->_base._base._base.second_Refman = second_Refman;
    t->_base._base._base.second_Dynamic = &ut_M_StructB_dynamic;
    t->_base._base._base.second = second;
    LUMI_inc_ref(third_Refman);
    LUMI_dec_ref(t->_base._base.third_Refman);
    t->_base._base.third_Refman = third_Refman;
    t->_base._base.third_Dynamic = &ut_M_StructC_dynamic;
    t->_base._base.third = third;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
}
/// @ test-parameter-inheritance-5
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_First ut_M_First;
typedef struct ut_M_Second ut_M_Second;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_MyStruct {
    uint32_t x;
};
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
void ut_M_MyStruct_Del(ut_M_MyStruct* self);
void ut_M_First_Del(ut_M_First* self);
void ut_M_Second_Del(ut_M_Second* self);
Return_Code ut_M_Test_set(ut_M_Test* self, Generic_Type* g, Ref_Manager* g_Refman, Generic_Type_Dynamic* g_Dynamic, ut_M_Second* sg, Ref_Manager* sg_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Return_Code ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman, ut_M_Second* ff, Ref_Manager* ff_Refman);
Generic_Type_Dynamic ut_M_MyStruct_dynamic = {(Dynamic_Del)ut_M_MyStruct_Del};
Generic_Type_Dynamic ut_M_First_dynamic = {(Dynamic_Del)ut_M_First_Del};
Generic_Type_Dynamic ut_M_Second_dynamic = {(Dynamic_Del)ut_M_Second_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_MyStruct_Del(ut_M_MyStruct* self) {
    if (self == NULL) return;
}
void ut_M_First_Del(ut_M_First* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
void ut_M_Second_Del(ut_M_Second* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Return_Code ut_M_Test_set(ut_M_Test* self, Generic_Type* g, Ref_Manager* g_Refman, Generic_Type_Dynamic* g_Dynamic, ut_M_Second* sg, Ref_Manager* sg_Refman) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(g_Refman);
    LUMI_inc_ref(sg_Refman);
    LUMI_inc_ref(sg_Refman);
    LUMI_dec_ref(self->_base.item_Refman);
    self->_base.item_Refman = sg_Refman;
    self->_base.item_Dynamic = &ut_M_Second_dynamic;
    self->_base.item = sg;
    CHECK_REF_REFMAN(10, LUMI_block0_cleanup, self->_base.item, self->_base.item_Refman)
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
Return_Code ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman, ut_M_Second* ff, Ref_Manager* ff_Refman) {
    Return_Code LUMI_err = OK;
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
    CHECK_REF_REFMAN(14, LUMI_block0_cleanup, t->_base.item, t->_base.item_Refman)
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(((ut_M_Second*)(t->_base.item))->item_Refman);
    ((ut_M_Second*)(t->_base.item))->item_Refman = f_Refman;
    ((ut_M_Second*)(t->_base.item))->item_Dynamic = &ut_M_MyStruct_dynamic;
    ((ut_M_Second*)(t->_base.item))->item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    LUMI_dec_ref(ff_Refman);
    LUMI_dec_ref(f_Refman);
    return LUMI_err;
}
/// @ test-parameter-inheritance-6
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
    uint32_t x;
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
/// @ test-parameter-inheritance-7
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Top ut_M_Top;
struct ut_M_MyStruct {
    uint32_t x;
};
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
void ut_M_MyStruct_Del(ut_M_MyStruct* self);
void ut_M_Base_Del(ut_M_Base* self);
void ut_M_Mid_Del(ut_M_Mid* self);
void ut_M_Top_Del(ut_M_Top* self);
void ut_M_fun(ut_M_Top* t);
Generic_Type_Dynamic ut_M_MyStruct_dynamic = {(Dynamic_Del)ut_M_MyStruct_Del};
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Top_dynamic = {(Dynamic_Del)ut_M_Top_Del};
void ut_M_MyStruct_Del(ut_M_MyStruct* self) {
    if (self == NULL) return;
}
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
/// @ test-parameter-inheritance-e0
unknown type "Generic"
/// @ test-parameter-inheritance-e1
cannot assign "String" into "MyStruct"
/// @ test-parameter-inheritance-e2
cannot assign "String" into "Generic Type"
/// @ test-parameter-inheritance-e3
cannot assign "String" into "MyStruct"
/// @@ test-error-handling
/// @ test-error-handling-0
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
/// @ test-error-handling-1
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
/// @ test-error-handling-2
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
/// @ test-error-handling-3
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
/// @ test-error-handling-4
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
/// @ test-error-handling-5
void ut_M_fun(char* s, Seq_Length s_Max_length, Seq_Length* s_Length, Ref_Manager* s_Refman, Bool* fail);
void ut_M_fun(char* s, Seq_Length s_Max_length, Seq_Length* s_Length, Ref_Manager* s_Refman, Bool* fail) {
    Return_Code LUMI_err = OK;
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
/// @ test-error-handling-e0
statement has no effect
/// @ test-error-handling-e1
statement has no effect
/// @ test-error-handling-e2
no error raised in expression
/// @ test-error-handling-e3
"if-ok" without "else"
/// @ test-error-handling-e4
error handling with no code
/// @ test-error-handling-e5
error handling with no code
/// @ test-error-handling-e6
using "!" where error is not propagated
/// @@ test-try-catch
/// @ test-try-catch-0
{
        ++LUMI_trace_ignore_count;
        CHECK_REF_REFMAN(2, LUMI_block1_cleanup, ut_M_t, ut_M_t_Refman)
        ut_M_t->num = 0x01;
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
        ut_M_fun4(0x02);
    LUMI_block2_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-try-catch-1
{
        ++LUMI_trace_ignore_count;
        CHECK_REF_REFMAN(2, LUMI_block1_cleanup, ut_M_t, ut_M_t_Refman)
        ut_M_t->num = 0x01;
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
/// @ test-try-catch-2
{
        ++LUMI_trace_ignore_count;
        CHECK_REF_REFMAN(2, LUMI_block1_cleanup, ut_M_t, ut_M_t_Refman)
        ut_M_t->num = 0x01;
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
            ut_M_fun4(0x02);
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
            if (0x03 >= ut_M_arr_Length) RAISE(9, LUMI_block5_cleanup, slice_index)
            ut_M_i = ut_M_arr[0x03];
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
/// @ test-try-catch-3
{
        char sa[0x04] = {0};
        Seq_Length sa_Length[1] = {0};
        ++LUMI_trace_ignore_count;
        /* initializing sa */
        {
            char sb[0x04] = {0};
            Seq_Length sb_Length[1] = {0};
            Ref_Manager* sb_Refman = NULL;
            ++LUMI_trace_ignore_count;
            INIT_VAR_REFMAN(4, LUMI_block2_cleanup, sb)
        LUMI_block2_cleanup:
            (void)0;
            LUMI_var_dec_ref(sb_Refman);
        }
        --LUMI_trace_ignore_count;
        if (LUMI_err != OK) {
            char sc[0x04] = {0};
            Seq_Length sc_Length[1] = {0};
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
        char sd[0x04] = {0};
        Seq_Length sd_Length[1] = {0};
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        /* initializing sd */
        {
            char se[0x04] = {0};
            Seq_Length se_Length[1] = {0};
            Ref_Manager* se_Refman = NULL;
            ++LUMI_trace_ignore_count;
            INIT_VAR_REFMAN(10, LUMI_block5_cleanup, se)
        LUMI_block5_cleanup:
            (void)0;
            LUMI_var_dec_ref(se_Refman);
        }
        --LUMI_trace_ignore_count;
        if (LUMI_err != OK) {
            char sf[0x04] = {0};
            Seq_Length sf_Length[1] = {0};
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
/// @ test-try-catch-4
void ut_M_fun(char* s, Seq_Length s_Max_length, Seq_Length* s_Length, Ref_Manager* s_Refman);
void ut_M_fun(char* s, Seq_Length s_Max_length, Seq_Length* s_Length, Ref_Manager* s_Refman) {
    Return_Code LUMI_err = OK;
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
/// @ test-try-catch-e0
expected new-line after "try", got "("
/// @ test-try-catch-e1
"catch" without a previous "try"
/// @ test-try-catch-e2
expected new-line after "catch", got "("
/// @ test-try-catch-e3
"try" statement with no code
/// @ test-try-catch-e4
"catch" statement with no code
/// @ test-try-catch-e5
"catch" without a previous "try"
/// @ test-try-catch-e6
no error raised in block
/// @ test-try-catch-e7
using "!" where error is not propagated
/// @ test-try-catch-e8
using "!" where error is not propagated
/// @@ test-for-each
/// @ test-for-each-0
typedef struct ut_M_TestIterator ut_M_TestIterator;
struct ut_M_TestIterator {
    uint32_t counter;
};
void ut_M_TestIterator_new(ut_M_TestIterator* self, uint32_t count);
void ut_M_TestIterator_step(ut_M_TestIterator* self, uint32_t* num, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
Return_Code ut_M_fun(uint32_t* i);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
void ut_M_TestIterator_new(ut_M_TestIterator* self, uint32_t count) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_TestIterator_step(ut_M_TestIterator* self, uint32_t* num, Bool* has_data) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
    if (self == NULL) return;
}
Return_Code ut_M_fun(uint32_t* i) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    ut_M_TestIterator* aux_TestIterator_1 = NULL;
    INIT_NEW(6, LUMI_block0_cleanup, aux_TestIterator_0, ut_M_TestIterator, 1);
    ut_M_TestIterator_new(aux_TestIterator_0, 0x06);
    aux_TestIterator_1 = aux_TestIterator_0;
    do {
        char s[0x04] = {0};
        Seq_Length s_Length[1] = {0};
        uint32_t n = 0;
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
/// @ test-for-each-1
typedef struct ut_M_TestIterator ut_M_TestIterator;
struct ut_M_TestIterator {
    char* value;
    Seq_Length value_Max_length;
    Seq_Length* value_Length;
};
void ut_M_TestIterator_step(ut_M_TestIterator* self, char** text, Seq_Length* text_Max_length, Seq_Length** text_Length, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
void ut_M_fun(ut_M_TestIterator* iter);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
void ut_M_TestIterator_step(ut_M_TestIterator* self, char** text, Seq_Length* text_Max_length, Seq_Length** text_Length, Bool* has_data) {
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
    Seq_Length t_Max_length = 0;
    Seq_Length* t_Length = &Lumi_empty_length;
    char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
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
/// @ test-for-each-2
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_TestIterator ut_M_TestIterator;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_TestIterator {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*fun)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self);
Return_Code ut_M_TestIterator_step(ut_M_TestIterator* self, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
void ut_M_Test_fun(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
Return_Code ut_M_fun(ut_M_TestIterator* fiter, ut_M_TestIterator* titer);
Generic_Type_Dynamic ut_M_MyStruct_dynamic = {(Dynamic_Del)ut_M_MyStruct_Del};
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_fun};
void ut_M_MyStruct_Del(ut_M_MyStruct* self) {
    if (self == NULL) return;
}
Return_Code ut_M_TestIterator_step(ut_M_TestIterator* self, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_data) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    CHECK_REFMAN(6, LUMI_block0_cleanup, self->item_Refman)
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
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
Return_Code ut_M_fun(ut_M_TestIterator* fiter, ut_M_TestIterator* titer) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_MyStruct* of = NULL;
    ut_M_Test* ot = NULL;
    ut_M_Test_Dynamic* ot_Dynamic = NULL;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    ut_M_TestIterator* aux_TestIterator_1 = NULL;
    aux_TestIterator_0 = fiter;
    do {
        ut_M_MyStruct* f = NULL;
        Bool aux_Bool_0 = 0;
        LUMI_loop_depth = 3;
        LUMI_err = ut_M_TestIterator_step(aux_TestIterator_0, (void*)&(f), &dynamic_Void, &(aux_Bool_0));
        CHECK(13, LUMI_block1_cleanup)
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
        CHECK(15, LUMI_block2_cleanup)
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
/// @ test-for-each-3
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_TestIterator ut_M_TestIterator;
typedef struct ut_M_TestIterator_Dynamic ut_M_TestIterator_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_TestIterator {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_TestIterator_Dynamic {
    Dynamic_Del _del;
    Return_Code (*step)(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_data);
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self);
Return_Code ut_M_TestIterator_step(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic);
Return_Code ut_M_f_mock(ut_M_TestIterator* iter, ut_M_TestIterator_Dynamic* iter_Dynamic);
Generic_Type_Dynamic ut_M_MyStruct_dynamic = {(Dynamic_Del)ut_M_MyStruct_Del};
ut_M_TestIterator_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del, ut_M_TestIterator_step};
void ut_M_MyStruct_Del(ut_M_MyStruct* self) {
    if (self == NULL) return;
}
Return_Code ut_M_TestIterator_step(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_data) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    CHECK_REFMAN(6, LUMI_block0_cleanup, self->item_Refman)
    *item_Dynamic = self->item_Dynamic;
    *item = self->item;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Return_Code ut_M_f_mock(ut_M_TestIterator* iter, ut_M_TestIterator_Dynamic* iter_Dynamic) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_MyStruct* f = NULL;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    ut_M_TestIterator_Dynamic* aux_TestIterator_0_Dynamic = NULL;
    aux_TestIterator_0_Dynamic = iter_Dynamic;
    aux_TestIterator_0 = iter;
    do {
        ut_M_MyStruct* t = NULL;
        Bool aux_Bool_0 = 0;
        LUMI_loop_depth = 3;
        LUMI_err = aux_TestIterator_0_Dynamic->step(aux_TestIterator_0, aux_TestIterator_0_Dynamic, (void*)&(t), &dynamic_Void, &(aux_Bool_0));
        CHECK(9, LUMI_block1_cleanup)
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
/// @ test-for-each-4
typedef struct ut_M_TestIterator ut_M_TestIterator;
struct ut_M_TestIterator {
    char* value;
    Seq_Length value_Max_length;
    Seq_Length* value_Length;
};
void ut_M_TestIterator_step(ut_M_TestIterator* self, char** text, Seq_Length* text_Max_length, Seq_Length** text_Length, Ref_Manager** text_Refman, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
void ut_M_fun(ut_M_TestIterator* iter);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
void ut_M_TestIterator_step(ut_M_TestIterator* self, char** text, Seq_Length* text_Max_length, Seq_Length** text_Length, Ref_Manager** text_Refman, Bool* has_data) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    ++LUMI_trace_ignore_count;
    CHECK_REF(4, LUMI_block2_cleanup, self->value)
    INIT_NEW_SEQUENCE(4, LUMI_block2_cleanup, aux_String_0, char, 0x0c);
    LUMI_err = String_copy(aux_String_0, 0x0c, aux_String_0_Length, self->value, *self->value_Length);
    CHECK(4, LUMI_block2_cleanup)
    String_Del(*text);
    LUMI_owner_dec_ref(*text_Refman);
    *text_Max_length = 0x0c;
    *text_Length = aux_String_0_Length;
    *text = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
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
        *text_Length = &Lumi_empty_length;
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
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    aux_TestIterator_0 = iter;
    do {
        char* t = NULL;
        Seq_Length t_Max_length = 0;
        Seq_Length* t_Length = &Lumi_empty_length;
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
        t_Length = &Lumi_empty_length;
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
/// @ test-for-each-5
typedef struct ut_M_TestIterator ut_M_TestIterator;
struct ut_M_TestIterator {
    char* value;
    Seq_Length value_Max_length;
    Seq_Length* value_Length;
};
void ut_M_TestIterator_step(ut_M_TestIterator* self, char** text, Seq_Length* text_Max_length, Seq_Length** text_Length, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
void ut_M_fun(ut_M_TestIterator* iter);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
void ut_M_TestIterator_step(ut_M_TestIterator* self, char** text, Seq_Length* text_Max_length, Seq_Length** text_Length, Bool* has_data) {
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
    uint32_t x = 0;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    aux_TestIterator_0 = iter;
    do {
        char* aux_String_0 = NULL;
        Seq_Length aux_String_0_Max_length = 0;
        Seq_Length* aux_String_0_Length = &Lumi_empty_length;
        Bool aux_Bool_0 = 0;
        LUMI_loop_depth = 3;
        ut_M_TestIterator_step(aux_TestIterator_0, &(aux_String_0), &(aux_String_0_Max_length), &(aux_String_0_Length), &(aux_Bool_0));
        if (!(aux_Bool_0)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        x = 0x01;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-for-each-e0
cannot iterate type with no "step" named method - "TestIterator"
/// @ test-for-each-e1
iterator "step" method has parameters in type "TestIterator"
/// @ test-for-each-e2
iterator "step" method has no outputs in type "TestIterator"
/// @ test-for-each-e3
iterator "step" method has only one output in type "TestIterator"
/// @ test-for-each-e4
iterator "step" method has more than two outputs in type "TestIterator"
/// @ test-for-each-e5
iterator "step" method second output is not "Bool" in type "TestIterator"
/// @ test-for-each-e6
iterator "step" method self access is not "user" in type "TestIterator"
/// @ test-for-each-e7
ignoring iterator step function error check
/// @@ test-complex-fields
/// @ test-complex-fields-0
typedef struct ut_M_Astruct ut_M_Astruct;
typedef struct ut_M_Astruct_Dynamic ut_M_Astruct_Dynamic;
typedef struct ut_M_Bstruct ut_M_Bstruct;
typedef struct ut_M_Bstruct_Dynamic ut_M_Bstruct_Dynamic;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Astruct {
    uint32_t x;
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
void ut_M_Astruct_Del(ut_M_Astruct* self, ut_M_Astruct_Dynamic* self_Dynamic);
void ut_M_Bstruct_meth(ut_M_Bstruct* self, ut_M_Bstruct_Dynamic* self_Dynamic);
void ut_M_Bstruct_Del(ut_M_Bstruct* self, ut_M_Bstruct_Dynamic* self_Dynamic);
Return_Code ut_M_Test_test(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
ut_M_Astruct_Dynamic ut_M_Astruct_dynamic = {(Dynamic_Del)ut_M_Astruct_Del, ut_M_Astruct_meth};
ut_M_Bstruct_Dynamic ut_M_Bstruct_dynamic = {{(Dynamic_Del)ut_M_Bstruct_Del, (void (*)(ut_M_Astruct* self, ut_M_Astruct_Dynamic* self_Dynamic))ut_M_Bstruct_meth}};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Astruct_meth(ut_M_Astruct* self, ut_M_Astruct_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Astruct_Del(ut_M_Astruct* self, ut_M_Astruct_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Bstruct_meth(ut_M_Bstruct* self, ut_M_Bstruct_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Bstruct_Del(ut_M_Bstruct* self, ut_M_Bstruct_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Astruct_Del(&(self->_base), &(self_Dynamic->_base));
    LUMI_dec_ref(self->b_Refman);
}
Return_Code ut_M_Test_test(ut_M_Test* self) {
    Return_Code LUMI_err = OK;
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
    self->b._base.x = 0x05;
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
    ut_M_Bstruct_Del(&(self->sb), &ut_M_Bstruct_dynamic);
    LUMI_var_dec_ref(self->sb_Refman);
    ut_M_Bstruct_Del(&(self->b), &ut_M_Bstruct_dynamic);
}
/// @ test-complex-fields-1
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Base {
    uint32_t x;
};
struct ut_M_Test {
    char s[0x0a];
    Seq_Length s_Length[1];
    uint32_t ai[0x0b];
    ut_M_Base ab[0x0c];
    char as[0x07 * 0x08];
    Seq_Length as_Seq_length[0x07];
    uint32_t aai[0x04 * 0x05 * 0x06];
    ut_M_Base aab[0x04 * 0x05 * 0x06];
    char aas[0x04 * 0x05 * 0x06];
    Seq_Length aas_Seq_length[0x04 * 0x05];
};
void ut_M_Base_Del(ut_M_Base* self);
Return_Code ut_M_Test_test(ut_M_Test* self, Char* c, uint32_t* i, ut_M_Base** b);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
}
Return_Code ut_M_Test_test(ut_M_Test* self, Char* c, uint32_t* i, ut_M_Base** b) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    uint32_t* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Seq_Length aux_Array_0_Value_length = 0;
    uint32_t* aux_Array_1 = NULL;
    Seq_Length aux_Array_1_Length = 0;
    ut_M_Base* aux_Array_2 = NULL;
    Seq_Length aux_Array_2_Length = 0;
    Seq_Length aux_Array_2_Value_length = 0;
    ut_M_Base* aux_Array_3 = NULL;
    Seq_Length aux_Array_3_Length = 0;
    char* aux_Array_4 = NULL;
    Seq_Length aux_Array_4_Length = 0;
    Seq_Length aux_Array_4_Value_length = 0;
    Seq_Length* aux_Array_4_Seq_length = NULL;
    char* aux_String_1 = NULL;
    Seq_Length aux_String_1_Max_length = 0;
    Seq_Length* aux_String_1_Length = &Lumi_empty_length;
    if (0x03 >= *(self->s_Length)) RAISE(12, LUMI_block0_cleanup, slice_index)
    *c = self->s[0x03];
    *i = self->ai[0x04];
    *b = self->ab + 0x05;
    aux_String_0 = self->as + 0x04 * 0x08;
    aux_String_0_Max_length = 0x08;
    aux_String_0_Length = self->as_Seq_length + 0x04;
    if (0x05 >= *(aux_String_0_Length)) RAISE(15, LUMI_block0_cleanup, slice_index)
    *c = (aux_String_0)[0x05];
    aux_Array_0 = self->aai + 0x01 * 0x05 * 0x06;
    aux_Array_0_Length = 0x05;
    aux_Array_0_Value_length = 0x06;
    aux_Array_1 = (aux_Array_0) + 0x02 * 0x06;
    aux_Array_1_Length = 0x06;
    *i = (aux_Array_1)[0x03];
    aux_Array_2 = self->aab + 0x01 * 0x05 * 0x06;
    aux_Array_2_Length = 0x05;
    aux_Array_2_Value_length = 0x06;
    aux_Array_3 = (aux_Array_2) + 0x02 * 0x06;
    aux_Array_3_Length = 0x06;
    *b = (aux_Array_3) + 0x03;
    aux_Array_4 = self->aas + 0x01 * 0x05 * 0x06;
    aux_Array_4_Length = 0x05;
    aux_Array_4_Value_length = 0x06;
    aux_Array_4_Seq_length = self->aas_Seq_length + 0x01 * 0x05;
    aux_String_1 = (aux_Array_4) + 0x02 * 0x06;
    aux_String_1_Max_length = 0x06;
    aux_String_1_Length = aux_Array_4_Seq_length + 0x02;
    if (0x03 >= *(aux_String_1_Length)) RAISE(18, LUMI_block0_cleanup, slice_index)
    *c = (aux_String_1)[0x03];
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ARRAY_DEL(ut_M_Base, self->aab, 0x04 * 0x05 * 0x06)
    ARRAY_DEL(ut_M_Base, self->ab, 0x0c)
}
/// @ test-complex-fields-e0
sequence length is not constant
/// @ test-complex-fields-e1
sequence length is not constant
/// @ test-complex-fields-e2
recursive declaration of type "Test", variable of type "Test"
/// @ test-complex-fields-e3
recursive declaration of type "Test", variable of type "Base", variable of type "Test"
/// @ test-complex-fields-e4
recursive declaration of type "Abase", extended by type "Aerror", variable of type "Bbase", extended by type "Berror", variable of type "Abase"
/// @ test-complex-fields-e5
assigning into non assignable expression
/// @ test-complex-fields-e6
cannot use "?" on non conditional or weak reference of type "Base"
/// @@ test-enum
/// @ test-enum-0
enum {
    ut_M_MyEnum_VALUE = 0,
    ut_M_MyEnum_ANOTHER_VALUE,
    ut_M_MyEnum_LAST_VALUE,
    ut_M_MyEnum_length
};
void ut_M_dummy(void);
void ut_M_dummy(void) {
    unsigned LUMI_loop_depth = 1;
    uint32_t x = 0;
    x = ut_M_MyEnum_VALUE;
    x = ut_M_MyEnum_ANOTHER_VALUE;
    x = ut_M_MyEnum_length;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-enum-1
enum {
    ut_M_MyEnum_VALUE = 0,
    ut_M_MyEnum_ANOTHER_VALUE,
    ut_M_MyEnum_LAST_VALUE,
    ut_M_MyEnum_length
};
uint32_t ut_M_arr[ut_M_MyEnum_length] = {0};
/// @ test-enum-e0
Enum "MyEnum" has no value "ERROR"
/// @ test-enum-e1
unknown Enum "Error"
/// @ test-enum-e2
unknown type "MyEnum"
/// @ test-enum-e3
illegal Enum name "My-Enum"
/// @ test-enum-e4
illegal constant name "Error"
/// @ test-enum-e5
illegal constant name "ERRoR"
/// @ test-enum-e6
expected space after "enum", got "new-line"
/// @ test-enum-e7
expected new-line after "VALUE", got "("
/// @ test-enum-e8
Enum with no values
/// @ test-enum-e9
indentation too long, expected 4 got 8
/// @ test-enum-e10
redefinition of Enum "Error"
/// @ test-enum-e11
Enum name overrides type "Error"
/// @ test-enum-e12
type name overrides Enum "Error"
/// @@ test-constant
/// @ test-constant-0
enum { ut_M_NUMBER = 0x0c };
/// @ test-constant-1
enum { ut_M_SIZE = 0x0c };
void ut_M_fun(uint32_t* a, Seq_Length a_Length);
uint32_t ut_M_arr[ut_M_SIZE + 0x03] = {0};
void ut_M_fun(uint32_t* a, Seq_Length a_Length) {
    unsigned LUMI_loop_depth = 1;
    ut_M_fun(ut_M_arr, 0x0f);
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-constant-2
enum { ut_M_SMALL = 0x07 };
enum { ut_M_LARGE = 0x0f };
/// @ test-constant-3
enum {
    ut_M_MyEnum_VALUE = 0,
    ut_M_MyEnum_length
};
enum { ut_M_NUMBER = 0 };
/// @ test-constant-4
enum { ut_M_NUMBER = 0x02 };
enum { ut_M_D_CHAR = 0x64 };
/// @ test-constant-5
enum {
    ut_M_Enum_VAL = 0,
    ut_M_Enum_length
};
enum { ut_M_LENGTH = 0x06 };
uint32_t ut_M_arr[(ut_M_Enum_VAL + ut_M_Enum_length) + ut_M_LENGTH] = {0};
/// @ test-constant-e0
expected space after "const", got "new-line"
/// @ test-constant-e1
Only "Int" typed constant supported, got "Bool"
/// @ test-constant-e2
expected space after "Int", got "new-line"
/// @ test-constant-e3
illegal constant name "Error"
/// @ test-constant-e4
expected space after "ERROR", got "new-line"
/// @ test-constant-e5
got "Bool" expression, expected "Int"
/// @ test-constant-e6
value is not constant
/// @ test-constant-e7
recursive dependency in constant "ERROR"
/// @ test-constant-e8
recursive dependency in constant "A-ERROR"
/// @ test-constant-e9
assigning into non assignable expression
/// @ test-constant-e10
non assignable call output
/// @@ test-module
/// @ test-module-0
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
enum { ut_M_SIZE = 0x0c };
enum { second_M_SIZE = 0x0c };
struct ut_M_Test {
    uint32_t x;
};
struct second_M_Test {
    ut_M_Test _base;
};
void ut_M_Test_meth(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
void second_M_Test_meth(second_M_Test* self);
void second_M_Test_Del(second_M_Test* self);
Return_Code ut_M_fun(void);
Return_Code second_M_fun(void);
Return_Code second_M_dummy(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Generic_Type_Dynamic second_M_Test_dynamic = {(Dynamic_Del)second_M_Test_Del};
ut_M_Test ut_M_t_Var = {0};
ut_M_Test* ut_M_t = NULL;
second_M_Test second_M_t_Var = {{0}};
second_M_Test* second_M_t = NULL;
Line_Count LUMI_file0_line_count[17] = {
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
Return_Code ut_M_fun(void) {
    Return_Code LUMI_err = OK;
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
Return_Code second_M_fun(void) {
    Return_Code LUMI_err = OK;
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
Return_Code second_M_dummy(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void new_Mock(Bool* allocate_success) { }
Return_Code delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Bool LUMI_success = true;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "mock.5.lm"
    ut_M_t = &ut_M_t_Var;
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "path\\second.5.lm"
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
/// @ test-module-1
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint32_t x;
};
void ut_M_Test_meth(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(void);
void ut_M_fun_Mock(void);
Bool ut_M_fun_Mock_active = true;
void ut_M_Test_meth_Mock(ut_M_Test* self);
Bool ut_M_Test_meth_Mock_active = true;
Return_Code second_M_dummy(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Line_Count LUMI_file0_line_count[8] = {
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
Return_Code second_M_dummy(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void new_Mock(Bool* allocate_success) { }
Return_Code delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Bool LUMI_success = true;
    LUMI_success &= LUMI_run_test("dummy", second_M_dummy);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
LUMI_block0_cleanup:
    return LUMI_err;
}
TEST_MAIN_FUNC
/// @ test-module-2
void ut_M_fun(void);
Return_Code second_M_use(void);
Line_Count LUMI_file0_line_count[7] = {
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
Return_Code second_M_use(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Native n = 0;
    x = 0x02;
    external();
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void new_Mock(Bool* allocate_success) { }
Return_Code delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Bool LUMI_success = true;
    LUMI_success &= LUMI_run_test("use", second_M_use);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
LUMI_block0_cleanup:
    return LUMI_err;
}
TEST_MAIN_FUNC
/// @ test-module-e0
unknown symbol "error" in module "ut"
/// @ test-module-e1
variable name overrides module "ut"
/// @ test-module-e2
function name overrides module "ut"
/// @ test-module-e3
unknown module "error"
/// @ test-module-e4
unknown type "Error" in module "ut"
/// @ test-module-e5
expected space after "module", got "("
/// @ test-module-e6
illegal module name "Error"
/// @ test-module-e7
module name overrides variable "true"
/// @ test-module-e8
illegal module name "; some global function"
/// @ test-module-e9
no "module" in file start
/// @ test-module-e10
expected module, got empty expression
/// @ test-module-e11
expected module, got "Int"
/// @ test-module-e12
unknown Enum "Error" in module "ut"
/// @@ test-memory-owner
/// @ test-memory-owner-0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    Seq_Length s_Max_length;
    Seq_Length* s_Length;
    char* str;
    Seq_Length str_Max_length;
    Seq_Length* str_Length;
};
Return_Code ut_M_Test_new(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_use(char* s, Seq_Length s_Max_length, Seq_Length* s_Length);
void ut_M_take(char* s, Seq_Length s_Max_length, Seq_Length* s_Length);
void ut_M_give(char** s, Seq_Length* s_Max_length, Seq_Length** s_Length);
Return_Code ut_M_fun(char* s, Seq_Length s_Max_length, Seq_Length* s_Length, ut_M_Test* tu, ut_M_Test* to);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Return_Code ut_M_Test_new(ut_M_Test* self) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    INIT_NEW_SEQUENCE(5, LUMI_block0_cleanup, aux_String_0, char, 0x0c);
    String_Del(self->str);
    free(self->str);
    self->str_Max_length = 0x0c;
    self->str_Length = aux_String_0_Length;
    self->str = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
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
void ut_M_use(char* s, Seq_Length s_Max_length, Seq_Length* s_Length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_take(char* s, Seq_Length s_Max_length, Seq_Length* s_Length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    String_Del(s);
    free(s);
}
void ut_M_give(char** s, Seq_Length* s_Max_length, Seq_Length** s_Length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
Return_Code ut_M_fun(char* s, Seq_Length s_Max_length, Seq_Length* s_Length, ut_M_Test* tu, ut_M_Test* to) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* su = NULL;
    Seq_Length su_Max_length = 0;
    Seq_Length* su_Length = &Lumi_empty_length;
    uint32_t arr[0x0c] = {0};
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    char* aux_String_1 = NULL;
    Seq_Length aux_String_1_Max_length = 0;
    Seq_Length* aux_String_1_Length = &Lumi_empty_length;
    String_Del(s);
    free(s);
    s_Max_length = 0;
    s_Length = &Lumi_empty_length;
    s = NULL;
    INIT_NEW_SEQUENCE(12, LUMI_block0_cleanup, aux_String_0, char, 0x0c);
    String_Del(s);
    free(s);
    s_Max_length = 0x0c;
    s_Length = aux_String_0_Length;
    s = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
    CHECK_REF(13, LUMI_block0_cleanup, s)
    String_clear(s, s_Max_length, s_Length);
    INIT_NEW_SEQUENCE(14, LUMI_block0_cleanup, aux_String_1, char, 0x0c);
    String_Del(to->s);
    free(to->s);
    to->s_Max_length = 0x0c;
    to->s_Length = aux_String_1_Length;
    to->s = aux_String_1;
    aux_String_1 = NULL;
    aux_String_1_Length = &Lumi_empty_length;
    su_Max_length = tu->s_Max_length;
    su_Length = tu->s_Length;
    su = tu->s;
    ut_M_use(tu->s, tu->s_Max_length, tu->s_Length);
    ut_M_take(to->s, to->s_Max_length, to->s_Length);
    to->s = NULL;
    to->s_Length = &Lumi_empty_length;
    /* initializing arr */
    arr[0x04] = arr[0x08];
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
/// @ test-memory-owner-1
typedef struct ut_M_TestStruct ut_M_TestStruct;
typedef struct ut_M_TestClass ut_M_TestClass;
typedef struct ut_M_TestClass_Dynamic ut_M_TestClass_Dynamic;
struct ut_M_TestStruct {
    ut_M_TestStruct* next;
};
struct ut_M_TestClass {
    ut_M_TestClass* next;
    Ref_Manager* next_Refman;
    ut_M_TestClass_Dynamic* next_Dynamic;
};
struct ut_M_TestClass_Dynamic {
    Dynamic_Del _del;
    void (*fun)(ut_M_TestClass* self, ut_M_TestClass_Dynamic* self_Dynamic);
};
void ut_M_TestStruct_Del(ut_M_TestStruct* self);
void ut_M_TestClass_fun(ut_M_TestClass* self, ut_M_TestClass_Dynamic* self_Dynamic);
void ut_M_TestClass_Del(ut_M_TestClass* self, ut_M_TestClass_Dynamic* self_Dynamic);
Return_Code ut_M_fun(ut_M_TestStruct* t, ut_M_TestClass* c, Ref_Manager* c_Refman, ut_M_TestClass_Dynamic* c_Dynamic, ut_M_TestStruct* tx, Ref_Manager* tx_Refman, ut_M_TestClass* cx, ut_M_TestClass_Dynamic* cx_Dynamic);
Generic_Type_Dynamic ut_M_TestStruct_dynamic = {(Dynamic_Del)ut_M_TestStruct_Del};
ut_M_TestClass_Dynamic ut_M_TestClass_dynamic = {(Dynamic_Del)ut_M_TestClass_Del, ut_M_TestClass_fun};
void ut_M_TestStruct_Del(ut_M_TestStruct* self) {
    if (self == NULL) return;
    SELF_REF_DEL(ut_M_TestStruct, next);
    free(self->next);
}
void ut_M_TestClass_fun(ut_M_TestClass* self, ut_M_TestClass_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_TestClass_Del(ut_M_TestClass* self, ut_M_TestClass_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    SELF_REF_DEL_STR_DYN(ut_M_TestClass, _, next, next_Dynamic);
    LUMI_owner_dec_ref(self->next_Refman);
}
Return_Code ut_M_fun(ut_M_TestStruct* t, ut_M_TestClass* c, Ref_Manager* c_Refman, ut_M_TestClass_Dynamic* c_Dynamic, ut_M_TestStruct* tx, Ref_Manager* tx_Refman, ut_M_TestClass* cx, ut_M_TestClass_Dynamic* cx_Dynamic) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_TestStruct* aux_TestStruct_0 = NULL;
    ut_M_TestStruct* aux_TestStruct_1 = NULL;
    ut_M_TestStruct* aux_TestStruct_2 = NULL;
    ut_M_TestStruct* aux_TestStruct_3 = NULL;
    ut_M_TestClass* aux_TestClass_0 = NULL;
    Ref_Manager* aux_TestClass_0_Refman = NULL;
    ut_M_TestClass_Dynamic* aux_TestClass_0_Dynamic = NULL;
    ut_M_TestStruct* aux_TestStruct_4 = NULL;
    ut_M_TestClass* aux_TestClass_1 = NULL;
    Ref_Manager* aux_TestClass_1_Refman = NULL;
    ut_M_TestClass_Dynamic* aux_TestClass_1_Dynamic = NULL;
    CHECK_REF(11, LUMI_block0_cleanup, t->next)
    aux_TestStruct_0 = t->next;
    t->next = NULL;
    ut_M_TestStruct_Del(t);
    free(t);
    t = aux_TestStruct_0;
    aux_TestStruct_0 = NULL;
    CHECK_REF(12, LUMI_block0_cleanup, t->next)
    CHECK_REF(12, LUMI_block0_cleanup, t->next->next)
    CHECK_REF(12, LUMI_block0_cleanup, t->next->next->next)
    aux_TestStruct_1 = t->next->next->next;
    t->next->next->next = NULL;
    ut_M_TestStruct_Del(t);
    free(t);
    t = aux_TestStruct_1;
    aux_TestStruct_1 = NULL;
    CHECK_REF(13, LUMI_block0_cleanup, t->next)
    CHECK_REF(13, LUMI_block0_cleanup, t->next->next)
    aux_TestStruct_2 = t->next->next->next;
    t->next->next->next = NULL;
    ut_M_TestStruct_Del(t->next);
    free(t->next);
    t->next = aux_TestStruct_2;
    aux_TestStruct_2 = NULL;
    CHECK_REF(14, LUMI_block0_cleanup, t->next)
    CHECK_REF(14, LUMI_block0_cleanup, t->next->next)
    CHECK_REF(14, LUMI_block0_cleanup, t->next)
    aux_TestStruct_3 = t->next->next->next;
    t->next->next->next = NULL;
    ut_M_TestStruct_Del(t->next->next);
    free(t->next->next);
    t->next->next = aux_TestStruct_3;
    aux_TestStruct_3 = NULL;
    CHECK_REF(15, LUMI_block0_cleanup, c->next)
    aux_TestClass_0_Refman = c->next_Refman;
    aux_TestClass_0_Dynamic = c->next_Dynamic;
    aux_TestClass_0 = c->next;
    c->next = NULL;
    c->next_Refman = NULL;
    c->next_Dynamic = NULL;
    if (c_Dynamic != NULL) c_Dynamic->_del(c, c_Dynamic);
    LUMI_owner_dec_ref(c_Refman);
    c_Refman = aux_TestClass_0_Refman;
    c_Dynamic = aux_TestClass_0_Dynamic;
    c = aux_TestClass_0;
    aux_TestClass_0 = NULL;
    aux_TestClass_0_Refman = NULL;
    aux_TestClass_0_Dynamic = NULL;
    CHECK_REF(16, LUMI_block0_cleanup, tx->next)
    aux_TestStruct_4 = tx->next;
    tx->next = NULL;
    ut_M_TestStruct_Del(tx);
    LUMI_owner_dec_ref(tx_Refman);
    tx = aux_TestStruct_4;
    aux_TestStruct_4 = NULL;
    INIT_NEW_REFMAN(16, LUMI_block0_cleanup, tx)
    CHECK_REF(17, LUMI_block0_cleanup, cx->next)
    aux_TestClass_1_Refman = cx->next_Refman;
    aux_TestClass_1_Dynamic = cx->next_Dynamic;
    aux_TestClass_1 = cx->next;
    cx->next = NULL;
    cx->next_Refman = NULL;
    cx->next_Dynamic = NULL;
    if (cx_Dynamic != NULL) cx_Dynamic->_del(cx, cx_Dynamic);
    free(cx);
    LUMI_var_dec_ref(aux_TestClass_1_Refman);
    cx_Dynamic = aux_TestClass_1_Dynamic;
    cx = aux_TestClass_1;
    aux_TestClass_1 = NULL;
    aux_TestClass_1_Refman = NULL;
    aux_TestClass_1_Dynamic = NULL;
LUMI_block0_cleanup:
    (void)0;
    if (aux_TestClass_1_Dynamic != NULL) aux_TestClass_1_Dynamic->_del(aux_TestClass_1, aux_TestClass_1_Dynamic);
    LUMI_owner_dec_ref(aux_TestClass_1_Refman);
    ut_M_TestStruct_Del(aux_TestStruct_4);
    free(aux_TestStruct_4);
    if (aux_TestClass_0_Dynamic != NULL) aux_TestClass_0_Dynamic->_del(aux_TestClass_0, aux_TestClass_0_Dynamic);
    LUMI_owner_dec_ref(aux_TestClass_0_Refman);
    ut_M_TestStruct_Del(aux_TestStruct_3);
    free(aux_TestStruct_3);
    ut_M_TestStruct_Del(aux_TestStruct_2);
    free(aux_TestStruct_2);
    ut_M_TestStruct_Del(aux_TestStruct_1);
    free(aux_TestStruct_1);
    ut_M_TestStruct_Del(aux_TestStruct_0);
    free(aux_TestStruct_0);
    if (cx_Dynamic != NULL) cx_Dynamic->_del(cx, cx_Dynamic);
    free(cx);
    ut_M_TestStruct_Del(tx);
    LUMI_owner_dec_ref(tx_Refman);
    if (c_Dynamic != NULL) c_Dynamic->_del(c, c_Dynamic);
    LUMI_owner_dec_ref(c_Refman);
    ut_M_TestStruct_Del(t);
    free(t);
    return LUMI_err;
}
/// @ test-memory-owner-e0
cannot modify owner field "s" in non-owner reference "t.s"
/// @ test-memory-owner-e1
cannot modify owner field "a" in non-owner reference "b.a"
/// @ test-memory-owner-e2
cannot modify owner field "a" in non-owner reference "b.a"
/// @ test-memory-owner-e3
cannot modify owner field "s" in non-owner reference "b.a.s"
/// @ test-memory-owner-e4
cannot modify owner field "s" in non-owner reference "t.s"
/// @ test-memory-owner-e5
cannot modify owner field "s" in non-owner reference "{anonymous}.s"
/// @ test-memory-owner-e6
cannot move non-conditional owner field "t.s"
/// @ test-memory-owner-e7
cannot move non-conditional owner field "t.s"
/// @ test-memory-owner-e8
cannot move non-conditional owner field "t.s"
/// @ test-memory-owner-e9
using invalid reference "s"
/// @ test-memory-owner-e12
using modified reference "t"
/// @ test-memory-owner-e13
using modified reference "t.t"
/// @ test-memory-owner-e14
cannot modify owner field "s" in non-owner reference "tu.s"
/// @ test-memory-owner-e15
using invalid reference "s"
/// @ test-memory-owner-e16
using invalid reference "tbad"
/// @ test-memory-owner-e17
using invalid reference "s"
/// @ test-memory-owner-e18
using modified reference "s"
/// @ test-memory-owner-e19
using modified reference "s"
/// @ test-memory-owner-e20
using modified reference "s"
/// @ test-memory-owner-e21
using modified reference "t"
/// @ test-memory-owner-e22
using modified reference "t"
/// @ test-memory-owner-e23
using invalid reference "s"
/// @ test-memory-owner-e24
using invalid reference "s"
/// @ test-memory-owner-e25
cannot modify owner field "s" in non-owner reference "{anonymous}.s"
/// @@ test-memory-user
/// @ test-memory-user-0
void ut_M_deleting(char** s, Seq_Length* s_Max_length, Seq_Length** s_Length);
void ut_M_fun(char* s, Seq_Length s_Max_length, Seq_Length* s_Length, char** so, Seq_Length* so_Max_length, Seq_Length** so_Length);
void ut_M_deleting(char** s, Seq_Length* s_Max_length, Seq_Length** s_Length) {
    unsigned LUMI_loop_depth = 1;
    String_Del(*s);
    free(*s);
    *s_Max_length = 0;
    *s_Length = &Lumi_empty_length;
    *s = NULL;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun(char* s, Seq_Length s_Max_length, Seq_Length* s_Length, char** so, Seq_Length* so_Max_length, Seq_Length** so_Length) {
    unsigned LUMI_loop_depth = 1;
    String_clear(s, s_Max_length, s_Length);
    ut_M_deleting(&(*so), &(*so_Max_length), &(*so_Length));
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-memory-user-1
void ut_M_deleting(char** s, Seq_Length* s_Max_length, Seq_Length** s_Length, Ref_Manager** s_Refman);
Return_Code ut_M_fun(void);
void ut_M_deleting(char** s, Seq_Length* s_Max_length, Seq_Length** s_Length, Ref_Manager** s_Refman) {
    unsigned LUMI_loop_depth = 1;
    String_Del(*s);
    LUMI_owner_dec_ref(*s_Refman);
    *s_Refman = NULL;
    *s_Max_length = 0;
    *s_Length = &Lumi_empty_length;
    *s = NULL;
LUMI_block0_cleanup:
    (void)0;
}
Return_Code ut_M_fun(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* so = NULL;
    Seq_Length so_Max_length = 0;
    Seq_Length* so_Length = &Lumi_empty_length;
    Ref_Manager* so_Refman = NULL;
    char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    INIT_NEW_SEQUENCE(4, LUMI_block0_cleanup, aux_String_0, char, 0x0c);
    so_Max_length = 0x0c;
    so_Length = aux_String_0_Length;
    so = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
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
/// @ test-memory-user-2
void ut_M_deleting(char** s, Seq_Length* s_Max_length, Seq_Length** s_Length, Ref_Manager** s_Refman);
Return_Code ut_M_fun(void);
void ut_M_deleting(char** s, Seq_Length* s_Max_length, Seq_Length** s_Length, Ref_Manager** s_Refman) {
    unsigned LUMI_loop_depth = 1;
    String_Del(*s);
    LUMI_owner_dec_ref(*s_Refman);
    *s_Refman = NULL;
    *s_Max_length = 0;
    *s_Length = &Lumi_empty_length;
    *s = NULL;
LUMI_block0_cleanup:
    (void)0;
}
Return_Code ut_M_fun(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* so = NULL;
    Seq_Length so_Max_length = 0;
    Seq_Length* so_Length = &Lumi_empty_length;
    Ref_Manager* so_Refman = NULL;
    char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    Ref_Manager* s_Refman = NULL;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    INIT_NEW_SEQUENCE(4, LUMI_block0_cleanup, aux_String_0, char, 0x0c);
    so_Max_length = 0x0c;
    so_Length = aux_String_0_Length;
    so = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
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
/// @ test-memory-user-3
char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    String_Del(*so);
    LUMI_owner_dec_ref(*so_Refman);
    *so_Refman = NULL;
    *so_Max_length = 0;
    *so_Length = &Lumi_empty_length;
    *so = NULL;
    s_Max_length = *so_Max_length;
    s_Length = *so_Length;
    s = *so;
    CHECK_REF(4, LUMI_block0_cleanup, s)
    String_clear(s, s_Max_length, s_Length);
/// @ test-memory-user-4
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    Seq_Length s_Max_length;
    Seq_Length* s_Length;
    Ref_Manager* s_Refman;
};
Return_Code ut_M_Test_get(ut_M_Test* self, char** s, Seq_Length* s_Max_length, Seq_Length** s_Length);
void ut_M_Test_Del(ut_M_Test* self);
Return_Code ut_M_fun(ut_M_Test* t);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->s_Refman);
}
Return_Code ut_M_Test_get(ut_M_Test* self, char** s, Seq_Length* s_Max_length, Seq_Length** s_Length) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    CHECK_REFMAN(5, LUMI_block0_cleanup, self->s_Refman)
    *s_Max_length = self->s_Max_length;
    *s_Length = self->s_Length;
    *s = self->s;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
Return_Code ut_M_fun(ut_M_Test* t) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    char* sowner = NULL;
    Seq_Length sowner_Max_length = 0;
    Seq_Length* sowner_Length = &Lumi_empty_length;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    sowner_Max_length = 0;
    sowner_Length = &Lumi_empty_length;
    sowner = NULL;
    LUMI_err = ut_M_Test_get(t, &(s), &(s_Max_length), &(s_Length));
    CHECK(9, LUMI_block0_cleanup)
    CHECK_REF(10, LUMI_block0_cleanup, s)
    String_clear(s, s_Max_length, s_Length);
    LUMI_err = ut_M_Test_get(t, &(aux_String_0), &(aux_String_0_Max_length), &(aux_String_0_Length));
    CHECK(11, LUMI_block0_cleanup)
    s_Max_length = aux_String_0_Max_length;
    s_Length = aux_String_0_Length;
    s = aux_String_0;
    CHECK_REF(12, LUMI_block0_cleanup, s)
    String_clear(s, s_Max_length, s_Length);
LUMI_block0_cleanup:
    (void)0;
    String_Del(sowner);
    free(sowner);
    return LUMI_err;
}
/// @ test-memory-user-5
char* s = NULL;
    Seq_Length s_Max_length = 0;
    Seq_Length* s_Length = &Lumi_empty_length;
    char* aux_Array_0 = NULL;
    Seq_Length aux_Array_0_Length = 0;
    Seq_Length aux_Array_0_Value_length = 0;
    Seq_Length* aux_Array_0_Seq_length = NULL;
    uint32_t aux_Int_0 = 0;
    s_Max_length = ut_M_ostr_Max_length;
    s_Length = ut_M_ostr_Length;
    s = ut_M_ostr;
    String_Del(ut_M_ostr);
    free(ut_M_ostr);
    ut_M_ostr_Max_length = 0;
    ut_M_ostr_Length = &Lumi_empty_length;
    ut_M_ostr = NULL;
    CHECK_REF_REFMAN(3, LUMI_block0_cleanup, ut_M_sarr, ut_M_sarr_Refman)
    aux_Array_0_Length = ut_M_sarr_Length;
    aux_Array_0_Value_length = ut_M_sarr_Value_length;
    aux_Array_0_Seq_length = ut_M_sarr_Seq_length;
    aux_Array_0 = ut_M_sarr;
    do {
        uint32_t aux_Int_1 = 0;
        char* aux_String_0 = NULL;
        Seq_Length aux_String_0_Max_length = 0;
        Seq_Length* aux_String_0_Length = &Lumi_empty_length;
        LUMI_loop_depth = 3;
        Array_length(aux_Array_0, aux_Array_0_Length, &(aux_Int_1));
        if (!(aux_Int_0 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        aux_String_0 = aux_Array_0 + aux_Int_0 * aux_Array_0_Value_length;
        aux_String_0_Max_length = aux_Array_0_Value_length;
        aux_String_0_Length = aux_Array_0_Seq_length + aux_Int_0;
        s_Max_length = aux_String_0_Max_length;
        s_Length = aux_String_0_Length;
        s = aux_String_0;
        aux_Int_0 += 0x01;
        CHECK_REF(4, LUMI_block1_cleanup, s)
        String_clear(s, s_Max_length, s_Length);
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-memory-user-6
void ut_M_get(char** s, Seq_Length* s_Max_length, Seq_Length** s_Length);
Return_Code ut_M_fun(void);
void ut_M_get(char** s, Seq_Length* s_Max_length, Seq_Length** s_Length) {
    unsigned LUMI_loop_depth = 1;
    *s_Max_length = 0;
    *s_Length = &Lumi_empty_length;
    *s = NULL;
LUMI_block0_cleanup:
    (void)0;
}
Return_Code ut_M_fun(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    do {
        char* s = NULL;
        Seq_Length s_Max_length = 0;
        Seq_Length* s_Length = &Lumi_empty_length;
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
/// @ test-memory-user-e0
using potentially illegal user reference "s"
/// @ test-memory-user-e1
using potentially illegal user reference "s"
/// @ test-memory-user-e2
using potentially illegal user reference "s"
/// @ test-memory-user-e3
using potentially illegal user reference "s"
/// @ test-memory-user-e4
using potentially illegal user reference "s"
/// @ test-memory-user-e5
using potentially illegal user reference "s"
/// @ test-memory-user-e6
using potentially illegal user reference "s"
/// @ test-memory-user-e7
using potentially illegal user reference "s"
/// @ test-memory-user-e8
using potentially illegal user reference "s"
/// @ test-memory-user-e9
using potentially illegal user reference "s"
/// @ test-memory-user-e10
using potentially illegal user reference "s"
/// @ test-memory-user-e11
using potentially illegal user reference "s"
/// @ test-memory-user-e12
using potentially illegal user reference "s"
/// @ test-memory-user-e13
using potentially illegal user reference "a"
/// @ test-memory-user-e14
using potentially illegal user reference "s"
/// @ test-memory-user-e15
using potentially illegal user reference "s"
/// @ test-memory-user-e16
using potentially illegal user reference "tt"
/// @ test-memory-user-e17
using potentially illegal user reference "f"
/// @ test-memory-user-e18
using potentially illegal user reference "t"
/// @ test-memory-user-e19
using potentially illegal user reference "b"
/// @ test-memory-user-e20
using potentially illegal user reference "s"
/// @ test-memory-user-e21
using potentially illegal user reference "s"
/// @ test-memory-user-e22
using potentially illegal user reference "s"
/// @ test-memory-user-e23
using potentially illegal user reference "s"
/// @ test-memory-user-e24
using potentially illegal user reference "s"
/// @ test-memory-user-e29
using potentially illegal user reference "s"
/// @ test-memory-user-e30
using potentially illegal user reference "s"
/// @ test-memory-user-e31
using potentially illegal user reference "s"
/// @ test-memory-user-e32
using potentially illegal user reference "s"
/// @ test-memory-user-e33
using potentially illegal user reference "f"
/// @ test-memory-user-e34
using potentially illegal user reference "f"
/// @ test-memory-user-e35
using potentially illegal user reference "su"
/// @ test-memory-user-e36
using potentially illegal user reference "str"
/// @ test-memory-user-e37
using potentially illegal user reference "str"
/// @ test-memory-user-e38
using potentially illegal user reference "str"
/// @ test-memory-user-e39
using potentially illegal user reference "str"
/// @ test-memory-user-e40
using potentially illegal user reference "str"
/// @ test-memory-user-e41
using potentially illegal user reference "str"
/// @ test-memory-user-e42
using potentially illegal user reference "str"
/// @ test-memory-user-e43
using potentially illegal user reference "str"
/// @ test-memory-user-e44
using potentially illegal user reference "str"
/// @ test-memory-user-e45
using potentially illegal user reference "str"
/// @ test-memory-user-e46
using potentially illegal user reference "{anonymous}"
/// @@ test-memory-temp
/// @ test-memory-temp-0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    Seq_Length s_Max_length;
    Seq_Length* s_Length;
};
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(ut_M_Test* t);
void ut_M_use(ut_M_Test* t);
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
    t->s_Length = &Lumi_empty_length;
    t->s = NULL;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_use(ut_M_Test* t) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test* tt = NULL;
    ut_M_Test* tc = NULL;
    ut_M_fun(t);
    ut_M_fun(t);
    tt = t;
    ut_M_fun(tt);
    ut_M_fun(tt);
    tc = NULL;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t);
    free(t);
}
/// @ test-memory-temp-1
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    Seq_Length s_Max_length;
    Seq_Length* s_Length;
};
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(ut_M_Test* to);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    String_Del(self->s);
    free(self->s);
}
void ut_M_fun(ut_M_Test* to) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test* t = NULL;
    t = to;
    String_Del(t->s);
    free(t->s);
    t->s_Max_length = 0;
    t->s_Length = &Lumi_empty_length;
    t->s = NULL;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(to);
    free(to);
}
/// @ test-memory-temp-2
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    Seq_Length s_Max_length;
    Seq_Length* s_Length;
};
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun(ut_M_Test* to, char* s, Seq_Length s_Max_length, Seq_Length* s_Length, char* s2, Seq_Length s2_Max_length, Seq_Length* s2_Length);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    String_Del(self->s);
    free(self->s);
}
void ut_M_fun(ut_M_Test* to, char* s, Seq_Length s_Max_length, Seq_Length* s_Length, char* s2, Seq_Length s2_Max_length, Seq_Length* s2_Length) {
    unsigned LUMI_loop_depth = 1;
    char* so = NULL;
    Seq_Length so_Max_length = 0;
    Seq_Length* so_Length = &Lumi_empty_length;
    char* so2 = NULL;
    Seq_Length so2_Max_length = 0;
    Seq_Length* so2_Length = &Lumi_empty_length;
    ut_M_Test* t3 = NULL;
    so_Max_length = s_Max_length;
    so_Length = s_Length;
    so = s;
    so2_Max_length = s2_Max_length;
    so2_Length = s2_Length;
    so2 = s2;
    if (to->s != NULL) {
        ut_M_Test* t1 = NULL;
        char* si = NULL;
        Seq_Length si_Max_length = 0;
        Seq_Length* si_Length = &Lumi_empty_length;
        String_Del(to->s);
        free(to->s);
        to->s_Max_length = 0;
        to->s_Length = &Lumi_empty_length;
        to->s = NULL;
        t1 = to;
        String_Del(t1->s);
        free(t1->s);
        t1->s_Max_length = 0;
        t1->s_Length = &Lumi_empty_length;
        t1->s = NULL;
        String_clear(so, so_Max_length, so_Length);
        so2_Max_length = so_Max_length;
        so2_Length = so_Length;
        so2 = so;
        String_clear(so2, so2_Max_length, so2_Length);
        si_Max_length = so2_Max_length;
        si_Length = so2_Length;
        si = so2;
    LUMI_block1_cleanup:
        (void)0;
    }
    else {
        ut_M_Test* t2 = NULL;
        char* si = NULL;
        Seq_Length si_Max_length = 0;
        Seq_Length* si_Length = &Lumi_empty_length;
        String_Del(to->s);
        free(to->s);
        to->s_Max_length = 0;
        to->s_Length = &Lumi_empty_length;
        to->s = NULL;
        t2 = to;
        String_Del(t2->s);
        free(t2->s);
        t2->s_Max_length = 0;
        t2->s_Length = &Lumi_empty_length;
        t2->s = NULL;
        String_clear(so, so_Max_length, so_Length);
        si_Max_length = so_Max_length;
        si_Length = so_Length;
        si = so;
        so2_Max_length = si_Max_length;
        so2_Length = si_Length;
        so2 = si;
        String_clear(so2, so2_Max_length, so2_Length);
    LUMI_block3_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    String_Del(to->s);
    free(to->s);
    to->s_Max_length = 0;
    to->s_Length = &Lumi_empty_length;
    to->s = NULL;
    t3 = to;
    String_Del(t3->s);
    free(t3->s);
    t3->s_Max_length = 0;
    t3->s_Length = &Lumi_empty_length;
    t3->s = NULL;
    String_clear(so, so_Max_length, so_Length);
LUMI_block0_cleanup:
    (void)0;
    String_Del(s2);
    free(s2);
    String_Del(s);
    free(s);
    ut_M_Test_Del(to);
    free(to);
}
/// @ test-memory-temp-3
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    ut_M_Test* next;
};
void ut_M_Test_Del(ut_M_Test* self);
Return_Code ut_M_fun(ut_M_Test* to);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    SELF_REF_DEL(ut_M_Test, next);
    free(self->next);
}
Return_Code ut_M_fun(ut_M_Test* to) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Test* t = NULL;
    t = to;
    do {
        LUMI_loop_depth = 3;
        if (!(t->next != NULL)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        CHECK_REF(7, LUMI_block1_cleanup, t->next)
        t = t->next;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(to);
    free(to);
    return LUMI_err;
}
/// @ test-memory-temp-e0
cannot assign value with access "user" into value with access "temp"
/// @ test-memory-temp-e1
assigning into an owner a non-owner access "temp"
/// @ test-memory-temp-e2
output "s" access should not be "temp" for non-primitive type "String"
/// @ test-memory-temp-e3
using modified reference "s"
/// @ test-memory-temp-e4
using modified reference "s"
/// @ test-memory-temp-e5
using modified reference "s"
/// @ test-memory-temp-e6
using modified reference "x"
/// @ test-memory-temp-e7
using invalid reference "so"
/// @ test-memory-temp-e8
using invalid reference "so"
/// @ test-memory-temp-e9
using invalid reference "s1"
/// @ test-memory-temp-e10
using invalid reference "s"
/// @ test-memory-temp-e11
using invalid reference "s"
/// @ test-memory-temp-e12
using invalid reference "t"
/// @ test-memory-temp-e13
using invalid reference "t"
/// @ test-memory-temp-e14
cannot take temporary owner from global "ostr"
/// @ test-memory-temp-e15
cannot take temporary owner from global "t"
/// @@ test-memory-output
/// @ test-memory-output-0
Return_Code ut_M_fun(char** s, Seq_Length* s_Max_length, Seq_Length** s_Length);
Return_Code ut_M_fun(char** s, Seq_Length* s_Max_length, Seq_Length** s_Length) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    INIT_NEW_SEQUENCE(2, LUMI_block0_cleanup, aux_String_0, char, 0x0c);
    String_Del(*s);
    free(*s);
    *s_Max_length = 0x0c;
    *s_Length = aux_String_0_Length;
    *s = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
    String_clear(*s, *s_Max_length, *s_Length);
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0);
    free(aux_String_0);
    return LUMI_err;
}
/// @ test-memory-output-e0
returning potentially illegal user output "s"
/// @ test-memory-output-e1
returning potentially illegal user output "s"
/// @ test-memory-output-e2
returning potentially illegal user output "s"
/// @ test-memory-output-e3
returning potentially illegal user output "s"
/// @ test-memory-output-e4
returning potentially illegal user output "sout"
/// @ test-memory-output-e5
returning potentially illegal user output "sout"
/// @ test-memory-output-e6
using invalid reference "s"
/// @ test-memory-output-e7
potentially not returning output "s"
/// @ test-memory-output-e8
potentially not returning output "s"
/// @ test-memory-output-e9
potentially not returning output "s"
/// @@ test-memory-constructor
/// @ test-memory-constructor-0
typedef struct ut_M_NoConstructor ut_M_NoConstructor;
typedef struct ut_M_HasConstructor ut_M_HasConstructor;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_NoConstructor {
    char s[0x0c];
    Seq_Length s_Length[1];
};
struct ut_M_HasConstructor {
    char* s;
    Seq_Length s_Max_length;
    Seq_Length* s_Length;
};
struct ut_M_Test {
    ut_M_NoConstructor vnc;
    ut_M_HasConstructor vhc;
    ut_M_NoConstructor svnc;
    Ref_Manager* svnc_Refman;
    ut_M_HasConstructor svhc;
    Ref_Manager* svhc_Refman;
};
void ut_M_NoConstructor_Del(ut_M_NoConstructor* self);
Return_Code ut_M_HasConstructor_new(ut_M_HasConstructor* self);
void ut_M_HasConstructor_Del(ut_M_HasConstructor* self);
Return_Code ut_M_Test_new(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_NoConstructor_dynamic = {(Dynamic_Del)ut_M_NoConstructor_Del};
Generic_Type_Dynamic ut_M_HasConstructor_dynamic = {(Dynamic_Del)ut_M_HasConstructor_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_NoConstructor_Del(ut_M_NoConstructor* self) {
    if (self == NULL) return;
}
Return_Code ut_M_HasConstructor_new(ut_M_HasConstructor* self) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    INIT_NEW_SEQUENCE(6, LUMI_block0_cleanup, aux_String_0, char, 0x0c);
    String_Del(self->s);
    free(self->s);
    self->s_Max_length = 0x0c;
    self->s_Length = aux_String_0_Length;
    self->s = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0);
    free(aux_String_0);
    return LUMI_err;
}
void ut_M_HasConstructor_Del(ut_M_HasConstructor* self) {
    if (self == NULL) return;
    String_Del(self->s);
    free(self->s);
}
Return_Code ut_M_Test_new(ut_M_Test* self) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    String_clear(self->vnc.s, 0x0c, self->vnc.s_Length);
    String_clear(self->svnc.s, 0x0c, self->svnc.s_Length);
    LUMI_err = ut_M_HasConstructor_new(&(self->vhc));
    CHECK(15, LUMI_block0_cleanup)
    String_clear(self->vhc.s, self->vhc.s_Max_length, self->vhc.s_Length);
    LUMI_err = ut_M_HasConstructor_new(&(self->svhc));
    CHECK(17, LUMI_block0_cleanup)
    String_clear(self->svhc.s, self->svhc.s_Max_length, self->svhc.s_Length);
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_HasConstructor_Del(&(self->svhc));
    LUMI_var_dec_ref(self->svhc_Refman);
    ut_M_NoConstructor_Del(&(self->svnc));
    LUMI_var_dec_ref(self->svnc_Refman);
    ut_M_HasConstructor_Del(&(self->vhc));
    ut_M_NoConstructor_Del(&(self->vnc));
}
/// @ test-memory-constructor-1
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Base {
    char* s;
    Seq_Length s_Max_length;
    Seq_Length* s_Length;
};
struct ut_M_Mid {
    ut_M_Base _base;
};
struct ut_M_Test {
    ut_M_Mid _base;
    ut_M_Base* b;
};
Return_Code ut_M_Base_new(ut_M_Base* self);
void ut_M_Base_Del(ut_M_Base* self);
Return_Code ut_M_Mid_new(ut_M_Mid* self);
void ut_M_Mid_Del(ut_M_Mid* self);
Return_Code ut_M_Test_new(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
void ut_M_fun1(void);
void ut_M_fun2(void (*f)(void));
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Return_Code ut_M_Base_new(ut_M_Base* self) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    char* aux_String_0 = NULL;
    Seq_Length aux_String_0_Max_length = 0;
    Seq_Length* aux_String_0_Length = &Lumi_empty_length;
    INIT_NEW_SEQUENCE(6, LUMI_block0_cleanup, aux_String_0, char, 0x0c);
    String_Del(self->s);
    free(self->s);
    self->s_Max_length = 0x0c;
    self->s_Length = aux_String_0_Length;
    self->s = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Length = &Lumi_empty_length;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0);
    free(aux_String_0);
    return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    String_Del(self->s);
    free(self->s);
}
Return_Code ut_M_Mid_new(ut_M_Mid* self) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    LUMI_err = ut_M_Base_new(&(self->_base));
    CHECK(9, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_Mid_Del(ut_M_Mid* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
Return_Code ut_M_Test_new(ut_M_Test* self) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_fun1();
    ut_M_fun2(ut_M_fun1);
    CHECK_REF(15, LUMI_block0_cleanup, self->b)
    LUMI_err = ut_M_Base_new(self->b);
    CHECK(15, LUMI_block0_cleanup)
    LUMI_err = ut_M_Mid_new(&(self->_base));
    CHECK(16, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base));
    ut_M_Base_Del(self->b);
    free(self->b);
}
void ut_M_fun1(void) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun2(void (*f)(void)) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-memory-constructor-2
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    uint8_t a;
    int8_t b;
    uint8_t c;
    int8_t d;
    int8_t e;
};
void ut_M_Test_new(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_new(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    self->a = 0x01;
    self->b = -0x01;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ test-memory-constructor-e0
non-conditional reference in type without constructor "Error"
/// @ test-memory-constructor-e1
constructor did not initialize field "s"
/// @ test-memory-constructor-e2
using invalid reference "self.s"
/// @ test-memory-constructor-e3
using invalid reference "self"
/// @ test-memory-constructor-e4
using invalid reference "self"
/// @ test-memory-constructor-e5
constructor did not initialize field "s"
/// @ test-memory-constructor-e6
constructor did not initialize field "s"
/// @ test-memory-constructor-e7
constructor did not initialize field "s"
/// @ test-memory-constructor-e8
variable with constructor in type without constructor "Error"
/// @ test-memory-constructor-e9
constructor did not initialize field "t"
/// @ test-memory-constructor-e10
constructor did not initialize field "s"
/// @ test-memory-constructor-e11
using invalid reference "self.t"
/// @ test-memory-constructor-e12
using invalid reference "self.t"
/// @ test-memory-constructor-e13
non-zero integer in type without constructor "Test"
/// @ test-memory-constructor-e14
constructor did not initialize field "a"
/// @ test-memory-constructor-e15
using invalid reference "self.a"
/// @@ test-memory-error
/// @ test-memory-error-e0
assigning reference into itself
/// @ test-memory-error-e1
fields cannot have access "user"
/// @ test-memory-error-e2
fields cannot have access "temp"
/// @ test-memory-error-e3
argument "s" access should not be "var" for non-primitive type "String"
/// @ test-memory-error-e4
argument "s" access should not be "var" for non-primitive type "String"
/// @@ test-c-objects
/// @ test-c-objects-0
uint16_t u16 = 0;
    int16_t s16 = 0;
    uint32_t u32 = 0;
    int32_t s32 = 0;
    uint64_t u64 = 0;
    int64_t s64 = 0;
    cdef_M_Char c_char = 0;
    cdef_M_Schar c_schar = 0;
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
    c_char = s16;
    s32 = c_char;
    c_schar = s16;
    s32 = c_schar;
    c_uchar = u16;
    u16 = c_uchar;
    c_short = s32;
    s64 = c_short;
    c_ushort = u32;
    u32 = c_ushort;
    c_int = s64;
    s64 = (c_int < -INT64_MAX)? -INT64_MAX: c_int;
    c_uint = u64;
    u64 = c_uint;
    c_long = s64;
    s64 = (c_long < -INT64_MAX)? -INT64_MAX: c_long;
    c_ulong = u64;
    u64 = c_ulong;
    c_size = u64;
    u64 = c_size;
    c_float = s64;
    s64 = (c_float < -INT64_MAX)? -INT64_MAX: c_float;
    c_double = s64;
    s64 = (c_double < -INT64_MAX)? -INT64_MAX: c_double;
    c_long_double = s64;
    s64 = (c_long_double < -INT64_MAX)? -INT64_MAX: c_long_double;
    ut_M_j = CLAMPED_ADD_SS(c_char, (CLAMPED_ADD_SU(c_schar, (CLAMPED_ADD_US(c_uchar, (CLAMPED_ADD_SU(c_short, (CLAMPED_ADD_US(c_ushort, (CLAMPED_ADD_SU(c_int, (CLAMPED_ADD_US(c_uint, (CLAMPED_ADD_SU(c_long, (CLAMPED_ADD_UU(c_ulong, (CLAMPED_ADD_US(c_size, (CLAMPED_ADD_SS(c_float, (CLAMPED_ADD_SS(c_double, (CLAMPED_ADD_SS(c_long_double, (c_char), -0x8000000000000000, INT64_MAX)), -0x8000000000000000, INT64_MAX)), -0x8000000000000000, INT64_MAX)), 0, UINT64_MAX)), 0, UINT64_MAX)), -0x8000000000000000, INT64_MAX)), 0, UINT64_MAX)), -0x8000000000000000, INT64_MAX)), 0, UINT32_MAX)), -0x80000000, INT32_MAX)), 0, UINT16_MAX)), -0x8000, INT16_MAX)), -0x010000, UINT16_MAX);
/// @ test-c-objects-1
void* p_void = 0;
    cdef_M_Char* p_char = 0;
    cdef_M_Uint* p_uint = 0;
    ut_M_Test* p_test = 0;
    cdef_M_Int** pp_int = 0;
    cdef_M_Char*** ppp_char = 0;
    p_void = p_char;
    p_uint = p_void;
    p_char = p_uint;
/// @ test-c-objects-2
cdef_M_Int cint = 0;
    cdef_M_Int* p_int = 0;
    cdef_M_Int** pp_int = 0;
    cdef_M_Int* arr_int = NULL;
    Seq_Length arr_int_Length = 0;
    ut_M_Test test_Var = {0};
    ut_M_Test* test = NULL;
    ut_M_Test* u_test = NULL;
    ut_M_Test* p_test = 0;
    ut_M_Test* arr_test = NULL;
    Seq_Length arr_test_Length = 0;
    CHECK_REF(5, LUMI_block0_cleanup, arr_int)
    cdef_M_Pointer_set_from_array(p_int, arr_int, arr_int_Length);
    cdef_M_Pointer_set_point_to(p_int, cint, &cdef_M_Int_dynamic);
    cdef_M_Pointer_set_point_to(pp_int, p_int, &cdef_M_Int*_dynamic);
    p_int = cdef_M_Pointer_get_pointed_at(pp_int, 0);
    cint = cdef_M_Pointer_get_pointed_at(p_int, 0x03);
    test = &test_Var;
    u_test = test;
    CHECK_REF(14, LUMI_block0_cleanup, arr_test)
    cdef_M_Pointer_set_from_array(p_test, arr_test, arr_test_Length);
    cdef_M_Pointer_set_from_ref(p_test, test, &ut_M_Test_dynamic);
    u_test = ((ut_M_Test*)cdef_M_Pointer_get_ref_at(p_test, 0x05));
/// @ test-c-objects-3
Char* p_char = 0;
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_ostr)
    cdef_M_Pointer_set_from_array(p_char, ut_M_ostr, *ut_M_ostr_Length);
    CHECK_REF(3, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = cdef_M_copy_to_string(p_char, ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length);
    CHECK(3, LUMI_block0_cleanup)
    CHECK_REF(4, LUMI_block0_cleanup, ut_M_ostr)
    cdef_M_set_null_term_length(ut_M_ostr, ut_M_ostr_Max_length, ut_M_ostr_Length);
/// @ test-c-objects-4
Byte* p_byte = 0;
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_buff)
    LUMI_err = cdef_M_copy_to_buffer(p_byte, 0x04, ut_M_buff, ut_M_buff_Max_length, ut_M_buff_Length);
    CHECK(2, LUMI_block0_cleanup)
/// @ test-c-objects-e0
dynamic pointed type "Ta"
/// @ test-c-objects-e1
cannot assign value with access "user" into value with access "var"
/// @ test-c-objects-e2
assigning into non assignable expression
/// @@ test-cleanup-function
/// @ test-cleanup-function-0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    char* s;
    Seq_Length s_Max_length;
    Seq_Length* s_Length;
};
void ut_M_Test_cleanup(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_cleanup(ut_M_Test* self) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    {
        ++LUMI_trace_ignore_count;
        CHECK_REF(5, LUMI_block1_cleanup, self->s)
        String_clear(self->s, self->s_Max_length, self->s_Length);
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
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Test_cleanup(self);
    String_Del(self->s);
    free(self->s);
}
/// @ test-cleanup-function-1
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Base {
    uint32_t x;
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
void ut_M_Base_cleanup(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Test_cleanup(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_meth};
ut_M_Test_Dynamic ut_M_Test_dynamic = {{(Dynamic_Del)ut_M_Test_Del, ut_M_Base_meth}};
void ut_M_Base_meth(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_cleanup(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    self_Dynamic->meth(self, self_Dynamic);
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_cleanup(self, self_Dynamic);
}
void ut_M_Test_cleanup(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    self_Dynamic->_base.meth(&(self->_base), &(self_Dynamic->_base));
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Test_cleanup(self, self_Dynamic);
    ut_M_Base_Del(&(self->_base), &(self_Dynamic->_base));
}
/// @ test-cleanup-function-e0
cleanup already defined for type "Test"
/// @ test-cleanup-function-e1
expected "(" after "cleanup", got "!"
/// @ test-cleanup-function-e2
error raised inside function not declared as error raising "cleanup"
/// @ test-cleanup-function-e3
cleanup with arguments
/// @ test-cleanup-function-e4
cleanup with arguments
/// @ test-cleanup-function-e5
using reserved method name "cleanup"
/// @
