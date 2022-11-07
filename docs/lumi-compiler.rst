Using Lumi Compiler Directly
============================

.. highlight:: shell

:ref:`using-lumi-command` is recommended to compile Lumi code. Using the Lumi
compiler directly is possible, but it is less convenient.

Latest Version - TL5 Compiler
-----------------------------
The :ref:`TL5 <syntax-tl5>` compiler generates a single C file based on one or
more Lumi files. For example ::

   tl5-compiler hello.c hello.5.lm other.5.lm

will generate ``hello.c`` C file from ``hello.5.lm`` and ``other.5.lm`` Lumi
files.

Compiling Testing Code
----------------------
To generate C code that tests a specific Lumi module ``-t <tested module name>``
should be used. For example::

   tl5-compiler -t hello hello-tests.c hello.5.lm hello-tests.5.lm

will generate ``hello-tests.c`` C file from ``hello.5.lm`` and
``hello-tests.5.lm`` Lumi files, with C code that tests the ``hello`` module.

Compiling Shared Library Code
-----------------------------
To generate C code that can be compiled to a shared library :ref:`exporting
C styled functions <native_export>` from a specific Lumi
module ``-l <exported module name>`` should be used. For example::

   tl5-compiler -l hello hello-lib.c hello.5.lm other.5.lm

will generate ``hello-lib.c`` C file from ``hello.5.lm`` and
``other.5.lm`` Lumi files, with C code that can be compiled to a shared library
exporting functions from the ``hello`` module.

Building an Executable
----------------------
The generated C file can be compiled on its own to an executable using a C
compiler. For example::

   $CC hello.c -o hello

will generate ``hello`` executable.

Old Versions
------------
::

   ## TL4
   # compiling hello.4.lm to hello.c
   tl4-compiler hello.c hello.4.lm other.4.lm
   # compiling tests
   tl4-compiler -t hello hello-tests.c hello.4.lm hello-tests.4.lm
   # compiling the C code as an executable
   $CC hello.c TL4/lumi.4.c -ITL4 -o hello

   ## TL3
   # compiling hello.3.lm to hello.c
   tl3-compiler hello.3.lm
   # compiling the C code as an executable
   $CC hello.c TL3/lumi.3.c -I. -ITL3 -o hello

   ## TL2
   # compiling hello.2.lm to hello.c
   tl2-compiler hello.2.lm
   # compiling the C code as an executable
   $CC hello.c TL2/lumi.2.c -ITL2 -o hello

   ## TL1
   # compiling hello.1.lm to hello.c
   tl1-compiler hello.1.lm hello.c
   # compiling the C code as an executable
   $CC hello.c TL1/lumi.1.c -ITL1 -o hello

   ## TL0
   # compiling hello.0.lm to hello.c
   tl0-compiler hello.0.lm hello.c
   # compiling the C code as an executable
   $CC hello.c TL0/tl0-file.c TL0/tl0-string.c -ITL0 -o hello
