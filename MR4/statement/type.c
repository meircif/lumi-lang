#ifndef MR_MAINFILE
#define MR_MAINFILE "statement/type.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file27_name = "statement/type.3.mr";
#endif
#define MR_FILE_NAME _mr_file27_name

/* MR4 compiler - Syntax tree type */

/* Type node in the syntax tree  */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeData TypeData;
#elif MR_STAGE == MR_TYPES(3)
struct TypeData {
  SyntaxTreeNamespace _base;
  String* name;
  TypeInstance* base_type;
  List* parameters;
  NameMap* dynamic_base_methods;
  SyntaxTreeConstructor* constructor;
  Bool is_primitive;
  Bool is_dynamic;
  Bool is_ordered;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_parse_new(TypeData* self, Bool is_dynamic, Char* end, TypeData** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_parse_new = "TypeData.parse-new";
#define MR_FUNC_NAME _func_name_TypeData_parse_new
Returncode TypeData_parse_new(TypeData* self, Bool is_dynamic, Char* end, TypeData** new_node) {
  (*new_node) = malloc(sizeof(TypeData));
  if ((*new_node) == NULL) RAISE(16)
  *(*new_node) = (TypeData){TypeData__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, NULL, false, false, false};
  (*new_node)->_base._base._base._dtl = TypeData__dtl;
  CHECK(17, TypeData_parse((*new_node), is_dynamic, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_parse(TypeData* self, Bool is_dynamic, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_parse = "TypeData.parse";
#define MR_FUNC_NAME _func_name_TypeData_parse
Returncode TypeData_parse(TypeData* self, Bool is_dynamic, Char* end) {
  self->is_dynamic = is_dynamic;
  CHECK(21, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(22, read_new(&(String){3, 2, "({"}, &(self->name), &((*end))) )
  CHECK(23, TypeData_add_type(self) )
  if ((*end) == '{') {
    self->parameters = malloc(sizeof(List));
    if (self->parameters == NULL) RAISE(25)
    *self->parameters = (List){NULL, NULL};
    while (true) {
      String* name = NULL;
      CHECK(28, read_new(&(String){3, 2, ":}"}, &(name), &((*end))) )
      Bool _Bool134;
      CHECK(29, f_is_legal_name(name, true, &(_Bool134)) )
      if (!_Bool134) {
        CHECK(30, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){28, 27, "illegal type parameter name"}, name) )
      }
      CHECK(31, List_add(self->parameters, name) )
      if (!((*end) == ':')) break;
    }
    if ((*end) != '}') {
      CHECK(34, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){40, 39, "expected \"}\" after type parameters, got"}, (*end)) )
    }
    CHECK(36, read_c(&((*end))) )
  }
  if ((*end) == '(') {
    self->base_type = malloc(sizeof(TypeInstance));
    if (self->base_type == NULL) RAISE(38)
    *self->base_type = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL};
    CHECK(39, TypeInstance_parse(self->base_type, &(String){2, 1, ")"}, &(self->_base._base._base), NULL, &((*end))) )
    if ((*end) != ')') {
      CHECK(41, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){34, 33, "expected \")\" after base type, got"}, (*end)) )
    }
    CHECK(43, read_c(&((*end))) )
  }
  self->_base._base.indentation_spaces = 2;
  CHECK(45, SyntaxTreeBranch_parse_block_children(&(self->_base._base), self, NULL, &((*end))) )
  self->_base._base.indentation_spaces = 0;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_add_type(TypeData* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_add_type = "TypeData.add-type";
#define MR_FUNC_NAME _func_name_TypeData_add_type
Returncode TypeData_add_type(TypeData* self) {
  Bool _Bool135;
  CHECK(49, f_is_legal_name(self->name, true, &(_Bool135)) )
  if (!_Bool135) {
    CHECK(50, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){18, 17, "illegal type name"}, self->name) )
  }
  TypeData* _TypeData136;
  CHECK(51, NameMap_find(glob->type_map, self->name, (void**)&(_TypeData136)) )
  if (NULL != _TypeData136) {
    CHECK(52, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){21, 20, "redefinition of type"}, self->name) )
  }
  CHECK(53, Global_add_type(glob, self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_parse_child(TypeData* self, String* keyword, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_parse_child = "TypeData.parse-child";
#define MR_FUNC_NAME _func_name_TypeData_parse_child
Returncode TypeData_parse_child(TypeData* self, String* keyword, Char* end) {
  Bool _Bool137;
  CHECK(56, SyntaxTreeNamespace_parse_if_function(&(self->_base), keyword, self, &((*end)), &(_Bool137)) )
  if (_Bool137) {
    return OK;
  }
  
  Bool _Bool138;
  CHECK(59, String_equal(keyword, &(String){4, 3, "new"}, &(_Bool138)) )
  if (_Bool138) {
    if ((*end) != '(') {
      CHECK(61, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){30, 29, "expected \"(\" after \"new\", got"}, (*end)) )
    }
    if (NULL != self->constructor) {
      CHECK(64, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){37, 36, "constructor already defined for type"}, self->name) )
    }
    SyntaxTreeConstructor* constructor = NULL;
    CHECK(67, SyntaxTreeConstructor_parse_new(NULL, self, &((*end)), &(constructor)) )
    self->constructor = constructor;
    CHECK(69, List_add(self->_base.functions, &(constructor->_base)) )
    
  }
  else {
    CHECK(72, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){16, 15, "unknown keyword"}, keyword) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_m_is_same(TypeData* self, TypeData* other, Bool* is_same);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_m_is_same = "TypeData.m-is-same";
