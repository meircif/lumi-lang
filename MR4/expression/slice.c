#ifndef MR_MAINFILE
#define MR_MAINFILE "expression/slice.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file13_name = "expression/slice.3.mr";
#endif
#define MR_FILE_NAME _mr_file13_name

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
  SymbolExpression* slice_symbol;
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
  *slice_expression = (SliceExpression){SliceExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL, NULL};
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
  self->_base.access = ACCESS_VAR;
  CHECK(22, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(23, parse_new_expression(&(String){3, 2, ":]"}, code_node, &(self->index), &((*end))) )
  if ((*end) == ':') {
    CHECK(25, parse_new_expression(&(String){2, 1, "]"}, code_node, &(self->second_index), &((*end))) )
  }
  if ((*end) != ']') {
    CHECK(28, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){18, 17, "expected \"]\", got"}, (*end)) )
  }
  CHECK(29, read_c(&((*end))) )
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
  CHECK(32, (self->sequence)->_base._dtl[2](self->sequence) )
  if (!(NULL != self->sequence->result_type)) {
    CHECK(34, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){31, 30, "cannot slice a void expression"}) )
  }
  if (self->sequence->result_type->type_data == &(glob->type_string->_base)) {
    if (!(NULL != self->second_index)) {
      CHECK(37, Expression_set_simple_type(&(self->_base), &(glob->type_char->_base)) )
    }
  }
  else {
    if (self->sequence->result_type->type_data == &(glob->type_array->_base)) {
      if (!(NULL != self->second_index)) {
        CHECK(40, TypeInstance_copy_new(((TypeInstance*)(self->sequence->result_type->sub_types->first->item)), &(self->_base.result_type)) )
      }
    }
    else {
      CHECK(43, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){18, 17, "cannot slice type"}, self->sequence->result_type->type_data->name) )
    }
  }
  self->_base.assignable = self->sequence->assignable &&  ! (NULL != self->second_index) && self->_base.result_type->type_data->is_primitive;
  
  CHECK(49, (self->index)->_base._dtl[2](self->index) )
  CHECK(50, SliceExpression_check_index(self, self->index) )
  
  if (NULL != self->second_index) {
    CHECK(53, (self->second_index)->_base._dtl[2](self->second_index) )
    CHECK(54, SliceExpression_check_index(self, self->second_index) )
    CHECK(55, TypeInstance_copy_new(self->sequence->result_type, &(self->_base.result_type)) )
    CHECK(56, Expression_add_aux_variable(&(self->_base), ACCESS_VAR, false, self->_base.result_type, &(self->slice_symbol)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SliceExpression_check_index(SliceExpression* self, Expression* index);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SliceExpression_check_index = "SliceExpression.check-index";
#define MR_FUNC_NAME _func_name_SliceExpression_check_index
Returncode SliceExpression_check_index(SliceExpression* self, Expression* index) {
  if (NULL != index->result_type) {
    if (index->result_type->type_data != &(glob->type_int->_base)) {
      CHECK(63, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){38, 37, "expected integer index for slice, got"}, index->result_type->type_data->name) )
    }
  }
  else {
    CHECK(67, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){54, 53, "expected integer index for slice, got void expression"}) )
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
  CHECK(71, (self->sequence)->_base._dtl[7](self->sequence) )
  CHECK(72, (self->index)->_base._dtl[7](self->index) )
  
  if (NULL != self->second_index) {
    CHECK(75, (self->second_index)->_base._dtl[7](self->second_index) )
    CHECK(76, Expression_write_init_var_ref(&(self->_base), self->slice_symbol) )
    CHECK(77, Expression_write_refman_init(&(self->_base), self->slice_symbol) )
    /* symbol_Var.length = second; */
    /* symbol_Var.max_length = symbol.length + 1; */
    /* symbol_Var.values = (seq)->values + (index); */
    /* symbol_Var.values = (Byte*)((seq)->values) + (index); */
    CHECK(82, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(83, (self->slice_symbol)->_base._base._dtl[3](self->slice_symbol) )
    CHECK(84, write(&(String){15, 14, "_Var.length = "}) )
    CHECK(85, (self->second_index)->_base._dtl[3](self->second_index) )
    CHECK(86, write(&(String){3, 2, ";\n"}) )
    CHECK(87, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    if (self->sequence->result_type->type_data == &(glob->type_string->_base)) {
      CHECK(89, (self->slice_symbol)->_base._base._dtl[3](self->slice_symbol) )
      CHECK(90, write(&(String){19, 18, "_Var.max_length = "}) )
      CHECK(91, (self->slice_symbol)->_base._base._dtl[3](self->slice_symbol) )
      CHECK(92, write(&(String){18, 17, "_Var.length + 1;\n"}) )
      CHECK(93, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    }
    CHECK(94, (self->slice_symbol)->_base._base._dtl[3](self->slice_symbol) )
    CHECK(95, write(&(String){16, 15, "_Var.values = ("}) )
    if (self->sequence->result_type->type_data != &(glob->type_string->_base)) {
      CHECK(97, write(&(String){9, 8, "Byte*)(("}) )
    }
    CHECK(98, (self->sequence)->_base._dtl[3](self->sequence) )
    CHECK(99, write(&(String){10, 9, ")->values"}) )
    if (self->sequence->result_type->type_data != &(glob->type_string->_base)) {
      CHECK(101, write(&(String){2, 1, ")"}) )
    }
    CHECK(102, write(&(String){5, 4, " + ("}) )
    CHECK(103, (self->index)->_base._dtl[3](self->index) )
    CHECK(104, write(&(String){4, 3, ");\n"}) )
    CHECK(105, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  }
  
  /* if (seq == NULL || seq_Refman->value == NULL) RAISE(line-num) */
  CHECK(108, write(&(String){5, 4, "if ("}) )
  CHECK(109, Expression_write_validate_ref(self->sequence) )
  CHECK(110, write(&(String){3, 2, ") "}) )
  CHECK(111, SyntaxTreeNode_write_raise(&(self->_base._base)) )
  CHECK(112, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  
  /* if ((index) < 0 || (index) >= (seq)->length) RAISE(line-num) */
  /* if ((index) < 0 || (second) < 0 || (index) + (second) > (seq)->length) */
  /*     RAISE(line-num) */
  CHECK(117, write(&(String){6, 5, "if (("}) )
  CHECK(118, (self->index)->_base._dtl[3](self->index) )
  CHECK(119, write(&(String){11, 10, ") < 0 || ("}) )
  if (NULL != self->second_index) {
    CHECK(121, (self->second_index)->_base._dtl[3](self->second_index) )
    CHECK(122, write(&(String){11, 10, ") < 0 || ("}) )
  }
  CHECK(123, (self->index)->_base._dtl[3](self->index) )
  CHECK(124, write(&(String){3, 2, ") "}) )
  if (NULL != self->second_index) {
    CHECK(126, write(&(String){4, 3, "+ ("}) )
    CHECK(127, (self->second_index)->_base._dtl[3](self->second_index) )
    CHECK(128, write(&(String){4, 3, ") >"}) )
  }
  else {
    CHECK(130, write(&(String){3, 2, ">="}) )
  }
  CHECK(131, write(&(String){3, 2, " ("}) )
  CHECK(132, (self->sequence)->_base._dtl[3](self->sequence) )
  CHECK(133, write(&(String){12, 11, ")->length) "}) )
  CHECK(134, SyntaxTreeNode_write_raise(&(self->_base._base)) )
  CHECK(135, SyntaxTreeCode_write_spaces(self->_base.code_node) )
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
    CHECK(139, (self->slice_symbol)->_base._base._dtl[3](self->slice_symbol) )
    return OK;
  }
  
  /* ((seq)->values)[index] */
  /* ((Prmitive*)((seq)->values))[index] */
  /* ((Complex**)((seq)->values))[index] */
  if (!self->_base.top) {
    CHECK(146, write(&(String){2, 1, "("}) )
  }
  CHECK(147, write(&(String){3, 2, "(("}) )
  if (self->sequence->result_type->type_data != &(glob->type_string->_base)) {
    if (self->_base.result_type->type_data == &(glob->type_func->_base) &&  NULL !=  self->_base.result_type->arguments) {
      CHECK(151, FunctionArguments_write_pointer(self->_base.result_type->arguments, &(String){2, 1, "*"}) )
    }
    else {
      CHECK(153, write_cname(self->_base.result_type->type_data->name) )
      if (!self->_base.result_type->type_data->is_primitive) {
        CHECK(155, write(&(String){2, 1, "*"}) )
      }
      CHECK(156, write(&(String){2, 1, "*"}) )
    }
    CHECK(157, write(&(String){4, 3, ")(("}) )
  }
  CHECK(158, (self->sequence)->_base._dtl[3](self->sequence) )
  CHECK(159, write(&(String){11, 10, ")->values)"}) )
  if (self->sequence->result_type->type_data != &(glob->type_string->_base)) {
    CHECK(161, write(&(String){2, 1, ")"}) )
  }
  CHECK(162, write(&(String){2, 1, "["}) )
  CHECK(163, (self->index)->_base._dtl[3](self->index) )
  CHECK(164, write(&(String){2, 1, "]"}) )
  if (!self->_base.top) {
    CHECK(166, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SliceExpression_write_dynamic(SliceExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SliceExpression_write_dynamic = "SliceExpression.write-dynamic";
#define MR_FUNC_NAME _func_name_SliceExpression_write_dynamic
Returncode SliceExpression_write_dynamic(SliceExpression* self) {
  CHECK(169, write(&(String){2, 1, "&"}) )
  CHECK(170, write_cname(self->_base.result_type->type_data->name) )
  CHECK(171, write(&(String){9, 8, "_dynamic"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SliceExpression_write_refman(SliceExpression* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SliceExpression_write_refman = "SliceExpression.write-refman";
#define MR_FUNC_NAME _func_name_SliceExpression_write_refman
Returncode SliceExpression_write_refman(SliceExpression* self) {
  CHECK(174, (self->sequence)->_base._dtl[5](self->sequence) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SliceExpression__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SliceExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SliceExpression_analyze, (void*)SliceExpression_write, (void*)SliceExpression_write_dynamic, (void*)SliceExpression_write_refman, (void*)Expression_analyze_call, (void*)SliceExpression_write_preactions};
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
#include "expression/base-type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/initialize.c"
#include "expression/symbol.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/function.c"
#include "syntax-tree/native.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "syntax-tree/test.c"
#include "syntax-tree/type.c"
#include "syntax-tree/type-instance.c"
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
