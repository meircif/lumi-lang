#include "lumi.2.h"
#include "common.c"
#include "map.c"
#include "global.c"
#include "exp.c"
#include "st-node.c"
#include "flow.c"
#include "args.c"
#include "func.c"
#include "member.c"
#include "call.c"
#include "operand.c"
#include "dec.c"
#include "type.c"
#include "test.c"

static char* _lumi_file15_name = "tl3-compiler.2.lm";
#define LUMI_FILE_NAME _lumi_file15_name
/* TL3 compiler main - written in TL2 */


static char* _func_name_add_kwn = "add-kwn";
#define LUMI_FUNC_NAME _func_name_add_kwn
Returncode add_kwn(Int index, String* key, Type node_type) {
  if ((index) < 0 || (index) >= glob->key_word_map->length) RAISE(5)
  Node_map_item* item = ((Node_map_item*)(glob->key_word_map->values)) + index;
  CHECK(6, f_new_copy(key, &(item->key)));
  item->node_type = node_type;
  return OK;
}
#undef LUMI_FUNC_NAME

static char* _func_name_f_create_key_word_map = "f-create-key-word-map";
#define LUMI_FUNC_NAME _func_name_f_create_key_word_map
Returncode f_create_key_word_map() {
  Array* key_word_map = new_array(26, sizeof(Node_map_item));
  if (key_word_map == NULL) RAISE(10)
  glob->key_word_map = key_word_map;
  CHECK(12, add_kwn(0, &(String){2, 1, "#"}, (Type){sizeof(St_comment), St_comment__dtl}));
  CHECK(13, add_kwn(1, &(String){5, 4, "func"}, (Type){sizeof(St_func), St_func__dtl}));
  CHECK(14, add_kwn(2, &(String){7, 6, "native"}, (Type){sizeof(St_native), St_native__dtl}));
  CHECK(15, add_kwn(3, &(String){5, 4, "main"}, (Type){sizeof(St_main), St_main__dtl}));
  CHECK(16, add_kwn(4, &(String){4, 3, "var"}, (Type){sizeof(St_var), St_var__dtl}));
  CHECK(17, add_kwn(5, &(String){6, 5, "owner"}, (Type){sizeof(St_ref), St_ref__dtl}));
  CHECK(18, add_kwn(6, &(String){5, 4, "user"}, (Type){sizeof(St_ref), St_ref__dtl}));
  CHECK(19, add_kwn(7, &(String){4, 3, "new"}, (Type){sizeof(St_new), St_new__dtl}));
  CHECK(20, add_kwn(8, &(String){7, 6, "delete"}, (Type){sizeof(St_delete), St_delete__dtl}));
  CHECK(21, add_kwn(9, &(String){3, 2, "if"}, (Type){sizeof(St_if), St_if__dtl}));
  CHECK(22, add_kwn(10, &(String){5, 4, "else"}, (Type){sizeof(St_else), St_else__dtl}));
  CHECK(23, add_kwn(11, &(String){8, 7, "else-if"}, (Type){sizeof(St_else_if), St_else_if__dtl}));
  CHECK(24, add_kwn(12, &(String){3, 2, "do"}, (Type){sizeof(St_do), St_do__dtl}));
  CHECK(25, add_kwn(13, &(String){6, 5, "while"}, (Type){sizeof(St_while), St_while__dtl}));
  CHECK(26, add_kwn(14, &(String){4, 3, "for"}, (Type){sizeof(St_for), St_for__dtl}));
  CHECK(27, add_kwn(15, &(String){7, 6, "return"}, (Type){sizeof(St_return), St_return__dtl}));
  CHECK(28, add_kwn(16, &(String){6, 5, "raise"}, (Type){sizeof(St_raise), St_raise__dtl}));
  CHECK(29, add_kwn(17, &(String){7, 6, "static"}, (Type){sizeof(St_static_class), St_static_class__dtl}));
  CHECK(30, add_kwn(18, &(String){6, 5, "class"}, (Type){sizeof(St_dynamic_class), St_dynamic_class__dtl}));
  CHECK(31, add_kwn(19, &(String){3, 2, "##"}, (Type){sizeof(St_documentation), St_documentation__dtl}));
  CHECK(32, add_kwn(20, &(String){2, 1, "*"}, (Type){sizeof(St_format), St_format__dtl}));
  CHECK(33, add_kwn(21, &(String){7, 6, "assert"}, (Type){sizeof(St_assert), St_assert__dtl}));
  CHECK(34, add_kwn(22, &(String){13, 12, "assert-error"}, (Type){sizeof(St_assert_error), St_assert_error__dtl}));
  CHECK(35, add_kwn(23, &(String){5, 4, "test"}, (Type){sizeof(St_test), St_test__dtl}));
  CHECK(36, add_kwn(24, &(String){5, 4, "mock"}, (Type){sizeof(St_mock), St_mock__dtl}));
  CHECK(37, add_kwn(25, &(String){6, 5, "debug"}, (Type){sizeof(St_debug), St_debug__dtl}));
  return OK;
}
#undef LUMI_FUNC_NAME


