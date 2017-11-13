#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/type.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file21_name = "syntax-tree/type.3.mr";
#endif
#define MR_FILE_NAME _mr_file21_name

/* MR4 compiler - Syntax tree type */

/* Type node in the syntax tree  */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeData TypeData;
#elif MR_STAGE == MR_TYPES(3)
struct TypeData {
  SyntaxTreeNamespace _base;
  String* name;
  String* base_type_name;
  TypeData* base_type;
  NameMap* dynamic_base_methods;
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
  if ((*new_node) == NULL) RAISE(15)
  *(*new_node) = (TypeData){TypeData__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, NULL, false, false, false};
  (*new_node)->_base._base._base._dtl = TypeData__dtl;
  CHECK(16, TypeData_parse((*new_node), is_dynamic, &((*end))) )
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
  CHECK(20, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(21, read_new(&(String){2, 1, "("}, &(self->name), &((*end))) )
  Bool _Bool104;
  CHECK(22, f_is_legal_name(self->name, true, &(_Bool104)) )
  if (!_Bool104) {
    CHECK(23, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){18, 17, "illegal type name"}, self->name) )
  }
  TypeData* _TypeData105;
  CHECK(24, NameMap_find(glob->type_map, self->name, (void**)&(_TypeData105)) )
  if (NULL != _TypeData105) {
    CHECK(25, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){21, 20, "redefinition of type"}, self->name) )
  }
  CHECK(26, Global_add_type(glob, self) )
  if ((*end) == '(') {
    CHECK(28, read_new(&(String){2, 1, ")"}, &(self->base_type_name), &((*end))) )
    if ((*end) != ')') {
      CHECK(30, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){34, 33, "expected \")\" after base type, got"}, (*end)) )
    }
    CHECK(32, read_c(&((*end))) )
  }
  self->_base._base.indentation_spaces = 2;
  CHECK(34, SyntaxTreeBranch_parse_block_children(&(self->_base._base), self, NULL, &((*end))) )
  self->_base._base.indentation_spaces = 0;
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
  Bool _Bool106;
  CHECK(38, SyntaxTreeNamespace_parse_if_function(&(self->_base), keyword, self, &((*end)), &(_Bool106)) )
  if (!_Bool106) {
    CHECK(39, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){16, 15, "unknown keyword"}, keyword) )
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
  (*is_same) = self == other || ((self == glob->type_int || self == glob->type_char) && (other == glob->type_int || other == glob->type_char));
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
  if ((*type_instance) == NULL) RAISE(47)
  *(*type_instance) = (TypeInstance){NULL, NULL, NULL, NULL, NULL};
  (*type_instance)->type_data = self;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_m_find_field(TypeData* self, String* name, SyntaxTreeVariable** field, Int* bases);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_m_find_field = "TypeData.m-find-field";
