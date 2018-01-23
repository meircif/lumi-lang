#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/code-flow.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file19_name = "syntax-tree/code-flow.3.mr";
#endif
#define MR_FILE_NAME _mr_file19_name

/* MR4 compiler - Syntax tree code flow elements */

/* Basic code flow element node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeFlowElement SyntaxTreeFlowElement;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeFlowElement {
  SyntaxTreeCode _base;
  SyntaxTreeBlock* block;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFlowElement_init(SyntaxTreeFlowElement* self, SyntaxTreeBlock* parent);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_init = "SyntaxTreeFlowElement.init";
#define MR_FUNC_NAME _func_name_SyntaxTreeFlowElement_init
Returncode SyntaxTreeFlowElement_init(SyntaxTreeFlowElement* self, SyntaxTreeBlock* parent) {
  self->block = malloc(sizeof(SyntaxTreeBlock));
  if (self->block == NULL) RAISE(8)
  *self->block = (SyntaxTreeBlock){SyntaxTreeBlock__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, false};
  self->block->_base._base._dtl = SyntaxTreeBlock__dtl;
  CHECK(9, SyntaxTreeFlowElement_set_parent(self, parent) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFlowElement_set_parent(SyntaxTreeFlowElement* self, SyntaxTreeBlock* parent);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_set_parent = "SyntaxTreeFlowElement.set-parent";
#define MR_FUNC_NAME _func_name_SyntaxTreeFlowElement_set_parent
Returncode SyntaxTreeFlowElement_set_parent(SyntaxTreeFlowElement* self, SyntaxTreeBlock* parent) {
  self->_base.parent = parent;
  self->block->parent = parent;
  self->block->_base.indentation_spaces = parent->_base.indentation_spaces + 2;
  self->block->is_in_loop = parent->is_in_loop;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFlowElement_parse_block(SyntaxTreeFlowElement* self, SyntaxTreeBlock* parent, Bool is_loop, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_parse_block = "SyntaxTreeFlowElement.parse-block";
#define MR_FUNC_NAME _func_name_SyntaxTreeFlowElement_parse_block
Returncode SyntaxTreeFlowElement_parse_block(SyntaxTreeFlowElement* self, SyntaxTreeBlock* parent, Bool is_loop, Char* end) {
  CHECK(19, SyntaxTreeFlowElement_init(self, parent) )
  if (is_loop) {
    self->block->is_in_loop = true;
  }
  CHECK(22, SyntaxTreeBlock_parse_block(self->block, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFlowElement_link_types(SyntaxTreeFlowElement* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_link_types = "SyntaxTreeFlowElement.link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeFlowElement_link_types
Returncode SyntaxTreeFlowElement_link_types(SyntaxTreeFlowElement* self) {
  CHECK(25, (self->block)->_base._base._dtl[1](self->block) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFlowElement_analyze(SyntaxTreeFlowElement* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_analyze = "SyntaxTreeFlowElement.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeFlowElement_analyze
Returncode SyntaxTreeFlowElement_analyze(SyntaxTreeFlowElement* self) {
  CHECK(28, (self->block)->_base._base._dtl[2](self->block) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFlowElement_write_block(SyntaxTreeFlowElement* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_write_block = "SyntaxTreeFlowElement.write-block";
#define MR_FUNC_NAME _func_name_SyntaxTreeFlowElement_write_block
Returncode SyntaxTreeFlowElement_write_block(SyntaxTreeFlowElement* self) {
  CHECK(31, SyntaxTreeBlock_write_block(self->block) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFlowElement_write_block_body(SyntaxTreeFlowElement* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_write_block_body = "SyntaxTreeFlowElement.write-block-body";
#define MR_FUNC_NAME _func_name_SyntaxTreeFlowElement_write_block_body
Returncode SyntaxTreeFlowElement_write_block_body(SyntaxTreeFlowElement* self) {
  CHECK(34, SyntaxTreeBlock_write_block_body(self->block) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeFlowElement__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeFlowElement__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeFlowElement_link_types, (void*)SyntaxTreeFlowElement_analyze, (void*)SyntaxTreeNode_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* If statement node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeIf SyntaxTreeIf;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeIf {
  SyntaxTreeFlowElement _base;
  Expression* condition;
  SyntaxTreeElse* else_node;
/* if (`condition`) { *//*   `block...` *//* } *//* `else-block` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeIf_parse_new(SyntaxTreeIf* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeIf** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeIf_parse_new = "SyntaxTreeIf.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeIf_parse_new
Returncode SyntaxTreeIf_parse_new(SyntaxTreeIf* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeIf** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeIf));
  if ((*new_node) == NULL) RAISE(44)
  *(*new_node) = (SyntaxTreeIf){SyntaxTreeIf__dtl, NULL, 0, NULL, NULL, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeIf__dtl;
  CHECK(45, SyntaxTreeIf_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeIf_parse(SyntaxTreeIf* self, SyntaxTreeBlock* parent, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeIf_parse = "SyntaxTreeIf.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeIf_parse
Returncode SyntaxTreeIf_parse(SyntaxTreeIf* self, SyntaxTreeBlock* parent, Char* end) {
  CHECK(48, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(49, parse_new_expression(&(String){1, 0, ""}, &(self->_base._base), &(self->condition), &((*end))) )
  CHECK(50, SyntaxTreeFlowElement_parse_block(&(self->_base), parent, false, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeIf_add_else(SyntaxTreeIf* self, SyntaxTreeElse* else_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeIf_add_else = "SyntaxTreeIf.add-else";
#define MR_FUNC_NAME _func_name_SyntaxTreeIf_add_else
Returncode SyntaxTreeIf_add_else(SyntaxTreeIf* self, SyntaxTreeElse* else_node) {
  CHECK(53, SyntaxTreeFlowElement_set_parent(&(else_node->_base), self->_base._base.parent) )
  self->else_node = else_node;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeIf_add_else_if(SyntaxTreeIf* self, SyntaxTreeIf* new_if);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeIf_add_else_if = "SyntaxTreeIf.add-else-if";
#define MR_FUNC_NAME _func_name_SyntaxTreeIf_add_else_if
Returncode SyntaxTreeIf_add_else_if(SyntaxTreeIf* self, SyntaxTreeIf* new_if) {
  self->else_node = malloc(sizeof(SyntaxTreeElse));
  if (self->else_node == NULL) RAISE(57)
  *self->else_node = (SyntaxTreeElse){SyntaxTreeElse__dtl, NULL, 0, NULL, NULL};
  self->else_node->_base._base._base._dtl = SyntaxTreeElse__dtl;
  CHECK(58, SyntaxTreeFlowElement_init(&(self->else_node->_base), self->_base._base.parent) )
  self->else_node->_base.block->_base.variables = malloc(sizeof(List));
  if (self->else_node->_base.block->_base.variables == NULL) RAISE(59)
  *self->else_node->_base.block->_base.variables = (List){NULL, NULL};
  self->else_node->_base.block->code_nodes = malloc(sizeof(List));
  if (self->else_node->_base.block->code_nodes == NULL) RAISE(60)
  *self->else_node->_base.block->code_nodes = (List){NULL, NULL};
  CHECK(61, List_add(self->else_node->_base.block->code_nodes, &(new_if->_base._base)) )
  CHECK(62, SyntaxTreeFlowElement_set_parent(&(new_if->_base), self->else_node->_base.block) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeIf_analyze(SyntaxTreeIf* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeIf_analyze = "SyntaxTreeIf.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeIf_analyze
Returncode SyntaxTreeIf_analyze(SyntaxTreeIf* self) {
  CHECK(65, SyntaxTreeNode_analyze_expression(&(self->_base._base._base), self->condition, &(glob->type_bool->_base)) )
  CHECK(66, SyntaxTreeFlowElement_analyze(&(self->_base)) )
  if (NULL != self->else_node) {
    CHECK(68, (self->else_node)->_base._base._base._dtl[2](self->else_node) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/* if (`condition`) { *//*   `block...` *//* } *//* `else-block` */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeIf_write(SyntaxTreeIf* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeIf_write = "SyntaxTreeIf.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeIf_write
Returncode SyntaxTreeIf_write(SyntaxTreeIf* self) {
  CHECK(75, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(76, (self->condition)->_base._dtl[7](self->condition) )
  CHECK(77, write(&(String){5, 4, "if ("}) )
  CHECK(78, (self->condition)->_base._dtl[3](self->condition) )
  CHECK(79, write(&(String){2, 1, ")"}) )
  CHECK(80, SyntaxTreeFlowElement_write_block(&(self->_base)) )
  if (NULL != self->else_node) {
    CHECK(82, (self->else_node)->_base._base._base._dtl[3](self->else_node) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeIf__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeIf__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeFlowElement_link_types, (void*)SyntaxTreeIf_analyze, (void*)SyntaxTreeIf_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Else statement node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeElse SyntaxTreeElse;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeElse {
  SyntaxTreeFlowElement _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeElse_parse_new(SyntaxTreeElse* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeElse** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeElse_parse_new = "SyntaxTreeElse.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeElse_parse_new
Returncode SyntaxTreeElse_parse_new(SyntaxTreeElse* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeElse** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeElse));
  if ((*new_node) == NULL) RAISE(89)
  *(*new_node) = (SyntaxTreeElse){SyntaxTreeElse__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeElse__dtl;
  CHECK(90, SyntaxTreeNode_set_location(&((*new_node)->_base._base._base)) )
  CHECK(91, SyntaxTreeFlowElement_parse_block(&((*new_node)->_base), parent, false, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeElse_write(SyntaxTreeElse* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeElse_write = "SyntaxTreeElse.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeElse_write
Returncode SyntaxTreeElse_write(SyntaxTreeElse* self) {
  /* else { */
  /*   `block...` */
  /* } */
  CHECK(97, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(98, write(&(String){5, 4, "else"}) )
  CHECK(99, SyntaxTreeFlowElement_write_block(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeElse__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeElse__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeFlowElement_link_types, (void*)SyntaxTreeFlowElement_analyze, (void*)SyntaxTreeElse_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Do loop node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeDoLoop SyntaxTreeDoLoop;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeDoLoop {
  SyntaxTreeFlowElement _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeDoLoop_parse_new(SyntaxTreeDoLoop* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeDoLoop** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeDoLoop_parse_new = "SyntaxTreeDoLoop.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeDoLoop_parse_new
Returncode SyntaxTreeDoLoop_parse_new(SyntaxTreeDoLoop* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeDoLoop** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeDoLoop));
  if ((*new_node) == NULL) RAISE(106)
  *(*new_node) = (SyntaxTreeDoLoop){SyntaxTreeDoLoop__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeDoLoop__dtl;
  CHECK(107, SyntaxTreeNode_set_location(&((*new_node)->_base._base._base)) )
  CHECK(108, SyntaxTreeFlowElement_parse_block(&((*new_node)->_base), parent, true, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeDoLoop_write(SyntaxTreeDoLoop* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeDoLoop_write = "SyntaxTreeDoLoop.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeDoLoop_write
Returncode SyntaxTreeDoLoop_write(SyntaxTreeDoLoop* self) {
  /* while (true) { */
  /*   `block...` */
  /* } */
  CHECK(114, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(115, write(&(String){13, 12, "while (true)"}) )
  CHECK(116, SyntaxTreeFlowElement_write_block(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeDoLoop__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeDoLoop__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeFlowElement_link_types, (void*)SyntaxTreeFlowElement_analyze, (void*)SyntaxTreeDoLoop_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* For loop node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeForLoop SyntaxTreeForLoop;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeForLoop {
  SyntaxTreeFlowElement _base;
  String* item_name;
  Expression* start;
  Expression* iterator;
  TypeData* item_type;
  SyntaxTreeFunction* has_func;
  SyntaxTreeFunction* get_func;
  SyntaxTreeFunction* next_func;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_parse_new(SyntaxTreeForLoop* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeForLoop** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_parse_new = "SyntaxTreeForLoop.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_parse_new
Returncode SyntaxTreeForLoop_parse_new(SyntaxTreeForLoop* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeForLoop** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeForLoop));
  if ((*new_node) == NULL) RAISE(131)
  *(*new_node) = (SyntaxTreeForLoop){SyntaxTreeForLoop__dtl, NULL, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeForLoop__dtl;
  CHECK(132, SyntaxTreeForLoop_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_parse(SyntaxTreeForLoop* self, SyntaxTreeBlock* parent, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_parse = "SyntaxTreeForLoop.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_parse
Returncode SyntaxTreeForLoop_parse(SyntaxTreeForLoop* self, SyntaxTreeBlock* parent, Char* end) {
  CHECK(135, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(136, read_new(&(String){2, 1, " "}, &(self->item_name), &((*end))) )
  if ((*end) != ' ') {
    CHECK(138, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){37, 36, "expected space after index name, got"}, (*end)) )
  }
  CHECK(140, SyntaxTreeNode_read_expect(&(self->_base._base._base), &(String){4, 3, "in "}) )
  CHECK(141, parse_new_expression(&(String){2, 1, ":"}, &(self->_base._base), &(self->iterator), &((*end))) )
  if ((*end) == ':') {
    self->start = self->iterator;
    CHECK(144, parse_new_expression(&(String){1, 0, ""}, &(self->_base._base), &(self->iterator), &((*end))) )
  }
  CHECK(145, SyntaxTreeFlowElement_parse_block(&(self->_base), parent, true, &((*end))) )
  self->_base.block->ref_variable = malloc(sizeof(SyntaxTreeVariable));
  if (self->_base.block->ref_variable == NULL) RAISE(146)
  *self->_base.block->ref_variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false, false, false};
  self->_base.block->ref_variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  CHECK(147, string_new_copy(self->item_name, &(self->_base.block->ref_variable->name)) )
  CHECK(148, SyntaxTreeVariable_check_name(self->_base.block->ref_variable) )
  self->_base.block->ref_variable->access = ACCESS_VAR;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_analyze(SyntaxTreeForLoop* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_analyze = "SyntaxTreeForLoop.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_analyze
Returncode SyntaxTreeForLoop_analyze(SyntaxTreeForLoop* self) {
  if (NULL != self->start) {
    CHECK(153, SyntaxTreeNode_analyze_expression(&(self->_base._base._base), self->start, &(glob->type_int->_base)) )
    CHECK(154, SyntaxTreeNode_analyze_expression(&(self->_base._base._base), self->iterator, &(glob->type_int->_base)) )
    self->item_type = &(glob->type_int->_base);
  }
  else {
    CHECK(157, (self->iterator)->_base._dtl[2](self->iterator) )
    if (!(NULL != self->iterator->result_type)) {
      CHECK(159, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){31, 30, "cannot iterate void expression"}) )
    }
    if (self->iterator->result_type->type_data == &(glob->type_int->_base)) {
      self->item_type = &(glob->type_int->_base);
    }
    else {
      if (self->iterator->result_type->type_data == &(glob->type_string->_base)) {
        self->item_type = &(glob->type_char->_base);
      }
      else {
        if (self->iterator->result_type->type_data == &(glob->type_array->_base)) {
          self->item_type = ((TypeInstance*)(self->iterator->result_type->parameters->first->item))->type_data;
        }
        else {
          CHECK(168, SyntaxTreeForLoop_check_iterator_type(self) )
        }
      }
    }
  }
  CHECK(169, TypeData_m_new_type_instance(self->item_type, &(self->_base.block->ref_variable->type_instance)) )
  CHECK(171, SyntaxTreeFlowElement_analyze(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_check_iterator_type(SyntaxTreeForLoop* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_check_iterator_type = "SyntaxTreeForLoop.check-iterator-type";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_check_iterator_type
Returncode SyntaxTreeForLoop_check_iterator_type(SyntaxTreeForLoop* self) {
  Int _Int91;
  CHECK(174, TypeData_find_meth(self->iterator->result_type->type_data, &(String){4, 3, "has"}, &(self->has_func), &(_Int91)) )
  if (!(NULL != self->has_func)) {
    CHECK(177, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){50, 49, "cannot iterate type with no \"has\" named method - "}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->has_func->arguments->parameters->first->next) {
    CHECK(181, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){45, 44, "iterator \"has\" method has parameters in type"}, self->iterator->result_type->type_data->name) )
  }
  if (!(NULL != self->has_func->arguments->outputs->first)) {
    CHECK(185, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){45, 44, "iterator \"has\" method has no outputs in type"}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->has_func->arguments->outputs->first->next) {
    CHECK(189, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){55, 54, "iterator \"has\" method has more than one output in type"}, self->iterator->result_type->type_data->name) )
  }
  TypeInstance* _TypeInstance92;
  CHECK(192, (((Argument*)(self->has_func->arguments->outputs->first->item)))->_base._dtl[6](((Argument*)(self->has_func->arguments->outputs->first->item)), &(_TypeInstance92)) )
  if (_TypeInstance92->type_data != &(glob->type_bool->_base)) {
    CHECK(194, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){51, 50, "iterator \"has\" method output is not \"Bool\" in type"}, self->iterator->result_type->type_data->name) )
  }
  
  Int _Int93;
  CHECK(198, TypeData_find_meth(self->iterator->result_type->type_data, &(String){4, 3, "get"}, &(self->get_func), &(_Int93)) )
  if (!(NULL != self->get_func)) {
    CHECK(201, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){50, 49, "cannot iterate type with no \"get\" named method - "}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->get_func->arguments->parameters->first->next) {
    CHECK(205, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){45, 44, "iterator \"get\" method has parameters in type"}, self->iterator->result_type->type_data->name) )
  }
  if (!(NULL != self->get_func->arguments->outputs->first)) {
    CHECK(209, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){45, 44, "iterator \"get\" method has no outputs in type"}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->get_func->arguments->outputs->first->next) {
    CHECK(213, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){55, 54, "iterator \"get\" method has more than one output in type"}, self->iterator->result_type->type_data->name) )
  }
  if (((Argument*)(self->get_func->arguments->outputs->first->item))->access == ACCESS_OWNER) {
    CHECK(217, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){56, 55, "iterator \"get\" method output has \"owner\" access in type"}, self->iterator->result_type->type_data->name) )
  }
  
  TypeInstance* real_type = NULL;
  TypeInstance* _TypeInstance94;
  CHECK(222, (((Argument*)(self->get_func->arguments->outputs->first->item)))->_base._dtl[6](((Argument*)(self->get_func->arguments->outputs->first->item)), &(_TypeInstance94)) )
  CHECK(222, TypeInstance_f_new_replace_params(_TypeInstance94, self->iterator->result_type, 0, &(real_type)) )
  self->item_type = real_type->type_data;
  free(real_type);
  
  Int _Int95;
  CHECK(227, TypeData_find_meth(self->iterator->result_type->type_data, &(String){5, 4, "next"}, &(self->next_func), &(_Int95)) )
  if (!(NULL != self->next_func)) {
    CHECK(230, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){51, 50, "cannot iterate type with no \"next\" named method - "}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->next_func->arguments->parameters->first->next) {
    CHECK(234, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){46, 45, "iterator \"next\" method has parameters in type"}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->next_func->arguments->outputs->first) {
    CHECK(238, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){43, 42, "iterator \"next\" method has outputs in type"}, self->iterator->result_type->type_data->name) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_write(SyntaxTreeForLoop* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_write = "SyntaxTreeForLoop.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_write
Returncode SyntaxTreeForLoop_write(SyntaxTreeForLoop* self) {
  CHECK(243, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  if (NULL != self->start) {
    CHECK(245, (self->start)->_base._dtl[7](self->start) )
  }
  CHECK(246, (self->iterator)->_base._dtl[7](self->iterator) )
  if (self->iterator->result_type->type_data == &(glob->type_int->_base)) {
    CHECK(248, SyntaxTreeForLoop_write_int_iter(self) )
  }
  else {
    if (self->iterator->result_type->type_data == &(glob->type_string->_base) || self->iterator->result_type->type_data == &(glob->type_array->_base)) {
      CHECK(251, SyntaxTreeForLoop_write_seq(self) )
    }
    else {
      CHECK(253, SyntaxTreeForLoop_write_iter(self) )
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_write_int_iter(SyntaxTreeForLoop* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_write_int_iter = "SyntaxTreeForLoop.write-int-iter";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_write_int_iter
Returncode SyntaxTreeForLoop_write_int_iter(SyntaxTreeForLoop* self) {
  /* {int `item`; for(`item` = `start`; `item` < `iterator`; ++`item`) { */
  /*   `block...` */
  /* }} */
  CHECK(259, write(&(String){6, 5, "{int "}) )
  CHECK(260, write_cname(self->item_name) )
  CHECK(261, write(&(String){8, 7, "; for ("}) )
  CHECK(262, write_cname(self->item_name) )
  CHECK(263, write(&(String){4, 3, " = "}) )
  if (NULL != self->start) {
    CHECK(265, (self->start)->_base._dtl[3](self->start) )
  }
  else {
    CHECK(267, write(&(String){2, 1, "0"}) )
  }
  CHECK(268, write(&(String){3, 2, "; "}) )
  CHECK(269, write_cname(self->item_name) )
  CHECK(270, write(&(String){4, 3, " < "}) )
  CHECK(271, (self->iterator)->_base._dtl[3](self->iterator) )
  CHECK(272, write(&(String){5, 4, "; ++"}) )
  CHECK(273, write_cname(self->item_name) )
  CHECK(274, write(&(String){2, 1, ")"}) )
  CHECK(275, SyntaxTreeFlowElement_write_block(&(self->_base)) )
  CHECK(276, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(277, write(&(String){3, 2, "}\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_write_seq(SyntaxTreeForLoop* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_write_seq = "SyntaxTreeForLoop.write-seq";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_write_seq
Returncode SyntaxTreeForLoop_write_seq(SyntaxTreeForLoop* self) {
  /* {int `item`_Index; for (`item`_Index = 0; `item`_Index < `iterator`->length; ++`item`_Index) { */
  /*   `item-type`* `item` = NULL; */
  /*   RefManager* `item`_Refman = NULL; */
  /*   `item` = `iterator`->values[`item`_Index]; */
  /*   `item` = ((`item-type`*)((`iterator`)->values))[`item`_Index]; */
  /*   `item` = ((`item-type`**)((`iterator`)->values))[`item`_Index]; */
  /*   `item`_Refman = `iterator-Refman`; */
  /*   `block...` */
  /* }} */
  CHECK(289, write(&(String){6, 5, "{int "}) )
  CHECK(290, write_cname(self->item_name) )
  CHECK(291, write(&(String){14, 13, "_Index; for ("}) )
  CHECK(292, write_cname(self->item_name) )
  CHECK(293, write(&(String){13, 12, "_Index = 0; "}) )
  CHECK(294, write_cname(self->item_name) )
  CHECK(295, write(&(String){10, 9, "_Index < "}) )
  CHECK(296, (self->iterator)->_base._dtl[3](self->iterator) )
  CHECK(297, write(&(String){13, 12, "->length; ++"}) )
  CHECK(298, write_cname(self->item_name) )
  CHECK(299, write(&(String){13, 12, "_Index) {\n  "}) )
  CHECK(300, SyntaxTreeForLoop_write_item_var(self) )
  CHECK(301, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(302, write_cname(self->item_name) )
  CHECK(303, write(&(String){4, 3, " = "}) )
  if (self->iterator->result_type->type_data == &(glob->type_string->_base)) {
    CHECK(305, (self->iterator)->_base._dtl[3](self->iterator) )
    CHECK(306, write(&(String){9, 8, "->values"}) )
  }
  else {
    CHECK(308, write(&(String){3, 2, "(("}) )
    CHECK(309, write_cname(self->item_type->name) )
    if (!self->item_type->is_primitive) {
      CHECK(311, write(&(String){2, 1, "*"}) )
    }
    CHECK(312, write(&(String){5, 4, "*)(("}) )
    CHECK(313, (self->iterator)->_base._dtl[3](self->iterator) )
    CHECK(314, write(&(String){12, 11, ")->values))"}) )
  }
  CHECK(315, write(&(String){2, 1, "["}) )
  CHECK(316, write_cname(self->item_name) )
  CHECK(317, write(&(String){10, 9, "_Index];\n"}) )
  if (!self->item_type->is_primitive) {
    CHECK(319, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
    CHECK(320, write(&(String){3, 2, "  "}) )
    CHECK(321, write_cname(self->item_name) )
    CHECK(322, write(&(String){11, 10, "_Refman = "}) )
    CHECK(323, (self->iterator)->_base._dtl[5](self->iterator) )
    CHECK(324, write(&(String){3, 2, ";\n"}) )
  }
  
  CHECK(326, SyntaxTreeFlowElement_write_block_body(&(self->_base)) )
  
  CHECK(328, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(329, write(&(String){4, 3, "}}\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_write_item_var(SyntaxTreeForLoop* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_write_item_var = "SyntaxTreeForLoop.write-item-var";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_write_item_var
Returncode SyntaxTreeForLoop_write_item_var(SyntaxTreeForLoop* self) {
  CHECK(332, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(333, write_cname(self->item_type->name) )
  if (!self->item_type->is_primitive) {
    CHECK(335, write(&(String){2, 1, "*"}) )
  }
  CHECK(336, write(&(String){2, 1, " "}) )
  CHECK(337, write_cname(self->item_name) )
  CHECK(338, write(&(String){4, 3, " = "}) )
  if (self->item_type->is_primitive) {
    CHECK(340, write(&(String){2, 1, "0"}) )
  }
  else {
    CHECK(342, write(&(String){5, 4, "NULL"}) )
  }
  CHECK(343, write(&(String){5, 4, ";\n  "}) )
  if (!self->item_type->is_primitive) {
    CHECK(345, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
    CHECK(346, write(&(String){13, 12, "RefManager* "}) )
    CHECK(347, write_cname(self->item_name) )
    CHECK(348, write(&(String){19, 18, "_Refman = NULL;\n  "}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_write_iter(SyntaxTreeForLoop* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_write_iter = "SyntaxTreeForLoop.write-iter";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_write_iter
Returncode SyntaxTreeForLoop_write_iter(SyntaxTreeForLoop* self) {
  /* while (true) { */
  /*   Bool `item`_Has = false; */
  /*   `item-type`* `item` = NULL; */
  /*   RefManager* `item`_Refman = NULL; */
  /*   CALL( `iterator-type`_has(`iterator`, &`item`_Has) ) */
  /*   if (!`item`_Has) break; */
  /*   CALL( `iterator-type`_get(`iterator`, (void*)&`item`, &`item-refman`) ) */
  /*   `block...` */
  /*   CALL( `iterator-type`_next(`iterator`) ) */
  /* } */
  CHECK(361, write(&(String){18, 17, "while (true) {\n  "}) )
  CHECK(362, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(363, write(&(String){6, 5, "Bool "}) )
  CHECK(364, write_cname(self->item_name) )
  CHECK(365, write(&(String){17, 16, "_Has = false;\n  "}) )
  CHECK(366, SyntaxTreeForLoop_write_item_var(self) )
  CHECK(367, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(368, SyntaxTreeForLoop_write_iter_meth(self, self->has_func) )
  CHECK(369, write(&(String){4, 3, ", &"}) )
  CHECK(370, write_cname(self->item_name) )
  CHECK(371, write(&(String){11, 10, "_Has) )\n  "}) )
  CHECK(372, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(373, write(&(String){6, 5, "if (!"}) )
  CHECK(374, write_cname(self->item_name) )
  CHECK(375, write(&(String){16, 15, "_Has) break;\n  "}) )
  CHECK(376, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(377, SyntaxTreeForLoop_write_iter_meth(self, self->get_func) )
  CHECK(378, write(&(String){11, 10, ", (void*)&"}) )
  CHECK(379, write_cname(self->item_name) )
  if (!self->item_type->is_primitive) {
    CHECK(381, write(&(String){4, 3, ", &"}) )
    CHECK(382, write_cname(self->item_name) )
    CHECK(383, write(&(String){8, 7, "_Refman"}) )
  }
  CHECK(384, write(&(String){5, 4, ") )\n"}) )
  
  CHECK(386, SyntaxTreeFlowElement_write_block_body(&(self->_base)) )
  
  CHECK(388, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(389, write(&(String){3, 2, "  "}) )
  CHECK(390, SyntaxTreeForLoop_write_iter_meth(self, self->next_func) )
  CHECK(391, write(&(String){5, 4, ") )\n"}) )
  CHECK(392, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(393, write(&(String){3, 2, "}\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_write_iter_meth(SyntaxTreeForLoop* self, SyntaxTreeFunction* meth);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_write_iter_meth = "SyntaxTreeForLoop.write-iter-meth";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_write_iter_meth
Returncode SyntaxTreeForLoop_write_iter_meth(SyntaxTreeForLoop* self, SyntaxTreeFunction* meth) {
  CHECK(396, SyntaxTreeNode_write_call(&(self->_base._base._base)) )
  CHECK(397, SyntaxTreeFunction_write_cname(meth) )
  CHECK(398, write(&(String){2, 1, "("}) )
  CHECK(399, (self->iterator)->_base._dtl[3](self->iterator) )
  CHECK(400, write(&(String){3, 2, ", "}) )
  CHECK(401, (self->iterator)->_base._dtl[5](self->iterator) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeForLoop__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeForLoop__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeFlowElement_link_types, (void*)SyntaxTreeForLoop_analyze, (void*)SyntaxTreeForLoop_write, (void*)SyntaxTreeCode_m_is_end_point};
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
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
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
