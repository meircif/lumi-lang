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

/* The syntax tree root */
#if MR_STAGE == MR_TYPEDEFS
typedef struct SyntaxTreeRoot SyntaxTreeRoot;
#elif MR_STAGE == MR_TYPES(3)
struct SyntaxTreeRoot {
  SyntaxTreeNamespace _base;
  List* types;
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
  CHECK(14, SyntaxTreeNamespace_init(&(self->_base)) )
  self->types = malloc(sizeof(List));
  if (self->types == NULL) RAISE(15)
  *self->types = (List){NULL, NULL};
  self->global_init = malloc(sizeof(GlobalInit));
  if (self->global_init == NULL) RAISE(16)
  *self->global_init = (GlobalInit){GlobalInit__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  self->global_init->_base._base._base._base._dtl = GlobalInit__dtl;
  CHECK(17, GlobalInit_init(self->global_init) )
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
    CHECK(21, print(&(String){58, 57, "usage: mr-4compiler OUTPUT-C-FILE-NAME INPUT-MR3-FILES..."}) )
    RAISE(22)
  }
  
  Int tested_files = 0;
  {int n; for (n = (2); n < (argv->length); ++n) {
    if ((n) < 0 || (n) >= (argv)->length) RAISE(26)
    Bool _Bool98;
    CHECK(26, String_equal((&(((String*)((argv)->values))[n])), &(String){6, 5, "-test"}, &(_Bool98)) )
    if (_Bool98) {
      self->testing = true;
      if (!(false)) break;
    }
    tested_files += 1;
  }}
  if (self->testing && tested_files > 0) {
    self->line_counts = _new_array(tested_files, sizeof(LineCount));
    if (self->line_counts == NULL) RAISE(31)
    glob->is_in_testing = true;
  }
  
  if ((1) < 0 || (1) >= (argv)->length) RAISE(34)
  self->output_file_name = (&(((String*)((argv)->values))[1]));
  {int n; for (n = (2); n < (argv->length); ++n) {
    if ((n) < 0 || (n) >= (argv)->length) RAISE(36)
    glob->input_file_name = (&(((String*)((argv)->values))[n]));
    glob->input_file_index = n - 2;
    Bool _Bool99;
    CHECK(38, String_equal(glob->input_file_name, &(String){6, 5, "-test"}, &(_Bool99)) )
    if (_Bool99) {
      glob->is_in_testing = false;
    }
    else {
      glob->line_number = 1;
      CHECK(42, file_open(glob->input_file_name, true, &(glob->input_file)) )
      
      Char _Char100;
      CHECK(44, SyntaxTreeBranch_parse_children(&(self->_base._base), NULL, NULL, &(_Char100)) )
      
      if (glob->input_buffer->length > 0 || glob->input_spaces > 0) {
        CHECK(47, SyntaxTreeNode_set_location(&(self->_base._base._base)) )
        CHECK(48, SyntaxTreeNode_m_syntax_error_msg(&(self->_base._base._base), &(String){28, 27, "no new-line before file end"}) )
      }
      
      CHECK(50, file_close(glob->input_file) )
      if (glob->is_in_testing) {
        if ((n - 2) < 0 || (n - 2) >= (self->line_counts)->length) RAISE(52)
        CHECK(52, LineCount_init((&(((LineCount*)((self->line_counts)->values))[n - 2]))) )
      }
    }
  }}
  
  if ((2) < 0 || (2) >= (argv)->length) RAISE(54)
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
  Bool _Bool101;
  CHECK(58, SyntaxTreeNamespace_parse_if_function(&(self->_base), keyword, NULL, &((*end)), &(_Bool101)) )
  if (_Bool101) {
    return OK;
  }
  
