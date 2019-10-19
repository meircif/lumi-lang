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
Returncode SyntaxTreeCode_check_try(SyntaxTreeCode* self, String* statement);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeCode_check_try = "SyntaxTreeCode.check-try";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeCode_check_try
Returncode SyntaxTreeCode_check_try(SyntaxTreeCode* self, String* statement) {
  SyntaxTreeBlock* parent = self->parent;
  while (true) {
    if (!(NULL != parent)) break;
    if (parent->is_try) {
      CHECK(26, SyntaxTreeNode_m_syntax_error(&(self->_base), &(String){30, 29, "inside \"try\" block cannot use"}, statement) )
    }
    parent = parent->parent;
  }
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
  CHECK(31, SyntaxTreeBranch_write_spaces(&(self->parent->_base)) )
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
  CHECK(34, (arguments)->_base._dtl[5](arguments) )
  CHECK(35, write(&(String){3, 2, ";\n"}) )
  CHECK(36, FunctionArguments_write_postactions(arguments) )
  CHECK(37, SyntaxTreeCode_write_spaces(self) )
  CHECK(38, write(&(String){7, 6, "CHECK("}) )
  CHECK(39, SyntaxTreeNode_write_line_num(&(self->_base)) )
  CHECK(40, write(&(String){3, 2, ")\n"}) )
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
  CHECK(44, SyntaxTreeNode_read_line_break_spaces(&(self->_base), self->parent->_base.indentation_spaces) )
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
  Bool is_try;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBlock_parse_block(SyntaxTreeBlock* self, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_parse_block = "SyntaxTreeBlock.parse-block";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBlock_parse_block
Returncode SyntaxTreeBlock_parse_block(SyntaxTreeBlock* self, Char* end) {
  self->code_nodes = malloc(sizeof(List));
  if (self->code_nodes == NULL) RAISE(60)
  *self->code_nodes = (List){NULL, NULL};
  CHECK(61, SyntaxTreeBranch_parse_block_children(&(self->_base), NULL, self, &((*end))) )
  TypeData* _TypeData58;
  CHECK(62, SyntaxTreeBlock_get_parent_type(self, &(_TypeData58)) )
  if (NULL != _TypeData58) {
    self->_base.indentation_spaces -= 4;
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
  CHECK(70, SyntaxTreeBlock_m_has_end_point(self, &(_Bool59)) )
  if (_Bool59) {
    CHECK(71, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){17, 16, "unreachable code"}) )
  }
  
  Bool _Bool60;
  CHECK(73, String_equal(keyword, &(String){3, 2, "if"}, &(_Bool60)) )
  if (_Bool60) {
    if ((*end) != ' ') {
      CHECK(75, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after \"if\", got"}, (*end)) )
    }
    CHECK(76, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
    CHECK(77, List_add(self->code_nodes, &(new_if->_base._base)) )
    
  }
  else {
    Bool _Bool61;
    CHECK(79, String_equal(keyword, &(String){5, 4, "else"}, &(_Bool61)) )
    if (_Bool61) {
      if (!(NULL != self->previous_if)) {
        CHECK(81, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){31, 30, "\"else\" without a previous \"if\""}) )
      }
      if ((*end) != '\n') {
        CHECK(83, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected new-line after \"else\", got"}, (*end)) )
      }
      SyntaxTreeElse* _SyntaxTreeElse62;
      CHECK(85, SyntaxTreeElse_parse_new(NULL, self, &((*end)), &(_SyntaxTreeElse62)) )
      CHECK(85, SyntaxTreeIf_add_else(self->previous_if, _SyntaxTreeElse62) )
      
    }
    else {
      Bool _Bool63;
      CHECK(88, String_equal(keyword, &(String){8, 7, "else-if"}, &(_Bool63)) )
      if (_Bool63) {
        if (!(NULL != self->previous_if)) {
          CHECK(90, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){34, 33, "\"else-if\" without a previous \"if\""}) )
        }
        if ((*end) != ' ') {
          CHECK(92, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected space after \"else-if\", got"}, (*end)) )
        }
        SyntaxTreeCoverage* coverage_node = NULL;
        if (NULL != glob->tested_module) {
          Bool _Bool64;
          CHECK(96, String_equal(glob->current_module->name, glob->tested_module, &(_Bool64)) )
          if (_Bool64) {
            CHECK(97, SyntaxTreeCoverage_init_new(NULL, NULL, &(coverage_node)) )
          }
        }
        CHECK(98, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
        CHECK(99, SyntaxTreeIf_add_else_if(self->previous_if, new_if, coverage_node) )
        
      }
      else {
        Bool _Bool65;
        CHECK(101, String_equal(keyword, &(String){3, 2, "do"}, &(_Bool65)) )
        if (_Bool65) {
          if ((*end) != '\n') {
            CHECK(103, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected new-line after \"do\", got"}, (*end)) )
          }
          SyntaxTreeDoLoop* _SyntaxTreeDoLoop66;
          CHECK(105, SyntaxTreeDoLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeDoLoop66)) )
          CHECK(105, List_add(self->code_nodes, &(_SyntaxTreeDoLoop66->_base._base)) )
          
        }
        else {
          Bool _Bool67;
          CHECK(108, String_equal(keyword, &(String){4, 3, "for"}, &(_Bool67)) )
          if (_Bool67) {
            if ((*end) != ' ') {
              CHECK(110, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"for\", got"}, (*end)) )
            }
            SyntaxTreeForLoop* _SyntaxTreeForLoop68;
            CHECK(112, SyntaxTreeForLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeForLoop68)) )
            CHECK(112, List_add(self->code_nodes, &(_SyntaxTreeForLoop68->_base._base)) )
            
          }
          else {
            Bool _Bool69;
            CHECK(115, String_equal(keyword, &(String){6, 5, "while"}, &(_Bool69)) )
            if (_Bool69) {
              if ((*end) != ' ') {
                CHECK(117, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected space after \"while\", got"}, (*end)) )
              }
              SyntaxTreeWhile* _SyntaxTreeWhile70;
              CHECK(119, SyntaxTreeWhile_parse_new(NULL, self, &((*end)), &(_SyntaxTreeWhile70)) )
              CHECK(119, List_add(self->code_nodes, &(_SyntaxTreeWhile70->_base)) )
              
            }
            else {
              Bool _Bool71;
              CHECK(122, String_equal(keyword, &(String){6, 5, "break"}, &(_Bool71)) )
              if (_Bool71) {
                if ((*end) != '\n') {
                  CHECK(124, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){37, 36, "expected new-line after \"break\", got"}, (*end)) )
                }
                SyntaxTreeBreak* _SyntaxTreeBreak72;
                CHECK(126, SyntaxTreeBreak_parse_new(NULL, self, &((*end)), &(_SyntaxTreeBreak72)) )
                CHECK(126, List_add(self->code_nodes, &(_SyntaxTreeBreak72->_base)) )
                
              }
              else {
                Bool _Bool73;
                CHECK(129, String_equal(keyword, &(String){9, 8, "continue"}, &(_Bool73)) )
                if (_Bool73) {
                  if ((*end) != '\n') {
                    CHECK(131, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){40, 39, "expected new-line after \"continue\", got"}, (*end)) )
                  }
                  SyntaxTreeContinue* _SyntaxTreeContinue74;
                  CHECK(133, SyntaxTreeContinue_parse_new(NULL, self, &((*end)), &(_SyntaxTreeContinue74)) )
                  CHECK(133, List_add(self->code_nodes, &(_SyntaxTreeContinue74->_base)) )
                  
                }
                else {
                  Bool _Bool75;
                  CHECK(136, String_equal(keyword, &(String){7, 6, "return"}, &(_Bool75)) )
                  if (_Bool75) {
                    if ((*end) != '\n') {
                      CHECK(138, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){38, 37, "expected new-line after \"return\", got"}, (*end)) )
                    }
                    SyntaxTreeReturn* _SyntaxTreeReturn76;
                    CHECK(140, SyntaxTreeReturn_parse_new(NULL, self, &((*end)), &(_SyntaxTreeReturn76)) )
                    CHECK(140, List_add(self->code_nodes, &(_SyntaxTreeReturn76->_base)) )
                    
                  }
                  else {
                    Bool _Bool77;
                    CHECK(143, String_equal(keyword, &(String){6, 5, "raise"}, &(_Bool77)) )
                    if (_Bool77) {
                      if ((*end) != ' ' && (*end) != '\n') {
                        CHECK(145, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){46, 45, "expected space or new-line after \"raise\", got"}, (*end)) )
                      }
                      SyntaxTreeRaise* _SyntaxTreeRaise78;
                      CHECK(147, SyntaxTreeRaise_parse_new(NULL, self, &((*end)), &(_SyntaxTreeRaise78)) )
                      CHECK(147, List_add(self->code_nodes, &(_SyntaxTreeRaise78->_base)) )
                      
                    }
                    else {
                      Bool _Bool79;
                      CHECK(150, String_equal(keyword, &(String){4, 3, "new"}, &(_Bool79)) )
                      if (_Bool79) {
                        if ((*end) != ' ') {
                          CHECK(152, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"new\", got"}, (*end)) )
                        }
                        SyntaxTreeFunction* _SyntaxTreeFunction80;
                        CHECK(154, (self)->_base._base._dtl[8](self, &(_SyntaxTreeFunction80)) )
                        SyntaxTreeVariable* _SyntaxTreeVariable81;
                        CHECK(154, SyntaxTreeVariable_parse_new(NULL, ACCESS_OWNER, true, NULL, self, &((*end)), &(_SyntaxTreeVariable81)) )
                        CHECK(154, List_add(_SyntaxTreeFunction80->_base._base.variables, _SyntaxTreeVariable81) )
                        
                      }
                      else {
                        Bool _Bool82;
                        CHECK(157, String_equal(keyword, &(String){4, 3, "try"}, &(_Bool82)) )
                        if (_Bool82) {
                          if ((*end) != '\n') {
                            CHECK(159, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){35, 34, "expected new-line after \"try\", got"}, (*end)) )
                          }
                          SyntaxTreeTry* try_node = NULL;
                          CHECK(162, SyntaxTreeTry_parse_new(NULL, self, &((*end)), &(try_node)) )
                          new_try = try_node;
                          CHECK(164, List_add(self->code_nodes, &(try_node->_base._base)) )
                          
                        }
                        else {
                          Bool _Bool83;
                          CHECK(166, String_equal(keyword, &(String){6, 5, "catch"}, &(_Bool83)) )
                          if (_Bool83) {
                            if (!(NULL != self->previous_try)) {
                              CHECK(168, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){33, 32, "\"catch\" without a previous \"try\""}) )
                            }
                            if ((*end) != '\n') {
                              CHECK(170, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){37, 36, "expected new-line after \"catch\", got"}, (*end)) )
                            }
                            SyntaxTreeCatch* catch_node = NULL;
                            CHECK(173, SyntaxTreeCatch_parse_new(NULL, self, &((*end)), &(catch_node)) )
                            self->previous_try->catch_node = catch_node;
                            CHECK(175, List_add(self->code_nodes, &(catch_node->_base._base)) )
                            
                          }
                          else {
                            Bool _Bool84;
                            CHECK(177, String_equal(keyword, &(String){7, 6, "assert"}, &(_Bool84)) )
                            if (_Bool84) {
                              if ((*end) != ' ') {
                                CHECK(179, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){35, 34, "expected space after \"assert\", got"}, (*end)) )
                              }
                              SyntaxTreeAssert* _SyntaxTreeAssert85;
                              CHECK(181, SyntaxTreeAssert_parse_new(NULL, self, &((*end)), &(_SyntaxTreeAssert85)) )
                              CHECK(181, List_add(self->code_nodes, &(_SyntaxTreeAssert85->_base)) )
                              
                            }
                            else {
                              Bool _Bool86;
                              CHECK(184, String_equal(keyword, &(String){13, 12, "assert-error"}, &(_Bool86)) )
                              if (_Bool86) {
                                if ((*end) != ' ') {
                                  CHECK(186, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){41, 40, "expected space after \"assert-error\", got"}, (*end)) )
                                }
                                SyntaxTreeAssertError* _SyntaxTreeAssertError87;
                                CHECK(188, SyntaxTreeAssertError_parse_new(NULL, self, &((*end)), &(_SyntaxTreeAssertError87)) )
                                CHECK(188, List_add(self->code_nodes, &(_SyntaxTreeAssertError87->_base)) )
                                
                              }
                              else {
                                glob->save_input = true;
                                SyntaxTreeExpression* _SyntaxTreeExpression88;
                                CHECK(193, SyntaxTreeExpression_parse_new(NULL, self, &((*end)), &(_SyntaxTreeExpression88)) )
                                CHECK(193, List_add(self->code_nodes, &(_SyntaxTreeExpression88->_base)) )
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
    CHECK(201, (((SyntaxTreeCode*)(self->code_nodes->last->item)))->_base._dtl[5](((SyntaxTreeCode*)(self->code_nodes->last->item)), &((*has_end))) )
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
  CHECK(207, SyntaxTreeBranch_find_variable(&(self->_base), name, module_name, &((*variable))) )
  if (!(NULL != (*variable)) &&  NULL !=  self->parent &&  ! (NULL != module_name)) {
    CHECK(209, (self->parent)->_base._base._dtl[7](self->parent, name, NULL, &((*variable))) )
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
  CHECK(212, (self->parent)->_base._base._dtl[8](self->parent, &((*function))) )
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
  CHECK(215, (self)->_base._base._dtl[8](self, &(_SyntaxTreeFunction89)) )
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
  CHECK(218, SyntaxTreeBranch_link_types(&(self->_base)) )
  CHECK(219, SyntaxTreeNode_link_children_types(&(self->_base._base), self->code_nodes) )
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
  CHECK(222, SyntaxTreeBranch_analyze(&(self->_base)) )
  CHECK(223, SyntaxTreeNode_analyze_children(&(self->_base._base), self->code_nodes) )
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
  CHECK(229, SyntaxTreeBlock_write_block_start(self) )
  CHECK(230, (self)->_base._base._dtl[9](self) )
  CHECK(231, SyntaxTreeBlock_write_block_end(self) )
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
  CHECK(234, write(&(String){4, 3, " {\n"}) )
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
  CHECK(237, SyntaxTreeNode_write_children(&(self->_base._base), self->code_nodes) )
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
  CHECK(240, write_spaces(self->_base.indentation_spaces - 4) )
  CHECK(241, write(&(String){3, 2, "}\n"}) )
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
