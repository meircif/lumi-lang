Basic Syntax
============

Comments
--------

In :ref:`TL4 <syntax-tl4>` Single line comments start with ``;``, multi-line
comments start with ``[;``, and end with ``;]``.
Comments that are not in line start are not supported yet - but will be
supported in the final syntax.::

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
external documentation.::

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
* miscellaneous: ``.``, ``[]``, ``()``

Operator Precedence
###################

1. ``. [] () ?``, left-to-right
2. ``- +``, ``* div mod``, ``bnot bor band xor >> <<``, left-to-right [1]_
3. ``= != > < >= <= is is-not``, left-to-right [2]_
4. ``not``
5. ``or``, ``and``, left-to-right [1]_
6. ``:= += -= *=``, only one allowed

.. [1] cannot combine operators from different sub-groups of this group, they
   must be separated using ``()``
.. [2] multiple operators from this group combined will be separated with ``and``
   operator, for example, ``a < b < c < d`` is treated as
   ``(a < b and b < c and c < d)``
