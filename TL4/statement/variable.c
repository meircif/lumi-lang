#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "statement/variable.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file30_name = "statement/variable.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file30_name

/* TL4 compiler - Syntax tree variable */

/* Variable node in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeVariable SyntaxTreeVariable;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct SyntaxTreeVariable {
  SyntaxTreeCode _base;
  String* name;
  ModuleMembers* my_module;
  Int access;
  TypeInstance* type_instance;
  TypeData* parent_type;
  Bool constant;
  Bool is_output;
  Bool is_create;
  Bool is_native;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeVariable_parse_new(SyntaxTreeVariable* self, Int access, Bool is_create, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, SyntaxTreeVariable** new_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_parse_new = "SyntaxTreeVariable.parse-new";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeVariable_parse_new
Returncode SyntaxTreeVariable_parse_new(SyntaxTreeVariable* self, Int access, Bool is_create, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, SyntaxTreeVariable** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeVariable));
  if ((*new_node) == NULL) RAISE(22)
  *(*new_node) = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, NULL, 0, NULL, NULL, false, false, false, false};
  (*new_node)->_base._base._dtl = SyntaxTreeVariable__dtl;
  CHECK(23, SyntaxTreeVariable_parse((*new_node), access, is_create, parent_type, parent_block, glob->current_module, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeVariable_parse(SyntaxTreeVariable* self, Int access, Bool is_create, TypeData* parent_type, SyntaxTreeBlock* parent_block, ModuleMembers* my_module, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_parse = "SyntaxTreeVariable.parse";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeVariable_parse
Returncode SyntaxTreeVariable_parse(SyntaxTreeVariable* self, Int access, Bool is_create, TypeData* parent_type, SyntaxTreeBlock* parent_block, ModuleMembers* my_module, Char* end) {
  CHECK(38, SyntaxTreeNode_set_location(&(self->_base._base)) )
  self->_base.parent = parent_block;
  self->parent_type = parent_type;
  self->access = access;
  self->is_create = is_create;
  self->type_instance = malloc(sizeof(TypeInstance));
  if (self->type_instance == NULL) RAISE(43)
  *self->type_instance = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL, NULL};
  if (self->is_create) {
    CHECK(45, TypeInstance_parse(self->type_instance, &(String){2, 1, " "}, &(self->_base._base), &(self->_base), 2, &((*end))) )
  }
  else {
    CHECK(48, TypeInstance_parse(self->type_instance, &(String){2, 1, " "}, &(self->_base._base), NULL, 2, &((*end))) )
  }
  if ((*end) != ' ') {
    CHECK(50, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after type, got"}, (*end)) )
  }
  CHECK(51, read_new(&(String){2, 1, "("}, &(self->name), &((*end))) )
  CHECK(52, SyntaxTreeVariable_check_name(self) )
  if ((*end) == '(' &&  NULL !=  self->parent_type) {
    CHECK(54, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){35, 34, "type members cannot be initialized"}) )
  }
  if (!(NULL != self->_base.parent) &&  ! (NULL != self->parent_type)) {
    self->_base.parent = &(glob->root->global_init->_base._base);
    self->my_module = my_module;
    CHECK(58, NameMap_add(self->my_module->variable_map, self->name, self) )
  }
  if (NULL != self->_base.parent && ((*end) == '(' || self->is_create)) {
    CHECK(60, VariableInit_parse_new(NULL, self, &((*end))) )
  }
  if (self->_base.parent == &(glob->root->global_init->_base._base)) {
    self->_base.parent = NULL;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeVariable_check_name(SyntaxTreeVariable* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_check_name = "SyntaxTreeVariable.check-name";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeVariable_check_name
Returncode SyntaxTreeVariable_check_name(SyntaxTreeVariable* self) {
  Bool _Bool195;
  CHECK(65, f_is_legal_name(self->name, NAME_DEFAULT, &(_Bool195)) )
  if (!_Bool195) {
    CHECK(66, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){22, 21, "illegal variable name"}, self->name) )
  }
  if (NULL != self->parent_type) {
    SyntaxTreeVariable* field = NULL;
    Int _Int196;
    CHECK(69, TypeData_find_field(self->parent_type, self->name, &(field), &(_Int196)) )
    if (NULL != field) {
      CHECK(71, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){22, 21, "redefinition of field"}, self->name) )
    }
    SyntaxTreeFunction* meth = NULL;
    Int _Int197;
    CHECK(73, TypeData_find_meth(self->parent_type, self->name, &(meth), &(_Int197)) )
    if (NULL != meth) {
      CHECK(75, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){28, 27, "field name overrides method"}, self->name) )
    }
  }
  else {
    ModuleMembers* _ModuleMembers198;
    CHECK(78, NameMap_find(glob->module_map, self->name, (void**)&(_ModuleMembers198)) )
    if (NULL != _ModuleMembers198) {
      CHECK(79, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){31, 30, "variable name overrides module"}, self->name) )
    }
    SyntaxTreeVariable* _SyntaxTreeVariable199;
    CHECK(81, Global_find_variable(glob, self->name, &(_SyntaxTreeVariable199)) )
    if (NULL != _SyntaxTreeVariable199) {
      CHECK(82, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){32, 31, "redefinition of global variable"}, self->name) )
    }
    SyntaxTreeFunction* _SyntaxTreeFunction200;
    CHECK(84, Global_find_function(glob, self->name, &(_SyntaxTreeFunction200)) )
    if (NULL != _SyntaxTreeFunction200) {
      CHECK(85, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){33, 32, "variable name overrides function"}, self->name) )
    }
    if (NULL != self->_base.parent) {
      SyntaxTreeVariable* _SyntaxTreeVariable201;
      CHECK(88, (self->_base.parent)->_base._base._dtl[7](self->_base.parent, self->name, NULL, &(_SyntaxTreeVariable201)) )
      if (NULL != _SyntaxTreeVariable201) {
        CHECK(89, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){25, 24, "redefinition of variable"}, self->name) )
      }
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeVariable_get_parent_type(SyntaxTreeVariable* self, TypeData** parent_type);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_get_parent_type = "SyntaxTreeVariable.get-parent-type";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeVariable_get_parent_type
Returncode SyntaxTreeVariable_get_parent_type(SyntaxTreeVariable* self, TypeData** parent_type) {
  if (NULL != self->parent_type) {
    (*parent_type) = self->parent_type;
  }
  else {
    if (NULL != self->_base.parent) {
      CHECK(96, SyntaxTreeCode_get_parent_type(&(self->_base), &((*parent_type))) )
    }
    else {
      (*parent_type) = NULL;
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeVariable_find_variable(SyntaxTreeVariable* self, String* name, String* module_name, SyntaxTreeVariable** variable);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_find_variable = "SyntaxTreeVariable.find-variable";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeVariable_find_variable
Returncode SyntaxTreeVariable_find_variable(SyntaxTreeVariable* self, String* name, String* module_name, SyntaxTreeVariable** variable) {
  Bool _Bool202;
  CHECK(102, String_equal(self->name, name, &(_Bool202)) )
  if (_Bool202) {
    (*variable) = self;
  }
  else {
    (*variable) = NULL;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeVariable_link_types(SyntaxTreeVariable* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_link_types = "SyntaxTreeVariable.link-types";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeVariable_link_types
Returncode SyntaxTreeVariable_link_types(SyntaxTreeVariable* self) {
  if (NULL != self->my_module) {
    glob->current_module = self->my_module;
  }
  CHECK(110, TypeInstance_link_types(self->type_instance, &(self->_base._base)) )
  if (NULL != self->my_module) {
    glob->current_module = NULL;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeVariable_analyze(SyntaxTreeVariable* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_analyze = "SyntaxTreeVariable.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeVariable_analyze
Returncode SyntaxTreeVariable_analyze(SyntaxTreeVariable* self) {
  if (NULL != self->my_module) {
    glob->current_module = self->my_module;
  }
  if (self->type_instance->type_data->is_primitive && self->access != ACCESS_VAR) {
    if ((self->access) < 0 || (self->access) >= (glob->access_names)->length) RAISE(118)
    CHECK(118, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){56, 55, "only \"var\" access is supported for primitive types, got"}, (&(((String*)((glob->access_names)->values))[self->access]))) )
  }
  CHECK(121, TypeInstance_analyze_lengths(self->type_instance, &(self->_base._base), self->access == ACCESS_VAR) )
  if (self->is_create && self->type_instance->type_data == glob->type_generic) {
    CHECK(123, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){39, 38, "declared variable with generic subtype"}, self->type_instance->name) )
  }
  if (self->is_create &&  ! self->type_instance->type_data->is_primitive &&  NULL !=  self->parent_type && (self->type_instance->type_data == glob->type_string || self->type_instance->type_data == glob->type_array)) {
    CHECK(130, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){45, 44, "cannot declared \"var\" field of sequence type"}, self->type_instance->type_data->name) )
  }
  if (self->is_create && self->type_instance->type_data->create_disallowed) {
    CHECK(134, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){32, 31, "cannot create objects with type"}, self->type_instance->type_data->name) )
  }
  if (self->access == ACCESS_VAR) {
    CHECK(138, TypeInstance_check_sequence(self->type_instance, &(self->_base._base)) )
  }
  if (self->is_create && self->type_instance->type_data == glob->type_array && ((TypeInstance*)(self->type_instance->parameters->first->item))->type_data == glob->type_generic) {
    CHECK(141, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){28, 27, "cannot create generic array"}) )
  }
  if (NULL != self->my_module) {
    glob->current_module = NULL;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeVariable_write_cname(SyntaxTreeVariable* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_write_cname = "SyntaxTreeVariable.write-cname";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeVariable_write_cname
Returncode SyntaxTreeVariable_write_cname(SyntaxTreeVariable* self) {
  if (NULL != self->my_module) {
    CHECK(147, ModuleMembers_write_prefix(self->my_module) )
  }
  CHECK(148, write_cname(self->name) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeVariable_write(SyntaxTreeVariable* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_write = "SyntaxTreeVariable.write";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeVariable_write
Returncode SyntaxTreeVariable_write(SyntaxTreeVariable* self) {
  if (NULL != self->_base.parent ||  NULL !=  self->parent_type) {
    CHECK(152, SyntaxTreeVariable_write_spaces(self) )
  }
  else {
    if (!self->is_native) {
      CHECK(154, write(&(String){2, 1, "\n"}) )
    }
  }
  
  if (self->access == ACCESS_VAR && self->is_create && (self->type_instance->type_data == glob->type_array || self->type_instance->type_data == glob->type_string)) {
    CHECK(159, (self)->_base._base._dtl[7](self) )
  }
  
  if (!self->type_instance->type_data->is_primitive && self->access == ACCESS_VAR &&  ! (NULL != self->parent_type)) {
    CHECK(163, SyntaxTreeVariable_write_var(self) )
  }
  
  /* `type` `name`[ = 0]; */
  /* `type`* `name`[ = NULL]; */
  /* Ref_Manager* `name`_Refman[ = NULL]; */
  if (self->type_instance->type_data == glob->type_func) {
    CHECK(169, FunctionArguments_write_pointer(self->type_instance->arguments, self->name) )
  }
  else {
    CHECK(171, TypeData_write_cname(self->type_instance->type_data) )
    if (!self->type_instance->type_data->is_primitive &&  ! (NULL != self->parent_type && self->access == ACCESS_VAR)) {
      CHECK(174, write(&(String){2, 1, "*"}) )
    }
    CHECK(175, write(&(String){2, 1, " "}) )
    CHECK(176, SyntaxTreeVariable_write_cname(self) )
  }
  
  if (!(NULL != self->parent_type) &&  ! self->is_native) {
    if (self->type_instance->type_data->is_primitive && self->type_instance->type_data != glob->type_func && self->type_instance->type_data != glob->type_ref) {
      CHECK(182, write(&(String){5, 4, " = 0"}) )
    }
    else {
      CHECK(184, write(&(String){8, 7, " = NULL"}) )
    }
  }
  
  CHECK(186, write(&(String){3, 2, ";\n"}) )
  
  if (!self->type_instance->type_data->is_primitive &&  ! (NULL != self->parent_type && self->access == ACCESS_VAR)) {
    CHECK(190, SyntaxTreeVariable_write_refman(self) )
  }
  
  if (self->type_instance->type_data->is_dynamic &&  ! (NULL != self->parent_type && self->access == ACCESS_VAR)) {
    CHECK(194, SyntaxTreeVariable_write_dynamic(self) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeVariable_write_sequence(SyntaxTreeVariable* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_write_sequence = "SyntaxTreeVariable.write-sequence";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeVariable_write_sequence
Returncode SyntaxTreeVariable_write_sequence(SyntaxTreeVariable* self) {
  if (self->type_instance->type_data == glob->type_array && ((TypeInstance*)(self->type_instance->parameters->first->item))->type_data == glob->type_string) {
    /* char `name`_Chars[`length` * `string-legth`] = {0}; */
    CHECK(200, write(&(String){6, 5, "char "}) )
    CHECK(201, SyntaxTreeVariable_write_cname(self) )
    CHECK(202, write(&(String){8, 7, "_Chars["}) )
    CHECK(203, (self->type_instance->length)->_base._dtl[4](self->type_instance->length) )
    CHECK(204, write(&(String){4, 3, " * "}) )
    CHECK(205, (((TypeInstance*)(self->type_instance->parameters->first->item))->length)->_base._dtl[4](((TypeInstance*)(self->type_instance->parameters->first->item))->length) )
    CHECK(206, write(&(String){4, 3, "];\n"}) )
    CHECK(207, SyntaxTreeVariable_write_spaces(self) )
  }
  /* `sub-type` `name`_Values[`length`]; */
  if (self->type_instance->type_data == glob->type_string) {
    CHECK(210, write(&(String){6, 5, "char "}) )
  }
  else {
    if (((TypeInstance*)(self->type_instance->parameters->first->item))->type_data == glob->type_func) {
      CHECK(212, write(&(String){14, 13, "Returncode (*"}) )
    }
    else {
      CHECK(214, TypeData_write_cname(((TypeInstance*)(self->type_instance->parameters->first->item))->type_data) )
      CHECK(215, write(&(String){2, 1, " "}) )
    }
  }
  CHECK(216, SyntaxTreeVariable_write_cname(self) )
  CHECK(217, write(&(String){9, 8, "_Values["}) )
  CHECK(218, (self->type_instance->length)->_base._dtl[4](self->type_instance->length) )
  CHECK(219, write(&(String){2, 1, "]"}) )
  if (self->type_instance->type_data == glob->type_array && ((TypeInstance*)(self->type_instance->parameters->first->item))->type_data == glob->type_func) {
    CHECK(222, write(&(String){2, 1, ")"}) )
    CHECK(223, (((TypeInstance*)(self->type_instance->parameters->first->item))->arguments)->_base._dtl[4](((TypeInstance*)(self->type_instance->parameters->first->item))->arguments) )
  }
  CHECK(224, write(&(String){4, 3, " = "}) )
  Int bases = 0;
  if (self->type_instance->type_data == glob->type_array &&  ! ((TypeInstance*)(self->type_instance->parameters->first->item))->type_data->is_primitive) {
    TypeData* type_data = ((TypeInstance*)(self->type_instance->parameters->first->item))->type_data;
    bases = 1;
    while (true) {
      CHECK(231, write(&(String){2, 1, "{"}) )
      if (!(NULL != type_data->base_type)) break;
      type_data = type_data->base_type->type_data;
      bases += 1;
    }
  }
  CHECK(235, write(&(String){4, 3, "{0}"}) )
  {int n; for (n = (0); n < (bases); ++n) {
    CHECK(237, write(&(String){2, 1, "}"}) )
  }}
  CHECK(238, write(&(String){3, 2, ";\n"}) )
  CHECK(239, SyntaxTreeVariable_write_spaces(self) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeVariable_write_var(SyntaxTreeVariable* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_write_var = "SyntaxTreeVariable.write-var";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeVariable_write_var
Returncode SyntaxTreeVariable_write_var(SyntaxTreeVariable* self) {
  /* `type` `name`_Var = {...}; */
  CHECK(243, TypeData_write_cname(self->type_instance->type_data) )
  CHECK(244, write(&(String){2, 1, " "}) )
  CHECK(245, SyntaxTreeVariable_write_cname(self) )
  CHECK(246, write(&(String){9, 8, "_Var = {"}) )
  if (self->is_create && (self->type_instance->type_data == glob->type_array || self->type_instance->type_data == glob->type_string)) {
    /* {`length`, 0, NULL} */
    CHECK(251, (self->type_instance->length)->_base._dtl[4](self->type_instance->length) )
    if (self->type_instance->type_data == glob->type_string) {
      CHECK(253, write(&(String){4, 3, ", 0"}) )
    }
    CHECK(254, write(&(String){7, 6, ", NULL"}) )
  }
  else {
    Int bases = 0;
    TypeData* type_data = self->type_instance->type_data;
    while (true) {
      if (NULL != type_data->base_type) {
        type_data = type_data->base_type->type_data;
      }
      else {
        if (((SyntaxTreeVariable*)(type_data->_base._base.variables->first->item))->access == ACCESS_VAR &&  ! ((SyntaxTreeVariable*)(type_data->_base._base.variables->first->item))->type_instance->type_data->is_primitive) {
          type_data = ((SyntaxTreeVariable*)(type_data->_base._base.variables->first->item))->type_instance->type_data;
        }
        else {
          if (!(false)) break;
        }
      }
      bases += 1;
      CHECK(267, write(&(String){2, 1, "{"}) )
    }
    CHECK(268, write(&(String){2, 1, "0"}) )
    {int n; for (n = (0); n < (bases); ++n) {
      CHECK(270, write(&(String){2, 1, "}"}) )
    }}
  }
  CHECK(271, write(&(String){4, 3, "};\n"}) )
  CHECK(272, SyntaxTreeVariable_write_spaces(self) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeVariable_write_refman(SyntaxTreeVariable* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_write_refman = "SyntaxTreeVariable.write-refman";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeVariable_write_refman
Returncode SyntaxTreeVariable_write_refman(SyntaxTreeVariable* self) {
  CHECK(275, SyntaxTreeVariable_write_spaces(self) )
  CHECK(276, write(&(String){14, 13, "Ref_Manager* "}) )
  CHECK(277, SyntaxTreeVariable_write_cname(self) )
  CHECK(278, write(&(String){8, 7, "_Refman"}) )
  if (!(NULL != self->parent_type)) {
    CHECK(280, write(&(String){8, 7, " = NULL"}) )
  }
  CHECK(281, write(&(String){3, 2, ";\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeVariable_write_dynamic(SyntaxTreeVariable* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_write_dynamic = "SyntaxTreeVariable.write-dynamic";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeVariable_write_dynamic
Returncode SyntaxTreeVariable_write_dynamic(SyntaxTreeVariable* self) {
  /* `type`_Dynamic* `name`_Dynamic[ = `type`_dynamic]; */
  CHECK(285, SyntaxTreeVariable_write_spaces(self) )
  /* if ? self.parent */
  /* self.write-spaces() */
  /* else-if ? self.parent-type */
  /* write(user "  ") */
  CHECK(290, TypeData_write_cname(self->type_instance->type_data) )
  CHECK(291, write(&(String){11, 10, "_Dynamic* "}) )
  CHECK(292, SyntaxTreeVariable_write_cname(self) )
  CHECK(293, write(&(String){9, 8, "_Dynamic"}) )
  if (!(NULL != self->parent_type)) {
    CHECK(295, write(&(String){4, 3, " = "}) )
    if (self->is_create) {
      CHECK(297, write(&(String){2, 1, "&"}) )
      CHECK(298, TypeData_write_cname(self->type_instance->type_data) )
      CHECK(299, write(&(String){9, 8, "_dynamic"}) )
    }
    else {
      CHECK(301, write(&(String){5, 4, "NULL"}) )
    }
  }
  CHECK(302, write(&(String){3, 2, ";\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeVariable_write_spaces(SyntaxTreeVariable* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_write_spaces = "SyntaxTreeVariable.write-spaces";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeVariable_write_spaces
Returncode SyntaxTreeVariable_write_spaces(SyntaxTreeVariable* self) {
  if (NULL != self->_base.parent) {
    SyntaxTreeFunction* _SyntaxTreeFunction203;
    CHECK(306, (self->_base.parent)->_base._base._dtl[8](self->_base.parent, &(_SyntaxTreeFunction203)) )
    CHECK(306, SyntaxTreeBranch_write_spaces(&(_SyntaxTreeFunction203->_base._base)) )
  }
  else {
    if (NULL != self->parent_type) {
      CHECK(308, SyntaxTreeBranch_write_spaces(&(self->parent_type->_base._base)) )
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeVariable__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeVariable__dtl[] = {(void*)SyntaxTreeVariable_get_parent_type, (void*)SyntaxTreeVariable_link_types, (void*)SyntaxTreeVariable_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeVariable_write, (void*)SyntaxTreeCode_m_is_end_point, (void*)SyntaxTreeVariable_find_variable, (void*)SyntaxTreeVariable_write_sequence};
#endif


#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct VariableInit VariableInit;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct VariableInit {
  SyntaxTreeCode _base;
  InitExpression* expression_init;
  SyntaxTreeVariable* variable;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode VariableInit_parse_new(VariableInit* self, SyntaxTreeVariable* variable, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_VariableInit_parse_new = "VariableInit.parse-new";
#define LUMI_FUNC_NAME _func_name_VariableInit_parse_new
Returncode VariableInit_parse_new(VariableInit* self, SyntaxTreeVariable* variable, Char* end) {
  VariableInit* new_node = malloc(sizeof(VariableInit));
  if (new_node == NULL) RAISE(316)
  *new_node = (VariableInit){VariableInit__dtl, NULL, 0, NULL, NULL, NULL};
  new_node->_base._base._dtl = VariableInit__dtl;
  CHECK(317, VariableInit_parse(new_node, variable, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode VariableInit_parse(VariableInit* self, SyntaxTreeVariable* variable, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_VariableInit_parse = "VariableInit.parse";
#define LUMI_FUNC_NAME _func_name_VariableInit_parse
Returncode VariableInit_parse(VariableInit* self, SyntaxTreeVariable* variable, Char* end) {
  CHECK(320, SyntaxTreeNode_set_location(&(self->_base._base)) )
  self->_base.parent = variable->_base.parent;
  self->variable = variable;
  self->expression_init = malloc(sizeof(InitExpression));
  if (self->expression_init == NULL) RAISE(323)
  *self->expression_init = (InitExpression){InitExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL, NULL};
  self->expression_init->_base._base._base._dtl = InitExpression__dtl;
  TypeInstance* _TypeInstance204;
  CHECK(324, TypeInstance_copy_new(variable->type_instance, &(_TypeInstance204)) )
  CHECK(324, InitExpression_parse(self->expression_init, _TypeInstance204, NULL, &(self->_base), &((*end))) )
  self->expression_init->_base._base.is_statement = true;
  self->expression_init->symbol = malloc(sizeof(SymbolExpression));
  if (self->expression_init->symbol == NULL) RAISE(327)
  *self->expression_init->symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL, false};
  self->expression_init->symbol->_base._base._dtl = SymbolExpression__dtl;
  CHECK(328, string_new_copy(variable->name, &(self->expression_init->symbol->name)) )
  self->expression_init->symbol->variable = variable;
  CHECK(331, TypeInstance_copy_new(variable->type_instance, &(self->expression_init->symbol->_base.result_type)) )
  self->expression_init->symbol->_base.access = variable->access;
  CHECK(334, List_add(variable->_base.parent->code_nodes, &(self->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode VariableInit_analyze(VariableInit* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_VariableInit_analyze = "VariableInit.analyze";
#define LUMI_FUNC_NAME _func_name_VariableInit_analyze
Returncode VariableInit_analyze(VariableInit* self) {
  if (self->_base.parent == &(glob->root->global_init->_base._base)) {
    glob->current_module = self->variable->my_module;
  }
  CHECK(339, (self->expression_init)->_base._base._base._dtl[2](self->expression_init) )
  if (self->_base.parent == &(glob->root->global_init->_base._base)) {
    glob->current_module = NULL;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode VariableInit_write(VariableInit* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_VariableInit_write = "VariableInit.write";
#define LUMI_FUNC_NAME _func_name_VariableInit_write
Returncode VariableInit_write(VariableInit* self) {
  if (self->variable->type_instance->type_data->is_primitive &&  ! (NULL != self->expression_init->arguments->parameters->first)) {
    return OK;
  }
  if (self->_base.parent == &(glob->root->global_init->_base._base)) {
    CHECK(348, write(&(String){25, 24, "#define LUMI_FILE_NAME \""}) )
    CHECK(349, write(self->variable->_base._base.input_file_name) )
    CHECK(350, write(&(String){3, 2, "\"\n"}) )
  }
  CHECK(351, (self->expression_init)->_base._base._base._dtl[4](self->expression_init) )
  if (self->_base.parent == &(glob->root->global_init->_base._base)) {
    CHECK(353, write(&(String){23, 22, "#undef LUMI_FILE_NAME\n"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func VariableInit__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func VariableInit__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)VariableInit_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)VariableInit_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeConstant SyntaxTreeConstant;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct SyntaxTreeConstant {
  SyntaxTreeVariable _base;
  Expression* value;
  Bool is_ordered;
  Bool ordering;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeConstant_parse_new(SyntaxTreeConstant* self, Char* end, SyntaxTreeConstant** constant);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeConstant_parse_new = "SyntaxTreeConstant.parse-new";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeConstant_parse_new
Returncode SyntaxTreeConstant_parse_new(SyntaxTreeConstant* self, Char* end, SyntaxTreeConstant** constant) {
  (*constant) = malloc(sizeof(SyntaxTreeConstant));
  if ((*constant) == NULL) RAISE(362)
  *(*constant) = (SyntaxTreeConstant){SyntaxTreeConstant__dtl, NULL, 0, NULL, NULL, NULL, 0, NULL, NULL, false, false, false, false, NULL, false, false};
  (*constant)->_base._base._base._dtl = SyntaxTreeConstant__dtl;
  CHECK(363, SyntaxTreeConstant_parse((*constant), &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeConstant_parse(SyntaxTreeConstant* self, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeConstant_parse = "SyntaxTreeConstant.parse";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeConstant_parse
Returncode SyntaxTreeConstant_parse(SyntaxTreeConstant* self, Char* end) {
  CHECK(366, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  self->_base.access = ACCESS_VAR;
  self->_base.constant = true;
  self->_base.my_module = glob->current_module;
  String* type_name = NULL;
  Int _Int205;
  CHECK(371, read_until(&(String){2, 1, " "}, false, &(type_name), &((*end)), &(_Int205)) )
  Bool _Bool206;
  CHECK(372, String_equal(type_name, &(String){4, 3, "Int"}, &(_Bool206)) )
  if (!_Bool206) {
    CHECK(373, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){41, 40, "Only \"Int\" typed constant supported, got"}, type_name) )
  }
  if ((*end) != ' ') {
    CHECK(376, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){32, 31, "expected space after \"Int\", got"}, (*end)) )
  }
  CHECK(378, read_new(&(String){2, 1, " "}, &(self->_base.name), &((*end))) )
  Bool _Bool207;
  CHECK(379, f_is_legal_name(self->_base.name, NAME_CONSTANT, &(_Bool207)) )
  if (!_Bool207) {
    CHECK(380, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){22, 21, "illegal constant name"}, self->_base.name) )
  }
  if ((*end) != ' ') {
    CHECK(382, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){40, 39, "expected space after constant name, got"}, (*end)) )
  }
  CHECK(384, parse_new_expression(&(String){1, 0, ""}, &(self->_base._base), &(self->value), &((*end))) )
  CHECK(385, TypeData_m_new_type_instance(glob->type_int, &(self->_base.type_instance)) )
  CHECK(386, NameMap_add(self->_base.my_module->variable_map, self->_base.name, &(self->_base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeConstant_link_types(SyntaxTreeConstant* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeConstant_link_types = "SyntaxTreeConstant.link-types";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeConstant_link_types
Returncode SyntaxTreeConstant_link_types(SyntaxTreeConstant* self) {
  /* do nothing */
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeConstant_analyze(SyntaxTreeConstant* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeConstant_analyze = "SyntaxTreeConstant.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeConstant_analyze
Returncode SyntaxTreeConstant_analyze(SyntaxTreeConstant* self) {
  glob->current_module = self->_base.my_module;
  CHECK(393, SyntaxTreeNode_analyze_expression(&(self->_base._base._base), self->value, glob->type_int) )
  if (!self->value->constant) {
    CHECK(395, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){22, 21, "value is not constant"}) )
  }
  glob->current_module = NULL;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeConstant_m_order_constants(SyntaxTreeConstant* self, List* ordered_list);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeConstant_m_order_constants = "SyntaxTreeConstant.m-order-constants";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeConstant_m_order_constants
Returncode SyntaxTreeConstant_m_order_constants(SyntaxTreeConstant* self, List* ordered_list) {
  if (self->is_ordered) {
    return OK;
  }
  if (self->ordering) {
    CHECK(402, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){33, 32, "recursive dependency in constant"}, self->_base.name) )
  }
  self->ordering = true;
  CHECK(405, (self->value)->_base._dtl[3](self->value, ordered_list) )
  CHECK(406, List_add(ordered_list, self) )
  self->is_ordered = true;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeConstant_write(SyntaxTreeConstant* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeConstant_write = "SyntaxTreeConstant.write";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeConstant_write
Returncode SyntaxTreeConstant_write(SyntaxTreeConstant* self) {
  if (!self->is_ordered) {
    return OK;
  }
  /* enum { `name` = `value` }; */
  CHECK(413, write(&(String){9, 8, "\nenum { "}) )
  CHECK(414, SyntaxTreeVariable_write_cname(&(self->_base)) )
  CHECK(415, write(&(String){4, 3, " = "}) )
  CHECK(416, (self->value)->_base._dtl[4](self->value) )
  CHECK(417, write(&(String){5, 4, " };\n"}) )
  self->is_ordered = false;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeConstant__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeConstant__dtl[] = {(void*)SyntaxTreeVariable_get_parent_type, (void*)SyntaxTreeConstant_link_types, (void*)SyntaxTreeConstant_analyze, (void*)SyntaxTreeConstant_m_order_constants, (void*)SyntaxTreeConstant_write, (void*)SyntaxTreeCode_m_is_end_point, (void*)SyntaxTreeVariable_find_variable, (void*)SyntaxTreeVariable_write_sequence};
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
