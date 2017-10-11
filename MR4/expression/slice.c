#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/slice.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file10_name = "expression/slice.3.mr";
#endif
#define MR_FILE_NAME _mr_file10_name

/* MR4 compiler - Slice expression */

/* A slice expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SliceExpression SliceExpression;
#elif MR_STAGE == MR_TYPES(1)
struct SliceExpression {
  Expression _base;
  Expression* sequence;
  Expression* index;
  Expression* second_index;
/* parsing `sequence[index]` or `sequence[index:second-index]` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SliceExpression_parse_new(SliceExpression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SliceExpression_parse_new = "SliceExpression.parse-new";
#define MR_FUNC_NAME _func_name_SliceExpression_parse_new
Returncode SliceExpression_parse_new(SliceExpression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  SliceExpression* slice_expression = malloc(sizeof(SliceExpression));
  if (slice_expression == NULL) RAISE(11)
  *slice_expression = (SliceExpression){SliceExpression__dtl, NULL, NULL, false, false, NULL, NULL, NULL};
  slice_expression->_base._dtl = SliceExpression__dtl;
  CHECK(12, SliceExpression_parse(slice_expression, (*expression), code_node, &((*end))) )
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
  self->sequence = sequence;
  CHECK(19, parse_new_expression(&(String){3, 2, ":]"}, code_node, &(self->index), &((*end))) )
  if ((*end) == ':') {
    CHECK(21, parse_new_expression(&(String){2, 1, "]"}, code_node, &(self->second_index), &((*end))) )
  }
  CHECK(23, read_c(&((*end))) )
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
  CHECK(26, (self->sequence)->_dtl[0](self->sequence) )
  self->_base.assignable = self->sequence->assignable;
  if (!(NULL != self->sequence->result_type->type_data)) {
    CHECK(29, f_syntax_error_msg(&(String){31, 30, "cannot slice a void expression"}) )
  }
  if (self->sequence->result_type->type_data == glob->type_string) {
    CHECK(31, Expression_set_simple_type(&(self->_base), glob->type_char) )
  }
  else {
    if (self->sequence->result_type->type_data == glob->type_array) {
      CHECK(33, TypeInstance_m_copy_new(self->sequence->result_type->sub_type, &(self->_base.result_type)) )
    }
    else {
      CHECK(36, f_syntax_error(&(String){18, 17, "cannot slice type"}, self->sequence->result_type->type_data->name) )
    }
  }
  
  CHECK(40, (self->index)->_dtl[0](self->index) )
  CHECK(41, SliceExpression_m_check_index(self, self->index) )
  
  if (NULL != self->second_index) {
    CHECK(44, (self->second_index)->_dtl[0](self->second_index) )
    CHECK(45, SliceExpression_m_check_index(self, self->second_index) )
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
      CHECK(50, f_syntax_error(&(String){38, 37, "expected integer index for slice, got"}, index->result_type->type_data->name) )
    }
  }
  else {
    CHECK(54, f_syntax_error_msg(&(String){54, 53, "expected integer index for slice, got void expression"}) )
  }
  
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
  CHECK(59, (self->sequence)->_dtl[2](self->sequence) )
  CHECK(60, write(&(String){2, 1, "["}) )
  CHECK(61, (self->index)->_dtl[2](self->index) )
  if (NULL != self->second_index) {
    CHECK(63, write(&(String){2, 1, ":"}) )
    CHECK(64, (self->second_index)->_dtl[2](self->second_index) )
  }
  CHECK(65, write(&(String){2, 1, "]"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SliceExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SliceExpression__dtl[] = {(void*)SliceExpression_analyze, (void*)Expression_analyze_call, (void*)SliceExpression_write};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
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
