#include "lumi.4.h"


/* types declaration */

typedef struct lumi_M_Input lumi_M_Input;

typedef struct lumi_M_Lumi lumi_M_Lumi;


/* Enums */


/* constants */

enum { lumi_M_MAX_COMMNAD_SIZE = 1024 };


/* types struct */

struct lumi_M_Input {
  String* name;
  Ref_Manager* name_Refman;
};

struct lumi_M_Lumi {
  Bool run_lumi;
  Bool run_c;
  Bool run_program;
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
  String* input_files;
  Ref_Manager* input_files_Refman;
  String* external_files;
  Ref_Manager* external_files_Refman;
  String* command;
  Ref_Manager* command_Refman;
  String* lumi_path;
  Ref_Manager* lumi_path_Refman;
  Char path_separator;
  Bool lumi_path_ends_with_separator;
};


/* types methods declaration */

void lumi_M_Input_Del(lumi_M_Input* self);

Returncode lumi_M_Lumi_new(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_m_run_command(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* error_msg, Ref_Manager* error_msg_Refman);

Returncode lumi_M_Lumi_get_any_opt_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman, Int* index, String** value, Ref_Manager** value_Refman);

Returncode lumi_M_Lumi_get_opt_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman, Int* index, String** value, Ref_Manager** value_Refman);

Returncode lumi_M_Lumi_check_opt_param_error(lumi_M_Lumi* self, Ref_Manager* self_Refman, Bool is_error, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman);

Returncode lumi_M_Lumi_check_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* value, Ref_Manager* value_Refman);

