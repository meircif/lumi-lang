#include <stdio.h>
#include <string.h>
#include "mr0-c-api.h"


Returncode print(String text);

typedef void* File;
Returncode file_open_read(File* file, String name);
Returncode file_open_write(File* file, String name);
Returncode file_close(File file);
Returncode file_getc(Char* ch, File file);
Returncode file_putc(File file, Char ch);
Returncode file_write(File file, String line);

Returncode string_clear(String* this);
Returncode string_length(Int* length, String this);
Returncode string_equal(Bool* equal, String this, String other);
Returncode string_get(Char* ch, String this, Int index);
Returncode string_append(String* this, Char ch);
Returncode string_replace(String this, Char old, Char new);
Returncode int_to_string(String* str, Int value);

Returncode parse_line(Bool* more_lines, File infile, File outfile, Int spaces);


Returncode write_csyle_char(File outfile, Char ch, Char prev) {
  if (ch == 45 and prev != ' ') {
    file_putc(outfile, '_');
    return OK;
  }
  if (ch == '.') {
    file_write(outfile, (String){2, 2, "->"});
    return OK;
  }
  if (ch == '=' and prev == ' ') {
    file_write(outfile, (String){2, 2, "=="});
    return OK;
  }
  if (ch != ':') {
    file_putc(outfile, ch);
  }
  return OK;
}

Returncode write_cstyle(File outfile, String text) {
  Int length;
  string_length(&length, text);
  Int index = 0;
  Char prev = ' ';
  
  while (true) {
    if (index >= length) break; ++index;
    Char ch;
    string_get(&ch, text, index minus 1);
    write_csyle_char(outfile, ch, prev);
    prev = ch;
  }
  return OK;
}

Returncode read_name(Char* end, File infile, String* name, Char end1, Char end2) {
  string_clear(name);
  Char ch;
  Char q = '\0';
  while (true) {
    file_getc(&ch, infile);
    if (q != '\0') {
      if (ch == '\\') {
        string_append(name, ch);
        file_getc(&ch, infile);
      }
      else {
        if (ch == q) {
          q = '\0';
        }
        if (not(ch != EOF)) break;
      }
    }
    else {
      if (not(not (ch == EOF or ch == end1 or ch == end2 or ch == '\n'))) break;
      if (ch == '\'' or ch == '"') {
        q = ch;
      }
    }
    string_append(name, ch);
  }
  *end = ch;
  return OK;
}

Returncode copy_text(Char* end, File infile, File outfile, Char end1, Char end2) {
  char _text_buff[80]; String text = {80, 0, _text_buff};
  read_name(end, infile, &text, end1, end2);
  write_cstyle(outfile, text);
  return OK;
}

Returncode real_string_length(Int* length, String text) {
  Int index = 1;
  Int real_length = 0;
  Int text_length;
  string_length(&text_length, text);
  while (true) {
    if (not(index + 1 < text_length)) break;
    Char ch;
    string_get(&ch, text, index);
    if (ch == '\\') {
      index = index + 1;
    }
    real_length = real_length + 1;
    index = index + 1;
  }
  *length = real_length;
  return OK;
}

Returncode is_primitive(Bool* res, String typename) {
  Bool equal;
  string_equal(&equal, typename, (String){3, 3, "Int"});
  if (equal) {
    *res = true;
    return OK;
  }
  string_equal(&equal, typename, (String){4, 4, "Char"});
  if (equal) {
    *res = true;
    return OK;
  }
  string_equal(&equal, typename, (String){4, 4, "Bool"});
  *res = equal;
  return OK;
}

Returncode copy_type(File infile, File outfile) {
  Char end;
  char _typename_buff[80]; String typename = {80, 0, _typename_buff};
  read_name(&end, infile, &typename, ' ', '{');
  Bool equal;
  string_equal(&equal, typename, (String){5, 5, "Array"});
  if (equal) {
    char _subtypename_buff[80]; String subtypename = {80, 0, _subtypename_buff};
    read_name(&end, infile, &subtypename, '}', '}');
    file_getc(&end, infile);
  }
  write_cstyle(outfile, typename);
  return OK;
}

