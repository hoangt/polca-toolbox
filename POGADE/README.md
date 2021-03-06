
Pogade
======

POGADE (POlca Graph Analysis & Development Environment) is a tool that makes it possible to visualize the static hierarchy graph, the inter-relationships and hierarchies between the POLCA blocks and the Higher-Order functions and data dependencies among them. Visualization parameters, including the ability for the user to surf the generated graph (i.e., zooming in and out subgraphs and the hierarchical annotations) can be changed interactively; it supports exporting to external files.

Dependencies
------

Qt5 libraries (> 5.2, mainly tested on 5.5.1).

OGDF libraries (release 2015-05)

QuaZip (> 0.7.0, tested with 0.7.2)

QScintilla2 (> 2.8, tested with 2.9.2)



Compilation
------

The Makefile is generated by the tool qmake that is provided with the Qt developer libraries:

<pre>
$ mkdir build
$ cd build
$ qmake ../pogade.pro
$ make
</pre>

Run
------

<pre>
$ ./pogade
</pre>

Usage
------

To be able to work with POGADE it is needed to create a project in which to add existing code files or create new ones. Editing the files inside a project allows to track the changes, create branches and making sure that all the changes are reversible.
