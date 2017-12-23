#ifndef MR_MAINFILE
#define MR_MAINFILE "global/common.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file2_name = "global/common.3.mr";
#endif
#define MR_FILE_NAME _mr_file2_name

/* MR4 compiler - Common stuff */

/* Create a new copy of given string */
#if MR_STAGE == MR_DECLARATIONS
Returncode string_new_copy(String* text, String** new_text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_string_new_copy = "string-new-copy";
#define MR_FUNC_NAME _func_name_string_new_copy
Returncode string_new_copy(String* text, String** new_text) {
  if (!(NULL != text)) {
    (*new_text) = NULL;
    return OK;
  }
  (*new_text) = _new_string(text->length + 1);
  if ((*new_text) == NULL) RAISE(8)
  CHECK(9, String_copy((*new_text), text) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Create a new string that is a concatenation of the 2 given strings */
#if MR_STAGE == MR_DECLARATIONS
Returncode string_new_concat(String* first, String* second, String** new_text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_string_new_concat = "string-new-concat";
#define MR_FUNC_NAME _func_name_string_new_concat
Returncode string_new_concat(String* first, String* second, String** new_text) {
  String* text = NULL;
  (*new_text) = _new_string(first->length + second->length + 1);
  if ((*new_text) == NULL) RAISE(16)
  CHECK(17, String_copy((*new_text), first) )
  CHECK(18, String_concat((*new_text), second) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Proxy function to be mocked in tests */
#if MR_STAGE == MR_DECLARATIONS
Returncode print(String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_print = "print";
#define MR_FUNC_NAME _func_name_print
Returncode print(String* text) {
  CHECK(23, Sys_print_raw(sys, text) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode print_msg_with_item(String* text, String* item);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_print_msg_with_item = "print-msg-with-item";
#define MR_FUNC_NAME _func_name_print_msg_with_item
Returncode print_msg_with_item(String* text, String* item) {
  CHECK(27, print(text) )
  CHECK(28, print(&(String){3, 2, " \""}) )
  CHECK(29, print(item) )
  CHECK(30, print(&(String){2, 1, "\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode f_is_legal_name(String* name, Bool is_type, Bool* is_legal);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_f_is_legal_name = "f-is-legal-name";
#define MR_FUNC_NAME _func_name_f_is_legal_name
Returncode f_is_legal_name(String* name, Bool is_type, Bool* is_legal) {
  if (name->length <= 0 || (is_type && name->length <= 1)) {
    (*is_legal) = false;
    return OK;
  }
  if ((0) < 0 || (0) >= (name)->length) RAISE(37)
  Char ch = ((name)->values[0]);
  Int first = 1;
  if (is_type) {
    if (ch < 'A' || ch > 'Z') {
      (*is_legal) = false;
      return OK;
    }
    if ((1) < 0 || (1) >= (name)->length) RAISE(43)
    ch = ((name)->values[1]);
    first = 2;
  }
  if (ch < 'a' || ch > 'z') {
    (*is_legal) = false;
    return OK;
  }
  {int n; for (n = (first); n < (name->length); ++n) {
    if ((n) < 0 || (n) >= (name)->length) RAISE(49)
    ch = ((name)->values[n]);
    if (!((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || (!is_type && ch == '-') || (is_type && (ch >= 'A' && ch <= 'Z')))) {
      (*is_legal) = false;
      return OK;
    }
  }}
  (*is_legal) = true;
  return OK;
}
#undef MR_FUNC_NAME
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/argument.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
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
#include "syntax-tree/function.c"
#include "syntax-tree/native.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "syntax-tree/test.c"
#include "syntax-tree/type.c"
#include "syntax-tree/type-instance.c"
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