Returncode parse_block_body(File infile, File outfile, Int spaces) {
  while (true) {
    Int count = 0;
    while (true) {
      Char ch;
      if (count >= spaces) break; ++count;
      file_getc(&ch, infile);
      if (ch != ' ') {
        return OK;
      }
      file_putc(outfile, ch);
    }
    Bool more_lines;
    parse_line(&more_lines, infile, outfile, spaces);
    if (not(more_lines)) break;
  }
  return OK;
}

Returncode parse_block(File infile, File outfile, Int spaces) {
  file_write(outfile, (String){3, 3, " {\n"});
  parse_block_body(infile, outfile, spaces + 2);
  file_write(outfile, (String){2, 2, "}\n"});
  return OK;
}

Returncode parse_param_type(File infile, File outfile, String access) {
  copy_type(infile, outfile);
  Bool is_copy;
  string_equal(&is_copy, access, (String){4, 4, "copy"});
  if (not is_copy) {
    file_putc(outfile, '*');
  }
  return OK;
}

Returncode parse_func_header(File infile, File outfile) {
  file_write(outfile, (String){11, 11, "Returncode "});
  Char end;
  copy_text(&end, infile, outfile, '(', '(');
  file_putc(outfile, '(');
  while (true) {
    char _access_buff[80]; String access = {80, 0, _access_buff};
    read_name(&end, infile, &access, ' ', ')');
    if (not(end == ' ')) break;
    parse_param_type(infile, outfile, access);
    file_putc(outfile, ' ');
    copy_text(&end, infile, outfile, ',', ')');
    if (not(end == ',')) break;
    file_getc(&end, infile);
    file_write(outfile, (String){2, 2, ", "});
  }
  file_getc(&end, infile);
  while (true) {
    if (not(end != '\n')) break;
    file_getc(&end, infile);
    file_write(outfile, (String){2, 2, ", "});
    char _access_buff[80]; String access = {80, 0, _access_buff};
    read_name(&end, infile, &access, ' ', ' ');
    parse_param_type(infile, outfile, access);
    Bool is_var;
    string_equal(&is_var, access, (String){3, 3, "var"});
    if (not is_var) {
      file_putc(outfile, '*');
    }
    file_putc(outfile, ' ');
    copy_text(&end, infile, outfile, ',', '\n');
    if (not(end == ',')) break;
  }
  file_putc(outfile, ')');
  return OK;
}

Returncode parse_comment(File infile, File outfile, String key_word, Int spaces) {
  file_write(outfile, (String){3, 3, "/* "});
  Char end;
  copy_text(&end, infile, outfile, '\n', '\n');
  file_write(outfile, (String){4, 4, " */\n"});
  return OK;
}

Returncode parse_func(File infile, File outfile, String key_word, Int spaces) {
  parse_func_header(infile, outfile);
  parse_block(infile, outfile, spaces);
  return OK;
}

Returncode parse_main(File infile, File outfile, String key_word, Int spaces) {
  parse_func(infile, outfile, key_word, spaces);
  file_write(outfile, (String){393, 393, "\nint main(int argc, char* argv[]) {\n  if (argc < 3) {\n    printf(\"too few arguments\");\n    return ERR;\n  }\n  String arg1, arg2;\n  arg1.chars = argv[1];\n  arg1.max_length = strnlen(arg1.chars, 1024);\n  arg1.actual_length = arg1.max_length;\n  arg2.chars = argv[2];\n  arg2.max_length = strnlen(arg2.chars, 1024);\n  arg2.actual_length = arg2.max_length;\n  CHECK(func(&arg1, &arg2))\n  return OK;\n}\n"});
  return OK;
}

