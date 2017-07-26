#ifndef MR_MAINFILE
#define MR_MAINFILE "global/map.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file4_name = "global/map.3.mr";
#endif
#define MR_FILE_NAME _mr_file4_name

/* MR4 compiler - Generic mappings */

/* Maps from a string name to a generic object */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Name_map Name_map;
#elif MR_STAGE == MR_TYPES(0)
struct Name_map {
  Name_map_node* first;
  Name_map_node* last;
/* Add `name` -> `value` mapping *//* Find a value mapped from `name`, return empty if not exists */};
#endif/* Add `name` -> `value` mapping */
#if MR_STAGE == MR_DECLARATIONS
Returncode Name_map_add(Name_map* self, String* name, void* value);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Name_map_add = "Name-map.add";
#define MR_FUNC_NAME _func_name_Name_map_add
Returncode Name_map_add(Name_map* self, String* name, void* value) {
  Name_map_node* node = malloc(sizeof(Name_map_node));
  if (node == NULL) RAISE(10)
  *node = (Name_map_node){NULL, NULL, NULL};
  CHECK(11, Name_map_node_init(node, name, value) )
  if (NULL != self->last) {
    self->last->next = node;
  }
  else {
    self->first = node;
  }
  self->last = node;
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Find a value mapped from `name`, return empty if not exists */
#if MR_STAGE == MR_DECLARATIONS
Returncode Name_map_find(Name_map* self, String* name, void** value);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Name_map_find = "Name-map.find";
#define MR_FUNC_NAME _func_name_Name_map_find
Returncode Name_map_find(Name_map* self, String* name, void** value) {
  Name_map_node* node = self->first;
  while (true) {
    if (!(NULL != node)) break;
    Bool _Bool10;
    CHECK(23, String_equal(node->name, name, &(_Bool10)) )
    if (_Bool10) {
      (*value) = ((void*)(node->value));
      return OK;
    }
    node = node->next;
  }
  (*value) = NULL;
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct Name_map_node Name_map_node;
#elif MR_STAGE == MR_TYPES(0)
struct Name_map_node {
  Name_map_node* next;
  String* name;
  void* value;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Name_map_node_init(Name_map_node* self, String* name, void* value);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Name_map_node_init = "Name-map-node.init";
#define MR_FUNC_NAME _func_name_Name_map_node_init
Returncode Name_map_node_init(Name_map_node* self, String* name, void* value) {
  self->name = name;
  self->value = value;
  return OK;
}
#undef MR_FUNC_NAME
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
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
