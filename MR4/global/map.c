#ifndef MR_MAINFILE
#define MR_MAINFILE "global/map.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file6_name = "global/map.3.mr";
#endif
#define MR_FILE_NAME _mr_file6_name

/* MR4 compiler - Generic mappings */

/* Maps from a string name to a generic object */
#if MR_STAGE == MR_TYPEDEFS
typedef struct NameMap NameMap;
#elif MR_STAGE == MR_TYPES(0)
struct NameMap {
  NameMapNode* first;
  NameMapNode* last;
/* Add `name` -> `value` mapping *//* Find a value mapped from `name`, return empty if not exists */};
#endif/* Add `name` -> `value` mapping */
#if MR_STAGE == MR_DECLARATIONS
Returncode NameMap_add(NameMap* self, String* name, void* value);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NameMap_add = "NameMap.add";
#define MR_FUNC_NAME _func_name_NameMap_add
Returncode NameMap_add(NameMap* self, String* name, void* value) {
  NameMapNode* node = malloc(sizeof(NameMapNode));
  if (node == NULL) RAISE(10)
  *node = (NameMapNode){NULL, NULL, NULL};
  CHECK(11, NameMapNode_init(node, name, value) )
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
Returncode NameMap_find(NameMap* self, String* name, void** value);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NameMap_find = "NameMap.find";
#define MR_FUNC_NAME _func_name_NameMap_find
Returncode NameMap_find(NameMap* self, String* name, void** value) {
  NameMapNode* node = self->first;
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
#if MR_STAGE == MR_DECLARATIONS
Returncode NameMap_m_update_or_add(NameMap* self, String* name, void* value);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NameMap_m_update_or_add = "NameMap.m-update-or-add";
#define MR_FUNC_NAME _func_name_NameMap_m_update_or_add
Returncode NameMap_m_update_or_add(NameMap* self, String* name, void* value) {
  NameMapNode* node = self->first;
  while (true) {
    if (!(NULL != node)) break;
    Bool _Bool11;
    CHECK(33, String_equal(node->name, name, &(_Bool11)) )
    if (_Bool11) {
      node->value = value;
      return OK;
    }
    node = node->next;
  }
  CHECK(37, NameMap_add(self, name, value) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct NameMapNode NameMapNode;
#elif MR_STAGE == MR_TYPES(0)
struct NameMapNode {
  NameMapNode* next;
  String* name;
  void* value;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode NameMapNode_init(NameMapNode* self, String* name, void* value);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_NameMapNode_init = "NameMapNode.init";
#define MR_FUNC_NAME _func_name_NameMapNode_init
Returncode NameMapNode_init(NameMapNode* self, String* name, void* value) {
  self->name = name;
  self->value = value;
  return OK;
}
#undef MR_FUNC_NAME
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/argument.c"
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/symbol.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/function.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "syntax-tree/test.c"
#include "syntax-tree/type.c"
#include "syntax-tree/variable.c"
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
