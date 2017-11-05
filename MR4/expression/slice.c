#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/slice.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file11_name = "expression/slice.3.mr";
#endif
#define MR_FILE_NAME _mr_file11_name

/* MR4 compiler - Slice expression */

/* A slice expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SliceExpression SliceExpression;
#elif MR_STAGE == MR_TYPES(2)
struct SliceExpression {
  Expression _base;
  Expression* sequence;
  Expression* index;
  Expression* second_index;
  Expression* slice_symbol;
/* parsing `sequence[index]` or `sequence[index:second-index]` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SliceExpression_parse_new(SliceExpression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SliceExpression_parse_new = "SliceExpression.parse-new";
#define MR_FUNC_NAME _func_name_SliceExpression_parse_new
Returncode SliceExpression_parse_new(SliceExpression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  SliceExpression* slice_expression = malloc(sizeof(SliceExpression));
  if (slice_expression == NULL) RAISE(12)
  *slice_expression = (SliceExpression){SliceExpression__dtl, NULL, 0, NULL, NULL, false, false, false, NULL, NULL, NULL, NULL};
  slice_expression->_base._base._dtl = SliceExpression__dtl;
  CHECK(13, SliceExpression_parse(slice_expression, (*expression), code_node, &((*end))) )
  (*expression) = &(slice_expression->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `sequence[index]` or `sequence[index:second-index]` */
