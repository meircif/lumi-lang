#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/node.c"
#define DEPTH 4
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file16_name = "syntax-tree/node.3.mr";
#endif
#define MR_FILE_NAME _mr_file16_name

/*  MR4 compiler - Syntax tree basic node types


 */

/* Basic node type for all syntax tree nodes */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeNode SyntaxTreeNode;
#elif MR_STAGE == MR_TYPES(0)
struct SyntaxTreeNode {
  Func* _dtl;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNode_write(SyntaxTreeNode* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNode_write = "SyntaxTreeNode.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeNode_write
Returncode SyntaxTreeNode_write(SyntaxTreeNode* self) {
  RAISE(9)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeNode__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeNode__dtl[] = {(void*)SyntaxTreeNode_write};
#endif


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
Returncode SyntaxTreeBranch_parse_children(SyntaxTreeBranch* self, SyntaxTreeType* parent_type, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_children = "SyntaxTreeBranch.parse-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_children
Returncode SyntaxTreeBranch_parse_children(SyntaxTreeBranch* self, SyntaxTreeType* parent_type, Char* end) {
  if ((*end) != '\n') {
    CHECK(19, f_syntax_error_c(&(String){34, 33, "expected block in a new line, got"}, (*end)) )
  }
  self->variables = malloc(sizeof(List));
  if (self->variables == NULL) RAISE(20)
  *self->variables = (List){NULL, NULL};
  while (true) {
    String* keyword = NULL;
    Int spaces = 0;
    CHECK(24, read_until(&(String){6, 5, " .([?"}, true, &(keyword), &((*end)), &(spaces)) )
    /* ignore empty lines */
    if (keyword->length > 0 || (*end) != '\n') {
      
      if (spaces > self->indentation_spaces) {
        String* expecte_num = &(String){32, 0, (char[32]){0}};
        CHECK(30, Int_str(self->indentation_spaces, expecte_num) )
        String* actual_num = &(String){32, 0, (char[32]){0}};
        CHECK(32, Int_str(spaces, actual_num) )
        CHECK(33, f_syntax_error2(&(String){30, 29, "indentation too big, expected"}, expecte_num, &(String){4, 3, "got"}, actual_num) )
      }
      
      if (!(spaces == self->indentation_spaces && (*end) != EOF)) break;
      
      Bool _Bool30;
      CHECK(41, SyntaxTreeBranch_parse_if_variable(self, keyword, parent_type, &((*end)), &(_Bool30)) )
      if (!_Bool30) {
        CHECK(42, (self)->_base._dtl[1](self, keyword, &((*end))) )
      }
      
      if (!((*end) != EOF)) break;
      if (!glob->save_input && (*end) != '\n') {
        /* TODO: is possible? */
        CHECK(47, f_syntax_error_c(&(String){35, 34, "expected new-line in line end, got"}, (*end)) )
      }
    }
  }
  
  glob->save_input = true;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_parse_if_variable(SyntaxTreeBranch* self, String* keyword, SyntaxTreeType* parent_type, Char* end, Bool* is_variable);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_parse_if_variable = "SyntaxTreeBranch.parse-if-variable";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_parse_if_variable
Returncode SyntaxTreeBranch_parse_if_variable(SyntaxTreeBranch* self, String* keyword, SyntaxTreeType* parent_type, Char* end, Bool* is_variable) {
  (*is_variable) = (*end) == ' ';
  if (!(*is_variable)) {
    return OK;
  }
  Bool _Bool31;
  CHECK(57, String_equal(keyword, &(String){4, 3, "var"}, &(_Bool31)) )
  if (_Bool31) {
    SyntaxTreeVariable* _SyntaxTreeVariable32;
    CHECK(58, SyntaxTreeVariable_parse_new(NULL, ACCESS_VAR, parent_type, &((*end)), &(_SyntaxTreeVariable32)) )
    CHECK(58, List_add(self->variables, _SyntaxTreeVariable32) )
  }
  else {
    Bool _Bool33;
    CHECK(60, String_equal(keyword, &(String){5, 4, "user"}, &(_Bool33)) )
    if (_Bool33) {
      SyntaxTreeVariable* _SyntaxTreeVariable34;
      CHECK(61, SyntaxTreeVariable_parse_new(NULL, ACCESS_USER, parent_type, &((*end)), &(_SyntaxTreeVariable34)) )
      CHECK(61, List_add(self->variables, _SyntaxTreeVariable34) )
    }
    else {
      Bool _Bool35;
      CHECK(63, String_equal(keyword, &(String){6, 5, "owner"}, &(_Bool35)) )
      if (_Bool35) {
        SyntaxTreeVariable* _SyntaxTreeVariable36;
        CHECK(64, SyntaxTreeVariable_parse_new(NULL, ACCESS_OWNER, parent_type, &((*end)), &(_SyntaxTreeVariable36)) )
        CHECK(64, List_add(self->variables, _SyntaxTreeVariable36) )
      }
      else {
        (*is_variable) = false;
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
  RAISE(70)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_write(SyntaxTreeBranch* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write = "SyntaxTreeBranch.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_write
Returncode SyntaxTreeBranch_write(SyntaxTreeBranch* self) {
  CHECK(73, SyntaxTreeBranch_write_children(self, self->variables) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBranch_write_children(SyntaxTreeBranch* self, List* child_list);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBranch_write_children = "SyntaxTreeBranch.write-children";
#define MR_FUNC_NAME _func_name_SyntaxTreeBranch_write_children
Returncode SyntaxTreeBranch_write_children(SyntaxTreeBranch* self, List* child_list) {
  ListNode* child = child_list->first;
  while (true) {
    if (!(NULL != child)) break;
    if (self->indentation_spaces > 0) {
      CHECK(80, write_spaces(self->indentation_spaces) )
    }
    else {
      CHECK(82, write(&(String){2, 1, "\n"}) )
    }
    CHECK(83, (((SyntaxTreeNode*)(child->item)))->_dtl[0](((SyntaxTreeNode*)(child->item))) )
    CHECK(84, write(&(String){2, 1, "\n"}) )
    child = child->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBranch__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBranch__dtl[] = {(void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBranch_parse_child};
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
  self->functions = malloc(sizeof(List));
  if (self->functions == NULL) RAISE(93)
  *self->functions = (List){NULL, NULL};
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_parse_if_function(SyntaxTreeNamespace* self, String* keyword, SyntaxTreeType* parent_type, Char* end, Bool* is_func);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_parse_if_function = "SyntaxTreeNamespace.parse-if-function";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_parse_if_function
Returncode SyntaxTreeNamespace_parse_if_function(SyntaxTreeNamespace* self, String* keyword, SyntaxTreeType* parent_type, Char* end, Bool* is_func) {
  if ((*end) != ' ') {
    CHECK(99, f_syntax_error_c(&(String){35, 34, "expected space after key-word, got"}, (*end)) )
  }
  CHECK(100, String_equal(keyword, &(String){5, 4, "func"}, &((*is_func))) )
  if ((*is_func)) {
    SyntaxTreeFunction* _SyntaxTreeFunction37;
    CHECK(102, SyntaxTreeFunction_parse_new(NULL, parent_type, &((*end)), &(_SyntaxTreeFunction37)) )
    CHECK(102, List_add(self->functions, _SyntaxTreeFunction37) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeNamespace_write(SyntaxTreeNamespace* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeNamespace_write = "SyntaxTreeNamespace.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeNamespace_write
Returncode SyntaxTreeNamespace_write(SyntaxTreeNamespace* self) {
  CHECK(106, SyntaxTreeBranch_write(&(self->_base)) )
  CHECK(107, SyntaxTreeBranch_write_children(&(self->_base), self->functions) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeNamespace__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeNamespace__dtl[] = {(void*)SyntaxTreeNamespace_write, (void*)SyntaxTreeBranch_parse_child};
#endif


/* A basic code node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeCode SyntaxTreeCode;
#elif MR_STAGE == MR_TYPES(1)
struct SyntaxTreeCode {
  SyntaxTreeNode _base;
  SyntaxTreeBlock* parent;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeCode__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeCode__dtl[] = {(void*)SyntaxTreeNode_write};
#endif


/* A basic code block node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeBlock SyntaxTreeBlock;
#elif MR_STAGE == MR_TYPES(2)
struct SyntaxTreeBlock {
  SyntaxTreeBranch _base;
  List* nodes;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_parse_block(SyntaxTreeBlock* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_parse_block = "SyntaxTreeBlock.parse-block";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_parse_block
Returncode SyntaxTreeBlock_parse_block(SyntaxTreeBlock* self, Char* end) {
  self->nodes = malloc(sizeof(List));
  if (self->nodes == NULL) RAISE(120)
  *self->nodes = (List){NULL, NULL};
  CHECK(121, SyntaxTreeBranch_parse_children(&(self->_base), NULL, &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_parse_child(SyntaxTreeBlock* self, String* keyword, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_parse_child = "SyntaxTreeBlock.parse-child";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_parse_child
Returncode SyntaxTreeBlock_parse_child(SyntaxTreeBlock* self, String* keyword, Char* end) {
  SyntaxTreeCode* node = NULL;
  Bool _Bool38;
  CHECK(125, String_equal(keyword, &(String){3, 2, "do"}, &(_Bool38)) )
  if (_Bool38) {
    if ((*end) != '\n') {
      CHECK(127, f_syntax_error_c(&(String){23, 22, "expected new-line, got"}, (*end)) )
    }
    SyntaxTreeDoLoop* _SyntaxTreeDoLoop39;
    CHECK(128, SyntaxTreeDoLoop_parse_new(NULL, self, &((*end)), &(_SyntaxTreeDoLoop39)) )
    CHECK(128, List_add(self->nodes, &(_SyntaxTreeDoLoop39->_base._base)) )
  }
  else {
    glob->save_input = true;
    SyntaxTreeExpression* _SyntaxTreeExpression40;
    CHECK(132, SyntaxTreeExpression_parse_new(NULL, self, &((*end)), &(_SyntaxTreeExpression40)) )
    CHECK(132, List_add(self->nodes, &(_SyntaxTreeExpression40->_base)) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeBlock_write_block(SyntaxTreeBlock* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeBlock_write_block = "SyntaxTreeBlock.write-block";
#define MR_FUNC_NAME _func_name_SyntaxTreeBlock_write_block
Returncode SyntaxTreeBlock_write_block(SyntaxTreeBlock* self) {
  CHECK(136, write(&(String){4, 3, " {\n"}) )
  CHECK(137, SyntaxTreeBranch_write(&(self->_base)) )
  CHECK(138, SyntaxTreeBranch_write_children(&(self->_base), self->nodes) )
  CHECK(139, write_spaces(self->_base.indentation_spaces - 2) )
  CHECK(140, write(&(String){2, 1, "}"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeBlock__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeBlock__dtl[] = {(void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBlock_parse_child};
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/file-io.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "global/type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/variable.c"
#include "syntax-tree/code.c"
#include "syntax-tree/function.c"
#include "syntax-tree/loop.c"
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
#endif
#undef MR_INCLUDES
#endif

#endif
