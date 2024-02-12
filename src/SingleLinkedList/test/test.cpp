#include <gtest/gtest.h>

#include "single.h"

TEST(SingleLinkedList, List) {
  auto list = new LinkedList<int>();

  list->append(5);
  list->append(7);
  list->append(9);

  EXPECT_EQ(list->get(2), 9);
  EXPECT_EQ(list->removeAt(1), 7);
  EXPECT_EQ(list->length, 2);

  list->append(11);
  EXPECT_EQ(list->removeAt(1), 9);
  ASSERT_THROW(list->remove(9), std::invalid_argument);
  EXPECT_EQ(list->remove(11), 11);
  EXPECT_EQ(list->length, 1);

  /* expect(list.removeAt(0)).toEqual(5); */
  /* expect(list.removeAt(0)).toEqual(11); */
  /* expect(list.length).toEqual(0); */

  /* list.prepend(5); */
  /* list.prepend(7); */
  /* list.prepend(9); */

  /* expect(list.get(2)).toEqual(5); */
  /* expect(list.get(0)).toEqual(9); */
  /* expect(list.remove(9)).toEqual(9); */
  /* expect(list.length).toEqual(2); */
  /* expect(list.get(0)).toEqual(7); */
}
