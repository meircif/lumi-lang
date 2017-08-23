#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/root.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file17_name = "syntax-tree/root.3.mr";
#endif
#define MR_FILE_NAME _mr_file17_name

/* MR4 compiler - Syntax tree root */

/* The syntax tree root */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeRoot SyntaxTreeRoot;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeRoot {
  SyntaxTreeNamespace _base;
  List* types;
/*  write C file in this order:
  1. type typedefs
  2. type structs (ordered by depth)
  3. function headers
  4. global variables
  5. function bodies
   */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_parse(SyntaxTreeRoot* self, Array* argv);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_parse = "SyntaxTreeRoot.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_parse
Returncode SyntaxTreeRoot_parse(SyntaxTreeRoot* self, Array* argv) {
  CHECK(8, SyntaxTreeNamespace_init(&(self->_base)) )
  self->types = malloc(sizeof(List));
  if (self->types == NULL) RAISE(9)
  *self->types = (List){NULL, NULL};
  {int n; for (n = (2); n < (argv->length); ++n) {
    if ((n) < 0 || (n) >= (argv)->length) RAISE(11)
    glob->input_file_name = (&(((String*)((argv)->values))[n]));
    glob->line_number = 0;
    
    Char end = '\n';
    CHECK(15, SyntaxTreeBranch_parse_children(&(self->_base._base), NULL, &(end)) )
    
    if (glob->input_buffer->length > 0 || glob->input_spaces > 0) {
      CHECK(18, f_syntax_error_msg(&(String){28, 27, "no new-line before file end"}) )
    }
  }}
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_parse_child(SyntaxTreeRoot* self, String* keyword, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_parse_child = "SyntaxTreeRoot.parse-child";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_parse_child
Returncode SyntaxTreeRoot_parse_child(SyntaxTreeRoot* self, String* keyword, Char* end) {
  Bool _Bool61;
  CHECK(21, SyntaxTreeNamespace_parse_if_function(&(self->_base), keyword, NULL, &((*end)), &(_Bool61)) )
  if (_Bool61) {
    return OK;
  }
  
  Bool _Bool62;
  CHECK(24, String_equal(keyword, &(String){7, 6, "struct"}, &(_Bool62)) )
  if (_Bool62) {
    if ((*end) != ' ') {
      CHECK(26, f_syntax_error_c(&(String){35, 34, "expected space after \"struct\", got"}, (*end)) )
    }
    SyntaxTreeType* _SyntaxTreeType63;
    CHECK(27, SyntaxTreeType_parse_new(NULL, &((*end)), &(_SyntaxTreeType63)) )
    CHECK(27, List_add(self->types, _SyntaxTreeType63) )
    
  }
  else {
    Bool _Bool64;
    CHECK(29, String_equal(keyword, &(String){6, 5, "class"}, &(_Bool64)) )
    if (_Bool64) {
      if ((*end) != ' ') {
        CHECK(31, f_syntax_error_c(&(String){34, 33, "expected space after \"class\", got"}, (*end)) )
      }
      SyntaxTreeType* _SyntaxTreeType65;
      CHECK(32, SyntaxTreeType_parse_new(NULL, &((*end)), &(_SyntaxTreeType65)) )
      CHECK(32, List_add(self->types, _SyntaxTreeType65) )
      
    }
    else {
      Bool _Bool66;
      CHECK(34, String_equal(keyword, &(String){5, 4, "main"}, &(_Bool66)) )
      if (_Bool66) {
        if ((*end) != '\n') {
          CHECK(36, f_syntax_error_c(&(String){36, 35, "expected new-line after \"main\", got"}, (*end)) )
        }
        SyntaxTreeMainFunction* _SyntaxTreeMainFunction67;
        CHECK(37, SyntaxTreeMainFunction_parse_new(NULL, &((*end)), &(_SyntaxTreeMainFunction67)) )
        CHECK(37, List_add(self->_base.functions, &(_SyntaxTreeMainFunction67->_base)) )
        
      }
      else {
        Bool _Bool68;
        CHECK(40, String_equal(keyword, &(String){7, 6, "native"}, &(_Bool68)) )
        if (_Bool68) {
          if ((*end) != ' ') {
            CHECK(42, f_syntax_error_c(&(String){35, 34, "expected space after \"native\", got"}, (*end)) )
          }
          SyntaxTreeNativeFunction* _SyntaxTreeNativeFunction69;
          CHECK(43, SyntaxTreeNativeFunction_parse_new(NULL, &((*end)), &(_SyntaxTreeNativeFunction69)) )
          CHECK(43, List_add(self->_base.functions, &(_SyntaxTreeNativeFunction69->_base)) )
          
        }
        else {
          Bool _Bool70;
          CHECK(46, String_equal(keyword, &(String){5, 4, "test"}, &(_Bool70)) )
          if (_Bool70) {
            if ((*end) != ' ') {
              CHECK(48, f_syntax_error_c(&(String){33, 32, "expected space after \"test\", got"}, (*end)) )
            }
            SyntaxTreeTestFunction* _SyntaxTreeTestFunction71;
            CHECK(49, SyntaxTreeTestFunction_parse_new(NULL, &((*end)), &(_SyntaxTreeTestFunction71)) )
            CHECK(49, List_add(self->_base.functions, &(_SyntaxTreeTestFunction71->_base)) )
            
          }
          else {
            Bool _Bool72;
            CHECK(52, String_equal(keyword, &(String){5, 4, "mock"}, &(_Bool72)) )
            if (_Bool72) {
              if ((*end) != ' ') {
                CHECK(54, f_syntax_error_c(&(String){33, 32, "expected space after \"mock\", got"}, (*end)) )
              }
              SyntaxTreeMockFunction* _SyntaxTreeMockFunction73;
              CHECK(55, SyntaxTreeMockFunction_parse_new(NULL, &((*end)), &(_SyntaxTreeMockFunction73)) )
              CHECK(55, List_add(self->_base.functions, &(_SyntaxTreeMockFunction73->_base)) )
              
            }
            else {
              CHECK(59, f_syntax_error(&(String){16, 15, "unknown keyword"}, keyword) )
            }
          }
        }
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif/*  write C file in this order:
  1. type typedefs
  2. type structs (ordered by depth)
  3. function headers
  4. global variables
  5. function bodies
   */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_write(SyntaxTreeRoot* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_write = "SyntaxTreeRoot.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_write
Returncode SyntaxTreeRoot_write(SyntaxTreeRoot* self) {
  CHECK(69, SyntaxTreeBranch_write_children(&(self->_base._base), self->types) )
  CHECK(70, SyntaxTreeNamespace_write(&(self->_base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeRoot__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeRoot__dtl[] = {(void*)SyntaxTreeRoot_write, (void*)SyntaxTreeRoot_parse_child};
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
#include "syntax-tree/code-flow.c"
#include "syntax-tree/function.c"
#include "syntax-tree/node.c"
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
