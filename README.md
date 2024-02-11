Simple fork of the @ThePrimeagen kata-machine written in c++17, cmake and gtest.

### Structure
Every subfolder has 3 files `src/<name>.cpp`,`src/<name>.h` and `test/<name>_test.cpp`that correspond to implementation, header and test.

### Dependencies
- cmake
- gcc ++17

### Getting started
- build 

```sh
cmake -S . -B build
```
- run all tests

```sh
cd build && ctest .
```
- run specific test 

```sh
cd build && ctest -R pattern 
```
