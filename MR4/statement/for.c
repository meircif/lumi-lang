#ifndef MR_MAINFILE
#define MR_MAINFILE "statement/for.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file24_name = "statement/for.3.mr";
#endif
#define MR_FILE_NAME _mr_file24_name

/* MR4 compiler - Syntax tree for loop */

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
  if ((*new_node) == NULL) RAISE(16)
  *(*new_node) = (SyntaxTreeForLoop){SyntaxTreeForLoop__dtl, NULL, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
  (*new_node)->_base._base._base._dtl = SyntaxTreeForLoop__dtl;
  CHECK(17, SyntaxTreeForLoop_parse((*new_node), parent, &((*end))) )
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
  CHECK(20, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(21, read_new(&(String){2, 1, " "}, &(self->item_name), &((*end))) )
  if ((*end) != ' ') {
    CHECK(23, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){37, 36, "expected space after index name, got"}, (*end)) )
  }
  CHECK(25, SyntaxTreeNode_read_expect(&(self->_base._base._base), &(String){4, 3, "in "}) )
  CHECK(26, parse_new_expression(&(String){2, 1, ":"}, &(self->_base._base), &(self->iterator), &((*end))) )
  if ((*end) == ':') {
    self->start = self->iterator;
    CHECK(29, parse_new_expression(&(String){1, 0, ""}, &(self->_base._base), &(self->iterator), &((*end))) )
  }
  
  CHECK(31, SyntaxTreeFlowElement_parse_block(&(self->_base), parent, true, &((*end))) )
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
    CHECK(36, SyntaxTreeNode_analyze_expression(&(self->_base._base._base), self->start, glob->type_int) )
    CHECK(37, SyntaxTreeNode_analyze_expression(&(self->_base._base._base), self->iterator, glob->type_int) )
    CHECK(38, TypeData_m_new_type_instance(glob->type_int, &(type_instance)) )
  }
  else {
    CHECK(40, (self->iterator)->_base._dtl[2](self->iterator) )
    if (!(NULL != self->iterator->result_type)) {
      CHECK(42, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){31, 30, "cannot iterate void expression"}) )
    }
    if (self->iterator->result_type->type_data == glob->type_int) {
      CHECK(44, TypeData_m_new_type_instance(glob->type_int, &(type_instance)) )
    }
    else {
      if (self->iterator->result_type->type_data == glob->type_string) {
        CHECK(46, TypeData_m_new_type_instance(glob->type_char, &(type_instance)) )
      }
      else {
        if (self->iterator->result_type->type_data == glob->type_array) {
          CHECK(48, TypeInstance_copy_new(((TypeInstance*)(self->iterator->result_type->parameters->first->item)), &(type_instance)) )
        }
        else {
          CHECK(51, SyntaxTreeForLoop_get_iterator_type(self, &(type_instance)) )
        }
      }
    }
  }
  
  CHECK(53, (self->_base._base.parent)->_base._base._dtl[7](self->_base._base.parent, self->item_name, NULL, &(self->item)) )
  if (NULL != self->item) {
    Int _Int137;
    CHECK(54, TypeInstance_check_assign_to(type_instance, self->item->access, self->item->type_instance, self->item->access, &(self->_base._base._base), &(_Int137)) )
    free(type_instance);
    free(self->item_name);
  }
  else {
    SyntaxTreeVariable* item = malloc(sizeof(SyntaxTreeVariable));
    if (item == NULL) RAISE(62)
    *item = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, NULL, 0, NULL, NULL, false, false, false, false};
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
    CHECK(70, SyntaxTreeCode_get_function(&(self->_base._base), &(function)) )
    item->_base.parent = &(function->_base);
    self->item = item;
    CHECK(73, List_add(function->_base._base.variables, item) )
  }
  self->item_name = NULL;
  
  if (self->iterator->result_type->type_data != glob->type_int) {
    self->aux_symbol = malloc(sizeof(SymbolExpression));
    if (self->aux_symbol == NULL) RAISE(77)
    *self->aux_symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL, false};
    self->aux_symbol->_base._base._dtl = SymbolExpression__dtl;
    self->aux_symbol->_base.code_node = &(self->_base._base);
    CHECK(79, TypeInstance_copy_new(self->iterator->result_type, &(self->aux_symbol->_base.result_type)) )
    SyntaxTreeFunction* _SyntaxTreeFunction138;
    CHECK(80, SyntaxTreeCode_get_function(&(self->_base._base), &(_SyntaxTreeFunction138)) )
    CHECK(80, SyntaxTreeFunction_add_aux_variable(_SyntaxTreeFunction138, ACCESS_USER, false, self->iterator->result_type, &(self->aux_symbol->variable)) )
    CHECK(83, string_new_copy(self->aux_symbol->variable->name, &(self->aux_symbol->name)) )
  }
  
  CHECK(86, SyntaxTreeFlowElement_analyze(&(self->_base)) )
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
  Int _Int139;
  CHECK(89, TypeData_find_meth(self->iterator->result_type->type_data, &(String){4, 3, "has"}, &(self->has_func), &(_Int139)) )
  if (!(NULL != self->has_func)) {
    CHECK(92, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){50, 49, "cannot iterate type with no \"has\" named method - "}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->has_func->arguments->parameters->first->next) {
    CHECK(96, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){45, 44, "iterator \"has\" method has parameters in type"}, self->iterator->result_type->type_data->name) )
  }
  if (!(NULL != self->has_func->arguments->outputs->first)) {
    CHECK(100, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){45, 44, "iterator \"has\" method has no outputs in type"}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->has_func->arguments->outputs->first->next) {
    CHECK(104, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){55, 54, "iterator \"has\" method has more than one output in type"}, self->iterator->result_type->type_data->name) )
  }
  TypeInstance* _TypeInstance140;
  CHECK(107, (((Argument*)(self->has_func->arguments->outputs->first->item)))->_base._dtl[7](((Argument*)(self->has_func->arguments->outputs->first->item)), &(_TypeInstance140)) )
  if (_TypeInstance140->type_data != glob->type_bool) {
    CHECK(109, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){51, 50, "iterator \"has\" method output is not \"Bool\" in type"}, self->iterator->result_type->type_data->name) )
  }
  
  Int _Int141;
  CHECK(113, TypeData_find_meth(self->iterator->result_type->type_data, &(String){4, 3, "get"}, &(self->get_func), &(_Int141)) )
  if (!(NULL != self->get_func)) {
    CHECK(116, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){50, 49, "cannot iterate type with no \"get\" named method - "}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->get_func->arguments->parameters->first->next) {
    CHECK(120, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){45, 44, "iterator \"get\" method has parameters in type"}, self->iterator->result_type->type_data->name) )
  }
  if (!(NULL != self->get_func->arguments->outputs->first)) {
    CHECK(124, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){45, 44, "iterator \"get\" method has no outputs in type"}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->get_func->arguments->outputs->first->next) {
    CHECK(128, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){55, 54, "iterator \"get\" method has more than one output in type"}, self->iterator->result_type->type_data->name) )
  }
  if (((Argument*)(self->get_func->arguments->outputs->first->item))->access == ACCESS_OWNER) {
    CHECK(132, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){56, 55, "iterator \"get\" method output has \"owner\" access in type"}, self->iterator->result_type->type_data->name) )
  }
  
  TypeInstance* _TypeInstance142;
  CHECK(136, (((Argument*)(self->get_func->arguments->outputs->first->item)))->_base._dtl[7](((Argument*)(self->get_func->arguments->outputs->first->item)), &(_TypeInstance142)) )
  CHECK(136, TypeInstance_f_new_replace_params(_TypeInstance142, self->iterator->result_type, 0, &((*type_instance))) )
  
  Int _Int143;
  CHECK(139, TypeData_find_meth(self->iterator->result_type->type_data, &(String){5, 4, "next"}, &(self->next_func), &(_Int143)) )
  if (!(NULL != self->next_func)) {
    CHECK(142, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){51, 50, "cannot iterate type with no \"next\" named method - "}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->next_func->arguments->parameters->first->next) {
    CHECK(146, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){46, 45, "iterator \"next\" method has parameters in type"}, self->iterator->result_type->type_data->name) )
  }
  if (NULL != self->next_func->arguments->outputs->first) {
    CHECK(150, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){43, 42, "iterator \"next\" method has outputs in type"}, self->iterator->result_type->type_data->name) )
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
    CHECK(157, SyntaxTreeForLoop_write_assign(self, self->aux_symbol->variable, self->iterator, self->_base._base.parent) )
  }
  CHECK(159, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  if (NULL != self->start) {
    CHECK(161, (self->start)->_base._dtl[9](self->start) )
  }
  if (iterator_type == glob->type_int) {
    CHECK(163, SyntaxTreeForLoop_write_int_iter(self) )
  }
  else {
    if (iterator_type == glob->type_string || iterator_type == glob->type_array) {
      CHECK(165, SyntaxTreeForLoop_write_seq(self) )
    }
    else {
      CHECK(167, SyntaxTreeForLoop_write_iter(self) )
    }
  }
  if (NULL != self->aux_symbol) {
    EmptyExpression* empty = malloc(sizeof(EmptyExpression));
    if (empty == NULL) RAISE(169)
    *empty = (EmptyExpression){EmptyExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false};
    empty->_base._base._dtl = EmptyExpression__dtl;
    CHECK(170, SyntaxTreeForLoop_write_assign(self, self->aux_symbol->variable, &(empty->_base), self->_base._base.parent) )
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
  if (symbol == NULL) RAISE(181)
  *symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL, false};
  symbol->_base._base._dtl = SymbolExpression__dtl;
  CHECK(182, string_new_copy(item->name, &(symbol->name)) )
  CHECK(183, TypeInstance_copy_new(item->type_instance, &(symbol->_base.result_type)) )
  
  BinaryExpression* assign = malloc(sizeof(BinaryExpression));
  if (assign == NULL) RAISE(185)
  *assign = (BinaryExpression){BinaryExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL, NULL};
  assign->_base._base._base._dtl = BinaryExpression__dtl;
  assign->_base._base.top = true;
  assign->_base._base.is_statement = true;
  assign->_base._base.code_node = &(expression_node->_base);
  assign->left_expression = &(symbol->_base);
  CHECK(190, NameMap_find(glob->operator_map, &(String){3, 2, ":="}, (void**)&(assign->_base.operator)) )
  assign->_base.right_expression = value;
  
  expression_node->expression = &(assign->_base._base);
  CHECK(194, (expression_node)->_base._base._dtl[4](expression_node) )
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
  CHECK(200, write(&(String){6, 5, "for ("}) )
  CHECK(201, write_cname(self->item->name) )
  CHECK(202, write(&(String){4, 3, " = "}) )
  if (NULL != self->start) {
    CHECK(204, (self->start)->_base._dtl[4](self->start) )
  }
  else {
    CHECK(206, write(&(String){2, 1, "0"}) )
  }
  CHECK(207, write(&(String){3, 2, "; "}) )
  CHECK(208, write_cname(self->item->name) )
  CHECK(209, write(&(String){4, 3, " < "}) )
  CHECK(210, (self->iterator)->_base._dtl[4](self->iterator) )
  CHECK(211, write(&(String){5, 4, "; ++"}) )
  CHECK(212, write_cname(self->item->name) )
  CHECK(213, write(&(String){2, 1, ")"}) )
  CHECK(214, SyntaxTreeFlowElement_write_block(&(self->_base)) )
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
  CHECK(221, write(&(String){6, 5, "{int "}) )
  CHECK(222, write_cname(self->item->name) )
  CHECK(223, write(&(String){14, 13, "_Index; for ("}) )
  CHECK(224, write_cname(self->item->name) )
  CHECK(225, write(&(String){13, 12, "_Index = 0; "}) )
  CHECK(226, write_cname(self->item->name) )
  CHECK(227, write(&(String){10, 9, "_Index < "}) )
  CHECK(228, (self->aux_symbol)->_base._base._dtl[4](self->aux_symbol) )
  CHECK(229, write(&(String){13, 12, "->length; ++"}) )
  CHECK(230, write_cname(self->item->name) )
  CHECK(231, write(&(String){11, 10, "_Index) {\n"}) )
  
  SymbolExpression* index_symbol = malloc(sizeof(SymbolExpression));
  if (index_symbol == NULL) RAISE(233)
  *index_symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL, false};
  index_symbol->_base._base._dtl = SymbolExpression__dtl;
  CHECK(234, string_new_concat(self->item->name, &(String){7, 6, "_Index"}, &(index_symbol->name)) )
  SliceExpression* slice = malloc(sizeof(SliceExpression));
  if (slice == NULL) RAISE(236)
  *slice = (SliceExpression){SliceExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL};
  slice->_base._base._dtl = SliceExpression__dtl;
  slice->_base.top = true;
  slice->_base._base.line_number = self->_base._base._base.line_number;
  slice->sequence = &(self->aux_symbol->_base);
  slice->index = &(index_symbol->_base);
  CHECK(241, TypeInstance_copy_new(self->item->type_instance, &(slice->_base.result_type)) )
  CHECK(242, SyntaxTreeForLoop_write_assign(self, self->item, &(slice->_base), self->_base.block) )
  
  CHECK(244, SyntaxTreeFlowElement_write_block_body(&(self->_base)) )
  
  CHECK(246, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(247, write(&(String){4, 3, "}}\n"}) )
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
  CHECK(258, write(&(String){16, 15, "while (true) {\n"}) )
  CHECK(259, SyntaxTreeBranch_write_spaces(&(self->_base.block->_base)) )
  CHECK(260, write(&(String){6, 5, "Bool "}) )
  CHECK(261, write_cname(self->item->name) )
  CHECK(262, write(&(String){15, 14, "_Has = false;\n"}) )
  
  SymbolExpression* has_symbol = malloc(sizeof(SymbolExpression));
  if (has_symbol == NULL) RAISE(264)
  *has_symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL, false};
  has_symbol->_base._base._dtl = SymbolExpression__dtl;
  CHECK(265, string_new_concat(self->item->name, &(String){5, 4, "_Has"}, &(has_symbol->name)) )
  CHECK(266, TypeData_m_new_type_instance(glob->type_bool, &(has_symbol->_base.result_type)) )
  CallArgument* has_arg = malloc(sizeof(CallArgument));
  if (has_arg == NULL) RAISE(267)
  *has_arg = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, NULL, false, false, false};
  has_arg->_base._base._dtl = CallArgument__dtl;
  has_arg->value = &(has_symbol->_base);
  CHECK(269, SyntaxTreeForLoop_write_iter_meth(self, self->has_func, has_arg) )
  
  CHECK(271, SyntaxTreeBranch_write_spaces(&(self->_base.block->_base)) )
  CHECK(272, write(&(String){6, 5, "if (!"}) )
  CHECK(273, write_cname(self->item->name) )
  CHECK(274, write(&(String){14, 13, "_Has) break;\n"}) )
  
  SymbolExpression* item_symbol = malloc(sizeof(SymbolExpression));
  if (item_symbol == NULL) RAISE(276)
  *item_symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL, false};
  item_symbol->_base._base._dtl = SymbolExpression__dtl;
  CHECK(277, string_new_copy(self->item->name, &(item_symbol->name)) )
  CHECK(278, TypeInstance_copy_new(self->item->type_instance, &(item_symbol->_base.result_type)) )
  CallArgument* item_arg = malloc(sizeof(CallArgument));
  if (item_arg == NULL) RAISE(279)
  *item_arg = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, NULL, false, false, false};
  item_arg->_base._base._dtl = CallArgument__dtl;
  item_arg->value = &(item_symbol->_base);
  TypeInstance* _TypeInstance144;
  CHECK(281, (((Argument*)(self->get_func->arguments->outputs->first->item)))->_base._dtl[7](((Argument*)(self->get_func->arguments->outputs->first->item)), &(_TypeInstance144)) )
  item_arg->is_generic = _TypeInstance144->type_data == glob->type_generic;
  CHECK(284, SyntaxTreeForLoop_write_iter_meth(self, self->get_func, item_arg) )
  
  CHECK(286, SyntaxTreeFlowElement_write_block_body(&(self->_base)) )
  
  CHECK(288, SyntaxTreeForLoop_write_iter_meth(self, self->next_func, NULL) )
  CHECK(289, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
  CHECK(290, write(&(String){3, 2, "}\n"}) )
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
  if (symbol == NULL) RAISE(297)
  *symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL, false};
  symbol->_base._base._dtl = SymbolExpression__dtl;
  symbol->function = meth;
  
  CallArgument* self_arg = malloc(sizeof(CallArgument));
  if (self_arg == NULL) RAISE(300)
  *self_arg = (CallArgument){CallArgument__dtl, NULL, 0, 0, false, false, NULL, NULL, NULL, false, false, false};
  self_arg->_base._base._dtl = CallArgument__dtl;
  self_arg->is_dynamic = self->aux_symbol->_base.result_type->type_data->is_dynamic;
  self_arg->value = &(self->aux_symbol->_base);
  
  CallExpression* call = malloc(sizeof(CallExpression));
  if (call == NULL) RAISE(304)
  *call = (CallExpression){CallExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, false};
  call->_base._base._dtl = CallExpression__dtl;
  call->_base._base.line_number = self->_base._base._base.line_number;
  call->_base.top = true;
  call->_base.is_statement = true;
  call->function = &(symbol->_base);
  call->arguments = malloc(sizeof(FunctionArguments));
  if (call->arguments == NULL) RAISE(309)
  *call->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  call->arguments->_base._dtl = FunctionArguments__dtl;
  CHECK(310, FunctionArguments_init(call->arguments) )
  CHECK(311, List_add(call->arguments->parameters, &(self_arg->_base)) )
  if (NULL != output_arg) {
    output_arg->_base.is_output = true;
    output_arg->code_node = &(expression_node->_base);
    CHECK(315, List_add(call->arguments->outputs, &(output_arg->_base)) )
  }
  
  expression_node->expression = &(call->_base);
  CHECK(318, (expression_node)->_base._base._dtl[4](expression_node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeForLoop__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeForLoop__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeFlowElement_link_types, (void*)SyntaxTreeForLoop_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeForLoop_write, (void*)SyntaxTreeCode_m_is_end_point};
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
#include "syntax-tree/code-flow.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "statement/enum.c"
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
