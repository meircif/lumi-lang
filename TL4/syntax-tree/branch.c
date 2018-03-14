#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "syntax-tree/branch.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file17_name = "syntax-tree/branch.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file17_name

/* TL4 compiler - Syntax tree node branch */

/* A basic branch node in the syntax tree - a node with chldren nodes */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeBranch SyntaxTreeBranch;
#elif LUMI_STAGE == LUMI_TYPES(1)
struct SyntaxTreeBranch {
  SyntaxTreeNode _base;
  Int indentation_spaces;
  List* variables;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBranch_init(SyntaxTreeBranch* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_init = "SyntaxTreeBranch.init";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBranch_init
Returncode SyntaxTreeBranch_init(SyntaxTreeBranch* self) {
  self->variables = malloc(sizeof(List));
  if (self->variables == NULL) RAISE(9)
  *self->variables = (List){NULL, NULL};
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBranch_parse_block_children(SyntaxTreeBranch* self, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_block_children = "SyntaxTreeBranch.parse-block-children";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBranch_parse_block_children
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
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBranch_parse_children(SyntaxTreeBranch* self, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_children = "SyntaxTreeBranch.parse-children";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBranch_parse_children
Returncode SyntaxTreeBranch_parse_children(SyntaxTreeBranch* self, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end) {
  Int my_line_number = self->_base.line_number;
  while (true) {
    String* keyword = NULL;
    Int spaces = 0;
    CHECK(28, read_until(&(String){7, 6, " .([{?"}, true, &(keyword), &((*end)), &(spaces)) )
    /* ignore empty lines */
    if (keyword->length > 0 || (*end) != '\n') {
      CHECK(31, SyntaxTreeNode_set_location(&(self->_base)) )
      
      Bool _Bool81;
      CHECK(33, SyntaxTreeBranch_parse_if_comment(self, keyword, &((*end)), &(_Bool81)) )
      if (!_Bool81) {
        if (spaces > self->indentation_spaces) {
          CHECK(35, SyntaxTreeNode_m_syntax_error_indentation(&(self->_base), spaces, self->indentation_spaces) )
        }
        
        if (!(spaces == self->indentation_spaces && (*end) != EOF)) break;
        
        Bool _Bool82;
        CHECK(40, (self)->_base._dtl[5](self, keyword, parent_type, parent_block, &((*end)), &(_Bool82)) )
        if (!_Bool82) {
          CHECK(42, (self)->_base._dtl[6](self, keyword, &((*end))) )
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
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBranch_parse_if_comment(SyntaxTreeBranch* self, String* keyword, Char* end, Bool* is_parsed);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_if_comment = "SyntaxTreeBranch.parse-if-comment";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBranch_parse_if_comment
Returncode SyntaxTreeBranch_parse_if_comment(SyntaxTreeBranch* self, String* keyword, Char* end, Bool* is_parsed) {
  (*is_parsed) = true;
  Bool _Bool83;
  CHECK(54, String_equal(keyword, &(String){2, 1, ";"}, &(_Bool83)) )
  if (_Bool83 && (*end) == ' ') {
    String* text = NULL;
    Int _Int84;
    CHECK(56, read_until(&(String){1, 0, ""}, false, &(text), &((*end)), &(_Int84)) )
  }
  else {
    Bool _Bool85;
    CHECK(57, String_equal(keyword, &(String){4, 3, "~~~"}, &(_Bool85)) )
    if (_Bool85 && (*end) == ' ') {
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
        Char _Char86;
        CHECK(69, read_c(&(_Char86)) )
        if (_Char86 != ';') {
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
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBranch_parse_if_common(SyntaxTreeBranch* self, String* keyword, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, Bool* is_parsed);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_if_common = "SyntaxTreeBranch.parse-if-common";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBranch_parse_if_common
Returncode SyntaxTreeBranch_parse_if_common(SyntaxTreeBranch* self, String* keyword, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, Bool* is_parsed) {
  (*is_parsed) = (*end) == ' ';
  
  List* variables = self->variables;
  if (NULL != parent_block) {
    SyntaxTreeFunction* _SyntaxTreeFunction87;
    CHECK(91, (parent_block)->_base._base._dtl[8](parent_block, &(_SyntaxTreeFunction87)) )
    variables = _SyntaxTreeFunction87->_base._base.variables;
    if (NULL != glob->tested_module) {
      Bool _Bool88;
      CHECK(93, String_equal(glob->current_module->name, glob->tested_module, &(_Bool88)) )
      Bool _Bool89;
      CHECK(93, String_equal(keyword, &(String){5, 4, "else"}, &(_Bool89)) )
      Bool _Bool90;
      CHECK(93, String_equal(keyword, &(String){8, 7, "else-if"}, &(_Bool90)) )
      if (_Bool88 &&  ! _Bool89 &&  ! _Bool90) {
        SyntaxTreeCoverage* _SyntaxTreeCoverage91;
        CHECK(95, SyntaxTreeCoverage_init_new(NULL, parent_block, &(_SyntaxTreeCoverage91)) )
        CHECK(95, List_add(parent_block->code_nodes, &(_SyntaxTreeCoverage91->_base)) )
      }
    }
  }
  
  if (!(*is_parsed)) {
    return OK;
  }
  
  else {
    Bool _Bool92;
    CHECK(101, String_equal(keyword, &(String){4, 3, "var"}, &(_Bool92)) )
    if (_Bool92) {
      SyntaxTreeVariable* _SyntaxTreeVariable93;
      CHECK(102, SyntaxTreeVariable_parse_new(NULL, ACCESS_VAR, true, parent_type, parent_block, &((*end)), &(_SyntaxTreeVariable93)) )
      CHECK(102, List_add(variables, _SyntaxTreeVariable93) )
    }
    else {
      Bool _Bool94;
      CHECK(109, String_equal(keyword, &(String){5, 4, "user"}, &(_Bool94)) )
      if (_Bool94) {
        SyntaxTreeVariable* _SyntaxTreeVariable95;
        CHECK(110, SyntaxTreeVariable_parse_new(NULL, ACCESS_USER, false, parent_type, parent_block, &((*end)), &(_SyntaxTreeVariable95)) )
        CHECK(110, List_add(variables, _SyntaxTreeVariable95) )
      }
      else {
        Bool _Bool96;
        CHECK(117, String_equal(keyword, &(String){6, 5, "owner"}, &(_Bool96)) )
        if (_Bool96) {
          SyntaxTreeVariable* _SyntaxTreeVariable97;
          CHECK(118, SyntaxTreeVariable_parse_new(NULL, ACCESS_OWNER, false, parent_type, parent_block, &((*end)), &(_SyntaxTreeVariable97)) )
          CHECK(118, List_add(variables, _SyntaxTreeVariable97) )
          
        }
        else {
          (*is_parsed) = false;
        }
      }
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBranch_parse_child(SyntaxTreeBranch* self, String* keyword, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_child = "SyntaxTreeBranch.parse-child";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBranch_parse_child
Returncode SyntaxTreeBranch_parse_child(SyntaxTreeBranch* self, String* keyword, Char* end) {
  RAISE(130)
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBranch_find_variable(SyntaxTreeBranch* self, String* name, String* module_name, SyntaxTreeVariable** variable);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_find_variable = "SyntaxTreeBranch.find-variable";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBranch_find_variable
Returncode SyntaxTreeBranch_find_variable(SyntaxTreeBranch* self, String* name, String* module_name, SyntaxTreeVariable** variable) {
  CHECK(134, SyntaxTreeNode_find_variable(&(self->_base), name, module_name, &((*variable))) )
  if (NULL != (*variable)) {
    return OK;
  }
  (*variable) = NULL;
  ListNode* child = self->variables->first;
  while (true) {
    if (!(NULL != child)) break;
    CHECK(140, (((SyntaxTreeVariable*)(child->item)))->_base._base._dtl[6](((SyntaxTreeVariable*)(child->item)), name, NULL, &((*variable))) )
    if (!(!(NULL != (*variable)))) break;
    child = child->next;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBranch_link_types(SyntaxTreeBranch* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_link_types = "SyntaxTreeBranch.link-types";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBranch_link_types
Returncode SyntaxTreeBranch_link_types(SyntaxTreeBranch* self) {
  CHECK(144, SyntaxTreeNode_link_children_types(&(self->_base), self->variables) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBranch_analyze(SyntaxTreeBranch* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_analyze = "SyntaxTreeBranch.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBranch_analyze
Returncode SyntaxTreeBranch_analyze(SyntaxTreeBranch* self) {
  CHECK(147, SyntaxTreeNode_analyze_children(&(self->_base), self->variables) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBranch_write(SyntaxTreeBranch* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write = "SyntaxTreeBranch.write";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBranch_write
Returncode SyntaxTreeBranch_write(SyntaxTreeBranch* self) {
  CHECK(150, SyntaxTreeNode_write_children(&(self->_base), self->variables) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBranch_write_spaces(SyntaxTreeBranch* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write_spaces = "SyntaxTreeBranch.write-spaces";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBranch_write_spaces
Returncode SyntaxTreeBranch_write_spaces(SyntaxTreeBranch* self) {
  CHECK(153, write_spaces(self->indentation_spaces) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBranch_write_cleanup(SyntaxTreeBranch* self, TypeData* type_data);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write_cleanup = "SyntaxTreeBranch.write-cleanup";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBranch_write_cleanup
Returncode SyntaxTreeBranch_write_cleanup(SyntaxTreeBranch* self, TypeData* type_data) {
  ListNode* var_node = self->variables->last;
  while (true) {
    if (!(NULL != var_node)) break;
    if (!((SyntaxTreeVariable*)(var_node->item))->type_instance->type_data->is_primitive) {
      CHECK(160, SyntaxTreeBranch_write_variable_cleanup(self, var_node->item, type_data) )
    }
    var_node = var_node->prev;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBranch_write_variable_cleanup(SyntaxTreeBranch* self, SyntaxTreeVariable* variable, TypeData* type_data);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write_variable_cleanup = "SyntaxTreeBranch.write-variable-cleanup";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBranch_write_variable_cleanup
Returncode SyntaxTreeBranch_write_variable_cleanup(SyntaxTreeBranch* self, SyntaxTreeVariable* variable, TypeData* type_data) {
  TypeData* item_type_data = variable->type_instance->type_data;
  if (item_type_data == glob->type_array) {
    item_type_data = ((TypeInstance*)(variable->type_instance->parameters->first->item))->type_data;
  }
  if (variable->access == ACCESS_OWNER &&  ! item_type_data->is_primitive) {
    CHECK(169, SyntaxTreeBranch_write_owner_reference_cleanup(self, variable, type_data, item_type_data) )
  }
  else {
    if (NULL != type_data && variable->access == ACCESS_VAR) {
      CHECK(172, write(&(String){3, 2, "  "}) )
      CHECK(173, TypeData_write_cname(item_type_data) )
      CHECK(174, write(&(String){14, 13, "_Del(&(self->"}) )
      CHECK(175, write_cname(variable->name) )
      CHECK(176, write(&(String){5, 4, "));\n"}) )
      return OK;
    }
  }
  CHECK(178, write(&(String){8, 7, "  LUMI_"}) )
  if (variable->access == ACCESS_OWNER) {
    CHECK(180, write(&(String){7, 6, "owner_"}) )
  }
  CHECK(181, write(&(String){9, 8, "dec_ref("}) )
  if (NULL != type_data) {
    CHECK(183, write(&(String){7, 6, "self->"}) )
  }
  CHECK(184, write_cname(variable->name) )
  CHECK(185, write(&(String){11, 10, "_Refman);\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeBranch_write_owner_reference_cleanup(SyntaxTreeBranch* self, SyntaxTreeVariable* variable, TypeData* type_data, TypeData* item_type_data);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write_owner_reference_cleanup = "SyntaxTreeBranch.write-owner-reference-cleanup";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeBranch_write_owner_reference_cleanup
Returncode SyntaxTreeBranch_write_owner_reference_cleanup(SyntaxTreeBranch* self, SyntaxTreeVariable* variable, TypeData* type_data, TypeData* item_type_data) {
  CHECK(191, write(&(String){3, 2, "  "}) )
  if (variable->type_instance->type_data == type_data) {
    if (type_data->is_dynamic) {
      CHECK(194, write(&(String){5, 4, "DYN_"}) )
    }
    CHECK(195, write(&(String){14, 13, "SELF_REF_DEL("}) )
    CHECK(196, TypeData_write_cname(type_data) )
    CHECK(197, write(&(String){3, 2, ", "}) )
    if (type_data->is_dynamic) {
      TypeData* base_type = type_data;
      while (true) {
        if (!(NULL != base_type->base_type)) break;
        CHECK(202, write(&(String){7, 6, "_base."}) )
        base_type = base_type->base_type->type_data;
      }
      CHECK(204, write(&(String){4, 3, "_, "}) )
    }
    type_data = NULL;
  }
  else {
    if (variable->type_instance->type_data->is_dynamic) {
      CHECK(207, write(&(String){5, 4, "if ("}) )
      if (NULL != type_data) {
        CHECK(209, write(&(String){7, 6, "self->"}) )
      }
      CHECK(210, write_cname(variable->name) )
      CHECK(211, write(&(String){19, 18, "_Dynamic != NULL) "}) )
      if (NULL != type_data) {
        CHECK(213, write(&(String){7, 6, "self->"}) )
      }
      CHECK(214, write_cname(variable->name) )
      CHECK(215, write(&(String){11, 10, "_Dynamic->"}) )
      TypeData* base_data = item_type_data;
      while (true) {
        if (!(NULL != base_data->base_type)) break;
        base_data = base_data->base_type->type_data;
        if (!(base_data->is_dynamic)) break;
        CHECK(221, write(&(String){7, 6, "_base."}) )
      }
      CHECK(222, write(&(String){6, 5, "_del("}) )
    }
    else {
      if (variable->type_instance->type_data == glob->type_array) {
        CHECK(224, write(&(String){11, 10, "ARRAY_DEL("}) )
        CHECK(225, TypeData_write_cname(item_type_data) )
        CHECK(226, write(&(String){3, 2, ", "}) )
      }
      else {
        CHECK(228, TypeData_write_cname(item_type_data) )
        CHECK(229, write(&(String){6, 5, "_Del("}) )
      }
    }
  }
  if (NULL != type_data) {
    CHECK(231, write(&(String){7, 6, "self->"}) )
  }
  CHECK(232, write_cname(variable->name) )
  CHECK(233, write(&(String){2, 1, ")"}) )
  if (variable->type_instance->type_data != glob->type_array) {
    CHECK(235, write(&(String){2, 1, ";"}) )
  }
  CHECK(236, write(&(String){2, 1, "\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeBranch__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeBranch__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeBranch_link_types, (void*)SyntaxTreeBranch_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBranch_parse_child, (void*)SyntaxTreeBranch_find_variable};
#endif


/* A basic namespace node in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeNamespace SyntaxTreeNamespace;
#elif LUMI_STAGE == LUMI_TYPES(2)
struct SyntaxTreeNamespace {
  SyntaxTreeBranch _base;
  List* functions;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNamespace_init(SyntaxTreeNamespace* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_init = "SyntaxTreeNamespace.init";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNamespace_init
Returncode SyntaxTreeNamespace_init(SyntaxTreeNamespace* self) {
  CHECK(244, SyntaxTreeBranch_init(&(self->_base)) )
  self->functions = malloc(sizeof(List));
  if (self->functions == NULL) RAISE(245)
  *self->functions = (List){NULL, NULL};
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNamespace_parse_if_function(SyntaxTreeNamespace* self, String* keyword, TypeData* parent_type, Char* end, Bool* is_func);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_parse_if_function = "SyntaxTreeNamespace.parse-if-function";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNamespace_parse_if_function
Returncode SyntaxTreeNamespace_parse_if_function(SyntaxTreeNamespace* self, String* keyword, TypeData* parent_type, Char* end, Bool* is_func) {
  CHECK(250, String_equal(keyword, &(String){5, 4, "func"}, &((*is_func))) )
  if ((*is_func)) {
    if ((*end) != ' ') {
      CHECK(253, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base), &(String){33, 32, "expected space after \"func\", got"}, (*end)) )
    }
    SyntaxTreeFunction* _SyntaxTreeFunction98;
    CHECK(255, SyntaxTreeFunction_parse_new(NULL, parent_type, &((*end)), &(_SyntaxTreeFunction98)) )
    CHECK(255, List_add(self->functions, _SyntaxTreeFunction98) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNamespace_link_types(SyntaxTreeNamespace* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_link_types = "SyntaxTreeNamespace.link-types";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNamespace_link_types
Returncode SyntaxTreeNamespace_link_types(SyntaxTreeNamespace* self) {
  CHECK(259, SyntaxTreeBranch_link_types(&(self->_base)) )
  CHECK(260, SyntaxTreeNode_link_children_types(&(self->_base._base), self->functions) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNamespace_analyze(SyntaxTreeNamespace* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_analyze = "SyntaxTreeNamespace.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNamespace_analyze
Returncode SyntaxTreeNamespace_analyze(SyntaxTreeNamespace* self) {
  CHECK(263, SyntaxTreeBranch_analyze(&(self->_base)) )
  CHECK(264, SyntaxTreeNode_analyze_children(&(self->_base._base), self->functions) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeNamespace_write_functions_declaration(SyntaxTreeNamespace* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_write_functions_declaration = "SyntaxTreeNamespace.write-functions-declaration";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeNamespace_write_functions_declaration
Returncode SyntaxTreeNamespace_write_functions_declaration(SyntaxTreeNamespace* self) {
  ListNode* child = self->functions->first;
  while (true) {
    if (!(NULL != child)) break;
    CHECK(270, (((SyntaxTreeFunction*)(child->item)))->_base._base._base._dtl[11](((SyntaxTreeFunction*)(child->item))) )
    child = child->next;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeNamespace__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeNamespace__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeNamespace_link_types, (void*)SyntaxTreeNamespace_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBranch_parse_child, (void*)SyntaxTreeBranch_find_variable};
#endif

#undef LUMI_FILE_NAME

#ifndef LUMI_INCLUDES
#define LUMI_INCLUDES
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
#include "statement/enum.c"
#include "statement/error.c"
#include "statement/for.c"
#include "statement/function.c"
#include "statement/native.c"
#include "statement/test.c"
#include "statement/type.c"
#include "statement/variable.c"
#include "tl4-compiler.c"
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
