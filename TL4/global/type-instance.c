#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "global/type-instance.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file8_name = "global/type-instance.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file8_name

/* TL4 compiler - Type instance */

/* Specific usage of a type including the assigned subtypes and values */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct TypeInstance TypeInstance;
#elif LUMI_STAGE == LUMI_TYPES(0)
struct TypeInstance {
  String* name;
  String* module_name;
  TypeData* type_data;
  List* parameters;
  Expression* length_owner;
  Expression* length;
  FunctionArguments* arguments;
/* Return a new deep-copy of self */};
#endif/* Return a new deep-copy of self */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_copy_new(TypeInstance* self, TypeInstance** type_instance);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_copy_new = "TypeInstance.copy-new";
#define LUMI_FUNC_NAME _func_name_TypeInstance_copy_new
Returncode TypeInstance_copy_new(TypeInstance* self, TypeInstance** type_instance) {
  if (NULL != self) {
    (*type_instance) = malloc(sizeof(TypeInstance));
    if ((*type_instance) == NULL) RAISE(16)
    *(*type_instance) = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL, NULL};
    CHECK(17, TypeInstance_copy(self, (*type_instance)) )
  }
  else {
    (*type_instance) = NULL;
    
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_copy(TypeInstance* self, TypeInstance* other);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_copy = "TypeInstance.copy";
#define LUMI_FUNC_NAME _func_name_TypeInstance_copy
Returncode TypeInstance_copy(TypeInstance* self, TypeInstance* other) {
  other->type_data = self->type_data;
  if (NULL != other->name) {
    free(other->name);
  }
  CHECK(25, string_new_copy(self->name, &(other->name)) )
  if (NULL != self->module_name) {
    CHECK(27, string_new_copy(self->module_name, &(other->module_name)) )
  }
  other->length = self->length;
  if (NULL != self->parameters) {
    other->parameters = malloc(sizeof(List));
    if (other->parameters == NULL) RAISE(30)
    *other->parameters = (List){NULL, NULL};
    ListNode* node = self->parameters->first;
    while (true) {
      if (!(NULL != node)) break;
      TypeInstance* _TypeInstance15;
      CHECK(34, TypeInstance_copy_new(((TypeInstance*)(node->item)), &(_TypeInstance15)) )
      CHECK(34, List_add(other->parameters, _TypeInstance15) )
      node = node->next;
    }
  }
  if (NULL != self->arguments) {
    CHECK(37, FunctionArguments_copy_new(self->arguments, &(other->arguments)) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_parse(TypeInstance* self, String* ends, SyntaxTreeNode* node, SyntaxTreeCode* code_node, Int indentation_spaces, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_parse = "TypeInstance.parse";
#define LUMI_FUNC_NAME _func_name_TypeInstance_parse
Returncode TypeInstance_parse(TypeInstance* self, String* ends, SyntaxTreeNode* node, SyntaxTreeCode* code_node, Int indentation_spaces, Char* end) {
  String* name = NULL;
  String* _String16;
  CHECK(46, string_new_concat(ends, &(String){3, 2, ".{"}, &(_String16)) )
  Int _Int17;
  CHECK(46, read_until(_String16, false, &(name), &((*end)), &(_Int17)) )
  if ((*end) == '.') {
    CHECK(49, string_new_copy(name, &(self->module_name)) )
    String* _String18;
    CHECK(50, string_new_concat(ends, &(String){2, 1, "{"}, &(_String18)) )
    Int _Int19;
    CHECK(50, read_until(_String18, false, &(name), &((*end)), &(_Int19)) )
  }
  CHECK(52, TypeInstance_parse_name(self, name, node, code_node, indentation_spaces, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_parse_name(TypeInstance* self, String* name, SyntaxTreeNode* node, SyntaxTreeCode* code_node, Int indentation_spaces, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_parse_name = "TypeInstance.parse-name";
#define LUMI_FUNC_NAME _func_name_TypeInstance_parse_name
Returncode TypeInstance_parse_name(TypeInstance* self, String* name, SyntaxTreeNode* node, SyntaxTreeCode* code_node, Int indentation_spaces, Char* end) {
  CHECK(62, string_new_copy(name, &(self->name)) )
  if ((*end) == '{') {
    Bool _Bool20;
    CHECK(64, String_equal(self->name, &(String){5, 4, "Func"}, &(_Bool20)) )
    if (_Bool20) {
      CHECK(65, read_c(&((*end))) )
      if ((*end) != '(') {
        CHECK(67, SyntaxTreeNode_m_syntax_error_c(node, &(String){39, 38, "expected \"(\" inside Function type, got"}, (*end)) )
      }
      self->arguments = malloc(sizeof(FunctionArguments));
      if (self->arguments == NULL) RAISE(69)
      *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
      self->arguments->_base._dtl = FunctionArguments__dtl;
      DeclarationArgumentFactory* argument_factory = &(DeclarationArgumentFactory){DeclarationArgumentFactory__dtl};
      argument_factory->_base._dtl = DeclarationArgumentFactory__dtl;
      CHECK(71, FunctionArguments_parse(self->arguments, &(argument_factory->_base), false, code_node, indentation_spaces, &((*end))) )
    }
    else {
      Bool _Bool21;
      CHECK(77, String_equal(self->name, &(String){7, 6, "String"}, &(_Bool21)) )
      if (NULL != code_node && _Bool21) {
        CHECK(78, parse_new_expression(&(String){2, 1, "}"}, code_node, &(self->length_owner), &((*end))) )
        self->length = self->length_owner;
      }
      else {
        Bool has_sub_type = true;
        Bool _Bool22;
        CHECK(83, String_equal(self->name, &(String){6, 5, "Array"}, &(_Bool22)) )
        Bool is_array = _Bool22;
        if (NULL != code_node && is_array) {
          CHECK(85, parse_new_expression(&(String){3, 2, ":}"}, code_node, &(self->length_owner), &((*end))) )
          self->length = self->length_owner;
          if ((*end) != ':' && (*end) != '}') {
            CHECK(89, SyntaxTreeNode_m_syntax_error_c(node, &(String){44, 43, "expected \":\" or \"} after array length\", got"}, (*end)) )
          }
          has_sub_type = (*end) == ':';
        }
        if (has_sub_type) {
          if (!is_array) {
            code_node = NULL;
          }
          self->parameters = malloc(sizeof(List));
          if (self->parameters == NULL) RAISE(96)
          *self->parameters = (List){NULL, NULL};
          while (true) {
            TypeInstance* sub_type = malloc(sizeof(TypeInstance));
            if (sub_type == NULL) RAISE(98)
            *sub_type = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL, NULL};
            CHECK(99, TypeInstance_parse(sub_type, &(String){3, 2, ":}"}, node, code_node, indentation_spaces, &((*end))) )
            CHECK(105, List_add(self->parameters, sub_type) )
            if (!((*end) == ':')) break;
            if (is_array) {
              CHECK(108, SyntaxTreeNode_m_syntax_error_msg(node, &(String){32, 31, "more than one subtype for array"}) )
            }
          }
        }
      }
    }
    if ((*end) != '}') {
      CHECK(110, SyntaxTreeNode_m_syntax_error_c(node, &(String){34, 33, "expected \"}\" after sub-types, got"}, (*end)) )
    }
    CHECK(112, read_c(&((*end))) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_add_subtype_copy(TypeInstance* self, TypeData* type_data);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_add_subtype_copy = "TypeInstance.add-subtype-copy";
#define LUMI_FUNC_NAME _func_name_TypeInstance_add_subtype_copy
Returncode TypeInstance_add_subtype_copy(TypeInstance* self, TypeData* type_data) {
  if (!(NULL != self->parameters)) {
    self->parameters = malloc(sizeof(List));
    if (self->parameters == NULL) RAISE(116)
    *self->parameters = (List){NULL, NULL};
  }
  TypeInstance* _TypeInstance23;
  CHECK(117, TypeData_m_new_type_instance(type_data, &(_TypeInstance23)) )
  CHECK(117, List_add(self->parameters, _TypeInstance23) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_analyze(TypeInstance* self, SyntaxTreeNode* node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_analyze = "TypeInstance.analyze";
#define LUMI_FUNC_NAME _func_name_TypeInstance_analyze
Returncode TypeInstance_analyze(TypeInstance* self, SyntaxTreeNode* node) {
  CHECK(120, TypeInstance_analyze_part(self, node, true, true, false) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_link_types(TypeInstance* self, SyntaxTreeNode* node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_link_types = "TypeInstance.link-types";
#define LUMI_FUNC_NAME _func_name_TypeInstance_link_types
Returncode TypeInstance_link_types(TypeInstance* self, SyntaxTreeNode* node) {
  CHECK(123, TypeInstance_analyze_part(self, node, true, false, true) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_analyze_lengths(TypeInstance* self, SyntaxTreeNode* node, Bool constant_length);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_analyze_lengths = "TypeInstance.analyze-lengths";
#define LUMI_FUNC_NAME _func_name_TypeInstance_analyze_lengths
Returncode TypeInstance_analyze_lengths(TypeInstance* self, SyntaxTreeNode* node, Bool constant_length) {
  CHECK(126, TypeInstance_analyze_part(self, node, false, true, constant_length) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_analyze_part(TypeInstance* self, SyntaxTreeNode* node, Bool check_types, Bool check_length, Bool constant_length);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_analyze_part = "TypeInstance.analyze-part";
#define LUMI_FUNC_NAME _func_name_TypeInstance_analyze_part
Returncode TypeInstance_analyze_part(TypeInstance* self, SyntaxTreeNode* node, Bool check_types, Bool check_length, Bool constant_length) {
  if (check_types) {
    if (!(NULL != self->type_data)) {
      CHECK(135, SyntaxTreeNode_find_type(node, self->name, self->module_name, &(self->type_data)) )
    }
    if (NULL != self->arguments) {
      CHECK(138, (self->arguments)->_base._dtl[1](self->arguments) )
    }
  }
  if (check_length) {
    if (NULL != self->length) {
      CHECK(141, SyntaxTreeNode_analyze_expression(node, self->length, glob->type_int) )
      if (constant_length &&  ! self->length->constant) {
        CHECK(143, SyntaxTreeNode_m_syntax_error_msg(node, &(String){29, 28, "array length is not constant"}) )
      }
    }
    if (NULL != self->arguments) {
      CHECK(145, (self->arguments)->_base._dtl[2](self->arguments) )
    }
  }
  if (NULL != self->parameters) {
    ListNode* sub_type = self->parameters->first;
    while (true) {
      if (!(NULL != sub_type)) break;
      CHECK(150, TypeInstance_analyze_part(((TypeInstance*)(sub_type->item)), node, check_types, check_length, constant_length) )
      sub_type = sub_type->next;
    }
  }
  if (check_types) {
    CHECK(157, TypeInstance_check_parameters(self, node) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_check_parameters(TypeInstance* self, SyntaxTreeNode* node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_check_parameters = "TypeInstance.check-parameters";
#define LUMI_FUNC_NAME _func_name_TypeInstance_check_parameters
Returncode TypeInstance_check_parameters(TypeInstance* self, SyntaxTreeNode* node) {
  if (self->type_data == glob->type_array) {
    if (!(NULL != self->parameters)) {
      CHECK(162, SyntaxTreeNode_m_syntax_error_msg(node, &(String){26, 25, "missing subtype for array"}) )
    }
    if (((TypeInstance*)(self->parameters->first->item))->type_data == glob->type_array) {
      CHECK(164, SyntaxTreeNode_m_syntax_error_msg(node, &(String){44, 43, "multidimensional array not supported yet..."}) )
    }
  }
  else {
    if (NULL != self->parameters) {
      if (!(NULL != self->type_data->parameters)) {
        CHECK(168, SyntaxTreeNode_m_syntax_error(node, &(String){44, 43, "parameter given for type with no parameters"}, self->type_data->name) )
      }
      ListNode* sub_type = self->parameters->first;
      ListNode* dec_node = self->type_data->parameters->first;
      while (true) {
        if (!(NULL != sub_type)) break;
        if (!(NULL != dec_node)) {
          CHECK(176, SyntaxTreeNode_m_syntax_error(node, &(String){35, 34, "too many parameters given for type"}, self->type_data->name) )
        }
        if (((TypeInstance*)(sub_type->item))->type_data->is_primitive) {
          CHECK(180, SyntaxTreeNode_m_syntax_error(node, &(String){37, 36, "unsupported primitive parameter type"}, ((TypeInstance*)(sub_type->item))->type_data->name) )
        }
        if (((TypeInstance*)(sub_type->item))->type_data == glob->type_array) {
          CHECK(184, SyntaxTreeNode_m_syntax_error_msg(node, &(String){39, 38, "array as parameter type is unsupported"}) )
        }
        sub_type = sub_type->next;
        dec_node = dec_node->next;
      }
      if (NULL != dec_node) {
        CHECK(188, SyntaxTreeNode_m_syntax_error(node, &(String){33, 32, "too few parameter given for type"}, self->type_data->name) )
      }
    }
    else {
      if (self->type_data == glob->type_func &&  ! (NULL != self->arguments)) {
        CHECK(191, SyntaxTreeNode_m_syntax_error_msg(node, &(String){35, 34, "missing arguments in function type"}) )
      }
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_check_assign_from(TypeInstance* self, Int access, SyntaxTreeNode* node, Expression** value, Expression** assignee);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_check_assign_from = "TypeInstance.check-assign-from";
#define LUMI_FUNC_NAME _func_name_TypeInstance_check_assign_from
Returncode TypeInstance_check_assign_from(TypeInstance* self, Int access, SyntaxTreeNode* node, Expression** value, Expression** assignee) {
  (*assignee) = (*value);
  Int bases = 0;
  CHECK(197, TypeInstance_check_assign_to((*value)->result_type, (*value)->access, self, access, node, &(bases)) )
  if (bases > 0) {
    CHECK(200, UpCastExpression_init_new(NULL, bases, &((*value))) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_check_assign_to(TypeInstance* self, Int self_access, TypeInstance* target, Int target_access, SyntaxTreeNode* node, Int* bases);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_check_assign_to = "TypeInstance.check-assign-to";
#define LUMI_FUNC_NAME _func_name_TypeInstance_check_assign_to
Returncode TypeInstance_check_assign_to(TypeInstance* self, Int self_access, TypeInstance* target, Int target_access, SyntaxTreeNode* node, Int* bases) {
  (*bases) = 0;
  if (!(NULL != self)) {
    CHECK(210, SyntaxTreeNode_m_syntax_error_msg(node, &(String){30, 29, "cannot assign void expression"}) )
  }
  if (self->type_data == glob->type_empty && (!target->type_data->is_primitive || target->type_data == glob->type_func)) {
    return OK;
  }
  if (target->type_data == glob->type_ref &&  ! self->type_data->is_primitive) {
    return OK;
  }
  if (target_access == ACCESS_OWNER) {
    if (self_access != ACCESS_OWNER) {
      if ((self_access) < 0 || (self_access) >= (glob->access_names)->length) RAISE(218)
      CHECK(218, SyntaxTreeNode_m_syntax_error(node, &(String){43, 42, "assigning into an owner a non-owner access"}, (&(((String*)((glob->access_names)->values))[self_access]))) )
    }
    if (self->type_data != target->type_data && self->type_data != glob->type_empty &&  ! target->type_data->is_primitive &&  ! target->type_data->is_dynamic) {
      CHECK(225, SyntaxTreeNode_m_syntax_error2(node, &(String){26, 25, "passing ownership of type"}, self->type_data->name, &(String){17, 16, "into static type"}, target->type_data->name) )
    }
  }
  if (self->type_data == glob->type_generic && target->type_data == glob->type_generic) {
    Bool _Bool24;
    CHECK(232, String_equal(self->name, target->name, &(_Bool24)) )
    if (!_Bool24) {
      CHECK(233, SyntaxTreeNode_m_syntax_error2(node, &(String){30, 29, "cannot assign generic subtype"}, self->name, &(String){31, 30, "into different generic subtype"}, target->name) )
    }
  }
  TypeInstance* self_type_instance = self;
  TypeInstance* base_type_instance = NULL;
  while (true) {
    Bool _Bool25;
    CHECK(241, TypeData_m_is_same(target->type_data, self_type_instance->type_data, &(_Bool25)) )
    if (!(!_Bool25)) break;
    if (!(NULL != self_type_instance->type_data->base_type)) {
      CHECK(243, SyntaxTreeNode_m_syntax_error2(node, &(String){14, 13, "cannot assign"}, self->type_data->name, &(String){5, 4, "into"}, target->type_data->name) )
    }
    TypeInstance* prev_base_type_instance = base_type_instance;
    CHECK(249, TypeInstance_f_new_replace_params(self_type_instance->type_data->base_type, self_type_instance, 0, &(base_type_instance)) )
    self_type_instance = base_type_instance;
    (*bases) += 1;
  }
  
  if (NULL != self->arguments) {
    Bool _Bool26;
    CHECK(255, FunctionArguments_check_same_as(self->arguments, target->arguments, NULL, 0, &(_Bool26)) )
    if (_Bool26) {
      CHECK(257, SyntaxTreeNode_m_syntax_error_msg(node, &(String){16, 15, "too few outputs"}) )
    }
  }
  
  if (target->type_data->is_primitive || target->type_data == glob->type_array) {
    CHECK(260, TypeInstance_check_sub_equal(self_type_instance, target, node) )
  }
  else {
    CHECK(262, TypeInstance_check_sub_assign_to(self_type_instance, target, node) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_check_sub_assign_to(TypeInstance* self, TypeInstance* target, SyntaxTreeNode* node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_check_sub_assign_to = "TypeInstance.check-sub-assign-to";
#define LUMI_FUNC_NAME _func_name_TypeInstance_check_sub_assign_to
Returncode TypeInstance_check_sub_assign_to(TypeInstance* self, TypeInstance* target, SyntaxTreeNode* node) {
  if (!(NULL != target->parameters)) {
    return OK;
  }
  ListNode* target_sub_type = target->parameters->first;
  CHECK(269, TypeInstance_check_has_subytpe(self, target_sub_type, node) )
  ListNode* my_sub_type = self->parameters->first;
  while (true) {
    if (!(NULL != target_sub_type &&  NULL !=  my_sub_type)) break;
    Int _Int27;
    CHECK(273, TypeInstance_check_assign_to(((TypeInstance*)(my_sub_type->item)), ACCESS_VAR, target_sub_type->item, ACCESS_VAR, node, &(_Int27)) )
    my_sub_type = my_sub_type->next;
    target_sub_type = target_sub_type->next;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_check_has_subytpe(TypeInstance* self, ListNode* target_sub_type, SyntaxTreeNode* node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_check_has_subytpe = "TypeInstance.check-has-subytpe";
#define LUMI_FUNC_NAME _func_name_TypeInstance_check_has_subytpe
Returncode TypeInstance_check_has_subytpe(TypeInstance* self, ListNode* target_sub_type, SyntaxTreeNode* node) {
  if (!(NULL != self->parameters)) {
    CHECK(284, SyntaxTreeNode_m_syntax_error2(node, &(String){19, 18, "cannot assign type"}, self->type_data->name, &(String){48, 47, "with no parameter into same type with parameter"}, ((TypeInstance*)(target_sub_type->item))->type_data->name) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_check_equal(TypeInstance* self, TypeInstance* other, SyntaxTreeNode* node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_check_equal = "TypeInstance.check-equal";
#define LUMI_FUNC_NAME _func_name_TypeInstance_check_equal
Returncode TypeInstance_check_equal(TypeInstance* self, TypeInstance* other, SyntaxTreeNode* node) {
  if (self->type_data != other->type_data) {
    CHECK(292, SyntaxTreeNode_m_syntax_error2(node, &(String){19, 18, "non matching types"}, self->type_data->name, &(String){4, 3, "and"}, other->type_data->name) )
  }
  CHECK(297, TypeInstance_check_sub_equal(self, other, node) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_check_sub_equal(TypeInstance* self, TypeInstance* target, SyntaxTreeNode* node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_check_sub_equal = "TypeInstance.check-sub-equal";
#define LUMI_FUNC_NAME _func_name_TypeInstance_check_sub_equal
Returncode TypeInstance_check_sub_equal(TypeInstance* self, TypeInstance* target, SyntaxTreeNode* node) {
  if (!(NULL != target->parameters)) {
    return OK;
  }
  ListNode* target_sub_type = target->parameters->first;
  CHECK(303, TypeInstance_check_has_subytpe(self, target_sub_type, node) )
  ListNode* my_sub_type = self->parameters->first;
  while (true) {
    if (!(NULL != target_sub_type &&  NULL !=  my_sub_type)) break;
    if (((TypeInstance*)(my_sub_type->item))->type_data != ((TypeInstance*)(target_sub_type->item))->type_data) {
      CHECK(308, SyntaxTreeNode_m_syntax_error2(node, &(String){22, 21, "non matching subtypes"}, ((TypeInstance*)(my_sub_type->item))->type_data->name, &(String){4, 3, "and"}, ((TypeInstance*)(target_sub_type->item))->type_data->name) )
    }
    CHECK(313, TypeInstance_check_sub_equal(((TypeInstance*)(my_sub_type->item)), target_sub_type->item, node) )
    my_sub_type = my_sub_type->next;
    target_sub_type = target_sub_type->next;
  }
  
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_check_sequence(TypeInstance* self, SyntaxTreeNode* node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_check_sequence = "TypeInstance.check-sequence";
#define LUMI_FUNC_NAME _func_name_TypeInstance_check_sequence
Returncode TypeInstance_check_sequence(TypeInstance* self, SyntaxTreeNode* node) {
  if ((self->type_data == glob->type_array || self->type_data == glob->type_string) &&  ! (NULL != self->length)) {
    CHECK(320, SyntaxTreeNode_m_syntax_error_msg(node, &(String){28, 27, "missing length for sequence"}) )
  }
  if (self->type_data == glob->type_array && ((TypeInstance*)(self->parameters->first->item))->type_data == glob->type_string &&  ! (NULL != ((TypeInstance*)(self->parameters->first->item))->length)) {
    CHECK(324, SyntaxTreeNode_m_syntax_error_msg(node, &(String){28, 27, "missing length for sequence"}) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_f_new_replace_params(TypeInstance* self, TypeInstance* instance_type, Int bases, TypeInstance** type_instance);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_f_new_replace_params = "TypeInstance.f-new-replace-params";
#define LUMI_FUNC_NAME _func_name_TypeInstance_f_new_replace_params
Returncode TypeInstance_f_new_replace_params(TypeInstance* self, TypeInstance* instance_type, Int bases, TypeInstance** type_instance) {
  CHECK(329, TypeInstance_copy_new(self, &((*type_instance))) )
  if (NULL != (*type_instance)) {
    CHECK(331, TypeInstance_f_replace_type_parameters((*type_instance), instance_type, bases) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_f_replace_type_parameters(TypeInstance* self, TypeInstance* instance_type, Int bases);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_f_replace_type_parameters = "TypeInstance.f-replace-type-parameters";
#define LUMI_FUNC_NAME _func_name_TypeInstance_f_replace_type_parameters
Returncode TypeInstance_f_replace_type_parameters(TypeInstance* self, TypeInstance* instance_type, Int bases) {
  if (!(NULL != instance_type)) {
    return OK;
  }
  if (bases > 0) {
    TypeInstance* base_type = NULL;
    CHECK(339, TypeInstance_f_new_replace_params(instance_type->type_data->base_type, instance_type, bases - 1, &(base_type)) )
    CHECK(341, TypeInstance_f_replace_type_parameters(self, base_type, bases - 1) )
    free(base_type);
  }
  if (self->type_data == glob->type_generic &&  NULL !=  instance_type->parameters &&  NULL !=  instance_type->type_data->parameters) {
    ListNode* dec_node = instance_type->type_data->parameters->first;
    ListNode* inst_node = instance_type->parameters->first;
    while (true) {
      if (!(NULL != dec_node &&  NULL !=  inst_node)) break;
      Bool _Bool28;
      CHECK(349, String_equal(((String*)(dec_node->item)), self->name, &(_Bool28)) )
      if (_Bool28) {
        CHECK(350, TypeInstance_copy(((TypeInstance*)(inst_node->item)), self) )
        if (!(false)) break;
      }
      dec_node = dec_node->next;
      inst_node = inst_node->next;
    }
  }
  if (NULL != self->parameters) {
    ListNode* node = self->parameters->first;
    while (true) {
      if (!(NULL != node)) break;
      CHECK(358, TypeInstance_f_replace_type_parameters(((TypeInstance*)(node->item)), instance_type, bases) )
      node = node->next;
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
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
#include "syntax-tree/code-flow.c"
#include "syntax-tree/code.c"
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
