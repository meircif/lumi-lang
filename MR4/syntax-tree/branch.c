#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/branch.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file17_name = "syntax-tree/branch.3.mr";
#endif
#define MR_FILE_NAME _mr_file17_name

/* MR4 compiler - Syntax tree node branch */

/* A basic branch node in the syntax tree - a node with chldren nodes */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeBranch SyntaxTreeBranch;
#elif MR_STAGE == MR_TYPES(1)
struct SyntaxTreeBranch {
  SyntaxTreeNode _base;
  Int indentation_spaces;
  List* variables;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_init(SyntaxTreeBranch* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_init = "SyntaxTreeBranch.init";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_init
Returncode SyntaxTreeBranch_init(SyntaxTreeBranch* self) {
  self->variables = malloc(sizeof(List));
  if (self->variables == NULL) RAISE(9)
  *self->variables = (List){NULL, NULL};
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_parse_block_children(SyntaxTreeBranch* self, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_block_children = "SyntaxTreeBranch.parse-block-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_block_children
Returncode SyntaxTreeBranch_parse_block_children(SyntaxTreeBranch* self, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end) {
  if ((*end) != '\n') {
    CHECK(15, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){34, 33, "expected block in a new line, got"}, (*end)) )
  }
  CHECK(16, SyntaxTreeBranch_init(self) )
  CHECK(17, SyntaxTreeBranch_parse_children(self, parent_type, parent_block, &((*end))) )
  if ((*end) != EOF) {
    glob->save_input = true;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_parse_children(SyntaxTreeBranch* self, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_children = "SyntaxTreeBranch.parse-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_children
Returncode SyntaxTreeBranch_parse_children(SyntaxTreeBranch* self, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end) {
  Int my_line_number = self->_base.line_number;
  while (true) {
    String* keyword = NULL;
    Int spaces = 0;
    CHECK(28, read_until(&(String){7, 6, " .([{?"}, true, &(keyword), &((*end)), &(spaces)) )
    /* ignore empty lines */
    if (keyword->length > 0 || (*end) != '\n') {
      CHECK(31, SyntaxTreeNode_set_location(&(self->_base)) )
      
      Bool _Bool73;
      CHECK(33, SyntaxTreeBranch_parse_if_comment(self, keyword, &((*end)), &(_Bool73)) )
      if (!_Bool73) {
        if (spaces > self->indentation_spaces) {
          CHECK(35, SyntaxTreeNode_m_syntax_error_indentation(&(self->_base), spaces, self->indentation_spaces) )
        }
        
        if (!(spaces == self->indentation_spaces && (*end) != EOF)) break;
        
        Bool _Bool74;
        CHECK(40, SyntaxTreeBranch_parse_if_common(self, keyword, parent_type, parent_block, &((*end)), &(_Bool74)) )
        if (!_Bool74) {
          CHECK(42, (self)->_base._dtl[4](self, keyword, &((*end))) )
        }
      }
      
      if (!((*end) != EOF)) break;
      if (!glob->save_input && (*end) != '\n') {
        CHECK(46, SyntaxTreeNode_m_syntax_error_c(&(self->_base), &(String){35, 34, "expected new-line in line end, got"}, (*end)) )
      }
    }
  }
  
  self->_base.line_number = my_line_number;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_parse_if_comment(SyntaxTreeBranch* self, String* keyword, Char* end, Bool* is_parsed);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_if_comment = "SyntaxTreeBranch.parse-if-comment";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_if_comment
Returncode SyntaxTreeBranch_parse_if_comment(SyntaxTreeBranch* self, String* keyword, Char* end, Bool* is_parsed) {
  (*is_parsed) = true;
  Bool _Bool75;
  CHECK(54, String_equal(keyword, &(String){2, 1, ";"}, &(_Bool75)) )
  if (_Bool75 && (*end) == ' ') {
    String* text = NULL;
    Int _Int76;
    CHECK(56, read_until(&(String){1, 0, ""}, false, &(text), &((*end)), &(_Int76)) )
  }
  else {
    Bool _Bool77;
    CHECK(57, String_equal(keyword, &(String){4, 3, "~~~"}, &(_Bool77)) )
    if (_Bool77 && (*end) == ' ') {
      Int count = 0;
      while (true) {
        Char ch = '\0';
        CHECK(61, read_c(&(ch)) )
        if (ch == '~') {
          count += 1;
        }
        else {
          count = 0;
        }
        if (!(ch != EOF && count < 3)) break;
      }
      CHECK(67, read_c(&((*end))) )
    }
    else {
      if (keyword->length == 0 && (*end) == '[') {
        Char _Char78;
        CHECK(69, read_c(&(_Char78)) )
        if (_Char78 != ';') {
          CHECK(70, SyntaxTreeNode_m_syntax_error_msg(&(self->_base), &(String){15, 14, "unexpected \"[\""}) )
        }
        Char prev = '\0';
        while (true) {
          Char curr = '\0';
          CHECK(74, read_c(&(curr)) )
          if (!(curr != EOF && (curr != ']' || prev != ';'))) break;
          prev = curr;
        }
        CHECK(77, read_c(&((*end))) )
      }
      else {
        (*is_parsed) = false;
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_parse_if_common(SyntaxTreeBranch* self, String* keyword, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, Bool* is_parsed);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_if_common = "SyntaxTreeBranch.parse-if-common";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_if_common
Returncode SyntaxTreeBranch_parse_if_common(SyntaxTreeBranch* self, String* keyword, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, Bool* is_parsed) {
  (*is_parsed) = (*end) == ' ';
  List* variables = self->variables;
  if (NULL != parent_block) {
    SyntaxTreeFunction* _SyntaxTreeFunction79;
    CHECK(90, (parent_block)->_base._base._dtl[6](parent_block, &(_SyntaxTreeFunction79)) )
    variables = _SyntaxTreeFunction79->_base._base.variables;
  }
  
  if (!(*is_parsed)) {
    return OK;
  }
  else {
    Bool _Bool80;
    CHECK(95, String_equal(keyword, &(String){4, 3, "var"}, &(_Bool80)) )
    if (_Bool80) {
      SyntaxTreeVariable* _SyntaxTreeVariable81;
      CHECK(96, SyntaxTreeVariable_parse_new(NULL, ACCESS_VAR, true, parent_type, parent_block, &((*end)), &(_SyntaxTreeVariable81)) )
      CHECK(96, List_add(variables, _SyntaxTreeVariable81) )
    }
    else {
      Bool _Bool82;
      CHECK(103, String_equal(keyword, &(String){5, 4, "user"}, &(_Bool82)) )
      if (_Bool82) {
        SyntaxTreeVariable* _SyntaxTreeVariable83;
        CHECK(104, SyntaxTreeVariable_parse_new(NULL, ACCESS_USER, false, parent_type, parent_block, &((*end)), &(_SyntaxTreeVariable83)) )
        CHECK(104, List_add(variables, _SyntaxTreeVariable83) )
      }
      else {
        Bool _Bool84;
        CHECK(111, String_equal(keyword, &(String){6, 5, "owner"}, &(_Bool84)) )
        if (_Bool84) {
          SyntaxTreeVariable* _SyntaxTreeVariable85;
          CHECK(112, SyntaxTreeVariable_parse_new(NULL, ACCESS_OWNER, false, parent_type, parent_block, &((*end)), &(_SyntaxTreeVariable85)) )
          CHECK(112, List_add(variables, _SyntaxTreeVariable85) )
          
        }
        else {
          (*is_parsed) = false;
        }
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_parse_child(SyntaxTreeBranch* self, String* keyword, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_child = "SyntaxTreeBranch.parse-child";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_child
Returncode SyntaxTreeBranch_parse_child(SyntaxTreeBranch* self, String* keyword, Char* end) {
  RAISE(124)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_find_variable(SyntaxTreeBranch* self, String* name, SyntaxTreeVariable** variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_find_variable = "SyntaxTreeBranch.find-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_find_variable
Returncode SyntaxTreeBranch_find_variable(SyntaxTreeBranch* self, String* name, SyntaxTreeVariable** variable) {
  (*variable) = NULL;
  ListNode* child = self->variables->first;
  while (true) {
    if (!(NULL != child)) break;
    Bool _Bool86;
    CHECK(132, SyntaxTreeVariable_find_variable(((SyntaxTreeVariable*)(child->item)), name, &((*variable)), &(_Bool86)) )
    if (!(!_Bool86)) break;
    child = child->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_link_types(SyntaxTreeBranch* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_link_types = "SyntaxTreeBranch.link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_link_types
Returncode SyntaxTreeBranch_link_types(SyntaxTreeBranch* self) {
  CHECK(136, SyntaxTreeNode_link_children_types(&(self->_base), self->variables) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_analyze(SyntaxTreeBranch* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_analyze = "SyntaxTreeBranch.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_analyze
Returncode SyntaxTreeBranch_analyze(SyntaxTreeBranch* self) {
  CHECK(139, SyntaxTreeNode_analyze_children(&(self->_base), self->variables) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_write(SyntaxTreeBranch* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write = "SyntaxTreeBranch.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_write
Returncode SyntaxTreeBranch_write(SyntaxTreeBranch* self) {
  CHECK(142, SyntaxTreeNode_write_children(&(self->_base), self->variables) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_write_spaces(SyntaxTreeBranch* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write_spaces = "SyntaxTreeBranch.write-spaces";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_write_spaces
Returncode SyntaxTreeBranch_write_spaces(SyntaxTreeBranch* self) {
  CHECK(145, write_spaces(self->indentation_spaces) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_write_cleanup(SyntaxTreeBranch* self, TypeData* type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write_cleanup = "SyntaxTreeBranch.write-cleanup";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_write_cleanup
Returncode SyntaxTreeBranch_write_cleanup(SyntaxTreeBranch* self, TypeData* type_data) {
  ListNode* var_node = self->variables->last;
  while (true) {
    if (!(NULL != var_node)) break;
    if (!((SyntaxTreeVariable*)(var_node->item))->type_instance->type_data->is_primitive) {
      CHECK(152, SyntaxTreeBranch_write_variable_cleanup(self, var_node->item, type_data) )
    }
    var_node = var_node->prev;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_write_variable_cleanup(SyntaxTreeBranch* self, SyntaxTreeVariable* variable, TypeData* type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write_variable_cleanup = "SyntaxTreeBranch.write-variable-cleanup";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_write_variable_cleanup
Returncode SyntaxTreeBranch_write_variable_cleanup(SyntaxTreeBranch* self, SyntaxTreeVariable* variable, TypeData* type_data) {
  TypeData* item_type_data = variable->type_instance->type_data;
  if (item_type_data == &(glob->type_array->_base)) {
    item_type_data = ((TypeInstance*)(variable->type_instance->parameters->first->item))->type_data;
  }
  if (variable->access == ACCESS_OWNER &&  ! item_type_data->is_primitive) {
    CHECK(161, SyntaxTreeBranch_write_owner_reference_cleanup(self, variable, type_data, item_type_data) )
  }
  else {
    if (NULL != type_data && variable->access == ACCESS_VAR) {
      CHECK(164, write(&(String){3, 2, "  "}) )
      CHECK(165, write_cname(item_type_data->name) )
      CHECK(166, write(&(String){14, 13, "_Del(&(self->"}) )
      CHECK(167, write_cname(variable->name) )
      CHECK(168, write(&(String){5, 4, "));\n"}) )
      return OK;
    }
  }
  CHECK(170, write(&(String){6, 5, "  MR_"}) )
  if (variable->access == ACCESS_OWNER) {
    CHECK(172, write(&(String){7, 6, "owner_"}) )
  }
  CHECK(173, write(&(String){9, 8, "dec_ref("}) )
  if (NULL != type_data) {
    CHECK(175, write(&(String){7, 6, "self->"}) )
  }
  CHECK(176, write_cname(variable->name) )
  CHECK(177, write(&(String){11, 10, "_Refman);\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_write_owner_reference_cleanup(SyntaxTreeBranch* self, SyntaxTreeVariable* variable, TypeData* type_data, TypeData* item_type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write_owner_reference_cleanup = "SyntaxTreeBranch.write-owner-reference-cleanup";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_write_owner_reference_cleanup
Returncode SyntaxTreeBranch_write_owner_reference_cleanup(SyntaxTreeBranch* self, SyntaxTreeVariable* variable, TypeData* type_data, TypeData* item_type_data) {
  CHECK(183, write(&(String){3, 2, "  "}) )
  if (variable->type_instance->type_data == type_data) {
    if (type_data->is_dynamic) {
      CHECK(186, write(&(String){5, 4, "DYN_"}) )
    }
    CHECK(187, write(&(String){14, 13, "SELF_REF_DEL("}) )
    CHECK(188, write_cname(type_data->name) )
    CHECK(189, write(&(String){3, 2, ", "}) )
    if (type_data->is_dynamic) {
      TypeData* base_type = type_data;
      while (true) {
        if (!(NULL != base_type->base_type)) break;
        CHECK(194, write(&(String){7, 6, "_base."}) )
        base_type = base_type->base_type->type_data;
      }
      CHECK(196, write(&(String){4, 3, "_, "}) )
    }
    type_data = NULL;
  }
  else {
    if (variable->type_instance->type_data->is_dynamic) {
      CHECK(199, write(&(String){5, 4, "if ("}) )
      if (NULL != type_data) {
        CHECK(201, write(&(String){7, 6, "self->"}) )
      }
      CHECK(202, write_cname(variable->name) )
      CHECK(203, write(&(String){19, 18, "_Dynamic != NULL) "}) )
      if (NULL != type_data) {
        CHECK(205, write(&(String){7, 6, "self->"}) )
      }
      CHECK(206, write_cname(variable->name) )
      CHECK(207, write(&(String){11, 10, "_Dynamic->"}) )
      TypeData* base_data = item_type_data;
      while (true) {
        if (!(NULL != base_data->base_type)) break;
        base_data = base_data->base_type->type_data;
        if (!(base_data->is_dynamic)) break;
        CHECK(213, write(&(String){7, 6, "_base."}) )
      }
      CHECK(214, write(&(String){6, 5, "_del("}) )
    }
    else {
      if (variable->type_instance->type_data == &(glob->type_array->_base)) {
        CHECK(216, write(&(String){11, 10, "ARRAY_DEL("}) )
        CHECK(217, write_cname(item_type_data->name) )
        CHECK(218, write(&(String){3, 2, ", "}) )
      }
      else {
        CHECK(220, write_cname(item_type_data->name) )
        CHECK(221, write(&(String){6, 5, "_Del("}) )
      }
    }
  }
  if (NULL != type_data) {
    CHECK(223, write(&(String){7, 6, "self->"}) )
  }
  CHECK(224, write_cname(variable->name) )
  CHECK(225, write(&(String){2, 1, ")"}) )
  if (variable->type_instance->type_data != &(glob->type_array->_base)) {
    CHECK(227, write(&(String){2, 1, ";"}) )
  }
  CHECK(228, write(&(String){2, 1, "\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBranch__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBranch__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeBranch_link_types, (void*)SyntaxTreeBranch_analyze, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBranch_parse_child, (void*)SyntaxTreeBranch_find_variable};
#endif


/* A basic namespace node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeNamespace SyntaxTreeNamespace;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeNamespace {
  SyntaxTreeBranch _base;
  List* functions;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_init(SyntaxTreeNamespace* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_init = "SyntaxTreeNamespace.init";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_init
Returncode SyntaxTreeNamespace_init(SyntaxTreeNamespace* self) {
  CHECK(236, SyntaxTreeBranch_init(&(self->_base)) )
  self->functions = malloc(sizeof(List));
  if (self->functions == NULL) RAISE(237)
  *self->functions = (List){NULL, NULL};
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_parse_if_function(SyntaxTreeNamespace* self, String* keyword, TypeData* parent_type, Char* end, Bool* is_func);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_parse_if_function = "SyntaxTreeNamespace.parse-if-function";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_parse_if_function
Returncode SyntaxTreeNamespace_parse_if_function(SyntaxTreeNamespace* self, String* keyword, TypeData* parent_type, Char* end, Bool* is_func) {
  CHECK(242, String_equal(keyword, &(String){5, 4, "func"}, &((*is_func))) )
  if ((*is_func)) {
    if ((*end) != ' ') {
      CHECK(245, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){33, 32, "expected space after \"func\", got"}, (*end)) )
    }
    SyntaxTreeFunction* _SyntaxTreeFunction87;
    CHECK(247, SyntaxTreeFunction_parse_new(NULL, parent_type, &((*end)), &(_SyntaxTreeFunction87)) )
    CHECK(247, List_add(self->functions, _SyntaxTreeFunction87) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_find_function(SyntaxTreeNamespace* self, String* name, SyntaxTreeFunction** function);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_find_function = "SyntaxTreeNamespace.find-function";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_find_function
Returncode SyntaxTreeNamespace_find_function(SyntaxTreeNamespace* self, String* name, SyntaxTreeFunction** function) {
  ListNode* child = self->functions->first;
  while (true) {
    if (!(NULL != child)) break;
    Bool _Bool88;
    CHECK(254, String_equal(((SyntaxTreeFunction*)(child->item))->name, name, &(_Bool88)) )
    if (_Bool88) {
      (*function) = ((SyntaxTreeFunction*)(child->item));
      return OK;
    }
    child = child->next;
  }
  (*function) = NULL;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_link_types(SyntaxTreeNamespace* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_link_types = "SyntaxTreeNamespace.link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_link_types
Returncode SyntaxTreeNamespace_link_types(SyntaxTreeNamespace* self) {
  CHECK(261, SyntaxTreeBranch_link_types(&(self->_base)) )
  CHECK(262, SyntaxTreeNode_link_children_types(&(self->_base._base), self->functions) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_analyze(SyntaxTreeNamespace* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_analyze = "SyntaxTreeNamespace.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_analyze
Returncode SyntaxTreeNamespace_analyze(SyntaxTreeNamespace* self) {
  CHECK(265, SyntaxTreeBranch_analyze(&(self->_base)) )
  CHECK(266, SyntaxTreeNode_analyze_children(&(self->_base._base), self->functions) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_write_functions_declaration(SyntaxTreeNamespace* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_write_functions_declaration = "SyntaxTreeNamespace.write-functions-declaration";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_write_functions_declaration
Returncode SyntaxTreeNamespace_write_functions_declaration(SyntaxTreeNamespace* self) {
  ListNode* child = self->functions->first;
  while (true) {
    if (!(NULL != child)) break;
    CHECK(272, (((SyntaxTreeFunction*)(child->item)))->_base._base._base._dtl[9](((SyntaxTreeFunction*)(child->item))) )
    child = child->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeNamespace__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeNamespace__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeNamespace_link_types, (void*)SyntaxTreeNamespace_analyze, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBranch_parse_child, (void*)SyntaxTreeBranch_find_variable};
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
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "statement/error.c"
#include "statement/for.c"
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
