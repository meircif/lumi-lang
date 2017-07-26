#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/slice.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file10_name = "expression/slice.3.mr";
#endif
#define MR_FILE_NAME _mr_file10_name

/* MR4 compiler - Slice expression */

/* A slice expression */
#if MR_STAGE == MR_TYPEDEFS
typedef struct Slice_expression Slice_expression;
#elif MR_STAGE == MR_TYPES(1)
struct Slice_expression {
  Expression _base;
  Expression* sequence;
  Expression* index;
  Expression* second_index;
/* parsing `sequence[index]` or `sequence[index:second-index]` */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Slice_expression_parse_new(Slice_expression* self, String* ends, Expression** expression, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Slice_expression_parse_new = "Slice-expression.parse-new";
#define MR_FUNC_NAME _func_name_Slice_expression_parse_new
Returncode Slice_expression_parse_new(Slice_expression* self, String* ends, Expression** expression, Char* end) {
  Slice_expression* slice_expression = malloc(sizeof(Slice_expression));
  if (slice_expression == NULL) RAISE(11)
  *slice_expression = (Slice_expression){Slice_expression__dtl, NULL, NULL, NULL, NULL};
  slice_expression->_base._dtl = Slice_expression__dtl;
  CHECK(12, Slice_expression_parse(slice_expression, (*expression), &((*end))) )
  (*expression) = &(slice_expression->_base);
  return OK;
}
#undef MR_FUNC_NAME
#endif/* parsing `sequence[index]` or `sequence[index:second-index]` */
#if MR_STAGE == MR_DECLARATIONS
Returncode Slice_expression_parse(Slice_expression* self, Expression* sequence, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Slice_expression_parse = "Slice-expression.parse";
#define MR_FUNC_NAME _func_name_Slice_expression_parse
Returncode Slice_expression_parse(Slice_expression* self, Expression* sequence, Char* end) {
  self->sequence = sequence;
  CHECK(18, parse_new_expression(&(String){3, 2, ":]"}, &(self->index), &((*end))) )
  if ((*end) == ':') {
    CHECK(20, parse_new_expression(&(String){2, 1, "]"}, &(self->second_index), &((*end))) )
  }
  CHECK(21, read_c(&((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode Slice_expression_write(Slice_expression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_Slice_expression_write = "Slice-expression.write";
#define MR_FUNC_NAME _func_name_Slice_expression_write
Returncode Slice_expression_write(Slice_expression* self) {
  CHECK(24, (self->sequence)->_dtl[0](self->sequence) )
  CHECK(25, write(&(String){2, 1, "["}) )
  CHECK(26, (self->index)->_dtl[0](self->index) )
  if (NULL != self->second_index) {
    CHECK(28, write(&(String){2, 1, ":"}) )
    CHECK(29, (self->second_index)->_dtl[0](self->second_index) )
  }
  CHECK(30, write(&(String){2, 1, "]"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func Slice_expression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func Slice_expression__dtl[] = {Slice_expression_write};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/map.c"
#include "global/type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/variable.c"
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
#endif
#undef MR_INCLUDES
#endif

#endif