Returncode parse_native(File infile, File outfile, String key_word, Int spaces) {
  Char end;
  char _name_buff[80]; String name = {80, 0, _name_buff};
  read_name(&end, infile, &name, ' ', ' ');
  Bool equal;
  string_equal(&equal, name, (String){4, 4, "func"});
  if (equal) {
    parse_func_header(infile, outfile);
  }
  else {
    file_write(outfile, (String){13, 13, "typedef void "});
    copy_text(&end, infile, outfile, '\n', '\n');
  }
  file_write(outfile, (String){2, 2, ";\n"});
  return OK;
}

Returncode parse_var(File infile, File outfile, String key_word, Int spaces) {
  Char end;
  char _typename_buff[80]; String typename = {80, 0, _typename_buff};
  read_name(&end, infile, &typename, ' ', '{');
  Bool equal;
  string_equal(&equal, typename, (String){6, 6, "String"});
  if (equal) {
    char _length_buff[80]; String length = {80, 0, _length_buff};
    read_name(&end, infile, &length, '}', '}');
    file_getc(&end, infile);
    file_write(outfile, (String){8, 8, "String* "});
    copy_text(&end, infile, outfile, '\n', '\n');
    file_write(outfile, (String){13, 13, " = &(String){"});
    file_write(outfile, length);
    file_write(outfile, (String){11, 11, ", 0, (char["});
    file_write(outfile, length);
    file_write(outfile, (String){8, 8, "]){0}};\n"});
    return OK;
  }
  string_equal(&equal, typename, (String){5, 5, "Array"});
  if (equal) {
    char _name_buff[80]; String name = {80, 0, _name_buff};
    char _length_buff[80]; String length = {80, 0, _length_buff};
    char _string_length_buff[80]; String string_length = {80, 0, _string_length_buff};
    read_name(&end, infile, &length, ':', ':');
    read_name(&end, infile, &typename, '{', '}');
    string_equal(&equal, typename, (String){6, 6, "String"});
    if (equal) {
      read_name(&end, infile, &string_length, '}', '}');
      file_getc(&end, infile);
    }
    file_getc(&end, infile);
    read_name(&end, infile, &name, '\n', '\n');
    file_write(outfile, (String){7, 7, "Array* "});
    write_cstyle(outfile, name);
    file_write(outfile, (String){12, 12, " = &(Array){"});
    file_write(outfile, length);
    file_write(outfile, (String){3, 3, ", ("});
    write_cstyle(outfile, typename);
    file_putc(outfile, '[');
    file_write(outfile, length);
    file_write(outfile, (String){7, 7, "]){0}};"});
    if (equal) {
      file_write(outfile, (String){7, 7, " char _"});
      write_cstyle(outfile, name);
      file_write(outfile, (String){7, 7, "_chars["});
      file_write(outfile, string_length);
      file_write(outfile, (String){2, 2, "]["});
      file_write(outfile, length);
      file_write(outfile, (String){22, 22, "]; {int n; for(n=0; n<"});
      file_write(outfile, length);
      file_write(outfile, (String){18, 18, "; ++n) ((String*)("});
      write_cstyle(outfile, name);
      file_write(outfile, (String){25, 25, "->values))[n] = (String){"});
      file_write(outfile, string_length);
      file_write(outfile, (String){6, 6, ", 0, _"});
      write_cstyle(outfile, name);
      file_write(outfile, (String){12, 12, "_chars[n]};}"});
    }
    file_putc(outfile, '\n');
    return OK;
  }
  write_cstyle(outfile, typename);
  is_primitive(&equal, typename);
  if (equal) {
    file_putc(outfile, ' ');
    copy_text(&end, infile, outfile, '\n', '\n');
    file_write(outfile, (String){2, 2, ";\n"});
    return OK;
  }
  file_write(outfile, (String){2, 2, "* "});
  copy_text(&end, infile, outfile, '\n', '\n');
  file_write(outfile, (String){5, 5, " = &("});
  write_cstyle(outfile, typename);
  file_write(outfile, (String){6, 6, "){0};\n"});
  return OK;
}

Returncode parse_ref(File infile, File outfile, String key_word, Int spaces) {
  copy_type(infile, outfile);
  file_write(outfile, (String){2, 2, "* "});
  Char end;
  copy_text(&end, infile, outfile, '\n', '\n');
  file_write(outfile, (String){2, 2, ";\n"});
  return OK;
}

