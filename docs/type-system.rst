.. _type-system:

Type System
===========

Lumi is **strongly typed**, which means that:

1. Each symbol is statically bound to one specific type and can only hold data
   from this type.
2. Type correctness is enforced in compile time by the compiler.

Lumi has a variety of :ref:`built-in primitive and complex types <built-in>`,
and allows adding user defined types in a variety of typing styles. All these
allow writing code with different trade-off between simplicity, generality and
performance, and adapting different programming paradigms.


Typing Styles of User Defined Types
-----------------------------------
All user defined types in Lumi are built based on two basic typing styles:

1. :ref:`type-system-static`
2. :ref:`type-system-dynamic`

These can be combined to build more complex typing styles:

3. :ref:`type-system-extend`
4. :ref:`type-system-bind`
5. :ref:`type-system-parameterized`
6. :ref:`type-system-embed`
7. :ref:`type-system-automatic`


.. _type-system-static:

Static Structures
-----------------
Typing style for the :ref:`static structure syntax <syntax-static>`.

This is the most basic, simple and efficient typing style. A static structures
(or "structure" in short) is simply a record that groups together multiple
variables of any kind under one type.

Structures may contain methods. Methods are functions with an implicit first
parameter named ``self`` that is a reference to an instance of the type.

It is possible to declare constants and global variables inside a structure.
They are not part of the structure record, but are like normal constants and
global variables that are named under the type name-space.


.. _type-system-dynamic:

Dynamic Interfaces
------------------
Typing style for the :ref:`dynamic interface syntax <syntax-dynamic>`.

Dynamic interfaces are the basics of dynamic dispatch in Lumi. A dynamic
interface (or "dynamic" in short) groups together multiple dynamic members that
will be implemented differently for multiple objectives. Dynamics can be
implemented for a specific :ref:`structure <type-system-static>`, or purely
without any binding.

Dynamic members are usually methods, but variables and references of any type
can also be dynamic members - where each implementation initializes them with a
different constant value.

Dynamics are always used as references and cannot be allocated because they
have no structure. A dynamic references can be set with any type that
implements the dynamic.

"Implementing" a dynamic means implementing each dynamic method and
initializing each dynamic variable with a constant value.

Dynamics standard method dispatch is dynamic. This means that when an
implementing type is passed to a dynamic reference, any method called on the
dynamic reference will use the implementing type implementation.

Dynamics may contain constants and global variables, they are not dynamic
members and behave exactly as global members in :ref:`structures
<type-system-static>` - they are just global elements under the type
name-space.

Dynamics cannot have static fields, but may contain static methods. They are
also not dynamic members and behave exactly as methods in
:ref:`structures <type-system-static>` - they must be implemented directly in
the dynamic, and their dispatch is static.


.. _type-system-extend:

Extending Types
---------------
Types can be extended by adding functionality to some base types.

:ref:`Structures <type-system-static>` can extend other structures. An
extending structure contains all members from all base structures, plus its own
members. An extending structure can override methods of a base structure, other
members may not be overridden.

Structures method dispatch is **static**. This means that when an extending
structure is passed to a base structure reference, any method called on the
base reference will use the base structure implementation even if the extending
structure overrode that method.

:ref:`Dynamics <type-system-dynamic>` can extend other dynamics. An extending
dynamic contains all members from all base dynamics, plus its own members.

An extending structure may override any dynamic implementation of its base
structure. Nevertheless, if an extending structure reference is passed to a
base structure reference, and then the base structure reference is passed to a
dynamic reference, any method call on the dynamic reference will use the base
structure implementation because structure dispatch is static.


.. _type-system-bind:

Classes - Binding Dynamic Interfaces and Static Structures
----------------------------------------------------------
Typing style for the :ref:`class syntax <syntax-bind>`.

Sometimes binding together :ref:`static structures <type-system-static>` and
:ref:`dynamic interfaces <type-system-dynamic>` under a single type is useful,
mainly to adapt the OOP (object oriented programming) paradigm. A type with
this kind of binding is also known as a "class".

Classes may be ad-hock binds between already declared structures and dynamics,
or declared as classes up-front in a type definition. Types declared as classes
may have both static and dynamic members, and the compiler creates an implicit
static structure and an implicit dynamic interface - each with its respected
members. The compiler then creates the class as a bind between these both
implicit types.

Classes may extended any number of structures, dynamics, and other classes.
The extending class implicit structure extends all base structures and the
implicit structures of all base classes. Similarly, the extending class
implicit dynamic extends all explicit and implicit base dynamics.

Classes may also implement dynamics. Any implementation method of the dynamic
is also dynamic in the class. As opposed to structures, if an extending
class reference is passed to a base class reference, and then the base class
reference is passed to a dynamic reference, any method call on the dynamic
reference will use the the extending class implementation because class
dispatch is also dynamic.


.. _type-system-parameterized:

Parameterized Types
-------------------
Typing style for the :ref:`parameterized type syntax <syntax-parameterized>`.

It is possible to declare types with parameters to avoid code duplication of
generic types. Each parameter can be either **static** or **dynamic**.


Static Parameters
+++++++++++++++++
Static parameters are like templates - for each different usage of any static
parameter a new type will be automatically generated. Static parameters can be
type names, or constant values of a specific type.


Dynamic Parameters
++++++++++++++++++
Dynamic parameters represent a generic type and only accept type names.

The main advantage of dynamic parameters is that - as oppose to static
parameters - different usage of it will **not** generated a new type.

The disadvantage is that dynamic parameters can only be used as abstract
references, as the same code handles references of different types with unknown
structure.


.. _type-system-embed:

Embedding a Dynamic Reference in a Static Structures
----------------------------------------------------
Typing style for the :ref:`embedded dynamic reference syntax <syntax-embed>`.

For some memory optimization scenarios, it is better if a dynamic reference
of a class will be implemented only with one C pointer, and the dynamic
structure reference will be embedded inside the type static structure (as done
in C++).

Lumi will support this, but the exact implementation is still under planning.


.. _type-system-automatic:

Automatic Dynamic Interfaces
----------------------------
This is an experimental typing style idea that will allow automatic creation
and implementation of dynamic interfaces based on the actual usage of a
reference.

For each reference typed as ``Auto`` the compiler will automatically create a
dynamic interface based on the methods called on this reference. Any type that
implements the same methods used by the reference can be assigned to it, and an
implementation of the dynamic interface will be automatically created by the
compiler. For example::

   ; a dynamic interface with "example" method will be created buy the compiler
   ; and used as the parameter actual type
   func auto-example(user Auto automatically-typed-dynamic-reference)
       automatically-typed-dynamic-reference.example()

   struct SomeStruct
       func some-method()

   var SomeStruct some-item
   ; implementation to the automatically created dynamic interface will be
   ; created by the compiler that uses "SomeStruct.example" method as the
   ; implementation to the "example" dynamic method
   auto-example(user some-item)

This feature is an experimental idea because it's unclear whether it is a good
idea, and there may be some edge cases that will make it hard to implement.
