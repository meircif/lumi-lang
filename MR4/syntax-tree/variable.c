#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/variable.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file22_name = "syntax-tree/variable.3.mr";
#endif
#define MR_FILE_NAME _mr_file22_name

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
  *self->type_instance = (TypeInstance){NULL, NULL, NULL, NULL, NULL};
  if (self->access == ACCESS_VAR || self->access == ACCESS_NEW) {
    CHECK(31, TypeInstance_parse(self->type_instance, &(String){2, 1, " "}, &(self->_base._base), self, &((*end))) )
  }
  else {
    CHECK(33, TypeInstance_parse(self->type_instance, &(String){2, 1, " "}, &(self->_base._base), NULL, &((*end))) )
  }
  if ((*end) != ' ') {
    CHECK(35, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){31, 30, "expected space after type, got"}, (*end)) )
  }
  if (self->access == ACCESS_VAR) {
    Bool _Bool115;
    CHECK(37, String_equal(self->type_instance->name, &(String){6, 5, "Array"}, &(_Bool115)) )
    Bool _Bool116;
    CHECK(37, String_equal(self->type_instance->name, &(String){7, 6, "String"}, &(_Bool116)) )
    if (_Bool115 || _Bool116) {
      CHECK(39, SyntaxTreeInitVarSequence_init_new(NULL, self) )
    }
  }
  CHECK(40, read_new(&(String){2, 1, "("}, &(self->name), &((*end))) )
  CHECK(41, SyntaxTreeVariable_m_check_name(self) )
  if ((*end) == '(') {
    if (NULL != self->parent_type) {
      CHECK(44, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){35, 34, "type members cannot be initialized"}) )
    }
    if (!(NULL != self->_base.parent)) {
      CHECK(46, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){39, 38, "global variables cannot be initialized"}) )
    }
    CHECK(47, SyntaxTreeVariableInit_parse_new(NULL, self, &((*end))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_m_check_name(SyntaxTreeVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_m_check_name = "SyntaxTreeVariable.m-check-name";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_m_check_name
Returncode SyntaxTreeVariable_m_check_name(SyntaxTreeVariable* self) {
  Bool _Bool117;
  CHECK(50, f_is_legal_name(self->name, false, &(_Bool117)) )
  if (!_Bool117) {
    CHECK(51, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){22, 21, "illegal variable name"}, self->name) )
  }
  if (NULL != self->parent_type) {
    SyntaxTreeVariable* field = NULL;
    Int _Int118;
    CHECK(54, TypeData_m_find_field(self->parent_type, self->name, &(field), &(_Int118)) )
    if (NULL != field) {
      CHECK(56, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){22, 21, "redefinition of field"}, self->name) )
    }
    SyntaxTreeFunction* meth = NULL;
    Int _Int119;
    CHECK(58, TypeData_m_find_meth(self->parent_type, self->name, &(meth), &(_Int119)) )
    if (NULL != meth) {
      CHECK(60, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){28, 27, "field name overrides method"}, self->name) )
    }
  }
  else {
    SyntaxTreeVariable* _SyntaxTreeVariable120;
    CHECK(63, (glob->root)->_base._base._base._dtl[4](glob->root, self->name, &(_SyntaxTreeVariable120)) )
    if (NULL != _SyntaxTreeVariable120) {
      CHECK(64, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){32, 31, "redefinition of global variable"}, self->name) )
    }
    SyntaxTreeFunction* _SyntaxTreeFunction121;
    CHECK(66, SyntaxTreeNamespace_m_find_function(&(glob->root->_base), self->name, &(_SyntaxTreeFunction121)) )
    if (NULL != _SyntaxTreeFunction121) {
      CHECK(67, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){33, 32, "variable name overrides function"}, self->name) )
    }
    if (NULL != self->_base.parent) {
      SyntaxTreeVariable* _SyntaxTreeVariable122;
      CHECK(70, (self->_base.parent)->_base._base._dtl[4](self->_base.parent, self->name, &(_SyntaxTreeVariable122)) )
      if (NULL != _SyntaxTreeVariable122) {
        CHECK(71, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){25, 24, "redefinition of variable"}, self->name) )
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_m_find_variable(SyntaxTreeVariable* self, String* name, SyntaxTreeVariable** variable, Bool* found);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_m_find_variable = "SyntaxTreeVariable.m-find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_m_find_variable
Returncode SyntaxTreeVariable_m_find_variable(SyntaxTreeVariable* self, String* name, SyntaxTreeVariable** variable, Bool* found) {
  CHECK(76, String_equal(self->name, name, &((*found))) )
  if ((*found)) {
    (*variable) = self;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariable_m_link_types(SyntaxTreeVariable* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariable_m_link_types = "SyntaxTreeVariable.m-link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariable_m_link_types
Returncode SyntaxTreeVariable_m_link_types(SyntaxTreeVariable* self) {
  /* sys.print-raw(user "m-link-type var ") */
  /* sys.print(user self.name) */
  CHECK(83, TypeInstance_m_link_types(self->type_instance, &(self->_base._base)) )
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
    if ((self->access) < 0 || (self->access) >= (glob->access_names)->length) RAISE(88)
    CHECK(88, SyntaxTreeNode_m_syntax_error(&(self->_base._base), &(String){56, 55, "only \"var\" access is supported for primitive types, got"}, (&(((String*)((glob->access_names)->values))[self->access]))) )
  }
  CHECK(91, TypeInstance_analyze_lengths(self->type_instance, &(self->_base._base)) )
  if (self->type_instance->type_data == glob->type_array) {
    if (!(NULL != self->type_instance->sub_type)) {
      CHECK(94, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){26, 25, "missing subtype for array"}) )
    }
    if (self->type_instance->sub_type->type_data == glob->type_array) {
      CHECK(96, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){44, 43, "multidimensional array not supported yet..."}) )
    }
  }
  if (self->access == ACCESS_VAR || self->access == ACCESS_NEW) {
    if (!self->type_instance->type_data->is_primitive &&  ! (NULL != self->_base.parent)) {
      CHECK(100, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){52, 51, "non-primitives cannot be declared \"var\" here yet..."}) )
    }
    if (self->type_instance->type_data == glob->type_array || self->type_instance->type_data == glob->type_string) {
      if (!(NULL != self->type_instance->length)) {
        CHECK(105, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){28, 27, "missing length for sequence"}) )
      }
    }
    if (self->type_instance->type_data == glob->type_array && self->type_instance->sub_type->type_data == glob->type_string &&  ! (NULL != self->type_instance->sub_type->length)) {
      CHECK(109, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){28, 27, "missing length for sequence"}) )
    }
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
  if (self->access == ACCESS_VAR && (self->type_instance->type_data == glob->type_array || self->type_instance->type_data == glob->type_string)) {
    if (self->type_instance->type_data == glob->type_array && self->type_instance->sub_type->type_data == glob->type_string) {
      /* char `name`_Chars[`length` * `string-legth`]; */
      CHECK(118, write(&(String){6, 5, "char "}) )
      CHECK(119, write_cname(self->name) )
      CHECK(120, write(&(String){8, 7, "_Chars["}) )
      CHECK(121, (self->type_instance->length)->_base._dtl[2](self->type_instance->length) )
      CHECK(122, write(&(String){4, 3, " * "}) )
      CHECK(123, (self->type_instance->sub_type->length)->_base._dtl[2](self->type_instance->sub_type->length) )
      CHECK(124, write(&(String){4, 3, "];\n"}) )
      CHECK(125, SyntaxTreeCode_write_spaces(&(self->_base)) )
    }
    /* `sub-type` `name`_Values[`length`]; */
    if (self->type_instance->type_data == glob->type_string) {
      CHECK(128, write(&(String){5, 4, "char"}) )
    }
    else {
      CHECK(130, write_cname(self->type_instance->sub_type->type_data->name) )
    }
    CHECK(131, write(&(String){2, 1, " "}) )
    CHECK(132, write_cname(self->name) )
    CHECK(133, write(&(String){9, 8, "_Values["}) )
    CHECK(134, (self->type_instance->length)->_base._dtl[2](self->type_instance->length) )
    CHECK(135, write(&(String){4, 3, "];\n"}) )
    CHECK(136, SyntaxTreeCode_write_spaces(&(self->_base)) )
  }
  
  CHECK(138, write_cname(self->type_instance->type_data->name) )
  if (self->access != ACCESS_VAR && self->access != ACCESS_AUX) {
    CHECK(140, write(&(String){2, 1, "*"}) )
  }
  CHECK(141, write(&(String){2, 1, " "}) )
  CHECK(142, write_cname(self->name) )
  
  if (!self->type_instance->type_data->is_primitive && (self->access == ACCESS_VAR || self->access == ACCESS_AUX)) {
    /* `type` `name`_Var = {...}; */
    /* `type`* `name` = &`name`_Var; */
    CHECK(148, write(&(String){9, 8, "_Var = {"}) )
    if ((self->type_instance->type_data == glob->type_array || self->type_instance->type_data == glob->type_string) && self->access == ACCESS_VAR) {
      /* {`length`, 0, NULL} */
      CHECK(153, (self->type_instance->length)->_base._dtl[2](self->type_instance->length) )
      if (self->type_instance->type_data == glob->type_string) {
        CHECK(155, write(&(String){4, 3, ", 0"}) )
      }
      CHECK(156, write(&(String){7, 6, ", NULL"}) )
    }
    else {
      CHECK(158, write(&(String){2, 1, "0"}) )
    }
    CHECK(159, write(&(String){4, 3, "};\n"}) )
    CHECK(160, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(161, write_cname(self->type_instance->type_data->name) )
    CHECK(162, write(&(String){3, 2, "* "}) )
    CHECK(163, write_cname(self->name) )
    CHECK(164, write(&(String){5, 4, " = &"}) )
    CHECK(165, write_cname(self->name) )
    CHECK(166, write(&(String){5, 4, "_Var"}) )
  }
  else {
    if (NULL != self->_base.parent) {
      /* `type` `name` = 0; */
      /* `type`* `name` = NULL; */
      if (self->access == ACCESS_VAR) {
        CHECK(171, write(&(String){5, 4, " = 0"}) )
      }
      else {
        CHECK(173, write(&(String){8, 7, " = NULL"}) )
      }
    }
  }
  CHECK(174, write(&(String){2, 1, ";"}) )
  
  if (self->type_instance->type_data->is_dynamic) {
    /* `type`_Dynamic* `name`_Dynamic[ = `type`_dynamic]; */
    CHECK(178, write(&(String){2, 1, "\n"}) )
    if (NULL != self->_base.parent) {
      CHECK(180, SyntaxTreeCode_write_spaces(&(self->_base)) )
    }
    else {
      if (NULL != self->parent_type) {
        CHECK(182, write(&(String){3, 2, "  "}) )
      }
    }
    CHECK(183, write_cname(self->type_instance->type_data->name) )
    CHECK(184, write(&(String){11, 10, "_Dynamic* "}) )
    CHECK(185, write_cname(self->name) )
    CHECK(186, write(&(String){9, 8, "_Dynamic"}) )
    if (NULL != self->_base.parent) {
      CHECK(188, write(&(String){4, 3, " = "}) )
      if (self->access == ACCESS_VAR || self->access == ACCESS_NEW) {
        CHECK(190, write(&(String){2, 1, "&"}) )
        CHECK(191, write_cname(self->type_instance->type_data->name) )
        CHECK(192, write(&(String){9, 8, "_dynamic"}) )
      }
      else {
        CHECK(194, write(&(String){5, 4, "NULL"}) )
      }
    }
    CHECK(195, write(&(String){2, 1, ";"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeVariable__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeVariable__dtl[] = {(void*)SyntaxTreeVariable_m_link_types, (void*)SyntaxTreeVariable_analyze, (void*)SyntaxTreeVariable_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct BaseVariableInit BaseVariableInit;
#elif MR_STAGE == MR_TYPES(2)
struct BaseVariableInit {
  SyntaxTreeCode _base;
  SyntaxTreeVariable* variable;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BaseVariableInit_init(BaseVariableInit* self, SyntaxTreeVariable* variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BaseVariableInit_init = "BaseVariableInit.init";
#define MR_FUNC_NAME _func_name_BaseVariableInit_init
Returncode BaseVariableInit_init(BaseVariableInit* self, SyntaxTreeVariable* variable) {
  self->variable = variable;
  CHECK(203, BaseVariableInit_init_parent(self, variable->_base.parent) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode BaseVariableInit_init_parent(BaseVariableInit* self, SyntaxTreeBlock* parent);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_BaseVariableInit_init_parent = "BaseVariableInit.init-parent";
#define MR_FUNC_NAME _func_name_BaseVariableInit_init_parent
Returncode BaseVariableInit_init_parent(BaseVariableInit* self, SyntaxTreeBlock* parent) {
  self->_base.parent = parent;
  CHECK(207, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(208, List_add(self->_base.parent->code_nodes, &(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BaseVariableInit__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BaseVariableInit__dtl[] = {(void*)SyntaxTreeNode_m_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Initialize sequence variable node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeInitVarSequence SyntaxTreeInitVarSequence;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeInitVarSequence {
  BaseVariableInit _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeInitVarSequence_init_new(SyntaxTreeInitVarSequence* self, SyntaxTreeVariable* variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeInitVarSequence_init_new = "SyntaxTreeInitVarSequence.init-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeInitVarSequence_init_new
Returncode SyntaxTreeInitVarSequence_init_new(SyntaxTreeInitVarSequence* self, SyntaxTreeVariable* variable) {
  SyntaxTreeInitVarSequence* new_node = malloc(sizeof(SyntaxTreeInitVarSequence));
  if (new_node == NULL) RAISE(214)
  *new_node = (SyntaxTreeInitVarSequence){SyntaxTreeInitVarSequence__dtl, NULL, 0, NULL, NULL};
  new_node->_base._base._base._dtl = SyntaxTreeInitVarSequence__dtl;
  CHECK(215, BaseVariableInit_init(&(new_node->_base), variable) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeInitVarSequence_write(SyntaxTreeInitVarSequence* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeInitVarSequence_write = "SyntaxTreeInitVarSequence.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeInitVarSequence_write
Returncode SyntaxTreeInitVarSequence_write(SyntaxTreeInitVarSequence* self) {
  /* `name`_Var.values = `name`_Values; */
  CHECK(219, write_cname(self->_base.variable->name) )
  CHECK(220, write(&(String){15, 14, "_Var.values = "}) )
  CHECK(221, write_cname(self->_base.variable->name) )
  CHECK(222, write(&(String){9, 8, "_Values;"}) )
  if (self->_base.variable->type_instance->type_data == glob->type_array && self->_base.variable->type_instance->sub_type->type_data == glob->type_string) {
    /* MR_set_var_string_array( */
    /*    `array-length`, `string-length`, `name`, `name`_Chars); */
    CHECK(227, write(&(String){2, 1, "\n"}) )
    CHECK(228, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
    CHECK(229, write(&(String){25, 24, "MR_set_var_string_array("}) )
    CHECK(230, (self->_base.variable->type_instance->length)->_base._dtl[2](self->_base.variable->type_instance->length) )
    CHECK(231, write(&(String){3, 2, ", "}) )
    CHECK(232, (self->_base.variable->type_instance->sub_type->length)->_base._dtl[2](self->_base.variable->type_instance->sub_type->length) )
    CHECK(233, write(&(String){3, 2, ", "}) )
    CHECK(234, write_cname(self->_base.variable->name) )
    CHECK(235, write(&(String){3, 2, ", "}) )
    CHECK(236, write_cname(self->_base.variable->name) )
    CHECK(237, write(&(String){9, 8, "_Chars);"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeInitVarSequence__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeInitVarSequence__dtl[] = {(void*)SyntaxTreeNode_m_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeInitVarSequence_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Initialize dynamically allocated variable node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeInitNew SyntaxTreeInitNew;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeInitNew {
  BaseVariableInit _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeInitNew_parse_new(SyntaxTreeInitNew* self, SyntaxTreeBlock* parent_block, Char* end, SyntaxTreeVariable** new_var_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeInitNew_parse_new = "SyntaxTreeInitNew.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeInitNew_parse_new
Returncode SyntaxTreeInitNew_parse_new(SyntaxTreeInitNew* self, SyntaxTreeBlock* parent_block, Char* end, SyntaxTreeVariable** new_var_node) {
  SyntaxTreeInitNew* node_init_new = malloc(sizeof(SyntaxTreeInitNew));
  if (node_init_new == NULL) RAISE(244)
  *node_init_new = (SyntaxTreeInitNew){SyntaxTreeInitNew__dtl, NULL, 0, NULL, NULL};
  node_init_new->_base._base._base._dtl = SyntaxTreeInitNew__dtl;
  CHECK(245, BaseVariableInit_init_parent(&(node_init_new->_base), parent_block) )
  CHECK(246, SyntaxTreeVariable_parse_new(NULL, ACCESS_NEW, NULL, parent_block, &((*end)), &((*new_var_node))) )
  node_init_new->_base.variable = (*new_var_node);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeInitNew_write(SyntaxTreeInitNew* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeInitNew_write = "SyntaxTreeInitNew.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeInitNew_write
Returncode SyntaxTreeInitNew_write(SyntaxTreeInitNew* self) {
  /* `name` = `...` */
  if (self->_base.variable->type_instance->type_data == glob->type_array || self->_base.variable->type_instance->type_data == glob->type_string) {
    CHECK(255, (self->_base.variable->type_instance->length)->_base._dtl[5](self->_base.variable->type_instance->length) )
  }
  if (self->_base.variable->type_instance->type_data == glob->type_array && self->_base.variable->type_instance->sub_type->type_data == glob->type_string) {
    CHECK(258, (self->_base.variable->type_instance->sub_type->length)->_base._dtl[5](self->_base.variable->type_instance->sub_type->length) )
  }
  CHECK(259, write_cname(self->_base.variable->name) )
  CHECK(260, write(&(String){4, 3, " = "}) )
  if (self->_base.variable->type_instance->type_data == glob->type_array) {
    /* MR_new_array(length, sizeof(SubType)); */
    /* MR_new_array(length, sizeof(String) + (string-length)); */
    /* MR_set_new_string_array(length, string-length, `name`); */
    CHECK(265, write(&(String){14, 13, "MR_new_array("}) )
    CHECK(266, (self->_base.variable->type_instance->length)->_base._dtl[2](self->_base.variable->type_instance->length) )
    CHECK(267, write(&(String){10, 9, ", sizeof("}) )
    CHECK(268, write_cname(self->_base.variable->type_instance->sub_type->type_data->name) )
    if (self->_base.variable->type_instance->sub_type->type_data == glob->type_string) {
      CHECK(270, write(&(String){6, 5, ") + ("}) )
      CHECK(271, (self->_base.variable->type_instance->sub_type->length)->_base._dtl[2](self->_base.variable->type_instance->sub_type->length) )
      CHECK(272, write(&(String){5, 4, "));\n"}) )
      CHECK(273, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
      CHECK(274, write(&(String){25, 24, "MR_set_new_string_array("}) )
      CHECK(275, (self->_base.variable->type_instance->length)->_base._dtl[2](self->_base.variable->type_instance->length) )
      CHECK(276, write(&(String){3, 2, ", "}) )
      CHECK(277, (self->_base.variable->type_instance->sub_type->length)->_base._dtl[2](self->_base.variable->type_instance->sub_type->length) )
      CHECK(278, write(&(String){3, 2, ", "}) )
      CHECK(279, write_cname(self->_base.variable->name) )
    }
    else {
      CHECK(281, write(&(String){2, 1, ")"}) )
      
    }
  }
  else {
    if (self->_base.variable->type_instance->type_data == glob->type_string) {
      /* MR_new_string(length); */
      CHECK(285, write(&(String){15, 14, "MR_new_string("}) )
      CHECK(286, (self->_base.variable->type_instance->length)->_base._dtl[2](self->_base.variable->type_instance->length) )
    }
    else {
      /* calloc(1, sizeof(`type`)); */
      CHECK(289, write(&(String){18, 17, "calloc(1, sizeof("}) )
      CHECK(290, write_cname(self->_base.variable->type_instance->type_data->name) )
      CHECK(291, write(&(String){2, 1, ")"}) )
    }
  }
  CHECK(292, write(&(String){3, 2, ");"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeInitNew__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeInitNew__dtl[] = {(void*)SyntaxTreeNode_m_link_types, (void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeInitNew_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Variable initialization node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeVariableInit SyntaxTreeVariableInit;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeVariableInit {
  BaseVariableInit _base;
  Expression* value;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariableInit_parse_new(SyntaxTreeVariableInit* self, SyntaxTreeVariable* variable, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariableInit_parse_new = "SyntaxTreeVariableInit.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariableInit_parse_new
Returncode SyntaxTreeVariableInit_parse_new(SyntaxTreeVariableInit* self, SyntaxTreeVariable* variable, Char* end) {
  SyntaxTreeVariableInit* new_node = malloc(sizeof(SyntaxTreeVariableInit));
  if (new_node == NULL) RAISE(300)
  *new_node = (SyntaxTreeVariableInit){SyntaxTreeVariableInit__dtl, NULL, 0, NULL, NULL, NULL};
  new_node->_base._base._base._dtl = SyntaxTreeVariableInit__dtl;
  CHECK(301, SyntaxTreeVariableInit_parse(new_node, variable, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariableInit_parse(SyntaxTreeVariableInit* self, SyntaxTreeVariable* variable, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariableInit_parse = "SyntaxTreeVariableInit.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariableInit_parse
Returncode SyntaxTreeVariableInit_parse(SyntaxTreeVariableInit* self, SyntaxTreeVariable* variable, Char* end) {
  CHECK(304, BaseVariableInit_init(&(self->_base), variable) )
  CHECK(305, parse_new_expression(&(String){2, 1, ")"}, &(self->_base._base), &(self->value), &((*end))) )
  if ((*end) != ')') {
    CHECK(307, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){39, 38, "expected \")\" after initialization, got"}, (*end)) )
  }
  CHECK(310, read_c(&((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariableInit_analyze(SyntaxTreeVariableInit* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariableInit_analyze = "SyntaxTreeVariableInit.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariableInit_analyze
Returncode SyntaxTreeVariableInit_analyze(SyntaxTreeVariableInit* self) {
  if ((self->_base.variable->access == ACCESS_VAR || self->_base.variable->access == ACCESS_NEW) &&  ! self->_base.variable->type_instance->type_data->is_primitive &&  ! (self->_base.variable->type_instance->type_data == glob->type_string)) {
    CHECK(317, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){37, 36, "cannot initialize non-primitive type"}, self->_base.variable->type_instance->type_data->name) )
  }
  CHECK(320, (self->value)->_base._dtl[1](self->value) )
  CHECK(321, TypeInstance_m_check_assign_from(self->_base.variable->type_instance, &(self->_base._base._base), &(self->value)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeVariableInit_write(SyntaxTreeVariableInit* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeVariableInit_write = "SyntaxTreeVariableInit.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeVariableInit_write
Returncode SyntaxTreeVariableInit_write(SyntaxTreeVariableInit* self) {
  CHECK(325, (self->value)->_base._dtl[5](self->value) )
  if ((self->_base.variable->access == ACCESS_VAR || self->_base.variable->access == ACCESS_NEW) && self->_base.variable->type_instance->type_data == glob->type_string) {
    /* CHECK(`line-num`, String_copy(`name`, `value`) ) */
    CHECK(330, SyntaxTreeNode_write_call(&(self->_base._base._base)) )
    CHECK(331, write(&(String){13, 12, "String_copy("}) )
    CHECK(332, write_cname(self->_base.variable->name) )
    CHECK(333, write(&(String){3, 2, ", "}) )
    CHECK(334, (self->value)->_base._dtl[2](self->value) )
    CHECK(335, write(&(String){4, 3, ") )"}) )
  }
  else {
    /* `name` = `value`; */
    CHECK(338, write_cname(self->_base.variable->name) )
    CHECK(339, write(&(String){4, 3, " = "}) )
    CHECK(340, (self->value)->_base._dtl[2](self->value) )
    CHECK(341, write(&(String){2, 1, ";"}) )
    if (self->_base.variable->type_instance->type_data->is_dynamic) {
      /* `name`_Dynamic = `Type`_Dynamic; */
      CHECK(344, write(&(String){2, 1, "\n"}) )
      CHECK(345, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
      CHECK(346, write_cname(self->_base.variable->name) )
      CHECK(347, write(&(String){12, 11, "_Dynamic = "}) )
      CHECK(348, (self->value)->_base._dtl[3](self->value) )
      CHECK(349, write(&(String){2, 1, ";"}) )
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeVariableInit__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeVariableInit__dtl[] = {(void*)SyntaxTreeNode_m_link_types, (void*)SyntaxTreeVariableInit_analyze, (void*)SyntaxTreeVariableInit_write, (void*)SyntaxTreeCode_m_is_end_point};
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
