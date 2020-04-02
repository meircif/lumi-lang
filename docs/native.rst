.. _native:

Calling C Code
==============
Lumi allows calling C code directly. This is useful for using an external C
library, or using already written C code.

.. warning::

   Calling C code cannot be guaranteed to be safe as the C code can mangle with
   the Lumi memory management.


The ``cdef`` Module
-------------------
The builtin ``cdef`` module contains various C declarations that help
interacting with C code.

It contains many C primitive types:

* ``cdef.Char``
* ``cdef.Uchar``
* ``cdef.Short``
* ``cdef.Ushort``
* ``cdef.Int``
* ``cdef.Uint``
* ``cdef.Long``
* ``cdef.Ulong``
* ``cdef.Size``
* ``cdef.Float``
* ``cdef.Double``
* ``cdef.LongDouble``


C Pointers
++++++++++
It also contains ``cdef.Pointer`` generic type to declare C pointers::

   var cdef.Pointer{cdef.Int} pointer-to-int
   var cdef.Pointer{cdef.Char} pointer-to-char
   var cdef.Pointer{SomeStruct} pointer-to-user-defined-struct
   var cdef.Pointer{cdef.Pointer{cdef.Int}} pointer-to-pointer-to-int
   var cdef.Pointer void-pointer
   
   ; pointer methods
   var cdef.Int value
   pointer-to-int.set-point-to(var value)
   pointer-to-pointer-to-int.set-point-to(var pointer-to-int)
   pointer-to-int := pointer-to-pointer-to-int.get-pointed-at(copy 0)
   value := pointer-to-int.get-pointed-at(copy 0)
   
   ; from array
   user Array?{cdef.Int} int-array
   pointer-to-int.set-from-array(user int-array)
   value := pointer-to-int.get-pointed-at(copy 3)
   
   ; from reference
   user SomeStruct? reference
   pointer-to-user-defined-struct.set-from-ref(user reference)
   reference := pointer-to-user-defined-struct.get-ref-at(copy 0)


Calling C Functions
-------------------
In order to call a C function it must be declared using the ``native func``
statement the same way as a standard Lumi function. ::

   ; Allow calling a C function with the following header:
   ; "int c_function_name(int number)"
   native func name-used-in-lumi(
           copy cdef.Int number)->(copy cdef.Int result) "c_function_name"

This function can now be called as any standard Lumi function.

Native functions Have some limitation compared to normal Lumi functions:

* ``owner``, ``strong`` or ``weak`` arguments are unsupported
* only up to one primitive output is supported
* primitive outputs must be ``copy``, not ``var``
* cannot be called with output arguments:
  ``native-function()->(copy output-argument)`` is illegal, may use
  ``output-argument := native-function()`` instead


Accessing C Global Variables
----------------------------
In order to access a C global variable it must be declared using the
``native var`` statement. The variable is declared as any uninitialized Lumi
global variable. ::

   native var cdef.Int name-used-in-lumi "c_variable_name"

Only primitive types can be declared as native variables.

This variable can now be accessed as any standard Lumi variable.


Accessing C Global Constants or Defines
---------------------------------------
In order to access a C global constant or ``#define`` value it must be
declared using the ``native const`` statement. The constant is declared as any
uninitialized Lumi global constant. ::

   native const cdef.Int name-used-in-lumi "C_CONSTANT_NAME"

Only ``Int`` Types can be declared as a native constant.

This constant can now be accessed as any standard Lumi constant.


Accessing C Structures
----------------------
This is not supported yet in :ref:`TL5 <syntax-tl5>`.

It is possible to access custom C structures and their internal fields using
the ``native struct`` statement with ``var`` lines for each needed field::
   
   native struct NameUsedInLumi "c_struct_name_t"
       var cdef.Int field-name-used-in-lumi "c_field_name"
       var cdef.Int other-field "other_field"

Not all the original fields must be declared - only the ones that are needed to
be used in Lumi. It is also legal to not declare any fields at all.


Accessing Custom C Types
------------------------
It is possible to handle values for custom C types. These types are treated
as "abstract" values in Lumi, meaning that their exact structure is unknown
and cannot be accessed.

C types can be declared using the ``native type`` statement. ::

   native type NameUsedInLumi "c_type_name_t"

Native types are treated as any standard Lumi **primitive** type, so this is
only useful to store and manage primitive C typedefs, or pointers to C
structures. The only way to use their content is by other C functions.


Writing C code directly
------------------------
It is possible to write C code directly using ``native code`` in global scope,
or just ``native`` inside a function ::

   native code "#define SOME_NEEDED_DEFINE 1"

   func is-unix()->(var Bool result)
       native "#ifdef __UNIX__"
       result := true
       native "#else"
       result := false
       native "#endif"

C Wrapper Code
--------------
It's recommended to wrap C declarations with pure Lumi declarations that takes
care for correct usage of the C declarations.
