General Syntax Highlights
=========================

* blocks are declared with indentation (as in Python)

* strict white-spacing:

  - tabs are syntax errors
  - indentation is exactly 2 spaces
  - exactly one space around operators
  - file must end with a newline
  - more as can be seen in the examples...

* "Kebab case" naming conventions:

  Everything is ``lowercase-only-with-hyphens`` except types that are
  ``FirstLetterUppercase`` (CamelCase) and compile time constants that are
  ``FULLY-UPPERCASE``.

.. _syntax:

Work in progress...
-------------------
The Lumi language is still a work in progress and the final syntax is not decided yet. The latest working compiler is for Temporary Lumi 4 (TL4) syntax, and this spec will describe it, and the differences between it and the planned final Lumi syntax.

The planned final Lumi syntax is still in development, so this spec is a taste of what **may** be the final syntax. Changes will happily be made based on coding experience and suggestions.

..
   # Examples
   _written in TL4, see [[spec|Lumi-Syntax#spec]] for comparison with the planned final syntax._
   ## Hello World
   ```
   main func()
     sys.println(user "hello world")
   ```

   ## Fibonacci
   ```
   func fibonacci(copy Int n)->(var Int res)
     var Int prev(copy 1)
     res := 0
     for _ in n
       var Int sum(copy res + prev)
       prev := res
       res := sum
   ```

   ## Complex number
   ```
   struct Complex
     var Int real
     var Int imaginary

     func str(user String out-str)
       self.real.str(user out-str)
       out-str.append(copy ' ')
       if self.imaginary > 0
         out-str.append(copy '+')
       else
         out-str.append(copy '-')
       out-str.append(copy ' ')
       var String{128} imaginary-str
       if self.imaginary > 0
         self.imaginary.str(user imaginary-str)
       else
         (-self.imaginary).str(user imaginary-str)
       out-str.concat(user imaginary-str)
       out-str.append(copy 'i')

   main
     var Complex complex
     complex.real := 5
     complex.imaginary := 3
     var String{1024} complex-str
     complex.str(complex-str)
     sys.println(complex-str)
   ```

   # Spec

   ## Comments
   ```
   ; single line comment
   [; <-- multi-line comment start
   multi
   line
   comment
   multi-line comment end --> ;]
   var Int x  ; this will also be a comment in the final syntax - not supported yet
   ```

   ## Basics
   ```
   ; primitive types
   var Int integer-stack-variable(copy 3)  ; initialized with "3"
   var Bool boolean-variable(copy false)
   var Char character-variable(copy 'r')
   var Byte single-byte-variable(copy `4f`)  ; planned in the final syntax - not supported yet
   var Real real-number(copy 3.6)  ; floating-point - not supported yet
   ; the `copy` will not be needed in the final syntax

   const Int COMPILE-TIME-CONSTANT 12
   ; in the final syntax:
   const Int COMPILE-TIME-CONSTANT(12)

   ; built-in complex types
   var Array{34:Int} integer-array  ; allocated in the stack with 34 length
   var String{128} string-variable
   var Buffer{6} buffer-variable(`39a4e0f112c7`)  ; planned in the final syntax - not supported yet
   user String string-reference(user "a static string")
   ; the `user` will not be needed in the final syntax

   ; operators
   integer-stack-variable := 3 + 8 - (4 * 7 div 2 mod 6)
   boolean-variable := true or false and 3 >= 6 or 5 = 6 or not 6 != 0
   ```
   ### Operator Precedence
   1. `. [] () ?`, left-to-right
   1. `- +`, `* div mod`, `bor band xor >> <<`, left-to-right _(1)_
   1. `= != > < >= <= is is-not`, left-to-right _(2)_
   1. `not`, only one is logical
   1. `or`, `and`, left-to-right _(1)_
   1. `:= += -= *=`, only one allowed

   _(1) cannot combine operators from different sub-groups of this group, they must be separated using `()`
   (2) multiple operators from this group combined will be separated with `and` operator, for example, `a < b < c < d` is treated as `(a < b and b < c and c < d)`_

   ## Control Flow
   ```
   if num > 30
     ; do
     ; stuff
   else-if num < 7
     ; do
     ; stuff
   else
     ; do
     ; stuff

   ; A loop that continues while every "while" statement inside is true,
   ; stops immediately when the first "while" statement inside is false
   do
     ; do stuff
     while num < 6  ; continue with the loop while condition is true, else breaking immediately
     ; do stuff
     while not boolean-variable  ; yes, multiple "while" statement are supported
     ; do stuff
     if num = 0
       ; do stuff
       break
     if num = 3
       ; do stuff
       continue
     ; do stuff

   for num in 3:7  ; "num" will iterate 3,4,5,6
     ; do stuff with "num"

   ; planned - not supported yet
   switch number
   case 34
     ; do stuff
   case 23
     ; do stuff
     fallthrough  ; this is not the default
   case 45, 67, 26, 56, 67, 89, 56, 87
     ; do stuff
   default
     ; do stuff
   ```

   ## Functions
   ```
   func function-name(copy Int parameter)->(var Int return-value)
     ; in the final syntax `copy` and `var` may be omitted
     ; do stuff ...
     return-value := 0
     return-value := parameter + return-value

   func multi-argument-function(
       copy Int parameter-by-value,
       user String parameter-by-reference)->(
       var Int return-by-value,
       user String return-by-reference)
     ; do
     ; stuff
     return 4, "some string"  ; planned - not supported yet, instead:
     return-by-value := 4
     return-by-reference := "some string"

   var Int result := function-name(copy 4)
   ; in the final syntax `copy` is not needed

   ; planned:
   var Int value, user String reference := multi-argument-function(
     copy 2,
     user "input string")
   ; currently only the last output is returned:
   var Int value
   user String reference := multi-argument-function(
     copy 2,
     user "input string",
     var value)
   ```

   ## Type Aliasing - planned
   ```
   alias New-name for Array{8:Int}
   ```

   ## Documentation
   ```
   ~~~ single line documentation ~~~
   func documented-function()
     ; do stuff

   ~~~  <-- multi-line documentation start
   multi
   line
   documentation
   multi-line documentation end --> ~~~
   func another-documented-function()
     ; do stuff
   ```

   ## Testing and Mocking
   ```
   test test-function()
     assert 3 < 5

   mock mocked-function()
     ; alternative implementation when running tests
   ```

   ## Type System
   A work in progress, see [[Type system|Type-system]] for some examples.

   ## Error Handling
   Not decided yet...
   `raise` keyword will probably be used to raise an error,
   `!` sign may also be used (somehow...).

   ## Modules and Libraries
   Not decided yet...

   ## Profiling
   Not decided yet...
