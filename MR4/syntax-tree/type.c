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
  CHECK(19, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
  CHECK(20, read_new(&(String){2, 1, "("}, &(self->name), &((*end))) )
  self->is_dynamic = is_dynamic;
  CHECK(22, Global_add_type(glob, self) )
  if ((*end) == '(') {
    CHECK(24, read_new(&(String){2, 1, ")"}, &(self->base_type_name), &((*end))) )
    if ((*end) != ')') {
      CHECK(26, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){33, 32, "expected ) after base class, got"}, (*end)) )
    }
    CHECK(27, read_c(&((*end))) )
  }
  self->_base._base.indentation_spaces = 2;
  CHECK(29, SyntaxTreeBranch_parse_block_children(&(self->_base._base), self, NULL, &((*end))) )
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
  Bool _Bool99;
  CHECK(33, SyntaxTreeNamespace_parse_if_function(&(self->_base), keyword, self, &((*end)), &(_Bool99)) )
  if (!_Bool99) {
    CHECK(34, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){16, 15, "unknown keyword"}, keyword) )
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
  if ((*type_instance) == NULL) RAISE(42)
  *(*type_instance) = (TypeInstance){NULL, NULL, NULL, NULL, NULL};
  (*type_instance)->type_data = self;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_m_find_field(TypeData* self, String* name, SyntaxTreeVariable** field);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_m_find_field = "TypeData.m-find-field";
