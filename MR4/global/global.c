#ifndef MR_MAINFILE
#define MR_MAINFILE "global/global.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file3_name = "global/global.3.mr";
#endif
#define MR_FILE_NAME _mr_file3_name

/* MR4 compiler - Global compiler data */

#if MR_STAGE == MR_TYPEDEFS
typedef struct Global Global;
#elif MR_STAGE == MR_TYPES(0)
struct Global {
/* stores all language operators */  Name_map* operator_map;
/* stores all types - language built-ins and user defined */  Name_map* type_map;
/* the currently parsed input file object */  File* input_file;
/* the currently written output file object */  File* output_file;
/* holds the name of the input-file and the line number of the code currently *//* been worked with */  String* input_file_name;
  Int line_number;
/* current indentation */  Int spaces;
/* built-in types */  Type_data* type_char;
  Type_data* type_bool;
  Type_data* type_int;
  Type_data* type_func;
  Type_data* type_string;
  Type_data* type_array;
  Type_data* type_file;
  Type_data* type_sys;
};
#endif/* stores all language operators *//* stores all types - language built-ins and user defined *//* the currently parsed input file object *//* the currently written output file object *//* holds the name of the input-file and the line number of the code currently *//* been worked with *//* current indentation *//* built-in types */
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_init(Global* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_init = "Global.init";
#define MR_FUNC_NAME _func_name_Global_init
Returncode Global_init(Global* self) {
  CHECK(35, Global_init_operator_map(self) )
  CHECK(36, Global_init_builtin_types(self) )
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
  self->operator_map = malloc(sizeof(Name_map));
  if (self->operator_map == NULL) RAISE(39)
  *self->operator_map = (Name_map){NULL, NULL};
  CHECK(40, Global_add_operator(self, &(String){3, 2, ":="}, &(String){2, 1, "="}) )
  CHECK(41, Global_add_operator_copy(self, &(String){2, 1, "+"}) )
  CHECK(42, Global_add_operator_copy(self, &(String){2, 1, "-"}) )
  CHECK(43, Global_add_operator_copy(self, &(String){2, 1, "*"}) )
  CHECK(44, Global_add_operator_copy(self, &(String){2, 1, "/"}) )
  CHECK(45, Global_add_operator_copy(self, &(String){3, 2, "+="}) )
  CHECK(46, Global_add_operator_copy(self, &(String){3, 2, "-="}) )
  CHECK(47, Global_add_operator(self, &(String){2, 1, "="}, &(String){3, 2, "=="}) )
  CHECK(48, Global_add_operator_copy(self, &(String){3, 2, "!="}) )
  CHECK(49, Global_add_operator_copy(self, &(String){2, 1, ">"}) )
  CHECK(50, Global_add_operator_copy(self, &(String){2, 1, "<"}) )
  CHECK(51, Global_add_operator_copy(self, &(String){3, 2, ">="}) )
  CHECK(52, Global_add_operator_copy(self, &(String){3, 2, "<="}) )
  CHECK(53, Global_add_operator(self, &(String){4, 3, "not"}, &(String){2, 1, "!"}) )
  CHECK(54, Global_add_operator(self, &(String){3, 2, "or"}, &(String){3, 2, "||"}) )
  CHECK(55, Global_add_operator(self, &(String){4, 3, "and"}, &(String){3, 2, "&&"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_operator(Global* self, String* name, String* c_name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_operator = "Global.add-operator";
#define MR_FUNC_NAME _func_name_Global_add_operator
Returncode Global_add_operator(Global* self, String* name, String* c_name) {
  Operator* operator = malloc(sizeof(Operator));
  if (operator == NULL) RAISE(58)
  *operator = (Operator){NULL, NULL};
  CHECK(59, Operator_init(operator, name, c_name) )
  CHECK(60, Name_map_add(self->operator_map, operator->name, operator) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_operator_copy(Global* self, String* name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_operator_copy = "Global.add-operator-copy";
#define MR_FUNC_NAME _func_name_Global_add_operator_copy
Returncode Global_add_operator_copy(Global* self, String* name) {
  CHECK(63, Global_add_operator(self, name, name) )
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
  self->type_map = malloc(sizeof(Name_map));
  if (self->type_map == NULL) RAISE(66)
  *self->type_map = (Name_map){NULL, NULL};
  CHECK(67, Global_add_type(self, &(String){5, 4, "Char"}, &(self->type_char)) )
  CHECK(68, Global_add_type(self, &(String){5, 4, "Bool"}, &(self->type_bool)) )
  CHECK(69, Global_add_type(self, &(String){4, 3, "Int"}, &(self->type_int)) )
  CHECK(70, Global_add_type(self, &(String){5, 4, "Func"}, &(self->type_func)) )
  CHECK(71, Global_add_type(self, &(String){7, 6, "String"}, &(self->type_string)) )
  CHECK(72, Global_add_type(self, &(String){6, 5, "Array"}, &(self->type_array)) )
  CHECK(73, Global_add_type(self, &(String){5, 4, "File"}, &(self->type_file)) )
  CHECK(74, Global_add_type(self, &(String){4, 3, "Sys"}, &(self->type_sys)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Global_add_type(Global* self, String* name, Type_data** type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Global_add_type = "Global.add-type";
#define MR_FUNC_NAME _func_name_Global_add_type
Returncode Global_add_type(Global* self, String* name, Type_data** type_data) {
  (*type_data) = malloc(sizeof(Type_data));
  if ((*type_data) == NULL) RAISE(77)
  *(*type_data) = (Type_data){NULL};
  String* _String5;
  CHECK(78, f_new_copy(name, &(_String5)) )
  CHECK(78, Type_data_init((*type_data), _String5) )
  CHECK(79, Name_map_add(self->type_map, (*type_data)->name, (*type_data)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
extern Global* glob;
#elif MR_STAGE == MR_FUNCTIONS
Global* glob = &(Global){NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/map.c"
#include "global/type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/variable.c"
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
#endif
#undef MR_INCLUDES
#endif

#endif
