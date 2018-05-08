.. _native:

Calling C Code
==============
Lumi allows calling C code directly. This is useful for using an external C
library, or using already written C code.

In :ref:`TL4 <syntax-tl4>` this is only basically implemented. It is planned to
extend this feature greatly to make this as convenient as possible. The full
syntax is still under planning.

In :ref:`TL4 <syntax-tl4>` in order to call C code one must know how the
various types in :ref:`TL4 <syntax-tl4>` are implemented in `lumi.4.h`_. If the
types do not match the C types needed, a :ref:`proxy C code <proxy-c>` should
be added to convert the interface. This method should be used whenever a
certain C item cannot be called directly.

.. _lumi.4.h: https://github.com/meircif/lumi-lang/blob/master/TL4/lumi.4.h

Calling C Functions
-------------------
In order to call a C function it must be declared using the ``native func``
statement. The function is declared as a standard Lumi function, and the
C function should match the Lumi types as implemented in C. If this is not the
case a :ref:`proxy C function <proxy-c>` must be used. The function name should
use hyphens (``-``) instead of C underscores (``_``). ::

   ; Allow calling a C function with the following header:
   ; "Returncode c_function_name(Int number, Int* result)"
   native func c-function-name(copy Int number)->(var Int result)

Native functions do not support ``owner`` access arguments.

This function can now be called as any standard Lumi function.

Accessing C Global Variables
----------------------------
In order to access a C global variable it must be declared using the
``native var`` statement. The variable is declared as any uninitialized Lumi
global variable. The variable name should use hyphens (``-``) instead of C
underscores (``_``). ::

   native var Int c-global-variable

Only primitive types can be declared as native variables.

This variable can now be accessed as any standard Lumi variable.

Accessing Custom C Types
------------------------
It is possible to handle references for custom C types. These types are treated
as "abstract" references in Lumi, meaning that the exact structure is unknown
and cannot be accessed. This is only useful to store and manage references
for custom C types inside Lumi. The only way to use their content is by other
C functions.

The type name must match Lumi type naming (CamelCase), if this is not the case
- a :ref:`proxy C <proxy-c>` ``typedef`` must be written.

C types can be declared using the ``native type`` statement. ::

   native type CustomCType

Native types are treated as any standard Lumi **primitive** type.

.. _proxy-c:

Proxy C Code Example
--------------------
In :ref:`TL4 <syntax-tl4>` calling C code is only basically implemented, so in
many cases proxy C code must be written to connect between Lumi and C code
needed to be used from Lumi.

If we want to use C code from this header:

.. code-block:: c

   short some_func(char* text);

   typedef struct {
     int number;
     char* name;
     size_t length;
     int* items;
   } some_struct_t;

   int some_struct_action(some_struct_t* some_struct);

We need to add a proxy C code, for example:

.. code-block:: c

   #include "lumi.4.h"

   Returncode some_func_proxy(String* text, Int* result) {
     if (text == NULL) {
       *result = some_func(NULL);
     }
     else {
       *result = some_func(text->values);
     }
     return OK;
   }

   typedef some_struct_t SomeStructProxy

   Returncode some_struct_new(SomeStructC** new_struct) {
     *new_struct = malloc(sizeof(SomeStructC));
     if (*new_struct == NULL) {
       return ERR;
     }
     return OK;
   }

   Returncode some_struct_set_number(SomeStructC* self, Int number) {
     if (self == NULL) {
       return ERR;
     }
     if (name != NULL) {
       self->number = number;
     }
     return OK;
   }

   Returncode some_struct_set_name(SomeStructC* self, String* name) {
     if (self == NULL) {
       return ERR;
     }
     if (name != NULL) {
       self->name = name->values;
     }
     return OK;
   }

   Returncode some_struct_set_items(SomeStructC* self, Array* items) {
     if (self == NULL) {
       return ERR;
     }
     if (array == NULL) {
       self->length = 0;
       self->items = NULL;
     }
     else {
       self->length = array->length;
       self->items = array->values;
     }
     return OK;
   }

   Returncode some_struct_action_proxy(SomeStructC* self) {
     if (some_struct_action(self) != 0) {
       return ERR;
     }
     return OK;
   }

Now the C code can be used from Lumi::

   native func some-func-proxy(user String text)->(copy Int result)

   native type SomeStructProxy

   native func some-struct-new()->(var SomeStructProxy new-struct)
   native func some-struct-set-number(copy SomeStructProxy self, copy Int number)
   native func some-struct-set-name(copy SomeStructProxy self, user String name)
   native func some-struct-set-items(copy SomeStructProxy self, user Array{Int} items)
   native func some-struct-action-proxy(copy SomeStructProxy self)

   ; optional OOP conversion
   struct SomeStruct
     var SomeStructProxy c-ref

     func new()
       some_struct_new()->(var self.c-ref)

     func set-number(copy Int number)
       some-struct-set-number(copy self.c-ref, copy number)

     func set-name(user String name)
       some-struct-set-name(copy self.c-ref, user name)

     func set-items(user Array{Int} items)
       some-struct-set-items(copy self.c-ref, user items)

     func action()
       some-struct-action-proxy(copy self.c-ref)
