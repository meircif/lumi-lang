.. _type-system:

Type System
===========

Lumi is **strongly typed**, which means that:

1. Each symbol is statically bound to one specific type and can only hold data
   from this type.
2. Type correctness is enforced in compile time by the compiler.

Lumi has a variety of :ref:`primitive types and built-in complex
types <built-in>` that can be combined to create user defined types. These can
be created in a variety of typing styles with different trade-offs between
simplicity, generality and performance:

1. :ref:`type-system-static`
2. :ref:`type-system-dynamic`
3. :ref:`type-system-bind`
4. :ref:`type-system-embed`
5. :ref:`type-system-parametrized`
6. :ref:`type-system-automatic`

In :ref:`TL4 <syntax-tl4>` only basic :ref:`static structures
<type-system-static>` and :ref:`mixed classes <type-system-mix>` are supported.

User defined types behave like built-in complex types with :ref:`references
<references>`, :ref:`static allocation <static-allocation>` and :ref:`dynamic
allocation <dynamic-allocation>`.

.. _type-system-static:

Static Structures
-----------------

This is the most basic, simple and efficient typing style. A static structures
(or "structure" in short) is simply a record that groups together multiple
variables of any kind under one type.

It's implemented in C as a simple C structure, and have similar behavior.

In :ref:`TL4 <syntax-tl4>`, structures may not contain string or array
variables, only their respected references. It will be supported in the final
Lumi syntax.

Structures are declared using the ``struct`` keyword::

   struct ExampleStruct
     var Int integer-variable
     user String string-reference

Members of struct can be accessed using ``.`` operator::

   var ExampleStruct struct-variable
   struct-variable.integer-variable := 3
   struct-variable.string-reference := "some string"

.. _global-members:

Global Members
++++++++++++++

It is possible to declare constants and global variables inside a structure.
They are not part of the structure record, but are like normal constants and
global variables that are named under the type name-space. This is not
supported yet in :ref:`TL4 <syntax-tl4>`. They are declared under the type
scope::

   struct ExampleStruct
     const Int GLOBAL-CONSTANT(12)
     global var Int global-variable


Outside the type definitions they can only be accessed with the type name as
prefix::

   some-integer := ExampleStruct.GLOBAL-CONSTANT
   ExampleStruct.global-variable := 5

.. _static-methods:

Methods
+++++++

Structures may contain methods. Methods are functions with an implicit first
parameter named ``self`` that is a reference to an instance of the type.
Methods are declared as normal functions, except they are declared inside the
type scope, and the ``self`` parameter should not be declared. Inside the
method implementation ``self`` keyword can be used to access the implicit
self parameter. Constants and global variables of the type can be accessed
using ``global`` keyword. ::

   struct ExampleStruct
     var Int integer-variable

     const Int GLOBAL-CONSTANT(12)
     global var Int global-variable

     func method(copy Int num)
       self.integer-variable := num + global.GLOBAL-CONSTANT
       global.global-variable := num

It possible to split the function deceleration from its implementation. In this
case the function deceleration should be followed by ``_``. This is not
supported yet in :ref:`TL4 <syntax-tl4>`. ::

   struct ExampleStruct
     func method(copy Int num) _

   func ExampleStruct.method(copy Int num)
     ; implementation...

There are 2 ways to call a method::

   instance.method(copy 4)  ; OOP style
   ExampleStruct.method(var instance, copy 4)  ; functional style

Extending Structures
++++++++++++++++++++
Structures can extend other structures. An extending structure contains all
members from all base structures, plus its own members. In :ref:`TL4
<syntax-tl4>` a structure may only extend one other structure. ::

   struct ExtendingStruct(BaseStruct, OtherBaseStruct)
     var Int additional-field

The extending structure may be used in any place one of its base structures is
expected::

   user BaseStruct base-struct := ExtendingStruct()

An extending structure can override methods of a base structure, other members
may not be overridden. The overwriting function arguments must be identical to
the base overridden function. ::

   struct BaseStruct
     func method(copy Int num)
       ; implementation...

   struct ExtendingStruct(BaseStruct)
     func method(copy Int num)
       ; other implementation...

