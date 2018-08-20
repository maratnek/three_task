#include <gtest/gtest.h>
#include "task2.hpp"

// task2 test

TEST(task2, det1)
{
  EXPECT_EQ(det<int>({-2, 3}, {1, 2}, {0, 0}), -7);
  EXPECT_EQ(det<int>({1, 2}, {-3, -1}, {0, 0}), 5);
  EXPECT_EQ(det<int>({-3, -1}, {-2, 3}, {0, 0}), -11);
}

TEST(task2, det_float)
{
  EXPECT_EQ(det<float>({-2, 3}, {1, 2}, {0, 0}), -7);
  EXPECT_EQ(det<float>({1, 2}, {-3, -1}, {0, 0}), 5);
  EXPECT_EQ(det<float>({-3, -1}, {-2, 3}, {0, 0}), -11);
}

TEST(task2, PointInTriangle_false)
{
  EXPECT_FALSE(PointInTriangle<int>({-2, 3}, {1, 2}, {-3, -1}, {0, 0}));
}

TEST(task2, PointInTriangle_true)
{
  EXPECT_TRUE(PointInTriangle<int>({-2, 4}, {-2, -4}, {1, 1}, {0, 0}));
}
