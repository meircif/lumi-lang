.. _built-in:

Built-in Types
==============

.. _integer:

Integer
-------
.. cpp:type:: Int

   Signed integer, same as ``int`` in C.

   Supported integer literals:
      * decimal: ``70695``
      * binary: ``0b100101``
      * octal: ``0175``
      * hexadecimal: ``0xa30eb9f6``
      * negative integer: ``-`` before any positive integer literal: ``-23``

   .. cpp:function:: str(user String text)

      write into ``text`` the integer converted to string

Boolean
-------
.. cpp:type:: Bool

   A boolean value that can only be a :cpp:var:`true` or a :cpp:var:`false`
   constant.

Built-in Global Constants
#########################

.. cpp:var:: Bool true

.. cpp:var:: Bool false

.. _character:

Character
---------
.. cpp:type:: Char

   A single ascii character.

   Character literal are surrounded with ``'`` characters: ``'a'``. Special
   characters can be written with ``\`` escape character as in C: ``\' \" \? \a
   \b \f \n \r \t \v \\``.

   In :ref:`TL4 <syntax-tl4>` characters can be used together with integers
   freely. In the final syntax it may not be possible without explicitly
   converting characters to and from integers using ``ord`` and ``chr``
   functions.

Byte
----
*planned - not supported in* :ref:`TL4 <syntax-tl4>`

.. cpp:type:: Byte

   A single memory byte value.

   Byte is threated as a normal :ref:`integers <integer>` with range 0..255.


Real Number
-----------
*planned - not supported in* :ref:`TL4 <syntax-tl4>`

.. cpp:type:: Real

   Floating point real number, same as ``float`` in C.

   Real number literal is a decimal number with ``.`` character in the middle,
   with optional exponential suffix: ``2.4``, ``-0.3``, ``4.0``, ``2.34e2``,
   ``-5.678e-12``.

Function
--------
.. cpp:type:: Func(arguments)

   Holds (pointer to) a function.

   :param arguments: the function in and out :ref:`arguments <arguments>`

   For example: ``Func{()}``, ``Func{(copy Int in)}``,
   ``Func{()->(var Int out)}`` , ``Func{(copy Int in)->(var Int out)}``.

.. _string:

String
------
.. cpp:type:: String(max length)

   Sequence of :cpp:type:`Char` items with dynamic length.

   :param max length: maximum length of the string and the actual allocation
      size

   For example: ``String{5}``, ``String{256}``.

   String references should be declared without a parameter: just ``String``.

   String literals are strings surrounded by ``"`` characters: ``"I am a string
   literal"``. Escape :ref:`characters <character>` can be used.

   String literals may contain line breaks, with additional indentation
   of exactly 4 spaces. It is treated as ``\n``, or ignored if ``\`` is used
   before it::

      ; the same as "line\nbrake"
      s := "line
          break"

      ; the same as "linebrake"
      s := "line\
          break"

   Accessing a single character can be done using ``string[index]``.

   It is possible to extract a sub-string from a string by slicing:
   ``string[start-index:substring-length]``. This will not copy the string but
   return a string reference that points to the original string.

   .. warning::
      In :ref:`TL4 <syntax-tl4>` string slicing is not fully safe. It should
      only be used temporarily before any modification to the original string.

   .. cpp:member:: Int length

      current (dynamic) string length

   .. cpp:function:: new(user String text)

      initialize this string with a copy of ``text``, does nothing if it's
      empty or invalid

      :raises: if ``text`` is too long to fit this string

   .. cpp:function:: clear()

      make this string empty

   .. cpp:function:: equal(user String other)->(var Bool is-equal)

      return whether this string is exactly equal to ``other``, return ``false``
      if ``other`` is empty or outdated

   .. cpp:function:: get(copy Int index)->(var Char character)

      return character at place ``index``,

      :raises: if ``index`` is out of range

   .. cpp:function:: append(copy Char character)

      append ``character`` to this string end

      :raises: if has no room for another character

   .. cpp:function:: concat(user String text)

      concatenate ``text`` to this string end

      :raises: if has no room for ``text``

   .. cpp:function:: concat-int(copy Int number)

      covert ``number`` to string and concatenate it to this string end

      :raises: if has no room for ``number``

   .. cpp:function:: find(user String pattern)->(copy Int index)

      return index of first accurance of ``pattern`` in this string, return
      ``0`` if empty or invalid pattern given, return this string
      :cpp:member:`length` if ``pattern`` not found

   .. cpp:function:: has(copy Char character)->(var Bool has)

      return whether this string contains ``character``

.. _buffer:

Buffer
------
*planned - not supported in* :ref:`TL4 <syntax-tl4>`

