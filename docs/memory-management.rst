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

No Performance Overhead - compile time only reference managing
--------------------------------------------------------------
Lumi will allow performance free reference managing that will be done only in
compile time.

Every objects has a single "owner" entity - which is another object or a
stack block. When an owner is destroyed it automatically destroys the
referenced object, unless the ownership was moved to another entity. Stack and
global variables are treated as owners - but they cannot move their ownership.

This has some similarities to the memory management in
`Rust <https://doc.rust-lang.org/stable/book/ch04-00-understanding-ownership.html>`_.

Owners can give the reference to multiple temporary "user" entities. Users are
free to read and modify the referenced object - but cannot destroy it or modify
its sub-owners. Users are temporary because they cannot be used after any
object of their type is destroyed, as the compiler cannot guarantee they are
pointing to a legal object any more.

Owners can "borrow" the reference to a single temporary owner that
automatically returns the ownership back to the original owner at the end of
its code block. While borrowing the original owner cannot be used.
The temporary owner has full control over the reference, except the ability to
destroy it.

This is :ref:`currently implemented <variables>`, but not fully optimized. In
the future the syntax may be slightly different and look like this::

   owner String some-string(String{16}())  ; new owner reference
   user-func(user some-string)  ; give reference to a user
   borrowing-func(temp some-string)  ; borrow ownership to a temporary owner
   owning-func(owner some-string)  ; move ownership, cannot be used anymore

.. _memory-management-2:

More Flexible Reference Managing - with a small performance cost
----------------------------------------------------------------
Lumi will allow more complex and flexible reference managing that come with a
small and predictable performance cost.

Same as :ref:`memory-management-1` with the addition of weak references.
To allow this the owner should be declared as "strong". It will work the same
way as a regular owner, plus that it can now give "weak" references to any
other entity without limitations. Weak references will automatically test that
the reference is still valid before accessing it.

There are several ways to implement this - but all need some extra memory to
manage the weak references, and some extra processing time to check if the weak
reference is valid. In all implementations the extra overhead is small and
predictable.

This is :ref:`currently implemented <variables>`, but in the
future the syntax may be slightly different and look like this::

   strong String some-string(String{16}())  ; new strong owner reference
   user-func(user some-string)  ; give reference to a user
   borrowing-func(temp some-string)  ; borrow ownership to a temporary owner
   weak-func(weak some-string)  ; give weak reference
   owning-func(strong some-string)  ; move ownership

.. note::
   Strong reference counting is currently not supported because it can cause
   memory leaks because of reference loops. It may be allowed in the future in
   cases where the compiler can ensure no reference loop is possible.

.. _memory-management-3:

Maximum Flexibility - but with performance issues
-------------------------------------------------
Lumi will allow declaring a reference as garbage-collected, which will allow
passing references freely without limitation. The memory will only be cleared
when all "strong" references are destroyed. The garbage-collector must check
and remove reference loops to avoid memory leaks.

To allow this a reference should be declared as "shared". This reference can
then be passed to other "shared", "user" or "weak" references.

Implementing a garbage-collector has a significant and unpredictable
performance cost, but some Lumi users may be willing to pay it in some sections
of their project where performance is less important.

This is not implemented yet, but in the future the syntax may look like this::

   shared String some-string(String{16}())  ; new shared reference
   shared-func(shared some-string)  ; copy shared reference
   user-func(user some-string)  ; give reference to a user
   weak-func(weak some-string)  ; give weak reference

.. _memory-management-empty:

Conditional and Empty References
--------------------------------
As default, (non-weak) references always point to a legal object.
To allow empty references, the reference type must be declared as "conditional"
using the ``?`` sign. Empty value can be set using ``_`` sign.

This is :ref:`currently implemented <variables>`, but not fully optimized.
In the future the syntax may be slightly different and look like this::

   user String? cond-str  ; initialized as empty
   cond-str := some-string  ; now not empty
   cond-str := _  ; now is empty again
   if cond-str?  ; check if has value
       ; can be used safely here...
   else
       ; here we know it's empty...
   cond-str!.clear()  ; raise error if empty
   func-with-cond(user _)  ; send empty to function
