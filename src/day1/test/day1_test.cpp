#include "day1.h"
#include <gtest/gtest.h>

TEST(MainTest, BasicAssertions) {
  // Expect equality.
  EXPECT_EQ(sum(3, 4), 7);
}
