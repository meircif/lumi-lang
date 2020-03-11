/// @@ test-general
/// @ t0
String* ut_M_str = NULL;
Ref_Manager* ut_M_str_Refman = NULL;
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
char ut_M_s_Values[12] = {0};
String ut_M_s_Var = {12, 0, NULL};
String* ut_M_s = NULL;
Ref_Manager* ut_M_s_Refman = NULL;
String* ut_M_us = NULL;
Ref_Manager* ut_M_us_Refman = NULL;
String* ut_M_gs = NULL;
Ref_Manager* ut_M_gs_Refman = NULL;
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    Int x = 0;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
#undef RETURN_ERROR
#define RETURN_ERROR return LUMI_err;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "mock.4.lm"
    INIT_VAR(1, ut_M_s)
    ut_M_s_Var.values = ut_M_s_Values;
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.4.lm"
    ut_M_us = ut_M_s;
    ut_M_us_Refman = ut_M_s_Refman;
    LUMI_inc_ref(ut_M_us_Refman);
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "mock.4.lm"
    INIT_STRING_CONST(3, aux_String_0, "global text");
    ut_M_gs = aux_String_0;
    ut_M_gs_Refman = aux_String_0_Refman;
    LUMI_inc_ref(ut_M_gs_Refman);
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    x = 6;
    x = 7;
