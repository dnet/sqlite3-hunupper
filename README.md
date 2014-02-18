UPPER() for SQLite3 that handles Hungarian accented characters
==============================================================

Building
--------

	$ make

Example usage
-------------

	sqlite> .load ./hunupper.so
	sqlite> select HUNUPPER("árvíztűrő tükörfúrógép");
	ÁRVÍZTŰRŐ TÜKÖRFÚRÓGÉP

License
-------

The whole project is available under MIT license, see `LICENSE.txt`.
