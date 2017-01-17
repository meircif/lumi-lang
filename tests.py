"""Test MR compilers.

Receives the C compiler name as first parameter.
"""

import os
import sys
import filecmp
import unittest
import subprocess


class TestMR0(unittest.TestCase):
  C_COMPILE_COMMAND = None
  MR_COMPILER = 'mr0-compiler.0.mr'
  PY_COMPILER = 'mr0-compiler.py'
  C_COMPILER = 'mr0-compiler.c'
  GENERATED_C_CODE = 'generated.c'
  COMPILER_EXE = 'mr0-compiler.exe'
  
  def test_python_compiler(self):
    # generate C code using Python compiler
    cmd = [sys.executable, self.PY_COMPILER,
           self.MR_COMPILER, self.GENERATED_C_CODE]
    self._generate_and_cmp(cmd)
  
  def test_mr_compiler(self):
    # compile MR compiler from C code
    cmd = [self.C_COMPILE_COMMAND, self.C_COMPILER, 'mr0-file.c', 'mr0-string.c',
           '-o', self.COMPILER_EXE]
    self._silent_run(cmd)
    # generate C code using MR compiler
    cmd = [self.COMPILER_EXE, self.MR_COMPILER, self.GENERATED_C_CODE]
    self._generate_and_cmp(cmd)
  
  def _generate_and_cmp(self, cmd):
    self._silent_run(cmd)
    self.assertTrue(filecmp.cmp(self.GENERATED_C_CODE, self.C_COMPILER))
  
  @staticmethod
  def _silent_run(cmd):
    with open(os.devnull, 'w') as devnull:
      subprocess.check_call(cmd, stdout=devnull, stderr=subprocess.STDOUT)
  

if __name__ == '__main__':
  TestMR0.C_COMPILE_COMMAND = sys.argv[1]
  unittest.main(argv=sys.argv[:1] + sys.argv[2:], verbosity=2)
