#include "lumi.4.h"


/* types declaration */

typedef struct lumi_M_Input lumi_M_Input;

typedef struct lumi_M_IncrementalString lumi_M_IncrementalString;

typedef struct lumi_M_Lumi lumi_M_Lumi;


/* Enums */


/* constants */

enum { lumi_M_MAX_COMMNAD_SIZE = 2048 };


/* types struct */

struct lumi_M_Input {
    String* name;
    Ref_Manager* name_Refman;
};

struct lumi_M_IncrementalString {
    String* text;
    Ref_Manager* text_Refman;
};

struct lumi_M_Lumi {
    Bool running_lumi;
    Bool running_c;
    Bool running_program;
    Bool explicit_output;
    Bool verbose;
    Bool execute;
    String* implicit_output;
    Ref_Manager* implicit_output_Refman;
    String* output;
    Ref_Manager* output_Refman;
    String* ut_module;
    Ref_Manager* ut_module_Refman;
    String* lib_module;
    Ref_Manager* lib_module_Refman;
    String* execute_arguments;
    Ref_Manager* execute_arguments_Refman;
    Char version;
    String* main_input;
    Ref_Manager* main_input_Refman;
    lumi_M_IncrementalString input_files;
    lumi_M_IncrementalString external_files;
    lumi_M_IncrementalString command;
    lumi_M_IncrementalString lumi_path;
    Char path_separator;
    Bool lumi_path_ends_with_separator;
};


/* types methods declaration */

void lumi_M_Input_Del(lumi_M_Input* self);

Returncode lumi_M_IncrementalString_new(lumi_M_IncrementalString* self, Ref_Manager* self_Refman);

Returncode lumi_M_IncrementalString_clear(lumi_M_IncrementalString* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman);

Returncode lumi_M_IncrementalString_concat(lumi_M_IncrementalString* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman);

Returncode lumi_M_IncrementalString_append(lumi_M_IncrementalString* self, Ref_Manager* self_Refman, Char ch);

Returncode lumi_M_IncrementalString_getenv(lumi_M_IncrementalString* self, Ref_Manager* self_Refman, String* name, Ref_Manager* name_Refman, Bool* exists);

Returncode lumi_M_IncrementalString_realloc(lumi_M_IncrementalString* self, Ref_Manager* self_Refman);

void lumi_M_IncrementalString_Del(lumi_M_IncrementalString* self);

Returncode lumi_M_Lumi_new(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_run_command(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* error_msg, Ref_Manager* error_msg_Refman);

Returncode lumi_M_Lumi_get_any_opt_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman, Int* index, String** value, Ref_Manager** value_Refman);

Returncode lumi_M_Lumi_get_opt_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman, Int* index, String** value, Ref_Manager** value_Refman);

Returncode lumi_M_Lumi_check_opt_param_error(lumi_M_Lumi* self, Ref_Manager* self_Refman, Bool is_error, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman);

Returncode lumi_M_Lumi_check_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* value, Ref_Manager* value_Refman);

