.. _functions:

Functions
=========

Summary
-------

Function are declared using the ``func`` keyword ::

   func func-name(copy Int input-argument)->(var Int output-argument)
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

   func split-arguments0(copy Int x, copy Int y)->(
      var Int z, var Int w)

   func split-arguments1(
      copy Int x, copy Int y)->(var Int z, var Int w)

   func split-arguments0(
      copy Int x, copy Int y)->(
      var Int z, var Int w)

   func split-arguments0(
      copy Int x,
      copy Int y)->(
      var Int z,
      var Int w)

.. _access:

Access
------
An "access" defines the memory access of the argument.

In :ref:`TL4 <syntax-tl4>`:

* for primitive types ``copy`` must be used for parameters, and ``var`` for
  outputs.
* for complex types ``owner`` or ``user`` must be used depends on the needed
  :ref:`memory access <variables>`

``copy`` parameter:

* the parameter is a new memory copy of the called argument
* changes to the parameter will **not** change any caller variable
* any expression can be given

``var`` output:

* the parameter is a reflection of an actual variable
* changes to the parameter will **also** change the caller variable
* only a writable value can be given

``user`` or ``owner`` parameter:

* the argument is a reference to an object
* changes to the reference itself will **not** change the called reference
* changes to the object will change the called object
* any expression can be given
* ``user`` means the parameter is a weak reference
* ``owner`` means the caller has passed the ownership of the referenced object
  to the function, and the object will be deleted in the function end if the
  ownership is not passed in the function body

``user`` or ``owner`` output:

* the parameter is a reflection of an actual reference
* changes to the reference itself will **also** change the called reference
* only a writable value can be given

In the planned final syntax this will be extended, and the access may be
omitted in a default usage.

Return and Output
-----------------
In :ref:`TL4 <syntax-tl4>` output is written by setting a value to an output
argument::

   func example()->(var Int first-output, user String second-output)
     first-output := 4
     second-output := String{16}()

A ``return`` statement can be used to stop the function in the middle::

   func example(copy int x)
      if x < 0
         return
      ; do something

In the final syntax this may be possible::

   func example()->(var Int first-output, owner String second-output)
     return 4, String{16}()

Error Handling
--------------
Raising an error can be done using the ``raise`` statement::

   func example()
      raise

In :ref:`TL4 <syntax-tl4>` an optional string expression can be raised::

   func example()
      raise "error message"

Unless caught, raised error will propagate to the caller function, up until the
main function - where uncaught errors will stop the execution of the program,
print the raised error message if given, and print a call traceback.

A ``try`` statement will catch an error raised inside it and break the
execution of the rest of the block. The error will be ignored unless ``try`` is
followed by a ``catch`` statement. The code under the ``catch`` statement will
only run if the above ``try`` statement caught an error. ::

   try
      ; do something that may raise errors
   catch
      ;  do some error handling

In the final syntax this may be different - the exact syntax is still under
planning.
