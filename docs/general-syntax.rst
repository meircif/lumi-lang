.. _syntax:

General Syntax Highlights
=========================

* blocks are declared with indentation (as in Python)

* strict white-spacing:

   - tabs are syntax errors
   - indentation is exactly 4 spaces
   - no spaces in line end
   - extra indentation for line breaking is exactly 8 spaces
   - exactly one space around operators
   - file must end with a single newline
   - in general, any whitespace in the syntax must be used exactly

* strict naming conventions:

   - everything is ``lowercase-only-with-hyphens`` (a.k.a "kebab-case")
   - types are ``FirstLetterUppercase`` (a.k.a "CamelCase)
   - compile time constants are ``UPPERCASE-ONLY-WITH-HYPHENS`` (a.k.a
     "FAT-KEBAB-CASE")

TL[number] - Temporary Lumi Language
------------------------------------
Lumi language development is done in an iterative style, where in each
step a compiler is written to a temporary Lumi language - "TL" in short - which
is a partial (or different) syntax of the final Lumi language.

These temporary Lumi languages are marked as "TL[number]" where "number is the
iteration step number. "TL0" is the initial compiler temporary Lumi language,
the next iteration is TL1 and so on...

.. _syntax-tl4:

Latest Version - TL4
--------------------
The Lumi language is still a work in progress and the final syntax is not
decided yet. The latest working compiler is for Temporary Lumi 4 (TL4) syntax,
and this guide will describe it, and the differences between it and the planned
final Lumi syntax.

The final Lumi syntax is still under planning, so this guide refers only to the
current planning state of the final syntax. Changes will happily be made based
on coding experience and suggestions.
