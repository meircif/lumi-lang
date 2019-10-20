User Defined Types
==================

As explained in :ref:`type-system`, Lumi allows variety of typing styles for
creating user defined types.

In :ref:`TL5 <syntax-tl5>` only basic :ref:`structures <syntax-static>` and
:ref:`classes <syntax-bind>` are supported.

User defined types behave like built-in complex types with :ref:`references
<references>`, :ref:`static allocation <static-allocation>` and :ref:`dynamic
allocation <dynamic-allocation>`.

.. _syntax-static:

Static Structures
-----------------
Syntax for the :ref:`static structure typing style <type-system-static>`.

In :ref:`TL5 <syntax-tl5>`, structures may not contain string or array
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
This is not supported yet in :ref:`TL5 <syntax-tl5>`.

Global members are declared under the type scope::

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
Methods are declared as normal :ref:`functions <functions>`, except they are
declared inside the type scope, and the ``self`` parameter should not be
declared. Inside the method implementation ``self`` keyword can be used to
access the implicit self parameter. Constants and global variables of the type
can be accessed using ``global`` keyword. ::

   struct ExampleStruct
       var Int integer-variable

       const Int GLOBAL-CONSTANT(12)
       global var Int global-variable

     func method(copy Int num)
         self.integer-variable := num + global.GLOBAL-CONSTANT
         global.global-variable := num

It possible to split the function deceleration from its implementation. In this
case the function deceleration should be followed by ``_``. This is not
supported yet in :ref:`TL5 <syntax-tl5>`. ::

   struct ExampleStruct
       func method(copy Int num) _

   func ExampleStruct.method(copy Int num)
       ; implementation...

There are two ways to call a method::

   instance.method(copy 4)  ; OOP style
   ExampleStruct.method(var instance, copy 4)  ; functional style

Construction and Destruction
++++++++++++++++++++++++++++
Structure members are automatically initialized to their default value on
construction. This can be extended by defining a "constructor" method for the
structure. This method will be called on every instance construction after the
default initialization. A constructor is declared as a normal method with a
dedicated name ``new``. ::

   struct ExampleStruct
       new() _

   func ExampleStruct.new()
       ; custom initialization

A constructor cannot have outputs, and if it has parameters - they must be
given on every object creation::

   struct ExampleStruct
       new(copy Int x, user String s)
           ; implementation

   func usage()
       var ExampleStruct variable(copy 4, user "some string")
       owner ExampleStruct reference := ExampleStruct(copy 4, user "some string")

A "destructor" method can also be defined for a structure. This method will be
called just before any object destruction. A destructor is declared as a normal
method with a dedicated name ``delete``. This is not supported yet in :ref:`TL5
<syntax-tl5>`. ::

   struct ExampleStruct
       func delete() _

   func ExampleStruct.delete()
       ; destruction code

A destructor cannot have any kind of arguments.

Extending Structures
++++++++++++++++++++
In :ref:`TL5 <syntax-tl5>` a structure may only extend one other structure. ::

   struct ExtendingStruct(BaseStruct, OtherBaseStruct)
       var Int additional-field

The extending structure may be used in any place one of its base structures is
expected::

   owner BaseStruct base-struct := ExtendingStruct()

The extending structure may overwrite a base method, the overwriting method
arguments access and type must be identical to the base overridden method. ::

   struct BaseStruct
       func method(copy Int num)
           ; implementation...

   struct ExtendingStruct(BaseStruct)
       func method(copy Int num)
           ; other implementation...

An overwriting function can call the overwritten function using ``base``
keyword. Other overwritten methods can be called using ``base.other-method``.
::

   struct ExtendingStruct(BaseStruct)
       func method(copy Int num)
           base(copy num)
           base.other-method()

Example for the **static** dispatch of structures::

   var ExtendingStruct extending-struct
   user BaseStruct base-struct(user extending-struct)
   extending-struct.method(copy 4)  ; will call ExtendingStruct.method
   base-struct.method(copy 4)  ; will call BaseStruct.method
   BaseStruct.method(var extending-struct, copy 4)  ; will call BaseStruct.method

Dynamic Interfaces
------------------
Syntax for the :ref:`dynamic interface typing style <type-system-dynamic>`.

This is not supported yet in :ref:`TL5 <syntax-tl5>`.

Dynamics are declared using the ``dynamic`` keyword::

   dynamic ExampleDynamic
       func dynamic-method(copy Int num)
       func another-method()->(var Int result)
       var Int dynamic-variable

