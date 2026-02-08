dlopen(3) example

* libfoo build in foo/interface uses dlopen() on foo.so build in foo/lib
* bar uses libfoo without any linker dependency on foo.so

the toplevel Maekfile has a "run" target to test it out

All code in this repo is for educational purposes only and hereby placed in the public domain.

