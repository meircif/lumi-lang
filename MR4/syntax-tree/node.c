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

/* Basic node type for all syntax tree nodes */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeNode SyntaxTreeNode;
#elif MR_STAGE == MR_TYPES(0)
struct SyntaxTreeNode {
  Func* _dtl;
};
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
  RAISE(12)
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
  List* code_nodes;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_init(SyntaxTreeBranch* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_init = "SyntaxTreeBranch.init";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_init
Returncode SyntaxTreeBranch_init(SyntaxTreeBranch* self) {
  self->variables = malloc(sizeof(List));
  if (self->variables == NULL) RAISE(22)
  *self->variables = (List){NULL, NULL};
  self->code_nodes = malloc(sizeof(List));
  if (self->code_nodes == NULL) RAISE(23)
  *self->code_nodes = (List){NULL, NULL};
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_parse_block_children(SyntaxTreeBranch* self, TypeData* parent_type, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_block_children = "SyntaxTreeBranch.parse-block-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_block_children
Returncode SyntaxTreeBranch_parse_block_children(SyntaxTreeBranch* self, TypeData* parent_type, Char* end) {
  if ((*end) != '\n') {
    CHECK(28, f_syntax_error_c(&(String){34, 33, "expected block in a new line, got"}, (*end)) )
  }
  CHECK(29, SyntaxTreeBranch_init(self) )
  CHECK(30, SyntaxTreeBranch_parse_children(self, parent_type, &((*end))) )
  if ((*end) != EOF) {
    glob->save_input = true;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_parse_children(SyntaxTreeBranch* self, TypeData* parent_type, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_children = "SyntaxTreeBranch.parse-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_children
Returncode SyntaxTreeBranch_parse_children(SyntaxTreeBranch* self, TypeData* parent_type, Char* end) {
  while (true) {
    String* keyword = NULL;
    Int spaces = 0;
    CHECK(38, read_until(&(String){6, 5, " .([?"}, true, &(keyword), &((*end)), &(spaces)) )
    /* ignore empty lines */
    if (keyword->length > 0 || (*end) != '\n') {
      
      if (spaces > self->indentation_spaces) {
        String* expecte_num = &(String){32, 0, (char[32]){0}};
        CHECK(44, Int_str(self->indentation_spaces, expecte_num) )
        String* actual_num = &(String){32, 0, (char[32]){0}};
        CHECK(46, Int_str(spaces, actual_num) )
        CHECK(47, f_syntax_error2(&(String){30, 29, "indentation too big, expected"}, expecte_num, &(String){4, 3, "got"}, actual_num) )
      }
      
      if (!(spaces == self->indentation_spaces && (*end) != EOF)) break;
      
      Bool _Bool44;
      CHECK(55, SyntaxTreeBranch_parse_if_common(self, keyword, parent_type, &((*end)), &(_Bool44)) )
      if (!_Bool44) {
        CHECK(56, (self)->_base._dtl[2](self, keyword, &((*end))) )
      }
      
      if (!((*end) != EOF)) break;
      if (!glob->save_input && (*end) != '\n') {
        /* TODO: is possible? */
        CHECK(61, f_syntax_error_c(&(String){35, 34, "expected new-line in line end, got"}, (*end)) )
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_parse_if_common(SyntaxTreeBranch* self, String* keyword, TypeData* parent_type, Char* end, Bool* is_parsed);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_if_common = "SyntaxTreeBranch.parse-if-common";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_if_common
Returncode SyntaxTreeBranch_parse_if_common(SyntaxTreeBranch* self, String* keyword, TypeData* parent_type, Char* end, Bool* is_parsed) {
  (*is_parsed) = (*end) == ' ';
  if (!(*is_parsed)) {
    return OK;
  }
  
  Bool _Bool45;
  CHECK(70, String_equal(keyword, &(String){2, 1, "#"}, &(_Bool45)) )
  Bool _Bool46;
  CHECK(70, String_equal(keyword, &(String){3, 2, "##"}, &(_Bool46)) )
  if (_Bool45 || _Bool46) {
    String* text = NULL;
    Int _Int47;
    CHECK(72, read_until(&(String){1, 0, ""}, false, &(text), &((*end)), &(_Int47)) )
  }
  else {
    Bool _Bool48;
    CHECK(73, String_equal(keyword, &(String){3, 2, "{#"}, &(_Bool48)) )
    Bool _Bool49;
    CHECK(73, String_equal(keyword, &(String){4, 3, "{##"}, &(_Bool49)) )
    if (_Bool48 || _Bool49) {
      Char prev = '\0';
      while (true) {
        Char curr = '\0';
        CHECK(77, read_c(&(curr)) )
        if (!(curr != EOF && (curr != '}' || prev != '#'))) break;
        prev = curr;
      }
      CHECK(80, read_c(&((*end))) )
      
    }
    else {
      Bool _Bool50;
      CHECK(82, String_equal(keyword, &(String){4, 3, "var"}, &(_Bool50)) )
      if (_Bool50) {
        CHECK(83, SyntaxTreeBranch_add_variable(self, parent_type, ACCESS_VAR, &((*end))) )
      }
      else {
        Bool _Bool51;
        CHECK(84, String_equal(keyword, &(String){5, 4, "user"}, &(_Bool51)) )
        if (_Bool51) {
          CHECK(85, SyntaxTreeBranch_add_variable(self, parent_type, ACCESS_USER, &((*end))) )
        }
        else {
          Bool _Bool52;
          CHECK(86, String_equal(keyword, &(String){6, 5, "owner"}, &(_Bool52)) )
          if (_Bool52) {
            CHECK(87, SyntaxTreeBranch_add_variable(self, parent_type, ACCESS_OWNER, &((*end))) )
            
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
Returncode SyntaxTreeBranch_add_variable(SyntaxTreeBranch* self, TypeData* parent_type, Int access, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_add_variable = "SyntaxTreeBranch.add-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_add_variable
Returncode SyntaxTreeBranch_add_variable(SyntaxTreeBranch* self, TypeData* parent_type, Int access, Char* end) {
  SyntaxTreeVariableInit* var_init = NULL;
  SyntaxTreeVariable* _SyntaxTreeVariable53;
  CHECK(95, SyntaxTreeVariable_parse_new(NULL, access, parent_type, &((*end)), &(var_init), &(_SyntaxTreeVariable53)) )
  CHECK(95, List_add(self->variables, _SyntaxTreeVariable53) )
  if (NULL != var_init) {
    CHECK(98, List_add(self->code_nodes, &(var_init->_base)) )
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
  RAISE(101)
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
    Bool _Bool54;
    CHECK(107, String_equal(((SyntaxTreeVariable*)(child->item))->name, name, &(_Bool54)) )
    if (_Bool54) {
      (*variable) = ((SyntaxTreeVariable*)(child->item));
      return OK;
    }
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
  CHECK(114, SyntaxTreeBranch_analyze_children(self, self->variables) )
  CHECK(115, SyntaxTreeBranch_analyze_children(self, self->code_nodes) )
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
    CHECK(121, (((SyntaxTreeNode*)(child->item)))->_dtl[0](((SyntaxTreeNode*)(child->item))) )
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
  CHECK(125, SyntaxTreeBranch_write_children(self, self->variables) )
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
      CHECK(132, SyntaxTreeBranch_write_spaces(self) )
    }
    else {
      CHECK(134, write(&(String){2, 1, "\n"}) )
    }
    CHECK(135, (((SyntaxTreeNode*)(child->item)))->_dtl[1](((SyntaxTreeNode*)(child->item))) )
    CHECK(136, write(&(String){2, 1, "\n"}) )
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
  CHECK(140, write_spaces(self->indentation_spaces) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBranch__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBranch__dtl[] = {(void*)SyntaxTreeBranch_analyze, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBranch_parse_child};
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
  CHECK(148, SyntaxTreeBranch_init(&(self->_base)) )
  self->functions = malloc(sizeof(List));
  if (self->functions == NULL) RAISE(149)
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
  CHECK(154, String_equal(keyword, &(String){5, 4, "func"}, &((*is_func))) )
  if ((*is_func)) {
    if ((*end) != ' ') {
      CHECK(157, f_syntax_error_c(&(String){33, 32, "expected space after \"func\", got"}, (*end)) )
    }
    SyntaxTreeFunction* _SyntaxTreeFunction55;
    CHECK(158, SyntaxTreeFunction_parse_new(NULL, parent_type, &((*end)), &(_SyntaxTreeFunction55)) )
    CHECK(158, List_add(self->functions, _SyntaxTreeFunction55) )
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
    Bool _Bool56;
    CHECK(165, String_equal(((SyntaxTreeFunction*)(child->item))->name, name, &(_Bool56)) )
    if (_Bool56) {
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
  CHECK(172, SyntaxTreeBranch_analyze(&(self->_base)) )
  CHECK(173, SyntaxTreeBranch_analyze_children(&(self->_base), self->functions) )
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
  CHECK(176, SyntaxTreeBranch_write(&(self->_base)) )
  CHECK(177, SyntaxTreeBranch_write_children(&(self->_base), self->functions) )
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
    CHECK(183, SyntaxTreeFunction_write_declaration(((SyntaxTreeFunction*)(child->item))) )
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
Func SyntaxTreeNamespace__dtl[] = {(void*)SyntaxTreeNamespace_analyze, (void*)SyntaxTreeNamespace_write, (void*)SyntaxTreeBranch_parse_child};
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
  CHECK(192, SyntaxTreeBlock_m_find_variable(self->parent, name, &((*variable))) )
  if (!(NULL != (*variable))) {
    CHECK(194, SyntaxTreeBranch_m_find_variable(&(glob->root->_base._base), name, &((*variable))) )
  }
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
  CHECK(197, (self->parent)->_base._base._dtl[3](self->parent, &((*parent_type))) )
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
  CHECK(200, SyntaxTreeBranch_write_spaces(&(self->parent->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeCode__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeCode__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write};
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
  List* aux_variables;
  SyntaxTreeIf* previous_if;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_parse_block(SyntaxTreeBlock* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_parse_block = "SyntaxTreeBlock.parse-block";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_parse_block
Returncode SyntaxTreeBlock_parse_block(SyntaxTreeBlock* self, Char* end) {
  CHECK(216, SyntaxTreeBranch_parse_block_children(&(self->_base), NULL, &((*end))) )
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
  
  Bool _Bool57;
  CHECK(222, String_equal(keyword, &(String){3, 2, "if"}, &(_Bool57)) )
  if (_Bool57) {
    if ((*end) != ' ') {
      CHECK(224, f_syntax_error_c(&(String){31, 30, "expected space after \"if\", got"}, (*end)) )
    }
    CHECK(225, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
    CHECK(226, List_add(self->_base.code_nodes, &(new_if->_base._base)) )
    
  }
  else {
    Bool _Bool58;
    CHECK(228, String_equal(keyword, &(String){5, 4, "else"}, &(_Bool58)) )
    if (_Bool58) {
      if (!(NULL != self->previous_if)) {
        CHECK(230, f_syntax_error_msg(&(String){31, 30, "\"else\" without a previous \"if\""}) )
      }
      if ((*end) != '\n') {
        CHECK(232, f_syntax_error_c(&(String){36, 35, "expected new-line after \"else\", got"}, (*end)) )
      }
      SyntaxTreeElse* _SyntaxTreeElse59;
      CHECK(233, SyntaxTreeElse_parse_new(NULL, self, &((*end)), &(_SyntaxTreeElse59)) )
      CHECK(233, SyntaxTreeIf_add_else(self->previous_if, _SyntaxTreeElse59) )
      
    }
    else {
      Bool _Bool60;
      CHECK(236, String_equal(keyword, &(String){8, 7, "else-if"}, &(_Bool60)) )
      if (_Bool60) {
        if (!(NULL != self->previous_if)) {
          CHECK(238, f_syntax_error_msg(&(String){34, 33, "\"else-if\" without a previous \"if\""}) )
        }
        if ((*end) != ' ') {
          CHECK(240, f_syntax_error_c(&(String){36, 35, "expected space after \"else-if\", got"}, (*end)) )
        }
        CHECK(241, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
        CHECK(242, SyntaxTreeIf_add_else_if(self->previous_if, new_if) )
        
      }
      else {
        Bool _Bool61;
        CHECK(244, String_equal(keyword, &(String){3, 2, "do"}, &(_Bool61)) )
        if (_Bool61) {
          if ((*end) != '\n') {
            CHECK(246, f_syntax_error_c(&(String){34, 33, "expected new-line after \"do\", got"}, (*end)) )
          }
          SyntaxTreeDoLoop* _SyntaxTreeDoLoop62;
          CHECK(247, SyntaxTreeDoLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeDoLoop62)) )
          CHECK(247, List_add(self->_base.code_nodes, &(_SyntaxTreeDoLoop62->_base._base)) )
          
        }
        else {
          Bool _Bool63;
          CHECK(250, String_equal(keyword, &(String){4, 3, "for"}, &(_Bool63)) )
          if (_Bool63) {
            if ((*end) != ' ') {
              CHECK(252, f_syntax_error_c(&(String){32, 31, "expected space after \"for\", got"}, (*end)) )
            }
            SyntaxTreeForLoop* _SyntaxTreeForLoop64;
            CHECK(253, SyntaxTreeForLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeForLoop64)) )
            CHECK(253, List_add(self->_base.code_nodes, &(_SyntaxTreeForLoop64->_base._base)) )
            
          }
          else {
            Bool _Bool65;
            CHECK(256, String_equal(keyword, &(String){6, 5, "while"}, &(_Bool65)) )
            if (_Bool65) {
              if ((*end) != ' ') {
                CHECK(258, f_syntax_error_c(&(String){34, 33, "expected space after \"while\", got"}, (*end)) )
              }
              SyntaxTreeWhile* _SyntaxTreeWhile66;
              CHECK(259, SyntaxTreeWhile_parse_new(NULL, self, &((*end)), &(_SyntaxTreeWhile66)) )
              CHECK(259, List_add(self->_base.code_nodes, &(_SyntaxTreeWhile66->_base)) )
              
            }
            else {
              Bool _Bool67;
              CHECK(262, String_equal(keyword, &(String){9, 8, "continue"}, &(_Bool67)) )
              if (_Bool67) {
                if ((*end) != '\n') {
                  CHECK(264, f_syntax_error_c(&(String){40, 39, "expected new-line after \"continue\", got"}, (*end)) )
                }
                SyntaxTreeContinue* _SyntaxTreeContinue68;
                CHECK(266, SyntaxTreeContinue_parse_new(NULL, self, &((*end)), &(_SyntaxTreeContinue68)) )
                CHECK(266, List_add(self->_base.code_nodes, &(_SyntaxTreeContinue68->_base)) )
                
              }
              else {
                Bool _Bool69;
                CHECK(269, String_equal(keyword, &(String){7, 6, "return"}, &(_Bool69)) )
                if (_Bool69) {
                  if ((*end) != '\n') {
                    CHECK(271, f_syntax_error_c(&(String){38, 37, "expected new-line after \"return\", got"}, (*end)) )
                  }
                  SyntaxTreeReturn* _SyntaxTreeReturn70;
                  CHECK(273, SyntaxTreeReturn_parse_new(NULL, self, &((*end)), &(_SyntaxTreeReturn70)) )
                  CHECK(273, List_add(self->_base.code_nodes, &(_SyntaxTreeReturn70->_base)) )
                  
                }
                else {
                  Bool _Bool71;
                  CHECK(276, String_equal(keyword, &(String){6, 5, "raise"}, &(_Bool71)) )
                  if (_Bool71) {
                    if ((*end) != '\n') {
                      CHECK(278, f_syntax_error_c(&(String){37, 36, "expected new-line after \"raise\", got"}, (*end)) )
                    }
                    SyntaxTreeRaise* _SyntaxTreeRaise72;
                    CHECK(280, SyntaxTreeRaise_parse_new(NULL, self, &((*end)), &(_SyntaxTreeRaise72)) )
                    CHECK(280, List_add(self->_base.code_nodes, &(_SyntaxTreeRaise72->_base)) )
                    
                  }
                  else {
                    Bool _Bool73;
                    CHECK(283, String_equal(keyword, &(String){4, 3, "new"}, &(_Bool73)) )
                    if (_Bool73) {
                      if ((*end) != ' ') {
                        CHECK(285, f_syntax_error_c(&(String){32, 31, "expected space after \"new\", got"}, (*end)) )
                      }
                      CHECK(286, SyntaxTreeBranch_add_variable(&(self->_base), NULL, ACCESS_OWNER, &((*end))) )
                      
                    }
                    else {
                      glob->save_input = true;
                      SyntaxTreeExpression* _SyntaxTreeExpression74;
                      CHECK(290, SyntaxTreeExpression_parse_new(NULL, self, &((*end)), &(_SyntaxTreeExpression74)) )
                      CHECK(290, List_add(self->_base.code_nodes, &(_SyntaxTreeExpression74->_base)) )
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
Returncode SyntaxTreeBlock_m_find_variable(SyntaxTreeBlock* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_m_find_variable = "SyntaxTreeBlock.m-find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_m_find_variable
Returncode SyntaxTreeBlock_m_find_variable(SyntaxTreeBlock* self, String* name, SyntaxTreeVariable** variable) {
  CHECK(296, SyntaxTreeBranch_m_find_variable(&(self->_base), name, &((*variable))) )
  if (!(NULL != (*variable)) &&  NULL !=  self->parent) {
    CHECK(298, SyntaxTreeBlock_m_find_variable(self->parent, name, &((*variable))) )
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
  CHECK(301, (self->parent)->_base._base._dtl[3](self->parent, &((*parent_type))) )
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
    if (type_count == NULL) RAISE(315)
    *type_count = (TypeCount){NULL, 0};
    type_count->type_data = type_instance->type_data;
    CHECK(317, List_add(self->aux_variables, type_count) )
  }
  SyntaxTreeVariable* variable = malloc(sizeof(SyntaxTreeVariable));
  if (variable == NULL) RAISE(318)
  *variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, NULL, 0, NULL, NULL};
  variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  variable->name = _new_string(type_instance->type_data->name->length + 21);
  if (variable->name == NULL) RAISE(319)
  CHECK(321, String_copy(variable->name, &(String){5, 4, "aux_"}) )
  CHECK(322, String_concat(variable->name, type_instance->type_data->name) )
  CHECK(323, String_append(variable->name, '_') )
  String* index_str = &(String){16, 0, (char[16]){0}};
  CHECK(325, Int_str(index, index_str) )
  CHECK(326, String_concat(variable->name, index_str) )
  variable->_base.parent = self;
  if (access == ACCESS_COPY) {
    variable->access = ACCESS_VAR;
  }
  else {
    variable->access = access;
  }
  CHECK(332, TypeInstance_m_copy_new(type_instance, &(variable->type_instance)) )
  (*new_variable) = variable;
  CHECK(334, List_add(self->_base.variables, variable) )
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
  CHECK(340, write(&(String){4, 3, " {\n"}) )
  CHECK(341, SyntaxTreeBranch_write(&(self->_base)) )
  CHECK(342, SyntaxTreeBranch_write_children(&(self->_base), self->_base.code_nodes) )
  CHECK(343, write_spaces(self->_base.indentation_spaces - 2) )
  CHECK(344, write(&(String){2, 1, "}"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBlock__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBlock__dtl[] = {(void*)SyntaxTreeBranch_analyze, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeBlock_m_get_parent_type};
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