static char* _func_name_add_global_func = "add-global-func";
#define LUMI_FUNC_NAME _func_name_add_global_func
Returncode add_global_func(Mtype* mtype, String* name, Mfunc** new_meth) {
  Mfunc* meth = malloc(sizeof(Mfunc));
  if (meth == NULL) RAISE(41)
  CHECK(42, Mfunc_init(meth, name));
  if (NULL != mtype) {
    Mvar* _Mvar0;
    CHECK(44, Mfunc_m_new_var(meth, &(_Mvar0)))
    CHECK(44, add_var(mtype->members, _Mvar0));
  }
  else {
    Mvar* _Mvar1;
    CHECK(46, Mfunc_m_new_var(meth, &(_Mvar1)))
    CHECK(46, add_var(glob->var_map, _Mvar1));
  }
  (*new_meth) = meth;
  return OK;
}
#undef LUMI_FUNC_NAME

static char* _func_name_add_new_var = "add-new-var";
#define LUMI_FUNC_NAME _func_name_add_new_var
Returncode add_new_var(Mtype* mtype, String* name, Var_map* map) {
  Mvar* mvar;
  CHECK(51, init_new_var(mtype, &(mvar)));
  CHECK(52, f_new_copy(name, &(mvar->name)));
  CHECK(53, f_new_copy(mtype->name, &(mvar->typename)));
  CHECK(54, add_var(map, mvar));
  return OK;
}
#undef LUMI_FUNC_NAME

static char* _func_name_add_member = "add-member";
#define LUMI_FUNC_NAME _func_name_add_member
Returncode add_member(Mtype* mtype, String* name, Mtype* member_type) {
  CHECK(57, add_new_var(member_type, name, mtype->members));
  return OK;
}
#undef LUMI_FUNC_NAME

static char* _func_name_add_glob_var = "add-glob-var";
#define LUMI_FUNC_NAME _func_name_add_glob_var
Returncode add_glob_var(Mtype* mtype, String* name) {
  CHECK(60, add_new_var(mtype, name, glob->var_map));
  return OK;
}
#undef LUMI_FUNC_NAME