  Bool _Bool102;
  CHECK(61, String_equal(keyword, &(String){7, 6, "struct"}, &(_Bool102)) )
  if (_Bool102) {
    if ((*end) != ' ') {
      CHECK(63, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){35, 34, "expected space after \"struct\", got"}, (*end)) )
    }
    TypeData* _TypeData103;
    CHECK(65, TypeData_parse_new(NULL, false, &((*end)), &(_TypeData103)) )
    CHECK(65, List_add(self->types, _TypeData103) )
    
  }
  else {
    Bool _Bool104;
    CHECK(68, String_equal(keyword, &(String){6, 5, "class"}, &(_Bool104)) )
    if (_Bool104) {
      if ((*end) != ' ') {
        CHECK(70, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){34, 33, "expected space after \"class\", got"}, (*end)) )
      }
      TypeData* _TypeData105;
      CHECK(72, TypeData_parse_new(NULL, true, &((*end)), &(_TypeData105)) )
      CHECK(72, List_add(self->types, _TypeData105) )
      
    }
    else {
      Bool _Bool106;
      CHECK(75, String_equal(keyword, &(String){5, 4, "main"}, &(_Bool106)) )
      if (_Bool106) {
        if ((*end) != '\n') {
          CHECK(77, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){36, 35, "expected new-line after \"main\", got"}, (*end)) )
        }
        CHECK(79, SyntaxTreeMainFunction_parse_new(NULL, &((*end)), &(self->main_function)) )
        
      }
      else {
        Bool _Bool107;
        CHECK(82, String_equal(keyword, &(String){7, 6, "native"}, &(_Bool107)) )
        if (_Bool107) {
          if ((*end) != ' ') {
            CHECK(84, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){35, 34, "expected space after \"native\", got"}, (*end)) )
          }
          CHECK(86, parse_native(self, &((*end))) )
          
        }
        else {
          Bool _Bool108;
          CHECK(88, String_equal(keyword, &(String){5, 4, "test"}, &(_Bool108)) )
          if (_Bool108) {
            if ((*end) != ' ') {
              CHECK(90, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){33, 32, "expected space after \"test\", got"}, (*end)) )
            }
            SyntaxTreeTestFunction* _SyntaxTreeTestFunction109;
            CHECK(92, SyntaxTreeTestFunction_parse_new(NULL, &((*end)), &(_SyntaxTreeTestFunction109)) )
            CHECK(92, List_add(self->_base.functions, &(_SyntaxTreeTestFunction109->_base)) )
            
          }
          else {
            Bool _Bool110;
            CHECK(95, String_equal(keyword, &(String){5, 4, "mock"}, &(_Bool110)) )
            if (_Bool110) {
              if ((*end) != ' ') {
                CHECK(97, SyntaxTreeNode_m_syntax_error_c(&(self->_base._base._base), &(String){33, 32, "expected space after \"mock\", got"}, (*end)) )
              }
              SyntaxTreeMockFunction* _SyntaxTreeMockFunction111;
              CHECK(99, SyntaxTreeMockFunction_parse_new(NULL, &((*end)), &(_SyntaxTreeMockFunction111)) )
              CHECK(99, List_add(self->_base.functions, &(_SyntaxTreeMockFunction111->_base)) )
              
            }
            else {
              CHECK(103, SyntaxTreeNode_m_syntax_error(&(self->_base._base._base), &(String){16, 15, "unknown keyword"}, keyword) )
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
  RAISE(106)
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_analyze(SyntaxTreeRoot* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_analyze = "SyntaxTreeRoot.analyze";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_analyze
Returncode SyntaxTreeRoot_analyze(SyntaxTreeRoot* self) {
  CHECK(109, SyntaxTreeRoot_m_order_types(self) )
  CHECK(110, SyntaxTreeNamespace_link_types(&(self->_base)) )
  CHECK(111, SyntaxTreeNode_link_children_types(&(self->_base._base._base), self->types) )
  CHECK(112, (self->global_init)->_base._base._base._base._dtl[1](self->global_init) )
  if (NULL != self->main_function) {
    CHECK(114, (self->main_function)->_base._base._base._base._dtl[1](self->main_function) )
  }
  CHECK(115, SyntaxTreeNamespace_analyze(&(self->_base)) )
  CHECK(116, SyntaxTreeNode_analyze_children(&(self->_base._base._base), self->types) )
  CHECK(117, (self->global_init)->_base._base._base._base._dtl[2](self->global_init) )
  if (self->testing) {
    if (!(NULL != glob->test_functions->first)) {
      CHECK(120, print(&(String){38, 37, "General code error: no test functions"}) )
      RAISE(121)
    }
  }
  else {
    if (NULL != self->main_function) {
      CHECK(123, (self->main_function)->_base._base._base._base._dtl[2](self->main_function) )
    }
    else {
      if (!self->is_library) {
        CHECK(125, print(&(String){37, 36, "General code error: no main function"}) )
        RAISE(126)
      }
    }
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
  if (ordered_list == NULL) RAISE(129)
  *ordered_list = (List){NULL, NULL};
  while (true) {
    TypeData* type_data = NULL;
    CHECK(132, List_pop(self->types, (void**)&(type_data)) )
    if (!(NULL != type_data)) break;
    CHECK(134, TypeData_m_order_bases(type_data, ordered_list) )
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
  6. main function
   */
#if MR_STAGE == MR_DECLARATIONS
Returncode SyntaxTreeRoot_write(SyntaxTreeRoot* self);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_SyntaxTreeRoot_write = "SyntaxTreeRoot.write";
#define MR_FUNC_NAME _func_name_SyntaxTreeRoot_write
Returncode SyntaxTreeRoot_write(SyntaxTreeRoot* self) {
  CHECK(147, file_open(self->output_file_name, false, &(glob->output_file)) )
  
  CHECK(149, write_global(&(String){19, 18, "#include \"mr.4.h\"\n"}) )
  
  CHECK(151, write_global(&(String){27, 26, "\n\n/* types declaration */\n"}) )
  TypeDeclarationWriter* type_declaration_writer = &(TypeDeclarationWriter){TypeDeclarationWriter__dtl};
  type_declaration_writer->_base._dtl = TypeDeclarationWriter__dtl;
  CHECK(153, SyntaxTreeRoot_write_for_type(self, &(type_declaration_writer->_base)) )
  
  /* will write type structures */
  CHECK(156, write_global(&(String){22, 21, "\n\n/* types struct */\n"}) )
  CHECK(157, SyntaxTreeNode_write_children(&(self->_base._base._base), self->types) )
  
  CHECK(159, write_global(&(String){35, 34, "\n\n/* types methods declaration */\n"}) )
  TypeMethodsDeclarationWriter* type_methods_declaration_writer = &(TypeMethodsDeclarationWriter){TypeMethodsDeclarationWriter__dtl};
  type_methods_declaration_writer->_base._dtl = TypeMethodsDeclarationWriter__dtl;
  CHECK(161, SyntaxTreeRoot_write_for_type(self, &(type_methods_declaration_writer->_base)) )
  
  CHECK(163, write_global(&(String){38, 37, "\n\n/* global functions declaration */\n"}) )
  CHECK(164, SyntaxTreeNamespace_write_functions_declaration(&(self->_base)) )
  
  CHECK(166, write_global(&(String){32, 31, "\n\n/* types global variables */\n"}) )
  TypeGlobalWriter* type_global_writer = &(TypeGlobalWriter){TypeGlobalWriter__dtl};
  type_global_writer->_base._dtl = TypeGlobalWriter__dtl;
  CHECK(168, SyntaxTreeRoot_write_for_type(self, &(type_global_writer->_base)) )
  
  /* will write global variables */
  CHECK(171, write_global(&(String){26, 25, "\n\n/* global variables */\n"}) )
  CHECK(172, SyntaxTreeNode_write_children(&(self->_base._base._base), self->_base._base.variables) )
  
  if (NULL != self->line_counts) {
    CHECK(175, SyntaxTreeRoot_write_test_coverage_data(self) )
  }
  
  CHECK(177, write_global(&(String){28, 27, "\n\n/* types methods body */\n"}) )
  TypeMethodsBodyWriter* type_methods_body_writer = &(TypeMethodsBodyWriter){TypeMethodsBodyWriter__dtl};
  type_methods_body_writer->_base._dtl = TypeMethodsBodyWriter__dtl;
  CHECK(179, SyntaxTreeRoot_write_for_type(self, &(type_methods_body_writer->_base)) )
  
  /* will write global functions bodies */
  CHECK(182, write_global(&(String){31, 30, "\n\n/* global functions body */\n"}) )
  CHECK(183, SyntaxTreeNode_write_children(&(self->_base._base._base), self->_base.functions) )
  
  /* write main function */
  if (self->testing ||  NULL !=  self->main_function) {
    if (!glob->is_new_mocked) {
      CHECK(188, write(&(String){61, 60, "\n\nReturncode new_Mock(Bool* allocate_success) { return OK; }"}) )
    }
    if (!glob->is_delete_mocked) {
      CHECK(191, write(&(String){50, 49, "\n\nReturncode delete_Mock(Ref self) { return OK; }"}) )
    }
  }
  if (self->testing) {
    CHECK(193, SyntaxTreeRoot_write_test_main(self) )
  }
  else {
    if (NULL != self->main_function) {
      CHECK(195, write_global(&(String){23, 22, "\n\n/* main function */\n"}) )
      CHECK(196, (self->main_function)->_base._base._base._base._dtl[3](self->main_function) )
    }
  }
  
  CHECK(198, file_close(glob->output_file) )
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
    CHECK(204, (((TypeData*)(child->item)))->_base._base._base._dtl[10](((TypeData*)(child->item)), type_writer) )
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
    if ((n) < 0 || (n) >= (self->line_counts)->length) RAISE(209)
    LineCount* line_count = (&(((LineCount*)((self->line_counts)->values))[n]));
    CHECK(210, write(&(String){13, 12, "\nint MR_file"}) )
    CHECK(211, write_int(n) )
    CHECK(212, write(&(String){13, 12, "_line_count["}) )
    CHECK(213, write_int(line_count->line_needs_cover->length) )
    CHECK(214, write(&(String){9, 8, "] = {\n  "}) )
    Int mod = 0;
    {int i; for (i = (0); i < (line_count->line_needs_cover->length); ++i) {
      if (i > 0) {
        CHECK(218, write(&(String){2, 1, ","}) )
      }
      if (mod == 25) {
        CHECK(220, write(&(String){4, 3, "\n  "}) )
        mod = 1;
      }
      else {
        mod += 1;
      }
      if ((i) < 0 || (i) >= (line_count->line_needs_cover)->length) RAISE(224)
      if ((((Bool*)((line_count->line_needs_cover)->values))[i])) {
        CHECK(225, write(&(String){3, 2, " 0"}) )
      }
      else {
        CHECK(227, write(&(String){3, 2, "-1"}) )
      }
    }}
    CHECK(228, write(&(String){4, 3, "\n};"}) )
  }}
  CHECK(229, write(&(String){33, 32, "\nFile_Coverage MR_file_coverage["}) )
  CHECK(230, write_int(self->line_counts->length) )
  CHECK(231, write(&(String){6, 5, "] = {"}) )
  {int n; for (n = (0); n < (self->line_counts->length); ++n) {
    if ((n) < 0 || (n) >= (self->line_counts)->length) RAISE(233)
    LineCount* line_count = (&(((LineCount*)((self->line_counts)->values))[n]));
    if (n > 0) {
      CHECK(235, write(&(String){2, 1, ","}) )
    }
    CHECK(236, write(&(String){6, 5, "\n  {\""}) )
    CHECK(237, write(line_count->filename) )
    CHECK(238, write(&(String){4, 3, "\", "}) )
    CHECK(239, write_int(line_count->line_needs_cover->length) )
    CHECK(240, write(&(String){10, 9, ", MR_file"}) )
    CHECK(241, write_int(n) )
    CHECK(242, write(&(String){13, 12, "_line_count}"}) )
  }}
  CHECK(243, write(&(String){5, 4, "\n};\n"}) )
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
  CHECK(246, write(&(String){21, 20, "\nUSER_MAIN_HEADER {\n"}) )
  CHECK(247, write(&(String){27, 26, "  Bool MR_success = true;\n"}) )
  CHECK(248, (self->global_init)->_base._base._base._base._dtl[3](self->global_init) )
  CHECK(249, write(&(String){2, 1, "\n"}) )
  NameMapNode* node = glob->test_functions->first;
  while (true) {
    CHECK(252, write(&(String){12, 11, "  RUN_TEST("}) )
    CHECK(253, SyntaxTreeFunction_write_cname(&(((SyntaxTreeTestFunction*)(node->value))->_base)) )
    CHECK(254, write(&(String){4, 3, ");\n"}) )
    node = node->next;
    if (!(NULL != node)) break;
  }
  if (NULL != self->line_counts) {
    CHECK(258, write(&(String){52, 51, "  MR_success &= MR_test_coverage(MR_file_coverage, "}) )
    CHECK(259, write_int(self->line_counts->length) )
    CHECK(260, write(&(String){4, 3, ");\n"}) )
  }
  CHECK(261, write(&(String){33, 32, "  return MR_success? OK : FAIL;\n"}) )
  CHECK(262, write(&(String){3, 2, "}\n"}) )
  CHECK(263, write(&(String){17, 16, "\nTEST_MAIN_FUNC\n"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeRoot__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeRoot__dtl[] = {(void*)SyntaxTreeNode_get_parent_type, (void*)SyntaxTreeRoot_link_types, (void*)SyntaxTreeRoot_analyze, (void*)SyntaxTreeRoot_write, (void*)SyntaxTreeRoot_parse_child, (void*)SyntaxTreeBranch_find_variable};
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
  if ((*new_node) == NULL) RAISE(269)
  *(*new_node) = (SyntaxTreeMainFunction){SyntaxTreeMainFunction__dtl, NULL, 0, 0, NULL, NULL, NULL, NULL, NULL, false, NULL, NULL, NULL, NULL, NULL, NULL, 0, false};
  (*new_node)->_base._base._base._base._dtl = SyntaxTreeMainFunction__dtl;
  CHECK(270, SyntaxTreeMainFunction_parse((*new_node), &((*end))) )
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
  CHECK(273, SyntaxTreeFunction_init(&(self->_base)) )
  CHECK(274, string_new_copy(&(String){5, 4, "main"}, &(self->_base.name)) )
  self->_base.arguments = malloc(sizeof(FunctionArguments));
  if (self->_base.arguments == NULL) RAISE(275)
  *self->_base.arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->_base.arguments->_base._dtl = FunctionArguments__dtl;
  CHECK(276, FunctionArguments_init(self->_base.arguments) )
  CHECK(277, SyntaxTreeFunction_parse_body(&(self->_base), &((*end))) )
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
  CHECK(284, write(&(String){18, 17, "\nUSER_MAIN_HEADER"}) )
  CHECK(285, SyntaxTreeFunction_write_block(&(self->_base)) )
  CHECK(286, write_post_func() )
  CHECK(287, write(&(String){12, 11, "\nMAIN_FUNC\n"}) )
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
  CHECK(290, (glob->root->global_init)->_base._base._base._base._dtl[3](glob->root->global_init) )
  CHECK(291, write_pre_func(&(self->_base)) )
  CHECK(292, write(&(String){2, 1, "\n"}) )
  CHECK(293, SyntaxTreeBlock_write_block_body(&(self->_base._base)) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func SyntaxTreeMainFunction__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func SyntaxTreeMainFunction__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)SyntaxTreeMainFunction_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeMainFunction_write_block_body, (void*)SyntaxTreeFunction_check_name, (void*)SyntaxTreeFunction_write_declaration};
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
  CHECK(298, SyntaxTreeFunction_init(&(self->_base)) )
  self->_base._base.code_nodes = malloc(sizeof(List));
  if (self->_base._base.code_nodes == NULL) RAISE(299)
  *self->_base._base.code_nodes = (List){NULL, NULL};
  self->_base._base._base.variables = malloc(sizeof(List));
  if (self->_base._base._base.variables == NULL) RAISE(300)
  *self->_base._base._base.variables = (List){NULL, NULL};
  self->_base.arguments = malloc(sizeof(FunctionArguments));
  if (self->_base.arguments == NULL) RAISE(301)
  *self->_base.arguments = (FunctionArguments){FunctionArguments__dtl, NULL, 0, NULL, NULL};
  self->_base.arguments->_base._dtl = FunctionArguments__dtl;
  CHECK(302, FunctionArguments_init(self->_base.arguments) )
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
  CHECK(308, SyntaxTreeNode_write_children(&(self->_base._base._base._base), self->_base._base._base.variables) )
  CHECK(309, write(&(String){21, 20, "#undef RETURN_ERROR\n"}) )
  CHECK(310, write(&(String){43, 42, "#define RETURN_ERROR(value) return value;\n"}) )
  CHECK(311, write(&(String){55, 54, "#define MR_FUNC_NAME \"global variable initialization\"\n"}) )
  CHECK(312, (self)->_base._base._base._base._dtl[7](self) )
  CHECK(313, write(&(String){21, 20, "#undef MR_FUNC_NAME\n"}) )
  CHECK(314, write(&(String){21, 20, "#undef RETURN_ERROR\n"}) )
  CHECK(315, write(&(String){60, 59, "#define RETURN_ERROR(value) MR_err = value; goto MR_cleanup"}) )
  return OK;
}
#undef MR_FUNC_NAME
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Func GlobalInit__dtl[];
#endif
#if MR_STAGE == MR_FUNCTIONS
Func GlobalInit__dtl[] = {(void*)SyntaxTreeFunction_get_parent_type, (void*)SyntaxTreeFunction_link_types, (void*)SyntaxTreeFunction_analyze, (void*)GlobalInit_write, (void*)SyntaxTreeBlock_parse_child, (void*)SyntaxTreeFunction_find_variable, (void*)SyntaxTreeFunction_get_function, (void*)SyntaxTreeBlock_write_block_body, (void*)SyntaxTreeFunction_check_name, (void*)SyntaxTreeFunction_write_declaration};
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
  if (self->line_needs_cover == NULL) RAISE(324)
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
  CHECK(329, write(text) )
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
