.. _built-in:

Built-in Types
==============

.. _integer:

Integer
-------
.. class:: Int(minimum-value, maximum-value)

   :param minimum-value: (optional) the minimum legal value (inclusive),
      default is ``0``
   :param maximum-value: the maximum legal value (inclusive)

   An integer that can only hold a range of values between its minimum and
   maximum (inclusive), enforced by the compiler. Obviously "minimum-value"
   should be equal or smaller than "maximum-value".
   
   For example: ``Int{10:20}``
   can only hold numbers between ``10`` and ``20``.
   
   If only one parameter is given it is treated as the maximum and the
   minimum is automatically ``0``.
   
   For example: ``Int{100}`` can only hold
   numbers between ``0`` and ``100``.
   
   If the minimum is negative the integer is consider "signed", else it is
   "unsigned".
   
   The actual representation of an integer in the memory is the
   minimal possible from 8,16,32,64 bits based on the limits. This mean that
   only ranges that fit in ``uint64_t`` or ``int64_t`` are supported:
   ``-9223372036854775808`` to ``9223372036854775807`` for signed
   integer, and ``0`` to ``18446744073709551615`` for unsigned.
   
   The default value of an uninitialized integer is ``0`` if it is within its
   legal range, otherwise the integer must be manually initialized.
   
   Aliases for common ranges:
      * ``Uint8`` for ``Int{0:255}``
      * ``Sint8`` for ``Int{-127:127}``
      * ``Uint16`` for ``Int{0:65535}``
      * ``Sint16`` for ``Int{-32767:32767}``
      * ``Uint32`` for ``Int{0:4294967295}``
      * ``Sint32`` for ``Int{-2147483647:2147483647}``
      * ``Uint64`` for ``Int{0:18446744073709551615}``
      * ``Sint64`` for ``Int{-9223372036854775807:9223372036854775807}``

   Supported integer literals:
      * decimal: ``70695``
      * binary: ``0b100101``
      * octal: ``0175``
      * hexadecimal: ``0xa30eb9f6``
      * negative integer: ``-`` before any positive integer literal: ``-23``
   
   A complete guide to integer range management is in :ref:`integer-overflow`.

   .. method:: str(user String text)

      write into ``text`` the integer converted to string in decimal

      :raises: if ``text`` is too short to store the number


Infinitely Long Integer
-----------------------
*planned - not supported yet in* :ref:`TL5 <syntax-tl5>`

.. class:: Long

   A signed integer that can be infinitely long (practically limited by
   the system memory). Automatically allocates heap memory to store the number.
   Is dramatically less efficient that a normal :ref:`integer <integer>`.


Boolean
-------
.. class:: Bool

   A boolean value that can only be a :data:`true` or a :data:`false`
   constant.

Constants:

.. data:: Bool true

.. data:: Bool false

.. _character:


Character
---------
.. class:: Char

   A single Unicode code-point, which is the same as `Int{1114111}`.

   Character literal are surrounded with ``'`` characters: ``'a'``. Special
   characters can be written with ``\`` escape character as in C: ``\' \" \? \a
   \b \f \n \r \t \v \\``.


Byte
----
.. class:: Byte

   A single memory byte value.

   Byte is treated as ``Int{255}``.


Real Number
-----------
*planned - not supported yet in* :ref:`TL5 <syntax-tl5>`

.. class:: Real

   Floating point real number, same as ``float`` in C.

   Real number literal is a decimal number with ``.`` character in the middle,
   with optional exponential suffix: ``2.4``, ``-0.3``, ``4.0``, ``2.34e2``,
   ``-5.678e-12``.


Function
--------
.. class:: Func(arguments)

   Holds (pointer to) a function.

   :param arguments: the function input and output :ref:`arguments <arguments>`

   For example: ``Func{()}``, ``Func{(copy Uint32 in)}``,
   ``Func{()->(var Uint32 out)}`` ,
   ``Func{(copy Uint32 in)->(var Uint32 out)}``.


Array
-----
.. class:: Array(length, subtype)

   Sequence of any typed item with static length.

   :param length: array static length and the actual allocation size
   :param subtype: the type of each item in the array

   For example: ``Array{12:Uint32}``, ``Array{6:String{16}}``.

   Array references should be declared without the ``length`` parameter:
   just ``Array{Uint32}`` or ``Array{String}`` for example.

   Accessing a single item can be done using ``array[index]``.
   
   .. note::
      If the index can be out of range it is checked at run-time and an error
      may raise. In such case the ``!`` warning sign must be used if error is
      to be propagated: ``array[index]!``.

   It is possible to extract a sub-array from an array by slicing:
   ``array[start-index:sub-array-length]``. This will not copy the array but
   return an array reference that points to the original array.

   .. method:: length()->(var Uint32 length)

      return (static) length of the array


