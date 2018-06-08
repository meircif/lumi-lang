#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "global/global.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file5_name = "global/global.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file5_name

/* TL4 compiler - Global compiler data */

/* Access values */
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Int ACCESS_UNDEFINED;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Int ACCESS_UNDEFINED = 0;
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Int ACCESS_COPY;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Int ACCESS_COPY = 1;
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Int ACCESS_USER;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Int ACCESS_USER = 2;
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Int ACCESS_OWNER;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Int ACCESS_OWNER = 3;
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Int ACCESS_VAR;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Int ACCESS_VAR = 4;
#endif


#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct Global Global;
#elif LUMI_STAGE == LUMI_TYPES(0)
struct Global {
/* stores all user defined nodes */  SyntaxTreeRoot* root;
/* stores all built-in nodes */  GlobalNodes* builtins;
/* stores all language operators */  List* operators;
/* maps all global-scope nodes */  ModuleMembers* global_module;
/* maps all language operators */  NameMap* operator_map;
/* maps all modules */  NameMap* module_map;
/* maps access number to its name */  Array* access_names;
/* the currently parsed input file object */  File* input_file;
/* the currently written output file object */  File* output_file;
/* holds the name of the input-file and the line number of the code currently *//* been worked with */  String* input_file_name;
  ModuleMembers* current_module;
  Int input_file_index;
  Int line_number;
/* test functions list */  NameMap* test_functions;
  String* tested_module;
  Bool is_new_mocked;
  Bool is_delete_mocked;
/* input reading state */  String* input_buffer;
  Char input_end;
  Int input_spaces;
  Bool got_new_line;
  Bool save_input;
/* built-in types */  TypeData* type_char;
  TypeData* type_bool;
  TypeData* type_int;
  TypeData* type_empty;
  TypeData* type_func;
  TypeData* type_ref;
  TypeData* type_string;
  TypeData* type_array;
  TypeData* type_type;
  TypeData* type_base;
  TypeData* type_generic;
  TypeData* type_module;
  TypeData* type_file;
  TypeData* type_sys;
};
#endif/* stores all user defined nodes *//* stores all built-in nodes *//* stores all language operators *//* maps all global-scope nodes *//* maps all language operators *//* maps all modules *//* maps access number to its name *//* the currently parsed input file object *//* the currently written output file object *//* holds the name of the input-file and the line number of the code currently *//* been worked with *//* test functions list *//* input reading state *//* built-in types */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_init(Global* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_init = "Global.init";
#define LUMI_FUNC_NAME _func_name_Global_init
Returncode Global_init(Global* self) {
  self->got_new_line = false;
  self->save_input = false;
  self->is_new_mocked = false;
  self->is_delete_mocked = false;
  self->tested_module = NULL;
  self->root = malloc(sizeof(SyntaxTreeRoot));
  if (self->root == NULL) RAISE(81)
  *self->root = (SyntaxTreeRoot){SyntaxTreeRoot__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  self->root->_base._base._base._base._dtl = SyntaxTreeRoot__dtl;
  CHECK(82, SyntaxTreeRoot_init(self->root) )
  self->builtins = malloc(sizeof(GlobalNodes));
  if (self->builtins == NULL) RAISE(83)
  *self->builtins = (GlobalNodes){GlobalNodes__dtl, NULL, 0, 0, NULL, NULL, NULL};
  self->builtins->_base._base._base._dtl = GlobalNodes__dtl;
  CHECK(84, GlobalNodes_init(self->builtins) )
  self->operators = malloc(sizeof(List));
  if (self->operators == NULL) RAISE(85)
  *self->operators = (List){NULL, NULL};
  self->input_buffer = _new_string(1024);
  if (self->input_buffer == NULL) RAISE(86)
  self->test_functions = malloc(sizeof(NameMap));
  if (self->test_functions == NULL) RAISE(87)
  *self->test_functions = (NameMap){NULL, NULL};
  self->global_module = malloc(sizeof(ModuleMembers));
  if (self->global_module == NULL) RAISE(88)
  *self->global_module = (ModuleMembers){NULL, NULL, NULL, NULL, NULL};
  CHECK(89, ModuleMembers_init(self->global_module, NULL) )
  self->module_map = malloc(sizeof(NameMap));
  if (self->module_map == NULL) RAISE(90)
  *self->module_map = (NameMap){NULL, NULL};
  CHECK(91, Global_init_operator_map(self) )
  CHECK(92, Global_init_builtin_types(self) )
  self->access_names = _new_array(5, sizeof(String) + (16));
  if (self->access_names == NULL) RAISE(93)
  _set_new_string_array(5, 16, self->access_names);
  if ((ACCESS_UNDEFINED) < 0 || (ACCESS_UNDEFINED) >= (self->access_names)->length) RAISE(94)
  CHECK(94, String_copy((&(((String*)((self->access_names)->values))[ACCESS_UNDEFINED])), &(String){10, 9, "undefined"}) )
  if ((ACCESS_COPY) < 0 || (ACCESS_COPY) >= (self->access_names)->length) RAISE(95)
  CHECK(95, String_copy((&(((String*)((self->access_names)->values))[ACCESS_COPY])), &(String){5, 4, "copy"}) )
  if ((ACCESS_USER) < 0 || (ACCESS_USER) >= (self->access_names)->length) RAISE(96)
  CHECK(96, String_copy((&(((String*)((self->access_names)->values))[ACCESS_USER])), &(String){5, 4, "user"}) )
  if ((ACCESS_OWNER) < 0 || (ACCESS_OWNER) >= (self->access_names)->length) RAISE(97)
  CHECK(97, String_copy((&(((String*)((self->access_names)->values))[ACCESS_OWNER])), &(String){6, 5, "owner"}) )
  if ((ACCESS_VAR) < 0 || (ACCESS_VAR) >= (self->access_names)->length) RAISE(98)
  CHECK(98, String_copy((&(((String*)((self->access_names)->values))[ACCESS_VAR])), &(String){4, 3, "var"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_init_operator_map(Global* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_init_operator_map = "Global.init-operator-map";
#define LUMI_FUNC_NAME _func_name_Global_init_operator_map
Returncode Global_init_operator_map(Global* self) {
  self->operator_map = malloc(sizeof(NameMap));
  if (self->operator_map == NULL) RAISE(101)
  *self->operator_map = (NameMap){NULL, NULL};
  CHECK(102, Global_add_operator_copy(self, &(String){2, 1, "+"}, 0, 0) )
  CHECK(103, Global_add_operator_copy(self, &(String){2, 1, "-"}, 0, 0) )
  CHECK(104, Global_add_operator_copy(self, &(String){2, 1, "*"}, 0, 1) )
  CHECK(105, Global_add_operator(self, &(String){4, 3, "div"}, &(String){2, 1, "/"}, 0, 1) )
  CHECK(106, Global_add_operator(self, &(String){4, 3, "mod"}, &(String){2, 1, "%"}, 0, 1) )
  CHECK(107, Global_add_operator(self, &(String){2, 1, "="}, &(String){3, 2, "=="}, 1, 0) )
  CHECK(108, Global_add_operator_copy(self, &(String){3, 2, "!="}, 1, 0) )
  CHECK(109, Global_add_operator_copy(self, &(String){2, 1, ">"}, 1, 0) )
  CHECK(110, Global_add_operator_copy(self, &(String){2, 1, "<"}, 1, 0) )
  CHECK(111, Global_add_operator_copy(self, &(String){3, 2, ">="}, 1, 0) )
  CHECK(112, Global_add_operator_copy(self, &(String){3, 2, "<="}, 1, 0) )
  CHECK(113, Global_add_operator(self, &(String){3, 2, "is"}, &(String){3, 2, "=="}, 1, 0) )
  CHECK(114, Global_add_operator(self, &(String){7, 6, "is-not"}, &(String){3, 2, "!="}, 1, 0) )
  CHECK(115, Global_add_operator(self, &(String){4, 3, "not"}, &(String){2, 1, "!"}, 2, 0) )
  CHECK(116, Global_add_operator(self, &(String){3, 2, "or"}, &(String){3, 2, "||"}, 3, 0) )
  CHECK(117, Global_add_operator(self, &(String){4, 3, "and"}, &(String){3, 2, "&&"}, 3, 1) )
  CHECK(118, Global_add_operator(self, &(String){3, 2, ":="}, &(String){2, 1, "="}, 4, 0) )
  CHECK(119, Global_add_operator_copy(self, &(String){3, 2, "+="}, 4, 1) )
  CHECK(120, Global_add_operator_copy(self, &(String){3, 2, "-="}, 4, 2) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_add_operator(Global* self, String* name, String* c_name, Int order, Int group_index);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_add_operator = "Global.add-operator";
#define LUMI_FUNC_NAME _func_name_Global_add_operator
Returncode Global_add_operator(Global* self, String* name, String* c_name, Int order, Int group_index) {
  Operator* operator = malloc(sizeof(Operator));
  if (operator == NULL) RAISE(127)
  *operator = (Operator){NULL, NULL, 0, 0};
  CHECK(128, Operator_init(operator, name, c_name, order, group_index) )
  CHECK(129, NameMap_add(self->operator_map, operator->name, operator) )
  CHECK(130, List_add(self->operators, operator) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_add_operator_copy(Global* self, String* name, Int order, Int group_index);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_add_operator_copy = "Global.add-operator-copy";
#define LUMI_FUNC_NAME _func_name_Global_add_operator_copy
Returncode Global_add_operator_copy(Global* self, String* name, Int order, Int group_index) {
  CHECK(136, Global_add_operator(self, name, name, order, group_index) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_init_builtin_types(Global* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_init_builtin_types = "Global.init-builtin-types";
#define LUMI_FUNC_NAME _func_name_Global_init_builtin_types
Returncode Global_init_builtin_types(Global* self) {
  CHECK(139, Global_add_builtin_type(self, &(String){5, 4, "Char"}, true, &(self->type_char)) )
  CHECK(140, Global_add_builtin_type(self, &(String){5, 4, "Bool"}, true, &(self->type_bool)) )
  CHECK(141, Global_add_builtin_type(self, &(String){4, 3, "Int"}, true, &(self->type_int)) )
  CHECK(142, Global_add_builtin_type(self, &(String){13, 12, "Empty Symbol"}, false, &(self->type_empty)) )
  CHECK(144, Global_add_builtin_type(self, &(String){5, 4, "Func"}, true, &(self->type_func)) )
  CHECK(145, Global_add_builtin_type(self, &(String){4, 3, "Ref"}, true, &(self->type_ref)) )
  CHECK(146, Global_add_builtin_type(self, &(String){7, 6, "String"}, false, &(self->type_string)) )
  CHECK(147, Global_add_builtin_type(self, &(String){6, 5, "Array"}, false, &(self->type_array)) )
  CHECK(148, Global_add_builtin_type(self, &(String){5, 4, "Type"}, false, &(self->type_type)) )
  CHECK(149, Global_add_builtin_type(self, &(String){12, 11, "Base Symbol"}, false, &(self->type_base)) )
  CHECK(150, Global_add_builtin_type(self, &(String){13, 12, "Generic Type"}, false, &(self->type_generic)) )
  self->type_generic->is_dynamic = true;
  CHECK(153, Global_add_builtin_type(self, &(String){12, 11, "Module Name"}, false, &(self->type_module)) )
  CHECK(155, Global_add_builtin_type(self, &(String){5, 4, "File"}, false, &(self->type_file)) )
  CHECK(156, Global_add_builtin_type(self, &(String){4, 3, "Sys"}, false, &(self->type_sys)) )
  
  FunctionArguments* arguments = NULL;
  
  /* Int */
  CHECK(161, Global_add_builtin_method(self, glob->type_int, &(String){4, 3, "str"}, &(arguments)) )
  CHECK(162, Global_add_builtin_parameter(self, arguments, ACCESS_USER, glob->type_string, &(String){4, 3, "str"}) )
  
  /* Bool */
  CHECK(166, Global_add_builtin_global_variable(self, glob->type_bool, &(String){5, 4, "true"}) )
  CHECK(167, Global_add_builtin_global_variable(self, glob->type_bool, &(String){6, 5, "false"}) )
  
  /* String */
  CHECK(170, Global_add_builtin_field(self, glob->type_string, &(String){7, 6, "length"}, glob->type_int, NULL) )
  
  CHECK(173, Global_add_builtin_method(self, glob->type_string, &(String){4, 3, "new"}, &(arguments)) )
  CHECK(174, Global_add_builtin_parameter(self, arguments, ACCESS_USER, glob->type_string, &(String){6, 5, "other"}) )
  
  CHECK(177, Global_add_builtin_method(self, glob->type_string, &(String){6, 5, "clear"}, &(arguments)) )
  
  CHECK(180, Global_add_builtin_method(self, glob->type_string, &(String){6, 5, "equal"}, &(arguments)) )
  CHECK(182, Global_add_builtin_parameter(self, arguments, ACCESS_USER, glob->type_string, &(String){8, 7, "pattern"}) )
  CHECK(184, Global_add_builtin_output(self, arguments, ACCESS_VAR, glob->type_bool, &(String){6, 5, "equal"}) )
  
  CHECK(187, Global_add_builtin_method(self, glob->type_string, &(String){4, 3, "get"}, &(arguments)) )
  CHECK(188, Global_add_builtin_parameter(self, arguments, ACCESS_COPY, glob->type_int, &(String){6, 5, "index"}) )
  CHECK(190, Global_add_builtin_output(self, arguments, ACCESS_VAR, glob->type_char, &(String){3, 2, "ch"}) )
  
  CHECK(193, Global_add_builtin_method(self, glob->type_string, &(String){7, 6, "append"}, &(arguments)) )
  CHECK(195, Global_add_builtin_parameter(self, arguments, ACCESS_COPY, glob->type_char, &(String){3, 2, "ch"}) )
  
  CHECK(198, Global_add_builtin_method(self, glob->type_string, &(String){7, 6, "concat"}, &(arguments)) )
  CHECK(200, Global_add_builtin_parameter(self, arguments, ACCESS_USER, glob->type_string, &(String){6, 5, "other"}) )
  
  CHECK(203, Global_add_builtin_method(self, glob->type_string, &(String){11, 10, "concat-int"}, &(arguments)) )
  CHECK(205, Global_add_builtin_parameter(self, arguments, ACCESS_COPY, glob->type_int, &(String){7, 6, "number"}) )
  
  CHECK(208, Global_add_builtin_method(self, glob->type_string, &(String){5, 4, "find"}, &(arguments)) )
  CHECK(209, Global_add_builtin_parameter(self, arguments, ACCESS_USER, glob->type_string, &(String){8, 7, "pattern"}) )
  CHECK(211, Global_add_builtin_output(self, arguments, ACCESS_VAR, glob->type_int, &(String){6, 5, "index"}) )
  
  CHECK(214, Global_add_builtin_method(self, glob->type_string, &(String){4, 3, "has"}, &(arguments)) )
  CHECK(215, Global_add_builtin_parameter(self, arguments, ACCESS_COPY, glob->type_char, &(String){3, 2, "ch"}) )
  CHECK(217, Global_add_builtin_output(self, arguments, ACCESS_VAR, glob->type_bool, &(String){6, 5, "equal"}) )
  
  /* Array */
  CHECK(221, Global_add_builtin_field(self, glob->type_array, &(String){7, 6, "length"}, glob->type_int, NULL) )
  
  /* File */
  CHECK(225, Global_add_builtin_global_function(self, &(String){15, 14, "file-open-read"}, &(arguments)) )
  CHECK(226, Global_add_builtin_parameter(self, arguments, ACCESS_USER, glob->type_string, &(String){5, 4, "name"}) )
  CHECK(228, Global_add_builtin_output(self, arguments, ACCESS_OWNER, glob->type_file, &(String){5, 4, "file"}) )
  
  CHECK(231, Global_add_builtin_global_function(self, &(String){16, 15, "file-open-write"}, &(arguments)) )
  CHECK(232, Global_add_builtin_parameter(self, arguments, ACCESS_USER, glob->type_string, &(String){5, 4, "name"}) )
  CHECK(234, Global_add_builtin_output(self, arguments, ACCESS_OWNER, glob->type_file, &(String){5, 4, "file"}) )
  
  CHECK(237, Global_add_builtin_method(self, glob->type_file, &(String){6, 5, "close"}, &(arguments)) )
  
  CHECK(239, Global_add_builtin_method(self, glob->type_file, &(String){5, 4, "getc"}, &(arguments)) )
  CHECK(240, Global_add_builtin_output(self, arguments, ACCESS_VAR, glob->type_char, &(String){3, 2, "ch"}) )
  CHECK(242, Global_add_builtin_output(self, arguments, ACCESS_VAR, glob->type_bool, &(String){7, 6, "is-eof"}) )
  
  CHECK(245, Global_add_builtin_method(self, glob->type_file, &(String){5, 4, "putc"}, &(arguments)) )
  CHECK(246, Global_add_builtin_parameter(self, arguments, ACCESS_COPY, glob->type_char, &(String){3, 2, "ch"}) )
  
  CHECK(249, Global_add_builtin_method(self, glob->type_file, &(String){6, 5, "write"}, &(arguments)) )
  CHECK(250, Global_add_builtin_parameter(self, arguments, ACCESS_USER, glob->type_string, &(String){5, 4, "text"}) )
  
  CHECK(253, Global_add_builtin_global_variable(self, glob->type_file, &(String){7, 6, "stdout"}) )
  CHECK(254, Global_add_builtin_global_variable(self, glob->type_file, &(String){6, 5, "stdin"}) )
  CHECK(255, Global_add_builtin_global_variable(self, glob->type_file, &(String){7, 6, "stderr"}) )
  
  /* Sys */
  CHECK(258, Global_add_builtin_field(self, glob->type_sys, &(String){5, 4, "argv"}, glob->type_array, glob->type_string) )
  
  CHECK(264, Global_add_builtin_method(self, glob->type_sys, &(String){6, 5, "print"}, &(arguments)) )
  CHECK(265, Global_add_builtin_parameter(self, arguments, ACCESS_USER, glob->type_string, &(String){5, 4, "text"}) )
  
  CHECK(268, Global_add_builtin_method(self, glob->type_sys, &(String){8, 7, "println"}, &(arguments)) )
  CHECK(269, Global_add_builtin_parameter(self, arguments, ACCESS_USER, glob->type_string, &(String){5, 4, "text"}) )
  
  CHECK(272, Global_add_builtin_method(self, glob->type_sys, &(String){8, 7, "getchar"}, &(arguments)) )
  CHECK(273, Global_add_builtin_output(self, arguments, ACCESS_VAR, glob->type_char, &(String){3, 2, "ch"}) )
  CHECK(275, Global_add_builtin_output(self, arguments, ACCESS_VAR, glob->type_bool, &(String){7, 6, "is-eof"}) )
  
  CHECK(278, Global_add_builtin_method(self, glob->type_sys, &(String){8, 7, "getline"}, &(arguments)) )
  CHECK(279, Global_add_builtin_parameter(self, arguments, ACCESS_USER, glob->type_string, &(String){5, 4, "line"}) )
  
  CHECK(282, Global_add_builtin_method(self, glob->type_sys, &(String){5, 4, "exit"}, &(arguments)) )
  CHECK(283, Global_add_builtin_parameter(self, arguments, ACCESS_COPY, glob->type_int, &(String){7, 6, "status"}) )
  
  CHECK(286, Global_add_builtin_method(self, glob->type_sys, &(String){7, 6, "system"}, &(arguments)) )
  CHECK(287, Global_add_builtin_parameter(self, arguments, ACCESS_USER, glob->type_string, &(String){8, 7, "command"}) )
  CHECK(289, Global_add_builtin_output(self, arguments, ACCESS_VAR, glob->type_int, &(String){7, 6, "status"}) )
  
  CHECK(292, Global_add_builtin_method(self, glob->type_sys, &(String){7, 6, "getenv"}, &(arguments)) )
  CHECK(293, Global_add_builtin_parameter(self, arguments, ACCESS_USER, glob->type_string, &(String){5, 4, "name"}) )
  CHECK(295, Global_add_builtin_parameter(self, arguments, ACCESS_USER, glob->type_string, &(String){6, 5, "value"}) )
  CHECK(297, Global_add_builtin_output(self, arguments, ACCESS_VAR, glob->type_bool, &(String){7, 6, "exists"}) )
  
  CHECK(300, Global_add_builtin_global_variable(self, glob->type_sys, &(String){4, 3, "sys"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_add_builtin_type(Global* self, String* name, Bool is_primitive, TypeData** type_data);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_add_builtin_type = "Global.add-builtin-type";
#define LUMI_FUNC_NAME _func_name_Global_add_builtin_type
Returncode Global_add_builtin_type(Global* self, String* name, Bool is_primitive, TypeData** type_data) {
  (*type_data) = malloc(sizeof(TypeData));
  if ((*type_data) == NULL) RAISE(304)
  *(*type_data) = (TypeData){TypeData__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, false, false, false, false, false};
  (*type_data)->_base._base._base._dtl = TypeData__dtl;
  CHECK(305, string_new_copy(name, &((*type_data)->name)) )
  (*type_data)->is_primitive = is_primitive;
  CHECK(307, SyntaxTreeNamespace_init(&((*type_data)->_base)) )
  CHECK(308, NameMap_add(self->global_module->type_map, (*type_data)->name, (*type_data)) )
  CHECK(309, List_add(self->builtins->types, (*type_data)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_add_builtin_global_variable(Global* self, TypeData* variable_type, String* name);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_add_builtin_global_variable = "Global.add-builtin-global-variable";
#define LUMI_FUNC_NAME _func_name_Global_add_builtin_global_variable
Returncode Global_add_builtin_global_variable(Global* self, TypeData* variable_type, String* name) {
  CHECK(313, Global_add_builtin_variable(self, name, variable_type, NULL, NULL, &(self->builtins->_base._base)) )
  SyntaxTreeVariable* variable = self->builtins->_base._base.variables->last->item;
  CHECK(316, NameMap_add(self->global_module->variable_map, variable->name, variable) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_add_builtin_field(Global* self, TypeData* builtin_type, String* name, TypeData* field_type, TypeData* field_subtype);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_add_builtin_field = "Global.add-builtin-field";
#define LUMI_FUNC_NAME _func_name_Global_add_builtin_field
Returncode Global_add_builtin_field(Global* self, TypeData* builtin_type, String* name, TypeData* field_type, TypeData* field_subtype) {
  CHECK(323, Global_add_builtin_variable(self, name, field_type, field_subtype, builtin_type, &(builtin_type->_base._base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_add_builtin_variable(Global* self, String* name, TypeData* variable_type, TypeData* variable_subtype, TypeData* parent_type, SyntaxTreeBranch* branch);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_add_builtin_variable = "Global.add-builtin-variable";
#define LUMI_FUNC_NAME _func_name_Global_add_builtin_variable
Returncode Global_add_builtin_variable(Global* self, String* name, TypeData* variable_type, TypeData* variable_subtype, TypeData* parent_type, SyntaxTreeBranch* branch) {
  SyntaxTreeVariable* variable = malloc(sizeof(SyntaxTreeVariable));
  if (variable == NULL) RAISE(336)
  *variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, NULL, 0, NULL, NULL, false, false, false, false};
  variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  CHECK(337, string_new_copy(name, &(variable->name)) )
  if (variable_type->is_primitive) {
    variable->access = ACCESS_VAR;
  }
  else {
    variable->access = ACCESS_USER;
  }
  CHECK(342, TypeData_m_new_type_instance(variable_type, &(variable->type_instance)) )
  if (NULL != variable_subtype) {
    CHECK(344, TypeInstance_add_subtype_copy(variable->type_instance, variable_subtype) )
  }
  variable->parent_type = parent_type;
  CHECK(346, List_add(branch->variables, variable) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_add_builtin_global_function(Global* self, String* name, FunctionArguments** arguments);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_add_builtin_global_function = "Global.add-builtin-global-function";
#define LUMI_FUNC_NAME _func_name_Global_add_builtin_global_function
Returncode Global_add_builtin_global_function(Global* self, String* name, FunctionArguments** arguments) {
  CHECK(350, Global_add_builtin_function(self, name, NULL, &(glob->builtins->_base), &((*arguments))) )
  SyntaxTreeFunction* function = self->builtins->_base.functions->last->item;
  CHECK(353, NameMap_add(self->global_module->function_map, function->name, function) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_add_builtin_method(Global* self, TypeData* builtin_type, String* name, FunctionArguments** arguments);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_add_builtin_method = "Global.add-builtin-method";
#define LUMI_FUNC_NAME _func_name_Global_add_builtin_method
Returncode Global_add_builtin_method(Global* self, TypeData* builtin_type, String* name, FunctionArguments** arguments) {
  CHECK(357, Global_add_builtin_function(self, name, builtin_type, &(builtin_type->_base), &((*arguments))) )
  CHECK(359, Global_add_builtin_parameter(self, (*arguments), ACCESS_USER, builtin_type, &(String){5, 4, "self"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_add_builtin_function(Global* self, String* name, TypeData* parent_type, SyntaxTreeNamespace* namespace, FunctionArguments** arguments);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_add_builtin_function = "Global.add-builtin-function";
#define LUMI_FUNC_NAME _func_name_Global_add_builtin_function
Returncode Global_add_builtin_function(Global* self, String* name, TypeData* parent_type, SyntaxTreeNamespace* namespace, FunctionArguments** arguments) {
  SyntaxTreeFunction* function = malloc(sizeof(SyntaxTreeFunction));
  if (function == NULL) RAISE(367)
  *function = (SyntaxTreeFunction){SyntaxTreeFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  function->_base._base._base._dtl = SyntaxTreeFunction__dtl;
  CHECK(368, SyntaxTreeFunction_init(function) )
  CHECK(369, string_new_copy(name, &(function->name)) )
  function->parent_type = parent_type;
  function->arguments = malloc(sizeof(FunctionArguments));
  if (function->arguments == NULL) RAISE(371)
  *function->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  function->arguments->_base._dtl = FunctionArguments__dtl;
  CHECK(372, FunctionArguments_init(function->arguments) )
  (*arguments) = function->arguments;
  CHECK(374, List_add(namespace->functions, function) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_add_builtin_parameter(Global* self, FunctionArguments* arguments, Int access, TypeData* parameter_type, String* name);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_add_builtin_parameter = "Global.add-builtin-parameter";
#define LUMI_FUNC_NAME _func_name_Global_add_builtin_parameter
Returncode Global_add_builtin_parameter(Global* self, FunctionArguments* arguments, Int access, TypeData* parameter_type, String* name) {
  CHECK(381, Global_add_builtin_argument(self, arguments->parameters, false, access, parameter_type, name) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_add_builtin_output(Global* self, FunctionArguments* arguments, Int access, TypeData* output_type, String* name);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_add_builtin_output = "Global.add-builtin-output";
#define LUMI_FUNC_NAME _func_name_Global_add_builtin_output
Returncode Global_add_builtin_output(Global* self, FunctionArguments* arguments, Int access, TypeData* output_type, String* name) {
  CHECK(393, Global_add_builtin_argument(self, arguments->outputs, true, access, output_type, name) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_add_builtin_argument(Global* self, List* argument_list, Bool is_output, Int access, TypeData* argument_type, String* name);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_add_builtin_argument = "Global.add-builtin-argument";
#define LUMI_FUNC_NAME _func_name_Global_add_builtin_argument
Returncode Global_add_builtin_argument(Global* self, List* argument_list, Bool is_output, Int access, TypeData* argument_type, String* name) {
  DeclarationArgument* argument = malloc(sizeof(DeclarationArgument));
  if (argument == NULL) RAISE(406)
  *argument = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, false, NULL};
  argument->_base._base._dtl = DeclarationArgument__dtl;
  argument->_base.access = access;
  argument->_base.is_output = is_output;
  argument->variable = malloc(sizeof(SyntaxTreeVariable));
  if (argument->variable == NULL) RAISE(409)
  *argument->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, NULL, 0, NULL, NULL, false, false, false, false};
  argument->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  CHECK(410, string_new_copy(name, &(argument->variable->name)) )
  argument->variable->access = access;
  CHECK(412, TypeData_m_new_type_instance(argument_type, &(argument->variable->type_instance)) )
  CHECK(414, List_add(argument_list, &(argument->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_find_type(Global* self, String* name, TypeData** type_data);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_find_type = "Global.find-type";
#define LUMI_FUNC_NAME _func_name_Global_find_type
Returncode Global_find_type(Global* self, String* name, TypeData** type_data) {
  if (NULL != self->current_module) {
    CHECK(418, NameMap_find(self->current_module->type_map, name, (void**)&((*type_data))) )
    if (NULL != (*type_data)) {
      return OK;
    }
  }
  CHECK(420, NameMap_find(self->global_module->type_map, name, (void**)&((*type_data))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_find_variable(Global* self, String* name, SyntaxTreeVariable** variable);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_find_variable = "Global.find-variable";
#define LUMI_FUNC_NAME _func_name_Global_find_variable
Returncode Global_find_variable(Global* self, String* name, SyntaxTreeVariable** variable) {
  CHECK(423, NameMap_find(self->current_module->variable_map, name, (void**)&((*variable))) )
  if (NULL != (*variable)) {
    return OK;
  }
  CHECK(425, NameMap_find(self->global_module->variable_map, name, (void**)&((*variable))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode Global_find_function(Global* self, String* name, SyntaxTreeFunction** function);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_Global_find_function = "Global.find-function";
#define LUMI_FUNC_NAME _func_name_Global_find_function
Returncode Global_find_function(Global* self, String* name, SyntaxTreeFunction** function) {
  CHECK(428, NameMap_find(self->current_module->function_map, name, (void**)&((*function))) )
  if (NULL != (*function)) {
    return OK;
  }
  CHECK(430, NameMap_find(self->global_module->function_map, name, (void**)&((*function))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
extern Global* glob;
#elif LUMI_STAGE == LUMI_FUNCTIONS
Global* glob = &(Global){NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, NULL, false, false, NULL, '\0', 0, false, false, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
#endif

#undef LUMI_FILE_NAME

#ifndef LUMI_INCLUDES
#define LUMI_INCLUDES
#include "tl4-compiler.c"
#include "global/argument.c"
#include "global/common.c"
#include "global/file-io.c"
#include "global/list.c"
#include "global/map.c"
#include "global/type-instance.c"
#include "expression/base-type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/initialize.c"
#include "expression/slice.c"
#include "expression/symbol.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "statement/enum.c"
#include "statement/error.c"
#include "statement/for.c"
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
#include "statement/type.c"
#include "statement/variable.c"
#if LUMI_STAGE == LUMI_TYPES(1)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(2)
#elif LUMI_STAGE == LUMI_TYPES(2)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(3)
#elif LUMI_STAGE == LUMI_TYPES(3)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(4)
#elif LUMI_STAGE == LUMI_TYPES(4)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(5)
#endif
#undef LUMI_INCLUDES
#endif

#endif
