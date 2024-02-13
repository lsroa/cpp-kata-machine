#include <gtest/gtest.h>

#include <stdexcept>

#include "stack.h"

TEST(Stack, List) {
  auto stack = new Stack<int>();

  stack->push(5);
  stack->push(7);
  stack->push(9);

  EXPECT_EQ(stack->pop(), 9);
  EXPECT_EQ(stack->length, 2);

  stack->push(11);
  EXPECT_EQ(stack->pop(), 11);
  EXPECT_EQ(stack->pop(), 7);
  EXPECT_EQ(stack->peek(), 5);
  EXPECT_EQ(stack->pop(), 5);
  EXPECT_THROW(stack->pop(), std::range_error);

  stack->push(69);
  EXPECT_EQ(stack->peek(), 69);
  EXPECT_EQ(stack->length, 1);
}
