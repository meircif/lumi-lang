#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/node.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file15_name = "syntax-tree/node.3.mr";
#endif
#define MR_FILE_NAME _mr_file15_name

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
  Bool _Bool42;
  CHECK(23, String_equal(access_str, &(String){5, 4, "copy"}, &(_Bool42)) )
  if (_Bool42) {
    (*access) = ACCESS_COPY;
  }
  else {
    Bool _Bool43;
    CHECK(25, String_equal(access_str, &(String){5, 4, "user"}, &(_Bool43)) )
    if (_Bool43) {
      (*access) = ACCESS_USER;
    }
    else {
      Bool _Bool44;
      CHECK(27, String_equal(access_str, &(String){6, 5, "owner"}, &(_Bool44)) )
      if (_Bool44) {
        (*access) = ACCESS_OWNER;
      }
      else {
        Bool _Bool45;
        CHECK(29, String_equal(access_str, &(String){4, 3, "var"}, &(_Bool45)) )
        if (_Bool45) {
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
    Char _Char46;
    CHECK(42, read_c(&(_Char46)) )
    CHECK(42, String_append(actual_text, _Char46) )
  }}
  Bool _Bool47;
  CHECK(43, String_equal(actual_text, expected_text, &(_Bool47)) )
  if (!_Bool47) {
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
    Char _Char48;
    CHECK(51, read_c(&(_Char48)) )
    if (_Char48 != ' ') {
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


/* A basic branch node in the syntax tree - a node with chldren nodes */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeBranch SyntaxTreeBranch;
#elif MR_STAGE == MR_TYPES(1)
struct SyntaxTreeBranch {
  SyntaxTreeNode _base;
  Int indentation_spaces;
  List* variables;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_init(SyntaxTreeBranch* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_init = "SyntaxTreeBranch.init";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_init
Returncode SyntaxTreeBranch_init(SyntaxTreeBranch* self) {
  self->variables = malloc(sizeof(List));
  if (self->variables == NULL) RAISE(144)
  *self->variables = (List){NULL, NULL};
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_parse_block_children(SyntaxTreeBranch* self, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_block_children = "SyntaxTreeBranch.parse-block-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_block_children
Returncode SyntaxTreeBranch_parse_block_children(SyntaxTreeBranch* self, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end) {
  if ((*end) != '\n') {
    CHECK(150, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){34, 33, "expected block in a new line, got"}, (*end)) )
  }
  CHECK(151, SyntaxTreeBranch_init(self) )
  CHECK(152, SyntaxTreeBranch_parse_children(self, parent_type, parent_block, &((*end))) )
  if ((*end) != EOF) {
    glob->save_input = true;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_parse_children(SyntaxTreeBranch* self, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_children = "SyntaxTreeBranch.parse-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_children
Returncode SyntaxTreeBranch_parse_children(SyntaxTreeBranch* self, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end) {
  Int my_line_number = self->_base.line_number;
  while (true) {
    String* keyword = NULL;
    Int spaces = 0;
    CHECK(163, read_until(&(String){6, 5, " .([?"}, true, &(keyword), &((*end)), &(spaces)) )
    /* ignore empty lines */
    if (keyword->length > 0 || (*end) != '\n') {
      CHECK(166, SyntaxTreeNode_set_location(&(self->_base)) )
      
      if (spaces > self->indentation_spaces) {
        String* expecte_num = &(String){32, 0, (char[32]){0}};
        CHECK(170, Int_str(self->indentation_spaces, expecte_num) )
        String* actual_num = &(String){32, 0, (char[32]){0}};
        CHECK(172, Int_str(spaces, actual_num) )
        CHECK(173, SyntaxTreeNode_m_syntax_error2(&(self->_base), &(String){30, 29, "indentation too big, expected"}, expecte_num, &(String){4, 3, "got"}, actual_num) )
      }
      
      if (!(spaces == self->indentation_spaces && (*end) != EOF)) break;
      
      Bool _Bool49;
      CHECK(181, SyntaxTreeBranch_parse_if_common(self, keyword, parent_type, parent_block, &((*end)), &(_Bool49)) )
      if (!_Bool49) {
        CHECK(183, (self)->_base._dtl[2](self, keyword, &((*end))) )
      }
      
      if (!((*end) != EOF)) break;
      if (!glob->save_input && (*end) != '\n') {
        /* TODO: is possible? */
        CHECK(188, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){35, 34, "expected new-line in line end, got"}, (*end)) )
      }
    }
  }
  
  self->_base.line_number = my_line_number;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_parse_if_common(SyntaxTreeBranch* self, String* keyword, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, Bool* is_parsed);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_if_common = "SyntaxTreeBranch.parse-if-common";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_if_common
Returncode SyntaxTreeBranch_parse_if_common(SyntaxTreeBranch* self, String* keyword, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, Bool* is_parsed) {
  (*is_parsed) = (*end) == ' ';
  if (!(*is_parsed)) {
    return OK;
  }
  
  Bool _Bool50;
  CHECK(203, String_equal(keyword, &(String){2, 1, "#"}, &(_Bool50)) )
  Bool _Bool51;
  CHECK(203, String_equal(keyword, &(String){3, 2, "##"}, &(_Bool51)) )
  if (_Bool50 || _Bool51) {
    String* text = NULL;
    Int _Int52;
    CHECK(205, read_until(&(String){1, 0, ""}, false, &(text), &((*end)), &(_Int52)) )
  }
  else {
    Bool _Bool53;
    CHECK(206, String_equal(keyword, &(String){3, 2, "{#"}, &(_Bool53)) )
    Bool _Bool54;
    CHECK(206, String_equal(keyword, &(String){4, 3, "{##"}, &(_Bool54)) )
    if (_Bool53 || _Bool54) {
      Char prev = '\0';
      while (true) {
        Char curr = '\0';
        CHECK(210, read_c(&(curr)) )
        if (!(curr != EOF && (curr != '}' || prev != '#'))) break;
        prev = curr;
      }
      CHECK(213, read_c(&((*end))) )
      
    }
    else {
      Bool _Bool55;
      CHECK(215, String_equal(keyword, &(String){4, 3, "var"}, &(_Bool55)) )
      if (_Bool55) {
        SyntaxTreeVariable* _SyntaxTreeVariable56;
        CHECK(216, SyntaxTreeVariable_parse_new(NULL, ACCESS_VAR, parent_type, parent_block, &((*end)), &(_SyntaxTreeVariable56)) )
        CHECK(216, List_add(self->variables, _SyntaxTreeVariable56) )
      }
      else {
        Bool _Bool57;
        CHECK(219, String_equal(keyword, &(String){5, 4, "user"}, &(_Bool57)) )
        if (_Bool57) {
          SyntaxTreeVariable* _SyntaxTreeVariable58;
          CHECK(220, SyntaxTreeVariable_parse_new(NULL, ACCESS_USER, parent_type, parent_block, &((*end)), &(_SyntaxTreeVariable58)) )
          CHECK(220, List_add(self->variables, _SyntaxTreeVariable58) )
        }
        else {
          Bool _Bool59;
          CHECK(223, String_equal(keyword, &(String){6, 5, "owner"}, &(_Bool59)) )
          if (_Bool59) {
            SyntaxTreeVariable* _SyntaxTreeVariable60;
            CHECK(224, SyntaxTreeVariable_parse_new(NULL, ACCESS_OWNER, parent_type, parent_block, &((*end)), &(_SyntaxTreeVariable60)) )
            CHECK(224, List_add(self->variables, _SyntaxTreeVariable60) )
            
          }
          else {
            (*is_parsed) = false;
          }
        }
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_parse_child(SyntaxTreeBranch* self, String* keyword, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_child = "SyntaxTreeBranch.parse-child";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_child
Returncode SyntaxTreeBranch_parse_child(SyntaxTreeBranch* self, String* keyword, Char* end) {
  RAISE(232)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_m_find_variable(SyntaxTreeBranch* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_m_find_variable = "SyntaxTreeBranch.m-find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_m_find_variable
Returncode SyntaxTreeBranch_m_find_variable(SyntaxTreeBranch* self, String* name, SyntaxTreeVariable** variable) {
  ListNode* child = self->variables->first;
  while (true) {
    if (!(NULL != child)) break;
    Bool _Bool61;
    CHECK(239, SyntaxTreeVariable_m_find_variable(((SyntaxTreeVariable*)(child->item)), name, &((*variable)), &(_Bool61)) )
    if (!(!_Bool61)) break;
    child = child->next;
  }
  (*variable) = NULL;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_analyze(SyntaxTreeBranch* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_analyze = "SyntaxTreeBranch.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_analyze
Returncode SyntaxTreeBranch_analyze(SyntaxTreeBranch* self) {
  CHECK(244, SyntaxTreeBranch_analyze_children(self, self->variables) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_analyze_children(SyntaxTreeBranch* self, List* child_list);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_analyze_children = "SyntaxTreeBranch.analyze-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_analyze_children
Returncode SyntaxTreeBranch_analyze_children(SyntaxTreeBranch* self, List* child_list) {
  ListNode* child = child_list->first;
  while (true) {
    if (!(NULL != child)) break;
    CHECK(250, (((SyntaxTreeNode*)(child->item)))->_dtl[0](((SyntaxTreeNode*)(child->item))) )
    child = child->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_write(SyntaxTreeBranch* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write = "SyntaxTreeBranch.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_write
Returncode SyntaxTreeBranch_write(SyntaxTreeBranch* self) {
  CHECK(254, SyntaxTreeBranch_write_children(self, self->variables) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_write_children(SyntaxTreeBranch* self, List* child_list);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write_children = "SyntaxTreeBranch.write-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_write_children
Returncode SyntaxTreeBranch_write_children(SyntaxTreeBranch* self, List* child_list) {
  ListNode* child = child_list->first;
  while (true) {
    if (!(NULL != child)) break;
    if (self->indentation_spaces > 0) {
      CHECK(261, SyntaxTreeBranch_write_spaces(self) )
    }
    else {
      CHECK(263, write(&(String){2, 1, "\n"}) )
    }
    CHECK(264, (((SyntaxTreeNode*)(child->item)))->_dtl[1](((SyntaxTreeNode*)(child->item))) )
    CHECK(265, write(&(String){2, 1, "\n"}) )
    child = child->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_write_spaces(SyntaxTreeBranch* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write_spaces = "SyntaxTreeBranch.write-spaces";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_write_spaces
Returncode SyntaxTreeBranch_write_spaces(SyntaxTreeBranch* self) {
  CHECK(269, write_spaces(self->indentation_spaces) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBranch__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBranch__dtl[] = {(void*)SyntaxTreeBranch_analyze, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBranch_parse_child, (void*)SyntaxTreeBranch_m_find_variable};
#endif


/* A basic namespace node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeNamespace SyntaxTreeNamespace;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeNamespace {
  SyntaxTreeBranch _base;
  List* functions;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_init(SyntaxTreeNamespace* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_init = "SyntaxTreeNamespace.init";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_init
Returncode SyntaxTreeNamespace_init(SyntaxTreeNamespace* self) {
  CHECK(277, SyntaxTreeBranch_init(&(self->_base)) )
  self->functions = malloc(sizeof(List));
  if (self->functions == NULL) RAISE(278)
  *self->functions = (List){NULL, NULL};
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_parse_if_function(SyntaxTreeNamespace* self, String* keyword, TypeData* parent_type, Char* end, Bool* is_func);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_parse_if_function = "SyntaxTreeNamespace.parse-if-function";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_parse_if_function
Returncode SyntaxTreeNamespace_parse_if_function(SyntaxTreeNamespace* self, String* keyword, TypeData* parent_type, Char* end, Bool* is_func) {
  CHECK(283, String_equal(keyword, &(String){5, 4, "func"}, &((*is_func))) )
  if ((*is_func)) {
    if ((*end) != ' ') {
      CHECK(286, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){33, 32, "expected space after \"func\", got"}, (*end)) )
    }
    SyntaxTreeFunction* _SyntaxTreeFunction62;
    CHECK(288, SyntaxTreeFunction_parse_new(NULL, parent_type, &((*end)), &(_SyntaxTreeFunction62)) )
    CHECK(288, List_add(self->functions, _SyntaxTreeFunction62) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_m_find_function(SyntaxTreeNamespace* self, String* name, SyntaxTreeFunction** function);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_m_find_function = "SyntaxTreeNamespace.m-find-function";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_m_find_function
Returncode SyntaxTreeNamespace_m_find_function(SyntaxTreeNamespace* self, String* name, SyntaxTreeFunction** function) {
  ListNode* child = self->functions->first;
  while (true) {
    if (!(NULL != child)) break;
    Bool _Bool63;
    CHECK(295, String_equal(((SyntaxTreeFunction*)(child->item))->name, name, &(_Bool63)) )
    if (_Bool63) {
      (*function) = ((SyntaxTreeFunction*)(child->item));
      return OK;
    }
    child = child->next;
  }
  (*function) = NULL;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_analyze(SyntaxTreeNamespace* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_analyze = "SyntaxTreeNamespace.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_analyze
Returncode SyntaxTreeNamespace_analyze(SyntaxTreeNamespace* self) {
  CHECK(302, SyntaxTreeBranch_analyze(&(self->_base)) )
  CHECK(303, SyntaxTreeBranch_analyze_children(&(self->_base), self->functions) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_write(SyntaxTreeNamespace* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_write = "SyntaxTreeNamespace.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_write
Returncode SyntaxTreeNamespace_write(SyntaxTreeNamespace* self) {
  CHECK(306, SyntaxTreeBranch_write(&(self->_base)) )
  CHECK(307, SyntaxTreeBranch_write_children(&(self->_base), self->functions) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_write_functions_declaration(SyntaxTreeNamespace* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_write_functions_declaration = "SyntaxTreeNamespace.write-functions-declaration";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_write_functions_declaration
Returncode SyntaxTreeNamespace_write_functions_declaration(SyntaxTreeNamespace* self) {
  ListNode* child = self->functions->first;
  while (true) {
    if (!(NULL != child)) break;
    CHECK(313, SyntaxTreeFunction_write_declaration(((SyntaxTreeFunction*)(child->item))) )
    child = child->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeNamespace__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeNamespace__dtl[] = {(void*)SyntaxTreeNamespace_analyze, (void*)SyntaxTreeNamespace_write, (void*)SyntaxTreeBranch_parse_child, (void*)SyntaxTreeBranch_m_find_variable};
#endif


/* A basic code node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeCode SyntaxTreeCode;
#elif MR_STAGE == MR_TYPES(1)
struct SyntaxTreeCode {
  SyntaxTreeNode _base;
  SyntaxTreeBlock* parent;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCode_m_find_variable(SyntaxTreeCode* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCode_m_find_variable = "SyntaxTreeCode.m-find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeCode_m_find_variable
Returncode SyntaxTreeCode_m_find_variable(SyntaxTreeCode* self, String* name, SyntaxTreeVariable** variable) {
  CHECK(322, (self->parent)->_base._base._dtl[3](self->parent, name, &((*variable))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCode_m_get_parent_type(SyntaxTreeCode* self, TypeData** parent_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCode_m_get_parent_type = "SyntaxTreeCode.m-get-parent-type";
#define MR_FUNC_NAME _func_name_SyntaxTreeCode_m_get_parent_type
Returncode SyntaxTreeCode_m_get_parent_type(SyntaxTreeCode* self, TypeData** parent_type) {
  CHECK(325, (self->parent)->_base._base._dtl[4](self->parent, &((*parent_type))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCode_analyze_expression(SyntaxTreeCode* self, Expression* expression, TypeData* expected_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCode_analyze_expression = "SyntaxTreeCode.analyze-expression";
#define MR_FUNC_NAME _func_name_SyntaxTreeCode_analyze_expression
Returncode SyntaxTreeCode_analyze_expression(SyntaxTreeCode* self, Expression* expression, TypeData* expected_type) {
  CHECK(329, (expression)->_base._dtl[0](expression) )
  if (!(NULL != expression->result_type)) {
    CHECK(331, SyntaxTreeNode_m_syntax_error(&(self->_base), &(String){30, 29, "got void expression, expected"}, expected_type->name) )
  }
  if (expression->result_type->type_data != expected_type) {
    CHECK(334, SyntaxTreeNode_m_syntax_error2(&(self->_base), &(String){4, 3, "got"}, expression->result_type->type_data->name, &(String){21, 20, "expression, expected"}, expected_type->name) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCode_write_spaces(SyntaxTreeCode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCode_write_spaces = "SyntaxTreeCode.write-spaces";
#define MR_FUNC_NAME _func_name_SyntaxTreeCode_write_spaces
Returncode SyntaxTreeCode_write_spaces(SyntaxTreeCode* self) {
  CHECK(341, SyntaxTreeBranch_write_spaces(&(self->parent->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCode_m_is_end_point(SyntaxTreeCode* self, Bool* is_end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCode_m_is_end_point = "SyntaxTreeCode.m-is-end-point";
#define MR_FUNC_NAME _func_name_SyntaxTreeCode_m_is_end_point
Returncode SyntaxTreeCode_m_is_end_point(SyntaxTreeCode* self, Bool* is_end) {
  (*is_end) = false;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeCode__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeCode__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Count occurrences of a specific type */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeCount TypeCount;
#elif MR_STAGE == MR_TYPES(0)
struct TypeCount {
  TypeData* type_data;
  Int count;
};
#endif


/* A basic code block node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeBlock SyntaxTreeBlock;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeBlock {
  SyntaxTreeBranch _base;
  SyntaxTreeBlock* parent;
  List* code_nodes;
  List* aux_variables;
  SyntaxTreeIf* previous_if;
  SyntaxTreeVariable* ref_variable;
  Bool is_in_loop;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_parse_block(SyntaxTreeBlock* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_parse_block = "SyntaxTreeBlock.parse-block";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_parse_block
Returncode SyntaxTreeBlock_parse_block(SyntaxTreeBlock* self, Char* end) {
  self->code_nodes = malloc(sizeof(List));
  if (self->code_nodes == NULL) RAISE(363)
  *self->code_nodes = (List){NULL, NULL};
  CHECK(364, SyntaxTreeBranch_parse_block_children(&(self->_base), NULL, self, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_parse_child(SyntaxTreeBlock* self, String* keyword, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_parse_child = "SyntaxTreeBlock.parse-child";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_parse_child
Returncode SyntaxTreeBlock_parse_child(SyntaxTreeBlock* self, String* keyword, Char* end) {
  SyntaxTreeCode* node = NULL;
  SyntaxTreeIf* new_if = NULL;
  
  Bool _Bool64;
  CHECK(370, SyntaxTreeBlock_m_has_end_point(self, &(_Bool64)) )
  if (_Bool64) {
    CHECK(371, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){17, 16, "unreachable code"}) )
  }
  
  Bool _Bool65;
  CHECK(373, String_equal(keyword, &(String){3, 2, "if"}, &(_Bool65)) )
  if (_Bool65) {
    if ((*end) != ' ') {
      CHECK(375, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after \"if\", got"}, (*end)) )
    }
    CHECK(376, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
    CHECK(377, List_add(self->code_nodes, &(new_if->_base._base)) )
    
  }
  else {
    Bool _Bool66;
    CHECK(379, String_equal(keyword, &(String){5, 4, "else"}, &(_Bool66)) )
    if (_Bool66) {
      if (!(NULL != self->previous_if)) {
        CHECK(381, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){31, 30, "\"else\" without a previous \"if\""}) )
      }
      if ((*end) != '\n') {
        CHECK(383, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected new-line after \"else\", got"}, (*end)) )
      }
      SyntaxTreeElse* _SyntaxTreeElse67;
      CHECK(385, SyntaxTreeElse_parse_new(NULL, self, &((*end)), &(_SyntaxTreeElse67)) )
      CHECK(385, SyntaxTreeIf_add_else(self->previous_if, _SyntaxTreeElse67) )
      
    }
    else {
      Bool _Bool68;
      CHECK(388, String_equal(keyword, &(String){8, 7, "else-if"}, &(_Bool68)) )
      if (_Bool68) {
        if (!(NULL != self->previous_if)) {
          CHECK(390, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){34, 33, "\"else-if\" without a previous \"if\""}) )
        }
        if ((*end) != ' ') {
          CHECK(392, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected space after \"else-if\", got"}, (*end)) )
        }
        CHECK(394, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
        CHECK(395, SyntaxTreeIf_add_else_if(self->previous_if, new_if) )
        
      }
      else {
        Bool _Bool69;
        CHECK(397, String_equal(keyword, &(String){3, 2, "do"}, &(_Bool69)) )
        if (_Bool69) {
          if ((*end) != '\n') {
            CHECK(399, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected new-line after \"do\", got"}, (*end)) )
          }
          SyntaxTreeDoLoop* _SyntaxTreeDoLoop70;
          CHECK(401, SyntaxTreeDoLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeDoLoop70)) )
          CHECK(401, List_add(self->code_nodes, &(_SyntaxTreeDoLoop70->_base._base)) )
          
        }
        else {
          Bool _Bool71;
          CHECK(404, String_equal(keyword, &(String){4, 3, "for"}, &(_Bool71)) )
          if (_Bool71) {
            if ((*end) != ' ') {
              CHECK(406, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"for\", got"}, (*end)) )
            }
            SyntaxTreeForLoop* _SyntaxTreeForLoop72;
            CHECK(408, SyntaxTreeForLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeForLoop72)) )
            CHECK(408, List_add(self->code_nodes, &(_SyntaxTreeForLoop72->_base._base)) )
            
          }
          else {
            Bool _Bool73;
            CHECK(411, String_equal(keyword, &(String){6, 5, "while"}, &(_Bool73)) )
            if (_Bool73) {
              if ((*end) != ' ') {
                CHECK(413, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected space after \"while\", got"}, (*end)) )
              }
              SyntaxTreeWhile* _SyntaxTreeWhile74;
              CHECK(415, SyntaxTreeWhile_parse_new(NULL, self, &((*end)), &(_SyntaxTreeWhile74)) )
              CHECK(415, List_add(self->code_nodes, &(_SyntaxTreeWhile74->_base)) )
              
            }
            else {
              Bool _Bool75;
              CHECK(418, String_equal(keyword, &(String){9, 8, "continue"}, &(_Bool75)) )
              if (_Bool75) {
                if ((*end) != '\n') {
                  CHECK(420, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){40, 39, "expected new-line after \"continue\", got"}, (*end)) )
                }
                SyntaxTreeContinue* _SyntaxTreeContinue76;
                CHECK(422, SyntaxTreeContinue_parse_new(NULL, self, &((*end)), &(_SyntaxTreeContinue76)) )
                CHECK(422, List_add(self->code_nodes, &(_SyntaxTreeContinue76->_base)) )
                
              }
              else {
                Bool _Bool77;
                CHECK(425, String_equal(keyword, &(String){7, 6, "return"}, &(_Bool77)) )
                if (_Bool77) {
                  if ((*end) != '\n') {
                    CHECK(427, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){38, 37, "expected new-line after \"return\", got"}, (*end)) )
                  }
                  SyntaxTreeReturn* _SyntaxTreeReturn78;
                  CHECK(429, SyntaxTreeReturn_parse_new(NULL, self, &((*end)), &(_SyntaxTreeReturn78)) )
                  CHECK(429, List_add(self->code_nodes, &(_SyntaxTreeReturn78->_base)) )
                  
                }
                else {
                  Bool _Bool79;
                  CHECK(432, String_equal(keyword, &(String){6, 5, "raise"}, &(_Bool79)) )
                  if (_Bool79) {
                    if ((*end) != '\n') {
                      CHECK(434, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){37, 36, "expected new-line after \"raise\", got"}, (*end)) )
                    }
                    SyntaxTreeRaise* _SyntaxTreeRaise80;
                    CHECK(436, SyntaxTreeRaise_parse_new(NULL, self, &((*end)), &(_SyntaxTreeRaise80)) )
                    CHECK(436, List_add(self->code_nodes, &(_SyntaxTreeRaise80->_base)) )
                    
                  }
                  else {
                    Bool _Bool81;
                    CHECK(439, String_equal(keyword, &(String){4, 3, "new"}, &(_Bool81)) )
                    if (_Bool81) {
                      if ((*end) != ' ') {
                        CHECK(441, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"new\", got"}, (*end)) )
                      }
                      SyntaxTreeVariable* _SyntaxTreeVariable82;
                      CHECK(443, SyntaxTreeVariable_parse_new(NULL, ACCESS_OWNER, NULL, self, &((*end)), &(_SyntaxTreeVariable82)) )
                      CHECK(443, List_add(self->_base.variables, _SyntaxTreeVariable82) )
                      
                    }
                    else {
                      glob->save_input = true;
                      SyntaxTreeExpression* _SyntaxTreeExpression83;
                      CHECK(448, SyntaxTreeExpression_parse_new(NULL, self, &((*end)), &(_SyntaxTreeExpression83)) )
                      CHECK(448, List_add(self->code_nodes, &(_SyntaxTreeExpression83->_base)) )
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  
  self->previous_if = new_if;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_m_has_end_point(SyntaxTreeBlock* self, Bool* has_end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_m_has_end_point = "SyntaxTreeBlock.m-has-end-point";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_m_has_end_point
Returncode SyntaxTreeBlock_m_has_end_point(SyntaxTreeBlock* self, Bool* has_end) {
  if (NULL != self->code_nodes->last) {
    CHECK(455, (((SyntaxTreeCode*)(self->code_nodes->last->item)))->_base._dtl[2](((SyntaxTreeCode*)(self->code_nodes->last->item)), &((*has_end))) )
  }
  else {
    (*has_end) = false;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_m_find_variable(SyntaxTreeBlock* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_m_find_variable = "SyntaxTreeBlock.m-find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_m_find_variable
Returncode SyntaxTreeBlock_m_find_variable(SyntaxTreeBlock* self, String* name, SyntaxTreeVariable** variable) {
  CHECK(461, SyntaxTreeBranch_m_find_variable(&(self->_base), name, &((*variable))) )
  if (!(NULL != (*variable)) &&  NULL !=  self->ref_variable) {
    Bool _Bool84;
    CHECK(463, SyntaxTreeVariable_m_find_variable(self->ref_variable, name, &((*variable)), &(_Bool84)) )
  }
  if (!(NULL != (*variable)) &&  NULL !=  self->parent) {
    CHECK(465, (self->parent)->_base._base._dtl[3](self->parent, name, &((*variable))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_m_get_parent_type(SyntaxTreeBlock* self, TypeData** parent_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_m_get_parent_type = "SyntaxTreeBlock.m-get-parent-type";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_m_get_parent_type
Returncode SyntaxTreeBlock_m_get_parent_type(SyntaxTreeBlock* self, TypeData** parent_type) {
  CHECK(468, (self->parent)->_base._base._dtl[4](self->parent, &((*parent_type))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_add_aux_variable(SyntaxTreeBlock* self, Int access, TypeInstance* type_instance, SyntaxTreeVariable** new_variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_add_aux_variable = "SyntaxTreeBlock.add-aux-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_add_aux_variable
Returncode SyntaxTreeBlock_add_aux_variable(SyntaxTreeBlock* self, Int access, TypeInstance* type_instance, SyntaxTreeVariable** new_variable) {
  Int index = 0;
  ListNode* node = self->aux_variables->first;
  while (true) {
    if (!(NULL != node)) break;
    if (!(((TypeCount*)(node->item))->type_data != type_instance->type_data)) break;
    node = node->next;
  }
  if (NULL != node) {
    ((TypeCount*)(node->item))->count += 1;
    index = ((TypeCount*)(node->item))->count;
  }
  else {
    TypeCount* type_count = malloc(sizeof(TypeCount));
    if (type_count == NULL) RAISE(482)
    *type_count = (TypeCount){NULL, 0};
    type_count->type_data = type_instance->type_data;
    CHECK(484, List_add(self->aux_variables, type_count) )
  }
  SyntaxTreeVariable* variable = malloc(sizeof(SyntaxTreeVariable));
  if (variable == NULL) RAISE(485)
  *variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL};
  variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  variable->name = _new_string(type_instance->type_data->name->length + 21);
  if (variable->name == NULL) RAISE(486)
  CHECK(488, String_copy(variable->name, &(String){5, 4, "aux_"}) )
  CHECK(489, String_concat(variable->name, type_instance->type_data->name) )
  CHECK(490, String_append(variable->name, '_') )
  String* index_str = &(String){16, 0, (char[16]){0}};
  CHECK(492, Int_str(index, index_str) )
  CHECK(493, String_concat(variable->name, index_str) )
  variable->_base.parent = self;
  if (access == ACCESS_COPY) {
    variable->access = ACCESS_VAR;
  }
  else {
    variable->access = access;
  }
  CHECK(499, TypeInstance_m_copy_new(type_instance, &(variable->type_instance)) )
  (*new_variable) = variable;
  CHECK(501, List_add(self->_base.variables, variable) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_analyze(SyntaxTreeBlock* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_analyze = "SyntaxTreeBlock.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_analyze
Returncode SyntaxTreeBlock_analyze(SyntaxTreeBlock* self) {
  CHECK(504, SyntaxTreeBranch_analyze(&(self->_base)) )
  CHECK(505, SyntaxTreeBranch_analyze_children(&(self->_base), self->code_nodes) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_write_block(SyntaxTreeBlock* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_write_block = "SyntaxTreeBlock.write-block";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_write_block
Returncode SyntaxTreeBlock_write_block(SyntaxTreeBlock* self) {
  /* `previous-text` { */
  /*   `block...` */
  /* } */
  CHECK(511, write(&(String){4, 3, " {\n"}) )
  CHECK(512, SyntaxTreeBranch_write(&(self->_base)) )
  CHECK(513, SyntaxTreeBranch_write_children(&(self->_base), self->code_nodes) )
  CHECK(514, write_spaces(self->_base.indentation_spaces - 2) )
  CHECK(515, write(&(String){2, 1, "}"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBlock__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBlock__dtl[] = {(void*)SyntaxTreeBlock_analyze, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeBlock_m_find_variable, (void*)SyntaxTreeBlock_m_get_parent_type};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
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
