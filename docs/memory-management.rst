.. _memory-management:

Memory Management
=================

Memory should be managed correctly to reach :ref:`Lumi goal <goals>` #1, to
reach :ref:`Lumi goal <goals>` #2 - it should be done as efficiently as
possible, and to reach :ref:`Lumi goal <goals>` #3 - it should be flexible.

This is achieved by combining 3 forms of managing - allowing easy trade-off
between flexibility and performance by the user:

1. :ref:`memory-management-1`
2. :ref:`memory-management-2`
3. :ref:`memory-management-3`

.. note::
   Below is a non-final suggestion to implement this, it will probably be
   developed further over time. See :ref:`variables` section for the currently
   implemented syntax.

.. _memory-management-1:

No performance overhead - compile time only reference managing
--------------------------------------------------------------

Lumi will allow performance free reference managing that will be done only in
compile time.

Every reference has a single "owner" entity - which is another object or a
stack block. When an owner is destroyed it automatically destroys the
referenced object, unless the ownership was moved to another entity. Owners can
give the reference to multiple "user" entities - other entities that are deeper
in the stack than the owner. Users are free to modify the referenced object
freely - but cannot destroy it or modify its sub-owners.
This is very similar to the memory management in
`Rust <https://doc.rust-lang.org/stable/book/second-edition/ch04-00-understanding-ownership.html>`_.

Stack and global variables are treated as owners - but they cannot move their
ownership.

This is not implemented yet, but in the future the syntax may look like this::

   owner String some-string(String{16}())  ; new owner reference
   user-func(user some-string)  ; give reference to a user
   owning-func(owner some-string)  ; move ownership, cannot be used anymore

.. _memory-management-2:

More flexible reference managing - with a small performance cost
----------------------------------------------------------------

Lumi will allow more complex and flexible reference managing that come with a
small and predictable performance cost.

Same as :ref:`memory-management-1` with the addition of weak references.
To allow this the owner should be declared as "managed". It will work the same
way as a regular owner, plus that it can now give "weak" references to any
other entity without limitations. Weak references will automatically test that
the reference is still valid before accessing it.

There are several ways to implement this - but all need some extra memory to
manage the weak references, plus the extra check if the weak reference is valid.
Depends on the implementation of the compiler the extra overhead is small and
predictable.

.. note::
   Strong reference counting is not supported because it can cause memory leaks
   because of reference loops.

This is :ref:`currently implemented <variables>` in a basic manner, but in the
future the syntax may be different and look like this::

   managed String some-string(String{16}())  ; new managed reference
   user-func(user some-string)  ; give reference to a user
   weak-func(weak some-string)  ; give weak reference
   owning-func(managed some-string)  ; move ownership

.. _memory-management-3:

Maximum flexibility - but with performance issues
-------------------------------------------------

Lumi will allow declaring a reference as garbage-collected, which will allow
passing references freely without limitation. The memory will only be cleared
when all "strong" references are destroyed. The garbage-collector must check
and remove reference loops to avoid memory leaks.

To allow this a reference should be declared as "shared". This reference can
then be passed to other "shared", "user" or "weak" references.

Implementing a garbage-collector has a significant and unpredicted performance
cost, but some Lumi users may be willing to pay it in some sections of their
project where performance is less important.

This is not implemented yet, but in the future the syntax may look like this::

   shared String some-string(String{16}())  ; new shared reference
   shared-func(shared some-string)  ; copy shared reference
   user-func(user some-string)  ; give reference to a user
   weak-func(weak some-string)  ; give weak reference

.. _memory-management-empty:

Empty references (nil/null/none)
--------------------------------

As default, (non-weak) references always point to a legal object.
To allow empty references, a references must be declared as "conditional"
using the ``?`` sign. Empty value can be set using ``_``.

This is :ref:`currently implemented <variables>` in a basic manner, but in the
future the syntax may be different and look like this::

   user String? cond-str  ; initialized as empty
   cond-str := some-string  ; now not empty
   cond-str := _  ; now is empty again
   if cond-str?  ; check if has value
     ; can be used safely here...
   else
     ; here we know it's empty...
   cond-str?.clear()  ; raise error if empty
   func-with-cond(user _)  ; send empty to function
