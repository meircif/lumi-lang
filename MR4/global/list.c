#ifndef MR_MAINFILE
#define MR_MAINFILE "global/list.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file4_name = "global/list.3.mr";
#endif
#define MR_FILE_NAME _mr_file4_name

/* MR4 compiler - Generic mappings */

/* A generic single link list */
#if MR_STAGE == MR_TYPEDEFS
typedef struct List List;
#elif MR_STAGE == MR_TYPES(0)
struct List {
  ListNode* first;
  ListNode* last;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode List_m_is_empty(List* self, Bool* is_empty);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_List_m_is_empty = "List.m-is-empty";
#define MR_FUNC_NAME _func_name_List_m_is_empty
Returncode List_m_is_empty(List* self, Bool* is_empty) {
  (*is_empty) =  ! (NULL != self->first);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode List_add(List* self, void* item);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_List_add = "List.add";
#define MR_FUNC_NAME _func_name_List_add
Returncode List_add(List* self, void* item) {
  ListNode* node = malloc(sizeof(ListNode));
  if (node == NULL) RAISE(12)
  *node = (ListNode){NULL, NULL};
  node->item = item;
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
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct ListNode ListNode;
#elif MR_STAGE == MR_TYPES(0)
struct ListNode {
  ListNode* next;
  void* item;
};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/map.c"
#include "global/type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/variable.c"
#include "syntax-tree/code.c"
#include "syntax-tree/function.c"
#include "syntax-tree/loop.c"
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
#endif
#undef MR_INCLUDES
#endif

#endif