.. cpp:type:: Buffer(max length)

   Sequence of :cpp:type:`Byte` items with dynamic length.

   :param max length: maximum length of the string and the actual allocation
      size

   For example: ``Buffer{5}``, ``Buffer{256}``.

   Buffer references should be declared without a parameter: just ``Buffer``.

   Buffer literals are hexadecimal strings surrounded by ````` characters:
   ```4a0069ff3487beef2649```.

   .. cpp:member:: Int length

      current (dynamic) string length

   .. cpp:member:: Int max-length

      maximum (static) length of the string

Array
-----
.. cpp:type:: Array(length, subtype)

   Sequence of any typed item with static length. In :ref:`TL4 <syntax-tl4>`
   array of arrays are not supported. It is planned to be supported in the final
   Lumi syntax.

   :param length: array static length and the actual allocation size
   :param subtype: the type of each item in the array

   For example: ``Array{12:Int}``, ``Array{6:String{16}}``.

   Array references should be declared without the ``length`` parameter:
   just ``Array{Int}`` or ``Array{String}`` for example.

   Accessing a single item can be done using ``array[index]``.

   It is possible to extract a sub-array from an array by slicing:
   ``array[start-index:sub-array-length]``. This will not copy the array but
   return an array reference that points to the original array.

   .. warning::
      In :ref:`TL4 <syntax-tl4>` array slicing is not fully safe. It should
      only be used temporarily before any modification to the original array.

   .. cpp:member:: Int length

      (static) length of the array

File
----
.. cpp:type:: File

   Used to access files. Use :cpp:func:`file-open-read` or
   :cpp:func:`file-open-write` to create new objects from this type.

   .. cpp:function:: close()

      close this file, does nothing if this file is already closed

      :raises: if closing failed

   .. cpp:function:: getc()->(var Char character, var Bool is-eof)

      read one character from this file

      if this file is not closed, has more data, and data read succeeded -
      return :cpp:var:`false` in ``is-eof`` and next character read from the
      file in ``character``, else - return :cpp:var:`true` in ``is-eof`` and do
      nothing with ``character``

   .. cpp:function:: putc(copy Char character)

      append ``character`` to this file end

      :raises: if writing failed

   .. cpp:function:: write(user String text)

      append ``text`` to this file end

      :raises: if writing failed

Built-in Global Functions
#########################

.. cpp:function:: file-open-read(user String filename)->(owner File file)

   Create a new :cpp:type:`File` object that is capable of **reading** from
   ``filename`` file.

.. cpp:function:: file-open-write(user String filename)->(owner File file)

   Create a new :cpp:type:`File` object that is capable of **writing** to
   ``filename`` file.

Built-in Global Variables
#########################

.. cpp:var:: File stdin

   can be used to **read** from the standard input stream

.. cpp:var:: File stdout

   can be used to **write** to the standard output stream

.. cpp:var:: File stderr

   can be used to **write** to the standard error stream

System
------
This type is temporary in :ref:`TL4 <syntax-tl4>`, in the planned Lumi syntax
there will be a ``sys`` module with the same interface.

.. cpp:type:: Sys

   The type of the built-in :cpp:var:`sys` object, can be used to access system
   data and functionality.

   .. cpp:member:: Array{String} argv

      holds program arguments

   .. cpp:function:: print(user String text)

      print ``text`` to the standard output stream, same as calling
      ``stdout.write``

      :raises: if writing failed

   .. cpp:function:: println(user String text)

      print ``text`` appended with new-line character to the standard output
      stream

      :raises: if writing failed

   .. cpp:function:: getchar()->(var Char character, var Bool is-eof)

      read one character from the standard input stream

      if the standard input stream is not closed, has more data, and data read
      succeeded - return :cpp:var:`false` in ``is-eof`` and next character read
      from the standard input stream in ``character``, else - return
      :cpp:var:`true` in ``is-eof`` and do nothing with ``character``

   .. cpp:function:: getline(user String text)

      read one line from the standard input stream into ``text``, the line-end
      character is not written into ``text``

      does nothing if could not read data

   .. cpp:function:: exit(copy Int status)

      terminates execution of the program immediately with ``status`` as the
      exit status value

      calls C ``exit`` function

   .. cpp:function:: system(user String command)->(var Int status)

      execute ``command`` by the host command processor and return the return
      status of the command

      calls C ``system`` function

      :raises: if ``command`` is empty or outdated, or if command fails to
         execute

   .. cpp:function:: getenv(user String name)->(user String value, var Bool exists)

      get an environment variable

      if environment variable named ``name`` exists - copy into ``value`` the
      value of the environment variable and return :cpp:var:`true` in
      ``exists``, else - return :cpp:var:`false` in ``exists`` and do nothing
      with ``value``

Built-in Global Variables
#########################

.. cpp:var:: Sys sys

   Only this variable should be be used to access system data and functionality
   as exposed by the :cpp:type:`Sys` type interface.
