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
This is not supported in :ref:`TL4 <syntax-tl4>`.

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

Do-While Loop
---------------
Do-while loop is declared using the ``do`` keyword and contains one or more
``while`` statements inside it. The loop continues while every ``while``
statement inside it is true, and stops immediately when the first ``while``
statement inside it is false. ::

   do
       ; do something
       while number < 6
       ; do something
       while not boolean-variable
       ; do something

Loops can be broke immediately using a ``break`` statement::

   do
       ; do something
       if number = 0
           break
       ; do something

That makes ``while condition`` the same as ``if not condition break``.

A ``continue`` statement can be used to only stop the current iteration and
start over from loop beginning::

   do
       ; do something
       if num = 3
           continue
       ; do something

For Loop
--------
For loop is declared using the ``for`` keyword, and iterates over a specific
set of values.

Iterating numbers incrementally, numbers can be any integer expression::

   for number in 3:7
       ; "number" will iterate 3,4,5,6

Number iteration with explicit step amount, this is not supported in :ref:`TL4
<syntax-tl4>`::

   for number in 9:1:-2
       ; "number" will iterate 9,7,5,3

String iteration::

   for character in "Example"
       ; "character" will iterate E,x,a,m,p,l,e

Array iteration::

   for item in array
       ; "item" will iterate each item of "array"

User Defined Iterators
++++++++++++++++++++++
A type can be made into an iterator in :ref:`TL4 <syntax-tl4>` by implementing
theses methods:

.. function:: has()->(var Bool has-another-item)

   Is called before any iteration. Iteration continues only if this method
   returns :data:`true`.

.. function:: get()->(user SomeType value)

   Is called before any iteration after :func:`has` returns
   :data:`true`. Returned value is set as the iteration value. "SomeType"
   declared in this method is used as the iterator value type.

.. function:: next()

   Is called after the end of any iteration. Should be used to advance the
   iteration.

This interface may change in the final syntax - the exact syntax is still under
planning.

An instance of an iterator type can be used in for loops::

   for item in iterator-instance
       ; "item" will iterate as implemented by "iterator-instance" type
