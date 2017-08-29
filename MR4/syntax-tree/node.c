#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/node.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file16_name = "syntax-tree/node.3.mr";
#endif
#define MR_FILE_NAME _mr_file16_name

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
Returncode SyntaxTreeBranch_parse_block_children(SyntaxTreeBranch* self, SyntaxTreeType* parent_type, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_block_children = "SyntaxTreeBranch.parse-block-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_block_children
Returncode SyntaxTreeBranch_parse_block_children(SyntaxTreeBranch* self, SyntaxTreeType* parent_type, Char* end) {
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
Returncode SyntaxTreeBranch_parse_children(SyntaxTreeBranch* self, SyntaxTreeType* parent_type, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_children = "SyntaxTreeBranch.parse-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_children
Returncode SyntaxTreeBranch_parse_children(SyntaxTreeBranch* self, SyntaxTreeType* parent_type, Char* end) {
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
      
      Bool _Bool31;
      CHECK(55, SyntaxTreeBranch_parse_if_common(self, keyword, parent_type, &((*end)), &(_Bool31)) )
      if (!_Bool31) {
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
Returncode SyntaxTreeBranch_parse_if_common(SyntaxTreeBranch* self, String* keyword, SyntaxTreeType* parent_type, Char* end, Bool* is_parsed);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_if_common = "SyntaxTreeBranch.parse-if-common";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_if_common
Returncode SyntaxTreeBranch_parse_if_common(SyntaxTreeBranch* self, String* keyword, SyntaxTreeType* parent_type, Char* end, Bool* is_parsed) {
  (*is_parsed) = (*end) == ' ';
  if (!(*is_parsed)) {
    return OK;
  }
  
  Bool _Bool32;
  CHECK(70, String_equal(keyword, &(String){2, 1, "#"}, &(_Bool32)) )
  Bool _Bool33;
  CHECK(70, String_equal(keyword, &(String){3, 2, "##"}, &(_Bool33)) )
  if (_Bool32 || _Bool33) {
    String* text = NULL;
    Int _Int34;
    CHECK(72, read_until(&(String){1, 0, ""}, false, &(text), &((*end)), &(_Int34)) )
  }
  else {
    Bool _Bool35;
    CHECK(73, String_equal(keyword, &(String){3, 2, "{#"}, &(_Bool35)) )
    Bool _Bool36;
    CHECK(73, String_equal(keyword, &(String){4, 3, "{##"}, &(_Bool36)) )
    if (_Bool35 || _Bool36) {
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
      Bool _Bool37;
      CHECK(82, String_equal(keyword, &(String){4, 3, "var"}, &(_Bool37)) )
      if (_Bool37) {
        CHECK(83, SyntaxTreeBranch_add_variable(self, parent_type, ACCESS_VAR, &((*end))) )
      }
      else {
        Bool _Bool38;
        CHECK(84, String_equal(keyword, &(String){5, 4, "user"}, &(_Bool38)) )
        if (_Bool38) {
          CHECK(85, SyntaxTreeBranch_add_variable(self, parent_type, ACCESS_USER, &((*end))) )
        }
        else {
          Bool _Bool39;
          CHECK(86, String_equal(keyword, &(String){6, 5, "owner"}, &(_Bool39)) )
          if (_Bool39) {
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
Returncode SyntaxTreeBranch_add_variable(SyntaxTreeBranch* self, SyntaxTreeType* parent_type, Int access, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_add_variable = "SyntaxTreeBranch.add-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_add_variable
Returncode SyntaxTreeBranch_add_variable(SyntaxTreeBranch* self, SyntaxTreeType* parent_type, Int access, Char* end) {
  SyntaxTreeVariableInit* var_init = NULL;
  SyntaxTreeVariable* _SyntaxTreeVariable40;
  CHECK(95, SyntaxTreeVariable_parse_new(NULL, access, parent_type, &((*end)), &(var_init), &(_SyntaxTreeVariable40)) )
  CHECK(95, List_add(self->variables, _SyntaxTreeVariable40) )
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
  RAISE(102)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_write(SyntaxTreeBranch* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write = "SyntaxTreeBranch.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_write
Returncode SyntaxTreeBranch_write(SyntaxTreeBranch* self) {
  CHECK(105, SyntaxTreeBranch_write_children(self, self->variables) )
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
      CHECK(112, write_spaces(self->indentation_spaces) )
    }
    else {
      CHECK(114, write(&(String){2, 1, "\n"}) )
    }
    CHECK(115, (((SyntaxTreeNode*)(child->item)))->_dtl[1](((SyntaxTreeNode*)(child->item))) )
    CHECK(116, write(&(String){2, 1, "\n"}) )
    child = child->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBranch__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBranch__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBranch_parse_child};
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
  CHECK(125, SyntaxTreeBranch_init(&(self->_base)) )
  self->functions = malloc(sizeof(List));
  if (self->functions == NULL) RAISE(126)
  *self->functions = (List){NULL, NULL};
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_parse_if_function(SyntaxTreeNamespace* self, String* keyword, SyntaxTreeType* parent_type, Char* end, Bool* is_func);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_parse_if_function = "SyntaxTreeNamespace.parse-if-function";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_parse_if_function
Returncode SyntaxTreeNamespace_parse_if_function(SyntaxTreeNamespace* self, String* keyword, SyntaxTreeType* parent_type, Char* end, Bool* is_func) {
  CHECK(131, String_equal(keyword, &(String){5, 4, "func"}, &((*is_func))) )
  if ((*is_func)) {
    if ((*end) != ' ') {
      CHECK(134, f_syntax_error_c(&(String){33, 32, "expected space after \"func\", got"}, (*end)) )
    }
    SyntaxTreeFunction* _SyntaxTreeFunction41;
    CHECK(135, SyntaxTreeFunction_parse_new(NULL, parent_type, &((*end)), &(_SyntaxTreeFunction41)) )
    CHECK(135, List_add(self->functions, _SyntaxTreeFunction41) )
  }
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
  CHECK(139, SyntaxTreeBranch_write(&(self->_base)) )
  CHECK(140, SyntaxTreeBranch_write_children(&(self->_base), self->functions) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeNamespace__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeNamespace__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNamespace_write, (void*)SyntaxTreeBranch_parse_child};
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
  CHECK(160, SyntaxTreeBranch_parse_block_children(&(self->_base), NULL, &((*end))) )
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
  
  Bool _Bool42;
  CHECK(166, String_equal(keyword, &(String){3, 2, "if"}, &(_Bool42)) )
  if (_Bool42) {
    if ((*end) != ' ') {
      CHECK(168, f_syntax_error_c(&(String){31, 30, "expected space after \"if\", got"}, (*end)) )
    }
    CHECK(169, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
    CHECK(170, List_add(self->_base.code_nodes, &(new_if->_base._base)) )
    
  }
  else {
    Bool _Bool43;
    CHECK(172, String_equal(keyword, &(String){5, 4, "else"}, &(_Bool43)) )
    if (_Bool43) {
      if (!(NULL != self->previous_if)) {
        CHECK(174, f_syntax_error_msg(&(String){31, 30, "\"else\" without a previous \"if\""}) )
      }
      if ((*end) != '\n') {
        CHECK(176, f_syntax_error_c(&(String){36, 35, "expected new-line after \"else\", got"}, (*end)) )
      }
      SyntaxTreeElse* _SyntaxTreeElse44;
      CHECK(177, SyntaxTreeElse_parse_new(NULL, self, &((*end)), &(_SyntaxTreeElse44)) )
      CHECK(177, SyntaxTreeIf_add_else(self->previous_if, _SyntaxTreeElse44) )
      
    }
    else {
      Bool _Bool45;
      CHECK(180, String_equal(keyword, &(String){8, 7, "else-if"}, &(_Bool45)) )
      if (_Bool45) {
        if (!(NULL != self->previous_if)) {
          CHECK(182, f_syntax_error_msg(&(String){34, 33, "\"else-if\" without a previous \"if\""}) )
        }
        if ((*end) != ' ') {
          CHECK(184, f_syntax_error_c(&(String){36, 35, "expected space after \"else-if\", got"}, (*end)) )
        }
        CHECK(185, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
        CHECK(186, SyntaxTreeIf_add_else_if(self->previous_if, new_if) )
        
      }
      else {
        Bool _Bool46;
        CHECK(188, String_equal(keyword, &(String){3, 2, "do"}, &(_Bool46)) )
        if (_Bool46) {
          if ((*end) != '\n') {
            CHECK(190, f_syntax_error_c(&(String){34, 33, "expected new-line after \"do\", got"}, (*end)) )
          }
          SyntaxTreeDoLoop* _SyntaxTreeDoLoop47;
          CHECK(191, SyntaxTreeDoLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeDoLoop47)) )
          CHECK(191, List_add(self->_base.code_nodes, &(_SyntaxTreeDoLoop47->_base._base)) )
          
        }
        else {
          Bool _Bool48;
          CHECK(194, String_equal(keyword, &(String){4, 3, "for"}, &(_Bool48)) )
          if (_Bool48) {
            if ((*end) != ' ') {
              CHECK(196, f_syntax_error_c(&(String){32, 31, "expected space after \"for\", got"}, (*end)) )
            }
            SyntaxTreeForLoop* _SyntaxTreeForLoop49;
            CHECK(197, SyntaxTreeForLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeForLoop49)) )
            CHECK(197, List_add(self->_base.code_nodes, &(_SyntaxTreeForLoop49->_base._base)) )
            
          }
          else {
            Bool _Bool50;
            CHECK(200, String_equal(keyword, &(String){6, 5, "while"}, &(_Bool50)) )
            if (_Bool50) {
              if ((*end) != ' ') {
                CHECK(202, f_syntax_error_c(&(String){34, 33, "expected space after \"while\", got"}, (*end)) )
              }
              SyntaxTreeWhile* _SyntaxTreeWhile51;
              CHECK(203, SyntaxTreeWhile_parse_new(NULL, self, &((*end)), &(_SyntaxTreeWhile51)) )
              CHECK(203, List_add(self->_base.code_nodes, &(_SyntaxTreeWhile51->_base)) )
              
            }
            else {
              Bool _Bool52;
              CHECK(206, String_equal(keyword, &(String){9, 8, "continue"}, &(_Bool52)) )
              if (_Bool52) {
                if ((*end) != '\n') {
                  CHECK(208, f_syntax_error_c(&(String){40, 39, "expected new-line after \"continue\", got"}, (*end)) )
                }
                SyntaxTreeContinue* _SyntaxTreeContinue53;
                CHECK(210, SyntaxTreeContinue_parse_new(NULL, self, &((*end)), &(_SyntaxTreeContinue53)) )
                CHECK(210, List_add(self->_base.code_nodes, &(_SyntaxTreeContinue53->_base)) )
                
              }
              else {
                Bool _Bool54;
                CHECK(213, String_equal(keyword, &(String){7, 6, "return"}, &(_Bool54)) )
                if (_Bool54) {
                  if ((*end) != '\n') {
                    CHECK(215, f_syntax_error_c(&(String){38, 37, "expected new-line after \"return\", got"}, (*end)) )
                  }
                  SyntaxTreeReturn* _SyntaxTreeReturn55;
                  CHECK(217, SyntaxTreeReturn_parse_new(NULL, self, &((*end)), &(_SyntaxTreeReturn55)) )
                  CHECK(217, List_add(self->_base.code_nodes, &(_SyntaxTreeReturn55->_base)) )
                  
                }
                else {
                  Bool _Bool56;
                  CHECK(220, String_equal(keyword, &(String){6, 5, "raise"}, &(_Bool56)) )
                  if (_Bool56) {
                    if ((*end) != '\n') {
                      CHECK(222, f_syntax_error_c(&(String){37, 36, "expected new-line after \"raise\", got"}, (*end)) )
                    }
                    SyntaxTreeRaise* _SyntaxTreeRaise57;
                    CHECK(224, SyntaxTreeRaise_parse_new(NULL, self, &((*end)), &(_SyntaxTreeRaise57)) )
                    CHECK(224, List_add(self->_base.code_nodes, &(_SyntaxTreeRaise57->_base)) )
                    
                  }
                  else {
                    Bool _Bool58;
                    CHECK(227, String_equal(keyword, &(String){4, 3, "new"}, &(_Bool58)) )
                    if (_Bool58) {
                      if ((*end) != ' ') {
                        CHECK(229, f_syntax_error_c(&(String){32, 31, "expected space after \"new\", got"}, (*end)) )
                      }
                      CHECK(230, SyntaxTreeBranch_add_variable(&(self->_base), NULL, ACCESS_OWNER, &((*end))) )
                      
                    }
                    else {
                      glob->save_input = true;
                      SyntaxTreeExpression* _SyntaxTreeExpression59;
                      CHECK(234, SyntaxTreeExpression_parse_new(NULL, self, &((*end)), &(_SyntaxTreeExpression59)) )
                      CHECK(234, List_add(self->_base.code_nodes, &(_SyntaxTreeExpression59->_base)) )
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
Returncode SyntaxTreeBlock_write_block(SyntaxTreeBlock* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_write_block = "SyntaxTreeBlock.write-block";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_write_block
Returncode SyntaxTreeBlock_write_block(SyntaxTreeBlock* self) {
  /* `previous-text` { */
  /*   `block...` */
  /* } */
  CHECK(243, write(&(String){4, 3, " {\n"}) )
  CHECK(244, SyntaxTreeBranch_write(&(self->_base)) )
  CHECK(245, SyntaxTreeBranch_write_children(&(self->_base), self->_base.code_nodes) )
  CHECK(246, write_spaces(self->_base.indentation_spaces - 2) )
  CHECK(247, write(&(String){2, 1, "}"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBlock__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBlock__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBlock_parse_child};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "global/type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/variable.c"
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
