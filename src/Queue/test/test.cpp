#include <gtest/gtest.h>

#include "queue.h"

TEST(Queue, List) {
  auto list = new Queue<int>();

  list->enqueue(5);
  list->enqueue(7);
  list->enqueue(9);

  EXPECT_EQ(list->deque(), 5);
  EXPECT_EQ(list->length, 2);

  list->enqueue(11);
  EXPECT_EQ(list->deque(), 7);
  EXPECT_EQ(list->deque(), 9);
  EXPECT_EQ(list->peek(), 11);
  EXPECT_EQ(list->deque(), 11);
  EXPECT_THROW(list->deque(), std::range_error);
  EXPECT_EQ(list->length, 0);

  list->enqueue(69);
  EXPECT_EQ(list->peek(), 69);
  EXPECT_EQ(list->length, 1);
}
