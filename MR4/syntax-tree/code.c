#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/code.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file18_name = "syntax-tree/code.3.mr";
#endif
#define MR_FILE_NAME _mr_file18_name

/* MR4 compiler - Syntax tree code nodes */

/* Expression node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeExpression SyntaxTreeExpression;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeExpression {
  SyntaxTreeCode _base;
  Expression* expression;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeExpression_parse_new(SyntaxTreeExpression* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeExpression** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeExpression_parse_new = "SyntaxTreeExpression.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeExpression_parse_new
Returncode SyntaxTreeExpression_parse_new(SyntaxTreeExpression* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeExpression** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeExpression));
  if ((*new_node) == NULL) RAISE(9)
  *(*new_node) = (SyntaxTreeExpression){SyntaxTreeExpression__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeExpression__dtl;
  CHECK(10, SyntaxTreeExpression_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeExpression_parse(SyntaxTreeExpression* self, SyntaxTreeBlock* parent, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeExpression_parse = "SyntaxTreeExpression.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeExpression_parse
Returncode SyntaxTreeExpression_parse(SyntaxTreeExpression* self, SyntaxTreeBlock* parent, Char* end) {
  self->_base.parent = parent;
  CHECK(14, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(15, parse_new_expression(&(String){1, 0, ""}, &(self->_base), &(self->expression), &((*end))) )
  self->expression->is_statement = true;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeExpression_analyze(SyntaxTreeExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeExpression_analyze = "SyntaxTreeExpression.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeExpression_analyze
Returncode SyntaxTreeExpression_analyze(SyntaxTreeExpression* self) {
  CHECK(19, (self->expression)->_base._dtl[2](self->expression) )
  if (NULL != self->expression->result_type) {
    CHECK(21, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){25, 24, "statememnt has no effect"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeExpression_write(SyntaxTreeExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeExpression_write = "SyntaxTreeExpression.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeExpression_write
Returncode SyntaxTreeExpression_write(SyntaxTreeExpression* self) {
  CHECK(24, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(25, (self->expression)->_base._dtl[8](self->expression) )
  CHECK(26, (self->expression)->_base._dtl[3](self->expression) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeExpression__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeExpression_analyze, (void*)SyntaxTreeExpression_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Return statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeReturn SyntaxTreeReturn;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeReturn {
  SyntaxTreeCode _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeReturn_parse_new(SyntaxTreeReturn* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeReturn** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeReturn_parse_new = "SyntaxTreeReturn.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeReturn_parse_new
Returncode SyntaxTreeReturn_parse_new(SyntaxTreeReturn* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeReturn** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeReturn));
  if ((*new_node) == NULL) RAISE(34)
  *(*new_node) = (SyntaxTreeReturn){SyntaxTreeReturn__dtl, NULL, 0, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeReturn__dtl;
  CHECK(35, SyntaxTreeNode_set_location(&((*new_node)->_base._base)) )
  (*new_node)->_base.parent = parent;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeReturn_m_is_end_point(SyntaxTreeReturn* self, Bool* is_end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeReturn_m_is_end_point = "SyntaxTreeReturn.m-is-end-point";
#define MR_FUNC_NAME _func_name_SyntaxTreeReturn_m_is_end_point
Returncode SyntaxTreeReturn_m_is_end_point(SyntaxTreeReturn* self, Bool* is_end) {
  (*is_end) = true;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeReturn_write(SyntaxTreeReturn* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeReturn_write = "SyntaxTreeReturn.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeReturn_write
Returncode SyntaxTreeReturn_write(SyntaxTreeReturn* self) {
  CHECK(42, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(43, write(&(String){18, 17, "goto MR_cleanup;\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeReturn__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeReturn__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeReturn_write, (void*)SyntaxTreeReturn_m_is_end_point};
#endif


/* Raise statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeRaise SyntaxTreeRaise;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeRaise {
  SyntaxTreeCode _base;
  Expression* error_message;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRaise_parse_new(SyntaxTreeRaise* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeRaise** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRaise_parse_new = "SyntaxTreeRaise.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeRaise_parse_new
Returncode SyntaxTreeRaise_parse_new(SyntaxTreeRaise* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeRaise** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeRaise));
  if ((*new_node) == NULL) RAISE(52)
  *(*new_node) = (SyntaxTreeRaise){SyntaxTreeRaise__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeRaise__dtl;
  CHECK(53, SyntaxTreeRaise_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRaise_parse(SyntaxTreeRaise* self, SyntaxTreeBlock* parent, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRaise_parse = "SyntaxTreeRaise.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeRaise_parse
Returncode SyntaxTreeRaise_parse(SyntaxTreeRaise* self, SyntaxTreeBlock* parent, Char* end) {
  CHECK(56, SyntaxTreeNode_set_location(&(self->_base._base)) )
  self->_base.parent = parent;
  if ((*end) == ' ') {
    CHECK(59, parse_new_expression(&(String){1, 0, ""}, &(self->_base), &(self->error_message), &((*end))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRaise_m_is_end_point(SyntaxTreeRaise* self, Bool* is_end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRaise_m_is_end_point = "SyntaxTreeRaise.m-is-end-point";
#define MR_FUNC_NAME _func_name_SyntaxTreeRaise_m_is_end_point
Returncode SyntaxTreeRaise_m_is_end_point(SyntaxTreeRaise* self, Bool* is_end) {
  (*is_end) = true;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRaise_analyze(SyntaxTreeRaise* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRaise_analyze = "SyntaxTreeRaise.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeRaise_analyze
Returncode SyntaxTreeRaise_analyze(SyntaxTreeRaise* self) {
  if (NULL != self->error_message) {
    CHECK(67, SyntaxTreeNode_analyze_expression(&(self->_base._base), self->error_message, &(glob->type_string->_base)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRaise_write(SyntaxTreeRaise* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRaise_write = "SyntaxTreeRaise.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeRaise_write
Returncode SyntaxTreeRaise_write(SyntaxTreeRaise* self) {
  CHECK(70, SyntaxTreeCode_write_spaces(&(self->_base)) )
  if (NULL != self->error_message) {
    CHECK(72, (self->error_message)->_base._dtl[8](self->error_message) )
  }
  CHECK(73, write(&(String){12, 11, "USER_RAISE("}) )
  CHECK(74, SyntaxTreeNode_write_line_num(&(self->_base._base)) )
  CHECK(75, write(&(String){3, 2, ", "}) )
  if (NULL != self->error_message) {
    CHECK(77, (self->error_message)->_base._dtl[3](self->error_message) )
    CHECK(78, write(&(String){3, 2, ", "}) )
    CHECK(79, (self->error_message)->_base._dtl[5](self->error_message) )
  }
  else {
    CHECK(81, write(&(String){11, 10, "NULL, NULL"}) )
  }
  CHECK(82, write(&(String){3, 2, ")\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeRaise__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeRaise__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeRaise_analyze, (void*)SyntaxTreeRaise_write, (void*)SyntaxTreeRaise_m_is_end_point};
#endif


/* While statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeWhile SyntaxTreeWhile;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeWhile {
  SyntaxTreeCode _base;
  Expression* condition;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeWhile_parse_new(SyntaxTreeWhile* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeWhile** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeWhile_parse_new = "SyntaxTreeWhile.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeWhile_parse_new
Returncode SyntaxTreeWhile_parse_new(SyntaxTreeWhile* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeWhile** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeWhile));
  if ((*new_node) == NULL) RAISE(91)
  *(*new_node) = (SyntaxTreeWhile){SyntaxTreeWhile__dtl, NULL, 0, NULL, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeWhile__dtl;
  CHECK(92, SyntaxTreeWhile_parse((*new_node), parent, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeWhile_parse(SyntaxTreeWhile* self, SyntaxTreeBlock* parent, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeWhile_parse = "SyntaxTreeWhile.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeWhile_parse
Returncode SyntaxTreeWhile_parse(SyntaxTreeWhile* self, SyntaxTreeBlock* parent, Char* end) {
  self->_base.parent = parent;
  CHECK(96, SyntaxTreeNode_set_location(&(self->_base._base)) )
  if (!parent->is_in_loop) {
    CHECK(98, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){29, 28, "\"while\" used not inside loop"}) )
  }
  CHECK(99, parse_new_expression(&(String){1, 0, ""}, &(self->_base), &(self->condition), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeWhile_analyze(SyntaxTreeWhile* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeWhile_analyze = "SyntaxTreeWhile.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeWhile_analyze
Returncode SyntaxTreeWhile_analyze(SyntaxTreeWhile* self) {
  CHECK(102, SyntaxTreeNode_analyze_expression(&(self->_base._base), self->condition, &(glob->type_bool->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeWhile_write(SyntaxTreeWhile* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeWhile_write = "SyntaxTreeWhile.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeWhile_write
Returncode SyntaxTreeWhile_write(SyntaxTreeWhile* self) {
  /* if (!(`condition`) break; */
  CHECK(106, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(107, (self->condition)->_base._dtl[8](self->condition) )
  CHECK(108, write(&(String){7, 6, "if (!("}) )
  CHECK(109, (self->condition)->_base._dtl[3](self->condition) )
  CHECK(110, write(&(String){11, 10, ")) break;\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeWhile__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeWhile__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeWhile_analyze, (void*)SyntaxTreeWhile_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Continue statement in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeContinue SyntaxTreeContinue;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeContinue {
  SyntaxTreeCode _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeContinue_parse_new(SyntaxTreeContinue* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeContinue** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeContinue_parse_new = "SyntaxTreeContinue.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeContinue_parse_new
Returncode SyntaxTreeContinue_parse_new(SyntaxTreeContinue* self, SyntaxTreeBlock* parent, Char* end, SyntaxTreeContinue** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeContinue));
  if ((*new_node) == NULL) RAISE(118)
  *(*new_node) = (SyntaxTreeContinue){SyntaxTreeContinue__dtl, NULL, 0, NULL};
  (*new_node)->_base._base._dtl = SyntaxTreeContinue__dtl;
  CHECK(119, SyntaxTreeContinue_parse((*new_node), parent) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeContinue_parse(SyntaxTreeContinue* self, SyntaxTreeBlock* parent);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeContinue_parse = "SyntaxTreeContinue.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeContinue_parse
Returncode SyntaxTreeContinue_parse(SyntaxTreeContinue* self, SyntaxTreeBlock* parent) {
  CHECK(122, SyntaxTreeNode_set_location(&(self->_base._base)) )
  self->_base.parent = parent;
  if (!parent->is_in_loop) {
    CHECK(125, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){32, 31, "\"continue\" used not inside loop"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeContinue_write(SyntaxTreeContinue* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeContinue_write = "SyntaxTreeContinue.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeContinue_write
Returncode SyntaxTreeContinue_write(SyntaxTreeContinue* self) {
  CHECK(128, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(129, write(&(String){11, 10, "continue;\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeContinue__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeContinue__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeContinue_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeCoverage SyntaxTreeCoverage;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeCoverage {
  SyntaxTreeCode _base;
  Int input_file_index;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCoverage_init_new(SyntaxTreeCoverage* self, SyntaxTreeBlock* parent, SyntaxTreeCoverage** coverage_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCoverage_init_new = "SyntaxTreeCoverage.init-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeCoverage_init_new
Returncode SyntaxTreeCoverage_init_new(SyntaxTreeCoverage* self, SyntaxTreeBlock* parent, SyntaxTreeCoverage** coverage_node) {
  (*coverage_node) = malloc(sizeof(SyntaxTreeCoverage));
  if ((*coverage_node) == NULL) RAISE(137)
  *(*coverage_node) = (SyntaxTreeCoverage){SyntaxTreeCoverage__dtl, NULL, 0, NULL, 0};
  (*coverage_node)->_base._base._dtl = SyntaxTreeCoverage__dtl;
  CHECK(138, SyntaxTreeCoverage_init((*coverage_node), parent) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCoverage_init(SyntaxTreeCoverage* self, SyntaxTreeBlock* parent);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCoverage_init = "SyntaxTreeCoverage.init";
#define MR_FUNC_NAME _func_name_SyntaxTreeCoverage_init
Returncode SyntaxTreeCoverage_init(SyntaxTreeCoverage* self, SyntaxTreeBlock* parent) {
  CHECK(141, SyntaxTreeNode_set_location(&(self->_base._base)) )
  self->_base.parent = parent;
  self->input_file_index = glob->input_file_index;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCoverage_analyze(SyntaxTreeCoverage* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCoverage_analyze = "SyntaxTreeCoverage.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeCoverage_analyze
Returncode SyntaxTreeCoverage_analyze(SyntaxTreeCoverage* self) {
  if ((self->input_file_index) < 0 || (self->input_file_index) >= (glob->root->line_counts)->length) RAISE(146)
  LineCount* line_count = (&(((LineCount*)((glob->root->line_counts)->values))[self->input_file_index]));
  if ((self->_base._base.line_number) < 0 || (self->_base._base.line_number) >= (line_count->line_needs_cover)->length) RAISE(147)
  (((Bool*)((line_count->line_needs_cover)->values))[self->_base._base.line_number]) = true;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeCoverage_write(SyntaxTreeCoverage* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeCoverage_write = "SyntaxTreeCoverage.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeCoverage_write
Returncode SyntaxTreeCoverage_write(SyntaxTreeCoverage* self) {
  /* ++MR_file_coverage[`file-index`].line_count[`line-number`]; */
  CHECK(151, SyntaxTreeCode_write_spaces(&(self->_base)) )
  CHECK(152, write(&(String){20, 19, "++MR_file_coverage["}) )
  CHECK(153, write_int(self->input_file_index) )
  CHECK(154, write(&(String){14, 13, "].line_count["}) )
  CHECK(155, write_int(self->_base._base.line_number) )
  CHECK(156, write(&(String){4, 3, "];\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeCoverage__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeCoverage__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SyntaxTreeCoverage_analyze, (void*)SyntaxTreeCoverage_write, (void*)SyntaxTreeCode_m_is_end_point};
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
