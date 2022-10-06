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
    String* mut;
    Ref_Manager* mut_Refman;
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
    INIT_NEW(348, aux_String_0, LUMI_new_string(64));
    aux_String_1 = aux_String_0;
    aux_String_1_Refman = aux_String_0_Refman;
    aux_String_0 = NULL;
    aux_String_0_Refman = NULL;
    CHECK_REF(348, self, self_Refman)
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
    CHECK_REF(351, self, self_Refman)
    LUMI_err = String_clear(self->text, self->text_Refman);
    CHECK(351)
    LUMI_err = lumi_M_IncrementalString_concat(self, self_Refman, text, text_Refman);
    CHECK(352)
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
            CHECK_REF(357, self, self_Refman)
            LUMI_err = String_concat(self->text, self->text_Refman, text, text_Refman);
            CHECK(357)

#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
        } while (false);
        --LUMI_trace_ignore_count;
        if (LUMI_err != OK) {
            LUMI_err = OK;
            LUMI_err = lumi_M_IncrementalString_realloc(self, self_Refman);
            CHECK(359)
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
    INIT_VAR(364, text)
    text_Var.values = text_Values;
    LUMI_err = String_append(text, text_Refman, ch);
    CHECK(365)
    LUMI_err = lumi_M_IncrementalString_concat(self, self_Refman, text, text_Refman);
    CHECK(366)
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
        CHECK_REF(370, self, self_Refman)
        LUMI_err = Sys_getenv(sys, sys_Refman, name, name_Refman, self->text, self->text_Refman, &(*exists));
        CHECK(370)
        if (!(*exists)) break;
        CHECK_REF(371, self, self_Refman)
        CHECK_REF(371, self->text, self->text_Refman)
        CHECK_REF(371, self, self_Refman)
        CHECK_REF(371, self->text, self->text_Refman)
        if (!(self->text->length == self->text->max_length)) break;
        LUMI_err = lumi_M_IncrementalString_realloc(self, self_Refman);
        CHECK(372)
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
    CHECK_REF(375, self, self_Refman)
    CHECK_REF(375, self, self_Refman)
    CHECK_REF(375, self->text, self->text_Refman)
    INIT_NEW(375, aux_String_0, LUMI_new_string(self->text->max_length * 2));
    LUMI_err = String_new(aux_String_0, aux_String_0_Refman, self->text, self->text_Refman);
    CHECK(375)
    aux_String_1 = aux_String_0;
    aux_String_1_Refman = aux_String_0_Refman;
    aux_String_0 = NULL;
    aux_String_0_Refman = NULL;
    CHECK_REF(375, self, self_Refman)
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
    CHECK_REF(76, self, self_Refman)
    self->running_lumi = true;
    CHECK_REF(77, self, self_Refman)
    self->running_c = true;
    CHECK_REF(78, self, self_Refman)
    self->execute = true;
    CHECK_REF(79, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_new(&(self->input_files), self_Refman);
    CHECK(79)
    CHECK_REF(80, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_new(&(self->external_files), self_Refman);
    CHECK(80)
    CHECK_REF(81, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_new(&(self->command), self_Refman);
    CHECK(81)
    CHECK_REF(82, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_new(&(self->lumi_path), self_Refman);
    CHECK(82)
    CHECK_REF(83, self, self_Refman)
    self->path_separator = '/';
    CHECK_REF(84, self, self_Refman)
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
    CHECK_REF(87, self, self_Refman)
    if (self->verbose) {
        CHECK_REF(88, self, self_Refman)
        LUMI_err = Sys_println(sys, sys_Refman, self->command.text, self->command.text_Refman);
        CHECK(88)
    }
    CHECK_REF(89, self, self_Refman)
    if (self->execute) {
        CHECK_REF(90, self, self_Refman)
        LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, 0);
        CHECK(90)
        CHECK_REF(91, self, self_Refman)
        LUMI_err = Sys_system(sys, sys_Refman, self->command.text, self->command.text_Refman, &(aux_Int_0));
        CHECK(91)
        if (aux_Int_0 != 0) {
            if (error_msg != NULL && error_msg_Refman->value != NULL) {
                LUMI_err = Sys_println(sys, sys_Refman, error_msg, error_msg_Refman);
                CHECK(93)
            }
            LUMI_err = Sys_exit(sys, sys_Refman, 1);
            CHECK(94)
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
    CHECK_REF(99, sys, sys_Refman)
    CHECK_REF(99, sys->argv, sys->argv_Refman)
    LUMI_err = lumi_M_Lumi_check_opt_param_error(self, self_Refman, (*index) >= (sys->argv->length - 1), option, option_Refman, param, param_Refman);
    CHECK(98)
    *index += 1;
    CHECK_REF(101, sys, sys_Refman)
    CHECK_REF(101, sys->argv, sys->argv_Refman)
    if ((*index) < 0 || (*index) >= (sys->argv)->length) RAISE(101, slice_index)
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
    CHECK(105)
    CHECK_REF(106, *value, (*value_Refman))
    if ((0) < 0 || (0) >= ((*value))->length) RAISE(106, slice_index)
    LUMI_err = lumi_M_Lumi_check_opt_param_error(self, self_Refman, ((((*value))->values)[0]) == '-', option, option_Refman, param, param_Refman);
    CHECK(106)
    LUMI_err = lumi_M_Lumi_check_param(self, self_Refman, *value, *value_Refman);
    CHECK(107)
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
        INIT_STRING_CONST(112, aux_String_0, "lumi: error: missing ");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
        CHECK(112)
        LUMI_err = Sys_print(sys, sys_Refman, param, param_Refman);
        CHECK(113)
        INIT_STRING_CONST(114, aux_String_1, " after \"-");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
        CHECK(114)
        LUMI_err = Sys_print(sys, sys_Refman, option, option_Refman);
        CHECK(115)
        INIT_STRING_CONST(116, aux_String_2, "\" flag");
        LUMI_err = Sys_println(sys, sys_Refman, aux_String_2, aux_String_2_Refman);
        CHECK(116)
        LUMI_err = Sys_exit(sys, sys_Refman, 1);
        CHECK(117)
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
    CHECK(120)
    if (aux_Bool_0) {
        INIT_STRING_CONST(121, aux_String_0, "lumi: error: illegal \" character in parameter '");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
        CHECK(121)
        LUMI_err = Sys_print(sys, sys_Refman, value, value_Refman);
        CHECK(122)
        INIT_STRING_CONST(123, aux_String_1, "'");
        LUMI_err = Sys_println(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
        CHECK(123)
        LUMI_err = Sys_exit(sys, sys_Refman, 1);
        CHECK(124)
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
    CHECK_REF(127, self, self_Refman)
    INIT_STRING_CONST(127, aux_String_0, " \"");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(127)
    CHECK_REF(128, self, self_Refman)
    CHECK_REF(128, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->output, self->output_Refman);
    CHECK(128)
    CHECK_REF(129, self, self_Refman)
    CHECK_REF(129, self, self_Refman)
    if (self->running_c || (! self->explicit_output)) {
        CHECK_REF(130, self, self_Refman)
        INIT_STRING_CONST(130, aux_String_1, ".c");
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_1, aux_String_1_Refman);
        CHECK(130)
    }
    CHECK_REF(131, self, self_Refman)
    INIT_STRING_CONST(131, aux_String_2, "\"");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_2, aux_String_2_Refman);
    CHECK(131)
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
    INIT_STRING_CONST(134, aux_String_0, "\"");
    LUMI_err = lumi_M_IncrementalString_concat(target, target_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(134)
    LUMI_err = lumi_M_IncrementalString_concat(target, target_Refman, name, name_Refman);
    CHECK(135)
    INIT_STRING_CONST(136, aux_String_1, "\"");
    LUMI_err = lumi_M_IncrementalString_concat(target, target_Refman, aux_String_1, aux_String_1_Refman);
    CHECK(136)
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
    INIT_STRING_CONST(139, aux_String_0, " ");
    LUMI_err = lumi_M_IncrementalString_concat(target, target_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(139)
    LUMI_err = lumi_M_Lumi_concat_first_file_name(self, self_Refman, target, target_Refman, name, name_Refman);
    CHECK(140)
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
    CHECK_REF(143, self, self_Refman)
    CHECK_REF(143, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->lumi_path.text, self->lumi_path.text_Refman);
    CHECK(143)
    CHECK_REF(144, self, self_Refman)
    if (! self->lumi_path_ends_with_separator) {
        CHECK_REF(145, self, self_Refman)
        CHECK_REF(145, self, self_Refman)
        LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->path_separator);
        CHECK(145)
    }
    CHECK_REF(146, self, self_Refman)
    INIT_STRING_CONST(146, aux_String_0, "TL");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(146)
    CHECK_REF(147, self, self_Refman)
    CHECK_REF(147, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->version);
    CHECK(147)
    CHECK_REF(148, self, self_Refman)
    CHECK_REF(148, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->path_separator);
    CHECK(148)
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
    String* aux_String_8 = NULL;
    Ref_Manager* aux_String_8_Refman = NULL;
    String aux_String_9_Var = {0};
    String* aux_String_9 = NULL;
    Ref_Manager* aux_String_9_Refman = NULL;
    String aux_String_10_Var = {0};
    String* aux_String_10 = NULL;
    Ref_Manager* aux_String_10_Refman = NULL;
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
    Bool aux_Bool_1 = 0;
    String aux_String_15_Var = {0};
    String* aux_String_15 = NULL;
    Ref_Manager* aux_String_15_Refman = NULL;
    Bool aux_Bool_2 = 0;
    String aux_String_16_Var = {0};
    String* aux_String_16 = NULL;
    Ref_Manager* aux_String_16_Refman = NULL;
    Bool aux_Bool_3 = 0;
    String aux_String_17_Var = {0};
    String* aux_String_17 = NULL;
    Ref_Manager* aux_String_17_Refman = NULL;
    String aux_String_18_Var = {0};
    String* aux_String_18 = NULL;
    Ref_Manager* aux_String_18_Refman = NULL;
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
    String* aux_String_29 = NULL;
    Ref_Manager* aux_String_29_Refman = NULL;
    String* aux_String_30 = NULL;
    Ref_Manager* aux_String_30_Refman = NULL;
    Ref_Manager* aux_Ref_Manager = NULL;
    LUMI_inc_ref(self_Refman);
    CHECK_REF(155, sys, sys_Refman)
    CHECK_REF(155, sys->argv, sys->argv_Refman)
    for (index = 1; index < sys->argv->length; ++index) {
        CHECK_REF(156, sys, sys_Refman)
        CHECK_REF(156, sys->argv, sys->argv_Refman)
        if ((index) < 0 || (index) >= (sys->argv)->length) RAISE(156, slice_index)
        arg = ((String*)((sys->argv)->values)) + index;
        arg_Refman = sys->argv_Refman;
        LUMI_inc_ref(arg_Refman);
        CHECK_REF(157, arg, arg_Refman)
        if ((0) < 0 || (0) >= (arg)->length) RAISE(157, slice_index)
        if ((((arg)->values)[0]) == '-') {
            CHECK_REF(158, arg, arg_Refman)
            if (arg->length < 2) {
                INIT_STRING_CONST(159, aux_String_0, "lumi: warning: unknown flag \"-\"");
                LUMI_err = Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
                CHECK(159)
            }
            else {
                    CHECK_REF(161, arg, arg_Refman)
                    if ((1) < 0 || (1) >= (arg)->length) RAISE(161, slice_index)
                    op = ((arg)->values)[1];
                    INIT_STRING_CONST(162, aux_String_1, "--help");
                    LUMI_err = String_equal(arg, arg_Refman, aux_String_1, aux_String_1_Refman, &(aux_Bool_0));
                    CHECK(162)
                    if ((op == 'h') || aux_Bool_0) {
                    LUMI_err = lumi_M_help();
                    CHECK(163)
                }
                    else {
                        if (op == 'o') {
                            INIT_STRING_CONST(165, aux_String_2, "o");
                            INIT_STRING_CONST(165, aux_String_3, "file name");
                            CHECK_REF(166, self, self_Refman)
                            LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_2, aux_String_2_Refman, aux_String_3, aux_String_3_Refman, &(index), &(self->output), &(self->output_Refman));
                            CHECK(165)
                            CHECK_REF(167, self, self_Refman)
                            self->explicit_output = true;
                        }
                        else {
                            if (op == 't') {
                                INIT_STRING_CONST(169, aux_String_4, "t");
                                INIT_STRING_CONST(169, aux_String_5, "module name");
                                CHECK_REF(170, self, self_Refman)
                                LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_4, aux_String_4_Refman, aux_String_5, aux_String_5_Refman, &(index), &(self->mut), &(self->mut_Refman));
                                CHECK(169)
                            }
                            else {
                                if (op == 'e') {
                                    CHECK_REF(173, self, self_Refman)
                                    INIT_STRING_CONST(175, aux_String_6, "e");
                                    INIT_STRING_CONST(175, aux_String_7, "argument");
                                    LUMI_err = lumi_M_Lumi_get_any_opt_param(self, self_Refman, aux_String_6, aux_String_6_Refman, aux_String_7, aux_String_7_Refman, &(index), &(aux_String_8), &(aux_String_8_Refman));
                                    CHECK(172)
                                    LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, &(self->external_files), self_Refman, aux_String_8, aux_String_8_Refman);
                                    CHECK(172)
                                }
                                else {
                                    if (op == 'p') {
                                        CHECK_REF(177, self, self_Refman)
                                        INIT_STRING_CONST(178, aux_String_9, "p");
                                        INIT_STRING_CONST(178, aux_String_10, "path");
                                        LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_9, aux_String_9_Refman, aux_String_10, aux_String_10_Refman, &(index), &(aux_String_11), &(aux_String_11_Refman));
                                        CHECK(177)
                                        LUMI_err = lumi_M_IncrementalString_clear(&(self->lumi_path), self_Refman, aux_String_11, aux_String_11_Refman);
                                        CHECK(177)
                                    }
                                    else {
                                        if (op == 'c') {
                                            CHECK_REF(180, self, self_Refman)
                                            self->running_c = false;
                                        }
                                        else {
                                            CHECK_REF(181, arg, arg_Refman)
                                            if ((op == 'l') && (arg->length > 2)) {
                                                CHECK_REF(182, self, self_Refman)
                                                self->running_lumi = false;
                                                CHECK_REF(183, arg, arg_Refman)
                                                if ((2) < 0 || (2) >= (arg)->length) RAISE(183, slice_index)
                                                CHECK_REF(183, self, self_Refman)
                                                self->version = ((arg)->values)[2];
                                            }
                                            else {
                                                if (op == 'r') {
                                                    CHECK_REF(185, self, self_Refman)
                                                    self->running_program = true;
                                                    CHECK_REF(186, arg, arg_Refman)
                                                    if (arg->length > 2) {
                        CHECK_REF(187, arg, arg_Refman)
                        if ((2) < 0 || (2) >= (arg)->length) RAISE(187, slice_index)
                        if ((((arg)->values)[2]) == 'a') {
                            INIT_STRING_CONST(189, aux_String_12, "ra");
                            INIT_STRING_CONST(189, aux_String_13, "arguments");
                            CHECK_REF(190, self, self_Refman)
                            LUMI_err = lumi_M_Lumi_get_any_opt_param(self, self_Refman, aux_String_12, aux_String_12_Refman, aux_String_13, aux_String_13_Refman, &(index), &(self->execute_arguments), &(self->execute_arguments_Refman));
                            CHECK(188)
                        }
                    }
                                                }
                                                else {
                                                    INIT_STRING_CONST(191, aux_String_14, "--verbose");
                                                    LUMI_err = String_equal(arg, arg_Refman, aux_String_14, aux_String_14_Refman, &(aux_Bool_1));
                                                    CHECK(191)
                                                    if ((op == 'v') || aux_Bool_1) {
                                                        CHECK_REF(192, self, self_Refman)
                                                        self->verbose = true;
                                                    }
                                                    else {
                                                        INIT_STRING_CONST(193, aux_String_15, "--debug");
                                                        LUMI_err = String_equal(arg, arg_Refman, aux_String_15, aux_String_15_Refman, &(aux_Bool_2));
                                                        CHECK(193)
                                                        if ((op == 'd') || aux_Bool_2) {
                                                            CHECK_REF(194, self, self_Refman)
                                                            self->verbose = true;
                                                            CHECK_REF(195, self, self_Refman)
                                                            self->execute = false;
                                                        }
                                                        else {
                                                            INIT_STRING_CONST(196, aux_String_16, "--version");
                                                            LUMI_err = String_equal(arg, arg_Refman, aux_String_16, aux_String_16_Refman, &(aux_Bool_3));
                                                            CHECK(196)
                                                            if (aux_Bool_3) {
                                                                INIT_STRING_CONST(197, aux_String_17, "lumi version 5.1.0");
                                                                LUMI_err = Sys_println(sys, sys_Refman, aux_String_17, aux_String_17_Refman);
                                                                CHECK(197)
                                                                LUMI_err = Sys_exit(sys, sys_Refman, 0);
                                                                CHECK(198)
                                                            }
                                                            else {
                                                                INIT_STRING_CONST(200, aux_String_18, "lumi: warning: unknown flag \"");
                                                                LUMI_err = Sys_print(sys, sys_Refman, aux_String_18, aux_String_18_Refman);
                                                                CHECK(200)
                                                                LUMI_err = Sys_print(sys, sys_Refman, arg, arg_Refman);
                                                                CHECK(201)
                                                                INIT_STRING_CONST(202, aux_String_19, "\"");
                                                                LUMI_err = Sys_println(sys, sys_Refman, aux_String_19, aux_String_19_Refman);
                                                                CHECK(202)
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
                CHECK(204)
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
                CHECK_REF(208, self, self_Refman)
                LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, &(self->input_files), self_Refman, arg, arg_Refman);
                CHECK(208)
                input_files_num += 1;
            }
    }
    INIT_STRING_CONST(211, aux_String_20, "lumi: error: no input files");
    LUMI_err = lumi_M_error_if(input_files_num == 0, aux_String_20, aux_String_20_Refman);
    CHECK(211)
    CHECK_REF(213, self, self_Refman)
    CHECK_REF(213, self, self_Refman)
    INIT_STRING_CONST(215, aux_String_21, "lumi: error: cannot run program when C compilation is turned off by \"-c\" flag");
    LUMI_err = lumi_M_error_if(self->running_program && (! self->running_c), aux_String_21, aux_String_21_Refman);
    CHECK(212)
    CHECK_REF(217, self, self_Refman)
    if (self->running_lumi) {
        CHECK_REF(218, first_input, first_input_Refman)
        legal_name = first_input->length >= 6;
        if (legal_name) {
            CHECK_REF(220, first_input, first_input_Refman)
            CHECK_REF(220, first_input, first_input_Refman)
            if ((first_input->length - 4) < 0 || (first_input->length - 4) >= (first_input)->length) RAISE(220, slice_index)
            CHECK_REF(220, self, self_Refman)
            self->version = ((first_input)->values)[first_input->length - 4];
            CHECK_REF(227, self, self_Refman)
            CHECK_REF(226, self, self_Refman)
            CHECK_REF(225, first_input, first_input_Refman)
            CHECK_REF(225, first_input, first_input_Refman)
            if ((first_input->length - 1) < 0 || (first_input->length - 1) >= (first_input)->length) RAISE(225, slice_index)
            CHECK_REF(224, first_input, first_input_Refman)
            CHECK_REF(224, first_input, first_input_Refman)
            if ((first_input->length - 2) < 0 || (first_input->length - 2) >= (first_input)->length) RAISE(224, slice_index)
            CHECK_REF(223, first_input, first_input_Refman)
            CHECK_REF(223, first_input, first_input_Refman)
            if ((first_input->length - 3) < 0 || (first_input->length - 3) >= (first_input)->length) RAISE(223, slice_index)
            CHECK_REF(222, first_input, first_input_Refman)
            CHECK_REF(222, first_input, first_input_Refman)
            if ((first_input->length - 5) < 0 || (first_input->length - 5) >= (first_input)->length) RAISE(222, slice_index)
            legal_name = ((((((((first_input)->values)[first_input->length - 5]) == '.') && ((((first_input)->values)[first_input->length - 3]) == '.')) && ((((first_input)->values)[first_input->length - 2]) == 'l')) && ((((first_input)->values)[first_input->length - 1]) == 'm')) && (self->version >= '0')) && (self->version <= '9');
        }
        if (! legal_name) {
            INIT_STRING_CONST(229, aux_String_22, "lumi: error: Illegal input Lumi file name \"");
            LUMI_err = Sys_print(sys, sys_Refman, aux_String_22, aux_String_22_Refman);
            CHECK(229)
            LUMI_err = Sys_print(sys, sys_Refman, first_input, first_input_Refman);
            CHECK(230)
            INIT_STRING_CONST(231, aux_String_23, "\", expected [name].[version digit].lm");
            LUMI_err = Sys_println(sys, sys_Refman, aux_String_23, aux_String_23_Refman);
            CHECK(231)
            LUMI_err = Sys_exit(sys, sys_Refman, 1);
            CHECK(232)
        }
    }
    CHECK_REF(234, self, self_Refman)
    CHECK_REF(234, self, self_Refman)
    if ((self->version < '0') || (self->version > '5')) {
        INIT_STRING_CONST(235, aux_String_24, "lumi: error: unsupported version TL");
        LUMI_err = Sys_print(sys, sys_Refman, aux_String_24, aux_String_24_Refman);
        CHECK(235)
        INIT_VAR(236, version_string)
        version_string_Var.values = version_string_Values;
        CHECK_REF(237, self, self_Refman)
        LUMI_err = String_append(version_string, version_string_Refman, self->version);
        CHECK(237)
        LUMI_err = Sys_println(sys, sys_Refman, version_string, version_string_Refman);
        CHECK(238)
        LUMI_err = Sys_exit(sys, sys_Refman, 1);
        CHECK(239)
    }
    CHECK_REF(241, self, self_Refman)
    INIT_STRING_CONST(242, aux_String_25, "lumi: error: multiple files not supported before TL2");
    LUMI_err = lumi_M_error_if((self->version < '2') && (input_files_num > 1), aux_String_25, aux_String_25_Refman);
    CHECK(240)
    CHECK_REF(245, self, self_Refman)
    CHECK_REF(245, self, self_Refman)
    CHECK_REF(244, self, self_Refman)
    CHECK_REF(244, self, self_Refman)
    INIT_STRING_CONST(246, aux_String_26, "lumi: error: cannot specify C output file in TL2 & TL3");
    LUMI_err = lumi_M_error_if((((self->version >= '2') && (self->version <= '3')) && self->explicit_output) && (! self->running_c), aux_String_26, aux_String_26_Refman);
    CHECK(243)
    CHECK_REF(248, self, self_Refman)
    CHECK_REF(248, self, self_Refman)
    INIT_STRING_CONST(249, aux_String_27, "lumi: error: testing not supported before TL4");
    LUMI_err = lumi_M_error_if((self->version < '4') && (self->mut != NULL && self->mut_Refman->value != NULL), aux_String_27, aux_String_27_Refman);
    CHECK(247)
    CHECK_REF(250, self, self_Refman)
    if (self->version <= '2') {
        CHECK_REF(251, self, self_Refman)
        aux_Ref_Manager = self->main_input_Refman;
        self->main_input_Refman = last_input_Refman;
        LUMI_inc_ref(self->main_input_Refman);
        LUMI_dec_ref(aux_Ref_Manager);
        aux_Ref_Manager = NULL;
        self->main_input = last_input;
    }
    else {
            CHECK_REF(253, self, self_Refman)
            aux_Ref_Manager = self->main_input_Refman;
            self->main_input_Refman = first_input_Refman;
            LUMI_inc_ref(self->main_input_Refman);
            LUMI_dec_ref(aux_Ref_Manager);
            aux_Ref_Manager = NULL;
            self->main_input = first_input;
        }
    CHECK_REF(255, self, self_Refman)
    if (! (self->output != NULL && self->output_Refman->value != NULL)) {
        suffix_length = 2;
        CHECK_REF(257, self, self_Refman)
        if (self->running_lumi) {
            suffix_length = 5;
        }
        CHECK_REF(260, self, self_Refman)
        CHECK_REF(260, self, self_Refman)
        CHECK_REF(260, self->main_input, self->main_input_Refman)
        INIT_VAR(260, aux_String_28)
        aux_String_28_Var.length = self->main_input->length - suffix_length;
        aux_String_28_Var.max_length = aux_String_28_Var.length + 1;
        aux_String_28_Var.values = (self->main_input)->values + (0);
        CHECK_REF(260, self->main_input, self->main_input_Refman)
        if ((0) < 0 || (self->main_input->length - suffix_length) < 0 || (0) + (self->main_input->length - suffix_length) > (self->main_input)->length) RAISE(260, slice_index)
        CHECK_REF(259, self, self_Refman)
        CHECK_REF(259, self->main_input, self->main_input_Refman)
        INIT_NEW(259, aux_String_29, LUMI_new_string(self->main_input->length));
        LUMI_err = String_new(aux_String_29, aux_String_29_Refman, aux_String_28, self->main_input_Refman);
        CHECK(259)
        aux_String_30 = aux_String_29;
        aux_String_30_Refman = aux_String_29_Refman;
        aux_String_29 = NULL;
        aux_String_29_Refman = NULL;
        CHECK_REF(259, self, self_Refman)
        String_Del(self->implicit_output);
        LUMI_owner_dec_ref(self->implicit_output_Refman);
        self->implicit_output_Refman = aux_String_30_Refman;
        self->implicit_output = aux_String_30;
        aux_String_30 = NULL;
        aux_String_30_Refman = NULL;
        CHECK_REF(262, self, self_Refman)
        CHECK_REF(262, self, self_Refman)
        aux_Ref_Manager = self->output_Refman;
        self->output_Refman = self->implicit_output_Refman;
        LUMI_inc_ref(self->output_Refman);
        LUMI_dec_ref(aux_Ref_Manager);
        aux_Ref_Manager = NULL;
        self->output = self->implicit_output;
    }
LUMI_cleanup:
    String_Del(aux_String_30);
    LUMI_owner_dec_ref(aux_String_30_Refman);
    String_Del(aux_String_29);
    LUMI_owner_dec_ref(aux_String_29_Refman);
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
    LUMI_var_dec_ref(aux_String_13_Refman);
    LUMI_var_dec_ref(aux_String_12_Refman);
    LUMI_dec_ref(aux_String_11_Refman);
    LUMI_var_dec_ref(aux_String_10_Refman);
    LUMI_var_dec_ref(aux_String_9_Refman);
    LUMI_dec_ref(aux_String_8_Refman);
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
    LUMI_inc_ref(self_Refman);
    CHECK_REF(266, self, self_Refman)
    INIT_STRING_CONST(266, aux_String_0, "tl");
    LUMI_err = lumi_M_IncrementalString_clear(&(self->command), self_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(266)
    CHECK_REF(267, self, self_Refman)
    CHECK_REF(267, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->version);
    CHECK(267)
    CHECK_REF(268, self, self_Refman)
    INIT_STRING_CONST(268, aux_String_1, "-compiler");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_1, aux_String_1_Refman);
    CHECK(268)
    CHECK_REF(269, self, self_Refman)
    if (self->version >= '4') {
        CHECK_REF(270, self, self_Refman)
        if (self->mut != NULL && self->mut_Refman->value != NULL) {
            CHECK_REF(271, self, self_Refman)
            INIT_STRING_CONST(271, aux_String_2, " -t");
            LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_2, aux_String_2_Refman);
            CHECK(271)
            CHECK_REF(272, self, self_Refman)
            CHECK_REF(272, self, self_Refman)
            LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, &(self->command), self_Refman, self->mut, self->mut_Refman);
            CHECK(272)
        }
        LUMI_err = lumi_M_Lumi_concat_lumi_output(self, self_Refman);
        CHECK(273)
    }
    CHECK_REF(274, self, self_Refman)
    CHECK_REF(274, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->input_files.text, self->input_files.text_Refman);
    CHECK(274)
    CHECK_REF(275, self, self_Refman)
    if (self->version <= '1') {
        LUMI_err = lumi_M_Lumi_concat_lumi_output(self, self_Refman);
        CHECK(276)
    }
    INIT_STRING_CONST(277, aux_String_3, "Lumi compiler failed");
    LUMI_err = lumi_M_Lumi_run_command(self, self_Refman, aux_String_3, aux_String_3_Refman);
    CHECK(277)
LUMI_cleanup:
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
    LUMI_inc_ref(self_Refman);
    CHECK_REF(280, self, self_Refman)
    INIT_STRING_CONST(280, aux_String_0, "CC");
    LUMI_err = lumi_M_IncrementalString_getenv(&(self->command), self_Refman, aux_String_0, aux_String_0_Refman, &(aux_Bool_0));
    CHECK(280)
    if (! aux_Bool_0) {
        CHECK_REF(281, self, self_Refman)
        INIT_STRING_CONST(281, aux_String_1, "gcc");
        LUMI_err = lumi_M_IncrementalString_clear(&(self->command), self_Refman, aux_String_1, aux_String_1_Refman);
        CHECK(281)
    }
    CHECK_REF(282, self, self_Refman)
    if (self->version < '5') {
        CHECK_REF(283, self, self_Refman)
        CHECK_REF(283, self->lumi_path.text, self->lumi_path.text_Refman)
        if (self->lumi_path.text->length == 0) {
            CHECK_REF(284, self, self_Refman)
            INIT_STRING_CONST(284, aux_String_2, "LUMIPATH");
            LUMI_err = lumi_M_IncrementalString_getenv(&(self->lumi_path), self_Refman, aux_String_2, aux_String_2_Refman, &(aux_Bool_1));
            CHECK(284)
        }
        CHECK_REF(285, self, self_Refman)
        CHECK_REF(285, self->lumi_path.text, self->lumi_path.text_Refman)
        if (self->lumi_path.text->length > 0) {
            CHECK_REF(287, self, self_Refman)
            CHECK_REF(287, self, self_Refman)
            CHECK_REF(287, self->lumi_path.text, self->lumi_path.text_Refman)
            CHECK_REF(287, self->lumi_path.text, self->lumi_path.text_Refman)
            if ((self->lumi_path.text->length - 1) < 0 || (self->lumi_path.text->length - 1) >= (self->lumi_path.text)->length) RAISE(287, slice_index)
            last = ((self->lumi_path.text)->values)[self->lumi_path.text->length - 1];
            if (last == '\\') {
                CHECK_REF(290, self, self_Refman)
                self->path_separator = '\\';
            }
            CHECK_REF(291, self, self_Refman)
            CHECK_REF(291, self, self_Refman)
            self->lumi_path_ends_with_separator = last == self->path_separator;
        }
    }
    CHECK_REF(292, self, self_Refman)
    INIT_STRING_CONST(292, aux_String_3, " -g");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_3, aux_String_3_Refman);
    CHECK(292)
    CHECK_REF(293, self, self_Refman)
    if (self->running_lumi) {
        CHECK_REF(295, self, self_Refman)
        CHECK_REF(294, self, self_Refman)
        CHECK_REF(294, self, self_Refman)
        if (((self->version >= '2') && (self->version <= '3')) && self->explicit_output) {
            CHECK_REF(296, self, self_Refman)
            INIT_STRING_CONST(296, aux_String_4, " \"");
            LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_4, aux_String_4_Refman);
            CHECK(296)
            CHECK_REF(297, self, self_Refman)
            CHECK_REF(298, self, self_Refman)
            CHECK_REF(298, self, self_Refman)
            CHECK_REF(298, self->main_input, self->main_input_Refman)
            INIT_VAR(298, aux_String_5)
            aux_String_5_Var.length = self->main_input->length - 5;
            aux_String_5_Var.max_length = aux_String_5_Var.length + 1;
            aux_String_5_Var.values = (self->main_input)->values + (0);
            CHECK_REF(298, self->main_input, self->main_input_Refman)
            if ((0) < 0 || (self->main_input->length - 5) < 0 || (0) + (self->main_input->length - 5) > (self->main_input)->length) RAISE(298, slice_index)
            LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_5, self->main_input_Refman);
            CHECK(297)
            CHECK_REF(299, self, self_Refman)
            INIT_STRING_CONST(299, aux_String_6, ".c\"");
            LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_6, aux_String_6_Refman);
            CHECK(299)
        }
        else {
                LUMI_err = lumi_M_Lumi_concat_lumi_output(self, self_Refman);
                CHECK(301)
            }
    }
    else {
            CHECK_REF(303, self, self_Refman)
            CHECK_REF(303, self, self_Refman)
            LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->input_files.text, self->input_files.text_Refman);
            CHECK(303)
        }
    CHECK_REF(304, self, self_Refman)
    CHECK_REF(304, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->external_files.text, self->external_files.text_Refman);
    CHECK(304)
    CHECK_REF(305, self, self_Refman)
    INIT_STRING_CONST(305, aux_String_7, " ");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_7, aux_String_7_Refman);
    CHECK(305)
    CHECK_REF(306, self, self_Refman)
    if (self->version < '5') {
        LUMI_err = lumi_M_Lumi_concat_tl_path(self, self_Refman);
        CHECK(307)
        CHECK_REF(308, self, self_Refman)
        if (self->version == '0') {
            CHECK_REF(309, self, self_Refman)
            INIT_STRING_CONST(309, aux_String_8, "tl0-file.c ");
            LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_8, aux_String_8_Refman);
            CHECK(309)
            LUMI_err = lumi_M_Lumi_concat_tl_path(self, self_Refman);
            CHECK(310)
            CHECK_REF(311, self, self_Refman)
            INIT_STRING_CONST(311, aux_String_9, "tl0-string.c");
            LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_9, aux_String_9_Refman);
            CHECK(311)
        }
        else {
                CHECK_REF(313, self, self_Refman)
                INIT_STRING_CONST(313, aux_String_10, "lumi.");
                LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_10, aux_String_10_Refman);
                CHECK(313)
                CHECK_REF(314, self, self_Refman)
                CHECK_REF(314, self, self_Refman)
                LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->version);
                CHECK(314)
                CHECK_REF(315, self, self_Refman)
                INIT_STRING_CONST(315, aux_String_11, ".c");
                LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_11, aux_String_11_Refman);
                CHECK(315)
            }
        CHECK_REF(316, self, self_Refman)
        INIT_STRING_CONST(316, aux_String_12, " -I");
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_12, aux_String_12_Refman);
        CHECK(316)
        LUMI_err = lumi_M_Lumi_concat_tl_path(self, self_Refman);
        CHECK(317)
        CHECK_REF(318, self, self_Refman)
        LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, ' ');
        CHECK(318)
    }
    CHECK_REF(319, self, self_Refman)
    INIT_STRING_CONST(319, aux_String_13, "-o");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_13, aux_String_13_Refman);
    CHECK(319)
    CHECK_REF(320, self, self_Refman)
    CHECK_REF(320, self, self_Refman)
    LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, &(self->command), self_Refman, self->output, self->output_Refman);
    CHECK(320)
    INIT_STRING_CONST(321, aux_String_14, "C compiler failed");
    LUMI_err = lumi_M_Lumi_run_command(self, self_Refman, aux_String_14, aux_String_14_Refman);
    CHECK(321)
