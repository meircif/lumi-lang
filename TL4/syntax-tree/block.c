#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "syntax-tree/block.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file17_name = "syntax-tree/block.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file17_name

/* TL4 compiler - Syntax tree code block */


/* A basic code node in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeCode SyntaxTreeCode;
#elif LUMI_STAGE == LUMI_TYPES(1)
struct SyntaxTreeCode {
  SyntaxTreeNode _base;
  SyntaxTreeBlock* parent;
/* Read and check indentation spaces for a line break from the input file */};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeCode_find_variable(SyntaxTreeCode* self, String* name, String* module_name, SyntaxTreeVariable** variable);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeCode_find_variable = "SyntaxTreeCode.find-variable";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeCode_find_variable
Returncode SyntaxTreeCode_find_variable(SyntaxTreeCode* self, String* name, String* module_name, SyntaxTreeVariable** variable) {
  if (NULL != self->parent &&  ! (NULL != module_name)) {
    CHECK(11, (self->parent)->_base._base._dtl[7](self->parent, name, NULL, &((*variable))) )
  }
  else {
    CHECK(13, SyntaxTreeNode_find_variable(&(self->_base), name, module_name, &((*variable))) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeCode_get_function(SyntaxTreeCode* self, SyntaxTreeFunction** function);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeCode_get_function = "SyntaxTreeCode.get-function";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeCode_get_function
Returncode SyntaxTreeCode_get_function(SyntaxTreeCode* self, SyntaxTreeFunction** function) {
  CHECK(16, (self->parent)->_base._base._dtl[8](self->parent, &((*function))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeCode_get_parent_type(SyntaxTreeCode* self, TypeData** parent_type);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeCode_get_parent_type = "SyntaxTreeCode.get-parent-type";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeCode_get_parent_type
Returncode SyntaxTreeCode_get_parent_type(SyntaxTreeCode* self, TypeData** parent_type) {
  CHECK(19, SyntaxTreeBlock_get_parent_type(self->parent, &((*parent_type))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeCode_write_spaces(SyntaxTreeCode* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeCode_write_spaces = "SyntaxTreeCode.write-spaces";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeCode_write_spaces
Returncode SyntaxTreeCode_write_spaces(SyntaxTreeCode* self) {
  CHECK(22, SyntaxTreeBranch_write_spaces(&(self->parent->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeCode_write_call(SyntaxTreeCode* self, FunctionArguments* arguments);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeCode_write_call = "SyntaxTreeCode.write-call";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeCode_write_call
Returncode SyntaxTreeCode_write_call(SyntaxTreeCode* self, FunctionArguments* arguments) {
  CHECK(25, (arguments)->_base._dtl[5](arguments) )
  CHECK(26, write(&(String){3, 2, ";\n"}) )
  CHECK(27, FunctionArguments_write_postactions(arguments) )
  CHECK(28, SyntaxTreeCode_write_spaces(self) )
  CHECK(29, write(&(String){7, 6, "CHECK("}) )
  CHECK(30, SyntaxTreeNode_write_line_num(&(self->_base)) )
  CHECK(31, write(&(String){3, 2, ")\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* Read and check indentation spaces for a line break from the input file */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeCode_read_parent_line_break_spaces(SyntaxTreeCode* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeCode_read_parent_line_break_spaces = "SyntaxTreeCode.read-parent-line-break-spaces";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeCode_read_parent_line_break_spaces
Returncode SyntaxTreeCode_read_parent_line_break_spaces(SyntaxTreeCode* self) {
  CHECK(35, SyntaxTreeNode_read_line_break_spaces(&(self->_base), self->parent->_base.indentation_spaces) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeCode_m_is_end_point(SyntaxTreeCode* self, Bool* is_end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeCode_m_is_end_point = "SyntaxTreeCode.m-is-end-point";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeCode_m_is_end_point
Returncode SyntaxTreeCode_m_is_end_point(SyntaxTreeCode* self, Bool* is_end) {
  (*is_end) = false;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeCode__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeCode__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeNode_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* A basic code block node in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeBlock SyntaxTreeBlock;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct SyntaxTreeBlock {
  SyntaxTreeBranch _base;
  SyntaxTreeBlock* parent;
  List* code_nodes;
  SyntaxTreeIf* previous_if;
  SyntaxTreeTry* previous_try;
  Bool is_in_loop;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBlock_parse_block(SyntaxTreeBlock* self, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_parse_block = "SyntaxTreeBlock.parse-block";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBlock_parse_block
Returncode SyntaxTreeBlock_parse_block(SyntaxTreeBlock* self, Char* end) {
  self->code_nodes = malloc(sizeof(List));
  if (self->code_nodes == NULL) RAISE(50)
  *self->code_nodes = (List){NULL, NULL};
  CHECK(51, SyntaxTreeBranch_parse_block_children(&(self->_base), NULL, self, &((*end))) )
  TypeData* _TypeData58;
  CHECK(52, SyntaxTreeBlock_get_parent_type(self, &(_TypeData58)) )
  if (NULL != _TypeData58) {
    self->_base.indentation_spaces -= 2;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBlock_parse_child(SyntaxTreeBlock* self, String* keyword, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_parse_child = "SyntaxTreeBlock.parse-child";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBlock_parse_child
Returncode SyntaxTreeBlock_parse_child(SyntaxTreeBlock* self, String* keyword, Char* end) {
  SyntaxTreeCode* node = NULL;
  SyntaxTreeIf* new_if = NULL;
  SyntaxTreeTry* new_try = NULL;
  
  Bool _Bool59;
  CHECK(60, SyntaxTreeBlock_m_has_end_point(self, &(_Bool59)) )
  if (_Bool59) {
    CHECK(61, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){17, 16, "unreachable code"}) )
  }
  
  Bool _Bool60;
  CHECK(63, String_equal(keyword, &(String){3, 2, "if"}, &(_Bool60)) )
  if (_Bool60) {
    if ((*end) != ' ') {
      CHECK(65, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after \"if\", got"}, (*end)) )
    }
    CHECK(66, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
    CHECK(67, List_add(self->code_nodes, &(new_if->_base._base)) )
    
  }
  else {
    Bool _Bool61;
    CHECK(69, String_equal(keyword, &(String){5, 4, "else"}, &(_Bool61)) )
    if (_Bool61) {
      if (!(NULL != self->previous_if)) {
        CHECK(71, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){31, 30, "\"else\" without a previous \"if\""}) )
      }
      if ((*end) != '\n') {
        CHECK(73, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected new-line after \"else\", got"}, (*end)) )
      }
      SyntaxTreeElse* _SyntaxTreeElse62;
      CHECK(75, SyntaxTreeElse_parse_new(NULL, self, &((*end)), &(_SyntaxTreeElse62)) )
      CHECK(75, SyntaxTreeIf_add_else(self->previous_if, _SyntaxTreeElse62) )
      
    }
    else {
      Bool _Bool63;
      CHECK(78, String_equal(keyword, &(String){8, 7, "else-if"}, &(_Bool63)) )
      if (_Bool63) {
        if (!(NULL != self->previous_if)) {
          CHECK(80, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){34, 33, "\"else-if\" without a previous \"if\""}) )
        }
        if ((*end) != ' ') {
          CHECK(82, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected space after \"else-if\", got"}, (*end)) )
        }
        SyntaxTreeCoverage* coverage_node = NULL;
        if (NULL != glob->tested_module) {
          Bool _Bool64;
          CHECK(86, String_equal(glob->current_module->name, glob->tested_module, &(_Bool64)) )
          if (_Bool64) {
            CHECK(87, SyntaxTreeCoverage_init_new(NULL, NULL, &(coverage_node)) )
          }
        }
        CHECK(88, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
        CHECK(89, SyntaxTreeIf_add_else_if(self->previous_if, new_if, coverage_node) )
        
      }
      else {
        Bool _Bool65;
        CHECK(91, String_equal(keyword, &(String){3, 2, "do"}, &(_Bool65)) )
        if (_Bool65) {
          if ((*end) != '\n') {
            CHECK(93, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected new-line after \"do\", got"}, (*end)) )
          }
          SyntaxTreeDoLoop* _SyntaxTreeDoLoop66;
          CHECK(95, SyntaxTreeDoLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeDoLoop66)) )
          CHECK(95, List_add(self->code_nodes, &(_SyntaxTreeDoLoop66->_base._base)) )
          
        }
        else {
          Bool _Bool67;
          CHECK(98, String_equal(keyword, &(String){4, 3, "for"}, &(_Bool67)) )
          if (_Bool67) {
            if ((*end) != ' ') {
              CHECK(100, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"for\", got"}, (*end)) )
            }
            SyntaxTreeForLoop* _SyntaxTreeForLoop68;
            CHECK(102, SyntaxTreeForLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeForLoop68)) )
            CHECK(102, List_add(self->code_nodes, &(_SyntaxTreeForLoop68->_base._base)) )
            
          }
          else {
            Bool _Bool69;
            CHECK(105, String_equal(keyword, &(String){6, 5, "while"}, &(_Bool69)) )
            if (_Bool69) {
              if ((*end) != ' ') {
                CHECK(107, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected space after \"while\", got"}, (*end)) )
              }
              SyntaxTreeWhile* _SyntaxTreeWhile70;
              CHECK(109, SyntaxTreeWhile_parse_new(NULL, self, &((*end)), &(_SyntaxTreeWhile70)) )
              CHECK(109, List_add(self->code_nodes, &(_SyntaxTreeWhile70->_base)) )
              
            }
            else {
              Bool _Bool71;
              CHECK(112, String_equal(keyword, &(String){6, 5, "break"}, &(_Bool71)) )
              if (_Bool71) {
                if ((*end) != '\n') {
                  CHECK(114, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){37, 36, "expected new-line after \"break\", got"}, (*end)) )
                }
                SyntaxTreeBreak* _SyntaxTreeBreak72;
                CHECK(116, SyntaxTreeBreak_parse_new(NULL, self, &((*end)), &(_SyntaxTreeBreak72)) )
                CHECK(116, List_add(self->code_nodes, &(_SyntaxTreeBreak72->_base)) )
                
              }
              else {
                Bool _Bool73;
                CHECK(119, String_equal(keyword, &(String){9, 8, "continue"}, &(_Bool73)) )
                if (_Bool73) {
                  if ((*end) != '\n') {
                    CHECK(121, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){40, 39, "expected new-line after \"continue\", got"}, (*end)) )
                  }
                  SyntaxTreeContinue* _SyntaxTreeContinue74;
                  CHECK(123, SyntaxTreeContinue_parse_new(NULL, self, &((*end)), &(_SyntaxTreeContinue74)) )
                  CHECK(123, List_add(self->code_nodes, &(_SyntaxTreeContinue74->_base)) )
                  
                }
                else {
                  Bool _Bool75;
                  CHECK(126, String_equal(keyword, &(String){7, 6, "return"}, &(_Bool75)) )
                  if (_Bool75) {
                    if ((*end) != '\n') {
                      CHECK(128, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){38, 37, "expected new-line after \"return\", got"}, (*end)) )
                    }
                    SyntaxTreeReturn* _SyntaxTreeReturn76;
                    CHECK(130, SyntaxTreeReturn_parse_new(NULL, self, &((*end)), &(_SyntaxTreeReturn76)) )
                    CHECK(130, List_add(self->code_nodes, &(_SyntaxTreeReturn76->_base)) )
                    
                  }
                  else {
                    Bool _Bool77;
                    CHECK(133, String_equal(keyword, &(String){6, 5, "raise"}, &(_Bool77)) )
                    if (_Bool77) {
                      if ((*end) != ' ' && (*end) != '\n') {
                        CHECK(135, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){46, 45, "expected space or new-line after \"raise\", got"}, (*end)) )
                      }
                      SyntaxTreeRaise* _SyntaxTreeRaise78;
                      CHECK(137, SyntaxTreeRaise_parse_new(NULL, self, &((*end)), &(_SyntaxTreeRaise78)) )
                      CHECK(137, List_add(self->code_nodes, &(_SyntaxTreeRaise78->_base)) )
                      
                    }
                    else {
                      Bool _Bool79;
                      CHECK(140, String_equal(keyword, &(String){4, 3, "new"}, &(_Bool79)) )
                      if (_Bool79) {
                        if ((*end) != ' ') {
                          CHECK(142, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"new\", got"}, (*end)) )
                        }
                        SyntaxTreeFunction* _SyntaxTreeFunction80;
                        CHECK(144, (self)->_base._base._dtl[8](self, &(_SyntaxTreeFunction80)) )
                        SyntaxTreeVariable* _SyntaxTreeVariable81;
                        CHECK(144, SyntaxTreeVariable_parse_new(NULL, ACCESS_OWNER, true, NULL, self, &((*end)), &(_SyntaxTreeVariable81)) )
                        CHECK(144, List_add(_SyntaxTreeFunction80->_base._base.variables, _SyntaxTreeVariable81) )
                        
                      }
                      else {
                        Bool _Bool82;
                        CHECK(147, String_equal(keyword, &(String){4, 3, "try"}, &(_Bool82)) )
                        if (_Bool82) {
                          if ((*end) != '\n') {
                            CHECK(149, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){35, 34, "expected new-line after \"try\", got"}, (*end)) )
                          }
                          SyntaxTreeTry* try_node = NULL;
                          CHECK(152, SyntaxTreeTry_parse_new(NULL, self, &((*end)), &(try_node)) )
                          new_try = try_node;
                          CHECK(154, List_add(self->code_nodes, &(try_node->_base._base)) )
                          
                        }
                        else {
                          Bool _Bool83;
                          CHECK(156, String_equal(keyword, &(String){6, 5, "catch"}, &(_Bool83)) )
                          if (_Bool83) {
                            if (!(NULL != self->previous_try)) {
                              CHECK(158, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){33, 32, "\"catch\" without a previous \"try\""}) )
                            }
                            if ((*end) != '\n') {
                              CHECK(160, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){37, 36, "expected new-line after \"catch\", got"}, (*end)) )
                            }
                            SyntaxTreeCatch* catch_node = NULL;
                            CHECK(163, SyntaxTreeCatch_parse_new(NULL, self, &((*end)), &(catch_node)) )
                            self->previous_try->catch_node = catch_node;
                            CHECK(165, List_add(self->code_nodes, &(catch_node->_base._base)) )
                            
                          }
                          else {
                            Bool _Bool84;
                            CHECK(167, String_equal(keyword, &(String){7, 6, "assert"}, &(_Bool84)) )
                            if (_Bool84) {
                              if ((*end) != ' ') {
                                CHECK(169, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){35, 34, "expected space after \"assert\", got"}, (*end)) )
                              }
                              SyntaxTreeAssert* _SyntaxTreeAssert85;
                              CHECK(171, SyntaxTreeAssert_parse_new(NULL, self, &((*end)), &(_SyntaxTreeAssert85)) )
                              CHECK(171, List_add(self->code_nodes, &(_SyntaxTreeAssert85->_base)) )
                              
                            }
                            else {
                              Bool _Bool86;
                              CHECK(174, String_equal(keyword, &(String){13, 12, "assert-error"}, &(_Bool86)) )
                              if (_Bool86) {
                                if ((*end) != ' ') {
                                  CHECK(176, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){41, 40, "expected space after \"assert-error\", got"}, (*end)) )
                                }
                                SyntaxTreeAssertError* _SyntaxTreeAssertError87;
                                CHECK(178, SyntaxTreeAssertError_parse_new(NULL, self, &((*end)), &(_SyntaxTreeAssertError87)) )
                                CHECK(178, List_add(self->code_nodes, &(_SyntaxTreeAssertError87->_base)) )
                                
                              }
                              else {
                                glob->save_input = true;
                                SyntaxTreeExpression* _SyntaxTreeExpression88;
                                CHECK(183, SyntaxTreeExpression_parse_new(NULL, self, &((*end)), &(_SyntaxTreeExpression88)) )
                                CHECK(183, List_add(self->code_nodes, &(_SyntaxTreeExpression88->_base)) )
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
  }
  
  self->previous_if = new_if;
  self->previous_try = new_try;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBlock_m_has_end_point(SyntaxTreeBlock* self, Bool* has_end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_m_has_end_point = "SyntaxTreeBlock.m-has-end-point";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBlock_m_has_end_point
Returncode SyntaxTreeBlock_m_has_end_point(SyntaxTreeBlock* self, Bool* has_end) {
  if (NULL != self->code_nodes->last) {
    CHECK(191, (((SyntaxTreeCode*)(self->code_nodes->last->item)))->_base._dtl[5](((SyntaxTreeCode*)(self->code_nodes->last->item)), &((*has_end))) )
  }
  else {
    (*has_end) = false;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBlock_find_variable(SyntaxTreeBlock* self, String* name, String* module_name, SyntaxTreeVariable** variable);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_find_variable = "SyntaxTreeBlock.find-variable";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBlock_find_variable
Returncode SyntaxTreeBlock_find_variable(SyntaxTreeBlock* self, String* name, String* module_name, SyntaxTreeVariable** variable) {
  CHECK(197, SyntaxTreeBranch_find_variable(&(self->_base), name, module_name, &((*variable))) )
  if (!(NULL != (*variable)) &&  NULL !=  self->parent &&  ! (NULL != module_name)) {
    CHECK(199, (self->parent)->_base._base._dtl[7](self->parent, name, NULL, &((*variable))) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBlock_get_function(SyntaxTreeBlock* self, SyntaxTreeFunction** function);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_get_function = "SyntaxTreeBlock.get-function";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBlock_get_function
Returncode SyntaxTreeBlock_get_function(SyntaxTreeBlock* self, SyntaxTreeFunction** function) {
  CHECK(202, (self->parent)->_base._base._dtl[8](self->parent, &((*function))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBlock_get_parent_type(SyntaxTreeBlock* self, TypeData** parent_type);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_get_parent_type = "SyntaxTreeBlock.get-parent-type";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBlock_get_parent_type
Returncode SyntaxTreeBlock_get_parent_type(SyntaxTreeBlock* self, TypeData** parent_type) {
  SyntaxTreeFunction* _SyntaxTreeFunction89;
  CHECK(205, (self)->_base._base._dtl[8](self, &(_SyntaxTreeFunction89)) )
  (*parent_type) = _SyntaxTreeFunction89->parent_type;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBlock_link_types(SyntaxTreeBlock* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_link_types = "SyntaxTreeBlock.link-types";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBlock_link_types
Returncode SyntaxTreeBlock_link_types(SyntaxTreeBlock* self) {
  CHECK(208, SyntaxTreeBranch_link_types(&(self->_base)) )
  CHECK(209, SyntaxTreeNode_link_children_types(&(self->_base._base), self->code_nodes) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBlock_analyze(SyntaxTreeBlock* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_analyze = "SyntaxTreeBlock.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBlock_analyze
Returncode SyntaxTreeBlock_analyze(SyntaxTreeBlock* self) {
  CHECK(212, SyntaxTreeBranch_analyze(&(self->_base)) )
  CHECK(213, SyntaxTreeNode_analyze_children(&(self->_base._base), self->code_nodes) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBlock_write_block(SyntaxTreeBlock* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_write_block = "SyntaxTreeBlock.write-block";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBlock_write_block
Returncode SyntaxTreeBlock_write_block(SyntaxTreeBlock* self) {
  /* `previous-text` { */
  /*   `block...` */
  /* } */
  CHECK(219, SyntaxTreeBlock_write_block_start(self) )
  CHECK(220, (self)->_base._base._dtl[9](self) )
  CHECK(221, SyntaxTreeBlock_write_block_end(self) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBlock_write_block_start(SyntaxTreeBlock* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_write_block_start = "SyntaxTreeBlock.write-block-start";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBlock_write_block_start
Returncode SyntaxTreeBlock_write_block_start(SyntaxTreeBlock* self) {
  CHECK(224, write(&(String){4, 3, " {\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBlock_write_block_body(SyntaxTreeBlock* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_write_block_body = "SyntaxTreeBlock.write-block-body";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBlock_write_block_body
Returncode SyntaxTreeBlock_write_block_body(SyntaxTreeBlock* self) {
  CHECK(227, SyntaxTreeNode_write_children(&(self->_base._base), self->code_nodes) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBlock_write_block_end(SyntaxTreeBlock* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_write_block_end = "SyntaxTreeBlock.write-block-end";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBlock_write_block_end
Returncode SyntaxTreeBlock_write_block_end(SyntaxTreeBlock* self) {
  CHECK(230, write_spaces(self->_base.indentation_spaces - 2) )
  CHECK(231, write(&(String){3, 2, "}\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeBlock__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeBlock__dtl[] = {(void*)SyntaxTreeBlock_get_parent_type, (void*)SyntaxTreeBlock_link_types, (void*)SyntaxTreeBlock_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeBlock_find_variable, (void*)SyntaxTreeBlock_get_function, (void*)SyntaxTreeBlock_write_block_body};
#endif

#undef LUMI_FILE_NAME

#ifndef LUMI_INCLUDES
#define LUMI_INCLUDES
#include "tl4-compiler.c"
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
#if LUMI_STAGE == LUMI_TYPES(1)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(2)
#elif LUMI_STAGE == LUMI_TYPES(2)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(3)
#elif LUMI_STAGE == LUMI_TYPES(3)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(4)
#elif LUMI_STAGE == LUMI_TYPES(4)
#undef LUMI_STAGE
#define LUMI_STAGE LUMI_TYPES(5)
#endif
#undef LUMI_INCLUDES
#endif

#endif
