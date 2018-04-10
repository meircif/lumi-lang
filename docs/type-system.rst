.. _type-system:

Type System
===========

Lumi is **strongly typed**, which means that:

1. Each symbol is statically bound to one specific type and can only hold data
   from this type.
2. Type correctness is enforced in compile time by the compiler.

Lumi has a variety of
:ref:`primitive types and built-in complex types<syntax>` that can be used to
create user defined types. These can be created in a variety of typing styles
with different trade-offs between simplicity, generality and performance:

1. :ref:`type-system-static`
2. :ref:`type-system-dynamic`
3. :ref:`type-system-mix`
4. :ref:`type-system-embed`
5. :ref:`type-system-parametrized`
6. :ref:`type-system-automatic`

.. _type-system-static:

Static Structures
-----------------

This is the most basic, simple and efficient typing style.

Static structures are declared using the ``struct`` keyword:
::

   ~~~ Static structure example. ~~~
   struct Example-struct
     ; may contain variables and references
     var Int integer-variable
     user String string-reference

     ; may contain method declarations, the implementation can come later...
     func method(copy Int num)

     ; may contain global members
     const Int GLOBAL-CONSTANT(12)
     global var Int global-variable
     global func global-function(copy Int num)

     ; methods implementation, use "self" and "global" to access instance and
     ; global members respectively
     func method(copy Int num)
       self.integer-variable := num + global.GLOBAL-CONSTANT
       global.global-variable := num

     func global-function(copy Int num)
       global.global-variable := num

   ~~~ A static structure that extends other structures.
   It contains all members from all extended structures.
   * In case of a diamond extension - the memory is duplicated.
   ~~~
   struct Extending-struct(Example-struct, Other-struct)
     ; more members can be added
     var Int additional-field

     ; can override methods of extended structures, but not fields
     func method(copy Int num)
       self.additional-field := num
       Example-struct.method(copy num)  ; call overridden method

   ; Dispatch is static
   var Extending-struct extending-struct
   user Example-struct base-struct(extending-struct)
   extending-struct.method(copy 4)  ; will call Extending-struct.method
   base-struct.method(copy 4)  ; will call Example-struct.method

.. _type-system-dynamic:

Dynamic Interfaces
------------------

Dynamic interfaces are the basics of dynamic dispatch in MR.

Dynamic interfaces are declared using the ``dynamic`` keyword:
::

   ~~~ Dynamic interface example ~~~
   dynamic Example-dynamic
     ; may contain dynamic methods
     func dynamic-func(copy Int num)

     ; usually dynamic interfaces will only contain dynamic methods,
     ; but it may contain any other member except static fields:
     var Int dynamic-variable
     static func static-method()
     ; and global members as in static structures

   ; Types can now implement this interface retroactively:
   implement Example-dynamic for Example-struct
     ; all dynamic methods must be implemented
     func dynamic-func(copy Int num)
       self.integer-variable := num

     ; all dynamic fields must be set with values
     var Int dynamic-variable(global.GLOBAL-CONSTANT)

   ; The dispatch is dynamic
   var Example-struct example-struct
   user Example-dynamic example-dynamic(example-struct)
   example-dynamic.dynamic-func(copy 5)

Dynamic interfaces can extend other dynamic interfaces the same way as static
structures.

*As opposed to static structure references that are simply implemented by one C
pointer, dynamic interface references are implemented using 2 C pointers - one
for the static structure and one for the dynamic structure.*

.. _type-system-mix:

Mixing Dynamic Interfaces and Static Structures
-----------------------------------------------

Sometimes binding together Static Structures and Dynamic Interfaces is needed.

The simple way to do this is using the built-in ``Bind`` type:
::

   ; a reference to a type that both extends "Example-struct" and implements
   ; "Example-dynamic"
   user Bind{Example-struct:Example-dynamic} mixed-reference

Another way is to declared a type as a mix in its definition using the ``class``
keyword:
::

   class Mixed-type
     ; every member must specify whether it is static or dynamic
     static var Int static-field
     dynamic func dynamic-func(copy Int num)

Mixed types can extend other static structures, dynamic interfaces and mixed
types.

*As dynamic interface references, mixed type references are implemented using 2
C pointers - one for the static structure and one for the dynamic structure.*

.. _type-system-embed:

Embedding Dynamic Reference in Static Structures
------------------------------------------------

For some memory optimization scenarios, it is better if a dynamic reference
will be implemented only with one C pointer, and the dynamic structure
reference will be embedded inside the type static structure (as done in C++).

This can be done using the built-in ``Embed`` type:
::

   ; An "Example-struct" structure with "Example-dynamic" reference embedded
   ; inside it
   var Embed{Example-struct:Example-dynamic} embedded-variable
   ; A "Mixed-type" static structure with a reference to its dynamic structure
   ; embedded inside
   var Embed{Mixed-type} embedded-mixed-variable

.. _type-system-parametrized:

Parametrized types
------------------

It is possible to declare types with parameters:
::

   struct Parametrized-type{Int SIZE:Type Generic}
     var Generic parametrized-typed-variable
     var Buffer{SIZE} parametrized-sized-variable

   ; For each usage of the parametrized-type a new type will be automatically
   ; generated
   var Parametrized-type{8:Int} specific-variable

Any type can be parametrized.

.. _type-system-automatic:

Automatic Dynamic Interfaces
----------------------------

This is an experimental feature idea that will allow automatic creation and
implementation of dynamic interfaces based on the actual usage of a reference.

For each reference typed as ``Auto`` the compiler will automatically create a
dynamic interface based on the methods called on this reference. Any type that
implements the same methods used by the reference can be assigned to it, and an
implementation of the dynamic interface will be automatically created by the
compiler.
::

   struct Some-struct
     func some-method()

   var Some-struct some-item
   user Auto automatically-typed-dynamic-reference(some-item)
   automatically-typed-dynamic-reference.some-method()

This feature is an experimental idea because it's unclear whether it is a good
idea, and there may be some edge cases that will make it hard to implement.
