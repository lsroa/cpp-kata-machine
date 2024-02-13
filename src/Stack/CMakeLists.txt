add_executable(stack_test test/test.cpp)
target_include_directories(stack_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(stack_test PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(stack_test)