Structures are **static** - therefore their method dispatch is static. This
means that in case of calling a method with multiple implementations - the
method matching the static type of the instance is called. Calling a method
with an explicit type always calls that explicit types method. ::

   var ExtendingStruct extending-struct
   user BaseStruct base-struct(user extending-struct)
   extending-struct.method(copy 4)  ; will call ExtendingStruct.method
   base-struct.method(copy 4)  ; will call BaseStruct.method
   BaseStruct.method(var extending-struct, copy 4)  ; will call BaseStruct.method

.. _type-system-dynamic:

Dynamic Interfaces
------------------
This is not supported yet in :ref:`TL4 <syntax-tl4>`.

Dynamic interfaces are the basics of dynamic dispatch in Lumi. A dynamic
interface (or "dynamic" in short) groups together multiple dynamic members that
will be implemented differently for multiple objectives. Dynamics can be
implemented for a specific :ref:`structure <type-system-static>`, or purely
without any binding.

Dynamics are implemented in C as a C structure containing all the dynamic
members, where dynamic methods are implemented as pointer to functions. Each
implementation of the dynamic is a global instance of this structure.

Dynamics are declared using the ``dynamic`` keyword::

   dynamic ExampleDynamic
     func dynamic-method(copy Int num)
     func another-method()->(var Int result)

Dynamics are always used as ``user`` access references, as there is nothing to
"allocate". Because the most common implementations of dynamics are for a
specific :ref:`structure <type-system-static>`, dynamic references also hold an
additional reference to a generic structure which is passed to the methods as
the first ``self`` parameter. ::

   var ImplementingStructure implementing-structure
   user ExampleDynamic dynamic-reference(user implementing-structure)
   dynamic-reference.dynamic-method(copy 4)

Using a pure dynamic without the binding can be done with the built-in
``Dynamic`` type, that only accepts implemented dynamic type names as value::

   user Dynamic{ExampleDynamic} dynamic-reference(user ExtendingDynamic)
   dynamic-reference.dynamic-method(copy 4)

Dynamic Variables
+++++++++++++++++
Dynamics can also contain dynamic variables that hold constant values for each
specific implementation of the interface::

   dynamic ExampleDynamic
     func dynamic-method(copy Int num)
     func another-method()->(var Int result)
     var Int dynamic-variable

"Implementing" a dynamic variable means initializing it with a value.

Non-Dynamic Members
+++++++++++++++++++
Dynamics may contain constants and global variables, they are not dynamic
members and they behave exactly as the :ref:`global members in static
structures <global-members>`- they are just global elements under the dynamic's
name-space.

Dynamics may also contain static methods. They behave exactly as the
:ref:`methods in static structures <static-methods>` - they must be implemented,
and their dispatch is static.

Extending Dynamics
++++++++++++++++++
Dynamics can extend other dynamics. An extending dynamic contains all members
from all base dynamics, plus its own members. ::

   dynamic ExtendingDynamic(BaseDynamic, OtherBaseDynamic)
     func additional-method(copy Int num)

Dynamics are **dynamic** - therefore their method dispatch is dynamic. This
means that in case of calling a method with multiple implementations - the
method matching the dynamic runtime type of the instance is called. Calling a
method with an explicit type always calls that explicit types method.


Implementing Dynamics
+++++++++++++++++++++
The most common implementations of dynamics are for a specific
:ref:`structure <type-system-static>`. This can be done using the ``implement``
keyword. All the dynamic members must be implemented. Method implementations
can use ``self`` and ``global`` keywords to access its own members, and also
members of the implemented dynamic. ::

   implement ExampleDynamic for ExampleStructure
   func dynamic-method(copy Int num)
     ; implementation...
   func another-method()->(var Int result)
     ; another implementation...
   var Int dynamic-variable(copy 4)

A dynamic may implement some or all of its members and its base dynamics
members. Method implementations can use ``self`` and ``global`` keywords to
access its own members. ::

   dynamic ExampleDynamic
     func implemented-method(copy Int num) _
     func unimplemented-method()->(var Int result)
     var Int implemented-variable(copy 5)
     var Int unimplemented-variable

   func ExampleDynamic.implemented-method(copy Int num) _
     ; implementation...

When a dynamic implements all its and its base dynamics members, it's
considered as implemented and can be used as a value to ``Dynamic`` references.

.. _type-system-bind:

Binding Dynamic Interfaces and Static Structures
------------------------------------------------

