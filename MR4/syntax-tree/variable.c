#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/variable.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file25_name = "syntax-tree/variable.3.mr";
#endif
#define MR_FILE_NAME _mr_file25_name

/* MR4 compiler - Syntax tree variable */

/* Variable node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeVariable SyntaxTreeVariable;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeVariable {
  SyntaxTreeCode _base;
  String* name;
  Int access;
  TypeInstance* type_instance;
  TypeData* parent_type;
  Bool is_output;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_parse_new(SyntaxTreeVariable* self, Int access, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, SyntaxTreeVariable** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_parse_new = "SyntaxTreeVariable.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_parse_new
Returncode SyntaxTreeVariable_parse_new(SyntaxTreeVariable* self, Int access, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, SyntaxTreeVariable** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeVariable));
  if ((*new_node) == NULL) RAISE(17)
  *(*new_node) = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false};
  (*new_node)->_base._base._dtl = SyntaxTreeVariable__dtl;
  CHECK(18, SyntaxTreeVariable_parse((*new_node), access, parent_type, parent_block, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_parse(SyntaxTreeVariable* self, Int access, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_parse = "SyntaxTreeVariable.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_parse
Returncode SyntaxTreeVariable_parse(SyntaxTreeVariable* self, Int access, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end) {
  CHECK(25, SyntaxTreeNode_set_location(&(self->_base._base)) )
  self->_base.parent = parent_block;
  self->parent_type = parent_type;
  self->access = access;
  self->type_instance = malloc(sizeof(TypeInstance));
  if (self->type_instance == NULL) RAISE(29)
  *self->type_instance = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL};
  if (self->access == ACCESS_VAR || self->access == ACCESS_NEW) {
    CHECK(31, TypeInstance_parse(self->type_instance, &(String){2, 1, " "}, &(self->_base._base), &(self->_base), &((*end))) )
  }
  else {
    CHECK(33, TypeInstance_parse(self->type_instance, &(String){2, 1, " "}, &(self->_base._base), NULL, &((*end))) )
  }
  if ((*end) != ' ') {
    CHECK(35, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after type, got"}, (*end)) )
  }
  CHECK(36, read_new(&(String){2, 1, "("}, &(self->name), &((*end))) )
  CHECK(37, SyntaxTreeVariable_check_name(self) )
  if ((*end) == '(') {
    if (NULL != self->parent_type) {
      CHECK(40, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){35, 34, "type members cannot be initialized"}) )
    }
    if (!(NULL != self->_base.parent)) {
      CHECK(42, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){39, 38, "global variables cannot be initialized"}) )
    }
  }
  if (NULL != self->_base.parent && ((*end) == '(' || self->access == ACCESS_VAR || self->access == ACCESS_NEW)) {
    CHECK(45, VariableInit_parse_new(NULL, self, &((*end))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_check_name(SyntaxTreeVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_check_name = "SyntaxTreeVariable.check-name";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_check_name
Returncode SyntaxTreeVariable_check_name(SyntaxTreeVariable* self) {
  Bool _Bool124;
  CHECK(48, f_is_legal_name(self->name, false, &(_Bool124)) )
  if (!_Bool124) {
    CHECK(49, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){22, 21, "illegal variable name"}, self->name) )
  }
  if (NULL != self->parent_type) {
    SyntaxTreeVariable* field = NULL;
    Int _Int125;
    CHECK(52, TypeData_find_field(self->parent_type, self->name, &(field), &(_Int125)) )
    if (NULL != field) {
      CHECK(54, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){22, 21, "redefinition of field"}, self->name) )
    }
    SyntaxTreeFunction* meth = NULL;
    Int _Int126;
    CHECK(56, TypeData_find_meth(self->parent_type, self->name, &(meth), &(_Int126)) )
    if (NULL != meth) {
      CHECK(58, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){28, 27, "field name overrides method"}, self->name) )
    }
  }
  else {
    SyntaxTreeVariable* _SyntaxTreeVariable127;
    CHECK(61, (glob->root)->_base._base._base._dtl[4](glob->root, self->name, &(_SyntaxTreeVariable127)) )
    if (NULL != _SyntaxTreeVariable127) {
      CHECK(62, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){32, 31, "redefinition of global variable"}, self->name) )
    }
    SyntaxTreeFunction* _SyntaxTreeFunction128;
    CHECK(64, SyntaxTreeNamespace_find_function(&(glob->root->_base), self->name, &(_SyntaxTreeFunction128)) )
    if (NULL != _SyntaxTreeFunction128) {
      CHECK(65, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){33, 32, "variable name overrides function"}, self->name) )
    }
    if (NULL != self->_base.parent) {
      SyntaxTreeVariable* _SyntaxTreeVariable129;
      CHECK(68, (self->_base.parent)->_base._base._dtl[4](self->_base.parent, self->name, &(_SyntaxTreeVariable129)) )
      if (NULL != _SyntaxTreeVariable129) {
        CHECK(69, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){25, 24, "redefinition of variable"}, self->name) )
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_find_variable(SyntaxTreeVariable* self, String* name, SyntaxTreeVariable** variable, Bool* found);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_find_variable = "SyntaxTreeVariable.find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_find_variable
Returncode SyntaxTreeVariable_find_variable(SyntaxTreeVariable* self, String* name, SyntaxTreeVariable** variable, Bool* found) {
  CHECK(74, String_equal(self->name, name, &((*found))) )
  if ((*found)) {
    (*variable) = self;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_link_types(SyntaxTreeVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_link_types = "SyntaxTreeVariable.link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_link_types
Returncode SyntaxTreeVariable_link_types(SyntaxTreeVariable* self) {
  /* sys.print-raw(user "m-link-type var ") */
  /* sys.print(user self.name) */
  CHECK(81, TypeInstance_link_types(self->type_instance, &(self->_base._base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_analyze(SyntaxTreeVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_analyze = "SyntaxTreeVariable.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_analyze
Returncode SyntaxTreeVariable_analyze(SyntaxTreeVariable* self) {
  if (self->type_instance->type_data->is_primitive && self->access != ACCESS_VAR) {
    if ((self->access) < 0 || (self->access) >= (glob->access_names)->length) RAISE(85)
    CHECK(85, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){56, 55, "only \"var\" access is supported for primitive types, got"}, (&(((String*)((glob->access_names)->values))[self->access]))) )
  }
  CHECK(88, TypeInstance_analyze_lengths(self->type_instance, &(self->_base._base)) )
  if ((self->access == ACCESS_VAR || self->access == ACCESS_NEW) &&  ! self->type_instance->type_data->is_primitive &&  ! (NULL != self->_base.parent)) {
    CHECK(91, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){52, 51, "non-primitives cannot be declared \"var\" here yet..."}) )
  }
  if (self->access == ACCESS_VAR) {
    CHECK(94, TypeInstance_check_sequence(self->type_instance, &(self->_base._base)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_write(SyntaxTreeVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_write = "SyntaxTreeVariable.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_write
Returncode SyntaxTreeVariable_write(SyntaxTreeVariable* self) {
  if (NULL != self->_base.parent ||  NULL !=  self->parent_type) {
    CHECK(98, SyntaxTreeVariable_write_spaces(self) )
  }
  else {
    CHECK(100, write(&(String){2, 1, "\n"}) )
  }
  
  if (self->access == ACCESS_VAR && (self->type_instance->type_data == &(glob->type_array->_base) || self->type_instance->type_data == &(glob->type_string->_base))) {
    CHECK(105, (self)->_base._base._dtl[4](self) )
  }
  
  if (!self->type_instance->type_data->is_primitive && (self->access == ACCESS_VAR || self->access == ACCESS_AUX)) {
    CHECK(109, SyntaxTreeVariable_write_var(self) )
  }
  
  /* `type` `name`[ = 0]; */
  /* `type`* `name`[ = NULL]; */
  /* RefManager* `name`_Refman[ = NULL]; */
  if (self->type_instance->type_data == &(glob->type_func->_base)) {
    CHECK(115, FunctionArguments_write_pointer(self->type_instance->arguments, self->name) )
  }
  else {
    CHECK(117, write_cname(self->type_instance->type_data->name) )
    if (!self->type_instance->type_data->is_primitive) {
      CHECK(119, write(&(String){2, 1, "*"}) )
    }
    CHECK(120, write(&(String){2, 1, " "}) )
    CHECK(121, write_cname(self->name) )
  }
  
  if (!(NULL != self->parent_type)) {
    if (self->type_instance->type_data->is_primitive && self->type_instance->type_data != &(glob->type_func->_base)) {
      CHECK(126, write(&(String){5, 4, " = 0"}) )
    }
    else {
      CHECK(128, write(&(String){8, 7, " = NULL"}) )
    }
  }
  
  CHECK(130, write(&(String){3, 2, ";\n"}) )
  
  if (!self->type_instance->type_data->is_primitive) {
    CHECK(133, SyntaxTreeVariable_write_refman(self) )
  }
  
  if (self->type_instance->type_data->is_dynamic) {
    CHECK(136, SyntaxTreeVariable_write_dynamic(self) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_write_sequence(SyntaxTreeVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_write_sequence = "SyntaxTreeVariable.write-sequence";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_write_sequence
Returncode SyntaxTreeVariable_write_sequence(SyntaxTreeVariable* self) {
  if (self->type_instance->type_data == &(glob->type_array->_base) && self->type_instance->sub_type->type_data == &(glob->type_string->_base)) {
    /* char `name`_Chars[`length` * `string-legth`]; */
    CHECK(142, write(&(String){6, 5, "char "}) )
    CHECK(143, write_cname(self->name) )
    CHECK(144, write(&(String){8, 7, "_Chars["}) )
    CHECK(145, (self->type_instance->length)->_base._dtl[2](self->type_instance->length) )
    CHECK(146, write(&(String){4, 3, " * "}) )
    CHECK(147, (self->type_instance->sub_type->length)->_base._dtl[2](self->type_instance->sub_type->length) )
    CHECK(148, write(&(String){4, 3, "];\n"}) )
    CHECK(149, SyntaxTreeVariable_write_spaces(self) )
  }
  /* `sub-type` `name`_Values[`length`]; */
  if (self->type_instance->type_data == &(glob->type_string->_base)) {
    CHECK(152, write(&(String){6, 5, "char "}) )
  }
  else {
    if (self->type_instance->sub_type->type_data == &(glob->type_func->_base)) {
      CHECK(154, write(&(String){14, 13, "Returncode (*"}) )
    }
    else {
      CHECK(156, write_cname(self->type_instance->sub_type->type_data->name) )
      CHECK(157, write(&(String){2, 1, " "}) )
    }
  }
  CHECK(158, write_cname(self->name) )
  CHECK(159, write(&(String){9, 8, "_Values["}) )
  CHECK(160, (self->type_instance->length)->_base._dtl[2](self->type_instance->length) )
  CHECK(161, write(&(String){2, 1, "]"}) )
  if (self->type_instance->type_data == &(glob->type_array->_base) && self->type_instance->sub_type->type_data == &(glob->type_func->_base)) {
    CHECK(164, write(&(String){2, 1, ")"}) )
    CHECK(165, (self->type_instance->sub_type->arguments)->_base._dtl[2](self->type_instance->sub_type->arguments) )
  }
  CHECK(166, write(&(String){3, 2, ";\n"}) )
  CHECK(167, SyntaxTreeVariable_write_spaces(self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_write_var(SyntaxTreeVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_write_var = "SyntaxTreeVariable.write-var";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_write_var
Returncode SyntaxTreeVariable_write_var(SyntaxTreeVariable* self) {
  /* `type` `name`_Var = {...}; */
  CHECK(171, write_cname(self->type_instance->type_data->name) )
  CHECK(172, write(&(String){2, 1, " "}) )
  CHECK(173, write_cname(self->name) )
  CHECK(174, write(&(String){9, 8, "_Var = {"}) )
  if (self->access == ACCESS_VAR && (self->type_instance->type_data == &(glob->type_array->_base) || self->type_instance->type_data == &(glob->type_string->_base))) {
    /* {`length`, 0, NULL} */
    CHECK(179, (self->type_instance->length)->_base._dtl[2](self->type_instance->length) )
    if (self->type_instance->type_data == &(glob->type_string->_base)) {
      CHECK(181, write(&(String){4, 3, ", 0"}) )
    }
    CHECK(182, write(&(String){7, 6, ", NULL"}) )
  }
  else {
    Int bases = 0;
    TypeData* type_data = self->type_instance->type_data->base_type;
    while (true) {
      if (!(NULL != type_data)) break;
      type_data = type_data->base_type;
      bases += 1;
      CHECK(190, write(&(String){2, 1, "{"}) )
    }
    CHECK(191, write(&(String){2, 1, "0"}) )
    {int n; for (n = (0); n < (bases); ++n) {
      CHECK(193, write(&(String){2, 1, "}"}) )
    }}
  }
  CHECK(194, write(&(String){4, 3, "};\n"}) )
  CHECK(195, SyntaxTreeVariable_write_spaces(self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_write_refman(SyntaxTreeVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_write_refman = "SyntaxTreeVariable.write-refman";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_write_refman
Returncode SyntaxTreeVariable_write_refman(SyntaxTreeVariable* self) {
  CHECK(198, SyntaxTreeVariable_write_spaces(self) )
  CHECK(199, write(&(String){13, 12, "RefManager* "}) )
  CHECK(200, write_cname(self->name) )
  CHECK(201, write(&(String){8, 7, "_Refman"}) )
  if (!(NULL != self->parent_type)) {
    CHECK(203, write(&(String){8, 7, " = NULL"}) )
  }
  CHECK(204, write(&(String){3, 2, ";\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_write_dynamic(SyntaxTreeVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_write_dynamic = "SyntaxTreeVariable.write-dynamic";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_write_dynamic
Returncode SyntaxTreeVariable_write_dynamic(SyntaxTreeVariable* self) {
  /* `type`_Dynamic* `name`_Dynamic[ = `type`_dynamic]; */
  CHECK(208, SyntaxTreeVariable_write_spaces(self) )
  /* if ? self.parent */
  /* self.write-spaces() */
  /* else-if ? self.parent-type */
  /* write(user "  ") */
  CHECK(213, write_cname(self->type_instance->type_data->name) )
  CHECK(214, write(&(String){11, 10, "_Dynamic* "}) )
  CHECK(215, write_cname(self->name) )
  CHECK(216, write(&(String){9, 8, "_Dynamic"}) )
  if (NULL != self->_base.parent) {
    CHECK(218, write(&(String){4, 3, " = "}) )
    if (self->access == ACCESS_VAR || self->access == ACCESS_NEW) {
      CHECK(220, write(&(String){2, 1, "&"}) )
      CHECK(221, write_cname(self->type_instance->type_data->name) )
      CHECK(222, write(&(String){9, 8, "_dynamic"}) )
    }
    else {
      CHECK(224, write(&(String){5, 4, "NULL"}) )
    }
  }
  CHECK(225, write(&(String){3, 2, ";\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_write_spaces(SyntaxTreeVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_write_spaces = "SyntaxTreeVariable.write-spaces";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_write_spaces
Returncode SyntaxTreeVariable_write_spaces(SyntaxTreeVariable* self) {
  if (NULL != self->_base.parent) {
    SyntaxTreeFunction* _SyntaxTreeFunction130;
    CHECK(229, (self->_base.parent)->_base._base._dtl[5](self->_base.parent, &(_SyntaxTreeFunction130)) )
    CHECK(229, SyntaxTreeBranch_write_spaces(&(_SyntaxTreeFunction130->_base._base)) )
  }
  else {
    if (NULL != self->parent_type) {
      CHECK(231, SyntaxTreeBranch_write_spaces(&(self->parent_type->_base._base)) )
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeVariable__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeVariable__dtl[] = {(void*)SyntaxTreeVariable_link_types, (void*)SyntaxTreeVariable_analyze, (void*)SyntaxTreeVariable_write, (void*)SyntaxTreeCode_m_is_end_point, (void*)SyntaxTreeVariable_write_sequence};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct VariableInit VariableInit;
#elif MR_STAGE == MR_TYPES(2)
struct VariableInit {
  SyntaxTreeCode _base;
  InitExpression* expression_init;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode VariableInit_parse_new(VariableInit* self, SyntaxTreeVariable* variable, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_VariableInit_parse_new = "VariableInit.parse-new";
#define MR_FUNC_NAME _func_name_VariableInit_parse_new
Returncode VariableInit_parse_new(VariableInit* self, SyntaxTreeVariable* variable, Char* end) {
  VariableInit* new_node = malloc(sizeof(VariableInit));
  if (new_node == NULL) RAISE(238)
  *new_node = (VariableInit){VariableInit__dtl, NULL, 0, NULL, NULL};
  new_node->_base._base._dtl = VariableInit__dtl;
  CHECK(239, VariableInit_parse(new_node, variable, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode VariableInit_parse(VariableInit* self, SyntaxTreeVariable* variable, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_VariableInit_parse = "VariableInit.parse";
#define MR_FUNC_NAME _func_name_VariableInit_parse
Returncode VariableInit_parse(VariableInit* self, SyntaxTreeVariable* variable, Char* end) {
  CHECK(242, SyntaxTreeNode_set_location(&(self->_base._base)) )
  self->_base.parent = variable->_base.parent;
  self->expression_init = malloc(sizeof(InitExpression));
  if (self->expression_init == NULL) RAISE(244)
  *self->expression_init = (InitExpression){InitExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL, NULL};
  self->expression_init->_base._base._dtl = InitExpression__dtl;
  TypeInstance* _TypeInstance131;
  CHECK(245, TypeInstance_copy_new(variable->type_instance, &(_TypeInstance131)) )
  CHECK(245, InitExpression_parse(self->expression_init, _TypeInstance131, &(self->_base), &((*end))) )
  self->expression_init->_base.is_statement = true;
  self->expression_init->symbol = malloc(sizeof(SymbolExpression));
  if (self->expression_init->symbol == NULL) RAISE(248)
  *self->expression_init->symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, NULL, NULL, NULL};
  self->expression_init->symbol->_base._base._dtl = SymbolExpression__dtl;
  CHECK(249, string_new_copy(variable->name, &(self->expression_init->symbol->name)) )
  self->expression_init->symbol->variable = variable;
  CHECK(252, TypeInstance_copy_new(variable->type_instance, &(self->expression_init->symbol->_base.result_type)) )
  self->expression_init->symbol->_base.access = variable->access;
  CHECK(255, List_add(variable->_base.parent->code_nodes, &(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode VariableInit_analyze(VariableInit* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_VariableInit_analyze = "VariableInit.analyze";
#define MR_FUNC_NAME _func_name_VariableInit_analyze
Returncode VariableInit_analyze(VariableInit* self) {
  CHECK(258, (self->expression_init)->_base._base._dtl[1](self->expression_init) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode VariableInit_write(VariableInit* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_VariableInit_write = "VariableInit.write";
#define MR_FUNC_NAME _func_name_VariableInit_write
Returncode VariableInit_write(VariableInit* self) {
  CHECK(261, (self->expression_init)->_base._base._dtl[2](self->expression_init) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func VariableInit__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func VariableInit__dtl[] = {(void*)SyntaxTreeNode_link_types, (void*)VariableInit_analyze, (void*)VariableInit_write, (void*)SyntaxTreeCode_m_is_end_point};
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
#include "expression/slice.c"
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
#include "syntax-tree/type-instance.c"
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
