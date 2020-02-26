#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "global/map.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file7_name = "global/map.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file7_name

/* TL4 compiler - Generic mappings */

/* Maps from a string name to a generic object */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct NameMap NameMap;
#elif LUMI_STAGE == LUMI_TYPES(0)
struct NameMap {
  NameMapNode* first;
  NameMapNode* last;
/* Add `name` -> `value` mapping *//* Find a value mapped from `name`, return empty if not exists */};
#endif/* Add `name` -> `value` mapping */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode NameMap_add(NameMap* self, String* name, void* value);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_NameMap_add = "NameMap.add";
#define LUMI_FUNC_NAME _func_name_NameMap_add
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
#undef LUMI_FUNC_NAME
#endif/* Find a value mapped from `name`, return empty if not exists */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode NameMap_find(NameMap* self, String* name, void** value);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_NameMap_find = "NameMap.find";
#define LUMI_FUNC_NAME _func_name_NameMap_find
Returncode NameMap_find(NameMap* self, String* name, void** value) {
  NameMapNode* node = self->first;
  while (true) {
    if (!(NULL != node)) break;
    Bool _Bool13;
    CHECK(23, String_equal(node->name, name, &(_Bool13)) )
    if (_Bool13) {
      (*value) = ((void*)(node->value));
      return OK;
    }
    node = node->next;
  }
  (*value) = NULL;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode NameMap_update_or_add(NameMap* self, String* name, void* value);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_NameMap_update_or_add = "NameMap.update-or-add";
#define LUMI_FUNC_NAME _func_name_NameMap_update_or_add
Returncode NameMap_update_or_add(NameMap* self, String* name, void* value) {
  NameMapNode* node = self->first;
  while (true) {
    if (!(NULL != node)) break;
    Bool _Bool14;
    CHECK(33, String_equal(node->name, name, &(_Bool14)) )
    if (_Bool14) {
      node->value = value;
      return OK;
    }
    node = node->next;
  }
  CHECK(37, NameMap_add(self, name, value) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct NameMapNode NameMapNode;
#elif LUMI_STAGE == LUMI_TYPES(0)
struct NameMapNode {
  NameMapNode* next;
  String* name;
  void* value;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode NameMapNode_init(NameMapNode* self, String* name, void* value);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_NameMapNode_init = "NameMapNode.init";
#define LUMI_FUNC_NAME _func_name_NameMapNode_init
Returncode NameMapNode_init(NameMapNode* self, String* name, void* value) {
  self->name = name;
  self->value = value;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#undef LUMI_FILE_NAME

#ifndef LUMI_INCLUDES
#define LUMI_INCLUDES
#include "tl4-compiler.c"
#include "global/argument.c"
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
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
#include "syntax-tree/code-flow.c"
#include "syntax-tree/code.c"
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
