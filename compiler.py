"""MR initial compiler."""

import re
import sys

from itertools import count


MAIN_START = """int main(int argc, char* argv[]) {
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
  
"""


class Parser(object):
  def __init__(self):
    self.blocks = []
    self.last_blocks = [self.blocks]
    self.items = []
    self.outfile = None
    self.counter = count()
  
  def main(self):
    _, infile_name, outfile_name = sys.argv
    with open(infile_name, 'r') as infile:
      for line in infile:
        self.read_line(line)
    
    self.items = self.parse_blocks(self.blocks)
    
    with open(outfile_name, 'w') as self.outfile:
      self.outfile.write('#include <stdio.h>\n')
      self.outfile.write('#include <string.h>\n')
      self.outfile.write('#include "mr-c-api.h"\n\n')
      self.write_items(self.items, 0)

  def read_line(self, full_line):
    full_line = full_line.rstrip()
    line = full_line.lstrip(' ')
    if not line:
      return
    spaces = len(full_line) - len(line)
    indent = spaces / 2
    self.last_blocks = self.last_blocks[:indent + 1]
      
    subblocks = []
    block = (line, subblocks)
    self.last_blocks[indent].append(block)
    self.last_blocks.append(subblocks)
  
  def parse_blocks(self, blocks):
    items = []
    for line, subblocks in blocks:
      subitems = self.parse_blocks(subblocks)
      item = self.parse_line(line)
      items.append((item, subitems))
    return items

  def parse_line(self, line):
    tokens = re.split('([ (),])', line)
    parser = {
      'func' : self.parse_func,
      'native' : self.parse_native,
      'owner' : self.parse_owner,
      'if' : self.parse_if,
      'else' : self.parse_else,
      'do' : self.parse_do,
      'while' : self.parse_while
    }
    parser = parser.get(tokens[0], self.parse_call)
    try:
      return parser(tokens)
    except:
      print 'failed parsing:', line
      raise
  
  @staticmethod
  def parse_func(tokens):
    func_name = tokens[2]
    args = []
    args_tokens = tokens[4:-2]
    while args_tokens:
      args.append((args_tokens[0], args_tokens[2], args_tokens[4]))
      args_tokens = args_tokens[8:]
    return ('func', func_name, args)
  
  def parse_native(self, tokens):
    native_type = tokens[2]
    if native_type == 'func':
      return ('native',) + self.parse_func(tokens[2:])
    else:
      value = tokens[4]
      return ('native', native_type, value)
  
  @staticmethod
  def parse_owner(tokens):
    type_name = tokens[2]
    var_name = tokens[4]
    is_init = len(tokens) > 5
    return ('owner', type_name, var_name, is_init)
  
  def parse_if(self, tokens):
    return self.parse_bool_exp('if', tokens)
  
  @staticmethod
  def parse_else(tokens):
    return ('else',)
  
  @staticmethod
  def parse_do(tokens):
    return ('do',)
  
  def parse_while(self, tokens):
    return self.parse_bool_exp('while', tokens)
  
  @staticmethod
  def parse_call(tokens):
    func_name = tokens[0]
    args = []
    args_tokens = tokens[2:-2]
    while args_tokens:
      args.append((args_tokens[0], args_tokens[2]))
      args_tokens = args_tokens[6:]
    return ('call', func_name, args)
  
  @staticmethod
  def parse_bool_exp(title, tokens):
    if len(tokens) == 5:
      var_name = tokens[4]
      positive = False
    else:
      var_name = tokens[2]
      positive = True
    return (title, var_name, positive)

  def write_items(self, items, indent):
    for item, subitems in items:
      self.write_item(item, subitems, indent)
  
  def write_line(self, text, indent):
    self.outfile.write('{}{}\n'.format('  ' * indent, text))
  
  def write_item(self, item, subitems, indent):
    writer = {
      'func' : self.write_func,
      'native' : self.write_native,
      'owner' : self.write_owner,
      'if' : self.write_if,
      'else' : self.write_else,
      'do' : self.write_do,
      'while' : self.write_while
    }
    writer = writer.get(item[0], self.write_call)
    writer(item, subitems, indent)
   
  def write_func(self, item, subitems, indent):
    name = self.name(item[1])
    self.write_line('', indent)
    if name == 'main':
      self.outfile.write(MAIN_START)
    
    self.write_items(subitems, indent + 1)
    
    if name == 'main':
      self.write_line('', indent + 1)
      self.write_line('return OK;', indent + 1)
      
    self.write_line('}', indent)
   
  def write_native(self, item, subitems, indent):
    name = self.name(item[2])
    if item[1] == 'func':
      args = item[3]
      args = ['{}{} {}'.format(arg_type, '*' if inout == 'out' else '', self.name(arg_name))
              for inout, arg_type, arg_name in args]
      self.write_line('Returncode {}({});'.format(name, ', '.join(args)), indent)
    else:
      self.write_line('typedef void* {};'.format(name), indent)
   
  def write_owner(self, item, subitems, indent):
    type_name = self.name(item[1])
    var_name = self.name(item[2])
    if type_name == 'Bool':
      self.write_line('Bool {} = false;'.format(var_name), indent)
    elif type_name.startswith('Int{'):
      self.write_line('Uint {} = 0;'.format(var_name), indent)
    elif type_name.startswith('String{'):
      length = int(type_name[7:-1])
      buff_name = '__{}_buff'.format(var_name)
      self.write_line('char {}[{}];'.format(buff_name, length), indent)
      self.write_line('String {};'.format(var_name), indent)
      self.write_line('{}.chars = {};'.format(var_name, buff_name), indent)
      self.write_line('{}.max_length = {};'.format(var_name, length), indent)
      self.write_line('{}.actual_length = 0;'.format(var_name), indent)
    elif type_name.startswith('Array{'):
      subtype, num = type_name[6:-1].rsplit(':', 1)
      if subtype.startswith('Int{'):
        self.write_line('Uint {}[{}] = {{ 0 }};'.format(var_name, num), indent)
        
    else:
      self.write_line('{} {};'.format(type_name, var_name), indent)
   
  def write_if(self, item, subitems, indent):
    cond = self.name(item[1])
    positive = item[2]
    if not positive:
      cond = '!({})'.format(cond)
    self.write_block('if ({})'.format(cond), subitems, indent)
   
  def write_else(self, item, subitems, indent):
    self.write_block('else', subitems, indent)
   
  def write_do(self, item, subitems, indent):
    self.write_block('while (1)', subitems, indent)
   
  def write_while(self, item, subitems, indent):
    cond = self.name(item[1])
    positive = item[2]
    if positive:
      cond = '!({})'.format(cond)
    self.write_line('if ({}) break;'.format(cond), indent)
   
  def write_call(self, item, subitems, indent):
    name = self.name(item[1])
    args = item[2]
    if args[0][1][0] == '"':
      str_name = '__str_arg{}'.format(self.counter.next())
      self.write_line('String {};'.format(str_name), indent)
      inline_string = self.get_inline_string(args[0][1])
      self.write_line('{}.chars = {};'.format(str_name, inline_string), indent)
      self.write_line('{0}.max_length = strnlen({0}.chars, 1024);'.format(str_name), indent)
      self.write_line('{0}.actual_length = {0}.max_length;'.format(str_name), indent)
      args = [(args[0][0], str_name)]
    args = ['{}{}'.format('&' if inout == 'out' else '', self.name(arg_name))
            for inout, arg_name in args]
    self.write_line('{}({});'.format(name, ', '.join(args)), indent)
  
  @staticmethod
  def get_inline_string(unparsed):
    parsed = unparsed.replace(';;', ',')
    parsed = parsed.replace('__', ' ')
    parsed = parsed.replace('{{', '(')
    return parsed.replace('}}', ')')
  
  def write_block(self, title, subitems, indent):
    self.write_line('{} {{'.format(title), indent)
    self.write_items(subitems, indent + 1)
    self.write_line('}', indent)
  
  @staticmethod
  def name(name):
    return name.replace('-', '_')


def main():
  parser = Parser()
  parser.main()


if __name__ == '__main__':
  main()
