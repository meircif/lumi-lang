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

String* lumi_M_usage = NULL;
Ref_Manager* lumi_M_usage_Refman = NULL;


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
  INIT_NEW(329, aux_String_0, LUMI_new_string(64));
  aux_String_1 = aux_String_0;
  aux_String_1_Refman = aux_String_0_Refman;
  aux_String_0 = NULL;
  aux_String_0_Refman = NULL;
  CHECK_REF(329, self, self_Refman)
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
  CHECK_REF(332, self, self_Refman)
  LUMI_err = String_clear(self->text, self->text_Refman);
  CHECK(332)
  LUMI_err = lumi_M_IncrementalString_concat(self, self_Refman, text, text_Refman);
  CHECK(333)
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
      CHECK_REF(338, self, self_Refman)
      LUMI_err = String_concat(self->text, self->text_Refman, text, text_Refman);
      CHECK(338)

#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
    } while (false);
    --LUMI_trace_ignore_count;
    if (LUMI_err != OK) {
      LUMI_err = OK;
      LUMI_err = lumi_M_IncrementalString_realloc(self, self_Refman);
      CHECK(340)
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
  INIT_VAR(345, text)
  text_Var.values = text_Values;
  LUMI_err = String_append(text, text_Refman, ch);
  CHECK(346)
  LUMI_err = lumi_M_IncrementalString_concat(self, self_Refman, text, text_Refman);
  CHECK(347)
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
    CHECK_REF(351, self, self_Refman)
    LUMI_err = Sys_getenv(sys, sys_Refman, name, name_Refman, self->text, self->text_Refman, &(*exists));
    CHECK(351)
    if (!(*exists)) break;
    CHECK_REF(352, self, self_Refman)
    CHECK_REF(352, self->text, self->text_Refman)
    CHECK_REF(352, self, self_Refman)
    CHECK_REF(352, self->text, self->text_Refman)
    if (!(self->text->length == self->text->max_length)) break;
    LUMI_err = lumi_M_IncrementalString_realloc(self, self_Refman);
    CHECK(353)
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
  CHECK_REF(356, self, self_Refman)
  CHECK_REF(356, self, self_Refman)
  CHECK_REF(356, self->text, self->text_Refman)
  INIT_NEW(356, aux_String_0, LUMI_new_string(self->text->max_length * 2));
  LUMI_err = String_new(aux_String_0, aux_String_0_Refman, self->text, self->text_Refman);
  CHECK(356)
  aux_String_1 = aux_String_0;
  aux_String_1_Refman = aux_String_0_Refman;
  aux_String_0 = NULL;
  aux_String_0_Refman = NULL;
  CHECK_REF(356, self, self_Refman)
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
    INIT_STRING_CONST(112, aux_String_0, "error: missing ");
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
    INIT_STRING_CONST(121, aux_String_0, "error: illegal \" character in parameter '");
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
  String* aux_String_23 = NULL;
  Ref_Manager* aux_String_23_Refman = NULL;
  String* aux_String_24 = NULL;
  Ref_Manager* aux_String_24_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(self_Refman);
  CHECK_REF(151, sys, sys_Refman)
  CHECK_REF(151, sys->argv, sys->argv_Refman)
  LUMI_err = lumi_M_error_if(sys->argv->length < 2, lumi_M_usage, lumi_M_usage_Refman);
  CHECK(151)
  CHECK_REF(156, sys, sys_Refman)
  CHECK_REF(156, sys->argv, sys->argv_Refman)
  for (index = 1; index < sys->argv->length; ++index) {
    CHECK_REF(157, sys, sys_Refman)
    CHECK_REF(157, sys->argv, sys->argv_Refman)
    if ((index) < 0 || (index) >= (sys->argv)->length) RAISE(157, slice_index)
    arg = ((String*)((sys->argv)->values)) + index;
    arg_Refman = sys->argv_Refman;
    LUMI_inc_ref(arg_Refman);
    CHECK_REF(158, arg, arg_Refman)
    if ((0) < 0 || (0) >= (arg)->length) RAISE(158, slice_index)
    if ((((arg)->values)[0]) == '-') {
      CHECK_REF(159, arg, arg_Refman)
      if (arg->length < 2) {
        INIT_STRING_CONST(160, aux_String_0, "warning: unknown flag \"-\"");
        LUMI_err = Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
        CHECK(160)
      }
      else {
          CHECK_REF(162, arg, arg_Refman)
          if ((1) < 0 || (1) >= (arg)->length) RAISE(162, slice_index)
          op = ((arg)->values)[1];
          if (op == 'h') {
          LUMI_err = lumi_M_help();
          CHECK(164)
        }
          else {
            if (op == 'o') {
              INIT_STRING_CONST(166, aux_String_1, "o");
              INIT_STRING_CONST(166, aux_String_2, "file name");
              CHECK_REF(167, self, self_Refman)
              LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_1, aux_String_1_Refman, aux_String_2, aux_String_2_Refman, &(index), &(self->output), &(self->output_Refman));
              CHECK(166)
              CHECK_REF(168, self, self_Refman)
              self->explicit_output = true;
            }
            else {
              if (op == 't') {
                INIT_STRING_CONST(170, aux_String_3, "t");
                INIT_STRING_CONST(170, aux_String_4, "module name");
                CHECK_REF(171, self, self_Refman)
                LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_3, aux_String_3_Refman, aux_String_4, aux_String_4_Refman, &(index), &(self->mut), &(self->mut_Refman));
                CHECK(170)
              }
              else {
                if (op == 'e') {
                  CHECK_REF(174, self, self_Refman)
                  INIT_STRING_CONST(175, aux_String_5, "e");
                  INIT_STRING_CONST(175, aux_String_6, "file name");
                  LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_5, aux_String_5_Refman, aux_String_6, aux_String_6_Refman, &(index), &(aux_String_7), &(aux_String_7_Refman));
                  CHECK(173)
                  LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, &(self->external_files), self_Refman, aux_String_7, aux_String_7_Refman);
                  CHECK(173)
                }
                else {
                  if (op == 'p') {
                    CHECK_REF(178, self, self_Refman)
                    INIT_STRING_CONST(179, aux_String_8, "p");
                    INIT_STRING_CONST(179, aux_String_9, "path");
                    LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_8, aux_String_8_Refman, aux_String_9, aux_String_9_Refman, &(index), &(aux_String_10), &(aux_String_10_Refman));
                    CHECK(178)
                    LUMI_err = lumi_M_IncrementalString_clear(&(self->lumi_path), self_Refman, aux_String_10, aux_String_10_Refman);
                    CHECK(178)
                  }
                  else {
                    if (op == 'c') {
                      CHECK_REF(181, self, self_Refman)
                      self->running_c = false;
                    }
                    else {
                      CHECK_REF(182, arg, arg_Refman)
                      if ((op == 'l') && (arg->length > 2)) {
                        CHECK_REF(183, self, self_Refman)
                        self->running_lumi = false;
                        CHECK_REF(184, arg, arg_Refman)
                        if ((2) < 0 || (2) >= (arg)->length) RAISE(184, slice_index)
                        CHECK_REF(184, self, self_Refman)
                        self->version = ((arg)->values)[2];
                      }
                      else {
                        if (op == 'r') {
                          CHECK_REF(186, self, self_Refman)
                          self->running_program = true;
                          CHECK_REF(187, arg, arg_Refman)
                          if (arg->length > 2) {
            CHECK_REF(188, arg, arg_Refman)
            if ((2) < 0 || (2) >= (arg)->length) RAISE(188, slice_index)
            if ((((arg)->values)[2]) == 'a') {
              INIT_STRING_CONST(189, aux_String_11, "ra");
              INIT_STRING_CONST(189, aux_String_12, "arguments");
              CHECK_REF(190, self, self_Refman)
              LUMI_err = lumi_M_Lumi_get_any_opt_param(self, self_Refman, aux_String_11, aux_String_11_Refman, aux_String_12, aux_String_12_Refman, &(index), &(self->execute_arguments), &(self->execute_arguments_Refman));
              CHECK(189)
            }
          }
                        }
                        else {
                          if (op == 'v') {
                            CHECK_REF(192, self, self_Refman)
                            self->verbose = true;
                          }
                          else {
                            if (op == 'd') {
                              CHECK_REF(194, self, self_Refman)
                              self->verbose = true;
                              CHECK_REF(195, self, self_Refman)
                              self->execute = false;
                            }
                            else {
                              INIT_STRING_CONST(197, aux_String_13, "warning: unknown flag \"");
                              LUMI_err = Sys_print(sys, sys_Refman, aux_String_13, aux_String_13_Refman);
                              CHECK(197)
                              LUMI_err = Sys_print(sys, sys_Refman, arg, arg_Refman);
                              CHECK(198)
                              INIT_STRING_CONST(199, aux_String_14, "\"");
                              LUMI_err = Sys_println(sys, sys_Refman, aux_String_14, aux_String_14_Refman);
                              CHECK(199)
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
        CHECK(201)
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
        CHECK_REF(205, self, self_Refman)
        LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, &(self->input_files), self_Refman, arg, arg_Refman);
        CHECK(205)
        input_files_num += 1;
      }
  }
  INIT_STRING_CONST(208, aux_String_15, "error: no input files");
  LUMI_err = lumi_M_error_if(input_files_num == 0, aux_String_15, aux_String_15_Refman);
  CHECK(208)
  CHECK_REF(210, self, self_Refman)
  CHECK_REF(210, self, self_Refman)
  INIT_STRING_CONST(212, aux_String_16, "error: cannot run program when C compilation is turned off by \"-c\" flag");
  LUMI_err = lumi_M_error_if(self->running_program && (! self->running_c), aux_String_16, aux_String_16_Refman);
  CHECK(209)
  CHECK_REF(214, self, self_Refman)
  if (self->running_lumi) {
    CHECK_REF(216, first_input, first_input_Refman)
    INIT_STRING_CONST(217, aux_String_17, "error: Lumi file name too short");
    LUMI_err = lumi_M_error_if(first_input->length < 6, aux_String_17, aux_String_17_Refman);
    CHECK(215)
    CHECK_REF(218, first_input, first_input_Refman)
    CHECK_REF(218, first_input, first_input_Refman)
    if ((first_input->length - 4) < 0 || (first_input->length - 4) >= (first_input)->length) RAISE(218, slice_index)
    CHECK_REF(218, self, self_Refman)
    self->version = ((first_input)->values)[first_input->length - 4];
  }
  CHECK_REF(219, self, self_Refman)
  CHECK_REF(219, self, self_Refman)
  if ((self->version < '0') || (self->version > '5')) {
    INIT_STRING_CONST(220, aux_String_18, "error: unsupported version TL");
    LUMI_err = Sys_print(sys, sys_Refman, aux_String_18, aux_String_18_Refman);
    CHECK(220)
    INIT_VAR(221, version_string)
    version_string_Var.values = version_string_Values;
    CHECK_REF(222, self, self_Refman)
    LUMI_err = String_append(version_string, version_string_Refman, self->version);
    CHECK(222)
    LUMI_err = Sys_println(sys, sys_Refman, version_string, version_string_Refman);
    CHECK(223)
    LUMI_err = Sys_exit(sys, sys_Refman, 1);
    CHECK(224)
  }
  CHECK_REF(226, self, self_Refman)
  INIT_STRING_CONST(227, aux_String_19, "error: multiple files not supported before TL2");
  LUMI_err = lumi_M_error_if((self->version < '2') && (input_files_num > 1), aux_String_19, aux_String_19_Refman);
  CHECK(225)
  CHECK_REF(230, self, self_Refman)
  CHECK_REF(230, self, self_Refman)
  CHECK_REF(229, self, self_Refman)
  CHECK_REF(229, self, self_Refman)
  INIT_STRING_CONST(231, aux_String_20, "error: cannot specify C output file in TL2 & TL3");
  LUMI_err = lumi_M_error_if((((self->version >= '2') && (self->version <= '3')) && self->explicit_output) && (! self->running_c), aux_String_20, aux_String_20_Refman);
  CHECK(228)
  CHECK_REF(233, self, self_Refman)
  CHECK_REF(233, self, self_Refman)
  INIT_STRING_CONST(234, aux_String_21, "error: testing not supported before TL4");
  LUMI_err = lumi_M_error_if((self->version < '4') && (self->mut != NULL && self->mut_Refman->value != NULL), aux_String_21, aux_String_21_Refman);
  CHECK(232)
  CHECK_REF(235, self, self_Refman)
  if (self->version <= '2') {
    CHECK_REF(236, self, self_Refman)
    aux_Ref_Manager = self->main_input_Refman;
    self->main_input_Refman = last_input_Refman;
    LUMI_inc_ref(self->main_input_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->main_input = last_input;
  }
  else {
      CHECK_REF(238, self, self_Refman)
      aux_Ref_Manager = self->main_input_Refman;
      self->main_input_Refman = first_input_Refman;
      LUMI_inc_ref(self->main_input_Refman);
      LUMI_dec_ref(aux_Ref_Manager);
      aux_Ref_Manager = NULL;
      self->main_input = first_input;
    }
  CHECK_REF(240, self, self_Refman)
  if (! (self->output != NULL && self->output_Refman->value != NULL)) {
    suffix_length = 2;
    CHECK_REF(242, self, self_Refman)
    if (self->running_lumi) {
      suffix_length = 5;
    }
    CHECK_REF(245, self, self_Refman)
    CHECK_REF(245, self, self_Refman)
    CHECK_REF(245, self->main_input, self->main_input_Refman)
    INIT_VAR(245, aux_String_22)
    aux_String_22_Var.length = self->main_input->length - suffix_length;
    aux_String_22_Var.max_length = aux_String_22_Var.length + 1;
    aux_String_22_Var.values = (self->main_input)->values + (0);
    CHECK_REF(245, self->main_input, self->main_input_Refman)
    if ((0) < 0 || (self->main_input->length - suffix_length) < 0 || (0) + (self->main_input->length - suffix_length) > (self->main_input)->length) RAISE(245, slice_index)
    CHECK_REF(244, self, self_Refman)
    CHECK_REF(244, self->main_input, self->main_input_Refman)
    INIT_NEW(244, aux_String_23, LUMI_new_string(self->main_input->length));
    LUMI_err = String_new(aux_String_23, aux_String_23_Refman, aux_String_22, self->main_input_Refman);
    CHECK(244)
    aux_String_24 = aux_String_23;
    aux_String_24_Refman = aux_String_23_Refman;
    aux_String_23 = NULL;
    aux_String_23_Refman = NULL;
    CHECK_REF(244, self, self_Refman)
    String_Del(self->implicit_output);
    LUMI_owner_dec_ref(self->implicit_output_Refman);
    self->implicit_output_Refman = aux_String_24_Refman;
    self->implicit_output = aux_String_24;
    aux_String_24 = NULL;
    aux_String_24_Refman = NULL;
    CHECK_REF(246, self, self_Refman)
    CHECK_REF(246, self, self_Refman)
    aux_Ref_Manager = self->output_Refman;
    self->output_Refman = self->implicit_output_Refman;
    LUMI_inc_ref(self->output_Refman);
    LUMI_dec_ref(aux_Ref_Manager);
    aux_Ref_Manager = NULL;
    self->output = self->implicit_output;
  }
LUMI_cleanup:
  String_Del(aux_String_24);
  LUMI_owner_dec_ref(aux_String_24_Refman);
  String_Del(aux_String_23);
  LUMI_owner_dec_ref(aux_String_23_Refman);
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
  LUMI_var_dec_ref(aux_String_11_Refman);
  LUMI_dec_ref(aux_String_10_Refman);
  LUMI_var_dec_ref(aux_String_9_Refman);
  LUMI_var_dec_ref(aux_String_8_Refman);
  LUMI_dec_ref(aux_String_7_Refman);
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
  CHECK_REF(250, self, self_Refman)
  INIT_STRING_CONST(250, aux_String_0, "tl");
  LUMI_err = lumi_M_IncrementalString_clear(&(self->command), self_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(250)
  CHECK_REF(251, self, self_Refman)
  CHECK_REF(251, self, self_Refman)
  LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->version);
  CHECK(251)
  CHECK_REF(252, self, self_Refman)
  INIT_STRING_CONST(252, aux_String_1, "-compiler");
  LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_1, aux_String_1_Refman);
  CHECK(252)
  CHECK_REF(253, self, self_Refman)
  if (self->version >= '4') {
    CHECK_REF(254, self, self_Refman)
    if (self->mut != NULL && self->mut_Refman->value != NULL) {
      CHECK_REF(255, self, self_Refman)
      INIT_STRING_CONST(255, aux_String_2, " -t");
      LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_2, aux_String_2_Refman);
      CHECK(255)
      CHECK_REF(256, self, self_Refman)
      CHECK_REF(256, self, self_Refman)
      LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, &(self->command), self_Refman, self->mut, self->mut_Refman);
      CHECK(256)
    }
    LUMI_err = lumi_M_Lumi_concat_lumi_output(self, self_Refman);
    CHECK(257)
  }
  CHECK_REF(258, self, self_Refman)
  CHECK_REF(258, self, self_Refman)
  LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->input_files.text, self->input_files.text_Refman);
  CHECK(258)
  CHECK_REF(259, self, self_Refman)
  if (self->version <= '1') {
    LUMI_err = lumi_M_Lumi_concat_lumi_output(self, self_Refman);
    CHECK(260)
  }
  INIT_STRING_CONST(261, aux_String_3, "Lumi compiler failed");
  LUMI_err = lumi_M_Lumi_run_command(self, self_Refman, aux_String_3, aux_String_3_Refman);
  CHECK(261)
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
  CHECK_REF(264, self, self_Refman)
  INIT_STRING_CONST(264, aux_String_0, "CC");
  LUMI_err = lumi_M_IncrementalString_getenv(&(self->command), self_Refman, aux_String_0, aux_String_0_Refman, &(aux_Bool_0));
  CHECK(264)
  if (! aux_Bool_0) {
    CHECK_REF(265, self, self_Refman)
    INIT_STRING_CONST(265, aux_String_1, "gcc");
    LUMI_err = lumi_M_IncrementalString_clear(&(self->command), self_Refman, aux_String_1, aux_String_1_Refman);
    CHECK(265)
  }
  CHECK_REF(266, self, self_Refman)
  if (self->version < '5') {
    CHECK_REF(267, self, self_Refman)
    CHECK_REF(267, self->lumi_path.text, self->lumi_path.text_Refman)
    if (self->lumi_path.text->length == 0) {
      CHECK_REF(268, self, self_Refman)
      INIT_STRING_CONST(268, aux_String_2, "LUMIPATH");
      LUMI_err = lumi_M_IncrementalString_getenv(&(self->lumi_path), self_Refman, aux_String_2, aux_String_2_Refman, &(aux_Bool_1));
      CHECK(268)
    }
    CHECK_REF(269, self, self_Refman)
    CHECK_REF(269, self->lumi_path.text, self->lumi_path.text_Refman)
    if (self->lumi_path.text->length > 0) {
      CHECK_REF(270, self, self_Refman)
      CHECK_REF(270, self, self_Refman)
      CHECK_REF(270, self->lumi_path.text, self->lumi_path.text_Refman)
      CHECK_REF(270, self->lumi_path.text, self->lumi_path.text_Refman)
      if ((self->lumi_path.text->length - 1) < 0 || (self->lumi_path.text->length - 1) >= (self->lumi_path.text)->length) RAISE(270, slice_index)
      last = ((self->lumi_path.text)->values)[self->lumi_path.text->length - 1];
      if (last == '\\') {
        CHECK_REF(272, self, self_Refman)
        self->path_separator = '\\';
      }
      CHECK_REF(273, self, self_Refman)
      CHECK_REF(273, self, self_Refman)
      self->lumi_path_ends_with_separator = last == self->path_separator;
    }
  }
  CHECK_REF(274, self, self_Refman)
  INIT_STRING_CONST(274, aux_String_3, " -g");
  LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_3, aux_String_3_Refman);
  CHECK(274)
  CHECK_REF(275, self, self_Refman)
  if (self->running_lumi) {
    CHECK_REF(276, self, self_Refman)
    CHECK_REF(276, self, self_Refman)
    CHECK_REF(276, self, self_Refman)
    if (((self->version >= '2') && (self->version <= '3')) && self->explicit_output) {
      CHECK_REF(277, self, self_Refman)
      INIT_STRING_CONST(277, aux_String_4, " \"");
      LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_4, aux_String_4_Refman);
      CHECK(277)
      CHECK_REF(278, self, self_Refman)
      CHECK_REF(279, self, self_Refman)
      CHECK_REF(279, self, self_Refman)
      CHECK_REF(279, self->main_input, self->main_input_Refman)
      INIT_VAR(279, aux_String_5)
      aux_String_5_Var.length = self->main_input->length - 5;
      aux_String_5_Var.max_length = aux_String_5_Var.length + 1;
      aux_String_5_Var.values = (self->main_input)->values + (0);
      CHECK_REF(279, self->main_input, self->main_input_Refman)
      if ((0) < 0 || (self->main_input->length - 5) < 0 || (0) + (self->main_input->length - 5) > (self->main_input)->length) RAISE(279, slice_index)
      LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_5, self->main_input_Refman);
      CHECK(278)
      CHECK_REF(280, self, self_Refman)
      INIT_STRING_CONST(280, aux_String_6, ".c\"");
      LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_6, aux_String_6_Refman);
      CHECK(280)
    }
    else {
        LUMI_err = lumi_M_Lumi_concat_lumi_output(self, self_Refman);
        CHECK(282)
      }
  }
  else {
      CHECK_REF(284, self, self_Refman)
      CHECK_REF(284, self, self_Refman)
      LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->input_files.text, self->input_files.text_Refman);
      CHECK(284)
    }
  CHECK_REF(285, self, self_Refman)
  CHECK_REF(285, self, self_Refman)
  LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->external_files.text, self->external_files.text_Refman);
  CHECK(285)
  CHECK_REF(286, self, self_Refman)
  INIT_STRING_CONST(286, aux_String_7, " ");
  LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_7, aux_String_7_Refman);
  CHECK(286)
  CHECK_REF(287, self, self_Refman)
  if (self->version < '5') {
    LUMI_err = lumi_M_Lumi_concat_tl_path(self, self_Refman);
    CHECK(288)
    CHECK_REF(289, self, self_Refman)
    if (self->version == '0') {
      CHECK_REF(290, self, self_Refman)
      INIT_STRING_CONST(290, aux_String_8, "tl0-file.c ");
      LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_8, aux_String_8_Refman);
      CHECK(290)
      LUMI_err = lumi_M_Lumi_concat_tl_path(self, self_Refman);
      CHECK(291)
      CHECK_REF(292, self, self_Refman)
      INIT_STRING_CONST(292, aux_String_9, "tl0-string.c");
      LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_9, aux_String_9_Refman);
      CHECK(292)
    }
    else {
        CHECK_REF(294, self, self_Refman)
        INIT_STRING_CONST(294, aux_String_10, "lumi.");
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_10, aux_String_10_Refman);
        CHECK(294)
        CHECK_REF(295, self, self_Refman)
        CHECK_REF(295, self, self_Refman)
        LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->version);
        CHECK(295)
        CHECK_REF(296, self, self_Refman)
        INIT_STRING_CONST(296, aux_String_11, ".c");
        LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_11, aux_String_11_Refman);
        CHECK(296)
      }
    CHECK_REF(297, self, self_Refman)
    INIT_STRING_CONST(297, aux_String_12, " -I");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_12, aux_String_12_Refman);
    CHECK(297)
    LUMI_err = lumi_M_Lumi_concat_tl_path(self, self_Refman);
    CHECK(298)
    CHECK_REF(299, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, ' ');
    CHECK(299)
  }
  CHECK_REF(300, self, self_Refman)
  INIT_STRING_CONST(300, aux_String_13, "-o");
  LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_13, aux_String_13_Refman);
  CHECK(300)
  CHECK_REF(301, self, self_Refman)
  CHECK_REF(301, self, self_Refman)
  LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, &(self->command), self_Refman, self->output, self->output_Refman);
  CHECK(301)
  INIT_STRING_CONST(302, aux_String_14, "C compiler failed");
  LUMI_err = lumi_M_Lumi_run_command(self, self_Refman, aux_String_14, aux_String_14_Refman);
  CHECK(302)
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
  CHECK_REF(305, self, self_Refman)
  LUMI_err = String_clear(self->command.text, self->command.text_Refman);
  CHECK(305)
  CHECK_REF(306, self, self_Refman)
  CHECK_REF(306, self, self_Refman)
  LUMI_err = String_has(self->output, self->output_Refman, self->path_separator, &(aux_Bool_0));
  CHECK(306)
  if (! aux_Bool_0) {
    CHECK_REF(307, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, '.');
    CHECK(307)
    CHECK_REF(308, self, self_Refman)
    CHECK_REF(308, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_append(&(self->command), self_Refman, self->path_separator);
    CHECK(308)
  }
  CHECK_REF(309, self, self_Refman)
  CHECK_REF(309, self, self_Refman)
  LUMI_err = lumi_M_Lumi_concat_first_file_name(self, self_Refman, &(self->command), self_Refman, self->output, self->output_Refman);
  CHECK(309)
  CHECK_REF(310, self, self_Refman)
  if (self->execute_arguments != NULL && self->execute_arguments_Refman->value != NULL) {
    CHECK_REF(311, self, self_Refman)
    INIT_STRING_CONST(311, aux_String_0, " ");
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, aux_String_0, aux_String_0_Refman);
    CHECK(311)
    CHECK_REF(312, self, self_Refman)
    CHECK_REF(312, self, self_Refman)
    LUMI_err = lumi_M_IncrementalString_concat(&(self->command), self_Refman, self->execute_arguments, self->execute_arguments_Refman);
    CHECK(312)
  }
  LUMI_err = lumi_M_Lumi_run_command(self, self_Refman, NULL, NULL);
  CHECK(313)
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
  CHECK(316)
  CHECK_REF(317, self, self_Refman)
  if (self->running_lumi) {
    LUMI_err = lumi_M_Lumi_run_lumi(self, self_Refman);
    CHECK(318)
  }
  CHECK_REF(319, self, self_Refman)
  if (self->running_c) {
    LUMI_err = lumi_M_Lumi_run_c(self, self_Refman);
    CHECK(320)
  }
  CHECK_REF(321, self, self_Refman)
  if (self->running_program) {
    LUMI_err = lumi_M_Lumi_run_program(self, self_Refman);
    CHECK(322)
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
    CHECK(34)
    LUMI_err = Sys_exit(sys, sys_Refman, 1);
    CHECK(35)
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
  LUMI_err = Sys_println(sys, sys_Refman, lumi_M_usage, lumi_M_usage_Refman);
  CHECK(39)
  INIT_STRING_CONST(51, aux_String_0, "Options:\n  -h \t\t print help\n  -o <file> \t output file name\n  -t <module> \t compile test program for <module>\n  -c \t\t only create C file(s)\n  -l<version> \t only run C compiler for TL<version>\n  -e <file> \t external C file for C compilation\n  -p <lumipath>  path of lumi-lang repository\n  -r \t\t   run the compiled program\n  -ra <arguments>  run the compiled program with given arguments\n  -v \t\t print executed commands\n  -d \t\t only print commands without execution");
  LUMI_err = Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(40)
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
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
#undef RETURN_ERROR
#define RETURN_ERROR return LUMI_err;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
  INIT_STRING_CONST(25, aux_String_0, "Usage: lumi [options] file...");
  lumi_M_usage = aux_String_0;
  lumi_M_usage_Refman = aux_String_0_Refman;
  LUMI_inc_ref(lumi_M_usage_Refman);
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR goto LUMI_cleanup
#define LUMI_FILE_NAME "lumi-command/lumi.4.lm"
#define LUMI_FUNC_NAME "main"
  INIT_VAR(360, lumi_object)
  LUMI_err = lumi_M_Lumi_new(lumi_object, lumi_object_Refman);
  CHECK(360)
  LUMI_err = lumi_M_Lumi_run(lumi_object, lumi_object_Refman);
  CHECK(361)
LUMI_cleanup:
  LUMI_var_dec_ref(lumi_object_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

MAIN_FUNC
