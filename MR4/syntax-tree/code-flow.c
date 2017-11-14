#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/code-flow.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file16_name = "syntax-tree/code-flow.3.mr";
#endif
#define MR_FILE_NAME _mr_file16_name

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
  self->block->aux_variables = parent->aux_variables;
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
  CHECK(20, SyntaxTreeFlowElement_init(self, parent) )
  if (is_loop) {
    self->block->is_in_loop = true;
  }
  CHECK(23, SyntaxTreeBlock_parse_block(self->block, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeFlowElement_m_link_types(SyntaxTreeFlowElement* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeFlowElement_m_link_types = "SyntaxTreeFlowElement.m-link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeFlowElement_m_link_types
Returncode SyntaxTreeFlowElement_m_link_types(SyntaxTreeFlowElement* self) {
  CHECK(26, (self->block)->_base._base._dtl[0](self->block) )
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
  CHECK(29, (self->block)->_base._base._dtl[1](self->block) )
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
  CHECK(32, SyntaxTreeBlock_write_block(self->block) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeFlowElement__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeFlowElement__dtl[] = {(void*)SyntaxTreeFlowElement_m_link_types, (void*)SyntaxTreeFlowElement_analyze, (void*)SyntaxTreeNode_write, (void*)SyntaxTreeCode_m_is_end_point};
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
  if ((*new_node) == NULL) RAISE(42)
  *(*new_node) = (SyntaxTreeIf){SyntaxTreeIf__dtl, NULL, 0, NULL, NULL, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeIf__dtl;
  CHECK(43, SyntaxTreeIf_parse((*new_node), parent, &((*end))) )
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
  CHECK(46, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(47, parse_new_expression(&(String){1, 0, ""}, &(self->_base._base), &(self->condition), &((*end))) )
  CHECK(48, SyntaxTreeFlowElement_parse_block(&(self->_base), parent, false, &((*end))) )
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
  CHECK(51, SyntaxTreeFlowElement_set_parent(&(else_node->_base), self->_base._base.parent) )
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
  if (self->else_node == NULL) RAISE(55)
  *self->else_node = (SyntaxTreeElse){SyntaxTreeElse__dtl, NULL, 0, NULL, NULL};
  self->else_node->_base._base._base._dtl = SyntaxTreeElse__dtl;
  CHECK(56, SyntaxTreeFlowElement_init(&(self->else_node->_base), self->_base._base.parent) )
  self->else_node->_base.block->_base.variables = malloc(sizeof(List));
  if (self->else_node->_base.block->_base.variables == NULL) RAISE(57)
  *self->else_node->_base.block->_base.variables = (List){NULL, NULL};
  self->else_node->_base.block->code_nodes = malloc(sizeof(List));
  if (self->else_node->_base.block->code_nodes == NULL) RAISE(58)
  *self->else_node->_base.block->code_nodes = (List){NULL, NULL};
  CHECK(59, List_add(self->else_node->_base.block->code_nodes, &(new_if->_base._base)) )
  CHECK(60, SyntaxTreeFlowElement_set_parent(&(new_if->_base), self->else_node->_base.block) )
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
  CHECK(63, SyntaxTreeNode_analyze_expression(&(self->_base._base._base), self->condition, &(glob->type_bool->_base)) )
  CHECK(64, SyntaxTreeFlowElement_analyze(&(self->_base)) )
  if (NULL != self->else_node) {
    CHECK(66, (self->else_node)->_base._base._base._dtl[1](self->else_node) )
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
  CHECK(73, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(74, (self->condition)->_base._dtl[5](self->condition) )
  CHECK(75, write(&(String){5, 4, "if ("}) )
  CHECK(76, (self->condition)->_base._dtl[2](self->condition) )
  CHECK(77, write(&(String){2, 1, ")"}) )
  CHECK(78, SyntaxTreeFlowElement_write_block(&(self->_base)) )
  if (NULL != self->else_node) {
    CHECK(80, (self->else_node)->_base._base._base._dtl[2](self->else_node) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeIf__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeIf__dtl[] = {(void*)SyntaxTreeFlowElement_m_link_types, (void*)SyntaxTreeIf_analyze, (void*)SyntaxTreeIf_write, (void*)SyntaxTreeCode_m_is_end_point};
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
  if ((*new_node) == NULL) RAISE(87)
  *(*new_node) = (SyntaxTreeElse){SyntaxTreeElse__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeElse__dtl;
  CHECK(88, SyntaxTreeNode_set_location(&((*new_node)->_base._base._base)) )
  CHECK(89, SyntaxTreeFlowElement_parse_block(&((*new_node)->_base), parent, false, &((*end))) )
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
  CHECK(95, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(96, write(&(String){5, 4, "else"}) )
  CHECK(97, SyntaxTreeFlowElement_write_block(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeElse__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeElse__dtl[] = {(void*)SyntaxTreeFlowElement_m_link_types, (void*)SyntaxTreeFlowElement_analyze, (void*)SyntaxTreeElse_write, (void*)SyntaxTreeCode_m_is_end_point};
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
  if ((*new_node) == NULL) RAISE(104)
  *(*new_node) = (SyntaxTreeDoLoop){SyntaxTreeDoLoop__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeDoLoop__dtl;
  CHECK(105, SyntaxTreeNode_set_location(&((*new_node)->_base._base._base)) )
  CHECK(106, SyntaxTreeFlowElement_parse_block(&((*new_node)->_base), parent, true, &((*end))) )
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
  CHECK(112, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(113, write(&(String){13, 12, "while (true)"}) )
  CHECK(114, SyntaxTreeFlowElement_write_block(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeDoLoop__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeDoLoop__dtl[] = {(void*)SyntaxTreeFlowElement_m_link_types, (void*)SyntaxTreeFlowElement_analyze, (void*)SyntaxTreeDoLoop_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* For loop node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeForLoop SyntaxTreeForLoop;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeForLoop {
  SyntaxTreeFlowElement _base;
  String* index_name;
  Expression* start;
  Expression* upper_bound;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_parse_new(SyntaxTreeForLoop* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeForLoop** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_parse_new = "SyntaxTreeForLoop.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_parse_new
Returncode SyntaxTreeForLoop_parse_new(SyntaxTreeForLoop* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeForLoop** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeForLoop));
  if ((*new_node) == NULL) RAISE(125)
  *(*new_node) = (SyntaxTreeForLoop){SyntaxTreeForLoop__dtl, NULL, 0, NULL, NULL, NULL, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeForLoop__dtl;
  CHECK(126, SyntaxTreeForLoop_parse((*new_node), parent, &((*end))) )
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
  CHECK(129, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(130, read_new(&(String){2, 1, " "}, &(self->index_name), &((*end))) )
  if ((*end) != ' ') {
    CHECK(132, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){37, 36, "expected space after index name, got"}, (*end)) )
  }
  CHECK(134, SyntaxTreeNode_read_expect(&(self->_base._base._base), &(String){4, 3, "in "}) )
  CHECK(135, parse_new_expression(&(String){2, 1, ":"}, &(self->_base._base), &(self->upper_bound), &((*end))) )
  if ((*end) == ':') {
    self->start = self->upper_bound;
    CHECK(138, parse_new_expression(&(String){1, 0, ""}, &(self->_base._base), &(self->upper_bound), &((*end))) )
  }
  CHECK(140, SyntaxTreeFlowElement_parse_block(&(self->_base), parent, true, &((*end))) )
  self->_base.block->ref_variable = malloc(sizeof(SyntaxTreeVariable));
  if (self->_base.block->ref_variable == NULL) RAISE(141)
  *self->_base.block->ref_variable = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false};
  self->_base.block->ref_variable->_base._base._dtl = SyntaxTreeVariable__dtl;
  CHECK(142, string_new_copy(self->index_name, &(self->_base.block->ref_variable->name)) )
  CHECK(143, SyntaxTreeVariable_m_check_name(self->_base.block->ref_variable) )
  self->_base.block->ref_variable->access = ACCESS_VAR;
  CHECK(145, TypeData_m_new_type_instance(&(glob->type_int->_base), &(self->_base.block->ref_variable->type_instance)) )
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
    CHECK(150, SyntaxTreeNode_analyze_expression(&(self->_base._base._base), self->start, &(glob->type_int->_base)) )
  }
  CHECK(151, SyntaxTreeNode_analyze_expression(&(self->_base._base._base), self->upper_bound, &(glob->type_int->_base)) )
  CHECK(152, SyntaxTreeFlowElement_analyze(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeForLoop_m_is_in_loop(SyntaxTreeForLoop* self, Bool* is_in_loop);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeForLoop_m_is_in_loop = "SyntaxTreeForLoop.m-is-in-loop";
#define MR_FUNC_NAME _func_name_SyntaxTreeForLoop_m_is_in_loop
Returncode SyntaxTreeForLoop_m_is_in_loop(SyntaxTreeForLoop* self, Bool* is_in_loop) {
  (*is_in_loop) = true;
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
  /* {int `index`; for(`index`=`start`; `index`<`upper-bound`; ++`index`) { */
  /*    `block...` */
  /* }} */
  CHECK(161, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  if (NULL != self->start) {
    CHECK(163, (self->start)->_base._dtl[5](self->start) )
  }
  CHECK(164, (self->upper_bound)->_base._dtl[5](self->upper_bound) )
  CHECK(165, write(&(String){6, 5, "{int "}) )
  CHECK(166, write_cname(self->index_name) )
  CHECK(167, write(&(String){7, 6, "; for("}) )
  CHECK(168, write_cname(self->index_name) )
  CHECK(169, write(&(String){2, 1, "="}) )
  if (NULL != self->start) {
    CHECK(171, (self->start)->_base._dtl[2](self->start) )
  }
  else {
    CHECK(173, write(&(String){2, 1, "0"}) )
  }
  CHECK(174, write(&(String){3, 2, "; "}) )
  CHECK(175, write_cname(self->index_name) )
  CHECK(176, write(&(String){2, 1, "<"}) )
  CHECK(177, (self->upper_bound)->_base._dtl[2](self->upper_bound) )
  CHECK(178, write(&(String){5, 4, "; ++"}) )
  CHECK(179, write_cname(self->index_name) )
  CHECK(180, write(&(String){2, 1, ")"}) )
  CHECK(181, SyntaxTreeFlowElement_write_block(&(self->_base)) )
  CHECK(182, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(183, write(&(String){3, 2, "}\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeForLoop__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeForLoop__dtl[] = {(void*)SyntaxTreeFlowElement_m_link_types, (void*)SyntaxTreeForLoop_analyze, (void*)SyntaxTreeForLoop_write, (void*)SyntaxTreeCode_m_is_end_point, (void*)SyntaxTreeForLoop_m_is_in_loop};
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
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
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
