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
  *self->block = (SyntaxTreeBlock){SyntaxTreeBlock__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false};
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
  SyntaxTreeVariable* item;
  Expression* start;
  Expression* iterator;
  SymbolExpression* aux_symbol;
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
  if ((*new_node) == NULL) RAISE(132)
  *(*new_node) = (SyntaxTreeForLoop){SyntaxTreeForLoop__dtl, NULL, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeForLoop__dtl;
  CHECK(133, SyntaxTreeForLoop_parse((*new_node), parent, &((*end))) )
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
  CHECK(136, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(137, read_new(&(String){2, 1, " "}, &(self->item_name), &((*end))) )
  if ((*end) != ' ') {
    CHECK(139, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){37, 36, "expected space after index name, got"}, (*end)) )
  }
  CHECK(141, SyntaxTreeNode_read_expect(&(self->_base._base._base), &(String){4, 3, "in "}) )
  CHECK(142, parse_new_expression(&(String){2, 1, ":"}, &(self->_base._base), &(self->iterator), &((*end))) )
  if ((*end) == ':') {
    self->start = self->iterator;
    CHECK(145, parse_new_expression(&(String){1, 0, ""}, &(self->_base._base), &(self->iterator), &((*end))) )
  }
  
  CHECK(147, SyntaxTreeFlowElement_parse_block(&(self->_base), parent, true, &((*end))) )
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
  TypeInstance* type_instance = NULL;
  if (NULL != self->start) {
    CHECK(152, SyntaxTreeNode_analyze_expression(&(self->_base._base._base), self->start, &(glob->type_int->_base)) )
    CHECK(153, SyntaxTreeNode_analyze_expression(&(self->_base._base._base), self->iterator, &(glob->type_int->_base)) )
    CHECK(154, TypeData_m_new_type_instance(&(glob->type_int->_base), &(type_instance)) )
  }
  else {
    CHECK(156, (self->iterator)->_base._dtl[2](self->iterator) )
    if (!(NULL != self->iterator->result_type)) {
      CHECK(158, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){31, 30, "cannot iterate void expression"}) )
    }
    if (self->iterator->result_type->type_data == &(glob->type_int->_base)) {
      CHECK(160, TypeData_m_new_type_instance(&(glob->type_int->_base), &(type_instance)) )
    }
    else {
      if (self->iterator->result_type->type_data == &(glob->type_string->_base)) {
        CHECK(162, TypeData_m_new_type_instance(&(glob->type_char->_base), &(type_instance)) )
      }
      else {
        if (self->iterator->result_type->type_data == &(glob->type_array->_base)) {
          CHECK(164, TypeInstance_copy_new(((TypeInstance*)(self->iterator->result_type->parameters->first->item)), &(type_instance)) )
        }
        else {
          CHECK(167, SyntaxTreeForLoop_get_iterator_type(self, &(type_instance)) )
        }
      }
    }
  }
  
  CHECK(169, (self->_base._base.parent)->_base._base._dtl[5](self->_base._base.parent, self->item_name, &(self->item)) )
  if (NULL != self->item) {
    Int _Int90;
    CHECK(170, TypeInstance_check_assign_to(type_instance, self->item->type_instance, &(self->_base._base._base), &(_Int90)) )
    free(type_instance);
    free(self->item_name);
  }
  else {
    SyntaxTreeVariable* item = malloc(sizeof(SyntaxTreeVariable));
    if (item == NULL) RAISE(174)
    *item = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false, false, false};
    item->_base._base._dtl = SyntaxTreeVariable__dtl;
    item->name = self->item_name;
    if (type_instance->type_data->is_primitive) {
      item->access = ACCESS_VAR;
    }
    else {
      item->access = ACCESS_USER;
    }
    item->type_instance = type_instance;
    SyntaxTreeFunction* function = NULL;
    CHECK(182, SyntaxTreeCode_get_function(&(self->_base._base), &(function)) )
    item->_base.parent = &(function->_base);
    self->item = item;
    CHECK(185, List_add(function->_base._base.variables, item) )
  }
  self->item_name = NULL;
  
  if (self->iterator->result_type->type_data != &(glob->type_int->_base)) {
    self->aux_symbol = malloc(sizeof(SymbolExpression));
    if (self->aux_symbol == NULL) RAISE(189)
    *self->aux_symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL};
    self->aux_symbol->_base._base._dtl = SymbolExpression__dtl;
    self->aux_symbol->_base.code_node = &(self->_base._base);
    CHECK(191, TypeInstance_copy_new(self->iterator->result_type, &(self->aux_symbol->_base.result_type)) )
    SyntaxTreeFunction* _SyntaxTreeFunction91;
    CHECK(192, SyntaxTreeCode_get_function(&(self->_base._base), &(_SyntaxTreeFunction91)) )
    CHECK(192, SyntaxTreeFunction_add_aux_variable(_SyntaxTreeFunction91, ACCESS_USER, false, self->iterator->result_type, &(self->aux_symbol->variable)) )
    CHECK(195, string_new_copy(self->aux_symbol->variable->name, &(self->aux_symbol->name)) )
  }
  
  CHECK(198, SyntaxTreeFlowElement_analyze(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_get_iterator_type(SyntaxTreeForLoop* self, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_get_iterator_type = "SyntaxTreeForLoop.get-iterator-type";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_get_iterator_type
Returncode SyntaxTreeForLoop_get_iterator_type(SyntaxTreeForLoop* self, TypeInstance** type_instance) {
  Int _Int92;
  CHECK(201, TypeData_find_meth(self->iterator->result_type->type_data, &(String){4, 3, "has"}, &(self->has_func), &(_Int92)) )
  if (!(NULL != self->has_func)) {
    CHECK(204, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){50, 49, "cannot iterate type with no \"has\" named method - "}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->has_func->arguments->parameters->first->next) {
    CHECK(208, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){45, 44, "iterator \"has\" method has parameters in type"}, self->iterator->result_type->type_data->name) )
  }
  if (!(NULL != self->has_func->arguments->outputs->first)) {
    CHECK(212, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){45, 44, "iterator \"has\" method has no outputs in type"}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->has_func->arguments->outputs->first->next) {
    CHECK(216, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){55, 54, "iterator \"has\" method has more than one output in type"}, self->iterator->result_type->type_data->name) )
  }
  TypeInstance* _TypeInstance93;
  CHECK(219, (((Argument*)(self->has_func->arguments->outputs->first->item)))->_base._dtl[6](((Argument*)(self->has_func->arguments->outputs->first->item)), &(_TypeInstance93)) )
  if (_TypeInstance93->type_data != &(glob->type_bool->_base)) {
    CHECK(221, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){51, 50, "iterator \"has\" method output is not \"Bool\" in type"}, self->iterator->result_type->type_data->name) )
  }
  
  Int _Int94;
  CHECK(225, TypeData_find_meth(self->iterator->result_type->type_data, &(String){4, 3, "get"}, &(self->get_func), &(_Int94)) )
  if (!(NULL != self->get_func)) {
    CHECK(228, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){50, 49, "cannot iterate type with no \"get\" named method - "}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->get_func->arguments->parameters->first->next) {
    CHECK(232, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){45, 44, "iterator \"get\" method has parameters in type"}, self->iterator->result_type->type_data->name) )
  }
  if (!(NULL != self->get_func->arguments->outputs->first)) {
    CHECK(236, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){45, 44, "iterator \"get\" method has no outputs in type"}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->get_func->arguments->outputs->first->next) {
    CHECK(240, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){55, 54, "iterator \"get\" method has more than one output in type"}, self->iterator->result_type->type_data->name) )
  }
  if (((Argument*)(self->get_func->arguments->outputs->first->item))->access == ACCESS_OWNER) {
    CHECK(244, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){56, 55, "iterator \"get\" method output has \"owner\" access in type"}, self->iterator->result_type->type_data->name) )
  }
  
  TypeInstance* _TypeInstance95;
  CHECK(248, (((Argument*)(self->get_func->arguments->outputs->first->item)))->_base._dtl[6](((Argument*)(self->get_func->arguments->outputs->first->item)), &(_TypeInstance95)) )
  CHECK(248, TypeInstance_f_new_replace_params(_TypeInstance95, self->iterator->result_type, 0, &((*type_instance))) )
  
  Int _Int96;
  CHECK(251, TypeData_find_meth(self->iterator->result_type->type_data, &(String){5, 4, "next"}, &(self->next_func), &(_Int96)) )
  if (!(NULL != self->next_func)) {
    CHECK(254, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){51, 50, "cannot iterate type with no \"next\" named method - "}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->next_func->arguments->parameters->first->next) {
    CHECK(258, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){46, 45, "iterator \"next\" method has parameters in type"}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->next_func->arguments->outputs->first) {
    CHECK(262, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){43, 42, "iterator \"next\" method has outputs in type"}, self->iterator->result_type->type_data->name) )
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
  TypeData* iterator_type = self->iterator->result_type->type_data;
  if (NULL != self->aux_symbol) {
    CHECK(269, SyntaxTreeForLoop_write_assign(self, self->aux_symbol->variable, self->iterator, self->_base._base.parent) )
  }
  CHECK(271, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  if (NULL != self->start) {
    CHECK(273, (self->start)->_base._dtl[7](self->start) )
  }
  if (iterator_type == &(glob->type_int->_base)) {
    CHECK(275, SyntaxTreeForLoop_write_int_iter(self) )
  }
  else {
    if (iterator_type == &(glob->type_string->_base) || iterator_type == &(glob->type_array->_base)) {
      CHECK(277, SyntaxTreeForLoop_write_seq(self) )
    }
    else {
      CHECK(279, SyntaxTreeForLoop_write_iter(self) )
    }
  }
  if (NULL != self->aux_symbol) {
    EmptyExpression* empty = malloc(sizeof(EmptyExpression));
    if (empty == NULL) RAISE(281)
    *empty = (EmptyExpression){EmptyExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false};
    empty->_base._base._dtl = EmptyExpression__dtl;
    CHECK(282, SyntaxTreeForLoop_write_assign(self, self->aux_symbol->variable, &(empty->_base), self->_base._base.parent) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_write_assign(SyntaxTreeForLoop* self, SyntaxTreeVariable* item, Expression* value, SyntaxTreeBlock* parent);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_write_assign = "SyntaxTreeForLoop.write-assign";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_write_assign
Returncode SyntaxTreeForLoop_write_assign(SyntaxTreeForLoop* self, SyntaxTreeVariable* item, Expression* value, SyntaxTreeBlock* parent) {
  SyntaxTreeExpression* expression_node = &(SyntaxTreeExpression){SyntaxTreeExpression__dtl, NULL, 0, NULL, NULL};
  expression_node->_base._base._dtl = SyntaxTreeExpression__dtl;
  expression_node->_base.parent = parent;
  value->code_node = &(expression_node->_base);
  
  SymbolExpression* symbol = malloc(sizeof(SymbolExpression));
  if (symbol == NULL) RAISE(293)
  *symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL};
  symbol->_base._base._dtl = SymbolExpression__dtl;
  CHECK(294, string_new_copy(item->name, &(symbol->name)) )
  CHECK(295, TypeInstance_copy_new(item->type_instance, &(symbol->_base.result_type)) )
  
  BinaryExpression* assign = malloc(sizeof(BinaryExpression));
  if (assign == NULL) RAISE(297)
  *assign = (BinaryExpression){BinaryExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL, NULL};
  assign->_base._base._base._dtl = BinaryExpression__dtl;
  assign->_base._base.top = true;
  assign->_base._base.is_statement = true;
  assign->_base._base.code_node = &(expression_node->_base);
  assign->left_expression = &(symbol->_base);
  CHECK(302, NameMap_find(glob->operator_map, &(String){3, 2, ":="}, (void**)&(assign->_base.operator)) )
  assign->_base.right_expression = value;
  
  expression_node->expression = &(assign->_base._base);
  CHECK(306, (expression_node)->_base._base._dtl[3](expression_node) )
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
  /* for(`item` = `start`; `item` < `iterator`; ++`item`) { */
  /*   `block...` */
  /* } */
  CHECK(312, write(&(String){6, 5, "for ("}) )
  CHECK(313, write_cname(self->item->name) )
  CHECK(314, write(&(String){4, 3, " = "}) )
  if (NULL != self->start) {
    CHECK(316, (self->start)->_base._dtl[3](self->start) )
  }
  else {
    CHECK(318, write(&(String){2, 1, "0"}) )
  }
  CHECK(319, write(&(String){3, 2, "; "}) )
  CHECK(320, write_cname(self->item->name) )
  CHECK(321, write(&(String){4, 3, " < "}) )
  CHECK(322, (self->iterator)->_base._dtl[3](self->iterator) )
  CHECK(323, write(&(String){5, 4, "; ++"}) )
  CHECK(324, write_cname(self->item->name) )
  CHECK(325, write(&(String){2, 1, ")"}) )
  CHECK(326, SyntaxTreeFlowElement_write_block(&(self->_base)) )
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
  /*   `item` = `aux-var`[`item`_Index]; */
  /*   `block...` */
  /* }} */
  CHECK(333, write(&(String){6, 5, "{int "}) )
  CHECK(334, write_cname(self->item->name) )
  CHECK(335, write(&(String){14, 13, "_Index; for ("}) )
  CHECK(336, write_cname(self->item->name) )
  CHECK(337, write(&(String){13, 12, "_Index = 0; "}) )
  CHECK(338, write_cname(self->item->name) )
  CHECK(339, write(&(String){10, 9, "_Index < "}) )
  CHECK(340, (self->aux_symbol)->_base._base._dtl[3](self->aux_symbol) )
  CHECK(341, write(&(String){13, 12, "->length; ++"}) )
  CHECK(342, write_cname(self->item->name) )
  CHECK(343, write(&(String){11, 10, "_Index) {\n"}) )
  
  SymbolExpression* index_symbol = malloc(sizeof(SymbolExpression));
  if (index_symbol == NULL) RAISE(345)
  *index_symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL};
  index_symbol->_base._base._dtl = SymbolExpression__dtl;
  CHECK(346, string_new_concat(self->item->name, &(String){7, 6, "_Index"}, &(index_symbol->name)) )
  SliceExpression* slice = malloc(sizeof(SliceExpression));
  if (slice == NULL) RAISE(348)
  *slice = (SliceExpression){SliceExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL, NULL};
  slice->_base._base._dtl = SliceExpression__dtl;
  slice->_base.top = true;
  slice->_base._base.line_number = self->_base._base._base.line_number;
  slice->sequence = &(self->aux_symbol->_base);
  slice->index = &(index_symbol->_base);
  CHECK(353, TypeInstance_copy_new(self->item->type_instance, &(slice->_base.result_type)) )
  CHECK(354, SyntaxTreeForLoop_write_assign(self, self->item, &(slice->_base), self->_base.block) )
  
  CHECK(356, SyntaxTreeFlowElement_write_block_body(&(self->_base)) )
  
  CHECK(358, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(359, write(&(String){4, 3, "}}\n"}) )
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
  /*   `has-func`()->(`item`_Has) */
  /*   if (!`item`_Has) break; */
  /*   `get-func`()->(`item`) */
  /*   `block...` */
  /*   `next-func`() */
  /* } */
  CHECK(370, write(&(String){16, 15, "while (true) {\n"}) )
  CHECK(371, SyntaxTreeBranch_write_spaces(&(self->_base.block->_base)) )
  CHECK(372, write(&(String){6, 5, "Bool "}) )
  CHECK(373, write_cname(self->item->name) )
  CHECK(374, write(&(String){15, 14, "_Has = false;\n"}) )
  
  SymbolExpression* has_symbol = malloc(sizeof(SymbolExpression));
  if (has_symbol == NULL) RAISE(376)
  *has_symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL};
  has_symbol->_base._base._dtl = SymbolExpression__dtl;
  CHECK(377, string_new_concat(self->item->name, &(String){5, 4, "_Has"}, &(has_symbol->name)) )
  CHECK(378, TypeData_m_new_type_instance(&(glob->type_bool->_base), &(has_symbol->_base.result_type)) )
  CallArgument* has_arg = malloc(sizeof(CallArgument));
  if (has_arg == NULL) RAISE(379)
  *has_arg = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, false, false, false};
  has_arg->_base._base._dtl = CallArgument__dtl;
  has_arg->value = &(has_symbol->_base);
  CHECK(381, SyntaxTreeForLoop_write_iter_meth(self, self->has_func, has_arg) )
  
  CHECK(383, SyntaxTreeBranch_write_spaces(&(self->_base.block->_base)) )
  CHECK(384, write(&(String){6, 5, "if (!"}) )
  CHECK(385, write_cname(self->item->name) )
  CHECK(386, write(&(String){14, 13, "_Has) break;\n"}) )
  
  SymbolExpression* item_symbol = malloc(sizeof(SymbolExpression));
  if (item_symbol == NULL) RAISE(388)
  *item_symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL};
  item_symbol->_base._base._dtl = SymbolExpression__dtl;
  CHECK(389, string_new_copy(self->item->name, &(item_symbol->name)) )
  CHECK(390, TypeInstance_copy_new(self->item->type_instance, &(item_symbol->_base.result_type)) )
  CallArgument* item_arg = malloc(sizeof(CallArgument));
  if (item_arg == NULL) RAISE(391)
  *item_arg = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, false, false, false};
  item_arg->_base._base._dtl = CallArgument__dtl;
  item_arg->value = &(item_symbol->_base);
  TypeInstance* _TypeInstance97;
  CHECK(393, (((Argument*)(self->get_func->arguments->outputs->first->item)))->_base._dtl[6](((Argument*)(self->get_func->arguments->outputs->first->item)), &(_TypeInstance97)) )
  item_arg->is_generic = _TypeInstance97->type_data == &(glob->type_generic->_base);
  CHECK(396, SyntaxTreeForLoop_write_iter_meth(self, self->get_func, item_arg) )
  
  CHECK(398, SyntaxTreeFlowElement_write_block_body(&(self->_base)) )
  
  CHECK(400, SyntaxTreeForLoop_write_iter_meth(self, self->next_func, NULL) )
  CHECK(401, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(402, write(&(String){3, 2, "}\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_write_iter_meth(SyntaxTreeForLoop* self, SyntaxTreeFunction* meth, CallArgument* output_arg);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_write_iter_meth = "SyntaxTreeForLoop.write-iter-meth";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_write_iter_meth
Returncode SyntaxTreeForLoop_write_iter_meth(SyntaxTreeForLoop* self, SyntaxTreeFunction* meth, CallArgument* output_arg) {
  SyntaxTreeExpression* expression_node = &(SyntaxTreeExpression){SyntaxTreeExpression__dtl, NULL, 0, NULL, NULL};
  expression_node->_base._base._dtl = SyntaxTreeExpression__dtl;
  expression_node->_base.parent = self->_base.block;
  
  SymbolExpression* symbol = malloc(sizeof(SymbolExpression));
  if (symbol == NULL) RAISE(409)
  *symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL};
  symbol->_base._base._dtl = SymbolExpression__dtl;
  symbol->function = meth;
  
  CallArgument* self_arg = malloc(sizeof(CallArgument));
  if (self_arg == NULL) RAISE(412)
  *self_arg = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, false, false, false};
  self_arg->_base._base._dtl = CallArgument__dtl;
  self_arg->is_dynamic = self->aux_symbol->_base.result_type->type_data->is_dynamic;
  self_arg->value = &(self->aux_symbol->_base);
  
  CallExpression* call = malloc(sizeof(CallExpression));
  if (call == NULL) RAISE(416)
  *call = (CallExpression){CallExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL, false};
  call->_base._base._dtl = CallExpression__dtl;
  call->_base._base.line_number = self->_base._base._base.line_number;
  call->_base.top = true;
  call->_base.is_statement = true;
  call->function = &(symbol->_base);
  call->arguments = malloc(sizeof(FunctionArguments));
  if (call->arguments == NULL) RAISE(421)
  *call->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  call->arguments->_base._dtl = FunctionArguments__dtl;
  CHECK(422, FunctionArguments_init(call->arguments) )
  CHECK(423, List_add(call->arguments->parameters, &(self_arg->_base)) )
  if (NULL != output_arg) {
    output_arg->_base.is_output = true;
    output_arg->code_node = &(expression_node->_base);
    CHECK(427, List_add(call->arguments->outputs, &(output_arg->_base)) )
  }
  
  expression_node->expression = &(call->_base);
  CHECK(430, (expression_node)->_base._base._dtl[3](expression_node) )
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