Returncode lumi_M_Lumi_concat_lumi_output(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_concat_first_file_name(lumi_M_Lumi* self, Ref_Manager* self_Refman, lumi_M_IncrementalString* target, Ref_Manager* target_Refman, String* name, Ref_Manager* name_Refman);

Returncode lumi_M_Lumi_concat_file_name(lumi_M_Lumi* self, Ref_Manager* self_Refman, lumi_M_IncrementalString* target, Ref_Manager* target_Refman, String* name, Ref_Manager* name_Refman);

Returncode lumi_M_Lumi_concat_tl_path(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_read_input(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_run_lumi(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_run_c(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_run_program(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_run(lumi_M_Lumi* self, Ref_Manager* self_Refman);

void lumi_M_Lumi_Del(lumi_M_Lumi* self);


/* global functions declaration */

Returncode lumi_M_error_if(Bool is_error, String* error_msg, Ref_Manager* error_msg_Refman);

Returncode lumi_M_help(void);


/* types global variables */

Generic_Type_Dynamic lumi_M_Input_dynamic = {(Dynamic_Del)lumi_M_Input_Del};

Generic_Type_Dynamic lumi_M_IncrementalString_dynamic = {(Dynamic_Del)lumi_M_IncrementalString_Del};

Generic_Type_Dynamic lumi_M_Lumi_dynamic = {(Dynamic_Del)lumi_M_Lumi_Del};


/* global variables */


/* types methods body */

void lumi_M_Input_Del(lumi_M_Input* self) {
    if (self == NULL) return;
    LUMI_dec_ref(self->name_Refman);
}

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "IncrementalString.new"
Returncode lumi_M_IncrementalString_new(lumi_M_IncrementalString* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    String* aux_String_1 = NULL;
    Ref_Manager* aux_String_1_Refman = NULL;
    LUMI_inc_ref(self_Refman);
    INIT_NEW(378, aux_String_0, LUMI_new_string(64));
    aux_String_1 = aux_String_0;
    aux_String_1_Refman = aux_String_0_Refman;
    aux_String_0 = NULL;
    aux_String_0_Refman = NULL;
    CHECK_REF(378, self, self_Refman)
    String_Del(self->text);
    LUMI_owner_dec_ref(self->text_Refman);
    self->text_Refman = aux_String_1_Refman;
    self->text = aux_String_1;
    aux_String_1 = NULL;
    aux_String_1_Refman = NULL;
LUMI_cleanup:
    String_Del(aux_String_1);
    LUMI_owner_dec_ref(aux_String_1_Refman);
    String_Del(aux_String_0);
    LUMI_owner_dec_ref(aux_String_0_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "IncrementalString.clear"
Returncode lumi_M_IncrementalString_clear(lumi_M_IncrementalString* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(text_Refman);
    CHECK_REF(381, self, self_Refman)
    LUMI_err = String_clear(self->text, self->text_Refman);
    CHECK(381)
    LUMI_err = lumi_M_IncrementalString_concat(self, self_Refman, text, text_Refman);
    CHECK(382)
LUMI_cleanup:
    LUMI_dec_ref(text_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "IncrementalString.concat"
Returncode lumi_M_IncrementalString_concat(lumi_M_IncrementalString* self, Ref_Manager* self_Refman, String* text, Ref_Manager* text_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(text_Refman);
    while (true) {
        do {
            ++LUMI_trace_ignore_count;
#undef RETURN_ERROR
#define RETURN_ERROR break
            CHECK_REF(387, self, self_Refman)
            LUMI_err = String_concat(self->text, self->text_Refman, text, text_Refman);
            CHECK(387)

#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
        } while (false);
        --LUMI_trace_ignore_count;
        if (LUMI_err != OK) {
            LUMI_err = OK;
            LUMI_err = lumi_M_IncrementalString_realloc(self, self_Refman);
            CHECK(389)
            continue;
        }
        break;
    }
LUMI_cleanup:
    LUMI_dec_ref(text_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "IncrementalString.append"
Returncode lumi_M_IncrementalString_append(lumi_M_IncrementalString* self, Ref_Manager* self_Refman, Char ch) {
    Returncode LUMI_err = OK;
    char text_Values[2] = {0};
    String text_Var = {2, 0, NULL};
    String* text = NULL;
    Ref_Manager* text_Refman = NULL;
    LUMI_inc_ref(self_Refman);
    INIT_VAR(394, text)
    text_Var.values = text_Values;
    LUMI_err = String_append(text, text_Refman, ch);
    CHECK(395)
    LUMI_err = lumi_M_IncrementalString_concat(self, self_Refman, text, text_Refman);
    CHECK(396)
LUMI_cleanup:
    LUMI_var_dec_ref(text_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "IncrementalString.getenv"
Returncode lumi_M_IncrementalString_getenv(lumi_M_IncrementalString* self, Ref_Manager* self_Refman, String* name, Ref_Manager* name_Refman, Bool* exists) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(name_Refman);
    while (true) {
        CHECK_REF(400, self, self_Refman)
        LUMI_err = Sys_getenv(sys, sys_Refman, name, name_Refman, self->text, self->text_Refman, &(*exists));
        CHECK(400)
        if (!(*exists)) break;
        CHECK_REF(401, self, self_Refman)
        CHECK_REF(401, self->text, self->text_Refman)
        CHECK_REF(401, self, self_Refman)
        CHECK_REF(401, self->text, self->text_Refman)
        if (!(self->text->length == self->text->max_length)) break;
        LUMI_err = lumi_M_IncrementalString_realloc(self, self_Refman);
        CHECK(402)
    }
LUMI_cleanup:
    LUMI_dec_ref(name_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "IncrementalString.realloc"
Returncode lumi_M_IncrementalString_realloc(lumi_M_IncrementalString* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    String* aux_String_1 = NULL;
    Ref_Manager* aux_String_1_Refman = NULL;
    LUMI_inc_ref(self_Refman);
    CHECK_REF(405, self, self_Refman)
    CHECK_REF(405, self, self_Refman)
    CHECK_REF(405, self->text, self->text_Refman)
    INIT_NEW(405, aux_String_0, LUMI_new_string(self->text->max_length * 2));
    LUMI_err = String_new(aux_String_0, aux_String_0_Refman, self->text, self->text_Refman);
    CHECK(405)
    aux_String_1 = aux_String_0;
    aux_String_1_Refman = aux_String_0_Refman;
    aux_String_0 = NULL;
    aux_String_0_Refman = NULL;
    CHECK_REF(405, self, self_Refman)
    String_Del(self->text);
    LUMI_owner_dec_ref(self->text_Refman);
    self->text_Refman = aux_String_1_Refman;
    self->text = aux_String_1;
    aux_String_1 = NULL;
    aux_String_1_Refman = NULL;
LUMI_cleanup:
    String_Del(aux_String_1);
    LUMI_owner_dec_ref(aux_String_1_Refman);
    String_Del(aux_String_0);
    LUMI_owner_dec_ref(aux_String_0_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void lumi_M_IncrementalString_Del(lumi_M_IncrementalString* self) {
    if (self == NULL) return;
    String_Del(self->text);
    LUMI_owner_dec_ref(self->text_Refman);
}

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.new"
Returncode lumi_M_Lumi_new(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    CHECK_REF(82, self, self_Refman)
    self->running_lumi = true;
    CHECK_REF(83, self, self_Refman)
    self->running_c = true;
    CHECK_REF(84, self, self_Refman)
    self->execute = true;
    CHECK_REF(85, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_new(&(self->input_files), self_Refman);
    CHECK(85)
    CHECK_REF(86, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_new(&(self->external_files), self_Refman);
    CHECK(86)
    CHECK_REF(87, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_new(&(self->command), self_Refman);
    CHECK(87)
    CHECK_REF(88, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_new(&(self->lumi_path), self_Refman);
    CHECK(88)
    CHECK_REF(89, self, self_Refman)
    self->path_separator = '/';
    CHECK_REF(90, self, self_Refman)
    self->lumi_path_ends_with_separator = true;
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.run-command"
Returncode lumi_M_Lumi_run_command(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* error_msg, Ref_Manager* error_msg_Refman) {
    Returncode LUMI_err = OK;
    Int aux_Int_0 = 0;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(error_msg_Refman);
    CHECK_REF(93, self, self_Refman)
    if (self->verbose) {
        CHECK_REF(94, self, self_Refman)
        LUMI_err = Sys_println(sys, sys_Refman, self->command.text, self->command.text_Refman);
        CHECK(94)
    }
    CHECK_REF(95, self, self_Refman)
    if (self->execute) {
        CHECK_REF(96, self, self_Refman)
        LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, 0);
        CHECK(96)
        CHECK_REF(97, self, self_Refman)
        LUMI_err = Sys_system(sys, sys_Refman, self->command.text, self->command.text_Refman, &(aux_Int_0));
        CHECK(97)
        if (aux_Int_0 != 0) {
            if (error_msg != NULL && error_msg_Refman->value != NULL) {
                LUMI_err = Sys_println(sys, sys_Refman, error_msg, error_msg_Refman);
                CHECK(99)
            }
            LUMI_err = Sys_exit(sys, sys_Refman, 1);
            CHECK(100)
        }
    }
LUMI_cleanup:
    LUMI_dec_ref(error_msg_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.get-any-opt-param"
Returncode lumi_M_Lumi_get_any_opt_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman, Int* index, String** value, Ref_Manager** value_Refman) {
    Returncode LUMI_err = OK;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(option_Refman);
    LUMI_inc_ref(param_Refman);
    CHECK_REF(105, sys, sys_Refman)
    CHECK_REF(105, sys->argv, sys->argv_Refman)
    LUMI_err = lumi_M_Lumi_check_opt_param_error(self, self_Refman, (*index) >= (sys->argv->length - 1), option, option_Refman, param, param_Refman);
    CHECK(104)
    *index += 1;
    CHECK_REF(107, sys, sys_Refman)
    CHECK_REF(107, sys->argv, sys->argv_Refman)
    if ((*index) < 0 || (*index) >= (sys->argv)->length) RAISE(107, slice_index)
    aux_Ref_Manager = *value_Refman;
    *value_Refman = sys->argv_Refman;
    LUMI_inc_ref(*value_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    *value = ((String*)((sys->argv)->values)) + *index;
LUMI_cleanup:
    LUMI_dec_ref(param_Refman);
    LUMI_dec_ref(option_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.get-opt-param"
Returncode lumi_M_Lumi_get_opt_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman, Int* index, String** value, Ref_Manager** value_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(option_Refman);
    LUMI_inc_ref(param_Refman);
    LUMI_err = lumi_M_Lumi_get_any_opt_param(self, self_Refman, option, option_Refman, param, param_Refman, &(*index), &(*value), &(*value_Refman));
    CHECK(111)
    CHECK_REF(112, *value, (*value_Refman))
    if ((0) < 0 || (0) >= ((*value))->length) RAISE(112, slice_index)
    LUMI_err = lumi_M_Lumi_check_opt_param_error(self, self_Refman, ((((*value))->values)[0]) == '-', option, option_Refman, param, param_Refman);
    CHECK(112)
    LUMI_err = lumi_M_Lumi_check_param(self, self_Refman, *value, *value_Refman);
    CHECK(113)
LUMI_cleanup:
    LUMI_dec_ref(param_Refman);
    LUMI_dec_ref(option_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.check-opt-param-error"
Returncode lumi_M_Lumi_check_opt_param_error(lumi_M_Lumi* self, Ref_Manager* self_Refman, Bool is_error, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman) {
    Returncode LUMI_err = OK;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    String aux_String_1_Var = {0};
    String* aux_String_1 = NULL;
    Ref_Manager* aux_String_1_Refman = NULL;
    String aux_String_2_Var = {0};
    String* aux_String_2 = NULL;
    Ref_Manager* aux_String_2_Refman = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(option_Refman);
    LUMI_inc_ref(param_Refman);
    if (is_error) {
        INIT_STRING_CONST(118, aux_String_0, "lumi: error: missing ");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
        CHECK(118)
        LUMI_err = Sys_print(sys, sys_Refman, param, param_Refman);
        CHECK(119)
        INIT_STRING_CONST(120, aux_String_1, " after \"-");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
        CHECK(120)
        LUMI_err = Sys_print(sys, sys_Refman, option, option_Refman);
        CHECK(121)
        INIT_STRING_CONST(122, aux_String_2, "\" flag");
        LUMI_err = Sys_println(sys, sys_Refman, aux_String_2, aux_String_2_Refman);
        CHECK(122)
        LUMI_err = Sys_exit(sys, sys_Refman, 1);
        CHECK(123)
    }
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_2_Refman);
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
    LUMI_dec_ref(param_Refman);
    LUMI_dec_ref(option_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.check-param"
Returncode lumi_M_Lumi_check_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* value, Ref_Manager* value_Refman) {
    Returncode LUMI_err = OK;
    Bool aux_Bool_0 = 0;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    String aux_String_1_Var = {0};
    String* aux_String_1 = NULL;
    Ref_Manager* aux_String_1_Refman = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(value_Refman);
    LUMI_err = String_has(value, value_Refman, '"', &(aux_Bool_0));
    CHECK(126)
    if (aux_Bool_0) {
        INIT_STRING_CONST(127, aux_String_0, "lumi: error: illegal \" character in parameter '");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
        CHECK(127)
        LUMI_err = Sys_print(sys, sys_Refman, value, value_Refman);
        CHECK(128)
        INIT_STRING_CONST(129, aux_String_1, "'");
        LUMI_err = Sys_println(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
        CHECK(129)
        LUMI_err = Sys_exit(sys, sys_Refman, 1);
        CHECK(130)
    }
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
    LUMI_dec_ref(value_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.concat-lumi-output"
Returncode lumi_M_Lumi_concat_lumi_output(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    String aux_String_1_Var = {0};
    String* aux_String_1 = NULL;
    Ref_Manager* aux_String_1_Refman = NULL;
    String aux_String_2_Var = {0};
    String* aux_String_2 = NULL;
    Ref_Manager* aux_String_2_Refman = NULL;
    LUMI_inc_ref(self_Refman);
    CHECK_REF(133, self, self_Refman)
    INIT_STRING_CONST(133, aux_String_0, " \"");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(133)
    CHECK_REF(134, self, self_Refman)
    CHECK_REF(134, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->output, self->output_Refman);
    CHECK(134)
    CHECK_REF(135, self, self_Refman)
    CHECK_REF(135, self, self_Refman)
    if (self->running_c || (! self->explicit_output)) {
        CHECK_REF(136, self, self_Refman)
        INIT_STRING_CONST(136, aux_String_1, ".c");
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_1, aux_String_1_Refman);
        CHECK(136)
    }
    CHECK_REF(137, self, self_Refman)
    INIT_STRING_CONST(137, aux_String_2, "\"");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_2, aux_String_2_Refman);
    CHECK(137)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_2_Refman);
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.concat-first-file-name"
Returncode lumi_M_Lumi_concat_first_file_name(lumi_M_Lumi* self, Ref_Manager* self_Refman, lumi_M_IncrementalString* target, Ref_Manager* target_Refman, String* name, Ref_Manager* name_Refman) {
    Returncode LUMI_err = OK;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    String aux_String_1_Var = {0};
    String* aux_String_1 = NULL;
    Ref_Manager* aux_String_1_Refman = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(target_Refman);
    LUMI_inc_ref(name_Refman);
    INIT_STRING_CONST(140, aux_String_0, "\"");
    LUMI_err = lumi_M_IncrementalString_concat(target, target_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(140)
    LUMI_err = lumi_M_IncrementalString_concat(target, target_Refman, name, name_Refman);
    CHECK(141)
    INIT_STRING_CONST(142, aux_String_1, "\"");
    LUMI_err = lumi_M_IncrementalString_concat(target, target_Refman, aux_String_1, aux_String_1_Refman);
    CHECK(142)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
    LUMI_dec_ref(name_Refman);
    LUMI_dec_ref(target_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.concat-file-name"
Returncode lumi_M_Lumi_concat_file_name(lumi_M_Lumi* self, Ref_Manager* self_Refman, lumi_M_IncrementalString* target, Ref_Manager* target_Refman, String* name, Ref_Manager* name_Refman) {
    Returncode LUMI_err = OK;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    LUMI_inc_ref(self_Refman);
    LUMI_inc_ref(target_Refman);
    LUMI_inc_ref(name_Refman);
    INIT_STRING_CONST(145, aux_String_0, " ");
    LUMI_err = lumi_M_IncrementalString_concat(target, target_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(145)
    LUMI_err = lumi_M_Lumi_concat_first_file_name(self, self_Refman, target, target_Refman, name, name_Refman);
    CHECK(146)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_0_Refman);
    LUMI_dec_ref(name_Refman);
    LUMI_dec_ref(target_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.concat-tl-path"
Returncode lumi_M_Lumi_concat_tl_path(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    LUMI_inc_ref(self_Refman);
    CHECK_REF(149, self, self_Refman)
    CHECK_REF(149, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->lumi_path.text, self->lumi_path.text_Refman);
    CHECK(149)
    CHECK_REF(150, self, self_Refman)
    if (! self->lumi_path_ends_with_separator) {
        CHECK_REF(151, self, self_Refman)
        CHECK_REF(151, self, self_Refman)
        LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->path_separator);
        CHECK(151)
    }
    CHECK_REF(152, self, self_Refman)
    INIT_STRING_CONST(152, aux_String_0, "TL");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(152)
    CHECK_REF(153, self, self_Refman)
    CHECK_REF(153, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->version);
    CHECK(153)
    CHECK_REF(154, self, self_Refman)
    CHECK_REF(154, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->path_separator);
    CHECK(154)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_0_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.read-input"
Returncode lumi_M_Lumi_read_input(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    Int input_files_num = 0;
    String* first_input = NULL;
    Ref_Manager* first_input_Refman = NULL;
    String* last_input = NULL;
    Ref_Manager* last_input_Refman = NULL;
    String* arg = NULL;
    Ref_Manager* arg_Refman = NULL;
    Char op = 0;
    Bool legal_name = 0;
    char version_string_Values[2] = {0};
    String version_string_Var = {2, 0, NULL};
    String* version_string = NULL;
    Ref_Manager* version_string_Refman = NULL;
    Int suffix_length = 0;
    Int index = 0;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    String aux_String_1_Var = {0};
    String* aux_String_1 = NULL;
    Ref_Manager* aux_String_1_Refman = NULL;
    Bool aux_Bool_0 = 0;
    String aux_String_2_Var = {0};
    String* aux_String_2 = NULL;
    Ref_Manager* aux_String_2_Refman = NULL;
    String aux_String_3_Var = {0};
    String* aux_String_3 = NULL;
    Ref_Manager* aux_String_3_Refman = NULL;
    String aux_String_4_Var = {0};
    String* aux_String_4 = NULL;
    Ref_Manager* aux_String_4_Refman = NULL;
    String aux_String_5_Var = {0};
    String* aux_String_5 = NULL;
    Ref_Manager* aux_String_5_Refman = NULL;
    String aux_String_6_Var = {0};
    String* aux_String_6 = NULL;
    Ref_Manager* aux_String_6_Refman = NULL;
    String aux_String_7_Var = {0};
    String* aux_String_7 = NULL;
    Ref_Manager* aux_String_7_Refman = NULL;
    String aux_String_8_Var = {0};
    String* aux_String_8 = NULL;
    Ref_Manager* aux_String_8_Refman = NULL;
    String aux_String_9_Var = {0};
    String* aux_String_9 = NULL;
    Ref_Manager* aux_String_9_Refman = NULL;
    String* aux_String_10 = NULL;
    Ref_Manager* aux_String_10_Refman = NULL;
    String aux_String_11_Var = {0};
    String* aux_String_11 = NULL;
    Ref_Manager* aux_String_11_Refman = NULL;
    String aux_String_12_Var = {0};
    String* aux_String_12 = NULL;
    Ref_Manager* aux_String_12_Refman = NULL;
    String* aux_String_13 = NULL;
    Ref_Manager* aux_String_13_Refman = NULL;
    String aux_String_14_Var = {0};
    String* aux_String_14 = NULL;
    Ref_Manager* aux_String_14_Refman = NULL;
    String aux_String_15_Var = {0};
    String* aux_String_15 = NULL;
    Ref_Manager* aux_String_15_Refman = NULL;
    String aux_String_16_Var = {0};
    String* aux_String_16 = NULL;
    Ref_Manager* aux_String_16_Refman = NULL;
    Bool aux_Bool_1 = 0;
    String aux_String_17_Var = {0};
    String* aux_String_17 = NULL;
    Ref_Manager* aux_String_17_Refman = NULL;
    Bool aux_Bool_2 = 0;
    String aux_String_18_Var = {0};
    String* aux_String_18 = NULL;
    Ref_Manager* aux_String_18_Refman = NULL;
    Bool aux_Bool_3 = 0;
    String aux_String_19_Var = {0};
    String* aux_String_19 = NULL;
    Ref_Manager* aux_String_19_Refman = NULL;
    String aux_String_20_Var = {0};
    String* aux_String_20 = NULL;
    Ref_Manager* aux_String_20_Refman = NULL;
    String aux_String_21_Var = {0};
    String* aux_String_21 = NULL;
    Ref_Manager* aux_String_21_Refman = NULL;
    String aux_String_22_Var = {0};
    String* aux_String_22 = NULL;
    Ref_Manager* aux_String_22_Refman = NULL;
    String aux_String_23_Var = {0};
    String* aux_String_23 = NULL;
    Ref_Manager* aux_String_23_Refman = NULL;
    String aux_String_24_Var = {0};
    String* aux_String_24 = NULL;
    Ref_Manager* aux_String_24_Refman = NULL;
    String aux_String_25_Var = {0};
    String* aux_String_25 = NULL;
    Ref_Manager* aux_String_25_Refman = NULL;
    String aux_String_26_Var = {0};
    String* aux_String_26 = NULL;
    Ref_Manager* aux_String_26_Refman = NULL;
    String aux_String_27_Var = {0};
    String* aux_String_27 = NULL;
    Ref_Manager* aux_String_27_Refman = NULL;
    String aux_String_28_Var = {0};
    String* aux_String_28 = NULL;
    Ref_Manager* aux_String_28_Refman = NULL;
    String aux_String_29_Var = {0};
    String* aux_String_29 = NULL;
    Ref_Manager* aux_String_29_Refman = NULL;
    String aux_String_30_Var = {0};
    String* aux_String_30 = NULL;
    Ref_Manager* aux_String_30_Refman = NULL;
    String aux_String_31_Var = {0};
    String* aux_String_31 = NULL;
    Ref_Manager* aux_String_31_Refman = NULL;
    String aux_String_32_Var = {0};
    String* aux_String_32 = NULL;
    Ref_Manager* aux_String_32_Refman = NULL;
    String aux_String_33_Var = {0};
    String* aux_String_33 = NULL;
    Ref_Manager* aux_String_33_Refman = NULL;
    String* aux_String_34 = NULL;
    Ref_Manager* aux_String_34_Refman = NULL;
    String* aux_String_35 = NULL;
    Ref_Manager* aux_String_35_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    CHECK_REF(161, sys, sys_Refman)
    CHECK_REF(161, sys->argv, sys->argv_Refman)
    for (index = 1; index < sys->argv->length; ++index) {
        CHECK_REF(162, sys, sys_Refman)
        CHECK_REF(162, sys->argv, sys->argv_Refman)
        if ((index) < 0 || (index) >= (sys->argv)->length) RAISE(162, slice_index)
        arg = ((String*)((sys->argv)->values)) + index;
        arg_Refman = sys->argv_Refman;
        LUMI_inc_ref(arg_Refman);
        CHECK_REF(163, arg, arg_Refman)
        if ((0) < 0 || (0) >= (arg)->length) RAISE(163, slice_index)
        if ((((arg)->values)[0]) == '-') {
            CHECK_REF(164, arg, arg_Refman)
            if (arg->length < 2) {
                INIT_STRING_CONST(165, aux_String_0, "lumi: warning: unknown flag \"-\"");
                LUMI_err = Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
                CHECK(165)
            }
            else {
                    CHECK_REF(167, arg, arg_Refman)
                    if ((1) < 0 || (1) >= (arg)->length) RAISE(167, slice_index)
                    op = ((arg)->values)[1];
                    INIT_STRING_CONST(168, aux_String_1, "--help");
                    LUMI_err = String_equal(arg, arg_Refman, aux_String_1, aux_String_1_Refman, &(aux_Bool_0));
                    CHECK(168)
                    if ((op == 'h') || aux_Bool_0) {
                    LUMI_err = lumi_M_help();
                    CHECK(169)
                }
                    else {
                        if (op == 'o') {
                            INIT_STRING_CONST(171, aux_String_2, "o");
                            INIT_STRING_CONST(171, aux_String_3, "file name");
                            CHECK_REF(172, self, self_Refman)
                            LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_2, aux_String_2_Refman, aux_String_3, aux_String_3_Refman, &(index), &(self->output), &(self->output_Refman));
                            CHECK(171)
                            CHECK_REF(173, self, self_Refman)
                            self->explicit_output = true;
                        }
                        else {
                            if (op == 't') {
                                INIT_STRING_CONST(175, aux_String_4, "t");
                                INIT_STRING_CONST(175, aux_String_5, "module name");
                                CHECK_REF(176, self, self_Refman)
                                LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_4, aux_String_4_Refman, aux_String_5, aux_String_5_Refman, &(index), &(self->ut_module), &(self->ut_module_Refman));
                                CHECK(175)
                            }
                            else {
                                if (op == 'l') {
                                    INIT_STRING_CONST(178, aux_String_6, "l");
                                    INIT_STRING_CONST(178, aux_String_7, "module name");
                                    CHECK_REF(179, self, self_Refman)
                                    LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_6, aux_String_6_Refman, aux_String_7, aux_String_7_Refman, &(index), &(self->lib_module), &(self->lib_module_Refman));
                                    CHECK(178)
                                }
                                else {
                                    if (op == 'e') {
                                        CHECK_REF(182, self, self_Refman)
                                        INIT_STRING_CONST(184, aux_String_8, "e");
                                        INIT_STRING_CONST(184, aux_String_9, "argument");
                                        LUMI_err = lumi_M_Lumi_get_any_opt_param(self, self_Refman, aux_String_8, aux_String_8_Refman, aux_String_9, aux_String_9_Refman, &(index), &(aux_String_10), &(aux_String_10_Refman));
                                        CHECK(181)
                                        LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, &(self->external_files), self_Refman, aux_String_10, aux_String_10_Refman);
                                        CHECK(181)
                                    }
                                    else {
                                        if (op == 'p') {
                                            CHECK_REF(186, self, self_Refman)
                                            INIT_STRING_CONST(187, aux_String_11, "p");
                                            INIT_STRING_CONST(187, aux_String_12, "path");
                                            LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_11, aux_String_11_Refman, aux_String_12, aux_String_12_Refman, &(index), &(aux_String_13), &(aux_String_13_Refman));
                                            CHECK(186)
                                            LUMI_err = lumi_M_IncrementalString_clear(&(self->lumi_path), self_Refman, aux_String_13, aux_String_13_Refman);
                                            CHECK(186)
                                        }
                                        else {
                                            if (op == 'c') {
                                                CHECK_REF(189, self, self_Refman)
                                                self->running_c = false;
                                            }
                                            else {
                                                CHECK_REF(190, arg, arg_Refman)
                                                if ((op == 'T') && (arg->length == 4)) {
                                                    CHECK_REF(191, self, self_Refman)
                                                    self->running_lumi = false;
                                                    CHECK_REF(192, arg, arg_Refman)
                                                    if ((3) < 0 || (3) >= (arg)->length) RAISE(192, slice_index)
                                                    CHECK_REF(192, self, self_Refman)
                                                    self->version = ((arg)->values)[3];
                                                }
                                                else {
                                                    if (op == 'r') {
                                                        CHECK_REF(194, self, self_Refman)
                                                        self->running_program = true;
                                                        CHECK_REF(195, arg, arg_Refman)
                                                        if (arg->length > 2) {
                        CHECK_REF(196, arg, arg_Refman)
                        if ((2) < 0 || (2) >= (arg)->length) RAISE(196, slice_index)
                        if ((((arg)->values)[2]) == 'a') {
                            INIT_STRING_CONST(198, aux_String_14, "ra");
                            INIT_STRING_CONST(198, aux_String_15, "arguments");
                            CHECK_REF(199, self, self_Refman)
                            LUMI_err = lumi_M_Lumi_get_any_opt_param(self, self_Refman, aux_String_14, aux_String_14_Refman, aux_String_15, aux_String_15_Refman, &(index), &(self->execute_arguments), &(self->execute_arguments_Refman));
                            CHECK(197)
                        }
                    }
                                                    }
                                                    else {
                                                        INIT_STRING_CONST(200, aux_String_16, "--verbose");
                                                        LUMI_err = String_equal(arg, arg_Refman, aux_String_16, aux_String_16_Refman, &(aux_Bool_1));
                                                        CHECK(200)
                                                        if ((op == 'v') || aux_Bool_1) {
                                                            CHECK_REF(201, self, self_Refman)
                                                            self->verbose = true;
                                                        }
                                                        else {
                                                            INIT_STRING_CONST(202, aux_String_17, "--debug");
                                                            LUMI_err = String_equal(arg, arg_Refman, aux_String_17, aux_String_17_Refman, &(aux_Bool_2));
                                                            CHECK(202)
                                                            if ((op == 'd') || aux_Bool_2) {
                                                                CHECK_REF(203, self, self_Refman)
                                                                self->verbose = true;
                                                                CHECK_REF(204, self, self_Refman)
                                                                self->execute = false;
                                                            }
                                                            else {
                                                                INIT_STRING_CONST(205, aux_String_18, "--version");
                                                                LUMI_err = String_equal(arg, arg_Refman, aux_String_18, aux_String_18_Refman, &(aux_Bool_3));
                                                                CHECK(205)
                                                                if (aux_Bool_3) {
                                                                    INIT_STRING_CONST(206, aux_String_19, "lumi version 5.1.0");
                                                                    LUMI_err = Sys_println(sys, sys_Refman, aux_String_19, aux_String_19_Refman);
                                                                    CHECK(206)
                                                                    LUMI_err = Sys_exit(sys, sys_Refman, 0);
                                                                    CHECK(207)
                                                                }
                                                                else {
                                                                    INIT_STRING_CONST(209, aux_String_20, "lumi: warning: unknown flag \"");
                                                                    LUMI_err = Sys_print(sys, sys_Refman, aux_String_20, aux_String_20_Refman);
                                                                    CHECK(209)
                                                                    LUMI_err = Sys_print(sys, sys_Refman, arg, arg_Refman);
                                                                    CHECK(210)
                                                                    INIT_STRING_CONST(211, aux_String_21, "\"");
                                                                    LUMI_err = Sys_println(sys, sys_Refman, aux_String_21, aux_String_21_Refman);
                                                                    CHECK(211)
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
        }
        else {
                LUMI_err = lumi_M_Lumi_check_param(self, self_Refman, arg, arg_Refman);
                CHECK(213)
                if (! (first_input != NULL && first_input_Refman->value != NULL)) {
                aux_Ref_Manager = first_input_Refman;
                first_input_Refman = arg_Refman;
                LUMI_inc_ref(first_input_Refman);
                LUMI_dec_ref(aux_Ref_Manager);
                aux_Ref_Manager = NULL;
                first_input = arg;
            }
                aux_Ref_Manager = last_input_Refman;
                last_input_Refman = arg_Refman;
                LUMI_inc_ref(last_input_Refman);
                LUMI_dec_ref(aux_Ref_Manager);
                aux_Ref_Manager = NULL;
                last_input = arg;
                CHECK_REF(217, self, self_Refman)
                LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, &(self->input_files), self_Refman, arg, arg_Refman);
                CHECK(217)
                input_files_num += 1;
            }
    }
    INIT_STRING_CONST(220, aux_String_22, "lumi: error: no input files");
    LUMI_err = lumi_M_error_if(input_files_num == 0, aux_String_22, aux_String_22_Refman);
    CHECK(220)
    CHECK_REF(222, self, self_Refman)
    CHECK_REF(222, self, self_Refman)
    INIT_STRING_CONST(224, aux_String_23, "lumi: error: cannot run program when C compilation is turned off by \"-c\" flag");
    LUMI_err = lumi_M_error_if(self->running_program && (! self->running_c), aux_String_23, aux_String_23_Refman);
    CHECK(221)
    CHECK_REF(226, self, self_Refman)
    if (self->running_lumi) {
        CHECK_REF(227, first_input, first_input_Refman)
        legal_name = first_input->length >= 6;
        if (legal_name) {
            CHECK_REF(229, first_input, first_input_Refman)
            CHECK_REF(229, first_input, first_input_Refman)
            if ((first_input->length - 4) < 0 || (first_input->length - 4) >= (first_input)->length) RAISE(229, slice_index)
            CHECK_REF(229, self, self_Refman)
            self->version = ((first_input)->values)[first_input->length - 4];
            CHECK_REF(236, self, self_Refman)
            CHECK_REF(235, self, self_Refman)
            CHECK_REF(234, first_input, first_input_Refman)
            CHECK_REF(234, first_input, first_input_Refman)
            if ((first_input->length - 1) < 0 || (first_input->length - 1) >= (first_input)->length) RAISE(234, slice_index)
            CHECK_REF(233, first_input, first_input_Refman)
            CHECK_REF(233, first_input, first_input_Refman)
            if ((first_input->length - 2) < 0 || (first_input->length - 2) >= (first_input)->length) RAISE(233, slice_index)
            CHECK_REF(232, first_input, first_input_Refman)
            CHECK_REF(232, first_input, first_input_Refman)
            if ((first_input->length - 3) < 0 || (first_input->length - 3) >= (first_input)->length) RAISE(232, slice_index)
            CHECK_REF(231, first_input, first_input_Refman)
            CHECK_REF(231, first_input, first_input_Refman)
            if ((first_input->length - 5) < 0 || (first_input->length - 5) >= (first_input)->length) RAISE(231, slice_index)
            legal_name = ((((((((first_input)->values)[first_input->length - 5]) == '.') && ((((first_input)->values)[first_input->length - 3]) == '.')) && ((((first_input)->values)[first_input->length - 2]) == 'l')) && ((((first_input)->values)[first_input->length - 1]) == 'm')) && (self->version >= '0')) && (self->version <= '9');
        }
        if (! legal_name) {
            INIT_STRING_CONST(238, aux_String_24, "lumi: error: Illegal input Lumi file name \"");
            LUMI_err = Sys_print(sys, sys_Refman, aux_String_24, aux_String_24_Refman);
            CHECK(238)
            LUMI_err = Sys_print(sys, sys_Refman, first_input, first_input_Refman);
            CHECK(239)
            INIT_STRING_CONST(240, aux_String_25, "\", expected [name].[version digit].lm");
            LUMI_err = Sys_println(sys, sys_Refman, aux_String_25, aux_String_25_Refman);
            CHECK(240)
            LUMI_err = Sys_exit(sys, sys_Refman, 1);
            CHECK(241)
        }
    }
    CHECK_REF(243, self, self_Refman)
    CHECK_REF(243, self, self_Refman)
    if ((self->version < '0') || (self->version > '5')) {
        INIT_STRING_CONST(244, aux_String_26, "lumi: error: unsupported version TL");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_26, aux_String_26_Refman);
        CHECK(244)
        INIT_VAR(245, version_string)
        version_string_Var.values = version_string_Values;
        CHECK_REF(246, self, self_Refman)
        LUMI_err = String_append(version_string, version_string_Refman, self->version);
        CHECK(246)
        LUMI_err = Sys_println(sys, sys_Refman, version_string, version_string_Refman);
        CHECK(247)
        LUMI_err = Sys_exit(sys, sys_Refman, 1);
        CHECK(248)
    }
    CHECK_REF(250, self, self_Refman)
    INIT_STRING_CONST(251, aux_String_27, "lumi: error: multiple files not supported before TL2");
    LUMI_err = lumi_M_error_if((self->version < '2') && (input_files_num > 1), aux_String_27, aux_String_27_Refman);
    CHECK(249)
    CHECK_REF(254, self, self_Refman)
    CHECK_REF(254, self, self_Refman)
    CHECK_REF(253, self, self_Refman)
    CHECK_REF(253, self, self_Refman)
    INIT_STRING_CONST(255, aux_String_28, "lumi: error: cannot specify C output file in TL2 & TL3");
    LUMI_err = lumi_M_error_if((((self->version >= '2') && (self->version <= '3')) && self->explicit_output) && (! self->running_c), aux_String_28, aux_String_28_Refman);
    CHECK(252)
    CHECK_REF(257, self, self_Refman)
    CHECK_REF(257, self, self_Refman)
    INIT_STRING_CONST(258, aux_String_29, "lumi: error: testing not supported before TL4");
    LUMI_err = lumi_M_error_if((self->version < '4') && (self->ut_module != NULL && self->ut_module_Refman->value != NULL), aux_String_29, aux_String_29_Refman);
    CHECK(256)
    CHECK_REF(260, self, self_Refman)
    CHECK_REF(260, self, self_Refman)
    INIT_STRING_CONST(262, aux_String_30, "lumi: error: shared library compilation not supported before TL5");
    LUMI_err = lumi_M_error_if((self->version < '5') && (self->lib_module != NULL && self->lib_module_Refman->value != NULL), aux_String_30, aux_String_30_Refman);
    CHECK(259)
    CHECK_REF(264, self, self_Refman)
    CHECK_REF(264, self, self_Refman)
    INIT_STRING_CONST(265, aux_String_31, "lumi: error: cannot run a shared library");
    LUMI_err = lumi_M_error_if(self->running_program && (self->lib_module != NULL && self->lib_module_Refman->value != NULL), aux_String_31, aux_String_31_Refman);
    CHECK(263)
    CHECK_REF(267, self, self_Refman)
    CHECK_REF(267, self, self_Refman)
    INIT_STRING_CONST(269, aux_String_32, "lumi: error: cannot generate testing and shared library compilation together");
    LUMI_err = lumi_M_error_if((self->ut_module != NULL && self->ut_module_Refman->value != NULL) && (self->lib_module != NULL && self->lib_module_Refman->value != NULL), aux_String_32, aux_String_32_Refman);
    CHECK(266)
    CHECK_REF(270, self, self_Refman)
    if (self->version <= '2') {
        CHECK_REF(271, self, self_Refman)
        aux_Ref_Manager = self->main_input_Refman;
        self->main_input_Refman = last_input_Refman;
        LUMI_inc_ref(self->main_input_Refman);
        LUMI_dec_ref(aux_Ref_Manager);
        aux_Ref_Manager = NULL;
        self->main_input = last_input;
    }
    else {
            CHECK_REF(273, self, self_Refman)
            aux_Ref_Manager = self->main_input_Refman;
            self->main_input_Refman = first_input_Refman;
            LUMI_inc_ref(self->main_input_Refman);
            LUMI_dec_ref(aux_Ref_Manager);
            aux_Ref_Manager = NULL;
            self->main_input = first_input;
        }
    CHECK_REF(275, self, self_Refman)
    if (! (self->output != NULL && self->output_Refman->value != NULL)) {
        suffix_length = 2;
        CHECK_REF(277, self, self_Refman)
        if (self->running_lumi) {
            suffix_length = 5;
        }
        CHECK_REF(280, self, self_Refman)
        CHECK_REF(280, self, self_Refman)
        CHECK_REF(280, self->main_input, self->main_input_Refman)
        INIT_VAR(280, aux_String_33)
        aux_String_33_Var.length = self->main_input->length - suffix_length;
        aux_String_33_Var.max_length = aux_String_33_Var.length + 1;
        aux_String_33_Var.values = (self->main_input)->values + (0);
        CHECK_REF(280, self->main_input, self->main_input_Refman)
        if ((0) < 0 || (self->main_input->length - suffix_length) < 0 || (0) + (self->main_input->length - suffix_length) > (self->main_input)->length) RAISE(280, slice_index)
        CHECK_REF(279, self, self_Refman)
        CHECK_REF(279, self->main_input, self->main_input_Refman)
        INIT_NEW(279, aux_String_34, LUMI_new_string(self->main_input->length));
        LUMI_err = String_new(aux_String_34, aux_String_34_Refman, aux_String_33, self->main_input_Refman);
        CHECK(279)
        aux_String_35 = aux_String_34;
        aux_String_35_Refman = aux_String_34_Refman;
        aux_String_34 = NULL;
        aux_String_34_Refman = NULL;
        CHECK_REF(279, self, self_Refman)
        String_Del(self->implicit_output);
        LUMI_owner_dec_ref(self->implicit_output_Refman);
        self->implicit_output_Refman = aux_String_35_Refman;
        self->implicit_output = aux_String_35;
        aux_String_35 = NULL;
        aux_String_35_Refman = NULL;
        CHECK_REF(282, self, self_Refman)
        CHECK_REF(282, self, self_Refman)
        aux_Ref_Manager = self->output_Refman;
        self->output_Refman = self->implicit_output_Refman;
        LUMI_inc_ref(self->output_Refman);
        LUMI_dec_ref(aux_Ref_Manager);
        aux_Ref_Manager = NULL;
        self->output = self->implicit_output;
    }
LUMI_cleanup:
    String_Del(aux_String_35);
    LUMI_owner_dec_ref(aux_String_35_Refman);
    String_Del(aux_String_34);
    LUMI_owner_dec_ref(aux_String_34_Refman);
    LUMI_var_dec_ref(aux_String_33_Refman);
    LUMI_var_dec_ref(aux_String_32_Refman);
    LUMI_var_dec_ref(aux_String_31_Refman);
    LUMI_var_dec_ref(aux_String_30_Refman);
    LUMI_var_dec_ref(aux_String_29_Refman);
    LUMI_var_dec_ref(aux_String_28_Refman);
    LUMI_var_dec_ref(aux_String_27_Refman);
    LUMI_var_dec_ref(aux_String_26_Refman);
    LUMI_var_dec_ref(aux_String_25_Refman);
    LUMI_var_dec_ref(aux_String_24_Refman);
    LUMI_var_dec_ref(aux_String_23_Refman);
    LUMI_var_dec_ref(aux_String_22_Refman);
    LUMI_var_dec_ref(aux_String_21_Refman);
    LUMI_var_dec_ref(aux_String_20_Refman);
    LUMI_var_dec_ref(aux_String_19_Refman);
    LUMI_var_dec_ref(aux_String_18_Refman);
    LUMI_var_dec_ref(aux_String_17_Refman);
    LUMI_var_dec_ref(aux_String_16_Refman);
    LUMI_var_dec_ref(aux_String_15_Refman);
    LUMI_var_dec_ref(aux_String_14_Refman);
    LUMI_dec_ref(aux_String_13_Refman);
    LUMI_var_dec_ref(aux_String_12_Refman);
    LUMI_var_dec_ref(aux_String_11_Refman);
    LUMI_dec_ref(aux_String_10_Refman);
    LUMI_var_dec_ref(aux_String_9_Refman);
    LUMI_var_dec_ref(aux_String_8_Refman);
    LUMI_var_dec_ref(aux_String_7_Refman);
    LUMI_var_dec_ref(aux_String_6_Refman);
    LUMI_var_dec_ref(aux_String_5_Refman);
    LUMI_var_dec_ref(aux_String_4_Refman);
    LUMI_var_dec_ref(aux_String_3_Refman);
    LUMI_var_dec_ref(aux_String_2_Refman);
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
    LUMI_var_dec_ref(version_string_Refman);
    LUMI_dec_ref(arg_Refman);
    LUMI_dec_ref(last_input_Refman);
    LUMI_dec_ref(first_input_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.run-lumi"
Returncode lumi_M_Lumi_run_lumi(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    String aux_String_1_Var = {0};
    String* aux_String_1 = NULL;
    Ref_Manager* aux_String_1_Refman = NULL;
    String aux_String_2_Var = {0};
    String* aux_String_2 = NULL;
    Ref_Manager* aux_String_2_Refman = NULL;
    String aux_String_3_Var = {0};
    String* aux_String_3 = NULL;
    Ref_Manager* aux_String_3_Refman = NULL;
    String aux_String_4_Var = {0};
    String* aux_String_4 = NULL;
    Ref_Manager* aux_String_4_Refman = NULL;
    LUMI_inc_ref(self_Refman);
    CHECK_REF(286, self, self_Refman)
    INIT_STRING_CONST(286, aux_String_0, "tl");
    LUMI_err = lumi_M_IncrementalString_clear(&(self->command), self_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(286)
    CHECK_REF(287, self, self_Refman)
    CHECK_REF(287, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->version);
    CHECK(287)
    CHECK_REF(288, self, self_Refman)
    INIT_STRING_CONST(288, aux_String_1, "-compiler");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_1, aux_String_1_Refman);
    CHECK(288)
    CHECK_REF(289, self, self_Refman)
    if (self->ut_module != NULL && self->ut_module_Refman->value != NULL) {
        CHECK_REF(290, self, self_Refman)
        INIT_STRING_CONST(290, aux_String_2, " -t");
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_2, aux_String_2_Refman);
        CHECK(290)
        CHECK_REF(291, self, self_Refman)
        CHECK_REF(291, self, self_Refman)
        LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, &(self->command), self_Refman, self->ut_module, self->ut_module_Refman);
        CHECK(291)
    }
    else {
            CHECK_REF(292, self, self_Refman)
            if (self->lib_module != NULL && self->lib_module_Refman->value != NULL) {
                CHECK_REF(293, self, self_Refman)
                INIT_STRING_CONST(293, aux_String_3, " -l");
                LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_3, aux_String_3_Refman);
                CHECK(293)
                CHECK_REF(294, self, self_Refman)
                CHECK_REF(294, self, self_Refman)
                LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, &(self->command), self_Refman, self->lib_module, self->lib_module_Refman);
                CHECK(294)
            }
        }
    CHECK_REF(295, self, self_Refman)
    if (self->version >= '4') {
        LUMI_err = lumi_M_Lumi_concat_lumi_output(self, self_Refman);
        CHECK(296)
    }
    CHECK_REF(297, self, self_Refman)
    CHECK_REF(297, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->input_files.text, self->input_files.text_Refman);
    CHECK(297)
    CHECK_REF(298, self, self_Refman)
    if (self->version <= '1') {
        LUMI_err = lumi_M_Lumi_concat_lumi_output(self, self_Refman);
        CHECK(299)
    }
    INIT_STRING_CONST(300, aux_String_4, "Lumi compiler failed");
    LUMI_err = lumi_M_Lumi_run_command(self, self_Refman, aux_String_4, aux_String_4_Refman);
    CHECK(300)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_4_Refman);
    LUMI_var_dec_ref(aux_String_3_Refman);
    LUMI_var_dec_ref(aux_String_2_Refman);
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.run-c"
Returncode lumi_M_Lumi_run_c(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    Char last = 0;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    Bool aux_Bool_0 = 0;
    String aux_String_1_Var = {0};
    String* aux_String_1 = NULL;
    Ref_Manager* aux_String_1_Refman = NULL;
    String aux_String_2_Var = {0};
    String* aux_String_2 = NULL;
    Ref_Manager* aux_String_2_Refman = NULL;
    Bool aux_Bool_1 = 0;
    String aux_String_3_Var = {0};
    String* aux_String_3 = NULL;
    Ref_Manager* aux_String_3_Refman = NULL;
    String aux_String_4_Var = {0};
    String* aux_String_4 = NULL;
    Ref_Manager* aux_String_4_Refman = NULL;
    String aux_String_5_Var = {0};
    String* aux_String_5 = NULL;
    Ref_Manager* aux_String_5_Refman = NULL;
    String aux_String_6_Var = {0};
    String* aux_String_6 = NULL;
    Ref_Manager* aux_String_6_Refman = NULL;
    String aux_String_7_Var = {0};
    String* aux_String_7 = NULL;
    Ref_Manager* aux_String_7_Refman = NULL;
    String aux_String_8_Var = {0};
    String* aux_String_8 = NULL;
    Ref_Manager* aux_String_8_Refman = NULL;
    String aux_String_9_Var = {0};
    String* aux_String_9 = NULL;
    Ref_Manager* aux_String_9_Refman = NULL;
    String aux_String_10_Var = {0};
    String* aux_String_10 = NULL;
    Ref_Manager* aux_String_10_Refman = NULL;
    String aux_String_11_Var = {0};
    String* aux_String_11 = NULL;
    Ref_Manager* aux_String_11_Refman = NULL;
    String aux_String_12_Var = {0};
    String* aux_String_12 = NULL;
    Ref_Manager* aux_String_12_Refman = NULL;
    String aux_String_13_Var = {0};
    String* aux_String_13 = NULL;
    Ref_Manager* aux_String_13_Refman = NULL;
    String aux_String_14_Var = {0};
    String* aux_String_14 = NULL;
    Ref_Manager* aux_String_14_Refman = NULL;
    String aux_String_15_Var = {0};
    String* aux_String_15 = NULL;
    Ref_Manager* aux_String_15_Refman = NULL;
    String aux_String_16_Var = {0};
    String* aux_String_16 = NULL;
    Ref_Manager* aux_String_16_Refman = NULL;
    String aux_String_17_Var = {0};
    String* aux_String_17 = NULL;
    Ref_Manager* aux_String_17_Refman = NULL;
    LUMI_inc_ref(self_Refman);
    CHECK_REF(303, self, self_Refman)
    INIT_STRING_CONST(303, aux_String_0, "CC");
    LUMI_err = lumi_M_IncrementalString_getenv(&(self->command), self_Refman, aux_String_0, aux_String_0_Refman, &(aux_Bool_0));
    CHECK(303)
    if (! aux_Bool_0) {
        CHECK_REF(304, self, self_Refman)
        INIT_STRING_CONST(304, aux_String_1, "gcc");
        LUMI_err = lumi_M_IncrementalString_clear(&(self->command), self_Refman, aux_String_1, aux_String_1_Refman);
        CHECK(304)
    }
    CHECK_REF(305, self, self_Refman)
    if (self->version < '5') {
        CHECK_REF(306, self, self_Refman)
        CHECK_REF(306, self->lumi_path.text, self->lumi_path.text_Refman)
        if (self->lumi_path.text->length == 0) {
            CHECK_REF(307, self, self_Refman)
            INIT_STRING_CONST(307, aux_String_2, "LUMIPATH");
            LUMI_err = lumi_M_IncrementalString_getenv(&(self->lumi_path), self_Refman, aux_String_2, aux_String_2_Refman, &(aux_Bool_1));
            CHECK(307)
        }
        CHECK_REF(308, self, self_Refman)
        CHECK_REF(308, self->lumi_path.text, self->lumi_path.text_Refman)
        if (self->lumi_path.text->length > 0) {
            CHECK_REF(310, self, self_Refman)
            CHECK_REF(310, self, self_Refman)
            CHECK_REF(310, self->lumi_path.text, self->lumi_path.text_Refman)
            CHECK_REF(310, self->lumi_path.text, self->lumi_path.text_Refman)
            if ((self->lumi_path.text->length - 1) < 0 || (self->lumi_path.text->length - 1) >= (self->lumi_path.text)->length) RAISE(310, slice_index)
            last = ((self->lumi_path.text)->values)[self->lumi_path.text->length - 1];
            if (last == '\\') {
                CHECK_REF(313, self, self_Refman)
                self->path_separator = '\\';
            }
            CHECK_REF(314, self, self_Refman)
            CHECK_REF(314, self, self_Refman)
            self->lumi_path_ends_with_separator = last == self->path_separator;
        }
    }
    CHECK_REF(315, self, self_Refman)
    INIT_STRING_CONST(315, aux_String_3, " -g");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_3, aux_String_3_Refman);
    CHECK(315)
    CHECK_REF(316, self, self_Refman)
    if (self->lib_module != NULL && self->lib_module_Refman->value != NULL) {
        CHECK_REF(317, self, self_Refman)
        INIT_STRING_CONST(317, aux_String_4, " -shared -fpic");
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_4, aux_String_4_Refman);
        CHECK(317)
    }
    CHECK_REF(318, self, self_Refman)
    if (self->running_lumi) {
        CHECK_REF(320, self, self_Refman)
        CHECK_REF(319, self, self_Refman)
        CHECK_REF(319, self, self_Refman)
        if (((self->version >= '2') && (self->version <= '3')) && self->explicit_output) {
            CHECK_REF(321, self, self_Refman)
            INIT_STRING_CONST(321, aux_String_5, " \"");
            LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_5, aux_String_5_Refman);
            CHECK(321)
            CHECK_REF(322, self, self_Refman)
            CHECK_REF(323, self, self_Refman)
            CHECK_REF(323, self, self_Refman)
            CHECK_REF(323, self->main_input, self->main_input_Refman)
            INIT_VAR(323, aux_String_6)
            aux_String_6_Var.length = self->main_input->length - 5;
            aux_String_6_Var.max_length = aux_String_6_Var.length + 1;
            aux_String_6_Var.values = (self->main_input)->values + (0);
            CHECK_REF(323, self->main_input, self->main_input_Refman)
            if ((0) < 0 || (self->main_input->length - 5) < 0 || (0) + (self->main_input->length - 5) > (self->main_input)->length) RAISE(323, slice_index)
            LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_6, self->main_input_Refman);
            CHECK(322)
            CHECK_REF(324, self, self_Refman)
            INIT_STRING_CONST(324, aux_String_7, ".c\"");
            LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_7, aux_String_7_Refman);
            CHECK(324)
        }
        else {
                LUMI_err = lumi_M_Lumi_concat_lumi_output(self, self_Refman);
                CHECK(326)
            }
    }
    else {
            CHECK_REF(328, self, self_Refman)
            CHECK_REF(328, self, self_Refman)
            LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->input_files.text, self->input_files.text_Refman);
            CHECK(328)
        }
    CHECK_REF(329, self, self_Refman)
    CHECK_REF(329, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->external_files.text, self->external_files.text_Refman);
    CHECK(329)
    CHECK_REF(330, self, self_Refman)
    INIT_STRING_CONST(330, aux_String_8, " ");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_8, aux_String_8_Refman);
    CHECK(330)
    CHECK_REF(331, self, self_Refman)
    if (self->version < '5') {
        LUMI_err = lumi_M_Lumi_concat_tl_path(self, self_Refman);
        CHECK(332)
        CHECK_REF(333, self, self_Refman)
        if (self->version == '0') {
            CHECK_REF(334, self, self_Refman)
            INIT_STRING_CONST(334, aux_String_9, "tl0-file.c ");
            LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_9, aux_String_9_Refman);
            CHECK(334)
            LUMI_err = lumi_M_Lumi_concat_tl_path(self, self_Refman);
            CHECK(335)
            CHECK_REF(336, self, self_Refman)
            INIT_STRING_CONST(336, aux_String_10, "tl0-string.c");
            LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_10, aux_String_10_Refman);
            CHECK(336)
        }
        else {
                CHECK_REF(338, self, self_Refman)
                INIT_STRING_CONST(338, aux_String_11, "lumi.");
                LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_11, aux_String_11_Refman);
                CHECK(338)
                CHECK_REF(339, self, self_Refman)
                CHECK_REF(339, self, self_Refman)
                LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->version);
                CHECK(339)
                CHECK_REF(340, self, self_Refman)
                INIT_STRING_CONST(340, aux_String_12, ".c");
                LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_12, aux_String_12_Refman);
                CHECK(340)
            }
        CHECK_REF(341, self, self_Refman)
        INIT_STRING_CONST(341, aux_String_13, " -I");
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_13, aux_String_13_Refman);
        CHECK(341)
        LUMI_err = lumi_M_Lumi_concat_tl_path(self, self_Refman);
        CHECK(342)
        CHECK_REF(343, self, self_Refman)
        LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, ' ');
        CHECK(343)
    }
    CHECK_REF(344, self, self_Refman)
    INIT_STRING_CONST(344, aux_String_14, "-o");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_14, aux_String_14_Refman);
    CHECK(344)
    CHECK_REF(345, self, self_Refman)
    CHECK_REF(345, self, self_Refman)
    if ((self->lib_module != NULL && self->lib_module_Refman->value != NULL) && (! self->explicit_output)) {
        CHECK_REF(346, self, self_Refman)
        INIT_STRING_CONST(346, aux_String_15, " \"lib");
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_15, aux_String_15_Refman);
        CHECK(346)
        CHECK_REF(347, self, self_Refman)
        CHECK_REF(347, self, self_Refman)
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->output, self->output_Refman);
        CHECK(347)
        CHECK_REF(348, self, self_Refman)
        INIT_STRING_CONST(348, aux_String_16, ".so\"");
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_16, aux_String_16_Refman);
        CHECK(348)
    }
    else {
            CHECK_REF(350, self, self_Refman)
            CHECK_REF(350, self, self_Refman)
            LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, &(self->command), self_Refman, self->output, self->output_Refman);
            CHECK(350)
        }
    INIT_STRING_CONST(351, aux_String_17, "C compiler failed");
    LUMI_err = lumi_M_Lumi_run_command(self, self_Refman, aux_String_17, aux_String_17_Refman);
    CHECK(351)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_17_Refman);
    LUMI_var_dec_ref(aux_String_16_Refman);
    LUMI_var_dec_ref(aux_String_15_Refman);
    LUMI_var_dec_ref(aux_String_14_Refman);
    LUMI_var_dec_ref(aux_String_13_Refman);
    LUMI_var_dec_ref(aux_String_12_Refman);
    LUMI_var_dec_ref(aux_String_11_Refman);
    LUMI_var_dec_ref(aux_String_10_Refman);
    LUMI_var_dec_ref(aux_String_9_Refman);
    LUMI_var_dec_ref(aux_String_8_Refman);
    LUMI_var_dec_ref(aux_String_7_Refman);
    LUMI_var_dec_ref(aux_String_6_Refman);
    LUMI_var_dec_ref(aux_String_5_Refman);
    LUMI_var_dec_ref(aux_String_4_Refman);
    LUMI_var_dec_ref(aux_String_3_Refman);
    LUMI_var_dec_ref(aux_String_2_Refman);
    LUMI_var_dec_ref(aux_String_1_Refman);
    LUMI_var_dec_ref(aux_String_0_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.run-program"
Returncode lumi_M_Lumi_run_program(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    Bool aux_Bool_0 = 0;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    LUMI_inc_ref(self_Refman);
    CHECK_REF(354, self, self_Refman)
    LUMI_err = String_clear(self->command.text, self->command.text_Refman);
    CHECK(354)
    CHECK_REF(355, self, self_Refman)
    CHECK_REF(355, self, self_Refman)
    LUMI_err = String_has(self->output, self->output_Refman, self->path_separator, &(aux_Bool_0));
    CHECK(355)
    if (! aux_Bool_0) {
        CHECK_REF(356, self, self_Refman)
        LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, '.');
        CHECK(356)
        CHECK_REF(357, self, self_Refman)
        CHECK_REF(357, self, self_Refman)
        LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->path_separator);
        CHECK(357)
    }
    CHECK_REF(358, self, self_Refman)
    CHECK_REF(358, self, self_Refman)
    LUMI_err = lumi_M_Lumi_concat_first_file_name(self, self_Refman, &(self->command), self_Refman, self->output, self->output_Refman);
    CHECK(358)
    CHECK_REF(359, self, self_Refman)
    if (self->execute_arguments != NULL && self->execute_arguments_Refman->value != NULL) {
        CHECK_REF(360, self, self_Refman)
        INIT_STRING_CONST(360, aux_String_0, " ");
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_0, aux_String_0_Refman);
        CHECK(360)
        CHECK_REF(361, self, self_Refman)
        CHECK_REF(361, self, self_Refman)
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->execute_arguments, self->execute_arguments_Refman);
        CHECK(361)
    }
    LUMI_err = lumi_M_Lumi_run_command(self, self_Refman, NULL, NULL);
    CHECK(362)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_0_Refman);
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.run"
Returncode lumi_M_Lumi_run(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(self_Refman);
    LUMI_err = lumi_M_Lumi_read_input(self, self_Refman);
    CHECK(365)
    CHECK_REF(366, self, self_Refman)
    if (self->running_lumi) {
        LUMI_err = lumi_M_Lumi_run_lumi(self, self_Refman);
        CHECK(367)
    }
    CHECK_REF(368, self, self_Refman)
    if (self->running_c) {
        LUMI_err = lumi_M_Lumi_run_c(self, self_Refman);
        CHECK(369)
    }
    CHECK_REF(370, self, self_Refman)
    if (self->running_program) {
        LUMI_err = lumi_M_Lumi_run_program(self, self_Refman);
        CHECK(371)
    }
LUMI_cleanup:
    LUMI_dec_ref(self_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void lumi_M_Lumi_Del(lumi_M_Lumi* self) {
    if (self == NULL) return;
    lumi_M_IncrementalString_Del(&(self->lumi_path));
    lumi_M_IncrementalString_Del(&(self->command));
    lumi_M_IncrementalString_Del(&(self->external_files));
    lumi_M_IncrementalString_Del(&(self->input_files));
    LUMI_dec_ref(self->main_input_Refman);
    LUMI_dec_ref(self->execute_arguments_Refman);
    LUMI_dec_ref(self->lib_module_Refman);
    LUMI_dec_ref(self->ut_module_Refman);
    LUMI_dec_ref(self->output_Refman);
    String_Del(self->implicit_output);
    LUMI_owner_dec_ref(self->implicit_output_Refman);
}


/* global functions body */

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "error-if"
Returncode lumi_M_error_if(Bool is_error, String* error_msg, Ref_Manager* error_msg_Refman) {
    Returncode LUMI_err = OK;
    LUMI_inc_ref(error_msg_Refman);
    if (is_error) {
        LUMI_err = Sys_println(sys, sys_Refman, error_msg, error_msg_Refman);
        CHECK(37)
        LUMI_err = Sys_exit(sys, sys_Refman, 1);
        CHECK(38)
    }
LUMI_cleanup:
    LUMI_dec_ref(error_msg_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "help"
Returncode lumi_M_help(void) {
    Returncode LUMI_err = OK;
    String aux_String_0_Var = {0};
    String* aux_String_0 = NULL;
    Ref_Manager* aux_String_0_Refman = NULL;
    INIT_STRING_CONST(56, aux_String_0, "Usage: lumi [options] file...\nOptions:\n  -h/--help        print this help\n  --version        print lumi command version\n  -o <file>        output file name\n  -t <module>      compile test program for <module>\n  -l <module>      compile shared library exporting <module>\n  -c               only create C file(s)\n  -TL<version>     only run C compiler for TL<version>\n  -e <argument>    extra argument for C compilation\n  -p <lumipath>    path of lumi-lang repository\n  -r               run the compiled program\n  -ra <arguments>  run the compiled program with given arguments\n  -v/--verbose     print executed commands\n  -d/--debug       only print commands without execution");
    LUMI_err = Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(42)
    LUMI_err = Sys_exit(sys, sys_Refman, 0);
    CHECK(57)
LUMI_cleanup:
    LUMI_var_dec_ref(aux_String_0_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME


Returncode new_Mock(Bool* allocate_success) { return OK; }

Returncode delete_Mock(Ref self) { return OK; }

/* main function */

USER_MAIN_HEADER {
    Returncode LUMI_err = OK;
    lumi_M_Lumi lumi_object_Var = {0};
    lumi_M_Lumi* lumi_object = NULL;
    Ref_Manager* lumi_object_Refman = NULL;

#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "main"
    INIT_VAR(409, lumi_object)
    LUMI_err = lumi_M_Lumi_new(lumi_object, lumi_object_Refman);
    CHECK(409)
    LUMI_err = lumi_M_Lumi_run(lumi_object, lumi_object_Refman);
    CHECK(410)
LUMI_cleanup:
    LUMI_var_dec_ref(lumi_object_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

MAIN_FUNC