LUMI_cleanup:
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
    CHECK_REF(324, self, self_Refman)
    LUMI_err = String_clear(self->command.text, self->command.text_Refman);
    CHECK(324)
    CHECK_REF(325, self, self_Refman)
    CHECK_REF(325, self, self_Refman)
    LUMI_err = String_has(self->output, self->output_Refman, self->path_separator, &(aux_Bool_0));
    CHECK(325)
    if (! aux_Bool_0) {
        CHECK_REF(326, self, self_Refman)
        LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, '.');
        CHECK(326)
        CHECK_REF(327, self, self_Refman)
        CHECK_REF(327, self, self_Refman)
        LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->path_separator);
        CHECK(327)
    }
    CHECK_REF(328, self, self_Refman)
    CHECK_REF(328, self, self_Refman)
    LUMI_err = lumi_M_Lumi_concat_first_file_name(self, self_Refman, &(self->command), self_Refman, self->output, self->output_Refman);
    CHECK(328)
    CHECK_REF(329, self, self_Refman)
    if (self->execute_arguments != NULL && self->execute_arguments_Refman->value != NULL) {
        CHECK_REF(330, self, self_Refman)
        INIT_STRING_CONST(330, aux_String_0, " ");
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_0, aux_String_0_Refman);
        CHECK(330)
        CHECK_REF(331, self, self_Refman)
        CHECK_REF(331, self, self_Refman)
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->execute_arguments, self->execute_arguments_Refman);
        CHECK(331)
    }
    LUMI_err = lumi_M_Lumi_run_command(self, self_Refman, NULL, NULL);
    CHECK(332)
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
    CHECK(335)
    CHECK_REF(336, self, self_Refman)
    if (self->running_lumi) {
        LUMI_err = lumi_M_Lumi_run_lumi(self, self_Refman);
        CHECK(337)
    }
    CHECK_REF(338, self, self_Refman)
    if (self->running_c) {
        LUMI_err = lumi_M_Lumi_run_c(self, self_Refman);
        CHECK(339)
    }
    CHECK_REF(340, self, self_Refman)
    if (self->running_program) {
        LUMI_err = lumi_M_Lumi_run_program(self, self_Refman);
        CHECK(341)
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
    LUMI_dec_ref(self->mut_Refman);
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
        CHECK(33)
        LUMI_err = Sys_exit(sys, sys_Refman, 1);
        CHECK(34)
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
    INIT_STRING_CONST(51, aux_String_0, "Usage: lumi [options] file...\nOptions:\n  -h/--help        print this help\n  --version        print lumi command version\n  -o <file>        output file name\n  -t <module>      compile test program for <module>\n  -c               only create C file(s)\n  -l<version>      only run C compiler for TL<version>\n  -e <argument>    extra argument for C compilation\n  -p <lumipath>    path of lumi-lang repository\n  -r               run the compiled program\n  -ra <arguments>  run the compiled program with given arguments\n  -v/--verbose     print executed commands\n  -d/--debug       only print commands without execution");
    LUMI_err = Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(38)
    LUMI_err = Sys_exit(sys, sys_Refman, 0);
    CHECK(52)
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
    INIT_VAR(379, lumi_object)
    LUMI_err = lumi_M_Lumi_new(lumi_object, lumi_object_Refman);
    CHECK(379)
    LUMI_err = lumi_M_Lumi_run(lumi_object, lumi_object_Refman);
    CHECK(380)
LUMI_cleanup:
    LUMI_var_dec_ref(lumi_object_Refman);
    return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

MAIN_FUNC
