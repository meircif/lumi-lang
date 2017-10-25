#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/node.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file18_name = "syntax-tree/node.3.mr";
#endif
#define MR_FILE_NAME _mr_file18_name

/*  MR4 compiler - Syntax tree basic node types


 */

/* Access values */
#if MR_STAGE == MR_DECLARATIONS
extern Int ACCESS_COPY;
#elif MR_STAGE == MR_FUNCTIONS
Int ACCESS_COPY = 0;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Int ACCESS_USER;
#elif MR_STAGE == MR_FUNCTIONS
Int ACCESS_USER = 1;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Int ACCESS_OWNER;
#elif MR_STAGE == MR_FUNCTIONS
Int ACCESS_OWNER = 2;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Int ACCESS_VAR;
#elif MR_STAGE == MR_FUNCTIONS
Int ACCESS_VAR = 3;
#endif


/* Basic node type for all syntax tree nodes */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeNode SyntaxTreeNode;
#elif MR_STAGE == MR_TYPES(0)
struct SyntaxTreeNode {
  Func* _dtl;
  String* input_file_name;
  Int line_number;
/* Expect `expected-text` to be read exaclty from the input file *//* Read and check indentation spaces for a line break from the input file *//* Raise a syntax error with message: *//* `Code error in {file-name}[{line-number}] {text} "{item}"` *//* Same as `m-syntax-error` but but with another `{text} "{item}" pair *//* Same as `m-syntax-error` but but with another 2 `{text} "{item}" pair *//* Same as `m-syntax-error` but with a character item */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_set_location(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_set_location = "SyntaxTreeNode.set-location";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_set_location
Returncode SyntaxTreeNode_set_location(SyntaxTreeNode* self) {
  self->input_file_name = glob->input_file_name;
  self->line_number = glob->line_number;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_get_access(SyntaxTreeNode* self, String* access_str, Int* access);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_get_access = "SyntaxTreeNode.get-access";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_get_access
Returncode SyntaxTreeNode_get_access(SyntaxTreeNode* self, String* access_str, Int* access) {
  Bool _Bool78;
  CHECK(23, String_equal(access_str, &(String){5, 4, "copy"}, &(_Bool78)) )
  if (_Bool78) {
    (*access) = ACCESS_COPY;
  }
  else {
    Bool _Bool79;
    CHECK(25, String_equal(access_str, &(String){5, 4, "user"}, &(_Bool79)) )
    if (_Bool79) {
      (*access) = ACCESS_USER;
    }
    else {
      Bool _Bool80;
      CHECK(27, String_equal(access_str, &(String){6, 5, "owner"}, &(_Bool80)) )
      if (_Bool80) {
        (*access) = ACCESS_OWNER;
      }
      else {
        Bool _Bool81;
        CHECK(29, String_equal(access_str, &(String){4, 3, "var"}, &(_Bool81)) )
        if (_Bool81) {
          (*access) = ACCESS_VAR;
        }
        else {
          CHECK(32, SyntaxTreeNode_m_syntax_error(self, &(String){15, 14, "illegal access"}, access_str) )
        }
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_find_type(SyntaxTreeNode* self, String* name, TypeData** type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_find_type = "SyntaxTreeNode.m-find-type";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_find_type
Returncode SyntaxTreeNode_m_find_type(SyntaxTreeNode* self, String* name, TypeData** type_data) {
  CHECK(35, NameMap_find(glob->type_map, name, (void**)&((*type_data))) )
  if (!(NULL != (*type_data))) {
    CHECK(36, SyntaxTreeNode_m_syntax_error(self, &(String){13, 12, "unknown type"}, name) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Expect `expected-text` to be read exaclty from the input file */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_read_expect(SyntaxTreeNode* self, String* expected_text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_read_expect = "SyntaxTreeNode.read-expect";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_read_expect
Returncode SyntaxTreeNode_read_expect(SyntaxTreeNode* self, String* expected_text) {
  String* actual_text = _new_string(expected_text->length + 1);
  if (actual_text == NULL) RAISE(40)
  {int n; for (n = (0); n < (expected_text->length); ++n) {
    Char _Char82;
    CHECK(42, read_c(&(_Char82)) )
    CHECK(42, String_append(actual_text, _Char82) )
  }}
  Bool _Bool83;
  CHECK(43, String_equal(actual_text, expected_text, &(_Bool83)) )
  if (!_Bool83) {
    CHECK(44, SyntaxTreeNode_m_syntax_error2(self, &(String){9, 8, "expected"}, expected_text, &(String){4, 3, "got"}, actual_text) )
  }
  free(actual_text);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Read and check indentation spaces for a line break from the input file */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_read_line_break_spaces(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_read_line_break_spaces = "SyntaxTreeNode.read-line-break-spaces";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_read_line_break_spaces
Returncode SyntaxTreeNode_read_line_break_spaces(SyntaxTreeNode* self) {
  {int n; for (n = (0); n < (glob->spaces + 4); ++n) {
    Char _Char84;
    CHECK(51, read_c(&(_Char84)) )
    if (_Char84 != ' ') {
      String* expected_spaces = &(String){128, 0, (char[128]){0}};
      String* actual_spaces = &(String){128, 0, (char[128]){0}};
      CHECK(54, Int_str(glob->spaces + 4, expected_spaces) )
      CHECK(55, Int_str(n - 1, actual_spaces) )
      CHECK(56, SyntaxTreeNode_m_syntax_error2(self, &(String){32, 31, "too short indentation, expected"}, expected_spaces, &(String){4, 3, "got"}, actual_spaces) )
    }
  }}
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_write_line_num(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_write_line_num = "SyntaxTreeNode.write-line-num";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_write_line_num
Returncode SyntaxTreeNode_write_line_num(SyntaxTreeNode* self) {
  CHECK(63, write_int(self->line_number) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_write_raise(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_write_raise = "SyntaxTreeNode.write-raise";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_write_raise
Returncode SyntaxTreeNode_write_raise(SyntaxTreeNode* self) {
  CHECK(66, write(&(String){7, 6, "RAISE("}) )
  CHECK(67, SyntaxTreeNode_write_line_num(self) )
  CHECK(68, write(&(String){2, 1, ")"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Raise a syntax error with message: *//* `Code error in {file-name}[{line-number}] {text} "{item}"` */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error(SyntaxTreeNode* self, String* text, String* item);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error = "SyntaxTreeNode.m-syntax-error";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error
Returncode SyntaxTreeNode_m_syntax_error(SyntaxTreeNode* self, String* text, String* item) {
  CHECK(73, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(74, print_msg_with_item(text, item) )
  CHECK(75, print(&(String){2, 1, "\n"}) )
  RAISE(76)
}
#undef MR_FUNC_NAME
#endif/* Same as `m-syntax-error` but but with another `{text} "{item}" pair */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error2(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error2 = "SyntaxTreeNode.m-syntax-error2";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error2
Returncode SyntaxTreeNode_m_syntax_error2(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2) {
  CHECK(81, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(82, print_msg_with_item(text1, item1) )
  CHECK(83, print(&(String){2, 1, " "}) )
  CHECK(84, print_msg_with_item(text2, item2) )
  CHECK(85, print(&(String){2, 1, "\n"}) )
  RAISE(86)
}
#undef MR_FUNC_NAME
#endif/* Same as `m-syntax-error` but but with another 2 `{text} "{item}" pair */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error3(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2, String* text3, String* item3);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error3 = "SyntaxTreeNode.m-syntax-error3";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error3
Returncode SyntaxTreeNode_m_syntax_error3(SyntaxTreeNode* self, String* text1, String* item1, String* text2, String* item2, String* text3, String* item3) {
  CHECK(96, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(97, print_msg_with_item(text1, item1) )
  CHECK(98, print(&(String){2, 1, " "}) )
  CHECK(99, print_msg_with_item(text2, item2) )
  CHECK(100, print(&(String){2, 1, " "}) )
  CHECK(101, print_msg_with_item(text3, item3) )
  CHECK(102, print(&(String){2, 1, "\n"}) )
  RAISE(103)
}
#undef MR_FUNC_NAME
#endif/* Same as `m-syntax-error` but with a character item */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error_c(SyntaxTreeNode* self, String* text, Char item);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error_c = "SyntaxTreeNode.m-syntax-error-c";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error_c
Returncode SyntaxTreeNode_m_syntax_error_c(SyntaxTreeNode* self, String* text, Char item) {
  String* char_str = &(String){16, 0, (char[16]){0}};
  if (item == EOF) {
    CHECK(109, String_copy(char_str, &(String){4, 3, "EOF"}) )
  }
  else {
    if (item == '\n') {
      CHECK(111, String_copy(char_str, &(String){9, 8, "new-line"}) )
    }
    else {
      CHECK(113, String_append(char_str, item) )
    }
  }
  CHECK(114, SyntaxTreeNode_m_syntax_error(self, text, char_str) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_m_syntax_error_msg(SyntaxTreeNode* self, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_m_syntax_error_msg = "SyntaxTreeNode.m-syntax-error-msg";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_m_syntax_error_msg
Returncode SyntaxTreeNode_m_syntax_error_msg(SyntaxTreeNode* self, String* text) {
  CHECK(117, SyntaxTreeNode_print_syntax_error_header(self) )
  CHECK(118, print(text) )
  CHECK(119, print(&(String){2, 1, "\n"}) )
  RAISE(120)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_print_syntax_error_header(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_print_syntax_error_header = "SyntaxTreeNode.print-syntax-error-header";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_print_syntax_error_header
Returncode SyntaxTreeNode_print_syntax_error_header(SyntaxTreeNode* self) {
  CHECK(123, print(&(String){15, 14, "Code error in "}) )
  CHECK(124, print(self->input_file_name) )
  CHECK(125, print(&(String){2, 1, "["}) )
  String* line_num_str = &(String){32, 0, (char[32]){0}};
  CHECK(127, Int_str(self->line_number, line_num_str) )
  CHECK(128, print(line_num_str) )
  CHECK(129, print(&(String){3, 2, "] "}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_analyze(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_analyze = "SyntaxTreeNode.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_analyze
Returncode SyntaxTreeNode_analyze(SyntaxTreeNode* self) {
  /* do nothing as default */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_write(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_write = "SyntaxTreeNode.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_write
Returncode SyntaxTreeNode_write(SyntaxTreeNode* self) {
  RAISE(135)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeNode__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeNode__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/argument.c"
#include "global/common.c"
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
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/function.c"
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
