.. _variables:

Variables and Constants
=======================

In :ref:`TL5 <syntax-tl5>` the :ref:`Lumi memory management <memory-management>`
is mostly implemented, excluding the
:ref:`third management form <memory-management-3>` from the 3 planned.

Constants
---------
In :ref:`TL5 <syntax-tl5>` only global integer constants are supported. The
final Lumi syntax is planned to support constants from all types, and allow
definition of constants under a specific type.

Integer constants are declared in :ref:`TL5 <syntax-tl5>` by::

   const Int CONSTANT-NAME 12

Where ``12`` is an example constant value. That constant value can be any
constant expression, which may include:

1. integer numbers
2. other integer constants
3. enumerators
4. integer operators, where the operands are constant expressions

Enumerators
-----------
Enumerators are a set of constant symbols that are treated as integer constants.
The first symbol is allocated a value of ``0``, the second is ``1`` and so on...

In :ref:`TL5 <syntax-tl5>` enumerators can only be declared in the global scope.
The final Lumi syntax is planned to support enumerators under a specific type,
will allow definition of specific values for the enumerator symbols, and will
generate automatic conversion functions between symbol names and values.

Enumerators are declared in :ref:`TL5 <syntax-tl5>` by::

   enum EnumeratorName
       FIRST-SYMBOL-NAME
       SECOND-SYMBOL-NAME
       THIRD-SYMBOL-NAME

Using an enumerator is done by ``EnumeratorName.SYMBOL-NAME``.

The amount of values is defined by a special ``length`` value, for example
``EnumeratorName.length`` is ``3``.

Primitive Variables
-------------------
Primitive variables are declared using ``var`` keyword::

   var Int integer-variable
   var Int with-initialization(copy 12)

If no explicit initialization value given - primitive values are initialized
with each type's default initialization value:

* :class:`Int` : ``0``
* :class:`Bool` : ``false``
* :class:`Char` : ``\0``
* :class:`Byte` : ``0x00``
* :class:`Real` : ``0.0``
* :class:`Func` : empty (``_``)

.. _references:

References
----------
References to complex types are declared using the wanted
memory access keywords:

* ``owner``: simple owner reference
* ``user``: simple user reference
* ``temp``: simple temporary owner reference
* ``strong``: reference counted strong reference
* ``weak``:  reference counted weak reference

::

   owner String string-owner-reference
   user Array{Int} user-reference-with-initialization(user some-int-array)
   temp String temporary-owner-reference
   strong String string-strong-reference
   weak Array{Int} weak-reference-with-initialization(weak some-int-array)

References must be assigned with a value before used.
  
Conditionals
++++++++++++

Conditional references are declared by appending ``?`` character in type end::

   owner String? conditional-owner-reference
   user Array?{Int} conditional-array-with-initialization(user some-int-array)

If no explicit initialization value given - conditional references are
initialized as empty (``_``).

Comparisons
+++++++++++

Comparing references by-reference is done using the ``is`` and ``is-not``
operators.

Checking if a reference is usable - not empty and not outdated - can be done
using the ``?`` operator, to explicitly check for emptiness the ``is`` and
``is-not`` operators can be used with ``_`` as operand. ::

   if first-reference is second-reference
       ; both references reference to the same object, or both are empty
   if first-reference is-not second-reference
       ; both references do not reference to the same object
   if reference?
       ; reference is usable - not empty and not outdated
   if not reference?
       ; reference is not usable - it is empty or outdated
   if reference is _
       ; reference is empty
   if reference is-not _
       ; reference is not empty, but may or may not be outdated

String and Buffer Literals
++++++++++++++++++++++++++
:ref:`string` and :ref:`buffer <buffer>` literals are allocated in the global
data section. In the scope they are used they are treated as ``user``
access references to the global data.

.. _static-allocation:

Static Allocation
-----------------
Static allocation of complex types is done using ``var`` or ``s-var`` keywords::

   var String{256} string-static-allocation
   s-var Array{34:Int} static-strong-int-array!

Doing this in the global scope will allocate the data in the process global
data section. Doing this in a function scope will allocate the data in the
stack.

Statically allocated variables cannot pass their ownership to ``owner``
references.

.. _dynamic-allocation:

Dynamic Allocation
------------------
Dynamic allocation is done by using the type as a function::

   string-owner-reference := String{256}()!
   array-strong-reference := Array{34:Int}()!

It's probably a good idea to store the returned object in an ``owner``
reference, otherwise it will be deleted in the end of the block.
