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
      TypeInstance* _TypeInstance11;
      CHECK(34, TypeInstance_copy_new(((TypeInstance*)(node->item)), &(_TypeInstance11)) )
      CHECK(34, List_add(other->parameters, _TypeInstance11) )
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
Returncode TypeInstance_parse(TypeInstance* self, String* ends, SyntaxTreeNode* node, SyntaxTreeCode* code_node, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_parse = "TypeInstance.parse";
#define LUMI_FUNC_NAME _func_name_TypeInstance_parse
Returncode TypeInstance_parse(TypeInstance* self, String* ends, SyntaxTreeNode* node, SyntaxTreeCode* code_node, Char* end) {
  String* name = NULL;
  String* _String12;
  CHECK(45, string_new_concat(ends, &(String){3, 2, ".{"}, &(_String12)) )
  Int _Int13;
  CHECK(45, read_until(_String12, false, &(name), &((*end)), &(_Int13)) )
  if ((*end) == '.') {
    CHECK(48, string_new_copy(name, &(self->module_name)) )
    String* _String14;
    CHECK(49, string_new_concat(ends, &(String){2, 1, "{"}, &(_String14)) )
    Int _Int15;
    CHECK(49, read_until(_String14, false, &(name), &((*end)), &(_Int15)) )
  }
  CHECK(51, TypeInstance_parse_name(self, name, node, code_node, &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode TypeInstance_parse_name(TypeInstance* self, String* name, SyntaxTreeNode* node, SyntaxTreeCode* code_node, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_TypeInstance_parse_name = "TypeInstance.parse-name";
#define LUMI_FUNC_NAME _func_name_TypeInstance_parse_name
Returncode TypeInstance_parse_name(TypeInstance* self, String* name, SyntaxTreeNode* node, SyntaxTreeCode* code_node, Char* end) {
  CHECK(58, string_new_copy(name, &(self->name)) )
  if ((*end) == '{') {
    Bool _Bool16;
    CHECK(60, String_equal(self->name, &(String){5, 4, "Func"}, &(_Bool16)) )
    if (_Bool16) {
      CHECK(61, read_c(&((*end))) )
      if ((*end) != '(') {
        CHECK(63, SyntaxTreeNode_m_syntax_error_c(node, &(String){39, 38, "expected \"(\" inside Function type, got"}, (*end)) )
      }
      self->arguments = malloc(sizeof(FunctionArguments));
      if (self->arguments == NULL) RAISE(65)
      *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
      self->arguments->_base._dtl = FunctionArguments__dtl;
      DeclarationArgumentFactory* argument_factory = &(DeclarationArgumentFactory){DeclarationArgumentFactory__dtl};
      argument_factory->_base._dtl = DeclarationArgumentFactory__dtl;
      CHECK(67, FunctionArguments_parse(self->arguments, &(argument_factory->_base), false, code_node, &((*end))) )
    }
    else {
      Bool _Bool17;
      CHECK(69, String_equal(self->name, &(String){7, 6, "String"}, &(_Bool17)) )
      if (NULL != code_node && _Bool17) {
        CHECK(70, parse_new_expression(&(String){2, 1, "}"}, code_node, &(self->length_owner), &((*end))) )
        self->length = self->length_owner;
      }
      else {
        Bool has_sub_type = true;
        Bool _Bool18;
        CHECK(75, String_equal(self->name, &(String){6, 5, "Array"}, &(_Bool18)) )
        Bool is_array = _Bool18;
        if (NULL != code_node && is_array) {
          CHECK(77, parse_new_expression(&(String){3, 2, ":}"}, code_node, &(self->length_owner), &((*end))) )
          self->length = self->length_owner;
          if ((*end) != ':' && (*end) != '}') {
            CHECK(81, SyntaxTreeNode_m_syntax_error_c(node, &(String){44, 43, "expected \":\" or \"} after array length\", got"}, (*end)) )
          }
          has_sub_type = (*end) == ':';
        }
        if (has_sub_type) {
          if (!is_array) {
            code_node = NULL;
          }
          self->parameters = malloc(sizeof(List));
          if (self->parameters == NULL) RAISE(88)
          *self->parameters = (List){NULL, NULL};
          while (true) {
            TypeInstance* sub_type = malloc(sizeof(TypeInstance));
            if (sub_type == NULL) RAISE(90)
            *sub_type = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL, NULL};
            CHECK(91, TypeInstance_parse(sub_type, &(String){3, 2, ":}"}, node, code_node, &((*end))) )
            CHECK(92, List_add(self->parameters, sub_type) )
            if (!((*end) == ':')) break;
            if (is_array) {
              CHECK(95, SyntaxTreeNode_m_syntax_error_msg(node, &(String){32, 31, "more than one subtype for array"}) )
            }
          }
        }
      }
    }
    if ((*end) != '}') {
      CHECK(97, SyntaxTreeNode_m_syntax_error_c(node, &(String){34, 33, "expected \"}\" after sub-types, got"}, (*end)) )
    }
    CHECK(99, read_c(&((*end))) )
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
    if (self->parameters == NULL) RAISE(103)
    *self->parameters = (List){NULL, NULL};
  }
  TypeInstance* _TypeInstance19;
  CHECK(104, TypeData_m_new_type_instance(type_data, &(_TypeInstance19)) )
  CHECK(104, List_add(self->parameters, _TypeInstance19) )
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
  CHECK(107, TypeInstance_analyze_part(self, node, true, true, false) )
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
  CHECK(110, TypeInstance_analyze_part(self, node, true, false, true) )
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
  CHECK(113, TypeInstance_analyze_part(self, node, false, true, constant_length) )
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
      CHECK(122, SyntaxTreeNode_find_type(node, self->name, self->module_name, &(self->type_data)) )
    }
    if (NULL != self->arguments) {
      CHECK(125, (self->arguments)->_base._dtl[1](self->arguments) )
    }
  }
  if (check_length) {
    if (NULL != self->length) {
      CHECK(128, SyntaxTreeNode_analyze_expression(node, self->length, glob->type_int) )
      if (constant_length &&  ! self->length->constant) {
        CHECK(130, SyntaxTreeNode_m_syntax_error_msg(node, &(String){29, 28, "array length is not constant"}) )
      }
    }
    if (NULL != self->arguments) {
      CHECK(132, (self->arguments)->_base._dtl[2](self->arguments) )
    }
  }
  if (NULL != self->parameters) {
    ListNode* sub_type = self->parameters->first;
    while (true) {
      if (!(NULL != sub_type)) break;
      CHECK(137, TypeInstance_analyze_part(((TypeInstance*)(sub_type->item)), node, check_types, check_length, constant_length) )
      sub_type = sub_type->next;
    }
  }
  if (check_types) {
    CHECK(144, TypeInstance_check_parameters(self, node) )
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
      CHECK(149, SyntaxTreeNode_m_syntax_error_msg(node, &(String){26, 25, "missing subtype for array"}) )
    }
    if (((TypeInstance*)(self->parameters->first->item))->type_data == glob->type_array) {
      CHECK(151, SyntaxTreeNode_m_syntax_error_msg(node, &(String){44, 43, "multidimensional array not supported yet..."}) )
    }
  }
  else {
    if (NULL != self->parameters) {
      if (!(NULL != self->type_data->parameters)) {
        CHECK(155, SyntaxTreeNode_m_syntax_error(node, &(String){44, 43, "parameter given for type with no parameters"}, self->type_data->name) )
      }
      ListNode* sub_type = self->parameters->first;
      ListNode* dec_node = self->type_data->parameters->first;
      while (true) {
        if (!(NULL != sub_type)) break;
        if (!(NULL != dec_node)) {
          CHECK(163, SyntaxTreeNode_m_syntax_error(node, &(String){35, 34, "too many parameters given for type"}, self->type_data->name) )
        }
        if (((TypeInstance*)(sub_type->item))->type_data->is_primitive) {
          CHECK(167, SyntaxTreeNode_m_syntax_error(node, &(String){37, 36, "unsupported primitive parameter type"}, ((TypeInstance*)(sub_type->item))->type_data->name) )
        }
        if (((TypeInstance*)(sub_type->item))->type_data == glob->type_array) {
          CHECK(171, SyntaxTreeNode_m_syntax_error_msg(node, &(String){39, 38, "array as parameter type is unsupported"}) )
        }
        sub_type = sub_type->next;
        dec_node = dec_node->next;
      }
      if (NULL != dec_node) {
        CHECK(175, SyntaxTreeNode_m_syntax_error(node, &(String){33, 32, "too few parameter given for type"}, self->type_data->name) )
      }
    }
    else {
      if (self->type_data == glob->type_func &&  ! (NULL != self->arguments)) {
        CHECK(178, SyntaxTreeNode_m_syntax_error_msg(node, &(String){35, 34, "missing arguments in function type"}) )
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
  CHECK(184, TypeInstance_check_assign_to((*value)->result_type, (*value)->access, self, access, node, &(bases)) )
  if (bases > 0) {
    CHECK(187, UpCastExpression_init_new(NULL, bases, &((*value))) )
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
    CHECK(197, SyntaxTreeNode_m_syntax_error_msg(node, &(String){30, 29, "cannot assign void expression"}) )
  }
  if (self->type_data == glob->type_empty && (!target->type_data->is_primitive || target->type_data == glob->type_func)) {
    return OK;
  }
  if (target->type_data == glob->type_ref &&  ! self->type_data->is_primitive) {
    return OK;
  }
  if (target_access == ACCESS_OWNER) {
    if (self_access != ACCESS_OWNER) {
      if ((self_access) < 0 || (self_access) >= (glob->access_names)->length) RAISE(205)
      CHECK(205, SyntaxTreeNode_m_syntax_error(node, &(String){43, 42, "assigning into an owner a non-owner access"}, (&(((String*)((glob->access_names)->values))[self_access]))) )
    }
    if (self->type_data != target->type_data && self->type_data != glob->type_empty &&  ! target->type_data->is_primitive &&  ! target->type_data->is_dynamic) {
      CHECK(212, SyntaxTreeNode_m_syntax_error2(node, &(String){26, 25, "passing ownership of type"}, self->type_data->name, &(String){17, 16, "into static type"}, target->type_data->name) )
    }
  }
  if (self->type_data == glob->type_generic && target->type_data == glob->type_generic) {
    Bool _Bool20;
    CHECK(219, String_equal(self->name, target->name, &(_Bool20)) )
    if (!_Bool20) {
      CHECK(220, SyntaxTreeNode_m_syntax_error2(node, &(String){30, 29, "cannot assign generic subtype"}, self->name, &(String){31, 30, "into different generic subtype"}, target->name) )
    }
  }
  TypeInstance* self_type_instance = self;
  TypeInstance* base_type_instance = NULL;
  while (true) {
    Bool _Bool21;
    CHECK(228, TypeData_m_is_same(target->type_data, self_type_instance->type_data, &(_Bool21)) )
    if (!(!_Bool21)) break;
    if (!(NULL != self_type_instance->type_data->base_type)) {
      CHECK(230, SyntaxTreeNode_m_syntax_error2(node, &(String){14, 13, "cannot assign"}, self->type_data->name, &(String){5, 4, "into"}, target->type_data->name) )
    }
    TypeInstance* prev_base_type_instance = base_type_instance;
    CHECK(236, TypeInstance_f_new_replace_params(self_type_instance->type_data->base_type, self_type_instance, 0, &(base_type_instance)) )
    self_type_instance = base_type_instance;
    (*bases) += 1;
  }
  
  if (NULL != self->arguments) {
    Bool _Bool22;
    CHECK(242, FunctionArguments_check_same_as(self->arguments, target->arguments, NULL, 0, &(_Bool22)) )
    if (_Bool22) {
      CHECK(244, SyntaxTreeNode_m_syntax_error_msg(node, &(String){16, 15, "too few outputs"}) )
    }
  }
  
  if (target->type_data->is_primitive || target->type_data == glob->type_array) {
    CHECK(247, TypeInstance_check_sub_equal(self_type_instance, target, node) )
  }
  else {
    CHECK(249, TypeInstance_check_sub_assign_to(self_type_instance, target, node) )
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
  CHECK(256, TypeInstance_check_has_subytpe(self, target_sub_type, node) )
  ListNode* my_sub_type = self->parameters->first;
  while (true) {
    if (!(NULL != target_sub_type &&  NULL !=  my_sub_type)) break;
    Int _Int23;
    CHECK(260, TypeInstance_check_assign_to(((TypeInstance*)(my_sub_type->item)), ACCESS_VAR, target_sub_type->item, ACCESS_VAR, node, &(_Int23)) )
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
    CHECK(271, SyntaxTreeNode_m_syntax_error2(node, &(String){19, 18, "cannot assign type"}, self->type_data->name, &(String){48, 47, "with no parameter into same type with parameter"}, ((TypeInstance*)(target_sub_type->item))->type_data->name) )
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
    CHECK(279, SyntaxTreeNode_m_syntax_error2(node, &(String){19, 18, "non matching types"}, self->type_data->name, &(String){4, 3, "and"}, other->type_data->name) )
  }
  CHECK(284, TypeInstance_check_sub_equal(self, other, node) )
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
  CHECK(290, TypeInstance_check_has_subytpe(self, target_sub_type, node) )
  ListNode* my_sub_type = self->parameters->first;
  while (true) {
    if (!(NULL != target_sub_type &&  NULL !=  my_sub_type)) break;
    if (((TypeInstance*)(my_sub_type->item))->type_data != ((TypeInstance*)(target_sub_type->item))->type_data) {
      CHECK(295, SyntaxTreeNode_m_syntax_error2(node, &(String){22, 21, "non matching subtypes"}, ((TypeInstance*)(my_sub_type->item))->type_data->name, &(String){4, 3, "and"}, ((TypeInstance*)(target_sub_type->item))->type_data->name) )
    }
    CHECK(300, TypeInstance_check_sub_equal(((TypeInstance*)(my_sub_type->item)), target_sub_type->item, node) )
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
    CHECK(307, SyntaxTreeNode_m_syntax_error_msg(node, &(String){28, 27, "missing length for sequence"}) )
  }
  if (self->type_data == glob->type_array && ((TypeInstance*)(self->parameters->first->item))->type_data == glob->type_string &&  ! (NULL != ((TypeInstance*)(self->parameters->first->item))->length)) {
    CHECK(311, SyntaxTreeNode_m_syntax_error_msg(node, &(String){28, 27, "missing length for sequence"}) )
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
  CHECK(316, TypeInstance_copy_new(self, &((*type_instance))) )
  if (NULL != (*type_instance)) {
    CHECK(318, TypeInstance_f_replace_type_parameters((*type_instance), instance_type, bases) )
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
    CHECK(326, TypeInstance_f_new_replace_params(instance_type->type_data->base_type, instance_type, bases - 1, &(base_type)) )
    CHECK(328, TypeInstance_f_replace_type_parameters(self, base_type, bases - 1) )
    free(base_type);
  }
  if (self->type_data == glob->type_generic &&  NULL !=  instance_type->parameters &&  NULL !=  instance_type->type_data->parameters) {
    ListNode* dec_node = instance_type->type_data->parameters->first;
    ListNode* inst_node = instance_type->parameters->first;
    while (true) {
      if (!(NULL != dec_node &&  NULL !=  inst_node)) break;
      Bool _Bool24;
      CHECK(336, String_equal(((String*)(dec_node->item)), self->name, &(_Bool24)) )
      if (_Bool24) {
        CHECK(337, TypeInstance_copy(((TypeInstance*)(inst_node->item)), self) )
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
      CHECK(345, TypeInstance_f_replace_type_parameters(((TypeInstance*)(node->item)), instance_type, bases) )
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
