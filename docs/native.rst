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


C Primitives
++++++++++++
``cdef`` contains many C primitive types:

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
``cdef`` contains ``cdef.Pointer`` generic type to declare C pointers::

   var cdef.Pointer{cdef.Int} pointer-to-int
   var cdef.Pointer{cdef.Char} pointer-to-char
   ; "cdef.CharP" is an alias to "cdef.Pointer{cdef.Char}"
   var cdef.CharP also-pointer-to-char
   var cdef.Pointer{cdef.Uchar} pointer-to-uchar
   var cdef.Pointer{cdef.Pointer{cdef.Int}} pointer-to-pointer-to-int
   var cdef.Pointer void-pointer

Set and get pointed value::
   
   var cdef.Int value
   pointer-to-int.set-point-to(var value)
   pointer-to-pointer-to-int.set-point-to(var pointer-to-int)
   pointer-to-int := pointer-to-pointer-to-int.get-pointed-at(copy 0)
   value := pointer-to-int.get-pointed-at(copy 0)

Get and set pointer from array, string and buffer::
   
   user Array{cdef.Int} int-array
   user String string
   user Buffer buffer
   pointer-to-int := int-array
   pointer-to-char := string
   pointer-to-uchar := buffer
   value := pointer-to-int.get-pointed-at(copy 3)
   cdef.copy-to-string(copy pointer-to-char, user string)!
   cdef.copy-to-buffer(copy pointer-to-uchar, copy 4, user buffer)!
   
Pointer to complex types::
   
   user SomeStruct reference
   var cdef.Pointer{SomeStruct} pointer-to-struct
   pointer-to-struct := reference
   reference := pointer-to-struct.get-ref-at(copy 0)


Calling C Functions
-------------------
To call a C function from Lumi it must first be declared using the
``native func`` statement::

   ; allow calling a C function with header:
   ; "int some_c_function(int number)"
   native func cdef.Int some-c-function(copy cdef.Int number)
   ; "_" characters in the C function name are replaced with "-" in Lumi
   
   ; allow calling a C function with header:
   ; "void CfunctionName(int number, char* text)"
   native func name-used-in-lumi(
       copy cdef.Int number,
       copy cdef.Pointer{cdef.Char} text) "CfunctionName"
   ; Lumi name can be different that the C name

These functions can now be called from Lumi code using their Lumi name.

Native functions Have some limitation compared to normal Lumi functions:

* have no output arguments, only input parameters
* all parameters must be primitives, with ``copy`` access
* cannot be called with output arguments:
  ``native-function()->(copy output-argument)`` is illegal, may use
  ``output-argument := native-function()`` instead


Accessing C Global Variables
----------------------------
In order to access a C global variable it must be declared using the
``native var`` statement::

   ; allow accessing "int some_c_variable" global variable
   native var cdef.Int some-c-variable
   
   ; allow accessing "char* CvariableName" global variable
   native var cdef.Pointer{cdef.Char} name-used-in-lumi "CvariableName"

These variables can now be accessed from Lumi code using their Lumi name.

Only primitive types can be declared as native variables.


Accessing C Global Constants or Defines
---------------------------------------
In order to access a C global constant or a ``#define`` value it must be
declared using the ``native const`` statement::

   ; allow accessing "SOME_C_CONSTANT" global constant
   native const cdef.Int SOME-C-CONSTANT

   ; allow accessing "c_constant_name" global constant
   native const cdef.Int NAME-USED-IN-LUMI "c_constant_name"

These constant can now be accessed from Lumi code using their Lumi name.

Only primitive types can be declared as native constants. Currently in
:ref:`TL5 <syntax-tl5>` only integer types are supported.


Accessing C Structures
----------------------
It is possible to access custom C structures and their internal fields using
the ``native struct`` statement with ``var`` lines for each needed field::
   
   ; allow using "SomeCStruct" structure that have fields:
   ;   int some_filed;
   ;   char* other_field;
   native struct SomeCStruct
       var cdef.Int some-filed
       var cdef.Pointer{cdef.Char} other-field
   
   ; allow using "struct c_struct_name" structure that have fields:
   ;   int CfieldName;
   ;   char* CanotherName;
   native struct NameUsedInLumi "struct c_struct_name"
       var cdef.Int field-name-used-in-lumi "CfieldName"
       var cdef.Pointer{cdef.Char} another-lumi-field "CanotherName"

Not all of the original fields must be declared - only the ones that are needed
to be used in Lumi. It is also legal to not declare any fields at all::
   
   native struct SomeCStruct

These structures can now be accessed from Lumi code using their Lumi name.

Native structures are treated as values and not as references like Lumi
structures. A pointer to the native structures can be used instead::

   var cdef.Pointer{SomeCStruct} pointer-to-native-struct

Native structures fields are accessed as in Lumi structures:
``native-struct.some-filed``. This also works with pointers to native
structures: ``pointer-to-native-struct.some-filed``.

Native structures can be used in other native functions, variables, constants,
and structures::

   native func SomeCStruct c-func-name(copy SomeCStruct input)
   native func cdef.Pointer{SomeCStruct} other-func(
       copy cdef.Pointer{SomeCStruct} input)
   native var SomeCStruct c-var-name
   native var cdef.Pointer{SomeCStruct} other-var
   native struct CstructName
      var SomeCStruct struct-field
      var cdef.Pointer{SomeCStruct} pointer-field
      var cdef.Pointer{OtherStruct} self-pointer


Accessing Custom C Types
------------------------
It is possible to handle values for custom C types that may be of any kind:
integers, structures, pointers, etc. These types are treated as "abstract"
values in Lumi, meaning that their exact structure is unknown and cannot be
accessed.

C types can be declared using the ``native type`` statement::

   ; allow using "SomeCtype" type:
   native type SomeCtype
   
   ; allow using "c_type_name" type:
   native type NameUsedInLumi "c_type_name"

These types can now be accessed from Lumi code using their Lumi name.

Native types are treated as abstract unknown values, the only way to use their
content is by other C functions.


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

This may be used in some special cases where the other methods above are not
sufficient, or to write some special glue code between Lumi and C.


C Wrapper Code
--------------
It's recommended to wrap native C declarations with pure Lumi declarations that
takes care for correct usage of the C declarations, and to present a simple and
safe pure Lumi interface.
