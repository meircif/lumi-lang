#ifndef MR_MAINFILE
#define MR_MAINFILE "global/type.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file5_name = "global/type.3.mr";
#endif
#define MR_FILE_NAME _mr_file5_name

/* MR4 compiler - Meta types */

/* Meta type for a type in the language */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeData TypeData;
#elif MR_STAGE == MR_TYPES(0)
struct TypeData {
  String* name;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_init(TypeData* self, String* name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_init = "TypeData.init";
#define MR_FUNC_NAME _func_name_TypeData_init
Returncode TypeData_init(TypeData* self, String* name) {
  self->name = name;
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Specific usage of a type including the assigned subtype */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeInstance TypeInstance;
#elif MR_STAGE == MR_TYPES(0)
struct TypeInstance {
  TypeData* type_data;
  TypeInstance* sub_type;
/* Return a new deep-copy of self */};
#endif/* Return a new deep-copy of self */
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_m_copy_new(TypeInstance* self, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_m_copy_new = "TypeInstance.m-copy-new";
#define MR_FUNC_NAME _func_name_TypeInstance_m_copy_new
Returncode TypeInstance_m_copy_new(TypeInstance* self, TypeInstance** type_instance) {
  (*type_instance) = malloc(sizeof(TypeInstance));
  if ((*type_instance) == NULL) RAISE(18)
  *(*type_instance) = (TypeInstance){NULL, NULL};
  (*type_instance)->type_data = self->type_data;
  if (NULL != self->sub_type) {
    CHECK(21, TypeInstance_m_copy_new(self->sub_type, &((*type_instance)->sub_type)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Meta type of an operator */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Operator Operator;
#elif MR_STAGE == MR_TYPES(0)
struct Operator {
  String* name;
  String* c_name;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Operator_init(Operator* self, String* name, String* c_name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Operator_init = "Operator.init";
#define MR_FUNC_NAME _func_name_Operator_init
Returncode Operator_init(Operator* self, String* name, String* c_name) {
  CHECK(30, string_new_copy(name, &(self->name)) )
  CHECK(31, string_new_copy(c_name, &(self->c_name)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Meta type for a variable in the language */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Variable Variable;
#elif MR_STAGE == MR_TYPES(0)
struct Variable {
  String* name;
};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/map.c"
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
