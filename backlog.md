# MR Development Backlog

## main tasks

1. initial MR C compiler
  1. write a complier in MR that can compile itself to C [compiler.mr](compiler.mr)
  1. write a python compiler that can compile the MR compiler to C [compiler.py](compiler.py)
  1. publish the generated C code to be used from now on
1. decide exception handling syntax [example.mr](example.mr)
1. decide OOP syntax [example.mr](example.mr)
1. support more MR features...

## initial compiler

The minimum needed for a working compiler:

1. only generate to C
1. only one input and output file
1. can have assumptions on file size
1. support only ints, bools, arrays and strings
1. no OOP or structs
1. only stack variables - no global or dynamic
1. no error checking
1. all ints will be generated to "int" (ignore range)
1. all strings and arrays will generated to the same type - no optimizations
1. only basic file IO support
1. whatever will make thing easier and still work...
