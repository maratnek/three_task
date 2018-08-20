#include <gtest/gtest.h>
#include "task1.hpp"
#include <string>
#include <exception>
#include <random>
#include <memory>

TEST(task1, MaxMultThreeNumbers)
{
  int wholeNumList[] = {-50, 1, 0, 1, -1, 30, 4000, 0, -50, -1340, 88, 8, -76, 99, 88, 7, -32, 88, 30, -1};
  size_t count = sizeof(wholeNumList)/sizeof(int);
  long expectedResult = 407360000;
  long actualResult = MaxMultThreeNumbers(wholeNumList,count);
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(task1, MaxMultThreeNumbers_Count_0)
{
  int wholeNumList[] = {};
  size_t count = sizeof(wholeNumList)/sizeof(int);
  std::string actualResult = "";
  try {
    MaxMultThreeNumbers(wholeNumList,count);
  }
  catch (const char *c)
  {
    actualResult = c;
  }
  std::string expectedResult = "Function MaxMultThreeNumbers count must >= 3 is mistaken.";
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(task1, MaxMultThreeNumbers_Count_eq_3)
{
  int wholeNumList[] = {-50, 1, 2};
  size_t count = sizeof(wholeNumList)/sizeof(int);
  long expectedResult =-100;
  long actualResult = MaxMultThreeNumbers(wholeNumList,count);
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(task1, MaxMultThreeNumbers_only_negative_and_zero)
{
  int wholeNumList[] = {-50, -1, 0, -1, -50, -1340, -1};
  size_t count = sizeof(wholeNumList)/sizeof(int);
  long expectedResult = 0;
  long actualResult = MaxMultThreeNumbers(wholeNumList,count);
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(task1, MaxMultThreeNumbers_only_negative1)
{
  int wholeNumList[] = {-2, -5, -7, -1};
  size_t count = sizeof(wholeNumList)/sizeof(int);
  long expectedResult = -10;
  long actualResult = MaxMultThreeNumbers(wholeNumList,count);
  EXPECT_EQ(expectedResult, actualResult);
}


TEST(task1, MaxMultThreeNumbers_only_negative2)
{
  int wholeNumList[] = {-5, -1, -7, -20, -400};
  size_t count = sizeof(wholeNumList)/sizeof(int);
  long expectedResult = -35;
  long actualResult = MaxMultThreeNumbers(wholeNumList,count);
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(task1, MaxMultThreeNumbers_all_one_positive_without_zero)
{
  int wholeNumList[] = {-50, 10, -2, -4};
  size_t count = sizeof(wholeNumList)/sizeof(int);
  long expectedResult = 2000;
  long actualResult = MaxMultThreeNumbers(wholeNumList,count);
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(task1, MaxMultThreeNumbers_all_two_positive_without_zero)
{
  int wholeNumList[] = {-50, 10, 16, -2, -4};
  size_t count = sizeof(wholeNumList)/sizeof(int);
  long expectedResult = 3200;
  long actualResult = MaxMultThreeNumbers(wholeNumList,count);
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(task1, MaxMultThreeNumbers_all_one_positive)
{
  int wholeNumList[] = {-50, 1, 0, -2, -4};
  size_t count = sizeof(wholeNumList)/sizeof(int);
  long expectedResult = 200;
  long actualResult = MaxMultThreeNumbers(wholeNumList,count);
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(task1, MaxMultThreeNumbers_all_two_positive)
{
  int wholeNumList[] = {-50, 1, 0, 15, -2, -4};
  size_t count = sizeof(wholeNumList)/sizeof(int);
  long expectedResult = 3000;
  long actualResult = MaxMultThreeNumbers(wholeNumList,count);
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(task1, MaxMultThreeNumbers_all2)
{
  int wholeNumList[] = {-50, 1, 0, 1, -1, 30, 4000, 0, -50, -1340, 88, 8, -76, 99, 88, 7, -32, 88, 30, -1};
  size_t count = sizeof(wholeNumList)/sizeof(int);
  long expectedResult = 407360000;
  long actualResult = MaxMultThreeNumbers(wholeNumList,count);
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(task1, MaxMultThreeNumbers_all_max)
{
  int wholeNumList[] = {10000, -50, 0, 1, -1, 30, 400, 0, -10000, -50, -134, 88, 8, -76, 99, 7, -32, 88, 30, -10000};
  size_t count = sizeof(wholeNumList)/sizeof(int);
  long long expectedResult = 1000000000000L;
  long long actualResult = MaxMultThreeNumbers(wholeNumList,count);
  EXPECT_EQ(expectedResult, actualResult);
}

TEST(task1, MaxMultThreeNumbers_all_random_big)
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(-10000, 10000);
  int wholeNumList[1000000] = {0};
  size_t count = sizeof(wholeNumList)/sizeof(int);
  for (size_t i = 0; i < count; i++) {
    wholeNumList[i] = dis(gen);
  }
  wholeNumList[count - 1] = 10000;
  wholeNumList[1] = -10000;
  wholeNumList[count/2] = -10000;

  long long expectedResult = 1000000000000L;
  long long actualResult = MaxMultThreeNumbers(wholeNumList,count);
  EXPECT_EQ(expectedResult, actualResult);
}

// TEST(task1, MaxMultThreeNumbers_all_random_very_big)
// {
//   std::random_device rd;
//   std::mt19937 gen(rd());
//   std::uniform_int_distribution<> dis(-10000, 10000);
//   size_t count = 300000000;
//   std::shared_ptr<int> wholeNumList(new int[count], [](auto del){delete[] del;});
//   for (size_t i = 0; i < count; i++) {
//     wholeNumList.get()[i] = dis(gen);
//   }
//   wholeNumList.get()[count - 1] = 10000;
//   wholeNumList.get()[1] = -10000;
//   wholeNumList.get()[count/2] = -10000;
//
//   long long expectedResult = 1000000000000L;
//   long long actualResult = MaxMultThreeNumbers(wholeNumList.get(),count);
//   EXPECT_EQ(expectedResult, actualResult);
// }