#define MR_FUNC_NAME _func_name_TypeData_m_find_field
Returncode TypeData_m_find_field(TypeData* self, String* name, SyntaxTreeVariable** field, Int* bases) {
  TypeData* type_data = self;
  (*bases) = 0;
  while (true) {
    if (!(NULL != type_data)) break;
    ListNode* child = type_data->_base._base.variables->first;
    while (true) {
      if (!(NULL != child)) break;
      Bool _Bool107;
      CHECK(59, String_equal(((SyntaxTreeVariable*)(child->item))->name, name, &(_Bool107)) )
      if (_Bool107) {
        (*field) = ((SyntaxTreeVariable*)(child->item));
        return OK;
      }
      child = child->next;
    }
    type_data = type_data->base_type;
    (*bases) += 1;
  }
  (*field) = NULL;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_m_find_meth(TypeData* self, String* name, SyntaxTreeFunction** method, Int* bases);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_m_find_meth = "TypeData.m-find-meth";
#define MR_FUNC_NAME _func_name_TypeData_m_find_meth
Returncode TypeData_m_find_meth(TypeData* self, String* name, SyntaxTreeFunction** method, Int* bases) {
  TypeData* type_data = self;
  (*bases) = 0;
  while (true) {
    if (!(NULL != type_data)) break;
    ListNode* child = type_data->_base.functions->first;
    while (true) {
      if (!(NULL != child)) break;
      Bool _Bool108;
      CHECK(76, String_equal(((SyntaxTreeFunction*)(child->item))->name, name, &(_Bool108)) )
      if (_Bool108) {
        (*method) = ((SyntaxTreeFunction*)(child->item));
        return OK;
      }
      child = child->next;
    }
    type_data = type_data->base_type;
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
  /* init `self.base-type` */
  if (NULL != self->base_type_name) {
    CHECK(89, SyntaxTreeNode_m_find_type(&(self->_base._base._base), self->base_type_name, &(self->base_type)) )
    CHECK(90, TypeData_m_order_bases(self->base_type, ordered_list) )
  }
  CHECK(91, List_add(ordered_list, self) )
  /* init `self.dynamic-base-methods` and test override methods */
  if (self->is_dynamic) {
    self->dynamic_base_methods = malloc(sizeof(NameMap));
    if (self->dynamic_base_methods == NULL) RAISE(94)
    *self->dynamic_base_methods = (NameMap){NULL, NULL};
  }
  ListNode* child = self->_base.functions->first;
  while (true) {
    if (!(NULL != child)) break;
    SyntaxTreeFunction* method = NULL;
    Int bases = 0;
    CHECK(100, TypeData_m_find_meth(self->base_type, ((SyntaxTreeFunction*)(child->item))->name, &(method), &(bases)) )
    if (NULL != method) {
      CHECK(102, SyntaxTreeFunction_m_compare(((SyntaxTreeFunction*)(child->item)), method) )
      if (((SyntaxTreeFunction*)(child->item))->is_dynamic) {
        ((SyntaxTreeFunction*)(child->item))->dynamic_base_method = method->dynamic_base_method;
        ((SyntaxTreeFunction*)(child->item))->dynamic_base_count = method->dynamic_base_count + bases + 1;
      }
    }
    else {
      if (((SyntaxTreeFunction*)(child->item))->is_dynamic) {
        ((SyntaxTreeFunction*)(child->item))->dynamic_base_method = ((SyntaxTreeFunction*)(child->item));
        CHECK(108, NameMap_add(self->dynamic_base_methods, ((SyntaxTreeFunction*)(child->item))->name, child->item) )
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
Returncode TypeData_write_declaration(TypeData* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_write_declaration = "TypeData.write-declaration";
#define MR_FUNC_NAME _func_name_TypeData_write_declaration
Returncode TypeData_write_declaration(TypeData* self) {
  /* typedef struct `name` `name`; */
  /* typedef struct `name`_Dynamic `name`_Dynamic; */
  CHECK(115, write(&(String){17, 16, "\ntypedef struct "}) )
  CHECK(116, write_cname(self->name) )
  CHECK(117, write(&(String){2, 1, " "}) )
  CHECK(118, write_cname(self->name) )
  CHECK(119, write(&(String){3, 2, ";\n"}) )
  if (self->is_dynamic) {
    CHECK(121, write(&(String){17, 16, "\ntypedef struct "}) )
    CHECK(122, write_cname(self->name) )
    CHECK(123, write(&(String){10, 9, "_Dynamic "}) )
    CHECK(124, write_cname(self->name) )
    CHECK(125, write(&(String){11, 10, "_Dynamic;\n"}) )
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
  CHECK(134, write(&(String){8, 7, "struct "}) )
  CHECK(135, write_cname(self->name) )
  CHECK(136, write(&(String){4, 3, " {\n"}) )
  self->_base._base.indentation_spaces = 2;
  if (NULL != self->base_type) {
    CHECK(139, SyntaxTreeBranch_write_spaces(&(self->_base._base)) )
    CHECK(140, write_cname(self->base_type->name) )
    CHECK(141, write(&(String){9, 8, " _base;\n"}) )
  }
  CHECK(142, SyntaxTreeBranch_write_children(&(self->_base._base), self->_base._base.variables) )
  CHECK(143, write(&(String){3, 2, "};"}) )
  if (self->is_dynamic) {
    CHECK(145, write(&(String){10, 9, "\n\nstruct "}) )
    CHECK(146, write_cname(self->name) )
    CHECK(147, write(&(String){12, 11, "_Dynamic {\n"}) )
    if (NULL != self->base_type && self->base_type->is_dynamic) {
      CHECK(149, SyntaxTreeBranch_write_spaces(&(self->_base._base)) )
      CHECK(150, write_cname(self->base_type->name) )
      CHECK(151, write(&(String){17, 16, "_Dynamic _base;\n"}) )
    }
    NameMapNode* child = self->dynamic_base_methods->first;
    while (true) {
      if (!(NULL != child)) break;
      CHECK(155, SyntaxTreeBranch_write_spaces(&(self->_base._base)) )
      CHECK(156, SyntaxTreeFunction_write_pointer(((SyntaxTreeFunction*)(child->value))) )
      CHECK(157, write(&(String){3, 2, ";\n"}) )
      child = child->next;
    }
    CHECK(159, write(&(String){3, 2, "};"}) )
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
  CHECK(163, SyntaxTreeNamespace_write_functions_declaration(&(self->_base)) )
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
    CHECK(168, write(&(String){2, 1, "\n"}) )
    CHECK(169, write_cname(self->name) )
    CHECK(170, write(&(String){10, 9, "_Dynamic "}) )
    CHECK(171, write_cname(self->name) )
    CHECK(172, write(&(String){12, 11, "_dynamic = "}) )
    CHECK(173, TypeData_write_dynamic_init(self, self) )
    CHECK(174, write(&(String){3, 2, ";\n"}) )
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
  CHECK(177, write(&(String){2, 1, "{"}) )
  Bool not_first = NULL != type_data->base_type && type_data->base_type->is_dynamic;
  if (not_first) {
    CHECK(180, TypeData_write_dynamic_init(self, type_data->base_type) )
  }
  NameMapNode* child = type_data->dynamic_base_methods->first;
  while (true) {
    if (!(NULL != child)) break;
    SyntaxTreeFunction* method = NULL;
    Int _Int109;
    CHECK(185, TypeData_m_find_meth(self, ((SyntaxTreeFunction*)(child->value))->name, &(method), &(_Int109)) )
    if (not_first) {
      CHECK(187, write(&(String){3, 2, ", "}) )
    }
    if (method != ((SyntaxTreeFunction*)(child->value))) {
      CHECK(189, write(&(String){7, 6, "(Func)"}) )
    }
    CHECK(190, write_cname(method->parent_type->name) )
    CHECK(191, write(&(String){2, 1, "_"}) )
    CHECK(192, write_cname(method->name) )
    not_first = true;
    child = child->next;
  }
  CHECK(195, write(&(String){2, 1, "}"}) )
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
  CHECK(198, SyntaxTreeBranch_write_children(&(self->_base._base), self->_base.functions) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func TypeData__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func TypeData__dtl[] = {(void*)SyntaxTreeNamespace_m_link_types, (void*)SyntaxTreeNamespace_analyze, (void*)TypeData_write, (void*)TypeData_parse_child, (void*)SyntaxTreeBranch_m_find_variable};
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
  RAISE(203)
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
  CHECK(207, TypeData_write_declaration(type_data) )
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
  CHECK(211, TypeData_write_methods_declaration(type_data) )
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
  CHECK(215, TypeData_write_global(type_data) )
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
  CHECK(219, TypeData_write_methods_body(type_data) )
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


/* Specific usage of a type including the assigned subtype */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeInstance TypeInstance;
#elif MR_STAGE == MR_TYPES(0)
struct TypeInstance {
  String* name;
  TypeData* type_data;
  TypeInstance* sub_type;
  Expression* length;
  FunctionArguments* arguments;
/* Return a new deep-copy of self */};
#endif/* Return a new deep-copy of self */
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_m_copy_new(TypeInstance* self, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_m_copy_new = "TypeInstance.m-copy-new";
#define MR_FUNC_NAME _func_name_TypeInstance_m_copy_new
Returncode TypeInstance_m_copy_new(TypeInstance* self, TypeInstance** type_instance) {
  if (!(NULL != self)) {
    (*type_instance) = NULL;
    return OK;
  }
  CHECK(235, TypeData_m_new_type_instance(self->type_data, &((*type_instance))) )
  CHECK(236, string_new_copy(self->name, &((*type_instance)->name)) )
  if (NULL != self->sub_type) {
    CHECK(238, TypeInstance_m_copy_new(self->sub_type, &((*type_instance)->sub_type)) )
  }
  if (NULL != self->arguments) {
    CHECK(240, FunctionArguments_m_copy_new(self->arguments, &((*type_instance)->arguments)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_parse(TypeInstance* self, String* ends, SyntaxTreeNode* node, SyntaxTreeVariable* var_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_parse = "TypeInstance.parse";
#define MR_FUNC_NAME _func_name_TypeInstance_parse
Returncode TypeInstance_parse(TypeInstance* self, String* ends, SyntaxTreeNode* node, SyntaxTreeVariable* var_node, Char* end) {
  String* _String110;
  CHECK(247, string_new_concat(ends, &(String){2, 1, "{"}, &(_String110)) )
  CHECK(247, read_new(_String110, &(self->name), &((*end))) )
  if ((*end) == '{') {
    Bool _Bool111;
    CHECK(250, String_equal(self->name, &(String){5, 4, "Func"}, &(_Bool111)) )
    if (_Bool111) {
      CHECK(251, read_c(&((*end))) )
      if ((*end) != '(') {
        CHECK(253, SyntaxTreeNode_m_syntax_error_c(node, &(String){39, 38, "expected \"(\" inside Function type, got"}, (*end)) )
      }
      self->arguments = malloc(sizeof(FunctionArguments));
      if (self->arguments == NULL) RAISE(255)
      *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
      self->arguments->_base._dtl = FunctionArguments__dtl;
      DeclarationArgumentFactory* argument_factory = &(DeclarationArgumentFactory){DeclarationArgumentFactory__dtl};
      argument_factory->_base._dtl = DeclarationArgumentFactory__dtl;
      CHECK(257, FunctionArguments_parse(self->arguments, &(argument_factory->_base), NULL, &((*end))) )
    }
    else {
      Bool _Bool112;
      CHECK(258, String_equal(self->name, &(String){7, 6, "String"}, &(_Bool112)) )
      if (NULL != var_node && _Bool112) {
        CHECK(259, parse_new_expression(&(String){2, 1, "}"}, &(var_node->_base), &(self->length), &((*end))) )
      }
      else {
        Bool has_sub_type = true;
        Bool _Bool113;
        CHECK(263, String_equal(self->name, &(String){6, 5, "Array"}, &(_Bool113)) )
        if (NULL != var_node && _Bool113) {
          CHECK(264, parse_new_expression(&(String){3, 2, ":}"}, &(var_node->_base), &(self->length), &((*end))) )
          if ((*end) != ':' && (*end) != '}') {
            CHECK(267, SyntaxTreeNode_m_syntax_error_c(node, &(String){18, 17, "expected \":\", got"}, (*end)) )
          }
          has_sub_type = (*end) == ':';
        }
        if (has_sub_type) {
          self->sub_type = malloc(sizeof(TypeInstance));
          if (self->sub_type == NULL) RAISE(270)
          *self->sub_type = (TypeInstance){NULL, NULL, NULL, NULL, NULL};
          CHECK(271, TypeInstance_parse(self->sub_type, &(String){2, 1, "}"}, node, var_node, &((*end))) )
        }
      }
    }
    if ((*end) != '}') {
      CHECK(273, SyntaxTreeNode_m_syntax_error_c(node, &(String){18, 17, "expected \"}\", got"}, (*end)) )
    }
    CHECK(274, read_c(&((*end))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_analyze(TypeInstance* self, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_analyze = "TypeInstance.analyze";
#define MR_FUNC_NAME _func_name_TypeInstance_analyze
Returncode TypeInstance_analyze(TypeInstance* self, SyntaxTreeNode* node) {
  CHECK(277, TypeInstance_analyze_part(self, node, true, true) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_m_link_types(TypeInstance* self, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_m_link_types = "TypeInstance.m-link-types";
#define MR_FUNC_NAME _func_name_TypeInstance_m_link_types
Returncode TypeInstance_m_link_types(TypeInstance* self, SyntaxTreeNode* node) {
  CHECK(280, TypeInstance_analyze_part(self, node, true, false) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_analyze_lengths(TypeInstance* self, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_analyze_lengths = "TypeInstance.analyze-lengths";
#define MR_FUNC_NAME _func_name_TypeInstance_analyze_lengths
Returncode TypeInstance_analyze_lengths(TypeInstance* self, SyntaxTreeNode* node) {
  CHECK(283, TypeInstance_analyze_part(self, node, false, true) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_analyze_part(TypeInstance* self, SyntaxTreeNode* node, Bool check_types, Bool check_length);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_analyze_part = "TypeInstance.analyze-part";
#define MR_FUNC_NAME _func_name_TypeInstance_analyze_part
Returncode TypeInstance_analyze_part(TypeInstance* self, SyntaxTreeNode* node, Bool check_types, Bool check_length) {
  if (check_types) {
    if (!(NULL != self->type_data)) {
      CHECK(289, SyntaxTreeNode_m_find_type(node, self->name, &(self->type_data)) )
    }
    if (NULL != self->arguments) {
      CHECK(291, (self->arguments)->_base._dtl[0](self->arguments) )
    }
  }
  if (check_length) {
    if (NULL != self->length) {
      CHECK(294, SyntaxTreeNode_analyze_expression(node, self->length, glob->type_int) )
    }
    if (NULL != self->arguments) {
      CHECK(296, (self->arguments)->_base._dtl[1](self->arguments) )
    }
  }
  if (NULL != self->sub_type) {
    CHECK(298, TypeInstance_analyze_part(self->sub_type, node, check_types, check_length) )
  }
  if (check_types) {
    if (self->type_data == glob->type_array) {
      if (!(NULL != self->sub_type)) {
        CHECK(302, SyntaxTreeNode_m_syntax_error_msg(node, &(String){26, 25, "missing subtype for array"}) )
      }
      if (self->sub_type->type_data == glob->type_array) {
        CHECK(304, SyntaxTreeNode_m_syntax_error_msg(node, &(String){44, 43, "multidimensional array not supported yet..."}) )
      }
    }
    else {
      if (self->type_data == glob->type_func &&  ! (NULL != self->arguments)) {
        CHECK(307, SyntaxTreeNode_m_syntax_error_msg(node, &(String){35, 34, "missing arguments in function type"}) )
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_m_check_assign_from(TypeInstance* self, SyntaxTreeNode* node, Expression** value);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_m_check_assign_from = "TypeInstance.m-check-assign-from";
#define MR_FUNC_NAME _func_name_TypeInstance_m_check_assign_from
Returncode TypeInstance_m_check_assign_from(TypeInstance* self, SyntaxTreeNode* node, Expression** value) {
  Int bases = 0;
  CHECK(312, TypeInstance_m_check_assign_to((*value)->result_type, self, node, &(bases)) )
  if (bases > 0) {
    CHECK(314, UpCastExpression_init_new(NULL, bases, &((*value))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_m_check_assign_to(TypeInstance* self, TypeInstance* target, SyntaxTreeNode* node, Int* bases);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_m_check_assign_to = "TypeInstance.m-check-assign-to";
#define MR_FUNC_NAME _func_name_TypeInstance_m_check_assign_to
Returncode TypeInstance_m_check_assign_to(TypeInstance* self, TypeInstance* target, SyntaxTreeNode* node, Int* bases) {
  (*bases) = 0;
  if (!(NULL != self)) {
    CHECK(320, SyntaxTreeNode_m_syntax_error_msg(node, &(String){30, 29, "cannot assign void expression"}) )
  }
  if (!(NULL != target)) {
    CHECK(322, SyntaxTreeNode_m_syntax_error_msg(node, &(String){35, 34, "cannot assign into void expression"}) )
  }
  if (self->type_data == glob->type_empty && (!target->type_data->is_primitive || target->type_data == glob->type_func)) {
    return OK;
  }
  TypeData* base_type = self->type_data;
  while (true) {
    Bool _Bool114;
    CHECK(328, TypeData_m_is_same(target->type_data, base_type, &(_Bool114)) )
    if (!(!_Bool114)) break;
    if (!(NULL != base_type->base_type)) {
      CHECK(330, SyntaxTreeNode_m_syntax_error2(node, &(String){14, 13, "cannot assign"}, self->type_data->name, &(String){5, 4, "into"}, target->type_data->name) )
    }
    base_type = base_type->base_type;
    (*bases) += 1;
  }
  
  if (NULL != self->arguments) {
    Bool _Bool115;
    CHECK(339, FunctionArguments_m_check_same_as(self->arguments, target->arguments, &(_Bool115)) )
    if (_Bool115) {
      CHECK(340, SyntaxTreeNode_m_syntax_error_msg(node, &(String){16, 15, "too few outputs"}) )
    }
  }
  
  CHECK(342, TypeInstance_m_check_sub_equal(self, target, node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_m_check_equal(TypeInstance* self, TypeInstance* other, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_m_check_equal = "TypeInstance.m-check-equal";
#define MR_FUNC_NAME _func_name_TypeInstance_m_check_equal
Returncode TypeInstance_m_check_equal(TypeInstance* self, TypeInstance* other, SyntaxTreeNode* node) {
  if (self->type_data != other->type_data) {
    CHECK(346, SyntaxTreeNode_m_syntax_error2(node, &(String){19, 18, "non matching types"}, self->type_data->name, &(String){4, 3, "and"}, other->type_data->name) )
  }
  CHECK(351, TypeInstance_m_check_sub_equal(self, other, node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_m_check_sub_equal(TypeInstance* self, TypeInstance* other, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_m_check_sub_equal = "TypeInstance.m-check-sub-equal";
#define MR_FUNC_NAME _func_name_TypeInstance_m_check_sub_equal
Returncode TypeInstance_m_check_sub_equal(TypeInstance* self, TypeInstance* other, SyntaxTreeNode* node) {
  if (NULL != self->sub_type) {
    if (NULL != other->sub_type) {
      if (self->sub_type->type_data != other->sub_type->type_data) {
        CHECK(357, SyntaxTreeNode_m_syntax_error2(node, &(String){22, 21, "non matching subtypes"}, self->sub_type->type_data->name, &(String){4, 3, "and"}, other->sub_type->type_data->name) )
      }
      CHECK(362, TypeInstance_m_check_sub_equal(self->sub_type, other->sub_type, node) )
    }
    else {
      CHECK(364, SyntaxTreeNode_m_syntax_error2(node, &(String){22, 21, "non matching subtypes"}, self->sub_type->type_data->name, &(String){25, 24, "and type with no subtype"}, other->type_data->name) )
    }
  }
  else {
    if (NULL != other->sub_type) {
      CHECK(370, SyntaxTreeNode_m_syntax_error2(node, &(String){34, 33, "non matching type with no subtype"}, self->type_data->name, &(String){12, 11, "and subtype"}, other->sub_type->type_data->name) )
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_write(TypeInstance* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_write = "TypeInstance.write";
#define MR_FUNC_NAME _func_name_TypeInstance_write
Returncode TypeInstance_write(TypeInstance* self) {
  CHECK(377, write(self->type_data->name) )
  if (NULL != self->sub_type) {
    CHECK(379, write(&(String){2, 1, "{"}) )
    CHECK(380, TypeInstance_write(self->sub_type) )
    CHECK(381, write(&(String){2, 1, "}"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
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
