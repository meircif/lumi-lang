Serialization
=============

This is not supported yet in :ref:`TL4 <syntax-tl4>`.

Lumi is planned to support 3 layout types for converting structures to buffers, and
vice versa:

* **encoding** - same layout as the structure platform-specific memory layout
* **serializing** - platform-independent and CPU efficient implicit layout
* **packing** - explicit, platform-independent, user defined layout

=============== ============== ============== ============== ==============
type            CPU            memory         cross-platform explicit
=============== ============== ============== ============== ==============
**encoding**    best           medium         no             no
**serializing** medium         worst          yes            no
**packing**     worst          best           yes            yes
=============== ============== ============== ============== ==============
