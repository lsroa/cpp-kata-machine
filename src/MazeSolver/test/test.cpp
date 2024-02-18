#include <gtest/gtest.h>

#include <sstream>
#include <vector>

#include "maze.h"

void PrintMatrix(const matrix &mat) {
  for (const auto &row : mat) {
    for (const auto &element : row) {
      std::cout << element << " ";
    }
    std::cout << "\n";
  }
}

#define ASSERT_MATRIX_EQ(actual, expected) \
  if (expected != actual) {                \
    std::cerr << "Expected:\n";            \
    PrintMatrix(expected);                 \
    std::cerr << std::endl;                \
    std::cerr << "But got:\n";             \
    PrintMatrix(actual);                   \
    std::cerr << std::endl;                \
    ASSERT_EQ(expected, actual);           \
  }

matrix render(const matrix &maze, const std::vector<Point> &solution) {
  matrix data;
  for (const auto &line : maze) {
    std::istringstream is(line);
    std::string cell;
    while (std::getline(is, cell, '\0')) {
      data.push_back(cell);
    }
  }

  for (const auto &point : solution) {
    data[point.y][point.x] = '.';
  }

  return data;
};

TEST(Maze, Solver) {
  auto maze = matrix{
      // clang-format off
        "xxxxxxxxxx x",
        "x        x x",
        "x        x x",
        "x xxxxxxxx x",
        "x          x",
        "x xxxxxxxxxx",
      // clang-format on
  };

  auto start = Point{
      .x = 10,
      .y = 0,
  };

  auto end = Point{
      .x = 1,
      .y = 5,
  };

  auto got = solve(maze, start, end);
  auto want = std::vector<Point>{
      {.x = 10, .y = 0}, {.x = 10, .y = 1}, {.x = 10, .y = 2},
      {.x = 10, .y = 3}, {.x = 10, .y = 4}, {.x = 9, .y = 4},
      {.x = 8, .y = 4},  {.x = 7, .y = 4},  {.x = 6, .y = 4},
      {.x = 5, .y = 4},  {.x = 4, .y = 4},  {.x = 3, .y = 4},
      {.x = 2, .y = 4},  {.x = 1, .y = 4},  {.x = 1, .y = 5},
  };

  ASSERT_MATRIX_EQ(render(maze, got), render(maze, want));
}
