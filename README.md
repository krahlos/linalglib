# Linear Algebra Library

* [About](#about)
* [Development Environment](#devenv)
* [How-to Build](#build)
* [Authors](#authors)
* [License](#license)

## <a name="about">About</a>
A playground for learning basic and enhanced concepts of C++, CMake and How-to-build-a-C++-Library wrapped up in a Linear Algebra library.

## <a name="devenv">Development Environment</a>
+ macOS Sierra 10.12.6
+ [Visual Studio Code](https://code.visualstudio.com)

## <a name="build">How-to Build</a>

### Perquisites
+ [CMake 3.12 or later](https://cmake.org/download/)
+ [GCC 7.1 or later](http://gcc.gnu.org/onlinedocs/)

### Build
*To be finished...*

> Clone the repository
```
cd /path/to/repo/collection
git clone https://github.com/marco1893/linalglib.git
```
> Create a build/ directory inside the local repository
```
cd linalglib
mkdir build
```
> Run CMake in the build directory. Ensure you have installed all requirements before running CMake.
```
cd build
cmake ..
```
> To build the lib, invoke the default build target
```
cmake --build . --config Release --clean-first
```

### How-to test
*Test settings to be done...*

## <a name="authors">Authors</a>

+ **Marco Krahl** - [marco1893](https://github.com/marco1893)

## <a name="license">License</a>

No license.
