#include "pt_utils.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(PointsTest, PointConstruction)
{
  static auto x = 1.0;
  static auto y = 2.0;
  Point pt{ x, y };
  Point pt2(x, y);

  EXPECT_TRUE(pt == pt2);
  EXPECT_EQ(x, pt.x);
  EXPECT_EQ(y, pt.y);
}