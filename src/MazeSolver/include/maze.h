#pragma once

#include <ostream>
#include <string>
#include <vector>

typedef std::vector<std::string> matrix;

class Point {
 public:
  Point() = default;
  int x, y;

  friend std::ostream &operator<<(std::ostream &out, const Point &point);

  bool operator==(const Point &b) const {
    //
    return b.x == x && b.y == y;
  }
};

inline std::ostream &operator<<(std::ostream &out, const Point &point) {
  out << "{ " + std::to_string(point.x) + ", " + std::to_string(point.y) + " }";
  return out;
}

std::vector<Point> solve(std::vector<std::string> &map, Point start, Point end);
