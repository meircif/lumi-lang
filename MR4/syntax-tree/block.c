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
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCode_m_find_variable(SyntaxTreeCode* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCode_m_find_variable = "SyntaxTreeCode.m-find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeCode_m_find_variable
Returncode SyntaxTreeCode_m_find_variable(SyntaxTreeCode* self, String* name, SyntaxTreeVariable** variable) {
  CHECK(9, (self->parent)->_base._base._dtl[3](self->parent, name, &((*variable))) )
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
  CHECK(12, (self->parent)->_base._base._dtl[4](self->parent, &((*parent_type))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCode_analyze_expression(SyntaxTreeCode* self, Expression* expression, TypeData* expected_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCode_analyze_expression = "SyntaxTreeCode.analyze-expression";
#define MR_FUNC_NAME _func_name_SyntaxTreeCode_analyze_expression
Returncode SyntaxTreeCode_analyze_expression(SyntaxTreeCode* self, Expression* expression, TypeData* expected_type) {
  CHECK(16, (expression)->_base._dtl[0](expression) )
  if (!(NULL != expression->result_type)) {
    CHECK(18, SyntaxTreeNode_m_syntax_error(&(self->_base), &(String){30, 29, "got void expression, expected"}, expected_type->name) )
  }
  if (expression->result_type->type_data != expected_type) {
    CHECK(21, SyntaxTreeNode_m_syntax_error2(&(self->_base), &(String){4, 3, "got"}, expression->result_type->type_data->name, &(String){21, 20, "expression, expected"}, expected_type->name) )
  }
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
  CHECK(28, SyntaxTreeBranch_write_spaces(&(self->parent->_base)) )
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
Func SyntaxTreeCode__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write, (void*)SyntaxTreeCode_m_is_end_point};
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
  if (self->code_nodes == NULL) RAISE(50)
  *self->code_nodes = (List){NULL, NULL};
  CHECK(51, SyntaxTreeBranch_parse_block_children(&(self->_base), NULL, self, &((*end))) )
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
  CHECK(57, SyntaxTreeBlock_m_has_end_point(self, &(_Bool36)) )
  if (_Bool36) {
    CHECK(58, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){17, 16, "unreachable code"}) )
  }
  
  Bool _Bool37;
  CHECK(60, String_equal(keyword, &(String){3, 2, "if"}, &(_Bool37)) )
  if (_Bool37) {
    if ((*end) != ' ') {
      CHECK(62, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after \"if\", got"}, (*end)) )
    }
    CHECK(63, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
    CHECK(64, List_add(self->code_nodes, &(new_if->_base._base)) )
    
  }
  else {
    Bool _Bool38;
    CHECK(66, String_equal(keyword, &(String){5, 4, "else"}, &(_Bool38)) )
    if (_Bool38) {
      if (!(NULL != self->previous_if)) {
        CHECK(68, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){31, 30, "\"else\" without a previous \"if\""}) )
      }
      if ((*end) != '\n') {
        CHECK(70, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected new-line after \"else\", got"}, (*end)) )
      }
      SyntaxTreeElse* _SyntaxTreeElse39;
      CHECK(72, SyntaxTreeElse_parse_new(NULL, self, &((*end)), &(_SyntaxTreeElse39)) )
      CHECK(72, SyntaxTreeIf_add_else(self->previous_if, _SyntaxTreeElse39) )
      
    }
    else {
      Bool _Bool40;
      CHECK(75, String_equal(keyword, &(String){8, 7, "else-if"}, &(_Bool40)) )
      if (_Bool40) {
        if (!(NULL != self->previous_if)) {
          CHECK(77, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){34, 33, "\"else-if\" without a previous \"if\""}) )
        }
        if ((*end) != ' ') {
          CHECK(79, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){36, 35, "expected space after \"else-if\", got"}, (*end)) )
        }
        CHECK(81, SyntaxTreeIf_parse_new(NULL, self, &((*end)), &(new_if)) )
        CHECK(82, SyntaxTreeIf_add_else_if(self->previous_if, new_if) )
        
      }
      else {
        Bool _Bool41;
        CHECK(84, String_equal(keyword, &(String){3, 2, "do"}, &(_Bool41)) )
        if (_Bool41) {
          if ((*end) != '\n') {
            CHECK(86, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected new-line after \"do\", got"}, (*end)) )
          }
          SyntaxTreeDoLoop* _SyntaxTreeDoLoop42;
          CHECK(88, SyntaxTreeDoLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeDoLoop42)) )
          CHECK(88, List_add(self->code_nodes, &(_SyntaxTreeDoLoop42->_base._base)) )
          
        }
        else {
          Bool _Bool43;
          CHECK(91, String_equal(keyword, &(String){4, 3, "for"}, &(_Bool43)) )
          if (_Bool43) {
            if ((*end) != ' ') {
              CHECK(93, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"for\", got"}, (*end)) )
            }
            SyntaxTreeForLoop* _SyntaxTreeForLoop44;
            CHECK(95, SyntaxTreeForLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeForLoop44)) )
            CHECK(95, List_add(self->code_nodes, &(_SyntaxTreeForLoop44->_base._base)) )
            
          }
          else {
            Bool _Bool45;
            CHECK(98, String_equal(keyword, &(String){6, 5, "while"}, &(_Bool45)) )
            if (_Bool45) {
              if ((*end) != ' ') {
                CHECK(100, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){34, 33, "expected space after \"while\", got"}, (*end)) )
              }
              SyntaxTreeWhile* _SyntaxTreeWhile46;
              CHECK(102, SyntaxTreeWhile_parse_new(NULL, self, &((*end)), &(_SyntaxTreeWhile46)) )
              CHECK(102, List_add(self->code_nodes, &(_SyntaxTreeWhile46->_base)) )
              
            }
            else {
              Bool _Bool47;
              CHECK(105, String_equal(keyword, &(String){9, 8, "continue"}, &(_Bool47)) )
              if (_Bool47) {
                if ((*end) != '\n') {
                  CHECK(107, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){40, 39, "expected new-line after \"continue\", got"}, (*end)) )
                }
                SyntaxTreeContinue* _SyntaxTreeContinue48;
                CHECK(109, SyntaxTreeContinue_parse_new(NULL, self, &((*end)), &(_SyntaxTreeContinue48)) )
                CHECK(109, List_add(self->code_nodes, &(_SyntaxTreeContinue48->_base)) )
                
              }
              else {
                Bool _Bool49;
                CHECK(112, String_equal(keyword, &(String){7, 6, "return"}, &(_Bool49)) )
                if (_Bool49) {
                  if ((*end) != '\n') {
                    CHECK(114, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){38, 37, "expected new-line after \"return\", got"}, (*end)) )
                  }
                  SyntaxTreeReturn* _SyntaxTreeReturn50;
                  CHECK(116, SyntaxTreeReturn_parse_new(NULL, self, &((*end)), &(_SyntaxTreeReturn50)) )
                  CHECK(116, List_add(self->code_nodes, &(_SyntaxTreeReturn50->_base)) )
                  
                }
                else {
                  Bool _Bool51;
                  CHECK(119, String_equal(keyword, &(String){6, 5, "raise"}, &(_Bool51)) )
                  if (_Bool51) {
                    if ((*end) != '\n') {
                      CHECK(121, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){37, 36, "expected new-line after \"raise\", got"}, (*end)) )
                    }
                    SyntaxTreeRaise* _SyntaxTreeRaise52;
                    CHECK(123, SyntaxTreeRaise_parse_new(NULL, self, &((*end)), &(_SyntaxTreeRaise52)) )
                    CHECK(123, List_add(self->code_nodes, &(_SyntaxTreeRaise52->_base)) )
                    
                  }
                  else {
                    Bool _Bool53;
                    CHECK(126, String_equal(keyword, &(String){4, 3, "new"}, &(_Bool53)) )
                    if (_Bool53) {
                      if ((*end) != ' ') {
                        CHECK(128, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){32, 31, "expected space after \"new\", got"}, (*end)) )
                      }
                      SyntaxTreeVariable* _SyntaxTreeVariable54;
                      CHECK(130, SyntaxTreeVariable_parse_new(NULL, ACCESS_OWNER, NULL, self, &((*end)), &(_SyntaxTreeVariable54)) )
                      CHECK(130, List_add(self->_base.variables, _SyntaxTreeVariable54) )
                      
                    }
                    else {
                      glob->save_input = true;
                      SyntaxTreeExpression* _SyntaxTreeExpression55;
                      CHECK(135, SyntaxTreeExpression_parse_new(NULL, self, &((*end)), &(_SyntaxTreeExpression55)) )
                      CHECK(135, List_add(self->code_nodes, &(_SyntaxTreeExpression55->_base)) )
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
    CHECK(142, (((SyntaxTreeCode*)(self->code_nodes->last->item)))->_base._dtl[2](((SyntaxTreeCode*)(self->code_nodes->last->item)), &((*has_end))) )
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
  CHECK(148, SyntaxTreeBranch_m_find_variable(&(self->_base), name, &((*variable))) )
  if (!(NULL != (*variable)) &&  NULL !=  self->ref_variable) {
    Bool _Bool56;
    CHECK(150, SyntaxTreeVariable_m_find_variable(self->ref_variable, name, &((*variable)), &(_Bool56)) )
  }
  if (!(NULL != (*variable)) &&  NULL !=  self->parent) {
    CHECK(152, (self->parent)->_base._base._dtl[3](self->parent, name, &((*variable))) )
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
  CHECK(155, (self->parent)->_base._base._dtl[4](self->parent, &((*parent_type))) )
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
    if (type_count == NULL) RAISE(169)
    *type_count = (TypeCount){NULL, 0};
    type_count->type_data = type_instance->type_data;
    CHECK(171, List_add(self->aux_variables, type_count) )
  }
  SyntaxTreeVariable* variable = malloc(sizeof(SyntaxTreeVariable));
  if (variable == NULL) RAISE(172)
  *variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL};
  variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  variable->name = _new_string(type_instance->type_data->name->length + 21);
  if (variable->name == NULL) RAISE(173)
  CHECK(175, String_copy(variable->name, &(String){5, 4, "aux_"}) )
  CHECK(176, String_concat(variable->name, type_instance->type_data->name) )
  CHECK(177, String_append(variable->name, '_') )
  String* index_str = &(String){16, 0, (char[16]){0}};
  CHECK(179, Int_str(index, index_str) )
  CHECK(180, String_concat(variable->name, index_str) )
  variable->_base.parent = self;
  if (access == ACCESS_COPY) {
    variable->access = ACCESS_VAR;
  }
  else {
    variable->access = access;
  }
  CHECK(186, TypeInstance_m_copy_new(type_instance, &(variable->type_instance)) )
  (*new_variable) = variable;
  CHECK(188, List_add(self->_base.variables, variable) )
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
  CHECK(191, SyntaxTreeBranch_analyze(&(self->_base)) )
  CHECK(192, SyntaxTreeBranch_analyze_children(&(self->_base), self->code_nodes) )
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
  CHECK(198, write(&(String){4, 3, " {\n"}) )
  CHECK(199, SyntaxTreeBranch_write(&(self->_base)) )
  CHECK(200, SyntaxTreeBranch_write_children(&(self->_base), self->code_nodes) )
  CHECK(201, write_spaces(self->_base.indentation_spaces - 2) )
  CHECK(202, write(&(String){2, 1, "}"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBlock__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBlock__dtl[] = {(void*)SyntaxTreeBlock_analyze, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeBlock_m_find_variable, (void*)SyntaxTreeBlock_m_get_parent_type};
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
