#ifndef MR_MAINFILE
#define MR_MAINFILE "statement/variable.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file29_name = "statement/variable.3.mr";
#endif
#define MR_FILE_NAME _mr_file29_name

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
  Bool constant;
  Bool is_output;
  Bool is_create;
  Bool is_native;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_parse_new(SyntaxTreeVariable* self, Int access, Bool is_create, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, SyntaxTreeVariable** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_parse_new = "SyntaxTreeVariable.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_parse_new
Returncode SyntaxTreeVariable_parse_new(SyntaxTreeVariable* self, Int access, Bool is_create, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, SyntaxTreeVariable** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeVariable));
  if ((*new_node) == NULL) RAISE(21)
  *(*new_node) = (SyntaxTreeVariable){SyntaxTreeVariable__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false, false, false, false};
  (*new_node)->_base._base._dtl = SyntaxTreeVariable__dtl;
  CHECK(22, SyntaxTreeVariable_parse((*new_node), access, is_create, parent_type, parent_block, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_parse(SyntaxTreeVariable* self, Int access, Bool is_create, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_parse = "SyntaxTreeVariable.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_parse
Returncode SyntaxTreeVariable_parse(SyntaxTreeVariable* self, Int access, Bool is_create, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end) {
  CHECK(32, SyntaxTreeNode_set_location(&(self->_base._base)) )
  self->_base.parent = parent_block;
  self->parent_type = parent_type;
  self->access = access;
  self->is_create = is_create;
  self->type_instance = malloc(sizeof(TypeInstance));
  if (self->type_instance == NULL) RAISE(37)
  *self->type_instance = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL};
  if (self->is_create) {
    CHECK(39, TypeInstance_parse(self->type_instance, &(String){2, 1, " "}, &(self->_base._base), &(self->_base), &((*end))) )
  }
  else {
    CHECK(41, TypeInstance_parse(self->type_instance, &(String){2, 1, " "}, &(self->_base._base), NULL, &((*end))) )
  }
  if ((*end) != ' ') {
    CHECK(43, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after type, got"}, (*end)) )
  }
  CHECK(44, read_new(&(String){2, 1, "("}, &(self->name), &((*end))) )
  CHECK(45, SyntaxTreeVariable_check_name(self) )
  if ((*end) == '(' &&  NULL !=  self->parent_type) {
    CHECK(47, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){35, 34, "type members cannot be initialized"}) )
  }
  if (!(NULL != self->_base.parent) &&  ! (NULL != self->parent_type)) {
    self->_base.parent = &(glob->root->global_init->_base._base);
  }
  if (NULL != self->_base.parent && ((*end) == '(' || self->is_create)) {
    CHECK(51, VariableInit_parse_new(NULL, self, &((*end))) )
  }
  if (self->_base.parent == &(glob->root->global_init->_base._base)) {
    self->_base.parent = NULL;
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
  Bool _Bool165;
  CHECK(56, f_is_legal_name(self->name, NAME_DEFAULT, &(_Bool165)) )
  if (!_Bool165) {
    CHECK(57, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){22, 21, "illegal variable name"}, self->name) )
  }
  if (NULL != self->parent_type) {
    SyntaxTreeVariable* field = NULL;
    Int _Int166;
    CHECK(60, TypeData_find_field(self->parent_type, self->name, &(field), &(_Int166)) )
    if (NULL != field) {
      CHECK(62, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){22, 21, "redefinition of field"}, self->name) )
    }
    SyntaxTreeFunction* meth = NULL;
    Int _Int167;
    CHECK(64, TypeData_find_meth(self->parent_type, self->name, &(meth), &(_Int167)) )
    if (NULL != meth) {
      CHECK(66, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){28, 27, "field name overrides method"}, self->name) )
    }
  }
  else {
    SyntaxTreeVariable* _SyntaxTreeVariable168;
    CHECK(69, (glob->root)->_base._base._base._dtl[6](glob->root, self->name, &(_SyntaxTreeVariable168)) )
    if (NULL != _SyntaxTreeVariable168) {
      CHECK(70, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){32, 31, "redefinition of global variable"}, self->name) )
    }
    SyntaxTreeFunction* _SyntaxTreeFunction169;
    CHECK(72, SyntaxTreeNamespace_find_function(&(glob->root->_base), self->name, &(_SyntaxTreeFunction169)) )
    if (NULL != _SyntaxTreeFunction169) {
      CHECK(73, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){33, 32, "variable name overrides function"}, self->name) )
    }
    if (NULL != self->_base.parent) {
      SyntaxTreeVariable* _SyntaxTreeVariable170;
      CHECK(76, (self->_base.parent)->_base._base._dtl[6](self->_base.parent, self->name, &(_SyntaxTreeVariable170)) )
      if (NULL != _SyntaxTreeVariable170) {
        CHECK(77, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){25, 24, "redefinition of variable"}, self->name) )
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_get_parent_type(SyntaxTreeVariable* self, TypeData** parent_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_get_parent_type = "SyntaxTreeVariable.get-parent-type";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_get_parent_type
Returncode SyntaxTreeVariable_get_parent_type(SyntaxTreeVariable* self, TypeData** parent_type) {
  if (NULL != self->parent_type) {
    (*parent_type) = self->parent_type;
  }
  else {
    if (NULL != self->_base.parent) {
      CHECK(84, SyntaxTreeCode_get_parent_type(&(self->_base), &((*parent_type))) )
    }
    else {
      (*parent_type) = NULL;
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
  CHECK(90, String_equal(self->name, name, &((*found))) )
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
  CHECK(95, TypeInstance_link_types(self->type_instance, &(self->_base._base)) )
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
    if ((self->access) < 0 || (self->access) >= (glob->access_names)->length) RAISE(99)
    CHECK(99, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){56, 55, "only \"var\" access is supported for primitive types, got"}, (&(((String*)((glob->access_names)->values))[self->access]))) )
  }
  CHECK(102, TypeInstance_analyze_lengths(self->type_instance, &(self->_base._base), self->access == ACCESS_VAR) )
  if (self->is_create && self->type_instance->type_data == &(glob->type_generic->_base)) {
    CHECK(104, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){39, 38, "declared variable with generic subtype"}, self->type_instance->name) )
  }
  if (self->is_create &&  ! self->type_instance->type_data->is_primitive &&  NULL !=  self->parent_type) {
    if (self->type_instance->type_data == &(glob->type_string->_base) || self->type_instance->type_data == &(glob->type_array->_base)) {
      CHECK(111, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){45, 44, "cannot declared \"var\" field of sequence type"}, self->type_instance->type_data->name) )
    }
    CHECK(114, SyntaxTreeVariable_check_var_recursion(self, self) )
  }
  if (self->access == ACCESS_VAR) {
    CHECK(116, TypeInstance_check_sequence(self->type_instance, &(self->_base._base)) )
  }
  if (self->is_create && self->type_instance->type_data == &(glob->type_array->_base) && ((TypeInstance*)(self->type_instance->parameters->first->item))->type_data == &(glob->type_generic->_base)) {
    CHECK(119, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){28, 27, "cannot create generic array"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_check_var_recursion(SyntaxTreeVariable* self, SyntaxTreeVariable* variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_check_var_recursion = "SyntaxTreeVariable.check-var-recursion";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_check_var_recursion
Returncode SyntaxTreeVariable_check_var_recursion(SyntaxTreeVariable* self, SyntaxTreeVariable* variable) {
  if (variable->type_instance->type_data == self->parent_type) {
    CHECK(123, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){50, 49, "variable will cause recursive declaration of type"}, self->parent_type->name) )
  }
  ListNode* child = variable->type_instance->type_data->_base._base.variables->first;
  while (true) {
    if (!(NULL != child)) break;
    if (((SyntaxTreeVariable*)(child->item))->access == ACCESS_VAR &&  ! ((SyntaxTreeVariable*)(child->item))->type_instance->type_data->is_primitive) {
      CHECK(131, SyntaxTreeVariable_check_var_recursion(self, child->item) )
    }
    child = child->next;
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
    CHECK(136, SyntaxTreeVariable_write_spaces(self) )
  }
  else {
    if (!self->is_native) {
      CHECK(138, write(&(String){2, 1, "\n"}) )
    }
  }
  
  if (self->access == ACCESS_VAR && self->is_create && (self->type_instance->type_data == &(glob->type_array->_base) || self->type_instance->type_data == &(glob->type_string->_base))) {
    CHECK(143, (self)->_base._base._dtl[6](self) )
  }
  
  if (!self->type_instance->type_data->is_primitive && self->access == ACCESS_VAR &&  ! (NULL != self->parent_type)) {
    CHECK(147, SyntaxTreeVariable_write_var(self) )
  }
  
  /* `type` `name`[ = 0]; */
  /* `type`* `name`[ = NULL]; */
  /* Ref_Manager* `name`_Refman[ = NULL]; */
  if (self->type_instance->type_data == &(glob->type_func->_base)) {
    CHECK(153, FunctionArguments_write_pointer(self->type_instance->arguments, self->name) )
  }
  else {
    CHECK(155, write_cname(self->type_instance->type_data->name) )
    if (!self->type_instance->type_data->is_primitive &&  ! (NULL != self->parent_type && self->access == ACCESS_VAR)) {
      CHECK(158, write(&(String){2, 1, "*"}) )
    }
    CHECK(159, write(&(String){2, 1, " "}) )
    CHECK(160, write_cname(self->name) )
  }
  
  if (!(NULL != self->parent_type) &&  ! self->is_native) {
    if (self->type_instance->type_data->is_primitive && self->type_instance->type_data != &(glob->type_func->_base) && self->type_instance->type_data != &(glob->type_ref->_base)) {
      CHECK(166, write(&(String){5, 4, " = 0"}) )
    }
    else {
      CHECK(168, write(&(String){8, 7, " = NULL"}) )
    }
  }
  
  CHECK(170, write(&(String){3, 2, ";\n"}) )
  
  if (!self->type_instance->type_data->is_primitive &&  ! (NULL != self->parent_type && self->access == ACCESS_VAR)) {
    CHECK(174, SyntaxTreeVariable_write_refman(self) )
  }
  
  if (self->type_instance->type_data->is_dynamic &&  ! (NULL != self->parent_type && self->access == ACCESS_VAR)) {
    CHECK(178, SyntaxTreeVariable_write_dynamic(self) )
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
  if (self->type_instance->type_data == &(glob->type_array->_base) && ((TypeInstance*)(self->type_instance->parameters->first->item))->type_data == &(glob->type_string->_base)) {
    /* char `name`_Chars[`length` * `string-legth`] = {0}; */
    CHECK(184, write(&(String){6, 5, "char "}) )
    CHECK(185, write_cname(self->name) )
    CHECK(186, write(&(String){8, 7, "_Chars["}) )
    CHECK(187, (self->type_instance->length)->_base._dtl[4](self->type_instance->length) )
    CHECK(188, write(&(String){4, 3, " * "}) )
    CHECK(189, (((TypeInstance*)(self->type_instance->parameters->first->item))->length)->_base._dtl[4](((TypeInstance*)(self->type_instance->parameters->first->item))->length) )
    CHECK(190, write(&(String){4, 3, "];\n"}) )
    CHECK(191, SyntaxTreeVariable_write_spaces(self) )
  }
  /* `sub-type` `name`_Values[`length`]; */
  if (self->type_instance->type_data == &(glob->type_string->_base)) {
    CHECK(194, write(&(String){6, 5, "char "}) )
  }
  else {
    if (((TypeInstance*)(self->type_instance->parameters->first->item))->type_data == &(glob->type_func->_base)) {
      CHECK(196, write(&(String){14, 13, "Returncode (*"}) )
    }
    else {
      CHECK(198, write_cname(((TypeInstance*)(self->type_instance->parameters->first->item))->type_data->name) )
      CHECK(199, write(&(String){2, 1, " "}) )
    }
  }
  CHECK(200, write_cname(self->name) )
  CHECK(201, write(&(String){9, 8, "_Values["}) )
  CHECK(202, (self->type_instance->length)->_base._dtl[4](self->type_instance->length) )
  CHECK(203, write(&(String){2, 1, "]"}) )
  if (self->type_instance->type_data == &(glob->type_array->_base) && ((TypeInstance*)(self->type_instance->parameters->first->item))->type_data == &(glob->type_func->_base)) {
    CHECK(206, write(&(String){2, 1, ")"}) )
    CHECK(207, (((TypeInstance*)(self->type_instance->parameters->first->item))->arguments)->_base._dtl[4](((TypeInstance*)(self->type_instance->parameters->first->item))->arguments) )
  }
  CHECK(208, write(&(String){4, 3, " = "}) )
  Int bases = 0;
  if (self->type_instance->type_data == &(glob->type_array->_base) &&  ! ((TypeInstance*)(self->type_instance->parameters->first->item))->type_data->is_primitive) {
    TypeData* type_data = ((TypeInstance*)(self->type_instance->parameters->first->item))->type_data;
    bases = 1;
    while (true) {
      CHECK(215, write(&(String){2, 1, "{"}) )
      if (!(NULL != type_data->base_type)) break;
      type_data = type_data->base_type->type_data;
      bases += 1;
    }
  }
  CHECK(219, write(&(String){4, 3, "{0}"}) )
  {int n; for (n = (0); n < (bases); ++n) {
    CHECK(221, write(&(String){2, 1, "}"}) )
  }}
  CHECK(222, write(&(String){3, 2, ";\n"}) )
  CHECK(223, SyntaxTreeVariable_write_spaces(self) )
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
  CHECK(227, write_cname(self->type_instance->type_data->name) )
  CHECK(228, write(&(String){2, 1, " "}) )
  CHECK(229, write_cname(self->name) )
  CHECK(230, write(&(String){9, 8, "_Var = {"}) )
  if (self->is_create && (self->type_instance->type_data == &(glob->type_array->_base) || self->type_instance->type_data == &(glob->type_string->_base))) {
    /* {`length`, 0, NULL} */
    CHECK(235, (self->type_instance->length)->_base._dtl[4](self->type_instance->length) )
    if (self->type_instance->type_data == &(glob->type_string->_base)) {
      CHECK(237, write(&(String){4, 3, ", 0"}) )
    }
    CHECK(238, write(&(String){7, 6, ", NULL"}) )
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
      CHECK(251, write(&(String){2, 1, "{"}) )
    }
    CHECK(252, write(&(String){2, 1, "0"}) )
    {int n; for (n = (0); n < (bases); ++n) {
      CHECK(254, write(&(String){2, 1, "}"}) )
    }}
  }
  CHECK(255, write(&(String){4, 3, "};\n"}) )
  CHECK(256, SyntaxTreeVariable_write_spaces(self) )
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
  CHECK(259, SyntaxTreeVariable_write_spaces(self) )
  CHECK(260, write(&(String){14, 13, "Ref_Manager* "}) )
  CHECK(261, write_cname(self->name) )
  CHECK(262, write(&(String){8, 7, "_Refman"}) )
  if (!(NULL != self->parent_type)) {
    CHECK(264, write(&(String){8, 7, " = NULL"}) )
  }
  CHECK(265, write(&(String){3, 2, ";\n"}) )
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
  CHECK(269, SyntaxTreeVariable_write_spaces(self) )
  /* if ? self.parent */
  /* self.write-spaces() */
  /* else-if ? self.parent-type */
  /* write(user "  ") */
  CHECK(274, write_cname(self->type_instance->type_data->name) )
  CHECK(275, write(&(String){11, 10, "_Dynamic* "}) )
  CHECK(276, write_cname(self->name) )
  CHECK(277, write(&(String){9, 8, "_Dynamic"}) )
  if (!(NULL != self->parent_type)) {
    CHECK(279, write(&(String){4, 3, " = "}) )
    if (self->is_create) {
      CHECK(281, write(&(String){2, 1, "&"}) )
      CHECK(282, write_cname(self->type_instance->type_data->name) )
      CHECK(283, write(&(String){9, 8, "_dynamic"}) )
    }
    else {
      CHECK(285, write(&(String){5, 4, "NULL"}) )
    }
  }
  CHECK(286, write(&(String){3, 2, ";\n"}) )
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
    SyntaxTreeFunction* _SyntaxTreeFunction171;
    CHECK(290, (self->_base.parent)->_base._base._dtl[7](self->_base.parent, &(_SyntaxTreeFunction171)) )
    CHECK(290, SyntaxTreeBranch_write_spaces(&(_SyntaxTreeFunction171->_base._base)) )
  }
  else {
    if (NULL != self->parent_type) {
      CHECK(292, SyntaxTreeBranch_write_spaces(&(self->parent_type->_base._base)) )
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
Func SyntaxTreeVariable__dtl[] = {(void*)SyntaxTreeVariable_get_parent_type, (void*)SyntaxTreeVariable_link_types, (void*)SyntaxTreeVariable_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeVariable_write, (void*)SyntaxTreeCode_m_is_end_point, (void*)SyntaxTreeVariable_write_sequence};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct VariableInit VariableInit;
#elif MR_STAGE == MR_TYPES(2)
struct VariableInit {
  SyntaxTreeCode _base;
  InitExpression* expression_init;
  SyntaxTreeVariable* variable;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode VariableInit_parse_new(VariableInit* self, SyntaxTreeVariable* variable, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_VariableInit_parse_new = "VariableInit.parse-new";
#define MR_FUNC_NAME _func_name_VariableInit_parse_new
Returncode VariableInit_parse_new(VariableInit* self, SyntaxTreeVariable* variable, Char* end) {
  VariableInit* new_node = malloc(sizeof(VariableInit));
  if (new_node == NULL) RAISE(300)
  *new_node = (VariableInit){VariableInit__dtl, NULL, 0, NULL, NULL, NULL};
  new_node->_base._base._dtl = VariableInit__dtl;
  CHECK(301, VariableInit_parse(new_node, variable, &((*end))) )
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
  CHECK(304, SyntaxTreeNode_set_location(&(self->_base._base)) )
  self->_base.parent = variable->_base.parent;
  self->variable = variable;
  self->expression_init = malloc(sizeof(InitExpression));
  if (self->expression_init == NULL) RAISE(307)
  *self->expression_init = (InitExpression){InitExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, NULL};
  self->expression_init->_base._base._dtl = InitExpression__dtl;
  TypeInstance* _TypeInstance172;
  CHECK(308, TypeInstance_copy_new(variable->type_instance, &(_TypeInstance172)) )
  CHECK(308, InitExpression_parse(self->expression_init, _TypeInstance172, &(self->_base), &((*end))) )
  self->expression_init->_base.is_statement = true;
  self->expression_init->symbol = malloc(sizeof(SymbolExpression));
  if (self->expression_init->symbol == NULL) RAISE(311)
  *self->expression_init->symbol = (SymbolExpression){SymbolExpression__dtl, NULL, 0, NULL, NULL, 0, false, false, false, false, false, false, NULL, NULL, NULL, false};
  self->expression_init->symbol->_base._base._dtl = SymbolExpression__dtl;
  CHECK(312, string_new_copy(variable->name, &(self->expression_init->symbol->name)) )
  self->expression_init->symbol->variable = variable;
  CHECK(315, TypeInstance_copy_new(variable->type_instance, &(self->expression_init->symbol->_base.result_type)) )
  self->expression_init->symbol->_base.access = variable->access;
  CHECK(318, List_add(variable->_base.parent->code_nodes, &(self->_base)) )
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
  CHECK(321, (self->expression_init)->_base._base._dtl[2](self->expression_init) )
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
  if (self->variable->type_instance->type_data->is_primitive &&  ! (NULL != self->expression_init->arguments->parameters->first)) {
    return OK;
  }
  if (self->_base.parent == &(glob->root->global_init->_base._base)) {
    CHECK(328, write(&(String){23, 22, "#define MR_FILE_NAME \""}) )
    CHECK(329, write(self->variable->_base._base.input_file_name) )
    CHECK(330, write(&(String){3, 2, "\"\n"}) )
  }
  CHECK(331, (self->expression_init)->_base._base._dtl[4](self->expression_init) )
  if (self->_base.parent == &(glob->root->global_init->_base._base)) {
    CHECK(333, write(&(String){21, 20, "#undef MR_FILE_NAME\n"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func VariableInit__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func VariableInit__dtl[] = {(void*)SyntaxTreeCode_get_parent_type, (void*)SyntaxTreeNode_link_types, (void*)VariableInit_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)VariableInit_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeConstant SyntaxTreeConstant;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeConstant {
  SyntaxTreeVariable _base;
  Expression* value;
  Bool is_ordered;
  Bool ordering;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeConstant_parse_new(SyntaxTreeConstant* self, Char* end, SyntaxTreeConstant** constant);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeConstant_parse_new = "SyntaxTreeConstant.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeConstant_parse_new
Returncode SyntaxTreeConstant_parse_new(SyntaxTreeConstant* self, Char* end, SyntaxTreeConstant** constant) {
  (*constant) = malloc(sizeof(SyntaxTreeConstant));
  if ((*constant) == NULL) RAISE(342)
  *(*constant) = (SyntaxTreeConstant){SyntaxTreeConstant__dtl, NULL, 0, NULL, NULL, 0, NULL, NULL, false, false, false, false, NULL, false, false};
  (*constant)->_base._base._base._dtl = SyntaxTreeConstant__dtl;
  CHECK(343, SyntaxTreeConstant_parse((*constant), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeConstant_parse(SyntaxTreeConstant* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeConstant_parse = "SyntaxTreeConstant.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeConstant_parse
Returncode SyntaxTreeConstant_parse(SyntaxTreeConstant* self, Char* end) {
  CHECK(346, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  self->_base.access = ACCESS_VAR;
  self->_base.constant = true;
  String* type_name = NULL;
  Int _Int173;
  CHECK(350, read_until(&(String){2, 1, " "}, false, &(type_name), &((*end)), &(_Int173)) )
  Bool _Bool174;
  CHECK(351, String_equal(type_name, &(String){4, 3, "Int"}, &(_Bool174)) )
  if (!_Bool174) {
    CHECK(352, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){41, 40, "Only \"Int\" typed constant supported, got"}, type_name) )
  }
  if ((*end) != ' ') {
    CHECK(355, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){32, 31, "expected space after \"Int\", got"}, (*end)) )
  }
  CHECK(357, read_new(&(String){2, 1, " "}, &(self->_base.name), &((*end))) )
  Bool _Bool175;
  CHECK(358, f_is_legal_name(self->_base.name, NAME_CONSTANT, &(_Bool175)) )
  if (!_Bool175) {
    CHECK(359, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){22, 21, "illegal constant name"}, self->_base.name) )
  }
  if ((*end) != ' ') {
    CHECK(361, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){40, 39, "expected space after constant name, got"}, (*end)) )
  }
  CHECK(363, parse_new_expression(&(String){1, 0, ""}, &(self->_base._base), &(self->value), &((*end))) )
  CHECK(364, TypeData_m_new_type_instance(&(glob->type_int->_base), &(self->_base.type_instance)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeConstant_link_types(SyntaxTreeConstant* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeConstant_link_types = "SyntaxTreeConstant.link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeConstant_link_types
Returncode SyntaxTreeConstant_link_types(SyntaxTreeConstant* self) {
  /* do nothing */
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeConstant_analyze(SyntaxTreeConstant* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeConstant_analyze = "SyntaxTreeConstant.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeConstant_analyze
Returncode SyntaxTreeConstant_analyze(SyntaxTreeConstant* self) {
  CHECK(370, SyntaxTreeNode_analyze_expression(&(self->_base._base._base), self->value, &(glob->type_int->_base)) )
  if (!self->value->constant) {
    CHECK(372, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){22, 21, "value is not constant"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeConstant_m_order_constants(SyntaxTreeConstant* self, List* ordered_list);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeConstant_m_order_constants = "SyntaxTreeConstant.m-order-constants";
#define MR_FUNC_NAME _func_name_SyntaxTreeConstant_m_order_constants
Returncode SyntaxTreeConstant_m_order_constants(SyntaxTreeConstant* self, List* ordered_list) {
  if (self->is_ordered) {
    return OK;
  }
  if (self->ordering) {
    CHECK(378, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){33, 32, "recursive dependency in constant"}, self->_base.name) )
  }
  self->ordering = true;
  CHECK(381, (self->value)->_base._dtl[3](self->value, ordered_list) )
  CHECK(382, List_add(ordered_list, self) )
  self->is_ordered = true;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeConstant_write(SyntaxTreeConstant* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeConstant_write = "SyntaxTreeConstant.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeConstant_write
Returncode SyntaxTreeConstant_write(SyntaxTreeConstant* self) {
  if (!self->is_ordered) {
    return OK;
  }
  /* enum { `name` = `value` }; */
  CHECK(389, write(&(String){9, 8, "\nenum { "}) )
  CHECK(390, write_cname(self->_base.name) )
  CHECK(391, write(&(String){4, 3, " = "}) )
  CHECK(392, (self->value)->_base._dtl[4](self->value) )
  CHECK(393, write(&(String){5, 4, " };\n"}) )
  self->is_ordered = false;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeConstant__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeConstant__dtl[] = {(void*)SyntaxTreeVariable_get_parent_type, (void*)SyntaxTreeConstant_link_types, (void*)SyntaxTreeConstant_analyze, (void*)SyntaxTreeConstant_m_order_constants, (void*)SyntaxTreeConstant_write, (void*)SyntaxTreeCode_m_is_end_point, (void*)SyntaxTreeVariable_write_sequence};
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
#include "statement/for.c"
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
#include "statement/type.c"
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
