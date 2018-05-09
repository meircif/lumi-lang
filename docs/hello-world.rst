Hello World - Code examples
===========================

Hello World Program
-------------------
A simple "Hello World" program written in :ref:`TL4 <syntax-tl4>`:

.. literalinclude:: hello-world.4.lm
   :caption:

Compiling and running this program will output as expected:

.. code-block:: none

   hello world

Testing the Hello World Program
-------------------------------
Testing code for the "Hello World" program:

.. literalinclude:: hello-world-test.4.lm
   :caption:

Compiling and running the test will output:

.. code-block:: none

   Running tests:
   testing show-hello-world-test... OK
   testing code coverage... 100%
   Tests passed

Fibonacci Function
------------------
.. literalinclude:: examples.4.lm
   :start-after: ; fibonacci start
   :end-before: ; fibonacci end

Complex number Type
-------------------
.. literalinclude:: examples.4.lm
   :start-after: ; Complex start
   :end-before: ; Complex end
