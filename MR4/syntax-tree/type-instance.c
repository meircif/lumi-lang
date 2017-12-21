#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/type-instance.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file24_name = "syntax-tree/type-instance.3.mr";
#endif
#define MR_FILE_NAME _mr_file24_name

/* MR4 compiler - Type instance */

/* Specific usage of a type including the assigned subtypes and values */
#if MR_STAGE == MR_TYPEDEFS
typedef struct TypeInstance TypeInstance;
#elif MR_STAGE == MR_TYPES(0)
struct TypeInstance {
  String* name;
  TypeData* type_data;
  TypeInstance* sub_type;
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
  if (!(NULL != self)) {
    (*type_instance) = NULL;
    return OK;
  }
  CHECK(17, TypeData_m_new_type_instance(self->type_data, &((*type_instance))) )
  CHECK(18, string_new_copy(self->name, &((*type_instance)->name)) )
  (*type_instance)->length = self->length;
  if (NULL != self->sub_type) {
    CHECK(21, TypeInstance_copy_new(self->sub_type, &((*type_instance)->sub_type)) )
  }
  if (NULL != self->arguments) {
    CHECK(23, FunctionArguments_copy_new(self->arguments, &((*type_instance)->arguments)) )
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
  String* _String117;
  CHECK(31, string_new_concat(ends, &(String){2, 1, "{"}, &(_String117)) )
  Int _Int118;
  CHECK(31, read_until(_String117, false, &(name), &((*end)), &(_Int118)) )
  CHECK(33, TypeInstance_parse_name(self, name, node, code_node, &((*end))) )
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
  CHECK(40, string_new_copy(name, &(self->name)) )
  if ((*end) == '{') {
    Bool _Bool119;
    CHECK(42, String_equal(self->name, &(String){5, 4, "Func"}, &(_Bool119)) )
    if (_Bool119) {
      CHECK(43, read_c(&((*end))) )
      if ((*end) != '(') {
        CHECK(45, SyntaxTreeNode_m_syntax_error_c(node, &(String){39, 38, "expected \"(\" inside Function type, got"}, (*end)) )
      }
      self->arguments = malloc(sizeof(FunctionArguments));
      if (self->arguments == NULL) RAISE(47)
      *self->arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
      self->arguments->_base._dtl = FunctionArguments__dtl;
      DeclarationArgumentFactory* argument_factory = &(DeclarationArgumentFactory){DeclarationArgumentFactory__dtl};
      argument_factory->_base._dtl = DeclarationArgumentFactory__dtl;
      CHECK(49, FunctionArguments_parse(self->arguments, &(argument_factory->_base), code_node, &((*end))) )
    }
    else {
      Bool _Bool120;
      CHECK(50, String_equal(self->name, &(String){7, 6, "String"}, &(_Bool120)) )
      if (NULL != code_node && _Bool120) {
        CHECK(51, parse_new_expression(&(String){2, 1, "}"}, code_node, &(self->length_owner), &((*end))) )
        self->length = self->length_owner;
      }
      else {
        Bool has_sub_type = true;
        Bool _Bool121;
        CHECK(56, String_equal(self->name, &(String){6, 5, "Array"}, &(_Bool121)) )
        if (NULL != code_node && _Bool121) {
          CHECK(57, parse_new_expression(&(String){3, 2, ":}"}, code_node, &(self->length_owner), &((*end))) )
          self->length = self->length_owner;
          if ((*end) != ':' && (*end) != '}') {
            CHECK(61, SyntaxTreeNode_m_syntax_error_c(node, &(String){18, 17, "expected \":\", got"}, (*end)) )
          }
          has_sub_type = (*end) == ':';
        }
        if (has_sub_type) {
          self->sub_type = malloc(sizeof(TypeInstance));
          if (self->sub_type == NULL) RAISE(64)
          *self->sub_type = (TypeInstance){NULL, NULL, NULL, NULL, NULL, NULL};
          CHECK(65, TypeInstance_parse(self->sub_type, &(String){2, 1, "}"}, node, code_node, &((*end))) )
        }
      }
    }
    if ((*end) != '}') {
      CHECK(67, SyntaxTreeNode_m_syntax_error_c(node, &(String){18, 17, "expected \"}\", got"}, (*end)) )
    }
    CHECK(68, read_c(&((*end))) )
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
  CHECK(71, TypeInstance_analyze_part(self, node, true, true) )
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
  CHECK(74, TypeInstance_analyze_part(self, node, true, false) )
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
  CHECK(77, TypeInstance_analyze_part(self, node, false, true) )
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
      CHECK(83, SyntaxTreeNode_find_type(node, self->name, &(self->type_data)) )
    }
    if (NULL != self->arguments) {
      CHECK(85, (self->arguments)->_base._dtl[0](self->arguments) )
    }
  }
  if (check_length) {
    if (NULL != self->length) {
      CHECK(88, SyntaxTreeNode_analyze_expression(node, self->length, &(glob->type_int->_base)) )
    }
    if (NULL != self->arguments) {
      CHECK(90, (self->arguments)->_base._dtl[1](self->arguments) )
    }
  }
  if (NULL != self->sub_type) {
    CHECK(92, TypeInstance_analyze_part(self->sub_type, node, check_types, check_length) )
  }
  if (check_types) {
    if (self->type_data == &(glob->type_array->_base)) {
      if (!(NULL != self->sub_type)) {
        CHECK(96, SyntaxTreeNode_m_syntax_error_msg(node, &(String){26, 25, "missing subtype for array"}) )
      }
      if (self->sub_type->type_data == &(glob->type_array->_base)) {
        CHECK(98, SyntaxTreeNode_m_syntax_error_msg(node, &(String){44, 43, "multidimensional array not supported yet..."}) )
      }
    }
    else {
      if (self->type_data == &(glob->type_func->_base) &&  ! (NULL != self->arguments)) {
        CHECK(101, SyntaxTreeNode_m_syntax_error_msg(node, &(String){35, 34, "missing arguments in function type"}) )
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
  CHECK(106, TypeInstance_check_assign_to((*value)->result_type, self, node, &(bases)) )
  if (bases > 0) {
    CHECK(108, UpCastExpression_init_new(NULL, bases, &((*value))) )
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
    CHECK(114, SyntaxTreeNode_m_syntax_error_msg(node, &(String){30, 29, "cannot assign void expression"}) )
  }
  if (!(NULL != target)) {
    CHECK(116, SyntaxTreeNode_m_syntax_error_msg(node, &(String){35, 34, "cannot assign into void expression"}) )
  }
  if (self->type_data == &(glob->type_empty->_base) && (!target->type_data->is_primitive || target->type_data == &(glob->type_func->_base))) {
    return OK;
  }
  TypeData* base_type = self->type_data;
  while (true) {
    Bool _Bool122;
    CHECK(122, TypeData_m_is_same(target->type_data, base_type, &(_Bool122)) )
    if (!(!_Bool122)) break;
    if (!(NULL != base_type->base_type)) {
      CHECK(124, SyntaxTreeNode_m_syntax_error2(node, &(String){14, 13, "cannot assign"}, self->type_data->name, &(String){5, 4, "into"}, target->type_data->name) )
    }
    base_type = base_type->base_type;
    (*bases) += 1;
  }
  
  if (NULL != self->arguments) {
    Bool _Bool123;
    CHECK(133, FunctionArguments_check_same_as(self->arguments, target->arguments, &(_Bool123)) )
    if (_Bool123) {
      CHECK(134, SyntaxTreeNode_m_syntax_error_msg(node, &(String){16, 15, "too few outputs"}) )
    }
  }
  
  CHECK(136, TypeInstance_check_sub_equal(self, target, node) )
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
    CHECK(140, SyntaxTreeNode_m_syntax_error2(node, &(String){19, 18, "non matching types"}, self->type_data->name, &(String){4, 3, "and"}, other->type_data->name) )
  }
  CHECK(145, TypeInstance_check_sub_equal(self, other, node) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode TypeInstance_check_sub_equal(TypeInstance* self, TypeInstance* other, SyntaxTreeNode* node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_TypeInstance_check_sub_equal = "TypeInstance.check-sub-equal";
#define MR_FUNC_NAME _func_name_TypeInstance_check_sub_equal
Returncode TypeInstance_check_sub_equal(TypeInstance* self, TypeInstance* other, SyntaxTreeNode* node) {
  if (NULL != self->sub_type) {
    if (NULL != other->sub_type) {
      if (self->sub_type->type_data != other->sub_type->type_data) {
        CHECK(151, SyntaxTreeNode_m_syntax_error2(node, &(String){22, 21, "non matching subtypes"}, self->sub_type->type_data->name, &(String){4, 3, "and"}, other->sub_type->type_data->name) )
      }
      CHECK(156, TypeInstance_check_sub_equal(self->sub_type, other->sub_type, node) )
    }
    else {
      CHECK(158, SyntaxTreeNode_m_syntax_error2(node, &(String){22, 21, "non matching subtypes"}, self->sub_type->type_data->name, &(String){25, 24, "and type with no subtype"}, other->type_data->name) )
    }
  }
  else {
    if (NULL != other->sub_type) {
      CHECK(164, SyntaxTreeNode_m_syntax_error2(node, &(String){34, 33, "non matching type with no subtype"}, self->type_data->name, &(String){12, 11, "and subtype"}, other->sub_type->type_data->name) )
    }
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
    CHECK(173, SyntaxTreeNode_m_syntax_error_msg(node, &(String){28, 27, "missing length for sequence"}) )
  }
  if (self->type_data == &(glob->type_array->_base) && self->sub_type->type_data == &(glob->type_string->_base) &&  ! (NULL != self->sub_type->length)) {
    CHECK(177, SyntaxTreeNode_m_syntax_error_msg(node, &(String){28, 27, "missing length for sequence"}) )
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
