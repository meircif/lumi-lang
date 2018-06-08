Quick Start - Hello World Example
=================================

This is a quick guide to install, compile and run Lumi "hello-world" example in
Linux.

Quick Installation
------------------

Clone `Lumi repository`_: ``git clone
https://github.com/meircif/lumi-lang.git``).

Enter the repository root directory: ``cd lumi-lang``.

:ref:`Build TL4 compiler <build-compiler>`: ``gcc TL4/tl4-compiler.c
TL3/lumi.3.c -ITL3 -ITL4 -I. -o /usr/local/bin/tl4-compiler``.

:ref:`Build "lumi" command <build-lumi-command>`: ``gcc lumi.c TL4/lumi.4.c
-ITL4 -o /usr/local/bin/lumi``.

Hello World Program
-------------------

.. literalinclude:: hello-world.4.lm
   :caption:

Compile it: ``lumi docs/hello-world.4.lm``.

Run it:

.. code-block:: none

   >>> docs/hello-world
   hello world

Hello World Test
----------------

.. literalinclude:: hello-world-test.4.lm
   :caption:

Compile it: ``lumi -t hello-world docs/hello-world-test.4.lm
docs/hello-world.4.lm``.

Run it:

.. code-block:: none

   >>> docs/hello-world-test
   Running tests:
   testing show-hello-world-test... OK
   testing code coverage... 100%
   Tests passed


.. _Lumi repository: https://github.com/meircif/lumi-lang