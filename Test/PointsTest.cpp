#include "pt_utils.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(PointsTest, PointConstruction)
{
  static auto x = 1.0;
  static auto y = 2.0;
  Point pt{ x, y };
  Point pt2(x, y);

  EXPECT_EQ(pt, pt2);
  EXPECT_NE(pt, Point(111.0, 111.0));

  EXPECT_EQ(x, pt.x);
  EXPECT_EQ(y, pt.y);
}

TEST(PointsTest, AddingPoints)
{
  Point pt{ 1.0, 1.0 };
  Point pt2(pt);

  EXPECT_EQ(pt, pt2);
  pt += pt2;

  EXPECT_EQ(Point(2.0, 2.0), pt);

  Point pt3{ pt2 };
  pt3 += pt2;

  EXPECT_EQ(pt3, pt);
}

TEST(PointsTest, SubstractingPoints)
{
  Point pt{ 1.0, 1.0 };
  Point pt2(pt);

  pt -= pt2;

  EXPECT_EQ(Point(0.0, 0.0), pt);

  Point pt3{ pt2 };
  pt3 -= pt2;

  EXPECT_EQ(pt3, pt);
}

TEST(PointsTest, Other)
{
  Point pt{ 2.0, 2.0 };
  Point pt2(pt);

  pt = pt * pt2;

  EXPECT_EQ(Point(4.0, 4.0), pt);

  Point pt3{ pt2 };
  pt3 = pt3 / pt2;

  EXPECT_EQ(Point(1.0, 1.0), pt3);

  {
    Point pt{ 2.0, 2.0 };
    auto ptNew = pt * 2.0;
    EXPECT_EQ(Point(4.0, 4.0), ptNew);
  }
}

TEST(PointsTest, MovesCountBetween)
{
  Point pt  {2.0, 2.0};
  Point pt2 {1.0, 1.0};

  auto distance1 = MovesCountBetween(pt, pt2);
  auto distance2 = MovesCountBetween(pt2, pt);

  EXPECT_EQ(distance1, distance2);
  EXPECT_EQ(2.0, distance1);
}

TEST(PointsTest, DISABLED_GetCrossingPoint_SUCC)
{
  Point line1_pt1{ 0.0, 0.0 };
  Point line1_pt2{ 1.0, 1.0 };

  Point line2_pt1{ 2.0, 2.0 };
  Point line2_pt2{ 1.0, 1.0 };

  Point ptCrossed{};
  auto isCrossed = GetCrossingPoint(line1_pt1, line1_pt2, line2_pt1, line2_pt2, ptCrossed);
  EXPECT_TRUE(isCrossed);

  EXPECT_EQ(Point(1.0, 1.0), ptCrossed);
}

TEST(PointsTest, GetCrossingPoint_FAIL)
{
  Point line1_pt1{ 0.0, 0.0 };
  Point line1_pt2{ 1.0, 1.0 };

  Point line2_pt1{ 2.0, 2.0 };
  Point line2_pt2{ 3.0, 3.0 };

  Point ptCrossed{};
  auto isCrossed = GetCrossingPoint(line1_pt1, line1_pt2, line2_pt1, line2_pt2, ptCrossed);
  EXPECT_FALSE(isCrossed);
  EXPECT_EQ(Point(), ptCrossed);
}