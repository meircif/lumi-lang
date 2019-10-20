.. _testing:

Testing
=======

Lumi has built-in testing and mocking capabilities.

Testing code should be written under a different module than the tested code.
In the testing code there should be :ref:`test cases <test-cases>` that test
the tested module using :ref:`assertions <assertions>`. :ref:`mocking` should
be used to simulate external interfaces.

Lumi can then run all test cases automatically, while also checking code
coverage for the tested module.

.. _test-cases:

Test Cases
----------
Can be written using the ``test`` keyword::

   test test-case-name()
       ; test code

The test case is consider a success if the code runs without any assertion
or runtime errors.

.. _assertions:

Assertions
----------
Assertions test that a certain condition is true.

The basic assertion is the ``assert`` statement that checks whether a given
boolean expression is true. If not, this statement will raise an assertion error
and the test will fail. ::

   assert! number = 4

Another assertion is the ``assert-error`` statement that checks whether a given
expression raises an error. If the execution of the statement didn't raise an
error this statement will raise an assertion error and the test will fail. ::

   assert-error! raising-function()

In :ref:`TL5 <syntax-tl5>` ``assert-error`` supports an optional additional
string literal that is the expected error message. If the raised error message
is not exactly the same as this literal, ``assert-error`` will raise an
assertion error and the test will fail. ::

   assert-error! raising-function(), "expected error message"

.. _mocking:

Mocking
-------
Mocking can replace an external interface with simulated behavior.

In :ref:`TL5 <syntax-tl5>`, only functions and methods can be mocked.

Mocking a function or method is done using the ``mock`` keyword. The function
name and its arguments access an type must much the mocked function exactly.
Whenever the mocked function is used the mocking function is called instead. ::

   mock mocked-module.mocked-function(copy Int input)->(var Int output)
       ; mocking body

   mock mocked-module.MockedType.mocked-method()
       ; mocking body

Built-in functions and methods can also be mocked::

   mock Sys.print(user String text)
       ; mocking body

   mock file-open-read(user String filename)->(owner File file)
       ; mocking body

The mocked function can still be called using ``mocked`` member::

   mocked-function-name.mocked()

To disable mocking of a function ``active`` member can be set to
:data:`false`. To re-enable mocking it can be set back to :data:`true`.
Mocks are active by default. ::

      mocked-function-name.active := false
      mocked-function-name()
      mocked-function-name.active := true
