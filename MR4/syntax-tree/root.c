#ifndef MR_MAINFILE
#define MR_MAINFILE "syntax-tree/root.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file21_name = "syntax-tree/root.3.mr";
#endif
#define MR_FILE_NAME _mr_file21_name

/* MR4 compiler - Syntax tree root */

#if MR_STAGE == MR_TYPEDEFS
typedef struct GlobalNodes GlobalNodes;
#elif MR_STAGE == MR_TYPES(3)
struct GlobalNodes {
  SyntaxTreeNamespace _base;
  List* types;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode GlobalNodes_init(GlobalNodes* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_GlobalNodes_init = "GlobalNodes.init";
#define MR_FUNC_NAME _func_name_GlobalNodes_init
Returncode GlobalNodes_init(GlobalNodes* self) {
  CHECK(7, SyntaxTreeNamespace_init(&(self->_base)) )
  self->types = malloc(sizeof(List));
  if (self->types == NULL) RAISE(8)
  *self->types = (List){NULL, NULL};
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func GlobalNodes__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func GlobalNodes__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeNamespace_link_types, (void*)SyntaxTreeNamespace_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeBranch_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBranch_parse_child, (void*)SyntaxTreeBranch_find_variable};
#endif


/* The syntax tree root */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeRoot SyntaxTreeRoot;
#elif MR_STAGE == MR_TYPES(4)
struct SyntaxTreeRoot {
  GlobalNodes _base;
  List* enums;
  List* constants;
  List* modules;
  String* output_file_name;
  SyntaxTreeMainFunction* main_function;
  GlobalInit* global_init;
  Array* line_counts;
  Bool is_library;
  Bool testing;
/*  write C file in this order:
  1. type declarations
  2. type structs (ordered by depth)
  3. function declarations
  4. global variables
  5. function bodies
  6. main function
   */};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_init(SyntaxTreeRoot* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_init = "SyntaxTreeRoot.init";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_init
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
  *self->global_init = (GlobalInit){GlobalInit__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  self->global_init->_base._base._base._base._dtl = GlobalInit__dtl;
  CHECK(29, GlobalInit_init(self->global_init) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_parse(SyntaxTreeRoot* self, Array* argv);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_parse = "SyntaxTreeRoot.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_parse
Returncode SyntaxTreeRoot_parse(SyntaxTreeRoot* self, Array* argv) {
  if (argv->length < 3) {
    CHECK(33, print(&(String){59, 58, "usage: mr-4compiler OUTPUT-C-FILE-NAME INPUT-MR3-FILES...\n"}) )
    RAISE(34)
  }
  
  Int tested_files = 0;
  {int n; for (n = (2); n < (argv->length); ++n) {
    if ((n) < 0 || (n) >= (argv)->length) RAISE(38)
    Bool _Bool104;
    CHECK(38, String_equal((&(((String*)((argv)->values))[n])), &(String){6, 5, "-test"}, &(_Bool104)) )
    if (_Bool104) {
      self->testing = true;
      if (!(false)) break;
    }
    tested_files += 1;
  }}
  if (self->testing && tested_files > 0) {
    self->line_counts = _new_array(tested_files, sizeof(LineCount));
    if (self->line_counts == NULL) RAISE(43)
    glob->is_in_testing = true;
  }
  
  if ((1) < 0 || (1) >= (argv)->length) RAISE(46)
  self->output_file_name = (&(((String*)((argv)->values))[1]));
  {int n; for (n = (2); n < (argv->length); ++n) {
    if ((n) < 0 || (n) >= (argv)->length) RAISE(48)
    glob->input_file_name = (&(((String*)((argv)->values))[n]));
    Bool _Bool105;
    CHECK(49, String_equal(glob->input_file_name, &(String){6, 5, "-test"}, &(_Bool105)) )
    if (_Bool105) {
      glob->is_in_testing = false;
    }
    else {
      glob->input_file_index = n - 2;
      glob->line_number = 1;
      glob->current_module = NULL;
      CHECK(55, file_open(glob->input_file_name, true, &(glob->input_file)) )
      
      Char _Char106;
      CHECK(57, SyntaxTreeBranch_parse_children(&(self->_base._base._base), NULL, NULL, &(_Char106)) )
      
      if (glob->input_buffer->length > 0 || glob->input_spaces > 0) {
        CHECK(60, SyntaxTreeNode_set_location(&(self->_base._base._base._base)) )
        CHECK(61, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base._base), &(String){28, 27, "no new-line before file end"}) )
      }
      
      CHECK(63, file_close(glob->input_file) )
      if (glob->is_in_testing) {
        if ((n - 2) < 0 || (n - 2) >= (self->line_counts)->length) RAISE(65)
        CHECK(65, LineCount_init((&(((LineCount*)((self->line_counts)->values))[n - 2]))) )
      }
    }
  }}
  
  glob->current_module = NULL;
  self->_base._base._base._base.line_number = 0;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_parse_if_common(SyntaxTreeRoot* self, String* keyword, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, Bool* is_parsed);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_parse_if_common = "SyntaxTreeRoot.parse-if-common";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_parse_if_common
Returncode SyntaxTreeRoot_parse_if_common(SyntaxTreeRoot* self, String* keyword, TypeData* parent_type, SyntaxTreeBlock* parent_block, Char* end, Bool* is_parsed) {
  (*is_parsed) = false;
  if (!(NULL != glob->current_module)) {
    Bool _Bool107;
    CHECK(78, String_equal(keyword, &(String){7, 6, "module"}, &(_Bool107)) )
    if (_Bool107) {
      if ((*end) != ' ') {
        CHECK(80, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){35, 34, "expected space after \"module\", got"}, (*end)) )
      }
      String* name = NULL;
      Int _Int108;
      CHECK(83, read_until(&(String){1, 0, ""}, false, &(name), &((*end)), &(_Int108)) )
      Bool _Bool109;
      CHECK(84, f_is_legal_name(name, NAME_DEFAULT, &(_Bool109)) )
      if (!_Bool109) {
        CHECK(85, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){20, 19, "illegal module name"}, name) )
      }
      SyntaxTreeVariable* _SyntaxTreeVariable110;
      CHECK(86, NameMap_find(glob->global_module->variable_map, name, (void**)&(_SyntaxTreeVariable110)) )
      if (NULL != _SyntaxTreeVariable110) {
        CHECK(87, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){31, 30, "module name overrides variable"}, name) )
      }
      SyntaxTreeFunction* _SyntaxTreeFunction111;
      CHECK(88, NameMap_find(glob->global_module->function_map, name, (void**)&(_SyntaxTreeFunction111)) )
      if (NULL != _SyntaxTreeFunction111) {
        CHECK(89, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){31, 30, "module name overrides function"}, name) )
      }
      CHECK(90, NameMap_find(glob->module_map, name, (void**)&(glob->current_module)) )
      if (!(NULL != glob->current_module)) {
        ModuleMembers* module_members = malloc(sizeof(ModuleMembers));
        if (module_members == NULL) RAISE(91)
        *module_members = (ModuleMembers){NULL, NULL, NULL, NULL, NULL};
        CHECK(92, ModuleMembers_init(module_members, name) )
        glob->current_module = module_members;
        CHECK(94, List_add(self->modules, module_members) )
      }
      (*is_parsed) = true;
      return OK;
    }
    else {
      CHECK(98, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){26, 25, "no \"module\" in file start"}, keyword) )
    }
  }
  CHECK(99, SyntaxTreeBranch_parse_if_common(&(self->_base._base._base), keyword, parent_type, parent_block, &((*end)), &((*is_parsed))) )
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
  Bool _Bool112;
  CHECK(103, SyntaxTreeNamespace_parse_if_function(&(self->_base._base), keyword, NULL, &((*end)), &(_Bool112)) )
  if (_Bool112) {
    return OK;
  }
  
  Bool _Bool113;
  CHECK(106, String_equal(keyword, &(String){6, 5, "const"}, &(_Bool113)) )
  if (_Bool113) {
    if ((*end) != ' ') {
      CHECK(108, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){34, 33, "expected space after \"const\", got"}, (*end)) )
    }
    SyntaxTreeConstant* _SyntaxTreeConstant114;
    CHECK(110, SyntaxTreeConstant_parse_new(NULL, &((*end)), &(_SyntaxTreeConstant114)) )
    CHECK(110, List_add(self->_base._base._base.variables, &(_SyntaxTreeConstant114->_base)) )
    
  }
  else {
    Bool _Bool115;
    CHECK(112, String_equal(keyword, &(String){7, 6, "struct"}, &(_Bool115)) )
    if (_Bool115) {
      if ((*end) != ' ') {
        CHECK(114, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){35, 34, "expected space after \"struct\", got"}, (*end)) )
      }
      TypeData* _TypeData116;
      CHECK(116, TypeData_parse_new(NULL, false, &((*end)), &(_TypeData116)) )
      CHECK(116, List_add(self->_base.types, _TypeData116) )
      
    }
    else {
      Bool _Bool117;
      CHECK(118, String_equal(keyword, &(String){6, 5, "class"}, &(_Bool117)) )
      if (_Bool117) {
        if ((*end) != ' ') {
          CHECK(120, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){34, 33, "expected space after \"class\", got"}, (*end)) )
        }
        TypeData* _TypeData118;
        CHECK(122, TypeData_parse_new(NULL, true, &((*end)), &(_TypeData118)) )
        CHECK(122, List_add(self->_base.types, _TypeData118) )
        
      }
      else {
        Bool _Bool119;
        CHECK(124, String_equal(keyword, &(String){5, 4, "enum"}, &(_Bool119)) )
        if (_Bool119) {
          if ((*end) != ' ') {
            CHECK(126, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){33, 32, "expected space after \"enum\", got"}, (*end)) )
          }
          EnumData* _EnumData120;
          CHECK(128, EnumData_parse_new(NULL, &((*end)), &(_EnumData120)) )
          CHECK(128, List_add(self->enums, _EnumData120) )
          
        }
        else {
          Bool _Bool121;
          CHECK(130, String_equal(keyword, &(String){5, 4, "main"}, &(_Bool121)) )
          if (_Bool121) {
            if ((*end) != '\n') {
              CHECK(132, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){36, 35, "expected new-line after \"main\", got"}, (*end)) )
            }
            CHECK(134, SyntaxTreeMainFunction_parse_new(NULL, &((*end)), &(self->main_function)) )
            
          }
          else {
            Bool _Bool122;
            CHECK(137, String_equal(keyword, &(String){7, 6, "native"}, &(_Bool122)) )
            if (_Bool122) {
              if ((*end) != ' ') {
                CHECK(139, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){35, 34, "expected space after \"native\", got"}, (*end)) )
              }
              CHECK(141, parse_native(self, &((*end))) )
              
            }
            else {
              Bool _Bool123;
              CHECK(143, String_equal(keyword, &(String){5, 4, "test"}, &(_Bool123)) )
              if (_Bool123) {
                if ((*end) != ' ') {
                  CHECK(145, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){33, 32, "expected space after \"test\", got"}, (*end)) )
                }
                SyntaxTreeTestFunction* _SyntaxTreeTestFunction124;
                CHECK(147, SyntaxTreeTestFunction_parse_new(NULL, &((*end)), &(_SyntaxTreeTestFunction124)) )
                CHECK(147, List_add(self->_base._base.functions, &(_SyntaxTreeTestFunction124->_base)) )
                
              }
              else {
                Bool _Bool125;
                CHECK(150, String_equal(keyword, &(String){5, 4, "mock"}, &(_Bool125)) )
                if (_Bool125) {
                  if ((*end) != ' ') {
                    CHECK(152, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base._base), &(String){33, 32, "expected space after \"mock\", got"}, (*end)) )
                  }
                  SyntaxTreeMockFunction* _SyntaxTreeMockFunction126;
                  CHECK(154, SyntaxTreeMockFunction_parse_new(NULL, &((*end)), &(_SyntaxTreeMockFunction126)) )
                  CHECK(154, List_add(self->_base._base.functions, &(_SyntaxTreeMockFunction126->_base)) )
                  
                }
                else {
                  CHECK(158, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base._base), &(String){16, 15, "unknown keyword"}, keyword) )
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
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_link_types(SyntaxTreeRoot* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_link_types = "SyntaxTreeRoot.link-types";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_link_types
Returncode SyntaxTreeRoot_link_types(SyntaxTreeRoot* self) {
  RAISE(161)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_analyze(SyntaxTreeRoot* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_analyze = "SyntaxTreeRoot.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_analyze
Returncode SyntaxTreeRoot_analyze(SyntaxTreeRoot* self) {
  CHECK(164, SyntaxTreeRoot_m_order_types(self) )
  CHECK(165, SyntaxTreeNamespace_link_types(&(self->_base._base)) )
  CHECK(166, SyntaxTreeNode_link_children_types(&(self->_base._base._base._base), self->_base.types) )
  CHECK(167, (self->global_init)->_base._base._base._base._dtl[1](self->global_init) )
  if (NULL != self->main_function) {
    CHECK(169, (self->main_function)->_base._base._base._base._dtl[1](self->main_function) )
  }
  CHECK(170, SyntaxTreeNamespace_analyze(&(self->_base._base)) )
  CHECK(171, SyntaxTreeNode_analyze_children(&(self->_base._base._base._base), self->_base.types) )
  CHECK(172, (self->global_init)->_base._base._base._base._dtl[2](self->global_init) )
  if (self->testing) {
    if (!(NULL != glob->test_functions->first)) {
      CHECK(175, print(&(String){39, 38, "General code error: no test functions\n"}) )
      RAISE(176)
    }
  }
  else {
    if (NULL != self->main_function) {
      CHECK(178, (self->main_function)->_base._base._base._base._dtl[2](self->main_function) )
    }
    else {
      if (!self->is_library) {
        CHECK(180, print(&(String){38, 37, "General code error: no main function\n"}) )
        RAISE(181)
      }
    }
  }
  CHECK(182, SyntaxTreeNode_m_order_children_constants(&(self->_base._base._base._base), self->_base._base._base.variables, self->constants) )
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
  if (ordered_list == NULL) RAISE(185)
  *ordered_list = (List){NULL, NULL};
  while (true) {
    TypeData* type_data = NULL;
    CHECK(188, List_pop(self->_base.types, (void**)&(type_data)) )
    if (!(NULL != type_data)) break;
    CHECK(190, TypeData_m_order_bases(type_data, ordered_list) )
  }
  free(self->_base.types);
  self->_base.types = ordered_list;
  return OK;
}
#undef MR_FUNC_NAME
#endif/*  write C file in this order:
  1. type declarations
  2. type structs (ordered by depth)
  3. function declarations
  4. global variables
  5. function bodies
  6. main function
   */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_write(SyntaxTreeRoot* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_write = "SyntaxTreeRoot.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_write
Returncode SyntaxTreeRoot_write(SyntaxTreeRoot* self) {
  CHECK(203, file_open(self->output_file_name, false, &(glob->output_file)) )
  
  CHECK(205, write_global(&(String){19, 18, "#include \"mr.4.h\"\n"}) )
  
  CHECK(207, write_global(&(String){27, 26, "\n\n/* types declaration */\n"}) )
  TypeDeclarationWriter* type_declaration_writer = &(TypeDeclarationWriter){TypeDeclarationWriter__dtl};
  type_declaration_writer->_base._dtl = TypeDeclarationWriter__dtl;
  CHECK(209, SyntaxTreeRoot_write_for_type(self, &(type_declaration_writer->_base)) )
  
  /* will write Enums */
  CHECK(212, write_global(&(String){15, 14, "\n\n/* Enums */\n"}) )
  CHECK(213, SyntaxTreeNode_write_children(&(self->_base._base._base._base), self->enums) )
  
  /* will write constants */
  CHECK(216, write_global(&(String){19, 18, "\n\n/* constants */\n"}) )
  CHECK(217, SyntaxTreeNode_write_children(&(self->_base._base._base._base), self->constants) )
  
  /* will write type structures */
  CHECK(220, write_global(&(String){22, 21, "\n\n/* types struct */\n"}) )
  CHECK(221, SyntaxTreeNode_write_children(&(self->_base._base._base._base), self->_base.types) )
  
  CHECK(223, write_global(&(String){35, 34, "\n\n/* types methods declaration */\n"}) )
  TypeMethodsDeclarationWriter* type_methods_declaration_writer = &(TypeMethodsDeclarationWriter){TypeMethodsDeclarationWriter__dtl};
  type_methods_declaration_writer->_base._dtl = TypeMethodsDeclarationWriter__dtl;
  CHECK(225, SyntaxTreeRoot_write_for_type(self, &(type_methods_declaration_writer->_base)) )
  
  CHECK(227, write_global(&(String){38, 37, "\n\n/* global functions declaration */\n"}) )
  CHECK(228, SyntaxTreeNamespace_write_functions_declaration(&(self->_base._base)) )
  
  CHECK(230, write_global(&(String){32, 31, "\n\n/* types global variables */\n"}) )
  TypeGlobalWriter* type_global_writer = &(TypeGlobalWriter){TypeGlobalWriter__dtl};
  type_global_writer->_base._dtl = TypeGlobalWriter__dtl;
  CHECK(232, SyntaxTreeRoot_write_for_type(self, &(type_global_writer->_base)) )
  
  /* will write global variables */
  CHECK(235, write_global(&(String){26, 25, "\n\n/* global variables */\n"}) )
  CHECK(236, SyntaxTreeNode_write_children(&(self->_base._base._base._base), self->_base._base._base.variables) )
  
  if (NULL != self->line_counts) {
    CHECK(239, SyntaxTreeRoot_write_test_coverage_data(self) )
  }
  
  CHECK(241, write_global(&(String){28, 27, "\n\n/* types methods body */\n"}) )
  TypeMethodsBodyWriter* type_methods_body_writer = &(TypeMethodsBodyWriter){TypeMethodsBodyWriter__dtl};
  type_methods_body_writer->_base._dtl = TypeMethodsBodyWriter__dtl;
  CHECK(243, SyntaxTreeRoot_write_for_type(self, &(type_methods_body_writer->_base)) )
  
  /* will write global functions bodies */
  CHECK(246, write_global(&(String){31, 30, "\n\n/* global functions body */\n"}) )
  CHECK(247, SyntaxTreeNode_write_children(&(self->_base._base._base._base), self->_base._base.functions) )
  
  /* write main function */
  if (self->testing ||  NULL !=  self->main_function) {
    if (!glob->is_new_mocked) {
      CHECK(252, write(&(String){61, 60, "\n\nReturncode new_Mock(Bool* allocate_success) { return OK; }"}) )
    }
    if (!glob->is_delete_mocked) {
      CHECK(255, write(&(String){50, 49, "\n\nReturncode delete_Mock(Ref self) { return OK; }"}) )
    }
  }
  if (self->testing) {
    CHECK(257, SyntaxTreeRoot_write_test_main(self) )
  }
  else {
    if (NULL != self->main_function) {
      CHECK(259, write_global(&(String){23, 22, "\n\n/* main function */\n"}) )
      CHECK(260, (self->main_function)->_base._base._base._base._dtl[4](self->main_function) )
    }
  }
  
  CHECK(262, file_close(glob->output_file) )
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
  ListNode* child = self->_base.types->first;
  while (true) {
    if (!(NULL != child)) break;
    CHECK(268, (((TypeData*)(child->item)))->_base._base._base._dtl[12](((TypeData*)(child->item)), type_writer) )
    child = child->next;
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_write_test_coverage_data(SyntaxTreeRoot* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_write_test_coverage_data = "SyntaxTreeRoot.write-test-coverage-data";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_write_test_coverage_data
Returncode SyntaxTreeRoot_write_test_coverage_data(SyntaxTreeRoot* self) {
  {int n; for (n = (0); n < (self->line_counts->length); ++n) {
    if ((n) < 0 || (n) >= (self->line_counts)->length) RAISE(273)
    LineCount* line_count = (&(((LineCount*)((self->line_counts)->values))[n]));
    CHECK(274, write(&(String){13, 12, "\nint MR_file"}) )
    CHECK(275, write_int(n) )
    CHECK(276, write(&(String){13, 12, "_line_count["}) )
    CHECK(277, write_int(line_count->line_needs_cover->length) )
    CHECK(278, write(&(String){9, 8, "] = {\n  "}) )
    Int mod = 0;
    {int i; for (i = (0); i < (line_count->line_needs_cover->length); ++i) {
      if (i > 0) {
        CHECK(282, write(&(String){2, 1, ","}) )
      }
      if (mod == 25) {
        CHECK(284, write(&(String){4, 3, "\n  "}) )
        mod = 1;
      }
      else {
        mod += 1;
      }
      if ((i) < 0 || (i) >= (line_count->line_needs_cover)->length) RAISE(288)
      if ((((Bool*)((line_count->line_needs_cover)->values))[i])) {
        CHECK(289, write(&(String){3, 2, " 0"}) )
      }
      else {
        CHECK(291, write(&(String){3, 2, "-1"}) )
      }
    }}
    CHECK(292, write(&(String){4, 3, "\n};"}) )
  }}
  CHECK(293, write(&(String){33, 32, "\nFile_Coverage MR_file_coverage["}) )
  CHECK(294, write_int(self->line_counts->length) )
  CHECK(295, write(&(String){6, 5, "] = {"}) )
  {int n; for (n = (0); n < (self->line_counts->length); ++n) {
    if ((n) < 0 || (n) >= (self->line_counts)->length) RAISE(297)
    LineCount* line_count = (&(((LineCount*)((self->line_counts)->values))[n]));
    if (n > 0) {
      CHECK(299, write(&(String){2, 1, ","}) )
    }
    CHECK(300, write(&(String){6, 5, "\n  {\""}) )
    CHECK(301, write(line_count->filename) )
    CHECK(302, write(&(String){4, 3, "\", "}) )
    CHECK(303, write_int(line_count->line_needs_cover->length) )
    CHECK(304, write(&(String){10, 9, ", MR_file"}) )
    CHECK(305, write_int(n) )
    CHECK(306, write(&(String){13, 12, "_line_count}"}) )
  }}
  CHECK(307, write(&(String){5, 4, "\n};\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_write_test_main(SyntaxTreeRoot* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_write_test_main = "SyntaxTreeRoot.write-test-main";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_write_test_main
Returncode SyntaxTreeRoot_write_test_main(SyntaxTreeRoot* self) {
  CHECK(310, write(&(String){21, 20, "\nUSER_MAIN_HEADER {\n"}) )
  CHECK(311, write(&(String){27, 26, "  Bool MR_success = true;\n"}) )
  CHECK(312, (self->global_init)->_base._base._base._base._dtl[4](self->global_init) )
  CHECK(313, write(&(String){2, 1, "\n"}) )
  NameMapNode* node = glob->test_functions->first;
  while (true) {
    /* MR_success &= MR_run_test("`test-func.name`", `test-func`); */
    CHECK(317, write(&(String){30, 29, "  MR_success &= MR_run_test(\""}) )
    CHECK(318, write(((SyntaxTreeTestFunction*)(node->value))->_base.name) )
    CHECK(319, write(&(String){4, 3, "\", "}) )
    CHECK(320, SyntaxTreeFunction_write_cname(&(((SyntaxTreeTestFunction*)(node->value))->_base)) )
    CHECK(321, write(&(String){4, 3, ");\n"}) )
    node = node->next;
    if (!(NULL != node)) break;
  }
  if (NULL != self->line_counts) {
    CHECK(325, write(&(String){52, 51, "  MR_success &= MR_test_coverage(MR_file_coverage, "}) )
    CHECK(326, write_int(self->line_counts->length) )
    CHECK(327, write(&(String){4, 3, ");\n"}) )
  }
  CHECK(328, write(&(String){33, 32, "  return MR_success? OK : FAIL;\n"}) )
  CHECK(329, write(&(String){3, 2, "}\n"}) )
  CHECK(330, write(&(String){17, 16, "\nTEST_MAIN_FUNC\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeRoot__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeRoot__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeRoot_link_types, (void*)SyntaxTreeRoot_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeRoot_write, (void*)SyntaxTreeRoot_parse_if_common, (void*)SyntaxTreeRoot_parse_child, (void*)SyntaxTreeBranch_find_variable};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct ModuleMembers ModuleMembers;
#elif MR_STAGE == MR_TYPES(0)
struct ModuleMembers {
  String* name;
  NameMap* type_map;
  NameMap* enum_map;
  NameMap* variable_map;
  NameMap* function_map;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode ModuleMembers_init(ModuleMembers* self, String* name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_ModuleMembers_init = "ModuleMembers.init";
#define MR_FUNC_NAME _func_name_ModuleMembers_init
Returncode ModuleMembers_init(ModuleMembers* self, String* name) {
  CHECK(341, string_new_copy(name, &(self->name)) )
  self->type_map = malloc(sizeof(NameMap));
  if (self->type_map == NULL) RAISE(342)
  *self->type_map = (NameMap){NULL, NULL};
  self->enum_map = malloc(sizeof(NameMap));
  if (self->enum_map == NULL) RAISE(343)
  *self->enum_map = (NameMap){NULL, NULL};
  self->variable_map = malloc(sizeof(NameMap));
  if (self->variable_map == NULL) RAISE(344)
  *self->variable_map = (NameMap){NULL, NULL};
  self->function_map = malloc(sizeof(NameMap));
  if (self->function_map == NULL) RAISE(345)
  *self->function_map = (NameMap){NULL, NULL};
  if (NULL != self->name) {
    CHECK(347, NameMap_add(glob->module_map, self->name, self) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode ModuleMembers_write_prefix(ModuleMembers* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_ModuleMembers_write_prefix = "ModuleMembers.write-prefix";
#define MR_FUNC_NAME _func_name_ModuleMembers_write_prefix
Returncode ModuleMembers_write_prefix(ModuleMembers* self) {
  CHECK(350, write_cname(self->name) )
  CHECK(351, write(&(String){4, 3, "_M_"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Main function node in the syntax tree */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeMainFunction SyntaxTreeMainFunction;
#elif MR_STAGE == MR_TYPES(4)
struct SyntaxTreeMainFunction {
  SyntaxTreeFunction _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMainFunction_parse_new(SyntaxTreeMainFunction* self, Char* end, SyntaxTreeMainFunction** new_node);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_parse_new = "SyntaxTreeMainFunction.parse-new";
#define MR_FUNC_NAME _func_name_SyntaxTreeMainFunction_parse_new
Returncode SyntaxTreeMainFunction_parse_new(SyntaxTreeMainFunction* self, Char* end, SyntaxTreeMainFunction** new_node) {
  (*new_node) = malloc(sizeof(SyntaxTreeMainFunction));
  if ((*new_node) == NULL) RAISE(357)
  *(*new_node) = (SyntaxTreeMainFunction){SyntaxTreeMainFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeMainFunction__dtl;
  CHECK(358, SyntaxTreeMainFunction_parse((*new_node), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMainFunction_parse(SyntaxTreeMainFunction* self, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_parse = "SyntaxTreeMainFunction.parse";
#define MR_FUNC_NAME _func_name_SyntaxTreeMainFunction_parse
Returncode SyntaxTreeMainFunction_parse(SyntaxTreeMainFunction* self, Char* end) {
  CHECK(361, SyntaxTreeFunction_init(&(self->_base)) )
  self->_base.my_module = glob->current_module;
  CHECK(363, string_new_copy(&(String){5, 4, "main"}, &(self->_base.name)) )
  self->_base.arguments = malloc(sizeof(FunctionArguments));
  if (self->_base.arguments == NULL) RAISE(364)
  *self->_base.arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->_base.arguments->_base._dtl = FunctionArguments__dtl;
  CHECK(365, FunctionArguments_init(self->_base.arguments) )
  CHECK(366, SyntaxTreeFunction_parse_body(&(self->_base), &((*end))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMainFunction_write(SyntaxTreeMainFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_write = "SyntaxTreeMainFunction.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeMainFunction_write
Returncode SyntaxTreeMainFunction_write(SyntaxTreeMainFunction* self) {
  /* USER_MAIN_HEADER { */
  /*   `block...` */
  /* } */
  /* MAIN_FUNC */
  CHECK(373, write(&(String){18, 17, "\nUSER_MAIN_HEADER"}) )
  CHECK(374, SyntaxTreeFunction_write_block(&(self->_base)) )
  CHECK(375, write_post_func() )
  CHECK(376, write(&(String){12, 11, "\nMAIN_FUNC\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeMainFunction_write_block_body(SyntaxTreeMainFunction* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeMainFunction_write_block_body = "SyntaxTreeMainFunction.write-block-body";
#define MR_FUNC_NAME _func_name_SyntaxTreeMainFunction_write_block_body
Returncode SyntaxTreeMainFunction_write_block_body(SyntaxTreeMainFunction* self) {
  CHECK(379, (glob->root->global_init)->_base._base._base._base._dtl[4](glob->root->global_init) )
  CHECK(380, write_pre_func(&(self->_base)) )
  CHECK(381, write(&(String){2, 1, "\n"}) )
  CHECK(382, SyntaxTreeBlock_write_block_body(&(self->_base._base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeMainFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeMainFunction__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)SyntaxTreeMainFunction_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeMainFunction_write_block_body, (void*)SyntaxTreeFunction_f_register_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct GlobalInit GlobalInit;
#elif MR_STAGE == MR_TYPES(4)
struct GlobalInit {
  SyntaxTreeFunction _base;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode GlobalInit_init(GlobalInit* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_GlobalInit_init = "GlobalInit.init";
#define MR_FUNC_NAME _func_name_GlobalInit_init
Returncode GlobalInit_init(GlobalInit* self) {
  CHECK(387, SyntaxTreeFunction_init(&(self->_base)) )
  self->_base._base.code_nodes = malloc(sizeof(List));
  if (self->_base._base.code_nodes == NULL) RAISE(388)
  *self->_base._base.code_nodes = (List){NULL, NULL};
  self->_base._base._base.variables = malloc(sizeof(List));
  if (self->_base._base._base.variables == NULL) RAISE(389)
  *self->_base._base._base.variables = (List){NULL, NULL};
  self->_base.arguments = malloc(sizeof(FunctionArguments));
  if (self->_base.arguments == NULL) RAISE(390)
  *self->_base.arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->_base.arguments->_base._dtl = FunctionArguments__dtl;
  CHECK(391, FunctionArguments_init(self->_base.arguments) )
  self->_base._base._base.indentation_spaces = 2;
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode GlobalInit_write(GlobalInit* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_GlobalInit_write = "GlobalInit.write";
#define MR_FUNC_NAME _func_name_GlobalInit_write
Returncode GlobalInit_write(GlobalInit* self) {
  if (!(NULL != self->_base._base.code_nodes->first)) {
    return OK;
  }
  CHECK(397, SyntaxTreeNode_write_children(&(self->_base._base._base._base), self->_base._base._base.variables) )
  CHECK(398, write(&(String){21, 20, "#undef RETURN_ERROR\n"}) )
  CHECK(399, write(&(String){43, 42, "#define RETURN_ERROR(value) return value;\n"}) )
  CHECK(400, write(&(String){55, 54, "#define MR_FUNC_NAME \"global variable initialization\"\n"}) )
  CHECK(401, (self)->_base._base._base._base._dtl[9](self) )
  CHECK(402, write(&(String){21, 20, "#undef MR_FUNC_NAME\n"}) )
  CHECK(403, write(&(String){21, 20, "#undef RETURN_ERROR\n"}) )
  CHECK(404, write(&(String){60, 59, "#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func GlobalInit__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func GlobalInit__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeNode_m_order_constants, (void*)GlobalInit_write, (void*)SyntaxTreeBranch_parse_if_common, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeBlock_write_block_body, (void*)SyntaxTreeFunction_f_register_name, (void*)SyntaxTreeFunction_write_declaration};
#endif


#if MR_STAGE == MR_TYPEDEFS
typedef struct LineCount LineCount;
#elif MR_STAGE == MR_TYPES(0)
struct LineCount {
  String* filename;
  Array* line_needs_cover;
};
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode LineCount_init(LineCount* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_LineCount_init = "LineCount.init";
#define MR_FUNC_NAME _func_name_LineCount_init
Returncode LineCount_init(LineCount* self) {
  self->filename = glob->input_file_name;
  self->line_needs_cover = _new_array(glob->line_number + 1, sizeof(Bool));
  if (self->line_needs_cover == NULL) RAISE(413)
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* proxy write function to be mocked on unit-tests */
#if MR_STAGE == MR_DECLARATIONS
Returncode write_global(String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_global = "write-global";
#define MR_FUNC_NAME _func_name_write_global
Returncode write_global(String* text) {
  CHECK(418, write(text) )
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
