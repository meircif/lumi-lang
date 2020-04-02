.. _functions:

Functions
=========


Summary
-------
Function are declared using the ``func`` keyword ::

   func func-name(copy Uint32 input-argument)->(var Uint32 output-argument)
       ; function implementation...

Functions are called using their name::

   func-name(copy 4)->(var some-int)

.. _arguments:


Arguments
---------
First input arguments (a.k.a "parameters") are written inside ``(...)``. If the
function has no input arguments an empty ``()`` should be used.

If the function has output arguments ("outputs" in short) they are written
second inside a different ``(...)`` after a ``->`` symbol with no whitespace.
Multiple outputs are supported.

In function deceleration each argument must be declared with ``access type
name`` trio. In function calling only ``access name`` duo is needed.
See :ref:`access` explanation below.

A new line can be placed before any argument access, with additional
indentation of exactly 4 spaces::

   func split-arguments0(copy Uint32 x, copy Uint32 y)->(
       var Uint32 z, var Uint32 w)

   func split-arguments1(
       copy Uint32 x, copy Uint32 y)->(var Uint32 z, var Uint32 w)

   func split-arguments0(
       copy Uint32 x, copy Uint32 y)->(
       var Uint32 z, var Uint32 w)

   func split-arguments0(
       copy Uint32 x,
       copy Uint32 y)->(
       var Uint32 z,
       var Uint32 w)

.. _access:


Access
------
An "access" defines the memory access of the argument.

In :ref:`TL5 <syntax-tl5>`:

* for primitive types ``copy`` must be used for parameters, and ``var`` for
  outputs.
* for complex types one of ``owner``, ``temp``, ``user``, ``strong``, ``weak``
  must be used depends on the needed :ref:`memory access <references>`

``copy`` parameter:

* the parameter is a new memory copy of the called argument
* changes to the parameter will **not** change any caller variable
* any expression can be given

``var`` output:

* the parameter is a reflection of an actual variable
* changes to the parameter will **also** change the caller variable
* only a writable value can be given

``user``, ``owner``, ``temp``, ``strong`` or ``weak`` parameter:

* the argument is a reference to an object
* changes to the reference itself will **not** change the called reference
* changes to the object will change the called object
* any expression can be given
* ``user`` or ``weak`` means the parameter is a simple reference
* ``owner`` or ``strong`` means the caller has passed the ownership of the
  referenced object to the function, and the object will be deleted in the
  function end if the ownership is not passed in the function body
* ``temp`` means the caller has temporally passed the ownership of the
  referenced object to the function, and the ownership will be returned after
  function end and cannot be deleted or permanently passed forward by the
  function

``user``, ``owner``, ``strong`` or ``weak`` output:

* the parameter is a reflection of an actual reference
* changes to the reference itself will **also** change the called reference
* only a writable value can be given

In the planned final syntax this will be extended, and the access may be
omitted in a default usage.


Return and Output
-----------------
In :ref:`TL5 <syntax-tl5>` output is written by setting a value to an output
argument::

   func example()->(var Uint32 first-output, user String second-output)
       first-output := 4
       second-output := String{16}()

A ``return`` statement can be used to stop the function in the middle::

   func example(copy int x)
       if x < 0
           return
       ; do something

In the final syntax this may be possible::

   func example()->(var Uint32 first-output, owner String second-output)
     return 4, String{16}()


Error Handling
--------------
Raising an error can be done using the ``raise`` statement. Functions that
may raise an error must be marked with ``!``::

   func ! example()
       raise!

In :ref:`TL5 <syntax-tl5>` an optional string expression can be raised::

   func ! example()
       raise! "error message"


Error Propagation
+++++++++++++++++

Unless caught, raised error will propagate to the caller function, up until the
main function - where uncaught errors will stop the execution of the program,
print the raised error message if given, and print a call traceback.

In the function code whenever an error may be raised and propagated to the
caller - the ``!`` warning sign must be added. A functions that may raise an
error must also add the ``!`` warning sign to its deceleration.


Error Catching
++++++++++++++

A local error can be handled using ``if-ok`` or ``if-error``::

   if-ok x := array[3]
       ; no error raised
   else
       ; index out of bound handling
   
   if-error x := array[4]
       ; index out of bound handling
   else-if-ok x := array[6]
       ; no error raised
   else-if-error x := array[5]
       ; index out of bound handling
   else
       ; no error raised

.. note:: ``if-ok`` must be followed by ``else`` to ensure error is not ignored

A ``try`` statement will catch an error raised inside it and break the
execution of the rest of the block. The error will be ignored unless ``try`` is
followed by a ``catch`` statement. The code under the ``catch`` statement will
only run if the above ``try`` statement caught an error. ::

   try
       ; do something that may raise errors
   catch
       ; do some error handling


Calling a Function
------------------
When calling a function the access of each argument must be written::
   
   example(copy primitive-input, user reference-input)->(
           var primitive-output, owner owner-output)

If the function may raise an error and the caller propagates the error - ``!``
warning sign must be used::
   
   raising-example(copy input)->(var output)!
