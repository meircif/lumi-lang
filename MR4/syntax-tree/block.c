#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/block.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file15_name = "syntax-tree/block.3.mr";
#endif
#define MR_FILE_NAME _mr_file15_name

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
  CHECK(9, (self->parent)->_base._base._dtl[4](self->parent, name, &((*variable))) )
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
  CHECK(12, (self->parent)->_base._base._dtl[5](self->parent, &((*function))) )
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
    Char _Char35;
    CHECK(21, read_c(&(_Char35)) )
    if (_Char35 != ' ') {
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
Func SyntaxTreeCode__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write, (void*)SyntaxTreeCode_m_is_end_point};
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
  if (self->code_nodes == NULL) RAISE(45)
  *self->code_nodes = (List){NULL, NULL};
  CHECK(46, SyntaxTreeBranch_parse_block_children(&(self->_base), NULL, self, &((*end))) )
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
  
  Bool _Bool36;
  CHECK(52, SyntaxTreeBlock_m_has_end_point(self, &(_Bool36)) )
  if (_Bool36) {
    CHECK(53, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){17, 16, "unreachable code"}) )
  }
  
  Bool _Bool37;
  CHECK(55, String_equal(keyword, &(String){3, 2, "if"}, &(_Bool37)) )
  if (_Bool37) {
    if ((*end) != ' ') {
      CHECK(57, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after \"if\", got"}, (*end)) )
    }
    CHECK(58, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
    CHECK(59, List_add(self->code_nodes, &(new_if->_base._base)) )
    
  }
  else {
    Bool _Bool38;
    CHECK(61, String_equal(keyword, &(String){5, 4, "else"}, &(_Bool38)) )
    if (_Bool38) {
      if (!(NULL != self->previous_if)) {
        CHECK(63, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){31, 30, "\"else\" without a previous \"if\""}) )
      }
      if ((*end) != '\n') {
        CHECK(65, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected new-line after \"else\", got"}, (*end)) )
      }
      SyntaxTreeElse* _SyntaxTreeElse39;
      CHECK(67, SyntaxTreeElse_parse_new(NULL, self, &((*end)), &(_SyntaxTreeElse39)) )
      CHECK(67, SyntaxTreeIf_add_else(self->previous_if, _SyntaxTreeElse39) )
      
    }
    else {
      Bool _Bool40;
      CHECK(70, String_equal(keyword, &(String){8, 7, "else-if"}, &(_Bool40)) )
      if (_Bool40) {
        if (!(NULL != self->previous_if)) {
          CHECK(72, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){34, 33, "\"else-if\" without a previous \"if\""}) )
        }
        if ((*end) != ' ') {
          CHECK(74, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected space after \"else-if\", got"}, (*end)) )
        }
        CHECK(76, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
        CHECK(77, SyntaxTreeIf_add_else_if(self->previous_if, new_if) )
        
      }
      else {
        Bool _Bool41;
        CHECK(79, String_equal(keyword, &(String){3, 2, "do"}, &(_Bool41)) )
        if (_Bool41) {
          if ((*end) != '\n') {
            CHECK(81, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected new-line after \"do\", got"}, (*end)) )
          }
          SyntaxTreeDoLoop* _SyntaxTreeDoLoop42;
          CHECK(83, SyntaxTreeDoLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeDoLoop42)) )
          CHECK(83, List_add(self->code_nodes, &(_SyntaxTreeDoLoop42->_base._base)) )
          
        }
        else {
          Bool _Bool43;
          CHECK(86, String_equal(keyword, &(String){4, 3, "for"}, &(_Bool43)) )
          if (_Bool43) {
            if ((*end) != ' ') {
              CHECK(88, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"for\", got"}, (*end)) )
            }
            SyntaxTreeForLoop* _SyntaxTreeForLoop44;
            CHECK(90, SyntaxTreeForLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeForLoop44)) )
            CHECK(90, List_add(self->code_nodes, &(_SyntaxTreeForLoop44->_base._base)) )
            
          }
          else {
            Bool _Bool45;
            CHECK(93, String_equal(keyword, &(String){6, 5, "while"}, &(_Bool45)) )
            if (_Bool45) {
              if ((*end) != ' ') {
                CHECK(95, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected space after \"while\", got"}, (*end)) )
              }
              SyntaxTreeWhile* _SyntaxTreeWhile46;
              CHECK(97, SyntaxTreeWhile_parse_new(NULL, self, &((*end)), &(_SyntaxTreeWhile46)) )
              CHECK(97, List_add(self->code_nodes, &(_SyntaxTreeWhile46->_base)) )
              
            }
            else {
              Bool _Bool47;
              CHECK(100, String_equal(keyword, &(String){9, 8, "continue"}, &(_Bool47)) )
              if (_Bool47) {
                if ((*end) != '\n') {
                  CHECK(102, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){40, 39, "expected new-line after \"continue\", got"}, (*end)) )
                }
                SyntaxTreeContinue* _SyntaxTreeContinue48;
                CHECK(104, SyntaxTreeContinue_parse_new(NULL, self, &((*end)), &(_SyntaxTreeContinue48)) )
                CHECK(104, List_add(self->code_nodes, &(_SyntaxTreeContinue48->_base)) )
                
              }
              else {
                Bool _Bool49;
                CHECK(107, String_equal(keyword, &(String){7, 6, "return"}, &(_Bool49)) )
                if (_Bool49) {
                  if ((*end) != '\n') {
                    CHECK(109, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){38, 37, "expected new-line after \"return\", got"}, (*end)) )
                  }
                  SyntaxTreeReturn* _SyntaxTreeReturn50;
                  CHECK(111, SyntaxTreeReturn_parse_new(NULL, self, &((*end)), &(_SyntaxTreeReturn50)) )
                  CHECK(111, List_add(self->code_nodes, &(_SyntaxTreeReturn50->_base)) )
                  
                }
                else {
                  Bool _Bool51;
                  CHECK(114, String_equal(keyword, &(String){6, 5, "raise"}, &(_Bool51)) )
                  if (_Bool51) {
                    if ((*end) != '\n') {
                      CHECK(116, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){37, 36, "expected new-line after \"raise\", got"}, (*end)) )
                    }
                    SyntaxTreeRaise* _SyntaxTreeRaise52;
                    CHECK(118, SyntaxTreeRaise_parse_new(NULL, self, &((*end)), &(_SyntaxTreeRaise52)) )
                    CHECK(118, List_add(self->code_nodes, &(_SyntaxTreeRaise52->_base)) )
                    
                  }
                  else {
                    Bool _Bool53;
                    CHECK(121, String_equal(keyword, &(String){4, 3, "new"}, &(_Bool53)) )
                    if (_Bool53) {
                      if ((*end) != ' ') {
                        CHECK(123, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"new\", got"}, (*end)) )
                      }
                      SyntaxTreeFunction* _SyntaxTreeFunction54;
                      CHECK(125, (self)->_base._base._dtl[5](self, &(_SyntaxTreeFunction54)) )
                      SyntaxTreeVariable* _SyntaxTreeVariable55;
                      CHECK(125, SyntaxTreeVariable_parse_new(NULL, ACCESS_OWNER, true, NULL, self, &((*end)), &(_SyntaxTreeVariable55)) )
                      CHECK(125, List_add(_SyntaxTreeFunction54->_base._base.variables, _SyntaxTreeVariable55) )
                      
                    }
                    else {
                      Bool _Bool56;
                      CHECK(128, String_equal(keyword, &(String){7, 6, "assert"}, &(_Bool56)) )
                      if (_Bool56) {
                        if ((*end) != ' ') {
                          CHECK(130, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){35, 34, "expected space after \"assert\", got"}, (*end)) )
                        }
                        SyntaxTreeAssert* _SyntaxTreeAssert57;
                        CHECK(132, SyntaxTreeAssert_parse_new(NULL, self, &((*end)), &(_SyntaxTreeAssert57)) )
                        CHECK(132, List_add(self->code_nodes, &(_SyntaxTreeAssert57->_base)) )
                        
                      }
                      else {
                        Bool _Bool58;
                        CHECK(135, String_equal(keyword, &(String){13, 12, "assert-error"}, &(_Bool58)) )
                        if (_Bool58) {
                          if ((*end) != ' ') {
                            CHECK(137, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){41, 40, "expected space after \"assert-error\", got"}, (*end)) )
                          }
                          SyntaxTreeAssertError* _SyntaxTreeAssertError59;
                          CHECK(139, SyntaxTreeAssertError_parse_new(NULL, self, &((*end)), &(_SyntaxTreeAssertError59)) )
                          CHECK(139, List_add(self->code_nodes, &(_SyntaxTreeAssertError59->_base)) )
                          
                        }
                        else {
                          glob->save_input = true;
                          SyntaxTreeExpression* _SyntaxTreeExpression60;
                          CHECK(144, SyntaxTreeExpression_parse_new(NULL, self, &((*end)), &(_SyntaxTreeExpression60)) )
                          CHECK(144, List_add(self->code_nodes, &(_SyntaxTreeExpression60->_base)) )
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
    CHECK(151, (((SyntaxTreeCode*)(self->code_nodes->last->item)))->_base._dtl[3](((SyntaxTreeCode*)(self->code_nodes->last->item)), &((*has_end))) )
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
  CHECK(157, SyntaxTreeBranch_find_variable(&(self->_base), name, &((*variable))) )
  if (!(NULL != (*variable)) &&  NULL !=  self->ref_variable) {
    Bool _Bool61;
    CHECK(159, SyntaxTreeVariable_find_variable(self->ref_variable, name, &((*variable)), &(_Bool61)) )
  }
  if (!(NULL != (*variable)) &&  NULL !=  self->parent) {
    CHECK(161, (self->parent)->_base._base._dtl[4](self->parent, name, &((*variable))) )
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
  CHECK(164, (self->parent)->_base._base._dtl[5](self->parent, &((*function))) )
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
  CHECK(167, SyntaxTreeBranch_link_types(&(self->_base)) )
  CHECK(168, SyntaxTreeNode_link_children_types(&(self->_base._base), self->code_nodes) )
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
  CHECK(171, SyntaxTreeBranch_analyze(&(self->_base)) )
  CHECK(172, SyntaxTreeNode_analyze_children(&(self->_base._base), self->code_nodes) )
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
  CHECK(178, SyntaxTreeBlock_write_block_start(self) )
  CHECK(179, SyntaxTreeNode_write_children(&(self->_base._base), self->code_nodes) )
  CHECK(180, SyntaxTreeBlock_write_block_end(self) )
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
  CHECK(183, write(&(String){4, 3, " {\n"}) )
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
  CHECK(186, write_spaces(self->_base.indentation_spaces - 2) )
  CHECK(187, write(&(String){3, 2, "}\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBlock__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBlock__dtl[] = {(void*)SyntaxTreeBlock_link_types, (void*)SyntaxTreeBlock_analyze, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeBlock_find_variable, (void*)SyntaxTreeBlock_get_function};
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
#include "syntax-tree/function.c"
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