.. _buffer:

Buffer
------

.. class:: Buffer(length)

   Alias for an :class:`Array` with :class:`Byte` items.

   :param length: length of the buffer and the actual allocation size

   For example: ``Buffer{5}``, ``Buffer{256}``.

   Buffer literals are hexadecimal strings surrounded by ````` characters:
   ```4a0069ff3487beef2649```.


.. _string:

String
------
.. class:: String

   Holds a legal UTF-8 string with dynamic length. The compiler ensures
   that the last character is a null-terminator (``'\0'``).

   String literals are strings surrounded by ``"`` characters: ``"I am a string
   literal"``. Escape :ref:`characters <character>` can be used.

   String literals may contain line breaks, with additional indentation
   of exactly 8 spaces. It is treated as ``\n``, or ignored if ``\`` is used
   before it::

      ; the same as "line\nbrake"
      s := "line
              break"

      ; the same as "linebrake"
      s := "line\
              break"
   
   String is currently not implicitly converted to ``Array{Byte}`` when needed.

   .. method:: length()->(var Uint32 length)

      returns current (dynamic) string length, not counting the null-terminator

   .. method:: new(user Buffer value)

      initialize this string with a copy of ``value``

      :raises: if not enough memory

   .. method:: clear()

      make this string empty

   .. method:: equal(user Buffer other)->(var Bool is-equal)

      return whether this string is exactly equal to ``other``

   .. method:: get(copy Uint32 index)->(var Char value)

      return character at place ``index``

      :raises: if ``index`` is out of range

   .. method:: set(copy Uint32 index, copy Char value)

      set character at place ``index`` to ``value``

      :raises: if ``index`` is out of range

   .. method:: append(copy Char character)

      append ``character`` to this string end

      :raises: if has no room for another character

   .. method:: concat(user Buffer other)

      concatenate ``other`` to this string end

      :raises: if has no room for ``other``

   .. method:: concat-int(copy Sint64 number)

      covert ``number`` to string and concatenate it to this string end

      :raises: if has no room for ``number`` string

   .. method:: find(user Buffer pattern)->(copy Uint32 index)

      return index of first occurrence of ``pattern`` in this string, return
      this string :data:`length` if ``pattern`` not found

   .. method:: has(copy Char character)->(var Bool has)

      return whether this string contains ``character``


