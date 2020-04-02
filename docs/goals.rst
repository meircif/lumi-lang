.. _goals:

Lumi Language Goals and Features
================================

Prioritized Goals
-----------------
1. **Enforce safe and reliable code**, free from:

   * illegal memory access
   * memory corruption
   * memory leaks
   * integer overflow
   * unexpected crashes
   * etc...

2. **Allow writing of efficient code**, suitable for real-time embedded:

      Modern programming languages solve goal #1 by making everything
      dynamically allocated and garbage collected, but this is inefficient and
      unpredictable. Lumi will allow as much efficiency and freedom as
      possible, as long as goal #1 is not harmed.

3. Be **flexible**, **easy to write**, and **easy to maintain**:

   This goal binds together 3 different goals:

   * **Flexible** - whenever possible Lumi should allow choosing from a
     variety of options
   * **Easy to write** - Lumi code should be easy to learn and writing code
     should be as efficient as possible
   * **Easy to maintain** - It should be easy to find and fix bugs and add new
     features, even in large and complex projects

   The above goals are bound together because no one is prioritized above the
   other and they sometimes contradict. Lumi will do its best to reach all of
   them with minimum harm to each one.


Features
--------
* **Code generating**: Lumi compiler will initially generate **C code**.
  Other "modern machine language" codes may also be generated, such as: Java
  (for Android and other devices), Objective-C/Swift (for Apple devices),
  JavaScript/WebAssembly (for web application), and more...
* Safe :ref:`memory-management` - allowing easy trade-off between flexibility
  and performance by the user
* :ref:`thread-safety` - Lumi code is ensured to be thread safe
* :ref:`integer-overflow` - Lumi code is ensured to be free from integer
  overflow and underflow
* :ref:`type-system` - Lumi is **strongly typed**, and allows variety of typing
  styles with different trade-offs between simplicity, generality and
  performance
* Exception-like error handling implemented with return values
* Strict coding conventions - all Lumi code should look the same
* Built-in support for productivity features:

      * testing and mocking
      * documentation
      * profiling