Returncode parse_call_args(File infile, File outfile, String* inout_name, Bool* line_end) {
  file_write(outfile, (String){6, 6, "CHECK("});
  write_cstyle(outfile, inout_name[0]);
  file_putc(outfile, '(');
  Char end;
  Bool equal;
  char _name_buff[512]; String name = {512, 0, _name_buff};
  while (true) {
    read_name(&end, infile, &name, ' ', ')');
    if (not(end == ' ')) break;
    read_name(&end, infile, &name, ',', ')');
    Char first;
    string_get(&first, name, 0);
    if (first == '"') {
      Int length;
      real_string_length(&length, name);
      char _length_str_buff[80]; String length_str = {80, 0, _length_str_buff};
      int_to_string(&length_str, length);
      file_write(outfile, (String){10, 10, "&(String){"});
      file_write(outfile, length_str);
      file_write(outfile, (String){2, 2, ", "});
      file_write(outfile, length_str);
      file_write(outfile, (String){2, 2, ", "});
      file_write(outfile, name);
      file_write(outfile, (String){1, 1, "}"});
    }
    else {
      if (first != '\'') {
        write_cstyle(outfile, name);
      }
      else {
        file_write(outfile, name);
      }
    }
    if (not(end == ',')) break;
    file_getc(&end, infile);
    file_write(outfile, (String){2, 2, ", "});
  }
  file_getc(&end, infile);
  while (true) {
    if (not(end != '\n')) break;
    file_getc(&end, infile);
    file_write(outfile, (String){2, 2, ", "});
    read_name(&end, infile, &name, ' ', ' ');
    string_equal(&equal, name, (String){3, 3, "var"});
    if (not equal) {
      file_putc(outfile, '&');
    }
    read_name(&end, infile, inout_name, ',', ' ');
    write_cstyle(outfile, inout_name[0]);
    if (not(end == ',')) break;
  }
  file_write(outfile, (String){2, 2, "))"});
  *line_end = end == '\n';
  return OK;
}

Returncode parse_call_in_exp(File infile, File outfile, String key_word, String prefix) {
  Char end;
  char _name_buff[80]; String name = {80, 0, _name_buff};
  read_name(&end, infile, &name, ' ', '(');
  Bool line_end = end == '\n';
  if (end == '(') {
    parse_call_args(infile, outfile, &name, &line_end);
    file_putc(outfile, ' ');
  }
  write_cstyle(outfile, key_word);
  file_write(outfile, prefix);
  write_cstyle(outfile, name);
  
  if (not line_end) {
    file_putc(outfile, ' ');
    copy_text(&end, infile, outfile, '\n', '\n');
  }
  return OK;
}

Returncode parse_if(File infile, File outfile, String key_word, Int spaces) {
  parse_call_in_exp(infile, outfile, key_word, (String){2, 2, " ("});
  file_putc(outfile, ')');
  parse_block(infile, outfile, spaces);
  return OK;
}

Returncode parse_else(File infile, File outfile, String key_word, Int spaces) {
  file_write(outfile, key_word);
  parse_block(infile, outfile, spaces);
  return OK;
}

Returncode parse_do(File infile, File outfile, String key_word, Int spaces) {
  file_write(outfile, (String){12, 12, "while (true)"});
  parse_block(infile, outfile, spaces);
  return OK;
}

Returncode parse_while(File infile, File outfile, String key_word, Int spaces) {
  file_write(outfile, (String){8, 8, "if (not("});
  Char end;
  copy_text(&end, infile, outfile, '\n', '\n');
  file_write(outfile, (String){10, 10, ")) break;\n"});
  return OK;
}

