# Daily Coding Challenge

A collection of problems meant for daily coding exercises.
The _current_ goal is one year of daily coding, i.e. 365 small programs.

An (optimal) problem results in a self-contained program, algorithm or data
structure, which can be implemented within approximately one hour.
Alternatively, series of sub-problems yield logically and structurally
independent solutions to a more complex problem.
It may then be solved by combining the previous solutions.

**Note**: Algorithms and data structures should be implemented generically,
i.e. they should be able to handle data of any size and type, unless explicitly
stated otherwise (e.g. LSD radix sort, which makes use of integer types).

## Project structure

The solution to each coding problem is implemented within a numbered
subdirectory of [dailies](dailies) as a standalone library or package, i.e.
files such as `CMakeLists.txt` or `__init__.py` accompany the source code s.t.
seamless integration of the code in other projects is possible.
Still, the overall project setup is done in [lang/\<language\>](lang) using
symlinks to the source code directories.
Moreover, unit tests are defined here.

## Building the project

### C++

Recommended build:

```shell
cd lang/cpp
mkdir build && cd build
cmake .. && make
```

CMake fetches [GoogleTest](https://google.github.io/googletest/) which is built
as part of the project.
In order to generate the project documentation,
[Doxygen](https://doxygen.nl/manual/starting.html) needs to be installed.
If you do not wish to enable this feature, set the `BUILD_DOC` CMake variable to
`OFF`:

```shell
cmake .. -DBUILD_DOC=OFF
```

Non-exhaustive overview of supported build targets:

```shell
make all   # default target, builds all project targets
make clean # remove all files generated during the compilation process
make doc   # generate the project documentation using Doxygen
make test  # execute all unit tests
```