static char* _func_name_f_create_global_var_map = "f-create-global-var-map";
#define LUMI_FUNC_NAME _func_name_f_create_global_var_map
Returncode f_create_global_var_map() {
  Var_map* map = malloc(sizeof(Var_map));
  if (map == NULL) RAISE(64)
  CHECK(65, Name_map_init(&(map->_base)));
  glob->var_map = map;
  Mfunc* meth;
  
  /* Int */
  CHECK(70, add_global_func(glob->type_int, &(String){4, 3, "str"}, &(meth)));
  CHECK(71, Arg_list_add_param(meth->args, ACCESS_USER, glob->type_string, &(String){4, 3, "str"}));
  CHECK(72, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_int, &(String){5, 4, "self"}));
  
  /* Bool */
  CHECK(75, add_glob_var(glob->type_bool, &(String){5, 4, "true"}));
  CHECK(76, add_glob_var(glob->type_bool, &(String){6, 5, "false"}));
  
  /* Char */
  /* add-glob-var(user glob.type-char, user "EOF") */
  
  /* String */
  CHECK(82, add_member(glob->type_string, &(String){7, 6, "length"}, glob->type_int));
  
  CHECK(84, add_global_func(glob->type_string, &(String){6, 5, "clear"}, &(meth)));
  CHECK(85, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_string, &(String){5, 4, "self"}));
  
  CHECK(87, add_global_func(glob->type_string, &(String){6, 5, "equal"}, &(meth)));
  CHECK(88, Arg_list_add_out(meth->args, ACCESS_COPY, glob->type_bool, &(String){6, 5, "equal"}));
  CHECK(89, Arg_list_add_param(meth->args, ACCESS_USER, glob->type_string, &(String){8, 7, "pattern"}));
  CHECK(90, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_string, &(String){5, 4, "self"}));
  
  CHECK(92, add_global_func(glob->type_string, &(String){4, 3, "get"}, &(meth)));
  CHECK(93, Arg_list_add_out(meth->args, ACCESS_COPY, glob->type_char, &(String){3, 2, "ch"}));
  CHECK(94, Arg_list_add_param(meth->args, ACCESS_COPY, glob->type_int, &(String){6, 5, "index"}));
  CHECK(95, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_string, &(String){5, 4, "self"}));
  
  CHECK(97, add_global_func(glob->type_string, &(String){7, 6, "append"}, &(meth)));
  CHECK(98, Arg_list_add_param(meth->args, ACCESS_COPY, glob->type_char, &(String){3, 2, "ch"}));
  CHECK(99, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_string, &(String){5, 4, "self"}));
  
  CHECK(101, add_global_func(glob->type_string, &(String){5, 4, "copy"}, &(meth)));
  CHECK(102, Arg_list_add_param(meth->args, ACCESS_USER, glob->type_string, &(String){6, 5, "other"}));
  CHECK(103, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_string, &(String){5, 4, "self"}));
  
  CHECK(105, add_global_func(glob->type_string, &(String){7, 6, "concat"}, &(meth)));
  CHECK(106, Arg_list_add_param(meth->args, ACCESS_USER, glob->type_string, &(String){6, 5, "other"}));
  CHECK(107, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_string, &(String){5, 4, "self"}));
  
  CHECK(109, add_global_func(glob->type_string, &(String){11, 10, "concat-int"}, &(meth)));
  CHECK(110, Arg_list_add_param(meth->args, ACCESS_COPY, glob->type_int, &(String){7, 6, "number"}));
  CHECK(111, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_string, &(String){5, 4, "self"}));
  
  CHECK(113, add_global_func(glob->type_string, &(String){5, 4, "find"}, &(meth)));
  CHECK(114, Arg_list_add_out(meth->args, ACCESS_COPY, glob->type_int, &(String){6, 5, "index"}));
  CHECK(115, Arg_list_add_param(meth->args, ACCESS_USER, glob->type_string, &(String){8, 7, "pattern"}));
  CHECK(116, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_string, &(String){5, 4, "self"}));
  
  CHECK(118, add_global_func(glob->type_string, &(String){8, 7, "replace"}, &(meth)));
  CHECK(119, Arg_list_add_param(meth->args, ACCESS_COPY, glob->type_char, &(String){6, 5, "newch"}));
  CHECK(120, Arg_list_add_param(meth->args, ACCESS_COPY, glob->type_char, &(String){6, 5, "oldch"}));
  CHECK(121, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_string, &(String){5, 4, "self"}));
  
  CHECK(123, add_global_func(glob->type_string, &(String){4, 3, "has"}, &(meth)));
  CHECK(124, Arg_list_add_out(meth->args, ACCESS_COPY, glob->type_bool, &(String){6, 5, "equal"}));
  CHECK(125, Arg_list_add_param(meth->args, ACCESS_COPY, glob->type_char, &(String){3, 2, "ch"}));
  CHECK(126, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_string, &(String){5, 4, "self"}));
  
  /* Array */
  CHECK(129, add_member(glob->type_array, &(String){7, 6, "length"}, glob->type_int));
  
  /* File */
  CHECK(132, add_global_func(glob->type_file, &(String){6, 5, "close"}, &(meth)));
  CHECK(133, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_file, &(String){5, 4, "self"}));
  
  CHECK(135, add_global_func(glob->type_file, &(String){5, 4, "getc"}, &(meth)));
  CHECK(136, Arg_list_add_out(meth->args, ACCESS_COPY, glob->type_char, &(String){3, 2, "ch"}));
  CHECK(137, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_file, &(String){5, 4, "self"}));
  
  CHECK(139, add_global_func(glob->type_file, &(String){5, 4, "putc"}, &(meth)));
  CHECK(140, Arg_list_add_param(meth->args, ACCESS_COPY, glob->type_char, &(String){3, 2, "ch"}));
  CHECK(141, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_file, &(String){5, 4, "self"}));
  
  CHECK(143, add_global_func(glob->type_file, &(String){6, 5, "write"}, &(meth)));
  CHECK(144, Arg_list_add_param(meth->args, ACCESS_USER, glob->type_string, &(String){5, 4, "text"}));
  CHECK(145, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_file, &(String){5, 4, "self"}));
  
  CHECK(147, add_global_func(NULL, &(String){15, 14, "file-open-read"}, &(meth)));
  CHECK(148, Arg_list_add_out(meth->args, ACCESS_OWNER, glob->type_file, &(String){5, 4, "file"}));
  CHECK(149, Arg_list_add_param(meth->args, ACCESS_USER, glob->type_string, &(String){5, 4, "name"}));
  
  CHECK(151, add_global_func(NULL, &(String){16, 15, "file-open-write"}, &(meth)));
  CHECK(152, Arg_list_add_out(meth->args, ACCESS_OWNER, glob->type_file, &(String){5, 4, "file"}));
  CHECK(153, Arg_list_add_param(meth->args, ACCESS_USER, glob->type_string, &(String){5, 4, "name"}));
  
  /* Sys */
  CHECK(156, add_global_func(glob->type_sys, &(String){6, 5, "print"}, &(meth)));
  CHECK(157, Arg_list_add_param(meth->args, ACCESS_USER, glob->type_string, &(String){5, 4, "text"}));
  CHECK(158, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_sys, &(String){5, 4, "self"}));
  
  CHECK(160, add_global_func(glob->type_sys, &(String){10, 9, "print-raw"}, &(meth)));
  CHECK(161, Arg_list_add_param(meth->args, ACCESS_USER, glob->type_string, &(String){5, 4, "text"}));
  CHECK(162, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_sys, &(String){5, 4, "self"}));
  
  CHECK(164, add_global_func(glob->type_sys, &(String){5, 4, "exit"}, &(meth)));
  CHECK(165, Arg_list_add_param(meth->args, ACCESS_COPY, glob->type_int, &(String){7, 6, "status"}));
  CHECK(166, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_sys, &(String){5, 4, "self"}));
  
  CHECK(168, add_global_func(glob->type_sys, &(String){7, 6, "system"}, &(meth)));
  CHECK(169, Arg_list_add_out(meth->args, ACCESS_COPY, glob->type_int, &(String){7, 6, "status"}));
  CHECK(170, Arg_list_add_param(meth->args, ACCESS_USER, glob->type_string, &(String){8, 7, "command"}));
  CHECK(171, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_sys, &(String){5, 4, "self"}));
  
  CHECK(173, add_global_func(glob->type_sys, &(String){7, 6, "getenv"}, &(meth)));
  CHECK(174, Arg_list_add_out(meth->args, ACCESS_COPY, glob->type_bool, &(String){7, 6, "exists"}));
  CHECK(175, Arg_list_add_param(meth->args, ACCESS_USER, glob->type_string, &(String){6, 5, "value"}));
  CHECK(176, Arg_list_add_param(meth->args, ACCESS_USER, glob->type_string, &(String){5, 4, "name"}));
  CHECK(177, Arg_list_add_param(meth->args, ACCESS_VAR, glob->type_sys, &(String){5, 4, "self"}));
  
  CHECK(179, add_glob_var(glob->type_sys, &(String){4, 3, "sys"}));
  return OK;
}
#undef LUMI_FUNC_NAME


