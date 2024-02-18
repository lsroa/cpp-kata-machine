#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "maze.h"

const std::vector<Point> dirs{
    // clang-format off
	{.x = 0 , .y = 1},
	{.x = 1 , .y = 0},
	{.x = 0 , .y = -1},
	{.x = -1 , .y = 0},
    // clang-format on
};

bool walk(matrix &map, const Point &current, const Point &end,
          std::vector<Point> &path, std::vector<std::vector<bool>> &seen) {
  // its out of bounds
  if (current.y >= map.size() || current.x >= map[0].size()) {
    return false;
  }

  // its a wall
  if (map[current.y][current.x] == 'x') {
    return false;
  }

  // its the end
  if (current.y == end.y && current.x == end.x) {
    path.push_back(current);
    return true;
  }

  // was already visited
  if (seen[current.y][current.x]) {
    return false;
  }

  seen[current.y][current.x] = true;
  path.push_back(current);

  for (const auto &dir : dirs) {
    Point next = {
        // clang-format off
			.x = current.x + dir.x, 
			.y = current.y + dir.y,
        // clang-format on
    };
    if (walk(map, next, end, path, seen)) {
      return true;
    }
  }

  path.erase(std::find(path.begin(), path.end(), current));

  return false;
}

std::vector<Point> solve(matrix &map, Point current, Point end) {
  std::vector<Point> result;
  std::vector<std::vector<bool>> seen;
  seen.resize(map.size());

  for (auto &row : seen) {
    row.resize(map[0].size());
  }

  walk(map, current, end, result, seen);

  return result;
};
