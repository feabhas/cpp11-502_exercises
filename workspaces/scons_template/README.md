# Using the Scons build system

SCons is an Open Source software construction tool—that is, a next-generation build tool. Think of SCons as an improved, cross-platform substitute for the classic Make utility with integrated functionality similar to autoconf/automake and compiler caches such as ccache. In short, SCons is an easier, more reliable and faster way to build software.

## Prerequisites

* Python
* [Scons](https://scons.org/)


## Build and Run

1.  $ scons
2.  $ ./App

## To clean
1.  $ scons -c  


## Testing the application

The project has been configured to use the modern, header-only, C++ testing framework [doctest](https://github.com/onqtam/doctest). 

To run them, simply type:
```
$ scons --tdd
$ ./App
```
