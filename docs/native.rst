Calling C Code
==============
Lumi allows calling C code directly. This is useful for using an external C
library, or using already written C code.

In :ref:`TL4 <syntax-tl4>` this is only basically implemented. It is planned to
extend this feature greatly to make this as convenient as possible. The full
syntax is still under planning.

In :ref:`TL4 <syntax-tl4>` in order to call C code one must know how the
various types in :ref:`TL4 <syntax-tl4>` are implemented in `lumi.4.h`_. If the
types do not match the C types needed, a proxy C file should be added to
convert the interface. This method should be used whenever a certain C item
cannot be called directly.

.. _lumi.4.h: https://github.com/meircif/lumi-lang/blob/master/TL4/lumi.4.h

Calling C Functions
-------------------
In order to call a C function it must be declared using the ``native func``
statement. The function is declared as a standard Lumi function, and the
C function should match the Lumi types as implemented in C. If this is not the
case a proxy C function must be used. The function name should use hyphens
(``-``) instead of C underscores (``_``). ::

   ; Allow calling a C function with the following header:
   ; "Returncode c_function_name(Int number, Int* result)"
   native func c-function-name(copy Int number)->(var Int result)

Native functions do not support ``owner`` access arguments.

This function can now be called as any standard Lumi function.

Accessing C Global Variables
----------------------------
In order to access a C global variable it must be declared using the
``native var`` statement. The variable is declared as any uninitialized Lumi
global variable. The variable name should use hyphens (``-``) instead of C
underscores (``_``). ::

   native var Int c-global-variable

Only primitive types can be declared as native variables.

This variable can now be accessed as any standard Lumi variable.

Accessing Custom C Types
------------------------
It is possible to handle references for custom C types. These types are treated
as "Abstract" references in Lumi, meaning that the exact structure is unknown
and cannot be accessed. This still can be used to store and manage references
for custom C types and use them as arguments to C functions that can use them.
C types can be declared using the ``native type`` statement. ::

   native type CustomCType

Native types are treated as any standard Lumi **primitive** type.
