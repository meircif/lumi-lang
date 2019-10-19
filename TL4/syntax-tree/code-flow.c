#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "syntax-tree/code-flow.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file20_name = "syntax-tree/code-flow.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file20_name

/* TL4 compiler - Syntax tree code flow elements */

/* Basic code flow element node in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeFlowElement SyntaxTreeFlowElement;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct SyntaxTreeFlowElement {
  SyntaxTreeCode _base;
  SyntaxTreeBlock* block;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFlowElement_init(SyntaxTreeFlowElement* self, SyntaxTreeBlock* parent);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_init = "SyntaxTreeFlowElement.init";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFlowElement_init
Returncode SyntaxTreeFlowElement_init(SyntaxTreeFlowElement* self, SyntaxTreeBlock* parent) {
  CHECK(8, SyntaxTreeNode_set_location(&(self->_base._base)) )
  self->block = malloc(sizeof(SyntaxTreeBlock));
  if (self->block == NULL) RAISE(9)
  *self->block = (SyntaxTreeBlock){SyntaxTreeBlock__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, false};
  self->block->_base._base._dtl = SyntaxTreeBlock__dtl;
  CHECK(10, SyntaxTreeFlowElement_set_parent(self, parent) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFlowElement_set_parent(SyntaxTreeFlowElement* self, SyntaxTreeBlock* parent);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_set_parent = "SyntaxTreeFlowElement.set-parent";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFlowElement_set_parent
Returncode SyntaxTreeFlowElement_set_parent(SyntaxTreeFlowElement* self, SyntaxTreeBlock* parent) {
  self->_base.parent = parent;
  self->block->parent = parent;
  self->block->_base.indentation_spaces = parent->_base.indentation_spaces + 4;
  self->block->is_in_loop = parent->is_in_loop;
  CHECK(17, SyntaxTreeNode_set_location(&(self->block->_base._base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFlowElement_parse_block(SyntaxTreeFlowElement* self, Bool is_loop, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_parse_block = "SyntaxTreeFlowElement.parse-block";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFlowElement_parse_block
Returncode SyntaxTreeFlowElement_parse_block(SyntaxTreeFlowElement* self, Bool is_loop, Char* end) {
  if (is_loop) {
    self->block->is_in_loop = true;
  }
  CHECK(22, SyntaxTreeBlock_parse_block(self->block, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFlowElement_link_types(SyntaxTreeFlowElement* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_link_types = "SyntaxTreeFlowElement.link-types";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFlowElement_link_types
Returncode SyntaxTreeFlowElement_link_types(SyntaxTreeFlowElement* self) {
  CHECK(25, (self->block)->_base._base._dtl[1](self->block) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFlowElement_analyze(SyntaxTreeFlowElement* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_analyze = "SyntaxTreeFlowElement.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFlowElement_analyze
Returncode SyntaxTreeFlowElement_analyze(SyntaxTreeFlowElement* self) {
  CHECK(28, (self->block)->_base._base._dtl[2](self->block) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFlowElement_write_block(SyntaxTreeFlowElement* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_write_block = "SyntaxTreeFlowElement.write-block";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFlowElement_write_block
Returncode SyntaxTreeFlowElement_write_block(SyntaxTreeFlowElement* self) {
  CHECK(31, SyntaxTreeBlock_write_block(self->block) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeFlowElement_write_block_body(SyntaxTreeFlowElement* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_write_block_body = "SyntaxTreeFlowElement.write-block-body";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeFlowElement_write_block_body
Returncode SyntaxTreeFlowElement_write_block_body(SyntaxTreeFlowElement* self) {
  CHECK(34, (self->block)->_base._base._dtl[9](self->block) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeFlowElement__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeFlowElement__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeFlowElement_link_types, (void*)SyntaxTreeFlowElement_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeNode_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* If statement node in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeIf SyntaxTreeIf;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct SyntaxTreeIf {
  SyntaxTreeFlowElement _base;
  Expression* condition;
  SyntaxTreeElse* else_node;
/* if (`condition`) { *//*   `block...` *//* } *//* `else-block` */};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeIf_parse_new(SyntaxTreeIf* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeIf** new_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeIf_parse_new = "SyntaxTreeIf.parse-new";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeIf_parse_new
Returncode SyntaxTreeIf_parse_new(SyntaxTreeIf* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeIf** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeIf));
  if ((*new_node) == NULL) RAISE(44)
  *(*new_node) = (SyntaxTreeIf){SyntaxTreeIf__dtl, NULL, 0, NULL, NULL, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeIf__dtl;
  CHECK(45, SyntaxTreeIf_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeIf_parse(SyntaxTreeIf* self, SyntaxTreeBlock* parent, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeIf_parse = "SyntaxTreeIf.parse";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeIf_parse
Returncode SyntaxTreeIf_parse(SyntaxTreeIf* self, SyntaxTreeBlock* parent, Char* end) {
  CHECK(48, SyntaxTreeFlowElement_init(&(self->_base), parent) )
  CHECK(49, parse_new_expression(&(String){1, 0, ""}, &(self->_base._base), &(self->condition), &((*end))) )
  CHECK(50, SyntaxTreeFlowElement_parse_block(&(self->_base), false, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeIf_add_else(SyntaxTreeIf* self, SyntaxTreeElse* else_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeIf_add_else = "SyntaxTreeIf.add-else";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeIf_add_else
Returncode SyntaxTreeIf_add_else(SyntaxTreeIf* self, SyntaxTreeElse* else_node) {
  CHECK(53, SyntaxTreeFlowElement_set_parent(&(else_node->_base), self->_base._base.parent) )
  self->else_node = else_node;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeIf_add_else_if(SyntaxTreeIf* self, SyntaxTreeIf* new_if, SyntaxTreeCoverage* coverage_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeIf_add_else_if = "SyntaxTreeIf.add-else-if";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeIf_add_else_if
Returncode SyntaxTreeIf_add_else_if(SyntaxTreeIf* self, SyntaxTreeIf* new_if, SyntaxTreeCoverage* coverage_node) {
  self->else_node = malloc(sizeof(SyntaxTreeElse));
  if (self->else_node == NULL) RAISE(58)
  *self->else_node = (SyntaxTreeElse){SyntaxTreeElse__dtl, NULL, 0, NULL, NULL};
  self->else_node->_base._base._base._dtl = SyntaxTreeElse__dtl;
  CHECK(59, SyntaxTreeFlowElement_init(&(self->else_node->_base), self->_base._base.parent) )
  self->else_node->_base.block->_base.variables = malloc(sizeof(List));
  if (self->else_node->_base.block->_base.variables == NULL) RAISE(60)
  *self->else_node->_base.block->_base.variables = (List){NULL, NULL};
  self->else_node->_base.block->code_nodes = malloc(sizeof(List));
  if (self->else_node->_base.block->code_nodes == NULL) RAISE(61)
  *self->else_node->_base.block->code_nodes = (List){NULL, NULL};
  if (NULL != coverage_node) {
    coverage_node->_base.parent = self->else_node->_base.block;
    CHECK(64, List_add(self->else_node->_base.block->code_nodes, &(coverage_node->_base)) )
  }
  CHECK(65, List_add(self->else_node->_base.block->code_nodes, &(new_if->_base._base)) )
  CHECK(66, SyntaxTreeFlowElement_set_parent(&(new_if->_base), self->else_node->_base.block) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeIf_analyze(SyntaxTreeIf* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeIf_analyze = "SyntaxTreeIf.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeIf_analyze
Returncode SyntaxTreeIf_analyze(SyntaxTreeIf* self) {
  CHECK(69, SyntaxTreeNode_analyze_expression(&(self->_base._base._base), self->condition, glob->type_bool) )
  CHECK(70, SyntaxTreeFlowElement_analyze(&(self->_base)) )
  if (NULL != self->else_node) {
    CHECK(72, (self->else_node)->_base._base._base._dtl[2](self->else_node) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* if (`condition`) { *//*   `block...` *//* } *//* `else-block` */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeIf_write(SyntaxTreeIf* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeIf_write = "SyntaxTreeIf.write";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeIf_write
Returncode SyntaxTreeIf_write(SyntaxTreeIf* self) {
  CHECK(79, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(80, (self->condition)->_base._dtl[9](self->condition) )
  CHECK(81, write(&(String){5, 4, "if ("}) )
  CHECK(82, (self->condition)->_base._dtl[4](self->condition) )
  CHECK(83, write(&(String){2, 1, ")"}) )
  CHECK(84, SyntaxTreeFlowElement_write_block(&(self->_base)) )
  if (NULL != self->else_node) {
    CHECK(86, (self->else_node)->_base._base._base._dtl[4](self->else_node) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeIf__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeIf__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeFlowElement_link_types, (void*)SyntaxTreeIf_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeIf_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Else statement node in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeElse SyntaxTreeElse;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct SyntaxTreeElse {
  SyntaxTreeFlowElement _base;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeElse_parse_new(SyntaxTreeElse* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeElse** new_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeElse_parse_new = "SyntaxTreeElse.parse-new";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeElse_parse_new
Returncode SyntaxTreeElse_parse_new(SyntaxTreeElse* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeElse** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeElse));
  if ((*new_node) == NULL) RAISE(93)
  *(*new_node) = (SyntaxTreeElse){SyntaxTreeElse__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeElse__dtl;
  CHECK(94, SyntaxTreeFlowElement_init(&((*new_node)->_base), parent) )
  CHECK(95, SyntaxTreeFlowElement_parse_block(&((*new_node)->_base), false, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeElse_write(SyntaxTreeElse* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeElse_write = "SyntaxTreeElse.write";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeElse_write
Returncode SyntaxTreeElse_write(SyntaxTreeElse* self) {
  /* else { */
  /*   `block...` */
  /* } */
  CHECK(101, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(102, write(&(String){5, 4, "else"}) )
  CHECK(103, SyntaxTreeFlowElement_write_block(&(self->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeElse__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeElse__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeFlowElement_link_types, (void*)SyntaxTreeFlowElement_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeElse_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Do loop node in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeDoLoop SyntaxTreeDoLoop;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct SyntaxTreeDoLoop {
  SyntaxTreeFlowElement _base;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeDoLoop_parse_new(SyntaxTreeDoLoop* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeDoLoop** new_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeDoLoop_parse_new = "SyntaxTreeDoLoop.parse-new";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeDoLoop_parse_new
Returncode SyntaxTreeDoLoop_parse_new(SyntaxTreeDoLoop* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeDoLoop** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeDoLoop));
  if ((*new_node) == NULL) RAISE(110)
  *(*new_node) = (SyntaxTreeDoLoop){SyntaxTreeDoLoop__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeDoLoop__dtl;
  CHECK(111, SyntaxTreeFlowElement_init(&((*new_node)->_base), parent) )
  CHECK(112, SyntaxTreeFlowElement_parse_block(&((*new_node)->_base), true, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeDoLoop_write(SyntaxTreeDoLoop* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeDoLoop_write = "SyntaxTreeDoLoop.write";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeDoLoop_write
Returncode SyntaxTreeDoLoop_write(SyntaxTreeDoLoop* self) {
  /* while (true) { */
  /*   `block...` */
  /* } */
  CHECK(118, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(119, write(&(String){13, 12, "while (true)"}) )
  CHECK(120, SyntaxTreeFlowElement_write_block(&(self->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeDoLoop__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeDoLoop__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeFlowElement_link_types, (void*)SyntaxTreeFlowElement_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeDoLoop_write, (void*)SyntaxTreeCode_m_is_end_point};
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
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
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
