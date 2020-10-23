typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
typedef struct ut_M_Ta ut_M_Ta;
typedef struct ut_M_Ta_Dynamic ut_M_Ta_Dynamic;
typedef struct ut_M_Tb ut_M_Tb;
typedef struct ut_M_Tb_Dynamic ut_M_Tb_Dynamic;
typedef struct ut_M_Tc ut_M_Tc;
typedef struct ut_M_Tc_Dynamic ut_M_Tc_Dynamic;
typedef struct ut_M_Data ut_M_Data;
typedef struct ut_M_Data_Dynamic ut_M_Data_Dynamic;
struct ut_M_Test {
    uint32_t num;
    ut_M_Test* t;
    Ref_Manager* t_Refman;
    void (*fun)(void);
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Ta {
    ut_M_Test _base;
    uint32_t numa;
};
struct ut_M_Ta_Dynamic {
    ut_M_Test_Dynamic _base;
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
struct ut_M_Data_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_meth(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
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
void ut_M_Data_Del(ut_M_Data* self, ut_M_Data_Dynamic* self_Dynamic);
void ut_M_fun0(void);
void ut_M_fun1(uint32_t x, String* s, String* o);
void ut_M_fun2(String** s, Ref_Manager** s_Refman, uint32_t* x);
void ut_M_fun3(uint32_t x, String** s, Ref_Manager** s_Refman);
void ut_M_fun4(uint32_t x);
void ut_M_fun5(uint32_t x, uint32_t* y);
void ut_M_fun6(uint32_t x, uint32_t y, uint32_t* n, uint32_t* m);
void ut_M_fun7(ut_M_Tb* tb, Ref_Manager* tb_Refman, ut_M_Tb_Dynamic* tb_Dynamic, ut_M_Tb** tbo, Ref_Manager** tbo_Refman, ut_M_Tb_Dynamic** tbo_Dynamic);
void ut_M_fun8(String* s, Ref_Manager* s_Refman);
Return_Code ut_M_fune(void);
Return_Code ut_M_mock(String* str, Byte* bfr, uint32_t bfr_Length, String** so, Ref_Manager** so_Refman, uint32_t* io, ut_M_Test** to, Ref_Manager** to_Refman, ut_M_Tc** tco, Ref_Manager** tco_Refman, ut_M_Tc_Dynamic** tco_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
ut_M_Ta_Dynamic ut_M_Ta_dynamic = {
    {
        (Dynamic_Del)ut_M_Ta_Del
    },
    ut_M_Ta_dyn
};
ut_M_Tb_Dynamic ut_M_Tb_dynamic = {
    {
        {
            (Dynamic_Del)ut_M_Tb_Del
        },
        (void (*)(ut_M_Ta* self, ut_M_Ta_Dynamic* self_Dynamic))ut_M_Tb_dyn
    }
};
ut_M_Tc_Dynamic ut_M_Tc_dynamic = {
    {
        {
            {
                (Dynamic_Del)ut_M_Tc_Del
            },
            (void (*)(ut_M_Ta* self, ut_M_Ta_Dynamic* self_Dynamic))ut_M_Tc_dyn
        }
    }
};
ut_M_Data_Dynamic ut_M_Data_dynamic = {
    (Dynamic_Del)ut_M_Data_Del
};
uint32_t ut_M_i = 0;
int32_t ut_M_j = 0;
Byte ut_M_bt = 0;
Char ut_M_c = 0;
Bool ut_M_b = 0;
String* ut_M_ostr = NULL;
Byte* ut_M_buff = NULL;
uint32_t ut_M_buff_Length = 0;
uint32_t* ut_M_arr = NULL;
uint32_t ut_M_arr_Length = 0;
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
String* ut_M_sarr = NULL;
uint32_t ut_M_sarr_Length = 0;
Ref_Manager* ut_M_sarr_Refman = NULL;
Byte* ut_M_barr = NULL;
uint32_t ut_M_barr_Length = 0;
uint32_t ut_M_barr_Value_length = 0;
Ref_Manager* ut_M_barr_Refman = NULL;
void ut_M_Test_meth(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
    ut_M_Test_Del(&(self->_base), NULL);
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
void ut_M_Data_Del(ut_M_Data* self, ut_M_Data_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
void ut_M_fun0(void) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun1(uint32_t x, String* s, String* o) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    String_Del(o, NULL);
    free(o);
}
void ut_M_fun2(String** s, Ref_Manager** s_Refman, uint32_t* x) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun3(uint32_t x, String** s, Ref_Manager** s_Refman) {
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
void ut_M_fun8(String* s, Ref_Manager* s_Refman) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    String_Del(s, NULL);
    LUMI_owner_dec_ref(s_Refman);
}
Return_Code ut_M_fune(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
Return_Code ut_M_mock(String* str, Byte* bfr, uint32_t bfr_Length, String** so, Ref_Manager** so_Refman, uint32_t* io, ut_M_Test** to, Ref_Manager** to_Refman, ut_M_Tc** tco, Ref_Manager** tco_Refman, ut_M_Tc_Dynamic** tco_Dynamic) {
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
/// @ test-char-expression-6
uint8_t c10 = 0;
    uint8_t c15 = 0;
    uint8_t c39 = 0;
    uint8_t c97 = 0;
    uint8_t c169 = 0;
    uint8_t c184 = 0;
    c10 = '\n';
    c15 = '\x0f';
    c39 = '\'';
    c97 = 'a';
    c169 = '\xA9';
    c184 = '\270';
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
/// @ test-char-expression-e11
illegal character constant "'\777'"
/// @ test-char-expression-e12
illegal character constant "'\0'"
/// @ test-char-expression-e13
illegal character constant "'\x00'"
/// @@ test-string-expression
/// @ test-string-expression-0
static Byte aux_Array_0[] = {'s','o','m','e',' ','s','t','r','i','n','g','\0',};
    bfr_Length = 0x0b;
    bfr = aux_Array_0;
/// @ test-string-expression-1
static Byte aux_Array_0[] = {'\n','s','t','r','i','n','g','\'','\t','\"','\xd5','w','i','t','h','!','\\','\'','\xc7','f',
        'o','r','m','a','t','t','i','n','g','\n','\0',};
    bfr_Length = 0x1e;
    bfr = aux_Array_0;
/// @ test-string-expression-2
static Byte aux_Array_0[] = {'l','i','n','e','s','p','l','i','t','s','t','r','i','n','g','\0',};
    bfr_Length = 0x0f;
    bfr = aux_Array_0;
/// @ test-string-expression-3
static Byte aux_Array_0[] = {'m','u','l','t','i','\n','l','i','n','e','\n','s','t','r','i','n','g','\n','\0',};
    bfr_Length = 0x12;
    bfr = aux_Array_0;
/// @ test-string-expression-4
static Byte aux_Array_0[] = {'l','i','n','e',' ','s','p','l','i','t','\0',};
    bfr_Length = 0x0a;
    bfr = aux_Array_0;
/// @ test-string-expression-5
static Byte aux_Array_0[] = {'\xd7','\xa9','\xd6','\xb8','\xd7','\x81','\xd7','\x9c','\xd7','\x95','\xd6','\xb9','\xd7','\x9d',' ','\xf0','\x9f','\x91','\x8b','\xf0',
        '\x9f','\x8f','\xbe',' ','\xd7','\xa2','\xd7','\x95','\xd6','\xb9','\xd7','\x9c','\xd6','\xb8','\xd6','\xbd','\xd7','\x9d',' ','\xf0',
        '\x9f','\x8c','\x8e','\0',};
    bfr_Length = 0x2b;
    bfr = aux_Array_0;
/// @ test-string-expression-e0
no '"' around string literal ""aaa"
/// @ test-string-expression-e1
too short string literal """
/// @ test-string-expression-e2
'"' inside string literal "error"+"string"
/// @ test-string-expression-e3
indentation too short, expected 12 got 8
/// @ test-string-expression-e4
indentation too short, expected 12 got 8
/// @ test-string-expression-e5
unfinished escape in string literal "\70"
/// @ test-string-expression-e6
unfinished escape in string literal "\xa"
/// @ test-string-expression-e7
illegal character constant "\787"
/// @ test-string-expression-e8
illegal character constant "\x8g"
/// @ test-string-expression-e9
illegal character constant "\c"
/// @ test-string-expression-e10
illegal character constant "\777"
/// @ test-string-expression-e11
illegal character constant "\x00"
/// @ test-string-expression-large
void ut_M_fun(void);
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    Byte* s = NULL;
    uint32_t s_Length = 0;
    static Byte aux_Array_0[] = {'0','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9',
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
    s_Length = 0x0258;
    s = aux_Array_0;
LUMI_block0_cleanup:
    (void)0;
}
/// @@ test-buffer-expression
/// @ test-buffer-expression-0
static Byte aux_Array_0[] = {0x4a,0x00,0xe2,0xff,0x59,};
    bfr_Length = 0x05;
    bfr = aux_Array_0;
/// @ test-buffer-expression-1
static Byte aux_Array_0[] = {0x4a,0x00,0xe2,0xff,0x59,0xa8,};
    bfr_Length = 0x06;
    bfr = aux_Array_0;
/// @ test-buffer-expression-2
static Byte aux_Array_0[] = {0x4a,0x00,0xe2,0xff,0x59,0xa8,};
    bfr_Length = 0x06;
    bfr = aux_Array_0;
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
    uint32_t b_Length = 0;
    static Byte aux_Array_0[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,
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
    b_Length = 0x0258;
    b = aux_Array_0;
LUMI_block0_cleanup:
    (void)0;
}
/// @@ test-empty-expression
/// @ test-empty-expression-0
bfr_Length = 0;
    bfr = NULL;
/// @ test-empty-expression-1
LUMI_inc_ref(NULL);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = NULL;
    ut_M_t = NULL;
/// @ test-empty-expression-2
String_Del(*so, NULL);
    LUMI_owner_dec_ref(*so_Refman);
    *so_Refman = NULL;
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
type "Void Expression" has no member "error"
/// @ test-member-expression-e2
type "Test" has no member "error"
/// @ test-member-expression-e3
type "Int" has no member "error"
/// @@ test-slice-expression
/// @ test-slice-expression-0
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    if (0x0d >= ut_M_buff_Length) RAISE(1, LUMI_block0_cleanup, slice_index)
    ut_M_bt = ut_M_buff[0x0d];
/// @ test-slice-expression-1
Byte* y = NULL;
    uint32_t y_Length = 0;
    Byte* aux_Array_0 = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_buff)
    if (SAFE_SUM_LARGER(0x02, 0x06, ut_M_buff_Length)) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = ut_M_buff + 0x02;
    y_Length = 0x06;
    y = aux_Array_0;
/// @ test-slice-expression-2
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (0x0d >= ut_M_arr_Length) RAISE(1, LUMI_block0_cleanup, slice_index)
    ut_M_i = ut_M_arr[0x0d];
/// @ test-slice-expression-3
uint32_t* x = NULL;
    uint32_t x_Length = 0;
    uint32_t* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_i <= 0 || SAFE_SUM_LARGER(0x02, ut_M_i, ut_M_arr_Length)) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = ut_M_arr + 0x02;
    aux_Array_0_Length = ut_M_i;
    x_Length = aux_Array_0_Length;
    x = aux_Array_0;
/// @ test-slice-expression-4
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    if (0x04 >= ut_M_buff_Length) RAISE(1, LUMI_block0_cleanup, slice_index)
    ut_M_buff[0x04] = ut_M_bt;
/// @ test-slice-expression-5
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (0x04 >= ut_M_arr_Length) RAISE(1, LUMI_block0_cleanup, slice_index)
    ut_M_arr[0x04] = ut_M_i;
/// @ test-slice-expression-6
ut_M_Test* tarr = NULL;
    uint32_t tarr_Length = 0;
    Ref_Manager* tarr_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, tarr)
    if (0x03 >= tarr_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(tarr_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = tarr_Refman;
    ut_M_t = tarr + 0x03;
/// @ test-slice-expression-7
Byte vba[0x08 * 0x05] = {0};
    Byte* bf = NULL;
    uint32_t bf_Length = 0;
    Byte* ba = NULL;
    uint32_t ba_Length = 0;
    uint32_t ba_Value_length = 0;
    Byte* aux_Array_0 = NULL;
    Byte* aux_Array_1 = NULL;
    /* initializing vba */
    aux_Array_0 = vba + 0x03 * 0x05;
    bf_Length = 0x05;
    bf = aux_Array_0;
    aux_Array_1 = vba + 0x02 * 0x05;
    ba_Length = 0x04;
    ba_Value_length = 0x05;
    ba = aux_Array_1;
/// @ test-slice-expression-8
Return_Code ut_M_fun(Byte* b, uint32_t b_Length, Byte* ba, uint32_t ba_Length, uint32_t ba_Value_length, Ref_Manager* ba_Refman);
Return_Code ut_M_fun(Byte* b, uint32_t b_Length, Byte* ba, uint32_t ba_Length, uint32_t ba_Value_length, Ref_Manager* ba_Refman) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Byte y = 0;
    Byte* bpart = NULL;
    uint32_t bpart_Length = 0;
    Byte* bi = NULL;
    uint32_t bi_Length = 0;
    Byte* aux_Array_0 = NULL;
    Byte* aux_Array_1 = NULL;
    uint32_t aux_Array_1_Length = 0;
    Ref_Manager* aux_Array_1_Refman = NULL;
    if (0x05 >= b_Length) RAISE(4, LUMI_block0_cleanup, slice_index)
    y = b[0x05];
    if (SAFE_SUM_LARGER(0x04, 0x02, b_Length)) RAISE(5, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = b + 0x04;
    bpart_Length = 0x02;
    bpart = aux_Array_0;
    if (0x03 >= ba_Length) RAISE(6, LUMI_block0_cleanup, slice_index)
    aux_Array_1 = ba + 0x03 * ba_Value_length;
    aux_Array_1_Length = ba_Value_length;
    aux_Array_1_Refman = ba_Refman;
    LUMI_inc_ref(aux_Array_1_Refman);
    CHECK_REFMAN(6, LUMI_block0_cleanup, aux_Array_1_Refman)
    bi_Length = aux_Array_1_Length;
    bi = aux_Array_1;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(aux_Array_1_Refman);
    LUMI_owner_dec_ref(ba_Refman);
    return LUMI_err;
}
/// @ test-slice-expression-9
String* sa = NULL;
    uint32_t sa_Length = 0;
    Ref_Manager* sa_Refman = NULL;
    static Byte aux_Array_0[] = {'t','e','x','t','\0',};
    CHECK_REF(2, LUMI_block0_cleanup, sa)
    if (0x03 >= sa_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    CHECK_REFMAN(2, LUMI_block0_cleanup, sa_Refman)
    LUMI_err = String_new(sa + 0x03, aux_Array_0, 0x04);
    CHECK(2, LUMI_block0_cleanup)
    ARRAY_DEL(String, sa, sa_Length)
    LUMI_owner_dec_ref(sa_Refman);
    sa_Refman = NULL;
    sa_Length = 0;
    sa = NULL;
/// @ test-slice-expression-10
uint32_t* aai = NULL;
    uint32_t aai_Length = 0;
    uint32_t aai_Value_length = 0;
    Ref_Manager* aai_Refman = NULL;
    uint32_t* ua = NULL;
    uint32_t ua_Length = 0;
    uint32_t ua_Value_length = 0;
    Ref_Manager* ua_Refman = NULL;
    uint32_t* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    Ref_Manager* aux_Array_0_Refman = NULL;
    uint32_t* aux_Array_1 = NULL;
    uint32_t aux_Array_1_Value_length = 0;
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
    uint32_t aai_Length = 0;
    uint32_t aai_Value_length = 0;
    uint32_t aai_Value_value_length = 0;
    uint32_t aai_Value_value_value_length = 0;
    Ref_Manager* aai_Refman = NULL;
    uint32_t* ua = NULL;
    uint32_t ua_Length = 0;
    uint32_t ua_Value_length = 0;
    uint32_t ua_Value_value_length = 0;
    Ref_Manager* ua_Refman = NULL;
    uint32_t* uaa = NULL;
    uint32_t uaa_Length = 0;
    uint32_t uaa_Value_length = 0;
    uint32_t uaa_Value_value_length = 0;
    uint32_t uaa_Value_value_value_length = 0;
    Ref_Manager* uaa_Refman = NULL;
    uint32_t* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    uint32_t aux_Array_0_Value_length = 0;
    uint32_t aux_Array_0_Value_value_length = 0;
    Ref_Manager* aux_Array_0_Refman = NULL;
    uint32_t* aux_Array_1 = NULL;
    uint32_t aux_Array_1_Value_length = 0;
    uint32_t aux_Array_1_Value_value_length = 0;
    uint32_t aux_Array_1_Value_value_value_length = 0;
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
String* aas = NULL;
    uint32_t aas_Length = 0;
    uint32_t aas_Value_length = 0;
    uint32_t aas_Value_value_length = 0;
    Ref_Manager* aas_Refman = NULL;
    String* wsa = NULL;
    uint32_t wsa_Length = 0;
    uint32_t wsa_Value_length = 0;
    Ref_Manager* wsa_Refman = NULL;
    String* wsaa = NULL;
    uint32_t wsaa_Length = 0;
    uint32_t wsaa_Value_length = 0;
    uint32_t wsaa_Value_value_length = 0;
    Ref_Manager* wsaa_Refman = NULL;
    Byte* aab = NULL;
    uint32_t aab_Length = 0;
    uint32_t aab_Value_length = 0;
    uint32_t aab_Value_value_length = 0;
    uint32_t aab_Value_value_value_length = 0;
    Ref_Manager* aab_Refman = NULL;
    Byte* wba = NULL;
    uint32_t wba_Length = 0;
    uint32_t wba_Value_length = 0;
    uint32_t wba_Value_value_length = 0;
    Ref_Manager* wba_Refman = NULL;
    Byte* wbaa = NULL;
    uint32_t wbaa_Length = 0;
    uint32_t wbaa_Value_length = 0;
    uint32_t wbaa_Value_value_length = 0;
    uint32_t wbaa_Value_value_value_length = 0;
    Ref_Manager* wbaa_Refman = NULL;
    String* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    uint32_t aux_Array_0_Value_length = 0;
    Ref_Manager* aux_Array_0_Refman = NULL;
    String* aux_Array_1 = NULL;
    uint32_t aux_Array_1_Value_length = 0;
    uint32_t aux_Array_1_Value_value_length = 0;
    Ref_Manager* aux_Array_1_Refman = NULL;
    Byte* aux_Array_2 = NULL;
    uint32_t aux_Array_2_Length = 0;
    uint32_t aux_Array_2_Value_length = 0;
    uint32_t aux_Array_2_Value_value_length = 0;
    Ref_Manager* aux_Array_2_Refman = NULL;
    Byte* aux_Array_3 = NULL;
    uint32_t aux_Array_3_Value_length = 0;
    uint32_t aux_Array_3_Value_value_length = 0;
    uint32_t aux_Array_3_Value_value_value_length = 0;
    Ref_Manager* aux_Array_3_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, aas)
    if (0x03 >= aas_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = aas + 0x03 * aas_Value_length * aas_Value_value_length;
    aux_Array_0_Length = aas_Value_length;
    aux_Array_0_Value_length = aas_Value_value_length;
    aux_Array_0_Refman = aas_Refman;
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_dec_ref(wsa_Refman);
    wsa_Refman = aux_Array_0_Refman;
    wsa_Length = aux_Array_0_Length;
    wsa_Value_length = aux_Array_0_Value_length;
    wsa = aux_Array_0;
    CHECK_REF(3, LUMI_block0_cleanup, aas)
    if (SAFE_SUM_LARGER(0x02, 0x04, aas_Length)) RAISE(3, LUMI_block0_cleanup, slice_index)
    aux_Array_1 = aas + 0x02 * aas_Value_length * aas_Value_value_length;
    aux_Array_1_Value_length = aas_Value_length;
    aux_Array_1_Value_value_length = aas_Value_value_length;
    aux_Array_1_Refman = aas_Refman;
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_dec_ref(wsaa_Refman);
    wsaa_Refman = aux_Array_1_Refman;
    wsaa_Length = 0x04;
    wsaa_Value_length = aux_Array_1_Value_length;
    wsaa_Value_value_length = aux_Array_1_Value_value_length;
    wsaa = aux_Array_1;
    ARRAY_DEL(String, aas, aas_Length)
    LUMI_owner_dec_ref(aas_Refman);
    aas_Refman = NULL;
    aas_Length = 0;
    aas_Value_length = 0;
    aas_Value_value_length = 0;
    aas = NULL;
    CHECK_REF(6, LUMI_block0_cleanup, aab)
    if (0x03 >= aab_Length) RAISE(6, LUMI_block0_cleanup, slice_index)
    aux_Array_2 = aab + 0x03 * aab_Value_length * aab_Value_value_length * aab_Value_value_value_length;
    aux_Array_2_Length = aab_Value_length;
    aux_Array_2_Value_length = aab_Value_value_length;
    aux_Array_2_Value_value_length = aab_Value_value_value_length;
    aux_Array_2_Refman = aab_Refman;
    LUMI_inc_ref(aux_Array_2_Refman);
    LUMI_inc_ref(aux_Array_2_Refman);
    LUMI_dec_ref(wba_Refman);
    wba_Refman = aux_Array_2_Refman;
    wba_Length = aux_Array_2_Length;
    wba_Value_length = aux_Array_2_Value_length;
    wba_Value_value_length = aux_Array_2_Value_value_length;
    wba = aux_Array_2;
    CHECK_REF(7, LUMI_block0_cleanup, aab)
    if (SAFE_SUM_LARGER(0x02, 0x04, aab_Length)) RAISE(7, LUMI_block0_cleanup, slice_index)
    aux_Array_3 = aab + 0x02 * aab_Value_length * aab_Value_value_length * aab_Value_value_value_length;
    aux_Array_3_Value_length = aab_Value_length;
    aux_Array_3_Value_value_length = aab_Value_value_length;
    aux_Array_3_Value_value_value_length = aab_Value_value_value_length;
    aux_Array_3_Refman = aab_Refman;
    LUMI_inc_ref(aux_Array_3_Refman);
    LUMI_inc_ref(aux_Array_3_Refman);
    LUMI_dec_ref(wbaa_Refman);
    wbaa_Refman = aux_Array_3_Refman;
    wbaa_Length = 0x04;
    wbaa_Value_length = aux_Array_3_Value_length;
    wbaa_Value_value_length = aux_Array_3_Value_value_length;
    wbaa_Value_value_value_length = aux_Array_3_Value_value_value_length;
    wbaa = aux_Array_3;
    ARRAY_DEL(String, aas, aas_Length)
    LUMI_owner_dec_ref(aas_Refman);
    aas_Refman = NULL;
    aas_Length = 0;
    aas_Value_length = 0;
    aas_Value_value_length = 0;
    aas = NULL;
/// @ test-slice-expression-13
uint32_t aai[0x08 * 0x07 * 0x06 * 0x05] = {0};
    uint32_t* ua = NULL;
    uint32_t ua_Length = 0;
    uint32_t ua_Value_length = 0;
    uint32_t ua_Value_value_length = 0;
    uint32_t* uaa = NULL;
    uint32_t uaa_Length = 0;
    uint32_t uaa_Value_length = 0;
    uint32_t uaa_Value_value_length = 0;
    uint32_t uaa_Value_value_value_length = 0;
    uint32_t* aux_Array_0 = NULL;
    uint32_t* aux_Array_1 = NULL;
    /* initializing aai */
    aux_Array_0 = aai + 0x03 * 0x07 * 0x06 * 0x05;
    ua_Length = 0x07;
    ua_Value_length = 0x06;
    ua_Value_value_length = 0x05;
    ua = aux_Array_0;
    aux_Array_1 = aai + 0x02 * 0x07 * 0x06 * 0x05;
    uaa_Length = 0x04;
    uaa_Value_length = 0x07;
    uaa_Value_value_length = 0x06;
    uaa_Value_value_value_length = 0x05;
    uaa = aux_Array_1;
/// @ test-slice-expression-14
Byte aab[0x08 * 0x07 * 0x06 * 0x05] = {0};
    Byte* uba = NULL;
    uint32_t uba_Length = 0;
    uint32_t uba_Value_length = 0;
    uint32_t uba_Value_value_length = 0;
    Byte* ubaa = NULL;
    uint32_t ubaa_Length = 0;
    uint32_t ubaa_Value_length = 0;
    uint32_t ubaa_Value_value_length = 0;
    uint32_t ubaa_Value_value_value_length = 0;
    Byte* aux_Array_0 = NULL;
    Byte* aux_Array_1 = NULL;
    /* initializing aab */
    if (ut_M_i >= 0x08) RAISE(2, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = aab + ut_M_i * 0x07 * 0x06 * 0x05;
    uba_Length = 0x07;
    uba_Value_length = 0x06;
    uba_Value_value_length = 0x05;
    uba = aux_Array_0;
    aux_Array_1 = aab + 0x02 * 0x07 * 0x06 * 0x05;
    ubaa_Length = 0x04;
    ubaa_Value_length = 0x07;
    ubaa_Value_value_length = 0x06;
    ubaa_Value_value_value_length = 0x05;
    ubaa = aux_Array_1;
/// @ test-slice-expression-15
void ut_M_fun(void);
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    Byte aab[0x08 * 0x07 * 0x06 * 0x05] = {0};
    Byte* b = NULL;
    uint32_t b_Length = 0;
    Byte* aux_Array_0 = NULL;
    Byte* aux_Array_1 = NULL;
    Byte* aux_Array_2 = NULL;
    /* initializing aab */
    aux_Array_0 = aab + 0x04 * 0x07 * 0x06 * 0x05;
    aux_Array_1 = (aux_Array_0) + 0x03 * 0x06 * 0x05;
    aux_Array_2 = (aux_Array_1) + 0x02 * 0x05;
    b_Length = 0x05;
    b = aux_Array_2;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-slice-expression-16
Byte* x = NULL;
    uint32_t x_Length = 0;
    Byte* y = NULL;
    uint32_t y_Length = 0;
    Byte* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_ostr)
    String_bytes(ut_M_ostr, &(aux_Array_0), &(aux_Array_0_Length));
    x_Length = aux_Array_0_Length;
    x = aux_Array_0;
    y_Length = ut_M_buff_Length;
    y = ut_M_buff;
/// @ test-slice-expression-17
Byte* s = NULL;
    Byte* bf = NULL;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, s, Byte, 0x0c, 1);
    LUMI_err = sys_M_print(s, 0x0c);
    CHECK(2, LUMI_block0_cleanup)
    INIT_NEW_ARRAY(3, LUMI_block0_cleanup, bf, Byte, 0x0c, 1);
/// @ test-slice-expression-18
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    String* s;
    Byte* b;
    uint32_t b_Length;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_fun(void);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    free(self->b);
    String_Del(self->s, NULL);
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
    ut_M_Test_Del(t, NULL);
}
/// @ test-slice-expression-19
uint32_t* a = NULL;
    uint32_t a_Length = 0;
    int8_t x = 0;
    int8_t y = 0;
    uint8_t length = 0;
    uint32_t* aa = NULL;
    uint8_t aa_Length = 0;
    uint8_t xx = 0;
    uint8_t yy = 0;
    uint32_t ab[0x0c] = {0};
    uint32_t* aux_Array_0 = NULL;
    int8_t aux_Array_0_Length = 0;
    uint32_t* aux_Array_1 = NULL;
    int8_t aux_Array_1_Length = 0;
    uint32_t* aux_Array_2 = NULL;
    uint64_t aux_Array_2_Length = 0;
    uint32_t* aux_Array_3 = NULL;
    int8_t aux_Array_3_Length = 0;
    uint32_t* aux_Array_4 = NULL;
    uint32_t* aux_Array_5 = NULL;
    uint8_t aux_Array_5_Length = 0;
    uint32_t* aux_Array_6 = NULL;
    if (ut_M_i <= 0) RAISE(1, LUMI_block0_cleanup, array_too_short)
    INIT_NEW_LEN_ARRAY(1, LUMI_block0_cleanup, a, uint32_t, ut_M_i, 1);
    if (x < 0 || x <= 0 || SAFE_SUM_LARGER(x, x, ut_M_i)) RAISE(4, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = a + x;
    aux_Array_0_Length = x;
    if (y < 0 || (y + 0x01) <= 0) RAISE(4, LUMI_block0_cleanup, slice_index)
    aux_Array_1 = (aux_Array_0) + y;
    aux_Array_1_Length = y + 0x01;
    if (x < 0 || x >= y + 0x01) RAISE(4, LUMI_block0_cleanup, slice_index)
    if (SAFE_SUM_LARGER(ut_M_i, ((uint64_t)ut_M_i + 0x01), ut_M_i)) RAISE(4, LUMI_block0_cleanup, slice_index)
    aux_Array_2 = a + ut_M_i;
    aux_Array_2_Length = (uint64_t)ut_M_i + 0x01;
    if ((y + 0x01) <= 0) RAISE(4, LUMI_block0_cleanup, slice_index)
    aux_Array_3 = (aux_Array_2) + 0;
    aux_Array_3_Length = y + 0x01;
    if (y < 0) RAISE(4, LUMI_block0_cleanup, slice_index)
    aux_Array_4 = a + 0;
    if (ut_M_i >= 0x01) RAISE(4, LUMI_block0_cleanup, slice_index)
    ut_M_i = ((uint64_t)((aux_Array_1)[x]) + ((aux_Array_3)[y])) + ((aux_Array_4)[ut_M_i]);
    INIT_NEW_LEN_ARRAY(6, LUMI_block0_cleanup, aa, uint32_t, length, 1);
    xx = 0x0a;
    aux_Array_5 = aa + xx;
    aux_Array_5_Length = xx;
    ut_M_i = (aux_Array_5)[yy];
    /* initializing ab */
    aux_Array_6 = ab + 0x03;
    ut_M_i = (aux_Array_6)[0x03];
/// @ test-slice-expression-20
Byte* aux_Array_0 = NULL;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    if (0x02 >= ut_M_buff_Length) RAISE(1, LUMI_block0_cleanup, slice_index)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    if (SAFE_SUM_LARGER(0x01, 0x03, ut_M_buff_Length)) RAISE(1, LUMI_block0_cleanup, slice_index)
    aux_Array_0 = ut_M_buff + 0x01;
    ut_M_i = (uint16_t)(ut_M_buff[0x02]) + ((aux_Array_0)[0x02]);
/// @ test-slice-expression-21
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t va[0x04];
    uint32_t* wa;
    Ref_Manager* wa_Refman;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
Return_Code ut_M_fun(uint32_t* a4, Ref_Manager* a4_Refman, uint32_t* ad, uint32_t ad_Length, Ref_Manager* ad_Refman, uint32_t** oa6, Ref_Manager** oa6_Refman, uint32_t** oad, uint32_t* oad_Length, Ref_Manager** oad_Refman);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->wa_Refman);
}
Return_Code ut_M_fun(uint32_t* a4, Ref_Manager* a4_Refman, uint32_t* ad, uint32_t ad_Length, Ref_Manager* ad_Refman, uint32_t** oa6, Ref_Manager** oa6_Refman, uint32_t** oad, uint32_t* oad_Length, Ref_Manager** oad_Refman) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    uint32_t a8[0x08] = {0};
    Ref_Manager* a8_Refman = NULL;
    uint32_t i = 0;
    uint32_t* a2 = NULL;
    uint32_t* aux_Array_0 = NULL;
    Ref_Manager* aux_Array_0_Refman = NULL;
    uint32_t* aux_Array_1 = NULL;
    uint32_t aux_Array_1_Length = 0;
    Ref_Manager* aux_Array_1_Refman = NULL;
    LUMI_inc_ref(a4_Refman);
    LUMI_inc_ref(ad_Refman);
    if (ad_Length < 0x06) RAISE(6, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(ad_Refman);
    LUMI_dec_ref(*oa6_Refman);
    *oa6_Refman = ad_Refman;
    *oa6 = ad;
    LUMI_inc_ref(a4_Refman);
    LUMI_dec_ref(*oad_Refman);
    *oad_Refman = a4_Refman;
    *oad_Length = 0x04;
    *oad = a4;
    INIT_VAR_REFMAN(8, LUMI_block0_cleanup, a8)
    LUMI_inc_ref(a8_Refman);
    LUMI_dec_ref(*oa6_Refman);
    *oa6_Refman = a8_Refman;
    *oa6 = a8;
    LUMI_inc_ref(a8_Refman);
    LUMI_dec_ref(*oad_Refman);
    *oad_Refman = a8_Refman;
    *oad_Length = 0x08;
    *oad = a8;
    CHECK_REFMAN(11, LUMI_block0_cleanup, a4_Refman)
    i = a4[0x02];
    CHECK_REFMAN(12, LUMI_block0_cleanup, ad_Refman)
    if (0x02 >= ad_Length) RAISE(12, LUMI_block0_cleanup, slice_index)
    i = ad[0x02];
    i = a8[0x02];
    if (ad_Length < 0x04) RAISE(14, LUMI_block0_cleanup, slice_index)
    LUMI_err = ut_M_fun(ad, ad_Refman, a4, 0x04, a4_Refman, &(*oa6), &(*oa6_Refman), &(*oad), &(*oad_Length), &(*oad_Refman));
    CHECK(14, LUMI_block0_cleanup)
    LUMI_err = ut_M_fun(a8, a8_Refman, a8, 0x08, a8_Refman, &(aux_Array_0), &(aux_Array_0_Refman), &(aux_Array_1), &(aux_Array_1_Length), &(aux_Array_1_Refman));
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_dec_ref(*oad_Refman);
    *oad_Refman = aux_Array_0_Refman;
    *oad_Length = 0x06;
    *oad = aux_Array_0;
    if (aux_Array_1_Length < 0x06) RAISE(15, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_dec_ref(*oa6_Refman);
    *oa6_Refman = aux_Array_1_Refman;
    *oa6 = aux_Array_1;
    CHECK(15, LUMI_block0_cleanup)
    a2 = a8;
    CHECK_REFMAN(18, LUMI_block0_cleanup, a4_Refman)
    a2 = a4;
    CHECK_REFMAN(19, LUMI_block0_cleanup, ad_Refman)
    if (ad_Length < 0x02) RAISE(19, LUMI_block0_cleanup, slice_index)
    a2 = ad;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(aux_Array_1_Refman);
    LUMI_dec_ref(aux_Array_0_Refman);
    LUMI_var_dec_ref(a8_Refman);
    LUMI_dec_ref(ad_Refman);
    LUMI_dec_ref(a4_Refman);
    return LUMI_err;
}
/// @ test-slice-expression-22
Return_Code ut_M_fun(uint32_t* a4, uint32_t* ad, uint32_t ad_Length, uint32_t** oa4, uint32_t** oad, uint32_t* oad_Length);
Return_Code ut_M_fun(uint32_t* a4, uint32_t* ad, uint32_t ad_Length, uint32_t** oa4, uint32_t** oad, uint32_t* oad_Length) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    uint32_t* aux_Array_0 = NULL;
    uint32_t* aux_Array_1 = NULL;
    uint32_t aux_Array_1_Length = 0;
    if (ad_Length != 0x04) RAISE(3, LUMI_block0_cleanup, slice_index)
    free(*oa4);
    *oa4 = ad;
    ad = NULL;
    free(*oad);
    *oad_Length = 0x04;
    *oad = a4;
    a4 = NULL;
    LUMI_err = ut_M_fun(a4, ad, ad_Length, &(*oa4), &(*oad), &(*oad_Length));
    a4 = NULL;
    ad = NULL;
    CHECK(5, LUMI_block0_cleanup)
    if (ad_Length != 0x04) RAISE(6, LUMI_block0_cleanup, slice_index)
    LUMI_err = ut_M_fun(ad, a4, 0x04, &(aux_Array_0), &(aux_Array_1), &(aux_Array_1_Length));
    ad = NULL;
    a4 = NULL;
    free(*oad);
    *oad_Length = 0x04;
    *oad = aux_Array_0;
    aux_Array_0 = NULL;
    if (aux_Array_1_Length != 0x04) RAISE(6, LUMI_block0_cleanup, slice_index)
    free(*oa4);
    *oa4 = aux_Array_1;
    aux_Array_1 = NULL;
    CHECK(6, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    free(aux_Array_1);
    free(aux_Array_0);
    free(ad);
    free(a4);
    return LUMI_err;
}
/// @ test-slice-expression-23
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t av[0x06 * 0x07 * 0x08];
    uint32_t* as;
    Ref_Manager* as_Refman;
    uint32_t* ams;
    uint32_t ams_Value_length;
    Ref_Manager* ams_Refman;
    uint32_t* amd;
    uint32_t amd_Length;
    uint32_t amd_Value_value_length;
    Ref_Manager* amd_Refman;
    uint32_t* ar;
    uint8_t ar_Length;
    uint8_t ar_Value_length;
    uint8_t ar_Value_value_length;
    Ref_Manager* ar_Refman;
    uint32_t* ad;
    uint32_t ad_Length;
    uint32_t ad_Value_length;
    uint32_t ad_Value_value_length;
    Ref_Manager* ad_Refman;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
Return_Code ut_M_fun(uint32_t* as, Ref_Manager* as_Refman, uint32_t* ams, uint32_t ams_Value_length, Ref_Manager* ams_Refman, uint32_t* amd, uint32_t amd_Length, uint32_t amd_Value_value_length, Ref_Manager* amd_Refman, uint32_t* ar, uint8_t ar_Length, uint8_t ar_Value_length, uint8_t ar_Value_value_length, Ref_Manager* ar_Refman, uint32_t* ad, uint32_t ad_Length, uint32_t ad_Value_length, uint32_t ad_Value_value_length, Ref_Manager* ad_Refman, uint32_t** oas, Ref_Manager** oas_Refman, uint32_t** oams, uint32_t* oams_Value_length, Ref_Manager** oams_Refman, uint32_t** oamd, uint32_t* oamd_Length, uint32_t* oamd_Value_value_length, Ref_Manager** oamd_Refman, uint32_t** oar, uint8_t* oar_Length, uint8_t* oar_Value_length, uint8_t* oar_Value_value_length, Ref_Manager** oar_Refman, uint32_t** oad, uint32_t* oad_Length, uint32_t* oad_Value_length, uint32_t* oad_Value_value_length, Ref_Manager** oad_Refman);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->ad_Refman);
    LUMI_dec_ref(self->ar_Refman);
    LUMI_dec_ref(self->amd_Refman);
    LUMI_dec_ref(self->ams_Refman);
    LUMI_dec_ref(self->as_Refman);
}
Return_Code ut_M_fun(uint32_t* as, Ref_Manager* as_Refman, uint32_t* ams, uint32_t ams_Value_length, Ref_Manager* ams_Refman, uint32_t* amd, uint32_t amd_Length, uint32_t amd_Value_value_length, Ref_Manager* amd_Refman, uint32_t* ar, uint8_t ar_Length, uint8_t ar_Value_length, uint8_t ar_Value_value_length, Ref_Manager* ar_Refman, uint32_t* ad, uint32_t ad_Length, uint32_t ad_Value_length, uint32_t ad_Value_value_length, Ref_Manager* ad_Refman, uint32_t** oas, Ref_Manager** oas_Refman, uint32_t** oams, uint32_t* oams_Value_length, Ref_Manager** oams_Refman, uint32_t** oamd, uint32_t* oamd_Length, uint32_t* oamd_Value_value_length, Ref_Manager** oamd_Refman, uint32_t** oar, uint8_t* oar_Length, uint8_t* oar_Value_length, uint8_t* oar_Value_value_length, Ref_Manager** oar_Refman, uint32_t** oad, uint32_t* oad_Length, uint32_t* oad_Value_length, uint32_t* oad_Value_value_length, Ref_Manager** oad_Refman) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    uint32_t* aux_Array_0 = NULL;
    Ref_Manager* aux_Array_0_Refman = NULL;
    uint32_t* aux_Array_1 = NULL;
    uint32_t aux_Array_1_Value_length = 0;
    Ref_Manager* aux_Array_1_Refman = NULL;
    uint32_t* aux_Array_2 = NULL;
    uint32_t aux_Array_2_Length = 0;
    uint32_t aux_Array_2_Value_value_length = 0;
    Ref_Manager* aux_Array_2_Refman = NULL;
    uint32_t* aux_Array_3 = NULL;
    uint8_t aux_Array_3_Length = 0;
    uint8_t aux_Array_3_Value_length = 0;
    uint8_t aux_Array_3_Value_value_length = 0;
    Ref_Manager* aux_Array_3_Refman = NULL;
    uint32_t* aux_Array_4 = NULL;
    uint32_t aux_Array_4_Length = 0;
    uint32_t aux_Array_4_Value_length = 0;
    uint32_t aux_Array_4_Value_value_length = 0;
    Ref_Manager* aux_Array_4_Refman = NULL;
    uint32_t* aux_Array_5 = NULL;
    Ref_Manager* aux_Array_5_Refman = NULL;
    uint32_t* aux_Array_6 = NULL;
    uint32_t aux_Array_6_Value_length = 0;
    Ref_Manager* aux_Array_6_Refman = NULL;
    uint32_t* aux_Array_7 = NULL;
    uint32_t aux_Array_7_Length = 0;
    uint32_t aux_Array_7_Value_value_length = 0;
    Ref_Manager* aux_Array_7_Refman = NULL;
    uint32_t* aux_Array_8 = NULL;
    uint8_t aux_Array_8_Length = 0;
    uint8_t aux_Array_8_Value_length = 0;
    uint8_t aux_Array_8_Value_value_length = 0;
    Ref_Manager* aux_Array_8_Refman = NULL;
    uint32_t* aux_Array_9 = NULL;
    uint32_t aux_Array_9_Length = 0;
    uint32_t aux_Array_9_Value_length = 0;
    uint32_t aux_Array_9_Value_value_length = 0;
    Ref_Manager* aux_Array_9_Refman = NULL;
    uint32_t* aux_Array_10 = NULL;
    Ref_Manager* aux_Array_10_Refman = NULL;
    uint32_t* aux_Array_11 = NULL;
    uint32_t aux_Array_11_Value_length = 0;
    Ref_Manager* aux_Array_11_Refman = NULL;
    uint32_t* aux_Array_12 = NULL;
    uint32_t aux_Array_12_Length = 0;
    uint32_t aux_Array_12_Value_value_length = 0;
    Ref_Manager* aux_Array_12_Refman = NULL;
    uint32_t* aux_Array_13 = NULL;
    uint8_t aux_Array_13_Length = 0;
    uint8_t aux_Array_13_Value_length = 0;
    uint8_t aux_Array_13_Value_value_length = 0;
    Ref_Manager* aux_Array_13_Refman = NULL;
    uint32_t* aux_Array_14 = NULL;
    uint32_t aux_Array_14_Length = 0;
    uint32_t aux_Array_14_Value_length = 0;
    uint32_t aux_Array_14_Value_value_length = 0;
    Ref_Manager* aux_Array_14_Refman = NULL;
    uint32_t* aux_Array_15 = NULL;
    Ref_Manager* aux_Array_15_Refman = NULL;
    uint32_t* aux_Array_16 = NULL;
    uint32_t aux_Array_16_Value_length = 0;
    Ref_Manager* aux_Array_16_Refman = NULL;
    uint32_t* aux_Array_17 = NULL;
    uint32_t aux_Array_17_Length = 0;
    uint32_t aux_Array_17_Value_value_length = 0;
    Ref_Manager* aux_Array_17_Refman = NULL;
    uint32_t* aux_Array_18 = NULL;
    uint8_t aux_Array_18_Length = 0;
    uint8_t aux_Array_18_Value_length = 0;
    uint8_t aux_Array_18_Value_value_length = 0;
    Ref_Manager* aux_Array_18_Refman = NULL;
    uint32_t* aux_Array_19 = NULL;
    uint32_t aux_Array_19_Length = 0;
    uint32_t aux_Array_19_Value_length = 0;
    uint32_t aux_Array_19_Value_value_length = 0;
    Ref_Manager* aux_Array_19_Refman = NULL;
    LUMI_inc_ref(as_Refman);
    LUMI_inc_ref(ams_Refman);
    LUMI_inc_ref(amd_Refman);
    LUMI_inc_ref(ar_Refman);
    LUMI_inc_ref(ad_Refman);
    LUMI_inc_ref(as_Refman);
    LUMI_dec_ref(*oas_Refman);
    *oas_Refman = as_Refman;
    *oas = as;
    if (ams_Value_length != 0x07) RAISE(21, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(ams_Refman);
    LUMI_dec_ref(*oas_Refman);
    *oas_Refman = ams_Refman;
    *oas = ams;
    if (amd_Length < 0x04 || amd_Value_value_length != 0x08) RAISE(22, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(amd_Refman);
    LUMI_dec_ref(*oas_Refman);
    *oas_Refman = amd_Refman;
    *oas = amd;
    if (ar_Length < 0x04 || ar_Value_length != 0x07 || ar_Value_value_length != 0x08) RAISE(23, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(ar_Refman);
    LUMI_dec_ref(*oas_Refman);
    *oas_Refman = ar_Refman;
    *oas = ar;
    if (ad_Length < 0x04 || ad_Value_length != 0x07 || ad_Value_value_length != 0x08) RAISE(24, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(ad_Refman);
    LUMI_dec_ref(*oas_Refman);
    *oas_Refman = ad_Refman;
    *oas = ad;
    LUMI_inc_ref(as_Refman);
    LUMI_dec_ref(*oams_Refman);
    *oams_Refman = as_Refman;
    *oams_Value_length = 0x07;
    *oams = as;
    LUMI_inc_ref(ams_Refman);
    LUMI_dec_ref(*oams_Refman);
    *oams_Refman = ams_Refman;
    *oams_Value_length = ams_Value_length;
    *oams = ams;
    if (amd_Length < 0x04 || amd_Value_value_length != 0x08) RAISE(27, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(amd_Refman);
    LUMI_dec_ref(*oams_Refman);
    *oams_Refman = amd_Refman;
    *oams_Value_length = 0x07;
    *oams = amd;
    if (ad_Length < 0x04 || ad_Value_value_length != 0x08) RAISE(28, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(ad_Refman);
    LUMI_dec_ref(*oams_Refman);
    *oams_Refman = ad_Refman;
    *oams_Value_length = ad_Value_length;
    *oams = ad;
    if (ar_Length < 0x04 || ar_Value_value_length != 0x08) RAISE(29, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(ar_Refman);
    LUMI_dec_ref(*oams_Refman);
    *oams_Refman = ar_Refman;
    *oams_Value_length = ar_Value_length;
    *oams = ar;
    LUMI_inc_ref(as_Refman);
    LUMI_dec_ref(*oamd_Refman);
    *oamd_Refman = as_Refman;
    *oamd_Length = 0x06;
    *oamd_Value_value_length = 0x08;
    *oamd = as;
    if (ams_Value_length != 0x07) RAISE(31, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(ams_Refman);
    LUMI_dec_ref(*oamd_Refman);
    *oamd_Refman = ams_Refman;
    *oamd_Length = 0x06;
    *oamd_Value_value_length = 0x08;
    *oamd = ams;
    LUMI_inc_ref(amd_Refman);
    LUMI_dec_ref(*oamd_Refman);
    *oamd_Refman = amd_Refman;
    *oamd_Length = amd_Length;
    *oamd_Value_value_length = amd_Value_value_length;
    *oamd = amd;
    if (ar_Value_length != 0x07) RAISE(33, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(ar_Refman);
    LUMI_dec_ref(*oamd_Refman);
    *oamd_Refman = ar_Refman;
    *oamd_Length = ar_Length;
    *oamd_Value_value_length = ar_Value_value_length;
    *oamd = ar;
    if (ad_Value_length != 0x07) RAISE(34, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(ad_Refman);
    LUMI_dec_ref(*oamd_Refman);
    *oamd_Refman = ad_Refman;
    *oamd_Length = ad_Length;
    *oamd_Value_value_length = ad_Value_value_length;
    *oamd = ad;
    LUMI_inc_ref(as_Refman);
    LUMI_dec_ref(*oar_Refman);
    *oar_Refman = as_Refman;
    *oar_Length = 0x06;
    *oar_Value_length = 0x07;
    *oar_Value_value_length = 0x08;
    *oar = as;
    if (ams_Value_length < 0x04 || ams_Value_length > 0x0a) RAISE(36, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(ams_Refman);
    LUMI_dec_ref(*oar_Refman);
    *oar_Refman = ams_Refman;
    *oar_Length = 0x06;
    *oar_Value_length = ams_Value_length;
    *oar_Value_value_length = 0x08;
    *oar = ams;
    if (amd_Length < 0x03 || amd_Length > 0x09 || amd_Value_value_length < 0x05 || amd_Value_value_length > 0x0b) RAISE(37, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(amd_Refman);
    LUMI_dec_ref(*oar_Refman);
    *oar_Refman = amd_Refman;
    *oar_Length = amd_Length;
    *oar_Value_length = 0x07;
    *oar_Value_value_length = amd_Value_value_length;
    *oar = amd;
    LUMI_inc_ref(ar_Refman);
    LUMI_dec_ref(*oar_Refman);
    *oar_Refman = ar_Refman;
    *oar_Length = ar_Length;
    *oar_Value_length = ar_Value_length;
    *oar_Value_value_length = ar_Value_value_length;
    *oar = ar;
    if (ad_Length < 0x03 || ad_Length > 0x09 || ad_Value_length < 0x04 || ad_Value_length > 0x0a || ad_Value_value_length < 0x05 || ad_Value_value_length > 0x0b) RAISE(39, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(ad_Refman);
    LUMI_dec_ref(*oar_Refman);
    *oar_Refman = ad_Refman;
    *oar_Length = ad_Length;
    *oar_Value_length = ad_Value_length;
    *oar_Value_value_length = ad_Value_value_length;
    *oar = ad;
    LUMI_inc_ref(as_Refman);
    LUMI_dec_ref(*oad_Refman);
    *oad_Refman = as_Refman;
    *oad_Length = 0x06;
    *oad_Value_length = 0x07;
    *oad_Value_value_length = 0x08;
    *oad = as;
    LUMI_inc_ref(ams_Refman);
    LUMI_dec_ref(*oad_Refman);
    *oad_Refman = ams_Refman;
    *oad_Length = 0x06;
    *oad_Value_length = ams_Value_length;
    *oad_Value_value_length = 0x08;
    *oad = ams;
    LUMI_inc_ref(amd_Refman);
    LUMI_dec_ref(*oad_Refman);
    *oad_Refman = amd_Refman;
    *oad_Length = amd_Length;
    *oad_Value_length = 0x07;
    *oad_Value_value_length = amd_Value_value_length;
    *oad = amd;
    LUMI_inc_ref(ar_Refman);
    LUMI_dec_ref(*oad_Refman);
    *oad_Refman = ar_Refman;
    *oad_Length = ar_Length;
    *oad_Value_length = ar_Value_length;
    *oad_Value_value_length = ar_Value_value_length;
    *oad = ar;
    LUMI_inc_ref(ad_Refman);
    LUMI_dec_ref(*oad_Refman);
    *oad_Refman = ad_Refman;
    *oad_Length = ad_Length;
    *oad_Value_length = ad_Value_length;
    *oad_Value_value_length = ad_Value_value_length;
    *oad = ad;
    LUMI_err = ut_M_fun(as, as_Refman, as, 0x07, as_Refman, as, 0x06, 0x08, as_Refman, as, 0x06, 0x07, 0x08, as_Refman, as, 0x06, 0x07, 0x08, as_Refman, &(*oas), &(*oas_Refman), &(*oams), &(*oams_Value_length), &(*oams_Refman), &(*oamd), &(*oamd_Length), &(*oamd_Value_value_length), &(*oamd_Refman), &(*oar), &(*oar_Length), &(*oar_Value_length), &(*oar_Value_value_length), &(*oar_Refman), &(*oad), &(*oad_Length), &(*oad_Value_length), &(*oad_Value_value_length), &(*oad_Refman));
    CHECK(46, LUMI_block0_cleanup)
    if (ams_Value_length != 0x07) RAISE(48, LUMI_block0_cleanup, slice_index)
    if (ams_Value_length != 0x07) RAISE(48, LUMI_block0_cleanup, slice_index)
    if (ams_Value_length < 0x04 || ams_Value_length > 0x0a) RAISE(48, LUMI_block0_cleanup, slice_index)
    LUMI_err = ut_M_fun(ams, ams_Refman, ams, ams_Value_length, ams_Refman, ams, 0x06, 0x08, ams_Refman, ams, 0x06, ams_Value_length, 0x08, ams_Refman, ams, 0x06, ams_Value_length, 0x08, ams_Refman, &(aux_Array_0), &(aux_Array_0_Refman), &(aux_Array_1), &(aux_Array_1_Value_length), &(aux_Array_1_Refman), &(aux_Array_2), &(aux_Array_2_Length), &(aux_Array_2_Value_value_length), &(aux_Array_2_Refman), &(aux_Array_3), &(aux_Array_3_Length), &(aux_Array_3_Value_length), &(aux_Array_3_Value_value_length), &(aux_Array_3_Refman), &(aux_Array_4), &(aux_Array_4_Length), &(aux_Array_4_Value_length), &(aux_Array_4_Value_value_length), &(aux_Array_4_Refman));
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_dec_ref(*oad_Refman);
    *oad_Refman = aux_Array_0_Refman;
    *oad_Length = 0x04;
    *oad_Value_length = 0x07;
    *oad_Value_value_length = 0x08;
    *oad = aux_Array_0;
    if (aux_Array_1_Value_length != 0x07) RAISE(48, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aux_Array_1_Refman);
    LUMI_dec_ref(*oas_Refman);
    *oas_Refman = aux_Array_1_Refman;
    *oas = aux_Array_1;
    if (aux_Array_2_Length < 0x04 || aux_Array_2_Value_value_length != 0x08) RAISE(48, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aux_Array_2_Refman);
    LUMI_dec_ref(*oams_Refman);
    *oams_Refman = aux_Array_2_Refman;
    *oams_Value_length = 0x07;
    *oams = aux_Array_2;
    if (aux_Array_3_Value_length != 0x07) RAISE(48, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aux_Array_3_Refman);
    LUMI_dec_ref(*oamd_Refman);
    *oamd_Refman = aux_Array_3_Refman;
    *oamd_Length = aux_Array_3_Length;
    *oamd_Value_value_length = aux_Array_3_Value_value_length;
    *oamd = aux_Array_3;
    if (aux_Array_4_Length < 0x03 || aux_Array_4_Length > 0x09 || aux_Array_4_Value_length < 0x04 || aux_Array_4_Value_length > 0x0a || aux_Array_4_Value_value_length < 0x05 || aux_Array_4_Value_value_length > 0x0b) RAISE(48, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aux_Array_4_Refman);
    LUMI_dec_ref(*oar_Refman);
    *oar_Refman = aux_Array_4_Refman;
    *oar_Length = aux_Array_4_Length;
    *oar_Value_length = aux_Array_4_Value_length;
    *oar_Value_value_length = aux_Array_4_Value_value_length;
    *oar = aux_Array_4;
    CHECK(48, LUMI_block0_cleanup)
    if (amd_Length < 0x06 || amd_Value_value_length != 0x08) RAISE(50, LUMI_block0_cleanup, slice_index)
    if (amd_Length < 0x06 || amd_Value_value_length != 0x08) RAISE(50, LUMI_block0_cleanup, slice_index)
    if (amd_Length < 0x03 || amd_Length > 0x09 || amd_Value_value_length < 0x05 || amd_Value_value_length > 0x0b) RAISE(50, LUMI_block0_cleanup, slice_index)
    LUMI_err = ut_M_fun(amd, amd_Refman, amd, 0x07, amd_Refman, amd, amd_Length, amd_Value_value_length, amd_Refman, amd, amd_Length, 0x07, amd_Value_value_length, amd_Refman, amd, amd_Length, 0x07, amd_Value_value_length, amd_Refman, &(aux_Array_5), &(aux_Array_5_Refman), &(aux_Array_6), &(aux_Array_6_Value_length), &(aux_Array_6_Refman), &(aux_Array_7), &(aux_Array_7_Length), &(aux_Array_7_Value_value_length), &(aux_Array_7_Refman), &(aux_Array_8), &(aux_Array_8_Length), &(aux_Array_8_Value_length), &(aux_Array_8_Value_value_length), &(aux_Array_8_Refman), &(aux_Array_9), &(aux_Array_9_Length), &(aux_Array_9_Value_length), &(aux_Array_9_Value_value_length), &(aux_Array_9_Refman));
    LUMI_inc_ref(aux_Array_5_Refman);
    LUMI_dec_ref(*oar_Refman);
    *oar_Refman = aux_Array_5_Refman;
    *oar_Length = 0x04;
    *oar_Value_length = 0x07;
    *oar_Value_value_length = 0x08;
    *oar = aux_Array_5;
    LUMI_inc_ref(aux_Array_6_Refman);
    LUMI_dec_ref(*oad_Refman);
    *oad_Refman = aux_Array_6_Refman;
    *oad_Length = 0x04;
    *oad_Value_length = aux_Array_6_Value_length;
    *oad_Value_value_length = 0x08;
    *oad = aux_Array_6;
    if (aux_Array_7_Length < 0x04 || aux_Array_7_Value_value_length != 0x08) RAISE(50, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aux_Array_7_Refman);
    LUMI_dec_ref(*oas_Refman);
    *oas_Refman = aux_Array_7_Refman;
    *oas = aux_Array_7;
    if (aux_Array_8_Length < 0x04 || aux_Array_8_Value_value_length != 0x08) RAISE(50, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aux_Array_8_Refman);
    LUMI_dec_ref(*oams_Refman);
    *oams_Refman = aux_Array_8_Refman;
    *oams_Value_length = aux_Array_8_Value_length;
    *oams = aux_Array_8;
    if (aux_Array_9_Value_length != 0x07) RAISE(50, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aux_Array_9_Refman);
    LUMI_dec_ref(*oamd_Refman);
    *oamd_Refman = aux_Array_9_Refman;
    *oamd_Length = aux_Array_9_Length;
    *oamd_Value_value_length = aux_Array_9_Value_value_length;
    *oamd = aux_Array_9;
    CHECK(50, LUMI_block0_cleanup)
    if (ar_Length < 0x06 || ar_Value_length != 0x07 || ar_Value_value_length != 0x08) RAISE(52, LUMI_block0_cleanup, slice_index)
    if (ar_Length < 0x06 || ar_Value_value_length != 0x08) RAISE(52, LUMI_block0_cleanup, slice_index)
    if (ar_Value_length != 0x07) RAISE(52, LUMI_block0_cleanup, slice_index)
    LUMI_err = ut_M_fun(ar, ar_Refman, ar, ar_Value_length, ar_Refman, ar, ar_Length, ar_Value_value_length, ar_Refman, ar, ar_Length, ar_Value_length, ar_Value_value_length, ar_Refman, ar, ar_Length, ar_Value_length, ar_Value_value_length, ar_Refman, &(aux_Array_10), &(aux_Array_10_Refman), &(aux_Array_11), &(aux_Array_11_Value_length), &(aux_Array_11_Refman), &(aux_Array_12), &(aux_Array_12_Length), &(aux_Array_12_Value_value_length), &(aux_Array_12_Refman), &(aux_Array_13), &(aux_Array_13_Length), &(aux_Array_13_Value_length), &(aux_Array_13_Value_value_length), &(aux_Array_13_Refman), &(aux_Array_14), &(aux_Array_14_Length), &(aux_Array_14_Value_length), &(aux_Array_14_Value_value_length), &(aux_Array_14_Refman));
    LUMI_inc_ref(aux_Array_10_Refman);
    LUMI_dec_ref(*oamd_Refman);
    *oamd_Refman = aux_Array_10_Refman;
    *oamd_Length = 0x04;
    *oamd_Value_value_length = 0x08;
    *oamd = aux_Array_10;
    if (aux_Array_11_Value_length < 0x04 || aux_Array_11_Value_length > 0x0a) RAISE(52, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aux_Array_11_Refman);
    LUMI_dec_ref(*oar_Refman);
    *oar_Refman = aux_Array_11_Refman;
    *oar_Length = 0x04;
    *oar_Value_length = aux_Array_11_Value_length;
    *oar_Value_value_length = 0x08;
    *oar = aux_Array_11;
    LUMI_inc_ref(aux_Array_12_Refman);
    LUMI_dec_ref(*oad_Refman);
    *oad_Refman = aux_Array_12_Refman;
    *oad_Length = aux_Array_12_Length;
    *oad_Value_length = 0x07;
    *oad_Value_value_length = aux_Array_12_Value_value_length;
    *oad = aux_Array_12;
    if (aux_Array_13_Length < 0x04 || aux_Array_13_Value_length != 0x07 || aux_Array_13_Value_value_length != 0x08) RAISE(52, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aux_Array_13_Refman);
    LUMI_dec_ref(*oas_Refman);
    *oas_Refman = aux_Array_13_Refman;
    *oas = aux_Array_13;
    if (aux_Array_14_Length < 0x04 || aux_Array_14_Value_value_length != 0x08) RAISE(52, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aux_Array_14_Refman);
    LUMI_dec_ref(*oams_Refman);
    *oams_Refman = aux_Array_14_Refman;
    *oams_Value_length = aux_Array_14_Value_length;
    *oams = aux_Array_14;
    CHECK(52, LUMI_block0_cleanup)
    if (ad_Length < 0x06 || ad_Value_length != 0x07 || ad_Value_value_length != 0x08) RAISE(54, LUMI_block0_cleanup, slice_index)
    if (ad_Length < 0x06 || ad_Value_value_length != 0x08) RAISE(54, LUMI_block0_cleanup, slice_index)
    if (ad_Value_length != 0x07) RAISE(54, LUMI_block0_cleanup, slice_index)
    if (ad_Length < 0x03 || ad_Length > 0x09 || ad_Value_length < 0x04 || ad_Value_length > 0x0a || ad_Value_value_length < 0x05 || ad_Value_value_length > 0x0b) RAISE(54, LUMI_block0_cleanup, slice_index)
    LUMI_err = ut_M_fun(ad, ad_Refman, ad, ad_Value_length, ad_Refman, ad, ad_Length, ad_Value_value_length, ad_Refman, ad, ad_Length, ad_Value_length, ad_Value_value_length, ad_Refman, ad, ad_Length, ad_Value_length, ad_Value_value_length, ad_Refman, &(aux_Array_15), &(aux_Array_15_Refman), &(aux_Array_16), &(aux_Array_16_Value_length), &(aux_Array_16_Refman), &(aux_Array_17), &(aux_Array_17_Length), &(aux_Array_17_Value_value_length), &(aux_Array_17_Refman), &(aux_Array_18), &(aux_Array_18_Length), &(aux_Array_18_Value_length), &(aux_Array_18_Value_value_length), &(aux_Array_18_Refman), &(aux_Array_19), &(aux_Array_19_Length), &(aux_Array_19_Value_length), &(aux_Array_19_Value_value_length), &(aux_Array_19_Refman));
    LUMI_inc_ref(aux_Array_15_Refman);
    LUMI_dec_ref(*oams_Refman);
    *oams_Refman = aux_Array_15_Refman;
    *oams_Value_length = 0x07;
    *oams = aux_Array_15;
    if (aux_Array_16_Value_length != 0x07) RAISE(54, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aux_Array_16_Refman);
    LUMI_dec_ref(*oamd_Refman);
    *oamd_Refman = aux_Array_16_Refman;
    *oamd_Length = 0x04;
    *oamd_Value_value_length = 0x08;
    *oamd = aux_Array_16;
    if (aux_Array_17_Length < 0x03 || aux_Array_17_Length > 0x09 || aux_Array_17_Value_value_length < 0x05 || aux_Array_17_Value_value_length > 0x0b) RAISE(54, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aux_Array_17_Refman);
    LUMI_dec_ref(*oar_Refman);
    *oar_Refman = aux_Array_17_Refman;
    *oar_Length = aux_Array_17_Length;
    *oar_Value_length = 0x07;
    *oar_Value_value_length = aux_Array_17_Value_value_length;
    *oar = aux_Array_17;
    LUMI_inc_ref(aux_Array_18_Refman);
    LUMI_dec_ref(*oad_Refman);
    *oad_Refman = aux_Array_18_Refman;
    *oad_Length = aux_Array_18_Length;
    *oad_Value_length = aux_Array_18_Value_length;
    *oad_Value_value_length = aux_Array_18_Value_value_length;
    *oad = aux_Array_18;
    if (aux_Array_19_Length < 0x04 || aux_Array_19_Value_length != 0x07 || aux_Array_19_Value_value_length != 0x08) RAISE(54, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aux_Array_19_Refman);
    LUMI_dec_ref(*oas_Refman);
    *oas_Refman = aux_Array_19_Refman;
    *oas = aux_Array_19;
    CHECK(54, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(aux_Array_19_Refman);
    LUMI_dec_ref(aux_Array_18_Refman);
    LUMI_dec_ref(aux_Array_17_Refman);
    LUMI_dec_ref(aux_Array_16_Refman);
    LUMI_dec_ref(aux_Array_15_Refman);
    LUMI_dec_ref(aux_Array_14_Refman);
    LUMI_dec_ref(aux_Array_13_Refman);
    LUMI_dec_ref(aux_Array_12_Refman);
    LUMI_dec_ref(aux_Array_11_Refman);
    LUMI_dec_ref(aux_Array_10_Refman);
    LUMI_dec_ref(aux_Array_9_Refman);
    LUMI_dec_ref(aux_Array_8_Refman);
    LUMI_dec_ref(aux_Array_7_Refman);
    LUMI_dec_ref(aux_Array_6_Refman);
    LUMI_dec_ref(aux_Array_5_Refman);
    LUMI_dec_ref(aux_Array_4_Refman);
    LUMI_dec_ref(aux_Array_3_Refman);
    LUMI_dec_ref(aux_Array_2_Refman);
    LUMI_dec_ref(aux_Array_1_Refman);
    LUMI_dec_ref(aux_Array_0_Refman);
    LUMI_dec_ref(ad_Refman);
    LUMI_dec_ref(ar_Refman);
    LUMI_dec_ref(amd_Refman);
    LUMI_dec_ref(ams_Refman);
    LUMI_dec_ref(as_Refman);
    return LUMI_err;
}
/// @ test-slice-expression-24
Byte* abi = NULL;
    uint32_t abi_Length = 0;
    Byte* ab6 = NULL;
    Byte* ab6o = NULL;
    Byte* uab = NULL;
    uint32_t uab_Length = 0;
    Byte* aux_Array_0 = NULL;
    if (ut_M_i <= 0) RAISE(1, LUMI_block0_cleanup, array_too_short)
    INIT_NEW_LEN_ARRAY(1, LUMI_block0_cleanup, abi, Byte, ut_M_i, 1);
    INIT_NEW_ARRAY(2, LUMI_block0_cleanup, ab6, Byte, 0x06, 1);
    INIT_NEW_ARRAY(3, LUMI_block0_cleanup, aux_Array_0, Byte, 0x06, 1);
    ab6o = aux_Array_0;
    aux_Array_0 = NULL;
    uab_Length = abi_Length;
    uab = abi;
    uab_Length = 0x06;
    uab = ab6;
    uab_Length = 0x06;
    uab = ab6o;
/// @ test-slice-expression-25
Byte* a3_8 = NULL;
    uint8_t a3_8_Length = 0;
    Byte* a6 = NULL;
    Byte* ad = NULL;
    uint32_t ad_Length = 0;
    Byte* as = NULL;
    uint32_t as_Length = 0;
    a3_8_Length = 0;
    a3_8 = NULL;
    a3_8_Length = 0x06;
    a3_8 = a6;
    if (ad_Length < 0x03 || ad_Length > 0x08) RAISE(5, LUMI_block0_cleanup, slice_index)
    a3_8_Length = ad_Length;
    a3_8 = ad;
    if (a3_8_Length < 0x06) RAISE(6, LUMI_block0_cleanup, slice_index)
    a6 = a3_8;
    ad_Length = a3_8_Length;
    ad = a3_8;
    if (ut_M_j <= 0) RAISE(8, LUMI_block0_cleanup, array_too_short)
    INIT_NEW_LEN_ARRAY(8, LUMI_block0_cleanup, as, Byte, ut_M_j, 1);
/// @ test-slice-expression-e0
expected "]", got "new-line"
/// @ test-slice-expression-e1
expected "]", got "new-line"
/// @ test-slice-expression-e2
cannot slice type "Void Expression"
/// @ test-slice-expression-e3
cannot slice type "Int"
/// @ test-slice-expression-e4
expected integer index for slice, got "String"
/// @ test-slice-expression-e5
expected integer index for slice, got "String"
/// @ test-slice-expression-e6
expected integer index for slice, got "Void Expression"
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
slice index always negative with maximum value of "-1"
/// @ test-slice-expression-e16
slice index always negative with maximum value of "-2"
/// @ test-slice-expression-e17
slice length never positive with maximum value of "0"
/// @ test-slice-expression-e18
slice length never positive with maximum value of "0"
/// @ test-slice-expression-e19
slice minimal length "4" is larger than sequence maximal size "3"
/// @ test-slice-expression-e20
slice minimal length "16" is larger than sequence maximal size "10"
/// @ test-slice-expression-e21
cannot assign array owner of length "6" into array owner of different length "4"
/// @ test-slice-expression-e22
cannot assign array of length "4" into array of larger length "6"
/// @ test-slice-expression-e23
non matching sub-array length "6" and "4"
/// @ test-slice-expression-e24
ignoring array length check
/// @ test-slice-expression-e25
negative array length minimum "-127"
/// @ test-slice-expression-e26
expected integer as array length, got "String"
/// @ test-slice-expression-e27
assigning integer with maximum of "200" into integer with smaller maximum of "20"
/// @ test-slice-expression-e28
ignoring array length check
/// @@ test-call-expression
/// @ test-call-expression-0
ut_M_fun0();
/// @ test-call-expression-1
ut_M_fun1(0x03, ut_M_ostr, NULL);
/// @ test-call-expression-2
ut_M_fun2(&(*so), &(*so_Refman), &(*io));
/// @ test-call-expression-3
uint32_t x = 0;
    String* s = NULL;
    Ref_Manager* s_Refman = NULL;
    ut_M_fun2(&(s), &(s_Refman), &(x));
/// @ test-call-expression-4
ut_M_fun3(0, &(*so), &(*so_Refman));
/// @ test-call-expression-5
uint32_t x = 0;
    ut_M_fun5(0x03, &(x));
    ut_M_fun4(x);
/// @ test-call-expression-6
ut_M_fun6(0x02, 0x03, &(ut_M_i), &(*io));
/// @ test-call-expression-7
uint32_t aux_Int_0 = 0;
    ut_M_fun5(0x04, &(aux_Int_0));
/// @ test-call-expression-8
uint32_t aux_Int_0 = 0;
    ut_M_fun5(0x04, &(aux_Int_0));
    *io = aux_Int_0;
/// @ test-call-expression-9
String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    ut_M_fun3(0x07, &(aux_String_0), &(aux_String_0_Refman));
    String_Del(*so, NULL);
    LUMI_owner_dec_ref(*so_Refman);
    *so_Refman = aux_String_0_Refman;
    *so = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Refman = NULL;
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
    ut_M_fun1(0x03, ut_M_ostr, *so);
    *so = NULL;
    *so_Refman = NULL;
/// @ test-call-expression-18
String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    uint32_t aux_Int_0 = 0;
    ut_M_fun3(0x01, &(aux_String_0), &(aux_String_0_Refman));
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
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del,
    ut_M_Base_meth
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        (Dynamic_Del)ut_M_Test_Del,
        (Return_Code (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, ut_M_Base* b, ut_M_Base_Dynamic* b_Dynamic))ut_M_Test_meth
    }
};
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
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del,
    ut_M_Test_meth
};
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
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del,
    ut_M_Test_meth
};
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
void ut_M_fun(String** astr, uint32_t* astr_Length);
void ut_M_fun(String** astr, uint32_t* astr_Length) {
    unsigned LUMI_loop_depth = 1;
    ut_M_fun(&(*astr), &(*astr_Length));
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-call-expression-23
Return_Code ut_M_fun(String* s);
Return_Code ut_M_fun(String* s) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    String vars_Var = {0};
    String* vars = NULL;
    String s_vars_Var = {0};
    String* s_vars = NULL;
    Ref_Manager* s_vars_Refman = NULL;
    String* owners = NULL;
    String* strongs = NULL;
    Ref_Manager* strongs_Refman = NULL;
    String* users = NULL;
    String* aux_String_0 = NULL;
    String* aux_String_1 = NULL;
    vars = &vars_Var;
    s_vars = &s_vars_Var;
    INIT_VAR_REFMAN(3, LUMI_block0_cleanup, s_vars)
    INIT_NEW(4, LUMI_block0_cleanup, aux_String_0, String, 1);
    owners = aux_String_0;
    aux_String_0 = NULL;
    INIT_NEW(5, LUMI_block0_cleanup, aux_String_1, String, 1);
    strongs = aux_String_1;
    aux_String_1 = NULL;
    INIT_NEW_REFMAN(5, LUMI_block0_cleanup, strongs)
    users = s;
    LUMI_err = ut_M_fun(s);
    CHECK(7, LUMI_block0_cleanup)
    LUMI_err = ut_M_fun(vars);
    CHECK(8, LUMI_block0_cleanup)
    LUMI_err = ut_M_fun(s_vars);
    CHECK(9, LUMI_block0_cleanup)
    LUMI_err = ut_M_fun(owners);
    CHECK(10, LUMI_block0_cleanup)
    LUMI_err = ut_M_fun(strongs);
    CHECK(11, LUMI_block0_cleanup)
    String_clear(s);
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_1, NULL);
    free(aux_String_1);
    String_Del(aux_String_0, NULL);
    free(aux_String_0);
    String_Del(strongs, NULL);
    LUMI_owner_dec_ref(strongs_Refman);
    String_Del(owners, NULL);
    free(owners);
    String_Del(s_vars, NULL);
    LUMI_var_dec_ref(s_vars_Refman);
    String_Del(vars, NULL);
    return LUMI_err;
}
/// @ test-call-expression-24
String* s = NULL;
    Ref_Manager* s_Refman = NULL;
    String* sw = NULL;
    Ref_Manager* sw_Refman = NULL;
    CHECK_REFMAN(3, LUMI_block0_cleanup, sw_Refman)
    LUMI_var_dec_ref(s_Refman);
    ut_M_fun1(0, sw, s);
    s = NULL;
    s_Refman = NULL;
/// @ test-call-expression-25
String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    aux_String_0 = ut_M_ostr;
    ut_M_ostr = NULL;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, aux_String_0)
    ut_M_fun8(aux_String_0, aux_String_0_Refman);
    aux_String_0 = NULL;
    aux_String_0_Refman = NULL;
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
    u8 = aux_Int_0;
    ut_M_fun5(0x01, &(aux_Int_1));
    s8 = (aux_Int_1 > 0x7f)? 0x7f: aux_Int_1;
    ut_M_fun5(0x32, &(u32));
    ut_M_fun5(0x02, &(aux_Int_2));
    s32 = (aux_Int_2 > INT32_MAX)? INT32_MAX: aux_Int_2;
    ut_M_fun5(0x03, &(aux_Int_3));
    u64 = aux_Int_3;
    ut_M_fun5(0x04, &(aux_Int_4));
    s64 = aux_Int_4;
/// @ test-call-expression-28
Return_Code ut_M_get(String** res, Ref_Manager** res_Refman);
Return_Code ut_M_get(String** res, Ref_Manager** res_Refman) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    String* s = NULL;
    Ref_Manager* s_Refman = NULL;
    LUMI_err = ut_M_get(&(s), &(s_Refman));
    CHECK(3, LUMI_block0_cleanup)
    CHECK_REFMAN(4, LUMI_block0_cleanup, s_Refman)
    String_clear(s);
    LUMI_inc_ref(s_Refman);
    LUMI_dec_ref(*res_Refman);
    *res_Refman = s_Refman;
    *res = s;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(s_Refman);
    return LUMI_err;
}
/// @ test-call-expression-29
ut_M_Tb* aux_Tb_0 = NULL;
    Ref_Manager* aux_Tb_0_Refman = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = NULL;
    ut_M_fun7(ut_M_tb, ut_M_tb_Refman, ut_M_tb_Dynamic, &(aux_Tb_0), &(aux_Tb_0_Refman), &(aux_Tb_0_Dynamic));
    LUMI_inc_ref(aux_Tb_0_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = aux_Tb_0_Refman;
    ut_M_t = &(aux_Tb_0->_base._base);
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
non callable type "Void Expression"
/// @ test-call-expression-e6
non callable type "Int"
/// @ test-call-expression-e7
non assignable call output
/// @ test-call-expression-e8
cannot assign "Tb" into "Tc"
/// @ test-call-expression-e9
cannot assign "Void Expression" into "Int"
/// @ test-call-expression-e10
expected access "copy" , got "user"
/// @ test-call-expression-e11
assigning into an owner a non-owner access "user"
/// @ test-call-expression-e12
assigning into an owner a non-owner access "user"
/// @ test-call-expression-e13
assigning into an owner a non-owner access "weak"
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
ignoring empty reference check
/// @ test-call-expression-e24
using invalid reference "s"
/// @ test-call-expression-e25
adding "->()" without outputs
/// @ test-call-expression-e26
using modified reference "io"
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
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Mid_Dynamic ut_M_Mid_Dynamic;
typedef struct ut_M_Top ut_M_Top;
typedef struct ut_M_Top_Dynamic ut_M_Top_Dynamic;
struct ut_M_Base {
    uint32_t x;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Mid {
    ut_M_Base _base;
};
struct ut_M_Mid_Dynamic {
    ut_M_Base_Dynamic _base;
};
struct ut_M_Top {
    ut_M_Mid _base;
};
struct ut_M_Top_Dynamic {
    ut_M_Mid_Dynamic _base;
};
void ut_M_Base_methb(ut_M_Base* self);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Mid_methm(ut_M_Mid* self);
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Top_methb(ut_M_Top* self);
void ut_M_Top_methm(ut_M_Top* self);
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del
};
ut_M_Mid_Dynamic ut_M_Mid_dynamic = {
    {
        (Dynamic_Del)ut_M_Mid_Del
    }
};
ut_M_Top_Dynamic ut_M_Top_dynamic = {
    {
        {
            (Dynamic_Del)ut_M_Top_Del
        }
    }
};
void ut_M_Base_methb(ut_M_Base* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Mid_methm(ut_M_Mid* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
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
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base), NULL);
}
/// @ test-base-expression-1
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Mid_Dynamic ut_M_Mid_Dynamic;
typedef struct ut_M_Top ut_M_Top;
typedef struct ut_M_Top_Dynamic ut_M_Top_Dynamic;
struct ut_M_Base {
    uint32_t x;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Mid {
    ut_M_Base _base;
};
struct ut_M_Mid_Dynamic {
    ut_M_Base_Dynamic _base;
};
struct ut_M_Top {
    ut_M_Mid _base;
};
struct ut_M_Top_Dynamic {
    ut_M_Mid_Dynamic _base;
};
void ut_M_Base_methb(ut_M_Base* self);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Mid_methm(ut_M_Mid* self);
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Top_methb(ut_M_Top* self);
void ut_M_Top_methm(ut_M_Top* self);
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del
};
ut_M_Mid_Dynamic ut_M_Mid_dynamic = {
    {
        (Dynamic_Del)ut_M_Mid_Del
    }
};
ut_M_Top_Dynamic ut_M_Top_dynamic = {
    {
        {
            (Dynamic_Del)ut_M_Top_Del
        }
    }
};
void ut_M_Base_methb(ut_M_Base* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Mid_methm(ut_M_Mid* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
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
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base), NULL);
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
ut_M_i = (0x7b * ((uint64_t)ut_M_i - 0x04)) + 0x02;
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
ut_M_i = (((uint64_t)ut_M_i + 0x01) > UINT32_MAX)? UINT32_MAX: ((uint64_t)ut_M_i + 0x01);
/// @ test-unary-expression-6
ut_M_j = ((ut_M_j - 0x01) < -INT32_MAX)? -INT32_MAX: (ut_M_j - 0x01);
/// @ test-unary-expression-7
int8_t x = 0;
    x = (ut_M_j < -0x7f)? -0x7f: ((ut_M_j > 0x7f)? 0x7f: ut_M_j);
    x = (ut_M_j < -0x7f)? -0x7f: ((ut_M_j > 0x7f)? 0x7f: ut_M_j);
/// @ test-unary-expression-8
if (((uint64_t)ut_M_i + 0x01) > UINT32_MAX) RAISE(1, LUMI_block0_cleanup, integer_overflow)
    ut_M_i = (uint64_t)ut_M_i + 0x01;
/// @ test-unary-expression-9
if ((ut_M_j - 0x01) < -INT32_MAX) RAISE(1, LUMI_block0_cleanup, integer_overflow)
    ut_M_j = ut_M_j - 0x01;
/// @ test-unary-expression-10
if (((int64_t)ut_M_j * 0x02) < -INT32_MAX || ((int64_t)ut_M_j * 0x02) > INT32_MAX) RAISE(1, LUMI_block0_cleanup, integer_overflow)
    ut_M_j = (int64_t)ut_M_j * 0x02;
/// @ test-unary-expression-11
++LUMI_trace_ignore_count;
    if (((uint64_t)ut_M_i + 0x01) > UINT32_MAX) RAISE(1, LUMI_block2_cleanup, integer_overflow)
    ut_M_i = (uint64_t)ut_M_i + 0x01;
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
    ut_M_fun4((((uint64_t)ut_M_i + 0x01) > UINT32_MAX)? UINT32_MAX: ((uint64_t)ut_M_i + 0x01));
    INIT_NEW(2, LUMI_block0_cleanup, ttb, ut_M_Tb, 1);
    LUMI_err = ut_M_Tb_new(ttb, ttb_Dynamic, (((uint64_t)ut_M_i + 0x01) > UINT32_MAX)? UINT32_MAX: ((uint64_t)ut_M_i + 0x01));
    CHECK(2, LUMI_block0_cleanup)
    INIT_NEW(3, LUMI_block0_cleanup, aux_Tb_0, ut_M_Tb, 1);
    LUMI_err = ut_M_Tb_new(aux_Tb_0, aux_Tb_0_Dynamic, (((uint64_t)ut_M_i + 0x01) > UINT32_MAX)? UINT32_MAX: ((uint64_t)ut_M_i + 0x01));
    CHECK(3, LUMI_block0_cleanup)
    if (ttb_Dynamic != NULL) ttb_Dynamic->_base._base._del(ttb, ttb_Dynamic);
    free(ttb);
    ttb_Dynamic = aux_Tb_0_Dynamic;
    ttb = aux_Tb_0;
    aux_Tb_0 = NULL;
    aux_Tb_0_Dynamic = NULL;
/// @ test-unary-expression-13
if (((uint64_t)ut_M_i + 0x01) > UINT32_MAX) RAISE(1, LUMI_block0_cleanup, integer_overflow)
    ut_M_fun4((uint64_t)ut_M_i + 0x01);
/// @ test-unary-expression-14
++LUMI_trace_ignore_count;
    if (((uint64_t)ut_M_i + 0x01) > UINT32_MAX) RAISE(1, LUMI_block2_cleanup, integer_overflow)
    ut_M_fun4((uint64_t)ut_M_i + 0x01);
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
/// @ test-unary-expression-15
ut_M_i = (uint64_t)ut_M_i + 0x01;
/// @ test-unary-expression-16
ut_M_Tb* ttb = NULL;
    ut_M_Tb_Dynamic* ttb_Dynamic = &ut_M_Tb_dynamic;
    ut_M_Tb* aux_Tb_0 = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = &ut_M_Tb_dynamic;
    ut_M_fun4((uint64_t)ut_M_i + 0x01);
    INIT_NEW(2, LUMI_block0_cleanup, ttb, ut_M_Tb, 1);
    LUMI_err = ut_M_Tb_new(ttb, ttb_Dynamic, (uint64_t)ut_M_i + 0x01);
    CHECK(2, LUMI_block0_cleanup)
    INIT_NEW(3, LUMI_block0_cleanup, aux_Tb_0, ut_M_Tb, 1);
    LUMI_err = ut_M_Tb_new(aux_Tb_0, aux_Tb_0_Dynamic, (uint64_t)ut_M_i + 0x01);
    CHECK(3, LUMI_block0_cleanup)
    if (ttb_Dynamic != NULL) ttb_Dynamic->_base._base._del(ttb, ttb_Dynamic);
    free(ttb);
    ttb_Dynamic = aux_Tb_0_Dynamic;
    ttb = aux_Tb_0;
    aux_Tb_0 = NULL;
    aux_Tb_0_Dynamic = NULL;
/// @ test-unary-expression-e0
expected expression, got "{"
/// @ test-unary-expression-e1
expected space after "-", got "["
/// @ test-unary-expression-e2
used non-unary operator "+"
/// @ test-unary-expression-e3
operator "-" expected "Int" operand, got "Void Expression"
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
/// @ test-unary-expression-e15
misplaced use of "wraparound"
/// @ test-unary-expression-e16
unnecessary use of "wraparound"
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
ut_M_b = ((0x02 < ut_M_i) && (ut_M_i < 0x0c)) && (0x0c == ((int64_t)-0x02 * ut_M_i));
/// @ test-binary-expression-7
LUMI_inc_ref(ut_M_tc_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = ut_M_tc_Refman;
    ut_M_t = &(ut_M_tc->_base._base._base);
/// @ test-binary-expression-8
String* s = NULL;
    String_Del(s, NULL);
    free(s);
    LUMI_var_dec_ref(*so_Refman);
    s = *so;
    *so = NULL;
    *so_Refman = NULL;
/// @ test-binary-expression-9
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
    if (ut_M_tb_Dynamic != NULL) ut_M_tb_Dynamic->_base._base._del(ut_M_tb, ut_M_tb_Dynamic);
    LUMI_owner_dec_ref(ut_M_tb_Refman);
    ut_M_tb_Dynamic = &(otc_Dynamic->_base);
    ut_M_tb = &(otc->_base);
    otc = NULL;
    otc_Dynamic = NULL;
    INIT_NEW_REFMAN(2, LUMI_block0_cleanup, ut_M_tb)
/// @ test-binary-expression-15
ut_M_Test* otarr = NULL;
    uint32_t otarr_Length = 0;
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
    ut_M_i = (uint32_t)((uint32_t)(((uint32_t)(~ ut_M_i)) + ((uint8_t)(~ i8))) + ((uint64_t)(~ i64)));
/// @ test-binary-expression-20
ut_M_i = ut_M_i ^ 0x10;
/// @ test-binary-expression-21
ut_M_i = 0x02 >> ut_M_i;
/// @ test-binary-expression-22
ut_M_i = ut_M_i << 0x01;
/// @ test-binary-expression-23
ut_M_i = (uint64_t)((uint32_t)(~ ut_M_i)) + (0x0a & ut_M_i);
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
/// @ test-binary-expression-28
ut_M_b = (((ut_M_i >= ut_M_i) || ((int64_t)ut_M_i < (int64_t)ut_M_j)) || ((int32_t)ut_M_j > (int32_t)ut_M_j)) || ((int32_t)ut_M_bt <= (int32_t)ut_M_j);
/// @ test-binary-expression-29
uint8_t x = 0;
    uint16_t y = 0;
    uint64_t z = 0;
    x = 0x32;
    ut_M_i = (uint8_t)(x + 0x03e8);
    ut_M_i = (uint16_t)(y - 0x07d0);
    z = (uint64_t)(z * 0x02);
    z = (uint64_t)((uint64_t)(z + ut_M_j) + ((uint8_t)(x - z)));
/// @ test-binary-expression-30
ut_M_i += ut_M_i;
    ut_M_i -= ut_M_i;
    ut_M_i *= ut_M_i;
/// @ test-binary-expression-31
int64_t x = 0;
    uint64_t y = 0;
    if (CHECK_MIN_ADD(x, ut_M_j) || CHECK_MAX_ADD(x, ut_M_j, INT64_MAX)) RAISE(3, LUMI_block0_cleanup, integer_overflow)
    ut_M_i = x + ut_M_j;
    if (CHECK_MIN_SUB(x, ut_M_j) || CHECK_MAX_SUB(x, ut_M_j, INT64_MAX)) RAISE(4, LUMI_block0_cleanup, integer_overflow)
    ut_M_i = x - ut_M_j;
    if (CHECK_MIN_MUL(x, ut_M_j) || CHECK_MAX_MUL(x, ut_M_j, INT64_MAX)) RAISE(5, LUMI_block0_cleanup, integer_overflow)
    ut_M_i = x * ut_M_j;
    if (CHECK_MAX_ADD(y, 0x03, UINT64_MAX)) RAISE(6, LUMI_block0_cleanup, integer_overflow)
    y = y + 0x03;
    if (CHECK_MIN_SUB(x, 0x03)) RAISE(7, LUMI_block0_cleanup, integer_overflow)
    ut_M_i = x - 0x03;
    ++LUMI_trace_ignore_count;
    if (CHECK_MAX_ADD(x, 0x03, INT64_MAX)) RAISE(8, LUMI_block2_cleanup, integer_overflow)
    x = x + 0x03;
LUMI_block2_cleanup:
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        x = 0;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
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
non matching array subtypes "Int" and "Char"
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
unsigned operation on signed integer with minimum value of "-10"
/// @ test-binary-expression-e27
unsigned operation on signed integer with minimum value of "-10"
/// @ test-binary-expression-e28
unsigned operation on signed integer with minimum value of "-10"
/// @ test-binary-expression-e29
unsigned operation on signed integer with minimum value of "-10"
/// @ test-binary-expression-e30
unsigned operation on signed integer with minimum value of "-10"
/// @ test-binary-expression-e31
unsigned operation on signed integer with minimum value of "-10"
/// @ test-binary-expression-e32
unsigned operation on signed integer with minimum value of "-10"
/// @ test-binary-expression-e33
unsigned operation on signed integer with minimum value of "-10"
/// @ test-binary-expression-e34
too high signed integer maximum "18446744073709551615"
/// @ test-binary-expression-e35
unnecessary wraparound with "+"
/// @ test-binary-expression-e36
unnecessary wraparound with "-"
/// @ test-binary-expression-e37
unnecessary wraparound with "*"
/// @ test-binary-expression-e38
assigning integer with minimum of "0" into integer with larger minimum of "1"
/// @ test-binary-expression-e39
assigning integer with maximum of "255" into integer with smaller maximum of "254"
/// @ test-binary-expression-e40
using "?" where error is propagated
/// @ test-binary-expression-e41
using "!" where error is not propagated
/// @ test-binary-expression-e42
error raised inside function not declared as error raising "error"
/// @ test-binary-expression-e43
using "!" where there is no error
/// @ test-binary-expression-e44
using "?" where there is no error
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
    uint32_t a1_Length = 0;
    uint32_t* a2 = NULL;
    uint32_t a2_Length = 0;
    uint32_t* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    if (ut_M_i <= 0) RAISE(1, LUMI_block0_cleanup, array_too_short)
    INIT_NEW_LEN_ARRAY(1, LUMI_block0_cleanup, a1, uint32_t, ut_M_i, 1);
    if (ut_M_i <= 0) RAISE(2, LUMI_block0_cleanup, array_too_short)
    INIT_NEW_LEN_ARRAY(2, LUMI_block0_cleanup, a2, uint32_t, ut_M_i, 1);
    aux_Array_0_Length = a1_Length;
    aux_Array_0 = a1;
    a1_Length = a2_Length;
    a1 = a2;
    a2_Length = aux_Array_0_Length;
    a2 = aux_Array_0;
    aux_Array_0 = NULL;
/// @ test-swap-expression-5
uint32_t* a1 = NULL;
    uint32_t a1_Length = 0;
    Ref_Manager* a1_Refman = NULL;
    uint32_t* a2 = NULL;
    uint32_t a2_Length = 0;
    Ref_Manager* a2_Refman = NULL;
    uint32_t* aux_Array_0 = NULL;
    uint32_t* aux_Array_1 = NULL;
    uint32_t* aux_Array_2 = NULL;
    uint32_t aux_Array_2_Length = 0;
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
String* s1 = NULL;
    String* s2 = NULL;
    String* aux_String_0 = NULL;
    INIT_NEW(1, LUMI_block0_cleanup, s1, String, 1);
    INIT_NEW(2, LUMI_block0_cleanup, s2, String, 1);
    aux_String_0 = s1;
    s1 = s2;
    s2 = aux_String_0;
    aux_String_0 = NULL;
/// @ test-swap-expression-7
String* s1 = NULL;
    Ref_Manager* s1_Refman = NULL;
    String* s2 = NULL;
    Ref_Manager* s2_Refman = NULL;
    String* aux_String_0 = NULL;
    String* aux_String_1 = NULL;
    String* aux_String_2 = NULL;
    Ref_Manager* aux_String_2_Refman = NULL;
    INIT_NEW(1, LUMI_block0_cleanup, aux_String_0, String, 1);
    s1 = aux_String_0;
    aux_String_0 = NULL;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, s1)
    INIT_NEW(2, LUMI_block0_cleanup, aux_String_1, String, 1);
    s2 = aux_String_1;
    aux_String_1 = NULL;
    INIT_NEW_REFMAN(2, LUMI_block0_cleanup, s2)
    aux_String_2_Refman = s1_Refman;
    aux_String_2 = s1;
    s1_Refman = s2_Refman;
    s1 = s2;
    s2_Refman = aux_String_2_Refman;
    s2 = aux_String_2;
    aux_String_2 = NULL;
    aux_String_2_Refman = NULL;
/// @ test-swap-expression-8
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_MyStruct_Dynamic ut_M_MyStruct_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_MyStruct_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test {
    ut_M_MyStruct* f;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic);
void ut_M_Test_new(ut_M_Test* self, ut_M_MyStruct* f);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_fun(ut_M_Test* t1, ut_M_Test* t2);
ut_M_MyStruct_Dynamic ut_M_MyStruct_dynamic = {
    (Dynamic_Del)ut_M_MyStruct_Del
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Test_new(ut_M_Test* self, ut_M_MyStruct* f) {
    unsigned LUMI_loop_depth = 1;
    ut_M_MyStruct_Del(self->f, NULL);
    free(self->f);
    self->f = f;
    f = NULL;
LUMI_block0_cleanup:
    (void)0;
    ut_M_MyStruct_Del(f, NULL);
    free(f);
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_MyStruct_Del(self->f, NULL);
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
    ut_M_MyStruct_Del(aux_MyStruct_0, NULL);
    free(aux_MyStruct_0);
    ut_M_Test_Del(t2, NULL);
    free(t2);
    ut_M_Test_Del(t1, NULL);
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
    ut_M_d->item_Dynamic = (Generic_Type_Dynamic*)&ut_M_Test_dynamic;
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
/// @ test-swap-expression-e8
non matching integer range minimum "0" and "-2147483647"
/// @ test-swap-expression-e9
non matching integer range maximum "4294967295" and "255"
/// @ test-swap-expression-e10
non matching length dynamic
/// @ test-swap-expression-e11
non matching length "6" and "8"
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
ut_M_Tb* aux_Tb_0 = NULL;
    Ref_Manager* aux_Tb_0_Refman = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = NULL;
    ut_M_fun7(NULL, NULL, NULL, &(aux_Tb_0), &(aux_Tb_0_Refman), &(aux_Tb_0_Dynamic));
    LUMI_inc_ref(aux_Tb_0_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = aux_Tb_0_Refman;
    ut_M_t = &(aux_Tb_0->_base._base);
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    String* s;
    Ref_Manager* s_Refman;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_meth(ut_M_Test* self, Bool* res);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_meth(ut_M_Test* self, Bool* res) {
    unsigned LUMI_loop_depth = 1;
    *res = self->s != NULL && (self->s_Refman)->value != NULL;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->s_Refman);
}
/// @ test-question-expression-e0
cannot use "?" on non conditional or weak reference of type "Void Expression"
/// @ test-question-expression-e1
cannot use "?" on non conditional or weak reference of type "Int"
/// @ test-question-expression-e2
cannot use "?" on non conditional or weak reference of type "Test"
/// @ test-question-expression-e3
cannot use "?" on primitive type "Int"
/// @@ test-exclamation-expression
/// @ test-exclamation-expression-0
String* s = NULL;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    s = ut_M_ostr;
/// @ test-exclamation-expression-1
ut_M_Test* tt = NULL;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t, ut_M_t_Refman)
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_t->t, ut_M_t->t_Refman)
    tt = ut_M_t->t;
/// @ test-exclamation-expression-2
ut_M_Test* tu = NULL;
    ut_M_Tb* aux_Tb_0 = NULL;
    Ref_Manager* aux_Tb_0_Refman = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = NULL;
    ut_M_fun7(NULL, NULL, NULL, &(aux_Tb_0), &(aux_Tb_0_Refman), &(aux_Tb_0_Dynamic));
    LUMI_inc_ref(aux_Tb_0_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = aux_Tb_0_Refman;
    ut_M_t = &(aux_Tb_0->_base._base);
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
Byte* s = NULL;
    uint32_t s_Length = 0;
    uint32_t aux_Int_0 = 0;
    CHECK_REF(1, LUMI_block0_cleanup, str)
    String_length(str, &(aux_Int_0));
    if (aux_Int_0 <= 0) RAISE(1, LUMI_block0_cleanup, array_too_short)
    INIT_NEW_LEN_ARRAY(1, LUMI_block0_cleanup, s, Byte, aux_Int_0, 1);
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
/// @ test-exclamation-expression-en34
using "!" where there is no error
/// @@ test-int-range
/// @ test-int-range-0
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
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
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_new(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
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
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
enum {
    ut_M_Nums_MIN = 0,
    ut_M_Nums_length
};
enum { ut_M_MAX = 0x2710 };
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_fun(ut_M_Test* t, uint32_t* x);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
int16_t ut_M_s16 = 0;
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_fun(ut_M_Test* t, uint32_t* x) {
    unsigned LUMI_loop_depth = 1;
    uint32_t aux_Int_0 = 0;
    ut_M_fun(t, &(aux_Int_0));
    *x = (uint64_t)aux_Int_0 + t->x;
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
/// @ test-int-range-4
void ut_M_fun(void);
void ut_M_get(uint8_t* x);
void ut_M_set(uint8_t x);
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    uint32_t x = 0;
    uint8_t aux_Int_0 = 0;
    uint8_t aux_Int_1 = 0;
    ut_M_set(0x0c);
    ut_M_get(&(aux_Int_0));
    ut_M_get(&(aux_Int_1));
    x = aux_Int_1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_get(uint8_t* x) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_set(uint8_t x) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-int-range-e0
integer range minimum "12" larger than maximum "11"
/// @ test-int-range-e1
too high unsigned integer maximum "18446744073709551616"
/// @ test-int-range-e2
too high signed integer maximum "9223372036854775808"
/// @ test-int-range-e3
too low signed integer minimum "-9223372036854775809"
/// @ test-int-range-e4
got "String" expression, expected "Int"
/// @ test-int-range-e5
integer range is not constant
/// @ test-int-range-e6
integer range minimum "0" larger than maximum "-100"
/// @ test-int-range-e7
assigning integer with minimum of "-2147483647" into integer with larger minimum of "0"
/// @ test-int-range-e8
assigning integer with maximum of "4294967295" into integer with smaller maximum of "2147483647"
/// @ test-int-range-e9
too high unsigned integer maximum "18446744073709551616"
/// @@ test-dynamic-call
/// @ test-dynamic-call-0
ut_M_Ta a_Var = {{0}};
    ut_M_Ta* a = NULL;
    ut_M_Ta_Dynamic* a_Dynamic = &ut_M_Ta_dynamic;
    a = &a_Var;
/// @ test-dynamic-call-1
ut_M_Ta* a = NULL;
    ut_M_Ta_Dynamic* a_Dynamic = NULL;
/// @ test-dynamic-call-2
ut_M_Ta* nta = NULL;
    ut_M_Ta_Dynamic* nta_Dynamic = NULL;
    ut_M_Ta* aux_Ta_0 = NULL;
    ut_M_Ta_Dynamic* aux_Ta_0_Dynamic = &ut_M_Ta_dynamic;
    INIT_NEW(1, LUMI_block0_cleanup, aux_Ta_0, ut_M_Ta, 1);
    nta_Dynamic = aux_Ta_0_Dynamic;
    nta = aux_Ta_0;
    aux_Ta_0 = NULL;
    aux_Ta_0_Dynamic = NULL;
/// @ test-dynamic-call-3
ut_M_Ta* a = NULL;
    ut_M_Ta_Dynamic* a_Dynamic = &ut_M_Ta_dynamic;
    INIT_NEW(1, LUMI_block0_cleanup, a, ut_M_Ta, 1);
/// @ test-dynamic-call-4
ut_M_Ta* a = NULL;
    ut_M_Ta_Dynamic* a_Dynamic = NULL;
    CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_ta_Refman)
    a_Dynamic = ut_M_ta_Dynamic;
    a = ut_M_ta;
/// @ test-dynamic-call-5
ut_M_Ta* x = NULL;
    ut_M_Ta_Dynamic* x_Dynamic = NULL;
    CHECK_REFMAN(2, LUMI_block0_cleanup, ut_M_ta_Refman)
    x_Dynamic = ut_M_ta_Dynamic;
    x = ut_M_ta;
/// @ test-dynamic-call-6
LUMI_inc_ref(ut_M_tb_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = ut_M_tb_Refman;
    ut_M_ta_Dynamic = &(ut_M_tb_Dynamic->_base);
    ut_M_ta = &(ut_M_tb->_base);
/// @ test-dynamic-call-7
LUMI_inc_ref(ut_M_tc_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = ut_M_tc_Refman;
    ut_M_ta_Dynamic = &(ut_M_tc_Dynamic->_base._base);
    ut_M_ta = &(ut_M_tc->_base._base);
/// @ test-dynamic-call-8
LUMI_inc_ref(NULL);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = NULL;
    ut_M_ta_Dynamic = NULL;
    ut_M_ta = NULL;
/// @ test-dynamic-call-9
ut_M_Ta* aa = NULL;
    uint32_t aa_Length = 0;
    Ref_Manager* aa_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, aa)
    if (0x04 >= aa_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(aa_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = aa_Refman;
    ut_M_ta_Dynamic = &ut_M_Ta_dynamic;
    ut_M_ta = aa + 0x04;
/// @ test-dynamic-call-10
ut_M_Tc* ca = NULL;
    uint32_t ca_Length = 0;
    Ref_Manager* ca_Refman = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, ca)
    if (0x04 >= ca_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    LUMI_inc_ref(ca_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = ca_Refman;
    ut_M_ta_Dynamic = &(&ut_M_Tc_dynamic->_base._base);
    ut_M_ta = &((ca + 0x04)->_base._base);
/// @ test-dynamic-call-11
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_ta_Refman)
    if (ut_M_ta_Dynamic == NULL) RAISE(1, LUMI_block0_cleanup, empty_object)
    ut_M_ta_Dynamic->dyn(ut_M_ta, ut_M_ta_Dynamic);
/// @ test-dynamic-call-12
if (ut_M_tb_Dynamic == NULL) RAISE(1, LUMI_block0_cleanup, empty_object)
    ut_M_tb_Dynamic->_base.dyn(&(ut_M_tb->_base), &(ut_M_tb_Dynamic->_base));
/// @ test-dynamic-call-13
CHECK_REFMAN(1, LUMI_block0_cleanup, ut_M_tc_Refman)
    if (ut_M_tc_Dynamic == NULL) RAISE(1, LUMI_block0_cleanup, empty_object)
    ut_M_tc_Dynamic->_base._base.dyn(&(ut_M_tc->_base._base), &(ut_M_tc_Dynamic->_base._base));
/// @ test-dynamic-call-14
LUMI_inc_ref(ut_M_tc_Refman);
    LUMI_dec_ref(*tco_Refman);
    *tco_Refman = ut_M_tc_Refman;
    *tco_Dynamic = ut_M_tc_Dynamic;
    *tco = ut_M_tc;
    CHECK_REFMAN(2, LUMI_block0_cleanup, *tco_Refman)
    if (*tco_Dynamic == NULL) RAISE(2, LUMI_block0_cleanup, empty_object)
    (*tco_Dynamic)->_base._base.dyn(&((*tco)->_base._base), &((*tco_Dynamic)->_base._base));
/// @ test-dynamic-call-15
ut_M_Tb* aux_Tb_0 = NULL;
    Ref_Manager* aux_Tb_0_Refman = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = NULL;
    ut_M_fun7(&(ut_M_tc->_base), ut_M_tc_Refman, &(ut_M_tc_Dynamic->_base), &(aux_Tb_0), &(aux_Tb_0_Refman), &(aux_Tb_0_Dynamic));
    LUMI_inc_ref(aux_Tb_0_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = aux_Tb_0_Refman;
    ut_M_ta_Dynamic = &(aux_Tb_0_Dynamic->_base);
    ut_M_ta = &(aux_Tb_0->_base);
/// @ test-dynamic-call-16
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
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del,
    ut_M_Test_meth
};
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
/// @ test-dynamic-call-17
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
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del,
    ut_M_Base_meth
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        (Dynamic_Del)ut_M_Test_Del,
        ut_M_Base_meth
    }
};
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
/// @ test-dynamic-call-18
ut_M_Tb* aux_Tb_0 = NULL;
    Ref_Manager* aux_Tb_0_Refman = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = NULL;
    ut_M_fun7(NULL, NULL, NULL, &(aux_Tb_0), &(aux_Tb_0_Refman), &(aux_Tb_0_Dynamic));
/// @ test-dynamic-call-e0
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
    Return_Code (**farr2)(void) = NULL;
    Return_Code (**ufarr)(void) = NULL;
    uint32_t ufarr_Length = 0;
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    void (*fun)(uint32_t x, uint32_t y);
    Return_Code (*afun[0x04])(uint32_t x, uint32_t* y);
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_meth(ut_M_Test* self, Return_Code (*fi)(uint32_t x, uint32_t y), Return_Code (**fo)(uint32_t x, uint32_t y));
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
Return_Code ut_M_fun(uint32_t x, uint32_t y);
void ut_M_mock(void (*fi)(uint32_t x, uint32_t y), Return_Code (**fo)(uint32_t x, uint32_t y));
void ut_M_afun(void (** in)(uint32_t x, uint32_t* y), uint32_t in_Length, Return_Code (*** out)(void), uint32_t* out_Length);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_meth(ut_M_Test* self, Return_Code (*fi)(uint32_t x, uint32_t y), Return_Code (**fo)(uint32_t x, uint32_t y)) {
    unsigned LUMI_loop_depth = 1;
    *fo = ut_M_fun;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
void ut_M_afun(void (** in)(uint32_t x, uint32_t* y), uint32_t in_Length, Return_Code (*** out)(void), uint32_t* out_Length) {
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
    LUMI_err = Int_strU(u64, ut_M_ostr);
    CHECK(3, LUMI_block0_cleanup)
    CHECK_REF(4, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = Int_strS(s64, ut_M_ostr);
    CHECK(4, LUMI_block0_cleanup)
/// @ test-builtin-bool0
ut_M_b = true;
/// @ test-builtin-bool1
ut_M_b = false;
/// @ test-builtin-char0
unknown symbol "EOF"
/// @ test-builtin-array0
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    ut_M_i = ut_M_arr_Length;
/// @ test-builtin-array1
Bool a[0x0c] = {0};
    Bool* ua = NULL;
    /* initializing a */
    ua = a;
    ut_M_i = 0x0c + 0x0c;
/// @ test-builtin-string0
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_length(ut_M_ostr, &(ut_M_i));
/// @ test-builtin-string1
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_clear(ut_M_ostr);
/// @ test-builtin-string2
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    String_equal(ut_M_ostr, ut_M_buff, ut_M_buff_Length, &(ut_M_b));
/// @ test-builtin-string3
Byte* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_bytes(ut_M_ostr, &(aux_Array_0), &(aux_Array_0_Length));
    bfr_Length = aux_Array_0_Length;
    bfr = aux_Array_0;
/// @ test-builtin-string4
Byte* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    Byte* aux_Array_1 = NULL;
    uint32_t aux_Array_1_Length = 0;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_bytes(ut_M_ostr, &(aux_Array_0), &(aux_Array_0_Length));
    bfr_Length = aux_Array_0_Length;
    bfr = aux_Array_0;
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_ostr)
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_ostr)
    String_bytes(ut_M_ostr, &(aux_Array_1), &(aux_Array_1_Length));
    String_equal(ut_M_ostr, aux_Array_1, aux_Array_1_Length, &(ut_M_b));
/// @ test-builtin-string5
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_append(ut_M_ostr, ut_M_c);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-string6
String sv_Var = {0};
    String* sv = NULL;
    sv = &sv_Var;
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_buff)
    LUMI_err = String_new(sv, ut_M_buff, ut_M_buff_Length);
    CHECK(2, LUMI_block0_cleanup)
/// @ test-builtin-string7
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    LUMI_err = String_concat(ut_M_ostr, ut_M_buff, ut_M_buff_Length);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-string8
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = String_concat_int(ut_M_ostr, ut_M_i);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-string10
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_has(ut_M_ostr, ut_M_c, &(ut_M_b));
/// @ test-builtin-string-e0
using potentially illegal user reference "bfr"
/// @ test-builtin-string-e1
using potentially illegal user reference "bfr"
/// @ test-builtin-string-e2
using potentially illegal user reference "bfr"
/// @ test-builtin-string-e3
using potentially illegal user reference "bfr"
/// @ test-builtin-string-e4
using potentially illegal user reference "bfr"
/// @ test-builtin-buffer0
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    ut_M_i = ut_M_buff_Length;
/// @ test-builtin-file0
{
        FileReadText f_Var = {0};
        FileReadText* f = NULL;
        Ref_Manager* f_Refman = NULL;
        int64_t x = 0;
        ut_M_Data df_Var = {0};
        ut_M_Data* df = NULL;
        Byte* aux_Array_0 = NULL;
        uint32_t aux_Array_0_Length = 0;
        ++LUMI_trace_ignore_count;
        CHECK_REF(2, LUMI_block1_cleanup, ut_M_ostr)
        f = &f_Var;
        INIT_VAR_REFMAN(2, LUMI_block1_cleanup, f)
        LUMI_err = FileReadText_new(f, ut_M_ostr);
        CHECK(2, LUMI_block1_cleanup)
        LUMI_err = FileReadText_get(f, &(ut_M_bt), &(ut_M_b));
        CHECK(3, LUMI_block1_cleanup)
        CHECK_REF(4, LUMI_block1_cleanup, ut_M_buff)
        LUMI_err = FileReadText_getline(f, ut_M_buff, ut_M_buff_Length, &(aux_Array_0), &(aux_Array_0_Length), &(ut_M_b));
        bfr_Length = aux_Array_0_Length;
        bfr = aux_Array_0;
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
        df->item_Dynamic = (Generic_Type_Dynamic*)&FileReadText_dynamic;
        df->item = f;
    LUMI_block1_cleanup:
        (void)0;
        ut_M_Data_Del(df, NULL);
        FileReadText_Del(f, NULL);
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
        int64_t x = 0;
        ut_M_Data df_Var = {0};
        ut_M_Data* df = NULL;
        ++LUMI_trace_ignore_count;
        CHECK_REF(2, LUMI_block1_cleanup, ut_M_ostr)
        INIT_NEW(2, LUMI_block1_cleanup, f, FileReadBinary, 1);
        LUMI_err = FileReadBinary_new(f, ut_M_ostr);
        CHECK(2, LUMI_block1_cleanup)
        LUMI_err = FileReadBinary_get(f, &(ut_M_bt), &(ut_M_b));
        CHECK(3, LUMI_block1_cleanup)
        CHECK_REF(4, LUMI_block1_cleanup, ut_M_buff)
        LUMI_err = FileReadBinary_read(f, ut_M_buff, ut_M_buff_Length, &(ut_M_i));
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
        ut_M_Data_set(df, f, (Generic_Type_Dynamic*)&FileReadBinary_dynamic);
        f = NULL;
    LUMI_block1_cleanup:
        (void)0;
        ut_M_Data_Del(df, NULL);
        FileReadBinary_Del(f, NULL);
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
        int64_t x = 0;
        ut_M_Data df_Var = {0};
        ut_M_Data* df = NULL;
        FileWriteText* aux_FileWriteText_0 = NULL;
        ++LUMI_trace_ignore_count;
        CHECK_REF(2, LUMI_block1_cleanup, ut_M_ostr)
        INIT_NEW(2, LUMI_block1_cleanup, aux_FileWriteText_0, FileWriteText, 1);
        LUMI_err = FileWriteText_new(aux_FileWriteText_0, ut_M_ostr, false);
        CHECK(2, LUMI_block1_cleanup)
        f = aux_FileWriteText_0;
        aux_FileWriteText_0 = NULL;
        LUMI_err = FileWriteText_put(f, ut_M_bt);
        CHECK(3, LUMI_block1_cleanup)
        CHECK_REF(4, LUMI_block1_cleanup, ut_M_buff)
        LUMI_err = FileWriteText_write(f, ut_M_buff, ut_M_buff_Length, &(ut_M_i));
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
        ut_M_Data_set(df, f, (Generic_Type_Dynamic*)&FileWriteText_dynamic);
        f = NULL;
    LUMI_block1_cleanup:
        (void)0;
        FileWriteText_Del(aux_FileWriteText_0, NULL);
        free(aux_FileWriteText_0);
        ut_M_Data_Del(df, NULL);
        FileWriteText_Del(f, NULL);
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
        int64_t x = 0;
        ut_M_Data df_Var = {0};
        ut_M_Data* df = NULL;
        FileWriteBinary* aux_FileWriteBinary_0 = NULL;
        ++LUMI_trace_ignore_count;
        CHECK_REF(2, LUMI_block1_cleanup, ut_M_ostr)
        INIT_NEW(2, LUMI_block1_cleanup, aux_FileWriteBinary_0, FileWriteBinary, 1);
        LUMI_err = FileWriteBinary_new(aux_FileWriteBinary_0, ut_M_ostr, true);
        CHECK(2, LUMI_block1_cleanup)
        f = aux_FileWriteBinary_0;
        aux_FileWriteBinary_0 = NULL;
        INIT_NEW_REFMAN(2, LUMI_block1_cleanup, f)
        LUMI_err = FileWriteBinary_put(f, ut_M_bt);
        CHECK(3, LUMI_block1_cleanup)
        CHECK_REF(4, LUMI_block1_cleanup, ut_M_buff)
        LUMI_err = FileWriteBinary_write(f, ut_M_buff, ut_M_buff_Length, &(ut_M_i));
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
        df->item_Dynamic = (Generic_Type_Dynamic*)&FileWriteBinary_dynamic;
        df->item = f;
    LUMI_block1_cleanup:
        (void)0;
        FileWriteBinary_Del(aux_FileWriteBinary_0, NULL);
        free(aux_FileWriteBinary_0);
        ut_M_Data_Del(df, NULL);
        FileWriteBinary_Del(f, NULL);
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
        int64_t x = 0;
        ut_M_Data df_Var = {0};
        ut_M_Data* df = NULL;
        Byte* aux_Array_0 = NULL;
        uint32_t aux_Array_0_Length = 0;
        ++LUMI_trace_ignore_count;
        CHECK_REF(2, LUMI_block1_cleanup, ut_M_ostr)
        f = &f_Var;
        INIT_VAR_REFMAN(2, LUMI_block1_cleanup, f)
        LUMI_err = FileReadWriteText_new(f, ut_M_ostr, true, true);
        CHECK(2, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteText_get(f, &(ut_M_bt), &(ut_M_b));
        CHECK(3, LUMI_block1_cleanup)
        CHECK_REF(4, LUMI_block1_cleanup, ut_M_buff)
        LUMI_err = FileReadWriteText_getline(f, ut_M_buff, ut_M_buff_Length, &(aux_Array_0), &(aux_Array_0_Length), &(ut_M_b));
        bfr_Length = aux_Array_0_Length;
        bfr = aux_Array_0;
        CHECK(4, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteText_put(f, ut_M_bt);
        CHECK(5, LUMI_block1_cleanup)
        CHECK_REF(6, LUMI_block1_cleanup, ut_M_buff)
        LUMI_err = FileReadWriteText_write(f, ut_M_buff, ut_M_buff_Length, &(ut_M_i));
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
        df->item_Dynamic = (Generic_Type_Dynamic*)&FileReadWriteText_dynamic;
        df->item = f;
    LUMI_block1_cleanup:
        (void)0;
        ut_M_Data_Del(df, NULL);
        FileReadWriteText_Del(f, NULL);
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
        int64_t x = 0;
        ut_M_Data df_Var = {0};
        ut_M_Data* df = NULL;
        ++LUMI_trace_ignore_count;
        CHECK_REF(2, LUMI_block1_cleanup, ut_M_ostr)
        INIT_NEW(2, LUMI_block1_cleanup, f, FileReadWriteBinary, 1);
        LUMI_err = FileReadWriteBinary_new(f, ut_M_ostr, false, false);
        CHECK(2, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteBinary_get(f, &(ut_M_bt), &(ut_M_b));
        CHECK(3, LUMI_block1_cleanup)
        CHECK_REF(4, LUMI_block1_cleanup, ut_M_buff)
        LUMI_err = FileReadWriteBinary_read(f, ut_M_buff, ut_M_buff_Length, &(ut_M_i));
        CHECK(4, LUMI_block1_cleanup)
        LUMI_err = FileReadWriteBinary_put(f, ut_M_bt);
        CHECK(5, LUMI_block1_cleanup)
        CHECK_REF(6, LUMI_block1_cleanup, ut_M_buff)
        LUMI_err = FileReadWriteBinary_write(f, ut_M_buff, ut_M_buff_Length, &(ut_M_i));
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
        ut_M_Data_set(df, f, (Generic_Type_Dynamic*)&FileReadWriteBinary_dynamic);
        f = NULL;
    LUMI_block1_cleanup:
        (void)0;
        ut_M_Data_Del(df, NULL);
        FileReadWriteBinary_Del(f, NULL);
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
typedef struct ut_M_Data_Dynamic ut_M_Data_Dynamic;
struct ut_M_Data {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Data_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Data_set(ut_M_Data* self, Generic_Type* item, Generic_Type_Dynamic* item_Dynamic);
void ut_M_Data_Del(ut_M_Data* self, ut_M_Data_Dynamic* self_Dynamic);
Return_Code ut_M_fun(String* name, File* f, FileReadText* frt, FileReadBinary* frb, FileWriteText* fwt, FileWriteBinary* fwb, FileReadWriteText* frwt, FileReadWriteBinary* frwb);
ut_M_Data_Dynamic ut_M_Data_dynamic = {
    (Dynamic_Del)ut_M_Data_Del
};
void ut_M_Data_set(ut_M_Data* self, Generic_Type* item, Generic_Type_Dynamic* item_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    if (item_Dynamic != NULL) item_Dynamic->_del(item, item_Dynamic);
    free(item);
}
void ut_M_Data_Del(ut_M_Data* self, ut_M_Data_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Return_Code ut_M_fun(String* name, File* f, FileReadText* frt, FileReadBinary* frb, FileWriteText* fwt, FileWriteBinary* fwb, FileReadWriteText* frwt, FileReadWriteBinary* frwb) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    ut_M_Data df_Var = {0};
    ut_M_Data* df = NULL;
    File* fo = NULL;
    int64_t i = 0;
    FileWriteBinary* aux_FileWriteBinary_0 = NULL;
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
    LUMI_err = ut_M_fun(name, frt, frwt, frwb, frwt, frwb, frwt, frwb);
    CHECK(24, LUMI_block0_cleanup)
    df = &df_Var;
    INIT_NEW(34, LUMI_block0_cleanup, aux_FileWriteBinary_0, FileWriteBinary, 1);
    LUMI_err = FileWriteBinary_new(aux_FileWriteBinary_0, name, false);
    CHECK(34, LUMI_block0_cleanup)
    fo = aux_FileWriteBinary_0;
    aux_FileWriteBinary_0 = NULL;
    LUMI_err = File_tell(fo, &(i));
    CHECK(36, LUMI_block0_cleanup)
    LUMI_err = File_seek_set(fo, i);
    CHECK(37, LUMI_block0_cleanup)
    LUMI_err = File_seek_cur(fo, i);
    CHECK(38, LUMI_block0_cleanup)
    LUMI_err = File_seek_end(fo, i);
    CHECK(39, LUMI_block0_cleanup)
    LUMI_err = File_flush(fo);
    CHECK(40, LUMI_block0_cleanup)
    LUMI_err = File_close(fo);
    CHECK(41, LUMI_block0_cleanup)
    ut_M_Data_set(df, fo, (Generic_Type_Dynamic*)&File_dynamic);
    fo = NULL;
LUMI_block0_cleanup:
    (void)0;
    FileWriteBinary_Del(aux_FileWriteBinary_0, NULL);
    free(aux_FileWriteBinary_0);
    File_Del(fo, NULL);
    free(fo);
    ut_M_Data_Del(df, NULL);
    return LUMI_err;
}
/// @ test-builtin-sys0
String* argv = NULL;
    uint32_t argv_Length = 0;
    argv_Length = sys_M_argv_Length;
    argv = sys_M_argv;
/// @ test-builtin-sys1
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    LUMI_err = sys_M_print(ut_M_buff, ut_M_buff_Length);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys2
CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    LUMI_err = sys_M_println(ut_M_buff, ut_M_buff_Length);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys3
LUMI_err = sys_M_getchar(&(ut_M_c), &(ut_M_b));
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys4
Byte* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    LUMI_err = sys_M_getline(ut_M_buff, ut_M_buff_Length, &(aux_Array_0), &(aux_Array_0_Length), &(ut_M_b));
    bfr_Length = aux_Array_0_Length;
    bfr = aux_Array_0;
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys5
LUMI_err = sys_M_exit(ut_M_j);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys6
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = sys_M_system(ut_M_ostr, &(ut_M_j));
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys7
CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    LUMI_err = sys_M_getenv(ut_M_ostr, ut_M_ostr, &(ut_M_b));
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys8
LUMI_err = FileReadText_get(sys_M_stdin, &(ut_M_bt), &(ut_M_b));
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys9
LUMI_err = FileWriteText_put(sys_M_stdout, ut_M_bt);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-sys10
LUMI_err = FileWriteText_put(sys_M_stderr, ut_M_bt);
    CHECK(1, LUMI_block0_cleanup)
/// @ test-builtin-file-e0
too few parameters
/// @ test-builtin-file-e1
too few parameters
/// @ test-builtin-file-e2
too few parameters
/// @@ test-general
/// @ test-general-0
String* ut_M_str = NULL;
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
String ut_M_s_Var = {0};
String* ut_M_s = NULL;
String ut_M_svs_Var = {0};
String* ut_M_svs = NULL;
Ref_Manager* ut_M_svs_Refman = NULL;
String* ut_M_cs = NULL;
String* ut_M_us = NULL;
Ref_Manager* ut_M_us_Refman = NULL;
String* ut_M_gs = NULL;
Ref_Manager* ut_M_gs_Refman = NULL;
void new_Mock(Bool* allocate_success) { }
Return_Code delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    uint32_t x = 0;
    String* ls = NULL;
    String* aux_String_0 = NULL;
    String* aux_String_0 = NULL;
    static Byte aux_Array_0[] = {'g','l','o','b','a','l',' ','t','e','x','t','\0',};
    String* aux_String_1 = NULL;
    Byte* aux_Array_1 = NULL;
    uint32_t aux_Array_1_Length = 0;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "mock.5.lm"
    ut_M_s = &ut_M_s_Var;
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.5.lm"
    ut_M_svs = &ut_M_svs_Var;
    INIT_VAR_REFMAN(2, LUMI_block0_cleanup, ut_M_svs)
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.5.lm"
    INIT_NEW(3, LUMI_block0_cleanup, aux_String_0, String, 1);
    LUMI_err = String_new(aux_String_0, aux_Array_0, 0x0b);
    CHECK(3, LUMI_block0_cleanup)
    ut_M_cs = aux_String_0;
    aux_String_0 = NULL;
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.5.lm"
    String_bytes(ut_M_s, &(aux_Array_1), &(aux_Array_1_Length));
    INIT_NEW(5, LUMI_block0_cleanup, aux_String_1, String, 1);
    LUMI_err = String_new(aux_String_1, aux_Array_1, aux_Array_1_Length);
    CHECK(5, LUMI_block0_cleanup)
    ut_M_us = aux_String_1;
    aux_String_1 = NULL;
    INIT_NEW_REFMAN(5, LUMI_block0_cleanup, ut_M_us)
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.5.lm"
    LUMI_inc_ref(ut_M_us_Refman);
    LUMI_dec_ref(ut_M_gs_Refman);
    ut_M_gs_Refman = ut_M_us_Refman;
    ut_M_gs = ut_M_us;
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
    x = 0x06;
    x = 0x07;
    INIT_NEW(10, LUMI_block0_cleanup, ls, String, 1);
    aux_String_0 = ls;
    ls = ut_M_cs;
    ut_M_cs = aux_String_0;
    aux_String_0 = NULL;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0, NULL);
    free(aux_String_0);
    String_Del(ls, NULL);
    free(ls);
    return LUMI_err;
}
MAIN_FUNC
/// @ test-general-7
void ut_M_fun(void);
Return_Code second_M_dummy(void);
String ut_M_s_Var = {0};
String* ut_M_s = NULL;
Line_Count LUMI_file0_line_count[5] = {
    -1,-1,-1, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.5.lm", 5, LUMI_file0_line_count}
};
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
    ++LUMI_file_coverage[0].line_count[3];
    String_clear(ut_M_s);
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
    ut_M_s = &ut_M_s_Var;
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
/// @ test-struct-1
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
/// @ test-struct-2
typedef struct ut_M_Test1 ut_M_Test1;
typedef struct ut_M_Test1_Dynamic ut_M_Test1_Dynamic;
typedef struct ut_M_Test2 ut_M_Test2;
typedef struct ut_M_Test2_Dynamic ut_M_Test2_Dynamic;
typedef struct ut_M_Test3 ut_M_Test3;
typedef struct ut_M_Test3_Dynamic ut_M_Test3_Dynamic;
struct ut_M_Test1 {
    uint32_t x;
};
struct ut_M_Test1_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test2 {
    uint32_t x;
};
struct ut_M_Test2_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test3 {
    uint32_t x;
};
struct ut_M_Test3_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test1_Del(ut_M_Test1* self, ut_M_Test1_Dynamic* self_Dynamic);
void ut_M_Test2_Del(ut_M_Test2* self, ut_M_Test2_Dynamic* self_Dynamic);
void ut_M_Test3_Del(ut_M_Test3* self, ut_M_Test3_Dynamic* self_Dynamic);
ut_M_Test1_Dynamic ut_M_Test1_dynamic = {
    (Dynamic_Del)ut_M_Test1_Del
};
ut_M_Test2_Dynamic ut_M_Test2_dynamic = {
    (Dynamic_Del)ut_M_Test2_Del
};
ut_M_Test3_Dynamic ut_M_Test3_dynamic = {
    (Dynamic_Del)ut_M_Test3_Del
};
void ut_M_Test1_Del(ut_M_Test1* self, ut_M_Test1_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Test2_Del(ut_M_Test2* self, ut_M_Test2_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Test3_Del(ut_M_Test3* self, ut_M_Test3_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
/// @ test-struct-3
typedef struct ut_M_Test1 ut_M_Test1;
typedef struct ut_M_Test1_Dynamic ut_M_Test1_Dynamic;
typedef struct ut_M_Test2 ut_M_Test2;
typedef struct ut_M_Test2_Dynamic ut_M_Test2_Dynamic;
struct ut_M_Test1 {
    uint32_t x;
};
struct ut_M_Test1_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test2 {
    ut_M_Test1 _base;
    uint32_t y;
};
struct ut_M_Test2_Dynamic {
    ut_M_Test1_Dynamic _base;
};
void ut_M_Test1_Del(ut_M_Test1* self, ut_M_Test1_Dynamic* self_Dynamic);
void ut_M_Test2_Del(ut_M_Test2* self, ut_M_Test2_Dynamic* self_Dynamic);
ut_M_Test1_Dynamic ut_M_Test1_dynamic = {
    (Dynamic_Del)ut_M_Test1_Del
};
ut_M_Test2_Dynamic ut_M_Test2_dynamic = {
    {
        (Dynamic_Del)ut_M_Test2_Del
    }
};
void ut_M_Test1_Del(ut_M_Test1* self, ut_M_Test1_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Test2_Del(ut_M_Test2* self, ut_M_Test2_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Test1_Del(&(self->_base), NULL);
}
/// @ test-struct-4
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    ut_M_Test* to;
    ut_M_Test* ts;
    Ref_Manager* ts_Refman;
    ut_M_Test* tw;
    Ref_Manager* tw_Refman;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->tw_Refman);
    SELF_REF_DEL_STR(ut_M_Test, ts, NULL);
    LUMI_owner_dec_ref(self->ts_Refman);
    SELF_REF_DEL(ut_M_Test, to, NULL);
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
/// @@ test-dynamic
/// @ test-dynamic-0
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Some ut_M_Some;
typedef struct ut_M_Some_Dynamic ut_M_Some_Dynamic;
struct ut_M_Test {
    Dynamic_Del _del;
    void* _self_Dynamic;
    void (*fun)(void* self, void* self_Dynamic);
    void (*wf)(void* self, Ref_Manager* self_Refman, void* self_Dynamic);
};
struct ut_M_Some {
    uint8_t x;
    void* t;
    ut_M_Test* t_Dynamic;
};
struct ut_M_Some_Dynamic {
    Dynamic_Del _del;
    ut_M_Test _ut_M_Test;
};
void ut_M_Some_fun(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic);
void ut_M_Some_wf(ut_M_Some* self, Ref_Manager* self_Refman, ut_M_Some_Dynamic* self_Dynamic);
void ut_M_Some_Del(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic);
Return_Code ut_M_fun(void* t, ut_M_Test* t_Dynamic, ut_M_Some** so, void** to, ut_M_Test** to_Dynamic);
void ut_M_sfun(ut_M_Some* s, Ref_Manager* s_Refman);
ut_M_Some_Dynamic ut_M_Some_dynamic = {
    (Dynamic_Del)ut_M_Some_Del,
    {
        (Dynamic_Del)ut_M_Some_Del,
        &ut_M_Some_dynamic,
        (void (*)(void* self, void* self_Dynamic))ut_M_Some_fun,
        (void (*)(void* self, Ref_Manager* self_Refman, void* self_Dynamic))ut_M_Some_wf
    }
};
void* ut_M_gt = NULL;
ut_M_Test* ut_M_gt_Dynamic = NULL;
void ut_M_Some_fun(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    self->x = 0x03;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Some_wf(ut_M_Some* self, Ref_Manager* self_Refman, ut_M_Some_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(self_Refman);
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(self_Refman);
}
void ut_M_Some_Del(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    if (self->t_Dynamic != NULL) self->t_Dynamic->_del(self->t, self->t_Dynamic);
    free(self->t);
}
Return_Code ut_M_fun(void* t, ut_M_Test* t_Dynamic, ut_M_Some** so, void** to, ut_M_Test** to_Dynamic) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    void* t2 = NULL;
    ut_M_Test* t2_Dynamic = NULL;
    void* aux_Test_0 = NULL;
    ut_M_Test* aux_Test_0_Dynamic = NULL;
    ut_M_Some* aux_Some_0 = NULL;
    *so = NULL;
    *to_Dynamic = t_Dynamic;
    *to = t;
    CHECK_REF(15, LUMI_block0_cleanup, t)
    if (t_Dynamic == NULL) RAISE(15, LUMI_block0_cleanup, empty_object)
    t_Dynamic->fun(t, t_Dynamic->_self_Dynamic);
    CHECK_REF(16, LUMI_block0_cleanup, *so)
    ut_M_Some_fun(*so, &ut_M_Some_dynamic);
    *to_Dynamic = NULL_OR_VALUE(*so, &(ut_M_Some_dynamic._ut_M_Test));
    *to = *so;
    *to_Dynamic = NULL;
    *to = NULL;
    LUMI_err = ut_M_fun(t, t_Dynamic, &(*so), &(*to), &(*to_Dynamic));
    CHECK(19, LUMI_block0_cleanup)
    LUMI_err = ut_M_fun(NULL, NULL, &(*so), &(aux_Test_0), &(aux_Test_0_Dynamic));
    CHECK(20, LUMI_block0_cleanup)
    LUMI_err = ut_M_fun(*so, NULL_OR_VALUE(*so, &(ut_M_Some_dynamic._ut_M_Test)), &(aux_Some_0), &(t2), &(t2_Dynamic));
    *to_Dynamic = NULL_OR_VALUE(aux_Some_0, &(ut_M_Some_dynamic._ut_M_Test));
    *to = aux_Some_0;
    CHECK(22, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_sfun(ut_M_Some* s, Ref_Manager* s_Refman) {
    unsigned LUMI_loop_depth = 1;
    void* tc = NULL;
    ut_M_Test* tc_Dynamic = NULL;
    void* t = NULL;
    Ref_Manager* t_Refman = NULL;
    ut_M_Test* t_Dynamic = NULL;
    ut_M_Some_wf(s, s_Refman, &ut_M_Some_dynamic);
    tc_Dynamic = &(ut_M_Some_dynamic._ut_M_Test);
    tc = s;
    if (t_Dynamic != NULL) t_Dynamic->_del(t, t_Dynamic);
    LUMI_owner_dec_ref(t_Refman);
    t_Refman = s_Refman;
    t_Dynamic = &(ut_M_Some_dynamic._ut_M_Test);
    t = s;
    s = NULL;
    s_Refman = NULL;
    t_Dynamic->fun(t, t_Dynamic->_self_Dynamic);
    t_Dynamic->wf(t, t_Refman, t_Dynamic->_self_Dynamic);
LUMI_block0_cleanup:
    (void)0;
    if (t_Dynamic != NULL) t_Dynamic->_del(t, t_Dynamic);
    LUMI_owner_dec_ref(t_Refman);
    ut_M_Some_Del(s, NULL);
    LUMI_owner_dec_ref(s_Refman);
}
/// @ test-dynamic-1
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Some ut_M_Some;
typedef struct ut_M_Some_Dynamic ut_M_Some_Dynamic;
struct ut_M_Test {
    Dynamic_Del _del;
    void* _self_Dynamic;
    void (*fun)(void* self, void* self_Dynamic);
    void (*wf)(void* self, Ref_Manager* self_Refman, void* self_Dynamic);
    void (*another)(void* self, void* self_Dynamic);
};
struct ut_M_Some {
    uint8_t x;
};
struct ut_M_Some_Dynamic {
    Dynamic_Del _del;
    ut_M_Test _ut_M_Test;
    void (*fun)(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic);
    void (*wf)(ut_M_Some* self, Ref_Manager* self_Refman, ut_M_Some_Dynamic* self_Dynamic);
};
void ut_M_Some_fun(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic);
void ut_M_Some_another(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic);
void ut_M_Some_wf(ut_M_Some* self, Ref_Manager* self_Refman, ut_M_Some_Dynamic* self_Dynamic);
void ut_M_Some_Del(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic);
Return_Code ut_M_fun(void* t, ut_M_Test* t_Dynamic, ut_M_Some** so, ut_M_Some_Dynamic** so_Dynamic);
void ut_M_sfun(ut_M_Some* s, Ref_Manager* s_Refman, ut_M_Some_Dynamic* s_Dynamic);
ut_M_Some_Dynamic ut_M_Some_dynamic = {
    (Dynamic_Del)ut_M_Some_Del,
    {
        (Dynamic_Del)ut_M_Some_Del,
        &ut_M_Some_dynamic,
        (void (*)(void* self, void* self_Dynamic))ut_M_Some_fun,
        (void (*)(void* self, Ref_Manager* self_Refman, void* self_Dynamic))ut_M_Some_wf,
        (void (*)(void* self, void* self_Dynamic))ut_M_Some_another
    },
    ut_M_Some_fun,
    ut_M_Some_wf
};
void ut_M_Some_fun(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    self->x = 0x04;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Some_another(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Some_wf(ut_M_Some* self, Ref_Manager* self_Refman, ut_M_Some_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(self_Refman);
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(self_Refman);
}
void ut_M_Some_Del(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
Return_Code ut_M_fun(void* t, ut_M_Test* t_Dynamic, ut_M_Some** so, ut_M_Some_Dynamic** so_Dynamic) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    void* tu = NULL;
    ut_M_Test* tu_Dynamic = NULL;
    ut_M_Some* aux_Some_0 = NULL;
    ut_M_Some_Dynamic* aux_Some_0_Dynamic = NULL;
    *so_Dynamic = NULL;
    *so = NULL;
    tu_Dynamic = NULL_OR_VALUE(*so, &((*so_Dynamic)->_ut_M_Test));
    tu = *so;
    CHECK_REF(15, LUMI_block0_cleanup, *so)
    if (*so_Dynamic == NULL) RAISE(15, LUMI_block0_cleanup, empty_object)
    (*so_Dynamic)->fun(*so, *so_Dynamic);
    CHECK_REF(16, LUMI_block0_cleanup, *so)
    ut_M_Some_another(*so, *so_Dynamic);
    LUMI_err = ut_M_fun(*so, NULL_OR_VALUE(*so, &((*so_Dynamic)->_ut_M_Test)), &(aux_Some_0), &(aux_Some_0_Dynamic));
    tu_Dynamic = NULL_OR_VALUE(aux_Some_0, &(aux_Some_0_Dynamic->_ut_M_Test));
    tu = aux_Some_0;
    CHECK(17, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_sfun(ut_M_Some* s, Ref_Manager* s_Refman, ut_M_Some_Dynamic* s_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    void* t = NULL;
    Ref_Manager* t_Refman = NULL;
    ut_M_Test* t_Dynamic = NULL;
    s_Dynamic->wf(s, s_Refman, s_Dynamic);
    if (t_Dynamic != NULL) t_Dynamic->_del(t, t_Dynamic);
    LUMI_owner_dec_ref(t_Refman);
    t_Refman = s_Refman;
    t_Dynamic = &(s_Dynamic->_ut_M_Test);
    t = s;
    s = NULL;
    s_Refman = NULL;
    s_Dynamic = NULL;
    t_Dynamic->fun(t, t_Dynamic->_self_Dynamic);
    t_Dynamic->another(t, t_Dynamic->_self_Dynamic);
    t_Dynamic->wf(t, t_Refman, t_Dynamic->_self_Dynamic);
LUMI_block0_cleanup:
    (void)0;
    if (t_Dynamic != NULL) t_Dynamic->_del(t, t_Dynamic);
    LUMI_owner_dec_ref(t_Refman);
    if (s_Dynamic != NULL) s_Dynamic->_del(s, s_Dynamic);
    LUMI_owner_dec_ref(s_Refman);
}
/// @ test-dynamic-2
typedef struct ut_M_Da ut_M_Da;
typedef struct ut_M_Db ut_M_Db;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Dc ut_M_Dc;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Mid_Dynamic ut_M_Mid_Dynamic;
typedef struct ut_M_Top ut_M_Top;
typedef struct ut_M_Top_Dynamic ut_M_Top_Dynamic;
struct ut_M_Da {
    Dynamic_Del _del;
    void* _self_Dynamic;
    void (*fa)(void* self, void* self_Dynamic);
};
struct ut_M_Db {
    Dynamic_Del _del;
    void* _self_Dynamic;
    void (*fb)(void* self, void* self_Dynamic);
};
struct ut_M_Base {
    Bool x;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
    ut_M_Da _ut_M_Da;
    ut_M_Db _ut_M_Db;
};
struct ut_M_Dc {
    Dynamic_Del _del;
    void* _self_Dynamic;
    void (*fc)(void* self, void* self_Dynamic);
};
struct ut_M_Mid {
    ut_M_Base _base;
};
struct ut_M_Mid_Dynamic {
    ut_M_Base_Dynamic _base;
    ut_M_Dc _ut_M_Dc;
};
struct ut_M_Top {
    ut_M_Mid _base;
};
struct ut_M_Top_Dynamic {
    ut_M_Mid_Dynamic _base;
};
void ut_M_Base_fa(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_fb(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Mid_fa(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Mid_fc(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Top_fa(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
void ut_M_fun(ut_M_Base* b, ut_M_Mid* m, ut_M_Top* t, void** da, ut_M_Da** da_Dynamic, void** db, ut_M_Db** db_Dynamic, void** dc, ut_M_Dc** dc_Dynamic);
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del,
    {
        (Dynamic_Del)ut_M_Base_Del,
        &ut_M_Base_dynamic,
        (void (*)(void* self, void* self_Dynamic))ut_M_Base_fa
    },
    {
        (Dynamic_Del)ut_M_Base_Del,
        &ut_M_Base_dynamic,
        (void (*)(void* self, void* self_Dynamic))ut_M_Base_fb
    }
};
ut_M_Mid_Dynamic ut_M_Mid_dynamic = {
    {
        (Dynamic_Del)ut_M_Mid_Del,
        {
            (Dynamic_Del)ut_M_Mid_Del,
            &ut_M_Mid_dynamic,
            (void (*)(void* self, void* self_Dynamic))ut_M_Mid_fa
        },
        {
            (Dynamic_Del)ut_M_Mid_Del,
            &ut_M_Mid_dynamic,
            (void (*)(void* self, void* self_Dynamic))ut_M_Base_fb
        }
    },
    {
        (Dynamic_Del)ut_M_Mid_Del,
        &ut_M_Mid_dynamic,
        (void (*)(void* self, void* self_Dynamic))ut_M_Mid_fc
    }
};
ut_M_Top_Dynamic ut_M_Top_dynamic = {
    {
        {
            (Dynamic_Del)ut_M_Top_Del,
            {
                (Dynamic_Del)ut_M_Top_Del,
                &ut_M_Top_dynamic,
                (void (*)(void* self, void* self_Dynamic))ut_M_Top_fa
            },
            {
                (Dynamic_Del)ut_M_Top_Del,
                &ut_M_Top_dynamic,
                (void (*)(void* self, void* self_Dynamic))ut_M_Base_fb
            }
        },
        {
            (Dynamic_Del)ut_M_Top_Del,
            &ut_M_Top_dynamic,
            (void (*)(void* self, void* self_Dynamic))ut_M_Mid_fc
        }
    }
};
void ut_M_Base_fa(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_fb(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Mid_fa(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Mid_fc(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
}
void ut_M_Top_fa(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base), NULL);
}
void ut_M_fun(ut_M_Base* b, ut_M_Mid* m, ut_M_Top* t, void** da, ut_M_Da** da_Dynamic, void** db, ut_M_Db** db_Dynamic, void** dc, ut_M_Dc** dc_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    *da_Dynamic = &(ut_M_Base_dynamic._ut_M_Da);
    *da = b;
    *da_Dynamic = &(ut_M_Mid_dynamic._base._ut_M_Da);
    *da = m;
    *da_Dynamic = &(ut_M_Top_dynamic._base._base._ut_M_Da);
    *da = t;
    *db_Dynamic = &(ut_M_Base_dynamic._ut_M_Db);
    *db = b;
    *db_Dynamic = &(ut_M_Mid_dynamic._base._ut_M_Db);
    *db = &(m->_base);
    *db_Dynamic = &(ut_M_Top_dynamic._base._base._ut_M_Db);
    *db = &(t->_base._base);
    *dc_Dynamic = &(ut_M_Mid_dynamic._ut_M_Dc);
    *dc = m;
    *dc_Dynamic = &(ut_M_Top_dynamic._base._ut_M_Dc);
    *dc = &(t->_base);
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-dynamic-3
typedef struct ut_M_Da ut_M_Da;
typedef struct ut_M_Db ut_M_Db;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Low ut_M_Low;
typedef struct ut_M_Low_Dynamic ut_M_Low_Dynamic;
typedef struct ut_M_Dc ut_M_Dc;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Mid_Dynamic ut_M_Mid_Dynamic;
typedef struct ut_M_Top ut_M_Top;
typedef struct ut_M_Top_Dynamic ut_M_Top_Dynamic;
struct ut_M_Da {
    Dynamic_Del _del;
    void* _self_Dynamic;
    void (*fa)(void* self, void* self_Dynamic);
};
struct ut_M_Db {
    Dynamic_Del _del;
    void* _self_Dynamic;
    void (*fb)(void* self, void* self_Dynamic);
};
struct ut_M_Base {
    Bool x;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
    ut_M_Da _ut_M_Da;
    ut_M_Db _ut_M_Db;
};
struct ut_M_Low {
    ut_M_Base _base;
};
struct ut_M_Low_Dynamic {
    ut_M_Base_Dynamic _base;
    void (*meth)(ut_M_Low* self, ut_M_Low_Dynamic* self_Dynamic);
    void (*fa)(ut_M_Low* self, ut_M_Low_Dynamic* self_Dynamic);
};
struct ut_M_Dc {
    Dynamic_Del _del;
    void* _self_Dynamic;
    void (*fc)(void* self, void* self_Dynamic);
};
struct ut_M_Mid {
    ut_M_Low _base;
};
struct ut_M_Mid_Dynamic {
    ut_M_Low_Dynamic _base;
    ut_M_Dc _ut_M_Dc;
    void (*fc)(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
};
struct ut_M_Top {
    ut_M_Mid _base;
};
struct ut_M_Top_Dynamic {
    ut_M_Mid_Dynamic _base;
};
void ut_M_Base_fa(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_fb(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Low_meth(ut_M_Low* self, ut_M_Low_Dynamic* self_Dynamic);
void ut_M_Low_fa(ut_M_Low* self, ut_M_Low_Dynamic* self_Dynamic);
void ut_M_Low_Del(ut_M_Low* self, ut_M_Low_Dynamic* self_Dynamic);
void ut_M_Mid_fa(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Mid_fc(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Top_fa(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
void ut_M_dyn(void* da, ut_M_Da* da_Dynamic, void* db, ut_M_Db* db_Dynamic, void* dc, ut_M_Dc* dc_Dynamic);
void ut_M_fun(ut_M_Base* b, ut_M_Low* l, ut_M_Low_Dynamic* l_Dynamic, ut_M_Mid* m, ut_M_Mid_Dynamic* m_Dynamic, ut_M_Top* t, ut_M_Top_Dynamic* t_Dynamic, void** da, ut_M_Da** da_Dynamic, void** db, ut_M_Db** db_Dynamic, void** dc, ut_M_Dc** dc_Dynamic);
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del,
    {
        (Dynamic_Del)ut_M_Base_Del,
        &ut_M_Base_dynamic,
        (void (*)(void* self, void* self_Dynamic))ut_M_Base_fa
    },
    {
        (Dynamic_Del)ut_M_Base_Del,
        &ut_M_Base_dynamic,
        (void (*)(void* self, void* self_Dynamic))ut_M_Base_fb
    }
};
ut_M_Low_Dynamic ut_M_Low_dynamic = {
    {
        (Dynamic_Del)ut_M_Low_Del,
        {
            (Dynamic_Del)ut_M_Low_Del,
            &ut_M_Low_dynamic,
            (void (*)(void* self, void* self_Dynamic))ut_M_Low_fa
        },
        {
            (Dynamic_Del)ut_M_Low_Del,
            &ut_M_Low_dynamic,
            (void (*)(void* self, void* self_Dynamic))ut_M_Base_fb
        }
    },
    ut_M_Low_meth,
    ut_M_Low_fa
};
ut_M_Mid_Dynamic ut_M_Mid_dynamic = {
    {
        {
            (Dynamic_Del)ut_M_Mid_Del,
            {
                (Dynamic_Del)ut_M_Mid_Del,
                &ut_M_Mid_dynamic,
                (void (*)(void* self, void* self_Dynamic))ut_M_Mid_fa
            },
            {
                (Dynamic_Del)ut_M_Mid_Del,
                &ut_M_Mid_dynamic,
                (void (*)(void* self, void* self_Dynamic))ut_M_Base_fb
            }
        },
        ut_M_Low_meth,
        (void (*)(ut_M_Low* self, ut_M_Low_Dynamic* self_Dynamic))ut_M_Mid_fa
    },
    {
        (Dynamic_Del)ut_M_Mid_Del,
        &ut_M_Mid_dynamic,
        (void (*)(void* self, void* self_Dynamic))ut_M_Mid_fc
    },
    ut_M_Mid_fc
};
ut_M_Top_Dynamic ut_M_Top_dynamic = {
    {
        {
            {
                (Dynamic_Del)ut_M_Top_Del,
                {
                    (Dynamic_Del)ut_M_Top_Del,
                    &ut_M_Top_dynamic,
                    (void (*)(void* self, void* self_Dynamic))ut_M_Top_fa
                },
                {
                    (Dynamic_Del)ut_M_Top_Del,
                    &ut_M_Top_dynamic,
                    (void (*)(void* self, void* self_Dynamic))ut_M_Base_fb
                }
            },
            ut_M_Low_meth,
            (void (*)(ut_M_Low* self, ut_M_Low_Dynamic* self_Dynamic))ut_M_Top_fa
        },
        {
            (Dynamic_Del)ut_M_Top_Del,
            &ut_M_Top_dynamic,
            (void (*)(void* self, void* self_Dynamic))ut_M_Mid_fc
        },
        ut_M_Mid_fc
    }
};
void ut_M_Base_fa(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_fb(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Low_meth(ut_M_Low* self, ut_M_Low_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Low_fa(ut_M_Low* self, ut_M_Low_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Low_Del(ut_M_Low* self, ut_M_Low_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
}
void ut_M_Mid_fa(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Mid_fc(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Low_Del(&(self->_base), &(self_Dynamic->_base));
}
void ut_M_Top_fa(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base), &(self_Dynamic->_base));
}
void ut_M_dyn(void* da, ut_M_Da* da_Dynamic, void* db, ut_M_Db* db_Dynamic, void* dc, ut_M_Dc* dc_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun(ut_M_Base* b, ut_M_Low* l, ut_M_Low_Dynamic* l_Dynamic, ut_M_Mid* m, ut_M_Mid_Dynamic* m_Dynamic, ut_M_Top* t, ut_M_Top_Dynamic* t_Dynamic, void** da, ut_M_Da** da_Dynamic, void** db, ut_M_Db** db_Dynamic, void** dc, ut_M_Dc** dc_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    *da_Dynamic = &(ut_M_Base_dynamic._ut_M_Da);
    *da = b;
    *da_Dynamic = &(l_Dynamic->_base._ut_M_Da);
    *da = l;
    *da_Dynamic = &(m_Dynamic->_base._base._ut_M_Da);
    *da = m;
    *da_Dynamic = &(t_Dynamic->_base._base._base._ut_M_Da);
    *da = t;
    *db_Dynamic = &(ut_M_Base_dynamic._ut_M_Db);
    *db = b;
    *db_Dynamic = &(l_Dynamic->_base._ut_M_Db);
    *db = &(l->_base);
    *db_Dynamic = &(m_Dynamic->_base._base._ut_M_Db);
    *db = &(m->_base._base);
    *db_Dynamic = &(t_Dynamic->_base._base._base._ut_M_Db);
    *db = &(t->_base._base._base);
    *dc_Dynamic = &(m_Dynamic->_ut_M_Dc);
    *dc = m;
    *dc_Dynamic = &(t_Dynamic->_base._ut_M_Dc);
    *dc = &(t->_base);
    ut_M_dyn(t, &(t_Dynamic->_base._base._base._ut_M_Da), &(t->_base._base._base), &(t_Dynamic->_base._base._base._ut_M_Db), &(t->_base), &(t_Dynamic->_base._ut_M_Dc));
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-dynamic-4
typedef struct ut_M_Data ut_M_Data;
typedef struct ut_M_Data_Dynamic ut_M_Data_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_MyStruct_Dynamic ut_M_MyStruct_Dynamic;
typedef struct ut_M_MyClass ut_M_MyClass;
typedef struct ut_M_MyClass_Dynamic ut_M_MyClass_Dynamic;
struct ut_M_Data {
    Generic_Type* d;
    Ref_Manager* d_Refman;
    Generic_Type_Dynamic* d_Dynamic;
};
struct ut_M_Data_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test {
    Dynamic_Del _del;
    void* _self_Dynamic;
    void (*fun)(void* self, void* self_Dynamic);
};
struct ut_M_MyStruct {
    Bool x;
};
struct ut_M_MyStruct_Dynamic {
    Dynamic_Del _del;
    ut_M_Test _ut_M_Test;
};
struct ut_M_MyClass {
    Bool x;
};
struct ut_M_MyClass_Dynamic {
    Dynamic_Del _del;
    ut_M_Test _ut_M_Test;
    void (*fun)(ut_M_MyClass* self, ut_M_MyClass_Dynamic* self_Dynamic);
};
void ut_M_Data_meth(ut_M_Data* self, Generic_Type* in, Ref_Manager* in_Refman, Generic_Type_Dynamic* in_Dynamic, Generic_Type** out, Ref_Manager** out_Refman, Generic_Type_Dynamic** out_Dynamic);
void ut_M_Data_Del(ut_M_Data* self, ut_M_Data_Dynamic* self_Dynamic);
void ut_M_MyStruct_fun(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic);
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic);
void ut_M_MyClass_fun(ut_M_MyClass* self, ut_M_MyClass_Dynamic* self_Dynamic);
void ut_M_MyClass_Del(ut_M_MyClass* self, ut_M_MyClass_Dynamic* self_Dynamic);
void ut_M_fun(ut_M_Data* dt, ut_M_Data* ds, ut_M_Data* dc);
ut_M_Data_Dynamic ut_M_Data_dynamic = {
    (Dynamic_Del)ut_M_Data_Del
};
ut_M_MyStruct_Dynamic ut_M_MyStruct_dynamic = {
    (Dynamic_Del)ut_M_MyStruct_Del,
    {
        (Dynamic_Del)ut_M_MyStruct_Del,
        &ut_M_MyStruct_dynamic,
        (void (*)(void* self, void* self_Dynamic))ut_M_MyStruct_fun
    }
};
ut_M_MyClass_Dynamic ut_M_MyClass_dynamic = {
    (Dynamic_Del)ut_M_MyClass_Del,
    {
        (Dynamic_Del)ut_M_MyClass_Del,
        &ut_M_MyClass_dynamic,
        (void (*)(void* self, void* self_Dynamic))ut_M_MyClass_fun
    },
    ut_M_MyClass_fun
};
void ut_M_Data_meth(ut_M_Data* self, Generic_Type* in, Ref_Manager* in_Refman, Generic_Type_Dynamic* in_Dynamic, Generic_Type** out, Ref_Manager** out_Refman, Generic_Type_Dynamic** out_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(in_Refman);
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(in_Refman);
}
void ut_M_Data_Del(ut_M_Data* self, ut_M_Data_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->d_Refman);
}
void ut_M_MyStruct_fun(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_MyClass_fun(ut_M_MyClass* self, ut_M_MyClass_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_MyClass_Del(ut_M_MyClass* self, ut_M_MyClass_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_fun(ut_M_Data* dt, ut_M_Data* ds, ut_M_Data* dc) {
    unsigned LUMI_loop_depth = 1;
    void* t = NULL;
    Ref_Manager* t_Refman = NULL;
    ut_M_Test* t_Dynamic = NULL;
    ut_M_MyStruct* aux_MyStruct_0 = NULL;
    Ref_Manager* aux_MyStruct_0_Refman = NULL;
    ut_M_MyClass* aux_MyClass_0 = NULL;
    Ref_Manager* aux_MyClass_0_Refman = NULL;
    ut_M_MyClass_Dynamic* aux_MyClass_0_Dynamic = NULL;
    LUMI_inc_ref(dt->d_Refman);
    LUMI_dec_ref(t_Refman);
    t_Refman = dt->d_Refman;
    t_Dynamic = ((ut_M_Test*)(dt->d_Dynamic));
    t = dt->d;
    LUMI_inc_ref(t_Refman);
    LUMI_dec_ref(dt->d_Refman);
    dt->d_Refman = t_Refman;
    dt->d_Dynamic = (Generic_Type_Dynamic*)t_Dynamic;
    dt->d = t;
    ut_M_Data_meth(dt, t, t_Refman, (void*)t_Dynamic, (void*)&(t), &(t_Refman), (void*)&(t_Dynamic));
    LUMI_inc_ref(ds->d_Refman);
    LUMI_dec_ref(t_Refman);
    t_Refman = ds->d_Refman;
    t_Dynamic = NULL_OR_VALUE(ds->d, &(ut_M_MyStruct_dynamic._ut_M_Test));
    t = ds->d;
    ut_M_Data_meth(ds, NULL, NULL, NULL, (void*)&(aux_MyStruct_0), &(aux_MyStruct_0_Refman), &dynamic_Void);
    LUMI_inc_ref(aux_MyStruct_0_Refman);
    LUMI_dec_ref(t_Refman);
    t_Refman = aux_MyStruct_0_Refman;
    t_Dynamic = NULL_OR_VALUE(aux_MyStruct_0, &(ut_M_MyStruct_dynamic._ut_M_Test));
    t = aux_MyStruct_0;
    LUMI_inc_ref(dc->d_Refman);
    LUMI_dec_ref(t_Refman);
    t_Refman = dc->d_Refman;
    t_Dynamic = NULL_OR_VALUE(dc->d, &(((ut_M_MyClass_Dynamic*)(dc->d_Dynamic))->_ut_M_Test));
    t = dc->d;
    ut_M_Data_meth(dc, NULL, NULL, NULL, (void*)&(aux_MyClass_0), &(aux_MyClass_0_Refman), (void*)&(aux_MyClass_0_Dynamic));
    LUMI_inc_ref(aux_MyClass_0_Refman);
    LUMI_dec_ref(t_Refman);
    t_Refman = aux_MyClass_0_Refman;
    t_Dynamic = NULL_OR_VALUE(aux_MyClass_0, &(aux_MyClass_0_Dynamic->_ut_M_Test));
    t = aux_MyClass_0;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(aux_MyClass_0_Refman);
    LUMI_dec_ref(aux_MyStruct_0_Refman);
    LUMI_dec_ref(t_Refman);
}
/// @ test-dynamic-5
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Some ut_M_Some;
typedef struct ut_M_Some_Dynamic ut_M_Some_Dynamic;
struct ut_M_Test {
    Dynamic_Del _del;
    void* _self_Dynamic;
    void (*fun)(void* self, void* self_Dynamic);
    void (*test)(void* self, void* self_Dynamic);
};
struct ut_M_Some {
    Bool x;
};
struct ut_M_Some_Dynamic {
    Dynamic_Del _del;
    ut_M_Test _ut_M_Test;
};
void ut_M_Some_fun(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic);
void ut_M_Some_test(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic);
void ut_M_Some_Del(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic);
Return_Code second_M_dummy(void);
ut_M_Some_Dynamic ut_M_Some_dynamic = {
    (Dynamic_Del)ut_M_Some_Del,
    {
        (Dynamic_Del)ut_M_Some_Del,
        &ut_M_Some_dynamic,
        (void (*)(void* self, void* self_Dynamic))ut_M_Some_fun,
        (void (*)(void* self, void* self_Dynamic))ut_M_Some_test
    }
};
Bool second_M_b = 0;
Line_Count LUMI_file0_line_count[9] = {
    -1,-1,-1,-1, 0,-1,-1,-1,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.5.lm", 9, LUMI_file0_line_count}
};
void ut_M_Some_fun(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    ++LUMI_file_coverage[0].line_count[4];
    self->x = true;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Some_test(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    self->x = second_M_b;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Some_Del(ut_M_Some* self, ut_M_Some_Dynamic* self_Dynamic) {
    if (self == NULL) return;
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
#undef LUMI_FUNC_NAME
    LUMI_success &= LUMI_run_test("dummy", second_M_dummy);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
LUMI_block0_cleanup:
    return LUMI_err;
}
TEST_MAIN_FUNC
/// @ test-dynamic-6
typedef struct ut_M_Da ut_M_Da;
typedef struct ut_M_Db ut_M_Db;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Da {
    Dynamic_Del _del;
    void* _self_Dynamic;
    void (*fa)(void* self, void* self_Dynamic);
};
struct ut_M_Db {
    Dynamic_Del _del;
    void* _self_Dynamic;
    void (*fb)(void* self, void* self_Dynamic);
};
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    ut_M_Db _ut_M_Db;
    ut_M_Da _ut_M_Da;
};
void ut_M_Test_fb(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_fa(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del,
    {
        (Dynamic_Del)ut_M_Test_Del,
        &ut_M_Test_dynamic,
        (void (*)(void* self, void* self_Dynamic))ut_M_Test_fb
    },
    {
        (Dynamic_Del)ut_M_Test_Del,
        &ut_M_Test_dynamic,
        (void (*)(void* self, void* self_Dynamic))ut_M_Test_fa
    }
};
void ut_M_Test_fb(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_fa(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
/// @ test-dynamic-e0
cannot add support for non-dynamic type "Error"
/// @ test-dynamic-e1
cannot add support to non-struct type "Error"
/// @ test-dynamic-e2
struct "Some" already supports "Test"
/// @ test-dynamic-e3
missing implementation of method "fun"
/// @ test-dynamic-e4
dynamic type with no dynamic methods "Error"
/// @ test-dynamic-e5
dynamic extension not supported yet
/// @ test-dynamic-e7
indentation too long, expected 4 got 8
/// @ test-dynamic-e8
cannot create variable from type without structure "Test"
/// @ test-dynamic-e9
cannot create variable from type without structure "Test"
/// @ test-dynamic-e10
array of type without structure "Test"
/// @ test-dynamic-e11
dynamic allocation of type without structure "Test"
/// @ test-dynamic-e12
dynamic allocation of type without structure "Test"
/// @ test-dynamic-e12a
expected space after "Error", got "new-line"
/// @ test-dynamic-e13
expected new-line after "Error", got "end-of-file"
/// @ test-dynamic-e14
expected space after "Error", got "{"
/// @ test-dynamic-e15
expected new-line after "Error", got "{"
/// @ test-dynamic-de0
fileds inside dynamics not supported yet
/// @ test-dynamic-de1
cannot yet add support to builtin type "String"
/// @ test-dynamic-de2
cannot add support to non-struct type "Bool"
/// @ test-dynamic-de3
cannot add support to native type "Some"
/// @ test-dynamic-de4
dynamic extension not supported yet
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
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del,
    ut_M_Base_dyn0,
    ut_M_Base_dyn1,
    ut_M_Base_dyn2
};
ut_M_Mid_Dynamic ut_M_Mid_dynamic = {
    {
        (Dynamic_Del)ut_M_Mid_Del,
        (void (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic))ut_M_Mid_dyn0,
        ut_M_Base_dyn1,
        ut_M_Base_dyn2
    },
    ut_M_Mid_dyn3,
    ut_M_Mid_dyn4
};
ut_M_Top_Dynamic ut_M_Top_dynamic = {
    {
        {
            (Dynamic_Del)ut_M_Top_Del,
            (void (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic))ut_M_Top_dyn0,
            (Return_Code (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic))ut_M_Top_dyn1,
            ut_M_Base_dyn2
        },
        (void (*)(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic))ut_M_Top_dyn3,
        ut_M_Mid_dyn4
    },
    ut_M_Top_dyn5
};
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
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del,
    ut_M_Test_fun
};
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
dynamic type with no dynamic methods "Error"
/// @ test-class-e2
expected "dynamic" or "inst" method type, got "error"
/// @ test-class-e3
illegal dynamic in function "meth"
/// @ test-class-e4
too many parameters
/// @ test-class-e5
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
void ut_M_name(String* self, String* text, uint32_t num);
void ut_M_name(String* self, String* text, uint32_t num) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-2
void ut_M_name(String** text, uint32_t* num);
void ut_M_name(String** text, uint32_t* num) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-3
void ut_M_name(Char param, String** out);
void ut_M_name(Char param, String** out) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-4
void ut_M_name(uint32_t* array, uint32_t array_Length);
void ut_M_name(uint32_t* array, uint32_t array_Length) {
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
Return_Code ut_M_name(String* self, uint32_t px, Byte* pu, uint32_t pu_Length, Byte* po, uint32_t po_Length, String** oself, Ref_Manager** oself_Refman, uint32_t* ox, String** ou, Ref_Manager** ou_Refman, String** oo);
Return_Code ut_M_name(String* self, uint32_t px, Byte* pu, uint32_t pu_Length, Byte* po, uint32_t po_Length, String** oself, Ref_Manager** oself_Refman, uint32_t* ox, String** ou, Ref_Manager** ou_Refman, String** oo) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    uint32_t x = 0;
    Byte* u = NULL;
    uint32_t u_Length = 0;
    Byte* b = NULL;
    uint32_t b_Length = 0;
    String* o = NULL;
    String v_Var = {0};
    String* v = NULL;
    String* n = NULL;
    String* aux_String_0 = NULL;
    static Byte aux_Array_0[] = {'c','o','n','s','t','a','n','t',' ','s','t','r','i','n','g','\0',};
    static Byte aux_Array_1[] = {0xbe,0xef,};
    Byte* aux_Array_2 = NULL;
    v = &v_Var;
    INIT_NEW(8, LUMI_block0_cleanup, n, String, 1);
    INIT_NEW(9, LUMI_block0_cleanup, aux_String_0, String, 1);
    String_Del(o, NULL);
    free(o);
    o = aux_String_0;
    aux_String_0 = NULL;
    u_Length = 0x0f;
    u = aux_Array_0;
    b_Length = 0x02;
    b = aux_Array_1;
    if (SAFE_SUM_LARGER(0x02, 0x06, po_Length)) RAISE(12, LUMI_block0_cleanup, slice_index)
    aux_Array_2 = po + 0x02;
    pu_Length = 0x06;
    pu = aux_Array_2;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0, NULL);
    free(aux_String_0);
    String_Del(n, NULL);
    free(n);
    String_Del(v, NULL);
    String_Del(o, NULL);
    free(o);
    free(po);
    return LUMI_err;
}
/// @ test-function-8
typedef struct ut_M_Struct ut_M_Struct;
typedef struct ut_M_Struct_Dynamic ut_M_Struct_Dynamic;
typedef struct ut_M_Class ut_M_Class;
typedef struct ut_M_Class_Dynamic ut_M_Class_Dynamic;
struct ut_M_Struct {
    ut_M_Struct* s;
    ut_M_Struct* as;
    uint32_t as_Length;
    String* astr;
    uint32_t astr_Length;
};
struct ut_M_Struct_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Class {
    ut_M_Class* c;
    ut_M_Class_Dynamic* c_Dynamic;
    ut_M_Class* ac;
    uint32_t ac_Length;
};
struct ut_M_Class_Dynamic {
    Dynamic_Del _del;
    void (*meth)(ut_M_Class* self, ut_M_Class_Dynamic* self_Dynamic);
};
void ut_M_Struct_Del(ut_M_Struct* self, ut_M_Struct_Dynamic* self_Dynamic);
void ut_M_Class_meth(ut_M_Class* self, ut_M_Class_Dynamic* self_Dynamic);
void ut_M_Class_Del(ut_M_Class* self, ut_M_Class_Dynamic* self_Dynamic);
void ut_M_name(ut_M_Struct* ps, ut_M_Class* pc, ut_M_Class_Dynamic* pc_Dynamic, ut_M_Struct* pas, uint32_t pas_Length, ut_M_Class* pac, uint32_t pac_Length);
ut_M_Struct_Dynamic ut_M_Struct_dynamic = {
    (Dynamic_Del)ut_M_Struct_Del
};
ut_M_Class_Dynamic ut_M_Class_dynamic = {
    (Dynamic_Del)ut_M_Class_Del,
    ut_M_Class_meth
};
void ut_M_Struct_Del(ut_M_Struct* self, ut_M_Struct_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ARRAY_DEL(String, self->astr, self->astr_Length)
    free(self->astr);
    ARRAY_DEL(ut_M_Struct, self->as, self->as_Length)
    free(self->as);
    SELF_REF_DEL(ut_M_Struct, s, NULL);
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
void ut_M_name(ut_M_Struct* ps, ut_M_Class* pc, ut_M_Class_Dynamic* pc_Dynamic, ut_M_Struct* pas, uint32_t pas_Length, ut_M_Class* pac, uint32_t pac_Length) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Struct* s = NULL;
    ut_M_Class* c = NULL;
    ut_M_Class_Dynamic* c_Dynamic = NULL;
    ut_M_Struct* as = NULL;
    uint32_t as_Length = 0;
    ut_M_Class* ac = NULL;
    uint32_t ac_Length = 0;
    uint32_t* ai = NULL;
    uint32_t ai_Length = 0;
    String* astr = NULL;
    uint32_t astr_Length = 0;
LUMI_block0_cleanup:
    (void)0;
    ARRAY_DEL(String, astr, astr_Length)
    free(astr);
    free(ai);
    ARRAY_DEL_DYN(ut_M_Class, ac, ac_Length)
    free(ac);
    ARRAY_DEL(ut_M_Struct, as, as_Length)
    free(as);
    if (c_Dynamic != NULL) c_Dynamic->_del(c, c_Dynamic);
    free(c);
    ut_M_Struct_Del(s, NULL);
    free(s);
    ARRAY_DEL_DYN(ut_M_Class, pac, pac_Length)
    free(pac);
    ARRAY_DEL(ut_M_Struct, pas, pas_Length)
    free(pas);
    if (pc_Dynamic != NULL) pc_Dynamic->_del(pc, pc_Dynamic);
    free(pc);
    ut_M_Struct_Del(ps, NULL);
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
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del,
    ut_M_Test_meth
};
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
void ut_M_name(String* ai, uint32_t ai_Length, uint32_t ai_Value_length, uint32_t** ao, uint32_t* ao_Length, uint32_t* ao_Value_length);
void ut_M_name(String* ai, uint32_t ai_Length, uint32_t ai_Value_length, uint32_t** ao, uint32_t* ao_Length, uint32_t* ao_Value_length) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-function-11
Return_Code ut_M_name(String** so);
Return_Code ut_M_name(String** so) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    String* aux_String_0 = NULL;
    INIT_NEW(2, LUMI_block0_cleanup, aux_String_0, String, 1);
    String_Del(*so, NULL);
    free(*so);
    *so = aux_String_0;
    aux_String_0 = NULL;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0, NULL);
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
    String* s = NULL;
    CHECK_REF(3, LUMI_block0_cleanup, s)
    String_clear(s);
LUMI_block0_cleanup:
    (void)0;
    String_Del(s, NULL);
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
/// @ test-function-e33
adding "->()" without outputs
/// @@ test-members
/// @ test-members-0
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
    String* str;
    Ref_Manager* str_Refman;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->str_Refman);
}
/// @ test-members-1
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_name(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_name(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    self->x = 0x02;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
/// @ test-members-2
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_name(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_name(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    uint32_t x = 0;
    x = self->x;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
/// @ test-members-3
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
/// @ test-members-4
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
/// @ test-members-5
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
/// @ test-members-6
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
/// @ test-members-7
typedef struct ut_M_Test1 ut_M_Test1;
typedef struct ut_M_Test1_Dynamic ut_M_Test1_Dynamic;
typedef struct ut_M_Test2 ut_M_Test2;
typedef struct ut_M_Test2_Dynamic ut_M_Test2_Dynamic;
struct ut_M_Test1 {
    uint32_t name;
};
struct ut_M_Test1_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test2 {
    uint32_t fun;
};
struct ut_M_Test2_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test1_fun(ut_M_Test1* self);
void ut_M_Test1_Del(ut_M_Test1* self, ut_M_Test1_Dynamic* self_Dynamic);
void ut_M_Test2_name(ut_M_Test2* self);
void ut_M_Test2_Del(ut_M_Test2* self, ut_M_Test2_Dynamic* self_Dynamic);
void ut_M_fun(void);
ut_M_Test1_Dynamic ut_M_Test1_dynamic = {
    (Dynamic_Del)ut_M_Test1_Del
};
ut_M_Test2_Dynamic ut_M_Test2_dynamic = {
    (Dynamic_Del)ut_M_Test2_Del
};
uint32_t ut_M_name = 0;
void ut_M_Test1_fun(ut_M_Test1* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test1_Del(ut_M_Test1* self, ut_M_Test1_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Test2_name(ut_M_Test2* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test2_Del(ut_M_Test2* self, ut_M_Test2_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_fun(void) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-members-8
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_fun(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
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
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
/// @ test-members-9
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_fun(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_fun(ut_M_Test* self, String* s, uint32_t* x);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Test_fun(ut_M_Test* self, String* s, uint32_t* x) {
    unsigned LUMI_loop_depth = 1;
    String_length(s, &(*x));
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-members-11
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_new(ut_M_Test* self, uint32_t x);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
    static Byte aux_Array_0[] = {'s','o','m','e',' ','e','r','r','o','r','\0',};
    USER_RAISE(2, LUMI_block0_cleanup, aux_Array_0, 0x0a)
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ test-return-3
Return_Code ut_M_name(String* arr, uint32_t arr_Length);
Return_Code ut_M_name(String* arr, uint32_t arr_Length) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Byte* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    if (0x03 >= arr_Length) RAISE(2, LUMI_block0_cleanup, slice_index)
    String_bytes(arr + 0x03, &(aux_Array_0), &(aux_Array_0_Length));
    USER_RAISE(2, LUMI_block0_cleanup, aux_Array_0, aux_Array_0_Length)
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ test-return-4
Byte* s = NULL;
    uint32_t s_Length = 0;
    Ref_Manager* s_Refman = NULL;
    CHECK_REFMAN(2, LUMI_block0_cleanup, s_Refman)
    USER_RAISE(2, LUMI_block0_cleanup, s, s_Length)
/// @ test-return-5
USER_RAISE(1, LUMI_block0_cleanup, NULL, 0)
/// @ test-return-e0
expected new-line after "return", got "("
/// @ test-return-e1
expected space or new-line after "raise!", got "("
/// @ test-return-e2
cannot assign "Int" into "Array"
/// @ test-return-e3
expected ! after "raise", got "new-line"
/// @ test-return-e4
non matching array subtypes "Int" and "Byte"
/// @@ test-code-variables
/// @ test-code-variables-0
uint32_t x = 0;
/// @ test-code-variables-1
String* s = NULL;
/// @ test-code-variables-2
uint32_t* a = NULL;
    uint32_t a_Length = 0;
/// @ test-code-variables-3
ut_M_Test* tt = NULL;
/// @ test-code-variables-4
Byte s[0x0c] = {0};
    /* initializing s */
/// @ test-code-variables-5
uint32_t a[0x0c] = {0};
    /* initializing a */
/// @ test-code-variables-6
ut_M_Test a[0x0c] = {0};
    /* initializing a */
/// @ test-code-variables-7
Byte sa[0x0c * 0x07] = {0};
    /* initializing sa */
/// @ test-code-variables-8
Byte* s = NULL;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, s, Byte, 0x0c, 1);
    free(ut_M_buff);
    ut_M_buff_Length = 0x0c;
    ut_M_buff = s;
    s = NULL;
/// @ test-code-variables-9
ut_M_Ta a[0x0c] = {0};
    /* initializing a */
/// @ test-code-variables-10
uint32_t* a = NULL;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, a, uint32_t, 0x0c, 1);
/// @ test-code-variables-11
Byte* sa = NULL;
    sa_Value_length = 0x07;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, sa, Byte, 0x0c, sa_Value_length);
/// @ test-code-variables-12
Byte aa[0x03 * 0x04 * 0x05] = {0};
    /* initializing aa */
/// @ test-code-variables-13
Byte* aa = NULL;
    aa_Value_length = 0x04;
    aa_Value_value_length = 0x05;
    INIT_NEW_ARRAY(1, LUMI_block0_cleanup, aa, Byte, 0x03, aa_Value_length * aa_Value_value_length);
/// @ test-code-variables-14
Return_Code ut_M_fun(void);
Return_Code ut_M_fun(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Byte sv[0x04] = {0};
    /* initializing sv */
    if (0x01 > 0x02) {
        Byte* su = NULL;
        uint32_t su_Length = 0;
        Byte* aux_Array_0 = NULL;
        aux_Array_0 = sv + 0x01;
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
sequence length never positive with maximum value of "-2"
/// @@ test-initialize
/// @ test-initialize-0
ut_M_Tb* aux_Tb_0 = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = &ut_M_Tb_dynamic;
    INIT_NEW(1, LUMI_block0_cleanup, aux_Tb_0, ut_M_Tb, 1);
    LUMI_err = ut_M_Tb_new(aux_Tb_0, aux_Tb_0_Dynamic, ut_M_i);
    CHECK(1, LUMI_block0_cleanup)
    if (ut_M_tb_Dynamic != NULL) ut_M_tb_Dynamic->_base._base._del(ut_M_tb, ut_M_tb_Dynamic);
    LUMI_owner_dec_ref(ut_M_tb_Refman);
    ut_M_tb_Dynamic = aux_Tb_0_Dynamic;
    ut_M_tb = aux_Tb_0;
    aux_Tb_0 = NULL;
    aux_Tb_0_Dynamic = NULL;
    INIT_NEW_REFMAN(1, LUMI_block0_cleanup, ut_M_tb)
/// @ test-initialize-1
String* aux_String_0 = NULL;
    Byte* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    INIT_NEW(1, LUMI_block0_cleanup, aux_String_0, String, 1);
    str = aux_String_0;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_arr[0] <= 0) RAISE(2, LUMI_block0_cleanup, array_too_short)
    INIT_NEW_LEN_ARRAY(2, LUMI_block0_cleanup, aux_Array_0, Byte, ut_M_arr[0], 1);
    free(ut_M_buff);
    ut_M_buff_Length = aux_Array_0_Length;
    ut_M_buff = aux_Array_0;
    aux_Array_0 = NULL;
/// @ test-initialize-2
uint32_t* a = NULL;
    uint32_t a_Length = 0;
    uint32_t* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_arr[0] <= 0) RAISE(1, LUMI_block0_cleanup, array_too_short)
    INIT_NEW_LEN_ARRAY(1, LUMI_block0_cleanup, aux_Array_0, uint32_t, ut_M_arr[0], 1);
    a_Length = aux_Array_0_Length;
    a = aux_Array_0;
    aux_Array_0 = NULL;
/// @ test-initialize-3
ut_M_Test* a = NULL;
    uint32_t a_Length = 0;
    ut_M_Test* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_arr[0] <= 0) RAISE(1, LUMI_block0_cleanup, array_too_short)
    INIT_NEW_LEN_ARRAY(1, LUMI_block0_cleanup, aux_Array_0, ut_M_Test, ut_M_arr[0], 1);
    a_Length = aux_Array_0_Length;
    a = aux_Array_0;
    aux_Array_0 = NULL;
/// @ test-initialize-4
String* sa = NULL;
    uint32_t sa_Length = 0;
    Byte* ba = NULL;
    uint32_t ba_Length = 0;
    uint32_t ba_Value_length = 0;
    String* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    Byte* aux_Array_1 = NULL;
    uint32_t aux_Array_1_Length = 0;
    uint32_t aux_Array_1_Value_length = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_arr[0] <= 0) RAISE(1, LUMI_block0_cleanup, array_too_short)
    INIT_NEW_LEN_ARRAY(1, LUMI_block0_cleanup, aux_Array_0, String, ut_M_arr[0], 1);
    sa_Length = aux_Array_0_Length;
    sa = aux_Array_0;
    aux_Array_0 = NULL;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_arr[0] <= 0) RAISE(2, LUMI_block0_cleanup, array_too_short)
    aux_Array_1_Value_length = ut_M_arr[0x01];
    INIT_NEW_LEN_ARRAY(2, LUMI_block0_cleanup, aux_Array_1, Byte, ut_M_arr[0], aux_Array_1_Value_length);
    ba_Length = aux_Array_1_Length;
    ba_Value_length = aux_Array_1_Value_length;
    ba = aux_Array_1;
    aux_Array_1 = NULL;
/// @ test-initialize-5
uint32_t x = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    x = ut_M_arr[0];
/// @ test-initialize-6
String* s = NULL;
    Byte* bf = NULL;
    uint32_t bf_Length = 0;
    s = ut_M_ostr;
    bf_Length = ut_M_buff_Length;
    bf = ut_M_buff;
/// @ test-initialize-7
String s_Var = {0};
    String* s = NULL;
    Byte* bf = NULL;
    uint32_t bf_Length = 0;
    static Byte aux_Array_0[] = {'s','o','m','e',' ','s','t','r','i','n','g','\0',};
    static Byte aux_Array_1[] = {0xfa,0xde,0x00,0xbe,0xaf,};
    s = &s_Var;
    LUMI_err = String_new(s, aux_Array_0, 0x0b);
    CHECK(1, LUMI_block0_cleanup)
    bf_Length = 0x05;
    bf = aux_Array_1;
/// @ test-initialize-8
String* s = NULL;
    Byte* bf = NULL;
    uint32_t bf_Length = 0;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    INIT_NEW(1, LUMI_block0_cleanup, s, String, 1);
    LUMI_err = String_new(s, ut_M_buff, ut_M_buff_Length);
    CHECK(1, LUMI_block0_cleanup)
    if (ut_M_i <= 0) RAISE(2, LUMI_block0_cleanup, array_too_short)
    INIT_NEW_LEN_ARRAY(2, LUMI_block0_cleanup, bf, Byte, ut_M_i, 1);
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
    if (ut_M_tb_Dynamic != NULL) ut_M_tb_Dynamic->_base._base._del(ut_M_tb, ut_M_tb_Dynamic);
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
String* sa = NULL;
    uint32_t sa_Length = 0;
    uint32_t sa_Value_length = 0;
    Byte* ba = NULL;
    uint32_t ba_Length = 0;
    uint32_t ba_Value_length = 0;
    uint32_t ba_Value_value_length = 0;
    String* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    uint32_t aux_Array_0_Value_length = 0;
    Byte* aux_Array_1 = NULL;
    uint32_t aux_Array_1_Length = 0;
    uint32_t aux_Array_1_Value_length = 0;
    uint32_t aux_Array_1_Value_value_length = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_arr[0] <= 0) RAISE(1, LUMI_block0_cleanup, array_too_short)
    aux_Array_0_Value_length = ut_M_arr[0x01];
    INIT_NEW_LEN_ARRAY(1, LUMI_block0_cleanup, aux_Array_0, String, ut_M_arr[0], aux_Array_0_Value_length);
    sa_Length = aux_Array_0_Length;
    sa_Value_length = aux_Array_0_Value_length;
    sa = aux_Array_0;
    aux_Array_0 = NULL;
    CHECK_REF_REFMAN(2, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    if (ut_M_arr[0] <= 0) RAISE(2, LUMI_block0_cleanup, array_too_short)
    aux_Array_1_Value_length = ut_M_arr[0x01];
    aux_Array_1_Value_value_length = ut_M_arr[0x02];
    INIT_NEW_LEN_ARRAY(2, LUMI_block0_cleanup, aux_Array_1, Byte, ut_M_arr[0], aux_Array_1_Value_length * aux_Array_1_Value_value_length);
    ba_Length = aux_Array_1_Length;
    ba_Value_length = aux_Array_1_Value_length;
    ba_Value_value_length = aux_Array_1_Value_value_length;
    ba = aux_Array_1;
    aux_Array_1 = NULL;
/// @ test-initialize-16
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_MyStruct_Dynamic ut_M_MyStruct_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_MyStruct_Dynamic {
    Dynamic_Del _del;
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic);
void ut_M_get(ut_M_MyStruct** a);
ut_M_MyStruct_Dynamic ut_M_MyStruct_dynamic = {
    (Dynamic_Del)ut_M_MyStruct_Del
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic) {
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
    ut_M_MyStruct_Del(aux_MyStruct_0, NULL);
    free(aux_MyStruct_0);
    ut_M_MyStruct_Del(b, NULL);
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_new(ut_M_Test* self, uint32_t x);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_fun(void);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_new(ut_M_Test* self, uint32_t x) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
    ut_M_Test_Del(t, NULL);
}
/// @ test-initialize-21
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Base {
    uint32_t x;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test {
    ut_M_Base _base;
    uint32_t y;
};
struct ut_M_Test_Dynamic {
    ut_M_Base_Dynamic _base;
};
void ut_M_Base_new(ut_M_Base* self);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Test_new(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        (Dynamic_Del)ut_M_Test_Del
    }
};
void ut_M_Base_new(ut_M_Base* self) {
    unsigned LUMI_loop_depth = 1;
    self->x = 0x02;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Test_new(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Base_new(&(self->_base));
    self->y = 0x03;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
}
/// @ test-initialize-22
if (ut_M_b) {
        ut_M_Test* nt = NULL;
        ut_M_Ta* nta = NULL;
        ut_M_Ta_Dynamic* nta_Dynamic = &ut_M_Ta_dynamic;
        ut_M_Tb* ntb = NULL;
        ut_M_Tb_Dynamic* ntb_Dynamic = &ut_M_Tb_dynamic;
        ut_M_Tc* ntc = NULL;
        ut_M_Tc_Dynamic* ntc_Dynamic = &ut_M_Tc_dynamic;
        INIT_NEW(2, LUMI_block1_cleanup, nt, ut_M_Test, 1);
        INIT_NEW(3, LUMI_block1_cleanup, nta, ut_M_Ta, 1);
        INIT_NEW(4, LUMI_block1_cleanup, ntb, ut_M_Tb, 1);
        LUMI_err = ut_M_Tb_new(ntb, ntb_Dynamic, 0x03);
        CHECK(4, LUMI_block1_cleanup)
        INIT_NEW(5, LUMI_block1_cleanup, ntc, ut_M_Tc, 1);
        LUMI_err = ut_M_Tb_new(&(ntc->_base), &(ntc_Dynamic->_base), 0x04);
        CHECK(5, LUMI_block1_cleanup)
    LUMI_block1_cleanup:
        (void)0;
        if (ntc_Dynamic != NULL) ntc_Dynamic->_base._base._base._del(ntc, ntc_Dynamic);
        free(ntc);
        if (ntb_Dynamic != NULL) ntb_Dynamic->_base._base._del(ntb, ntb_Dynamic);
        free(ntb);
        if (nta_Dynamic != NULL) nta_Dynamic->_base._del(nta, nta_Dynamic);
        free(nta);
        ut_M_Test_Del(nt, NULL);
        free(nt);
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-initialize-e0
dynamic allocation of primitive type "Int"
/// @ test-initialize-e1
missing length for array
/// @ test-initialize-e2
missing length for array
/// @ test-initialize-e3
missing length for array
/// @ test-initialize-e4
missing length for array
/// @ test-initialize-e5
missing subtype for array
/// @ test-initialize-e6
missing subtype for array
/// @ test-initialize-e7
missing subtype for array
/// @ test-initialize-e8
got "Int" expression, expected "Type Name"
/// @ test-initialize-e9
generic arrays not supported
/// @ test-initialize-e10
expected "}" after sub-types, got "new-line"
/// @ test-initialize-e11
expected "}" after sub-types, got "new-line"
/// @ test-initialize-e12
unknown symbol "error"
/// @ test-initialize-e13
expected integer as array length, got "Array"
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
expected "}" after sub-types, got ":"
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
sequence length never positive with maximum value of "-2"
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
        ut_M_Test_Del(tt, NULL);
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
        Byte ba[0x04] = {0};
        /* initializing ba */
        if (ut_M_b) {
            Byte bb[0x04] = {0};
            /* initializing bb */
        LUMI_block2_cleanup:
            (void)0;
        }
        else {
            if (ut_M_b) {
                Byte bc[0x04] = {0};
                /* initializing bc */
            LUMI_block5_cleanup:
                (void)0;
            }
            else {
                Byte bd[0x04] = {0};
                /* initializing bd */
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
            Byte be[0x04] = {0};
            /* initializing be */
        LUMI_block10_cleanup:
            (void)0;
        }
        else {
            Byte bf[0x04] = {0};
            /* initializing bf */
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
        Byte ba[0x04] = {0};
        LUMI_loop_depth = 3;
        /* initializing ba */
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
            Byte bb[0x04] = {0};
            LUMI_loop_depth = 5;
            /* initializing bb */
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
                Byte bc[0x04] = {0};
                LUMI_loop_depth = 7;
                /* initializing bc */
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
        String_length(ut_M_ostr, &(aux_Int_0));
        aux_Int_2 = (uint64_t)aux_Int_0 + 0x02;
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
got "Void Expression" expression, expected "Bool"
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
    String_length(ut_M_ostr, &(aux_Int_0));
    aux_Int_1 = (uint64_t)aux_Int_0 + 0x02;
    do {
        uint64_t n = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_2 < aux_Int_1)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Int_2;
        aux_Int_2 += 0x01;
        ut_M_i = n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-2
Byte* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    uint32_t aux_Int_0 = 0;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    aux_Array_0_Length = ut_M_buff_Length;
    aux_Array_0 = ut_M_buff;
    do {
        Byte y = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < aux_Array_0_Length)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        y = aux_Array_0[aux_Int_0];
        aux_Int_0 += 0x01;
        ut_M_bt = y;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-3
uint32_t* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    uint32_t aux_Int_0 = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_arr, ut_M_arr_Refman)
    aux_Array_0_Length = ut_M_arr_Length;
    aux_Array_0 = ut_M_arr;
    do {
        uint32_t n = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < aux_Array_0_Length)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Array_0[aux_Int_0];
        aux_Int_0 += 0x01;
        ut_M_i = n;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-4
String* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    uint32_t aux_Int_0 = 0;
    Byte* aux_Array_1 = NULL;
    uint32_t aux_Array_1_Length = 0;
    uint32_t aux_Array_1_Value_length = 0;
    uint32_t aux_Int_1 = 0;
    CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_sarr, ut_M_sarr_Refman)
    aux_Array_0_Length = ut_M_sarr_Length;
    aux_Array_0 = ut_M_sarr;
    do {
        String* s = NULL;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < aux_Array_0_Length)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        s = aux_Array_0 + aux_Int_0;
        aux_Int_0 += 0x01;
        String_clear(s);
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    CHECK_REF_REFMAN(3, LUMI_block0_cleanup, ut_M_barr, ut_M_barr_Refman)
    aux_Array_1_Length = ut_M_barr_Length;
    aux_Array_1_Value_length = ut_M_barr_Value_length;
    aux_Array_1 = ut_M_barr;
    do {
        Byte* bf = NULL;
        uint32_t bf_Length = 0;
        Byte* aux_Array_2 = NULL;
        uint32_t aux_Array_2_Length = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_1 < aux_Array_1_Length)) { LUMI_loop_depth = 1; goto LUMI_block2_cleanup; }
        aux_Array_2 = aux_Array_1 + aux_Int_1 * aux_Array_1_Value_length;
        aux_Array_2_Length = aux_Array_1_Value_length;
        bf_Length = aux_Array_2_Length;
        bf = aux_Array_2;
        aux_Int_1 += 0x01;
        ut_M_i = bf_Length;
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
        Byte ba[0x04] = {0};
        uint8_t n = 0;
        Byte* aux_Array_0 = NULL;
        uint32_t aux_Array_0_Length = 0;
        uint32_t aux_Int_1 = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < 0x06)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        n = aux_Int_0;
        aux_Int_0 += 0x01;
        /* initializing ba */
        LUMI_loop_depth = 1; goto LUMI_block1_cleanup;
        LUMI_loop_depth = 2; goto LUMI_block1_cleanup;
        if (ut_M_b) {
            LUMI_loop_depth = 0; goto LUMI_block2_cleanup;
        LUMI_block2_cleanup:
            (void)0;
        }
        if (LUMI_loop_depth < 3) goto LUMI_block1_cleanup;
        CHECK_REF(7, LUMI_block1_cleanup, ut_M_buff)
        aux_Array_0_Length = ut_M_buff_Length;
        aux_Array_0 = ut_M_buff;
        do {
            Byte bb[0x04] = {0};
            Byte ch = 0;
            LUMI_loop_depth = 5;
            if (!(aux_Int_1 < aux_Array_0_Length)) { LUMI_loop_depth = 3; goto LUMI_block3_cleanup; }
            ch = aux_Array_0[aux_Int_1];
            aux_Int_1 += 0x01;
            /* initializing bb */
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
Byte* bf = NULL;
    uint32_t bf_Length = 0;
    static Byte aux_Array_0[] = {0xbe,0xaf,};
    Byte* aux_Array_1 = NULL;
    uint32_t aux_Array_1_Length = 0;
    uint32_t aux_Int_0 = 0;
    bf_Length = 0x02;
    bf = aux_Array_0;
    aux_Array_1_Length = bf_Length;
    aux_Array_1 = bf;
    do {
        Byte y = 0;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < aux_Array_1_Length)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        y = aux_Array_1[aux_Int_0];
        aux_Int_0 += 0x01;
        ut_M_bt = y;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-10
String sa[0x03] = {0};
    Byte ba[0x03 * 0x04] = {0};
    String* aux_Array_0 = NULL;
    uint32_t aux_Int_0 = 0;
    Byte* aux_Array_1 = NULL;
    uint32_t aux_Int_1 = 0;
    /* initializing sa */
    aux_Array_0 = sa;
    do {
        String* s = NULL;
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < 0x03)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        s = aux_Array_0 + aux_Int_0;
        aux_Int_0 += 0x01;
        String_clear(s);
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    /* initializing ba */
    aux_Array_1 = ba;
    do {
        Byte* bf = NULL;
        Byte* aux_Array_2 = NULL;
        LUMI_loop_depth = 3;
        if (!(aux_Int_1 < 0x03)) { LUMI_loop_depth = 1; goto LUMI_block2_cleanup; }
        aux_Array_2 = aux_Array_1 + aux_Int_1 * 0x04;
        bf = aux_Array_2;
        aux_Int_1 += 0x01;
        ut_M_i = 0x04;
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
Byte* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    uint32_t aux_Int_0 = 0;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_buff)
    aux_Array_0_Length = ut_M_buff_Length;
    aux_Array_0 = ut_M_buff;
    do {
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < aux_Array_0_Length)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        aux_Int_0 += 0x01;
        ut_M_i = 0x01;
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-for-loop-13
uint32_t aux_Int_0 = 0;
    uint32_t aux_Int_1 = 0;
    CHECK_REF(1, LUMI_block0_cleanup, ut_M_ostr)
    String_length(ut_M_ostr, &(aux_Int_0));
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
    aux_Int_0 = (uint64_t)ut_M_i - 0x04;
    do {
        LUMI_loop_depth = 3;
        if (!((int64_t)aux_Int_1 < (int64_t)aux_Int_0)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
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
cannot iterate type with no "step" named method - "Void Expression"
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
{Byte* LUMI_expected_error_prev;
    size_t LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error_prev = LUMI_expected_error;
    LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
    LUMI_expected_error = (Byte*)"expected error";
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
{Byte* LUMI_expected_error_prev;
    size_t LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error_prev = LUMI_expected_error;
    LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
    LUMI_expected_error = (Byte*)"expected error in the function";
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
{Byte* LUMI_expected_error_prev;
    size_t LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error_prev = LUMI_expected_error;
    LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
    LUMI_expected_error = (Byte*)"expected error in new line";
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
        Byte bf[0x04] = {0};
        Byte* aux_Array_0 = NULL;
        uint8_t aux_Int_0 = 0;
        /* initializing bf */
        TEST_ASSERT(3, LUMI_block1_cleanup, ut_M_b)
        ++LUMI_trace_ignore_count;
        if (SAFE_SUM_LARGER(ut_M_i, 0x02, 0x04)) RAISE(4, LUMI_block2_cleanup, slice_index)
        aux_Array_0 = bf + ut_M_i;
        --LUMI_trace_ignore_count;
        TEST_FAIL(4, LUMI_block1_cleanup, 16, "error not raised")
        LUMI_block2_cleanup:
        (void)0;
        --LUMI_trace_ignore_count;
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        do {
            Byte* aux_Array_1 = NULL;
            LUMI_loop_depth = 3;
            if (!(aux_Int_0 < 0x03)) { LUMI_loop_depth = 1; goto LUMI_block3_cleanup; }
            aux_Int_0 += 0x01;
            ++LUMI_trace_ignore_count;
            if (SAFE_SUM_LARGER(ut_M_i, 0x02, 0x04)) RAISE(6, LUMI_block4_cleanup, slice_index)
            aux_Array_1 = bf + ut_M_i;
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_meth(ut_M_Test* self, uint32_t x);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_meth_Mock(ut_M_Test* self, uint32_t x);
Bool ut_M_Test_meth_Mock_active = true;
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_meth(ut_M_Test* self, uint32_t x) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test_meth_Mock(self, x);
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del,
    ut_M_Test_meth_Mock
};
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_meth(ut_M_Test* self, uint32_t x, uint32_t* y);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_meth_Mock(ut_M_Test* self, uint32_t x, uint32_t* y);
Bool ut_M_Test_meth_Mock_active = true;
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_meth(ut_M_Test* self, uint32_t x, uint32_t* y) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test_meth_Mock(self, x, &(*y));
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del,
    ut_M_Test_meth_Mock
};
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
Return_Code sys_M_print_Mock(Byte* text, uint32_t text_Length);
Bool sys_M_print_Mock_active = true;
Return_Code ut_M_fun(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    static Byte aux_Array_0[] = {'m','o','c','k',' ','p','r','i','n','t','\0',};
    static Byte aux_Array_1[] = {'r','e','a','l','l','y',' ','p','r','i','n','t','\0',};
    LUMI_err = sys_M_print_Mock(aux_Array_0, 0x0a);
    CHECK(2, LUMI_block0_cleanup)
    LUMI_err = sys_M_print(aux_Array_1, 0x0c);
    CHECK(3, LUMI_block0_cleanup)
    sys_M_print_Mock_active = false;
    sys_M_print_Mock_active = true;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
Return_Code sys_M_print_Mock(Byte* text, uint32_t text_Length) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    if (!sys_M_print_Mock_active) { return sys_M_print(text, text_Length); }
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ test-testing-m8
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_new(ut_M_Test* self, uint32_t x);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_new_Mock(ut_M_Test* self, uint32_t x);
Bool ut_M_Test_new_Mock_active = true;
void ut_M_fun(void);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_new(ut_M_Test* self, uint32_t x) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
    ut_M_Test_Del(t, NULL);
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
        static Byte aux_Array_0[] = {'t','e','x','t','\0',};
        ++LUMI_trace_ignore_count;
        ++LUMI_file_coverage[0].line_count[13];
        x = 0;
        ++LUMI_file_coverage[0].line_count[14];
        LUMI_err = sys_M_print(aux_Array_0, 0x04);
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    String* s;
    Ref_Manager* s_Refman;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_MockDel(Ref self);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
non matching types "Char" and "Int"
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
no '"' around string literal " "error""
/// @ test-testing-e21
no '"' around string literal "error"
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_fun(void);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del,
    ut_M_Test_meth
};
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
    String* s = NULL;
    uint32_t* a = NULL;
    uint32_t a_Length = 0;
    ut_M_Test* t = NULL;
    ut_M_Test_Dynamic* t_Dynamic = NULL;
    i = external(0x05, s, a, t);
    i = ((uint64_t)0x02 * external(0x05, s, a, t)) + 0x03;
    external(0x05, s, a, t);
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_call(void);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
    *x = (uint64_t)VALUE + BYTE;
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
void ut_M_get(Native* n);
void ut_M_call(void);
void ut_M_get(Native* n) {
    unsigned LUMI_loop_depth = 1;
    *n = get_native();
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_call(void) {
    unsigned LUMI_loop_depth = 1;
    Native n;
    set_native(native_var);
    ut_M_get(&(n));
    set_native(n);
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-native-t1
void ut_M_call(void);
void ut_M_call(void) {
    unsigned LUMI_loop_depth = 1;
    SOME_External_type n;
    n = SOME_External_get_func();
    SOME_External_set_func(n);
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-native-s0
void ut_M_fun(c_native_type_t in, c_native_type_t* out);
void ut_M_fun(c_native_type_t in, c_native_type_t* out) {
    unsigned LUMI_loop_depth = 1;
    c_native_type_t n = {0};
    c_native_type_t def = {0};
    n = in;
    *out = n;
    *out = ext(in);
    if ((uint64_t)(in.c_y_field + (*out).c_x_field) > 0x64) {
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    in.c_x_field = 0;
    in.c_y_field = 0;
    *out = def;
    ext(def);
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-native-s1
Return_Code ut_M_fun(Test t, TestRef r, Native in, Native* out);
Return_Code ut_M_fun(Test t, TestRef r, Native in, Native* out) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    CHECK_REF(10, LUMI_block0_cleanup, in.n)
    if (((in.x == 0) && (in.t.x == 0)) && (in.n->x == 0)) {
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    in.x = 0;
    in.t = t;
    in.t.x = 0;
    in.r = r;
    CHECK_REF(15, LUMI_block0_cleanup, in.n)
    in.n->x = 0;
    cdef_M_Pointer_set_point_to(in.n, in, (Generic_Type_Dynamic*)&Native_dynamic);
    *out = cdef_M_Pointer_get_pointed_at(in.n, 0);
    *out = in;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
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
no '"' around string literal "native.h"
/// @ test-native-ef0
redefinition of function "error"
/// @ test-native-ef1
error raising native function
/// @ test-native-ef2
output arguments to native function
/// @ test-native-ef3
expected space after "return type", got "new-line"
/// @ test-native-ef4
owner argument to native function
/// @ test-native-ef5
managed argument to native function
/// @ test-native-ef6
owner argument to native function
/// @ test-native-ef7
argument "s" access should not be "s-var" for non-primitive type "String"
/// @ test-native-ef8
output argument in native function call
/// @ test-native-ef9
no '"' around string literal "error"
/// @ test-native-ef10
user output to native function with non struct type "Array"
/// @ test-native-ef11
user output to native function with non struct type "Array"
/// @ test-native-ef12
user output to native function with non struct type "Error"
/// @ test-native-ev0
only primitive types supported for native variable, got "String"
/// @ test-native-ev1
no '"' around string literal "error"
/// @ test-native-ec0
no '"' around string literal "error"
/// @ test-native-ec1
Only numeric typed native constant supported, got "Bool"
/// @ test-native-ec2
sequence length is not constant
/// @ test-native-et0
no '"' around string literal "error"
/// @ test-native-et1
using invalid reference "n"
/// @ test-native-es0
unknown keyword "user"
/// @ test-native-es1
unknown keyword "func"
/// @ test-native-es2
only primitive types supported for native variable, got "String"
/// @ test-native-eb0
no '"' around string literal "#define error"
/// @ test-native-eb1
no '"' around string literal "#ifdef error"
/// @@ test-parameter-type
/// @ test-parameter-type-0
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
Return_Code ut_M_Test_set(ut_M_Test* self, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
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
    ut_M_Test_Del(t, NULL);
    free(t);
    LUMI_dec_ref(x_Refman);
    LUMI_dec_ref(item_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
/// @ test-parameter-type-1
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    Generic_Type* item;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_get(ut_M_Test* self, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_get(ut_M_Test* self, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    *item_Dynamic = self->item_Dynamic;
    *item = self->item;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    if (self->item_Dynamic != NULL) self->item_Dynamic->_del(self->item, self->item_Dynamic);
    free(self->item);
}
/// @ test-parameter-type-2
typedef struct ut_M_StructA ut_M_StructA;
typedef struct ut_M_StructA_Dynamic ut_M_StructA_Dynamic;
typedef struct ut_M_StructB ut_M_StructB;
typedef struct ut_M_StructB_Dynamic ut_M_StructB_Dynamic;
typedef struct ut_M_StructC ut_M_StructC;
typedef struct ut_M_StructC_Dynamic ut_M_StructC_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_StructA {
    uint32_t x;
};
struct ut_M_StructA_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_StructB {
    uint32_t x;
};
struct ut_M_StructB_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_StructC {
    uint32_t x;
};
struct ut_M_StructC_Dynamic {
    Dynamic_Del _del;
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
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_StructA_Del(ut_M_StructA* self, ut_M_StructA_Dynamic* self_Dynamic);
void ut_M_StructB_Del(ut_M_StructB* self, ut_M_StructB_Dynamic* self_Dynamic);
void ut_M_StructC_Del(ut_M_StructC* self, ut_M_StructC_Dynamic* self_Dynamic);
void ut_M_Test_set(ut_M_Test* self, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Generic_Type* second, Ref_Manager* second_Refman, Generic_Type_Dynamic* second_Dynamic, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_use(ut_M_StructA* first, Ref_Manager* first_Refman, ut_M_StructB* second, Ref_Manager* second_Refman, ut_M_StructC* third, Ref_Manager* third_Refman);
ut_M_StructA_Dynamic ut_M_StructA_dynamic = {
    (Dynamic_Del)ut_M_StructA_Del
};
ut_M_StructB_Dynamic ut_M_StructB_dynamic = {
    (Dynamic_Del)ut_M_StructB_Del
};
ut_M_StructC_Dynamic ut_M_StructC_dynamic = {
    (Dynamic_Del)ut_M_StructC_Del
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_StructA_Del(ut_M_StructA* self, ut_M_StructA_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_StructB_Del(ut_M_StructB* self, ut_M_StructB_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_StructC_Del(ut_M_StructC* self, ut_M_StructC_Dynamic* self_Dynamic) {
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
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
    t->first_Dynamic = (Generic_Type_Dynamic*)&ut_M_StructA_dynamic;
    t->first = first;
    LUMI_inc_ref(second_Refman);
    LUMI_dec_ref(t->second_Refman);
    t->second_Refman = second_Refman;
    t->second_Dynamic = (Generic_Type_Dynamic*)&ut_M_StructB_dynamic;
    t->second = second;
    LUMI_inc_ref(third_Refman);
    LUMI_dec_ref(t->third_Refman);
    t->third_Refman = third_Refman;
    t->third_Dynamic = (Generic_Type_Dynamic*)&ut_M_StructC_dynamic;
    t->third = third;
    ut_M_Test_set(t, first, first_Refman, (Generic_Type_Dynamic*)&ut_M_StructA_dynamic, second, second_Refman, (Generic_Type_Dynamic*)&ut_M_StructB_dynamic, third, third_Refman, (Generic_Type_Dynamic*)&ut_M_StructC_dynamic);
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t, NULL);
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
}
/// @ test-parameter-type-3
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Base {
    uint32_t x;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test {
    ut_M_Base _base;
};
struct ut_M_Test_Dynamic {
    ut_M_Base_Dynamic _base;
};
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        (Dynamic_Del)ut_M_Test_Del
    }
};
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
}
/// @ test-parameter-type-4
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_d, ut_M_d_Refman)
    LUMI_inc_ref(ut_M_t_Refman);
    LUMI_dec_ref(ut_M_d->item_Refman);
    ut_M_d->item_Refman = ut_M_t_Refman;
    ut_M_d->item_Dynamic = (Generic_Type_Dynamic*)&ut_M_Test_dynamic;
    ut_M_d->item = ut_M_t;
/// @ test-parameter-type-5
CHECK_REF_REFMAN(1, LUMI_block0_cleanup, ut_M_d, ut_M_d_Refman)
    LUMI_inc_ref(ut_M_d->item_Refman);
    LUMI_dec_ref(ut_M_t_Refman);
    ut_M_t_Refman = ut_M_d->item_Refman;
    ut_M_t = ut_M_d->item;
/// @ test-parameter-type-6
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
    void (*fun)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic, void (*fun)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic));
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_meth(ut_M_Test* self, void (*fun)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic, void (*fun)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic)));
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_meth(ut_M_Test* self, void (*fun)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic, void (*fun)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic))) {
    unsigned LUMI_loop_depth = 1;
    void (*funv)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic, void (*funa)(Generic_Type* item, Generic_Type_Dynamic* item_Dynamic)) = NULL;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
    ut_M_Data_set(ut_M_d, *to, (Generic_Type_Dynamic*)&ut_M_Test_dynamic);
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
    ut_M_Data_set(ut_M_d, *to, (Generic_Type_Dynamic*)&ut_M_Test_dynamic);
    *to = NULL;
    *to_Refman = NULL;
/// @ test-parameter-type-17
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    ut_M_Test* next;
    Ref_Manager* next_Refman;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_meth(ut_M_Test* self, ut_M_Test* next, Ref_Manager* next_Refman, ut_M_Test** out);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
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
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
    ut_M_Tb* aux_Tb_1 = NULL;
    Ref_Manager* aux_Tb_1_Refman = NULL;
    ut_M_Tb_Dynamic* aux_Tb_1_Dynamic = NULL;
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
    ut_M_Data_get(dt, (void*)&(aux_Tb_0), &(aux_Tb_0_Refman), (void*)&(aux_Tb_0_Dynamic));
    LUMI_inc_ref(aux_Tb_0_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = aux_Tb_0_Refman;
    ut_M_ta_Dynamic = &(aux_Tb_0_Dynamic->_base);
    ut_M_ta = &(aux_Tb_0->_base);
    ut_M_Data_get(dt, (void*)&(aux_Tb_1), &(aux_Tb_1_Refman), (void*)&(aux_Tb_1_Dynamic));
    CHECK_REF_REFMAN(7, LUMI_block0_cleanup, aux_Tb_1, aux_Tb_1_Refman)
    ut_M_i = aux_Tb_1->_base.numa;
    ut_M_fun7(dt->item, dt->item_Refman, ((ut_M_Tb_Dynamic*)(dt->item_Dynamic)), &(dt->item), &(dt->item_Refman), &(((ut_M_Tb_Dynamic*)(dt->item_Dynamic))));
    CHECK_REFMAN(9, LUMI_block0_cleanup, dt->item_Refman)
    tb2_Dynamic = ((ut_M_Tb_Dynamic*)(dt->item_Dynamic));
    tb2 = dt->item;
    CHECK_REFMAN(10, LUMI_block0_cleanup, dt->item_Refman)
    tb2_Dynamic = ((ut_M_Tb_Dynamic*)(dt->item_Dynamic));
    tb2 = dt->item;
/// @ test-parameter-type-19
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_MyStruct_Dynamic ut_M_MyStruct_Dynamic;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_MyStruct_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Base {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test {
    ut_M_Base _base;
};
struct ut_M_Test_Dynamic {
    ut_M_Base_Dynamic _base;
};
void ut_M_MyStruct_meth(ut_M_MyStruct* self);
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic);
void ut_M_Base_get(ut_M_Base* self, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Test_set(ut_M_Test* self, ut_M_MyStruct* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
Return_Code ut_M_fun(ut_M_Test* test, ut_M_MyStruct* f, Ref_Manager* f_Refman);
ut_M_MyStruct_Dynamic ut_M_MyStruct_dynamic = {
    (Dynamic_Del)ut_M_MyStruct_Del
};
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        (Dynamic_Del)ut_M_Test_Del
    }
};
void ut_M_MyStruct_meth(ut_M_MyStruct* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Base_get(ut_M_Base* self, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
void ut_M_Test_set(ut_M_Test* self, ut_M_MyStruct* f, Ref_Manager* f_Refman) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(f_Refman);
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(self->_base.item_Refman);
    self->_base.item_Refman = f_Refman;
    self->_base.item_Dynamic = (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic;
    self->_base.item = f;
    ut_M_Base_get(&(self->_base), (void*)&(f), &(f_Refman), &dynamic_Void);
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(f_Refman);
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
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
    test->_base.item_Dynamic = (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic;
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
typedef struct ut_M_MyStruct_Dynamic ut_M_MyStruct_Dynamic;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_MyStruct_Dynamic {
    Dynamic_Del _del;
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
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic);
void ut_M_Base_set(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
void ut_M_Base_get(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Test_set(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
void ut_M_Test_get(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
Return_Code ut_M_mock(ut_M_Test* test, Ref_Manager* test_Refman, ut_M_Test_Dynamic* test_Dynamic, ut_M_MyStruct* f, Ref_Manager* f_Refman);
ut_M_MyStruct_Dynamic ut_M_MyStruct_dynamic = {
    (Dynamic_Del)ut_M_MyStruct_Del
};
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del,
    ut_M_Base_set,
    ut_M_Base_get
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        (Dynamic_Del)ut_M_Test_Del,
        (void (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic))ut_M_Test_set,
        (void (*)(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic))ut_M_Test_get
    }
};
void ut_M_MyStruct_meth(ut_M_MyStruct* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic) {
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
    test_Dynamic->_base.set(&(test->_base), &(test_Dynamic->_base), f, f_Refman, (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic);
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_meth(ut_M_Test* self, Generic_Type* in, Ref_Manager* in_Refman, Generic_Type_Dynamic* in_Dynamic, Generic_Type** out, Ref_Manager** out_Refman, Generic_Type_Dynamic** out_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
/// @ test-parameter-type-22
ut_M_Data* db = NULL;
    ut_M_Tb* aux_Tb_0 = NULL;
    Ref_Manager* aux_Tb_0_Refman = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, db)
    LUMI_inc_ref(ut_M_tb_Refman);
    LUMI_dec_ref(db->item_Refman);
    db->item_Refman = ut_M_tb_Refman;
    db->item_Dynamic = (Generic_Type_Dynamic*)ut_M_tb_Dynamic;
    db->item = ut_M_tb;
    CHECK_REF(3, LUMI_block0_cleanup, db)
    LUMI_inc_ref(NULL);
    LUMI_dec_ref(db->item_Refman);
    db->item_Refman = NULL;
    db->item_Dynamic = NULL;
    db->item = NULL;
    CHECK_REF(4, LUMI_block0_cleanup, db)
    LUMI_inc_ref(db->item_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = db->item_Refman;
    ut_M_ta_Dynamic = &(((ut_M_Tb_Dynamic*)(db->item_Dynamic))->_base);
    ut_M_ta = &(((ut_M_Tb*)(db->item))->_base);
    LUMI_var_dec_ref(ut_M_tb_Refman);
    ut_M_Data_set(db, ut_M_tb, (void*)ut_M_tb_Dynamic);
    ut_M_tb = NULL;
    ut_M_tb_Refman = NULL;
    ut_M_tb_Dynamic = NULL;
    ut_M_Data_set(db, NULL, NULL);
    ut_M_Data_get(db, (void*)&(aux_Tb_0), &(aux_Tb_0_Refman), (void*)&(aux_Tb_0_Dynamic));
    LUMI_inc_ref(aux_Tb_0_Refman);
    LUMI_dec_ref(ut_M_ta_Refman);
    ut_M_ta_Refman = aux_Tb_0_Refman;
    ut_M_ta_Dynamic = &(aux_Tb_0_Dynamic->_base);
    ut_M_ta = &(aux_Tb_0->_base);
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
array as parameter type is unsupported
/// @@ test-parameter-inheritance
/// @ test-parameter-inheritance-0
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_MyStruct_Dynamic ut_M_MyStruct_Dynamic;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_MyStruct_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Base {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test {
    ut_M_Base _base;
};
struct ut_M_Test_Dynamic {
    ut_M_Base_Dynamic _base;
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
Return_Code ut_M_Test_set(ut_M_Test* self, ut_M_MyStruct* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman);
ut_M_MyStruct_Dynamic ut_M_MyStruct_dynamic = {
    (Dynamic_Del)ut_M_MyStruct_Del
};
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        (Dynamic_Del)ut_M_Test_Del
    }
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
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
    self->_base.item_Dynamic = (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic;
    self->_base.item = f;
    INIT_NEW(8, LUMI_block0_cleanup, aux_Test_0, ut_M_Test, 1);
    LUMI_err = ut_M_Test_set(aux_Test_0, f, f_Refman);
    CHECK(8, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(aux_Test_0, NULL);
    free(aux_Test_0);
    LUMI_dec_ref(f_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
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
    t->_base.item_Dynamic = (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic;
    t->_base.item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t, NULL);
    LUMI_dec_ref(f_Refman);
}
/// @ test-parameter-inheritance-1
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_MyStruct_Dynamic ut_M_MyStruct_Dynamic;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_MyStruct_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Base {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test {
    ut_M_Base _base;
};
struct ut_M_Test_Dynamic {
    ut_M_Base_Dynamic _base;
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
Return_Code ut_M_Test_set(ut_M_Test* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, ut_M_MyStruct* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman);
ut_M_MyStruct_Dynamic ut_M_MyStruct_dynamic = {
    (Dynamic_Del)ut_M_MyStruct_Del
};
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        (Dynamic_Del)ut_M_Test_Del
    }
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
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
    LUMI_err = ut_M_Test_set(aux_Test_0, f, f_Refman, (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic, f, f_Refman);
    CHECK(8, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(aux_Test_0, NULL);
    free(aux_Test_0);
    LUMI_dec_ref(f_Refman);
    LUMI_dec_ref(i_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
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
    t->_base.item_Dynamic = (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic;
    t->_base.item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t, NULL);
    LUMI_dec_ref(f_Refman);
}
/// @ test-parameter-inheritance-2
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_MyStruct_Dynamic ut_M_MyStruct_Dynamic;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Mid_Dynamic ut_M_Mid_Dynamic;
typedef struct ut_M_Top ut_M_Top;
typedef struct ut_M_Top_Dynamic ut_M_Top_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_MyStruct_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Base {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Mid {
    ut_M_Base _base;
};
struct ut_M_Mid_Dynamic {
    ut_M_Base_Dynamic _base;
};
struct ut_M_Top {
    ut_M_Mid _base;
};
struct ut_M_Top_Dynamic {
    ut_M_Mid_Dynamic _base;
};
struct ut_M_Test {
    ut_M_Top _base;
};
struct ut_M_Test_Dynamic {
    ut_M_Top_Dynamic _base;
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic);
void ut_M_Base_set(ut_M_Base* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Mid_set(ut_M_Mid* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Top_set(ut_M_Top* self, ut_M_MyStruct* f, Ref_Manager* f_Refman);
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
Return_Code ut_M_Test_set(ut_M_Test* self, ut_M_MyStruct* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman);
ut_M_MyStruct_Dynamic ut_M_MyStruct_dynamic = {
    (Dynamic_Del)ut_M_MyStruct_Del
};
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del
};
ut_M_Mid_Dynamic ut_M_Mid_dynamic = {
    {
        (Dynamic_Del)ut_M_Mid_Del
    }
};
ut_M_Top_Dynamic ut_M_Top_dynamic = {
    {
        {
            (Dynamic_Del)ut_M_Top_Del
        }
    }
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        {
            {
                (Dynamic_Del)ut_M_Test_Del
            }
        }
    }
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Base_set(ut_M_Base* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(i_Refman);
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(i_Refman);
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
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
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
}
void ut_M_Top_set(ut_M_Top* self, ut_M_MyStruct* f, Ref_Manager* f_Refman) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(f_Refman);
    ut_M_Mid_set(&(self->_base), f, f_Refman, (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic);
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(self->_base._base.item_Refman);
    self->_base._base.item_Refman = f_Refman;
    self->_base._base.item_Dynamic = (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic;
    self->_base._base.item = f;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(f_Refman);
}
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base), NULL);
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
    self->_base._base._base.item_Dynamic = (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic;
    self->_base._base._base.item = f;
    INIT_NEW(16, LUMI_block0_cleanup, aux_Top_0, ut_M_Top, 1);
    ut_M_Top_set(aux_Top_0, f, f_Refman);
    INIT_NEW(17, LUMI_block0_cleanup, aux_Test_0, ut_M_Test, 1);
    LUMI_err = ut_M_Test_set(aux_Test_0, f, f_Refman);
    CHECK(17, LUMI_block0_cleanup)
    INIT_NEW(18, LUMI_block0_cleanup, aux_Top_1, ut_M_Top, 1);
    ut_M_Mid_set(&(aux_Top_1->_base), f, f_Refman, (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic);
LUMI_block0_cleanup:
    (void)0;
    ut_M_Top_Del(aux_Top_1, NULL);
    free(aux_Top_1);
    ut_M_Test_Del(aux_Test_0, NULL);
    free(aux_Test_0);
    ut_M_Top_Del(aux_Top_0, NULL);
    free(aux_Top_0);
    LUMI_dec_ref(f_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Top_Del(&(self->_base), NULL);
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
    t->_base._base._base.item_Dynamic = (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic;
    t->_base._base._base.item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t, NULL);
    LUMI_dec_ref(f_Refman);
}
/// @ test-parameter-inheritance-3
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_MyStruct_Dynamic ut_M_MyStruct_Dynamic;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_MyStruct_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Base {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test {
    ut_M_Base _base;
};
struct ut_M_Test_Dynamic {
    ut_M_Base_Dynamic _base;
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
Return_Code ut_M_Test_set(ut_M_Test* self, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, ut_M_MyStruct* f, Ref_Manager* f_Refman);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman);
ut_M_MyStruct_Dynamic ut_M_MyStruct_dynamic = {
    (Dynamic_Del)ut_M_MyStruct_Del
};
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        (Dynamic_Del)ut_M_Test_Del
    }
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
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
    LUMI_err = ut_M_Test_set(aux_Test_0, f, f_Refman, (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic, f, f_Refman);
    CHECK(8, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(aux_Test_0, NULL);
    free(aux_Test_0);
    LUMI_dec_ref(f_Refman);
    LUMI_dec_ref(i_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
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
    t->_base.item_Dynamic = (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic;
    t->_base.item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t, NULL);
    LUMI_dec_ref(f_Refman);
}
/// @ test-parameter-inheritance-4
typedef struct ut_M_StructA ut_M_StructA;
typedef struct ut_M_StructA_Dynamic ut_M_StructA_Dynamic;
typedef struct ut_M_StructB ut_M_StructB;
typedef struct ut_M_StructB_Dynamic ut_M_StructB_Dynamic;
typedef struct ut_M_StructC ut_M_StructC;
typedef struct ut_M_StructC_Dynamic ut_M_StructC_Dynamic;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Mid_Dynamic ut_M_Mid_Dynamic;
typedef struct ut_M_Top ut_M_Top;
typedef struct ut_M_Top_Dynamic ut_M_Top_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_StructA {
    uint32_t x;
};
struct ut_M_StructA_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_StructB {
    uint32_t x;
};
struct ut_M_StructB_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_StructC {
    uint32_t x;
};
struct ut_M_StructC_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Base {
    Generic_Type* first;
    Ref_Manager* first_Refman;
    Generic_Type_Dynamic* first_Dynamic;
    Generic_Type* second;
    Ref_Manager* second_Refman;
    Generic_Type_Dynamic* second_Dynamic;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Mid {
    ut_M_Base _base;
    Generic_Type* third;
    Ref_Manager* third_Refman;
    Generic_Type_Dynamic* third_Dynamic;
};
struct ut_M_Mid_Dynamic {
    ut_M_Base_Dynamic _base;
};
struct ut_M_Top {
    ut_M_Mid _base;
};
struct ut_M_Top_Dynamic {
    ut_M_Mid_Dynamic _base;
};
struct ut_M_Test {
    ut_M_Top _base;
};
struct ut_M_Test_Dynamic {
    ut_M_Top_Dynamic _base;
};
void ut_M_StructA_Del(ut_M_StructA* self, ut_M_StructA_Dynamic* self_Dynamic);
void ut_M_StructB_Del(ut_M_StructB* self, ut_M_StructB_Dynamic* self_Dynamic);
void ut_M_StructC_Del(ut_M_StructC* self, ut_M_StructC_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Mid_set(ut_M_Mid* self, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, ut_M_StructB* second, Ref_Manager* second_Refman, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Top_set(ut_M_Top* self, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, ut_M_StructB* second, Ref_Manager* second_Refman, ut_M_StructC* third, Ref_Manager* third_Refman);
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
void ut_M_Test_set(ut_M_Test* self, ut_M_StructA* first, Ref_Manager* first_Refman, ut_M_StructB* second, Ref_Manager* second_Refman, ut_M_StructC* third, Ref_Manager* third_Refman);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_use(ut_M_StructA* first, Ref_Manager* first_Refman, ut_M_StructB* second, Ref_Manager* second_Refman, ut_M_StructC* third, Ref_Manager* third_Refman);
ut_M_StructA_Dynamic ut_M_StructA_dynamic = {
    (Dynamic_Del)ut_M_StructA_Del
};
ut_M_StructB_Dynamic ut_M_StructB_dynamic = {
    (Dynamic_Del)ut_M_StructB_Del
};
ut_M_StructC_Dynamic ut_M_StructC_dynamic = {
    (Dynamic_Del)ut_M_StructC_Del
};
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del
};
ut_M_Mid_Dynamic ut_M_Mid_dynamic = {
    {
        (Dynamic_Del)ut_M_Mid_Del
    }
};
ut_M_Top_Dynamic ut_M_Top_dynamic = {
    {
        {
            (Dynamic_Del)ut_M_Top_Del
        }
    }
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        {
            {
                (Dynamic_Del)ut_M_Test_Del
            }
        }
    }
};
void ut_M_StructA_Del(ut_M_StructA* self, ut_M_StructA_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_StructB_Del(ut_M_StructB* self, ut_M_StructB_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_StructC_Del(ut_M_StructC* self, ut_M_StructC_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
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
    self->_base.second_Dynamic = (Generic_Type_Dynamic*)&ut_M_StructB_dynamic;
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
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
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
    self->_base._base.second_Dynamic = (Generic_Type_Dynamic*)&ut_M_StructB_dynamic;
    self->_base._base.second = second;
    LUMI_inc_ref(third_Refman);
    LUMI_dec_ref(self->_base.third_Refman);
    self->_base.third_Refman = third_Refman;
    self->_base.third_Dynamic = (Generic_Type_Dynamic*)&ut_M_StructC_dynamic;
    self->_base.third = third;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
}
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base), NULL);
}
void ut_M_Test_set(ut_M_Test* self, ut_M_StructA* first, Ref_Manager* first_Refman, ut_M_StructB* second, Ref_Manager* second_Refman, ut_M_StructC* third, Ref_Manager* third_Refman) {
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(first_Refman);
    LUMI_inc_ref(second_Refman);
    LUMI_inc_ref(third_Refman);
    LUMI_inc_ref(first_Refman);
    LUMI_dec_ref(self->_base._base._base.first_Refman);
    self->_base._base._base.first_Refman = first_Refman;
    self->_base._base._base.first_Dynamic = (Generic_Type_Dynamic*)&ut_M_StructA_dynamic;
    self->_base._base._base.first = first;
    LUMI_inc_ref(second_Refman);
    LUMI_dec_ref(self->_base._base._base.second_Refman);
    self->_base._base._base.second_Refman = second_Refman;
    self->_base._base._base.second_Dynamic = (Generic_Type_Dynamic*)&ut_M_StructB_dynamic;
    self->_base._base._base.second = second;
    LUMI_inc_ref(third_Refman);
    LUMI_dec_ref(self->_base._base.third_Refman);
    self->_base._base.third_Refman = third_Refman;
    self->_base._base.third_Dynamic = (Generic_Type_Dynamic*)&ut_M_StructC_dynamic;
    self->_base._base.third = third;
LUMI_block0_cleanup:
    (void)0;
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Top_Del(&(self->_base), NULL);
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
    t->_base._base._base.first_Dynamic = (Generic_Type_Dynamic*)&ut_M_StructA_dynamic;
    t->_base._base._base.first = first;
    LUMI_inc_ref(second_Refman);
    LUMI_dec_ref(t->_base._base._base.second_Refman);
    t->_base._base._base.second_Refman = second_Refman;
    t->_base._base._base.second_Dynamic = (Generic_Type_Dynamic*)&ut_M_StructB_dynamic;
    t->_base._base._base.second = second;
    LUMI_inc_ref(third_Refman);
    LUMI_dec_ref(t->_base._base.third_Refman);
    t->_base._base.third_Refman = third_Refman;
    t->_base._base.third_Dynamic = (Generic_Type_Dynamic*)&ut_M_StructC_dynamic;
    t->_base._base.third = third;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t, NULL);
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
}
/// @ test-parameter-inheritance-5
typedef struct ut_M_MyStruct ut_M_MyStruct;
typedef struct ut_M_MyStruct_Dynamic ut_M_MyStruct_Dynamic;
typedef struct ut_M_First ut_M_First;
typedef struct ut_M_First_Dynamic ut_M_First_Dynamic;
typedef struct ut_M_Second ut_M_Second;
typedef struct ut_M_Second_Dynamic ut_M_Second_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_MyStruct_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_First {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_First_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Second {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_Second_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test {
    ut_M_First _base;
};
struct ut_M_Test_Dynamic {
    ut_M_First_Dynamic _base;
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic);
void ut_M_First_Del(ut_M_First* self, ut_M_First_Dynamic* self_Dynamic);
void ut_M_Second_Del(ut_M_Second* self, ut_M_Second_Dynamic* self_Dynamic);
Return_Code ut_M_Test_set(ut_M_Test* self, Generic_Type* g, Ref_Manager* g_Refman, Generic_Type_Dynamic* g_Dynamic, ut_M_Second* sg, Ref_Manager* sg_Refman);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
Return_Code ut_M_use(ut_M_MyStruct* f, Ref_Manager* f_Refman, ut_M_Second* ff, Ref_Manager* ff_Refman);
ut_M_MyStruct_Dynamic ut_M_MyStruct_dynamic = {
    (Dynamic_Del)ut_M_MyStruct_Del
};
ut_M_First_Dynamic ut_M_First_dynamic = {
    (Dynamic_Del)ut_M_First_Del
};
ut_M_Second_Dynamic ut_M_Second_dynamic = {
    (Dynamic_Del)ut_M_Second_Del
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        (Dynamic_Del)ut_M_Test_Del
    }
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_First_Del(ut_M_First* self, ut_M_First_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
void ut_M_Second_Del(ut_M_Second* self, ut_M_Second_Dynamic* self_Dynamic) {
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
    self->_base.item_Dynamic = (Generic_Type_Dynamic*)&ut_M_Second_dynamic;
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
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_First_Del(&(self->_base), NULL);
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
    t->_base.item_Dynamic = (Generic_Type_Dynamic*)&ut_M_Second_dynamic;
    t->_base.item = ff;
    CHECK_REF_REFMAN(14, LUMI_block0_cleanup, t->_base.item, t->_base.item_Refman)
    LUMI_inc_ref(f_Refman);
    LUMI_dec_ref(((ut_M_Second*)(t->_base.item))->item_Refman);
    ((ut_M_Second*)(t->_base.item))->item_Refman = f_Refman;
    ((ut_M_Second*)(t->_base.item))->item_Dynamic = (Generic_Type_Dynamic*)&ut_M_MyStruct_dynamic;
    ((ut_M_Second*)(t->_base.item))->item = f;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(t, NULL);
    LUMI_dec_ref(ff_Refman);
    LUMI_dec_ref(f_Refman);
    return LUMI_err;
}
/// @ test-parameter-inheritance-6
typedef struct ut_M_BaseGen ut_M_BaseGen;
typedef struct ut_M_BaseGen_Dynamic ut_M_BaseGen_Dynamic;
typedef struct ut_M_TestGen ut_M_TestGen;
typedef struct ut_M_TestGen_Dynamic ut_M_TestGen_Dynamic;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_BaseGen {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_BaseGen_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_TestGen {
    ut_M_BaseGen _base;
};
struct ut_M_TestGen_Dynamic {
    ut_M_BaseGen_Dynamic _base;
};
struct ut_M_Base {
    uint32_t x;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test {
    ut_M_Base _base;
};
struct ut_M_Test_Dynamic {
    ut_M_Base_Dynamic _base;
};
void ut_M_BaseGen_Del(ut_M_BaseGen* self, ut_M_BaseGen_Dynamic* self_Dynamic);
void ut_M_TestGen_Del(ut_M_TestGen* self, ut_M_TestGen_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_test(void);
ut_M_BaseGen_Dynamic ut_M_BaseGen_dynamic = {
    (Dynamic_Del)ut_M_BaseGen_Del
};
ut_M_TestGen_Dynamic ut_M_TestGen_dynamic = {
    {
        (Dynamic_Del)ut_M_TestGen_Del
    }
};
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        (Dynamic_Del)ut_M_Test_Del
    }
};
void ut_M_BaseGen_Del(ut_M_BaseGen* self, ut_M_BaseGen_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
void ut_M_TestGen_Del(ut_M_TestGen* self, ut_M_TestGen_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_BaseGen_Del(&(self->_base), NULL);
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
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
typedef struct ut_M_MyStruct_Dynamic ut_M_MyStruct_Dynamic;
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Mid_Dynamic ut_M_Mid_Dynamic;
typedef struct ut_M_Top ut_M_Top;
typedef struct ut_M_Top_Dynamic ut_M_Top_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_MyStruct_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Base {
    Generic_Type* first;
    Ref_Manager* first_Refman;
    Generic_Type_Dynamic* first_Dynamic;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Mid {
    ut_M_Base _base;
    Generic_Type* second;
    Ref_Manager* second_Refman;
    Generic_Type_Dynamic* second_Dynamic;
};
struct ut_M_Mid_Dynamic {
    ut_M_Base_Dynamic _base;
};
struct ut_M_Top {
    ut_M_Mid _base;
};
struct ut_M_Top_Dynamic {
    ut_M_Mid_Dynamic _base;
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic);
void ut_M_fun(ut_M_Top* t);
ut_M_MyStruct_Dynamic ut_M_MyStruct_dynamic = {
    (Dynamic_Del)ut_M_MyStruct_Del
};
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del
};
ut_M_Mid_Dynamic ut_M_Mid_dynamic = {
    {
        (Dynamic_Del)ut_M_Mid_Del
    }
};
ut_M_Top_Dynamic ut_M_Top_dynamic = {
    {
        {
            (Dynamic_Del)ut_M_Top_Del
        }
    }
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->first_Refman);
}
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
    LUMI_dec_ref(self->second_Refman);
}
void ut_M_Top_Del(ut_M_Top* self, ut_M_Top_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base), NULL);
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
void ut_M_fun(String* s, Ref_Manager* s_Refman, Bool* fail);
void ut_M_fun(String* s, Ref_Manager* s_Refman, Bool* fail) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(s_Refman);
    ++LUMI_trace_ignore_count;
    CHECK_REFMAN(2, LUMI_block2_cleanup, s_Refman)
    String_clear(s);
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
        Byte sa[0x04] = {0};
        ++LUMI_trace_ignore_count;
        /* initializing sa */
        {
            Byte sb[0x04] = {0};
            Ref_Manager* sb_Refman = NULL;
            ++LUMI_trace_ignore_count;
            INIT_VAR_REFMAN(4, LUMI_block2_cleanup, sb)
        LUMI_block2_cleanup:
            (void)0;
            LUMI_var_dec_ref(sb_Refman);
        }
        --LUMI_trace_ignore_count;
        if (LUMI_err != OK) {
            Byte sc[0x04] = {0};
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
        Byte sd[0x04] = {0};
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        /* initializing sd */
        {
            Byte se[0x04] = {0};
            Ref_Manager* se_Refman = NULL;
            ++LUMI_trace_ignore_count;
            INIT_VAR_REFMAN(10, LUMI_block5_cleanup, se)
        LUMI_block5_cleanup:
            (void)0;
            LUMI_var_dec_ref(se_Refman);
        }
        --LUMI_trace_ignore_count;
        if (LUMI_err != OK) {
            Byte sf[0x04] = {0};
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
void ut_M_fun(String* s, Ref_Manager* s_Refman);
void ut_M_fun(String* s, Ref_Manager* s_Refman) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    LUMI_inc_ref(s_Refman);
    {
        ++LUMI_trace_ignore_count;
        CHECK_REFMAN(3, LUMI_block1_cleanup, s_Refman)
        String_clear(s);
        TEST_ASSERT(4, LUMI_block1_cleanup, true)
        ++LUMI_trace_ignore_count;
        CHECK_REFMAN(5, LUMI_block2_cleanup, s_Refman)
        String_clear(s);
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
typedef struct ut_M_TestIterator_Dynamic ut_M_TestIterator_Dynamic;
struct ut_M_TestIterator {
    uint32_t counter;
};
struct ut_M_TestIterator_Dynamic {
    Dynamic_Del _del;
};
void ut_M_TestIterator_new(ut_M_TestIterator* self, uint32_t count);
void ut_M_TestIterator_step(ut_M_TestIterator* self, uint32_t* num, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic);
Return_Code ut_M_fun(uint32_t* i);
ut_M_TestIterator_Dynamic ut_M_TestIterator_dynamic = {
    (Dynamic_Del)ut_M_TestIterator_Del
};
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
void ut_M_TestIterator_Del(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic) {
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
        Byte s[0x04] = {0};
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
    ut_M_TestIterator_Del(aux_TestIterator_0, NULL);
    free(aux_TestIterator_0);
    return LUMI_err;
}
/// @ test-for-each-1
typedef struct ut_M_TestIterator ut_M_TestIterator;
typedef struct ut_M_TestIterator_Dynamic ut_M_TestIterator_Dynamic;
struct ut_M_TestIterator {
    String* value;
};
struct ut_M_TestIterator_Dynamic {
    Dynamic_Del _del;
};
void ut_M_TestIterator_step(ut_M_TestIterator* self, String** text, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic);
void ut_M_fun(ut_M_TestIterator* iter);
ut_M_TestIterator_Dynamic ut_M_TestIterator_dynamic = {
    (Dynamic_Del)ut_M_TestIterator_Del
};
void ut_M_TestIterator_step(ut_M_TestIterator* self, String** text, Bool* has_data) {
    unsigned LUMI_loop_depth = 1;
    *text = self->value;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    String_Del(self->value, NULL);
    free(self->value);
}
void ut_M_fun(ut_M_TestIterator* iter) {
    unsigned LUMI_loop_depth = 1;
    String* t = NULL;
    String* s = NULL;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    aux_TestIterator_0 = iter;
    do {
        Bool aux_Bool_0 = 0;
        LUMI_loop_depth = 3;
        ut_M_TestIterator_step(aux_TestIterator_0, &(t), &(aux_Bool_0));
        if (!(aux_Bool_0)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
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
typedef struct ut_M_MyStruct_Dynamic ut_M_MyStruct_Dynamic;
typedef struct ut_M_TestIterator ut_M_TestIterator;
typedef struct ut_M_TestIterator_Dynamic ut_M_TestIterator_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_MyStruct_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_TestIterator {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
struct ut_M_TestIterator_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    void (*fun)(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic);
Return_Code ut_M_TestIterator_step(ut_M_TestIterator* self, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic);
void ut_M_Test_fun(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
Return_Code ut_M_fun(ut_M_TestIterator* fiter, ut_M_TestIterator* titer);
ut_M_MyStruct_Dynamic ut_M_MyStruct_dynamic = {
    (Dynamic_Del)ut_M_MyStruct_Del
};
ut_M_TestIterator_Dynamic ut_M_TestIterator_dynamic = {
    (Dynamic_Del)ut_M_TestIterator_Del
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del,
    ut_M_Test_fun
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic) {
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
void ut_M_TestIterator_Del(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic) {
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
typedef struct ut_M_MyStruct_Dynamic ut_M_MyStruct_Dynamic;
typedef struct ut_M_TestIterator ut_M_TestIterator;
typedef struct ut_M_TestIterator_Dynamic ut_M_TestIterator_Dynamic;
struct ut_M_MyStruct {
    uint32_t x;
};
struct ut_M_MyStruct_Dynamic {
    Dynamic_Del _del;
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
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic);
Return_Code ut_M_TestIterator_step(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic, Generic_Type** item, Generic_Type_Dynamic** item_Dynamic, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic);
Return_Code ut_M_f_mock(ut_M_TestIterator* iter, ut_M_TestIterator_Dynamic* iter_Dynamic);
ut_M_MyStruct_Dynamic ut_M_MyStruct_dynamic = {
    (Dynamic_Del)ut_M_MyStruct_Del
};
ut_M_TestIterator_Dynamic ut_M_TestIterator_dynamic = {
    (Dynamic_Del)ut_M_TestIterator_Del,
    ut_M_TestIterator_step
};
void ut_M_MyStruct_Del(ut_M_MyStruct* self, ut_M_MyStruct_Dynamic* self_Dynamic) {
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
typedef struct ut_M_TestIterator_Dynamic ut_M_TestIterator_Dynamic;
struct ut_M_TestIterator {
    String* value;
};
struct ut_M_TestIterator_Dynamic {
    Dynamic_Del _del;
};
void ut_M_TestIterator_step(ut_M_TestIterator* self, String** text, Ref_Manager** text_Refman, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic);
void ut_M_fun(ut_M_TestIterator* iter);
ut_M_TestIterator_Dynamic ut_M_TestIterator_dynamic = {
    (Dynamic_Del)ut_M_TestIterator_Del
};
void ut_M_TestIterator_step(ut_M_TestIterator* self, String** text, Ref_Manager** text_Refman, Bool* has_data) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    String* aux_String_0 = NULL;
    Byte* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    ++LUMI_trace_ignore_count;
    CHECK_REF(4, LUMI_block2_cleanup, self->value)
    String_bytes(self->value, &(aux_Array_0), &(aux_Array_0_Length));
    INIT_NEW(4, LUMI_block2_cleanup, aux_String_0, String, 1);
    LUMI_err = String_new(aux_String_0, aux_Array_0, aux_Array_0_Length);
    CHECK(4, LUMI_block2_cleanup)
    String_Del(*text, NULL);
    LUMI_owner_dec_ref(*text_Refman);
    *text = aux_String_0;
    aux_String_0 = NULL;
    INIT_NEW_REFMAN(4, LUMI_block2_cleanup, *text)
LUMI_block2_cleanup:
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        LUMI_loop_depth = 1;
        String_Del(*text, NULL);
        LUMI_owner_dec_ref(*text_Refman);
        *text_Refman = NULL;
        *text = NULL;
    LUMI_block1_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0, NULL);
    free(aux_String_0);
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    String_Del(self->value, NULL);
    free(self->value);
}
void ut_M_fun(ut_M_TestIterator* iter) {
    unsigned LUMI_loop_depth = 1;
    String* s = NULL;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    aux_TestIterator_0 = iter;
    do {
        String* t = NULL;
        Ref_Manager* t_Refman = NULL;
        Bool aux_Bool_0 = 0;
        LUMI_loop_depth = 3;
        ut_M_TestIterator_step(aux_TestIterator_0, &(t), &(t_Refman), &(aux_Bool_0));
        if (!(aux_Bool_0)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        String_Del(s, NULL);
        free(s);
        LUMI_var_dec_ref(t_Refman);
        s = t;
        t = NULL;
        t_Refman = NULL;
    LUMI_block1_cleanup:
        (void)0;
        String_Del(t, NULL);
        LUMI_owner_dec_ref(t_Refman);
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    String_Del(s, NULL);
    free(s);
}
/// @ test-for-each-5
typedef struct ut_M_TestIterator ut_M_TestIterator;
typedef struct ut_M_TestIterator_Dynamic ut_M_TestIterator_Dynamic;
struct ut_M_TestIterator {
    String* value;
};
struct ut_M_TestIterator_Dynamic {
    Dynamic_Del _del;
};
void ut_M_TestIterator_step(ut_M_TestIterator* self, String** text, Bool* has_data);
void ut_M_TestIterator_Del(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic);
void ut_M_fun(ut_M_TestIterator* iter);
ut_M_TestIterator_Dynamic ut_M_TestIterator_dynamic = {
    (Dynamic_Del)ut_M_TestIterator_Del
};
void ut_M_TestIterator_step(ut_M_TestIterator* self, String** text, Bool* has_data) {
    unsigned LUMI_loop_depth = 1;
    *text = self->value;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self, ut_M_TestIterator_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    String_Del(self->value, NULL);
    free(self->value);
}
void ut_M_fun(ut_M_TestIterator* iter) {
    unsigned LUMI_loop_depth = 1;
    uint32_t x = 0;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    aux_TestIterator_0 = iter;
    do {
        String* aux_String_0 = NULL;
        Bool aux_Bool_0 = 0;
        LUMI_loop_depth = 3;
        ut_M_TestIterator_step(aux_TestIterator_0, &(aux_String_0), &(aux_Bool_0));
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
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
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Astruct_meth(ut_M_Astruct* self, ut_M_Astruct_Dynamic* self_Dynamic);
void ut_M_Astruct_Del(ut_M_Astruct* self, ut_M_Astruct_Dynamic* self_Dynamic);
void ut_M_Bstruct_meth(ut_M_Bstruct* self, ut_M_Bstruct_Dynamic* self_Dynamic);
void ut_M_Bstruct_Del(ut_M_Bstruct* self, ut_M_Bstruct_Dynamic* self_Dynamic);
Return_Code ut_M_Test_test(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Astruct_Dynamic ut_M_Astruct_dynamic = {
    (Dynamic_Del)ut_M_Astruct_Del,
    ut_M_Astruct_meth
};
ut_M_Bstruct_Dynamic ut_M_Bstruct_dynamic = {
    {
        (Dynamic_Del)ut_M_Bstruct_Del,
        (void (*)(ut_M_Astruct* self, ut_M_Astruct_Dynamic* self_Dynamic))ut_M_Bstruct_meth
    }
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
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
    ut_M_Test_Del(t, NULL);
    LUMI_var_dec_ref(t_Refman);
    LUMI_dec_ref(b_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Bstruct_Del(&(self->sb), &ut_M_Bstruct_dynamic);
    LUMI_var_dec_ref(self->sb_Refman);
    ut_M_Bstruct_Del(&(self->b), &ut_M_Bstruct_dynamic);
}
/// @ test-complex-fields-1
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Base {
    uint32_t x;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test {
    Byte s[0x0a];
    uint32_t ai[0x0b];
    ut_M_Base ab[0x0c];
    Byte as[0x07 * 0x08];
    uint32_t aai[0x04 * 0x05 * 0x06];
    ut_M_Base aab[0x04 * 0x05 * 0x06];
    Byte aas[0x04 * 0x05 * 0x06];
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
Return_Code ut_M_Test_test(ut_M_Test* self, Byte* c, uint32_t* i, ut_M_Base** b);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
Return_Code ut_M_Test_test(ut_M_Test* self, Byte* c, uint32_t* i, ut_M_Base** b) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    Byte* aux_Array_0 = NULL;
    uint32_t* aux_Array_1 = NULL;
    uint32_t* aux_Array_2 = NULL;
    ut_M_Base* aux_Array_3 = NULL;
    ut_M_Base* aux_Array_4 = NULL;
    Byte* aux_Array_5 = NULL;
    Byte* aux_Array_6 = NULL;
    *c = self->s[0x03];
    *i = self->ai[0x04];
    *b = self->ab + 0x05;
    aux_Array_0 = self->as + 0x04 * 0x08;
    *c = (aux_Array_0)[0x05];
    aux_Array_1 = self->aai + 0x01 * 0x05 * 0x06;
    aux_Array_2 = (aux_Array_1) + 0x02 * 0x06;
    *i = (aux_Array_2)[0x03];
    aux_Array_3 = self->aab + 0x01 * 0x05 * 0x06;
    aux_Array_4 = (aux_Array_3) + 0x02 * 0x06;
    *b = (aux_Array_4) + 0x03;
    aux_Array_5 = self->aas + 0x01 * 0x05 * 0x06;
    aux_Array_6 = (aux_Array_5) + 0x02 * 0x06;
    *c = (aux_Array_6)[0x03];
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
void ut_M_fun(uint32_t* a, uint32_t a_Length);
uint32_t ut_M_arr[ut_M_SIZE + 0x03] = {0};
void ut_M_fun(uint32_t* a, uint32_t a_Length) {
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
typedef struct second_M_Test second_M_Test;
typedef struct second_M_Test_Dynamic second_M_Test_Dynamic;
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
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
struct second_M_Test {
    ut_M_Test _base;
};
struct second_M_Test_Dynamic {
    ut_M_Test_Dynamic _base;
};
void ut_M_Test_meth(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void second_M_Test_meth(second_M_Test* self);
void second_M_Test_Del(second_M_Test* self, second_M_Test_Dynamic* self_Dynamic);
Return_Code ut_M_fun(void);
Return_Code second_M_fun(void);
Return_Code second_M_dummy(void);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
second_M_Test_Dynamic second_M_Test_dynamic = {
    {
        (Dynamic_Del)second_M_Test_Del
    }
};
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
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
}
void second_M_Test_meth(second_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void second_M_Test_Del(second_M_Test* self, second_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Test_Del(&(self->_base), NULL);
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
    second_M_Test_Del(nt, NULL);
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
    ut_M_Test_Del(nt, NULL);
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint32_t x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_meth(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_fun(void);
void ut_M_fun_Mock(void);
Bool ut_M_fun_Mock_active = true;
void ut_M_Test_meth_Mock(ut_M_Test* self);
Bool ut_M_Test_meth_Mock_active = true;
Return_Code second_M_dummy(void);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
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
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
    Native n;
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
expected module, got "Void Expression"
/// @ test-module-e11
expected module, got "Int"
/// @ test-module-e12
unknown Enum "Error" in module "ut"
/// @@ test-memory-owner
/// @ test-memory-owner-0
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    String* s;
    String* str;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
Return_Code ut_M_Test_new(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_use(String* s);
void ut_M_take(String* s);
void ut_M_give(String** s);
Return_Code ut_M_fun(String* s, ut_M_Test* tu, ut_M_Test* to);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
Return_Code ut_M_Test_new(ut_M_Test* self) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    String* aux_String_0 = NULL;
    INIT_NEW(5, LUMI_block0_cleanup, aux_String_0, String, 1);
    String_Del(self->str, NULL);
    free(self->str);
    self->str = aux_String_0;
    aux_String_0 = NULL;
    String_clear(self->str);
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0, NULL);
    free(aux_String_0);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    String_Del(self->str, NULL);
    free(self->str);
    String_Del(self->s, NULL);
    free(self->s);
}
void ut_M_use(String* s) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_take(String* s) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
    String_Del(s, NULL);
    free(s);
}
void ut_M_give(String** s) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
Return_Code ut_M_fun(String* s, ut_M_Test* tu, ut_M_Test* to) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    String* su = NULL;
    uint32_t arr[0x0c] = {0};
    String* aux_String_0 = NULL;
    String* aux_String_1 = NULL;
    String_Del(s, NULL);
    free(s);
    s = NULL;
    INIT_NEW(12, LUMI_block0_cleanup, aux_String_0, String, 1);
    String_Del(s, NULL);
    free(s);
    s = aux_String_0;
    aux_String_0 = NULL;
    CHECK_REF(13, LUMI_block0_cleanup, s)
    String_clear(s);
    INIT_NEW(14, LUMI_block0_cleanup, aux_String_1, String, 1);
    String_Del(to->s, NULL);
    free(to->s);
    to->s = aux_String_1;
    aux_String_1 = NULL;
    su = tu->s;
    ut_M_use(tu->s);
    ut_M_take(to->s);
    to->s = NULL;
    /* initializing arr */
    arr[0x04] = arr[0x08];
    do {
        LUMI_loop_depth = 3;
        ut_M_give(&(s));
        if (!(s != NULL)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_1, NULL);
    free(aux_String_1);
    String_Del(aux_String_0, NULL);
    free(aux_String_0);
    ut_M_Test_Del(to, NULL);
    free(to);
    String_Del(s, NULL);
    free(s);
    return LUMI_err;
}
/// @ test-memory-owner-1
typedef struct ut_M_TestStruct ut_M_TestStruct;
typedef struct ut_M_TestStruct_Dynamic ut_M_TestStruct_Dynamic;
typedef struct ut_M_TestClass ut_M_TestClass;
typedef struct ut_M_TestClass_Dynamic ut_M_TestClass_Dynamic;
struct ut_M_TestStruct {
    ut_M_TestStruct* next;
};
struct ut_M_TestStruct_Dynamic {
    Dynamic_Del _del;
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
void ut_M_TestStruct_Del(ut_M_TestStruct* self, ut_M_TestStruct_Dynamic* self_Dynamic);
void ut_M_TestClass_fun(ut_M_TestClass* self, ut_M_TestClass_Dynamic* self_Dynamic);
void ut_M_TestClass_Del(ut_M_TestClass* self, ut_M_TestClass_Dynamic* self_Dynamic);
Return_Code ut_M_fun(ut_M_TestStruct* t, ut_M_TestClass* c, Ref_Manager* c_Refman, ut_M_TestClass_Dynamic* c_Dynamic, ut_M_TestStruct* tx, Ref_Manager* tx_Refman, ut_M_TestClass* cx, ut_M_TestClass_Dynamic* cx_Dynamic);
ut_M_TestStruct_Dynamic ut_M_TestStruct_dynamic = {
    (Dynamic_Del)ut_M_TestStruct_Del
};
ut_M_TestClass_Dynamic ut_M_TestClass_dynamic = {
    (Dynamic_Del)ut_M_TestClass_Del,
    ut_M_TestClass_fun
};
void ut_M_TestStruct_Del(ut_M_TestStruct* self, ut_M_TestStruct_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    SELF_REF_DEL(ut_M_TestStruct, next, NULL);
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
    ut_M_TestStruct_Del(t, NULL);
    free(t);
    t = aux_TestStruct_0;
    aux_TestStruct_0 = NULL;
    CHECK_REF(12, LUMI_block0_cleanup, t->next)
    CHECK_REF(12, LUMI_block0_cleanup, t->next->next)
    CHECK_REF(12, LUMI_block0_cleanup, t->next->next->next)
    aux_TestStruct_1 = t->next->next->next;
    t->next->next->next = NULL;
    ut_M_TestStruct_Del(t, NULL);
    free(t);
    t = aux_TestStruct_1;
    aux_TestStruct_1 = NULL;
    CHECK_REF(13, LUMI_block0_cleanup, t->next)
    CHECK_REF(13, LUMI_block0_cleanup, t->next->next)
    aux_TestStruct_2 = t->next->next->next;
    t->next->next->next = NULL;
    ut_M_TestStruct_Del(t->next, NULL);
    free(t->next);
    t->next = aux_TestStruct_2;
    aux_TestStruct_2 = NULL;
    CHECK_REF(14, LUMI_block0_cleanup, t->next)
    CHECK_REF(14, LUMI_block0_cleanup, t->next->next)
    CHECK_REF(14, LUMI_block0_cleanup, t->next)
    aux_TestStruct_3 = t->next->next->next;
    t->next->next->next = NULL;
    ut_M_TestStruct_Del(t->next->next, NULL);
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
    ut_M_TestStruct_Del(tx, NULL);
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
    ut_M_TestStruct_Del(aux_TestStruct_4, NULL);
    free(aux_TestStruct_4);
    if (aux_TestClass_0_Dynamic != NULL) aux_TestClass_0_Dynamic->_del(aux_TestClass_0, aux_TestClass_0_Dynamic);
    LUMI_owner_dec_ref(aux_TestClass_0_Refman);
    ut_M_TestStruct_Del(aux_TestStruct_3, NULL);
    free(aux_TestStruct_3);
    ut_M_TestStruct_Del(aux_TestStruct_2, NULL);
    free(aux_TestStruct_2);
    ut_M_TestStruct_Del(aux_TestStruct_1, NULL);
    free(aux_TestStruct_1);
    ut_M_TestStruct_Del(aux_TestStruct_0, NULL);
    free(aux_TestStruct_0);
    if (cx_Dynamic != NULL) cx_Dynamic->_del(cx, cx_Dynamic);
    free(cx);
    ut_M_TestStruct_Del(tx, NULL);
    LUMI_owner_dec_ref(tx_Refman);
    if (c_Dynamic != NULL) c_Dynamic->_del(c, c_Dynamic);
    LUMI_owner_dec_ref(c_Refman);
    ut_M_TestStruct_Del(t, NULL);
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
void ut_M_deleting(String** s);
void ut_M_fun(String* s, String** so);
void ut_M_deleting(String** s) {
    unsigned LUMI_loop_depth = 1;
    String_Del(*s, NULL);
    free(*s);
    *s = NULL;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_fun(String* s, String** so) {
    unsigned LUMI_loop_depth = 1;
    String_clear(s);
    ut_M_deleting(&(*so));
LUMI_block0_cleanup:
    (void)0;
}
/// @ test-memory-user-1
void ut_M_deleting(String** s, Ref_Manager** s_Refman);
Return_Code ut_M_fun(void);
void ut_M_deleting(String** s, Ref_Manager** s_Refman) {
    unsigned LUMI_loop_depth = 1;
    String_Del(*s, NULL);
    LUMI_owner_dec_ref(*s_Refman);
    *s_Refman = NULL;
    *s = NULL;
LUMI_block0_cleanup:
    (void)0;
}
Return_Code ut_M_fun(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    String* so = NULL;
    Ref_Manager* so_Refman = NULL;
    String* s = NULL;
    String* aux_String_0 = NULL;
    INIT_NEW(4, LUMI_block0_cleanup, aux_String_0, String, 1);
    so = aux_String_0;
    aux_String_0 = NULL;
    INIT_NEW_REFMAN(4, LUMI_block0_cleanup, so)
    s = so;
    CHECK_REF(6, LUMI_block0_cleanup, s)
    String_clear(s);
    ut_M_deleting(&(so), &(so_Refman));
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0, NULL);
    free(aux_String_0);
    String_Del(so, NULL);
    LUMI_owner_dec_ref(so_Refman);
    return LUMI_err;
}
/// @ test-memory-user-2
void ut_M_deleting(String** s, Ref_Manager** s_Refman);
Return_Code ut_M_fun(void);
void ut_M_deleting(String** s, Ref_Manager** s_Refman) {
    unsigned LUMI_loop_depth = 1;
    String_Del(*s, NULL);
    LUMI_owner_dec_ref(*s_Refman);
    *s_Refman = NULL;
    *s = NULL;
LUMI_block0_cleanup:
    (void)0;
}
Return_Code ut_M_fun(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    String* so = NULL;
    Ref_Manager* so_Refman = NULL;
    String* s = NULL;
    Ref_Manager* s_Refman = NULL;
    String* aux_String_0 = NULL;
    INIT_NEW(4, LUMI_block0_cleanup, aux_String_0, String, 1);
    so = aux_String_0;
    aux_String_0 = NULL;
    INIT_NEW_REFMAN(4, LUMI_block0_cleanup, so)
    LUMI_inc_ref(so_Refman);
    LUMI_dec_ref(s_Refman);
    s_Refman = so_Refman;
    s = so;
    ut_M_deleting(&(so), &(so_Refman));
    CHECK_REF_REFMAN(7, LUMI_block0_cleanup, s, s_Refman)
    String_clear(s);
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0, NULL);
    free(aux_String_0);
    LUMI_dec_ref(s_Refman);
    String_Del(so, NULL);
    LUMI_owner_dec_ref(so_Refman);
    return LUMI_err;
}
/// @ test-memory-user-3
String* s = NULL;
    String_Del(*so, NULL);
    LUMI_owner_dec_ref(*so_Refman);
    *so_Refman = NULL;
    *so = NULL;
    s = *so;
    CHECK_REF(4, LUMI_block0_cleanup, s)
    String_clear(s);
/// @ test-memory-user-4
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    String* s;
    Ref_Manager* s_Refman;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
Return_Code ut_M_Test_get(ut_M_Test* self, String** s);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
Return_Code ut_M_fun(ut_M_Test* t);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    LUMI_dec_ref(self->s_Refman);
}
Return_Code ut_M_Test_get(ut_M_Test* self, String** s) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    CHECK_REFMAN(5, LUMI_block0_cleanup, self->s_Refman)
    *s = self->s;
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
Return_Code ut_M_fun(ut_M_Test* t) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    String* s = NULL;
    String* sowner = NULL;
    String* aux_String_0 = NULL;
    sowner = NULL;
    LUMI_err = ut_M_Test_get(t, &(s));
    CHECK(9, LUMI_block0_cleanup)
    CHECK_REF(10, LUMI_block0_cleanup, s)
    String_clear(s);
    LUMI_err = ut_M_Test_get(t, &(aux_String_0));
    CHECK(11, LUMI_block0_cleanup)
    s = aux_String_0;
    CHECK_REF(12, LUMI_block0_cleanup, s)
    String_clear(s);
LUMI_block0_cleanup:
    (void)0;
    String_Del(sowner, NULL);
    free(sowner);
    return LUMI_err;
}
/// @ test-memory-user-5
String* s = NULL;
    String* aux_Array_0 = NULL;
    uint32_t aux_Array_0_Length = 0;
    uint32_t aux_Int_0 = 0;
    s = ut_M_ostr;
    String_Del(ut_M_ostr, NULL);
    free(ut_M_ostr);
    ut_M_ostr = NULL;
    CHECK_REF_REFMAN(3, LUMI_block0_cleanup, ut_M_sarr, ut_M_sarr_Refman)
    aux_Array_0_Length = ut_M_sarr_Length;
    aux_Array_0 = ut_M_sarr;
    do {
        LUMI_loop_depth = 3;
        if (!(aux_Int_0 < aux_Array_0_Length)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        s = aux_Array_0 + aux_Int_0;
        aux_Int_0 += 0x01;
        CHECK_REF(4, LUMI_block1_cleanup, s)
        String_clear(s);
    LUMI_block1_cleanup:
        (void)0;
    } while (LUMI_loop_depth >= 2);
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
/// @ test-memory-user-6
void ut_M_get(String** s);
Return_Code ut_M_fun(void);
void ut_M_get(String** s) {
    unsigned LUMI_loop_depth = 1;
    *s = NULL;
LUMI_block0_cleanup:
    (void)0;
}
Return_Code ut_M_fun(void) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    do {
        String* s = NULL;
        LUMI_loop_depth = 3;
        ut_M_get(&(s));
        if (!(s != NULL)) { LUMI_loop_depth = 1; goto LUMI_block1_cleanup; }
        CHECK_REF(7, LUMI_block1_cleanup, s)
        String_clear(s);
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
using potentially illegal user reference "bfr"
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    String* s;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_fun(ut_M_Test* t);
void ut_M_use(ut_M_Test* t);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    String_Del(self->s, NULL);
    free(self->s);
}
void ut_M_fun(ut_M_Test* t) {
    unsigned LUMI_loop_depth = 1;
    String_Del(t->s, NULL);
    free(t->s);
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
    ut_M_Test_Del(t, NULL);
    free(t);
}
/// @ test-memory-temp-1
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    String* s;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_fun(ut_M_Test* to);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    String_Del(self->s, NULL);
    free(self->s);
}
void ut_M_fun(ut_M_Test* to) {
    unsigned LUMI_loop_depth = 1;
    ut_M_Test* t = NULL;
    t = to;
    String_Del(t->s, NULL);
    free(t->s);
    t->s = NULL;
LUMI_block0_cleanup:
    (void)0;
    ut_M_Test_Del(to, NULL);
    free(to);
}
/// @ test-memory-temp-2
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    String* s;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_fun(ut_M_Test* to, String* s, String* s2);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    String_Del(self->s, NULL);
    free(self->s);
}
void ut_M_fun(ut_M_Test* to, String* s, String* s2) {
    unsigned LUMI_loop_depth = 1;
    String* so = NULL;
    String* so2 = NULL;
    ut_M_Test* t3 = NULL;
    so = s;
    so2 = s2;
    if (to->s != NULL) {
        ut_M_Test* t1 = NULL;
        String* si = NULL;
        String_Del(to->s, NULL);
        free(to->s);
        to->s = NULL;
        t1 = to;
        String_Del(t1->s, NULL);
        free(t1->s);
        t1->s = NULL;
        String_clear(so);
        so2 = so;
        String_clear(so2);
        si = so2;
    LUMI_block1_cleanup:
        (void)0;
    }
    else {
        ut_M_Test* t2 = NULL;
        String* si = NULL;
        String_Del(to->s, NULL);
        free(to->s);
        to->s = NULL;
        t2 = to;
        String_Del(t2->s, NULL);
        free(t2->s);
        t2->s = NULL;
        String_clear(so);
        si = so;
        so2 = si;
        String_clear(so2);
    LUMI_block3_cleanup:
        (void)0;
    }
    if (LUMI_loop_depth < 1) goto LUMI_block0_cleanup;
    String_Del(to->s, NULL);
    free(to->s);
    to->s = NULL;
    t3 = to;
    String_Del(t3->s, NULL);
    free(t3->s);
    t3->s = NULL;
    String_clear(so);
LUMI_block0_cleanup:
    (void)0;
    String_Del(s2, NULL);
    free(s2);
    String_Del(s, NULL);
    free(s);
    ut_M_Test_Del(to, NULL);
    free(to);
}
/// @ test-memory-temp-3
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    ut_M_Test* next;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
Return_Code ut_M_fun(ut_M_Test* to);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    SELF_REF_DEL(ut_M_Test, next, NULL);
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
    ut_M_Test_Del(to, NULL);
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
Return_Code ut_M_fun(String** s);
Return_Code ut_M_fun(String** s) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    String* aux_String_0 = NULL;
    INIT_NEW(2, LUMI_block0_cleanup, aux_String_0, String, 1);
    String_Del(*s, NULL);
    free(*s);
    *s = aux_String_0;
    aux_String_0 = NULL;
    String_clear(*s);
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0, NULL);
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
typedef struct ut_M_NoConstructor_Dynamic ut_M_NoConstructor_Dynamic;
typedef struct ut_M_HasConstructor ut_M_HasConstructor;
typedef struct ut_M_HasConstructor_Dynamic ut_M_HasConstructor_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_NoConstructor {
    String s;
};
struct ut_M_NoConstructor_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_HasConstructor {
    String* s;
};
struct ut_M_HasConstructor_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Test {
    ut_M_NoConstructor vnc;
    ut_M_HasConstructor vhc;
    ut_M_NoConstructor svnc;
    Ref_Manager* svnc_Refman;
    ut_M_HasConstructor svhc;
    Ref_Manager* svhc_Refman;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_NoConstructor_Del(ut_M_NoConstructor* self, ut_M_NoConstructor_Dynamic* self_Dynamic);
Return_Code ut_M_HasConstructor_new(ut_M_HasConstructor* self);
void ut_M_HasConstructor_Del(ut_M_HasConstructor* self, ut_M_HasConstructor_Dynamic* self_Dynamic);
Return_Code ut_M_Test_new(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_NoConstructor_Dynamic ut_M_NoConstructor_dynamic = {
    (Dynamic_Del)ut_M_NoConstructor_Del
};
ut_M_HasConstructor_Dynamic ut_M_HasConstructor_dynamic = {
    (Dynamic_Del)ut_M_HasConstructor_Del
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_NoConstructor_Del(ut_M_NoConstructor* self, ut_M_NoConstructor_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    String_Del(&(self->s), NULL);
}
Return_Code ut_M_HasConstructor_new(ut_M_HasConstructor* self) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    String* aux_String_0 = NULL;
    INIT_NEW(6, LUMI_block0_cleanup, aux_String_0, String, 1);
    String_Del(self->s, NULL);
    free(self->s);
    self->s = aux_String_0;
    aux_String_0 = NULL;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0, NULL);
    free(aux_String_0);
    return LUMI_err;
}
void ut_M_HasConstructor_Del(ut_M_HasConstructor* self, ut_M_HasConstructor_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    String_Del(self->s, NULL);
    free(self->s);
}
Return_Code ut_M_Test_new(ut_M_Test* self) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    String_clear(&(self->vnc.s));
    String_clear(&(self->svnc.s));
    LUMI_err = ut_M_HasConstructor_new(&(self->vhc));
    CHECK(15, LUMI_block0_cleanup)
    String_clear(self->vhc.s);
    LUMI_err = ut_M_HasConstructor_new(&(self->svhc));
    CHECK(17, LUMI_block0_cleanup)
    String_clear(self->svhc.s);
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_HasConstructor_Del(&(self->svhc), NULL);
    LUMI_var_dec_ref(self->svhc_Refman);
    ut_M_NoConstructor_Del(&(self->svnc), NULL);
    LUMI_var_dec_ref(self->svnc_Refman);
    ut_M_HasConstructor_Del(&(self->vhc), NULL);
    ut_M_NoConstructor_Del(&(self->vnc), NULL);
}
/// @ test-memory-constructor-1
typedef struct ut_M_Base ut_M_Base;
typedef struct ut_M_Base_Dynamic ut_M_Base_Dynamic;
typedef struct ut_M_Mid ut_M_Mid;
typedef struct ut_M_Mid_Dynamic ut_M_Mid_Dynamic;
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Base {
    String* s;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
};
struct ut_M_Mid {
    ut_M_Base _base;
};
struct ut_M_Mid_Dynamic {
    ut_M_Base_Dynamic _base;
};
struct ut_M_Test {
    ut_M_Mid _base;
    ut_M_Base* b;
};
struct ut_M_Test_Dynamic {
    ut_M_Mid_Dynamic _base;
};
Return_Code ut_M_Base_new(ut_M_Base* self);
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic);
Return_Code ut_M_Mid_new(ut_M_Mid* self);
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic);
Return_Code ut_M_Test_new(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_fun1(void);
void ut_M_fun2(void (*f)(void));
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del
};
ut_M_Mid_Dynamic ut_M_Mid_dynamic = {
    {
        (Dynamic_Del)ut_M_Mid_Del
    }
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        {
            (Dynamic_Del)ut_M_Test_Del
        }
    }
};
Return_Code ut_M_Base_new(ut_M_Base* self) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    String* aux_String_0 = NULL;
    INIT_NEW(6, LUMI_block0_cleanup, aux_String_0, String, 1);
    String_Del(self->s, NULL);
    free(self->s);
    self->s = aux_String_0;
    aux_String_0 = NULL;
LUMI_block0_cleanup:
    (void)0;
    String_Del(aux_String_0, NULL);
    free(aux_String_0);
    return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self, ut_M_Base_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    String_Del(self->s, NULL);
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
void ut_M_Mid_Del(ut_M_Mid* self, ut_M_Mid_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base), NULL);
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
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base), NULL);
    ut_M_Base_Del(self->b, NULL);
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
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    uint8_t a;
    int8_t b;
    uint8_t c;
    int8_t d;
    int8_t e;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_new(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_new(ut_M_Test* self) {
    unsigned LUMI_loop_depth = 1;
    self->a = 0x01;
    self->b = -0x01;
LUMI_block0_cleanup:
    (void)0;
}
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
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
void* p_void = NULL;
    cdef_M_Char* p_char = NULL;
    cdef_M_Uint* p_uint = NULL;
    ut_M_Test* p_test = NULL;
    cdef_M_Int** pp_int = NULL;
    cdef_M_Char*** ppp_char = NULL;
    p_void = p_char;
    p_uint = p_void;
    p_char = p_uint;
    ut_M_b = ((((p_void != NULL) || (p_char != NULL)) || (p_test != NULL)) || (pp_int != NULL)) || (ppp_char != NULL);
    p_void = str;
/// @ test-c-objects-2
cdef_M_Int cint = 0;
    cdef_M_Int* p_int = NULL;
    cdef_M_Int** pp_int = NULL;
    cdef_M_Int* arr_int = NULL;
    uint32_t arr_int_Length = 0;
    ut_M_Test test_Var = {0};
    ut_M_Test* test = NULL;
    ut_M_Test* u_test = NULL;
    ut_M_Test* p_test = NULL;
    ut_M_Test* arr_test = NULL;
    uint32_t arr_test_Length = 0;
    p_int = arr_int;
    cdef_M_Pointer_set_point_to(p_int, cint, (Generic_Type_Dynamic*)&cdef_M_Int_dynamic);
    cdef_M_Pointer_set_point_to(pp_int, p_int, (Generic_Type_Dynamic*)&cdef_M_Int*_dynamic);
    p_int = cdef_M_Pointer_get_pointed_at(pp_int, 0);
    cint = cdef_M_Pointer_get_pointed_at(p_int, 0x03);
    cdef_M_Pointer_get_pointed_at(p_int, 0x03) = 0x05;
    test = &test_Var;
    u_test = test;
    p_test = arr_test;
    p_test = test;
    u_test = ((ut_M_Test*)cdef_M_Pointer_get_ref_at(p_test, 0x05));
/// @ test-c-objects-3
void ut_M_proxy(cdef_M_Char* p_char, cdef_M_Uchar* p_uchar);
Return_Code ut_M_fun(String* str, Byte* buff, uint32_t buff_Length);
void ut_M_proxy(cdef_M_Char* p_char, cdef_M_Uchar* p_uchar) {
    unsigned LUMI_loop_depth = 1;
LUMI_block0_cleanup:
    (void)0;
}
Return_Code ut_M_fun(String* str, Byte* buff, uint32_t buff_Length) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    cdef_M_Char* p_char = NULL;
    cdef_M_Uchar* p_uchar = NULL;
    p_char = cdef_M_string_pointer(str);
    p_uchar = buff;
    ext(cdef_M_string_pointer(str), buff);
    ut_M_proxy(cdef_M_string_pointer(str), buff);
    LUMI_err = cdef_M_copy_to_string(p_char, str);
    CHECK(10, LUMI_block0_cleanup)
LUMI_block0_cleanup:
    (void)0;
    return LUMI_err;
}
/// @ test-c-objects-4
cdef_M_Uchar* p_uchar = NULL;
    CHECK_REF(2, LUMI_block0_cleanup, ut_M_buff)
    cdef_M_copy_to_buffer(p_uchar, ut_M_buff, ut_M_buff_Length);
/// @ test-c-objects-e0
dynamic pointed type "Ta"
/// @ test-c-objects-e1
cannot assign value with access "user" into value with access "var"
/// @ test-c-objects-e2
assigning into non assignable expression
/// @ test-c-objects-e3
cannot use "?" on primitive type "Pointer"
/// @ test-c-objects-e4
cannot assign "String" into "Pointer"
/// @@ test-cleanup-function
/// @ test-cleanup-function-0
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    String* s;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
};
void ut_M_Test_cleanup(ut_M_Test* self);
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    (Dynamic_Del)ut_M_Test_Del
};
void ut_M_Test_cleanup(ut_M_Test* self) {
    Return_Code LUMI_err = OK;
    unsigned LUMI_loop_depth = 1;
    {
        ++LUMI_trace_ignore_count;
        CHECK_REF(5, LUMI_block1_cleanup, self->s)
        String_clear(self->s);
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
void ut_M_Test_Del(ut_M_Test* self, ut_M_Test_Dynamic* self_Dynamic) {
    if (self == NULL) return;
    ut_M_Test_cleanup(self);
    String_Del(self->s, NULL);
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
ut_M_Base_Dynamic ut_M_Base_dynamic = {
    (Dynamic_Del)ut_M_Base_Del,
    ut_M_Base_meth
};
ut_M_Test_Dynamic ut_M_Test_dynamic = {
    {
        (Dynamic_Del)ut_M_Test_Del,
        ut_M_Base_meth
    }
};
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
