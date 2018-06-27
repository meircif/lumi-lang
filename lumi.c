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

Returncode lumi_M_Lumi_run_command(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* error_msg, Ref_Manager* error_msg_Refman);

Returncode lumi_M_Lumi_get_any_opt_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman, Int* index, String** value, Ref_Manager** value_Refman);

Returncode lumi_M_Lumi_get_opt_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman, Int* index, String** value, Ref_Manager** value_Refman);

Returncode lumi_M_Lumi_check_opt_param_error(lumi_M_Lumi* self, Ref_Manager* self_Refman, Bool is_error, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman);

Returncode lumi_M_Lumi_check_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* value, Ref_Manager* value_Refman);

Returncode lumi_M_Lumi_concat_lumi_output(lumi_M_Lumi* self, Ref_Manager* self_Refman);

Returncode lumi_M_Lumi_concat_first_file_name(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* target, Ref_Manager* target_Refman, String* name, Ref_Manager* name_Refman);

Returncode lumi_M_Lumi_concat_file_name(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* target, Ref_Manager* target_Refman, String* name, Ref_Manager* name_Refman);

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
  String* aux_String_4 = NULL;
  Ref_Manager* aux_String_4_Refman = NULL;
  String* aux_String_5 = NULL;
  Ref_Manager* aux_String_5_Refman = NULL;
  String* aux_String_6 = NULL;
  Ref_Manager* aux_String_6_Refman = NULL;
  String* aux_String_7 = NULL;
  Ref_Manager* aux_String_7_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(76, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(76, 28, "outdated weak reference used")
  self->running_lumi = true;
  if (self == NULL) RAISE(77, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(77, 28, "outdated weak reference used")
  self->running_c = true;
  if (self == NULL) RAISE(78, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(78, 28, "outdated weak reference used")
  self->execute = true;
  aux_String_0 = LUMI_new_string(lumi_M_MAX_COMMNAD_SIZE);
  if (aux_String_0 == NULL) RAISE(79, 49, "insufficient memory for object dynamic allocation")
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(79, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(79, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(79, 28, "outdated weak reference used")
  aux_String_1 = aux_String_0;
  aux_String_1_Refman = aux_String_0_Refman;
  aux_String_0 = NULL;
  aux_String_0_Refman = NULL;
  String_Del(self->input_files);
  LUMI_owner_dec_ref(self->input_files_Refman);
  self->input_files_Refman = aux_String_1_Refman;
  self->input_files = aux_String_1;
  aux_String_1 = NULL;
  aux_String_1_Refman = NULL;
  aux_String_2 = LUMI_new_string(lumi_M_MAX_COMMNAD_SIZE);
  if (aux_String_2 == NULL) RAISE(80, 49, "insufficient memory for object dynamic allocation")
  aux_String_2_Refman = LUMI_new_ref(aux_String_2);
  if (aux_String_2_Refman == NULL) RAISE(80, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(80, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(80, 28, "outdated weak reference used")
  aux_String_3 = aux_String_2;
  aux_String_3_Refman = aux_String_2_Refman;
  aux_String_2 = NULL;
  aux_String_2_Refman = NULL;
  String_Del(self->external_files);
  LUMI_owner_dec_ref(self->external_files_Refman);
  self->external_files_Refman = aux_String_3_Refman;
  self->external_files = aux_String_3;
  aux_String_3 = NULL;
  aux_String_3_Refman = NULL;
  aux_String_4 = LUMI_new_string(lumi_M_MAX_COMMNAD_SIZE);
  if (aux_String_4 == NULL) RAISE(81, 49, "insufficient memory for object dynamic allocation")
  aux_String_4_Refman = LUMI_new_ref(aux_String_4);
  if (aux_String_4_Refman == NULL) RAISE(81, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(81, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(81, 28, "outdated weak reference used")
  aux_String_5 = aux_String_4;
  aux_String_5_Refman = aux_String_4_Refman;
  aux_String_4 = NULL;
  aux_String_4_Refman = NULL;
  String_Del(self->command);
  LUMI_owner_dec_ref(self->command_Refman);
  self->command_Refman = aux_String_5_Refman;
  self->command = aux_String_5;
  aux_String_5 = NULL;
  aux_String_5_Refman = NULL;
  aux_String_6 = LUMI_new_string(lumi_M_MAX_COMMNAD_SIZE);
  if (aux_String_6 == NULL) RAISE(82, 49, "insufficient memory for object dynamic allocation")
  aux_String_6_Refman = LUMI_new_ref(aux_String_6);
  if (aux_String_6_Refman == NULL) RAISE(82, 38, "insufficient memory for managed object")
  if (self == NULL) RAISE(82, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(82, 28, "outdated weak reference used")
  aux_String_7 = aux_String_6;
  aux_String_7_Refman = aux_String_6_Refman;
  aux_String_6 = NULL;
  aux_String_6_Refman = NULL;
  String_Del(self->lumi_path);
  LUMI_owner_dec_ref(self->lumi_path_Refman);
  self->lumi_path_Refman = aux_String_7_Refman;
  self->lumi_path = aux_String_7;
  aux_String_7 = NULL;
  aux_String_7_Refman = NULL;
  if (self == NULL) RAISE(83, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(83, 28, "outdated weak reference used")
  self->path_separator = '/';
  if (self == NULL) RAISE(84, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(84, 28, "outdated weak reference used")
  self->lumi_path_ends_with_separator = true;
LUMI_cleanup:
  String_Del(aux_String_7);
  LUMI_owner_dec_ref(aux_String_7_Refman);
  String_Del(aux_String_6);
  LUMI_owner_dec_ref(aux_String_6_Refman);
  String_Del(aux_String_5);
  LUMI_owner_dec_ref(aux_String_5_Refman);
  String_Del(aux_String_4);
  LUMI_owner_dec_ref(aux_String_4_Refman);
  String_Del(aux_String_3);
  LUMI_owner_dec_ref(aux_String_3_Refman);
  String_Del(aux_String_2);
  LUMI_owner_dec_ref(aux_String_2_Refman);
  String_Del(aux_String_1);
  LUMI_owner_dec_ref(aux_String_1_Refman);
  String_Del(aux_String_0);
  LUMI_owner_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.run-command"
Returncode lumi_M_Lumi_run_command(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* error_msg, Ref_Manager* error_msg_Refman) {
  Returncode LUMI_err = OK;
  Int aux_Int_0 = 0;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(error_msg_Refman);
  if (self == NULL) RAISE(87, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(87, 28, "outdated weak reference used")
  if (self->verbose) {
      if (self == NULL) RAISE(88, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(88, 28, "outdated weak reference used")
      LUMI_err = Sys_println(sys, sys_Refman, self->command, self->command_Refman);
      CHECK(88)
    }
  if (self == NULL) RAISE(89, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(89, 28, "outdated weak reference used")
  if (self->execute) {
      if (self == NULL) RAISE(90, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(90, 28, "outdated weak reference used")
      LUMI_err = Sys_system(sys, sys_Refman, self->command, self->command_Refman, &(aux_Int_0));
      CHECK(90)
      if (aux_Int_0 != 0) {
        if (error_msg != NULL && error_msg_Refman->value != NULL) {
          LUMI_err = Sys_println(sys, sys_Refman, error_msg, error_msg_Refman);
          CHECK(92)
        }
        LUMI_err = Sys_exit(sys, sys_Refman, 1);
        CHECK(93)
      }
    }
LUMI_cleanup:
  LUMI_dec_ref(error_msg_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.get-any-opt-param"
Returncode lumi_M_Lumi_get_any_opt_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman, Int* index, String** value, Ref_Manager** value_Refman) {
  Returncode LUMI_err = OK;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(option_Refman);
  LUMI_inc_ref(param_Refman);
  if (sys == NULL) RAISE(98, 17, "empty object used")
  if (sys_Refman->value == NULL) RAISE(98, 28, "outdated weak reference used")
  if (sys->argv == NULL) RAISE(98, 17, "empty object used")
  if (sys->argv_Refman->value == NULL) RAISE(98, 28, "outdated weak reference used")
  LUMI_err = lumi_M_Lumi_check_opt_param_error(self, self_Refman, (*index) >= (sys->argv->length - 1), option, option_Refman, param, param_Refman);
  CHECK(97)
  *index += 1;
  if (sys == NULL) RAISE(100, 17, "empty object used")
  if (sys_Refman->value == NULL) RAISE(100, 28, "outdated weak reference used")
  if (sys->argv == NULL) RAISE(100, 17, "empty object used")
  if (sys->argv_Refman->value == NULL) RAISE(100, 28, "outdated weak reference used")
  if ((*index) < 0 || (*index) >= (sys->argv)->length) RAISE(100, 25, "slice index out of bounds")
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

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.get-opt-param"
Returncode lumi_M_Lumi_get_opt_param(lumi_M_Lumi* self, Ref_Manager* self_Refman, String* option, Ref_Manager* option_Refman, String* param, Ref_Manager* param_Refman, Int* index, String** value, Ref_Manager** value_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(option_Refman);
  LUMI_inc_ref(param_Refman);
  LUMI_err = lumi_M_Lumi_get_any_opt_param(self, self_Refman, option, option_Refman, param, param_Refman, &(*index), &(*value), &(*value_Refman));
  CHECK(104)
  if (*value == NULL) RAISE(105, 17, "empty object used")
  if ((*value_Refman)->value == NULL) RAISE(105, 28, "outdated weak reference used")
  if ((0) < 0 || (0) >= ((*value))->length) RAISE(105, 25, "slice index out of bounds")
  LUMI_err = lumi_M_Lumi_check_opt_param_error(self, self_Refman, ((((*value))->values)[0]) == '-', option, option_Refman, param, param_Refman);
  CHECK(105)
  LUMI_err = lumi_M_Lumi_check_param(self, self_Refman, *value, *value_Refman);
  CHECK(106)
LUMI_cleanup:
  LUMI_dec_ref(param_Refman);
  LUMI_dec_ref(option_Refman);
  LUMI_dec_ref(self_Refman);
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
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(option_Refman);
  LUMI_inc_ref(param_Refman);
  if (is_error) {
      aux_String_0 = &aux_String_0_Var;
      aux_String_0_Refman = LUMI_new_ref(aux_String_0);
      if (aux_String_0_Refman == NULL) RAISE(111, 38, "insufficient memory for managed object")
      aux_String_0_Var.max_length = 16;
      aux_String_0_Var.length = 15;
      aux_String_0_Var.values = "error: missing ";
      LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
      CHECK(111)
      LUMI_err = Sys_print(sys, sys_Refman, param, param_Refman);
      CHECK(112)
      aux_String_1 = &aux_String_1_Var;
      aux_String_1_Refman = LUMI_new_ref(aux_String_1);
      if (aux_String_1_Refman == NULL) RAISE(113, 38, "insufficient memory for managed object")
      aux_String_1_Var.max_length = 10;
      aux_String_1_Var.length = 9;
      aux_String_1_Var.values = " after \"-";
      LUMI_err = Sys_print(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
      CHECK(113)
      LUMI_err = Sys_print(sys, sys_Refman, option, option_Refman);
      CHECK(114)
      aux_String_2 = &aux_String_2_Var;
      aux_String_2_Refman = LUMI_new_ref(aux_String_2);
      if (aux_String_2_Refman == NULL) RAISE(115, 38, "insufficient memory for managed object")
      aux_String_2_Var.max_length = 7;
      aux_String_2_Var.length = 6;
      aux_String_2_Var.values = "\" flag";
      LUMI_err = Sys_println(sys, sys_Refman, aux_String_2, aux_String_2_Refman);
      CHECK(115)
      LUMI_err = Sys_exit(sys, sys_Refman, 1);
      CHECK(116)
    }
LUMI_cleanup:
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(param_Refman);
  LUMI_dec_ref(option_Refman);
  LUMI_dec_ref(self_Refman);
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
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(value_Refman);
  LUMI_err = String_has(value, value_Refman, '"', &(aux_Bool_0));
  CHECK(119)
  if (aux_Bool_0) {
      aux_String_0 = &aux_String_0_Var;
      aux_String_0_Refman = LUMI_new_ref(aux_String_0);
      if (aux_String_0_Refman == NULL) RAISE(120, 38, "insufficient memory for managed object")
      aux_String_0_Var.max_length = 42;
      aux_String_0_Var.length = 41;
      aux_String_0_Var.values = "error: illegal \" character in parameter '";
      LUMI_err = Sys_print(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
      CHECK(120)
      LUMI_err = Sys_print(sys, sys_Refman, value, value_Refman);
      CHECK(121)
      aux_String_1 = &aux_String_1_Var;
      aux_String_1_Refman = LUMI_new_ref(aux_String_1);
      if (aux_String_1_Refman == NULL) RAISE(122, 38, "insufficient memory for managed object")
      aux_String_1_Var.max_length = 2;
      aux_String_1_Var.length = 1;
      aux_String_1_Var.values = "'";
      LUMI_err = Sys_println(sys, sys_Refman, aux_String_1, aux_String_1_Refman);
      CHECK(122)
      LUMI_err = Sys_exit(sys, sys_Refman, 1);
      CHECK(123)
    }
LUMI_cleanup:
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(value_Refman);
  LUMI_dec_ref(self_Refman);
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
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(126, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(126, 28, "outdated weak reference used")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(126, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = " \"";
  LUMI_err = String_concat(self->command, self->command_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(126)
  if (self == NULL) RAISE(127, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(127, 28, "outdated weak reference used")
  if (self == NULL) RAISE(127, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(127, 28, "outdated weak reference used")
  LUMI_err = String_concat(self->command, self->command_Refman, self->output, self->output_Refman);
  CHECK(127)
  if (self == NULL) RAISE(128, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(128, 28, "outdated weak reference used")
  if (self == NULL) RAISE(128, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(128, 28, "outdated weak reference used")
  if (self->running_c || (! self->explicit_output)) {
      if (self == NULL) RAISE(129, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(129, 28, "outdated weak reference used")
      aux_String_1 = &aux_String_1_Var;
      aux_String_1_Refman = LUMI_new_ref(aux_String_1);
      if (aux_String_1_Refman == NULL) RAISE(129, 38, "insufficient memory for managed object")
      aux_String_1_Var.max_length = 3;
      aux_String_1_Var.length = 2;
      aux_String_1_Var.values = ".c";
      LUMI_err = String_concat(self->command, self->command_Refman, aux_String_1, aux_String_1_Refman);
      CHECK(129)
    }
  if (self == NULL) RAISE(130, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(130, 28, "outdated weak reference used")
  aux_String_2 = &aux_String_2_Var;
  aux_String_2_Refman = LUMI_new_ref(aux_String_2);
  if (aux_String_2_Refman == NULL) RAISE(130, 38, "insufficient memory for managed object")
  aux_String_2_Var.max_length = 2;
  aux_String_2_Var.length = 1;
  aux_String_2_Var.values = "\"";
  LUMI_err = String_concat(self->command, self->command_Refman, aux_String_2, aux_String_2_Refman);
  CHECK(130)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(self_Refman);
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
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(target_Refman);
  LUMI_inc_ref(name_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(133, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 2;
  aux_String_0_Var.length = 1;
  aux_String_0_Var.values = "\"";
  LUMI_err = String_concat(target, target_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(133)
  LUMI_err = String_concat(target, target_Refman, name, name_Refman);
  CHECK(134)
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(135, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 2;
  aux_String_1_Var.length = 1;
  aux_String_1_Var.values = "\"";
  LUMI_err = String_concat(target, target_Refman, aux_String_1, aux_String_1_Refman);
  CHECK(135)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(name_Refman);
  LUMI_dec_ref(target_Refman);
  LUMI_dec_ref(self_Refman);
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
  LUMI_inc_ref(self_Refman);
  LUMI_inc_ref(target_Refman);
  LUMI_inc_ref(name_Refman);
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(138, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 2;
  aux_String_0_Var.length = 1;
  aux_String_0_Var.values = " ";
  LUMI_err = String_concat(target, target_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(138)
  LUMI_err = lumi_M_Lumi_concat_first_file_name(self, self_Refman, target, target_Refman, name, name_Refman);
  CHECK(139)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(name_Refman);
  LUMI_dec_ref(target_Refman);
  LUMI_dec_ref(self_Refman);
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
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(142, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(142, 28, "outdated weak reference used")
  if (self == NULL) RAISE(142, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(142, 28, "outdated weak reference used")
  LUMI_err = String_concat(self->command, self->command_Refman, self->lumi_path, self->lumi_path_Refman);
  CHECK(142)
  if (self == NULL) RAISE(143, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(143, 28, "outdated weak reference used")
  if (! self->lumi_path_ends_with_separator) {
      if (self == NULL) RAISE(144, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(144, 28, "outdated weak reference used")
      if (self == NULL) RAISE(144, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(144, 28, "outdated weak reference used")
      LUMI_err = String_append(self->command, self->command_Refman, self->path_separator);
      CHECK(144)
    }
  if (self == NULL) RAISE(145, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(145, 28, "outdated weak reference used")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(145, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = "TL";
  LUMI_err = String_concat(self->command, self->command_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(145)
  if (self == NULL) RAISE(146, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(146, 28, "outdated weak reference used")
  if (self == NULL) RAISE(146, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(146, 28, "outdated weak reference used")
  LUMI_err = String_append(self->command, self->command_Refman, self->version);
  CHECK(146)
  if (self == NULL) RAISE(147, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(147, 28, "outdated weak reference used")
  if (self == NULL) RAISE(147, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(147, 28, "outdated weak reference used")
  LUMI_err = String_append(self->command, self->command_Refman, self->path_separator);
  CHECK(147)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(self_Refman);
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
  String* aux_String_24 = NULL;
  Ref_Manager* aux_String_24_Refman = NULL;
  Ref_Manager* aux_Ref_Manager = NULL;
  LUMI_inc_ref(self_Refman);
  if (sys == NULL) RAISE(150, 17, "empty object used")
  if (sys_Refman->value == NULL) RAISE(150, 28, "outdated weak reference used")
  if (sys->argv == NULL) RAISE(150, 17, "empty object used")
  if (sys->argv_Refman->value == NULL) RAISE(150, 28, "outdated weak reference used")
  LUMI_err = lumi_M_error_if(sys->argv->length < 2, lumi_M_usage, lumi_M_usage_Refman);
  CHECK(150)
  if (sys == NULL) RAISE(155, 17, "empty object used")
  if (sys_Refman->value == NULL) RAISE(155, 28, "outdated weak reference used")
  if (sys->argv == NULL) RAISE(155, 17, "empty object used")
  if (sys->argv_Refman->value == NULL) RAISE(155, 28, "outdated weak reference used")
  for (index = 1; index < sys->argv->length; ++index) {
      if (sys == NULL) RAISE(156, 17, "empty object used")
      if (sys_Refman->value == NULL) RAISE(156, 28, "outdated weak reference used")
      if (sys->argv == NULL) RAISE(156, 17, "empty object used")
      if (sys->argv_Refman->value == NULL) RAISE(156, 28, "outdated weak reference used")
      if ((index) < 0 || (index) >= (sys->argv)->length) RAISE(156, 25, "slice index out of bounds")
      arg = ((String*)((sys->argv)->values)) + index;
      arg_Refman = sys->argv_Refman;
      LUMI_inc_ref(arg_Refman);
      if (arg == NULL) RAISE(157, 17, "empty object used")
      if (arg_Refman->value == NULL) RAISE(157, 28, "outdated weak reference used")
      if ((0) < 0 || (0) >= (arg)->length) RAISE(157, 25, "slice index out of bounds")
      if ((((arg)->values)[0]) == '-') {
        if (arg == NULL) RAISE(158, 17, "empty object used")
        if (arg_Refman->value == NULL) RAISE(158, 28, "outdated weak reference used")
        if (arg->length < 2) {
          aux_String_0 = &aux_String_0_Var;
          aux_String_0_Refman = LUMI_new_ref(aux_String_0);
          if (aux_String_0_Refman == NULL) RAISE(159, 38, "insufficient memory for managed object")
          aux_String_0_Var.max_length = 26;
          aux_String_0_Var.length = 25;
          aux_String_0_Var.values = "warning: unknown flag \"-\"";
          LUMI_err = Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
          CHECK(159)
        }
        else {
          if (arg == NULL) RAISE(161, 17, "empty object used")
          if (arg_Refman->value == NULL) RAISE(161, 28, "outdated weak reference used")
          if ((1) < 0 || (1) >= (arg)->length) RAISE(161, 25, "slice index out of bounds")
          op = ((arg)->values)[1];
          if (op == 'h') {
            LUMI_err = lumi_M_help();
            CHECK(163)
          }
          else {
            if (op == 'o') {
              aux_String_1 = &aux_String_1_Var;
              aux_String_1_Refman = LUMI_new_ref(aux_String_1);
              if (aux_String_1_Refman == NULL) RAISE(165, 38, "insufficient memory for managed object")
              aux_String_1_Var.max_length = 2;
              aux_String_1_Var.length = 1;
              aux_String_1_Var.values = "o";
              aux_String_2 = &aux_String_2_Var;
              aux_String_2_Refman = LUMI_new_ref(aux_String_2);
              if (aux_String_2_Refman == NULL) RAISE(165, 38, "insufficient memory for managed object")
              aux_String_2_Var.max_length = 10;
              aux_String_2_Var.length = 9;
              aux_String_2_Var.values = "file name";
              if (self == NULL) RAISE(166, 17, "empty object used")
              if (self_Refman->value == NULL) RAISE(166, 28, "outdated weak reference used")
              LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_1, aux_String_1_Refman, aux_String_2, aux_String_2_Refman, &(index), &(self->output), &(self->output_Refman));
              CHECK(165)
              if (self == NULL) RAISE(167, 17, "empty object used")
              if (self_Refman->value == NULL) RAISE(167, 28, "outdated weak reference used")
              self->explicit_output = true;
            }
            else {
              if (op == 't') {
                aux_String_3 = &aux_String_3_Var;
                aux_String_3_Refman = LUMI_new_ref(aux_String_3);
                if (aux_String_3_Refman == NULL) RAISE(169, 38, "insufficient memory for managed object")
                aux_String_3_Var.max_length = 2;
                aux_String_3_Var.length = 1;
                aux_String_3_Var.values = "t";
                aux_String_4 = &aux_String_4_Var;
                aux_String_4_Refman = LUMI_new_ref(aux_String_4);
                if (aux_String_4_Refman == NULL) RAISE(169, 38, "insufficient memory for managed object")
                aux_String_4_Var.max_length = 12;
                aux_String_4_Var.length = 11;
                aux_String_4_Var.values = "module name";
                if (self == NULL) RAISE(170, 17, "empty object used")
                if (self_Refman->value == NULL) RAISE(170, 28, "outdated weak reference used")
                LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_3, aux_String_3_Refman, aux_String_4, aux_String_4_Refman, &(index), &(self->mut), &(self->mut_Refman));
                CHECK(169)
              }
              else {
                if (op == 'e') {
                  if (self == NULL) RAISE(173, 17, "empty object used")
                  if (self_Refman->value == NULL) RAISE(173, 28, "outdated weak reference used")
                  aux_String_5 = &aux_String_5_Var;
                  aux_String_5_Refman = LUMI_new_ref(aux_String_5);
                  if (aux_String_5_Refman == NULL) RAISE(174, 38, "insufficient memory for managed object")
                  aux_String_5_Var.max_length = 2;
                  aux_String_5_Var.length = 1;
                  aux_String_5_Var.values = "e";
                  aux_String_6 = &aux_String_6_Var;
                  aux_String_6_Refman = LUMI_new_ref(aux_String_6);
                  if (aux_String_6_Refman == NULL) RAISE(174, 38, "insufficient memory for managed object")
                  aux_String_6_Var.max_length = 10;
                  aux_String_6_Var.length = 9;
                  aux_String_6_Var.values = "file name";
                  LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_5, aux_String_5_Refman, aux_String_6, aux_String_6_Refman, &(index), &(aux_String_7), &(aux_String_7_Refman));
                  CHECK(172)
                  LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, self->external_files, self->external_files_Refman, aux_String_7, aux_String_7_Refman);
                  CHECK(172)
                }
                else {
                  if (op == 'p') {
                    if (self == NULL) RAISE(177, 17, "empty object used")
                    if (self_Refman->value == NULL) RAISE(177, 28, "outdated weak reference used")
                    aux_String_8 = &aux_String_8_Var;
                    aux_String_8_Refman = LUMI_new_ref(aux_String_8);
                    if (aux_String_8_Refman == NULL) RAISE(178, 38, "insufficient memory for managed object")
                    aux_String_8_Var.max_length = 2;
                    aux_String_8_Var.length = 1;
                    aux_String_8_Var.values = "p";
                    aux_String_9 = &aux_String_9_Var;
                    aux_String_9_Refman = LUMI_new_ref(aux_String_9);
                    if (aux_String_9_Refman == NULL) RAISE(178, 38, "insufficient memory for managed object")
                    aux_String_9_Var.max_length = 5;
                    aux_String_9_Var.length = 4;
                    aux_String_9_Var.values = "path";
                    LUMI_err = lumi_M_Lumi_get_opt_param(self, self_Refman, aux_String_8, aux_String_8_Refman, aux_String_9, aux_String_9_Refman, &(index), &(aux_String_10), &(aux_String_10_Refman));
                    CHECK(177)
                    LUMI_err = String_new(self->lumi_path, self->lumi_path_Refman, aux_String_10, aux_String_10_Refman);
                    CHECK(177)
                  }
                  else {
                    if (op == 'c') {
                      if (self == NULL) RAISE(180, 17, "empty object used")
                      if (self_Refman->value == NULL) RAISE(180, 28, "outdated weak reference used")
                      self->running_c = false;
                    }
                    else {
                      if (arg == NULL) RAISE(181, 17, "empty object used")
                      if (arg_Refman->value == NULL) RAISE(181, 28, "outdated weak reference used")
                      if ((op == 'l') && (arg->length > 2)) {
                        if (self == NULL) RAISE(182, 17, "empty object used")
                        if (self_Refman->value == NULL) RAISE(182, 28, "outdated weak reference used")
                        self->running_lumi = false;
                        if (arg == NULL) RAISE(183, 17, "empty object used")
                        if (arg_Refman->value == NULL) RAISE(183, 28, "outdated weak reference used")
                        if ((2) < 0 || (2) >= (arg)->length) RAISE(183, 25, "slice index out of bounds")
                        if (self == NULL) RAISE(183, 17, "empty object used")
                        if (self_Refman->value == NULL) RAISE(183, 28, "outdated weak reference used")
                        self->version = ((arg)->values)[2];
                      }
                      else {
                        if (op == 'r') {
                          if (self == NULL) RAISE(185, 17, "empty object used")
                          if (self_Refman->value == NULL) RAISE(185, 28, "outdated weak reference used")
                          self->running_program = true;
                          if (arg == NULL) RAISE(186, 17, "empty object used")
                          if (arg_Refman->value == NULL) RAISE(186, 28, "outdated weak reference used")
                          if (arg->length > 2) {
              if (arg == NULL) RAISE(187, 17, "empty object used")
              if (arg_Refman->value == NULL) RAISE(187, 28, "outdated weak reference used")
              if ((2) < 0 || (2) >= (arg)->length) RAISE(187, 25, "slice index out of bounds")
              if ((((arg)->values)[2]) == 'a') {
                aux_String_11 = &aux_String_11_Var;
                aux_String_11_Refman = LUMI_new_ref(aux_String_11);
                if (aux_String_11_Refman == NULL) RAISE(188, 38, "insufficient memory for managed object")
                aux_String_11_Var.max_length = 3;
                aux_String_11_Var.length = 2;
                aux_String_11_Var.values = "ra";
                aux_String_12 = &aux_String_12_Var;
                aux_String_12_Refman = LUMI_new_ref(aux_String_12);
                if (aux_String_12_Refman == NULL) RAISE(188, 38, "insufficient memory for managed object")
                aux_String_12_Var.max_length = 10;
                aux_String_12_Var.length = 9;
                aux_String_12_Var.values = "arguments";
                if (self == NULL) RAISE(189, 17, "empty object used")
                if (self_Refman->value == NULL) RAISE(189, 28, "outdated weak reference used")
                LUMI_err = lumi_M_Lumi_get_any_opt_param(self, self_Refman, aux_String_11, aux_String_11_Refman, aux_String_12, aux_String_12_Refman, &(index), &(self->execute_arguments), &(self->execute_arguments_Refman));
                CHECK(188)
              }
            }
                        }
                        else {
                          if (op == 'v') {
                            if (self == NULL) RAISE(191, 17, "empty object used")
                            if (self_Refman->value == NULL) RAISE(191, 28, "outdated weak reference used")
                            self->verbose = true;
                          }
                          else {
                            if (op == 'd') {
                              if (self == NULL) RAISE(193, 17, "empty object used")
                              if (self_Refman->value == NULL) RAISE(193, 28, "outdated weak reference used")
                              self->verbose = true;
                              if (self == NULL) RAISE(194, 17, "empty object used")
                              if (self_Refman->value == NULL) RAISE(194, 28, "outdated weak reference used")
                              self->execute = false;
                            }
                            else {
                              aux_String_13 = &aux_String_13_Var;
                              aux_String_13_Refman = LUMI_new_ref(aux_String_13);
                              if (aux_String_13_Refman == NULL) RAISE(196, 38, "insufficient memory for managed object")
                              aux_String_13_Var.max_length = 24;
                              aux_String_13_Var.length = 23;
                              aux_String_13_Var.values = "warning: unknown flag \"";
                              LUMI_err = Sys_print(sys, sys_Refman, aux_String_13, aux_String_13_Refman);
                              CHECK(196)
                              LUMI_err = Sys_print(sys, sys_Refman, arg, arg_Refman);
                              CHECK(197)
                              aux_String_14 = &aux_String_14_Var;
                              aux_String_14_Refman = LUMI_new_ref(aux_String_14);
                              if (aux_String_14_Refman == NULL) RAISE(198, 38, "insufficient memory for managed object")
                              aux_String_14_Var.max_length = 2;
                              aux_String_14_Var.length = 1;
                              aux_String_14_Var.values = "\"";
                              LUMI_err = Sys_println(sys, sys_Refman, aux_String_14, aux_String_14_Refman);
                              CHECK(198)
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
        CHECK(200)
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
        if (self == NULL) RAISE(204, 17, "empty object used")
        if (self_Refman->value == NULL) RAISE(204, 28, "outdated weak reference used")
        LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, self->input_files, self->input_files_Refman, arg, arg_Refman);
        CHECK(204)
        input_files_num += 1;
      }
    }
  aux_String_15 = &aux_String_15_Var;
  aux_String_15_Refman = LUMI_new_ref(aux_String_15);
  if (aux_String_15_Refman == NULL) RAISE(207, 38, "insufficient memory for managed object")
  aux_String_15_Var.max_length = 22;
  aux_String_15_Var.length = 21;
  aux_String_15_Var.values = "error: no input files";
  LUMI_err = lumi_M_error_if(input_files_num == 0, aux_String_15, aux_String_15_Refman);
  CHECK(207)
  if (self == NULL) RAISE(209, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(209, 28, "outdated weak reference used")
  if (self == NULL) RAISE(209, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(209, 28, "outdated weak reference used")
  aux_String_16 = &aux_String_16_Var;
  aux_String_16_Refman = LUMI_new_ref(aux_String_16);
  if (aux_String_16_Refman == NULL) RAISE(211, 38, "insufficient memory for managed object")
  aux_String_16_Var.max_length = 72;
  aux_String_16_Var.length = 71;
  aux_String_16_Var.values = "error: cannot run program when C compilation is turned off by \"-c\" flag";
  LUMI_err = lumi_M_error_if(self->running_program && (! self->running_c), aux_String_16, aux_String_16_Refman);
  CHECK(208)
  if (self == NULL) RAISE(213, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(213, 28, "outdated weak reference used")
  if (self->running_lumi) {
      if (first_input == NULL) RAISE(215, 17, "empty object used")
      if (first_input_Refman->value == NULL) RAISE(215, 28, "outdated weak reference used")
      aux_String_17 = &aux_String_17_Var;
      aux_String_17_Refman = LUMI_new_ref(aux_String_17);
      if (aux_String_17_Refman == NULL) RAISE(216, 38, "insufficient memory for managed object")
      aux_String_17_Var.max_length = 32;
      aux_String_17_Var.length = 31;
      aux_String_17_Var.values = "error: Lumi file name too short";
      LUMI_err = lumi_M_error_if(first_input->length < 6, aux_String_17, aux_String_17_Refman);
      CHECK(214)
      if (first_input == NULL) RAISE(217, 17, "empty object used")
      if (first_input_Refman->value == NULL) RAISE(217, 28, "outdated weak reference used")
      if (first_input == NULL) RAISE(217, 17, "empty object used")
      if (first_input_Refman->value == NULL) RAISE(217, 28, "outdated weak reference used")
      if ((first_input->length - 4) < 0 || (first_input->length - 4) >= (first_input)->length) RAISE(217, 25, "slice index out of bounds")
      if (self == NULL) RAISE(217, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(217, 28, "outdated weak reference used")
      self->version = ((first_input)->values)[first_input->length - 4];
    }
  if (self == NULL) RAISE(218, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(218, 28, "outdated weak reference used")
  if (self == NULL) RAISE(218, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(218, 28, "outdated weak reference used")
  if ((self->version < '0') || (self->version > '4')) {
      aux_String_18 = &aux_String_18_Var;
      aux_String_18_Refman = LUMI_new_ref(aux_String_18);
      if (aux_String_18_Refman == NULL) RAISE(219, 38, "insufficient memory for managed object")
      aux_String_18_Var.max_length = 30;
      aux_String_18_Var.length = 29;
      aux_String_18_Var.values = "error: unsupported version TL";
      LUMI_err = Sys_print(sys, sys_Refman, aux_String_18, aux_String_18_Refman);
      CHECK(219)
      version_string = &version_string_Var;
      version_string_Var.values = version_string_Values;
      version_string_Refman = LUMI_new_ref(version_string);
      if (version_string_Refman == NULL) RAISE(220, 38, "insufficient memory for managed object")
      if (self == NULL) RAISE(221, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(221, 28, "outdated weak reference used")
      LUMI_err = String_append(version_string, version_string_Refman, self->version);
      CHECK(221)
      LUMI_err = Sys_println(sys, sys_Refman, version_string, version_string_Refman);
      CHECK(222)
      LUMI_err = Sys_exit(sys, sys_Refman, 1);
      CHECK(223)
    }
  if (self == NULL) RAISE(225, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(225, 28, "outdated weak reference used")
  aux_String_19 = &aux_String_19_Var;
  aux_String_19_Refman = LUMI_new_ref(aux_String_19);
  if (aux_String_19_Refman == NULL) RAISE(226, 38, "insufficient memory for managed object")
  aux_String_19_Var.max_length = 47;
  aux_String_19_Var.length = 46;
  aux_String_19_Var.values = "error: multiple files not supported before TL2";
  LUMI_err = lumi_M_error_if((self->version < '2') && (input_files_num > 1), aux_String_19, aux_String_19_Refman);
  CHECK(224)
  if (self == NULL) RAISE(229, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(229, 28, "outdated weak reference used")
  if (self == NULL) RAISE(229, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(229, 28, "outdated weak reference used")
  if (self == NULL) RAISE(228, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(228, 28, "outdated weak reference used")
  if (self == NULL) RAISE(228, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(228, 28, "outdated weak reference used")
  aux_String_20 = &aux_String_20_Var;
  aux_String_20_Refman = LUMI_new_ref(aux_String_20);
  if (aux_String_20_Refman == NULL) RAISE(230, 38, "insufficient memory for managed object")
  aux_String_20_Var.max_length = 49;
  aux_String_20_Var.length = 48;
  aux_String_20_Var.values = "error: cannot specify C output file in TL2 & TL3";
  LUMI_err = lumi_M_error_if((((self->version >= '2') && (self->version <= '3')) && self->explicit_output) && (! self->running_c), aux_String_20, aux_String_20_Refman);
  CHECK(227)
  if (self == NULL) RAISE(232, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(232, 28, "outdated weak reference used")
  if (self == NULL) RAISE(232, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(232, 28, "outdated weak reference used")
  aux_String_21 = &aux_String_21_Var;
  aux_String_21_Refman = LUMI_new_ref(aux_String_21);
  if (aux_String_21_Refman == NULL) RAISE(233, 38, "insufficient memory for managed object")
  aux_String_21_Var.max_length = 40;
  aux_String_21_Var.length = 39;
  aux_String_21_Var.values = "error: testing not supported before TL4";
  LUMI_err = lumi_M_error_if((self->version < '4') && (self->mut != NULL && self->mut_Refman->value != NULL), aux_String_21, aux_String_21_Refman);
  CHECK(231)
  if (self == NULL) RAISE(234, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(234, 28, "outdated weak reference used")
  if (self->version <= '2') {
      if (self == NULL) RAISE(235, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(235, 28, "outdated weak reference used")
      aux_Ref_Manager = self->main_input_Refman;
      self->main_input_Refman = last_input_Refman;
      LUMI_inc_ref(self->main_input_Refman);
      LUMI_dec_ref(aux_Ref_Manager);
      aux_Ref_Manager = NULL;
      self->main_input = last_input;
    }
  else {
      if (self == NULL) RAISE(237, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(237, 28, "outdated weak reference used")
      aux_Ref_Manager = self->main_input_Refman;
      self->main_input_Refman = first_input_Refman;
      LUMI_inc_ref(self->main_input_Refman);
      LUMI_dec_ref(aux_Ref_Manager);
      aux_Ref_Manager = NULL;
      self->main_input = first_input;
    }
  if (self == NULL) RAISE(239, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(239, 28, "outdated weak reference used")
  if (! (self->output != NULL && self->output_Refman->value != NULL)) {
      suffix_length = 2;
      if (self == NULL) RAISE(241, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(241, 28, "outdated weak reference used")
      if (self->running_lumi) {
        suffix_length = 5;
      }
      if (self == NULL) RAISE(244, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(244, 28, "outdated weak reference used")
      if (self == NULL) RAISE(244, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(244, 28, "outdated weak reference used")
      if (self->main_input == NULL) RAISE(244, 17, "empty object used")
      if (self->main_input_Refman->value == NULL) RAISE(244, 28, "outdated weak reference used")
      aux_String_22 = &aux_String_22_Var;
      aux_String_22_Refman = LUMI_new_ref(aux_String_22);
      if (aux_String_22_Refman == NULL) RAISE(244, 38, "insufficient memory for managed object")
      aux_String_22_Var.length = self->main_input->length - suffix_length;
      aux_String_22_Var.max_length = aux_String_22_Var.length + 1;
      aux_String_22_Var.values = (self->main_input)->values + (0);
      if (self->main_input == NULL) RAISE(244, 17, "empty object used")
      if (self->main_input_Refman->value == NULL) RAISE(244, 28, "outdated weak reference used")
      if ((0) < 0 || (self->main_input->length - suffix_length) < 0 || (0) + (self->main_input->length - suffix_length) > (self->main_input)->length) RAISE(244, 25, "slice index out of bounds")
      if (self == NULL) RAISE(243, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(243, 28, "outdated weak reference used")
      if (self->main_input == NULL) RAISE(243, 17, "empty object used")
      if (self->main_input_Refman->value == NULL) RAISE(243, 28, "outdated weak reference used")
      aux_String_23 = LUMI_new_string(self->main_input->length);
      if (aux_String_23 == NULL) RAISE(243, 49, "insufficient memory for object dynamic allocation")
      aux_String_23_Refman = LUMI_new_ref(aux_String_23);
      if (aux_String_23_Refman == NULL) RAISE(243, 38, "insufficient memory for managed object")
      LUMI_err = String_new(aux_String_23, aux_String_23_Refman, aux_String_22, self->main_input_Refman);
      CHECK(243)
      if (self == NULL) RAISE(243, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(243, 28, "outdated weak reference used")
      aux_String_24 = aux_String_23;
      aux_String_24_Refman = aux_String_23_Refman;
      aux_String_23 = NULL;
      aux_String_23_Refman = NULL;
      String_Del(self->implicit_output);
      LUMI_owner_dec_ref(self->implicit_output_Refman);
      self->implicit_output_Refman = aux_String_24_Refman;
      self->implicit_output = aux_String_24;
      aux_String_24 = NULL;
      aux_String_24_Refman = NULL;
      if (self == NULL) RAISE(245, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(245, 28, "outdated weak reference used")
      if (self == NULL) RAISE(245, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(245, 28, "outdated weak reference used")
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
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
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
  if (self == NULL) RAISE(249, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(249, 28, "outdated weak reference used")
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(249, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = "tl";
  LUMI_err = String_new(self->command, self->command_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(249)
  if (self == NULL) RAISE(250, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(250, 28, "outdated weak reference used")
  if (self == NULL) RAISE(250, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(250, 28, "outdated weak reference used")
  LUMI_err = String_append(self->command, self->command_Refman, self->version);
  CHECK(250)
  if (self == NULL) RAISE(251, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(251, 28, "outdated weak reference used")
  aux_String_1 = &aux_String_1_Var;
  aux_String_1_Refman = LUMI_new_ref(aux_String_1);
  if (aux_String_1_Refman == NULL) RAISE(251, 38, "insufficient memory for managed object")
  aux_String_1_Var.max_length = 10;
  aux_String_1_Var.length = 9;
  aux_String_1_Var.values = "-compiler";
  LUMI_err = String_concat(self->command, self->command_Refman, aux_String_1, aux_String_1_Refman);
  CHECK(251)
  if (self == NULL) RAISE(252, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(252, 28, "outdated weak reference used")
  if (self->version >= '4') {
      if (self == NULL) RAISE(253, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(253, 28, "outdated weak reference used")
      if (self->mut != NULL && self->mut_Refman->value != NULL) {
        if (self == NULL) RAISE(254, 17, "empty object used")
        if (self_Refman->value == NULL) RAISE(254, 28, "outdated weak reference used")
        aux_String_2 = &aux_String_2_Var;
        aux_String_2_Refman = LUMI_new_ref(aux_String_2);
        if (aux_String_2_Refman == NULL) RAISE(254, 38, "insufficient memory for managed object")
        aux_String_2_Var.max_length = 4;
        aux_String_2_Var.length = 3;
        aux_String_2_Var.values = " -t";
        LUMI_err = String_concat(self->command, self->command_Refman, aux_String_2, aux_String_2_Refman);
        CHECK(254)
        if (self == NULL) RAISE(255, 17, "empty object used")
        if (self_Refman->value == NULL) RAISE(255, 28, "outdated weak reference used")
        if (self == NULL) RAISE(255, 17, "empty object used")
        if (self_Refman->value == NULL) RAISE(255, 28, "outdated weak reference used")
        LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, self->command, self->command_Refman, self->mut, self->mut_Refman);
        CHECK(255)
      }
      LUMI_err = lumi_M_Lumi_concat_lumi_output(self, self_Refman);
      CHECK(256)
    }
  if (self == NULL) RAISE(257, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(257, 28, "outdated weak reference used")
  if (self == NULL) RAISE(257, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(257, 28, "outdated weak reference used")
  LUMI_err = String_concat(self->command, self->command_Refman, self->input_files, self->input_files_Refman);
  CHECK(257)
  if (self == NULL) RAISE(258, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(258, 28, "outdated weak reference used")
  if (self->version <= '1') {
      LUMI_err = lumi_M_Lumi_concat_lumi_output(self, self_Refman);
      CHECK(259)
    }
  aux_String_3 = &aux_String_3_Var;
  aux_String_3_Refman = LUMI_new_ref(aux_String_3);
  if (aux_String_3_Refman == NULL) RAISE(260, 38, "insufficient memory for managed object")
  aux_String_3_Var.max_length = 21;
  aux_String_3_Var.length = 20;
  aux_String_3_Var.values = "Lumi compiler failed";
  LUMI_err = lumi_M_Lumi_run_command(self, self_Refman, aux_String_3, aux_String_3_Refman);
  CHECK(260)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_3_Refman);
  LUMI_dec_ref(aux_String_2_Refman);
  LUMI_dec_ref(aux_String_1_Refman);
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
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
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(263, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 3;
  aux_String_0_Var.length = 2;
  aux_String_0_Var.values = "CC";
  if (self == NULL) RAISE(263, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(263, 28, "outdated weak reference used")
  LUMI_err = Sys_getenv(sys, sys_Refman, aux_String_0, aux_String_0_Refman, self->command, self->command_Refman, &(aux_Bool_0));
  CHECK(263)
  if (! aux_Bool_0) {
      if (self == NULL) RAISE(264, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(264, 28, "outdated weak reference used")
      aux_String_1 = &aux_String_1_Var;
      aux_String_1_Refman = LUMI_new_ref(aux_String_1);
      if (aux_String_1_Refman == NULL) RAISE(264, 38, "insufficient memory for managed object")
      aux_String_1_Var.max_length = 4;
      aux_String_1_Var.length = 3;
      aux_String_1_Var.values = "gcc";
      LUMI_err = String_new(self->command, self->command_Refman, aux_String_1, aux_String_1_Refman);
      CHECK(264)
    }
  if (self == NULL) RAISE(265, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(265, 28, "outdated weak reference used")
  if (self->lumi_path == NULL) RAISE(265, 17, "empty object used")
  if (self->lumi_path_Refman->value == NULL) RAISE(265, 28, "outdated weak reference used")
  if (self->lumi_path->length == 0) {
      aux_String_2 = &aux_String_2_Var;
      aux_String_2_Refman = LUMI_new_ref(aux_String_2);
      if (aux_String_2_Refman == NULL) RAISE(266, 38, "insufficient memory for managed object")
      aux_String_2_Var.max_length = 9;
      aux_String_2_Var.length = 8;
      aux_String_2_Var.values = "LUMIPATH";
      if (self == NULL) RAISE(266, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(266, 28, "outdated weak reference used")
      LUMI_err = Sys_getenv(sys, sys_Refman, aux_String_2, aux_String_2_Refman, self->lumi_path, self->lumi_path_Refman, &(aux_Bool_1));
      CHECK(266)
    }
  if (self == NULL) RAISE(267, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(267, 28, "outdated weak reference used")
  if (self->lumi_path == NULL) RAISE(267, 17, "empty object used")
  if (self->lumi_path_Refman->value == NULL) RAISE(267, 28, "outdated weak reference used")
  if (self->lumi_path->length > 0) {
      if (self == NULL) RAISE(268, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(268, 28, "outdated weak reference used")
      if (self == NULL) RAISE(268, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(268, 28, "outdated weak reference used")
      if (self->lumi_path == NULL) RAISE(268, 17, "empty object used")
      if (self->lumi_path_Refman->value == NULL) RAISE(268, 28, "outdated weak reference used")
      if (self->lumi_path == NULL) RAISE(268, 17, "empty object used")
      if (self->lumi_path_Refman->value == NULL) RAISE(268, 28, "outdated weak reference used")
      if ((self->lumi_path->length - 1) < 0 || (self->lumi_path->length - 1) >= (self->lumi_path)->length) RAISE(268, 25, "slice index out of bounds")
      last = ((self->lumi_path)->values)[self->lumi_path->length - 1];
      if (last == '\\') {
        if (self == NULL) RAISE(270, 17, "empty object used")
        if (self_Refman->value == NULL) RAISE(270, 28, "outdated weak reference used")
        self->path_separator = '\\';
      }
      if (self == NULL) RAISE(271, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(271, 28, "outdated weak reference used")
      if (self == NULL) RAISE(271, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(271, 28, "outdated weak reference used")
      self->lumi_path_ends_with_separator = last == self->path_separator;
    }
  if (self == NULL) RAISE(272, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(272, 28, "outdated weak reference used")
  aux_String_3 = &aux_String_3_Var;
  aux_String_3_Refman = LUMI_new_ref(aux_String_3);
  if (aux_String_3_Refman == NULL) RAISE(272, 38, "insufficient memory for managed object")
  aux_String_3_Var.max_length = 4;
  aux_String_3_Var.length = 3;
  aux_String_3_Var.values = " -g";
  LUMI_err = String_concat(self->command, self->command_Refman, aux_String_3, aux_String_3_Refman);
  CHECK(272)
  if (self == NULL) RAISE(273, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(273, 28, "outdated weak reference used")
  if (self->running_lumi) {
      if (self == NULL) RAISE(274, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(274, 28, "outdated weak reference used")
      if (self == NULL) RAISE(274, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(274, 28, "outdated weak reference used")
      if (self == NULL) RAISE(274, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(274, 28, "outdated weak reference used")
      if (((self->version >= '2') && (self->version <= '3')) && self->explicit_output) {
        if (self == NULL) RAISE(275, 17, "empty object used")
        if (self_Refman->value == NULL) RAISE(275, 28, "outdated weak reference used")
        aux_String_4 = &aux_String_4_Var;
        aux_String_4_Refman = LUMI_new_ref(aux_String_4);
        if (aux_String_4_Refman == NULL) RAISE(275, 38, "insufficient memory for managed object")
        aux_String_4_Var.max_length = 3;
        aux_String_4_Var.length = 2;
        aux_String_4_Var.values = " \"";
        LUMI_err = String_concat(self->command, self->command_Refman, aux_String_4, aux_String_4_Refman);
        CHECK(275)
        if (self == NULL) RAISE(276, 17, "empty object used")
        if (self_Refman->value == NULL) RAISE(276, 28, "outdated weak reference used")
        if (self == NULL) RAISE(277, 17, "empty object used")
        if (self_Refman->value == NULL) RAISE(277, 28, "outdated weak reference used")
        if (self == NULL) RAISE(277, 17, "empty object used")
        if (self_Refman->value == NULL) RAISE(277, 28, "outdated weak reference used")
        if (self->main_input == NULL) RAISE(277, 17, "empty object used")
        if (self->main_input_Refman->value == NULL) RAISE(277, 28, "outdated weak reference used")
        aux_String_5 = &aux_String_5_Var;
        aux_String_5_Refman = LUMI_new_ref(aux_String_5);
        if (aux_String_5_Refman == NULL) RAISE(277, 38, "insufficient memory for managed object")
        aux_String_5_Var.length = self->main_input->length - 5;
        aux_String_5_Var.max_length = aux_String_5_Var.length + 1;
        aux_String_5_Var.values = (self->main_input)->values + (0);
        if (self->main_input == NULL) RAISE(277, 17, "empty object used")
        if (self->main_input_Refman->value == NULL) RAISE(277, 28, "outdated weak reference used")
        if ((0) < 0 || (self->main_input->length - 5) < 0 || (0) + (self->main_input->length - 5) > (self->main_input)->length) RAISE(277, 25, "slice index out of bounds")
        LUMI_err = String_concat(self->command, self->command_Refman, aux_String_5, self->main_input_Refman);
        CHECK(276)
        if (self == NULL) RAISE(278, 17, "empty object used")
        if (self_Refman->value == NULL) RAISE(278, 28, "outdated weak reference used")
        aux_String_6 = &aux_String_6_Var;
        aux_String_6_Refman = LUMI_new_ref(aux_String_6);
        if (aux_String_6_Refman == NULL) RAISE(278, 38, "insufficient memory for managed object")
        aux_String_6_Var.max_length = 4;
        aux_String_6_Var.length = 3;
        aux_String_6_Var.values = ".c\"";
        LUMI_err = String_concat(self->command, self->command_Refman, aux_String_6, aux_String_6_Refman);
        CHECK(278)
      }
      else {
        LUMI_err = lumi_M_Lumi_concat_lumi_output(self, self_Refman);
        CHECK(280)
      }
    }
  else {
      if (self == NULL) RAISE(282, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(282, 28, "outdated weak reference used")
      if (self == NULL) RAISE(282, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(282, 28, "outdated weak reference used")
      LUMI_err = String_concat(self->command, self->command_Refman, self->input_files, self->input_files_Refman);
      CHECK(282)
    }
  if (self == NULL) RAISE(283, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(283, 28, "outdated weak reference used")
  if (self == NULL) RAISE(283, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(283, 28, "outdated weak reference used")
  LUMI_err = String_concat(self->command, self->command_Refman, self->external_files, self->external_files_Refman);
  CHECK(283)
  if (self == NULL) RAISE(284, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(284, 28, "outdated weak reference used")
  aux_String_7 = &aux_String_7_Var;
  aux_String_7_Refman = LUMI_new_ref(aux_String_7);
  if (aux_String_7_Refman == NULL) RAISE(284, 38, "insufficient memory for managed object")
  aux_String_7_Var.max_length = 2;
  aux_String_7_Var.length = 1;
  aux_String_7_Var.values = " ";
  LUMI_err = String_concat(self->command, self->command_Refman, aux_String_7, aux_String_7_Refman);
  CHECK(284)
  LUMI_err = lumi_M_Lumi_concat_tl_path(self, self_Refman);
  CHECK(285)
  if (self == NULL) RAISE(286, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(286, 28, "outdated weak reference used")
  if (self->version == '0') {
      if (self == NULL) RAISE(287, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(287, 28, "outdated weak reference used")
      aux_String_8 = &aux_String_8_Var;
      aux_String_8_Refman = LUMI_new_ref(aux_String_8);
      if (aux_String_8_Refman == NULL) RAISE(287, 38, "insufficient memory for managed object")
      aux_String_8_Var.max_length = 12;
      aux_String_8_Var.length = 11;
      aux_String_8_Var.values = "tl0-file.c ";
      LUMI_err = String_concat(self->command, self->command_Refman, aux_String_8, aux_String_8_Refman);
      CHECK(287)
      LUMI_err = lumi_M_Lumi_concat_tl_path(self, self_Refman);
      CHECK(288)
      if (self == NULL) RAISE(289, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(289, 28, "outdated weak reference used")
      aux_String_9 = &aux_String_9_Var;
      aux_String_9_Refman = LUMI_new_ref(aux_String_9);
      if (aux_String_9_Refman == NULL) RAISE(289, 38, "insufficient memory for managed object")
      aux_String_9_Var.max_length = 13;
      aux_String_9_Var.length = 12;
      aux_String_9_Var.values = "tl0-string.c";
      LUMI_err = String_concat(self->command, self->command_Refman, aux_String_9, aux_String_9_Refman);
      CHECK(289)
    }
  else {
      if (self == NULL) RAISE(291, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(291, 28, "outdated weak reference used")
      aux_String_10 = &aux_String_10_Var;
      aux_String_10_Refman = LUMI_new_ref(aux_String_10);
      if (aux_String_10_Refman == NULL) RAISE(291, 38, "insufficient memory for managed object")
      aux_String_10_Var.max_length = 6;
      aux_String_10_Var.length = 5;
      aux_String_10_Var.values = "lumi.";
      LUMI_err = String_concat(self->command, self->command_Refman, aux_String_10, aux_String_10_Refman);
      CHECK(291)
      if (self == NULL) RAISE(292, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(292, 28, "outdated weak reference used")
      if (self == NULL) RAISE(292, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(292, 28, "outdated weak reference used")
      LUMI_err = String_append(self->command, self->command_Refman, self->version);
      CHECK(292)
      if (self == NULL) RAISE(293, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(293, 28, "outdated weak reference used")
      aux_String_11 = &aux_String_11_Var;
      aux_String_11_Refman = LUMI_new_ref(aux_String_11);
      if (aux_String_11_Refman == NULL) RAISE(293, 38, "insufficient memory for managed object")
      aux_String_11_Var.max_length = 3;
      aux_String_11_Var.length = 2;
      aux_String_11_Var.values = ".c";
      LUMI_err = String_concat(self->command, self->command_Refman, aux_String_11, aux_String_11_Refman);
      CHECK(293)
    }
  if (self == NULL) RAISE(294, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(294, 28, "outdated weak reference used")
  aux_String_12 = &aux_String_12_Var;
  aux_String_12_Refman = LUMI_new_ref(aux_String_12);
  if (aux_String_12_Refman == NULL) RAISE(294, 38, "insufficient memory for managed object")
  aux_String_12_Var.max_length = 4;
  aux_String_12_Var.length = 3;
  aux_String_12_Var.values = " -I";
  LUMI_err = String_concat(self->command, self->command_Refman, aux_String_12, aux_String_12_Refman);
  CHECK(294)
  LUMI_err = lumi_M_Lumi_concat_tl_path(self, self_Refman);
  CHECK(295)
  if (self == NULL) RAISE(296, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(296, 28, "outdated weak reference used")
  aux_String_13 = &aux_String_13_Var;
  aux_String_13_Refman = LUMI_new_ref(aux_String_13);
  if (aux_String_13_Refman == NULL) RAISE(296, 38, "insufficient memory for managed object")
  aux_String_13_Var.max_length = 4;
  aux_String_13_Var.length = 3;
  aux_String_13_Var.values = " -o";
  LUMI_err = String_concat(self->command, self->command_Refman, aux_String_13, aux_String_13_Refman);
  CHECK(296)
  if (self == NULL) RAISE(297, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(297, 28, "outdated weak reference used")
  if (self == NULL) RAISE(297, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(297, 28, "outdated weak reference used")
  LUMI_err = lumi_M_Lumi_concat_file_name(self, self_Refman, self->command, self->command_Refman, self->output, self->output_Refman);
  CHECK(297)
  aux_String_14 = &aux_String_14_Var;
  aux_String_14_Refman = LUMI_new_ref(aux_String_14);
  if (aux_String_14_Refman == NULL) RAISE(298, 38, "insufficient memory for managed object")
  aux_String_14_Var.max_length = 18;
  aux_String_14_Var.length = 17;
  aux_String_14_Var.values = "C compiler failed";
  LUMI_err = lumi_M_Lumi_run_command(self, self_Refman, aux_String_14, aux_String_14_Refman);
  CHECK(298)
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
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.run-program"
Returncode lumi_M_Lumi_run_program(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  Bool aux_Bool_0 = 0;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_inc_ref(self_Refman);
  if (self == NULL) RAISE(301, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(301, 28, "outdated weak reference used")
  LUMI_err = String_clear(self->command, self->command_Refman);
  CHECK(301)
  if (self == NULL) RAISE(302, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(302, 28, "outdated weak reference used")
  if (self == NULL) RAISE(302, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(302, 28, "outdated weak reference used")
  LUMI_err = String_has(self->output, self->output_Refman, self->path_separator, &(aux_Bool_0));
  CHECK(302)
  if (! aux_Bool_0) {
      if (self == NULL) RAISE(303, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(303, 28, "outdated weak reference used")
      LUMI_err = String_append(self->command, self->command_Refman, '.');
      CHECK(303)
      if (self == NULL) RAISE(304, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(304, 28, "outdated weak reference used")
      if (self == NULL) RAISE(304, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(304, 28, "outdated weak reference used")
      LUMI_err = String_append(self->command, self->command_Refman, self->path_separator);
      CHECK(304)
    }
  if (self == NULL) RAISE(305, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(305, 28, "outdated weak reference used")
  if (self == NULL) RAISE(305, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(305, 28, "outdated weak reference used")
  LUMI_err = lumi_M_Lumi_concat_first_file_name(self, self_Refman, self->command, self->command_Refman, self->output, self->output_Refman);
  CHECK(305)
  if (self == NULL) RAISE(306, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(306, 28, "outdated weak reference used")
  if (self->execute_arguments != NULL && self->execute_arguments_Refman->value != NULL) {
      if (self == NULL) RAISE(307, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(307, 28, "outdated weak reference used")
      aux_String_0 = &aux_String_0_Var;
      aux_String_0_Refman = LUMI_new_ref(aux_String_0);
      if (aux_String_0_Refman == NULL) RAISE(307, 38, "insufficient memory for managed object")
      aux_String_0_Var.max_length = 2;
      aux_String_0_Var.length = 1;
      aux_String_0_Var.values = " ";
      LUMI_err = String_concat(self->command, self->command_Refman, aux_String_0, aux_String_0_Refman);
      CHECK(307)
      if (self == NULL) RAISE(308, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(308, 28, "outdated weak reference used")
      if (self == NULL) RAISE(308, 17, "empty object used")
      if (self_Refman->value == NULL) RAISE(308, 28, "outdated weak reference used")
      LUMI_err = String_concat(self->command, self->command_Refman, self->execute_arguments, self->execute_arguments_Refman);
      CHECK(308)
    }
  LUMI_err = lumi_M_Lumi_run_command(self, self_Refman, NULL, NULL);
  CHECK(309)
LUMI_cleanup:
  LUMI_dec_ref(aux_String_0_Refman);
  LUMI_dec_ref(self_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "Lumi.run"
Returncode lumi_M_Lumi_run(lumi_M_Lumi* self, Ref_Manager* self_Refman) {
  Returncode LUMI_err = OK;
  LUMI_inc_ref(self_Refman);
  LUMI_err = lumi_M_Lumi_read_input(self, self_Refman);
  CHECK(312)
  if (self == NULL) RAISE(313, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(313, 28, "outdated weak reference used")
  if (self->running_lumi) {
      LUMI_err = lumi_M_Lumi_run_lumi(self, self_Refman);
      CHECK(314)
    }
  if (self == NULL) RAISE(315, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(315, 28, "outdated weak reference used")
  if (self->running_c) {
      LUMI_err = lumi_M_Lumi_run_c(self, self_Refman);
      CHECK(316)
    }
  if (self == NULL) RAISE(317, 17, "empty object used")
  if (self_Refman->value == NULL) RAISE(317, 28, "outdated weak reference used")
  if (self->running_program) {
      LUMI_err = lumi_M_Lumi_run_program(self, self_Refman);
      CHECK(318)
    }
LUMI_cleanup:
  LUMI_dec_ref(self_Refman);
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

#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "help"
Returncode lumi_M_help(void) {
  Returncode LUMI_err = OK;
  String aux_String_0_Var = {0};
  String* aux_String_0 = NULL;
  Ref_Manager* aux_String_0_Refman = NULL;
  LUMI_err = Sys_println(sys, sys_Refman, lumi_M_usage, lumi_M_usage_Refman);
  CHECK(39)
  aux_String_0 = &aux_String_0_Var;
  aux_String_0_Refman = LUMI_new_ref(aux_String_0);
  if (aux_String_0_Refman == NULL) RAISE(51, 38, "insufficient memory for managed object")
  aux_String_0_Var.max_length = 463;
  aux_String_0_Var.length = 462;
  aux_String_0_Var.values = "Options:\n  -h \t\t print help\n  -o <file> \t output file name\n  -t <module> \t compile test program for <module>\n  -c \t\t only create C file(s)\n  -l<version> \t only run C compiler for TL<version>\n  -e <file> \t external C file for C compilation\n  -p <lumipath>  path of lumi-lang repository\n  -r \t\t   run the compiled program\n  -ra <arguments>  run the compiled program with given arguments\n  -v \t\t print executed commands\n  -d \t\t only print commands without execution";
  LUMI_err = Sys_println(sys, sys_Refman, aux_String_0, aux_String_0_Refman);
  CHECK(40)
  LUMI_err = Sys_exit(sys, sys_Refman, 0);
  CHECK(52)
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
#define RETURN_ERROR return LUMI_err;
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
#define RETURN_ERROR goto LUMI_cleanup
#define LUMI_FILE_NAME "lumi.4.lm"
#define LUMI_FUNC_NAME "main"
  lumi_object = &lumi_object_Var;
  lumi_object_Refman = LUMI_new_ref(lumi_object);
  if (lumi_object_Refman == NULL) RAISE(322, 38, "insufficient memory for managed object")
  LUMI_err = lumi_M_Lumi_new(lumi_object, lumi_object_Refman);
  CHECK(322)
  LUMI_err = lumi_M_Lumi_run(lumi_object, lumi_object_Refman);
  CHECK(323)
LUMI_cleanup:
  LUMI_dec_ref(lumi_object_Refman);
  return LUMI_err;
}
#undef LUMI_FILE_NAME
#undef LUMI_FUNC_NAME

MAIN_FUNC