Returncode lumi_M_Lumi_concat_lumi_output(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_concat_first_file_name(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* target, Ref_Manager* target_Refman, String* name, Ref_Manager* name_Refman);

Returncode lumi_M_Lumi_concat_file_name(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* target, Ref_Manager* target_Refman, String* name, Ref_Manager* name_Refman);

Returncode lumi_M_Lumi_concat_tl_path(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_read_input(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_m_run_lumi(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_m_run_c(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_m_run_program(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_m_run(lumi_M_Lumi* self, Ref_Manager* self_Refman);

void lumi_M_Lumi_Del(lumi_M_Lumi* self);


/* global functions declaration */

Returncode lumi_M_f_error_if(Bool is_error, String* error_msg, Ref_Manager* error_msg_Refman);

Returncode lumi_M_f_help(void);


/* types global variables */

Generic_Type_Dynamic lumi_M_Input_dynamic = {(Dynamic_Del)lumi_M_Input_Del};

Generic_Type_Dynamic lumi_M_Lumi_dynamic = {(Dynamic_Del)lumi_M_Lumi_Del};


/* global variables */

String* lumi_M_usage = NULL;
Ref_Manager* lumi_M_usage_Refman = NULL;


/* types methods body */

void lumi_M_Input_Del(lumi_M_Input* self) {
  if (self == NULL) return;
  LUMI_dec_ref(self->name_Refman);
}

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.new"
Returncode lumi_M_Lumi_new(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  String* aux_String_2 = NULL;
  Ref_Manager* aux_String_2_Refman = NULL;
  String* aux_String_3 = NULL;
  Ref_Manager* aux_String_3_Refman = NULL;
  if (self == NULL) RAISE(76, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(76, 38, "used member of outdated weak reference")
  self->run_lumi = true;
  if (self == NULL) RAISE(77, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(77, 38, "used member of outdated weak reference")
  self->run_c = true;
  if (self == NULL) RAISE(78, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(78, 38, "used member of outdated weak reference")
  self->execute = true;
  aux_String_0 = LUMI_new_string(lumi_M_MAX_COMMNAD_SIZE);
  if (aux_String_0 == NULL) RAISE(79, 49, "insufficient memory for object dynamic allocation")
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(79, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(79, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(79, 38, "used member of outdated weak reference")
  String_Del(self->input_files);
  LUMI_owner_dec_ref(self->input_files_Refman);
  self->input_files_Refman = aux_String_0_Refman;
  self->input_files = aux_String_0;
  aux_String_0 = NULL;
  aux_String_0_Refman = NULL;
  aux_String_1 = LUMI_new_string(lumi_M_MAX_COMMNAD_SIZE);
  if (aux_String_1 == NULL) RAISE(80, 49, "insufficient memory for object dynamic allocation")
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(80, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(80, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(80, 38, "used member of outdated weak reference")
  String_Del(self->external_files);
  LUMI_owner_dec_ref(self->external_files_Refman);
  self->external_files_Refman = aux_String_1_Refman;
  self->external_files = aux_String_1;
  aux_String_1 = NULL;
  aux_String_1_Refman = NULL;
  aux_String_2 = LUMI_new_string(lumi_M_MAX_COMMNAD_SIZE);
  if (aux_String_2 == NULL) RAISE(81, 49, "insufficient memory for object dynamic allocation")
  aux_String_2_Refman = LUMI_new_ref(aux_String_2);
  if (aux_String_2_Refman == NULL) RAISE(81, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(81, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(81, 38, "used member of outdated weak reference")
  String_Del(self->command);
  LUMI_owner_dec_ref(self->command_Refman);
  self->command_Refman = aux_String_2_Refman;
  self->command = aux_String_2;
  aux_String_2 = NULL;
  aux_String_2_Refman = NULL;
  aux_String_3 = LUMI_new_string(lumi_M_MAX_COMMNAD_SIZE);
  if (aux_String_3 == NULL) RAISE(82, 49, "insufficient memory for object dynamic allocation")
  aux_String_3_Refman = LUMI_new_ref(aux_String_3);
  if (aux_String_3_Refman == NULL) RAISE(82, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(82, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(82, 38, "used member of outdated weak reference")
  String_Del(self->lumi_path);
  LUMI_owner_dec_ref(self->lumi_path_Refman);
  self->lumi_path_Refman = aux_String_3_Refman;
  self->lumi_path = aux_String_3;
  aux_String_3 = NULL;
  aux_String_3_Refman = NULL;
  if (self == NULL) RAISE(83, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(83, 38, "used member of outdated weak reference")
  self->path_separator = '/';
  if (self == NULL) RAISE(84, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(84, 38, "used member of outdated weak reference")
  self->lumi_path_ends_with_separator = true;
LUMI_cleanup:
  String_Del(aux_String_3);
  LUMI_owner_dec_ref(aux_String_3_Refman);
  String_Del(aux_String_2);
  LUMI_owner_dec_ref(aux_String_2_Refman);
  String_Del(aux_String_1);
  LUMI_owner_dec_ref(aux_String_1_Refman);
  String_Del(aux_String_0);
  LUMI_owner_dec_ref(aux_String_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.m-run-command"
Returncode lumi_M_Lumi_m_run_command(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* error_msg, Ref_Manager* error_msg_Refman) {
  Returncode LUMI_err = OK;
  Int aux_Int_0 = 0;
  LUMI_inc_ref(error_msg_Refman);
  if (self == NULL) RAISE(87, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(87, 38, "used member of outdated weak reference")
  if (self->verbose) {
      if (self == NULL) RAISE(88, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(88, 38, "used member of outdated weak reference")
      CHECK(88, Sys_println(sys, sys_Refman, self->command, self->command_Refman) )
    }
  if (self == NULL) RAISE(89, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(89, 38, "used member of outdated weak reference")
  if (self->execute) {
      if (self == NULL) RAISE(90, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(90, 38, "used member of outdated weak reference")
      CHECK(90, Sys_system(sys, sys_Refman, self->command, self->command_Refman, &(aux_Int_0)) )
      if (aux_Int_0 != 0) {
        if (error_msg != NULL && error_msg_Refman->value != NULL) {
          CHECK(92, Sys_println(sys, sys_Refman, error_msg, error_msg_Refman) )
          USER_RAISE(93, NULL, NULL)
        }
        else {
          CHECK(95, Sys_exit(sys, sys_Refman, 1) )
        }
      }
    }
LUMI_cleanup:
  LUMI_dec_ref(error_msg_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.get-any-opt-param"
Returncode lumi_M_Lumi_get_any_opt_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman, Int* index, String** value, Ref_Manager** value_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(option_Refman);
  LUMI_inc_ref(param_Refman);
  if (sys == NULL) RAISE(100, 27, "used member of empty object")
  if (sys_Refman->value == NULL) RAISE(100, 38, "used member of outdated weak reference")
  if (sys->argv == NULL) RAISE(100, 27, "used member of empty object")
  if (sys->argv_Refman->value == NULL) RAISE(100, 38, "used member of outdated weak reference")
  CHECK(99, lumi_M_Lumi_check_opt_param_error(self, self_Refman, (*index) >= (sys->argv->length - 1), option, option_Refman, param, param_Refman) )
  *index += 1;
  if (sys == NULL) RAISE(102, 27, "used member of empty object")
  if (sys_Refman->value == NULL) RAISE(102, 38, "used member of outdated weak reference")
  if (sys->argv == NULL) RAISE(102, 29, "empty object used as sequence")
  if (sys->argv_Refman->value == NULL) RAISE(102, 40, "outdated weak reference used as sequence")
  if ((*index) < 0 || (*index) >= (sys->argv)->length) RAISE(102, 25, "slice index out of bounds")
  LUMI_dec_ref(*value_Refman);
  *value_Refman = sys->argv_Refman;
  LUMI_inc_ref(*value_Refman);
  *value = ((String*)((sys->argv)->values)) + *index;
LUMI_cleanup:
  LUMI_dec_ref(param_Refman);
  LUMI_dec_ref(option_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.get-opt-param"
Returncode lumi_M_Lumi_get_opt_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman, Int* index, String** value, Ref_Manager** value_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(option_Refman);
  LUMI_inc_ref(param_Refman);
  CHECK(106, lumi_M_Lumi_get_any_opt_param(self, self_Refman, option, option_Refman, param, param_Refman, &(*index), &(*value), &(*value_Refman)) )
  if (*value == NULL) RAISE(107, 29, "empty object used as sequence")
  if ((*value_Refman)->value == NULL) RAISE(107, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= ((*value))->length) RAISE(107, 25, "slice index out of bounds")
  CHECK(107, lumi_M_Lumi_check_opt_param_error(self, self_Refman, ((((*value))->values)[0]) == '-', option, option_Refman, param, param_Refman) )
  CHECK(108, lumi_M_Lumi_check_param(self, self_Refman, *value, *value_Refman) )
LUMI_cleanup:
  LUMI_dec_ref(param_Refman);
  LUMI_dec_ref(option_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
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
  LUMI_inc_ref(option_Refman);
  LUMI_inc_ref(param_Refman);
  if (is_error) {
      aux_String_0 = &aux_String_0_Var;
      aux_String_0_Refman = LUMI_new_ref(aux_String_0);
      if (aux_String_0_Refman == NULL) RAISE(113, 38, "insufficient memory for managed object")
      aux_String_0_Var.max_length = 16;
      aux_String_0_Var.length = 15;
      aux_String_0_Var.values = "error: missing ";
      CHECK(113, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
      CHECK(114, Sys_print(sys, sys_Refman, param, param_Refman) )
      aux_String_1 = &aux_String_1_Var;
      aux_String_1_Refman = LUMI_new_ref(aux_String_1);
      if (aux_String_1_Refman == NULL) RAISE(115, 38, "insufficient memory for managed object")
      aux_String_1_Var.max_length = 10;
      aux_String_1_Var.length = 9;
      aux_String_1_Var.values = " after \"-";
      CHECK(115, Sys_print(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
      CHECK(116, Sys_print(sys, sys_Refman, option, option_Refman) )
      aux_String_2 = &aux_String_2_Var;
      aux_String_2_Refman = LUMI_new_ref(aux_String_2);
      if (aux_String_2_Refman == NULL) RAISE(117, 38, "insufficient memory for managed object")
      aux_String_2_Var.max_length = 7;
      aux_String_2_Var.length = 6;
      aux_String_2_Var.values = "\" flag";
      CHECK(117, Sys_println(sys, sys_Refman, aux_String_2, aux_String_2_Refman) )
      USER_RAISE(118, NULL, NULL)
    }
LUMI_cleanup:
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(param_Refman);
  LUMI_dec_ref(option_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
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
  LUMI_inc_ref(value_Refman);
  CHECK(121, String_has(value, value_Refman, '"', &(aux_Bool_0)) )
  if (aux_Bool_0) {
      aux_String_0 = &aux_String_0_Var;
      aux_String_0_Refman = LUMI_new_ref(aux_String_0);
      if (aux_String_0_Refman == NULL) RAISE(122, 38, "insufficient memory for managed object")
      aux_String_0_Var.max_length = 42;
      aux_String_0_Var.length = 41;
      aux_String_0_Var.values = "error: illegal \" character in parameter '";
      CHECK(122, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
      CHECK(123, Sys_print(sys, sys_Refman, value, value_Refman) )
      aux_String_1 = &aux_String_1_Var;
      aux_String_1_Refman = LUMI_new_ref(aux_String_1);
      if (aux_String_1_Refman == NULL) RAISE(124, 38, "insufficient memory for managed object")
      aux_String_1_Var.max_length = 2;
      aux_String_1_Var.length = 1;
      aux_String_1_Var.values = "'";
      CHECK(124, Sys_println(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
      USER_RAISE(125, NULL, NULL)
    }
LUMI_cleanup:
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(value_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
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
  if (self == NULL) RAISE(128, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(128, 38, "used member of outdated weak reference")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(128, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = " \"";
  CHECK(128, String_concat(self->command, self->command_Refman, aux_String_0, aux_String_0_Refman) )
  if (self == NULL) RAISE(129, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(129, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(129, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(129, 38, "used member of outdated weak reference")
  CHECK(129, String_concat(self->command, self->command_Refman, self->output, self->output_Refman) )
  if (self == NULL) RAISE(130, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(130, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(130, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(130, 38, "used member of outdated weak reference")
  if (self->run_c || (! self->explicit_output)) {
      if (self == NULL) RAISE(131, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(131, 38, "used member of outdated weak reference")
      aux_String_1 = &aux_String_1_Var;
      aux_String_1_Refman = LUMI_new_ref(aux_String_1);
      if (aux_String_1_Refman == NULL) RAISE(131, 38, "insufficient memory for managed object")
      aux_String_1_Var.max_length = 3;
      aux_String_1_Var.length = 2;
      aux_String_1_Var.values = ".c";
      CHECK(131, String_concat(self->command, self->command_Refman, aux_String_1, aux_String_1_Refman) )
    }
  if (self == NULL) RAISE(132, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(132, 38, "used member of outdated weak reference")
  aux_String_2 = &aux_String_2_Var;
  aux_String_2_Refman = LUMI_new_ref(aux_String_2);
  if (aux_String_2_Refman == NULL) RAISE(132, 38, "insufficient memory for managed object")
  aux_String_2_Var.max_length = 2;
  aux_String_2_Var.length = 1;
  aux_String_2_Var.values = "\"";
  CHECK(132, String_concat(self->command, self->command_Refman, aux_String_2, aux_String_2_Refman) )
LUMI_cleanup:
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.concat-first-file-name"
Returncode lumi_M_Lumi_concat_first_file_name(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* target, Ref_Manager* target_Refman, String* name, Ref_Manager* name_Refman) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  LUMI_inc_ref(target_Refman);
  LUMI_inc_ref(name_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(135, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 2;
  aux_String_0_Var.length = 1;
  aux_String_0_Var.values = "\"";
  CHECK(135, String_concat(target, target_Refman, aux_String_0, aux_String_0_Refman) )
  CHECK(136, String_concat(target, target_Refman, name, name_Refman) )
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(137, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 2;
  aux_String_1_Var.length = 1;
  aux_String_1_Var.values = "\"";
  CHECK(137, String_concat(target, target_Refman, aux_String_1, aux_String_1_Refman) )
LUMI_cleanup:
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(name_Refman);
  LUMI_dec_ref(target_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.concat-file-name"
Returncode lumi_M_Lumi_concat_file_name(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* target, Ref_Manager* target_Refman, String* name, Ref_Manager* name_Refman) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(target_Refman);
  LUMI_inc_ref(name_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(140, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 2;
  aux_String_0_Var.length = 1;
  aux_String_0_Var.values = " ";
  CHECK(140, String_concat(target, target_Refman, aux_String_0, aux_String_0_Refman) )
  CHECK(141, lumi_M_Lumi_concat_first_file_name(self, self_Refman, target, target_Refman, name, name_Refman) )
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(name_Refman);
  LUMI_dec_ref(target_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.concat-tl-path"
Returncode lumi_M_Lumi_concat_tl_path(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  if (self == NULL) RAISE(144, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(144, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(144, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(144, 38, "used member of outdated weak reference")
  CHECK(144, String_concat(self->command, self->command_Refman, self->lumi_path, self->lumi_path_Refman) )
  if (self == NULL) RAISE(145, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(145, 38, "used member of outdated weak reference")
  if (! self->lumi_path_ends_with_separator) {
      if (self == NULL) RAISE(146, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(146, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(146, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(146, 38, "used member of outdated weak reference")
      CHECK(146, String_append(self->command, self->command_Refman, self->path_separator) )
    }
  if (self == NULL) RAISE(147, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(147, 38, "used member of outdated weak reference")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(147, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = "TL";
  CHECK(147, String_concat(self->command, self->command_Refman, aux_String_0, aux_String_0_Refman) )
  if (self == NULL) RAISE(148, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(148, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(148, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(148, 38, "used member of outdated weak reference")
  CHECK(148, String_append(self->command, self->command_Refman, self->version) )
  if (self == NULL) RAISE(149, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(149, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(149, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(149, 38, "used member of outdated weak reference")
  CHECK(149, String_append(self->command, self->command_Refman, self->path_separator) )
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
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
  if (sys == NULL) RAISE(152, 27, "used member of empty object")
  if (sys_Refman->value == NULL) RAISE(152, 38, "used member of outdated weak reference")
  if (sys->argv == NULL) RAISE(152, 27, "used member of empty object")
  if (sys->argv_Refman->value == NULL) RAISE(152, 38, "used member of outdated weak reference")
  CHECK(152, lumi_M_f_error_if(sys->argv->length < 2, lumi_M_usage, lumi_M_usage_Refman) )
  for (index = 1; index < sys->argv->length; ++index) {
      if (sys == NULL) RAISE(158, 27, "used member of empty object")
      if (sys_Refman->value == NULL) RAISE(158, 38, "used member of outdated weak reference")
      if (sys->argv == NULL) RAISE(158, 29, "empty object used as sequence")
      if (sys->argv_Refman->value == NULL) RAISE(158, 40, "outdated weak reference used as sequence")
      if ((index) < 0 || (index) >= (sys->argv)->length) RAISE(158, 25, "slice index out of bounds")
      arg = ((String*)((sys->argv)->values)) + index;
      arg_Refman = sys->argv_Refman;
      LUMI_inc_ref(arg_Refman);
      if (arg == NULL) RAISE(159, 29, "empty object used as sequence")
      if (arg_Refman->value == NULL) RAISE(159, 40, "outdated weak reference used as sequence")
      if ((0) < 0 || (0) >= (arg)->length) RAISE(159, 25, "slice index out of bounds")
      if ((((arg)->values)[0]) == '-') {
        if (arg == NULL) RAISE(160, 27, "used member of empty object")
        if (arg_Refman->value == NULL) RAISE(160, 38, "used member of outdated weak reference")
        if (arg->length < 2) {
          aux_String_0 = &aux_String_0_Var;
          aux_String_0_Refman = LUMI_new_ref(aux_String_0);
          if (aux_String_0_Refman == NULL) RAISE(161, 38, "insufficient memory for managed object")
          aux_String_0_Var.max_length = 26;
          aux_String_0_Var.length = 25;
          aux_String_0_Var.values = "warning: unknown flag \"-\"";
          CHECK(161, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
        }
        else {
          if (arg == NULL) RAISE(163, 29, "empty object used as sequence")
          if (arg_Refman->value == NULL) RAISE(163, 40, "outdated weak reference used as sequence")
          if ((1) < 0 || (1) >= (arg)->length) RAISE(163, 25, "slice index out of bounds")
          op = ((arg)->values)[1];
          if (op == 'h') {
            CHECK(165, lumi_M_f_help() )
          }
          else {
            if (op == 'o') {
              aux_String_1 = &aux_String_1_Var;
              aux_String_1_Refman = LUMI_new_ref(aux_String_1);
              if (aux_String_1_Refman == NULL) RAISE(167, 38, "insufficient memory for managed object")
              aux_String_1_Var.max_length = 2;
              aux_String_1_Var.length = 1;
              aux_String_1_Var.values = "o";
              aux_String_2 = &aux_String_2_Var;
              aux_String_2_Refman = LUMI_new_ref(aux_String_2);
              if (aux_String_2_Refman == NULL) RAISE(167, 38, "insufficient memory for managed object")
              aux_String_2_Var.max_length = 10;
              aux_String_2_Var.length = 9;
              aux_String_2_Var.values = "file name";
              if (self == NULL) RAISE(168, 27, "used member of empty object")
              if (self_Refman->value == NULL) RAISE(168, 38, "used member of outdated weak reference")
              CHECK(167, lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_1, aux_String_1_Refman, aux_String_2, aux_String_2_Refman, &(index), &(self->output), &(self->output_Refman)) )
              if (self == NULL) RAISE(169, 27, "used member of empty object")
              if (self_Refman->value == NULL) RAISE(169, 38, "used member of outdated weak reference")
              self->explicit_output = true;
            }
            else {
              if (op == 't') {
                aux_String_3 = &aux_String_3_Var;
                aux_String_3_Refman = LUMI_new_ref(aux_String_3);
                if (aux_String_3_Refman == NULL) RAISE(171, 38, "insufficient memory for managed object")
                aux_String_3_Var.max_length = 2;
                aux_String_3_Var.length = 1;
                aux_String_3_Var.values = "t";
                aux_String_4 = &aux_String_4_Var;
                aux_String_4_Refman = LUMI_new_ref(aux_String_4);
                if (aux_String_4_Refman == NULL) RAISE(171, 38, "insufficient memory for managed object")
                aux_String_4_Var.max_length = 12;
                aux_String_4_Var.length = 11;
                aux_String_4_Var.values = "module name";
                if (self == NULL) RAISE(172, 27, "used member of empty object")
                if (self_Refman->value == NULL) RAISE(172, 38, "used member of outdated weak reference")
                CHECK(171, lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_3, aux_String_3_Refman, aux_String_4, aux_String_4_Refman, &(index), &(self->mut), &(self->mut_Refman)) )
              }
              else {
                if (op == 'e') {
                  if (self == NULL) RAISE(175, 27, "used member of empty object")
                  if (self_Refman->value == NULL) RAISE(175, 38, "used member of outdated weak reference")
                  aux_String_5 = &aux_String_5_Var;
                  aux_String_5_Refman = LUMI_new_ref(aux_String_5);
                  if (aux_String_5_Refman == NULL) RAISE(176, 38, "insufficient memory for managed object")
                  aux_String_5_Var.max_length = 2;
                  aux_String_5_Var.length = 1;
                  aux_String_5_Var.values = "e";
                  aux_String_6 = &aux_String_6_Var;
                  aux_String_6_Refman = LUMI_new_ref(aux_String_6);
                  if (aux_String_6_Refman == NULL) RAISE(176, 38, "insufficient memory for managed object")
                  aux_String_6_Var.max_length = 10;
                  aux_String_6_Var.length = 9;
                  aux_String_6_Var.values = "file name";
                  CHECK(176, lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_5, aux_String_5_Refman, aux_String_6, aux_String_6_Refman, &(index), &(aux_String_7), &(aux_String_7_Refman)) )
                  CHECK(174, lumi_M_Lumi_concat_file_name(self, self_Refman, self->external_files, self->external_files_Refman, aux_String_7, aux_String_7_Refman) )
                }
                else {
                  if (op == 'p') {
                    if (self == NULL) RAISE(179, 27, "used member of empty object")
                    if (self_Refman->value == NULL) RAISE(179, 38, "used member of outdated weak reference")
                    aux_String_8 = &aux_String_8_Var;
                    aux_String_8_Refman = LUMI_new_ref(aux_String_8);
                    if (aux_String_8_Refman == NULL) RAISE(180, 38, "insufficient memory for managed object")
                    aux_String_8_Var.max_length = 2;
                    aux_String_8_Var.length = 1;
                    aux_String_8_Var.values = "p";
                    aux_String_9 = &aux_String_9_Var;
                    aux_String_9_Refman = LUMI_new_ref(aux_String_9);
                    if (aux_String_9_Refman == NULL) RAISE(180, 38, "insufficient memory for managed object")
                    aux_String_9_Var.max_length = 5;
                    aux_String_9_Var.length = 4;
                    aux_String_9_Var.values = "path";
                    CHECK(180, lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_8, aux_String_8_Refman, aux_String_9, aux_String_9_Refman, &(index), &(aux_String_10), &(aux_String_10_Refman)) )
                    CHECK(179, String_new(self->lumi_path, self->lumi_path_Refman, aux_String_10, aux_String_10_Refman) )
                  }
                  else {
                    if (op == 'c') {
                      if (self == NULL) RAISE(182, 27, "used member of empty object")
                      if (self_Refman->value == NULL) RAISE(182, 38, "used member of outdated weak reference")
                      self->run_c = false;
                    }
                    else {
                      if (arg == NULL) RAISE(183, 27, "used member of empty object")
                      if (arg_Refman->value == NULL) RAISE(183, 38, "used member of outdated weak reference")
                      if ((op == 'l') && (arg->length > 2)) {
                        if (self == NULL) RAISE(184, 27, "used member of empty object")
                        if (self_Refman->value == NULL) RAISE(184, 38, "used member of outdated weak reference")
                        self->run_lumi = false;
                        if (arg == NULL) RAISE(185, 29, "empty object used as sequence")
                        if (arg_Refman->value == NULL) RAISE(185, 40, "outdated weak reference used as sequence")
                        if ((2) < 0 || (2) >= (arg)->length) RAISE(185, 25, "slice index out of bounds")
                        if (self == NULL) RAISE(185, 27, "used member of empty object")
                        if (self_Refman->value == NULL) RAISE(185, 38, "used member of outdated weak reference")
                        self->version = ((arg)->values)[2];
                      }
                      else {
                        if (op == 'r') {
                          if (self == NULL) RAISE(187, 27, "used member of empty object")
                          if (self_Refman->value == NULL) RAISE(187, 38, "used member of outdated weak reference")
                          self->run_program = true;
                          if (arg == NULL) RAISE(188, 27, "used member of empty object")
                          if (arg_Refman->value == NULL) RAISE(188, 38, "used member of outdated weak reference")
                          if (arg->length > 2) {
              if (arg == NULL) RAISE(189, 29, "empty object used as sequence")
              if (arg_Refman->value == NULL) RAISE(189, 40, "outdated weak reference used as sequence")
              if ((2) < 0 || (2) >= (arg)->length) RAISE(189, 25, "slice index out of bounds")
              if ((((arg)->values)[2]) == 'a') {
                aux_String_11 = &aux_String_11_Var;
                aux_String_11_Refman = LUMI_new_ref(aux_String_11);
                if (aux_String_11_Refman == NULL) RAISE(190, 38, "insufficient memory for managed object")
                aux_String_11_Var.max_length = 3;
                aux_String_11_Var.length = 2;
                aux_String_11_Var.values = "ra";
                aux_String_12 = &aux_String_12_Var;
                aux_String_12_Refman = LUMI_new_ref(aux_String_12);
                if (aux_String_12_Refman == NULL) RAISE(190, 38, "insufficient memory for managed object")
                aux_String_12_Var.max_length = 10;
                aux_String_12_Var.length = 9;
                aux_String_12_Var.values = "arguments";
                if (self == NULL) RAISE(191, 27, "used member of empty object")
                if (self_Refman->value == NULL) RAISE(191, 38, "used member of outdated weak reference")
                CHECK(190, lumi_M_Lumi_get_any_opt_param(self, self_Refman, aux_String_11, aux_String_11_Refman, aux_String_12, aux_String_12_Refman, &(index), &(self->execute_arguments), &(self->execute_arguments_Refman)) )
              }
            }
                        }
                        else {
                          if (op == 'v') {
                            if (self == NULL) RAISE(193, 27, "used member of empty object")
                            if (self_Refman->value == NULL) RAISE(193, 38, "used member of outdated weak reference")
                            self->verbose = true;
                          }
                          else {
                            if (op == 'd') {
                              if (self == NULL) RAISE(195, 27, "used member of empty object")
                              if (self_Refman->value == NULL) RAISE(195, 38, "used member of outdated weak reference")
                              self->verbose = true;
                              if (self == NULL) RAISE(196, 27, "used member of empty object")
                              if (self_Refman->value == NULL) RAISE(196, 38, "used member of outdated weak reference")
                              self->execute = false;
                            }
                            else {
                              aux_String_13 = &aux_String_13_Var;
                              aux_String_13_Refman = LUMI_new_ref(aux_String_13);
                              if (aux_String_13_Refman == NULL) RAISE(198, 38, "insufficient memory for managed object")
                              aux_String_13_Var.max_length = 24;
                              aux_String_13_Var.length = 23;
                              aux_String_13_Var.values = "warning: unknown flag \"";
                              CHECK(198, Sys_print(sys, sys_Refman, aux_String_13, aux_String_13_Refman) )
                              CHECK(199, Sys_print(sys, sys_Refman, arg, arg_Refman) )
                              aux_String_14 = &aux_String_14_Var;
                              aux_String_14_Refman = LUMI_new_ref(aux_String_14);
                              if (aux_String_14_Refman == NULL) RAISE(200, 38, "insufficient memory for managed object")
                              aux_String_14_Var.max_length = 2;
                              aux_String_14_Var.length = 1;
                              aux_String_14_Var.values = "\"";
                              CHECK(200, Sys_println(sys, sys_Refman, aux_String_14, aux_String_14_Refman) )
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
        CHECK(202, lumi_M_Lumi_check_param(self, self_Refman, arg, arg_Refman) )
        if (! (first_input != NULL && first_input_Refman->value != NULL)) {
          LUMI_dec_ref(first_input_Refman);
          first_input_Refman = arg_Refman;
          LUMI_inc_ref(first_input_Refman);
          first_input = arg;
        }
        LUMI_dec_ref(last_input_Refman);
        last_input_Refman = arg_Refman;
        LUMI_inc_ref(last_input_Refman);
        last_input = arg;
        if (self == NULL) RAISE(206, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(206, 38, "used member of outdated weak reference")
        CHECK(206, lumi_M_Lumi_concat_file_name(self, self_Refman, self->input_files, self->input_files_Refman, arg, arg_Refman) )
        input_files_num += 1;
      }
    }
  aux_String_15 = &aux_String_15_Var;
  aux_String_15_Refman = LUMI_new_ref(aux_String_15);
  if (aux_String_15_Refman == NULL) RAISE(209, 38, "insufficient memory for managed object")
  aux_String_15_Var.max_length = 22;
  aux_String_15_Var.length = 21;
  aux_String_15_Var.values = "error: no input files";
  CHECK(209, lumi_M_f_error_if(input_files_num == 0, aux_String_15, aux_String_15_Refman) )
  if (self == NULL) RAISE(211, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(211, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(211, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(211, 38, "used member of outdated weak reference")
  aux_String_16 = &aux_String_16_Var;
  aux_String_16_Refman = LUMI_new_ref(aux_String_16);
  if (aux_String_16_Refman == NULL) RAISE(213, 38, "insufficient memory for managed object")
  aux_String_16_Var.max_length = 72;
  aux_String_16_Var.length = 71;
  aux_String_16_Var.values = "error: cannot run program when C compilation is turned off by \"-c\" flag";
  CHECK(210, lumi_M_f_error_if(self->run_program && (! self->run_c), aux_String_16, aux_String_16_Refman) )
  if (self == NULL) RAISE(215, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(215, 38, "used member of outdated weak reference")
  if (self->run_lumi) {
      if (first_input == NULL) RAISE(217, 27, "used member of empty object")
      if (first_input_Refman->value == NULL) RAISE(217, 38, "used member of outdated weak reference")
      aux_String_17 = &aux_String_17_Var;
      aux_String_17_Refman = LUMI_new_ref(aux_String_17);
      if (aux_String_17_Refman == NULL) RAISE(218, 38, "insufficient memory for managed object")
      aux_String_17_Var.max_length = 32;
      aux_String_17_Var.length = 31;
      aux_String_17_Var.values = "error: Lumi file name too short";
      CHECK(216, lumi_M_f_error_if(first_input->length < 6, aux_String_17, aux_String_17_Refman) )
      if (first_input == NULL) RAISE(219, 27, "used member of empty object")
      if (first_input_Refman->value == NULL) RAISE(219, 38, "used member of outdated weak reference")
      if (first_input == NULL) RAISE(219, 29, "empty object used as sequence")
      if (first_input_Refman->value == NULL) RAISE(219, 40, "outdated weak reference used as sequence")
      if ((first_input->length - 4) < 0 || (first_input->length - 4) >= (first_input)->length) RAISE(219, 25, "slice index out of bounds")
      if (self == NULL) RAISE(219, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(219, 38, "used member of outdated weak reference")
      self->version = ((first_input)->values)[first_input->length - 4];
    }
  if (self == NULL) RAISE(220, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(220, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(220, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(220, 38, "used member of outdated weak reference")
  if ((self->version < '0') || (self->version > '4')) {
      aux_String_18 = &aux_String_18_Var;
      aux_String_18_Refman = LUMI_new_ref(aux_String_18);
      if (aux_String_18_Refman == NULL) RAISE(221, 38, "insufficient memory for managed object")
      aux_String_18_Var.max_length = 30;
      aux_String_18_Var.length = 29;
      aux_String_18_Var.values = "error: unsupported version TL";
      CHECK(221, Sys_print(sys, sys_Refman, aux_String_18, aux_String_18_Refman) )
      version_string = &version_string_Var;
      version_string_Var.values = version_string_Values;
      version_string_Refman = LUMI_new_ref(version_string);
      if (version_string_Refman == NULL) RAISE(222, 38, "insufficient memory for managed object")
      if (self == NULL) RAISE(223, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(223, 38, "used member of outdated weak reference")
      CHECK(223, String_append(version_string, version_string_Refman, self->version) )
      CHECK(224, Sys_println(sys, sys_Refman, version_string, version_string_Refman) )
      USER_RAISE(225, NULL, NULL)
    }
  if (self == NULL) RAISE(227, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(227, 38, "used member of outdated weak reference")
  aux_String_19 = &aux_String_19_Var;
  aux_String_19_Refman = LUMI_new_ref(aux_String_19);
  if (aux_String_19_Refman == NULL) RAISE(228, 38, "insufficient memory for managed object")
  aux_String_19_Var.max_length = 47;
  aux_String_19_Var.length = 46;
  aux_String_19_Var.values = "error: multiple files not supported before TL2";
  CHECK(226, lumi_M_f_error_if((self->version < '2') && (input_files_num > 1), aux_String_19, aux_String_19_Refman) )
  if (self == NULL) RAISE(231, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(231, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(231, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(231, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(230, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(230, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(230, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(230, 38, "used member of outdated weak reference")
  aux_String_20 = &aux_String_20_Var;
  aux_String_20_Refman = LUMI_new_ref(aux_String_20);
  if (aux_String_20_Refman == NULL) RAISE(232, 38, "insufficient memory for managed object")
  aux_String_20_Var.max_length = 49;
  aux_String_20_Var.length = 48;
  aux_String_20_Var.values = "error: cannot specify C output file in TL2 & TL3";
  CHECK(229, lumi_M_f_error_if((((self->version >= '2') && (self->version <= '3')) && self->explicit_output) && (! self->run_c), aux_String_20, aux_String_20_Refman) )
  if (self == NULL) RAISE(234, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(234, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(234, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(234, 38, "used member of outdated weak reference")
  aux_String_21 = &aux_String_21_Var;
  aux_String_21_Refman = LUMI_new_ref(aux_String_21);
  if (aux_String_21_Refman == NULL) RAISE(235, 38, "insufficient memory for managed object")
  aux_String_21_Var.max_length = 40;
  aux_String_21_Var.length = 39;
  aux_String_21_Var.values = "error: testing not supported before TL4";
  CHECK(233, lumi_M_f_error_if((self->version < '4') && (self->mut != NULL && self->mut_Refman->value != NULL), aux_String_21, aux_String_21_Refman) )
  if (self == NULL) RAISE(236, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(236, 38, "used member of outdated weak reference")
  if (self->version <= '2') {
      if (self == NULL) RAISE(237, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(237, 38, "used member of outdated weak reference")
      LUMI_dec_ref(self->main_input_Refman);
      self->main_input_Refman = last_input_Refman;
      LUMI_inc_ref(self->main_input_Refman);
      self->main_input = last_input;
    }
  else {
      if (self == NULL) RAISE(239, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(239, 38, "used member of outdated weak reference")
      LUMI_dec_ref(self->main_input_Refman);
      self->main_input_Refman = first_input_Refman;
      LUMI_inc_ref(self->main_input_Refman);
      self->main_input = first_input;
    }
  if (self == NULL) RAISE(241, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(241, 38, "used member of outdated weak reference")
  if (! (self->output != NULL && self->output_Refman->value != NULL)) {
      suffix_length = 2;
      if (self == NULL) RAISE(243, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(243, 38, "used member of outdated weak reference")
      if (self->run_lumi) {
        suffix_length = 5;
      }
      if (self == NULL) RAISE(246, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(246, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(246, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(246, 38, "used member of outdated weak reference")
      if (self->main_input == NULL) RAISE(246, 27, "used member of empty object")
      if (self->main_input_Refman->value == NULL) RAISE(246, 38, "used member of outdated weak reference")
      aux_String_22 = &aux_String_22_Var;
      aux_String_22_Refman = LUMI_new_ref(aux_String_22);
      if (aux_String_22_Refman == NULL) RAISE(246, 38, "insufficient memory for managed object")
      aux_String_22_Var.length = self->main_input->length - suffix_length;
      aux_String_22_Var.max_length = aux_String_22_Var.length + 1;
      aux_String_22_Var.values = (self->main_input)->values + (0);
      if (self->main_input == NULL) RAISE(246, 29, "empty object used as sequence")
      if (self->main_input_Refman->value == NULL) RAISE(246, 40, "outdated weak reference used as sequence")
      if ((0) < 0 || (self->main_input->length - suffix_length) < 0 || (0) + (self->main_input->length - suffix_length) > (self->main_input)->length) RAISE(246, 25, "slice index out of bounds")
      if (self == NULL) RAISE(245, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(245, 38, "used member of outdated weak reference")
      if (self->main_input == NULL) RAISE(245, 27, "used member of empty object")
      if (self->main_input_Refman->value == NULL) RAISE(245, 38, "used member of outdated weak reference")
      aux_String_23 = LUMI_new_string(self->main_input->length);
      if (aux_String_23 == NULL) RAISE(245, 49, "insufficient memory for object dynamic allocation")
      aux_String_23_Refman = LUMI_new_ref(aux_String_23);
      if (aux_String_23_Refman == NULL) RAISE(245, 38, "insufficient memory for managed object")
      CHECK(245, String_new(aux_String_23, aux_String_23_Refman, aux_String_22, self->main_input_Refman) )
      if (self == NULL) RAISE(245, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(245, 38, "used member of outdated weak reference")
      String_Del(self->implicit_output);
      LUMI_owner_dec_ref(self->implicit_output_Refman);
      self->implicit_output_Refman = aux_String_23_Refman;
      self->implicit_output = aux_String_23;
      aux_String_23 = NULL;
      aux_String_23_Refman = NULL;
      if (self == NULL) RAISE(247, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(247, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(247, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(247, 38, "used member of outdated weak reference")
      LUMI_dec_ref(self->output_Refman);
      self->output_Refman = self->implicit_output_Refman;
      LUMI_inc_ref(self->output_Refman);
      self->output = self->implicit_output;
    }
LUMI_cleanup:
  String_Del(aux_String_23);
  LUMI_owner_dec_ref(aux_String_23_Refman);
  LUMI_dec_ref(aux_String_22_Refman);
  LUMI_dec_ref(aux_String_21_Refman);
  LUMI_dec_ref(aux_String_20_Refman);
  LUMI_dec_ref(aux_String_19_Refman);
  LUMI_dec_ref(aux_String_18_Refman);
  LUMI_dec_ref(aux_String_17_Refman);
  LUMI_dec_ref(aux_String_16_Refman);
  LUMI_dec_ref(aux_String_15_Refman);
  LUMI_dec_ref(aux_String_14_Refman);
  LUMI_dec_ref(aux_String_13_Refman);
  LUMI_dec_ref(aux_String_12_Refman);
  LUMI_dec_ref(aux_String_11_Refman);
  LUMI_dec_ref(aux_String_10_Refman);
  LUMI_dec_ref(aux_String_9_Refman);
  LUMI_dec_ref(aux_String_8_Refman);
  LUMI_dec_ref(aux_String_7_Refman);
  LUMI_dec_ref(aux_String_6_Refman);
  LUMI_dec_ref(aux_String_5_Refman);
  LUMI_dec_ref(aux_String_4_Refman);
  LUMI_dec_ref(aux_String_3_Refman);
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(version_string_Refman);
  LUMI_dec_ref(arg_Refman);
  LUMI_dec_ref(last_input_Refman);
  LUMI_dec_ref(first_input_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.m-run-lumi"
Returncode lumi_M_Lumi_m_run_lumi(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
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
  if (self == NULL) RAISE(251, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(251, 38, "used member of outdated weak reference")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(251, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = "tl";
  CHECK(251, String_new(self->command, self->command_Refman, aux_String_0, aux_String_0_Refman) )
  if (self == NULL) RAISE(252, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(252, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(252, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(252, 38, "used member of outdated weak reference")
  CHECK(252, String_append(self->command, self->command_Refman, self->version) )
  if (self == NULL) RAISE(253, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(253, 38, "used member of outdated weak reference")
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(253, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 10;
  aux_String_1_Var.length = 9;
  aux_String_1_Var.values = "-compiler";
  CHECK(253, String_concat(self->command, self->command_Refman, aux_String_1, aux_String_1_Refman) )
  if (self == NULL) RAISE(254, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(254, 38, "used member of outdated weak reference")
  if (self->version >= '4') {
      if (self == NULL) RAISE(255, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(255, 38, "used member of outdated weak reference")
      if (self->mut != NULL && self->mut_Refman->value != NULL) {
        if (self == NULL) RAISE(256, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(256, 38, "used member of outdated weak reference")
        aux_String_2 = &aux_String_2_Var;
        aux_String_2_Refman = LUMI_new_ref(aux_String_2);
        if (aux_String_2_Refman == NULL) RAISE(256, 38, "insufficient memory for managed object")
        aux_String_2_Var.max_length = 4;
        aux_String_2_Var.length = 3;
        aux_String_2_Var.values = " -t";
        CHECK(256, String_concat(self->command, self->command_Refman, aux_String_2, aux_String_2_Refman) )
        if (self == NULL) RAISE(257, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(257, 38, "used member of outdated weak reference")
        if (self == NULL) RAISE(257, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(257, 38, "used member of outdated weak reference")
        CHECK(257, lumi_M_Lumi_concat_file_name(self, self_Refman, self->command, self->command_Refman, self->mut, self->mut_Refman) )
      }
      CHECK(258, lumi_M_Lumi_concat_lumi_output(self, self_Refman) )
    }
  if (self == NULL) RAISE(259, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(259, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(259, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(259, 38, "used member of outdated weak reference")
  CHECK(259, String_concat(self->command, self->command_Refman, self->input_files, self->input_files_Refman) )
  if (self == NULL) RAISE(260, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(260, 38, "used member of outdated weak reference")
  if (self->version <= '1') {
      CHECK(261, lumi_M_Lumi_concat_lumi_output(self, self_Refman) )
    }
  aux_String_3 = &aux_String_3_Var;
  aux_String_3_Refman = LUMI_new_ref(aux_String_3);
  if (aux_String_3_Refman == NULL) RAISE(262, 38, "insufficient memory for managed object")
  aux_String_3_Var.max_length = 21;
  aux_String_3_Var.length = 20;
  aux_String_3_Var.values = "Lumi compiler failed";
  CHECK(262, lumi_M_Lumi_m_run_command(self, self_Refman, aux_String_3, aux_String_3_Refman) )
LUMI_cleanup:
  LUMI_dec_ref(aux_String_3_Refman);
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.m-run-c"
Returncode lumi_M_Lumi_m_run_c(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
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
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(265, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = "CC";
  if (self == NULL) RAISE(265, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(265, 38, "used member of outdated weak reference")
  CHECK(265, Sys_getenv(sys, sys_Refman, aux_String_0, aux_String_0_Refman, self->command, self->command_Refman, &(aux_Bool_0)) )
  if (! aux_Bool_0) {
      if (self == NULL) RAISE(266, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(266, 38, "used member of outdated weak reference")
      aux_String_1 = &aux_String_1_Var;
      aux_String_1_Refman = LUMI_new_ref(aux_String_1);
      if (aux_String_1_Refman == NULL) RAISE(266, 38, "insufficient memory for managed object")
      aux_String_1_Var.max_length = 4;
      aux_String_1_Var.length = 3;
      aux_String_1_Var.values = "gcc";
      CHECK(266, String_new(self->command, self->command_Refman, aux_String_1, aux_String_1_Refman) )
    }
  if (self == NULL) RAISE(267, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(267, 38, "used member of outdated weak reference")
  if (self->lumi_path == NULL) RAISE(267, 27, "used member of empty object")
  if (self->lumi_path_Refman->value == NULL) RAISE(267, 38, "used member of outdated weak reference")
  if (self->lumi_path->length == 0) {
      aux_String_2 = &aux_String_2_Var;
      aux_String_2_Refman = LUMI_new_ref(aux_String_2);
      if (aux_String_2_Refman == NULL) RAISE(268, 38, "insufficient memory for managed object")
      aux_String_2_Var.max_length = 9;
      aux_String_2_Var.length = 8;
      aux_String_2_Var.values = "LUMIPATH";
      if (self == NULL) RAISE(268, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(268, 38, "used member of outdated weak reference")
      CHECK(268, Sys_getenv(sys, sys_Refman, aux_String_2, aux_String_2_Refman, self->lumi_path, self->lumi_path_Refman, &(aux_Bool_1)) )
    }
  if (self == NULL) RAISE(269, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(269, 38, "used member of outdated weak reference")
  if (self->lumi_path == NULL) RAISE(269, 27, "used member of empty object")
  if (self->lumi_path_Refman->value == NULL) RAISE(269, 38, "used member of outdated weak reference")
  if (self->lumi_path->length > 0) {
      if (self == NULL) RAISE(270, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(270, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(270, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(270, 38, "used member of outdated weak reference")
      if (self->lumi_path == NULL) RAISE(270, 27, "used member of empty object")
      if (self->lumi_path_Refman->value == NULL) RAISE(270, 38, "used member of outdated weak reference")
      if (self->lumi_path == NULL) RAISE(270, 29, "empty object used as sequence")
      if (self->lumi_path_Refman->value == NULL) RAISE(270, 40, "outdated weak reference used as sequence")
      if ((self->lumi_path->length - 1) < 0 || (self->lumi_path->length - 1) >= (self->lumi_path)->length) RAISE(270, 25, "slice index out of bounds")
      last = ((self->lumi_path)->values)[self->lumi_path->length - 1];
      if (last == '\\') {
        if (self == NULL) RAISE(272, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(272, 38, "used member of outdated weak reference")
        self->path_separator = '\\';
      }
      if (self == NULL) RAISE(273, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(273, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(273, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(273, 38, "used member of outdated weak reference")
      self->lumi_path_ends_with_separator = last == self->path_separator;
    }
  if (self == NULL) RAISE(274, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(274, 38, "used member of outdated weak reference")
  aux_String_3 = &aux_String_3_Var;
  aux_String_3_Refman = LUMI_new_ref(aux_String_3);
  if (aux_String_3_Refman == NULL) RAISE(274, 38, "insufficient memory for managed object")
  aux_String_3_Var.max_length = 4;
  aux_String_3_Var.length = 3;
  aux_String_3_Var.values = " -g";
  CHECK(274, String_concat(self->command, self->command_Refman, aux_String_3, aux_String_3_Refman) )
  if (self == NULL) RAISE(275, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(275, 38, "used member of outdated weak reference")
  if (self->run_lumi) {
      if (self == NULL) RAISE(276, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(276, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(276, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(276, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(276, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(276, 38, "used member of outdated weak reference")
      if (((self->version >= '2') && (self->version <= '3')) && self->explicit_output) {
        if (self == NULL) RAISE(277, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(277, 38, "used member of outdated weak reference")
        aux_String_4 = &aux_String_4_Var;
        aux_String_4_Refman = LUMI_new_ref(aux_String_4);
        if (aux_String_4_Refman == NULL) RAISE(277, 38, "insufficient memory for managed object")
        aux_String_4_Var.max_length = 3;
        aux_String_4_Var.length = 2;
        aux_String_4_Var.values = " \"";
        CHECK(277, String_concat(self->command, self->command_Refman, aux_String_4, aux_String_4_Refman) )
        if (self == NULL) RAISE(278, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(278, 38, "used member of outdated weak reference")
        if (self == NULL) RAISE(279, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(279, 38, "used member of outdated weak reference")
        if (self == NULL) RAISE(279, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(279, 38, "used member of outdated weak reference")
        if (self->main_input == NULL) RAISE(279, 27, "used member of empty object")
        if (self->main_input_Refman->value == NULL) RAISE(279, 38, "used member of outdated weak reference")
        aux_String_5 = &aux_String_5_Var;
        aux_String_5_Refman = LUMI_new_ref(aux_String_5);
        if (aux_String_5_Refman == NULL) RAISE(279, 38, "insufficient memory for managed object")
        aux_String_5_Var.length = self->main_input->length - 5;
        aux_String_5_Var.max_length = aux_String_5_Var.length + 1;
        aux_String_5_Var.values = (self->main_input)->values + (0);
        if (self->main_input == NULL) RAISE(279, 29, "empty object used as sequence")
        if (self->main_input_Refman->value == NULL) RAISE(279, 40, "outdated weak reference used as sequence")
        if ((0) < 0 || (self->main_input->length - 5) < 0 || (0) + (self->main_input->length - 5) > (self->main_input)->length) RAISE(279, 25, "slice index out of bounds")
        CHECK(278, String_concat(self->command, self->command_Refman, aux_String_5, self->main_input_Refman) )
        if (self == NULL) RAISE(280, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(280, 38, "used member of outdated weak reference")
        aux_String_6 = &aux_String_6_Var;
        aux_String_6_Refman = LUMI_new_ref(aux_String_6);
        if (aux_String_6_Refman == NULL) RAISE(280, 38, "insufficient memory for managed object")
        aux_String_6_Var.max_length = 4;
        aux_String_6_Var.length = 3;
        aux_String_6_Var.values = ".c\"";
        CHECK(280, String_concat(self->command, self->command_Refman, aux_String_6, aux_String_6_Refman) )
      }
      else {
        CHECK(282, lumi_M_Lumi_concat_lumi_output(self, self_Refman) )
      }
    }
  else {
      if (self == NULL) RAISE(284, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(284, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(284, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(284, 38, "used member of outdated weak reference")
      CHECK(284, String_concat(self->command, self->command_Refman, self->input_files, self->input_files_Refman) )
    }
  if (self == NULL) RAISE(285, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(285, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(285, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(285, 38, "used member of outdated weak reference")
  CHECK(285, String_concat(self->command, self->command_Refman, self->external_files, self->external_files_Refman) )
  if (self == NULL) RAISE(286, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(286, 38, "used member of outdated weak reference")
  aux_String_7 = &aux_String_7_Var;
  aux_String_7_Refman = LUMI_new_ref(aux_String_7);
  if (aux_String_7_Refman == NULL) RAISE(286, 38, "insufficient memory for managed object")
  aux_String_7_Var.max_length = 2;
  aux_String_7_Var.length = 1;
  aux_String_7_Var.values = " ";
  CHECK(286, String_concat(self->command, self->command_Refman, aux_String_7, aux_String_7_Refman) )
  CHECK(287, lumi_M_Lumi_concat_tl_path(self, self_Refman) )
  if (self == NULL) RAISE(288, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(288, 38, "used member of outdated weak reference")
  if (self->version == '0') {
      if (self == NULL) RAISE(289, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(289, 38, "used member of outdated weak reference")
      aux_String_8 = &aux_String_8_Var;
      aux_String_8_Refman = LUMI_new_ref(aux_String_8);
      if (aux_String_8_Refman == NULL) RAISE(289, 38, "insufficient memory for managed object")
      aux_String_8_Var.max_length = 12;
      aux_String_8_Var.length = 11;
      aux_String_8_Var.values = "tl0-file.c ";
      CHECK(289, String_concat(self->command, self->command_Refman, aux_String_8, aux_String_8_Refman) )
      CHECK(290, lumi_M_Lumi_concat_tl_path(self, self_Refman) )
      if (self == NULL) RAISE(291, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(291, 38, "used member of outdated weak reference")
      aux_String_9 = &aux_String_9_Var;
      aux_String_9_Refman = LUMI_new_ref(aux_String_9);
      if (aux_String_9_Refman == NULL) RAISE(291, 38, "insufficient memory for managed object")
      aux_String_9_Var.max_length = 13;
      aux_String_9_Var.length = 12;
      aux_String_9_Var.values = "tl0-string.c";
      CHECK(291, String_concat(self->command, self->command_Refman, aux_String_9, aux_String_9_Refman) )
    }
  else {
      if (self == NULL) RAISE(293, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(293, 38, "used member of outdated weak reference")
      aux_String_10 = &aux_String_10_Var;
      aux_String_10_Refman = LUMI_new_ref(aux_String_10);
      if (aux_String_10_Refman == NULL) RAISE(293, 38, "insufficient memory for managed object")
      aux_String_10_Var.max_length = 6;
      aux_String_10_Var.length = 5;
      aux_String_10_Var.values = "lumi.";
      CHECK(293, String_concat(self->command, self->command_Refman, aux_String_10, aux_String_10_Refman) )
      if (self == NULL) RAISE(294, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(294, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(294, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(294, 38, "used member of outdated weak reference")
      CHECK(294, String_append(self->command, self->command_Refman, self->version) )
      if (self == NULL) RAISE(295, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(295, 38, "used member of outdated weak reference")
      aux_String_11 = &aux_String_11_Var;
      aux_String_11_Refman = LUMI_new_ref(aux_String_11);
      if (aux_String_11_Refman == NULL) RAISE(295, 38, "insufficient memory for managed object")
      aux_String_11_Var.max_length = 3;
      aux_String_11_Var.length = 2;
      aux_String_11_Var.values = ".c";
      CHECK(295, String_concat(self->command, self->command_Refman, aux_String_11, aux_String_11_Refman) )
    }
  if (self == NULL) RAISE(296, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(296, 38, "used member of outdated weak reference")
  aux_String_12 = &aux_String_12_Var;
  aux_String_12_Refman = LUMI_new_ref(aux_String_12);
  if (aux_String_12_Refman == NULL) RAISE(296, 38, "insufficient memory for managed object")
  aux_String_12_Var.max_length = 4;
  aux_String_12_Var.length = 3;
  aux_String_12_Var.values = " -I";
  CHECK(296, String_concat(self->command, self->command_Refman, aux_String_12, aux_String_12_Refman) )
  CHECK(297, lumi_M_Lumi_concat_tl_path(self, self_Refman) )
  if (self == NULL) RAISE(298, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(298, 38, "used member of outdated weak reference")
  aux_String_13 = &aux_String_13_Var;
  aux_String_13_Refman = LUMI_new_ref(aux_String_13);
  if (aux_String_13_Refman == NULL) RAISE(298, 38, "insufficient memory for managed object")
  aux_String_13_Var.max_length = 4;
  aux_String_13_Var.length = 3;
  aux_String_13_Var.values = " -o";
  CHECK(298, String_concat(self->command, self->command_Refman, aux_String_13, aux_String_13_Refman) )
  if (self == NULL) RAISE(299, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(299, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(299, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(299, 38, "used member of outdated weak reference")
  CHECK(299, lumi_M_Lumi_concat_file_name(self, self_Refman, self->command, self->command_Refman, self->output, self->output_Refman) )
  aux_String_14 = &aux_String_14_Var;
  aux_String_14_Refman = LUMI_new_ref(aux_String_14);
  if (aux_String_14_Refman == NULL) RAISE(300, 38, "insufficient memory for managed object")
  aux_String_14_Var.max_length = 18;
  aux_String_14_Var.length = 17;
  aux_String_14_Var.values = "C compiler failed";
  CHECK(300, lumi_M_Lumi_m_run_command(self, self_Refman, aux_String_14, aux_String_14_Refman) )
LUMI_cleanup:
  LUMI_dec_ref(aux_String_14_Refman);
  LUMI_dec_ref(aux_String_13_Refman);
  LUMI_dec_ref(aux_String_12_Refman);
  LUMI_dec_ref(aux_String_11_Refman);
  LUMI_dec_ref(aux_String_10_Refman);
  LUMI_dec_ref(aux_String_9_Refman);
  LUMI_dec_ref(aux_String_8_Refman);
  LUMI_dec_ref(aux_String_7_Refman);
  LUMI_dec_ref(aux_String_6_Refman);
  LUMI_dec_ref(aux_String_5_Refman);
  LUMI_dec_ref(aux_String_4_Refman);
  LUMI_dec_ref(aux_String_3_Refman);
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.m-run-program"
Returncode lumi_M_Lumi_m_run_program(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  if (self == NULL) RAISE(303, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(303, 38, "used member of outdated weak reference")
  CHECK(303, String_clear(self->command, self->command_Refman) )
  if (self == NULL) RAISE(304, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(304, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(304, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(304, 38, "used member of outdated weak reference")
  CHECK(304, lumi_M_Lumi_concat_first_file_name(self, self_Refman, self->command, self->command_Refman, self->output, self->output_Refman) )
  if (self == NULL) RAISE(305, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(305, 38, "used member of outdated weak reference")
  if (self->execute_arguments != NULL && self->execute_arguments_Refman->value != NULL) {
      if (self == NULL) RAISE(306, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(306, 38, "used member of outdated weak reference")
      aux_String_0 = &aux_String_0_Var;
      aux_String_0_Refman = LUMI_new_ref(aux_String_0);
      if (aux_String_0_Refman == NULL) RAISE(306, 38, "insufficient memory for managed object")
      aux_String_0_Var.max_length = 2;
      aux_String_0_Var.length = 1;
      aux_String_0_Var.values = " ";
      CHECK(306, String_concat(self->command, self->command_Refman, aux_String_0, aux_String_0_Refman) )
      if (self == NULL) RAISE(307, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(307, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(307, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(307, 38, "used member of outdated weak reference")
      CHECK(307, String_concat(self->command, self->command_Refman, self->execute_arguments, self->execute_arguments_Refman) )
    }
  CHECK(308, lumi_M_Lumi_m_run_command(self, self_Refman, NULL, NULL) )
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.m-run"
Returncode lumi_M_Lumi_m_run(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  CHECK(311, lumi_M_Lumi_read_input(self, self_Refman) )
  if (self == NULL) RAISE(312, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(312, 38, "used member of outdated weak reference")
  if (self->run_lumi) {
      CHECK(313, lumi_M_Lumi_m_run_lumi(self, self_Refman) )
    }
  if (self == NULL) RAISE(314, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(314, 38, "used member of outdated weak reference")
  if (self->run_c) {
      CHECK(315, lumi_M_Lumi_m_run_c(self, self_Refman) )
    }
  if (self == NULL) RAISE(316, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(316, 38, "used member of outdated weak reference")
  if (self->run_program) {
      CHECK(317, lumi_M_Lumi_m_run_program(self, self_Refman) )
    }
LUMI_cleanup:
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

void lumi_M_Lumi_Del(lumi_M_Lumi* self) {
  if (self == NULL) return;
  String_Del(self->lumi_path);
  LUMI_owner_dec_ref(self->lumi_path_Refman);
  String_Del(self->command);
  LUMI_owner_dec_ref(self->command_Refman);
  String_Del(self->external_files);
  LUMI_owner_dec_ref(self->external_files_Refman);
  String_Del(self->input_files);
  LUMI_owner_dec_ref(self->input_files_Refman);
  LUMI_dec_ref(self->main_input_Refman);
  LUMI_dec_ref(self->execute_arguments_Refman);
  LUMI_dec_ref(self->mut_Refman);
  LUMI_dec_ref(self->output_Refman);
  String_Del(self->implicit_output);
  LUMI_owner_dec_ref(self->implicit_output_Refman);
}


/* global functions body */

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "f-error-if"
Returncode lumi_M_f_error_if(Bool is_error, String* error_msg, Ref_Manager* error_msg_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(error_msg_Refman);
  if (is_error) {
    CHECK(34, Sys_println(sys, sys_Refman, error_msg, error_msg_Refman) )
    USER_RAISE(35, NULL, NULL)
  }
LUMI_cleanup:
  LUMI_dec_ref(error_msg_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "f-help"
Returncode lumi_M_f_help(void) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  CHECK(39, Sys_println(sys, sys_Refman, lumi_M_usage, lumi_M_usage_Refman) )
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(51, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 463;
  aux_String_0_Var.length = 462;
  aux_String_0_Var.values = "Options:\n  -h \t\t print help\n  -o <file> \t output file name\n  -t <module> \t compile test program for <module>\n  -c \t\t only create C file(s)\n  -l<version> \t only run C compiler for TL<version>\n  -e <file> \t external C file for C compilation\n  -p <lumipath>  path of lumi-lang repository\n  -r \t\t   run the compiled program\n  -ra <arguments>  run the compiled program with given arguments\n  -v \t\t print executed commands\n  -d \t\t only print commands without execution";
  CHECK(40, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  CHECK(52, Sys_exit(sys, sys_Refman, 0) )
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
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
#define RETURN_ERROR(value) return value;
#define LUMI_FUNC_NAME "global variable initialization"
#define LUMI_FILE_NAME "lumi.4.lm"
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(25, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 30;
  aux_String_0_Var.length = 29;
  aux_String_0_Var.values = "Usage: lumi [options] file...";
  lumi_M_usage = aux_String_0;
  lumi_M_usage_Refman = aux_String_0_Refman;
  LUMI_inc_ref(lumi_M_usage_Refman);
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME
#undef RETURN_ERROR
#define RETURN_ERROR(value) LUMI_err = value; goto LUMI_cleanup
#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "main"
  lumi_object = &lumi_object_Var;
  lumi_object_Refman = LUMI_new_ref(lumi_object);
  if (lumi_object_Refman == NULL) RAISE(321, 38, "insufficient memory for managed object")
  CHECK(321, lumi_M_Lumi_new(lumi_object, lumi_object_Refman) )
  CHECK(322, lumi_M_Lumi_m_run(lumi_object, lumi_object_Refman) )
LUMI_cleanup:
  LUMI_dec_ref(lumi_object_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

MAIN_FUNC
