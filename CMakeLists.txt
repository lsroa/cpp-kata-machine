cmake_minimum_required(VERSION 3.28)
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

list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")

add_subdirectory(src/BubbleSort)
add_subdirectory(src/BinarySearch)
add_subdirectory(src/SingleLinkedList)
add_subdirectory(src/Stack)
add_subdirectory(src/Queue)
