#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/branch.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file14_name = "syntax-tree/branch.3.mr";
#endif
#define MR_FILE_NAME _mr_file14_name

/* MR4 compiler - Syntax tree node branch */

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
  if (self->variables == NULL) RAISE(9)
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
    CHECK(15, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){34, 33, "expected block in a new line, got"}, (*end)) )
  }
  CHECK(16, SyntaxTreeBranch_init(self) )
  CHECK(17, SyntaxTreeBranch_parse_children(self, parent_type, parent_block, &((*end))) )
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
    CHECK(28, read_until(&(String){6, 5, " .([?"}, true, &(keyword), &((*end)), &(spaces)) )
    /* ignore empty lines */
    if (keyword->length > 0 || (*end) != '\n') {
      CHECK(31, SyntaxTreeNode_set_location(&(self->_base)) )
      
      Bool _Bool64;
      CHECK(33, SyntaxTreeBranch_parse_if_comment(self, keyword, &((*end)), &(_Bool64)) )
      if (!_Bool64) {
        if (spaces > self->indentation_spaces) {
          String* expecte_num = &(String){32, 0, (char[32]){0}};
          CHECK(36, Int_str(self->indentation_spaces, expecte_num) )
          String* actual_num = &(String){32, 0, (char[32]){0}};
          CHECK(38, Int_str(spaces, actual_num) )
          CHECK(39, SyntaxTreeNode_m_syntax_error2(&(self->_base), &(String){30, 29, "indentation too big, expected"}, expecte_num, &(String){4, 3, "got"}, actual_num) )
        }
        
        if (!(spaces == self->indentation_spaces && (*end) != EOF)) break;
        
        Bool _Bool65;
        CHECK(47, SyntaxTreeBranch_parse_if_common(self, keyword, parent_type, parent_block, &((*end)), &(_Bool65)) )
        if (!_Bool65) {
          CHECK(49, (self)->_base._dtl[3](self, keyword, &((*end))) )
        }
      }
      
      if (!((*end) != EOF)) break;
      if (!glob->save_input && (*end) != '\n') {
        CHECK(53, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){35, 34, "expected new-line in line end, got"}, (*end)) )
      }
    }
  }
  
  self->_base.line_number = my_line_number;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_parse_if_comment(SyntaxTreeBranch* self, String* keyword, Char* end, Bool* is_parsed);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_if_comment = "SyntaxTreeBranch.parse-if-comment";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_if_comment
