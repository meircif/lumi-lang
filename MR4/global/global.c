#ifndef MR_MAINFILE
#define MR_MAINFILE "global/global.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file4_name = "global/global.3.mr";
#endif
#define MR_FILE_NAME _mr_file4_name

/* MR4 compiler - Global compiler data */

/* Access values */
#if MR_STAGE == MR_DECLARATIONS
extern Int ACCESS_UNDEFINED;
#elif MR_STAGE == MR_FUNCTIONS
Int ACCESS_UNDEFINED = 0;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Int ACCESS_COPY;
#elif MR_STAGE == MR_FUNCTIONS
Int ACCESS_COPY = 1;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Int ACCESS_USER;
#elif MR_STAGE == MR_FUNCTIONS
Int ACCESS_USER = 2;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Int ACCESS_OWNER;
#elif MR_STAGE == MR_FUNCTIONS
Int ACCESS_OWNER = 3;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Int ACCESS_VAR;
#elif MR_STAGE == MR_FUNCTIONS
Int ACCESS_VAR = 4;
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct Global Global;
#elif MR_STAGE == MR_TYPES(0)
struct Global {
/* stores all language operators */  SyntaxTreeRoot* root;
/* stores all language operators */  NameMap* operator_map;
/* stores all types - language built-ins and user defined */  NameMap* type_map;
/* map access number to its name */  Array* access_names;
/* the currently parsed input file object */  File* input_file;
/* the currently written output file object */  File* output_file;
/* holds the name of the input-file and the line number of the code currently *//* been worked with */  String* input_file_name;
  Int line_number;
/* test functions list */  NameMap* test_functions;
/* input reading state */  String* input_buffer;
  Char input_end;
  Int input_spaces;
  Bool got_new_line;
  Bool save_input;
/* built-in types */  BuiltinType* type_char;
  BuiltinType* type_bool;
  BuiltinType* type_int;
  BuiltinType* type_empty;
  BuiltinType* type_func;
  BuiltinType* type_string;
  BuiltinType* type_array;
  BuiltinType* type_type;
  BuiltinType* type_base;
  BuiltinType* type_generic;
  BuiltinType* type_file;
  BuiltinType* type_sys;
};
#endif/* stores all language operators *//* stores all language operators *//* stores all types - language built-ins and user defined *//* map access number to its name *//* the currently parsed input file object *//* the currently written output file object *//* holds the name of the input-file and the line number of the code currently *//* been worked with *//* test functions list *//* input reading state *//* built-in types */
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_init(Global* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_init = "Global.init";
#define MR_FUNC_NAME _func_name_Global_init
Returncode Global_init(Global* self) {
  self->root = malloc(sizeof(SyntaxTreeRoot));
  if (self->root == NULL) RAISE(60)
  *self->root = (SyntaxTreeRoot){SyntaxTreeRoot__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL};
  self->root->_base._base._base._dtl = SyntaxTreeRoot__dtl;
  CHECK(61, SyntaxTreeRoot_init(self->root) )
  self->input_buffer = _new_string(1024);
  if (self->input_buffer == NULL) RAISE(62)
  self->test_functions = malloc(sizeof(NameMap));
  if (self->test_functions == NULL) RAISE(63)
  *self->test_functions = (NameMap){NULL, NULL};
  CHECK(64, Global_init_operator_map(self) )
  CHECK(65, Global_init_builtin_types(self) )
  self->access_names = _new_array(5, sizeof(String) + (16));
  if (self->access_names == NULL) RAISE(66)
  _set_new_string_array(5, 16, self->access_names);
  if ((ACCESS_UNDEFINED) < 0 || (ACCESS_UNDEFINED) >= (self->access_names)->length) RAISE(67)
  CHECK(67, String_copy((&(((String*)((self->access_names)->values))[ACCESS_UNDEFINED])), &(String){10, 9, "undefined"}) )
  if ((ACCESS_COPY) < 0 || (ACCESS_COPY) >= (self->access_names)->length) RAISE(68)
  CHECK(68, String_copy((&(((String*)((self->access_names)->values))[ACCESS_COPY])), &(String){5, 4, "copy"}) )
  if ((ACCESS_USER) < 0 || (ACCESS_USER) >= (self->access_names)->length) RAISE(69)
  CHECK(69, String_copy((&(((String*)((self->access_names)->values))[ACCESS_USER])), &(String){5, 4, "user"}) )
  if ((ACCESS_OWNER) < 0 || (ACCESS_OWNER) >= (self->access_names)->length) RAISE(70)
  CHECK(70, String_copy((&(((String*)((self->access_names)->values))[ACCESS_OWNER])), &(String){6, 5, "owner"}) )
  if ((ACCESS_VAR) < 0 || (ACCESS_VAR) >= (self->access_names)->length) RAISE(71)
  CHECK(71, String_copy((&(((String*)((self->access_names)->values))[ACCESS_VAR])), &(String){4, 3, "var"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_init_operator_map(Global* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_init_operator_map = "Global.init-operator-map";
#define MR_FUNC_NAME _func_name_Global_init_operator_map
Returncode Global_init_operator_map(Global* self) {
  self->operator_map = malloc(sizeof(NameMap));
  if (self->operator_map == NULL) RAISE(74)
  *self->operator_map = (NameMap){NULL, NULL};
  CHECK(75, Global_add_operator_copy(self, &(String){2, 1, "+"}, 0, 0) )
  CHECK(76, Global_add_operator_copy(self, &(String){2, 1, "-"}, 0, 0) )
  CHECK(77, Global_add_operator_copy(self, &(String){2, 1, "*"}, 0, 1) )
  CHECK(78, Global_add_operator(self, &(String){4, 3, "div"}, &(String){2, 1, "/"}, 0, 1) )
  CHECK(79, Global_add_operator(self, &(String){4, 3, "mod"}, &(String){2, 1, "%"}, 0, 1) )
  CHECK(80, Global_add_operator(self, &(String){2, 1, "="}, &(String){3, 2, "=="}, 1, 0) )
  CHECK(81, Global_add_operator_copy(self, &(String){3, 2, "!="}, 1, 0) )
  CHECK(82, Global_add_operator_copy(self, &(String){2, 1, ">"}, 1, 0) )
  CHECK(83, Global_add_operator_copy(self, &(String){2, 1, "<"}, 1, 0) )
  CHECK(84, Global_add_operator_copy(self, &(String){3, 2, ">="}, 1, 0) )
  CHECK(85, Global_add_operator_copy(self, &(String){3, 2, "<="}, 1, 0) )
  CHECK(86, Global_add_operator(self, &(String){3, 2, "is"}, &(String){3, 2, "=="}, 1, 0) )
  CHECK(87, Global_add_operator(self, &(String){7, 6, "is-not"}, &(String){3, 2, "!="}, 1, 0) )
  CHECK(88, Global_add_operator(self, &(String){4, 3, "not"}, &(String){2, 1, "!"}, 2, 0) )
  CHECK(89, Global_add_operator(self, &(String){3, 2, "or"}, &(String){3, 2, "||"}, 3, 0) )
  CHECK(90, Global_add_operator(self, &(String){4, 3, "and"}, &(String){3, 2, "&&"}, 3, 1) )
  CHECK(91, Global_add_operator(self, &(String){3, 2, ":="}, &(String){2, 1, "="}, 4, 0) )
  CHECK(92, Global_add_operator_copy(self, &(String){3, 2, "+="}, 4, 1) )
  CHECK(93, Global_add_operator_copy(self, &(String){3, 2, "-="}, 4, 2) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_operator(Global* self, String* name, String* c_name, Int order, Int group_index);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_operator = "Global.add-operator";
#define MR_FUNC_NAME _func_name_Global_add_operator
Returncode Global_add_operator(Global* self, String* name, String* c_name, Int order, Int group_index) {
  Operator* operator = malloc(sizeof(Operator));
  if (operator == NULL) RAISE(100)
  *operator = (Operator){NULL, NULL, 0, 0};
  CHECK(101, Operator_init(operator, name, c_name, order, group_index) )
  CHECK(102, NameMap_add(self->operator_map, operator->name, operator) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_operator_copy(Global* self, String* name, Int order, Int group_index);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_operator_copy = "Global.add-operator-copy";
#define MR_FUNC_NAME _func_name_Global_add_operator_copy
Returncode Global_add_operator_copy(Global* self, String* name, Int order, Int group_index) {
  CHECK(108, Global_add_operator(self, name, name, order, group_index) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_init_builtin_types(Global* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_init_builtin_types = "Global.init-builtin-types";
#define MR_FUNC_NAME _func_name_Global_init_builtin_types
Returncode Global_init_builtin_types(Global* self) {
  self->type_map = malloc(sizeof(NameMap));
  if (self->type_map == NULL) RAISE(111)
  *self->type_map = (NameMap){NULL, NULL};
  CHECK(112, Global_add_builtin_type(self, &(String){5, 4, "Char"}, true, &(self->type_char)) )
  CHECK(113, Global_add_builtin_type(self, &(String){5, 4, "Bool"}, true, &(self->type_bool)) )
  CHECK(114, Global_add_builtin_type(self, &(String){4, 3, "Int"}, true, &(self->type_int)) )
  CHECK(115, Global_add_builtin_type(self, &(String){13, 12, "Empty Symbol"}, false, &(self->type_empty)) )
  CHECK(117, Global_add_builtin_type(self, &(String){5, 4, "Func"}, true, &(self->type_func)) )
  CHECK(118, Global_add_builtin_type(self, &(String){7, 6, "String"}, false, &(self->type_string)) )
  CHECK(119, Global_add_builtin_type(self, &(String){6, 5, "Array"}, false, &(self->type_array)) )
  CHECK(120, Global_add_builtin_type(self, &(String){5, 4, "Type"}, false, &(self->type_type)) )
  CHECK(121, Global_add_builtin_type(self, &(String){12, 11, "Base Symbol"}, false, &(self->type_base)) )
  CHECK(122, Global_add_builtin_type(self, &(String){13, 12, "Generic Type"}, false, &(self->type_generic)) )
  self->type_generic->_base.is_dynamic = true;
  CHECK(125, Global_add_builtin_type(self, &(String){5, 4, "File"}, false, &(self->type_file)) )
  CHECK(126, Global_add_builtin_type(self, &(String){4, 3, "Sys"}, false, &(self->type_sys)) )
  
  FunctionArguments* arguments = NULL;
  
  /* Int */
  CHECK(131, Global_add_builtin_method(self, &(glob->type_int->_base), &(String){4, 3, "str"}, &(arguments)) )
  CHECK(132, Global_add_builtin_parameter(self, arguments, ACCESS_USER, &(glob->type_string->_base), &(String){4, 3, "str"}) )
  
  /* Bool */
  CHECK(136, Global_add_builtin_global_variable(self, &(glob->type_bool->_base), &(String){5, 4, "true"}) )
  CHECK(137, Global_add_builtin_global_variable(self, &(glob->type_bool->_base), &(String){6, 5, "false"}) )
  
  /* String */
  CHECK(140, Global_add_builtin_field(self, &(glob->type_string->_base), &(String){7, 6, "length"}, &(glob->type_int->_base), NULL) )
  
  CHECK(143, Global_add_builtin_method(self, &(glob->type_string->_base), &(String){4, 3, "new"}, &(arguments)) )
  CHECK(144, Global_add_builtin_parameter(self, arguments, ACCESS_USER, &(glob->type_string->_base), &(String){6, 5, "other"}) )
  
  CHECK(147, Global_add_builtin_method(self, &(glob->type_string->_base), &(String){6, 5, "clear"}, &(arguments)) )
  
  CHECK(150, Global_add_builtin_method(self, &(glob->type_string->_base), &(String){6, 5, "equal"}, &(arguments)) )
  CHECK(152, Global_add_builtin_parameter(self, arguments, ACCESS_USER, &(glob->type_string->_base), &(String){8, 7, "pattern"}) )
  CHECK(154, Global_add_builtin_output(self, arguments, ACCESS_VAR, &(glob->type_bool->_base), &(String){6, 5, "equal"}) )
  
  CHECK(157, Global_add_builtin_method(self, &(glob->type_string->_base), &(String){4, 3, "get"}, &(arguments)) )
  CHECK(158, Global_add_builtin_parameter(self, arguments, ACCESS_COPY, &(glob->type_int->_base), &(String){6, 5, "index"}) )
  CHECK(160, Global_add_builtin_output(self, arguments, ACCESS_VAR, &(glob->type_char->_base), &(String){3, 2, "ch"}) )
  
  CHECK(163, Global_add_builtin_method(self, &(glob->type_string->_base), &(String){7, 6, "append"}, &(arguments)) )
  CHECK(165, Global_add_builtin_parameter(self, arguments, ACCESS_COPY, &(glob->type_char->_base), &(String){3, 2, "ch"}) )
  
  CHECK(168, Global_add_builtin_method(self, &(glob->type_string->_base), &(String){7, 6, "concat"}, &(arguments)) )
  CHECK(170, Global_add_builtin_parameter(self, arguments, ACCESS_USER, &(glob->type_string->_base), &(String){6, 5, "other"}) )
  
  CHECK(173, Global_add_builtin_method(self, &(glob->type_string->_base), &(String){11, 10, "concat-int"}, &(arguments)) )
  CHECK(175, Global_add_builtin_parameter(self, arguments, ACCESS_COPY, &(glob->type_int->_base), &(String){7, 6, "number"}) )
  
  CHECK(178, Global_add_builtin_method(self, &(glob->type_string->_base), &(String){5, 4, "find"}, &(arguments)) )
  CHECK(179, Global_add_builtin_parameter(self, arguments, ACCESS_USER, &(glob->type_string->_base), &(String){8, 7, "pattern"}) )
  CHECK(181, Global_add_builtin_output(self, arguments, ACCESS_VAR, &(glob->type_int->_base), &(String){6, 5, "index"}) )
  
  CHECK(184, Global_add_builtin_method(self, &(glob->type_string->_base), &(String){4, 3, "has"}, &(arguments)) )
  CHECK(185, Global_add_builtin_parameter(self, arguments, ACCESS_COPY, &(glob->type_char->_base), &(String){3, 2, "ch"}) )
  CHECK(187, Global_add_builtin_output(self, arguments, ACCESS_VAR, &(glob->type_bool->_base), &(String){6, 5, "equal"}) )
  
  /* Array */
  CHECK(191, Global_add_builtin_field(self, &(glob->type_array->_base), &(String){7, 6, "length"}, &(glob->type_int->_base), NULL) )
  
  /* File */
  CHECK(195, Global_add_builtin_global_function(self, &(String){15, 14, "file-open-read"}, &(arguments)) )
  CHECK(196, Global_add_builtin_parameter(self, arguments, ACCESS_USER, &(glob->type_string->_base), &(String){5, 4, "name"}) )
  CHECK(198, Global_add_builtin_output(self, arguments, ACCESS_OWNER, &(glob->type_file->_base), &(String){5, 4, "file"}) )
  
  CHECK(201, Global_add_builtin_global_function(self, &(String){16, 15, "file-open-write"}, &(arguments)) )
  CHECK(202, Global_add_builtin_parameter(self, arguments, ACCESS_USER, &(glob->type_string->_base), &(String){5, 4, "name"}) )
  CHECK(204, Global_add_builtin_output(self, arguments, ACCESS_OWNER, &(glob->type_file->_base), &(String){5, 4, "file"}) )
  
  CHECK(207, Global_add_builtin_method(self, &(glob->type_file->_base), &(String){6, 5, "close"}, &(arguments)) )
  
  CHECK(209, Global_add_builtin_method(self, &(glob->type_file->_base), &(String){5, 4, "getc"}, &(arguments)) )
  CHECK(210, Global_add_builtin_output(self, arguments, ACCESS_VAR, &(glob->type_char->_base), &(String){3, 2, "ch"}) )
  CHECK(212, Global_add_builtin_output(self, arguments, ACCESS_VAR, &(glob->type_bool->_base), &(String){7, 6, "is-eof"}) )
  
  CHECK(215, Global_add_builtin_method(self, &(glob->type_file->_base), &(String){5, 4, "putc"}, &(arguments)) )
  CHECK(216, Global_add_builtin_parameter(self, arguments, ACCESS_COPY, &(glob->type_char->_base), &(String){3, 2, "ch"}) )
  
  CHECK(219, Global_add_builtin_method(self, &(glob->type_file->_base), &(String){6, 5, "write"}, &(arguments)) )
  CHECK(220, Global_add_builtin_parameter(self, arguments, ACCESS_USER, &(glob->type_string->_base), &(String){5, 4, "text"}) )
  
  CHECK(223, Global_add_builtin_global_variable(self, &(glob->type_file->_base), &(String){7, 6, "stdout"}) )
  CHECK(224, Global_add_builtin_global_variable(self, &(glob->type_file->_base), &(String){6, 5, "stdin"}) )
  CHECK(225, Global_add_builtin_global_variable(self, &(glob->type_file->_base), &(String){7, 6, "stderr"}) )
  
  /* Sys */
  CHECK(228, Global_add_builtin_field(self, &(glob->type_sys->_base), &(String){5, 4, "argv"}, &(glob->type_array->_base), &(glob->type_string->_base)) )
  
  CHECK(234, Global_add_builtin_method(self, &(glob->type_sys->_base), &(String){6, 5, "print"}, &(arguments)) )
  CHECK(235, Global_add_builtin_parameter(self, arguments, ACCESS_USER, &(glob->type_string->_base), &(String){5, 4, "text"}) )
  
  CHECK(238, Global_add_builtin_method(self, &(glob->type_sys->_base), &(String){8, 7, "println"}, &(arguments)) )
  CHECK(239, Global_add_builtin_parameter(self, arguments, ACCESS_USER, &(glob->type_string->_base), &(String){5, 4, "text"}) )
  
  CHECK(242, Global_add_builtin_method(self, &(glob->type_sys->_base), &(String){8, 7, "getchar"}, &(arguments)) )
  CHECK(243, Global_add_builtin_output(self, arguments, ACCESS_VAR, &(glob->type_char->_base), &(String){3, 2, "ch"}) )
  CHECK(245, Global_add_builtin_output(self, arguments, ACCESS_VAR, &(glob->type_bool->_base), &(String){7, 6, "is-eof"}) )
  
  CHECK(248, Global_add_builtin_method(self, &(glob->type_sys->_base), &(String){8, 7, "getline"}, &(arguments)) )
  CHECK(249, Global_add_builtin_parameter(self, arguments, ACCESS_USER, &(glob->type_string->_base), &(String){5, 4, "line"}) )
  
  CHECK(252, Global_add_builtin_method(self, &(glob->type_sys->_base), &(String){5, 4, "exit"}, &(arguments)) )
  CHECK(253, Global_add_builtin_parameter(self, arguments, ACCESS_COPY, &(glob->type_int->_base), &(String){7, 6, "status"}) )
  
  CHECK(256, Global_add_builtin_method(self, &(glob->type_sys->_base), &(String){7, 6, "system"}, &(arguments)) )
  CHECK(257, Global_add_builtin_parameter(self, arguments, ACCESS_USER, &(glob->type_string->_base), &(String){8, 7, "command"}) )
  CHECK(259, Global_add_builtin_output(self, arguments, ACCESS_VAR, &(glob->type_int->_base), &(String){7, 6, "status"}) )
  
  CHECK(262, Global_add_builtin_method(self, &(glob->type_sys->_base), &(String){7, 6, "getenv"}, &(arguments)) )
  CHECK(263, Global_add_builtin_parameter(self, arguments, ACCESS_USER, &(glob->type_string->_base), &(String){5, 4, "name"}) )
  CHECK(265, Global_add_builtin_parameter(self, arguments, ACCESS_USER, &(glob->type_string->_base), &(String){6, 5, "value"}) )
  CHECK(267, Global_add_builtin_output(self, arguments, ACCESS_VAR, &(glob->type_bool->_base), &(String){7, 6, "exists"}) )
  
  CHECK(270, Global_add_builtin_global_variable(self, &(glob->type_sys->_base), &(String){4, 3, "sys"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_builtin_type(Global* self, String* name, Bool is_primitive, BuiltinType** type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_builtin_type = "Global.add-builtin-type";
#define MR_FUNC_NAME _func_name_Global_add_builtin_type
Returncode Global_add_builtin_type(Global* self, String* name, Bool is_primitive, BuiltinType** type_data) {
  (*type_data) = malloc(sizeof(BuiltinType));
  if ((*type_data) == NULL) RAISE(274)
  *(*type_data) = (BuiltinType){BuiltinType__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, false, false, false};
  (*type_data)->_base._base._base._base._dtl = BuiltinType__dtl;
  CHECK(275, string_new_copy(name, &((*type_data)->_base.name)) )
  (*type_data)->_base.is_primitive = is_primitive;
  CHECK(277, Global_add_type(self, &((*type_data)->_base)) )
  CHECK(278, List_add(self->root->types, &((*type_data)->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_type(Global* self, TypeData* type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_type = "Global.add-type";
#define MR_FUNC_NAME _func_name_Global_add_type
Returncode Global_add_type(Global* self, TypeData* type_data) {
  CHECK(281, SyntaxTreeNamespace_init(&(type_data->_base)) )
  CHECK(282, NameMap_add(self->type_map, type_data->name, type_data) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_builtin_global_variable(Global* self, TypeData* variable_type, String* name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_builtin_global_variable = "Global.add-builtin-global-variable";
#define MR_FUNC_NAME _func_name_Global_add_builtin_global_variable
Returncode Global_add_builtin_global_variable(Global* self, TypeData* variable_type, String* name) {
  CHECK(286, Global_add_builtin_variable(self, name, variable_type, NULL, NULL, &(self->root->_base._base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_builtin_field(Global* self, TypeData* builtin_type, String* name, TypeData* field_type, TypeData* field_subtype);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_builtin_field = "Global.add-builtin-field";
#define MR_FUNC_NAME _func_name_Global_add_builtin_field
Returncode Global_add_builtin_field(Global* self, TypeData* builtin_type, String* name, TypeData* field_type, TypeData* field_subtype) {
  CHECK(294, Global_add_builtin_variable(self, name, field_type, field_subtype, builtin_type, &(builtin_type->_base._base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_builtin_variable(Global* self, String* name, TypeData* variable_type, TypeData* variable_subtype, TypeData* parent_type, SyntaxTreeBranch* branch);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_builtin_variable = "Global.add-builtin-variable";
#define MR_FUNC_NAME _func_name_Global_add_builtin_variable
Returncode Global_add_builtin_variable(Global* self, String* name, TypeData* variable_type, TypeData* variable_subtype, TypeData* parent_type, SyntaxTreeBranch* branch) {
  BuiltinVariable* variable = malloc(sizeof(BuiltinVariable));
  if (variable == NULL) RAISE(307)
  *variable = (BuiltinVariable){BuiltinVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false, false, false};
  variable->_base._base._base._dtl = BuiltinVariable__dtl;
  CHECK(308, string_new_copy(name, &(variable->_base.name)) )
  if (variable_type->is_primitive) {
    variable->_base.access = ACCESS_VAR;
  }
  else {
    variable->_base.access = ACCESS_OWNER;
  }
  CHECK(313, TypeData_m_new_type_instance(variable_type, &(variable->_base.type_instance)) )
  if (NULL != variable_subtype) {
    CHECK(315, TypeInstance_add_subtype_copy(variable->_base.type_instance, variable_subtype) )
  }
  variable->_base.parent_type = parent_type;
  CHECK(317, List_add(branch->variables, &(variable->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_builtin_global_function(Global* self, String* name, FunctionArguments** arguments);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_builtin_global_function = "Global.add-builtin-global-function";
#define MR_FUNC_NAME _func_name_Global_add_builtin_global_function
Returncode Global_add_builtin_global_function(Global* self, String* name, FunctionArguments** arguments) {
  CHECK(321, Global_add_builtin_function(self, name, NULL, &(glob->root->_base), &((*arguments))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_builtin_method(Global* self, TypeData* builtin_type, String* name, FunctionArguments** arguments);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_builtin_method = "Global.add-builtin-method";
#define MR_FUNC_NAME _func_name_Global_add_builtin_method
Returncode Global_add_builtin_method(Global* self, TypeData* builtin_type, String* name, FunctionArguments** arguments) {
  CHECK(326, Global_add_builtin_function(self, name, builtin_type, &(builtin_type->_base), &((*arguments))) )
  CHECK(328, Global_add_builtin_parameter(self, (*arguments), ACCESS_VAR, builtin_type, &(String){5, 4, "self"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_builtin_function(Global* self, String* name, TypeData* parent_type, SyntaxTreeNamespace* namespace, FunctionArguments** arguments);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_builtin_function = "Global.add-builtin-function";
#define MR_FUNC_NAME _func_name_Global_add_builtin_function
Returncode Global_add_builtin_function(Global* self, String* name, TypeData* parent_type, SyntaxTreeNamespace* namespace, FunctionArguments** arguments) {
  BuiltinFunction* function = malloc(sizeof(BuiltinFunction));
  if (function == NULL) RAISE(336)
  *function = (BuiltinFunction){BuiltinFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  function->_base._base._base._base._dtl = BuiltinFunction__dtl;
  CHECK(337, SyntaxTreeFunction_init(&(function->_base)) )
  CHECK(338, string_new_copy(name, &(function->_base.name)) )
  function->_base.parent_type = parent_type;
  function->_base.arguments = malloc(sizeof(FunctionArguments));
  if (function->_base.arguments == NULL) RAISE(340)
  *function->_base.arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  function->_base.arguments->_base._dtl = FunctionArguments__dtl;
  CHECK(341, FunctionArguments_init(function->_base.arguments) )
  (*arguments) = function->_base.arguments;
  CHECK(343, List_add(namespace->functions, &(function->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_builtin_parameter(Global* self, FunctionArguments* arguments, Int access, TypeData* parameter_type, String* name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_builtin_parameter = "Global.add-builtin-parameter";
#define MR_FUNC_NAME _func_name_Global_add_builtin_parameter
Returncode Global_add_builtin_parameter(Global* self, FunctionArguments* arguments, Int access, TypeData* parameter_type, String* name) {
  CHECK(350, Global_add_builtin_argument(self, arguments->parameters, false, access, parameter_type, name) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_builtin_output(Global* self, FunctionArguments* arguments, Int access, TypeData* output_type, String* name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_builtin_output = "Global.add-builtin-output";
#define MR_FUNC_NAME _func_name_Global_add_builtin_output
Returncode Global_add_builtin_output(Global* self, FunctionArguments* arguments, Int access, TypeData* output_type, String* name) {
  CHECK(362, Global_add_builtin_argument(self, arguments->outputs, true, access, output_type, name) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_builtin_argument(Global* self, List* argument_list, Bool is_output, Int access, TypeData* argument_type, String* name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_builtin_argument = "Global.add-builtin-argument";
#define MR_FUNC_NAME _func_name_Global_add_builtin_argument
Returncode Global_add_builtin_argument(Global* self, List* argument_list, Bool is_output, Int access, TypeData* argument_type, String* name) {
  DeclarationArgument* argument = malloc(sizeof(DeclarationArgument));
  if (argument == NULL) RAISE(375)
  *argument = (DeclarationArgument){DeclarationArgument__dtl, NULL, 0, 0, false, false, NULL};
  argument->_base._base._dtl = DeclarationArgument__dtl;
  argument->_base.access = access;
  argument->_base.is_output = is_output;
  argument->variable = malloc(sizeof(SyntaxTreeVariable));
  if (argument->variable == NULL) RAISE(378)
  *argument->variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false, false, false};
  argument->variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  CHECK(379, string_new_copy(name, &(argument->variable->name)) )
  argument->variable->access = access;
  CHECK(381, TypeData_m_new_type_instance(argument_type, &(argument->variable->type_instance)) )
  CHECK(383, List_add(argument_list, &(argument->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
extern Global* glob;
#elif MR_STAGE == MR_FUNCTIONS
Global* glob = &(Global){NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL, NULL, '\0', 0, false, false, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct BuiltinType BuiltinType;
#elif MR_STAGE == MR_TYPES(4)
struct BuiltinType {
  TypeData _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BuiltinType_link_types(BuiltinType* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BuiltinType_link_types = "BuiltinType.link-types";
#define MR_FUNC_NAME _func_name_BuiltinType_link_types
Returncode BuiltinType_link_types(BuiltinType* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BuiltinType_analyze(BuiltinType* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BuiltinType_analyze = "BuiltinType.analyze";
#define MR_FUNC_NAME _func_name_BuiltinType_analyze
Returncode BuiltinType_analyze(BuiltinType* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BuiltinType_write(BuiltinType* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BuiltinType_write = "BuiltinType.write";
#define MR_FUNC_NAME _func_name_BuiltinType_write
Returncode BuiltinType_write(BuiltinType* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BuiltinType_write_me(BuiltinType* self, TypeWriter* type_writer);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BuiltinType_write_me = "BuiltinType.write-me";
#define MR_FUNC_NAME _func_name_BuiltinType_write_me
Returncode BuiltinType_write_me(BuiltinType* self, TypeWriter* type_writer) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BuiltinType__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BuiltinType__dtl[] = {(void*)TypeData_get_parent_type, (void*)BuiltinType_link_types, (void*)BuiltinType_analyze, (void*)BuiltinType_write, (void*)TypeData_parse_child, (void*)SyntaxTreeBranch_find_variable, (void*)TypeData_write_declaration, (void*)BuiltinType_write_me};
#endif

#if MR_STAGE == MR_TYPEDEFS
typedef struct BuiltinVariable BuiltinVariable;
#elif MR_STAGE == MR_TYPES(3)
struct BuiltinVariable {
  SyntaxTreeVariable _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BuiltinVariable_link_types(BuiltinVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BuiltinVariable_link_types = "BuiltinVariable.link-types";
#define MR_FUNC_NAME _func_name_BuiltinVariable_link_types
Returncode BuiltinVariable_link_types(BuiltinVariable* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BuiltinVariable_analyze(BuiltinVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BuiltinVariable_analyze = "BuiltinVariable.analyze";
#define MR_FUNC_NAME _func_name_BuiltinVariable_analyze
Returncode BuiltinVariable_analyze(BuiltinVariable* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BuiltinVariable_write(BuiltinVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BuiltinVariable_write = "BuiltinVariable.write";
#define MR_FUNC_NAME _func_name_BuiltinVariable_write
Returncode BuiltinVariable_write(BuiltinVariable* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BuiltinVariable__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BuiltinVariable__dtl[] = {(void*)SyntaxTreeVariable_get_parent_type, (void*)BuiltinVariable_link_types, (void*)BuiltinVariable_analyze, (void*)BuiltinVariable_write, (void*)SyntaxTreeCode_m_is_end_point, (void*)SyntaxTreeVariable_write_sequence};
#endif

#if MR_STAGE == MR_TYPEDEFS
typedef struct BuiltinFunction BuiltinFunction;
#elif MR_STAGE == MR_TYPES(4)
struct BuiltinFunction {
  SyntaxTreeFunction _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BuiltinFunction_link_types(BuiltinFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BuiltinFunction_link_types = "BuiltinFunction.link-types";
#define MR_FUNC_NAME _func_name_BuiltinFunction_link_types
Returncode BuiltinFunction_link_types(BuiltinFunction* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BuiltinFunction_analyze(BuiltinFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BuiltinFunction_analyze = "BuiltinFunction.analyze";
#define MR_FUNC_NAME _func_name_BuiltinFunction_analyze
Returncode BuiltinFunction_analyze(BuiltinFunction* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BuiltinFunction_write(BuiltinFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BuiltinFunction_write = "BuiltinFunction.write";
#define MR_FUNC_NAME _func_name_BuiltinFunction_write
Returncode BuiltinFunction_write(BuiltinFunction* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BuiltinFunction_write_declaration(BuiltinFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BuiltinFunction_write_declaration = "BuiltinFunction.write-declaration";
#define MR_FUNC_NAME _func_name_BuiltinFunction_write_declaration
Returncode BuiltinFunction_write_declaration(BuiltinFunction* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BuiltinFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BuiltinFunction__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)BuiltinFunction_link_types, (void*)BuiltinFunction_analyze, (void*)BuiltinFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeFunction_check_name, (void*)BuiltinFunction_write_declaration};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
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
#include "statement/error.c"
#include "statement/for.c"
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
#include "statement/type.c"
#include "statement/variable.c"
#include "mr4-compiler.c"
#if MR_STAGE == MR_TYPES(1)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(2)
#elif MR_STAGE == MR_TYPES(2)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(3)
#elif MR_STAGE == MR_TYPES(3)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(4)
#elif MR_STAGE == MR_TYPES(4)
#undef MR_STAGE
#define MR_STAGE MR_TYPES(5)
#endif
#undef MR_INCLUDES
#endif

#endif
