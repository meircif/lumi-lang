.. _integer-overflow:

Integer Ranges and Overflow Prevention
======================================

As part of :ref:`Lumi goal <goals>` #1 the compiler will enforce code that is
without any integer overflow (or underflow).


Integer Ranges
--------------
In Lumi all :ref:`integers <integer>` are declared with explicit range
``Int{minimum:maximum}`` and the compiler enforces that it will always contain
values inside this legal range.

For example, the compiler will not allow these assignments::
   
   func compute(Int{0:20} x)->(Int{-10:10} y)
      y := 20  ; error - clearly out of range
      y := other  ; error - may be out of range

Assigning a constant or an integer with overlapped range are naturally legal,
for example::
   
   func compute(Int{-10:10} x)->(Int{-20:20} y)
      y := 10  ; legal - inside legal range
      y := x  ; legal - all legal values of x are overlapped by y range

Integer Arithmetic
------------------
The result of any arithmetic operation is an integer with a new range based on
the operator. For example::
   
   func compute(Int{6:12} x, Int{0:100} y)
       x + y  ; return range is Int{6:112}
       x - y  ; return range is Int{-12:94}
       x * y  ; return range is Int{0:1200}
       x div y  ; return range is Int{0:16}
       x mod y  ; return range is Int{0:11}


Compile Time Overflow Prevention
--------------------------------
The compiler will not allow operation that may result in an overflow (or and
underflow). For example::
   
   func compute(Uint64 a, Uint64 b)
       a + b  ; error - potential overflow
       -a  ; error - potential underflow


Run-Time Overflow Checking
--------------------------
It is possible to check for an overflow in run-time using ``!`` or ``?``
together with one of ``+ - *`` operators. For example::
   
   ~~~ raises an error when overflow detected ~~~
   func ! raising-compute(Uint64 x, Uint64 y)->(Uint64 z)
       z := x +! y
       z := x -! y
       z := x *! y
         
   func handling-compute(Uint64 a, Uint64 b)->(Uint64 z)
       if-error z := x +? y
           z := 0
       if-error z := x -? y
           z := 0
       if-error z := x *? y
           z := 0


Efficient Native Wraparound
---------------------------
Utilizing native overhead-free wraparound is supported by using ``wraparound``
keyword. The result of native wraparound is naturally limited only for the
ranges that native wraparound is guaranteed to be supported: ``Uint8 Uint16
Uint32 Uint64`` (``Int{0:255} Int{0:65535} Int{0:4294967295}
Int{0:18446744073709551615}``). For other ranges wraparound must be done
manually using ``((value - min) mod (max - min + 1)) + min`` for example.

``wraparound`` can be used as a single unary operator before assignment or
together with one of ``+= -= *=`` assignment operators::
   
   func compute(Uint32 x)->(Uint32 y)
       y := wraparound x + 1
       y := compute(wraparound x - 1)
       y wraparound+= 1
       y wraparound-= 1
       y wraparound*= 1

The result range of using ``wraparound`` as above is the same as the target
assignee range (``Uint32`` in the examples above). This means that the assigned
range must always be one of ``Uint8 Uint16 Uint32 Uint64``.

``wraparound`` can also be used together with ``+ - *`` operators::
   
   func compute(Int{0:1000000} x, Uint64 y)->(Uint32 z)
       z := x wraparound+ y
       z := x wraparound- y
       z := x wraparound* y

The result range of using ``wraparound`` as above is the minimal from ``Uint8
Uint16 Uint32 Uint64`` that overlaps the left operand (``Uint32`` from ``x`` in
the examples above). This means that the left operand can be any unsigned
range.


Clamping
--------
Clamping allows shrinking an integer range to a smaller range ``Int{min:max}``
by converting any value larger than ``max`` to ``max`` and smaller than
``min`` to ``min``. This can be done automatically using ``clamp`` keyword.
Clamping is not overhead-free because the checking and converting must be done
at run-time.

``clamp`` can be used as a single unary operator before assignment or
together with one of ``+= -= *=`` assignment operators::
   
   func compute(Uint32 x)->(Uint32 y)
       y := clamp x + 1
       y := compute(clamp x - 1)
       y clamp+= 1
       y clamp-= 1
       y clamp*= 1

Using ``clamp`` as above will clamp the result to the range of the target
assignee (``Uint32`` in the examples above).

``clamp`` can also be used together with ``+ - *`` operators::
   
   func compute(Uint32 x, Uint64 y)->(Uint32 z)
       z := x clamp+ y
       z := x clamp- y
       z := x clamp* y

Using ``clamp`` as above will clamp the result to the range of the left operand
(``Uint32`` from ``x`` in the examples above).

On assignment it is possible to raise an error instead of clamping using ``!``
or ``?`` together with ``clamp``. Whenever a value is too small or big for the
assignee target range - instead of setting ``min`` or ``max`` an error is raised.
For example::
   
   ~~~ raises an error when clamping ~~~
   func ! raising-compute(Uint32 x)->(Uint32 y)
       y := clamp! x + 1
       y := raising-compute(clamp! x - 1)
         
   func handling-compute(Uint32 x)->(Uint32 y)
       if-error y := clamp? x + 1
           y := 0


Sequences Index Integer Range
-----------------------------
*planned - not supported in* :ref:`TL5 <syntax-tl5>`

It is planned to support a special range that is bound to a sequence and can
only hold values that are legal indices to the sequence.

It may look like this::
   
   func example(Array{Char} array)->(Char result)
       var Int{array} index
       result := array[index]  ; no need to check index at run-time
