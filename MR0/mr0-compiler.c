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


Returncode cname(String name) {
  string_replace(name, '-', '_');
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

Returncode parse_func_header(File infile, File outfile) {
  file_write(outfile, (String){11, 11, "Returncode "});
  Char end;
  char _name_buff[80]; String name = {80, 0, _name_buff};
  read_name(&end, infile, &name, '(', '(');
  cname(name);
  file_write(outfile, name);
  file_putc(outfile, '(');
  while (true) {
    char _access_buff[80]; String access = {80, 0, _access_buff};
    read_name(&end, infile, &access, ' ', ')');
    if (not(end == ' ')) break;
    char _typename_buff[80]; String typename = {80, 0, _typename_buff};
    read_name(&end, infile, &typename, ' ', ' ');
    file_write(outfile, typename);
    Bool equal;
    string_equal(&equal, access, (String){3, 3, "out"});
    if (equal) {
      file_putc(outfile, '*');
    }
    file_putc(outfile, ' ');
    read_name(&end, infile, &name, ',', ')');
    cname(name);
    file_write(outfile, name);
    if (not(end == ',')) break;
    file_putc(outfile, end);
    file_getc(&end, infile);
    file_putc(outfile, end);
  }
  file_putc(outfile, ')');
  return OK;
}

Returncode parse_comment(File infile, File outfile, String key_word, Int spaces) {
  while (true) {
    Char ch;
    file_getc(&ch, infile);
    if (not(ch != '\n')) break;
  }
  return OK;
}

Returncode parse_func(File infile, File outfile, String key_word, Int spaces) {
  parse_func_header(infile, outfile);
  Char newline;
  file_getc(&newline, infile);
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
    file_getc(&end, infile);
  }
  else {
    file_write(outfile, (String){14, 14, "typedef void* "});
    read_name(&end, infile, &name, '\n', '\n');
    cname(name);
    file_write(outfile, name);
  }
  file_putc(outfile, ';');
  file_putc(outfile, end);
  return OK;
}

Returncode parse_var(File infile, File outfile, String key_word, Int spaces) {
  Char end;
  char _typename_buff[80]; String typename = {80, 0, _typename_buff};
  char _varname_buff[80]; String varname = {80, 0, _varname_buff};
  read_name(&end, infile, &typename, ' ', '{');
  Bool equal;
  string_equal(&equal, typename, (String){6, 6, "String"});
  if (equal) {
    char _length_buff[80]; String length = {80, 0, _length_buff};
    read_name(&end, infile, &length, '}', '}');
    file_getc(&end, infile);
    read_name(&end, infile, &varname, '\n', '\n');
    cname(varname);
    file_write(outfile, (String){6, 6, "char _"});
    file_write(outfile, varname);
    file_write(outfile, (String){6, 6, "_buff["});
    file_write(outfile, length);
    file_write(outfile, (String){10, 10, "]; String "});
    file_write(outfile, varname);
    file_write(outfile, (String){4, 4, " = {"});
    file_write(outfile, length);
    file_write(outfile, (String){6, 6, ", 0, _"});
    file_write(outfile, varname);
    file_write(outfile, (String){6, 6, "_buff}"});
  }
  else {
    file_write(outfile, typename);
    file_putc(outfile, end);
    read_name(&end, infile, &varname, '\n', '\n');
    cname(varname);
    file_write(outfile, varname);
  }
  file_putc(outfile, ';');
  file_putc(outfile, end);
  return OK;
}

Returncode parse_if(File infile, File outfile, String key_word, Int spaces) {
  file_write(outfile, key_word);
  file_write(outfile, (String){2, 2, " ("});
  Char end;
  char _line_buff[80]; String line = {80, 0, _line_buff};
  read_name(&end, infile, &line, '\n', '\n');
  cname(line);
  file_write(outfile, line);
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
  char _line_buff[80]; String line = {80, 0, _line_buff};
  read_name(&end, infile, &line, '\n', '\n');
  cname(line);
  file_write(outfile, line);
  file_write(outfile, (String){10, 10, ")) break;\n"});
  return OK;
}

Returncode parse_for(File infile, File outfile, String key_word, Int spaces) {
  Char end;
  char _varname_buff[80]; String varname = {80, 0, _varname_buff};
  char _line_buff[80]; String line = {80, 0, _line_buff};
  read_name(&end, infile, &varname, ' ', ' ');
  cname(varname);
  read_name(&end, infile, &line, ' ', ' ');
  read_name(&end, infile, &line, '\n', '\n');
  cname(line);
  file_write(outfile, (String){4, 4, "if ("});
  file_write(outfile, varname);
  file_write(outfile, (String){4, 4, " >= "});
  file_write(outfile, line);
  file_write(outfile, (String){11, 11, ") break; ++"});
  file_write(outfile, varname);
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
  char _name_buff[80]; String name = {80, 0, _name_buff};
  read_name(&end, infile, &name, ' ', ' ');
  cname(name);
  file_write(outfile, name);
  read_name(&end, infile, &name, ' ', ' ');
  file_write(outfile, (String){3, 3, " = "});
  read_name(&end, infile, &name, '\n', '\n');
  cname(name);
  file_write(outfile, name);
  file_write(outfile, (String){2, 2, ";\n"});
  return OK;
}

Returncode parse_call(File infile, File outfile, String key_word, Int spaces) {
  cname(key_word);
  file_write(outfile, key_word);
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
      file_write(outfile, (String){9, 9, "(String){"});
      file_write(outfile, length_str);
      file_write(outfile, (String){2, 2, ", "});
      file_write(outfile, length_str);
      file_write(outfile, (String){2, 2, ", "});
      file_write(outfile, name);
      file_write(outfile, (String){1, 1, "}"});
    }
    else {
      if (first != '\'') {
        cname(name);
      }
      file_write(outfile, name);
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
  cname(key_word);
  file_write(outfile, key_word);
  Char end;
  char _line_buff[80]; String line = {80, 0, _line_buff};
  read_name(&end, infile, &line, ' ', ' ');
  file_write(outfile, (String){3, 3, " = "});
  read_name(&end, infile, &line, '\n', '\n');
  cname(line);
  file_write(outfile, line);
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
    parse_var(infile, outfile, key_word, spaces);
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
