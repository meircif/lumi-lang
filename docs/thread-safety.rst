.. _thread-safety:

Thread Safety
=============

Running threads should be safe to reach :ref:`Lumi goal <goals>` +1, therefore
the compiler will enforce it.

*This page explains a first suggestion to implement this.*

The default approach - complete data isolation
----------------------------------------------
The compiler takes care that each data is only accessible from a single
thread - creating a complete isolation of data between threads. Global data
will be duplicated for each thread (probably using "thread local" mechanism).
This mean no data sharing is possible - ensuring thread safety.

This is the default approach on all data unless one of the thread data sharing
mechanism described below is used.

Sharing data between threads
----------------------------

Constant and immutable data
+++++++++++++++++++++++++++

Every compile-time constant or run-time immutable data can be safely shared
between threads. The compiler will ensure no thread can modify these data.

Atomic operations
+++++++++++++++++
Based on the platform, atomic types will be provided, and all operations on an
atomic item will be atomic.

Messaging
+++++++++
It will be possible to send messages between threads, the data on the message
will be copied from one thread to another in a safe manner taken care by the
compiler.

Built-in thread-safe data structures
++++++++++++++++++++++++++++++++++++
Various built-in thread-safe data structures will be provided that can be used
to share data between threads.

Automatic locks
+++++++++++++++
It will be possible to mark data as thread-shared, and the compiler will
automatically protect access to this data using various lock types.
