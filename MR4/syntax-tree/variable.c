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
    Bool _Bool109;
    CHECK(37, String_equal(self->type_instance->name, &(String){6, 5, "Array"}, &(_Bool109)) )
    Bool _Bool110;
    CHECK(37, String_equal(self->type_instance->name, &(String){7, 6, "String"}, &(_Bool110)) )
    if (_Bool109 || _Bool110) {
      CHECK(39, SyntaxTreeInitVarSequence_init_new(NULL, self) )
    }
  }
  CHECK(40, read_new(&(String){2, 1, "("}, &(self->name), &((*end))) )
  if ((*end) == '(') {
    if (NULL != self->parent_type) {
      CHECK(43, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){35, 34, "type members cannot be initialized"}) )
    }
    if (!(NULL != self->_base.parent)) {
      CHECK(45, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){39, 38, "global variables cannot be initialized"}) )
    }
    CHECK(46, SyntaxTreeVariableInit_parse_new(NULL, self, &((*end))) )
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
  CHECK(50, String_equal(self->name, name, &((*found))) )
  if ((*found)) {
    (*variable) = self;
  }
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
  CHECK(55, TypeInstance_analyze(self->type_instance, &(self->_base._base)) )
  if (self->type_instance->type_data == glob->type_array) {
    if (!(NULL != self->type_instance->sub_type)) {
      CHECK(58, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){26, 25, "missing subtype for array"}) )
    }
    if (self->type_instance->sub_type->type_data == glob->type_array) {
      CHECK(60, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){44, 43, "multidimensional array not supported yet..."}) )
    }
  }
  if (self->access == ACCESS_VAR || self->access == ACCESS_NEW) {
    if (!self->type_instance->type_data->is_primitive &&  ! (NULL != self->_base.parent)) {
      CHECK(64, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){52, 51, "non-primitives cannot be declared \"var\" here yet..."}) )
    }
    if (self->type_instance->type_data == glob->type_array || self->type_instance->type_data == glob->type_string) {
      if (!(NULL != self->type_instance->length)) {
        CHECK(69, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){28, 27, "missing length for sequence"}) )
      }
    }
    if (self->type_instance->type_data == glob->type_array && self->type_instance->sub_type->type_data == glob->type_string &&  ! (NULL != self->type_instance->sub_type->length)) {
      CHECK(73, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base), &(String){28, 27, "missing length for sequence"}) )
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
      CHECK(82, write(&(String){6, 5, "char "}) )
      CHECK(83, write_cname(self->name) )
      CHECK(84, write(&(String){8, 7, "_Chars["}) )
      CHECK(85, (self->type_instance->length)->_base._dtl[1](self->type_instance->length) )
      CHECK(86, write(&(String){4, 3, " * "}) )
      CHECK(87, (self->type_instance->sub_type->length)->_base._dtl[1](self->type_instance->sub_type->length) )
      CHECK(88, write(&(String){4, 3, "];\n"}) )
      CHECK(89, SyntaxTreeCode_write_spaces(&(self->_base)) )
    }
    /* `sub-type` `name`_Values[`length`]; */
    if (self->type_instance->type_data == glob->type_string) {
      CHECK(92, write(&(String){5, 4, "char"}) )
    }
    else {
      CHECK(94, write_cname(self->type_instance->sub_type->type_data->name) )
    }
    CHECK(95, write(&(String){2, 1, " "}) )
    CHECK(96, write_cname(self->name) )
    CHECK(97, write(&(String){9, 8, "_Values["}) )
    CHECK(98, (self->type_instance->length)->_base._dtl[1](self->type_instance->length) )
    CHECK(99, write(&(String){4, 3, "];\n"}) )
    CHECK(100, SyntaxTreeCode_write_spaces(&(self->_base)) )
  }
  
  CHECK(102, write_cname(self->type_instance->type_data->name) )
  if (self->access != ACCESS_VAR && self->access != ACCESS_AUX) {
    CHECK(104, write(&(String){2, 1, "*"}) )
  }
  CHECK(105, write(&(String){2, 1, " "}) )
  CHECK(106, write_cname(self->name) )
  
  if (!self->type_instance->type_data->is_primitive && (self->access == ACCESS_VAR || self->access == ACCESS_AUX)) {
    /* `type` `name`_Var = {...}; */
    /* `type`* `name` = &`name`_Var; */
    CHECK(112, write(&(String){9, 8, "_Var = {"}) )
    if ((self->type_instance->type_data == glob->type_array || self->type_instance->type_data == glob->type_string) && self->access == ACCESS_VAR) {
      /* {`length`, 0, NULL} */
      CHECK(117, (self->type_instance->length)->_base._dtl[1](self->type_instance->length) )
      if (self->type_instance->type_data == glob->type_string) {
        CHECK(119, write(&(String){4, 3, ", 0"}) )
      }
      CHECK(120, write(&(String){7, 6, ", NULL"}) )
    }
    else {
      CHECK(122, write(&(String){2, 1, "0"}) )
    }
    CHECK(123, write(&(String){4, 3, "};\n"}) )
    CHECK(124, SyntaxTreeCode_write_spaces(&(self->_base)) )
    CHECK(125, write_cname(self->type_instance->type_data->name) )
    CHECK(126, write(&(String){3, 2, "* "}) )
    CHECK(127, write_cname(self->name) )
    CHECK(128, write(&(String){5, 4, " = &"}) )
    CHECK(129, write_cname(self->name) )
    CHECK(130, write(&(String){5, 4, "_Var"}) )
  }
  else {
    if (NULL != self->_base.parent) {
      /* `type` `name` = 0; */
      /* `type`* `name` = NULL; */
      if (self->access == ACCESS_VAR) {
        CHECK(135, write(&(String){5, 4, " = 0"}) )
      }
      else {
        CHECK(137, write(&(String){8, 7, " = NULL"}) )
      }
    }
  }
  
  CHECK(139, write(&(String){2, 1, ";"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeVariable__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeVariable__dtl[] = {(void*)SyntaxTreeVariable_analyze, (void*)SyntaxTreeVariable_write, (void*)SyntaxTreeCode_m_is_end_point};
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
  CHECK(147, BaseVariableInit_init_parent(self, variable->_base.parent) )
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
  CHECK(151, SyntaxTreeNode_set_location(&(self->_base._base)) )
  CHECK(152, List_add(self->_base.parent->code_nodes, &(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func BaseVariableInit__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func BaseVariableInit__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeNode_write, (void*)SyntaxTreeCode_m_is_end_point};
#endif


/* Initialize dynamically allocated variable node in the syntax tree */
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
  if (new_node == NULL) RAISE(158)
  *new_node = (SyntaxTreeInitVarSequence){SyntaxTreeInitVarSequence__dtl, NULL, 0, NULL, NULL};
  new_node->_base._base._base._dtl = SyntaxTreeInitVarSequence__dtl;
  CHECK(159, BaseVariableInit_init(&(new_node->_base), variable) )
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
  CHECK(163, write_cname(self->_base.variable->name) )
  CHECK(164, write(&(String){15, 14, "_Var.values = "}) )
  CHECK(165, write_cname(self->_base.variable->name) )
  CHECK(166, write(&(String){9, 8, "_Values;"}) )
  if (self->_base.variable->type_instance->type_data == glob->type_array && self->_base.variable->type_instance->sub_type->type_data == glob->type_string) {
    /* MR_set_var_string_array( */
    /*    `array-length`, `string-length`, `name`, `name`_Chars); */
    CHECK(171, write(&(String){2, 1, "\n"}) )
    CHECK(172, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
    CHECK(173, write(&(String){25, 24, "MR_set_var_string_array("}) )
    CHECK(174, (self->_base.variable->type_instance->length)->_base._dtl[1](self->_base.variable->type_instance->length) )
    CHECK(175, write(&(String){3, 2, ", "}) )
    CHECK(176, (self->_base.variable->type_instance->sub_type->length)->_base._dtl[1](self->_base.variable->type_instance->sub_type->length) )
    CHECK(177, write(&(String){3, 2, ", "}) )
    CHECK(178, write_cname(self->_base.variable->name) )
    CHECK(179, write(&(String){3, 2, ", "}) )
    CHECK(180, write_cname(self->_base.variable->name) )
    CHECK(181, write(&(String){9, 8, "_Chars);"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeInitVarSequence__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeInitVarSequence__dtl[] = {(void*)SyntaxTreeNode_analyze, (void*)SyntaxTreeInitVarSequence_write, (void*)SyntaxTreeCode_m_is_end_point};
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
  if (node_init_new == NULL) RAISE(188)
  *node_init_new = (SyntaxTreeInitNew){SyntaxTreeInitNew__dtl, NULL, 0, NULL, NULL};
  node_init_new->_base._base._base._dtl = SyntaxTreeInitNew__dtl;
  CHECK(189, BaseVariableInit_init_parent(&(node_init_new->_base), parent_block) )
  CHECK(190, SyntaxTreeVariable_parse_new(NULL, ACCESS_NEW, NULL, parent_block, &((*end)), &((*new_var_node))) )
  node_init_new->_base.variable = (*new_var_node);
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeInitNew_analyze(SyntaxTreeInitNew* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeInitNew_analyze = "SyntaxTreeInitNew.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeInitNew_analyze
Returncode SyntaxTreeInitNew_analyze(SyntaxTreeInitNew* self) {
  if (self->_base.variable->type_instance->type_data->is_primitive) {
    CHECK(197, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){37, 36, "cannot use \"new\" with primitive type"}, self->_base.variable->type_instance->type_data->name) )
  }
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
    CHECK(205, (self->_base.variable->type_instance->length)->_base._dtl[3](self->_base.variable->type_instance->length) )
  }
  if (self->_base.variable->type_instance->type_data == glob->type_array && self->_base.variable->type_instance->sub_type->type_data == glob->type_string) {
    CHECK(208, (self->_base.variable->type_instance->sub_type->length)->_base._dtl[3](self->_base.variable->type_instance->sub_type->length) )
  }
  CHECK(209, write_cname(self->_base.variable->name) )
  CHECK(210, write(&(String){4, 3, " = "}) )
  if (self->_base.variable->type_instance->type_data == glob->type_array) {
    /* MR_new_array(length, sizeof(SubType)); */
    /* MR_new_array(length, sizeof(String) + (string-length)); */
    /* MR_set_new_string_array(length, string-length, `name`); */
    CHECK(215, write(&(String){14, 13, "MR_new_array("}) )
    CHECK(216, (self->_base.variable->type_instance->length)->_base._dtl[1](self->_base.variable->type_instance->length) )
    CHECK(217, write(&(String){10, 9, ", sizeof("}) )
    CHECK(218, write_cname(self->_base.variable->type_instance->sub_type->type_data->name) )
    if (self->_base.variable->type_instance->sub_type->type_data == glob->type_string) {
      CHECK(220, write(&(String){6, 5, ") + ("}) )
      CHECK(221, (self->_base.variable->type_instance->sub_type->length)->_base._dtl[1](self->_base.variable->type_instance->sub_type->length) )
      CHECK(222, write(&(String){5, 4, "));\n"}) )
      CHECK(223, SyntaxTreeCode_write_spaces(&(self->_base._base)) )
      CHECK(224, write(&(String){25, 24, "MR_set_new_string_array("}) )
      CHECK(225, (self->_base.variable->type_instance->length)->_base._dtl[1](self->_base.variable->type_instance->length) )
      CHECK(226, write(&(String){3, 2, ", "}) )
      CHECK(227, (self->_base.variable->type_instance->sub_type->length)->_base._dtl[1](self->_base.variable->type_instance->sub_type->length) )
      CHECK(228, write(&(String){3, 2, ", "}) )
      CHECK(229, write_cname(self->_base.variable->name) )
    }
    else {
      CHECK(231, write(&(String){2, 1, ")"}) )
      
    }
  }
  else {
    if (self->_base.variable->type_instance->type_data == glob->type_string) {
      /* MR_new_string(length); */
      CHECK(235, write(&(String){15, 14, "MR_new_string("}) )
      CHECK(236, (self->_base.variable->type_instance->length)->_base._dtl[1](self->_base.variable->type_instance->length) )
    }
    else {
      /* calloc(1, sizeof(`type`)); */
      CHECK(239, write(&(String){18, 17, "calloc(1, sizeof("}) )
      CHECK(240, write_cname(self->_base.variable->type_instance->type_data->name) )
      CHECK(241, write(&(String){2, 1, ")"}) )
    }
  }
  CHECK(242, write(&(String){3, 2, ");"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeInitNew__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeInitNew__dtl[] = {(void*)SyntaxTreeInitNew_analyze, (void*)SyntaxTreeInitNew_write, (void*)SyntaxTreeCode_m_is_end_point};
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
  if (new_node == NULL) RAISE(250)
  *new_node = (SyntaxTreeVariableInit){SyntaxTreeVariableInit__dtl, NULL, 0, NULL, NULL, NULL};
  new_node->_base._base._base._dtl = SyntaxTreeVariableInit__dtl;
  CHECK(251, SyntaxTreeVariableInit_parse(new_node, variable, &((*end))) )
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
  CHECK(254, BaseVariableInit_init(&(self->_base), variable) )
  CHECK(255, parse_new_expression(&(String){2, 1, ")"}, &(self->_base._base), &(self->value), &((*end))) )
  if ((*end) != ')') {
    CHECK(257, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){39, 38, "expected \")\" after initialization, got"}, (*end)) )
  }
  CHECK(260, read_c(&((*end))) )
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
    CHECK(267, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){37, 36, "cannot initialize non-primitive type"}, self->_base.variable->type_instance->type_data->name) )
  }
  CHECK(270, (self->value)->_base._dtl[0](self->value) )
  CHECK(271, TypeInstance_m_check_assign_to(self->value->result_type, self->_base.variable->type_instance, &(self->_base._base._base)) )
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
  CHECK(275, (self->value)->_base._dtl[3](self->value) )
  if ((self->_base.variable->access == ACCESS_VAR || self->_base.variable->access == ACCESS_NEW) && self->_base.variable->type_instance->type_data == glob->type_string) {
    /* CHECK(`line-num`, String_copy(`name`, `value`) ) */
    CHECK(280, SyntaxTreeNode_write_call(&(self->_base._base._base)) )
    CHECK(281, write(&(String){13, 12, "String_copy("}) )
    CHECK(282, write_cname(self->_base.variable->name) )
    CHECK(283, write(&(String){3, 2, ", "}) )
    CHECK(284, (self->value)->_base._dtl[1](self->value) )
    CHECK(285, write(&(String){4, 3, ") )"}) )
  }
  else {
    /* `name` = `value`; */
    CHECK(288, write_cname(self->_base.variable->name) )
    CHECK(289, write(&(String){4, 3, " = "}) )
    CHECK(290, (self->value)->_base._dtl[1](self->value) )
    CHECK(291, write(&(String){2, 1, ";"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeVariableInit__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeVariableInit__dtl[] = {(void*)SyntaxTreeVariableInit_analyze, (void*)SyntaxTreeVariableInit_write, (void*)SyntaxTreeCode_m_is_end_point};
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
