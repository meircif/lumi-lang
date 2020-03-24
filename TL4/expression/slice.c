#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "expression/slice.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file15_name = "expression/slice.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file15_name

/* TL4 compiler - Slice expression */

/* A slice expression */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SliceExpression SliceExpression;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct SliceExpression {
  Expression _base;
  Expression* sequence;
  Expression* index;
  Expression* second_index;
  SymbolExpression* slice_symbol;
/* parsing `sequence[index]` or `sequence[index:second-index]` */};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SliceExpression_parse_new(SliceExpression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SliceExpression_parse_new = "SliceExpression.parse-new";
#define LUMI_FUNC_NAME _func_name_SliceExpression_parse_new
Returncode SliceExpression_parse_new(SliceExpression* self, String* ends, SyntaxTreeCode* code_node, Expression** expression, Char* end) {
  SliceExpression* slice_expression = malloc(sizeof(SliceExpression));
  if (slice_expression == NULL) RAISE(12)
  *slice_expression = (SliceExpression){SliceExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL};
  slice_expression->_base._base._dtl = SliceExpression__dtl;
  CHECK(13, SliceExpression_parse(slice_expression, (*expression), code_node, &((*end))) )
  (*expression) = &(slice_expression->_base);
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/* parsing `sequence[index]` or `sequence[index:second-index]` */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SliceExpression_parse(SliceExpression* self, Expression* sequence, SyntaxTreeCode* code_node, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SliceExpression_parse = "SliceExpression.parse";
#define LUMI_FUNC_NAME _func_name_SliceExpression_parse
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
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SliceExpression_analyze(SliceExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SliceExpression_analyze = "SliceExpression.analyze";
#define LUMI_FUNC_NAME _func_name_SliceExpression_analyze
Returncode SliceExpression_analyze(SliceExpression* self) {
  CHECK(32, (self->sequence)->_base._dtl[2](self->sequence) )
  if (!(NULL != self->sequence->result_type)) {
    CHECK(34, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){31, 30, "cannot slice a void expression"}) )
  }
  if (self->sequence->result_type->type_data == glob->type_string) {
    if (!(NULL != self->second_index)) {
      CHECK(37, Expression_set_simple_type(&(self->_base), glob->type_char) )
    }
  }
  else {
    if (self->sequence->result_type->type_data == glob->type_array) {
      if (!(NULL != self->second_index)) {
        CHECK(40, TypeInstance_copy_new(((TypeInstance*)(self->sequence->result_type->parameters->first->item)), &(self->_base.result_type)) )
      }
      if (((TypeInstance*)(self->sequence->result_type->parameters->first->item))->type_data == glob->type_generic) {
        CHECK(44, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){27, 26, "cannot slice generic array"}) )
      }
    }
    else {
      CHECK(46, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){18, 17, "cannot slice type"}, self->sequence->result_type->type_data->name) )
    }
  }
  self->_base.assignable = self->sequence->assignable &&  ! (NULL != self->second_index) && self->_base.result_type->type_data->is_primitive;
  
  CHECK(52, (self->index)->_base._dtl[2](self->index) )
  CHECK(53, SliceExpression_check_index(self, self->index) )
  
  if (NULL != self->second_index) {
    CHECK(56, (self->second_index)->_base._dtl[2](self->second_index) )
    CHECK(57, SliceExpression_check_index(self, self->second_index) )
    CHECK(58, TypeInstance_copy_new(self->sequence->result_type, &(self->_base.result_type)) )
    CHECK(59, Expression_add_aux_variable(&(self->_base), ACCESS_VAR, false, self->_base.result_type, &(self->slice_symbol)) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SliceExpression_check_index(SliceExpression* self, Expression* index);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SliceExpression_check_index = "SliceExpression.check-index";
#define LUMI_FUNC_NAME _func_name_SliceExpression_check_index
Returncode SliceExpression_check_index(SliceExpression* self, Expression* index) {
  if (NULL != index->result_type) {
    if (index->result_type->type_data != glob->type_int) {
      CHECK(66, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){38, 37, "expected integer index for slice, got"}, index->result_type->type_data->name) )
    }
  }
  else {
    CHECK(70, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){54, 53, "expected integer index for slice, got void expression"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SliceExpression_write_preactions(SliceExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SliceExpression_write_preactions = "SliceExpression.write-preactions";
#define LUMI_FUNC_NAME _func_name_SliceExpression_write_preactions
Returncode SliceExpression_write_preactions(SliceExpression* self) {
  CHECK(74, (self->sequence)->_base._dtl[9](self->sequence) )
  CHECK(75, (self->index)->_base._dtl[9](self->index) )
  
  if (NULL != self->second_index) {
    CHECK(78, (self->second_index)->_base._dtl[9](self->second_index) )
    CHECK(79, Expression_write_init_var_ref(&(self->_base), self->slice_symbol) )
    /* symbol_Var.length = second; */
    /* symbol_Var.max_length = symbol.length + 1; */
    /* symbol_Var.values = (seq)->values + (index); */
    /* symbol_Var.values = (Byte*)((seq)->values) + (index); */
    CHECK(84, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    CHECK(85, (self->slice_symbol)->_base._base._dtl[4](self->slice_symbol) )
    CHECK(86, write(&(String){15, 14, "_Var.length = "}) )
    CHECK(87, (self->second_index)->_base._dtl[4](self->second_index) )
    CHECK(88, write(&(String){3, 2, ";\n"}) )
    CHECK(89, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    if (self->sequence->result_type->type_data == glob->type_string) {
      CHECK(91, (self->slice_symbol)->_base._base._dtl[4](self->slice_symbol) )
      CHECK(92, write(&(String){19, 18, "_Var.max_length = "}) )
      CHECK(93, (self->slice_symbol)->_base._base._dtl[4](self->slice_symbol) )
      CHECK(94, write(&(String){18, 17, "_Var.length + 1;\n"}) )
      CHECK(95, SyntaxTreeCode_write_spaces(self->_base.code_node) )
    }
    CHECK(96, (self->slice_symbol)->_base._base._dtl[4](self->slice_symbol) )
    CHECK(97, write(&(String){16, 15, "_Var.values = ("}) )
    if (self->sequence->result_type->type_data != glob->type_string) {
      CHECK(99, write(&(String){9, 8, "Byte*)(("}) )
    }
    CHECK(100, (self->sequence)->_base._dtl[4](self->sequence) )
    CHECK(101, write(&(String){10, 9, ")->values"}) )
    if (self->sequence->result_type->type_data != glob->type_string) {
      CHECK(103, write(&(String){2, 1, ")"}) )
    }
    CHECK(104, write(&(String){5, 4, " + ("}) )
    CHECK(105, (self->index)->_base._dtl[4](self->index) )
    CHECK(106, write(&(String){4, 3, ");\n"}) )
    CHECK(107, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  }
  
  CHECK(109, Expression_write_check_ref(self->sequence) )
  CHECK(110, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  
  /* if ((index) < 0 || (index) >= (seq)->length) */
  /* if ((index) < 0 || (second) < 0 || (index) + (second) > (seq)->length) */
  /*     RAISE("slice_index") */
  CHECK(115, write(&(String){6, 5, "if (("}) )
  CHECK(116, (self->index)->_base._dtl[4](self->index) )
  CHECK(117, write(&(String){11, 10, ") < 0 || ("}) )
  if (NULL != self->second_index) {
    CHECK(119, (self->second_index)->_base._dtl[4](self->second_index) )
    CHECK(120, write(&(String){11, 10, ") < 0 || ("}) )
  }
  CHECK(121, (self->index)->_base._dtl[4](self->index) )
  CHECK(122, write(&(String){3, 2, ") "}) )
  if (NULL != self->second_index) {
    CHECK(124, write(&(String){4, 3, "+ ("}) )
    CHECK(125, (self->second_index)->_base._dtl[4](self->second_index) )
    CHECK(126, write(&(String){4, 3, ") >"}) )
  }
  else {
    CHECK(128, write(&(String){3, 2, ">="}) )
  }
  CHECK(129, write(&(String){3, 2, " ("}) )
  CHECK(130, (self->sequence)->_base._dtl[4](self->sequence) )
  CHECK(131, write(&(String){12, 11, ")->length) "}) )
  CHECK(132, SyntaxTreeNode_write_raise(&(self->_base._base), &(String){12, 11, "slice_index"}) )
  CHECK(133, SyntaxTreeCode_write_spaces(self->_base.code_node) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SliceExpression_write(SliceExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SliceExpression_write = "SliceExpression.write";
#define LUMI_FUNC_NAME _func_name_SliceExpression_write
Returncode SliceExpression_write(SliceExpression* self) {
  if (NULL != self->second_index) {
    CHECK(137, (self->slice_symbol)->_base._base._dtl[4](self->slice_symbol) )
    return OK;
  }
  
  /* ((seq)->values)[index] */
  /* ((Prmitive*)((seq)->values))[index] */
  /* ((Complex*)((seq)->values)) + index */
  if (!self->_base.top) {
    CHECK(144, write(&(String){2, 1, "("}) )
  }
  CHECK(145, write(&(String){3, 2, "(("}) )
  if (self->sequence->result_type->type_data != glob->type_string) {
    if (self->_base.result_type->type_data == glob->type_func &&  NULL !=  self->_base.result_type->arguments) {
      CHECK(149, FunctionArguments_write_pointer(self->_base.result_type->arguments, &(String){2, 1, "*"}) )
    }
    else {
      CHECK(151, TypeData_write_cname(self->_base.result_type->type_data) )
      CHECK(152, write(&(String){2, 1, "*"}) )
    }
    CHECK(153, write(&(String){4, 3, ")(("}) )
  }
  CHECK(154, (self->sequence)->_base._dtl[4](self->sequence) )
  CHECK(155, write(&(String){11, 10, ")->values)"}) )
  if (self->sequence->result_type->type_data != glob->type_string) {
    CHECK(157, write(&(String){2, 1, ")"}) )
  }
  if (self->_base.result_type->type_data->is_primitive) {
    CHECK(159, write(&(String){2, 1, "["}) )
  }
  else {
    CHECK(161, write(&(String){4, 3, " + "}) )
  }
  CHECK(162, (self->index)->_base._dtl[4](self->index) )
  if (self->_base.result_type->type_data->is_primitive) {
    CHECK(164, write(&(String){2, 1, "]"}) )
  }
  if (!self->_base.top) {
    CHECK(166, write(&(String){2, 1, ")"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SliceExpression_write_dynamic(SliceExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SliceExpression_write_dynamic = "SliceExpression.write-dynamic";
#define LUMI_FUNC_NAME _func_name_SliceExpression_write_dynamic
Returncode SliceExpression_write_dynamic(SliceExpression* self) {
  CHECK(169, write(&(String){2, 1, "&"}) )
  CHECK(170, TypeData_write_cname(self->_base.result_type->type_data) )
  CHECK(171, write(&(String){9, 8, "_dynamic"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SliceExpression_write_refman(SliceExpression* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SliceExpression_write_refman = "SliceExpression.write-refman";
#define LUMI_FUNC_NAME _func_name_SliceExpression_write_refman
Returncode SliceExpression_write_refman(SliceExpression* self) {
  CHECK(174, (self->sequence)->_base._dtl[6](self->sequence) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SliceExpression__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SliceExpression__dtl[] = {(void*)Expression_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)SliceExpression_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SliceExpression_write, (void*)SliceExpression_write_dynamic, (void*)SliceExpression_write_refman, (void*)Expression_analyze_call, (void*)Expression_analyze_mock, (void*)SliceExpression_write_preactions};
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
#include "expression/symbol.c"
#include "syntax-tree/block.c"
#include "syntax-tree/branch.c"
#include "syntax-tree/code-flow.c"
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
