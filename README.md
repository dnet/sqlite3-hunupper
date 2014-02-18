UPPER() for SQLite3 that handles Hungarian accented characters
==============================================================

Building
--------

	$ make

Cross-compiling for Windows with MinGW
--------------------------------------

 - download `sqlite-amalgamation` from https://www.sqlite.org/download.html
 - extract all files from the ZIP
 - (install MinGW if you haven't done so already, Debian/Ubuntu package: `mingw32`)
 - run `CC=i586-mingw32msvc-gcc CFLAGS=-I/path/to/sqlite-amalgamation make`
 - rename `hunupper.so` to `hunupper.dll`

Example usage
-------------

	sqlite> .load ./hunupper.so
	sqlite> select HUNUPPER("árvíztűrő tükörfúrógép");
	ÁRVÍZTŰRŐ TÜKÖRFÚRÓGÉP

License
-------

The whole project is available under MIT license, see `LICENSE.txt`.
