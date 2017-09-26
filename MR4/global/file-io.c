#ifndef MR_MAINFILE
#define MR_MAINFILE "global/file-io.c"
#define DEPTH 5
#include "mr.3.h"
#else

#if MR_STAGE == MR_TYPEDEFS
static char* _mr_file2_name = "global/file-io.3.mr";
#endif
#define MR_FILE_NAME _mr_file2_name

/* MR4 compiler - File read and write functions */

/* Proxy functions to be mocked in tests */
#if MR_STAGE == MR_DECLARATIONS
Returncode file_open(String* name, Bool is_read, File** file);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_file_open = "file-open";
#define MR_FUNC_NAME _func_name_file_open
Returncode file_open(String* name, Bool is_read, File** file) {
  if (is_read) {
    CHECK(6, file_open_read(name, &((*file))) )
  }
  else {
    CHECK(8, file_open_write(name, &((*file))) )
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode file_close(File* file);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_file_close = "file-close";
#define MR_FUNC_NAME _func_name_file_close
Returncode file_close(File* file) {
  CHECK(11, File_close(file) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode file_getc(File* file, Char* ch);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_file_getc = "file-getc";
#define MR_FUNC_NAME _func_name_file_getc
Returncode file_getc(File* file, Char* ch) {
  CHECK(14, File_getc(file, &((*ch))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode file_putc(File* file, Char ch);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_file_putc = "file-putc";
#define MR_FUNC_NAME _func_name_file_putc
Returncode file_putc(File* file, Char ch) {
  CHECK(17, File_putc(file, ch) )
  return OK;
}
#undef MR_FUNC_NAME
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode file_write(File* file, String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_file_write = "file-write";
#define MR_FUNC_NAME _func_name_file_write
Returncode file_write(File* file, String* text) {
  CHECK(20, File_write(file, text) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Read a single character from the input file */
#if MR_STAGE == MR_DECLARATIONS
Returncode read_c(Char* ch);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_read_c = "read-c";
#define MR_FUNC_NAME _func_name_read_c
Returncode read_c(Char* ch) {
  if (glob->got_new_line) {
    glob->line_number += 1;
  }
  CHECK(27, file_getc(glob->input_file, &((*ch))) )
  glob->got_new_line = (*ch) == '\n';
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Expect `expected-text` to be read exaclty from the input file */
#if MR_STAGE == MR_DECLARATIONS
Returncode read_expect(String* expected_text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_read_expect = "read-expect";
#define MR_FUNC_NAME _func_name_read_expect
Returncode read_expect(String* expected_text) {
  String* actual_text = _new_string(expected_text->length + 1);
  if (actual_text == NULL) RAISE(33)
  {int n; for (n = (0); n < (expected_text->length); ++n) {
    Char _Char0;
    CHECK(35, read_c(&(_Char0)) )
    CHECK(35, String_append(actual_text, _Char0) )
  }}
  Bool _Bool1;
  CHECK(36, String_equal(actual_text, expected_text, &(_Bool1)) )
  if (!_Bool1) {
    CHECK(37, f_syntax_error2(&(String){9, 8, "expected"}, expected_text, &(String){4, 3, "got"}, actual_text) )
  }
  free(actual_text);
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Read and check indentation spaces for a line break from the input file */
#if MR_STAGE == MR_DECLARATIONS
Returncode read_line_break_spaces();
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_read_line_break_spaces = "read-line-break-spaces";
#define MR_FUNC_NAME _func_name_read_line_break_spaces
Returncode read_line_break_spaces() {
  {int n; for (n = (0); n < (glob->spaces + 4); ++n) {
    Char _Char2;
    CHECK(45, read_c(&(_Char2)) )
    if (_Char2 != ' ') {
      String* expected_spaces = &(String){128, 0, (char[128]){0}};
      String* actual_spaces = &(String){128, 0, (char[128]){0}};
      CHECK(48, Int_str(glob->spaces + 4, expected_spaces) )
      CHECK(49, Int_str(n - 1, actual_spaces) )
      CHECK(50, f_syntax_error2(&(String){32, 31, "too short indentation, expected"}, expected_spaces, &(String){4, 3, "got"}, actual_spaces) )
    }
  }}
  return OK;
}
#undef MR_FUNC_NAME
#endif


/*  Read from the input file to `text` until a new-line, EOF, or one of the
characters in `ends` is reached, and return the end character in `end`.
If `indent` is true, ignore and count trailing spaces.
It is possible to "save" previous read result by setting "glob.save-input" to
true. Next time this function will be colled it will return the saved values.
 */
#if MR_STAGE == MR_DECLARATIONS
Returncode read_until(String* ends, Bool indent, String** text, Char* end, Int* spaces);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_read_until = "read-until";
#define MR_FUNC_NAME _func_name_read_until
Returncode read_until(String* ends, Bool indent, String** text, Char* end, Int* spaces) {
  Char ch = '\0';
  if (glob->save_input) {
    ch = glob->input_end;
    (*spaces) = glob->input_spaces;
  }
  else {
    CHECK(70, String_clear(glob->input_buffer) )
    (*spaces) = 0;
    CHECK(72, read_c(&(ch)) )
    if (indent) {
      /* ignore and count indent */
      while (true) {
        if (!(ch == ' ')) break;
        (*spaces) += 1;
        CHECK(78, read_c(&(ch)) )
      }
    }
  }
  
  Char quote = '\0';
  while (true) {
    if (!(ch != EOF && ch != '\n')) break;
    if (quote == '\0') {
      Bool _Bool3;
      CHECK(84, String_has(ends, ch, &(_Bool3)) )
      if (!(!_Bool3)) break;
      if (ch == '\'' || ch == '"' || ch == '`') {
        quote = ch;
      }
    }
    else {
      if (ch == '\\') {
        CHECK(88, String_append(glob->input_buffer, ch) )
        CHECK(89, read_c(&(ch)) )
      }
      else {
        if (ch == quote) {
          quote = '\0';
        }
      }
    }
    CHECK(92, String_append(glob->input_buffer, ch) )
    CHECK(93, read_c(&(ch)) )
  }
  
  glob->input_end = ch;
  glob->input_spaces = (*spaces);
  glob->save_input = false;
  (*text) = glob->input_buffer;
  (*end) = ch;
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Return in `new-text` a new allocated string read using `read-until`. */
#if MR_STAGE == MR_DECLARATIONS
Returncode read_new(String* ends, String** new_text, Char* end);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_read_new = "read-new";
#define MR_FUNC_NAME _func_name_read_new
Returncode read_new(String* ends, String** new_text, Char* end) {
  String* text = NULL;
  Int _Int4;
  CHECK(105, read_until(ends, false, &(text), &((*end)), &(_Int4)) )
  CHECK(106, string_new_copy(text, &((*new_text))) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* Access values */
#if MR_STAGE == MR_DECLARATIONS
extern Int ACCESS_COPY;
#elif MR_STAGE == MR_FUNCTIONS
Int ACCESS_COPY = 0;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Int ACCESS_USER;
#elif MR_STAGE == MR_FUNCTIONS
Int ACCESS_USER = 1;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Int ACCESS_OWNER;
#elif MR_STAGE == MR_FUNCTIONS
Int ACCESS_OWNER = 2;
#endif
#if MR_STAGE == MR_DECLARATIONS
extern Int ACCESS_VAR;
#elif MR_STAGE == MR_FUNCTIONS
Int ACCESS_VAR = 3;
#endif

#if MR_STAGE == MR_DECLARATIONS
Returncode get_access(String* access_str, Int* access);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_get_access = "get-access";
#define MR_FUNC_NAME _func_name_get_access
Returncode get_access(String* access_str, Int* access) {
  Bool _Bool5;
  CHECK(116, String_equal(access_str, &(String){5, 4, "copy"}, &(_Bool5)) )
  if (_Bool5) {
    (*access) = 0;
  }
  else {
    Bool _Bool6;
    CHECK(118, String_equal(access_str, &(String){5, 4, "user"}, &(_Bool6)) )
    if (_Bool6) {
      (*access) = 1;
    }
    else {
      Bool _Bool7;
      CHECK(120, String_equal(access_str, &(String){6, 5, "owner"}, &(_Bool7)) )
      if (_Bool7) {
        (*access) = 2;
      }
      else {
        Bool _Bool8;
        CHECK(122, String_equal(access_str, &(String){4, 3, "var"}, &(_Bool8)) )
        if (_Bool8) {
          (*access) = 3;
        }
        else {
          CHECK(125, f_syntax_error(&(String){15, 14, "illegal access"}, access_str) )
        }
      }
    }
  }
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* write a single character to the output file */
#if MR_STAGE == MR_DECLARATIONS
Returncode write_c(Char ch);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_c = "write-c";
#define MR_FUNC_NAME _func_name_write_c
Returncode write_c(Char ch) {
  CHECK(130, file_putc(glob->output_file, ch) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* write `text` to the output file */
#if MR_STAGE == MR_DECLARATIONS
Returncode write(String* text);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write = "write";
#define MR_FUNC_NAME _func_name_write
Returncode write(String* text) {
  CHECK(135, file_write(glob->output_file, text) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* write `name` with `-` replaced by `_` */
#if MR_STAGE == MR_DECLARATIONS
Returncode write_cname(String* name);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_cname = "write-cname";
#define MR_FUNC_NAME _func_name_write_cname
Returncode write_cname(String* name) {
  if (!(NULL != name)) {
    RAISE(141)
  }
  {int index; for (index = (0); index < (name->length); ++index) {
    if ((index) < 0 || (index) >= (name)->length) RAISE(143)
    Char ch = ((name)->values[index]);
    if (ch == '-') {
      CHECK(145, write_c('_') )
    }
    else {
      CHECK(147, write_c(ch) )
    }
  }}
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* write `num` to the output file as text */
#if MR_STAGE == MR_DECLARATIONS
Returncode write_int(Int num);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_int = "write-int";
#define MR_FUNC_NAME _func_name_write_int
Returncode write_int(Int num) {
  String* num_str = &(String){64, 0, (char[64]){0}};
  CHECK(153, Int_str(num, num_str) )
  CHECK(154, write(num_str) )
  return OK;
}
#undef MR_FUNC_NAME
#endif


/* write `num` spaces - usefull for writing indentation */
#if MR_STAGE == MR_DECLARATIONS
Returncode write_spaces(Int num);
#elif MR_STAGE == MR_FUNCTIONS
static char* _func_name_write_spaces = "write-spaces";
#define MR_FUNC_NAME _func_name_write_spaces
Returncode write_spaces(Int num) {
  {int n; for (n = (0); n < (num); ++n) {
    CHECK(160, write_c(' ') )
  }}
  return OK;
}
#undef MR_FUNC_NAME
#endif

#undef MR_FILE_NAME

#ifndef MR_INCLUDES
#define MR_INCLUDES
#include "global/common.c"
#include "global/global.c"
#include "global/list.c"
#include "global/map.c"
#include "global/type.c"
#include "expression/call.c"
#include "expression/constant.c"
#include "expression/container.c"
#include "expression/expression.c"
#include "expression/slice.c"
#include "expression/symbol.c"
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
