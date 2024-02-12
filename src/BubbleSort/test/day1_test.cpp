#include "day1.h"
#include <gtest/gtest.h>

TEST(BubbleSort, BasicSorting) {
  auto arr = std::vector<int>{9, 3, 7, 4, 69, 420, 42};
  bubble_sort(arr);

  auto want = std::vector<int>{3, 4, 7, 9, 42, 69, 420};
  EXPECT_EQ(want, arr);
}