Sometimes binding together :ref:`static structures <type-system-static>` and
:ref:`dynamic interfaces <type-system-dynamic>` under a single type is useful,
mainly to achieve OOP (object oriented programming) style architecture. A type
with this kind of binding is also known as a "class".

A straightforward way to use classes is using the built-in ``Bind`` typed
references. References of this type only accept types that extend all binded
structures and implement all binded dynamics. ::

   user Bind{ExampleStruct:ExampleDynamic} class-reference

Another way to use classes is to declare a type as a class in its definition
using the ``class`` keyword. This class may have both static and dynamic
members, and creates an implicit static structure and an implicit dynamic
interface - each with its respected members. The defined class is a bind
between these both implicit types . Each non-global member must come after a
``static`` or a ``dynamic`` keyword to declare witch implicit type this member
belongs to: the structure or the dynamic. Global members are only defined under
the name-space of the class. ::

   class ExampleClass
     static var Int static-field  ; part of the implicit structure
     dynamic func dynamic-func(copy Int num)  ; part of the implicit dynamic
     global var Int global-variable  ; defined under the class name-space

Class references are implemented using two C pointers: one for the structure,
and one for the dynamic.

In :ref:`TL4 <syntax-tl4>` this only partially implemented:

* Only ``class`` type definition is supported, ``Bind`` is not
* All restrictions on structures also apply to classes
* Only methods can be dynamic
* Variables don't need to start with ``static`` keyword - as they cannot be
  dynamic or global

Extending Classes
+++++++++++++++++
Classes may extended any number of structures, dynamics, and other classes.
The extending class implicit structure extends all base structures and the
implicit structures of all base classes. Similarly, the extending class
implicit dynamic extends all explicit and implicit base dynamics.

Although classes have a dynamic interface, they cannot be implemented for
another structure as dynamics, because they also have a static structure.

Using Classes Implicit Structure or Dynamic
+++++++++++++++++++++++++++++++++++++++++++

The implicit structure of a class can be used using the built-in ``Struct``
type, and the implicit dynamic can be used using the built-in ``Dynamic``
type. This is not supported in :ref:`TL4 <syntax-tl4>`. ::

   var Struct{ExampleClass} static-structure-only
   user Dynamic{ExampleClass} dynamic-interface-only

.. _type-system-embed:

Embedding Dynamic Reference in Static Structures
------------------------------------------------
This is not supported yet in :ref:`TL4 <syntax-tl4>`.

For some memory optimization scenarios, it is better if a dynamic reference
will be implemented only with one C pointer, and the dynamic structure
reference will be embedded inside the type static structure (as done in C++).

This can be done using the built-in ``Embed`` type: ::

   ; "ExampleStruct" structure with "ExampleDynamic" reference embedded
   ; inside it
   var Embed{ExampleStruct:ExampleDynamic} embedded-variable
   ; "ExampleClass" static structure with a reference to its dynamic structure
   ; embedded inside it
   var Embed{MixedType} embedded-mixed-variable

.. _type-system-parametrized:

Parametrized types
------------------

It is possible to declare types with parameters::

   struct ParametrizedType{Int SIZE:Type Generic}
     var Generic parametrized-typed-variable
     var Buffer{SIZE} parametrized-sized-variable

   ; For each usage of the parametrized-type a new type will be automatically
   ; generated
   var ParametrizedType{8:Int} specific-variable

Any type can be parametrized.

This is partially supported in :ref:`TL4 <syntax-tl4>`.

.. _type-system-automatic:

Automatic Dynamic Interfaces
----------------------------
This is not supported in :ref:`TL4 <syntax-tl4>`.

This is an experimental feature idea that will allow automatic creation and
implementation of dynamic interfaces based on the actual usage of a reference.

For each reference typed as ``Auto`` the compiler will automatically create a
dynamic interface based on the methods called on this reference. Any type that
implements the same methods used by the reference can be assigned to it, and an
implementation of the dynamic interface will be automatically created by the
compiler. ::

   struct SomeStruct
     func some-method()

   var SomeStruct some-item
   user Auto automatically-typed-dynamic-reference(user some-item)
   automatically-typed-dynamic-reference.some-method()

This feature is an experimental idea because it's unclear whether it is a good
idea, and there may be some edge cases that will make it hard to implement.
