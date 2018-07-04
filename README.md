# Requirements

* C++ build system
* CMake 3.2+
* python 3 and pip (to install the conan package manager)
* Additional requirements will be installed by conan

## Installing requirements

### C++ Build System
For Ubuntu Linux, this is usually satisfied by the build_essentials package:

```shell
sudo apt install build_essentials
```

### CMake
CMake is a build system that generates build files for a system's native build
tools.

```shell
sudo apt install cmake
```

### conan
Conan is a C/C++ package manager system.  It runs under Python 2 or 3 and is
available in PyPI.  But, Python 2 will soon not be supported by the Python
devleopers, so use of 3 is recommended.

```shell
pip3 install conan
```

And bintray respository for pdcurses will need to be set up:

    $ conan remote add alexwarrior-conan https://api.bintray.com/conan/alexwarrior-org/alexwarrior-conan


The requirements as set up in the file conanfile.txt can be compiled and installed in the user home directory as:

    $ cd build
    $ conan install ..

If building for a 32-bit x86 machine, you might need to specify the platform as:

    $ conan install .. -s arch=x86


# Building
```shell
cd build
cmake .. -G "Unix Makefiles"
cmake --build .
```
# Testing

Testing is provided by the Google Test framework. Run tests from the project
build directory as:
```shell
test/bin/test_runner
```
