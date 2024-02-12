# add_library(single src/main.cpp)

add_executable(single_test test/test.cpp)
target_include_directories(single_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(single_test PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(single_test)
