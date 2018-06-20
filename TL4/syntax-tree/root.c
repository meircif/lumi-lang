#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "syntax-tree/root.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file22_name = "syntax-tree/root.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file22_name

/* TL4 compiler - Syntax tree root */

#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct GlobalNodes GlobalNodes;
#elif LUMI_STAGE == LUMI_TYPES(3)
struct GlobalNodes {
  SyntaxTreeNamespace _base;
  List* types;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode GlobalNodes_init(GlobalNodes* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_GlobalNodes_init = "GlobalNodes.init";
#define LUMI_FUNC_NAME _func_name_GlobalNodes_init
Returncode GlobalNodes_init(GlobalNodes* self) {
  CHECK(7, SyntaxTreeNamespace_init(&(self->_base)) )
  self->types = malloc(sizeof(List));
  if (self->types == NULL) RAISE(8)
  *self->types = (List){NULL, NULL};
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func GlobalNodes__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func GlobalNodes__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeNamespace_link_types, (void*)SyntaxTreeNamespace_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBranch_parse_child, (void*)SyntaxTreeBranch_find_variable};
#endif


/* The syntax tree root */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeRoot SyntaxTreeRoot;
#elif LUMI_STAGE == LUMI_TYPES(4)
struct SyntaxTreeRoot {
  GlobalNodes _base;
  List* enums;
  List* constants;
  List* modules;
  String* output_file_name;
  SyntaxTreeMainFunction* main_function;
  GlobalInit* global_init;
  Array* line_counts;
  Int covered_files;
  Bool is_library;
/*  write C file in this order:
  1. type declarations
  2. type structs (ordered by depth)
  3. function declarations
  4. global variables
  5. function bodies
  6. main function
   */};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeRoot_init(SyntaxTreeRoot* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_init = "SyntaxTreeRoot.init";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeRoot_init
Returncode SyntaxTreeRoot_init(SyntaxTreeRoot* self) {
  CHECK(24, GlobalNodes_init(&(self->_base)) )
  self->enums = malloc(sizeof(List));
  if (self->enums == NULL) RAISE(25)
  *self->enums = (List){NULL, NULL};
  self->constants = malloc(sizeof(List));
  if (self->constants == NULL) RAISE(26)
  *self->constants = (List){NULL, NULL};
  self->modules = malloc(sizeof(List));
  if (self->modules == NULL) RAISE(27)
  *self->modules = (List){NULL, NULL};
  self->global_init = malloc(sizeof(GlobalInit));
  if (self->global_init == NULL) RAISE(28)
  *self->global_init = (GlobalInit){GlobalInit__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, false, false};
  self->global_init->_base._base._base._base._dtl = GlobalInit__dtl;
  CHECK(29, GlobalInit_init(self->global_init) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeRoot_parse(SyntaxTreeRoot* self, Array* argv);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_parse = "SyntaxTreeRoot.parse";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeRoot_parse
Returncode SyntaxTreeRoot_parse(SyntaxTreeRoot* self, Array* argv) {
  Int first_file_index = 0;
  Int arg_test_index = -1;
  Int input_files_number = 0;
  {int n; for (n = (1); n < (argv->length); ++n) {
    if ((n) < 0 || (n) >= (argv)->length) RAISE(36)
    String* arg = (&(((String*)((argv)->values))[n]));
    if (arg_test_index == n - 1) {
      CHECK(38, string_new_copy(arg, &(glob->tested_module)) )
    }
    else {
      Bool _Bool110;
      CHECK(39, String_equal(arg, &(String){3, 2, "-t"}, &(_Bool110)) )
      Bool _Bool111;
      CHECK(39, String_equal(arg, &(String){7, 6, "--test"}, &(_Bool111)) )
      if (_Bool110 || _Bool111) {
        arg_test_index = n;
      }
      else {
        if (first_file_index == 0) {
          first_file_index = n;
        }
        else {
          input_files_number += 1;
        }
      }
    }
  }}
  
  if (input_files_number == 0 || arg_test_index == argv->length - 1) {
    CHECK(47, print(&(String){39, 38, "usage: tl4-compiler [-t TESTED-MODULE]"}) )
    CHECK(48, print(&(String){40, 39, " OUTPUT-C-FILE-NAME INPUT-TL4-FILES...\n"}) )
    RAISE(49)
  }
  
  if (NULL != glob->tested_module) {
    self->line_counts = _new_array(input_files_number, sizeof(LineCount));
    if (self->line_counts == NULL) RAISE(52)
  }
  
  if ((first_file_index) < 0 || (first_file_index) >= (argv)->length) RAISE(54)
  self->output_file_name = (&(((String*)((argv)->values))[first_file_index]));
  input_files_number = 0;
  {int n; for (n = (first_file_index + 1); n < (argv->length); ++n) {
    if (n > (arg_test_index + 1) || n < arg_test_index) {
      if ((n) < 0 || (n) >= (argv)->length) RAISE(58)
      glob->input_file_name = (&(((String*)((argv)->values))[n]));
      glob->input_file_index = input_files_number;
      input_files_number += 1;
      glob->line_number = 1;
      glob->current_module = NULL;
      CHECK(63, file_open(glob->input_file_name, true, &(glob->input_file)) )
      
      Char _Char112;
      CHECK(65, SyntaxTreeBranch_parse_children(&(self->_base._base._base), NULL, NULL, &(_Char112)) )
      
      if (glob->input_buffer->length > 0 || glob->input_spaces > 0) {
        CHECK(68, SyntaxTreeNode_set_location(&(self->_base._base._base._base)) )
        CHECK(69, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){28, 27, "no new-line before file end"}) )
      }
      
      CHECK(71, file_close(glob->input_file) )
      if (NULL != self->line_counts) {
        if ((glob->input_file_index) < 0 || (glob->input_file_index) >= (self->line_counts)->length) RAISE(73)
        CHECK(73, LineCount_init((&(((LineCount*)((self->line_counts)->values))[glob->input_file_index]))) )
      }
    }
  }}
  
  glob->current_module = NULL;
  self->_base._base._base._base.line_number = 0;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeRoot_parse_if_common(SyntaxTreeRoot* self, String* keyword, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, Bool* is_parsed);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_parse_if_common = "SyntaxTreeRoot.parse-if-common";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeRoot_parse_if_common
Returncode SyntaxTreeRoot_parse_if_common(SyntaxTreeRoot* self, String* keyword, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, Bool* is_parsed) {
  (*is_parsed) = false;
  if (!(NULL != glob->current_module)) {
    Bool _Bool113;
    CHECK(86, String_equal(keyword, &(String){7, 6, "module"}, &(_Bool113)) )
    if (_Bool113) {
      if ((*end) != ' ') {
        CHECK(88, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){35, 34, "expected space after \"module\", got"}, (*end)) )
      }
      String* name = NULL;
      Int _Int114;
      CHECK(91, read_until(&(String){1, 0, ""}, false, &(name), &((*end)), &(_Int114)) )
      Bool _Bool115;
      CHECK(92, f_is_legal_name(name, NAME_DEFAULT, &(_Bool115)) )
      if (!_Bool115) {
        CHECK(93, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){20, 19, "illegal module name"}, name) )
      }
      SyntaxTreeVariable* _SyntaxTreeVariable116;
      CHECK(94, NameMap_find(glob->global_module->variable_map, name, (void**)&(_SyntaxTreeVariable116)) )
      if (NULL != _SyntaxTreeVariable116) {
        CHECK(95, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){31, 30, "module name overrides variable"}, name) )
      }
      SyntaxTreeFunction* _SyntaxTreeFunction117;
      CHECK(96, NameMap_find(glob->global_module->function_map, name, (void**)&(_SyntaxTreeFunction117)) )
      if (NULL != _SyntaxTreeFunction117) {
        CHECK(97, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){31, 30, "module name overrides function"}, name) )
      }
      CHECK(98, NameMap_find(glob->module_map, name, (void**)&(glob->current_module)) )
      if (!(NULL != glob->current_module)) {
        ModuleMembers* module_members = malloc(sizeof(ModuleMembers));
        if (module_members == NULL) RAISE(99)
        *module_members = (ModuleMembers){NULL, NULL, NULL, NULL, NULL};
        CHECK(100, ModuleMembers_init(module_members, name) )
        glob->current_module = module_members;
        CHECK(102, List_add(self->modules, module_members) )
      }
      (*is_parsed) = true;
      return OK;
    }
    else {
      CHECK(106, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){26, 25, "no \"module\" in file start"}) )
    }
  }
  CHECK(107, SyntaxTreeBranch_parse_if_common(&(self->_base._base._base), keyword, parent_type, parent_block, &((*end)), &((*is_parsed))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeRoot_parse_child(SyntaxTreeRoot* self, String* keyword, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_parse_child = "SyntaxTreeRoot.parse-child";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeRoot_parse_child
Returncode SyntaxTreeRoot_parse_child(SyntaxTreeRoot* self, String* keyword, Char* end) {
  Bool _Bool118;
  CHECK(111, SyntaxTreeNamespace_parse_if_function(&(self->_base._base), keyword, NULL, &((*end)), &(_Bool118)) )
  if (_Bool118) {
    return OK;
  }
  
  Bool _Bool119;
  CHECK(114, String_equal(keyword, &(String){6, 5, "const"}, &(_Bool119)) )
  if (_Bool119) {
    if ((*end) != ' ') {
      CHECK(116, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){34, 33, "expected space after \"const\", got"}, (*end)) )
    }
    SyntaxTreeConstant* _SyntaxTreeConstant120;
    CHECK(118, SyntaxTreeConstant_parse_new(NULL, &((*end)), &(_SyntaxTreeConstant120)) )
    CHECK(118, List_add(self->_base._base._base.variables, &(_SyntaxTreeConstant120->_base)) )
    
  }
  else {
    Bool _Bool121;
    CHECK(120, String_equal(keyword, &(String){7, 6, "struct"}, &(_Bool121)) )
    if (_Bool121) {
      if ((*end) != ' ') {
        CHECK(122, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){35, 34, "expected space after \"struct\", got"}, (*end)) )
      }
      TypeData* _TypeData122;
      CHECK(124, TypeData_parse_new(NULL, false, &((*end)), &(_TypeData122)) )
      CHECK(124, List_add(self->_base.types, _TypeData122) )
      
    }
    else {
      Bool _Bool123;
      CHECK(126, String_equal(keyword, &(String){6, 5, "class"}, &(_Bool123)) )
      if (_Bool123) {
        if ((*end) != ' ') {
          CHECK(128, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){34, 33, "expected space after \"class\", got"}, (*end)) )
        }
        TypeData* _TypeData124;
        CHECK(130, TypeData_parse_new(NULL, true, &((*end)), &(_TypeData124)) )
        CHECK(130, List_add(self->_base.types, _TypeData124) )
        
      }
      else {
        Bool _Bool125;
        CHECK(132, String_equal(keyword, &(String){5, 4, "enum"}, &(_Bool125)) )
        if (_Bool125) {
          if ((*end) != ' ') {
            CHECK(134, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){33, 32, "expected space after \"enum\", got"}, (*end)) )
          }
          EnumData* _EnumData126;
          CHECK(136, EnumData_parse_new(NULL, &((*end)), &(_EnumData126)) )
          CHECK(136, List_add(self->enums, _EnumData126) )
          
        }
        else {
          Bool _Bool127;
          CHECK(138, String_equal(keyword, &(String){5, 4, "main"}, &(_Bool127)) )
          if (_Bool127) {
            if ((*end) != '\n') {
              CHECK(140, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){36, 35, "expected new-line after \"main\", got"}, (*end)) )
            }
            CHECK(142, SyntaxTreeMainFunction_parse_new(NULL, &((*end)), &(self->main_function)) )
            
          }
          else {
            Bool _Bool128;
            CHECK(145, String_equal(keyword, &(String){7, 6, "native"}, &(_Bool128)) )
            if (_Bool128) {
              if ((*end) != ' ') {
                CHECK(147, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){35, 34, "expected space after \"native\", got"}, (*end)) )
              }
              CHECK(149, parse_native(self, &((*end))) )
              
            }
            else {
              Bool _Bool129;
              CHECK(151, String_equal(keyword, &(String){5, 4, "test"}, &(_Bool129)) )
              if (_Bool129) {
                if ((*end) != ' ') {
                  CHECK(153, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){33, 32, "expected space after \"test\", got"}, (*end)) )
                }
                SyntaxTreeTestFunction* _SyntaxTreeTestFunction130;
                CHECK(155, SyntaxTreeTestFunction_parse_new(NULL, &((*end)), &(_SyntaxTreeTestFunction130)) )
                CHECK(155, List_add(self->_base._base.functions, &(_SyntaxTreeTestFunction130->_base)) )
                
              }
              else {
                Bool _Bool131;
                CHECK(158, String_equal(keyword, &(String){5, 4, "mock"}, &(_Bool131)) )
                if (_Bool131) {
                  if ((*end) != ' ') {
                    CHECK(160, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){33, 32, "expected space after \"mock\", got"}, (*end)) )
                  }
                  SyntaxTreeMockFunction* _SyntaxTreeMockFunction132;
                  CHECK(162, SyntaxTreeMockFunction_parse_new(NULL, &((*end)), &(_SyntaxTreeMockFunction132)) )
                  CHECK(162, List_add(self->_base._base.functions, &(_SyntaxTreeMockFunction132->_base)) )
                  
                }
                else {
                  CHECK(166, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){16, 15, "unknown keyword"}, keyword) )
                }
              }
            }
          }
        }
      }
    }
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeRoot_link_types(SyntaxTreeRoot* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_link_types = "SyntaxTreeRoot.link-types";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeRoot_link_types
Returncode SyntaxTreeRoot_link_types(SyntaxTreeRoot* self) {
  RAISE(169)
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeRoot_analyze(SyntaxTreeRoot* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_analyze = "SyntaxTreeRoot.analyze";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeRoot_analyze
Returncode SyntaxTreeRoot_analyze(SyntaxTreeRoot* self) {
  CHECK(172, SyntaxTreeRoot_m_order_types(self) )
  CHECK(173, SyntaxTreeNamespace_link_types(&(self->_base._base)) )
  CHECK(174, SyntaxTreeNode_link_children_types(&(self->_base._base._base._base), self->_base.types) )
  CHECK(175, (self->global_init)->_base._base._base._base._dtl[1](self->global_init) )
  if (NULL != self->main_function) {
    CHECK(177, (self->main_function)->_base._base._base._base._dtl[1](self->main_function) )
  }
  CHECK(178, SyntaxTreeNamespace_analyze(&(self->_base._base)) )
  CHECK(179, SyntaxTreeNode_analyze_children(&(self->_base._base._base._base), self->_base.types) )
  CHECK(180, (self->global_init)->_base._base._base._base._dtl[2](self->global_init) )
  if (NULL != glob->tested_module) {
    if (!(NULL != glob->test_functions->first)) {
      CHECK(183, print(&(String){39, 38, "General code error: no test functions\n"}) )
      RAISE(184)
    }
  }
  else {
    if (NULL != self->main_function) {
      CHECK(186, (self->main_function)->_base._base._base._base._dtl[2](self->main_function) )
    }
    else {
      if (!self->is_library) {
        CHECK(188, print(&(String){38, 37, "General code error: no main function\n"}) )
        RAISE(189)
      }
    }
  }
  CHECK(190, SyntaxTreeNode_m_order_children_constants(&(self->_base._base._base._base), self->_base._base._base.variables, self->constants) )
  if (NULL != self->line_counts) {
    CHECK(192, SyntaxTreeRoot_analyze_cover(self) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeRoot_m_order_types(SyntaxTreeRoot* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_m_order_types = "SyntaxTreeRoot.m-order-types";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeRoot_m_order_types
Returncode SyntaxTreeRoot_m_order_types(SyntaxTreeRoot* self) {
  List* ordered_list = malloc(sizeof(List));
  if (ordered_list == NULL) RAISE(195)
  *ordered_list = (List){NULL, NULL};
  while (true) {
    TypeData* type_data = NULL;
    CHECK(198, List_pop(self->_base.types, (void**)&(type_data)) )
    if (!(NULL != type_data)) break;
    CHECK(200, TypeData_m_order_bases(type_data, ordered_list) )
  }
  free(self->_base.types);
  self->_base.types = ordered_list;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeRoot_analyze_cover(SyntaxTreeRoot* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_analyze_cover = "SyntaxTreeRoot.analyze-cover";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeRoot_analyze_cover
Returncode SyntaxTreeRoot_analyze_cover(SyntaxTreeRoot* self) {
  ModuleMembers* _ModuleMembers133;
  CHECK(205, NameMap_find(glob->module_map, glob->tested_module, (void**)&(_ModuleMembers133)) )
  if (!(NULL != _ModuleMembers133)) {
    CHECK(206, print(&(String){44, 43, "General code error: unknown tested module \""}) )
    CHECK(207, print(glob->tested_module) )
    CHECK(208, print(&(String){3, 2, "\"\n"}) )
    RAISE(209)
  }
  Int covered_index = 0;
  {int n; for (n = (0); n < (self->line_counts->length); ++n) {
    if ((n) < 0 || (n) >= (self->line_counts)->length) RAISE(212)
    LineCount* line_count = (&(((LineCount*)((self->line_counts)->values))[n]));
    if (line_count->needs_cover) {
      line_count->covered_index = covered_index;
      covered_index += 1;
    }
  }}
  self->covered_files = covered_index;
  if (self->covered_files == 0) {
    CHECK(218, print(&(String){51, 50, "General code error: no code to test under module \""}) )
    CHECK(219, print(glob->tested_module) )
    CHECK(220, print(&(String){3, 2, "\"\n"}) )
    RAISE(221)
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif/*  write C file in this order:
  1. type declarations
  2. type structs (ordered by depth)
  3. function declarations
  4. global variables
  5. function bodies
  6. main function
   */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeRoot_write(SyntaxTreeRoot* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_write = "SyntaxTreeRoot.write";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeRoot_write
Returncode SyntaxTreeRoot_write(SyntaxTreeRoot* self) {
  CHECK(232, file_open(self->output_file_name, false, &(glob->output_file)) )
  
  CHECK(234, write_global(&(String){21, 20, "#include \"lumi.4.h\"\n"}) )
  
  CHECK(236, write_global(&(String){27, 26, "\n\n/* types declaration */\n"}) )
  TypeDeclarationWriter* type_declaration_writer = &(TypeDeclarationWriter){TypeDeclarationWriter__dtl};
  type_declaration_writer->_base._dtl = TypeDeclarationWriter__dtl;
  CHECK(238, SyntaxTreeRoot_write_for_type(self, &(type_declaration_writer->_base)) )
  
  /* will write Enums */
  CHECK(241, write_global(&(String){15, 14, "\n\n/* Enums */\n"}) )
  CHECK(242, SyntaxTreeNode_write_children(&(self->_base._base._base._base), self->enums) )
  
  /* will write constants */
  CHECK(245, write_global(&(String){19, 18, "\n\n/* constants */\n"}) )
  CHECK(246, SyntaxTreeNode_write_children(&(self->_base._base._base._base), self->constants) )
  
  /* will write type structures */
  CHECK(249, write_global(&(String){22, 21, "\n\n/* types struct */\n"}) )
  CHECK(250, SyntaxTreeNode_write_children(&(self->_base._base._base._base), self->_base.types) )
  
  CHECK(252, write_global(&(String){35, 34, "\n\n/* types methods declaration */\n"}) )
  TypeMethodsDeclarationWriter* type_methods_declaration_writer = &(TypeMethodsDeclarationWriter){TypeMethodsDeclarationWriter__dtl};
  type_methods_declaration_writer->_base._dtl = TypeMethodsDeclarationWriter__dtl;
  CHECK(254, SyntaxTreeRoot_write_for_type(self, &(type_methods_declaration_writer->_base)) )
  
  CHECK(256, write_global(&(String){38, 37, "\n\n/* global functions declaration */\n"}) )
  CHECK(257, SyntaxTreeNamespace_write_functions_declaration(&(self->_base._base)) )
  
  CHECK(259, write_global(&(String){32, 31, "\n\n/* types global variables */\n"}) )
  TypeGlobalWriter* type_global_writer = &(TypeGlobalWriter){TypeGlobalWriter__dtl};
  type_global_writer->_base._dtl = TypeGlobalWriter__dtl;
  CHECK(261, SyntaxTreeRoot_write_for_type(self, &(type_global_writer->_base)) )
  
  /* will write global variables */
  CHECK(264, write_global(&(String){26, 25, "\n\n/* global variables */\n"}) )
  CHECK(265, SyntaxTreeNode_write_children(&(self->_base._base._base._base), self->_base._base._base.variables) )
  
  if (NULL != self->line_counts) {
    CHECK(268, SyntaxTreeRoot_write_test_coverage_data(self) )
  }
  
  CHECK(270, write_global(&(String){28, 27, "\n\n/* types methods body */\n"}) )
  TypeMethodsBodyWriter* type_methods_body_writer = &(TypeMethodsBodyWriter){TypeMethodsBodyWriter__dtl};
  type_methods_body_writer->_base._dtl = TypeMethodsBodyWriter__dtl;
  CHECK(272, SyntaxTreeRoot_write_for_type(self, &(type_methods_body_writer->_base)) )
  
  /* will write global functions bodies */
  CHECK(275, write_global(&(String){31, 30, "\n\n/* global functions body */\n"}) )
  CHECK(276, SyntaxTreeNode_write_children(&(self->_base._base._base._base), self->_base._base.functions) )
  
  /* write main function */
  if (NULL != glob->tested_module ||  NULL !=  self->main_function) {
    if (!glob->is_new_mocked) {
      CHECK(281, write(&(String){61, 60, "\n\nReturncode new_Mock(Bool* allocate_success) { return OK; }"}) )
    }
    if (!glob->is_delete_mocked) {
      CHECK(284, write(&(String){50, 49, "\n\nReturncode delete_Mock(Ref self) { return OK; }"}) )
    }
  }
  if (NULL != glob->tested_module) {
    CHECK(286, SyntaxTreeRoot_write_test_main(self) )
  }
  else {
    if (NULL != self->main_function) {
      CHECK(288, write_global(&(String){23, 22, "\n\n/* main function */\n"}) )
      CHECK(289, (self->main_function)->_base._base._base._base._dtl[4](self->main_function) )
    }
  }
  
  CHECK(291, file_close(glob->output_file) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeRoot_write_for_type(SyntaxTreeRoot* self, TypeWriter* type_writer);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_write_for_type = "SyntaxTreeRoot.write-for-type";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeRoot_write_for_type
Returncode SyntaxTreeRoot_write_for_type(SyntaxTreeRoot* self, TypeWriter* type_writer) {
  ListNode* child = self->_base.types->first;
  while (true) {
    if (!(NULL != child)) break;
    CHECK(297, (((TypeData*)(child->item)))->_base._base._base._dtl[12](((TypeData*)(child->item)), type_writer) )
    child = child->next;
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeRoot_write_test_coverage_data(SyntaxTreeRoot* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_write_test_coverage_data = "SyntaxTreeRoot.write-test-coverage-data";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeRoot_write_test_coverage_data
Returncode SyntaxTreeRoot_write_test_coverage_data(SyntaxTreeRoot* self) {
  {int n; for (n = (0); n < (self->line_counts->length); ++n) {
    if ((n) < 0 || (n) >= (self->line_counts)->length) RAISE(302)
    LineCount* line_count = (&(((LineCount*)((self->line_counts)->values))[n]));
    if (line_count->needs_cover) {
      CHECK(304, write(&(String){15, 14, "\nint LUMI_file"}) )
      CHECK(305, write_int(line_count->covered_index) )
      CHECK(306, write(&(String){13, 12, "_line_count["}) )
      CHECK(307, write_int(line_count->line_needs_cover->length) )
      CHECK(308, write(&(String){9, 8, "] = {\n  "}) )
      Int mod = 0;
      {int i; for (i = (0); i < (line_count->line_needs_cover->length); ++i) {
        if (i > 0) {
          CHECK(312, write(&(String){2, 1, ","}) )
        }
        if (mod == 25) {
          CHECK(314, write(&(String){4, 3, "\n  "}) )
          mod = 1;
        }
        else {
          mod += 1;
        }
        if ((i) < 0 || (i) >= (line_count->line_needs_cover)->length) RAISE(318)
        if ((((Bool*)((line_count->line_needs_cover)->values))[i])) {
          CHECK(319, write(&(String){3, 2, " 0"}) )
        }
        else {
          CHECK(321, write(&(String){3, 2, "-1"}) )
        }
      }}
      CHECK(322, write(&(String){4, 3, "\n};"}) )
    }
  }}
  CHECK(323, write(&(String){35, 34, "\nFile_Coverage LUMI_file_coverage["}) )
  CHECK(324, write_int(self->covered_files) )
  CHECK(325, write(&(String){6, 5, "] = {"}) )
  {int n; for (n = (0); n < (self->line_counts->length); ++n) {
    if ((n) < 0 || (n) >= (self->line_counts)->length) RAISE(327)
    LineCount* line_count = (&(((LineCount*)((self->line_counts)->values))[n]));
    if (line_count->needs_cover) {
      if (line_count->covered_index > 0) {
        CHECK(330, write(&(String){2, 1, ","}) )
      }
      CHECK(331, write(&(String){6, 5, "\n  {\""}) )
      CHECK(332, write(line_count->filename) )
      CHECK(333, write(&(String){4, 3, "\", "}) )
      CHECK(334, write_int(line_count->line_needs_cover->length) )
      CHECK(335, write(&(String){12, 11, ", LUMI_file"}) )
      CHECK(336, write_int(line_count->covered_index) )
      CHECK(337, write(&(String){13, 12, "_line_count}"}) )
    }
  }}
  CHECK(338, write(&(String){5, 4, "\n};\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeRoot_write_test_main(SyntaxTreeRoot* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_write_test_main = "SyntaxTreeRoot.write-test-main";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeRoot_write_test_main
Returncode SyntaxTreeRoot_write_test_main(SyntaxTreeRoot* self) {
  CHECK(341, write(&(String){21, 20, "\nUSER_MAIN_HEADER {\n"}) )
  CHECK(342, write(&(String){29, 28, "  Returncode LUMI_err = OK;\n"}) )
  CHECK(343, write(&(String){29, 28, "  Bool LUMI_success = true;\n"}) )
  CHECK(344, (self->global_init)->_base._base._base._base._dtl[4](self->global_init) )
  CHECK(345, write(&(String){2, 1, "\n"}) )
  NameMapNode* node = glob->test_functions->first;
  while (true) {
    /* LUMI_success &= LUMI_run_test("`test-func.name`", `test-func`); */
    CHECK(349, write(&(String){34, 33, "  LUMI_success &= LUMI_run_test(\""}) )
    CHECK(350, write(((SyntaxTreeTestFunction*)(node->value))->_base.name) )
    CHECK(351, write(&(String){4, 3, "\", "}) )
    CHECK(352, SyntaxTreeFunction_write_cname(&(((SyntaxTreeTestFunction*)(node->value))->_base)) )
    CHECK(353, write(&(String){4, 3, ");\n"}) )
    node = node->next;
    if (!(NULL != node)) break;
  }
  if (NULL != self->line_counts) {
    CHECK(357, write(&(String){58, 57, "  LUMI_success &= LUMI_test_coverage(LUMI_file_coverage, "}) )
    CHECK(358, write_int(self->covered_files) )
    CHECK(359, write(&(String){4, 3, ");\n"}) )
  }
  CHECK(360, write(&(String){41, 40, "  return LUMI_success? LUMI_err : FAIL;\n"}) )
  CHECK(361, write(&(String){3, 2, "}\n"}) )
  CHECK(362, write(&(String){17, 16, "\nTEST_MAIN_FUNC\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeRoot__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeRoot__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeRoot_link_types, (void*)SyntaxTreeRoot_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeRoot_write, (void*)SyntaxTreeRoot_parse_if_common, (void*)SyntaxTreeRoot_parse_child, (void*)SyntaxTreeBranch_find_variable};
#endif


#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct ModuleMembers ModuleMembers;
#elif LUMI_STAGE == LUMI_TYPES(0)
struct ModuleMembers {
  String* name;
  NameMap* type_map;
  NameMap* enum_map;
  NameMap* variable_map;
  NameMap* function_map;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode ModuleMembers_init(ModuleMembers* self, String* name);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_ModuleMembers_init = "ModuleMembers.init";
#define LUMI_FUNC_NAME _func_name_ModuleMembers_init
Returncode ModuleMembers_init(ModuleMembers* self, String* name) {
  CHECK(373, string_new_copy(name, &(self->name)) )
  self->type_map = malloc(sizeof(NameMap));
  if (self->type_map == NULL) RAISE(374)
  *self->type_map = (NameMap){NULL, NULL};
  self->enum_map = malloc(sizeof(NameMap));
  if (self->enum_map == NULL) RAISE(375)
  *self->enum_map = (NameMap){NULL, NULL};
  self->variable_map = malloc(sizeof(NameMap));
  if (self->variable_map == NULL) RAISE(376)
  *self->variable_map = (NameMap){NULL, NULL};
  self->function_map = malloc(sizeof(NameMap));
  if (self->function_map == NULL) RAISE(377)
  *self->function_map = (NameMap){NULL, NULL};
  if (NULL != self->name) {
    CHECK(379, NameMap_add(glob->module_map, self->name, self) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode ModuleMembers_write_prefix(ModuleMembers* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_ModuleMembers_write_prefix = "ModuleMembers.write-prefix";
#define LUMI_FUNC_NAME _func_name_ModuleMembers_write_prefix
Returncode ModuleMembers_write_prefix(ModuleMembers* self) {
  CHECK(382, write_cname(self->name) )
  CHECK(383, write(&(String){4, 3, "_M_"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* Main function node in the syntax tree */
#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct SyntaxTreeMainFunction SyntaxTreeMainFunction;
#elif LUMI_STAGE == LUMI_TYPES(4)
struct SyntaxTreeMainFunction {
  SyntaxTreeFunction _base;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeMainFunction_parse_new(SyntaxTreeMainFunction* self, Char* end, SyntaxTreeMainFunction** new_node);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_parse_new = "SyntaxTreeMainFunction.parse-new";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeMainFunction_parse_new
Returncode SyntaxTreeMainFunction_parse_new(SyntaxTreeMainFunction* self, Char* end, SyntaxTreeMainFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeMainFunction));
  if ((*new_node) == NULL) RAISE(389)
  *(*new_node) = (SyntaxTreeMainFunction){SyntaxTreeMainFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, false, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeMainFunction__dtl;
  CHECK(390, SyntaxTreeMainFunction_parse((*new_node), &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeMainFunction_parse(SyntaxTreeMainFunction* self, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_parse = "SyntaxTreeMainFunction.parse";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeMainFunction_parse
Returncode SyntaxTreeMainFunction_parse(SyntaxTreeMainFunction* self, Char* end) {
  CHECK(393, SyntaxTreeFunction_init(&(self->_base)) )
  self->_base.my_module = glob->current_module;
  CHECK(395, string_new_copy(&(String){5, 4, "main"}, &(self->_base.name)) )
  self->_base.arguments = malloc(sizeof(FunctionArguments));
  if (self->_base.arguments == NULL) RAISE(396)
  *self->_base.arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->_base.arguments->_base._dtl = FunctionArguments__dtl;
  CHECK(397, FunctionArguments_init(self->_base.arguments) )
  CHECK(398, SyntaxTreeFunction_parse_body(&(self->_base), &((*end))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeMainFunction_write(SyntaxTreeMainFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_write = "SyntaxTreeMainFunction.write";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeMainFunction_write
Returncode SyntaxTreeMainFunction_write(SyntaxTreeMainFunction* self) {
  /* USER_MAIN_HEADER { */
  /*   `block...` */
  /* } */
  /* MAIN_FUNC */
  CHECK(405, write(&(String){18, 17, "\nUSER_MAIN_HEADER"}) )
  CHECK(406, SyntaxTreeFunction_write_block(&(self->_base)) )
  CHECK(407, write_post_func() )
  CHECK(408, write(&(String){12, 11, "\nMAIN_FUNC\n"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode SyntaxTreeMainFunction_write_block_body(SyntaxTreeMainFunction* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_write_block_body = "SyntaxTreeMainFunction.write-block-body";
#define LUMI_FUNC_NAME _func_name_SyntaxTreeMainFunction_write_block_body
Returncode SyntaxTreeMainFunction_write_block_body(SyntaxTreeMainFunction* self) {
  CHECK(411, (glob->root->global_init)->_base._base._base._base._dtl[4](glob->root->global_init) )
  CHECK(412, write_pre_func(&(self->_base)) )
  CHECK(413, write(&(String){2, 1, "\n"}) )
  CHECK(414, SyntaxTreeBlock_write_block_body(&(self->_base._base)) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func SyntaxTreeMainFunction__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func SyntaxTreeMainFunction__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeMainFunction_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeMainFunction_write_block_body, (void*)SyntaxTreeFunction_f_register_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct GlobalInit GlobalInit;
#elif LUMI_STAGE == LUMI_TYPES(4)
struct GlobalInit {
  SyntaxTreeFunction _base;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode GlobalInit_init(GlobalInit* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_GlobalInit_init = "GlobalInit.init";
#define LUMI_FUNC_NAME _func_name_GlobalInit_init
Returncode GlobalInit_init(GlobalInit* self) {
  CHECK(419, SyntaxTreeFunction_init(&(self->_base)) )
  self->_base._base.code_nodes = malloc(sizeof(List));
  if (self->_base._base.code_nodes == NULL) RAISE(420)
  *self->_base._base.code_nodes = (List){NULL, NULL};
  self->_base._base._base.variables = malloc(sizeof(List));
  if (self->_base._base._base.variables == NULL) RAISE(421)
  *self->_base._base._base.variables = (List){NULL, NULL};
  self->_base.arguments = malloc(sizeof(FunctionArguments));
  if (self->_base.arguments == NULL) RAISE(422)
  *self->_base.arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->_base.arguments->_base._dtl = FunctionArguments__dtl;
  CHECK(423, FunctionArguments_init(self->_base.arguments) )
  self->_base._base._base.indentation_spaces = 2;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode GlobalInit_write(GlobalInit* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_GlobalInit_write = "GlobalInit.write";
#define LUMI_FUNC_NAME _func_name_GlobalInit_write
Returncode GlobalInit_write(GlobalInit* self) {
  if (!(NULL != self->_base._base.code_nodes->first)) {
    return OK;
  }
  CHECK(429, SyntaxTreeNode_write_children(&(self->_base._base._base._base), self->_base._base._base.variables) )
  CHECK(430, write(&(String){21, 20, "#undef RETURN_ERROR\n"}) )
  CHECK(431, write(&(String){39, 38, "#define RETURN_ERROR return LUMI_err;\n"}) )
  CHECK(432, write(&(String){57, 56, "#define LUMI_FUNC_NAME \"global variable initialization\"\n"}) )
  CHECK(433, (self)->_base._base._base._base._dtl[9](self) )
  CHECK(434, write(&(String){23, 22, "#undef LUMI_FUNC_NAME\n"}) )
  CHECK(435, write(&(String){21, 20, "#undef RETURN_ERROR\n"}) )
  CHECK(436, write(&(String){39, 38, "#define RETURN_ERROR goto LUMI_cleanup"}) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
extern Func GlobalInit__dtl[];
#endif
#if LUMI_STAGE == LUMI_FUNCTIONS
Func GlobalInit__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)GlobalInit_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeBlock_write_block_body, (void*)SyntaxTreeFunction_f_register_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


#if LUMI_STAGE == LUMI_TYPEDEFS
typedef struct LineCount LineCount;
#elif LUMI_STAGE == LUMI_TYPES(0)
struct LineCount {
  String* filename;
  Int covered_index;
  Bool needs_cover;
  Array* line_needs_cover;
};
#endif
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode LineCount_init(LineCount* self);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_LineCount_init = "LineCount.init";
#define LUMI_FUNC_NAME _func_name_LineCount_init
Returncode LineCount_init(LineCount* self) {
  self->filename = glob->input_file_name;
  self->line_needs_cover = _new_array(glob->line_number + 1, sizeof(Bool));
  if (self->line_needs_cover == NULL) RAISE(447)
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* proxy write function to be mocked on unit-tests */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode write_global(String* text);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_write_global = "write-global";
#define LUMI_FUNC_NAME _func_name_write_global
Returncode write_global(String* text) {
  CHECK(452, write(text) )
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
#include "syntax-tree/branch.c"
#include "syntax-tree/code.c"
#include "syntax-tree/code-flow.c"
#include "syntax-tree/node.c"
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
