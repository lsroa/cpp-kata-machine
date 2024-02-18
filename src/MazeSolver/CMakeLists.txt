add_library(maze src/main.cpp)
add_executable(maze_test test/test.cpp)

target_include_directories(maze_test PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(maze PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(maze_test PRIVATE maze gtest_main)

include(GoogleTest)
gtest_discover_tests(maze_test)
