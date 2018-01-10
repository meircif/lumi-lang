#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/block.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file16_name = "syntax-tree/block.3.mr";
#endif
#define MR_FILE_NAME _mr_file16_name

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
Returncode SyntaxTreeCode_find_variable(SyntaxTreeCode* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCode_find_variable = "SyntaxTreeCode.find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeCode_find_variable
Returncode SyntaxTreeCode_find_variable(SyntaxTreeCode* self, String* name, SyntaxTreeVariable** variable) {
  CHECK(9, (self->parent)->_base._base._dtl[5](self->parent, name, &((*variable))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCode_get_function(SyntaxTreeCode* self, SyntaxTreeFunction** function);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCode_get_function = "SyntaxTreeCode.get-function";
#define MR_FUNC_NAME _func_name_SyntaxTreeCode_get_function
Returncode SyntaxTreeCode_get_function(SyntaxTreeCode* self, SyntaxTreeFunction** function) {
  CHECK(12, (self->parent)->_base._base._dtl[6](self->parent, &((*function))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCode_get_parent_type(SyntaxTreeCode* self, TypeData** parent_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCode_get_parent_type = "SyntaxTreeCode.get-parent-type";
#define MR_FUNC_NAME _func_name_SyntaxTreeCode_get_parent_type
Returncode SyntaxTreeCode_get_parent_type(SyntaxTreeCode* self, TypeData** parent_type) {
  SyntaxTreeFunction* _SyntaxTreeFunction44;
  CHECK(15, SyntaxTreeCode_get_function(self, &(_SyntaxTreeFunction44)) )
  (*parent_type) = _SyntaxTreeFunction44->parent_type;
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
  CHECK(18, SyntaxTreeBranch_write_spaces(&(self->parent->_base)) )
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
    Char _Char45;
    CHECK(24, read_c(&(_Char45)) )
    if (_Char45 != ' ') {
      String* expected_spaces_str = &(String){16, 0, (char[16]){0}};
      String* actual_spaces_str = &(String){16, 0, (char[16]){0}};
      CHECK(27, Int_str(expected_spaces, expected_spaces_str) )
      CHECK(28, Int_str(n, actual_spaces_str) )
      CHECK(29, SyntaxTreeNode_m_syntax_error2(&(self->_base), &(String){32, 31, "too short indentation, expected"}, expected_spaces_str, &(String){4, 3, "got"}, actual_spaces_str) )
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
Func SyntaxTreeCode__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* A basic code block node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeBlock SyntaxTreeBlock;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeBlock {
  SyntaxTreeBranch _base;
  SyntaxTreeBlock* parent;
  List* code_nodes;
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
  if (self->code_nodes == NULL) RAISE(48)
  *self->code_nodes = (List){NULL, NULL};
  CHECK(49, SyntaxTreeBranch_parse_block_children(&(self->_base), NULL, self, &((*end))) )
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
  
  Bool _Bool46;
  CHECK(55, SyntaxTreeBlock_m_has_end_point(self, &(_Bool46)) )
  if (_Bool46) {
    CHECK(56, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){17, 16, "unreachable code"}) )
  }
  
  Bool _Bool47;
  CHECK(58, String_equal(keyword, &(String){3, 2, "if"}, &(_Bool47)) )
  if (_Bool47) {
    if ((*end) != ' ') {
      CHECK(60, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after \"if\", got"}, (*end)) )
    }
    CHECK(61, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
    CHECK(62, List_add(self->code_nodes, &(new_if->_base._base)) )
    
  }
  else {
    Bool _Bool48;
    CHECK(64, String_equal(keyword, &(String){5, 4, "else"}, &(_Bool48)) )
    if (_Bool48) {
      if (!(NULL != self->previous_if)) {
        CHECK(66, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){31, 30, "\"else\" without a previous \"if\""}) )
      }
      if ((*end) != '\n') {
        CHECK(68, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected new-line after \"else\", got"}, (*end)) )
      }
      SyntaxTreeElse* _SyntaxTreeElse49;
      CHECK(70, SyntaxTreeElse_parse_new(NULL, self, &((*end)), &(_SyntaxTreeElse49)) )
      CHECK(70, SyntaxTreeIf_add_else(self->previous_if, _SyntaxTreeElse49) )
      
    }
    else {
      Bool _Bool50;
      CHECK(73, String_equal(keyword, &(String){8, 7, "else-if"}, &(_Bool50)) )
      if (_Bool50) {
        if (!(NULL != self->previous_if)) {
          CHECK(75, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){34, 33, "\"else-if\" without a previous \"if\""}) )
        }
        if ((*end) != ' ') {
          CHECK(77, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected space after \"else-if\", got"}, (*end)) )
        }
        CHECK(79, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
        CHECK(80, SyntaxTreeIf_add_else_if(self->previous_if, new_if) )
        
      }
      else {
        Bool _Bool51;
        CHECK(82, String_equal(keyword, &(String){3, 2, "do"}, &(_Bool51)) )
        if (_Bool51) {
          if ((*end) != '\n') {
            CHECK(84, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected new-line after \"do\", got"}, (*end)) )
          }
          SyntaxTreeDoLoop* _SyntaxTreeDoLoop52;
          CHECK(86, SyntaxTreeDoLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeDoLoop52)) )
          CHECK(86, List_add(self->code_nodes, &(_SyntaxTreeDoLoop52->_base._base)) )
          
        }
        else {
          Bool _Bool53;
          CHECK(89, String_equal(keyword, &(String){4, 3, "for"}, &(_Bool53)) )
          if (_Bool53) {
            if ((*end) != ' ') {
              CHECK(91, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"for\", got"}, (*end)) )
            }
            SyntaxTreeForLoop* _SyntaxTreeForLoop54;
            CHECK(93, SyntaxTreeForLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeForLoop54)) )
            CHECK(93, List_add(self->code_nodes, &(_SyntaxTreeForLoop54->_base._base)) )
            
          }
          else {
            Bool _Bool55;
            CHECK(96, String_equal(keyword, &(String){6, 5, "while"}, &(_Bool55)) )
            if (_Bool55) {
              if ((*end) != ' ') {
                CHECK(98, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected space after \"while\", got"}, (*end)) )
              }
              SyntaxTreeWhile* _SyntaxTreeWhile56;
              CHECK(100, SyntaxTreeWhile_parse_new(NULL, self, &((*end)), &(_SyntaxTreeWhile56)) )
              CHECK(100, List_add(self->code_nodes, &(_SyntaxTreeWhile56->_base)) )
              
            }
            else {
              Bool _Bool57;
              CHECK(103, String_equal(keyword, &(String){9, 8, "continue"}, &(_Bool57)) )
              if (_Bool57) {
                if ((*end) != '\n') {
                  CHECK(105, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){40, 39, "expected new-line after \"continue\", got"}, (*end)) )
                }
                SyntaxTreeContinue* _SyntaxTreeContinue58;
                CHECK(107, SyntaxTreeContinue_parse_new(NULL, self, &((*end)), &(_SyntaxTreeContinue58)) )
                CHECK(107, List_add(self->code_nodes, &(_SyntaxTreeContinue58->_base)) )
                
              }
              else {
                Bool _Bool59;
                CHECK(110, String_equal(keyword, &(String){7, 6, "return"}, &(_Bool59)) )
                if (_Bool59) {
                  if ((*end) != '\n') {
                    CHECK(112, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){38, 37, "expected new-line after \"return\", got"}, (*end)) )
                  }
                  SyntaxTreeReturn* _SyntaxTreeReturn60;
                  CHECK(114, SyntaxTreeReturn_parse_new(NULL, self, &((*end)), &(_SyntaxTreeReturn60)) )
                  CHECK(114, List_add(self->code_nodes, &(_SyntaxTreeReturn60->_base)) )
                  
                }
                else {
                  Bool _Bool61;
                  CHECK(117, String_equal(keyword, &(String){6, 5, "raise"}, &(_Bool61)) )
                  if (_Bool61) {
                    if ((*end) != '\n') {
                      CHECK(119, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){37, 36, "expected new-line after \"raise\", got"}, (*end)) )
                    }
                    SyntaxTreeRaise* _SyntaxTreeRaise62;
                    CHECK(121, SyntaxTreeRaise_parse_new(NULL, self, &((*end)), &(_SyntaxTreeRaise62)) )
                    CHECK(121, List_add(self->code_nodes, &(_SyntaxTreeRaise62->_base)) )
                    
                  }
                  else {
                    Bool _Bool63;
                    CHECK(124, String_equal(keyword, &(String){4, 3, "new"}, &(_Bool63)) )
                    if (_Bool63) {
                      if ((*end) != ' ') {
                        CHECK(126, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"new\", got"}, (*end)) )
                      }
                      SyntaxTreeFunction* _SyntaxTreeFunction64;
                      CHECK(128, (self)->_base._base._dtl[6](self, &(_SyntaxTreeFunction64)) )
                      SyntaxTreeVariable* _SyntaxTreeVariable65;
                      CHECK(128, SyntaxTreeVariable_parse_new(NULL, ACCESS_OWNER, true, NULL, self, &((*end)), &(_SyntaxTreeVariable65)) )
                      CHECK(128, List_add(_SyntaxTreeFunction64->_base._base.variables, _SyntaxTreeVariable65) )
                      
                    }
                    else {
                      Bool _Bool66;
                      CHECK(131, String_equal(keyword, &(String){7, 6, "assert"}, &(_Bool66)) )
                      if (_Bool66) {
                        if ((*end) != ' ') {
                          CHECK(133, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){35, 34, "expected space after \"assert\", got"}, (*end)) )
                        }
                        SyntaxTreeAssert* _SyntaxTreeAssert67;
                        CHECK(135, SyntaxTreeAssert_parse_new(NULL, self, &((*end)), &(_SyntaxTreeAssert67)) )
                        CHECK(135, List_add(self->code_nodes, &(_SyntaxTreeAssert67->_base)) )
                        
                      }
                      else {
                        Bool _Bool68;
                        CHECK(138, String_equal(keyword, &(String){13, 12, "assert-error"}, &(_Bool68)) )
                        if (_Bool68) {
                          if ((*end) != ' ') {
                            CHECK(140, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){41, 40, "expected space after \"assert-error\", got"}, (*end)) )
                          }
                          SyntaxTreeAssertError* _SyntaxTreeAssertError69;
                          CHECK(142, SyntaxTreeAssertError_parse_new(NULL, self, &((*end)), &(_SyntaxTreeAssertError69)) )
                          CHECK(142, List_add(self->code_nodes, &(_SyntaxTreeAssertError69->_base)) )
                          
                        }
                        else {
                          glob->save_input = true;
                          SyntaxTreeExpression* _SyntaxTreeExpression70;
                          CHECK(147, SyntaxTreeExpression_parse_new(NULL, self, &((*end)), &(_SyntaxTreeExpression70)) )
                          CHECK(147, List_add(self->code_nodes, &(_SyntaxTreeExpression70->_base)) )
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
    CHECK(154, (((SyntaxTreeCode*)(self->code_nodes->last->item)))->_base._dtl[4](((SyntaxTreeCode*)(self->code_nodes->last->item)), &((*has_end))) )
  }
  else {
    (*has_end) = false;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_find_variable(SyntaxTreeBlock* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_find_variable = "SyntaxTreeBlock.find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_find_variable
Returncode SyntaxTreeBlock_find_variable(SyntaxTreeBlock* self, String* name, SyntaxTreeVariable** variable) {
  CHECK(160, SyntaxTreeBranch_find_variable(&(self->_base), name, &((*variable))) )
  if (!(NULL != (*variable)) &&  NULL !=  self->ref_variable) {
    Bool _Bool71;
    CHECK(162, SyntaxTreeVariable_find_variable(self->ref_variable, name, &((*variable)), &(_Bool71)) )
  }
  if (!(NULL != (*variable)) &&  NULL !=  self->parent) {
    CHECK(164, (self->parent)->_base._base._dtl[5](self->parent, name, &((*variable))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_get_function(SyntaxTreeBlock* self, SyntaxTreeFunction** function);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_get_function = "SyntaxTreeBlock.get-function";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_get_function
Returncode SyntaxTreeBlock_get_function(SyntaxTreeBlock* self, SyntaxTreeFunction** function) {
  CHECK(167, (self->parent)->_base._base._dtl[6](self->parent, &((*function))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_link_types(SyntaxTreeBlock* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_link_types = "SyntaxTreeBlock.link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_link_types
Returncode SyntaxTreeBlock_link_types(SyntaxTreeBlock* self) {
  CHECK(170, SyntaxTreeBranch_link_types(&(self->_base)) )
  CHECK(171, SyntaxTreeNode_link_children_types(&(self->_base._base), self->code_nodes) )
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
  CHECK(174, SyntaxTreeBranch_analyze(&(self->_base)) )
  CHECK(175, SyntaxTreeNode_analyze_children(&(self->_base._base), self->code_nodes) )
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
  CHECK(181, SyntaxTreeBlock_write_block_start(self) )
  CHECK(182, SyntaxTreeNode_write_children(&(self->_base._base), self->code_nodes) )
  CHECK(183, SyntaxTreeBlock_write_block_end(self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_write_block_start(SyntaxTreeBlock* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_write_block_start = "SyntaxTreeBlock.write-block-start";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_write_block_start
Returncode SyntaxTreeBlock_write_block_start(SyntaxTreeBlock* self) {
  CHECK(186, write(&(String){4, 3, " {\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_write_block_end(SyntaxTreeBlock* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_write_block_end = "SyntaxTreeBlock.write-block-end";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_write_block_end
Returncode SyntaxTreeBlock_write_block_end(SyntaxTreeBlock* self) {
  CHECK(189, write_spaces(self->_base.indentation_spaces - 2) )
  CHECK(190, write(&(String){3, 2, "}\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBlock__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBlock__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeBlock_link_types, (void*)SyntaxTreeBlock_analyze, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeBlock_find_variable, (void*)SyntaxTreeBlock_get_function};
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
#include "global/type-instance.c"
#include "expression/base-type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/initialize.c"
#include "expression/slice.c"
#include "expression/symbol.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "statement/error.c"
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
#include "statement/type.c"
#include "statement/variable.c"
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
