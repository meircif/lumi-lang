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
  Char prev = '\0';
  
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
  Char end;
  char _typename_buff[80]; String typename = {80, 0, _typename_buff};
  read_name(&end, infile, &typename, ' ', '{');
  Bool equal;
  string_equal(&equal, typename, (String){5, 5, "Array"});
  if (equal) {
    read_name(&end, infile, &typename, '}', '}');
    file_getc(&end, infile);
  }
  write_cstyle(outfile, typename);
  string_equal(&equal, access, (String){4, 4, "copy"});
  if (not equal) {
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
  file_write(outfile, (String){385, 385, "\nint main(int argc, char* argv[]) {\n  if (argc < 3) {\n    printf(\"too few arguments\");\n    return ERR;\n  }\n  String arg1, arg2;\n  arg1.chars = argv[1];\n  arg1.max_length = strnlen(arg1.chars, 1024);\n  arg1.actual_length = arg1.max_length;\n  arg2.chars = argv[2];\n  arg2.max_length = strnlen(arg2.chars, 1024);\n  arg2.actual_length = arg2.max_length;\n  func(arg1, arg2);\n  return OK;\n}\n"});
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
  Bool is_int;
  Bool is_char;
  Bool is_bool;
  Bool is_array;
  Bool is_string;
  string_equal(&is_int, typename, (String){3, 3, "Int"});
  string_equal(&is_char, typename, (String){4, 4, "Char"});
  string_equal(&is_bool, typename, (String){4, 4, "Bool"});
  string_equal(&is_array, typename, (String){5, 5, "Array"});
  string_equal(&is_string, typename, (String){6, 6, "String"});
  if (is_string) {
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
  if (is_array) {
    char _length_buff[80]; String length = {80, 0, _length_buff};
    read_name(&end, infile, &length, ':', ':');
    copy_text(&end, infile, outfile, '}', '}');
    file_getc(&end, infile);
    file_putc(outfile, ' ');
    copy_text(&end, infile, outfile, '\n', '\n');
    file_putc(outfile, '[');
    file_write(outfile, length);
    file_write(outfile, (String){3, 3, "];\n"});
    return OK;
  }
  write_cstyle(outfile, typename);
  if (is_int or is_char or is_bool) {
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
  Char end;
  char _typename_buff[80]; String typename = {80, 0, _typename_buff};
  read_name(&end, infile, &typename, ' ', '{');
  Bool is_array;
  string_equal(&is_array, typename, (String){5, 5, "Array"});
  if (is_array) {
    read_name(&end, infile, &typename, '}', '}');
    file_getc(&end, infile);
  }
  write_cstyle(outfile, typename);
  file_write(outfile, (String){2, 2, "* "});
  copy_text(&end, infile, outfile, '\n', '\n');
  file_write(outfile, (String){2, 2, ";\n"});
  return OK;
}

Returncode parse_if(File infile, File outfile, String key_word, Int spaces) {
  file_write(outfile, key_word);
  file_write(outfile, (String){2, 2, " ("});
  Char end;
  copy_text(&end, infile, outfile, '\n', '\n');
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

Returncode parse_call(File infile, File outfile, String key_word, Int spaces) {
  write_cstyle(outfile, key_word);
  file_putc(outfile, '(');
  Char end;
  while (true) {
    char _access_buff[80]; String access = {80, 0, _access_buff};
    read_name(&end, infile, &access, ' ', ')');
    if (not(end == ' ')) break;
    Bool equal;
    string_equal(&equal, access, (String){3, 3, "out"});
    if (equal) {
      file_putc(outfile, '&');
    }
    char _name_buff[512]; String name = {512, 0, _name_buff};
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
    file_putc(outfile, end);
    file_getc(&end, infile);
    file_putc(outfile, end);
  }
  file_write(outfile, (String){2, 2, ");"});
  file_getc(&end, infile);
  file_putc(outfile, end);
  return OK;
}

Returncode parse_assign(File infile, File outfile, String key_word, Int spaces) {
  write_cstyle(outfile, key_word);
  Char end;
  char _ignore_assign_buff[80]; String ignore_assign = {80, 0, _ignore_assign_buff};
  read_name(&end, infile, &ignore_assign, ' ', ' ');
  file_write(outfile, (String){3, 3, " = "});
  copy_text(&end, infile, outfile, '\n', '\n');
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
  file_write(outfile, (String){24, 24, "#include \"mr0-c-api.h\"\n\n"});
  
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