static char* _func_name_init_global_data = "init-global-data";
#define LUMI_FUNC_NAME _func_name_init_global_data
Returncode init_global_data() {
  CHECK(183, Global_data_init(glob));
  CHECK(184, f_create_key_word_map());
  CHECK(185, f_create_global_var_map());
  return OK;
}
#undef LUMI_FUNC_NAME


static char* _func_name_func = "func";
#define LUMI_FUNC_NAME _func_name_func
Returncode func(Array* argv) {
  CHECK(189, Sys_print(sys, &(String){19, 18, "TL3 compiler start"}));
  
  if (argv->length < 2) {
    CHECK(192, Sys_print(sys, &(String){42, 41, "usage: tl3-compiler [input Lumi files]..."}));
    return OK;
  }
  
  CHECK(195, init_global_data());
  St_root* root = &(St_root){0};
  *((Func**)(root)) = St_root__dtl;
  CHECK(197, St_root_init(root, argv));
  
  CHECK(199, (*((Func**)(root)))[0](root));
  CHECK(200, (*((Func**)(root)))[2](root));
  CHECK(201, (*((Func**)(root)))[3](root));
  
  CHECK(203, Sys_print(sys, &(String){17, 16, "TL3 compiler end"}));
  return OK;
}
#undef LUMI_FUNC_NAME

MAIN_FUNC

#undef LUMI_FILE_NAME
