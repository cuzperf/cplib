#include "tests/test_util.h"

TEST(EMPTY, test)
{
  EXPECT_EQ(1 + 1, 2);
}

TEST(EMPTY, DISABLED_test)
{
  EXPECT_EQ(1 + 1, 3);
}
