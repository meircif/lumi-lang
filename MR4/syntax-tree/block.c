#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/block.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file13_name = "syntax-tree/block.3.mr";
#endif
#define MR_FILE_NAME _mr_file13_name

/* MR4 compiler - Syntax tree code block */


/* A basic code node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeCode SyntaxTreeCode;
#elif MR_STAGE == MR_TYPES(1)
struct SyntaxTreeCode {
  SyntaxTreeNode _base;
  SyntaxTreeBlock* parent;
/* Read and check indentation spaces for a line break from the input file */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCode_m_find_variable(SyntaxTreeCode* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCode_m_find_variable = "SyntaxTreeCode.m-find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeCode_m_find_variable
Returncode SyntaxTreeCode_m_find_variable(SyntaxTreeCode* self, String* name, SyntaxTreeVariable** variable) {
  CHECK(9, (self->parent)->_base._base._dtl[4](self->parent, name, &((*variable))) )
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
  CHECK(12, (self->parent)->_base._base._dtl[5](self->parent, &((*parent_type))) )
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
  CHECK(15, SyntaxTreeBranch_write_spaces(&(self->parent->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif/* Read and check indentation spaces for a line break from the input file */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCode_read_line_break_spaces(SyntaxTreeCode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCode_read_line_break_spaces = "SyntaxTreeCode.read-line-break-spaces";
#define MR_FUNC_NAME _func_name_SyntaxTreeCode_read_line_break_spaces
Returncode SyntaxTreeCode_read_line_break_spaces(SyntaxTreeCode* self) {
  Int expected_spaces = self->parent->_base.indentation_spaces + 4;
  {int n; for (n = (0); n < (expected_spaces); ++n) {
    Char _Char32;
    CHECK(21, read_c(&(_Char32)) )
    if (_Char32 != ' ') {
      String* expected_spaces_str = &(String){16, 0, (char[16]){0}};
      String* actual_spaces_str = &(String){16, 0, (char[16]){0}};
      CHECK(24, Int_str(expected_spaces, expected_spaces_str) )
      CHECK(25, Int_str(n - 1, actual_spaces_str) )
      CHECK(26, SyntaxTreeNode_m_syntax_error2(&(self->_base), &(String){32, 31, "too short indentation, expected"}, expected_spaces_str, &(String){4, 3, "got"}, actual_spaces_str) )
    }
  }}
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
Func SyntaxTreeCode__dtl[] = {(void*)SyntaxTreeNode_m_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write, (void*)SyntaxTreeCode_m_is_end_point};
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
  if (self->code_nodes == NULL) RAISE(52)
  *self->code_nodes = (List){NULL, NULL};
  CHECK(53, SyntaxTreeBranch_parse_block_children(&(self->_base), NULL, self, &((*end))) )
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
  
  Bool _Bool33;
  CHECK(59, SyntaxTreeBlock_m_has_end_point(self, &(_Bool33)) )
  if (_Bool33) {
    CHECK(60, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){17, 16, "unreachable code"}) )
  }
  
  Bool _Bool34;
  CHECK(62, String_equal(keyword, &(String){3, 2, "if"}, &(_Bool34)) )
  if (_Bool34) {
    if ((*end) != ' ') {
      CHECK(64, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after \"if\", got"}, (*end)) )
    }
    CHECK(65, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
    CHECK(66, List_add(self->code_nodes, &(new_if->_base._base)) )
    
  }
  else {
    Bool _Bool35;
    CHECK(68, String_equal(keyword, &(String){5, 4, "else"}, &(_Bool35)) )
    if (_Bool35) {
      if (!(NULL != self->previous_if)) {
        CHECK(70, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){31, 30, "\"else\" without a previous \"if\""}) )
      }
      if ((*end) != '\n') {
        CHECK(72, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected new-line after \"else\", got"}, (*end)) )
      }
      SyntaxTreeElse* _SyntaxTreeElse36;
      CHECK(74, SyntaxTreeElse_parse_new(NULL, self, &((*end)), &(_SyntaxTreeElse36)) )
      CHECK(74, SyntaxTreeIf_add_else(self->previous_if, _SyntaxTreeElse36) )
      
    }
    else {
      Bool _Bool37;
      CHECK(77, String_equal(keyword, &(String){8, 7, "else-if"}, &(_Bool37)) )
      if (_Bool37) {
        if (!(NULL != self->previous_if)) {
          CHECK(79, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){34, 33, "\"else-if\" without a previous \"if\""}) )
        }
        if ((*end) != ' ') {
          CHECK(81, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected space after \"else-if\", got"}, (*end)) )
        }
        CHECK(83, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
        CHECK(84, SyntaxTreeIf_add_else_if(self->previous_if, new_if) )
        
      }
      else {
        Bool _Bool38;
        CHECK(86, String_equal(keyword, &(String){3, 2, "do"}, &(_Bool38)) )
        if (_Bool38) {
          if ((*end) != '\n') {
            CHECK(88, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected new-line after \"do\", got"}, (*end)) )
          }
          SyntaxTreeDoLoop* _SyntaxTreeDoLoop39;
          CHECK(90, SyntaxTreeDoLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeDoLoop39)) )
          CHECK(90, List_add(self->code_nodes, &(_SyntaxTreeDoLoop39->_base._base)) )
          
        }
        else {
          Bool _Bool40;
          CHECK(93, String_equal(keyword, &(String){4, 3, "for"}, &(_Bool40)) )
          if (_Bool40) {
            if ((*end) != ' ') {
              CHECK(95, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"for\", got"}, (*end)) )
            }
            SyntaxTreeForLoop* _SyntaxTreeForLoop41;
            CHECK(97, SyntaxTreeForLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeForLoop41)) )
            CHECK(97, List_add(self->code_nodes, &(_SyntaxTreeForLoop41->_base._base)) )
            
          }
          else {
            Bool _Bool42;
            CHECK(100, String_equal(keyword, &(String){6, 5, "while"}, &(_Bool42)) )
            if (_Bool42) {
              if ((*end) != ' ') {
                CHECK(102, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected space after \"while\", got"}, (*end)) )
              }
              SyntaxTreeWhile* _SyntaxTreeWhile43;
              CHECK(104, SyntaxTreeWhile_parse_new(NULL, self, &((*end)), &(_SyntaxTreeWhile43)) )
              CHECK(104, List_add(self->code_nodes, &(_SyntaxTreeWhile43->_base)) )
              
            }
            else {
              Bool _Bool44;
              CHECK(107, String_equal(keyword, &(String){9, 8, "continue"}, &(_Bool44)) )
              if (_Bool44) {
                if ((*end) != '\n') {
                  CHECK(109, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){40, 39, "expected new-line after \"continue\", got"}, (*end)) )
                }
                SyntaxTreeContinue* _SyntaxTreeContinue45;
                CHECK(111, SyntaxTreeContinue_parse_new(NULL, self, &((*end)), &(_SyntaxTreeContinue45)) )
                CHECK(111, List_add(self->code_nodes, &(_SyntaxTreeContinue45->_base)) )
                
              }
              else {
                Bool _Bool46;
                CHECK(114, String_equal(keyword, &(String){7, 6, "return"}, &(_Bool46)) )
                if (_Bool46) {
                  if ((*end) != '\n') {
                    CHECK(116, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){38, 37, "expected new-line after \"return\", got"}, (*end)) )
                  }
                  SyntaxTreeReturn* _SyntaxTreeReturn47;
                  CHECK(118, SyntaxTreeReturn_parse_new(NULL, self, &((*end)), &(_SyntaxTreeReturn47)) )
                  CHECK(118, List_add(self->code_nodes, &(_SyntaxTreeReturn47->_base)) )
                  
                }
                else {
                  Bool _Bool48;
                  CHECK(121, String_equal(keyword, &(String){6, 5, "raise"}, &(_Bool48)) )
                  if (_Bool48) {
                    if ((*end) != '\n') {
                      CHECK(123, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){37, 36, "expected new-line after \"raise\", got"}, (*end)) )
                    }
                    SyntaxTreeRaise* _SyntaxTreeRaise49;
                    CHECK(125, SyntaxTreeRaise_parse_new(NULL, self, &((*end)), &(_SyntaxTreeRaise49)) )
                    CHECK(125, List_add(self->code_nodes, &(_SyntaxTreeRaise49->_base)) )
                    
                  }
                  else {
                    Bool _Bool50;
                    CHECK(128, String_equal(keyword, &(String){4, 3, "new"}, &(_Bool50)) )
                    if (_Bool50) {
                      if ((*end) != ' ') {
                        CHECK(130, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"new\", got"}, (*end)) )
                      }
                      SyntaxTreeVariable* _SyntaxTreeVariable51;
                      CHECK(132, SyntaxTreeInitNew_parse_new(NULL, self, &((*end)), &(_SyntaxTreeVariable51)) )
                      CHECK(132, List_add(self->_base.variables, _SyntaxTreeVariable51) )
                      
                    }
                    else {
                      Bool _Bool52;
                      CHECK(135, String_equal(keyword, &(String){7, 6, "assert"}, &(_Bool52)) )
                      if (_Bool52) {
                        if ((*end) != ' ') {
                          CHECK(137, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){35, 34, "expected space after \"assert\", got"}, (*end)) )
                        }
                        SyntaxTreeAssert* _SyntaxTreeAssert53;
                        CHECK(139, SyntaxTreeAssert_parse_new(NULL, self, &((*end)), &(_SyntaxTreeAssert53)) )
                        CHECK(139, List_add(self->code_nodes, &(_SyntaxTreeAssert53->_base)) )
                        
                      }
                      else {
                        Bool _Bool54;
                        CHECK(142, String_equal(keyword, &(String){13, 12, "assert-error"}, &(_Bool54)) )
                        if (_Bool54) {
                          if ((*end) != ' ') {
                            CHECK(144, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){41, 40, "expected space after \"assert-error\", got"}, (*end)) )
                          }
                          SyntaxTreeAssertError* _SyntaxTreeAssertError55;
                          CHECK(146, SyntaxTreeAssertError_parse_new(NULL, self, &((*end)), &(_SyntaxTreeAssertError55)) )
                          CHECK(146, List_add(self->code_nodes, &(_SyntaxTreeAssertError55->_base)) )
                          
                        }
                        else {
                          glob->save_input = true;
                          SyntaxTreeExpression* _SyntaxTreeExpression56;
                          CHECK(151, SyntaxTreeExpression_parse_new(NULL, self, &((*end)), &(_SyntaxTreeExpression56)) )
                          CHECK(151, List_add(self->code_nodes, &(_SyntaxTreeExpression56->_base)) )
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
    CHECK(158, (((SyntaxTreeCode*)(self->code_nodes->last->item)))->_base._dtl[3](((SyntaxTreeCode*)(self->code_nodes->last->item)), &((*has_end))) )
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
  CHECK(164, SyntaxTreeBranch_m_find_variable(&(self->_base), name, &((*variable))) )
  if (!(NULL != (*variable)) &&  NULL !=  self->ref_variable) {
    Bool _Bool57;
    CHECK(166, SyntaxTreeVariable_m_find_variable(self->ref_variable, name, &((*variable)), &(_Bool57)) )
  }
  if (!(NULL != (*variable)) &&  NULL !=  self->parent) {
    CHECK(168, (self->parent)->_base._base._dtl[4](self->parent, name, &((*variable))) )
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
  CHECK(171, (self->parent)->_base._base._dtl[5](self->parent, &((*parent_type))) )
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
    if (type_count == NULL) RAISE(185)
    *type_count = (TypeCount){NULL, 0};
    type_count->type_data = type_instance->type_data;
    CHECK(187, List_add(self->aux_variables, type_count) )
  }
  SyntaxTreeVariable* variable = malloc(sizeof(SyntaxTreeVariable));
  if (variable == NULL) RAISE(188)
  *variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false};
  variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  variable->name = _new_string(type_instance->type_data->name->length + 21);
  if (variable->name == NULL) RAISE(189)
  CHECK(191, String_copy(variable->name, &(String){5, 4, "aux_"}) )
  CHECK(192, String_concat(variable->name, type_instance->type_data->name) )
  CHECK(193, String_append(variable->name, '_') )
  String* index_str = &(String){16, 0, (char[16]){0}};
  CHECK(195, Int_str(index, index_str) )
  CHECK(196, String_concat(variable->name, index_str) )
  variable->_base.parent = self;
  if (access == ACCESS_COPY) {
    variable->access = ACCESS_VAR;
  }
  else {
    variable->access = access;
  }
  CHECK(202, TypeInstance_m_copy_new(type_instance, &(variable->type_instance)) )
  (*new_variable) = variable;
  CHECK(204, List_add(self->_base.variables, variable) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_m_link_types(SyntaxTreeBlock* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_m_link_types = "SyntaxTreeBlock.m-link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_m_link_types
Returncode SyntaxTreeBlock_m_link_types(SyntaxTreeBlock* self) {
  CHECK(207, SyntaxTreeBranch_m_link_types(&(self->_base)) )
  CHECK(208, SyntaxTreeNode_m_link_children_types(&(self->_base._base), self->code_nodes) )
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
  CHECK(211, SyntaxTreeBranch_analyze(&(self->_base)) )
  CHECK(212, SyntaxTreeNode_analyze_children(&(self->_base._base), self->code_nodes) )
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
  CHECK(218, write(&(String){4, 3, " {\n"}) )
  CHECK(219, SyntaxTreeBranch_write(&(self->_base)) )
  CHECK(220, SyntaxTreeNode_write_children(&(self->_base._base), self->code_nodes) )
  CHECK(221, write_spaces(self->_base.indentation_spaces - 2) )
  CHECK(222, write(&(String){3, 2, "}\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBlock__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBlock__dtl[] = {(void*)SyntaxTreeBlock_m_link_types, (void*)SyntaxTreeBlock_analyze, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeBlock_m_find_variable, (void*)SyntaxTreeBlock_m_get_parent_type};
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
