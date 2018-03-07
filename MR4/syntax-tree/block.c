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
Returncode SyntaxTreeCode_find_variable(SyntaxTreeCode* self, String* name, String* module_name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCode_find_variable = "SyntaxTreeCode.find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeCode_find_variable
Returncode SyntaxTreeCode_find_variable(SyntaxTreeCode* self, String* name, String* module_name, SyntaxTreeVariable** variable) {
  if (NULL != self->parent &&  ! (NULL != module_name)) {
    CHECK(11, (self->parent)->_base._base._dtl[7](self->parent, name, NULL, &((*variable))) )
  }
  else {
    CHECK(13, SyntaxTreeNode_find_variable(&(self->_base), name, module_name, &((*variable))) )
  }
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
  CHECK(16, (self->parent)->_base._base._dtl[8](self->parent, &((*function))) )
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
  SyntaxTreeFunction* _SyntaxTreeFunction51;
  CHECK(19, SyntaxTreeCode_get_function(self, &(_SyntaxTreeFunction51)) )
  (*parent_type) = _SyntaxTreeFunction51->parent_type;
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
  CHECK(22, SyntaxTreeBranch_write_spaces(&(self->parent->_base)) )
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
    Char _Char52;
    CHECK(28, read_c(&(_Char52)) )
    if (_Char52 != ' ') {
      CHECK(29, SyntaxTreeNode_m_syntax_error_indentation(&(self->_base), n, expected_spaces) )
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
Func SyntaxTreeCode__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeNode_write, (void*)SyntaxTreeCode_m_is_end_point};
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
  SyntaxTreeTry* previous_try;
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
  if (self->code_nodes == NULL) RAISE(44)
  *self->code_nodes = (List){NULL, NULL};
  CHECK(45, SyntaxTreeBranch_parse_block_children(&(self->_base), NULL, self, &((*end))) )
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
  SyntaxTreeTry* new_try = NULL;
  
  Bool _Bool53;
  CHECK(52, SyntaxTreeBlock_m_has_end_point(self, &(_Bool53)) )
  if (_Bool53) {
    CHECK(53, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){17, 16, "unreachable code"}) )
  }
  
  Bool _Bool54;
  CHECK(55, String_equal(keyword, &(String){3, 2, "if"}, &(_Bool54)) )
  if (_Bool54) {
    if ((*end) != ' ') {
      CHECK(57, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after \"if\", got"}, (*end)) )
    }
    CHECK(58, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
    CHECK(59, List_add(self->code_nodes, &(new_if->_base._base)) )
    
  }
  else {
    Bool _Bool55;
    CHECK(61, String_equal(keyword, &(String){5, 4, "else"}, &(_Bool55)) )
    if (_Bool55) {
      if (!(NULL != self->previous_if)) {
        CHECK(63, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){31, 30, "\"else\" without a previous \"if\""}) )
      }
      if ((*end) != '\n') {
        CHECK(65, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected new-line after \"else\", got"}, (*end)) )
      }
      SyntaxTreeElse* _SyntaxTreeElse56;
      CHECK(67, SyntaxTreeElse_parse_new(NULL, self, &((*end)), &(_SyntaxTreeElse56)) )
      CHECK(67, SyntaxTreeIf_add_else(self->previous_if, _SyntaxTreeElse56) )
      
    }
    else {
      Bool _Bool57;
      CHECK(70, String_equal(keyword, &(String){8, 7, "else-if"}, &(_Bool57)) )
      if (_Bool57) {
        if (!(NULL != self->previous_if)) {
          CHECK(72, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){34, 33, "\"else-if\" without a previous \"if\""}) )
        }
        if ((*end) != ' ') {
          CHECK(74, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected space after \"else-if\", got"}, (*end)) )
        }
        SyntaxTreeCoverage* coverage_node = NULL;
        if (NULL != glob->tested_module) {
          Bool _Bool58;
          CHECK(78, String_equal(glob->current_module->name, glob->tested_module, &(_Bool58)) )
          if (_Bool58) {
            CHECK(79, SyntaxTreeCoverage_init_new(NULL, NULL, &(coverage_node)) )
          }
        }
        CHECK(80, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
        CHECK(81, SyntaxTreeIf_add_else_if(self->previous_if, new_if, coverage_node) )
        
      }
      else {
        Bool _Bool59;
        CHECK(83, String_equal(keyword, &(String){3, 2, "do"}, &(_Bool59)) )
        if (_Bool59) {
          if ((*end) != '\n') {
            CHECK(85, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected new-line after \"do\", got"}, (*end)) )
          }
          SyntaxTreeDoLoop* _SyntaxTreeDoLoop60;
          CHECK(87, SyntaxTreeDoLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeDoLoop60)) )
          CHECK(87, List_add(self->code_nodes, &(_SyntaxTreeDoLoop60->_base._base)) )
          
        }
        else {
          Bool _Bool61;
          CHECK(90, String_equal(keyword, &(String){4, 3, "for"}, &(_Bool61)) )
          if (_Bool61) {
            if ((*end) != ' ') {
              CHECK(92, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"for\", got"}, (*end)) )
            }
            SyntaxTreeForLoop* _SyntaxTreeForLoop62;
            CHECK(94, SyntaxTreeForLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeForLoop62)) )
            CHECK(94, List_add(self->code_nodes, &(_SyntaxTreeForLoop62->_base._base)) )
            
          }
          else {
            Bool _Bool63;
            CHECK(97, String_equal(keyword, &(String){6, 5, "while"}, &(_Bool63)) )
            if (_Bool63) {
              if ((*end) != ' ') {
                CHECK(99, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected space after \"while\", got"}, (*end)) )
              }
              SyntaxTreeWhile* _SyntaxTreeWhile64;
              CHECK(101, SyntaxTreeWhile_parse_new(NULL, self, &((*end)), &(_SyntaxTreeWhile64)) )
              CHECK(101, List_add(self->code_nodes, &(_SyntaxTreeWhile64->_base)) )
              
            }
            else {
              Bool _Bool65;
              CHECK(104, String_equal(keyword, &(String){9, 8, "continue"}, &(_Bool65)) )
              if (_Bool65) {
                if ((*end) != '\n') {
                  CHECK(106, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){40, 39, "expected new-line after \"continue\", got"}, (*end)) )
                }
                SyntaxTreeContinue* _SyntaxTreeContinue66;
                CHECK(108, SyntaxTreeContinue_parse_new(NULL, self, &((*end)), &(_SyntaxTreeContinue66)) )
                CHECK(108, List_add(self->code_nodes, &(_SyntaxTreeContinue66->_base)) )
                
              }
              else {
                Bool _Bool67;
                CHECK(111, String_equal(keyword, &(String){7, 6, "return"}, &(_Bool67)) )
                if (_Bool67) {
                  if ((*end) != '\n') {
                    CHECK(113, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){38, 37, "expected new-line after \"return\", got"}, (*end)) )
                  }
                  SyntaxTreeReturn* _SyntaxTreeReturn68;
                  CHECK(115, SyntaxTreeReturn_parse_new(NULL, self, &((*end)), &(_SyntaxTreeReturn68)) )
                  CHECK(115, List_add(self->code_nodes, &(_SyntaxTreeReturn68->_base)) )
                  
                }
                else {
                  Bool _Bool69;
                  CHECK(118, String_equal(keyword, &(String){6, 5, "raise"}, &(_Bool69)) )
                  if (_Bool69) {
                    if ((*end) != ' ' && (*end) != '\n') {
                      CHECK(120, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){46, 45, "expected space or new-line after \"raise\", got"}, (*end)) )
                    }
                    SyntaxTreeRaise* _SyntaxTreeRaise70;
                    CHECK(122, SyntaxTreeRaise_parse_new(NULL, self, &((*end)), &(_SyntaxTreeRaise70)) )
                    CHECK(122, List_add(self->code_nodes, &(_SyntaxTreeRaise70->_base)) )
                    
                  }
                  else {
                    Bool _Bool71;
                    CHECK(125, String_equal(keyword, &(String){4, 3, "new"}, &(_Bool71)) )
                    if (_Bool71) {
                      if ((*end) != ' ') {
                        CHECK(127, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"new\", got"}, (*end)) )
                      }
                      SyntaxTreeFunction* _SyntaxTreeFunction72;
                      CHECK(129, (self)->_base._base._dtl[8](self, &(_SyntaxTreeFunction72)) )
                      SyntaxTreeVariable* _SyntaxTreeVariable73;
                      CHECK(129, SyntaxTreeVariable_parse_new(NULL, ACCESS_OWNER, true, NULL, self, &((*end)), &(_SyntaxTreeVariable73)) )
                      CHECK(129, List_add(_SyntaxTreeFunction72->_base._base.variables, _SyntaxTreeVariable73) )
                      
                    }
                    else {
                      Bool _Bool74;
                      CHECK(132, String_equal(keyword, &(String){4, 3, "try"}, &(_Bool74)) )
                      if (_Bool74) {
                        if ((*end) != '\n') {
                          CHECK(134, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){35, 34, "expected new-line after \"try\", got"}, (*end)) )
                        }
                        SyntaxTreeTry* try_node = NULL;
                        CHECK(137, SyntaxTreeTry_parse_new(NULL, self, &((*end)), &(try_node)) )
                        new_try = try_node;
                        CHECK(139, List_add(self->code_nodes, &(try_node->_base._base)) )
                        
                      }
                      else {
                        Bool _Bool75;
                        CHECK(141, String_equal(keyword, &(String){6, 5, "catch"}, &(_Bool75)) )
                        if (_Bool75) {
                          if (!(NULL != self->previous_try)) {
                            CHECK(143, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){33, 32, "\"catch\" without a previous \"try\""}) )
                          }
                          if ((*end) != '\n') {
                            CHECK(145, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){37, 36, "expected new-line after \"catch\", got"}, (*end)) )
                          }
                          SyntaxTreeCatch* catch_node = NULL;
                          CHECK(148, SyntaxTreeCatch_parse_new(NULL, self, &((*end)), &(catch_node)) )
                          self->previous_try->catch_node = catch_node;
                          CHECK(150, List_add(self->code_nodes, &(catch_node->_base._base)) )
                          
                        }
                        else {
                          Bool _Bool76;
                          CHECK(152, String_equal(keyword, &(String){7, 6, "assert"}, &(_Bool76)) )
                          if (_Bool76) {
                            if ((*end) != ' ') {
                              CHECK(154, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){35, 34, "expected space after \"assert\", got"}, (*end)) )
                            }
                            SyntaxTreeAssert* _SyntaxTreeAssert77;
                            CHECK(156, SyntaxTreeAssert_parse_new(NULL, self, &((*end)), &(_SyntaxTreeAssert77)) )
                            CHECK(156, List_add(self->code_nodes, &(_SyntaxTreeAssert77->_base)) )
                            
                          }
                          else {
                            Bool _Bool78;
                            CHECK(159, String_equal(keyword, &(String){13, 12, "assert-error"}, &(_Bool78)) )
                            if (_Bool78) {
                              if ((*end) != ' ') {
                                CHECK(161, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){41, 40, "expected space after \"assert-error\", got"}, (*end)) )
                              }
                              SyntaxTreeAssertError* _SyntaxTreeAssertError79;
                              CHECK(163, SyntaxTreeAssertError_parse_new(NULL, self, &((*end)), &(_SyntaxTreeAssertError79)) )
                              CHECK(163, List_add(self->code_nodes, &(_SyntaxTreeAssertError79->_base)) )
                              
                            }
                            else {
                              glob->save_input = true;
                              SyntaxTreeExpression* _SyntaxTreeExpression80;
                              CHECK(168, SyntaxTreeExpression_parse_new(NULL, self, &((*end)), &(_SyntaxTreeExpression80)) )
                              CHECK(168, List_add(self->code_nodes, &(_SyntaxTreeExpression80->_base)) )
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
    }
  }
  
  self->previous_if = new_if;
  self->previous_try = new_try;
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
    CHECK(176, (((SyntaxTreeCode*)(self->code_nodes->last->item)))->_base._dtl[5](((SyntaxTreeCode*)(self->code_nodes->last->item)), &((*has_end))) )
  }
  else {
    (*has_end) = false;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_find_variable(SyntaxTreeBlock* self, String* name, String* module_name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_find_variable = "SyntaxTreeBlock.find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_find_variable
Returncode SyntaxTreeBlock_find_variable(SyntaxTreeBlock* self, String* name, String* module_name, SyntaxTreeVariable** variable) {
  CHECK(182, SyntaxTreeBranch_find_variable(&(self->_base), name, module_name, &((*variable))) )
  if (!(NULL != (*variable)) &&  NULL !=  self->parent &&  ! (NULL != module_name)) {
    CHECK(184, (self->parent)->_base._base._dtl[7](self->parent, name, NULL, &((*variable))) )
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
  CHECK(187, (self->parent)->_base._base._dtl[8](self->parent, &((*function))) )
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
  CHECK(190, SyntaxTreeBranch_link_types(&(self->_base)) )
  CHECK(191, SyntaxTreeNode_link_children_types(&(self->_base._base), self->code_nodes) )
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
  CHECK(194, SyntaxTreeBranch_analyze(&(self->_base)) )
  CHECK(195, SyntaxTreeNode_analyze_children(&(self->_base._base), self->code_nodes) )
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
  CHECK(201, SyntaxTreeBlock_write_block_start(self) )
  CHECK(202, (self)->_base._base._dtl[9](self) )
  CHECK(203, SyntaxTreeBlock_write_block_end(self) )
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
  CHECK(206, write(&(String){4, 3, " {\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_write_block_body(SyntaxTreeBlock* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_write_block_body = "SyntaxTreeBlock.write-block-body";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_write_block_body
Returncode SyntaxTreeBlock_write_block_body(SyntaxTreeBlock* self) {
  CHECK(209, SyntaxTreeNode_write_children(&(self->_base._base), self->code_nodes) )
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
  CHECK(212, write_spaces(self->_base.indentation_spaces - 2) )
  CHECK(213, write(&(String){3, 2, "}\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBlock__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBlock__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeBlock_link_types, (void*)SyntaxTreeBlock_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeBlock_find_variable, (void*)SyntaxTreeBlock_get_function, (void*)SyntaxTreeBlock_write_block_body};
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
#include "statement/enum.c"
#include "statement/error.c"
#include "statement/for.c"
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
