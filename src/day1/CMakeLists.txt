add_library(day1 src/day1.cpp)
target_include_directories(day1 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(day1_test test/day1_test.cpp)
target_link_libraries(day1_test PRIVATE day1 gtest_main)

include(GoogleTest)
gtest_discover_tests(day1_test)