Dynamics are always used as ``user`` access references, as there is nothing to
"allocate". Because the most common implementations of dynamics are for a
specific :ref:`structure <syntax-static>`, dynamic references also hold an
additional reference to a generic structure which is passed to the methods as
the first ``self`` parameter. ::

   var ImplementingStructure implementing-structure
   user ExampleDynamic dynamic-reference(user implementing-structure)
   dynamic-reference.dynamic-method(copy 4)

Using a pure dynamic without the binding can be done with the built-in
``Dynamic`` type, that only accepts implemented dynamic type names as value::

   user Dynamic{ExampleDynamic} dynamic-reference(user ExtendingDynamic)
   dynamic-reference.dynamic-method(copy 4)

Non-Dynamic Members
+++++++++++++++++++
Constants and global variables are declared and used exactly as :ref:`global
members in static structures <global-members>`.

Static methods must be declared using ``static`` prefix::

   dynamic ExampleDynamic
       func dynamic-method(copy Int num)
       static func static-method(copy Int num)
           ; implementation


Extending Dynamics
++++++++++++++++++
Same syntax as structures::

   dynamic ExtendingDynamic(BaseDynamic, OtherBaseDynamic)
       func additional-method(copy Int num)

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

.. _syntax-bind:

Classes and Binds
-----------------
Syntax for the :ref:`class typing style <type-system-static>`.

A straightforward way to use classes is using the built-in ``Bind`` typed
references. References of this type only accept types that extend all bound
structures and implement all bound dynamics. ::

   user Bind{ExampleStruct:ExampleDynamic} class-reference

Another way to use classes is to declare a type as a class in its definition
using the ``class`` keyword. Each non-global member of the class must come
after a ``static`` or a ``dynamic`` keyword to declare witch implicit type this
member belongs to: the structure or the dynamic. Global members are only
defined under the name-space of the class. ::

   class ExampleClass
       static var Int static-field  ; part of the implicit structure
       dynamic func dynamic-method(copy Int num)  ; part of the implicit dynamic
       global var Int global-variable  ; defined under the class name-space

In :ref:`TL5 <syntax-tl5>` this only partially implemented:

* Only ``class`` type definition is supported, ``Bind`` is not
* All restrictions on structures also apply to classes
* Only methods can be dynamic
* Variables don't need to start with ``static`` keyword - as they cannot be
  dynamic or global

Extending Classes
+++++++++++++++++
As all types::

   class ExtendingClass(BaseStruct, BaseDynamic, BaseClass)
       static var Int addition-static-field
       dynamic func addition-dynamic-method(copy Int num)

In :ref:`TL5 <syntax-tl5>` a class may only extend one other type.

Using the Implicit Structure or Dynamic of a Class
++++++++++++++++++++++++++++++++++++++++++++++++++
The implicit structure of a class can be used using the built-in ``Struct``
type, and the implicit dynamic can be used using the built-in ``Dynamic``
type. This is not supported in :ref:`TL5 <syntax-tl5>`. ::

   var Struct{ExampleClass} static-structure-only
   user Dynamic{ExampleClass} dynamic-interface-only

parameterized types
-------------------
Syntax for the :ref:`parameterized type typing style <type-system-static>`.

Each type parameter must have a type and a name. For static type names ``Type``
should be used as the parameter type, and for dynamic parameters ``Generic``
should be used as the parameter type. The parameter name must conform the
naming standard of types if one of these is used, else it must conform naming
standard of constants. ::

   struct ParametrizedType{Int CONSTANT-PARAMETER:Type TypeParameter:Generic GenericParameter}
       var String{CONSTANT-PARAMETER} parametrized-sized-string
       var TypeParameter static-parametrized-typed-variable
       user GenericParameter dynamic-parametrized-typed-reference

Whenever a parameterized type is used it must be set with appropriate values for
each parameter ::

   var ParametrizedType{8:Int:File} specific-variable

This is partially supported in :ref:`TL5 <syntax-tl5>`:

* Only dynamic parameters are supported
* Only the parameter name is needed
* Some types are not supported as parameter values:

   * any primitive type
   * String
   * Array

Embedded Dynamic Reference
--------------------------
Syntax for the :ref:`embedded dynamic reference typing style
<type-system-static>`.

This is not supported yet in :ref:`TL5 <syntax-tl5>`.

Embedded classes can be declared using the built-in ``Embed`` type::

   ; "ExampleStruct" structure with "ExampleDynamic" reference embedded
   ; inside it
   var Embed{ExampleStruct:ExampleDynamic} explicit-embedded-variable

   ; "ExampleClass" static structure with a reference to its dynamic structure
   ; embedded inside it
   var Embed{ExampleClass} implicit-embedded-variable

The syntax may change as this typing style is still under planning.