Files
-----
.. class:: File

   Basic type for managing files, is extended by these types:
      
   * ``FileReadText``
   * ``FileReadBinary``
   * ``FileWriteText``
   * ``FileWriteBinary``
   * ``FileReadWriteText``
   * ``FileReadWriteBinary``
   
   .. method:: FileReadText(user String file-name)
   
      open ``file-name`` for read only in textual mode

      :raises: if file opening failed
      
   .. method:: FileReadBinary(user String file-name)
   
      open ``file-name`` for read only in binary mode

      :raises: if file opening failed
      
      
   .. method:: FileWriteText(user String file-name, copy Bool append)
   
      open ``file-name`` for write only in textual mode
      
      file is created if it does not exist
      
      if ``append`` is true all writes will be appended to the file end

      :raises: if file opening failed
      
   .. method:: FileWriteBinary(user String file-name, copy Bool append)
   
      open ``file-name`` for write only in binary mode
      
      file is created if it does not exist
      
      if ``append`` is true all writes will be appended to the file end

      :raises: if file opening failed
      
      
   .. method:: FileReadWriteText(user String file-name, copy Bool append, copy Bool create)
   
      open ``file-name`` for read and write in textual mode
      
      if ``append`` is true:
         
         file is created if it does not exist
         
         all writes will be appended to the file end
         
         ``create`` is ignored
      
      else, if ``create`` is true file is cleared of data if exists, or created
      if it does not exist

      :raises: if file opening failed
      
   .. method:: FileReadWriteBinary(user String file-name, copy Bool append, copy Bool exist)
   
      open ``file-name`` for read and write in binary mode
      
      if ``append`` is true:
         
         file is created if it does not exist
         
         all writes will be appended to the file end
         
         ``create`` is ignored
      
      else, if ``create`` is true file is cleared of data if exists, or created
      if it does not exist

      :raises: if file opening failed
      

   .. method:: close()

      close this file, does nothing if this file is already closed

      :raises: if closing failed
   
   .. method:: tell()->(var Sint64 offset)

      return current position of the file

      :raises: if getting offset failed
   
   .. method:: seek-set(var Sint64 offset)

      set file position to ``offset`` relative to file start

      :raises: if setting offset failed
   
   .. method:: seek-cur(var Sint64 offset)

      set file position to ``offset`` relative to the current position

      :raises: if setting offset failed
   
   .. method:: seek-end(var Sint64 offset)

      set file position to ``offset`` relative to file end

      :raises: if setting offset failed

   .. method:: flush()

      flush any buffered written data to the file

      :raises: if flush failed

   .. method:: get()->(var Char value, var Bool is-eof)

      *only available in* ``FileReadText`` *and* ``FileReadWriteText``
      
      read one character from this file into ``value`` or set ``is-eof`` to
      :data:`true` if end-of-file reached

      :raises: if read failed

   .. method:: get()->(var Byte value, var Bool is-eof)
      :noindex:

      *only available in* ``FileReadBinary`` *and* ``FileReadWriteBinary``
      
      read one byte from this file into ``value`` or set ``is-eof`` to
      :data:`true` if end-of-file reached

      :raises: if read failed

   .. method:: getline()->(user String line, var Bool is-eof)

      *only available in* ``FileReadText`` *and* ``FileReadWriteText``
      
      read one line from this file into ``line`` or set ``is-eof`` to
      :data:`true` if end-of-file reached
      
      new-line character is not added to ``line`` end

      :raises: if read failed or ``line`` is too short to store the line

   .. method:: read(user Array{Byte} data)->(var Uint32 bytes-read)

      *only available in* ``FileReadBinary`` *and* ``FileReadWriteBinary``

      read bytes from file to ``data`` up to the its length, set in
      ``bytes-read`` the number of actual read bytes

      :raises: if read failed

   .. method:: put(copy Char value)

      *only available in* ``FileWriteText`` *and* ``FileReadWriteText``

      write ``value`` character to this file

      :raises: if writing failed

   .. method:: put(copy Byte value)
      :noindex:

      *only available in* ``FileWriteBinary`` *and* ``FileReadWriteBinary``

      write ``value`` byte to this file

      :raises: if writing failed

   .. method:: write(user Array{Char} data)->(var Uint32 written)

      *only available in* ``FileWriteText`` *and* ``FileReadWriteText``

      try write all ``data`` characters to this file, set in ``written`` the
      number of actual written characters

      :raises: if writing failed

   .. method:: write(user Array{Byte} data)->(var Uint32 written)
      :noindex:

      *only available in* ``FileWriteBinary`` *and* ``FileReadWriteBinary``

      try write all ``data`` bytes to this file, set in ``written`` the number
      of actual written bytes

      :raises: if writing failed


``sys`` Module
--------------

.. data:: Array{String} sys.argv

   holds program arguments

.. data:: FileReadText sys.stdin

   can be used to **read** from the standard input stream

.. data:: FileWriteText sys.stdout

   can be used to **write** to the standard output stream

.. data:: FileWriteText sys.stderr

   can be used to **write** to the standard error stream

.. function:: sys.print(user String text)

   print ``text`` to the standard output stream, same as calling
   ``sys.stdout.write``

   :raises: if writing failed

.. function:: sys.println(user String text)

   print ``text`` appended with new-line character to the standard output
   stream

   :raises: if writing failed

.. function:: sys.getchar()->(var Char character, var Bool is-eof)

   read one character from the standard input stream into ``value`` or set
   ``is-eof`` to :data:`true` if end-of-file reached, same as calling
   ``sys.stdin.get``

   :raises: if read failed

.. function:: sys.getline(user String line)->(var Bool is-eof)

   read one line from the standard input stream into ``line`` or set ``is-eof``
   to :data:`true` if end-of-file reached, same as calling
   ``sys.stdin.getline``
   
   new-line character is not added to ``line`` end

   :raises: if read failed or ``line`` is too short to store the line

.. function:: sys.exit(copy Sint32 status)

   terminates execution of the program immediately with ``status`` as the
   exit status value

   calls C ``exit`` function

   :raises: if exiting failed

.. function:: sys.system(user String command)->(var Sint32 status)

   execute ``command`` by the host command processor and return the return
   status of the command

   calls C ``system`` function

   :raises: if command fails to execute

.. function:: sys.getenv(user String name, user String value)->(var Bool exists)

   set into ``value`` the value of the environment variable ``name``, or set
   ``exists`` to :data:`false` if it does not exist