Returncode parse_for(File infile, File outfile, String key_word, Int spaces) {
  Char end;
  char _varname_buff[80]; String varname = {80, 0, _varname_buff};
  char _ignore_in_buff[80]; String ignore_in = {80, 0, _ignore_in_buff};
  read_name(&end, infile, &varname, ' ', ' ');
  read_name(&end, infile, &ignore_in, ' ', ' ');
  file_write(outfile, (String){4, 4, "if ("});
  write_cstyle(outfile, varname);
  file_write(outfile, (String){4, 4, " >= "});
  copy_text(&end, infile, outfile, '\n', '\n');
  file_write(outfile, (String){11, 11, ") break; ++"});
  write_cstyle(outfile, varname);
  file_write(outfile, (String){2, 2, ";\n"});
  return OK;
}

Returncode parse_return(File infile, File outfile, String key_word, Int spaces) {
  file_write(outfile, key_word);
  file_write(outfile, (String){5, 5, " OK;\n"});
  return OK;
}

Returncode parse_out(File infile, File outfile, String key_word, Int spaces) {
  file_putc(outfile, '*');
  Char end;
  char _ignore_assign_buff[80]; String ignore_assign = {80, 0, _ignore_assign_buff};
  copy_text(&end, infile, outfile, ' ', ' ');
  read_name(&end, infile, &ignore_assign, ' ', ' ');
  file_write(outfile, (String){3, 3, " = "});
  copy_text(&end, infile, outfile, '\n', '\n');
  file_write(outfile, (String){2, 2, ";\n"});
  return OK;
}

Returncode parse_class(File infile, File outfile, String key_word, Int spaces) {
  Char end;
  char _name_buff[80]; String name = {80, 0, _name_buff};
  read_name(&end, infile, &name, '\n', '\n');
  file_write(outfile, (String){17, 17, "typedef struct {\n"});
  parse_block_body(infile, outfile, spaces + 2);
  file_write(outfile, (String){2, 2, "} "});
  write_cstyle(outfile, name);
  file_write(outfile, (String){2, 2, ";\n"});
  return OK;
}

Returncode parse_array(File infile, File outfile, String key_word, Int spaces) {
  Char end;
  char _index_buff[80]; String index = {80, 0, _index_buff};
  char _source_buff[80]; String source = {80, 0, _source_buff};
  char _target_buff[80]; String target = {80, 0, _target_buff};
  char _typename_buff[80]; String typename = {80, 0, _typename_buff};
  read_name(&end, infile, &typename, ' ', ' ');
  read_name(&end, infile, &target, ' ', '[');
  Bool is_get = end != '[';
  if (is_get) {
    read_name(&end, infile, &source, ' ', ' ');
    read_name(&end, infile, &source, '[', '[');
    read_name(&end, infile, &index, ']', ']');
    file_getc(&end, infile);
  }
  else {
    read_name(&end, infile, &index, ']', ']');
    file_getc(&end, infile);
    read_name(&end, infile, &source, ' ', ' ');
  }
  file_write(outfile, (String){4, 4, "if ("});
  write_cstyle(outfile, index);
  file_write(outfile, (String){8, 8, " < 0 || "});
  write_cstyle(outfile, index);
  file_write(outfile, (String){4, 4, " >= "});
  if (is_get) {
    write_cstyle(outfile, source);
  }
  else {
    write_cstyle(outfile, target);
  }
  file_write(outfile, (String){22, 22, "->length) return ERR; "});
  if (is_get) {
    write_cstyle(outfile, target);
    file_write(outfile, (String){3, 3, " = "});
  }
  file_write(outfile, (String){2, 2, "(("});
  write_cstyle(outfile, typename);
  file_write(outfile, (String){3, 3, "*)("});
  if (is_get) {
    write_cstyle(outfile, source);
  }
  else {
    write_cstyle(outfile, target);
  }
  file_write(outfile, (String){10, 10, "->values))"});
  
  Bool primitive;
  is_primitive(&primitive, typename);
  if (not is_get or primitive) {
    file_putc(outfile, '[');
    write_cstyle(outfile, index);
    file_putc(outfile, ']');
  }
  else {
    file_write(outfile, (String){3, 3, " + "});
    write_cstyle(outfile, index);
  }
  if (not is_get) {
    file_write(outfile, (String){3, 3, " = "});
    copy_text(&end, infile, outfile, '\n', '\n');
  }
  file_write(outfile, (String){2, 2, ";\n"});
  return OK;
}

