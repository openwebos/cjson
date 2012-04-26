cjson
=====

This repository contains the edition of the open-source json-c library used by webOS.

How to Build on Linux
=====================

## Dependencies

Below are the tools and libraries (and their minimum versions) required to build cjson:

* autoconf 2.61
* automake 1.9.3
* gcc 4.3
* libtool 1.5.24
* make (any version)

## Building

Once you have downloaded the source, execute the following to build it:

    $ sh autogen.sh
    $ ./configure --disable-static
    $ make
    $ sudo make install

The header files will be installed under

    /usr/local/include/cjson

and the libraries and the pkg-config file under

    /usr/local/lib

You can install it elsewhere by supplying the _--prefix_ option when invoking _configure_. For example:

    $ ./configure --disable-static --prefix=$HOME/projects/openwebos
    $ make
    $ sudo make install
    
will install the header files under

    $HOME/projects/openwebos/include/cjson
    
and the libraries and the pkg-config file under

    $HOME/projects/openwebos/lib
    
directory.

To undo what _make install_ did, run:

    $ sudo make uninstall

## Generating documentation

The tools required to generate the documentation are:

* doxygen 1.6.3
* graphviz 2.20.2

Once you have run _configure_, execute the following to generate the documentation:

    $ make doc

To view the generated HTML documentation, point your browser to:

    doc/html/index.html

## Testing

To build the test programs, run:

    $ make check

## Linking against libcjson

If your system has pkg-config then you can just add this to your makefile:

CFLAGS += $(shell pkg-config --cflags cjson)
LDFLAGS += $(shell pkg-config --libs cjson)

# Copyright and License Information

See the file COPYING.
