#ifndef MR_MAINFILE
#define MR_MAINFILE "global/common.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file1_name = "global/common.3.mr";
#endif
#define MR_FILE_NAME _mr_file1_name

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


/* Raise a syntax error with message: */
/* `Code error in {file-name}[{line-number}] {text} "{item}"` */
#if MR_STAGE == MR_DECLARATIONS
Returncode f_syntax_error(String* text, String* item);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_f_syntax_error = "f-syntax-error";
#define MR_FUNC_NAME _func_name_f_syntax_error
Returncode f_syntax_error(String* text, String* item) {
  CHECK(29, print_syntax_error_header() )
  CHECK(30, print_msg_with_item(text, item) )
  CHECK(31, print(&(String){2, 1, "\n"}) )
  RAISE(32)
}
#undef MR_FUNC_NAME
#endif


/* Same as `f-syntax-error` but but with another `{text} "{item}" pair */
#if MR_STAGE == MR_DECLARATIONS
Returncode f_syntax_error2(String* text1, String* item1, String* text2, String* item2);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_f_syntax_error2 = "f-syntax-error2";
#define MR_FUNC_NAME _func_name_f_syntax_error2
Returncode f_syntax_error2(String* text1, String* item1, String* text2, String* item2) {
  CHECK(38, print_syntax_error_header() )
  CHECK(39, print_msg_with_item(text1, item1) )
  CHECK(40, print(&(String){2, 1, " "}) )
  CHECK(41, print_msg_with_item(text2, item2) )
  CHECK(42, print(&(String){2, 1, "\n"}) )
  RAISE(43)
}
#undef MR_FUNC_NAME
#endif


/* Same as `f-syntax-error` but with a character item */
#if MR_STAGE == MR_DECLARATIONS
Returncode f_syntax_error_c(String* text, Char item);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_f_syntax_error_c = "f-syntax-error-c";
#define MR_FUNC_NAME _func_name_f_syntax_error_c
Returncode f_syntax_error_c(String* text, Char item) {
  String* char_str = &(String){16, 0, (char[16]){0}};
  if (item == EOF) {
    CHECK(50, String_copy(char_str, &(String){4, 3, "EOF"}) )
  }
  else {
    if (item == '\n') {
      CHECK(52, String_copy(char_str, &(String){9, 8, "new-line"}) )
    }
    else {
      CHECK(54, String_append(char_str, item) )
    }
  }
  CHECK(55, f_syntax_error(text, char_str) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode f_syntax_error_msg(String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_f_syntax_error_msg = "f-syntax-error-msg";
#define MR_FUNC_NAME _func_name_f_syntax_error_msg
Returncode f_syntax_error_msg(String* text) {
  CHECK(59, print_syntax_error_header() )
  CHECK(60, print(text) )
  CHECK(61, print(&(String){2, 1, "\n"}) )
  RAISE(62)
}
#undef MR_FUNC_NAME
#endif


#if MR_STAGE == MR_DECLARATIONS
Returncode print_syntax_error_header();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_print_syntax_error_header = "print-syntax-error-header";
#define MR_FUNC_NAME _func_name_print_syntax_error_header
Returncode print_syntax_error_header() {
  CHECK(66, print(&(String){15, 14, "Code error in "}) )
  CHECK(67, print(glob->input_file_name) )
  CHECK(68, print(&(String){2, 1, "["}) )
  String* line_num_str = &(String){32, 0, (char[32]){0}};
  CHECK(70, Int_str(glob->line_number, line_num_str) )
  CHECK(71, print(line_num_str) )
  CHECK(72, print(&(String){3, 2, "] "}) )
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
  CHECK(76, print(text) )
  CHECK(77, print(&(String){3, 2, " \""}) )
  CHECK(78, print(item) )
  CHECK(79, print(&(String){2, 1, "\""}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/symbol.c"
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
