Basic Syntax
============

Comments
--------
In :ref:`TL4 <syntax-tl4>` Single line comments start with ``;``, multi-line
comments start with ``[;``, and end with ``;]``.
Comments that are not in line start are not supported yet - but will be
supported in the final syntax. ::

   ; single line comment
   [; <-- multi-line comment start
   multi
   line
   comment
   multi-line comment end --> ;]
   var Int x  ; not supported yet :(

Some suggest to change this in the final syntax to be as in C with ``//``,
``/*`` and ``*/``.

Documentation
-------------
Documentation have their own dedicated syntax: they start and end with ``~~~``.
Documentation must be placed at line start and may be single or multi-line.

In :ref:`TL4 <syntax-tl4>` documentation are treated as comments. In the final
syntax they must come before the element they are documenting, they could be
used dynamically in the code, and would be used to automatically generate
external documentation. ::

   ~~~ single line documentation ~~~
   func documented-function()
       ; do stuff

   ~~~  <-- multi-line documentation start
   multi
   line
   documentation
   multi-line documentation end --> ~~~
   func another-documented-function()
       ; do stuff

Operators
---------
* assignment: ``:=``
* arithmetic: ``+``, ``-``, ``*``, ``div``, ``mod``
* assignment and arithmetic: ``+=``, ``-=``, ``*=``
* bitwise: ``bnot``, ``bor``, ``band``, ``xor``, ``>>``, ``<<``
* relational (arithmetic): ``=``, ``!=``, ``<``, ``>``, ``<=``, ``>=``
* relational (referential): ``is``, ``is-not``, ``?``
* logical: ``not``, ``or``, ``and``
* miscellaneous: ``.``, ``[]``, ``[:]``, ``()``

Not supported yet in :ref:`TL4 <syntax-tl4>`: ``*=``, and all bitwise operators

Any binary operator may be followed by a line brake with additional indentation
of exactly 8 spaces::

   x := 3 +
           4
   y :=
           3 + 4
   z :=
           3 +
           4

Operator Precedence
+++++++++++++++++++
1. ``. [] () ?``, left-to-right
2. ``- +``, ``* div mod``, ``bnot bor band xor >> <<``, left-to-right 
   :ref:`[1] <operator-precedence-1>`
3. ``= != > < >= <= is is-not``, left-to-right 
   :ref:`[2] <operator-precedence-2>`
4. ``not``
5. ``or``, ``and``, left-to-right :ref:`[1] <operator-precedence-1>`
6. ``:= += -= *=``, only one allowed

.. _operator-precedence-1:

**[1]** cannot combine operators from different sub-groups of this group, they
must be separated using ``()``, for example ``a + b * c`` is not legal and
should be changed to ``a + (b * c)``

.. _operator-precedence-2:

**[2]** multiple operators from this group combined will be separated with
``and`` operator, for example, ``a < b < c < d`` is treated as ``a < b and
b < c and c < d``

Modules
-------
In :ref:`TL4 <syntax-tl4>` each Lumi file is declared under a single module,
multiple files may be declared under the same module.

The first line of each file must declare its module using the ``module``
keyword::

   module my-module-name

Only a single documentation block can come before it.

Using any item of another module must come after the other module prefix::

   var other-module.SomeType variable
   other-moudle.function(user variable)

In the final syntax modules and libraries support will be greatly extended -
the exact syntax is still under planning.
