"""MR0 compiler. The initial MR compiler.

Is written in MR0 style to mimic the compiler written in MR0.
"""

import re
import sys

from itertools import count


MAIN_START = """
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
"""


class Parser(object):
  def __init__(self):
    self.infile = None
    self.outfile = None
  
  def main(self):
    _, infile_name, outfile_name = sys.argv
    with open(infile_name, 'r') as self.infile:
      with open(outfile_name, 'w') as self.outfile:
        self.write('#include <stdio.h>\n')
        self.write('#include <string.h>\n')
        self.write('#include "mr0-c-api.h"\n\n')
        while self.parse_line(0):
          pass
  
  def getc(self):
    return self.infile.read(1)
  
  def write(self, text):
    self.outfile.write(text)
  
  def read_name(self, end1, end2):
    name = ''
    q = None
    while True:
      char = self.getc()
      if q is not None:
        if char == '\\':
          name += char
          char = self.getc()
        elif char == q:
          q = None
        elif not char:
          return name, char
      elif not char or char == end1 or char == end2 or char == '\n':
        return name, char
      elif char == '"' or char == "'":
        q = char
      name += char
  
  @staticmethod
  def cname(name):
    return name.replace('-', '_')
    
  @staticmethod
  def real_string_length(text):
    index = 1
    length = 0
    while index + 1 < len(text):
      if text[index] == '\\':
        index += 1
      length += 1
      index += 1
    return length
      
  def parse_block_body(self, spaces):
    while True:
      for _ in xrange(spaces):
        char = self.getc()
        if char != ' ':
          return
        self.write(char)
      self.parse_line(spaces)
      
  def parse_block(self, spaces):
    self.write(' {\n')
    self.parse_block_body(spaces)
    self.write('}\n')
      
  def parse_line(self, spaces):
    key_word, end = self.read_name(' ', '(')
    if not end:
      return False
    if not key_word:
      self.write(end)
      return True
    parsers = {
      '#' : self.parse_comment,
      'main' : self.parse_main,
      'func' : self.parse_func,
      'native' : self.parse_native,
      'var' : self.parse_var,
      'owner' : self.parse_var,
      'if' : self.parse_if,
      'else' : self.parse_else,
      'do' : self.parse_do,
      'while' : self.parse_while,
      'for' : self.parse_for,
      'return' : self.parse_return,
      'out' : self.parse_out
    }
    parser = parsers.get(key_word,
                         self.parse_call if end == '(' else self.parse_assign)
    parser(key_word, spaces)
    return True
  
  def parse_comment(self, _, __):
    while self.getc() != '\n':
      pass
    
  def parse_main(self, key_word, spaces):
    self.parse_func(key_word, spaces)
    self.write(MAIN_START)
    
  def parse_func_header(self):
    self.write('Returncode ')
    name, _ = self.read_name('(', '(')
    name = self.cname(name)
    self.write(name)
    self.write('(')
    while True:
      access, end = self.read_name(' ', ')')
      if end != ' ':
        break
      type, _ = self.read_name(' ', ' ')
      self.write(type)
      if access == 'out':
        self.write('*')
      self.write(' ')
      name, end = self.read_name(',', ')')
      name = self.cname(name)
      self.write(name)
      if end != ',':
        break
      self.write(end)
      space = self.getc()
      self.write(space)
    self.write(')')
    
  def parse_func(self, _, spaces):
    self.parse_func_header()
    self.getc()  # ignore '\n'
    self.parse_block(spaces + 2)
    
  def parse_native(self, _, __):
    subtype, _ = self.read_name(' ', ' ')
    if subtype == 'func':
      self.parse_func_header()
      end = self.getc()
    else:
      self.write("typedef void* ")
      name, end = self.read_name('\n', '\n')
      self.write(name)
    self.write(';')
    self.write(end)
    
  def parse_var(self, _, __):
    typename, end = self.read_name(' ', '{')
    if typename == 'String':
      length, _ = self.read_name('}', '}')
      self.getc()  # ignore ' '
      varname, end = self.read_name('\n', '\n')
      varname = self.cname(varname)
      self.write('char _{0}_buff[{1}]; String {0} = {{{1}, 0, _{0}_buff}}'
        .format(varname, length))
    else:
      self.write(typename)
      self.write(end)
      varname, end = self.read_name('\n', '\n')
      varname = self.cname(varname)
      self.write(varname)
    self.write(';')
    self.write(end)
    
  def parse_if(self, key_word, spaces):
    self.write(key_word)
    self.write(' (')
    line, _ = self.read_name('\n', '\n')
    line = self.cname(line)
    self.write(line)
    self.write(')')
    self.parse_block(spaces + 2)
    
  def parse_else(self, key_word, spaces):
    self.write(key_word)
    self.parse_block(spaces + 2)
    
  def parse_do(self, _, spaces):
    self.write('while (true)')
    self.parse_block(spaces + 2)
    
  def parse_while(self, _, __):
    self.write('if (not(')
    line, _ = self.read_name('\n', '\n')
    line = self.cname(line)
    self.write(line)
    self.write(')) break;\n')
    
  def parse_for(self, _, __):
    varname, _ = self.read_name(' ', ' ')
    self.read_name(' ', ' ')  # ignore "in"
    line, _ = self.read_name('\n', '\n')
    line = self.cname(line)
    self.write('if ({0} >= {1}) break; ++{0};\n'.format(varname, line))
    
  def parse_return(self, key_word, _):
    self.write(key_word)
    self.write(' OK;\n')
    
  def parse_out(self, _, __):
    self.write('*')
    name, _ = self.read_name(' ', ' ')
    name = self.cname(name)
    self.write(name)
    self.read_name(' ', ' ')
    self.write(' = ')
    line, _ = self.read_name('\n', '\n')
    line = self.cname(line)
    self.write(line)
    self.write(';\n')
    
  def parse_call(self, key_word, _):
    func_name = self.cname(key_word)
    self.write(func_name)
    self.write('(')
    while True:
      access, end = self.read_name(' ', ')')
      if end != ' ':
        break
      if access == 'out':
        self.write('&')
      name, end = self.read_name(',', ')')
      if name[0] == '"':
        length = self.real_string_length(name)
        self.write('(String){{{0}, {0}, {1}}}'.format(length, name))
      else:
        if name[0] != "'":
          name = self.cname(name)
        self.write(name)
      if end != ',':
        break
      self.write(end)
      space = self.getc()
      self.write(space)
    self.write(');')
    end = self.getc()
    self.write(end)
  
  def parse_assign(self, key_word, _):
    name = self.cname(key_word)
    self.write(name)
    self.read_name(' ', ' ')  # ignore ":="
    self.write(' = ')
    line, _ = self.read_name('\n', '\n')
    line = self.cname(line)
    self.write(line)
    self.write(';\n')
    
  def parse_unsupported(self, key_word, __):
    self.write('// ')
    self.write(key_word)
    self.write(' ')
    line, end = self.read_name('\n', '\n')
    self.write(line)
    self.write(end)


def main():
  parser = Parser()
  parser.main()


if __name__ == '__main__':
  main()
