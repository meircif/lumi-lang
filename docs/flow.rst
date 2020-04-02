Control Flow
============

If-Else Condition
-----------------
If-else condition is declared using ``if``, ``else``, and ``else-if`` keywords.
The condition expression must be boolean typed. ::

   if x > 4
       ; do something
   else-if x < 2
       ; do something
   else
       ; do something


Switch-Case Condition
---------------------
This is not supported in :ref:`TL5 <syntax-tl5>`.

Switch-case condition is declared using the ``switch`` keyword, contains
multiple ``case`` blocks, and optionally one last ``default`` block. A
``fallthrough`` statement must be used to fall-through the next case - the
default is not to fall-through. ::

   switch number
   case 34
       ; do something
   case 23
       ; do something
       fallthrough
   case 45, 67, 26, 56, 67, 89, 56, 87
       ; do something
   default
       ; do something


Simple Loop
-----------
Simple loop is declared using the ``loop`` keyword and contains one or more
``while`` statements inside it. The loop continues while every ``while``
statement inside it is true, and stops immediately when the first ``while``
statement inside it is false. ::

   loop
       ; do something
       while number < 6
       ; do something
       while not boolean-variable
       ; do something

Loops can be broken immediately using a ``break`` statement::

   loop
       ; do something
       if number = 0
           break
       ; do something

That makes ``while condition`` the same as ``if not condition break``.

A ``continue`` statement can be used to only stop the current iteration and
start over from loop beginning::

   loop
       ; do something
       if num = 3
           continue
       ; do something

It is possible to limit the number of loop iterations, when the limit is
reached an error is raised::
   
   loop! number
       ; do something
       while condition

.. note:: The ``!`` warning sign must be used if error is to be propagated.

Loops must contain at least one ``while``, ``break`` or ``return`` statement -
otherwise the compiler will complain about an infinite loop. If an infinite
loop is intentional ``loop-infinite`` must be used::
   
   loop-infinite
      ; do something forever


Repeat Loop
-----------
A simple loop that just repeats itself a specific number of times::
   
   repeat number
       ; do this "number" times


For Loop
--------
For loop iterates over a specific set of values, and is declared using the
``for`` keyword.

Iterating numbers incrementally, limits can be any integer expression::

   for number in 3:7
       ; "number" will iterate 3,4,5,6

Number iteration with explicit step amount, this is not supported in :ref:`TL5
<syntax-tl5>`::

   for number in 9:1:-2
       ; "number" will iterate 9,7,5,3

Array iteration::

   for item in array
       ; "item" will iterate each item of "array"

String iteration::

   for character in "Example"
       ; "character" will iterate E,x,a,m,p,l,e

Buffer iteration::

   for byte in `baffdaca`
       ; "character" will iterate ba,ff,da,ca

In all for loops it is possible to ignore the iteration item by replacing it
with ``_``::
   
   for _ in 3:7
       ; will iterate 4 times


User Defined Iterators
++++++++++++++++++++++
A type can be made into an iterator in :ref:`TL5 <syntax-tl5>` by implementing
a ``step`` named method that has the following deceleration:

.. function:: step()->(user SomeType? value, var Bool has-another-item)

   Is called once before any iteration. Iteration continue only
   if ``has-another-item`` is :data:`true`. In such case ``value`` returns
   the next iteration value, and the iteration should advance one step.
   ``SomeType`` declared in this method is used as the iterator value type.

An instance of such iterator type can be used in for loops::

   for item in iterator-instance
       ; "item" will iterate as implemented by "iterator-instance" type

This interface may change in the final syntax - the exact syntax is still under
planning.
