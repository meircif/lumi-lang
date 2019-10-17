#ifndef LUMI_MAINFILE
#define LUMI_MAINFILE "global/file-io.c"
#define DEPTH 5
#include "lumi.3.h"
#else

#if LUMI_STAGE == LUMI_TYPEDEFS
static char* _lumi_file4_name = "global/file-io.3.lm";
#endif
#define LUMI_FILE_NAME _lumi_file4_name

/* TL4 compiler - File read and write functions */

/* Read a single character from the input file */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode read_c(Char* ch);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_read_c = "read-c";
#define LUMI_FUNC_NAME _func_name_read_c
Returncode read_c(Char* ch) {
  if (glob->got_new_line) {
    glob->line_number += 1;
  }
  CHECK(7, file_getc(glob->input_file, &((*ch))) )
  glob->got_new_line = (*ch) == '\n';
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/*  Read from the input file to `text` until a new-line, EOF, or one of the
characters in `ends` is reached, and return the end character in `end`.
If `indent` is true, ignore and count trailing spaces.
It is possible to "save" previous read result by setting "glob.save-input" to
true. Next time this function will be colled it will return the saved values.
 */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode read_until(String* ends, Bool indent, String** text, Char* end, Int* spaces);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_read_until = "read-until";
#define LUMI_FUNC_NAME _func_name_read_until
Returncode read_until(String* ends, Bool indent, String** text, Char* end, Int* spaces) {
  Char ch = '\0';
  if (glob->save_input) {
    ch = glob->input_end;
    (*spaces) = glob->input_spaces;
  }
  else {
    CHECK(24, String_clear(glob->input_buffer) )
    (*spaces) = 0;
    CHECK(26, read_c(&(ch)) )
    if (indent) {
      /* ignore and count indent */
      while (true) {
        if (!(ch == ' ')) break;
        (*spaces) += 1;
        CHECK(32, read_c(&(ch)) )
      }
    }
  }
  
  Char quote = '\0';
  while (true) {
    if (!(ch != EOF)) break;
    if (quote == '\0') {
      if (!(ch != '\n')) break;
      Bool _Bool7;
      CHECK(39, String_has(ends, ch, &(_Bool7)) )
      if (!(!_Bool7)) break;
      if (ch == '\'' || ch == '"' || ch == '`') {
        quote = ch;
      }
    }
    else {
      if (ch == '\\') {
        CHECK(43, String_append(glob->input_buffer, ch) )
        CHECK(44, read_c(&(ch)) )
      }
      else {
        if (ch == quote) {
          quote = '\0';
        }
      }
    }
    CHECK(47, String_append(glob->input_buffer, ch) )
    CHECK(48, read_c(&(ch)) )
  }
  
  glob->input_end = ch;
  glob->input_spaces = (*spaces);
  glob->save_input = false;
  (*text) = glob->input_buffer;
  (*end) = ch;
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* Return in `new-text` a new allocated string read using `read-until`. */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode read_new(String* ends, String** new_text, Char* end);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_read_new = "read-new";
#define LUMI_FUNC_NAME _func_name_read_new
Returncode read_new(String* ends, String** new_text, Char* end) {
  String* text = NULL;
  Int _Int8;
  CHECK(60, read_until(ends, false, &(text), &((*end)), &(_Int8)) )
  CHECK(61, string_new_copy(text, &((*new_text))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* write a single character to the output file */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode write_c(Char ch);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_write_c = "write-c";
#define LUMI_FUNC_NAME _func_name_write_c
Returncode write_c(Char ch) {
  CHECK(66, file_putc(glob->output_file, ch) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* write `text` to the output file */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode write(String* text);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_write = "write";
#define LUMI_FUNC_NAME _func_name_write
Returncode write(String* text) {
  CHECK(71, file_write(glob->output_file, text) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* write `name` with `-` replaced by `_` */
/* replace C builtin names */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode write_cname(String* name);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_write_cname = "write-cname";
#define LUMI_FUNC_NAME _func_name_write_cname
Returncode write_cname(String* name) {
  if (!(NULL != name)) {
    RAISE(78)
  }
  Bool _Bool9;
  CHECK(79, String_equal(name, &(String){7, 6, "stdout"}, &(_Bool9)) )
  Bool _Bool10;
  CHECK(79, String_equal(name, &(String){6, 5, "stdin"}, &(_Bool10)) )
  Bool _Bool11;
  CHECK(79, String_equal(name, &(String){7, 6, "stderr"}, &(_Bool11)) )
  if (_Bool9 || _Bool10 || _Bool11) {
    CHECK(81, write(name) )
    CHECK(82, write(&(String){7, 6, "_Cname"}) )
    return OK;
  }
  {int index; for (index = (0); index < (name->length); ++index) {
    if ((index) < 0 || (index) >= (name)->length) RAISE(85)
    Char ch = ((name)->values[index]);
    if (ch == '-' || ch == ' ') {
      CHECK(87, write_c('_') )
    }
    else {
      CHECK(89, write_c(ch) )
    }
  }}
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* write `num` to the output file as text */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode write_int(Int num);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_write_int = "write-int";
#define LUMI_FUNC_NAME _func_name_write_int
Returncode write_int(Int num) {
  String* num_str = &(String){64, 0, (char[64]){0}};
  CHECK(95, Int_str(num, num_str) )
  CHECK(96, write(num_str) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* write `num` spaces - usefull for writing indentation */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode write_spaces(Int num);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_write_spaces = "write-spaces";
#define LUMI_FUNC_NAME _func_name_write_spaces
Returncode write_spaces(Int num) {
  {int n; for (n = (0); n < (num); ++n) {
    CHECK(102, write_c(' ') )
  }}
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* write `text` to the output file as string literal */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode write_string_literal(String* text);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_write_string_literal = "write-string-literal";
#define LUMI_FUNC_NAME _func_name_write_string_literal
Returncode write_string_literal(String* text) {
  CHECK(107, write_c('\"') )
  {int i; for (i = (0); i < (text->length); ++i) {
    if ((i) < 0 || (i) >= (text)->length) RAISE(109)
    Char ch = ((text)->values[i]);
    CHECK(110, write_c(ch) )
    if (ch == '\\') {
      CHECK(112, write_c(ch) )
    }
  }}
  CHECK(113, write_c('\"') )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif


/* Proxy functions to be mocked in tests */
#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode file_open(String* name, Bool is_read, File** file);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_file_open = "file-open";
#define LUMI_FUNC_NAME _func_name_file_open
Returncode file_open(String* name, Bool is_read, File** file) {
  if (is_read) {
    CHECK(119, file_open_read(name, &((*file))) )
  }
  else {
    CHECK(121, file_open_write(name, &((*file))) )
  }
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode file_close(File* file);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_file_close = "file-close";
#define LUMI_FUNC_NAME _func_name_file_close
Returncode file_close(File* file) {
  CHECK(124, File_close(file) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode file_getc(File* file, Char* ch);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_file_getc = "file-getc";
#define LUMI_FUNC_NAME _func_name_file_getc
Returncode file_getc(File* file, Char* ch) {
  CHECK(127, File_getc(file, &((*ch))) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode file_putc(File* file, Char ch);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_file_putc = "file-putc";
#define LUMI_FUNC_NAME _func_name_file_putc
Returncode file_putc(File* file, Char ch) {
  CHECK(130, File_putc(file, ch) )
  return OK;
}
#undef LUMI_FUNC_NAME
#endif

#if LUMI_STAGE == LUMI_DECLARATIONS
Returncode file_write(File* file, String* text);
#elif LUMI_STAGE == LUMI_FUNCTIONS
static char* _func_name_file_write = "file-write";
#define LUMI_FUNC_NAME _func_name_file_write
Returncode file_write(File* file, String* text) {
  CHECK(133, File_write(file, text) )
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
#include "syntax-tree/root.c"
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
