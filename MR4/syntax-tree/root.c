#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/root.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file19_name = "syntax-tree/root.3.mr";
#endif
#define MR_FILE_NAME _mr_file19_name

/* MR4 compiler - Syntax tree root */

/* The syntax tree root */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeRoot SyntaxTreeRoot;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeRoot {
  SyntaxTreeNamespace _base;
  List* types;
  String* output_file_name;
  SyntaxTreeMainFunction* main_function;
/*  write C file in this order:
  1. type declarations
  2. type structs (ordered by depth)
  3. function declarations
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
  if (argv->length < 3) {
    CHECK(11, Sys_print(sys, &(String){58, 57, "usage: mr-4compiler OUTPUT-C-FILE-NAME INPUT-MR3-FILES..."}) )
    RAISE(13)
  }
  
  CHECK(15, SyntaxTreeNamespace_init(&(self->_base)) )
  if ((1) < 0 || (1) >= (argv)->length) RAISE(16)
  self->output_file_name = (&(((String*)((argv)->values))[1]));
  self->types = malloc(sizeof(List));
  if (self->types == NULL) RAISE(17)
  *self->types = (List){NULL, NULL};
  {int n; for (n = (2); n < (argv->length); ++n) {
    if ((n) < 0 || (n) >= (argv)->length) RAISE(19)
    glob->input_file_name = (&(((String*)((argv)->values))[n]));
    glob->line_number = 1;
    CHECK(21, file_open(glob->input_file_name, true, &(glob->input_file)) )
    
    Char _Char89;
    CHECK(23, SyntaxTreeBranch_parse_children(&(self->_base._base), NULL, NULL, &(_Char89)) )
    
    if (glob->input_buffer->length > 0 || glob->input_spaces > 0) {
      CHECK(26, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
      CHECK(27, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){28, 27, "no new-line before file end"}) )
    }
    
    CHECK(29, file_close(glob->input_file) )
  }}
  
  if ((2) < 0 || (2) >= (argv)->length) RAISE(31)
  self->_base._base._base.input_file_name = (&(((String*)((argv)->values))[2]));
  self->_base._base._base.line_number = 0;
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
  Bool _Bool90;
  CHECK(35, SyntaxTreeNamespace_parse_if_function(&(self->_base), keyword, NULL, &((*end)), &(_Bool90)) )
  if (_Bool90) {
    return OK;
  }
  
  Bool _Bool91;
  CHECK(38, String_equal(keyword, &(String){7, 6, "struct"}, &(_Bool91)) )
  if (_Bool91) {
    if ((*end) != ' ') {
      CHECK(40, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){35, 34, "expected space after \"struct\", got"}, (*end)) )
    }
    TypeData* _TypeData92;
    CHECK(42, TypeData_parse_new(NULL, false, &((*end)), &(_TypeData92)) )
    CHECK(42, List_add(self->types, _TypeData92) )
    
  }
  else {
    Bool _Bool93;
    CHECK(45, String_equal(keyword, &(String){6, 5, "class"}, &(_Bool93)) )
    if (_Bool93) {
      if ((*end) != ' ') {
        CHECK(47, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){34, 33, "expected space after \"class\", got"}, (*end)) )
      }
      TypeData* _TypeData94;
      CHECK(49, TypeData_parse_new(NULL, true, &((*end)), &(_TypeData94)) )
      CHECK(49, List_add(self->types, _TypeData94) )
      
    }
    else {
      Bool _Bool95;
      CHECK(52, String_equal(keyword, &(String){5, 4, "main"}, &(_Bool95)) )
      if (_Bool95) {
        if ((*end) != '\n') {
          CHECK(54, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){36, 35, "expected new-line after \"main\", got"}, (*end)) )
        }
        CHECK(56, SyntaxTreeMainFunction_parse_new(NULL, &((*end)), &(self->main_function)) )
        
      }
      else {
        Bool _Bool96;
        CHECK(59, String_equal(keyword, &(String){7, 6, "native"}, &(_Bool96)) )
        if (_Bool96) {
          if ((*end) != ' ') {
            CHECK(61, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){35, 34, "expected space after \"native\", got"}, (*end)) )
          }
          SyntaxTreeNativeFunction* _SyntaxTreeNativeFunction97;
          CHECK(63, SyntaxTreeNativeFunction_parse_new(NULL, &((*end)), &(_SyntaxTreeNativeFunction97)) )
          CHECK(63, List_add(self->_base.functions, &(_SyntaxTreeNativeFunction97->_base)) )
          
        }
        else {
          Bool _Bool98;
          CHECK(66, String_equal(keyword, &(String){5, 4, "test"}, &(_Bool98)) )
          if (_Bool98) {
            if ((*end) != ' ') {
              CHECK(68, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){33, 32, "expected space after \"test\", got"}, (*end)) )
            }
            SyntaxTreeTestFunction* _SyntaxTreeTestFunction99;
            CHECK(70, SyntaxTreeTestFunction_parse_new(NULL, &((*end)), &(_SyntaxTreeTestFunction99)) )
            CHECK(70, List_add(self->_base.functions, &(_SyntaxTreeTestFunction99->_base)) )
            
          }
          else {
            Bool _Bool100;
            CHECK(73, String_equal(keyword, &(String){5, 4, "mock"}, &(_Bool100)) )
            if (_Bool100) {
              if ((*end) != ' ') {
                CHECK(75, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){33, 32, "expected space after \"mock\", got"}, (*end)) )
              }
              SyntaxTreeMockFunction* _SyntaxTreeMockFunction101;
              CHECK(77, SyntaxTreeMockFunction_parse_new(NULL, &((*end)), &(_SyntaxTreeMockFunction101)) )
              CHECK(77, List_add(self->_base.functions, &(_SyntaxTreeMockFunction101->_base)) )
              
            }
            else {
              CHECK(81, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){16, 15, "unknown keyword"}, keyword) )
            }
          }
        }
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_m_link_types(SyntaxTreeRoot* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_m_link_types = "SyntaxTreeRoot.m-link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_m_link_types
Returncode SyntaxTreeRoot_m_link_types(SyntaxTreeRoot* self) {
  RAISE(84)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_analyze(SyntaxTreeRoot* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_analyze = "SyntaxTreeRoot.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_analyze
Returncode SyntaxTreeRoot_analyze(SyntaxTreeRoot* self) {
  CHECK(87, SyntaxTreeRoot_m_order_types(self) )
  CHECK(88, SyntaxTreeNamespace_m_link_types(&(self->_base)) )
  CHECK(89, SyntaxTreeNode_m_link_children_types(&(self->_base._base._base), self->types) )
  if (NULL != self->main_function) {
    CHECK(91, (self->main_function)->_base._base._base._base._dtl[0](self->main_function) )
  }
  CHECK(92, SyntaxTreeNamespace_analyze(&(self->_base)) )
  CHECK(93, SyntaxTreeNode_analyze_children(&(self->_base._base._base), self->types) )
  if (NULL != self->main_function) {
    CHECK(95, (self->main_function)->_base._base._base._base._dtl[1](self->main_function) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_m_order_types(SyntaxTreeRoot* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_m_order_types = "SyntaxTreeRoot.m-order-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_m_order_types
Returncode SyntaxTreeRoot_m_order_types(SyntaxTreeRoot* self) {
  List* ordered_list = malloc(sizeof(List));
  if (ordered_list == NULL) RAISE(98)
  *ordered_list = (List){NULL, NULL};
  while (true) {
    TypeData* type_data = NULL;
    CHECK(101, List_m_pop(self->types, (void**)&(type_data)) )
    if (!(NULL != type_data)) break;
    CHECK(103, TypeData_m_order_bases(type_data, ordered_list) )
  }
  free(self->types);
  self->types = ordered_list;
  return OK;
}
#undef MR_FUNC_NAME
#endif/*  write C file in this order:
  1. type declarations
  2. type structs (ordered by depth)
  3. function declarations
  4. global variables
  5. function bodies
   */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_write(SyntaxTreeRoot* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_write = "SyntaxTreeRoot.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_write
Returncode SyntaxTreeRoot_write(SyntaxTreeRoot* self) {
  CHECK(115, file_open(self->output_file_name, false, &(glob->output_file)) )
  
  CHECK(117, write_global(&(String){19, 18, "#include \"mr.4.h\"\n"}) )
  
  CHECK(119, write_global(&(String){27, 26, "\n\n/* types declaration */\n"}) )
  TypeDeclarationWriter* type_declaration_writer = &(TypeDeclarationWriter){TypeDeclarationWriter__dtl};
  type_declaration_writer->_base._dtl = TypeDeclarationWriter__dtl;
  CHECK(121, SyntaxTreeRoot_write_for_type(self, &(type_declaration_writer->_base)) )
  
  /* will write type structs */
  CHECK(124, write_global(&(String){22, 21, "\n\n/* types struct */\n"}) )
  CHECK(125, SyntaxTreeBranch_write_children(&(self->_base._base), self->types) )
  
  CHECK(127, write_global(&(String){35, 34, "\n\n/* types methods declaration */\n"}) )
  TypeMethodsDeclarationWriter* type_methods_declaration_writer = &(TypeMethodsDeclarationWriter){TypeMethodsDeclarationWriter__dtl};
  type_methods_declaration_writer->_base._dtl = TypeMethodsDeclarationWriter__dtl;
  CHECK(129, SyntaxTreeRoot_write_for_type(self, &(type_methods_declaration_writer->_base)) )
  
  CHECK(131, write_global(&(String){32, 31, "\n\n/* types global variables */\n"}) )
  TypeGlobalWriter* type_global_writer = &(TypeGlobalWriter){TypeGlobalWriter__dtl};
  type_global_writer->_base._dtl = TypeGlobalWriter__dtl;
  CHECK(133, SyntaxTreeRoot_write_for_type(self, &(type_global_writer->_base)) )
  
  /* will write global variables */
  CHECK(136, write_global(&(String){26, 25, "\n\n/* global variables */\n"}) )
  CHECK(137, SyntaxTreeBranch_write_children(&(self->_base._base), self->_base._base.variables) )
  
  CHECK(139, write_global(&(String){38, 37, "\n\n/* global functions declaration */\n"}) )
  CHECK(140, SyntaxTreeNamespace_write_functions_declaration(&(self->_base)) )
  
  CHECK(142, write_global(&(String){28, 27, "\n\n/* types methods body */\n"}) )
  TypeMethodsBodyWriter* type_methods_body_writer = &(TypeMethodsBodyWriter){TypeMethodsBodyWriter__dtl};
  type_methods_body_writer->_base._dtl = TypeMethodsBodyWriter__dtl;
  CHECK(144, SyntaxTreeRoot_write_for_type(self, &(type_methods_body_writer->_base)) )
  
  /* will write global functions bodies */
  CHECK(147, write_global(&(String){31, 30, "\n\n/* global functions body */\n"}) )
  CHECK(148, SyntaxTreeBranch_write_children(&(self->_base._base), self->_base.functions) )
  
  if (NULL != self->main_function) {
    CHECK(151, write_global(&(String){23, 22, "\n\n/* main function */\n"}) )
    CHECK(152, (self->main_function)->_base._base._base._base._dtl[2](self->main_function) )
  }
  
  CHECK(154, file_close(glob->output_file) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_write_for_type(SyntaxTreeRoot* self, TypeWriter* type_writer);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_write_for_type = "SyntaxTreeRoot.write-for-type";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_write_for_type
Returncode SyntaxTreeRoot_write_for_type(SyntaxTreeRoot* self, TypeWriter* type_writer) {
  ListNode* child = self->types->first;
  while (true) {
    if (!(NULL != child)) break;
    CHECK(160, (type_writer)->_dtl[0](type_writer, child->item) )
    child = child->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeRoot__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeRoot__dtl[] = {(void*)SyntaxTreeRoot_m_link_types, (void*)SyntaxTreeRoot_analyze, (void*)SyntaxTreeRoot_write, (void*)SyntaxTreeRoot_parse_child, (void*)SyntaxTreeBranch_m_find_variable};
#endif


/* proxy write function to be mocked on unit-tests */
#if MR_STAGE == MR_DECLARATIONS
Returncode write_global(String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_global = "write-global";
#define MR_FUNC_NAME _func_name_write_global
Returncode write_global(String* text) {
  CHECK(166, write(text) )
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
