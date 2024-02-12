#include "day2.h"
#include <gtest/gtest.h>

TEST(BinarySearchList, Search) {
  auto arr = std::vector<int>{1, 3, 4, 69, 71, 81, 90, 99, 420, 1337, 69420};

  EXPECT_EQ(binary_search(arr, 69), true);
  EXPECT_EQ(binary_search(arr, 1336), false);
  EXPECT_EQ(binary_search(arr, 69420), true);
  EXPECT_EQ(binary_search(arr, 69421), false);
  EXPECT_EQ(binary_search(arr, 1), true);
  EXPECT_EQ(binary_search(arr, 0), false);
}
