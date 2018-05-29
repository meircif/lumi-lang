Lumi Language Guide
===================

Welcome to **Lumi** programming language guide!

Lumi is a general purpose programming language that is good for all needs,
specially for long-term projects, or where resource efficiency is needed.

Lumi aims to be safe, efficient, flexible, easy to write,
and easy to maintain. See :ref:`goals` for more details.

Lumi files use ``.lm`` extension.

"Lumi" name was chosen because:

* "Lumi" is an abbreviation for "Illuminating", and Lumi language aims to cast
  new light to the programming world. (it's also the meaning of my first name)
* "Lumi" means "snow" in Finnish, which is bright, light, handy, flexible,
  strong and fun - such as the Lumi language. (and also - I like snow)
* "Lumi" is short, easy to pronounce, and fun to say.

   The Lumi image is
   `Designed by kjpargeter / Freepik <http://www.freepik.com>`_

A Work in Progress...
---------------------
Lumi is still under initial planning and building. Many features are already
implemented and it is possible to write complex programs with Lumi, but some
key elements are not, and many implemented feature may change dramatically.

The latest state of the language is named ":ref:`Temporary Lumi 4
<syntax-tl4>`", or "TL4" in short, to emphasizing the current temporary state
of the language.

Contributing to Lumi
--------------------
Any help, suggestion, comment or questions is welcome! See Lumi repository
`wiki`_ for more details on how to contribute to Lumi.

.. _wiki: https://github.com/meircif/lumi-lang/wiki

.. toctree::
   :maxdepth: 2
   :caption: Installation and Usage

   quick-start
   install
   lumi-command
   lumi-compiler

.. toctree::
   :maxdepth: 2
   :caption: Concepts

   goals
   memory-management
   thread-safety
   type-system

.. toctree::
   :maxdepth: 2
   :caption: Syntax

   general-syntax
   basics
   builtin
   variables
   functions
   user-types
   flow
   testing
   native
   examples

.. toctree::
   :maxdepth: 2
   :caption: Future

   standard-libraries
   serialization
   async-io