Returncode SyntaxTreeBranch_parse_if_comment(SyntaxTreeBranch* self, String* keyword, Char* end, Bool* is_parsed) {
  (*is_parsed) = (*end) == ' ';
  if (!(*is_parsed)) {
    return OK;
  }
  Bool _Bool66;
  CHECK(63, String_equal(keyword, &(String){2, 1, "#"}, &(_Bool66)) )
  Bool _Bool67;
  CHECK(63, String_equal(keyword, &(String){3, 2, "##"}, &(_Bool67)) )
  if (_Bool66 || _Bool67) {
    String* text = NULL;
    Int _Int68;
    CHECK(65, read_until(&(String){1, 0, ""}, false, &(text), &((*end)), &(_Int68)) )
  }
  else {
    Bool _Bool69;
    CHECK(66, String_equal(keyword, &(String){3, 2, "{#"}, &(_Bool69)) )
    Bool _Bool70;
    CHECK(66, String_equal(keyword, &(String){4, 3, "{##"}, &(_Bool70)) )
    if (_Bool69 || _Bool70) {
      Char prev = '\0';
      while (true) {
        Char curr = '\0';
        CHECK(70, read_c(&(curr)) )
        if (!(curr != EOF && (curr != '}' || prev != '#'))) break;
        prev = curr;
      }
      CHECK(73, read_c(&((*end))) )
    }
    else {
      (*is_parsed) = false;
    }
  }
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
  List* variables = self->variables;
  if (NULL != parent_block) {
    variables = parent_block->_base.variables;
  }
  
  if (!(*is_parsed)) {
    return OK;
  }
  else {
    Bool _Bool71;
    CHECK(91, String_equal(keyword, &(String){4, 3, "var"}, &(_Bool71)) )
    if (_Bool71) {
      SyntaxTreeVariable* _SyntaxTreeVariable72;
      CHECK(92, SyntaxTreeVariable_parse_new(NULL, ACCESS_VAR, parent_type, parent_block, &((*end)), &(_SyntaxTreeVariable72)) )
      CHECK(92, List_add(variables, _SyntaxTreeVariable72) )
    }
    else {
      Bool _Bool73;
      CHECK(95, String_equal(keyword, &(String){5, 4, "user"}, &(_Bool73)) )
      if (_Bool73) {
        SyntaxTreeVariable* _SyntaxTreeVariable74;
        CHECK(96, SyntaxTreeVariable_parse_new(NULL, ACCESS_USER, parent_type, parent_block, &((*end)), &(_SyntaxTreeVariable74)) )
        CHECK(96, List_add(variables, _SyntaxTreeVariable74) )
      }
      else {
        Bool _Bool75;
        CHECK(99, String_equal(keyword, &(String){6, 5, "owner"}, &(_Bool75)) )
        if (_Bool75) {
          SyntaxTreeVariable* _SyntaxTreeVariable76;
          CHECK(100, SyntaxTreeVariable_parse_new(NULL, ACCESS_OWNER, parent_type, parent_block, &((*end)), &(_SyntaxTreeVariable76)) )
          CHECK(100, List_add(variables, _SyntaxTreeVariable76) )
          
        }
        else {
          (*is_parsed) = false;
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
  RAISE(108)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_find_variable(SyntaxTreeBranch* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_find_variable = "SyntaxTreeBranch.find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_find_variable
Returncode SyntaxTreeBranch_find_variable(SyntaxTreeBranch* self, String* name, SyntaxTreeVariable** variable) {
  (*variable) = NULL;
  ListNode* child = self->variables->first;
  while (true) {
    if (!(NULL != child)) break;
    Bool _Bool77;
    CHECK(116, SyntaxTreeVariable_find_variable(((SyntaxTreeVariable*)(child->item)), name, &((*variable)), &(_Bool77)) )
    if (!(!_Bool77)) break;
    child = child->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_link_types(SyntaxTreeBranch* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_link_types = "SyntaxTreeBranch.link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_link_types
Returncode SyntaxTreeBranch_link_types(SyntaxTreeBranch* self) {
  CHECK(120, SyntaxTreeNode_link_children_types(&(self->_base), self->variables) )
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
  CHECK(123, SyntaxTreeNode_analyze_children(&(self->_base), self->variables) )
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
  CHECK(126, SyntaxTreeNode_write_children(&(self->_base), self->variables) )
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
  CHECK(129, write_spaces(self->indentation_spaces) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBranch__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBranch__dtl[] = {(void*)SyntaxTreeBranch_link_types, (void*)SyntaxTreeBranch_analyze, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBranch_parse_child, (void*)SyntaxTreeBranch_find_variable};
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
  CHECK(137, SyntaxTreeBranch_init(&(self->_base)) )
  self->functions = malloc(sizeof(List));
  if (self->functions == NULL) RAISE(138)
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
  CHECK(143, String_equal(keyword, &(String){5, 4, "func"}, &((*is_func))) )
  if ((*is_func)) {
    if ((*end) != ' ') {
      CHECK(146, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){33, 32, "expected space after \"func\", got"}, (*end)) )
    }
    SyntaxTreeFunction* _SyntaxTreeFunction78;
    CHECK(148, SyntaxTreeFunction_parse_new(NULL, parent_type, &((*end)), &(_SyntaxTreeFunction78)) )
    CHECK(148, List_add(self->functions, _SyntaxTreeFunction78) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_find_function(SyntaxTreeNamespace* self, String* name, SyntaxTreeFunction** function);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_find_function = "SyntaxTreeNamespace.find-function";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_find_function
Returncode SyntaxTreeNamespace_find_function(SyntaxTreeNamespace* self, String* name, SyntaxTreeFunction** function) {
  ListNode* child = self->functions->first;
  while (true) {
    if (!(NULL != child)) break;
    Bool _Bool79;
    CHECK(155, String_equal(((SyntaxTreeFunction*)(child->item))->name, name, &(_Bool79)) )
    if (_Bool79) {
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
Returncode SyntaxTreeNamespace_link_types(SyntaxTreeNamespace* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_link_types = "SyntaxTreeNamespace.link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_link_types
Returncode SyntaxTreeNamespace_link_types(SyntaxTreeNamespace* self) {
  CHECK(162, SyntaxTreeBranch_link_types(&(self->_base)) )
  CHECK(163, SyntaxTreeNode_link_children_types(&(self->_base._base), self->functions) )
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
  CHECK(166, SyntaxTreeBranch_analyze(&(self->_base)) )
  CHECK(167, SyntaxTreeNode_analyze_children(&(self->_base._base), self->functions) )
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
  CHECK(170, SyntaxTreeBranch_write(&(self->_base)) )
  CHECK(171, SyntaxTreeNode_write_children(&(self->_base._base), self->functions) )
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
    CHECK(177, (((SyntaxTreeFunction*)(child->item)))->_base._base._base._dtl[7](((SyntaxTreeFunction*)(child->item))) )
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
Func SyntaxTreeNamespace__dtl[] = {(void*)SyntaxTreeNamespace_link_types, (void*)SyntaxTreeNamespace_analyze, (void*)SyntaxTreeNamespace_write, (void*)SyntaxTreeBranch_parse_child, (void*)SyntaxTreeBranch_find_variable};
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
