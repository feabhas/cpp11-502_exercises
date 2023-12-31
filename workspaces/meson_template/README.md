# Using the Meson and Ninja build system

Meson is an open source build system meant to be both extremely fast, and, even more importantly, as user friendly as possible.

Ninja is a small build system with a focus on speed. It differs from other build systems in two major respects: it is designed to have its input files generated by a higher-level build system, and it is designed to run builds as fast as possible.

## Prerequisites

* Python
* [Meson](https://mesonbuild.com/)
* [ninja](https://ninja-build.org/)


## Build and Run
### Create a build directory

This is typically a one-off operation

Create the build directory (this can be any name, `builddir` is used here)
   ```
   $ meson builddir
   $ cd builddir
   ```

### Build the application 
The project is compiled by invoking the Ninja build tool.
```
$ ninja
```
this will create the application under the subdirectory `src`

### Run the application

Invoke the application from the command line:
```
$ ./src/app
```
The name of the application, e.g. `app` is configured  in the file `src/meson.build` on the line `executable('app',...`

### Rebuild

To rebuild and rerun the application, simply repeat:
```
$ ninja
$ ./src/app
```

### Adding new source files
To add new `.cpp`files to the project, add the filenames to the line in the `src/meson.build` file:
```
app_src = []
```
e.g.
```
app_src = ['file1.cpp', 'file2.cpp']
```
As lonk as headers are in the `src` directory, the project will discover them as part of the build


## Testing the application

The project has been configured to use the modern, header-only, C++ testing framework [doctest](https://github.com/onqtam/doctest). 

When building with meson/ninja the test, any tests defined in `test/meson.build` are automatically built.

To run them, simply type:
```
$ meson test
```
Any failures will be reported, with the full `doctest` reporting found in the file:
```
/build/meson-logs/testlog.txt
```