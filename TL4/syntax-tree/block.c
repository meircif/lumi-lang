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
  SyntaxTreeFunction* _SyntaxTreeFunction58;
  CHECK(19, SyntaxTreeCode_get_function(self, &(_SyntaxTreeFunction58)) )
  (*parent_type) = _SyntaxTreeFunction58->parent_type;
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
Returncode SyntaxTreeCode_read_line_break_spaces(SyntaxTreeCode* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeCode_read_line_break_spaces = "SyntaxTreeCode.read-line-break-spaces";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeCode_read_line_break_spaces
Returncode SyntaxTreeCode_read_line_break_spaces(SyntaxTreeCode* self) {
  Int expected_spaces = self->parent->_base.indentation_spaces + 4;
  {int n; for (n = (0); n < (expected_spaces); ++n) {
    Char _Char59;
    CHECK(37, read_c(&(_Char59)) )
    if (_Char59 != ' ') {
      CHECK(38, SyntaxTreeNode_m_syntax_error_indentation(&(self->_base), n, expected_spaces) )
    }
  }}
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
  if (self->code_nodes == NULL) RAISE(53)
  *self->code_nodes = (List){NULL, NULL};
  CHECK(54, SyntaxTreeBranch_parse_block_children(&(self->_base), NULL, self, &((*end))) )
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
  
  Bool _Bool60;
  CHECK(61, SyntaxTreeBlock_m_has_end_point(self, &(_Bool60)) )
  if (_Bool60) {
    CHECK(62, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){17, 16, "unreachable code"}) )
  }
  
  Bool _Bool61;
  CHECK(64, String_equal(keyword, &(String){3, 2, "if"}, &(_Bool61)) )
  if (_Bool61) {
    if ((*end) != ' ') {
      CHECK(66, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after \"if\", got"}, (*end)) )
    }
    CHECK(67, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
    CHECK(68, List_add(self->code_nodes, &(new_if->_base._base)) )
    
  }
  else {
    Bool _Bool62;
    CHECK(70, String_equal(keyword, &(String){5, 4, "else"}, &(_Bool62)) )
    if (_Bool62) {
      if (!(NULL != self->previous_if)) {
        CHECK(72, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){31, 30, "\"else\" without a previous \"if\""}) )
      }
      if ((*end) != '\n') {
        CHECK(74, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected new-line after \"else\", got"}, (*end)) )
      }
      SyntaxTreeElse* _SyntaxTreeElse63;
      CHECK(76, SyntaxTreeElse_parse_new(NULL, self, &((*end)), &(_SyntaxTreeElse63)) )
      CHECK(76, SyntaxTreeIf_add_else(self->previous_if, _SyntaxTreeElse63) )
      
    }
    else {
      Bool _Bool64;
      CHECK(79, String_equal(keyword, &(String){8, 7, "else-if"}, &(_Bool64)) )
      if (_Bool64) {
        if (!(NULL != self->previous_if)) {
          CHECK(81, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){34, 33, "\"else-if\" without a previous \"if\""}) )
        }
        if ((*end) != ' ') {
          CHECK(83, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected space after \"else-if\", got"}, (*end)) )
        }
        SyntaxTreeCoverage* coverage_node = NULL;
        if (NULL != glob->tested_module) {
          Bool _Bool65;
          CHECK(87, String_equal(glob->current_module->name, glob->tested_module, &(_Bool65)) )
          if (_Bool65) {
            CHECK(88, SyntaxTreeCoverage_init_new(NULL, NULL, &(coverage_node)) )
          }
        }
        CHECK(89, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
        CHECK(90, SyntaxTreeIf_add_else_if(self->previous_if, new_if, coverage_node) )
        
      }
      else {
        Bool _Bool66;
        CHECK(92, String_equal(keyword, &(String){3, 2, "do"}, &(_Bool66)) )
        if (_Bool66) {
          if ((*end) != '\n') {
            CHECK(94, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected new-line after \"do\", got"}, (*end)) )
          }
          SyntaxTreeDoLoop* _SyntaxTreeDoLoop67;
          CHECK(96, SyntaxTreeDoLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeDoLoop67)) )
          CHECK(96, List_add(self->code_nodes, &(_SyntaxTreeDoLoop67->_base._base)) )
          
        }
        else {
          Bool _Bool68;
          CHECK(99, String_equal(keyword, &(String){4, 3, "for"}, &(_Bool68)) )
          if (_Bool68) {
            if ((*end) != ' ') {
              CHECK(101, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"for\", got"}, (*end)) )
            }
            SyntaxTreeForLoop* _SyntaxTreeForLoop69;
            CHECK(103, SyntaxTreeForLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeForLoop69)) )
            CHECK(103, List_add(self->code_nodes, &(_SyntaxTreeForLoop69->_base._base)) )
            
          }
          else {
            Bool _Bool70;
            CHECK(106, String_equal(keyword, &(String){6, 5, "while"}, &(_Bool70)) )
            if (_Bool70) {
              if ((*end) != ' ') {
                CHECK(108, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected space after \"while\", got"}, (*end)) )
              }
              SyntaxTreeWhile* _SyntaxTreeWhile71;
              CHECK(110, SyntaxTreeWhile_parse_new(NULL, self, &((*end)), &(_SyntaxTreeWhile71)) )
              CHECK(110, List_add(self->code_nodes, &(_SyntaxTreeWhile71->_base)) )
              
            }
            else {
              Bool _Bool72;
              CHECK(113, String_equal(keyword, &(String){6, 5, "break"}, &(_Bool72)) )
              if (_Bool72) {
                if ((*end) != '\n') {
                  CHECK(115, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){37, 36, "expected new-line after \"break\", got"}, (*end)) )
                }
                SyntaxTreeBreak* _SyntaxTreeBreak73;
                CHECK(117, SyntaxTreeBreak_parse_new(NULL, self, &((*end)), &(_SyntaxTreeBreak73)) )
                CHECK(117, List_add(self->code_nodes, &(_SyntaxTreeBreak73->_base)) )
                
              }
              else {
                Bool _Bool74;
                CHECK(120, String_equal(keyword, &(String){9, 8, "continue"}, &(_Bool74)) )
                if (_Bool74) {
                  if ((*end) != '\n') {
                    CHECK(122, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){40, 39, "expected new-line after \"continue\", got"}, (*end)) )
                  }
                  SyntaxTreeContinue* _SyntaxTreeContinue75;
                  CHECK(124, SyntaxTreeContinue_parse_new(NULL, self, &((*end)), &(_SyntaxTreeContinue75)) )
                  CHECK(124, List_add(self->code_nodes, &(_SyntaxTreeContinue75->_base)) )
                  
                }
                else {
                  Bool _Bool76;
                  CHECK(127, String_equal(keyword, &(String){7, 6, "return"}, &(_Bool76)) )
                  if (_Bool76) {
                    if ((*end) != '\n') {
                      CHECK(129, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){38, 37, "expected new-line after \"return\", got"}, (*end)) )
                    }
                    SyntaxTreeReturn* _SyntaxTreeReturn77;
                    CHECK(131, SyntaxTreeReturn_parse_new(NULL, self, &((*end)), &(_SyntaxTreeReturn77)) )
                    CHECK(131, List_add(self->code_nodes, &(_SyntaxTreeReturn77->_base)) )
                    
                  }
                  else {
                    Bool _Bool78;
                    CHECK(134, String_equal(keyword, &(String){6, 5, "raise"}, &(_Bool78)) )
                    if (_Bool78) {
                      if ((*end) != ' ' && (*end) != '\n') {
                        CHECK(136, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){46, 45, "expected space or new-line after \"raise\", got"}, (*end)) )
                      }
                      SyntaxTreeRaise* _SyntaxTreeRaise79;
                      CHECK(138, SyntaxTreeRaise_parse_new(NULL, self, &((*end)), &(_SyntaxTreeRaise79)) )
                      CHECK(138, List_add(self->code_nodes, &(_SyntaxTreeRaise79->_base)) )
                      
                    }
                    else {
                      Bool _Bool80;
                      CHECK(141, String_equal(keyword, &(String){4, 3, "new"}, &(_Bool80)) )
                      if (_Bool80) {
                        if ((*end) != ' ') {
                          CHECK(143, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"new\", got"}, (*end)) )
                        }
                        SyntaxTreeFunction* _SyntaxTreeFunction81;
                        CHECK(145, (self)->_base._base._dtl[8](self, &(_SyntaxTreeFunction81)) )
                        SyntaxTreeVariable* _SyntaxTreeVariable82;
                        CHECK(145, SyntaxTreeVariable_parse_new(NULL, ACCESS_OWNER, true, NULL, self, &((*end)), &(_SyntaxTreeVariable82)) )
                        CHECK(145, List_add(_SyntaxTreeFunction81->_base._base.variables, _SyntaxTreeVariable82) )
                        
                      }
                      else {
                        Bool _Bool83;
                        CHECK(148, String_equal(keyword, &(String){4, 3, "try"}, &(_Bool83)) )
                        if (_Bool83) {
                          if ((*end) != '\n') {
                            CHECK(150, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){35, 34, "expected new-line after \"try\", got"}, (*end)) )
                          }
                          SyntaxTreeTry* try_node = NULL;
                          CHECK(153, SyntaxTreeTry_parse_new(NULL, self, &((*end)), &(try_node)) )
                          new_try = try_node;
                          CHECK(155, List_add(self->code_nodes, &(try_node->_base._base)) )
                          
                        }
                        else {
                          Bool _Bool84;
                          CHECK(157, String_equal(keyword, &(String){6, 5, "catch"}, &(_Bool84)) )
                          if (_Bool84) {
                            if (!(NULL != self->previous_try)) {
                              CHECK(159, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){33, 32, "\"catch\" without a previous \"try\""}) )
                            }
                            if ((*end) != '\n') {
                              CHECK(161, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){37, 36, "expected new-line after \"catch\", got"}, (*end)) )
                            }
                            SyntaxTreeCatch* catch_node = NULL;
                            CHECK(164, SyntaxTreeCatch_parse_new(NULL, self, &((*end)), &(catch_node)) )
                            self->previous_try->catch_node = catch_node;
                            CHECK(166, List_add(self->code_nodes, &(catch_node->_base._base)) )
                            
                          }
                          else {
                            Bool _Bool85;
                            CHECK(168, String_equal(keyword, &(String){7, 6, "assert"}, &(_Bool85)) )
                            if (_Bool85) {
                              if ((*end) != ' ') {
                                CHECK(170, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){35, 34, "expected space after \"assert\", got"}, (*end)) )
                              }
                              SyntaxTreeAssert* _SyntaxTreeAssert86;
                              CHECK(172, SyntaxTreeAssert_parse_new(NULL, self, &((*end)), &(_SyntaxTreeAssert86)) )
                              CHECK(172, List_add(self->code_nodes, &(_SyntaxTreeAssert86->_base)) )
                              
                            }
                            else {
                              Bool _Bool87;
                              CHECK(175, String_equal(keyword, &(String){13, 12, "assert-error"}, &(_Bool87)) )
                              if (_Bool87) {
                                if ((*end) != ' ') {
                                  CHECK(177, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){41, 40, "expected space after \"assert-error\", got"}, (*end)) )
                                }
                                SyntaxTreeAssertError* _SyntaxTreeAssertError88;
                                CHECK(179, SyntaxTreeAssertError_parse_new(NULL, self, &((*end)), &(_SyntaxTreeAssertError88)) )
                                CHECK(179, List_add(self->code_nodes, &(_SyntaxTreeAssertError88->_base)) )
                                
                              }
                              else {
                                glob->save_input = true;
                                SyntaxTreeExpression* _SyntaxTreeExpression89;
                                CHECK(184, SyntaxTreeExpression_parse_new(NULL, self, &((*end)), &(_SyntaxTreeExpression89)) )
                                CHECK(184, List_add(self->code_nodes, &(_SyntaxTreeExpression89->_base)) )
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
    CHECK(192, (((SyntaxTreeCode*)(self->code_nodes->last->item)))->_base._dtl[5](((SyntaxTreeCode*)(self->code_nodes->last->item)), &((*has_end))) )
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
  CHECK(198, SyntaxTreeBranch_find_variable(&(self->_base), name, module_name, &((*variable))) )
  if (!(NULL != (*variable)) &&  NULL !=  self->parent &&  ! (NULL != module_name)) {
    CHECK(200, (self->parent)->_base._base._dtl[7](self->parent, name, NULL, &((*variable))) )
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
  CHECK(203, (self->parent)->_base._base._dtl[8](self->parent, &((*function))) )
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
  CHECK(206, SyntaxTreeBranch_link_types(&(self->_base)) )
  CHECK(207, SyntaxTreeNode_link_children_types(&(self->_base._base), self->code_nodes) )
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
  CHECK(210, SyntaxTreeBranch_analyze(&(self->_base)) )
  CHECK(211, SyntaxTreeNode_analyze_children(&(self->_base._base), self->code_nodes) )
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
  CHECK(217, SyntaxTreeBlock_write_block_start(self) )
  CHECK(218, (self)->_base._base._dtl[9](self) )
  CHECK(219, SyntaxTreeBlock_write_block_end(self) )
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
  CHECK(222, write(&(String){4, 3, " {\n"}) )
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
  CHECK(225, SyntaxTreeNode_write_children(&(self->_base._base), self->code_nodes) )
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
  CHECK(228, write_spaces(self->_base.indentation_spaces - 2) )
  CHECK(229, write(&(String){3, 2, "}\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeBlock__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeBlock__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeBlock_link_types, (void*)SyntaxTreeBlock_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeBlock_find_variable, (void*)SyntaxTreeBlock_get_function, (void*)SyntaxTreeBlock_write_block_body};
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