#define MR_FUNC_NAME _func_name_TypeData_m_find_field
Returncode TypeData_m_find_field(TypeData* self, String* name, SyntaxTreeVariable** field) {
  TypeData* type_data = self;
  while (true) {
    if (!(NULL != type_data)) break;
    ListNode* child = type_data->_base._base.variables->first;
    while (true) {
      if (!(NULL != child)) break;
      Bool _Bool100;
      CHECK(52, String_equal(((SyntaxTreeVariable*)(child->item))->name, name, &(_Bool100)) )
      if (_Bool100) {
        (*field) = ((SyntaxTreeVariable*)(child->item));
        return OK;
      }
      child = child->next;
    }
    type_data = type_data->base_type;
  }
  (*field) = NULL;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeData_m_find_meth(TypeData* self, String* name, SyntaxTreeFunction** method);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeData_m_find_meth = "TypeData.m-find-meth";
#define MR_FUNC_NAME _func_name_TypeData_m_find_meth
Returncode TypeData_m_find_meth(TypeData* self, String* name, SyntaxTreeFunction** method) {
  TypeData* type_data = self;
  while (true) {
    if (!(NULL != type_data)) break;
    ListNode* child = type_data->_base.functions->first;
    while (true) {
      if (!(NULL != child)) break;
      Bool _Bool101;
      CHECK(66, String_equal(((SyntaxTreeFunction*)(child->item))->name, name, &(_Bool101)) )
      if (_Bool101) {
        (*method) = ((SyntaxTreeFunction*)(child->item));
        return OK;
      }
      child = child->next;
    }
    type_data = type_data->base_type;
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
    CHECK(78, SyntaxTreeNode_m_find_type(&(self->_base._base._base), self->base_type_name, &(self->base_type)) )
    CHECK(79, TypeData_m_order_bases(self->base_type, ordered_list) )
  }
  CHECK(80, List_add(ordered_list, self) )
  /* init `self.dynamic-base-methods` and test override methods */
  if (self->is_dynamic) {
    self->dynamic_base_methods = malloc(sizeof(NameMap));
    if (self->dynamic_base_methods == NULL) RAISE(83)
    *self->dynamic_base_methods = (NameMap){NULL, NULL};
  }
  ListNode* child = self->_base.functions->first;
  while (true) {
    if (!(NULL != child)) break;
    SyntaxTreeFunction* method = NULL;
    CHECK(88, TypeData_m_find_meth(self->base_type, ((SyntaxTreeFunction*)(child->item))->name, &(method)) )
    if (NULL != method) {
      CHECK(90, SyntaxTreeFunction_m_compare(((SyntaxTreeFunction*)(child->item)), method) )
    }
    else {
      if (((SyntaxTreeFunction*)(child->item))->is_dynamic) {
        CHECK(92, NameMap_add(self->dynamic_base_methods, ((SyntaxTreeFunction*)(child->item))->name, child->item) )
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
  CHECK(99, write(&(String){17, 16, "\ntypedef struct "}) )
  CHECK(100, write_cname(self->name) )
  CHECK(101, write(&(String){2, 1, " "}) )
  CHECK(102, write_cname(self->name) )
  CHECK(103, write(&(String){3, 2, ";\n"}) )
  if (self->is_dynamic) {
    CHECK(105, write(&(String){17, 16, "\ntypedef struct "}) )
    CHECK(106, write_cname(self->name) )
    CHECK(107, write(&(String){10, 9, "_Dynamic "}) )
    CHECK(108, write_cname(self->name) )
    CHECK(109, write(&(String){11, 10, "_Dynamic;\n"}) )
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
  CHECK(118, write(&(String){8, 7, "struct "}) )
  CHECK(119, write_cname(self->name) )
  CHECK(120, write(&(String){4, 3, " {\n"}) )
  self->_base._base.indentation_spaces = 2;
  if (NULL != self->base_type) {
    CHECK(123, SyntaxTreeBranch_write_spaces(&(self->_base._base)) )
    CHECK(124, write_cname(self->base_type->name) )
    CHECK(125, write(&(String){9, 8, " _base;\n"}) )
  }
  CHECK(126, SyntaxTreeBranch_write_children(&(self->_base._base), self->_base._base.variables) )
  CHECK(127, write(&(String){3, 2, "};"}) )
  if (self->is_dynamic) {
    CHECK(129, write(&(String){10, 9, "\n\nstruct "}) )
    CHECK(130, write_cname(self->name) )
    CHECK(131, write(&(String){12, 11, "_Dynamic {\n"}) )
    if (NULL != self->base_type && self->base_type->is_dynamic) {
      CHECK(133, SyntaxTreeBranch_write_spaces(&(self->_base._base)) )
      CHECK(134, write_cname(self->base_type->name) )
      CHECK(135, write(&(String){17, 16, "_Dynamic _base;\n"}) )
    }
    NameMapNode* child = self->dynamic_base_methods->first;
    while (true) {
      if (!(NULL != child)) break;
      CHECK(139, SyntaxTreeBranch_write_spaces(&(self->_base._base)) )
      CHECK(140, SyntaxTreeFunction_write_pointer(((SyntaxTreeFunction*)(child->value))) )
      CHECK(141, write(&(String){3, 2, ";\n"}) )
      child = child->next;
    }
    CHECK(143, write(&(String){3, 2, "};"}) )
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
  CHECK(147, SyntaxTreeNamespace_write_functions_declaration(&(self->_base)) )
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
    CHECK(152, write(&(String){2, 1, "\n"}) )
    CHECK(153, write_cname(self->name) )
    CHECK(154, write(&(String){10, 9, "_Dynamic "}) )
    CHECK(155, write_cname(self->name) )
    CHECK(156, write(&(String){12, 11, "_dynamic = "}) )
    CHECK(157, TypeData_write_dynamic_init(self, self) )
    CHECK(158, write(&(String){3, 2, ";\n"}) )
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
  CHECK(161, write(&(String){2, 1, "{"}) )
  Bool not_first = NULL != type_data->base_type;
  if (not_first) {
    CHECK(164, TypeData_write_dynamic_init(self, type_data->base_type) )
  }
  NameMapNode* child = type_data->dynamic_base_methods->first;
  while (true) {
    if (!(NULL != child)) break;
    SyntaxTreeFunction* method = NULL;
    CHECK(169, TypeData_m_find_meth(self, ((SyntaxTreeFunction*)(child->value))->name, &(method)) )
    if (not_first) {
      CHECK(171, write(&(String){3, 2, ", "}) )
    }
    if (method != ((SyntaxTreeFunction*)(child->value))) {
      CHECK(173, write(&(String){7, 6, "(Func)"}) )
    }
    CHECK(174, write_cname(method->parent_type->name) )
    CHECK(175, write(&(String){2, 1, "_"}) )
    CHECK(176, write_cname(method->name) )
    not_first = true;
    child = child->next;
  }
  CHECK(179, write(&(String){2, 1, "}"}) )
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
  CHECK(182, SyntaxTreeBranch_write_children(&(self->_base._base), self->_base.functions) )
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
  RAISE(187)
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
  CHECK(191, TypeData_write_declaration(type_data) )
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
  CHECK(195, TypeData_write_methods_declaration(type_data) )
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
  CHECK(199, TypeData_write_global(type_data) )
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
  CHECK(203, TypeData_write_methods_body(type_data) )
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
  CHECK(219, TypeData_m_new_type_instance(self->type_data, &((*type_instance))) )
  CHECK(220, string_new_copy(self->name, &((*type_instance)->name)) )
  if (NULL != self->sub_type) {
    CHECK(222, TypeInstance_m_copy_new(self->sub_type, &((*type_instance)->sub_type)) )
  }
  if (NULL != self->arguments) {
    CHECK(224, FunctionArguments_m_copy_new(self->arguments, &((*type_instance)->arguments)) )
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
  String* _String102;
  CHECK(231, string_new_concat(ends, &(String){2, 1, "{"}, &(_String102)) )
  CHECK(231, read_new(_String102, &(self->name), &((*end))) )
  if ((*end) == '{') {
    Bool _Bool103;
    CHECK(234, String_equal(self->name, &(String){5, 4, "Func"}, &(_Bool103)) )
    if (_Bool103) {
      self->arguments = malloc(sizeof(FunctionArguments));
      if (self->arguments == NULL) RAISE(235)
      *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
      self->arguments->_base._dtl = FunctionArguments__dtl;
      ArgumentFactory* argument_factory = &(ArgumentFactory){ArgumentFactory__dtl};
      argument_factory->_dtl = ArgumentFactory__dtl;
      CHECK(237, FunctionArguments_parse(self->arguments, argument_factory, NULL, NULL, &((*end))) )
    }
    else {
      Bool _Bool104;
      CHECK(238, String_equal(self->name, &(String){7, 6, "String"}, &(_Bool104)) )
      if (NULL != var_node && _Bool104) {
        CHECK(239, parse_new_expression(&(String){2, 1, "}"}, &(var_node->_base), &(self->length), &((*end))) )
      }
      else {
        Bool has_sub_type = true;
        Bool _Bool105;
        CHECK(243, String_equal(self->name, &(String){6, 5, "Array"}, &(_Bool105)) )
        if (NULL != var_node && _Bool105) {
          CHECK(244, parse_new_expression(&(String){3, 2, ":}"}, &(var_node->_base), &(self->length), &((*end))) )
          if ((*end) != ':' && (*end) != '}') {
            CHECK(247, SyntaxTreeNode_m_syntax_error_c(node, &(String){18, 17, "expected \":\", got"}, (*end)) )
          }
          has_sub_type = (*end) == ':';
        }
        if (has_sub_type) {
          self->sub_type = malloc(sizeof(TypeInstance));
          if (self->sub_type == NULL) RAISE(250)
          *self->sub_type = (TypeInstance){NULL, NULL, NULL, NULL, NULL};
          CHECK(251, TypeInstance_parse(self->sub_type, &(String){2, 1, "}"}, node, var_node, &((*end))) )
        }
      }
    }
    if ((*end) != '}') {
      CHECK(253, SyntaxTreeNode_m_syntax_error_c(node, &(String){18, 17, "expected \"}\", got"}, (*end)) )
    }
    CHECK(254, read_c(&((*end))) )
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
  CHECK(257, TypeInstance_analyze_part(self, node, true, true) )
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
  CHECK(260, TypeInstance_analyze_part(self, node, true, false) )
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
  CHECK(263, TypeInstance_analyze_part(self, node, false, true) )
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
  if (check_types &&  ! (NULL != self->type_data)) {
    CHECK(268, SyntaxTreeNode_m_find_type(node, self->name, &(self->type_data)) )
  }
  if (check_length &&  NULL !=  self->length) {
    CHECK(270, SyntaxTreeNode_analyze_expression(node, self->length, glob->type_int) )
  }
  if (NULL != self->sub_type) {
    CHECK(272, TypeInstance_analyze_part(self->sub_type, node, check_types, check_length) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_m_check_assign_to(TypeInstance* self, TypeInstance* target, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_m_check_assign_to = "TypeInstance.m-check-assign-to";
#define MR_FUNC_NAME _func_name_TypeInstance_m_check_assign_to
Returncode TypeInstance_m_check_assign_to(TypeInstance* self, TypeInstance* target, SyntaxTreeNode* node) {
  if (!(NULL != self->type_data)) {
    CHECK(277, SyntaxTreeNode_m_syntax_error_msg(node, &(String){30, 29, "cannot assign void expression"}) )
  }
  if (!(NULL != target->type_data)) {
    CHECK(279, SyntaxTreeNode_m_syntax_error_msg(node, &(String){35, 34, "cannot assign into void expression"}) )
  }
  if (self->type_data == glob->type_empty &&  ! target->type_data->is_primitive) {
    return OK;
  }
  TypeData* base_type = self->type_data;
  while (true) {
    Bool _Bool106;
    CHECK(284, TypeData_m_is_same(target->type_data, base_type, &(_Bool106)) )
    if (!(!_Bool106)) break;
    if (!(NULL != base_type->base_type)) {
      CHECK(286, SyntaxTreeNode_m_syntax_error2(node, &(String){14, 13, "cannot assign"}, self->type_data->name, &(String){5, 4, "into"}, target->type_data->name) )
    }
    base_type = base_type->base_type;
  }
  
  CHECK(293, TypeInstance_m_check_sub_equal(self, target, node) )
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
  if (NULL != self->sub_type &&  NULL !=  self->sub_type->type_data) {
    if (NULL != other->sub_type &&  NULL !=  other->sub_type->type_data) {
      if (self->type_data != other->type_data) {
        CHECK(299, SyntaxTreeNode_m_syntax_error2(node, &(String){22, 21, "cannot assign subtype"}, self->sub_type->type_data->name, &(String){13, 12, "into subtype"}, other->sub_type->type_data->name) )
      }
      CHECK(304, TypeInstance_m_check_sub_equal(self->sub_type, other->sub_type, node) )
    }
    else {
      CHECK(306, SyntaxTreeNode_m_syntax_error2(node, &(String){22, 21, "cannot assign subtype"}, self->sub_type->type_data->name, &(String){26, 25, "into type with no subtype"}, other->type_data->name) )
    }
  }
  else {
    if (NULL != other->sub_type &&  NULL !=  other->sub_type->type_data) {
      CHECK(312, SyntaxTreeNode_m_syntax_error2(node, &(String){35, 34, "cannot assign type with no subtype"}, self->type_data->name, &(String){13, 12, "into subtype"}, other->sub_type->type_data->name) )
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
  CHECK(319, write(self->type_data->name) )
  if (NULL != self->sub_type) {
    CHECK(321, write(&(String){2, 1, "{"}) )
    CHECK(322, TypeInstance_write(self->sub_type) )
    CHECK(323, write(&(String){2, 1, "}"}) )
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
