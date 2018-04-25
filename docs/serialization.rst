Serialization
=============

3 types of converting structures to buffers, and vice versa:

* encoding - same layout as the structure memory
* serializing - platform-independent and CPU efficient implicit layout
* packing - explicit user defined layout

============== ============== ============== ============== ==============
type           CPU            memory         cross-platform explicit
============== ============== ============== ============== ==============
encoding       best           medium         no             no
serializing    medium         worst          yes            no
packing        worst          best           yes            yes
============== ============== ============== ============== ==============