LUMI_cleanup:
    return LUMI_err;
}
MAIN_FUNC
/// @ t7
Returncode ut_M_fun(void);
Returncode second_M_dummy(void);
char ut_M_s_Values[12] = {0};
String ut_M_s_Var = {12, 0, NULL};
String* ut_M_s = NULL;
Ref_Manager* ut_M_s_Refman = NULL;
int LUMI_file0_line_count[5] = {
    -1,-1,-1, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.4.lm", 5, LUMI_file0_line_count}
};
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
    ++LUMI_file_coverage[0].line_count[3];
    aux_Ref_Manager = ut_M_s_Refman;
    ut_M_s_Refman = NULL;
    LUMI_inc_ref(ut_M_s_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ut_M_s = NULL;
LUMI_cleanup:
    return LUMI_err;
}
Returncode second_M_dummy(void) {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    Bool LUMI_success = true;
#undef RETURN_ERROR
#define RETURN_ERROR return LUMI_err;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "mock.4.lm"
    INIT_VAR(1, ut_M_s)
    ut_M_s_Var.values = ut_M_s_Values;
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    LUMI_success &= LUMI_run_test("dummy", second_M_dummy);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
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
    Ref_Manager* b_Refman;
    ut_M_Base_Dynamic* b_Dynamic;
};
struct ut_M_Base_Dynamic {
    Dynamic_Del _del;
    Returncode (*dyn0)(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic);
    Returncode (*dyn1)(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic);
};
struct ut_M_Mid {
    ut_M_Base _base;
    Int y;
    ut_M_Mid* m;
    Ref_Manager* m_Refman;
    ut_M_Mid_Dynamic* m_Dynamic;
};
struct ut_M_Mid_Dynamic {
    ut_M_Base_Dynamic _base;
    Returncode (*dyn2)(ut_M_Mid* self, Ref_Manager* self_Refman, ut_M_Mid_Dynamic* self_Dynamic);
};
struct ut_M_Top {
    ut_M_Mid _base;
    Int z;
    ut_M_Top* t;
    Ref_Manager* t_Refman;
    ut_M_Top_Dynamic* t_Dynamic;
};
struct ut_M_Top_Dynamic {
    ut_M_Mid_Dynamic _base;
    Returncode (*dyn3)(ut_M_Top* self, Ref_Manager* self_Refman, ut_M_Top_Dynamic* self_Dynamic);
};
Returncode ut_M_Base_stat(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic);
Returncode ut_M_Base_dyn0(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic);
Returncode ut_M_Base_dyn1(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Mid_dyn0(ut_M_Mid* self, Ref_Manager* self_Refman, ut_M_Mid_Dynamic* self_Dynamic);
Returncode ut_M_Mid_dyn2(ut_M_Mid* self, Ref_Manager* self_Refman, ut_M_Mid_Dynamic* self_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self);
Returncode ut_M_Top_dyn0(ut_M_Top* self, Ref_Manager* self_Refman, ut_M_Top_Dynamic* self_Dynamic);
Returncode ut_M_Top_dyn3(ut_M_Top* self, Ref_Manager* self_Refman, ut_M_Top_Dynamic* self_Dynamic);
void ut_M_Top_Del(ut_M_Top* self);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_dyn0, ut_M_Base_dyn1};
ut_M_Mid_Dynamic ut_M_Mid_dynamic = {{(Dynamic_Del)ut_M_Mid_Del, (Func)ut_M_Mid_dyn0, ut_M_Base_dyn1}, ut_M_Mid_dyn2};
ut_M_Top_Dynamic ut_M_Top_dynamic = {{{(Dynamic_Del)ut_M_Top_Del, (Func)ut_M_Top_dyn0, ut_M_Base_dyn1}, ut_M_Mid_dyn2}, ut_M_Top_dyn3};
Returncode ut_M_Base_stat(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_Base_dyn0(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_Base_dyn1(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    DYN_SELF_REF_DEL(ut_M_Base, _, b);
    LUMI_owner_dec_ref(self->b_Refman);
}
Returncode ut_M_Mid_dyn0(ut_M_Mid* self, Ref_Manager* self_Refman, ut_M_Mid_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_Mid_dyn2(ut_M_Mid* self, Ref_Manager* self_Refman, ut_M_Mid_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Mid_Del(ut_M_Mid* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
    DYN_SELF_REF_DEL(ut_M_Mid, _base._, m);
    LUMI_owner_dec_ref(self->m_Refman);
}
Returncode ut_M_Top_dyn0(ut_M_Top* self, Ref_Manager* self_Refman, ut_M_Top_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_err = ut_M_Mid_dyn0(&(self->_base), self_Refman, &(self_Dynamic->_base));
    CHECK(16)
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_Top_dyn3(ut_M_Top* self, Ref_Manager* self_Refman, ut_M_Top_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_err = ut_M_Mid_dyn0(&(self->_base), self_Refman, &(self_Dynamic->_base));
    CHECK(18)
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Top_Del(ut_M_Top* self) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base));
    DYN_SELF_REF_DEL(ut_M_Top, _base._base._, t);
    LUMI_owner_dec_ref(self->t_Refman);
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
Returncode ut_M_name(void);
Returncode ut_M_name(void) {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
/// @ t1
Returncode ut_M_name(String* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman, Int num);
Returncode ut_M_name(String* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman, Int num) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(text_Refman);
LUMI_cleanup:
    LUMI_dec_ref(text_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
/// @ t2
Returncode ut_M_name(String** text, Ref_Manager** text_Refman, Int* num);
Returncode ut_M_name(String** text, Ref_Manager** text_Refman, Int* num) {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
/// @ t3
Returncode ut_M_name(Char param, String** out, Ref_Manager** out_Refman);
Returncode ut_M_name(Char param, String** out, Ref_Manager** out_Refman) {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
/// @ t4
Returncode ut_M_name(Array* array, Ref_Manager* array_Refman);
Returncode ut_M_name(Array* array, Ref_Manager* array_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(array_Refman);
LUMI_cleanup:
    LUMI_dec_ref(array_Refman);
    return LUMI_err;
}
/// @ t5
Returncode ut_M_name(Returncode (*fun)(Int x, Int* y), Returncode (**joy)(void));
Returncode ut_M_name(Returncode (*fun)(Int x, Int* y), Returncode (**joy)(void)) {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
/// @ t6
Returncode ut_M_name(void);
Returncode ut_M_name(void) {
    Returncode LUMI_err = OK;
    Int x = 0;
LUMI_cleanup:
    return LUMI_err;
}
/// @ t7
Returncode ut_M_name(String* self, Ref_Manager* self_Refman, Int px, String* pu, Ref_Manager* pu_Refman, String* po, Ref_Manager* po_Refman, String** oself, Ref_Manager** oself_Refman, Int* ox, String** ou, Ref_Manager** ou_Refman, String** oo, Ref_Manager** oo_Refman);
Returncode ut_M_name(String* self, Ref_Manager* self_Refman, Int px, String* pu, Ref_Manager* pu_Refman, String* po, Ref_Manager* po_Refman, String** oself, Ref_Manager** oself_Refman, Int* ox, String** ou, Ref_Manager** ou_Refman, String** oo, Ref_Manager** oo_Refman) {
    Returncode LUMI_err = OK;
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
    String* aux_String_1 = NULL;
    Ref_Manager* aux_String_1_Refman = NULL;
    String aux_String_2_Var = {0};
    String* aux_String_2 = NULL;
    Ref_Manager* aux_String_2_Refman = NULL;
    String aux_String_3_Var = {0};
    String* aux_String_3 = NULL;
    Ref_Manager* aux_String_3_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(pu_Refman);
    INIT_VAR(6, v)
    v_Var.values = v_Values;
    INIT_NEW(7, n, LUMI_new_string(12));
    INIT_NEW(8, aux_String_0, LUMI_new_string(12));
    aux_String_1 = aux_String_0;
    aux_String_1_Refman = aux_String_0_Refman;
    aux_String_0 = NULL;
    aux_String_0_Refman = NULL;
    String_Del(o);
    LUMI_owner_dec_ref(o_Refman);
    o_Refman = aux_String_1_Refman;
    o = aux_String_1;
    aux_String_1 = NULL;
    aux_String_1_Refman = NULL;
    INIT_STRING_CONST(9, aux_String_2, "constant string");
    aux_Ref_Manager = u_Refman;
    u_Refman = aux_String_2_Refman;
    LUMI_inc_ref(u_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    u = aux_String_2;
    INIT_VAR(10, aux_String_3)
    aux_String_3_Var.length = 6;
    aux_String_3_Var.max_length = aux_String_3_Var.length + 1;
    aux_String_3_Var.values = (po)->values + (2);
    CHECK_REF(10, po, po_Refman)
    if ((2) < 0 || (6) < 0 || (2) + (6) > (po)->length) RAISE(10, slice_index)
    aux_Ref_Manager = pu_Refman;
    pu_Refman = po_Refman;
    LUMI_inc_ref(pu_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    pu = aux_String_3;
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_3_Refman);
    LUMI_var_dec_ref(aux_String_2_Refman);
    String_Del(aux_String_1);
    LUMI_owner_dec_ref(aux_String_1_Refman);
    String_Del(aux_String_0);
    LUMI_owner_dec_ref(aux_String_0_Refman);
    String_Del(n);
    LUMI_owner_dec_ref(n_Refman);
    LUMI_var_dec_ref(v_Refman);
    String_Del(o);
    LUMI_owner_dec_ref(o_Refman);
    LUMI_dec_ref(u_Refman);
    String_Del(po);
    LUMI_owner_dec_ref(po_Refman);
    LUMI_dec_ref(pu_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
/// @ t8
typedef struct ut_M_Struct ut_M_Struct;
typedef struct ut_M_Class ut_M_Class;
typedef struct ut_M_Class_Dynamic ut_M_Class_Dynamic;
struct ut_M_Struct {
    ut_M_Struct* s;
    Ref_Manager* s_Refman;
    Array* as;
    Ref_Manager* as_Refman;
};
struct ut_M_Class {
    ut_M_Class* c;
    Ref_Manager* c_Refman;
    ut_M_Class_Dynamic* c_Dynamic;
    Array* ac;
    Ref_Manager* ac_Refman;
};
struct ut_M_Class_Dynamic {
    Dynamic_Del _del;
    Returncode (*meth)(ut_M_Class* self, Ref_Manager* self_Refman, ut_M_Class_Dynamic* self_Dynamic);
};
void ut_M_Struct_Del(ut_M_Struct* self);
Returncode ut_M_Class_meth(ut_M_Class* self, Ref_Manager* self_Refman, ut_M_Class_Dynamic* self_Dynamic);
void ut_M_Class_Del(ut_M_Class* self);
Returncode ut_M_name(ut_M_Struct* ps, Ref_Manager* ps_Refman, ut_M_Class* pc, Ref_Manager* pc_Refman, ut_M_Class_Dynamic* pc_Dynamic, Array* pas, Ref_Manager* pas_Refman, Array* pac, Ref_Manager* pac_Refman);
Generic_Type_Dynamic ut_M_Struct_dynamic = {(Dynamic_Del)ut_M_Struct_Del};
ut_M_Class_Dynamic ut_M_Class_dynamic = {(Dynamic_Del)ut_M_Class_Del, ut_M_Class_meth};
void ut_M_Struct_Del(ut_M_Struct* self) {
    if (self == NULL) return;
    ARRAY_DEL(ut_M_Struct, self->as)
    LUMI_owner_dec_ref(self->as_Refman);
    SELF_REF_DEL(ut_M_Struct, s);
    LUMI_owner_dec_ref(self->s_Refman);
}
Returncode ut_M_Class_meth(ut_M_Class* self, Ref_Manager* self_Refman, ut_M_Class_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Class_Del(ut_M_Class* self) {
    if (self == NULL) return;
    ARRAY_DEL(ut_M_Class, self->ac)
    LUMI_owner_dec_ref(self->ac_Refman);
    DYN_SELF_REF_DEL(ut_M_Class, _, c);
    LUMI_owner_dec_ref(self->c_Refman);
}
Returncode ut_M_name(ut_M_Struct* ps, Ref_Manager* ps_Refman, ut_M_Class* pc, Ref_Manager* pc_Refman, ut_M_Class_Dynamic* pc_Dynamic, Array* pas, Ref_Manager* pas_Refman, Array* pac, Ref_Manager* pac_Refman) {
    Returncode LUMI_err = OK;
    ut_M_Struct* s = NULL;
    Ref_Manager* s_Refman = NULL;
    ut_M_Class* c = NULL;
    Ref_Manager* c_Refman = NULL;
    ut_M_Class_Dynamic* c_Dynamic = NULL;
    Array* as = NULL;
    Ref_Manager* as_Refman = NULL;
    Array* ac = NULL;
    Ref_Manager* ac_Refman = NULL;
    Array* ai = NULL;
    Ref_Manager* ai_Refman = NULL;
    Array* af = NULL;
    Ref_Manager* af_Refman = NULL;
LUMI_cleanup:
    ARRAY_DEL(File, af)
    LUMI_owner_dec_ref(af_Refman);
    LUMI_owner_dec_ref(ai_Refman);
    ARRAY_DEL(ut_M_Class, ac)
    LUMI_owner_dec_ref(ac_Refman);
    ARRAY_DEL(ut_M_Struct, as)
    LUMI_owner_dec_ref(as_Refman);
    if (c_Dynamic != NULL) c_Dynamic->_del(c);
    LUMI_owner_dec_ref(c_Refman);
    ut_M_Struct_Del(s);
    LUMI_owner_dec_ref(s_Refman);
    ARRAY_DEL(ut_M_Class, pac)
    LUMI_owner_dec_ref(pac_Refman);
    ARRAY_DEL(ut_M_Struct, pas)
    LUMI_owner_dec_ref(pas_Refman);
    if (pc_Dynamic != NULL) pc_Dynamic->_del(pc);
    LUMI_owner_dec_ref(pc_Refman);
    ut_M_Struct_Del(ps);
    LUMI_owner_dec_ref(ps_Refman);
    return LUMI_err;
}
/// @ t9
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    Int x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    Returncode (*meth)(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic);
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_name(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
Returncode ut_M_name(ut_M_Test** t, Ref_Manager** t_Refman, ut_M_Test_Dynamic** t_Dynamic) {
    Returncode LUMI_err = OK;
    ut_M_Test* aux_Test_0 = NULL;
    Ref_Manager* aux_Test_0_Refman = NULL;
    ut_M_Test_Dynamic* aux_Test_0_Dynamic = NULL;
    aux_Test_0 = NULL;
    aux_Test_0_Refman = NULL;
    aux_Test_0_Dynamic = NULL;
    if (*t_Dynamic != NULL) (*t_Dynamic)->_del(*t);
    LUMI_owner_dec_ref(*t_Refman);
    *t_Refman = aux_Test_0_Refman;
    *t_Dynamic = aux_Test_0_Dynamic;
    *t = aux_Test_0;
    aux_Test_0 = NULL;
    aux_Test_0_Refman = NULL;
    aux_Test_0_Dynamic = NULL;
LUMI_cleanup:
    if (aux_Test_0_Dynamic != NULL) aux_Test_0_Dynamic->_del(aux_Test_0);
    LUMI_owner_dec_ref(aux_Test_0_Refman);
    return LUMI_err;
}
/// @ tm0
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    Int x = 0;
LUMI_cleanup:
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
/// @ te19
multidimensional array not supported yet...
/// @ te20
indentation too short, expected 8 got 4
/// @@ test-members
/// @ t0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
    String* str;
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
Returncode ut_M_Test_name(ut_M_Test* self, Ref_Manager* self_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_name(ut_M_Test* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    CHECK_REF(4, self, self_Refman)
    self->x = 2;
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
/// @ t2
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
Returncode ut_M_Test_name(ut_M_Test* self, Ref_Manager* self_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_name(ut_M_Test* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    Int x = 0;
    LUMI_inc_ref(self_Refman);
    CHECK_REF(5, self, self_Refman)
    x = self->x;
    if (x > 2) {
        x = 2;
    }
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
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
Returncode ut_M_Test1_fun(ut_M_Test1* self, Ref_Manager* self_Refman);
void ut_M_Test1_Del(ut_M_Test1* self);
Returncode ut_M_Test2_name(ut_M_Test2* self, Ref_Manager* self_Refman);
void ut_M_Test2_Del(ut_M_Test2* self);
Returncode ut_M_fun(void);
Generic_Type_Dynamic ut_M_Test1_dynamic = {(Dynamic_Del)ut_M_Test1_Del};
Generic_Type_Dynamic ut_M_Test2_dynamic = {(Dynamic_Del)ut_M_Test2_Del};
Int ut_M_name = 0;
Returncode ut_M_Test1_fun(ut_M_Test1* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test1_Del(ut_M_Test1* self) {
    if (self == NULL) return;
}
Returncode ut_M_Test2_name(ut_M_Test2* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test2_Del(ut_M_Test2* self) {
    if (self == NULL) return;
}
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
/// @ t8
redefinition of field "name"
/// @ t9
field name overrides method "name"
/// @ t10
redefinition of method "name"
/// @ t11
method name overrides field "name"
/// @ t12
assigning into an owner a non-owner access "user"
/// @@ test-return
/// @ t0
Returncode ut_M_name(void);
Returncode ut_M_name(void) {
    Returncode LUMI_err = OK;
    goto LUMI_cleanup;
LUMI_cleanup:
    return LUMI_err;
}
/// @ t1
Returncode ut_M_name(void);
Returncode ut_M_name(void) {
    Returncode LUMI_err = OK;
    USER_RAISE(2, NULL, NULL)
LUMI_cleanup:
    return LUMI_err;
}
/// @ t2
Returncode ut_M_name(void);
Returncode ut_M_name(void) {
    Returncode LUMI_err = OK;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    INIT_STRING_CONST(2, aux_String_0, "some error");
    USER_RAISE(2, aux_String_0, aux_String_0_Refman)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_0_Refman);
    return LUMI_err;
}
/// @ t3
Returncode ut_M_name(Array* arr, Ref_Manager* arr_Refman);
Returncode ut_M_name(Array* arr, Ref_Manager* arr_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(arr_Refman);
    CHECK_REF(2, arr, arr_Refman)
    if ((3) < 0 || (3) >= (arr)->length) RAISE(2, slice_index)
    USER_RAISE(2, ((String*)((arr)->values)) + 3, arr_Refman)
LUMI_cleanup:
    LUMI_dec_ref(arr_Refman);
    return LUMI_err;
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
ut_M_Test* tt = NULL;
    Ref_Manager* tt_Refman = NULL;
/// @ t4
char s_Values[12] = {0};
    String s_Var = {12, 0, NULL};
    String* s = NULL;
    Ref_Manager* s_Refman = NULL;
    INIT_VAR(1, s)
    s_Var.values = s_Values;
/// @ t5
Int a_Values[12] = {0};
    Array a_Var = {12, NULL};
    Array* a = NULL;
    Ref_Manager* a_Refman = NULL;
    INIT_VAR(1, a)
    a_Var.values = a_Values;
/// @ t6
ut_M_Test a_Values[12] = {{0}};
    Array a_Var = {12, NULL};
    Array* a = NULL;
    Ref_Manager* a_Refman = NULL;
    INIT_VAR(1, a)
    a_Var.values = a_Values;
/// @ t7
char sa_Chars[12 * 7];
    String sa_Values[12] = {{0}};
    Array sa_Var = {12, NULL};
    Array* sa = NULL;
    Ref_Manager* sa_Refman = NULL;
    INIT_VAR(1, sa)
    sa_Var.values = sa_Values;
    LUMI_set_var_string_array(12, 7, sa, sa_Chars);
/// @ t8
String* s = NULL;
    Ref_Manager* s_Refman = NULL;
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    INIT_NEW(1, s, LUMI_new_string(12));
    aux_String_0 = s;
    aux_String_0_Refman = s_Refman;
    s = NULL;
    s_Refman = NULL;
    String_Del(*so);
    LUMI_owner_dec_ref(*so_Refman);
    *so_Refman = aux_String_0_Refman;
    *so = aux_String_0;
    aux_String_0 = NULL;
    aux_String_0_Refman = NULL;
/// @ t9
ut_M_Tc a_Values[12] = {{{{{0}}}}};
    Array a_Var = {12, NULL};
    Array* a = NULL;
    Ref_Manager* a_Refman = NULL;
    INIT_VAR(1, a)
    a_Var.values = a_Values;
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
/// @ te9
array length is not constant
/// @ te10
illegal variable name "error--name"
/// @@ test-initialize
/// @ t0
ut_M_Test* aux_Test_0 = NULL;
    Ref_Manager* aux_Test_0_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    INIT_NEW(1, aux_Test_0, LUMI_alloc(sizeof(ut_M_Test)));
    LUMI_err = ut_M_Test_new(aux_Test_0, aux_Test_0_Refman, ut_M_i);
    CHECK(1)
    aux_Ref_Manager = ut_M_t_Refman;
    ut_M_t_Refman = aux_Test_0_Refman;
    LUMI_inc_ref(ut_M_t_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ut_M_t = aux_Test_0;
/// @ t1
String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    CHECK_REF(1, ut_M_arr, ut_M_arr_Refman)
    if ((0) < 0 || (0) >= (ut_M_arr)->length) RAISE(1, slice_index)
    INIT_NEW(1, aux_String_0, LUMI_new_string(((Int*)((ut_M_arr)->values))[0]));
    aux_Ref_Manager = ut_M_str_Refman;
    ut_M_str_Refman = aux_String_0_Refman;
    LUMI_inc_ref(ut_M_str_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ut_M_str = aux_String_0;
/// @ t2
Array* aux_Array_0 = NULL;
    Ref_Manager* aux_Array_0_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    CHECK_REF(1, ut_M_arr, ut_M_arr_Refman)
    if ((0) < 0 || (0) >= (ut_M_arr)->length) RAISE(1, slice_index)
    INIT_NEW(1, aux_Array_0, LUMI_new_array(((Int*)((ut_M_arr)->values))[0], sizeof(Int)));
    aux_Ref_Manager = ut_M_arr_Refman;
    ut_M_arr_Refman = aux_Array_0_Refman;
    LUMI_inc_ref(ut_M_arr_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ut_M_arr = aux_Array_0;
/// @ t3
Array* a = NULL;
    Ref_Manager* a_Refman = NULL;
    Array* aux_Array_0 = NULL;
    Ref_Manager* aux_Array_0_Refman = NULL;
    CHECK_REF(1, ut_M_arr, ut_M_arr_Refman)
    if ((0) < 0 || (0) >= (ut_M_arr)->length) RAISE(1, slice_index)
    INIT_NEW(1, aux_Array_0, LUMI_new_array(((Int*)((ut_M_arr)->values))[0], sizeof(ut_M_Test)));
    a = aux_Array_0;
    a_Refman = aux_Array_0_Refman;
    aux_Array_0 = NULL;
    aux_Array_0_Refman = NULL;
/// @ t4
Array* sa = NULL;
    Ref_Manager* sa_Refman = NULL;
    Array* aux_Array_0 = NULL;
    Ref_Manager* aux_Array_0_Refman = NULL;
    CHECK_REF(1, ut_M_arr, ut_M_arr_Refman)
    if ((0) < 0 || (0) >= (ut_M_arr)->length) RAISE(1, slice_index)
    CHECK_REF(1, ut_M_arr, ut_M_arr_Refman)
    if ((1) < 0 || (1) >= (ut_M_arr)->length) RAISE(1, slice_index)
    INIT_NEW(1, aux_Array_0, LUMI_new_string_array(((Int*)((ut_M_arr)->values))[0], ((Int*)((ut_M_arr)->values))[1]));
    sa = aux_Array_0;
    sa_Refman = aux_Array_0_Refman;
    aux_Array_0 = NULL;
    aux_Array_0_Refman = NULL;
/// @ t5
Int x = 0;
    CHECK_REF(1, ut_M_arr, ut_M_arr_Refman)
    if ((0) < 0 || (0) >= (ut_M_arr)->length) RAISE(1, slice_index)
    x = ((Int*)((ut_M_arr)->values))[0];
/// @ t6
String* s = NULL;
    Ref_Manager* s_Refman = NULL;
    s = ut_M_str;
    s_Refman = ut_M_str_Refman;
    LUMI_inc_ref(s_Refman);
/// @ t7
char s_Values[12] = {0};
    String s_Var = {12, 0, NULL};
    String* s = NULL;
    Ref_Manager* s_Refman = NULL;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    INIT_STRING_CONST(1, aux_String_0, "some string");
    INIT_VAR(1, s)
    s_Var.values = s_Values;
    LUMI_err = String_new(s, s_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(1)
/// @ t8
String* s = NULL;
    Ref_Manager* s_Refman = NULL;
    INIT_NEW(1, s, LUMI_new_string(ut_M_i));
    LUMI_err = String_new(s, s_Refman, ut_M_str, ut_M_str_Refman);
    CHECK(1)
/// @ t9
ut_M_Test* tt = NULL;
    Ref_Manager* tt_Refman = NULL;
    tt = &(ut_M_tc->_base._base._base);
    tt_Refman = ut_M_tc_Refman;
    LUMI_inc_ref(tt_Refman);
/// @ t10
ut_M_Test tt_Var = {0};
    ut_M_Test* tt = NULL;
    Ref_Manager* tt_Refman = NULL;
    INIT_VAR(1, tt)
    LUMI_err = ut_M_Test_new(tt, tt_Refman, 3);
    CHECK(1)
/// @ t11
ut_M_Test* tt = NULL;
    Ref_Manager* tt_Refman = NULL;
    INIT_NEW(1, tt, LUMI_alloc(sizeof(ut_M_Test)));
    LUMI_err = ut_M_Test_new(tt, tt_Refman, 3);
    CHECK(1)
/// @ t12
ut_M_Test* aux_Test_0 = NULL;
    Ref_Manager* aux_Test_0_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    INIT_NEW(1, aux_Test_0, LUMI_alloc(sizeof(ut_M_Test)));
    LUMI_err = ut_M_Test_new(aux_Test_0, aux_Test_0_Refman, 3);
    CHECK(1)
    aux_Ref_Manager = ut_M_t_Refman;
    ut_M_t_Refman = aux_Test_0_Refman;
    LUMI_inc_ref(ut_M_t_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ut_M_t = aux_Test_0;
/// @ t13
ut_M_Tb* tt = NULL;
    Ref_Manager* tt_Refman = NULL;
    ut_M_Tb_Dynamic* tt_Dynamic = NULL;
    tt = ut_M_tb;
    tt_Refman = ut_M_tb_Refman;
    LUMI_inc_ref(tt_Refman);
    tt_Dynamic = ut_M_tb_Dynamic;
/// @ t14
ut_M_Ta* ota = NULL;
    Ref_Manager* ota_Refman = NULL;
    ut_M_Ta_Dynamic* ota_Dynamic = NULL;
    ota = &(ut_M_tb->_base);
    ota_Refman = ut_M_tb_Refman;
    ota_Dynamic = &(ut_M_tb_Dynamic->_base);
    ut_M_tb = NULL;
    ut_M_tb_Refman = NULL;
    ut_M_tb_Dynamic = NULL;
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
CHECK_REF(1, ut_M_t, ut_M_t_Refman)
    if (ut_M_t->num > 3) {
        ut_M_i -= 2;
    }
/// @ t1
if (ut_M_i > 3) {
        ut_M_i -= 2;
    }
    else {
        ut_M_i += 1;
    }
/// @ t2
if (ut_M_i > 3) {
        ut_M_i -= 3;
    }
    else {
        CHECK_REF(3, ut_M_t, ut_M_t_Refman)
        if (ut_M_t->num > 2) {
            ut_M_i -= 2;
        }
        else {
            CHECK_REF(5, ut_M_t, ut_M_t_Refman)
            if (ut_M_t->num > 1) {
                ut_M_i -= 1;
            }
            else {
                ut_M_i += 1;
            }
        }
    }
/// @ t3
if (ut_M_b) {
        goto LUMI_cleanup;
    }
    ut_M_i = 3;
/// @ t4
if (ut_M_b && ut_M_b) {
        ut_M_i += 1;
    }
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
while (true) {
        break;
    }
/// @ t2
while (true) {
        CHECK_REF(2, ut_M_t, ut_M_t_Refman)
        if (!(ut_M_t->num > 3)) break;
    }
/// @ t3
while (true) {
        continue;
    }
/// @ t4
while (true) {
        if (true) {
            if (!(false)) break;
        }
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
/// @ te7
"break" used not inside loop
/// @ te8
expected new-line after "break", got " "
/// @ te9
expected new-line after "continue", got " "
/// @@ test-for-loop
/// @ t0
Int n = 0;
    for (n = 0; n < 5; ++n) {
        ut_M_i += n;
    }
/// @ t1
Int n = 0;
    CHECK_REF(1, ut_M_t, ut_M_t_Refman)
    CHECK_REF(1, ut_M_str, ut_M_str_Refman)
    for (n = ut_M_t->num; n < ut_M_str->length; ++n) {
        ut_M_i += n;
    }
/// @ t2
Char ch = 0;
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    aux_Ref_Manager = aux_String_0_Refman;
    aux_String_0_Refman = ut_M_str_Refman;
    LUMI_inc_ref(aux_String_0_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_String_0 = ut_M_str;
    CHECK_REF(1, aux_String_0, aux_String_0_Refman)
    {int ch_Index; for (ch_Index = 0; ch_Index < aux_String_0->length; ++ch_Index) {
        CHECK_REF(1, aux_String_0, aux_String_0_Refman)
        if ((ch_Index) < 0 || (ch_Index) >= (aux_String_0)->length) RAISE(1, slice_index)
        ch = ((aux_String_0)->values)[ch_Index];
        ut_M_c = ch;
    }}
    aux_Ref_Manager = aux_String_0_Refman;
    aux_String_0_Refman = NULL;
    LUMI_inc_ref(aux_String_0_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_String_0 = NULL;
/// @ t3
Int n = 0;
    Array* aux_Array_0 = NULL;
    Ref_Manager* aux_Array_0_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    aux_Ref_Manager = aux_Array_0_Refman;
    aux_Array_0_Refman = ut_M_arr_Refman;
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_Array_0 = ut_M_arr;
    CHECK_REF(1, aux_Array_0, aux_Array_0_Refman)
    {int n_Index; for (n_Index = 0; n_Index < aux_Array_0->length; ++n_Index) {
        CHECK_REF(1, aux_Array_0, aux_Array_0_Refman)
        if ((n_Index) < 0 || (n_Index) >= (aux_Array_0)->length) RAISE(1, slice_index)
        n = ((Int*)((aux_Array_0)->values))[n_Index];
        ut_M_i += n;
    }}
    aux_Ref_Manager = aux_Array_0_Refman;
    aux_Array_0_Refman = NULL;
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_Array_0 = NULL;
/// @ t4
String* s = NULL;
    Ref_Manager* s_Refman = NULL;
    Array* aux_Array_0 = NULL;
    Ref_Manager* aux_Array_0_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    aux_Ref_Manager = aux_Array_0_Refman;
    aux_Array_0_Refman = ut_M_sarr_Refman;
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_Array_0 = ut_M_sarr;
    CHECK_REF(1, aux_Array_0, aux_Array_0_Refman)
    {int s_Index; for (s_Index = 0; s_Index < aux_Array_0->length; ++s_Index) {
        CHECK_REF(1, aux_Array_0, aux_Array_0_Refman)
        if ((s_Index) < 0 || (s_Index) >= (aux_Array_0)->length) RAISE(1, slice_index)
        aux_Ref_Manager = s_Refman;
        s_Refman = aux_Array_0_Refman;
        LUMI_inc_ref(s_Refman);
        LUMI_dec_ref(aux_Ref_Manager);
        aux_Ref_Manager = NULL;
        s = ((String*)((aux_Array_0)->values)) + s_Index;
        aux_Ref_Manager = ut_M_str_Refman;
        ut_M_str_Refman = s_Refman;
        LUMI_inc_ref(ut_M_str_Refman);
        LUMI_dec_ref(aux_Ref_Manager);
        aux_Ref_Manager = NULL;
        ut_M_str = s;
    }}
    aux_Ref_Manager = aux_Array_0_Refman;
    aux_Array_0_Refman = NULL;
    LUMI_inc_ref(aux_Array_0_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_Array_0 = NULL;
/// @ t5
Int n = 0;
    for (n = 0; n < 5; ++n) {
        ut_M_i += n;
    }
/// @ t6
Int n = 0;
    for (n = 0; n < 5; ++n) {
        ut_M_i += n;
    }
    for (n = 0; n < 7; ++n) {
        ut_M_i += n;
    }
/// @ t7
Int n = 0;
    for (n = 0; n < 1 + 2; ++n) {
        ut_M_i += n;
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
/// @ ta0
CHECK_REF(1, ut_M_t, ut_M_t_Refman)
    TEST_ASSERT(1, ut_M_t->num == 2)
/// @ ta1
do {
        ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
        CHECK_REF(1, ut_M_t, ut_M_t_Refman)
        #undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
        --LUMI_trace_ignore_count;
        TEST_FAIL(1, 16, "error not raised")
    } while (false);
    --LUMI_trace_ignore_count;
    LUMI_err = OK;
/// @ ta2
do {
        ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
        LUMI_err = ut_M_fun0();
        CHECK(1)
        #undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
        --LUMI_trace_ignore_count;
        TEST_FAIL(1, 16, "error not raised")
    } while (false);
    --LUMI_trace_ignore_count;
    LUMI_err = OK;
/// @ ta3
{char* LUMI_expected_error_prev;
    int LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error_prev = LUMI_expected_error;
    LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
    LUMI_expected_error = "expected error";
    LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
    do {
        ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
        CHECK_REF(1, ut_M_t, ut_M_t_Refman)
        #undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
        --LUMI_trace_ignore_count;
        LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
        LUMI_expected_error = LUMI_expected_error_prev;
        TEST_FAIL(1, 16, "error not raised")
    } while (false);
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    if (LUMI_expected_error == NULL) {
        LUMI_expected_error = LUMI_expected_error_prev;
        TEST_FAIL_NULL(1)
    }
    LUMI_expected_error = LUMI_expected_error_prev;}
    LUMI_err = OK;
/// @ ta4
{char* LUMI_expected_error_prev;
    int LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error_prev = LUMI_expected_error;
    LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
    LUMI_expected_error = "expected error in the function";
    LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
    do {
        ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
        LUMI_err = ut_M_fun0();
        CHECK(1)
        #undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
        --LUMI_trace_ignore_count;
        LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
        LUMI_expected_error = LUMI_expected_error_prev;
        TEST_FAIL(1, 16, "error not raised")
    } while (false);
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    if (LUMI_expected_error == NULL) {
        LUMI_expected_error = LUMI_expected_error_prev;
        TEST_FAIL_NULL(1)
    }
    LUMI_expected_error = LUMI_expected_error_prev;}
    LUMI_err = OK;
/// @ ta5
{char* LUMI_expected_error_prev;
    int LUMI_expected_error_trace_ignore_count_prev;
    LUMI_expected_error_prev = LUMI_expected_error;
    LUMI_expected_error_trace_ignore_count_prev = LUMI_expected_error_trace_ignore_count;
    LUMI_expected_error = "expected error in new line";
    LUMI_expected_error_trace_ignore_count = LUMI_trace_ignore_count + 1;
    do {
        ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
        CHECK_REF(1, ut_M_t, ut_M_t_Refman)
        #undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
        --LUMI_trace_ignore_count;
        LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
        LUMI_expected_error = LUMI_expected_error_prev;
        TEST_FAIL(1, 16, "error not raised")
    } while (false);
    --LUMI_trace_ignore_count;
    LUMI_expected_error_trace_ignore_count = LUMI_expected_error_trace_ignore_count_prev;
    if (LUMI_expected_error == NULL) {
        LUMI_expected_error = LUMI_expected_error_prev;
        TEST_FAIL_NULL(1)
    }
    LUMI_expected_error = LUMI_expected_error_prev;}
    LUMI_err = OK;
/// @ tm0
Returncode ut_M_fun(void);
Returncode ut_M_fun_Mock(void);
Bool ut_M_fun_Mock_active = true;
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
    LUMI_err = ut_M_fun_Mock();
    CHECK(2)
LUMI_cleanup:
    return LUMI_err;
}
Returncode ut_M_fun_Mock(void) {
    Returncode LUMI_err = OK;
    if (!ut_M_fun_Mock_active) return ut_M_fun();
    USER_RAISE(4, NULL, NULL)
LUMI_cleanup:
    return LUMI_err;
}
/// @ tm1
Returncode ut_M_fun_Mock(void);
Bool ut_M_fun_Mock_active = true;
Returncode ut_M_fun(void);
Returncode ut_M_fun_Mock(void) {
    Returncode LUMI_err = OK;
    if (!ut_M_fun_Mock_active) return ut_M_fun();
LUMI_cleanup:
    return LUMI_err;
}
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
    LUMI_err = ut_M_fun_Mock();
    CHECK(3)
LUMI_cleanup:
    return LUMI_err;
}
/// @ tm2
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, Int x);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, Int x);
Bool ut_M_Test_meth_Mock_active = true;
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, Int x) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_err = ut_M_Test_meth_Mock(self, self_Refman, x);
    CHECK(5)
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, Int x) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    if (!ut_M_Test_meth_Mock_active) return ut_M_Test_meth(self, self_Refman, x);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
/// @ tm3
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    Int x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    Returncode (*meth)(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x);
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x);
Bool ut_M_Test_meth_Mock_active = true;
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth_Mock};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    if (self_Dynamic == NULL) RAISE(5, empty_object)
    LUMI_err = self_Dynamic->meth(self, self_Refman, self_Dynamic, x);
    CHECK(5)
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    if (!ut_M_Test_meth_Mock_active) return ut_M_Test_meth(self, self_Refman, self_Dynamic, x);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
/// @ tm4
Returncode ut_M_fun(Int x, Int* y);
Returncode ut_M_fun_Mock(Int x, Int* y);
Bool ut_M_fun_Mock_active = true;
Returncode ut_M_fun(Int x, Int* y) {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
Returncode ut_M_fun_Mock(Int x, Int* y) {
    Returncode LUMI_err = OK;
    if (!ut_M_fun_Mock_active) return ut_M_fun(x, y);
    LUMI_err = ut_M_fun(x, &(*y));
    CHECK(3)
    ut_M_fun_Mock_active = false;
    LUMI_err = ut_M_fun_Mock(x, &(*y));
    CHECK(5)
    ut_M_fun_Mock_active = true;
LUMI_cleanup:
    return LUMI_err;
}
/// @ tm5
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, Int x, Int* y);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, Int x, Int* y);
Bool ut_M_Test_meth_Mock_active = true;
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, Int x, Int* y) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_err = ut_M_Test_meth_Mock(self, self_Refman, x, &(*y));
    CHECK(4)
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, Int x, Int* y) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    if (!ut_M_Test_meth_Mock_active) return ut_M_Test_meth(self, self_Refman, x, y);
    LUMI_err = ut_M_Test_meth(self, self_Refman, x, &(*y));
    CHECK(6)
    LUMI_err = ut_M_Test_meth(self, self_Refman, x, &(*y));
    CHECK(7)
    ut_M_Test_meth_Mock_active = false;
    LUMI_err = ut_M_Test_meth_Mock(self, self_Refman, x, &(*y));
    CHECK(9)
    ut_M_Test_meth_Mock_active = true;
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
/// @ tm6
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    Int x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    Returncode (*meth)(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y);
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y);
Bool ut_M_Test_meth_Mock_active = true;
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth_Mock};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    if (self_Dynamic == NULL) RAISE(4, empty_object)
    LUMI_err = self_Dynamic->meth(self, self_Refman, self_Dynamic, x, &(*y));
    CHECK(4)
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Int x, Int* y) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    if (!ut_M_Test_meth_Mock_active) return ut_M_Test_meth(self, self_Refman, self_Dynamic, x, y);
    LUMI_err = ut_M_Test_meth(self, self_Refman, self_Dynamic, x, &(*y));
    CHECK(6)
    ut_M_Test_meth_Mock_active = false;
    LUMI_err = ut_M_Test_meth_Mock(self, self_Refman, self_Dynamic, x, &(*y));
    CHECK(8)
    ut_M_Test_meth_Mock_active = true;
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
/// @ tm7
Returncode ut_M_fun(void);
Returncode Sys_print_Mock(Sys* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman);
Bool Sys_print_Mock_active = true;
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    String aux_String_1_Var = {0};
    String* aux_String_1 = NULL;
    Ref_Manager* aux_String_1_Refman = NULL;
    INIT_STRING_CONST(2, aux_String_0, "mock print");
    LUMI_err = Sys_print_Mock(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(2)
    INIT_STRING_CONST(3, aux_String_1, "really print");
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
    CHECK(3)
    Sys_print_Mock_active = false;
    Sys_print_Mock_active = true;
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
    return LUMI_err;
}
Returncode Sys_print_Mock(Sys* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(text_Refman);
    if (!Sys_print_Mock_active) return Sys_print(self, self_Refman, text, text_Refman);
LUMI_cleanup:
    LUMI_dec_ref(text_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
/// @ tt0
Returncode ut_M_fun0(void);
Returncode ut_M_fun1(void);
Returncode ut_M_fun2(void);
int LUMI_file0_line_count[30] = {
    -1,-1, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,-1, 0, 0, 0,
     0, 0, 0, 0,-1
};
int LUMI_file1_line_count[7] = {
    -1,-1,-1, 0,-1, 0,-1
};
File_Coverage LUMI_file_coverage[2] = {
    {"mock.4.lm", 30, LUMI_file0_line_count},
    {"path\\second.4.lm", 7, LUMI_file1_line_count}
};
Returncode ut_M_fun0(void) {
    Returncode LUMI_err = OK;
    Int x = 0;
    Int y = 0;
    Int n = 0;
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
    }
    else {
        ++LUMI_file_coverage[0].line_count[8];
        if (y < 0) {
            ++LUMI_file_coverage[0].line_count[9];
            y = 0;
        }
        else {
            ++LUMI_file_coverage[0].line_count[11];
            y += 1;
        }
    }
    ++LUMI_file_coverage[0].line_count[12];
    do {
        ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
        ++LUMI_file_coverage[0].line_count[13];
        x = 0;
        ++LUMI_file_coverage[0].line_count[14];
        LUMI_err = Sys_print(sys, sys_Refman, NULL, NULL);
        CHECK(14)
        ++LUMI_file_coverage[0].line_count[15];
        y = 0;
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    } while (false);
    --LUMI_trace_ignore_count;
    ++LUMI_file_coverage[0].line_count[16];
    if (LUMI_err != OK) {
        LUMI_err = OK;
        ++LUMI_file_coverage[0].line_count[17];
        x = 1;
        ++LUMI_file_coverage[0].line_count[18];
        x = 2;
    }
    ++LUMI_file_coverage[0].line_count[19];
    if (x > 3) {
        ++LUMI_file_coverage[0].line_count[20];
        goto LUMI_cleanup;
    }
    else {
        ++LUMI_file_coverage[0].line_count[22];
        USER_RAISE(22, NULL, NULL)
    }
    ++LUMI_file_coverage[0].line_count[23];
    while (true) {
        ++LUMI_file_coverage[0].line_count[24];
        if (!(x > 1)) break;
        ++LUMI_file_coverage[0].line_count[25];
        if (x == 5) {
            ++LUMI_file_coverage[0].line_count[26];
            continue;
        }
    }
    ++LUMI_file_coverage[0].line_count[27];
    for (n = 0; n < 3; ++n) {
        ++LUMI_file_coverage[0].line_count[28];
        x += y;
    }
LUMI_cleanup:
    return LUMI_err;
}
Returncode ut_M_fun1(void) {
    Returncode LUMI_err = OK;
    ++LUMI_file_coverage[1].line_count[3];
    LUMI_err = ut_M_fun0();
    CHECK(3)
LUMI_cleanup:
    return LUMI_err;
}
Returncode ut_M_fun2(void) {
    Returncode LUMI_err = OK;
    ++LUMI_file_coverage[1].line_count[5];
    LUMI_err = ut_M_fun1();
    CHECK(5)
LUMI_cleanup:
    return LUMI_err;
}
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    Bool LUMI_success = true;
    LUMI_success &= LUMI_run_test("fun2", ut_M_fun2);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 2);
    return LUMI_success? LUMI_err : FAIL;
}
TEST_MAIN_FUNC
/// @ tt1
Returncode ut_M_fun(void);
Returncode second_M_fun0(void);
Returncode second_M_fun1(void);
int LUMI_file0_line_count[5] = {
    -1,-1, 0,-1,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.4.lm", 5, LUMI_file0_line_count}
};
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
    Int x = 0;
    ++LUMI_file_coverage[0].line_count[2];
LUMI_cleanup:
    return LUMI_err;
}
Returncode second_M_fun0(void) {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
Returncode second_M_fun1(void) {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    Bool LUMI_success = true;
    LUMI_success &= LUMI_run_test("fun0", second_M_fun0);
    LUMI_success &= LUMI_run_test("fun1", second_M_fun1);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
}
TEST_MAIN_FUNC
/// @ tmg0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    String* s;
    Ref_Manager* s_Refman;
};
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_Test_MockDel(Ref self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    IGNORE_ERRORS( ut_M_Test_MockDel(self) )
    LUMI_dec_ref(self->s_Refman);
}
Returncode ut_M_Test_MockDel(Ref self) {
    Returncode LUMI_err = OK;
    Ref r = NULL;
    r = self;
LUMI_cleanup:
    return LUMI_err;
}
/// @ tmg1
Returncode delete_Mock(Ref self);
Returncode delete_Mock(Ref self) {
    Returncode LUMI_err = OK;
    Ref r = NULL;
    r = self;
LUMI_cleanup:
    return LUMI_err;
}
Returncode new_Mock(Bool* allocate_success) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
MAIN_FUNC
/// @ tmg2
Returncode new_Mock(Bool* allocate_success);
Returncode new_Mock(Bool* allocate_success) {
    Returncode LUMI_err = OK;
    *allocate_success = false;
LUMI_cleanup:
    return LUMI_err;
}
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
MAIN_FUNC
/// @ tr0
Ref r = NULL;
/// @ tr1
Ref r = NULL;
    r = ut_M_str;
/// @ tr2
Ref r = NULL;
    r = NULL;
/// @ tr3
Ref r = NULL;
    r = ut_M_str;
/// @ tr4
Ref r = NULL;
    TEST_ASSERT(2, (void*)r == r)
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
/// @ te19-copy
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
mock function has no member "error"
/// @ te30
accessing mock function field in dynamic call to "meth"
/// @@ test-native
/// @ tf0
Returncode external(void);
Returncode ut_M_call(void);
Returncode ut_M_call(void) {
    Returncode LUMI_err = OK;
    LUMI_err = external();
    CHECK(3)
LUMI_cleanup:
    return LUMI_err;
}
/// @ tf1
typedef struct ut_M_Test ut_M_Test;
typedef struct ut_M_Test_Dynamic ut_M_Test_Dynamic;
struct ut_M_Test {
    Int x;
};
struct ut_M_Test_Dynamic {
    Dynamic_Del _del;
    Returncode (*meth)(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic);
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Returncode external(Int i, String* s, ut_M_Test* ta, Int* io);
Returncode ut_M_call(void);
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_meth};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
Returncode ut_M_call(void) {
    Returncode LUMI_err = OK;
    Int i = 0;
    String* s = NULL;
    Ref_Manager* s_Refman = NULL;
    ut_M_Test* ta = NULL;
    Ref_Manager* ta_Refman = NULL;
    ut_M_Test_Dynamic* ta_Dynamic = NULL;
    LUMI_err = external(5, s, ta, &(i));
    CHECK(9)
LUMI_cleanup:
    LUMI_dec_ref(ta_Refman);
    LUMI_dec_ref(s_Refman);
    return LUMI_err;
}
/// @ tv0
Returncode ut_M_use(void);
extern Int x;
Returncode ut_M_use(void) {
    Returncode LUMI_err = OK;
    x = 2;
LUMI_cleanup:
    return LUMI_err;
}
/// @ tt0
typedef void* Native;
Returncode external(Native n, Native* no);
/// @ te0
expected space after "native", got "("
/// @ te1
expected space after "native" keyword, got "new-line"
/// @ te2
unknown "native" keyword "error"
/// @ tef1
owner argument to native function
/// @ tef2
user output to native function
/// @ tef3
owner argument to native function
/// @ tef4
redefinition of function "error"
/// @ tev3
only primitive types supported for native variable, got "String"
/// @@ test-parameter-type
/// @ t0
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
    Array* arr;
    Ref_Manager* arr_Refman;
};
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic, Array* arr, Ref_Manager* arr_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic, Array* arr, Ref_Manager* arr_Refman) {
    Returncode LUMI_err = OK;
    Generic_Type* x = NULL;
    Ref_Manager* x_Refman = NULL;
    Generic_Type_Dynamic* x_Dynamic = NULL;
    ut_M_Test* t = NULL;
    Ref_Manager* t_Refman = NULL;
    Generic_Type* aux_Generic_Type_0 = NULL;
    Ref_Manager* aux_Generic_Type_0_Refman = NULL;
    Generic_Type_Dynamic* aux_Generic_Type_0_Dynamic = NULL;
    Generic_Type* aux_Generic_Type_1 = NULL;
    Ref_Manager* aux_Generic_Type_1_Refman = NULL;
    Generic_Type_Dynamic* aux_Generic_Type_1_Dynamic = NULL;
    Generic_Type* aux_Generic_Type_2 = NULL;
    Ref_Manager* aux_Generic_Type_2_Refman = NULL;
    Generic_Type_Dynamic* aux_Generic_Type_2_Dynamic = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(arr_Refman);
    x = item;
    x_Refman = item_Refman;
    x_Dynamic = item_Dynamic;
    item = NULL;
    item_Refman = NULL;
    item_Dynamic = NULL;
    aux_Generic_Type_0 = x;
    aux_Generic_Type_0_Refman = x_Refman;
    aux_Generic_Type_0_Dynamic = x_Dynamic;
    x = NULL;
    x_Refman = NULL;
    x_Dynamic = NULL;
    CHECK_REF(6, self, self_Refman)
    if (self->item_Dynamic != NULL) ((Generic_Type_Dynamic*)(self->item_Dynamic))->_del(self->item);
    LUMI_owner_dec_ref(self->item_Refman);
    self->item_Refman = aux_Generic_Type_0_Refman;
    self->item_Dynamic = aux_Generic_Type_0_Dynamic;
    self->item = aux_Generic_Type_0;
    aux_Generic_Type_0 = NULL;
    aux_Generic_Type_0_Refman = NULL;
    aux_Generic_Type_0_Dynamic = NULL;
    CHECK_REF(7, self, self_Refman)
    aux_Ref_Manager = self->arr_Refman;
    self->arr_Refman = arr_Refman;
    LUMI_inc_ref(self->arr_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->arr = arr;
    INIT_NEW(8, t, LUMI_alloc(sizeof(ut_M_Test)));
    CHECK_REF(9, self, self_Refman)
    aux_Generic_Type_1 = self->item;
    aux_Generic_Type_1_Refman = self->item_Refman;
    aux_Generic_Type_1_Dynamic = self->item_Dynamic;
    self->item = NULL;
    self->item_Refman = NULL;
    self->item_Dynamic = NULL;
    CHECK_REF(9, t, t_Refman)
    if (t->item_Dynamic != NULL) ((Generic_Type_Dynamic*)(t->item_Dynamic))->_del(t->item);
    LUMI_owner_dec_ref(t->item_Refman);
    t->item_Refman = aux_Generic_Type_1_Refman;
    t->item_Dynamic = aux_Generic_Type_1_Dynamic;
    t->item = aux_Generic_Type_1;
    aux_Generic_Type_1 = NULL;
    aux_Generic_Type_1_Refman = NULL;
    aux_Generic_Type_1_Dynamic = NULL;
    CHECK_REF(10, t, t_Refman)
    aux_Generic_Type_2 = t->item;
    aux_Generic_Type_2_Refman = t->item_Refman;
    aux_Generic_Type_2_Dynamic = t->item_Dynamic;
    t->item = NULL;
    t->item_Refman = NULL;
    t->item_Dynamic = NULL;
    CHECK_REF(10, self, self_Refman)
    if (self->item_Dynamic != NULL) ((Generic_Type_Dynamic*)(self->item_Dynamic))->_del(self->item);
    LUMI_owner_dec_ref(self->item_Refman);
    self->item_Refman = aux_Generic_Type_2_Refman;
    self->item_Dynamic = aux_Generic_Type_2_Dynamic;
    self->item = aux_Generic_Type_2;
    aux_Generic_Type_2 = NULL;
    aux_Generic_Type_2_Refman = NULL;
    aux_Generic_Type_2_Dynamic = NULL;
LUMI_cleanup:
    if (aux_Generic_Type_2_Dynamic != NULL) aux_Generic_Type_2_Dynamic->_del(aux_Generic_Type_2);
    LUMI_owner_dec_ref(aux_Generic_Type_2_Refman);
    if (aux_Generic_Type_1_Dynamic != NULL) aux_Generic_Type_1_Dynamic->_del(aux_Generic_Type_1);
    LUMI_owner_dec_ref(aux_Generic_Type_1_Refman);
    if (aux_Generic_Type_0_Dynamic != NULL) aux_Generic_Type_0_Dynamic->_del(aux_Generic_Type_0);
    LUMI_owner_dec_ref(aux_Generic_Type_0_Refman);
    ut_M_Test_Del(t);
    LUMI_owner_dec_ref(t_Refman);
    if (x_Dynamic != NULL) x_Dynamic->_del(x);
    LUMI_owner_dec_ref(x_Refman);
    LUMI_dec_ref(arr_Refman);
    if (item_Dynamic != NULL) item_Dynamic->_del(item);
    LUMI_owner_dec_ref(item_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->arr_Refman);
    if (self->item_Dynamic != NULL) self->item_Dynamic->_del(self->item);
    LUMI_owner_dec_ref(self->item_Refman);
}
/// @ t1
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Generic_Type* item;
    Ref_Manager* item_Refman;
    Generic_Type_Dynamic* item_Dynamic;
};
Returncode ut_M_Test_get(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_get(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
    Returncode LUMI_err = OK;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    CHECK_REF(4, self, self_Refman)
    aux_Ref_Manager = *item_Refman;
    *item_Refman = self->item_Refman;
    *item_Dynamic = self->item_Dynamic;
    LUMI_inc_ref(*item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    *item = self->item;
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    if (self->item_Dynamic != NULL) self->item_Dynamic->_del(self->item);
    LUMI_owner_dec_ref(self->item_Refman);
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
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Generic_Type* second, Ref_Manager* second_Refman, Generic_Type_Dynamic* second_Dynamic, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Generic_Type* second, Ref_Manager* second_Refman, Generic_Type_Dynamic* second_Dynamic, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic) {
    Returncode LUMI_err = OK;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(first_Refman);
    LUMI_inc_ref(second_Refman);
    LUMI_inc_ref(third_Refman);
    CHECK_REF(6, self, self_Refman)
    aux_Ref_Manager = self->first_Refman;
    self->first_Refman = first_Refman;
    self->first_Dynamic = first_Dynamic;
    LUMI_inc_ref(self->first_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->first = first;
    CHECK_REF(7, self, self_Refman)
    aux_Ref_Manager = self->second_Refman;
    self->second_Refman = second_Refman;
    self->second_Dynamic = second_Dynamic;
    LUMI_inc_ref(self->second_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->second = second;
    CHECK_REF(8, self, self_Refman)
    aux_Ref_Manager = self->third_Refman;
    self->third_Refman = third_Refman;
    self->third_Dynamic = third_Dynamic;
    LUMI_inc_ref(self->third_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->third = third;
LUMI_cleanup:
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->third_Refman);
    LUMI_dec_ref(self->second_Refman);
    LUMI_dec_ref(self->first_Refman);
}
Returncode ut_M_use(String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
    Returncode LUMI_err = OK;
    ut_M_Test t_Var = {0};
    ut_M_Test* t = NULL;
    Ref_Manager* t_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(first_Refman);
    LUMI_inc_ref(second_Refman);
    LUMI_inc_ref(third_Refman);
    INIT_VAR(10, t)
    CHECK_REF(11, t, t_Refman)
    aux_Ref_Manager = t->first_Refman;
    t->first_Refman = first_Refman;
    t->first_Dynamic = &String_dynamic;
    LUMI_inc_ref(t->first_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->first = first;
    CHECK_REF(12, t, t_Refman)
    aux_Ref_Manager = t->second_Refman;
    t->second_Refman = second_Refman;
    t->second_Dynamic = &Sys_dynamic;
    LUMI_inc_ref(t->second_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->second = second;
    CHECK_REF(13, t, t_Refman)
    aux_Ref_Manager = t->third_Refman;
    t->third_Refman = third_Refman;
    t->third_Dynamic = &File_dynamic;
    LUMI_inc_ref(t->third_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->third = third;
    LUMI_err = ut_M_Test_set(t, t_Refman, first, first_Refman, &String_dynamic, second, second_Refman, &Sys_dynamic, third, third_Refman, &File_dynamic);
    CHECK(14)
LUMI_cleanup:
    LUMI_var_dec_ref(t_Refman);
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
    return LUMI_err;
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
Ref_Manager* aux_Ref_Manager = NULL;
    CHECK_REF(1, ut_M_d, ut_M_d_Refman)
    aux_Ref_Manager = ut_M_d->item_Refman;
    ut_M_d->item_Refman = ut_M_str_Refman;
    ut_M_d->item_Dynamic = &String_dynamic;
    LUMI_inc_ref(ut_M_d->item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ut_M_d->item = ut_M_str;
/// @ t5
Ref_Manager* aux_Ref_Manager = NULL;
    CHECK_REF(1, ut_M_d, ut_M_d_Refman)
    aux_Ref_Manager = ut_M_str_Refman;
    ut_M_str_Refman = ut_M_d->item_Refman;
    LUMI_inc_ref(ut_M_str_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ut_M_str = ut_M_d->item;
/// @ t6
Ref_Manager* aux_Ref_Manager = NULL;
    CHECK_REF(1, ut_M_d, ut_M_d_Refman)
    aux_Ref_Manager = ut_M_d->arr_Refman;
    ut_M_d->arr_Refman = ut_M_sarr_Refman;
    LUMI_inc_ref(ut_M_d->arr_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ut_M_d->arr = ut_M_sarr;
/// @ t7
Ref_Manager* aux_Ref_Manager = NULL;
    CHECK_REF(1, ut_M_d, ut_M_d_Refman)
    CHECK_REF(1, ut_M_d->arr, ut_M_d->arr_Refman)
    if ((4) < 0 || (4) >= (ut_M_d->arr)->length) RAISE(1, slice_index)
    aux_Ref_Manager = ut_M_str_Refman;
    ut_M_str_Refman = ut_M_d->arr_Refman;
    LUMI_inc_ref(ut_M_str_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ut_M_str = ((String*)((ut_M_d->arr)->values)) + 4;
/// @ t8
ut_M_Data ad_Values[5] = {{0}};
    Array ad_Var = {5, NULL};
    Array* ad = NULL;
    Ref_Manager* ad_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    INIT_VAR(1, ad)
    ad_Var.values = ad_Values;
    CHECK_REF(2, ad, ad_Refman)
    if ((2) < 0 || (2) >= (ad)->length) RAISE(2, slice_index)
    CHECK_REF(2, ((ut_M_Data*)((ad)->values)) + 2, ad_Refman)
    aux_Ref_Manager = ut_M_str_Refman;
    ut_M_str_Refman = (((ut_M_Data*)((ad)->values)) + 2)->item_Refman;
    LUMI_inc_ref(ut_M_str_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ut_M_str = (((ut_M_Data*)((ad)->values)) + 2)->item;
/// @ t9
ut_M_Data ad_Values[5] = {{0}};
    Array ad_Var = {5, NULL};
    Array* ad = NULL;
    Ref_Manager* ad_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    INIT_VAR(1, ad)
    ad_Var.values = ad_Values;
    CHECK_REF(2, ad, ad_Refman)
    if ((2) < 0 || (2) >= (ad)->length) RAISE(2, slice_index)
    CHECK_REF(2, ((ut_M_Data*)((ad)->values)) + 2, ad_Refman)
    CHECK_REF(2, (((ut_M_Data*)((ad)->values)) + 2)->arr, (((ut_M_Data*)((ad)->values)) + 2)->arr_Refman)
    if ((3) < 0 || (3) >= ((((ut_M_Data*)((ad)->values)) + 2)->arr)->length) RAISE(2, slice_index)
    aux_Ref_Manager = ut_M_str_Refman;
    ut_M_str_Refman = (((ut_M_Data*)((ad)->values)) + 2)->arr_Refman;
    LUMI_inc_ref(ut_M_str_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ut_M_str = ((String*)(((((ut_M_Data*)((ad)->values)) + 2)->arr)->values)) + 3;
/// @ t10
LUMI_err = ut_M_Data_set(ut_M_d, ut_M_d_Refman, NULL, NULL, NULL, NULL, NULL);
    CHECK(1)
/// @ t11
ut_M_Data dr_Var = {0};
    ut_M_Data* dr = NULL;
    Ref_Manager* dr_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    INIT_VAR(1, dr)
    CHECK_REF(2, dr, dr_Refman)
    CHECK_REF(2, dr->item, dr->item_Refman)
    CHECK_REF(2, ((ut_M_Data*)(dr->item))->item, ((ut_M_Data*)(dr->item))->item_Refman)
    aux_Ref_Manager = ut_M_str_Refman;
    ut_M_str_Refman = ((ut_M_Data*)(((ut_M_Data*)(dr->item))->item))->item_Refman;
    LUMI_inc_ref(ut_M_str_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ut_M_str = ((ut_M_Data*)(((ut_M_Data*)(dr->item))->item))->item;
/// @ t12
LUMI_err = ut_M_Data_set(ut_M_d, ut_M_d_Refman, *so, *so_Refman, &String_dynamic, ut_M_sarr, ut_M_sarr_Refman);
    *so = NULL;
    *so_Refman = NULL;
    CHECK(1)
/// @ t13
String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    LUMI_err = ut_M_Data_get(ut_M_d, ut_M_d_Refman, (void*)&(ut_M_str), &(ut_M_str_Refman), &dynamic_Void);
    CHECK(1)
    LUMI_err = ut_M_Data_get(ut_M_d, ut_M_d_Refman, (void*)&(aux_String_0), &(aux_String_0_Refman), &dynamic_Void);
    CHECK(2)
    LUMI_err = String_clear(aux_String_0, aux_String_0_Refman);
    CHECK(2)
/// @ t14
ut_M_Data dg_Var = {0};
    ut_M_Data* dg = NULL;
    Ref_Manager* dg_Refman = NULL;
    INIT_VAR(1, dg)
/// @ t15
ut_M_Data* dg = NULL;
    Ref_Manager* dg_Refman = NULL;
    dg = ut_M_d;
    dg_Refman = ut_M_d_Refman;
    LUMI_inc_ref(dg_Refman);
/// @ t16
LUMI_err = ut_M_Data_set(ut_M_d, ut_M_d_Refman, *so, *so_Refman, &String_dynamic, ut_M_sarr, ut_M_sarr_Refman);
    *so = NULL;
    *so_Refman = NULL;
    CHECK(1)
/// @ t17
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    ut_M_Test* next;
    Ref_Manager* next_Refman;
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    CHECK_REF(4, self, self_Refman)
    aux_Ref_Manager = self->next_Refman;
    self->next_Refman = self_Refman;
    LUMI_inc_ref(self->next_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->next = self;
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->next_Refman);
}
/// @ t18
ut_M_Data dt_Var = {0};
    ut_M_Data* dt = NULL;
    Ref_Manager* dt_Refman = NULL;
    ut_M_Tc* otc = NULL;
    Ref_Manager* otc_Refman = NULL;
    ut_M_Tc_Dynamic* otc_Dynamic = NULL;
    ut_M_Tb* tb2 = NULL;
    Ref_Manager* tb2_Refman = NULL;
    ut_M_Tb_Dynamic* tb2_Dynamic = NULL;
    ut_M_Tb* aux_Tb_0 = NULL;
    Ref_Manager* aux_Tb_0_Refman = NULL;
    ut_M_Tb_Dynamic* aux_Tb_0_Dynamic = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    INIT_VAR(1, dt)
    CHECK_REF(2, dt, dt_Refman)
    aux_Ref_Manager = dt->item_Refman;
    dt->item_Refman = ut_M_tc_Refman;
    dt->item_Dynamic = (Generic_Type_Dynamic*)&(ut_M_tc_Dynamic->_base);
    LUMI_inc_ref(dt->item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    dt->item = &(ut_M_tc->_base);
    CHECK_REF(3, dt, dt_Refman)
    aux_Ref_Manager = ut_M_ta_Refman;
    ut_M_ta_Refman = dt->item_Refman;
    ut_M_ta_Dynamic = &(((ut_M_Tb_Dynamic*)(dt->item_Dynamic))->_base);
    LUMI_inc_ref(ut_M_ta_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ut_M_ta = &(((ut_M_Tb*)(dt->item))->_base);
    LUMI_err = ut_M_Data_set(dt, dt_Refman, &(otc->_base), otc_Refman, (void*)&(otc_Dynamic->_base), NULL, NULL);
    otc = NULL;
    otc_Refman = NULL;
    otc_Dynamic = NULL;
    CHECK(5)
    if (ut_M_ta != NULL) RAISE(6, empty_base_output)
    LUMI_err = ut_M_Data_get(dt, dt_Refman, (void*)&(ut_M_ta), &(ut_M_ta_Refman), (void*)&(ut_M_ta_Dynamic));
    CHECK(6)
    LUMI_err = ut_M_Data_get(dt, dt_Refman, (void*)&(aux_Tb_0), &(aux_Tb_0_Refman), (void*)&(aux_Tb_0_Dynamic));
    CHECK(7)
    CHECK_REF(7, aux_Tb_0, aux_Tb_0_Refman)
    ut_M_i = aux_Tb_0->_base.numa;
    CHECK_REF(8, dt, dt_Refman)
    CHECK_REF(8, dt, dt_Refman)
    LUMI_err = ut_M_fun7(dt->item, dt->item_Refman, ((ut_M_Tb_Dynamic*)(dt->item_Dynamic)), &(dt->item), &(dt->item_Refman), &(((ut_M_Tb_Dynamic*)(dt->item_Dynamic))));
    CHECK(8)
    CHECK_REF(9, dt, dt_Refman)
    tb2 = dt->item;
    tb2_Refman = dt->item_Refman;
    LUMI_inc_ref(tb2_Refman);
    tb2_Dynamic = ((ut_M_Tb_Dynamic*)(dt->item_Dynamic));
    CHECK_REF(10, dt, dt_Refman)
    aux_Ref_Manager = tb2_Refman;
    tb2_Refman = dt->item_Refman;
    tb2_Dynamic = ((ut_M_Tb_Dynamic*)(dt->item_Dynamic));
    LUMI_inc_ref(tb2_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
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
Returncode ut_M_Base_get(ut_M_Base* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_mock(ut_M_Test* test, Ref_Manager* test_Refman, String* text, Ref_Manager* text_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Base_get(ut_M_Base* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman) {
    Returncode LUMI_err = OK;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(text_Refman);
    CHECK_REF(6, self, self_Refman)
    aux_Ref_Manager = self->_base.item_Refman;
    self->_base.item_Refman = text_Refman;
    self->_base.item_Dynamic = &String_dynamic;
    LUMI_inc_ref(self->_base.item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base.item = text;
    LUMI_err = ut_M_Base_get(&(self->_base), self_Refman, (void*)&(text), &(text_Refman), &dynamic_Void);
    CHECK(7)
LUMI_cleanup:
    LUMI_dec_ref(text_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_mock(ut_M_Test* test, Ref_Manager* test_Refman, String* text, Ref_Manager* text_Refman) {
    Returncode LUMI_err = OK;
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(test_Refman);
    LUMI_inc_ref(text_Refman);
    CHECK_REF(9, test, test_Refman)
    aux_Ref_Manager = test->_base.item_Refman;
    test->_base.item_Refman = text_Refman;
    test->_base.item_Dynamic = &String_dynamic;
    LUMI_inc_ref(test->_base.item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    test->_base.item = text;
    LUMI_err = ut_M_Test_set(test, test_Refman, text, text_Refman);
    CHECK(10)
    CHECK_REF(11, test, test_Refman)
    aux_Ref_Manager = text_Refman;
    text_Refman = test->_base.item_Refman;
    LUMI_inc_ref(text_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    text = test->_base.item;
    LUMI_err = ut_M_Base_get(&(test->_base), test_Refman, (void*)&(text), &(text_Refman), &dynamic_Void);
    CHECK(12)
    LUMI_err = ut_M_Base_get(&(test->_base), test_Refman, (void*)&(aux_String_0), &(aux_String_0_Refman), &dynamic_Void);
    CHECK(13)
    LUMI_err = String_clear(aux_String_0, aux_String_0_Refman);
    CHECK(13)
LUMI_cleanup:
    LUMI_dec_ref(aux_String_0_Refman);
    LUMI_dec_ref(text_Refman);
    LUMI_dec_ref(test_Refman);
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
    Returncode (*set)(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
    Returncode (*get)(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
};
struct ut_M_Test {
    ut_M_Base _base;
};
struct ut_M_Test_Dynamic {
    ut_M_Base_Dynamic _base;
};
Returncode ut_M_Base_set(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
Returncode ut_M_Base_get(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic);
Returncode ut_M_Test_get(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_mock(ut_M_Test* test, Ref_Manager* test_Refman, ut_M_Test_Dynamic* test_Dynamic, String* text, Ref_Manager* text_Refman);
ut_M_Base_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del, ut_M_Base_set, ut_M_Base_get};
ut_M_Test_Dynamic ut_M_Test_dynamic = {{(Dynamic_Del)ut_M_Test_Del, (Func)ut_M_Test_set, (Func)ut_M_Test_get}};
Returncode ut_M_Base_set(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(item_Refman);
LUMI_cleanup:
    LUMI_dec_ref(item_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_Base_get(ut_M_Base* self, Ref_Manager* self_Refman, ut_M_Base_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Generic_Type* item, Ref_Manager* item_Refman, Generic_Type_Dynamic* item_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(item_Refman);
LUMI_cleanup:
    LUMI_dec_ref(item_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_Test_get(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_mock(ut_M_Test* test, Ref_Manager* test_Refman, ut_M_Test_Dynamic* test_Dynamic, String* text, Ref_Manager* text_Refman) {
    Returncode LUMI_err = OK;
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    LUMI_inc_ref(test_Refman);
    LUMI_inc_ref(text_Refman);
    if (test_Dynamic == NULL) RAISE(9, empty_object)
    LUMI_err = test_Dynamic->_base.set(&(test->_base), test_Refman, &(test_Dynamic->_base), text, text_Refman, &String_dynamic);
    CHECK(9)
    if (test_Dynamic == NULL) RAISE(10, empty_object)
    LUMI_err = test_Dynamic->_base.get(&(test->_base), test_Refman, &(test_Dynamic->_base), (void*)&(text), &(text_Refman), &dynamic_Void);
    CHECK(10)
    if (test_Dynamic == NULL) RAISE(11, empty_object)
    LUMI_err = test_Dynamic->_base.get(&(test->_base), test_Refman, &(test_Dynamic->_base), (void*)&(aux_String_0), &(aux_String_0_Refman), &dynamic_Void);
    CHECK(11)
    LUMI_err = String_clear(aux_String_0, aux_String_0_Refman);
    CHECK(11)
LUMI_cleanup:
    LUMI_dec_ref(aux_String_0_Refman);
    LUMI_dec_ref(text_Refman);
    LUMI_dec_ref(test_Refman);
    return LUMI_err;
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
/// @ teg8
cannot slice generic array
/// @ teg9
cannot create generic array
/// @ teg10
cannot create generic array
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
cannot assign type "Data" with no parameter into same type with parameter "String"
/// @ tec6
cannot assign "String" into "Test"
/// @ tec7
array as parameter type is unsupported
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
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(String* s, Ref_Manager* s_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman) {
    Returncode LUMI_err = OK;
    ut_M_Test* aux_Test_0 = NULL;
    Ref_Manager* aux_Test_0_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(s_Refman);
    CHECK_REF(5, self, self_Refman)
    aux_Ref_Manager = self->_base.item_Refman;
    self->_base.item_Refman = s_Refman;
    self->_base.item_Dynamic = &String_dynamic;
    LUMI_inc_ref(self->_base.item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base.item = s;
    INIT_NEW(6, aux_Test_0, LUMI_alloc(sizeof(ut_M_Test)));
    LUMI_err = ut_M_Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman);
    CHECK(6)
LUMI_cleanup:
    ut_M_Test_Del(aux_Test_0);
    LUMI_owner_dec_ref(aux_Test_0_Refman);
    LUMI_dec_ref(s_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_use(String* s, Ref_Manager* s_Refman) {
    Returncode LUMI_err = OK;
    ut_M_Test t_Var = {{0}};
    ut_M_Test* t = NULL;
    Ref_Manager* t_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(s_Refman);
    INIT_VAR(8, t)
    CHECK_REF(9, t, t_Refman)
    aux_Ref_Manager = t->_base.item_Refman;
    t->_base.item_Refman = s_Refman;
    t->_base.item_Dynamic = &String_dynamic;
    LUMI_inc_ref(t->_base.item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->_base.item = s;
LUMI_cleanup:
    LUMI_var_dec_ref(t_Refman);
    LUMI_dec_ref(s_Refman);
    return LUMI_err;
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
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, String* s, Ref_Manager* s_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(String* s, Ref_Manager* s_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, String* s, Ref_Manager* s_Refman) {
    Returncode LUMI_err = OK;
    ut_M_Test* aux_Test_0 = NULL;
    Ref_Manager* aux_Test_0_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(i_Refman);
    LUMI_inc_ref(s_Refman);
    CHECK_REF(5, self, self_Refman)
    aux_Ref_Manager = self->_base.item_Refman;
    self->_base.item_Refman = i_Refman;
    self->_base.item_Dynamic = i_Dynamic;
    LUMI_inc_ref(self->_base.item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base.item = i;
    INIT_NEW(6, aux_Test_0, LUMI_alloc(sizeof(ut_M_Test)));
    LUMI_err = ut_M_Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman, &String_dynamic, s, s_Refman);
    CHECK(6)
LUMI_cleanup:
    ut_M_Test_Del(aux_Test_0);
    LUMI_owner_dec_ref(aux_Test_0_Refman);
    LUMI_dec_ref(s_Refman);
    LUMI_dec_ref(i_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_use(String* s, Ref_Manager* s_Refman) {
    Returncode LUMI_err = OK;
    ut_M_Test t_Var = {{0}};
    ut_M_Test* t = NULL;
    Ref_Manager* t_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(s_Refman);
    INIT_VAR(8, t)
    CHECK_REF(9, t, t_Refman)
    aux_Ref_Manager = t->_base.item_Refman;
    t->_base.item_Refman = s_Refman;
    t->_base.item_Dynamic = &String_dynamic;
    LUMI_inc_ref(t->_base.item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->_base.item = s;
LUMI_cleanup:
    LUMI_var_dec_ref(t_Refman);
    LUMI_dec_ref(s_Refman);
    return LUMI_err;
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
Returncode ut_M_Base_set(ut_M_Base* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic);
void ut_M_Base_Del(ut_M_Base* self);
Returncode ut_M_Mid_set(ut_M_Mid* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self);
Returncode ut_M_Top_set(ut_M_Top* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman);
void ut_M_Top_Del(ut_M_Top* self);
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(String* s, Ref_Manager* s_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Top_dynamic = {(Dynamic_Del)ut_M_Top_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Base_set(ut_M_Base* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(i_Refman);
LUMI_cleanup:
    LUMI_dec_ref(i_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Mid_set(ut_M_Mid* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(i_Refman);
LUMI_cleanup:
    LUMI_dec_ref(i_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Mid_Del(ut_M_Mid* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_Top_set(ut_M_Top* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman) {
    Returncode LUMI_err = OK;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(s_Refman);
    LUMI_err = ut_M_Mid_set(&(self->_base), self_Refman, s, s_Refman, &String_dynamic);
    CHECK(8)
    CHECK_REF(9, self, self_Refman)
    aux_Ref_Manager = self->_base._base.item_Refman;
    self->_base._base.item_Refman = s_Refman;
    self->_base._base.item_Dynamic = &String_dynamic;
    LUMI_inc_ref(self->_base._base.item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base._base.item = s;
LUMI_cleanup:
    LUMI_dec_ref(s_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Top_Del(ut_M_Top* self) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base));
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* s, Ref_Manager* s_Refman) {
    Returncode LUMI_err = OK;
    ut_M_Top* aux_Top_0 = NULL;
    Ref_Manager* aux_Top_0_Refman = NULL;
    ut_M_Test* aux_Test_0 = NULL;
    Ref_Manager* aux_Test_0_Refman = NULL;
    ut_M_Top* aux_Top_1 = NULL;
    Ref_Manager* aux_Top_1_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(s_Refman);
    LUMI_err = ut_M_Top_set(&(self->_base), self_Refman, s, s_Refman);
    CHECK(12)
    CHECK_REF(13, self, self_Refman)
    aux_Ref_Manager = self->_base._base._base.item_Refman;
    self->_base._base._base.item_Refman = s_Refman;
    self->_base._base._base.item_Dynamic = &String_dynamic;
    LUMI_inc_ref(self->_base._base._base.item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base._base._base.item = s;
    INIT_NEW(14, aux_Top_0, LUMI_alloc(sizeof(ut_M_Top)));
    LUMI_err = ut_M_Top_set(aux_Top_0, aux_Top_0_Refman, s, s_Refman);
    CHECK(14)
    INIT_NEW(15, aux_Test_0, LUMI_alloc(sizeof(ut_M_Test)));
    LUMI_err = ut_M_Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman);
    CHECK(15)
    INIT_NEW(16, aux_Top_1, LUMI_alloc(sizeof(ut_M_Top)));
    LUMI_err = ut_M_Mid_set(&(aux_Top_1->_base), aux_Top_1_Refman, s, s_Refman, &String_dynamic);
    CHECK(16)
LUMI_cleanup:
    ut_M_Top_Del(aux_Top_1);
    LUMI_owner_dec_ref(aux_Top_1_Refman);
    ut_M_Test_Del(aux_Test_0);
    LUMI_owner_dec_ref(aux_Test_0_Refman);
    ut_M_Top_Del(aux_Top_0);
    LUMI_owner_dec_ref(aux_Top_0_Refman);
    LUMI_dec_ref(s_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Top_Del(&(self->_base));
}
Returncode ut_M_use(String* s, Ref_Manager* s_Refman) {
    Returncode LUMI_err = OK;
    ut_M_Test t_Var = {{{{0}}}};
    ut_M_Test* t = NULL;
    Ref_Manager* t_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(s_Refman);
    INIT_VAR(18, t)
    CHECK_REF(19, t, t_Refman)
    aux_Ref_Manager = t->_base._base._base.item_Refman;
    t->_base._base._base.item_Refman = s_Refman;
    t->_base._base._base.item_Dynamic = &String_dynamic;
    LUMI_inc_ref(t->_base._base._base.item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->_base._base._base.item = s;
LUMI_cleanup:
    LUMI_var_dec_ref(t_Refman);
    LUMI_dec_ref(s_Refman);
    return LUMI_err;
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
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, String* s, Ref_Manager* s_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(String* s, Ref_Manager* s_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* i, Ref_Manager* i_Refman, Generic_Type_Dynamic* i_Dynamic, String* s, Ref_Manager* s_Refman) {
    Returncode LUMI_err = OK;
    ut_M_Test* aux_Test_0 = NULL;
    Ref_Manager* aux_Test_0_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(i_Refman);
    LUMI_inc_ref(s_Refman);
    CHECK_REF(5, self, self_Refman)
    aux_Ref_Manager = self->_base.item_Refman;
    self->_base.item_Refman = i_Refman;
    self->_base.item_Dynamic = i_Dynamic;
    LUMI_inc_ref(self->_base.item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base.item = i;
    INIT_NEW(6, aux_Test_0, LUMI_alloc(sizeof(ut_M_Test)));
    LUMI_err = ut_M_Test_set(aux_Test_0, aux_Test_0_Refman, s, s_Refman, &String_dynamic, s, s_Refman);
    CHECK(6)
LUMI_cleanup:
    ut_M_Test_Del(aux_Test_0);
    LUMI_owner_dec_ref(aux_Test_0_Refman);
    LUMI_dec_ref(s_Refman);
    LUMI_dec_ref(i_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
}
Returncode ut_M_use(String* s, Ref_Manager* s_Refman) {
    Returncode LUMI_err = OK;
    ut_M_Test t_Var = {{0}};
    ut_M_Test* t = NULL;
    Ref_Manager* t_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(s_Refman);
    INIT_VAR(8, t)
    CHECK_REF(9, t, t_Refman)
    aux_Ref_Manager = t->_base.item_Refman;
    t->_base.item_Refman = s_Refman;
    t->_base.item_Dynamic = &String_dynamic;
    LUMI_inc_ref(t->_base.item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->_base.item = s;
LUMI_cleanup:
    LUMI_var_dec_ref(t_Refman);
    LUMI_dec_ref(s_Refman);
    return LUMI_err;
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
Returncode ut_M_Mid_set(ut_M_Mid* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic);
void ut_M_Mid_Del(ut_M_Mid* self);
Returncode ut_M_Top_set(ut_M_Top* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
void ut_M_Top_Del(ut_M_Top* self);
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman);
Generic_Type_Dynamic ut_M_Base_dynamic = {(Dynamic_Del)ut_M_Base_Del};
Generic_Type_Dynamic ut_M_Mid_dynamic = {(Dynamic_Del)ut_M_Mid_Del};
Generic_Type_Dynamic ut_M_Top_dynamic = {(Dynamic_Del)ut_M_Top_Del};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
void ut_M_Base_Del(ut_M_Base* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->second_Refman);
    LUMI_dec_ref(self->first_Refman);
}
Returncode ut_M_Mid_set(ut_M_Mid* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, Generic_Type* third, Ref_Manager* third_Refman, Generic_Type_Dynamic* third_Dynamic) {
    Returncode LUMI_err = OK;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(first_Refman);
    LUMI_inc_ref(second_Refman);
    LUMI_inc_ref(third_Refman);
    CHECK_REF(7, self, self_Refman)
    aux_Ref_Manager = self->_base.first_Refman;
    self->_base.first_Refman = first_Refman;
    self->_base.first_Dynamic = first_Dynamic;
    LUMI_inc_ref(self->_base.first_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base.first = first;
    CHECK_REF(8, self, self_Refman)
    aux_Ref_Manager = self->_base.second_Refman;
    self->_base.second_Refman = second_Refman;
    self->_base.second_Dynamic = &Sys_dynamic;
    LUMI_inc_ref(self->_base.second_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base.second = second;
    CHECK_REF(9, self, self_Refman)
    aux_Ref_Manager = self->third_Refman;
    self->third_Refman = third_Refman;
    self->third_Dynamic = third_Dynamic;
    LUMI_inc_ref(self->third_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->third = third;
LUMI_cleanup:
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Mid_Del(ut_M_Mid* self) {
    if (self == NULL) return;
    ut_M_Base_Del(&(self->_base));
    LUMI_dec_ref(self->third_Refman);
}
Returncode ut_M_Top_set(ut_M_Top* self, Ref_Manager* self_Refman, Generic_Type* first, Ref_Manager* first_Refman, Generic_Type_Dynamic* first_Dynamic, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
    Returncode LUMI_err = OK;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(first_Refman);
    LUMI_inc_ref(second_Refman);
    LUMI_inc_ref(third_Refman);
    CHECK_REF(12, self, self_Refman)
    aux_Ref_Manager = self->_base._base.first_Refman;
    self->_base._base.first_Refman = first_Refman;
    self->_base._base.first_Dynamic = first_Dynamic;
    LUMI_inc_ref(self->_base._base.first_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base._base.first = first;
    CHECK_REF(13, self, self_Refman)
    aux_Ref_Manager = self->_base._base.second_Refman;
    self->_base._base.second_Refman = second_Refman;
    self->_base._base.second_Dynamic = &Sys_dynamic;
    LUMI_inc_ref(self->_base._base.second_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base._base.second = second;
    CHECK_REF(14, self, self_Refman)
    aux_Ref_Manager = self->_base.third_Refman;
    self->_base.third_Refman = third_Refman;
    self->_base.third_Dynamic = &File_dynamic;
    LUMI_inc_ref(self->_base.third_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base.third = third;
LUMI_cleanup:
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Top_Del(ut_M_Top* self) {
    if (self == NULL) return;
    ut_M_Mid_Del(&(self->_base));
}
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
    Returncode LUMI_err = OK;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(first_Refman);
    LUMI_inc_ref(second_Refman);
    LUMI_inc_ref(third_Refman);
    CHECK_REF(17, self, self_Refman)
    aux_Ref_Manager = self->_base._base._base.first_Refman;
    self->_base._base._base.first_Refman = first_Refman;
    self->_base._base._base.first_Dynamic = &String_dynamic;
    LUMI_inc_ref(self->_base._base._base.first_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base._base._base.first = first;
    CHECK_REF(18, self, self_Refman)
    aux_Ref_Manager = self->_base._base._base.second_Refman;
    self->_base._base._base.second_Refman = second_Refman;
    self->_base._base._base.second_Dynamic = &Sys_dynamic;
    LUMI_inc_ref(self->_base._base._base.second_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base._base._base.second = second;
    CHECK_REF(19, self, self_Refman)
    aux_Ref_Manager = self->_base._base.third_Refman;
    self->_base._base.third_Refman = third_Refman;
    self->_base._base.third_Dynamic = &File_dynamic;
    LUMI_inc_ref(self->_base._base.third_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base._base.third = third;
LUMI_cleanup:
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Top_Del(&(self->_base));
}
Returncode ut_M_use(String* first, Ref_Manager* first_Refman, Sys* second, Ref_Manager* second_Refman, File* third, Ref_Manager* third_Refman) {
    Returncode LUMI_err = OK;
    ut_M_Test t_Var = {{{{0}}}};
    ut_M_Test* t = NULL;
    Ref_Manager* t_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(first_Refman);
    LUMI_inc_ref(second_Refman);
    LUMI_inc_ref(third_Refman);
    INIT_VAR(21, t)
    CHECK_REF(22, t, t_Refman)
    aux_Ref_Manager = t->_base._base._base.first_Refman;
    t->_base._base._base.first_Refman = first_Refman;
    t->_base._base._base.first_Dynamic = &String_dynamic;
    LUMI_inc_ref(t->_base._base._base.first_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->_base._base._base.first = first;
    CHECK_REF(23, t, t_Refman)
    aux_Ref_Manager = t->_base._base._base.second_Refman;
    t->_base._base._base.second_Refman = second_Refman;
    t->_base._base._base.second_Dynamic = &Sys_dynamic;
    LUMI_inc_ref(t->_base._base._base.second_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->_base._base._base.second = second;
    CHECK_REF(24, t, t_Refman)
    aux_Ref_Manager = t->_base._base.third_Refman;
    t->_base._base.third_Refman = third_Refman;
    t->_base._base.third_Dynamic = &File_dynamic;
    LUMI_inc_ref(t->_base._base.third_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->_base._base.third = third;
LUMI_cleanup:
    LUMI_var_dec_ref(t_Refman);
    LUMI_dec_ref(third_Refman);
    LUMI_dec_ref(second_Refman);
    LUMI_dec_ref(first_Refman);
    return LUMI_err;
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
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* g, Ref_Manager* g_Refman, Generic_Type_Dynamic* g_Dynamic, ut_M_Second* sg, Ref_Manager* sg_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_use(String* s, Ref_Manager* s_Refman, ut_M_Second* ss, Ref_Manager* ss_Refman);
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
Returncode ut_M_Test_set(ut_M_Test* self, Ref_Manager* self_Refman, Generic_Type* g, Ref_Manager* g_Refman, Generic_Type_Dynamic* g_Dynamic, ut_M_Second* sg, Ref_Manager* sg_Refman) {
    Returncode LUMI_err = OK;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(g_Refman);
    LUMI_inc_ref(sg_Refman);
    CHECK_REF(7, self, self_Refman)
    aux_Ref_Manager = self->_base.item_Refman;
    self->_base.item_Refman = sg_Refman;
    self->_base.item_Dynamic = &ut_M_Second_dynamic;
    LUMI_inc_ref(self->_base.item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->_base.item = sg;
    CHECK_REF(8, self, self_Refman)
    CHECK_REF(8, self->_base.item, self->_base.item_Refman)
    aux_Ref_Manager = ((ut_M_Second*)(self->_base.item))->item_Refman;
    ((ut_M_Second*)(self->_base.item))->item_Refman = g_Refman;
    ((ut_M_Second*)(self->_base.item))->item_Dynamic = g_Dynamic;
    LUMI_inc_ref(((ut_M_Second*)(self->_base.item))->item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ((ut_M_Second*)(self->_base.item))->item = g;
LUMI_cleanup:
    LUMI_dec_ref(sg_Refman);
    LUMI_dec_ref(g_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_First_Del(&(self->_base));
}
Returncode ut_M_use(String* s, Ref_Manager* s_Refman, ut_M_Second* ss, Ref_Manager* ss_Refman) {
    Returncode LUMI_err = OK;
    ut_M_Test t_Var = {{0}};
    ut_M_Test* t = NULL;
    Ref_Manager* t_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(s_Refman);
    LUMI_inc_ref(ss_Refman);
    INIT_VAR(10, t)
    CHECK_REF(11, t, t_Refman)
    aux_Ref_Manager = t->_base.item_Refman;
    t->_base.item_Refman = ss_Refman;
    t->_base.item_Dynamic = &ut_M_Second_dynamic;
    LUMI_inc_ref(t->_base.item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    t->_base.item = ss;
    CHECK_REF(12, t, t_Refman)
    CHECK_REF(12, t->_base.item, t->_base.item_Refman)
    aux_Ref_Manager = ((ut_M_Second*)(t->_base.item))->item_Refman;
    ((ut_M_Second*)(t->_base.item))->item_Refman = s_Refman;
    ((ut_M_Second*)(t->_base.item))->item_Dynamic = &String_dynamic;
    LUMI_inc_ref(((ut_M_Second*)(t->_base.item))->item_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    ((ut_M_Second*)(t->_base.item))->item = s;
LUMI_cleanup:
    LUMI_var_dec_ref(t_Refman);
    LUMI_dec_ref(ss_Refman);
    LUMI_dec_ref(s_Refman);
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
Returncode ut_M_test(void);
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
Returncode ut_M_test(void) {
    Returncode LUMI_err = OK;
    ut_M_BaseGen* bb = NULL;
    Ref_Manager* bb_Refman = NULL;
    ut_M_BaseGen* bt = NULL;
    Ref_Manager* bt_Refman = NULL;
    ut_M_TestGen* tb = NULL;
    Ref_Manager* tb_Refman = NULL;
    ut_M_TestGen* tt = NULL;
    Ref_Manager* tt_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    aux_Ref_Manager = bb_Refman;
    bb_Refman = tb_Refman;
    LUMI_inc_ref(bb_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    bb = &(tb->_base);
    aux_Ref_Manager = bt_Refman;
    bt_Refman = tt_Refman;
    LUMI_inc_ref(bt_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    bt = &(tt->_base);
    aux_Ref_Manager = bb_Refman;
    bb_Refman = bt_Refman;
    LUMI_inc_ref(bb_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    bb = bt;
    aux_Ref_Manager = tb_Refman;
    tb_Refman = tt_Refman;
    LUMI_inc_ref(tb_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    tb = tt;
    aux_Ref_Manager = bb_Refman;
    bb_Refman = tt_Refman;
    LUMI_inc_ref(bb_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    bb = &(tt->_base);
LUMI_cleanup:
    LUMI_dec_ref(tt_Refman);
    LUMI_dec_ref(tb_Refman);
    LUMI_dec_ref(bt_Refman);
    LUMI_dec_ref(bb_Refman);
    return LUMI_err;
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
        ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
        CHECK_REF(2, ut_M_t, ut_M_t_Refman)
        ut_M_t->num = 1;
        LUMI_err = ut_M_fun0();
        CHECK(3)
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    } while (false);
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        CHECK_REF(5, ut_M_t, ut_M_t_Refman)
        ut_M_i = ut_M_t->num;
        LUMI_err = ut_M_fun4(2);
        CHECK(6)
    }
/// @ t1
do {
        ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
        CHECK_REF(2, ut_M_t, ut_M_t_Refman)
        ut_M_t->num = 1;
        LUMI_err = ut_M_fun0();
        CHECK(3)
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    } while (false);
    --LUMI_trace_ignore_count;
    LUMI_err = OK;
/// @ t2
do {
        ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
        CHECK_REF(2, ut_M_t, ut_M_t_Refman)
        ut_M_t->num = 1;
        do {
            ++LUMI_trace_ignore_count;
            LUMI_err = ut_M_fun0();
            CHECK(4)
        } while (false);
        --LUMI_trace_ignore_count;
        if (LUMI_err != OK) {
            LUMI_err = OK;
            LUMI_err = ut_M_fun4(2);
            CHECK(6)
        }
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    } while (false);
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
        LUMI_err = OK;
        do {
            ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
            CHECK_REF(9, ut_M_arr, ut_M_arr_Refman)
            if ((3) < 0 || (3) >= (ut_M_arr)->length) RAISE(9, slice_index)
            ut_M_i = ((Int*)((ut_M_arr)->values))[3];
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
        } while (false);
        --LUMI_trace_ignore_count;
        if (LUMI_err != OK) {
            LUMI_err = OK;
            CHECK_REF(11, ut_M_t, ut_M_t_Refman)
            ut_M_i = ut_M_t->num;
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
/// @ te6
inside "try" block cannot use "while"
/// @ te7
inside "try" block cannot use "break"
/// @ te8
inside "try" block cannot use "continue"
/// @ te9
inside "try" block cannot use "return"
/// @@ test-for-each
/// @ t0
typedef struct ut_M_TestIterator ut_M_TestIterator;
struct ut_M_TestIterator {
    Int counter;
};
Returncode ut_M_TestIterator_new(ut_M_TestIterator* self, Ref_Manager* self_Refman, Int count);
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, Bool* has_data);
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, Int* num);
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
Returncode ut_M_f_mock(Int* i);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
Returncode ut_M_TestIterator_new(ut_M_TestIterator* self, Ref_Manager* self_Refman, Int count) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, Bool* has_data) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, Int* num) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
    if (self == NULL) return;
}
Returncode ut_M_f_mock(Int* i) {
    Returncode LUMI_err = OK;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    Ref_Manager* aux_TestIterator_0_Refman = NULL;
    Int n = 0;
    ut_M_TestIterator* aux_TestIterator_1 = NULL;
    Ref_Manager* aux_TestIterator_1_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    INIT_NEW(8, aux_TestIterator_0, LUMI_alloc(sizeof(ut_M_TestIterator)));
    LUMI_err = ut_M_TestIterator_new(aux_TestIterator_0, aux_TestIterator_0_Refman, 6);
    CHECK(8)
    aux_Ref_Manager = aux_TestIterator_1_Refman;
    aux_TestIterator_1_Refman = aux_TestIterator_0_Refman;
    LUMI_inc_ref(aux_TestIterator_1_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_TestIterator_1 = aux_TestIterator_0;
    while (true) {
        Bool n_Has = false;
        LUMI_err = ut_M_TestIterator_has(aux_TestIterator_1, aux_TestIterator_1_Refman, &(n_Has));
        CHECK(8)
        if (!n_Has) break;
        LUMI_err = ut_M_TestIterator_get(aux_TestIterator_1, aux_TestIterator_1_Refman, &(n));
        CHECK(8)
        *i = n;
        LUMI_err = ut_M_TestIterator_next(aux_TestIterator_1, aux_TestIterator_1_Refman);
        CHECK(8)
    }
    aux_Ref_Manager = aux_TestIterator_1_Refman;
    aux_TestIterator_1_Refman = NULL;
    LUMI_inc_ref(aux_TestIterator_1_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_TestIterator_1 = NULL;
LUMI_cleanup:
    LUMI_dec_ref(aux_TestIterator_1_Refman);
    ut_M_TestIterator_Del(aux_TestIterator_0);
    LUMI_owner_dec_ref(aux_TestIterator_0_Refman);
    return LUMI_err;
}
/// @ t1
typedef struct ut_M_TestIterator ut_M_TestIterator;
struct ut_M_TestIterator {
    String* value;
    Ref_Manager* value_Refman;
};
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, Bool* has_data);
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, String** text, Ref_Manager** text_Refman);
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
Returncode ut_M_f_mock(ut_M_TestIterator* iter, Ref_Manager* iter_Refman, String** s, Ref_Manager** s_Refman);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, Bool* has_data) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, String** text, Ref_Manager** text_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->value_Refman);
}
Returncode ut_M_f_mock(ut_M_TestIterator* iter, Ref_Manager* iter_Refman, String** s, Ref_Manager** s_Refman) {
    Returncode LUMI_err = OK;
    String* t = NULL;
    Ref_Manager* t_Refman = NULL;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    Ref_Manager* aux_TestIterator_0_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(iter_Refman);
    aux_Ref_Manager = aux_TestIterator_0_Refman;
    aux_TestIterator_0_Refman = iter_Refman;
    LUMI_inc_ref(aux_TestIterator_0_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_TestIterator_0 = iter;
    while (true) {
        Bool t_Has = false;
        LUMI_err = ut_M_TestIterator_has(aux_TestIterator_0, aux_TestIterator_0_Refman, &(t_Has));
        CHECK(7)
        if (!t_Has) break;
        LUMI_err = ut_M_TestIterator_get(aux_TestIterator_0, aux_TestIterator_0_Refman, &(t), &(t_Refman));
        CHECK(7)
        aux_Ref_Manager = *s_Refman;
        *s_Refman = t_Refman;
        LUMI_inc_ref(*s_Refman);
        LUMI_dec_ref(aux_Ref_Manager);
        aux_Ref_Manager = NULL;
        *s = t;
        LUMI_err = ut_M_TestIterator_next(aux_TestIterator_0, aux_TestIterator_0_Refman);
        CHECK(7)
    }
    aux_Ref_Manager = aux_TestIterator_0_Refman;
    aux_TestIterator_0_Refman = NULL;
    LUMI_inc_ref(aux_TestIterator_0_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_TestIterator_0 = NULL;
LUMI_cleanup:
    LUMI_dec_ref(aux_TestIterator_0_Refman);
    LUMI_dec_ref(t_Refman);
    LUMI_dec_ref(iter_Refman);
    return LUMI_err;
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
    Returncode (*fun)(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic);
};
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, Bool* has_data);
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
Returncode ut_M_Test_fun(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_f_mock(ut_M_TestIterator* siter, Ref_Manager* siter_Refman, ut_M_TestIterator* titer, Ref_Manager* titer_Refman, String** os, Ref_Manager** os_Refman, ut_M_Test** ot, Ref_Manager** ot_Refman, ut_M_Test_Dynamic** ot_Dynamic);
Generic_Type_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del};
ut_M_Test_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del, ut_M_Test_fun};
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, Bool* has_data) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_Test_fun(ut_M_Test* self, Ref_Manager* self_Refman, ut_M_Test_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
Returncode ut_M_f_mock(ut_M_TestIterator* siter, Ref_Manager* siter_Refman, ut_M_TestIterator* titer, Ref_Manager* titer_Refman, String** os, Ref_Manager** os_Refman, ut_M_Test** ot, Ref_Manager** ot_Refman, ut_M_Test_Dynamic** ot_Dynamic) {
    Returncode LUMI_err = OK;
    String* s = NULL;
    Ref_Manager* s_Refman = NULL;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    Ref_Manager* aux_TestIterator_0_Refman = NULL;
    ut_M_Test* t = NULL;
    Ref_Manager* t_Refman = NULL;
    ut_M_Test_Dynamic* t_Dynamic = NULL;
    ut_M_TestIterator* aux_TestIterator_1 = NULL;
    Ref_Manager* aux_TestIterator_1_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(siter_Refman);
    LUMI_inc_ref(titer_Refman);
    aux_Ref_Manager = aux_TestIterator_0_Refman;
    aux_TestIterator_0_Refman = siter_Refman;
    LUMI_inc_ref(aux_TestIterator_0_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_TestIterator_0 = siter;
    while (true) {
        Bool s_Has = false;
        LUMI_err = ut_M_TestIterator_has(aux_TestIterator_0, aux_TestIterator_0_Refman, &(s_Has));
        CHECK(11)
        if (!s_Has) break;
        LUMI_err = ut_M_TestIterator_get(aux_TestIterator_0, aux_TestIterator_0_Refman, (void*)&(s), &(s_Refman), &dynamic_Void);
        CHECK(11)
        aux_Ref_Manager = *os_Refman;
        *os_Refman = s_Refman;
        LUMI_inc_ref(*os_Refman);
        LUMI_dec_ref(aux_Ref_Manager);
        aux_Ref_Manager = NULL;
        *os = s;
        LUMI_err = ut_M_TestIterator_next(aux_TestIterator_0, aux_TestIterator_0_Refman);
        CHECK(11)
    }
    aux_Ref_Manager = aux_TestIterator_0_Refman;
    aux_TestIterator_0_Refman = NULL;
    LUMI_inc_ref(aux_TestIterator_0_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_TestIterator_0 = NULL;
    aux_Ref_Manager = aux_TestIterator_1_Refman;
    aux_TestIterator_1_Refman = titer_Refman;
    LUMI_inc_ref(aux_TestIterator_1_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_TestIterator_1 = titer;
    while (true) {
        Bool t_Has = false;
        LUMI_err = ut_M_TestIterator_has(aux_TestIterator_1, aux_TestIterator_1_Refman, &(t_Has));
        CHECK(13)
        if (!t_Has) break;
        LUMI_err = ut_M_TestIterator_get(aux_TestIterator_1, aux_TestIterator_1_Refman, (void*)&(t), &(t_Refman), (void*)&(t_Dynamic));
        CHECK(13)
        aux_Ref_Manager = *ot_Refman;
        *ot_Refman = t_Refman;
        *ot_Dynamic = t_Dynamic;
        LUMI_inc_ref(*ot_Refman);
        LUMI_dec_ref(aux_Ref_Manager);
        aux_Ref_Manager = NULL;
        *ot = t;
        LUMI_err = ut_M_TestIterator_next(aux_TestIterator_1, aux_TestIterator_1_Refman);
        CHECK(13)
    }
    aux_Ref_Manager = aux_TestIterator_1_Refman;
    aux_TestIterator_1_Refman = NULL;
    LUMI_inc_ref(aux_TestIterator_1_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_TestIterator_1 = NULL;
LUMI_cleanup:
    LUMI_dec_ref(aux_TestIterator_1_Refman);
    LUMI_dec_ref(t_Refman);
    LUMI_dec_ref(aux_TestIterator_0_Refman);
    LUMI_dec_ref(s_Refman);
    LUMI_dec_ref(titer_Refman);
    LUMI_dec_ref(siter_Refman);
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
    Returncode (*has)(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic, Bool* has_data);
    Returncode (*get)(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
    Returncode (*next)(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic);
};
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic, Bool* has_data);
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic);
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic);
void ut_M_TestIterator_Del(ut_M_TestIterator* self);
Returncode ut_M_f_mock(ut_M_TestIterator* iter, Ref_Manager* iter_Refman, ut_M_TestIterator_Dynamic* iter_Dynamic, String** s, Ref_Manager** s_Refman);
ut_M_TestIterator_Dynamic ut_M_TestIterator_dynamic = {(Dynamic_Del)ut_M_TestIterator_Del, ut_M_TestIterator_has, ut_M_TestIterator_get, ut_M_TestIterator_next};
Returncode ut_M_TestIterator_has(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic, Bool* has_data) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_TestIterator_get(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic, Generic_Type** item, Ref_Manager** item_Refman, Generic_Type_Dynamic** item_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode ut_M_TestIterator_next(ut_M_TestIterator* self, Ref_Manager* self_Refman, ut_M_TestIterator_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_TestIterator_Del(ut_M_TestIterator* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->item_Refman);
}
Returncode ut_M_f_mock(ut_M_TestIterator* iter, Ref_Manager* iter_Refman, ut_M_TestIterator_Dynamic* iter_Dynamic, String** s, Ref_Manager** s_Refman) {
    Returncode LUMI_err = OK;
    String* t = NULL;
    Ref_Manager* t_Refman = NULL;
    ut_M_TestIterator* aux_TestIterator_0 = NULL;
    Ref_Manager* aux_TestIterator_0_Refman = NULL;
    ut_M_TestIterator_Dynamic* aux_TestIterator_0_Dynamic = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(iter_Refman);
    aux_Ref_Manager = aux_TestIterator_0_Refman;
    aux_TestIterator_0_Refman = iter_Refman;
    aux_TestIterator_0_Dynamic = iter_Dynamic;
    LUMI_inc_ref(aux_TestIterator_0_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_TestIterator_0 = iter;
    while (true) {
        Bool t_Has = false;
        if (aux_TestIterator_0_Dynamic == NULL) RAISE(7, empty_object)
        LUMI_err = aux_TestIterator_0_Dynamic->has(aux_TestIterator_0, aux_TestIterator_0_Refman, aux_TestIterator_0_Dynamic, &(t_Has));
        CHECK(7)
        if (!t_Has) break;
        if (aux_TestIterator_0_Dynamic == NULL) RAISE(7, empty_object)
        LUMI_err = aux_TestIterator_0_Dynamic->get(aux_TestIterator_0, aux_TestIterator_0_Refman, aux_TestIterator_0_Dynamic, (void*)&(t), &(t_Refman), &dynamic_Void);
        CHECK(7)
        aux_Ref_Manager = *s_Refman;
        *s_Refman = t_Refman;
        LUMI_inc_ref(*s_Refman);
        LUMI_dec_ref(aux_Ref_Manager);
        aux_Ref_Manager = NULL;
        *s = t;
        if (aux_TestIterator_0_Dynamic == NULL) RAISE(8, empty_object)
        LUMI_err = aux_TestIterator_0_Dynamic->next(aux_TestIterator_0, aux_TestIterator_0_Refman, aux_TestIterator_0_Dynamic);
        CHECK(7)
    }
    aux_Ref_Manager = aux_TestIterator_0_Refman;
    aux_TestIterator_0_Refman = NULL;
    aux_TestIterator_0_Dynamic = NULL;
    LUMI_inc_ref(aux_TestIterator_0_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    aux_TestIterator_0 = NULL;
LUMI_cleanup:
    LUMI_dec_ref(aux_TestIterator_0_Refman);
    LUMI_dec_ref(t_Refman);
    LUMI_dec_ref(iter_Refman);
    return LUMI_err;
}
/// @ te0
cannot iterate type with no "has" named method - "TestIterator"
/// @ te1
iterator "has" method has parameters in type "TestIterator"
/// @ te2
iterator "has" method has no outputs in type "TestIterator"
/// @ te3
iterator "has" method has more than one output in type "TestIterator"
/// @ te4
iterator "has" method output is not "Bool" in type "TestIterator"
/// @ te5
cannot iterate type with no "get" named method - "TestIterator"
/// @ te6
iterator "get" method has parameters in type "TestIterator"
/// @ te7
iterator "get" method has no outputs in type "TestIterator"
/// @ te8
iterator "get" method has more than one output in type "TestIterator"
/// @ te9
iterator "get" method output has "owner" access in type "TestIterator"
/// @ te10
cannot iterate type with no "next" named method - "TestIterator"
/// @ te11
iterator "next" method has parameters in type "TestIterator"
/// @ te12
iterator "next" method has outputs in type "TestIterator"
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
    Returncode (*meth)(ut_M_Astruct* self, Ref_Manager* self_Refman, ut_M_Astruct_Dynamic* self_Dynamic);
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
};
Returncode ut_M_Astruct_meth(ut_M_Astruct* self, Ref_Manager* self_Refman, ut_M_Astruct_Dynamic* self_Dynamic);
void ut_M_Astruct_Del(ut_M_Astruct* self);
Returncode ut_M_Bstruct_meth(ut_M_Bstruct* self, Ref_Manager* self_Refman, ut_M_Bstruct_Dynamic* self_Dynamic);
void ut_M_Bstruct_Del(ut_M_Bstruct* self);
Returncode ut_M_Test_test(ut_M_Test* self, Ref_Manager* self_Refman);
void ut_M_Test_Del(ut_M_Test* self);
ut_M_Astruct_Dynamic ut_M_Astruct_dynamic = {(Dynamic_Del)ut_M_Astruct_Del, ut_M_Astruct_meth};
ut_M_Bstruct_Dynamic ut_M_Bstruct_dynamic = {{(Dynamic_Del)ut_M_Bstruct_Del, (Func)ut_M_Bstruct_meth}};
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Returncode ut_M_Astruct_meth(ut_M_Astruct* self, Ref_Manager* self_Refman, ut_M_Astruct_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Astruct_Del(ut_M_Astruct* self) {
    if (self == NULL) return;
}
Returncode ut_M_Bstruct_meth(ut_M_Bstruct* self, Ref_Manager* self_Refman, ut_M_Bstruct_Dynamic* self_Dynamic) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Bstruct_Del(ut_M_Bstruct* self) {
    if (self == NULL) return;
    ut_M_Astruct_Del(&(self->_base));
    LUMI_dec_ref(self->b_Refman);
}
Returncode ut_M_Test_test(ut_M_Test* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    ut_M_Bstruct* b = NULL;
    Ref_Manager* b_Refman = NULL;
    ut_M_Bstruct_Dynamic* b_Dynamic = NULL;
    ut_M_Bstruct* b2 = NULL;
    Ref_Manager* b2_Refman = NULL;
    ut_M_Bstruct_Dynamic* b2_Dynamic = NULL;
    ut_M_Test t_Var = {{{0}}};
    ut_M_Test* t = NULL;
    Ref_Manager* t_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    CHECK_REF(4, self, self_Refman)
    b = &(self->b);
    b_Refman = self_Refman;
    LUMI_inc_ref(b_Refman);
    b_Dynamic = &ut_M_Bstruct_dynamic;
    CHECK_REF(5, self, self_Refman)
    aux_Ref_Manager = b_Refman;
    b_Refman = self_Refman;
    b_Dynamic = &ut_M_Bstruct_dynamic;
    LUMI_inc_ref(b_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    b = &(self->b);
    CHECK_REF(6, self, self_Refman)
    LUMI_err = ut_M_Bstruct_meth(&(self->b), self_Refman, &ut_M_Bstruct_dynamic);
    CHECK(6)
    CHECK_REF(7, self, self_Refman)
    LUMI_err = ut_M_Bstruct_meth(&(self->b), self_Refman, &ut_M_Bstruct_dynamic);
    CHECK(7)
    CHECK_REF(8, self, self_Refman)
    b2 = self->b.b;
    b2_Refman = self->b.b_Refman;
    LUMI_inc_ref(b2_Refman);
    b2_Dynamic = self->b.b_Dynamic;
    CHECK_REF(9, self, self_Refman)
    aux_Ref_Manager = b2_Refman;
    b2_Refman = self->b.b_Refman;
    b2_Dynamic = self->b.b_Dynamic;
    LUMI_inc_ref(b2_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    b2 = self->b.b;
    CHECK_REF(10, self, self_Refman)
    if (self->b.b_Dynamic == NULL) RAISE(10, empty_object)
    LUMI_err = self->b.b_Dynamic->_base.meth(&(self->b.b->_base), self->b.b_Refman, &(self->b.b_Dynamic->_base));
    CHECK(10)
    CHECK_REF(11, self, self_Refman)
    aux_Ref_Manager = self->b.b_Refman;
    self->b.b_Refman = b_Refman;
    self->b.b_Dynamic = b_Dynamic;
    LUMI_inc_ref(self->b.b_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->b.b = b;
    CHECK_REF(12, self, self_Refman)
    LUMI_err = ut_M_Bstruct_meth(self->b.b, self->b.b_Refman, self->b.b_Dynamic);
    CHECK(12)
    INIT_VAR(13, t)
    CHECK_REF(14, self, self_Refman)
    self->b._base.x = 5;
    CHECK_REF(15, self, self_Refman)
    LUMI_err = ut_M_Astruct_meth(&(self->b._base), self_Refman, &(ut_M_Bstruct_dynamic._base));
    CHECK(15)
    CHECK_REF(16, self, self_Refman)
    CHECK_REF(16, self, self_Refman)
    if (((void*)&(self->b) == b) || ((void*)b2 != &(self->b))) {
    }
LUMI_cleanup:
    LUMI_var_dec_ref(t_Refman);
    LUMI_dec_ref(b2_Refman);
    LUMI_dec_ref(b_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
    ut_M_Bstruct_Del(&(self->b));
}
/// @ te0
cannot declared "var" field of sequence type "String"
/// @ te1
cannot declared "var" field of sequence type "Array"
/// @ te2
recursive declaration of type "Test", variable of type "Test"
/// @ te3
recursive declaration of type "Test", variable of type "Base", variable of type "Test"
/// @ te4
recursive declaration of type "Abase", extended by type "Aerror", variable of type "Bbase", extended by type "Berror", variable of type "Abase"
/// @ te5
assigning into non assignable expression
/// @ te6
cannot use "?" on complex field
/// @@ test-enum
/// @ t0
enum {
    ut_M_MyEnum_VALUE = 0,
    ut_M_MyEnum_ANOTHER_VALUE,
    ut_M_MyEnum_LAST_VALUE,
    ut_M_MyEnum_length
};
Returncode ut_M_dummy(void);
Returncode ut_M_dummy(void) {
    Returncode LUMI_err = OK;
    Int x = 0;
    x = ut_M_MyEnum_VALUE;
    x += ut_M_MyEnum_ANOTHER_VALUE;
    x -= ut_M_MyEnum_length;
LUMI_cleanup:
    return LUMI_err;
}
/// @ t1
enum {
    ut_M_MyEnum_VALUE = 0,
    ut_M_MyEnum_ANOTHER_VALUE,
    ut_M_MyEnum_LAST_VALUE,
    ut_M_MyEnum_length
};
Int ut_M_arr_Values[ut_M_MyEnum_length] = {0};
Array ut_M_arr_Var = {ut_M_MyEnum_length, NULL};
Array* ut_M_arr = NULL;
Ref_Manager* ut_M_arr_Refman = NULL;
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
expected new-line after Enum value, got "("
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
Int ut_M_arr_Values[ut_M_SIZE + 3] = {0};
Array ut_M_arr_Var = {ut_M_SIZE + 3, NULL};
Array* ut_M_arr = NULL;
Ref_Manager* ut_M_arr_Refman = NULL;
/// @ t2
enum { ut_M_SMALL = 7 };
enum { ut_M_LARGE = (- (2 * ut_M_SMALL)) + 1 };
/// @ te0
expected space after "const", got "new-line"
/// @ te1
Only "Int" typed constant supported, got "Bool"
/// @ te2
expected space after "Int", got "new-line"
/// @ te3
illegal constant name "Error"
/// @ te4
expected space after constant name, got "new-line"
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
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode second_M_Test_meth(second_M_Test* self, Ref_Manager* self_Refman);
void second_M_Test_Del(second_M_Test* self);
Returncode ut_M_fun(void);
Returncode second_M_fun(void);
Returncode second_M_dummy(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
Generic_Type_Dynamic second_M_Test_dynamic = {(Dynamic_Del)second_M_Test_Del};
ut_M_Test ut_M_t_Var = {0};
ut_M_Test* ut_M_t = NULL;
Ref_Manager* ut_M_t_Refman = NULL;
second_M_Test second_M_t_Var = {{0}};
second_M_Test* second_M_t = NULL;
Ref_Manager* second_M_t_Refman = NULL;
int LUMI_file0_line_count[17] = {
    -1,-1,-1,-1,-1,-1,-1,-1,-1, 0, 0, 0, 0, 0, 0, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.4.lm", 17, LUMI_file0_line_count}
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
Returncode second_M_Test_meth(second_M_Test* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void second_M_Test_Del(second_M_Test* self) {
    if (self == NULL) return;
    ut_M_Test_Del(&(self->_base));
}
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
    second_M_Test* nt = NULL;
    Ref_Manager* nt_Refman = NULL;
    ++LUMI_file_coverage[0].line_count[9];
    CHECK_REF(9, ut_M_t, ut_M_t_Refman)
    ut_M_t->x = ut_M_Enum_VALUE + ut_M_SIZE;
    ++LUMI_file_coverage[0].line_count[10];
    LUMI_err = ut_M_fun();
    CHECK(10)
    ++LUMI_file_coverage[0].line_count[11];
    LUMI_err = ut_M_Test_meth(ut_M_t, ut_M_t_Refman);
    CHECK(11)
    ++LUMI_file_coverage[0].line_count[12];
    CHECK_REF(12, second_M_t, second_M_t_Refman)
    second_M_t->_base.x = second_M_Enum_VALUE + second_M_SIZE;
    ++LUMI_file_coverage[0].line_count[13];
    LUMI_err = second_M_fun();
    CHECK(13)
    ++LUMI_file_coverage[0].line_count[14];
    LUMI_err = second_M_Test_meth(second_M_t, second_M_t_Refman);
    CHECK(14)
    ++LUMI_file_coverage[0].line_count[15];
    INIT_NEW(15, nt, LUMI_alloc(sizeof(second_M_Test)));
LUMI_cleanup:
    second_M_Test_Del(nt);
    LUMI_owner_dec_ref(nt_Refman);
    return LUMI_err;
}
Returncode second_M_fun(void) {
    Returncode LUMI_err = OK;
    ut_M_Test* nt = NULL;
    Ref_Manager* nt_Refman = NULL;
    CHECK_REF(9, second_M_t, second_M_t_Refman)
    second_M_t->_base.x = second_M_Enum_VALUE + second_M_SIZE;
    LUMI_err = second_M_fun();
    CHECK(10)
    LUMI_err = second_M_Test_meth(second_M_t, second_M_t_Refman);
    CHECK(11)
    CHECK_REF(12, ut_M_t, ut_M_t_Refman)
    ut_M_t->x = ut_M_Enum_VALUE + ut_M_SIZE;
    LUMI_err = ut_M_fun();
    CHECK(13)
    LUMI_err = ut_M_Test_meth(ut_M_t, ut_M_t_Refman);
    CHECK(14)
    INIT_NEW(15, nt, LUMI_alloc(sizeof(ut_M_Test)));
LUMI_cleanup:
    ut_M_Test_Del(nt);
    LUMI_owner_dec_ref(nt_Refman);
    return LUMI_err;
}
Returncode second_M_dummy(void) {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    Bool LUMI_success = true;
#undef RETURN_ERROR
#define RETURN_ERROR return LUMI_err;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "mock.4.lm"
    INIT_VAR(7, ut_M_t)
#undef LUMI_FILE_NAME
#define LUMI_FILE_NAME "path\\second.4.lm"
    INIT_VAR(7, second_M_t)
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    LUMI_success &= LUMI_run_test("dummy", second_M_dummy);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
}
TEST_MAIN_FUNC
/// @ t1
typedef struct ut_M_Test ut_M_Test;
struct ut_M_Test {
    Int x;
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman);
void ut_M_Test_Del(ut_M_Test* self);
Returncode ut_M_fun(void);
Returncode ut_M_fun_Mock(void);
Bool ut_M_fun_Mock_active = true;
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman);
Bool ut_M_Test_meth_Mock_active = true;
Returncode second_M_dummy(void);
Generic_Type_Dynamic ut_M_Test_dynamic = {(Dynamic_Del)ut_M_Test_Del};
int LUMI_file0_line_count[8] = {
    -1,-1,-1,-1,-1, 0, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.4.lm", 8, LUMI_file0_line_count}
};
Returncode ut_M_Test_meth(ut_M_Test* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    ++LUMI_file_coverage[0].line_count[5];
    LUMI_err = ut_M_fun_Mock();
    CHECK(5)
    ++LUMI_file_coverage[0].line_count[6];
    LUMI_err = ut_M_Test_meth_Mock(self, self_Refman);
    CHECK(6)
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
void ut_M_Test_Del(ut_M_Test* self) {
    if (self == NULL) return;
}
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
Returncode ut_M_fun_Mock(void) {
    Returncode LUMI_err = OK;
    if (!ut_M_fun_Mock_active) return ut_M_fun();
LUMI_cleanup:
    return LUMI_err;
}
Returncode ut_M_Test_meth_Mock(ut_M_Test* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    if (!ut_M_Test_meth_Mock_active) return ut_M_Test_meth(self, self_Refman);
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
Returncode second_M_dummy(void) {
    Returncode LUMI_err = OK;
LUMI_cleanup:
    return LUMI_err;
}
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    Bool LUMI_success = true;
    LUMI_success &= LUMI_run_test("dummy", second_M_dummy);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
}
TEST_MAIN_FUNC
/// @ t2
typedef void* Native;
Returncode external(void);
Returncode ut_M_fun(void);
Returncode second_M_use(void);
extern Int x;
int LUMI_file0_line_count[7] = {
    -1,-1,-1,-1,-1, 0,-1
};
File_Coverage LUMI_file_coverage[1] = {
    {"mock.4.lm", 7, LUMI_file0_line_count}
};
Returncode ut_M_fun(void) {
    Returncode LUMI_err = OK;
    ++LUMI_file_coverage[0].line_count[5];
    x = 0;
LUMI_cleanup:
    return LUMI_err;
}
Returncode second_M_use(void) {
    Returncode LUMI_err = OK;
    Native n = 0;
    x = 2;
    LUMI_err = external();
    CHECK(5)
LUMI_cleanup:
    return LUMI_err;
}
Returncode new_Mock(Bool* allocate_success) { return OK; }
Returncode delete_Mock(Ref self) { return OK; }
USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    Bool LUMI_success = true;
    LUMI_success &= LUMI_run_test("use", second_M_use);
    LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, 1);
    return LUMI_success? LUMI_err : FAIL;
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
/// @