#if MR_STAGE == MR_DECLARATIONS
Returncode SliceExpression_parse(SliceExpression* self, Expression* sequence, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SliceExpression_parse = "SliceExpression.parse";
#define MR_FUNC_NAME _func_name_SliceExpression_parse
Returncode SliceExpression_parse(SliceExpression* self, Expression* sequence, SyntaxTreeCode* code_node, Char* end) {
  self->_base.code_node = code_node;
  self->sequence = sequence;
  CHECK(21, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(22, parse_new_expression(&(String){3, 2, ":]"}, code_node, &(self->index), &((*end))) )
  if ((*end) == ':') {
    CHECK(24, parse_new_expression(&(String){2, 1, "]"}, code_node, &(self->second_index), &((*end))) )
  }
  CHECK(26, read_c(&((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SliceExpression_analyze(SliceExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SliceExpression_analyze = "SliceExpression.analyze";
#define MR_FUNC_NAME _func_name_SliceExpression_analyze
Returncode SliceExpression_analyze(SliceExpression* self) {
  CHECK(29, (self->sequence)->_base._dtl[1](self->sequence) )
  self->_base.assignable = self->sequence->assignable;
  if (!(NULL != self->sequence->result_type->type_data)) {
    CHECK(32, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){31, 30, "cannot slice a void expression"}) )
  }
  if (self->sequence->result_type->type_data == glob->type_string) {
    if (!(NULL != self->second_index)) {
      CHECK(35, Expression_set_simple_type(&(self->_base), glob->type_char) )
    }
  }
  else {
    if (self->sequence->result_type->type_data == glob->type_array) {
      if (!(NULL != self->second_index)) {
        CHECK(38, TypeInstance_m_copy_new(self->sequence->result_type->sub_type, &(self->_base.result_type)) )
      }
    }
    else {
      CHECK(40, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){18, 17, "cannot slice type"}, self->sequence->result_type->type_data->name) )
    }
  }
  
  CHECK(44, (self->index)->_base._dtl[1](self->index) )
  CHECK(45, SliceExpression_m_check_index(self, self->index) )
  
  if (NULL != self->second_index) {
    CHECK(48, (self->second_index)->_base._dtl[1](self->second_index) )
    CHECK(49, SliceExpression_m_check_index(self, self->second_index) )
    CHECK(50, TypeInstance_m_copy_new(self->sequence->result_type, &(self->_base.result_type)) )
    CHECK(51, Expression_add_aux_variable(&(self->_base), ACCESS_AUX, &(self->slice_symbol)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SliceExpression_m_check_index(SliceExpression* self, Expression* index);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SliceExpression_m_check_index = "SliceExpression.m-check-index";
#define MR_FUNC_NAME _func_name_SliceExpression_m_check_index
Returncode SliceExpression_m_check_index(SliceExpression* self, Expression* index) {
  if (NULL != index->result_type->type_data) {
    if (index->result_type->type_data != glob->type_int) {
      CHECK(56, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){38, 37, "expected integer index for slice, got"}, index->result_type->type_data->name) )
    }
  }
  else {
    CHECK(60, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){54, 53, "expected integer index for slice, got void expression"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SliceExpression_write_preactions(SliceExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SliceExpression_write_preactions = "SliceExpression.write-preactions";
#define MR_FUNC_NAME _func_name_SliceExpression_write_preactions
Returncode SliceExpression_write_preactions(SliceExpression* self) {
  CHECK(64, (self->sequence)->_base._dtl[4](self->sequence) )
  CHECK(65, (self->index)->_base._dtl[4](self->index) )
  
  if (NULL != self->second_index) {
    CHECK(68, (self->second_index)->_base._dtl[4](self->second_index) )
    /* symbol_Var.length = second; */
    /* symbol_Var.max_length = symbol.length + 1; */
    /* symbol_Var.values = (seq)->values + (index); */
    /* symbol_Var.values = (Byte*)((seq)->values) + (index); */
    CHECK(73, (self->slice_symbol)->_base._dtl[2](self->slice_symbol) )
    CHECK(74, write(&(String){15, 14, "_Var.length = "}) )
    CHECK(75, (self->second_index)->_base._dtl[2](self->second_index) )
    CHECK(76, write(&(String){3, 2, ";\n"}) )
    CHECK(77, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    if (self->sequence->result_type->type_data == glob->type_string) {
      CHECK(79, (self->slice_symbol)->_base._dtl[2](self->slice_symbol) )
      CHECK(80, write(&(String){19, 18, "_Var.max_length = "}) )
      CHECK(81, (self->slice_symbol)->_base._dtl[2](self->slice_symbol) )
      CHECK(82, write(&(String){18, 17, "_Var.length + 1;\n"}) )
      CHECK(83, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    }
    CHECK(84, (self->slice_symbol)->_base._dtl[2](self->slice_symbol) )
    CHECK(85, write(&(String){16, 15, "_Var.values = ("}) )
    if (self->sequence->result_type->type_data != glob->type_string) {
      CHECK(87, write(&(String){9, 8, "Byte*)(("}) )
    }
    CHECK(88, (self->sequence)->_base._dtl[2](self->sequence) )
    CHECK(89, write(&(String){10, 9, ")->values"}) )
    if (self->sequence->result_type->type_data != glob->type_string) {
      CHECK(91, write(&(String){2, 1, ")"}) )
    }
    CHECK(92, write(&(String){5, 4, " + ("}) )
    CHECK(93, (self->index)->_base._dtl[2](self->index) )
    CHECK(94, write(&(String){4, 3, ");\n"}) )
    CHECK(95, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  }
  
  /* if ((index) < 0 || (index) >= (seq)->length) RAISE(line-num) */
  /* if ((index) < 0 || (second) < 0 || (index) + (second) > (seq)->length) */
  /*     RAISE(line-num) */
  CHECK(100, write(&(String){6, 5, "if (("}) )
  CHECK(101, (self->index)->_base._dtl[2](self->index) )
  CHECK(102, write(&(String){11, 10, ") < 0 || ("}) )
  if (NULL != self->second_index) {
    CHECK(104, (self->second_index)->_base._dtl[2](self->second_index) )
    CHECK(105, write(&(String){11, 10, ") < 0 || ("}) )
  }
  CHECK(106, (self->index)->_base._dtl[2](self->index) )
  CHECK(107, write(&(String){3, 2, ") "}) )
  if (NULL != self->second_index) {
    CHECK(109, write(&(String){4, 3, "+ ("}) )
    CHECK(110, (self->second_index)->_base._dtl[2](self->second_index) )
    CHECK(111, write(&(String){4, 3, ") >"}) )
  }
  else {
    CHECK(113, write(&(String){3, 2, ">="}) )
  }
  CHECK(114, write(&(String){3, 2, " ("}) )
  CHECK(115, (self->sequence)->_base._dtl[2](self->sequence) )
  CHECK(116, write(&(String){12, 11, ")->length) "}) )
  CHECK(117, SyntaxTreeNode_write_raise(&(self->_base._base)) )
  CHECK(118, write(&(String){2, 1, "\n"}) )
  CHECK(119, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SliceExpression_write(SliceExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SliceExpression_write = "SliceExpression.write";
#define MR_FUNC_NAME _func_name_SliceExpression_write
Returncode SliceExpression_write(SliceExpression* self) {
  if (NULL != self->second_index) {
    CHECK(123, (self->slice_symbol)->_base._dtl[2](self->slice_symbol) )
    return OK;
  }
  
  /* (((seq)->values)[index]) */
  /* (((Prmitive*)((seq)->values))[index]) */
  /* (((Complex**)((seq)->values))[index]) */
  if (!self->_base.top) {
    CHECK(130, write(&(String){2, 1, "("}) )
  }
  CHECK(131, write(&(String){3, 2, "(("}) )
  if (self->sequence->result_type->type_data != glob->type_string) {
    CHECK(133, write_cname(self->_base.result_type->type_data->name) )
    if (!self->_base.result_type->type_data->is_primitive) {
      CHECK(135, write(&(String){2, 1, "*"}) )
    }
    CHECK(136, write(&(String){5, 4, "*)(("}) )
  }
  CHECK(137, (self->sequence)->_base._dtl[2](self->sequence) )
  CHECK(138, write(&(String){11, 10, ")->values)"}) )
  if (self->sequence->result_type->type_data != glob->type_string) {
    CHECK(140, write(&(String){2, 1, ")"}) )
  }
  CHECK(141, write(&(String){2, 1, "["}) )
  CHECK(142, (self->index)->_base._dtl[2](self->index) )
  CHECK(143, write(&(String){2, 1, "]"}) )
  if (!self->_base.top) {
    CHECK(145, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SliceExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SliceExpression__dtl[] = {(void*)SyntaxTreeNode_m_link_types, (void*)SliceExpression_analyze, (void*)SliceExpression_write, (void*)Expression_analyze_call, (void*)SliceExpression_write_preactions};
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
#include "expression/symbol.c"
#include "syntax-tree/block.c"
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
