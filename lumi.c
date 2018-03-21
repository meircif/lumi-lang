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
  Bool explicit_output;
  Bool verbose;
  String* implicit_output;
  Ref_Manager* implicit_output_Refman;
  String* output;
  Ref_Manager* output_Refman;
  String* mut;
  Ref_Manager* mut_Refman;
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

Returncode lumi_M_Lumi_get_opt_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman, Int* index, String** value, Ref_Manager** value_Refman);

Returncode lumi_M_Lumi_check_opt_param_error(lumi_M_Lumi* self, Ref_Manager* self_Refman, Bool is_error, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman);

Returncode lumi_M_Lumi_check_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* value, Ref_Manager* value_Refman);

Returncode lumi_M_Lumi_concat_lumi_output(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_concat_file_name(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* target, Ref_Manager* target_Refman, String* name, Ref_Manager* name_Refman);

Returncode lumi_M_Lumi_concat_tl_path(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_read_input(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_m_run_lumi(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_m_run_c(lumi_M_Lumi* self, Ref_Manager* self_Refman);

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
  if (self == NULL) RAISE(69, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(69, 38, "used member of outdated weak reference")
  self->run_lumi = true;
  if (self == NULL) RAISE(70, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(70, 38, "used member of outdated weak reference")
  self->run_c = true;
  aux_String_0 = LUMI_new_string(lumi_M_MAX_COMMNAD_SIZE);
  if (aux_String_0 == NULL) RAISE(71, 49, "insufficient memory for object dynamic allocation")
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(71, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(71, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(71, 38, "used member of outdated weak reference")
  String_Del(self->input_files);
  LUMI_owner_dec_ref(self->input_files_Refman);
  self->input_files_Refman = aux_String_0_Refman;
  self->input_files = aux_String_0;
  aux_String_0 = NULL;
  aux_String_0_Refman = NULL;
  aux_String_1 = LUMI_new_string(lumi_M_MAX_COMMNAD_SIZE);
  if (aux_String_1 == NULL) RAISE(72, 49, "insufficient memory for object dynamic allocation")
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(72, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(72, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(72, 38, "used member of outdated weak reference")
  String_Del(self->external_files);
  LUMI_owner_dec_ref(self->external_files_Refman);
  self->external_files_Refman = aux_String_1_Refman;
  self->external_files = aux_String_1;
  aux_String_1 = NULL;
  aux_String_1_Refman = NULL;
  aux_String_2 = LUMI_new_string(lumi_M_MAX_COMMNAD_SIZE);
  if (aux_String_2 == NULL) RAISE(73, 49, "insufficient memory for object dynamic allocation")
  aux_String_2_Refman = LUMI_new_ref(aux_String_2);
  if (aux_String_2_Refman == NULL) RAISE(73, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(73, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(73, 38, "used member of outdated weak reference")
  String_Del(self->command);
  LUMI_owner_dec_ref(self->command_Refman);
  self->command_Refman = aux_String_2_Refman;
  self->command = aux_String_2;
  aux_String_2 = NULL;
  aux_String_2_Refman = NULL;
  aux_String_3 = LUMI_new_string(lumi_M_MAX_COMMNAD_SIZE);
  if (aux_String_3 == NULL) RAISE(74, 49, "insufficient memory for object dynamic allocation")
  aux_String_3_Refman = LUMI_new_ref(aux_String_3);
  if (aux_String_3_Refman == NULL) RAISE(74, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(74, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(74, 38, "used member of outdated weak reference")
  String_Del(self->lumi_path);
  LUMI_owner_dec_ref(self->lumi_path_Refman);
  self->lumi_path_Refman = aux_String_3_Refman;
  self->lumi_path = aux_String_3;
  aux_String_3 = NULL;
  aux_String_3_Refman = NULL;
  if (self == NULL) RAISE(75, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(75, 38, "used member of outdated weak reference")
  self->path_separator = '/';
  if (self == NULL) RAISE(76, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(76, 38, "used member of outdated weak reference")
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
  if (self == NULL) RAISE(79, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(79, 38, "used member of outdated weak reference")
  if (self->verbose) {
      if (self == NULL) RAISE(80, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(80, 38, "used member of outdated weak reference")
      CHECK(80, Sys_println(sys, sys_Refman, self->command, self->command_Refman) )
    }
  if (self == NULL) RAISE(81, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(81, 38, "used member of outdated weak reference")
  CHECK(81, Sys_system(sys, sys_Refman, self->command, self->command_Refman, &(aux_Int_0)) )
  if (aux_Int_0 != 0) {
      CHECK(82, Sys_println(sys, sys_Refman, error_msg, error_msg_Refman) )
      USER_RAISE(83, NULL, NULL)
    }
LUMI_cleanup:
  LUMI_dec_ref(error_msg_Refman);
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
  if (sys == NULL) RAISE(88, 27, "used member of empty object")
  if (sys_Refman->value == NULL) RAISE(88, 38, "used member of outdated weak reference")
  if (sys->argv == NULL) RAISE(88, 27, "used member of empty object")
  if (sys->argv_Refman->value == NULL) RAISE(88, 38, "used member of outdated weak reference")
  CHECK(87, lumi_M_Lumi_check_opt_param_error(self, self_Refman, (*index) >= (sys->argv->length - 1), option, option_Refman, param, param_Refman) )
  *index += 1;
  if (sys == NULL) RAISE(90, 27, "used member of empty object")
  if (sys_Refman->value == NULL) RAISE(90, 38, "used member of outdated weak reference")
  if (sys->argv == NULL) RAISE(90, 29, "empty object used as sequence")
  if (sys->argv_Refman->value == NULL) RAISE(90, 40, "outdated weak reference used as sequence")
  if ((*index) < 0 || (*index) >= (sys->argv)->length) RAISE(90, 25, "slice index out of bounds")
  LUMI_dec_ref(*value_Refman);
  *value_Refman = sys->argv_Refman;
  LUMI_inc_ref(*value_Refman);
  *value = ((String*)((sys->argv)->values)) + *index;
  if (*value == NULL) RAISE(91, 29, "empty object used as sequence")
  if ((*value_Refman)->value == NULL) RAISE(91, 40, "outdated weak reference used as sequence")
  if ((0) < 0 || (0) >= ((*value))->length) RAISE(91, 25, "slice index out of bounds")
  CHECK(91, lumi_M_Lumi_check_opt_param_error(self, self_Refman, ((((*value))->values)[0]) == '-', option, option_Refman, param, param_Refman) )
  CHECK(92, lumi_M_Lumi_check_param(self, self_Refman, *value, *value_Refman) )
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
      if (aux_String_0_Refman == NULL) RAISE(97, 38, "insufficient memory for managed object")
      aux_String_0_Var.max_length = 16;
      aux_String_0_Var.length = 15;
      aux_String_0_Var.values = "error: missing ";
      CHECK(97, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
      CHECK(98, Sys_print(sys, sys_Refman, param, param_Refman) )
      aux_String_1 = &aux_String_1_Var;
      aux_String_1_Refman = LUMI_new_ref(aux_String_1);
      if (aux_String_1_Refman == NULL) RAISE(99, 38, "insufficient memory for managed object")
      aux_String_1_Var.max_length = 9;
      aux_String_1_Var.length = 8;
      aux_String_1_Var.values = " after \"";
      CHECK(99, Sys_print(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
      CHECK(100, Sys_print(sys, sys_Refman, option, option_Refman) )
      aux_String_2 = &aux_String_2_Var;
      aux_String_2_Refman = LUMI_new_ref(aux_String_2);
      if (aux_String_2_Refman == NULL) RAISE(101, 38, "insufficient memory for managed object")
      aux_String_2_Var.max_length = 7;
      aux_String_2_Var.length = 6;
      aux_String_2_Var.values = "\" flag";
      CHECK(101, Sys_println(sys, sys_Refman, aux_String_2, aux_String_2_Refman) )
      USER_RAISE(102, NULL, NULL)
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
  CHECK(105, String_has(value, value_Refman, '"', &(aux_Bool_0)) )
  if (aux_Bool_0) {
      aux_String_0 = &aux_String_0_Var;
      aux_String_0_Refman = LUMI_new_ref(aux_String_0);
      if (aux_String_0_Refman == NULL) RAISE(106, 38, "insufficient memory for managed object")
      aux_String_0_Var.max_length = 42;
      aux_String_0_Var.length = 41;
      aux_String_0_Var.values = "error: illegal \" character in parameter '";
      CHECK(106, Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
      CHECK(107, Sys_print(sys, sys_Refman, value, value_Refman) )
      aux_String_1 = &aux_String_1_Var;
      aux_String_1_Refman = LUMI_new_ref(aux_String_1);
      if (aux_String_1_Refman == NULL) RAISE(108, 38, "insufficient memory for managed object")
      aux_String_1_Var.max_length = 2;
      aux_String_1_Var.length = 1;
      aux_String_1_Var.values = "'";
      CHECK(108, Sys_println(sys, sys_Refman, aux_String_1, aux_String_1_Refman) )
      USER_RAISE(109, NULL, NULL)
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
  if (self == NULL) RAISE(112, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(112, 38, "used member of outdated weak reference")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(112, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = " \"";
  CHECK(112, String_concat(self->command, self->command_Refman, aux_String_0, aux_String_0_Refman) )
  if (self == NULL) RAISE(113, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(113, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(113, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(113, 38, "used member of outdated weak reference")
  CHECK(113, String_concat(self->command, self->command_Refman, self->output, self->output_Refman) )
  if (self == NULL) RAISE(114, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(114, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(114, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(114, 38, "used member of outdated weak reference")
  if (self->run_c || (! self->explicit_output)) {
      if (self == NULL) RAISE(115, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(115, 38, "used member of outdated weak reference")
      aux_String_1 = &aux_String_1_Var;
      aux_String_1_Refman = LUMI_new_ref(aux_String_1);
      if (aux_String_1_Refman == NULL) RAISE(115, 38, "insufficient memory for managed object")
      aux_String_1_Var.max_length = 3;
      aux_String_1_Var.length = 2;
      aux_String_1_Var.values = ".c";
      CHECK(115, String_concat(self->command, self->command_Refman, aux_String_1, aux_String_1_Refman) )
    }
  if (self == NULL) RAISE(116, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(116, 38, "used member of outdated weak reference")
  aux_String_2 = &aux_String_2_Var;
  aux_String_2_Refman = LUMI_new_ref(aux_String_2);
  if (aux_String_2_Refman == NULL) RAISE(116, 38, "insufficient memory for managed object")
  aux_String_2_Var.max_length = 2;
  aux_String_2_Var.length = 1;
  aux_String_2_Var.values = "\"";
  CHECK(116, String_concat(self->command, self->command_Refman, aux_String_2, aux_String_2_Refman) )
LUMI_cleanup:
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
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
  String aux_String_1_Var = {0};
  String* aux_String_1 = NULL;
  Ref_Manager* aux_String_1_Refman = NULL;
  LUMI_inc_ref(target_Refman);
  LUMI_inc_ref(name_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(119, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = " \"";
  CHECK(119, String_concat(target, target_Refman, aux_String_0, aux_String_0_Refman) )
  CHECK(120, String_concat(target, target_Refman, name, name_Refman) )
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(121, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 2;
  aux_String_1_Var.length = 1;
  aux_String_1_Var.values = "\"";
  CHECK(121, String_concat(target, target_Refman, aux_String_1, aux_String_1_Refman) )
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
#define LUMI_FUNC_NAME "Lumi.concat-tl-path"
Returncode lumi_M_Lumi_concat_tl_path(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  if (self == NULL) RAISE(124, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(124, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(124, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(124, 38, "used member of outdated weak reference")
  CHECK(124, String_concat(self->command, self->command_Refman, self->lumi_path, self->lumi_path_Refman) )
  if (self == NULL) RAISE(125, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(125, 38, "used member of outdated weak reference")
  if (! self->lumi_path_ends_with_separator) {
      if (self == NULL) RAISE(126, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(126, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(126, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(126, 38, "used member of outdated weak reference")
      CHECK(126, String_append(self->command, self->command_Refman, self->path_separator) )
    }
  if (self == NULL) RAISE(127, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(127, 38, "used member of outdated weak reference")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(127, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = "TL";
  CHECK(127, String_concat(self->command, self->command_Refman, aux_String_0, aux_String_0_Refman) )
  if (self == NULL) RAISE(128, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(128, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(128, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(128, 38, "used member of outdated weak reference")
  CHECK(128, String_append(self->command, self->command_Refman, self->version) )
  if (self == NULL) RAISE(129, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(129, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(129, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(129, 38, "used member of outdated weak reference")
  CHECK(129, String_append(self->command, self->command_Refman, self->path_separator) )
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
  String* aux_String_17 = NULL;
  Ref_Manager* aux_String_17_Refman = NULL;
  if (sys == NULL) RAISE(132, 27, "used member of empty object")
  if (sys_Refman->value == NULL) RAISE(132, 38, "used member of outdated weak reference")
  if (sys->argv == NULL) RAISE(132, 27, "used member of empty object")
  if (sys->argv_Refman->value == NULL) RAISE(132, 38, "used member of outdated weak reference")
  CHECK(132, lumi_M_f_error_if(sys->argv->length < 2, lumi_M_usage, lumi_M_usage_Refman) )
  for (index = 1; index < sys->argv->length; ++index) {
      if (sys == NULL) RAISE(138, 27, "used member of empty object")
      if (sys_Refman->value == NULL) RAISE(138, 38, "used member of outdated weak reference")
      if (sys->argv == NULL) RAISE(138, 29, "empty object used as sequence")
      if (sys->argv_Refman->value == NULL) RAISE(138, 40, "outdated weak reference used as sequence")
      if ((index) < 0 || (index) >= (sys->argv)->length) RAISE(138, 25, "slice index out of bounds")
      arg = ((String*)((sys->argv)->values)) + index;
      arg_Refman = sys->argv_Refman;
      LUMI_inc_ref(arg_Refman);
      if (arg == NULL) RAISE(139, 29, "empty object used as sequence")
      if (arg_Refman->value == NULL) RAISE(139, 40, "outdated weak reference used as sequence")
      if ((0) < 0 || (0) >= (arg)->length) RAISE(139, 25, "slice index out of bounds")
      if ((((arg)->values)[0]) == '-') {
        if (arg == NULL) RAISE(140, 27, "used member of empty object")
        if (arg_Refman->value == NULL) RAISE(140, 38, "used member of outdated weak reference")
        if (arg->length < 2) {
          aux_String_0 = &aux_String_0_Var;
          aux_String_0_Refman = LUMI_new_ref(aux_String_0);
          if (aux_String_0_Refman == NULL) RAISE(141, 38, "insufficient memory for managed object")
          aux_String_0_Var.max_length = 26;
          aux_String_0_Var.length = 25;
          aux_String_0_Var.values = "warning: unknown flag \"-\"";
          CHECK(141, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
        }
        else {
          if (arg == NULL) RAISE(143, 29, "empty object used as sequence")
          if (arg_Refman->value == NULL) RAISE(143, 40, "outdated weak reference used as sequence")
          if ((1) < 0 || (1) >= (arg)->length) RAISE(143, 25, "slice index out of bounds")
          op = ((arg)->values)[1];
          if (op == 'h') {
            CHECK(145, lumi_M_f_help() )
          }
          else {
            if (op == 'o') {
              aux_String_1 = &aux_String_1_Var;
              aux_String_1_Refman = LUMI_new_ref(aux_String_1);
              if (aux_String_1_Refman == NULL) RAISE(147, 38, "insufficient memory for managed object")
              aux_String_1_Var.max_length = 2;
              aux_String_1_Var.length = 1;
              aux_String_1_Var.values = "o";
              aux_String_2 = &aux_String_2_Var;
              aux_String_2_Refman = LUMI_new_ref(aux_String_2);
              if (aux_String_2_Refman == NULL) RAISE(147, 38, "insufficient memory for managed object")
              aux_String_2_Var.max_length = 10;
              aux_String_2_Var.length = 9;
              aux_String_2_Var.values = "file name";
              if (self == NULL) RAISE(148, 27, "used member of empty object")
              if (self_Refman->value == NULL) RAISE(148, 38, "used member of outdated weak reference")
              CHECK(147, lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_1, aux_String_1_Refman, aux_String_2, aux_String_2_Refman, &(index), &(self->output), &(self->output_Refman)) )
              if (self == NULL) RAISE(149, 27, "used member of empty object")
              if (self_Refman->value == NULL) RAISE(149, 38, "used member of outdated weak reference")
              self->explicit_output = true;
            }
            else {
              if (op == 't') {
                aux_String_3 = &aux_String_3_Var;
                aux_String_3_Refman = LUMI_new_ref(aux_String_3);
                if (aux_String_3_Refman == NULL) RAISE(151, 38, "insufficient memory for managed object")
                aux_String_3_Var.max_length = 2;
                aux_String_3_Var.length = 1;
                aux_String_3_Var.values = "t";
                aux_String_4 = &aux_String_4_Var;
                aux_String_4_Refman = LUMI_new_ref(aux_String_4);
                if (aux_String_4_Refman == NULL) RAISE(151, 38, "insufficient memory for managed object")
                aux_String_4_Var.max_length = 12;
                aux_String_4_Var.length = 11;
                aux_String_4_Var.values = "module name";
                if (self == NULL) RAISE(152, 27, "used member of empty object")
                if (self_Refman->value == NULL) RAISE(152, 38, "used member of outdated weak reference")
                CHECK(151, lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_3, aux_String_3_Refman, aux_String_4, aux_String_4_Refman, &(index), &(self->mut), &(self->mut_Refman)) )
              }
              else {
                if (op == 'e') {
                  if (self == NULL) RAISE(155, 27, "used member of empty object")
                  if (self_Refman->value == NULL) RAISE(155, 38, "used member of outdated weak reference")
                  aux_String_5 = &aux_String_5_Var;
                  aux_String_5_Refman = LUMI_new_ref(aux_String_5);
                  if (aux_String_5_Refman == NULL) RAISE(156, 38, "insufficient memory for managed object")
                  aux_String_5_Var.max_length = 2;
                  aux_String_5_Var.length = 1;
                  aux_String_5_Var.values = "e";
                  aux_String_6 = &aux_String_6_Var;
                  aux_String_6_Refman = LUMI_new_ref(aux_String_6);
                  if (aux_String_6_Refman == NULL) RAISE(156, 38, "insufficient memory for managed object")
                  aux_String_6_Var.max_length = 10;
                  aux_String_6_Var.length = 9;
                  aux_String_6_Var.values = "file name";
                  CHECK(156, lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_5, aux_String_5_Refman, aux_String_6, aux_String_6_Refman, &(index), &(aux_String_7), &(aux_String_7_Refman)) )
                  CHECK(154, lumi_M_Lumi_concat_file_name(self, self_Refman, self->external_files, self->external_files_Refman, aux_String_7, aux_String_7_Refman) )
                }
                else {
                  if (op == 'c') {
                    if (self == NULL) RAISE(159, 27, "used member of empty object")
                    if (self_Refman->value == NULL) RAISE(159, 38, "used member of outdated weak reference")
                    self->run_c = false;
                  }
                  else {
                    if (arg == NULL) RAISE(160, 27, "used member of empty object")
                    if (arg_Refman->value == NULL) RAISE(160, 38, "used member of outdated weak reference")
                    if ((op == 'l') && (arg->length >= 2)) {
                      if (self == NULL) RAISE(161, 27, "used member of empty object")
                      if (self_Refman->value == NULL) RAISE(161, 38, "used member of outdated weak reference")
                      self->run_lumi = false;
                      if (arg == NULL) RAISE(162, 29, "empty object used as sequence")
                      if (arg_Refman->value == NULL) RAISE(162, 40, "outdated weak reference used as sequence")
                      if ((2) < 0 || (2) >= (arg)->length) RAISE(162, 25, "slice index out of bounds")
                      if (self == NULL) RAISE(162, 27, "used member of empty object")
                      if (self_Refman->value == NULL) RAISE(162, 38, "used member of outdated weak reference")
                      self->version = ((arg)->values)[2];
                    }
                    else {
                      if (op == 'v') {
                        if (self == NULL) RAISE(164, 27, "used member of empty object")
                        if (self_Refman->value == NULL) RAISE(164, 38, "used member of outdated weak reference")
                        self->verbose = true;
                      }
                      else {
                        aux_String_8 = &aux_String_8_Var;
                        aux_String_8_Refman = LUMI_new_ref(aux_String_8);
                        if (aux_String_8_Refman == NULL) RAISE(166, 38, "insufficient memory for managed object")
                        aux_String_8_Var.max_length = 24;
                        aux_String_8_Var.length = 23;
                        aux_String_8_Var.values = "warning: unknown flag \"";
                        CHECK(166, Sys_print(sys, sys_Refman, aux_String_8, aux_String_8_Refman) )
                        CHECK(167, Sys_print(sys, sys_Refman, arg, arg_Refman) )
                        aux_String_9 = &aux_String_9_Var;
                        aux_String_9_Refman = LUMI_new_ref(aux_String_9);
                        if (aux_String_9_Refman == NULL) RAISE(168, 38, "insufficient memory for managed object")
                        aux_String_9_Var.max_length = 2;
                        aux_String_9_Var.length = 1;
                        aux_String_9_Var.values = "\"";
                        CHECK(168, Sys_println(sys, sys_Refman, aux_String_9, aux_String_9_Refman) )
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
        CHECK(170, lumi_M_Lumi_check_param(self, self_Refman, arg, arg_Refman) )
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
        if (self == NULL) RAISE(174, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(174, 38, "used member of outdated weak reference")
        CHECK(174, lumi_M_Lumi_concat_file_name(self, self_Refman, self->input_files, self->input_files_Refman, arg, arg_Refman) )
        input_files_num += 1;
      }
    }
  aux_String_10 = &aux_String_10_Var;
  aux_String_10_Refman = LUMI_new_ref(aux_String_10);
  if (aux_String_10_Refman == NULL) RAISE(177, 38, "insufficient memory for managed object")
  aux_String_10_Var.max_length = 22;
  aux_String_10_Var.length = 21;
  aux_String_10_Var.values = "error: no input files";
  CHECK(177, lumi_M_f_error_if(input_files_num == 0, aux_String_10, aux_String_10_Refman) )
  if (self == NULL) RAISE(179, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(179, 38, "used member of outdated weak reference")
  if (self->run_lumi) {
      if (first_input == NULL) RAISE(181, 27, "used member of empty object")
      if (first_input_Refman->value == NULL) RAISE(181, 38, "used member of outdated weak reference")
      aux_String_11 = &aux_String_11_Var;
      aux_String_11_Refman = LUMI_new_ref(aux_String_11);
      if (aux_String_11_Refman == NULL) RAISE(182, 38, "insufficient memory for managed object")
      aux_String_11_Var.max_length = 32;
      aux_String_11_Var.length = 31;
      aux_String_11_Var.values = "error: Lumi file name too short";
      CHECK(180, lumi_M_f_error_if(first_input->length < 6, aux_String_11, aux_String_11_Refman) )
      if (first_input == NULL) RAISE(183, 27, "used member of empty object")
      if (first_input_Refman->value == NULL) RAISE(183, 38, "used member of outdated weak reference")
      if (first_input == NULL) RAISE(183, 29, "empty object used as sequence")
      if (first_input_Refman->value == NULL) RAISE(183, 40, "outdated weak reference used as sequence")
      if ((first_input->length - 4) < 0 || (first_input->length - 4) >= (first_input)->length) RAISE(183, 25, "slice index out of bounds")
      if (self == NULL) RAISE(183, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(183, 38, "used member of outdated weak reference")
      self->version = ((first_input)->values)[first_input->length - 4];
    }
  if (self == NULL) RAISE(184, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(184, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(184, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(184, 38, "used member of outdated weak reference")
  if ((self->version < '0') || (self->version > '4')) {
      aux_String_12 = &aux_String_12_Var;
      aux_String_12_Refman = LUMI_new_ref(aux_String_12);
      if (aux_String_12_Refman == NULL) RAISE(185, 38, "insufficient memory for managed object")
      aux_String_12_Var.max_length = 30;
      aux_String_12_Var.length = 29;
      aux_String_12_Var.values = "error: unsupported version TL";
      CHECK(185, Sys_print(sys, sys_Refman, aux_String_12, aux_String_12_Refman) )
      version_string = &version_string_Var;
      version_string_Var.values = version_string_Values;
      version_string_Refman = LUMI_new_ref(version_string);
      if (version_string_Refman == NULL) RAISE(186, 38, "insufficient memory for managed object")
      if (self == NULL) RAISE(187, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(187, 38, "used member of outdated weak reference")
      CHECK(187, String_append(version_string, version_string_Refman, self->version) )
      CHECK(188, Sys_println(sys, sys_Refman, version_string, version_string_Refman) )
      USER_RAISE(189, NULL, NULL)
    }
  if (self == NULL) RAISE(191, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(191, 38, "used member of outdated weak reference")
  aux_String_13 = &aux_String_13_Var;
  aux_String_13_Refman = LUMI_new_ref(aux_String_13);
  if (aux_String_13_Refman == NULL) RAISE(192, 38, "insufficient memory for managed object")
  aux_String_13_Var.max_length = 47;
  aux_String_13_Var.length = 46;
  aux_String_13_Var.values = "error: multiple files not supported before TL2";
  CHECK(190, lumi_M_f_error_if((self->version < '2') && (input_files_num > 1), aux_String_13, aux_String_13_Refman) )
  if (self == NULL) RAISE(195, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(195, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(195, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(195, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(194, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(194, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(194, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(194, 38, "used member of outdated weak reference")
  aux_String_14 = &aux_String_14_Var;
  aux_String_14_Refman = LUMI_new_ref(aux_String_14);
  if (aux_String_14_Refman == NULL) RAISE(196, 38, "insufficient memory for managed object")
  aux_String_14_Var.max_length = 49;
  aux_String_14_Var.length = 48;
  aux_String_14_Var.values = "error: cannot specify C output file in TL2 & TL3";
  CHECK(193, lumi_M_f_error_if((((self->version >= '2') && (self->version <= '3')) && self->explicit_output) && (! self->run_c), aux_String_14, aux_String_14_Refman) )
  if (self == NULL) RAISE(198, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(198, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(198, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(198, 38, "used member of outdated weak reference")
  aux_String_15 = &aux_String_15_Var;
  aux_String_15_Refman = LUMI_new_ref(aux_String_15);
  if (aux_String_15_Refman == NULL) RAISE(199, 38, "insufficient memory for managed object")
  aux_String_15_Var.max_length = 40;
  aux_String_15_Var.length = 39;
  aux_String_15_Var.values = "error: testing not supported before TL4";
  CHECK(197, lumi_M_f_error_if((self->version < '4') && (self->mut != NULL && self->mut_Refman->value != NULL), aux_String_15, aux_String_15_Refman) )
  if (self == NULL) RAISE(200, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(200, 38, "used member of outdated weak reference")
  if (self->version <= '2') {
      if (self == NULL) RAISE(201, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(201, 38, "used member of outdated weak reference")
      LUMI_dec_ref(self->main_input_Refman);
      self->main_input_Refman = last_input_Refman;
      LUMI_inc_ref(self->main_input_Refman);
      self->main_input = last_input;
    }
  else {
      if (self == NULL) RAISE(203, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(203, 38, "used member of outdated weak reference")
      LUMI_dec_ref(self->main_input_Refman);
      self->main_input_Refman = first_input_Refman;
      LUMI_inc_ref(self->main_input_Refman);
      self->main_input = first_input;
    }
  if (self == NULL) RAISE(205, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(205, 38, "used member of outdated weak reference")
  if (! (self->output != NULL && self->output_Refman->value != NULL)) {
      suffix_length = 2;
      if (self == NULL) RAISE(207, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(207, 38, "used member of outdated weak reference")
      if (self->run_lumi) {
        suffix_length = 5;
      }
      if (self == NULL) RAISE(210, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(210, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(210, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(210, 38, "used member of outdated weak reference")
      if (self->main_input == NULL) RAISE(210, 27, "used member of empty object")
      if (self->main_input_Refman->value == NULL) RAISE(210, 38, "used member of outdated weak reference")
      aux_String_16 = &aux_String_16_Var;
      aux_String_16_Refman = LUMI_new_ref(aux_String_16);
      if (aux_String_16_Refman == NULL) RAISE(210, 38, "insufficient memory for managed object")
      aux_String_16_Var.length = self->main_input->length - suffix_length;
      aux_String_16_Var.max_length = aux_String_16_Var.length + 1;
      aux_String_16_Var.values = (self->main_input)->values + (0);
      if (self->main_input == NULL) RAISE(210, 29, "empty object used as sequence")
      if (self->main_input_Refman->value == NULL) RAISE(210, 40, "outdated weak reference used as sequence")
      if ((0) < 0 || (self->main_input->length - suffix_length) < 0 || (0) + (self->main_input->length - suffix_length) > (self->main_input)->length) RAISE(210, 25, "slice index out of bounds")
      if (self == NULL) RAISE(209, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(209, 38, "used member of outdated weak reference")
      if (self->main_input == NULL) RAISE(209, 27, "used member of empty object")
      if (self->main_input_Refman->value == NULL) RAISE(209, 38, "used member of outdated weak reference")
      aux_String_17 = LUMI_new_string(self->main_input->length);
      if (aux_String_17 == NULL) RAISE(209, 49, "insufficient memory for object dynamic allocation")
      aux_String_17_Refman = LUMI_new_ref(aux_String_17);
      if (aux_String_17_Refman == NULL) RAISE(209, 38, "insufficient memory for managed object")
      CHECK(209, String_new(aux_String_17, aux_String_17_Refman, aux_String_16, self->main_input_Refman) )
      if (self == NULL) RAISE(209, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(209, 38, "used member of outdated weak reference")
      String_Del(self->implicit_output);
      LUMI_owner_dec_ref(self->implicit_output_Refman);
      self->implicit_output_Refman = aux_String_17_Refman;
      self->implicit_output = aux_String_17;
      aux_String_17 = NULL;
      aux_String_17_Refman = NULL;
      if (self == NULL) RAISE(211, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(211, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(211, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(211, 38, "used member of outdated weak reference")
      LUMI_dec_ref(self->output_Refman);
      self->output_Refman = self->implicit_output_Refman;
      LUMI_inc_ref(self->output_Refman);
      self->output = self->implicit_output;
    }
LUMI_cleanup:
  String_Del(aux_String_17);
  LUMI_owner_dec_ref(aux_String_17_Refman);
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
  if (self == NULL) RAISE(215, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(215, 38, "used member of outdated weak reference")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(215, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = "tl";
  CHECK(215, String_new(self->command, self->command_Refman, aux_String_0, aux_String_0_Refman) )
  if (self == NULL) RAISE(216, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(216, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(216, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(216, 38, "used member of outdated weak reference")
  CHECK(216, String_append(self->command, self->command_Refman, self->version) )
  if (self == NULL) RAISE(217, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(217, 38, "used member of outdated weak reference")
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(217, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 10;
  aux_String_1_Var.length = 9;
  aux_String_1_Var.values = "-compiler";
  CHECK(217, String_concat(self->command, self->command_Refman, aux_String_1, aux_String_1_Refman) )
  if (self == NULL) RAISE(218, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(218, 38, "used member of outdated weak reference")
  if (self->version >= '4') {
      if (self == NULL) RAISE(219, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(219, 38, "used member of outdated weak reference")
      if (self->mut != NULL && self->mut_Refman->value != NULL) {
        if (self == NULL) RAISE(220, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(220, 38, "used member of outdated weak reference")
        aux_String_2 = &aux_String_2_Var;
        aux_String_2_Refman = LUMI_new_ref(aux_String_2);
        if (aux_String_2_Refman == NULL) RAISE(220, 38, "insufficient memory for managed object")
        aux_String_2_Var.max_length = 4;
        aux_String_2_Var.length = 3;
        aux_String_2_Var.values = " -t";
        CHECK(220, String_concat(self->command, self->command_Refman, aux_String_2, aux_String_2_Refman) )
        if (self == NULL) RAISE(221, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(221, 38, "used member of outdated weak reference")
        if (self == NULL) RAISE(221, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(221, 38, "used member of outdated weak reference")
        CHECK(221, lumi_M_Lumi_concat_file_name(self, self_Refman, self->command, self->command_Refman, self->mut, self->mut_Refman) )
      }
      CHECK(222, lumi_M_Lumi_concat_lumi_output(self, self_Refman) )
    }
  if (self == NULL) RAISE(223, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(223, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(223, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(223, 38, "used member of outdated weak reference")
  CHECK(223, String_concat(self->command, self->command_Refman, self->input_files, self->input_files_Refman) )
  if (self == NULL) RAISE(224, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(224, 38, "used member of outdated weak reference")
  if (self->version <= '1') {
      CHECK(225, lumi_M_Lumi_concat_lumi_output(self, self_Refman) )
    }
  aux_String_3 = &aux_String_3_Var;
  aux_String_3_Refman = LUMI_new_ref(aux_String_3);
  if (aux_String_3_Refman == NULL) RAISE(226, 38, "insufficient memory for managed object")
  aux_String_3_Var.max_length = 21;
  aux_String_3_Var.length = 20;
  aux_String_3_Var.values = "Lumi compiler failed";
  CHECK(226, lumi_M_Lumi_m_run_command(self, self_Refman, aux_String_3, aux_String_3_Refman) )
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
  if (aux_String_0_Refman == NULL) RAISE(229, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = "CC";
  if (self == NULL) RAISE(229, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(229, 38, "used member of outdated weak reference")
  CHECK(229, Sys_getenv(sys, sys_Refman, aux_String_0, aux_String_0_Refman, self->command, self->command_Refman, &(aux_Bool_0)) )
  if (! aux_Bool_0) {
      if (self == NULL) RAISE(230, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(230, 38, "used member of outdated weak reference")
      aux_String_1 = &aux_String_1_Var;
      aux_String_1_Refman = LUMI_new_ref(aux_String_1);
      if (aux_String_1_Refman == NULL) RAISE(230, 38, "insufficient memory for managed object")
      aux_String_1_Var.max_length = 4;
      aux_String_1_Var.length = 3;
      aux_String_1_Var.values = "gcc";
      CHECK(230, String_new(self->command, self->command_Refman, aux_String_1, aux_String_1_Refman) )
    }
  if (self == NULL) RAISE(232, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(232, 38, "used member of outdated weak reference")
  if (self->lumi_path == NULL) RAISE(232, 27, "used member of empty object")
  if (self->lumi_path_Refman->value == NULL) RAISE(232, 38, "used member of outdated weak reference")
  aux_String_2 = &aux_String_2_Var;
  aux_String_2_Refman = LUMI_new_ref(aux_String_2);
  if (aux_String_2_Refman == NULL) RAISE(231, 38, "insufficient memory for managed object")
  aux_String_2_Var.max_length = 9;
  aux_String_2_Var.length = 8;
  aux_String_2_Var.values = "LUMIPATH";
  if (self == NULL) RAISE(231, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(231, 38, "used member of outdated weak reference")
  CHECK(231, Sys_getenv(sys, sys_Refman, aux_String_2, aux_String_2_Refman, self->lumi_path, self->lumi_path_Refman, &(aux_Bool_1)) )
  if (aux_Bool_1 && (self->lumi_path->length > 0)) {
      if (self == NULL) RAISE(233, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(233, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(233, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(233, 38, "used member of outdated weak reference")
      if (self->lumi_path == NULL) RAISE(233, 27, "used member of empty object")
      if (self->lumi_path_Refman->value == NULL) RAISE(233, 38, "used member of outdated weak reference")
      if (self->lumi_path == NULL) RAISE(233, 29, "empty object used as sequence")
      if (self->lumi_path_Refman->value == NULL) RAISE(233, 40, "outdated weak reference used as sequence")
      if ((self->lumi_path->length - 1) < 0 || (self->lumi_path->length - 1) >= (self->lumi_path)->length) RAISE(233, 25, "slice index out of bounds")
      last = ((self->lumi_path)->values)[self->lumi_path->length - 1];
      if (last == '\\') {
        if (self == NULL) RAISE(235, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(235, 38, "used member of outdated weak reference")
        self->path_separator = '\\';
      }
      if (self == NULL) RAISE(236, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(236, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(236, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(236, 38, "used member of outdated weak reference")
      self->lumi_path_ends_with_separator = last == self->path_separator;
    }
  if (self == NULL) RAISE(237, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(237, 38, "used member of outdated weak reference")
  aux_String_3 = &aux_String_3_Var;
  aux_String_3_Refman = LUMI_new_ref(aux_String_3);
  if (aux_String_3_Refman == NULL) RAISE(237, 38, "insufficient memory for managed object")
  aux_String_3_Var.max_length = 4;
  aux_String_3_Var.length = 3;
  aux_String_3_Var.values = " -g";
  CHECK(237, String_concat(self->command, self->command_Refman, aux_String_3, aux_String_3_Refman) )
  if (self == NULL) RAISE(238, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(238, 38, "used member of outdated weak reference")
  if (self->run_lumi) {
      if (self == NULL) RAISE(239, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(239, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(239, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(239, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(239, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(239, 38, "used member of outdated weak reference")
      if (((self->version >= '2') && (self->version <= '3')) && self->explicit_output) {
        if (self == NULL) RAISE(240, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(240, 38, "used member of outdated weak reference")
        aux_String_4 = &aux_String_4_Var;
        aux_String_4_Refman = LUMI_new_ref(aux_String_4);
        if (aux_String_4_Refman == NULL) RAISE(240, 38, "insufficient memory for managed object")
        aux_String_4_Var.max_length = 3;
        aux_String_4_Var.length = 2;
        aux_String_4_Var.values = " \"";
        CHECK(240, String_concat(self->command, self->command_Refman, aux_String_4, aux_String_4_Refman) )
        if (self == NULL) RAISE(241, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(241, 38, "used member of outdated weak reference")
        if (self == NULL) RAISE(242, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(242, 38, "used member of outdated weak reference")
        if (self == NULL) RAISE(242, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(242, 38, "used member of outdated weak reference")
        if (self->main_input == NULL) RAISE(242, 27, "used member of empty object")
        if (self->main_input_Refman->value == NULL) RAISE(242, 38, "used member of outdated weak reference")
        aux_String_5 = &aux_String_5_Var;
        aux_String_5_Refman = LUMI_new_ref(aux_String_5);
        if (aux_String_5_Refman == NULL) RAISE(242, 38, "insufficient memory for managed object")
        aux_String_5_Var.length = self->main_input->length - 5;
        aux_String_5_Var.max_length = aux_String_5_Var.length + 1;
        aux_String_5_Var.values = (self->main_input)->values + (0);
        if (self->main_input == NULL) RAISE(242, 29, "empty object used as sequence")
        if (self->main_input_Refman->value == NULL) RAISE(242, 40, "outdated weak reference used as sequence")
        if ((0) < 0 || (self->main_input->length - 5) < 0 || (0) + (self->main_input->length - 5) > (self->main_input)->length) RAISE(242, 25, "slice index out of bounds")
        CHECK(241, String_concat(self->command, self->command_Refman, aux_String_5, self->main_input_Refman) )
        if (self == NULL) RAISE(243, 27, "used member of empty object")
        if (self_Refman->value == NULL) RAISE(243, 38, "used member of outdated weak reference")
        aux_String_6 = &aux_String_6_Var;
        aux_String_6_Refman = LUMI_new_ref(aux_String_6);
        if (aux_String_6_Refman == NULL) RAISE(243, 38, "insufficient memory for managed object")
        aux_String_6_Var.max_length = 4;
        aux_String_6_Var.length = 3;
        aux_String_6_Var.values = ".c\"";
        CHECK(243, String_concat(self->command, self->command_Refman, aux_String_6, aux_String_6_Refman) )
      }
      else {
        CHECK(245, lumi_M_Lumi_concat_lumi_output(self, self_Refman) )
      }
    }
  else {
      if (self == NULL) RAISE(247, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(247, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(247, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(247, 38, "used member of outdated weak reference")
      CHECK(247, String_concat(self->command, self->command_Refman, self->input_files, self->input_files_Refman) )
    }
  if (self == NULL) RAISE(248, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(248, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(248, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(248, 38, "used member of outdated weak reference")
  CHECK(248, String_concat(self->command, self->command_Refman, self->external_files, self->external_files_Refman) )
  if (self == NULL) RAISE(249, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(249, 38, "used member of outdated weak reference")
  aux_String_7 = &aux_String_7_Var;
  aux_String_7_Refman = LUMI_new_ref(aux_String_7);
  if (aux_String_7_Refman == NULL) RAISE(249, 38, "insufficient memory for managed object")
  aux_String_7_Var.max_length = 2;
  aux_String_7_Var.length = 1;
  aux_String_7_Var.values = " ";
  CHECK(249, String_concat(self->command, self->command_Refman, aux_String_7, aux_String_7_Refman) )
  CHECK(250, lumi_M_Lumi_concat_tl_path(self, self_Refman) )
  if (self == NULL) RAISE(251, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(251, 38, "used member of outdated weak reference")
  if (self->version == '0') {
      if (self == NULL) RAISE(252, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(252, 38, "used member of outdated weak reference")
      aux_String_8 = &aux_String_8_Var;
      aux_String_8_Refman = LUMI_new_ref(aux_String_8);
      if (aux_String_8_Refman == NULL) RAISE(252, 38, "insufficient memory for managed object")
      aux_String_8_Var.max_length = 12;
      aux_String_8_Var.length = 11;
      aux_String_8_Var.values = "tl0-file.c ";
      CHECK(252, String_concat(self->command, self->command_Refman, aux_String_8, aux_String_8_Refman) )
      CHECK(253, lumi_M_Lumi_concat_tl_path(self, self_Refman) )
      if (self == NULL) RAISE(254, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(254, 38, "used member of outdated weak reference")
      aux_String_9 = &aux_String_9_Var;
      aux_String_9_Refman = LUMI_new_ref(aux_String_9);
      if (aux_String_9_Refman == NULL) RAISE(254, 38, "insufficient memory for managed object")
      aux_String_9_Var.max_length = 13;
      aux_String_9_Var.length = 12;
      aux_String_9_Var.values = "tl0-string.c";
      CHECK(254, String_concat(self->command, self->command_Refman, aux_String_9, aux_String_9_Refman) )
    }
  else {
      if (self == NULL) RAISE(256, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(256, 38, "used member of outdated weak reference")
      aux_String_10 = &aux_String_10_Var;
      aux_String_10_Refman = LUMI_new_ref(aux_String_10);
      if (aux_String_10_Refman == NULL) RAISE(256, 38, "insufficient memory for managed object")
      aux_String_10_Var.max_length = 6;
      aux_String_10_Var.length = 5;
      aux_String_10_Var.values = "lumi.";
      CHECK(256, String_concat(self->command, self->command_Refman, aux_String_10, aux_String_10_Refman) )
      if (self == NULL) RAISE(257, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(257, 38, "used member of outdated weak reference")
      if (self == NULL) RAISE(257, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(257, 38, "used member of outdated weak reference")
      CHECK(257, String_append(self->command, self->command_Refman, self->version) )
      if (self == NULL) RAISE(258, 27, "used member of empty object")
      if (self_Refman->value == NULL) RAISE(258, 38, "used member of outdated weak reference")
      aux_String_11 = &aux_String_11_Var;
      aux_String_11_Refman = LUMI_new_ref(aux_String_11);
      if (aux_String_11_Refman == NULL) RAISE(258, 38, "insufficient memory for managed object")
      aux_String_11_Var.max_length = 3;
      aux_String_11_Var.length = 2;
      aux_String_11_Var.values = ".c";
      CHECK(258, String_concat(self->command, self->command_Refman, aux_String_11, aux_String_11_Refman) )
    }
  if (self == NULL) RAISE(259, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(259, 38, "used member of outdated weak reference")
  aux_String_12 = &aux_String_12_Var;
  aux_String_12_Refman = LUMI_new_ref(aux_String_12);
  if (aux_String_12_Refman == NULL) RAISE(259, 38, "insufficient memory for managed object")
  aux_String_12_Var.max_length = 4;
  aux_String_12_Var.length = 3;
  aux_String_12_Var.values = " -I";
  CHECK(259, String_concat(self->command, self->command_Refman, aux_String_12, aux_String_12_Refman) )
  CHECK(260, lumi_M_Lumi_concat_tl_path(self, self_Refman) )
  if (self == NULL) RAISE(261, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(261, 38, "used member of outdated weak reference")
  aux_String_13 = &aux_String_13_Var;
  aux_String_13_Refman = LUMI_new_ref(aux_String_13);
  if (aux_String_13_Refman == NULL) RAISE(261, 38, "insufficient memory for managed object")
  aux_String_13_Var.max_length = 4;
  aux_String_13_Var.length = 3;
  aux_String_13_Var.values = " -o";
  CHECK(261, String_concat(self->command, self->command_Refman, aux_String_13, aux_String_13_Refman) )
  if (self == NULL) RAISE(262, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(262, 38, "used member of outdated weak reference")
  if (self == NULL) RAISE(262, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(262, 38, "used member of outdated weak reference")
  CHECK(262, lumi_M_Lumi_concat_file_name(self, self_Refman, self->command, self->command_Refman, self->output, self->output_Refman) )
  aux_String_14 = &aux_String_14_Var;
  aux_String_14_Refman = LUMI_new_ref(aux_String_14);
  if (aux_String_14_Refman == NULL) RAISE(263, 38, "insufficient memory for managed object")
  aux_String_14_Var.max_length = 18;
  aux_String_14_Var.length = 17;
  aux_String_14_Var.values = "C compiler failed";
  CHECK(263, lumi_M_Lumi_m_run_command(self, self_Refman, aux_String_14, aux_String_14_Refman) )
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
#define LUMI_FUNC_NAME "Lumi.m-run"
Returncode lumi_M_Lumi_m_run(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  CHECK(266, lumi_M_Lumi_read_input(self, self_Refman) )
  if (self == NULL) RAISE(267, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(267, 38, "used member of outdated weak reference")
  if (self->run_lumi) {
      CHECK(268, lumi_M_Lumi_m_run_lumi(self, self_Refman) )
    }
  if (self == NULL) RAISE(269, 27, "used member of empty object")
  if (self_Refman->value == NULL) RAISE(269, 38, "used member of outdated weak reference")
  if (self->run_c) {
      CHECK(270, lumi_M_Lumi_m_run_c(self, self_Refman) )
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
  if (aux_String_0_Refman == NULL) RAISE(47, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 271;
  aux_String_0_Var.length = 270;
  aux_String_0_Var.values = "Options:\n  -h \t\t print help\n  -o <file> \t output file name\n  -t <module> \t compile test program for <module>\n  -c \t\t only create C file(s)\n  -l<version> \t only run C compiler for TL<version>\n  -e <file> \t external C file for C compilation\n  -v \t\t print executed commands";
  CHECK(40, Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman) )
  CHECK(48, Sys_exit(sys, sys_Refman, 0) )
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
  if (lumi_object_Refman == NULL) RAISE(274, 38, "insufficient memory for managed object")
  CHECK(274, lumi_M_Lumi_new(lumi_object, lumi_object_Refman) )
  CHECK(275, lumi_M_Lumi_m_run(lumi_object, lumi_object_Refman) )
LUMI_cleanup:
  LUMI_dec_ref(lumi_object_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

MAIN_FUNC
