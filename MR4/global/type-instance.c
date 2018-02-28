#ifndef MR_MAINFILE
#define MR_MAINFILE "global/type-instance.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file7_name = "global/type-instance.3.mr";
#endif
#define MR_FILE_NAME _mr_file7_name

/* MR4 compiler - Type instance */

/* Specific usage of a type including the assigned subtypes and values */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeInstance TypeInstance;
#elif MR_STAGE == MR_TYPES(0)
struct TypeInstance {
  String* name;
  TypeData* type_data;
  List* parameters;
  Expression* length_owner;
  Expression* length;
  FunctionArguments* arguments;
/* Return a new deep-copy of self */};
#endif/* Return a new deep-copy of self */
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_copy_new(TypeInstance* self, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_copy_new = "TypeInstance.copy-new";
#define MR_FUNC_NAME _func_name_TypeInstance_copy_new
Returncode TypeInstance_copy_new(TypeInstance* self, TypeInstance** type_instance) {
  if (NULL != self) {
    (*type_instance) = malloc(sizeof(TypeInstance));
    if ((*type_instance) == NULL) RAISE(15)
    *(*type_instance) = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL};
    CHECK(16, TypeInstance_copy(self, (*type_instance)) )
  }
  else {
    (*type_instance) = NULL;
    
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_copy(TypeInstance* self, TypeInstance* other);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_copy = "TypeInstance.copy";
#define MR_FUNC_NAME _func_name_TypeInstance_copy
Returncode TypeInstance_copy(TypeInstance* self, TypeInstance* other) {
  other->type_data = self->type_data;
  if (NULL != other->name) {
    free(other->name);
  }
  CHECK(24, string_new_copy(self->name, &(other->name)) )
  other->length = self->length;
  if (NULL != self->parameters) {
    other->parameters = malloc(sizeof(List));
    if (other->parameters == NULL) RAISE(27)
    *other->parameters = (List){NULL, NULL};
    ListNode* node = self->parameters->first;
    while (true) {
      if (!(NULL != node)) break;
      TypeInstance* _TypeInstance12;
      CHECK(31, TypeInstance_copy_new(((TypeInstance*)(node->item)), &(_TypeInstance12)) )
      CHECK(31, List_add(other->parameters, _TypeInstance12) )
      node = node->next;
    }
  }
  if (NULL != self->arguments) {
    CHECK(34, FunctionArguments_copy_new(self->arguments, &(other->arguments)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_parse(TypeInstance* self, String* ends, SyntaxTreeNode* node, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_parse = "TypeInstance.parse";
#define MR_FUNC_NAME _func_name_TypeInstance_parse
Returncode TypeInstance_parse(TypeInstance* self, String* ends, SyntaxTreeNode* node, SyntaxTreeCode* code_node, Char* end) {
  String* name = NULL;
  String* _String13;
  CHECK(42, string_new_concat(ends, &(String){2, 1, "{"}, &(_String13)) )
  Int _Int14;
  CHECK(42, read_until(_String13, false, &(name), &((*end)), &(_Int14)) )
  CHECK(44, TypeInstance_parse_name(self, name, node, code_node, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_parse_name(TypeInstance* self, String* name, SyntaxTreeNode* node, SyntaxTreeCode* code_node, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_parse_name = "TypeInstance.parse-name";
#define MR_FUNC_NAME _func_name_TypeInstance_parse_name
Returncode TypeInstance_parse_name(TypeInstance* self, String* name, SyntaxTreeNode* node, SyntaxTreeCode* code_node, Char* end) {
  CHECK(51, string_new_copy(name, &(self->name)) )
  if ((*end) == '{') {
    Bool _Bool15;
    CHECK(53, String_equal(self->name, &(String){5, 4, "Func"}, &(_Bool15)) )
    if (_Bool15) {
      CHECK(54, read_c(&((*end))) )
      if ((*end) != '(') {
        CHECK(56, SyntaxTreeNode_m_syntax_error_c(node, &(String){39, 38, "expected \"(\" inside Function type, got"}, (*end)) )
      }
      self->arguments = malloc(sizeof(FunctionArguments));
      if (self->arguments == NULL) RAISE(58)
      *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
      self->arguments->_base._dtl = FunctionArguments__dtl;
      DeclarationArgumentFactory* argument_factory = &(DeclarationArgumentFactory){DeclarationArgumentFactory__dtl};
      argument_factory->_base._dtl = DeclarationArgumentFactory__dtl;
      CHECK(60, FunctionArguments_parse(self->arguments, &(argument_factory->_base), false, code_node, &((*end))) )
    }
    else {
      Bool _Bool16;
      CHECK(62, String_equal(self->name, &(String){7, 6, "String"}, &(_Bool16)) )
      if (NULL != code_node && _Bool16) {
        CHECK(63, parse_new_expression(&(String){2, 1, "}"}, code_node, &(self->length_owner), &((*end))) )
        self->length = self->length_owner;
      }
      else {
        Bool has_sub_type = true;
        Bool _Bool17;
        CHECK(68, String_equal(self->name, &(String){6, 5, "Array"}, &(_Bool17)) )
        Bool is_array = _Bool17;
        if (NULL != code_node && is_array) {
          CHECK(70, parse_new_expression(&(String){3, 2, ":}"}, code_node, &(self->length_owner), &((*end))) )
          self->length = self->length_owner;
          if ((*end) != ':' && (*end) != '}') {
            CHECK(74, SyntaxTreeNode_m_syntax_error_c(node, &(String){44, 43, "expected \":\" or \"} after array length\", got"}, (*end)) )
          }
          has_sub_type = (*end) == ':';
        }
        if (has_sub_type) {
          if (!is_array) {
            code_node = NULL;
          }
          self->parameters = malloc(sizeof(List));
          if (self->parameters == NULL) RAISE(81)
          *self->parameters = (List){NULL, NULL};
          while (true) {
            TypeInstance* sub_type = malloc(sizeof(TypeInstance));
            if (sub_type == NULL) RAISE(83)
            *sub_type = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL};
            CHECK(84, TypeInstance_parse(sub_type, &(String){3, 2, ":}"}, node, code_node, &((*end))) )
            CHECK(85, List_add(self->parameters, sub_type) )
            if (!((*end) == ':')) break;
            if (is_array) {
              CHECK(88, SyntaxTreeNode_m_syntax_error_msg(node, &(String){32, 31, "more than one subtype for array"}) )
            }
          }
        }
      }
    }
    if ((*end) != '}') {
      CHECK(90, SyntaxTreeNode_m_syntax_error_c(node, &(String){34, 33, "expected \"}\" after sub-types, got"}, (*end)) )
    }
    CHECK(92, read_c(&((*end))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_add_subtype_copy(TypeInstance* self, TypeData* type_data);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_add_subtype_copy = "TypeInstance.add-subtype-copy";
#define MR_FUNC_NAME _func_name_TypeInstance_add_subtype_copy
Returncode TypeInstance_add_subtype_copy(TypeInstance* self, TypeData* type_data) {
  if (!(NULL != self->parameters)) {
    self->parameters = malloc(sizeof(List));
    if (self->parameters == NULL) RAISE(96)
    *self->parameters = (List){NULL, NULL};
  }
  TypeInstance* _TypeInstance18;
  CHECK(97, TypeData_m_new_type_instance(type_data, &(_TypeInstance18)) )
  CHECK(97, List_add(self->parameters, _TypeInstance18) )
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
  CHECK(100, TypeInstance_analyze_part(self, node, true, true) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_link_types(TypeInstance* self, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_link_types = "TypeInstance.link-types";
#define MR_FUNC_NAME _func_name_TypeInstance_link_types
Returncode TypeInstance_link_types(TypeInstance* self, SyntaxTreeNode* node) {
  CHECK(103, TypeInstance_analyze_part(self, node, true, false) )
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
  CHECK(106, TypeInstance_analyze_part(self, node, false, true) )
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
      CHECK(112, SyntaxTreeNode_find_type(node, self->name, &(self->type_data)) )
    }
    if (NULL != self->arguments) {
      CHECK(114, (self->arguments)->_base._dtl[1](self->arguments) )
    }
  }
  if (check_length) {
    if (NULL != self->length) {
      CHECK(117, SyntaxTreeNode_analyze_expression(node, self->length, &(glob->type_int->_base)) )
    }
    if (NULL != self->arguments) {
      CHECK(119, (self->arguments)->_base._dtl[2](self->arguments) )
    }
  }
  if (NULL != self->parameters) {
    ListNode* sub_type = self->parameters->first;
    while (true) {
      if (!(NULL != sub_type)) break;
      CHECK(124, TypeInstance_analyze_part(((TypeInstance*)(sub_type->item)), node, check_types, check_length) )
      sub_type = sub_type->next;
    }
  }
  if (check_types) {
    CHECK(128, TypeInstance_check_parameters(self, node) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_check_parameters(TypeInstance* self, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_check_parameters = "TypeInstance.check-parameters";
#define MR_FUNC_NAME _func_name_TypeInstance_check_parameters
Returncode TypeInstance_check_parameters(TypeInstance* self, SyntaxTreeNode* node) {
  if (self->type_data == &(glob->type_array->_base)) {
    if (!(NULL != self->parameters)) {
      CHECK(133, SyntaxTreeNode_m_syntax_error_msg(node, &(String){26, 25, "missing subtype for array"}) )
    }
    if (((TypeInstance*)(self->parameters->first->item))->type_data == &(glob->type_array->_base)) {
      CHECK(135, SyntaxTreeNode_m_syntax_error_msg(node, &(String){44, 43, "multidimensional array not supported yet..."}) )
    }
  }
  else {
    if (NULL != self->parameters) {
      if (!(NULL != self->type_data->parameters)) {
        CHECK(139, SyntaxTreeNode_m_syntax_error(node, &(String){44, 43, "parameter given for type with no parameters"}, self->type_data->name) )
      }
      ListNode* sub_type = self->parameters->first;
      ListNode* dec_node = self->type_data->parameters->first;
      while (true) {
        if (!(NULL != sub_type)) break;
        if (!(NULL != dec_node)) {
          CHECK(147, SyntaxTreeNode_m_syntax_error(node, &(String){28, 27, "too many parameter for type"}, self->type_data->name) )
        }
        if (((TypeInstance*)(sub_type->item))->type_data->is_primitive) {
          CHECK(150, SyntaxTreeNode_m_syntax_error(node, &(String){37, 36, "unsupported primitive parameter type"}, ((TypeInstance*)(sub_type->item))->type_data->name) )
        }
        if (((TypeInstance*)(sub_type->item))->type_data == &(glob->type_array->_base)) {
          CHECK(154, SyntaxTreeNode_m_syntax_error_msg(node, &(String){39, 38, "array as parameter type is unsupported"}) )
        }
        sub_type = sub_type->next;
        dec_node = dec_node->next;
      }
    }
    else {
      if (self->type_data == &(glob->type_func->_base) &&  ! (NULL != self->arguments)) {
        CHECK(158, SyntaxTreeNode_m_syntax_error_msg(node, &(String){35, 34, "missing arguments in function type"}) )
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_check_assign_from(TypeInstance* self, Int access, SyntaxTreeNode* node, Expression** value, Expression** assignee);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_check_assign_from = "TypeInstance.check-assign-from";
#define MR_FUNC_NAME _func_name_TypeInstance_check_assign_from
Returncode TypeInstance_check_assign_from(TypeInstance* self, Int access, SyntaxTreeNode* node, Expression** value, Expression** assignee) {
  (*assignee) = (*value);
  Int bases = 0;
  CHECK(164, TypeInstance_check_assign_to((*value)->result_type, (*value)->access, self, access, node, &(bases)) )
  if (bases > 0) {
    CHECK(167, UpCastExpression_init_new(NULL, bases, &((*value))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_check_assign_to(TypeInstance* self, Int self_access, TypeInstance* target, Int target_access, SyntaxTreeNode* node, Int* bases);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_check_assign_to = "TypeInstance.check-assign-to";
#define MR_FUNC_NAME _func_name_TypeInstance_check_assign_to
Returncode TypeInstance_check_assign_to(TypeInstance* self, Int self_access, TypeInstance* target, Int target_access, SyntaxTreeNode* node, Int* bases) {
  (*bases) = 0;
  if (!(NULL != self)) {
    CHECK(177, SyntaxTreeNode_m_syntax_error_msg(node, &(String){30, 29, "cannot assign void expression"}) )
  }
  if (self->type_data == &(glob->type_empty->_base) && (!target->type_data->is_primitive || target->type_data == &(glob->type_func->_base))) {
    return OK;
  }
  if (target->type_data == &(glob->type_ref->_base) &&  ! self->type_data->is_primitive) {
    return OK;
  }
  if (target_access == ACCESS_OWNER) {
    if (self_access != ACCESS_OWNER) {
      if ((self_access) < 0 || (self_access) >= (glob->access_names)->length) RAISE(185)
      CHECK(185, SyntaxTreeNode_m_syntax_error(node, &(String){43, 42, "assigning into an owner a non-owner access"}, (&(((String*)((glob->access_names)->values))[self_access]))) )
    }
    if (self->type_data != target->type_data && self->type_data != &(glob->type_empty->_base) &&  ! target->type_data->is_primitive &&  ! target->type_data->is_dynamic) {
      CHECK(192, SyntaxTreeNode_m_syntax_error2(node, &(String){26, 25, "passing ownership of type"}, self->type_data->name, &(String){17, 16, "into static type"}, target->type_data->name) )
    }
  }
  if (self->type_data == &(glob->type_generic->_base) && target->type_data == &(glob->type_generic->_base)) {
    Bool _Bool19;
    CHECK(199, String_equal(self->name, target->name, &(_Bool19)) )
    if (!_Bool19) {
      CHECK(200, SyntaxTreeNode_m_syntax_error2(node, &(String){30, 29, "cannot assign generic subtype"}, self->name, &(String){31, 30, "into different generic subtype"}, target->name) )
    }
  }
  TypeInstance* self_type_instance = self;
  while (true) {
    Bool _Bool20;
    CHECK(207, TypeData_m_is_same(target->type_data, self_type_instance->type_data, &(_Bool20)) )
    if (!(!_Bool20)) break;
    if (!(NULL != self_type_instance->type_data->base_type)) {
      CHECK(209, SyntaxTreeNode_m_syntax_error2(node, &(String){14, 13, "cannot assign"}, self->type_data->name, &(String){5, 4, "into"}, target->type_data->name) )
    }
    self_type_instance = self_type_instance->type_data->base_type;
    (*bases) += 1;
  }
  
  if (NULL != self->arguments) {
    Bool _Bool21;
    CHECK(218, FunctionArguments_check_same_as(self->arguments, target->arguments, NULL, 0, &(_Bool21)) )
    if (_Bool21) {
      CHECK(220, SyntaxTreeNode_m_syntax_error_msg(node, &(String){16, 15, "too few outputs"}) )
    }
  }
  
  CHECK(222, TypeInstance_check_sub_equal(self_type_instance, target, node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_check_equal(TypeInstance* self, TypeInstance* other, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_check_equal = "TypeInstance.check-equal";
#define MR_FUNC_NAME _func_name_TypeInstance_check_equal
Returncode TypeInstance_check_equal(TypeInstance* self, TypeInstance* other, SyntaxTreeNode* node) {
  if (self->type_data != other->type_data) {
    CHECK(226, SyntaxTreeNode_m_syntax_error2(node, &(String){19, 18, "non matching types"}, self->type_data->name, &(String){4, 3, "and"}, other->type_data->name) )
  }
  CHECK(231, TypeInstance_check_sub_equal(self, other, node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_check_sub_equal(TypeInstance* self, TypeInstance* target, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_check_sub_equal = "TypeInstance.check-sub-equal";
#define MR_FUNC_NAME _func_name_TypeInstance_check_sub_equal
Returncode TypeInstance_check_sub_equal(TypeInstance* self, TypeInstance* target, SyntaxTreeNode* node) {
  if (!(NULL != target->parameters)) {
    return OK;
  }
  ListNode* target_sub_type = target->parameters->first;
  if (!(NULL != self->parameters)) {
    CHECK(238, SyntaxTreeNode_m_syntax_error2(node, &(String){19, 18, "cannot assign type"}, self->type_data->name, &(String){48, 47, "with no parameter into same type with parameter"}, ((TypeInstance*)(target_sub_type->item))->type_data->name) )
  }
  
  ListNode* my_sub_type = self->parameters->first;
  while (true) {
    if (!(NULL != target_sub_type)) break;
    if (!(NULL != my_sub_type)) {
      CHECK(248, SyntaxTreeNode_m_syntax_error2(node, &(String){19, 18, "cannot assign type"}, self->type_data->name, &(String){52, 51, "with parameters into same type with more parameters"}, ((TypeInstance*)(target_sub_type->item))->type_data->name) )
    }
    if (((TypeInstance*)(my_sub_type->item))->type_data != ((TypeInstance*)(target_sub_type->item))->type_data) {
      CHECK(254, SyntaxTreeNode_m_syntax_error2(node, &(String){22, 21, "non matching subtypes"}, ((TypeInstance*)(my_sub_type->item))->type_data->name, &(String){4, 3, "and"}, ((TypeInstance*)(target_sub_type->item))->type_data->name) )
    }
    CHECK(259, TypeInstance_check_sub_equal(((TypeInstance*)(my_sub_type->item)), target_sub_type->item, node) )
    my_sub_type = my_sub_type->next;
    target_sub_type = target_sub_type->next;
  }
  
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_check_sequence(TypeInstance* self, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_check_sequence = "TypeInstance.check-sequence";
#define MR_FUNC_NAME _func_name_TypeInstance_check_sequence
Returncode TypeInstance_check_sequence(TypeInstance* self, SyntaxTreeNode* node) {
  if ((self->type_data == &(glob->type_array->_base) || self->type_data == &(glob->type_string->_base)) &&  ! (NULL != self->length)) {
    CHECK(266, SyntaxTreeNode_m_syntax_error_msg(node, &(String){28, 27, "missing length for sequence"}) )
  }
  if (self->type_data == &(glob->type_array->_base) && ((TypeInstance*)(self->parameters->first->item))->type_data == &(glob->type_string->_base) &&  ! (NULL != ((TypeInstance*)(self->parameters->first->item))->length)) {
    CHECK(270, SyntaxTreeNode_m_syntax_error_msg(node, &(String){28, 27, "missing length for sequence"}) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_f_new_replace_params(TypeInstance* self, TypeInstance* instance_type, Int bases, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_f_new_replace_params = "TypeInstance.f-new-replace-params";
#define MR_FUNC_NAME _func_name_TypeInstance_f_new_replace_params
Returncode TypeInstance_f_new_replace_params(TypeInstance* self, TypeInstance* instance_type, Int bases, TypeInstance** type_instance) {
  CHECK(275, TypeInstance_copy_new(self, &((*type_instance))) )
  if (NULL != (*type_instance)) {
    CHECK(277, TypeInstance_f_replace_type_parameters((*type_instance), instance_type, bases) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_f_replace_type_parameters(TypeInstance* self, TypeInstance* instance_type, Int bases);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_f_replace_type_parameters = "TypeInstance.f-replace-type-parameters";
#define MR_FUNC_NAME _func_name_TypeInstance_f_replace_type_parameters
Returncode TypeInstance_f_replace_type_parameters(TypeInstance* self, TypeInstance* instance_type, Int bases) {
  if (!(NULL != instance_type)) {
    return OK;
  }
  if (bases > 0) {
    CHECK(284, TypeInstance_f_replace_type_parameters(self, instance_type->type_data->base_type, bases - 1) )
  }
  if (self->type_data == &(glob->type_generic->_base) &&  NULL !=  instance_type->parameters &&  NULL !=  instance_type->type_data->parameters) {
    ListNode* dec_node = instance_type->type_data->parameters->first;
    ListNode* inst_node = instance_type->parameters->first;
    while (true) {
      if (!(NULL != dec_node &&  NULL !=  inst_node)) break;
      Bool _Bool22;
      CHECK(292, String_equal(((String*)(dec_node->item)), self->name, &(_Bool22)) )
      if (_Bool22) {
        CHECK(293, TypeInstance_copy(((TypeInstance*)(inst_node->item)), self) )
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
      CHECK(301, TypeInstance_f_replace_type_parameters(((TypeInstance*)(node->item)), instance_type, bases) )
      node = node->next;
    }
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
