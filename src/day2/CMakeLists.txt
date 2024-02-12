add_library(day2 src/main.cpp)
target_include_directories(day2 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_executable(test_day2 test/test.cpp)
target_link_libraries(test_day2 gtest_main day2)

include(GoogleTest)
gtest_discover_tests(test_day2)
