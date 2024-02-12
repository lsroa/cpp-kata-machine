cmake_minimum_required(VERSION 3.10)
project(kata)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip 
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(src/BubbleSort)
add_subdirectory(src/BinarySearch)
