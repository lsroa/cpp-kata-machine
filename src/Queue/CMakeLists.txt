set(CTEST_OUTPUT_ON_FAILURE ON)
add_executable(queue_test test/test.cpp)
target_include_directories(queue_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(queue_test PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(queue_test)