Returncode parse_call(File infile, File outfile, String key_word, Int spaces) {
  Bool line_end;
  parse_call_args(infile, outfile, &key_word, &line_end);
  file_putc(outfile, '\n');
  return OK;
}

Returncode parse_assign(File infile, File outfile, String key_word, Int spaces) {
  Char end;
  char _ignore_assign_buff[80]; String ignore_assign = {80, 0, _ignore_assign_buff};
  read_name(&end, infile, &ignore_assign, ' ', ' ');
  parse_call_in_exp(infile, outfile, key_word, (String){3, 3, " = "});
  file_write(outfile, (String){2, 2, ";\n"});
  return OK;
}

Returncode parse_line(Bool* more_lines, File infile, File outfile, Int spaces) {
  char _key_word_buff[80]; String key_word = {80, 0, _key_word_buff};
  Char end;
  read_name(&end, infile, &key_word, ' ', '(');
  if (end == EOF) {
    *more_lines = false;
    return OK;
  }
  *more_lines = true;
  Bool equal;
  
  string_equal(&equal, key_word, (String){0, 0, ""});
  if (equal) {
    file_putc(outfile, end);
    return OK;
  }
  string_equal(&equal, key_word, (String){1, 1, "#"});
  if (equal) {
    parse_comment(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){4, 4, "main"});
  if (equal) {
    parse_main(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){4, 4, "func"});
  if (equal) {
    parse_func(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){6, 6, "native"});
  if (equal) {
    parse_native(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){3, 3, "var"});
  if (equal) {
    parse_var(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){5, 5, "owner"});
  if (equal) {
    parse_ref(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){4, 4, "user"});
  if (equal) {
    parse_ref(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){2, 2, "if"});
  if (equal) {
    parse_if(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){4, 4, "else"});
  if (equal) {
    parse_else(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){2, 2, "do"});
  if (equal) {
    parse_do(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){5, 5, "while"});
  if (equal) {
    parse_while(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){3, 3, "for"});
  if (equal) {
    parse_for(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){6, 6, "return"});
  if (equal) {
    parse_return(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){3, 3, "out"});
  if (equal) {
    parse_out(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){5, 5, "class"});
  if (equal) {
    parse_class(infile, outfile, key_word, spaces);
    return OK;
  }
  string_equal(&equal, key_word, (String){2, 2, "[]"});
  if (equal) {
    parse_array(infile, outfile, key_word, spaces);
    return OK;
  }
  if (end == '(') {
    parse_call(infile, outfile, key_word, spaces);
  }
  else {
    parse_assign(infile, outfile, key_word, spaces);
  }
  return OK;
}

Returncode func(String arg1, String arg2) {
  print((String){17, 17, "MR compiler start"});
  
  File infile;
  File outfile;
  file_open_read(&infile, arg1);
  file_open_write(&outfile, arg2);
  
  file_write(outfile, (String){19, 19, "#include <stdio.h>\n"});
  file_write(outfile, (String){20, 20, "#include <string.h>\n"});
  file_write(outfile, (String){24, 24, "#include \"mr1-c-api.h\"\n\n"});
  
  while (true) {
    Bool more_lines;
    parse_line(&more_lines, infile, outfile, 0);
    if (not(more_lines)) break;
  }
  file_close(infile);
  file_close(outfile);
  
  print((String){15, 15, "MR compiler end"});
  return OK;
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    printf("too few arguments");
    return ERR;
  }
  String arg1, arg2;
  arg1.chars = argv[1];
  arg1.max_length = strnlen(arg1.chars, 1024);
  arg1.actual_length = arg1.max_length;
  arg2.chars = argv[2];
  arg2.max_length = strnlen(arg2.chars, 1024);
  arg2.actual_length = arg2.max_length;
  func(arg1, arg2);
  return OK;
}
