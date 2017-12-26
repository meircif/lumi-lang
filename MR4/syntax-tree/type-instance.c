#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/type-instance.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file25_name = "syntax-tree/type-instance.3.mr";
#endif
#define MR_FILE_NAME _mr_file25_name

/* MR4 compiler - Type instance */

/* Specific usage of a type including the assigned subtypes and values */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeInstance TypeInstance;
#elif MR_STAGE == MR_TYPES(0)
struct TypeInstance {
  String* name;
  TypeData* type_data;
  List* sub_types;
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
  CHECK(14, TypeInstance_f_new_replace_params(self, NULL, &((*type_instance))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_f_new_replace_params(TypeInstance* self, TypeInstance* instance_type, TypeInstance** type_instance);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_f_new_replace_params = "TypeInstance.f-new-replace-params";
#define MR_FUNC_NAME _func_name_TypeInstance_f_new_replace_params
Returncode TypeInstance_f_new_replace_params(TypeInstance* self, TypeInstance* instance_type, TypeInstance** type_instance) {
  if (!(NULL != self)) {
    (*type_instance) = NULL;
    return OK;
  }
  if (self->type_data == &(glob->type_subtype->_base) &&  NULL !=  instance_type &&  NULL !=  instance_type->sub_types &&  NULL !=  instance_type->type_data->sub_types) {
    ListNode* dec_node = instance_type->type_data->sub_types->first;
    ListNode* inst_node = instance_type->sub_types->first;
    while (true) {
      if (!(NULL != dec_node &&  NULL !=  inst_node)) break;
      Bool _Bool126;
      CHECK(27, String_equal(((String*)(dec_node->item)), self->name, &(_Bool126)) )
      if (_Bool126) {
        (*type_instance) = ((TypeInstance*)(inst_node->item));
        return OK;
      }
      dec_node = dec_node->next;
      inst_node = inst_node->next;
    }
  }
  CHECK(32, TypeData_m_new_type_instance(self->type_data, &((*type_instance))) )
  CHECK(33, string_new_copy(self->name, &((*type_instance)->name)) )
  (*type_instance)->length = self->length;
  if (NULL != self->sub_types) {
    (*type_instance)->sub_types = malloc(sizeof(List));
    if ((*type_instance)->sub_types == NULL) RAISE(36)
    *(*type_instance)->sub_types = (List){NULL, NULL};
    ListNode* node = self->sub_types->first;
    while (true) {
      if (!(NULL != node)) break;
      TypeInstance* _TypeInstance127;
      CHECK(40, TypeInstance_f_new_replace_params(((TypeInstance*)(node->item)), instance_type, &(_TypeInstance127)) )
      CHECK(40, List_add((*type_instance)->sub_types, _TypeInstance127) )
      node = node->next;
    }
  }
  if (NULL != self->arguments) {
    CHECK(44, FunctionArguments_copy_new(self->arguments, &((*type_instance)->arguments)) )
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
  String* _String128;
  CHECK(52, string_new_concat(ends, &(String){2, 1, "{"}, &(_String128)) )
  Int _Int129;
  CHECK(52, read_until(_String128, false, &(name), &((*end)), &(_Int129)) )
  CHECK(54, TypeInstance_parse_name(self, name, node, code_node, &((*end))) )
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
  CHECK(61, string_new_copy(name, &(self->name)) )
  if ((*end) == '{') {
    Bool _Bool130;
    CHECK(63, String_equal(self->name, &(String){5, 4, "Func"}, &(_Bool130)) )
    if (_Bool130) {
      CHECK(64, read_c(&((*end))) )
      if ((*end) != '(') {
        CHECK(66, SyntaxTreeNode_m_syntax_error_c(node, &(String){39, 38, "expected \"(\" inside Function type, got"}, (*end)) )
      }
      self->arguments = malloc(sizeof(FunctionArguments));
      if (self->arguments == NULL) RAISE(68)
      *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
      self->arguments->_base._dtl = FunctionArguments__dtl;
      DeclarationArgumentFactory* argument_factory = &(DeclarationArgumentFactory){DeclarationArgumentFactory__dtl};
      argument_factory->_base._dtl = DeclarationArgumentFactory__dtl;
      CHECK(70, FunctionArguments_parse(self->arguments, &(argument_factory->_base), false, code_node, &((*end))) )
    }
    else {
      Bool _Bool131;
      CHECK(72, String_equal(self->name, &(String){7, 6, "String"}, &(_Bool131)) )
      if (NULL != code_node && _Bool131) {
        CHECK(73, parse_new_expression(&(String){2, 1, "}"}, code_node, &(self->length_owner), &((*end))) )
        self->length = self->length_owner;
      }
      else {
        Bool has_sub_type = true;
        Bool _Bool132;
        CHECK(78, String_equal(self->name, &(String){6, 5, "Array"}, &(_Bool132)) )
        Bool is_array = _Bool132;
        if (NULL != code_node && is_array) {
          CHECK(80, parse_new_expression(&(String){3, 2, ":}"}, code_node, &(self->length_owner), &((*end))) )
          self->length = self->length_owner;
          if ((*end) != ':' && (*end) != '}') {
            CHECK(84, SyntaxTreeNode_m_syntax_error_c(node, &(String){44, 43, "expected \":\" or \"} after array length\", got"}, (*end)) )
          }
          has_sub_type = (*end) == ':';
        }
        if (has_sub_type) {
          if (!is_array) {
            code_node = NULL;
          }
          self->sub_types = malloc(sizeof(List));
          if (self->sub_types == NULL) RAISE(91)
          *self->sub_types = (List){NULL, NULL};
          while (true) {
            TypeInstance* sub_type = malloc(sizeof(TypeInstance));
            if (sub_type == NULL) RAISE(93)
            *sub_type = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL};
            CHECK(94, TypeInstance_parse(sub_type, &(String){3, 2, ":}"}, node, code_node, &((*end))) )
            CHECK(95, List_add(self->sub_types, sub_type) )
            if (!((*end) == ':')) break;
            if (is_array) {
              CHECK(98, SyntaxTreeNode_m_syntax_error_msg(node, &(String){32, 31, "more than one subtype for array"}) )
            }
          }
        }
      }
    }
    if ((*end) != '}') {
      CHECK(100, SyntaxTreeNode_m_syntax_error_c(node, &(String){34, 33, "expected \"}\" after sub-types, got"}, (*end)) )
    }
    CHECK(102, read_c(&((*end))) )
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
  if (!(NULL != self->sub_types)) {
    self->sub_types = malloc(sizeof(List));
    if (self->sub_types == NULL) RAISE(106)
    *self->sub_types = (List){NULL, NULL};
  }
  TypeInstance* _TypeInstance133;
  CHECK(107, TypeData_m_new_type_instance(type_data, &(_TypeInstance133)) )
  CHECK(107, List_add(self->sub_types, _TypeInstance133) )
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
  CHECK(110, TypeInstance_analyze_part(self, node, true, true) )
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
  CHECK(113, TypeInstance_analyze_part(self, node, true, false) )
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
  CHECK(116, TypeInstance_analyze_part(self, node, false, true) )
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
      CHECK(122, SyntaxTreeNode_find_type(node, self->name, &(self->type_data)) )
    }
    if (NULL != self->arguments) {
      CHECK(124, (self->arguments)->_base._dtl[1](self->arguments) )
    }
  }
  if (check_length) {
    if (NULL != self->length) {
      CHECK(127, SyntaxTreeNode_analyze_expression(node, self->length, &(glob->type_int->_base)) )
    }
    if (NULL != self->arguments) {
      CHECK(129, (self->arguments)->_base._dtl[2](self->arguments) )
    }
  }
  if (NULL != self->sub_types) {
    ListNode* sub_type = self->sub_types->first;
    while (true) {
      if (!(NULL != sub_type)) break;
      CHECK(134, TypeInstance_analyze_part(((TypeInstance*)(sub_type->item)), node, check_types, check_length) )
      sub_type = sub_type->next;
    }
  }
  if (check_types) {
    CHECK(138, TypeInstance_check_parameters(self, node) )
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
    if (!(NULL != self->sub_types)) {
      CHECK(143, SyntaxTreeNode_m_syntax_error_msg(node, &(String){26, 25, "missing subtype for array"}) )
    }
    if (((TypeInstance*)(self->sub_types->first->item))->type_data == &(glob->type_array->_base)) {
      CHECK(145, SyntaxTreeNode_m_syntax_error_msg(node, &(String){44, 43, "multidimensional array not supported yet..."}) )
    }
  }
  else {
    if (NULL != self->sub_types) {
      if (!(NULL != self->type_data->sub_types)) {
        CHECK(149, SyntaxTreeNode_m_syntax_error(node, &(String){44, 43, "parameter given for type with no parameters"}, self->type_data->name) )
      }
      ListNode* sub_type = self->sub_types->first;
      ListNode* dec_node = self->type_data->sub_types->first;
      while (true) {
        if (!(NULL != sub_type)) break;
        if (!(NULL != dec_node)) {
          CHECK(157, SyntaxTreeNode_m_syntax_error(node, &(String){28, 27, "too many parameter for type"}, self->type_data->name) )
        }
        if (((TypeInstance*)(sub_type->item))->type_data->is_primitive) {
          CHECK(160, SyntaxTreeNode_m_syntax_error(node, &(String){37, 36, "unsupported primitive parameter type"}, ((TypeInstance*)(sub_type->item))->type_data->name) )
        }
        sub_type = sub_type->next;
        dec_node = dec_node->next;
      }
    }
    else {
      if (self->type_data == &(glob->type_func->_base) &&  ! (NULL != self->arguments)) {
        CHECK(166, SyntaxTreeNode_m_syntax_error_msg(node, &(String){35, 34, "missing arguments in function type"}) )
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_check_assign_from(TypeInstance* self, SyntaxTreeNode* node, Expression** value);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_check_assign_from = "TypeInstance.check-assign-from";
#define MR_FUNC_NAME _func_name_TypeInstance_check_assign_from
Returncode TypeInstance_check_assign_from(TypeInstance* self, SyntaxTreeNode* node, Expression** value) {
  Int bases = 0;
  CHECK(171, TypeInstance_check_assign_to((*value)->result_type, self, node, &(bases)) )
  if (bases > 0) {
    CHECK(173, UpCastExpression_init_new(NULL, bases, &((*value))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_check_assign_to(TypeInstance* self, TypeInstance* target, SyntaxTreeNode* node, Int* bases);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_check_assign_to = "TypeInstance.check-assign-to";
#define MR_FUNC_NAME _func_name_TypeInstance_check_assign_to
Returncode TypeInstance_check_assign_to(TypeInstance* self, TypeInstance* target, SyntaxTreeNode* node, Int* bases) {
  (*bases) = 0;
  if (!(NULL != self)) {
    CHECK(179, SyntaxTreeNode_m_syntax_error_msg(node, &(String){30, 29, "cannot assign void expression"}) )
  }
  if (self->type_data == &(glob->type_empty->_base) && (!target->type_data->is_primitive || target->type_data == &(glob->type_func->_base))) {
    return OK;
  }
  if (self->type_data == &(glob->type_subtype->_base) && target->type_data == &(glob->type_subtype->_base)) {
    Bool _Bool134;
    CHECK(185, String_equal(self->name, target->name, &(_Bool134)) )
    if (!_Bool134) {
      CHECK(186, SyntaxTreeNode_m_syntax_error2(node, &(String){30, 29, "cannot assign generic subtype"}, self->name, &(String){31, 30, "into different generic subtype"}, target->name) )
    }
  }
  TypeData* base_type = self->type_data;
  while (true) {
    Bool _Bool135;
    CHECK(193, TypeData_m_is_same(target->type_data, base_type, &(_Bool135)) )
    if (!(!_Bool135)) break;
    if (!(NULL != base_type->base_type)) {
      CHECK(195, SyntaxTreeNode_m_syntax_error2(node, &(String){14, 13, "cannot assign"}, self->type_data->name, &(String){5, 4, "into"}, target->type_data->name) )
    }
    if (!(NULL != base_type->base_type)) break;
    base_type = base_type->base_type->type_data;
    (*bases) += 1;
  }
  
  if (NULL != self->arguments) {
    Bool _Bool136;
    CHECK(205, FunctionArguments_check_same_as(self->arguments, target->arguments, NULL, &(_Bool136)) )
    if (_Bool136) {
      CHECK(206, SyntaxTreeNode_m_syntax_error_msg(node, &(String){16, 15, "too few outputs"}) )
    }
  }
  
  CHECK(208, TypeInstance_check_sub_equal(self, target, node) )
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
    CHECK(212, SyntaxTreeNode_m_syntax_error2(node, &(String){19, 18, "non matching types"}, self->type_data->name, &(String){4, 3, "and"}, other->type_data->name) )
  }
  CHECK(217, TypeInstance_check_sub_equal(self, other, node) )
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
  if (!(NULL != target->sub_types)) {
    return OK;
  }
  ListNode* target_sub_type = target->sub_types->first;
  if (!(NULL != self->sub_types)) {
    CHECK(224, SyntaxTreeNode_m_syntax_error2(node, &(String){19, 18, "cannot assign type"}, self->type_data->name, &(String){48, 47, "with no parameter into same type with parameter"}, ((TypeInstance*)(target_sub_type->item))->type_data->name) )
  }
  
  ListNode* my_sub_type = self->sub_types->first;
  while (true) {
    if (!(NULL != target_sub_type)) break;
    if (!(NULL != my_sub_type)) {
      CHECK(234, SyntaxTreeNode_m_syntax_error2(node, &(String){19, 18, "cannot assign type"}, self->type_data->name, &(String){52, 51, "with parameters into same type with more parameters"}, ((TypeInstance*)(target_sub_type->item))->type_data->name) )
    }
    if (((TypeInstance*)(my_sub_type->item))->type_data != ((TypeInstance*)(target_sub_type->item))->type_data) {
      CHECK(240, SyntaxTreeNode_m_syntax_error2(node, &(String){22, 21, "non matching subtypes"}, ((TypeInstance*)(my_sub_type->item))->type_data->name, &(String){4, 3, "and"}, ((TypeInstance*)(target_sub_type->item))->type_data->name) )
    }
    CHECK(245, TypeInstance_check_sub_equal(((TypeInstance*)(my_sub_type->item)), target_sub_type->item, node) )
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
    CHECK(252, SyntaxTreeNode_m_syntax_error_msg(node, &(String){28, 27, "missing length for sequence"}) )
  }
  if (self->type_data == &(glob->type_array->_base) && ((TypeInstance*)(self->sub_types->first->item))->type_data == &(glob->type_string->_base) &&  ! (NULL != ((TypeInstance*)(self->sub_types->first->item))->length)) {
    CHECK(256, SyntaxTreeNode_m_syntax_error_msg(node, &(String){28, 27, "missing length for sequence"}) )
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
#include "syntax-tree/function.c"
#include "syntax-tree/native.c"
#include "syntax-tree/node.c"
#include "syntax-tree/root.c"
#include "syntax-tree/test.c"
#include "syntax-tree/type.c"
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
