Installing and Building Lumi
============================

.. highlight:: shell

Syntax Highlighting
-------------------

For Lumi syntax highlighting it's recommended to use `Atom`_ editor with
`language-lumi package`_ installed.

Installing Lumi
---------------
.. note::
   In all shell examples below ``$CC`` assumed to hold the C compiler, and the
   current directory assumed to be on `Lumi repository`_ root directory

1. clone or download `Lumi repository`_: ``git clone
   https://github.com/meircif/lumi-lang.git``
2. :ref:`build the latest Lumi compiler <build-compiler>` with a C compiler:
   ``$CC TL4/tl4-compiler.c TL3/lumi.3.c -ITL3 -ITL4 -I. -o tl4-compiler``

optional but recommended:

3. :ref:`build the "lumi" command <build-lumi-command>` with a C compiler:
   ``$CC lumi.c TL4/lumi.4.c -ITL4 -o lumi``
4. add the Lumi compiler and the ``lumi`` command to the system path

.. _build-compiler:

Building the Lumi Compiler
--------------------------
A Lumi compiler must first be compiled using a C compiler. That Lumi compiler
can then be used to generate C code from Lumi code.

Latest Version - TL4 Compiler
+++++++++++++++++++++++++++++
::

   $CC TL4/tl4-compiler.c TL3/lumi.3.c -ITL3 -ITL4 -I. -o tl4-compiler

Old Versions
++++++++++++
::

   # TL3 compiler
   $CC TL3/tl3-compiler.c TL2/lumi.2.c -ITL2 -o tl3-compiler

   # TL2 compiler
   $CC TL2/tl2-compiler.c TL1/lumi.1.c -ITL1 -o tl2-compiler

   # TL1 compiler
   $CC TL1/tl1-compiler.c TL0/tl0-file.c TL0/tl0-string.c -ITL0 -o tl1-compiler

   # TL0 compiler
   $CC TL0/tl0-compiler.c TL0/tl0-file.c TL0/tl0-string.c -o tl0-compiler

.. _build-lumi-command:

Building the ``lumi`` Command
-----------------------------
The ``lumi`` command must first be compiled using a C compiler. ``lumi``
command can then be :ref:`used <using-lumi-command>` to compile an executable
directly from Lumi code by running Lumi compiler and C compiler one after
another.

::

   $CC lumi.c TL4/lumi.4.c -ITL4 -o lumi

.. _Atom: https://atom.io
.. _language-lumi package: https://atom.io/packages/language-lumi
.. _Lumi repository: https://github.com/meircif/lumi-lang