#define MR_FUNC_NAME _func_name_TypeData_m_is_same
Returncode TypeData_m_is_same(TypeData* self, TypeData* other, Bool* is_same) {
  (*is_same) = self == other || ((self == &(glob->type_int->_base) || self == &(glob->type_char->_base)) && (other == &(glob->type_int->_base) || other == &(glob->type_char->_base)));
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_m_new_type_instance(TypeData* self, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_m_new_type_instance = "TypeData.m-new-type-instance";
#define MR_FUNC_NAME _func_name_TypeData_m_new_type_instance
Returncode TypeData_m_new_type_instance(TypeData* self, TypeInstance** type_instance) {
  (*type_instance) = malloc(sizeof(TypeInstance));
  if ((*type_instance) == NULL) RAISE(80)
  *(*type_instance) = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL};
  (*type_instance)->type_data = self;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_m_self_type_instance(TypeData* self, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_m_self_type_instance = "TypeData.m-self-type-instance";
#define MR_FUNC_NAME _func_name_TypeData_m_self_type_instance
Returncode TypeData_m_self_type_instance(TypeData* self, TypeInstance** type_instance) {
  CHECK(84, TypeData_m_new_type_instance(self, &((*type_instance))) )
  if (NULL != self->parameters) {
    (*type_instance)->parameters = malloc(sizeof(List));
    if ((*type_instance)->parameters == NULL) RAISE(86)
    *(*type_instance)->parameters = (List){NULL, NULL};
    ListNode* node = self->parameters->first;
    while (true) {
      if (!(NULL != node)) break;
      TypeInstance* parameter = malloc(sizeof(TypeInstance));
      if (parameter == NULL) RAISE(90)
      *parameter = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL};
      parameter->type_data = &(glob->type_generic->_base);
      CHECK(92, string_new_copy(node->item, &(parameter->name)) )
      CHECK(93, List_add((*type_instance)->parameters, parameter) )
      node = node->next;
    }
  }
  
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_get_parent_type(TypeData* self, TypeData** parent_type);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_get_parent_type = "TypeData.get-parent-type";
#define MR_FUNC_NAME _func_name_TypeData_get_parent_type
Returncode TypeData_get_parent_type(TypeData* self, TypeData** parent_type) {
  (*parent_type) = self;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_find_field(TypeData* self, String* name, SyntaxTreeVariable** field, Int* bases);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_find_field = "TypeData.find-field";
#define MR_FUNC_NAME _func_name_TypeData_find_field
Returncode TypeData_find_field(TypeData* self, String* name, SyntaxTreeVariable** field, Int* bases) {
  TypeData* type_data = self;
  (*bases) = 0;
  while (true) {
    if (!(NULL != type_data)) break;
    ListNode* child = type_data->_base._base.variables->first;
    while (true) {
      if (!(NULL != child)) break;
      Bool _Bool139;
      CHECK(109, String_equal(((SyntaxTreeVariable*)(child->item))->name, name, &(_Bool139)) )
      if (_Bool139) {
        (*field) = ((SyntaxTreeVariable*)(child->item));
        return OK;
      }
      child = child->next;
    }
    if (!(NULL != type_data->base_type)) break;
    type_data = type_data->base_type->type_data;
    (*bases) += 1;
  }
  (*field) = NULL;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_find_meth(TypeData* self, String* name, SyntaxTreeFunction** method, Int* bases);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_find_meth = "TypeData.find-meth";
#define MR_FUNC_NAME _func_name_TypeData_find_meth
Returncode TypeData_find_meth(TypeData* self, String* name, SyntaxTreeFunction** method, Int* bases) {
  TypeData* type_data = self;
  (*bases) = 0;
  while (true) {
    if (!(NULL != type_data)) break;
    ListNode* child = type_data->_base.functions->first;
    while (true) {
      if (!(NULL != child)) break;
      Bool _Bool140;
      CHECK(127, String_equal(((SyntaxTreeFunction*)(child->item))->name, name, &(_Bool140)) )
      if (_Bool140) {
        (*method) = ((SyntaxTreeFunction*)(child->item));
        return OK;
      }
      child = child->next;
    }
    if (!(NULL != type_data->base_type)) break;
    type_data = type_data->base_type->type_data;
    (*bases) += 1;
  }
  (*method) = NULL;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_m_order_bases(TypeData* self, List* ordered_list);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_m_order_bases = "TypeData.m-order-bases";
#define MR_FUNC_NAME _func_name_TypeData_m_order_bases
Returncode TypeData_m_order_bases(TypeData* self, List* ordered_list) {
  if (self->is_ordered) {
    return OK;
  }
  if (NULL != self->base_type) {
    CHECK(140, SyntaxTreeNode_find_type(&(self->_base._base._base), self->base_type->name, &(self->base_type->type_data)) )
    CHECK(141, TypeData_m_order_bases(self->base_type->type_data, ordered_list) )
  }
  CHECK(142, List_add(ordered_list, self) )
  /* init `self.dynamic-base-methods` and test override methods */
  if (self->is_dynamic) {
    self->dynamic_base_methods = malloc(sizeof(NameMap));
    if (self->dynamic_base_methods == NULL) RAISE(145)
    *self->dynamic_base_methods = (NameMap){NULL, NULL};
  }
  ListNode* child = self->_base.functions->first;
  while (true) {
    if (!(NULL != child)) break;
    SyntaxTreeFunction* method = NULL;
    Int bases = 0;
    if (NULL != self->base_type) {
      CHECK(152, TypeData_find_meth(self->base_type->type_data, ((SyntaxTreeFunction*)(child->item))->name, &(method), &(bases)) )
    }
    if (NULL != method) {
      CHECK(155, SyntaxTreeFunction_m_compare(((SyntaxTreeFunction*)(child->item)), method) )
      if (((SyntaxTreeFunction*)(child->item))->is_dynamic) {
        ((SyntaxTreeFunction*)(child->item))->dynamic_base_method = method->dynamic_base_method;
        ((SyntaxTreeFunction*)(child->item))->dynamic_base_count = method->dynamic_base_count + bases + 1;
      }
    }
    else {
      if (((SyntaxTreeFunction*)(child->item))->is_dynamic) {
        ((SyntaxTreeFunction*)(child->item))->dynamic_base_method = ((SyntaxTreeFunction*)(child->item));
        CHECK(161, NameMap_add(self->dynamic_base_methods, ((SyntaxTreeFunction*)(child->item))->name, child->item) )
      }
    }
    child = child->next;
  }
  self->is_ordered = true;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_link_types(TypeData* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_link_types = "TypeData.link-types";
#define MR_FUNC_NAME _func_name_TypeData_link_types
Returncode TypeData_link_types(TypeData* self) {
  if (NULL != self->base_type) {
    CHECK(167, TypeInstance_link_types(self->base_type, &(self->_base._base._base)) )
  }
  CHECK(168, SyntaxTreeNamespace_link_types(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_analyze(TypeData* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_analyze = "TypeData.analyze";
#define MR_FUNC_NAME _func_name_TypeData_analyze
Returncode TypeData_analyze(TypeData* self) {
  if (NULL != self->base_type) {
    CHECK(172, TypeInstance_analyze_lengths(self->base_type, &(self->_base._base._base)) )
  }
  Bool _Bool141;
  CHECK(173, List_m_is_empty(self->_base._base.variables, &(_Bool141)) )
  if (!(NULL != self->base_type) && _Bool141) {
    CHECK(174, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){20, 19, "type with no fields"}, self->name) )
  }
  if (self->is_dynamic &&  ! (NULL != self->base_type && self->base_type->type_data->is_dynamic)) {
    ListNode* node = self->_base.functions->first;
    while (true) {
      if (!(NULL != node)) {
        CHECK(180, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){30, 29, "class with no dynamic methods"}, self->name) )
      }
      if (!(!((SyntaxTreeFunction*)(node->item))->is_dynamic)) break;
      node = node->next;
    }
  }
  CHECK(184, SyntaxTreeNamespace_analyze(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_write_declaration(TypeData* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_write_declaration = "TypeData.write-declaration";
#define MR_FUNC_NAME _func_name_TypeData_write_declaration
Returncode TypeData_write_declaration(TypeData* self) {
  /* typedef struct `name` `name`; */
  /* typedef struct `name`_Dynamic `name`_Dynamic; */
  CHECK(189, write(&(String){17, 16, "\ntypedef struct "}) )
  CHECK(190, write_cname(self->name) )
  CHECK(191, write(&(String){2, 1, " "}) )
  CHECK(192, write_cname(self->name) )
  CHECK(193, write(&(String){3, 2, ";\n"}) )
  if (self->is_dynamic) {
    CHECK(195, write(&(String){17, 16, "\ntypedef struct "}) )
    CHECK(196, write_cname(self->name) )
    CHECK(197, write(&(String){10, 9, "_Dynamic "}) )
    CHECK(198, write_cname(self->name) )
    CHECK(199, write(&(String){11, 10, "_Dynamic;\n"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_write(TypeData* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_write = "TypeData.write";
#define MR_FUNC_NAME _func_name_TypeData_write
Returncode TypeData_write(TypeData* self) {
  /* struct `name` { */
  /*   `variables...` */
  /* }; */
  /* struct `name`_Dynamic { */
  /*   `dynamic-function-pointers...` */
  /* }; */
  CHECK(208, write(&(String){9, 8, "\nstruct "}) )
  CHECK(209, write_cname(self->name) )
  CHECK(210, write(&(String){4, 3, " {\n"}) )
  self->_base._base.indentation_spaces = 2;
  if (NULL != self->base_type) {
    CHECK(213, SyntaxTreeBranch_write_spaces(&(self->_base._base)) )
    CHECK(214, write_cname(self->base_type->type_data->name) )
    CHECK(215, write(&(String){9, 8, " _base;\n"}) )
  }
  CHECK(216, SyntaxTreeNode_write_children(&(self->_base._base._base), self->_base._base.variables) )
  CHECK(217, write(&(String){4, 3, "};\n"}) )
  if (self->is_dynamic) {
    CHECK(219, write(&(String){9, 8, "\nstruct "}) )
    CHECK(220, write_cname(self->name) )
    CHECK(221, write(&(String){12, 11, "_Dynamic {\n"}) )
    if (NULL != self->base_type && self->base_type->type_data->is_dynamic) {
      CHECK(223, SyntaxTreeBranch_write_spaces(&(self->_base._base)) )
      CHECK(224, write_cname(self->base_type->type_data->name) )
      CHECK(225, write(&(String){17, 16, "_Dynamic _base;\n"}) )
    }
    else {
      CHECK(227, SyntaxTreeBranch_write_spaces(&(self->_base._base)) )
      CHECK(228, write(&(String){19, 18, "Dynamic_Del _del;\n"}) )
    }
    NameMapNode* child = self->dynamic_base_methods->first;
    while (true) {
      if (!(NULL != child)) break;
      CHECK(232, SyntaxTreeBranch_write_spaces(&(self->_base._base)) )
      CHECK(233, SyntaxTreeFunction_write_pointer(((SyntaxTreeFunction*)(child->value))) )
      CHECK(234, write(&(String){3, 2, ";\n"}) )
      child = child->next;
    }
    CHECK(236, write(&(String){4, 3, "};\n"}) )
  }
  self->_base._base.indentation_spaces = 0;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_write_methods_declaration(TypeData* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_write_methods_declaration = "TypeData.write-methods-declaration";
#define MR_FUNC_NAME _func_name_TypeData_write_methods_declaration
Returncode TypeData_write_methods_declaration(TypeData* self) {
  CHECK(240, SyntaxTreeNamespace_write_functions_declaration(&(self->_base)) )
  /* void `cname`_Del(`cname`* self); */
  CHECK(242, write(&(String){7, 6, "\nvoid "}) )
  CHECK(243, write_cname(self->name) )
  CHECK(244, write(&(String){6, 5, "_Del("}) )
  CHECK(245, write_cname(self->name) )
  CHECK(246, write(&(String){10, 9, "* self);\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_write_global(TypeData* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_write_global = "TypeData.write-global";
#define MR_FUNC_NAME _func_name_TypeData_write_global
Returncode TypeData_write_global(TypeData* self) {
  /* `name`_Dynamic `name`_dynamic = {`dynamic-functions...`}; */
  if (self->is_dynamic) {
    CHECK(251, write(&(String){2, 1, "\n"}) )
    CHECK(252, write_cname(self->name) )
    CHECK(253, write(&(String){10, 9, "_Dynamic "}) )
    CHECK(254, write_cname(self->name) )
    CHECK(255, write(&(String){12, 11, "_dynamic = "}) )
    CHECK(256, TypeData_write_dynamic_init(self, self) )
    CHECK(257, write(&(String){3, 2, ";\n"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_write_dynamic_init(TypeData* self, TypeData* type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_write_dynamic_init = "TypeData.write-dynamic-init";
#define MR_FUNC_NAME _func_name_TypeData_write_dynamic_init
Returncode TypeData_write_dynamic_init(TypeData* self, TypeData* type_data) {
  CHECK(260, write(&(String){2, 1, "{"}) )
  if (NULL != type_data->base_type && type_data->base_type->type_data->is_dynamic) {
    CHECK(262, TypeData_write_dynamic_init(self, type_data->base_type->type_data) )
  }
  else {
    CHECK(264, write(&(String){14, 13, "(Dynamic_Del)"}) )
    CHECK(265, write_cname(self->name) )
    CHECK(266, write(&(String){5, 4, "_Del"}) )
  }
  NameMapNode* child = type_data->dynamic_base_methods->first;
  while (true) {
    if (!(NULL != child)) break;
    SyntaxTreeFunction* method = NULL;
    Int _Int142;
    CHECK(271, TypeData_find_meth(self, ((SyntaxTreeFunction*)(child->value))->name, &(method), &(_Int142)) )
    CHECK(272, write(&(String){3, 2, ", "}) )
    if (method != ((SyntaxTreeFunction*)(child->value))) {
      CHECK(274, write(&(String){7, 6, "(Func)"}) )
    }
    CHECK(275, write_cname(method->parent_type->name) )
    CHECK(276, write(&(String){2, 1, "_"}) )
    CHECK(277, write_cname(method->name) )
    child = child->next;
  }
  CHECK(279, write(&(String){2, 1, "}"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_write_methods_body(TypeData* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_write_methods_body = "TypeData.write-methods-body";
#define MR_FUNC_NAME _func_name_TypeData_write_methods_body
Returncode TypeData_write_methods_body(TypeData* self) {
  CHECK(282, SyntaxTreeNode_write_children(&(self->_base._base._base), self->_base.functions) )
  /* void `cname`_Del(`cname`* self) { */
  /*   if (self == NULL) return; */
  /*   `base`_Del(self); */
  /*   ... */
  /* } */
  CHECK(288, write(&(String){7, 6, "\nvoid "}) )
  CHECK(289, write_cname(self->name) )
  CHECK(290, write(&(String){6, 5, "_Del("}) )
  CHECK(291, write_cname(self->name) )
  CHECK(292, write(&(String){11, 10, "* self) {\n"}) )
  CHECK(293, write(&(String){29, 28, "  if (self == NULL) return;\n"}) )
  if (NULL != self->base_type) {
    CHECK(295, write(&(String){3, 2, "  "}) )
    CHECK(296, write_cname(self->base_type->type_data->name) )
    CHECK(297, write(&(String){23, 22, "_Del(&(self->_base));\n"}) )
  }
  CHECK(298, SyntaxTreeBranch_write_cleanup(&(self->_base._base), true) )
  CHECK(299, write(&(String){3, 2, "}\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_write_me(TypeData* self, TypeWriter* type_writer);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_write_me = "TypeData.write-me";
#define MR_FUNC_NAME _func_name_TypeData_write_me
Returncode TypeData_write_me(TypeData* self, TypeWriter* type_writer) {
  CHECK(302, (type_writer)->_dtl[0](type_writer, self) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func TypeData__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func TypeData__dtl[] = {(void*)TypeData_get_parent_type, (void*)TypeData_link_types, (void*)TypeData_analyze, (void*)TypeData_write, (void*)TypeData_parse_child, (void*)SyntaxTreeBranch_find_variable, (void*)TypeData_write_declaration, (void*)TypeData_write_methods_declaration, (void*)TypeData_write_methods_body, (void*)TypeData_write_me};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeWriter TypeWriter;
#elif MR_STAGE == MR_TYPES(0)
struct TypeWriter {
  Func* _dtl;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeWriter_write(TypeWriter* self, TypeData* type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeWriter_write = "TypeWriter.write";
#define MR_FUNC_NAME _func_name_TypeWriter_write
Returncode TypeWriter_write(TypeWriter* self, TypeData* type_data) {
  RAISE(307)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func TypeWriter__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func TypeWriter__dtl[] = {(void*)TypeWriter_write};
#endif

#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeDeclarationWriter TypeDeclarationWriter;
#elif MR_STAGE == MR_TYPES(1)
struct TypeDeclarationWriter {
  TypeWriter _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeDeclarationWriter_write(TypeDeclarationWriter* self, TypeData* type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeDeclarationWriter_write = "TypeDeclarationWriter.write";
#define MR_FUNC_NAME _func_name_TypeDeclarationWriter_write
Returncode TypeDeclarationWriter_write(TypeDeclarationWriter* self, TypeData* type_data) {
  CHECK(311, (type_data)->_base._base._base._dtl[6](type_data) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func TypeDeclarationWriter__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func TypeDeclarationWriter__dtl[] = {(void*)TypeDeclarationWriter_write};
#endif

#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeMethodsDeclarationWriter TypeMethodsDeclarationWriter;
#elif MR_STAGE == MR_TYPES(1)
struct TypeMethodsDeclarationWriter {
  TypeWriter _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeMethodsDeclarationWriter_write(TypeMethodsDeclarationWriter* self, TypeData* type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeMethodsDeclarationWriter_write = "TypeMethodsDeclarationWriter.write";
#define MR_FUNC_NAME _func_name_TypeMethodsDeclarationWriter_write
Returncode TypeMethodsDeclarationWriter_write(TypeMethodsDeclarationWriter* self, TypeData* type_data) {
  CHECK(315, (type_data)->_base._base._base._dtl[7](type_data) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func TypeMethodsDeclarationWriter__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func TypeMethodsDeclarationWriter__dtl[] = {(void*)TypeMethodsDeclarationWriter_write};
#endif

#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeGlobalWriter TypeGlobalWriter;
#elif MR_STAGE == MR_TYPES(1)
struct TypeGlobalWriter {
  TypeWriter _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeGlobalWriter_write(TypeGlobalWriter* self, TypeData* type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeGlobalWriter_write = "TypeGlobalWriter.write";
#define MR_FUNC_NAME _func_name_TypeGlobalWriter_write
Returncode TypeGlobalWriter_write(TypeGlobalWriter* self, TypeData* type_data) {
  CHECK(319, TypeData_write_global(type_data) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func TypeGlobalWriter__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func TypeGlobalWriter__dtl[] = {(void*)TypeGlobalWriter_write};
#endif

#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeMethodsBodyWriter TypeMethodsBodyWriter;
#elif MR_STAGE == MR_TYPES(1)
struct TypeMethodsBodyWriter {
  TypeWriter _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeMethodsBodyWriter_write(TypeMethodsBodyWriter* self, TypeData* type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeMethodsBodyWriter_write = "TypeMethodsBodyWriter.write";
#define MR_FUNC_NAME _func_name_TypeMethodsBodyWriter_write
Returncode TypeMethodsBodyWriter_write(TypeMethodsBodyWriter* self, TypeData* type_data) {
  CHECK(323, (type_data)->_base._base._base._dtl[8](type_data) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func TypeMethodsBodyWriter__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func TypeMethodsBodyWriter__dtl[] = {(void*)TypeMethodsBodyWriter_write};
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
#include "statement/error.c"
#include "statement/for.c"
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
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
